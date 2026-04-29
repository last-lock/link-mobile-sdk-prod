function createVersionRow(version) {
  const item = document.createElement("li");

  const label = document.createElement("strong");
  label.textContent = version;
  item.appendChild(label);

  const links = document.createElement("span");
  links.className = "version-links";
  links.innerHTML =
    `(<a href="./ios/${version}/documentation/linkmobile/">iOS</a> | <a href="./android/${version}/">Android</a>)`;
  item.appendChild(links);

  return item;
}

function updateLatestButtons(version) {
  const iosLatestLink = document.getElementById("ios-latest-link");
  if (iosLatestLink) {
    iosLatestLink.href = `./ios/${version}/documentation/linkmobile/`;
  }

  const androidLatestLink = document.getElementById("android-latest-link");
  if (androidLatestLink) {
    androidLatestLink.href = `./android/${version}/`;
  }
}

async function renderVersions() {
  const list = document.getElementById("version-list");
  if (!list) {
    return;
  }

  try {
    const response = await fetch("./versions.json", { cache: "no-store" });
    if (!response.ok) {
      throw new Error(`Failed to load versions.json (${response.status})`);
    }

    const data = await response.json();
    const versions = Array.isArray(data.versions) ? data.versions : [];
    list.innerHTML = "";

    if (versions.length === 0) {
      const empty = document.createElement("li");
      empty.className = "muted";
      empty.textContent = "No published versions yet.";
      list.appendChild(empty);
      return;
    }

    updateLatestButtons(versions[0]);
    versions.forEach((version) => list.appendChild(createVersionRow(version)));
  } catch (_err) {
    list.innerHTML = "";
    const fallback = document.createElement("li");
    fallback.className = "muted";
    fallback.textContent = "No previous versions available yet.";
    list.appendChild(fallback);
  }
}

function ensureFavicon() {
  const head = document.head;
  if (!head) {
    return;
  }

  const href = "../SeamlessLinkLogo.png";
  const links = [
    { rel: "icon", type: "image/png" },
    { rel: "apple-touch-icon" },
  ];

  links.forEach(({ rel, type }) => {
    if (document.querySelector(`link[rel="${rel}"]`)) {
      return;
    }

    const link = document.createElement("link");
    link.rel = rel;
    if (type) {
      link.type = type;
    }
    link.href = href;
    head.appendChild(link);
  });
}

ensureFavicon();
void renderVersions();
