/**
 * @param {string} columnTitle
 * @return {number}
 */
var titleToNumber = function(columnTitle) {
    let num = 0;
    for(let i=0; i<columnTitle.length; i++){
        num += (columnTitle.charCodeAt(i) - 64)*Math.pow(26,columnTitle.length - 1 - i)
    }
    return num;
};