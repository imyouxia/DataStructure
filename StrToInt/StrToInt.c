/*《剑指offer》里，把字符串变为int类型的一个类似atoi()函数

*/

enum Status {kValid = 0 ,kInvalid};
int g_nStatus = kValid;

int StrToInt(const char* str)
{
	g_nStatus = kInvalid;
	long long num = 0;
	if(str != NULL && *str != '\0')
	{
		bool minus = false;
		if(*str == '+')
			str++;
		else if(*str == '-')
		{
			str++;
			minus = true;
		}
		if(*str != '\0')
		{
			num = StrToIntCore(str,minus);
		}
	}
	return (int)num;
}


long long StrToIntCore(const char* digit,bool minus)
{
	long long num = 0;
	
	while(*digit != '\0')
	{
		if(*digit >='0' && *digit <= '9')
		{
			int flag = minus ? -1 : 1;
			num = num * 10 + flag * (*digit - '0');
			if((!minus && num > 0x7FFFFFFF) || (minus && num < (signed int)0x80000000))
			{
				num = 0;
				break;
			}
			digit++;
		}
		else
		{
			num = 0;
			break;
		}
	}

	if(*digit == '\0')
	{
		g_nStatus = kValid;
	}

	return num;
}





