begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)uucp.h	5.16	5/4/88	*/
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * Determine local uucp name of this machine.  * Define one of the following:  *  * For UCB 4.1A and later systems, you will have the gethostname(2) call.  * If this call exists, define GETHOSTNAME.  *  * For USG 3.0 and later systems, you will have the uname(2) call.  * If this call exists, define UNAME.  *  * Some systems have a line of the form '#define sysname "myuucpname",'  * in the file /usr/include/whoami.h, to identify their machine.  * If your site does that, define WHOAMI.  *  * If your site has<whoami.h>, but you do not want to read  * that file every time uucp runs, you can compile sysname into uucp.  * This is faster and more reliable, but binaries do not port.  * If you want to do that, define CCWHOAMI.  *  * Some systems put the local uucp name in a single-line file  * named /etc/uucpname or /local/uucpname.  * If your site does that, define UUNAME.  *  * You should also define MYNAME to be your uucp name.  *  * For each of the above that are defined, uucp checks them in order.  * It stops on the first method that returns a non null name.  * If everything fails, it uses "unknown" for the system name.  */
end_comment

begin_define
define|#
directive|define
name|GETHOSTNAME
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* #define UNAME	/**/
end_comment

begin_comment
comment|/* #define WHOAMI	/**/
end_comment

begin_comment
comment|/* #define CCWHOAMI	/**/
end_comment

begin_comment
comment|/* #define UUNAME	/**/
end_comment

begin_comment
comment|/* If the above fails ... */
end_comment

begin_define
define|#
directive|define
name|MYNAME
value|"erehwon"
end_define

begin_comment
comment|/*  * Define the various kinds of connections to include.  * The complete list is in the condevs array in condevs.c  */
end_comment

begin_define
define|#
directive|define
name|ATT2224
end_define

begin_comment
comment|/* AT&T 2224 */
end_comment

begin_define
define|#
directive|define
name|BSDTCP
end_define

begin_comment
comment|/* 4.2bsd TCP/IP */
end_comment

begin_define
define|#
directive|define
name|CDS224
end_define

begin_comment
comment|/* Concord Data Systems 2400 */
end_comment

begin_comment
comment|/* #define DATAKIT	/* ATT's datakit */
end_comment

begin_define
define|#
directive|define
name|DF02
end_define

begin_comment
comment|/* Dec's DF02/DF03 */
end_comment

begin_define
define|#
directive|define
name|DF112
end_define

begin_comment
comment|/* Dec's DF112 */
end_comment

begin_define
define|#
directive|define
name|DN11
end_define

begin_comment
comment|/* "standard" DEC dialer */
end_comment

begin_define
define|#
directive|define
name|HAYES
end_define

begin_comment
comment|/* Hayes' Smartmodem */
end_comment

begin_define
define|#
directive|define
name|HAYES2400
end_define

begin_comment
comment|/* Hayes' 2400 baud Smartmodem */
end_comment

begin_comment
comment|/* #define MICOM	/* Micom Mux port */
end_comment

begin_define
define|#
directive|define
name|NOVATION
end_define

begin_comment
comment|/* Novation modem */
end_comment

begin_define
define|#
directive|define
name|PAD
end_define

begin_comment
comment|/* X.25 PAD */
end_comment

begin_define
define|#
directive|define
name|PENRIL
end_define

begin_comment
comment|/* PENRIL Dialer */
end_comment

begin_comment
comment|/* #define PNET		/* Purdue network */
end_comment

begin_define
define|#
directive|define
name|RVMACS
end_define

begin_comment
comment|/* Racal-Vadic MACS  820 dialer, 831 adaptor */
end_comment

begin_comment
comment|/* #define SYTEK	/* Sytek Local Area Net */
end_comment

begin_comment
comment|/* #define UNETTCP	/* 3Com's UNET */
end_comment

begin_define
define|#
directive|define
name|USR2400
end_define

begin_comment
comment|/* USRobotics Courier 2400 */
end_comment

begin_define
define|#
directive|define
name|VA212
end_define

begin_comment
comment|/* Racal-Vadic 212 */
end_comment

begin_define
define|#
directive|define
name|VA811S
end_define

begin_comment
comment|/* Racal-Vadic 811S dialer, 831 adaptor */
end_comment

begin_define
define|#
directive|define
name|VA820
end_define

begin_comment
comment|/* Racal-Vadic 820 dialer, 831 adaptor */
end_comment

begin_define
define|#
directive|define
name|VADIC
end_define

begin_comment
comment|/* Racal-Vadic 345x */
end_comment

begin_define
define|#
directive|define
name|VENTEL
end_define

begin_comment
comment|/* Ventel Dialer */
end_comment

begin_define
define|#
directive|define
name|VMACS
end_define

begin_comment
comment|/* Racal-Vadic MACS  811 dialer, 831 adaptor */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|USR2400
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAYES
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAYES
end_define

begin_endif
endif|#
directive|endif
endif|USR2400&& !HAYES
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|UNETTCP
argument_list|)
operator|||
name|defined
argument_list|(
name|BSDTCP
argument_list|)
end_if

begin_define
define|#
directive|define
name|TCPIP
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We need a timer to write slowly to certain modems.  * and for generating breaks.  *  * define INTERVALTIMER to use 4.[23] bsd interval timer.  * define FASTTIMER if you have the nap() system call.  * define FTIME if you have the ftime() system call.  * define BUSYLOOP if you must do a busy loop.  * Look at uucpdelay() in condevs.c for details.  */
end_comment

begin_define
define|#
directive|define
name|INTERVALTIMER
end_define

begin_comment
comment|/*#define FASTTIMER /**/
end_comment

begin_comment
comment|/*#define FTIME /**/
end_comment

begin_comment
comment|/*#define BUSYLOOP /**/
end_comment

begin_comment
comment|/*  * If your site is using "ndir.h" to retrofit the Berkeley  * directory reading routines, define NDIR.  * You will probably also have to set LIBNDIR in Makefile.  * Otherwise,<dir.h> is assumed to have the Berkeley directory definitions.  */
end_comment

begin_comment
comment|/*#define	NDIR	/**/
end_comment

begin_comment
comment|/*  * If yours is a BTL system III, IV, V or so-on site, define USG.  */
end_comment

begin_comment
comment|/*#define	USG	/**/
end_comment

begin_comment
comment|/*  * If you are running 4.3bsd, define BSD4_3 and BSD4_2  * If you are just running 4.2bsd, define BSD4_2  * If you are running the BRL version of 4.2BSD define BRL4_2, NOT BSD4_3  */
end_comment

begin_define
define|#
directive|define
name|BSD4_3
end_define

begin_comment
comment|/**/
end_comment

begin_define
define|#
directive|define
name|BSD4_2
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*#define BRL4_2 /**/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BRL4_2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSD4_2
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD4_2
end_define

begin_undef
undef|#
directive|undef
name|BSD4_3
end_undef

begin_endif
endif|#
directive|endif
endif|BRL4_2
end_endif

begin_comment
comment|/*  * If you are using /etc/inetd with 4.2bsd, define BSDINETD  */
end_comment

begin_define
define|#
directive|define
name|BSDINETD
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*  * If you are running 4.3bsd or BRL 4.2, you are running the inetd  */
end_comment

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|BSD4_3
argument_list|)
operator|||
name|defined
argument_list|(
name|BRL4_2
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|BSDINETD
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSDINETD
end_define

begin_endif
endif|#
directive|endif
endif|(BSD4_3 ||BRL4_2)&& !BSDINETD
end_endif

begin_comment
comment|/*#define VMSDTR	/* Turn on modem control on vms(works DTR) for 			   develcon and gandalf ports to gain access */
end_comment

begin_comment
comment|/*  *	If you want to use the same modem for dialing in and out define  *	DIALINOUT to be the localtion of the acucntrl program  */
end_comment

begin_comment
comment|/* #define DIALINOUT	"/usr/lib/uucp/acucntrl" /**/
end_comment

begin_comment
comment|/*  *	If you want all ACU lines to be DIALINOUT, define ALLACUINOUT  */
end_comment

begin_comment
comment|/* #define ALLACUINOUT	/**/
end_comment

begin_comment
comment|/* define the value of WFMASK - for umask call - used for all uucp work files */
end_comment

begin_define
define|#
directive|define
name|WFMASK
value|0137
end_define

begin_comment
comment|/* define the value of LOGMASK - for LOGFILE, SYSLOG, ERRLOG */
end_comment

begin_define
define|#
directive|define
name|LOGMASK
value|0133
end_define

begin_comment
comment|/* All files are given at least the following at the final destination */
end_comment

begin_comment
comment|/* It is also the default mode, so '666' is recommended */
end_comment

begin_comment
comment|/* and 444 is minimal (minimally useful, maximally annoying) */
end_comment

begin_define
define|#
directive|define
name|BASEMODE
value|0666
end_define

begin_comment
comment|/*  * Define NOSTRANGERS if you don't want to accept transactions from  * sites that are not in your L.sys file (see cico.c)  */
end_comment

begin_define
define|#
directive|define
name|NOSTRANGERS
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*  * Traditionally LCK (lock) files have been kept in /usr/spool/uucp.  * If you want that define LOCKDIR to be ".".  * If you want the locks kept in a subdirectory, define LOCKDIR as "LCK".  * Good news about LCK. subdirectory: the directory can be mode 777 so  * unprivileged programs can share the uucp locking system,  * and the subdirectory keeps down clutter in the main directory.  * The BAD news: you have to change 'tip' and another programs that  * know where the LCK files are kept, and you have to change your /etc/rc  * if your rc cleans out the lock files (as it should).  */
end_comment

begin_comment
comment|/* #define	LOCKDIR	"LCK"	/**/
end_comment

begin_define
define|#
directive|define
name|LOCKDIR
value|"."
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*  * If you want uucp and uux to copy the data files by default,  * don't define DONTCOPY (This is the way older 4bsd uucps worked)  * If you want uucp and uux to use the original files instead of  * copies, define DONTCOPY (This is the way System III and V work)  */
end_comment

begin_define
define|#
directive|define
name|DONTCOPY
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*  * Very few (that I know of) systems use the sequence checking feature.  * If you are not going to use it (hint: you are not),  * do not define GNXSEQ.  This saves precious room on PDP11s.  */
end_comment

begin_comment
comment|/*#define	GNXSEQ	/* comment this out to save space */
end_comment

begin_comment
comment|/*  * If you want the logfile stored in a file for each site instead  * of one file  * define LOGBYSITE as the directory to put the files in  */
end_comment

begin_comment
comment|/* #define LOGBYSITE	"/usr/spool/uucp/LOG" /**/
end_comment

begin_comment
comment|/*  * define USE_SYSLOG if you want error messages to use SYSLOG instead  * of being written to /usr/spool/log/ERRLOG  */
end_comment

begin_define
define|#
directive|define
name|USE_SYSLOG
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/*  * If you are doing rebilling and need connect accounting,  * define DO_CONNECT_ACCOUNTING to be the accounting file name  */
end_comment

begin_comment
comment|/*#define DO_CONNECT_ACCOUNTING	"/usr/spool/uucp/CONNECT"	/**/
end_comment

begin_define
define|#
directive|define
name|XQTDIR
value|"/usr/spool/uucp/XTMP"
end_define

begin_define
define|#
directive|define
name|SQFILE
value|"/usr/lib/uucp/SQFILE"
end_define

begin_define
define|#
directive|define
name|SQTMP
value|"/usr/lib/uucp/SQTMP"
end_define

begin_define
define|#
directive|define
name|SLCKTIME
value|5400
end_define

begin_comment
comment|/* system/device timeout (LCK.. files) */
end_comment

begin_define
define|#
directive|define
name|SEQFILE
value|"/usr/lib/uucp/SEQF"
end_define

begin_define
define|#
directive|define
name|SYSFILE
value|"/usr/lib/uucp/L.sys"
end_define

begin_define
define|#
directive|define
name|DEVFILE
value|"/usr/lib/uucp/L-devices"
end_define

begin_define
define|#
directive|define
name|DIALFILE
value|"/usr/lib/uucp/L-dialcodes"
end_define

begin_define
define|#
directive|define
name|USERFILE
value|"/usr/lib/uucp/USERFILE"
end_define

begin_define
define|#
directive|define
name|CMDFILE
value|"/usr/lib/uucp/L.cmds"
end_define

begin_define
define|#
directive|define
name|ALIASFILE
value|"/usr/lib/uucp/L.aliases"
end_define

begin_define
define|#
directive|define
name|SPOOL
value|"/usr/spool/uucp"
end_define

begin_define
define|#
directive|define
name|SYSLOG
value|"/usr/spool/uucp/SYSLOG"
end_define

begin_define
define|#
directive|define
name|PUBDIR
value|"/usr/spool/uucppublic"
end_define

begin_define
define|#
directive|define
name|SQLOCK
value|"SQ"
end_define

begin_define
define|#
directive|define
name|SEQLOCK
value|"SEQL"
end_define

begin_define
define|#
directive|define
name|CMDPRE
value|'C'
end_define

begin_define
define|#
directive|define
name|DATAPRE
value|'D'
end_define

begin_define
define|#
directive|define
name|XQTPRE
value|'X'
end_define

begin_define
define|#
directive|define
name|LOGFILE
value|"/usr/spool/uucp/LOGFILE"
end_define

begin_define
define|#
directive|define
name|ERRLOG
value|"/usr/spool/uucp/ERRLOG"
end_define

begin_define
define|#
directive|define
name|CMDSDIR
value|"/usr/spool/uucp/C."
end_define

begin_define
define|#
directive|define
name|DATADIR
value|"/usr/spool/uucp/D."
end_define

begin_define
define|#
directive|define
name|XEQTDIR
value|"/usr/spool/uucp/X."
end_define

begin_define
define|#
directive|define
name|RMTDEBUG
value|"AUDIT"
end_define

begin_define
define|#
directive|define
name|CORRUPT
value|"CORRUPT"
end_define

begin_define
define|#
directive|define
name|SQTIME
value|60
end_define

begin_define
define|#
directive|define
name|TRYCALLS
value|2
end_define

begin_comment
comment|/* number of tries to dial call */
end_comment

begin_define
define|#
directive|define
name|LLEN
value|150
end_define

begin_define
define|#
directive|define
name|MAXRQST
value|250
end_define

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|l
parameter_list|,
name|f
parameter_list|,
name|s
parameter_list|)
value|if (Debug>= l) fprintf(stderr, f, s); else
end_define

begin_define
define|#
directive|define
name|delock
parameter_list|(
name|dev
parameter_list|)
value|rmlock(dev)
end_define

begin_define
define|#
directive|define
name|mlock
parameter_list|(
name|dev
parameter_list|)
value|ulockf(dev, SLCKTIME)
end_define

begin_define
define|#
directive|define
name|SAME
value|0
end_define

begin_define
define|#
directive|define
name|ANYREAD
value|0004
end_define

begin_define
define|#
directive|define
name|ANYWRITE
value|02
end_define

begin_define
define|#
directive|define
name|FAIL
value|-1
end_define

begin_define
define|#
directive|define
name|SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|CNULL
value|(char *) 0
end_define

begin_define
define|#
directive|define
name|STBNULL
value|(struct sgttyb *) 0
end_define

begin_define
define|#
directive|define
name|MASTER
value|1
end_define

begin_define
define|#
directive|define
name|SLAVE
value|0
end_define

begin_define
define|#
directive|define
name|MAXFULLNAME
value|255
end_define

begin_define
define|#
directive|define
name|MAXMSGTIME
value|45
end_define

begin_define
define|#
directive|define
name|NAMESIZE
value|255
end_define

begin_define
define|#
directive|define
name|MAXBASENAME
value|14
end_define

begin_define
define|#
directive|define
name|SYSNSIZE
value|(MAXBASENAME-1-1-1-4)
end_define

begin_define
define|#
directive|define
name|EOTMSG
value|"\04\n\04\n"
end_define

begin_define
define|#
directive|define
name|CALLBACK
value|1
end_define

begin_define
define|#
directive|define
name|ONEDAY
value|86400L
end_define

begin_comment
comment|/*  commands  */
end_comment

begin_define
define|#
directive|define
name|SHELL
value|"/bin/sh"
end_define

begin_define
define|#
directive|define
name|MAIL
value|"/usr/lib/sendmail"
end_define

begin_define
define|#
directive|define
name|UUCICO
value|"/usr/lib/uucp/uucico"
end_define

begin_define
define|#
directive|define
name|UUXQT
value|"/usr/lib/uucp/uuxqt"
end_define

begin_define
define|#
directive|define
name|UUCP
value|"uucp"
end_define

begin_comment
comment|/*  call connect fail stuff  */
end_comment

begin_define
define|#
directive|define
name|CF_SYSTEM
value|-1
end_define

begin_define
define|#
directive|define
name|CF_TIME
value|-2
end_define

begin_define
define|#
directive|define
name|CF_LOCK
value|-3
end_define

begin_define
define|#
directive|define
name|CF_NODEV
value|-4
end_define

begin_define
define|#
directive|define
name|CF_DIAL
value|-5
end_define

begin_define
define|#
directive|define
name|CF_LOGIN
value|-6
end_define

begin_define
define|#
directive|define
name|F_NAME
value|0
end_define

begin_define
define|#
directive|define
name|F_TIME
value|1
end_define

begin_define
define|#
directive|define
name|F_LINE
value|2
end_define

begin_define
define|#
directive|define
name|F_CLASS
value|3
end_define

begin_comment
comment|/* an optional prefix and the speed */
end_comment

begin_define
define|#
directive|define
name|F_PHONE
value|4
end_define

begin_define
define|#
directive|define
name|F_LOGIN
value|5
end_define

begin_define
define|#
directive|define
name|MAXPH
value|60
end_define

begin_comment
comment|/* maximum length of a phone number */
end_comment

begin_comment
comment|/* This structure tells how to get to a device */
end_comment

begin_struct
struct|struct
name|condev
block|{
name|char
modifier|*
name|CU_meth
decl_stmt|;
comment|/* method, such as 'ACU' or 'DIR' */
name|char
modifier|*
name|CU_brand
decl_stmt|;
comment|/* brand, such as 'Hayes' or 'Vadic' */
name|int
function_decl|(
modifier|*
name|CU_gen
function_decl|)
parameter_list|()
function_decl|;
comment|/* what to call to search for brands */
name|int
function_decl|(
modifier|*
name|CU_open
function_decl|)
parameter_list|()
function_decl|;
comment|/* what to call to open brand */
name|int
function_decl|(
modifier|*
name|CU_clos
function_decl|)
parameter_list|()
function_decl|;
comment|/* what to call to close brand */
block|}
struct|;
end_struct

begin_comment
comment|/* This structure tells about a device */
end_comment

begin_struct
struct|struct
name|Devices
block|{
define|#
directive|define
name|D_type
value|D_arg[0]
define|#
directive|define
name|D_line
value|D_arg[1]
define|#
directive|define
name|D_calldev
value|D_arg[2]
define|#
directive|define
name|D_class
value|D_arg[3]
define|#
directive|define
name|D_brand
value|D_arg[4]
define|#
directive|define
name|D_CHAT
value|5
name|int
name|D_numargs
decl_stmt|;
name|int
name|D_speed
decl_stmt|;
name|char
modifier|*
name|D_arg
index|[
literal|20
index|]
decl_stmt|;
name|char
name|D_argbfr
index|[
literal|100
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  system status stuff  */
end_comment

begin_define
define|#
directive|define
name|SS_OK
value|0
end_define

begin_define
define|#
directive|define
name|SS_NODEVICE
value|1
end_define

begin_define
define|#
directive|define
name|SS_CALLBACK
value|2
end_define

begin_define
define|#
directive|define
name|SS_INPROGRESS
value|3
end_define

begin_define
define|#
directive|define
name|SS_FAIL
value|4
end_define

begin_define
define|#
directive|define
name|SS_BADSEQ
value|5
end_define

begin_define
define|#
directive|define
name|SS_WRONGTIME
value|6
end_define

begin_comment
comment|/*  fail/retry parameters  */
end_comment

begin_define
define|#
directive|define
name|RETRYTIME
value|600
end_define

begin_define
define|#
directive|define
name|MAXRECALLS
value|25
end_define

begin_comment
comment|/*  stuff for command execution  */
end_comment

begin_define
define|#
directive|define
name|X_RQDFILE
value|'F'
end_define

begin_define
define|#
directive|define
name|X_STDIN
value|'I'
end_define

begin_define
define|#
directive|define
name|X_STDOUT
value|'O'
end_define

begin_define
define|#
directive|define
name|X_CMD
value|'C'
end_define

begin_define
define|#
directive|define
name|X_USER
value|'U'
end_define

begin_define
define|#
directive|define
name|X_SENDFILE
value|'S'
end_define

begin_define
define|#
directive|define
name|X_NONOTI
value|'N'
end_define

begin_define
define|#
directive|define
name|X_RETURNTO
value|'R'
end_define

begin_define
define|#
directive|define
name|X_NONZERO
value|'Z'
end_define

begin_define
define|#
directive|define
name|X_LOCK
value|"XQT"
end_define

begin_define
define|#
directive|define
name|X_LOCKTIME
value|3600L
end_define

begin_define
define|#
directive|define
name|WKDSIZE
value|100
end_define

begin_comment
comment|/*  size of work dir name  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|USG
end_ifndef

begin_include
include|#
directive|include
file|<sys/timeb.h>
end_include

begin_else
else|#
directive|else
else|USG
end_else

begin_struct
struct|struct
name|timeb
block|{
name|time_t
name|time
decl_stmt|;
name|unsigned
name|short
name|millitm
decl_stmt|;
name|short
name|timezone
decl_stmt|;
name|short
name|dstflag
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rindex
value|strrchr
end_define

begin_define
define|#
directive|define
name|index
value|strchr
end_define

begin_endif
endif|#
directive|endif
endif|USG
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_2
end_ifdef

begin_include
include|#
directive|include
file|<syslog.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4_2 */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|timeb
name|Now
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Ifn
decl_stmt|,
name|Ofn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Rmtname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|User
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Loginuser
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Spool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Myname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Myfullname
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Bspeed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Wrkdir
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|time_t
name|Retrytime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|short
name|Usrf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|IsTcpIp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|Progname
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|CU_end
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|condev
name|condevs
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|NOLOGIN
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|DLocal
index|[]
decl_stmt|,
name|DLocalX
index|[]
decl_stmt|,
modifier|*
name|subfile
argument_list|()
decl_stmt|,
modifier|*
name|subdir
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Commonly called routines which return non-int value */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ttyname
argument_list|()
decl_stmt|,
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|,
modifier|*
name|index
argument_list|()
decl_stmt|,
modifier|*
name|rindex
argument_list|()
decl_stmt|,
modifier|*
name|fgets
argument_list|()
decl_stmt|,
modifier|*
name|calloc
argument_list|()
decl_stmt|,
modifier|*
name|malloc
argument_list|()
decl_stmt|,
modifier|*
name|fdig
argument_list|()
decl_stmt|,
modifier|*
name|ttyname
argument_list|()
decl_stmt|,
modifier|*
name|cfgets
argument_list|()
decl_stmt|,
modifier|*
name|getwd
argument_list|()
decl_stmt|,
modifier|*
name|strpbrk
argument_list|()
decl_stmt|,
modifier|*
name|strncpy
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|time
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
name|_FAILED
index|[]
decl_stmt|,
name|CANTOPEN
index|[]
decl_stmt|,
name|DEVNULL
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|lint
end_ifdef

begin_comment
comment|/* This horrible gross kludge is the only way I know to  * convince lint that signal(SIGINT,SIG_IGN) is legal. It hates SIG_IGN.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIG_IGN
end_ifdef

begin_undef
undef|#
directive|undef
name|SIG_IGN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIG_IGN */
end_comment

begin_define
define|#
directive|define
name|SIG_IGN
value|main
end_define

begin_function_decl
specifier|extern
name|int
name|main
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_undef
undef|#
directive|undef
name|DEBUG
end_undef

begin_endif
endif|#
directive|endif
endif|DEBUG
end_endif

begin_define
define|#
directive|define
name|DEBUG
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

end_unit

