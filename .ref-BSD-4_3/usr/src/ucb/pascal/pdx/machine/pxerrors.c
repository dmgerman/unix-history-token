begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)pxerrors.c	5.1 (Berkeley) 6/6/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * px error messages  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|pxerrmsg
index|[]
init|=
block|{
literal|"not an error!"
block|,
literal|"argument to chr out of range"
block|,
literal|"div (integer divide) by zero"
block|,
literal|"real divide by zero"
block|,
literal|"call to procedure halt"
block|,
literal|"reference through a nil pointer"
block|,
literal|"tried to read past end-of-file"
block|,
literal|"negative parameter to sqrt"
block|,
literal|"pi/px error: stack not empty"
block|,
literal|"subscript out of range"
block|,
literal|"reference to an inactive file"
block|,
literal|"pi/px error: write failed"
block|,
literal|"pi/px error: create failed"
block|,
literal|"non-positive argument to ln"
block|,
literal|"pi/px error: bad op"
block|,
literal|"bad data on integer read"
block|,
literal|"pi/px error: active frame not found in goto"
block|,
literal|"label not found in case"
block|,
literal|"pi/px error: seek failed"
block|,
literal|"pi/px error: bad parameter to alloc"
block|,
literal|"out of memory"
block|,
literal|"constructed set parameter exceeds set bounds"
block|,
literal|"too many digits in number"
block|,
literal|"mod (integer remainder) by 0"
block|,
literal|"bad data on real read"
block|,
literal|"pi/px error: remove failed"
block|,
literal|"pi/px error: close failed"
block|,
literal|"pi/px error: open failed"
block|,
literal|"parameter to argv out of range"
block|,
literal|"bad i to pack(a, i, z)"
block|,
literal|"bad i to unpack(z, a, i)"
block|,
literal|"value out of range"
block|,
literal|"assertion failed"
block|,
literal|"tried to read, but open for writing"
block|,
literal|"tried to write, but open for reading"
block|,
literal|"integer number too large"
block|,
literal|"statement limit exceeded"
block|,
literal|"runtime stack overflow"
block|,
literal|"interrupt"
block|,
literal|"overflow, underflow, or divide by zero in arithmetic operation"
block|, }
decl_stmt|;
end_decl_stmt

end_unit

