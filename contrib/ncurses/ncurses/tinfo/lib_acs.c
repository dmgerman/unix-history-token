begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/****************************************************************************  * Copyright (c) 1998,1999,2000,2001 Free Software Foundation, Inc.         *  *                                                                          *  * Permission is hereby granted, free of charge, to any person obtaining a  *  * copy of this software and associated documentation files (the            *  * "Software"), to deal in the Software without restriction, including      *  * without limitation the rights to use, copy, modify, merge, publish,      *  * distribute, distribute with modifications, sublicense, and/or sell       *  * copies of the Software, and to permit persons to whom the Software is    *  * furnished to do so, subject to the following conditions:                 *  *                                                                          *  * The above copyright notice and this permission notice shall be included  *  * in all copies or substantial portions of the Software.                   *  *                                                                          *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS  *  * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF               *  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.   *  * IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,   *  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR    *  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR    *  * THE USE OR OTHER DEALINGS IN THE SOFTWARE.                               *  *                                                                          *  * Except as contained in this notice, the name(s) of the above copyright   *  * holders shall not be used in advertising or otherwise to promote the     *  * sale, use or other dealings in this Software without prior written       *  * authorization.                                                           *  ****************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************  *  Author: Zeyd M. Ben-Halim<zmbenhal@netcom.com> 1992,1995               *  *     and: Eric S. Raymond<esr@snark.thyrsus.com>                         *  ****************************************************************************/
end_comment

begin_include
include|#
directive|include
file|<curses.priv.h>
end_include

begin_include
include|#
directive|include
file|<term.h>
end_include

begin_comment
comment|/* ena_acs, acs_chars */
end_comment

begin_macro
name|MODULE_ID
argument_list|(
literal|"$Id: lib_acs.c,v 1.21 2001/12/23 00:15:10 tom Exp $"
argument_list|)
end_macro

begin_if
if|#
directive|if
name|BROKEN_LINKER
end_if

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|chtype *
argument_list|)
end_macro

begin_macro
name|_nc_acs_map
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
specifier|static
name|chtype
modifier|*
name|the_map
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|the_map
operator|==
literal|0
condition|)
name|the_map
operator|=
name|typeCalloc
argument_list|(
name|chtype
argument_list|,
name|ACS_LEN
argument_list|)
expr_stmt|;
return|return
name|the_map
return|;
block|}
end_block

begin_else
else|#
directive|else
end_else

begin_macro
name|NCURSES_EXPORT_VAR
argument_list|(
argument|chtype
argument_list|)
end_macro

begin_expr_stmt
name|acs_map
index|[
name|ACS_LEN
index|]
operator|=
block|{
literal|0
block|}
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|NCURSES_EXPORT
argument_list|(
argument|void
argument_list|)
end_macro

begin_macro
name|_nc_init_acs
argument_list|(
argument|void
argument_list|)
end_macro

begin_block
block|{
name|T
argument_list|(
operator|(
literal|"initializing ACS map"
operator|)
argument_list|)
expr_stmt|;
comment|/*      * Initializations for a UNIX-like multi-terminal environment.  Use      * ASCII chars and count on the terminfo description to do better.      */
name|ACS_ULCORNER
operator|=
literal|'+'
expr_stmt|;
comment|/* should be upper left corner */
name|ACS_LLCORNER
operator|=
literal|'+'
expr_stmt|;
comment|/* should be lower left corner */
name|ACS_URCORNER
operator|=
literal|'+'
expr_stmt|;
comment|/* should be upper right corner */
name|ACS_LRCORNER
operator|=
literal|'+'
expr_stmt|;
comment|/* should be lower right corner */
name|ACS_RTEE
operator|=
literal|'+'
expr_stmt|;
comment|/* should be tee pointing left */
name|ACS_LTEE
operator|=
literal|'+'
expr_stmt|;
comment|/* should be tee pointing right */
name|ACS_BTEE
operator|=
literal|'+'
expr_stmt|;
comment|/* should be tee pointing up */
name|ACS_TTEE
operator|=
literal|'+'
expr_stmt|;
comment|/* should be tee pointing down */
name|ACS_HLINE
operator|=
literal|'-'
expr_stmt|;
comment|/* should be horizontal line */
name|ACS_VLINE
operator|=
literal|'|'
expr_stmt|;
comment|/* should be vertical line */
name|ACS_PLUS
operator|=
literal|'+'
expr_stmt|;
comment|/* should be large plus or crossover */
name|ACS_S1
operator|=
literal|'~'
expr_stmt|;
comment|/* should be scan line 1 */
name|ACS_S9
operator|=
literal|'_'
expr_stmt|;
comment|/* should be scan line 9 */
name|ACS_DIAMOND
operator|=
literal|'+'
expr_stmt|;
comment|/* should be diamond */
name|ACS_CKBOARD
operator|=
literal|':'
expr_stmt|;
comment|/* should be checker board (stipple) */
name|ACS_DEGREE
operator|=
literal|'\''
expr_stmt|;
comment|/* should be degree symbol */
name|ACS_PLMINUS
operator|=
literal|'#'
expr_stmt|;
comment|/* should be plus/minus */
name|ACS_BULLET
operator|=
literal|'o'
expr_stmt|;
comment|/* should be bullet */
name|ACS_LARROW
operator|=
literal|'<'
expr_stmt|;
comment|/* should be arrow pointing left */
name|ACS_RARROW
operator|=
literal|'>'
expr_stmt|;
comment|/* should be arrow pointing right */
name|ACS_DARROW
operator|=
literal|'v'
expr_stmt|;
comment|/* should be arrow pointing down */
name|ACS_UARROW
operator|=
literal|'^'
expr_stmt|;
comment|/* should be arrow pointing up */
name|ACS_BOARD
operator|=
literal|'#'
expr_stmt|;
comment|/* should be board of squares */
name|ACS_LANTERN
operator|=
literal|'#'
expr_stmt|;
comment|/* should be lantern symbol */
name|ACS_BLOCK
operator|=
literal|'#'
expr_stmt|;
comment|/* should be solid square block */
comment|/* these defaults were invented for ncurses */
name|ACS_S3
operator|=
literal|'-'
expr_stmt|;
comment|/* should be scan line 3 */
name|ACS_S7
operator|=
literal|'-'
expr_stmt|;
comment|/* should be scan line 7 */
name|ACS_LEQUAL
operator|=
literal|'<'
expr_stmt|;
comment|/* should be less-than-or-equal-to */
name|ACS_GEQUAL
operator|=
literal|'>'
expr_stmt|;
comment|/* should be greater-than-or-equal-to */
name|ACS_PI
operator|=
literal|'*'
expr_stmt|;
comment|/* should be greek pi */
name|ACS_NEQUAL
operator|=
literal|'!'
expr_stmt|;
comment|/* should be not-equal */
name|ACS_STERLING
operator|=
literal|'f'
expr_stmt|;
comment|/* should be pound-sterling symbol */
if|if
condition|(
name|ena_acs
operator|!=
name|NULL
condition|)
block|{
name|TPUTS_TRACE
argument_list|(
literal|"ena_acs"
argument_list|)
expr_stmt|;
name|putp
argument_list|(
name|ena_acs
argument_list|)
expr_stmt|;
block|}
define|#
directive|define
name|ALTCHAR
parameter_list|(
name|c
parameter_list|)
value|((chtype)(((unsigned char)(c)) | A_ALTCHARSET))
if|if
condition|(
name|acs_chars
operator|!=
name|NULL
condition|)
block|{
name|size_t
name|i
init|=
literal|0
decl_stmt|;
name|size_t
name|length
init|=
name|strlen
argument_list|(
name|acs_chars
argument_list|)
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|length
condition|)
switch|switch
condition|(
name|acs_chars
index|[
name|i
index|]
condition|)
block|{
case|case
literal|'l'
case|:
case|case
literal|'m'
case|:
case|case
literal|'k'
case|:
case|case
literal|'j'
case|:
case|case
literal|'u'
case|:
case|case
literal|'t'
case|:
case|case
literal|'v'
case|:
case|case
literal|'w'
case|:
case|case
literal|'q'
case|:
case|case
literal|'x'
case|:
case|case
literal|'n'
case|:
case|case
literal|'o'
case|:
case|case
literal|'s'
case|:
case|case
literal|'`'
case|:
case|case
literal|'a'
case|:
case|case
literal|'f'
case|:
case|case
literal|'g'
case|:
case|case
literal|'~'
case|:
case|case
literal|','
case|:
case|case
literal|'+'
case|:
case|case
literal|'.'
case|:
case|case
literal|'-'
case|:
case|case
literal|'h'
case|:
case|case
literal|'i'
case|:
case|case
literal|'0'
case|:
case|case
literal|'p'
case|:
case|case
literal|'r'
case|:
case|case
literal|'y'
case|:
case|case
literal|'z'
case|:
case|case
literal|'{'
case|:
case|case
literal|'|'
case|:
case|case
literal|'}'
case|:
name|acs_map
index|[
operator|(
name|unsigned
name|int
operator|)
name|acs_chars
index|[
name|i
index|]
index|]
operator|=
name|ALTCHAR
argument_list|(
name|acs_chars
index|[
name|i
operator|+
literal|1
index|]
argument_list|)
expr_stmt|;
name|i
operator|++
expr_stmt|;
comment|/* FALLTHRU */
default|default:
name|i
operator|++
expr_stmt|;
break|break;
block|}
block|}
ifdef|#
directive|ifdef
name|TRACE
comment|/* Show the equivalent mapping, noting if it does not match the      * given attribute, whether by re-ordering or duplication.      */
if|if
condition|(
name|_nc_tracing
operator|&
name|TRACE_CALLS
condition|)
block|{
name|size_t
name|n
decl_stmt|,
name|m
decl_stmt|;
name|char
name|show
index|[
name|ACS_LEN
operator|+
literal|1
index|]
decl_stmt|;
for|for
control|(
name|n
operator|=
literal|1
operator|,
name|m
operator|=
literal|0
init|;
name|n
operator|<
name|ACS_LEN
condition|;
name|n
operator|++
control|)
block|{
if|if
condition|(
name|acs_map
index|[
name|n
index|]
operator|!=
literal|0
condition|)
block|{
name|show
index|[
name|m
operator|++
index|]
operator|=
operator|(
name|char
operator|)
name|n
expr_stmt|;
name|show
index|[
name|m
operator|++
index|]
operator|=
name|ChCharOf
argument_list|(
name|acs_map
index|[
name|n
index|]
argument_list|)
expr_stmt|;
block|}
block|}
name|show
index|[
name|m
index|]
operator|=
literal|0
expr_stmt|;
name|_tracef
argument_list|(
literal|"%s acs_chars %s"
argument_list|,
operator|(
name|acs_chars
operator|==
name|NULL
operator|)
condition|?
literal|"NULL"
else|:
operator|(
name|strcmp
argument_list|(
name|acs_chars
argument_list|,
name|show
argument_list|)
condition|?
literal|"DIFF"
else|:
literal|"SAME"
operator|)
argument_list|,
name|_nc_visbuf
argument_list|(
name|show
argument_list|)
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* TRACE */
block|}
end_block

end_unit

