begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)spint.h	4.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The 'spint' (spawn and interrupt) routines use this structure.  *  * Note that spint_asm.asm contains an Assembly language version of  * the following, so keep changes in synch!  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|union
name|REGS
name|regs
decl_stmt|;
name|struct
name|SREGS
name|sregs
decl_stmt|;
name|int
name|int_no
decl_stmt|;
comment|/* Which interrupt to wait on */
name|int
name|done
decl_stmt|;
comment|/* Are we done, or just took an interrupt? */
name|int
name|rc
decl_stmt|;
comment|/* return code */
block|}
name|Spint
typedef|;
end_typedef

end_unit

