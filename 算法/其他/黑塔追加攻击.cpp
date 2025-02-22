#include <stdio.h>
#include <stdlib.h>
void attack(int enemies[], int n);

int main() {
    int n,blood; 
    scanf("%d %d", &n, &blood);

    int *enemies = (int *)malloc(n * sizeof(int));
    if (enemies == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        enemies[i] = blood;
    }

    attack(enemies, n);

    free(enemies);

    return 0;
}

void attack(int enemies[], int n , int blood) {
	
    int attackCount = 0; 

    int allDefeated = 1;
    for (int i = 0; i < n; i++) {
        if (enemies[i] > 0) {
            allDefeated = 0;
            break;
        }
    }

    if (allDefeated) {
        printf("%d", attackCount);
        return;
    }

    int halfHealth = 0;
    int flag=1;
    for (int i=0 ; i<n ; i++){
    	if (enemies[i]>blood/2){
    		enemies[i]--;
    		attackCount++;
    		flag=0;
    		break;
		}
	}
    for (int i = 0; i < n; i++) {
        if (enemies[i] == blood/2) { 
            halfHealth++; 
            attackCount++;
        }
    }

    if (halfHealth > 0) {
        for (int i = 0; i < n; i++) {
            enemies[i]=enemies[i]-halfHealth; 
        }
    }
    
    if (flag==1){
    	for(int i=0;i<n;i++){
    		if (enemies[i]>0)
    		attackCount+=enemies[i];
		}
	}

    attack(enemies, n);
}