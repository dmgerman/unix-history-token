begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2012-2014 Matteo Landi, Luigi Rizzo, Giuseppe Lettieri. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   1. Redistributions of source code must retain the above copyright  *      notice, this list of conditions and the following disclaimer.  *   2. Redistributions in binary form must reproduce the above copyright  *      notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  *  * (New) memory allocator for netmap  */
end_comment

begin_comment
comment|/*  * This allocator creates three memory pools:  *	nm_if_pool	for the struct netmap_if  *	nm_ring_pool	for the struct netmap_ring  *	nm_buf_pool	for the packet buffers.  *  * that contain netmap objects. Each pool is made of a number of clusters,  * multiple of a page size, each containing an integer number of objects.  * The clusters are contiguous in user space but not in the kernel.  * Only nm_buf_pool needs to be dma-able,  * but for convenience use the same type of allocator for all.  *  * Once mapped, the three pools are exported to userspace  * as a contiguous block, starting from nm_if_pool. Each  * cluster (and pool) is an integral number of pages.  *   [ . . . ][ . . . . . .][ . . . . . . . . . .]  *    nm_if     nm_ring            nm_buf  *  * The userspace areas contain offsets of the objects in userspace.  * When (at init time) we write these offsets, we find out the index  * of the object, and from there locate the offset from the beginning  * of the region.  *  * The invididual allocators manage a pool of memory for objects of  * the same size.  * The pool is split into smaller clusters, whose size is a  * multiple of the page size. The cluster size is chosen  * to minimize the waste for a given max cluster size  * (we do it by brute force, as we have relatively few objects  * per cluster).  *  * Objects are aligned to the cache line (64 bytes) rounding up object  * sizes when needed. A bitmap contains the state of each object.  * Allocation scans the bitmap; this is done only on attach, so we are not  * too worried about performance  *  * For each allocator we can define (thorugh sysctl) the size and  * number of each object. Memory is allocated at the first use of a  * netmap file descriptor, and can be freed when all such descriptors  * have been released (including unmapping the memory).  * If memory is scarce, the system tries to get as much as possible  * and the sysctl values reflect the actual allocation.  * Together with desired values, the sysctl export also absolute  * min and maximum values that cannot be overridden.  *  * struct netmap_if:  *	variable size, max 16 bytes per ring pair plus some fixed amount.  *	1024 bytes should be large enough in practice.  *  *	In the worst case we have one netmap_if per ring in the system.  *  * struct netmap_ring  *	variable size, 8 byte per slot plus some fixed amount.  *	Rings can be large (e.g. 4k slots, or>32Kbytes).  *	We default to 36 KB (9 pages), and a few hundred rings.  *  * struct netmap_buffer  *	The more the better, both because fast interfaces tend to have  *	many slots, and because we may want to use buffers to store  *	packets in userspace avoiding copies.  *	Must contain a full frame (eg 1518, or more for vlans, jumbo  *	frames etc.) plus be nicely aligned, plus some NICs restrict  *	the size to multiple of 1K or so. Default to 2K  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_NETMAP_MEM2_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_NETMAP_MEM2_H_
end_define

begin_define
define|#
directive|define
name|NETMAP_BUF_MAX_NUM
value|20*4096*2
end_define

begin_comment
comment|/* large machine */
end_comment

begin_define
define|#
directive|define
name|NETMAP_POOL_MAX_NAMSZ
value|32
end_define

begin_enum
enum|enum
block|{
name|NETMAP_IF_POOL
init|=
literal|0
block|,
name|NETMAP_RING_POOL
block|,
name|NETMAP_BUF_POOL
block|,
name|NETMAP_POOLS_NR
block|}
enum|;
end_enum

begin_struct
struct|struct
name|netmap_obj_params
block|{
name|u_int
name|size
decl_stmt|;
name|u_int
name|num
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|netmap_obj_pool
block|{
name|char
name|name
index|[
name|NETMAP_POOL_MAX_NAMSZ
index|]
decl_stmt|;
comment|/* name of the allocator */
comment|/* ---------------------------------------------------*/
comment|/* these are only meaningful if the pool is finalized */
comment|/* (see 'finalized' field in netmap_mem_d)            */
name|u_int
name|objtotal
decl_stmt|;
comment|/* actual total number of objects. */
name|u_int
name|memtotal
decl_stmt|;
comment|/* actual total memory space */
name|u_int
name|numclusters
decl_stmt|;
comment|/* actual number of clusters */
name|u_int
name|objfree
decl_stmt|;
comment|/* number of free objects. */
name|struct
name|lut_entry
modifier|*
name|lut
decl_stmt|;
comment|/* virt,phys addresses, objtotal entries */
name|uint32_t
modifier|*
name|bitmap
decl_stmt|;
comment|/* one bit per buffer, 1 means free */
name|uint32_t
name|bitmap_slots
decl_stmt|;
comment|/* number of uint32 entries in bitmap */
comment|/* ---------------------------------------------------*/
comment|/* limits */
name|u_int
name|objminsize
decl_stmt|;
comment|/* minimum object size */
name|u_int
name|objmaxsize
decl_stmt|;
comment|/* maximum object size */
name|u_int
name|nummin
decl_stmt|;
comment|/* minimum number of objects */
name|u_int
name|nummax
decl_stmt|;
comment|/* maximum number of objects */
comment|/* these are changed only by config */
name|u_int
name|_objtotal
decl_stmt|;
comment|/* total number of objects */
name|u_int
name|_objsize
decl_stmt|;
comment|/* object size */
name|u_int
name|_clustsize
decl_stmt|;
comment|/* cluster size */
name|u_int
name|_clustentries
decl_stmt|;
comment|/* objects per cluster */
name|u_int
name|_numclusters
decl_stmt|;
comment|/* number of clusters */
comment|/* requested values */
name|u_int
name|r_objtotal
decl_stmt|;
name|u_int
name|r_objsize
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|linux
end_ifdef

begin_comment
comment|// XXX a mtx would suffice here 20130415 lr
end_comment

begin_define
define|#
directive|define
name|NMA_LOCK_T
value|struct semaphore
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !linux */
end_comment

begin_define
define|#
directive|define
name|NMA_LOCK_T
value|struct mtx
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* linux */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|netmap_mem_config_t
function_decl|)
parameter_list|(
name|struct
name|netmap_mem_d
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|netmap_mem_finalize_t
function_decl|)
parameter_list|(
name|struct
name|netmap_mem_d
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|netmap_mem_deref_t
function_decl|)
parameter_list|(
name|struct
name|netmap_mem_d
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|nm_memid_t
typedef|;
end_typedef

begin_comment
comment|/* We implement two kinds of netmap_mem_d structures:  *  * - global: used by hardware NICS;  *  * - private: used by VALE ports.  *  * In both cases, the netmap_mem_d structure has the same lifetime as the  * netmap_adapter of the corresponding NIC or port. It is the responsibility of  * the client code to delete the private allocator when the associated  * netmap_adapter is freed (this is implemented by the NAF_MEM_OWNER flag in  * netmap.c).  The 'refcount' field counts the number of active users of the  * structure. The global allocator uses this information to prevent/allow  * reconfiguration. The private allocators release all their memory when there  * are no active users.  By 'active user' we mean an existing netmap_priv  * structure holding a reference to the allocator.  */
end_comment

begin_struct
struct|struct
name|netmap_mem_d
block|{
name|NMA_LOCK_T
name|nm_mtx
decl_stmt|;
comment|/* protect the allocator */
name|u_int
name|nm_totalsize
decl_stmt|;
comment|/* shorthand */
name|u_int
name|flags
decl_stmt|;
define|#
directive|define
name|NETMAP_MEM_FINALIZED
value|0x1
comment|/* preallocation done */
define|#
directive|define
name|NETMAP_MEM_PRIVATE
value|0x2
comment|/* uses private address space */
name|int
name|lasterr
decl_stmt|;
comment|/* last error for curr config */
name|int
name|refcount
decl_stmt|;
comment|/* existing priv structures */
comment|/* the three allocators */
name|struct
name|netmap_obj_pool
name|pools
index|[
name|NETMAP_POOLS_NR
index|]
decl_stmt|;
name|netmap_mem_config_t
name|config
decl_stmt|;
name|netmap_mem_finalize_t
name|finalize
decl_stmt|;
name|netmap_mem_deref_t
name|deref
decl_stmt|;
name|nm_memid_t
name|nm_id
decl_stmt|;
comment|/* allocator identifier */
comment|/* list of all existing allocators, sorted by nm_id */
name|struct
name|netmap_mem_d
modifier|*
name|prev
decl_stmt|,
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|netmap_mem_d
name|nm_mem
decl_stmt|;
end_decl_stmt

begin_function_decl
name|vm_paddr_t
name|netmap_mem_ofstophys
parameter_list|(
name|struct
name|netmap_mem_d
modifier|*
parameter_list|,
name|vm_ooffset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_mem_finalize
parameter_list|(
name|struct
name|netmap_mem_d
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_mem_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_mem_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netmap_if
modifier|*
name|netmap_mem_if_new
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_mem_if_delete
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|struct
name|netmap_if
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_mem_rings_create
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_mem_rings_delete
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_mem_deref
parameter_list|(
name|struct
name|netmap_mem_d
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|netmap_mem_get_info
parameter_list|(
name|struct
name|netmap_mem_d
modifier|*
parameter_list|,
name|u_int
modifier|*
name|size
parameter_list|,
name|u_int
modifier|*
name|memflags
parameter_list|,
name|uint16_t
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|netmap_mem_if_offset
parameter_list|(
name|struct
name|netmap_mem_d
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
name|vaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|netmap_mem_d
modifier|*
name|netmap_mem_private_new
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|u_int
name|txr
parameter_list|,
name|u_int
name|txd
parameter_list|,
name|u_int
name|rxr
parameter_list|,
name|u_int
name|rxd
parameter_list|,
name|u_int
name|extra_bufs
parameter_list|,
name|u_int
name|npipes
parameter_list|,
name|int
modifier|*
name|error
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|netmap_mem_private_delete
parameter_list|(
name|struct
name|netmap_mem_d
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|NETMAP_BDG_BUF_SIZE
parameter_list|(
name|n
parameter_list|)
value|((n)->pools[NETMAP_BUF_POOL]._objsize)
end_define

begin_function_decl
name|uint32_t
name|netmap_extra_alloc
parameter_list|(
name|struct
name|netmap_adapter
modifier|*
parameter_list|,
name|uint32_t
modifier|*
parameter_list|,
name|uint32_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

