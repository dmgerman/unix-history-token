begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: if_enreg.h,v 4.300 91/06/09 06:25:57 root Rel41 $ SONY  *  *	@(#)if_enreg.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * if_enreg.h for news800, news900  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__IF_ENREG__
end_ifndef

begin_define
define|#
directive|define
name|__IF_ENREG__
value|1
end_define

begin_comment
comment|/* command definitions */
end_comment

begin_define
define|#
directive|define
name|ENC_ADDR
value|0x00
end_define

begin_comment
comment|/* Get Ethernet address */
end_comment

begin_define
define|#
directive|define
name|ENC_DIAG
value|0x01
end_define

begin_comment
comment|/* Run On-board Diagnostics */
end_comment

begin_define
define|#
directive|define
name|ENC_START
value|0x02
end_define

begin_comment
comment|/* Go Online */
end_comment

begin_define
define|#
directive|define
name|ENC_RESET
value|0x03
end_define

begin_comment
comment|/* Reset */
end_comment

begin_define
define|#
directive|define
name|ENC_STAT
value|0x04
end_define

begin_comment
comment|/* Report and Reset Statistics */
end_comment

begin_define
define|#
directive|define
name|ENC_XMIT
value|0x05
end_define

begin_comment
comment|/* Load Transmit Data and Send */
end_comment

begin_define
define|#
directive|define
name|ENC_RECV
value|0x06
end_define

begin_comment
comment|/* Receive Data */
end_comment

begin_define
define|#
directive|define
name|ENC_PROM
value|0x07
end_define

begin_comment
comment|/* Set prom mode */
end_comment

begin_define
define|#
directive|define
name|ENC_SADDR
value|0x08
end_define

begin_comment
comment|/* Set Ethernet address */
end_comment

begin_define
define|#
directive|define
name|ENC_NEWIF
value|0x09
end_define

begin_comment
comment|/* Switch driver interface */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__IF_ENREG__ */
end_comment

end_unit

