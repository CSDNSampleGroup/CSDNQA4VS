void main()
{
	char hexTable[] = "0123456789ABCDEF";
	int i = 60;
	char result[3];
	result[0] = hexTable[i / 16];
	result[1] = hexTable[i % 16];
	result[2] = 0;
}
