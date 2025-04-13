
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#include<unistd.h>
#include"machine_learning.h"

void typewriter_print(char *str, unsigned int milliseconds, int colour_code)
{
  for (; *str != '\0'; str++)
  {
    printf("\x1b[38;5;%d;1m", colour_code);
    putchar(*str);
    fflush(stdout);
    //sleep(milliseconds * 700);
    printf("\x1b[0m");
  }
}

int main(){
    printf("                      ");
    typewriter_print("WELCOME TO MACHINE LEARNING IN C\n",60,197);
    printf("                                ");
    typewriter_print("Main Menu\n",70,197);

    //get the train file
    typewriter_print("Please select your Dataset file: ",60,208);
    char filename[200];
    char test_filename[200];
    int file;
    typewriter_print("Please select the file number: \n",60,197);
    typewriter_print("1. Breast Cancer DataSet\n",60,208);
    typewriter_print("2. Iris Dataset\n",60,208);
    typewriter_print("3. Scaled Data\n",60,208);
    typewriter_print("4. Tvmarketing Dataset\n",60,208);
    scanf("%d",file);
    switch(file){
        case 1:
        strcpy(filename,"Breast_cancer.csv");
        strcpy(test_filename,"test_breast.csv");
        break;

        case 2:
        strcpy(filename,"iris_flower_dataset.csv");
        strcpy(test_filename,"test_iris.csv");
        //filename[0] = "iris_flower_dataset.csv";
        //test_filename[0]= "test_iris.csv";
        break;

        case 3:
        strcpy(filename,"scaled_data.csv");
        strcpy(test_filename,"test_scaled_data.csv");
        break;

        case 4:
        strcpy(filename,"tvmarketing.csv");
        strcpy(test_filename,"test_tvmarketing.csv");
        break;

    }
    FILE* fptr= fopen(filename,"r");

    //check if file can be loaded or not
    if(fptr==NULL){
        typewriter_print("Train file can't be opened\n",50,197);
    }
    fclose(fptr);

    // get the test file
    //typewriter_print("Please enter your test file name: ",60,208);
    
    //scanf("%s",test_filename);
    FILE* fptr_= fopen(filename,"r");
    if(fptr_==NULL){
        typewriter_print("Test file can't be opened\n",50,197);
    }
    fclose(fptr_);

    //giving the options to user for model selection and for scaling the data
    typewriter_print("\nPlease select the model to use:\n",60,208);
    typewriter_print("1. Data Scaling\n",60,208);
    typewriter_print("2. Linear Regression\n",60,208);
    typewriter_print("3. Logistic Regression\n",60,208);
    typewriter_print("4. K Nearest Neighbour\n",60,208);
    typewriter_print("5. Exit\n",60,208);
    typewriter_print("Enter option: ",60,208);
    int option;
    scanf("%d",&option);
    int choice=0;
    switch (option)
    {
    case 1:
        typewriter_print("Choose scaler type:\n",60,208);
        typewriter_print("1. Min Max Scaler\n",60,208);
        typewriter_print("2. Standard Scaler\n",60,208);
        typewriter_print("3. Main Menu\n",60,208);
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
        exit(0);

    default:
        typewriter_print("Invalid option",60,196);
        main();
        break;
    }

    return 0;
}
