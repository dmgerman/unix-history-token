begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
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
literal|"@(#)rnd_pos.c	5.4 (Berkeley) %G%"
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
file|"robots.h"
end_include

begin_define
define|#
directive|define
name|IS_SAME
parameter_list|(
name|p
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|)
value|((p).y != -1&& (p).y == y&& (p).x == x)
end_define

begin_comment
comment|/*  * rnd_pos:  *	Pick a random, unoccupied position  */
end_comment

begin_function
name|COORD
modifier|*
name|rnd_pos
parameter_list|()
block|{
specifier|static
name|COORD
name|pos
decl_stmt|;
specifier|static
name|int
name|call
init|=
literal|0
decl_stmt|;
specifier|register
name|int
name|i
init|=
literal|0
decl_stmt|;
do|do
block|{
name|pos
operator|.
name|y
operator|=
name|rnd
argument_list|(
name|Y_FIELDSIZE
operator|-
literal|1
argument_list|)
operator|+
literal|1
expr_stmt|;
name|pos
operator|.
name|x
operator|=
name|rnd
argument_list|(
name|X_FIELDSIZE
operator|-
literal|1
argument_list|)
operator|+
literal|1
expr_stmt|;
name|refresh
argument_list|()
expr_stmt|;
block|}
do|while
condition|(
name|Field
index|[
name|pos
operator|.
name|y
index|]
index|[
name|pos
operator|.
name|x
index|]
operator|!=
literal|0
condition|)
do|;
name|call
operator|++
expr_stmt|;
return|return
operator|&
name|pos
return|;
block|}
end_function

begin_macro
name|rnd
argument_list|(
argument|range
argument_list|)
end_macro

begin_decl_stmt
name|int
name|range
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|unsigned
name|int
name|rand
parameter_list|()
function_decl|;
return|return
name|rand
argument_list|()
operator|%
name|range
return|;
block|}
end_block

end_unit

