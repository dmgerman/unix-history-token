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

begin_comment
comment|/**  * \mainpage  *  * The Direct Rendering Manager (DRM) is a device-independent kernel-level  * device driver that provides support for the XFree86 Direct Rendering  * Infrastructure (DRI).  *  * The DRM supports the Direct Rendering Infrastructure (DRI) in four major  * ways:  *     -# The DRM provides synchronized access to the graphics hardware via  *        the use of an optimized two-tiered lock.  *     -# The DRM enforces the DRI security policy for access to the graphics  *        hardware by only allowing authenticated X11 clients access to  *        restricted regions of memory.  *     -# The DRM provides a generic DMA engine, complete with multiple  *        queues and the ability to detect the need for an OpenGL context  *        switch.  *     -# The DRM is extensible via the use of small device-specific modules  *        that rely extensively on the API exported by the DRM module.  *  */
end_comment

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

begin_ifndef
ifndef|#
directive|ifndef
name|__user
end_ifndef

begin_define
define|#
directive|define
name|__user
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__iomem
end_ifndef

begin_define
define|#
directive|define
name|__iomem
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|DEPRECATED
value|__attribute__ ((deprecated))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEPRECATED
end_define

begin_endif
endif|#
directive|endif
end_endif

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
file|<asm/ioctl.h>
end_include

begin_comment
comment|/* For _IO* macros */
end_comment

begin_define
define|#
directive|define
name|DRM_IOCTL_NR
parameter_list|(
name|n
parameter_list|)
value|_IOC_NR(n)
end_define

begin_define
define|#
directive|define
name|DRM_IOC_VOID
value|_IOC_NONE
end_define

begin_define
define|#
directive|define
name|DRM_IOC_READ
value|_IOC_READ
end_define

begin_define
define|#
directive|define
name|DRM_IOC_WRITE
value|_IOC_WRITE
end_define

begin_define
define|#
directive|define
name|DRM_IOC_READWRITE
value|_IOC_READ|_IOC_WRITE
end_define

begin_define
define|#
directive|define
name|DRM_IOC
parameter_list|(
name|dir
parameter_list|,
name|group
parameter_list|,
name|nr
parameter_list|,
name|size
parameter_list|)
value|_IOC(dir, group, nr, size)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD_kernel__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__DragonFly__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|DRM_IOCTL_NR
parameter_list|(
name|n
parameter_list|)
value|((n)& 0xff)
end_define

begin_define
define|#
directive|define
name|DRM_IOC_VOID
value|IOC_VOID
end_define

begin_define
define|#
directive|define
name|DRM_IOC_READ
value|IOC_OUT
end_define

begin_define
define|#
directive|define
name|DRM_IOC_WRITE
value|IOC_IN
end_define

begin_define
define|#
directive|define
name|DRM_IOC_READWRITE
value|IOC_INOUT
end_define

begin_define
define|#
directive|define
name|DRM_IOC
parameter_list|(
name|dir
parameter_list|,
name|group
parameter_list|,
name|nr
parameter_list|,
name|size
parameter_list|)
value|_IOC(dir, group, nr, size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_define
define|#
directive|define
name|DRM_MAJOR
value|81
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
operator|||
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DRM_MAJOR
value|226
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DRM_MAX_MINOR
value|15
end_define

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__linux__
argument_list|)
end_if

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

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_typedef
typedef|typedef
name|unsigned
name|long
name|drm_handle_t
typedef|;
end_typedef

begin_comment
comment|/**< To mapped regions */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|int
name|drm_context_t
typedef|;
end_typedef

begin_comment
comment|/**< GLXContext handle */
end_comment

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
comment|/**< Magic for authentication */
end_comment

begin_comment
comment|/**  * Cliprect.  *  * \warning If you change this structure, make sure you change  * XF86DRIClipRectRec in the server as well  *  * \note KW: Actually it's illegal to change either for  * backwards-compatibility reasons.  */
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
comment|/* This is beyond ugly, and only works on GCC.  However, it allows me to use  * drm.h in places (i.e., in the X-server) where I can't use size_t.  The real  * fix is to use uint32_t instead of size_t, but that fix will break existing  * LP64 (i.e., PowerPC64, SPARC64, Alpha, etc.) systems.  That *will*  * eventually happen, though.  I chose 'unsigned long' to be the fallback type  * because that works on all the platforms I know about.  Hopefully, the  * real fix will happen before that bites us.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__SIZE_TYPE__
end_ifdef

begin_define
define|#
directive|define
name|DRM_SIZE_T
value|__SIZE_TYPE__
end_define

begin_else
else|#
directive|else
end_else

begin_warning
warning|#
directive|warning
literal|"__SIZE_TYPE__ not defined.  Assuming sizeof(size_t) == sizeof(unsigned long)!"
end_warning

begin_define
define|#
directive|define
name|DRM_SIZE_T
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|DRM_SIZE_T
name|name_len
decl_stmt|;
comment|/**< Length of name buffer */
name|char
name|__user
modifier|*
name|name
decl_stmt|;
comment|/**< Name of driver */
name|DRM_SIZE_T
name|date_len
decl_stmt|;
comment|/**< Length of date buffer */
name|char
name|__user
modifier|*
name|date
decl_stmt|;
comment|/**< User-space buffer to hold date */
name|DRM_SIZE_T
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
name|DRM_SIZE_T
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

begin_undef
undef|#
directive|undef
name|DRM_SIZE_T
end_undef

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
name|_DRM_TTM
init|=
literal|6
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
comment|/**< Number of buffers described in list */
name|struct
name|drm_buf_desc
name|__user
modifier|*
name|list
decl_stmt|;
comment|/**< List of buffer descriptions */
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
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
name|void
name|__user
modifier|*
name|c_virtual
decl_stmt|;
else|#
directive|else
name|void
name|__user
modifier|*
name|virtual
decl_stmt|;
comment|/**< Mmap'd area in user-virtual */
endif|#
directive|endif
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
comment|/**< Send signal instead of blocking */
block|}
enum|;
end_enum

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
value|(_DRM_VBLANK_SIGNAL | _DRM_VBLANK_SECONDARY | \ 				_DRM_VBLANK_NEXTONMISS)
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
name|uint32_t
name|crtc
decl_stmt|;
name|uint32_t
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
comment|/**< physical address */
name|unsigned
name|long
name|aperture_size
decl_stmt|;
comment|/**< bytes */
name|unsigned
name|long
name|memory_allowed
decl_stmt|;
comment|/**< bytes */
name|unsigned
name|long
name|memory_used
decl_stmt|;
comment|/** \name PCI information */
comment|/*@{ */
name|unsigned
name|short
name|id_vendor
decl_stmt|;
name|unsigned
name|short
name|id_device
decl_stmt|;
comment|/*@} */
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

begin_define
define|#
directive|define
name|DRM_FENCE_FLAG_EMIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DRM_FENCE_FLAG_SHAREABLE
value|0x00000002
end_define

begin_comment
comment|/**  * On hardware with no interrupt events for operation completion,  * indicates that the kernel should sleep while waiting for any blocking  * operation to complete rather than spinning.  *  * Has no effect otherwise.  */
end_comment

begin_define
define|#
directive|define
name|DRM_FENCE_FLAG_WAIT_LAZY
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DRM_FENCE_FLAG_NO_USER
value|0x00000010
end_define

begin_comment
comment|/* Reserved for driver use */
end_comment

begin_define
define|#
directive|define
name|DRM_FENCE_MASK_DRIVER
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|DRM_FENCE_TYPE_EXE
value|0x00000001
end_define

begin_struct
struct|struct
name|drm_fence_arg
block|{
name|unsigned
name|int
name|handle
decl_stmt|;
name|unsigned
name|int
name|fence_class
decl_stmt|;
name|unsigned
name|int
name|type
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
name|unsigned
name|int
name|signaled
decl_stmt|;
name|unsigned
name|int
name|error
decl_stmt|;
name|unsigned
name|int
name|sequence
decl_stmt|;
name|unsigned
name|int
name|pad64
decl_stmt|;
name|uint64_t
name|expand_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/*Future expansion */
block|}
struct|;
end_struct

begin_comment
comment|/* Buffer permissions, referring to how the GPU uses the buffers.  * these translate to fence types used for the buffers.  * Typically a texture buffer is read, A destination buffer is write and  *  a command (batch-) buffer is exe. Can be or-ed together.  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_READ
value|(1ULL<< 0)
end_define

begin_define
define|#
directive|define
name|DRM_BO_FLAG_WRITE
value|(1ULL<< 1)
end_define

begin_define
define|#
directive|define
name|DRM_BO_FLAG_EXE
value|(1ULL<< 2)
end_define

begin_comment
comment|/*  * All of the bits related to access mode  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_MASK_ACCESS
value|(DRM_BO_FLAG_READ | DRM_BO_FLAG_WRITE | DRM_BO_FLAG_EXE)
end_define

begin_comment
comment|/*  * Status flags. Can be read to determine the actual state of a buffer.  * Can also be set in the buffer mask before validation.  */
end_comment

begin_comment
comment|/*  * Mask: Never evict this buffer. Not even with force. This type of buffer is only  * available to root and must be manually removed before buffer manager shutdown  * or lock.  * Flags: Acknowledge  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_NO_EVICT
value|(1ULL<< 4)
end_define

begin_comment
comment|/*  * Mask: Require that the buffer is placed in mappable memory when validated.  *       If not set the buffer may or may not be in mappable memory when validated.  * Flags: If set, the buffer is in mappable memory.  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_MAPPABLE
value|(1ULL<< 5)
end_define

begin_comment
comment|/* Mask: The buffer should be shareable with other processes.  * Flags: The buffer is shareable with other processes.  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_SHAREABLE
value|(1ULL<< 6)
end_define

begin_comment
comment|/* Mask: If set, place the buffer in cache-coherent memory if available.  *       If clear, never place the buffer in cache coherent memory if validated.  * Flags: The buffer is currently in cache-coherent memory.  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_CACHED
value|(1ULL<< 7)
end_define

begin_comment
comment|/* Mask: Make sure that every time this buffer is validated,  *       it ends up on the same location provided that the memory mask is the same.  *       The buffer will also not be evicted when claiming space for  *       other buffers. Basically a pinned buffer but it may be thrown out as  *       part of buffer manager shutdown or locking.  * Flags: Acknowledge.  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_NO_MOVE
value|(1ULL<< 8)
end_define

begin_comment
comment|/* Mask: Make sure the buffer is in cached memory when mapped.  In conjunction  * with DRM_BO_FLAG_CACHED it also allows the buffer to be bound into the GART  * with unsnooped PTEs instead of snooped, by using chipset-specific cache  * flushing at bind time.  A better name might be DRM_BO_FLAG_TT_UNSNOOPED,  * as the eviction to local memory (TTM unbind) on map is just a side effect  * to prevent aggressive cache prefetch from the GPU disturbing the cache  * management that the DRM is doing.  *  * Flags: Acknowledge.  * Buffers allocated with this flag should not be used for suballocators  * This type may have issues on CPUs with over-aggressive caching  * http://marc.info/?l=linux-kernel&m=102376926732464&w=2  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_CACHED_MAPPED
value|(1ULL<< 19)
end_define

begin_comment
comment|/* Mask: Force DRM_BO_FLAG_CACHED flag strictly also if it is set.  * Flags: Acknowledge.  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_FORCE_CACHING
value|(1ULL<< 13)
end_define

begin_comment
comment|/*  * Mask: Force DRM_BO_FLAG_MAPPABLE flag strictly also if it is clear.  * Flags: Acknowledge.  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_FORCE_MAPPABLE
value|(1ULL<< 14)
end_define

begin_define
define|#
directive|define
name|DRM_BO_FLAG_TILE
value|(1ULL<< 15)
end_define

begin_comment
comment|/*  * Memory type flags that can be or'ed together in the mask, but only  * one appears in flags.  */
end_comment

begin_comment
comment|/* System memory */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_MEM_LOCAL
value|(1ULL<< 24)
end_define

begin_comment
comment|/* Translation table memory */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_MEM_TT
value|(1ULL<< 25)
end_define

begin_comment
comment|/* Vram memory */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_MEM_VRAM
value|(1ULL<< 26)
end_define

begin_comment
comment|/* Up to the driver to define. */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_FLAG_MEM_PRIV0
value|(1ULL<< 27)
end_define

begin_define
define|#
directive|define
name|DRM_BO_FLAG_MEM_PRIV1
value|(1ULL<< 28)
end_define

begin_define
define|#
directive|define
name|DRM_BO_FLAG_MEM_PRIV2
value|(1ULL<< 29)
end_define

begin_define
define|#
directive|define
name|DRM_BO_FLAG_MEM_PRIV3
value|(1ULL<< 30)
end_define

begin_define
define|#
directive|define
name|DRM_BO_FLAG_MEM_PRIV4
value|(1ULL<< 31)
end_define

begin_comment
comment|/* We can add more of these now with a 64-bit flag type */
end_comment

begin_comment
comment|/*  * This is a mask covering all of the memory type flags; easier to just  * use a single constant than a bunch of | values. It covers  * DRM_BO_FLAG_MEM_LOCAL through DRM_BO_FLAG_MEM_PRIV4  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_MASK_MEM
value|0x00000000FF000000ULL
end_define

begin_comment
comment|/*  * This adds all of the CPU-mapping options in with the memory  * type to label all bits which change how the page gets mapped  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_MASK_MEMTYPE
value|(DRM_BO_MASK_MEM | \ 				 DRM_BO_FLAG_CACHED_MAPPED | \ 				 DRM_BO_FLAG_CACHED | \ 				 DRM_BO_FLAG_MAPPABLE)
end_define

begin_comment
comment|/* Driver-private flags */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_MASK_DRIVER
value|0xFFFF000000000000ULL
end_define

begin_comment
comment|/*  * Don't block on validate and map. Instead, return EBUSY.  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_HINT_DONT_BLOCK
value|0x00000002
end_define

begin_comment
comment|/*  * Don't place this buffer on the unfenced list. This means  * that the buffer will not end up having a fence associated  * with it as a result of this operation  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_HINT_DONT_FENCE
value|0x00000004
end_define

begin_comment
comment|/**  * On hardware with no interrupt events for operation completion,  * indicates that the kernel should sleep while waiting for any blocking  * operation to complete rather than spinning.  *  * Has no effect otherwise.  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_HINT_WAIT_LAZY
value|0x00000008
end_define

begin_comment
comment|/*  * The client has compute relocations refering to this buffer using the  * offset in the presumed_offset field. If that offset ends up matching  * where this buffer lands, the kernel is free to skip executing those  * relocations  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_HINT_PRESUMED_OFFSET
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DRM_BO_INIT_MAGIC
value|0xfe769812
end_define

begin_define
define|#
directive|define
name|DRM_BO_INIT_MAJOR
value|1
end_define

begin_define
define|#
directive|define
name|DRM_BO_INIT_MINOR
value|0
end_define

begin_define
define|#
directive|define
name|DRM_BO_INIT_PATCH
value|0
end_define

begin_struct
struct|struct
name|drm_bo_info_req
block|{
name|uint64_t
name|mask
decl_stmt|;
name|uint64_t
name|flags
decl_stmt|;
name|unsigned
name|int
name|handle
decl_stmt|;
name|unsigned
name|int
name|hint
decl_stmt|;
name|unsigned
name|int
name|fence_class
decl_stmt|;
name|unsigned
name|int
name|desired_tile_stride
decl_stmt|;
name|unsigned
name|int
name|tile_info
decl_stmt|;
name|unsigned
name|int
name|pad64
decl_stmt|;
name|uint64_t
name|presumed_offset
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_bo_create_req
block|{
name|uint64_t
name|flags
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
name|uint64_t
name|buffer_start
decl_stmt|;
name|unsigned
name|int
name|hint
decl_stmt|;
name|unsigned
name|int
name|page_alignment
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Reply flags  */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_REP_BUSY
value|0x00000001
end_define

begin_struct
struct|struct
name|drm_bo_info_rep
block|{
name|uint64_t
name|flags
decl_stmt|;
name|uint64_t
name|proposed_flags
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
name|uint64_t
name|offset
decl_stmt|;
name|uint64_t
name|arg_handle
decl_stmt|;
name|uint64_t
name|buffer_start
decl_stmt|;
name|unsigned
name|int
name|handle
decl_stmt|;
name|unsigned
name|int
name|fence_flags
decl_stmt|;
name|unsigned
name|int
name|rep_flags
decl_stmt|;
name|unsigned
name|int
name|page_alignment
decl_stmt|;
name|unsigned
name|int
name|desired_tile_stride
decl_stmt|;
name|unsigned
name|int
name|hw_tile_stride
decl_stmt|;
name|unsigned
name|int
name|tile_info
decl_stmt|;
name|unsigned
name|int
name|pad64
decl_stmt|;
name|uint64_t
name|expand_pad
index|[
literal|4
index|]
decl_stmt|;
comment|/*Future expansion */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_bo_arg_rep
block|{
name|struct
name|drm_bo_info_rep
name|bo_info
decl_stmt|;
name|int
name|ret
decl_stmt|;
name|unsigned
name|int
name|pad64
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_bo_create_arg
block|{
union|union
block|{
name|struct
name|drm_bo_create_req
name|req
decl_stmt|;
name|struct
name|drm_bo_info_rep
name|rep
decl_stmt|;
block|}
name|d
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_bo_handle_arg
block|{
name|unsigned
name|int
name|handle
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_bo_reference_info_arg
block|{
union|union
block|{
name|struct
name|drm_bo_handle_arg
name|req
decl_stmt|;
name|struct
name|drm_bo_info_rep
name|rep
decl_stmt|;
block|}
name|d
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_bo_map_wait_idle_arg
block|{
union|union
block|{
name|struct
name|drm_bo_info_req
name|req
decl_stmt|;
name|struct
name|drm_bo_info_rep
name|rep
decl_stmt|;
block|}
name|d
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_bo_op_req
block|{
enum|enum
block|{
name|drm_bo_validate
block|,
name|drm_bo_fence
block|,
name|drm_bo_ref_fence
block|, 	}
name|op
enum|;
name|unsigned
name|int
name|arg_handle
decl_stmt|;
name|struct
name|drm_bo_info_req
name|bo_req
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_bo_op_arg
block|{
name|uint64_t
name|next
decl_stmt|;
union|union
block|{
name|struct
name|drm_bo_op_req
name|req
decl_stmt|;
name|struct
name|drm_bo_arg_rep
name|rep
decl_stmt|;
block|}
name|d
union|;
name|int
name|handled
decl_stmt|;
name|unsigned
name|int
name|pad64
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_BO_MEM_LOCAL
value|0
end_define

begin_define
define|#
directive|define
name|DRM_BO_MEM_TT
value|1
end_define

begin_define
define|#
directive|define
name|DRM_BO_MEM_VRAM
value|2
end_define

begin_define
define|#
directive|define
name|DRM_BO_MEM_PRIV0
value|3
end_define

begin_define
define|#
directive|define
name|DRM_BO_MEM_PRIV1
value|4
end_define

begin_define
define|#
directive|define
name|DRM_BO_MEM_PRIV2
value|5
end_define

begin_define
define|#
directive|define
name|DRM_BO_MEM_PRIV3
value|6
end_define

begin_define
define|#
directive|define
name|DRM_BO_MEM_PRIV4
value|7
end_define

begin_define
define|#
directive|define
name|DRM_BO_MEM_TYPES
value|8
end_define

begin_comment
comment|/* For now. */
end_comment

begin_define
define|#
directive|define
name|DRM_BO_LOCK_UNLOCK_BM
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DRM_BO_LOCK_IGNORE_NO_EVICT
value|(1<< 1)
end_define

begin_struct
struct|struct
name|drm_bo_version_arg
block|{
name|uint32_t
name|major
decl_stmt|;
name|uint32_t
name|minor
decl_stmt|;
name|uint32_t
name|patchlevel
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mm_type_arg
block|{
name|unsigned
name|int
name|mem_type
decl_stmt|;
name|unsigned
name|int
name|lock_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mm_init_arg
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|unsigned
name|int
name|major
decl_stmt|;
name|unsigned
name|int
name|minor
decl_stmt|;
name|unsigned
name|int
name|mem_type
decl_stmt|;
name|uint64_t
name|p_offset
decl_stmt|;
name|uint64_t
name|p_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_mm_info_arg
block|{
name|unsigned
name|int
name|mem_type
decl_stmt|;
name|uint64_t
name|p_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_gem_close
block|{
comment|/** Handle of the object to be closed. */
name|uint32_t
name|handle
decl_stmt|;
name|uint32_t
name|pad
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_gem_flink
block|{
comment|/** Handle for the object being named */
name|uint32_t
name|handle
decl_stmt|;
comment|/** Returned global name */
name|uint32_t
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_gem_open
block|{
comment|/** Name of object being opened */
name|uint32_t
name|name
decl_stmt|;
comment|/** Returned handle for the object */
name|uint32_t
name|handle
decl_stmt|;
comment|/** Returned size of the object */
name|uint64_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * \name Ioctls Definitions  */
end_comment

begin_comment
comment|/*@{*/
end_comment

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
value|DRM_IOW(0x08,  struct drm_modeset_ctl)
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
name|DRM_IOCTL_MM_INIT
value|DRM_IOWR(0xc0, struct drm_mm_init_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MM_TAKEDOWN
value|DRM_IOWR(0xc1, struct drm_mm_type_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MM_LOCK
value|DRM_IOWR(0xc2, struct drm_mm_type_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MM_UNLOCK
value|DRM_IOWR(0xc3, struct drm_mm_type_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_FENCE_CREATE
value|DRM_IOWR(0xc4, struct drm_fence_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_FENCE_REFERENCE
value|DRM_IOWR(0xc6, struct drm_fence_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_FENCE_UNREFERENCE
value|DRM_IOWR(0xc7, struct drm_fence_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_FENCE_SIGNALED
value|DRM_IOWR(0xc8, struct drm_fence_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_FENCE_FLUSH
value|DRM_IOWR(0xc9, struct drm_fence_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_FENCE_WAIT
value|DRM_IOWR(0xca, struct drm_fence_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_FENCE_EMIT
value|DRM_IOWR(0xcb, struct drm_fence_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_FENCE_BUFFERS
value|DRM_IOWR(0xcc, struct drm_fence_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_BO_CREATE
value|DRM_IOWR(0xcd, struct drm_bo_create_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_BO_MAP
value|DRM_IOWR(0xcf, struct drm_bo_map_wait_idle_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_BO_UNMAP
value|DRM_IOWR(0xd0, struct drm_bo_handle_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_BO_REFERENCE
value|DRM_IOWR(0xd1, struct drm_bo_reference_info_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_BO_UNREFERENCE
value|DRM_IOWR(0xd2, struct drm_bo_handle_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_BO_SETSTATUS
value|DRM_IOWR(0xd3, struct drm_bo_map_wait_idle_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_BO_INFO
value|DRM_IOWR(0xd4, struct drm_bo_reference_info_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_BO_WAIT_IDLE
value|DRM_IOWR(0xd5, struct drm_bo_map_wait_idle_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_BO_VERSION
value|DRM_IOR(0xd6, struct drm_bo_version_arg)
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_MM_INFO
value|DRM_IOWR(0xd7, struct drm_mm_info_arg)
end_define

begin_comment
comment|/*@}*/
end_comment

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

begin_typedef
typedef|typedef
name|struct
name|drm_fence_arg
name|drm_fence_arg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_mm_type_arg
name|drm_mm_type_arg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_mm_init_arg
name|drm_mm_init_arg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|enum
name|drm_bo_type
name|drm_bo_type_t
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

