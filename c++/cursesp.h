begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// * This makes emacs happy -*-Mode: C++;-*-
end_comment

begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2008,2012 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author: Juergen Pfeifer, 1997                                          *  ****************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NCURSES_CURSESP_H_incl
end_ifndef

begin_define
define|#
directive|define
name|NCURSES_CURSESP_H_incl
value|1
end_define

begin_comment
comment|// $Id: cursesp.h,v 1.30 2012/12/29 21:50:55 tom Exp $
end_comment

begin_include
include|#
directive|include
file|<cursesw.h>
end_include

begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|<panel.h>
block|}
end_extern

begin_decl_stmt
name|class
name|NCURSES_IMPEXP
name|NCursesPanel
range|:
name|public
name|NCursesWindow
block|{
name|protected
operator|:
name|PANEL
operator|*
name|p
block|;
specifier|static
name|NCursesPanel
operator|*
name|dummy
block|;
name|private
operator|:
comment|// This structure is used for the panel's user data field to link the
comment|// PANEL* to the C++ object and to provide extra space for a user pointer.
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|m_user
decl_stmt|;
comment|// the pointer for the user's data
specifier|const
name|NCursesPanel
modifier|*
name|m_back
decl_stmt|;
comment|// backward pointer to C++ object
specifier|const
name|PANEL
modifier|*
name|m_owner
decl_stmt|;
comment|// the panel itself
block|}
name|UserHook
expr_stmt|;
specifier|inline
name|UserHook
operator|*
name|UserPointer
argument_list|()
block|{
name|UserHook
operator|*
name|uptr
operator|=
name|reinterpret_cast
operator|<
name|UserHook
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|::
name|panel_userptr
argument_list|(
name|p
argument_list|)
operator|)
operator|)
block|;
return|return
name|uptr
return|;
block|}
name|void
name|init
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Initialize the panel object
end_comment

begin_label
name|protected
label|:
end_label

begin_function
name|void
name|set_user
parameter_list|(
name|void
modifier|*
name|user
parameter_list|)
block|{
name|UserHook
modifier|*
name|uptr
init|=
name|UserPointer
argument_list|()
decl_stmt|;
if|if
condition|(
name|uptr
operator|!=
literal|0
operator|&&
name|uptr
operator|->
name|m_back
operator|==
name|this
operator|&&
name|uptr
operator|->
name|m_owner
operator|==
name|p
condition|)
block|{
name|uptr
operator|->
name|m_user
operator|=
name|user
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// Set the user pointer of the panel.
end_comment

begin_function
name|void
modifier|*
name|get_user
parameter_list|()
block|{
name|UserHook
modifier|*
name|uptr
init|=
name|UserPointer
argument_list|()
decl_stmt|;
name|void
modifier|*
name|result
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|uptr
operator|!=
literal|0
operator|&&
name|uptr
operator|->
name|m_back
operator|==
name|this
operator|&&
name|uptr
operator|->
name|m_owner
operator|==
name|p
condition|)
name|result
operator|=
name|uptr
operator|->
name|m_user
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_decl_stmt
name|void
name|OnError
argument_list|(
name|int
name|err
argument_list|)
decl|const
name|THROW2
argument_list|(
name|NCursesException
specifier|const
argument_list|,
name|NCursesPanelException
argument_list|)
block|{
if|if
condition|(
name|err
operator|==
name|ERR
condition|)
name|THROW
argument_list|(
argument|new NCursesPanelException (this, err)
argument_list|)
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// If err is equal to the curses error indicator ERR, an error handler
end_comment

begin_comment
comment|// is called.
end_comment

begin_comment
comment|// Get a keystroke. Default implementation calls getch()
end_comment

begin_function_decl
name|virtual
name|int
name|getKey
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_macro
name|NCursesPanel
argument_list|(
argument|int nlines
argument_list|,
argument|int ncols
argument_list|,
argument|int begin_y =
literal|0
argument_list|,
argument|int begin_x =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|NCursesWindow
argument_list|(
name|nlines
argument_list|,
name|ncols
argument_list|,
name|begin_y
argument_list|,
name|begin_x
argument_list|)
operator|,
name|p
argument_list|(
literal|0
argument_list|)
block|{
name|init
argument_list|()
block|;   }
comment|// Create a panel with this size starting at the requested position.
name|NCursesPanel
argument_list|()
operator|:
name|NCursesWindow
argument_list|(
operator|::
name|stdscr
argument_list|)
operator|,
name|p
argument_list|(
literal|0
argument_list|)
block|{
name|init
argument_list|()
block|;   }
comment|// This constructor creates the default Panel associated with the
comment|// ::stdscr window
name|NCursesPanel
operator|&
name|operator
operator|=
operator|(
specifier|const
name|NCursesPanel
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|rhs
condition|)
block|{
operator|*
name|this
operator|=
name|rhs
expr_stmt|;
name|NCursesWindow
operator|::
name|operator
operator|=
operator|(
name|rhs
operator|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_expr_stmt
unit|}    NCursesPanel
operator|(
specifier|const
name|NCursesPanel
operator|&
name|rhs
operator|)
operator|:
name|NCursesWindow
argument_list|(
name|rhs
argument_list|)
operator|,
name|p
argument_list|(
argument|rhs.p
argument_list|)
block|{   }
name|virtual
operator|~
name|NCursesPanel
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// basic manipulation
end_comment

begin_function
specifier|inline
name|void
name|hide
parameter_list|()
block|{
name|OnError
argument_list|(
operator|::
name|hide_panel
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Hide the panel. It stays in the stack but becomes invisible.
end_comment

begin_function
specifier|inline
name|void
name|show
parameter_list|()
block|{
name|OnError
argument_list|(
operator|::
name|show_panel
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Show the panel, i.e. make it visible.
end_comment

begin_function
specifier|inline
name|void
name|top
parameter_list|()
block|{
name|OnError
argument_list|(
operator|::
name|top_panel
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Make this panel the top panel in the stack.
end_comment

begin_function
specifier|inline
name|void
name|bottom
parameter_list|()
block|{
name|OnError
argument_list|(
operator|::
name|bottom_panel
argument_list|(
name|p
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Make this panel the bottom panel in the stack.
end_comment

begin_comment
comment|// N.B.: The panel associated with ::stdscr is always on the bottom. So
end_comment

begin_comment
comment|// actually bottom() makes the panel the first above ::stdscr.
end_comment

begin_function
name|virtual
name|int
name|mvwin
parameter_list|(
name|int
name|y
parameter_list|,
name|int
name|x
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|move_panel
argument_list|(
name|p
argument_list|,
name|y
argument_list|,
name|x
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|OK
return|;
block|}
end_function

begin_expr_stmt
specifier|inline
name|bool
name|hidden
argument_list|()
specifier|const
block|{
return|return
operator|(
operator|::
name|panel_hidden
argument_list|(
name|p
argument_list|)
operator|?
name|TRUE
operator|:
name|FALSE
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Return TRUE if the panel is hidden, FALSE otherwise.
end_comment

begin_comment
comment|/* The functions panel_above() and panel_below() are not reflected in    the NCursesPanel class. The reason for this is, that we cannot    assume that a panel retrieved by those operations is one wrapped    by a C++ class. Although this situation might be handled, we also    need a reverse mapping from PANEL to NCursesPanel which needs some    redesign of the low level stuff. At the moment, we define them in the    interface but they will always produce an error. */
end_comment

begin_expr_stmt
specifier|inline
name|NCursesPanel
operator|&
name|above
argument_list|()
specifier|const
block|{
name|OnError
argument_list|(
name|ERR
argument_list|)
block|;
return|return
operator|*
name|dummy
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|inline
name|NCursesPanel
operator|&
name|below
argument_list|()
specifier|const
block|{
name|OnError
argument_list|(
name|ERR
argument_list|)
block|;
return|return
operator|*
name|dummy
return|;
block|}
end_expr_stmt

begin_comment
comment|// Those two are rewrites of the corresponding virtual members of
end_comment

begin_comment
comment|// NCursesWindow
end_comment

begin_function_decl
name|virtual
name|int
name|refresh
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Propagate all panel changes to the virtual screen and update the
end_comment

begin_comment
comment|// physical screen.
end_comment

begin_function_decl
name|virtual
name|int
name|noutrefresh
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Propagate all panel changes to the virtual screen.
end_comment

begin_function_decl
specifier|static
name|void
name|redraw
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Redraw all panels.
end_comment

begin_comment
comment|// decorations
end_comment

begin_function_decl
name|virtual
name|void
name|frame
parameter_list|(
specifier|const
name|char
modifier|*
name|title
init|=
name|NULL
parameter_list|,
specifier|const
name|char
modifier|*
name|btitle
init|=
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Put a frame around the panel and put the title centered in the top line
end_comment

begin_comment
comment|// and btitle in the bottom line.
end_comment

begin_function_decl
name|virtual
name|void
name|boldframe
parameter_list|(
specifier|const
name|char
modifier|*
name|title
init|=
name|NULL
parameter_list|,
specifier|const
name|char
modifier|*
name|btitle
init|=
name|NULL
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Same as frame(), but use highlighted attributes.
end_comment

begin_function_decl
name|virtual
name|void
name|label
parameter_list|(
specifier|const
name|char
modifier|*
name|topLabel
parameter_list|,
specifier|const
name|char
modifier|*
name|bottomLabel
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Put the title centered in the top line and btitle in the bottom line.
end_comment

begin_function_decl
name|virtual
name|void
name|centertext
parameter_list|(
name|int
name|row
parameter_list|,
specifier|const
name|char
modifier|*
name|label
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Put the label text centered in the specified row.
end_comment

begin_comment
unit|};
comment|/* We use templates to provide a typesafe mechanism to associate  * user data with a panel. A NCursesUserPanel<T> is a panel  * associated with some user data of type T.  */
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|NCursesUserPanel
operator|:
name|public
name|NCursesPanel
block|{
name|public
operator|:
name|NCursesUserPanel
argument_list|(
argument|int nlines
argument_list|,
argument|int ncols
argument_list|,
argument|int begin_y =
literal|0
argument_list|,
argument|int begin_x =
literal|0
argument_list|,
argument|const T* p_UserData = STATIC_CAST(T*)(
literal|0
argument|)
argument_list|)
operator|:
name|NCursesPanel
argument_list|(
argument|nlines
argument_list|,
argument|ncols
argument_list|,
argument|begin_y
argument_list|,
argument|begin_x
argument_list|)
block|{
if|if
condition|(
name|p
condition|)
name|set_user
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|p_UserData
operator|)
argument_list|)
expr_stmt|;
block|}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This creates an user panel of the requested size with associated
end_comment

begin_comment
comment|// user data pointed to by p_UserData.
end_comment

begin_expr_stmt
name|NCursesUserPanel
argument_list|(
specifier|const
name|T
operator|*
name|p_UserData
operator|=
name|STATIC_CAST
argument_list|(
name|T
operator|*
argument_list|)
argument_list|(
literal|0
argument_list|)
argument_list|)
operator|:
name|NCursesPanel
argument_list|()
block|{
if|if
condition|(
name|p
condition|)
name|set_user
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|p_UserData
operator|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// This creates an user panel associated with the ::stdscr and user data
end_comment

begin_comment
comment|// pointed to by p_UserData.
end_comment

begin_expr_stmt
name|virtual
operator|~
name|NCursesUserPanel
argument_list|()
block|{}
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|T
modifier|*
name|UserData
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|get_user
argument_list|()
operator|)
return|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Retrieve the user data associated with the panel.
end_comment

begin_function
name|virtual
name|void
name|setUserData
parameter_list|(
specifier|const
name|T
modifier|*
name|p_UserData
parameter_list|)
block|{
if|if
condition|(
name|p
condition|)
name|set_user
argument_list|(
name|const_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|p_UserData
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Associate the user panel with the user data pointed to by p_UserData.
end_comment

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCURSES_CURSESP_H_incl */
end_comment

end_unit

