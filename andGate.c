#include "helpers.c"
#include <stdio.h>

int main () {
    const double learningRate = 0.2;
    const int iterations = 100;
    const int numInputsAND = 2;
    int numCorrect = 0;

    Node n1;
    nodeInit(&n1,numInputsAND);

    printf("Begin Neural Net ----------------\n");

    // Training Process
    for (int i = 0; i < iterations; i++){
        int* inputs = generateInputs(numInputsAND);

        n1.output = outputCalc(&n1, inputs);
        printf("For %i and %i the PRED: %i\n", inputs[0], inputs[1], n1.output);

        int expected = andFunction(inputs); // AND FUNC
        printf("EXPECTED: %i\n", expected);

        if(expected == n1.output){
            ("CORRECT----\n");
            numCorrect++;
        }

        // Error Correction time baby
        n1.weights[0] = weightUpdate(errorCalc(expected, n1.output), n1.weights[0], 1, learningRate);
        n1.weights[1] = weightUpdate(errorCalc(expected, n1.output), n1.weights[1], inputs[0], learningRate);
        n1.weights[2] = weightUpdate(errorCalc(expected, n1.output), n1.weights[2], inputs[1], learningRate);

    }

    printf("N1 Weights 0: %f\n", n1.weights[0]);
    printf("N1 Weights 1: %f\n", n1.weights[1]);
    printf("N1 Weights 2: %f\n", n1.weights[2]);
    printf("Percent correct = %.2f", (numCorrect/(double)iterations) * 100);

}