begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)confxx.c	7.4 (Berkeley) %G%  */
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

