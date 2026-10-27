export const TOKEN_NAMESPACE = 'timekeeper';

function base(url: string) {
  return url.trim().replace(/\/$/, '');
}

async function post(url: string, path: string, body: unknown) {
  const response = await fetch(`${base(url)}${path}`, {
    method: 'POST',
    headers: {'Content-Type': 'application/json'},
    body: JSON.stringify(body),
  });
  const payload = await response.json().catch(() => ({}));
  if (!response.ok) {
    const message = typeof payload.error === 'string' ? payload.error : `Request failed (${response.status})`;
    throw new Error(message);
  }
  return payload;
}

export function enterInstallMode(serverUrl: string, deviceId: string) {
  return post(serverUrl, '/v1/install-mode', {
    device_id: Number(deviceId),
    action: 'enter',
    duration_seconds: 300,
  });
}

export function exitInstallMode(serverUrl: string, deviceId: string) {
  return post(serverUrl, '/v1/install-mode', {
    device_id: Number(deviceId),
    action: 'exit',
  });
}

export async function issueUnlockPass(serverUrl: string, publicKeyBase64: string) {
  const payload = await post(serverUrl, '/v1/issue-unlock-pass', {
    credential_public_key: publicKeyBase64,
    duration: 7 * 24 * 60 * 60,
  });
  const group = payload.reader_groups?.[0];
  if (!payload.access_document || !group?.reader_group_id || !group?.issuer_ca_public_key || !group?.issuer_ca_certificate_der) {
    throw new Error('The example server returned an incomplete unlock pass.');
  }
  return {
    accessDocument: payload.access_document as string,
    readerGroupId: group.reader_group_id as string,
    issuerCaPublicKey: group.issuer_ca_public_key as string,
    issuerCaCertificate: group.issuer_ca_certificate_der as string,
  };
}
