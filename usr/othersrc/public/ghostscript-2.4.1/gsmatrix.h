begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gsmatrix.h */
end_comment

begin_comment
comment|/* Definition of matrices and matrix routines for Ghostscript library */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gsmatrix_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|gsmatrix_INCLUDED
end_define

begin_comment
comment|/* See p. 65 of the PostScript manual for the semantics of */
end_comment

begin_comment
comment|/* transformation matrices. */
end_comment

begin_comment
comment|/* Structure for a transformation matrix. */
end_comment

begin_comment
comment|/* This is a machine-dependent hack to avoid importing */
end_comment

begin_comment
comment|/* the full definition of a Ghostscript type-tagged reference. */
end_comment

begin_define
define|#
directive|define
name|_matrix_body
define|\
value|long _xx
comment|/*skip*/
value|; float xx;\ 	long _xy
comment|/*skip*/
value|; float xy;\ 	long _yx
comment|/*skip*/
value|; float yx;\ 	long _yy
comment|/*skip*/
value|; float yy;\ 	long _tx
comment|/*skip*/
value|; float tx;\ 	long _ty
comment|/*skip*/
value|; float ty
end_define

begin_typedef
typedef|typedef
struct|struct
name|gs_matrix_s
block|{
name|_matrix_body
expr_stmt|;
block|}
name|gs_matrix
typedef|;
end_typedef

begin_comment
comment|/* Macro for initializing constant matrices */
end_comment

begin_define
define|#
directive|define
name|constant_matrix_body
parameter_list|(
name|xx
parameter_list|,
name|xy
parameter_list|,
name|yx
parameter_list|,
name|yy
parameter_list|,
name|tx
parameter_list|,
name|ty
parameter_list|)
define|\
value|0L,(float)(xx), 0L,(float)(xy), 0L,(float)(yx),\ 	0L,(float)(yy), 0L,(float)(tx), 0L,(float)(ty)
end_define

begin_comment
comment|/* The identity matrix (for structure initialization) */
end_comment

begin_define
define|#
directive|define
name|identity_matrix_body
define|\
value|constant_matrix_body(1, 0, 0, 1, 0, 0)
end_define

begin_comment
comment|/* Matrix creation */
end_comment

begin_decl_stmt
name|void
name|gs_make_identity
argument_list|(
name|P1
argument_list|(
name|gs_matrix
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_make_translation
argument_list|(
name|P3
argument_list|(
name|floatp
argument_list|,
name|floatp
argument_list|,
name|gs_matrix
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_make_scaling
argument_list|(
name|P3
argument_list|(
name|floatp
argument_list|,
name|floatp
argument_list|,
name|gs_matrix
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_make_rotation
argument_list|(
name|P2
argument_list|(
name|floatp
argument_list|,
name|gs_matrix
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Matrix arithmetic */
end_comment

begin_decl_stmt
name|int
name|gs_matrix_multiply
argument_list|(
name|P3
argument_list|(
specifier|const
name|gs_matrix
operator|*
argument_list|,
specifier|const
name|gs_matrix
operator|*
argument_list|,
name|gs_matrix
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_matrix_invert
argument_list|(
name|P2
argument_list|(
specifier|const
name|gs_matrix
operator|*
argument_list|,
name|gs_matrix
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_matrix_rotate
argument_list|(
name|P3
argument_list|(
specifier|const
name|gs_matrix
operator|*
argument_list|,
name|floatp
argument_list|,
name|gs_matrix
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Coordinate transformation */
end_comment

begin_decl_stmt
name|int
name|gs_point_transform
argument_list|(
name|P4
argument_list|(
name|floatp
argument_list|,
name|floatp
argument_list|,
specifier|const
name|gs_matrix
operator|*
argument_list|,
name|gs_point
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_point_transform_inverse
argument_list|(
name|P4
argument_list|(
name|floatp
argument_list|,
name|floatp
argument_list|,
specifier|const
name|gs_matrix
operator|*
argument_list|,
name|gs_point
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_distance_transform
argument_list|(
name|P4
argument_list|(
name|floatp
argument_list|,
name|floatp
argument_list|,
specifier|const
name|gs_matrix
operator|*
argument_list|,
name|gs_point
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_distance_transform_inverse
argument_list|(
name|P4
argument_list|(
name|floatp
argument_list|,
name|floatp
argument_list|,
specifier|const
name|gs_matrix
operator|*
argument_list|,
name|gs_point
operator|*
argument_list|)
argument_list|)
decl_stmt|,
name|gs_bbox_transform_inverse
argument_list|(
name|P3
argument_list|(
name|gs_rect
operator|*
argument_list|,
name|gs_matrix
operator|*
argument_list|,
name|gs_rect
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gsmatrix_INCLUDED */
end_comment

end_unit

