begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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

begin_comment
comment|/* define UNAME if uname() should be used to get uucpname */
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

begin_define
define|#
directive|define
name|MYNAME
value|"ucbvax"
end_define

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
value|if (!(e)) {\ fprintf(stderr, "AERROR - (%s) ", "e");\ fprintf(stderr, f, v);\ cleanup(FAIL);};
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
value|100
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
name|MAXCHARTIME
value|15
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
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|User
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|Loginuser
index|[
literal|10
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
literal|8
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

