/**
 * Programmer:	Jeffrey Minton
 * File:		jeffutil.c
 * Description:	A file containing various utilities i use for my 
 * 				programs
 */
 
#include "jeffutil.h"

/**
 * Function:    match
 */
int match(const char *string, char *pattern)
{
    int    status;
    regex_t    re;


    if (regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB) != 0) {
        return(0);      /* Report error. */
    }
    status = regexec(&re, string, (size_t) 0, NULL, 0);
    regfree(&re);
    
    if (status != 0) {
        return(0);      /* Report error. */
    }

    return(1);
}


/**
 * Function:    strip
 */
void strip(char* line)
{
	int lineLen;
	int pos; //current position in string
	int whiteSpace;
	
	if(line != NULL)
	{
		//get number of leading empty spaces
		whiteSpace = strspn(line, " ");
		//increment pointer past whitespace
		line = line + whiteSpace;
		
		//get length of line
		lineLen = strlen(line);
		//get last char in string
		pos = lineLen - 1;
		//while still whitespace
		while(line[pos] == ' ' || line[pos] == '\n' || line[pos] == '\r')
		{
			pos--;
		}

		//put null char at end of non whitespace
		line[pos + 1] = '\0';
	}
}


/**
 * Function:	readn
 */
int readn (int fd, char *ptr, int nbytes)
{
	int	nleft,  nread;
	
	nleft = nbytes;
	while (nleft > 0)	{
		nread = read(fd, ptr, nleft);
		if (nread < 0)
			return (nread);	/* error, return < 0 */
		else if (nread == 0)
			break;		/* EOF */

		nleft  -=  nread;
		ptr     += nread;
	}
	return (nbytes - nleft);		/* return >= 0 */
}  // end function readn


/**
 * Function:	writen
 */
int writen (int fd, void *ptr, int nbytes)
{
	int	nleft,  nwritten;

	nleft = nbytes;
	while (nleft > 0)   {
		nwritten = write (fd, ptr, nleft);
		if (nwritten <= 0)
			return (nwritten);		/* error */

		nleft -= nwritten;
		ptr    += nwritten;
	}
	return (nbytes - nleft);
}   // end function writen

/**
 * Function:	readline
 */
int readline (int fd, char *ptr, int maxlen)
{
	int	n,  rc;
	char	c;

	for (n = 1; n < maxlen; n++)
	{
		if( (rc = read (fd, &c, 1)) == 1)
		{
			*ptr++ = c;
			if (c == '\n')
				break;
		}
		else if (rc == 0)
		{
			if (n == 1)
				return (0);	/* EOF, no data read */
			else 
				break;		/* EOF, some data was read */
		}
		else
			return (-1);		/* error */
	}
	*ptr = 0;
	return (n);
}  // end function readline



/**
 * Function:	str_echo
 */
void str_echo(int sockfd)
{
	int	n, n2;
	char	line[MAXLINE];
	char	*temp = (char *)malloc(sizeof(char)*MAXLINE);

	for ( ; ; )  {
		n = readline (sockfd, line, MAXLINE);
		if (n == 0)
			return;       /* connection terminated */
		else if (n < 0)
			perror ("str_echo: readline error");

		//		fputs("In str_echo:\n", stdout);
		fputs(line, stdout);

		strcpy(temp, "Server performed action!\n");
		n2 = strlen(temp);
		if (writen ( sockfd, temp, n2) != n2)
			perror ("str_echo: writen error");
	}   // end for
}   // end function str_echo

