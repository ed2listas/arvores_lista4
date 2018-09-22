void tiraTerminador(char *texto) {
	if(texto[strlen(texto)-1] == '\n')
		texto[strlen(texto)-1] = '\0';
}
