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
literal|"@(#)tell.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * return offset in file.  */
end_comment

begin_function_decl
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|long
name|tell
parameter_list|(
name|f
parameter_list|)
block|{
return|return
operator|(
name|lseek
argument_list|(
name|f
argument_list|,
literal|0L
argument_list|,
literal|1
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

