begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Dag-Erling Coïdan Smørgrav  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  *	$Id$  */
end_comment

begin_comment
comment|/*  * Portions of this code were taken from ftpio.c:  *  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dknet.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * Major Changelog:  *  * Dag-Erling Coïdan Smørgrav  * 9 Jun 1998  *  * Incorporated into libfetch  *  * Jordan K. Hubbard  * 17 Jan 1996  *  * Turned inside out. Now returns xfers as new file ids, not as a special  * `state' of FTP_t  *  * $ftpioId: ftpio.c,v 1.30 1998/04/11 07:28:53 phk Exp $  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"fetch.h"
end_include

begin_include
include|#
directive|include
file|"ftperr.c"
end_include

begin_define
define|#
directive|define
name|FTP_ANONYMOUS_USER
value|"ftp"
end_define

begin_define
define|#
directive|define
name|FTP_ANONYMOUS_PASSWORD
value|"ftp"
end_define

begin_decl_stmt
specifier|static
name|url_t
name|cached_host
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|cached_socket
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|_ftp_errcode
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|int
name|_ftp_isconnected
parameter_list|(
name|url_t
modifier|*
name|url
parameter_list|)
block|{
return|return
operator|(
name|cached_socket
operator|&&
operator|(
name|strcmp
argument_list|(
name|url
operator|->
name|host
argument_list|,
name|cached_host
operator|.
name|host
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|strcmp
argument_list|(
name|url
operator|->
name|user
argument_list|,
name|cached_host
operator|.
name|user
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|strcmp
argument_list|(
name|url
operator|->
name|pwd
argument_list|,
name|cached_host
operator|.
name|pwd
argument_list|)
operator|==
literal|0
operator|)
operator|&&
operator|(
name|url
operator|->
name|port
operator|==
name|cached_host
operator|.
name|port
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Get server response, check that first digit is a '2'  */
end_comment

begin_function
specifier|static
name|int
name|_ftp_chkerr
parameter_list|(
name|FILE
modifier|*
name|s
parameter_list|,
name|char
modifier|*
name|e
parameter_list|)
block|{
name|char
modifier|*
name|line
decl_stmt|;
name|size_t
name|len
decl_stmt|;
do|do
block|{
if|if
condition|(
operator|(
operator|(
name|line
operator|=
name|fgetln
argument_list|(
name|s
argument_list|,
operator|&
name|len
argument_list|)
operator|)
operator|==
name|NULL
operator|)
operator|||
operator|(
name|len
operator|<
literal|4
operator|)
condition|)
return|return
operator|-
literal|1
return|;
block|}
do|while
condition|(
name|line
index|[
literal|3
index|]
operator|==
literal|'-'
condition|)
do|;
if|if
condition|(
operator|!
name|isdigit
argument_list|(
name|line
index|[
literal|0
index|]
argument_list|)
operator|||
operator|!
name|isdigit
argument_list|(
name|line
index|[
literal|1
index|]
argument_list|)
operator|||
operator|!
name|isdigit
argument_list|(
name|line
index|[
literal|2
index|]
argument_list|)
operator|||
operator|(
name|line
index|[
literal|3
index|]
operator|!=
literal|' '
operator|)
condition|)
return|return
operator|-
literal|1
return|;
name|_ftp_errcode
operator|=
operator|(
name|line
index|[
literal|0
index|]
operator|-
literal|'0'
operator|)
operator|*
literal|100
operator|+
operator|(
name|line
index|[
literal|1
index|]
operator|-
literal|'0'
operator|)
operator|*
literal|10
operator|+
operator|(
name|line
index|[
literal|2
index|]
operator|-
literal|'0'
operator|)
expr_stmt|;
if|if
condition|(
name|e
condition|)
operator|*
name|e
operator|=
name|_ftp_errcode
expr_stmt|;
return|return
operator|(
name|line
index|[
literal|0
index|]
operator|==
literal|'2'
operator|)
operator|-
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Map error code to string  */
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|_ftp_errstring
parameter_list|(
name|int
name|e
parameter_list|)
block|{
name|struct
name|ftperr
modifier|*
name|p
init|=
name|_ftp_errlist
decl_stmt|;
while|while
condition|(
operator|(
name|p
operator|->
name|num
operator|)
operator|&&
operator|(
name|p
operator|->
name|num
operator|!=
name|e
operator|)
condition|)
name|p
operator|++
expr_stmt|;
return|return
name|p
operator|->
name|string
return|;
block|}
end_function

begin_comment
comment|/*  * Change remote working directory  */
end_comment

begin_function
specifier|static
name|int
name|_ftp_cwd
parameter_list|(
name|FILE
modifier|*
name|s
parameter_list|,
name|char
modifier|*
name|dir
parameter_list|)
block|{
name|fprintf
argument_list|(
name|s
argument_list|,
literal|"CWD %s\n"
argument_list|,
name|dir
argument_list|)
expr_stmt|;
if|if
condition|(
name|ferror
argument_list|(
name|s
argument_list|)
condition|)
return|return
operator|-
literal|1
return|;
return|return
name|_ftp_chkerr
argument_list|(
name|s
argument_list|,
name|NULL
argument_list|)
return|;
comment|/* expecting 250 */
block|}
end_function

begin_comment
comment|/*  * Retrieve file  */
end_comment

begin_function
specifier|static
name|FILE
modifier|*
name|_ftp_retr
parameter_list|(
name|FILE
modifier|*
name|s
parameter_list|,
name|char
modifier|*
name|file
parameter_list|,
name|int
name|pasv
parameter_list|)
block|{
name|char
modifier|*
name|p
decl_stmt|;
comment|/* change directory */
if|if
condition|(
operator|(
operator|(
name|p
operator|=
name|strrchr
argument_list|(
name|file
argument_list|,
literal|'/'
argument_list|)
operator|)
operator|!=
name|NULL
operator|)
operator|&&
operator|(
name|p
operator|!=
name|file
operator|)
condition|)
block|{
operator|*
name|p
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|_ftp_cwd
argument_list|(
name|s
argument_list|,
name|file
argument_list|)
operator|<
literal|0
condition|)
block|{
operator|*
name|p
operator|=
literal|'/'
expr_stmt|;
return|return
name|NULL
return|;
block|}
operator|*
name|p
operator|++
operator|=
literal|'/'
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|_ftp_cwd
argument_list|(
name|s
argument_list|,
literal|"/"
argument_list|)
operator|<
literal|0
condition|)
return|return
name|NULL
return|;
block|}
comment|/* retrieve file; p now points to file name */
return|return
name|NULL
return|;
block|}
end_function

begin_comment
comment|/*  * XXX rewrite these  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_ifdef
unit|FILE * fetchGetFTP(url_t *url, char *flags) {     int retcode = 0;     static FILE *fp = NULL;     static char *prev_host = NULL;     FILE *fp2;
ifdef|#
directive|ifdef
name|DEFAULT_TO_ANONYMOUS
end_ifdef

begin_endif
unit|if (!url->user[0]) { 	strcpy(url->user, FTP_ANONYMOUS_USER); 	strcpy(url->pwd, FTP_ANONYMOUS_PASSWORD);     }
endif|#
directive|endif
end_endif

begin_comment
unit|if (fp&& prev_host) { 	if (!strcmp(prev_host, url->host)) {
comment|/* Try to use cached connection */
end_comment

begin_comment
unit|fp2 = ftpGet(fp, url->doc, NULL); 	    if (!fp2) {
comment|/* Connection timed out or was no longer valid */
end_comment

begin_comment
unit|fclose(fp); 		free(prev_host); 		prev_host = NULL; 	    } 	    else 		return fp2; 	} 	else {
comment|/* It's a different host now, flush old */
end_comment

begin_comment
unit|fclose(fp); 	    free(prev_host); 	    prev_host = NULL; 	}     }     fp = ftpLogin(url->host, url->user, url->pwd, url->port, 0,&retcode);     if (fp) { 	if (strchr(flags, 'p')) { 	    if (ftpPassive(fp, 1) != SUCCESS)
comment|/* XXX what should we do? */
end_comment

begin_comment
unit|; 	} 	fp2 = ftpGet(fp, url->doc, NULL); 	if (!fp2) {
comment|/* Connection timed out or was no longer valid */
end_comment

begin_comment
unit|retcode = ftpErrno(fp); 	    fclose(fp); 	    fp = NULL; 	} 	else 	    prev_host = strdup(url->host); 	return fp2;     }     return NULL; }  FILE * fetchPutFTP(url_t *url, char *flags) {     static FILE *fp = NULL;     FILE *fp2;     int retcode = 0;      if (fp) {
comment|/* Close previous managed connection */
end_comment

begin_comment
unit|fclose(fp); 	fp = NULL;     }     fp = ftpLogin(url->host, url->user, url->pwd, url->port, 0,&retcode);     if (fp) { 	if (strchr(flags, 'p')) { 	    if (ftpPassive(fp, 1) != SUCCESS)
comment|/* XXX what should we do? */
end_comment

begin_endif
unit|; 	} 	fp2 = ftpPut(fp, url->doc); 	if (!fp2) { 	    retcode = ftpErrno(fp); 	    fclose(fp); 	    fp = NULL; 	} 	return fp2;     }     return NULL; }
endif|#
directive|endif
end_endif

end_unit

