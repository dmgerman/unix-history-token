begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file drm_os_freebsd.h  * OS-specific #defines for FreeBSD  *   * \author Eric Anholt<anholt@FreeBSD.org>  */
end_comment

begin_comment
comment|/*  * Copyright 2003 Eric Anholt  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

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
file|<sys/stat.h>
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
file|<vm/vm_map.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
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

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
end_if

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<sys/selinfo.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|400005
end_if

begin_include
include|#
directive|include
file|<sys/taskqueue.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
end_if

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|400006
end_if

begin_define
define|#
directive|define
name|__REALLY_HAVE_AGP
value|__HAVE_AGP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_define
define|#
directive|define
name|__REALLY_HAVE_MTRR
value|(__HAVE_MTRR)&& (__FreeBSD_version>= 500000)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__REALLY_HAVE_MTRR
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|__REALLY_HAVE_SG
value|(__HAVE_SG)
end_define

begin_if
if|#
directive|if
name|__REALLY_HAVE_AGP
end_if

begin_include
include|#
directive|include
file|<pci/agpvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/agpio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<opt_drm.h>
end_include

begin_if
if|#
directive|if
name|DRM_DEBUG
end_if

begin_undef
undef|#
directive|undef
name|DRM_DEBUG_CODE
end_undef

begin_define
define|#
directive|define
name|DRM_DEBUG_CODE
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|DRM_DEBUG
end_undef

begin_if
if|#
directive|if
name|DRM_LINUX
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

begin_endif
endif|#
directive|endif
end_endif

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
name|CDEV_MAJOR
value|145
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500000
end_if

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
value|mtx_init(&l, name, NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|DRM_SPINUNINIT
parameter_list|(
name|l
parameter_list|)
value|mtx_destroy(&l)
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
value|mtx_unlock(u);
end_define

begin_define
define|#
directive|define
name|DRM_CURRENTPID
value|curthread->td_proc->p_pid
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DRM_CURPROC
value|curproc
end_define

begin_define
define|#
directive|define
name|DRM_STRUCTPROC
value|struct proc
end_define

begin_define
define|#
directive|define
name|DRM_SPINTYPE
value|struct simplelock
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
value|simple_lock_init(&l)
end_define

begin_define
define|#
directive|define
name|DRM_SPINUNINIT
parameter_list|(
name|l
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DRM_SPINLOCK
parameter_list|(
name|l
parameter_list|)
value|simple_lock(l)
end_define

begin_define
define|#
directive|define
name|DRM_SPINUNLOCK
parameter_list|(
name|u
parameter_list|)
value|simple_unlock(u);
end_define

begin_define
define|#
directive|define
name|DRM_CURRENTPID
value|curproc->p_pid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Currently our DRMFILE (filp) is a void * which is actually the pid  * of the current process.  It should be a per-open unique pointer, but  * code for that is not yet written */
end_comment

begin_define
define|#
directive|define
name|DRMFILE
value|void *
end_define

begin_define
define|#
directive|define
name|DRM_IOCTL_ARGS
value|dev_t kdev, u_long cmd, caddr_t data, int flags, DRM_STRUCTPROC *p, DRMFILE filp
end_define

begin_define
define|#
directive|define
name|DRM_LOCK
value|lockmgr(&dev->dev_lock, LK_EXCLUSIVE, 0, DRM_CURPROC)
end_define

begin_define
define|#
directive|define
name|DRM_UNLOCK
value|lockmgr(&dev->dev_lock, LK_RELEASE, 0, DRM_CURPROC)
end_define

begin_define
define|#
directive|define
name|DRM_SUSER
parameter_list|(
name|p
parameter_list|)
value|suser(p)
end_define

begin_define
define|#
directive|define
name|DRM_TASKQUEUE_ARGS
value|void *arg, int pending
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
name|DRM_DEVICE
value|drm_device_t	*dev	= kdev->si_drv1
end_define

begin_define
define|#
directive|define
name|DRM_MALLOC
parameter_list|(
name|size
parameter_list|)
value|malloc( size, DRM(M_DRM), M_NOWAIT )
end_define

begin_define
define|#
directive|define
name|DRM_FREE
parameter_list|(
name|pt
parameter_list|,
name|size
parameter_list|)
value|free( pt, DRM(M_DRM) )
end_define

begin_comment
comment|/* Read/write from bus space, with byteswapping to le if necessary */
end_comment

begin_define
define|#
directive|define
name|DRM_READ8
parameter_list|(
name|map
parameter_list|,
name|offset
parameter_list|)
value|*(volatile u_int8_t *) (((unsigned long)(map)->handle) + (offset))
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
value|*(volatile u_int32_t *)(((unsigned long)(map)->handle) + (offset))
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
value|*(volatile u_int8_t *) (((unsigned long)(map)->handle) + (offset)) = val
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
value|*(volatile u_int32_t *)(((unsigned long)(map)->handle) + (offset)) = val
end_define

begin_comment
comment|/* #define DRM_READ8(map, offset)		bus_space_read_1(  (map)->iot, (map)->ioh, (offset) ) #define DRM_READ32(map, offset)		bus_space_read_4(  (map)->iot, (map)->ioh, (offset) ) #define DRM_WRITE8(map, offset, val)	bus_space_write_1( (map)->iot, (map)->ioh, (offset), (val) ) #define DRM_WRITE32(map, offset, val)	bus_space_write_4( (map)->iot, (map)->ioh, (offset), (val) ) */
end_comment

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
name|DRM_ERR
parameter_list|(
name|v
parameter_list|)
value|v
end_define

begin_define
define|#
directive|define
name|DRM_PRIV
define|\
value|drm_file_t	*priv	= (drm_file_t *) DRM(find_file_by_proc)(dev, p); \ 	if (!priv) {						\ 		DRM_DEBUG("can't find authenticator\n");	\ 		return EINVAL;					\ 	}
end_define

begin_define
define|#
directive|define
name|LOCK_TEST_WITH_RETURN
parameter_list|(
name|dev
parameter_list|,
name|filp
parameter_list|)
define|\
value|do {									\ 	if (!_DRM_LOCK_IS_HELD(dev->lock.hw_lock->lock) ||		\ 	     dev->lock.filp != filp) {					\ 		DRM_ERROR("%s called without lock held\n",		\ 			   __FUNCTION__);				\ 		return EINVAL;						\ 	}								\ } while (0)
end_define

begin_define
define|#
directive|define
name|DRM_UDELAY
parameter_list|(
name|udelay
parameter_list|)
define|\
value|do {								\ 	struct timeval tv1, tv2;				\ 	microtime(&tv1);					\ 	do {							\ 		microtime(&tv2);				\ 	}							\ 	while (((tv2.tv_sec-tv1.tv_sec)*1000000 + tv2.tv_usec - tv1.tv_usec)< udelay ); \ } while (0)
end_define

begin_define
define|#
directive|define
name|DRM_GETSAREA
parameter_list|()
define|\
value|do {								\ 	drm_map_list_entry_t *listentry;			\ 	TAILQ_FOREACH(listentry, dev->maplist, link) {		\ 		drm_local_map_t *map = listentry->map;		\ 		if (map->type == _DRM_SHM&&			\ 			map->flags& _DRM_CONTAINS_LOCK) {	\ 			dev_priv->sarea = map;			\ 			break;					\ 		}						\ 	}							\ } while (0)
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
value|while (!condition) {							\ 	ret = tsleep(&(queue), PZERO | PCATCH, "drmwtq", (timeout) );	\ 	if ( ret )							\ 		return ret;						\ }
end_define

begin_define
define|#
directive|define
name|DRM_WAKEUP
parameter_list|(
name|queue
parameter_list|)
value|wakeup( queue )
end_define

begin_define
define|#
directive|define
name|DRM_WAKEUP_INT
parameter_list|(
name|queue
parameter_list|)
value|wakeup( queue )
end_define

begin_define
define|#
directive|define
name|DRM_INIT_WAITQUEUE
parameter_list|(
name|queue
parameter_list|)
value|do {} while (0)
end_define

begin_define
define|#
directive|define
name|DRM_COPY_TO_USER_IOCTL
parameter_list|(
name|user
parameter_list|,
name|kern
parameter_list|,
name|size
parameter_list|)
define|\
value|if ( IOCPARM_LEN(cmd) != size)			\ 		return EINVAL;				\ 	*user = kern;
end_define

begin_define
define|#
directive|define
name|DRM_COPY_FROM_USER_IOCTL
parameter_list|(
name|kern
parameter_list|,
name|user
parameter_list|,
name|size
parameter_list|)
define|\
value|if ( IOCPARM_LEN(cmd) != size)			\ 		return EINVAL;				\ 	kern = *user;
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

begin_comment
comment|/* Macros for userspace access with checking readability once */
end_comment

begin_comment
comment|/* FIXME: can't find equivalent functionality for nocheck yet.  * It'll be slower than linux, but should be correct.  */
end_comment

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
value|(!useracc((caddr_t)uaddr, size, VM_PROT_READ))
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
name|DRM_GET_USER_UNCHECKED
parameter_list|(
name|val
parameter_list|,
name|uaddr
parameter_list|)
define|\
value|((val) = fuword(uaddr), 0)
end_define

begin_comment
comment|/* DRM_READMEMORYBARRIER() prevents reordering of reads.  * DRM_WRITEMEMORYBARRIER() prevents reordering of writes.  * DRM_MEMORYBARRIER() prevents reordering of reads and writes.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_define
define|#
directive|define
name|DRM_READMEMORYBARRIER
parameter_list|()
value|__asm __volatile( \ 					"lock; addl $0,0(%%esp)" : : : "memory");
end_define

begin_define
define|#
directive|define
name|DRM_WRITEMEMORYBARRIER
parameter_list|()
value|__asm __volatile("" : : : "memory");
end_define

begin_define
define|#
directive|define
name|DRM_MEMORYBARRIER
parameter_list|()
value|__asm __volatile( \ 					"lock; addl $0,0(%%esp)" : : : "memory");
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|DRM_READMEMORYBARRIER
parameter_list|()
value|alpha_mb();
end_define

begin_define
define|#
directive|define
name|DRM_WRITEMEMORYBARRIER
parameter_list|()
value|alpha_wmb();
end_define

begin_define
define|#
directive|define
name|DRM_MEMORYBARRIER
parameter_list|()
value|alpha_mb();
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PAGE_ALIGN
parameter_list|(
name|addr
parameter_list|)
value|round_page(addr)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|M_WAITOK
end_ifndef

begin_comment
comment|/* M_WAITOK (=0) name removed in -current */
end_comment

begin_define
define|#
directive|define
name|M_WAITOK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|malloctype
value|DRM(M_DRM)
end_define

begin_comment
comment|/* The macros conflicted in the MALLOC_DEFINE */
end_comment

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|malloctype
argument_list|)
expr_stmt|;
end_expr_stmt

begin_undef
undef|#
directive|undef
name|malloctype
end_undef

begin_typedef
typedef|typedef
struct|struct
name|drm_chipinfo
block|{
name|int
name|vendor
decl_stmt|;
name|int
name|device
decl_stmt|;
name|int
name|supported
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
block|}
name|drm_chipinfo_t
typedef|;
end_typedef

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

begin_typedef
typedef|typedef
name|unsigned
name|long
name|dma_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|atomic_t
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

begin_define
define|#
directive|define
name|atomic_set
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|)
value|(*(p) = (v))
end_define

begin_define
define|#
directive|define
name|atomic_read
parameter_list|(
name|p
parameter_list|)
value|(*(p))
end_define

begin_define
define|#
directive|define
name|atomic_inc
parameter_list|(
name|p
parameter_list|)
value|atomic_add_int(p, 1)
end_define

begin_define
define|#
directive|define
name|atomic_dec
parameter_list|(
name|p
parameter_list|)
value|atomic_subtract_int(p, 1)
end_define

begin_define
define|#
directive|define
name|atomic_add
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|atomic_add_int(p, n)
end_define

begin_define
define|#
directive|define
name|atomic_sub
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|atomic_subtract_int(p, n)
end_define

begin_comment
comment|/* Fake this */
end_comment

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|500000
end_if

begin_comment
comment|/* The extra atomic functions from 5.0 haven't been merged to 4.x */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|atomic_cmpset_int
parameter_list|(
specifier|volatile
name|u_int
modifier|*
name|dst
parameter_list|,
name|u_int
name|exp
parameter_list|,
name|u_int
name|src
parameter_list|)
block|{
name|int
name|res
init|=
name|exp
decl_stmt|;
asm|__asm __volatile (
literal|"	lock ;			"
literal|"	cmpxchgl %1,%2 ;	"
literal|"       setz	%%al ;		"
literal|"	movzbl	%%al,%0 ;	"
literal|"1:				"
literal|"# atomic_cmpset_int"
operator|:
literal|"+a"
operator|(
name|res
operator|)
comment|/* 0 (result) */
operator|:
literal|"r"
operator|(
name|src
operator|)
operator|,
comment|/* 1 */
literal|"m"
operator|(
operator|*
operator|(
name|dst
operator|)
operator|)
comment|/* 2 */
operator|:
literal|"memory"
block|)
function|;
end_function

begin_return
return|return
operator|(
name|res
operator|)
return|;
end_return

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_function
unit|static
name|__inline
name|atomic_t
name|test_and_set_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
name|int
name|s
init|=
name|splhigh
argument_list|()
decl_stmt|;
name|unsigned
name|int
name|m
init|=
literal|1
operator|<<
name|b
decl_stmt|;
name|unsigned
name|int
name|r
init|=
operator|*
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|&
name|m
decl_stmt|;
operator|*
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator||=
name|m
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
return|return
name|r
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|clear_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
name|atomic_clear_int
argument_list|(
operator|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|)
operator|+
operator|(
name|b
operator|>>
literal|5
operator|)
argument_list|,
literal|1
operator|<<
operator|(
name|b
operator|&
literal|0x1f
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|set_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
name|atomic_set_int
argument_list|(
operator|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|)
operator|+
operator|(
name|b
operator|>>
literal|5
operator|)
argument_list|,
literal|1
operator|<<
operator|(
name|b
operator|&
literal|0x1f
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|test_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|void
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|)
index|[
name|b
operator|>>
literal|5
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|b
operator|&
literal|0x1f
operator|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|find_first_zero_bit
parameter_list|(
specifier|volatile
name|void
modifier|*
name|p
parameter_list|,
name|int
name|max
parameter_list|)
block|{
name|int
name|b
decl_stmt|;
for|for
control|(
name|b
operator|=
literal|0
init|;
name|b
operator|<
name|max
condition|;
name|b
operator|+=
literal|32
control|)
block|{
if|if
condition|(
operator|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|)
index|[
name|b
operator|>>
literal|5
index|]
operator|!=
operator|~
literal|0
condition|)
block|{
for|for
control|(
init|;
condition|;
control|)
block|{
if|if
condition|(
operator|(
operator|(
operator|(
specifier|volatile
name|int
operator|*
operator|)
name|p
operator|)
index|[
name|b
operator|>>
literal|5
index|]
operator|&
operator|(
literal|1
operator|<<
operator|(
name|b
operator|&
literal|0x1f
operator|)
operator|)
operator|)
operator|==
literal|0
condition|)
return|return
name|b
return|;
name|b
operator|++
expr_stmt|;
block|}
block|}
block|}
return|return
name|max
return|;
block|}
end_function

begin_define
define|#
directive|define
name|spldrm
parameter_list|()
value|spltty()
end_define

begin_comment
comment|/*  * Fake out the module macros for versions of FreeBSD where they don't  * exist.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|<
literal|500002
operator|&&
name|__FreeBSD_version
operator|>
literal|500000
operator|)
operator|||
name|__FreeBSD_version
operator|<
literal|420000
end_if

begin_define
define|#
directive|define
name|MODULE_VERSION
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|struct __hack
end_define

begin_define
define|#
directive|define
name|MODULE_DEPEND
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|struct __hack
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Redefinitions to make templating easy */
end_comment

begin_define
define|#
directive|define
name|wait_queue_head_t
value|atomic_t
end_define

begin_define
define|#
directive|define
name|agp_memory
value|void
end_define

begin_define
define|#
directive|define
name|jiffies
value|ticks
end_define

begin_comment
comment|/* Macros to make printf easier */
end_comment

begin_define
define|#
directive|define
name|DRM_ERROR
parameter_list|(
name|fmt
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|printf("error: " "[" DRM_NAME ":%s] *ERROR* " fmt , __func__ , ## arg)
end_define

begin_define
define|#
directive|define
name|DRM_MEM_ERROR
parameter_list|(
name|area
parameter_list|,
name|fmt
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|printf("error: " "[" DRM_NAME ":%s:%s] *ERROR* " fmt , \ 		__func__, DRM(mem_stats)[area].name , ##arg)
end_define

begin_define
define|#
directive|define
name|DRM_INFO
parameter_list|(
name|fmt
parameter_list|,
name|arg
modifier|...
parameter_list|)
value|printf("info: " "[" DRM_NAME "] " fmt , ## arg)
end_define

begin_if
if|#
directive|if
name|DRM_DEBUG_CODE
end_if

begin_define
define|#
directive|define
name|DRM_DEBUG
parameter_list|(
name|fmt
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|do {								  \ 		if (DRM(flags)& DRM_FLAG_DEBUG)			  \ 			printf("[" DRM_NAME ":%s] " fmt , __func__ , ## arg); \ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DRM_DEBUG
parameter_list|(
name|fmt
parameter_list|,
name|arg
modifier|...
parameter_list|)
value|do { } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|__FreeBSD_version
operator|>=
literal|500000
operator|)
operator|||
operator|(
operator|(
name|__FreeBSD_version
operator|<
literal|500000
operator|)
operator|&&
operator|(
name|__FreeBSD_version
operator|>=
literal|410002
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|DRM_SYSCTL_HANDLER_ARGS
value|(SYSCTL_HANDLER_ARGS)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DRM_SYSCTL_HANDLER_ARGS
value|SYSCTL_HANDLER_ARGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DRM_SYSCTL_PRINT
parameter_list|(
name|fmt
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|do {						\   snprintf(buf, sizeof(buf), fmt, ##arg);	\   error = SYSCTL_OUT(req, buf, strlen(buf));	\   if (error) return error;			\ } while (0)
end_define

begin_define
define|#
directive|define
name|DRM_FIND_MAP
parameter_list|(
name|dest
parameter_list|,
name|o
parameter_list|)
define|\
value|do {								\ 		drm_map_list_entry_t *listentry;			\ 		TAILQ_FOREACH(listentry, dev->maplist, link) {		\ 			if ( listentry->map->offset == o ) {		\ 				dest = listentry->map;			\ 				break;					\ 			}						\ 		}							\ 	} while (0)
end_define

begin_comment
comment|/* Internal functions */
end_comment

begin_comment
comment|/* drm_drv.h */
end_comment

begin_function_decl
specifier|extern
name|d_ioctl_t
name|DRM
parameter_list|(
name|ioctl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|d_open_t
name|DRM
parameter_list|(
name|open
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|d_close_t
name|DRM
parameter_list|(
name|close
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|d_read_t
name|DRM
parameter_list|(
name|read
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|d_poll_t
name|DRM
parameter_list|(
name|poll
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|d_mmap_t
name|DRM
parameter_list|(
name|mmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|open_helper
function_decl|)
parameter_list|(
name|dev_t
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
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|drm_file_t
modifier|*
name|DRM
function_decl|(
name|find_file_by_proc
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|DRM_STRUCTPROC
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* sysctl support (drm_sysctl.h) */
end_comment

begin_function_decl
specifier|extern
name|int
name|DRM
function_decl|(
name|sysctl_init
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
name|sysctl_cleanup
function_decl|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Memory info sysctl (drm_memory_debug.h) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG_MEMORY
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|DRM
argument_list|(
name|mem_info
argument_list|)
name|DRM_SYSCTL_HANDLER_ARGS
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

