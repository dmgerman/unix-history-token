begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  */
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
literal|"@(#)arc.c	5.2 (Berkeley) %G%"
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
file|"dumb.h"
end_include

begin_macro
name|arc
argument_list|(
argument|xc
argument_list|,
argument|yc
argument_list|,
argument|xbeg
argument_list|,
argument|ybeg
argument_list|,
argument|xend
argument_list|,
argument|yend
argument_list|)
end_macro

begin_decl_stmt
name|int
name|xc
decl_stmt|,
name|yc
decl_stmt|,
name|xbeg
decl_stmt|,
name|ybeg
decl_stmt|,
name|xend
decl_stmt|,
name|yend
decl_stmt|;
end_decl_stmt

begin_block
block|{ }
end_block

end_unit

