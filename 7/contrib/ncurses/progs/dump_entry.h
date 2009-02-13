begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2002,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1996-on                 *  ****************************************************************************/
end_comment

begin_comment
comment|/*  * $Id: dump_entry.h,v 1.29 2006/08/19 21:11:14 tom Exp $  *  * Dump control definitions and variables  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DUMP_ENTRY_H
end_ifndef

begin_define
define|#
directive|define
name|DUMP_ENTRY_H
value|1
end_define

begin_comment
comment|/* capability output formats */
end_comment

begin_define
define|#
directive|define
name|F_TERMINFO
value|0
end_define

begin_comment
comment|/* use terminfo names */
end_comment

begin_define
define|#
directive|define
name|F_VARIABLE
value|1
end_define

begin_comment
comment|/* use C variable names */
end_comment

begin_define
define|#
directive|define
name|F_TERMCAP
value|2
end_define

begin_comment
comment|/* termcap names with capability conversion */
end_comment

begin_define
define|#
directive|define
name|F_TCONVERR
value|3
end_define

begin_comment
comment|/* as T_TERMCAP, no skip of untranslatables */
end_comment

begin_define
define|#
directive|define
name|F_LITERAL
value|4
end_define

begin_comment
comment|/* like F_TERMINFO, but no smart defaults */
end_comment

begin_comment
comment|/* capability sort modes */
end_comment

begin_define
define|#
directive|define
name|S_DEFAULT
value|0
end_define

begin_comment
comment|/* sort by terminfo name (implicit) */
end_comment

begin_define
define|#
directive|define
name|S_NOSORT
value|1
end_define

begin_comment
comment|/* don't sort */
end_comment

begin_define
define|#
directive|define
name|S_TERMINFO
value|2
end_define

begin_comment
comment|/* sort by terminfo names (explicit) */
end_comment

begin_define
define|#
directive|define
name|S_VARIABLE
value|3
end_define

begin_comment
comment|/* sort by C variable names */
end_comment

begin_define
define|#
directive|define
name|S_TERMCAP
value|4
end_define

begin_comment
comment|/* sort by termcap names */
end_comment

begin_comment
comment|/* capability types for the comparison hook */
end_comment

begin_define
define|#
directive|define
name|CMP_BOOLEAN
value|0
end_define

begin_comment
comment|/* comparison on booleans */
end_comment

begin_define
define|#
directive|define
name|CMP_NUMBER
value|1
end_define

begin_comment
comment|/* comparison on numerics */
end_comment

begin_define
define|#
directive|define
name|CMP_STRING
value|2
end_define

begin_comment
comment|/* comparison on strings */
end_comment

begin_define
define|#
directive|define
name|CMP_USE
value|3
end_define

begin_comment
comment|/* comparison on use capabilities */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|PredType
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|PredIdx
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|PredFunc
function_decl|)
parameter_list|(
name|PredType
parameter_list|,
name|PredIdx
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|NCURSES_CONST
name|char
modifier|*
name|nametrans
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fmt_entry
parameter_list|(
name|TERMTYPE
modifier|*
parameter_list|,
name|PredFunc
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|show_entry
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|compare_entry
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|PredType
parameter_list|,
name|PredIdx
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
parameter_list|,
name|TERMTYPE
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_entry
parameter_list|(
name|TERMTYPE
modifier|*
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|,
name|int
parameter_list|,
name|PredFunc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_init
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_uses
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|repair_acsc
parameter_list|(
name|TERMTYPE
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FAIL
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DUMP_ENTRY_H */
end_comment

end_unit

