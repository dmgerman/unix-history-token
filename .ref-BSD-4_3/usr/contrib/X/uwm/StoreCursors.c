begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_StoreCursors_c
init|=
literal|"$Header: StoreCursors.c,v 10.3 86/02/01 16:23:56 tony Rel $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_comment
comment|/************************************************************************  *									*  *			Copyright (c) 1986 by				*  *		Digital Equipment Corporation, Maynard, MA		*  *		         All Rights Reserved.				*  *									*  *	Permission to use, copy, modify, and distribute this software	*  *	and its documentation is hereby granted only to licensees of 	*  *	The Regents of the University of California pursuant to their	*  *	license agreement for the Berkeley Software Distribution 	*  *	provided that the following appears on all copies.		*  *									*  *            "LICENSED FROM DIGITAL EQUIPMENT CORPORATION		*  *                      COPYRIGHT (C) 1986				*	  *                 DIGITAL EQUIPMENT CORPORATION			*  *                         MAYNARD, MA					*  *                     ALL RIGHTS RESERVED.				*  *									*  *      THE INFORMATION IN THIS SOFTWARE IS SUBJECT TO CHANGE WITHOUT	*   *	NOTICE AND SHOULD NOT BE CONSTRUED AS A COMMITMENT BY DIGITAL	*  *	EQUIPMENT CORPORATION.  DIGITAL MAKES NO REPRESENTATIONS	*  *	ABOUT SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE. IT IS	*  *	SUPPLIED "AS IS" WITHOUT EXPRESS OR IMPLIED WARRANTY.		*  *									*	  * 	IF THE UNIVERSITY OF CALIFORNIA OR ITS LICENSEES MODIFY 	*	  *	THE SOFTWARE IN A MANNER CREATING DERIVATIVE COPYRIGHT 		*	  *	RIGHTS APPROPRIATE COPYRIGHT LEGENDS MAY BE PLACED ON THE	*  *	DERIVATIVE WORK IN ADDITION TO THAT SET FORTH ABOVE."		*	  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*  * MODIFICATION HISTORY  *  * 000 -- M. Gancarz, DEC Ultrix Engineering Group  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)StoreCursors.c	3.8	1/24/86"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"uwm.h"
end_include

begin_comment
comment|/*  * Include the cursor definition files.  */
end_comment

begin_include
include|#
directive|include
file|<X/cursors/arrow_cross.cursor>
end_include

begin_include
include|#
directive|include
file|<X/cursors/arrow_cross_mask.cursor>
end_include

begin_include
include|#
directive|include
file|<X/cursors/xterm.cursor>
end_include

begin_include
include|#
directive|include
file|<X/cursors/xterm_mask.cursor>
end_include

begin_include
include|#
directive|include
file|<X/cursors/icon.cursor>
end_include

begin_include
include|#
directive|include
file|<X/cursors/icon_mask.cursor>
end_include

begin_include
include|#
directive|include
file|"menu.cursor"
end_include

begin_include
include|#
directive|include
file|"menu_mask.cursor"
end_include

begin_include
include|#
directive|include
file|"leftbutton.cursor"
end_include

begin_include
include|#
directive|include
file|"middlebutton.cursor"
end_include

begin_include
include|#
directive|include
file|"rightbutton.cursor"
end_include

begin_include
include|#
directive|include
file|"button_mask.cursor"
end_include

begin_comment
comment|/*  * Store all the cursors into global variables.  */
end_comment

begin_macro
name|StoreCursors
argument_list|()
end_macro

begin_block
block|{
comment|/*      * Main uwm cursor and movement cursor.      */
name|ArrowCrossCursor
operator|=
name|XCreateCursor
argument_list|(
name|arrow_cross_width
argument_list|,
name|arrow_cross_height
argument_list|,
name|arrow_cross_bits
argument_list|,
name|arrow_cross_mask_bits
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
name|BlackPixel
argument_list|,
name|WhitePixel
argument_list|,
name|CursorFunc
argument_list|)
expr_stmt|;
if|if
condition|(
name|ArrowCrossCursor
operator|==
name|FAILURE
condition|)
block|{
name|Error
argument_list|(
literal|"StoreCursors -> Unable to store ArrowCrossCursor."
argument_list|)
expr_stmt|;
block|}
comment|/*      * Text cursor used in icons.      */
name|TextCursor
operator|=
name|XCreateCursor
argument_list|(
name|xterm_width
argument_list|,
name|xterm_height
argument_list|,
name|xterm_bits
argument_list|,
name|xterm_mask_bits
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
name|BlackPixel
argument_list|,
name|WhitePixel
argument_list|,
name|CursorFunc
argument_list|)
expr_stmt|;
if|if
condition|(
name|TextCursor
operator|==
name|FAILURE
condition|)
block|{
name|Error
argument_list|(
literal|"StoreCursors -> Unable to store TextCursor."
argument_list|)
expr_stmt|;
block|}
comment|/*      * Icon cursor used to iconify windows.      */
name|IconCursor
operator|=
name|XCreateCursor
argument_list|(
name|icon_width
argument_list|,
name|icon_height
argument_list|,
name|icon_bits
argument_list|,
name|icon_mask_bits
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
name|ITextForground
argument_list|,
name|ITextBackground
argument_list|,
name|IconCursorFunc
argument_list|)
expr_stmt|;
if|if
condition|(
name|IconCursor
operator|==
name|FAILURE
condition|)
block|{
name|Error
argument_list|(
literal|"StoreCursors -> Unable to store IconCursor."
argument_list|)
expr_stmt|;
block|}
comment|/*      * Menu cursor.      */
name|MenuCursor
operator|=
name|XCreateCursor
argument_list|(
name|menu_width
argument_list|,
name|menu_height
argument_list|,
name|menu_bits
argument_list|,
name|menu_mask_bits
argument_list|,
literal|0
argument_list|,
literal|8
argument_list|,
name|ITextForground
argument_list|,
name|ITextBackground
argument_list|,
name|IconCursorFunc
argument_list|)
expr_stmt|;
if|if
condition|(
name|MenuCursor
operator|==
name|FAILURE
condition|)
block|{
name|Error
argument_list|(
literal|"StoreCursors -> Unable to store MenuCursor."
argument_list|)
expr_stmt|;
block|}
comment|/*      * Left button main cursor.      */
name|LeftButtonCursor
operator|=
name|XCreateCursor
argument_list|(
name|leftbutton_width
argument_list|,
name|leftbutton_height
argument_list|,
name|leftbutton_bits
argument_list|,
name|button_mask_bits
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
name|WhitePixel
argument_list|,
name|BlackPixel
argument_list|,
name|CursorFunc
argument_list|)
expr_stmt|;
if|if
condition|(
name|LeftButtonCursor
operator|==
name|FAILURE
condition|)
block|{
name|Error
argument_list|(
literal|"StoreCursors -> Unable to store LeftButtonCursor."
argument_list|)
expr_stmt|;
block|}
comment|/*      * Middle button main cursor.      */
name|MiddleButtonCursor
operator|=
name|XCreateCursor
argument_list|(
name|middlebutton_width
argument_list|,
name|middlebutton_height
argument_list|,
name|middlebutton_bits
argument_list|,
name|button_mask_bits
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
name|WhitePixel
argument_list|,
name|BlackPixel
argument_list|,
name|CursorFunc
argument_list|)
expr_stmt|;
if|if
condition|(
name|MiddleButtonCursor
operator|==
name|FAILURE
condition|)
block|{
name|Error
argument_list|(
literal|"StoreCursors -> Unable to store MiddleButtonCursor."
argument_list|)
expr_stmt|;
block|}
comment|/*      * Right button main cursor.      */
name|RightButtonCursor
operator|=
name|XCreateCursor
argument_list|(
name|rightbutton_width
argument_list|,
name|rightbutton_height
argument_list|,
name|rightbutton_bits
argument_list|,
name|button_mask_bits
argument_list|,
literal|8
argument_list|,
literal|8
argument_list|,
name|WhitePixel
argument_list|,
name|BlackPixel
argument_list|,
name|CursorFunc
argument_list|)
expr_stmt|;
if|if
condition|(
name|RightButtonCursor
operator|==
name|FAILURE
condition|)
block|{
name|Error
argument_list|(
literal|"StoreCursors -> Unable to store RightButtonCursor."
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

