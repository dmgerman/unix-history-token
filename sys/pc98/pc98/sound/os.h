begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_OS_H_
end_ifndef

begin_define
define|#
directive|define
name|_OS_H_
end_define

begin_comment
comment|/*  * OS specific settings for FreeBSD  *  * This chould be used as an example when porting the driver to a new  * operating systems.  *  * What you should do is to rewrite the soundcard.c and os.h (this file).  * You should create a new subdirectory and put these two files there.  * In addition you have to do a makefile.<OS>.  *  * If you have to make changes to other than these two files, please contact me  * before making the changes. It's possible that I have already made the  * change.   */
end_comment

begin_comment
comment|/*  * Insert here the includes required by your kernel.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/syslog.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/buf.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_if
if|#
directive|if
name|NSND
operator|>
literal|0
end_if

begin_define
define|#
directive|define
name|CONFIGURE_SOUNDCARD
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|CONFIGURED_SOUNDCARD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Rest of the file is compiled only if the driver is really required.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIGURE_SOUNDCARD
end_ifdef

begin_comment
comment|/*   * select() is currently implemented in Linux specific way. Don't enable.  * I don't remember what the SHORT_BANNERS means so forget it.  */
end_comment

begin_comment
comment|/*#undef ALLOW_SELECT*/
end_comment

begin_define
define|#
directive|define
name|SHORT_BANNERS
end_define

begin_comment
comment|/* The soundcard.h could be in a nonstandard place so inclyde it here. */
end_comment

begin_include
include|#
directive|include
file|<machine/soundcard.h>
end_include

begin_comment
comment|/*  * Here is the first portability problem. Every OS has it's own way to  * pass a pointer to the buffer in read() and write() calls. In Linux it's  * just a char*. In BSD it's struct uio. This parameter is passed to  * all functions called from read() or write(). Since nothing can be   * assumed about this structure, the driver uses set of macros for  * accessing the user buffer.   *  * The driver reads/writes bytes in the user buffer sequentially which  * means that calls like uiomove() can be used.  *  * snd_rw_buf is the type which is passed to the device file specific  * read() and write() calls.  *   * The following macros are used to move date to and from the  * user buffer. These macros should be used only when the   * target or source parameter has snd_rw_buf type.  * The offs parameter is a offset relative to the beginning of  * the user buffer. In Linux the offset is required but for example  * BSD passes the offset info in the uio structure. It could be usefull  * if these macros verify that the offs parameter and the value in  * the snd_rw_buf structure are equal.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|uio
name|snd_rw_buf
typedef|;
end_typedef

begin_comment
comment|/*  * Move bytes from the buffer which the application given in a  * write() call.  * offs is position relative to the beginning of the buffer in  * user space. The count is number of bytes to be moved.  */
end_comment

begin_define
define|#
directive|define
name|COPY_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|source
parameter_list|,
name|offs
parameter_list|,
name|count
parameter_list|)
define|\
value|do { if (uiomove((caddr_t ) target, count, (struct uio *)source)) { \ 		printf ("sb: Bad copyin()!\n"); \ 	} } while(0)
end_define

begin_comment
comment|/* Like COPY_FOM_USER but for writes. */
end_comment

begin_define
define|#
directive|define
name|COPY_TO_USER
parameter_list|(
name|target
parameter_list|,
name|offs
parameter_list|,
name|source
parameter_list|,
name|count
parameter_list|)
define|\
value|do { if (uiomove(source, count, (struct uio *)target)) { \ 		printf ("sb: Bad copyout()!\n"); \ 	} } while(0)
end_define

begin_comment
comment|/*   * The following macros are like COPY_*_USER but work just with one byte (8bit),  * short (16 bit) or long (32 bit) at a time.  * The same restrictions apply than for COPY_*_USER  */
end_comment

begin_define
define|#
directive|define
name|GET_BYTE_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|addr
parameter_list|,
name|offs
parameter_list|)
value|{uiomove((char*)&(target), 1, (struct uio *)addr);}
end_define

begin_define
define|#
directive|define
name|GET_SHORT_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|addr
parameter_list|,
name|offs
parameter_list|)
value|{uiomove((char*)&(target), 2, (struct uio *)addr);}
end_define

begin_define
define|#
directive|define
name|GET_WORD_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|addr
parameter_list|,
name|offs
parameter_list|)
value|{uiomove((char*)&(target), 4, (struct uio *)addr);}
end_define

begin_define
define|#
directive|define
name|PUT_WORD_TO_USER
parameter_list|(
name|addr
parameter_list|,
name|offs
parameter_list|,
name|data
parameter_list|)
value|{uiomove((char*)&(data), 4, (struct uio *)addr);}
end_define

begin_define
define|#
directive|define
name|EREMOTEIO
value|-1
end_define

begin_comment
comment|/*  * The way how the ioctl arguments are passed is another nonportable thing.  * In Linux the argument is just a pointer directly to the user segment. On  * FreeBSD the data is already moved to the kernel space. The following  * macros should handle the difference.  */
end_comment

begin_comment
comment|/*  * IOCTL_FROM_USER is used to copy a record pointed by the argument to  * a buffer in the kernel space. On FreeBSD it can be done just by calling  * memcpy. With Linux a memcpy_from_fs should be called instead.  * Parameters of the following macros are like in the COPY_*_USER macros.  */
end_comment

begin_comment
comment|/*  * When the ioctl argument points to a record or array (longer than 32 bits),  * the macros IOCTL_*_USER are used. It's assumed that the source and target  * parameters are direct memory addresses.  */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FROM_USER
parameter_list|(
name|target
parameter_list|,
name|source
parameter_list|,
name|offs
parameter_list|,
name|count
parameter_list|)
value|{memcpy(target,&((source)[offs]), count);}
end_define

begin_define
define|#
directive|define
name|IOCTL_TO_USER
parameter_list|(
name|target
parameter_list|,
name|offs
parameter_list|,
name|source
parameter_list|,
name|count
parameter_list|)
value|{memcpy(&((target)[offs]), source, count);}
end_define

begin_comment
comment|/* The following macros are used if the ioctl argument points to 32 bit int */
end_comment

begin_define
define|#
directive|define
name|IOCTL_IN
parameter_list|(
name|arg
parameter_list|)
value|(*(int*)arg)
end_define

begin_define
define|#
directive|define
name|IOCTL_OUT
parameter_list|(
name|arg
parameter_list|,
name|ret
parameter_list|)
value|*(int*)arg = ret
end_define

begin_comment
comment|/*  * When the driver displays something to the console, printk() will be called.  * The name can be changed here.  */
end_comment

begin_define
define|#
directive|define
name|printk
value|printf
end_define

begin_comment
comment|/*  * The following macros define an interface to the process management.  */
end_comment

begin_struct
struct|struct
name|snd_wait
block|{
name|int
name|mode
decl_stmt|;
name|int
name|aborting
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * DEFINE_WAIT_QUEUE is used where a wait queue is required. It must define  * a structure which can be passed as a parameter to a sleep(). The second  * parameter is name of a flag variable (must be defined as int).  */
end_comment

begin_define
define|#
directive|define
name|DEFINE_WAIT_QUEUE
parameter_list|(
name|qname
parameter_list|,
name|flag
parameter_list|)
value|static int *qname = NULL; \ 	static volatile struct snd_wait flag = {0}
end_define

begin_comment
comment|/* Like the above but defines an array of wait queues and flags */
end_comment

begin_define
define|#
directive|define
name|DEFINE_WAIT_QUEUES
parameter_list|(
name|qname
parameter_list|,
name|flag
parameter_list|)
value|static int *qname = {NULL}; \ 	static volatile struct snd_wait flag = {{0}}
end_define

begin_define
define|#
directive|define
name|RESET_WAIT_QUEUE
parameter_list|(
name|q
parameter_list|,
name|f
parameter_list|)
value|{f.aborting = 0;f.mode = WK_NONE;}
end_define

begin_define
define|#
directive|define
name|SET_ABORT_FLAG
parameter_list|(
name|q
parameter_list|,
name|f
parameter_list|)
value|f.aborting = 1
end_define

begin_define
define|#
directive|define
name|TIMED_OUT
parameter_list|(
name|q
parameter_list|,
name|f
parameter_list|)
value|(f.mode& WK_TIMEOUT)
end_define

begin_define
define|#
directive|define
name|SOMEONE_WAITING
parameter_list|(
name|q
parameter_list|,
name|f
parameter_list|)
value|(f.mode& WK_SLEEP)
end_define

begin_comment
comment|/*  * This driver handles interrupts little bit nonstandard way. The following  * macro is used to test if the current process has received a signal which  * is aborts the process. This macro is called from close() to see if the  * buffers should be discarded. If this kind info is not available, a constant  * 1 or 0 could be returned (1 should be better than 0).  */
end_comment

begin_define
define|#
directive|define
name|PROCESS_ABORTING
parameter_list|(
name|q
parameter_list|,
name|f
parameter_list|)
value|(f.aborting || CURSIG(curproc))
end_define

begin_comment
comment|/*  * The following macro calls tsleep. It should be implemented such that  * the process is resumed if it receives a signal.  * The q parameter is a wait_queue defined with DEFINE_WAIT_QUEUE(),  * and the second is a workarea parameter. The third is a timeout   * in ticks. Zero means no timeout.  */
end_comment

begin_define
define|#
directive|define
name|DO_SLEEP
parameter_list|(
name|q
parameter_list|,
name|f
parameter_list|,
name|time_limit
parameter_list|)
define|\
value|{ \ 	  int flag; \ 	  f.mode = WK_SLEEP; \ 	  flag=tsleep(&q, (PRIBIO-5)|PCATCH, "sndint", time_limit); \ 	  f.mode&= ~WK_SLEEP; \ 	  if (flag == EWOULDBLOCK) { \ 		f.mode |= WK_TIMEOUT; \ 		f.aborting = 0; \ 	  } else \ 		f.aborting = flag; \ 	}
end_define

begin_comment
comment|/* An the following wakes up a process */
end_comment

begin_define
define|#
directive|define
name|WAKE_UP
parameter_list|(
name|q
parameter_list|,
name|f
parameter_list|)
value|wakeup(&q)
end_define

begin_comment
comment|/*  * Timing macros. This driver assumes that there is a timer running in the  * kernel. The timer should return a value which is increased once at every  * timer tick. The macro HZ should return the number of such ticks/sec.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HZ
end_ifndef

begin_define
define|#
directive|define
name|HZ
value|hz
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * GET_TIME() returns current value of the counter incremented at timer  * ticks.  This can overflow, so the timeout might be real big...  *   */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|long
name|get_time
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GET_TIME
parameter_list|()
value|get_time()
end_define

begin_comment
comment|/*#define GET_TIME()	(lbolt)	*/
end_comment

begin_comment
comment|/* Returns current time (1/HZ secs since boot) */
end_comment

begin_comment
comment|/*  * The following three macros are called before and after atomic  * code sequences. The flags parameter has always type of unsigned long.  * The macro DISABLE_INTR() should ensure that all interrupts which  * may invoke any part of the driver (timer, soundcard interrupts) are  * disabled.  * RESTORE_INTR() should return the interrupt status back to the  * state when DISABLE_INTR() was called. The flags parameter is  * a variable which can carry 32 bits of state information between  * DISABLE_INTR() and RESTORE_INTR() calls.  */
end_comment

begin_define
define|#
directive|define
name|DISABLE_INTR
parameter_list|(
name|flags
parameter_list|)
value|flags = splhigh()
end_define

begin_define
define|#
directive|define
name|RESTORE_INTR
parameter_list|(
name|flags
parameter_list|)
value|splx(flags)
end_define

begin_comment
comment|/*  * INB() and OUTB() should be obvious. NOTE! The order of  * paratemeters of OUTB() is different than on some other  * operating systems.  */
end_comment

begin_define
define|#
directive|define
name|INB
value|inb
end_define

begin_define
define|#
directive|define
name|INW
value|inb
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*    * The outb(0, 0x80) is just for slowdown. It's bit unsafe since  * this address could be used for something usefull.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PC98
end_ifdef

begin_define
define|#
directive|define
name|OUTB
parameter_list|(
name|addr
parameter_list|,
name|data
parameter_list|)
value|{outb(data, addr);outb(0x5f, 0);}
end_define

begin_define
define|#
directive|define
name|OUTW
parameter_list|(
name|addr
parameter_list|,
name|data
parameter_list|)
value|{outw(data, addr);outb(0x5f, 0);}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OUTB
parameter_list|(
name|addr
parameter_list|,
name|data
parameter_list|)
value|{outb(data, addr);outb(0, 0x80);}
end_define

begin_define
define|#
directive|define
name|OUTW
parameter_list|(
name|addr
parameter_list|,
name|data
parameter_list|)
value|{outw(data, addr);outb(0, 0x80);}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OUTB
parameter_list|(
name|addr
parameter_list|,
name|data
parameter_list|)
value|outb(data, addr)
end_define

begin_define
define|#
directive|define
name|OUTW
parameter_list|(
name|addr
parameter_list|,
name|data
parameter_list|)
value|outw(data, addr)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* memcpy() was not defined on FreeBSD. Lets define it here */
end_comment

begin_define
define|#
directive|define
name|memcpy
parameter_list|(
name|d
parameter_list|,
name|s
parameter_list|,
name|c
parameter_list|)
value|bcopy(s, d, c)
end_define

begin_comment
comment|/*  * When a error (such as EINVAL) is returned by a function,  * the following macro is used. The driver assumes that a  * error is signalled by returning a negative value.  */
end_comment

begin_define
define|#
directive|define
name|RET_ERROR
parameter_list|(
name|err
parameter_list|)
value|-(err)
end_define

begin_comment
comment|/*     KERNEL_MALLOC() allocates requested number of memory  and     KERNEL_FREE is used to free it.     These macros are never called from interrupt, in addition the    nbytes will never be more than 4096 bytes. Generally the driver    will allocate memory in blocks of 4k. If the kernel has just a    page level memory allocation, 4K can be safely used as the size    (the nbytes parameter can be ignored). */
end_comment

begin_define
define|#
directive|define
name|KERNEL_MALLOC
parameter_list|(
name|nbytes
parameter_list|)
value|malloc(nbytes, M_TEMP, M_WAITOK)
end_define

begin_define
define|#
directive|define
name|KERNEL_FREE
parameter_list|(
name|addr
parameter_list|)
value|free(addr, M_TEMP)
end_define

begin_comment
comment|/*  * The macro PERMANENT_MALLOC(typecast, mem_ptr, size, linux_ptr)  * returns size bytes of  * (kernel virtual) memory which will never get freed by the driver.  * This macro is called only during boot. The linux_ptr is a linux specific  * parameter which should be ignored in other operating systems.  * The mem_ptr is a pointer variable where the macro assigns pointer to the  * memory area. The type is the type of the mem_ptr.  */
end_comment

begin_define
define|#
directive|define
name|PERMANENT_MALLOC
parameter_list|(
name|typecast
parameter_list|,
name|mem_ptr
parameter_list|,
name|size
parameter_list|,
name|linux_ptr
parameter_list|)
define|\
value|{mem_ptr = (typecast)malloc(size, M_DEVBUF, M_NOWAIT); \    if (!mem_ptr)panic("SOUND: Cannot allocate memory\n");}
end_define

begin_comment
comment|/*  * The macro DEFINE_TIMER defines variables for the ACTIVATE_TIMER if  * required. The name is the variable/name to be used and the proc is  * the procedure to be called when the timer expires.  */
end_comment

begin_define
define|#
directive|define
name|DEFINE_TIMER
parameter_list|(
name|name
parameter_list|,
name|proc
parameter_list|)
end_define

begin_comment
comment|/*  * The ACTIVATE_TIMER requests system to call 'proc' after 'time' ticks.  */
end_comment

begin_define
define|#
directive|define
name|ACTIVATE_TIMER
parameter_list|(
name|name
parameter_list|,
name|proc
parameter_list|,
name|time
parameter_list|)
define|\
value|timeout((timeout_func_t)proc, 0, time);
end_define

begin_comment
comment|/*  * The rest of this file is not complete yet. The functions using these  * macros will not work  */
end_comment

begin_define
define|#
directive|define
name|ALLOC_DMA_CHN
parameter_list|(
name|chn
parameter_list|,
name|deviceID
parameter_list|)
value|(isa_dma_acquire(chn))
end_define

begin_define
define|#
directive|define
name|RELEASE_DMA_CHN
parameter_list|(
name|chn
parameter_list|)
value|(isa_dma_release(chn))
end_define

begin_define
define|#
directive|define
name|DMA_MODE_READ
value|0
end_define

begin_define
define|#
directive|define
name|DMA_MODE_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|RELEASE_IRQ
parameter_list|(
name|irq_no
parameter_list|)
end_define

begin_comment
comment|/*  * The macro DECLARE_FILE() adds an entry to struct fileinfo referencing the  * connected filestructure.  * This entry must be initialized in sound_open() in soundcard.c  *  * ISSET_FILE_FLAG() allows checking of flags like O_NONBLOCK on files  *  */
end_comment

begin_define
define|#
directive|define
name|DECLARE_FILE
parameter_list|()
value|struct file *filp
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_define
define|#
directive|define
name|ISSET_FILE_FLAG
parameter_list|(
name|fileinfo
parameter_list|,
name|flag
parameter_list|)
value|(fileinfo->filp->f_flag& (flag) ? \ 					  1 : 0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ISSET_FILE_FLAG
parameter_list|(
name|fileinfo
parameter_list|,
name|flag
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INT_HANDLER_PROTO
parameter_list|()
value|void(*hndlr)(int)
end_define

begin_define
define|#
directive|define
name|INT_HANDLER_PARMS
parameter_list|(
name|irq
parameter_list|,
name|parms
parameter_list|)
value|int irq
end_define

begin_define
define|#
directive|define
name|INT_HANDLER_CALL
parameter_list|(
name|irq
parameter_list|)
value|irq
end_define

begin_comment
comment|/*  * For select call...  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ALLOW_SELECT
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|proc
name|select_table
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SEL_IN
value|FREAD
end_define

begin_define
define|#
directive|define
name|SEL_OUT
value|FWRITE
end_define

begin_define
define|#
directive|define
name|SEL_EX
value|0
end_define

begin_decl_stmt
specifier|extern
name|struct
name|selinfo
name|selinfo
index|[]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

