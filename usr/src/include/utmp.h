begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)utmp.h	5.1 (Berkeley) 5/30/85  */
end_comment

begin_comment
comment|/*  * Structure of utmp and wtmp files.  *  * Assuming the number 8 is unwise.  */
end_comment

begin_struct
struct|struct
name|utmp
block|{
name|char
name|ut_line
index|[
literal|8
index|]
decl_stmt|;
comment|/* tty name */
name|char
name|ut_name
index|[
literal|8
index|]
decl_stmt|;
comment|/* user id */
name|char
name|ut_host
index|[
literal|16
index|]
decl_stmt|;
comment|/* host name, if remote */
name|long
name|ut_time
decl_stmt|;
comment|/* time on */
block|}
struct|;
end_struct

end_unit

