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
literal|"@(#)tempnam.c	4.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_function
name|char
modifier|*
name|tmpnam
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
specifier|static
name|seed
expr_stmt|;
name|sprintf
argument_list|(
name|s
argument_list|,
literal|"temp.%d.%d"
argument_list|,
name|getpid
argument_list|()
argument_list|,
name|seed
operator|++
argument_list|)
expr_stmt|;
return|return
operator|(
name|s
operator|)
return|;
block|}
end_function

end_unit

