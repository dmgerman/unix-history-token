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
literal|"@(#)close.c	5.2 (Berkeley) 4/30/85"
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
file|"aed.h"
end_include

begin_comment
comment|/*---------------------------------------------------------  *	Closepl does whatever is necessary to reset the characteristics  *	of the AED512 after the program is finished.  *  *	Results:	None.  *  *	Side Effects:  *	The graphics display modes are reset.  *---------------------------------------------------------  */
end_comment

begin_macro
name|closepl
argument_list|()
end_macro

begin_block
block|{
name|fputs
argument_list|(
literal|"Q00204\6"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|stty
argument_list|(
name|fileno
argument_list|(
name|stdout
argument_list|)
argument_list|,
operator|&
name|sgttyb
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

