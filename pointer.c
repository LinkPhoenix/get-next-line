char *str1 = "BONJOUR"

pointe sur ladd de B donc BONJOUR\0

char **str2 = NULL;
**str2 = *str1 donc = "BONJOUR";


str2 = &str1

str2 etant un Pointeur sur Pointeur il doit recupere ladresse dun autre pointeur

*str2 je vais acceder au CONTENU sur lequel str2 POINTE


