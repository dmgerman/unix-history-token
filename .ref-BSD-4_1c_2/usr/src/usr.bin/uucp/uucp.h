begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)uucp.h	4.4	(Berkeley)	2/18/83	*/
end_comment

begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_comment
comment|/* define DATAKIT if datakit is available */
end_comment

begin_comment
comment|/* define DIALOUT if new dialout routine is to be used */
end_comment

begin_comment
comment|/* define the last characters for ACU */
end_comment

begin_define
define|#
directive|define
name|ACULAST
value|"-<"
end_define

begin_comment
comment|/*  some system names  */
end_comment

begin_comment
comment|/*  put in local uucp name of this machine */
end_comment

begin_comment
comment|/*  * For UCB 4.1A and Later System, you will have the gethostname(2) call.  * if this call exists, define GETHOST.  *  * For BTL 3.0 and Later USG products, the uname(2) call is used.  * If your systemis one of these, use this call,  *  * Otherwise, you must set the string to your system name.  */
end_comment

begin_define
define|#
directive|define
name|GETHOST
value|1
end_define

begin_comment
comment|/* We have a 4.1A System */
end_comment

begin_comment
comment|/* #define UNAME	1 */
end_comment

begin_comment
comment|/* #define MYNAME	"hostnameunknown" */
end_comment

begin_comment
comment|/*  * If you have a Berkeley UNIX system, include<sysexits.h> to use exit  * codes that will be understood by sendmail.  *	Otherwise, define EX_NOHOST and EX_CANTCREAT.  */
end_comment

begin_include
include|#
directive|include
file|<sysexits.h>
end_include

begin_comment
comment|/* #define EX_NOHOST	101 */
end_comment

begin_comment
comment|/* #define EX_CANTCREAT	1 */
end_comment

begin_comment
comment|/*  * define LONGNAMES if you have login names>8 chars long.  * This isn't handled too cleanly - they are arbitrarily truncated  * at 8 for entries in the control files to avoid choking remote  * sites which haven't allocated enough space for the username.  * This unfortunately may cause return mail to be lost.  Sigh.  */
end_comment

begin_comment
comment|/* #define	LONGNAMES	1 */
end_comment

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
name|THISDIR
value|"/usr/lib/uucp"
end_define

begin_define
define|#
directive|define
name|XQTDIR
value|"/usr/lib/uucp/.XQTDIR"
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
name|SYSFILECR
value|"/usr/lib/uucp/L.sys.cr"
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
name|SPOOL
value|"/usr/spool/uucp"
end_define

begin_define
define|#
directive|define
name|LOGDIR
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
name|LOGPREFIX
value|"LOG."
end_define

begin_define
define|#
directive|define
name|LOGLOCK
value|"/usr/spool/uucp/LCK.LOG"
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
name|RMTDEBUG
value|"AUDIT"
end_define

begin_define
define|#
directive|define
name|SQTIME
value|60L
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
name|DEBUG
parameter_list|(
name|l
parameter_list|,
name|f
parameter_list|,
name|s
parameter_list|)
value|if (Debug>= l) fprintf(stderr, f, s)
end_define

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|e
parameter_list|,
name|f
parameter_list|,
name|v
parameter_list|)
value|if (!(e)) {\ fprintf(stderr, "AERROR - (%s) ", "e");\ fprintf(stderr, f, v);\ fprintf(stderr, "\n");\ cleanup(FAIL);};
end_define

begin_define
define|#
directive|define
name|FMV
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|close(n); dup(p[n]); close(p[n]);
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
value|256
end_define

begin_define
define|#
directive|define
name|MAXMSGTIME
value|100
end_define

begin_define
define|#
directive|define
name|MAXCHARTIME
value|8
end_define

begin_comment
comment|/* Time to wait between sending "expect" field in conn.c */
end_comment

begin_define
define|#
directive|define
name|NAMESIZE
value|256
end_define

begin_define
define|#
directive|define
name|EOTMSG
value|"\004\n\004\n"
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
name|CF_DIAL
value|-5
end_define

begin_define
define|#
directive|define
name|CF_LOGIN
value|-6
end_define

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
value|3300L
end_define

begin_define
define|#
directive|define
name|INPROGTIME
value|7200L
end_define

begin_define
define|#
directive|define
name|MAXRECALLS
value|10
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
value|3600L
end_define

begin_decl_stmt
name|int
name|Ifn
decl_stmt|,
name|Ofn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Rmtname
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|User
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Loginuser
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Thisdir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Spool
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Myname
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Sysfiles
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Devfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Dialfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Pkdebug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Pkdrvon
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Bspeed
decl_stmt|;
end_decl_stmt

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
name|char
name|Wrkdir
index|[
name|WKDSIZE
index|]
decl_stmt|;
end_decl_stmt

end_unit

