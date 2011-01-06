begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2010 Nathan Whitehorn  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PS3_LV1CALL_H
end_ifndef

begin_define
define|#
directive|define
name|_PS3_LV1CALL_H
end_define

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_function_decl
name|int
name|lv1_get_physmem
parameter_list|(
name|uint64_t
modifier|*
name|maxmem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_setup_address_space
parameter_list|(
name|uint64_t
modifier|*
name|as_id
parameter_list|,
name|uint64_t
modifier|*
name|ptsize
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_insert_pte
parameter_list|(
name|u_int
name|ptegidx
parameter_list|,
name|struct
name|lpte
modifier|*
name|pte
parameter_list|,
name|int
name|lockflags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_panic
parameter_list|(
name|int
name|reboot
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|L1GPU_CONTEXT_ATTRIBUTE_DISPLAY_MODE_SET
value|0x0100
end_define

begin_define
define|#
directive|define
name|L1GPU_CONTEXT_ATTRIBUTE_DISPLAY_SYNC
value|0x0101
end_define

begin_define
define|#
directive|define
name|L1GPU_DISPLAY_SYNC_HSYNC
value|1
end_define

begin_define
define|#
directive|define
name|L1GPU_DISPLAY_SYNC_VSYNC
value|2
end_define

begin_define
define|#
directive|define
name|L1GPU_CONTEXT_ATTRIBUTE_DISPLAY_FLIP
value|0x0102
end_define

begin_function_decl
name|int
name|lv1_gpu_open
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_gpu_context_attribute
parameter_list|(
name|int
name|context
parameter_list|,
name|int
name|op
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_gpu_memory_allocate
parameter_list|(
name|int
name|size
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint64_t
modifier|*
name|handle
parameter_list|,
name|uint64_t
modifier|*
name|paddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_gpu_context_allocate
parameter_list|(
name|uint64_t
name|handle
parameter_list|,
name|int
parameter_list|,
name|uint64_t
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_open_device
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
comment|/* 0 */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_close_device
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_setup_dma
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|uint64_t
modifier|*
name|dmabase
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GELIC_GET_MAC_ADDRESS
value|0x0001
end_define

begin_define
define|#
directive|define
name|GELIC_GET_LINK_STATUS
value|0x0002
end_define

begin_define
define|#
directive|define
name|GELIC_LINK_UP
value|0x0001
end_define

begin_define
define|#
directive|define
name|GELIC_FULL_DUPLEX
value|0x0002
end_define

begin_define
define|#
directive|define
name|GELIC_AUTO_NEG
value|0x0004
end_define

begin_define
define|#
directive|define
name|GELIC_SPEED_10
value|0x0010
end_define

begin_define
define|#
directive|define
name|GELIC_SPEED_100
value|0x0020
end_define

begin_define
define|#
directive|define
name|GELIC_SPEED_1000
value|0x0040
end_define

begin_define
define|#
directive|define
name|GELIC_GET_VLAN_ID
value|0x0004
end_define

begin_function_decl
name|int
name|lv1_net_init
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_net_control
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|uint64_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_net_start_tx_dma
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_net_start_rx_dma
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|uint32_t
name|addr
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_net_stop_tx_dma
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lv1_net_stop_rx_dma
parameter_list|(
name|int
name|bus
parameter_list|,
name|int
name|dev
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

