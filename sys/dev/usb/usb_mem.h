begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: usb_mem.h,v 1.18 2002/05/28 17:45:17 augustss Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Lennart Augustsson (lennart@augustsson.net) at  * Carlstedt Research& Technology.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *        This product includes software developed by the NetBSD  *        Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|usb_dma_block
block|{
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
ifdef|#
directive|ifdef
name|__FreeBSD__
name|void
modifier|*
name|kaddr
decl_stmt|;
else|#
directive|else
name|caddr_t
name|kaddr
decl_stmt|;
endif|#
directive|endif
name|bus_dma_segment_t
name|segs
index|[
literal|1
index|]
decl_stmt|;
name|int
name|nsegs
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|size_t
name|align
decl_stmt|;
name|int
name|fullblock
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|usb_dma_block
argument_list|)
name|next
expr_stmt|;
block|}
name|usb_dma_block_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_define
define|#
directive|define
name|DMAADDR
parameter_list|(
name|dma
parameter_list|,
name|o
parameter_list|)
value|((dma)->block->segs[0].ds_addr + (dma)->offs + (o))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DMAADDR
parameter_list|(
name|dma
parameter_list|,
name|o
parameter_list|)
value|(((char *)(dma)->block->map->dm_segs[0].ds_addr) + (dma)->offs + (o))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KERNADDR
parameter_list|(
name|dma
parameter_list|,
name|o
parameter_list|)
define|\
value|((void *)((char *)((dma)->block->kaddr) + (dma)->offs + (o)))
end_define

begin_function_decl
name|usbd_status
name|usb_allocmem
parameter_list|(
name|usbd_bus_handle
parameter_list|,
name|size_t
parameter_list|,
name|size_t
parameter_list|,
name|usb_dma_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|usb_freemem
parameter_list|(
name|usbd_bus_handle
parameter_list|,
name|usb_dma_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

