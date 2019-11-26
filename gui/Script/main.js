const { app, BrowserWindow, ipcMain } = require('electron');

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

let win2 = [];
app.on('ready', createWindow);
ipcMain.on('new-window', function(event, arg) {
    win2.push(new BrowserWindow({
        width: 800,
        height: 600,
        title: arg.title + ': ' + arg.subtitle
    }));
});