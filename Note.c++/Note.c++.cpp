#include<iostream>
#include<fstream>
#include<direct.h>
#include<stdio.h>
#include<io.h>
#include<string.h>
#include<string>


using namespace std;


struct Data_Note {
	int ad = 0, choose;
	char name[150], oldName[150], newName[150], file_Name[150], file_name_del[150], path[500], newpath[500];
	bool login = false, pin = false, forget = false, ptrfrget = &forget;
	_finddata_t fileinfo;
	string filesName[150], PinCode, usname, Phrase, usNameCheck, pinCheck, logCheck, CheckPhrase;
	ofstream file;
	intptr_t der;
	ifstream nf;

};


class Folders : public Data_Note
{
public:
	void CreateFolder() {
		//char name[50];
		this->name;
		cout << "Введите директорию для папки:";
		cin >> this->name;
		if (_mkdir(this->name) == -1) {
			cout << "Error" << endl;
		}
		else {
			cout << "Папка созадна!!!" << endl;
		}
	}

	void DeleteFolder() {
		//char name[150];
		cout << "Введите путь к папке:";
		cin >> this->name;
		if (_rmdir(this->name) == -1) {
			cout << "Не удалось удалить файл проверьте наличие файла в папке!!!" << endl;
		}
		else {
			cout << "Папка Удалена!!!" << endl;
		}
	}

	void RenameFolder() {
		//char oldName[150], newName[150];
		cout << "Введите путь к папке название которой хотите изменить:";
		cin >> this->oldName;//C:\Hello
		cout << "Введите новое название папке:";
		cin >> this->newName;//C:\HelloWorld

		//string WordDir = "E:\\Games\\test1";
		//string NewName = ExtractFilePath(WordDir) + "test2";

		if (rename(this->oldName, this->newName) != 0) {
			cout << "Ошибка не найдена папка или в папке есть файлы!!!" << endl;
		}
		else {
			cout << "Папка переименована!!!" << endl;
		}
	}

	void FolderSize() {
		int s = 0;
		cin >> this->path;

		this->der = _findfirst(this->path, &this->fileinfo);

		if (this->der != -1) {
			if (_findnext(this->der, &this->fileinfo) == 0) {
				while (_findnext(this->der, &this->fileinfo) == 0) {
					//cout << this->fileinfo.size << " байт" << endl;
					s += fileinfo.size;

				}
			}
			else {
				cout << "Size:";
				cout << this->fileinfo.size << " байт" << endl;
				s += fileinfo.size;
				cout << "int:" << s << endl;
			}
			cout << "Размер папки:" << s << " байт" << endl;
			//Fill_zero_memset(path, 0);
			_findclose(der);
		}
		else {
			cout << "Error" << endl;
		}

	}

	void CopyFolder() {

		//char oldpath[150] = { 0 }, newpaht[150];
		//_finddata_t fileinfo;
		//intptr_t der;

		//string filesName[150];

		cout << "Enter Old:"; //C:\F1\* .*
		cin >> this->path;
		cout << "Enter Dir to copy"; //C:\F2\/
		cin >> this->newpath;


		der = _findfirst(path, &fileinfo);

		if (der != -1) {
			filesName[0] = fileinfo.name;
			while (_findnext(der, &fileinfo) == 0) {
				filesName[ad] = fileinfo.name;
				ad++;
				cout << ad;
			}
		}
		else {
			cout << "Error" << endl;
		}

		ofstream* file = new ofstream[ad];
		for (int j = 0; j < ad; j++) {
			file[j].open(newpath + filesName[j]);
		}

		delete[] file;
	}
};

class Files :public Data_Note
{
public:
	void CreateFile() {
		cout << "Введите название файла(С расширением и деректорию если нужно):";
		cin >> this->file_Name;
		this->file.open(this->file_Name);
		if (this->file.is_open()) {
			cout << "Файл создан!!!\nПуть к файлу:" << this->file_Name << endl;
			//this->file.close();
		}
		else {
			cout << "Не удалось создать файл" << endl;
		}
	}

	void DeleteFile() {
		//char file_name_del[100];

		cout << "Введите название файла(с расширением и деректорией):";
		cin >> this->file_name_del;

		if (remove(this->file_name_del) == 0) {
			cout << "Файл удален" << endl;
		}
		else {
			cout << "ОШИБКА!!!" << endl;
		}

	}

	void RenameFile() {
		//char oldname[150], newname[150];
		cout << "Old name:";
		cin >> this->oldName;//C:\Hello\File.txt
		cout << "New name:";
		cin >> this->newName;//C:\Hello\File_1.txt
		if (rename(this->oldName, this->newName) != 0) {
			cout << "Ошибка удаления файла!!!" << endl;
		}
		else {
			cout << "Папка переименована" << endl;
		}
	}

	void MoveFiles() {
		//char oldname[150], newname[150];
		cout << "Old Path:";
		cin >> this->oldName;//C:\Hello\File.txt
		cout << "New Path:";
		cin >> this->newName;//C:\Hello\File_1.txt
		if (rename(this->oldName, this->newName) != 0) {
			cout << "Ошибка перемещение файла!!!" << endl;
		}
		else {
			cout << "Файл перемещен" << endl;
		}
	}

	void FileSize() {
		cin >> this->path;
		this->der = _findfirst(this->path, &this->fileinfo);

		if (this->der != -1) {
			cout << "Size:";
			cout << this->fileinfo.size << " байт" << endl;
			/*if (_findnext(this->der, &this->fileinfo) == 0) {
				while (_findnext(this->der, &this->fileinfo) == 0) {
					cout << "Size:";
					cout << this->fileinfo.size << " байт" << endl;
					s += fileinfo.size;
					cout << "int:" << s << endl;
				}
			}
			else {
			}*/
			//Fill_zero_memset(path, 0);
			_findclose(der);
		}
		else {
			cout << "Error" << endl;
		}


	}

	void CopyFile() {
		//ifstream fPath;
		//ifstream pathtocpy;
		//char oldpath[250],pathtocopy[250];
		cin >> this->oldName;
		cin >> this->newName;
		ifstream fPath(this->oldName, ios::binary);
		ofstream pathtocpy(this->newName, ios::binary);

		if (fPath.is_open() && pathtocpy.is_open()) {
			// из старого записываем в новый 
			pathtocpy << fPath.rdbuf();//буфер для копирования 

			cout << "Файл скопирован:)" << endl;
		}
		else
		{
			cout << "Файл не скопирован !!! " << endl;
		}

	}

	~Files() {
		this->file.close();
		//cout << "Файл закрыт" << endl;
	}
};

class other : public Data_Note
{
public:
	void MackSearch() {
		//_finddata_t fileinfo;
		//intptr_t der;
		//char path[100];
		cin >> path;
		der = _findfirst(path, &fileinfo);

		if (der != -1) {
			cout << fileinfo.name << endl;
			while (_findnext(der, &fileinfo) == 0) {
				cout << fileinfo.name << endl;
			}
		}
		else {
			cout << "Error" << endl;
		}

	}

	//очищаем консоль чтобы пользователь не увидел заданый пароль
	void Clear()
	{
#if defined _WIN32
		system("cls");
		//clrscr(); // including header file : conio.h
#elif defined (LINUX) || defined(gnu_linux) || defined(linux)
		system("clear");
		//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences
#elif defined (APPLE)
		system("clear");
#endif
	}
	//получаем данные от пользователя 
	void GetLine(string usname, string PinCode) {
		cout << "Enter Login to log:";
		cin >> usname;
		cout << "Enter Pin:";
		cin >> PinCode;
	}
	//(Войти) получем данные от пользователя и сравниваем с заданным логин и паролем при регистрации
	void GetPinCode(string usname, string PinCode, string usNameCheck, string pinCheck, bool* login, bool* pin, bool* forget) {
		//Clear();
		cout << "Введите логин для входа:";
		cin >> usname;
		cout << "Введите пароль:";
		cin >> PinCode;

		if (usNameCheck == usname) {
			*login = true;
		}
		else if (usNameCheck != usname) {
			cout << "Неверный логин!!!" << endl;
		}
		if (pinCheck == PinCode) {
			*pin = true;
		}
		else if (pinCheck != PinCode) cout << "Неверный пароль!!!" << endl;
		if (usname == "8888") {
			*forget = true;
		}
	}
	bool Acsess() {
		if (login && pin) {
			return true;
		}
		else {
			return false;
		}
	}
	//(Зарегистрироватся) получаем данные от пользователя и сохраняем в тексовый документ(P.S в будушем можно шифровать и храннить данные в файле с расширени .bin или .dat для надежности)
	void SetPinCode(string usname, string PinCode, string Phrase) {
		ofstream f;
		f.open("UserData.txt");
		f.clear();
		cout << "Введите логин:";
		cin >> usname;
		cout << "Задайте пароль:";
		cin >> PinCode;
		cout << "(Внимание!!! для сброса данных при введение логина напишите 8888)\nВведите проверочную фразу или слово для сброса пароля:";
		cin >> Phrase;
		f << usname << endl;
		f << PinCode << endl;
		f << "LOGGED" << endl;
		f << Phrase << endl;
		f.close();
		//system("cls");1
	}

	bool AutoCheck() {
		nf.open("UserData.txt");
		getline(nf, usNameCheck);
		getline(nf, pinCheck);
		getline(nf, logCheck);
		getline(nf, CheckPhrase);
		nf.close();
		if (logCheck == "LOGGED") {
			return true;
		}
		else return false;

	}
	void Pin() {
		//nf.open("UserData.txt");
		/*getline(nf, usNameCheck);
		getline(nf, pinCheck);
		getline(nf, logCheck);
		getline(nf, CheckPhrase);*/
		nf.close();
		if (logCheck == "LOGGED") {
			GetPinCode(usname, PinCode, usNameCheck, pinCheck, &login, &pin, &forget);

		}
		else
		{
			SetPinCode(usname, PinCode, Phrase);
			Clear();
			cout << "Потдвердите данные!!!" << endl;
			GetPinCode(usname, PinCode, usNameCheck, pinCheck, &login, &pin, &forget);
		}
		if (forget == true) {
			cout << "Потдвердите сид фразу:" << endl;
			cin >> Phrase;
			if (Phrase == CheckPhrase) {
				cout << "Введите новый логин и праоль!!!" << endl;
				SetPinCode(usname, PinCode, Phrase);
			}
		}

	}

};


void MainMenuPrint(int numn) {
	if (numn == 1) {
		cout << "\t=========================================" << endl;
		cout << "\t=\t1 - Создать папку\t\t=\n\t=\t2 - Удалить папку\t\t=\n\t=\t3 - Переименовать папку\t\t=\n\t=\t4 - Создать файл\t\t=\n\t=\t5 - Удалить файл\t\t=\n\t=\t6 - Переименовать файл\t\t=\n\t=\t7 - Перемеситить Файл\t\t=\n\t=\t8 - Копировать файл\t\t=\n\t=\t9 - Поиск по маске\t\t=\n\t=\t10- Размер файла\t\t=\n\t=\t11- Размер папки\t\t=\n\t=\t12 - Задать пароль\t\t=\n\t=\t0 - Выход\t\t\t=\n";
		cout << "\t=========================================" << endl;

	}
	else if (numn == 0) {
		cout << "\t=========================================" << endl;
		cout << "\t=\t1 - Создать папку\t\t=\n\t=\t2 - Удалить папку\t\t=\n\t=\t3 - Переименовать папку\t\t=\n\t=\t4 - Создать файл\t\t=\n\t=\t5 - Удалить файл\t\t=\n\t=\t6 - Переименовать файл\t\t=\n\t=\t7 - Перемеситить Файл\t\t=\n\t=\t8 - Копировать файл\t\t=\n\t=\t9 - Поиск по маске\t\t=\n\t=\t10- Размер файла\t\t=\n\t=\t11- Размер папки\t\t=\n\t=\t0 - Выход\t\t\t=\n";
		cout << "\t=========================================" << endl;
	}

}

int main() {
	setlocale(LC_ALL, "rus");
	int ch, printCounter = 0;
	bool flag = true;
	Folders Folder;
	Files File;
	other Other;

	if (Other.AutoCheck()) {
		Other.Pin();
		if (Other.Acsess()) {
			MainMenuPrint(0);
			while (flag) {

				cout << ">>>";
				cin >> ch;
				printCounter += 1;

				if (ch == 1) Folder.CreateFolder();
				else if (ch == 2) Folder.DeleteFolder();
				else if (ch == 3) Folder.RenameFolder();
				else if (ch == 4) File.CreateFile();
				else if (ch == 5) File.DeleteFile();
				else if (ch == 6) File.RenameFile();
				else if (ch == 7) File.MoveFiles();
				else if (ch == 8) File.CopyFile();
				else if (ch == 9) Other.MackSearch();
				else if (ch == 10)File.FileSize();
				else if (ch == 11)Folder.FolderSize();
				else if (ch == 12)Other.Pin();
				else if (ch == 0) {
					flag = false;
					break;
				}

				if (printCounter == 5) {
					cout << endl << endl;
					MainMenuPrint(0);
				}
			}
		}


	}
	else if (!Other.AutoCheck()) {
		MainMenuPrint(1);
		while (flag) {

			cout << ">>>";
			cin >> ch;
			printCounter += 1;

			if (ch == 1) Folder.CreateFolder();
			else if (ch == 2) Folder.DeleteFolder();
			else if (ch == 3) Folder.RenameFolder();
			else if (ch == 4) File.CreateFile();
			else if (ch == 5) File.DeleteFile();
			else if (ch == 6) File.RenameFile();
			else if (ch == 7) File.MoveFiles();
			else if (ch == 8) File.CopyFile();
			else if (ch == 9) Other.MackSearch();
			else if (ch == 10)File.FileSize();
			else if (ch == 11)Folder.FolderSize();
			else if (ch == 12)Other.Pin();
			else if (ch == 0) {
				flag = false;
				break;
			}

			if (printCounter == 5) {
				cout << endl << endl;
				MainMenuPrint(1);
			}
		}
	}

}


















