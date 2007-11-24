begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2005 HighPoint Technologies, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_RAID5N_
end_ifdef

begin_comment
comment|/* OS provided function, call only at initialization time */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|HPTLIBAPI
name|os_alloc_page
parameter_list|(
name|_VBUS_ARG0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* may be cached memory */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|HPTLIBAPI
name|os_alloc_dma_page
parameter_list|(
name|_VBUS_ARG0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* must be non-cached memory */
end_comment

begin_comment
comment|/* implement if the driver can be unloaded */
end_comment

begin_function_decl
name|void
name|HPTLIBAPI
name|os_free_page
parameter_list|(
name|_VBUS_ARG
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|os_free_dma_page
parameter_list|(
name|_VBUS_ARG
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|xfer_done_fn
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|void
modifier|*
name|tag
parameter_list|,
name|int
name|result
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|DATAXFER_STACK_VAR
end_define

begin_define
define|#
directive|define
name|DATAXFER_INIT_ARG
value|0
end_define

begin_define
define|#
directive|define
name|dataxfer_init
parameter_list|(
name|arg
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|dataxfer_add_item
parameter_list|(
name|handle
parameter_list|,
name|host
parameter_list|,
name|cache
parameter_list|,
name|bytes
parameter_list|,
name|tocache
parameter_list|)
define|\
value|if (tocache) memcpy((PUCHAR)(cache), (PUCHAR)(host), bytes); \ 		else memcpy((PUCHAR)(host), (PUCHAR)(cache), bytes)
end_define

begin_define
define|#
directive|define
name|dataxfer_exec
parameter_list|(
name|handle
parameter_list|,
name|done
parameter_list|,
name|tag
parameter_list|)
value|done(_VBUS_P tag, 0)
end_define

begin_define
define|#
directive|define
name|dataxfer_poll
parameter_list|()
end_define

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|HPTLIBAPI
name|xor_done_fn
function_decl|)
parameter_list|(
name|_VBUS_ARG
name|void
modifier|*
name|tag
parameter_list|,
name|int
name|result
parameter_list|)
function_decl|;
end_typedef

begin_define
define|#
directive|define
name|XOR_STACK_VAR
end_define

begin_define
define|#
directive|define
name|XOR_INIT_ARG
value|0
end_define

begin_comment
comment|/* DoXor1, DoXor2 provided by platform dependent code */
end_comment

begin_function_decl
name|void
name|HPTLIBAPI
name|DoXor1
parameter_list|(
name|ULONG
modifier|*
name|p0
parameter_list|,
name|ULONG
modifier|*
name|p1
parameter_list|,
name|ULONG
modifier|*
name|p2
parameter_list|,
name|UINT
name|nBytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HPTLIBAPI
name|DoXor2
parameter_list|(
name|ULONG
modifier|*
name|p0
parameter_list|,
name|ULONG
modifier|*
name|p2
parameter_list|,
name|UINT
name|nBytes
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|max_xor_way
value|2
end_define

begin_define
define|#
directive|define
name|xor_init
parameter_list|(
name|arg
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|xor_add_item
parameter_list|(
name|handle
parameter_list|,
name|dest
parameter_list|,
name|src
parameter_list|,
name|nsrc
parameter_list|,
name|bytes
parameter_list|)
define|\
value|do {\ 		if (((void**)src)[0]==dest)\ 			DoXor2((PULONG)(dest), ((PULONG *)src)[1], bytes);\ 		else\ 			DoXor1((PULONG)(dest), ((PULONG *)src)[0], ((PULONG *)src)[1], bytes);\ 	} while(0)
end_define

begin_define
define|#
directive|define
name|xor_exec
parameter_list|(
name|handle
parameter_list|,
name|done
parameter_list|,
name|tag
parameter_list|)
value|done(_VBUS_P tag, 0)
end_define

begin_define
define|#
directive|define
name|xor_poll
parameter_list|()
end_define

begin_comment
comment|/* set before calling init_raid5_memory */
end_comment

begin_decl_stmt
specifier|extern
name|UINT
name|num_raid5_pages
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* called by init.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|HPTLIBAPI
name|init_raid5_memory
parameter_list|(
name|_VBUS_ARG0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HPTLIBAPI
name|free_raid5_memory
parameter_list|(
name|_VBUS_ARG0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* asynchronous flush, may be called periodly */
end_comment

begin_function_decl
specifier|extern
name|void
name|HPTLIBAPI
name|flush_stripe_cache
parameter_list|(
name|_VBUS_ARG0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HPTLIBAPI
name|flush_raid5_async
parameter_list|(
name|PVDevice
name|pArray
parameter_list|,
name|DPC_PROC
name|done
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* synchronous function called at shutdown */
end_comment

begin_function_decl
specifier|extern
name|int
name|HPTLIBAPI
name|flush_raid5
parameter_list|(
name|PVDevice
name|pArray
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HPTLIBAPI
name|raid5_free
parameter_list|(
name|_VBUS_ARG
name|PVDevice
name|pArray
parameter_list|)
function_decl|;
end_function_decl

begin_struct
struct|struct
name|free_heap_block
block|{
name|struct
name|free_heap_block
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|LIST_H_INCLUDED
end_ifndef

begin_struct
struct|struct
name|list_head
block|{
name|struct
name|list_head
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|free_page
block|{
name|struct
name|free_page
modifier|*
name|link
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|r5_global_data
block|{
name|int
name|enable_write_back
decl_stmt|;
name|struct
name|list_head
name|inactive_list
decl_stmt|;
name|struct
name|list_head
name|dirty_list
decl_stmt|;
name|struct
name|list_head
name|active_list
decl_stmt|;
ifdef|#
directive|ifdef
name|R5_CONTIG_CACHE
name|BUS_ADDR
name|page_base_phys
decl_stmt|;
name|PUCHAR
name|page_base_virt
decl_stmt|;
name|PUCHAR
name|page_current
decl_stmt|;
endif|#
directive|endif
name|struct
name|free_heap_block
modifier|*
name|free_heap_slots
index|[
literal|10
index|]
decl_stmt|;
name|struct
name|free_page
modifier|*
name|free_pages
decl_stmt|;
name|UINT
name|num_free_pages
decl_stmt|;
name|UINT
name|active_stripes
decl_stmt|;
name|UINT
name|num_flushing
decl_stmt|;
name|PCommand
name|cache_wait_list
decl_stmt|;
name|LBA_T
name|__start
index|[
name|MAX_MEMBERS
index|]
decl_stmt|;
name|USHORT
name|__sectors
index|[
name|MAX_MEMBERS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

end_unit

