// Struct for Node
typedef struct Node {
    int bias;
    double weights[3];
    int output;
} Node;

// Activation Function
int signFunction (double nodeOutput) {
    if(nodeOutput > 0) {
        return 1;
    }
    return 0;
}

// Weight Summation
double weightSummation (Node* n1, int* inputs) {
    return (n1->weights[0] * inputs[0]) + (n1->weights[1] * inputs[1]) + (n1->weights[2] * n1->bias);
}

// Error Calculation
int errorCalc (int correct, int guessed) {
    return (correct - guessed);
}

// New Weight Calculation
double weightUpdate (int error, double oldWeight, int input, double learningRate) {
    return oldWeight + (error * input * learningRate);
}

// And Function for "Correct" data
int andFunction (int *inputs) {
    if(inputs [0] == 1 && inputs[1] == 1){
        return 1;
    }
    return 0;
}

int orFunction (int *inputs) {
    if(inputs[0] == 1 || inputs[1] == 1){\
        return 1;
    }
    return 0;
}

int xorFunction (int *inputs) {
    if((orFunction(inputs)) && !(andFunction(inputs))){
        return 1;
    }
    return 0;
}
