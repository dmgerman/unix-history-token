begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Chris Torek and Darren F. Provine.  *  * %sccs.include.redist.c%  *  *	@(#)shapes.c	8.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Tetris shapes and related routines.  *  * Note that the first 7 are `well known'.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|"tetris.h"
end_include

begin_define
define|#
directive|define
name|TL
value|-B_COLS-1
end_define

begin_comment
comment|/* top left */
end_comment

begin_define
define|#
directive|define
name|TC
value|-B_COLS
end_define

begin_comment
comment|/* top center */
end_comment

begin_define
define|#
directive|define
name|TR
value|-B_COLS+1
end_define

begin_comment
comment|/* top right */
end_comment

begin_define
define|#
directive|define
name|ML
value|-1
end_define

begin_comment
comment|/* middle left */
end_comment

begin_define
define|#
directive|define
name|MR
value|1
end_define

begin_comment
comment|/* middle right */
end_comment

begin_define
define|#
directive|define
name|BL
value|B_COLS-1
end_define

begin_comment
comment|/* bottom left */
end_comment

begin_define
define|#
directive|define
name|BC
value|B_COLS
end_define

begin_comment
comment|/* bottom center */
end_comment

begin_define
define|#
directive|define
name|BR
value|B_COLS+1
end_define

begin_comment
comment|/* bottom right */
end_comment

begin_decl_stmt
name|struct
name|shape
name|shapes
index|[]
init|=
block|{
comment|/* 0*/
literal|7
block|,
name|TL
block|,
name|TC
block|,
name|MR
block|,
comment|/* 1*/
literal|8
block|,
name|TC
block|,
name|TR
block|,
name|ML
block|,
comment|/* 2*/
literal|9
block|,
name|ML
block|,
name|MR
block|,
name|BC
block|,
comment|/* 3*/
literal|3
block|,
name|TL
block|,
name|TC
block|,
name|ML
block|,
comment|/* 4*/
literal|12
block|,
name|ML
block|,
name|BL
block|,
name|MR
block|,
comment|/* 5*/
literal|15
block|,
name|ML
block|,
name|BR
block|,
name|MR
block|,
comment|/* 6*/
literal|18
block|,
name|ML
block|,
name|MR
block|,
comment|/* sticks out */
literal|2
block|,
comment|/* 7*/
literal|0
block|,
name|TC
block|,
name|ML
block|,
name|BL
block|,
comment|/* 8*/
literal|1
block|,
name|TC
block|,
name|MR
block|,
name|BR
block|,
comment|/* 9*/
literal|10
block|,
name|TC
block|,
name|MR
block|,
name|BC
block|,
comment|/*10*/
literal|11
block|,
name|TC
block|,
name|ML
block|,
name|MR
block|,
comment|/*11*/
literal|2
block|,
name|TC
block|,
name|ML
block|,
name|BC
block|,
comment|/*12*/
literal|13
block|,
name|TC
block|,
name|BC
block|,
name|BR
block|,
comment|/*13*/
literal|14
block|,
name|TR
block|,
name|ML
block|,
name|MR
block|,
comment|/*14*/
literal|4
block|,
name|TL
block|,
name|TC
block|,
name|BC
block|,
comment|/*15*/
literal|16
block|,
name|TR
block|,
name|TC
block|,
name|BC
block|,
comment|/*16*/
literal|17
block|,
name|TL
block|,
name|MR
block|,
name|ML
block|,
comment|/*17*/
literal|5
block|,
name|TC
block|,
name|BC
block|,
name|BL
block|,
comment|/*18*/
literal|6
block|,
name|TC
block|,
name|BC
block|,
comment|/* sticks out */
literal|2
operator|*
name|B_COLS
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Return true iff the given shape fits in the given position,  * taking the current board into account.  */
end_comment

begin_function
name|int
name|fits_in
parameter_list|(
name|shape
parameter_list|,
name|pos
parameter_list|)
name|struct
name|shape
modifier|*
name|shape
decl_stmt|;
specifier|register
name|int
name|pos
decl_stmt|;
block|{
specifier|register
name|int
modifier|*
name|o
init|=
name|shape
operator|->
name|off
decl_stmt|;
if|if
condition|(
name|board
index|[
name|pos
index|]
operator|||
name|board
index|[
name|pos
operator|+
operator|*
name|o
operator|++
index|]
operator|||
name|board
index|[
name|pos
operator|+
operator|*
name|o
operator|++
index|]
operator|||
name|board
index|[
name|pos
operator|+
operator|*
name|o
index|]
condition|)
return|return
literal|0
return|;
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/*  * Write the given shape into the current board, turning it on  * if `onoff' is 1, and off if `onoff' is 0.  */
end_comment

begin_function
name|void
name|place
parameter_list|(
name|shape
parameter_list|,
name|pos
parameter_list|,
name|onoff
parameter_list|)
name|struct
name|shape
modifier|*
name|shape
decl_stmt|;
specifier|register
name|int
name|pos
decl_stmt|,
name|onoff
decl_stmt|;
block|{
specifier|register
name|int
modifier|*
name|o
init|=
name|shape
operator|->
name|off
decl_stmt|;
name|board
index|[
name|pos
index|]
operator|=
name|onoff
expr_stmt|;
name|board
index|[
name|pos
operator|+
operator|*
name|o
operator|++
index|]
operator|=
name|onoff
expr_stmt|;
name|board
index|[
name|pos
operator|+
operator|*
name|o
operator|++
index|]
operator|=
name|onoff
expr_stmt|;
name|board
index|[
name|pos
operator|+
operator|*
name|o
index|]
operator|=
name|onoff
expr_stmt|;
block|}
end_function

end_unit

