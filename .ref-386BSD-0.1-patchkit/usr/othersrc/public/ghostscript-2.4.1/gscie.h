begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1992 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gscie.h */
end_comment

begin_comment
comment|/* Interface to Ghostscript CIE color algorithms */
end_comment

begin_comment
comment|/* ------ Common definitions ------ */
end_comment

begin_comment
comment|/* A 3-element vector. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_vector3_s
block|{
name|float
name|u
decl_stmt|,
name|v
decl_stmt|,
name|w
decl_stmt|;
block|}
name|gs_vector3
typedef|;
end_typedef

begin_comment
comment|/* A 3x3 matrix, stored in column order. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_matrix3_s
block|{
name|gs_vector3
name|cu
decl_stmt|,
name|cv
decl_stmt|,
name|cw
decl_stmt|;
block|}
name|gs_matrix3
typedef|;
end_typedef

begin_comment
comment|/* A 3-element vector of ranges. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_range_s
block|{
name|float
name|rmin
decl_stmt|,
name|rmax
decl_stmt|;
block|}
name|gs_range
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gs_range3_s
block|{
name|gs_range
name|u
decl_stmt|,
name|v
decl_stmt|,
name|w
decl_stmt|;
block|}
name|gs_range3
typedef|;
end_typedef

begin_comment
comment|/* A 3-element procedure vector. */
end_comment

begin_typedef
typedef|typedef
name|float
argument_list|(
operator|*
name|gs_float_proc
argument_list|)
argument_list|(
name|P1
argument_list|(
name|floatp
argument_list|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gs_float_proc3_s
block|{
name|gs_float_proc
name|u
decl_stmt|,
name|v
decl_stmt|,
name|w
decl_stmt|;
block|}
name|gs_float_proc3
typedef|;
end_typedef

begin_comment
comment|/* CIE white and black points. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_cie_wb_s
block|{
name|gs_vector3
name|WhitePoint
decl_stmt|;
name|gs_vector3
name|BlackPoint
decl_stmt|;
block|}
name|gs_cie_wb
typedef|;
end_typedef

begin_comment
comment|/* ------ Color space dictionaries ------ */
end_comment

begin_comment
comment|/* A CIEBasedABC dictionary. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_cie_abc_s
block|{
name|gs_range3
name|RangeABC
decl_stmt|;
name|gs_float_proc3
name|DecodeABC
decl_stmt|;
name|gs_matrix3
name|MatrixABC
decl_stmt|;
name|gs_range3
name|RangeLMN
decl_stmt|;
name|gs_float_proc3
name|DecodeLMN
decl_stmt|;
name|gs_matrix3
name|MatrixLMN
decl_stmt|;
name|gs_cie_wb
name|points
decl_stmt|;
block|}
name|gs_cie_abc
typedef|;
end_typedef

begin_comment
comment|/* A CIEBasedA dictionary. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_cie_a_s
block|{
name|gs_range
name|RangeA
decl_stmt|;
name|gs_float_proc
name|DecodeA
decl_stmt|;
name|gs_vector3
name|MatrixA
decl_stmt|;
name|gs_range3
name|RangeLMN
decl_stmt|;
name|gs_float_proc3
name|DecodeLMN
decl_stmt|;
name|gs_matrix3
name|MatrixLMN
decl_stmt|;
name|gs_cie_wb
name|points
decl_stmt|;
block|}
name|gs_cie_a
typedef|;
end_typedef

begin_comment
comment|/* Default values for components */
end_comment

begin_decl_stmt
specifier|extern
name|gs_range3
name|Range3_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gs_float_proc3
name|Decode3_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gs_matrix3
name|Matrix3_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gs_range
name|RangeA_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gs_float_proc
name|DecodeA_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gs_vector3
name|MatrixA_default
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|gs_vector3
name|BlackPoint_default
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ------ Rendering dictionaries ------ */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_cie_wbsd_s
block|{
struct|struct
block|{
name|gs_vector3
name|xyz
decl_stmt|,
name|pqr
decl_stmt|;
block|}
name|ws
struct|,
name|bs
struct|,
name|wd
struct|,
name|bd
struct|;
block|}
name|gs_cie_wbsd
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|float
argument_list|(
operator|*
name|gs_cie_transform_proc
argument_list|)
argument_list|(
name|P2
argument_list|(
name|gs_cie_wbsd
operator|*
argument_list|,
name|floatp
argument_list|)
argument_list|)
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|gs_cie_render_table_s
block|{
name|int
name|NA
decl_stmt|,
name|NB
decl_stmt|,
name|NC
decl_stmt|;
comment|/*>1 */
name|byte
modifier|*
modifier|*
name|table
decl_stmt|;
comment|/* [NA][m * NB * NC] */
comment|/* 0 means no table */
name|int
name|m
decl_stmt|;
comment|/* 3 or 4 */
name|gs_float_proc
name|T
index|[
literal|4
index|]
decl_stmt|;
comment|/* [m] */
block|}
name|gs_cie_render_table
typedef|;
end_typedef

begin_comment
comment|/* The main dictionary */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_cie_render_s
block|{
name|gs_matrix3
name|MatrixLMN
decl_stmt|;
name|gs_float_proc3
name|EncodeLMN
decl_stmt|;
name|gs_range3
name|RangeLMN
decl_stmt|;
name|gs_matrix3
name|MatrixABC
decl_stmt|;
name|gs_float_proc3
name|EncodeABC
decl_stmt|;
name|gs_range3
name|RangeABC
decl_stmt|;
name|gs_cie_wb
name|points
decl_stmt|;
name|gs_matrix3
name|MatrixPQR
decl_stmt|;
name|gs_range3
name|RangePQR
decl_stmt|;
struct|struct
block|{
name|gs_cie_transform_proc
name|u
decl_stmt|,
name|v
decl_stmt|,
name|w
decl_stmt|;
block|}
name|TransformPQR
struct|;
name|gs_cie_render_table
name|RenderTable
decl_stmt|;
comment|/* Following are computed when table is initialized. */
name|gs_matrix3
name|MatrixPQR_inverse
decl_stmt|;
name|gs_vector3
name|wdpqr
decl_stmt|,
name|bdpqr
decl_stmt|;
block|}
name|gs_cie_render
typedef|;
end_typedef

begin_comment
comment|/* ------ Procedures ------ */
end_comment

begin_comment
comment|/*  * The decoding and rendering algorithms involve user-defined procedures.  * Since the interpreter handles these specially, the algorithms *return*  * to the caller between steps, rather than using a call-back.  * The scenario for decoding:  *	gs_cie_abc_decode1(abc, tabc)  *	... DecodeABC(tabc) ...  *	gs_cie_abc_decode2(tabc, tlmn)  *	... DecodeLMN(tlmn) ...  *	gs_cie_abc_decode3(tlmn, xyz)  * or:  *	gs_cie_a_decode1(a, ta)  *	... DecodeA(ta) ...  *	gs_cie_a_decode2(ta, tlmn)  *	... DecodeLMN(tlmn) ...  *	gs_cie_a_decode3(tlmn, xyz) [same as abc_decode3]  * The scenario for rendering:  *	gs_cie_render_colors1(xyz, wbsd, tpqr)  *	... TransformPQR(wbsd, tpqr) ...  *	gs_cie_render_colors2(tpqr, tlmn)  *	... EncodeLMN(tlmn) ...  *	gs_cie_render_colors3(tlmn, tabc)  *	... EncodeABC(tabc) ...  *	gs_cie_render_colors4(tabc, colors)  */
end_comment

begin_comment
comment|/* Decode ABC values to XYZ. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gs_cie_abc_decode1
argument_list|(
name|P3
argument_list|(
name|gs_vector3
operator|*
name|pabc
argument_list|,
name|gs_vector3
operator|*
name|ptabc
argument_list|,
name|gs_cie_abc
operator|*
name|pcie
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gs_cie_abc_decode2
argument_list|(
name|P3
argument_list|(
name|gs_vector3
operator|*
name|ptabc
argument_list|,
name|gs_vector3
operator|*
name|ptlmn
argument_list|,
name|gs_cie_abc
operator|*
name|pcie
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gs_cie_abc_decode3
argument_list|(
name|P3
argument_list|(
name|gs_vector3
operator|*
name|ptlmn
argument_list|,
name|gs_vector3
operator|*
name|pxyz
argument_list|,
name|gs_cie_abc
operator|*
name|pcie
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Decode A value to XYZ. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gs_cie_a_decode1
argument_list|(
name|P3
argument_list|(
argument|floatp va
argument_list|,
argument|float *pta
argument_list|,
argument|gs_cie_a *pcie
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gs_cie_a_decode2
argument_list|(
name|P3
argument_list|(
argument|floatp ta
argument_list|,
argument|gs_vector3 *ptlmn
argument_list|,
argument|gs_cie_a *pcie
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|gs_cie_a_decode3
parameter_list|(
name|ptlmn
parameter_list|,
name|pxyz
parameter_list|,
name|pcie
parameter_list|)
value|gs_cie_abc_decode3(ptlmn, pxyz, pcie)
end_define

begin_comment
comment|/* Compute the cached values in a CIE rendering table. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gs_cie_render_init
argument_list|(
name|P1
argument_list|(
name|gs_cie_render
operator|*
name|pcie
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Render CIE colors */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gs_cie_render_colors1
argument_list|(
name|P5
argument_list|(
name|gs_vector3
operator|*
name|pxyz
argument_list|,
name|gs_cie_wbsd
operator|*
name|pwbsd
argument_list|,
name|gs_vector3
operator|*
name|ppqr
argument_list|,
name|gs_cie_wb
operator|*
name|points
argument_list|,
name|gs_cie_render
operator|*
name|pcie
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gs_cir_render_colors2
argument_list|(
name|P3
argument_list|(
name|gs_vector3
operator|*
name|ptpqr
argument_list|,
name|gs_vector3
operator|*
name|ptlmn
argument_list|,
name|gs_cie_render
operator|*
name|pcie
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gs_cir_render_colors3
argument_list|(
name|P3
argument_list|(
name|gs_vector3
operator|*
name|ptlmn
argument_list|,
name|gs_vector3
operator|*
name|ptabc
argument_list|,
name|gs_cie_render
operator|*
name|pcie
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gs_cie_render_colors4
argument_list|(
name|P3
argument_list|(
name|gs_vector3
operator|*
name|ptabc
argument_list|,
name|float
operator|*
name|colors
argument_list|,
name|gs_cie_render
operator|*
name|pcie
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

