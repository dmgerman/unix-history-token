begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* drmP.h -- Private header for Direct Rendering Manager -*- linux-c -*-  * Created: Mon Jan  4 10:05:05 1999 by faith@precisioninsight.com  *  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Rickard E. (Rik) Faith<faith@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DRM_P_H_
end_ifndef

begin_define
define|#
directive|define
name|_DRM_P_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
end_if

begin_comment
comment|/* DRM template customization defaults  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HAVE_AGP
end_ifndef

begin_define
define|#
directive|define
name|__HAVE_AGP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__HAVE_MTRR
end_ifndef

begin_define
define|#
directive|define
name|__HAVE_MTRR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__HAVE_CTX_BITMAP
end_ifndef

begin_define
define|#
directive|define
name|__HAVE_CTX_BITMAP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__HAVE_DMA
end_ifndef

begin_define
define|#
directive|define
name|__HAVE_DMA
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__HAVE_DMA_IRQ
end_ifndef

begin_define
define|#
directive|define
name|__HAVE_DMA_IRQ
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DRM_DEBUG_CODE
value|0
end_define

begin_comment
comment|/* Include debugging code (if> 1, then 				     also include looping detection. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|drm_device
name|drm_device_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_file
name|drm_file_t
typedef|;
end_typedef

begin_comment
comment|/* There's undoubtably more of this file to go into these OS dependent ones. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

begin_include
include|#
directive|include
file|"dev/drm/drm_os_freebsd.h"
end_include

begin_elif
elif|#
directive|elif
name|defined
name|__NetBSD__
end_elif

begin_include
include|#
directive|include
file|"dev/drm/drm_os_netbsd.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"dev/drm/drm.h"
end_include

begin_comment
comment|/* Begin the DRM... */
end_comment

begin_define
define|#
directive|define
name|DRM_HASH_SIZE
value|16
end_define

begin_comment
comment|/* Size of key hash table		  */
end_comment

begin_define
define|#
directive|define
name|DRM_KERNEL_CONTEXT
value|0
end_define

begin_comment
comment|/* Change drm_resctx if changed	  */
end_comment

begin_define
define|#
directive|define
name|DRM_RESERVED_CONTEXTS
value|1
end_define

begin_comment
comment|/* Change drm_resctx if changed	  */
end_comment

begin_define
define|#
directive|define
name|DRM_FLAG_DEBUG
value|0x01
end_define

begin_define
define|#
directive|define
name|DRM_MEM_DMA
value|0
end_define

begin_define
define|#
directive|define
name|DRM_MEM_SAREA
value|1
end_define

begin_define
define|#
directive|define
name|DRM_MEM_DRIVER
value|2
end_define

begin_define
define|#
directive|define
name|DRM_MEM_MAGIC
value|3
end_define

begin_define
define|#
directive|define
name|DRM_MEM_IOCTLS
value|4
end_define

begin_define
define|#
directive|define
name|DRM_MEM_MAPS
value|5
end_define

begin_define
define|#
directive|define
name|DRM_MEM_BUFS
value|6
end_define

begin_define
define|#
directive|define
name|DRM_MEM_SEGS
value|7
end_define

begin_define
define|#
directive|define
name|DRM_MEM_PAGES
value|8
end_define

begin_define
define|#
directive|define
name|DRM_MEM_FILES
value|9
end_define

begin_define
define|#
directive|define
name|DRM_MEM_QUEUES
value|10
end_define

begin_define
define|#
directive|define
name|DRM_MEM_CMDS
value|11
end_define

begin_define
define|#
directive|define
name|DRM_MEM_MAPPINGS
value|12
end_define

begin_define
define|#
directive|define
name|DRM_MEM_BUFLISTS
value|13
end_define

begin_define
define|#
directive|define
name|DRM_MEM_AGPLISTS
value|14
end_define

begin_define
define|#
directive|define
name|DRM_MEM_TOTALAGP
value|15
end_define

begin_define
define|#
directive|define
name|DRM_MEM_BOUNDAGP
value|16
end_define

begin_define
define|#
directive|define
name|DRM_MEM_CTXBITMAP
value|17
end_define

begin_define
define|#
directive|define
name|DRM_MEM_STUB
value|18
end_define

begin_define
define|#
directive|define
name|DRM_MEM_SGLISTS
value|19
end_define

begin_define
define|#
directive|define
name|DRM_MAX_CTXBITMAP
value|(PAGE_SIZE * 8)
end_define

begin_comment
comment|/* Mapping helper macros */
end_comment

begin_define
define|#
directive|define
name|DRM_IOREMAP
parameter_list|(
name|map
parameter_list|,
name|dev
parameter_list|)
define|\
value|(map)->handle = DRM(ioremap)( dev, map )
end_define

begin_define
define|#
directive|define
name|DRM_IOREMAP_NOCACHE
parameter_list|(
name|map
parameter_list|,
name|dev
parameter_list|)
define|\
value|(map)->handle = DRM(ioremap_nocache)( dev, map )
end_define

begin_define
define|#
directive|define
name|DRM_IOREMAPFREE
parameter_list|(
name|map
parameter_list|,
name|dev
parameter_list|)
define|\
value|do {								\ 		if ( (map)->handle&& (map)->size )			\ 			DRM(ioremapfree)( map );			\ 	} while (0)
end_define

begin_comment
comment|/* Internal types and structures */
end_comment

begin_define
define|#
directive|define
name|DRM_ARRAY_SIZE
parameter_list|(
name|x
parameter_list|)
value|(sizeof(x)/sizeof(x[0]))
end_define

begin_define
define|#
directive|define
name|DRM_MIN
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)<(b)?(a):(b))
end_define

begin_define
define|#
directive|define
name|DRM_MAX
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((a)>(b)?(a):(b))
end_define

begin_define
define|#
directive|define
name|DRM_LEFTCOUNT
parameter_list|(
name|x
parameter_list|)
value|(((x)->rp + (x)->count - (x)->wp) % ((x)->count + 1))
end_define

begin_define
define|#
directive|define
name|DRM_BUFCOUNT
parameter_list|(
name|x
parameter_list|)
value|((x)->count - DRM_LEFTCOUNT(x))
end_define

begin_define
define|#
directive|define
name|DRM_WAITCOUNT
parameter_list|(
name|dev
parameter_list|,
name|idx
parameter_list|)
value|DRM_BUFCOUNT(&dev->queuelist[idx]->waitlist)
end_define

begin_define
define|#
directive|define
name|DRM_GET_PRIV_SAREA
parameter_list|(
name|_dev
parameter_list|,
name|_ctx
parameter_list|,
name|_map
parameter_list|)
value|do {	\ 	(_map) = (_dev)->context_sareas[_ctx];		\ } while(0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_ioctl_desc
block|{
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
name|int
name|auth_needed
decl_stmt|;
name|int
name|root_only
decl_stmt|;
block|}
name|drm_ioctl_desc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_magic_entry
block|{
name|drm_magic_t
name|magic
decl_stmt|;
name|struct
name|drm_file
modifier|*
name|priv
decl_stmt|;
name|struct
name|drm_magic_entry
modifier|*
name|next
decl_stmt|;
block|}
name|drm_magic_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_magic_head
block|{
name|struct
name|drm_magic_entry
modifier|*
name|head
decl_stmt|;
name|struct
name|drm_magic_entry
modifier|*
name|tail
decl_stmt|;
block|}
name|drm_magic_head_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_buf
block|{
name|int
name|idx
decl_stmt|;
comment|/* Index into master buflist	     */
name|int
name|total
decl_stmt|;
comment|/* Buffer size			     */
name|int
name|order
decl_stmt|;
comment|/* log-base-2(total)		     */
name|int
name|used
decl_stmt|;
comment|/* Amount of buffer in use (for DMA)  */
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/* Byte offset (used internally)	     */
name|void
modifier|*
name|address
decl_stmt|;
comment|/* Address of buffer		     */
name|unsigned
name|long
name|bus_address
decl_stmt|;
comment|/* Bus address of buffer		     */
name|struct
name|drm_buf
modifier|*
name|next
decl_stmt|;
comment|/* Kernel-only: used for free list    */
specifier|__volatile__
name|int
name|pending
decl_stmt|;
comment|/* On hardware DMA queue		     */
name|DRMFILE
name|filp
decl_stmt|;
comment|/* Unique identifier of holding process */
name|int
name|context
decl_stmt|;
comment|/* Kernel queue for this buffer	     */
enum|enum
block|{
name|DRM_LIST_NONE
init|=
literal|0
block|,
name|DRM_LIST_FREE
init|=
literal|1
block|,
name|DRM_LIST_WAIT
init|=
literal|2
block|,
name|DRM_LIST_PEND
init|=
literal|3
block|,
name|DRM_LIST_PRIO
init|=
literal|4
block|,
name|DRM_LIST_RECLAIM
init|=
literal|5
block|}
name|list
enum|;
comment|/* Which list we're on		     */
name|int
name|dev_priv_size
decl_stmt|;
comment|/* Size of buffer private stoarge   */
name|void
modifier|*
name|dev_private
decl_stmt|;
comment|/* Per-buffer private storage       */
block|}
name|drm_buf_t
typedef|;
end_typedef

begin_comment
comment|/* bufs is one longer than it has to be */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_waitlist
block|{
name|int
name|count
decl_stmt|;
comment|/* Number of possible buffers	   */
name|drm_buf_t
modifier|*
modifier|*
name|bufs
decl_stmt|;
comment|/* List of pointers to buffers	   */
name|drm_buf_t
modifier|*
modifier|*
name|rp
decl_stmt|;
comment|/* Read pointer			   */
name|drm_buf_t
modifier|*
modifier|*
name|wp
decl_stmt|;
comment|/* Write pointer		   */
name|drm_buf_t
modifier|*
modifier|*
name|end
decl_stmt|;
comment|/* End pointer			   */
name|DRM_SPINTYPE
name|read_lock
decl_stmt|;
name|DRM_SPINTYPE
name|write_lock
decl_stmt|;
block|}
name|drm_waitlist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_freelist
block|{
name|int
name|initialized
decl_stmt|;
comment|/* Freelist in use		   */
name|atomic_t
name|count
decl_stmt|;
comment|/* Number of free buffers	   */
name|drm_buf_t
modifier|*
name|next
decl_stmt|;
comment|/* End pointer			   */
name|int
name|low_mark
decl_stmt|;
comment|/* Low water mark		   */
name|int
name|high_mark
decl_stmt|;
comment|/* High water mark		   */
name|DRM_SPINTYPE
name|lock
decl_stmt|;
block|}
name|drm_freelist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_buf_entry
block|{
name|int
name|buf_size
decl_stmt|;
name|int
name|buf_count
decl_stmt|;
name|drm_buf_t
modifier|*
name|buflist
decl_stmt|;
name|int
name|seg_count
decl_stmt|;
name|int
name|page_order
decl_stmt|;
name|vm_offset_t
modifier|*
name|seglist
decl_stmt|;
name|dma_addr_t
modifier|*
name|seglist_bus
decl_stmt|;
name|drm_freelist_t
name|freelist
decl_stmt|;
block|}
name|drm_buf_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_hw_lock
block|{
specifier|__volatile__
name|unsigned
name|int
name|lock
decl_stmt|;
name|char
name|padding
index|[
literal|60
index|]
decl_stmt|;
comment|/* Pad to cache line */
block|}
name|drm_hw_lock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|drm_file_list
argument_list|,
argument|drm_file
argument_list|)
name|drm_file_list_t
expr_stmt|;
end_typedef

begin_struct
struct|struct
name|drm_file
block|{
name|TAILQ_ENTRY
argument_list|(
argument|drm_file
argument_list|)
name|link
expr_stmt|;
name|int
name|authenticated
decl_stmt|;
name|int
name|minor
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
name|uid_t
name|uid
decl_stmt|;
name|int
name|refs
decl_stmt|;
name|drm_magic_t
name|magic
decl_stmt|;
name|unsigned
name|long
name|ioctl_count
decl_stmt|;
name|struct
name|drm_device
modifier|*
name|devXX
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|drm_lock_data
block|{
name|drm_hw_lock_t
modifier|*
name|hw_lock
decl_stmt|;
comment|/* Hardware lock		   */
name|DRMFILE
name|filp
decl_stmt|;
comment|/* Unique identifier of holding process (NULL is kernel)*/
name|wait_queue_head_t
name|lock_queue
decl_stmt|;
comment|/* Queue of blocked processes	   */
name|unsigned
name|long
name|lock_time
decl_stmt|;
comment|/* Time of last lock in jiffies	   */
block|}
name|drm_lock_data_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_device_dma
block|{
name|drm_buf_entry_t
name|bufs
index|[
name|DRM_MAX_ORDER
operator|+
literal|1
index|]
decl_stmt|;
name|int
name|buf_count
decl_stmt|;
name|drm_buf_t
modifier|*
modifier|*
name|buflist
decl_stmt|;
comment|/* Vector of pointers info bufs	   */
name|int
name|seg_count
decl_stmt|;
name|int
name|page_count
decl_stmt|;
name|unsigned
name|long
modifier|*
name|pagelist
decl_stmt|;
name|unsigned
name|long
name|byte_count
decl_stmt|;
enum|enum
block|{
name|_DRM_DMA_USE_AGP
init|=
literal|0x01
block|,
name|_DRM_DMA_USE_SG
init|=
literal|0x02
block|}
name|flags
enum|;
comment|/* DMA support */
name|drm_buf_t
modifier|*
name|this_buffer
decl_stmt|;
comment|/* Buffer being sent		   */
name|drm_buf_t
modifier|*
name|next_buffer
decl_stmt|;
comment|/* Selected buffer to send	   */
block|}
name|drm_device_dma_t
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__REALLY_HAVE_AGP
end_if

begin_typedef
typedef|typedef
struct|struct
name|drm_agp_mem
block|{
name|void
modifier|*
name|handle
decl_stmt|;
name|unsigned
name|long
name|bound
decl_stmt|;
comment|/* address */
name|int
name|pages
decl_stmt|;
name|struct
name|drm_agp_mem
modifier|*
name|prev
decl_stmt|;
name|struct
name|drm_agp_mem
modifier|*
name|next
decl_stmt|;
block|}
name|drm_agp_mem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_agp_head
block|{
name|device_t
name|agpdev
decl_stmt|;
name|struct
name|agp_info
name|info
decl_stmt|;
specifier|const
name|char
modifier|*
name|chipset
decl_stmt|;
name|drm_agp_mem_t
modifier|*
name|memory
decl_stmt|;
name|unsigned
name|long
name|mode
decl_stmt|;
name|int
name|enabled
decl_stmt|;
name|int
name|acquired
decl_stmt|;
name|unsigned
name|long
name|base
decl_stmt|;
name|int
name|agp_mtrr
decl_stmt|;
name|int
name|cant_use_aperture
decl_stmt|;
name|unsigned
name|long
name|page_mask
decl_stmt|;
block|}
name|drm_agp_head_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|drm_sg_mem
block|{
name|unsigned
name|long
name|handle
decl_stmt|;
name|void
modifier|*
name|virtual
decl_stmt|;
name|int
name|pages
decl_stmt|;
name|dma_addr_t
modifier|*
name|busaddr
decl_stmt|;
block|}
name|drm_sg_mem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_local_map
block|{
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/* Physical address (0 for SAREA)*/
name|unsigned
name|long
name|size
decl_stmt|;
comment|/* Physical size (bytes)	    */
name|drm_map_type_t
name|type
decl_stmt|;
comment|/* Type of memory mapped		    */
name|drm_map_flags_t
name|flags
decl_stmt|;
comment|/* Flags				    */
name|void
modifier|*
name|handle
decl_stmt|;
comment|/* User-space: "Handle" to pass to mmap    */
comment|/* Kernel-space: kernel-virtual address    */
name|int
name|mtrr
decl_stmt|;
comment|/* MTRR slot used			    */
comment|/* Private data			    */
name|bus_space_tag_t
name|iot
decl_stmt|;
name|bus_space_handle_t
name|ioh
decl_stmt|;
block|}
name|drm_local_map_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|drm_map_list
argument_list|,
argument|drm_map_list_entry
argument_list|)
name|drm_map_list_t
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_map_list_entry
block|{
name|TAILQ_ENTRY
argument_list|(
argument|drm_map_list_entry
argument_list|)
name|link
expr_stmt|;
name|drm_local_map_t
modifier|*
name|map
decl_stmt|;
block|}
name|drm_map_list_entry_t
typedef|;
end_typedef

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|drm_vbl_sig_list
argument_list|,
name|drm_vbl_sig
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
struct|struct
name|drm_vbl_sig
block|{
name|TAILQ_ENTRY
argument_list|(
argument|drm_vbl_sig
argument_list|)
name|link
expr_stmt|;
name|unsigned
name|int
name|sequence
decl_stmt|;
name|int
name|signo
decl_stmt|;
name|int
name|pid
decl_stmt|;
block|}
name|drm_vbl_sig_t
typedef|;
end_typedef

begin_struct
struct|struct
name|drm_device
block|{
ifdef|#
directive|ifdef
name|__NetBSD__
name|struct
name|device
name|device
decl_stmt|;
comment|/* NetBSD's softc is an extension of struct device */
endif|#
directive|endif
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Simple driver name		   */
name|char
modifier|*
name|unique
decl_stmt|;
comment|/* Unique identifier: e.g., busid  */
name|int
name|unique_len
decl_stmt|;
comment|/* Length of unique field	   */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|device_t
name|device
decl_stmt|;
comment|/* Device instance from newbus     */
endif|#
directive|endif
name|dev_t
name|devnode
decl_stmt|;
comment|/* Device number for mknod	   */
name|int
name|flags
decl_stmt|;
comment|/* Flags to open(2)		   */
comment|/* Locks */
name|DRM_SPINTYPE
name|count_lock
decl_stmt|;
comment|/* For open_count, buf_use, buf_alloc */
name|struct
name|lock
name|dev_lock
decl_stmt|;
comment|/* For others			   */
comment|/* Usage Counters */
name|int
name|open_count
decl_stmt|;
comment|/* Outstanding files open	   */
name|int
name|buf_use
decl_stmt|;
comment|/* Buffers in use -- cannot alloc  */
name|int
name|buf_alloc
decl_stmt|;
comment|/* Buffer allocation in progress   */
comment|/* Performance counters */
name|unsigned
name|long
name|counters
decl_stmt|;
name|drm_stat_type_t
name|types
index|[
literal|15
index|]
decl_stmt|;
name|atomic_t
name|counts
index|[
literal|15
index|]
decl_stmt|;
comment|/* Authentication */
name|drm_file_list_t
name|files
decl_stmt|;
name|drm_magic_head_t
name|magiclist
index|[
name|DRM_HASH_SIZE
index|]
decl_stmt|;
comment|/* Memory management */
name|drm_map_list_t
modifier|*
name|maplist
decl_stmt|;
comment|/* Linked list of regions	   */
name|drm_local_map_t
modifier|*
modifier|*
name|context_sareas
decl_stmt|;
name|int
name|max_context
decl_stmt|;
name|drm_lock_data_t
name|lock
decl_stmt|;
comment|/* Information on hardware lock	   */
comment|/* DMA queues (contexts) */
name|drm_device_dma_t
modifier|*
name|dma
decl_stmt|;
comment|/* Optional pointer for DMA support */
comment|/* Context support */
name|int
name|irq
decl_stmt|;
comment|/* Interrupt used by board	   */
name|int
name|irqrid
decl_stmt|;
comment|/* Interrupt used by board	   */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|resource
modifier|*
name|irqr
decl_stmt|;
comment|/* Resource for interrupt used by board	   */
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|struct
name|pci_attach_args
name|pa
decl_stmt|;
name|pci_intr_handle_t
name|ih
decl_stmt|;
endif|#
directive|endif
name|void
modifier|*
name|irqh
decl_stmt|;
comment|/* Handle from bus_setup_intr      */
name|atomic_t
name|context_flag
decl_stmt|;
comment|/* Context swapping flag	   */
name|struct
name|callout
name|timer
decl_stmt|;
comment|/* Timer for delaying ctx switch   */
name|int
name|last_context
decl_stmt|;
comment|/* Last current context		   */
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|400005
name|struct
name|task
name|task
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|__HAVE_VBL_IRQ
name|wait_queue_head_t
name|vbl_queue
decl_stmt|;
comment|/* vbl wait channel */
name|atomic_t
name|vbl_received
decl_stmt|;
if|#
directive|if
literal|0
comment|/* vbl signals are untested */
block|struct drm_vbl_sig_list vbl_sig_list; 	DRM_SPINTYPE      vbl_lock;
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|sigio
modifier|*
name|buf_sigio
decl_stmt|;
comment|/* Processes waiting for SIGIO     */
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
name|pid_t
name|buf_pgid
decl_stmt|;
endif|#
directive|endif
comment|/* Sysctl support */
name|struct
name|drm_sysctl_info
modifier|*
name|sysctl
decl_stmt|;
if|#
directive|if
name|__REALLY_HAVE_AGP
name|drm_agp_head_t
modifier|*
name|agp
decl_stmt|;
endif|#
directive|endif
name|drm_sg_mem_t
modifier|*
name|sg
decl_stmt|;
comment|/* Scatter gather memory */
name|atomic_t
modifier|*
name|ctx_bitmap
decl_stmt|;
name|void
modifier|*
name|dev_private
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|int
name|DRM
parameter_list|(
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Authentication (drm_auth.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|add_magic
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|drm_file_t
modifier|*
name|priv
parameter_list|,
name|drm_magic_t
name|magic
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|remove_magic
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|drm_magic_t
name|magic
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Driver support (drm_drv.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|version
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Memory management support (drm_memory.h) */
end_comment

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|mem_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|mem_uninit
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|DRM
function_decl|(
name|alloc
function_decl|)
parameter_list|(
name|size_t
name|size
parameter_list|,
name|int
name|area
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|DRM
function_decl|(
name|calloc
function_decl|)
parameter_list|(
name|size_t
name|nmemb
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|area
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|DRM
function_decl|(
name|realloc
function_decl|)
parameter_list|(
name|void
modifier|*
name|oldpt
parameter_list|,
name|size_t
name|oldsize
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|area
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|free
function_decl|)
parameter_list|(
name|void
modifier|*
name|pt
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|area
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|DRM
function_decl|(
name|ioremap
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|drm_local_map_t
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|ioremapfree
function_decl|)
parameter_list|(
name|drm_local_map_t
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__REALLY_HAVE_AGP
end_if

begin_function_decl
specifier|extern
name|agp_memory
modifier|*
name|DRM
function_decl|(
name|alloc_agp
function_decl|)
parameter_list|(
name|int
name|pages
parameter_list|,
name|u32
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|free_agp
function_decl|)
parameter_list|(
name|agp_memory
modifier|*
name|handle
parameter_list|,
name|int
name|pages
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|bind_agp
function_decl|)
parameter_list|(
name|agp_memory
modifier|*
name|handle
parameter_list|,
name|unsigned
name|int
name|start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|unbind_agp
function_decl|)
parameter_list|(
name|agp_memory
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|context_switch
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|int
name|old
parameter_list|,
name|int
name|new
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|context_switch_complete
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|int
name|new
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__HAVE_CTX_BITMAP
end_if

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|ctxbitmap_init
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|ctxbitmap_cleanup
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|ctxbitmap_free
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|int
name|ctx_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|ctxbitmap_next
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Locking IOCTL support (drm_lock.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|lock_take
function_decl|)
parameter_list|(
specifier|__volatile__
name|unsigned
name|int
modifier|*
name|lock
parameter_list|,
name|unsigned
name|int
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|lock_transfer
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
specifier|__volatile__
name|unsigned
name|int
modifier|*
name|lock
parameter_list|,
name|unsigned
name|int
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|lock_free
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
specifier|__volatile__
name|unsigned
name|int
modifier|*
name|lock
parameter_list|,
name|unsigned
name|int
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Buffer management support (drm_bufs.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|order
function_decl|)
parameter_list|(
name|unsigned
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__HAVE_DMA
end_if

begin_comment
comment|/* DMA support (drm_dma.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|dma_setup
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|dma_takedown
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|free_buffer
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|drm_buf_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|reclaim_buffers
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|DRMFILE
name|filp
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__HAVE_DMA_IRQ
end_if

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|irq_install
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|int
name|irq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|irq_uninstall
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|irqreturn_t
name|DRM
function_decl|(
name|dma_service
function_decl|)
parameter_list|(
name|DRM_IRQ_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|driver_irq_preinstall
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|driver_irq_postinstall
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|driver_irq_uninstall
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__HAVE_DMA_IRQ_BH
end_if

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|dma_immediate_bh
function_decl|)
parameter_list|(
name|DRM_TASKQUEUE_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Buffer list support (drm_lists.h) */
end_comment

begin_if
if|#
directive|if
name|__HAVE_DMA_WAITLIST
end_if

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|waitlist_create
function_decl|)
parameter_list|(
name|drm_waitlist_t
modifier|*
name|bl
parameter_list|,
name|int
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|waitlist_destroy
function_decl|)
parameter_list|(
name|drm_waitlist_t
modifier|*
name|bl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|waitlist_put
function_decl|)
parameter_list|(
name|drm_waitlist_t
modifier|*
name|bl
parameter_list|,
name|drm_buf_t
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|drm_buf_t
modifier|*
name|DRM
function_decl|(
name|waitlist_get
function_decl|)
parameter_list|(
name|drm_waitlist_t
modifier|*
name|bl
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HAVE_DMA */
end_comment

begin_if
if|#
directive|if
name|__HAVE_VBL_IRQ
end_if

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|vblank_wait
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
modifier|*
name|vbl_seq
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|vbl_send_signals
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__REALLY_HAVE_AGP
end_if

begin_comment
comment|/* AGP/GART support (drm_agpsupport.h) */
end_comment

begin_function_decl
specifier|extern
name|drm_agp_head_t
modifier|*
name|DRM
function_decl|(
name|agp_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|agp_uninit
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|agp_do_release
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|agp_memory
modifier|*
name|DRM
function_decl|(
name|agp_allocate_memory
function_decl|)
parameter_list|(
name|size_t
name|pages
parameter_list|,
name|u32
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|agp_free_memory
function_decl|)
parameter_list|(
name|agp_memory
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|agp_bind_memory
function_decl|)
parameter_list|(
name|agp_memory
modifier|*
name|handle
parameter_list|,
name|off_t
name|start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|agp_unbind_memory
function_decl|)
parameter_list|(
name|agp_memory
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__HAVE_SG
end_if

begin_comment
comment|/* Scatter Gather Support (drm_scatter.h) */
end_comment

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|sg_cleanup
function_decl|)
parameter_list|(
name|drm_sg_mem_t
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__REALLY_HAVE_SG
end_if

begin_comment
comment|/* ATI PCIGART support (ati_pcigart.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|ati_pcigart_init
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|unsigned
name|long
modifier|*
name|addr
parameter_list|,
name|dma_addr_t
modifier|*
name|bus_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|ati_pcigart_cleanup
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|unsigned
name|long
name|addr
parameter_list|,
name|dma_addr_t
name|bus_addr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Locking IOCTL support (drm_drv.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|lock
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|unlock
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Misc. IOCTL support (drm_ioctl.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|irq_busid
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|getunique
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|setunique
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|getmap
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|getclient
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|getstats
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|noop
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Context IOCTL support (drm_context.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|resctx
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|addctx
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|modctx
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|getctx
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|switchctx
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|newctx
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|rmctx
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|setsareactx
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|getsareactx
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Drawable IOCTL support (drm_drawable.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|adddraw
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|rmdraw
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Authentication IOCTL support (drm_auth.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|getmagic
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|authmagic
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Buffer management support (drm_bufs.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|addmap
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|rmmap
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__HAVE_DMA
end_if

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|addbufs
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|infobufs
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|markbufs
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|freebufs
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|mapbufs
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DMA support (drm_dma.h) */
end_comment

begin_if
if|#
directive|if
name|__HAVE_DMA
end_if

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|control
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__HAVE_VBL_IRQ
end_if

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|wait_vblank
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AGP/GART support (drm_agpsupport.h) */
end_comment

begin_if
if|#
directive|if
name|__REALLY_HAVE_AGP
end_if

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|agp_acquire
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|agp_release
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|agp_enable
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|agp_info
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|agp_alloc
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|agp_free
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|agp_unbind
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|agp_bind
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Scatter Gather Support (drm_scatter.h) */
end_comment

begin_if
if|#
directive|if
name|__HAVE_SG
end_if

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|sg_alloc
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|sg_free
function_decl|)
parameter_list|(
name|DRM_IOCTL_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* consistent PCI memory functions (drm_pci.h) */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|DRM
function_decl|(
name|pci_alloc
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|align
parameter_list|,
name|dma_addr_t
name|maxaddr
parameter_list|,
name|dma_addr_t
modifier|*
name|busaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|pci_free
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|size_t
name|size
parameter_list|,
name|void
modifier|*
name|vaddr
parameter_list|,
name|dma_addr_t
name|busaddr
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __KERNEL__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DRM_P_H_ */
end_comment

end_unit

