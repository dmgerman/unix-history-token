begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* debugging code */
end_comment

begin_undef
undef|#
directive|undef
name|DEBUG
end_undef

begin_comment
comment|/* Minutes per DST adjustment */
end_comment

begin_undef
undef|#
directive|undef
name|DSTMINUTES
end_undef

begin_comment
comment|/* MD5 authentication */
end_comment

begin_undef
undef|#
directive|undef
name|MD5
end_undef

begin_comment
comment|/* DES authentication (COCOM only) */
end_comment

begin_undef
undef|#
directive|undef
name|DES
end_undef

begin_comment
comment|/* time_t */
end_comment

begin_undef
undef|#
directive|undef
name|time_t
end_undef

begin_comment
comment|/* reference clock interface */
end_comment

begin_undef
undef|#
directive|undef
name|REFCLOCK
end_undef

begin_comment
comment|/* Audio CHU? */
end_comment

begin_undef
undef|#
directive|undef
name|AUDIO_CHU
end_undef

begin_comment
comment|/* PARSE kernel PLL PPS support */
end_comment

begin_undef
undef|#
directive|undef
name|PPS_SYNC
end_undef

begin_comment
comment|/* ACTS modem service */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_ACTS
end_undef

begin_comment
comment|/* Arbiter 1088A/B GPS receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_ARBITER
end_undef

begin_comment
comment|/* DHD19970505: ARCRON support. */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_ARCRON_MSF
end_undef

begin_comment
comment|/* Austron 2200A/2201A GPS receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_AS2201
end_undef

begin_comment
comment|/* PPS interface */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_ATOM
end_undef

begin_comment
comment|/* PPS auxiliary interface for ATOM */
end_comment

begin_undef
undef|#
directive|undef
name|PPS_SAMPLE
end_undef

begin_comment
comment|/* Datum/Bancomm bc635/VME interface */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_BANC
end_undef

begin_comment
comment|/* Diems Computime Radio Clock */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_COMPUTIME
end_undef

begin_comment
comment|/* Chronolog K-series WWVB receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_CHRONOLOG
end_undef

begin_comment
comment|/* Datum Programmable Time System */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_DATUM
end_undef

begin_comment
comment|/* ELV/DCF7000 clock */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_DCF7000
end_undef

begin_comment
comment|/* Dumb generic hh:mm:ss local clock */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_DUMBCLOCK
end_undef

begin_comment
comment|/* Forum Graphic GPS datating station driver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_FG
end_undef

begin_comment
comment|/* TrueTime GPS receiver/VME interface */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_GPSVME
end_undef

begin_comment
comment|/* Heath GC-1000 WWV/WWVH receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_HEATH
end_undef

begin_comment
comment|/* HOPF 6021 clock */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_HOPF6021
end_undef

begin_comment
comment|/* HOPF PCI clock device */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_HOPF_PCI
end_undef

begin_comment
comment|/* HOPF serial clock device*/
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_HOPF_SERIAL
end_undef

begin_comment
comment|/* HP 58503A GPS receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_HPGPS
end_undef

begin_comment
comment|/* Sun IRIG audio decoder */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_IRIG
end_undef

begin_comment
comment|/* Rockwell Jupiter GPS clock */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_JUPITER
end_undef

begin_comment
comment|/* Leitch CSD 5300 Master Clock System Driver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_LEITCH
end_undef

begin_comment
comment|/* local clock reference */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_LOCAL
end_undef

begin_comment
comment|/* Meinberg clocks */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_MEINBERG
end_undef

begin_comment
comment|/* EES M201 MSF receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_MSFEES
end_undef

begin_comment
comment|/* Magnavox MX4200 GPS receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_MX4200
end_undef

begin_comment
comment|/* NMEA GPS receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_NMEA
end_undef

begin_comment
comment|/* Motorola UT Oncore GPS */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_ONCORE
end_undef

begin_comment
comment|/* Palisade clock */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_PALISADE
end_undef

begin_comment
comment|/* PARSE driver interface */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_PARSE
end_undef

begin_comment
comment|/* Conrad parallel port radio clock */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_PCF
end_undef

begin_comment
comment|/* PCL 720 clock support */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_PPS720
end_undef

begin_comment
comment|/* PST/Traconex 1020 WWV/WWVH receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_PST
end_undef

begin_comment
comment|/* PTB modem service */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_PTBACTS
end_undef

begin_comment
comment|/* DCF77 raw time code */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_RAWDCF
end_undef

begin_comment
comment|/* RCC 8000 clock */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_RCC8000
end_undef

begin_comment
comment|/* Schmid DCF77 clock */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_SCHMID
end_undef

begin_comment
comment|/* clock thru shared memory */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_SHM
end_undef

begin_comment
comment|/* Spectracom 8170/Netclock/2 WWVB receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_SPECTRACOM
end_undef

begin_comment
comment|/* KSI/Odetics TPRO/S GPS receiver/IRIG interface */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_TPRO
end_undef

begin_comment
comment|/* TRAK 8810 GPS receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_TRAK
end_undef

begin_comment
comment|/* Trimble GPS receiver/TAIP protocol */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_TRIMTAIP
end_undef

begin_comment
comment|/* Trimble GPS receiver/TSIP protocol */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_TRIMTSIP
end_undef

begin_comment
comment|/* Kinemetrics/TrueTime receivers */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_TRUETIME
end_undef

begin_comment
comment|/* Ultralink M320 WWVB receiver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_ULINK
end_undef

begin_comment
comment|/* USNO modem service */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_USNO
end_undef

begin_comment
comment|/* WHARTON 400A Series protocol */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_WHARTON_400A
end_undef

begin_comment
comment|/* WWV audio driver */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_WWV
end_undef

begin_comment
comment|/* VARITEXT protocol */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_VARITEXT
end_undef

begin_comment
comment|/* define if we need to declare int errno; */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_ERRNO
end_undef

begin_comment
comment|/* define if we may declare int h_errno; */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_H_ERRNO
end_undef

begin_comment
comment|/* define if it's OK to declare char *sys_errlist[]; */
end_comment

begin_undef
undef|#
directive|undef
name|CHAR_SYS_ERRLIST
end_undef

begin_comment
comment|/* define if it's OK to declare int syscall P((int, struct timeval *, struct timeval *)); */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_SYSCALL
end_undef

begin_comment
comment|/* define if we have syscall is buggy (Solaris 2.4) */
end_comment

begin_undef
undef|#
directive|undef
name|SYSCALL_BUG
end_undef

begin_comment
comment|/* Do we need extra room for SO_RCVBUF? (HPUX<8) */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_RCVBUF_SLOP
end_undef

begin_comment
comment|/* Should we open the broadcast socket? */
end_comment

begin_undef
undef|#
directive|undef
name|OPEN_BCAST_SOCKET
end_undef

begin_comment
comment|/* Do we want the HPUX FindConfig()? */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_HPUX_FINDCONFIG
end_undef

begin_comment
comment|/* canonical system (cpu-vendor-os) string */
end_comment

begin_undef
undef|#
directive|undef
name|STR_SYSTEM
end_undef

begin_comment
comment|/* define if NetInfo support is available */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_NETINFO
end_undef

begin_comment
comment|/* define if [gs]ettimeofday() only takes 1 argument */
end_comment

begin_undef
undef|#
directive|undef
name|SYSV_TIMEOFDAY
end_undef

begin_comment
comment|/* define if struct sockaddr has sa_len */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SA_LEN_IN_STRUCT_SOCKADDR
end_undef

begin_comment
comment|/* define if struct clockinfo has hz */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_HZ_IN_STRUCT_CLOCKINFO
end_undef

begin_comment
comment|/* define if struct sigaction has sa_sigaction */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SA_SIGACTION_IN_STRUCT_SIGACTION
end_undef

begin_comment
comment|/* define if struct clockinfo has tickadj */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TICKADJ_IN_STRUCT_CLOCKINFO
end_undef

begin_comment
comment|/* define if struct ntptimeval uses time.tv_nsec instead of time.tv_usec */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TV_NSEC_IN_NTPTIMEVAL
end_undef

begin_comment
comment|/* Does a system header defind struct ppsclockev? */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRUCT_PPSCLOCKEV
end_undef

begin_comment
comment|/* define if function prototypes are OK */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PROTOTYPES
end_undef

begin_comment
comment|/* define if setpgrp takes 0 arguments */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SETPGRP_0
end_undef

begin_comment
comment|/* hardwire a value for tick? */
end_comment

begin_undef
undef|#
directive|undef
name|PRESET_TICK
end_undef

begin_comment
comment|/* hardwire a value for tickadj? */
end_comment

begin_undef
undef|#
directive|undef
name|PRESET_TICKADJ
end_undef

begin_comment
comment|/* is adjtime() accurate? */
end_comment

begin_undef
undef|#
directive|undef
name|ADJTIME_IS_ACCURATE
end_undef

begin_comment
comment|/* should we NOT read /dev/kmem? */
end_comment

begin_undef
undef|#
directive|undef
name|NOKMEM
end_undef

begin_comment
comment|/* use UDP Wildcard Delivery? */
end_comment

begin_undef
undef|#
directive|undef
name|UDP_WILDCARD_DELIVERY
end_undef

begin_comment
comment|/* always slew the clock? */
end_comment

begin_undef
undef|#
directive|undef
name|SLEWALWAYS
end_undef

begin_comment
comment|/* step, then slew the clock? */
end_comment

begin_undef
undef|#
directive|undef
name|STEP_SLEW
end_undef

begin_comment
comment|/* force ntpdate to step the clock if !defined(STEP_SLEW) ? */
end_comment

begin_undef
undef|#
directive|undef
name|FORCE_NTPDATE_STEP
end_undef

begin_comment
comment|/* synch TODR hourly? */
end_comment

begin_undef
undef|#
directive|undef
name|DOSYNCTODR
end_undef

begin_comment
comment|/* do we set process groups with -pid? */
end_comment

begin_undef
undef|#
directive|undef
name|UDP_BACKWARDS_SETOWN
end_undef

begin_comment
comment|/* must we have a CTTY for fsetown? */
end_comment

begin_undef
undef|#
directive|undef
name|USE_FSETOWNCTTY
end_undef

begin_comment
comment|/* can we use SIGIO for tcp and udp IO? */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SIGNALED_IO
end_undef

begin_comment
comment|/* can we use SIGPOLL for UDP? */
end_comment

begin_undef
undef|#
directive|undef
name|USE_UDP_SIGPOLL
end_undef

begin_comment
comment|/* can we use SIGPOLL for tty IO? */
end_comment

begin_undef
undef|#
directive|undef
name|USE_TTY_SIGPOLL
end_undef

begin_comment
comment|/* should we use clock_settime()? */
end_comment

begin_undef
undef|#
directive|undef
name|USE_CLOCK_SETTIME
end_undef

begin_comment
comment|/* do we want the CHU driver? */
end_comment

begin_undef
undef|#
directive|undef
name|CLOCK_CHU
end_undef

begin_comment
comment|/* do we have the ppsclock streams module? */
end_comment

begin_undef
undef|#
directive|undef
name|PPS
end_undef

begin_comment
comment|/* do we have the tty_clk line discipline/streams module? */
end_comment

begin_undef
undef|#
directive|undef
name|TTYCLK
end_undef

begin_comment
comment|/* does the kernel support precision time discipline? */
end_comment

begin_undef
undef|#
directive|undef
name|KERNEL_PLL
end_undef

begin_comment
comment|/* does the kernel support multicasting IP? */
end_comment

begin_undef
undef|#
directive|undef
name|MCAST
end_undef

begin_comment
comment|/* do we have ntp_{adj,get}time in libc? */
end_comment

begin_undef
undef|#
directive|undef
name|NTP_SYSCALLS_LIBC
end_undef

begin_comment
comment|/* do we have ntp_{adj,get}time in the kernel? */
end_comment

begin_undef
undef|#
directive|undef
name|NTP_SYSCALLS_STD
end_undef

begin_comment
comment|/* do we have STREAMS/TLI? (Can we replace this with HAVE_SYS_STROPTS_H? */
end_comment

begin_undef
undef|#
directive|undef
name|STREAMS_TLI
end_undef

begin_comment
comment|/* do we need an s_char typedef? */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_S_CHAR_TYPEDEF
end_undef

begin_comment
comment|/* include the GDT Surveying code? */
end_comment

begin_undef
undef|#
directive|undef
name|GDT_SURVEYING
end_undef

begin_comment
comment|/* does SIOCGIFCONF return size in the buffer? */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_RETURNED_IN_BUFFER
end_undef

begin_comment
comment|/* what is the name of TICK in the kernel? */
end_comment

begin_undef
undef|#
directive|undef
name|K_TICK_NAME
end_undef

begin_comment
comment|/* Is K_TICK_NAME (nsec_per_tick, for example) in nanoseconds? */
end_comment

begin_undef
undef|#
directive|undef
name|TICK_NANO
end_undef

begin_comment
comment|/* what is the name of TICKADJ in the kernel? */
end_comment

begin_undef
undef|#
directive|undef
name|K_TICKADJ_NAME
end_undef

begin_comment
comment|/* Is K_TICKADJ_NAME (hrestime_adj, for example) in nanoseconds? */
end_comment

begin_undef
undef|#
directive|undef
name|TICKADJ_NANO
end_undef

begin_comment
comment|/* what is (probably) the name of DOSYNCTODR in the kernel? */
end_comment

begin_undef
undef|#
directive|undef
name|K_DOSYNCTODR_NAME
end_undef

begin_comment
comment|/* what is (probably) the name of NOPRINTF in the kernel? */
end_comment

begin_undef
undef|#
directive|undef
name|K_NOPRINTF_NAME
end_undef

begin_comment
comment|/* do we need HPUX adjtime() library support? */
end_comment

begin_undef
undef|#
directive|undef
name|NEED_HPUX_ADJTIME
end_undef

begin_comment
comment|/* Might nlist() values require an extra level of indirection (AIX)? */
end_comment

begin_undef
undef|#
directive|undef
name|NLIST_EXTRA_INDIRECTION
end_undef

begin_comment
comment|/* Other needed NLIST stuff */
end_comment

begin_undef
undef|#
directive|undef
name|NLIST_STRUCT
end_undef

begin_undef
undef|#
directive|undef
name|NLIST_NAME_UNION
end_undef

begin_comment
comment|/* Should we recommend a minimum value for tickadj? */
end_comment

begin_undef
undef|#
directive|undef
name|MIN_REC_TICKADJ
end_undef

begin_comment
comment|/* Is there a problem using PARENB and IGNPAR (IRIX)? */
end_comment

begin_undef
undef|#
directive|undef
name|NO_PARENB_IGNPAR
end_undef

begin_comment
comment|/* Should we not IGNPAR (Linux)? */
end_comment

begin_undef
undef|#
directive|undef
name|RAWDCF_NO_IGNPAR
end_undef

begin_comment
comment|/* Does the compiler like "volatile"? */
end_comment

begin_undef
undef|#
directive|undef
name|volatile
end_undef

begin_comment
comment|/* Does qsort expect to work on "void *" stuff? */
end_comment

begin_undef
undef|#
directive|undef
name|QSORT_USES_VOID_P
end_undef

begin_comment
comment|/* What is the fallback value for HZ? */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_HZ
end_undef

begin_comment
comment|/* Do we need to override the system's idea of HZ? */
end_comment

begin_undef
undef|#
directive|undef
name|OVERRIDE_HZ
end_undef

begin_comment
comment|/* Do we want the SCO clock hacks? */
end_comment

begin_undef
undef|#
directive|undef
name|SCO5_CLOCK
end_undef

begin_comment
comment|/* Do we want the ReliantUNIX clock hacks? */
end_comment

begin_undef
undef|#
directive|undef
name|RELIANTUNIX_CLOCK
end_undef

begin_comment
comment|/* Does the kernel have an FLL bug? */
end_comment

begin_undef
undef|#
directive|undef
name|KERNEL_FLL_BUG
end_undef

begin_comment
comment|/* Define if you have the TIOCGPPSEV ioctl (Solaris) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TIOCGPPSEV
end_undef

begin_comment
comment|/* Define if you have the TIOCSPPS ioctl (Solaris) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TIOCSPPS
end_undef

begin_comment
comment|/* Define if you have the CIOGETEV ioctl (SunOS, Linux) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CIOGETEV
end_undef

begin_comment
comment|/* Define if you have the TIOCGSERIAL, TIOCSSERIAL, ASYNC_PPS_CD_POS, and ASYNC_PPS_CD_NEG ioctls (linux) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_TIO_SERIAL_STUFF
end_undef

begin_comment
comment|/* Define if you have the interface in the Draft RFC */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PPSAPI
end_undef

begin_comment
comment|/* Do we need to #define _SVID3 when we #include<termios.h>? */
end_comment

begin_undef
undef|#
directive|undef
name|TERMIOS_NEEDS__SVID3
end_undef

begin_comment
comment|/* Do we have support for SHMEM_STATUS? */
end_comment

begin_undef
undef|#
directive|undef
name|ONCORE_SHMEM_STATUS
end_undef

begin_comment
comment|/***/
end_comment

begin_comment
comment|/* Which way should we declare... */
end_comment

begin_comment
comment|/* adjtime()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_ADJTIME_0
end_undef

begin_comment
comment|/* bcopy()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_BCOPY_0
end_undef

begin_comment
comment|/* bzero()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_BZERO_0
end_undef

begin_comment
comment|/* cfset[io]speed()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_CFSETISPEED_0
end_undef

begin_comment
comment|/* hstrerror()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_HSTRERROR_0
end_undef

begin_comment
comment|/* ioctl()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_IOCTL_0
end_undef

begin_comment
comment|/* IPC? (bind, connect, recvfrom, sendto, setsockopt, socket) */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_IPC_0
end_undef

begin_comment
comment|/* memmove()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_MEMMOVE_0
end_undef

begin_comment
comment|/* memset()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_MEMSET_0
end_undef

begin_comment
comment|/* mkstemp()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_MKSTEMP_0
end_undef

begin_comment
comment|/* mktemp()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_MKTEMP_0
end_undef

begin_comment
comment|/* mrand48()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_MRAND48_0
end_undef

begin_comment
comment|/* nlist()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_NLIST_0
end_undef

begin_comment
comment|/* plock()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_PLOCK_0
end_undef

begin_comment
comment|/* rename()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_RENAME_0
end_undef

begin_comment
comment|/* select()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_SELECT_0
end_undef

begin_comment
comment|/* setitimer()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_SETITIMER_0
end_undef

begin_comment
comment|/* setpriority()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_SETPRIORITY_0
end_undef

begin_undef
undef|#
directive|undef
name|DECL_SETPRIORITY_1
end_undef

begin_comment
comment|/* sigvec()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_SIGVEC_0
end_undef

begin_comment
comment|/* srand48()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_SRAND48_0
end_undef

begin_comment
comment|/* stdio stuff? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_STDIO_0
end_undef

begin_comment
comment|/* stime()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_STIME_0
end_undef

begin_undef
undef|#
directive|undef
name|DECL_STIME_1
end_undef

begin_comment
comment|/* strtol()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_STRTOL_0
end_undef

begin_comment
comment|/* syslog() stuff? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_SYSLOG_0
end_undef

begin_comment
comment|/* time()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_TIME_0
end_undef

begin_comment
comment|/* [gs]ettimeofday()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_TIMEOFDAY_0
end_undef

begin_comment
comment|/* tolower()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_TOLOWER_0
end_undef

begin_comment
comment|/* toupper()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_TOUPPER_0
end_undef

begin_comment
comment|/* strerror()? */
end_comment

begin_undef
undef|#
directive|undef
name|DECL_STRERROR_0
end_undef

begin_undef
undef|#
directive|undef
name|ULONG_CONST
end_undef

end_unit

