#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum class archive {
    MainMenu,
    SearchingAlgorithms,
    SortingAlgorithms,
    LinealDataStructures,
    NonlinearDataStructures,
    SearchSubmenu,
    SortSubmenu
};

vector<sf::Text> createMenuItems(const vector<string>& items, sf::Font& font) {
    vector<sf::Text> texts;
    for (size_t i = 0; i < items.size(); ++i) {
        sf::Text text;
        text.setFont(font);
        text.setString(items[i]);
        text.setCharacterSize(60);
        text.setFillColor(sf::Color::White);
        text.setPosition(100.f, 200.f + i * 80.f);
        texts.push_back(text);
    }
    return texts;
}

int main() {
    // Create window
    sf::RenderWindow window(sf::VideoMode(1500, 800), "Code Archive");

    // Load font
    sf::Font font;
    if (!font.loadFromFile("C:/Users/hanes/Downloads/vcr_osd_mono/VCR_OSD_MONO_1.001.ttf")) {
        return -1; // Error handling
    }


    // Define menu items for each state
    map<archive, vector<string>> menuItems = {
        {archive::MainMenu, {"Searching Algorithms", "Sorting Algorithms", "Lineal Data Structures", "Non-linear Data Structures", "Exit"}},
        {archive::SearchingAlgorithms, {"Binary Search", "Linear Search", "Back"}},
        {archive::SortingAlgorithms, {"Quick Sort", "Merge Sort", "Back"}},
        {archive::LinealDataStructures, {"Stacks","Queues", "Linked Lists", "Back"}},
        {archive::NonlinearDataStructures, {"Binary Tree AVL", "Dijkstra", "BFS", "DFS", "Back"}}
    };

    archive currentState = archive::MainMenu; // Current state
    archive previousState = archive::MainMenu; // Store the previous state for going back
    vector<sf::Text> menuTexts = createMenuItems(menuItems[currentState], font);

    size_t selectedIndex = 0; // Tracks the currently selected menu item
    menuTexts[selectedIndex].setFillColor(sf::Color::Red); // Highlight the first item

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up) {
                    // Move selection up
                    menuTexts[selectedIndex].setFillColor(sf::Color::White);
                    selectedIndex = (selectedIndex > 0) ? selectedIndex - 1 : menuTexts.size() - 1;
                    menuTexts[selectedIndex].setFillColor(sf::Color::Red);
                } else if (event.key.code == sf::Keyboard::Down) {
                    // Move selection down
                    menuTexts[selectedIndex].setFillColor(sf::Color::White);
                    selectedIndex = (selectedIndex + 1) % menuTexts.size();
                    menuTexts[selectedIndex].setFillColor(sf::Color::Red);
                } else if (event.key.code == sf::Keyboard::Enter) {
                    // Handle selection
                    string selectedItem = menuItems[currentState][selectedIndex];

                    if (selectedItem == "Exit") {
                        window.close();
                    } else if (selectedItem == "Back") {
                        currentState = previousState;

                    } else if (selectedItem == "Searching Algorithms") {
                        previousState = currentState;
                        currentState = archive::SearchingAlgorithms;

                    } else if (selectedItem == "Sorting Algorithms") {
                        previousState = currentState;
                        currentState = archive::SortingAlgorithms;

                    } else if (selectedItem == "Lineal Data Structures") {
                        previousState = currentState;
                        currentState = archive::LinealDataStructures;
                        // Add logic for Lineal Data Structures
                    } else if (selectedItem == "Non-linear Data Structures") {
                        previousState = currentState;
                        currentState = archive::NonlinearDataStructures;
                        // Add logic for Non-linear Data Structures
                    } else {
                        // Handle sub-options like "Binary Search", "Quick Sort", etc.
                        previousState = currentState;
                        // You can transition to another state if needed here
                    }

                    // Update menu items for the new state
                    menuTexts = createMenuItems(menuItems[currentState], font);
                    selectedIndex = 0; // Reset selection
                    menuTexts[selectedIndex].setFillColor(sf::Color::Red); // Highlight the first item


                } else if (event.key.code == sf::Keyboard::Backspace) {
                    // Go back to the previous menu
                    currentState = previousState;
                    menuTexts = createMenuItems(menuItems[currentState], font);
                    selectedIndex = 0; // Reset selection
                    menuTexts[selectedIndex].setFillColor(sf::Color::Red); // Highlight the first item
                }
            }
        }

        // Draw the current menu
        window.clear();
        for (const auto& text : menuTexts) {
            window.draw(text);
        }
        window.display();
    }

    return 0;
}