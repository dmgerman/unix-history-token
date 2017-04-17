begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* drmP.h -- Private header for Direct Rendering Manager -*- linux-c -*-  * Created: Mon Jan  4 10:05:05 1999 by faith@precisioninsight.com  */
end_comment

begin_comment
comment|/*-  * Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All rights reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Rickard E. (Rik) Faith<faith@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *  */
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

begin_struct_decl
struct_decl|struct
name|drm_device
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|drm_file
struct_decl|;
end_struct_decl

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
file|<sys/rwlock.h>
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
file|<sys/vmmeter.h>
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

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|__BIG_ENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

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
file|"dev/drm/drm.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_atomic.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_internal.h"
end_include

begin_include
include|#
directive|include
file|"dev/drm/drm_linux_list.h"
end_include

begin_include
include|#
directive|include
file|<opt_drm.h>
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DRM_LINUX
argument_list|)
operator|&&
name|DRM_LINUX
operator|&&
operator|!
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<machine/../linux/linux.h>
end_include

begin_include
include|#
directive|include
file|<machine/../linux/linux_proto.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Either it was defined when it shouldn't be (FreeBSD amd64) or it isn't  * supported on this OS yet.  */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

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
name|DRIVER_DMA_QUEUE
value|0x100
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
value|UID_ROOT
end_define

begin_define
define|#
directive|define
name|DRM_DEV_GID
value|GID_VIDEO
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
parameter_list|()
value|mtx_lock(&dev->dev_lock)
end_define

begin_define
define|#
directive|define
name|DRM_UNLOCK
parameter_list|()
value|mtx_unlock(&dev->dev_lock)
end_define

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

begin_define
define|#
directive|define
name|unlikely
parameter_list|(
name|x
parameter_list|)
value|__builtin_expect(!!(x), 0)
end_define

begin_define
define|#
directive|define
name|container_of
parameter_list|(
name|ptr
parameter_list|,
name|type
parameter_list|,
name|member
parameter_list|)
value|({			\ 	__typeof( ((type *)0)->member ) *__mptr = (ptr);	\ 	(type *)( (char *)__mptr - offsetof(type,member) );})
end_define

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

begin_typedef
typedef|typedef
name|vm_paddr_t
name|dma_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int64_t
name|u64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int8_t
name|u8
typedef|;
end_typedef

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
name|cpu_to_le32
parameter_list|(
name|x
parameter_list|)
value|htole32(x)
end_define

begin_define
define|#
directive|define
name|le32_to_cpu
parameter_list|(
name|x
parameter_list|)
value|le32toh(x)
end_define

begin_define
define|#
directive|define
name|DRM_HZ
value|hz
end_define

begin_define
define|#
directive|define
name|DRM_UDELAY
parameter_list|(
name|udelay
parameter_list|)
value|DELAY(udelay)
end_define

begin_define
define|#
directive|define
name|DRM_TIME_SLICE
value|(hz/20)
end_define

begin_comment
comment|/* Time slice for GLXContexts	  */
end_comment

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
value|for ( ret = 0 ; !ret&& !(condition) ; ) {			\ 	DRM_UNLOCK();						\ 	mtx_lock(&dev->irq_lock);				\ 	if (!(condition))					\ 	    ret = -mtx_sleep(&(queue),&dev->irq_lock, 		\ 		PCATCH, "drmwtq", (timeout));			\ 	mtx_unlock(&dev->irq_lock);				\ 	DRM_LOCK();						\ }
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
value|do {					\ 	if (drm_debug_flag)						\ 		printf("[" DRM_NAME ":pid%d:%s] " fmt, DRM_CURRENTPID,	\ 			__func__ , ##__VA_ARGS__);			\ } while (0)
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
name|struct
name|drm_file
modifier|*
name|file_priv
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
name|drm_pci_id_list_t
modifier|*
name|id_entry
decl_stmt|;
comment|/* PCI ID, name, and chipset private */
comment|/** 	 * Called by \c drm_device_is_agp.  Typically used to determine if a 	 * card is really attached to AGP or not. 	 * 	 * \param dev  DRM device handle 	 * 	 * \returns  	 * One of three values is returned depending on whether or not the 	 * card is absolutely \b not AGP (return of 0), absolutely \b is AGP 	 * (return of 1), or may or may not be AGP (return of 2). 	 */
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
comment|/* Length for the array of resource pointers for drm_get_resource_*. */
end_comment

begin_define
define|#
directive|define
name|DRM_MAX_PCI_RESOURCE
value|6
end_define

begin_comment
comment|/**   * DRM device functions structure  */
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
name|u_int16_t
name|pci_device
decl_stmt|;
comment|/* PCI device id */
name|u_int16_t
name|pci_vendor
decl_stmt|;
comment|/* PCI vendor id */
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
name|vbl_lock
decl_stmt|;
comment|/* protects vblank operations */
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
name|vblank_disable_allowed
decl_stmt|;
name|struct
name|callout
name|vblank_disable_timer
decl_stmt|;
name|u32
name|max_vblank_count
decl_stmt|;
comment|/* size of vblank counter register */
name|struct
name|drm_vblank_info
modifier|*
name|vblank
decl_stmt|;
comment|/* per crtc vblank info */
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
name|drm_agp_head_t
modifier|*
name|agp
decl_stmt|;
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
name|unsigned
name|int
name|agp_buffer_token
decl_stmt|;
name|drm_local_map_t
modifier|*
name|agp_buffer_map
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
block|}
struct|;
end_struct

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

begin_decl_stmt
specifier|extern
name|int
name|drm_debug_flag
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

begin_function_decl
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
name|DRM_SPINLOCK_ASSERT
argument_list|(
operator|&
name|dev
operator|->
name|dev_lock
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

