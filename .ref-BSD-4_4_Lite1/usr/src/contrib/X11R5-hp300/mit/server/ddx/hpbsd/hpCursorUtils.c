begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************  *   * (c)Copyright 1992 Hewlett-Packard Co.,  All Rights Reserved.  *   *                          RESTRICTED RIGHTS LEGEND  * Use, duplication, or disclosure by the U.S. Government is subject to  * restrictions as set forth in sub-paragraph (c)(1)(ii) of the Rights in  * Technical Data and Computer Software clause in DFARS 252.227-7013.  *   *                          Hewlett-Packard Company  *                          3000 Hanover Street  *                          Palo Alto, CA 94304 U.S.A.  *   * Rights for non-DOD U.S. Government Departments and Agencies are as set  * forth in FAR 52.227-19(c)(1,2).  *  *************************************************************************/
end_comment

begin_comment
comment|/*'''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''' Copyright (c) 1988 by Hewlett-Packard Company Copyright (c) 1987, 1988 by Digital Equipment Corporation, Maynard,                Massachusetts, and the Massachusetts Institute of Technology,                Cambridge, Massachusetts  Permission to use, copy, modify, and distribute this software  and its documentation for any purpose and without fee is hereby  granted, provided that the above copyright notice appear in all  copies and that both that copyright notice and this permission  notice appear in supporting documentation, and that the names of  Hewlett-Packard, Digital or  M.I.T.  not be used in advertising or  publicity pertaining to distribution of the software without specific,  written prior permission.  DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE. '''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''*/
end_comment

begin_include
include|#
directive|include
file|"hpext.h"
end_include

begin_include
include|#
directive|include
file|"hildef.h"
end_include

begin_include
include|#
directive|include
file|"scrnintstr.h"
end_include

begin_include
include|#
directive|include
file|"cursorstr.h"
end_include

begin_include
include|#
directive|include
file|"regionstr.h"
end_include

begin_include
include|#
directive|include
file|"inputstr.h"
end_include

begin_include
include|#
directive|include
file|"opaque.h"
end_include

begin_include
include|#
directive|include
file|"hppriv.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|hpActiveScreen
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stacked mode,>1 head */
end_comment

begin_decl_stmt
specifier|extern
name|WindowPtr
modifier|*
name|WindowTable
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Defined by DIX */
end_comment

begin_decl_stmt
specifier|static
name|BoxRec
name|LimitTheCursor
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|CursorPtr
name|currentCursors
index|[
name|MAXSCREENS
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|hpBlottoCursors
parameter_list|()
block|{
name|int
name|j
decl_stmt|;
for|for
control|(
name|j
operator|=
name|MAXSCREENS
init|;
name|j
operator|--
condition|;
control|)
name|currentCursors
index|[
name|j
index|]
operator|=
name|NULL
expr_stmt|;
block|}
end_function

begin_comment
comment|/************************************************************  * hpConstrainCursor  *  * This function simply sets the box to which the cursor   * is limited.    *   * ASSUMPTION:  a single BoxRec is used for recording  * the cursor limits, instead of one per screen.  This is   * done, in part, because the bogus hpConstrainXY routine  * (see below) is not passed a pScreen pointer.  *  * THEREFORE:  Zaphod mode code will have to call this routine  * to establish new limits when the cursor leaves one screen  * for another.  *  ************************************************************/
end_comment

begin_function
name|void
name|hpConstrainCursor
parameter_list|(
name|pScreen
parameter_list|,
name|pBox
parameter_list|)
name|ScreenPtr
name|pScreen
decl_stmt|;
comment|/* Screen to which it should be constrained */
name|BoxPtr
name|pBox
decl_stmt|;
comment|/* Box in which... */
block|{
name|LimitTheCursor
operator|=
operator|*
name|pBox
expr_stmt|;
block|}
end_function

begin_comment
comment|/************************************************************  * hpConstrainXY  *  * This function is called directly from x_hil.c  * It adjusts the cursor position to fit within the current   * constraints.  *  ************************************************************/
end_comment

begin_function
name|Bool
name|hpConstrainXY
parameter_list|(
name|px
parameter_list|,
name|py
parameter_list|)
name|int
modifier|*
name|px
decl_stmt|,
decl|*
name|py
decl_stmt|;
end_function

begin_block
block|{
operator|*
name|px
operator|=
name|max
argument_list|(
name|LimitTheCursor
operator|.
name|x1
argument_list|,
name|min
argument_list|(
name|LimitTheCursor
operator|.
name|x2
argument_list|,
operator|*
name|px
argument_list|)
argument_list|)
expr_stmt|;
operator|*
name|py
operator|=
name|max
argument_list|(
name|LimitTheCursor
operator|.
name|y1
argument_list|,
name|min
argument_list|(
name|LimitTheCursor
operator|.
name|y2
argument_list|,
operator|*
name|py
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|TRUE
return|;
block|}
end_block

begin_comment
comment|/************************************************************  * hpCursorLimits  *      Return a box within which the given cursor may move on the given  *      screen. We assume that the HotBox is actually on the given screen,  *      since dix knows that size.  *  * Results:  *      A box for the hot spot corner of the cursor.  ************************************************************/
end_comment

begin_function
name|void
name|hpCursorLimits
parameter_list|(
name|pScreen
parameter_list|,
name|pCursor
parameter_list|,
name|pHotBox
parameter_list|,
name|pResultBox
parameter_list|)
name|ScreenPtr
name|pScreen
decl_stmt|;
comment|/* Screen on which limits are desired */
name|CursorPtr
name|pCursor
decl_stmt|;
comment|/* Cursor whose limits are desired */
name|BoxPtr
name|pHotBox
decl_stmt|;
comment|/* Limits for pCursor's hot point */
name|BoxPtr
name|pResultBox
decl_stmt|;
comment|/* RETURN: limits for hot spot */
block|{
operator|*
name|pResultBox
operator|=
operator|*
name|pHotBox
expr_stmt|;
name|pResultBox
operator|->
name|x2
operator|=
name|min
argument_list|(
name|pResultBox
operator|->
name|x2
argument_list|,
name|pScreen
operator|->
name|width
argument_list|)
expr_stmt|;
name|pResultBox
operator|->
name|y2
operator|=
name|min
argument_list|(
name|pResultBox
operator|->
name|y2
argument_list|,
name|pScreen
operator|->
name|height
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/************************************************************  * hpSetCursorPosition  ************************************************************/
end_comment

begin_function
name|Bool
name|hpSetCursorPosition
parameter_list|(
name|pScreen
parameter_list|,
name|xhot
parameter_list|,
name|yhot
parameter_list|,
name|generateEvent
parameter_list|)
name|ScreenPtr
name|pScreen
decl_stmt|;
name|short
name|xhot
decl_stmt|;
name|short
name|yhot
decl_stmt|;
name|Bool
name|generateEvent
decl_stmt|;
block|{
name|HPInputDevice
modifier|*
name|InDev
decl_stmt|;
comment|/* Input device structure */
name|hpPrivScreenPtr
name|php
decl_stmt|;
comment|/* XOS private structure */
name|php
operator|=
operator|(
name|hpPrivScreenPtr
operator|)
name|pScreen
operator|->
name|devPrivate
expr_stmt|;
comment|/* Check to see if we've switched screens: */
name|InDev
operator|=
name|GET_HPINPUTDEVICE
argument_list|(
operator|(
name|DeviceIntPtr
operator|)
name|LookupPointerDevice
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|pScreen
operator|!=
name|InDev
operator|->
name|pScreen
condition|)
block|{
name|WindowPtr
name|pRootWindow
init|=
name|WindowTable
index|[
name|InDev
operator|->
name|pScreen
operator|->
name|myNum
index|]
decl_stmt|;
comment|/*         ********************************************************************         ** Turn old cursor off, blank/unblank screens for stacked mode,         ** let DIX know there is a new screen, set the input driver variable         ** to the new screen number.         ********************************************************************         */
operator|(
operator|*
operator|(
call|(
name|hpPrivScreenPtr
call|)
argument_list|(
name|InDev
operator|->
name|pScreen
operator|->
name|devPrivate
argument_list|)
operator|)
operator|->
name|CursorOff
operator|)
operator|(
name|InDev
operator|->
name|pScreen
operator|)
expr_stmt|;
comment|/* Old cursor off */
name|php
operator|->
name|ChangeScreen
argument_list|(
name|pScreen
argument_list|)
expr_stmt|;
comment|/* Stacked mode switch */
name|NewCurrentScreen
argument_list|(
name|pScreen
argument_list|,
name|xhot
argument_list|,
name|yhot
argument_list|)
expr_stmt|;
comment|/* Let DIX know */
name|hpActiveScreen
operator|=
name|pScreen
operator|->
name|myNum
expr_stmt|;
comment|/* Input driver global */
block|}
comment|/* Must Update the Corvallis Input Driver's Variables: */
name|InDev
operator|->
name|pScreen
operator|=
name|pScreen
expr_stmt|;
name|InDev
operator|->
name|coords
index|[
literal|0
index|]
operator|=
name|xhot
expr_stmt|;
name|InDev
operator|->
name|coords
index|[
literal|1
index|]
operator|=
name|yhot
expr_stmt|;
if|if
condition|(
operator|!
name|generateEvent
condition|)
block|{
call|(
modifier|*
name|php
operator|->
name|MoveMouse
call|)
argument_list|(
name|pScreen
argument_list|,
name|xhot
argument_list|,
name|yhot
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* Do the move now */
block|}
else|else
block|{
name|queue_motion_event
argument_list|(
name|InDev
argument_list|)
expr_stmt|;
comment|/* Enqueue motion event, in x_hil.c */
name|isItTimeToYield
operator|++
expr_stmt|;
comment|/* Insures client get the event! */
block|}
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
end_function

end_unit

