begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_refclock.h - definitions for reference clock support  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_BSD_TTYS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BSD_TTYS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYSV_TTYS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYSV_TTYS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIOS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STREAM
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stropts.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CLK
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/clkdefs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CLK */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STREAM */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYSV_TTYS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STREAM
argument_list|)
operator|&
operator|!
name|defined
argument_list|(
name|BSD_TTYS
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD_TTYS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSV_TTYS STREAM BSD_TTYS */
end_comment

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
comment|/*  * List of reference clock names and descriptions. These must agree with  * lib/clocktypes.c and xntpd/refclock_conf.c.  */
end_comment

begin_struct
struct|struct
name|clktype
block|{
name|int
name|code
decl_stmt|;
comment|/* driver "major" number */
name|char
modifier|*
name|clocktype
decl_stmt|;
comment|/* long description */
name|char
modifier|*
name|abbrev
decl_stmt|;
comment|/* short description */
block|}
struct|;
end_struct

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
name|u_char
name|lencode
decl_stmt|;
comment|/* length of last timecode */
name|char
modifier|*
name|lastcode
decl_stmt|;
comment|/* last timecode received */
name|U_LONG
name|polls
decl_stmt|;
comment|/* transmit polls */
name|U_LONG
name|noresponse
decl_stmt|;
comment|/* no response to poll */
name|U_LONG
name|badformat
decl_stmt|;
comment|/* bad format timecode received */
name|U_LONG
name|baddata
decl_stmt|;
comment|/* invalid data timecode received */
name|U_LONG
name|timereset
decl_stmt|;
comment|/* driver resets */
name|char
modifier|*
name|clockdesc
decl_stmt|;
comment|/* ASCII description */
name|l_fp
name|fudgetime1
decl_stmt|;
comment|/* configure fudge time1 */
name|l_fp
name|fudgetime2
decl_stmt|;
comment|/* configure fudge time2 */
name|LONG
name|fudgeval1
decl_stmt|;
comment|/* configure fudge value1 */
name|LONG
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
name|unused
decl_stmt|;
comment|/* spare */
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
parameter_list|()
function_decl|;
comment|/* completion routine */
name|caddr_t
name|srcclock
decl_stmt|;
comment|/* pointer to clock structure */
name|int
name|datalen
decl_stmt|;
comment|/* lenth of data */
name|int
name|fd
decl_stmt|;
comment|/* file descriptor */
name|u_long
name|recvcount
decl_stmt|;
comment|/* count of receive completions */
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
name|U_LONG
name|stimes
decl_stmt|;
comment|/* times format sign array */
name|U_LONG
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

begin_comment
comment|/*  * Structure interface between the reference clock support  * ntp_refclock.c and the driver utility routines  */
end_comment

begin_define
define|#
directive|define
name|MAXSTAGE
value|64
end_define

begin_comment
comment|/* max stages in shift register */
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
value|20
end_define

begin_comment
comment|/* max length of modem dial strings */
end_comment

begin_comment
comment|/*  * Line discipline flags. These require line discipline or streams  * modules to be installed/loaded in the kernel. If specified, but not  * installed, the code runs as if unspecified.  */
end_comment

begin_define
define|#
directive|define
name|LDISC_STD
value|0x0
end_define

begin_comment
comment|/* standard */
end_comment

begin_define
define|#
directive|define
name|LDISC_CLK
value|0x1
end_define

begin_comment
comment|/* tty_clk \n intercept */
end_comment

begin_define
define|#
directive|define
name|LDISC_CLKPPS
value|0x2
end_define

begin_comment
comment|/* tty_clk \377 intercept */
end_comment

begin_define
define|#
directive|define
name|LDISC_ACTS
value|0x4
end_define

begin_comment
comment|/* tty_clk #* intercept */
end_comment

begin_define
define|#
directive|define
name|LDISC_CHU
value|0x8
end_define

begin_comment
comment|/* tty_chu */
end_comment

begin_define
define|#
directive|define
name|LDISC_PPS
value|0x10
end_define

begin_comment
comment|/* ppsclock */
end_comment

begin_struct
struct|struct
name|refclockproc
block|{
name|struct
name|refclockio
name|io
decl_stmt|;
comment|/* I/O handler structure */
name|caddr_t
name|unitptr
decl_stmt|;
comment|/* pointer to unit structure */
name|u_long
name|lasttime
decl_stmt|;
comment|/* last clock update time */
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
name|char
modifier|*
name|clockdesc
decl_stmt|;
comment|/* clock description */
name|char
name|lastcode
index|[
name|BMAX
index|]
decl_stmt|;
comment|/* last timecode received */
name|u_char
name|lencode
decl_stmt|;
comment|/* length of last timecode */
name|u_int
name|year
decl_stmt|;
comment|/* year of eternity */
name|u_int
name|day
decl_stmt|;
comment|/* day of year */
name|u_int
name|hour
decl_stmt|;
comment|/* hour of day */
name|u_int
name|minute
decl_stmt|;
comment|/* minute of hour */
name|u_int
name|second
decl_stmt|;
comment|/* second of minute */
name|u_int
name|msec
decl_stmt|;
comment|/* millisecond of second */
name|u_long
name|usec
decl_stmt|;
comment|/* microsecond of second (alt) */
name|u_int
name|nstages
decl_stmt|;
comment|/* median filter stages */
name|u_long
name|yearstart
decl_stmt|;
comment|/* beginning of year */
name|u_long
name|coderecv
decl_stmt|;
comment|/* sample counter */
name|l_fp
name|lastref
decl_stmt|;
comment|/* last reference timestamp */
name|l_fp
name|lastrec
decl_stmt|;
comment|/* last local timestamp */
name|l_fp
name|offset
decl_stmt|;
comment|/* median offset */
name|u_fp
name|dispersion
decl_stmt|;
comment|/* sample dispersion */
name|l_fp
name|filter
index|[
name|MAXSTAGE
index|]
decl_stmt|;
comment|/* median filter */
comment|/* 	 * Configuration data 	 */
name|l_fp
name|fudgetime1
decl_stmt|;
comment|/* fudge time1 */
name|l_fp
name|fudgetime2
decl_stmt|;
comment|/* fudge time2 */
name|u_long
name|refid
decl_stmt|;
comment|/* reference identifier */
name|u_long
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
argument_list|(
argument|*clock_start
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*clock_shutdown
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*clock_poll
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*clock_control
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|refclockstat
operator|*
operator|,
expr|struct
name|refclockstat
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*clock_init
argument_list|)
name|P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*clock_buginfo
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|refclockbug
operator|*
operator|)
argument_list|)
expr_stmt|;
name|u_long
name|clock_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|io_addclock_simple
name|P
argument_list|(
operator|(
expr|struct
name|refclockio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|io_addclock
name|P
argument_list|(
operator|(
expr|struct
name|refclockio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|io_closeclock
name|P
argument_list|(
operator|(
expr|struct
name|refclockio
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|REFCLOCK
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|refclock_buginfo
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|refclockbug
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|refclock_control
name|P
argument_list|(
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|refclockstat
operator|*
operator|,
expr|struct
name|refclockstat
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|refclock_open
name|P
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|refclock_transmit
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|refclock_ioctl
name|P
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|refclock_process
name|P
argument_list|(
operator|(
expr|struct
name|refclockproc
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|refclock_report
name|P
argument_list|(
operator|(
expr|struct
name|peer
operator|*
operator|,
name|u_char
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|refclock_gtlin
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|l_fp
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REFCLOCK */
end_comment

end_unit

