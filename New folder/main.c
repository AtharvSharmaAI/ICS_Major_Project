#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<unistd.h>
#include<ctype.h>
#include"machine_learning.h"

void typewriter_print(char *str, int colour_code)
{
  for (; *str != '\0'; str++)
  {
    printf("\x1b[38;5;%d;1m", colour_code);
    putchar(*str);
    fflush(stdout);
    // usleep(milliseconds * 700);
    printf("\x1b[0m");
  }
}

int main(){
    printf("                      ");
    typewriter_print("WELCOME TO MACHINE LEARNING IN C\n",197);
    printf("                                ");
    typewriter_print("Main Menu\n",197);

    //get the train file
    typewriter_print("Please Select your Dataset: \n",208);
    char filename[200];
    char test_filename[200];
    int file;
    typewriter_print("1. Breast Cancer dataset\n",208);
    typewriter_print("2. iris flower dataset\n",208);
    typewriter_print("3. scaled dataset\n",208);
    typewriter_print("4. TV Marketing dataset\n",208);
    typewriter_print("5. Exit\n",208);
    scanf("%d",&file);
    switch(file) {
        case 1:
            strcpy(filename, "Breast_cancer.csv");
            strcpy(test_filename, "test_breast.csv");
            break;

        case 2:
            strcpy(filename, "iris_flower_dataset.csv");
            strcpy(test_filename, "test_iris.csv");
            break;

        case 3:
            strcpy(filename, "scaled_data.csv");
            strcpy(test_filename, "test_scaled_data.csv");
            break;

        case 4:
            strcpy(filename, "tvmarketing.csv");
            strcpy(test_filename, "test_tvmarketing.csv");
            break;

        case 5:

        exit(0);

        break;

        default:
        typewriter_print("wrong number try again",197);
        return main();
        break;

    };
    
    FILE* fptr= fopen(filename,"r");

    //check if file can be loaded or not
    if(fptr==NULL){
        typewriter_print("Train file can't be opened\n",197);
    }
    fclose(fptr);

    // get the test file
    typewriter_print("Please enter your test file name: ",208);
    
    //scanf("%s",test_filename);
    FILE* fptr_= fopen(filename,"r");
    if(fptr_==NULL){
        typewriter_print("Test file can't be opened\n",197);
    }
    fclose(fptr_);

    //giving the options to user for model selection and for scaling the data
    typewriter_print("\nPlease select the model to use:\n",208);
    typewriter_print("1. Data Scaling\n",208);
    typewriter_print("2. Linear Regression\n",208);
    typewriter_print("3. Logistic Regression\n",208);
    typewriter_print("4. K Nearest Neighbour\n",208);
    typewriter_print("5. Softmax Regression\n",208);
    typewriter_print("6. Exit\n",208);
    typewriter_print("7. Restart\n",208);

    typewriter_print("Enter option: ",208);
    int option;
    scanf("%d",&option);
    int choice=0;
    switch (option)
    {
    case 1:
        typewriter_print("Choose scaler type:\n",208);
        typewriter_print("1. Min Max Scaler\n",208);
        typewriter_print("2. Standard Scaler\n",208);
        typewriter_print("3. Main Menu\n",208);
        do{
            scanf("%d",&choice);
            switch (choice)
            {
            case 1:
                min_max_scaler(filename,test_filename);
                break;
            case 2:
                standard_scaler(filename,test_filename);
                break;
            case 3:
                main();
                break;
            default:
                printf("Invalid choice\n");
                break;
            }

        }while((choice<1)||(choice>2));
        break;

    case 2:
        linear_regression(filename,test_filename);
        break; 
    
    case 3:
        logistic_regression(filename,test_filename);
        break;

    case 4:
        KNN(filename,test_filename);
        break;
    
    case 5:
        softmax_regression(filename,test_filename);
        break;
    case 6:
        exit(0);
        break;
    case 7:
        main();
        break;

    default:
        typewriter_print("Invalid option",196);
        main();
        break;
    }

    return 0;
}

