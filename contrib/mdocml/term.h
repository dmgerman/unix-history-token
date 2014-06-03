begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: term.h,v 1.97 2013/12/25 00:39:31 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2008, 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2011, 2012, 2013 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TERM_H
end_ifndef

begin_define
define|#
directive|define
name|TERM_H
end_define

begin_macro
name|__BEGIN_DECLS
end_macro

begin_struct_decl
struct_decl|struct
name|termp
struct_decl|;
end_struct_decl

begin_enum
enum|enum
name|termenc
block|{
name|TERMENC_ASCII
block|,
name|TERMENC_LOCALE
block|,
name|TERMENC_UTF8
block|}
enum|;
end_enum

begin_enum
enum|enum
name|termtype
block|{
name|TERMTYPE_CHAR
block|,
name|TERMTYPE_PS
block|,
name|TERMTYPE_PDF
block|}
enum|;
end_enum

begin_enum
enum|enum
name|termfont
block|{
name|TERMFONT_NONE
init|=
literal|0
block|,
name|TERMFONT_BOLD
block|,
name|TERMFONT_UNDER
block|,
name|TERMFONT_BI
block|,
name|TERMFONT__MAX
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|TERM_MAXMARGIN
value|100000
end_define

begin_comment
comment|/* FIXME */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|term_margin
function_decl|)
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|termp_tbl
block|{
name|int
name|width
decl_stmt|;
comment|/* width in fixed chars */
name|int
name|decimal
decl_stmt|;
comment|/* decimal point position */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|termp
block|{
name|enum
name|termtype
name|type
decl_stmt|;
name|struct
name|rofftbl
name|tbl
decl_stmt|;
comment|/* table configuration */
name|int
name|mdocstyle
decl_stmt|;
comment|/* imitate mdoc(7) output */
name|size_t
name|defindent
decl_stmt|;
comment|/* Default indent for text. */
name|size_t
name|defrmargin
decl_stmt|;
comment|/* Right margin of the device. */
name|size_t
name|rmargin
decl_stmt|;
comment|/* Current right margin. */
name|size_t
name|maxrmargin
decl_stmt|;
comment|/* Max right margin. */
name|size_t
name|maxcols
decl_stmt|;
comment|/* Max size of buf. */
name|size_t
name|offset
decl_stmt|;
comment|/* Margin offest. */
name|size_t
name|tabwidth
decl_stmt|;
comment|/* Distance of tab positions. */
name|size_t
name|col
decl_stmt|;
comment|/* Bytes in buf. */
name|size_t
name|viscol
decl_stmt|;
comment|/* Chars on current line. */
name|size_t
name|trailspace
decl_stmt|;
comment|/* See termp_flushln(). */
name|int
name|overstep
decl_stmt|;
comment|/* See termp_flushln(). */
name|int
name|skipvsp
decl_stmt|;
comment|/* Vertical space to skip. */
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|TERMP_SENTENCE
value|(1<< 1)
comment|/* Space before a sentence. */
define|#
directive|define
name|TERMP_NOSPACE
value|(1<< 2)
comment|/* No space before words. */
define|#
directive|define
name|TERMP_NONOSPACE
value|(1<< 3)
comment|/* No space (no autounset). */
define|#
directive|define
name|TERMP_NBRWORD
value|(1<< 4)
comment|/* Make next word nonbreaking. */
define|#
directive|define
name|TERMP_KEEP
value|(1<< 5)
comment|/* Keep words together. */
define|#
directive|define
name|TERMP_PREKEEP
value|(1<< 6)
comment|/* ...starting with the next one. */
define|#
directive|define
name|TERMP_SKIPCHAR
value|(1<< 7)
comment|/* Skip the next character. */
define|#
directive|define
name|TERMP_NOBREAK
value|(1<< 8)
comment|/* See term_flushln(). */
define|#
directive|define
name|TERMP_DANGLE
value|(1<< 9)
comment|/* See term_flushln(). */
define|#
directive|define
name|TERMP_HANG
value|(1<< 10)
comment|/* See term_flushln(). */
define|#
directive|define
name|TERMP_NOSPLIT
value|(1<< 11)
comment|/* See termp_an_pre/post(). */
define|#
directive|define
name|TERMP_SPLIT
value|(1<< 12)
comment|/* See termp_an_pre/post(). */
define|#
directive|define
name|TERMP_ANPREC
value|(1<< 13)
comment|/* See termp_an_pre(). */
name|int
modifier|*
name|buf
decl_stmt|;
comment|/* Output buffer. */
name|enum
name|termenc
name|enc
decl_stmt|;
comment|/* Type of encoding. */
name|struct
name|mchars
modifier|*
name|symtab
decl_stmt|;
comment|/* Encoded-symbol table. */
name|enum
name|termfont
name|fontl
decl_stmt|;
comment|/* Last font set. */
name|enum
name|termfont
name|fontq
index|[
literal|10
index|]
decl_stmt|;
comment|/* Symmetric fonts. */
name|int
name|fonti
decl_stmt|;
comment|/* Index of font stack. */
name|term_margin
name|headf
decl_stmt|;
comment|/* invoked to print head */
name|term_margin
name|footf
decl_stmt|;
comment|/* invoked to print foot */
name|void
function_decl|(
modifier|*
name|letter
function_decl|)
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|begin
function_decl|)
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|end
function_decl|)
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|endline
function_decl|)
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|advance
function_decl|)
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|size_t
function_decl|(
modifier|*
name|width
function_decl|)
parameter_list|(
specifier|const
name|struct
name|termp
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|double
function_decl|(
modifier|*
name|hspan
function_decl|)
parameter_list|(
specifier|const
name|struct
name|termp
modifier|*
parameter_list|,
specifier|const
name|struct
name|roffsu
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|void
modifier|*
name|argf
decl_stmt|;
comment|/* arg for headf/footf */
name|struct
name|termp_ps
modifier|*
name|ps
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|term_eqn
parameter_list|(
name|struct
name|termp
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
name|term_tbl
parameter_list|(
name|struct
name|termp
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
name|term_free
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|term_newln
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|term_vspace
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|term_word
parameter_list|(
name|struct
name|termp
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
name|term_flushln
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|term_begin
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|,
name|term_margin
parameter_list|,
name|term_margin
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|term_end
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|term_hspan
parameter_list|(
specifier|const
name|struct
name|termp
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
name|size_t
name|term_vspan
parameter_list|(
specifier|const
name|struct
name|termp
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
name|size_t
name|term_strlen
parameter_list|(
specifier|const
name|struct
name|termp
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|term_len
parameter_list|(
specifier|const
name|struct
name|termp
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|termfont
name|term_fonttop
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|term_fontq
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|term_fontpush
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|,
name|enum
name|termfont
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|term_fontpop
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|term_fontpopq
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|term_fontrepl
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|,
name|enum
name|termfont
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|term_fontlast
parameter_list|(
name|struct
name|termp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*!TERM_H*/
end_comment

end_unit

