begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Dallas DS2153, DS21x54 single-chip E1 tranceiver registers.  *  * Copyright (C) 1996 Cronyx Engineering.  * Author: Serge Vakulenko,<vak@cronyx.ru>  *  * This software is distributed with NO WARRANTIES, not even the implied  * warranties for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  *  * Authors grant any other persons or organisations permission to use  * or modify this software as long as this message is kept with the software,  * all derivative works or modified versions.  *  * Cronyx Id: ds2153.h,v 1.2.4.1 2003/11/12 17:22:33 rik Exp $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Control and test registers  */
end_comment

begin_define
define|#
directive|define
name|DS_RCR1
value|0x10
end_define

begin_comment
comment|/* rw - receive control 1 */
end_comment

begin_define
define|#
directive|define
name|DS_RCR2
value|0x11
end_define

begin_comment
comment|/* rw - receive control 2 */
end_comment

begin_define
define|#
directive|define
name|DS_TCR1
value|0x12
end_define

begin_comment
comment|/* rw - transmit control 1 */
end_comment

begin_define
define|#
directive|define
name|DS_TCR2
value|0x13
end_define

begin_comment
comment|/* rw - transmit control 2 */
end_comment

begin_define
define|#
directive|define
name|DS_CCR1
value|0x14
end_define

begin_comment
comment|/* rw - common control 1 */
end_comment

begin_define
define|#
directive|define
name|DS_CCR2
value|0x1a
end_define

begin_comment
comment|/* rw - common control 2 */
end_comment

begin_define
define|#
directive|define
name|DS_CCR3
value|0x1b
end_define

begin_comment
comment|/* rw - common control 3 */
end_comment

begin_define
define|#
directive|define
name|DS_LICR
value|0x18
end_define

begin_comment
comment|/* rw - line interface control */
end_comment

begin_define
define|#
directive|define
name|DS_IMR1
value|0x16
end_define

begin_comment
comment|/* rw - interrupt mask 1 */
end_comment

begin_define
define|#
directive|define
name|DS_IMR2
value|0x17
end_define

begin_comment
comment|/* rw - interrupt mask 2 */
end_comment

begin_define
define|#
directive|define
name|DS_TEST1
value|0x15
end_define

begin_comment
comment|/* rw - test 1 */
end_comment

begin_define
define|#
directive|define
name|DS_TEST2
value|0x19
end_define

begin_comment
comment|/* rw - test 2 */
end_comment

begin_comment
comment|/*  * Status and information registers  */
end_comment

begin_define
define|#
directive|define
name|DS_RIR
value|0x08
end_define

begin_comment
comment|/* r  - receive information */
end_comment

begin_define
define|#
directive|define
name|DS_SSR
value|0x1e
end_define

begin_comment
comment|/* r  - synchronizer status */
end_comment

begin_define
define|#
directive|define
name|DS_SR1
value|0x06
end_define

begin_comment
comment|/* r  - status 1 */
end_comment

begin_define
define|#
directive|define
name|DS_SR2
value|0x07
end_define

begin_comment
comment|/* r  - status 2 */
end_comment

begin_comment
comment|/*  * Error count registers  */
end_comment

begin_define
define|#
directive|define
name|DS_VCR1
value|0x00
end_define

begin_comment
comment|/* r  - BPV or code violation count 1 */
end_comment

begin_define
define|#
directive|define
name|DS_VCR2
value|0x01
end_define

begin_comment
comment|/* r  - BPV or code violation count 2 */
end_comment

begin_define
define|#
directive|define
name|DS_CRCCR1
value|0x02
end_define

begin_comment
comment|/* r  - CRC4 error count 1 */
end_comment

begin_define
define|#
directive|define
name|DS_CRCCR2
value|0x03
end_define

begin_comment
comment|/* r  - CRC4 error count 2 */
end_comment

begin_define
define|#
directive|define
name|DS_EBCR1
value|0x04
end_define

begin_comment
comment|/* r  - E-bit count 1 */
end_comment

begin_define
define|#
directive|define
name|DS_EBCR2
value|0x05
end_define

begin_comment
comment|/* r  - E-bit count 2 */
end_comment

begin_define
define|#
directive|define
name|DS_FASCR1
value|0x02
end_define

begin_comment
comment|/* r  - FAS error count 1 */
end_comment

begin_define
define|#
directive|define
name|DS_FASCR2
value|0x04
end_define

begin_comment
comment|/* r  - FAS error count 2 */
end_comment

begin_comment
comment|/*  * Signaling registers  */
end_comment

begin_define
define|#
directive|define
name|DS_RS
value|0x30
end_define

begin_comment
comment|/* r  - receive signaling 1..16 */
end_comment

begin_define
define|#
directive|define
name|DS_TS
value|0x40
end_define

begin_comment
comment|/* rw - transmit signaling 1..16 */
end_comment

begin_comment
comment|/*  * Transmit idle registers  */
end_comment

begin_define
define|#
directive|define
name|DS_TIR
value|0x26
end_define

begin_comment
comment|/* rw - transmit idle 1..4 */
end_comment

begin_define
define|#
directive|define
name|DS_TIDR
value|0x2a
end_define

begin_comment
comment|/* rw - transmit idle definition */
end_comment

begin_comment
comment|/*  * Clock blocking registers  */
end_comment

begin_define
define|#
directive|define
name|DS_RCBR
value|0x2b
end_define

begin_comment
comment|/* rw - receive channel blocking 1..4 */
end_comment

begin_define
define|#
directive|define
name|DS_TCBR
value|0x22
end_define

begin_comment
comment|/* rw - transmit channel blocking 1..4 */
end_comment

begin_comment
comment|/*  * Slot 0 registers  */
end_comment

begin_define
define|#
directive|define
name|DS_RAF
value|0x2f
end_define

begin_comment
comment|/* r  - receive align frame */
end_comment

begin_define
define|#
directive|define
name|DS_RNAF
value|0x1f
end_define

begin_comment
comment|/* r  - receive non-align frame */
end_comment

begin_define
define|#
directive|define
name|DS_TAF
value|0x20
end_define

begin_comment
comment|/* rw - transmit align frame */
end_comment

begin_define
define|#
directive|define
name|DS_TNAF
value|0x21
end_define

begin_comment
comment|/* rw - transmit non-align frame */
end_comment

begin_comment
comment|/*----------------------------------------------  * Receive control register 1  */
end_comment

begin_define
define|#
directive|define
name|RCR1_RSO
value|0x00
end_define

begin_comment
comment|/* RSYNC outputs frame boundaries */
end_comment

begin_define
define|#
directive|define
name|RCR1_RSI
value|0x20
end_define

begin_comment
comment|/* RSYNC is input (elastic store) */
end_comment

begin_define
define|#
directive|define
name|RCR1_RSO_CAS
value|0x40
end_define

begin_comment
comment|/* RSYNC outputs CAS multiframe boundaries */
end_comment

begin_define
define|#
directive|define
name|RCR1_RSO_CRC4
value|0xc0
end_define

begin_comment
comment|/* RSYNC outputs CRC4 multiframe boundaries */
end_comment

begin_define
define|#
directive|define
name|RCR1_FRC
value|0x04
end_define

begin_comment
comment|/* frame resync criteria */
end_comment

begin_define
define|#
directive|define
name|RCR1_SYNCD
value|0x02
end_define

begin_comment
comment|/* auto resync disable */
end_comment

begin_define
define|#
directive|define
name|RCR1_RESYNC
value|0x01
end_define

begin_comment
comment|/* force resync */
end_comment

begin_comment
comment|/*  * Receive control register 2  */
end_comment

begin_define
define|#
directive|define
name|RCR2_SA_8
value|0x80
end_define

begin_comment
comment|/* output Sa8 bit at RLINK pin */
end_comment

begin_define
define|#
directive|define
name|RCR2_SA_7
value|0x40
end_define

begin_comment
comment|/* output Sa7 bit at RLINK pin */
end_comment

begin_define
define|#
directive|define
name|RCR2_SA_6
value|0x20
end_define

begin_comment
comment|/* output Sa6 bit at RLINK pin */
end_comment

begin_define
define|#
directive|define
name|RCR2_SA_5
value|0x10
end_define

begin_comment
comment|/* output Sa5 bit at RLINK pin */
end_comment

begin_define
define|#
directive|define
name|RCR2_SA_4
value|0x08
end_define

begin_comment
comment|/* output Sa4 bit at RLINK pin */
end_comment

begin_define
define|#
directive|define
name|RCR2_RSCLKM
value|0x04
end_define

begin_comment
comment|/* receive side SYSCLK mode 2048 */
end_comment

begin_define
define|#
directive|define
name|RCR2_RESE
value|0x02
end_define

begin_comment
comment|/* receive side elastic store enable */
end_comment

begin_comment
comment|/*  * Transmit control register 1  */
end_comment

begin_define
define|#
directive|define
name|TCR1_TFPT
value|0x40
end_define

begin_comment
comment|/* source timeslot 0 from TSER pin */
end_comment

begin_define
define|#
directive|define
name|TCR1_T16S
value|0x20
end_define

begin_comment
comment|/* source timeslot 16 from TS1..TS16 regs */
end_comment

begin_define
define|#
directive|define
name|TCR1_TUA1
value|0x10
end_define

begin_comment
comment|/* transmit unframed all ones */
end_comment

begin_define
define|#
directive|define
name|TCR1_TSIS
value|0x08
end_define

begin_comment
comment|/* source Si bits from TAF/TNAF registers */
end_comment

begin_define
define|#
directive|define
name|TCR1_TSA1
value|0x04
end_define

begin_comment
comment|/* transmit timeslot 16 all ones */
end_comment

begin_define
define|#
directive|define
name|TCR1_TSI
value|0x00
end_define

begin_comment
comment|/* TSYNC is input */
end_comment

begin_define
define|#
directive|define
name|TCR1_TSO
value|0x01
end_define

begin_comment
comment|/* TSYNC outputs frame boundaries */
end_comment

begin_define
define|#
directive|define
name|TCR1_TSO_MF
value|0x03
end_define

begin_comment
comment|/* TSYNC outputs CAS/CRC4 m/f boundaries */
end_comment

begin_comment
comment|/*  * Transmit control register 2  */
end_comment

begin_define
define|#
directive|define
name|TCR2_SA_8
value|0x80
end_define

begin_comment
comment|/* source Sa8 bit from TLINK pin */
end_comment

begin_define
define|#
directive|define
name|TCR2_SA_7
value|0x40
end_define

begin_comment
comment|/* source Sa7 bit from TLINK pin */
end_comment

begin_define
define|#
directive|define
name|TCR2_SA_6
value|0x20
end_define

begin_comment
comment|/* source Sa6 bit from TLINK pin */
end_comment

begin_define
define|#
directive|define
name|TCR2_SA_5
value|0x10
end_define

begin_comment
comment|/* source Sa5 bit from TLINK pin */
end_comment

begin_define
define|#
directive|define
name|TCR2_SA_4
value|0x08
end_define

begin_comment
comment|/* source Sa4 bit from TLINK pin */
end_comment

begin_define
define|#
directive|define
name|TCR2_AEBE
value|0x02
end_define

begin_comment
comment|/* automatic E-bit enable */
end_comment

begin_define
define|#
directive|define
name|TCR2_P16F
value|0x01
end_define

begin_comment
comment|/* pin 16 is Loss of Transmit Clock */
end_comment

begin_comment
comment|/*  * Common control register 1  */
end_comment

begin_define
define|#
directive|define
name|CCR1_FLOOP
value|0x80
end_define

begin_comment
comment|/* enable framer loopback */
end_comment

begin_define
define|#
directive|define
name|CCR1_THDB3
value|0x40
end_define

begin_comment
comment|/* enable transmit HDB3 */
end_comment

begin_define
define|#
directive|define
name|CCR1_TG802
value|0x20
end_define

begin_comment
comment|/* enable transmit G.802 */
end_comment

begin_define
define|#
directive|define
name|CCR1_TCRC4
value|0x10
end_define

begin_comment
comment|/* enable transmit CRC4 */
end_comment

begin_define
define|#
directive|define
name|CCR1_CCS
value|0x08
end_define

begin_comment
comment|/* common channel signaling mode */
end_comment

begin_define
define|#
directive|define
name|CCR1_RHDB3
value|0x04
end_define

begin_comment
comment|/* enable receive HDB3 */
end_comment

begin_define
define|#
directive|define
name|CCR1_RG802
value|0x02
end_define

begin_comment
comment|/* enable receive G.802 */
end_comment

begin_define
define|#
directive|define
name|CCR1_RCRC4
value|0x01
end_define

begin_comment
comment|/* enable receive CRC4 */
end_comment

begin_comment
comment|/*  * Common control register 2  */
end_comment

begin_define
define|#
directive|define
name|CCR2_EC625
value|0x80
end_define

begin_comment
comment|/* update error counters every 62.5 ms */
end_comment

begin_define
define|#
directive|define
name|CCR2_CNTCV
value|0x40
end_define

begin_comment
comment|/* count code violations */
end_comment

begin_define
define|#
directive|define
name|CCR2_AUTOAIS
value|0x20
end_define

begin_comment
comment|/* automatic AIS generation */
end_comment

begin_define
define|#
directive|define
name|CCR2_AUTORA
value|0x10
end_define

begin_comment
comment|/* automatic remote alarm generation */
end_comment

begin_define
define|#
directive|define
name|CCR2_LOFA1
value|0x08
end_define

begin_comment
comment|/* force RSER to 1 under loss of frame align */
end_comment

begin_define
define|#
directive|define
name|CCR2_TRCLK
value|0x04
end_define

begin_comment
comment|/* switch transmitter to RCLK if TCLK stops */
end_comment

begin_define
define|#
directive|define
name|CCR2_RLOOP
value|0x02
end_define

begin_comment
comment|/* enable remote loopback */
end_comment

begin_define
define|#
directive|define
name|CCR2_LLOOP
value|0x01
end_define

begin_comment
comment|/* enable local loopback */
end_comment

begin_comment
comment|/*  * Common control register 3  */
end_comment

begin_define
define|#
directive|define
name|CCR3_TESE
value|0x80
end_define

begin_comment
comment|/* enable transmit elastic store */
end_comment

begin_define
define|#
directive|define
name|CCR3_TCBFS
value|0x40
end_define

begin_comment
comment|/* TCBRs define signaling bits to insert */
end_comment

begin_define
define|#
directive|define
name|CCR3_TIRSER
value|0x20
end_define

begin_comment
comment|/* TIRs define data channels from RSER pin */
end_comment

begin_define
define|#
directive|define
name|CCR3_ESRESET
value|0x10
end_define

begin_comment
comment|/* elastic store reset */
end_comment

begin_define
define|#
directive|define
name|CCR3_LIRESET
value|0x08
end_define

begin_comment
comment|/* line interface reset */
end_comment

begin_define
define|#
directive|define
name|CCR3_THSE
value|0x04
end_define

begin_comment
comment|/* insert signaling from TSIG into TSER */
end_comment

begin_define
define|#
directive|define
name|CCR3_TSCLKM
value|0x02
end_define

begin_comment
comment|/* transmit backplane clock 2048 */
end_comment

begin_comment
comment|/*  * Line interface control register  */
end_comment

begin_define
define|#
directive|define
name|LICR_DB21
value|0x80
end_define

begin_comment
comment|/* return loss 21 dB */
end_comment

begin_define
define|#
directive|define
name|LICR_LB75
value|0x00
end_define

begin_comment
comment|/* 75 Ohm normal */
end_comment

begin_define
define|#
directive|define
name|LICR_LB120
value|0x20
end_define

begin_comment
comment|/* 120 Ohm normal */
end_comment

begin_define
define|#
directive|define
name|LICR_LB75P
value|0x40
end_define

begin_comment
comment|/* 75 Ohm protected */
end_comment

begin_define
define|#
directive|define
name|LICR_LB120P
value|0x60
end_define

begin_comment
comment|/* 120 Ohm protected */
end_comment

begin_define
define|#
directive|define
name|LICR_HIGAIN
value|0x10
end_define

begin_comment
comment|/* receive gain 30 dB */
end_comment

begin_define
define|#
directive|define
name|LICR_JA_TX
value|0x08
end_define

begin_comment
comment|/* transmit side jitter attenuator select */
end_comment

begin_define
define|#
directive|define
name|LICR_JA_LOW
value|0x04
end_define

begin_comment
comment|/* low jitter attenuator depth (32 bits) */
end_comment

begin_define
define|#
directive|define
name|LICR_JA_DISABLE
value|0x02
end_define

begin_comment
comment|/* disable jitter attenuator */
end_comment

begin_define
define|#
directive|define
name|LICR_POWERDOWN
value|0x01
end_define

begin_comment
comment|/* transmit power down */
end_comment

begin_comment
comment|/*----------------------------------------------  * Receive information register  */
end_comment

begin_define
define|#
directive|define
name|RIR_TES_FULL
value|0x80
end_define

begin_comment
comment|/* transmit elastic store full */
end_comment

begin_define
define|#
directive|define
name|RIR_TES_EMPTY
value|0x40
end_define

begin_comment
comment|/* transmit elastic store empty */
end_comment

begin_define
define|#
directive|define
name|RIR_JALT
value|0x20
end_define

begin_comment
comment|/* jitter attenuation limit trip */
end_comment

begin_define
define|#
directive|define
name|RIR_ES_FULL
value|0x10
end_define

begin_comment
comment|/* elastic store full */
end_comment

begin_define
define|#
directive|define
name|RIR_ES_EMPTY
value|0x08
end_define

begin_comment
comment|/* elastic store empty */
end_comment

begin_define
define|#
directive|define
name|RIR_RESYNC_CRC
value|0x04
end_define

begin_comment
comment|/* CRC4 resync (915/1000 errors) */
end_comment

begin_define
define|#
directive|define
name|RIR_RESYNC
value|0x02
end_define

begin_comment
comment|/* frame resync (three consec errors) */
end_comment

begin_define
define|#
directive|define
name|RIR_RESYNC_CAS
value|0x01
end_define

begin_comment
comment|/* CAS resync (two consec errors) */
end_comment

begin_comment
comment|/*  * Synchronizer status register  */
end_comment

begin_define
define|#
directive|define
name|SSR_CSC
parameter_list|(
name|v
parameter_list|)
value|(((v)>> 2)& 0x3c | ((v)>> 3)& 1)
end_define

begin_comment
comment|/* CRC4 sync counter (6 bits, bit 1 n/a) */
end_comment

begin_define
define|#
directive|define
name|SSR_SYNC
value|0x04
end_define

begin_comment
comment|/* frame alignment sync active */
end_comment

begin_define
define|#
directive|define
name|SSR_SYNC_CAS
value|0x02
end_define

begin_comment
comment|/* CAS multiframe sync active */
end_comment

begin_define
define|#
directive|define
name|SSR_SYNC_CRC4
value|0x01
end_define

begin_comment
comment|/* CRC4 multiframe sync active */
end_comment

begin_comment
comment|/*  * Status register 1  */
end_comment

begin_define
define|#
directive|define
name|SR1_RSA1
value|0x80
end_define

begin_comment
comment|/* receive signaling all ones */
end_comment

begin_define
define|#
directive|define
name|SR1_RDMA
value|0x40
end_define

begin_comment
comment|/* receive distant multiframe alarm */
end_comment

begin_define
define|#
directive|define
name|SR1_RSA0
value|0x20
end_define

begin_comment
comment|/* receive signaling all zeros */
end_comment

begin_define
define|#
directive|define
name|SR1_RSLIP
value|0x10
end_define

begin_comment
comment|/* receive elastic store slip event */
end_comment

begin_define
define|#
directive|define
name|SR1_RUA1
value|0x08
end_define

begin_comment
comment|/* receive unframed all ones */
end_comment

begin_define
define|#
directive|define
name|SR1_RRA
value|0x04
end_define

begin_comment
comment|/* receive remote alarm */
end_comment

begin_define
define|#
directive|define
name|SR1_RCL
value|0x02
end_define

begin_comment
comment|/* receive carrier loss */
end_comment

begin_define
define|#
directive|define
name|SR1_RLOS
value|0x01
end_define

begin_comment
comment|/* receive loss of sync */
end_comment

begin_comment
comment|/*  * Status register 2  */
end_comment

begin_define
define|#
directive|define
name|SR2_RMF
value|0x80
end_define

begin_comment
comment|/* receive CAS multiframe (every 2 ms) */
end_comment

begin_define
define|#
directive|define
name|SR2_RAF
value|0x40
end_define

begin_comment
comment|/* receive align frame (every 250 us) */
end_comment

begin_define
define|#
directive|define
name|SR2_TMF
value|0x20
end_define

begin_comment
comment|/* transmit multiframe (every 2 ms) */
end_comment

begin_define
define|#
directive|define
name|SR2_SEC
value|0x10
end_define

begin_comment
comment|/* one second timer (or 62.5 ms) */
end_comment

begin_define
define|#
directive|define
name|SR2_TAF
value|0x08
end_define

begin_comment
comment|/* transmit align frame (every 250 us) */
end_comment

begin_define
define|#
directive|define
name|SR2_LOTC
value|0x04
end_define

begin_comment
comment|/* loss of transmit clock */
end_comment

begin_define
define|#
directive|define
name|SR2_RCMF
value|0x02
end_define

begin_comment
comment|/* receive CRC4 multiframe (every 2 ms) */
end_comment

begin_define
define|#
directive|define
name|SR2_TSLIP
value|0x01
end_define

begin_comment
comment|/* transmit elastic store slip event */
end_comment

begin_comment
comment|/*  * Error count registers  */
end_comment

begin_define
define|#
directive|define
name|VCR
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|(((short) (h)<< 8) | (l))
end_define

begin_comment
comment|/* 16-bit code violation */
end_comment

begin_define
define|#
directive|define
name|CRCCR
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|(((short) (h)<< 8& 0x300) | (l))
end_define

begin_comment
comment|/* 10-bit CRC4 error count */
end_comment

begin_define
define|#
directive|define
name|EBCR
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|(((short) (h)<< 8& 0x300) | (l))
end_define

begin_comment
comment|/* 10-bit E-bit count */
end_comment

begin_define
define|#
directive|define
name|FASCR
parameter_list|(
name|h
parameter_list|,
name|l
parameter_list|)
value|(((short) (h)<< 4& 0xfc0) | (l)>> 2)
end_define

begin_comment
comment|/* 12-bit FAS error count */
end_comment

begin_define
define|#
directive|define
name|FASCRH
parameter_list|(
name|h
parameter_list|)
value|((h)<< 4)
end_define

begin_comment
comment|/* 12-bit FAS error count */
end_comment

begin_define
define|#
directive|define
name|FASCRL
parameter_list|(
name|l
parameter_list|)
value|((l)>> 2)
end_define

begin_comment
comment|/* 12-bit FAS error count */
end_comment

begin_comment
comment|/*  * DS21x54 additional registers  */
end_comment

begin_define
define|#
directive|define
name|DS_IDR
value|0x0f
end_define

begin_comment
comment|/* r  - device id */
end_comment

begin_define
define|#
directive|define
name|DS_TSACR
value|0x1c
end_define

begin_comment
comment|/* rw - transmit Sa bit control */
end_comment

begin_define
define|#
directive|define
name|DS_CCR6
value|0x1d
end_define

begin_comment
comment|/* rw - common control 6 */
end_comment

begin_define
define|#
directive|define
name|DS_TSIAF
value|0x50
end_define

begin_comment
comment|/* rw - transmit Si bits align frame */
end_comment

begin_define
define|#
directive|define
name|DS_TSINAF
value|0x51
end_define

begin_comment
comment|/* rw - transmit Si bits non-align frame */
end_comment

begin_define
define|#
directive|define
name|DS_TRA
value|0x52
end_define

begin_comment
comment|/* rw - transmit remote alarm bits */
end_comment

begin_define
define|#
directive|define
name|DS_TSA4
value|0x53
end_define

begin_comment
comment|/* rw - transmit Sa4 bits */
end_comment

begin_define
define|#
directive|define
name|DS_TSA5
value|0x54
end_define

begin_comment
comment|/* rw - transmit Sa5 bits */
end_comment

begin_define
define|#
directive|define
name|DS_TSA6
value|0x55
end_define

begin_comment
comment|/* rw - transmit Sa6 bits */
end_comment

begin_define
define|#
directive|define
name|DS_TSA7
value|0x56
end_define

begin_comment
comment|/* rw - transmit Sa7 bits */
end_comment

begin_define
define|#
directive|define
name|DS_TSA8
value|0x57
end_define

begin_comment
comment|/* rw - transmit Sa8 bits */
end_comment

begin_define
define|#
directive|define
name|DS_RSIAF
value|0x58
end_define

begin_comment
comment|/* r  - receive Si bits align frame */
end_comment

begin_define
define|#
directive|define
name|DS_RSINAF
value|0x59
end_define

begin_comment
comment|/* r  - receive Si bits non-align frame */
end_comment

begin_define
define|#
directive|define
name|DS_RRA
value|0x5a
end_define

begin_comment
comment|/* r  - receive remote alarm bits */
end_comment

begin_define
define|#
directive|define
name|DS_RSA4
value|0x5b
end_define

begin_comment
comment|/* r  - receive Sa4 bits */
end_comment

begin_define
define|#
directive|define
name|DS_RSA5
value|0x5c
end_define

begin_comment
comment|/* r  - receive Sa5 bits */
end_comment

begin_define
define|#
directive|define
name|DS_RSA6
value|0x5d
end_define

begin_comment
comment|/* r  - receive Sa6 bits */
end_comment

begin_define
define|#
directive|define
name|DS_RSA7
value|0x5e
end_define

begin_comment
comment|/* r  - receive Sa7 bits */
end_comment

begin_define
define|#
directive|define
name|DS_RSA8
value|0x5f
end_define

begin_comment
comment|/* r  - receive Sa8 bits */
end_comment

begin_define
define|#
directive|define
name|DS_TCC1
value|0xa0
end_define

begin_comment
comment|/* rw - transmit channel control 1 */
end_comment

begin_define
define|#
directive|define
name|DS_TCC2
value|0xa1
end_define

begin_comment
comment|/* rw - transmit channel control 2 */
end_comment

begin_define
define|#
directive|define
name|DS_TCC3
value|0xa2
end_define

begin_comment
comment|/* rw - transmit channel control 3 */
end_comment

begin_define
define|#
directive|define
name|DS_TCC4
value|0xa3
end_define

begin_comment
comment|/* rw - transmit channel control 4 */
end_comment

begin_define
define|#
directive|define
name|DS_RCC1
value|0xa4
end_define

begin_comment
comment|/* rw - receive channel control 1 */
end_comment

begin_define
define|#
directive|define
name|DS_RCC2
value|0xa5
end_define

begin_comment
comment|/* rw - receive channel control 2 */
end_comment

begin_define
define|#
directive|define
name|DS_RCC3
value|0xa6
end_define

begin_comment
comment|/* rw - receive channel control 3 */
end_comment

begin_define
define|#
directive|define
name|DS_RCC4
value|0xa7
end_define

begin_comment
comment|/* rw - receive channel control 4 */
end_comment

begin_define
define|#
directive|define
name|DS_CCR4
value|0xa8
end_define

begin_comment
comment|/* rw - common control 4 */
end_comment

begin_define
define|#
directive|define
name|DS_TDS0M
value|0xa9
end_define

begin_comment
comment|/* r  - transmit ds0 monitor */
end_comment

begin_define
define|#
directive|define
name|DS_CCR5
value|0xaa
end_define

begin_comment
comment|/* rw - common control 5 */
end_comment

begin_define
define|#
directive|define
name|DS_RDS0M
value|0xab
end_define

begin_comment
comment|/* r  - receive ds0 monitor */
end_comment

begin_define
define|#
directive|define
name|DS_TEST3
value|0xac
end_define

begin_comment
comment|/* rw - test 3, set to 00h */
end_comment

begin_define
define|#
directive|define
name|DS_HCR
value|0xb0
end_define

begin_comment
comment|/* rw - hdlc control */
end_comment

begin_define
define|#
directive|define
name|DS_HSR
value|0xb1
end_define

begin_comment
comment|/* rw - hdlc status */
end_comment

begin_define
define|#
directive|define
name|DS_HIMR
value|0xb2
end_define

begin_comment
comment|/* rw - hdlc interrupt mask */
end_comment

begin_define
define|#
directive|define
name|DS_RHIR
value|0xb3
end_define

begin_comment
comment|/* rw - receive hdlc information */
end_comment

begin_define
define|#
directive|define
name|DS_RHFR
value|0xb4
end_define

begin_comment
comment|/* rw - receive hdlc fifo */
end_comment

begin_define
define|#
directive|define
name|DS_IBO
value|0xb5
end_define

begin_comment
comment|/* rw - interleave bus operation */
end_comment

begin_define
define|#
directive|define
name|DS_THIR
value|0xb6
end_define

begin_comment
comment|/* rw - transmit hdlc information */
end_comment

begin_define
define|#
directive|define
name|DS_THFR
value|0xb7
end_define

begin_comment
comment|/* rw - transmit hdlc fifo */
end_comment

begin_define
define|#
directive|define
name|DS_RDC1
value|0xb8
end_define

begin_comment
comment|/* rw - receive hdlc ds0 control 1 */
end_comment

begin_define
define|#
directive|define
name|DS_RDC2
value|0xb9
end_define

begin_comment
comment|/* rw - receive hdlc ds0 control 2 */
end_comment

begin_define
define|#
directive|define
name|DS_TDC1
value|0xba
end_define

begin_comment
comment|/* rw - transmit hdlc ds0 control 1 */
end_comment

begin_define
define|#
directive|define
name|DS_TDC2
value|0xbb
end_define

begin_comment
comment|/* rw - transmit hdlc ds0 control 2 */
end_comment

begin_define
define|#
directive|define
name|CCR4_RLB
value|0x80
end_define

begin_comment
comment|/* enable remote loopback */
end_comment

begin_define
define|#
directive|define
name|CCR4_LLB
value|0x40
end_define

begin_comment
comment|/* enable local loopback */
end_comment

begin_define
define|#
directive|define
name|CCR5_LIRST
value|0x80
end_define

begin_comment
comment|/* line interface reset */
end_comment

begin_define
define|#
directive|define
name|CCR6_RESR
value|0x02
end_define

begin_comment
comment|/* receive elastic store reset */
end_comment

begin_define
define|#
directive|define
name|CCR6_TESR
value|0x01
end_define

begin_comment
comment|/* transmit elastic store reset */
end_comment

end_unit

