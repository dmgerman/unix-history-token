begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)confxx.c	7.5 (Berkeley) 6/29/88  */
end_comment

begin_decl_stmt
name|int
name|xxstrategy
argument_list|()
decl_stmt|,
name|xxopen
argument_list|()
decl_stmt|,
name|xxioctl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|devsw
name|devsw
index|[]
init|=
block|{
block|{
literal|"XX"
block|,
name|xxstrategy
block|,
name|xxopen
block|,
name|nullsys
block|,
name|noioctl
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ndevs
init|=
operator|(
sizeof|sizeof
argument_list|(
name|devsw
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|devsw
index|[
literal|0
index|]
argument_list|)
operator|)
decl_stmt|;
end_decl_stmt

end_unit

