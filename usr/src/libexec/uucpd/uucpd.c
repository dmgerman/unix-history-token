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
literal|"@(#)uucpd.c	5.1 (BERKELEY) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * UUCP server daemon  * 	Looks for attempts to connect on our uucp socket.  When it  *	finds one it execs uucico to handle it.  *  * Invoked by inetd.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

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

begin_define
define|#
directive|define
name|UUCICO
value|"/usr/lib/uucp/uucico"
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

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
name|int
name|status
decl_stmt|,
name|fromlen
decl_stmt|;
name|struct
name|sockaddr_in
name|from
decl_stmt|;
name|fromlen
operator|=
sizeof|sizeof
argument_list|(
name|from
argument_list|)
expr_stmt|;
if|if
condition|(
name|getpeername
argument_list|(
literal|0
argument_list|,
operator|&
name|from
argument_list|,
operator|&
name|fromlen
argument_list|)
operator|<
literal|0
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|argv
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|perror
argument_list|(
literal|"getpeername"
argument_list|)
expr_stmt|;
name|_exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|execl
argument_list|(
name|UUCICO
argument_list|,
literal|"UUCICO"
argument_list|,
literal|"-r0"
argument_list|,
literal|"-v"
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|openlog
argument_list|(
literal|"uucpd"
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|syslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"%s: %m"
argument_list|,
name|UUCICO
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

