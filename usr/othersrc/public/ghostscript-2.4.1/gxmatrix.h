begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gxmatrix.h */
end_comment

begin_comment
comment|/* Internal matrix routines for Ghostscript library */
end_comment

begin_include
include|#
directive|include
file|"gsmatrix.h"
end_include

begin_comment
comment|/* A matrix with a cached fixed-point copy of the translation. */
end_comment

begin_comment
comment|/* This is only used by a few routines; they are responsible */
end_comment

begin_comment
comment|/* for ensuring the validity of the cache */
end_comment

begin_comment
comment|/* (by calling gs_update_matrix_fixed). */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gs_matrix_fixed_s
block|{
name|_matrix_body
expr_stmt|;
name|fixed
name|tx_fixed
decl_stmt|,
name|ty_fixed
decl_stmt|;
block|}
name|gs_matrix_fixed
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|void
name|gs_update_matrix_fixed
argument_list|(
name|P1
argument_list|(
name|gs_matrix_fixed
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Coordinate transformations to fixed point */
end_comment

begin_decl_stmt
name|int
name|gs_point_transform2fixed
argument_list|(
name|P4
argument_list|(
name|gs_matrix_fixed
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|gs_fixed_point
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_distance_transform2fixed
argument_list|(
name|P4
argument_list|(
name|gs_matrix_fixed
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|gs_fixed_point
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macro for testing whether matrix coefficients are zero, */
end_comment

begin_comment
comment|/* for shortcuts when the matrix has no skew. */
end_comment

begin_define
define|#
directive|define
name|is_skewed
parameter_list|(
name|pmat
parameter_list|)
value|!is_fzero2((pmat)->xy, (pmat)->yx)
end_define

begin_comment
comment|/* Define the fixed-point coefficient structure for avoiding */
end_comment

begin_comment
comment|/* floating point in coordinate transformations. */
end_comment

begin_comment
comment|/* Currently this is used only by the Type 1 font interpreter. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|xx
decl_stmt|,
name|xy
decl_stmt|,
name|yx
decl_stmt|,
name|yy
decl_stmt|;
name|int
name|skewed
decl_stmt|;
name|int
name|shift
decl_stmt|;
comment|/* see c_fixed */
name|int
name|max_bits
decl_stmt|;
comment|/* max bits of coefficient */
name|fixed
name|round
decl_stmt|;
comment|/* ditto */
block|}
name|fixed_coeff
typedef|;
end_typedef

begin_comment
comment|/* Multiply an integer not exceeding max_bits in magnitude */
end_comment

begin_comment
comment|/* by a coefficient from a fixed_coeff. */
end_comment

begin_define
define|#
directive|define
name|m_fixed
parameter_list|(
name|iv
parameter_list|,
name|c
parameter_list|,
name|fc
parameter_list|)
define|\
value|arith_rshift((iv) * (c) + (fc).round, (fc).shift)
end_define

end_unit

