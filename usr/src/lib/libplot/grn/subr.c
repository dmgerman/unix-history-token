begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980, 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  */
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
literal|"@(#)subr.c	6.1 (Berkeley) 8/29/86"
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
file|"grnplot.h"
end_include

begin_comment
comment|/*---------------------------------------------------------  *	This local routine outputs an x-y coordinate pair in the standard  *	format required by the grn file.  *  *	Results:	None.  *	  *	Side Effects:  *  *	Errors:		None.  *---------------------------------------------------------  */
end_comment

begin_macro
name|outxy
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|)
end_macro

begin_decl_stmt
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The coordinates to be output.  Note: 				 * these are world coordinates, not screen 				 * ones.  We scale in this routine. 				 */
end_comment

begin_block
block|{
name|printf
argument_list|(
literal|"%.2f %.2f\n"
argument_list|,
operator|(
name|x
operator|-
name|xbot
operator|)
operator|*
name|scale
argument_list|,
operator|(
name|y
operator|-
name|ybot
operator|)
operator|*
name|scale
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|outcurxy
argument_list|()
end_macro

begin_block
block|{
name|outxy
argument_list|(
name|curx
argument_list|,
name|cury
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|startvector
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|ingrnfile
condition|)
name|erase
argument_list|()
expr_stmt|;
if|if
condition|(
name|invector
condition|)
return|return;
name|invector
operator|=
literal|1
expr_stmt|;
name|printf
argument_list|(
literal|"VECTOR\n"
argument_list|)
expr_stmt|;
name|outcurxy
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|endvector
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|invector
condition|)
return|return;
name|invector
operator|=
literal|0
expr_stmt|;
name|printf
argument_list|(
literal|"*\n%d 0\n0\n"
argument_list|,
name|linestyle
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

