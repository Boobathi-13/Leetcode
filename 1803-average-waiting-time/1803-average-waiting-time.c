double averageWaitingTime(int** a, long n, int* m) {
    double totalWaitingTime = 0;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        int arrivalTime = a[i][0];
        int prepTime = a[i][1];

        // If the chef is free before the customer arrives, he starts at the customer's arrival time
        if (arrivalTime >= currentTime) {
            currentTime = arrivalTime + prepTime;
        } else {
            // Otherwise, the chef starts preparing the order as soon as he finishes the previous one
            currentTime += prepTime;
        }

        // Calculate the waiting time for this customer
        int waitingTime = currentTime - arrivalTime;
        totalWaitingTime += waitingTime;
    }

    // Return the average waiting time
    return totalWaitingTime / n;
}
