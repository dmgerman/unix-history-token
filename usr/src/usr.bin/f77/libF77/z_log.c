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
literal|"@(#)z_log.c	5.3 (Berkeley) 4/12/91"
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

begin_ifdef
ifdef|#
directive|ifdef
name|tahoe
end_ifdef

begin_define
define|#
directive|define
name|cabs
value|zabs
end_define

begin_endif
endif|#
directive|endif
endif|tahoe
end_endif

begin_macro
name|z_log
argument_list|(
argument|r
argument_list|,
argument|z
argument_list|)
end_macro

begin_decl_stmt
name|dcomplex
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
name|log
argument_list|()
decl_stmt|,
name|cabs
argument_list|()
decl_stmt|,
name|atan2
argument_list|()
decl_stmt|;
name|r
operator|->
name|dimag
operator|=
name|atan2
argument_list|(
name|z
operator|->
name|dimag
argument_list|,
name|z
operator|->
name|dreal
argument_list|)
expr_stmt|;
name|r
operator|->
name|dreal
operator|=
name|log
argument_list|(
name|cabs
argument_list|(
name|z
operator|->
name|dreal
argument_list|,
name|z
operator|->
name|dimag
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

