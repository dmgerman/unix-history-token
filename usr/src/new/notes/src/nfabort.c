begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|RCSIDENT
end_ifdef

begin_decl_stmt
specifier|static
name|char
name|rcsid
index|[]
init|=
literal|"$Header: nfabort.c,v 1.7 85/01/18 15:40:50 notes Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|RCSIDENT
end_endif

begin_comment
comment|/*  *	nfabort(nf, message, title, cname, exitcode)  *  *	Dump a core file and leave it in "cname" suffixed with  *	the pid of the current process.  Place "message" and  *	a line about where the core dump is in "nf" with "title"  *	and then terminate with "exitcode" as an exit code.  *  *	Ray Essick,	February 1984  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_macro
name|nfabort
argument_list|(
argument|nf
argument_list|,
argument|message
argument_list|,
argument|title
argument_list|,
argument|cname
argument_list|,
argument|exitcode
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|nf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|message
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|title
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|cname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|exitcode
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|mypid
decl_stmt|;
name|int
name|pid
decl_stmt|;
name|int
name|rpid
decl_stmt|;
name|int
name|retcode
decl_stmt|;
name|char
name|pbuf
index|[
literal|256
index|]
decl_stmt|;
comment|/* char buffer */
name|char
modifier|*
name|p
decl_stmt|;
comment|/* for message */
if|if
condition|(
name|message
operator|==
name|NULL
condition|)
comment|/* empty */
name|message
operator|=
literal|""
expr_stmt|;
comment|/* fake one */
if|if
condition|(
name|cname
operator|==
name|NULL
operator|||
operator|*
name|cname
operator|==
literal|'\0'
condition|)
comment|/* make one */
name|cname
operator|=
literal|"core"
expr_stmt|;
if|if
condition|(
name|title
operator|==
name|NULL
operator|||
operator|*
name|title
operator|==
literal|'\0'
condition|)
comment|/* title */
name|title
operator|=
literal|"nfabort"
expr_stmt|;
name|mypid
operator|=
name|getpid
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|pid
operator|=
name|fork
argument_list|()
condition|)
block|{
case|case
operator|-
literal|1
case|:
comment|/* couldn't fork! */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"nfabort() unable to log dump\n"
argument_list|)
expr_stmt|;
name|fflush
argument_list|(
name|stderr
argument_list|)
expr_stmt|;
comment|/* dump core anyway */
case|case
literal|0
case|:
comment|/* child */
name|umask
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
comment|/* die quick */
default|default:
comment|/* parent */
while|while
condition|(
operator|(
name|rpid
operator|=
name|wait
argument_list|(
operator|&
name|retcode
argument_list|)
operator|)
operator|!=
name|pid
operator|&&
name|rpid
operator|!=
operator|-
literal|1
condition|)
empty_stmt|;
name|sprintf
argument_list|(
name|pbuf
argument_list|,
literal|"/bin/mv core %s.%d"
argument_list|,
name|cname
argument_list|,
name|mypid
argument_list|)
expr_stmt|;
name|system
argument_list|(
name|pbuf
argument_list|)
expr_stmt|;
comment|/* move it */
name|sprintf
argument_list|(
name|pbuf
argument_list|,
literal|"/bin/chmod 666 %s.%d"
argument_list|,
name|cname
argument_list|,
name|mypid
argument_list|)
expr_stmt|;
name|system
argument_list|(
name|pbuf
argument_list|)
expr_stmt|;
comment|/* un-protect it */
name|sprintf
argument_list|(
name|pbuf
argument_list|,
literal|"Core image left in %s.%d\n"
argument_list|,
name|cname
argument_list|,
name|mypid
argument_list|)
expr_stmt|;
name|p
operator|=
name|malloc
argument_list|(
name|strlen
argument_list|(
name|message
argument_list|)
operator|+
name|strlen
argument_list|(
name|pbuf
argument_list|)
operator|+
literal|4
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
operator|==
name|NULL
condition|)
comment|/* no space */
name|p
operator|=
name|message
expr_stmt|;
comment|/* write something */
else|else
name|sprintf
argument_list|(
name|p
argument_list|,
literal|"%s\n\n%s"
argument_list|,
name|message
argument_list|,
name|pbuf
argument_list|)
expr_stmt|;
if|if
condition|(
name|nf
condition|)
comment|/* only if given */
name|nfcomment
argument_list|(
name|nf
argument_list|,
name|p
argument_list|,
name|title
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* and log it */
name|exit
argument_list|(
name|exitcode
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

