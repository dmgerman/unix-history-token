begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: /f/osi/others/ntp/RCS/ntp.h,v 7.2 91/02/22 09:33:43 mrose Interim $ */
end_comment

begin_comment
comment|/*  *  $Log:	ntp.h,v $  * Revision 7.2  91/02/22  09:33:43  mrose  * Interim 6.8  *   * Revision 7.1  90/12/10  23:15:43  mrose  * isode/  *   * Revision 7.0  90/12/10  17:21:24  mrose  * *** empty log message ***  *   * Revision 1.4  90/08/14  10:13:51  jpo  * new protocol version  *   * Revision 1.3  90/02/13  14:23:52  jpo  * First beta released version  *   * Revision 1.2  89/12/19  08:32:34  jpo  * Updated for ISODE 6.0ish  *   * Revision 1.1  89/06/15  20:36:54  jpo  * Initial revision  *   *   */
end_comment

begin_include
include|#
directive|include
file|"ntp-config.h"
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/uio.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|NOSWAP
end_ifdef

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/udp.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_include
include|#
directive|include
file|"rosy.h"
end_include

begin_include
include|#
directive|include
file|"tsap.h"
end_include

begin_include
include|#
directive|include
file|"logger.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|FD_SET
end_ifndef

begin_define
define|#
directive|define
name|NFDBITS
value|32
end_define

begin_define
define|#
directive|define
name|FD_SETSIZE
value|32
end_define

begin_define
define|#
directive|define
name|FD_SET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS] |= (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_CLR
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]&= ~(1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ISSET
parameter_list|(
name|n
parameter_list|,
name|p
parameter_list|)
value|((p)->fds_bits[(n)/NFDBITS]& (1<< ((n) % NFDBITS)))
end_define

begin_define
define|#
directive|define
name|FD_ZERO
parameter_list|(
name|p
parameter_list|)
value|bzero((char *)(p), sizeof(*(p)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NBBY
end_ifndef

begin_define
define|#
directive|define
name|NBBY
value|8
end_define

begin_comment
comment|/* number of bits per byte */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|TRACE
parameter_list|(
name|level
parameter_list|,
name|args
parameter_list|)
value|if (debug>= level) \ 	SLOG (pgm_log, LLOG_DEBUG, NULLCP, args); \ 	else
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TRACE
parameter_list|(
name|level
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|Naddr
block|{
name|int
name|type
decl_stmt|;
union|union
block|{
name|struct
name|sockaddr_in
name|un_inet_ad
decl_stmt|;
name|struct
name|PSAPaddr
name|un_psap_ad
decl_stmt|;
block|}
name|un
union|;
define|#
directive|define
name|inet_ad
value|un.un_inet_ad
define|#
directive|define
name|psap_ad
value|un.un_psap_ad
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|Refid
block|{
name|char
name|rid_type
decl_stmt|;
define|#
directive|define
name|RID_STRING
value|1
define|#
directive|define
name|RID_INET
value|2
define|#
directive|define
name|RID_PSAP
value|3
union|union
block|{
name|char
name|un_rid_string
index|[
literal|5
index|]
decl_stmt|;
name|u_long
name|un_rid_inet
decl_stmt|;
name|struct
name|PSAPaddr
name|un_rid_psap
decl_stmt|;
block|}
name|un
union|;
define|#
directive|define
name|rid_string
value|un.un_rid_string
define|#
directive|define
name|rid_inet
value|un.un_rid_inet
define|#
directive|define
name|rid_psap
value|un.un_rid_psap
block|}
name|Refid
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAXNETIF
value|10
end_define

begin_struct
struct|struct
name|intf
block|{
name|int
name|fd
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|Naddr
name|addr
decl_stmt|;
name|struct
name|sockaddr_in
name|bcast
decl_stmt|;
name|struct
name|sockaddr_in
name|mask
decl_stmt|;
name|int
name|uses
decl_stmt|;
name|int
name|flags
decl_stmt|;
define|#
directive|define
name|INTF_VALID
value|01
define|#
directive|define
name|INTF_STATIC
value|02
define|#
directive|define
name|INTF_PENDING
value|04
define|#
directive|define
name|INTF_ACCEPTING
value|010
define|#
directive|define
name|INTF_SELECT
value|(INTF_ACCEPTING|INTF_PENDING|INTF_VALID)
name|int
name|if_flags
decl_stmt|;
name|char
modifier|*
name|vec
index|[
literal|4
index|]
decl_stmt|;
name|int
name|vecp
decl_stmt|;
name|int
name|inum
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|intf
modifier|*
name|addrs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nintf
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|intf
modifier|*
name|getintf
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ACT_ERROR
value|1
end_define

begin_define
define|#
directive|define
name|ACT_RECV
value|2
end_define

begin_define
define|#
directive|define
name|ACT_XMIT
value|3
end_define

begin_define
define|#
directive|define
name|ACT_PKT
value|4
end_define

begin_decl_stmt
specifier|extern
name|char
name|actions
index|[
literal|5
index|]
index|[
literal|5
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  Definitions for the masses  */
end_comment

begin_define
define|#
directive|define
name|JAN_1970
value|2208988800
end_define

begin_comment
comment|/* 1970 - 1900 in seconds */
end_comment

begin_comment
comment|/*  *  Daemon specific (ntpd.c)  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_MASK
value|0xff
end_define

begin_comment
comment|/* number of intervals to wait */
end_comment

begin_struct
struct|struct
name|list
block|{
name|struct
name|ntp_peer
modifier|*
name|head
decl_stmt|;
name|struct
name|ntp_peer
modifier|*
name|tail
decl_stmt|;
name|int
name|members
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STRMCMP
parameter_list|(
name|a
parameter_list|,
name|cond
parameter_list|,
name|b
parameter_list|)
define|\
value|(((a) == UNSPECIFIED ? NTP_INFIN+1 : a) cond \ 	 ((b) == UNSPECIFIED ? NTP_INFIN+1 : (b)))
end_define

begin_comment
comment|/*  *  Definitions outlined in the NTP spec  */
end_comment

begin_define
define|#
directive|define
name|NTP_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|NTP_PORT
value|123
end_define

begin_comment
comment|/* for ref only (see /etc/services) */
end_comment

begin_define
define|#
directive|define
name|NTP_INFIN
value|15
end_define

begin_define
define|#
directive|define
name|NTP_MAXAGE
value|86400
end_define

begin_define
define|#
directive|define
name|NTP_MAXSKW
value|0.01
end_define

begin_comment
comment|/* seconds */
end_comment

begin_define
define|#
directive|define
name|NTP_MINDIST
value|0.02
end_define

begin_comment
comment|/* seconds */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REFCLOCK
end_ifdef

begin_define
define|#
directive|define
name|NTP_REFMAXSKW
value|0.001
end_define

begin_comment
comment|/* seconds (for REFCLOCKs) */
end_comment

begin_define
define|#
directive|define
name|NTP_REFMINDIST
value|0.001
end_define

begin_comment
comment|/* seconds (for REFCLOCKs) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|NTP_MINPOLL
value|6
end_define

begin_comment
comment|/* (64) seconds between messages */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXPOLL
value|10
end_define

begin_comment
comment|/* (1024) secs to poll */
end_comment

begin_define
define|#
directive|define
name|NTP_WINDOW
value|8
end_define

begin_comment
comment|/* size of shift register */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXWGT
value|8
end_define

begin_comment
comment|/* maximum allowable dispersion */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXLIST
value|5
end_define

begin_comment
comment|/* max size of selection list */
end_comment

begin_define
define|#
directive|define
name|NTP_MAXSTRA
value|2
end_define

begin_comment
comment|/* max number of strata in selection list */
end_comment

begin_define
define|#
directive|define
name|X_NTP_CANDIDATES
value|64
end_define

begin_comment
comment|/* number of peers to consider when doing 				   clock selection */
end_comment

begin_define
define|#
directive|define
name|NTP_SELECT
value|0.75
end_define

begin_comment
comment|/* weight used to compute dispersion */
end_comment

begin_define
define|#
directive|define
name|PEER_MAXDISP
value|64.0
end_define

begin_comment
comment|/* Maximum dispersion  */
end_comment

begin_define
define|#
directive|define
name|PEER_THRESHOLD
value|0.5
end_define

begin_comment
comment|/* dispersion threshold */
end_comment

begin_define
define|#
directive|define
name|PEER_FILTER
value|0.5
end_define

begin_comment
comment|/* filter weight */
end_comment

begin_define
define|#
directive|define
name|BACKOFF_COUNT
value|3
end_define

begin_comment
comment|/* backoff for lost peers */
end_comment

begin_if
if|#
directive|if
name|XTAL
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|PEER_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|NTP_WINDOW_SHIFT_MASK
value|0x0f
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PEER_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|NTP_WINDOW_SHIFT_MASK
value|0xff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  5.1 Uniform Phase Adjustments  *  Clock parameters  */
end_comment

begin_define
define|#
directive|define
name|CLOCK_UPDATE
value|8
end_define

begin_comment
comment|/* update interval (1<<CLOCK_UPDATE secs) */
end_comment

begin_if
if|#
directive|if
name|XTAL
end_if

begin_define
define|#
directive|define
name|CLOCK_ADJ
value|2
end_define

begin_comment
comment|/* adjustment interval (1<<CLOCK_ADJ secs) */
end_comment

begin_define
define|#
directive|define
name|CLOCK_PHASE
value|8
end_define

begin_comment
comment|/* phase shift */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MAX
value|0.128
end_define

begin_comment
comment|/* maximum aperture (milliseconds) */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLOCK_ADJ
value|0
end_define

begin_define
define|#
directive|define
name|CLOCK_PHASE
value|6
end_define

begin_comment
comment|/* phase shift */
end_comment

begin_define
define|#
directive|define
name|CLOCK_MAX
value|0.512
end_define

begin_comment
comment|/* maximum aperture (milliseconds) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CLOCK_FREQ
value|10
end_define

begin_comment
comment|/* frequency shift */
end_comment

begin_define
define|#
directive|define
name|CLOCK_TRACK
value|8
end_define

begin_define
define|#
directive|define
name|CLOCK_COMP
value|4
end_define

begin_define
define|#
directive|define
name|CLOCK_FACTOR
value|18
end_define

begin_escape
end_escape

begin_comment
comment|/*  * Structure definitions for NTP fixed point values  *  *    0			  1		      2			  3  *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			       Integer Part			     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			       Fraction Part			     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *  *    0			  1		      2			  3  *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |		  Integer Part	     |	   Fraction Part	     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
end_comment

begin_struct
struct|struct
name|l_fixedpt
block|{
name|u_long
name|int_part
decl_stmt|;
name|u_long
name|fraction
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s_fixedpt
block|{
name|u_short
name|int_part
decl_stmt|;
name|u_short
name|fraction
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  =================  Table 3.3. Packet Variables   ================= */
end_comment

begin_comment
comment|/*  *    0			  1		      2			  3  *    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |LI | VN  | Mode|	  Stratum    |	    Poll     |	 Precision   |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			   Synchronizing Distance		     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			  Synchronizing Dispersion		     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |			Reference Clock Identifier		     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |								     |  *   |		       Reference Timestamp (64 bits)		     |  *   |								     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |								     |  *   |		       Originate Timestamp (64 bits)		     |  *   |								     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |								     |  *   |			Receive Timestamp (64 bits)		     |  *   |								     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *   |								     |  *   |			Transmit Timestamp (64 bits)		     |  *   |								     |  *   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ */
end_comment

begin_struct
struct|struct
name|ntpdata
block|{
name|u_char
name|status
decl_stmt|;
comment|/* status of local clock and leap info */
name|u_char
name|stratum
decl_stmt|;
comment|/* Stratum level */
name|u_char
name|ppoll
decl_stmt|;
comment|/* poll value */
name|int
name|precision
range|:
literal|8
decl_stmt|;
name|struct
name|s_fixedpt
name|distance
decl_stmt|;
name|struct
name|s_fixedpt
name|dispersion
decl_stmt|;
name|u_long
name|refid
decl_stmt|;
name|struct
name|l_fixedpt
name|reftime
decl_stmt|;
name|struct
name|l_fixedpt
name|org
decl_stmt|;
name|struct
name|l_fixedpt
name|rec
decl_stmt|;
name|struct
name|l_fixedpt
name|xmt
decl_stmt|;
ifdef|#
directive|ifdef
name|notdef
comment|/* Not Yet in this version... */
name|u_long
name|keyid
decl_stmt|;
name|struct
name|l_fixedpt
name|mac
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAC_LEN
value|(sizeof(l_fp) + sizeof(u_long))
end_define

begin_define
define|#
directive|define
name|LEN_PKT_MAC
value|(sizeof(struct pkt))
end_define

begin_define
define|#
directive|define
name|LEN_PKT_NOMAC
value|(sizeof(struct pkt) - MAC_LEN)
end_define

begin_comment
comment|/*  *	Leap Second Codes (high order two bits)  */
end_comment

begin_define
define|#
directive|define
name|NO_WARNING
value|0x00
end_define

begin_comment
comment|/* no warning */
end_comment

begin_define
define|#
directive|define
name|PLUS_SEC
value|0x40
end_define

begin_comment
comment|/* add a second (61 seconds) */
end_comment

begin_define
define|#
directive|define
name|MINUS_SEC
value|0x80
end_define

begin_comment
comment|/* minus a second (59 seconds) */
end_comment

begin_define
define|#
directive|define
name|ALARM
value|0xc0
end_define

begin_comment
comment|/* alarm condition (clock unsynchronized) */
end_comment

begin_comment
comment|/*  *	Clock Status Bits that Encode Version  */
end_comment

begin_define
define|#
directive|define
name|VERS2PKT
parameter_list|(
name|status
parameter_list|,
name|vers
parameter_list|)
value|((status) |= ((vers)<< 3))
end_define

begin_define
define|#
directive|define
name|PKT2VERS
parameter_list|(
name|status
parameter_list|)
value|((status>> 3)& 07)
end_define

begin_define
define|#
directive|define
name|NTPVERSION_1
value|0x08
end_define

begin_define
define|#
directive|define
name|VERSIONMASK
value|0x38
end_define

begin_define
define|#
directive|define
name|LEAPMASK
value|0xc0
end_define

begin_define
define|#
directive|define
name|MODEMASK
value|0x07
end_define

begin_comment
comment|/*  *	Code values  */
end_comment

begin_define
define|#
directive|define
name|MODE_UNSPEC
value|0
end_define

begin_comment
comment|/* unspecified */
end_comment

begin_define
define|#
directive|define
name|MODE_SYM_ACT
value|1
end_define

begin_comment
comment|/* symmetric active */
end_comment

begin_define
define|#
directive|define
name|MODE_SYM_PAS
value|2
end_define

begin_comment
comment|/* symmetric passive */
end_comment

begin_define
define|#
directive|define
name|MODE_CLIENT
value|3
end_define

begin_comment
comment|/* client */
end_comment

begin_define
define|#
directive|define
name|MODE_SERVER
value|4
end_define

begin_comment
comment|/* server */
end_comment

begin_define
define|#
directive|define
name|MODE_BROADCAST
value|5
end_define

begin_comment
comment|/* broadcast */
end_comment

begin_define
define|#
directive|define
name|MODE_RES1
value|6
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|MODE_RES2
value|7
end_define

begin_comment
comment|/* reserved */
end_comment

begin_comment
comment|/*  *	Stratum Definitions  */
end_comment

begin_define
define|#
directive|define
name|UNSPECIFIED
value|0
end_define

begin_define
define|#
directive|define
name|PRIM_REF
value|1
end_define

begin_comment
comment|/* radio clock */
end_comment

begin_define
define|#
directive|define
name|INFO_QUERY
value|62
end_define

begin_comment
comment|/* **** THIS implementation dependent **** */
end_comment

begin_define
define|#
directive|define
name|INFO_REPLY
value|63
end_define

begin_comment
comment|/* **** THIS implementation dependent **** */
end_comment

begin_comment
comment|/* =================  table 3.2 Peer Variables	================= */
end_comment

begin_struct
struct|struct
name|ntp_peer
block|{
name|struct
name|ntp_peer
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
name|struct
name|Naddr
name|src
decl_stmt|;
comment|/* both peer.srcadr and  					   peer.srcport */
name|int
name|flags
decl_stmt|;
comment|/* local flags */
define|#
directive|define
name|PEER_FL_CONFIG
value|0x0001
define|#
directive|define
name|PEER_FL_AUTHENABLE
value|0x0002
define|#
directive|define
name|PEER_FL_SNOOZE
value|0x0004
define|#
directive|define
name|PEER_FL_SANE
value|0x0100
comment|/* sane peer */
define|#
directive|define
name|PEER_FL_CANDIDATE
value|0x0200
comment|/* candidate peer */
define|#
directive|define
name|PEER_FL_SYNC
value|0x1000
comment|/* peer can bet sync'd to */
define|#
directive|define
name|PEER_FL_BCAST
value|0x2000
comment|/* broadcast peer */
define|#
directive|define
name|PEER_FL_REFCLOCK
value|0x4000
comment|/* peer is a local reference clock */
define|#
directive|define
name|PEER_FL_SELECTED
value|0x8000
comment|/* actually used by query routine */
define|#
directive|define
name|PEER_FL_CONREQ
value|0x10000
define|#
directive|define
name|PEER_FL_CONNECTED
value|0x20000
comment|/* connected */
define|#
directive|define
name|PEER_FL_CONINP1
value|0x40000
comment|/* connection in progress - stage1 */
define|#
directive|define
name|PEER_FL_CONINP2
value|0x80000
comment|/* connection in progress - stage2 */
define|#
directive|define
name|PEER_FL_CONNSTATE
value|(PEER_FL_CONINP2|PEER_FL_CONINP1|PEER_FL_CONNECTED)
name|int
name|sock
decl_stmt|;
comment|/* index into sockets to derive 					   peer.dstadr and peer.dstport */
name|u_char
name|leap
decl_stmt|;
comment|/* receive */
name|u_char
name|hmode
decl_stmt|;
comment|/* receive */
name|u_char
name|stratum
decl_stmt|;
comment|/* receive */
name|u_char
name|ppoll
decl_stmt|;
comment|/* receive */
name|u_char
name|hpoll
decl_stmt|;
comment|/* poll update */
name|u_char
name|vers
decl_stmt|;
comment|/* version */
define|#
directive|define
name|PEERMODE_NORMAL
value|1
define|#
directive|define
name|PEERMODE_QUERY
value|2
name|u_char
name|mode
decl_stmt|;
comment|/* mode */
name|short
name|precision
decl_stmt|;
comment|/* receive */
name|struct
name|s_fixedpt
name|distance
decl_stmt|;
comment|/* receive */
name|struct
name|s_fixedpt
name|dispersion
decl_stmt|;
comment|/* receive */
name|Refid
name|refid
decl_stmt|;
comment|/* receive */
name|struct
name|l_fixedpt
name|reftime
decl_stmt|;
comment|/* receive */
name|struct
name|l_fixedpt
name|org
decl_stmt|;
comment|/* receive, clear */
name|struct
name|l_fixedpt
name|rec
decl_stmt|;
comment|/* receive, clear */
name|struct
name|l_fixedpt
name|xmt
decl_stmt|;
comment|/* transmit, clear */
name|u_long
name|reach
decl_stmt|;
comment|/* receive, transmit, clear */
name|u_long
name|valid
decl_stmt|;
comment|/* packet, transmit, clear */
name|u_long
name|timer
decl_stmt|;
comment|/* receive, transmit, poll update */
name|long
name|stopwatch
decl_stmt|;
comment|/*<<local>> for timing */
comment|/* 	 * first order offsets 	 */
struct|struct
name|filter
block|{
name|short
name|samples
decl_stmt|;
comment|/*<<local>> */
name|double
name|offset
index|[
name|PEER_SHIFT
index|]
decl_stmt|;
name|double
name|delay
index|[
name|PEER_SHIFT
index|]
decl_stmt|;
block|}
name|filter
struct|;
comment|/* filter, clear */
name|double
name|estdelay
decl_stmt|;
comment|/* filter */
name|double
name|estoffset
decl_stmt|;
comment|/* filter */
name|double
name|estdisp
decl_stmt|;
comment|/* filter */
name|u_long
name|pkt_sent
decl_stmt|;
comment|/*<<local>> */
name|u_long
name|pkt_rcvd
decl_stmt|;
comment|/*<<local>> */
name|u_long
name|pkt_dropped
decl_stmt|;
comment|/*<<local>> */
name|int
name|backoff
decl_stmt|;
comment|/*<<local>> */
block|}
struct|;
end_struct

begin_comment
comment|/* ================= table 3.1:  System Variables ================= */
end_comment

begin_struct
struct|struct
name|sysdata
block|{
comment|/* procedure */
name|u_char
name|leap
decl_stmt|;
comment|/* clock update */
name|u_char
name|stratum
decl_stmt|;
comment|/* clock update */
name|short
name|precision
decl_stmt|;
comment|/* system */
name|struct
name|s_fixedpt
name|distance
decl_stmt|;
comment|/* clock update */
name|struct
name|s_fixedpt
name|dispersion
decl_stmt|;
comment|/* clock update */
name|Refid
name|refid
decl_stmt|;
comment|/* clock update */
name|struct
name|l_fixedpt
name|reftime
decl_stmt|;
comment|/* clock update */
name|int
name|hold
decl_stmt|;
comment|/* clock update */
name|struct
name|ntp_peer
modifier|*
name|peer
decl_stmt|;
comment|/* selection */
name|int
name|maxpeers
decl_stmt|;
comment|/*<<local>> */
name|u_char
name|filler
decl_stmt|;
comment|/* put here for %&*%$$ SUNs */
block|}
struct|;
end_struct

begin_escape
end_escape

begin_define
define|#
directive|define
name|NTPDC_VERSION
value|2
end_define

begin_comment
comment|/*  *  These structures are used to pass information to the ntpdc (control)  *  program.  They are unique to this implementation and not part of the  *  NTP specification.  */
end_comment

begin_struct
struct|struct
name|clockinfo
block|{
name|u_long
name|net_address
decl_stmt|;
name|u_long
name|my_address
decl_stmt|;
name|u_short
name|port
decl_stmt|;
name|u_short
name|flags
decl_stmt|;
name|u_long
name|pkt_sent
decl_stmt|;
name|u_long
name|pkt_rcvd
decl_stmt|;
name|u_long
name|pkt_dropped
decl_stmt|;
name|u_long
name|timer
decl_stmt|;
name|u_char
name|leap
decl_stmt|;
name|u_char
name|stratum
decl_stmt|;
name|u_char
name|ppoll
decl_stmt|;
name|int
name|precision
range|:
literal|8
decl_stmt|;
name|u_char
name|hpoll
decl_stmt|;
name|u_char
name|filler1
decl_stmt|;
name|u_short
name|reach
decl_stmt|;
name|long
name|estdisp
decl_stmt|;
comment|/* scaled by 1000 */
name|long
name|estdelay
decl_stmt|;
comment|/* in milliseconds */
name|long
name|estoffset
decl_stmt|;
comment|/* in milliseconds */
name|u_long
name|refid
decl_stmt|;
name|struct
name|l_fixedpt
name|reftime
decl_stmt|;
struct|struct
name|info_filter
block|{
name|short
name|index
decl_stmt|;
name|short
name|filler
decl_stmt|;
name|long
name|offset
index|[
name|PEER_SHIFT
index|]
decl_stmt|;
comment|/* in milliseconds */
name|long
name|delay
index|[
name|PEER_SHIFT
index|]
decl_stmt|;
comment|/* in milliseconds */
block|}
name|info_filter
struct|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ntpinfo
block|{
name|u_char
name|version
decl_stmt|;
name|u_char
name|type
decl_stmt|;
comment|/* request type (stratum in ntp packets) */
name|u_char
name|count
decl_stmt|;
comment|/* number of entries in this packet */
name|u_char
name|seq
decl_stmt|;
comment|/* sequence number of this packet */
name|u_char
name|npkts
decl_stmt|;
comment|/* total number of packets */
name|u_char
name|peers
decl_stmt|;
name|u_char
name|fill3
decl_stmt|;
name|u_char
name|fill4
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|int
name|selfds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|fd_set
name|globmask
decl_stmt|,
name|globwmask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|paddr
argument_list|()
decl_stmt|,
modifier|*
name|ntoa
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|strcpy
argument_list|()
decl_stmt|,
modifier|*
name|strcat
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|sprintf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|malloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|lseek
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|random
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|void
name|advise
argument_list|()
decl_stmt|,
name|avoid
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|double
name|s_fixed_to_double
argument_list|()
decl_stmt|,
name|ul_fixed_to_double
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|double
name|atof
parameter_list|()
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_function_decl
specifier|extern
name|void
name|dump_pkt
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

