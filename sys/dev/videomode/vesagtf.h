begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD$	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2006 Itronix Inc.  * All rights reserved.  *  * Written by Garrett D'Amore for Itronix Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of Itronix Inc. may not be used to endorse  *    or promote products derived from this software without specific  *    prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY ITRONIX INC. ``AS IS'' AND ANY EXPRESS  * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL ITRONIX INC. BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE  * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_VIDEOMODE_VESAGTF_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_VIDEOMODE_VESAGTF_H
end_define

begin_comment
comment|/*  * Use VESA GTF formula to generate a monitor mode, given resolution and  * refresh rates.  */
end_comment

begin_struct
struct|struct
name|vesagtf_params
block|{
name|unsigned
name|margin_ppt
decl_stmt|;
comment|/* vertical margin size, percent * 10 					 * think parts-per-thousand */
name|unsigned
name|min_porch
decl_stmt|;
comment|/* minimum front porch */
name|unsigned
name|vsync_rqd
decl_stmt|;
comment|/* width of vsync in lines */
name|unsigned
name|hsync_pct
decl_stmt|;
comment|/* hsync as % of total width */
name|unsigned
name|min_vsbp
decl_stmt|;
comment|/* minimum vsync + back porch (usec) */
name|unsigned
name|M
decl_stmt|;
comment|/* blanking formula gradient */
name|unsigned
name|C
decl_stmt|;
comment|/* blanking formula offset */
name|unsigned
name|K
decl_stmt|;
comment|/* blanking formula scaling factor */
name|unsigned
name|J
decl_stmt|;
comment|/* blanking formula scaling factor */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Default values to use for params.  */
end_comment

begin_define
define|#
directive|define
name|VESAGTF_MARGIN_PPT
value|18
end_define

begin_comment
comment|/* 1.8% */
end_comment

begin_define
define|#
directive|define
name|VESAGTF_MIN_PORCH
value|1
end_define

begin_comment
comment|/* minimum front porch */
end_comment

begin_define
define|#
directive|define
name|VESAGTF_VSYNC_RQD
value|3
end_define

begin_comment
comment|/* vsync width in lines */
end_comment

begin_define
define|#
directive|define
name|VESAGTF_HSYNC_PCT
value|8
end_define

begin_comment
comment|/* width of hsync % of total line */
end_comment

begin_define
define|#
directive|define
name|VESAGTF_MIN_VSBP
value|550
end_define

begin_comment
comment|/* min vsync + back porch (usec) */
end_comment

begin_define
define|#
directive|define
name|VESAGTF_M
value|600
end_define

begin_comment
comment|/* blanking formula gradient */
end_comment

begin_define
define|#
directive|define
name|VESAGTF_C
value|40
end_define

begin_comment
comment|/* blanking formula offset */
end_comment

begin_define
define|#
directive|define
name|VESAGTF_K
value|128
end_define

begin_comment
comment|/* blanking formula scaling factor */
end_comment

begin_define
define|#
directive|define
name|VESAGTF_J
value|20
end_define

begin_comment
comment|/* blanking formula scaling factor */
end_comment

begin_comment
comment|/*  * Use VESA GTF formula to generate monitor timings.  Assumes default  * GTF parameters, non-interlaced, and no margins.  */
end_comment

begin_function_decl
name|void
name|vesagtf_mode
parameter_list|(
name|unsigned
name|x
parameter_list|,
name|unsigned
name|y
parameter_list|,
name|unsigned
name|refresh
parameter_list|,
name|struct
name|videomode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * A more complete version, in case we ever want to use alternate GTF  * parameters.  EDID 1.3 allows for "secondary GTF parameters".  */
end_comment

begin_function_decl
name|void
name|vesagtf_mode_params
parameter_list|(
name|unsigned
name|x
parameter_list|,
name|unsigned
name|y
parameter_list|,
name|unsigned
name|refresh
parameter_list|,
name|struct
name|vesagtf_params
modifier|*
parameter_list|,
name|int
name|flags
parameter_list|,
name|struct
name|videomode
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VESAGTF_FLAG_ILACE
value|0x0001
end_define

begin_comment
comment|/* use interlace */
end_comment

begin_define
define|#
directive|define
name|VESAGTF_FLAG_MARGINS
value|0x0002
end_define

begin_comment
comment|/* use margins */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_VIDEOMODE_VESAGTF_H */
end_comment

end_unit

