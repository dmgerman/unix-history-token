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
comment|/*  * Macros to determine the clock type and unit numbers from a  * 127.127.t.u address.  */
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
comment|/*  * list of reference clock names  * see lib/clocktypes.c (must also agree with xntpd/refclock_conf.c)  */
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
comment|/* LONG description */
name|char
modifier|*
name|abbrev
decl_stmt|;
comment|/* short description */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Definitions for default values  */
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

begin_comment
comment|/*  * Definitions for flags  */
end_comment

begin_define
define|#
directive|define
name|NOFLAGS
value|0
end_define

begin_define
define|#
directive|define
name|REF_FLAG_BCLIENT
value|0x1
end_define

begin_comment
comment|/* clock prefers to run as a bclient */
end_comment

begin_comment
comment|/*  * Flag values  */
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
name|u_char
name|flags
decl_stmt|;
name|u_char
name|haveflags
decl_stmt|;
name|u_short
name|lencode
decl_stmt|;
comment|/* ahem, we do have some longer "time-codes" */
name|char
modifier|*
name|lastcode
decl_stmt|;
name|U_LONG
name|polls
decl_stmt|;
name|U_LONG
name|noresponse
decl_stmt|;
name|U_LONG
name|badformat
decl_stmt|;
name|U_LONG
name|baddata
decl_stmt|;
name|U_LONG
name|timereset
decl_stmt|;
name|char
modifier|*
name|clockdesc
decl_stmt|;
comment|/* description of clock, in ASCII */
name|l_fp
name|fudgetime1
decl_stmt|;
name|l_fp
name|fudgetime2
decl_stmt|;
name|LONG
name|fudgeval1
decl_stmt|;
name|LONG
name|fudgeval2
decl_stmt|;
name|u_char
name|currentstatus
decl_stmt|;
name|u_char
name|lastevent
decl_stmt|;
name|u_char
name|unused
decl_stmt|;
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
name|void
function_decl|(
modifier|*
name|clock_recv
function_decl|)
parameter_list|()
function_decl|;
name|caddr_t
name|srcclock
decl_stmt|;
comment|/* pointer to clock structure */
name|int
name|datalen
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|U_LONG
name|recvcount
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Sizes of things we return for debugging  */
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

begin_comment
comment|/*  * Structure for returning debugging info  */
end_comment

begin_struct
struct|struct
name|refclockbug
block|{
name|u_char
name|nvalues
decl_stmt|;
name|u_char
name|ntimes
decl_stmt|;
name|u_short
name|svalues
decl_stmt|;
name|U_LONG
name|stimes
decl_stmt|;
name|U_LONG
name|values
index|[
name|NCLKBUGVALUES
index|]
decl_stmt|;
name|l_fp
name|times
index|[
name|NCLKBUGTIMES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Struct refclock provides the interface between the reference  * clock support and particular clock drivers.  There are entries  * to open and close a unit, optional values to specify the  * timer interval for calls to the transmit procedure and to  * specify a polling routine to be called when the transmit  * procedure executes.  There is an entry which is called when  * the transmit routine is about to shift zeroes into the  * filter register, and entries for stuffing fudge factors into  * the driver and getting statistics from it.  */
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
name|u_int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* start a clock unit */
name|void
argument_list|(
argument|*clock_shutdown
argument_list|)
name|P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
expr_stmt|;
comment|/* shut a clock down */
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
comment|/* called from the xmit routine */
name|void
argument_list|(
argument|*clock_control
argument_list|)
name|P
argument_list|(
operator|(
name|u_int
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
comment|/* set fudge values, return stats */
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
comment|/* initialize driver data at startup */
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
comment|/* get clock dependent bug info */
name|U_LONG
name|clock_flags
decl_stmt|;
comment|/* flag values */
block|}
struct|;
end_struct

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REFCLOCK */
end_comment

end_unit

