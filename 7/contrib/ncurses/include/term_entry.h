begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998-2001,2004 Free Software Foundation, Inc.              *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  *     and: Thomas E. Dickey                        1998-2004               *  ****************************************************************************/
end_comment

begin_comment
comment|/* $Id: term_entry.h,v 1.34 2005/07/16 21:15:07 tom Exp $ */
end_comment

begin_comment
comment|/*  *	term_entry.h -- interface to entry-manipulation code  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NCURSES_TERM_ENTRY_H_incl
end_ifndef

begin_define
define|#
directive|define
name|NCURSES_TERM_ENTRY_H_incl
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
include|#
directive|include
file|<term.h>
define|#
directive|define
name|MAX_USES
value|32
define|#
directive|define
name|MAX_CROSSLINKS
value|16
typedef|typedef
struct|struct
name|entry
block|{
name|TERMTYPE
name|tterm
decl_stmt|;
name|int
name|nuses
decl_stmt|;
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|entry
modifier|*
name|link
decl_stmt|;
name|long
name|line
decl_stmt|;
block|}
name|uses
index|[
name|MAX_USES
index|]
struct|;
name|int
name|ncrosslinks
decl_stmt|;
name|struct
name|entry
modifier|*
name|crosslinks
index|[
name|MAX_CROSSLINKS
index|]
decl_stmt|;
name|long
name|cstart
decl_stmt|,
name|cend
decl_stmt|;
name|long
name|startline
decl_stmt|;
name|struct
name|entry
modifier|*
name|next
decl_stmt|;
name|struct
name|entry
modifier|*
name|last
decl_stmt|;
block|}
name|ENTRY
typedef|;
if|#
directive|if
name|NCURSES_XNAMES
define|#
directive|define
name|NUM_BOOLEANS
parameter_list|(
name|tp
parameter_list|)
value|(tp)->num_Booleans
define|#
directive|define
name|NUM_NUMBERS
parameter_list|(
name|tp
parameter_list|)
value|(tp)->num_Numbers
define|#
directive|define
name|NUM_STRINGS
parameter_list|(
name|tp
parameter_list|)
value|(tp)->num_Strings
define|#
directive|define
name|EXT_NAMES
parameter_list|(
name|tp
parameter_list|,
name|i
parameter_list|,
name|limit
parameter_list|,
name|index
parameter_list|,
name|table
parameter_list|)
value|(i>= limit) ? tp->ext_Names[index] : table[i]
else|#
directive|else
define|#
directive|define
name|NUM_BOOLEANS
parameter_list|(
name|tp
parameter_list|)
value|BOOLCOUNT
define|#
directive|define
name|NUM_NUMBERS
parameter_list|(
name|tp
parameter_list|)
value|NUMCOUNT
define|#
directive|define
name|NUM_STRINGS
parameter_list|(
name|tp
parameter_list|)
value|STRCOUNT
define|#
directive|define
name|EXT_NAMES
parameter_list|(
name|tp
parameter_list|,
name|i
parameter_list|,
name|limit
parameter_list|,
name|index
parameter_list|,
name|table
parameter_list|)
value|table[i]
endif|#
directive|endif
define|#
directive|define
name|NUM_EXT_NAMES
parameter_list|(
name|tp
parameter_list|)
value|((tp)->ext_Booleans + (tp)->ext_Numbers + (tp)->ext_Strings)
define|#
directive|define
name|for_each_boolean
parameter_list|(
name|n
parameter_list|,
name|tp
parameter_list|)
value|for(n = 0; n< NUM_BOOLEANS(tp); n++)
define|#
directive|define
name|for_each_number
parameter_list|(
name|n
parameter_list|,
name|tp
parameter_list|)
value|for(n = 0; n< NUM_NUMBERS(tp);  n++)
define|#
directive|define
name|for_each_string
parameter_list|(
name|n
parameter_list|,
name|tp
parameter_list|)
value|for(n = 0; n< NUM_STRINGS(tp);  n++)
define|#
directive|define
name|ExtBoolname
parameter_list|(
name|tp
parameter_list|,
name|i
parameter_list|,
name|names
parameter_list|)
value|EXT_NAMES(tp, i, BOOLCOUNT, (i - (tp->num_Booleans - tp->ext_Booleans)), names)
define|#
directive|define
name|ExtNumname
parameter_list|(
name|tp
parameter_list|,
name|i
parameter_list|,
name|names
parameter_list|)
value|EXT_NAMES(tp, i, NUMCOUNT, (i - (tp->num_Numbers - tp->ext_Numbers)) + tp->ext_Booleans, names)
define|#
directive|define
name|ExtStrname
parameter_list|(
name|tp
parameter_list|,
name|i
parameter_list|,
name|names
parameter_list|)
value|EXT_NAMES(tp, i, STRCOUNT, (i - (tp->num_Strings - tp->ext_Strings)) + (tp->ext_Numbers + tp->ext_Booleans), names)
extern|extern NCURSES_EXPORT_VAR(ENTRY *
block|)
name|_nc_head
expr_stmt|;
end_extern

begin_extern
extern|extern NCURSES_EXPORT_VAR(ENTRY *
end_extern

begin_expr_stmt
unit|)
name|_nc_tail
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|for_entry_list
parameter_list|(
name|qp
parameter_list|)
value|for (qp = _nc_head; qp; qp = qp->next)
end_define

begin_define
define|#
directive|define
name|MAX_LINE
value|132
end_define

begin_define
define|#
directive|define
name|NULLHOOK
value|(bool(*)(ENTRY *))0
end_define

begin_comment
comment|/*  * Note that WANTED and PRESENT are not simple inverses!  If a capability  * has been explicitly cancelled, it's not considered WANTED.  */
end_comment

begin_define
define|#
directive|define
name|WANTED
parameter_list|(
name|s
parameter_list|)
value|((s) == ABSENT_STRING)
end_define

begin_define
define|#
directive|define
name|PRESENT
parameter_list|(
name|s
parameter_list|)
value|(((s) != ABSENT_STRING)&& ((s) != CANCELLED_STRING))
end_define

begin_define
define|#
directive|define
name|ANDMISSING
parameter_list|(
name|p
parameter_list|,
name|q
parameter_list|)
define|\
value|{if (PRESENT(p)&& !PRESENT(q)) _nc_warning(#p " but no " #q);}
end_define

begin_define
define|#
directive|define
name|PAIRED
parameter_list|(
name|p
parameter_list|,
name|q
parameter_list|)
define|\
value|{ \ 		if (PRESENT(q)&& !PRESENT(p)) \ 			_nc_warning(#q " but no " #p); \ 		if (PRESENT(p)&& !PRESENT(q)) \ 			_nc_warning(#p " but no " #q); \ 		}
end_define

begin_comment
comment|/* alloc_entry.c: elementary allocation code */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(ENTRY *
end_extern

begin_expr_stmt
unit|)
name|_nc_copy_entry
argument_list|(
name|ENTRY
operator|*
name|oldp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(char *
end_extern

begin_expr_stmt
unit|)
name|_nc_save_str
argument_list|(
specifier|const
name|char
operator|*
specifier|const
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_init_entry
argument_list|(
name|TERMTYPE
operator|*
specifier|const
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_merge_entry
argument_list|(
name|TERMTYPE
operator|*
specifier|const
argument_list|,
name|TERMTYPE
operator|*
specifier|const
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_wrap_entry
argument_list|(
name|ENTRY
operator|*
specifier|const
argument_list|,
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* alloc_ttype.c: elementary allocation code */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_align_termtype
argument_list|(
name|TERMTYPE
operator|*
argument_list|,
name|TERMTYPE
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_copy_termtype
argument_list|(
name|TERMTYPE
operator|*
argument_list|,
name|TERMTYPE
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* free_ttype.c: elementary allocation code */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_free_termtype
argument_list|(
name|TERMTYPE
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* lib_acs.c */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_init_acs
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* corresponds to traditional 'init_acs()' */
end_comment

begin_comment
comment|/* lib_termcap.c: trim sgr0 string for termcap users */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(char *
end_extern

begin_expr_stmt
unit|)
name|_nc_trim_sgr0
argument_list|(
name|TERMTYPE
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* parse_entry.c: entry-parsing code */
end_comment

begin_if
if|#
directive|if
name|NCURSES_XNAMES
end_if

begin_extern
extern|extern NCURSES_EXPORT_VAR(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_user_definable
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT_VAR(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_disable_period
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_parse_entry
argument_list|(
name|ENTRY
operator|*
argument_list|,
name|int
argument_list|,
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_capcmp
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* write_entry.c: writing an entry to the file system */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_set_writedir
argument_list|(
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_write_entry
argument_list|(
name|TERMTYPE
operator|*
specifier|const
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* comp_parse.c: entry list handling */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_read_entry_source
argument_list|(
name|FILE
operator|*
argument_list|,
name|char
operator|*
argument_list|,
name|int
argument_list|,
name|bool
argument_list|,
name|bool
argument_list|(
operator|*
argument_list|)
argument_list|(
name|ENTRY
operator|*
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(bool
end_extern

begin_expr_stmt
unit|)
name|_nc_entry_match
argument_list|(
name|char
operator|*
argument_list|,
name|char
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_resolve_uses
argument_list|(
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* obs 20040705 */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(int
end_extern

begin_expr_stmt
unit|)
name|_nc_resolve_uses2
argument_list|(
name|bool
argument_list|,
name|bool
argument_list|)
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_free_entries
argument_list|(
name|ENTRY
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
specifier|extern
name|NCURSES_IMPEXP
name|void
name|NCURSES_API
function_decl|(
modifier|*
name|_nc_check_termtype
function_decl|)
parameter_list|(
name|TERMTYPE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* obs 20040705 */
end_comment

begin_function_decl
specifier|extern
name|NCURSES_IMPEXP
name|void
name|NCURSES_API
function_decl|(
modifier|*
name|_nc_check_termtype2
function_decl|)
parameter_list|(
name|TERMTYPE
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* trace_xnames.c */
end_comment

begin_extern
extern|extern NCURSES_EXPORT(void
end_extern

begin_expr_stmt
unit|)
name|_nc_trace_xnames
argument_list|(
name|TERMTYPE
operator|*
argument_list|)
expr_stmt|;
end_expr_stmt

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
comment|/* NCURSES_TERM_ENTRY_H_incl */
end_comment

end_unit

