begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * os.h -- only included by sound_config.h right after local.h  *  * $FreeBSD$  */
end_comment

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
file|<sys/fcntl.h>
end_include

begin_include
include|#
directive|include
file|<sys/filio.h>
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
file|<sys/poll.h>
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
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/soundcard.h>
end_include

begin_include
include|#
directive|include
file|<i386/isa/isa_device.h>
end_include

begin_undef
undef|#
directive|undef
name|DELAY
end_undef

begin_define
define|#
directive|define
name|DELAY
parameter_list|(
name|x
parameter_list|)
value|tenmicrosec(x)
end_define

begin_typedef
typedef|typedef
name|struct
name|uio
name|snd_rw_buf
typedef|;
end_typedef

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

begin_function_decl
name|unsigned
name|long
name|get_time
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OS_H_ */
end_comment

begin_typedef
typedef|typedef
name|caddr_t
name|ioctl_arg
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|sound_os_info
block|{
name|int
name|unit
decl_stmt|;
block|}
name|sound_os_info
typedef|;
end_typedef

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

begin_define
define|#
directive|define
name|DO_SLEEP1
parameter_list|(
name|q
parameter_list|,
name|f
parameter_list|,
name|time_limit
parameter_list|)
define|\
value|{ \ 	  int flag; \ 	  f.mode = WK_SLEEP; \ 	  flag=tsleep(&q, (PRIBIO-5)|PCATCH, "snd1", time_limit); \ 	  f.mode&= ~WK_SLEEP; \ 	  if (flag == EWOULDBLOCK) { \ 		f.mode |= WK_TIMEOUT; \ 		f.aborting = 0; \ 	  } else \ 		f.aborting = flag; \ 	}
end_define

begin_define
define|#
directive|define
name|DO_SLEEP2
parameter_list|(
name|q
parameter_list|,
name|f
parameter_list|,
name|time_limit
parameter_list|)
define|\
value|{ \ 	  int flag; \ 	  f.mode = WK_SLEEP; \ 	  flag=tsleep(&q, (PRIBIO-5)|PCATCH, "snd2", time_limit); \ 	  f.mode&= ~WK_SLEEP; \ 	  if (flag == EWOULDBLOCK) { \ 		f.mode |= WK_TIMEOUT; \ 		f.aborting = 0; \ 	  } else \ 		f.aborting = flag; \ 	}
end_define

begin_define
define|#
directive|define
name|PROCESS_ABORTING
parameter_list|(
name|f
parameter_list|)
value|(f.aborting || CURSIG(curproc))
end_define

begin_define
define|#
directive|define
name|TIMED_OUT
parameter_list|(
name|f
parameter_list|)
value|(f.mode& WK_TIMEOUT)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ALLOW_POLL
end_ifdef

begin_typedef
typedef|typedef
name|struct
name|proc
name|select_table
typedef|;
end_typedef

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

end_unit

