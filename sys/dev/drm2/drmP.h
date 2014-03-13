begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file drmP.h  * Private header for Direct Rendering Manager  *  * \author Rickard E. (Rik) Faith<faith@valinux.com>  * \author Gareth Hughes<gareth@valinux.com>  */
end_comment

begin_comment
comment|/*  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * Copyright (c) 2009-2010, Code Aurora Forum.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  */
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

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/sglist.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<sys/priv.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/filio.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/poll.h>
end_include

begin_include
include|#
directive|include
file|<sys/sbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_include
include|#
directive|include
file|<sys/tree.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_object.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_page.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_pager.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_phys.h>
end_include

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/sysarch.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<sys/memrange.h>
end_include

begin_include
include|#
directive|include
file|<dev/agp/agpvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/agpio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/drm.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/drm_sarea.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/drm_atomic.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/drm_internal.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/drm_linux_list.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/drm_gem_names.h>
end_include

begin_struct_decl
struct_decl|struct
name|drm_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|drm_device
struct_decl|;
end_struct_decl

begin_include
include|#
directive|include
file|<dev/drm2/drm_os_freebsd.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/drm_hashtab.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/drm_mm.h>
end_include

begin_include
include|#
directive|include
file|"opt_compat.h"
end_include

begin_include
include|#
directive|include
file|"opt_drm.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|DRM_DEBUG
end_ifdef

begin_undef
undef|#
directive|undef
name|DRM_DEBUG
end_undef

begin_define
define|#
directive|define
name|DRM_DEBUG_DEFAULT_ON
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DRM_DEBUG */
end_comment

begin_define
define|#
directive|define
name|DRM_DEBUGBITS_DEBUG
value|0x1
end_define

begin_define
define|#
directive|define
name|DRM_DEBUGBITS_KMS
value|0x2
end_define

begin_define
define|#
directive|define
name|DRM_DEBUGBITS_FAILED_IOCTL
value|0x4
end_define

begin_undef
undef|#
directive|undef
name|DRM_LINUX
end_undef

begin_define
define|#
directive|define
name|DRM_LINUX
value|0
end_define

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/** \name DRM template customization defaults */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/* driver capabilities and requirements mask */
end_comment

begin_define
define|#
directive|define
name|DRIVER_USE_AGP
value|0x1
end_define

begin_define
define|#
directive|define
name|DRIVER_REQUIRE_AGP
value|0x2
end_define

begin_define
define|#
directive|define
name|DRIVER_USE_MTRR
value|0x4
end_define

begin_define
define|#
directive|define
name|DRIVER_PCI_DMA
value|0x8
end_define

begin_define
define|#
directive|define
name|DRIVER_SG
value|0x10
end_define

begin_define
define|#
directive|define
name|DRIVER_HAVE_DMA
value|0x20
end_define

begin_define
define|#
directive|define
name|DRIVER_HAVE_IRQ
value|0x40
end_define

begin_define
define|#
directive|define
name|DRIVER_IRQ_SHARED
value|0x80
end_define

begin_define
define|#
directive|define
name|DRIVER_IRQ_VBL
value|0x100
end_define

begin_define
define|#
directive|define
name|DRIVER_DMA_QUEUE
value|0x200
end_define

begin_define
define|#
directive|define
name|DRIVER_FB_DMA
value|0x400
end_define

begin_define
define|#
directive|define
name|DRIVER_IRQ_VBL2
value|0x800
end_define

begin_define
define|#
directive|define
name|DRIVER_GEM
value|0x1000
end_define

begin_define
define|#
directive|define
name|DRIVER_MODESET
value|0x2000
end_define

begin_define
define|#
directive|define
name|DRIVER_PRIME
value|0x4000
end_define

begin_define
define|#
directive|define
name|DRIVER_LOCKLESS_IRQ
value|0x8000
end_define

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
name|DRM_GEM_MAPPING_MASK
value|(3ULL<< 62)
end_define

begin_define
define|#
directive|define
name|DRM_GEM_MAPPING_KEY
value|(2ULL<< 62)
end_define

begin_comment
comment|/* Non-canonical address form */
end_comment

begin_define
define|#
directive|define
name|DRM_GEM_MAX_IDX
value|0x3fffff
end_define

begin_define
define|#
directive|define
name|DRM_GEM_MAPPING_IDX
parameter_list|(
name|o
parameter_list|)
value|(((o)>> 40)& DRM_GEM_MAX_IDX)
end_define

begin_define
define|#
directive|define
name|DRM_GEM_MAPPING_OFF
parameter_list|(
name|i
parameter_list|)
value|(((uint64_t)(i))<< 40)
end_define

begin_define
define|#
directive|define
name|DRM_GEM_MAPPING_MAPOFF
parameter_list|(
name|o
parameter_list|)
define|\
value|((o)& ~(DRM_GEM_MAPPING_OFF(DRM_GEM_MAX_IDX) | DRM_GEM_MAPPING_KEY))
end_define

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_DMA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_SAREA
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_DRIVER
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_MAGIC
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_IOCTLS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_MAPS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_BUFS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_SEGS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_PAGES
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_FILES
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_QUEUES
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_CMDS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_MAPPINGS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_BUFLISTS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_AGPLISTS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_CTXBITMAP
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_SGLISTS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_DRAWABLE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_MM
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_HASHTAB
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|DRM_MEM_KMS
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_DECL
argument_list|(
name|_hw_drm
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|DRM_MAX_CTXBITMAP
value|(PAGE_SIZE * 8)
end_define

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/** \name Internal types and structures */
end_comment

begin_comment
comment|/*@{*/
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
name|DRM_IF_VERSION
parameter_list|(
name|maj
parameter_list|,
name|min
parameter_list|)
value|(maj<< 16 | min)
end_define

begin_define
define|#
directive|define
name|__OS_HAS_AGP
value|1
end_define

begin_define
define|#
directive|define
name|DRM_DEV_MODE
value|(S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP)
end_define

begin_define
define|#
directive|define
name|DRM_DEV_UID
value|0
end_define

begin_define
define|#
directive|define
name|DRM_DEV_GID
value|0
end_define

begin_define
define|#
directive|define
name|wait_queue_head_t
value|atomic_t
end_define

begin_define
define|#
directive|define
name|DRM_WAKEUP
parameter_list|(
name|w
parameter_list|)
value|wakeup((void *)w)
end_define

begin_define
define|#
directive|define
name|DRM_WAKEUP_INT
parameter_list|(
name|w
parameter_list|)
value|wakeup(w)
end_define

begin_define
define|#
directive|define
name|DRM_INIT_WAITQUEUE
parameter_list|(
name|queue
parameter_list|)
value|do {(void)(queue);} while (0)
end_define

begin_define
define|#
directive|define
name|DRM_CURPROC
value|curthread
end_define

begin_define
define|#
directive|define
name|DRM_STRUCTPROC
value|struct thread
end_define

begin_define
define|#
directive|define
name|DRM_SPINTYPE
value|struct mtx
end_define

begin_define
define|#
directive|define
name|DRM_SPININIT
parameter_list|(
name|l
parameter_list|,
name|name
parameter_list|)
value|mtx_init(l, name, NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|DRM_SPINUNINIT
parameter_list|(
name|l
parameter_list|)
value|mtx_destroy(l)
end_define

begin_define
define|#
directive|define
name|DRM_SPINLOCK
parameter_list|(
name|l
parameter_list|)
value|mtx_lock(l)
end_define

begin_define
define|#
directive|define
name|DRM_SPINUNLOCK
parameter_list|(
name|u
parameter_list|)
value|mtx_unlock(u)
end_define

begin_define
define|#
directive|define
name|DRM_SPINLOCK_IRQSAVE
parameter_list|(
name|l
parameter_list|,
name|irqflags
parameter_list|)
value|do {		\ 	mtx_lock(l);					\ 	(void)irqflags;					\ } while (0)
end_define

begin_define
define|#
directive|define
name|DRM_SPINUNLOCK_IRQRESTORE
parameter_list|(
name|u
parameter_list|,
name|irqflags
parameter_list|)
value|mtx_unlock(u)
end_define

begin_define
define|#
directive|define
name|DRM_SPINLOCK_ASSERT
parameter_list|(
name|l
parameter_list|)
value|mtx_assert(l, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|DRM_CURRENTPID
value|curthread->td_proc->p_pid
end_define

begin_define
define|#
directive|define
name|DRM_LOCK
parameter_list|(
name|dev
parameter_list|)
value|sx_xlock(&(dev)->dev_struct_lock)
end_define

begin_define
define|#
directive|define
name|DRM_UNLOCK
parameter_list|(
name|dev
parameter_list|)
value|sx_xunlock(&(dev)->dev_struct_lock)
end_define

begin_define
define|#
directive|define
name|DRM_LOCK_SLEEP
parameter_list|(
name|dev
parameter_list|,
name|chan
parameter_list|,
name|flags
parameter_list|,
name|msg
parameter_list|,
name|timeout
parameter_list|)
define|\
value|(sx_sleep((chan),&(dev)->dev_struct_lock, (flags), (msg), (timeout)))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DRM_LOCK_ASSERT
parameter_list|(
name|dev
parameter_list|)
value|sx_assert(&(dev)->dev_struct_lock, SA_XLOCKED)
end_define

begin_define
define|#
directive|define
name|DRM_UNLOCK_ASSERT
parameter_list|(
name|dev
parameter_list|)
value|sx_assert(&(dev)->dev_struct_lock, SA_UNLOCKED)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DRM_LOCK_ASSERT
parameter_list|(
name|d
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DRM_UNLOCK_ASSERT
parameter_list|(
name|d
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DRM_SYSCTL_HANDLER_ARGS
value|(SYSCTL_HANDLER_ARGS)
end_define

begin_define
define|#
directive|define
name|DRM_IRQ_ARGS
value|void *arg
end_define

begin_typedef
typedef|typedef
name|void
name|irqreturn_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IRQ_HANDLED
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|IRQ_NONE
end_define

begin_comment
comment|/* nothing */
end_comment

begin_enum
enum|enum
block|{
name|DRM_IS_NOT_AGP
block|,
name|DRM_IS_AGP
block|,
name|DRM_MIGHT_BE_AGP
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|DRM_AGP_MEM
value|struct agp_memory_info
end_define

begin_define
define|#
directive|define
name|drm_get_device_from_kdev
parameter_list|(
name|_kdev
parameter_list|)
value|(_kdev->si_drv1)
end_define

begin_define
define|#
directive|define
name|PAGE_ALIGN
parameter_list|(
name|addr
parameter_list|)
value|round_page(addr)
end_define

begin_comment
comment|/* DRM_SUSER returns true if the user is superuser */
end_comment

begin_define
define|#
directive|define
name|DRM_SUSER
parameter_list|(
name|p
parameter_list|)
value|(priv_check(p, PRIV_DRIVER) == 0)
end_define

begin_define
define|#
directive|define
name|DRM_AGP_FIND_DEVICE
parameter_list|()
value|agp_find_device()
end_define

begin_define
define|#
directive|define
name|DRM_MTRR_WC
value|MDF_WRITECOMBINE
end_define

begin_define
define|#
directive|define
name|jiffies
value|ticks
end_define

begin_define
define|#
directive|define
name|jiffies_to_msecs
parameter_list|(
name|x
parameter_list|)
value|(((int64_t)(x)) * 1000 / hz)
end_define

begin_define
define|#
directive|define
name|msecs_to_jiffies
parameter_list|(
name|x
parameter_list|)
value|(((int64_t)(x)) * hz / 1000)
end_define

begin_define
define|#
directive|define
name|time_after
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)(b) - (long)(a)< 0)
end_define

begin_define
define|#
directive|define
name|time_after_eq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|((long)(b) - (long)(a)<= 0)
end_define

begin_define
define|#
directive|define
name|drm_msleep
parameter_list|(
name|x
parameter_list|,
name|msg
parameter_list|)
value|pause((msg), ((int64_t)(x)) * hz / 1000)
end_define

begin_comment
comment|/* DRM_READMEMORYBARRIER() prevents reordering of reads.  * DRM_WRITEMEMORYBARRIER() prevents reordering of writes.  * DRM_MEMORYBARRIER() prevents reordering of reads and writes.  */
end_comment

begin_define
define|#
directive|define
name|DRM_READMEMORYBARRIER
parameter_list|()
value|rmb()
end_define

begin_define
define|#
directive|define
name|DRM_WRITEMEMORYBARRIER
parameter_list|()
value|wmb()
end_define

begin_define
define|#
directive|define
name|DRM_MEMORYBARRIER
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|DRM_READ8
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|)
define|\
value|*(volatile u_int8_t *)(((vm_offset_t)(map)->virtual) +		\ 	    (vm_offset_t)(offset))
end_define

begin_define
define|#
directive|define
name|DRM_READ16
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|)
define|\
value|le16toh(*(volatile u_int16_t *)(((vm_offset_t)(map)->virtual) +	\ 	    (vm_offset_t)(offset)))
end_define

begin_define
define|#
directive|define
name|DRM_READ32
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|)
define|\
value|le32toh(*(volatile u_int32_t *)(((vm_offset_t)(map)->virtual) +	\ 	    (vm_offset_t)(offset)))
end_define

begin_define
define|#
directive|define
name|DRM_READ64
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|)
define|\
value|le64toh(*(volatile u_int64_t *)(((vm_offset_t)(map)->virtual) +	\ 	    (vm_offset_t)(offset)))
end_define

begin_define
define|#
directive|define
name|DRM_WRITE8
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|*(volatile u_int8_t *)(((vm_offset_t)(map)->virtual) +		\ 	    (vm_offset_t)(offset)) = val
end_define

begin_define
define|#
directive|define
name|DRM_WRITE16
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|*(volatile u_int16_t *)(((vm_offset_t)(map)->virtual) +		\ 	    (vm_offset_t)(offset)) = htole16(val)
end_define

begin_define
define|#
directive|define
name|DRM_WRITE32
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|*(volatile u_int32_t *)(((vm_offset_t)(map)->virtual) +		\ 	    (vm_offset_t)(offset)) = htole32(val)
end_define

begin_define
define|#
directive|define
name|DRM_WRITE64
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|*(volatile u_int64_t *)(((vm_offset_t)(map)->virtual) +		\ 	    (vm_offset_t)(offset)) = htole64(val)
end_define

begin_define
define|#
directive|define
name|DRM_VERIFYAREA_READ
parameter_list|(
name|uaddr
parameter_list|,
name|size
parameter_list|)
define|\
value|(!useracc(__DECONST(caddr_t, uaddr), size, VM_PROT_READ))
end_define

begin_define
define|#
directive|define
name|DRM_COPY_TO_USER
parameter_list|(
name|user
parameter_list|,
name|kern
parameter_list|,
name|size
parameter_list|)
define|\
value|copyout(kern, user, size)
end_define

begin_define
define|#
directive|define
name|DRM_COPY_FROM_USER
parameter_list|(
name|kern
parameter_list|,
name|user
parameter_list|,
name|size
parameter_list|)
define|\
value|copyin(user, kern, size)
end_define

begin_define
define|#
directive|define
name|DRM_COPY_FROM_USER_UNCHECKED
parameter_list|(
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|copyin(arg2, arg1, arg3)
end_define

begin_define
define|#
directive|define
name|DRM_COPY_TO_USER_UNCHECKED
parameter_list|(
name|arg1
parameter_list|,
name|arg2
parameter_list|,
name|arg3
parameter_list|)
define|\
value|copyout(arg2, arg1, arg3)
end_define

begin_define
define|#
directive|define
name|DRM_GET_USER_UNCHECKED
parameter_list|(
name|val
parameter_list|,
name|uaddr
parameter_list|)
define|\
value|((val) = fuword32(uaddr), 0)
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

begin_define
define|#
directive|define
name|LOCK_TEST_WITH_RETURN
parameter_list|(
name|dev
parameter_list|,
name|file_priv
parameter_list|)
define|\
value|do {									\ 	if (!_DRM_LOCK_IS_HELD(dev->lock.hw_lock->lock) ||		\ 	     dev->lock.file_priv != file_priv) {			\ 		DRM_ERROR("%s called without lock held\n",		\ 			   __FUNCTION__);				\ 		return EINVAL;						\ 	}								\ } while (0)
end_define

begin_comment
comment|/* Returns -errno to shared code */
end_comment

begin_define
define|#
directive|define
name|DRM_WAIT_ON
parameter_list|(
name|ret
parameter_list|,
name|queue
parameter_list|,
name|timeout
parameter_list|,
name|condition
parameter_list|)
define|\
value|for ( ret = 0 ; !ret&& !(condition) ; ) {			\ 	DRM_UNLOCK(dev);						\ 	mtx_lock(&dev->irq_lock);				\ 	if (!(condition))					\ 	    ret = -mtx_sleep(&(queue),&dev->irq_lock, 		\ 		PCATCH, "drmwtq", (timeout));			\ 	mtx_unlock(&dev->irq_lock);				\ 	DRM_LOCK(dev);						\ }
end_define

begin_define
define|#
directive|define
name|DRM_ERROR
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|printf("error: [" DRM_NAME ":pid%d:%s] *ERROR* " fmt,		\ 	    DRM_CURRENTPID, __func__ , ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DRM_INFO
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|printf("info: [" DRM_NAME "] " fmt , ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DRM_DEBUG
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	if ((drm_debug_flag& DRM_DEBUGBITS_DEBUG) != 0)		\ 		printf("[" DRM_NAME ":pid%d:%s] " fmt, DRM_CURRENTPID,	\ 			__func__ , ##__VA_ARGS__);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|DRM_DEBUG_KMS
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	if ((drm_debug_flag& DRM_DEBUGBITS_KMS) != 0)			\ 		printf("[" DRM_NAME ":KMS:pid%d:%s] " fmt, DRM_CURRENTPID,\ 			__func__ , ##__VA_ARGS__);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|DRM_DEBUG_DRIVER
parameter_list|(
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	if ((drm_debug_flag& DRM_DEBUGBITS_KMS) != 0)			\ 		printf("[" DRM_NAME ":KMS:pid%d:%s] " fmt, DRM_CURRENTPID,\ 			__func__ , ##__VA_ARGS__);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|dev_err
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|device_printf((dev), "error: " fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|dev_warn
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|device_printf((dev), "warning: " fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|dev_info
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
define|\
value|device_printf((dev), "info: " fmt, ## __VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|dev_dbg
parameter_list|(
name|dev
parameter_list|,
name|fmt
parameter_list|,
modifier|...
parameter_list|)
value|do {					\ 	if ((drm_debug_flag& DRM_DEBUGBITS_KMS) != 0) {			\ 		device_printf((dev), "debug: " fmt, ## __VA_ARGS__);	\ 	}								\ } while (0)
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_pci_id_list
block|{
name|int
name|vendor
decl_stmt|;
name|int
name|device
decl_stmt|;
name|long
name|driver_private
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|drm_pci_id_list_t
typedef|;
end_typedef

begin_struct
struct|struct
name|drm_msi_blacklist_entry
block|{
name|int
name|vendor
decl_stmt|;
name|int
name|device
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_AUTH
value|0x1
end_define

begin_define
define|#
directive|define
name|DRM_MASTER
value|0x2
end_define

begin_define
define|#
directive|define
name|DRM_ROOT_ONLY
value|0x4
end_define

begin_define
define|#
directive|define
name|DRM_CONTROL_ALLOW
value|0x8
end_define

begin_define
define|#
directive|define
name|DRM_UNLOCKED
value|0x10
end_define

begin_typedef
typedef|typedef
struct|struct
name|drm_ioctl_desc
block|{
name|unsigned
name|long
name|cmd
decl_stmt|;
name|int
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
name|int
name|flags
decl_stmt|;
name|unsigned
name|int
name|cmd_drv
decl_stmt|;
block|}
name|drm_ioctl_desc_t
typedef|;
end_typedef

begin_comment
comment|/**  * Creates a driver or general drm_ioctl_desc array entry for the given  * ioctl, for use by drm_ioctl().  */
end_comment

begin_define
define|#
directive|define
name|DRM_IOCTL_DEF
parameter_list|(
name|ioctl
parameter_list|,
name|func
parameter_list|,
name|flags
parameter_list|)
define|\
value|[DRM_IOCTL_NR(ioctl)] = {ioctl, func, flags}
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_DEF_DRV
parameter_list|(
name|ioctl
parameter_list|,
name|_func
parameter_list|,
name|_flags
parameter_list|)
define|\
value|[DRM_IOCTL_NR(DRM_##ioctl)] = {.cmd = DRM_##ioctl, .func = _func, .flags = _flags, .cmd_drv = DRM_IOCTL_##ioctl}
end_define

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
comment|/**< Index into master buflist */
name|int
name|total
decl_stmt|;
comment|/**< Buffer size */
name|int
name|order
decl_stmt|;
comment|/**< log-base-2(total) */
name|int
name|used
decl_stmt|;
comment|/**< Amount of buffer in use (for DMA) */
name|unsigned
name|long
name|offset
decl_stmt|;
comment|/**< Byte offset (used internally) */
name|void
modifier|*
name|address
decl_stmt|;
comment|/**< Address of buffer */
name|unsigned
name|long
name|bus_address
decl_stmt|;
comment|/**< Bus address of buffer */
name|struct
name|drm_buf
modifier|*
name|next
decl_stmt|;
comment|/**< Kernel-only: used for free list */
specifier|__volatile__
name|int
name|waiting
decl_stmt|;
comment|/**< On kernel DMA queue */
specifier|__volatile__
name|int
name|pending
decl_stmt|;
comment|/**< On hardware DMA queue */
name|struct
name|drm_file
modifier|*
name|file_priv
decl_stmt|;
comment|/**< Private of holding file descr */
name|int
name|context
decl_stmt|;
comment|/**< Kernel queue for this buffer */
name|int
name|while_locked
decl_stmt|;
comment|/**< Dispatch this buffer while locked */
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
comment|/**< Which list we're on */
name|int
name|dev_priv_size
decl_stmt|;
comment|/**< Size of buffer private storage */
name|void
modifier|*
name|dev_private
decl_stmt|;
comment|/**< Per-buffer private storage */
block|}
name|drm_buf_t
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
block|}
name|drm_freelist_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|drm_dma_handle
block|{
name|void
modifier|*
name|vaddr
decl_stmt|;
name|bus_addr_t
name|busaddr
decl_stmt|;
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
block|}
name|drm_dma_handle_t
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
name|drm_dma_handle_t
modifier|*
modifier|*
name|seglist
decl_stmt|;
name|int
name|page_order
decl_stmt|;
name|drm_freelist_t
name|freelist
decl_stmt|;
block|}
name|drm_buf_entry_t
typedef|;
end_typedef

begin_comment
comment|/* Event queued up for userspace to read */
end_comment

begin_struct
struct|struct
name|drm_pending_event
block|{
name|struct
name|drm_event
modifier|*
name|event
decl_stmt|;
name|struct
name|list_head
name|link
decl_stmt|;
name|struct
name|drm_file
modifier|*
name|file_priv
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
comment|/* pid of requester, no guarantee it's valid by the time 		      we deliver the event, for tracing only */
name|void
function_decl|(
modifier|*
name|destroy
function_decl|)
parameter_list|(
name|struct
name|drm_pending_event
modifier|*
name|event
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/* initial implementaton using a linked list - todo hashtab */
end_comment

begin_struct
struct|struct
name|drm_prime_file_private
block|{
name|struct
name|list_head
name|head
decl_stmt|;
ifdef|#
directive|ifdef
name|DUMBBELL_WIP
name|struct
name|mutex
name|lock
decl_stmt|;
endif|#
directive|endif
comment|/* DUMBBELL_WIP */
block|}
struct|;
end_struct

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
name|struct
name|drm_device
modifier|*
name|dev
decl_stmt|;
name|int
name|authenticated
decl_stmt|;
name|int
name|master
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
name|void
modifier|*
name|driver_priv
decl_stmt|;
name|struct
name|drm_gem_names
name|object_names
decl_stmt|;
name|int
name|is_master
decl_stmt|;
name|struct
name|drm_master
modifier|*
name|masterp
decl_stmt|;
name|struct
name|list_head
name|fbs
decl_stmt|;
name|struct
name|list_head
name|event_list
decl_stmt|;
name|int
name|event_space
decl_stmt|;
name|struct
name|selinfo
name|event_poll
decl_stmt|;
name|struct
name|drm_prime_file_private
name|prime
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|drm_lock_data
block|{
name|struct
name|drm_hw_lock
modifier|*
name|hw_lock
decl_stmt|;
comment|/* Hardware lock		   */
name|struct
name|drm_file
modifier|*
name|file_priv
decl_stmt|;
comment|/* Unique identifier of holding process (NULL is kernel)*/
name|int
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

begin_comment
comment|/* This structure, in the struct drm_device, is always initialized while the  * device  * is open.  dev->dma_lock protects the incrementing of dev->buf_use, which  * when set marks that no further bufs may be allocated until device teardown  * occurs (when the last open of the device has closed).  The high/low  * watermarks of bufs are only touched by the X Server, and thus not  * concurrently accessed, so no locking is needed.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_device_dma
block|{
name|struct
name|drm_buf_entry
name|bufs
index|[
name|DRM_MAX_ORDER
operator|+
literal|1
index|]
decl_stmt|;
comment|/**< buffers, grouped by their size order */
name|int
name|buf_count
decl_stmt|;
comment|/**< total number of buffers */
name|struct
name|drm_buf
modifier|*
modifier|*
name|buflist
decl_stmt|;
comment|/**< Vector of pointers into drm_device_dma::bufs */
name|int
name|seg_count
decl_stmt|;
name|int
name|page_count
decl_stmt|;
comment|/**< number of pages */
name|unsigned
name|long
modifier|*
name|pagelist
decl_stmt|;
comment|/**< page list */
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
block|,
name|_DRM_DMA_USE_FB
init|=
literal|0x04
block|,
name|_DRM_DMA_USE_PCI_RO
init|=
literal|0x08
block|}
name|flags
enum|;
block|}
name|drm_device_dma_t
typedef|;
end_typedef

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
name|mtrr
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

begin_typedef
typedef|typedef
struct|struct
name|drm_sg_mem
block|{
name|vm_offset_t
name|vaddr
decl_stmt|;
name|vm_paddr_t
modifier|*
name|busaddr
decl_stmt|;
name|vm_pindex_t
name|pages
decl_stmt|;
block|}
name|drm_sg_mem_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DRM_MAP_HANDLE_BITS
value|(sizeof(void *) == 4 ? 4 : 24)
end_define

begin_define
define|#
directive|define
name|DRM_MAP_HANDLE_SHIFT
value|(sizeof(void *) * 8 - DRM_MAP_HANDLE_BITS)
end_define

begin_typedef
typedef|typedef
name|TAILQ_HEAD
argument_list|(
argument|drm_map_list
argument_list|,
argument|drm_local_map
argument_list|)
name|drm_map_list_t
expr_stmt|;
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
comment|/* Physical address (0 for SAREA)       */
name|unsigned
name|long
name|size
decl_stmt|;
comment|/* Physical size (bytes)                */
name|enum
name|drm_map_type
name|type
decl_stmt|;
comment|/* Type of memory mapped                */
name|enum
name|drm_map_flags
name|flags
decl_stmt|;
comment|/* Flags                                */
name|void
modifier|*
name|handle
decl_stmt|;
comment|/* User-space: "Handle" to pass to mmap */
comment|/* Kernel-space: kernel-virtual address */
name|int
name|mtrr
decl_stmt|;
comment|/* Boolean: MTRR used                   */
comment|/* Private data                         */
name|int
name|rid
decl_stmt|;
comment|/* PCI resource ID for bus_space        */
name|void
modifier|*
name|virtual
decl_stmt|;
comment|/* Kernel-space: kernel-virtual address */
name|struct
name|resource
modifier|*
name|bsr
decl_stmt|;
name|bus_space_tag_t
name|bst
decl_stmt|;
name|bus_space_handle_t
name|bsh
decl_stmt|;
name|drm_dma_handle_t
modifier|*
name|dmah
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|drm_local_map
argument_list|)
name|link
expr_stmt|;
block|}
name|drm_local_map_t
typedef|;
end_typedef

begin_struct
struct|struct
name|drm_vblank_info
block|{
name|wait_queue_head_t
name|queue
decl_stmt|;
comment|/* vblank wait queue */
name|atomic_t
name|count
decl_stmt|;
comment|/* number of VBLANK interrupts */
comment|/* (driver must alloc the right number of counters) */
name|atomic_t
name|refcount
decl_stmt|;
comment|/* number of users of vblank interrupts */
name|u32
name|last
decl_stmt|;
comment|/* protected by dev->vbl_lock, used */
comment|/* for wraparound handling */
name|int
name|enabled
decl_stmt|;
comment|/* so we don't call enable more than */
comment|/* once per disable */
name|int
name|inmodeset
decl_stmt|;
comment|/* Display driver is setting mode */
block|}
struct|;
end_struct

begin_comment
comment|/* location of GART table */
end_comment

begin_define
define|#
directive|define
name|DRM_ATI_GART_MAIN
value|1
end_define

begin_define
define|#
directive|define
name|DRM_ATI_GART_FB
value|2
end_define

begin_define
define|#
directive|define
name|DRM_ATI_GART_PCI
value|1
end_define

begin_define
define|#
directive|define
name|DRM_ATI_GART_PCIE
value|2
end_define

begin_define
define|#
directive|define
name|DRM_ATI_GART_IGP
value|3
end_define

begin_struct
struct|struct
name|drm_ati_pcigart_info
block|{
name|int
name|gart_table_location
decl_stmt|;
name|int
name|gart_reg_if
decl_stmt|;
name|void
modifier|*
name|addr
decl_stmt|;
name|dma_addr_t
name|bus_addr
decl_stmt|;
name|dma_addr_t
name|table_mask
decl_stmt|;
name|dma_addr_t
name|member_mask
decl_stmt|;
name|struct
name|drm_dma_handle
modifier|*
name|table_handle
decl_stmt|;
name|drm_local_map_t
name|mapping
decl_stmt|;
name|int
name|table_size
decl_stmt|;
name|struct
name|drm_dma_handle
modifier|*
name|dmah
decl_stmt|;
comment|/* handle for ATI PCIGART table */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|vm_paddr_t
name|resource_size_t
typedef|;
end_typedef

begin_comment
comment|/**  * GEM specific mm private for tracking GEM objects  */
end_comment

begin_struct
struct|struct
name|drm_gem_mm
block|{
name|struct
name|drm_open_hash
name|offset_hash
decl_stmt|;
comment|/**< User token hash table for maps */
name|struct
name|unrhdr
modifier|*
name|idxunr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_gem_object
block|{
comment|/** Reference count of this object */
name|u_int
name|refcount
decl_stmt|;
comment|/** Handle count of this object. Each handle also holds a reference */
name|u_int
name|handle_count
decl_stmt|;
comment|/* number of handles on this object */
comment|/** Related drm device */
name|struct
name|drm_device
modifier|*
name|dev
decl_stmt|;
comment|/** File representing the shmem storage: filp in Linux parlance */
name|vm_object_t
name|vm_obj
decl_stmt|;
name|bool
name|on_map
decl_stmt|;
name|struct
name|drm_hash_item
name|map_list
decl_stmt|;
comment|/** 	 * Size of the object, in bytes.  Immutable over the object's 	 * lifetime. 	 */
name|size_t
name|size
decl_stmt|;
comment|/** 	 * Global name for this object, starts at 1. 0 means unnamed. 	 * Access is covered by the object_name_lock in the related drm_device 	 */
name|int
name|name
decl_stmt|;
comment|/** 	 * Memory domains. These monitor which caches contain read/write data 	 * related to the object. When transitioning from one set of domains 	 * to another, the driver is called to ensure that caches are suitably 	 * flushed and invalidated 	 */
name|uint32_t
name|read_domains
decl_stmt|;
name|uint32_t
name|write_domain
decl_stmt|;
comment|/** 	 * While validating an exec operation, the 	 * new read/write domain values are computed here. 	 * They will be transferred to the above values 	 * at the point that any cache flushing occurs 	 */
name|uint32_t
name|pending_read_domains
decl_stmt|;
name|uint32_t
name|pending_write_domain
decl_stmt|;
name|void
modifier|*
name|driver_private
decl_stmt|;
ifdef|#
directive|ifdef
name|DUMBBELL_WIP
comment|/* dma buf exported from this GEM object */
name|struct
name|dma_buf
modifier|*
name|export_dma_buf
decl_stmt|;
comment|/* dma buf attachment backing this object */
name|struct
name|dma_buf_attachment
modifier|*
name|import_attach
decl_stmt|;
endif|#
directive|endif
comment|/* DUMBBELL_WIP */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|"drm_crtc.h"
end_include

begin_comment
comment|/* per-master structure */
end_comment

begin_struct
struct|struct
name|drm_master
block|{
name|u_int
name|refcount
decl_stmt|;
comment|/* refcount for this master */
name|struct
name|list_head
name|head
decl_stmt|;
comment|/**< each minor contains a list of masters */
name|struct
name|drm_minor
modifier|*
name|minor
decl_stmt|;
comment|/**< link back to minor we are a master for */
name|char
modifier|*
name|unique
decl_stmt|;
comment|/**< Unique identifier: e.g., busid */
name|int
name|unique_len
decl_stmt|;
comment|/**< Length of unique field */
name|int
name|unique_size
decl_stmt|;
comment|/**< amount allocated */
name|int
name|blocked
decl_stmt|;
comment|/**< Blocked due to VC switch? */
comment|/** \name Authentication */
comment|/*@{ */
name|struct
name|drm_open_hash
name|magiclist
decl_stmt|;
name|struct
name|list_head
name|magicfree
decl_stmt|;
comment|/*@} */
name|struct
name|drm_lock_data
name|lock
decl_stmt|;
comment|/**< Information on hardware lock */
name|void
modifier|*
name|driver_priv
decl_stmt|;
comment|/**< Private structure for driver to use */
block|}
struct|;
end_struct

begin_comment
comment|/* Size of ringbuffer for vblank timestamps. Just double-buffer  * in initial implementation.  */
end_comment

begin_define
define|#
directive|define
name|DRM_VBLANKTIME_RBSIZE
value|2
end_define

begin_comment
comment|/* Flags and return codes for get_vblank_timestamp() driver function. */
end_comment

begin_define
define|#
directive|define
name|DRM_CALLED_FROM_VBLIRQ
value|1
end_define

begin_define
define|#
directive|define
name|DRM_VBLANKTIME_SCANOUTPOS_METHOD
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DRM_VBLANKTIME_INVBL
value|(1<< 1)
end_define

begin_comment
comment|/* get_scanout_position() return flags */
end_comment

begin_define
define|#
directive|define
name|DRM_SCANOUTPOS_VALID
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|DRM_SCANOUTPOS_INVBL
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|DRM_SCANOUTPOS_ACCURATE
value|(1<< 2)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|DMA_BIT_MASK
end_ifndef

begin_define
define|#
directive|define
name|DMA_BIT_MASK
parameter_list|(
name|n
parameter_list|)
value|(((n) == 64) ? ~0ULL : (1ULL<<(n)) - 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|upper_32_bits
parameter_list|(
name|n
parameter_list|)
value|((u32)(((n)>> 16)>> 16))
end_define

begin_struct
struct|struct
name|drm_driver_info
block|{
name|int
function_decl|(
modifier|*
name|load
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|,
name|unsigned
name|long
name|flags
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|use_msi
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|,
name|unsigned
name|long
name|flags
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|firstopen
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|open
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|,
name|struct
name|drm_file
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|preclose
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|postclose
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|,
name|struct
name|drm_file
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|lastclose
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|unload
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|reclaim_buffers_locked
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dma_ioctl
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dma_ready
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dma_quiescent
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dma_flush_block_and_flush
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|,
name|int
name|context
parameter_list|,
name|enum
name|drm_lock_flags
name|flags
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dma_flush_unblock
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
parameter_list|,
name|int
name|context
parameter_list|,
name|enum
name|drm_lock_flags
name|flags
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|context_ctor
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|context
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|context_dtor
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|context
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|kernel_context_switch
function_decl|)
parameter_list|(
name|struct
name|drm_device
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
name|int
function_decl|(
modifier|*
name|kernel_context_switch_unlock
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|irq_preinstall
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|irq_postinstall
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|irq_uninstall
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|irq_handler
function_decl|)
parameter_list|(
name|DRM_IRQ_ARGS
parameter_list|)
function_decl|;
name|u32
function_decl|(
modifier|*
name|get_vblank_counter
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|enable_vblank
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|disable_vblank
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|get_scanout_position
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|,
name|int
modifier|*
name|vpos
parameter_list|,
name|int
modifier|*
name|hpos
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|get_vblank_timestamp
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|,
name|int
modifier|*
name|max_error
parameter_list|,
name|struct
name|timeval
modifier|*
name|vblank_time
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|gem_init_object
function_decl|)
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|gem_free_object
function_decl|)
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|gem_open_object
function_decl|)
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
parameter_list|,
name|struct
name|drm_file
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|gem_close_object
function_decl|)
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
parameter_list|,
name|struct
name|drm_file
modifier|*
parameter_list|)
function_decl|;
name|struct
name|cdev_pager_ops
modifier|*
name|gem_pager_ops
decl_stmt|;
name|int
function_decl|(
modifier|*
name|dumb_create
function_decl|)
parameter_list|(
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|,
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_mode_create_dumb
modifier|*
name|args
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dumb_map_offset
function_decl|)
parameter_list|(
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|,
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|uint32_t
name|handle
parameter_list|,
name|uint64_t
modifier|*
name|offset
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dumb_destroy
function_decl|)
parameter_list|(
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|,
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|uint32_t
name|handle
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sysctl_init
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|sysctl_ctx_list
modifier|*
name|ctx
parameter_list|,
name|struct
name|sysctl_oid
modifier|*
name|top
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|sysctl_cleanup
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|drm_pci_id_list_t
modifier|*
name|id_entry
decl_stmt|;
comment|/* PCI ID, name, and chipset private */
comment|/** 	 * Called by \c drm_device_is_agp.  Typically used to determine if a 	 * card is really attached to AGP or not. 	 * 	 * \param dev  DRM device handle 	 * 	 * \returns 	 * One of three values is returned depending on whether or not the 	 * card is absolutely \b not AGP (return of 0), absolutely \b is AGP 	 * (return of 1), or may or may not be AGP (return of 2). 	 */
name|int
function_decl|(
modifier|*
name|device_is_agp
function_decl|)
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
name|drm_ioctl_desc_t
modifier|*
name|ioctls
decl_stmt|;
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD32
name|drm_ioctl_desc_t
modifier|*
name|compat_ioctls
decl_stmt|;
name|int
modifier|*
name|compat_ioctls_nr
decl_stmt|;
endif|#
directive|endif
name|int
name|max_ioctl
decl_stmt|;
name|int
name|buf_priv_size
decl_stmt|;
name|int
name|major
decl_stmt|;
name|int
name|minor
decl_stmt|;
name|int
name|patchlevel
decl_stmt|;
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Simple driver name		   */
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* Longer driver name		   */
specifier|const
name|char
modifier|*
name|date
decl_stmt|;
comment|/* Date of last major changes.	   */
name|u32
name|driver_features
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * DRM minor structure. This structure represents a drm minor number.  */
end_comment

begin_struct
struct|struct
name|drm_minor
block|{
name|int
name|index
decl_stmt|;
comment|/**< Minor device number */
name|int
name|type
decl_stmt|;
comment|/**< Control or render */
name|device_t
name|kdev
decl_stmt|;
comment|/**< OS device */
name|struct
name|drm_device
modifier|*
name|dev
decl_stmt|;
name|struct
name|drm_master
modifier|*
name|master
decl_stmt|;
comment|/* currently active master for this node */
name|struct
name|list_head
name|master_list
decl_stmt|;
name|struct
name|drm_mode_group
name|mode_group
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* mode specified on the command line */
end_comment

begin_struct
struct|struct
name|drm_cmdline_mode
block|{
name|bool
name|specified
decl_stmt|;
name|bool
name|refresh_specified
decl_stmt|;
name|bool
name|bpp_specified
decl_stmt|;
name|int
name|xres
decl_stmt|,
name|yres
decl_stmt|;
name|int
name|bpp
decl_stmt|;
name|int
name|refresh
decl_stmt|;
name|bool
name|rb
decl_stmt|;
name|bool
name|interlace
decl_stmt|;
name|bool
name|cvt
decl_stmt|;
name|bool
name|margins
decl_stmt|;
name|enum
name|drm_connector_force
name|force
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|drm_pending_vblank_event
block|{
name|struct
name|drm_pending_event
name|base
decl_stmt|;
name|int
name|pipe
decl_stmt|;
name|struct
name|drm_event_vblank
name|event
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Length for the array of resource pointers for drm_get_resource_*. */
end_comment

begin_define
define|#
directive|define
name|DRM_MAX_PCI_RESOURCE
value|6
end_define

begin_comment
comment|/**  * DRM device structure. This structure represent a complete card that  * may contain multiple heads.  */
end_comment

begin_struct
struct|struct
name|drm_device
block|{
name|struct
name|drm_driver_info
modifier|*
name|driver
decl_stmt|;
name|drm_pci_id_list_t
modifier|*
name|id_entry
decl_stmt|;
comment|/* PCI ID, name, and chipset private */
name|uint16_t
name|pci_device
decl_stmt|;
comment|/* PCI device id */
name|uint16_t
name|pci_vendor
decl_stmt|;
comment|/* PCI vendor id */
name|uint16_t
name|pci_subdevice
decl_stmt|;
comment|/* PCI subsystem device id */
name|uint16_t
name|pci_subvendor
decl_stmt|;
comment|/* PCI subsystem vendor id */
name|char
modifier|*
name|unique
decl_stmt|;
comment|/* Unique identifier: e.g., busid  */
name|int
name|unique_len
decl_stmt|;
comment|/* Length of unique field	   */
name|device_t
name|device
decl_stmt|;
comment|/* Device instance from newbus     */
name|struct
name|cdev
modifier|*
name|devnode
decl_stmt|;
comment|/* Device number for mknod	   */
name|int
name|if_version
decl_stmt|;
comment|/* Highest interface version set */
name|int
name|flags
decl_stmt|;
comment|/* Flags to open(2)		   */
comment|/* Locks */
name|struct
name|mtx
name|dma_lock
decl_stmt|;
comment|/* protects dev->dma */
name|struct
name|mtx
name|irq_lock
decl_stmt|;
comment|/* protects irq condition checks */
name|struct
name|mtx
name|dev_lock
decl_stmt|;
comment|/* protects everything else */
name|struct
name|sx
name|dev_struct_lock
decl_stmt|;
name|DRM_SPINTYPE
name|drw_lock
decl_stmt|;
comment|/* Usage Counters */
name|int
name|open_count
decl_stmt|;
comment|/* Outstanding files open	   */
name|int
name|buf_use
decl_stmt|;
comment|/* Buffers in use -- cannot alloc  */
comment|/* Performance counters */
name|unsigned
name|long
name|counters
decl_stmt|;
name|enum
name|drm_stat_type
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
comment|/* Linked list of mappable regions. Protected by dev_lock */
name|drm_map_list_t
name|maplist
decl_stmt|;
name|struct
name|unrhdr
modifier|*
name|map_unrhdr
decl_stmt|;
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
name|irq_enabled
decl_stmt|;
comment|/* True if the irq handler is enabled */
name|int
name|msi_enabled
decl_stmt|;
comment|/* MSI enabled */
name|int
name|irqrid
decl_stmt|;
comment|/* Interrupt used by board */
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
comment|/* Storage of resource pointers for drm_get_resource_* */
name|struct
name|resource
modifier|*
name|pcir
index|[
name|DRM_MAX_PCI_RESOURCE
index|]
decl_stmt|;
name|int
name|pcirid
index|[
name|DRM_MAX_PCI_RESOURCE
index|]
decl_stmt|;
name|int
name|pci_domain
decl_stmt|;
name|int
name|pci_bus
decl_stmt|;
name|int
name|pci_slot
decl_stmt|;
name|int
name|pci_func
decl_stmt|;
name|atomic_t
name|context_flag
decl_stmt|;
comment|/* Context swapping flag	   */
name|int
name|last_context
decl_stmt|;
comment|/* Last current context		   */
name|int
name|num_crtcs
decl_stmt|;
name|struct
name|sigio
modifier|*
name|buf_sigio
decl_stmt|;
comment|/* Processes waiting for SIGIO     */
comment|/* Sysctl support */
name|struct
name|drm_sysctl_info
modifier|*
name|sysctl
decl_stmt|;
name|int
name|sysctl_node_idx
decl_stmt|;
name|drm_agp_head_t
modifier|*
name|agp
decl_stmt|;
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
name|unsigned
name|int
name|agp_buffer_token
decl_stmt|;
name|drm_local_map_t
modifier|*
name|agp_buffer_map
decl_stmt|;
name|struct
name|drm_minor
modifier|*
name|control
decl_stmt|;
comment|/**< Control node for card */
name|struct
name|drm_minor
modifier|*
name|primary
decl_stmt|;
comment|/**< render type primary screen head */
name|void
modifier|*
name|drm_ttm_bdev
decl_stmt|;
name|struct
name|unrhdr
modifier|*
name|drw_unrhdr
decl_stmt|;
comment|/* RB tree of drawable infos */
name|RB_HEAD
argument_list|(
argument|drawable_tree
argument_list|,
argument|bsd_drm_drawable_info
argument_list|)
name|drw_head
expr_stmt|;
name|int
name|vblank_disable_allowed
decl_stmt|;
name|atomic_t
modifier|*
name|_vblank_count
decl_stmt|;
comment|/**< number of VBLANK interrupts (driver must alloc the right number of counters) */
name|struct
name|timeval
modifier|*
name|_vblank_time
decl_stmt|;
comment|/**< timestamp of current vblank_count (drivers must alloc right number of fields) */
name|struct
name|mtx
name|vblank_time_lock
decl_stmt|;
comment|/**< Protects vblank count and time updates during vblank enable/disable */
name|struct
name|mtx
name|vbl_lock
decl_stmt|;
name|atomic_t
modifier|*
name|vblank_refcount
decl_stmt|;
comment|/* number of users of vblank interruptsper crtc */
name|u32
modifier|*
name|last_vblank
decl_stmt|;
comment|/* protected by dev->vbl_lock, used */
comment|/* for wraparound handling */
name|int
modifier|*
name|vblank_enabled
decl_stmt|;
comment|/* so we don't call enable more than 					   once per disable */
name|int
modifier|*
name|vblank_inmodeset
decl_stmt|;
comment|/* Display driver is setting mode */
name|u32
modifier|*
name|last_vblank_wait
decl_stmt|;
comment|/* Last vblank seqno waited per CRTC */
name|struct
name|callout
name|vblank_disable_callout
decl_stmt|;
name|u32
name|max_vblank_count
decl_stmt|;
comment|/**< size of vblank counter register */
name|struct
name|list_head
name|vblank_event_list
decl_stmt|;
name|struct
name|mtx
name|event_lock
decl_stmt|;
name|struct
name|drm_mode_config
name|mode_config
decl_stmt|;
comment|/**< Current mode config */
comment|/* GEM part */
name|struct
name|sx
name|object_name_lock
decl_stmt|;
name|struct
name|drm_gem_names
name|object_names
decl_stmt|;
name|void
modifier|*
name|mm_private
decl_stmt|;
name|void
modifier|*
name|sysctl_private
decl_stmt|;
name|char
name|busid_str
index|[
literal|128
index|]
decl_stmt|;
name|int
name|modesetting
decl_stmt|;
name|int
name|switch_power_state
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DRM_SWITCH_POWER_ON
value|0
end_define

begin_define
define|#
directive|define
name|DRM_SWITCH_POWER_OFF
value|1
end_define

begin_define
define|#
directive|define
name|DRM_SWITCH_POWER_CHANGING
value|2
end_define

begin_function
specifier|static
name|__inline__
name|int
name|drm_core_check_feature
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|feature
parameter_list|)
block|{
return|return
operator|(
operator|(
name|dev
operator|->
name|driver
operator|->
name|driver_features
operator|&
name|feature
operator|)
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_if
if|#
directive|if
name|__OS_HAS_AGP
end_if

begin_function
specifier|static
specifier|inline
name|int
name|drm_core_has_AGP
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
block|{
return|return
name|drm_core_check_feature
argument_list|(
name|dev
argument_list|,
name|DRIVER_USE_AGP
argument_list|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|drm_core_has_AGP
parameter_list|(
name|dev
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_enum
enum|enum
name|dmi_field
block|{
name|DMI_NONE
block|,
name|DMI_BIOS_VENDOR
block|,
name|DMI_BIOS_VERSION
block|,
name|DMI_BIOS_DATE
block|,
name|DMI_SYS_VENDOR
block|,
name|DMI_PRODUCT_NAME
block|,
name|DMI_PRODUCT_VERSION
block|,
name|DMI_PRODUCT_SERIAL
block|,
name|DMI_PRODUCT_UUID
block|,
name|DMI_BOARD_VENDOR
block|,
name|DMI_BOARD_NAME
block|,
name|DMI_BOARD_VERSION
block|,
name|DMI_BOARD_SERIAL
block|,
name|DMI_BOARD_ASSET_TAG
block|,
name|DMI_CHASSIS_VENDOR
block|,
name|DMI_CHASSIS_TYPE
block|,
name|DMI_CHASSIS_VERSION
block|,
name|DMI_CHASSIS_SERIAL
block|,
name|DMI_CHASSIS_ASSET_TAG
block|,
name|DMI_STRING_MAX
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|dmi_strmatch
block|{
name|unsigned
name|char
name|slot
decl_stmt|;
name|char
name|substr
index|[
literal|79
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|dmi_system_id
block|{
name|int
function_decl|(
modifier|*
name|callback
function_decl|)
parameter_list|(
specifier|const
name|struct
name|dmi_system_id
modifier|*
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|ident
decl_stmt|;
name|struct
name|dmi_strmatch
name|matches
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|DMI_MATCH
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{(a), (b)}
end_define

begin_function_decl
name|bool
name|dmi_check_system
parameter_list|(
specifier|const
name|struct
name|dmi_system_id
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|drm_debug_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|drm_notyet_flag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|drm_vblank_offdelay
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|drm_timestamp_precision
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|drm_timestamp_monotonic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device setup support (drm_drv.c) */
end_comment

begin_function_decl
name|int
name|drm_probe
parameter_list|(
name|device_t
name|kdev
parameter_list|,
name|drm_pci_id_list_t
modifier|*
name|idlist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_attach
parameter_list|(
name|device_t
name|kdev
parameter_list|,
name|drm_pci_id_list_t
modifier|*
name|idlist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_create_cdevs
parameter_list|(
name|device_t
name|kdev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_close
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_detach
parameter_list|(
name|device_t
name|kdev
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|d_ioctl_t
name|drm_ioctl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_open_t
name|drm_open
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_read_t
name|drm_read
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_poll_t
name|drm_poll
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|d_mmap_t
name|drm_mmap
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|drm_local_map_t
modifier|*
name|drm_getsarea
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_event_wakeup
parameter_list|(
name|struct
name|drm_pending_event
modifier|*
name|e
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_add_busid_modesetting
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|sysctl_ctx_list
modifier|*
name|ctx
parameter_list|,
name|struct
name|sysctl_oid
modifier|*
name|top
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* File operations helpers (drm_fops.c) */
end_comment

begin_function_decl
specifier|extern
name|int
name|drm_open_helper
parameter_list|(
name|struct
name|cdev
modifier|*
name|kdev
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|fmt
parameter_list|,
name|DRM_STRUCTPROC
modifier|*
name|p
parameter_list|,
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DUMBBELL_WIP
end_ifdef

begin_function_decl
specifier|extern
name|int
name|drm_gem_prime_handle_to_fd
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|,
name|uint32_t
name|handle
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
name|int
modifier|*
name|prime_fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drm_gem_prime_fd_to_handle
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|,
name|int
name|prime_fd
parameter_list|,
name|uint32_t
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drm_prime_handle_to_fd_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drm_prime_fd_to_handle_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DUMBBELL_WIP
end_ifdef

begin_comment
comment|/*  * See drm_prime.c  *   -- dumbbell@  */
end_comment

begin_function_decl
specifier|extern
name|int
name|drm_prime_sg_to_page_addr_arrays
parameter_list|(
name|struct
name|sg_table
modifier|*
name|sgt
parameter_list|,
name|vm_page_t
modifier|*
name|pages
parameter_list|,
name|dma_addr_t
modifier|*
name|addrs
parameter_list|,
name|int
name|max_pages
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DUMBBELL_WIP */
end_comment

begin_function_decl
specifier|extern
name|struct
name|sg_table
modifier|*
name|drm_prime_pages_to_sg
parameter_list|(
name|vm_page_t
modifier|*
name|pages
parameter_list|,
name|int
name|nr_pages
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|drm_prime_gem_destroy
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|,
name|struct
name|sg_table
modifier|*
name|sg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_prime_init_file_private
parameter_list|(
name|struct
name|drm_prime_file_private
modifier|*
name|prime_fpriv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_prime_destroy_file_private
parameter_list|(
name|struct
name|drm_prime_file_private
modifier|*
name|prime_fpriv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_prime_add_imported_buf_handle
parameter_list|(
name|struct
name|drm_prime_file_private
modifier|*
name|prime_fpriv
parameter_list|,
name|struct
name|dma_buf
modifier|*
name|dma_buf
parameter_list|,
name|uint32_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_prime_lookup_imported_buf_handle
parameter_list|(
name|struct
name|drm_prime_file_private
modifier|*
name|prime_fpriv
parameter_list|,
name|struct
name|dma_buf
modifier|*
name|dma_buf
parameter_list|,
name|uint32_t
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_prime_remove_imported_buf_handle
parameter_list|(
name|struct
name|drm_prime_file_private
modifier|*
name|prime_fpriv
parameter_list|,
name|struct
name|dma_buf
modifier|*
name|dma_buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_prime_add_dma_buf
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_prime_lookup_obj
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|dma_buf
modifier|*
name|buf
parameter_list|,
name|struct
name|drm_gem_object
modifier|*
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DUMBBELL_WIP */
end_comment

begin_comment
comment|/* Memory management support (drm_memory.c) */
end_comment

begin_function_decl
name|void
name|drm_mem_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_mem_uninit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|drm_ioremap_wc
parameter_list|(
name|struct
name|drm_device
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
name|void
modifier|*
name|drm_ioremap
parameter_list|(
name|struct
name|drm_device
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
name|void
name|drm_ioremapfree
parameter_list|(
name|drm_local_map_t
modifier|*
name|map
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_mtrr_add
parameter_list|(
name|unsigned
name|long
name|offset
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_mtrr_del
parameter_list|(
name|int
name|handle
parameter_list|,
name|unsigned
name|long
name|offset
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_context_switch
parameter_list|(
name|struct
name|drm_device
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
name|int
name|drm_context_switch_complete
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|new
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_ctxbitmap_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_ctxbitmap_cleanup
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_ctxbitmap_free
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|ctx_handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_ctxbitmap_next
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Locking IOCTL support (drm_lock.c) */
end_comment

begin_function_decl
name|int
name|drm_lock_take
parameter_list|(
name|struct
name|drm_lock_data
modifier|*
name|lock_data
parameter_list|,
name|unsigned
name|int
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_lock_transfer
parameter_list|(
name|struct
name|drm_lock_data
modifier|*
name|lock_data
parameter_list|,
name|unsigned
name|int
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_lock_free
parameter_list|(
name|struct
name|drm_lock_data
modifier|*
name|lock_data
parameter_list|,
name|unsigned
name|int
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Buffer management support (drm_bufs.c) */
end_comment

begin_function_decl
name|unsigned
name|long
name|drm_get_resource_start
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|resource
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|drm_get_resource_len
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|int
name|resource
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_rmmap
parameter_list|(
name|struct
name|drm_device
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
name|int
name|drm_order
parameter_list|(
name|unsigned
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_addmap
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|unsigned
name|long
name|offset
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|enum
name|drm_map_type
name|type
parameter_list|,
name|enum
name|drm_map_flags
name|flags
parameter_list|,
name|drm_local_map_t
modifier|*
modifier|*
name|map_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_addbufs_pci
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_buf_desc
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_addbufs_sg
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_buf_desc
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_addbufs_agp
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_buf_desc
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DMA support (drm_dma.c) */
end_comment

begin_function_decl
name|int
name|drm_dma_setup
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_dma_takedown
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_free_buffer
parameter_list|(
name|struct
name|drm_device
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
name|void
name|drm_reclaim_buffers
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|drm_core_reclaim_buffers
value|drm_reclaim_buffers
end_define

begin_comment
comment|/* IRQ support (drm_irq.c) */
end_comment

begin_function_decl
name|int
name|drm_irq_install
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_irq_uninstall
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|irqreturn_t
name|drm_irq_handler
parameter_list|(
name|DRM_IRQ_ARGS
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_driver_irq_preinstall
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_driver_irq_postinstall
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_driver_irq_uninstall
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_vblank_pre_modeset
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_vblank_post_modeset
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_modeset_ctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drm_vblank_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|num_crtcs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drm_wait_vblank
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|filp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drm_vblank_wait
parameter_list|(
name|struct
name|drm_device
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
name|u32
name|drm_vblank_count
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u32
name|drm_vblank_count_and_time
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|,
name|struct
name|timeval
modifier|*
name|vblanktime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|drm_handle_vblank
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_handle_vblank_events
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drm_vblank_get
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|drm_vblank_put
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|drm_vblank_off
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|drm_vblank_cleanup
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u32
name|drm_get_last_vbltimestamp
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|,
name|struct
name|timeval
modifier|*
name|tvblank
parameter_list|,
name|unsigned
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drm_calc_vbltimestamp_from_scanoutpos
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|crtc
parameter_list|,
name|int
modifier|*
name|max_error
parameter_list|,
name|struct
name|timeval
modifier|*
name|vblank_time
parameter_list|,
name|unsigned
name|flags
parameter_list|,
name|struct
name|drm_crtc
modifier|*
name|refcrtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|drm_calc_timestamping_constants
parameter_list|(
name|struct
name|drm_crtc
modifier|*
name|crtc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|timeval
name|ns_to_timeval
parameter_list|(
specifier|const
name|int64_t
name|nsec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int64_t
name|timeval_to_ns
parameter_list|(
specifier|const
name|struct
name|timeval
modifier|*
name|tv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* AGP/PCI Express/GART support (drm_agpsupport.c) */
end_comment

begin_function_decl
name|int
name|drm_device_is_agp
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_device_is_pcie
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|drm_agp_head_t
modifier|*
name|drm_agp_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_acquire
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_release
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_info
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_agp_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_enable
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_agp_mode
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|drm_agp_allocate_memory
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
name|int
name|drm_agp_free_memory
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_bind_memory
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|,
name|off_t
name|start
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_unbind_memory
parameter_list|(
name|void
modifier|*
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_alloc
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_agp_buffer
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_free
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_agp_buffer
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_bind
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_agp_binding
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_unbind
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_agp_binding
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Scatter Gather Support (drm_scatter.c) */
end_comment

begin_function_decl
name|void
name|drm_sg_cleanup
parameter_list|(
name|drm_sg_mem_t
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_sg_alloc
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_scatter_gather
modifier|*
name|request
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sysctl support (drm_sysctl.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|drm_sysctl_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drm_sysctl_cleanup
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ATI PCIGART support (ati_pcigart.c) */
end_comment

begin_function_decl
name|int
name|drm_ati_pcigart_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_ati_pcigart_info
modifier|*
name|gart_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_ati_pcigart_cleanup
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_ati_pcigart_info
modifier|*
name|gart_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Cache management (drm_memory.c) */
end_comment

begin_function_decl
name|void
name|drm_clflush_pages
parameter_list|(
name|vm_page_t
modifier|*
name|pages
parameter_list|,
name|unsigned
name|long
name|num_pages
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Locking IOCTL support (drm_drv.c) */
end_comment

begin_function_decl
name|int
name|drm_lock
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_unlock
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_version
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_setversion
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Misc. IOCTL support (drm_ioctl.c) */
end_comment

begin_function_decl
name|int
name|drm_irq_by_busid
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_getunique
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_setunique
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_getmap
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_getclient
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_getstats
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_getcap
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_noop
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Context IOCTL support (drm_context.c) */
end_comment

begin_function_decl
name|int
name|drm_resctx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_addctx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_modctx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_getctx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_switchctx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_newctx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_rmctx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_setsareactx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_getsareactx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Drawable IOCTL support (drm_drawable.c) */
end_comment

begin_function_decl
name|int
name|drm_adddraw
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_rmdraw
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_update_draw
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|drm_drawable_info
modifier|*
name|drm_get_drawable_info
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|int
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Drawable support (drm_drawable.c) */
end_comment

begin_function_decl
name|void
name|drm_drawable_free_all
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Authentication IOCTL support (drm_auth.c) */
end_comment

begin_function_decl
name|int
name|drm_getmagic
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_authmagic
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Buffer management support (drm_bufs.c) */
end_comment

begin_function_decl
name|int
name|drm_addmap_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_rmmap_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_addbufs
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_infobufs
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_markbufs
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_freebufs
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_mapbufs
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DMA support (drm_dma.c) */
end_comment

begin_function_decl
name|int
name|drm_dma
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* IRQ support (drm_irq.c) */
end_comment

begin_function_decl
name|int
name|drm_control
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* AGP/GART support (drm_agpsupport.c) */
end_comment

begin_function_decl
name|int
name|drm_agp_acquire_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_release_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_enable_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_info_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_alloc_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_free_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_unbind_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_agp_bind_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Stub support (drm_stub.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|drm_setmaster_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drm_dropmaster_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Scatter Gather Support (drm_scatter.c) */
end_comment

begin_function_decl
name|int
name|drm_sg_alloc_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_sg_free
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* consistent PCI memory functions (drm_pci.c) */
end_comment

begin_function_decl
name|drm_dma_handle_t
modifier|*
name|drm_pci_alloc
parameter_list|(
name|struct
name|drm_device
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_pci_free
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|drm_dma_handle_t
modifier|*
name|dmah
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Graphics Execution Manager library functions (drm_gem.c) */
end_comment

begin_function_decl
name|int
name|drm_gem_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_destroy
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_gem_close_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_gem_flink_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_gem_open_ioctl
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_gem_handle_create
parameter_list|(
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|,
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|,
name|u32
modifier|*
name|handlep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_gem_handle_delete
parameter_list|(
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|,
name|uint32_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_object_handle_reference
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_object_handle_unreference
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_object_handle_unreference_unlocked
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_object_handle_free
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_object_reference
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_object_unreference
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_object_unreference_unlocked
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_object_release
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_object_free
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_gem_object_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_gem_private_object_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|drm_gem_object
modifier|*
name|drm_gem_object_alloc
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|drm_gem_object
modifier|*
name|drm_gem_object_lookup
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|,
name|uint32_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_open
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_release
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_file
modifier|*
name|file_priv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_gem_create_mmap_offset
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_free_mmap_offset
parameter_list|(
name|struct
name|drm_gem_object
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_gem_mmap_single
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|vm_ooffset_t
modifier|*
name|offset
parameter_list|,
name|vm_size_t
name|size
parameter_list|,
name|struct
name|vm_object
modifier|*
modifier|*
name|obj_res
parameter_list|,
name|int
name|nprot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_gem_pager_dtr
parameter_list|(
name|void
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ttm_bo_device
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ttm_bo_mmap_single
parameter_list|(
name|struct
name|ttm_bo_device
modifier|*
name|bdev
parameter_list|,
name|vm_ooffset_t
modifier|*
name|offset
parameter_list|,
name|vm_size_t
name|size
parameter_list|,
name|struct
name|vm_object
modifier|*
modifier|*
name|obj_res
parameter_list|,
name|int
name|nprot
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|ttm_buffer_object
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|ttm_bo_release_mmap
parameter_list|(
name|struct
name|ttm_buffer_object
modifier|*
name|bo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_device_lock_mtx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_device_unlock_mtx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_device_sleep_mtx
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|chan
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_device_assert_mtx_locked
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_device_assert_mtx_unlocked
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_device_lock_struct
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_device_unlock_struct
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|drm_device_sleep_struct
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|void
modifier|*
name|chan
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|msg
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_device_assert_struct_locked
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_device_assert_struct_unlocked
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_compat_locking_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|drm_sleep_locking_init
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* drm_modes.c */
end_comment

begin_function_decl
name|bool
name|drm_mode_parse_command_line_for_connector
parameter_list|(
specifier|const
name|char
modifier|*
name|mode_option
parameter_list|,
name|struct
name|drm_connector
modifier|*
name|connector
parameter_list|,
name|struct
name|drm_cmdline_mode
modifier|*
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|drm_display_mode
modifier|*
name|drm_mode_create_from_cmdline_mode
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|struct
name|drm_cmdline_mode
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* drm_edid.c */
end_comment

begin_function_decl
name|u8
modifier|*
name|drm_find_cea_extension
parameter_list|(
name|struct
name|edid
modifier|*
name|edid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Inline replacements for drm_alloc and friends */
end_comment

begin_function
specifier|static
name|__inline__
name|void
modifier|*
name|drm_alloc
parameter_list|(
name|size_t
name|size
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|area
parameter_list|)
block|{
return|return
name|malloc
argument_list|(
name|size
argument_list|,
name|area
argument_list|,
name|M_NOWAIT
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
modifier|*
name|drm_calloc
parameter_list|(
name|size_t
name|nmemb
parameter_list|,
name|size_t
name|size
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|area
parameter_list|)
block|{
return|return
name|malloc
argument_list|(
name|size
operator|*
name|nmemb
argument_list|,
name|area
argument_list|,
name|M_NOWAIT
operator||
name|M_ZERO
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
modifier|*
name|drm_realloc
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
name|struct
name|malloc_type
modifier|*
name|area
parameter_list|)
block|{
return|return
name|reallocf
argument_list|(
name|oldpt
argument_list|,
name|size
argument_list|,
name|area
argument_list|,
name|M_NOWAIT
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|drm_free
parameter_list|(
name|void
modifier|*
name|pt
parameter_list|,
name|size_t
name|size
parameter_list|,
name|struct
name|malloc_type
modifier|*
name|area
parameter_list|)
block|{
name|free
argument_list|(
name|pt
argument_list|,
name|area
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Inline replacements for DRM_IOREMAP macros */
end_comment

begin_function
specifier|static
name|__inline__
name|void
name|drm_core_ioremap_wc
parameter_list|(
name|struct
name|drm_local_map
modifier|*
name|map
parameter_list|,
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
block|{
name|map
operator|->
name|virtual
operator|=
name|drm_ioremap_wc
argument_list|(
name|dev
argument_list|,
name|map
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|drm_core_ioremap
parameter_list|(
name|struct
name|drm_local_map
modifier|*
name|map
parameter_list|,
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
block|{
name|map
operator|->
name|virtual
operator|=
name|drm_ioremap
argument_list|(
name|dev
argument_list|,
name|map
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|drm_core_ioremapfree
parameter_list|(
name|struct
name|drm_local_map
modifier|*
name|map
parameter_list|,
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|)
block|{
if|if
condition|(
name|map
operator|->
name|virtual
operator|&&
name|map
operator|->
name|size
condition|)
name|drm_ioremapfree
argument_list|(
name|map
argument_list|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
specifier|static
name|__inline__
expr|struct
name|drm_local_map
operator|*
name|drm_core_findmap
argument_list|(
argument|struct drm_device *dev
argument_list|,
argument|unsigned long offset
argument_list|)
block|{
name|drm_local_map_t
operator|*
name|map
block|;
name|DRM_LOCK_ASSERT
argument_list|(
name|dev
argument_list|)
block|;
name|TAILQ_FOREACH
argument_list|(
argument|map
argument_list|,
argument|&dev->maplist
argument_list|,
argument|link
argument_list|)
block|{
if|if
condition|(
name|offset
operator|==
operator|(
name|unsigned
name|long
operator|)
name|map
operator|->
name|handle
condition|)
return|return
name|map
return|;
block|}
end_expr_stmt

begin_return
return|return
name|NULL
return|;
end_return

begin_function
unit|}  static
name|__inline__
name|void
name|drm_core_dropmap
parameter_list|(
name|struct
name|drm_map
modifier|*
name|map
parameter_list|)
block|{ }
end_function

begin_define
define|#
directive|define
name|DRM_PCIE_SPEED_25
value|1
end_define

begin_define
define|#
directive|define
name|DRM_PCIE_SPEED_50
value|2
end_define

begin_define
define|#
directive|define
name|DRM_PCIE_SPEED_80
value|4
end_define

begin_function_decl
specifier|extern
name|int
name|drm_pcie_get_speed_cap_mask
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|u32
modifier|*
name|speed_mask
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|drm_can_sleep
parameter_list|()
value|(DRM_HZ& 1)
end_define

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

