begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2017-2018 Cavium, Inc.   * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ECORE_UTILS_H__
end_ifndef

begin_define
define|#
directive|define
name|__ECORE_UTILS_H__
end_define

begin_comment
comment|/* dma_addr_t manip */
end_comment

begin_comment
comment|/* Suppress "right shift count>= width of type" warning when that quantity is  * 32-bits rquires the>> 16)>> 16)  */
end_comment

begin_define
define|#
directive|define
name|PTR_LO
parameter_list|(
name|x
parameter_list|)
value|((u32)(((osal_uintptr_t)(x))& 0xffffffff))
end_define

begin_define
define|#
directive|define
name|PTR_HI
parameter_list|(
name|x
parameter_list|)
value|((u32)((((osal_uintptr_t)(x))>> 16)>> 16))
end_define

begin_define
define|#
directive|define
name|DMA_LO
parameter_list|(
name|x
parameter_list|)
value|((u32)(((dma_addr_t)(x))& 0xffffffff))
end_define

begin_define
define|#
directive|define
name|DMA_HI
parameter_list|(
name|x
parameter_list|)
value|((u32)(((dma_addr_t)(x))>> 32))
end_define

begin_define
define|#
directive|define
name|DMA_LO_LE
parameter_list|(
name|x
parameter_list|)
value|OSAL_CPU_TO_LE32(DMA_LO(x))
end_define

begin_define
define|#
directive|define
name|DMA_HI_LE
parameter_list|(
name|x
parameter_list|)
value|OSAL_CPU_TO_LE32(DMA_HI(x))
end_define

begin_comment
comment|/* It's assumed that whoever includes this has previously included an hsi  * file defining the regpair.  */
end_comment

begin_define
define|#
directive|define
name|DMA_REGPAIR_LE
parameter_list|(
name|x
parameter_list|,
name|val
parameter_list|)
value|(x).hi = DMA_HI_LE((val)); \ 				(x).lo = DMA_LO_LE((val))
end_define

begin_define
define|#
directive|define
name|HILO_GEN
parameter_list|(
name|hi
parameter_list|,
name|lo
parameter_list|,
name|type
parameter_list|)
value|((((type)(hi))<< 32) + (lo))
end_define

begin_define
define|#
directive|define
name|HILO_DMA
parameter_list|(
name|hi
parameter_list|,
name|lo
parameter_list|)
value|HILO_GEN(hi, lo, dma_addr_t)
end_define

begin_define
define|#
directive|define
name|HILO_64
parameter_list|(
name|hi
parameter_list|,
name|lo
parameter_list|)
value|HILO_GEN(hi, lo, u64)
end_define

begin_define
define|#
directive|define
name|HILO_DMA_REGPAIR
parameter_list|(
name|regpair
parameter_list|)
value|(HILO_DMA(regpair.hi, regpair.lo))
end_define

begin_define
define|#
directive|define
name|HILO_64_REGPAIR
parameter_list|(
name|regpair
parameter_list|)
value|(HILO_64(regpair.hi, regpair.lo))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

