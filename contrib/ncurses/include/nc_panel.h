begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2008,2009 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Juergen Pfeifer                        1997                     *  *     and: Thomas E. Dickey                                                *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * $Id: nc_panel.h,v 1.7 2009/07/04 18:20:02 tom Exp $  *  *	nc_panel.h  *  *	Headerfile to provide an interface for the panel layer into  *      the SCREEN structure of the ncurses core.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NC_PANEL_H
end_ifndef

begin_define
define|#
directive|define
name|NC_PANEL_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
struct_decl|struct
name|panel
struct_decl|;
comment|/* Forward Declaration */
struct|struct
name|panelhook
block|{
name|struct
name|panel
modifier|*
name|top_panel
decl_stmt|;
name|struct
name|panel
modifier|*
name|bottom_panel
decl_stmt|;
name|struct
name|panel
modifier|*
name|stdscr_pseudo_panel
decl_stmt|;
if|#
directive|if
name|NO_LEAKS
name|int
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|struct
name|panel
modifier|*
parameter_list|)
function_decl|;
endif|#
directive|endif
block|}
struct|;
struct_decl|struct
name|screen
struct_decl|;
comment|/* Forward declaration */
comment|/* Retrieve the panelhook of the specified screen */
extern|extern NCURSES_EXPORT(struct panelhook *
block|)
name|_nc_panelhook
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_extern

begin_if
if|#
directive|if
name|NCURSES_SP_FUNCS
end_if

begin_extern
extern|extern NCURSES_EXPORT(struct panelhook *
end_extern

begin_function_decl
unit|)
name|NCURSES_SP_NAME
function_decl|(
name|_nc_panelhook
function_decl|)
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

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

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
comment|/* NC_PANEL_H */
end_comment

end_unit

