#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<double>> a, int n) {
  // print the matrix
  // cout << "------------------" << endl;
  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j <= n; j++) {
  //     cout << a[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  // cout << "------------------" << endl;

  // Make it also account the negative numbers, and make the numbers in a column
  // aligned
  cout << "------------------" << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      cout << setw(10) << a[i][j] << " ";
    }
    cout << endl;
  }
  cout << "------------------" << endl;
}

double determinant(vector<vector<double>> a, int n) {
  double det = 1.0;
  for (int i = 0; i < n; i++) {
    int pivot = i;
    for (int j = i + 1; j < n; j++) {
      if (abs(a[j][i]) > abs(a[pivot][i])) {
        pivot = j;
      }
    }
    if (pivot != i) {
      swap(a[i], a[pivot]);
      det *= -1;
    }
    if (a[i][i] == 0) {
      return 0;
    }
    det *= a[i][i];
    for (int j = i + 1; j < n; j++) {
      double factor = a[j][i] / a[i][i];
      for (int k = i + 1; k < n; k++) {
        a[j][k] -= factor * a[i][k];
      }
    }
  }
  return det;
}

int main() {
  // 2 variable equation solver using jordan elimination
  int n;
  cin >> n;
  vector<vector<double>> a(n, vector<double>(n + 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  if (determinant(a, n) == 0) {
    cout << "Inconsistent determinant" << endl;
    return 0;
  }

  // jordan elimination

  // Row Echelon Form

  // Make the (1,1) element 1
  for (int t = 0; t < n; t++) {
    double oneOne = a[t][t];
    for (int i = 0; i <= n; i++) {
      if (oneOne != 0)
        a[t][i] /= oneOne;
      else {
        // swap with the next row, after checking if it isn't the last row
        if (t != n - 1) {
          for (int j = t + 1; j < n; j++) {
            if (a[j][t] != 0) {
              swap(a[t], a[j]);
              break;
            }
          }
          t--;
          break;
        }
      }
    }

    printMatrix(a, n);

    for (int i = t + 1; i < n; i++) {
      // Make the first column 0 (except the first row)
      double firstCol = a[i][t];
      for (int j = 0; j <= n; j++) {
        a[i][j] -= firstCol * a[t][j];
      }
    }

    printMatrix(a, n);
  }

  // Back Substitution (Reduced Row Echelon Form)

  for (int t = n - 1; t >= 0; t--) {
    for (int i = t - 1; i >= 0; i--) {
      double firstCol = a[i][t];
      for (int j = 0; j <= n; j++) {
        a[i][j] -= firstCol * a[t][j];
      }
    }
  }

  printMatrix(a, n);
  // printf("Determinant: %lf\n", determinant(a, n));
}