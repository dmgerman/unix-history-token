begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  *  * Register definitions for the following chips:  *	IDT 77105  *	IDT 77155  */
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

begin_define
define|#
directive|define
name|IDTPHY_REGO_MRID
value|0x00
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_MRID
value|"Master Reset& ID"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_MRID_RESET
value|0x80
end_define

begin_comment
comment|/* software reset */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MRID_TYPE
value|0x70
end_define

begin_comment
comment|/* type */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MRID_155
value|0x30
end_define

begin_comment
comment|/* idt77155 type */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MRID_ID
value|0x0f
end_define

begin_comment
comment|/* revision */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_MRID
define|\
value|"\020\010mstReset\12\x70\12type\12\xf\12id"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_CONF
value|0x01
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_CONF
value|"Configuration"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_CONF_AFEBE
value|0x40
end_define

begin_comment
comment|/* autoFEBE */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_CONF_ALRDI
value|0x20
end_define

begin_comment
comment|/* autoLRDI */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_CONF_APRDI
value|0x10
end_define

begin_comment
comment|/* autoPRDI */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_CONF_TCAIN
value|0x08
end_define

begin_comment
comment|/* TCAInv */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_CONF_RCAIN
value|0x04
end_define

begin_comment
comment|/* RCAInv */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_CONF_RXDIN
value|0x02
end_define

begin_comment
comment|/* RXDInv */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_CONF_RESV
value|0x81
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_CONF
define|\
value|"\020\07autoFEBE\6autoLRDI\5autoPRDI\4TCAInv\3RCAInv\2RXDInv"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_INT
value|0x02
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_INT
value|"Interrupt"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_INT_TXOOLI
value|0x80
end_define

begin_comment
comment|/* txOOLInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_INT_RXLOCI
value|0x40
end_define

begin_comment
comment|/* rxLOCInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_INT_RXOOLI
value|0x20
end_define

begin_comment
comment|/* rxOOLInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_INT_TXCDI
value|0x10
end_define

begin_comment
comment|/* txCDi */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_INT_RXCDI
value|0x08
end_define

begin_comment
comment|/* rxCDi */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_INT_RXPOHI
value|0x04
end_define

begin_comment
comment|/* rxPOHi */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_INT_RXLOHI
value|0x02
end_define

begin_comment
comment|/* rxLOHi */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_INT_RXSOHI
value|0x01
end_define

begin_comment
comment|/* rxSOHi */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_INT
define|\
value|"\020\10txOOLInt\7rxLOCInt\6rxOOLInt\5txCDi\4rxCDi\3rxPOHi" \ 	    "\2rxLOHi\1rxSOHi"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_MCM
value|0x04
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_MCM
value|"Master Clock Monitor"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCM_RRCLK
value|0x08
end_define

begin_comment
comment|/* rrclkReg */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCM_TRCLK
value|0x04
end_define

begin_comment
comment|/* trclkReg */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCM_RCLK
value|0x02
end_define

begin_comment
comment|/* rclkReg */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCM_TCLK
value|0x01
end_define

begin_comment
comment|/* tclkReg */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCM_RESV
value|0xf0
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_MCM
define|\
value|"\020\4rrclkReg\3trclkReg\2rclkReg\1tclkReg"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_MCTL
value|0x05
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_MCTL
value|"Master Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCTL_LOCI
value|0x80
end_define

begin_comment
comment|/* rxLOCIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCTL_LOC
value|0x40
end_define

begin_comment
comment|/* LOC */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCTL_FIXP
value|0x20
end_define

begin_comment
comment|/* txFixptr */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCTL_LLOOP
value|0x04
end_define

begin_comment
comment|/* txLLoop */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCTL_DLOOP
value|0x02
end_define

begin_comment
comment|/* rxDLoop */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCTL_TLOOP
value|0x01
end_define

begin_comment
comment|/* rxLoopT */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_MCTL_RESV
value|0x18
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_MCTL
define|\
value|"\020\10rxLOCIEn\7LOC\6txFixptr\3txLLoop\2rxDLoop\1rxLoopT"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TXC
value|0x06
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TXC
value|"Transmit Clock Synthesis C/S"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TXC_TXOOL
value|0x08
end_define

begin_comment
comment|/* txOOL */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TXC_TXOOLI
value|0x02
end_define

begin_comment
comment|/* txOOLIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TXC_TXREF
value|0x01
end_define

begin_comment
comment|/* txrefSel */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TXC_RESV
value|0xf4
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_TXC
define|\
value|"\020\4txOOL\2txOOLIEn\1txrefSel"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RXC
value|0x07
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RXC
value|"Receive Clock/Data Recovery C/S"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RXC_RXOOL
value|0x08
end_define

begin_comment
comment|/* rxOOL */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RXC_RXOOLI
value|0x02
end_define

begin_comment
comment|/* rxOOLIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RXC_RXREF
value|0x01
end_define

begin_comment
comment|/* rxrefSel */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RXC_RESV
value|0xf4
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_RXC
define|\
value|"\020\4rxOOL\2rxOOLIEn\1rxrefSel"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RSOC
value|0x10
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RSOC
value|"Receive Overhead Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOC_DSCR
value|0x40
end_define

begin_comment
comment|/* scrDis */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOC_FOOF
value|0x20
end_define

begin_comment
comment|/* frcOOF */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOC_B1IE
value|0x08
end_define

begin_comment
comment|/* B1ErrIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOC_LOSI
value|0x04
end_define

begin_comment
comment|/* LOSIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOC_LOFI
value|0x02
end_define

begin_comment
comment|/* LOFIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOC_OOFI
value|0x01
end_define

begin_comment
comment|/* OOFIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOC_RESV
value|0x90
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_RSOC
define|\
value|"\020\7scrDis\6frcOOF\4B1ErrIEn\3LOSIEn\2LOFIEn\1OOFIEn"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RSOS
value|0x11
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RSOS
value|"Receive Overhead Status"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOS_C1INT
value|0x80
end_define

begin_comment
comment|/* C1Int */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOS_B1INT
value|0x40
end_define

begin_comment
comment|/* B1ErrInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOS_LOSI
value|0x20
end_define

begin_comment
comment|/* LOSInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOS_LOFI
value|0x10
end_define

begin_comment
comment|/* LOFInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOS_OOFI
value|0x08
end_define

begin_comment
comment|/* OOFInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOS_LOS
value|0x04
end_define

begin_comment
comment|/* LOS */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOS_LOF
value|0x02
end_define

begin_comment
comment|/* LOF */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RSOS_OOF
value|0x01
end_define

begin_comment
comment|/* OOF */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_RSOS
define|\
value|"\020\10C1Int\7B1ErrInt\6LOSInt\5LOFInt\4OOFint\3LOS\2LOF\1OOF"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_BIPC
value|0x12
end_define

begin_comment
comment|/* + 0x13 LE */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGN_BIPC
value|"Receive Section BIP Errors"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TSOC
value|0x14
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TSOC
value|"Transmit Overhead Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TSOC_DSCR
value|0x40
end_define

begin_comment
comment|/* scrDis */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TSOC_LAISI
value|0x01
end_define

begin_comment
comment|/* LAISIns */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TSOC_RESV
value|0xbe
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_TSOC
define|\
value|"\020\7scrDis\1LAISIns"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TSOC2
value|0x15
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TSOC2
value|"Transmit Overhead Control 2"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TSOC2_LOSI
value|0x04
end_define

begin_comment
comment|/* LOSIns */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TSOC2_B1INV
value|0x02
end_define

begin_comment
comment|/* B1Inv */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TSOC2_IFE
value|0x01
end_define

begin_comment
comment|/* frErrIns */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TSOC2_RESV
value|0xf8
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_TSOC2
define|\
value|"\020\3LOSIns\2B1Inv\1frErrIns"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RLOS
value|0x18
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RLOS
value|"Receive Line Overhead Status"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOS_B2W
value|0x80
end_define

begin_comment
comment|/* B2Word */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOS_LAIS
value|0x02
end_define

begin_comment
comment|/* LAIS */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOS_LRDI
value|0x01
end_define

begin_comment
comment|/* LRDI */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOS_RESV
value|0x7c
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_RLOS
define|\
value|"\020\10B2Word\2LAIS\1LRDI"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RLOI
value|0x19
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RLOI
value|"Receive Line Overhead Interrupt"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOI_LFEBEE
value|0x80
end_define

begin_comment
comment|/* LFEBEIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOI_B2EE
value|0x40
end_define

begin_comment
comment|/* B2ErrIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOI_LAISE
value|0x20
end_define

begin_comment
comment|/* LAISIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOI_LRDIE
value|0x10
end_define

begin_comment
comment|/* LRDIIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOI_LFEBEI
value|0x08
end_define

begin_comment
comment|/* LFEBEInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOI_B2EI
value|0x04
end_define

begin_comment
comment|/* B2ErrInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOI_LAISI
value|0x02
end_define

begin_comment
comment|/* LAISInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RLOI_LRDII
value|0x01
end_define

begin_comment
comment|/* LRDIInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_RLOI
define|\
value|"\020\10LFEBEIEn\7B2ErrIEn\6LAISIEn\5LRDIIEn\4LFEBEInt\3B2ErrInt" \ 	    "\2LAISInt\1LRDIInt"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_B2EC
value|0x1a
end_define

begin_comment
comment|/* + 0x1b, 0x1c, 20bit LE */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGN_B2EC
value|"B2 Errors"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_FEBEC
value|0x1d
end_define

begin_comment
comment|/* + 0x1e, 0x1f, 20bit LE */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGN_FEBEC
value|"Line FEBE Errors"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TLOS
value|0x20
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TLOS
value|"Transmit Line Overhead Status"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TLOS_LRDI
value|0x01
end_define

begin_comment
comment|/* LRDI */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TLOS_RESV
value|0xfe
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_TLOS
define|\
value|"\020\1LRDI"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TLOC
value|0x21
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TLOC
value|"Transmit Line Overhead Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TLOC_B2INV
value|0x01
end_define

begin_comment
comment|/* B2Inv */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TLOC_RESV
value|0xfe
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_TLOC
define|\
value|"\020\1B2Inv"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TK1
value|0x24
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TK1
value|"Transmit K1"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TK2
value|0x25
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TK2
value|"Transmit K2"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RK1
value|0x26
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RK1
value|"Receive K1"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RK2
value|0x27
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RK2
value|"Receive K2"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RPOS
value|0x30
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RPOS
value|"Receive Path Overhead Status"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPOS_LOP
value|0x20
end_define

begin_comment
comment|/* LOP */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPOS_PAIS
value|0x08
end_define

begin_comment
comment|/* PAIS */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPOS_PRDI
value|0x04
end_define

begin_comment
comment|/* PRDI */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPOS_RESV
value|0xd3
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_RPOS
define|\
value|"\020\6LOP\4PAIS\3PRDI"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RPOI
value|0x31
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RPOI
value|"Receive Path Overhead Interrupt"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPOI_C2I
value|0x80
end_define

begin_comment
comment|/* C2Int */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPOI_LOPI
value|0x20
end_define

begin_comment
comment|/* LOPInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPOI_PAISI
value|0x08
end_define

begin_comment
comment|/* PAISInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPOI_PRDII
value|0x04
end_define

begin_comment
comment|/* PRDIInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPOI_B3EI
value|0x02
end_define

begin_comment
comment|/* B3ErrInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPOI_PFEBEI
value|0x01
end_define

begin_comment
comment|/* PFEBEInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPOI_RESV
value|0x50
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_RPOI
define|\
value|"\020\10C2Int\6LOPInt\4PAISInt\3PRDIInt\2B3ErrInt\1PFEBEInt"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RPIE
value|0x33
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RPIE
value|"Receive Path Interrupt Enable"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPIE_C2E
value|0x80
end_define

begin_comment
comment|/* C2IEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPIE_LOPE
value|0x20
end_define

begin_comment
comment|/* LOPIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPIE_PAISE
value|0x08
end_define

begin_comment
comment|/* PAISIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPIE_PRDIE
value|0x04
end_define

begin_comment
comment|/* PRDIIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPIE_B3EE
value|0x02
end_define

begin_comment
comment|/* B3ErrIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPIE_PFEBEE
value|0x01
end_define

begin_comment
comment|/* PFEBEIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPIE_RESV
value|0x50
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_RPIE
define|\
value|"\020\10CSIEn\6LOPIEn\4PAISIEn\3PRDIIEn\2B3ErrIEn\1PFEBEIEn"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RC2
value|0x37
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RC2
value|"Receive C2"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_B3EC
value|0x38
end_define

begin_comment
comment|/* + 0x39, LE, 16bit */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGN_B3EC
value|"B3 Errors"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_PFEBEC
value|0x3a
end_define

begin_comment
comment|/* + 0x3b, LE, 16bit */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGN_PFEBEC
value|"Path FEBE Errors"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RPEC
value|0x3d
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RPEC
value|"Receive Path BIP Error Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPEC_B3C
value|0x20
end_define

begin_comment
comment|/* blkBIP */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RPEC_RESV
value|0xdf
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_RPEC
define|\
value|"\020\6blkBIP"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TPOC
value|0x40
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TPOC
value|"Transmit Path Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPOC_B3INV
value|0x02
end_define

begin_comment
comment|/* B3Inv */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPOC_PAISI
value|0x01
end_define

begin_comment
comment|/* PAISIns */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPOC_RESC
value|0xfc
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_TPOC
define|\
value|"\020\2B3Inv\1PAISIns"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TPTC
value|0x41
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TPTC
value|"Transmit Pointer Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPTC_FPTR
value|0x40
end_define

begin_comment
comment|/* frcPtr */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPTC_STUFF
value|0x20
end_define

begin_comment
comment|/* stuffCtl */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPTC_PTR
value|0x10
end_define

begin_comment
comment|/* Ptr */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPTC_NDF
value|0x08
end_define

begin_comment
comment|/* NDF */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPTC_DECP
value|0x04
end_define

begin_comment
comment|/* decPtr */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPTC_INCP
value|0x02
end_define

begin_comment
comment|/* incPtr */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPTC_RESV
value|0x81
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_TPTC
define|\
value|"\020\7frcPtr\6stuffCtl\5Ptr\4NDF\3decPtr\2incPtr"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_PTRL
value|0x45
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_PTRL
value|"Transmit Pointer LSB"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_PTRL
define|\
value|"\020\12\xff\20arbPtr"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_PTRM
value|0x46
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_PTRM
value|"Transmit Pointer MSB"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_PTRM_NDF
value|0xf0
end_define

begin_comment
comment|/* NDFVal */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGS_PTRM_NDF
value|4
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_PTRM_SS
value|0x0c
end_define

begin_comment
comment|/* ssBit */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_PTRM_SONET
value|0x00
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_PTRM_SDH
value|0x08
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_PTRM_PTR
value|0x03
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_PTRM
define|\
value|"\020\12\xf0\20NDFVal\12\xc\20ssBit\12\x3\20arbPtr"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TC2
value|0x48
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TC2
value|"Transmit C2"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TPOC2
value|0x49
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TPOC2
value|"Transmit Path Control 2"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPOC2_FEBE
value|0xf0
end_define

begin_comment
comment|/* PFEBEIns */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGS_TPOC2_FEBE
value|4
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPOC2_PRDII
value|0x08
end_define

begin_comment
comment|/* PRDIIns */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TPOC2_G1
value|0x07
end_define

begin_comment
comment|/* G1Ins */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_TPOC2
define|\
value|"\020\12\xf0\20PFEBEIns\4PRDIIns\12\x7\20G1Ins"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RCC
value|0x50
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RCC
value|"Receive Cell Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCC_OCD
value|0x80
end_define

begin_comment
comment|/* OCD */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCC_PARTY
value|0x40
end_define

begin_comment
comment|/* parity */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCC_PASS
value|0x20
end_define

begin_comment
comment|/* pass */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCC_DCOR
value|0x10
end_define

begin_comment
comment|/* corDis */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCC_DHEC
value|0x08
end_define

begin_comment
comment|/* HECdis */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCC_ADD
value|0x04
end_define

begin_comment
comment|/* csetAdd */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCC_DSCR
value|0x02
end_define

begin_comment
comment|/* scrDis */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCC_RFIFO
value|0x01
end_define

begin_comment
comment|/* rxFIFOrst */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_RCC
define|\
value|"\020\10OCD\7parity\6pass\5corDis\4HECdis\3csetAdd" \ 	    "\2scrDis\1rxFIFOrst"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RCI
value|0x51
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RCI
value|"Receive Cell Interrupt"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCI_OCDE
value|0x80
end_define

begin_comment
comment|/* OCDIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCI_HECE
value|0x40
end_define

begin_comment
comment|/* HECIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCI_OVFE
value|0x20
end_define

begin_comment
comment|/* ovfIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCI_OCDI
value|0x10
end_define

begin_comment
comment|/* OCDInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCI_CORI
value|0x08
end_define

begin_comment
comment|/* corInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCI_UCORI
value|0x04
end_define

begin_comment
comment|/* uncorInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCI_OVFI
value|0x02
end_define

begin_comment
comment|/* ovfInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCI_RESV
value|0x01
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_RCI
define|\
value|"\020\10OCDIEn\7HECIEn\6ovfIEn\5OCDInt\4corInt\3uncorInt\2ovfInt"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_CMH
value|0x52
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_CMH
value|"Receive Cell Match Header"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_CMH_GFC
value|0xf0
end_define

begin_comment
comment|/* GFC */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGS_CMH_GFC
value|4
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_CMH_PTI
value|0x0e
end_define

begin_comment
comment|/* PTI */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGS_CMH_PTI
value|1
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_CMH_CLP
value|0x01
end_define

begin_comment
comment|/* CLP */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_CMH
define|\
value|"\020\12\xf0\20GFC\12\xe\20PTI\12\x1\20CLP"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_CMHM
value|0x53
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_CMHM
value|"Receive Cell Match Header Mask"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_CMHM_GFC
value|0xf0
end_define

begin_comment
comment|/* mskGFC */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGS_CMHM_GFC
value|4
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_CMHM_PTI
value|0x0e
end_define

begin_comment
comment|/* mskPTI */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGS_CMHM_PTI
value|1
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_CMHM_CLP
value|0x01
end_define

begin_comment
comment|/* mskCLP */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_CMHM
define|\
value|"\020\12\xf0\20mskGFC\12\xe\20mskPTI\12\x1\20mskCLP"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_CEC
value|0x54
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_CEC
value|"Correctable Errors"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_UEC
value|0x55
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_UEC
value|"Uncorrectable Errors"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RCCNT
value|0x56
end_define

begin_comment
comment|/* +0x57, 0x58, LE, 19bit */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGN_RCCNT
value|"Receive Cells"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RCCF
value|0x59
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RCCF
value|"Receive Cell Configuration"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCCF_GFCE
value|0xf0
end_define

begin_comment
comment|/* GFCen */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGS_RCCF_GFCE
value|4
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCCF_FIXS
value|0x08
end_define

begin_comment
comment|/* FixSen */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCCF_RCAL
value|0x04
end_define

begin_comment
comment|/* RCAlevel */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RCCF_HECF
value|0x03
end_define

begin_comment
comment|/* HECftr */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_RCCF
define|\
value|"\020\12\xf0\20GFCen\4FixSen\3RCAlevel\12\x3\20HECftr"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RXID
value|0x5a
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RXID
value|"Receive ID Address"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RXID_ID
value|0x03
end_define

begin_comment
comment|/* IDAddr */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RXID_RESV
value|0xfc
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_RXID
define|\
value|"\020\12\x3\20IDAddr"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TCC
value|0x60
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TCC
value|"Transmit Cell Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC_FIFOE
value|0x80
end_define

begin_comment
comment|/* fovrIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC_SOCI
value|0x40
end_define

begin_comment
comment|/* socInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC_FIFOI
value|0x20
end_define

begin_comment
comment|/* fovrInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC_HECINV
value|0x10
end_define

begin_comment
comment|/* HECInv */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC_HECDIS
value|0x08
end_define

begin_comment
comment|/* HECDis */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC_ADD
value|0x04
end_define

begin_comment
comment|/* csetAdd */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC_DSCR
value|0x02
end_define

begin_comment
comment|/* scrDis */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC_FIFOR
value|0x01
end_define

begin_comment
comment|/* txFIFOrst */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_TCC
define|\
value|"\020\10fovrIEn\7socInt\6fovrInt\5HECInv\4HECDis\3csetAdd" \ 	    "\2scrDis\1txFIFOrst"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TCHP
value|0x61
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TCHP
value|"Transmit Idle Cell Header"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCHP_GFC
value|0xf0
end_define

begin_comment
comment|/* GFCtx */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGS_TCHP_GFC
value|4
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCHP_PTI
value|0x0e
end_define

begin_comment
comment|/* PTItx */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGS_TCHP_PTI
value|1
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCHP_CLP
value|0x01
end_define

begin_comment
comment|/* CLPtx */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_TCHP
define|\
value|"\020\12\xf0\20GFCtx\12\xe\20PTItx\12\x1\20CLPtx"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TPLD
value|0x62
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TPLD
value|"Transmit Idle Cell Payload"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TCC2
value|0x63
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TCC2
value|"Transmit Cell Configuration 2"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC2_PARITY
value|0x80
end_define

begin_comment
comment|/* parity */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC2_PARE
value|0x40
end_define

begin_comment
comment|/* parIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC2_PARI
value|0x10
end_define

begin_comment
comment|/* parInt */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC2_FIFO
value|0x0c
end_define

begin_comment
comment|/* FIFOdpth */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGS_TCC2_FIFO
value|2
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC2_TCAL
value|0x02
end_define

begin_comment
comment|/* TCAlevel */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC2_RESV
value|0x01
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_TCC2
define|\
value|"\020\10parity\7parIEn\5parInt\12\xc\20FIFOdpth\2TCAlevel"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TXCNT
value|0x64
end_define

begin_comment
comment|/* +65,66 LE 19bit */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGN_TXCNT
value|"Transmit Cells"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TCC3
value|0x67
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TCC3
value|"Transmit Cell Configuration 3"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC3_GFCE
value|0xf0
end_define

begin_comment
comment|/* txGFCen */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGS_TCC3_GFCE
value|4
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC3_FIXE
value|0x08
end_define

begin_comment
comment|/* txFixSen */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC3_H4ID
value|0x04
end_define

begin_comment
comment|/* H4InsDis */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC3_FIXB
value|0x03
end_define

begin_comment
comment|/* fixByte */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC3_FIX00
value|0x00
end_define

begin_comment
comment|/* 0x00 */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC3_FIX55
value|0x01
end_define

begin_comment
comment|/* 0x55 */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC3_FIXAA
value|0x02
end_define

begin_comment
comment|/* 0xAA */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TCC3_FIXFF
value|0x03
end_define

begin_comment
comment|/* 0xFF */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGX_TCC3
define|\
value|"\020\12\xf0\20txGFCen\4txFixSen\3H4InsDis" \ 	    "\11\x3\x0FIX00\11\x3\x1FIX55\11\x3\x2FIXAA\11\x3\x3FIXFF"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_TXID
value|0x68
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_TXID
value|"Transmit ID Address"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_TXID_ID
value|0x03
end_define

begin_comment
comment|/* txIDAddr */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_TXID_RESV
value|0xfc
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_TXID
define|\
value|"\020\12\x3\20txIDAddr"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_RBER
value|0x70
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_RBER
value|"Receive BER S/C"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_RBER_FAILE
value|0x08
end_define

begin_comment
comment|/* FailIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RBER_WARNE
value|0x04
end_define

begin_comment
comment|/* WarnIEn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RBER_FAIL
value|0x02
end_define

begin_comment
comment|/* BERfail */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RBER_WARN
value|0x01
end_define

begin_comment
comment|/* BERwarn */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_RBER_RESV
value|0xf0
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_RBER
define|\
value|"\020\4FailIEn\3WarnIEn\2BERfail\1BERwarn"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_BFTH
value|0x71
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_BFTH
value|"Receive BER Fail Threshold"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_BFWIN
value|0x72
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_BFWIN
value|"Receive BER Fail Window"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_BFDEN
value|0x73
end_define

begin_comment
comment|/* +74, 16bit LE */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGN_BFDEN
value|"Receive BER Fail Denominator"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_BWTH
value|0x75
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_BWTH
value|"Receive BER Warn Threshold"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_BWWIN
value|0x76
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_BWWIN
value|"Receive BER Warn Window"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_BWDEN
value|0x77
end_define

begin_comment
comment|/* +78, 16bit LE */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGN_BWDEN
value|"Receive BER Warn Denomiator"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGO_OPEC
value|0x7f
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGN_OPEC
value|"Output PECL Control"
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGM_OPEC_TXC
value|0x04
end_define

begin_comment
comment|/* pcctl_tc */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_OPEC_TXD
value|0x02
end_define

begin_comment
comment|/* pcctl_td */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_OPEC_RXDO
value|0x01
end_define

begin_comment
comment|/* pcctl_r */
end_comment

begin_define
define|#
directive|define
name|IDTPHY_REGM_OPEC_RESV
value|0xf8
end_define

begin_define
define|#
directive|define
name|IDTPHY_REGX_OPEC
define|\
value|"\020\3pctl_tc\2pcctl_td\1pcctl_r"
end_define

begin_define
define|#
directive|define
name|IDTPHY_PRINT_77155
define|\
value|{
comment|/* 00 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_MRID,		\ 	  IDTPHY_REGN_MRID,	IDTPHY_REGX_MRID },		\ 	{
comment|/* 01 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_CONF,		\ 	  IDTPHY_REGN_CONF,	IDTPHY_REGX_CONF },		\ 	{
comment|/* 02 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_INT,		\ 	  IDTPHY_REGN_INT,	IDTPHY_REGX_INT },		\
comment|/* 03 unused */
value|\ 	{
comment|/* 04 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_MCM,		\ 	  IDTPHY_REGN_MCM,	IDTPHY_REGX_MCM },		\ 	{
comment|/* 05 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_MCTL,		\ 	  IDTPHY_REGN_MCTL,	IDTPHY_REGX_MCTL },		\ 	{
comment|/* 06 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TXC,		\ 	  IDTPHY_REGN_TXC,	IDTPHY_REGX_TXC },		\ 	{
comment|/* 07 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RXC,		\ 	  IDTPHY_REGN_RXC,	IDTPHY_REGX_RXC },		\
comment|/* 08-0f unused */
value|\ 	{
comment|/* 10 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RSOC,		\ 	  IDTPHY_REGN_RSOC,	IDTPHY_REGX_RSOC },		\ 	{
comment|/* 11 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RSOS,		\ 	  IDTPHY_REGN_RSOS,	IDTPHY_REGX_RSOS },		\ 	{
comment|/* 12, 13 */
value|\ 	  UTP_REGT_INT16,	IDTPHY_REGO_BIPC,		\ 	  IDTPHY_REGN_BIPC,	NULL },				\ 	{
comment|/* 14 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TSOC,		\ 	  IDTPHY_REGN_TSOC,	IDTPHY_REGX_TSOC },		\ 	{
comment|/* 15 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TSOC2,		\ 	  IDTPHY_REGN_TSOC2,	IDTPHY_REGX_TSOC2 },		\
comment|/* 16, 17 unused */
value|\ 	{
comment|/* 18 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RLOS,		\ 	  IDTPHY_REGN_RLOS,	IDTPHY_REGX_RLOS },		\ 	{
comment|/* 19 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RLOI,		\ 	  IDTPHY_REGN_RLOI,	IDTPHY_REGX_RLOI },		\ 	{
comment|/* 1a-1c */
value|\ 	  UTP_REGT_INT20,	IDTPHY_REGO_B2EC,		\ 	  IDTPHY_REGN_B2EC,	NULL },				\ 	{
comment|/* 1d-1f */
value|\ 	  UTP_REGT_INT20,	IDTPHY_REGO_FEBEC,		\ 	  IDTPHY_REGN_FEBEC,	NULL },				\ 	{
comment|/* 20 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TLOS,		\ 	  IDTPHY_REGN_TLOS,	IDTPHY_REGX_TLOS },		\ 	{
comment|/* 21 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TLOC,		\ 	  IDTPHY_REGN_TLOC,	IDTPHY_REGX_TLOC },		\
comment|/* 22, 23 unused */
value|\ 	{
comment|/* 24 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_TK1,		\ 	  IDTPHY_REGN_TK1,	NULL },				\ 	{
comment|/* 25 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_TK2,		\ 	  IDTPHY_REGN_TK2,	NULL },				\ 	{
comment|/* 26 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_RK1,		\ 	  IDTPHY_REGN_RK1,	NULL },				\ 	{
comment|/* 27 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_RK2,		\ 	  IDTPHY_REGN_RK2,	NULL },				\
comment|/* 28-2f unused */
value|\ 	{
comment|/* 30 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RPOS,		\ 	  IDTPHY_REGN_RPOS,	IDTPHY_REGX_RPOS },		\ 	{
comment|/* 31 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RPOI,		\ 	  IDTPHY_REGN_RPOI,	IDTPHY_REGX_RPOI },		\
comment|/* 32 unused */
value|\ 	{
comment|/* 33 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RPIE,		\ 	  IDTPHY_REGN_RPIE,	IDTPHY_REGX_RPIE },		\
comment|/* 34-36 unused */
value|\ 	{
comment|/* 37 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_RC2,		\ 	  IDTPHY_REGN_RC2,	NULL },				\ 	{
comment|/* 38-39 */
value|\ 	  UTP_REGT_INT16,	IDTPHY_REGO_B3EC,		\ 	  IDTPHY_REGN_B3EC,	NULL },				\ 	{
comment|/* 3a-3b */
value|\ 	  UTP_REGT_INT16,	IDTPHY_REGO_PFEBEC,		\ 	  IDTPHY_REGN_PFEBEC,	NULL },				\
comment|/* 3c unused */
value|\ 	{
comment|/* 3d */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RPEC,		\ 	  IDTPHY_REGN_RPEC,	IDTPHY_REGX_RPEC },		\
comment|/* 3e, 3f unused */
value|\ 	{
comment|/* 40 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TPOC,		\ 	  IDTPHY_REGN_TPOC,	IDTPHY_REGX_TPOC },		\ 	{
comment|/* 41 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TPTC,		\ 	  IDTPHY_REGN_TPTC,	IDTPHY_REGX_TPTC },		\
comment|/* 42-44 unused */
value|\ 	{
comment|/* 45 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_PTRL,		\ 	  IDTPHY_REGN_PTRL,	IDTPHY_REGX_PTRL },		\ 	{
comment|/* 46 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_PTRM,		\ 	  IDTPHY_REGN_PTRM,	IDTPHY_REGX_PTRM },		\
comment|/* 47 unused */
value|\ 	{
comment|/* 48 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_TC2,		\ 	  IDTPHY_REGN_TC2,	NULL },				\ 	{
comment|/* 49 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TPOC2,		\ 	  IDTPHY_REGN_TPOC2,	IDTPHY_REGX_TPOC2 },		\
comment|/* 4a-4f unused */
value|\ 	{
comment|/* 50 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RCC,		\ 	  IDTPHY_REGN_RCC,	IDTPHY_REGX_RCC },		\ 	{
comment|/* 51 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RCI,		\ 	  IDTPHY_REGN_RCI,	IDTPHY_REGX_RCI },		\ 	{
comment|/* 52 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_CMH,		\ 	  IDTPHY_REGN_CMH,	IDTPHY_REGX_CMH },		\ 	{
comment|/* 53 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_CMHM,		\ 	  IDTPHY_REGN_CMHM,	IDTPHY_REGX_CMHM },		\ 	{
comment|/* 54 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_CEC,		\ 	  IDTPHY_REGN_CEC,	NULL },				\ 	{
comment|/* 55 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_UEC,		\ 	  IDTPHY_REGN_UEC,	NULL },				\ 	{
comment|/* 56-58 */
value|\ 	  UTP_REGT_INT19,	IDTPHY_REGO_RCCNT,		\ 	  IDTPHY_REGN_RCCNT,	NULL },				\ 	{
comment|/* 59 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RCCF,		\ 	  IDTPHY_REGN_RCCF,	IDTPHY_REGX_RCCF },		\ 	{
comment|/* 5a */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RXID,		\ 	  IDTPHY_REGN_RXID,	IDTPHY_REGX_RXID },		\
comment|/* 5b-5f unused */
value|\ 	{
comment|/* 60 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TCC,		\ 	  IDTPHY_REGN_TCC,	IDTPHY_REGX_TCC },		\ 	{
comment|/* 61 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TCHP,		\ 	  IDTPHY_REGN_TCHP,	IDTPHY_REGX_TCHP },		\ 	{
comment|/* 62 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_TPLD,		\ 	  IDTPHY_REGN_TPLD,	NULL },				\ 	{
comment|/* 63 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TCC2,		\ 	  IDTPHY_REGN_TCC2,	IDTPHY_REGX_TCC2 },		\ 	{
comment|/* 64-66 */
value|\ 	  UTP_REGT_INT19,	IDTPHY_REGO_TXCNT,		\ 	  IDTPHY_REGN_TXCNT,	NULL },				\ 	{
comment|/* 67 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TCC3,		\ 	  IDTPHY_REGN_TCC3,	IDTPHY_REGX_TCC3 },		\ 	{
comment|/* 68 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_TXID,		\ 	  IDTPHY_REGN_TXID,	IDTPHY_REGX_TXID },		\
comment|/* 69-6f unused */
value|\ 	{
comment|/* 70 */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_RBER,		\ 	  IDTPHY_REGN_RBER,	IDTPHY_REGX_RBER },		\ 	{
comment|/* 71 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_BFTH,		\ 	  IDTPHY_REGN_BFTH,	NULL },				\ 	{
comment|/* 72 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_BFWIN,		\ 	  IDTPHY_REGN_BFWIN,	NULL },				\ 	{
comment|/* 73,74 */
value|\ 	  UTP_REGT_INT16,	IDTPHY_REGO_BFDEN,		\ 	  IDTPHY_REGN_BFDEN,	NULL },				\ 	{
comment|/* 75 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_BWTH,		\ 	  IDTPHY_REGN_BWTH,	NULL },				\ 	{
comment|/* 76 */
value|\ 	  UTP_REGT_INT8,	IDTPHY_REGO_BWWIN,		\ 	  IDTPHY_REGN_BWWIN,	NULL },				\ 	{
comment|/* 77,78 */
value|\ 	  UTP_REGT_INT16,	IDTPHY_REGO_BWDEN,		\ 	  IDTPHY_REGN_BWDEN,	NULL },				\
comment|/* 79-7e unused */
value|\ 	{
comment|/* 7f */
value|\ 	  UTP_REGT_BITS,	IDTPHY_REGO_OPEC,		\ 	  IDTPHY_REGN_OPEC,	IDTPHY_REGX_OPEC }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_UTOPIA_IDTPHY_H */
end_comment

end_unit

