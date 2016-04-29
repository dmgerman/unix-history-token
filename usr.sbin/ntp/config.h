begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Define if building universal (internal helper macro) */
end_comment

begin_comment
comment|/* #undef AC_APPLE_UNIVERSAL_BUILD */
end_comment

begin_comment
comment|/* Is adjtime() accurate? */
end_comment

begin_comment
comment|/* #undef ADJTIME_IS_ACCURATE */
end_comment

begin_comment
comment|/* Support NTP Autokey protocol? */
end_comment

begin_comment
comment|/* #define AUTOKEY 1 */
end_comment

begin_comment
comment|/* why not HAVE_P_S? */
end_comment

begin_comment
comment|/* #undef CALL_PTHREAD_SETCONCURRENCY */
end_comment

begin_comment
comment|/* ACTS modem service */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ACTS
value|1
end_define

begin_comment
comment|/* Arbiter 1088A/B GPS receiver */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ARBITER
value|1
end_define

begin_comment
comment|/* ARCRON support? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ARCRON_MSF
value|1
end_define

begin_comment
comment|/* Austron 2200A/2201A GPS receiver? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_AS2201
value|1
end_define

begin_comment
comment|/* PPS interface? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ATOM
value|1
end_define

begin_comment
comment|/* Datum/Bancomm bc635/VME interface? */
end_comment

begin_comment
comment|/* #undef CLOCK_BANC */
end_comment

begin_comment
comment|/* Chronolog K-series WWVB receiver? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_CHRONOLOG
value|1
end_define

begin_comment
comment|/* CHU modem/decoder */
end_comment

begin_define
define|#
directive|define
name|CLOCK_CHU
value|1
end_define

begin_comment
comment|/* Diems Computime Radio Clock? */
end_comment

begin_comment
comment|/* #undef CLOCK_COMPUTIME */
end_comment

begin_comment
comment|/* Datum Programmable Time System? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_DATUM
value|1
end_define

begin_comment
comment|/* ELV/DCF7000 clock? */
end_comment

begin_comment
comment|/* #undef CLOCK_DCF7000 */
end_comment

begin_comment
comment|/* Dumb generic hh:mm:ss local clock? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_DUMBCLOCK
value|1
end_define

begin_comment
comment|/* Forum Graphic GPS datating station driver? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_FG
value|1
end_define

begin_comment
comment|/* GPSD JSON receiver */
end_comment

begin_define
define|#
directive|define
name|CLOCK_GPSDJSON
value|1
end_define

begin_comment
comment|/* TrueTime GPS receiver/VME interface? */
end_comment

begin_comment
comment|/* #undef CLOCK_GPSVME */
end_comment

begin_comment
comment|/* Heath GC-1000 WWV/WWVH receiver? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_HEATH
value|1
end_define

begin_comment
comment|/* HOPF 6021 clock? */
end_comment

begin_comment
comment|/* #undef CLOCK_HOPF6021 */
end_comment

begin_comment
comment|/* HOPF PCI clock device? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_HOPF_PCI
value|1
end_define

begin_comment
comment|/* HOPF serial clock device? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_HOPF_SERIAL
value|1
end_define

begin_comment
comment|/* HP 58503A GPS receiver? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_HPGPS
value|1
end_define

begin_comment
comment|/* IRIG audio decoder? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_IRIG
value|1
end_define

begin_comment
comment|/* JJY receiver? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_JJY
value|1
end_define

begin_comment
comment|/* Rockwell Jupiter GPS clock? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_JUPITER
value|1
end_define

begin_comment
comment|/* Leitch CSD 5300 Master Clock System Driver? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_LEITCH
value|1
end_define

begin_comment
comment|/* local clock reference? */
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

begin_define
define|#
directive|define
name|CLOCK_MEINBERG
value|1
end_define

begin_comment
comment|/* Magnavox MX4200 GPS receiver */
end_comment

begin_comment
comment|/* #undef CLOCK_MX4200 */
end_comment

begin_comment
comment|/* NeoClock4X */
end_comment

begin_define
define|#
directive|define
name|CLOCK_NEOCLOCK4X
value|1
end_define

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

begin_define
define|#
directive|define
name|CLOCK_PALISADE
value|1
end_define

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

begin_define
define|#
directive|define
name|CLOCK_PCF
value|1
end_define

begin_comment
comment|/* PCL 720 clock support */
end_comment

begin_comment
comment|/* #undef CLOCK_PPS720 */
end_comment

begin_comment
comment|/* PST/Traconex 1020 WWV/WWVH receiver */
end_comment

begin_define
define|#
directive|define
name|CLOCK_PST
value|1
end_define

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
comment|/* RIPE NCC Trimble clock */
end_comment

begin_comment
comment|/* #undef CLOCK_RIPENCC */
end_comment

begin_comment
comment|/* Schmid DCF77 clock */
end_comment

begin_comment
comment|/* #undef CLOCK_SCHMID */
end_comment

begin_comment
comment|/* SEL240X protocol */
end_comment

begin_comment
comment|/* #undef CLOCK_SEL240X */
end_comment

begin_comment
comment|/* clock thru shared memory */
end_comment

begin_define
define|#
directive|define
name|CLOCK_SHM
value|1
end_define

begin_comment
comment|/* Spectracom 8170/Netclock/2 WWVB receiver */
end_comment

begin_define
define|#
directive|define
name|CLOCK_SPECTRACOM
value|1
end_define

begin_comment
comment|/* KSI/Odetics TPRO/S GPS receiver/IRIG interface */
end_comment

begin_comment
comment|/* #undef CLOCK_TPRO */
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

begin_define
define|#
directive|define
name|CLOCK_TRUETIME
value|1
end_define

begin_comment
comment|/* Spectracom TSYNC timing board */
end_comment

begin_comment
comment|/* #undef CLOCK_TSYNCPCI */
end_comment

begin_comment
comment|/* TrueTime 560 IRIG-B decoder? */
end_comment

begin_comment
comment|/* #undef CLOCK_TT560 */
end_comment

begin_comment
comment|/* Ultralink M320 WWVB receiver? */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ULINK
value|1
end_define

begin_comment
comment|/* VARITEXT clock */
end_comment

begin_comment
comment|/* #undef CLOCK_VARITEXT */
end_comment

begin_comment
comment|/* WHARTON 400A Series clock */
end_comment

begin_comment
comment|/* #undef CLOCK_WHARTON_400A */
end_comment

begin_comment
comment|/* WWV audio driver */
end_comment

begin_define
define|#
directive|define
name|CLOCK_WWV
value|1
end_define

begin_comment
comment|/* Zyfer GPStarplus */
end_comment

begin_define
define|#
directive|define
name|CLOCK_ZYFER
value|1
end_define

begin_comment
comment|/* Define to one of `_getb67', `GETB67', `getb67' for Cray-2 and Cray-YMP    systems. This function is required for `alloca.c' support on those systems.    */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define to 1 if using `alloca.c'. */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Enable debugging code? */
end_comment

begin_comment
comment|/* #undef DEBUG */
end_comment

begin_comment
comment|/* Enable processing time debugging? */
end_comment

begin_comment
comment|/* #undef DEBUG_TIMING */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_ADJTIME_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_BCOPY_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_BZERO_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_CFSETISPEED_0 */
end_comment

begin_comment
comment|/* Declare errno? */
end_comment

begin_comment
comment|/* #undef DECL_ERRNO */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_HSTRERROR_0 */
end_comment

begin_comment
comment|/* Declare h_errno? */
end_comment

begin_define
define|#
directive|define
name|DECL_H_ERRNO
value|1
end_define

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_INET_NTOA_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_IOCTL_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_IPC_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_MEMMOVE_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_MKSTEMP_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_MKTEMP_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_NLIST_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_PLOCK_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_RENAME_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_SELECT_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_SETITIMER_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_SETPRIORITY_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_SETPRIORITY_1 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_SIGVEC_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_STDIO_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_STIME_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_STIME_1 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_STRERROR_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_STRTOL_0 */
end_comment

begin_comment
comment|/* Declare syscall()? */
end_comment

begin_comment
comment|/* #undef DECL_SYSCALL */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_SYSLOG_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_TIMEOFDAY_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_TIME_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_TOLOWER_0 */
end_comment

begin_comment
comment|/* Declaration style */
end_comment

begin_comment
comment|/* #undef DECL_TOUPPER_0 */
end_comment

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
comment|/* Default number of megabytes for RLIMIT_MEMLOCK */
end_comment

begin_define
define|#
directive|define
name|DFLT_RLIMIT_MEMLOCK
value|32
end_define

begin_comment
comment|/* Default number of 4k pages for RLIMIT_STACK */
end_comment

begin_define
define|#
directive|define
name|DFLT_RLIMIT_STACK
value|50
end_define

begin_comment
comment|/* Directory separator character, usually / or \\ */
end_comment

begin_define
define|#
directive|define
name|DIR_SEP
value|'/'
end_define

begin_comment
comment|/* use old autokey session key behavior? */
end_comment

begin_comment
comment|/* #undef DISABLE_BUG1243_FIX */
end_comment

begin_comment
comment|/* synch TODR hourly? */
end_comment

begin_comment
comment|/* #undef DOSYNCTODR */
end_comment

begin_comment
comment|/* The number of minutes in a DST adjustment */
end_comment

begin_define
define|#
directive|define
name|DSTMINUTES
value|60
end_define

begin_comment
comment|/* support dynamic interleave? */
end_comment

begin_define
define|#
directive|define
name|DYNAMIC_INTERLEAVE
value|0
end_define

begin_comment
comment|/* number of args to el_init() */
end_comment

begin_define
define|#
directive|define
name|EL_INIT_ARGS
value|4
end_define

begin_comment
comment|/* Provide the explicit 127.0.0.0/8 martian filter? */
end_comment

begin_define
define|#
directive|define
name|ENABLE_BUG3020_FIX
value|1
end_define

begin_comment
comment|/* nls support in libopts */
end_comment

begin_comment
comment|/* #undef ENABLE_NLS */
end_comment

begin_comment
comment|/* force ntpdate to step the clock if !defined(STEP_SLEW) ? */
end_comment

begin_comment
comment|/* #undef FORCE_NTPDATE_STEP */
end_comment

begin_comment
comment|/* What is getsockname()'s socklen type? */
end_comment

begin_define
define|#
directive|define
name|GETSOCKNAME_SOCKLEN_TYPE
value|socklen_t
end_define

begin_comment
comment|/* Do we have a routing socket (rt_msghdr or rtattr)? */
end_comment

begin_define
define|#
directive|define
name|HAS_ROUTING_SOCKET
value|1
end_define

begin_comment
comment|/* via __adjtimex */
end_comment

begin_comment
comment|/* #undef HAVE_ADJTIMEX */
end_comment

begin_comment
comment|/* Define to 1 if you have `alloca', as a function or macro. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define to 1 if you have<alloca.h> and it should be used (not on Ultrix).    */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `arc4random_buf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARC4RANDOM_BUF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<arpa/nameser.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ARPA_NAMESER_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `atomic_thread_fence' function. */
end_comment

begin_comment
comment|/* #undef HAVE_ATOMIC_THREAD_FENCE */
end_comment

begin_comment
comment|/* Do we have audio support? */
end_comment

begin_define
define|#
directive|define
name|HAVE_AUDIO
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* Define to 1 if you have the<bstring.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_BSTRING_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `canonicalize_file_name' function. */
end_comment

begin_comment
comment|/* #undef HAVE_CANONICALIZE_FILE_NAME */
end_comment

begin_comment
comment|/* Define to 1 if you have the `chmod' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CHMOD
value|1
end_define

begin_comment
comment|/* Do we have the CIOGETEV ioctl (SunOS, Linux)? */
end_comment

begin_comment
comment|/* #undef HAVE_CIOGETEV */
end_comment

begin_comment
comment|/* Define to 1 if you have the `clock_getres' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK_GETRES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `clock_gettime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK_GETTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `clock_settime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK_SETTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<cthreads.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_CTHREADS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `daemon' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DAEMON
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `strerror_r', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRERROR_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dirent.h> header file, and it defines `DIR'.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_comment
comment|/* Use Rendezvous/DNS-SD registration */
end_comment

begin_comment
comment|/* #undef HAVE_DNSREGISTRATION */
end_comment

begin_comment
comment|/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
end_comment

begin_comment
comment|/* #undef HAVE_DOPRNT */
end_comment

begin_comment
comment|/* Can we drop root privileges? */
end_comment

begin_comment
comment|/* #undef HAVE_DROPROOT */
end_comment

begin_comment
comment|/* Define to 1 if you have the<errno.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fchmod' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCHMOD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `finite' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FINITE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `fnmatch' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FNMATCH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<fnmatch.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FNMATCH_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FORK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fstat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FSTAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getbootfile' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETBOOTFILE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getclock' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETCLOCK */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getdtablesize' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETDTABLESIZE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getifaddrs' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETIFADDRS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpassphrase' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETPASSPHRASE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `getrusage' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRUSAGE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUID
value|1
end_define

begin_comment
comment|/* if you have GNU Pth */
end_comment

begin_comment
comment|/* #undef HAVE_GNU_PTH */
end_comment

begin_comment
comment|/* Define to 1 if you have the<histedit.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_HISTEDIT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<history.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_HISTORY_H */
end_comment

begin_comment
comment|/* Obvious */
end_comment

begin_define
define|#
directive|define
name|HAVE_HZ_IN_STRUCT_CLOCKINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ieeefp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_IEEEFP_H
value|1
end_define

begin_comment
comment|/* have iflist_sysctl? */
end_comment

begin_define
define|#
directive|define
name|HAVE_IFLIST_SYSCTL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `if_nametoindex' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_IF_NAMETOINDEX
value|1
end_define

begin_comment
comment|/* inline keyword or macro available */
end_comment

begin_define
define|#
directive|define
name|HAVE_INLINE
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `int16_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT16_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `int32'. */
end_comment

begin_comment
comment|/* #undef HAVE_INT32 */
end_comment

begin_comment
comment|/* int32 type in DNS headers, not others. */
end_comment

begin_comment
comment|/* #undef HAVE_INT32_ONLY_WITH_DNS */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `int32_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT32_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `int8_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INT8_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `intmax_t'. */
end_comment

begin_comment
comment|/* #undef HAVE_INTMAX_T */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `intptr_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTPTR_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `isfinite' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISFINITE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<kvm.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_KVM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `kvm_open' function. */
end_comment

begin_comment
comment|/* #undef HAVE_KVM_OPEN */
end_comment

begin_comment
comment|/* Define to 1 if you have the `gen' library (-lgen). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBGEN */
end_comment

begin_comment
comment|/* Define to 1 if you have the<libgen.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBGEN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `intl' library (-lintl). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBINTL */
end_comment

begin_comment
comment|/* Define to 1 if you have the<libintl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LIBINTL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<libscf.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSCF_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* using Linux pthread? */
end_comment

begin_comment
comment|/* #undef HAVE_LINUXTHREADS */
end_comment

begin_comment
comment|/* Do we have Linux capabilities? */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_CAPABILITIES */
end_comment

begin_comment
comment|/* Define to 1 if you have the<linux/if_addr.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_IF_ADDR_H */
end_comment

begin_comment
comment|/* if you have LinuxThreads */
end_comment

begin_comment
comment|/* #undef HAVE_LINUX_THREADS */
end_comment

begin_comment
comment|/* Define to 1 if you have the `localeconv' function. */
end_comment

begin_comment
comment|/* #undef HAVE_LOCALECONV */
end_comment

begin_comment
comment|/* Define to 1 if you have the<locale.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LOCALE_H */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `long double'. */
end_comment

begin_comment
comment|/* #undef HAVE_LONG_DOUBLE */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `long long'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `long long int'. */
end_comment

begin_comment
comment|/* #undef HAVE_LONG_LONG_INT */
end_comment

begin_comment
comment|/* if you have SunOS LWP package */
end_comment

begin_comment
comment|/* #undef HAVE_LWP */
end_comment

begin_comment
comment|/* Define to 1 if you have the<lwp/lwp.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LWP_LWP_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<machine/inline.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MACHINE_INLINE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<machine/soundcard.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MACHINE_SOUNDCARD_H */
end_comment

begin_comment
comment|/* define if you have Mach Cthreads */
end_comment

begin_comment
comment|/* #undef HAVE_MACH_CTHREADS */
end_comment

begin_comment
comment|/* Define to 1 if you have the<mach/cthreads.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MACH_CTHREADS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<math.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MATH_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `MD5Init' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MD5INIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<md5.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MD5_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `memlk' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MEMLK */
end_comment

begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mkstemp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mktime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mlockall' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MLOCKALL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `mmap' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `nanosleep' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NANOSLEEP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ndir.h> header file, and it defines `DIR'. */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netdb.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETDB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/in.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/in_system.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINET_IN_SYSTEM_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinet/in_systm.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_SYSTM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/in_var.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_VAR_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/ip.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IP_H
value|1
end_define

begin_comment
comment|/* NetInfo support? */
end_comment

begin_comment
comment|/* #undef HAVE_NETINFO */
end_comment

begin_comment
comment|/* Define to 1 if you have the<netinfo/ni.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NETINFO_NI_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<net/if6.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NET_IF6_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<net/if.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_IF_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<net/if_var.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_IF_VAR_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<net/route.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NET_ROUTE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `nice' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NICE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<nlist.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NLIST_H
value|1
end_define

begin_comment
comment|/* via __adjtimex */
end_comment

begin_define
define|#
directive|define
name|HAVE_NTP_ADJTIME
value|1
end_define

begin_comment
comment|/* via __ntp_gettime */
end_comment

begin_define
define|#
directive|define
name|HAVE_NTP_GETTIME
value|1
end_define

begin_comment
comment|/* Do we want support for Samba's signing daemon? */
end_comment

begin_define
define|#
directive|define
name|HAVE_NTP_SIGND
value|1
end_define

begin_comment
comment|/* if you have NT Event Log */
end_comment

begin_comment
comment|/* #undef HAVE_NT_EVENT_LOG */
end_comment

begin_comment
comment|/* if you have NT Service Manager */
end_comment

begin_comment
comment|/* #undef HAVE_NT_SERVICE_MANAGER */
end_comment

begin_comment
comment|/* if you have NT Threads */
end_comment

begin_comment
comment|/* #undef HAVE_NT_THREADS */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `pid_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PID_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `plock' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PLOCK */
end_comment

begin_comment
comment|/* Define to 1 if you have the<poll.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL_H
value|1
end_define

begin_comment
comment|/* Do we have the PPS API per the Draft RFC? */
end_comment

begin_define
define|#
directive|define
name|HAVE_PPSAPI
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<priv.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PRIV_H */
end_comment

begin_comment
comment|/* Define if you have POSIX threads libraries and header files. */
end_comment

begin_comment
comment|/* #undef HAVE_PTHREAD */
end_comment

begin_comment
comment|/* define to pthreads API spec revision */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREADS
value|10
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_attr_getstacksize' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_ATTR_GETSTACKSIZE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_attr_setstacksize' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_ATTR_SETSTACKSIZE
value|1
end_define

begin_comment
comment|/* define if you have pthread_detach function */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_DETACH
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_getconcurrency' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_GETCONCURRENCY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pthread.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_kill' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_KILL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_kill_other_threads_np' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PTHREAD_KILL_OTHER_THREADS_NP */
end_comment

begin_comment
comment|/* define if you have pthread_rwlock_destroy function */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_RWLOCK_DESTROY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_setconcurrency' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_SETCONCURRENCY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pthread_yield' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_YIELD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pth.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_PTH_H */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `ptrdiff_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTRDIFF_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pututline' function. */
end_comment

begin_comment
comment|/* #undef HAVE_PUTUTLINE */
end_comment

begin_comment
comment|/* Define to 1 if you have the `pututxline' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTUTXLINE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `RAND_bytes' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RAND_BYTES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `RAND_poll' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RAND_POLL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<readline.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_READLINE_H */
end_comment

begin_comment
comment|/* Define if your readline library has \`add_history' */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINE_HISTORY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<readline/history.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINE_HISTORY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<readline/readline.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINE_READLINE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `readlink' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_READLINK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `recvmsg' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RECVMSG
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<resolv.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RESOLV_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `res_init' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RES_INIT
value|1
end_define

begin_comment
comment|/* Do we have Linux routing socket? */
end_comment

begin_comment
comment|/* #undef HAVE_RTNETLINK */
end_comment

begin_comment
comment|/* Define to 1 if you have the `rtprio' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RTPRIO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<runetype.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_RUNETYPE_H
value|1
end_define

begin_comment
comment|/* Obvious */
end_comment

begin_define
define|#
directive|define
name|HAVE_SA_SIGACTION_IN_STRUCT_SIGACTION
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sched.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SCHED_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sched_setscheduler' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SCHED_SETSCHEDULER
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sched_yield' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SCHED_YIELD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<semaphore.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SEMAPHORE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sem_timedwait' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SEM_TIMEDWAIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<setjmp.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETJMP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setlinebuf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLINEBUF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setpgid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPGID
value|1
end_define

begin_comment
comment|/* define if setpgrp takes 0 arguments */
end_comment

begin_comment
comment|/* #undef HAVE_SETPGRP_0 */
end_comment

begin_comment
comment|/* Define to 1 if you have the `setpriority' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPRIORITY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setrlimit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRLIMIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setsid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETSID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `settimeofday' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setvbuf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETVBUF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sgtty.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SGTTY_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sigaction' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Can we use SIGIO for tcp and udp IO? */
end_comment

begin_comment
comment|/* #undef HAVE_SIGNALED_IO */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sigset' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSET
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sigvec' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGVEC
value|1
end_define

begin_comment
comment|/* sigwait() available? */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGWAIT
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `size_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIZE_T
value|1
end_define

begin_comment
comment|/* Define if C99-compliant `snprintf' is available. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `socketpair' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKETPAIR
value|1
end_define

begin_comment
comment|/* Are Solaris privileges available? */
end_comment

begin_comment
comment|/* #undef HAVE_SOLARIS_PRIVS */
end_comment

begin_comment
comment|/* Define to 1 if you have the<stdarg.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDARG_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdatomic.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDATOMIC_H
value|1
end_define

begin_comment
comment|/* Define to 1 if stdbool.h conforms to C99. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDBOOL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stddef.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_STDDEF_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `stime' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STIME */
end_comment

begin_comment
comment|/* Define to 1 if you have the `strchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strdup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strerror_r' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR_R
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strlcat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strlcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stropts.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_STROPTS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `strrchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRRCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strsignal' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSIGNAL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtoll' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOLL
value|1
end_define

begin_comment
comment|/* Define to 1 if `decimal_point' is a member of `struct lconv'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_LCONV_DECIMAL_POINT */
end_comment

begin_comment
comment|/* Define to 1 if `thousands_sep' is a member of `struct lconv'. */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_LCONV_THOUSANDS_SEP */
end_comment

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
comment|/* Define to 1 if `time.tv_nsec' is a member of `struct ntptimeval'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_NTPTIMEVAL_TIME_TV_NSEC
value|1
end_define

begin_comment
comment|/* Does a system header define struct ppsclockev? */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_PPSCLOCKEV */
end_comment

begin_comment
comment|/* Do we have struct snd_size? */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SND_SIZE
value|1
end_define

begin_comment
comment|/* Does a system header define struct sockaddr_storage? */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SOCKADDR_STORAGE
value|1
end_define

begin_comment
comment|/* struct timespec declared? */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_TIMESPEC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sun/audioio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SUN_AUDIOIO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<synch.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYNCH_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `sysconf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sysexits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSEXITS_H
value|1
end_define

begin_comment
comment|/* */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSLOG_FACILITYNAMES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/audioio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_AUDIOIO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/capability.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_CAPABILITY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/clockctl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_CLOCKCTL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/dir.h> header file, and it defines `DIR'.    */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/file.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/i8253.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_I8253_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/ioctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ipc.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IPC_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/limits.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_LIMITS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/lock.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_LOCK_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/mman.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MMAN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/modem.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_MODEM_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/ndir.h> header file, and it defines `DIR'.    */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/pcl720.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PCL720_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/poll.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_POLL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ppsclock.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PPSCLOCK_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/ppstime.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PPSTIME_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/prctl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PRCTL_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/procset.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PROCSET_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/proc.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PROC_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/resource.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/sched.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SCHED_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/select.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/shm.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SHM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/signal.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGNAL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/socket.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKET_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/sockio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOCKIO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/soundcard.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SOUNDCARD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stream.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STREAM_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/stropts.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STROPTS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/sysctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/syssgi.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SYSSGI_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/systune.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SYSTUNE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/termios.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/timepps.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEPPS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/timers.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMERS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/timex.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMEX_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/tpro.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TPRO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Use sys/uio.h for struct iovec help */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_UIO_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/un.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_UN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/var.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_VAR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/wait.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `s_char'. */
end_comment

begin_comment
comment|/* #undef HAVE_S_CHAR */
end_comment

begin_comment
comment|/* Define to 1 if you have the<termios.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<termio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TERMIO_H */
end_comment

begin_comment
comment|/* if you have Solaris LWP (thr) package */
end_comment

begin_comment
comment|/* #undef HAVE_THR */
end_comment

begin_comment
comment|/* Define to 1 if you have the<thread.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_THREAD_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `thr_getconcurrency' function. */
end_comment

begin_comment
comment|/* #undef HAVE_THR_GETCONCURRENCY */
end_comment

begin_comment
comment|/* Define to 1 if you have the `thr_setconcurrency' function. */
end_comment

begin_comment
comment|/* #undef HAVE_THR_SETCONCURRENCY */
end_comment

begin_comment
comment|/* Define to 1 if you have the `thr_yield' function. */
end_comment

begin_comment
comment|/* #undef HAVE_THR_YIELD */
end_comment

begin_comment
comment|/* Obvious */
end_comment

begin_define
define|#
directive|define
name|HAVE_TICKADJ_IN_STRUCT_CLOCKINFO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `timegm' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMEGM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<timepps.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TIMEPPS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `timer_create' function. */
end_comment

begin_comment
comment|/* #undef HAVE_TIMER_CREATE */
end_comment

begin_comment
comment|/* Define to 1 if you have the<timex.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TIMEX_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/* Do we have the TIOCGPPSEV ioctl (Solaris)? */
end_comment

begin_comment
comment|/* #undef HAVE_TIOCGPPSEV */
end_comment

begin_comment
comment|/* Do we have the TIOCSPPS ioctl (Solaris)? */
end_comment

begin_comment
comment|/* #undef HAVE_TIOCSPPS */
end_comment

begin_comment
comment|/* Do we have the TIO serial stuff? */
end_comment

begin_comment
comment|/* #undef HAVE_TIO_SERIAL_STUFF */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `uint16_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT16_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uint32_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT32_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uint8_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINT8_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uintmax_t'. */
end_comment

begin_comment
comment|/* #undef HAVE_UINTMAX_T */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `uintptr_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UINTPTR_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `uint_t'. */
end_comment

begin_comment
comment|/* #undef HAVE_UINT_T */
end_comment

begin_comment
comment|/* Define to 1 if you have the `umask' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UMASK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `uname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* deviant sigwait? */
end_comment

begin_comment
comment|/* #undef HAVE_UNIXWARE_SIGWAIT */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `unsigned long long int'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSIGNED_LONG_LONG_INT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `updwtmp' function. */
end_comment

begin_comment
comment|/* #undef HAVE_UPDWTMP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `updwtmpx' function. */
end_comment

begin_comment
comment|/* #undef HAVE_UPDWTMPX */
end_comment

begin_comment
comment|/* Define to 1 if you have the<utime.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<utmpx.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTMPX_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<utmp.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_UTMP_H */
end_comment

begin_comment
comment|/* Define to 1 if the system has the type `u_int32'. */
end_comment

begin_comment
comment|/* #undef HAVE_U_INT32 */
end_comment

begin_comment
comment|/* u_int32 type in DNS headers, not others. */
end_comment

begin_comment
comment|/* #undef HAVE_U_INT32_ONLY_WITH_DNS */
end_comment

begin_comment
comment|/* Define to 1 if you have the<values.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_VALUES_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<varargs.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_VARARGS_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `vfork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFORK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<vfork.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `vprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_comment
comment|/* Define if C99-compliant `vsnprintf' is available. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<wchar.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCHAR_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `wchar_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCHAR_T
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `wint_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WINT_T
value|1
end_define

begin_comment
comment|/* Define to 1 if `fork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_FORK
value|1
end_define

begin_comment
comment|/* Define to 1 if `vfork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_VFORK
value|1
end_define

begin_comment
comment|/* define if select implicitly yields */
end_comment

begin_define
define|#
directive|define
name|HAVE_YIELDING_SELECT
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `_Bool'. */
end_comment

begin_define
define|#
directive|define
name|HAVE__BOOL
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `_exit' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE__EXIT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the</sys/sync/queue.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE__SYS_SYNC_QUEUE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the</sys/sync/sema.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE__SYS_SYNC_SEMA_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `__adjtimex' function. */
end_comment

begin_comment
comment|/* #undef HAVE___ADJTIMEX */
end_comment

begin_comment
comment|/* defined if C compiler supports __attribute__((...)) */
end_comment

begin_define
define|#
directive|define
name|HAVE___ATTRIBUTE__
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* define away __attribute__() if unsupported */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE___ATTRIBUTE__
end_ifndef

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* empty */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ISC_PLATFORM_NORETURN_PRE
end_define

begin_define
define|#
directive|define
name|ISC_PLATFORM_NORETURN_POST
value|__attribute__((__noreturn__))
end_define

begin_comment
comment|/* Define to 1 if you have the `__ntp_gettime' function. */
end_comment

begin_comment
comment|/* #undef HAVE___NTP_GETTIME */
end_comment

begin_comment
comment|/* Define to 1 if you have the `__res_init' function. */
end_comment

begin_comment
comment|/* #undef HAVE___RES_INIT */
end_comment

begin_comment
comment|/* Does struct sockaddr_storage have __ss_family? */
end_comment

begin_comment
comment|/* #undef HAVE___SS_FAMILY_IN_SS */
end_comment

begin_comment
comment|/* Handle sockaddr_storage.__ss_family */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE___SS_FAMILY_IN_SS
end_ifdef

begin_define
define|#
directive|define
name|ss_family
value|__ss_family
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE___SS_FAMILY_IN_SS */
end_comment

begin_comment
comment|/* Define to provide `rpl_snprintf' function. */
end_comment

begin_comment
comment|/* #undef HW_WANT_RPL_SNPRINTF */
end_comment

begin_comment
comment|/* Define to provide `rpl_vsnprintf' function. */
end_comment

begin_comment
comment|/* #undef HW_WANT_RPL_VSNPRINTF */
end_comment

begin_comment
comment|/* Retry queries on _any_ DNS error? */
end_comment

begin_comment
comment|/* #undef IGNORE_DNS_ERRORS */
end_comment

begin_comment
comment|/* Should we use the IRIG sawtooth filter? */
end_comment

begin_comment
comment|/* #undef IRIG_SUCKS */
end_comment

begin_comment
comment|/* Enclose PTHREAD_ONCE_INIT in extra braces? */
end_comment

begin_comment
comment|/* #undef ISC_PLATFORM_BRACEPTHREADONCEINIT */
end_comment

begin_comment
comment|/* Do we need to fix in6isaddr? */
end_comment

begin_comment
comment|/* #undef ISC_PLATFORM_FIXIN6ISADDR */
end_comment

begin_comment
comment|/* ISC: do we have if_nametoindex()? */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVEIFNAMETOINDEX
value|1
end_define

begin_comment
comment|/* have struct if_laddrconf? */
end_comment

begin_comment
comment|/* #undef ISC_PLATFORM_HAVEIF_LADDRCONF */
end_comment

begin_comment
comment|/* have struct if_laddrreq? */
end_comment

begin_comment
comment|/* #undef ISC_PLATFORM_HAVEIF_LADDRREQ */
end_comment

begin_comment
comment|/* have struct in6_pktinfo? */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVEIN6PKTINFO
value|1
end_define

begin_comment
comment|/* have IPv6? */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVEIPV6
value|1
end_define

begin_comment
comment|/* struct sockaddr has sa_len? */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVESALEN
value|1
end_define

begin_comment
comment|/* sin6_scope_id? */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_HAVESCOPEID
value|1
end_define

begin_comment
comment|/* missing in6addr_any? */
end_comment

begin_comment
comment|/* #undef ISC_PLATFORM_NEEDIN6ADDRANY */
end_comment

begin_comment
comment|/* Do we need netinet6/in6.h? */
end_comment

begin_comment
comment|/* #undef ISC_PLATFORM_NEEDNETINET6IN6H */
end_comment

begin_comment
comment|/* ISC: provide inet_ntop() */
end_comment

begin_comment
comment|/* #undef ISC_PLATFORM_NEEDNTOP */
end_comment

begin_comment
comment|/* Declare in_port_t? */
end_comment

begin_comment
comment|/* #undef ISC_PLATFORM_NEEDPORTT */
end_comment

begin_comment
comment|/* ISC: provide inet_pton() */
end_comment

begin_comment
comment|/* #undef ISC_PLATFORM_NEEDPTON */
end_comment

begin_comment
comment|/* enable libisc thread support? */
end_comment

begin_define
define|#
directive|define
name|ISC_PLATFORM_USETHREADS
value|1
end_define

begin_comment
comment|/* Does the kernel have an FLL bug? */
end_comment

begin_comment
comment|/* #undef KERNEL_FLL_BUG */
end_comment

begin_comment
comment|/* Does the kernel support precision time discipline? */
end_comment

begin_define
define|#
directive|define
name|KERNEL_PLL
value|1
end_define

begin_comment
comment|/* Define to use libseccomp system call filtering. */
end_comment

begin_comment
comment|/* #undef KERN_SECCOMP */
end_comment

begin_comment
comment|/* What is (probably) the name of DOSYNCTODR in the kernel? */
end_comment

begin_define
define|#
directive|define
name|K_DOSYNCTODR_NAME
value|"_dosynctodr"
end_define

begin_comment
comment|/* What is (probably) the name of NOPRINTF in the kernel? */
end_comment

begin_define
define|#
directive|define
name|K_NOPRINTF_NAME
value|"_noprintf"
end_define

begin_comment
comment|/* What is the name of TICKADJ in the kernel? */
end_comment

begin_define
define|#
directive|define
name|K_TICKADJ_NAME
value|"_tickadj"
end_define

begin_comment
comment|/* What is the name of TICK in the kernel? */
end_comment

begin_define
define|#
directive|define
name|K_TICK_NAME
value|"_tick"
end_define

begin_comment
comment|/* define to 1 if library is thread safe */
end_comment

begin_define
define|#
directive|define
name|LDAP_API_FEATURE_X_OPENLDAP_THREAD_SAFE
value|1
end_define

begin_comment
comment|/* leap smear mechanism */
end_comment

begin_comment
comment|/* #undef LEAP_SMEAR */
end_comment

begin_comment
comment|/* Define to any value to include libseccomp sandboxing. */
end_comment

begin_comment
comment|/* #undef LIBSECCOMP */
end_comment

begin_comment
comment|/* Should we align with the NIST lockclock scheme? */
end_comment

begin_comment
comment|/* #undef LOCKCLOCK */
end_comment

begin_comment
comment|/* Define to the sub-directory in which libtool stores uninstalled libraries.    */
end_comment

begin_define
define|#
directive|define
name|LT_OBJDIR
value|".libs/"
end_define

begin_comment
comment|/* Does the target support multicast IP? */
end_comment

begin_define
define|#
directive|define
name|MCAST
value|1
end_define

begin_comment
comment|/* Should we recommend a minimum value for tickadj? */
end_comment

begin_comment
comment|/* #undef MIN_REC_TICKADJ */
end_comment

begin_comment
comment|/* Define to 1 if the compiler does not support C99's structure    initialization. */
end_comment

begin_comment
comment|/* #undef MISSING_C99_STRUCT_INIT */
end_comment

begin_comment
comment|/* having to fork the DNS worker early when doing chroot? */
end_comment

begin_comment
comment|/* #undef NEED_EARLY_FORK */
end_comment

begin_comment
comment|/* Do we need HPUX adjtime() library support? */
end_comment

begin_comment
comment|/* #undef NEED_HPUX_ADJTIME */
end_comment

begin_comment
comment|/* Do we want the HPUX FindConfig()? */
end_comment

begin_comment
comment|/* #undef NEED_HPUX_FINDCONFIG */
end_comment

begin_comment
comment|/* We need to provide netsnmp_daemonize() */
end_comment

begin_comment
comment|/* #undef NEED_NETSNMP_DAEMONIZE */
end_comment

begin_comment
comment|/* pthread_init() required? */
end_comment

begin_comment
comment|/* #undef NEED_PTHREAD_INIT */
end_comment

begin_comment
comment|/* use PTHREAD_SCOPE_SYSTEM? */
end_comment

begin_comment
comment|/* #undef NEED_PTHREAD_SCOPE_SYSTEM */
end_comment

begin_comment
comment|/* Do we need the qnx adjtime call? */
end_comment

begin_comment
comment|/* #undef NEED_QNX_ADJTIME */
end_comment

begin_comment
comment|/* Do we need extra room for SO_RCVBUF? (HPUX< 8) */
end_comment

begin_comment
comment|/* #undef NEED_RCVBUF_SLOP */
end_comment

begin_comment
comment|/* Do we need an s_char typedef? */
end_comment

begin_define
define|#
directive|define
name|NEED_S_CHAR_TYPEDEF
value|1
end_define

begin_comment
comment|/* Might nlist() values require an extra level of indirection (AIX)? */
end_comment

begin_comment
comment|/* #undef NLIST_EXTRA_INDIRECTION */
end_comment

begin_comment
comment|/* does struct nlist use a name union? */
end_comment

begin_comment
comment|/* #undef NLIST_NAME_UNION */
end_comment

begin_comment
comment|/* nlist stuff */
end_comment

begin_define
define|#
directive|define
name|NLIST_STRUCT
value|1
end_define

begin_comment
comment|/* Should we NOT read /dev/kmem? */
end_comment

begin_define
define|#
directive|define
name|NOKMEM
value|1
end_define

begin_comment
comment|/* Define to 1 if your C compiler doesn't accept -c and -o together. */
end_comment

begin_comment
comment|/* #undef NO_MINUS_C_MINUS_O */
end_comment

begin_comment
comment|/* Should we avoid #warning on option name collisions? */
end_comment

begin_comment
comment|/* #undef NO_OPTION_NAME_WARNINGS */
end_comment

begin_comment
comment|/* Is there a problem using PARENB and IGNPAR? */
end_comment

begin_comment
comment|/* #undef NO_PARENB_IGNPAR */
end_comment

begin_comment
comment|/* define if you have (or want) no threads */
end_comment

begin_comment
comment|/* #undef NO_THREADS */
end_comment

begin_comment
comment|/* Default location of crypto key info */
end_comment

begin_define
define|#
directive|define
name|NTP_KEYSDIR
value|"/etc/ntp"
end_define

begin_comment
comment|/* Path to sign daemon rendezvous socket */
end_comment

begin_define
define|#
directive|define
name|NTP_SIGND_PATH
value|"/var/run/ntp_signd"
end_define

begin_comment
comment|/* Do we have ntp_{adj,get}time in libc? */
end_comment

begin_define
define|#
directive|define
name|NTP_SYSCALLS_LIBC
value|1
end_define

begin_comment
comment|/* Do we have ntp_{adj,get}time in the kernel? */
end_comment

begin_comment
comment|/* #undef NTP_SYSCALLS_STD */
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
comment|/* Use OpenSSL? */
end_comment

begin_comment
comment|/* #define OPENSSL */
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
comment|/* need to recreate sockets on changed routing? */
end_comment

begin_comment
comment|/* #undef OS_MISSES_SPECIFIC_ROUTE_UPDATES */
end_comment

begin_comment
comment|/* wildcard socket needs REUSEADDR to bind interface addresses */
end_comment

begin_comment
comment|/* #undef OS_NEEDS_REUSEADDR_FOR_IFADDRBIND */
end_comment

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
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"ntp"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"http://bugs.ntp.org./"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"ntp"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"ntp 4.2.8p7"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"ntp"
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|"http://www.ntp.org./"
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"4.2.8p7"
end_define

begin_comment
comment|/* data dir */
end_comment

begin_define
define|#
directive|define
name|PERLLIBDIR
value|"/usr/local/share/ntp/lib"
end_define

begin_comment
comment|/* define to a working POSIX compliant shell */
end_comment

begin_define
define|#
directive|define
name|POSIX_SHELL
value|"/bin/sh"
end_define

begin_comment
comment|/* PARSE kernel PLL PPS support */
end_comment

begin_comment
comment|/* #undef PPS_SYNC */
end_comment

begin_comment
comment|/* Preset a value for 'tick'? */
end_comment

begin_define
define|#
directive|define
name|PRESET_TICK
value|1000000L/hz
end_define

begin_comment
comment|/* Preset a value for 'tickadj'? */
end_comment

begin_define
define|#
directive|define
name|PRESET_TICKADJ
value|500/hz
end_define

begin_comment
comment|/* Should we not IGNPAR (Linux)? */
end_comment

begin_comment
comment|/* #undef RAWDCF_NO_IGNPAR */
end_comment

begin_comment
comment|/* enable thread safety */
end_comment

begin_define
define|#
directive|define
name|REENTRANT
value|1
end_define

begin_comment
comment|/* Basic refclock support? */
end_comment

begin_define
define|#
directive|define
name|REFCLOCK
value|1
end_define

begin_comment
comment|/* Do we want the ReliantUNIX clock hacks? */
end_comment

begin_comment
comment|/* #undef RELIANTUNIX_CLOCK */
end_comment

begin_comment
comment|/* define if sched_yield yields the entire process */
end_comment

begin_comment
comment|/* #undef REPLACE_BROKEN_YIELD */
end_comment

begin_comment
comment|/* Define as the return type of signal handlers (`int' or `void'). */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* saveconfig mechanism */
end_comment

begin_define
define|#
directive|define
name|SAVECONFIG
value|1
end_define

begin_comment
comment|/* Do we want the SCO clock hacks? */
end_comment

begin_comment
comment|/* #undef SCO5_CLOCK */
end_comment

begin_comment
comment|/* The size of `char *', as computed by sizeof. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
end_ifdef

begin_define
define|#
directive|define
name|SIZEOF_CHARP
value|8
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIZEOF_CHARP
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The size of `int', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_INT
value|4
end_define

begin_comment
comment|/* The size of `long', as computed by sizeof. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LP64__
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
comment|/* The size of `long long', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_LONG_LONG
value|8
end_define

begin_comment
comment|/* The size of `pthread_t', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_PTHREAD_T
value|8
end_define

begin_comment
comment|/* The size of `short', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_SHORT
value|2
end_define

begin_comment
comment|/* The size of `signed char', as computed by sizeof. */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_SIGNED_CHAR
value|1
end_define

begin_comment
comment|/* The size of `time_t', as computed by sizeof. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIZEOF_TIME_T
value|4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIZEOF_TIME_T
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Does SIOCGIFCONF return size in the buffer? */
end_comment

begin_comment
comment|/* #undef SIZE_RETURNED_IN_BUFFER */
end_comment

begin_comment
comment|/* Slew always? */
end_comment

begin_comment
comment|/* #undef SLEWALWAYS */
end_comment

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at runtime. 	STACK_DIRECTION> 0 => grows toward higher addresses 	STACK_DIRECTION< 0 => grows toward lower addresses 	STACK_DIRECTION = 0 => direction of growth unknown */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Step, then slew the clock? */
end_comment

begin_comment
comment|/* #undef STEP_SLEW */
end_comment

begin_comment
comment|/* Define to 1 if strerror_r returns char *. */
end_comment

begin_comment
comment|/* #undef STRERROR_R_CHAR_P */
end_comment

begin_comment
comment|/* canonical system (cpu-vendor-os) of where we should run */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_if

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"alpha-undermydesk-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"sparc64-undermydesk-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"amd64-undermydesk-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"powerpc64-undermydesk-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"powerpc-undermydesk-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips64
argument_list|)
end_elif

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"mips64-undermydesk-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__mips__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"mips-undermydesk-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__aarch64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"arm64-undermydesk-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__arm__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"arm-undermydesk-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"sparc64-undermydesk-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"sparc-undermydesk-freebsd"
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__ia64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"ia64-undermydesk-freebsd"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STR_SYSTEM
value|"i386-undermydesk-freebsd"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Does Xettimeofday take 1 arg? */
end_comment

begin_comment
comment|/* #undef SYSV_TIMEOFDAY */
end_comment

begin_comment
comment|/* Do we need to #define _SVID3 when we #include<termios.h>? */
end_comment

begin_comment
comment|/* #undef TERMIOS_NEEDS__SVID3 */
end_comment

begin_comment
comment|/* enable thread safety */
end_comment

begin_define
define|#
directive|define
name|THREADSAFE
value|1
end_define

begin_comment
comment|/* enable thread safety */
end_comment

begin_define
define|#
directive|define
name|THREAD_SAFE
value|1
end_define

begin_comment
comment|/* Is K_TICKADJ_NAME in nanoseconds? */
end_comment

begin_comment
comment|/* #undef TICKADJ_NANO */
end_comment

begin_comment
comment|/* Is K_TICK_NAME in nanoseconds? */
end_comment

begin_comment
comment|/* #undef TICK_NANO */
end_comment

begin_comment
comment|/* Define to 1 if you can safely include both<sys/time.h> and<time.h>. */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define to 1 if your<sys/time.h> declares `struct tm'. */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Provide a typedef for uintptr_t? */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_UINTPTR_T
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uintptr_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|HAVE_UINTPTR_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* What type to use for setsockopt */
end_comment

begin_define
define|#
directive|define
name|TYPEOF_IP_MULTICAST_LOOP
value|u_char
end_define

begin_comment
comment|/* Do we set process groups with -pid? */
end_comment

begin_comment
comment|/* #undef UDP_BACKWARDS_SETOWN */
end_comment

begin_comment
comment|/* Must we have a CTTY for fsetown? */
end_comment

begin_define
define|#
directive|define
name|USE_FSETOWNCTTY
value|1
end_define

begin_comment
comment|/* Use OpenSSL's crypto random functions */
end_comment

begin_comment
comment|/* #define USE_OPENSSL_CRYPTO_RAND 1 */
end_comment

begin_comment
comment|/* OK to use snprintb()? */
end_comment

begin_comment
comment|/* #undef USE_SNPRINTB */
end_comment

begin_comment
comment|/* Can we use SIGPOLL for tty IO? */
end_comment

begin_comment
comment|/* #undef USE_TTY_SIGPOLL */
end_comment

begin_comment
comment|/* Can we use SIGPOLL for UDP? */
end_comment

begin_comment
comment|/* #undef USE_UDP_SIGPOLL */
end_comment

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"4.2.8p7"
end_define

begin_comment
comment|/* vsnprintf expands "%m" to strerror(errno) */
end_comment

begin_comment
comment|/* #undef VSNPRINTF_PERCENT_M */
end_comment

begin_comment
comment|/* configure --enable-ipv6 */
end_comment

begin_define
define|#
directive|define
name|WANT_IPV6
value|1
end_define

begin_comment
comment|/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most    significant byte first (like Motorola and SPARC, unlike Intel). */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ARMEB__
argument_list|)
operator|||
name|defined
argument_list|(
name|__MIPSEB__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc__
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|WORDS_BIGENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* routine worker child proc uses to exit. */
end_comment

begin_define
define|#
directive|define
name|WORKER_CHILD_EXIT
value|exit
end_define

begin_comment
comment|/* Define to 1 if on MINIX. */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define to 2 if the system does not provide POSIX.1 features except with    this defined. */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define to 1 if you need to in order for `stat' and other things to work. */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* enable thread safety */
end_comment

begin_define
define|#
directive|define
name|_REENTRANT
value|1
end_define

begin_comment
comment|/* enable thread safety */
end_comment

begin_define
define|#
directive|define
name|_SGI_MP_SOURCE
value|1
end_define

begin_comment
comment|/* enable thread safety */
end_comment

begin_define
define|#
directive|define
name|_THREADSAFE
value|1
end_define

begin_comment
comment|/* enable thread safety */
end_comment

begin_define
define|#
directive|define
name|_THREAD_SAFE
value|1
end_define

begin_comment
comment|/* Define to 500 only on HP-UX. */
end_comment

begin_comment
comment|/* #undef _XOPEN_SOURCE */
end_comment

begin_comment
comment|/* Are we _special_? */
end_comment

begin_comment
comment|/* #undef __APPLE_USE_RFC_3542 */
end_comment

begin_comment
comment|/* Define to 1 if type `char' is unsigned and you are not using gcc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CHAR_UNSIGNED__
end_ifndef

begin_comment
comment|/* # undef __CHAR_UNSIGNED__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable extensions on AIX 3, Interix.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_ALL_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable GNU extensions on systems that have them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable threading extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_PTHREAD_SEMANTICS
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_PTHREAD_SEMANTICS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable extensions on HP NonStop.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TANDEM_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_TANDEM_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable general extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EXTENSIONS__
end_ifndef

begin_define
define|#
directive|define
name|__EXTENSIONS__
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* deviant */
end_comment

begin_comment
comment|/* #undef adjtimex */
end_comment

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef gid_t */
end_comment

begin_comment
comment|/* Define to `__inline__' or `__inline' if that's what the C compiler    calls it, or to nothing if 'inline' is not supported under any name.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_comment
comment|/* #undef inline */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to the widest signed integer type if<stdint.h> and<inttypes.h> do    not define. */
end_comment

begin_comment
comment|/* #undef intmax_t */
end_comment

begin_comment
comment|/* deviant */
end_comment

begin_comment
comment|/* #undef ntp_adjtime */
end_comment

begin_comment
comment|/* deviant */
end_comment

begin_comment
comment|/* #undef ntp_gettime */
end_comment

begin_comment
comment|/* Define to `long int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PARSESTREAM
argument_list|)
end_if

begin_comment
comment|/* 	     * stdio.h must be included after _GNU_SOURCE is defined 	     * but before #define snprintf rpl_snprintf 	     */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to rpl_snprintf if the replacement function should be used. */
end_comment

begin_comment
comment|/* #undef snprintf */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define. */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

begin_comment
comment|/* Define to the widest unsigned integer type if<stdint.h> and<inttypes.h>    do not define. */
end_comment

begin_comment
comment|/* #undef uintmax_t */
end_comment

begin_comment
comment|/* Define to the type of an unsigned integer type wide enough to hold a    pointer, if such a type exists, and if the system does not define it. */
end_comment

begin_comment
comment|/* #undef uintptr_t */
end_comment

begin_comment
comment|/* Define as `fork' if `vfork' does not work. */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_comment
comment|/* Define to empty if the keyword `volatile' does not work. Warning: valid    code using `volatile' can become incorrect without. Disable with care. */
end_comment

begin_comment
comment|/* #undef volatile */
end_comment

begin_comment
comment|/* Define to rpl_vsnprintf if the replacement function should be used. */
end_comment

begin_comment
comment|/* #undef vsnprintf */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MPINFOU_PREDECLARED
end_ifndef

begin_define
define|#
directive|define
name|MPINFOU_PREDECLARED
end_define

begin_typedef
typedef|typedef
union|union
name|mpinfou
block|{
name|struct
name|pdk_mpinfo
modifier|*
name|pdkptr
decl_stmt|;
name|struct
name|mpinfo
modifier|*
name|pikptr
decl_stmt|;
block|}
name|mpinfou_t
typedef|;
end_typedef

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
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|PARSESTREAM
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HW_WANT_RPL_VSNPRINTF
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<stdarg.h>
name|int
name|rpl_vsnprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|va_list
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern

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
name|defined
argument_list|(
name|HW_WANT_RPL_SNPRINTF
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
name|int
name|rpl_snprintf
parameter_list|(
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
block|}
end_extern

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

begin_comment
comment|/* !defined(_KERNEL)&& !defined(PARSESTREAM) */
end_comment

begin_comment
comment|/*  * FreeBSD specific: Explicitly specify date/time for reproducible build.  */
end_comment

begin_define
define|#
directive|define
name|MKREPRO_DATE
value|"Apr 27 2016"
end_define

begin_define
define|#
directive|define
name|MKREPRO_TIME
value|"05:53:49"
end_define

end_unit

