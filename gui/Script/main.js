const { app, BrowserWindow, ipcMain } = require('electron');
const bind = require('./dear-my-prof-bind.node');

function newPosition() {
    let pos = BrowserWindow.getFocusedWindow().getPosition();
    return { x : pos[0] + 22, y : pos[1] + 22 };
}

let rootWindow = null;
function createRootWindow() {
    rootWindow = new BrowserWindow({
        webPreferences: {
            devTools: false,
            nodeIntegration: true
        },
        minWidth: 500,
        minHeight: 600,
        frame: false
    });
    rootWindow.loadFile('./View/login.html');
}

function login(id, pw) {
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

let newEmailWindow = null;
function createNewEmailWindow() {
    if (newEmailWindow != null) {
        newEmailWindow.focus();
    } else {
        let pos = newPosition();
        newEmailWindow = new BrowserWindow({
            webPreferences: {
                devTools: false,
                nodeIntegration: true
            },
            x: pos.x,
            y: pos.y,
            frame: false
        });
        newEmailWindow.loadFile('./View/newemail.html');
        newEmailWindow.on('close', function() {
            newEmailWindow = null;
        });
    }
}

const emailData = {
    'test1': { title: 'Title', subtitle: 'Subtitle', body: 'Body' },
    'test2': { title: '제목', subtitle: '부제목', body: '본문' }
};

app.on('ready', createRootWindow);

ipcMain.on('login', function(event, arg) {
    setTimeout(() => {
        login(arg.id, arg.pw);
    }, 1000);
}).on('mail-refresh', function(event, arg) {
    setTimeout(() => {
        let arg = [];
        for (let dataId in emailData) {
            let data = emailData[dataId];
            data.dataId = dataId;
            arg.push(data);
        }
        event.reply('mail-refresh-reply', arg);
    }, 1000);
}).on('create-detail-window', function(event, arg) {
    createDetailWindow(arg.dataId);
}).on('create-new-email-window', function(event, arg) {
    createNewEmailWindow();
}).on('detail-refresh', function(event, arg) {
    event.reply('detail-refresh-reply', emailData[arg.dataId]);
})