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
literal|"@(#)erase.c	5.2 (Berkeley) %G%"
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
file|"hp2648.h"
end_include

begin_macro
name|erase
argument_list|()
end_macro

begin_block
block|{
name|buffready
argument_list|(
literal|8
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
name|ESC
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
name|GRAPHIC
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
name|DISPLAY
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'a'
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
name|ESC
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
name|GRAPHIC
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
name|PLOT
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
name|BINARY
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

