# Test Report: TestCharacter

*Test File:* TestCharacter.cpp  
*Test Objective:* Verify that derived character classes (Warrior, Mage, and Rogue) correctly initialize with the expected attributes: name, health, and mana.

---

## Test Cases and Results

| Character        | Property Tested | Expected Value | Actual Value | Status |
|------------------|----------------|----------------|--------------|--------|
| Warrior ("Alice") | getName()    | "Alice"      | "Alice"    | Passed |
|                  | getHealth()   | 120          | 120        | Passed |
|                  | getMana()     | 30           | 30         | Passed |
| Mage ("Bob")   | getName()     | "Bob"        | "Bob"      | Passed |
|                  | getHealth()   | 80           | 80         | Passed |
|                  | getMana()     | 100          | 100        | Passed |
| Rogue ("Cara") | getName()     | "Cara"       | "Cara"     | Passed |
|                  | getHealth()   | 90           | 90         | Passed |
|                  | getMana()     | 50           | 50         | Passed |

---

## Summary

- *Total Tests:* 9  
- *Passed:* 9  
- *Failed:* 0  
- *Status:* All tests passed successfully.

---

## Notes

- All assertions were completed using the assert() macro.
- No runtime errors or failed assertions occurred.
- This test verifies object construction and attribute correctness only; no behavior or methods beyond getters were tested.