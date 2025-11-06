#include <iostream>
#include <string>
#include <map>

std::string input;
std::string command;
std::string argument;

class LED{
    private:
    std::string name;
    bool status;


    public:
    LED(std::string chosen_name){
        status = false;
        name = chosen_name;
    }

    std::string getName(){ return name; }

    void turn_on(){
        status = true;
        std::cout << name <<" is now ON" << "\n\n";
    }

    void turn_off(){
        status = false;
        std::cout << name <<" is now OFF" << "\n\n";
    }

    void display_status(){
        std::string current_status = (status == true) ? "ON" : "OFF";

        std::cout << name <<" status is " << current_status << "\n\n";
    }

};

void to_lower_case(std::string &command);
void help_command();

auto trim = [](std::string &s) {
    size_t start = s.find_first_not_of(" ");
    size_t end   = s.find_last_not_of(" ");
    if (start == std::string::npos) { s = ""; return; }
    s = s.substr(start, end - start + 1);
};

std::map<std::string, LED> leds;


int main(){
    std::cout << "Welcome to the Mini Commander!" << "\n";
    std::cout << "If you want to see all commands type 'help'" << "\n\n";

    while(true){
        std::cout << "Insert Command: ";
        getline(std::cin, input);
        trim(input);

        size_t spacePos = input.find(' ');
        
        if (spacePos == std::string::npos) {
            // NO space was found
            command = input;
            argument = "";
        } else {
            command = input.substr(0, spacePos);
            argument = input.substr(spacePos + 1);
            trim(argument);
        }

        to_lower_case(command);

        if(command == "add"){
            std::string name_led = argument;

            if (leds.count(name_led)) {
                std::cout << "LED '" << name_led << "' already exists.\n";
            } else {
                leds.emplace(name_led, LED(name_led));
                std::cout << "LED '" << name_led << "' created.\n";
            }

        } else if(command == "off" || command == "on" || command == "status"){
            std::string name_led = argument;

            auto it = leds.find(name_led);
            if (it == leds.end()) {
                std::cout << "No LED named '" << name_led << "'.\n";
            } else {
                LED &led = it->second;
                if (command == "on") led.turn_on();
                else if (command == "off") led.turn_off();
                else if (command == "status") led.display_status();
            }

        }else if(command == "help"){
            help_command();

        } else if(command == "exit"){
            std::cout << "Goodbye, until next time!" << "\n\n";
            break;

         }else {
            std::cout << "'" << command << "' is a invalid command, Please type a valid command!" << "\n\n";
        }

    }

    return 0;
}


void to_lower_case(std::string &command){
    for(int i = 0; i < command.length(); i++){
        if(command[i] >= 'A' && command[i] <= 'Z'){
            command[i] = command[i] + ('a' - 'A');
        }
    }
}

void help_command(){
    std::cout << "All commands: add <name>, on <name>, off <name>, status <name>, help, exit" << "\n\n";
}