begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1980, 1991, 1993\n\ 	The Regents of the University of California.  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)uusend.c	8.1 (Berkeley) 6/6/93"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * uusend: primitive operation to allow uucp like copy of binary files  * but handle indirection over systems.  *  * usage: uusend [-r] [-m ooo] localfile sysname1!sysname2!...!destfile  *        uusend [-r] [-m ooo]     -     sysname1!sysname2!...!destfile  *  * Author: Mark Horton, May 1980.  *  * "-r" switch added.  Has same effect as "-r" in uux. 11/82  CCW  *  * Error recovery (a la uucp) added& ifdefs for ruusend (as in rmail).  * Checks for illegal access to /usr/lib/uucp.  *				February 1983  Christopher Woodbury  * Fixed mode set[ug]id loophole. 4/8/83  CCW  *  * Add '-f' to make uusend syntax more similar to UUCP.  "destname"  * can now be a directory.	June 1983  CCW  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<pwd.h>
end_include

begin_comment
comment|/*  * define RECOVER to permit requests like 'uusend file sys1!sys2!~uucp'  * (abbreviation for 'uusend file sys1!sys2!~uucp/file').  * define DEBUG to keep log of uusend uusage.  * define RUUSEND if neighboring sites permit 'ruusend',  * which they certainly should to avoid security holes  */
end_comment

begin_define
define|#
directive|define
name|RECOVER
end_define

begin_comment
comment|/*#define	DEBUG	"/usr/spool/uucp/uusend.log"/**/
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|in
decl_stmt|,
modifier|*
name|out
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|dout
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|popen
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|index
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|,
modifier|*
name|ctime
argument_list|()
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RUUSEND
end_ifdef

begin_decl_stmt
name|int
name|rsend
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RUUSEND
end_endif

begin_decl_stmt
name|int
name|mode
init|=
operator|-
literal|1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mode to chmod new file to */
end_comment

begin_decl_stmt
name|char
modifier|*
name|nextsys
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* next system in the chain */
end_comment

begin_decl_stmt
name|char
name|dnbuf
index|[
literal|200
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for result of ~user/file */
end_comment

begin_decl_stmt
name|char
name|cmdbuf
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer to build uux command in */
end_comment

begin_decl_stmt
name|char
modifier|*
name|rflg
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default value of rflg  ccw -- 1 Nov '82 */
end_comment

begin_decl_stmt
name|struct
name|passwd
modifier|*
name|user
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* entry  in /etc/passwd for ~user */
end_comment

begin_function_decl
name|struct
name|passwd
modifier|*
name|getpwnam
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|stat
name|stbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|excl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of first ! in destname */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sl
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* location of first / in destname */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sourcename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argv[1] */
end_comment

begin_decl_stmt
name|char
modifier|*
name|destname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* argv[2] */
end_comment

begin_decl_stmt
name|char
modifier|*
name|UULIB
init|=
literal|"/usr/lib/uucp"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* UUCP lib directory */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RECOVER
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|UUPUB
init|=
literal|"/usr/spool/uucppublic/"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* public UUCP directory */
end_comment

begin_decl_stmt
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file name from end of destname */
end_comment

begin_function_decl
name|char
modifier|*
name|getfname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* routine to get filename from destname */
end_comment

begin_decl_stmt
name|int
name|fflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|f
index|[
literal|100
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of default output file */
end_comment

begin_else
else|#
directive|else
else|!RECOVER
end_else

begin_decl_stmt
name|char
modifier|*
name|f
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* so we waste a little space */
end_comment

begin_endif
endif|#
directive|endif
endif|!RECOVER
end_endif

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
specifier|register
name|int
name|c
decl_stmt|;
name|long
name|count
decl_stmt|;
specifier|extern
name|char
modifier|*
modifier|*
name|environ
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|long
name|t
decl_stmt|;
name|umask
argument_list|(
literal|022
argument_list|)
expr_stmt|;
name|dout
operator|=
name|fopen
argument_list|(
name|DEBUG
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
if|if
condition|(
name|dout
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"Cannot append to %s\n"
argument_list|,
name|DEBUG
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|freopen
argument_list|(
name|DEBUG
argument_list|,
literal|"a"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|dout
argument_list|,
literal|"\nuusend run: "
argument_list|)
expr_stmt|;
for|for
control|(
name|c
operator|=
literal|0
init|;
name|c
operator|<
name|argc
condition|;
name|c
operator|++
control|)
name|fprintf
argument_list|(
name|dout
argument_list|,
literal|"%s "
argument_list|,
name|argv
index|[
name|c
index|]
argument_list|)
expr_stmt|;
name|time
argument_list|(
operator|&
name|t
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|dout
argument_list|,
literal|"%s"
argument_list|,
name|ctime
argument_list|(
operator|&
name|t
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
ifdef|#
directive|ifdef
name|RUUSEND
if|if
condition|(
name|argv
index|[
literal|0
index|]
index|[
literal|0
index|]
operator|==
literal|'r'
condition|)
name|rsend
operator|++
expr_stmt|;
endif|#
directive|endif
endif|RUUSEND
while|while
condition|(
name|argc
operator|>
literal|1
operator|&&
name|argv
index|[
literal|1
index|]
index|[
literal|0
index|]
operator|==
literal|'-'
operator|&&
name|argv
index|[
literal|1
index|]
index|[
literal|1
index|]
condition|)
block|{
switch|switch
condition|(
name|argv
index|[
literal|1
index|]
index|[
literal|1
index|]
condition|)
block|{
case|case
literal|'m'
case|:
name|sscanf
argument_list|(
name|argv
index|[
literal|2
index|]
argument_list|,
literal|"%o"
argument_list|,
operator|&
name|mode
argument_list|)
expr_stmt|;
name|mode
operator|&=
literal|0777
expr_stmt|;
comment|/* fix set[ug]id loophole */
name|argc
operator|--
expr_stmt|;
name|argv
operator|++
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
comment|/* -r flag for uux */
name|rflg
operator|=
literal|"-r "
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|RECOVER
case|case
literal|'f'
case|:
name|fflg
operator|++
expr_stmt|;
name|strcpy
argument_list|(
name|f
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
endif|#
directive|endif
endif|RECOVER
default|default:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Bad flag: %s\n"
argument_list|,
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
break|break;
block|}
name|argc
operator|--
expr_stmt|;
name|argv
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|argc
operator|!=
literal|3
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Usage: uusend [-m ooo] [-r] -/file sys!sys!..!rfile\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|sourcename
operator|=
name|argv
index|[
literal|1
index|]
expr_stmt|;
name|destname
operator|=
name|argv
index|[
literal|2
index|]
expr_stmt|;
if|if
condition|(
name|sourcename
index|[
literal|0
index|]
operator|==
literal|'-'
condition|)
name|in
operator|=
name|stdin
expr_stmt|;
else|else
block|{
ifdef|#
directive|ifdef
name|RUUSEND
if|if
condition|(
name|rsend
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"illegal input\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|RUUSEND
name|in
operator|=
name|fopen
argument_list|(
name|sourcename
argument_list|,
literal|"r"
argument_list|)
expr_stmt|;
if|if
condition|(
name|in
operator|==
name|NULL
condition|)
block|{
name|perror
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|!
name|fflg
operator|||
name|f
index|[
literal|2
index|]
operator|==
literal|'\0'
condition|)
block|{
name|strcpy
argument_list|(
name|f
argument_list|,
literal|"-f"
argument_list|)
expr_stmt|;
name|strcat
argument_list|(
name|f
argument_list|,
name|getfname
argument_list|(
name|sourcename
argument_list|)
argument_list|)
expr_stmt|;
name|fflg
operator|++
expr_stmt|;
block|}
block|}
name|excl
operator|=
name|index
argument_list|(
name|destname
argument_list|,
literal|'!'
argument_list|)
expr_stmt|;
if|if
condition|(
name|excl
condition|)
block|{
comment|/* 		 * destname is on a remote system. 		 */
name|nextsys
operator|=
name|destname
expr_stmt|;
operator|*
name|excl
operator|++
operator|=
literal|0
expr_stmt|;
name|destname
operator|=
name|excl
expr_stmt|;
if|if
condition|(
name|mode
operator|<
literal|0
condition|)
block|{
name|fstat
argument_list|(
name|fileno
argument_list|(
name|in
argument_list|)
argument_list|,
operator|&
name|stbuf
argument_list|)
expr_stmt|;
name|mode
operator|=
name|stbuf
operator|.
name|st_mode
operator|&
literal|0777
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|RUUSEND
name|sprintf
argument_list|(
argument|cmdbuf
argument_list|,
literal|"uux -gn -z %s- \"%s!ruusend %s -m %o - (%s)\""
argument_list|,
else|#
directive|else
else|!RUUSEND
argument|sprintf(cmdbuf,
literal|"uux -gn -z %s- \"%s!uusend %s -m %o - (%s)\""
argument|,
endif|#
directive|endif
endif|!RUUSEND
argument|rflg, nextsys, f, mode, destname);
ifdef|#
directive|ifdef
name|DEBUG
argument|fprintf(dout,
literal|"remote: nextsys='%s', destname='%s', cmd='%s'\n"
argument|, nextsys, destname, cmdbuf);
endif|#
directive|endif
endif|DEBUG
argument|out = popen(cmdbuf,
literal|"w"
argument|); 	} else {
comment|/* 		 * destname is local. 		 */
argument|if (destname[
literal|0
argument|] ==
literal|'~'
argument|) {
ifdef|#
directive|ifdef
name|DEBUG
argument|fprintf(dout,
literal|"before ~: '%s'\n"
argument|, destname); fflush(dout);
endif|#
directive|endif
endif|DEBUG
argument|sl = index(destname,
literal|'/'
argument|);
ifdef|#
directive|ifdef
name|RECOVER
argument|if (sl == NULL&& !fflg) { 				fprintf(stderr,
literal|"Illegal ~user\n"
argument|); 				exit(
literal|3
argument|); 			} 			for (sl = destname; *sl !=
literal|'\0'
argument|; sl++) 				;
comment|/* boy, is this a hack! */
else|#
directive|else
else|!RECOVER
argument|if (sl == NULL) { 				fprintf(stderr,
literal|"Illegal ~user\n"
argument|); 				exit(
literal|3
argument|); 			} 			*sl++ =
literal|0
argument|;
endif|#
directive|endif
endif|!RECOVER
argument|user = getpwnam(destname+
literal|1
argument|); 			if (user == NULL) { 				fprintf(stderr,
literal|"No such user as %s\n"
argument|, 					destname);
ifdef|#
directive|ifdef
name|RECOVER
argument|if ((filename =getfname(sl)) == NULL&& 				     !fflg) 					exit(
literal|4
argument|); 				strcpy(dnbuf, UUPUB); 				if (fflg) 					strcat(dnbuf,&f[
literal|2
argument|]); 				else 					strcat(dnbuf, filename); 			} 			else { 				strcpy(dnbuf, user->pw_dir); 				strcat(dnbuf,
literal|"/"
argument|); 				strcat(dnbuf, sl); 			}
else|#
directive|else
else|!RECOVER
argument|exit(
literal|4
argument|); 			} 			strcpy(dnbuf, user->pw_dir); 			strcat(dnbuf,
literal|"/"
argument|); 			strcat(dnbuf, sl);
endif|#
directive|endif
endif|!RECOVER
argument|destname = dnbuf; 		}
ifdef|#
directive|ifdef
name|RECOVER
argument|else 			destname = strcpy(dnbuf, destname);
endif|#
directive|endif
endif|!RECOVER
argument|if(strncmp(UULIB, destname, strlen(UULIB)) ==
literal|0
argument|) { 			fprintf(stderr,
literal|"illegal file: %s"
argument|, destname); 			exit(
literal|4
argument|); 		}
ifdef|#
directive|ifdef
name|RECOVER
argument|if (stat(destname,&stbuf) ==
literal|0
argument|&& 		    (stbuf.st_mode& S_IFMT) == S_IFDIR&& 		     fflg) { 			strcat(destname,
literal|"/"
argument|); 			strcat(destname,&f[
literal|2
argument|]); 		}
endif|#
directive|endif
endif|RECOVER
argument|out = fopen(destname,
literal|"w"
argument|);
ifdef|#
directive|ifdef
name|DEBUG
argument|fprintf(dout,
literal|"local, file='%s'\n"
argument|, destname);
endif|#
directive|endif
endif|DEBUG
argument|if (out == NULL) { 			perror(destname);
ifdef|#
directive|ifdef
name|RECOVER
argument|if (strncmp(destname,UUPUB,strlen(UUPUB)) ==
literal|0
argument|) 				exit(
literal|5
argument|);
comment|/* forget it! */
argument|filename = getfname(destname); 			if (destname == dnbuf)
comment|/* cmdbuf is scratch */
argument|filename = strcpy(cmdbuf, filename); 			destname = strcpy(dnbuf, UUPUB); 			if (user != NULL) { 				strcat(destname, user->pw_name); 				if (stat(destname,&stbuf) == -
literal|1
argument|) { 					mkdir(destname,
literal|0777
argument|); 				} 				strcat(destname,
literal|"/"
argument|); 			} 			if (fflg) 				strcat(destname,&f[
literal|2
argument|]); 			else 				strcat(destname, filename); 			if ((out = fopen(destname,
literal|"w"
argument|)) == NULL) 				exit(
literal|5
argument|);
comment|/* all for naught! */
else|#
directive|else
else|!RECOVER
argument|exit(
literal|5
argument|);
endif|#
directive|endif
endif|!RECOVER
argument|} 		if (mode>
literal|0
argument|) 			chmod(destname, mode);
comment|/* don't bother to check it */
argument|}
comment|/* 	 * Now, in any case, copy from in to out. 	 */
argument|count =
literal|0
argument|; 	while ((c=getc(in)) != EOF) { 		putc(c, out); 		count++; 	}
ifdef|#
directive|ifdef
name|DEBUG
argument|fprintf(dout,
literal|"count %ld bytes\n"
argument|, count); 	fclose(dout);
endif|#
directive|endif
endif|DEBUG
argument|fclose(in); 	fclose(out);
comment|/* really should pclose in that case */
argument|exit(
literal|0
argument|); }
comment|/*  * Return the ptr in sp at which the character c appears;  * NULL if not found.  Included so I don't have to fight the  * index/strchr battle.  */
define|#
directive|define
name|NULL
value|0
argument|char * index(sp, c) register char *sp
argument_list|,
argument|c; { 	do { 		if (*sp == c) 			return(sp); 	} while (*sp++); 	return(NULL); }
ifdef|#
directive|ifdef
name|RECOVER
argument|char * getfname(p) register char *p; { 	register char *s; 	s = p; 	while (*p !=
literal|'\0'
argument|) 		p++; 	if (p == s) 		return (NULL); 	for (;p != s; p--) 		if (*p ==
literal|'/'
argument|) { 			p++; 			break; 		} 	return (p); }
ifndef|#
directive|ifndef
name|BSD4_2
argument|makedir(dirname, mode) char *dirname; int mode; { 	register int pid; 	int retcode
argument_list|,
argument|status; 	switch ((pid = fork())) { 	    case -
literal|1
argument|:
comment|/* error */
argument|return (-
literal|1
argument|); 	    case
literal|0
argument|:
comment|/* child */
argument|umask(
literal|0
argument|); 		execl(
literal|"/bin/mkdir"
argument|,
literal|"mkdir"
argument|, dirname, (char *)
literal|0
argument|); 		exit(
literal|1
argument|);
comment|/* NOTREACHED */
argument|default:
comment|/* parent */
argument|while ((retcode=wait(&status)) != pid&& retcode != -
literal|1
argument|) 			; 		if (retcode == -
literal|1
argument|) 			return  -
literal|1
argument|; 		else { 			chmod(dirname, mode); 			return status; 		} 	}
comment|/* NOTREACHED */
argument|}
end_function

begin_endif
endif|#
directive|endif
endif|!BSD4_2
end_endif

begin_endif
endif|#
directive|endif
endif|RECOVER
end_endif

end_unit

