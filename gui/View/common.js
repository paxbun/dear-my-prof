module.exports.Field_getValue = function (field) {
    return field.firstElementChild.lastElementChild.innerHTML;
};

module.exports.Field_preventMultiline = function (field) {
    field.firstElementChild.lastElementChild.addEventListener('keydown',
        (event) => {
            if (event.keyCode === 13) {
                event.preventDefault();
            }
        }
    );
};

module.exports.Field_invokeWithEnter = function (field, func) {
    field.firstElementChild.lastElementChild.addEventListener('keydown',
        (event) => {
            if (event.keyCode === 13) {
                func();
                event.preventDefault();
            }
        }
    );
}