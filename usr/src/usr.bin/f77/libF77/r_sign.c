begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * This module is believed to contain source code proprietary to AT&T.  * Use and redistribution is subject to the Berkeley Software License  * Agreement and your Software Agreement with AT&T (Western Electric).  */
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
literal|"@(#)r_sign.c	5.3 (Berkeley) 4/12/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_function
name|float
name|r_sign
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
name|float
modifier|*
name|a
decl_stmt|,
decl|*
name|b
decl_stmt|;
end_function

begin_block
block|{
name|float
name|x
decl_stmt|;
name|x
operator|=
operator|(
operator|*
name|a
operator|>=
literal|0
condition|?
operator|*
name|a
else|:
operator|-
operator|*
name|a
operator|)
expr_stmt|;
return|return
operator|(
operator|*
name|b
operator|>=
literal|0
condition|?
name|x
else|:
operator|-
name|x
operator|)
return|;
block|}
end_block

end_unit

