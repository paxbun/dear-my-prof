function getDataId() {
    const prefix = '---data-id=';
    for (let i in window.process.argv) {
        let str = window.process.argv[i];
        if (str.startsWith(prefix))
            return str.substring(prefix.length);
    }
    return 'null';
}

let titleBar;
window.onload = function() {
    titleBar = document.getElementById('title-bar');
    titleBar.innerHTML = getDataId();
}