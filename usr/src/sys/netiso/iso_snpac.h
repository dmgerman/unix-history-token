begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** 		Copyright IBM Corporation 1987                        All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the name of IBM not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    IBM DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL IBM BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_comment
comment|/*  * ARGO Project, Computer Sciences Dept., University of Wisconsin - Madison  */
end_comment

begin_comment
comment|/*	@(#)iso_snpac.h	7.3 (Berkeley) %G% */
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

begin_comment
comment|/*  *	Structure of the SNPA cache  */
end_comment

begin_struct
struct|struct
name|snpa_cache
block|{
name|struct
name|snpa_req
name|sc_sr
decl_stmt|;
define|#
directive|define
name|sc_nsap
value|sc_sr.sr_isoa
comment|/* this could be a NET if entry is 											for an IS */
define|#
directive|define
name|sc_len
value|sc_sr.sr_len
define|#
directive|define
name|sc_snpa
value|sc_sr.sr_snpa
define|#
directive|define
name|sc_ht
value|sc_sr.sr_ht
define|#
directive|define
name|sc_flags
value|sc_sr.sr_flags
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
define|#
directive|define
name|SNPA_VALID
value|0x01
define|#
directive|define
name|SNPA_ES
value|0x02
define|#
directive|define
name|SNPA_IS
value|0x04
define|#
directive|define
name|SNPA_PERM
value|0x10
comment|/* redirects only */
name|struct
name|iso_addr
name|sc_da
decl_stmt|;
comment|/* DA from RD */
name|struct
name|rtentry
modifier|*
name|sc_rt
decl_stmt|;
block|}
struct|;
end_struct

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
name|char
name|sr_type
decl_stmt|;
comment|/* SNPA_ES or SNPA_IS */
block|}
struct|;
end_struct

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
value|_IOW('a', 40, struct systype_req)
end_define

begin_comment
comment|/* set system type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_function_decl
name|struct
name|snpa_cache
modifier|*
name|snpac_look
parameter_list|(
comment|/* struct iso_addr *isoa */
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|KERNEL
end_endif

end_unit

