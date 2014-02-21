begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2006 John-Mark Gurney.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__BUS_DMA_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__BUS_DMA_H_
end_define

begin_typedef
typedef|typedef
name|int
name|bus_dmasync_op_t
typedef|;
end_typedef

begin_comment
comment|/*  *	bus_dma_tag_t  *  *	A machine-dependent opaque type describing the characteristics  *	of how to perform DMA mappings.  This structure encapsultes  *	information concerning address and alignment restrictions, number  *	of S/G segments, amount of data per S/G segment, etc.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bus_dma_tag
modifier|*
name|bus_dma_tag_t
typedef|;
end_typedef

begin_comment
comment|/*  *	bus_dmamap_t  *  *	DMA mapping instance information.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|bus_dmamap
modifier|*
name|bus_dmamap_t
typedef|;
end_typedef

begin_comment
comment|/*  * A function that performs driver-specific synchronization on behalf of  * busdma.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BUS_DMA_LOCK
init|=
literal|0x01
block|,
name|BUS_DMA_UNLOCK
init|=
literal|0x02
block|, }
name|bus_dma_lock_op_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
name|bus_dma_lock_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_dma_lock_op_t
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__BUS_DMA_H_ */
end_comment

end_unit

