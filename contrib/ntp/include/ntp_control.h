begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_control.h - definitions related to NTP mode 6 control messages  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_struct
struct|struct
name|ntp_control
block|{
name|u_char
name|li_vn_mode
decl_stmt|;
comment|/* leap, version, mode */
name|u_char
name|r_m_e_op
decl_stmt|;
comment|/* response, more, error, opcode */
name|u_short
name|sequence
decl_stmt|;
comment|/* sequence number of request */
name|u_short
name|status
decl_stmt|;
comment|/* status word for association */
name|u_short
name|associd
decl_stmt|;
comment|/* association ID */
name|u_short
name|offset
decl_stmt|;
comment|/* offset of this batch of data */
name|u_short
name|count
decl_stmt|;
comment|/* count of data in this packet */
name|u_char
name|data
index|[
operator|(
literal|480
operator|+
name|MAX_MAC_LEN
operator|)
index|]
decl_stmt|;
comment|/* data + auth */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Length of the control header, in octets  */
end_comment

begin_define
define|#
directive|define
name|CTL_HEADER_LEN
value|12
end_define

begin_define
define|#
directive|define
name|CTL_MAX_DATA_LEN
value|468
end_define

begin_comment
comment|/*  * Limits and things  */
end_comment

begin_define
define|#
directive|define
name|CTL_MAXTRAPS
value|3
end_define

begin_comment
comment|/* maximum number of traps we allow */
end_comment

begin_define
define|#
directive|define
name|CTL_TRAPTIME
value|(60*60)
end_define

begin_comment
comment|/* time out traps in 1 hour */
end_comment

begin_define
define|#
directive|define
name|CTL_MAXAUTHSIZE
value|64
end_define

begin_comment
comment|/* maximum size of an authen'ed req */
end_comment

begin_comment
comment|/*  * Decoding for the r_m_e_op field  */
end_comment

begin_define
define|#
directive|define
name|CTL_RESPONSE
value|0x80
end_define

begin_define
define|#
directive|define
name|CTL_ERROR
value|0x40
end_define

begin_define
define|#
directive|define
name|CTL_MORE
value|0x20
end_define

begin_define
define|#
directive|define
name|CTL_OP_MASK
value|0x1f
end_define

begin_define
define|#
directive|define
name|CTL_ISRESPONSE
parameter_list|(
name|r_m_e_op
parameter_list|)
value|(((r_m_e_op)& 0x80) != 0)
end_define

begin_define
define|#
directive|define
name|CTL_ISMORE
parameter_list|(
name|r_m_e_op
parameter_list|)
value|(((r_m_e_op)& 0x20) != 0)
end_define

begin_define
define|#
directive|define
name|CTL_ISERROR
parameter_list|(
name|r_m_e_op
parameter_list|)
value|(((r_m_e_op)& 0x40) != 0)
end_define

begin_define
define|#
directive|define
name|CTL_OP
parameter_list|(
name|r_m_e_op
parameter_list|)
value|((r_m_e_op)& CTL_OP_MASK)
end_define

begin_comment
comment|/*  * Opcodes  */
end_comment

begin_define
define|#
directive|define
name|CTL_OP_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|CTL_OP_READSTAT
value|1
end_define

begin_define
define|#
directive|define
name|CTL_OP_READVAR
value|2
end_define

begin_define
define|#
directive|define
name|CTL_OP_WRITEVAR
value|3
end_define

begin_define
define|#
directive|define
name|CTL_OP_READCLOCK
value|4
end_define

begin_define
define|#
directive|define
name|CTL_OP_WRITECLOCK
value|5
end_define

begin_define
define|#
directive|define
name|CTL_OP_SETTRAP
value|6
end_define

begin_define
define|#
directive|define
name|CTL_OP_ASYNCMSG
value|7
end_define

begin_define
define|#
directive|define
name|CTL_OP_UNSETTRAP
value|31
end_define

begin_comment
comment|/*  * {En,De}coding of the system status word  */
end_comment

begin_define
define|#
directive|define
name|CTL_SST_TS_UNSPEC
value|0
end_define

begin_comment
comment|/* time source unspecified */
end_comment

begin_define
define|#
directive|define
name|CTL_SST_TS_ATOM
value|1
end_define

begin_comment
comment|/* time source calibrated atomic */
end_comment

begin_define
define|#
directive|define
name|CTL_SST_TS_LF
value|2
end_define

begin_comment
comment|/* time source VLF or LF radio */
end_comment

begin_define
define|#
directive|define
name|CTL_SST_TS_HF
value|3
end_define

begin_comment
comment|/* time source HF radio */
end_comment

begin_define
define|#
directive|define
name|CTL_SST_TS_UHF
value|4
end_define

begin_comment
comment|/* time source UHF radio */
end_comment

begin_define
define|#
directive|define
name|CTL_SST_TS_LOCAL
value|5
end_define

begin_comment
comment|/* time source LOCAL */
end_comment

begin_define
define|#
directive|define
name|CTL_SST_TS_NTP
value|6
end_define

begin_comment
comment|/* time source NTP */
end_comment

begin_define
define|#
directive|define
name|CTL_SST_TS_UDPTIME
value|7
end_define

begin_comment
comment|/* time source UDP/TIME */
end_comment

begin_define
define|#
directive|define
name|CTL_SST_TS_WRSTWTCH
value|8
end_define

begin_comment
comment|/* time source is wristwatch */
end_comment

begin_define
define|#
directive|define
name|CTL_SST_TS_TELEPHONE
value|9
end_define

begin_comment
comment|/* time source is telephone modem */
end_comment

begin_define
define|#
directive|define
name|CTL_SST_TS_PPS
value|0x20
end_define

begin_comment
comment|/* time source is PPS signal */
end_comment

begin_define
define|#
directive|define
name|CTL_SYS_MAXEVENTS
value|15
end_define

begin_define
define|#
directive|define
name|CTL_SYS_STATUS
parameter_list|(
name|li
parameter_list|,
name|source
parameter_list|,
name|nevnt
parameter_list|,
name|evnt
parameter_list|)
define|\
value|(((((unsigned short)(li))<< 14)&0xc000) | \ 		(((source)<<8)&0x3f00) | \ 		(((nevnt)<<4)&0x00f0) | \ 		((evnt)&0x000f))
end_define

begin_define
define|#
directive|define
name|CTL_SYS_LI
parameter_list|(
name|status
parameter_list|)
value|(((status)>>14)& 0x3)
end_define

begin_define
define|#
directive|define
name|CTL_SYS_SOURCE
parameter_list|(
name|status
parameter_list|)
value|(((status)>>8)& 0x3f)
end_define

begin_define
define|#
directive|define
name|CTL_SYS_NEVNT
parameter_list|(
name|status
parameter_list|)
value|(((status)>>4)& 0xf)
end_define

begin_define
define|#
directive|define
name|CTL_SYS_EVENT
parameter_list|(
name|status
parameter_list|)
value|((status)& 0xf)
end_define

begin_comment
comment|/*  * {En,De}coding of the peer status word  */
end_comment

begin_define
define|#
directive|define
name|CTL_PST_CONFIG
value|0x80
end_define

begin_define
define|#
directive|define
name|CTL_PST_AUTHENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|CTL_PST_AUTHENTIC
value|0x20
end_define

begin_define
define|#
directive|define
name|CTL_PST_REACH
value|0x10
end_define

begin_define
define|#
directive|define
name|CTL_PST_UNSPEC
value|0x08
end_define

begin_define
define|#
directive|define
name|CTL_PST_SEL_REJECT
value|0
end_define

begin_comment
comment|/*   reject */
end_comment

begin_define
define|#
directive|define
name|CTL_PST_SEL_SANE
value|1
end_define

begin_comment
comment|/* x falsetick */
end_comment

begin_define
define|#
directive|define
name|CTL_PST_SEL_CORRECT
value|2
end_define

begin_comment
comment|/* . excess */
end_comment

begin_define
define|#
directive|define
name|CTL_PST_SEL_SELCAND
value|3
end_define

begin_comment
comment|/* - outlyer */
end_comment

begin_define
define|#
directive|define
name|CTL_PST_SEL_SYNCCAND
value|4
end_define

begin_comment
comment|/* + candidat */
end_comment

begin_define
define|#
directive|define
name|CTL_PST_SEL_DISTSYSPEER
value|5
end_define

begin_comment
comment|/* # selected */
end_comment

begin_define
define|#
directive|define
name|CTL_PST_SEL_SYSPEER
value|6
end_define

begin_comment
comment|/* * sys.peer */
end_comment

begin_define
define|#
directive|define
name|CTL_PST_SEL_PPS
value|7
end_define

begin_comment
comment|/* o pps.peer */
end_comment

begin_define
define|#
directive|define
name|CTL_PEER_MAXEVENTS
value|15
end_define

begin_define
define|#
directive|define
name|CTL_PEER_STATUS
parameter_list|(
name|status
parameter_list|,
name|nevnt
parameter_list|,
name|evnt
parameter_list|)
define|\
value|((((status)<<8)& 0xff00) | \ 		(((nevnt)<<4)& 0x00f0) | \ 		((evnt)& 0x000f))
end_define

begin_define
define|#
directive|define
name|CTL_PEER_STATVAL
parameter_list|(
name|status
parameter_list|)
value|(((status)>>8)& 0xff)
end_define

begin_define
define|#
directive|define
name|CTL_PEER_NEVNT
parameter_list|(
name|status
parameter_list|)
value|(((status)>>4)& 0xf)
end_define

begin_define
define|#
directive|define
name|CTL_PEER_EVENT
parameter_list|(
name|status
parameter_list|)
value|((status)& 0xf)
end_define

begin_comment
comment|/*  * {En,De}coding of the clock status word  */
end_comment

begin_define
define|#
directive|define
name|CTL_CLK_OKAY
value|0
end_define

begin_define
define|#
directive|define
name|CTL_CLK_NOREPLY
value|1
end_define

begin_define
define|#
directive|define
name|CTL_CLK_BADFORMAT
value|2
end_define

begin_define
define|#
directive|define
name|CTL_CLK_FAULT
value|3
end_define

begin_define
define|#
directive|define
name|CTL_CLK_PROPAGATION
value|4
end_define

begin_define
define|#
directive|define
name|CTL_CLK_BADDATE
value|5
end_define

begin_define
define|#
directive|define
name|CTL_CLK_BADTIME
value|6
end_define

begin_define
define|#
directive|define
name|CTL_CLK_STATUS
parameter_list|(
name|status
parameter_list|,
name|event
parameter_list|)
define|\
value|((((status)<<8)& 0xff00) | \ 		((event)& 0x00ff))
end_define

begin_comment
comment|/*  * Error code responses returned when the E bit is set.  */
end_comment

begin_define
define|#
directive|define
name|CERR_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|CERR_PERMISSION
value|1
end_define

begin_define
define|#
directive|define
name|CERR_BADFMT
value|2
end_define

begin_define
define|#
directive|define
name|CERR_BADOP
value|3
end_define

begin_define
define|#
directive|define
name|CERR_BADASSOC
value|4
end_define

begin_define
define|#
directive|define
name|CERR_UNKNOWNVAR
value|5
end_define

begin_define
define|#
directive|define
name|CERR_BADVALUE
value|6
end_define

begin_define
define|#
directive|define
name|CERR_RESTRICT
value|7
end_define

begin_define
define|#
directive|define
name|CERR_NORESOURCE
value|CERR_PERMISSION
end_define

begin_comment
comment|/* wish there was a different code */
end_comment

begin_comment
comment|/*  * System variables we understand  */
end_comment

begin_define
define|#
directive|define
name|CS_LEAP
value|1
end_define

begin_define
define|#
directive|define
name|CS_STRATUM
value|2
end_define

begin_define
define|#
directive|define
name|CS_PRECISION
value|3
end_define

begin_define
define|#
directive|define
name|CS_ROOTDELAY
value|4
end_define

begin_define
define|#
directive|define
name|CS_ROOTDISPERSION
value|5
end_define

begin_define
define|#
directive|define
name|CS_REFID
value|6
end_define

begin_define
define|#
directive|define
name|CS_REFTIME
value|7
end_define

begin_define
define|#
directive|define
name|CS_POLL
value|8
end_define

begin_define
define|#
directive|define
name|CS_PEERID
value|9
end_define

begin_define
define|#
directive|define
name|CS_STATE
value|10
end_define

begin_define
define|#
directive|define
name|CS_OFFSET
value|11
end_define

begin_define
define|#
directive|define
name|CS_DRIFT
value|12
end_define

begin_define
define|#
directive|define
name|CS_COMPLIANCE
value|13
end_define

begin_define
define|#
directive|define
name|CS_CLOCK
value|14
end_define

begin_define
define|#
directive|define
name|CS_PROCESSOR
value|15
end_define

begin_define
define|#
directive|define
name|CS_SYSTEM
value|16
end_define

begin_define
define|#
directive|define
name|CS_STABIL
value|17
end_define

begin_define
define|#
directive|define
name|CS_VARLIST
value|18
end_define

begin_define
define|#
directive|define
name|CS_MAXCODE
value|CS_VARLIST
end_define

begin_comment
comment|/*  * Peer variables we understand  */
end_comment

begin_define
define|#
directive|define
name|CP_CONFIG
value|1
end_define

begin_define
define|#
directive|define
name|CP_AUTHENABLE
value|2
end_define

begin_define
define|#
directive|define
name|CP_AUTHENTIC
value|3
end_define

begin_define
define|#
directive|define
name|CP_SRCADR
value|4
end_define

begin_define
define|#
directive|define
name|CP_SRCPORT
value|5
end_define

begin_define
define|#
directive|define
name|CP_DSTADR
value|6
end_define

begin_define
define|#
directive|define
name|CP_DSTPORT
value|7
end_define

begin_define
define|#
directive|define
name|CP_LEAP
value|8
end_define

begin_define
define|#
directive|define
name|CP_HMODE
value|9
end_define

begin_define
define|#
directive|define
name|CP_STRATUM
value|10
end_define

begin_define
define|#
directive|define
name|CP_PPOLL
value|11
end_define

begin_define
define|#
directive|define
name|CP_HPOLL
value|12
end_define

begin_define
define|#
directive|define
name|CP_PRECISION
value|13
end_define

begin_define
define|#
directive|define
name|CP_ROOTDELAY
value|14
end_define

begin_define
define|#
directive|define
name|CP_ROOTDISPERSION
value|15
end_define

begin_define
define|#
directive|define
name|CP_REFID
value|16
end_define

begin_define
define|#
directive|define
name|CP_REFTIME
value|17
end_define

begin_define
define|#
directive|define
name|CP_ORG
value|18
end_define

begin_define
define|#
directive|define
name|CP_REC
value|19
end_define

begin_define
define|#
directive|define
name|CP_XMT
value|20
end_define

begin_define
define|#
directive|define
name|CP_REACH
value|21
end_define

begin_define
define|#
directive|define
name|CP_VALID
value|22
end_define

begin_define
define|#
directive|define
name|CP_TIMER
value|23
end_define

begin_define
define|#
directive|define
name|CP_DELAY
value|24
end_define

begin_define
define|#
directive|define
name|CP_OFFSET
value|25
end_define

begin_define
define|#
directive|define
name|CP_JITTER
value|26
end_define

begin_define
define|#
directive|define
name|CP_DISPERSION
value|27
end_define

begin_define
define|#
directive|define
name|CP_KEYID
value|28
end_define

begin_define
define|#
directive|define
name|CP_FILTDELAY
value|29
end_define

begin_define
define|#
directive|define
name|CP_FILTOFFSET
value|30
end_define

begin_define
define|#
directive|define
name|CP_PMODE
value|31
end_define

begin_define
define|#
directive|define
name|CP_RECEIVED
value|32
end_define

begin_define
define|#
directive|define
name|CP_SENT
value|33
end_define

begin_define
define|#
directive|define
name|CP_FILTERROR
value|34
end_define

begin_define
define|#
directive|define
name|CP_FLASH
value|35
end_define

begin_define
define|#
directive|define
name|CP_DISP
value|36
end_define

begin_define
define|#
directive|define
name|CP_VARLIST
value|37
end_define

begin_define
define|#
directive|define
name|CP_MAXCODE
value|CP_VARLIST
end_define

begin_comment
comment|/*  * Clock variables we understand  */
end_comment

begin_define
define|#
directive|define
name|CC_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|CC_TIMECODE
value|2
end_define

begin_define
define|#
directive|define
name|CC_POLL
value|3
end_define

begin_define
define|#
directive|define
name|CC_NOREPLY
value|4
end_define

begin_define
define|#
directive|define
name|CC_BADFORMAT
value|5
end_define

begin_define
define|#
directive|define
name|CC_BADDATA
value|6
end_define

begin_define
define|#
directive|define
name|CC_FUDGETIME1
value|7
end_define

begin_define
define|#
directive|define
name|CC_FUDGETIME2
value|8
end_define

begin_define
define|#
directive|define
name|CC_FUDGEVAL1
value|9
end_define

begin_define
define|#
directive|define
name|CC_FUDGEVAL2
value|10
end_define

begin_define
define|#
directive|define
name|CC_FLAGS
value|11
end_define

begin_define
define|#
directive|define
name|CC_DEVICE
value|12
end_define

begin_define
define|#
directive|define
name|CC_VARLIST
value|13
end_define

begin_define
define|#
directive|define
name|CC_MAXCODE
value|CC_VARLIST
end_define

begin_comment
comment|/*  * Definition of the structure used internally to hold trap information.  * ntp_request.c wants to see this.  */
end_comment

begin_struct
struct|struct
name|ctl_trap
block|{
name|struct
name|sockaddr_in
name|tr_addr
decl_stmt|;
comment|/* address of trap recipient */
name|struct
name|interface
modifier|*
name|tr_localaddr
decl_stmt|;
comment|/* interface to send this through */
name|u_long
name|tr_settime
decl_stmt|;
comment|/* time trap was set */
name|u_long
name|tr_count
decl_stmt|;
comment|/* async messages sent to this guy */
name|u_long
name|tr_origtime
decl_stmt|;
comment|/* time trap was originally set */
name|u_long
name|tr_resets
decl_stmt|;
comment|/* count of resets for this trap */
name|u_short
name|tr_sequence
decl_stmt|;
comment|/* trap sequence id */
name|u_char
name|tr_flags
decl_stmt|;
comment|/* trap flags */
name|u_char
name|tr_version
decl_stmt|;
comment|/* version number of trapper */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Flag bits  */
end_comment

begin_define
define|#
directive|define
name|TRAP_INUSE
value|0x1
end_define

begin_comment
comment|/* this trap is active */
end_comment

begin_define
define|#
directive|define
name|TRAP_NONPRIO
value|0x2
end_define

begin_comment
comment|/* this trap is non-priority */
end_comment

begin_define
define|#
directive|define
name|TRAP_CONFIGURED
value|0x4
end_define

begin_comment
comment|/* this trap was configured */
end_comment

begin_comment
comment|/*  * Types of things we may deal with  * shared between ntpq and library  */
end_comment

begin_define
define|#
directive|define
name|TYPE_SYS
value|1
end_define

begin_define
define|#
directive|define
name|TYPE_PEER
value|2
end_define

begin_define
define|#
directive|define
name|TYPE_CLOCK
value|3
end_define

end_unit

