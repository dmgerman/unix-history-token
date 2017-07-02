begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: bus.h,v 1.12 1997/10/01 08:25:15 fvdl Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996, 1997 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996 Charles M. Hannum.  All rights reserved.  * Copyright (c) 1996 Christopher G. Demetriou.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Christopher G. Demetriou  *	for the NetBSD Project.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BUS_DMA_H_
end_ifndef

begin_define
define|#
directive|define
name|_BUS_DMA_H_
end_define

begin_include
include|#
directive|include
file|<sys/_bus_dma.h>
end_include

begin_comment
comment|/*  * Machine independent interface for mapping physical addresses to peripheral  * bus 'physical' addresses, and assisting with DMA operations.  *  * XXX This file is always included from<machine/bus_dma.h> and should not  *     (yet) be included directly.  */
end_comment

begin_comment
comment|/*  * Flags used in various bus DMA methods.  */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_WAITOK
value|0x00
end_define

begin_comment
comment|/* safe to sleep (pseudo-flag) */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_NOWAIT
value|0x01
end_define

begin_comment
comment|/* not safe to sleep */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_ALLOCNOW
value|0x02
end_define

begin_comment
comment|/* perform resource allocation now */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_COHERENT
value|0x04
end_define

begin_comment
comment|/* hint: map memory in a coherent way */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_ZERO
value|0x08
end_define

begin_comment
comment|/* allocate zero'ed memory */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_BUS1
value|0x10
end_define

begin_comment
comment|/* placeholders for bus functions... */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_BUS2
value|0x20
end_define

begin_define
define|#
directive|define
name|BUS_DMA_BUS3
value|0x40
end_define

begin_define
define|#
directive|define
name|BUS_DMA_BUS4
value|0x80
end_define

begin_comment
comment|/*  * The following two flags are non-standard or specific to only certain  * architectures  */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_NOWRITE
value|0x100
end_define

begin_define
define|#
directive|define
name|BUS_DMA_NOCACHE
value|0x200
end_define

begin_comment
comment|/*  * The following flag is a DMA tag hint that the page offset of the  * loaded kernel virtual address must be preserved in the first  * physical segment address, when the KVA is loaded into DMA.  */
end_comment

begin_define
define|#
directive|define
name|BUS_DMA_KEEP_PG_OFFSET
value|0x400
end_define

begin_define
define|#
directive|define
name|BUS_DMA_LOAD_MBUF
value|0x800
end_define

begin_comment
comment|/* Forwards needed by prototypes below. */
end_comment

begin_union_decl
union_decl|union
name|ccb
union_decl|;
end_union_decl

begin_struct_decl
struct_decl|struct
name|bio
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|memdesc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|uio
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Operations performed by bus_dmamap_sync().  */
end_comment

begin_define
define|#
directive|define
name|BUS_DMASYNC_PREREAD
value|1
end_define

begin_define
define|#
directive|define
name|BUS_DMASYNC_POSTREAD
value|2
end_define

begin_define
define|#
directive|define
name|BUS_DMASYNC_PREWRITE
value|4
end_define

begin_define
define|#
directive|define
name|BUS_DMASYNC_POSTWRITE
value|8
end_define

begin_comment
comment|/*  *	bus_dma_segment_t  *  *	Describes a single contiguous DMA transaction.  Values  *	are suitable for programming into DMA registers.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|bus_dma_segment
block|{
name|bus_addr_t
name|ds_addr
decl_stmt|;
comment|/* DMA address */
name|bus_size_t
name|ds_len
decl_stmt|;
comment|/* length of transfer */
block|}
name|bus_dma_segment_t
typedef|;
end_typedef

begin_comment
comment|/*  * A function that returns 1 if the address cannot be accessed by  * a device and 0 if it can be.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|bus_dma_filter_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_addr_t
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Generic helper function for manipulating mutexes.  */
end_comment

begin_function_decl
name|void
name|busdma_lock_mutex
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|bus_dma_lock_op_t
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate a device specific dma_tag encapsulating the constraints of  * the parent tag in addition to other restrictions specified:  *  *	alignment:	Alignment for segments.  *	boundary:	Boundary that segments cannot cross.  *	lowaddr:	Low restricted address that cannot appear in a mapping.  *	highaddr:	High restricted address that cannot appear in a mapping.  *	filtfunc:	An optional function to further test if an address  *			within the range of lowaddr and highaddr cannot appear  *			in a mapping.  *	filtfuncarg:	An argument that will be passed to filtfunc in addition  *			to the address to test.  *	maxsize:	Maximum mapping size supported by this tag.  *	nsegments:	Number of discontinuities allowed in maps.  *	maxsegsz:	Maximum size of a segment in the map.  *	flags:		Bus DMA flags.  *	lockfunc:	An optional function to handle driver-defined lock  *			operations.  *	lockfuncarg:	An argument that will be passed to lockfunc in addition  *			to the lock operation.  *	dmat:		A pointer to set to a valid dma tag should the return  *			value of this function indicate success.  */
end_comment

begin_comment
comment|/* XXX Should probably allow specification of alignment */
end_comment

begin_function_decl
name|int
name|bus_dma_tag_create
parameter_list|(
name|bus_dma_tag_t
name|parent
parameter_list|,
name|bus_size_t
name|alignment
parameter_list|,
name|bus_addr_t
name|boundary
parameter_list|,
name|bus_addr_t
name|lowaddr
parameter_list|,
name|bus_addr_t
name|highaddr
parameter_list|,
name|bus_dma_filter_t
modifier|*
name|filtfunc
parameter_list|,
name|void
modifier|*
name|filtfuncarg
parameter_list|,
name|bus_size_t
name|maxsize
parameter_list|,
name|int
name|nsegments
parameter_list|,
name|bus_size_t
name|maxsegsz
parameter_list|,
name|int
name|flags
parameter_list|,
name|bus_dma_lock_t
modifier|*
name|lockfunc
parameter_list|,
name|void
modifier|*
name|lockfuncarg
parameter_list|,
name|bus_dma_tag_t
modifier|*
name|dmat
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_dma_tag_destroy
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * A function that processes a successfully loaded dma map or an error  * from a delayed load map.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|bus_dmamap_callback_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Like bus_dmamap_callback but includes map size in bytes.  This is  * defined as a separate interface to maintain compatibility for users  * of bus_dmamap_callback_t--at some point these interfaces should be merged.  */
end_comment

begin_typedef
typedef|typedef
name|void
name|bus_dmamap_callback2_t
parameter_list|(
name|void
modifier|*
parameter_list|,
name|bus_dma_segment_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Map the buffer buf into bus space using the dmamap map.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_load
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|bus_size_t
name|buflen
parameter_list|,
name|bus_dmamap_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like bus_dmamap_load but for mbufs.  Note the use of the  * bus_dmamap_callback2_t interface.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_load_mbuf
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|struct
name|mbuf
modifier|*
name|mbuf
parameter_list|,
name|bus_dmamap_callback2_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bus_dmamap_load_mbuf_sg
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|struct
name|mbuf
modifier|*
name|mbuf
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
modifier|*
name|nsegs
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like bus_dmamap_load but for uios.  Note the use of the  * bus_dmamap_callback2_t interface.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_load_uio
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|struct
name|uio
modifier|*
name|ui
parameter_list|,
name|bus_dmamap_callback2_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like bus_dmamap_load but for cam control blocks.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_load_ccb
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|union
name|ccb
modifier|*
name|ccb
parameter_list|,
name|bus_dmamap_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Like bus_dmamap_load but for bios.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_load_bio
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|struct
name|bio
modifier|*
name|bio
parameter_list|,
name|bus_dmamap_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Loads any memory descriptor.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_load_mem
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|struct
name|memdesc
modifier|*
name|mem
parameter_list|,
name|bus_dmamap_callback_t
modifier|*
name|callback
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Placeholder for use by busdma implementations which do not benefit  * from optimized procedure to load an array of vm_page_t.  Falls back  * to do _bus_dmamap_load_phys() in loop.  */
end_comment

begin_function_decl
name|int
name|bus_dmamap_load_ma_triv
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|,
name|struct
name|vm_page
modifier|*
modifier|*
name|ma
parameter_list|,
name|bus_size_t
name|tlen
parameter_list|,
name|int
name|ma_offs
parameter_list|,
name|int
name|flags
parameter_list|,
name|bus_dma_segment_t
modifier|*
name|segs
parameter_list|,
name|int
modifier|*
name|segp
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|WANT_INLINE_DMAMAP
end_ifdef

begin_define
define|#
directive|define
name|BUS_DMAMAP_OP
value|static inline
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BUS_DMAMAP_OP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Allocate a handle for mapping from kva/uva/physical  * address space into bus device space.  */
end_comment

begin_function_decl
name|BUS_DMAMAP_OP
name|int
name|bus_dmamap_create
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|int
name|flags
parameter_list|,
name|bus_dmamap_t
modifier|*
name|mapp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy a handle for mapping from kva/uva/physical  * address space into bus device space.  */
end_comment

begin_function_decl
name|BUS_DMAMAP_OP
name|int
name|bus_dmamap_destroy
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Allocate a piece of memory that can be efficiently mapped into  * bus device space based on the constraints listed in the dma tag.  * A dmamap to for use with dmamap_load is also allocated.  */
end_comment

begin_function_decl
name|BUS_DMAMAP_OP
name|int
name|bus_dmamem_alloc
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|void
modifier|*
modifier|*
name|vaddr
parameter_list|,
name|int
name|flags
parameter_list|,
name|bus_dmamap_t
modifier|*
name|mapp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Free a piece of memory and its allocated dmamap, that was allocated  * via bus_dmamem_alloc.  */
end_comment

begin_function_decl
name|BUS_DMAMAP_OP
name|void
name|bus_dmamem_free
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|void
modifier|*
name|vaddr
parameter_list|,
name|bus_dmamap_t
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Perform a synchronization operation on the given map. If the map  * is NULL we have a fully IO-coherent system.  */
end_comment

begin_function_decl
name|BUS_DMAMAP_OP
name|void
name|bus_dmamap_sync
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|dmamap
parameter_list|,
name|bus_dmasync_op_t
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Release the mapping held by map.  */
end_comment

begin_function_decl
name|BUS_DMAMAP_OP
name|void
name|bus_dmamap_unload
parameter_list|(
name|bus_dma_tag_t
name|dmat
parameter_list|,
name|bus_dmamap_t
name|dmamap
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|BUS_DMAMAP_OP
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BUS_DMA_H_ */
end_comment

end_unit

