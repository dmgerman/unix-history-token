begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ntp_machine.h,v 3.1 1993/07/06 01:06:49 jbj Exp  * Collect all machine dependent idiosyncrasies in one place.  */
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
comment|/*     Various options.     They can defined with the DEFS directive in the Config file if they     are not defined here.   WHICH NICE    HAVE_ATT_NICE     - Use att nice(priority_change)   HAVE_BSD_NICE     - Use bsd setprioirty(which, who, priority)   HAVE_NO_NICE      - Don't have (or use) either  KERNEL MUCKING - If you porting to a new system see xntpd/ntp_unixclock.c and 		 util/tickadj.c to see what these do. This is very system  	         dependent stuff!!! 		    HAVE_LIBKVM       - Use libkvm to read kernal memory   HAVE_READKMEM     - Use read to read kernal memory    NOKMEM	    - Don't read kmem   HAVE_N_UN         - Have u_nn nlist struct.  WHICH SETPGRP TO USE - Not needed if NTP_POSIX_SOURCE is defined since you 		       better of setsid!    HAVE_ATT_SETPGRP  - setpgrp(void) instead of setpgrp(int, int)   Signaled IO -  Signled IO defines.     HAVE_SIGNALED_IO  - Enable signaled io. Assumes you are going to use SIGIO 		      for tty and udp io.   USE_UDP_SIGPOLL   - Use SIGPOLL on socket io. This assumes that the 		      sockets routines are defined on top of streams.   USE_TTY_SIGPOLL   - Use SIGPOLL on tty io. This assumes streams.   UDP_BACKWARDS_SETOWN - SunOS 3.5 or Ultirx 2.0 system. 	        WHICH TERMINAL MODEL TO USE - I would assume HAVE_TERMIOS if  		      NTP_POSIX_SOURCE was set but can't.  The  		      posix tty driver is too restrictive on most systems. 		      It is defined if you define STREAMS.    We do not put these defines in the ntp_machine.h as some systems   offer multiple interfaces and refclock configuration likes to   peek into the configuration defines for tty model restrictions.   Thus all tty definitions should be in the files in the machines directory.    HAVE_TERMIOS      - Use POSIX termios.h   HAVE_SYSV_TTYS    - Use SYSV termio.h   HAVE_BSD_TTYS     - Use BSD stty.h  THIS MAKES PORTS TO NEW SYSTEMS EASY - You only have to wory about 		                       kernel mucking.    NTP_POSIX_SOURCE  - Use POSIX functions over bsd functions and att functions. 		      This is NOT the same as _POSIX_SOURCE. 		      It is much weaker!   STEP SLEW OR TWO STEP - The Default is to step.    SLEWALWAYS  	    - setttimeofday can not be used to set the time of day at  		      all.    STEP_SLEW 	    - setttimeofday can not set the seconds part of time 		      time use setttimeofday to set the seconds part of the 		      time and the slew the seconds.   FORCE_NTPDATE_STEP - even if SLEWALWAYS is defined, force a step of 		      of the systemtime (via settimeofday()). Only takes 		      affect if STEP_SLEW isn't defined.  WHICH TIMEOFDAY()    SYSV_TIMEOFDAY    - [sg]ettimeofday(struct timeval *) as opposed to BSD                       [sg]ettimeofday(struct timeval *, struct timezone *)  INFO ON NEW KERNEL PLL SYS CALLS    NTP_SYSCALLS_STD  - use the "normal" ones   NTP_SYSCALL_GET   - SYS_ntp_gettime id   NTP_SYSCALL_ADJ   - SYS_ntp_adjtime id   NTP_SYSCALLS_LIBC - ntp_adjtime() and ntp_gettime() are in libc.  HOW TO GET IP INTERFACE INFORMATION    Some UNIX V.4 machines implement a sockets library on top of   streams. For these systems, you must use send the SIOCGIFCONF down   the stream in an I_STR ioctl. This ususally also implies   USE_STREAMS_DEVICE FOR IF_CONFIG. Dell UNIX is a notable exception.    STREAMS_TLI - use ioctl(I_STR) to implement ioctl(SIOCGIFCONF)  WHAT DOES IOCTL(SIOCGIFCONF) RETURN IN THE BUFFER    UNIX V.4 machines implement a sockets library on top of streams.   When requesting the IP interface configuration with an ioctl(2) calll,   an array of ifreq structures are placed in the provided buffer.  Some   implementations also place the length of the buffer information in   the first integer position of the buffer.        SIZE_RETURNED_IN_BUFFER - size integer is in the buffer  WILL IOCTL(SIOCGIFCONF) WORK ON A SOCKET    Some UNIX V.4 machines do not appear to support ioctl() requests for the   IP interface configuration on a socket.  They appear to require the use   of the streams device instead.    USE_STREAMS_DEVICE_FOR_IF_CONFIG - use the /dev/ip device for configuration  MISC      USE_PROTOTYPES    - Prototype functions   DOSYNCTODR        - Resync TODR clock  every hour.   RETSIGTYPE        - Define signal function type.   NO_SIGNED_CHAR_DECL - No "signed char" see include/ntp.h   LOCK_PROCESS      - Have plock.   UDP_WILDCARD_DELIVERY 		    - these systems deliver broadcast packets to the wildcard 		      port instead to a port bound to the interface bound 		      to the correct broadcast address - are these 		      implementations broken or did the spec change ?  DEFINITIONS FOR SYSTEM&& PROCESSOR   STR_SYSTEM        - value of system variable   STR_PROCESSOR     - value of processor variable  You could just put the defines on the DEFS line in machines/<os> file. I don't since there are lots of different types of compilers that a system might have, some that can do proto typing and others that cannot on the same system. I get a chance to twiddle some of the configuration parameters at compile time based on compiler/machine combinations by using this include file. See convex, aix and sun configurations see how complex it get.    Note that it _is_ considered reasonable to add some system-specific defines to the machine/<os> file if it would be too inconvenient to puzzle them out in this file.    */
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/AIX"
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
name|NTP_NEED_BOPS
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/SunOS 4.x"
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
name|STREAMS_TLI
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/SINIX-M"
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/Solaris 2.x"
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/ConvexOS"
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/IRIX"
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/Ultrix"
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
name|LOG_NTP
value|LOG_LOCAL1
end_define

begin_define
define|#
directive|define
name|HAVE_SIGNALED_IO
end_define

begin_define
define|#
directive|define
name|NTP_NEED_BOPS
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/AUX"
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
name|RETSIGTYPE
value|void
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/Next"
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
literal|9
operator|)
end_if

begin_define
define|#
directive|define
name|HAVE_NO_NICE
end_define

begin_comment
comment|/* HPUX uses rtprio instead */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_comment
comment|/* new at 9.X */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/HPUX"
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/BSDI"
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

begin_comment
comment|/* hope there will be a standard interface   * along with a standard name one day ! */
end_comment

begin_define
define|#
directive|define
name|ntp_adjtime
value|__adjtimex
end_define

begin_define
define|#
directive|define
name|HAVE_BSD_NICE
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/Linux"
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/*BSD"
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
name|SYS_FREEBSD
end_ifdef

begin_define
define|#
directive|define
name|HAVE_TERMIOS
end_define

begin_define
define|#
directive|define
name|HAVE_UNAME
end_define

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEX_H
end_define

begin_define
define|#
directive|define
name|NTP_SYSCALLS_LIBC
end_define

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
comment|/*  * DEC AXP OSF/1  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/DECOSF1"
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
comment|/*  * I386  * XXX - what OS?  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/I386"
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/Mips"
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/Sequent Dynix 3"
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

begin_define
define|#
directive|define
name|STREAMS_TLI
end_define

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

begin_define
define|#
directive|define
name|memmove
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|z
parameter_list|)
value|memcpy(x, y, z)
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/Sequent PTX"
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
comment|/*  * Sony NEWS  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/Sony"
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
comment|/*  * VAX  * XXX - VMS?  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/VAX"
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/SysVR4"
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

begin_undef
undef|#
directive|undef
name|HAVE_ATT_SETPGRP
end_undef

begin_define
define|#
directive|define
name|USE_PROTOTYPES
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
name|UDP_WILDCARD_DELIVERY
end_define

begin_undef
undef|#
directive|undef
name|HAVE_SIGNALED_IO
end_undef

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

begin_ifndef
ifndef|#
directive|ifndef
name|STREAMS_TLI
end_ifndef

begin_comment
comment|/*#define STREAMS_TLI*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #define USE_STREAMS_DEVICE_FOR_IF_CONFIG */
end_comment

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
name|NO_SIGNED_CHAR_DECL
end_define

begin_undef
undef|#
directive|undef
name|SYSV_TIMEOFDAY
end_undef

begin_define
define|#
directive|define
name|SIZE_RETURNED_IN_BUFFER
end_define

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
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

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/Unixware1"
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
name|HAVE_BSD_NICE
end_define

begin_define
define|#
directive|define
name|NOKMEM
end_define

begin_define
define|#
directive|define
name|HAVE_SIGNALED_IO
end_define

begin_define
define|#
directive|define
name|NTP_SYSCALLS_STD
end_define

begin_define
define|#
directive|define
name|USE_PROTOTYPES
end_define

begin_define
define|#
directive|define
name|UDP_WILDCARD_DELIVERY
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|STR_SYSTEM
end_ifndef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"UNIX/DOMAINOS"
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
name|STREAM
end_ifdef

begin_comment
comment|/* STREAM implies TERMIOS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_TERMIOS
end_ifndef

begin_define
define|#
directive|define
name|HAVE_TERMIOS
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

begin_expr_stmt
name|ERROR
name|You_must_define_one_of_the_HAVE_xx_NICE_defines
endif|#
directive|endif
comment|/*  * use only one tty model - no use in initialising  * a tty in three ways  * HAVE_TERMIOS is preferred over HAVE_SYSV_TTYS over HAVE_BSD_TTYS  */
ifdef|#
directive|ifdef
name|HAVE_TERMIOS
undef|#
directive|undef
name|HAVE_BSD_TTYS
undef|#
directive|undef
name|HAVE_SYSV_TTYS
endif|#
directive|endif
ifdef|#
directive|ifdef
name|HAVE_SYSV_TTYS
undef|#
directive|undef
name|HAVE_BSD_TTYS
endif|#
directive|endif
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
name|ERROR
name|no_tty_type_defined
endif|#
directive|endif
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
if|#
directive|if
name|defined
argument_list|(
name|XNTP_AUTO_ENDIAN
argument_list|)
include|#
directive|include
file|<netinet/in.h>
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
define|#
directive|define
name|XNTP_BIG_ENDIAN
endif|#
directive|endif
if|#
directive|if
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
define|#
directive|define
name|XNTP_LITTLE_ENDIAN
endif|#
directive|endif
else|#
directive|else
comment|/* AUTO */
ifdef|#
directive|ifdef
name|WORDS_BIGENDIAN
define|#
directive|define
name|XNTP_BIG_ENDIAN
value|1
else|#
directive|else
define|#
directive|define
name|XNTP_LITTLE_ENDIAN
value|1
endif|#
directive|endif
endif|#
directive|endif
comment|/* AUTO */
endif|#
directive|endif
comment|/* !BIG&& !LITTLE */
comment|/*  * Byte order woes.  The DES code is sensitive to byte order.  This  * used to be resolved by calling ntohl() and htonl() to swap things  * around, but this turned out to be quite costly on Vaxes where those  * things are actual functions.  The code now straightens out byte  * order troubles on its own, with no performance penalty for little  * end first machines, but at great expense to cleanliness.  */
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
comment|/* 	 * Pick one or the other. 	 */
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

