begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Define if on AIX 3.    System headers sometimes define this.    We just want to avoid a redefinition error message.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_comment
comment|/* #undef _ALL_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if type char is unsigned and you are not using gcc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CHAR_UNSIGNED__
end_ifndef

begin_comment
comment|/* #undef __CHAR_UNSIGNED__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef gid_t */
end_comment

begin_comment
comment|/* Define as __inline if that's what the C compiler calls it.  */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* Define if on MINIX.  */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define if your struct nlist has an n_un member.  */
end_comment

begin_comment
comment|/* #undef NLIST_NAME_UNION */
end_comment

begin_comment
comment|/* Define if you have<nlist.h>.  */
end_comment

begin_define
define|#
directive|define
name|NLIST_STRUCT
value|1
end_define

begin_comment
comment|/* Define to `long' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define if the system does not provide POSIX.1 features except    with this defined.  */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define if you need to in order for stat and other things to work.  */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define as the return type of signal handlers (int or void).  */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* Define to `unsigned' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define if you have the ANSI C header files.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if you can safely include both<sys/time.h> and<time.h>.  */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define if your<sys/time.h> declares struct tm.  */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

begin_comment
comment|/* Define if your processor stores words with the most significant    byte first (like Motorola and SPARC, unlike Intel and VAX).  */
end_comment

begin_comment
comment|/* #undef WORDS_BIGENDIAN */
end_comment

begin_comment
comment|/* debugging code */
end_comment

begin_define
define|#
directive|define
name|DEBUG
value|1
end_define

begin_comment
comment|/* Minutes per DST adjustment */
end_comment

begin_define
define|#
directive|define
name|DSTMINUTES
value|60
end_define

begin_comment
comment|/* MD5 authentication */
end_comment

begin_define
define|#
directive|define
name|MD5
value|1
end_define

begin_comment
comment|/* DES authentication (COCOM only) */
end_comment

begin_comment
comment|/* #undef DES */
end_comment

begin_comment
comment|/* time_t */
end_comment

begin_comment
comment|/* #undef time_t */
end_comment

begin_comment
comment|/* reference clock interface */
end_comment

begin_define
define|#
directive|define
name|REFCLOCK
value|1
end_define

begin_comment
comment|/* Audio CHU? */
end_comment

begin_comment
comment|/* #undef AUDIO_CHU */
end_comment

begin_comment
comment|/* PARSE kernel PLL PPS support */
end_comment

begin_comment
comment|/* #undef PPS_SYNC */
end_comment

begin_comment
comment|/* ACTS modem service */
end_comment

begin_comment
comment|/* #undef CLOCK_ACTS */
end_comment

begin_comment
comment|/* Arbiter 1088A/B GPS receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_ARBITER */
end_comment

begin_comment
comment|/* DHD19970505: ARCRON support. */
end_comment

begin_comment
comment|/* #undef CLOCK_ARCRON_MSF */
end_comment

begin_comment
comment|/* Austron 2200A/2201A GPS receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_AS2201 */
end_comment

begin_comment
comment|/* PPS interface */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ATOM
value|1
end_define

begin_comment
comment|/* PPS auxiliary interface for ATOM */
end_comment

begin_define
define|#
directive|define
name|PPS_SAMPLE
value|1
end_define

begin_comment
comment|/* Datum/Bancomm bc635/VME interface */
end_comment

begin_comment
comment|/* #undef CLOCK_BANC */
end_comment

begin_comment
comment|/* Diems Computime Radio Clock */
end_comment

begin_comment
comment|/* #undef CLOCK_COMPUTIME */
end_comment

begin_comment
comment|/* Chronolog K-series WWVB receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_CHRONOLOG */
end_comment

begin_comment
comment|/* Datum Programmable Time System */
end_comment

begin_comment
comment|/* #undef CLOCK_DATUM */
end_comment

begin_comment
comment|/* ELV/DCF7000 clock */
end_comment

begin_comment
comment|/* #undef CLOCK_DCF7000 */
end_comment

begin_comment
comment|/* Dumb generic hh:mm:ss local clock */
end_comment

begin_define
define|#
directive|define
name|CLOCK_DUMBCLOCK
value|1
end_define

begin_comment
comment|/* Forum Graphic GPS datating station driver */
end_comment

begin_comment
comment|/* #undef CLOCK_FG */
end_comment

begin_comment
comment|/* TrueTime GPS receiver/VME interface */
end_comment

begin_comment
comment|/* #undef CLOCK_GPSVME */
end_comment

begin_comment
comment|/* Heath GC-1000 WWV/WWVH receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_HEATH */
end_comment

begin_comment
comment|/* HOPF 6021 clock */
end_comment

begin_comment
comment|/* #undef CLOCK_HOPF6021 */
end_comment

begin_comment
comment|/* HP 58503A GPS receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_HPGPS */
end_comment

begin_comment
comment|/* Sun IRIG audio decoder */
end_comment

begin_comment
comment|/* #undef CLOCK_IRIG */
end_comment

begin_comment
comment|/* Rockwell Jupiter GPS clock */
end_comment

begin_comment
comment|/* #undef CLOCK_JUPITER */
end_comment

begin_comment
comment|/* Leitch CSD 5300 Master Clock System Driver */
end_comment

begin_comment
comment|/* #undef CLOCK_LEITCH */
end_comment

begin_comment
comment|/* local clock reference */
end_comment

begin_define
define|#
directive|define
name|CLOCK_LOCAL
value|1
end_define

begin_comment
comment|/* Meinberg clocks */
end_comment

begin_comment
comment|/* #undef CLOCK_MEINBERG */
end_comment

begin_comment
comment|/* EES M201 MSF receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_MSFEES */
end_comment

begin_comment
comment|/* Magnavox MX4200 GPS receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_MX4200 */
end_comment

begin_comment
comment|/* NMEA GPS receiver */
end_comment

begin_define
define|#
directive|define
name|CLOCK_NMEA
value|1
end_define

begin_comment
comment|/* Motorola UT Oncore GPS */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ONCORE
value|1
end_define

begin_comment
comment|/* Palisade clock */
end_comment

begin_comment
comment|/* #undef CLOCK_PALISADE */
end_comment

begin_comment
comment|/* PARSE driver interface */
end_comment

begin_define
define|#
directive|define
name|CLOCK_PARSE
value|1
end_define

begin_comment
comment|/* Conrad parallel port radio clock */
end_comment

begin_comment
comment|/* #undef CLOCK_PCF */
end_comment

begin_comment
comment|/* PCL 720 clock support */
end_comment

begin_comment
comment|/* #undef CLOCK_PPS720 */
end_comment

begin_comment
comment|/* PST/Traconex 1020 WWV/WWVH receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_PST */
end_comment

begin_comment
comment|/* PTB modem service */
end_comment

begin_comment
comment|/* #undef CLOCK_PTBACTS */
end_comment

begin_comment
comment|/* DCF77 raw time code */
end_comment

begin_define
define|#
directive|define
name|CLOCK_RAWDCF
value|1
end_define

begin_comment
comment|/* RCC 8000 clock */
end_comment

begin_comment
comment|/* #undef CLOCK_RCC8000 */
end_comment

begin_comment
comment|/* Schmid DCF77 clock */
end_comment

begin_comment
comment|/* #undef CLOCK_SCHMID */
end_comment

begin_comment
comment|/* clock thru shared memory */
end_comment

begin_comment
comment|/* #undef CLOCK_SHM */
end_comment

begin_comment
comment|/* Spectracom 8170/Netclock/2 WWVB receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_SPECTRACOM */
end_comment

begin_comment
comment|/* KSI/Odetics TPRO/S GPS receiver/IRIG interface */
end_comment

begin_comment
comment|/* #undef CLOCK_TPRO */
end_comment

begin_comment
comment|/* TRAK 8810 GPS receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_TRAK */
end_comment

begin_comment
comment|/* Trimble GPS receiver/TAIP protocol */
end_comment

begin_comment
comment|/* #undef CLOCK_TRIMTAIP */
end_comment

begin_comment
comment|/* Trimble GPS receiver/TSIP protocol */
end_comment

begin_comment
comment|/* #undef CLOCK_TRIMTSIP */
end_comment

begin_comment
comment|/* Kinemetrics/TrueTime receivers */
end_comment

begin_comment
comment|/* #undef CLOCK_TRUETIME */
end_comment

begin_comment
comment|/* Ultralink M320 WWVB receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_ULINK */
end_comment

begin_comment
comment|/* USNO modem service */
end_comment

begin_comment
comment|/* #undef CLOCK_USNO */
end_comment

begin_comment
comment|/* WHARTON 400A Series protocol */
end_comment

begin_comment
comment|/* #undef CLOCK_WHARTON_400A */
end_comment

begin_comment
comment|/* WWV audio driver */
end_comment

begin_comment
comment|/* #undef CLOCK_WWV */
end_comment

begin_comment
comment|/* VARITEXT protocol */
end_comment

begin_comment
comment|/* #undef CLOCK_VARITEXT */
end_comment

begin_comment
comment|/* define if we need to declare int errno; */
end_comment

begin_comment
comment|/* #undef DECL_ERRNO */
end_comment

begin_comment
comment|/* define if we may declare int h_errno; */
end_comment

begin_define
define|#
directive|define
name|DECL_H_ERRNO
value|1
end_define

begin_comment
comment|/* define if it's OK to declare char *sys_errlist[]; */
end_comment

begin_comment
comment|/* #undef CHAR_SYS_ERRLIST */
end_comment

begin_comment
comment|/* define if it's OK to declare int syscall P((int, struct timeval *, struct timeval *)); */
end_comment

begin_define
define|#
directive|define
name|DECL_SYSCALL
value|1
end_define

begin_comment
comment|/* define if we have syscall is buggy (Solaris 2.4) */
end_comment

begin_comment
comment|/* #undef SYSCALL_BUG */
end_comment

begin_comment
comment|/* Do we need extra room for SO_RCVBUF? (HPUX<8) */
end_comment

begin_comment
comment|/* #undef NEED_RCVBUF_SLOP */
end_comment

begin_comment
comment|/* Should we open the broadcast socket? */
end_comment

begin_define
define|#
directive|define
name|OPEN_BCAST_SOCKET
value|1
end_define

begin_comment
comment|/* Do we want the HPUX FindConfig()? */
end_comment

begin_comment
comment|/* #undef NEED_HPUX_FINDCONFIG */
end_comment

begin_comment
comment|/* canonical system (cpu-vendor-os) string */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"alpha-unknown-freebsd"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"i386-unknown-freebsd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* define if NetInfo support is available */
end_comment

begin_comment
comment|/* #undef HAVE_NETINFO */
end_comment

begin_comment
comment|/* define if [gs]ettimeofday() only takes 1 argument */
end_comment

begin_comment
comment|/* #undef SYSV_TIMEOFDAY */
end_comment

begin_comment
comment|/* define if struct sockaddr has sa_len */
end_comment

begin_define
define|#
directive|define
name|HAVE_SA_LEN_IN_STRUCT_SOCKADDR
value|1
end_define

begin_comment
comment|/* define if struct clockinfo has hz */
end_comment

begin_define
define|#
directive|define
name|HAVE_HZ_IN_STRUCT_CLOCKINFO
value|1
end_define

begin_comment
comment|/* define if struct sigaction has sa_sigaction */
end_comment

begin_define
define|#
directive|define
name|HAVE_SA_SIGACTION_IN_STRUCT_SIGACTION
value|1
end_define

begin_comment
comment|/* define if struct clockinfo has tickadj */
end_comment

begin_define
define|#
directive|define
name|HAVE_TICKADJ_IN_STRUCT_CLOCKINFO
value|1
end_define

begin_comment
comment|/* define if struct ntptimeval uses time.tv_nsec instead of time.tv_usec */
end_comment

begin_define
define|#
directive|define
name|HAVE_TV_NSEC_IN_NTPTIMEVAL
value|1
end_define

begin_comment
comment|/* Does a system header defind struct ppsclockev? */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_PPSCLOCKEV */
end_comment

begin_comment
comment|/* define if function prototypes are OK */
end_comment

begin_define
define|#
directive|define
name|HAVE_PROTOTYPES
value|1
end_define

begin_comment
comment|/* define if setpgrp takes 0 arguments */
end_comment

begin_comment
comment|/* #undef HAVE_SETPGRP_0 */
end_comment

begin_comment
comment|/* hardwire a value for tick? */
end_comment

begin_define
define|#
directive|define
name|PRESET_TICK
value|1000000L/hz
end_define

begin_comment
comment|/* hardwire a value for tickadj? */
end_comment

begin_define
define|#
directive|define
name|PRESET_TICKADJ
value|500/hz
end_define

begin_comment
comment|/* is adjtime() accurate? */
end_comment

begin_comment
comment|/* #undef ADJTIME_IS_ACCURATE */
end_comment

begin_comment
comment|/* should we NOT read /dev/kmem? */
end_comment

begin_comment
comment|/* #undef NOKMEM */
end_comment

begin_comment
comment|/* use UDP Wildcard Delivery? */
end_comment

begin_define
define|#
directive|define
name|UDP_WILDCARD_DELIVERY
value|1
end_define

begin_comment
comment|/* always slew the clock? */
end_comment

begin_comment
comment|/* #undef SLEWALWAYS */
end_comment

begin_comment
comment|/* step, then slew the clock? */
end_comment

begin_comment
comment|/* #undef STEP_SLEW */
end_comment

begin_comment
comment|/* force ntpdate to step the clock if !defined(STEP_SLEW) ? */
end_comment

begin_comment
comment|/* #undef FORCE_NTPDATE_STEP */
end_comment

begin_comment
comment|/* synch TODR hourly? */
end_comment

begin_comment
comment|/* #undef DOSYNCTODR */
end_comment

begin_comment
comment|/* do we set process groups with -pid? */
end_comment

begin_comment
comment|/* #undef UDP_BACKWARDS_SETOWN */
end_comment

begin_comment
comment|/* must we have a CTTY for fsetown? */
end_comment

begin_define
define|#
directive|define
name|USE_FSETOWNCTTY
value|1
end_define

begin_comment
comment|/* can we use SIGIO for tcp and udp IO? */
end_comment

begin_comment
comment|/* #undef HAVE_SIGNALED_IO */
end_comment

begin_comment
comment|/* can we use SIGPOLL for UDP? */
end_comment

begin_comment
comment|/* #undef USE_UDP_SIGPOLL */
end_comment

begin_comment
comment|/* can we use SIGPOLL for tty IO? */
end_comment

begin_comment
comment|/* #undef USE_TTY_SIGPOLL */
end_comment

begin_comment
comment|/* do we want the CHU driver? */
end_comment

begin_comment
comment|/* #undef CLOCK_CHU */
end_comment

begin_comment
comment|/* do we have the ppsclock streams module? */
end_comment

begin_comment
comment|/* #undef PPS */
end_comment

begin_comment
comment|/* do we have the tty_clk line discipline/streams module? */
end_comment

begin_comment
comment|/* #undef TTYCLK */
end_comment

begin_comment
comment|/* does the kernel support precision time discipline? */
end_comment

begin_define
define|#
directive|define
name|KERNEL_PLL
value|1
end_define

begin_comment
comment|/* does the kernel support multicasting IP? */
end_comment

begin_define
define|#
directive|define
name|MCAST
value|1
end_define

begin_comment
comment|/* do we have ntp_{adj,get}time in libc? */
end_comment

begin_define
define|#
directive|define
name|NTP_SYSCALLS_LIBC
value|1
end_define

begin_comment
comment|/* do we have ntp_{adj,get}time in the kernel? */
end_comment

begin_comment
comment|/* #undef NTP_SYSCALLS_STD */
end_comment

begin_comment
comment|/* do we have STREAMS/TLI? (Can we replace this with HAVE_SYS_STROPTS_H? */
end_comment

begin_comment
comment|/* #undef STREAMS_TLI */
end_comment

begin_comment
comment|/* do we need an s_char typedef? */
end_comment

begin_define
define|#
directive|define
name|NEED_S_CHAR_TYPEDEF
value|1
end_define

begin_comment
comment|/* does SIOCGIFCONF return size in the buffer? */
end_comment

begin_comment
comment|/* #undef SIZE_RETURNED_IN_BUFFER */
end_comment

begin_comment
comment|/* what is the name of TICK in the kernel? */
end_comment

begin_define
define|#
directive|define
name|K_TICK_NAME
value|"_tick"
end_define

begin_comment
comment|/* Is K_TICK_NAME (nsec_per_tick, for example) in nanoseconds? */
end_comment

begin_comment
comment|/* #undef TICK_NANO */
end_comment

begin_comment
comment|/* what is the name of TICKADJ in the kernel? */
end_comment

begin_define
define|#
directive|define
name|K_TICKADJ_NAME
value|"_tickadj"
end_define

begin_comment
comment|/* Is K_TICKADJ_NAME (hrestime_adj, for example) in nanoseconds? */
end_comment

begin_comment
comment|/* #undef TICKADJ_NANO */
end_comment

begin_comment
comment|/* what is (probably) the name of DOSYNCTODR in the kernel? */
end_comment

begin_define
define|#
directive|define
name|K_DOSYNCTODR_NAME
value|"_dosynctodr"
end_define

begin_comment
comment|/* what is (probably) the name of NOPRINTF in the kernel? */
end_comment

begin_define
define|#
directive|define
name|K_NOPRINTF_NAME
value|"_noprintf"
end_define

begin_comment
comment|/* do we need HPUX adjtime() library support? */
end_comment

begin_comment
comment|/* #undef NEED_HPUX_ADJTIME */
end_comment

begin_comment
comment|/* Might nlist() values require an extra level of indirection (AIX)? */
end_comment

begin_comment
comment|/* #undef NLIST_EXTRA_INDIRECTION */
end_comment

begin_comment
comment|/* Other needed NLIST stuff */
end_comment

begin_define
define|#
directive|define
name|NLIST_STRUCT
value|1
end_define

begin_comment
comment|/* #undef NLIST_NAME_UNION */
end_comment

begin_comment
comment|/* Should we recommend a minimum value for tickadj? */
end_comment

begin_comment
comment|/* #undef MIN_REC_TICKADJ */
end_comment

begin_comment
comment|/* Is there a problem using PARENB and IGNPAR (IRIX)? */
end_comment

begin_define
define|#
directive|define
name|NO_PARENB_IGNPAR
value|1
end_define

begin_comment
comment|/* Should we not IGNPAR (Linux)? */
end_comment

begin_comment
comment|/* #undef RAWDCF_NO_IGNPAR */
end_comment

begin_comment
comment|/* Does the compiler like "volatile"? */
end_comment

begin_comment
comment|/* #undef volatile */
end_comment

begin_comment
comment|/* Does qsort expect to work on "void *" stuff? */
end_comment

begin_define
define|#
directive|define
name|QSORT_USES_VOID_P
value|1
end_define

begin_comment
comment|/* What is the fallback value for HZ? */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_HZ
value|100
end_define

begin_comment
comment|/* Do we need to override the system's idea of HZ? */
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_HZ
value|1
end_define

begin_comment
comment|/* Do we want the SCO clock hacks? */
end_comment

begin_comment
comment|/* #undef SCO5_CLOCK */
end_comment

begin_comment
comment|/* Do we want the ReliantUNIX clock hacks? */
end_comment

begin_comment
comment|/* #undef RELIANTUNIX_CLOCK */
end_comment

begin_comment
comment|/* Does the kernel have an FLL bug? */
end_comment

begin_comment
comment|/* #undef KERNEL_FLL_BUG */
end_comment

begin_comment
comment|/* Define if you have the TIOCGPPSEV ioctl (Solaris) */
end_comment

begin_comment
comment|/* #undef HAVE_TIOCGPPSEV */
end_comment

begin_comment
comment|/* Define if you have the TIOCSPPS ioctl (Solaris) */
end_comment

begin_comment
comment|/* #undef HAVE_TIOCSPPS */
end_comment

begin_comment
comment|/* Define if you have the CIOGETEV ioctl (SunOS, Linux) */
end_comment

begin_comment
comment|/* #undef HAVE_CIOGETEV */
end_comment

begin_comment
comment|/* Define if you have the TIOCGSERIAL, TIOCSSERIAL, ASYNC_PPS_CD_POS, and ASYNC_PPS_CD_NEG ioctls (linux) */
end_comment

begin_comment
comment|/* #undef HAVE_TIO_SERIAL_STUFF */
end_comment

begin_comment
comment|/* Define if you use struct timespec rather than struct timeval (time in ns rather than us) */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMESPEC
value|1
end_define

begin_comment
comment|/* Define if you have the interface in the Draft RFC */
end_comment

begin_define
define|#
directive|define
name|HAVE_PPSAPI
value|1
end_define

begin_comment
comment|/* Do we need to #define _SVID3 when we #include<termios.h>? */
end_comment

begin_comment
comment|/* #undef TERMIOS_NEEDS__SVID3 */
end_comment

begin_comment
comment|/* Do we have support for SHMEM_STATUS? */
end_comment

begin_define
define|#
directive|define
name|ONCORE_SHMEM_STATUS
value|1
end_define

begin_comment
comment|/* adjtime()? */
end_comment

begin_comment
comment|/* #undef DECL_ADJTIME_0 */
end_comment

begin_comment
comment|/* bcopy()? */
end_comment

begin_comment
comment|/* #undef DECL_BCOPY_0 */
end_comment

begin_comment
comment|/* bzero()? */
end_comment

begin_comment
comment|/* #undef DECL_BZERO_0 */
end_comment

begin_comment
comment|/* cfset[io]speed()? */
end_comment

begin_comment
comment|/* #undef DECL_CFSETISPEED_0 */
end_comment

begin_comment
comment|/* ioctl()? */
end_comment

begin_comment
comment|/* #undef DECL_IOCTL_0 */
end_comment

begin_comment
comment|/* IPC? (bind, connect, recvfrom, sendto, setsockopt, socket) */
end_comment

begin_comment
comment|/* #undef DECL_IPC_0 */
end_comment

begin_comment
comment|/* memmove()? */
end_comment

begin_comment
comment|/* #undef DECL_MEMMOVE_0 */
end_comment

begin_comment
comment|/* mkstemp()? */
end_comment

begin_comment
comment|/* #undef DECL_MKSTEMP_0 */
end_comment

begin_comment
comment|/* mktemp()? */
end_comment

begin_comment
comment|/* #undef DECL_MKTEMP_0 */
end_comment

begin_comment
comment|/* mrand48()? */
end_comment

begin_comment
comment|/* #undef DECL_MRAND48_0 */
end_comment

begin_comment
comment|/* nlist()? */
end_comment

begin_comment
comment|/* #undef DECL_NLIST_0 */
end_comment

begin_comment
comment|/* plock()? */
end_comment

begin_comment
comment|/* #undef DECL_PLOCK_0 */
end_comment

begin_comment
comment|/* rename()? */
end_comment

begin_comment
comment|/* #undef DECL_RENAME_0 */
end_comment

begin_comment
comment|/* select()? */
end_comment

begin_comment
comment|/* #undef DECL_SELECT_0 */
end_comment

begin_comment
comment|/* setitimer()? */
end_comment

begin_comment
comment|/* #undef DECL_SETITIMER_0 */
end_comment

begin_comment
comment|/* setpriority()? */
end_comment

begin_comment
comment|/* #undef DECL_SETPRIORITY_0 */
end_comment

begin_comment
comment|/* #undef DECL_SETPRIORITY_1 */
end_comment

begin_comment
comment|/* sigvec()? */
end_comment

begin_comment
comment|/* #undef DECL_SIGVEC_0 */
end_comment

begin_comment
comment|/* srand48()? */
end_comment

begin_comment
comment|/* #undef DECL_SRAND48_0 */
end_comment

begin_comment
comment|/* stdio stuff? */
end_comment

begin_comment
comment|/* #undef DECL_STDIO_0 */
end_comment

begin_comment
comment|/* stime()? */
end_comment

begin_comment
comment|/* #undef DECL_STIME_0 */
end_comment

begin_comment
comment|/* #undef DECL_STIME_1 */
end_comment

begin_comment
comment|/* strtol()? */
end_comment

begin_comment
comment|/* #undef DECL_STRTOL_0 */
end_comment

begin_comment
comment|/* syslog() stuff? */
end_comment

begin_comment
comment|/* #undef DECL_SYSLOG_0 */
end_comment

begin_comment
comment|/* time()? */
end_comment

begin_comment
comment|/* #undef DECL_TIME_0 */
end_comment

begin_comment
comment|/* [gs]ettimeofday()? */
end_comment

begin_comment
comment|/* #undef DECL_TIMEOFDAY_0 */
end_comment

begin_comment
comment|/* tolower()? */
end_comment

begin_comment
comment|/* #undef DECL_TOLOWER_0 */
end_comment

begin_comment
comment|/* toupper()? */
end_comment

begin_comment
comment|/* #undef DECL_TOUPPER_0 */
end_comment

begin_comment
comment|/* The number of bytes in a int.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_INT
value|4
end_define

begin_comment
comment|/* The number of bytes in a long.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__alpha__
end_ifdef

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The number of bytes in a signed char.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_SIGNED_CHAR
value|1
end_define

begin_comment
comment|/* Define if you have the K_open function.  */
end_comment

begin_comment
comment|/* #undef HAVE_K_OPEN */
end_comment

begin_comment
comment|/* Define if you have the __adjtimex function.  */
end_comment

begin_comment
comment|/* #undef HAVE___ADJTIMEX */
end_comment

begin_comment
comment|/* Define if you have the __ntp_gettime function.  */
end_comment

begin_comment
comment|/* #undef HAVE___NTP_GETTIME */
end_comment

begin_comment
comment|/* Define if you have the clock_settime function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK_SETTIME
value|1
end_define

begin_comment
comment|/* Define if you have the daemon function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DAEMON
value|1
end_define

begin_comment
comment|/* Define if you have the getbootfile function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETBOOTFILE
value|1
end_define

begin_comment
comment|/* Define if you have the getdtablesize function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETDTABLESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the getrusage function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRUSAGE
value|1
end_define

begin_comment
comment|/* Define if you have the gettimeofday function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define if you have the getuid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUID
value|1
end_define

begin_comment
comment|/* Define if you have the kvm_open function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_KVM_OPEN
value|1
end_define

begin_comment
comment|/* Define if you have the memcpy function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCPY
value|1
end_define

begin_comment
comment|/* Define if you have the memlk function.  */
end_comment

begin_comment
comment|/* #undef HAVE_MEMLK */
end_comment

begin_comment
comment|/* Define if you have the memmove function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_comment
comment|/* Define if you have the memset function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_comment
comment|/* Define if you have the mkstemp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define if you have the mktime function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKTIME
value|1
end_define

begin_comment
comment|/* Define if you have the mlockall function.  */
end_comment

begin_comment
comment|/* #undef HAVE_MLOCKALL */
end_comment

begin_comment
comment|/* Define if you have the mrand48 function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MRAND48
value|1
end_define

begin_comment
comment|/* Define if you have the nice function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NICE
value|1
end_define

begin_comment
comment|/* Define if you have the nlist function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NLIST
value|1
end_define

begin_comment
comment|/* Define if you have the ntp_adjtime function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NTP_ADJTIME
value|1
end_define

begin_comment
comment|/* Define if you have the ntp_gettime function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NTP_GETTIME
value|1
end_define

begin_comment
comment|/* Define if you have the plock function.  */
end_comment

begin_comment
comment|/* #undef HAVE_PLOCK */
end_comment

begin_comment
comment|/* Define if you have the pututline function.  */
end_comment

begin_comment
comment|/* #undef HAVE_PUTUTLINE */
end_comment

begin_comment
comment|/* Define if you have the pututxline function.  */
end_comment

begin_comment
comment|/* #undef HAVE_PUTUTXLINE */
end_comment

begin_comment
comment|/* Define if you have the random function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RANDOM
value|1
end_define

begin_comment
comment|/* Define if you have the rtprio function.  */
end_comment

begin_comment
comment|/* #undef HAVE_RTPRIO 1 */
end_comment

begin_comment
comment|/* Define if you have the sched_setscheduler function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SCHED_SETSCHEDULER 1 */
end_comment

begin_comment
comment|/* Define if you have the setlinebuf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
value|1
end_define

begin_comment
comment|/* Define if you have the setpgid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPGID
value|1
end_define

begin_comment
comment|/* Define if you have the setpriority function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPRIORITY
value|1
end_define

begin_comment
comment|/* Define if you have the setsid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSID
value|1
end_define

begin_comment
comment|/* Define if you have the settimeofday function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define if you have the setvbuf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETVBUF
value|1
end_define

begin_comment
comment|/* Define if you have the sigaction function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Define if you have the sigset function.  */
end_comment

begin_comment
comment|/* #undef HAVE_SIGSET */
end_comment

begin_comment
comment|/* Define if you have the sigsuspend function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSUSPEND
value|1
end_define

begin_comment
comment|/* Define if you have the sigvec function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGVEC
value|1
end_define

begin_comment
comment|/* Define if you have the srand48 function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SRAND48
value|1
end_define

begin_comment
comment|/* Define if you have the srandom function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SRANDOM
value|1
end_define

begin_comment
comment|/* Define if you have the stime function.  */
end_comment

begin_comment
comment|/* #undef HAVE_STIME */
end_comment

begin_comment
comment|/* Define if you have the strchr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define if you have the strerror function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the sysconf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_comment
comment|/* Define if you have the sysctl function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCTL
value|1
end_define

begin_comment
comment|/* Define if you have the timer_create function.  */
end_comment

begin_comment
comment|/* #undef HAVE_TIMER_CREATE */
end_comment

begin_comment
comment|/* Define if you have the timer_settime function.  */
end_comment

begin_comment
comment|/* #undef HAVE_TIMER_SETTIME */
end_comment

begin_comment
comment|/* Define if you have the umask function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UMASK
value|1
end_define

begin_comment
comment|/* Define if you have the uname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNAME
value|1
end_define

begin_comment
comment|/* Define if you have the updwtmp function.  */
end_comment

begin_comment
comment|/* #undef HAVE_UPDWTMP */
end_comment

begin_comment
comment|/* Define if you have the updwtmpx function.  */
end_comment

begin_comment
comment|/* #undef HAVE_UPDWTMPX */
end_comment

begin_comment
comment|/* Define if you have the vsprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the</sys/sync/queue.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE__SYS_SYNC_QUEUE_H */
end_comment

begin_comment
comment|/* Define if you have the</sys/sync/sema.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE__SYS_SYNC_SEMA_H */
end_comment

begin_comment
comment|/* Define if you have the<arpa/nameser.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_NAMESER_H
value|1
end_define

begin_comment
comment|/* Define if you have the<bstring.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_BSTRING_H */
end_comment

begin_comment
comment|/* Define if you have the<errno.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<fcntl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<machine/inline.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_MACHINE_INLINE_H */
end_comment

begin_comment
comment|/* Define if you have the<memory.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define if you have the<net/if.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_IF_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netdb.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet/in.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinet/in_systm.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_SYSTM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<netinfo/ni.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NETINFO_NI_H */
end_comment

begin_comment
comment|/* Define if you have the<poll.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<resolv.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RESOLV_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sched.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SCHED_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sgtty.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SGTTY_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdlib.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sun/audioio.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SUN_AUDIOIO_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/audioio.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_AUDIOIO_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/clkdefs.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_CLKDEFS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/file.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/i8253.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_I8253_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/ioctl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/lock.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_LOCK_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/mman.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MMAN_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/modem.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_MODEM_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/param.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/pcl720.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PCL720_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/ppsclock.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PPSCLOCK_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/ppstime.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PPSTIME_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/proc.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PROC_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/resource.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/sched.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SCHED_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/select.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/sio.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SIO_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/sockio.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stat.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stream.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STREAM_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/stropts.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STROPTS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/sysctl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/syssgi.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SYSSGI_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/termios.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/timepps.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEPPS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/timers.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMERS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/timex.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEX_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/tpro.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TPRO_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/wait.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<termio.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_TERMIO_H */
end_comment

begin_comment
comment|/* Define if you have the<termios.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<timepps.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_TIMEPPS_H */
end_comment

begin_comment
comment|/* Define if you have the<timex.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_TIMEX_H */
end_comment

begin_comment
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if you have the<utmp.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTMP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<utmpx.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_UTMPX_H */
end_comment

begin_comment
comment|/* Define if you have the advapi32 library (-ladvapi32).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBADVAPI32 */
end_comment

begin_comment
comment|/* Define if you have the elf library (-lelf).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBELF */
end_comment

begin_comment
comment|/* Define if you have the gen library (-lgen).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBGEN */
end_comment

begin_comment
comment|/* Define if you have the kvm library (-lkvm).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBKVM
value|1
end_define

begin_comment
comment|/* Define if you have the ld library (-lld).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBLD */
end_comment

begin_comment
comment|/* Define if you have the mld library (-lmld).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBMLD */
end_comment

begin_comment
comment|/* Define if you have the nsl library (-lnsl).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBNSL */
end_comment

begin_comment
comment|/* Define if you have the rt library (-lrt).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBRT */
end_comment

begin_comment
comment|/* Define if you have the socket library (-lsocket).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSOCKET */
end_comment

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"ntp"
end_define

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"4.0.99b"
end_define

begin_comment
comment|/* Define if compiler has function prototypes */
end_comment

begin_define
define|#
directive|define
name|PROTOTYPES
value|1
end_define

begin_comment
comment|/* Do we have struct ntptimeval? */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_NTPTIMEVAL
value|1
end_define

begin_comment
comment|/* Does ntptimeval use struct timespec? */
end_comment

begin_define
define|#
directive|define
name|TIMESPEC_IN_NTPTIMEVAL
value|1
end_define

end_unit

