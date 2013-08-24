begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  */
end_comment

begin_comment
comment|/*  * This implements pools of DMA-able buffers that conserve DMA address space  * by putting several buffers into one page and that allow to map between  * 32-bit handles for the buffer and buffer addresses (to use 32-bit network  * interfaces on 64bit machines). This assists network interfaces that may need  * huge numbers of mbufs.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MBPOOL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MBPOOL_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* opaque */
end_comment

begin_struct_decl
struct_decl|struct
name|mbpool
struct_decl|;
end_struct_decl

begin_comment
comment|/* size of reserved area at end of each chunk */
end_comment

begin_define
define|#
directive|define
name|MBPOOL_TRAILER_SIZE
value|4
end_define

begin_comment
comment|/* maximum value of max_pages */
end_comment

begin_define
define|#
directive|define
name|MBPOOL_MAX_MAXPAGES
value|((1<< 14) - 1)
end_define

begin_comment
comment|/* maximum number of chunks per page */
end_comment

begin_define
define|#
directive|define
name|MBPOOL_MAX_CHUNKS
value|(1<< 9)
end_define

begin_comment
comment|/* initialize a pool */
end_comment

begin_function_decl
name|int
name|mbp_create
parameter_list|(
name|struct
name|mbpool
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|bus_dma_tag_t
parameter_list|,
name|u_int
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* destroy a pool */
end_comment

begin_function_decl
name|void
name|mbp_destroy
parameter_list|(
name|struct
name|mbpool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* allocate a chunk and set used and on card */
end_comment

begin_function_decl
name|void
modifier|*
name|mbp_alloc
parameter_list|(
name|struct
name|mbpool
modifier|*
parameter_list|,
name|bus_addr_t
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* free a chunk */
end_comment

begin_function_decl
name|void
name|mbp_free
parameter_list|(
name|struct
name|mbpool
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* free a chunk that is an external mbuf */
end_comment

begin_function_decl
name|void
name|mbp_ext_free
parameter_list|(
name|struct
name|mbuf
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* free all buffers that are marked to be on the card */
end_comment

begin_function_decl
name|void
name|mbp_card_free
parameter_list|(
name|struct
name|mbpool
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* count used buffers and buffers on card */
end_comment

begin_function_decl
name|void
name|mbp_count
parameter_list|(
name|struct
name|mbpool
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get the buffer from a handle and clear card bit */
end_comment

begin_function_decl
name|void
modifier|*
name|mbp_get
parameter_list|(
name|struct
name|mbpool
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* get the buffer from a handle and don't clear card bit */
end_comment

begin_function_decl
name|void
modifier|*
name|mbp_get_keep
parameter_list|(
name|struct
name|mbpool
modifier|*
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sync the chunk */
end_comment

begin_function_decl
name|void
name|mbp_sync
parameter_list|(
name|struct
name|mbpool
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|bus_addr_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_MBPOOL_H_ */
end_comment

end_unit

