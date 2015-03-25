begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file drm.h  * Header for the Direct Rendering Manager  *  * \author Rickard E. (Rik) Faith<faith@valinux.com>  *  * \par Acknowledgments:  * Dec 1999, Richard Henderson<rth@twiddle.net>, move to generic \c cmpxchg.  */
end_comment

begin_comment
comment|/*-  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|_DRM_H_
end_ifndef

begin_define
define|#
directive|define
name|_DRM_H_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<asm/ioctl.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|int
name|drm_handle_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* One of the BSDs */
end_comment

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_typedef
typedef|typedef
name|int8_t
name|__s8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|__u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|__s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|__u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|__s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|__u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|__s64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|__u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|drm_handle_t
typedef|;
end_typedef

begin_include
include|#
directive|include
file|<dev/drm2/drm_os_freebsd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DRM_NAME
value|"drm"
end_define

begin_comment
comment|/**< Name in kernel, /dev, and /proc */
end_comment

begin_define
define|#
directive|define
name|DRM_MIN_ORDER
value|5
end_define

begin_comment
comment|/**< At least 2^5 bytes = 32 bytes */
end_comment

begin_define
define|#
directive|define
name|DRM_MAX_ORDER
value|22
end_define

begin_comment
comment|/**< Up to 2^22 bytes = 4MB */
end_comment

begin_define
define|#
directive|define
name|DRM_RAM_PERCENT
value|10
end_define

begin_comment
comment|/**< How much system ram can we lock? */
end_comment

begin_define
define|#
directive|define
name|_DRM_LOCK_HELD
value|0x80000000U
end_define

begin_comment
comment|/**< Hardware lock is held */
end_comment

begin_define
define|#
directive|define
name|_DRM_LOCK_CONT
value|0x40000000U
end_define

begin_comment
comment|/**< Hardware lock is contended */
end_comment

begin_define
define|#
directive|define
name|_DRM_LOCK_IS_HELD
parameter_list|(
name|lock
parameter_list|)
value|((lock)& _DRM_LOCK_HELD)
end_define

begin_define
define|#
directive|define
name|_DRM_LOCK_IS_CONT
parameter_list|(
name|lock
parameter_list|)
value|((lock)& _DRM_LOCK_CONT)
end_define

begin_define
define|#
directive|define
name|_DRM_LOCKING_CONTEXT
parameter_list|(
name|lock
parameter_list|)
value|((lock)& ~(_DRM_LOCK_HELD|_DRM_LOCK_CONT))
end_define

begin_typedef
typedef|typedef
name|unsigned
name|int
name|drm_context_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|drm_drawable_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|drm_magic_t
typedef|;
end_typedef

begin_comment
comment|/**  * Cliprect.  *  * \warning: If you change this structure, make sure you change  * XF86DRIClipRectRec in the server as well  *  * \note KW: Actually it's illegal to change either for  * backwards-compatibility reasons.  */
end_comment

begin_struct
struct|struct
name|drm_clip_rect
block|{
name|unsigned
name|short
name|x1
decl_stmt|;
name|unsigned
name|short
name|y1
decl_stmt|;
name|unsigned
name|short
name|x2
decl_stmt|;
name|unsigned
name|short
name|y2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Drawable information.  */
end_comment

begin_struct
struct|struct
name|drm_drawable_info
block|{
name|unsigned
name|int
name|num_rects
decl_stmt|;
name|struct
name|drm_clip_rect
modifier|*
name|rects
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Texture region,  */
end_comment

begin_struct
struct|struct
name|drm_tex_region
block|{
name|unsigned
name|char
name|next
decl_stmt|;
name|unsigned
name|char
name|prev
decl_stmt|;
name|unsigned
name|char
name|in_use
decl_stmt|;
name|unsigned
name|char
name|padding
decl_stmt|;
name|unsigned
name|int
name|age
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Hardware lock.  *  * The lock structure is a simple cache-line aligned integer.  To avoid  * processor bus contention on a multiprocessor system, there should not be any  * other data stored in the same cache line.  */
end_comment

begin_struct
struct|struct
name|drm_hw_lock
block|{
specifier|__volatile__
name|unsigned
name|int
name|lock
decl_stmt|;
comment|/**< lock variable */
name|char
name|padding
index|[
literal|60
index|]
decl_stmt|;
comment|/**< Pad to cache line */
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_VERSION ioctl argument type.  *  * \sa drmGetVersion().  */
end_comment

begin_struct
struct|struct
name|drm_version
block|{
name|int
name|version_major
decl_stmt|;
comment|/**< Major version */
name|int
name|version_minor
decl_stmt|;
comment|/**< Minor version */
name|int
name|version_patchlevel
decl_stmt|;
comment|/**< Patch level */
name|size_t
name|name_len
decl_stmt|;
comment|/**< Length of name buffer */
name|char
name|__user
modifier|*
name|name
decl_stmt|;
comment|/**< Name of driver */
name|size_t
name|date_len
decl_stmt|;
comment|/**< Length of date buffer */
name|char
name|__user
modifier|*
name|date
decl_stmt|;
comment|/**< User-space buffer to hold date */
name|size_t
name|desc_len
decl_stmt|;
comment|/**< Length of desc buffer */
name|char
name|__user
modifier|*
name|desc
decl_stmt|;
comment|/**< User-space buffer to hold desc */
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_GET_UNIQUE ioctl argument type.  *  * \sa drmGetBusid() and drmSetBusId().  */
end_comment

begin_struct
struct|struct
name|drm_unique
block|{
name|size_t
name|unique_len
decl_stmt|;
comment|/**< Length of unique */
name|char
name|__user
modifier|*
name|unique
decl_stmt|;
comment|/**< Unique name for driver instantiation */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_list
block|{
name|int
name|count
decl_stmt|;
comment|/**< Length of user-space structures */
name|struct
name|drm_version
name|__user
modifier|*
name|version
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_block
block|{
name|int
name|unused
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_CONTROL ioctl argument type.  *  * \sa drmCtlInstHandler() and drmCtlUninstHandler().  */
end_comment

begin_struct
struct|struct
name|drm_control
block|{
enum|enum
block|{
name|DRM_ADD_COMMAND
block|,
name|DRM_RM_COMMAND
block|,
name|DRM_INST_HANDLER
block|,
name|DRM_UNINST_HANDLER
block|}
name|func
enum|;
name|int
name|irq
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Type of memory to map.  */
end_comment

begin_enum
enum|enum
name|drm_map_type
block|{
name|_DRM_FRAME_BUFFER
init|=
literal|0
block|,
comment|/**< WC (no caching), no core dump */
name|_DRM_REGISTERS
init|=
literal|1
block|,
comment|/**< no caching, no core dump */
name|_DRM_SHM
init|=
literal|2
block|,
comment|/**< shared, cached */
name|_DRM_AGP
init|=
literal|3
block|,
comment|/**< AGP/GART */
name|_DRM_SCATTER_GATHER
init|=
literal|4
block|,
comment|/**< Scatter/gather memory for PCI DMA */
name|_DRM_CONSISTENT
init|=
literal|5
block|,
comment|/**< Consistent memory for PCI DMA */
name|_DRM_GEM
init|=
literal|6
block|,
comment|/**< GEM object */
block|}
enum|;
end_enum

begin_comment
comment|/**  * Memory mapping flags.  */
end_comment

begin_enum
enum|enum
name|drm_map_flags
block|{
name|_DRM_RESTRICTED
init|=
literal|0x01
block|,
comment|/**< Cannot be mapped to user-virtual */
name|_DRM_READ_ONLY
init|=
literal|0x02
block|,
name|_DRM_LOCKED
init|=
literal|0x04
block|,
comment|/**< shared, cached, locked */
name|_DRM_KERNEL
init|=
literal|0x08
block|,
comment|/**< kernel requires access */
name|_DRM_WRITE_COMBINING
init|=
literal|0x10
block|,
comment|/**< use write-combining if available */
name|_DRM_CONTAINS_LOCK
init|=
literal|0x20
block|,
comment|/**< SHM page that contains lock */
name|_DRM_REMOVABLE
init|=
literal|0x40
block|,
comment|/**< Removable mapping */
name|_DRM_DRIVER
init|=
literal|0x80
comment|/**< Managed by driver */
block|}
enum|;
end_enum

begin_struct
struct|struct
name|drm_ctx_priv_map
block|{
name|unsigned
name|int
name|ctx_id
decl_stmt|;
comment|/**< Context requesting private mapping */
name|void
modifier|*
name|handle
decl_stmt|;
comment|/**< Handle of map */
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_GET_MAP, DRM_IOCTL_ADD_MAP and DRM_IOCTL_RM_MAP ioctls  * argument type.  *  * \sa drmAddMap().  */
end_comment

begin_struct
struct|struct
name|drm_map
block|{
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/**< Requested physical address (0 for SAREA)*/
name|unsigned
name|long
name|size
decl_stmt|;
comment|/**< Requested physical size (bytes) */
name|enum
name|drm_map_type
name|type
decl_stmt|;
comment|/**< Type of memory to map */
name|enum
name|drm_map_flags
name|flags
decl_stmt|;
comment|/**< Flags */
name|void
modifier|*
name|handle
decl_stmt|;
comment|/**< User-space: "Handle" to pass to mmap() */
comment|/**< Kernel-space: kernel-virtual address */
name|int
name|mtrr
decl_stmt|;
comment|/**< MTRR slot used */
comment|/*   Private data */
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_GET_CLIENT ioctl argument type.  */
end_comment

begin_struct
struct|struct
name|drm_client
block|{
name|int
name|idx
decl_stmt|;
comment|/**< Which client desired? */
name|int
name|auth
decl_stmt|;
comment|/**< Is client authenticated? */
name|unsigned
name|long
name|pid
decl_stmt|;
comment|/**< Process ID */
name|unsigned
name|long
name|uid
decl_stmt|;
comment|/**< User ID */
name|unsigned
name|long
name|magic
decl_stmt|;
comment|/**< Magic */
name|unsigned
name|long
name|iocs
decl_stmt|;
comment|/**< Ioctl count */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|drm_stat_type
block|{
name|_DRM_STAT_LOCK
block|,
name|_DRM_STAT_OPENS
block|,
name|_DRM_STAT_CLOSES
block|,
name|_DRM_STAT_IOCTLS
block|,
name|_DRM_STAT_LOCKS
block|,
name|_DRM_STAT_UNLOCKS
block|,
name|_DRM_STAT_VALUE
block|,
comment|/**< Generic value */
name|_DRM_STAT_BYTE
block|,
comment|/**< Generic byte counter (1024bytes/K) */
name|_DRM_STAT_COUNT
block|,
comment|/**< Generic non-byte counter (1000/k) */
name|_DRM_STAT_IRQ
block|,
comment|/**< IRQ */
name|_DRM_STAT_PRIMARY
block|,
comment|/**< Primary DMA bytes */
name|_DRM_STAT_SECONDARY
block|,
comment|/**< Secondary DMA bytes */
name|_DRM_STAT_DMA
block|,
comment|/**< DMA */
name|_DRM_STAT_SPECIAL
block|,
comment|/**< Special DMA (e.g., priority or polled) */
name|_DRM_STAT_MISSED
comment|/**< Missed DMA opportunity */
comment|/* Add to the *END* of the list */
block|}
enum|;
end_enum

begin_comment
comment|/**  * DRM_IOCTL_GET_STATS ioctl argument type.  */
end_comment

begin_struct
struct|struct
name|drm_stats
block|{
name|unsigned
name|long
name|count
decl_stmt|;
struct|struct
block|{
name|unsigned
name|long
name|value
decl_stmt|;
name|enum
name|drm_stat_type
name|type
decl_stmt|;
block|}
name|data
index|[
literal|15
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Hardware locking flags.  */
end_comment

begin_enum
enum|enum
name|drm_lock_flags
block|{
name|_DRM_LOCK_READY
init|=
literal|0x01
block|,
comment|/**< Wait until hardware is ready for DMA */
name|_DRM_LOCK_QUIESCENT
init|=
literal|0x02
block|,
comment|/**< Wait until hardware quiescent */
name|_DRM_LOCK_FLUSH
init|=
literal|0x04
block|,
comment|/**< Flush this context's DMA queue first */
name|_DRM_LOCK_FLUSH_ALL
init|=
literal|0x08
block|,
comment|/**< Flush all DMA queues first */
comment|/* These *HALT* flags aren't supported yet 	   -- they will be used to support the 	   full-screen DGA-like mode. */
name|_DRM_HALT_ALL_QUEUES
init|=
literal|0x10
block|,
comment|/**< Halt all current and future queues */
name|_DRM_HALT_CUR_QUEUES
init|=
literal|0x20
comment|/**< Halt all current queues */
block|}
enum|;
end_enum

begin_comment
comment|/**  * DRM_IOCTL_LOCK, DRM_IOCTL_UNLOCK and DRM_IOCTL_FINISH ioctl argument type.  *  * \sa drmGetLock() and drmUnlock().  */
end_comment

begin_struct
struct|struct
name|drm_lock
block|{
name|int
name|context
decl_stmt|;
name|enum
name|drm_lock_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DMA flags  *  * \warning  * These values \e must match xf86drm.h.  *  * \sa drm_dma.  */
end_comment

begin_enum
enum|enum
name|drm_dma_flags
block|{
comment|/* Flags for DMA buffer dispatch */
name|_DRM_DMA_BLOCK
init|=
literal|0x01
block|,
comment|/**< 				       * Block until buffer dispatched. 				       * 				       * \note The buffer may not yet have 				       * been processed by the hardware -- 				       * getting a hardware lock with the 				       * hardware quiescent will ensure 				       * that the buffer has been 				       * processed. 				       */
name|_DRM_DMA_WHILE_LOCKED
init|=
literal|0x02
block|,
comment|/**< Dispatch while lock held */
name|_DRM_DMA_PRIORITY
init|=
literal|0x04
block|,
comment|/**< High priority dispatch */
comment|/* Flags for DMA buffer request */
name|_DRM_DMA_WAIT
init|=
literal|0x10
block|,
comment|/**< Wait for free buffers */
name|_DRM_DMA_SMALLER_OK
init|=
literal|0x20
block|,
comment|/**< Smaller-than-requested buffers OK */
name|_DRM_DMA_LARGER_OK
init|=
literal|0x40
comment|/**< Larger-than-requested buffers OK */
block|}
enum|;
end_enum

begin_comment
comment|/**  * DRM_IOCTL_ADD_BUFS and DRM_IOCTL_MARK_BUFS ioctl argument type.  *  * \sa drmAddBufs().  */
end_comment

begin_struct
struct|struct
name|drm_buf_desc
block|{
name|int
name|count
decl_stmt|;
comment|/**< Number of buffers of this size */
name|int
name|size
decl_stmt|;
comment|/**< Size in bytes */
name|int
name|low_mark
decl_stmt|;
comment|/**< Low water mark */
name|int
name|high_mark
decl_stmt|;
comment|/**< High water mark */
enum|enum
block|{
name|_DRM_PAGE_ALIGN
init|=
literal|0x01
block|,
comment|/**< Align on page boundaries for DMA */
name|_DRM_AGP_BUFFER
init|=
literal|0x02
block|,
comment|/**< Buffer is in AGP space */
name|_DRM_SG_BUFFER
init|=
literal|0x04
block|,
comment|/**< Scatter/gather memory buffer */
name|_DRM_FB_BUFFER
init|=
literal|0x08
block|,
comment|/**< Buffer is in frame buffer */
name|_DRM_PCI_BUFFER_RO
init|=
literal|0x10
comment|/**< Map PCI DMA buffer read-only */
block|}
name|flags
enum|;
name|unsigned
name|long
name|agp_start
decl_stmt|;
comment|/**< 				  * Start address of where the AGP buffers are 				  * in the AGP aperture 				  */
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_INFO_BUFS ioctl argument type.  */
end_comment

begin_struct
struct|struct
name|drm_buf_info
block|{
name|int
name|count
decl_stmt|;
comment|/**< Entries in list */
name|struct
name|drm_buf_desc
name|__user
modifier|*
name|list
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_FREE_BUFS ioctl argument type.  */
end_comment

begin_struct
struct|struct
name|drm_buf_free
block|{
name|int
name|count
decl_stmt|;
name|int
name|__user
modifier|*
name|list
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Buffer information  *  * \sa drm_buf_map.  */
end_comment

begin_struct
struct|struct
name|drm_buf_pub
block|{
name|int
name|idx
decl_stmt|;
comment|/**< Index into the master buffer list */
name|int
name|total
decl_stmt|;
comment|/**< Buffer size */
name|int
name|used
decl_stmt|;
comment|/**< Amount of buffer in use (for DMA) */
name|void
name|__user
modifier|*
name|address
decl_stmt|;
comment|/**< Address of buffer */
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_MAP_BUFS ioctl argument type.  */
end_comment

begin_struct
struct|struct
name|drm_buf_map
block|{
name|int
name|count
decl_stmt|;
comment|/**< Length of the buffer list */
name|void
name|__user
modifier|*
name|virtual
decl_stmt|;
comment|/**< Mmap'd area in user-virtual */
name|struct
name|drm_buf_pub
name|__user
modifier|*
name|list
decl_stmt|;
comment|/**< Buffer information */
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_DMA ioctl argument type.  *  * Indices here refer to the offset into the buffer list in drm_buf_get.  *  * \sa drmDMA().  */
end_comment

begin_struct
struct|struct
name|drm_dma
block|{
name|int
name|context
decl_stmt|;
comment|/**< Context handle */
name|int
name|send_count
decl_stmt|;
comment|/**< Number of buffers to send */
name|int
name|__user
modifier|*
name|send_indices
decl_stmt|;
comment|/**< List of handles to buffers */
name|int
name|__user
modifier|*
name|send_sizes
decl_stmt|;
comment|/**< Lengths of data to send */
name|enum
name|drm_dma_flags
name|flags
decl_stmt|;
comment|/**< Flags */
name|int
name|request_count
decl_stmt|;
comment|/**< Number of buffers requested */
name|int
name|request_size
decl_stmt|;
comment|/**< Desired size for buffers */
name|int
name|__user
modifier|*
name|request_indices
decl_stmt|;
comment|/**< Buffer information */
name|int
name|__user
modifier|*
name|request_sizes
decl_stmt|;
name|int
name|granted_count
decl_stmt|;
comment|/**< Number of buffers granted */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|drm_ctx_flags
block|{
name|_DRM_CONTEXT_PRESERVED
init|=
literal|0x01
block|,
name|_DRM_CONTEXT_2DONLY
init|=
literal|0x02
block|}
enum|;
end_enum

begin_comment
comment|/**  * DRM_IOCTL_ADD_CTX ioctl argument type.  *  * \sa drmCreateContext() and drmDestroyContext().  */
end_comment

begin_struct
struct|struct
name|drm_ctx
block|{
name|drm_context_t
name|handle
decl_stmt|;
name|enum
name|drm_ctx_flags
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_RES_CTX ioctl argument type.  */
end_comment

begin_struct
struct|struct
name|drm_ctx_res
block|{
name|int
name|count
decl_stmt|;
name|struct
name|drm_ctx
name|__user
modifier|*
name|contexts
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_ADD_DRAW and DRM_IOCTL_RM_DRAW ioctl argument type.  */
end_comment

begin_struct
struct|struct
name|drm_draw
block|{
name|drm_drawable_t
name|handle
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_UPDATE_DRAW ioctl argument type.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|DRM_DRAWABLE_CLIPRECTS
block|, }
name|drm_drawable_info_type_t
typedef|;
end_typedef

begin_struct
struct|struct
name|drm_update_draw
block|{
name|drm_drawable_t
name|handle
decl_stmt|;
name|unsigned
name|int
name|type
decl_stmt|;
name|unsigned
name|int
name|num
decl_stmt|;
name|unsigned
name|long
name|long
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_GET_MAGIC and DRM_IOCTL_AUTH_MAGIC ioctl argument type.  */
end_comment

begin_struct
struct|struct
name|drm_auth
block|{
name|drm_magic_t
name|magic
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_IRQ_BUSID ioctl argument type.  *  * \sa drmGetInterruptFromBusID().  */
end_comment

begin_struct
struct|struct
name|drm_irq_busid
block|{
name|int
name|irq
decl_stmt|;
comment|/**< IRQ number */
name|int
name|busnum
decl_stmt|;
comment|/**< bus number */
name|int
name|devnum
decl_stmt|;
comment|/**< device number */
name|int
name|funcnum
decl_stmt|;
comment|/**< function number */
block|}
struct|;
end_struct

begin_enum
enum|enum
name|drm_vblank_seq_type
block|{
name|_DRM_VBLANK_ABSOLUTE
init|=
literal|0x0
block|,
comment|/**< Wait for specific vblank sequence number */
name|_DRM_VBLANK_RELATIVE
init|=
literal|0x1
block|,
comment|/**< Wait for given number of vblanks */
comment|/* bits 1-6 are reserved for high crtcs */
name|_DRM_VBLANK_HIGH_CRTC_MASK
init|=
literal|0x0000003e
block|,
name|_DRM_VBLANK_EVENT
init|=
literal|0x4000000
block|,
comment|/**< Send event instead of blocking */
name|_DRM_VBLANK_FLIP
init|=
literal|0x8000000
block|,
comment|/**< Scheduled buffer swap should flip */
name|_DRM_VBLANK_NEXTONMISS
init|=
literal|0x10000000
block|,
comment|/**< If missed, wait for next vblank */
name|_DRM_VBLANK_SECONDARY
init|=
literal|0x20000000
block|,
comment|/**< Secondary display controller */
name|_DRM_VBLANK_SIGNAL
init|=
literal|0x40000000
comment|/**< Send signal instead of blocking, unsupported */
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|_DRM_VBLANK_HIGH_CRTC_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|_DRM_VBLANK_TYPES_MASK
value|(_DRM_VBLANK_ABSOLUTE | _DRM_VBLANK_RELATIVE)
end_define

begin_define
define|#
directive|define
name|_DRM_VBLANK_FLAGS_MASK
value|(_DRM_VBLANK_EVENT | _DRM_VBLANK_SIGNAL | \ 				_DRM_VBLANK_SECONDARY | _DRM_VBLANK_NEXTONMISS)
end_define

begin_struct
struct|struct
name|drm_wait_vblank_request
block|{
name|enum
name|drm_vblank_seq_type
name|type
decl_stmt|;
name|unsigned
name|int
name|sequence
decl_stmt|;
name|unsigned
name|long
name|signal
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_wait_vblank_reply
block|{
name|enum
name|drm_vblank_seq_type
name|type
decl_stmt|;
name|unsigned
name|int
name|sequence
decl_stmt|;
name|long
name|tval_sec
decl_stmt|;
name|long
name|tval_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_WAIT_VBLANK ioctl argument type.  *  * \sa drmWaitVBlank().  */
end_comment

begin_union
union|union
name|drm_wait_vblank
block|{
name|struct
name|drm_wait_vblank_request
name|request
decl_stmt|;
name|struct
name|drm_wait_vblank_reply
name|reply
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|_DRM_PRE_MODESET
value|1
end_define

begin_define
define|#
directive|define
name|_DRM_POST_MODESET
value|2
end_define

begin_comment
comment|/**  * DRM_IOCTL_MODESET_CTL ioctl argument type  *  * \sa drmModesetCtl().  */
end_comment

begin_struct
struct|struct
name|drm_modeset_ctl
block|{
name|__u32
name|crtc
decl_stmt|;
name|__u32
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_AGP_ENABLE ioctl argument type.  *  * \sa drmAgpEnable().  */
end_comment

begin_struct
struct|struct
name|drm_agp_mode
block|{
name|unsigned
name|long
name|mode
decl_stmt|;
comment|/**< AGP mode */
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_AGP_ALLOC and DRM_IOCTL_AGP_FREE ioctls argument type.  *  * \sa drmAgpAlloc() and drmAgpFree().  */
end_comment

begin_struct
struct|struct
name|drm_agp_buffer
block|{
name|unsigned
name|long
name|size
decl_stmt|;
comment|/**< In bytes -- will round to page boundary */
name|unsigned
name|long
name|handle
decl_stmt|;
comment|/**< Used for binding / unbinding */
name|unsigned
name|long
name|type
decl_stmt|;
comment|/**< Type of memory to allocate */
name|unsigned
name|long
name|physical
decl_stmt|;
comment|/**< Physical used by i810 */
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_AGP_BIND and DRM_IOCTL_AGP_UNBIND ioctls argument type.  *  * \sa drmAgpBind() and drmAgpUnbind().  */
end_comment

begin_struct
struct|struct
name|drm_agp_binding
block|{
name|unsigned
name|long
name|handle
decl_stmt|;
comment|/**< From drm_agp_buffer */
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/**< In bytes -- will round to page boundary */
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_AGP_INFO ioctl argument type.  *  * \sa drmAgpVersionMajor(), drmAgpVersionMinor(), drmAgpGetMode(),  * drmAgpBase(), drmAgpSize(), drmAgpMemoryUsed(), drmAgpMemoryAvail(),  * drmAgpVendorId() and drmAgpDeviceId().  */
end_comment

begin_struct
struct|struct
name|drm_agp_info
block|{
name|int
name|agp_version_major
decl_stmt|;
name|int
name|agp_version_minor
decl_stmt|;
name|unsigned
name|long
name|mode
decl_stmt|;
name|unsigned
name|long
name|aperture_base
decl_stmt|;
comment|/* physical address */
name|unsigned
name|long
name|aperture_size
decl_stmt|;
comment|/* bytes */
name|unsigned
name|long
name|memory_allowed
decl_stmt|;
comment|/* bytes */
name|unsigned
name|long
name|memory_used
decl_stmt|;
comment|/* PCI information */
name|unsigned
name|short
name|id_vendor
decl_stmt|;
name|unsigned
name|short
name|id_device
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_SG_ALLOC ioctl argument type.  */
end_comment

begin_struct
struct|struct
name|drm_scatter_gather
block|{
name|unsigned
name|long
name|size
decl_stmt|;
comment|/**< In bytes -- will round to page boundary */
name|unsigned
name|long
name|handle
decl_stmt|;
comment|/**< Used for mapping / unmapping */
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM_IOCTL_SET_VERSION ioctl argument type.  */
end_comment

begin_struct
struct|struct
name|drm_set_version
block|{
name|int
name|drm_di_major
decl_stmt|;
name|int
name|drm_di_minor
decl_stmt|;
name|int
name|drm_dd_major
decl_stmt|;
name|int
name|drm_dd_minor
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** DRM_IOCTL_GEM_CLOSE ioctl argument type */
end_comment

begin_struct
struct|struct
name|drm_gem_close
block|{
comment|/** Handle of the object to be closed. */
name|__u32
name|handle
decl_stmt|;
name|__u32
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** DRM_IOCTL_GEM_FLINK ioctl argument type */
end_comment

begin_struct
struct|struct
name|drm_gem_flink
block|{
comment|/** Handle for the object being named */
name|__u32
name|handle
decl_stmt|;
comment|/** Returned global name */
name|__u32
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** DRM_IOCTL_GEM_OPEN ioctl argument type */
end_comment

begin_struct
struct|struct
name|drm_gem_open
block|{
comment|/** Name of object being opened */
name|__u32
name|name
decl_stmt|;
comment|/** Returned handle for the object */
name|__u32
name|handle
decl_stmt|;
comment|/** Returned size of the object */
name|__u64
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** DRM_IOCTL_GET_CAP ioctl argument type */
end_comment

begin_struct
struct|struct
name|drm_get_cap
block|{
name|__u64
name|capability
decl_stmt|;
name|__u64
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_CLOEXEC
value|O_CLOEXEC
end_define

begin_struct
struct|struct
name|drm_prime_handle
block|{
name|__u32
name|handle
decl_stmt|;
comment|/** Flags.. only applicable for handle->fd */
name|__u32
name|flags
decl_stmt|;
comment|/** Returned dmabuf file descriptor */
name|__s32
name|fd
decl_stmt|;
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<dev/drm2/drm_mode.h>
end_include

begin_define
define|#
directive|define
name|DRM_IOCTL_BASE
value|'d'
end_define

begin_define
define|#
directive|define
name|DRM_IO
parameter_list|(
name|nr
parameter_list|)
value|_IO(DRM_IOCTL_BASE,nr)
end_define

begin_define
define|#
directive|define
name|DRM_IOR
parameter_list|(
name|nr
parameter_list|,
name|type
parameter_list|)
value|_IOR(DRM_IOCTL_BASE,nr,type)
end_define

begin_define
define|#
directive|define
name|DRM_IOW
parameter_list|(
name|nr
parameter_list|,
name|type
parameter_list|)
value|_IOW(DRM_IOCTL_BASE,nr,type)
end_define

begin_define
define|#
directive|define
name|DRM_IOWR
parameter_list|(
name|nr
parameter_list|,
name|type
parameter_list|)
value|_IOWR(DRM_IOCTL_BASE,nr,type)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_VERSION
value|DRM_IOWR(0x00, struct drm_version)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_GET_UNIQUE
value|DRM_IOWR(0x01, struct drm_unique)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_GET_MAGIC
value|DRM_IOR( 0x02, struct drm_auth)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_IRQ_BUSID
value|DRM_IOWR(0x03, struct drm_irq_busid)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_GET_MAP
value|DRM_IOWR(0x04, struct drm_map)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_GET_CLIENT
value|DRM_IOWR(0x05, struct drm_client)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_GET_STATS
value|DRM_IOR( 0x06, struct drm_stats)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SET_VERSION
value|DRM_IOWR(0x07, struct drm_set_version)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODESET_CTL
value|DRM_IOW(0x08, struct drm_modeset_ctl)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_GEM_CLOSE
value|DRM_IOW (0x09, struct drm_gem_close)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_GEM_FLINK
value|DRM_IOWR(0x0a, struct drm_gem_flink)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_GEM_OPEN
value|DRM_IOWR(0x0b, struct drm_gem_open)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_GET_CAP
value|DRM_IOWR(0x0c, struct drm_get_cap)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SET_UNIQUE
value|DRM_IOW( 0x10, struct drm_unique)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_AUTH_MAGIC
value|DRM_IOW( 0x11, struct drm_auth)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_BLOCK
value|DRM_IOWR(0x12, struct drm_block)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_UNBLOCK
value|DRM_IOWR(0x13, struct drm_block)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_CONTROL
value|DRM_IOW( 0x14, struct drm_control)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_ADD_MAP
value|DRM_IOWR(0x15, struct drm_map)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_ADD_BUFS
value|DRM_IOWR(0x16, struct drm_buf_desc)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MARK_BUFS
value|DRM_IOW( 0x17, struct drm_buf_desc)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_INFO_BUFS
value|DRM_IOWR(0x18, struct drm_buf_info)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MAP_BUFS
value|DRM_IOWR(0x19, struct drm_buf_map)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_FREE_BUFS
value|DRM_IOW( 0x1a, struct drm_buf_free)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RM_MAP
value|DRM_IOW( 0x1b, struct drm_map)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SET_SAREA_CTX
value|DRM_IOW( 0x1c, struct drm_ctx_priv_map)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_GET_SAREA_CTX
value|DRM_IOWR(0x1d, struct drm_ctx_priv_map)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SET_MASTER
value|DRM_IO(0x1e)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_DROP_MASTER
value|DRM_IO(0x1f)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_ADD_CTX
value|DRM_IOWR(0x20, struct drm_ctx)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RM_CTX
value|DRM_IOWR(0x21, struct drm_ctx)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MOD_CTX
value|DRM_IOW( 0x22, struct drm_ctx)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_GET_CTX
value|DRM_IOWR(0x23, struct drm_ctx)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SWITCH_CTX
value|DRM_IOW( 0x24, struct drm_ctx)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_NEW_CTX
value|DRM_IOW( 0x25, struct drm_ctx)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RES_CTX
value|DRM_IOWR(0x26, struct drm_ctx_res)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_ADD_DRAW
value|DRM_IOWR(0x27, struct drm_draw)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_RM_DRAW
value|DRM_IOWR(0x28, struct drm_draw)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_DMA
value|DRM_IOWR(0x29, struct drm_dma)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_LOCK
value|DRM_IOW( 0x2a, struct drm_lock)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_UNLOCK
value|DRM_IOW( 0x2b, struct drm_lock)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_FINISH
value|DRM_IOW( 0x2c, struct drm_lock)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_PRIME_HANDLE_TO_FD
value|DRM_IOWR(0x2d, struct drm_prime_handle)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_PRIME_FD_TO_HANDLE
value|DRM_IOWR(0x2e, struct drm_prime_handle)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_AGP_ACQUIRE
value|DRM_IO(  0x30)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_AGP_RELEASE
value|DRM_IO(  0x31)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_AGP_ENABLE
value|DRM_IOW( 0x32, struct drm_agp_mode)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_AGP_INFO
value|DRM_IOR( 0x33, struct drm_agp_info)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_AGP_ALLOC
value|DRM_IOWR(0x34, struct drm_agp_buffer)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_AGP_FREE
value|DRM_IOW( 0x35, struct drm_agp_buffer)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_AGP_BIND
value|DRM_IOW( 0x36, struct drm_agp_binding)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_AGP_UNBIND
value|DRM_IOW( 0x37, struct drm_agp_binding)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SG_ALLOC
value|DRM_IOWR(0x38, struct drm_scatter_gather)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_SG_FREE
value|DRM_IOW( 0x39, struct drm_scatter_gather)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_WAIT_VBLANK
value|DRM_IOWR(0x3a, union drm_wait_vblank)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_UPDATE_DRAW
value|DRM_IOW(0x3f, struct drm_update_draw)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_GETRESOURCES
value|DRM_IOWR(0xA0, struct drm_mode_card_res)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_GETCRTC
value|DRM_IOWR(0xA1, struct drm_mode_crtc)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_SETCRTC
value|DRM_IOWR(0xA2, struct drm_mode_crtc)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_CURSOR
value|DRM_IOWR(0xA3, struct drm_mode_cursor)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_GETGAMMA
value|DRM_IOWR(0xA4, struct drm_mode_crtc_lut)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_SETGAMMA
value|DRM_IOWR(0xA5, struct drm_mode_crtc_lut)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_GETENCODER
value|DRM_IOWR(0xA6, struct drm_mode_get_encoder)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_GETCONNECTOR
value|DRM_IOWR(0xA7, struct drm_mode_get_connector)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_ATTACHMODE
value|DRM_IOWR(0xA8, struct drm_mode_mode_cmd)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_DETACHMODE
value|DRM_IOWR(0xA9, struct drm_mode_mode_cmd)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_GETPROPERTY
value|DRM_IOWR(0xAA, struct drm_mode_get_property)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_SETPROPERTY
value|DRM_IOWR(0xAB, struct drm_mode_connector_set_property)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_GETPROPBLOB
value|DRM_IOWR(0xAC, struct drm_mode_get_blob)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_GETFB
value|DRM_IOWR(0xAD, struct drm_mode_fb_cmd)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_ADDFB
value|DRM_IOWR(0xAE, struct drm_mode_fb_cmd)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_RMFB
value|DRM_IOWR(0xAF, unsigned int)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_PAGE_FLIP
value|DRM_IOWR(0xB0, struct drm_mode_crtc_page_flip)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_DIRTYFB
value|DRM_IOWR(0xB1, struct drm_mode_fb_dirty_cmd)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_CREATE_DUMB
value|DRM_IOWR(0xB2, struct drm_mode_create_dumb)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_MAP_DUMB
value|DRM_IOWR(0xB3, struct drm_mode_map_dumb)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_DESTROY_DUMB
value|DRM_IOWR(0xB4, struct drm_mode_destroy_dumb)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_GETPLANERESOURCES
value|DRM_IOWR(0xB5, struct drm_mode_get_plane_res)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_GETPLANE
value|DRM_IOWR(0xB6, struct drm_mode_get_plane)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_SETPLANE
value|DRM_IOWR(0xB7, struct drm_mode_set_plane)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_ADDFB2
value|DRM_IOWR(0xB8, struct drm_mode_fb_cmd2)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_OBJ_GETPROPERTIES
value|DRM_IOWR(0xB9, struct drm_mode_obj_get_properties)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MODE_OBJ_SETPROPERTY
value|DRM_IOWR(0xBA, struct drm_mode_obj_set_property)
end_define

begin_comment
comment|/**  * Device specific ioctls should only be in their respective headers  * The device specific ioctl range is from 0x40 to 0x99.  * Generic IOCTLS restart at 0xA0.  *  * \sa drmCommandNone(), drmCommandRead(), drmCommandWrite(), and  * drmCommandReadWrite().  */
end_comment

begin_define
define|#
directive|define
name|DRM_COMMAND_BASE
value|0x40
end_define

begin_define
define|#
directive|define
name|DRM_COMMAND_END
value|0xA0
end_define

begin_comment
comment|/**  * Header for events written back to userspace on the drm fd.  The  * type defines the type of event, the length specifies the total  * length of the event (including the header), and user_data is  * typically a 64 bit value passed with the ioctl that triggered the  * event.  A read on the drm fd will always only return complete  * events, that is, if for example the read buffer is 100 bytes, and  * there are two 64 byte events pending, only one will be returned.  *  * Event types 0 - 0x7fffffff are generic drm events, 0x80000000 and  * up are chipset specific.  */
end_comment

begin_struct
struct|struct
name|drm_event
block|{
name|__u32
name|type
decl_stmt|;
name|__u32
name|length
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_EVENT_VBLANK
value|0x01
end_define

begin_define
define|#
directive|define
name|DRM_EVENT_FLIP_COMPLETE
value|0x02
end_define

begin_struct
struct|struct
name|drm_event_vblank
block|{
name|struct
name|drm_event
name|base
decl_stmt|;
name|__u64
name|user_data
decl_stmt|;
name|__u32
name|tv_sec
decl_stmt|;
name|__u32
name|tv_usec
decl_stmt|;
name|__u32
name|sequence
decl_stmt|;
name|__u32
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_CAP_DUMB_BUFFER
value|0x1
end_define

begin_define
define|#
directive|define
name|DRM_CAP_VBLANK_HIGH_CRTC
value|0x2
end_define

begin_define
define|#
directive|define
name|DRM_CAP_DUMB_PREFERRED_DEPTH
value|0x3
end_define

begin_define
define|#
directive|define
name|DRM_CAP_DUMB_PREFER_SHADOW
value|0x4
end_define

begin_define
define|#
directive|define
name|DRM_CAP_PRIME
value|0x5
end_define

begin_define
define|#
directive|define
name|DRM_CAP_TIMESTAMP_MONOTONIC
value|0x6
end_define

begin_define
define|#
directive|define
name|DRM_PRIME_CAP_IMPORT
value|0x1
end_define

begin_define
define|#
directive|define
name|DRM_PRIME_CAP_EXPORT
value|0x2
end_define

begin_comment
comment|/* typedef area */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KERNEL__
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|drm_clip_rect
name|drm_clip_rect_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_drawable_info
name|drm_drawable_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_tex_region
name|drm_tex_region_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_hw_lock
name|drm_hw_lock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_version
name|drm_version_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_unique
name|drm_unique_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_list
name|drm_list_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_block
name|drm_block_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_control
name|drm_control_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|drm_map_type
name|drm_map_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|drm_map_flags
name|drm_map_flags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_ctx_priv_map
name|drm_ctx_priv_map_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_map
name|drm_map_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_client
name|drm_client_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|drm_stat_type
name|drm_stat_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_stats
name|drm_stats_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|drm_lock_flags
name|drm_lock_flags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_lock
name|drm_lock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|drm_dma_flags
name|drm_dma_flags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_buf_desc
name|drm_buf_desc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_buf_info
name|drm_buf_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_buf_free
name|drm_buf_free_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_buf_pub
name|drm_buf_pub_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_buf_map
name|drm_buf_map_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_dma
name|drm_dma_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|drm_wait_vblank
name|drm_wait_vblank_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_agp_mode
name|drm_agp_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|drm_ctx_flags
name|drm_ctx_flags_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_ctx
name|drm_ctx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_ctx_res
name|drm_ctx_res_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_draw
name|drm_draw_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_update_draw
name|drm_update_draw_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_auth
name|drm_auth_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_irq_busid
name|drm_irq_busid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|drm_vblank_seq_type
name|drm_vblank_seq_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_agp_buffer
name|drm_agp_buffer_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_agp_binding
name|drm_agp_binding_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_agp_info
name|drm_agp_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_scatter_gather
name|drm_scatter_gather_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_set_version
name|drm_set_version_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

