begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE".  Use of the mrouted program represents acceptance of  * the terms and conditions listed in that file.  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  *  * $FreeBSD$  * dvmrp.h,v 3.8.4.5 1997/11/18 23:25:57 fenner Exp  */
end_comment

begin_comment
comment|/*  * A DVMRP message consists of an IP header + an IGMP header + (for some types)  * zero or more bytes of data.  *  * For REPORT messages, the data is route information; the route information  * consists of one or more lists of the following form:  *  *		(mask, (origin, metric), (origin, metric), ...)  *  * where:  *  *	"mask" is the subnet mask for all the origins in the list.  *		It is always THREE bytes long, containing the low-order  *		three bytes of the mask (the high-order byte is always  *		0xff and therefore need not be transmitted).  *  *	"origin" is the number of a subnet from which multicast datagrams  *		may originate.  It is from one to four bytes long,  *		depending on the value of "mask":  *			if all bytes of the mask are zero  *			    the subnet number is one byte long  *			else if the low-order two bytes of the mask are zero  *			    the subnet number is two bytes long  *			else if the lowest-order byte of the mask is zero  *			    the subnet number is three bytes long,  *			else  *			    the subnet number is four bytes long.  *  *	"metric" is a one-byte value consisting of two subfields:  *		- the high-order bit is a flag which, when set, indicates  *		  the last (origin, metric) pair of a list.  *		- the low-order seven bits contain the routing metric for  *		  the corresponding origin, relative to the sender of the  *		  DVMRP report.  The metric may have the value of UNREACHABLE  *		  added to it as a "split horizon" indication (so called  *		  "poisoned reverse").  *  * Within a list, the origin subnet numbers must be in ascending order, and  * the lists themselves are in order of increasing mask value.  A message may  * not exceed 576 bytes, the default maximum IP reassembly size, including  * the IP and IGMP headers; the route information may be split across more  * than one message if necessary, by terminating a list in one message and  * starting a new list in the next message (repeating the same mask value,  * if necessary).  *  * For NEIGHBORS messages, the data is neighboring-router information  * consisting of one or more lists of the following form:  *  *	(local-addr, metric, threshold, ncount, neighbor, neighbor, ...)  *  * where:  *  *	"local-addr" is the sending router's address as seen by the neighbors  *		     in this list; it is always four bytes long.  *	"metric" is a one-byte unsigned value, the TTL `cost' of forwarding  *		 packets to any of the neighbors on this list.  *	"threshold" is a one-byte unsigned value, a lower bound on the TTL a  *		    packet must have to be forwarded to any of the neighbors on  *		    this list.  *	"ncount" is the number of neighbors in this list.  *	"neighbor" is the address of a neighboring router, four bytes long.  *  * As with REPORT messages, NEIGHBORS messages should not exceed 576 bytes,  * including the IP and IGMP headers; split longer messages by terminating the  * list in one and continuing in another, repeating the local-addr, etc., if  * necessary.  *  * For NEIGHBORS2 messages, the data is identical to NEIGHBORS except  * there is a flags byte before the neighbor count:  *  *	(local-addr, metric, threshold, flags, ncount, neighbor, neighbor, ...)  */
end_comment

begin_comment
comment|/*  * DVMRP message types (carried in the "code" field of an IGMP header)  */
end_comment

begin_define
define|#
directive|define
name|DVMRP_PROBE
value|1
end_define

begin_comment
comment|/* for finding neighbors             */
end_comment

begin_define
define|#
directive|define
name|DVMRP_REPORT
value|2
end_define

begin_comment
comment|/* for reporting some or all routes  */
end_comment

begin_define
define|#
directive|define
name|DVMRP_ASK_NEIGHBORS
value|3
end_define

begin_comment
comment|/* sent by mapper, asking for a list */
end_comment

begin_comment
comment|/* of this router's neighbors. */
end_comment

begin_define
define|#
directive|define
name|DVMRP_NEIGHBORS
value|4
end_define

begin_comment
comment|/* response to such a request */
end_comment

begin_define
define|#
directive|define
name|DVMRP_ASK_NEIGHBORS2
value|5
end_define

begin_comment
comment|/* as above, want new format reply */
end_comment

begin_define
define|#
directive|define
name|DVMRP_NEIGHBORS2
value|6
end_define

begin_define
define|#
directive|define
name|DVMRP_PRUNE
value|7
end_define

begin_comment
comment|/* prune message */
end_comment

begin_define
define|#
directive|define
name|DVMRP_GRAFT
value|8
end_define

begin_comment
comment|/* graft message */
end_comment

begin_define
define|#
directive|define
name|DVMRP_GRAFT_ACK
value|9
end_define

begin_comment
comment|/* graft acknowledgement */
end_comment

begin_define
define|#
directive|define
name|DVMRP_INFO_REQUEST
value|10
end_define

begin_comment
comment|/* information request */
end_comment

begin_define
define|#
directive|define
name|DVMRP_INFO_REPLY
value|11
end_define

begin_comment
comment|/* information reply */
end_comment

begin_comment
comment|/*  * 'flags' byte values in DVMRP_NEIGHBORS2 reply.  */
end_comment

begin_define
define|#
directive|define
name|DVMRP_NF_TUNNEL
value|0x01
end_define

begin_comment
comment|/* neighbors reached via tunnel */
end_comment

begin_define
define|#
directive|define
name|DVMRP_NF_SRCRT
value|0x02
end_define

begin_comment
comment|/* tunnel uses IP source routing */
end_comment

begin_define
define|#
directive|define
name|DVMRP_NF_PIM
value|0x04
end_define

begin_comment
comment|/* neighbor is a PIM neighbor */
end_comment

begin_define
define|#
directive|define
name|DVMRP_NF_DOWN
value|0x10
end_define

begin_comment
comment|/* kernel state of interface */
end_comment

begin_define
define|#
directive|define
name|DVMRP_NF_DISABLED
value|0x20
end_define

begin_comment
comment|/* administratively disabled */
end_comment

begin_define
define|#
directive|define
name|DVMRP_NF_QUERIER
value|0x40
end_define

begin_comment
comment|/* I am the subnet's querier */
end_comment

begin_define
define|#
directive|define
name|DVMRP_NF_LEAF
value|0x80
end_define

begin_comment
comment|/* Neighbor reports that it is a leaf */
end_comment

begin_comment
comment|/*  * Request/reply types for info queries/replies  */
end_comment

begin_define
define|#
directive|define
name|DVMRP_INFO_VERSION
value|1
end_define

begin_comment
comment|/* version string */
end_comment

begin_define
define|#
directive|define
name|DVMRP_INFO_NEIGHBORS
value|2
end_define

begin_comment
comment|/* neighbors2 data */
end_comment

begin_comment
comment|/*  * Limit on length of route data  */
end_comment

begin_define
define|#
directive|define
name|MAX_IP_PACKET_LEN
value|576
end_define

begin_define
define|#
directive|define
name|MIN_IP_HEADER_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MAX_IP_HEADER_LEN
value|60
end_define

begin_define
define|#
directive|define
name|MAX_DVMRP_DATA_LEN
define|\
value|( MAX_IP_PACKET_LEN - MAX_IP_HEADER_LEN - IGMP_MINLEN )
end_define

begin_comment
comment|/*  * Various protocol constants (all times in seconds)  */
end_comment

begin_comment
comment|/* address for multicast DVMRP msgs */
end_comment

begin_define
define|#
directive|define
name|INADDR_DVMRP_GROUP
value|(u_int32)0xe0000004
end_define

begin_comment
comment|/* 224.0.0.4 */
end_comment

begin_comment
comment|/*  * The IGMPv2<netinet/in.h> defines INADDR_ALLRTRS_GROUP, but earlier  * ones don't, so we define it conditionally here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INADDR_ALLRTRS_GROUP
end_ifndef

begin_comment
comment|/* address for multicast mtrace msg */
end_comment

begin_define
define|#
directive|define
name|INADDR_ALLRTRS_GROUP
value|(u_int32)0xe0000002
end_define

begin_comment
comment|/* 224.0.0.2 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ROUTE_MAX_REPORT_DELAY
value|5
end_define

begin_comment
comment|/* max delay for reporting changes  */
end_comment

begin_comment
comment|/*  (This is the timer interrupt    */
end_comment

begin_comment
comment|/*  interval; all times must be     */
end_comment

begin_comment
comment|/*  multiples of this value.)       */
end_comment

begin_define
define|#
directive|define
name|ROUTE_REPORT_INTERVAL
value|60
end_define

begin_comment
comment|/* periodic route report interval   */
end_comment

begin_define
define|#
directive|define
name|ROUTE_SWITCH_TIME
value|140
end_define

begin_comment
comment|/* time to switch to equivalent gw  */
end_comment

begin_define
define|#
directive|define
name|ROUTE_EXPIRE_TIME
value|200
end_define

begin_comment
comment|/* time to mark route invalid       */
end_comment

begin_define
define|#
directive|define
name|ROUTE_DISCARD_TIME
value|340
end_define

begin_comment
comment|/* time to garbage collect route    */
end_comment

begin_define
define|#
directive|define
name|LEAF_CONFIRMATION_TIME
value|200
end_define

begin_comment
comment|/* time to consider subnet a leaf   */
end_comment

begin_define
define|#
directive|define
name|NEIGHBOR_PROBE_INTERVAL
value|10
end_define

begin_comment
comment|/* periodic neighbor probe interval */
end_comment

begin_define
define|#
directive|define
name|NEIGHBOR_EXPIRE_TIME
value|30
end_define

begin_comment
comment|/* time to consider neighbor gone   */
end_comment

begin_define
define|#
directive|define
name|OLD_NEIGHBOR_EXPIRE_TIME
value|140
end_define

begin_comment
comment|/* time to consider neighbor gone   */
end_comment

begin_define
define|#
directive|define
name|UNREACHABLE
value|32
end_define

begin_comment
comment|/* "infinity" metric, must be<= 64 */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_METRIC
value|1
end_define

begin_comment
comment|/* default subnet/tunnel metric     */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_THRESHOLD
value|1
end_define

begin_comment
comment|/* default subnet/tunnel threshold  */
end_comment

begin_define
define|#
directive|define
name|MAX_RATE_LIMIT
value|100000
end_define

begin_comment
comment|/* max rate limit      	    	    */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_PHY_RATE_LIMIT
value|0
end_define

begin_comment
comment|/* default phyint rate limit  	    */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_TUN_RATE_LIMIT
value|0
end_define

begin_comment
comment|/* default tunnel rate limit	    */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CACHE_LIFETIME
value|300
end_define

begin_comment
comment|/* kernel route entry discard time  */
end_comment

begin_define
define|#
directive|define
name|MIN_CACHE_LIFETIME
value|60
end_define

begin_comment
comment|/* minimum allowed cache lifetime   */
end_comment

begin_define
define|#
directive|define
name|AVERAGE_PRUNE_LIFETIME
value|7200
end_define

begin_comment
comment|/* average lifetime of prunes sent  */
end_comment

begin_define
define|#
directive|define
name|MIN_PRUNE_LIFETIME
value|120
end_define

begin_comment
comment|/* minimum allowed prune lifetime   */
end_comment

begin_define
define|#
directive|define
name|GRAFT_TIMEOUT_VAL
value|5
end_define

begin_comment
comment|/* retransmission time for grafts   */
end_comment

begin_define
define|#
directive|define
name|PRUNE_REXMIT_VAL
value|3
end_define

begin_comment
comment|/* initial time for prune rexmission*/
end_comment

end_unit

