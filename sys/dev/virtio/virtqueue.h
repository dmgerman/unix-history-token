begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011, Bryan Venteicher<bryanv@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VIRTIO_VIRTQUEUE_H
end_ifndef

begin_define
define|#
directive|define
name|_VIRTIO_VIRTQUEUE_H
end_define

begin_struct_decl
struct_decl|struct
name|virtqueue
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sglist
struct_decl|;
end_struct_decl

begin_comment
comment|/* Device callback for a virtqueue interrupt. */
end_comment

begin_typedef
typedef|typedef
name|void
name|virtqueue_intr_t
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Hint on how long the next interrupt should be postponed. This is  * only used when the EVENT_IDX feature is negotiated.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|VQ_POSTPONE_SHORT
block|,
name|VQ_POSTPONE_LONG
block|,
name|VQ_POSTPONE_EMPTIED
comment|/* Until all available desc are used. */
block|}
name|vq_postpone_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VIRTQUEUE_MAX_NAME_SZ
value|32
end_define

begin_comment
comment|/* One for each virtqueue the device wishes to allocate. */
end_comment

begin_struct
struct|struct
name|vq_alloc_info
block|{
name|char
name|vqai_name
index|[
name|VIRTQUEUE_MAX_NAME_SZ
index|]
decl_stmt|;
name|int
name|vqai_maxindirsz
decl_stmt|;
name|virtqueue_intr_t
modifier|*
name|vqai_intr
decl_stmt|;
name|void
modifier|*
name|vqai_intr_arg
decl_stmt|;
name|struct
name|virtqueue
modifier|*
modifier|*
name|vqai_vq
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VQ_ALLOC_INFO_INIT
parameter_list|(
name|_i
parameter_list|,
name|_nsegs
parameter_list|,
name|_intr
parameter_list|,
name|_arg
parameter_list|,
name|_vqp
parameter_list|,
name|_str
parameter_list|,
modifier|...
parameter_list|)
value|do {	\ 	snprintf((_i)->vqai_name, VIRTQUEUE_MAX_NAME_SZ, _str,		\ 	    ##__VA_ARGS__);						\ 	(_i)->vqai_maxindirsz = (_nsegs);				\ 	(_i)->vqai_intr = (_intr);					\ 	(_i)->vqai_intr_arg = (_arg);					\ 	(_i)->vqai_vq = (_vqp);						\ } while (0)
end_define

begin_function_decl
name|uint64_t
name|virtqueue_filter_features
parameter_list|(
name|uint64_t
name|features
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtqueue_alloc
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|uint16_t
name|queue
parameter_list|,
name|uint16_t
name|size
parameter_list|,
name|int
name|align
parameter_list|,
name|vm_paddr_t
name|highaddr
parameter_list|,
name|struct
name|vq_alloc_info
modifier|*
name|info
parameter_list|,
name|struct
name|virtqueue
modifier|*
modifier|*
name|vqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|virtqueue_drain
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|,
name|int
modifier|*
name|last
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virtqueue_free
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtqueue_reinit
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|,
name|uint16_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtqueue_intr_filter
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virtqueue_intr
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtqueue_enable_intr
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtqueue_postpone_intr
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|,
name|vq_postpone_t
name|hint
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virtqueue_disable_intr
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get physical address of the virtqueue ring. */
end_comment

begin_function_decl
name|vm_paddr_t
name|virtqueue_paddr
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtqueue_full
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtqueue_empty
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtqueue_size
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtqueue_nfree
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtqueue_nused
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virtqueue_notify
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|virtqueue_dump
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|virtqueue_enqueue
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|,
name|struct
name|sglist
modifier|*
name|sg
parameter_list|,
name|int
name|readable
parameter_list|,
name|int
name|writable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|virtqueue_dequeue
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|,
name|uint32_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|virtqueue_poll
parameter_list|(
name|struct
name|virtqueue
modifier|*
name|vq
parameter_list|,
name|uint32_t
modifier|*
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VIRTIO_VIRTQUEUE_H */
end_comment

end_unit

