begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)oia.c	4.2 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  * Routines to maintain the Operator Information Area.  */
end_comment

begin_include
include|#
directive|include
file|"../general/general.h"
end_include

begin_include
include|#
directive|include
file|"oia.h"
end_include

begin_include
include|#
directive|include
file|"../general/globals.h"
end_include

begin_macro
name|init_oia
argument_list|()
end_macro

begin_block
block|{
name|ClearElement
argument_list|(
name|OperatorInformationArea
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

