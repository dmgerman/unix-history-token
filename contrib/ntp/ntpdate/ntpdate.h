begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntpdate.h - declarations for the ntpdate and ntptimeset programs  */
end_comment

begin_include
include|#
directive|include
file|"ntp_malloc.h"
end_include

begin_comment
comment|/*  * The server structure is a much simplified version of the  * peer structure, for ntpdate's use.  Since we always send  * in client mode and expect to receive in server mode, this  * leaves only a very limited number of things we need to  * remember about the server.  */
end_comment

begin_struct
struct|struct
name|server
block|{
name|struct
name|server
modifier|*
name|next_server
decl_stmt|;
comment|/* next server in build list */
name|struct
name|sockaddr_in
name|srcadr
decl_stmt|;
comment|/* address of remote host */
name|u_char
name|version
decl_stmt|;
comment|/* version to use */
name|u_char
name|leap
decl_stmt|;
comment|/* leap indicator */
name|u_char
name|stratum
decl_stmt|;
comment|/* stratum of remote server */
name|s_char
name|precision
decl_stmt|;
comment|/* server's clock precision */
name|u_char
name|trust
decl_stmt|;
comment|/* trustability of the filtered data */
name|u_fp
name|rootdelay
decl_stmt|;
comment|/* distance from primary clock */
name|u_fp
name|rootdispersion
decl_stmt|;
comment|/* peer clock dispersion */
name|u_int32
name|refid
decl_stmt|;
comment|/* peer reference ID */
name|l_fp
name|reftime
decl_stmt|;
comment|/* time of peer's last update */
name|u_long
name|event_time
decl_stmt|;
comment|/* time for next timeout */
name|u_long
name|last_xmit
decl_stmt|;
comment|/* time of last transmit */
name|u_short
name|xmtcnt
decl_stmt|;
comment|/* number of packets transmitted */
name|u_short
name|rcvcnt
decl_stmt|;
comment|/* number of packets received */
name|u_char
name|reach
decl_stmt|;
comment|/* reachability, NTP_WINDOW bits */
name|u_short
name|filter_nextpt
decl_stmt|;
comment|/* index into filter shift register */
name|s_fp
name|filter_delay
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* delay part of shift register */
name|l_fp
name|filter_offset
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* offset part of shift register */
name|s_fp
name|filter_soffset
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* offset in s_fp format, for disp */
name|u_fp
name|filter_error
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* error part of shift register */
name|l_fp
name|org
decl_stmt|;
comment|/* peer's originate time stamp */
name|l_fp
name|xmt
decl_stmt|;
comment|/* transmit time stamp */
name|u_fp
name|delay
decl_stmt|;
comment|/* filter estimated delay */
name|u_fp
name|dispersion
decl_stmt|;
comment|/* filter estimated dispersion */
name|l_fp
name|offset
decl_stmt|;
comment|/* filter estimated clock offset */
name|s_fp
name|soffset
decl_stmt|;
comment|/* fp version of above */
block|}
struct|;
end_struct

begin_comment
comment|/*  * ntpdate runs everything on a simple, short timeout.  It sends a  * packet and sets the timeout (by default, to a small value suitable  * for a LAN).  If it receives a response it sends another request.  * If it times out it shifts zeroes into the filter and sends another  * request.  *  * The timer routine is run often (once every 1/5 second currently)  * so that time outs are done with reasonable precision.  */
end_comment

begin_define
define|#
directive|define
name|TIMER_HZ
value|(5)
end_define

begin_comment
comment|/* 5 per second */
end_comment

begin_comment
comment|/*  * ntpdate will make a long adjustment using adjtime() if the times  * are close, or step the time if the times are farther apart.  The  * following defines what is "close".  */
end_comment

begin_define
define|#
directive|define
name|NTPDATE_THRESHOLD
value|(FP_SECOND>> 1)
end_define

begin_comment
comment|/* 1/2 second */
end_comment

begin_comment
comment|/*  * When doing adjustments, ntpdate actually overadjusts (currently  * by 50%, though this may change).  While this will make it take longer  * to reach a steady state condition, it will typically result in  * the clock keeping more accurate time, on average.  The amount of  * overshoot is limited.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOTNOW
end_ifdef

begin_define
define|#
directive|define
name|ADJ_OVERSHOOT
value|1/2
end_define

begin_comment
comment|/* this is hard coded */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOTNOW */
end_comment

begin_define
define|#
directive|define
name|ADJ_MAXOVERSHOOT
value|0x10000000
end_define

begin_comment
comment|/* 50 ms as a ts fraction */
end_comment

begin_comment
comment|/*  * Since ntpdate isn't aware of some of the things that normally get  * put in an NTP packet, we fix some values.  */
end_comment

begin_define
define|#
directive|define
name|NTPDATE_PRECISION
value|(-6)
end_define

begin_comment
comment|/* use this precision */
end_comment

begin_define
define|#
directive|define
name|NTPDATE_DISTANCE
value|FP_SECOND
end_define

begin_comment
comment|/* distance is 1 sec */
end_comment

begin_define
define|#
directive|define
name|NTPDATE_DISP
value|FP_SECOND
end_define

begin_comment
comment|/* so is the dispersion */
end_comment

begin_define
define|#
directive|define
name|NTPDATE_REFID
value|(0)
end_define

begin_comment
comment|/* reference ID to use */
end_comment

begin_define
define|#
directive|define
name|PEER_MAXDISP
value|(64*FP_SECOND)
end_define

begin_comment
comment|/* maximum dispersion (fp 64) */
end_comment

begin_comment
comment|/*  * Some defaults  */
end_comment

begin_define
define|#
directive|define
name|DEFTIMEOUT
value|5
end_define

begin_comment
comment|/* 5 timer increments */
end_comment

begin_define
define|#
directive|define
name|DEFSAMPLES
value|4
end_define

begin_comment
comment|/* get 4 samples per server */
end_comment

begin_define
define|#
directive|define
name|DEFPRECISION
value|(-5)
end_define

begin_comment
comment|/* the precision we claim */
end_comment

begin_define
define|#
directive|define
name|DEFMAXPERIOD
value|60
end_define

begin_comment
comment|/* maximum time to wait */
end_comment

begin_define
define|#
directive|define
name|DEFMINSERVERS
value|3
end_define

begin_comment
comment|/* minimum responding servers */
end_comment

begin_define
define|#
directive|define
name|DEFMINVALID
value|1
end_define

begin_comment
comment|/* mimimum servers with valid time */
end_comment

end_unit

