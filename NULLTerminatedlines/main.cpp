#include<iostream>
#include<Windows.h>
#include<fstream>
#include<string.h>
using namespace std;

int StringLengt(const char str[]);
void to_upper(char str[]);
void to_lower(char str[]);
void shrink(char str[]);
bool is_palindrome(char str[]);
bool is_int_number(char str[]);
bool is_bin_number(char str[]);
bool is_hex_number(char str[]);
int string_to_int(char str[]);
int bin_to_int(char str[]);
int hex_to_int(char str[]);
bool is_mac_address(char str[]);
bool is_ip_address(char str[]);

void main()
{
	setlocale(LC_ALL, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//char str[] = { 'H','e','l','l','o',0 };
	//char str[] = "Hello";
	//cout << str << endl;
	const int SIZE = 256;
	char str[SIZE] = {};
	cout << "������� ������: ";
	SetConsoleCP(1251);
	//cin >> str; ������� ������ �� ��� ���� ���������� �� �������
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << "��������� ������ ����� �����: " << StringLengt(str) << endl;
	//to_upper(str);
	//cout<<str<<endl;
	//to_lower(str);
	//cout<<str<<endl;
	//shrink(str);
	//cout<<str<<endl;
	//cin >> str[n];
	/*cout<<is_palindrome(str);
	cout<<endl;
	cout<<str<<endl;*/
	//cout << is_int_number(str);
	//cout << is_bin_number(str);
	//cout << is_hex_number(str);
	//cout << string_to_int(str);
	//cout << bin_to_int(str);
	//cout << hex_to_int(str);
	/*if(is_palindrome)
	{
		cout<<"true";
	}*/
	cout << is_ip_address(str);
}
int StringLengt(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;

}
void to_upper(char str[])
{
	int n = StringLengt(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')str[i] += 32;
		if (str[i] >= '�' && str[i] <= '�')str[i] += 32;
	}
}
void to_lower(char str[])
{
	int n = StringLengt(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')str[i] += 32;
		if (str[i] >= '�' && str[i] <= '�')str[i] += 32;
	}
}
void shrink(char str[], char symbol, int mode)
{
	int n = StringLengt(str);
	for (int i = 0; i < n; i++)
	{
		if (mode == 0)
		{
			if (str[i] == symbol)
			{
				int cut = i;
				i--;
				for (; cut < n; ++cut)
					str[cut] = str[cut + 1];
				n--;
			}
		}
		if (mode == 1)
		{
			if (str[i] == symbol && str[i + 1] == symbol)
			{
				int cut = i + 1;
				i--;
				for (; cut < n; ++cut)
					str[cut] = str[cut + 1];
				n--;
			}
		}
	}
}
bool is_palindrome(char str[])
{
	bool palindrome = 1;
	int n = StringLengt(str);
	for (int i = 0; i < n; i++, n--)
	{
		while (str[i] == ' ')i++;
		while (str[n - 1] == ' ')n--;
		if (str[i] != str[n - 1] && str[i] != (str[n - 1] - 32) && str[i] != (str[n - 1] + 32))
		{
			palindrome = 0;
			break;
		}
	}
	return palindrome;
}
bool is_int_number(char str[])
{
	bool int_number = 1;
	int n = StringLengt(str);
	for (int i = 0; i < n; i++)
	{
		if (str[0] == '0')
		{
			int_number = 0;
			break;
		}
	}
	return int_number;

}
bool is_bin_number(char str[])
{
	bool bin_number = 1;
	int n = StringLengt(str);
	for (int i = 0; i < n; i++)
	{
		if (str[i] != '1'&& str[i] != '0')
		{
			bin_number = 0;
			break;
		}
	}
	return bin_number;
}
bool is_hex_number(char str[])
{
	bool hex_number = 1;
	int n = StringLengt(str);
	for (int i = 0; i < n; i++)
	{
		if ((str[i] > '9' || str[i] < '0') && (str[i]<'A' || str[i]>'F') && (str[i]<'a' || str[i]>'f'))
		{
			hex_number = 0;
			break;
		}
	}
	return hex_number;
}
int string_to_int(char str[])
{
	int n = StringLengt(str);
	int chislo = 0;
	if (!is_int_number(str))
	{
		cout << "������ ������ �� �������� ����� ���������� ������" << endl;
		return 0;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			chislo = chislo * 10 + (str[i] - '0');
		}
		return chislo;
	}
	/*srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n;
		for (int j = 0; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				i--;
				break;
			}
		}
	}*/
	for (int i = 0; i < n; i++)
	{
		for (int i = 0; i < n; i++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	bool is_palindrome(char str[])
	{
		bool palindrome = 1;
		int n = StringLength(str);
		for (int i = 0; i < n; i++, n--)
		{
			while (str[i] == ' ')i++;
			while (str[n - 1] == ' ')n--;
			if (str[i] != str[n - 1] && str[i] != (str[n - 1] - 32) && str[i] != (str[n - 1] + 32))
			{
				palindrome = 0;
				break;
			}
		}
		return palindrome;
	}

	bool is_int_number(char str[])
	{
		bool int_number = 1;
		int n = StringLength(str);
		for (int i = 0; i < n; i++)
		{
			if (str[0] == '0')
			{
				int_number = 0;
				break;
			}
			if (str[i] > '9' || str[i] < '0')
			{
				int_number = 0;
				break;
			}
		}
		return int_number;
	}

	bool is_bin_number(char str[])
	{
		bool bin_number = 1;
		int n = StringLength(str);
		for (int i = 0; i < n; i++)
		{
			if (str[i] != '1' && str[i] != '0')
			{
				bin_number = 0;
				break;
			}
		}
		return bin_number;
	}

	bool is_hex_number(char str[])
	{
		bool hex_number = 1;
		int n = StringLength(str);
		for (int i = 0; i < n; i++)
		{
			if ((str[i] > '9' || str[i] < '0') && (str[i] < 'A' || str[i] > 'F') && (str[i] < 'a' || str[i] > 'f'))
			{
				hex_number = 0;
				break;
			}
		}
		return hex_number;
	}

	int string_to_int(char str[])
	{
		int n = StringLength(str);
		int chislo = 0;
		if (!is_int_number(str))
		{
			cout << "������ ������ �� �������� ����� ���������� ������" << endl;
			return 0;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				chislo = chislo * 10 + (str[i] - '0');
			}
			return chislo;
		}
	}

	int bin_to_int(char str[])
	{
		int n = StringLength(str);
		int chislo = 0;
		if (!is_bin_number(str))
		{
			cout << "������ ������ �� �������� �������� ������" << endl;
			return 0;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				chislo += (str[i] - 48) * pow(2.0, double(n - i - 1));
			}
			return chislo;
		}
	}

	int hex_to_int(char str[])
	{
		int n = StringLength(str);
		int chislo = 0;
		if (!is_hex_number(str))
		{
			cout << "������ ������ �� �������� ����������������� ������" << endl;
			return 0;
		}
		else
		{
			for (int i = 0; i < n; i++)
			{
				if (str[i] >= 48 && str[i] <= 57)
				{
					chislo += (str[i] - '0') * pow(16, n - i - 1);
				}
				else if (str[i] >= 65 && str[i] <= 70) {
					chislo += (str[i] - 55) * pow(16, n - i - 1);
				}
				else if (str[i] >= 97 && str[i] <= 102) {
					chislo += (str[i] - 87) * pow(16, n - i - 1);
				}
			}
			return chislo;
		}
	}

	bool is_mac_address(char str[])
	{
		int n = StringLength(str);
		int length = 0;
		bool this_is_the_mac_address = 1;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == ':' || str[i] == '-' || str[i] == '.')
			{
				length = 0;
			}
			else if (str[i] > '9' && str[i] < '0' || str[i] < 'A' && str[i]>'F' || str[i] < 'a' && str[i]>'f')
			{
				this_is_the_mac_address = 0;
				break;
			}

			if (length > 2)
			{
				this_is_the_mac_address = 0;
				break;
			}

			length++;
		}
		return this_is_the_mac_address;
	}

	bool is_ip_address(char str[])
	{
		int n = StringLength(str);
		int length = 0;
		int fragments = 0;
		bool this_is_the_ip_address = 1;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == '.')
			{
				length = 0;
				fragments++;
				i++;
			}
			if (str[i] > '9' && str[i] < '0')
			{
				this_is_the_ip_address = 0;
				break;
			}
			if (length > 3)
			{
				this_is_the_ip_address = 0;
				break;
			}
			if (length == 0 && str[i] > '2')
			{
				cout << length;
				this_is_the_ip_address = 0;
				break;
			}
			if (length == 1 || length == 2)
			{
				if (length == 1 && str[i - 1] == '2' && str[i] > '5')
				{
					return false;
				}
				if (length == 2 && str[i - 2] == '2' && str[i] > '5')
				{
					return false;
				}
			}
			length++;
		}
		if (fragments != 3)
		{
			return false;
		}
		return this_is_the_ip_address;
	}
}
