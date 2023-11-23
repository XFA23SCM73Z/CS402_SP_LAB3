#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float *array;
    size_t used;
    size_t size;
} DynamicArray;

void initArray(DynamicArray *a, size_t initialSize) {
    a->array = (float *)malloc(initialSize * sizeof(float));
    a->used = 0;
    a->size = initialSize;
}

void insertArray(DynamicArray *a, float element) {
    if (a->used == a->size) {
        a->size *= 2;
        a->array = (float *)realloc(a->array, a->size * sizeof(float));
    }
    a->array[a->used++] = element;
}

void freeArray(DynamicArray *a) {
    free(a->array);
    a->array = NULL;
    a->used = a->size = 0;
}

void readFileIntoArray(const char *filename, DynamicArray *a) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    float value;
    while (fscanf(file, "%f", &value) == 1) {
        insertArray(a, value);
    }

    fclose(file);
}

float calculateMean(DynamicArray *a) {
    float sum = 0.0;
    for (size_t i = 0; i < a->used; i++) {
        sum += a->array[i];
    }
    return sum / (float)a->used;
}

// Custom square root function using the Newton-Raphson method
float customSqrt(float number) {
    const float precision = 0.001f;
    float x = number;
    float root;
    while (1) {
        root = 0.5f * (x + (number / x));
        if (abs(root - x) < precision) break;
        x = root;
    }
    return root;
}

float calculateStdDev(DynamicArray *a, float mean) {
    float sum = 0.0;
    for (size_t i = 0; i < a->used; i++) {
        sum += (a->array[i] - mean) * (a->array[i] - mean);
    }
    return customSqrt(sum / (float)a->used);
}

int compareFloats(const void *a, const void *b) {
    float fa = *(const float*) a;
    float fb = *(const float*) b;
    return (fa > fb) - (fa < fb);
}

float calculateMedian(DynamicArray *a) {
    qsort(a->array, a->used, sizeof(float), compareFloats);
    size_t middle = a->used / 2;
    if (a->used % 2 == 0) {
        return (a->array[middle - 1] + a->array[middle]) / 2.0f;
    } else {
        return a->array[middle];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    DynamicArray dataArray;
    initArray(&dataArray, 20); // Start with 20 elements

    readFileIntoArray(argv[1], &dataArray);

    float mean = calculateMean(&dataArray);
    float median = calculateMedian(&dataArray);
    float stddev = calculateStdDev(&dataArray, mean);

    printf("Results:\n--------\n");
    printf("Num values: %zu\n", dataArray.used);
    printf("mean: %f\n", mean);
    printf("median: %f\n", median);
    printf("stddev: %f\n", stddev);
    printf("Unused array capacity: %zu\n", dataArray.size - dataArray.used);

    freeArray(&dataArray);

    return EXIT_SUCCESS;
}
