#include <iostream>
#include <string>
using namespace std;

string command;
int LED_status = 0;
void to_lower_case(string &command);
void turn_led_on();
void turn_led_off();
void help_command();
void display_status();


int main(){
    cout << "Welcome to the Mini Commander!" << "\n";
    cout << "If you want to see all commands type 'help'" << "\n\n";

    while(true){
        cout << "Insert Command: ";
        getline(cin, command);

        to_lower_case(command);

        if(command == "led on"){
            turn_led_on();

        } else if(command == "led off"){
            turn_led_off();

        } else if(command == "help"){
            help_command();

        } else if(command == "status"){
            display_status();

        } else if(command == "exit"){
            cout << "Goodbye, until next time!" << "\n\n";
            break;

         }else {
            cout << "'" << command << "' is a invalid command, Please type a valid command!" << "\n\n";
        }

    }

    return 0;
}


void to_lower_case(string &command){
    for(int i = 0; i < command.length(); i++){
        if(command[i] >= 'A' && command[i] <= 'Z'){
            command[i] = command[i] + ('a' - 'A');
        }
    }
}

void turn_led_on(){
    LED_status = 1;
    cout << "LED is now ON" << "\n\n";
}

void turn_led_off(){
    LED_status = 0;
    cout << "LED is now OFF" << "\n\n";
}

void help_command(){
    cout << "All commands: led on, led off, status, help, exit" << "\n\n";
}

void display_status(){
    string current_status = (LED_status == 1) ? "ON" : "OFF";

    cout << "The LED status is " << current_status << "\n\n";
}