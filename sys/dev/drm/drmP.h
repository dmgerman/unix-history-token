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

begin_ifndef
ifndef|#
directive|ifndef
name|__HAVE_DMA_WAITLIST
end_ifndef

begin_define
define|#
directive|define
name|__HAVE_DMA_WAITLIST
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__HAVE_DMA_FREELIST
end_ifndef

begin_define
define|#
directive|define
name|__HAVE_DMA_FREELIST
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__HAVE_DMA_HISTOGRAM
end_ifndef

begin_define
define|#
directive|define
name|__HAVE_DMA_HISTOGRAM
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
name|__linux__
end_ifdef

begin_include
include|#
directive|include
file|"dev/drm/drm_os_linux.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

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
name|DRM_LOOPING_LIMIT
value|5000000
end_define

begin_define
define|#
directive|define
name|DRM_BSZ
value|1024
end_define

begin_comment
comment|/* Buffer size for /dev/drm? output	  */
end_comment

begin_define
define|#
directive|define
name|DRM_LOCK_SLICE
value|1
end_define

begin_comment
comment|/* Time slice for lock, in jiffies	  */
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
name|DRM_FLAG_NOCTX
value|0x02
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
name|DRM_MEM_VMAS
value|6
end_define

begin_define
define|#
directive|define
name|DRM_MEM_BUFS
value|7
end_define

begin_define
define|#
directive|define
name|DRM_MEM_SEGS
value|8
end_define

begin_define
define|#
directive|define
name|DRM_MEM_PAGES
value|9
end_define

begin_define
define|#
directive|define
name|DRM_MEM_FILES
value|10
end_define

begin_define
define|#
directive|define
name|DRM_MEM_QUEUES
value|11
end_define

begin_define
define|#
directive|define
name|DRM_MEM_CMDS
value|12
end_define

begin_define
define|#
directive|define
name|DRM_MEM_MAPPINGS
value|13
end_define

begin_define
define|#
directive|define
name|DRM_MEM_BUFLISTS
value|14
end_define

begin_define
define|#
directive|define
name|DRM_MEM_AGPLISTS
value|15
end_define

begin_define
define|#
directive|define
name|DRM_MEM_TOTALAGP
value|16
end_define

begin_define
define|#
directive|define
name|DRM_MEM_BOUNDAGP
value|17
end_define

begin_define
define|#
directive|define
name|DRM_MEM_CTXBITMAP
value|18
end_define

begin_define
define|#
directive|define
name|DRM_MEM_STUB
value|19
end_define

begin_define
define|#
directive|define
name|DRM_MEM_SGLISTS
value|20
end_define

begin_define
define|#
directive|define
name|DRM_MAX_CTXBITMAP
value|(PAGE_SIZE * 8)
end_define

begin_comment
comment|/* Backward compatibility section */
end_comment

begin_comment
comment|/* _PAGE_WT changed to _PAGE_PWT in 2.2.6 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PAGE_PWT
end_ifndef

begin_define
define|#
directive|define
name|_PAGE_PWT
value|_PAGE_WT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Mapping helper macros */
end_comment

begin_define
define|#
directive|define
name|DRM_IOREMAP
parameter_list|(
name|map
parameter_list|)
define|\
value|(map)->handle = DRM(ioremap)( (map)->offset, (map)->size )
end_define

begin_define
define|#
directive|define
name|DRM_IOREMAPFREE
parameter_list|(
name|map
parameter_list|)
define|\
value|do {								\ 		if ( (map)->handle&& (map)->size )			\ 			DRM(ioremapfree)( (map)->handle, (map)->size );	\ 	} while (0)
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

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_typedef
typedef|typedef
name|int
name|drm_ioctl_t
parameter_list|(
name|DRM_OS_IOCTL
parameter_list|)
function_decl|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_pci_list
block|{
name|u16
name|vendor
decl_stmt|;
name|u16
name|device
decl_stmt|;
block|}
name|drm_pci_list_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_ioctl_desc
block|{
ifdef|#
directive|ifdef
name|__linux__
name|drm_ioctl_t
modifier|*
name|func
decl_stmt|;
endif|#
directive|endif
comment|/* __linux__ */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|d_ioctl_t
modifier|*
name|func
decl_stmt|;
endif|#
directive|endif
comment|/* __FreeBSD__ */
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
name|drm_devstate
block|{
name|pid_t
name|owner
decl_stmt|;
comment|/* X server pid holding x_lock */
block|}
name|drm_devstate_t
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
name|drm_vma_entry
block|{
name|struct
name|vm_area_struct
modifier|*
name|vma
decl_stmt|;
name|struct
name|drm_vma_entry
modifier|*
name|next
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
block|}
name|drm_vma_entry_t
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
name|waiting
decl_stmt|;
comment|/* On kernel DMA queue		     */
specifier|__volatile__
name|int
name|pending
decl_stmt|;
comment|/* On hardware DMA queue		     */
name|wait_queue_head_t
name|dma_wait
decl_stmt|;
comment|/* Processes waiting		     */
name|pid_t
name|pid
decl_stmt|;
comment|/* PID of holding process	     */
name|int
name|context
decl_stmt|;
comment|/* Kernel queue for this buffer	     */
name|int
name|while_locked
decl_stmt|;
comment|/* Dispatch this buffer while locked  */
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
if|#
directive|if
name|DRM_DMA_HISTOGRAM
name|cycles_t
name|time_queued
decl_stmt|;
comment|/* Queued to kernel DMA queue     */
name|cycles_t
name|time_dispatched
decl_stmt|;
comment|/* Dispatched to hardware	     */
name|cycles_t
name|time_completed
decl_stmt|;
comment|/* Completed by hardware	     */
name|cycles_t
name|time_freed
decl_stmt|;
comment|/* Back on freelist		     */
endif|#
directive|endif
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

begin_if
if|#
directive|if
name|DRM_DMA_HISTOGRAM
end_if

begin_define
define|#
directive|define
name|DRM_DMA_HISTOGRAM_SLOTS
value|9
end_define

begin_define
define|#
directive|define
name|DRM_DMA_HISTOGRAM_INITIAL
value|10
end_define

begin_define
define|#
directive|define
name|DRM_DMA_HISTOGRAM_NEXT
parameter_list|(
name|current
parameter_list|)
value|((current)*10)
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_histogram
block|{
name|atomic_t
name|total
decl_stmt|;
name|atomic_t
name|queued_to_dispatched
index|[
name|DRM_DMA_HISTOGRAM_SLOTS
index|]
decl_stmt|;
name|atomic_t
name|dispatched_to_completed
index|[
name|DRM_DMA_HISTOGRAM_SLOTS
index|]
decl_stmt|;
name|atomic_t
name|completed_to_freed
index|[
name|DRM_DMA_HISTOGRAM_SLOTS
index|]
decl_stmt|;
name|atomic_t
name|queued_to_completed
index|[
name|DRM_DMA_HISTOGRAM_SLOTS
index|]
decl_stmt|;
name|atomic_t
name|queued_to_freed
index|[
name|DRM_DMA_HISTOGRAM_SLOTS
index|]
decl_stmt|;
name|atomic_t
name|dma
index|[
name|DRM_DMA_HISTOGRAM_SLOTS
index|]
decl_stmt|;
name|atomic_t
name|schedule
index|[
name|DRM_DMA_HISTOGRAM_SLOTS
index|]
decl_stmt|;
name|atomic_t
name|ctx
index|[
name|DRM_DMA_HISTOGRAM_SLOTS
index|]
decl_stmt|;
name|atomic_t
name|lacq
index|[
name|DRM_DMA_HISTOGRAM_SLOTS
index|]
decl_stmt|;
name|atomic_t
name|lhld
index|[
name|DRM_DMA_HISTOGRAM_SLOTS
index|]
decl_stmt|;
block|}
name|drm_histogram_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

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
name|DRM_OS_SPINTYPE
name|read_lock
decl_stmt|;
name|DRM_OS_SPINTYPE
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
name|wait_queue_head_t
name|waiting
decl_stmt|;
comment|/* Processes waiting on free bufs   */
name|int
name|low_mark
decl_stmt|;
comment|/* Low water mark		   */
name|int
name|high_mark
decl_stmt|;
comment|/* High water mark		   */
name|atomic_t
name|wfh
decl_stmt|;
comment|/* If waiting for high mark	   */
name|DRM_OS_SPINTYPE
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
name|unsigned
name|long
modifier|*
name|seglist
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

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_struct
struct|struct
name|drm_file
block|{
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
name|drm_magic_t
name|magic
decl_stmt|;
name|unsigned
name|long
name|ioctl_count
decl_stmt|;
name|struct
name|drm_file
modifier|*
name|next
decl_stmt|;
name|struct
name|drm_file
modifier|*
name|prev
decl_stmt|;
name|struct
name|drm_device
modifier|*
name|dev
decl_stmt|;
name|int
name|remove_auth_on_close
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_queue
block|{
name|atomic_t
name|use_count
decl_stmt|;
comment|/* Outstanding uses (+1)	    */
name|atomic_t
name|finalization
decl_stmt|;
comment|/* Finalization in progress	    */
name|atomic_t
name|block_count
decl_stmt|;
comment|/* Count of processes waiting	    */
name|atomic_t
name|block_read
decl_stmt|;
comment|/* Queue blocked for reads	    */
name|wait_queue_head_t
name|read_queue
decl_stmt|;
comment|/* Processes waiting on block_read  */
name|atomic_t
name|block_write
decl_stmt|;
comment|/* Queue blocked for writes	    */
name|wait_queue_head_t
name|write_queue
decl_stmt|;
comment|/* Processes waiting on block_write */
if|#
directive|if
literal|1
name|atomic_t
name|total_queued
decl_stmt|;
comment|/* Total queued statistic	    */
name|atomic_t
name|total_flushed
decl_stmt|;
comment|/* Total flushes statistic	    */
name|atomic_t
name|total_locks
decl_stmt|;
comment|/* Total locks statistics	    */
endif|#
directive|endif
name|drm_ctx_flags_t
name|flags
decl_stmt|;
comment|/* Context preserving and 2D-only   */
name|drm_waitlist_t
name|waitlist
decl_stmt|;
comment|/* Pending buffers		    */
name|wait_queue_head_t
name|flush_queue
decl_stmt|;
comment|/* Processes waiting until flush    */
block|}
name|drm_queue_t
typedef|;
end_typedef

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
name|pid_t
name|pid
decl_stmt|;
comment|/* PID of lock holder (0=kernel)   */
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
if|#
directive|if
literal|0
comment|/* Performance Counters */
block|atomic_t	  total_prio;
comment|/* Total DRM_DMA_PRIORITY	   */
block|atomic_t	  total_bytes;
comment|/* Total bytes DMA'd		   */
block|atomic_t	  total_dmas;
comment|/* Total DMA buffers dispatched	   */
block|atomic_t	  total_missed_dma;
comment|/* Missed drm_do_dma	    */
block|atomic_t	  total_missed_lock;
comment|/* Missed lock in drm_do_dma   */
block|atomic_t	  total_missed_free;
comment|/* Missed drm_free_this_buffer */
block|atomic_t	  total_missed_sched;
comment|/* Missed drm_dma_schedule	    */
block|atomic_t	  total_tried;
comment|/* Tried next_buffer		    */
block|atomic_t	  total_hit;
comment|/* Sent next_buffer		    */
block|atomic_t	  total_lost;
comment|/* Lost interrupt		    */
endif|#
directive|endif
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
name|drm_queue_t
modifier|*
name|next_queue
decl_stmt|;
comment|/* Queue from which buffer selected*/
name|wait_queue_head_t
name|waiting
decl_stmt|;
comment|/* Processes waiting on free bufs  */
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
ifdef|#
directive|ifdef
name|__linux__
name|unsigned
name|long
name|handle
decl_stmt|;
name|agp_memory
modifier|*
name|memory
decl_stmt|;
endif|#
directive|endif
comment|/* __linux__ */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|void
modifier|*
name|handle
decl_stmt|;
endif|#
directive|endif
comment|/* __FreeBSD__ */
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
ifdef|#
directive|ifdef
name|__linux__
name|agp_kern_info
name|agp_info
decl_stmt|;
endif|#
directive|endif
comment|/* __linux__ */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|device_t
name|agpdev
decl_stmt|;
name|struct
name|agp_info
name|info
decl_stmt|;
endif|#
directive|endif
comment|/* __FreeBSD__ */
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
name|struct
name|page
modifier|*
modifier|*
name|pagelist
decl_stmt|;
ifdef|#
directive|ifdef
name|__linux__
name|dma_addr_t
modifier|*
name|busaddr
decl_stmt|;
endif|#
directive|endif
comment|/* __linux__ */
block|}
name|drm_sg_mem_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_sigdata
block|{
name|int
name|context
decl_stmt|;
name|drm_hw_lock_t
modifier|*
name|lock
decl_stmt|;
block|}
name|drm_sigdata_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|__linux__
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|drm_map_list
block|{
name|struct
name|list_head
name|head
decl_stmt|;
name|drm_map_t
modifier|*
name|map
decl_stmt|;
block|}
name|drm_map_list_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __linux__ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__FreeBSD__
end_ifdef

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
name|drm_map_t
modifier|*
name|map
decl_stmt|;
block|}
name|drm_map_list_entry_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FreeBSD__ */
end_comment

begin_struct
struct|struct
name|drm_device
block|{
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
name|__linux__
name|dev_t
name|device
decl_stmt|;
comment|/* Device number for mknod	   */
endif|#
directive|endif
comment|/* __linux__ */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|device_t
name|device
decl_stmt|;
comment|/* Device instance from newbus     */
name|dev_t
name|devnode
decl_stmt|;
comment|/* Device number for mknod	   */
endif|#
directive|endif
comment|/* __FreeBSD__ */
name|char
modifier|*
name|devname
decl_stmt|;
comment|/* For /proc/interrupts		   */
name|int
name|blocked
decl_stmt|;
comment|/* Blocked due to VC switch?	   */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|int
name|flags
decl_stmt|;
comment|/* Flags to open(2)		   */
name|int
name|writable
decl_stmt|;
comment|/* Opened with FWRITE		   */
endif|#
directive|endif
comment|/* __FreeBSD__ */
name|struct
name|proc_dir_entry
modifier|*
name|root
decl_stmt|;
comment|/* Root for this device's entries  */
comment|/* Locks */
ifdef|#
directive|ifdef
name|__linux__
name|spinlock_t
name|count_lock
decl_stmt|;
comment|/* For inuse, open_count, buf_use  */
name|struct
name|semaphore
name|struct_sem
decl_stmt|;
comment|/* For others			   */
endif|#
directive|endif
comment|/* __linux__ */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|DRM_OS_SPINTYPE
name|count_lock
decl_stmt|;
comment|/* For inuse, open_count, buf_use  */
name|struct
name|lock
name|dev_lock
decl_stmt|;
comment|/* For others			   */
endif|#
directive|endif
comment|/* __FreeBSD__ */
comment|/* Usage Counters */
name|int
name|open_count
decl_stmt|;
comment|/* Outstanding files open	   */
name|atomic_t
name|ioctl_count
decl_stmt|;
comment|/* Outstanding IOCTLs pending	   */
name|atomic_t
name|vma_count
decl_stmt|;
comment|/* Outstanding vma areas open	   */
name|int
name|buf_use
decl_stmt|;
comment|/* Buffers in use -- cannot alloc  */
name|atomic_t
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
ifdef|#
directive|ifdef
name|__linux__
name|drm_file_t
modifier|*
name|file_first
decl_stmt|;
name|drm_file_t
modifier|*
name|file_last
decl_stmt|;
endif|#
directive|endif
comment|/* __linux__ */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|drm_file_list_t
name|files
decl_stmt|;
endif|#
directive|endif
comment|/* __FreeBSD__ */
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
name|int
name|map_count
decl_stmt|;
comment|/* Number of mappable regions	   */
name|drm_map_t
modifier|*
modifier|*
name|context_sareas
decl_stmt|;
name|int
name|max_context
decl_stmt|;
name|drm_vma_entry_t
modifier|*
name|vmalist
decl_stmt|;
comment|/* List of vmas (for debugging)	   */
name|drm_lock_data_t
name|lock
decl_stmt|;
comment|/* Information on hardware lock	   */
comment|/* DMA queues (contexts) */
name|int
name|queue_count
decl_stmt|;
comment|/* Number of active DMA queues	   */
name|int
name|queue_reserved
decl_stmt|;
comment|/* Number of reserved DMA queues */
name|int
name|queue_slots
decl_stmt|;
comment|/* Actual length of queuelist	   */
name|drm_queue_t
modifier|*
modifier|*
name|queuelist
decl_stmt|;
comment|/* Vector of pointers to DMA queues */
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
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|resource
modifier|*
name|irqr
decl_stmt|;
comment|/* Resource for interrupt used by board	   */
name|void
modifier|*
name|irqh
decl_stmt|;
comment|/* Handle from bus_setup_intr      */
endif|#
directive|endif
comment|/* __FreeBSD__ */
specifier|__volatile__
name|long
name|context_flag
decl_stmt|;
comment|/* Context swapping flag	   */
specifier|__volatile__
name|long
name|interrupt_flag
decl_stmt|;
comment|/* Interruption handler flag	   */
specifier|__volatile__
name|long
name|dma_flag
decl_stmt|;
comment|/* DMA dispatch flag		   */
ifdef|#
directive|ifdef
name|__linux__
name|struct
name|timer_list
name|timer
decl_stmt|;
comment|/* Timer for delaying ctx switch   */
endif|#
directive|endif
comment|/* __linux__ */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|callout
name|timer
decl_stmt|;
comment|/* Timer for delaying ctx switch   */
endif|#
directive|endif
comment|/* __FreeBSD__ */
name|wait_queue_head_t
name|context_wait
decl_stmt|;
comment|/* Processes waiting on ctx switch */
name|int
name|last_checked
decl_stmt|;
comment|/* Last context checked for DMA	   */
name|int
name|last_context
decl_stmt|;
comment|/* Last current context		   */
name|unsigned
name|long
name|last_switch
decl_stmt|;
comment|/* jiffies at last context switch  */
ifdef|#
directive|ifdef
name|__linux__
name|struct
name|tq_struct
name|tq
decl_stmt|;
endif|#
directive|endif
comment|/* __linux__ */
ifdef|#
directive|ifdef
name|__FreeBSD__
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
endif|#
directive|endif
comment|/* __FreeBSD__ */
name|cycles_t
name|ctx_start
decl_stmt|;
name|cycles_t
name|lck_start
decl_stmt|;
if|#
directive|if
name|__HAVE_DMA_HISTOGRAM
name|drm_histogram_t
name|histo
decl_stmt|;
endif|#
directive|endif
comment|/* Callback to X server for context switch 				   and for heavy-handed reset. */
name|char
name|buf
index|[
name|DRM_BSZ
index|]
decl_stmt|;
comment|/* Output buffer		   */
name|char
modifier|*
name|buf_rp
decl_stmt|;
comment|/* Read pointer			   */
name|char
modifier|*
name|buf_wp
decl_stmt|;
comment|/* Write pointer		   */
name|char
modifier|*
name|buf_end
decl_stmt|;
comment|/* End pointer			   */
ifdef|#
directive|ifdef
name|__linux__
name|struct
name|fasync_struct
modifier|*
name|buf_async
decl_stmt|;
comment|/* Processes waiting for SIGIO	   */
endif|#
directive|endif
comment|/* __linux__ */
ifdef|#
directive|ifdef
name|__FreeBSD__
name|struct
name|sigio
modifier|*
name|buf_sigio
decl_stmt|;
comment|/* Processes waiting for SIGIO     */
name|struct
name|selinfo
name|buf_sel
decl_stmt|;
comment|/* Workspace for select/poll       */
name|int
name|buf_selecting
decl_stmt|;
comment|/* True if poll sleeper            */
endif|#
directive|endif
comment|/* __FreeBSD__ */
name|wait_queue_head_t
name|buf_readers
decl_stmt|;
comment|/* Processes waiting to read	   */
name|wait_queue_head_t
name|buf_writers
decl_stmt|;
comment|/* Processes waiting to ctx switch */
ifdef|#
directive|ifdef
name|__FreeBSD__
comment|/* Sysctl support */
name|struct
name|drm_sysctl_info
modifier|*
name|sysctl
decl_stmt|;
endif|#
directive|endif
comment|/* __FreeBSD__ */
if|#
directive|if
name|__REALLY_HAVE_AGP
name|drm_agp_head_t
modifier|*
name|agp
decl_stmt|;
endif|#
directive|endif
name|struct
name|pci_dev
modifier|*
name|pdev
decl_stmt|;
ifdef|#
directive|ifdef
name|__alpha__
if|#
directive|if
name|LINUX_VERSION_CODE
operator|<
literal|0x020403
name|struct
name|pci_controler
modifier|*
name|hose
decl_stmt|;
else|#
directive|else
name|struct
name|pci_controller
modifier|*
name|hose
decl_stmt|;
endif|#
directive|endif
endif|#
directive|endif
name|drm_sg_mem_t
modifier|*
name|sg
decl_stmt|;
comment|/* Scatter gather memory */
name|unsigned
name|long
modifier|*
name|ctx_bitmap
decl_stmt|;
name|void
modifier|*
name|dev_private
decl_stmt|;
name|drm_sigdata_t
name|sigdata
decl_stmt|;
comment|/* For block_all_signals */
name|sigset_t
name|sigmask
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

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|parse_options
function_decl|)
parameter_list|(
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|cpu_valid
function_decl|)
parameter_list|(
name|void
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
name|DRM_OS_IOCTL
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|write_string
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
specifier|const
name|char
modifier|*
name|s
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
name|char
modifier|*
name|DRM
function_decl|(
name|strdup
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|s
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
name|strfree
function_decl|)
parameter_list|(
name|char
modifier|*
name|s
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
name|unsigned
name|long
name|DRM
function_decl|(
name|alloc_pages
function_decl|)
parameter_list|(
name|int
name|order
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
name|free_pages
function_decl|)
parameter_list|(
name|unsigned
name|long
name|address
parameter_list|,
name|int
name|order
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
name|unsigned
name|long
name|offset
parameter_list|,
name|unsigned
name|long
name|size
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
name|void
modifier|*
name|pt
parameter_list|,
name|unsigned
name|long
name|size
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

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|flush_unblock
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|int
name|context
parameter_list|,
name|drm_lock_flags_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|flush_block_and_flush
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|int
name|context
parameter_list|,
name|drm_lock_flags_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|notifier
function_decl|)
parameter_list|(
name|void
modifier|*
name|priv
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
name|pid_t
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|__HAVE_OLD_DMA
end_if

begin_comment
comment|/* GH: This is a dirty hack for now...  */
end_comment

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|clear_next_buffer
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
name|int
name|DRM
function_decl|(
name|select_queue
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|void
function_decl|(
modifier|*
name|wrapper
function_decl|)
parameter_list|(
name|unsigned
name|long
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|dma_enqueue
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|drm_dma_t
modifier|*
name|dma
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|dma_get_buffers
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|drm_dma_t
modifier|*
name|dma
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
name|void
name|DRM
function_decl|(
name|dma_service
function_decl|)
parameter_list|(
name|DRM_OS_IRQ_ARGS
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
name|DRM_OS_TASKQUEUE_ARGS
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

begin_if
if|#
directive|if
name|DRM_DMA_HISTOGRAM
end_if

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|histogram_slot
function_decl|)
parameter_list|(
name|unsigned
name|long
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DRM
function_decl|(
name|histogram_compute
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

begin_if
if|#
directive|if
name|__HAVE_DMA_FREELIST
end_if

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|freelist_create
function_decl|)
parameter_list|(
name|drm_freelist_t
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
name|freelist_destroy
function_decl|)
parameter_list|(
name|drm_freelist_t
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
name|freelist_put
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|drm_freelist_t
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
name|freelist_get
function_decl|)
parameter_list|(
name|drm_freelist_t
modifier|*
name|bl
parameter_list|,
name|int
name|block
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

begin_comment
comment|/* Proc support (drm_proc.h) */
end_comment

begin_function_decl
specifier|extern
name|struct
name|proc_dir_entry
modifier|*
name|DRM
function_decl|(
name|proc_init
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|int
name|minor
parameter_list|,
name|struct
name|proc_dir_entry
modifier|*
name|root
parameter_list|,
name|struct
name|proc_dir_entry
modifier|*
modifier|*
name|dev_root
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|proc_cleanup
function_decl|)
parameter_list|(
name|int
name|minor
parameter_list|,
name|struct
name|proc_dir_entry
modifier|*
name|root
parameter_list|,
name|struct
name|proc_dir_entry
modifier|*
name|dev_root
parameter_list|)
function_decl|;
end_function_decl

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

end_unit

