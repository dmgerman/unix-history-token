begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// * This makes emacs happy -*-Mode: C++;-*-
end_comment

begin_comment
comment|/****************************************************************************  * Copyright (c) 1998 Free Software Foundation, Inc.                        *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *   Author: Juergen Pfeifer<juergen.pfeifer@gmx.net> 1997                 *  ****************************************************************************/
end_comment

begin_comment
comment|// $Id: cursesapp.h,v 1.5 1999/05/16 17:29:59 juergen Exp $
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CURSESAPP_H
end_ifndef

begin_define
define|#
directive|define
name|_CURSESAPP_H
end_define

begin_include
include|#
directive|include
file|<cursslk.h>
end_include

begin_decl_stmt
name|class
name|NCursesApplication
block|{
name|public
label|:
typedef|typedef
struct|struct
name|_slk_link
block|{
comment|// This structure is used to maintain
name|struct
name|_slk_link
modifier|*
name|prev
decl_stmt|;
comment|// a stack of SLKs
name|Soft_Label_Key_Set
modifier|*
name|SLKs
decl_stmt|;
block|}
name|SLK_Link
typedef|;
name|private
label|:
specifier|static
name|int
name|rinit
parameter_list|(
name|NCursesWindow
modifier|&
name|w
parameter_list|)
function_decl|;
comment|// Internal Init function for title
specifier|static
name|NCursesApplication
modifier|*
name|theApp
decl_stmt|;
comment|// Global ref. to the application
specifier|static
name|SLK_Link
modifier|*
name|slk_stack
decl_stmt|;
name|protected
label|:
specifier|static
name|NCursesWindow
modifier|*
name|titleWindow
decl_stmt|;
comment|// The Title Window (if any)
name|bool
name|b_Colors
decl_stmt|;
comment|// Is this a color application?
name|NCursesWindow
modifier|*
name|Root_Window
decl_stmt|;
comment|// This is the stdscr equiv.
comment|// Initialization of attributes;
comment|// Rewrite this in your derived class if you prefer other settings
name|virtual
name|void
name|init
parameter_list|(
name|bool
name|bColors
parameter_list|)
function_decl|;
comment|// The number of lines for the title window. Default is no title window
comment|// You may rewrite this in your derived class
name|virtual
name|int
name|titlesize
argument_list|()
specifier|const
block|{
return|return
literal|0
return|;
block|}
comment|// This method is called to put something into the title window initially
comment|// You may rewrite this in your derived class
name|virtual
name|void
name|title
parameter_list|()
block|{   }
comment|// The layout used for the Soft Label Keys. Default is to have no SLKs.
comment|// You may rewrite this in your derived class
name|virtual
name|Soft_Label_Key_Set
operator|::
name|Label_Layout
name|useSLKs
argument_list|()
specifier|const
block|{
return|return
name|Soft_Label_Key_Set
operator|::
name|None
return|;
block|}
comment|// This method is called to initialize the SLKs. Default is nothing.
comment|// You may rewrite this in your derived class
name|virtual
name|void
name|init_labels
argument_list|(
name|Soft_Label_Key_Set
operator|&
name|S
argument_list|)
decl|const
block|{   }
comment|// Your derived class must implement this method. The return value must
comment|// be the exit value of your application.
name|virtual
name|int
name|run
parameter_list|()
init|=
literal|0
function_decl|;
comment|// The constructor is protected, so you may use it in your derived
comment|// class constructor. The argument tells whether or not you want colors.
name|NCursesApplication
argument_list|(
argument|bool wantColors = FALSE
argument_list|)
empty_stmt|;
name|public
label|:
name|virtual
operator|~
name|NCursesApplication
argument_list|()
expr_stmt|;
comment|// Get a pointer to the current application object
specifier|static
name|NCursesApplication
modifier|*
name|getApplication
parameter_list|()
block|{
return|return
name|theApp
return|;
block|}
comment|// This method runs the application and returns its exit value
name|int
name|operator
argument_list|()
argument_list|(
name|void
argument_list|)
expr_stmt|;
comment|// Process the commandline arguments. The default implementation simply
comment|// ignores them. Your derived class may rewrite this.
name|virtual
name|void
name|handleArgs
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{   }
comment|// Does this application use colors?
specifier|inline
name|bool
name|useColors
argument_list|()
specifier|const
block|{
return|return
name|b_Colors
return|;
block|}
comment|// Push the Key Set S onto the SLK Stack. S then becomes the current set
comment|// of Soft Labelled Keys.
name|void
name|push
parameter_list|(
name|Soft_Label_Key_Set
modifier|&
name|S
parameter_list|)
function_decl|;
comment|// Throw away the current set of SLKs and make the previous one the
comment|// new current set.
name|bool
name|pop
parameter_list|()
function_decl|;
comment|// Retrieve the current set of Soft Labelled Keys.
name|Soft_Label_Key_Set
operator|*
name|top
argument_list|()
specifier|const
expr_stmt|;
comment|// Attributes to use for menu and forms foregrounds
name|virtual
name|chtype
name|foregrounds
argument_list|()
specifier|const
block|{
return|return
name|b_Colors
operator|?
name|COLOR_PAIR
argument_list|(
literal|1
argument_list|)
operator|:
name|A_BOLD
return|;
block|}
comment|// Attributes to use for menu and forms backgrounds
name|virtual
name|chtype
name|backgrounds
argument_list|()
specifier|const
block|{
return|return
name|b_Colors
operator|?
name|COLOR_PAIR
argument_list|(
literal|2
argument_list|)
operator|:
name|A_NORMAL
return|;
block|}
comment|// Attributes to use for inactive (menu) elements
name|virtual
name|chtype
name|inactives
argument_list|()
specifier|const
block|{
return|return
name|b_Colors
operator|?
operator|(
name|COLOR_PAIR
argument_list|(
literal|3
argument_list|)
operator||
name|A_DIM
operator|)
operator|:
name|A_DIM
return|;
block|}
comment|// Attributes to use for (form) labels and SLKs
name|virtual
name|chtype
name|labels
argument_list|()
specifier|const
block|{
return|return
name|b_Colors
operator|?
name|COLOR_PAIR
argument_list|(
literal|4
argument_list|)
operator|:
name|A_NORMAL
return|;
block|}
comment|// Attributes to use for form backgrounds
name|virtual
name|chtype
name|dialog_backgrounds
argument_list|()
specifier|const
block|{
return|return
name|b_Colors
operator|?
name|COLOR_PAIR
argument_list|(
literal|4
argument_list|)
operator|:
name|A_NORMAL
return|;
block|}
comment|// Attributes to use as default for (form) window backgrounds
name|virtual
name|chtype
name|window_backgrounds
argument_list|()
specifier|const
block|{
return|return
name|b_Colors
operator|?
name|COLOR_PAIR
argument_list|(
literal|5
argument_list|)
operator|:
name|A_NORMAL
return|;
block|}
comment|// Attributes to use for the title window
name|virtual
name|chtype
name|screen_titles
argument_list|()
specifier|const
block|{
return|return
name|b_Colors
operator|?
name|COLOR_PAIR
argument_list|(
literal|6
argument_list|)
operator|:
name|A_BOLD
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _CURSESAPP_H
end_comment

end_unit

