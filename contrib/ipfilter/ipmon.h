begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1993-2001 by Darren Reed.  *  * See the IPFILTER.LICENCE file for details on licencing.  *  * @(#)ip_fil.h	1.35 6/5/96  * Id: ipmon.h,v 2.8 2003/07/25 22:16:20 darrenr Exp  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ipmon_action
block|{
name|struct
name|ipmon_action
modifier|*
name|ac_next
decl_stmt|;
name|int
name|ac_mflag
decl_stmt|;
comment|/* collection of things to compare */
name|int
name|ac_dflag
decl_stmt|;
comment|/* flags to compliment the doing fields */
name|int
name|ac_syslog
decl_stmt|;
comment|/* = 1 to syslog rules. */
name|char
modifier|*
name|ac_savefile
decl_stmt|;
comment|/* filename to save log records to */
name|FILE
modifier|*
name|ac_savefp
decl_stmt|;
name|int
name|ac_direction
decl_stmt|;
name|char
name|ac_group
index|[
name|FR_GROUPLEN
index|]
decl_stmt|;
name|char
name|ac_nattag
index|[
literal|16
index|]
decl_stmt|;
name|u_32_t
name|ac_logtag
decl_stmt|;
name|int
name|ac_type
decl_stmt|;
comment|/* nat/state/ipf */
name|int
name|ac_proto
decl_stmt|;
name|int
name|ac_rule
decl_stmt|;
name|int
name|ac_packet
decl_stmt|;
name|int
name|ac_second
decl_stmt|;
name|int
name|ac_result
decl_stmt|;
name|u_32_t
name|ac_sip
decl_stmt|;
name|u_32_t
name|ac_smsk
decl_stmt|;
name|u_32_t
name|ac_dip
decl_stmt|;
name|u_32_t
name|ac_dmsk
decl_stmt|;
name|u_short
name|ac_sport
decl_stmt|;
name|u_short
name|ac_dport
decl_stmt|;
name|char
modifier|*
name|ac_exec
decl_stmt|;
comment|/* execute argument */
name|char
modifier|*
name|ac_run
decl_stmt|;
comment|/* actual command that gets run */
name|char
modifier|*
name|ac_iface
decl_stmt|;
comment|/* 	 * used with ac_packet/ac_second 	 */
name|struct
name|timeval
name|ac_last
decl_stmt|;
name|int
name|ac_pktcnt
decl_stmt|;
block|}
name|ipmon_action_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ac_lastsec
value|ac_last.tv_sec
end_define

begin_define
define|#
directive|define
name|ac_lastusec
value|ac_last.tv_usec
end_define

begin_comment
comment|/*  * Flags indicating what fields to do matching upon (ac_mflag).  */
end_comment

begin_define
define|#
directive|define
name|IPMAC_DIRECTION
value|0x0001
end_define

begin_define
define|#
directive|define
name|IPMAC_DSTIP
value|0x0002
end_define

begin_define
define|#
directive|define
name|IPMAC_DSTPORT
value|0x0004
end_define

begin_define
define|#
directive|define
name|IPMAC_EVERY
value|0x0008
end_define

begin_define
define|#
directive|define
name|IPMAC_GROUP
value|0x0010
end_define

begin_define
define|#
directive|define
name|IPMAC_INTERFACE
value|0x0020
end_define

begin_define
define|#
directive|define
name|IPMAC_LOGTAG
value|0x0040
end_define

begin_define
define|#
directive|define
name|IPMAC_NATTAG
value|0x0080
end_define

begin_define
define|#
directive|define
name|IPMAC_PROTOCOL
value|0x0100
end_define

begin_define
define|#
directive|define
name|IPMAC_RESULT
value|0x0200
end_define

begin_define
define|#
directive|define
name|IPMAC_RULE
value|0x0400
end_define

begin_define
define|#
directive|define
name|IPMAC_SRCIP
value|0x0800
end_define

begin_define
define|#
directive|define
name|IPMAC_SRCPORT
value|0x1000
end_define

begin_define
define|#
directive|define
name|IPMAC_TYPE
value|0x2000
end_define

begin_define
define|#
directive|define
name|IPMAC_WITH
value|0x4000
end_define

begin_define
define|#
directive|define
name|IPMR_BLOCK
value|1
end_define

begin_define
define|#
directive|define
name|IPMR_PASS
value|2
end_define

begin_define
define|#
directive|define
name|IPMR_NOMATCH
value|3
end_define

begin_define
define|#
directive|define
name|IPMR_LOG
value|4
end_define

begin_define
define|#
directive|define
name|IPMDO_SAVERAW
value|0x0001
end_define

begin_define
define|#
directive|define
name|OPT_SYSLOG
value|0x001
end_define

begin_define
define|#
directive|define
name|OPT_RESOLVE
value|0x002
end_define

begin_define
define|#
directive|define
name|OPT_HEXBODY
value|0x004
end_define

begin_define
define|#
directive|define
name|OPT_VERBOSE
value|0x008
end_define

begin_define
define|#
directive|define
name|OPT_HEXHDR
value|0x010
end_define

begin_define
define|#
directive|define
name|OPT_TAIL
value|0x020
end_define

begin_define
define|#
directive|define
name|OPT_NAT
value|0x080
end_define

begin_define
define|#
directive|define
name|OPT_STATE
value|0x100
end_define

begin_define
define|#
directive|define
name|OPT_FILTER
value|0x200
end_define

begin_define
define|#
directive|define
name|OPT_PORTNUM
value|0x400
end_define

begin_define
define|#
directive|define
name|OPT_LOGALL
value|(OPT_NAT|OPT_STATE|OPT_FILTER)
end_define

begin_define
define|#
directive|define
name|HOSTNAME_V4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|hostname((a), 4, (u_32_t *)&(b))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|LOGFAC
end_ifndef

begin_define
define|#
directive|define
name|LOGFAC
value|LOG_LOCAL0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|load_config
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dumphex
name|__P
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|check_action
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|,
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
name|char
modifier|*
name|getword
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

