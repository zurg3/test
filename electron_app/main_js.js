var app_version = require('@electron/remote').app.getVersion();
var app_name = 'TestElectronApp' + ' v' + app_version;

function openURL_click() {
  var get_url = document.getElementById('open_url').value;

  window.open(get_url, '_self');
}

function openURL_enter() {
  var get_url = document.getElementById('open_url').value;

  if (event.key === "Enter") {
    window.open(get_url, '_self');
  }
}

function clicker() {
  document.getElementById('clicker_score').innerText++;
}

document.title = app_name;

document.write('<h1 align="center">' + app_name + '</h1>');
