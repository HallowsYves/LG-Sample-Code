/*
  Rod Cutting Problem (Simplified Sample)

  Given a rod of length 5 and a list of available cut sizes with associated
  values, this program calculates the maximum obtainable value using dynamic
  programming.

  Cut sizes: [1, 2]
  Values:    [2, 5]
  Example output shows the sequence of cuts and their total value.

  Cut a piece of size 2 worth 5 dollars
  Cut a piece of size 2 worth 5 dollars
  Cut a piece of size 1 worth 2 dollars
  Total Value: 12
*/
#include <stdio.h>
#include <stdlib.h>

void solve_rod_cutting() {
  int rodLength = 5;
  int lengths[] = {1, 2};
  int values[] = {2, 5};
  int numCutOptions = 2;

  int *bestValueForLength = malloc((rodLength + 1) * sizeof(int));
  int *chosenPiece = malloc((rodLength + 1) * sizeof(int));

  // Base Case
  for (int i = 0; i <= rodLength; i++) {
    bestValueForLength[i] = 0;
    chosenPiece[i] = -1;
  }

  for (int pieceIndex = 0; pieceIndex < numCutOptions; pieceIndex++) {
    int cutSize = lengths[pieceIndex];
    int cutValue = values[pieceIndex];

    for (int currentLength = cutSize; currentLength <= rodLength; currentLength++) {
      int candidateValue = bestValueForLength[currentLength - cutSize] + cutValue;
      
      if (candidateValue > bestValueForLength[currentLength]) {
        bestValueForLength[currentLength] = candidateValue;
        chosenPiece[currentLength] = pieceIndex;
      }
    }
  }

  // Reconstruct and print solution
  int lengthToCut = rodLength;
  while (lengthToCut > 0 && chosenPiece[lengthToCut] != -1) {
    int pieceIndex = chosenPiece[lengthToCut];
    int cutSize = lengths[pieceIndex];
    int cutValue = values[pieceIndex];
    printf("Cut 1 piece of length %d worth %d\n", cutSize, cutValue);
    lengthToCut -= cutSize;
  }

  if (lengthToCut > 0) {
    printf("Remainder: %d\n", lengthToCut);
  }
  printf("Value: %d\n", bestValueForLength[rodLength]);

  // Free memory
  free(bestValueForLength);
  free(chosenPiece);
}

int main() {
  solve_rod_cutting();
  return 0;
}
