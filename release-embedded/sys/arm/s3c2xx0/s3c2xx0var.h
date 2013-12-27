begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: s3c2xx0var.h,v 1.3 2003/08/05 11:26:54 bsh Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2002 Fujitsu Component Limited  * Copyright (c) 2002 Genetec Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of The Fujitsu Component Limited nor the name of  *    Genetec corporation may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY FUJITSU COMPONENT LIMITED AND GENETEC  * CORPORATION ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL FUJITSU COMPONENT LIMITED OR GENETEC  * CORPORATION BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_S3C2XX0VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_ARM_S3C2XX0VAR_H_
end_define

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_typedef
typedef|typedef
enum|enum
block|{
name|CPU_S3C2410
block|,
name|CPU_S3C2440
block|, }
name|s3c2xx0_cpu
typedef|;
end_typedef

begin_struct
struct|struct
name|s3c2xx0_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
name|s3c2xx0_cpu
name|sc_cpu
decl_stmt|;
name|bus_space_tag_t
name|sc_iot
decl_stmt|;
name|bus_space_handle_t
name|sc_intctl_ioh
decl_stmt|;
name|bus_space_handle_t
name|sc_gpio_ioh
decl_stmt|;
comment|/* GPIO */
name|bus_space_handle_t
name|sc_clkman_ioh
decl_stmt|;
comment|/* Clock manager */
name|bus_space_handle_t
name|sc_wdt_ioh
decl_stmt|;
comment|/* Watchdog Timer */
name|bus_dma_tag_t
name|sc_dmat
decl_stmt|;
comment|/* clock frequency */
name|int
name|sc_fclk
decl_stmt|;
comment|/* CPU clock */
name|int
name|sc_hclk
decl_stmt|;
comment|/* AHB bus clock */
name|int
name|sc_pclk
decl_stmt|;
comment|/* peripheral clock */
name|struct
name|rman
name|s3c2xx0_irq_rman
decl_stmt|;
name|struct
name|rman
name|s3c2xx0_mem_rman
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s3c2xx0_ivar
block|{
name|struct
name|resource_list
name|resources
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|void
modifier|*
name|s3c2xx0_chipset_tag_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|struct
name|bus_space
name|s3c2xx0_bs_tag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|s3c2xx0_softc
modifier|*
name|s3c2xx0_softc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|arm32_bus_dma_tag
name|s3c2xx0_bus_dma
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Platform needs to provide this */
end_comment

begin_function_decl
name|bus_dma_tag_t
name|s3c2xx0_bus_dma_init
parameter_list|(
name|struct
name|arm32_bus_dma_tag
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_S3C2XX0VAR_H_ */
end_comment

end_unit

