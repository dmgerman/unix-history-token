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
comment|/*  * OS specific settings for FreeBSD  *  * Copyright by Hannu Savolainen 1993  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * This should be used as an example when porting the driver to a new  * operating systems.  *  * What you should do is to rewrite the soundcard.c and os.h (this file).  * You should create a new subdirectory and put these two files there.  * In addition you have to do a makefile.<OS>.  *  * If you have to make changes to other than these two files, please contact me  * before making the changes. It's possible that I have already made the  * change.   */
end_comment

begin_comment
comment|/*  * Insert here the includes required by your kernel.  */
end_comment

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"user.h"
end_include

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_include
include|#
directive|include
file|"file.h"
end_include

begin_include
include|#
directive|include
file|"uio.h"
end_include

begin_include
include|#
directive|include
file|"syslog.h"
end_include

begin_include
include|#
directive|include
file|"errno.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_include
include|#
directive|include
file|"buf.h"
end_include

begin_include
include|#
directive|include
file|"i386/isa/isa_device.h"
end_include

begin_comment
comment|/* These few lines are used by FreeBSD (only??). */
end_comment

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
name|KERNEL_SOUNDCARD
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|KERNEL_SOUNDCARD
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
comment|/* lbolt is required by the FreeBSD version (only???) */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|__timeout_val
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|__process_aborting
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   * select() is currently implemented in Linux specific way. Don't enable.  * I don't remember what the SHORT_BANNERS means so forget it.  */
end_comment

begin_undef
undef|#
directive|undef
name|ALLOW_SELECT
end_undef

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
file|"soundcard.h"
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
value|do { if (uiomove(target, count, source)) { \ 		printf ("sb: Bad copyin()!\n"); \ 	} } while(0)
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
value|do { if (uiomove(source, count, target)) { \ 		printf ("sb: Bad copyout()!\n"); \ 	} } while(0)
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
value|{uiomove((char*)&(target), 1, addr);}
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
value|{uiomove((char*)&(target), 2, addr);}
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
value|{uiomove((char*)&(target), 4, addr);}
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
value|{uiomove((char*)&(data), 4, addr);}
end_define

begin_comment
comment|/*  * The way how the ioctl arguments are passed is another nonportable thing.  * In Linux the argument is just a pointer directly to the user segment. On  * 386bsd the data is already moved to the kernel space. The following  * macros should handle the difference.  */
end_comment

begin_comment
comment|/*  * IOCTL_FROM_USER is used to copy a record pointed by the argument to  * a buffer in the kernel space. On 386bsd it can be done just by calling  * memcpy. With Linux a memcpy_from_fs should be called instead.  * Parameters of the following macros are like in the COPY_*_USER macros.  */
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
value|static int *qname = NULL; static int flag = 0
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
value|static int *qname = {NULL}; static int flag = {0}
end_define

begin_comment
comment|/*  * This driver handles interrupts little bit nonstandard way. The following  * macro is used to test if the current process has received a signal which  * is aborts the process. This macro is called from close() to see if the  * buffers should be discarded. If this kind info is not available, a constant  * 1 or 0 could be returned (1 should be better than 0).  * I'm not sure if the following is correct for FreeBSD.  */
end_comment

begin_define
define|#
directive|define
name|PROCESS_ABORTING
value|(__process_aborting | curproc->p_sig)
end_define

begin_comment
comment|/*   * REQUEST_TIMEOUT is called before sleep. It shoud ensure that the  * process is woken up after given number of ticks (1/HZ secs.).  * The wqueue gives the wait queue.  */
end_comment

begin_define
define|#
directive|define
name|REQUEST_TIMEOUT
parameter_list|(
name|nticks
parameter_list|,
name|wqueue
parameter_list|)
value|__timeout_val = nticks;
end_define

begin_comment
comment|/*  * The following macro calls sleep. It should be implemented such that  * the process is resumed if it receives a signal. The following is propably  * not the way how it should be done on 386bsd.  * The on_what parameter is a wait_queue defined with DEFINE_WAIT_QUEUE()  * The second parameter is a flag. It must be initialized to 1 before sleep  * and to zero after proces continues.  */
end_comment

begin_define
define|#
directive|define
name|INTERRUPTIBLE_SLEEP_ON
parameter_list|(
name|on_what
parameter_list|,
name|flag
parameter_list|)
define|\
value|{ \ 	  flag = 1; \ 	  flag=tsleep((caddr_t)&(on_what), (PRIBIO-5)|PCATCH, "sndint", __timeout_val); \ 	  if(flag == ERESTART) __process_aborting = 1;\ 	  else __process_aborting = 0;\ 	  __timeout_val = 0; \ 	  flag = 0; \ 	}
end_define

begin_comment
comment|/* An the following wakes up a process */
end_comment

begin_define
define|#
directive|define
name|WAKE_UP
parameter_list|(
name|who
parameter_list|)
value|wakeup((caddr_t)&(who))
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

begin_define
define|#
directive|define
name|GET_TIME
parameter_list|()
value|get_time()
end_define

begin_comment
comment|/*#define GET_TIME()	(lbolt)*/
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
name|OUTB
parameter_list|(
name|addr
parameter_list|,
name|data
parameter_list|)
value|outb(data, addr)
end_define

begin_comment
comment|/* memcpy() was not defined og 386bsd. Lets define it here */
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
comment|/*  * The rest of this file is not complete yet. The functions using these  * macros will not work  */
end_comment

begin_define
define|#
directive|define
name|ALLOC_DMA_CHN
parameter_list|(
name|chn
parameter_list|)
value|({ 0; })
end_define

begin_define
define|#
directive|define
name|RELEASE_DMA_CHN
parameter_list|(
name|chn
parameter_list|)
value|({ 0; })
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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

