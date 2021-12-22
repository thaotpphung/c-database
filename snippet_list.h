#define MAX_LINE_LENGTH 115
#define MAX_NAME_LENGTH 32
#define MAX_ADDRESS_LENGTH 64
#define MAX_CITY_LENGTH 16
#define STATE_LENGTH 3

void read_file(char *snippet_file);
void print_list(void);
void add_snippet(char a_name[], char an_addr[], char a_city[], char a_state[],
		  		 unsigned int a_zip);
void remove_snippet(char substring[]);
void terminate(char *snippet_file);

