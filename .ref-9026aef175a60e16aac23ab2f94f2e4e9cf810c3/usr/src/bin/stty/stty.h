begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)stty.h	8.1 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_struct
struct|struct
name|info
block|{
name|int
name|fd
decl_stmt|;
comment|/* file descriptor */
name|int
name|ldisc
decl_stmt|;
comment|/* line discipline */
name|int
name|off
decl_stmt|;
comment|/* turn off */
name|int
name|set
decl_stmt|;
comment|/* need set */
name|int
name|wset
decl_stmt|;
comment|/* need window set */
name|char
modifier|*
name|arg
decl_stmt|;
comment|/* argument */
name|struct
name|termios
name|t
decl_stmt|;
comment|/* terminal info */
name|struct
name|winsize
name|win
decl_stmt|;
comment|/* window info */
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

