begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)lstFake.c	5.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*-  * lstFake.c --  *	This is a file whose sole purpose is to force ranlib to  *	place enough entries in the library's table of contents to  *	prevent it (the table of contents) from looking like an object  *	file. As of this writing, the table had 0410 (shared text) entries  *	in it, so we define five junk variables to up the number beyond  *	the range of the magic numbers.  */
end_comment

begin_decl_stmt
name|int
name|_junk_one__
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_junk_two__
init|=
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_junk_three__
init|=
literal|3
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_junk_four__
init|=
literal|4
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|_junk_five__
init|=
literal|5
decl_stmt|;
end_decl_stmt

end_unit

