begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	OpenBSD: qsphyreg.h,v 1.2 1999/03/09 00:02:45 jason Exp 	*/
end_comment

begin_comment
comment|/*	NetBSD: qsphyreg.h,v 1.1 1998/08/11 00:01:03 thorpej Exp 	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1998 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe of the Numerical Aerospace Simulation Facility,  * NASA Ames Research Center.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_MII_QSPHYREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_MII_QSPHYREG_H_
end_define

begin_comment
comment|/*  * Register definitions for the Quality Semiconductor QS6612  * Further documentation can be found at:  * 	http://www.qualitysemi.com/products/network.html  */
end_comment

begin_define
define|#
directive|define
name|MII_QSPHY_MCTL
value|0x11
end_define

begin_comment
comment|/* Mode control */
end_comment

begin_define
define|#
directive|define
name|MCTL_T4PRE
value|0x1000
end_define

begin_comment
comment|/* 100baseT4 interface present */
end_comment

begin_define
define|#
directive|define
name|MCTL_BTEXT
value|0x0800
end_define

begin_comment
comment|/* reduce 10baseT squelch level */
end_comment

begin_define
define|#
directive|define
name|MCTL_FACTTEST
value|0x0100
end_define

begin_comment
comment|/* factory test mode */
end_comment

begin_define
define|#
directive|define
name|MCTL_PHYADDRMASK
value|0x00f8
end_define

begin_comment
comment|/* PHY address */
end_comment

begin_define
define|#
directive|define
name|MCTL_FACTTEST2
value|0x0004
end_define

begin_comment
comment|/* another factory test mode */
end_comment

begin_define
define|#
directive|define
name|MCTL_NLPDIS
value|0x0002
end_define

begin_comment
comment|/* disable link pulse tx */
end_comment

begin_define
define|#
directive|define
name|MCTL_SQEDIS
value|0x0001
end_define

begin_comment
comment|/* disable SQE */
end_comment

begin_define
define|#
directive|define
name|MII_QSPHY_ISRC
value|0x1d
end_define

begin_comment
comment|/* Interrupt source */
end_comment

begin_define
define|#
directive|define
name|MII_QSPHY_IMASK
value|0x1e
end_define

begin_comment
comment|/* Interrupt mask */
end_comment

begin_define
define|#
directive|define
name|IMASK_TLINTR
value|0x8000
end_define

begin_comment
comment|/* ThunderLAN interrupt mode */
end_comment

begin_define
define|#
directive|define
name|IMASK_ANCPL
value|0x0040
end_define

begin_comment
comment|/* autonegotiation complete */
end_comment

begin_define
define|#
directive|define
name|IMASK_RFD
value|0x0020
end_define

begin_comment
comment|/* remote fault detected */
end_comment

begin_define
define|#
directive|define
name|IMASK_LD
value|0x0010
end_define

begin_comment
comment|/* link down */
end_comment

begin_define
define|#
directive|define
name|IMASK_ANLPA
value|0x0008
end_define

begin_comment
comment|/* autonegotiation LP ACK */
end_comment

begin_define
define|#
directive|define
name|IMASK_PDT
value|0x0004
end_define

begin_comment
comment|/* parallel detection fault */
end_comment

begin_define
define|#
directive|define
name|IMASK_ANPR
value|0x0002
end_define

begin_comment
comment|/* autonegotiation page received */
end_comment

begin_define
define|#
directive|define
name|IMASK_REF
value|0x0001
end_define

begin_comment
comment|/* receive error counter full */
end_comment

begin_define
define|#
directive|define
name|MII_QSPHY_PCTL
value|0x1f
end_define

begin_comment
comment|/* PHY control */
end_comment

begin_define
define|#
directive|define
name|PCTL_RXERDIS
value|0x2000
end_define

begin_comment
comment|/* receive error counter disable */
end_comment

begin_define
define|#
directive|define
name|PCTL_ANC
value|0x1000
end_define

begin_comment
comment|/* autonegotiation complete */
end_comment

begin_define
define|#
directive|define
name|PCTL_RLBEN
value|0x0200
end_define

begin_comment
comment|/* remote coopback enable */
end_comment

begin_define
define|#
directive|define
name|PCTL_DCREN
value|0x0100
end_define

begin_comment
comment|/* DC restoration enable */
end_comment

begin_define
define|#
directive|define
name|PCTL_4B5BEN
value|0x0040
end_define

begin_comment
comment|/* 4b/5b encoding */
end_comment

begin_define
define|#
directive|define
name|PCTL_PHYISO
value|0x0020
end_define

begin_comment
comment|/* isolate PHY */
end_comment

begin_define
define|#
directive|define
name|PCTL_OPMASK
value|0x001c
end_define

begin_comment
comment|/* operation mode mask */
end_comment

begin_define
define|#
directive|define
name|PCTL_AN
value|0x0000
end_define

begin_comment
comment|/* autonegotiation in-progress */
end_comment

begin_define
define|#
directive|define
name|PCTL_10_T
value|0x0004
end_define

begin_comment
comment|/* 10baseT */
end_comment

begin_define
define|#
directive|define
name|PCTL_100_TX
value|0x0008
end_define

begin_comment
comment|/* 100baseTX */
end_comment

begin_define
define|#
directive|define
name|PCTL_100_T4
value|0x0010
end_define

begin_comment
comment|/* 100baseT4 */
end_comment

begin_define
define|#
directive|define
name|PCTL_10_T_FDX
value|0x0014
end_define

begin_comment
comment|/* 10baseT-FDX */
end_comment

begin_define
define|#
directive|define
name|PCTL_100_TX_FDX
value|0x0018
end_define

begin_comment
comment|/* 100baseTX-FDX */
end_comment

begin_define
define|#
directive|define
name|PCTL_MLT3DIS
value|0x0002
end_define

begin_comment
comment|/* disable MLT3 */
end_comment

begin_define
define|#
directive|define
name|PCTL_SRCDIS
value|0x0001
end_define

begin_comment
comment|/* disable scrambling */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_MII_QSPHYREG_H_ */
end_comment

end_unit

