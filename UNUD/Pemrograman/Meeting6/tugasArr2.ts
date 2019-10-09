function print2DMatrix(arr: number[][]) {
    for (let i = 0; i < arr.length; i++) {
        for (let j = 0; j < arr[i].length; j++) {
            process.stdout.write(`${arr[i][j]}`);
            if (j != arr[i].length) process.stdout.write("\t");
        }
        if (i != arr.length) process.stdout.write("\n");
    }
}

function calcMatrixMultPerItem(arrA: number[][], arrB: number[][], y: number, x: number) {
    let res: number = 0;
    for (let i: number = 0; i < arrA.length; i++) {
        res += arrA[y][i] * arrB[i][x];
    }

    return res;
}

function multiplyMatrix(firstArray: number[][], secondArray: number[][]): number[][] {
    // let res: number[][] = new Array(firstArray.length).fill(new Array(firstArray[0].length));
    // let res: number[][] = [[null, null, null], [null, null, null], [null, null, null]];
    let res: number[][] = [];

    for (let i = 0; i < firstArray.length; i++) {
        res.push(new Array(secondArray[i].length));
    }

    for (let i = 0; i < res.length; i++) {
        for (let j = 0; j < res[i].length; j++) {
            res[i][j] = calcMatrixMultPerItem(firstArray, secondArray, i, j);
        }
    }

    return res;
}

function tryUserInput() {
    let arr: number[][] = [];
    process.stdout.write("Masukkan height matrix A:\n");
    let hA: number = Number(process.stdin.read());
    process.stdout.write("Masukkan width matrix A:\n");
    let wA: number = Number(process.stdin.read());
    process.stdout.write("Masukkan height matrix B:\n");
    let hB: number = Number(process.stdin.read());
    process.stdout.write("Masukkan width matrix B:\n");
    let wB: number = Number(process.stdin.read());

    process.stdout.write("\nInput nilai ke matrix A\n");
    for (let i = 0; i < hA; i++) {
        for (let j = 0; j < wA; j++) {
            
        }
    }
}


function try3by3() {
    let arrA: number[][] = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
    ];
    let arrB: number[][] = [
        [9, 8, 7],
        [6, 5, 4],
        [3, 2, 1],
    ];

    // print2DMatrix(arrA);
    // console.log("");
    // print2DMatrix(arrB);
    print2DMatrix(multiplyMatrix(arrA, arrB));

}

function try2by2() {
    let _a = [
        [2, 3],
        [5, 2],
    ];
    let _b = [
        [1, 3],
        [4, 2],
    ];
    // print2DMatrix(_a);
    // console.log("");
    // print2DMatrix(_b);
    print2DMatrix(multiplyMatrix(_a, _b));
}

function try3x3by3x2() {
    let arrA: number[][] = [
        [1, 2, 3],
        [4, 5, 6],
        [7, 8, 9],
    ];
    let arrB: number[][] = [
        [6, 5],
        [4, 3],
        [2, 1],
    ];

    // print2DMatrix(arrA);
    // console.log("");
    // print2DMatrix(arrB);
    print2DMatrix(multiplyMatrix(arrA, arrB));
}

// try2by2();
// process.stdout.write("\n");
// try3by3();
// process.stdout.write("\n");
// try3x3by3x2();
// process.stdout.write("\n");
tryUserInput();