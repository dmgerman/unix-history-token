begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  *  *	@(#)cat.c	7.2 (Berkeley) %G%  */
end_comment

begin_function
name|main
parameter_list|()
block|{
specifier|register
name|int
name|c
decl_stmt|,
name|fd
decl_stmt|;
name|fd
operator|=
name|getfile
argument_list|(
literal|"File: "
argument_list|,
literal|0
argument_list|)
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getc
argument_list|(
name|fd
argument_list|)
operator|)
operator|>
literal|0
condition|)
name|putchar
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

