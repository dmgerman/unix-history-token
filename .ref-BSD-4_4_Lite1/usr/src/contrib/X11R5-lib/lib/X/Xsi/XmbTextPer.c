begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: XmbTextPer.c,v 1.16 91/05/02 11:57:42 rws Exp $  */
end_comment

begin_comment
comment|/*  * Copyright 1990, 1991 by OMRON Corporation, NTT Software Corporation,  *                      and Nippon Telegraph and Telephone Corporation  * Copyright 1991 by the Massachusetts Institute of Technology  *  * Permission to use, copy, modify, distribute, and sell this software and its  * documentation for any purpose is hereby granted without fee, provided that  * the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the names of OMRON, NTT Software, NTT, and M.I.T.  * not be used in advertising or publicity pertaining to distribution of the  * software without specific, written prior permission. OMRON, NTT Software,  * NTT, and M.I.T. make no representations about the suitability of this  * software for any purpose.  It is provided "as is" without express or  * implied warranty.  *  * OMRON, NTT SOFTWARE, NTT, AND M.I.T. DISCLAIM ALL WARRANTIES WITH REGARD  * TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS, IN NO EVENT SHALL OMRON, NTT SOFTWARE, NTT, OR M.I.T. BE  * LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES   * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *	Authors: Li Yuhong	OMRON Corporation  *		 Tatsuya Kato	NTT Software Corporation  *     */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xlib.h>
end_include

begin_include
include|#
directive|include
file|"Xi18nint.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|X_NOT_STDC_ENV
end_ifdef

begin_function_decl
specifier|extern
name|int
name|abs
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|Status
name|_XsimbTextPerCharExtents
parameter_list|(
name|font_set
parameter_list|,
name|text
parameter_list|,
name|text_len
parameter_list|,
name|ink_extents_buffer
parameter_list|,
name|logical_extents_buffer
parameter_list|,
name|buffer_size
parameter_list|,
name|num_chars
parameter_list|,
name|max_ink_extents
parameter_list|,
name|max_logical_extents
parameter_list|)
name|XFontSet
name|font_set
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
name|int
name|text_len
decl_stmt|;
name|XRectangle
modifier|*
name|ink_extents_buffer
decl_stmt|;
name|XRectangle
modifier|*
name|logical_extents_buffer
decl_stmt|;
name|int
name|buffer_size
decl_stmt|;
name|int
modifier|*
name|num_chars
decl_stmt|;
name|XRectangle
modifier|*
name|max_ink_extents
decl_stmt|;
name|XRectangle
modifier|*
name|max_logical_extents
decl_stmt|;
block|{
define|#
directive|define
name|DecomposeGlyphCharset
parameter_list|(
name|xlocale
parameter_list|,
name|mbstr
parameter_list|,
name|mb_bytes
parameter_list|,
name|cs_str
parameter_list|,
name|cs_bytes
parameter_list|,
name|scanned
parameter_list|,
name|ctid
parameter_list|)
define|\
value|_XmbDecomposeGlyphCharset(xlocale, (unsigned char *)mbstr, mb_bytes, (unsigned char *)cs_str, cs_bytes, scanned, ctid)
include|#
directive|include
file|"TextPerBd.c"
undef|#
directive|undef
name|DecomposeGlyphCharset
block|}
end_function

end_unit

