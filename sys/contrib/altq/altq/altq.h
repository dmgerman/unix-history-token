begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: altq.h,v 1.10 2003/07/10 12:07:47 kjc Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (C) 1998-2003  *	Sony Computer Science Laboratories Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY SONY CSL AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL SONY CSL OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALTQ_ALTQ_H_
end_ifndef

begin_define
define|#
directive|define
name|_ALTQ_ALTQ_H_
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * allow altq-3 (altqd(8) and /dev/altq) to coexist with the new pf-based altq.  * altq3 is mainly for research experiments. pf-based altq is for daily use.  */
end_comment

begin_define
define|#
directive|define
name|ALTQ3_COMPAT
end_define

begin_comment
comment|/* for compatibility with altq-3 */
end_comment

begin_define
define|#
directive|define
name|ALTQ3_CLFIER_COMPAT
end_define

begin_comment
comment|/* for compatibility with altq-3 classifier */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|IFNAMSIZ
end_ifndef

begin_define
define|#
directive|define
name|IFNAMSIZ
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTQ3_COMPAT */
end_comment

begin_comment
comment|/* altq discipline type */
end_comment

begin_define
define|#
directive|define
name|ALTQT_NONE
value|0
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|ALTQT_CBQ
value|1
end_define

begin_comment
comment|/* cbq */
end_comment

begin_define
define|#
directive|define
name|ALTQT_WFQ
value|2
end_define

begin_comment
comment|/* wfq */
end_comment

begin_define
define|#
directive|define
name|ALTQT_AFMAP
value|3
end_define

begin_comment
comment|/* afmap */
end_comment

begin_define
define|#
directive|define
name|ALTQT_FIFOQ
value|4
end_define

begin_comment
comment|/* fifoq */
end_comment

begin_define
define|#
directive|define
name|ALTQT_RED
value|5
end_define

begin_comment
comment|/* red */
end_comment

begin_define
define|#
directive|define
name|ALTQT_RIO
value|6
end_define

begin_comment
comment|/* rio */
end_comment

begin_define
define|#
directive|define
name|ALTQT_LOCALQ
value|7
end_define

begin_comment
comment|/* local use */
end_comment

begin_define
define|#
directive|define
name|ALTQT_HFSC
value|8
end_define

begin_comment
comment|/* hfsc */
end_comment

begin_define
define|#
directive|define
name|ALTQT_CDNR
value|9
end_define

begin_comment
comment|/* traffic conditioner */
end_comment

begin_define
define|#
directive|define
name|ALTQT_BLUE
value|10
end_define

begin_comment
comment|/* blue */
end_comment

begin_define
define|#
directive|define
name|ALTQT_PRIQ
value|11
end_define

begin_comment
comment|/* priority queue */
end_comment

begin_define
define|#
directive|define
name|ALTQT_JOBS
value|12
end_define

begin_comment
comment|/* JoBS */
end_comment

begin_define
define|#
directive|define
name|ALTQT_MAX
value|13
end_define

begin_comment
comment|/* should be max discipline type + 1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
end_ifdef

begin_struct
struct|struct
name|altqreq
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|u_long
name|arg
decl_stmt|;
comment|/* request-specific argument */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* simple token backet meter profile */
end_comment

begin_struct
struct|struct
name|tb_profile
block|{
name|u_int
name|rate
decl_stmt|;
comment|/* rate in bit-per-sec */
name|u_int
name|depth
decl_stmt|;
comment|/* depth in bytes */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
end_ifdef

begin_struct
struct|struct
name|tbrreq
block|{
name|char
name|ifname
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* if name, e.g. "en0" */
name|struct
name|tb_profile
name|tb_prof
decl_stmt|;
comment|/* token bucket profile */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_CLFIER_COMPAT
end_ifdef

begin_comment
comment|/*  * common network flow info structure  */
end_comment

begin_struct
struct|struct
name|flowinfo
block|{
name|u_char
name|fi_len
decl_stmt|;
comment|/* total length */
name|u_char
name|fi_family
decl_stmt|;
comment|/* address family */
name|u_int8_t
name|fi_data
index|[
literal|46
index|]
decl_stmt|;
comment|/* actually longer; address family 					   specific flow info. */
block|}
struct|;
end_struct

begin_comment
comment|/*  * flow info structure for internet protocol family.  * (currently this is the only protocol family supported)  */
end_comment

begin_struct
struct|struct
name|flowinfo_in
block|{
name|u_char
name|fi_len
decl_stmt|;
comment|/* sizeof(struct flowinfo_in) */
name|u_char
name|fi_family
decl_stmt|;
comment|/* AF_INET */
name|u_int8_t
name|fi_proto
decl_stmt|;
comment|/* IPPROTO_XXX */
name|u_int8_t
name|fi_tos
decl_stmt|;
comment|/* type-of-service */
name|struct
name|in_addr
name|fi_dst
decl_stmt|;
comment|/* dest address */
name|struct
name|in_addr
name|fi_src
decl_stmt|;
comment|/* src address */
name|u_int16_t
name|fi_dport
decl_stmt|;
comment|/* dest port */
name|u_int16_t
name|fi_sport
decl_stmt|;
comment|/* src port */
name|u_int32_t
name|fi_gpi
decl_stmt|;
comment|/* generalized port id for ipsec */
name|u_int8_t
name|_pad
index|[
literal|28
index|]
decl_stmt|;
comment|/* make the size equal to 					   flowinfo_in6 */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|SIN6_LEN
end_ifdef

begin_struct
struct|struct
name|flowinfo_in6
block|{
name|u_char
name|fi6_len
decl_stmt|;
comment|/* sizeof(struct flowinfo_in6) */
name|u_char
name|fi6_family
decl_stmt|;
comment|/* AF_INET6 */
name|u_int8_t
name|fi6_proto
decl_stmt|;
comment|/* IPPROTO_XXX */
name|u_int8_t
name|fi6_tclass
decl_stmt|;
comment|/* traffic class */
name|u_int32_t
name|fi6_flowlabel
decl_stmt|;
comment|/* ipv6 flowlabel */
name|u_int16_t
name|fi6_dport
decl_stmt|;
comment|/* dest port */
name|u_int16_t
name|fi6_sport
decl_stmt|;
comment|/* src port */
name|u_int32_t
name|fi6_gpi
decl_stmt|;
comment|/* generalized port id */
name|struct
name|in6_addr
name|fi6_dst
decl_stmt|;
comment|/* dest address */
name|struct
name|in6_addr
name|fi6_src
decl_stmt|;
comment|/* src address */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_comment
comment|/*  * flow filters for AF_INET and AF_INET6  */
end_comment

begin_struct
struct|struct
name|flow_filter
block|{
name|int
name|ff_ruleno
decl_stmt|;
name|struct
name|flowinfo_in
name|ff_flow
decl_stmt|;
struct|struct
block|{
name|struct
name|in_addr
name|mask_dst
decl_stmt|;
name|struct
name|in_addr
name|mask_src
decl_stmt|;
name|u_int8_t
name|mask_tos
decl_stmt|;
name|u_int8_t
name|_pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ff_mask
struct|;
name|u_int8_t
name|_pad2
index|[
literal|24
index|]
decl_stmt|;
comment|/* make the size equal to flow_filter6 */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|SIN6_LEN
end_ifdef

begin_struct
struct|struct
name|flow_filter6
block|{
name|int
name|ff_ruleno
decl_stmt|;
name|struct
name|flowinfo_in6
name|ff_flow6
decl_stmt|;
struct|struct
block|{
name|struct
name|in6_addr
name|mask6_dst
decl_stmt|;
name|struct
name|in6_addr
name|mask6_src
decl_stmt|;
name|u_int8_t
name|mask6_tclass
decl_stmt|;
name|u_int8_t
name|_pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|ff_mask6
struct|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INET6 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTQ3_CLFIER_COMPAT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTQ3_COMPAT */
end_comment

begin_comment
comment|/*  * generic packet counter  */
end_comment

begin_struct
struct|struct
name|pktcntr
block|{
name|u_int64_t
name|packets
decl_stmt|;
name|u_int64_t
name|bytes
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PKTCNTR_ADD
parameter_list|(
name|cntr
parameter_list|,
name|len
parameter_list|)
define|\
value|do { (cntr)->packets++; (cntr)->bytes += len; } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ALTQ3_COMPAT
end_ifdef

begin_comment
comment|/*  * altq related ioctls  */
end_comment

begin_define
define|#
directive|define
name|ALTQGTYPE
value|_IOWR('q', 0, struct altqreq)
end_define

begin_comment
comment|/* get queue type */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * these ioctls are currently discipline-specific but could be shared  * in the future.  */
end_comment

begin_define
define|#
directive|define
name|ALTQATTACH
value|_IOW('q', 1, struct altqreq)
end_define

begin_comment
comment|/* attach discipline */
end_comment

begin_define
define|#
directive|define
name|ALTQDETACH
value|_IOW('q', 2, struct altqreq)
end_define

begin_comment
comment|/* detach discipline */
end_comment

begin_define
define|#
directive|define
name|ALTQENABLE
value|_IOW('q', 3, struct altqreq)
end_define

begin_comment
comment|/* enable discipline */
end_comment

begin_define
define|#
directive|define
name|ALTQDISABLE
value|_IOW('q', 4, struct altqreq)
end_define

begin_comment
comment|/* disable discipline*/
end_comment

begin_define
define|#
directive|define
name|ALTQCLEAR
value|_IOW('q', 5, struct altqreq)
end_define

begin_comment
comment|/* (re)initialize */
end_comment

begin_define
define|#
directive|define
name|ALTQCONFIG
value|_IOWR('q', 6, struct altqreq)
end_define

begin_comment
comment|/* set config params */
end_comment

begin_define
define|#
directive|define
name|ALTQADDCLASS
value|_IOWR('q', 7, struct altqreq)
end_define

begin_comment
comment|/* add a class */
end_comment

begin_define
define|#
directive|define
name|ALTQMODCLASS
value|_IOWR('q', 8, struct altqreq)
end_define

begin_comment
comment|/* modify a class */
end_comment

begin_define
define|#
directive|define
name|ALTQDELCLASS
value|_IOWR('q', 9, struct altqreq)
end_define

begin_comment
comment|/* delete a class */
end_comment

begin_define
define|#
directive|define
name|ALTQADDFILTER
value|_IOWR('q', 10, struct altqreq)
end_define

begin_comment
comment|/* add a filter */
end_comment

begin_define
define|#
directive|define
name|ALTQDELFILTER
value|_IOWR('q', 11, struct altqreq)
end_define

begin_comment
comment|/* delete a filter */
end_comment

begin_define
define|#
directive|define
name|ALTQGETSTATS
value|_IOWR('q', 12, struct altqreq)
end_define

begin_comment
comment|/* get statistics */
end_comment

begin_define
define|#
directive|define
name|ALTQGETCNTR
value|_IOWR('q', 13, struct altqreq)
end_define

begin_comment
comment|/* get a pkt counter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|ALTQTBRSET
value|_IOW('q', 14, struct tbrreq)
end_define

begin_comment
comment|/* set tb regulator */
end_comment

begin_define
define|#
directive|define
name|ALTQTBRGET
value|_IOWR('q', 15, struct tbrreq)
end_define

begin_comment
comment|/* get tb regulator */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ALTQ3_COMPAT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<altq/altq_var.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ALTQ_ALTQ_H_ */
end_comment

end_unit

