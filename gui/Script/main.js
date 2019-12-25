const { app, BrowserWindow, ipcMain } = require('electron');
const bind = require('./dear-my-prof-bind.node');

let windows = {}

let binding = new bind.CppImpl({
    "navigate": navigate,
    "newWindow": newWindow,
    "close": close,
    "output": output
});

function newPosition() {
    let focused = BrowserWindow.getFocusedWindow();
    if (focused === null)
        return { x: undefined, y: undefined };
    else {
        let pos = focused.getPosition();
        return { x: pos[0] + 22, y: pos[1] + 22 };
    }
}

function navigate(currentWin, newViewName) {
    windows[currentWin].loadFile(`./View/${newViewName}`)
}

function newWindow(newViewName, args, parent) {
    let pos = newPosition();
    let win = new BrowserWindow({
        webPreferences: {
            devTools: false,
            nodeIntegration: true,
            additionalArguments: args
        },
        minWidth: 500,
        minHeight: 800,
        parent: windows[parent],
        x: pos.x,
        y: pos.y,
        frame: false
    });
    let id = win.webContents.id;
    win.webContents.on('ipc-message', function (event, channel, arg) {
        if (arg === undefined)
            arg = {};
        binding.input(id, channel, arg);
    });
    windows[id] = win;
    navigate(id, newViewName);
    return id;
}

function close(currentWin) {
    windows[currentWin].close();
}

function output(currentWin, responseName, responseArgs) {
    windows[currentWin].webContents.send(responseName, responseArgs);
}

app.on('ready', function (event, arg) {
    binding.start(newWindow);
});

