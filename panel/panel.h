begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2006,2009 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1995                    *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Juergen Pfeifer                         1996-1999,2008          *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: panel.h,v 1.11 2009/04/11 19:50:40 tom Exp $ */
end_comment

begin_comment
comment|/* panel.h -- interface file for panels library */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NCURSES_PANEL_H_incl
end_ifndef

begin_define
define|#
directive|define
name|NCURSES_PANEL_H_incl
value|1
end_define

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_typedef
typedef|typedef
struct|struct
name|panel
block|{
name|WINDOW
modifier|*
name|win
decl_stmt|;
name|struct
name|panel
modifier|*
name|below
decl_stmt|;
name|struct
name|panel
modifier|*
name|above
decl_stmt|;
name|NCURSES_CONST
name|void
modifier|*
name|user
decl_stmt|;
block|}
name|PANEL
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
extern|extern NCURSES_EXPORT(WINDOW*
block|)
name|panel_window
argument_list|(
specifier|const
name|PANEL
operator|*
argument_list|)
expr_stmt|;
end_extern

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|update_panels
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|hide_panel
argument_list|(
name|PANEL
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|show_panel
argument_list|(
name|PANEL
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|del_panel
argument_list|(
name|PANEL
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|top_panel
argument_list|(
name|PANEL
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|bottom_panel
argument_list|(
name|PANEL
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(PANEL*
end_extern

begin_expr_stmt
unit|)
name|new_panel
argument_list|(
name|WINDOW
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(PANEL*
end_extern

begin_expr_stmt
unit|)
name|panel_above
argument_list|(
specifier|const
name|PANEL
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(PANEL*
end_extern

begin_expr_stmt
unit|)
name|panel_below
argument_list|(
specifier|const
name|PANEL
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_macro
unit|)
name|set_panel_userptr
argument_list|(
argument|PANEL *
argument_list|,
argument|NCURSES_CONST void *
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_extern
extern|extern NCURSES_EXPORT(NCURSES_CONST void*
end_extern

begin_expr_stmt
unit|)
name|panel_userptr
argument_list|(
specifier|const
name|PANEL
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|move_panel
argument_list|(
name|PANEL
operator|*
argument_list|,
name|int
argument_list|,
name|int
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|replace_panel
argument_list|(
name|PANEL
operator|*
argument_list|,
name|WINDOW
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|panel_hidden
argument_list|(
specifier|const
name|PANEL
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
name|NCURSES_SP_FUNCS
end_if

begin_extern
extern|extern NCURSES_EXPORT(PANEL *
end_extern

begin_expr_stmt
unit|)
name|ground_panel
argument_list|(
name|SCREEN
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(PANEL *
end_extern

begin_expr_stmt
unit|)
name|ceiling_panel
argument_list|(
name|SCREEN
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|NCURSES_EXPORT
function_decl|(
name|void
function_decl|)
name|NCURSES_SP_NAME
argument_list|(
argument|update_panels
argument_list|)
parameter_list|(
name|SCREEN
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NCURSES_PANEL_H_incl */
end_comment

begin_comment
comment|/* end of panel.h */
end_comment

end_unit

