begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)s_rnge.c	5.1	6/7/85  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/* called when a subscript is out of range */
end_comment

begin_macro
name|s_rnge
argument_list|(
argument|varn
argument_list|,
argument|offset
argument_list|,
argument|procn
argument_list|,
argument|line
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|varn
decl_stmt|,
modifier|*
name|procn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|int
name|offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|line
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Subscript out of range on file line %d, procedure "
argument_list|,
name|line
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|8
operator|&&
operator|*
name|procn
operator|!=
literal|'_'
condition|;
operator|++
name|i
control|)
name|putc
argument_list|(
operator|*
name|procn
operator|++
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|".\nAttempt to access the %ld-th element of variable "
argument_list|,
name|offset
operator|+
literal|1
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|6
operator|&&
operator|*
name|varn
operator|!=
literal|' '
condition|;
operator|++
name|i
control|)
name|putc
argument_list|(
operator|*
name|varn
operator|++
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|".\n"
argument_list|)
expr_stmt|;
name|f77_abort
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

