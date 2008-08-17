begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntptrace.h - declarations for the ntptrace program  */
end_comment

begin_comment
comment|/*  * The server structure is a much simplified version of the  * peer structure, for ntptrace's use.  Since we always send  * in client mode and expect to receive in server mode, this  * leaves only a very limited number of things we need to  * remember about the server.  */
end_comment

begin_struct
struct|struct
name|server
block|{
name|struct
name|sockaddr_in
name|srcadr
decl_stmt|;
comment|/* address of remote host */
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
name|l_fp
name|org
decl_stmt|;
comment|/* peer's originate time stamp */
name|l_fp
name|xmt
decl_stmt|;
comment|/* transmit time stamp */
name|s_fp
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
block|}
struct|;
end_struct

begin_comment
comment|/*  * Since ntptrace isn't aware of some of the things that normally get  * put in an NTP packet, we fix some values.  */
end_comment

begin_define
define|#
directive|define
name|NTPTRACE_PRECISION
value|(-6)
end_define

begin_comment
comment|/* use this precision */
end_comment

begin_define
define|#
directive|define
name|NTPTRACE_DISTANCE
value|FP_SECOND
end_define

begin_comment
comment|/* distance is 1 sec */
end_comment

begin_define
define|#
directive|define
name|NTPTRACE_DISP
value|FP_SECOND
end_define

begin_comment
comment|/* so is the dispersion */
end_comment

begin_define
define|#
directive|define
name|NTPTRACE_REFID
value|(0)
end_define

begin_comment
comment|/* reference ID to use */
end_comment

end_unit

