begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Aleksandr Rybalko.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RT_SWREG_H_
end_ifndef

begin_define
define|#
directive|define
name|_RT_SWREG_H_
end_define

begin_comment
comment|/* XXX: must move to config */
end_comment

begin_define
define|#
directive|define
name|RT3052F
end_define

begin_define
define|#
directive|define
name|RT_SW_BASE
value|0x10110000
end_define

begin_define
define|#
directive|define
name|RT_SW_ISR
value|0x00
end_define

begin_define
define|#
directive|define
name|WATCHDOG1_TMR_EXPIRED
value|(1<<29)
end_define

begin_define
define|#
directive|define
name|WATCHDOG0_TMR_EXPIRED
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|HAS_INTRUDER
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|PORT_ST_CHG
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|BC_STORM
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|MUST_DROP_LAN
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|GLOBAL_QUE_FULL
value|(1<<23)
end_define

begin_define
define|#
directive|define
name|LAN_QUE_FULL6
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|LAN_QUE_FULL5
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|LAN_QUE_FULL4
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|LAN_QUE_FULL3
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|LAN_QUE_FULL2
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|LAN_QUE_FULL1
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|LAN_QUE_FULL0
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|RT_SW_IMR
value|0x04
end_define

begin_define
define|#
directive|define
name|RT_SW_FCT0
value|0x08
end_define

begin_define
define|#
directive|define
name|RT_SW_FCT1
value|0x0c
end_define

begin_define
define|#
directive|define
name|RT_SW_PFC0
value|0x10
end_define

begin_define
define|#
directive|define
name|RT_SW_PFC1
value|0x14
end_define

begin_define
define|#
directive|define
name|RT_SW_PFC2
value|0x18
end_define

begin_define
define|#
directive|define
name|RT_SW_GQS0
value|0x1c
end_define

begin_define
define|#
directive|define
name|RT_SW_GQS1
value|0x20
end_define

begin_define
define|#
directive|define
name|RT_SW_ATS
value|0x24
end_define

begin_define
define|#
directive|define
name|RT_SW_ATS0
value|0x28
end_define

begin_define
define|#
directive|define
name|RT_SW_ATS1
value|0x2c
end_define

begin_define
define|#
directive|define
name|RT_SW_ATS2
value|0x30
end_define

begin_define
define|#
directive|define
name|RT_SW_WMAD0
value|0x34
end_define

begin_define
define|#
directive|define
name|RT_SW_WMAD1
value|0x38
end_define

begin_define
define|#
directive|define
name|RT_SW_WMAD2
value|0x3c
end_define

begin_define
define|#
directive|define
name|RT_SW_PVIDC0
value|0x40
end_define

begin_define
define|#
directive|define
name|RT_SW_PVIDC1
value|0x44
end_define

begin_define
define|#
directive|define
name|RT_SW_PVIDC2
value|0x48
end_define

begin_define
define|#
directive|define
name|RT_SW_PVIDC3
value|0x4c
end_define

begin_define
define|#
directive|define
name|RT_SW_VID0
value|0x50
end_define

begin_define
define|#
directive|define
name|RT_SW_VID1
value|0x54
end_define

begin_define
define|#
directive|define
name|RT_SW_VID2
value|0x58
end_define

begin_define
define|#
directive|define
name|RT_SW_VID3
value|0x5c
end_define

begin_define
define|#
directive|define
name|RT_SW_VID4
value|0x60
end_define

begin_define
define|#
directive|define
name|RT_SW_VID5
value|0x64
end_define

begin_define
define|#
directive|define
name|RT_SW_VID6
value|0x68
end_define

begin_define
define|#
directive|define
name|RT_SW_VID7
value|0x6c
end_define

begin_define
define|#
directive|define
name|RT_SW_VMSC0
value|0x70
end_define

begin_define
define|#
directive|define
name|RT_SW_VMSC1
value|0x74
end_define

begin_define
define|#
directive|define
name|RT_SW_VMSC2
value|0x78
end_define

begin_define
define|#
directive|define
name|RT_SW_VMSC3
value|0x7c
end_define

begin_define
define|#
directive|define
name|RT_SW_POA
value|0x80
end_define

begin_define
define|#
directive|define
name|RT_SW_FPA
value|0x84
end_define

begin_define
define|#
directive|define
name|RT_SW_PTS
value|0x88
end_define

begin_define
define|#
directive|define
name|RT_SW_SOCPC
value|0x8c
end_define

begin_define
define|#
directive|define
name|RT_SW_POC0
value|0x90
end_define

begin_define
define|#
directive|define
name|RT_SW_POC1
value|0x94
end_define

begin_define
define|#
directive|define
name|RT_SW_POC2
value|0x98
end_define

begin_define
define|#
directive|define
name|RT_SW_SGC
value|0x9c
end_define

begin_define
define|#
directive|define
name|RT_SW_STRT
value|0xa0
end_define

begin_define
define|#
directive|define
name|RT_SW_LEDP0
value|0xa4
end_define

begin_define
define|#
directive|define
name|RT_SW_LEDP1
value|0xa8
end_define

begin_define
define|#
directive|define
name|RT_SW_LEDP2
value|0xac
end_define

begin_define
define|#
directive|define
name|RT_SW_LEDP3
value|0xb0
end_define

begin_define
define|#
directive|define
name|RT_SW_LEDP4
value|0xb4
end_define

begin_define
define|#
directive|define
name|RT_SW_WDTR
value|0xb8
end_define

begin_define
define|#
directive|define
name|RT_SW_DES
value|0xbc
end_define

begin_define
define|#
directive|define
name|RT_SW_PCR0
value|0xc0
end_define

begin_define
define|#
directive|define
name|RT_SW_PCR1
value|0xc4
end_define

begin_define
define|#
directive|define
name|RT_SW_FPA
value|0xc8
end_define

begin_define
define|#
directive|define
name|RT_SW_FCT2
value|0xcc
end_define

begin_define
define|#
directive|define
name|RT_SW_QSS0
value|0xd0
end_define

begin_define
define|#
directive|define
name|RT_SW_QSS1
value|0xd4
end_define

begin_define
define|#
directive|define
name|RT_SW_DEC
value|0xd8
end_define

begin_define
define|#
directive|define
name|BRIDGE_IPG_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|DEBUG_SW_PORT_SEL_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|DEBUG_SW_PORT_SEL_MASK
value|0x00000038
end_define

begin_define
define|#
directive|define
name|RT_SW_MTI
value|0xdc
end_define

begin_define
define|#
directive|define
name|SKIP_BLOCKS_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|SKIP_BLOCKS_MASK
value|0x0000ff80
end_define

begin_define
define|#
directive|define
name|SW_RAM_TEST_DONE
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|AT_RAM_TEST_DONE
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|AT_RAM_TEST_FAIL
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|LK_RAM_TEST_DONE
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|LK_RAM_TEST_FAIL
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|DT_RAM_TEST_DONE
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|DT_RAM_TEST_FAIL
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|RT_SW_PPC
value|0xe0
end_define

begin_define
define|#
directive|define
name|SW2FE_CNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FE2SW_CNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|RT_SW_SGC2
value|0xe4
end_define

begin_define
define|#
directive|define
name|FE2SW_WL_FC_EN
value|(1<<30)
end_define

begin_define
define|#
directive|define
name|LAN_PMAP_P0_IS_LAN
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|LAN_PMAP_P1_IS_LAN
value|(1<<25)
end_define

begin_define
define|#
directive|define
name|LAN_PMAP_P2_IS_LAN
value|(1<<26)
end_define

begin_define
define|#
directive|define
name|LAN_PMAP_P3_IS_LAN
value|(1<<27)
end_define

begin_define
define|#
directive|define
name|LAN_PMAP_P4_IS_LAN
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|LAN_PMAP_P5_IS_LAN
value|(1<<29)
end_define

begin_comment
comment|/* Transmit CPU TPID(810x) port bit map */
end_comment

begin_define
define|#
directive|define
name|TX_CPU_TPID_BIT_MAP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|TX_CPU_TPID_BIT_MAP_MASK
value|0x007f0000
end_define

begin_define
define|#
directive|define
name|ARBITER_LAN_EN
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|CPU_TPID_EN
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|P0_DOUBLE_TAG_EN
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|P1_DOUBLE_TAG_EN
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|P2_DOUBLE_TAG_EN
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|P3_DOUBLE_TAG_EN
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|P4_DOUBLE_TAG_EN
value|(1<<4)
end_define

begin_define
define|#
directive|define
name|P5_DOUBLE_TAG_EN
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|RT_SW_P0PC
value|0xe8
end_define

begin_define
define|#
directive|define
name|RT_SW_P1PC
value|0xec
end_define

begin_define
define|#
directive|define
name|RT_SW_P2PC
value|0xf0
end_define

begin_define
define|#
directive|define
name|RT_SW_P3PC
value|0xf4
end_define

begin_define
define|#
directive|define
name|RT_SW_P4PC
value|0xf8
end_define

begin_define
define|#
directive|define
name|RT_SW_P5PC
value|0xfc
end_define

begin_define
define|#
directive|define
name|BAD_PCOUNT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BAD_PCOUNT_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|GOOD_PCOUNT_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GOOD_PCOUNT_MASK
value|0x0000ffff
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RT_SWREG_H_ */
end_comment

end_unit

