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
literal|"@(#)logent.c	5.6 (Berkeley) 10/9/85"
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

begin_expr_stmt
specifier|static
name|Ltried
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|Stried
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*LINTLIBRARY*/
end_comment

begin_comment
comment|/*  *	make log entry  */
end_comment

begin_macro
name|logent
argument_list|(
argument|text
argument_list|,
argument|status
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

begin_block
block|{
ifdef|#
directive|ifdef
name|LOGBYSITE
name|char
name|lfile
index|[
name|MAXFULLNAME
index|]
decl_stmt|;
specifier|static
name|char
name|LogRmtname
index|[
literal|64
index|]
decl_stmt|;
endif|#
directive|endif
endif|LOGBYSITE
if|if
condition|(
name|Rmtname
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
name|strcpy
argument_list|(
name|Rmtname
argument_list|,
name|Myname
argument_list|)
expr_stmt|;
comment|/* Open the log file if necessary */
ifdef|#
directive|ifdef
name|LOGBYSITE
if|if
condition|(
name|strcmp
argument_list|(
name|Rmtname
argument_list|,
name|LogRmtname
argument_list|)
condition|)
block|{
if|if
condition|(
name|Lp
operator|!=
name|NULL
condition|)
name|fclose
argument_list|(
name|Lp
argument_list|)
expr_stmt|;
name|Lp
operator|=
name|NULL
expr_stmt|;
name|Ltried
operator|=
literal|0
expr_stmt|;
block|}
endif|#
directive|endif
endif|LOGBYSITE
if|if
condition|(
name|Lp
operator|==
name|NULL
condition|)
block|{
if|if
condition|(
operator|!
name|Ltried
condition|)
block|{
name|int
name|savemask
decl_stmt|;
ifdef|#
directive|ifdef
name|F_SETFL
name|int
name|flags
decl_stmt|;
endif|#
directive|endif
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
name|Progname
argument_list|,
name|Rmtname
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|LogRmtname
argument_list|,
name|Rmtname
argument_list|)
expr_stmt|;
name|Lp
operator|=
name|fopen
argument_list|(
name|lfile
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
else|#
directive|else
else|!LOGBYSITE
name|Lp
operator|=
name|fopen
argument_list|(
name|LOGFILE
argument_list|,
literal|"a"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|LOGBYSITE
name|umask
argument_list|(
name|savemask
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|F_SETFL
name|flags
operator|=
name|fcntl
argument_list|(
name|fileno
argument_list|(
name|Lp
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
block|}
name|Ltried
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|Lp
operator|==
name|NULL
condition|)
return|return;
name|fioclex
argument_list|(
name|fileno
argument_list|(
name|Lp
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/*  make entry in existing temp log file  */
name|mlogent
argument_list|(
name|Lp
argument_list|,
name|status
argument_list|,
name|text
argument_list|)
expr_stmt|;
block|}
end_block

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
specifier|static
name|pid
operator|=
literal|0
expr_stmt|;
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
operator|!
name|pid
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
literal|"%s (%s)\n"
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
literal|"%s (%s)\n"
argument|, status, text); 	} }
comment|/*  *	close log file  */
argument|logcls() { 	if (Lp != NULL) 		fclose(Lp); 	Lp = NULL; 	Ltried =
literal|0
argument|;  	if (Sp != NULL) 		fclose (Sp); 	Sp = NULL; 	Stried =
literal|0
argument|; }
comment|/*  *	make system log entry  */
argument|syslog(text) char *text; { 	register struct tm *tp; 	extern struct tm *localtime();
ifdef|#
directive|ifdef
name|LOGBYSITE
argument|char lfile[MAXFULLNAME]; 	static char SLogRmtname[
literal|64
argument|];  	if (strcmp(Rmtname, SLogRmtname)) { 		if (Sp != NULL) 			fclose(Sp); 		Sp = NULL; 		Stried =
literal|0
argument|; 	}
endif|#
directive|endif
endif|LOGBYSITE
argument|if (Sp == NULL) { 		if (!Stried) { 			int savemask;
ifdef|#
directive|ifdef
name|F_SETFL
argument|int flags;
endif|#
directive|endif
endif|F_SETFL
argument|savemask = umask(LOGMASK);
ifdef|#
directive|ifdef
name|LOGBYSITE
argument|(void) sprintf(lfile,
literal|"%s/xferstats/%s"
argument|, LOGBYSITE, Rmtname); 			strcpy(SLogRmtname, Rmtname); 			Sp = fopen (lfile,
literal|"a"
argument|);
else|#
directive|else
else|!LOGBYSITE
argument|Sp = fopen (SYSLOG,
literal|"a"
argument|);
endif|#
directive|endif
endif|LOGBYSITE
argument|umask(savemask);
ifdef|#
directive|ifdef
name|F_SETFL
argument|flags = fcntl(fileno(Sp), F_GETFL,
literal|0
argument|); 			fcntl(fileno(Sp), F_SETFL, flags|O_APPEND);
endif|#
directive|endif
endif|F_SETFL
argument|} 		Stried =
literal|1
argument|; 		if (Sp == NULL) 			return; 		fioclex(fileno(Sp)); 	}
ifdef|#
directive|ifdef
name|USG
argument|time(&Now.time); 	Now.millitm =
literal|0
argument|;
else|#
directive|else
else|!USG
argument|ftime(&Now);
endif|#
directive|endif
endif|!USG
argument|tp = localtime(&Now.time);  	fprintf(Sp,
literal|"%s %s "
argument|, User, Rmtname);
ifdef|#
directive|ifdef
name|USG
argument|fprintf(Sp,
literal|"(%d/%d-%2.2d:%2.2d) "
argument|, tp->tm_mon +
literal|1
argument|, 		tp->tm_mday, tp->tm_hour, tp->tm_min); 	fprintf(Sp,
literal|"(%ld) %s\n"
argument|, Now.time, text);
else|#
directive|else
else|!USG
argument|fprintf(Sp,
literal|"(%d/%d-%02d:%02d) "
argument|, tp->tm_mon +
literal|1
argument|, 		tp->tm_mday, tp->tm_hour, tp->tm_min); 	fprintf(Sp,
literal|"(%ld.%02u) %s\n"
argument|, Now.time, Now.millitm/
literal|10
argument|, text);
endif|#
directive|endif
endif|!USG
comment|/* Position at end and flush */
ifndef|#
directive|ifndef
name|F_SETFL
argument|lseek (fileno(Sp), (long)
literal|0
argument|,
literal|2
argument|);
endif|#
directive|endif
endif|F_SETFL
argument|fflush (Sp); }
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
argument|, fd); }
end_block

end_unit

