begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Daisuke Aoyama<aoyama@peach.ne.jp>  * Copyright (c) 2013 Oleksandr Tymoshenko<gonzo@bluezbox.com>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BCM2835_DMA_H_
end_ifndef

begin_define
define|#
directive|define
name|_BCM2835_DMA_H_
end_define

begin_define
define|#
directive|define
name|BCM_DMA_BLOCK_SIZE
value|512
end_define

begin_comment
comment|/* DMA0-DMA15 but DMA15 is special */
end_comment

begin_define
define|#
directive|define
name|BCM_DMA_CH_MAX
value|12
end_define

begin_comment
comment|/* request CH for any nubmer */
end_comment

begin_define
define|#
directive|define
name|BCM_DMA_CH_INVALID
value|(-1)
end_define

begin_define
define|#
directive|define
name|BCM_DMA_CH_ANY
value|(-1)
end_define

begin_comment
comment|/* Peripheral DREQ Signals (4.2.1.3) */
end_comment

begin_define
define|#
directive|define
name|BCM_DMA_DREQ_NONE
value|0
end_define

begin_define
define|#
directive|define
name|BCM_DMA_DREQ_EMMC
value|11
end_define

begin_define
define|#
directive|define
name|BCM_DMA_DREQ_SDHOST
value|13
end_define

begin_define
define|#
directive|define
name|BCM_DMA_SAME_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|BCM_DMA_INC_ADDR
value|1
end_define

begin_define
define|#
directive|define
name|BCM_DMA_32BIT
value|0
end_define

begin_define
define|#
directive|define
name|BCM_DMA_128BIT
value|1
end_define

begin_function_decl
name|int
name|bcm_dma_allocate
parameter_list|(
name|int
name|req_ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcm_dma_free
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcm_dma_setup_intr
parameter_list|(
name|int
name|ch
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcm_dma_setup_src
parameter_list|(
name|int
name|ch
parameter_list|,
name|int
name|dreq
parameter_list|,
name|int
name|inc_addr
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcm_dma_setup_dst
parameter_list|(
name|int
name|ch
parameter_list|,
name|int
name|dreq
parameter_list|,
name|int
name|inc_addr
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bcm_dma_start
parameter_list|(
name|int
name|ch
parameter_list|,
name|vm_paddr_t
name|src
parameter_list|,
name|vm_paddr_t
name|dst
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bcm_dma_length
parameter_list|(
name|int
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BCM2835_DMA_H_ */
end_comment

end_unit

