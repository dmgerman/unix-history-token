begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1984, 1985, 1986, 1987 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)spidp.h	7.4 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Definitions for NS(tm) Internet Datagram Protocol  * containing a Sequenced Packet Protocol packet.  */
end_comment

begin_struct
struct|struct
name|spidp
block|{
name|struct
name|idp
name|si_i
decl_stmt|;
name|struct
name|sphdr
name|si_s
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|spidp_q
block|{
name|struct
name|spidp_q
modifier|*
name|si_next
decl_stmt|;
name|struct
name|spidp_q
modifier|*
name|si_prev
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SI
parameter_list|(
name|x
parameter_list|)
value|((struct spidp *)x)
end_define

begin_define
define|#
directive|define
name|si_sum
value|si_i.idp_sum
end_define

begin_define
define|#
directive|define
name|si_len
value|si_i.idp_len
end_define

begin_define
define|#
directive|define
name|si_tc
value|si_i.idp_tc
end_define

begin_define
define|#
directive|define
name|si_pt
value|si_i.idp_pt
end_define

begin_define
define|#
directive|define
name|si_dna
value|si_i.idp_dna
end_define

begin_define
define|#
directive|define
name|si_sna
value|si_i.idp_sna
end_define

begin_define
define|#
directive|define
name|si_sport
value|si_i.idp_sna.x_port
end_define

begin_define
define|#
directive|define
name|si_cc
value|si_s.sp_cc
end_define

begin_define
define|#
directive|define
name|si_dt
value|si_s.sp_dt
end_define

begin_define
define|#
directive|define
name|si_sid
value|si_s.sp_sid
end_define

begin_define
define|#
directive|define
name|si_did
value|si_s.sp_did
end_define

begin_define
define|#
directive|define
name|si_seq
value|si_s.sp_seq
end_define

begin_define
define|#
directive|define
name|si_ack
value|si_s.sp_ack
end_define

begin_define
define|#
directive|define
name|si_alo
value|si_s.sp_alo
end_define

end_unit

