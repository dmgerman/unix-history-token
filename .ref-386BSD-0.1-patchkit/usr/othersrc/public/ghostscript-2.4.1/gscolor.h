begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* gscolor.h */
end_comment

begin_comment
comment|/* Client interface to color routines for Ghostscript library */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|gscolor_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|gscolor_INCLUDED
end_define

begin_comment
comment|/* Color spaces */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|gs_color_space_DeviceGray
init|=
literal|0
block|,
name|gs_color_space_DeviceRGB
block|,
name|gs_color_space_DeviceCMYK
comment|/* not used yet */
block|}
name|gs_color_space
typedef|;
end_typedef

begin_comment
comment|/* Color and gray interface */
end_comment

begin_typedef
typedef|typedef
name|struct
name|gs_color_s
name|gs_color
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|uint
name|gs_color_sizeof
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_setgray
argument_list|(
name|P2
argument_list|(
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float
name|gs_currentgray
argument_list|(
name|P1
argument_list|(
name|gs_state
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_sethsbcolor
argument_list|(
name|P4
argument_list|(
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|)
argument_list|)
decl_stmt|,
name|gs_currenthsbcolor
argument_list|(
name|P2
argument_list|(
name|gs_state
operator|*
argument_list|,
name|float
index|[
literal|3
index|]
argument_list|)
argument_list|)
decl_stmt|,
name|gs_setrgbcolor
argument_list|(
name|P4
argument_list|(
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|,
name|floatp
argument_list|)
argument_list|)
decl_stmt|,
name|gs_currentrgbcolor
argument_list|(
name|P2
argument_list|(
name|gs_state
operator|*
argument_list|,
name|float
index|[
literal|3
index|]
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_currentcolorspace
argument_list|(
name|P2
argument_list|(
name|gs_state
operator|*
argument_list|,
name|gs_color_space
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Transfer function */
end_comment

begin_typedef
typedef|typedef
name|float
argument_list|(
operator|*
name|gs_transfer_proc
argument_list|)
argument_list|(
name|P2
argument_list|(
name|gs_state
operator|*
argument_list|,
name|floatp
argument_list|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|int
name|gs_settransfer
argument_list|(
name|P2
argument_list|(
name|gs_state
operator|*
argument_list|,
name|gs_transfer_proc
argument_list|)
argument_list|)
decl_stmt|,
name|gs_settransfer_remap
argument_list|(
name|P3
argument_list|(
name|gs_state
operator|*
argument_list|,
name|gs_transfer_proc
argument_list|,
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|gs_transfer_proc
name|gs_currenttransfer
argument_list|(
name|P1
argument_list|(
name|gs_state
operator|*
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|gs_setcolortransfer
argument_list|(
name|P5
argument_list|(
name|gs_state
operator|*
argument_list|,
name|gs_transfer_proc
comment|/*red*/
argument_list|,
name|gs_transfer_proc
comment|/*green*/
argument_list|,
name|gs_transfer_proc
comment|/*blue*/
argument_list|,
name|gs_transfer_proc
comment|/*gray*/
argument_list|)
argument_list|)
decl_stmt|,
name|gs_setcolortransfer_remap
argument_list|(
name|P6
argument_list|(
name|gs_state
operator|*
argument_list|,
name|gs_transfer_proc
comment|/*red*/
argument_list|,
name|gs_transfer_proc
comment|/*green*/
argument_list|,
name|gs_transfer_proc
comment|/*blue*/
argument_list|,
name|gs_transfer_proc
comment|/*gray*/
argument_list|,
name|int
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|gs_currentcolortransfer
argument_list|(
name|P2
argument_list|(
name|gs_state
operator|*
argument_list|,
name|gs_transfer_proc
index|[
literal|4
index|]
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gscolor_INCLUDED */
end_comment

end_unit

