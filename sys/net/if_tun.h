begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_tun.h,v 1.5 1994/06/29 06:36:27 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1988, Julian Onions<jpo@cs.nott.ac.uk>  * Nottingham University 1987.  *  * This source may be freely distributed, however I would be interested  * in any changes that are made.  *  * This driver takes packets off the IP i/f and hands them up to a  * user process to have it's wicked way with. This driver has it's  * roots in a similar driver written by Phil Cockcroft (formerly) at  * UCL. This driver is based much more on read/write/select mode of  * operation though.  *  * : $Header: if_tnreg.h,v 1.1.2.1 1992/07/16 22:39:16 friedl Exp  */
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
name|TUN_READY
value|(TUN_OPEN | TUN_INITED)
name|struct
name|ifnet
name|tun_if
decl_stmt|;
comment|/* the interface */
name|int
name|tun_pgrp
decl_stmt|;
comment|/* the process group - if any */
name|struct
name|selinfo
name|tun_rsel
decl_stmt|;
comment|/* read select */
name|struct
name|selinfo
name|tun_wsel
decl_stmt|;
comment|/* write select (not used) */
block|}
struct|;
end_struct

begin_comment
comment|/* Maximum transmit packet size (default) */
end_comment

begin_define
define|#
directive|define
name|TUNMTU
value|1500
end_define

begin_comment
comment|/* Maximum receive packet size (hard limit) */
end_comment

begin_define
define|#
directive|define
name|TUNMRU
value|16384
end_define

begin_struct
struct|struct
name|tuninfo
block|{
name|int
name|baudrate
decl_stmt|;
comment|/* linespeed */
name|short
name|mtu
decl_stmt|;
comment|/* maximum transmission unit */
name|u_char
name|type
decl_stmt|;
comment|/* ethernet, tokenring, etc. */
name|u_char
name|dummy
decl_stmt|;
comment|/* place holder */
block|}
struct|;
end_struct

begin_comment
comment|/* ioctl's for get/set debug */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_IF_TUN_H_ */
end_comment

end_unit

