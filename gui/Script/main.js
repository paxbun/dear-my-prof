const { app, BrowserWindow, ipcMain } = require('electron');

function newPosition() {
    let pos = BrowserWindow.getFocusedWindow().getPosition();
    return { x : pos[0] + 22, y : pos[1] + 22 };
}

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
    if (detailWindows.hasOwnProperty(dataId)) {
        detailWindows[dataId].focus();
    } else {
        let pos = newPosition();
        let newWindow = new BrowserWindow({
            webPreferences: {
                devTools: false,
                nodeIntegration: true,
                additionalArguments: [`---data-id=${dataId}`]
            },
            x: pos.x,
            y: pos.y,
            frame: false
        });
        newWindow.loadFile('./View/detail.html');
        newWindow.on('close', function() {
            delete detailWindows[dataId];
        });

        detailWindows[dataId] = newWindow;
    }
}

app.on('ready', createRootWindow);

ipcMain.on('create-detail-window', function(event, arg) {
    createDetailWindow(arg.dataId);
});