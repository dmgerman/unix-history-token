begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* @(#)errlst.c	4.1 (Berkeley) 12/21/80 */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sys_errlist
index|[]
init|=
block|{
literal|"Error 0"
block|,
literal|"Not owner"
block|,
literal|"No such file or directory"
block|,
literal|"No such process"
block|,
literal|"Interrupted system call"
block|,
literal|"I/O error"
block|,
literal|"No such device or address"
block|,
literal|"Arg list too long"
block|,
literal|"Exec format error"
block|,
literal|"Bad file number"
block|,
literal|"No children"
block|,
literal|"No more processes"
block|,
literal|"Not enough core"
block|,
literal|"Permission denied"
block|,
literal|"Bad address"
block|,
literal|"Block device required"
block|,
literal|"Mount device busy"
block|,
literal|"File exists"
block|,
literal|"Cross-device link"
block|,
literal|"No such device"
block|,
literal|"Not a directory"
block|,
literal|"Is a directory"
block|,
literal|"Invalid argument"
block|,
literal|"File table overflow"
block|,
literal|"Too many open files"
block|,
literal|"Not a typewriter"
block|,
literal|"Text file busy"
block|,
literal|"File too large"
block|,
literal|"No space left on device"
block|,
literal|"Illegal seek"
block|,
literal|"Read-only file system"
block|,
literal|"Too many links"
block|,
literal|"Broken pipe"
block|,
literal|"Argument too large"
block|,
literal|"Result too large"
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sys_nerr
init|=
block|{
sizeof|sizeof
name|sys_errlist
operator|/
sizeof|sizeof
name|sys_errlist
index|[
literal|0
index|]
block|}
decl_stmt|;
end_decl_stmt

end_unit

