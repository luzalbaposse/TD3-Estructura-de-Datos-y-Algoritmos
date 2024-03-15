#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

map<string, int> info_personas = { {"Ada", 1800}, {"Barbara", 1939}};

info_personas["Rebeca"] = 1926; // Ahora Rebeca tiene 1926
info_personas["Ada"] = 1815; // Ahora Ada tiene 1815

info_personas["Ada"] // devuelve 1815
info_personas.contains("Alan") // false
info_personas.size() // 2
info_personas.empty() // false