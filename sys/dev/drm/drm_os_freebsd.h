begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
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
file|<sys/lockmgr.h>
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
file|<machine/pmap.h>
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
file|<sys/selinfo.h>
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

begin_define
define|#
directive|define
name|__REALLY_HAVE_MTRR
value|0
end_define

begin_define
define|#
directive|define
name|__REALLY_HAVE_SG
value|0
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allow setting of debug code enabling from kernel config file */
end_comment

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
name|DRM_OS_SPINTYPE
value|struct mtx
end_define

begin_define
define|#
directive|define
name|DRM_OS_SPININIT
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
name|DRM_OS_SPINLOCK
parameter_list|(
name|l
parameter_list|)
value|mtx_lock(l)
end_define

begin_define
define|#
directive|define
name|DRM_OS_SPINUNLOCK
parameter_list|(
name|u
parameter_list|)
value|mtx_unlock(u);
end_define

begin_define
define|#
directive|define
name|DRM_OS_CURPROC
value|curthread
end_define

begin_define
define|#
directive|define
name|DRM_OS_STRUCTPROC
value|struct thread
end_define

begin_define
define|#
directive|define
name|DRM_OS_CURRENTPID
value|curthread->td_proc->p_pid
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DRM_OS_CURPROC
value|curproc
end_define

begin_define
define|#
directive|define
name|DRM_OS_STRUCTPROC
value|struct proc
end_define

begin_define
define|#
directive|define
name|DRM_OS_SPINTYPE
value|struct simplelock
end_define

begin_define
define|#
directive|define
name|DRM_OS_SPININIT
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
name|DRM_OS_SPINLOCK
parameter_list|(
name|l
parameter_list|)
value|simple_lock(l)
end_define

begin_define
define|#
directive|define
name|DRM_OS_SPINUNLOCK
parameter_list|(
name|u
parameter_list|)
value|simple_unlock(u);
end_define

begin_define
define|#
directive|define
name|DRM_OS_CURRENTPID
value|curproc->p_pid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DRM_OS_IOCTL
value|dev_t kdev, u_long cmd, caddr_t data, int flags, DRM_OS_STRUCTPROC *p
end_define

begin_define
define|#
directive|define
name|IOCTL_ARGS_PASS
value|kdev, cmd, data, flags, p
end_define

begin_define
define|#
directive|define
name|DRM_OS_LOCK
value|lockmgr(&dev->dev_lock, LK_EXCLUSIVE, 0, DRM_OS_CURPROC)
end_define

begin_define
define|#
directive|define
name|DRM_OS_UNLOCK
value|lockmgr(&dev->dev_lock, LK_RELEASE, 0, DRM_OS_CURPROC)
end_define

begin_define
define|#
directive|define
name|DRM_OS_CHECKSUSER
value|suser(p)
end_define

begin_define
define|#
directive|define
name|DRM_OS_TASKQUEUE_ARGS
value|void *dev, int pending
end_define

begin_define
define|#
directive|define
name|DRM_OS_IRQ_ARGS
value|void *device
end_define

begin_define
define|#
directive|define
name|DRM_OS_DEVICE
value|drm_device_t	*dev	= kdev->si_drv1
end_define

begin_define
define|#
directive|define
name|DRM_OS_MALLOC
parameter_list|(
name|size
parameter_list|)
value|malloc( size, DRM(M_DRM), M_NOWAIT )
end_define

begin_define
define|#
directive|define
name|DRM_OS_FREE
parameter_list|(
name|pt
parameter_list|)
value|free( pt, DRM(M_DRM) )
end_define

begin_define
define|#
directive|define
name|DRM_OS_VTOPHYS
parameter_list|(
name|addr
parameter_list|)
value|vtophys(addr)
end_define

begin_define
define|#
directive|define
name|DRM_OS_PRIV
define|\
value|drm_file_t	*priv	= (drm_file_t *) DRM(find_file_by_proc)(dev, p); \ 	if (!priv) {						\ 		DRM_DEBUG("can't find authenticator\n");	\ 		return EINVAL;					\ 	}
end_define

begin_define
define|#
directive|define
name|DRM_OS_DELAY
parameter_list|(
name|udelay
parameter_list|)
define|\
value|do {								\ 	struct timeval tv1, tv2;				\ 	microtime(&tv1);					\ 	do {							\ 		microtime(&tv2);				\ 	}							\ 	while (((tv2.tv_sec-tv1.tv_sec)*1000000 + tv2.tv_usec - tv1.tv_usec)< udelay ); \ } while (0)
end_define

begin_define
define|#
directive|define
name|DRM_OS_ERR
parameter_list|(
name|v
parameter_list|)
value|v
end_define

begin_define
define|#
directive|define
name|DRM_OS_KRNTOUSR
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
name|DRM_OS_KRNFROMUSR
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
name|DRM_OS_COPYTOUSR
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
name|DRM_OS_COPYFROMUSR
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
name|DRM_OS_READMEMORYBARRIER
define|\
value|{												\    	int xchangeDummy;									\ 	DRM_DEBUG("%s\n", __func__);							\    	__asm__ volatile(" push %%eax ; xchg %%eax, %0 ; pop %%eax" : : "m" (xchangeDummy));	\    	__asm__ volatile(" push %%eax ; push %%ebx ; push %%ecx ; push %%edx ;"			\ 			 " movl $0,%%eax ; cpuid ; pop %%edx ; pop %%ecx ; pop %%ebx ;"		\ 			 " pop %%eax" :
comment|/* no outputs */
value|:
comment|/* no inputs */
value|);			\ } while (0);
end_define

begin_define
define|#
directive|define
name|DRM_OS_WRITEMEMORYBARRIER
value|DRM_OS_READMEMORYBARRIER
end_define

begin_define
define|#
directive|define
name|DRM_OS_WAKEUP
parameter_list|(
name|w
parameter_list|)
value|wakeup(w)
end_define

begin_define
define|#
directive|define
name|DRM_OS_WAKEUP_INT
parameter_list|(
name|w
parameter_list|)
value|wakeup(w)
end_define

begin_define
define|#
directive|define
name|PAGE_ALIGN
parameter_list|(
name|addr
parameter_list|)
value|(((addr)+PAGE_SIZE-1)&PAGE_MASK)
end_define

begin_define
define|#
directive|define
name|malloctype
value|DRM(M_DRM)
end_define

begin_comment
comment|/* The macros confliced in the MALLOC_DEFINE */
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

begin_typedef
typedef|typedef
name|unsigned
name|long
name|atomic_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|cycles_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|spinlock_t
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
value|atomic_add_long(p, 1)
end_define

begin_define
define|#
directive|define
name|atomic_dec
parameter_list|(
name|p
parameter_list|)
value|atomic_subtract_long(p, 1)
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
value|atomic_add_long(p, n)
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
value|atomic_subtract_long(p, n)
end_define

begin_comment
comment|/* Fake this */
end_comment

begin_function
specifier|static
name|__inline
name|unsigned
name|int
name|test_and_set_bit
parameter_list|(
name|int
name|b
parameter_list|,
specifier|volatile
name|unsigned
name|long
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
name|p
operator|&
name|m
decl_stmt|;
operator|*
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
name|unsigned
name|long
modifier|*
name|p
parameter_list|)
block|{
name|atomic_clear_long
argument_list|(
name|p
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
name|unsigned
name|long
modifier|*
name|p
parameter_list|)
block|{
name|atomic_set_long
argument_list|(
name|p
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
name|unsigned
name|long
modifier|*
name|p
parameter_list|)
block|{
return|return
name|p
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
name|unsigned
name|long
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
name|p
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
name|p
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

begin_define
define|#
directive|define
name|memset
parameter_list|(
name|p
parameter_list|,
name|v
parameter_list|,
name|s
parameter_list|)
value|bzero(p, s)
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

begin_comment
comment|/* FIXME: again, what's the exact date? */
end_comment

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

begin_define
define|#
directive|define
name|__drm_dummy_lock
parameter_list|(
name|lock
parameter_list|)
value|(*(__volatile__ unsigned int *)lock)
end_define

begin_define
define|#
directive|define
name|_DRM_CAS
parameter_list|(
name|lock
parameter_list|,
name|old
parameter_list|,
name|new
parameter_list|,
name|__ret
parameter_list|)
define|\
value|do {							       \ 		int __dummy;
comment|/* Can't mark eax as clobbered */
value|\ 		__asm__ __volatile__(				       \ 			"lock ; cmpxchg %4,%1\n\t"		       \ 			"setnz %0"				       \ 			: "=d" (__ret),				       \ 			  "=m" (__drm_dummy_lock(lock)),	       \ 			  "=a" (__dummy)			       \ 			: "2" (old),				       \ 			  "r" (new));				       \ 	} while (0)
end_define

begin_comment
comment|/* Redefinitions to make templating easy */
end_comment

begin_define
define|#
directive|define
name|wait_queue_head_t
value|long
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
value|printf("error: [" DRM_NAME ":%s] *ERROR* " fmt , \ 		__func__, ##arg)
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
value|printf("error: [" DRM_NAME ":%s:%s] *ERROR* " fmt , \ 	       __func__, DRM(mem_stats)[area].name , ##arg)
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
value|printf("info: " "[" DRM_NAME "] " fmt , ##arg)
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
value|do {								\ 		if (DRM(flags)& DRM_FLAG_DEBUG)			\ 			printf("[" DRM_NAME ":%s] " fmt , 		\ 				__func__, ##arg);			\ 	} while (0)
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

begin_define
define|#
directive|define
name|DRM_PROC_LIMIT
value|(PAGE_SIZE-80)
end_define

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
value|snprintf(buf, sizeof(buf), fmt, ##arg);	\   error = SYSCTL_OUT(req, buf, strlen(buf));	\   if (error) return error;
end_define

begin_define
define|#
directive|define
name|DRM_SYSCTL_PRINT_RET
parameter_list|(
name|ret
parameter_list|,
name|fmt
parameter_list|,
name|arg
modifier|...
parameter_list|)
define|\
value|snprintf(buf, sizeof(buf), fmt, ##arg);	\   error = SYSCTL_OUT(req, buf, strlen(buf));	\   if (error) { ret; return error; }
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
name|d_write_t
name|DRM
parameter_list|(
name|write
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
name|DRM_OS_STRUCTPROC
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
name|DRM_OS_STRUCTPROC
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Memory management support (drm_memory.h) */
end_comment

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

begin_comment
comment|/* SysCtl Support (drm_sysctl.h) */
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

end_unit

