begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: edidvar.h,v 1.2 2006/05/11 19:05:41 gdamore Exp $	*/
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
name|_DEV_VIDEOMODE_EDIDVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_VIDEOMODE_EDIDVAR_H
end_define

begin_struct
struct|struct
name|edid_chroma
block|{
name|uint16_t
name|ec_redx
decl_stmt|;
name|uint16_t
name|ec_redy
decl_stmt|;
name|uint16_t
name|ec_greenx
decl_stmt|;
name|uint16_t
name|ec_greeny
decl_stmt|;
name|uint16_t
name|ec_bluex
decl_stmt|;
name|uint16_t
name|ec_bluey
decl_stmt|;
name|uint16_t
name|ec_whitex
decl_stmt|;
name|uint16_t
name|ec_whitey
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|edid_range
block|{
name|uint16_t
name|er_min_vfreq
decl_stmt|;
comment|/* Hz */
name|uint16_t
name|er_max_vfreq
decl_stmt|;
comment|/* Hz */
name|uint16_t
name|er_min_hfreq
decl_stmt|;
comment|/* kHz */
name|uint16_t
name|er_max_hfreq
decl_stmt|;
comment|/* kHz */
name|uint16_t
name|er_max_clock
decl_stmt|;
comment|/* MHz */
name|int
name|er_have_gtf2
decl_stmt|;
name|uint16_t
name|er_gtf2_hfreq
decl_stmt|;
name|uint16_t
name|er_gtf2_c
decl_stmt|;
name|uint16_t
name|er_gtf2_m
decl_stmt|;
name|uint16_t
name|er_gtf2_k
decl_stmt|;
name|uint16_t
name|er_gtf2_j
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|edid_info
block|{
name|uint8_t
name|edid_vendor
index|[
literal|4
index|]
decl_stmt|;
name|char
name|edid_vendorname
index|[
literal|16
index|]
decl_stmt|;
name|char
name|edid_productname
index|[
literal|16
index|]
decl_stmt|;
name|char
name|edid_comment
index|[
literal|16
index|]
decl_stmt|;
name|char
name|edid_serial
index|[
literal|16
index|]
decl_stmt|;
name|uint16_t
name|edid_product
decl_stmt|;
name|uint8_t
name|edid_version
decl_stmt|;
name|uint8_t
name|edid_revision
decl_stmt|;
name|int
name|edid_year
decl_stmt|;
name|int
name|edid_week
decl_stmt|;
name|uint8_t
name|edid_video_input
decl_stmt|;
comment|/* see edidregs.h */
name|uint8_t
name|edid_max_hsize
decl_stmt|;
comment|/* in cm */
name|uint8_t
name|edid_max_vsize
decl_stmt|;
comment|/* in cm */
name|uint8_t
name|edid_gamma
decl_stmt|;
name|uint8_t
name|edid_features
decl_stmt|;
name|uint8_t
name|edid_ext_block_count
decl_stmt|;
name|int
name|edid_have_range
decl_stmt|;
name|struct
name|edid_range
name|edid_range
decl_stmt|;
name|struct
name|edid_chroma
name|edid_chroma
decl_stmt|;
comment|/* parsed modes */
name|struct
name|videomode
modifier|*
name|edid_preferred_mode
decl_stmt|;
name|int
name|edid_nmodes
decl_stmt|;
name|struct
name|videomode
name|edid_modes
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|edid_is_valid
parameter_list|(
name|uint8_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|edid_parse
parameter_list|(
name|uint8_t
modifier|*
parameter_list|,
name|struct
name|edid_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|edid_print
parameter_list|(
name|struct
name|edid_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_VIDEOMODE_EDIDVAR_H */
end_comment

end_unit

