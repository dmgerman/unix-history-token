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
literal|"@(#)zoomon.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|zoomon
argument_list|()
end_macro

begin_block
block|{
name|escseq
argument_list|(
name|ESCD
argument_list|)
expr_stmt|;
name|outchar
argument_list|(
literal|'g'
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|zoomoff
argument_list|()
end_macro

begin_block
block|{
name|escseq
argument_list|(
name|ESCD
argument_list|)
expr_stmt|;
name|outchar
argument_list|(
literal|'h'
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

