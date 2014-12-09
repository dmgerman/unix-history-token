begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * This software was developed by SRI International and the University of  * Cambridge Computer Laboratory under DARPA/AFRL contract (FA8750-10-C-0237)  * ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_define
define|#
directive|define
name|READ2
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
define|\
value|bus_read_2((_sc)->res[0], _reg)
end_define

begin_define
define|#
directive|define
name|READ4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|)
define|\
value|bus_read_4((_sc)->res[0], _reg)
end_define

begin_define
define|#
directive|define
name|WRITE2
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_write_2((_sc)->res[0], _reg, _val)
end_define

begin_define
define|#
directive|define
name|WRITE4
parameter_list|(
name|_sc
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_write_4((_sc)->res[0], _reg, _val)
end_define

begin_define
define|#
directive|define
name|PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|VRING_ALIGN
value|4096
end_define

begin_define
define|#
directive|define
name|VQ_ALLOC
value|0x01
end_define

begin_comment
comment|/* set once we have a pfn */
end_comment

begin_define
define|#
directive|define
name|VQ_MAX_DESCRIPTORS
value|512
end_define

begin_struct
struct|struct
name|vqueue_info
block|{
name|uint16_t
name|vq_qsize
decl_stmt|;
comment|/* size of this queue (a power of 2) */
name|uint16_t
name|vq_num
decl_stmt|;
name|uint16_t
name|vq_flags
decl_stmt|;
name|uint16_t
name|vq_last_avail
decl_stmt|;
comment|/* a recent value of vq_avail->va_idx */
name|uint16_t
name|vq_save_used
decl_stmt|;
comment|/* saved vq_used->vu_idx; see vq_endchains */
name|uint32_t
name|vq_pfn
decl_stmt|;
comment|/* PFN of virt queue (not shifted!) */
specifier|volatile
name|struct
name|vring_desc
modifier|*
name|vq_desc
decl_stmt|;
comment|/* descriptor array */
specifier|volatile
name|struct
name|vring_avail
modifier|*
name|vq_avail
decl_stmt|;
comment|/* the "avail" ring */
specifier|volatile
name|struct
name|vring_used
modifier|*
name|vq_used
decl_stmt|;
comment|/* the "used" ring */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|vq_ring_ready
parameter_list|(
name|struct
name|vqueue_info
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vq_has_descs
parameter_list|(
name|struct
name|vqueue_info
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|paddr_map
parameter_list|(
name|uint32_t
name|offset
parameter_list|,
name|uint32_t
name|phys
parameter_list|,
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|paddr_unmap
parameter_list|(
name|void
modifier|*
name|phys
parameter_list|,
name|uint32_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vq_getchain
parameter_list|(
name|uint32_t
name|beri_mem_offset
parameter_list|,
name|struct
name|vqueue_info
modifier|*
name|vq
parameter_list|,
name|struct
name|iovec
modifier|*
name|iov
parameter_list|,
name|int
name|n_iov
parameter_list|,
name|uint16_t
modifier|*
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vq_relchain
parameter_list|(
name|struct
name|vqueue_info
modifier|*
name|vq
parameter_list|,
name|struct
name|iovec
modifier|*
name|iov
parameter_list|,
name|int
name|n
parameter_list|,
name|uint32_t
name|iolen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setup_pio
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|device_t
modifier|*
name|pio_dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setup_offset
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint32_t
modifier|*
name|offset
parameter_list|)
function_decl|;
end_function_decl

end_unit

