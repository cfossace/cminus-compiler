/* A useful function that concatenates two strings and returns the result */
char * concat( char * str1, char * str2) {
  
  char *str3;
  str3 = (char *)calloc(strlen(str1) + strlen(str2) + 1, 
                        sizeof(char));
  strcpy(str3, str1);
  strcat(str3, str2);
  
  return str3;
}


int main() {
  printf("%s\n", concat("Hello ", "world"));
}
