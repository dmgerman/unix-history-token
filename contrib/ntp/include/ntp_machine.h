begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_machine.h  *  * Collect all machine dependent idiosyncrasies in one place.  *  * The functionality formerly in this file is mostly handled by  * Autoconf these days.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_MACHINE_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_MACHINE_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|"ntp_proto.h"
end_include

begin_comment
comment|/*  			 HEY!  CHECK THIS OUT!    The per-system SYS_* #defins ARE NO LONGER USED, with the temporary   exception of SYS_WINNT.    If you find a hunk of code that is bracketed by a SYS_* macro and you   *know* that it is still needed, please let us know.  In many cases the   code fragment is now handled somewhere else by autoconf choices.  */
end_comment

begin_comment
comment|/*  HOW TO GET IP INTERFACE INFORMATION    Some UNIX V.4 machines implement a sockets library on top of   streams. For these systems, you must use send the SIOCGIFCONF down   the stream in an I_STR ioctl. This ususally also implies   USE_STREAMS_DEVICE FOR IF_CONFIG. Dell UNIX is a notable exception.  WHAT DOES IOCTL(SIOCGIFCONF) RETURN IN THE BUFFER    UNIX V.4 machines implement a sockets library on top of streams.   When requesting the IP interface configuration with an ioctl(2) calll,   an array of ifreq structures are placed in the provided buffer.  Some   implementations also place the length of the buffer information in   the first integer position of the buffer.    SIZE_RETURNED_IN_BUFFER - size integer is in the buffer  WILL IOCTL(SIOCGIFCONF) WORK ON A SOCKET    Some UNIX V.4 machines do not appear to support ioctl() requests for the   IP interface configuration on a socket.  They appear to require the use   of the streams device instead.    USE_STREAMS_DEVICE_FOR_IF_CONFIG - use the /dev/ip device for configuration  MISC    DOSYNCTODR		- Resync TODR clock  every hour.   RETSIGTYPE		- Define signal function type.   NO_SIGNED_CHAR_DECL - No "signed char" see include/ntp.h   LOCK_PROCESS		- Have plock. */
end_comment

begin_function_decl
name|int
name|ntp_set_tod
parameter_list|(
name|struct
name|timeval
modifier|*
name|tvp
parameter_list|,
name|void
modifier|*
name|tzp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*casey Tue May 27 15:45:25 SAT 1997*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_VXWORKS
end_ifdef

begin_comment
comment|/* casey's new defines */
end_comment

begin_define
define|#
directive|define
name|NO_MAIN_ALLOWED
value|1
end_define

begin_define
define|#
directive|define
name|NO_NETDB
value|1
end_define

begin_define
define|#
directive|define
name|NO_RENAME
value|1
end_define

begin_comment
comment|/* in vxWorks we use FIONBIO, but the others are defined for old systems, so  * all hell breaks loose if we leave them defined we define USE_FIONBIO to  * undefine O_NONBLOCK FNDELAY O_NDELAY where necessary.  */
end_comment

begin_define
define|#
directive|define
name|USE_FIONBIO
value|1
end_define

begin_comment
comment|/* end my new defines */
end_comment

begin_define
define|#
directive|define
name|TIMEOFDAY
value|0x0
end_define

begin_comment
comment|/* system wide realtime clock */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCLOCK
value|1
end_define

begin_comment
comment|/* configure does not set this ... */
end_comment

begin_define
define|#
directive|define
name|HAVE_NO_NICE
value|1
end_define

begin_comment
comment|/* configure does not set this ... */
end_comment

begin_define
define|#
directive|define
name|HAVE_RANDOM
value|1
end_define

begin_comment
comment|/* configure does not set this ...  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SRANDOM
value|1
end_define

begin_comment
comment|/* configure does not set this ... */
end_comment

begin_comment
comment|/* vxWorks specific additions to take care of its  * unix (non)complicance  */
end_comment

begin_include
include|#
directive|include
file|"vxWorks.h"
end_include

begin_include
include|#
directive|include
file|"ioLib.h"
end_include

begin_include
include|#
directive|include
file|"taskLib.h"
end_include

begin_include
include|#
directive|include
file|"time.h"
end_include

begin_function_decl
specifier|extern
name|int
name|sysClkRateGet
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* usrtime.h  * Bob Herlien's excellent time code find it at:  * ftp://ftp.atd.ucar.edu/pub/vxworks/vx/usrTime.shar  * I would recommend this instead of clock_[g|s]ettime() plus you get  * adjtime() too ... casey  */
end_comment

begin_comment
comment|/* extern int	  gettimeofday ( struct timeval *tp, struct timezone *tzp ); extern int	  settimeofday (struct timeval *, struct timezone *); extern int	  adjtime ( struct timeval *delta, struct timeval *olddelta );  */
end_comment

begin_comment
comment|/* in  machines.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|sleep
parameter_list|(
name|int
name|seconds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alarm
parameter_list|(
name|int
name|seconds
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* machines.c */
end_comment

begin_comment
comment|/*		this is really this 	*/
end_comment

begin_define
define|#
directive|define
name|getpid
value|taskIdSelf
end_define

begin_define
define|#
directive|define
name|getclock
value|clock_gettime
end_define

begin_define
define|#
directive|define
name|fcntl
value|ioctl
end_define

begin_define
define|#
directive|define
name|_getch
value|getchar
end_define

begin_comment
comment|/* define this away for vxWorks */
end_comment

begin_define
define|#
directive|define
name|openlog
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
end_define

begin_comment
comment|/* use local defines for these */
end_comment

begin_undef
undef|#
directive|undef
name|min
end_undef

begin_undef
undef|#
directive|undef
name|max
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_VXWORKS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_NETDB
end_ifdef

begin_comment
comment|/* These structures are needed for gethostbyname() etc... */
end_comment

begin_comment
comment|/* structures used by netdb.h */
end_comment

begin_struct
struct|struct
name|hostent
block|{
name|char
modifier|*
name|h_name
decl_stmt|;
comment|/* official name of host */
name|char
modifier|*
modifier|*
name|h_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|h_addrtype
decl_stmt|;
comment|/* host address type */
name|int
name|h_length
decl_stmt|;
comment|/* length of address */
name|char
modifier|*
modifier|*
name|h_addr_list
decl_stmt|;
comment|/* list of addresses from name server */
define|#
directive|define
name|h_addr
value|h_addr_list[0]
comment|/* address, for backward compatibility */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|servent
block|{
name|char
modifier|*
name|s_name
decl_stmt|;
comment|/* official service name */
name|char
modifier|*
modifier|*
name|s_aliases
decl_stmt|;
comment|/* alias list */
name|int
name|s_port
decl_stmt|;
comment|/* port # */
name|char
modifier|*
name|s_proto
decl_stmt|;
comment|/* protocol to use */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|h_errno
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TRY_AGAIN
value|2
end_define

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbyname
parameter_list|(
name|char
modifier|*
name|netnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|hostent
modifier|*
name|gethostbyaddr
parameter_list|(
name|char
modifier|*
name|netnum
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|addr_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* type is the protocol */
end_comment

begin_function_decl
name|struct
name|servent
modifier|*
name|getservbyname
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_NETDB */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_MAIN_ALLOWED
end_ifdef

begin_comment
comment|/* we have no main routines so lets make a plan */
end_comment

begin_define
define|#
directive|define
name|CALL
parameter_list|(
name|callname
parameter_list|,
name|progname
parameter_list|,
name|callmain
parameter_list|)
define|\
value|extern int callmain (int,char**); \ 	void callname (a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10) \ 		char *a0;  \ 		char *a1;  \ 		char *a2;  \ 		char *a3;  \ 		char *a4;  \ 		char *a5;  \ 		char *a6;  \ 		char *a7;  \ 		char *a8;  \ 		char *a9;  \ 		char *a10; \ 	{ \ 	  char *x[11]; \ 	  int argc; \ 	  char *argv[] = {progname,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL}; \ 	  int i; \ 	  for (i=0;i<11;i++) \ 	   x[i] = NULL; \ 	  x[0] = a0; \ 	  x[1] = a1; \ 	  x[2] = a2; \ 	  x[3] = a3; \ 	  x[4] = a4; \ 	  x[5] = a5; \ 	  x[6] = a6; \ 	  x[7] = a7; \ 	  x[8] = a8; \ 	  x[9] = a9; \ 	  x[10] = a10; \ 	  argc=1; \ 	  for (i=0; i<11;i++) \ 		if (x[i]) \ 		{ \ 		  argv[argc++] = x[i];	\ 		} \ 	 callmain(argc,argv);  \ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NO_MAIN_ALLOWED */
end_comment

begin_comment
comment|/*casey Tue May 27 15:45:25 SAT 1997*/
end_comment

begin_comment
comment|/*  * Here's where autoconfig starts to take over  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STROPTS_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_STREAM_H
end_ifdef

begin_define
define|#
directive|define
name|STREAM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|RETSIGTYPE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|NTP_POSIX_SOURCE
argument_list|)
end_if

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RETSIGTYPE
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|NTP_SYSCALLS_STD
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_SYSCALL_GET
end_ifndef

begin_define
define|#
directive|define
name|NTP_SYSCALL_GET
value|235
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_SYSCALL_ADJ
end_ifndef

begin_define
define|#
directive|define
name|NTP_SYSCALL_ADJ
value|236
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_SYSCALLS_STD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MPE
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/* missing functions that are easily renamed */
end_comment

begin_define
define|#
directive|define
name|_getch
value|getchar
end_define

begin_comment
comment|/* special functions that require MPE-specific wrappers */
end_comment

begin_define
define|#
directive|define
name|bind
value|__ntp_mpe_bind
end_define

begin_define
define|#
directive|define
name|fcntl
value|__ntp_mpe_fcntl
end_define

begin_comment
comment|/* standard macros missing from MPE include files */
end_comment

begin_define
define|#
directive|define
name|IN_CLASSD
parameter_list|(
name|i
parameter_list|)
value|((((long)(i))&0xf0000000)==0xe0000000)
end_define

begin_define
define|#
directive|define
name|IN_MULTICAST
value|IN_CLASSD
end_define

begin_define
define|#
directive|define
name|ITIMER_REAL
value|0
end_define

begin_comment
comment|/* standard structures missing from MPE include files */
end_comment

begin_struct
struct|struct
name|itimerval
block|{
name|struct
name|timeval
name|it_interval
decl_stmt|;
comment|/* timer interval */
name|struct
name|timeval
name|it_value
decl_stmt|;
comment|/* current value */
block|}
struct|;
end_struct

begin_comment
comment|/* various declarations to make gcc stop complaining */
end_comment

begin_function_decl
specifier|extern
name|int
name|__filbuf
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|__flsbuf
parameter_list|(
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gethostname
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|long
name|inet_addr
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* miscellaneous NTP macros */
end_comment

begin_define
define|#
directive|define
name|HAVE_NO_NICE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MPE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_RTPRIO
end_ifdef

begin_define
define|#
directive|define
name|HAVE_NO_NICE
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SETPRIORITY
end_ifdef

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NICE
end_ifdef

begin_define
define|#
directive|define
name|HAVE_ATT_NICE
end_define

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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_ATT_NICE
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_BSD_NICE
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_NO_NICE
argument_list|)
end_if

begin_include
include|#
directive|include
file|"ERROR: You must define one of the HAVE_xx_NICE defines!"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TIMEGM
end_ifndef

begin_function_decl
specifier|extern
name|time_t
name|timegm
parameter_list|(
name|struct
name|tm
modifier|*
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
comment|/* NTP_MACHINE_H */
end_comment

end_unit

