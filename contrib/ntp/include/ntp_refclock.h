begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_refclock.h - definitions for reference clock support  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_REFCLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_REFCLOCK_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_MODEM_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/modem.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|"ntp_tty.h"
end_include

begin_include
include|#
directive|include
file|"recvbuff.h"
end_include

begin_define
define|#
directive|define
name|SAMPLE
parameter_list|(
name|x
parameter_list|)
value|pp->coderecv = (pp->coderecv + 1) % MAXSTAGE; \ 			pp->filter[pp->coderecv] = (x); \ 			if (pp->coderecv == pp->codeproc) \ 				pp->codeproc = (pp->codeproc + 1) % MAXSTAGE;
end_define

begin_comment
comment|/*  * Macros to determine the clock type and unit numbers from a  * 127.127.t.u address  */
end_comment

begin_define
define|#
directive|define
name|REFCLOCKTYPE
parameter_list|(
name|srcadr
parameter_list|)
value|((SRCADR(srcadr)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|REFCLOCKUNIT
parameter_list|(
name|srcadr
parameter_list|)
value|(SRCADR(srcadr)& 0xff)
end_define

begin_comment
comment|/*  * List of reference clock names and descriptions. These must agree with  * lib/clocktypes.c and ntpd/refclock_conf.c.  */
end_comment

begin_struct
struct|struct
name|clktype
block|{
name|int
name|code
decl_stmt|;
comment|/* driver "major" number */
specifier|const
name|char
modifier|*
name|clocktype
decl_stmt|;
comment|/* long description */
specifier|const
name|char
modifier|*
name|abbrev
decl_stmt|;
comment|/* short description */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|clktype
name|clktypes
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Configuration flag values  */
end_comment

begin_define
define|#
directive|define
name|CLK_HAVETIME1
value|0x1
end_define

begin_define
define|#
directive|define
name|CLK_HAVETIME2
value|0x2
end_define

begin_define
define|#
directive|define
name|CLK_HAVEVAL1
value|0x4
end_define

begin_define
define|#
directive|define
name|CLK_HAVEVAL2
value|0x8
end_define

begin_define
define|#
directive|define
name|CLK_FLAG1
value|0x1
end_define

begin_define
define|#
directive|define
name|CLK_FLAG2
value|0x2
end_define

begin_define
define|#
directive|define
name|CLK_FLAG3
value|0x4
end_define

begin_define
define|#
directive|define
name|CLK_FLAG4
value|0x8
end_define

begin_define
define|#
directive|define
name|CLK_HAVEFLAG1
value|0x10
end_define

begin_define
define|#
directive|define
name|CLK_HAVEFLAG2
value|0x20
end_define

begin_define
define|#
directive|define
name|CLK_HAVEFLAG3
value|0x40
end_define

begin_define
define|#
directive|define
name|CLK_HAVEFLAG4
value|0x80
end_define

begin_comment
comment|/*  * Constant for disabling event reporting in  * refclock_receive. ORed in leap  * parameter  */
end_comment

begin_define
define|#
directive|define
name|REFCLOCK_OWN_STATES
value|0x80
end_define

begin_comment
comment|/*  * Structure for returning clock status  */
end_comment

begin_struct
struct|struct
name|refclockstat
block|{
name|u_char
name|type
decl_stmt|;
comment|/* clock type */
name|u_char
name|flags
decl_stmt|;
comment|/* clock flags */
name|u_char
name|haveflags
decl_stmt|;
comment|/* bit array of valid flags */
name|u_short
name|lencode
decl_stmt|;
comment|/* length of last timecode */
specifier|const
name|char
modifier|*
name|p_lastcode
decl_stmt|;
comment|/* last timecode received */
name|u_int32
name|polls
decl_stmt|;
comment|/* transmit polls */
name|u_int32
name|noresponse
decl_stmt|;
comment|/* no response to poll */
name|u_int32
name|badformat
decl_stmt|;
comment|/* bad format timecode received */
name|u_int32
name|baddata
decl_stmt|;
comment|/* invalid data timecode received */
name|u_int32
name|timereset
decl_stmt|;
comment|/* driver resets */
specifier|const
name|char
modifier|*
name|clockdesc
decl_stmt|;
comment|/* ASCII description */
name|double
name|fudgetime1
decl_stmt|;
comment|/* configure fudge time1 */
name|double
name|fudgetime2
decl_stmt|;
comment|/* configure fudge time2 */
name|int32
name|fudgeval1
decl_stmt|;
comment|/* configure fudge value1 */
name|u_int32
name|fudgeval2
decl_stmt|;
comment|/* configure fudge value2 */
name|u_char
name|currentstatus
decl_stmt|;
comment|/* clock status */
name|u_char
name|lastevent
decl_stmt|;
comment|/* last exception event */
name|u_char
name|leap
decl_stmt|;
comment|/* leap bits */
name|struct
name|ctl_var
modifier|*
name|kv_list
decl_stmt|;
comment|/* additional variables */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Reference clock I/O structure.  Used to provide an interface between  * the reference clock drivers and the I/O module.  */
end_comment

begin_struct
struct|struct
name|refclockio
block|{
name|struct
name|refclockio
modifier|*
name|next
decl_stmt|;
comment|/* link to next structure */
name|void
function_decl|(
modifier|*
name|clock_recv
function_decl|)
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|)
function_decl|;
comment|/* completion routine */
name|int
function_decl|(
modifier|*
name|io_input
function_decl|)
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|)
function_decl|;
comment|/* input routine - 				to avoid excessive buffer use 				due to small bursts 				of refclock input data */
name|struct
name|peer
modifier|*
name|srcclock
decl_stmt|;
comment|/* refclock peer */
name|int
name|datalen
decl_stmt|;
comment|/* length of data */
name|int
name|fd
decl_stmt|;
comment|/* file descriptor */
name|u_long
name|recvcount
decl_stmt|;
comment|/* count of receive completions */
name|int
name|active
decl_stmt|;
comment|/* nonzero when in use */
ifdef|#
directive|ifdef
name|HAVE_IO_COMPLETION_PORT
name|void
modifier|*
name|device_context
decl_stmt|;
comment|/* device-related data for i/o subsystem */
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for returning debugging info  */
end_comment

begin_define
define|#
directive|define
name|NCLKBUGVALUES
value|16
end_define

begin_define
define|#
directive|define
name|NCLKBUGTIMES
value|32
end_define

begin_struct
struct|struct
name|refclockbug
block|{
name|u_char
name|nvalues
decl_stmt|;
comment|/* values following */
name|u_char
name|ntimes
decl_stmt|;
comment|/* times following */
name|u_short
name|svalues
decl_stmt|;
comment|/* values format sign array */
name|u_int32
name|stimes
decl_stmt|;
comment|/* times format sign array */
name|u_int32
name|values
index|[
name|NCLKBUGVALUES
index|]
decl_stmt|;
comment|/* real values */
name|l_fp
name|times
index|[
name|NCLKBUGTIMES
index|]
decl_stmt|;
comment|/* real times */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_IO_COMPLETION_PORT
end_ifdef

begin_decl_stmt
specifier|extern
name|HANDLE
name|WaitableIoEventHandle
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Structure interface between the reference clock support  * ntp_refclock.c and the driver utility routines  */
end_comment

begin_define
define|#
directive|define
name|MAXSTAGE
value|60
end_define

begin_comment
comment|/* max median filter stages  */
end_comment

begin_define
define|#
directive|define
name|NSTAGE
value|5
end_define

begin_comment
comment|/* default median filter stages */
end_comment

begin_define
define|#
directive|define
name|BMAX
value|128
end_define

begin_comment
comment|/* max timecode length */
end_comment

begin_define
define|#
directive|define
name|GMT
value|0
end_define

begin_comment
comment|/* I hope nobody sees this */
end_comment

begin_define
define|#
directive|define
name|MAXDIAL
value|60
end_define

begin_comment
comment|/* max length of modem dial strings */
end_comment

begin_struct
struct|struct
name|refclockproc
block|{
name|void
modifier|*
name|unitptr
decl_stmt|;
comment|/* pointer to unit structure */
name|struct
name|refclock
modifier|*
name|conf
decl_stmt|;
comment|/* refclock_conf[type] */
name|struct
name|refclockio
name|io
decl_stmt|;
comment|/* I/O handler structure */
name|u_char
name|leap
decl_stmt|;
comment|/* leap/synchronization code */
name|u_char
name|currentstatus
decl_stmt|;
comment|/* clock status */
name|u_char
name|lastevent
decl_stmt|;
comment|/* last exception event */
name|u_char
name|type
decl_stmt|;
comment|/* clock type */
specifier|const
name|char
modifier|*
name|clockdesc
decl_stmt|;
comment|/* clock description */
name|u_long
name|nextaction
decl_stmt|;
comment|/* local activity timeout */
name|void
function_decl|(
modifier|*
name|action
function_decl|)
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
comment|/* timeout callback */
name|char
name|a_lastcode
index|[
name|BMAX
index|]
decl_stmt|;
comment|/* last timecode received */
name|int
name|lencode
decl_stmt|;
comment|/* length of last timecode */
name|int
name|year
decl_stmt|;
comment|/* year of eternity */
name|int
name|day
decl_stmt|;
comment|/* day of year */
name|int
name|hour
decl_stmt|;
comment|/* hour of day */
name|int
name|minute
decl_stmt|;
comment|/* minute of hour */
name|int
name|second
decl_stmt|;
comment|/* second of minute */
name|long
name|nsec
decl_stmt|;
comment|/* nanosecond of second */
name|u_long
name|yearstart
decl_stmt|;
comment|/* beginning of year */
name|int
name|coderecv
decl_stmt|;
comment|/* put pointer */
name|int
name|codeproc
decl_stmt|;
comment|/* get pointer */
name|l_fp
name|lastref
decl_stmt|;
comment|/* reference timestamp */
name|l_fp
name|lastrec
decl_stmt|;
comment|/* receive timestamp */
name|double
name|offset
decl_stmt|;
comment|/* mean offset */
name|double
name|disp
decl_stmt|;
comment|/* sample dispersion */
name|double
name|jitter
decl_stmt|;
comment|/* jitter (mean squares) */
name|double
name|filter
index|[
name|MAXSTAGE
index|]
decl_stmt|;
comment|/* median filter */
comment|/* 	 * Configuration data 	 */
name|double
name|fudgetime1
decl_stmt|;
comment|/* fudge time1 */
name|double
name|fudgetime2
decl_stmt|;
comment|/* fudge time2 */
name|u_char
name|stratum
decl_stmt|;
comment|/* server stratum */
name|u_int32
name|refid
decl_stmt|;
comment|/* reference identifier */
name|u_char
name|sloppyclockflag
decl_stmt|;
comment|/* fudge flags */
comment|/* 	 * Status tallies  	 */
name|u_long
name|timestarted
decl_stmt|;
comment|/* time we started this */
name|u_long
name|polls
decl_stmt|;
comment|/* polls sent */
name|u_long
name|noreply
decl_stmt|;
comment|/* no replies to polls */
name|u_long
name|badformat
decl_stmt|;
comment|/* bad format reply */
name|u_long
name|baddata
decl_stmt|;
comment|/* bad data reply */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure interface between the reference clock support  * ntp_refclock.c and particular clock drivers. This must agree with the  * structure defined in the driver.  */
end_comment

begin_define
define|#
directive|define
name|noentry
value|0
end_define

begin_comment
comment|/* flag for null routine */
end_comment

begin_define
define|#
directive|define
name|NOFLAGS
value|0
end_define

begin_comment
comment|/* flag for null flags */
end_comment

begin_struct
struct|struct
name|refclock
block|{
name|int
function_decl|(
modifier|*
name|clock_start
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clock_shutdown
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clock_poll
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clock_control
function_decl|)
parameter_list|(
name|int
parameter_list|,
specifier|const
name|struct
name|refclockstat
modifier|*
parameter_list|,
name|struct
name|refclockstat
modifier|*
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clock_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clock_buginfo
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|refclockbug
modifier|*
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clock_timer
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_function_decl
specifier|extern
name|int
name|io_addclock
parameter_list|(
name|struct
name|refclockio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|io_closeclock
parameter_list|(
name|struct
name|refclockio
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|REFCLOCK
end_ifdef

begin_function_decl
specifier|extern
name|void
name|refclock_buginfo
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
name|struct
name|refclockbug
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|refclock_control
parameter_list|(
name|sockaddr_u
modifier|*
parameter_list|,
specifier|const
name|struct
name|refclockstat
modifier|*
parameter_list|,
name|struct
name|refclockstat
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|refclock_open
parameter_list|(
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|refclock_setup
parameter_list|(
name|int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|refclock_timer
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|refclock_transmit
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|refclock_process
parameter_list|(
name|struct
name|refclockproc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|refclock_process_f
parameter_list|(
name|struct
name|refclockproc
modifier|*
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|refclock_process_offset
parameter_list|(
name|struct
name|refclockproc
modifier|*
parameter_list|,
name|l_fp
parameter_list|,
name|l_fp
parameter_list|,
name|double
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|refclock_report
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|refclock_gtlin
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|refclock_gtraw
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|l_fp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|indicate_refclock_packet
parameter_list|(
name|struct
name|refclockio
modifier|*
parameter_list|,
name|struct
name|recvbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|process_refclock_packet
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REFCLOCK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_REFCLOCK_H */
end_comment

end_unit

