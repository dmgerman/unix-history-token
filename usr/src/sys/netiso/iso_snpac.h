begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)iso_snpac.h	7.9 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_define
define|#
directive|define
name|MAX_SNPALEN
value|8
end_define

begin_comment
comment|/* curiously equal to sizeof x.121 ( 										plus 1 for nibble len) addr */
end_comment

begin_struct
struct|struct
name|snpa_req
block|{
name|struct
name|iso_addr
name|sr_isoa
decl_stmt|;
comment|/* nsap address */
name|u_char
name|sr_len
decl_stmt|;
comment|/* length of snpa */
name|u_char
name|sr_snpa
index|[
name|MAX_SNPALEN
index|]
decl_stmt|;
comment|/* snpa associated  												with nsap address */
name|u_char
name|sr_flags
decl_stmt|;
comment|/* true if entry is valid */
name|u_short
name|sr_ht
decl_stmt|;
comment|/* holding time */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SNPA_VALID
value|0x01
end_define

begin_define
define|#
directive|define
name|SNPA_ES
value|0x02
end_define

begin_define
define|#
directive|define
name|SNPA_IS
value|0x04
end_define

begin_define
define|#
directive|define
name|SNPA_PERM
value|0x10
end_define

begin_struct
struct|struct
name|systype_req
block|{
name|short
name|sr_holdt
decl_stmt|;
comment|/* holding timer */
name|short
name|sr_configt
decl_stmt|;
comment|/* configuration timer */
name|short
name|sr_esconfigt
decl_stmt|;
comment|/* suggested ES configuration timer */
name|char
name|sr_type
decl_stmt|;
comment|/* SNPA_ES or SNPA_IS */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|esis_req
block|{
name|short
name|er_ht
decl_stmt|;
comment|/* holding time */
name|u_char
name|er_flags
decl_stmt|;
comment|/* type and validity */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Space for this structure gets added onto the end of a route  * going to an ethernet or other 802.[45x] device.  */
end_comment

begin_struct
struct|struct
name|llinfo_llc
block|{
name|struct
name|llinfo_llc
modifier|*
name|lc_next
decl_stmt|;
comment|/* keep all llc routes linked */
name|struct
name|llinfo_llc
modifier|*
name|lc_prev
decl_stmt|;
comment|/* keep all llc routes linked */
name|struct
name|rtentry
modifier|*
name|lc_rt
decl_stmt|;
comment|/* backpointer to route */
name|struct
name|esis_req
name|lc_er
decl_stmt|;
comment|/* holding time, etc */
define|#
directive|define
name|lc_ht
value|lc_er.er_ht
define|#
directive|define
name|lc_flags
value|lc_er.er_flags
block|}
struct|;
end_struct

begin_comment
comment|/* ISO arp IOCTL data structures */
end_comment

begin_define
define|#
directive|define
name|SIOCSSTYPE
value|_IOW('a', 39, struct systype_req)
end_define

begin_comment
comment|/* set system type */
end_comment

begin_define
define|#
directive|define
name|SIOCGSTYPE
value|_IOR('a', 40, struct systype_req)
end_define

begin_comment
comment|/* get system type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|struct
name|llinfo_llc
name|llinfo_llc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* head for linked lists */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

