int main(int argc, char *argv[])
{
	if (argc != 3) {
		printf("error\n");
		return -1;
	}

	print_number_compar(atoi(argv[1]), atoi(argv[2]));

	return 0;
}
