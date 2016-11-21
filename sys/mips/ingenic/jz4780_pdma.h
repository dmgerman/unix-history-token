begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract FA8750-10-C-0237  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* DMA Channel Registers */
end_comment

begin_define
define|#
directive|define
name|PDMA_DSA
parameter_list|(
name|n
parameter_list|)
value|(0x00 + 0x20 * n)
end_define

begin_comment
comment|/* Channel n Source Address */
end_comment

begin_define
define|#
directive|define
name|PDMA_DTA
parameter_list|(
name|n
parameter_list|)
value|(0x04 + 0x20 * n)
end_define

begin_comment
comment|/* Channel n Target Address */
end_comment

begin_define
define|#
directive|define
name|PDMA_DTC
parameter_list|(
name|n
parameter_list|)
value|(0x08 + 0x20 * n)
end_define

begin_comment
comment|/* Channel n Transfer Count */
end_comment

begin_define
define|#
directive|define
name|PDMA_DRT
parameter_list|(
name|n
parameter_list|)
value|(0x0C + 0x20 * n)
end_define

begin_comment
comment|/* Channel n Request Source */
end_comment

begin_define
define|#
directive|define
name|PDMA_DCS
parameter_list|(
name|n
parameter_list|)
value|(0x10 + 0x20 * n)
end_define

begin_comment
comment|/* Channel n Control/Status */
end_comment

begin_define
define|#
directive|define
name|PDMA_DCM
parameter_list|(
name|n
parameter_list|)
value|(0x14 + 0x20 * n)
end_define

begin_comment
comment|/* Channel n Command */
end_comment

begin_define
define|#
directive|define
name|PDMA_DDA
parameter_list|(
name|n
parameter_list|)
value|(0x18 + 0x20 * n)
end_define

begin_comment
comment|/* Channel n Descriptor Address */
end_comment

begin_define
define|#
directive|define
name|PDMA_DSD
parameter_list|(
name|n
parameter_list|)
value|(0x1C + 0x20 * n)
end_define

begin_comment
comment|/* Channel n Stride Difference */
end_comment

begin_comment
comment|/* Global Control Registers */
end_comment

begin_define
define|#
directive|define
name|PDMA_DMAC
value|0x1000
end_define

begin_comment
comment|/* DMA Control */
end_comment

begin_define
define|#
directive|define
name|PDMA_DIRQP
value|0x1004
end_define

begin_comment
comment|/* DMA Interrupt Pending */
end_comment

begin_define
define|#
directive|define
name|PDMA_DDB
value|0x1008
end_define

begin_comment
comment|/* DMA Doorbell */
end_comment

begin_define
define|#
directive|define
name|PDMA_DDS
value|0x100C
end_define

begin_comment
comment|/* DMA Doorbell Set */
end_comment

begin_define
define|#
directive|define
name|PDMA_DIP
value|0x1010
end_define

begin_comment
comment|/* Descriptor Interrupt Pending */
end_comment

begin_define
define|#
directive|define
name|PDMA_DIC
value|0x1014
end_define

begin_comment
comment|/* Descriptor Interrupt Clear */
end_comment

begin_define
define|#
directive|define
name|PDMA_DMACP
value|0x101C
end_define

begin_comment
comment|/* DMA Channel Programmable */
end_comment

begin_define
define|#
directive|define
name|PDMA_DSIRQP
value|0x1020
end_define

begin_comment
comment|/* Channel soft IRQ to MCU */
end_comment

begin_define
define|#
directive|define
name|PDMA_DSIRQM
value|0x1024
end_define

begin_comment
comment|/* Channel soft IRQ mask */
end_comment

begin_define
define|#
directive|define
name|PDMA_DCIRQP
value|0x1028
end_define

begin_comment
comment|/* Channel IRQ to MCU */
end_comment

begin_define
define|#
directive|define
name|PDMA_DCIRQM
value|0x102C
end_define

begin_comment
comment|/* Channel IRQ to MCU mask */
end_comment

begin_define
define|#
directive|define
name|PDMA_DMCS
value|0x1030
end_define

begin_comment
comment|/* MCU Control and Status */
end_comment

begin_define
define|#
directive|define
name|PDMA_DMNMB
value|0x1034
end_define

begin_comment
comment|/* MCU Normal Mailbox */
end_comment

begin_define
define|#
directive|define
name|PDMA_DMSMB
value|0x1038
end_define

begin_comment
comment|/* MCU Security Mailbox */
end_comment

begin_define
define|#
directive|define
name|PDMA_DMINT
value|0x103C
end_define

begin_comment
comment|/* MCU Interrupt */
end_comment

begin_struct
struct|struct
name|pdma_hwdesc
block|{
name|uint32_t
name|dcm
decl_stmt|;
comment|/* DMA Channel Command */
name|uint32_t
name|dsa
decl_stmt|;
comment|/* DMA Source Address */
name|uint32_t
name|dta
decl_stmt|;
comment|/* DMA Target Address */
name|uint32_t
name|dtc
decl_stmt|;
comment|/* DMA Transfer Counter */
name|uint32_t
name|sd
decl_stmt|;
comment|/* Stride Address */
name|uint32_t
name|drt
decl_stmt|;
comment|/* DMA Request Type */
name|uint32_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

