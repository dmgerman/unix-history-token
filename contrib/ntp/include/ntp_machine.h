begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Collect all machine dependent idiosyncrasies in one place.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ntp_machine
end_ifndef

begin_define
define|#
directive|define
name|__ntp_machine
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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
file|"ntp_proto.h"
end_include

begin_comment
comment|/*  			 HEY!  CHECK THIS OUT!    The first half of this file is obsolete, and is only there to help   reconcile "what went before" with "current behavior".    The per-system SYS_* #defins ARE NO LONGER USED, with the temporary   exception of SYS_WINNT.    If you find a hunk of code that is bracketed by a SYS_* macro and you   *know* that it is still needed, please let us know.  In many cases the   code fragment is now handled somewhere else by autoconf choices.  */
end_comment

begin_comment
comment|/*  INFO ON NEW KERNEL PLL SYS CALLS    NTP_SYSCALLS_STD	- use the "normal" ones   NTP_SYSCALL_GET	- SYS_ntp_gettime id   NTP_SYSCALL_ADJ	- SYS_ntp_adjtime id   NTP_SYSCALLS_LIBC - ntp_adjtime() and ntp_gettime() are in libc.  HOW TO GET IP INTERFACE INFORMATION    Some UNIX V.4 machines implement a sockets library on top of   streams. For these systems, you must use send the SIOCGIFCONF down   the stream in an I_STR ioctl. This ususally also implies   USE_STREAMS_DEVICE FOR IF_CONFIG. Dell UNIX is a notable exception.    STREAMS_TLI - use ioctl(I_STR) to implement ioctl(SIOCGIFCONF)  WHAT DOES IOCTL(SIOCGIFCONF) RETURN IN THE BUFFER    UNIX V.4 machines implement a sockets library on top of streams.   When requesting the IP interface configuration with an ioctl(2) calll,   an array of ifreq structures are placed in the provided buffer.  Some   implementations also place the length of the buffer information in   the first integer position of the buffer.    SIZE_RETURNED_IN_BUFFER - size integer is in the buffer  WILL IOCTL(SIOCGIFCONF) WORK ON A SOCKET    Some UNIX V.4 machines do not appear to support ioctl() requests for the   IP interface configuration on a socket.  They appear to require the use   of the streams device instead.    USE_STREAMS_DEVICE_FOR_IF_CONFIG - use the /dev/ip device for configuration  MISC    HAVE_PROTOTYPES	- Prototype functions   DOSYNCTODR		- Resync TODR clock  every hour.   RETSIGTYPE		- Define signal function type.   NO_SIGNED_CHAR_DECL - No "signed char" see include/ntp.h   LOCK_PROCESS		- Have plock.   UDP_WILDCARD_DELIVERY 			- these systems deliver broadcast packets to the wildcard 			  port instead to a port bound to the interface bound 			  to the correct broadcast address - are these 			  implementations broken or did the spec change ? */
end_comment

begin_comment
comment|/*  * Set up for prototyping (duplicated from ntp_types.h)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|P
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_PROTOTYPES
argument_list|)
end_if

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ and not HAVE_PROTOTYPES */
end_comment

begin_define
define|#
directive|define
name|P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ and not HAVE_PROTOTYPES */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* P */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * IRIX 4.X and IRIX 5.x  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_IRIX4
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_IRIX5
argument_list|)
end_if

begin_define
define|#
directive|define
name|ADJTIME_IS_ACCURATE
end_define

begin_define
define|#
directive|define
name|LOCK_PROCESS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Ultrix  * Note: posix version has NTP_POSIX_SOURCE and HAVE_SIGNALED_IO  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_ULTRIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|S_CHAR_DEFINED
end_define

begin_define
define|#
directive|define
name|NTP_SYSCALLS_STD
end_define

begin_define
define|#
directive|define
name|HAVE_MODEM_CONTROL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * AUX  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_AUX2
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_AUX3
argument_list|)
end_if

begin_define
define|#
directive|define
name|NO_SIGNED_CHAR_DECL
end_define

begin_define
define|#
directive|define
name|LOCK_PROCESS
end_define

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
end_define

begin_comment
comment|/*  * This requires that _POSIX_SOURCE be forced on the  * compiler command flag. We can't do it here since this  * file is included _after_ the system header files and we  * need to let _them_ know we're POSIX. We do this in  * compilers/aux3.gcc...  */
end_comment

begin_define
define|#
directive|define
name|LOG_NTP
value|LOG_LOCAL1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * HPUX  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_HPUX
argument_list|)
end_if

begin_define
define|#
directive|define
name|getdtablesize
parameter_list|()
value|sysconf(_SC_OPEN_MAX)
end_define

begin_define
define|#
directive|define
name|setlinebuf
parameter_list|(
name|f
parameter_list|)
value|setvbuf(f, NULL, _IOLBF, 0)
end_define

begin_define
define|#
directive|define
name|NO_SIGNED_CHAR_DECL
end_define

begin_define
define|#
directive|define
name|LOCK_PROCESS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * BSD/OS 2.0 and above  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_BSDI
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_FSETOWNCTTY
end_define

begin_comment
comment|/* this funny system demands a CTTY for FSETOWN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * FreeBSD 2.0 and above  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYS_FREEBSD
end_ifdef

begin_define
define|#
directive|define
name|KERNEL_PLL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Linux  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_LINUX
argument_list|)
end_if

begin_define
define|#
directive|define
name|ntp_adjtime
value|__adjtimex
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * PTX  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_PTX
argument_list|)
end_if

begin_define
define|#
directive|define
name|LOCK_PROCESS
end_define

begin_comment
unit|struct timezone { int __0; };
comment|/* unused placebo */
end_comment

begin_comment
comment|/*  * no comment !@!  */
end_comment

begin_ifndef
unit|typedef unsigned int u_int;
ifndef|#
directive|ifndef
name|_NETINET_IN_SYSTM_INCLUDED
end_ifndef

begin_comment
comment|/* i am about to comment... */
end_comment

begin_endif
unit|typedef unsigned char u_char; typedef unsigned short u_short; typedef unsigned long u_long;
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * UNIX V.4 on and NCR 3000  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_SVR4
argument_list|)
end_if

begin_define
define|#
directive|define
name|STREAM
end_define

begin_define
define|#
directive|define
name|LOCK_PROCESS
end_define

begin_define
define|#
directive|define
name|SIZE_RETURNED_IN_BUFFER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * (Univel/Novell) Unixware1 SVR4 on intel x86 processor  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_UNIXWARE1
argument_list|)
end_if

begin_comment
comment|/* #define _POSIX_SOURCE */
end_comment

begin_define
define|#
directive|define
name|STREAM
end_define

begin_define
define|#
directive|define
name|STREAMS
end_define

begin_undef
undef|#
directive|undef
name|STEP_SLEW
end_undef

begin_comment
comment|/* TWO step */
end_comment

begin_define
define|#
directive|define
name|LOCK_PROCESS
end_define

begin_define
define|#
directive|define
name|SIZE_RETURNED_IN_BUFFER
end_define

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * DomainOS  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_DOMAINOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NTP_SYSCALLS_STD
end_define

begin_comment
comment|/* older versions of domain/os don't have class D */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|IN_CLASSD
end_ifndef

begin_define
define|#
directive|define
name|IN_CLASSD
parameter_list|(
name|i
parameter_list|)
value|(((long)(i)& 0xf0000000) == 0xe0000000)
end_define

begin_define
define|#
directive|define
name|IN_CLASSD_NET
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|IN_CLASSD_NSHIFT
value|28
end_define

begin_define
define|#
directive|define
name|IN_CLASSD_HOST
value|0xfffffff
end_define

begin_define
define|#
directive|define
name|IN_MULTICAST
parameter_list|(
name|i
parameter_list|)
value|IN_CLASSD(i)
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
comment|/*  * Fujitsu UXP/V  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_UXPV
argument_list|)
end_if

begin_define
define|#
directive|define
name|LOCK_PROCESS
end_define

begin_define
define|#
directive|define
name|SIZE_RETURNED_IN_BUFFER
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
comment|/* 0 */
end_comment

begin_comment
comment|/*  * Windows NT  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_WINNT
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_CONFIG_H
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|__config
argument_list|)
end_if

begin_expr_stmt
name|error
literal|"NT requires config.h to be included"
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H) */
end_comment

begin_if
if|#
directive|if
name|defined
name|SYS_WINNT
end_if

begin_define
define|#
directive|define
name|ifreq
value|_INTERFACE_INFO
end_define

begin_define
define|#
directive|define
name|ifr_flags
value|iiFlags
end_define

begin_define
define|#
directive|define
name|ifr_addr
value|iiAddress.AddressIn
end_define

begin_define
define|#
directive|define
name|ifr_broadaddr
value|iiBroadcastAddress.AddressIn
end_define

begin_define
define|#
directive|define
name|ifr_mask
value|iiNetmask.AddressIn
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_WINNT */
end_comment

begin_define
define|#
directive|define
name|isascii
value|__isascii
end_define

begin_define
define|#
directive|define
name|isatty
value|_isatty
end_define

begin_define
define|#
directive|define
name|mktemp
value|_mktemp
end_define

begin_define
define|#
directive|define
name|getpid
value|GetCurrentProcessId
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<ws2tcpip.h>
end_include

begin_undef
undef|#
directive|undef
name|interface
end_undef

begin_typedef
typedef|typedef
name|char
modifier|*
name|caddr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_WINNT */
end_comment

begin_decl_stmt
name|int
name|ntp_set_tod
name|P
argument_list|(
operator|(
expr|struct
name|timeval
operator|*
name|tvp
operator|,
name|void
operator|*
name|tzp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_CYGWIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_define
define|#
directive|define
name|__int64
value|long long
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_define
define|#
directive|define
name|NODETACH
value|1
end_define

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

begin_decl_stmt
specifier|extern
name|int
name|sysClkRateGet
name|P
argument_list|(
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* usrtime.h  * Bob Herlien's excellent time code find it at:  * ftp://ftp.atd.ucar.edu/pub/vxworks/vx/usrTime.shar  * I would recommend this instead of clock_[g|s]ettime() plus you get  * adjtime() too ... casey  */
end_comment

begin_comment
comment|/* extern int	  gettimeofday P(( struct timeval *tp, struct timezone *tzp )); extern int	  settimeofday P((struct timeval *, struct timezone *)); extern int	  adjtime P(( struct timeval *delta, struct timeval *olddelta ));  */
end_comment

begin_comment
comment|/* in  machines.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|sleep
name|P
argument_list|(
operator|(
name|int
name|seconds
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|alarm
name|P
argument_list|(
operator|(
name|int
name|seconds
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_define
define|#
directive|define
name|random
value|rand
end_define

begin_define
define|#
directive|define
name|srandom
value|srand
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

begin_decl_stmt
name|struct
name|hostent
modifier|*
name|gethostbyname
name|P
argument_list|(
operator|(
name|char
operator|*
name|netnum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|hostent
modifier|*
name|gethostbyaddr
name|P
argument_list|(
operator|(
name|char
operator|*
name|netnum
operator|,
name|int
name|size
operator|,
name|int
name|addr_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* type is the protocol */
end_comment

begin_decl_stmt
name|struct
name|servent
modifier|*
name|getservbyname
name|P
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|SYS_WINNT
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

begin_comment
comment|/*  * use only one tty model - no use in initialising  * a tty in three ways  * HAVE_TERMIOS is preferred over HAVE_SYSV_TTYS over HAVE_BSD_TTYS  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIOS_H
end_ifdef

begin_define
define|#
directive|define
name|HAVE_TERMIOS
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIO_H
end_ifdef

begin_define
define|#
directive|define
name|HAVE_SYSV_TTYS
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SGTTY_H
end_ifdef

begin_define
define|#
directive|define
name|HAVE_BSD_TTYS
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIOS
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_BSD_TTYS
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_SYSV_TTYS
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYSV_TTYS
end_ifdef

begin_undef
undef|#
directive|undef
name|HAVE_BSD_TTYS
end_undef

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
name|SYS_WINNT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SYS_VXWORKS
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SYSV_TTYS
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_BSD_TTYS
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TERMIOS
argument_list|)
end_if

begin_include
include|#
directive|include
file|"ERROR: no tty type defined!"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYS_WINNT || VMS	|| SYS_VXWORKS*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
end_ifdef

begin_define
define|#
directive|define
name|XNTP_BIG_ENDIAN
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|XNTP_LITTLE_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Byte order woes.  The DES code is sensitive to byte order.  This  * used to be resolved by calling ntohl() and htonl() to swap things  * around, but this turned out to be quite costly on Vaxes where those  * things are actual functions.  The code now straightens out byte  * order troubles on its own, with no performance penalty for little  * end first machines, but at great expense to cleanliness.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|XNTP_BIG_ENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|XNTP_LITTLE_ENDIAN
argument_list|)
end_if

begin_comment
comment|/* 	 * Pick one or the other. 	 */
end_comment

begin_expr_stmt
name|BYTE_ORDER_NOT_DEFINED_FOR_AUTHENTICATION
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|XNTP_BIG_ENDIAN
argument_list|)
operator|&&
name|defined
argument_list|(
name|XNTP_LITTLE_ENDIAN
argument_list|)
comment|/* 	 * Pick one or the other. 	 */
name|BYTE_ORDER_NOT_DEFINED_FOR_AUTHENTICATION
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ntp_machine */
end_comment

end_unit

