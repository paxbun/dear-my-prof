const { app, BrowserWindow } = require('electron');

let win;
function createWindow() {
    let win = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            devTools: false,
            nodeIntegration: true
        },
        frame: false
    });
    win.loadFile('./View/inbox.html');
}

app.on('ready', createWindow);