begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)vfont.h	5.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The structures header and dispatch define the format of a font file.  *  * See vfont(5) for more details.  */
end_comment

begin_struct
struct|struct
name|header
block|{
name|short
name|magic
decl_stmt|;
name|unsigned
name|short
name|size
decl_stmt|;
name|short
name|maxx
decl_stmt|;
name|short
name|maxy
decl_stmt|;
name|short
name|xtend
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dispatch
block|{
name|unsigned
name|short
name|addr
decl_stmt|;
name|short
name|nbytes
decl_stmt|;
name|char
name|up
decl_stmt|,
name|down
decl_stmt|,
name|left
decl_stmt|,
name|right
decl_stmt|;
name|short
name|width
decl_stmt|;
block|}
struct|;
end_struct

end_unit

