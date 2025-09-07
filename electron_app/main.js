const {app, BrowserWindow} = require('electron');
const path = require('path');
const url = require('url');
const remote_main = require('@electron/remote/main');

remote_main.initialize();

//app.allowRendererProcessReuse = true;

function createWindow() {
  const win = new BrowserWindow({
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

  //win.loadURL('https://www.google.com');

  win.loadFile('index.html');

  //win.webContents.openDevTools();
};

app.whenReady().then(() => {
  createWindow();

  app.on('activate', function() {
    if (BrowserWindow.getAllWindows().length === 0) createWindow();
  });
});

app.on('window-all-closed', function() {
  if (process.platform !== 'darwin') app.quit();
});
