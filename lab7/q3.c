#include <stdio.h>

int can_get_money_together(int K) {
 
    int group_vignesh = K / 3;

    int group_lata = (K + 1) / 3;
 
    return group_vignesh == group_lata;
}

int main() {
    int T; 
    scanf("%d", &T);
    
    while (T--) {
        int N, K;
        scanf("%d %d", &N, &K);
        
        if (can_get_money_together(K)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}
