const { app, BrowserWindow, ipcMain } = require('electron');
const bind = require('./dear-my-prof-bind.node');

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
    currentWin.loadFile(`./View/${newViewName}`)
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
        minHeight: 600,
        parent: parent,
        x: pos.x,
        y: pos.y,
        frame: false
    });
    navigate(win, newViewName);
    return win;
}

function close(currentWin) {
    currentWin.close();
}

function output(currentWin, responseName, responseArgs) {
    currentWin.webContents.send(responseName, responseArgs);
}

let binding = new bind.CppImpl({
    navigate: navigate,
    newWindow: newWindow,
    close: close,
    output: output
});

app.on('ready', function (event, arg) {
    binding.start();
});

