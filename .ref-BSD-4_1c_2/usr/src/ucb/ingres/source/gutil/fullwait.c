begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)fullwait.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  FULLWAIT -- performs a wait(II) primitive for a given child. ** **	The wait primitive is executed as many times as needed to get **	termination status for a given child.  The case of an interrupt **	during the wait is handled.  No other children may die during **	the wait.  Also, the child must die "normally", that is, as the **	result of an exit() system call, or from an interrupt. ** **	Parameters: **		"child" -- the pid of the child process to wait for, **			returned from the fork() system call. **		"name" -- a character string representing the name of **			the calling routine; printed on syserr's. **	Returns: **		The exit parameter of the child process. */
end_comment

begin_macro
name|fullwait
argument_list|(
argument|child
argument_list|,
argument|name
argument_list|)
end_macro

begin_decl_stmt
name|int
name|child
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|name
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|auto
name|int
name|st
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
specifier|extern
name|int
name|errno
decl_stmt|;
specifier|register
name|char
modifier|*
name|n
decl_stmt|;
specifier|register
name|char
modifier|*
name|coredump
decl_stmt|;
name|n
operator|=
name|name
expr_stmt|;
comment|/* wait for a child to die */
while|while
condition|(
operator|(
name|i
operator|=
name|wait
argument_list|(
operator|&
name|st
argument_list|)
operator|)
operator|!=
name|child
condition|)
block|{
comment|/* it is not the child we want; chew on it a little more */
if|if
condition|(
name|i
operator|!=
operator|-
literal|1
condition|)
name|syserr
argument_list|(
literal|"%s: bad child: pid %d st 0%o"
argument_list|,
name|n
argument_list|,
name|i
argument_list|,
name|st
argument_list|)
expr_stmt|;
comment|/* check for interrupted system call */
if|if
condition|(
name|errno
operator|!=
name|EINTR
condition|)
block|{
comment|/* wait with no child */
name|syserr
argument_list|(
literal|"%s: no child"
argument_list|,
name|n
argument_list|)
expr_stmt|;
block|}
name|errno
operator|=
literal|0
expr_stmt|;
comment|/* dropped out from signal: reexecute the wait */
block|}
comment|/* check termination status */
name|i
operator|=
name|st
operator|&
literal|0377
expr_stmt|;
if|if
condition|(
name|i
operator|>
literal|2
condition|)
block|{
comment|/* child collapsed */
if|if
condition|(
name|i
operator|&
literal|0200
condition|)
block|{
name|coredump
operator|=
literal|" -- core dumped"
expr_stmt|;
name|i
operator|&=
literal|0177
expr_stmt|;
block|}
else|else
block|{
name|coredump
operator|=
literal|""
expr_stmt|;
block|}
name|syserr
argument_list|(
literal|"%s: stat %d%s"
argument_list|,
name|n
argument_list|,
name|i
argument_list|,
name|coredump
argument_list|)
expr_stmt|;
block|}
comment|/* return exit status */
return|return
operator|(
name|st
operator|>>
literal|8
operator|)
return|;
block|}
end_block

end_unit

