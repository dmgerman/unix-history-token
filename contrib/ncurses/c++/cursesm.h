begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// * This makes emacs happy -*-Mode: C++;-*-
end_comment

begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,1999 Free Software Foundation, Inc.                   *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author: Juergen Pfeifer<juergen.pfeifer@gmx.net> 1997                 *  ****************************************************************************/
end_comment

begin_comment
comment|// $Id: cursesm.h,v 1.13 1999/10/30 23:59:37 tom Exp $
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CURSESM_H
end_ifndef

begin_define
define|#
directive|define
name|_CURSESM_H
end_define

begin_include
include|#
directive|include
file|<cursesp.h>
end_include

begin_extern
extern|extern
literal|"C"
block|{
include|#
directive|include
file|<menu.h>
block|}
end_extern

begin_comment
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// This wraps the ITEM type of<menu.h>
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|NCursesMenuItem
block|{
name|friend
name|class
name|NCursesMenu
decl_stmt|;
name|protected
label|:
name|ITEM
modifier|*
name|item
decl_stmt|;
specifier|inline
name|void
name|OnError
argument_list|(
name|int
name|err
argument_list|)
decl|const
name|THROWS
argument_list|(
name|NCursesMenuException
argument_list|)
block|{
if|if
condition|(
name|err
operator|!=
name|E_OK
condition|)
name|THROW
argument_list|(
argument|new NCursesMenuException (err)
argument_list|)
empty_stmt|;
block|}
name|public
label|:
name|NCursesMenuItem
argument_list|(
argument|const char* p_name     = NULL
argument_list|,
argument|const char* p_descript = NULL
argument_list|)
block|{
name|item
operator|=
name|p_name
condition|?
operator|::
name|new_item
argument_list|(
name|p_name
argument_list|,
name|p_descript
argument_list|)
else|:
operator|(
name|ITEM
operator|*
operator|)
literal|0
expr_stmt|;
if|if
condition|(
name|p_name
operator|&&
operator|!
name|item
condition|)
name|OnError
argument_list|(
name|E_SYSTEM_ERROR
argument_list|)
expr_stmt|;
block|}
comment|// Create an item. If you pass both parameters as NULL, a delimiting
comment|// item is constructed which can be used to terminate a list of
comment|// NCursesMenu objects.
name|virtual
operator|~
name|NCursesMenuItem
argument_list|()
expr_stmt|;
comment|// Release the items memory
specifier|inline
specifier|const
name|char
operator|*
name|name
argument_list|()
specifier|const
block|{
return|return
operator|::
name|item_name
argument_list|(
name|item
argument_list|)
return|;
block|}
comment|// Name of the item
specifier|inline
specifier|const
name|char
operator|*
name|description
argument_list|()
specifier|const
block|{
return|return
operator|::
name|item_description
argument_list|(
name|item
argument_list|)
return|;
block|}
comment|// Description of the item
specifier|inline
name|int
argument_list|(
argument|index
argument_list|)
operator|(
name|void
operator|)
specifier|const
block|{
return|return
operator|::
name|item_index
argument_list|(
name|item
argument_list|)
return|;
block|}
comment|// Index of the item in an item array (or -1)
specifier|inline
name|void
name|options_on
parameter_list|(
name|Item_Options
name|options
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|item_opts_on
argument_list|(
name|item
argument_list|,
name|options
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Switch on the items options
specifier|inline
name|void
name|options_off
parameter_list|(
name|Item_Options
name|options
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|item_opts_off
argument_list|(
name|item
argument_list|,
name|options
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Switch off the item's option
specifier|inline
name|Item_Options
name|options
argument_list|()
specifier|const
block|{
return|return
operator|::
name|item_opts
argument_list|(
name|item
argument_list|)
return|;
block|}
comment|// Retrieve the items options
specifier|inline
name|void
name|set_options
parameter_list|(
name|Item_Options
name|options
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_item_opts
argument_list|(
name|item
argument_list|,
name|options
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Set the items options
specifier|inline
name|void
name|set_value
parameter_list|(
name|bool
name|f
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_item_value
argument_list|(
name|item
argument_list|,
name|f
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// Set/Reset the items selection state
specifier|inline
name|bool
name|value
argument_list|()
specifier|const
block|{
return|return
operator|::
name|item_value
argument_list|(
name|item
argument_list|)
return|;
block|}
comment|// Retrieve the items selection state
specifier|inline
name|bool
name|visible
argument_list|()
specifier|const
block|{
return|return
operator|::
name|item_visible
argument_list|(
name|item
argument_list|)
return|;
block|}
comment|// Retrieve visibility of the item
name|virtual
name|bool
name|action
parameter_list|()
function_decl|;
comment|// Perform an action associated with this item; you may use this in an
comment|// user supplied driver for a menu; you may derive from this class and
comment|// overload action() to supply items with different actions.
comment|// If an action returns true, the menu will be exited. The default action
comment|// is to do nothing.
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Prototype for an items callback function.
end_comment

begin_typedef
typedef|typedef
name|bool
name|ITEMCALLBACK
parameter_list|(
name|NCursesMenuItem
modifier|&
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// If you don't like to create a child class for individual items to
end_comment

begin_comment
comment|// overload action(), you may use this class and provide a callback
end_comment

begin_comment
comment|// function pointer for items.
end_comment

begin_decl_stmt
name|class
name|NCursesMenuCallbackItem
range|:
name|public
name|NCursesMenuItem
block|{
name|private
operator|:
name|ITEMCALLBACK
operator|*
name|p_fct
block|;
name|public
operator|:
name|NCursesMenuCallbackItem
argument_list|(
name|ITEMCALLBACK
operator|*
name|fct
operator|=
name|NULL
argument_list|,
specifier|const
name|char
operator|*
name|p_name
operator|=
name|NULL
argument_list|,
specifier|const
name|char
operator|*
name|p_descript
operator|=
name|NULL
argument_list|)
operator|:
name|NCursesMenuItem
argument_list|(
name|p_name
argument_list|,
name|p_descript
argument_list|)
block|,
name|p_fct
argument_list|(
argument|fct
argument_list|)
block|{   }
name|virtual
operator|~
name|NCursesMenuCallbackItem
argument_list|()
block|;
name|bool
name|action
argument_list|()
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// This wraps the MENU type of<menu.h>
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_decl_stmt
name|class
name|NCursesMenu
range|:
name|public
name|NCursesPanel
block|{
name|protected
operator|:
name|MENU
operator|*
name|menu
block|;
name|private
operator|:
name|NCursesWindow
operator|*
name|sub
block|;
comment|// the subwindow object
name|bool
name|b_sub_owner
block|;
comment|// is this our own subwindow?
name|bool
name|b_framed
block|;
comment|// has the menu a border?
name|bool
name|b_autoDelete
block|;
comment|// Delete items when deleting menu?
name|NCursesMenuItem
operator|*
operator|*
name|my_items
block|;
comment|// The array of items for this menu
comment|// This structure is used for the menu's user data field to link the
comment|// MENU* to the C++ object and to provide extra space for a user pointer.
typedef|typedef
struct|struct
block|{
name|void
modifier|*
name|m_user
decl_stmt|;
comment|// the pointer for the user's data
specifier|const
name|NCursesMenu
modifier|*
name|m_back
decl_stmt|;
comment|// backward pointer to C++ object
specifier|const
name|MENU
modifier|*
name|m_owner
decl_stmt|;
block|}
name|UserHook
expr_stmt|;
comment|// Get the backward pointer to the C++ object from a MENU
specifier|static
specifier|inline
name|NCursesMenu
operator|*
name|getHook
argument_list|(
argument|const MENU *m
argument_list|)
block|{
name|UserHook
operator|*
name|hook
operator|=
operator|(
name|UserHook
operator|*
operator|)
operator|::
name|menu_userptr
argument_list|(
name|m
argument_list|)
block|;
name|assert
argument_list|(
name|hook
operator|!=
literal|0
operator|&&
name|hook
operator|->
name|m_owner
operator|==
name|m
argument_list|)
block|;
return|return
operator|(
name|NCursesMenu
operator|*
operator|)
operator|(
name|hook
operator|->
name|m_back
operator|)
return|;
block|}
comment|// This are the built-in hook functions in this C++ binding. In C++ we use
comment|// virtual member functions (see below On_..._Init and On_..._Termination)
comment|// to provide this functionality in an object oriented manner.
specifier|static
name|void
name|mnu_init
argument_list|(
name|MENU
operator|*
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|static
name|void
name|mnu_term
parameter_list|(
name|MENU
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|itm_init
parameter_list|(
name|MENU
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|itm_term
parameter_list|(
name|MENU
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Calculate ITEM* array for the menu
end_comment

begin_function_decl
name|ITEM
modifier|*
modifier|*
name|mapItems
parameter_list|(
name|NCursesMenuItem
modifier|*
name|nitems
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_comment
comment|// internal routines
end_comment

begin_function
specifier|inline
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
operator|(
name|UserHook
operator|*
operator|)
operator|::
name|menu_userptr
argument_list|(
name|menu
argument_list|)
decl_stmt|;
name|assert
argument_list|(
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
name|menu
argument_list|)
expr_stmt|;
name|uptr
operator|->
name|m_user
operator|=
name|user
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
modifier|*
name|get_user
parameter_list|()
block|{
name|UserHook
modifier|*
name|uptr
init|=
operator|(
name|UserHook
operator|*
operator|)
operator|::
name|menu_userptr
argument_list|(
name|menu
argument_list|)
decl_stmt|;
name|assert
argument_list|(
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
name|menu
argument_list|)
expr_stmt|;
return|return
name|uptr
operator|->
name|m_user
return|;
block|}
end_function

begin_function_decl
name|void
name|InitMenu
parameter_list|(
name|NCursesMenuItem
modifier|*
name|menu
index|[]
parameter_list|,
name|bool
name|with_frame
parameter_list|,
name|bool
name|autoDeleteItems
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|inline
name|void
name|OnError
argument_list|(
name|int
name|err
argument_list|)
decl|const
name|THROWS
argument_list|(
name|NCursesMenuException
argument_list|)
block|{
if|if
condition|(
name|err
operator|!=
name|E_OK
condition|)
name|THROW
argument_list|(
argument|new NCursesMenuException (this, err)
argument_list|)
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// this wraps the menu_driver call.
end_comment

begin_function_decl
name|virtual
name|int
name|driver
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// 'Internal' constructor to create a menu without association to
end_comment

begin_comment
comment|// an array of items.
end_comment

begin_macro
name|NCursesMenu
argument_list|(
argument|int  lines
argument_list|,
argument|int  cols
argument_list|,
argument|int  begin_y =
literal|0
argument_list|,
argument|int  begin_x =
literal|0
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|NCursesPanel
argument_list|(
name|lines
argument_list|,
name|cols
argument_list|,
name|begin_y
argument_list|,
name|begin_x
argument_list|)
operator|,
name|menu
argument_list|(
argument|(MENU*)
literal|0
argument_list|)
block|{   }
name|public
operator|:
comment|// Make a full window size menu
name|NCursesMenu
argument_list|(
argument|NCursesMenuItem* Items[]
argument_list|,
argument|bool with_frame=FALSE
argument_list|,
comment|// Reserve space for a frame?
argument|bool autoDelete_Items=FALSE
argument_list|)
comment|// Autocleanup of Items?
operator|:
name|NCursesPanel
argument_list|()
block|{
name|InitMenu
argument_list|(
name|Items
argument_list|,
name|with_frame
argument_list|,
name|autoDelete_Items
argument_list|)
block|;   }
comment|// Make a menu with a window of this size.
name|NCursesMenu
argument_list|(
argument|NCursesMenuItem* Items[]
argument_list|,
argument|int  lines
argument_list|,
argument|int  cols
argument_list|,
argument|int  begin_y =
literal|0
argument_list|,
argument|int  begin_x =
literal|0
argument_list|,
argument|bool with_frame=FALSE
argument_list|,
comment|// Reserve space for a frame?
argument|bool autoDelete_Items=FALSE
argument_list|)
comment|// Autocleanup of Items?
operator|:
name|NCursesPanel
argument_list|(
argument|lines
argument_list|,
argument|cols
argument_list|,
argument|begin_y
argument_list|,
argument|begin_x
argument_list|)
block|{
name|InitMenu
argument_list|(
name|Items
argument_list|,
name|with_frame
argument_list|,
name|autoDelete_Items
argument_list|)
block|;   }
name|virtual
operator|~
name|NCursesMenu
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Retrieve the menus subwindow
end_comment

begin_expr_stmt
specifier|inline
name|NCursesWindow
operator|&
name|subWindow
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|sub
operator|!=
name|NULL
argument_list|)
block|;
return|return
operator|*
name|sub
return|;
block|}
end_expr_stmt

begin_comment
comment|// Set the menus subwindow
end_comment

begin_function_decl
name|void
name|setSubWindow
parameter_list|(
name|NCursesWindow
modifier|&
name|sub
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Set these items for the menu
end_comment

begin_function
specifier|inline
name|void
name|setItems
parameter_list|(
name|NCursesMenuItem
modifier|*
name|Items
index|[]
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_menu_items
argument_list|(
name|menu
argument_list|,
name|mapItems
argument_list|(
name|Items
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Remove the menu from the screen
end_comment

begin_function
specifier|inline
name|void
name|unpost
parameter_list|(
name|void
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|unpost_menu
argument_list|(
name|menu
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Post the menu to the screen if flag is true, unpost it otherwise
end_comment

begin_function
specifier|inline
name|void
name|post
parameter_list|(
name|bool
name|flag
init|=
name|TRUE
parameter_list|)
block|{
name|flag
condition|?
name|OnError
argument_list|(
operator|::
name|post_menu
argument_list|(
name|menu
argument_list|)
argument_list|)
else|:
name|OnError
argument_list|(
operator|::
name|unpost_menu
argument_list|(
name|menu
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Get the numer of rows and columns for this menu
end_comment

begin_decl_stmt
specifier|inline
name|void
name|scale
argument_list|(
name|int
operator|&
name|mrows
argument_list|,
name|int
operator|&
name|mcols
argument_list|)
decl|const
block|{
name|OnError
argument_list|(
operator|::
name|scale_menu
argument_list|(
name|menu
argument_list|,
operator|&
name|mrows
argument_list|,
operator|&
name|mcols
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Set the format of this menu
end_comment

begin_function
specifier|inline
name|void
name|set_format
parameter_list|(
name|int
name|mrows
parameter_list|,
name|int
name|mcols
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_menu_format
argument_list|(
name|menu
argument_list|,
name|mrows
argument_list|,
name|mcols
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Get the format of this menu
end_comment

begin_function
specifier|inline
name|void
name|menu_format
parameter_list|(
name|int
modifier|&
name|rows
parameter_list|,
name|int
modifier|&
name|cols
parameter_list|)
block|{
operator|::
name|menu_format
argument_list|(
name|menu
argument_list|,
operator|&
name|rows
argument_list|,
operator|&
name|cols
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Items of the menu
end_comment

begin_expr_stmt
specifier|inline
name|NCursesMenuItem
operator|*
name|items
argument_list|()
specifier|const
block|{
return|return
operator|*
name|my_items
return|;
block|}
end_expr_stmt

begin_comment
comment|// Get the number of items in this menu
end_comment

begin_expr_stmt
specifier|inline
name|int
name|count
argument_list|()
specifier|const
block|{
return|return
operator|::
name|item_count
argument_list|(
name|menu
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Get the current item (i.e. the one the cursor is located)
end_comment

begin_expr_stmt
specifier|inline
name|NCursesMenuItem
operator|*
name|current_item
argument_list|()
specifier|const
block|{
return|return
name|my_items
index|[
operator|::
name|item_index
argument_list|(
operator|::
name|current_item
argument_list|(
name|menu
argument_list|)
argument_list|)
index|]
return|;
block|}
end_expr_stmt

begin_comment
comment|// Get the marker string
end_comment

begin_expr_stmt
specifier|inline
specifier|const
name|char
operator|*
name|mark
argument_list|()
specifier|const
block|{
return|return
operator|::
name|menu_mark
argument_list|(
name|menu
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Set the marker string
end_comment

begin_function
specifier|inline
name|void
name|set_mark
parameter_list|(
specifier|const
name|char
modifier|*
name|mark
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_menu_mark
argument_list|(
name|menu
argument_list|,
name|mark
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Get the name of the request code c
end_comment

begin_function
specifier|inline
specifier|static
specifier|const
name|char
modifier|*
name|request_name
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
operator|::
name|menu_request_name
argument_list|(
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Get the current pattern
end_comment

begin_expr_stmt
specifier|inline
name|char
operator|*
name|pattern
argument_list|()
specifier|const
block|{
return|return
operator|::
name|menu_pattern
argument_list|(
name|menu
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// true if there is a pattern match, false otherwise.
end_comment

begin_function_decl
name|bool
name|set_pattern
parameter_list|(
specifier|const
name|char
modifier|*
name|pat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// set the default attributes for the menu
end_comment

begin_comment
comment|// i.e. set fore, back and grey attribute
end_comment

begin_function_decl
name|virtual
name|void
name|setDefaultAttributes
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Get the menus background attributes
end_comment

begin_expr_stmt
specifier|inline
name|chtype
name|back
argument_list|()
specifier|const
block|{
return|return
operator|::
name|menu_back
argument_list|(
name|menu
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Get the menus foreground attributes
end_comment

begin_expr_stmt
specifier|inline
name|chtype
name|fore
argument_list|()
specifier|const
block|{
return|return
operator|::
name|menu_fore
argument_list|(
name|menu
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Get the menus grey attributes (used for unselectable items)
end_comment

begin_expr_stmt
specifier|inline
name|chtype
name|grey
argument_list|()
specifier|const
block|{
return|return
operator|::
name|menu_grey
argument_list|(
name|menu
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Set the menus background attributes
end_comment

begin_function
specifier|inline
name|chtype
name|set_background
parameter_list|(
name|chtype
name|a
parameter_list|)
block|{
return|return
operator|::
name|set_menu_back
argument_list|(
name|menu
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Set the menus foreground attributes
end_comment

begin_function
specifier|inline
name|chtype
name|set_foreground
parameter_list|(
name|chtype
name|a
parameter_list|)
block|{
return|return
operator|::
name|set_menu_fore
argument_list|(
name|menu
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Set the menus grey attributes (used for unselectable items)
end_comment

begin_function
specifier|inline
name|chtype
name|set_grey
parameter_list|(
name|chtype
name|a
parameter_list|)
block|{
return|return
operator|::
name|set_menu_grey
argument_list|(
name|menu
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
specifier|inline
name|void
name|options_on
parameter_list|(
name|Menu_Options
name|opts
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|menu_opts_on
argument_list|(
name|menu
argument_list|,
name|opts
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
name|void
name|options_off
parameter_list|(
name|Menu_Options
name|opts
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|menu_opts_off
argument_list|(
name|menu
argument_list|,
name|opts
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|inline
name|Menu_Options
name|options
argument_list|()
specifier|const
block|{
return|return
operator|::
name|menu_opts
argument_list|(
name|menu
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|inline
name|void
name|set_options
parameter_list|(
name|Menu_Options
name|opts
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_menu_opts
argument_list|(
name|menu
argument_list|,
name|opts
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|inline
name|int
name|pad
argument_list|()
specifier|const
block|{
return|return
operator|::
name|menu_pad
argument_list|(
name|menu
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
specifier|inline
name|void
name|set_pad
parameter_list|(
name|int
name|padch
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_menu_pad
argument_list|(
name|menu
argument_list|,
name|padch
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Position the cursor to the current item
end_comment

begin_expr_stmt
specifier|inline
name|void
name|position_cursor
argument_list|()
specifier|const
block|{
name|OnError
argument_list|(
operator|::
name|pos_menu_cursor
argument_list|(
name|menu
argument_list|)
argument_list|)
block|;   }
comment|// Set the current item
specifier|inline
name|void
name|set_current
argument_list|(
argument|NCursesMenuItem& I
argument_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_current_item
argument_list|(
name|menu
argument_list|,
name|I
operator|.
name|item
argument_list|)
argument_list|)
block|;   }
comment|// Get the current top row of the menu
specifier|inline
name|int
name|top_row
argument_list|(
argument|void
argument_list|)
specifier|const
block|{
return|return
operator|::
name|top_row
argument_list|(
name|menu
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Set the current top row of the menu
end_comment

begin_function
specifier|inline
name|void
name|set_top_row
parameter_list|(
name|int
name|row
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_top_row
argument_list|(
name|menu
argument_list|,
name|row
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// spacing control
end_comment

begin_comment
comment|// Set the spacing for the menu
end_comment

begin_function
specifier|inline
name|void
name|setSpacing
parameter_list|(
name|int
name|spc_description
parameter_list|,
name|int
name|spc_rows
parameter_list|,
name|int
name|spc_columns
parameter_list|)
block|{
name|OnError
argument_list|(
operator|::
name|set_menu_spacing
argument_list|(
name|menu
argument_list|,
name|spc_description
argument_list|,
name|spc_rows
argument_list|,
name|spc_columns
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// Get the spacing info for the menu
end_comment

begin_decl_stmt
specifier|inline
name|void
name|Spacing
argument_list|(
name|int
operator|&
name|spc_description
argument_list|,
name|int
operator|&
name|spc_rows
argument_list|,
name|int
operator|&
name|spc_columns
argument_list|)
decl|const
block|{
name|OnError
argument_list|(
operator|::
name|menu_spacing
argument_list|(
name|menu
argument_list|,
operator|&
name|spc_description
argument_list|,
operator|&
name|spc_rows
argument_list|,
operator|&
name|spc_columns
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Decorations
end_comment

begin_function
specifier|inline
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
block|{
if|if
condition|(
name|b_framed
condition|)
name|NCursesPanel
operator|::
name|frame
argument_list|(
name|title
argument_list|,
name|btitle
argument_list|)
expr_stmt|;
else|else
name|OnError
argument_list|(
name|E_SYSTEM_ERROR
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
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
block|{
if|if
condition|(
name|b_framed
condition|)
name|NCursesPanel
operator|::
name|boldframe
argument_list|(
name|title
argument_list|,
name|btitle
argument_list|)
expr_stmt|;
else|else
name|OnError
argument_list|(
name|E_SYSTEM_ERROR
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|inline
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
block|{
if|if
condition|(
name|b_framed
condition|)
name|NCursesPanel
operator|::
name|label
argument_list|(
name|topLabel
argument_list|,
name|bottomLabel
argument_list|)
expr_stmt|;
else|else
name|OnError
argument_list|(
name|E_SYSTEM_ERROR
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// -----
end_comment

begin_comment
comment|// Hooks
end_comment

begin_comment
comment|// -----
end_comment

begin_comment
comment|// Called after the menu gets repositioned in its window.
end_comment

begin_comment
comment|// This is especially true if the menu is posted.
end_comment

begin_function_decl
name|virtual
name|void
name|On_Menu_Init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Called before the menu gets repositioned in its window.
end_comment

begin_comment
comment|// This is especially true if the menu is unposted.
end_comment

begin_function_decl
name|virtual
name|void
name|On_Menu_Termination
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// Called after the item became the current item
end_comment

begin_function_decl
name|virtual
name|void
name|On_Item_Init
parameter_list|(
name|NCursesMenuItem
modifier|&
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Called before this item is left as current item.
end_comment

begin_function_decl
name|virtual
name|void
name|On_Item_Termination
parameter_list|(
name|NCursesMenuItem
modifier|&
name|item
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Provide a default key virtualization. Translate the keyboard
end_comment

begin_comment
comment|// code c into a menu request code.
end_comment

begin_comment
comment|// The default implementation provides a hopefully straightforward
end_comment

begin_comment
comment|// mapping for the most common keystrokes and menu requests.
end_comment

begin_function_decl
name|virtual
name|int
name|virtualize
parameter_list|(
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Operators
end_comment

begin_decl_stmt
specifier|inline
name|NCursesMenuItem
modifier|*
name|operator
index|[]
argument_list|(
name|int
name|i
argument_list|)
decl|const
block|{
if|if
condition|(
operator|(
name|i
operator|<
literal|0
operator|)
operator|||
operator|(
name|i
operator|>=
operator|::
name|item_count
argument_list|(
name|menu
argument_list|)
operator|)
condition|)
name|OnError
argument_list|(
name|E_BAD_ARGUMENT
argument_list|)
expr_stmt|;
return|return
operator|(
name|my_items
index|[
name|i
index|]
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|// Perform the menu's operation
end_comment

begin_comment
comment|// Return the item where you left the selection mark for a single
end_comment

begin_comment
comment|// selection menu, or NULL for a multivalued menu.
end_comment

begin_expr_stmt
name|virtual
name|NCursesMenuItem
operator|*
name|operator
argument_list|()
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// --------------------
end_comment

begin_comment
comment|// Exception handlers
end_comment

begin_comment
comment|// Called by operator()
end_comment

begin_comment
comment|// --------------------
end_comment

begin_comment
comment|// Called if the request is denied
end_comment

begin_decl_stmt
name|virtual
name|void
name|On_Request_Denied
argument_list|(
name|int
name|c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Called if the item is not selectable
end_comment

begin_decl_stmt
name|virtual
name|void
name|On_Not_Selectable
argument_list|(
name|int
name|c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Called if pattern doesn't match
end_comment

begin_decl_stmt
name|virtual
name|void
name|On_No_Match
argument_list|(
name|int
name|c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Called if the command is unknown
end_comment

begin_decl_stmt
name|virtual
name|void
name|On_Unknown_Command
argument_list|(
name|int
name|c
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// This is the typical C++ typesafe way to allow to attach
end_comment

begin_comment
comment|// user data to an item of a menu. Its assumed that the user
end_comment

begin_comment
comment|// data belongs to some class T. Use T as template argument
end_comment

begin_comment
comment|// to create a UserItem.
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|NCursesUserItem
operator|:
name|public
name|NCursesMenuItem
block|{
name|public
operator|:
name|NCursesUserItem
argument_list|(
specifier|const
name|char
operator|*
name|p_name
argument_list|,
specifier|const
name|char
operator|*
name|p_descript
operator|=
name|NULL
argument_list|,
specifier|const
name|T
operator|*
name|p_UserData
operator|=
operator|(
name|T
operator|*
operator|)
literal|0
argument_list|)
operator|:
name|NCursesMenuItem
argument_list|(
argument|p_name
argument_list|,
argument|p_descript
argument_list|)
block|{
if|if
condition|(
name|item
condition|)
name|OnError
argument_list|(
operator|::
name|set_item_userptr
argument_list|(
name|item
argument_list|,
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
argument_list|)
expr_stmt|;
block|}
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
operator|~
name|NCursesUserItem
argument_list|()
block|{}
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|inline
specifier|const
name|T
modifier|*
name|UserData
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
operator|(
specifier|const
name|T
operator|*
operator|)
operator|::
name|item_userptr
argument_list|(
name|item
argument_list|)
return|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
specifier|inline
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
name|item
condition|)
name|OnError
argument_list|(
operator|::
name|set_item_userptr
argument_list|(
name|item
argument_list|,
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
comment|//
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|// The same mechanism is used to attach user data to a menu
end_comment

begin_comment
comment|// -------------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|NCursesUserMenu
operator|:
name|public
name|NCursesMenu
block|{
name|protected
operator|:
name|NCursesUserMenu
argument_list|(
argument|int  lines
argument_list|,
argument|int  cols
argument_list|,
argument|int  begin_y =
literal|0
argument_list|,
argument|int  begin_x =
literal|0
argument_list|,
argument|const T* p_UserData = (T*)
literal|0
argument_list|)
operator|:
name|NCursesMenu
argument_list|(
argument|lines
argument_list|,
argument|cols
argument_list|,
argument|begin_y
argument_list|,
argument|begin_x
argument_list|)
block|{
if|if
condition|(
name|menu
condition|)
name|set_user
argument_list|(
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
expr_stmt|;
block|}
name|public
operator|:
name|NCursesUserMenu
argument_list|(
argument|NCursesMenuItem Items[]
argument_list|,
argument|const T* p_UserData = (T*)
literal|0
argument_list|,
argument|bool with_frame=FALSE
argument_list|,
argument|bool autoDelete_Items=FALSE
argument_list|)
operator|:
name|NCursesMenu
argument_list|(
argument|Items
argument_list|,
argument|with_frame
argument_list|,
argument|autoDelete_Items
argument_list|)
block|{
if|if
condition|(
name|menu
condition|)
name|set_user
argument_list|(
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_macro
name|NCursesUserMenu
argument_list|(
argument|NCursesMenuItem Items[]
argument_list|,
argument|int lines
argument_list|,
argument|int cols
argument_list|,
argument|int begin_y =
literal|0
argument_list|,
argument|int begin_x =
literal|0
argument_list|,
argument|const T* p_UserData = (T*)
literal|0
argument_list|,
argument|bool with_frame=FALSE
argument_list|)
end_macro

begin_macro
unit|:
name|NCursesMenu
argument_list|(
argument|Items
argument_list|,
argument|lines
argument_list|,
argument|cols
argument_list|,
argument|begin_y
argument_list|,
argument|begin_x
argument_list|,
argument|with_frame
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|menu
condition|)
name|set_user
argument_list|(
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
expr_stmt|;
block|}
end_block

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|virtual
operator|~
name|NCursesUserMenu
argument_list|()
block|{   }
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|inline
name|T
modifier|*
name|UserData
argument_list|(
name|void
argument_list|)
decl|const
block|{
return|return
operator|(
name|T
operator|*
operator|)
name|get_user
argument_list|()
return|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_function
specifier|inline
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
name|menu
condition|)
name|set_user
argument_list|(
operator|(
name|void
operator|*
operator|)
name|p_UserData
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// _CURSESM_H
end_comment

end_unit

