 #include <stdio.h>

int main() {
    int t[20], d[20], h, i, j, n, temp, k, atr[20], tot, p, sum = 0;

    // Input the number of tracks to be traversed
    printf("\nEnter the no of tracks to be traversed: ");
    scanf("%d", &n);

    // Input the position of the head
    printf("\nEnter the position of head: ");
    scanf("%d", &h);

    // Initialize the track array
    t[0] = 0;
    t[1] = h;

    // Input the track positions
    printf("\nEnter the tracks: ");
    for (i = 2; i < n + 2; i++) {
        scanf("%d", &t[i]);
    }

    // Sort the track array
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < (n + 2) - i - 1; j++) {
            if (t[j] > t[j + 1]) {
                temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }

    // Find the position of the head in the sorted array
    for (i = 0; i < n + 2; i++) {
        if (t[i] == h) {
            j = i;
            k = i;
        }
    }
    
    // Reorder the tracks based on the head position
    p = 0;
    while (t[j] != 0) {
        atr[p] = t[j];
        j--;
        p++;
    }
    atr[p] = t[j];
    for (p = k + 1; p < n + 2; p++, k++) {
        atr[p] = t[k + 1];
    }

    // Calculate the difference between consecutive tracks and sum them up
    for (j = 0; j < n + 1; j++) {
        if (atr[j] > atr[j + 1]) {
            d[j] = atr[j] - atr[j + 1];
        } else {
            d[j] = atr[j + 1] - atr[j];
        }
        sum += d[j];
    }

    // Output the average header movements
    printf("\nAverage header movements: %f", (float)sum / n);

    return 0;
}

