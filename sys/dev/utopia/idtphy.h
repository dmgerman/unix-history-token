begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  *  * Register definitions for the following chips:  *	IDT 77105  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_UTOPIA_IDTPHY_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_UTOPIA_IDTPHY_H
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_MCR
value|0x00
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_MCR
value|"Master Control Register"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_MCR
value|"\020\010UPLO\7DREC\6ECEI\5TDPC\4DRIC\3HALTTX\2BYTEM\1EI"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCR_UPL0
value|0x80
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCR_DREC
value|0x40
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCR_ECEI
value|0x20
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCR_TDPC
value|0x10
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCR_DRIC
value|0x08
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCR_HALTTX
value|0x04
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCR_BYTEM
value|0x02
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCR_EI
value|0x01
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_ISTAT
value|0x01
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_ISTAT
value|"Interrupt Status"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_ISTAT
value|"\020\7GOOD\6HECE\5SCRE\4TPE\3RSCC\2RSE\1RFO"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_ISTAT_GOOD
value|0x40
end_define

begin_comment
comment|/* good signal bit */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_ISTAT_HECE
value|0x20
end_define

begin_comment
comment|/* HEC error */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_ISTAT_SCRE
value|0x10
end_define

begin_comment
comment|/* short cell received error */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_ISTAT_TPE
value|0x08
end_define

begin_comment
comment|/* transmit parity error */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_ISTAT_RSCC
value|0x04
end_define

begin_comment
comment|/* receive signal condition change */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_ISTAT_RSE
value|0x02
end_define

begin_comment
comment|/* receive symbol error */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_ISTAT_RFO
value|0x01
end_define

begin_comment
comment|/* read FIFO overrun */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGO_DIAG
value|0x02
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_DIAG
value|"Diagnostic Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_DIAG
value|"\020\010FTD\7ROS\6MULTI\5RFLUSH\4ITPE\3IHECE\11\3\0NORM\11\3\2PLOOP\11\3\3LLOOP"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_DIAG_FTD
value|0x80
end_define

begin_comment
comment|/* Force TxClav Deassert */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_DIAG_ROS
value|0x40
end_define

begin_comment
comment|/* RxClav Operation Select */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_DIAG_MULTI
value|0x20
end_define

begin_comment
comment|/* Multi-phy operation */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_DIAG_RFLUSH
value|0x10
end_define

begin_comment
comment|/* clear receive Fifo */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_DIAG_ITPE
value|0x08
end_define

begin_comment
comment|/* insert transmit payload error */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_DIAG_IHECE
value|0x04
end_define

begin_comment
comment|/* insert transmit HEC error */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_DIAG_LOOP
value|0x03
end_define

begin_comment
comment|/* loopback mode */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_DIAG_LOOP_NONE
value|0x00
end_define

begin_comment
comment|/* normal */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_DIAG_LOOP_PHY
value|0x02
end_define

begin_comment
comment|/* PHY loopback */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_DIAG_LOOP_LINE
value|0x03
end_define

begin_comment
comment|/* Line loopback */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGO_LHEC
value|0x03
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_LHEC
value|"LED Driver and HEC Status/Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_LHEC
value|"\020\7DRHEC\6DTHEC\11\x18\0CYC1\11\x18\1CYC2\11\x18\2CYC4\11\x18\3CYC8\3FIFOE\2TXLED\1RXLED"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_LHEC_DRHEC
value|0x40
end_define

begin_comment
comment|/* disable receive HEC */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_LHEC_DTHEC
value|0x20
end_define

begin_comment
comment|/* disable transmit HEC */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_LHEC_RXREF
value|0x18
end_define

begin_comment
comment|/* RxRef pulse width */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_LHEC_RXREF1
value|0x00
end_define

begin_comment
comment|/* 1 pulse */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_LHEC_RXREF2
value|0x08
end_define

begin_comment
comment|/* 2 pulse */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_LHEC_RXREF4
value|0x10
end_define

begin_comment
comment|/* 4 pulse */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_LHEC_RXREF8
value|0x18
end_define

begin_comment
comment|/* 8 pulse */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_LHEC_FIFOE
value|0x04
end_define

begin_comment
comment|/* Fifo empty */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_LHEC_TXLED
value|0x02
end_define

begin_comment
comment|/* Tx LED status */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_LHEC_RXLED
value|0x01
end_define

begin_comment
comment|/* Rx LED status */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGO_CNT
value|0x04
end_define

begin_comment
comment|/* +0x05 */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGN_CNT
value|"Counter"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_CNTS
value|0x06
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_CNTS
value|"Counter select"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_CNTS
value|"\020\4SEC\3TX\2RX\1HECE"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_CNTS_SEC
value|0x08
end_define

begin_comment
comment|/* symbol error counter */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_CNTS_TX
value|0x04
end_define

begin_comment
comment|/* Tx cells */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_CNTS_RX
value|0x02
end_define

begin_comment
comment|/* Rx cells */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_CNTS_HECE
value|0x01
end_define

begin_comment
comment|/* HEC errors */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_PRINT_77105
define|\
value|{
comment|/* 00 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_MCR,		\ 	  IDTPHY_REGN_MCR,	IDTPHY_REGX_MCR },		\ 	{
comment|/* 01 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_ISTAT,		\ 	  IDTPHY_REGN_ISTAT,	IDTPHY_REGX_ISTAT },		\ 	{
comment|/* 02 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_DIAG,		\ 	  IDTPHY_REGN_DIAG,	IDTPHY_REGX_DIAG },		\ 	{
comment|/* 03 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_LHEC,		\ 	  IDTPHY_REGN_LHEC,	IDTPHY_REGX_LHEC },		\ 	{
comment|/* 04, 05 */
value|\ 	  UTP_REGT_INT16,	IDTPHY_REGO_CNT,		\ 	  IDTPHY_REGN_CNT,	NULL },				\ 	{
comment|/* 06 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_CNTS,		\ 	  IDTPHY_REGN_CNTS,	IDTPHY_REGX_CNTS }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_UTOPIA_IDTPHY_H */
end_comment

end_unit

