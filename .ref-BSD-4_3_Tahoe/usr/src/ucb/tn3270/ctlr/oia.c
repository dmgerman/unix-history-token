begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that this notice is preserved and that due credit is given  * to the University of California at Berkeley. The name of the University  * may not be used to endorse or promote products derived from this  * software without specific prior written permission. This software  * is provided ``as is'' without express or implied warranty.  */
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
literal|"@(#)oia.c	3.2 (Berkeley) 3/28/88"
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

