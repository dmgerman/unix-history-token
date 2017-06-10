begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$Id: out.h,v 1.29 2017/06/08 18:11:22 schwarze Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2009, 2010, 2011 Kristaps Dzonsons<kristaps@bsd.lv>  * Copyright (c) 2014, 2017 Ingo Schwarze<schwarze@openbsd.org>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_enum
enum|enum
name|roffscale
block|{
name|SCALE_CM
block|,
comment|/* centimeters (c) */
name|SCALE_IN
block|,
comment|/* inches (i) */
name|SCALE_PC
block|,
comment|/* pica (P) */
name|SCALE_PT
block|,
comment|/* points (p) */
name|SCALE_EM
block|,
comment|/* ems (m) */
name|SCALE_MM
block|,
comment|/* mini-ems (M) */
name|SCALE_EN
block|,
comment|/* ens (n) */
name|SCALE_BU
block|,
comment|/* default horizontal (u) */
name|SCALE_VS
block|,
comment|/* default vertical (v) */
name|SCALE_FS
block|,
comment|/* syn. for u (f) */
name|SCALE_MAX
block|}
enum|;
end_enum

begin_struct
struct|struct
name|roffcol
block|{
name|size_t
name|width
decl_stmt|;
comment|/* width of cell */
name|size_t
name|decimal
decl_stmt|;
comment|/* decimal position in cell */
name|int
name|flags
decl_stmt|;
comment|/* layout flags, see tbl_cell */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|roffsu
block|{
name|enum
name|roffscale
name|unit
decl_stmt|;
name|double
name|scale
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|tbl_sulen
function_decl|)
parameter_list|(
specifier|const
name|struct
name|roffsu
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|tbl_strlen
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|tbl_len
function_decl|)
parameter_list|(
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|rofftbl
block|{
name|tbl_sulen
name|sulen
decl_stmt|;
comment|/* calculate scaling unit length */
name|tbl_strlen
name|slen
decl_stmt|;
comment|/* calculate string length */
name|tbl_len
name|len
decl_stmt|;
comment|/* produce width of empty space */
name|struct
name|roffcol
modifier|*
name|cols
decl_stmt|;
comment|/* master column specifiers */
name|void
modifier|*
name|arg
decl_stmt|;
comment|/* passed to sulen, slen, and len */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SCALE_VS_INIT
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|do { (p)->unit = SCALE_VS; \ 	     (p)->scale = (v); } \ 	while (
comment|/* CONSTCOND */
value|0)
end_define

begin_define
define|#
directive|define
name|SCALE_HS_INIT
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
define|\
value|do { (p)->unit = SCALE_EN; \ 	     (p)->scale = (v); } \ 	while (
comment|/* CONSTCOND */
value|0)
end_define

begin_struct_decl
struct_decl|struct
name|tbl_span
struct_decl|;
end_struct_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|a2roffsu
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|roffsu
modifier|*
parameter_list|,
name|enum
name|roffscale
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tblcalc
parameter_list|(
name|struct
name|rofftbl
modifier|*
name|tbl
parameter_list|,
specifier|const
name|struct
name|tbl_span
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

