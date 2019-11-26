const { app, BrowserWindow, ipcMain } = require('electron');

let rootWindow;
function createRootWindow() {
    rootWindow = new BrowserWindow({
        webPreferences: {
            devTools: false,
            nodeIntegration: true
        },
        frame: false
    });
    rootWindow.loadFile('./View/root.html');
}

let detailWindows = {};
function createDetailWindow(dataId) {
    if (detailWindows.hasOwnProperty(dataId))
        return;
    
    let newWindow = new BrowserWindow({
        webPreferences: {
            devTools: false,
            nodeIntegration: true,
            additionalArguments: [`---data-id=${dataId}`]
        },
        frame: false
    });
    newWindow.loadFile('./View/detail.html');
    newWindow.on('close', function() {
        delete detailWindows[dataId];
    });

    detailWindows[dataId] = newWindow;
}

app.on('ready', createRootWindow);

ipcMain.on('create-detail-window', function(event, arg) {
    createDetailWindow(arg.dataId);
});