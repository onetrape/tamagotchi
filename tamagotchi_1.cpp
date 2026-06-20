#include <iostream>
#include <string>

class Tamagotchi {
private:
    std::string name;
    int hunger;
    int happiness;
    int energy;

   
    int clamp(int value) {
        if (value < 0) return 0;
        if (value > 100) return 100;
        return value;
    }

public:
   
    Tamagotchi(std::string petName) {
        name = petName;
        hunger = 50;
        happiness = 50;
        energy = 50;
    }

    // Годування улюбленця
    void feed() {
        hunger = clamp(hunger - 20);
        happiness = clamp(happiness + 5);
        energy = clamp(energy - 5);
        std::cout << name << " поїв(ла).\n";
    }

    // Гра з улюбленцем
    void play() {
        if (energy < 15) {
            std::cout << name << " занадто втомлений(а), щоб гратися!\n";
            return;
        }
        happiness = clamp(happiness + 15);
        energy = clamp(energy - 15);
        hunger = clamp(hunger + 10);
        std::cout << name << " пограв(ла) і трохи втомився(лась).\n";
    }

    // Сон улюбленця
    void sleep() {
        energy = clamp(energy + 30);
        hunger = clamp(hunger + 10);
        happiness = clamp(happiness - 5);
        std::cout << name << " добре поспав(ла).\n";
    }

    // Перехід до наступного дня
    void nextDay() {
        hunger = clamp(hunger + 15);
        happiness = clamp(happiness - 10);
        energy = clamp(energy - 10);
        std::cout << "Настав новий день для " << name << ".\n";
    }

    // Виведення поточного стану улюбленця
    void showStatus() {
        std::cout << "Name: " << name << "\n";
        std::cout << "Hunger: " << hunger << "\n";
        std::cout << "Happiness: " << happiness << "\n";
        std::cout << "Energy: " << energy << "\n";
    }

    // Повертає настрій улюбленця залежно від happiness
    std::string getMood() {
        if (happiness >= 70) {
            return "Happy";
        } else if (happiness >= 40) {
            return "Normal";
        } else if (happiness >= 20) {
            return "Sad";
        } else {
            return "Critical";
        }
    }
};

int main() {
    Tamagotchi pet("Bobik");

    std::cout << "=== Початковий стан ===\n";
    pet.showStatus();
    std::cout << "Настрій: " << pet.getMood() << "\n\n";

    std::cout << "=== Годуємо улюбленця ===\n";
    pet.feed();
    pet.showStatus();
    std::cout << "\n";

    std::cout << "=== Граємось з улюбленцем ===\n";
    pet.play();
    pet.showStatus();
    std::cout << "\n";

    std::cout << "=== Улюбленець спить ===\n";
    pet.sleep();
    pet.showStatus();
    std::cout << "\n";

    std::cout << "=== Настає новий день ===\n";
    pet.nextDay();
    pet.showStatus();
    std::cout << "Настрій: " << pet.getMood() << "\n\n";

    // Перевірка межі: якщо energy замала, грати не можна
    std::cout << "=== Перевірка обмеження для play() ===\n";
    for (int i = 0; i < 4; i++) {
        pet.play(); // знижуємо energy, поки вона не стане < 15
    }
    pet.showStatus();
    pet.play(); // ця спроба має бути заблокована

    return 0;
}
