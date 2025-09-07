const app_name = `TestElectronApp`;
const app_version = require('@electron/remote').app.getVersion();

function openURL_click() {
  const get_url = document.getElementById('open_url').value;

  window.open(get_url, '_self');
}

function openURL_enter() {
  const get_url = document.getElementById('open_url').value;

  if (event.key === 'Enter') window.open(get_url, '_self');
}

function clicker() {
  document.getElementById('clicker_score').innerText++;
}

document.title = app_name;

document.write(`<h1 align="center">${app_name} v${app_version}</h1>`);
