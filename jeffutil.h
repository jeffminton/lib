/**
 * Programmer:	Jeffrey Minton
 * File:		jeffutil.h
 * Description:	A file containing various utilities i use for my 
 * 				programs
 */
 
#include <stdio.h>
#include <regex.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>

#define EMPTYLINE "^\s*$"
#define MAXLINE 512

/**
 * Function:    match
 * Description: determines whether or not a string matches
 * 				the pattern
 * Prameters:	const char *string - string to check for pattern
 * 				char *patter - pattern to search for
 * Return		int - 1 if string contains pattern
 * Source:      http://www.opengroup.org/onlinepubs/000095399/functions/regcomp.html
 */
int match(const char *string, char *pattern);

/**
 * Function:    strip
 * Description: strips leading and trailing whitespace
 * Parameters:	char *line - line of text to strip
 */
void strip(char* line);

/**
 * Function:	readn
 * Description:	Read "n" bytes from a descriptor. Use in place of 
 * 				read() when fd is a stream socket.
 * Parameters:	int fd - file desc to read from
 * 				char *ptr - pointer to char buf to place data read from
 * 					fd, should be at least big enough to hold nbytes
 * 				int nbytes - number of bytes to read
 * Return:		int - number of bytes read
 * Source:		Prof. Frye - utils.c
 */
int readn (int fd, char *ptr, int nbytes);

/**
 * Function:	writen
 * Description:	Write "n" bytes to a descriptor. Use in place of write()
 * 				when fd is a stream socket.
 * Parameters:	int fd - file desc to write to
 * 				void *ptr - pointer to void buf containing data to write
 * 					to fd
 * 				int nbytes - number of bytes to write
 * Return:		int - number of bytes writen
 * Source:		Prof. Frye - utils.c
 */
int writen (int fd, void *ptr, int nbytes);

/**
 * Function:	readline
 * Description:	Read a line from a descriptor.  Read the line one byte
 * 				at a time, looking for the newline.  We store the 
 * 				newline in the buffer, then follow it with a null 
 * 				(the same as fgets (3)). We return the number of 
 * 				characters up to, but not including, the null 
 * 				(the same as strlen (3)).
 * Parameters:	int fd - file desc to read from
 * 				char *ptr - char buf to read data from fd into, should
 * 				be able to hold at least maxlen bytes
 * 				int maxlen - max number of bytes to read, 
 * Return:		int - number of bytes read
 * Source:		Prof. Frye, utils.c
 */
int readline (int fd, char *ptr, int maxlen);

/**
 * Function:	str_echo
 * Description:	Read a stream socket one line at a time, and write each
 * 				line back to the sender. Return when the connection 
 * 				is terminated.
 * Parameters:	int sockfd - file desc to read from
 * Source:		Prof. Frye, utils.c
 */
void str_echo(int sockfd);



