begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntp_compat.h,v 3.1 1993/07/06 01:06:49 jbj Exp  * Collect all machine dependent idiosyncrasies in one place.  */
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

begin_comment
comment|/*     Various options.     They can defined with the DEFS directive in the Config file if they     are not defined here.   WHICH NICE    HAVE_ATT_NICE     - Use att nice(priority_change)   HAVE_BSD_NICE     - Use bsd setprioirty(which, who, priority)   HAVE_NO_NICE      - Don't have (or use) either  KERNEL MUCKING - If you porting to a new system see xntpd/ntp_unixclock.c and 		 util/tickadj.c to see what these do. This is very system  	         dependent stuff!!! 		    HAVE_LIBKVM       - Use libkvm to read kernal memory   HAVE_READKMEM     - Use read to read kernal memory    NOKMEM	    - Don't read kmem   HAVE_N_UN         - Have u_nn nlist struct.  WHICH SETPGRP TO USE - Not needed if NTP_POSIX_SOURCE is defined since you 		       better of setsid!    HAVE_ATT_SETPGRP  - setpgrp(void) instead of setpgrp(int, int)   Signaled IO -  Signled IO defines.     HAVE_SIGNALED_IO  - Enable signaled io. Assumes you are going to use SIGIO 		      for tty and udp io.   USE_UDP_SIGPOLL   - Use SIGPOLL on socket io. This assumes that the 		      sockets routines are defined on top of streams.   USE_TTY_SIGPOLL   - Use SIGPOLL on tty io. This assumes streams.   UDP_BACKWARDS_SETOWN - SunOS 3.5 or Ultirx 2.0 system. 	        WHICH TERMINAL MODEL TO USE - I would assume HAVE_POSIX_TTYS if  		      NTP_POSIX_SOURCE was set but cann't.  The  		      posix tty driver is too restrictive on most systems. 		      It defined if you define STREAMS.    HAVE_SYSV_TTYS    - Use SYSV termio.h   HAVE_BSD_TTYS     - Use BSD stty.h   HAVE_POSIX_TTYS   - "struct termios" has c_line defined  THIS MAKES PORTS TO NEW SYSTEMS EASY - You only have to wory about 		                       kernal mucking.    NTP_POSIX_SOURCE  - Use POSIX functions over bsd functions and att functions. 		      This is NOT the same as _POSIX_SOURCE. 		      It is much weeker!   STEP SLEW OR TWO STEP - The Default is to step.    SLEWALWAYS  	    - setttimeofday can not be used to set the time of day at  		      all.    STEP_SLEW 	    - setttimeofday can not set the seconds part of time 		      time use setttimeofday to set the seconds part of the 		      time and the slew the seconds.   FORCE_NTPDATE_STEP - even if SLEWALWAYS is defined, force a step of 		      of the systemtime (via settimeofday()). Only takes 		      affect if STEP_SLEW isn't defined.  WHICH TIMEOFDAY()    SYSV_TIMEOFDAY    - [sg]ettimeofday(struct timeval *) as opposed to BSD                       [sg]ettimeofday(struct timeval *, struct timezone *)  INFO ON NEW KERNEL PLL SYS CALLS    NTP_SYSCALLS_STD  - use the "normal" ones   NTP_SYSCALL_GET   - SYS_ntp_gettime id   NTP_SYSCALL_ADJ   - SYS_ntp_adjtime id  WHAT DOES IOCTL(SIOCGIFCONF) RETURN IN THE BUFFER    UNIX V.4 machines implement a sockets library on top of streams.   When requesting the IP interface configuration with an ioctl(2) calll,   an arrat of ifreq structures are placed in the provided buffer.  Some   implementations also place the length of the buffer information in   the first integer position of the buffer.        SIZE_RETURNED_IN_BUFFER - size integer is in the buffer  WILL IOCTL(SIOCGIFCONF) WORK ON A SOCKET    Some UNIX V.4 machines do not appear to support ioctl() requests for the   IP interface configuration on a socket.  They appear to require the use   of the streams device instead.    USE_STREAMS_DEVICE_FOR_IF_CONFIG - use the /dev/ip device for configuration  MISC      USE_PROTOTYPES    - Prototype functions   DOSYNCTODR        - Resync TODR clock  every hour.   RETSIGTYPE        - Define signal function type.   NO_SIGNED_CHAR_DECL - No "signed char" see include/ntp.h   LOCK_PROCESS      -  Have plock.   UDP_WILDCARD_DELIVERY 		    - these systems deliver broadcast pakets to the wildcard 		      port instead to a port bound to the interface bound 		      to the correct broadcast address - are these 		      implementations broken or did the spec change ?    HAVE_UNISTD_H     - Maybe should be part of NTP_POSIX_SOURCE ?  You could just put the defines on the DEFS line in machines/<os> file. I don't since there are lost of different types compiler that a systemm might have, some that can do proto typing and others that cannot on the saem system. I get a chanse to twiddle some of the configuration paramasters at compile time based on compler/machine combinatsions by using this include file. See convex, aix and sun configurations see how complex it get.  */
end_comment

begin_comment
comment|/*  * RS6000 running AIX.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_AIX
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SIGNALED_IO
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_BSD
end_ifndef

begin_define
define|#
directive|define
name|NTP_STDC
end_define

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
end_define

begin_comment
comment|/*  * Keep USE_PROTOTYPES and _NO_PROTO in step.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_NO_PROTO
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|USE_PROTOTYPES
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
name|_NO_PROTO
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_PROTOTYPES
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
comment|/*_BSD */
end_comment

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RS6000 */
end_comment

begin_comment
comment|/*  * SunOS 4.X.X  * Note: posix version has NTP_POSIX_SOURCE and HAVE_SIGNALED_IO  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_SUNOS4
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
name|HAVE_LIBKVM
end_define

begin_define
define|#
directive|define
name|HAVE_MALLOC_H
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_define
define|#
directive|define
name|NTP_SYSCALL_GET
value|132
end_define

begin_define
define|#
directive|define
name|NTP_SYSCALL_ADJ
value|147
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Sinix-M  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_SINIXM
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HAVE_SIGNALED_IO
end_undef

begin_undef
undef|#
directive|undef
name|USE_TTY_SIGPOLL
end_undef

begin_undef
undef|#
directive|undef
name|USE_UDP_SIGPOLL
end_undef

begin_define
define|#
directive|define
name|NO_SIGNED_CHAR_DECL
end_define

begin_define
define|#
directive|define
name|STEP_SLEW
end_define

begin_comment
comment|/* TWO step */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|HAVE_ATT_SETPGRP
end_define

begin_define
define|#
directive|define
name|HAVE_ATT_NICE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SunOS 5.1 or SunOS 5.2 or Solaris 2.1 or Solaris 2.2  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_SOLARIS
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SIGNALED_IO
end_define

begin_define
define|#
directive|define
name|USE_TTY_SIGPOLL
end_define

begin_define
define|#
directive|define
name|USE_UDP_SIGPOLL
end_define

begin_define
define|#
directive|define
name|NO_SIGNED_CHAR_DECL
end_define

begin_define
define|#
directive|define
name|STEP_SLEW
end_define

begin_comment
comment|/* TWO step */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|HAVE_ATT_SETPGRP
end_define

begin_define
define|#
directive|define
name|HAVE_ATT_NICE
end_define

begin_define
define|#
directive|define
name|UDP_WILDCARD_DELIVERY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Convex  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_CONVEXOS10
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_CONVEXOS9
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SIGNALED_IO
end_define

begin_define
define|#
directive|define
name|HAVE_N_UN
end_define

begin_define
define|#
directive|define
name|HAVE_READKMEM
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|convex
argument_list|)
end_if

begin_define
define|#
directive|define
name|RETSIGTYPE
value|int
end_define

begin_define
define|#
directive|define
name|NO_SIGNED_CHAR_DECL
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__stdc__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_PROTOTYPES
end_define

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
name|__stdc__
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_PROTOTYPES
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|USE_PROTOTYPES
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|HAVE_ATT_SETPGRP
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
name|HAVE_SIGNALED_IO
end_define

begin_define
define|#
directive|define
name|USE_TTY_SIGPOLL
end_define

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

begin_define
define|#
directive|define
name|USE_PROTOTYPES
end_define

begin_define
define|#
directive|define
name|HAVE_ATT_SETPGRP
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
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
name|HAVE_READKMEM
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_define
define|#
directive|define
name|NTP_SYSCALLS_STD
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
name|HAVE_READKMEM
end_define

begin_define
define|#
directive|define
name|HAVE_ATT_NICE
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
name|SLEWALWAYS
end_define

begin_define
define|#
directive|define
name|FORCE_NTPDATE_STEP
end_define

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_define
define|#
directive|define
name|HAVE_ATT_SETPGRP
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_TTYS
end_define

begin_define
define|#
directive|define
name|LOG_NTP
value|LOG_LOCAL1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGNALED_IO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Next  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_NEXT
argument_list|)
end_if

begin_define
define|#
directive|define
name|DOSYNCTODR
end_define

begin_define
define|#
directive|define
name|HAVE_READKMEM
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_define
define|#
directive|define
name|HAVE_N_UN
end_define

begin_undef
undef|#
directive|undef
name|NTP_POSIX_SOURCE
end_undef

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
name|NTP_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|HAVE_SIGNALED_IO
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
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

begin_define
define|#
directive|define
name|HAVE_NO_NICE
end_define

begin_comment
comment|/* HPUX uses rtprio instead */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_if
if|#
directive|if
operator|(
name|SYS_HPUX
operator|<
literal|10
operator|)
end_if

begin_define
define|#
directive|define
name|NOKMEM
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_READKMEM
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
comment|/*  * bsdi  */
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
name|HAVE_SIGNALED_IO
end_define

begin_define
define|#
directive|define
name|HAVE_LIBKVM
end_define

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
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

begin_undef
undef|#
directive|undef
name|HAVE_SIGNALED_IO
end_undef

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|ADJTIME_IS_ACCURATE
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEX_H
end_define

begin_define
define|#
directive|define
name|ntp_adjtime
value|adjtimex
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * 386BSD and any variants 8-) - should really have only ONE define  * for this bunch.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_386BSD
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_FREEBSD
argument_list|)
operator|||
name|defined
argument_list|(
name|SYS_NETBSD
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SIGNALED_IO
end_define

begin_define
define|#
directive|define
name|HAVE_READKMEM
end_define

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * DECOSF1  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_DECOSF1
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SIGNALED_IO
end_define

begin_define
define|#
directive|define
name|HAVE_READKMEM
end_define

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|NTP_SYSCALLS_STD
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * I386  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_I386
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_READKMEM
end_define

begin_define
define|#
directive|define
name|S_CHAR_DEFINED
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Mips  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_MIPS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NOKMEM
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * SEQUENT  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_SEQUENT
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
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
name|NO_SIGNED_CHAR_DECL
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_SYSV_TTYS
end_ifndef

begin_define
define|#
directive|define
name|HAVE_SYSV_TTYS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HAVE_ATT_SETPGRP
end_define

begin_define
define|#
directive|define
name|HAVE_SIGNALED_IO
end_define

begin_define
define|#
directive|define
name|USE_UDP_SIGPOLL
end_define

begin_define
define|#
directive|define
name|USE_TTY_SIGPOLL
end_define

begin_undef
undef|#
directive|undef
name|ADJTIME_IS_ACCURATE
end_undef

begin_comment
comment|/* not checked yet */
end_comment

begin_define
define|#
directive|define
name|LOCK_PROCESS
end_define

begin_define
define|#
directive|define
name|HAVE_ATT_SETPGRP
end_define

begin_define
define|#
directive|define
name|HAVE_ATT_NICE
end_define

begin_define
define|#
directive|define
name|STEP_SLEW
end_define

begin_comment
comment|/* TWO step */
end_comment

begin_define
define|#
directive|define
name|SYSV_GETTIMEOFDAY
end_define

begin_define
define|#
directive|define
name|HAVE_READKMEM
end_define

begin_define
define|#
directive|define
name|UDP_WILDCARD_DELIVERY
end_define

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
end_define

begin_struct
struct|struct
name|timezone
block|{
name|int
name|__0
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* unused placebo */
end_comment

begin_comment
comment|/*  * no comment !@!  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_NETINET_IN_SYSTM_INCLUDED
end_ifndef

begin_comment
comment|/* i am about to comment... */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|u_char
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|u_short
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|u_long
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

begin_comment
comment|/*  * Sony  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_SONY
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
name|HAVE_READKMEM
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * VAX  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SYS_VAX
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
name|HAVE_READKMEM
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   * UNIX V.4 on and NCR 3000  */
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
name|HAVE_ATT_SETPGRP
end_define

begin_define
define|#
directive|define
name|USE_PROTOTYPES
end_define

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
end_define

begin_define
define|#
directive|define
name|NTP_POSIX_SOURCE
end_define

begin_define
define|#
directive|define
name|HAVE_ATT_NICE
end_define

begin_define
define|#
directive|define
name|HAVE_READKMEM
end_define

begin_define
define|#
directive|define
name|HAVE_SIGNALED_IO
end_define

begin_define
define|#
directive|define
name|USE_TTY_SIGPOLL
end_define

begin_define
define|#
directive|define
name|USE_UDP_SIGPOLL
end_define

begin_define
define|#
directive|define
name|STREAM
end_define

begin_define
define|#
directive|define
name|STEP_SLEW
end_define

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
name|SYSV_TIMEOFDAY
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_ATT_NICE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_BSD_NICE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_NO_NICE
argument_list|)
end_if

begin_expr_stmt
name|ERROR
name|You_must_define_one_of_the_HAVE_xx_NICE_defines
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

