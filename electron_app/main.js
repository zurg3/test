const {app, BrowserWindow} = require('electron');
const path = require('path');
const url = require('url');
const remote_main = require('@electron/remote/main');

remote_main.initialize();

let win;

//app.allowRendererProcessReuse = true;

function createWindow() {
  win = new BrowserWindow({
    width: 800,
    height: 600,
    icon: __dirname + '/img/icon.png',
    webPreferences: {
      preload: path.join(__dirname, 'preload.js'),
      nodeIntegration: true,
      enableRemoteModule: true,
      contextIsolation: false
    }
  });

  remote_main.enable(win.webContents);

  win.loadURL(
    url.format({
      pathname: path.join(__dirname, 'index.html'),
      protocol: 'file:',
      slashes: true
    })
  );

  //win.loadURL('https://www.google.com')

  //win.webContents.openDevTools();

  win.on('closed', function() {
    win = null;
  });
};

app.whenReady().then(() => {
  createWindow();

  app.on('activate', function() {
    if (BrowserWindow.getAllWindows().length === 0) {
      createWindow();
    }
  });
});

app.on('window-all-closed', function() {
  if (process.platform !== 'darwin') {
    app.quit();
  }
});
