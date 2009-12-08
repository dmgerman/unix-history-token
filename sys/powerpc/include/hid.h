begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Tsubai Masanari.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $NetBSD: hid.h,v 1.2 2001/08/22 21:05:25 matt Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POWERPC_HID_H_
end_ifndef

begin_define
define|#
directive|define
name|_POWERPC_HID_H_
end_define

begin_comment
comment|/* Hardware Implementation Dependent registers for the PowerPC */
end_comment

begin_define
define|#
directive|define
name|HID0_EMCP
value|0x80000000
end_define

begin_comment
comment|/* Enable machine check pin */
end_comment

begin_define
define|#
directive|define
name|HID0_DBP
value|0x40000000
end_define

begin_comment
comment|/* Disable 60x bus parity generation */
end_comment

begin_define
define|#
directive|define
name|HID0_EBA
value|0x20000000
end_define

begin_comment
comment|/* Enable 60x bus address parity checking */
end_comment

begin_define
define|#
directive|define
name|HID0_EBD
value|0x10000000
end_define

begin_comment
comment|/* Enable 60x bus data parity checking */
end_comment

begin_define
define|#
directive|define
name|HID0_BCLK
value|0x08000000
end_define

begin_comment
comment|/* CLK_OUT clock type selection */
end_comment

begin_define
define|#
directive|define
name|HID0_EICE
value|0x04000000
end_define

begin_comment
comment|/* Enable ICE output */
end_comment

begin_define
define|#
directive|define
name|HID0_ECLK
value|0x02000000
end_define

begin_comment
comment|/* CLK_OUT clock type selection */
end_comment

begin_define
define|#
directive|define
name|HID0_PAR
value|0x01000000
end_define

begin_comment
comment|/* Disable precharge of ARTRY */
end_comment

begin_define
define|#
directive|define
name|HID0_STEN
value|0x01000000
end_define

begin_comment
comment|/* Software table search enable (7450) */
end_comment

begin_define
define|#
directive|define
name|HID0_DEEPNAP
value|0x01000000
end_define

begin_comment
comment|/* Enable deep nap mode (970) */
end_comment

begin_define
define|#
directive|define
name|HID0_HBATEN
value|0x00800000
end_define

begin_comment
comment|/* High BAT enable (74[45][578])  */
end_comment

begin_define
define|#
directive|define
name|HID0_DOZE
value|0x00800000
end_define

begin_comment
comment|/* Enable doze mode */
end_comment

begin_define
define|#
directive|define
name|HID0_NAP
value|0x00400000
end_define

begin_comment
comment|/* Enable nap mode */
end_comment

begin_define
define|#
directive|define
name|HID0_SLEEP
value|0x00200000
end_define

begin_comment
comment|/* Enable sleep mode */
end_comment

begin_define
define|#
directive|define
name|HID0_DPM
value|0x00100000
end_define

begin_comment
comment|/* Enable Dynamic power management */
end_comment

begin_define
define|#
directive|define
name|HID0_RISEG
value|0x00080000
end_define

begin_comment
comment|/* Read I-SEG */
end_comment

begin_define
define|#
directive|define
name|HID0_TG
value|0x00040000
end_define

begin_comment
comment|/* Timebase Granularity (OEA64) */
end_comment

begin_define
define|#
directive|define
name|HID0_BHTCLR
value|0x00040000
end_define

begin_comment
comment|/* Clear branch history table (7450) */
end_comment

begin_define
define|#
directive|define
name|HID0_EIEC
value|0x00040000
end_define

begin_comment
comment|/* Enable internal error checking */
end_comment

begin_define
define|#
directive|define
name|HID0_XAEN
value|0x00020000
end_define

begin_comment
comment|/* Enable eXtended Addressing (7450) */
end_comment

begin_define
define|#
directive|define
name|HID0_NHR
value|0x00010000
end_define

begin_comment
comment|/* Not hard reset */
end_comment

begin_define
define|#
directive|define
name|HID0_ICE
value|0x00008000
end_define

begin_comment
comment|/* Enable i-cache */
end_comment

begin_define
define|#
directive|define
name|HID0_DCE
value|0x00004000
end_define

begin_comment
comment|/* Enable d-cache */
end_comment

begin_define
define|#
directive|define
name|HID0_ILOCK
value|0x00002000
end_define

begin_comment
comment|/* i-cache lock */
end_comment

begin_define
define|#
directive|define
name|HID0_DLOCK
value|0x00001000
end_define

begin_comment
comment|/* d-cache lock */
end_comment

begin_define
define|#
directive|define
name|HID0_ICFI
value|0x00000800
end_define

begin_comment
comment|/* i-cache flush invalidate */
end_comment

begin_define
define|#
directive|define
name|HID0_DCFI
value|0x00000400
end_define

begin_comment
comment|/* d-cache flush invalidate */
end_comment

begin_define
define|#
directive|define
name|HID0_SPD
value|0x00000200
end_define

begin_comment
comment|/* Disable speculative cache access */
end_comment

begin_define
define|#
directive|define
name|HID0_XBSEN
value|0x00000100
end_define

begin_comment
comment|/* Extended BAT block-size enable (7457) */
end_comment

begin_define
define|#
directive|define
name|HID0_IFEM
value|0x00000100
end_define

begin_comment
comment|/* Enable M-bit for I-fetch */
end_comment

begin_define
define|#
directive|define
name|HID0_XBSEN
value|0x00000100
end_define

begin_comment
comment|/* Extended BAT block size enable (7455+)*/
end_comment

begin_define
define|#
directive|define
name|HID0_SGE
value|0x00000080
end_define

begin_comment
comment|/* Enable store gathering */
end_comment

begin_define
define|#
directive|define
name|HID0_DCFA
value|0x00000040
end_define

begin_comment
comment|/* Data cache flush assist */
end_comment

begin_define
define|#
directive|define
name|HID0_BTIC
value|0x00000020
end_define

begin_comment
comment|/* Enable BTIC */
end_comment

begin_define
define|#
directive|define
name|HID0_LRSTK
value|0x00000010
end_define

begin_comment
comment|/* Link register stack enable (7450) */
end_comment

begin_define
define|#
directive|define
name|HID0_ABE
value|0x00000008
end_define

begin_comment
comment|/* Enable address broadcast */
end_comment

begin_define
define|#
directive|define
name|HID0_FOLD
value|0x00000008
end_define

begin_comment
comment|/* Branch folding enable (7450) */
end_comment

begin_define
define|#
directive|define
name|HID0_BHT
value|0x00000004
end_define

begin_comment
comment|/* Enable branch history table */
end_comment

begin_define
define|#
directive|define
name|HID0_NOPTI
value|0x00000001
end_define

begin_comment
comment|/* No-op the dcbt(st) */
end_comment

begin_define
define|#
directive|define
name|HID0_AIM_TBEN
value|0x04000000
end_define

begin_comment
comment|/* Time base enable (7450) */
end_comment

begin_define
define|#
directive|define
name|HID0_E500_TBEN
value|0x00004000
end_define

begin_comment
comment|/* Time Base and decr. enable */
end_comment

begin_define
define|#
directive|define
name|HID0_E500_SEL_TBCLK
value|0x00002000
end_define

begin_comment
comment|/* Select Time Base clock */
end_comment

begin_define
define|#
directive|define
name|HID0_E500_MAS7UPDEN
value|0x00000080
end_define

begin_comment
comment|/* Enable MAS7 update (e500v2) */
end_comment

begin_define
define|#
directive|define
name|HID0_BITMASK
define|\
value|"\20"								\     "\040EMCP\037DBP\036EBA\035EBD\034BCLK\033EICE\032ECLK\031PAR"	\     "\030DOZE\027NAP\026SLEEP\025DPM\024RISEG\023EIEC\022res\021NHR"	\     "\020ICE\017DCE\016ILOCK\015DLOCK\014ICFI\013DCFI\012SPD\011IFEM"	\     "\010SGE\007DCFA\006BTIC\005FBIOB\004ABE\003BHT\002NOPDST\001NOPTI"
end_define

begin_define
define|#
directive|define
name|HID0_7450_BITMASK
define|\
value|"\20"								\     "\040EMCP\037b1\036b2\035b3\034b4\033TBEN\032b6\031STEN"		\     "\030HBATEN\027NAP\026SLEEP\025DPM\024b12\023BHTCLR\022XAEN\021NHR"	\     "\020ICE\017DCE\016ILOCK\015DLOCK\014ICFI\013DCFI\012SPD\011XBSEN"	\     "\010SGE\007b25\006BTIC\005LRSTK\004FOLD\003BHT\002NOPDST\001NOPTI"
end_define

begin_define
define|#
directive|define
name|HID0_E500_BITMASK
define|\
value|"\20"								\     "\040EMCP\037b1\036b2\035b3\034b4\033b5\032b6\031b7"		\     "\030DOZE\027NAP\026SLEEP\025b11\024b12\023b13\022b14\021b15"	\     "\020b16\017TBEN\016SEL_TBCLK\015b19\014b20\013b21\012b22\011b23"	\     "\010EN_MAS7_UPDATE\007DCFA\006b26\005b27\004b28\003b29\002b30\001NOPTI"
end_define

begin_define
define|#
directive|define
name|HID0_970_BITMASK
define|\
value|"\20"								\     "\040ONEPPC\037SINGLE\036ISYNCSC\035SERGP\031DEEPNAP\030DOZE"	\     "\027NAP\025DPM\023TG\022HANGDETECT\021NHR\020INORDER"		\     "\016TBCTRL\015TBEN\012CIABREN\011HDICEEN\001ENATTN"
end_define

begin_comment
comment|/*  *  HID0 bit definitions per cpu model  *  * bit	603	604	750	7400	7410	7450	7457	e500  *   0	EMCP	EMCP	EMCP	EMCP	EMCP	-	-	EMCP  *   1	-	ECP	DBP	-	-	-	-	-  *   2	EBA	EBA	EBA	EBA	EDA	-	-	-  *   3	EBD	EBD	EBD	EBD	EBD	-	-	-  *   4	SBCLK	-	BCLK	BCKL	BCLK	-	-	-  *   5	EICE	-	-	-	-	TBEN	TBEN	-  *   6	ECLK	-	ECLK	ECLK	ECLK	-	-	-  *   7	PAR	PAR	PAR	PAR	PAR	STEN	STEN	-  *   8	DOZE	-	DOZE	DOZE	DOZE	-	HBATEN	DOZE  *   9	NAP	-	NAP	NAP	NAP	NAP	NAP	NAP  *  10	SLEEP	-	SLEEP	SLEEP	SLEEP	SLEEP	SLEEP	SLEEP  *  11	DPM	-	DPM	DPM	DPM	DPM	DPM	-  *  12	RISEG	-	-	RISEG	-	-	-	-  *  13	-	-	-	EIEC	EIEC	BHTCLR	BHTCLR	-  *  14	-	-	-	-	-	XAEN	XAEN	-  *  15	-	NHR	NHR	NHR	NHR	NHR	NHR	-  *  16	ICE	ICE	ICE	ICE	ICE	ICE	ICE	-  *  17	DCE	DCE	DCE	DCE	DCE	DCE	DCE	TBEN  *  18	ILOCK	ILOCK	ILOCK	ILOCK	ILOCK	ILOCK	ILOCK	SEL_TBCLK  *  19	DLOCK	DLOCK	DLOCK	DLOCK	DLOCK	DLOCK	DLOCK	-  *  20	ICFI	ICFI	ICFI	ICFI	ICFI	ICFI	ICFI	-  *  21	DCFI	DCFI	DCFI	DCFI	DCFI	DCFI	DCFI	-  *  22	-	-	SPD	SPD	SPG	SPD	SPD	-  *  23	-	-	IFEM	IFTT	IFTT	-	XBSEN	-  *  24	-	SIE	SGE	SGE	SGE	SGE	SGE	EN_MAS7_UPDATE  *  25	-	-	DCFA	DCFA	DCFA	-	-	DCFA  *  26	-	-	BTIC	BTIC	BTIC	BTIC	BTIC	-  *  27	FBIOB	-	-	-	-	LRSTK	LRSTK	-  *  28	-	-	ABE	-	-	FOLD	FOLD	-  *  29	-	BHT	BHT	BHT	BHT	BHT	BHT	-  *  30	-	-	-	NOPDST	NOPDST	NOPDST	NOPDST	-  *  31	NOOPTI	-	NOOPTI	NOPTI	NOPTI	NOPTI	NOPTI	NOPTI  *  *  604: ECP = Enable cache parity checking  *  604: SIE = Serial instruction execution disable  * 7450: TBEN = Time Base Enable  * 7450: STEN = Software table lookup enable  * 7450: BHTCLR = Branch history clear  * 7450: XAEN = Extended Addressing Enabled  * 7450: LRSTK = Link Register Stack Enable  * 7450: FOLD = Branch folding enable  * 7457: HBATEN = High BAT Enable  * 7457: XBSEN = Extended BAT Block Size Enable  */
end_comment

begin_define
define|#
directive|define
name|HID1_E500_ABE
value|0x00001000
end_define

begin_comment
comment|/* Address broadcast enable */
end_comment

begin_define
define|#
directive|define
name|HID1_E500_ASTME
value|0x00002000
end_define

begin_comment
comment|/* Address bus streaming mode enable */
end_comment

begin_define
define|#
directive|define
name|HID1_E500_RFXE
value|0x00020000
end_define

begin_comment
comment|/* Read fault exception enable */
end_comment

begin_define
define|#
directive|define
name|HID0_E500_DEFAULT_SET
value|(HID0_EMCP | HID0_E500_TBEN)
end_define

begin_define
define|#
directive|define
name|HID1_E500_DEFAULT_SET
value|(HID1_E500_ABE | HID1_E500_ASTME)
end_define

begin_define
define|#
directive|define
name|HID5_970_DCBZ_SIZE_HI
value|0x01000000
end_define

begin_comment
comment|/* dcbz does a 32-byte store */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _POWERPC_HID_H_ */
end_comment

end_unit

