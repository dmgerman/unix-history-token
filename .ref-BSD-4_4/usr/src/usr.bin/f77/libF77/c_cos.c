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
literal|"@(#)c_cos.c	5.2 (Berkeley) 4/12/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"complex"
end_include

begin_macro
name|c_cos
argument_list|(
argument|r
argument_list|,
argument|z
argument_list|)
end_macro

begin_decl_stmt
name|complex
modifier|*
name|r
decl_stmt|,
modifier|*
name|z
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|double
name|sin
argument_list|()
decl_stmt|,
name|cos
argument_list|()
decl_stmt|,
name|sinh
argument_list|()
decl_stmt|,
name|cosh
argument_list|()
decl_stmt|;
name|r
operator|->
name|real
operator|=
name|cos
argument_list|(
name|z
operator|->
name|real
argument_list|)
operator|*
name|cosh
argument_list|(
name|z
operator|->
name|imag
argument_list|)
expr_stmt|;
name|r
operator|->
name|imag
operator|=
operator|-
name|sin
argument_list|(
name|z
operator|->
name|real
argument_list|)
operator|*
name|sinh
argument_list|(
name|z
operator|->
name|imag
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

