begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gzstate.h */
end_comment

begin_comment
comment|/* Private graphics state definition for Ghostscript library */
end_comment

begin_comment
comment|/* Requires gxmatrix.h and gxfixed.h */
end_comment

begin_include
include|#
directive|include
file|"gsstate.h"
end_include

begin_comment
comment|/* Graphics state structure.  See pp. 59-60 of the PostScript manual. */
end_comment

begin_struct
struct|struct
name|gs_state_s
block|{
name|gs_state
modifier|*
name|saved
decl_stmt|;
comment|/* previous state from gsave */
name|gs_memory_procs
name|memory_procs
decl_stmt|;
comment|/* Transformation: */
name|gs_matrix_fixed
name|ctm
decl_stmt|;
define|#
directive|define
name|ctm_only
parameter_list|(
name|pgs
parameter_list|)
value|*(gs_matrix *)&(pgs)->ctm
name|gs_matrix
name|ctm_inverse
decl_stmt|;
name|int
name|inverse_valid
decl_stmt|;
comment|/* true if ctm_inverse = ctm^-1 */
comment|/* Paths: */
name|struct
name|gx_path_s
modifier|*
name|path
decl_stmt|;
name|struct
name|gx_clip_path_s
modifier|*
name|clip_path
decl_stmt|;
name|int
name|clip_rule
decl_stmt|;
comment|/* Lines: */
name|struct
name|line_params_s
modifier|*
name|line_params
decl_stmt|;
comment|/* Halftone screen: */
name|struct
name|halftone_params_s
modifier|*
name|halftone
decl_stmt|;
name|float
argument_list|(
operator|*
name|ht_proc
argument_list|)
argument_list|(
name|P2
argument_list|(
name|floatp
argument_list|,
name|floatp
argument_list|)
argument_list|)
expr_stmt|;
name|gs_int_point
name|ht_phase
decl_stmt|;
name|gs_int_point
name|phase_mod
decl_stmt|;
comment|/* negated phase mod tile size */
comment|/* Colors: */
name|struct
name|gs_color_s
modifier|*
name|color
decl_stmt|;
name|struct
name|gx_device_color_s
modifier|*
name|dev_color
decl_stmt|;
name|struct
name|gx_transfer_s
modifier|*
name|transfer
decl_stmt|;
comment|/* Font: */
name|struct
name|gs_font_s
modifier|*
name|font
decl_stmt|;
name|gs_matrix
name|char_tm
decl_stmt|;
comment|/* font matrix * ctm */
name|int
name|char_tm_valid
decl_stmt|;
comment|/* true if char_tm is valid */
name|byte
name|in_cachedevice
decl_stmt|;
comment|/* true after a setcachedevice */
name|byte
name|in_charpath
decl_stmt|;
comment|/* 0 if not in charpath, */
comment|/* 1 if false charpath, */
comment|/* 2 if true charpath */
comment|/* (see charpath_flag in */
comment|/* gs_show_enum_s) */
comment|/* Other stuff: */
name|int
name|level
decl_stmt|;
comment|/* incremented by 1 per gsave */
name|float
name|flatness
decl_stmt|;
name|int
name|stroke_adjust
decl_stmt|;
name|struct
name|device_s
modifier|*
name|device
decl_stmt|;
name|int
name|device_is_shared
decl_stmt|;
comment|/* true if device is shared, */
comment|/* so don't deallocate at grestore */
block|}
struct|;
end_struct

end_unit

