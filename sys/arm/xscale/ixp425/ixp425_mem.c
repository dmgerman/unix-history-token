begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ixp425_mem.c,v 1.2 2005/12/11 12:16:51 christos Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2003 Wasabi Systems, Inc.  * All rights reserved.  *  * Written by Steve C. Woodford for Wasabi Systems, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed for the NetBSD Project by  *      Wasabi Systems, Inc.  * 4. The name of Wasabi Systems, Inc. may not be used to endorse  *    or promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY WASABI SYSTEMS, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL WASABI SYSTEMS, INC  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425reg.h>
end_include

begin_include
include|#
directive|include
file|<arm/xscale/ixp425/ixp425var.h>
end_include

begin_decl_stmt
specifier|static
name|uint32_t
name|sdram_64bit
index|[]
init|=
block|{
literal|0x00800000
block|,
comment|/* 8M:  One 2M x 32 chip */
literal|0x01000000
block|,
comment|/* 16M: Two 2M x 32 chips */
literal|0x01000000
block|,
comment|/* 16M: One 4M x 32 chip */
literal|0x02000000
block|,
comment|/* 32M: Two 4M x 32 chips */
literal|0
block|,
literal|0
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|uint32_t
name|sdram_other
index|[]
init|=
block|{
literal|0x02000000
block|,
comment|/*  32M: Two   8M x 16 chips */
literal|0x04000000
block|,
comment|/*  64M: Four  8M x 16 chips */
literal|0x04000000
block|,
comment|/*  64M: Two  16M x 16 chips */
literal|0x08000000
block|,
comment|/* 128M: Four 16M x 16 chips */
literal|0x08000000
block|,
comment|/* 128M: Two  32M x 16 chips */
literal|0x10000000
block|,
comment|/* 256M: Four 32M x 16 chips */
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MCU_REG_READ
parameter_list|(
name|x
parameter_list|)
value|(*(volatile uint32_t *)(IXP425_MCU_VBASE + (x)))
end_define

begin_function
name|uint32_t
name|ixp425_sdram_size
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|size
decl_stmt|,
name|sdr_config
decl_stmt|;
name|sdr_config
operator|=
name|MCU_REG_READ
argument_list|(
name|MCU_SDR_CONFIG
argument_list|)
expr_stmt|;
if|if
condition|(
name|sdr_config
operator|&
name|MCU_SDR_CONFIG_64MBIT
condition|)
name|size
operator|=
name|sdram_64bit
index|[
name|MCU_SDR_CONFIG_MCONF
argument_list|(
name|sdr_config
argument_list|)
index|]
expr_stmt|;
else|else
name|size
operator|=
name|sdram_other
index|[
name|MCU_SDR_CONFIG_MCONF
argument_list|(
name|sdr_config
argument_list|)
index|]
expr_stmt|;
if|if
condition|(
name|size
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"** SDR_CONFIG retuns unknown value, using 32M\n"
argument_list|)
expr_stmt|;
name|size
operator|=
literal|32
operator|*
literal|1024
operator|*
literal|1024
expr_stmt|;
block|}
return|return
operator|(
name|size
operator|)
return|;
block|}
end_function

end_unit

