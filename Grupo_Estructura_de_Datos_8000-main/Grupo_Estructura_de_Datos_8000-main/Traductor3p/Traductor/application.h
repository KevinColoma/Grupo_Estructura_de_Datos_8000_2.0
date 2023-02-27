#pragma once
#include <windows.h>
#include "utils.h"
#include <iostream>
#include "avl_tree.h"
#include <vector>
#include <thread>
#include "menu.h"

//
#include <sapi.h>
#include <string>
#include <locale>
#include <codecvt>
#include <cstring>
#include <wchar.h>

// Función que convierte un std::string a un const wchar_t*
const wchar_t* string_to_wchar(const std::string& str) {
	// Crea un objeto de conversión de codecvt para UTF-8 a UTF-16
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	// Convierte la cadena de entrada a una cadena wstring UTF-16
	std::wstring wstr = converter.from_bytes(str);
	// Crea un búfer de caracteres wchar_t en el montón
	size_t len = wstr.length() + 1;
	wchar_t* buf = new wchar_t[len];
	// Copia los caracteres wstring en el búfer wchar_t
	std::memcpy(buf, wstr.c_str(), len * sizeof(wchar_t));
	// Devuelve el búfer, que debe ser eliminado por el llamante
	return buf;
}

// Función que utiliza SAPI para leer un texto en voz alta
void speak(const std::string& str) {
	// Convierte el std::string a un const wchar_t*
	const wchar_t* text = string_to_wchar(str);

	// Inicializa SAPI
	CoInitialize(NULL);

	// Crea una instancia de la voz
	ISpVoice* pVoice = NULL;
	HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void**)&pVoice);
	if (SUCCEEDED(hr)) {
		// Establece la velocidad de la voz
		hr = pVoice->SetRate(-1);
		if (SUCCEEDED(hr)) {
			// Lee el texto en voz alta
			hr = pVoice->Speak(text, 0, NULL);
		}
		// Libera los recursos
		pVoice->Release();
	}

	// Finaliza SAPI
	CoUninitialize();

	// Elimina el búfer wchar_t
	delete[] text;
}
//
template <typename T = std::string, typename K = std::string>
class HashTable;
//
class AvlTree;
enum ApplicationState
{
	RUN,
	STOP,
	RUNNING
};

enum Language
{
	ENGLISH = 1,
	SPANISH = 2
};

class Application
{
public:
	static inline int run(int);
	static inline void exit();

private:
	static inline void main_menu();
	static inline void administrator_menu();
	static inline void user_menu();

private:
	static inline void init_tree(AvlTree&, int state, int type);
	static inline void find_word();
	static inline void list_words();

	static inline void new_admin();
	static inline void add_word();
	static inline void remove_word();

	////////////////////

};

int inline Application::run(int state)
{
	std::cout << "  \n\n\n\n\n                       Cargado correctamente....." << std::endl;
	AvlTree tree{};
	AvlTree temp{};

	if (state == ApplicationState::RUN)
	{
		init_tree(tree, ApplicationState::RUN, Language::ENGLISH);
		init_tree(temp, ApplicationState::RUN, Language::SPANISH);

		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		system("cls");
		main_menu();
	}
	return 0;
}

inline void Application::main_menu() {
	while (true)
	{
		std::cout << "( 1 ) AVL-TREE" << std::endl;
		std::cout << "( 3 ) SALIR" << std::endl;
		int opcion = Utils::Validation::read_int("Por favor  Seleccione una opcion: ", 1, 1);
		std::cin.ignore();
		switch (opcion)
		{
		case 1:
		{
			std::cout << "________________MENU _____________" << std::endl;
			std::vector<MenuOption> menu_item{

				{1, "INICIAR COMO ADMINISTRADOR", administrator_menu},
				{2, "INICIAR COMO USUARIO", user_menu},
				{3, "SALIR DEL PROGRAMA", exit} };
			Menu menu{ menu_item };
			menu.navigation();
			break;
		}

		case 3:
		{
			std::exit(0);
		}
		default:
		{
			std::cout << "¡¡   Opcion no valida   !!" << std::endl;
			system("cls");
			main_menu();
		}
		}
	}
}

inline void Application::administrator_menu()
{
	std::cout << "Administrador" << std::endl;
	std::string user = Utils::Validation::read_string("Ingrese su usuario: ", Utils::InputType::USER);
	std::string password = Utils::Validation::read_string("Ingrese su contrasenia: ", Utils::InputType::PASSWORD);
	std::cout << std::endl;

	if (Utils::Login::login(user, password))
	{
		std::vector<MenuOption> menu_item{
			{1, "BUSCAR UNA PALABRA", find_word},
			{2, "LISTAR PALABRAS", list_words},
			{3, "INGRESAR NUEVA PALABRA", add_word},
			{4, "ELIMINAR UNA PALABRA", remove_word},
			{5, "CREAR UN ADMINISTRADOR", new_admin},
			{6, "REGRESAR AL MENU", main_menu},
			{7, "SALIR DEL PROGRAMA ", exit} };

		Menu menu{ menu_item };
		menu.navigation();
	}
	else
	{
		if (!Utils::File::exists_file("user.txt"))
		{
			std::cout << "NO EXISTE NINGUN ADMINISTRADOR PRINCIPAL" << std::endl;
			std::string user = Utils::Validation::read_string("Crear usuario: ", Utils::InputType::USER);
			std::string password = Utils::Validation::read_string("Ingrese la contrasenia: ", Utils::InputType::PASSWORD);
			Utils::Generator::generate_admins(user, password);
			std::cout << "\nAdministrador principal creado" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			main_menu();
		}
		std::cout << "\n   USUARIO O CONTRASENIA INCORRECTO/A  \n " << std::endl;
		std::cin.get();

		main_menu();
	}
}
// MENU  USER
inline void Application::user_menu()
{
	std::vector<MenuOption> menu_item{
		{1, "  BUSCAR UNA PALABRA", find_word},
		{2, "  LISTAR PALABRAS", list_words},
		{3, "  REGRESAR", main_menu},
	};

	Menu menu{ menu_item };
	menu.navigation();
}


inline void Application::exit()
{
	AvlTree tree;
	init_tree(tree, ApplicationState::RUNNING, Language::ENGLISH);
	std::cout << "  Actualizando datos..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	init_tree(tree, ApplicationState::STOP, Language::ENGLISH);
	std::cout << " Gracias por la atencion , Programa finalizado  " << std::endl;
	std::exit(0);
}

inline void Application::init_tree(AvlTree& tree, int state, int type)
{

	static AvlTree temp_tree_spanish;
	static AvlTree temp_tree_english;
	if (state == ApplicationState::RUN)
	{
		if (type == Language::ENGLISH)
		{
			Utils::File::load_tree(temp_tree_english, "dic.txt", Language::ENGLISH);
		}
		if (type == Language::SPANISH)
		{
			Utils::File::load_tree(temp_tree_spanish, "dic.txt", Language::SPANISH);
		}
	}
	else if (state == ApplicationState::RUNNING)
	{
		if (type == Language::SPANISH)
		{
			tree = temp_tree_spanish;
		}
		if (type == Language::ENGLISH)
		{
			tree = temp_tree_english;
		}
	}
	else if (state == ApplicationState::STOP)
	{
		Utils::File::save_tree(tree, "dic.txt");
	}
}

inline void Application::find_word()
{
	enum LanguageType
	{
		ENGLISH = 1,
		SPANISH = 2
	};
	int option = 0;
	while (true)
	{
		std::cout << "       BUSCAR PALABRA[INGLES - ESPA]  o  [ESPA - INGLES] \n" << std::endl;
		std::cout << " ( 1 ) IMPRIMIR   INGLES-ESPANIOL    " << std::endl;
		std::cout << " ( 2 ) IMPRIMIR   ESPA-INGLES    " << std::endl;
		option = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));

		if (option == ENGLISH || option == SPANISH)
		{
			break;
		}

	}
	std::cin.ignore();
	std::string word = Utils::Validation::read_string(
		"Ingrese la palabra a Traducir: ", Utils::InputType::WORD);
	AvlTree tree;
	Application::init_tree(tree, ApplicationState::RUNNING, Language::ENGLISH);
	if (tree.has(word))
	{
		std::vector<AvlNode*> node = tree.find(word);

		if (option == ENGLISH)
		{
			std::cout << "\nTotal de palabras encontradas: " << node.size() << std::endl;
			int i = 1;
			for (auto& n : node)
			{
				std::cout << "( " << i << " ) " << n->english_word() << ": "
					<< n->spanish_word() << std::endl;
				speak(n->english_word());////////////////
				speak(n->spanish_word());
				i++;
			}
		}
		if (option == SPANISH)
		{
			std::cout << "\nTotal de palabras encontradas: " << node.size() << std::endl;
			int i = 1;
			for (auto& n : node)
			{
				std::cout << "( " << i << " ) " << n->spanish_word() << ": "
					<< n->english_word() << std::endl;
				speak(n->spanish_word());////////////////
				speak(n->english_word());
				i++;
			}
		}
		node.clear();
	}
	else
	{
		std::cout << "\nNO EXISTE LA PALABRA EN EL DICCIONARIO..\n    de ser necesario consulte con el  administrador" << std::endl;
	}
	std::cin.get();
	std::cout << "\033[2J\033[1;1H";
}

inline void Application::list_words()
{
	enum TypeTraversal
	{
		PREORDER = 1,
		INORDER = 2,
		POSTORDER = 3
	};
	enum LanguageType
	{
		ENGLISH = 1,
		SPANISH = 2
	};

	int option = 0;
	while (true)
	{
		std::cout << "LISTAR PALABRAS [PREORDEN] [INORDER] [POSTORDER]" << std::endl;
		std::cout << "( 1 )  PREORDER" << std::endl;
		std::cout << "( 2 )  INORDER[ALFABETICO]" << std::endl;
		std::cout << "( 3 )  POSTORDER" << std::endl;
		option = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));
		if (option == PREORDER || option == INORDER || option == POSTORDER)
		{
			break;
		}
		system("cls");
	}
	AvlTree tree_spanish; //[ESPANiOL/INGLES]
	AvlTree tree_english; //[INGLES/ESPAniOL]
	Application::init_tree(tree_spanish, ApplicationState::RUNNING, Language::SPANISH);
	Application::init_tree(tree_english, ApplicationState::RUNNING, Language::ENGLISH);

	if (option == PREORDER)
	{
		int op = 0;
		while (true)
		{
			std::cout << " ( 1 ) INGLES/ESPA" << std::endl;
			std::cout << "( 2 ) ESPA/INGLES" << std::endl;
			op = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));
			if (op == ENGLISH || op == SPANISH)
			{
				break;
			}
			system("cls");
		}

		if (op == ENGLISH)
		{
			tree_english.for_each_preorder([](AvlNode* node)
				{ std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
			std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_english.get_size() << std::endl;
		}
		if (op == SPANISH)
		{
			tree_spanish.for_each_preorder([](AvlNode* node)
				{ std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
			std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_spanish.get_size() << std::endl;
		}
	}
	if (option == INORDER)
	{
		int op = 0;
		while (true)
		{
			std::cout << "( 1 ) INGLES/ESPA" << std::endl;
			std::cout << "( 2 ) ESPA/INGLES" << std::endl;
			op = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));
			if (op == ENGLISH || op == SPANISH)
			{
				break;
			}
			system("cls");
		}

		if (op == ENGLISH)
		{
			tree_english.for_each_inorder([](AvlNode* node)
				{ std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
			std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_english.get_size() << std::endl;
			std::cin.get();
			std::cout << "\033[2J\033[1;1H";
		}
		if (op == SPANISH)
		{
			tree_spanish.for_each_inorder([](AvlNode* node)
				{ std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
			std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_spanish.get_size() << std::endl;
		}
	}
	if (option == POSTORDER)
	{
		int op = 0;
		while (true)
		{
			std::cout << "( 1 )INGLES/ESPA" << std::endl;
			std::cout << "( 2 ) ESPA/INGLES" << std::endl;
			op = (Utils::Validation::read_int("\nIngrese la opcion: ", 1, 1));
			if (op == ENGLISH || op == SPANISH)
			{
				break;
			}
			system("cls");
		}

		if (op == ENGLISH)
		{
			tree_english.for_each_postorder([](AvlNode* node)
				{ std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
			std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_english.get_size() << std::endl;
		}
		if (op == SPANISH)
		{
			tree_spanish.for_each_postorder([](AvlNode* node)
				{ std::cout << node->english_word() << ": " << node->spanish_word() << std::endl; });
			std::cout << "\nTOTAL PALABRAS EN EL DICCIONARIO: " << tree_spanish.get_size() << std::endl;
		}
	};
	system("pause");
}

inline void Application::new_admin()
{
	std::cout << "Desea Crear un nuevo administrador[s/n]: ";
	char option = 0;
	std::cin >> option;
	std::cin.ignore();
	if (option == 's' || option == 'S')
	{
		system("cls");
		std::cout << "Ingrese los datos del administrador principal: " << std::endl;
		std::string user_admin = Utils::Validation::read_string("Ingrese el usuario: ", Utils::InputType::USER);
		std::string password_admin = Utils::Validation::read_string("Ingrese la contrasenia: ", Utils::InputType::PASSWORD);
		std::cout << std::endl;

		if (Utils::Login::login(user_admin, password_admin))
		{
			std::string new_user = Utils::Validation::read_string("Crear usuario: ", Utils::InputType::USER);
			std::string new_password = Utils::Validation::read_string("Ingrese la contrasenia: ", Utils::InputType::PASSWORD);
			Utils::Generator::generate_admins(new_user, new_password);
			std::cout << "Administrado creado con exito" << std::endl;
			main_menu();
		}
		else
		{
			std::cout << "Credenciales incorrectas, regresando al menu principal. " << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			administrator_menu();
		}
	}
	else
	{
		administrator_menu();
	}
}

inline void Application::add_word()
{
	AvlTree tree;
	Application::init_tree(tree, ApplicationState::RUNNING, Language::ENGLISH);
	while (true)
	{
		std::cout << "Ingrese la palabra a insertar." << std::endl;

		std::string spanish_word = Utils::Validation::read_string("Espaniol: ", Utils::InputType::WORD);
		std::string english_word = Utils::Validation::read_string("Ingles: ", Utils::InputType::WORD);

		if (tree.has(english_word))
		{
			std::cout << "La palabra ya existe en el diccionario." << std::endl;
		}
		else
		{
			tree.insert(spanish_word, english_word);
		}
		std::cout << "Desea agregar otra palabra[s/n]: ";
		char option = 0;
		std::cin >> option;
		std::cin.ignore();
		if (option == 's' || option == 'S')
		{
			continue;
		}
		else
		{
			break;
		}
	}
	system("cls");
	administrator_menu();
}

inline void Application::remove_word()
{

	while (true)
	{
		std::cout << "ELIMINAR PALABRAS" << std::endl;
		std::cout << "Ingrese la palabra a eliminar." << std::endl;
		std::string word = Utils::Validation::read_string("\nPalabra: ", Utils::InputType::WORD);
		AvlTree tree;
		Application::init_tree(tree, ApplicationState::RUNNING, Language::ENGLISH);

		if (tree.has(word))
		{
			tree.remove(word);
			std::cout << "ELIMINACION EXITOSA" << std::endl;
		}
		else
		{
			std::cout << "LA PALABRA INGRESADA NO EXISTE EN EL DICCIONARIO" << std::endl;
		}
		std::cout << "\nDesea eliminar otra palabra[s/n]: ";
		char option = 0;
		std::cin >> option;
		std::cin.ignore();
		if (option == 's' || option == 'S')
		{
			continue;
		}
		else
		{
			break;
		}
	}
}


