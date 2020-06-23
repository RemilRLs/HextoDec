#include <iostream>
#include <vector>
#include <math.h>

/*
    Author : Remil
    Program : HexToDec
*/

int convHexToDec(std::string inputUserValidate , int lenUserInput);
int askUserHexandCheck(std::string inputUser);

int askUserHexandCheck(std::string inputUser){


    std::cout << "[*] - Please give a value in hexadecimal : ";
    std::cin >> inputUser;

    int lenUserInput = inputUser.size(); // On récupère la longueur de la chaîne de caractère.

    if(lenUserInput == 0){ // On vérifie la longueur de la chaîne de caractère afin de voir s'il y a bien une entrée de l'utilisateur.

        return 0;
    }

    else{
        

        for(int i = 0 ; i < lenUserInput ; i++){
            inputUser[i] = toupper(inputUser[i]); // On met en majuscule.


            if(((int)inputUser[i] < 48 || (int)inputUser[i] > 57) && ((int)inputUser[i] < 65 || (int)inputUser[i] > 70)){ // On vérifie les valeurs de 0 à 9 puis de A à F.
                std::cout << "\n[X] - The Value is not in Hexadecimal. Retry..." << std::endl;
                break;
            }

            else{

                std::cout << "[*] - Transform the Input in Decimal ..." << std::endl;
                std::cout << "[*] - The Result is : " << convHexToDec( inputUser , lenUserInput) <<  std::endl;
                break;
            }
        }

        return 1;
    }


}

int convHexToDec(std::string inputUserValidate , int lenUserInput){

    int result = 0;
    int t = lenUserInput;

    for(int j = 0  ; j < lenUserInput  ; j++){


        if(inputUserValidate[j] >= 65 && inputUserValidate[j] <= 70){
            result = result + (((int)inputUserValidate[j] - 55) * pow(16, t - 1));
        }

        else if(inputUserValidate[j] >= 48 && inputUserValidate[j] <= 57){
            std::cout << " rezrez : " << inputUserValidate[j] << std::endl;
            result = result + ((int)inputUserValidate[j] - 48) * pow(16, t - 1); // Exemple 2F : 0 + 2 * 16^1
        }

        t -= 1;

    }

    return result;
}




int main(){

    std::string userInput;

    if(!askUserHexandCheck(userInput)){
        std::cout << "[X] - No User Input, retry." << std::endl;
    }

    return 0;
}