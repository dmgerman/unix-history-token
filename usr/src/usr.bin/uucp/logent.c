begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)logent.c	5.9	(Berkeley) 5/4/88"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"uucp.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_2
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD4_2
argument_list|)
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sys_nerr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sys_errlist
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|Lp
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|Sp
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|USE_SYSLOG
end_ifndef

begin_decl_stmt
specifier|static
name|FILE
modifier|*
name|Ep
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_SYSLOG */
end_comment

begin_decl_stmt
specifier|static
name|int
name|pid
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  *	make log entry  */
end_comment

begin_function
name|FILE
modifier|*
name|get_logfd
parameter_list|(
name|pname
parameter_list|,
name|logfilename
parameter_list|)
name|char
modifier|*
name|pname
decl_stmt|;
name|char
modifier|*
name|logfilename
decl_stmt|;
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
name|int
name|savemask
decl_stmt|;
ifdef|#
directive|ifdef
name|LOGBYSITE
name|char
name|lfile
index|[
name|MAXFULLNAME
index|]
decl_stmt|;
endif|#
directive|endif
endif|LOGBYSITE
name|savemask
operator|=
name|umask
argument_list|(
name|LOGMASK
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|LOGBYSITE
if|if
condition|(
name|pname
operator|!=
name|NULL
condition|)
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|lfile
argument_list|,
literal|"%s/%s/%s"
argument_list|,
name|LOGBYSITE
argument_list|,
name|pname
argument_list|,
name|Rmtname
argument_list|)
expr_stmt|;
name|logfilename
operator|=
name|lfile
expr_stmt|;
block|}
endif|#
directive|endif
endif|LOGBYSITE
name|fp
operator|=
name|fopen
argument_list|(
name|logfilename
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
name|umask
argument_list|(
name|savemask
argument_list|)
expr_stmt|;
if|if
condition|(
name|fp
condition|)
block|{
ifdef|#
directive|ifdef
name|F_SETFL
name|int
name|flags
decl_stmt|;
name|flags
operator|=
name|fcntl
argument_list|(
name|fileno
argument_list|(
name|fp
argument_list|)
argument_list|,
name|F_GETFL
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|fcntl
argument_list|(
name|fileno
argument_list|(
name|Lp
argument_list|)
argument_list|,
name|F_SETFL
argument_list|,
name|flags
operator||
name|O_APPEND
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* F_SETFL */
name|fioclex
argument_list|(
name|fileno
argument_list|(
name|fp
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
comment|/* we really want to log this, but it's the logging that failed*/
name|perror
argument_list|(
name|logfilename
argument_list|)
expr_stmt|;
return|return
name|fp
return|;
block|}
end_function

begin_comment
comment|/*  *	make a log entry  */
end_comment

begin_macro
name|mlogent
argument_list|(
argument|fp
argument_list|,
argument|status
argument_list|,
argument|text
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|text
decl_stmt|,
modifier|*
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|FILE
modifier|*
name|fp
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|struct
name|tm
modifier|*
name|tp
decl_stmt|;
specifier|extern
name|struct
name|tm
modifier|*
name|localtime
parameter_list|()
function_decl|;
if|if
condition|(
name|text
operator|==
name|NULL
condition|)
name|text
operator|=
literal|""
expr_stmt|;
if|if
condition|(
name|status
operator|==
name|NULL
condition|)
name|status
operator|=
literal|""
expr_stmt|;
if|if
condition|(
name|pid
operator|==
literal|0
condition|)
name|pid
operator|=
name|getpid
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|USG
name|time
argument_list|(
operator|&
name|Now
operator|.
name|time
argument_list|)
expr_stmt|;
name|Now
operator|.
name|millitm
operator|=
literal|0
expr_stmt|;
else|#
directive|else
else|!USG
name|ftime
argument_list|(
operator|&
name|Now
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|!USG
name|tp
operator|=
name|localtime
argument_list|(
operator|&
name|Now
operator|.
name|time
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|USG
name|fprintf
argument_list|(
argument|fp
argument_list|,
literal|"%s %s (%d/%d-%2.2d:%2.2d-%d) "
argument_list|,
else|#
directive|else
else|!USG
argument|fprintf(fp,
literal|"%s %s (%d/%d-%02d:%02d-%d) "
argument|,
endif|#
directive|endif
endif|!USG
argument|User, Rmtname, tp->tm_mon +
literal|1
argument|, tp->tm_mday, 		tp->tm_hour, tp->tm_min, pid); 	fprintf(fp,
literal|"%s %s\n"
argument|, status, text);
comment|/* Since it's buffered */
ifndef|#
directive|ifndef
name|F_SETFL
argument|lseek (fileno(fp), (long)
literal|0
argument|,
literal|2
argument|);
endif|#
directive|endif
endif|!F_SETFL
argument|fflush (fp); 	if (Debug) { 		fprintf(stderr,
literal|"%s %s "
argument|, User, Rmtname);
ifdef|#
directive|ifdef
name|USG
argument|fprintf(stderr,
literal|"(%d/%d-%2.2d:%2.2d-%d) "
argument|, tp->tm_mon +
literal|1
argument|, 			tp->tm_mday, tp->tm_hour, tp->tm_min, pid);
else|#
directive|else
else|!USG
argument|fprintf(stderr,
literal|"(%d/%d-%02d:%02d-%d) "
argument|, tp->tm_mon +
literal|1
argument|, 			tp->tm_mday, tp->tm_hour, tp->tm_min, pid);
endif|#
directive|endif
endif|!USG
argument|fprintf(stderr,
literal|"%s %s\n"
argument|, status, text); 	} }
comment|/*  *	close log file  */
argument|logcls() { 	if (Lp != NULL) 		fclose(Lp); 	Lp = NULL;  	if (Sp != NULL) 		fclose (Sp); 	Sp = NULL;
ifndef|#
directive|ifndef
name|USE_SYSLOG
argument|if (Ep != NULL) 		fclose (Ep); 	Ep = NULL;
endif|#
directive|endif
comment|/* !USE_SYSLOG */
argument|}
comment|/*  * Arrange to close fd on exec(II).  * Otherwise unwanted file descriptors are inherited  * by other programs.  And that may be a security hole.  */
ifndef|#
directive|ifndef
name|USG
include|#
directive|include
file|<sgtty.h>
endif|#
directive|endif
argument|fioclex(fd) int fd; { 	register int ret;
if|#
directive|if
name|defined
argument_list|(
name|USG
argument_list|)
operator|||
name|defined
argument_list|(
name|BSD4_2
argument_list|)
argument|ret = fcntl(fd, F_SETFD,
literal|1
argument|);
comment|/* Steve Bellovin says this does it */
else|#
directive|else
argument|ret = ioctl(fd, FIOCLEX, STBNULL);
endif|#
directive|endif
argument|if (ret) 		DEBUG(
literal|2
argument|,
literal|"CAN'T FIOCLEX %d\n"
argument|, fd); }  logent(text, status) char *text
argument_list|,
argument|*status; { 	if (Lp == NULL) 		Lp = get_logfd(Progname, LOGFILE);  	mlogent(Lp, status, text); }
comment|/*  *	make system log entry  */
argument|log_xferstats(text) char *text; { 	char tbuf[BUFSIZ]; 	if (Sp == NULL) 		Sp = get_logfd(
literal|"xferstats"
argument|, SYSLOG); 	sprintf(tbuf,
literal|"(%ld.%02u)"
argument|, Now.time, Now.millitm/
literal|10
argument|); 	mlogent(Sp, tbuf, text); }
ifndef|#
directive|ifndef
name|USE_SYSLOG
comment|/*  * This is for sites that don't have a decent syslog() in their library  * This routine would be a lot simpler if syslog() didn't permit %m  * (or if printf did!)  */
argument|syslog(priority, format, p0, p1, p2, p3, p4) int priority; char *format; { 	char nformat[BUFSIZ]
argument_list|,
argument|sbuf[BUFSIZ]; 	register char *s
argument_list|,
argument|*d; 	register int c; 	long now;  	s = format; 	d = nformat; 	while ((c = *s++) !=
literal|'\0'
argument|&& c !=
literal|'\n'
argument|&& d<&nformat[BUFSIZ]) { 		if (c !=
literal|'%'
argument|) { 			*d++ = c; 			continue; 		} 		if ((c = *s++) !=
literal|'m'
argument|) { 			*d++ =
literal|'%'
argument|; 			*d++ = c; 			continue; 		} 		if ((unsigned)errno> sys_nerr) 			sprintf(d,
literal|"error %d"
argument|, errno); 		else 			strcpy(d, sys_errlist[errno]); 		d += strlen(d); 	} 	*d =
literal|'\0'
argument|;  	if (Ep == NULL) 		Ep = get_logfd(NULL, ERRLOG); 	sprintf(sbuf, nformat, p0, p1, p2, p3, p4); 	mlogent(Ep, sbuf,
literal|""
argument|); }
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !USE_SYSLOG */
end_comment

end_unit

