begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	uucp.h	5.2	83/07/19	*/
end_comment

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_comment
comment|/*  * Determine local uucp name of this machine.  * Define one of the following:  *  * For UCB 4.1A and later systems, you will have the gethostname(2) call.  * If this call exists, define GETHOSTNAME.  *  * For USG 3.0 and later systems, you will have the uname(2) call.  * If this call exists, define UNAME.  *  * Some systems have a line of the form '#define sysname "myuucpname",'  * in the file /usr/include/whoami.h, to identify their machine.  * If your site does that, define WHOAMI.  *  * If your site has<whoami.h>, but you do not want to read  * that file every time uucp runs, you can compile sysname into uucp.  * This is faster and more reliable, but binaries do not port.  * If you want to do that, define CCWHOAMI.  *  * Some systems put the local uucp name in a single-line file  * named /etc/uucpname or /local/uucpname.  * If your site does that, define UUNAME.  *  * Systems running 3Com's UNET will have the getmyhname() call.  * If you want to, define GETMYHNAME.  *  * You should also define MYNANE to be your uucp name.  *  * For each of the above that are defined, uucp checks them in order.  * It stops on the first method that returns a non null name.  * If everything fails, it uses "unknown" for the system name.  */
end_comment

begin_define
define|#
directive|define
name|GETHOSTNAME
end_define

begin_comment
comment|/* If the above fails ... */
end_comment

begin_define
define|#
directive|define
name|MYNAME
value|"erewhon"
end_define

begin_comment
comment|/*  * If you have it, include<sysexits.h> to use exit  * codes that will be understood by sendmail.  * Otherwise, define EX_NOHOST, EX_CANTCREAT, and EX_NOINPUT.  */
end_comment

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_comment
comment|/*#define EX_NOHOST	101*/
end_comment

begin_comment
comment|/*#define EX_CANTCREAT	1*/
end_comment

begin_comment
comment|/*#define EX_NOINPUT	2*/
end_comment

begin_comment
comment|/* define UUDIR for uucp subdirectory kludge (recommended) */
end_comment

begin_define
define|#
directive|define
name|UUDIR
end_define

begin_comment
comment|/*  * Define the various kinds of connections to include.  * The complete list is in the condevs array in condevs.c  */
end_comment

begin_define
define|#
directive|define
name|DN11
end_define

begin_comment
comment|/* standard dialer */
end_comment

begin_comment
comment|/*#define DATAKIT		/* ATT's datakit */
end_comment

begin_comment
comment|/*#define PNET		/* Purdue network */
end_comment

begin_comment
comment|/*#define DF02		/* Dec's DF02/DF03 */
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
name|VENTEL
end_define

begin_comment
comment|/* ventel dialer */
end_comment

begin_define
define|#
directive|define
name|VADIC
end_define

begin_comment
comment|/* Racal-Vadic 3450 */
end_comment

begin_comment
comment|/*#define RVMACS		/* Racal-Vadic MACS 831 */
end_comment

begin_comment
comment|/*#define UNET		/* 3Com's UNET */
end_comment

begin_comment
comment|/*#define MICOM		/* micom mux port */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VENTEL
end_ifdef

begin_comment
comment|/*  * We need a timer to write slowly to ventels.  * define INTERVALTIMER to use 4.2 bsd interval timer.  * define FASTTIMER if you have the nap() system call.  * define FTIME if you have the ftime() system call.  * define BUSYLOOP if you must do a busy loop.  * Look at uucpdelay() in condevs.c for details.  */
end_comment

begin_define
define|#
directive|define
name|FTIME
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If your site is using "ndir.h" to retrofit the Berkeley  * directory reading routines, define NDIR.  * You will probably also have to set LIBNDIR in Makefile.  * Otherwise,<dir.h> is assumed to have the Berkeley directory definitions.  */
end_comment

begin_comment
comment|/*#define	NDIR*/
end_comment

begin_comment
comment|/*  * If yours is a BTL system III, IV, or so-on site, define SYSIII.  * Conditional compilations should produce the right code,  * but if it doesn't (the compiler will probably complain loudly),  * make the needed adjustments and guard the code with  * #ifdef SYSIII, (code for system III), #else, (code for V7), #endif  */
end_comment

begin_comment
comment|/*#define	SYSIII*/
end_comment

begin_comment
comment|/* define the last characters for ACU */
end_comment

begin_comment
comment|/* burl!lda, rti!trt, isn't "<" more widely used than "-"? */
end_comment

begin_comment
comment|/* rti!trt: use -< as is done in 4.1c uucp */
end_comment

begin_define
define|#
directive|define
name|ACULAST
value|"-<"
end_define

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
comment|/* All users with getuid()<= PRIV_UIDS are 'privileged'. */
end_comment

begin_comment
comment|/* Was 10, reduced to 3 as suggested by duke!dbl (David Leonard) */
end_comment

begin_define
define|#
directive|define
name|PRIV_UIDS
value|3
end_define

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
name|SPOOL
value|"/usr/spool/uucp"
end_define

begin_define
define|#
directive|define
name|SQLOCK
value|"/usr/spool/uucp/LCK.SQ"
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
name|SEQLOCK
value|"LCK.SEQL"
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
name|RMTDEBUG
value|"AUDIT"
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

begin_comment
comment|/*define PROTODEBUG = 1 if testing protocol - introduce errors */
end_comment

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
name|ASSERT
parameter_list|(
name|e
parameter_list|,
name|s1
parameter_list|,
name|s2
parameter_list|,
name|i1
parameter_list|)
value|if (!(e)) {\ assert(s1, s2, i1);\ cleanup(FAIL);} else
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
value|04
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
value|250
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
value|15
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
value|"mail"
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
name|char
name|D_type
index|[
literal|20
index|]
decl_stmt|;
name|char
name|D_line
index|[
literal|20
index|]
decl_stmt|;
name|char
name|D_calldev
index|[
literal|20
index|]
decl_stmt|;
name|char
name|D_class
index|[
literal|20
index|]
decl_stmt|;
name|int
name|D_speed
decl_stmt|;
name|char
name|D_brand
index|[
literal|20
index|]
decl_stmt|;
comment|/* brand name, as 'Hayes' or 'Vadic' */
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
name|SS_FAIL
value|4
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
name|SS_BADSEQ
value|5
end_define

begin_comment
comment|/*  fail/retry parameters  */
end_comment

begin_define
define|#
directive|define
name|RETRYTIME
value|3300
end_define

begin_define
define|#
directive|define
name|MAXRECALLS
value|20
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
name|X_NONZERO
value|'Z'
end_define

begin_define
define|#
directive|define
name|X_LOCK
value|"LCK.XQT"
end_define

begin_define
define|#
directive|define
name|X_LOCKTIME
value|3600
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
name|Rmtname
index|[]
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
name|int
name|Debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Pkdebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Pkdrvon
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
name|long
name|Retrytime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Unet
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

begin_ifdef
ifdef|#
directive|ifdef
name|UUDIR
end_ifdef

begin_define
define|#
directive|define
name|subfile
parameter_list|(
name|s
parameter_list|)
value|SubFile(s)
end_define

begin_define
define|#
directive|define
name|subdir
parameter_list|(
name|d
parameter_list|,
name|p
parameter_list|)
value|SubDir(d, p)
end_define

begin_define
define|#
directive|define
name|subchdir
parameter_list|(
name|d
parameter_list|)
value|SubChDir(d)
end_define

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
name|SubFile
argument_list|()
decl_stmt|,
modifier|*
name|SubDir
argument_list|()
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|subfile
parameter_list|(
name|s
parameter_list|)
value|s
end_define

begin_define
define|#
directive|define
name|subdir
parameter_list|(
name|d
parameter_list|,
name|p
parameter_list|)
value|d
end_define

begin_define
define|#
directive|define
name|subchdir
parameter_list|(
name|d
parameter_list|)
value|chdir(d)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|cfgets
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
name|FILE
modifier|*
name|rpopen
parameter_list|()
function_decl|;
end_function_decl

end_unit

