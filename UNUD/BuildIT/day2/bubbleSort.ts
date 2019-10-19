let container: number[];
let counter: number;

function swap(indexA: number, indexB: number) {
    const temp = container[indexA];
    container[indexA] = container[indexB];
    container[indexB] = temp;
}

function oneLoop() {
}

function sort() {
    while (true) {
        for (let i = 0; i < container.length; i++) {
            if (container[i] < container[i + 1]) {
                swap(i, i + 1);
                counter++;
            }
        }

        if (counter == 0) {
            return container;
        }

        counter = 0;
    }
}
}


let xx = [3, 5, 3, 2, 2];
console.log(bubbleSort(xx).sort());