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
name|char
name|copyright
index|[]
init|=
literal|"@(#) Copyright (c) 1980 Regents of the University of California.\n\  All rights reserved.\n"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

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
literal|"@(#)makekey.c	5.1 (Berkeley) 6/6/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * You send it 10 bytes.  * It sends you 13 bytes.  * The transformation is expensive to perform  * (a significant part of a second).  */
end_comment

begin_function_decl
name|char
modifier|*
name|crypt
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|main
parameter_list|()
block|{
name|char
name|key
index|[
literal|8
index|]
decl_stmt|;
name|char
name|salt
index|[
literal|2
index|]
decl_stmt|;
name|read
argument_list|(
literal|0
argument_list|,
name|key
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|read
argument_list|(
literal|0
argument_list|,
name|salt
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|write
argument_list|(
literal|1
argument_list|,
name|crypt
argument_list|(
name|key
argument_list|,
name|salt
argument_list|)
argument_list|,
literal|13
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

