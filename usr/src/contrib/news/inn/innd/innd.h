begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.41 $ ** **  Many of the data types used here have abbreviations, such as CT **  for CHANNELTYPE.  Here are a list of the conventions and meanings: **	ART	A news article **	CHAN	An I/O channel **	CS	Channel state **	CT	Channel type **	FNL	Funnel, into which other feeds pour **	FT	Feed type -- how a site gets told about new articles **	ICD	In-core data (primarily the active and sys files) **	LC	Local NNTP connection-receiving channel **	CC	Control channel (used by ctlinnd) **	NC	NNTP client channel **	NG	Newsgroup **	NGH	Newgroup hashtable **	PROC	A process (used to feed a site) **	PS	Process state **	RC	Remote NNTP connection-receiving channel **	RCHAN	A channel in "read" state **	SITE	Something that gets told when we get an article **	WCHAN	A channel in "write" state */
end_comment

begin_include
include|#
directive|include
file|"configdata.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DO_NEED_TIME
argument_list|)
end_if

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DO_NEED_TIME) */
end_comment

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|"nntp.h"
end_include

begin_include
include|#
directive|include
file|"paths.h"
end_include

begin_include
include|#
directive|include
file|"logging.h"
end_include

begin_include
include|#
directive|include
file|"libinn.h"
end_include

begin_include
include|#
directive|include
file|"clibrary.h"
end_include

begin_include
include|#
directive|include
file|"macros.h"
end_include

begin_define
define|#
directive|define
name|NOSITE
value|-1
end_define

begin_comment
comment|/* **  Some convenient shorthands. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|in_addr
name|INADDR
typedef|;
end_typedef

begin_comment
comment|/* **  Server's operating mode. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_OPERATINGMODE
block|{
name|OMrunning
block|,
name|OMpaused
block|,
name|OMthrottled
block|}
name|OPERATINGMODE
typedef|;
end_typedef

begin_comment
comment|/* **  An I/O buffer, including a size, an amount used, and a count of how **  much space is left if reading or how much still needs to be written. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_BUFFER
block|{
name|int
name|Size
decl_stmt|;
name|int
name|Used
decl_stmt|;
name|int
name|Left
decl_stmt|;
name|char
modifier|*
name|Data
decl_stmt|;
block|}
name|BUFFER
typedef|;
end_typedef

begin_comment
comment|/* **  What program to handoff a connection to. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_HANDOFF
block|{
name|HOnnrpd
block|,
name|HOnnrqd
block|,
name|HOnntpd
block|}
name|HANDOFF
typedef|;
end_typedef

begin_comment
comment|/* **  Set of channel types. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_CHANNELTYPE
block|{
name|CTany
block|,
name|CTfree
block|,
name|CTremconn
block|,
name|CTnntp
block|,
name|CTlocalconn
block|,
name|CTcontrol
block|,
name|CTfile
block|,
name|CTexploder
block|,
name|CTprocess
block|}
name|CHANNELTYPE
typedef|;
end_typedef

begin_comment
comment|/* **  The state a channel is in.  Interpretation of this depends on the **  channel's type.  Used mostly by CTnntp channels. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_CHANNELSTATE
block|{
name|CSerror
block|,
name|CSwaiting
block|,
name|CSgetcmd
block|,
name|CSgetauth
block|,
name|CSwritegoodbye
block|,
name|CSwriting
block|,
name|CSpaused
block|,
name|CSgetarticle
block|,
name|CSeatarticle
block|,
name|CSgetrep
block|}
name|CHANNELSTATE
typedef|;
end_typedef

begin_comment
comment|/* **  I/O channel, the heart of the program.  A channel has input and output **  buffers, and functions to call when there is input to be read, or when **  all the output was been written. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_CHANNEL
block|{
name|CHANNELTYPE
name|Type
decl_stmt|;
name|CHANNELSTATE
name|State
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|int
name|Reported
decl_stmt|;
name|long
name|Received
decl_stmt|;
name|long
name|Refused
decl_stmt|;
name|long
name|Rejected
decl_stmt|;
name|int
name|BadWrites
decl_stmt|;
name|int
name|BadReads
decl_stmt|;
name|int
name|BlockedWrites
decl_stmt|;
name|int
name|BadCommands
decl_stmt|;
name|time_t
name|LastActive
decl_stmt|;
name|time_t
name|NextLog
decl_stmt|;
name|INADDR
name|Address
decl_stmt|;
name|FUNCPTR
name|Reader
decl_stmt|;
name|FUNCPTR
name|WriteDone
decl_stmt|;
name|time_t
name|Waketime
decl_stmt|;
name|time_t
name|Started
decl_stmt|;
name|FUNCPTR
name|Waker
decl_stmt|;
name|POINTER
name|Argument
decl_stmt|;
name|POINTER
name|Event
decl_stmt|;
name|BUFFER
name|In
decl_stmt|;
name|BUFFER
name|Out
decl_stmt|;
name|BOOL
name|Tracing
decl_stmt|;
block|}
name|CHANNEL
typedef|;
end_typedef

begin_comment
comment|/* **  A newsgroup has a name in different formats, and a high-water count, **  also kept in different formats.  It also has a list of sites that **  get this group. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_NEWSGROUP
block|{
name|long
name|Start
decl_stmt|;
comment|/* Offset into the active file	*/
name|char
modifier|*
name|Name
decl_stmt|;
name|char
modifier|*
name|Dir
decl_stmt|;
comment|/* The name, as a directory	*/
name|int
name|NameLength
decl_stmt|;
name|ARTNUM
name|Last
decl_stmt|;
name|ARTNUM
name|Filenum
decl_stmt|;
comment|/* File name to use		*/
name|int
name|Lastwidth
decl_stmt|;
name|int
name|PostCount
decl_stmt|;
comment|/* Have we already put it here?	*/
name|char
modifier|*
name|LastString
decl_stmt|;
name|char
modifier|*
name|Rest
decl_stmt|;
name|int
name|nSites
decl_stmt|;
name|int
modifier|*
name|Sites
decl_stmt|;
name|struct
name|_NEWSGROUP
modifier|*
name|Alias
decl_stmt|;
block|}
name|NEWSGROUP
typedef|;
end_typedef

begin_comment
comment|/* **  How a site is fed. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_FEEDTYPE
block|{
name|FTerror
block|,
name|FTfile
block|,
name|FTchannel
block|,
name|FTexploder
block|,
name|FTfunnel
block|,
name|FTlogonly
block|,
name|FTprogram
block|}
name|FEEDTYPE
typedef|;
end_typedef

begin_comment
comment|/* **  A site may reject something in its subscription list if it has **  too many hops, or a bad distribution. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SITE
block|{
name|char
modifier|*
name|Name
decl_stmt|;
name|char
modifier|*
name|Entry
decl_stmt|;
name|int
name|NameLength
decl_stmt|;
name|char
modifier|*
modifier|*
name|Exclusions
decl_stmt|;
name|char
modifier|*
modifier|*
name|Distributions
decl_stmt|;
name|char
modifier|*
modifier|*
name|Patterns
decl_stmt|;
name|BOOL
name|Sendit
decl_stmt|;
name|BOOL
name|Seenit
decl_stmt|;
name|BOOL
name|DistRequired
decl_stmt|;
name|BOOL
name|IgnorePath
decl_stmt|;
name|int
name|Hops
decl_stmt|;
name|int
name|Groupcount
decl_stmt|;
name|FEEDTYPE
name|Type
decl_stmt|;
name|NEWSGROUP
modifier|*
name|ng
decl_stmt|;
name|BOOL
name|Spooling
decl_stmt|;
name|char
modifier|*
name|SpoolName
decl_stmt|;
name|BOOL
name|Working
decl_stmt|;
name|long
name|StartWriting
decl_stmt|;
name|long
name|StopWriting
decl_stmt|;
name|long
name|StartSpooling
decl_stmt|;
name|char
modifier|*
name|Param
decl_stmt|;
name|char
name|FileFlags
index|[
name|FEED_MAXFLAGS
operator|+
literal|1
index|]
decl_stmt|;
name|long
name|MaxSize
decl_stmt|;
name|CHANNEL
modifier|*
name|Channel
decl_stmt|;
name|BOOL
name|IsMaster
decl_stmt|;
name|int
name|Master
decl_stmt|;
name|int
name|Funnel
decl_stmt|;
name|BOOL
name|FNLwantsnames
decl_stmt|;
name|BUFFER
name|FNLnames
decl_stmt|;
name|int
name|Process
decl_stmt|;
name|PID_T
name|pid
decl_stmt|;
name|int
name|Flushpoint
decl_stmt|;
name|BUFFER
name|Buffer
decl_stmt|;
name|BOOL
name|Buffered
decl_stmt|;
name|struct
name|_SITE
modifier|*
name|Next
decl_stmt|;
name|struct
name|_SITE
modifier|*
name|Prev
decl_stmt|;
block|}
name|SITE
typedef|;
end_typedef

begin_comment
comment|/* **  A process is something we start up to send articles. */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|_PROCSTATE
block|{
name|PSfree
block|,
name|PSrunning
block|,
name|PSdead
block|}
name|PROCSTATE
typedef|;
end_typedef

begin_comment
comment|/* **  We track our children and collect them synchronously. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_PROCESS
block|{
name|PROCSTATE
name|State
decl_stmt|;
name|PID_T
name|Pid
decl_stmt|;
name|int
name|Status
decl_stmt|;
name|time_t
name|Started
decl_stmt|;
name|time_t
name|Collected
decl_stmt|;
name|int
name|Site
decl_stmt|;
block|}
name|PROCESS
typedef|;
end_typedef

begin_comment
comment|/* **  Miscellaneous data we want to keep on an article.  All the fields **  are not always valid. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_ARTDATA
block|{
name|STRING
name|Poster
decl_stmt|;
name|STRING
name|Replyto
decl_stmt|;
name|char
modifier|*
name|Body
decl_stmt|;
name|time_t
name|Posted
decl_stmt|;
name|time_t
name|Arrived
decl_stmt|;
name|time_t
name|Expires
decl_stmt|;
name|int
name|Groupcount
decl_stmt|;
name|int
name|LinesValue
decl_stmt|;
name|char
name|Lines
index|[
name|SMBUF
index|]
decl_stmt|;
name|long
name|SizeValue
decl_stmt|;
name|char
name|Size
index|[
name|SMBUF
index|]
decl_stmt|;
name|int
name|SizeLength
decl_stmt|;
name|char
name|Name
index|[
name|SPOOLNAMEBUFF
index|]
decl_stmt|;
name|int
name|NameLength
decl_stmt|;
name|char
name|TimeReceived
index|[
literal|33
index|]
decl_stmt|;
name|int
name|TimeReceivedLength
decl_stmt|;
name|STRING
name|MessageID
decl_stmt|;
name|int
name|MessageIDLength
decl_stmt|;
name|STRING
name|Newsgroups
decl_stmt|;
name|int
name|NewsgroupsLength
decl_stmt|;
name|STRING
name|Distribution
decl_stmt|;
name|int
name|DistributionLength
decl_stmt|;
name|STRING
name|Feedsite
decl_stmt|;
name|int
name|FeedsiteLength
decl_stmt|;
name|STRING
name|Replic
decl_stmt|;
name|int
name|ReplicLength
decl_stmt|;
name|BUFFER
modifier|*
name|Headers
decl_stmt|;
name|BUFFER
modifier|*
name|Overview
decl_stmt|;
block|}
name|ARTDATA
typedef|;
end_typedef

begin_escape
end_escape

begin_comment
comment|/* **  In-line macros for efficiency. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|lint
argument_list|)
operator|||
name|defined
argument_list|(
name|__CENTERLINE__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|KeepLintQuiet
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|JUSTONCE
value|KeepLintQuiet
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|JUSTONCE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(lint) || defined(__CENTERLINE__) */
end_comment

begin_comment
comment|/* **  Set or append data to a channel's output buffer. */
end_comment

begin_define
define|#
directive|define
name|WCHANset
parameter_list|(
name|cp
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|BUFFset(&(cp)->Out, (p), (l))
end_define

begin_define
define|#
directive|define
name|WCHANappend
parameter_list|(
name|cp
parameter_list|,
name|p
parameter_list|,
name|l
parameter_list|)
value|BUFFappend(&(cp)->Out, (p), (l))
end_define

begin_comment
comment|/* **  Append data to a buffer. */
end_comment

begin_define
define|#
directive|define
name|BUFFappend
parameter_list|(
name|bp_parm
parameter_list|,
name|p_parm
parameter_list|,
name|l_parm
parameter_list|)
define|\
value|do { \ 	register int	l_; \ 	register BUFFER	*bp_; \ 	int		i_; \     \ 	if ((l_ = l_parm) != 0) { \ 	    bp_ = bp_parm; \
comment|/* Note end of buffer, grow it if we need more room. */
value|\ 	    i_ = bp_->Used + bp_->Left; \ 	    if (i_ + l_> bp_->Size) { \
comment|/* Round size up to next 1K. */
value|\ 		bp_->Size += (l_ + 0x3FF)& ~0x3FF; \ 		RENEW(bp_->Data, char, bp_->Size); \ 	    } \ 	    bp_->Left += l_; \ 	    if (l_> MEMCPY_THRESHOLD) \ 		(void)memcpy((POINTER)&bp_->Data[i_], (POINTER)p_parm, (SIZE_T)l_); \ 	    else { \ 		register STRING	p_; \ 		register char	*dest_; \     \ 		for (p_ = p_parm, dest_ =&bp_->Data[i_], l_++; --l_> 0; ) \ 		    *dest_++ = *p_++; \ 	    } \ 	} \     } while (JUSTONCE)
end_define

begin_comment
comment|/* **  Mark that an I/O error occurred, and block if we got too many. */
end_comment

begin_define
define|#
directive|define
name|IOError
parameter_list|(
name|WHEN
parameter_list|)
define|\
value|if (--ErrorCount<= 0 || errno == ENOSPC) ThrottleIOError(WHEN); else
end_define

begin_escape
end_escape

begin_comment
comment|/* **  Global data. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEFINE_DATA
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTERN
end_define

begin_comment
comment|/* NULL */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTERN
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(DEFINE_DATA) */
end_comment

begin_decl_stmt
name|EXTERN
name|BOOL
name|AlwaysCrosspost
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|AmRoot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|BufferedLogs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BOOL
name|AmSlave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BOOL
name|AnyIncoming
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|Debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BOOL
name|ICDneedsetup
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BOOL
name|NeedHeaders
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BOOL
name|NeedOverview
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BOOL
name|NNRPFollows
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|NNRPTracing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|BOOL
name|Tracing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BUFFER
name|Path
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|BUFFER
name|Xref
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|ModeReason
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NNTP reject message		*/
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|NNRPReason
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NNRP reject message		*/
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|Reservation
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reserved lock message	*/
end_comment

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|RejectReason
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* NNTP reject message		*/
end_comment

begin_decl_stmt
specifier|extern
name|char
name|SPOOL
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|char
modifier|*
name|Version
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|FILE
modifier|*
name|Errlog
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|FILE
modifier|*
name|Log
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|LogName
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|INADDR
name|MyAddress
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ErrorCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|ICDactivedirty
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|MaxIncoming
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|MaxOutgoing
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|nGroups
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|nSites
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|PROCneedscan
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|SPOOLlen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|int
name|Xrefbase
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|LargestArticle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|NEWSGROUP
modifier|*
modifier|*
name|GroupPointers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|NEWSGROUP
modifier|*
name|Groups
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|OPERATINGMODE
name|Mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|SIGVAR
name|GotTerminate
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|SITE
modifier|*
name|Sites
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|SITE
name|ME
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|struct
name|timeval
name|TimeOut
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|EXTERN
name|TIMEINFO
name|Now
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Reasonably accurate time	*/
end_comment

begin_decl_stmt
specifier|extern
name|time_t
name|Cutoff
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  Function declarations. */
end_comment

begin_function_decl
specifier|extern
name|BOOL
name|FormatLong
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|MakeSpoolDirectory
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|NeedShell
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|CommaSplit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|MaxLength
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Spawn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|NORETURN
name|CleanupAndExit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|FileGlue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|JustCleanup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ThrottleIOError
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ReopenLog
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xchown
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|ARTidok
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|ARTreadschema
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ARTreadarticle
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ARTreadheader
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|STRING
name|ARTpost
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ARTcancel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ARTclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ARTsetup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|BUFFset
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|CHANsleeping
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CHANNEL
modifier|*
name|CHANcreate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CHANNEL
modifier|*
name|CHANiter
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CHANNEL
modifier|*
name|CHANfromdescriptor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|CHANname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|CHANreadtext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CHANclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CHANreadloop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CHANsetup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CHANtracing
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RCHANadd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RCHANremove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SCHANadd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SCHANremove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SCHANwakeup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|WCHANflush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|WCHANadd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|WCHANfappend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|WCHANremove
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|WCHANsetfrombuffer
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CCcopyargv
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|STRING
name|CCblock
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|STRING
name|CCcancel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|STRING
name|CCcheckfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|HIShavearticle
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|HISwrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|HISfilesfor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HISclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HISsetup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HISsync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|ICDnewgroup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ICDreadactive
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|ICDchangegroup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ICDclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ICDrenumberactive
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|ICDrmgroup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ICDsetup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ICDwrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ICDwriteactive
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CCclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CCsetup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LCclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|LCsetup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|NGsplit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|NEWSGROUP
modifier|*
name|NGfind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CHANNEL
modifier|*
name|NCcreate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|NGparsefile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|NGrenumber
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|NCclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|NCsetup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|PROCwatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|PROCunwatch
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* extern void		PROCclose(); */
end_comment

begin_function_decl
specifier|extern
name|void
name|PROCscan
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|PROCsetup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|RCnolimit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|RCauthorized
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|RCcanpost
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|RChostname
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|RCismaster
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RCclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RChandoff
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RCreadlist
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|RCsetup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|SITEfunnelpatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|SITEsetup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|BOOL
name|SITEwantsgroup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
modifier|*
name|SITEreadfile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SITE
modifier|*
name|SITEfind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|SITE
modifier|*
name|SITEfindnext
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|STRING
name|SITEparseone
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SITEchanclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SITEdrop
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SITEflush
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SITEflushall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SITEforward
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SITEfree
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SITElinkall
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SITEparsefile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SITEprocdied
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SITEsend
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|SITEwrite
parameter_list|()
function_decl|;
end_function_decl

end_unit

