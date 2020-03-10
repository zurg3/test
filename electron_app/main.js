const { app, BrowserWindow } = require('electron');
const path = require('path');
const url = require('url');

let win;

app.allowRendererProcessReuse = true;

function createWindow() {
  win = new BrowserWindow({
    width: 800,
    height: 600,
    icon: __dirname + '/img/icon.png',
    webPreferences: {
      preload: path.join(__dirname, 'preload.js'),
      nodeIntegration: true
    }
  });

  win.loadURL(
    url.format({
      pathname: path.join(__dirname, 'index.html'),
      protocol: 'file:',
      slashes: true
    })
  );

  //win.loadURL('https://google.com')

  //win.webContents.openDevTools();

  win.on('closed', function() {
    win = null;
  });
};

app.on('ready', createWindow);

app.on('window-all-closed', () => {
  app.quit();
});
