begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 by the University of Southern California  * All rights reserved.  *  * Permission to use, copy, modify, and distribute this software and its  * documentation in source and binary forms for non-commercial purposes  * and without fee is hereby granted, provided that the above copyright  * notice appear in all copies and that both the copyright notice and  * this permission notice appear in supporting documentation. and that  * any documentation, advertising materials, and other materials related  * to such distribution and use acknowledge that the software was  * developed by the University of Southern California, Information  * Sciences Institute.  The name of the University may not be used to  * endorse or promote products derived from this software without  * specific prior written permission.  *  * THE UNIVERSITY OF SOUTHERN CALIFORNIA makes no representations about  * the suitability of this software for any purpose.  THIS SOFTWARE IS  * PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  * INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Other copyrights might apply to parts of this software and are so  * noted when applicable.  */
end_comment

begin_define
define|#
directive|define
name|RSRR_SERV_PATH
value|"/var/run/rsrr_svr"
end_define

begin_comment
comment|/* Note this needs to be 14 chars for 4.3 BSD compatibility */
end_comment

begin_comment
comment|/* Note This appears to be unused */
end_comment

begin_define
define|#
directive|define
name|RSRR_CLI_PATH
value|"/var/run/rsrr_cli"
end_define

begin_define
define|#
directive|define
name|RSRR_MAX_LEN
value|2048
end_define

begin_define
define|#
directive|define
name|RSRR_HEADER_LEN
value|(sizeof(struct rsrr_header))
end_define

begin_define
define|#
directive|define
name|RSRR_RQ_LEN
value|(RSRR_HEADER_LEN + sizeof(struct rsrr_rq))
end_define

begin_define
define|#
directive|define
name|RSRR_RR_LEN
value|(RSRR_HEADER_LEN + sizeof(struct rsrr_rr))
end_define

begin_define
define|#
directive|define
name|RSRR_VIF_LEN
value|(sizeof(struct rsrr_vif))
end_define

begin_comment
comment|/* Current maximum number of vifs. */
end_comment

begin_define
define|#
directive|define
name|RSRR_MAX_VIFS
value|32
end_define

begin_comment
comment|/* Maximum acceptable version */
end_comment

begin_define
define|#
directive|define
name|RSRR_MAX_VERSION
value|1
end_define

begin_comment
comment|/* RSRR message types */
end_comment

begin_define
define|#
directive|define
name|RSRR_ALL_TYPES
value|0
end_define

begin_define
define|#
directive|define
name|RSRR_INITIAL_QUERY
value|1
end_define

begin_define
define|#
directive|define
name|RSRR_INITIAL_REPLY
value|2
end_define

begin_define
define|#
directive|define
name|RSRR_ROUTE_QUERY
value|3
end_define

begin_define
define|#
directive|define
name|RSRR_ROUTE_REPLY
value|4
end_define

begin_comment
comment|/* RSRR Initial Reply (Vif) Status bits  * Each definition represents the position of the bit from right to left.  *  * Right-most bit is the disabled bit, set if the vif is administratively  * disabled.  */
end_comment

begin_define
define|#
directive|define
name|RSRR_DISABLED_BIT
value|0
end_define

begin_comment
comment|/* All other bits are zeroes */
end_comment

begin_comment
comment|/* RSRR Route Query/Reply flag bits  * Each definition represents the position of the bit from right to left.  *  * Right-most bit is the Route Change Notification bit, set if the  * reservation protocol wishes to receive notification of  * a route change for the source-destination pair listed in the query.  * Notification is in the form of an unsolicitied Route Reply.  */
end_comment

begin_define
define|#
directive|define
name|RSRR_NOTIFICATION_BIT
value|0
end_define

begin_comment
comment|/* Next bit indicates an error returning the Route Reply. */
end_comment

begin_define
define|#
directive|define
name|RSRR_ERROR_BIT
value|1
end_define

begin_comment
comment|/* All other bits are zeroes */
end_comment

begin_comment
comment|/* Definition of an RSRR message header.  * An Initial Query uses only the header, and an Initial Reply uses  * the header and a list of vifs.  */
end_comment

begin_struct
struct|struct
name|rsrr_header
block|{
name|u_char
name|version
decl_stmt|;
comment|/* RSRR Version, currently 1 */
name|u_char
name|type
decl_stmt|;
comment|/* type of message, as defined above */
name|u_char
name|flags
decl_stmt|;
comment|/* flags; defined by type */
name|u_char
name|num
decl_stmt|;
comment|/* number; defined by type */
block|}
struct|;
end_struct

begin_comment
comment|/* Definition of a vif as seen by the reservation protocol.  *  * Routing gives the reservation protocol a list of vifs in the  * Initial Reply.  *  * We explicitly list the ID because we can't assume that all routing  * protocols will use the same numbering scheme.  *   * The status is a bitmask of status flags, as defined above.  It is the  * responsibility of the reservation protocol to perform any status checks  * if it uses the MULTICAST_VIF socket option.  *  * The threshold indicates the ttl an outgoing packet needs in order to  * be forwarded. The reservation protocol must perform this check itself if  * it uses the MULTICAST_VIF socket option.  *  * The local address is the address of the physical interface over which  * packets are sent.  */
end_comment

begin_struct
struct|struct
name|rsrr_vif
block|{
name|u_char
name|id
decl_stmt|;
comment|/* vif id */
name|u_char
name|threshold
decl_stmt|;
comment|/* vif threshold ttl */
name|u_short
name|status
decl_stmt|;
comment|/* vif status bitmask */
name|struct
name|in_addr
name|local_addr
decl_stmt|;
comment|/* vif local address */
block|}
struct|;
end_struct

begin_comment
comment|/* Definition of an RSRR Route Query.  *   * The query asks routing for the forwarding entry for a particular  * source and destination.  The query ID uniquely identifies the query  * for the reservation protocol.  Thus, the combination of the client's  * address and the query ID forms a unique identifier for routing.  * Flags are defined above.  */
end_comment

begin_struct
struct|struct
name|rsrr_rq
block|{
name|struct
name|in_addr
name|dest_addr
decl_stmt|;
comment|/* destination */
name|struct
name|in_addr
name|source_addr
decl_stmt|;
comment|/* source */
name|u_long
name|query_id
decl_stmt|;
comment|/* query ID */
block|}
struct|;
end_struct

begin_comment
comment|/* Definition of an RSRR Route Reply.  *  * Routing uses the reply to give the reservation protocol the  * forwarding entry for a source-destination pair.  Routing copies the  * query ID from the query and fills in the incoming vif and a bitmask  * of the outgoing vifs.  * Flags are defined above.  */
end_comment

begin_struct
struct|struct
name|rsrr_rr
block|{
name|struct
name|in_addr
name|dest_addr
decl_stmt|;
comment|/* destination */
name|struct
name|in_addr
name|source_addr
decl_stmt|;
comment|/* source */
name|u_long
name|query_id
decl_stmt|;
comment|/* query ID */
name|u_short
name|in_vif
decl_stmt|;
comment|/* incoming vif */
name|u_short
name|reserved
decl_stmt|;
comment|/* reserved */
name|u_long
name|out_vif_bm
decl_stmt|;
comment|/* outgoing vif bitmask */
block|}
struct|;
end_struct

end_unit

