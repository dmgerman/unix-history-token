begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: mii_bitbang.h,v 1.6 2009/05/12 14:31:27 cegger Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1999 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|MII_BIT_MDO
value|0
end_define

begin_comment
comment|/* data out (host->PHY) */
end_comment

begin_define
define|#
directive|define
name|MII_BIT_MDI
value|1
end_define

begin_comment
comment|/* data in (PHY->host) */
end_comment

begin_define
define|#
directive|define
name|MII_BIT_MDC
value|2
end_define

begin_comment
comment|/* clock */
end_comment

begin_define
define|#
directive|define
name|MII_BIT_DIR_HOST_PHY
value|3
end_define

begin_comment
comment|/* set direction: host->PHY */
end_comment

begin_define
define|#
directive|define
name|MII_BIT_DIR_PHY_HOST
value|4
end_define

begin_comment
comment|/* set direction: PHY->host */
end_comment

begin_define
define|#
directive|define
name|MII_NBITS
value|5
end_define

begin_struct
struct|struct
name|mii_bitbang_ops
block|{
name|uint32_t
function_decl|(
modifier|*
name|mbo_read
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|mbo_write
function_decl|)
parameter_list|(
name|device_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
name|uint32_t
name|mbo_bits
index|[
name|MII_NBITS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
specifier|const
name|struct
name|mii_bitbang_ops
modifier|*
name|mii_bitbang_ops_t
typedef|;
end_typedef

begin_function_decl
name|int
name|mii_bitbang_readreg
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|mii_bitbang_ops_t
name|ops
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mii_bitbang_sync
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|mii_bitbang_ops_t
name|ops
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mii_bitbang_writereg
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|mii_bitbang_ops_t
name|ops
parameter_list|,
name|int
name|phy
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|val
parameter_list|)
function_decl|;
end_function_decl

end_unit

