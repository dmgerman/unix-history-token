begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Akshay Jaggi<jaggi@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * gntdev.h  *  * Interface to /dev/xen/gntdev.  *  * This device provides the user with two kinds of functionalities:  * 1. Grant Allocation  *    Allocate a page of our own memory, and share it with a foreign domain.  * 2. Grant Mapping  *    Map a grant allocated by a foreign domain, into our own memory.  *  *  * Grant Allocation  *  * Steps to allocate a grant:  * 1. Do an `IOCTL_GNTDEV_ALLOC_GREF ioctl`, with  *     - `domid`, as the domain-id of the foreign domain  *     - `flags`, ORed with GNTDEV_ALLOC_FLAG_WRITABLE if you want the foreign  *       domain to have write access to the shared memory  *     - `count`, with the number of pages to share with the foreign domain  *  *    Ensure that the structure you allocate has enough memory to store  *    all the allocated grant-refs, i.e., you need to allocate  *    (sizeof(struct ioctl_gntdev_alloc_gref) + (count - 1)*sizeof(uint32_t))  *    bytes of memory.  *  * 2. Mmap the address given in `index` after a successful ioctl.  *    This will give you access to the granted pages.  *  * Note:  * 1. The grant is not removed until all three of the following conditions  *    are met  *     - The region is not mmaped. That is, munmap() has been called if  *       the region was mmapped previously.  *     - IOCTL_GNTDEV_DEALLOC_GREF ioctl has been performed. After you  *       perform this ioctl, you can no longer mmap or set notify on  *       the grant.  *     - The foreign domain has stopped using the grant.  * 2. Granted pages can only belong to one mmap region.  * 3. Every page of granted memory is a unit in itself. What this means  *    is that you can set a unmap notification for each of the granted  *    pages, individually; you can mmap and dealloc-ioctl a contiguous  *    range of allocated grants (even if alloc-ioctls were performed  *    individually), etc.  *  *  * Grant Mapping  *  * Steps to map a grant:  * 1. Do a `IOCTL_GNTDEV_MAP_GRANT_REF` ioctl, with  *     - `count`, as the number of foreign grants to map  *     - `refs[i].domid`, as the domain id of the foreign domain  *     - `refs[i].ref`, as the grant-ref for the grant to be mapped  *  * 2. Mmap the address given in `index` after a successful ioctl.  *    This will give you access to the mapped pages.  *  * Note:  * 1. The map hypercall is not made till the region is mmapped.  * 2. The unit is defined by the map ioctl. This means that only one  *    unmap notification can be set on a group of pages that were  *    mapped together in one ioctl, and also no single mmaping of contiguous  *    grant-maps is possible.  * 3. You can mmap the same grant-map region multiple times.  * 4. The grant is not unmapped until both of the following conditions are met  *     - The region is not mmaped. That is, munmap() has been called for  *       as many times as the grant was mmapped.  *     - IOCTL_GNTDEV_UNMAP_GRANT_REF ioctl has been called.  * 5. IOCTL_GNTDEV_GET_OFFSET_FOR_VADDR ioctl gives index and count of  *    a grant-map from the virtual address of the location where the grant  *    is mmapped.  *  *  * IOCTL_GNTDEV_SET_UNMAP_NOTIFY  * This ioctl allows us to set notifications to be made when the grant is  * either unmapped (in case of a mapped grant), or when it is ready to be  * deallocated by us, ie, the grant is no more mmapped, and the dealloc  * ioctl has been called (in case of an allocated grant). OR `action` with  * the required notification masks, and fill in the appropriate fields.  *  - UNMAP_NOTIFY_CLEAR_BYTE clears the byte at `index`, where index is  *    the address of the byte in file address space.  *  - UNMAP_NOTIFY_SEND_EVENT sends an event channel notification on  *    `event_channel_port`  * In case of multiple notify ioctls, only the last one survives.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_GNTDEV_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_GNTDEV_H__
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_define
define|#
directive|define
name|IOCTL_GNTDEV_SET_UNMAP_NOTIFY
define|\
value|_IOW('E', 0, struct ioctl_gntdev_unmap_notify)
end_define

begin_struct
struct|struct
name|ioctl_gntdev_unmap_notify
block|{
comment|/* IN parameters */
name|uint64_t
name|index
decl_stmt|;
name|uint32_t
name|action
decl_stmt|;
name|uint32_t
name|event_channel_port
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNMAP_NOTIFY_CLEAR_BYTE
value|0x1
end_define

begin_define
define|#
directive|define
name|UNMAP_NOTIFY_SEND_EVENT
value|0x2
end_define

begin_comment
comment|/*-------------------- Grant Allocation IOCTLs  ------------------------------*/
end_comment

begin_define
define|#
directive|define
name|IOCTL_GNTDEV_ALLOC_GREF
define|\
value|_IOWR('E', 1, struct ioctl_gntdev_alloc_gref)
end_define

begin_struct
struct|struct
name|ioctl_gntdev_alloc_gref
block|{
comment|/* IN parameters */
name|uint16_t
name|domid
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
name|uint32_t
name|count
decl_stmt|;
comment|/* OUT parameters */
name|uint64_t
name|index
decl_stmt|;
comment|/* Variable OUT parameter */
name|uint32_t
name|gref_ids
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GNTDEV_ALLOC_FLAG_WRITABLE
value|1
end_define

begin_define
define|#
directive|define
name|IOCTL_GNTDEV_DEALLOC_GREF
define|\
value|_IOW('E', 2, struct ioctl_gntdev_dealloc_gref)
end_define

begin_struct
struct|struct
name|ioctl_gntdev_dealloc_gref
block|{
comment|/* IN parameters */
name|uint64_t
name|index
decl_stmt|;
name|uint32_t
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*-------------------- Grant Mapping IOCTLs  ---------------------------------*/
end_comment

begin_struct
struct|struct
name|ioctl_gntdev_grant_ref
block|{
name|uint32_t
name|domid
decl_stmt|;
name|uint32_t
name|ref
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOCTL_GNTDEV_MAP_GRANT_REF
define|\
value|_IOWR('E', 3, struct ioctl_gntdev_map_grant_ref)
end_define

begin_struct
struct|struct
name|ioctl_gntdev_map_grant_ref
block|{
comment|/* IN parameters */
name|uint32_t
name|count
decl_stmt|;
name|uint32_t
name|pad0
decl_stmt|;
comment|/* OUT parameters */
name|uint64_t
name|index
decl_stmt|;
comment|/* Variable IN parameter */
name|struct
name|ioctl_gntdev_grant_ref
name|refs
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOCTL_GNTDEV_UNMAP_GRANT_REF
define|\
value|_IOW('E', 4, struct ioctl_gntdev_unmap_grant_ref)
end_define

begin_struct
struct|struct
name|ioctl_gntdev_unmap_grant_ref
block|{
comment|/* IN parameters */
name|uint64_t
name|index
decl_stmt|;
name|uint32_t
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IOCTL_GNTDEV_GET_OFFSET_FOR_VADDR
define|\
value|_IOWR('E', 5, struct ioctl_gntdev_get_offset_for_vaddr)
end_define

begin_struct
struct|struct
name|ioctl_gntdev_get_offset_for_vaddr
block|{
comment|/* IN parameters */
name|uint64_t
name|vaddr
decl_stmt|;
comment|/* OUT parameters */
name|uint64_t
name|offset
decl_stmt|;
name|uint32_t
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_GNTDEV_H__ */
end_comment

end_unit

