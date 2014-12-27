begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: html.h,v 1.70 2014/12/02 10:08:06 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008-2011, 2014 Kristaps Dzonsons<kristaps@bsd.lv>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_enum
enum|enum
name|htmltag
block|{
name|TAG_HTML
block|,
name|TAG_HEAD
block|,
name|TAG_BODY
block|,
name|TAG_META
block|,
name|TAG_TITLE
block|,
name|TAG_DIV
block|,
name|TAG_H1
block|,
name|TAG_H2
block|,
name|TAG_SPAN
block|,
name|TAG_LINK
block|,
name|TAG_BR
block|,
name|TAG_A
block|,
name|TAG_TABLE
block|,
name|TAG_TBODY
block|,
name|TAG_COL
block|,
name|TAG_TR
block|,
name|TAG_TD
block|,
name|TAG_LI
block|,
name|TAG_UL
block|,
name|TAG_OL
block|,
name|TAG_DL
block|,
name|TAG_DT
block|,
name|TAG_DD
block|,
name|TAG_BLOCKQUOTE
block|,
name|TAG_PRE
block|,
name|TAG_B
block|,
name|TAG_I
block|,
name|TAG_CODE
block|,
name|TAG_SMALL
block|,
name|TAG_STYLE
block|,
name|TAG_MATH
block|,
name|TAG_MROW
block|,
name|TAG_MI
block|,
name|TAG_MO
block|,
name|TAG_MSUP
block|,
name|TAG_MSUB
block|,
name|TAG_MSUBSUP
block|,
name|TAG_MFRAC
block|,
name|TAG_MSQRT
block|,
name|TAG_MFENCED
block|,
name|TAG_MTABLE
block|,
name|TAG_MTR
block|,
name|TAG_MTD
block|,
name|TAG_MUNDEROVER
block|,
name|TAG_MUNDER
block|,
name|TAG_MOVER
block|,
name|TAG_MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
name|htmlattr
block|{
name|ATTR_NAME
block|,
name|ATTR_REL
block|,
name|ATTR_HREF
block|,
name|ATTR_TYPE
block|,
name|ATTR_MEDIA
block|,
name|ATTR_CLASS
block|,
name|ATTR_STYLE
block|,
name|ATTR_ID
block|,
name|ATTR_COLSPAN
block|,
name|ATTR_CHARSET
block|,
name|ATTR_OPEN
block|,
name|ATTR_CLOSE
block|,
name|ATTR_MATHVARIANT
block|,
name|ATTR_MAX
block|}
enum|;
end_enum

begin_enum
enum|enum
name|htmlfont
block|{
name|HTMLFONT_NONE
init|=
literal|0
block|,
name|HTMLFONT_BOLD
block|,
name|HTMLFONT_ITALIC
block|,
name|HTMLFONT_BI
block|,
name|HTMLFONT_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|tag
block|{
name|struct
name|tag
modifier|*
name|next
decl_stmt|;
name|enum
name|htmltag
name|tag
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tagq
block|{
name|struct
name|tag
modifier|*
name|head
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|htmlpair
block|{
name|enum
name|htmlattr
name|key
decl_stmt|;
specifier|const
name|char
modifier|*
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PAIR_INIT
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|,
name|v
parameter_list|)
define|\
value|do { \ 		(p)->key = (t); \ 		(p)->val = (v); \ 	} while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|PAIR_ID_INIT
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|PAIR_INIT(p, ATTR_ID, v)
end_define

begin_define
define|#
directive|define
name|PAIR_CLASS_INIT
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|PAIR_INIT(p, ATTR_CLASS, v)
end_define

begin_define
define|#
directive|define
name|PAIR_HREF_INIT
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|PAIR_INIT(p, ATTR_HREF, v)
end_define

begin_define
define|#
directive|define
name|PAIR_STYLE_INIT
parameter_list|(
name|p
parameter_list|,
name|h
parameter_list|)
value|PAIR_INIT(p, ATTR_STYLE, (h)->buf)
end_define

begin_struct
struct|struct
name|html
block|{
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|HTML_NOSPACE
value|(1<< 0)
comment|/* suppress next space */
define|#
directive|define
name|HTML_IGNDELIM
value|(1<< 1)
define|#
directive|define
name|HTML_KEEP
value|(1<< 2)
define|#
directive|define
name|HTML_PREKEEP
value|(1<< 3)
define|#
directive|define
name|HTML_NONOSPACE
value|(1<< 4)
comment|/* never add spaces */
define|#
directive|define
name|HTML_LITERAL
value|(1<< 5)
comment|/* literal (e.g.,<PRE>) context */
define|#
directive|define
name|HTML_SKIPCHAR
value|(1<< 6)
comment|/* skip the next character */
define|#
directive|define
name|HTML_NOSPLIT
value|(1<< 7)
comment|/* do not break line before .An */
define|#
directive|define
name|HTML_SPLIT
value|(1<< 8)
comment|/* break line before .An */
define|#
directive|define
name|HTML_NONEWLINE
value|(1<< 9)
comment|/* No line break in nofill mode. */
name|struct
name|tagq
name|tags
decl_stmt|;
comment|/* stack of open tags */
name|struct
name|rofftbl
name|tbl
decl_stmt|;
comment|/* current table */
name|struct
name|tag
modifier|*
name|tblt
decl_stmt|;
comment|/* current open table scope */
specifier|const
name|struct
name|mchars
modifier|*
name|symtab
decl_stmt|;
comment|/* character table */
name|char
modifier|*
name|base_man
decl_stmt|;
comment|/* base for manpage href */
name|char
modifier|*
name|base_includes
decl_stmt|;
comment|/* base for include href */
name|char
modifier|*
name|style
decl_stmt|;
comment|/* style-sheet URI */
name|char
name|buf
index|[
name|BUFSIZ
index|]
decl_stmt|;
comment|/* see bufcat and friends */
name|size_t
name|buflen
decl_stmt|;
name|struct
name|tag
modifier|*
name|metaf
decl_stmt|;
comment|/* current open font scope */
name|enum
name|htmlfont
name|metal
decl_stmt|;
comment|/* last used font */
name|enum
name|htmlfont
name|metac
decl_stmt|;
comment|/* current font mode */
name|int
name|oflags
decl_stmt|;
comment|/* output options */
define|#
directive|define
name|HTML_FRAGMENT
value|(1<< 0)
comment|/* don't emit HTML/HEAD/BODY */
block|}
struct|;
end_struct

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|tbl_span
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|eqn
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|print_gen_decls
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_gen_head
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|tag
modifier|*
name|print_otag
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
name|enum
name|htmltag
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|htmlpair
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_tagq
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|struct
name|tag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_stagq
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|struct
name|tag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_text
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_tblclose
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_tbl
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|struct
name|tbl_span
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_eqn
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|struct
name|eqn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_paragraph
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__GNUC__
operator|-
literal|0
operator|>=
literal|4
end_if

begin_macro
name|__attribute__
argument_list|(
argument|(__format__ (__printf__,
literal|2
argument|,
literal|3
argument|))
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|bufcat_fmt
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufcat
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufcat_id
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufcat_style
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufcat_su
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|struct
name|roffsu
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bufinit
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffmt_man
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|buffmt_includes
parameter_list|(
name|struct
name|html
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|html_strlen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

end_unit

