begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_request.h - definitions for the ntpd remote query facility  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_comment
comment|/*  * A mode 7 packet is used exchanging data between an NTP server  * and a client for purposes other than time synchronization, e.g.  * monitoring, statistics gathering and configuration.  A mode 7  * packet has the following format:  *  *    0			  1		      2			  3  *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |R|M| VN  | Mode|A|  Sequence   | Implementation|   Req Code    |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |  Err  | Number of data items  |  MBZ  |   Size of data item   |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |								     |  *   |            Data (Minimum 0 octets, maximum 500 octets)        |  *   |								     |  *                            [...]  *   |								     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |               Encryption Keyid (when A bit set)               |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |								     |  *   |          Message Authentication Code (when A bit set)         |  *   |								     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *  * where the fields are (note that the client sends requests, the server  * responses):  *  * Response Bit:  This packet is a response (if clear, packet is a request).  *  * More Bit:	Set for all packets but the last in a response which  *		requires more than one packet.  *  * Version Number: 2 for current version  *  * Mode:	Always 7  *  * Authenticated bit: If set, this packet is authenticated.  *  * Sequence number: For a multipacket response, contains the sequence  *		number of this packet.  0 is the first in the sequence,  *		127 (or less) is the last.  The More Bit must be set in  *		all packets but the last.  *  * Implementation number: The number of the implementation this request code  *		is defined by.  An implementation number of zero is used  *		for requst codes/data formats which all implementations  *		agree on.  Implementation number 255 is reserved (for  *		extensions, in case we run out).  *  * Request code: An implementation-specific code which specifies the  *		operation to be (which has been) performed and/or the  *		format and semantics of the data included in the packet.  *  * Err:		Must be 0 for a request.  For a response, holds an error  *		code relating to the request.  If nonzero, the operation  *		requested wasn't performed.  *  *		0 - no error  *		1 - incompatable implementation number  *		2 - unimplemented request code  *		3 - format error (wrong data items, data size, packet size etc.)  *		4 - no data available (e.g. request for details on unknown peer)  *		5-6 I don't know  *		7 - authentication failure (i.e. permission denied)  *  * Number of data items: number of data items in packet.  0 to 500  *  * MBZ:		A reserved data field, must be zero in requests and responses.  *  * Size of data item: size of each data item in packet.  0 to 500  *  * Data:	Variable sized area containing request/response data.  For  *		requests and responses the size in octets must be greater  *		than or equal to the product of the number of data items  *		and the size of a data item.  For requests the data area  *		must be exactly 40 octets in length.  For responses the  *		data area may be any length between 0 and 500 octets  *		inclusive.  *  * Message Authentication Code: Same as NTP spec, in definition and function.  *		May optionally be included in requests which require  *		authentication, is never included in responses.  *  * The version number, mode and keyid have the same function and are  * in the same location as a standard NTP packet.  The request packet  * is the same size as a standard NTP packet to ease receive buffer  * management, and to allow the same encryption procedure to be used  * both on mode 7 and standard NTP packets.  The mac is included when  * it is required that a request be authenticated, the keyid should be  * zero in requests in which the mac is not included.  *  * The data format depends on the implementation number/request code pair  * and whether the packet is a request or a response.  The only requirement  * is that data items start in the octet immediately following the size  * word and that data items be concatenated without padding between (i.e.  * if the data area is larger than data_items*size, all padding is at  * the end).  Padding is ignored, other than for encryption purposes.  * Implementations using encryption might want to include a time stamp  * or other data in the request packet padding.  The key used for requests  * is implementation defined, but key 15 is suggested as a default.  */
end_comment

begin_comment
comment|/*  * A request packet.  These are almost a fixed length.  */
end_comment

begin_define
define|#
directive|define
name|MAXFILENAME
value|128
end_define

begin_comment
comment|/* max key file name length */
end_comment

begin_comment
comment|/* NOTE: also in ntp.h */
end_comment

begin_struct
struct|struct
name|req_pkt
block|{
name|u_char
name|rm_vn_mode
decl_stmt|;
comment|/* response, more, version, mode */
name|u_char
name|auth_seq
decl_stmt|;
comment|/* key, sequence number */
name|u_char
name|implementation
decl_stmt|;
comment|/* implementation number */
name|u_char
name|request
decl_stmt|;
comment|/* request number */
name|u_short
name|err_nitems
decl_stmt|;
comment|/* error code/number of data items */
name|u_short
name|mbz_itemsize
decl_stmt|;
comment|/* item size */
name|char
name|data
index|[
name|MAXFILENAME
operator|+
literal|16
index|]
decl_stmt|;
comment|/* data area [32 prev](144 byte max) */
name|l_fp
name|tstamp
decl_stmt|;
comment|/* time stamp, for authentication */
name|keyid_t
name|keyid
decl_stmt|;
comment|/* encryption key */
name|char
name|mac
index|[
name|MAX_MAC_LEN
operator|-
sizeof|sizeof
argument_list|(
name|u_int32
argument_list|)
index|]
decl_stmt|;
comment|/* (optional) 8 byte auth code */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Input packet lengths.  One with the mac, one without.  */
end_comment

begin_define
define|#
directive|define
name|REQ_LEN_MAC
value|(sizeof(struct req_pkt))
end_define

begin_define
define|#
directive|define
name|REQ_LEN_NOMAC
value|(sizeof(struct req_pkt) - MAX_MAC_LEN)
end_define

begin_comment
comment|/*  * A response packet.  The length here is variable, this is a  * maximally sized one.  Note that this implementation doesn't  * authenticate responses.  */
end_comment

begin_define
define|#
directive|define
name|RESP_HEADER_SIZE
value|(8)
end_define

begin_define
define|#
directive|define
name|RESP_DATA_SIZE
value|(500)
end_define

begin_struct
struct|struct
name|resp_pkt
block|{
name|u_char
name|rm_vn_mode
decl_stmt|;
comment|/* response, more, version, mode */
name|u_char
name|auth_seq
decl_stmt|;
comment|/* key, sequence number */
name|u_char
name|implementation
decl_stmt|;
comment|/* implementation number */
name|u_char
name|request
decl_stmt|;
comment|/* request number */
name|u_short
name|err_nitems
decl_stmt|;
comment|/* error code/number of data items */
name|u_short
name|mbz_itemsize
decl_stmt|;
comment|/* item size */
name|char
name|data
index|[
name|RESP_DATA_SIZE
index|]
decl_stmt|;
comment|/* data area */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Information error codes  */
end_comment

begin_define
define|#
directive|define
name|INFO_OKAY
value|0
end_define

begin_define
define|#
directive|define
name|INFO_ERR_IMPL
value|1
end_define

begin_comment
comment|/* incompatable implementation */
end_comment

begin_define
define|#
directive|define
name|INFO_ERR_REQ
value|2
end_define

begin_comment
comment|/* unknown request code */
end_comment

begin_define
define|#
directive|define
name|INFO_ERR_FMT
value|3
end_define

begin_comment
comment|/* format error */
end_comment

begin_define
define|#
directive|define
name|INFO_ERR_NODATA
value|4
end_define

begin_comment
comment|/* no data for this request */
end_comment

begin_define
define|#
directive|define
name|INFO_ERR_AUTH
value|7
end_define

begin_comment
comment|/* authentication failure */
end_comment

begin_comment
comment|/*  * Maximum sequence number.  */
end_comment

begin_define
define|#
directive|define
name|MAXSEQ
value|127
end_define

begin_comment
comment|/*  * Bit setting macros for multifield items.  */
end_comment

begin_define
define|#
directive|define
name|RESP_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|MORE_BIT
value|0x40
end_define

begin_define
define|#
directive|define
name|ISRESPONSE
parameter_list|(
name|rm_vn_mode
parameter_list|)
value|(((rm_vn_mode)&RESP_BIT)!=0)
end_define

begin_define
define|#
directive|define
name|ISMORE
parameter_list|(
name|rm_vn_mode
parameter_list|)
value|(((rm_vn_mode)&MORE_BIT)!=0)
end_define

begin_define
define|#
directive|define
name|INFO_VERSION
parameter_list|(
name|rm_vn_mode
parameter_list|)
value|((u_char)(((rm_vn_mode)>>3)&0x7))
end_define

begin_define
define|#
directive|define
name|INFO_MODE
parameter_list|(
name|rm_vn_mode
parameter_list|)
value|((rm_vn_mode)&0x7)
end_define

begin_define
define|#
directive|define
name|RM_VN_MODE
parameter_list|(
name|resp
parameter_list|,
name|more
parameter_list|,
name|version
parameter_list|)
define|\
value|((u_char)(((resp)?RESP_BIT:0)\ 				|((more)?MORE_BIT:0)\ 				|((version?version:(NTP_OLDVERSION+1))<<3)\ 				|(MODE_PRIVATE)))
end_define

begin_define
define|#
directive|define
name|INFO_IS_AUTH
parameter_list|(
name|auth_seq
parameter_list|)
value|(((auth_seq)& 0x80) != 0)
end_define

begin_define
define|#
directive|define
name|INFO_SEQ
parameter_list|(
name|auth_seq
parameter_list|)
value|((auth_seq)&0x7f)
end_define

begin_define
define|#
directive|define
name|AUTH_SEQ
parameter_list|(
name|auth
parameter_list|,
name|seq
parameter_list|)
value|((u_char)((((auth)!=0)?0x80:0)|((seq)&0x7f)))
end_define

begin_define
define|#
directive|define
name|INFO_ERR
parameter_list|(
name|err_nitems
parameter_list|)
value|((u_short)((ntohs(err_nitems)>>12)&0xf))
end_define

begin_define
define|#
directive|define
name|INFO_NITEMS
parameter_list|(
name|err_nitems
parameter_list|)
value|((u_short)(ntohs(err_nitems)&0xfff))
end_define

begin_define
define|#
directive|define
name|ERR_NITEMS
parameter_list|(
name|err
parameter_list|,
name|nitems
parameter_list|)
value|(htons((u_short)((((u_short)(err)<<12)&0xf000)\ 				|((u_short)(nitems)&0xfff))))
end_define

begin_define
define|#
directive|define
name|INFO_MBZ
parameter_list|(
name|mbz_itemsize
parameter_list|)
value|((ntohs(mbz_itemsize)>>12)&0xf)
end_define

begin_define
define|#
directive|define
name|INFO_ITEMSIZE
parameter_list|(
name|mbz_itemsize
parameter_list|)
value|(ntohs(mbz_itemsize)&0xfff)
end_define

begin_define
define|#
directive|define
name|MBZ_ITEMSIZE
parameter_list|(
name|itemsize
parameter_list|)
value|(htons((u_short)(itemsize)))
end_define

begin_comment
comment|/*  * Implementation numbers.  One for universal use and one for ntpd.  */
end_comment

begin_define
define|#
directive|define
name|IMPL_UNIV
value|0
end_define

begin_define
define|#
directive|define
name|IMPL_XNTPD
value|2
end_define

begin_comment
comment|/*  * Some limits related to authentication.  Frames which are  * authenticated must include a time stamp which differs from  * the receive time stamp by no more than 10 seconds.  */
end_comment

begin_define
define|#
directive|define
name|INFO_TS_MAXSKEW
value|10.
end_define

begin_comment
comment|/*  * Universal request codes go here.  There aren't any.  */
end_comment

begin_comment
comment|/*  * NTPD request codes go here.  */
end_comment

begin_define
define|#
directive|define
name|REQ_PEER_LIST
value|0
end_define

begin_comment
comment|/* return list of peers */
end_comment

begin_define
define|#
directive|define
name|REQ_PEER_LIST_SUM
value|1
end_define

begin_comment
comment|/* return summary info for all peers */
end_comment

begin_define
define|#
directive|define
name|REQ_PEER_INFO
value|2
end_define

begin_comment
comment|/* get standard information on peer */
end_comment

begin_define
define|#
directive|define
name|REQ_PEER_STATS
value|3
end_define

begin_comment
comment|/* get statistics for peer */
end_comment

begin_define
define|#
directive|define
name|REQ_SYS_INFO
value|4
end_define

begin_comment
comment|/* get system information */
end_comment

begin_define
define|#
directive|define
name|REQ_SYS_STATS
value|5
end_define

begin_comment
comment|/* get system stats */
end_comment

begin_define
define|#
directive|define
name|REQ_IO_STATS
value|6
end_define

begin_comment
comment|/* get I/O stats */
end_comment

begin_define
define|#
directive|define
name|REQ_MEM_STATS
value|7
end_define

begin_comment
comment|/* stats related to peer list maint */
end_comment

begin_define
define|#
directive|define
name|REQ_LOOP_INFO
value|8
end_define

begin_comment
comment|/* info from the loop filter */
end_comment

begin_define
define|#
directive|define
name|REQ_TIMER_STATS
value|9
end_define

begin_comment
comment|/* get timer stats */
end_comment

begin_define
define|#
directive|define
name|REQ_CONFIG
value|10
end_define

begin_comment
comment|/* configure a new peer */
end_comment

begin_define
define|#
directive|define
name|REQ_UNCONFIG
value|11
end_define

begin_comment
comment|/* unconfigure an existing peer */
end_comment

begin_define
define|#
directive|define
name|REQ_SET_SYS_FLAG
value|12
end_define

begin_comment
comment|/* set system flags */
end_comment

begin_define
define|#
directive|define
name|REQ_CLR_SYS_FLAG
value|13
end_define

begin_comment
comment|/* clear system flags */
end_comment

begin_define
define|#
directive|define
name|REQ_MONITOR
value|14
end_define

begin_comment
comment|/* (not used) */
end_comment

begin_define
define|#
directive|define
name|REQ_NOMONITOR
value|15
end_define

begin_comment
comment|/* (not used) */
end_comment

begin_define
define|#
directive|define
name|REQ_GET_RESTRICT
value|16
end_define

begin_comment
comment|/* return restrict list */
end_comment

begin_define
define|#
directive|define
name|REQ_RESADDFLAGS
value|17
end_define

begin_comment
comment|/* add flags to restrict list */
end_comment

begin_define
define|#
directive|define
name|REQ_RESSUBFLAGS
value|18
end_define

begin_comment
comment|/* remove flags from restrict list */
end_comment

begin_define
define|#
directive|define
name|REQ_UNRESTRICT
value|19
end_define

begin_comment
comment|/* remove entry from restrict list */
end_comment

begin_define
define|#
directive|define
name|REQ_MON_GETLIST
value|20
end_define

begin_comment
comment|/* return data collected by monitor */
end_comment

begin_define
define|#
directive|define
name|REQ_RESET_STATS
value|21
end_define

begin_comment
comment|/* reset stat counters */
end_comment

begin_define
define|#
directive|define
name|REQ_RESET_PEER
value|22
end_define

begin_comment
comment|/* reset peer stat counters */
end_comment

begin_define
define|#
directive|define
name|REQ_REREAD_KEYS
value|23
end_define

begin_comment
comment|/* reread the encryption key file */
end_comment

begin_define
define|#
directive|define
name|REQ_DO_DIRTY_HACK
value|24
end_define

begin_comment
comment|/* (not used) */
end_comment

begin_define
define|#
directive|define
name|REQ_DONT_DIRTY_HACK
value|25
end_define

begin_comment
comment|/* (not used) */
end_comment

begin_define
define|#
directive|define
name|REQ_TRUSTKEY
value|26
end_define

begin_comment
comment|/* add a trusted key */
end_comment

begin_define
define|#
directive|define
name|REQ_UNTRUSTKEY
value|27
end_define

begin_comment
comment|/* remove a trusted key */
end_comment

begin_define
define|#
directive|define
name|REQ_AUTHINFO
value|28
end_define

begin_comment
comment|/* return authentication info */
end_comment

begin_define
define|#
directive|define
name|REQ_TRAPS
value|29
end_define

begin_comment
comment|/* return currently set traps */
end_comment

begin_define
define|#
directive|define
name|REQ_ADD_TRAP
value|30
end_define

begin_comment
comment|/* add a trap */
end_comment

begin_define
define|#
directive|define
name|REQ_CLR_TRAP
value|31
end_define

begin_comment
comment|/* clear a trap */
end_comment

begin_define
define|#
directive|define
name|REQ_REQUEST_KEY
value|32
end_define

begin_comment
comment|/* define a new request keyid */
end_comment

begin_define
define|#
directive|define
name|REQ_CONTROL_KEY
value|33
end_define

begin_comment
comment|/* define a new control keyid */
end_comment

begin_define
define|#
directive|define
name|REQ_GET_CTLSTATS
value|34
end_define

begin_comment
comment|/* get stats from the control module */
end_comment

begin_define
define|#
directive|define
name|REQ_GET_LEAPINFO
value|35
end_define

begin_comment
comment|/* (not used) */
end_comment

begin_define
define|#
directive|define
name|REQ_GET_CLOCKINFO
value|36
end_define

begin_comment
comment|/* get clock information */
end_comment

begin_define
define|#
directive|define
name|REQ_SET_CLKFUDGE
value|37
end_define

begin_comment
comment|/* set clock fudge factors */
end_comment

begin_define
define|#
directive|define
name|REQ_GET_KERNEL
value|38
end_define

begin_comment
comment|/* get kernel pll/pps information */
end_comment

begin_define
define|#
directive|define
name|REQ_GET_CLKBUGINFO
value|39
end_define

begin_comment
comment|/* get clock debugging info */
end_comment

begin_define
define|#
directive|define
name|REQ_SET_PRECISION
value|41
end_define

begin_comment
comment|/* (not used) */
end_comment

begin_define
define|#
directive|define
name|REQ_MON_GETLIST_1
value|42
end_define

begin_comment
comment|/* return collected v1 monitor data */
end_comment

begin_define
define|#
directive|define
name|REQ_HOSTNAME_ASSOCID
value|43
end_define

begin_comment
comment|/* Here is a hostname + assoc_id */
end_comment

begin_comment
comment|/*  * Flags in the peer information returns  */
end_comment

begin_define
define|#
directive|define
name|INFO_FLAG_CONFIG
value|0x1
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_SYSPEER
value|0x2
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_BURST
value|0x4
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_REFCLOCK
value|0x8
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_PREFER
value|0x10
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_AUTHENABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_SEL_CANDIDATE
value|0x40
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_SHORTLIST
value|0x80
end_define

begin_comment
comment|/*  * Flags in the system information returns  */
end_comment

begin_define
define|#
directive|define
name|INFO_FLAG_BCLIENT
value|0x1
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_AUTHENTICATE
value|0x2
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_NTP
value|0x4
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_KERNEL
value|0x8
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_MONITOR
value|0x40
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_FILEGEN
value|0x80
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_PLL_SYNC
value|0x10
end_define

begin_define
define|#
directive|define
name|INFO_FLAG_PPS_SYNC
value|0x20
end_define

begin_comment
comment|/*  * Peer list structure.  Used to return raw lists of peers.  It goes  * without saying that everything returned is in network byte order.  * Well, it *would* have gone without saying, but somebody said it.  */
end_comment

begin_struct
struct|struct
name|info_peer_list
block|{
name|u_int32
name|address
decl_stmt|;
comment|/* address of peer */
name|u_short
name|port
decl_stmt|;
comment|/* port number of peer */
name|u_char
name|hmode
decl_stmt|;
comment|/* mode for this peer */
name|u_char
name|flags
decl_stmt|;
comment|/* flags (from above) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Peer summary structure.  Sort of the info that ntpdc returns by default.  */
end_comment

begin_struct
struct|struct
name|info_peer_summary
block|{
name|u_int32
name|dstadr
decl_stmt|;
comment|/* local address (zero for undetermined) */
name|u_int32
name|srcadr
decl_stmt|;
comment|/* source address */
name|u_short
name|srcport
decl_stmt|;
comment|/* source port */
name|u_char
name|stratum
decl_stmt|;
comment|/* stratum of peer */
name|s_char
name|hpoll
decl_stmt|;
comment|/* host polling interval */
name|s_char
name|ppoll
decl_stmt|;
comment|/* peer polling interval */
name|u_char
name|reach
decl_stmt|;
comment|/* reachability register */
name|u_char
name|flags
decl_stmt|;
comment|/* flags, from above */
name|u_char
name|hmode
decl_stmt|;
comment|/* peer mode */
name|s_fp
name|delay
decl_stmt|;
comment|/* peer.estdelay */
name|l_fp
name|offset
decl_stmt|;
comment|/* peer.estoffset */
name|u_fp
name|dispersion
decl_stmt|;
comment|/* peer.estdisp */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Peer information structure.  */
end_comment

begin_struct
struct|struct
name|info_peer
block|{
name|u_int32
name|dstadr
decl_stmt|;
comment|/* local address */
name|u_int32
name|srcadr
decl_stmt|;
comment|/* remote address */
name|u_short
name|srcport
decl_stmt|;
comment|/* remote port */
name|u_char
name|flags
decl_stmt|;
comment|/* peer flags */
name|u_char
name|leap
decl_stmt|;
comment|/* peer.leap */
name|u_char
name|hmode
decl_stmt|;
comment|/* peer.hmode */
name|u_char
name|pmode
decl_stmt|;
comment|/* peer.pmode */
name|u_char
name|stratum
decl_stmt|;
comment|/* peer.stratum */
name|u_char
name|ppoll
decl_stmt|;
comment|/* peer.ppoll */
name|u_char
name|hpoll
decl_stmt|;
comment|/* peer.hpoll */
name|s_char
name|precision
decl_stmt|;
comment|/* peer.precision */
name|u_char
name|version
decl_stmt|;
comment|/* peer.version */
name|u_char
name|unused8
decl_stmt|;
name|u_char
name|reach
decl_stmt|;
comment|/* peer.reach */
name|u_char
name|unreach
decl_stmt|;
comment|/* peer.unreach */
name|u_char
name|flash
decl_stmt|;
comment|/* old peer.flash */
name|u_char
name|ttl
decl_stmt|;
comment|/* peer.ttl */
name|u_short
name|flash2
decl_stmt|;
comment|/* new peer.flash */
name|associd_t
name|associd
decl_stmt|;
comment|/* association ID */
name|keyid_t
name|keyid
decl_stmt|;
comment|/* peer.keyid */
name|u_int32
name|pkeyid
decl_stmt|;
comment|/* unused */
name|u_int32
name|refid
decl_stmt|;
comment|/* peer.refid */
name|u_int32
name|timer
decl_stmt|;
comment|/* peer.timer */
name|s_fp
name|rootdelay
decl_stmt|;
comment|/* peer.distance */
name|u_fp
name|rootdispersion
decl_stmt|;
comment|/* peer.dispersion */
name|l_fp
name|reftime
decl_stmt|;
comment|/* peer.reftime */
name|l_fp
name|org
decl_stmt|;
comment|/* peer.org */
name|l_fp
name|rec
decl_stmt|;
comment|/* peer.rec */
name|l_fp
name|xmt
decl_stmt|;
comment|/* peer.xmt */
name|s_fp
name|filtdelay
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* delay shift register */
name|l_fp
name|filtoffset
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* offset shift register */
name|u_char
name|order
index|[
name|NTP_SHIFT
index|]
decl_stmt|;
comment|/* order of peers from last filter */
name|s_fp
name|delay
decl_stmt|;
comment|/* peer.estdelay */
name|u_fp
name|dispersion
decl_stmt|;
comment|/* peer.estdisp */
name|l_fp
name|offset
decl_stmt|;
comment|/* peer.estoffset */
name|u_fp
name|selectdisp
decl_stmt|;
comment|/* peer select dispersion */
name|int32
name|unused1
decl_stmt|;
comment|/* (obsolete) */
name|int32
name|unused2
decl_stmt|;
name|int32
name|unused3
decl_stmt|;
name|int32
name|unused4
decl_stmt|;
name|int32
name|unused5
decl_stmt|;
name|int32
name|unused6
decl_stmt|;
name|int32
name|unused7
decl_stmt|;
name|s_fp
name|estbdelay
decl_stmt|;
comment|/* broadcast offset */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Peer statistics structure  */
end_comment

begin_struct
struct|struct
name|info_peer_stats
block|{
name|u_int32
name|dstadr
decl_stmt|;
comment|/* local address */
name|u_int32
name|srcadr
decl_stmt|;
comment|/* remote address */
name|u_short
name|srcport
decl_stmt|;
comment|/* remote port */
name|u_short
name|flags
decl_stmt|;
comment|/* peer flags */
name|u_int32
name|timereset
decl_stmt|;
comment|/* time counters were reset */
name|u_int32
name|timereceived
decl_stmt|;
comment|/* time since a packet received */
name|u_int32
name|timetosend
decl_stmt|;
comment|/* time until a packet sent */
name|u_int32
name|timereachable
decl_stmt|;
comment|/* time peer has been reachable */
name|u_int32
name|sent
decl_stmt|;
comment|/* number sent */
name|u_int32
name|unused1
decl_stmt|;
comment|/* (unused) */
name|u_int32
name|processed
decl_stmt|;
comment|/* number processed */
name|u_int32
name|unused2
decl_stmt|;
comment|/* (unused) */
name|u_int32
name|badauth
decl_stmt|;
comment|/* bad authentication */
name|u_int32
name|bogusorg
decl_stmt|;
comment|/* bogus origin */
name|u_int32
name|oldpkt
decl_stmt|;
comment|/* duplicate */
name|u_int32
name|unused3
decl_stmt|;
comment|/* (unused) */
name|u_int32
name|unused4
decl_stmt|;
comment|/* (unused) */
name|u_int32
name|seldisp
decl_stmt|;
comment|/* bad dispersion */
name|u_int32
name|selbroken
decl_stmt|;
comment|/* bad reference time */
name|u_int32
name|unused5
decl_stmt|;
comment|/* (unused) */
name|u_char
name|candidate
decl_stmt|;
comment|/* select order */
name|u_char
name|unused6
decl_stmt|;
comment|/* (unused) */
name|u_char
name|unused7
decl_stmt|;
comment|/* (unused) */
name|u_char
name|unused8
decl_stmt|;
comment|/* (unused) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Loop filter variables  */
end_comment

begin_struct
struct|struct
name|info_loop
block|{
name|l_fp
name|last_offset
decl_stmt|;
name|l_fp
name|drift_comp
decl_stmt|;
name|u_int32
name|compliance
decl_stmt|;
name|u_int32
name|watchdog_timer
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * System info.  Mostly the sys.* variables, plus a few unique to  * the implementation.  */
end_comment

begin_struct
struct|struct
name|info_sys
block|{
name|u_int32
name|peer
decl_stmt|;
comment|/* system peer address */
name|u_char
name|peer_mode
decl_stmt|;
comment|/* mode we are syncing to peer in */
name|u_char
name|leap
decl_stmt|;
comment|/* system leap bits */
name|u_char
name|stratum
decl_stmt|;
comment|/* our stratum */
name|s_char
name|precision
decl_stmt|;
comment|/* local clock precision */
name|s_fp
name|rootdelay
decl_stmt|;
comment|/* distance from sync source */
name|u_fp
name|rootdispersion
decl_stmt|;
comment|/* dispersion from sync source */
name|u_int32
name|refid
decl_stmt|;
comment|/* reference ID of sync source */
name|l_fp
name|reftime
decl_stmt|;
comment|/* system reference time */
name|u_int32
name|poll
decl_stmt|;
comment|/* system poll interval */
name|u_char
name|flags
decl_stmt|;
comment|/* system flags */
name|u_char
name|unused1
decl_stmt|;
comment|/* unused */
name|u_char
name|unused2
decl_stmt|;
comment|/* unused */
name|u_char
name|unused3
decl_stmt|;
comment|/* unused */
name|s_fp
name|bdelay
decl_stmt|;
comment|/* default broadcast offset */
name|s_fp
name|frequency
decl_stmt|;
comment|/* frequency residual (scaled ppm)  */
name|l_fp
name|authdelay
decl_stmt|;
comment|/* default authentication delay */
name|u_fp
name|stability
decl_stmt|;
comment|/* clock stability (scaled ppm) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * System stats.  These are collected in the protocol module  */
end_comment

begin_struct
struct|struct
name|info_sys_stats
block|{
name|u_int32
name|timeup
decl_stmt|;
comment|/* time we have been up and running */
name|u_int32
name|timereset
decl_stmt|;
comment|/* time since these were last cleared */
name|u_int32
name|badstratum
decl_stmt|;
comment|/* packets claiming an invalid stratum */
name|u_int32
name|oldversionpkt
decl_stmt|;
comment|/* old version packets received */
name|u_int32
name|newversionpkt
decl_stmt|;
comment|/* new version packets received */
name|u_int32
name|unknownversion
decl_stmt|;
comment|/* don't know version packets */
name|u_int32
name|badlength
decl_stmt|;
comment|/* packets with bad length */
name|u_int32
name|processed
decl_stmt|;
comment|/* packets processed */
name|u_int32
name|badauth
decl_stmt|;
comment|/* packets dropped because of authorization */
name|u_int32
name|wanderhold
decl_stmt|;
comment|/* (obsolete) */
name|u_int32
name|limitrejected
decl_stmt|;
comment|/* rejected because of client limitation */
block|}
struct|;
end_struct

begin_comment
comment|/*  * System stats - old version  */
end_comment

begin_struct
struct|struct
name|old_info_sys_stats
block|{
name|u_int32
name|timeup
decl_stmt|;
comment|/* time we have been up and running */
name|u_int32
name|timereset
decl_stmt|;
comment|/* time since these were last cleared */
name|u_int32
name|badstratum
decl_stmt|;
comment|/* packets claiming an invalid stratum */
name|u_int32
name|oldversionpkt
decl_stmt|;
comment|/* old version packets received */
name|u_int32
name|newversionpkt
decl_stmt|;
comment|/* new version packets received */
name|u_int32
name|unknownversion
decl_stmt|;
comment|/* don't know version packets */
name|u_int32
name|badlength
decl_stmt|;
comment|/* packets with bad length */
name|u_int32
name|processed
decl_stmt|;
comment|/* packets processed */
name|u_int32
name|badauth
decl_stmt|;
comment|/* packets dropped because of authorization */
name|u_int32
name|wanderhold
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Peer memory statistics.  Collected in the peer module.  */
end_comment

begin_struct
struct|struct
name|info_mem_stats
block|{
name|u_int32
name|timereset
decl_stmt|;
comment|/* time since reset */
name|u_short
name|totalpeermem
decl_stmt|;
name|u_short
name|freepeermem
decl_stmt|;
name|u_int32
name|findpeer_calls
decl_stmt|;
name|u_int32
name|allocations
decl_stmt|;
name|u_int32
name|demobilizations
decl_stmt|;
name|u_char
name|hashcount
index|[
name|HASH_SIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * I/O statistics.  Collected in the I/O module  */
end_comment

begin_struct
struct|struct
name|info_io_stats
block|{
name|u_int32
name|timereset
decl_stmt|;
comment|/* time since reset */
name|u_short
name|totalrecvbufs
decl_stmt|;
comment|/* total receive bufs */
name|u_short
name|freerecvbufs
decl_stmt|;
comment|/* free buffers */
name|u_short
name|fullrecvbufs
decl_stmt|;
comment|/* full buffers */
name|u_short
name|lowwater
decl_stmt|;
comment|/* number of times we've added buffers */
name|u_int32
name|dropped
decl_stmt|;
comment|/* dropped packets */
name|u_int32
name|ignored
decl_stmt|;
comment|/* ignored packets */
name|u_int32
name|received
decl_stmt|;
comment|/* received packets */
name|u_int32
name|sent
decl_stmt|;
comment|/* packets sent */
name|u_int32
name|notsent
decl_stmt|;
comment|/* packets not sent */
name|u_int32
name|interrupts
decl_stmt|;
comment|/* interrupts we've handled */
name|u_int32
name|int_received
decl_stmt|;
comment|/* received by interrupt handler */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Timer stats.  Guess where from.  */
end_comment

begin_struct
struct|struct
name|info_timer_stats
block|{
name|u_int32
name|timereset
decl_stmt|;
comment|/* time since reset */
name|u_int32
name|alarms
decl_stmt|;
comment|/* alarms we've handled */
name|u_int32
name|overflows
decl_stmt|;
comment|/* timer overflows */
name|u_int32
name|xmtcalls
decl_stmt|;
comment|/* calls to xmit */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for passing peer configuration information  */
end_comment

begin_struct
struct|struct
name|conf_peer
block|{
name|u_int32
name|peeraddr
decl_stmt|;
comment|/* address to poll */
name|u_char
name|hmode
decl_stmt|;
comment|/* mode, either broadcast, active or client */
name|u_char
name|version
decl_stmt|;
comment|/* version number to poll with */
name|u_char
name|minpoll
decl_stmt|;
comment|/* min host poll interval */
name|u_char
name|maxpoll
decl_stmt|;
comment|/* max host poll interval */
name|u_char
name|flags
decl_stmt|;
comment|/* flags for this request */
name|u_char
name|ttl
decl_stmt|;
comment|/* time to live (multicast) or refclock mode */
name|u_short
name|unused
decl_stmt|;
comment|/* unused */
name|keyid_t
name|keyid
decl_stmt|;
comment|/* key to use for this association */
name|char
name|keystr
index|[
name|MAXFILENAME
index|]
decl_stmt|;
comment|/* public key file name*/
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CONF_FLAG_AUTHENABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|CONF_FLAG_PREFER
value|0x02
end_define

begin_define
define|#
directive|define
name|CONF_FLAG_BURST
value|0x04
end_define

begin_define
define|#
directive|define
name|CONF_FLAG_IBURST
value|0x08
end_define

begin_define
define|#
directive|define
name|CONF_FLAG_NOSELECT
value|0x10
end_define

begin_define
define|#
directive|define
name|CONF_FLAG_SKEY
value|0x20
end_define

begin_comment
comment|/*  * Structure for passing peer deletion information.  Currently  * we only pass the address and delete all configured peers with  * this addess.  */
end_comment

begin_struct
struct|struct
name|conf_unpeer
block|{
name|u_int32
name|peeraddr
decl_stmt|;
comment|/* address of peer */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure for carrying system flags.  */
end_comment

begin_struct
struct|struct
name|conf_sys_flags
block|{
name|u_int32
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * System flags we can set/clear  */
end_comment

begin_define
define|#
directive|define
name|SYS_FLAG_BCLIENT
value|0x1
end_define

begin_define
define|#
directive|define
name|SYS_FLAG_PPS
value|0x2
end_define

begin_define
define|#
directive|define
name|SYS_FLAG_NTP
value|0x4
end_define

begin_define
define|#
directive|define
name|SYS_FLAG_KERNEL
value|0x8
end_define

begin_define
define|#
directive|define
name|SYS_FLAG_MONITOR
value|0x10
end_define

begin_define
define|#
directive|define
name|SYS_FLAG_FILEGEN
value|0x20
end_define

begin_comment
comment|/*  * Structure used for returning restrict entries  */
end_comment

begin_struct
struct|struct
name|info_restrict
block|{
name|u_int32
name|addr
decl_stmt|;
comment|/* match address */
name|u_int32
name|mask
decl_stmt|;
comment|/* match mask */
name|u_int32
name|count
decl_stmt|;
comment|/* number of packets matched */
name|u_short
name|flags
decl_stmt|;
comment|/* restrict flags */
name|u_short
name|mflags
decl_stmt|;
comment|/* match flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used for specifying restrict entries  */
end_comment

begin_struct
struct|struct
name|conf_restrict
block|{
name|u_int32
name|addr
decl_stmt|;
comment|/* match address */
name|u_int32
name|mask
decl_stmt|;
comment|/* match mask */
name|u_short
name|flags
decl_stmt|;
comment|/* restrict flags */
name|u_short
name|mflags
decl_stmt|;
comment|/* match flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used for returning monitor data  */
end_comment

begin_struct
struct|struct
name|info_monitor_1
block|{
name|u_int32
name|lasttime
decl_stmt|;
comment|/* last packet from this host */
name|u_int32
name|firsttime
decl_stmt|;
comment|/* first time we received a packet */
name|u_int32
name|lastdrop
decl_stmt|;
comment|/* last time we rejected a packet due to client limitation policy */
name|u_int32
name|count
decl_stmt|;
comment|/* count of packets received */
name|u_int32
name|addr
decl_stmt|;
comment|/* host address */
name|u_int32
name|daddr
decl_stmt|;
comment|/* destination host address */
name|u_int32
name|flags
decl_stmt|;
comment|/* flags about destination */
name|u_short
name|port
decl_stmt|;
comment|/* port number of last reception */
name|u_char
name|mode
decl_stmt|;
comment|/* mode of last packet */
name|u_char
name|version
decl_stmt|;
comment|/* version number of last packet */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used for returning monitor data  */
end_comment

begin_struct
struct|struct
name|info_monitor
block|{
name|u_int32
name|lasttime
decl_stmt|;
comment|/* last packet from this host */
name|u_int32
name|firsttime
decl_stmt|;
comment|/* first time we received a packet */
name|u_int32
name|lastdrop
decl_stmt|;
comment|/* last time we rejected a packet due to client limitation policy */
name|u_int32
name|count
decl_stmt|;
comment|/* count of packets received */
name|u_int32
name|addr
decl_stmt|;
comment|/* host address */
name|u_short
name|port
decl_stmt|;
comment|/* port number of last reception */
name|u_char
name|mode
decl_stmt|;
comment|/* mode of last packet */
name|u_char
name|version
decl_stmt|;
comment|/* version number of last packet */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used for returning monitor data (old format  */
end_comment

begin_struct
struct|struct
name|old_info_monitor
block|{
name|u_int32
name|lasttime
decl_stmt|;
comment|/* last packet from this host */
name|u_int32
name|firsttime
decl_stmt|;
comment|/* first time we received a packet */
name|u_int32
name|count
decl_stmt|;
comment|/* count of packets received */
name|u_int32
name|addr
decl_stmt|;
comment|/* host address */
name|u_short
name|port
decl_stmt|;
comment|/* port number of last reception */
name|u_char
name|mode
decl_stmt|;
comment|/* mode of last packet */
name|u_char
name|version
decl_stmt|;
comment|/* version number of last packet */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used for passing indication of flags to clear  */
end_comment

begin_struct
struct|struct
name|reset_flags
block|{
name|u_int32
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RESET_FLAG_ALLPEERS
value|0x01
end_define

begin_define
define|#
directive|define
name|RESET_FLAG_IO
value|0x02
end_define

begin_define
define|#
directive|define
name|RESET_FLAG_SYS
value|0x04
end_define

begin_define
define|#
directive|define
name|RESET_FLAG_MEM
value|0x08
end_define

begin_define
define|#
directive|define
name|RESET_FLAG_TIMER
value|0x10
end_define

begin_define
define|#
directive|define
name|RESET_FLAG_AUTH
value|0x20
end_define

begin_define
define|#
directive|define
name|RESET_FLAG_CTL
value|0x40
end_define

begin_define
define|#
directive|define
name|RESET_ALLFLAGS
define|\
value|(RESET_FLAG_ALLPEERS|RESET_FLAG_IO|RESET_FLAG_SYS \ 	|RESET_FLAG_MEM|RESET_FLAG_TIMER|RESET_FLAG_AUTH|RESET_FLAG_CTL)
end_define

begin_comment
comment|/*  * Structure used to return information concerning the authentication  * module.  */
end_comment

begin_struct
struct|struct
name|info_auth
block|{
name|u_int32
name|timereset
decl_stmt|;
comment|/* time counters were reset */
name|u_int32
name|numkeys
decl_stmt|;
comment|/* number of keys we know */
name|u_int32
name|numfreekeys
decl_stmt|;
comment|/* number of free keys */
name|u_int32
name|keylookups
decl_stmt|;
comment|/* calls to authhavekey() */
name|u_int32
name|keynotfound
decl_stmt|;
comment|/* requested key unknown */
name|u_int32
name|encryptions
decl_stmt|;
comment|/* number of encryptions */
name|u_int32
name|decryptions
decl_stmt|;
comment|/* number of decryptions */
name|u_int32
name|expired
decl_stmt|;
comment|/* number of expired keys */
name|u_int32
name|keyuncached
decl_stmt|;
comment|/* calls to encrypt/decrypt with uncached key */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to pass trap information to the client  */
end_comment

begin_struct
struct|struct
name|info_trap
block|{
name|u_int32
name|local_address
decl_stmt|;
comment|/* local interface address */
name|u_int32
name|trap_address
decl_stmt|;
comment|/* remote client's address */
name|u_short
name|trap_port
decl_stmt|;
comment|/* remote port number */
name|u_short
name|sequence
decl_stmt|;
comment|/* sequence number */
name|u_int32
name|settime
decl_stmt|;
comment|/* time trap last set */
name|u_int32
name|origtime
decl_stmt|;
comment|/* time trap originally set */
name|u_int32
name|resets
decl_stmt|;
comment|/* number of resets on this trap */
name|u_int32
name|flags
decl_stmt|;
comment|/* trap flags, as defined in ntp_control.h */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to pass add/clear trap information to the client  */
end_comment

begin_struct
struct|struct
name|conf_trap
block|{
name|u_int32
name|local_address
decl_stmt|;
comment|/* local interface address */
name|u_int32
name|trap_address
decl_stmt|;
comment|/* remote client's address */
name|u_short
name|trap_port
decl_stmt|;
comment|/* remote client's port */
name|u_short
name|unused
decl_stmt|;
comment|/* (unused) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to return statistics from the control module  */
end_comment

begin_struct
struct|struct
name|info_control
block|{
name|u_int32
name|ctltimereset
decl_stmt|;
name|u_int32
name|numctlreq
decl_stmt|;
comment|/* number of requests we've received */
name|u_int32
name|numctlbadpkts
decl_stmt|;
comment|/* number of bad control packets */
name|u_int32
name|numctlresponses
decl_stmt|;
comment|/* # resp packets sent */
name|u_int32
name|numctlfrags
decl_stmt|;
comment|/* # of fragments sent */
name|u_int32
name|numctlerrors
decl_stmt|;
comment|/* number of error responses sent */
name|u_int32
name|numctltooshort
decl_stmt|;
comment|/* number of too short input packets */
name|u_int32
name|numctlinputresp
decl_stmt|;
comment|/* number of responses on input */
name|u_int32
name|numctlinputfrag
decl_stmt|;
comment|/* number of fragments on input */
name|u_int32
name|numctlinputerr
decl_stmt|;
comment|/* # input pkts with err bit set */
name|u_int32
name|numctlbadoffset
decl_stmt|;
comment|/* # input pkts with nonzero offset */
name|u_int32
name|numctlbadversion
decl_stmt|;
comment|/* # input pkts with unknown version */
name|u_int32
name|numctldatatooshort
decl_stmt|;
comment|/* data too short for count */
name|u_int32
name|numctlbadop
decl_stmt|;
comment|/* bad op code found in packet */
name|u_int32
name|numasyncmsgs
decl_stmt|;
comment|/* # async messages we've sent */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used to return clock information  */
end_comment

begin_struct
struct|struct
name|info_clock
block|{
name|u_int32
name|clockadr
decl_stmt|;
name|u_char
name|type
decl_stmt|;
name|u_char
name|flags
decl_stmt|;
name|u_char
name|lastevent
decl_stmt|;
name|u_char
name|currentstatus
decl_stmt|;
name|u_int32
name|polls
decl_stmt|;
name|u_int32
name|noresponse
decl_stmt|;
name|u_int32
name|badformat
decl_stmt|;
name|u_int32
name|baddata
decl_stmt|;
name|u_int32
name|timestarted
decl_stmt|;
name|l_fp
name|fudgetime1
decl_stmt|;
name|l_fp
name|fudgetime2
decl_stmt|;
name|int32
name|fudgeval1
decl_stmt|;
name|int32
name|fudgeval2
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used for setting clock fudge factors  */
end_comment

begin_struct
struct|struct
name|conf_fudge
block|{
name|u_int32
name|clockadr
decl_stmt|;
name|u_int32
name|which
decl_stmt|;
name|l_fp
name|fudgetime
decl_stmt|;
name|int32
name|fudgeval_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FUDGE_TIME1
value|1
end_define

begin_define
define|#
directive|define
name|FUDGE_TIME2
value|2
end_define

begin_define
define|#
directive|define
name|FUDGE_VAL1
value|3
end_define

begin_define
define|#
directive|define
name|FUDGE_VAL2
value|4
end_define

begin_define
define|#
directive|define
name|FUDGE_FLAGS
value|5
end_define

begin_comment
comment|/*  * Structure used for returning clock debugging info  */
end_comment

begin_define
define|#
directive|define
name|NUMCBUGVALUES
value|16
end_define

begin_define
define|#
directive|define
name|NUMCBUGTIMES
value|32
end_define

begin_struct
struct|struct
name|info_clkbug
block|{
name|u_int32
name|clockadr
decl_stmt|;
name|u_char
name|nvalues
decl_stmt|;
name|u_char
name|ntimes
decl_stmt|;
name|u_short
name|svalues
decl_stmt|;
name|u_int32
name|stimes
decl_stmt|;
name|u_int32
name|values
index|[
name|NUMCBUGVALUES
index|]
decl_stmt|;
name|l_fp
name|times
index|[
name|NUMCBUGTIMES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure used for returning kernel pll/PPS information  */
end_comment

begin_struct
struct|struct
name|info_kernel
block|{
name|int32
name|offset
decl_stmt|;
name|int32
name|freq
decl_stmt|;
name|int32
name|maxerror
decl_stmt|;
name|int32
name|esterror
decl_stmt|;
name|u_short
name|status
decl_stmt|;
name|u_short
name|shift
decl_stmt|;
name|int32
name|constant
decl_stmt|;
name|int32
name|precision
decl_stmt|;
name|int32
name|tolerance
decl_stmt|;
comment|/*  * Variables used only if PPS signal discipline is implemented  */
name|int32
name|ppsfreq
decl_stmt|;
name|int32
name|jitter
decl_stmt|;
name|int32
name|stabil
decl_stmt|;
name|int32
name|jitcnt
decl_stmt|;
name|int32
name|calcnt
decl_stmt|;
name|int32
name|errcnt
decl_stmt|;
name|int32
name|stbcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Info returned with IP -> hostname lookup  */
end_comment

begin_comment
comment|/* 144 might need to become 32, matching data[] member of req_pkt */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXHOSTNAME
value|(32 - sizeof(u_int32) - sizeof(u_short))
end_define

begin_struct
struct|struct
name|info_dns_assoc
block|{
name|u_int32
name|peeraddr
decl_stmt|;
comment|/* peer address (HMS: being careful...) */
name|associd_t
name|associd
decl_stmt|;
comment|/* association ID */
name|char
name|hostname
index|[
name|NTP_MAXHOSTNAME
index|]
decl_stmt|;
comment|/* hostname */
block|}
struct|;
end_struct

end_unit

