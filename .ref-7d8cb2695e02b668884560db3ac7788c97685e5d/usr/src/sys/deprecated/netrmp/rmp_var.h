begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * %sccs.include.redist.c%  *  * from: Utah $Hdr: rmp_var.h 1.3 89/06/07$  *  *	@(#)rmp_var.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *  WARNING: rmp_packet is defined assuming alignment on 16-bit boundaries.  *  Data will be contiguous on HP's (MC68000), but there may be holes if  *  this is used elsewhere (e.g. VAXen).  Or, in other words:  *  *  if (sizeof(struct rmp_packet) != 1504) error("AlignmentProblem");  */
end_comment

begin_comment
comment|/*  *  Possible values for "rmp_type" fields.  */
end_comment

begin_define
define|#
directive|define
name|RMP_BOOT_REQ
value|1
end_define

begin_comment
comment|/* boot request packet */
end_comment

begin_define
define|#
directive|define
name|RMP_BOOT_REPL
value|129
end_define

begin_comment
comment|/* boot reply packet */
end_comment

begin_define
define|#
directive|define
name|RMP_READ_REQ
value|2
end_define

begin_comment
comment|/* read request packet */
end_comment

begin_define
define|#
directive|define
name|RMP_READ_REPL
value|130
end_define

begin_comment
comment|/* read reply packet */
end_comment

begin_define
define|#
directive|define
name|RMP_BOOT_DONE
value|3
end_define

begin_comment
comment|/* boot complete packet */
end_comment

begin_comment
comment|/*  *  Useful constants.  */
end_comment

begin_define
define|#
directive|define
name|RMP_VERSION
value|2
end_define

begin_comment
comment|/* protocol version */
end_comment

begin_define
define|#
directive|define
name|RMP_TIMEOUT
value|600
end_define

begin_comment
comment|/* timeout connection after ten minutes */
end_comment

begin_define
define|#
directive|define
name|RMP_PROBESID
value|0xffff
end_define

begin_comment
comment|/* session ID for probes */
end_comment

begin_define
define|#
directive|define
name|RMP_HOSTLEN
value|13
end_define

begin_comment
comment|/* max length of server's name */
end_comment

begin_comment
comment|/*  *  RMP error codes  */
end_comment

begin_define
define|#
directive|define
name|RMP_E_OKAY
value|0
end_define

begin_define
define|#
directive|define
name|RMP_E_EOF
value|2
end_define

begin_comment
comment|/* read reply: returned end of file */
end_comment

begin_define
define|#
directive|define
name|RMP_E_ABORT
value|3
end_define

begin_comment
comment|/* abort operation */
end_comment

begin_define
define|#
directive|define
name|RMP_E_BUSY
value|4
end_define

begin_comment
comment|/* boot reply: server busy */
end_comment

begin_define
define|#
directive|define
name|RMP_E_TIMEOUT
value|5
end_define

begin_comment
comment|/* lengthen time out (not implemented) */
end_comment

begin_define
define|#
directive|define
name|RMP_E_NOFILE
value|16
end_define

begin_comment
comment|/* boot reply: file does not exist */
end_comment

begin_define
define|#
directive|define
name|RMP_E_OPENFILE
value|17
end_define

begin_comment
comment|/* boot reply: file open failed */
end_comment

begin_define
define|#
directive|define
name|RMP_E_NODFLT
value|18
end_define

begin_comment
comment|/* boot reply: default file does not exist */
end_comment

begin_define
define|#
directive|define
name|RMP_E_OPENDFLT
value|19
end_define

begin_comment
comment|/* boot reply: default file open failed */
end_comment

begin_define
define|#
directive|define
name|RMP_E_BADSID
value|25
end_define

begin_comment
comment|/* read reply: bad session ID */
end_comment

begin_define
define|#
directive|define
name|RMP_E_BADPACKET
value|27
end_define

begin_comment
comment|/* Bad packet detected */
end_comment

begin_comment
comment|/*  *  Assorted field sizes.  */
end_comment

begin_define
define|#
directive|define
name|RMPADDRLEN
value|6
end_define

begin_comment
comment|/* size of ethernet address */
end_comment

begin_define
define|#
directive|define
name|RMPLENGTHLEN
value|2
end_define

begin_comment
comment|/* size of ethernet length field (802.3) */
end_comment

begin_define
define|#
directive|define
name|RMPMACHLEN
value|20
end_define

begin_comment
comment|/* length of machine type field */
end_comment

begin_comment
comment|/*  *  RMPDATALEN is the maximum number of data octets that can be stuffed  *  into an RMP packet.  This excludes the 802.2 LLC w/HP extensions.  */
end_comment

begin_define
define|#
directive|define
name|RMPDATALEN
value|(RMP_MAX_PACKET - (2*RMPADDRLEN + RMPLENGTHLEN + \ 			                   sizeof(struct hp_llc)) )
end_define

begin_comment
comment|/*  *  Define sizes of packets we send.  Boot and Read replies are variable  *  in length depending on the length of `s'.  *  *  Also, define how much space `restofpkt' can take up for outgoing  *  Boot and Read replies.  Boot Request packets are effectively  *  limited to 255 bytes due to the preceding 1-byte length field.  */
end_comment

begin_define
define|#
directive|define
name|RMPBOOTSIZE
parameter_list|(
name|s
parameter_list|)
value|(sizeof(struct hp_llc) + sizeof(struct ifnet *) + \ 			 sizeof(struct rmp_boot_repl) + s - \ 			 sizeof(restofpkt))
end_define

begin_define
define|#
directive|define
name|RMPREADSIZE
parameter_list|(
name|s
parameter_list|)
value|(sizeof(struct hp_llc) + sizeof(struct ifnet *) + \ 			 sizeof(struct rmp_read_repl) + s - \ 			 sizeof(restofpkt) - sizeof(u_char))
end_define

begin_define
define|#
directive|define
name|RMPDONESIZE
value|(sizeof(struct hp_llc) + sizeof(struct ifnet *) + \ 			 sizeof(struct rmp_boot_done))
end_define

begin_define
define|#
directive|define
name|RMPBOOTDATA
value|255
end_define

begin_define
define|#
directive|define
name|RMPREADDATA
value|(RMPDATALEN - \ 			 (2*sizeof(u_char)+sizeof(u_short)+sizeof(u_long)))
end_define

begin_comment
comment|/*  * This protocol defines some field sizes as "rest of ethernet packet".  * There is no easy way to specify this in C, so we use a one character  * field to denote it, and index past it to the end of the packet.  */
end_comment

begin_typedef
typedef|typedef
name|char
name|restofpkt
typedef|;
end_typedef

begin_comment
comment|/*  * Packet structures.  */
end_comment

begin_struct
struct|struct
name|rmp_raw
block|{
name|u_char
name|rmp_type
decl_stmt|;
comment|/* packet type */
name|u_char
name|rmp_rawdata
index|[
name|RMPDATALEN
operator|-
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_boot_req
block|{
comment|/* boot request */
name|u_char
name|rmp_type
decl_stmt|;
comment|/* packet type (RMP_BOOT_REQ) */
name|u_char
name|rmp_retcode
decl_stmt|;
comment|/* return code (0) */
name|u_long
name|rmp_seqno
decl_stmt|;
comment|/* sequence number (real time clock) */
name|u_short
name|rmp_session
decl_stmt|;
comment|/* session id (normally 0) */
name|u_short
name|rmp_version
decl_stmt|;
comment|/* protocol version (RMP_VERSION) */
name|char
name|rmp_machtype
index|[
name|RMPMACHLEN
index|]
decl_stmt|;
comment|/* machine type */
name|u_char
name|rmp_flnmsize
decl_stmt|;
comment|/* length of rmp_flnm */
name|restofpkt
name|rmp_flnm
decl_stmt|;
comment|/* name of file to be read */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_boot_repl
block|{
comment|/* boot reply */
name|u_char
name|rmp_type
decl_stmt|;
comment|/* packet type (RMP_BOOT_REPL) */
name|u_char
name|rmp_retcode
decl_stmt|;
comment|/* return code (normally 0) */
name|u_long
name|rmp_seqno
decl_stmt|;
comment|/* sequence number (from boot req) */
name|u_short
name|rmp_session
decl_stmt|;
comment|/* session id (generated) */
name|u_short
name|rmp_version
decl_stmt|;
comment|/* protocol version (RMP_VERSION) */
name|u_char
name|rmp_flnmsize
decl_stmt|;
comment|/* length of rmp_flnm */
name|restofpkt
name|rmp_flnm
decl_stmt|;
comment|/* name of file (from boot req) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_read_req
block|{
comment|/* read request */
name|u_char
name|rmp_type
decl_stmt|;
comment|/* packet type (RMP_READ_REQ) */
name|u_char
name|rmp_retcode
decl_stmt|;
comment|/* return code (0) */
name|u_long
name|rmp_offset
decl_stmt|;
comment|/* file relative byte offset */
name|u_short
name|rmp_session
decl_stmt|;
comment|/* session id (from boot repl) */
name|u_short
name|rmp_size
decl_stmt|;
comment|/* max no of bytes to send */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_read_repl
block|{
comment|/* read reply */
name|u_char
name|rmp_type
decl_stmt|;
comment|/* packet type (RMP_READ_REPL) */
name|u_char
name|rmp_retcode
decl_stmt|;
comment|/* return code (normally 0) */
name|u_long
name|rmp_offset
decl_stmt|;
comment|/* byte offset (from read req) */
name|u_short
name|rmp_session
decl_stmt|;
comment|/* session id (from read req) */
name|restofpkt
name|rmp_data
decl_stmt|;
comment|/* data (max size from read req) */
name|u_char
name|rmp_unused
decl_stmt|;
comment|/* padding to 16-bit boundary */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_boot_done
block|{
comment|/* boot complete */
name|u_char
name|rmp_type
decl_stmt|;
comment|/* packet type (RMP_BOOT_DONE) */
name|u_char
name|rmp_retcode
decl_stmt|;
comment|/* return code (0) */
name|u_long
name|rmp_unused
decl_stmt|;
comment|/* not used (0) */
name|u_short
name|rmp_session
decl_stmt|;
comment|/* session id (from read repl) */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rmp_packet
block|{
name|struct
name|ifnet
modifier|*
name|ifp
decl_stmt|;
comment|/* ptr to intf packet arrived on */
name|struct
name|hp_llc
name|hp_llc
decl_stmt|;
union|union
block|{
name|struct
name|rmp_boot_req
name|rmp_brq
decl_stmt|;
comment|/* boot request */
name|struct
name|rmp_boot_repl
name|rmp_brpl
decl_stmt|;
comment|/* boot reply */
name|struct
name|rmp_read_req
name|rmp_rrq
decl_stmt|;
comment|/* read request */
name|struct
name|rmp_read_repl
name|rmp_rrpl
decl_stmt|;
comment|/* read reply */
name|struct
name|rmp_boot_done
name|rmp_done
decl_stmt|;
comment|/* boot complete */
name|struct
name|rmp_raw
name|rmp_raw
decl_stmt|;
comment|/* raw data */
block|}
name|rmp_proto
union|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  Make life easier...  */
end_comment

begin_define
define|#
directive|define
name|r_type
value|rmp_proto.rmp_raw.rmp_type
end_define

begin_define
define|#
directive|define
name|r_data
value|rmp_proto.rmp_raw.rmp_data
end_define

begin_define
define|#
directive|define
name|r_brq
value|rmp_proto.rmp_brq
end_define

begin_define
define|#
directive|define
name|r_brpl
value|rmp_proto.rmp_brpl
end_define

begin_define
define|#
directive|define
name|r_rrq
value|rmp_proto.rmp_rrq
end_define

begin_define
define|#
directive|define
name|r_rrpl
value|rmp_proto.rmp_rrpl
end_define

begin_define
define|#
directive|define
name|r_done
value|rmp_proto.rmp_done
end_define

begin_comment
comment|/*  *  RMP socket address: just family& destination addr.  */
end_comment

begin_struct
struct|struct
name|sockaddr_rmp
block|{
name|short
name|srmp_family
decl_stmt|;
comment|/* address family (AF_RMP) */
name|u_char
name|srmp_dhost
index|[
name|RMPADDRLEN
index|]
decl_stmt|;
comment|/* ethernet destination addr */
block|}
struct|;
end_struct

end_unit

