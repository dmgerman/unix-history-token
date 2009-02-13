begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: bus.h,v 1.11 2003/07/28 17:35:54 thorpej Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996, 1997, 1998, 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996 Charles M. Hannum.  All rights reserved.  * Copyright (c) 1996 Christopher G. Demetriou.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_BUS_DMA_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_BUS_DMA_H
end_define

begin_include
include|#
directive|include
file|<sys/bus_dma.h>
end_include

begin_comment
comment|/* Bus Space DMA macros */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_TAG_VALID
parameter_list|(
name|t
parameter_list|)
value|((t) != (bus_dma_tag_t)0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_ARM32_BUS_DMA_PRIVATE
end_ifdef

begin_comment
comment|/*  *	arm32_dma_range  *  *	This structure describes a valid DMA range.  */
end_comment

begin_struct
struct|struct
name|arm32_dma_range
block|{
name|bus_addr_t
name|dr_sysbase
decl_stmt|;
comment|/* system base address */
name|bus_addr_t
name|dr_busbase
decl_stmt|;
comment|/* appears here on bus */
name|bus_size_t
name|dr_len
decl_stmt|;
comment|/* length of range */
block|}
struct|;
end_struct

begin_comment
comment|/* _dm_buftype */
end_comment

begin_define
define|#
directive|define
name|ARM32_BUFTYPE_INVALID
value|0
end_define

begin_define
define|#
directive|define
name|ARM32_BUFTYPE_LINEAR
value|1
end_define

begin_define
define|#
directive|define
name|ARM32_BUFTYPE_MBUF
value|2
end_define

begin_define
define|#
directive|define
name|ARM32_BUFTYPE_UIO
value|3
end_define

begin_define
define|#
directive|define
name|ARM32_BUFTYPE_RAW
value|4
end_define

begin_function_decl
name|struct
name|arm32_dma_range
modifier|*
name|bus_dma_get_range
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_dma_get_range_nb
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|bus_dma_tag_t
name|arm_root_dma_tag
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM32_BUS_DMA_PRIVATE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_BUS_DMA_H */
end_comment

end_unit

