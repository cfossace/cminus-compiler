/* A C function to generate new label names */

char * genLabel(void) {
  static int num = 0;
  char * lab = (char *)malloc(20*sizeof(char));
  num++;
  sprintf(lab, "Label%d", num);
  return lab;
}
