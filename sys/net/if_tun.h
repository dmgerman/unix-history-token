begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, Julian Onions<jpo@cs.nott.ac.uk>  * Nottingham University 1987.  *  * This source may be freely distributed, however I would be interested  * in any changes that are made.  *  * This driver takes packets off the IP i/f and hands them up to a  * user process to have it's wicked way with. This driver has it's  * roots in a similar driver written by Phil Cockcroft (formerly) at  * UCL. This driver is based much more on read/write/select mode of  * operation though.  *   * from: $Header: if_tnreg.h,v 1.1.2.1 1992/07/16 22:39:16 friedl Exp  * $Id: if_tun.h,v 1.3 1993/12/13 14:27:01 deraadt Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_IF_TUN_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_IF_TUN_H_
end_define

begin_struct
struct|struct
name|tun_softc
block|{
name|u_short
name|tun_flags
decl_stmt|;
comment|/* misc flags */
define|#
directive|define
name|TUN_OPEN
value|0x0001
define|#
directive|define
name|TUN_INITED
value|0x0002
define|#
directive|define
name|TUN_RCOLL
value|0x0004
define|#
directive|define
name|TUN_IASET
value|0x0008
define|#
directive|define
name|TUN_DSTADDR
value|0x0010
ifdef|#
directive|ifdef
name|notdef
define|#
directive|define
name|TUN_READY
value|0x0020
else|#
directive|else
define|#
directive|define
name|TUN_READY
value|(TUN_IASET|TUN_OPEN|TUN_DSTADDR)
endif|#
directive|endif
define|#
directive|define
name|TUN_RWAIT
value|0x0040
define|#
directive|define
name|TUN_ASYNC
value|0x0080
define|#
directive|define
name|TUN_NBIO
value|0x0100
name|struct
name|ifnet
name|tun_if
decl_stmt|;
comment|/* the interface */
name|int
name|tun_pgrp
decl_stmt|;
comment|/* the process group - if any */
if|#
directive|if
name|BSD
operator|<
literal|199103
name|struct
name|proc
modifier|*
name|tun_rsel
decl_stmt|;
name|struct
name|proc
modifier|*
name|tun_wsel
decl_stmt|;
else|#
directive|else
name|u_char
name|tun_pad
decl_stmt|;
comment|/* explicit alignment */
name|struct
name|selinfo
name|tun_sel
decl_stmt|;
comment|/* bsd select info */
endif|#
directive|endif
if|#
directive|if
name|NBPFILTER
operator|>
literal|0
name|caddr_t
name|tun_bpf
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* Maximum packet size */
end_comment

begin_define
define|#
directive|define
name|TUNMTU
value|1500
end_define

begin_comment
comment|/* ioctl's for get/set debug */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__NetBSD__
end_ifdef

begin_define
define|#
directive|define
name|TUNSDEBUG
value|_IOW('t', 90, int)
end_define

begin_define
define|#
directive|define
name|TUNGDEBUG
value|_IOR('t', 89, int)
end_define

begin_define
define|#
directive|define
name|TUNSIFINFO
value|_IOW('t', 91, struct tuninfo)
end_define

begin_define
define|#
directive|define
name|TUNGIFINFO
value|_IOR('t', 92, struct tuninfo)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Assume BSDI */
end_comment

begin_define
define|#
directive|define
name|TUNSDEBUG
value|_IOW('T', 90, int)
end_define

begin_define
define|#
directive|define
name|TUNGDEBUG
value|_IOR('T', 89, int)
end_define

begin_define
define|#
directive|define
name|TUNSIFINFO
value|_IOW('T', 91, struct tuninfo)
end_define

begin_define
define|#
directive|define
name|TUNGIFINFO
value|_IOR('T', 92, struct tuninfo)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|tuninfo
block|{
name|int
name|tif_baudrate
decl_stmt|;
comment|/* linespeed */
name|short
name|tif_mtu
decl_stmt|;
comment|/* maximum transmission unit */
name|u_char
name|tif_type
decl_stmt|;
comment|/* ethernet, tokenring, etc. */
name|u_char
name|tif_dummy
decl_stmt|;
comment|/* place holder */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_TUN_H_ */
end_comment

end_unit

