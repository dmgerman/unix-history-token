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
literal|"@(#)open.c	5.2 (Berkeley) 4/30/85"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|not lint
end_endif

begin_comment
comment|/*  * Displays plot files on a AED512 graphics terminal.  */
end_comment

begin_include
include|#
directive|include
file|"aed.h"
end_include

begin_decl_stmt
name|char
name|dbuf
index|[
name|BUFSIZ
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used to buffer display characters */
end_comment

begin_decl_stmt
name|struct
name|sgttyb
name|sgttyb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Used to save terminal control bits */
end_comment

begin_expr_stmt
name|curx
operator|,
name|cury
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Current screen position */
end_comment

begin_decl_stmt
name|int
name|xbot
decl_stmt|,
name|ybot
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Coordinates of screen lower-left corner */
end_comment

begin_decl_stmt
name|int
name|scale
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The number of pixels per 2**12 units 			 * of world coordinates. 			 */
end_comment

begin_comment
comment|/*  * The following is the color map, containing reg, green, and blue  * values for color locations 0 and 1.  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|colors
index|[]
init|=
block|{
literal|200
block|,
literal|200
block|,
literal|200
block|,
literal|0
block|,
literal|0
block|,
literal|125
block|,
literal|125
block|,
literal|0
block|,
literal|0
block|,
literal|125
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*---------------------------------------------------------  *	Openpl initializes the graphics display and clears its screen.  *  *	Results:	None.  *  *	Side Effects:  *	The display is re-initialized and the file is remembered for  *	use in all subsequent calls to this module.  The display's  *	color map is reset.  The display is put into raw mode, but  *	the previous mode bits are saved.  *  *	Errors:		None.  *---------------------------------------------------------  */
end_comment

begin_macro
name|openpl
argument_list|()
end_macro

begin_block
block|{
name|int
name|flags
decl_stmt|,
modifier|*
name|p
decl_stmt|,
name|i
decl_stmt|;
name|char
name|dum
index|[
literal|4
index|]
decl_stmt|;
comment|/* First, grab up the display modes, then reset them to put it      * into cooked mode.  Also, lock the terminal.      */
operator|(
name|void
operator|)
name|gtty
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
name|flags
operator|=
name|sgttyb
operator|.
name|sg_flags
expr_stmt|;
name|sgttyb
operator|.
name|sg_flags
operator|=
operator|(
name|sgttyb
operator|.
name|sg_flags
operator|&
operator|~
operator|(
name|RAW
operator||
name|CBREAK
operator|)
operator|)
operator||
name|EVENP
operator||
name|ODDP
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
name|sgttyb
operator|.
name|sg_flags
operator|=
name|flags
expr_stmt|;
comment|/* Save the file pointer around for later use, then output an      * initialization string to the display.  The initialization      * string resets the terminal, sets formats, clears the display,      * initializes the read and write masks, and sets the color map.      */
name|setbuf
argument_list|(
name|stdout
argument_list|,
name|dbuf
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"\33\33G1HHHN[00LFFCFFMFFFFFFFF"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
literal|"K0004"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|p
operator|=
name|colors
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|12
condition|;
name|i
operator|++
control|)
block|{
name|chex
argument_list|(
operator|*
name|p
operator|++
argument_list|,
name|dum
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|fputs
argument_list|(
name|dum
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
block|}
name|fputs
argument_list|(
literal|"^15060AL"
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
name|scale
operator|=
literal|1
operator|<<
literal|12
expr_stmt|;
name|curx
operator|=
name|cury
operator|=
name|xbot
operator|=
name|ybot
operator|=
literal|0
expr_stmt|;
operator|(
name|void
operator|)
name|fflush
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

