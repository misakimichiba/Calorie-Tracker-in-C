#include <stdio.h>
#include <stdlib.h>
//B1901267
//All the functions I used in this program
float BMICalculator (float FLweight, float FLheight);
char FindWeightStatus (float FLBMI);
float MaleIdealWeight (float weight, float height);
float FemaleIdealWeight (float weight, float height);
float MaleBMR (float weight, float height, int age, char dailyActivityLevel);
float FemaleBMR (float weight, float height, int age, char dailyActivityLevel);
int DisplayMenu (int mealCounter);
void WeeksToGainOrLose (int totalCalories, float weight, float idealWeight, char weightStatus);

int main()
{
    //variables for input
    int age;
    char gender, userChoiceToExit = 'N';
    char dailyActivityLevel;
    float weight,height;

    //variables for output
    float BMI, BMR, idealWeight;
    int mealCounter, breakfastCalories, lunchCalories, dinnerCalories, totalCalories;
    char weightStatus;

    //while loop to repeat the program
    while (userChoiceToExit != 'Y' && userChoiceToExit != 'y')
    {
        //display welcome message
        printf("=================================================================\n");
        printf("Welcome to Calories Tracker!\nThis is a program to help people count their calories and stay healthy!\nPlease enter your following data\n");
        printf("=================================================================\n");
        printf("\n");

        //user input for gender
        printf("Gender[F/M]: ");
        scanf(" %c",&gender);
        //while loop to ensure user can only input F or M
        while (gender != 'M' && gender != 'F')
        {
            printf("\n");
            printf("Please enter either F(for Female) or M(for Male)\n");
            printf("Gender[F/M]: ");
            scanf(" %c",&gender);
        }
        //user input for age
        printf("Age: ");
        scanf(" %i",&age);
        //while loop to ensure user can only input valid numbers
        while (age < 1 || age > 120)
        {
            printf("\n");
            printf("Please enter a valid number for your age\n");
            printf("Age: ");
            scanf(" %i",&age);
        }
        //user input for weight
        printf("Weight[kilograms]: ");
        scanf(" %f",&weight);
        //while loop to ensure user can only input valid numbers
        while (weight < 1)
        {
            printf("\n");
            printf("Please enter a valid number/positive number for your weight\n");
            printf("Weight[kilograms/kg]: ");
            scanf(" %f",&weight);
        }
        //user input for height
        printf("Height[metres]: ");
        scanf(" %f",&height);
        //while loop to ensure user can only input valid numbers
        while (height > 3 || height <= 0)
        {
            printf("\n");
            printf("Please enter a valid number for your height (in metres, not centimetres)\n");
            printf("Height[metres/m]: ");
            scanf(" %f",&height);
        }

        //display menu for daily activity level
        printf("\n");
        printf("=================================================================\n");
        printf("Sedentary (little or no exercise)                         [Enter 1]\n");
        printf("Lightly Active (light exercise/sports 1-3 days/week)      [Enter 2]\n");
        printf("Moderately Active (moderate exercise/sports 3-5days/week) [Enter 3]\n");
        printf("Very Active (hard exercise/sports 6-7 days a week)        [Enter 4]\n");
        printf("=================================================================\n");
        printf("\n");
        printf("Please enter your daily activity level: ");
        scanf(" %c",&dailyActivityLevel);
        //while loop to ensure user can only input 1,2,3 or 4
        while (dailyActivityLevel != '1' && dailyActivityLevel != '2' && dailyActivityLevel != '3' && dailyActivityLevel != '4')
        {
            printf("\n");
            printf("Please enter 1,2,3 or 4 to select\n");
            printf("\n");
            printf("=================================================================\n");
            printf("Sedentary (little or no exercise)                         [Enter 1]\n");
            printf("Lightly Active (light exercise/sports 1-3 days/week)      [Enter 2]\n");
            printf("Moderately Active (moderate exercise/sports 3-5days/week) [Enter 3]\n");
            printf("Very Active (hard exercise/sports 6-7 days a week)        [Enter 4]\n");
            printf("=================================================================\n");
            printf("\n");
            printf("Please enter your daily activity level: ");
            scanf(" %c",&dailyActivityLevel);
        }

        //to calculate BMR for men
        if (gender == 'M')
        {
            BMR = MaleBMR(weight, height, age, dailyActivityLevel);
            printf("\n");
            printf("Your BMR is : %.2f\n", BMR);
        }

        //to calculate BMR for women
        else if (gender == 'F')
        {
            BMR = FemaleBMR(weight, height, age, dailyActivityLevel);
            printf("\n");
            printf("Your BMR is : %.2f\n", BMR);
        }

        //to calculate BMI
        BMI = BMICalculator (weight, height);
        printf("\n");
        printf("Your BMI is : %.2f\n", BMI);

        //to get the user's weight status (whether they're underweight,normal,overweight or obese)
        weightStatus = FindWeightStatus(BMI);
        printf("\n");
        printf("Your weight status is : %c\n", weightStatus);

        //display for is the user has a normal weight
        if (weightStatus == '2')
        {
                idealWeight = weight;
                printf("\n");
                printf("Your ideal weight is : %.2fkg\nYou already have the ideal weight!\n", idealWeight);
        }
        //displays the ideal weight for men if they're overweight or obese
        else if (gender == 'M' && weightStatus != '2')
        {
            idealWeight = MaleIdealWeight(weight,height);
            printf("\n");
            printf("Your ideal weight is : %.2fkg\n", idealWeight);
        }

        //displays the ideal weight for women if they're overweight or obese
        else if (gender == 'F' && weightStatus != '2')
        {
            idealWeight = FemaleIdealWeight(weight,height);
            printf("\n");
            printf("Your ideal weight is : %.2fkg\n", idealWeight);
        }

        //meal counter is to make a different display for breakfast,lunch and dinner
        mealCounter = 0;
        breakfastCalories = DisplayMenu(mealCounter);
        mealCounter = 1;
        lunchCalories = DisplayMenu(mealCounter);
        mealCounter = 2;
        dinnerCalories = DisplayMenu(mealCounter);
        totalCalories = breakfastCalories + lunchCalories + dinnerCalories;

        printf("\n");
        printf("Calories from breakfast are : %i\n",breakfastCalories);
        printf("Calories from lunch are : %i\n",lunchCalories);
        printf("Calories from dinner are : %i\n",dinnerCalories);
        printf("\n");
        printf("Total calories are : %i\n",totalCalories);

        //function to display amount of weeks to gain ideal weight
        WeeksToGainOrLose(totalCalories,weight,idealWeight,weightStatus);

        printf("\n");
        printf("Do you wish to exit the program? [Enter 'Y' or 'y' to exit]: ");
        scanf(" %c",&userChoiceToExit);
        printf("\n");
        printf("=================================================================\n");
        printf("\n");
    }

    printf("\n");
    printf("Thank you for using this program\n");

    return 0;
}

float BMICalculator(float FLweight, float FLheight)
{
    float BMI;
    //formula to calculate BMI
    BMI = FLweight/(FLheight * FLheight);

    return BMI;
}

char FindWeightStatus(float FLBMI)
{
    char weightStatus;
    //if else statement to assign weightStatus for underweight(1),normal(2),overweight(3) and obese(4)
    if (FLBMI < 18.5)
        weightStatus = '1';
    else if (FLBMI >= 18.5 && FLBMI <=24.9)
        weightStatus = '2';
    else if (FLBMI >= 25 && FLBMI <=29.9)
        weightStatus = '3';
    else
        weightStatus = '4';

    return weightStatus;
}

float MaleIdealWeight(float weight, float height)
{
    float idealWeight;
    float remainingHeight;

    //formula to calculate ideal weight for men
    if (height < 1.52)
        idealWeight = 50;
    else
    {
        remainingHeight = (height * 100) - 152;
        idealWeight = 50 + (0.9 * remainingHeight);
    }

    return idealWeight;
}

float FemaleIdealWeight(float weight, float height)
{
    float idealWeight;
    float remainingHeight;

    //formula to calculate ideal weight for women
    if (height < 1.52)
        idealWeight = 45.5;
    else
    {
        remainingHeight = (height * 100) - 152;
        idealWeight = 45.5 + (0.9 * remainingHeight);
    }

    return idealWeight;
}

float MaleBMR(float weight, float height, int age, char dailyActivityLevel)
{
    float BMR, heightInCM;

    //formula to calculate BMR for men
    heightInCM = height * 100;
    BMR = 66 + (13.7 * weight) + (5 * heightInCM) - (6.8 * (float)age);

    if (dailyActivityLevel == '1')
        BMR = 1.2 * BMR;
    else if (dailyActivityLevel == '2')
        BMR = 1.375 * BMR;
    else if (dailyActivityLevel == '3')
        BMR = 1.55 * BMR;
    else
        BMR = 1.725 * BMR;

    return BMR;
}

float FemaleBMR(float weight, float height, int age, char dailyActivityLevel)
{
    float BMR, heightInCM;

    //formula to calculate BMR for women
    heightInCM = height * 100;
    BMR = 655 + (9.6 * weight) + (1.8 * heightInCM) - (4.7 * (float)age);

    if (dailyActivityLevel == '1')
        BMR = 1.2 * BMR;
    else if (dailyActivityLevel == '2')
        BMR = 1.375 * BMR;
    else if (dailyActivityLevel == '3')
        BMR = 1.55 * BMR;
    else
        BMR = 1.725 * BMR;

    return BMR;
}

int DisplayMenu(int mealCounter)
{
    char drinkChoice, drinkType;
    int index, calories, choice;
    //array for menu containing food names
    char *menu[12] = {"Nasi Lemak                              ", "Roti Canai/Dhall                     "
    , "Roti Telur                              "
    , "Chappati                                ", "2 Half Boiled Eggs/Plain Bread         "
    , "Mamak Noodles Goreng                    ", "Prawn Mee                              "
    , "Lor Mee                                 ", "Mee Hailam                             "
    , "Penang Laksa                            ", "McDonalds/KFC/Pizza Hut Meal           "
    , "Rice + Meat/Poultry/Seafood + Vegetables"};
    //array for menu containing calories
    int caloriesAmount[12] = {644,359,414,166,277,660,239,383,277,436,850,620};

    printf("\n");
    printf("-----------------------------------------------------------------------\n");
    printf("                       Food                                   Calories\n");
    printf("-----------------------------------------------------------------------\n");

    //display the food and calorie menu
    for (index = 0; index < 12; index ++)
    {
        printf("[Enter %d to select] %s\t%d\n", index, menu[index], caloriesAmount[index]);
        //\t is for tab
    }

    printf("\n");

    //if else statement to display different messages for breakfast, lunch and dinner
    if (mealCounter == 0)
    {
        printf("Please select what you ate for breakfast: ");
        scanf(" %i",&choice);
    }

    else if (mealCounter == 1)
    {
        printf("Please select what you ate for lunch: ");
        scanf(" %i",&choice);
    }
    else if (mealCounter == 2)
    {
        printf("Please select what you ate for dinner: ");
        scanf(" %i",&choice);
    }

    //while loop to ensure user enters 0 to 11 only
    while (choice < 0 || choice > 11)
    {
        switch (mealCounter)
        {
            //display error message for breakfast
            case 0:
                printf("\n");
                printf("Please enter you choice from 0 - 11\n");
                printf("Please select what you ate for breakfast: ");
                scanf(" %i",&choice);
                break;

            //display error message for lunch
            case 1:
                printf("\n");
                printf("Please enter you choice from 0 - 11\n");
                printf("Please select what you ate for lunch: ");
                scanf(" %i",&choice);
                break;

            //display error message for dinner
            case 2:
                printf("\n");
                printf("Please enter you choice from 0 - 11\n");
                printf("Please select what you ate for dinner: ");
                scanf(" %i",&choice);
                break;
        }

    }

    //switch case for calories based on user's choice of food
    switch (choice)
    {
        case 0:
            calories = 644;
            break;
        case 1:
            calories = 359;
            break;
        case 2:
            calories = 414;
            break;
        case 3:
            calories = 166;
            break;
        case 4:
            calories = 277;
            break;
        case 5:
            calories = 660;
            break;
        case 6:
            calories = 239;
            break;
        case 7:
            calories = 383;
            break;
        case 8:
            calories = 277;
            break;
        case 9:
            calories = 436;
            break;
        case 10:
            calories = 850;
            break;
        case 11:
            calories = 620;
            break;
    }

    //ask if user had a drink with their meal
    printf("\n");
    printf("Did you have a drink with your meal? [Enter Y for yes and N for no] : ");
    scanf(" %c",&drinkChoice);

    //while loop to ensure user can only enter Y or N
    while (drinkChoice != 'Y' && drinkChoice != 'N')
    {
        printf("\n");
        printf("Please enter only Y or N\n");
        printf("Did you have a drink with your meal? [Enter Y for yes and N for no] : ");
        scanf(" %c",&drinkChoice);
    }

    //if statement for if user had a drink with their meal
    if (drinkChoice == 'Y')
    {
            printf("\n");
            printf("[Enter 1 to select]\tTeh Tarik\t83 calories\n");
            printf("[Enter 2 to select]\tSoft Drink\t120 calories\n");
            printf("\n");
            printf("What did you drink? : ");
            scanf(" %c",&drinkType);

                //while loop to ensure user can only enter 1 or 2 to select if they had a drink with their meal
                while (drinkType != '1' && drinkType != '2' && drinkChoice == 'Y')
                    {
                        printf("\n");
                        printf("Please enter only 1 or 2\n");
                        printf("\n");
                        printf("[Enter 1 to select]\tTeh Tarik\t83 calories\n");
                        printf("[Enter 2 to select]\tSoft Drink\t120 calories\n");
                        printf("What did you drink? : ");
                        scanf(" %c",&drinkType);
                    }

                //calorie calculations for drinks
                if (drinkType == '1')
                    calories += 83;
                else if (drinkType == '2')
                    calories +=  120;
    }

    return calories;

}

void WeeksToGainOrLose(int totalCalories, float weight, float idealWeight, char weightStatus)
{
    int weeksNumber;
    float caloriesToEat, weightToGainOrLose;

    //if else statement for number of weeks calculation based on whether user is underweight, overweight/obese or normal
    if (weightStatus == '1')
    {
        //formula to calculate recommended calories for user to gain weight and weeks required
        caloriesToEat = totalCalories + 500;
        weightToGainOrLose = idealWeight - weight;
        weeksNumber = (int)weightToGainOrLose * 2;

        printf("\n");
        printf("You are underweight so in order for you to have the ideal weight,\n");
        printf("you will have to gain %.2fkg\n",weightToGainOrLose);
        printf("We recommend you to follow this regimen to gain weight : \n");
        printf("Please eat %.2f amount of calories each day\n", caloriesToEat);
        printf("\n");
        printf("If you follow this regimen,\n");
        printf("it would take you %i weeks to get your ideal weight\n", weeksNumber);
    }

    else if (weightStatus == '2')
    {
        //congratulatory and encouraging message for user to maintain their weight
        printf("\n");
        printf("Congratulations! You already have the ideal weight!\n");
        printf("All the best in maintaining this weight!\n");
    }

    else if (weightStatus == '3' || weightStatus == '4')
    {
        //formula to calculate recommended calories for user to lose weight and weeks required
        caloriesToEat = totalCalories * 0.85;
        weightToGainOrLose = weight - idealWeight;
        weeksNumber = (((int)weightToGainOrLose * 7000) / (totalCalories - (int)caloriesToEat)) / 7;

        printf("\n");

        if (weightStatus == '3')
            //message for overweight user
            printf("You are overweight so in order for you to have the ideal weight,\n");
        else
            //message for obese user
            printf("You are obese so in order for you to have the ideal weight,\n");

        printf("you will have to lose %.2fkg\n",weightToGainOrLose);
        printf("We recommend you to follow this regimen to gain weight : \n");
        printf("Please eat %.2f amount of calories each day\n", caloriesToEat);
        printf("\n");
        printf("If you follow this regimen,\n");
        printf("it would take you %i weeks to get your ideal weight\n", weeksNumber);
    }
}
