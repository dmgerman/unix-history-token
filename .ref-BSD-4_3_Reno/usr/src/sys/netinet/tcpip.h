begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986 Regents of the University of California.  * All rights reserved.  *  * Redistribution is only permitted until one year after the first shipment  * of 4.4BSD by the Regents.  Otherwise, redistribution and use in source and  * binary forms are permitted provided that: (1) source distributions retain  * this entire copyright notice and comment, and (2) distributions including  * binaries display the following acknowledgement:  This product includes  * software developed by the University of California, Berkeley and its  * contributors'' in the documentation or other materials provided with the  * distribution and in all advertising materials mentioning features or use  * of this software.  Neither the name of the University nor the names of  * its contributors may be used to endorse or promote products derived from  * this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  *	@(#)tcpip.h	7.4 (Berkeley) 6/28/90  */
end_comment

begin_comment
comment|/*  * Tcp+ip header, after ip options removed.  */
end_comment

begin_struct
struct|struct
name|tcpiphdr
block|{
name|struct
name|ipovly
name|ti_i
decl_stmt|;
comment|/* overlaid ip structure */
name|struct
name|tcphdr
name|ti_t
decl_stmt|;
comment|/* tcp header */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ti_next
value|ti_i.ih_next
end_define

begin_define
define|#
directive|define
name|ti_prev
value|ti_i.ih_prev
end_define

begin_define
define|#
directive|define
name|ti_x1
value|ti_i.ih_x1
end_define

begin_define
define|#
directive|define
name|ti_pr
value|ti_i.ih_pr
end_define

begin_define
define|#
directive|define
name|ti_len
value|ti_i.ih_len
end_define

begin_define
define|#
directive|define
name|ti_src
value|ti_i.ih_src
end_define

begin_define
define|#
directive|define
name|ti_dst
value|ti_i.ih_dst
end_define

begin_define
define|#
directive|define
name|ti_sport
value|ti_t.th_sport
end_define

begin_define
define|#
directive|define
name|ti_dport
value|ti_t.th_dport
end_define

begin_define
define|#
directive|define
name|ti_seq
value|ti_t.th_seq
end_define

begin_define
define|#
directive|define
name|ti_ack
value|ti_t.th_ack
end_define

begin_define
define|#
directive|define
name|ti_x2
value|ti_t.th_x2
end_define

begin_define
define|#
directive|define
name|ti_off
value|ti_t.th_off
end_define

begin_define
define|#
directive|define
name|ti_flags
value|ti_t.th_flags
end_define

begin_define
define|#
directive|define
name|ti_win
value|ti_t.th_win
end_define

begin_define
define|#
directive|define
name|ti_sum
value|ti_t.th_sum
end_define

begin_define
define|#
directive|define
name|ti_urp
value|ti_t.th_urp
end_define

end_unit

