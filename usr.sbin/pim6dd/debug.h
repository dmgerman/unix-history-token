begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Copyright (c) 1998 by the University of Southern California.  *  All rights reserved.  *  *  Permission to use, copy, modify, and distribute this software and  *  its documentation in source and binary forms for lawful  *  purposes and without fee is hereby granted, provided  *  that the above copyright notice appear in all copies and that both  *  the copyright notice and this permission notice appear in supporting  *  documentation, and that any documentation, advertising materials,  *  and other materials related to such distribution and use acknowledge  *  that the software was developed by the University of Southern  *  California and/or Information Sciences Institute.  *  The name of the University of Southern California may not  *  be used to endorse or promote products derived from this software  *  without specific prior written permission.  *  *  THE UNIVERSITY OF SOUTHERN CALIFORNIA DOES NOT MAKE ANY REPRESENTATIONS  *  ABOUT THE SUITABILITY OF THIS SOFTWARE FOR ANY PURPOSE.  THIS SOFTWARE IS  *  PROVIDED "AS IS" AND WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES,  *  INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  *  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, TITLE, AND   *  NON-INFRINGEMENT.  *  *  IN NO EVENT SHALL USC, OR ANY OTHER CONTRIBUTOR BE LIABLE FOR ANY  *  SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, WHETHER IN CONTRACT,  *  TORT, OR OTHER FORM OF ACTION, ARISING OUT OF OR IN CONNECTION WITH,  *  THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  *  Other copyrights might apply to parts of this software and are so  *  noted when applicable.  */
end_comment

begin_comment
comment|/*  *  Questions concerning this software should be directed to   *  Pavlin Ivanov Radoslavov (pavlin@catarina.usc.edu)  *  *  $Id: debug.h,v 1.1.1.1 1999/08/08 23:30:52 itojun Exp $  */
end_comment

begin_comment
comment|/*  * Part of this program has been derived from mrouted.  * The mrouted program is covered by the license in the accompanying file  * named "LICENSE.mrouted".  *  * The mrouted program is COPYRIGHT 1989 by The Board of Trustees of  * Leland Stanford Junior University.  *  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|log_nmsgs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IF_DEBUG
parameter_list|(
name|l
parameter_list|)
value|if (debug&& debug& (l))
end_define

begin_define
define|#
directive|define
name|LOG_MAX_MSGS
value|20
end_define

begin_comment
comment|/* if> 20/minute then shut up for a while */
end_comment

begin_define
define|#
directive|define
name|LOG_SHUT_UP
value|600
end_define

begin_comment
comment|/* shut up for 10 minutes */
end_comment

begin_comment
comment|/* Debug values definition */
end_comment

begin_comment
comment|/* DVMRP reserved for future use */
end_comment

begin_define
define|#
directive|define
name|DEBUG_DVMRP_PRUNE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DEBUG_DVMRP_ROUTE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DEBUG_DVMRP_PEER
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DEBUG_DVMRP_TIMER
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DEBUG_DVMRP_DETAIL
value|0x01000000
end_define

begin_define
define|#
directive|define
name|DEBUG_DVMRP
value|( DEBUG_DVMRP_PRUNE | DEBUG_DVMRP_ROUTE | \ 				DEBUG_DVMRP_PEER )
end_define

begin_comment
comment|/* MLD related */
end_comment

begin_define
define|#
directive|define
name|DEBUG_MLD_PROTO
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DEBUG_MLD_TIMER
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DEBUG_MLD_MEMBER
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DEBUG_MEMBER
value|DEBUG_MLD_MEMBER
end_define

begin_define
define|#
directive|define
name|DEBUG_MLD
value|( DEBUG_MLD_PROTO | DEBUG_MLD_TIMER | \ 				DEBUG_MLD_MEMBER )
end_define

begin_comment
comment|/* Misc */
end_comment

begin_define
define|#
directive|define
name|DEBUG_TRACE
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DEBUG_TIMEOUT
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DEBUG_PKT
value|0x00000200
end_define

begin_comment
comment|/* Kernel related */
end_comment

begin_define
define|#
directive|define
name|DEBUG_IF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DEBUG_KERN
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DEBUG_MFC
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DEBUG_RSRR
value|0x00002000
end_define

begin_comment
comment|/* PIM related */
end_comment

begin_define
define|#
directive|define
name|DEBUG_PIM_GRAFT
value|0x02000000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_HELLO
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_REGISTER
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_JOIN_PRUNE
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_BOOTSTRAP
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_ASSERT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_CAND_RP
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_MRT
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_TIMER
value|0x00200000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_RPF
value|0x00400000
end_define

begin_define
define|#
directive|define
name|DEBUG_RPF
value|DEBUG_PIM_RPF
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM_DETAIL
value|0x00800000
end_define

begin_define
define|#
directive|define
name|DEBUG_PIM
value|( DEBUG_PIM_HELLO | DEBUG_PIM_REGISTER | \ 				DEBUG_PIM_JOIN_PRUNE | DEBUG_PIM_BOOTSTRAP | \ 				DEBUG_PIM_ASSERT | DEBUG_PIM_CAND_RP | \ 				DEBUG_PIM_MRT | DEBUG_PIM_TIMER | \ 				DEBUG_PIM_RPF | DEBUG_PIM_GRAFT )
end_define

begin_define
define|#
directive|define
name|DEBUG_MRT
value|( DEBUG_DVMRP_ROUTE | DEBUG_PIM_MRT )
end_define

begin_define
define|#
directive|define
name|DEBUG_NEIGHBORS
value|( DEBUG_DVMRP_PEER | DEBUG_PIM_HELLO )
end_define

begin_define
define|#
directive|define
name|DEBUG_TIMER
value|( DEBUG_MLD_TIMER | DEBUG_DVMRP_TIMER | \ 				DEBUG_PIM_TIMER )
end_define

begin_define
define|#
directive|define
name|DEBUG_ASSERT
value|( DEBUG_PIM_ASSERT )
end_define

begin_define
define|#
directive|define
name|DEBUG_ALL
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|DEBUG_DEFAULT
value|0xffffffff
end_define

begin_comment
comment|/*  default if "-d" given without value */
end_comment

end_unit

