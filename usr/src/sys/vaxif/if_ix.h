begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1986 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)if_ix.h	7.1 (Berkeley) 6/5/86  */
end_comment

begin_union
union|union
name|ix_stats
block|{
struct|struct
block|{
comment|/* General statistics below */
name|u_char
name|macg_physaddr
index|[
literal|6
index|]
decl_stmt|;
name|u_short
name|macg_pad
decl_stmt|;
name|u_long
name|dlag_rcvmac
decl_stmt|;
comment|/* packets received by DLA from MAC */
name|u_long
name|dlag_rcvpass
decl_stmt|;
comment|/* packets passed to users by DLA */
name|u_long
name|dlag_txreq
decl_stmt|;
comment|/* packets sent by users to DLA */
name|u_long
name|dlag_txsnt
decl_stmt|;
comment|/* packets sent by DLA to MAC */
name|u_short
name|dlag_chaopn
decl_stmt|;
comment|/* channels open */
name|u_short
name|dlag_maxopn
decl_stmt|;
comment|/* max channels opened concurrently */
name|u_long
name|macg_frmtos
decl_stmt|;
comment|/* packets discarded by MAC */
name|u_long
name|macg_frmpas
decl_stmt|;
comment|/* packets sent to DLA by MAC */
name|u_long
name|macg_x2x
decl_stmt|;
comment|/* packets put on wire by MAC */
name|u_long
name|macg_x2r
decl_stmt|;
comment|/* packets looped by MAC */
name|u_long
name|macg_xrty
decl_stmt|;
comment|/* transmitter retries */
name|u_short
name|macg_noap
decl_stmt|;
comment|/* open MAC paths */
name|u_short
name|macg_nprom
decl_stmt|;
comment|/* open promiscuous paths */
name|u_short
name|macg_conopn
decl_stmt|;
comment|/* max concurrent MAC paths */
name|u_short
name|sysg_crce
decl_stmt|;
comment|/* CRC errors */
name|u_short
name|sysg_alne
decl_stmt|;
comment|/* alignment errors */
name|u_short
name|sysg_rsce
decl_stmt|;
comment|/* resource errors */
name|u_short
name|sysg_ovre
decl_stmt|;
comment|/* overrun errors */
block|}
name|ixg
struct|;
struct|struct
block|{
comment|/* Channel statistics below */
name|u_long
name|dabc_rcvacc
decl_stmt|;
comment|/* packets received */
name|u_long
name|dabc_rcvtoss
decl_stmt|;
comment|/* packets discarded, queue full */
name|u_long
name|dabc_rcvpass
decl_stmt|;
comment|/* packets passed to user */
name|u_long
name|dabc_txreq
decl_stmt|;
comment|/* packets sent by  user */
name|u_long
name|dabc_txsent
decl_stmt|;
comment|/* packets sent to MAC */
name|u_long
name|macc_rcvcnt
decl_stmt|;
comment|/* packets received by MAC */
name|u_long
name|macc_txtcnt
decl_stmt|;
comment|/* packets sent by MAC to wire */
name|u_long
name|macc_lowmem
decl_stmt|;
comment|/* packets discarded, no mem  */
block|}
name|ixc
struct|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|IXC_MAP
parameter_list|(
name|a
parameter_list|)
value|(((a)<< 6) | 0100077)
end_define

begin_define
define|#
directive|define
name|IXC_OPEN
value|IXC_MAP(1)
end_define

begin_comment
comment|/* Open Channel */
end_comment

begin_define
define|#
directive|define
name|IXC_CLOSE
value|IXC_MAP(2)
end_define

begin_comment
comment|/* Close Channel */
end_comment

begin_define
define|#
directive|define
name|IXC_MCAST
value|IXC_MAP(3)
end_define

begin_comment
comment|/* Set Multicast Addresses */
end_comment

begin_define
define|#
directive|define
name|IXC_RECV
value|IXC_MAP(4)
end_define

begin_comment
comment|/* Receive Frame */
end_comment

begin_define
define|#
directive|define
name|IXC_RECVF
value|IXC_MAP(5)
end_define

begin_comment
comment|/* Receive Fragment */
end_comment

begin_define
define|#
directive|define
name|IXC_XMIT
value|IXC_MAP(6)
end_define

begin_comment
comment|/* Send Frame */
end_comment

begin_define
define|#
directive|define
name|IXC_GSTAT
value|IXC_MAP(7)
end_define

begin_comment
comment|/* Get General Statistics */
end_comment

begin_define
define|#
directive|define
name|IXC_CSTAT
value|IXC_MAP(8)
end_define

begin_comment
comment|/* Get Channel Statistics */
end_comment

begin_define
define|#
directive|define
name|IXC_GSCLR
value|IXC_MAP(9)
end_define

begin_comment
comment|/* Clear General Statistics */
end_comment

begin_define
define|#
directive|define
name|IXC_CSCLR
value|IXC_MAP(10)
end_define

begin_comment
comment|/* Clear Channel Statistics */
end_comment

begin_define
define|#
directive|define
name|IXC_RESET
value|IXC_MAP(11)
end_define

begin_comment
comment|/* Reset DLA module */
end_comment

begin_define
define|#
directive|define
name|IXC_LDPA
value|IXC_MAP(12)
end_define

begin_comment
comment|/* Load Physical Address */
end_comment

end_unit

