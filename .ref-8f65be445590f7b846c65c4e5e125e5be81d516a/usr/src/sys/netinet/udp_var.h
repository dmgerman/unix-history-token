begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989 Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)udp_var.h	7.7 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * UDP kernel structures and variables.  */
end_comment

begin_struct
struct|struct
name|udpiphdr
block|{
name|struct
name|ipovly
name|ui_i
decl_stmt|;
comment|/* overlaid ip structure */
name|struct
name|udphdr
name|ui_u
decl_stmt|;
comment|/* udp header */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ui_next
value|ui_i.ih_next
end_define

begin_define
define|#
directive|define
name|ui_prev
value|ui_i.ih_prev
end_define

begin_define
define|#
directive|define
name|ui_x1
value|ui_i.ih_x1
end_define

begin_define
define|#
directive|define
name|ui_pr
value|ui_i.ih_pr
end_define

begin_define
define|#
directive|define
name|ui_len
value|ui_i.ih_len
end_define

begin_define
define|#
directive|define
name|ui_src
value|ui_i.ih_src
end_define

begin_define
define|#
directive|define
name|ui_dst
value|ui_i.ih_dst
end_define

begin_define
define|#
directive|define
name|ui_sport
value|ui_u.uh_sport
end_define

begin_define
define|#
directive|define
name|ui_dport
value|ui_u.uh_dport
end_define

begin_define
define|#
directive|define
name|ui_ulen
value|ui_u.uh_ulen
end_define

begin_define
define|#
directive|define
name|ui_sum
value|ui_u.uh_sum
end_define

begin_struct
struct|struct
name|udpstat
block|{
comment|/* input statistics: */
name|int
name|udps_ipackets
decl_stmt|;
comment|/* total input packets */
name|int
name|udps_hdrops
decl_stmt|;
comment|/* packet shorter than header */
name|int
name|udps_badsum
decl_stmt|;
comment|/* checksum error */
name|int
name|udps_badlen
decl_stmt|;
comment|/* data length larger than packet */
name|int
name|udps_noport
decl_stmt|;
comment|/* no socket on port */
name|int
name|udps_noportbcast
decl_stmt|;
comment|/* of above, arrived as broadcast */
name|int
name|udps_fullsock
decl_stmt|;
comment|/* not delivered, input socket full */
name|int
name|udpps_pcbcachemiss
decl_stmt|;
comment|/* input packets missing pcb cache */
comment|/* output statistics: */
name|int
name|udps_opackets
decl_stmt|;
comment|/* total output packets */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UDP_TTL
value|30
end_define

begin_comment
comment|/* default time to live for UDP packets */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|inpcb
name|udb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|udpstat
name|udpstat
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

