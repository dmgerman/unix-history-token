begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2001,2006 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_comment
comment|/* **	lib_mvwin.c ** **	The routine mvwin(). ** */
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_mvwin.c,v 1.14 2006/02/25 22:53:46 tom Exp $"
argument_list|)
end_macro

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|int
argument_list|)
end_macro

begin_macro
name|mvwin
argument_list|(
argument|WINDOW *win
argument_list|,
argument|int by
argument_list|,
argument|int bx
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
name|T_CALLED
argument_list|(
literal|"mvwin(%p,%d,%d)"
argument_list|)
operator|,
name|win
operator|,
name|by
operator|,
name|bx
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|win
operator|||
operator|(
name|win
operator|->
name|_flags
operator|&
name|_ISPAD
operator|)
condition|)
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
comment|/*      * mvwin() should only modify the indices.  See test/demo_menus.c and      * test/movewindow.c for examples.      */
if|#
directive|if
literal|0
comment|/* Copying subwindows is allowed, but it is expensive... */
block|if (win->_flags& _SUBWIN) { 	int err = ERR; 	WINDOW *parent = win->_parent; 	if (parent) {
comment|/* Now comes the complicated and costly part, you should really 				 * try to avoid to move subwindows. Because a subwindow shares 				 * the text buffers with its parent, one can't do a simple 				 * memmove of the text buffers. One has to create a copy, then 				 * to relocate the subwindow and then to do a copy. 				 */
block|if ((by - parent->_begy == win->_pary)&& 		(bx - parent->_begx == win->_parx)) 		err = OK;
comment|/* we don't actually move */
block|else { 		WINDOW *clone = dupwin(win); 		if (clone) {
comment|/* now we have the clone, so relocate win */
block|werase(win);
comment|/* Erase the original place     */
comment|/* fill with parents background */
block|wbkgrnd(win, CHREF(parent->_nc_bkgd)); 		    wsyncup(win);
comment|/* Tell the parent(s)           */
block|err = mvderwin(win, 				   by - parent->_begy, 				   bx - parent->_begx); 		    if (err != ERR) { 			err = copywin(clone, win, 				      0, 0, 0, 0, win->_maxy, win->_maxx, 0); 			if (ERR != err) 			    wsyncup(win); 		    } 		    if (ERR == delwin(clone)) 			err = ERR; 		} 	    } 	} 	returnCode(err);     }
endif|#
directive|endif
if|if
condition|(
name|by
operator|+
name|win
operator|->
name|_maxy
operator|>
name|screen_lines
operator|-
literal|1
operator|||
name|bx
operator|+
name|win
operator|->
name|_maxx
operator|>
name|screen_columns
operator|-
literal|1
operator|||
name|by
operator|<
literal|0
operator|||
name|bx
operator|<
literal|0
condition|)
name|returnCode
argument_list|(
name|ERR
argument_list|)
expr_stmt|;
comment|/*      * Whether or not the window is moved, touch the window's contents so      * that a following call to 'wrefresh()' will paint the window at the      * new location.  This ensures that if the caller has refreshed another      * window at the same location, that this one will be displayed.      */
name|win
operator|->
name|_begy
operator|=
name|by
expr_stmt|;
name|win
operator|->
name|_begx
operator|=
name|bx
expr_stmt|;
name|returnCode
argument_list|(
name|touchwin
argument_list|(
name|win
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

