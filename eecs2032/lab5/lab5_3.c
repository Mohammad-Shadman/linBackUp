#include <stdio.h>

int main(){
    int age, strength, wisdom;
    float weight;

    printf("Enter age: ");
    scanf("%d",&age);
    printf("Enter strength: ");
    scanf("%d",&strength);
    printf("Enter weight: ");
    scanf("%f",&weight);
    printf("Enter wisdom: ");
    scanf("%d",&wisdom);

    strength += (strength)*(age<=25);
    weight *= 0.9*((age<=40 && age >=26)) + 1*(!((age<=40 && age >=26)));
    wisdom += 5*(age>40);
    
    printf("After drinking the Reversal Potion:\n"
            "Age: %d\n"
            "Strength: %d\n"
            "Weight: %.2f\n"
            "Wisdom: %d\n",
            age,strength,weight,wisdom
    ); 
    return 0;
}