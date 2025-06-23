var minFlips = function(s) {
    const n = s.length;
    const doubleS = s + s;
    const alt1 = [], alt2 = [];

    // Generate alternating patterns of length 2n
    for (let i = 0; i < 2 * n; i++) {
        alt1.push(i % 2 === 0 ? '0' : '1'); // "010101..."
        alt2.push(i % 2 === 0 ? '1' : '0'); // "101010..."
    }

    let minFlips = Infinity;
    let diff1 = 0, diff2 = 0;

    for (let i = 0; i < 2 * n; i++) {
        if (doubleS[i] !== alt1[i]) diff1++;
        if (doubleS[i] !== alt2[i]) diff2++;

        if (i >= n) {
            if (doubleS[i - n] !== alt1[i - n]) diff1--;
            if (doubleS[i - n] !== alt2[i - n]) diff2--;
        }

        if (i >= n - 1) {
            minFlips = Math.min(minFlips, diff1, diff2);
        }
    }

    return minFlips;
};
