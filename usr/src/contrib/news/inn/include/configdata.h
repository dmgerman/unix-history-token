begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.29 $ ** **  Here be configuration data used by various InterNetNews programs. **  The numbers refer to sections in the config.dist file. */
end_comment

begin_comment
comment|/* **  1.  MAKE CONFIG PARAMETERS */
end_comment

begin_comment
comment|/* =()<#define @<USE_CHAR_CONST>@_USE_CHAR_CONST>()= */
end_comment

begin_define
define|#
directive|define
name|DUNNO_USE_CHAR_CONST
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DO_USE_CHAR_CONST
argument_list|)
end_if

begin_typedef
typedef|typedef
name|char
specifier|const
modifier|*
name|STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
specifier|const
name|CSTRING
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DO_USE_CHAR_CONST) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DONT_USE_CHAR_CONST
argument_list|)
end_if

begin_typedef
typedef|typedef
name|char
modifier|*
name|STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|CSTRING
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DONT_USE_CHAR_CONST) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DUNNO_USE_CHAR_CONST
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|char
specifier|const
modifier|*
name|STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
specifier|const
name|CSTRING
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
modifier|*
name|STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|CSTRING
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__STDC__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DUNNO_USE_CHAR_CONST) */
end_comment

begin_comment
comment|/* **  Declare a function that doesn't return. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__dead
argument_list|)
end_if

begin_comment
comment|/* BSD4.4 */
end_comment

begin_define
define|#
directive|define
name|NORETURN
value|__dead
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
name|__GNUC__
argument_list|)
end_if

begin_comment
comment|/* GCC */
end_comment

begin_define
define|#
directive|define
name|NORETURN
value|volatile void
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Everyone else */
end_comment

begin_define
define|#
directive|define
name|NORETURN
value|void
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__GNUC__) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__dead) */
end_comment

begin_comment
comment|/* **  3.  OWNERSHIPS AND FILE MODES */
end_comment

begin_comment
comment|/* =()<#define NEWSUSER		"@<NEWSUSER>@">()= */
end_comment

begin_define
define|#
directive|define
name|NEWSUSER
value|"news"
end_define

begin_comment
comment|/* =()<#define NEWSGID		"@<NEWSGROUP>@">()= */
end_comment

begin_define
define|#
directive|define
name|NEWSGID
value|"news"
end_define

begin_comment
comment|/* =()<#define NEWSMASTER		"@<NEWSMASTER>@">()= */
end_comment

begin_define
define|#
directive|define
name|NEWSMASTER
value|"usenet"
end_define

begin_comment
comment|/* =()<#define PATHMASTER		"@<PATHMASTER>@">()= */
end_comment

begin_define
define|#
directive|define
name|PATHMASTER
value|"not-for-mail"
end_define

begin_comment
comment|/* Umask to set. */
end_comment

begin_comment
comment|/* =()<#define NEWSUMASK		@<NEWSUMASK>@>()= */
end_comment

begin_define
define|#
directive|define
name|NEWSUMASK
value|02
end_define

begin_comment
comment|/* Mode that incoming articles are created under. */
end_comment

begin_comment
comment|/* =()<#define ARTFILE_MODE	@<ARTFILE_MODE>@>()= */
end_comment

begin_define
define|#
directive|define
name|ARTFILE_MODE
value|0664
end_define

begin_comment
comment|/* Mode that batch files are created under. */
end_comment

begin_comment
comment|/* =()<#define BATCHFILE_MODE	@<BATCHFILE_MODE>@>()= */
end_comment

begin_define
define|#
directive|define
name|BATCHFILE_MODE
value|0664
end_define

begin_comment
comment|/* Mode that directories are created under. */
end_comment

begin_comment
comment|/* =()<#define GROUPDIR_MODE	@<GROUPDIR_MODE>@>()= */
end_comment

begin_define
define|#
directive|define
name|GROUPDIR_MODE
value|0775
end_define

begin_comment
comment|/* **  4.  C LIBRARY DIFFERENCES */
end_comment

begin_comment
comment|/* Use have stdargs, varargs, or neither? */
end_comment

begin_comment
comment|/* =()<#define VAR_@<VAR_STYLE>@>()= */
end_comment

begin_define
define|#
directive|define
name|VAR_STDARGS
end_define

begin_comment
comment|/* Use BSD4.2 or Posix directory names? */
end_comment

begin_comment
comment|/* =()<#define DIR_@<DIR_STYLE>@>()= */
end_comment

begin_define
define|#
directive|define
name|DIR_DIRENT
end_define

begin_comment
comment|/* Use flock, lockf, or nothing to lock files? */
end_comment

begin_comment
comment|/* =()<#define LOCK_@<LOCK_STYLE>@>()= */
end_comment

begin_define
define|#
directive|define
name|LOCK_FLOCK
end_define

begin_comment
comment|/* Do you have<unistd.h>? */
end_comment

begin_comment
comment|/* =()<#define @<HAVE_UNISTD>@_HAVE_UNISTD>()= */
end_comment

begin_define
define|#
directive|define
name|DO_HAVE_UNISTD
end_define

begin_comment
comment|/* Do you have setbuffer? */
end_comment

begin_comment
comment|/* =()<#define @<HAVE_SETBUFFER>@_HAVE_SETBUFFER>()= */
end_comment

begin_define
define|#
directive|define
name|DO_HAVE_SETBUFFER
end_define

begin_comment
comment|/* Do you have gettimeofday? */
end_comment

begin_comment
comment|/* =()<#define @<HAVE_GETTIMEOFDAY>@_HAVE_GETTIMEOFDAY>()= */
end_comment

begin_define
define|#
directive|define
name|DO_HAVE_GETTIMEOFDAY
end_define

begin_comment
comment|/* Do you have fchmod? */
end_comment

begin_comment
comment|/* =()<#define @<HAVE_FCHMOD>@_HAVE_FCHMOD>()= */
end_comment

begin_define
define|#
directive|define
name|DO_HAVE_FCHMOD
end_define

begin_comment
comment|/* Do you have setsid()? */
end_comment

begin_comment
comment|/* =()<#define @<HAVE_SETSID>@_HAVE_SETSID>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_HAVE_SETSID
end_define

begin_comment
comment|/* Does your (struct tm) have a tm_gmtoff field? */
end_comment

begin_comment
comment|/* =()<#define @<HAVE_TM_GMTOFF>@_HAVE_TM_GMTOFF>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_HAVE_TM_GMTOFF
end_define

begin_comment
comment|/* Does your (struct stat) have a st_blksize field? */
end_comment

begin_comment
comment|/* =()<#define @<HAVE_ST_BLKSIZE>@_HAVE_ST_BLKSIZE>()= */
end_comment

begin_define
define|#
directive|define
name|DO_HAVE_ST_BLKSIZE
end_define

begin_comment
comment|/* Use waitpid instead of wait3? */
end_comment

begin_comment
comment|/* =()<#define @<HAVE_WAITPID>@_HAVE_WAITPID>()= */
end_comment

begin_define
define|#
directive|define
name|DO_HAVE_WAITPID
end_define

begin_comment
comment|/* Use "union wait" instead of int? */
end_comment

begin_comment
comment|/* =()<#define @<USE_UNION_WAIT>@_USE_UNION_WAIT>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_USE_UNION_WAIT
end_define

begin_comment
comment|/* How to fork? */
end_comment

begin_comment
comment|/* =()<#define FORK()	@<FORK>@()>()= */
end_comment

begin_define
define|#
directive|define
name|FORK
parameter_list|()
value|vfork()
end_define

begin_comment
comment|/* Do you have symbolic links? */
end_comment

begin_comment
comment|/* =()<#define @<HAVE_SYMLINK>@_HAVE_SYMLINK>()= */
end_comment

begin_define
define|#
directive|define
name|DO_HAVE_SYMLINK
end_define

begin_comment
comment|/* Does your AF_UNIX bind use sizeof for the socket size? */
end_comment

begin_comment
comment|/* =()<#define @<BIND_USE_SIZEOF>@_BIND_USE_SIZEOF>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_BIND_USE_SIZEOF
end_define

begin_comment
comment|/* Do you have Unix-domain sockets? */
end_comment

begin_comment
comment|/* =()<#define @<HAVE_UNIX_DOMAIN>@_HAVE_UNIX_DOMAIN>()= */
end_comment

begin_define
define|#
directive|define
name|DO_HAVE_UNIX_DOMAIN
end_define

begin_comment
comment|/* How should close-on-exec be done? */
end_comment

begin_comment
comment|/* =()<#define CLX_@<CLX_STYLE>@>()= */
end_comment

begin_define
define|#
directive|define
name|CLX_IOCTL
end_define

begin_comment
comment|/* How should non-blocking I/O be done? */
end_comment

begin_comment
comment|/* =()<#define NBIO_@<NBIO_STYLE>@>()= */
end_comment

begin_define
define|#
directive|define
name|NBIO_FCNTL
end_define

begin_comment
comment|/* How should resource-totalling be done? */
end_comment

begin_comment
comment|/* =()<#define RES_@<RES_STYLE>@>()= */
end_comment

begin_define
define|#
directive|define
name|RES_RUSAGE
end_define

begin_comment
comment|/* How to get number of available descriptors? */
end_comment

begin_comment
comment|/* =()<#define FDCOUNT_@<FDCOUNT_STYLE>@>()= */
end_comment

begin_define
define|#
directive|define
name|FDCOUNT_GETDTAB
end_define

begin_comment
comment|/* If greater than -1, then use [gs]etrlimit to set that many descriptors. */
end_comment

begin_comment
comment|/* If -1, then no [gs]etrlimit calls are done. */
end_comment

begin_comment
comment|/* =()<#define NOFILE_LIMIT		@<NOFILE_LIMIT>@>()= */
end_comment

begin_define
define|#
directive|define
name|NOFILE_LIMIT
value|-1
end_define

begin_comment
comment|/* Do you need<time.h> as well as<sys/time.h>? */
end_comment

begin_comment
comment|/* =()<#define @<NEED_TIME>@_NEED_TIME>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_NEED_TIME
end_define

begin_comment
comment|/* What predicate, if any, the<ctype.h> macros need. */
end_comment

begin_comment
comment|/* =()<#define CTYPE(isXXXXX, c)	(@<CTYPE>@)>()= */
end_comment

begin_define
define|#
directive|define
name|CTYPE
parameter_list|(
name|isXXXXX
parameter_list|,
name|c
parameter_list|)
value|((isascii((c))&& isXXXXX((c))))
end_define

begin_comment
comment|/* **  6.  MISCELLANEOUS CONFIG DATA */
end_comment

begin_comment
comment|/* Use mmap() to read the active file, or read it in? */
end_comment

begin_comment
comment|/* =()<#define ACT_@<ACT_STYLE>@>()= */
end_comment

begin_define
define|#
directive|define
name|ACT_READ
end_define

begin_comment
comment|/* Use our NNTP-server-open routine, or the one in NNTP? */
end_comment

begin_comment
comment|/* INND is nicer, but you must install inn.conf files everywhere; NNTP */
end_comment

begin_comment
comment|/* is better if you already have lots of /usr/lib/news/server files. */
end_comment

begin_comment
comment|/* =()<#define REM_@<REM_STYLE>@>()= */
end_comment

begin_define
define|#
directive|define
name|REM_INND
end_define

begin_comment
comment|/* Should rnews save articles that the server rejects? */
end_comment

begin_comment
comment|/* =()<#define @<RNEWS_SAVE_BAD>@_RNEWS_SAVE_BAD>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_RNEWS_SAVE_BAD
end_define

begin_comment
comment|/* Should rnews syslog articles innd already has? */
end_comment

begin_comment
comment|/* =()<#define @<RNEWS_LOG_DUPS>@_RNEWS_LOG_DUPS>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_RNEWS_LOG_DUPS
end_define

begin_comment
comment|/* Look in _PATH_RNEWSPROGS for rnews unpackers? */
end_comment

begin_comment
comment|/* =()<#define @<RNEWSPROGS>@_RNEWSPROGS>()= */
end_comment

begin_define
define|#
directive|define
name|DO_RNEWSPROGS
end_define

begin_comment
comment|/* Should rnews try the local host? */
end_comment

begin_comment
comment|/* =()<#define @<RNEWSLOCALCONNECT>@_RNEWSLOCALCONNECT>()= */
end_comment

begin_define
define|#
directive|define
name|DO_RNEWSLOCALCONNECT
end_define

begin_comment
comment|/* Disallow posts with more than 50% inclusion (">") lines? */
end_comment

begin_comment
comment|/* (This is only for inews and nnrpd.) */
end_comment

begin_comment
comment|/* =()<#define @<CHECK_INCLUDED_TEXT>@_CHECK_INCLUDED_TEXT>()= */
end_comment

begin_define
define|#
directive|define
name|DO_CHECK_INCLUDED_TEXT
end_define

begin_comment
comment|/* Put hosts in the inews Path header? */
end_comment

begin_comment
comment|/* =()<#define @<INEWS_PATH>@_INEWS_PATH>()= */
end_comment

begin_define
define|#
directive|define
name|DO_INEWS_PATH
end_define

begin_comment
comment|/* Munge the gecos field of password entry? */
end_comment

begin_comment
comment|/* =()<#define @<MUNGE_GECOS>@_MUNGE_GECOS>()= */
end_comment

begin_define
define|#
directive|define
name|DO_MUNGE_GECOS
end_define

begin_comment
comment|/* How many times to try before giving up */
end_comment

begin_comment
comment|/* =()<#define MAX_FORKS	@<MAX_FORKS>@>()= */
end_comment

begin_define
define|#
directive|define
name|MAX_FORKS
value|10
end_define

begin_comment
comment|/* Largest acceptable article size; 0 allows any size */
end_comment

begin_comment
comment|/* =()<#define MAX_ART_SIZE	@<MAX_ART_SIZE>@>()= */
end_comment

begin_define
define|#
directive|define
name|MAX_ART_SIZE
value|1000000
end_define

begin_comment
comment|/* Value of dbzincore(FLAG) call in innd. */
end_comment

begin_comment
comment|/* =()<#define INND_DBZINCORE	@<INND_DBZINCORE>@>()= */
end_comment

begin_define
define|#
directive|define
name|INND_DBZINCORE
value|1
end_define

begin_comment
comment|/* Should sub-processes get a nice(2) value? */
end_comment

begin_comment
comment|/* =()<#define @<INND_NICE_KIDS>@_INND_NICE_KIDS>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_INND_NICE_KIDS
end_define

begin_comment
comment|/* Value for nice(2) call in innd. */
end_comment

begin_comment
comment|/* =()<#define INND_NICE_VALUE	@<INND_NICE_VALUE>@>()= */
end_comment

begin_define
define|#
directive|define
name|INND_NICE_VALUE
value|10
end_define

begin_comment
comment|/* Null-terminated list of unknown commands to not log to syslog. */
end_comment

begin_comment
comment|/* =()<#define INND_QUIET_BADLIST	@<INND_QUIET_BADLIST>@>()= */
end_comment

begin_define
define|#
directive|define
name|INND_QUIET_BADLIST
value|NULL
end_define

begin_comment
comment|/* Null-terminated set of illegal distribution patterns. */
end_comment

begin_comment
comment|/* =()<#define BAD_DISTRIBS	@<BAD_DISTRIBS>@>()= */
end_comment

begin_define
define|#
directive|define
name|BAD_DISTRIBS
value|"*.*",NULL
end_define

begin_comment
comment|/* Check that poster is the person doing the cancel? */
end_comment

begin_comment
comment|/* =()<#define @<VERIFY_CANCELS>@_VERIFY_CANCELS>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_VERIFY_CANCELS
end_define

begin_comment
comment|/* Log "ctlinnd cancel" commands to syslog? */
end_comment

begin_comment
comment|/* =()<#define @<LOG_CANCEL_COMMANDS>@_LOG_CANCEL_COMMANDS>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_LOG_CANCEL_COMMANDS
end_define

begin_comment
comment|/* File unknown "to.*" groups into the "to" newsgroup? */
end_comment

begin_comment
comment|/* =()<#define @<MERGE_TO_GROUPS>@_MERGE_TO_GROUPS>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_MERGE_TO_GROUPS
end_define

begin_comment
comment|/* File articles in unknown newsgroups into junk? */
end_comment

begin_comment
comment|/* =()<#define @<WANT_TRASH>@_WANT_TRASH>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_WANT_TRASH
end_define

begin_comment
comment|/* Record rejected articles in history? */
end_comment

begin_comment
comment|/* =()<#define @<REMEMBER_TRASH>@_REMEMBER_TRASH>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_REMEMBER_TRASH
end_define

begin_comment
comment|/* Check the linecount against the Lines header? */
end_comment

begin_comment
comment|/* =()<#define @<CHECK_LINECOUNT>@_CHECK_LINECOUNT>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_CHECK_LINECOUNT
end_define

begin_comment
comment|/* If checking, the error must be within LINECOUNT_FUZZ lines. */
end_comment

begin_comment
comment|/* =()<#define LINECOUNT_FUZZ	@<LINECOUNT_FUZZ>@>()= */
end_comment

begin_define
define|#
directive|define
name|LINECOUNT_FUZZ
value|5
end_define

begin_comment
comment|/* Have innd throttle itself after this many I/O errors. */
end_comment

begin_comment
comment|/* =()<#define IO_ERROR_COUNT	@<IO_ERROR_COUNT>@>()= */
end_comment

begin_define
define|#
directive|define
name|IO_ERROR_COUNT
value|50
end_define

begin_comment
comment|/* Default value for ctlinnd -t flag. */
end_comment

begin_comment
comment|/* =()<#define CTLINND_TIMEOUT	@<CTLINND_TIMEOUT>@>()= */
end_comment

begin_define
define|#
directive|define
name|CTLINND_TIMEOUT
value|0
end_define

begin_comment
comment|/* Flush logs (and NNRP connections) if we go this long with no I/O. */
end_comment

begin_comment
comment|/* =()<#define DEFAULT_TIMEOUT	@<DEFAULT_TIMEOUT>@>()= */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TIMEOUT
value|300
end_define

begin_comment
comment|/* INND closes channel if inactive this long (seconds). */
end_comment

begin_comment
comment|/* =()<#define PEER_TIMEOUT	@<PEER_TIMEOUT>@>()= */
end_comment

begin_define
define|#
directive|define
name|PEER_TIMEOUT
value|(1 * 60 * 60)
end_define

begin_comment
comment|/* NNRP exits if inactive this long (seconds). */
end_comment

begin_comment
comment|/* =()<#define CLIENT_TIMEOUT	@<CLIENT_TIMEOUT>@>()= */
end_comment

begin_define
define|#
directive|define
name|CLIENT_TIMEOUT
value|(2 * 60 * 60)
end_define

begin_comment
comment|/* Allow nnrpd readers when paused or throttled? */
end_comment

begin_comment
comment|/* =()<#define @<ALLOW_READERS>@_ALLOW_READERS>()= */
end_comment

begin_define
define|#
directive|define
name|DO_ALLOW_READERS
end_define

begin_comment
comment|/* Refuse NNTP connections if load is higher then this; -1 disables. */
end_comment

begin_comment
comment|/* =()<#define NNRP_LOADLIMIT	@<NNRP_LOADLIMIT>@>()= */
end_comment

begin_define
define|#
directive|define
name|NNRP_LOADLIMIT
value|16
end_define

begin_comment
comment|/* Don't readdir() spool dir if same group within this many seconds. */
end_comment

begin_comment
comment|/* =()<#define NNRP_RESCAN_DELAY	@<NNRP_RESCAN_DELAY>@>()= */
end_comment

begin_define
define|#
directive|define
name|NNRP_RESCAN_DELAY
value|60
end_define

begin_comment
comment|/* Do gethostbyaddr on client addresses in nnrp? */
end_comment

begin_comment
comment|/* =()<#define @<NNRP_GETHOSTBYADDR>@_NNRP_GETHOSTBYADDR>()= */
end_comment

begin_define
define|#
directive|define
name|DO_NNRP_GETHOSTBYADDR
end_define

begin_comment
comment|/* Should nnrpd do a dbzincore? */
end_comment

begin_comment
comment|/* =()<#define NNRP_DBZINCORE_DELAY	@<NNRP_DBZINCORE_DELAY>@>()= */
end_comment

begin_define
define|#
directive|define
name|NNRP_DBZINCORE_DELAY
value|40
end_define

begin_comment
comment|/*  Strip Sender from posts that did authenticate? */
end_comment

begin_comment
comment|/* =()<#define @<NNRP_AUTH_SENDER>@_NNRP_AUTH_SENDER>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_NNRP_AUTH_SENDER
end_define

begin_comment
comment|/* How many read/write failures until channel is put to sleep or closed? */
end_comment

begin_comment
comment|/* =()<#define BAD_IO_COUNT	@<BAD_IO_COUNT>@>()= */
end_comment

begin_define
define|#
directive|define
name|BAD_IO_COUNT
value|5
end_define

begin_comment
comment|/* Multiplier for sleep in EWOULDBLOCK writes (seconds). */
end_comment

begin_comment
comment|/* =()<#define BLOCK_BACKOFF	@<BLOCK_BACKOFF>@>()= */
end_comment

begin_define
define|#
directive|define
name|BLOCK_BACKOFF
value|(2 * 60)
end_define

begin_comment
comment|/* How many article-writes between active and history updates? */
end_comment

begin_comment
comment|/* =()<#define ICD_SYNC_COUNT	@<ICD_SYNC_COUNT>@>()= */
end_comment

begin_define
define|#
directive|define
name|ICD_SYNC_COUNT
value|10
end_define

begin_comment
comment|/* Tell resolver _res.options to be fast? */
end_comment

begin_comment
comment|/* =()<#define @<FAST_RESOLV>@_FAST_RESOLV>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_FAST_RESOLV
end_define

begin_comment
comment|/* Drop articles that were posted this many days ago. */
end_comment

begin_comment
comment|/* =()<#define DEFAULT_CUTOFF	@<DEFAULT_CUTOFF>@>()= */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CUTOFF
value|14
end_define

begin_comment
comment|/* Maximum number of incoming NNTP connections. */
end_comment

begin_comment
comment|/* =()<#define DEFAULT_CONNECTIONS	@<DEFAULT_CONNECTIONS>@>()= */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CONNECTIONS
value|50
end_define

begin_comment
comment|/* Wait this many seconds before channel restarts. */
end_comment

begin_comment
comment|/* =()<#define CHANNEL_RETRY_TIME	@<CHANNEL_RETRY_TIME>@>()= */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_RETRY_TIME
value|(5 * 60)
end_define

begin_comment
comment|/* Wait this many seconds before seeing if pause is ended. */
end_comment

begin_comment
comment|/* =()<#define PAUSE_RETRY_TIME	@<PAUSE_RETRY_TIME>@>()= */
end_comment

begin_define
define|#
directive|define
name|PAUSE_RETRY_TIME
value|(5 * 60)
end_define

begin_comment
comment|/* Wait this many seconds before seeing if pause is ended. */
end_comment

begin_comment
comment|/* =()<#define CHANNEL_INACTIVE_TIME	@<CHANNEL_INACTIVE_TIME>@>()= */
end_comment

begin_define
define|#
directive|define
name|CHANNEL_INACTIVE_TIME
value|(10 * 60)
end_define

begin_comment
comment|/* Put nntplink info (filename) into the log? */
end_comment

begin_comment
comment|/* =()<#define @<NNTPLINK_LOG>@_NNTPLINK_LOG>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_NNTPLINK_LOG
end_define

begin_comment
comment|/* Log by host IP address, rather than from Path line? */
end_comment

begin_comment
comment|/* =()<#define @<IPADDR_LOG>@_IPADDR_LOG>()= */
end_comment

begin_define
define|#
directive|define
name|DONT_IPADDR_LOG
end_define

begin_comment
comment|/* Log NNTP activity after this many articles. */
end_comment

begin_comment
comment|/* =()<#define NNTP_ACTIVITY_SYNC	@<NNTP_ACTIVITY_SYNC>@>()= */
end_comment

begin_define
define|#
directive|define
name|NNTP_ACTIVITY_SYNC
value|200
end_define

begin_comment
comment|/* Free buffers bigger than this when we're done with them. */
end_comment

begin_comment
comment|/* =()<#define BIG_BUFFER	@<BIG_BUFFER>@>()= */
end_comment

begin_define
define|#
directive|define
name|BIG_BUFFER
value|(2 * START_BUFF_SIZE)
end_define

begin_comment
comment|/* A general small buffer. */
end_comment

begin_comment
comment|/* =()<#define SMBUF	@<SMBUF>@>()= */
end_comment

begin_define
define|#
directive|define
name|SMBUF
value|256
end_define

begin_comment
comment|/* Buffer for a single article name. */
end_comment

begin_comment
comment|/* =()<#define MAXARTFNAME	@<MAXARTFNAME>@>()= */
end_comment

begin_define
define|#
directive|define
name|MAXARTFNAME
value|10
end_define

begin_comment
comment|/* Buffer for a single pathname in the spool directory. */
end_comment

begin_comment
comment|/* =()<#define SPOOLNAMEBUFF	@<SPOOLNAMEBUFF>@>()= */
end_comment

begin_define
define|#
directive|define
name|SPOOLNAMEBUFF
value|512
end_define

begin_comment
comment|/* Maximum size of a single header. */
end_comment

begin_comment
comment|/* =()<#define MAXHEADERSIZE	@<MAXHEADERSIZE>@>()= */
end_comment

begin_define
define|#
directive|define
name|MAXHEADERSIZE
value|1024
end_define

begin_comment
comment|/* Byte limit on locally-posted articles; 0 to disable the check. */
end_comment

begin_comment
comment|/* =()<#define LOCAL_MAX_ARTSIZE	@<LOCAL_MAX_ARTSIZE>@>()= */
end_comment

begin_define
define|#
directive|define
name|LOCAL_MAX_ARTSIZE
value|0
end_define

begin_comment
comment|/* Function that returns no value, and a pointer to it. */
end_comment

begin_comment
comment|/* =()<#define FUNCTYPE	@<FUNCTYPE>@>()= */
end_comment

begin_define
define|#
directive|define
name|FUNCTYPE
value|void
end_define

begin_typedef
typedef|typedef
name|FUNCTYPE
function_decl|(
modifier|*
name|FUNCPTR
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* While reading input, if we have less than LOW_WATER bytes free, we      * use the current buffersize as input to GROW_AMOUNT to determine how      * much to realloc.  (Doubling seems to be the best thing right now.)      * Growth must be at least NNTP_STRLEN bytes! */
end_comment

begin_define
define|#
directive|define
name|START_BUFF_SIZE
value|(4 * 1024)
end_define

begin_define
define|#
directive|define
name|LOW_WATER
value|(1 * 1024)
end_define

begin_define
define|#
directive|define
name|GROW_AMOUNT
parameter_list|(
name|x
parameter_list|)
value|((x))
end_define

begin_comment
comment|/* Some debuggers might need this set to an empty string. */
end_comment

begin_define
define|#
directive|define
name|STATIC
value|static
end_define

begin_comment
comment|/* How to store article numbers; note that INN is not int/long clean. */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ARTNUM
typedef|;
end_typedef

begin_comment
comment|/* A general convenience; you shouldn't have to change this. */
end_comment

begin_typedef
typedef|typedef
name|int
name|BOOL
typedef|;
end_typedef

begin_comment
comment|/* General values that you should not have to change. */
end_comment

begin_define
define|#
directive|define
name|MEMCPY_THRESHOLD
value|12
end_define

begin_define
define|#
directive|define
name|MAX_BUILTIN_ARGV
value|20
end_define

begin_define
define|#
directive|define
name|NNTP_PORT
value|119
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|MAXLISTEN
value|5
end_define

begin_define
define|#
directive|define
name|STDIN
value|0
end_define

begin_define
define|#
directive|define
name|STDOUT
value|1
end_define

begin_define
define|#
directive|define
name|PIPE_READ
value|0
end_define

begin_define
define|#
directive|define
name|PIPE_WRITE
value|1
end_define

begin_define
define|#
directive|define
name|DATE_FUZZ
value|(24L * 60L * 60L)
end_define

begin_define
define|#
directive|define
name|COMMENT_CHAR
value|'#'
end_define

begin_define
define|#
directive|define
name|ART_ACCEPT
value|'+'
end_define

begin_define
define|#
directive|define
name|ART_CANC
value|'c'
end_define

begin_define
define|#
directive|define
name|ART_JUNK
value|'j'
end_define

begin_define
define|#
directive|define
name|ART_REJECT
value|'-'
end_define

begin_define
define|#
directive|define
name|EXP_CONTROL
value|'!'
end_define

begin_define
define|#
directive|define
name|FEED_MAXFLAGS
value|20
end_define

begin_define
define|#
directive|define
name|FEED_BYTESIZE
value|'b'
end_define

begin_define
define|#
directive|define
name|FEED_FULLNAME
value|'f'
end_define

begin_define
define|#
directive|define
name|FEED_HDR_DISTRIB
value|'D'
end_define

begin_define
define|#
directive|define
name|FEED_HDR_NEWSGROUP
value|'N'
end_define

begin_define
define|#
directive|define
name|FEED_MESSAGEID
value|'m'
end_define

begin_define
define|#
directive|define
name|FEED_FNLNAMES
value|'*'
end_define

begin_define
define|#
directive|define
name|FEED_HEADERS
value|'H'
end_define

begin_define
define|#
directive|define
name|FEED_NAME
value|'n'
end_define

begin_define
define|#
directive|define
name|FEED_NEWSGROUP
value|'g'
end_define

begin_define
define|#
directive|define
name|FEED_OVERVIEW
value|'O'
end_define

begin_define
define|#
directive|define
name|FEED_REPLIC
value|'R'
end_define

begin_define
define|#
directive|define
name|FEED_SITE
value|'s'
end_define

begin_define
define|#
directive|define
name|FEED_TIMERECEIVED
value|'t'
end_define

begin_define
define|#
directive|define
name|HIS_BADCHAR
value|'_'
end_define

begin_define
define|#
directive|define
name|HIS_FIELDSEP
value|'\t'
end_define

begin_define
define|#
directive|define
name|HIS_NOEXP
value|"-"
end_define

begin_define
define|#
directive|define
name|HIS_SUBFIELDSEP
value|'~'
end_define

begin_define
define|#
directive|define
name|NF_FIELD_SEP
value|':'
end_define

begin_define
define|#
directive|define
name|NF_FLAG_ALIAS
value|'='
end_define

begin_define
define|#
directive|define
name|NF_FLAG_EXCLUDED
value|'j'
end_define

begin_define
define|#
directive|define
name|NF_FLAG_MODERATED
value|'m'
end_define

begin_define
define|#
directive|define
name|NF_FLAG_OK
value|'y'
end_define

begin_define
define|#
directive|define
name|NF_FLAG_NOLOCAL
value|'n'
end_define

begin_define
define|#
directive|define
name|NF_FLAG_IGNORE
value|'x'
end_define

begin_define
define|#
directive|define
name|NF_SUBFIELD_SEP
value|'/'
end_define

begin_define
define|#
directive|define
name|NG_SEPARATOR
value|","
end_define

begin_define
define|#
directive|define
name|NG_ISSEP
parameter_list|(
name|c
parameter_list|)
value|((c) == ',')
end_define

begin_define
define|#
directive|define
name|RNEWS_MAGIC1
value|'#'
end_define

begin_define
define|#
directive|define
name|RNEWS_MAGIC2
value|'!'
end_define

begin_define
define|#
directive|define
name|SIG_MAXLINES
value|4
end_define

begin_define
define|#
directive|define
name|SIG_SEPARATOR
value|"-- \n"
end_define

begin_define
define|#
directive|define
name|SUB_DEFAULT
value|FALSE
end_define

begin_define
define|#
directive|define
name|SUB_NEGATE
value|'!'
end_define

begin_define
define|#
directive|define
name|LOOPBACK_HOST
value|"127.0.0.1"
end_define

end_unit

