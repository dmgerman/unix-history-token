begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_cnwioctl.h,v 1.2 1999/11/29 12:54:00 itojun Exp $	*/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996, 1997 Berkeley Software Design, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that this notice is retained,  * the conditions in the following notices are met, and terms applying  * to contributors in the following notices also apply to Berkeley  * Software Design, Inc.  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by  *	Berkeley Software Design, Inc.  * 4. Neither the name of the Berkeley Software Design, Inc. nor the names  *    of its contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY BERKELEY SOFTWARE DESIGN, INC. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL BERKELEY SOFTWARE DESIGN, INC. BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	PAO2 Id: if_cnwioctl.h,v 1.1.8.1 1998/12/05 22:47:11 itojun Exp  *  * Paul Borman, December 1996  *  * This driver is derived from a generic frame work which is  * Copyright(c) 1994,1995,1996  * Yoichi Shinoda, Yoshitaka Tokugawa, WIDE Project, Wildboar Project  * and Foretune.  All rights reserved.  *  * A linux driver was used as the "hardware reference manual" (i.e.,  * to determine registers and a general outline of how the card works)  * That driver is publically available and copyright  *  * John Markus Bj
comment|Nxrndalen  * Department of Computer Science  * University of Troms
comment|Nx  * Norway               * johnm@staff.cs.uit.no, http://www.cs.uit.no/~johnm/  */
end_comment

begin_struct
struct|struct
name|cnwstatus
block|{
name|struct
name|ifreq
name|ifr
decl_stmt|;
name|u_char
name|data
index|[
literal|0x100
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cnwstats
block|{
name|u_quad_t
name|nws_rx
decl_stmt|;
name|u_quad_t
name|nws_rxerr
decl_stmt|;
name|u_quad_t
name|nws_rxoverflow
decl_stmt|;
name|u_quad_t
name|nws_rxoverrun
decl_stmt|;
name|u_quad_t
name|nws_rxcrcerror
decl_stmt|;
name|u_quad_t
name|nws_rxframe
decl_stmt|;
name|u_quad_t
name|nws_rxerrors
decl_stmt|;
name|u_quad_t
name|nws_rxavail
decl_stmt|;
name|u_quad_t
name|nws_rxone
decl_stmt|;
name|u_quad_t
name|nws_tx
decl_stmt|;
name|u_quad_t
name|nws_txokay
decl_stmt|;
name|u_quad_t
name|nws_txabort
decl_stmt|;
name|u_quad_t
name|nws_txlostcd
decl_stmt|;
name|u_quad_t
name|nws_txerrors
decl_stmt|;
name|u_quad_t
name|nws_txretries
index|[
literal|16
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cnwistats
block|{
name|struct
name|ifreq
name|ifr
decl_stmt|;
name|struct
name|cnwstats
name|stats
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cnwtrail
block|{
name|u_char
name|what
decl_stmt|;
name|u_char
name|status
decl_stmt|;
name|u_short
name|length
decl_stmt|;
name|struct
name|timeval
name|when
decl_stmt|;
name|struct
name|timeval
name|done
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cnwitrail
block|{
name|struct
name|ifreq
name|ifr
decl_stmt|;
name|int
name|head
decl_stmt|;
name|struct
name|cnwtrail
name|trail
index|[
literal|128
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ifr_domain
value|ifr_ifru.ifru_flags
end_define

begin_comment
comment|/* domain */
end_comment

begin_define
define|#
directive|define
name|ifr_key
value|ifr_ifru.ifru_flags
end_define

begin_comment
comment|/* scramble key */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ifr_domain
value|ifr_flags
end_define

begin_comment
comment|/* domain */
end_comment

begin_define
define|#
directive|define
name|ifr_key
value|ifr_flags
end_define

begin_comment
comment|/* scramble key */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SIOCSCNWDOMAIN
value|_IOW('i', 254, struct ifreq)
end_define

begin_comment
comment|/* set domain */
end_comment

begin_define
define|#
directive|define
name|SIOCGCNWDOMAIN
value|_IOWR('i', 253, struct ifreq)
end_define

begin_comment
comment|/* get domain */
end_comment

begin_define
define|#
directive|define
name|SIOCSCNWKEY
value|_IOWR('i', 252, struct ifreq)
end_define

begin_comment
comment|/* set scramble key */
end_comment

begin_define
define|#
directive|define
name|SIOCGCNWSTATUS
value|_IOWR('i', 251, struct cnwstatus)
end_define

begin_comment
comment|/* get raw status */
end_comment

begin_define
define|#
directive|define
name|SIOCGCNWSTATS
value|_IOWR('i', 250, struct cnwistats)
end_define

begin_comment
comment|/* get stats */
end_comment

begin_define
define|#
directive|define
name|SIOCGCNWTRAIL
value|_IOWR('i', 249, struct cnwitrail)
end_define

begin_comment
comment|/* get trail */
end_comment

end_unit

