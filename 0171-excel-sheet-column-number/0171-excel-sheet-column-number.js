/**
 * @param {string} columnTitle
 * @return {number}
 */
var titleToNumber = function(columnTitle) {
    let num = 0;
    for(let i=0; i<columnTitle.length; i++){
        num = num*26 + (columnTitle.charCodeAt(i)-64);
    }
    return num;
};