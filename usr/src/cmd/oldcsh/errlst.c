begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_decl_stmt
name|char
modifier|*
name|sys_errlist
index|[]
block|{
literal|"Error 0"
operator|,
literal|"Not super-user"
operator|,
literal|"No such file or directory"
operator|,
literal|"No such process"
operator|,
literal|"Interrupted system call"
operator|,
literal|"I/O error"
operator|,
literal|"No such device or address"
operator|,
literal|"Arguments too long"
operator|,
literal|"Exec format error"
operator|,
literal|"Bad file number"
operator|,
literal|"No children"
operator|,
literal|"No more processes"
operator|,
literal|"Not enough core"
operator|,
literal|"Permission denied"
operator|,
literal|"Error 14"
operator|,
literal|"Block device required"
operator|,
literal|"Mount device busy"
operator|,
literal|"File exists"
operator|,
literal|"Cross-device link"
operator|,
literal|"No such device"
operator|,
literal|"Not a directory"
operator|,
literal|"Is a directory"
operator|,
literal|"Invalid argument"
operator|,
literal|"File table overflow"
operator|,
literal|"Too many open files"
operator|,
literal|"Not a typewriter"
operator|,
literal|"Text file busy"
operator|,
literal|"File too large"
operator|,
literal|"No space left on device"
operator|,
literal|"Illegal seek"
operator|,
literal|"Read-only file system"
operator|,
literal|"Too many links"
operator|,
literal|"Broken Pipe"
operator|,
literal|"Disk quota exceeded"
operator|,
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|sys_nerr
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
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

