begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)stty.h	5.1 (Berkeley) %G%  */
end_comment

begin_struct
struct|struct
name|modes
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|long
name|set
decl_stmt|;
name|long
name|unset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cchar
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|sub
decl_stmt|;
name|u_char
name|def
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|FMT
block|{
name|NOTSET
block|,
name|GFLAG
block|,
name|BSD
block|,
name|POSIX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|LINELENGTH
value|72
end_define

end_unit

