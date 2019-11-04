int main() {
    int currentBest = INVALID_VALUE; // our best must be some invalid value, e.g -1 or INT_MIN
    int left = MIN; // left bound (worst possible answer)
    int right = MAX; // right bound (best possible answer)
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(mid)) { // check if the guessed answer is valid
            if (mid > currentBest) { // if mid is better than currentBest, currentBest = mid
                currentBest = mid;
            }
            left = mid + 1;
        } else { // the check failed, look for smaller answers
            right = mid - 1;
        }
    }

    cout << currentBest;
}