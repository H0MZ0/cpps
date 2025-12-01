#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

void printSection(std::string title) {
	std::cout << "\n========================================" << std::endl;
	std::cout << title << std::endl;
	std::cout << "========================================" << std::endl;
}

int main()
{
	printSection("TEST 1: Subject's Main Test");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}

	printSection("TEST 2: Creating Unknown Materia Type");
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		AMateria* unknown = src->createMateria("fire");
		if (unknown == NULL)
			std::cout << "✓ Correctly returned NULL for unknown type" << std::endl;
		else
			std::cout << "✗ ERROR: Should return NULL for unknown type" << std::endl;
		delete src;
	}

	printSection("TEST 3: Full Inventory (4 Materias Max)");
	{
		ICharacter* hero = new Character("Hero");
		AMateria* m1 = new Ice();
		AMateria* m2 = new Cure();
		AMateria* m3 = new Ice();
		AMateria* m4 = new Cure();
		AMateria* m5 = new Ice(); // 5th one - should not fit
		
		hero->equip(m1);
		hero->equip(m2);
		hero->equip(m3);
		hero->equip(m4);
		std::cout << "Trying to equip 5th materia (inventory full)..." << std::endl;
		hero->equip(m5);
		
		std::cout << "Inventory contents (should have 4 materias):" << std::endl;
		ICharacter* target = new Character("Target");
		hero->use(0, *target);
		hero->use(1, *target);
		hero->use(2, *target);
		hero->use(3, *target);
		
		// delete m5; // Must delete the 5th one manually since it wasn't equipped
		delete target;
		delete hero;
	}

	printSection("TEST 4: Unequip and Memory Management");
	{
		ICharacter* wizard = new Character("Wizard");
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		
		wizard->equip(ice);
		wizard->equip(cure);
		
		std::cout << "Before unequip:" << std::endl;
		ICharacter* dummy = new Character("Dummy");
		wizard->use(0, *dummy);
		wizard->use(1, *dummy);
		
		std::cout << "\nUnequipping slot 0..." << std::endl;
		wizard->unequip(0);
		
		std::cout << "After unequip (slot 0 should be empty):" << std::endl;
		wizard->use(0, *dummy); // Should do nothing
		wizard->use(1, *dummy); // Should still work
		
		std::cout << "\nManually deleting unequipped materia..." << std::endl;
		delete ice; // WE must delete it after unequip
		
		delete dummy;
		delete wizard;
		// Note: cure is deleted by wizard's destructor
	}

	printSection("TEST 5: Invalid Index Tests");
	{
		ICharacter* test = new Character("Test");
		test->equip(new Ice());
		
		ICharacter* target = new Character("Target");
		std::cout << "Testing negative index (-1):" << std::endl;
		test->use(-1, *target);
		
		std::cout << "Testing out of bounds index (4):" << std::endl;
		test->use(4, *target);
		
		std::cout << "Testing valid index (0):" << std::endl;
		test->use(0, *target);
		
		std::cout << "Testing empty slot (3):" << std::endl;
		test->use(3, *target);
		
		std::cout << "\nTesting unequip with invalid indices:" << std::endl;
		test->unequip(-1);
		test->unequip(10);
		
		delete target;
		delete test;
	}

	printSection("TEST 6: Character Deep Copy (Copy Constructor)");
	{
		std::cout << "Creating original character with 2 materias..." << std::endl;
		Character* original = new Character("Original");
		original->equip(new Ice());
		original->equip(new Cure());
		
		std::cout << "\nCreating copy via copy constructor..." << std::endl;
		Character* copy = new Character(*original);
		
		std::cout << "\nDeleting original..." << std::endl;
		delete original;
		
		std::cout << "\nUsing copy (should work independently):" << std::endl;
		ICharacter* target = new Character("Target");
		copy->use(0, *target);
		copy->use(1, *target);
		
		std::cout << "\nIf this works without crash, deep copy succeeded!" << std::endl;
		
		delete target;
		delete copy;
	}

	printSection("TEST 7: Character Deep Copy (Assignment Operator)");
	{
		std::cout << "Creating two characters..." << std::endl;
		Character* char1 = new Character("Char1");
		Character* char2 = new Character("Char2");
		
		char1->equip(new Ice());
		char1->equip(new Cure());
		char2->equip(new Ice());
		
		std::cout << "\nBefore assignment:" << std::endl;
		ICharacter* target = new Character("Target");
		std::cout << "Char1 inventory:" << std::endl;
		char1->use(0, *target);
		char1->use(1, *target);
		std::cout << "Char2 inventory:" << std::endl;
		char2->use(0, *target);
		
		std::cout << "\nAssigning char2 = char1..." << std::endl;
		*char2 = *char1;
		
		std::cout << "\nAfter assignment (char2 should have char1's materias):" << std::endl;
		char2->use(0, *target);
		char2->use(1, *target);
		
		std::cout << "\nDeleting char1..." << std::endl;
		delete char1;
		
		std::cout << "Using char2 after char1 deleted (deep copy test):" << std::endl;
		char2->use(0, *target);
		
		delete target;
		delete char2;
	}

	printSection("TEST 8: Self-Assignment Test");
	{
		Character* self = new Character("Self");
		self->equip(new Ice());
		
		std::cout << "Performing self-assignment (self = self)..." << std::endl;
		*self = *self;
		
		std::cout << "Using materia after self-assignment:" << std::endl;
		ICharacter* target = new Character("Target");
		self->use(0, *target);
		
		std::cout << "✓ Self-assignment handled correctly" << std::endl;
		
		delete target;
		delete self;
	}

	printSection("TEST 9: MateriaSource - Learning 4+ Materias");
	{
		IMateriaSource* src = new MateriaSource();
		
		std::cout << "Learning 4 materias..." << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		std::cout << "Trying to learn 5th materia (should not fit)..." << std::endl;
		AMateria* fifth = new Ice();
		src->learnMateria(fifth);
		
		std::cout << "Creating materias from learned templates:" << std::endl;
		AMateria* ice = src->createMateria("ice");
		AMateria* cure = src->createMateria("cure");
		
		if (ice)
			std::cout << "✓ Created ice materia" << std::endl;
		if (cure)
			std::cout << "✓ Created cure materia" << std::endl;
		
		delete ice;
		delete cure;
		// delete fifth; // Must delete 5th one manually
		delete src;
	}

	printSection("TEST 10: MateriaSource Deep Copy");
	{
		std::cout << "Creating original MateriaSource..." << std::endl;
		MateriaSource* original = new MateriaSource();
		original->learnMateria(new Ice());
		original->learnMateria(new Cure());
		
		std::cout << "\nCreating copy..." << std::endl;
		MateriaSource* copy = new MateriaSource(*original);
		
		std::cout << "\nDeleting original..." << std::endl;
		delete original;
		
		std::cout << "\nCreating materias from copy (should work):" << std::endl;
		AMateria* ice = copy->createMateria("ice");
		AMateria* cure = copy->createMateria("cure");
		
		if (ice) {
			std::cout << "✓ Copy can create ice" << std::endl;
			delete ice;
		}
		if (cure) {
			std::cout << "✓ Copy can create cure" << std::endl;
			delete cure;
		}
		
		delete copy;
	}

	printSection("TEST 11: Clone() Method Test");
	{
		std::cout << "Creating original materias..." << std::endl;
		AMateria* originalIce = new Ice();
		AMateria* originalCure = new Cure();
		
		std::cout << "Cloning materias..." << std::endl;
		AMateria* clonedIce = originalIce->clone();
		AMateria* clonedCure = originalCure->clone();
		
		std::cout << "Original types: " << originalIce->getType() 
				  << ", " << originalCure->getType() << std::endl;
		std::cout << "Cloned types: " << clonedIce->getType() 
				  << ", " << clonedCure->getType() << std::endl;
		
		std::cout << "\nUsing cloned materias:" << std::endl;
		ICharacter* target = new Character("Target");
		clonedIce->use(*target);
		clonedCure->use(*target);
		
		delete originalIce;
		delete originalCure;
		delete clonedIce;
		delete clonedCure;
		delete target;
	}

	printSection("TEST 12: Multiple Unequip and Re-equip");
	{
		ICharacter* player = new Character("Player");
		AMateria* ice1 = new Ice();
		AMateria* cure1 = new Cure();
		AMateria* ice2 = new Ice();
		
		player->equip(ice1);
		player->equip(cure1);
		
		std::cout << "Unequipping slot 0..." << std::endl;
		player->unequip(0);
		
		std::cout << "Re-equipping new materia in slot 0..." << std::endl;
		player->equip(ice2);
		
		ICharacter* target = new Character("Target");
		std::cout << "\nUsing slot 0 (should be new ice):" << std::endl;
		player->use(0, *target);
		std::cout << "Using slot 1 (should be cure):" << std::endl;
		player->use(1, *target);
		
		delete ice1; // Manually delete unequipped one
		delete target;
		delete player;
	}

	printSection("TEST 13: Equip NULL Materia");
	{
		ICharacter* test = new Character("Test");
		std::cout << "Trying to equip NULL materia..." << std::endl;
		test->equip(NULL);
		std::cout << "✓ Handled NULL equip gracefully" << std::endl;
		delete test;
	}

	printSection("TEST 14: Learn NULL Materia");
	{
		IMateriaSource* src = new MateriaSource();
		std::cout << "Trying to learn NULL materia..." << std::endl;
		src->learnMateria(NULL);
		std::cout << "✓ Handled NULL learn gracefully" << std::endl;
		delete src;
	}

	printSection("ALL TESTS COMPLETED!");
	std::cout << "\nRun with valgrind to check for memory leaks:" << std::endl;
	std::cout << "valgrind --leak-check=full --show-leak-kinds=all ./Interface" << std::endl;
	std::cout << "\nExpected result: 0 bytes leaked, no errors" << std::endl;

	return 0;
}