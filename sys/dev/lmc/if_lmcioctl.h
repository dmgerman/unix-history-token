begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994-1997 Matt Thomas (matt@3am-software.com)  * Copyright (c) LAN Media Corporation 1998, 1999.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  *	$Id: if_lmcioctl.h,v 1.9 1999/02/18 10:30:18 explorer Exp $  */
end_comment

begin_comment
comment|/*  * IOCTLs for the sane world.  */
end_comment

begin_define
define|#
directive|define
name|LMCIOCGINFO
value|_IOW('i', 240, struct ifreq)
end_define

begin_define
define|#
directive|define
name|LMCIOCSINFO
value|_IOWR('i', 241, struct ifreq)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|n
decl_stmt|;
name|u_int32_t
name|m
decl_stmt|;
name|u_int32_t
name|v
decl_stmt|;
name|u_int32_t
name|x
decl_stmt|;
name|u_int32_t
name|r
decl_stmt|;
name|u_int32_t
name|f
decl_stmt|;
name|u_int32_t
name|exact
decl_stmt|;
block|}
name|lmc_av9110_t
typedef|;
end_typedef

begin_comment
comment|/*  * Common structure passed to the ioctl code.  */
end_comment

begin_struct
struct|struct
name|lmc___ctl
block|{
name|u_int32_t
name|cardtype
decl_stmt|;
name|u_int32_t
name|clock_source
decl_stmt|;
comment|/* HSSI, SSI */
name|u_int32_t
name|clock_rate
decl_stmt|;
comment|/* SSI */
name|u_int32_t
name|crc_length
decl_stmt|;
name|u_int32_t
name|cable_length
decl_stmt|;
comment|/* DS3 */
name|u_int32_t
name|scrambler_onoff
decl_stmt|;
comment|/* DS3 */
name|u_int32_t
name|cable_type
decl_stmt|;
comment|/* SSI */
name|u_int32_t
name|keepalive_onoff
decl_stmt|;
comment|/* protocol */
name|u_int32_t
name|ticks
decl_stmt|;
comment|/* ticks/sec */
union|union
block|{
name|lmc_av9110_t
name|ssi
decl_stmt|;
block|}
name|cardspec
union|;
name|u_int32_t
name|circuit_type
decl_stmt|;
comment|/* T1 or E1 circuit */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|LMC_CTL_CARDTYPE_LMC5200
value|0
end_define

begin_comment
comment|/* HSSI */
end_comment

begin_define
define|#
directive|define
name|LMC_CTL_CARDTYPE_LMC5245
value|1
end_define

begin_comment
comment|/* DS3 */
end_comment

begin_define
define|#
directive|define
name|LMC_CTL_CARDTYPE_LMC1000
value|2
end_define

begin_comment
comment|/* SSI, E1, etc */
end_comment

begin_define
define|#
directive|define
name|LMC_CTL_CARDTYPE_LMC1200
value|3
end_define

begin_comment
comment|/* T1 */
end_comment

begin_define
define|#
directive|define
name|LMC_CTL_OFF
value|0
end_define

begin_comment
comment|/* generic OFF value */
end_comment

begin_define
define|#
directive|define
name|LMC_CTL_ON
value|1
end_define

begin_comment
comment|/* generic ON value */
end_comment

begin_define
define|#
directive|define
name|LMC_CTL_CLOCK_SOURCE_EXT
value|0
end_define

begin_comment
comment|/* clock off line */
end_comment

begin_define
define|#
directive|define
name|LMC_CTL_CLOCK_SOURCE_INT
value|1
end_define

begin_comment
comment|/* internal clock */
end_comment

begin_define
define|#
directive|define
name|LMC_CTL_CRC_LENGTH_16
value|16
end_define

begin_define
define|#
directive|define
name|LMC_CTL_CRC_LENGTH_32
value|32
end_define

begin_define
define|#
directive|define
name|LMC_CTL_CRC_BYTESIZE_2
value|2
end_define

begin_define
define|#
directive|define
name|LMC_CTL_CRC_BYTESIZE_4
value|4
end_define

begin_define
define|#
directive|define
name|LMC_CTL_CABLE_LENGTH_LT_100FT
value|0
end_define

begin_comment
comment|/* DS3 cable< 100 feet */
end_comment

begin_define
define|#
directive|define
name|LMC_CTL_CABLE_LENGTH_GT_100FT
value|1
end_define

begin_comment
comment|/* DS3 cable>= 100 feet */
end_comment

begin_define
define|#
directive|define
name|LMC_CTL_CIRCUIT_TYPE_E1
value|0
end_define

begin_define
define|#
directive|define
name|LMC_CTL_CIRCUIT_TYPE_T1
value|1
end_define

begin_comment
comment|/*  * These are not in the least IOCTL related, but I want them common.  */
end_comment

begin_comment
comment|/*  * assignments for the GPIO register on the DEC chip (common)  */
end_comment

begin_define
define|#
directive|define
name|LMC_GEP_INIT
value|0x01
end_define

begin_comment
comment|/* 0: */
end_comment

begin_define
define|#
directive|define
name|LMC_GEP_RESET
value|0x02
end_define

begin_comment
comment|/* 1: */
end_comment

begin_define
define|#
directive|define
name|LMC_GEP_LOAD
value|0x10
end_define

begin_comment
comment|/* 4: */
end_comment

begin_define
define|#
directive|define
name|LMC_GEP_DP
value|0x20
end_define

begin_comment
comment|/* 5: */
end_comment

begin_define
define|#
directive|define
name|LMC_GEP_SERIAL
value|0x40
end_define

begin_comment
comment|/* 6: serial out */
end_comment

begin_define
define|#
directive|define
name|LMC_GEP_SERIALCLK
value|0x80
end_define

begin_comment
comment|/* 7: serial clock */
end_comment

begin_comment
comment|/*  * HSSI GPIO assignments  */
end_comment

begin_define
define|#
directive|define
name|LMC_GEP_HSSI_ST
value|0x04
end_define

begin_comment
comment|/* 2: receive timing sense (deprecated) */
end_comment

begin_define
define|#
directive|define
name|LMC_GEP_HSSI_CLOCK
value|0x08
end_define

begin_comment
comment|/* 3: clock source */
end_comment

begin_comment
comment|/*  * SSI GPIO assignments  */
end_comment

begin_define
define|#
directive|define
name|LMC_GEP_SSI_GENERATOR
value|0x04
end_define

begin_comment
comment|/* 2: enable prog freq gen serial i/f */
end_comment

begin_define
define|#
directive|define
name|LMC_GEP_SSI_TXCLOCK
value|0x08
end_define

begin_comment
comment|/* 3: provide clock on TXCLOCK output */
end_comment

begin_comment
comment|/* Note: 2 pairs of LEDs where swapped by mistake  * in Xilinx code for DS3& DS1 adapters */
end_comment

begin_define
define|#
directive|define
name|LMC_DS3_LED0
value|0x0100
end_define

begin_comment
comment|/* bit 08  yellow */
end_comment

begin_define
define|#
directive|define
name|LMC_DS3_LED1
value|0x0080
end_define

begin_comment
comment|/* bit 07  blue   */
end_comment

begin_define
define|#
directive|define
name|LMC_DS3_LED2
value|0x0400
end_define

begin_comment
comment|/* bit 10  green  */
end_comment

begin_define
define|#
directive|define
name|LMC_DS3_LED3
value|0x0200
end_define

begin_comment
comment|/* bit 09  red    */
end_comment

begin_comment
comment|/*  * Common MII16 bits  */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_LED0
value|0x0080
end_define

begin_define
define|#
directive|define
name|LMC_MII16_LED1
value|0x0100
end_define

begin_define
define|#
directive|define
name|LMC_MII16_LED2
value|0x0200
end_define

begin_define
define|#
directive|define
name|LMC_MII16_LED3
value|0x0400
end_define

begin_comment
comment|/* Error, and the red one */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_LED_ALL
value|0x0780
end_define

begin_comment
comment|/* LED bit mask */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_FIFO_RESET
value|0x0800
end_define

begin_comment
comment|/*  * definitions for HSSI  */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_HSSI_TA
value|0x0001
end_define

begin_define
define|#
directive|define
name|LMC_MII16_HSSI_CA
value|0x0002
end_define

begin_define
define|#
directive|define
name|LMC_MII16_HSSI_LA
value|0x0004
end_define

begin_define
define|#
directive|define
name|LMC_MII16_HSSI_LB
value|0x0008
end_define

begin_define
define|#
directive|define
name|LMC_MII16_HSSI_LC
value|0x0010
end_define

begin_define
define|#
directive|define
name|LMC_MII16_HSSI_TM
value|0x0020
end_define

begin_define
define|#
directive|define
name|LMC_MII16_HSSI_CRC
value|0x0040
end_define

begin_comment
comment|/*  * assignments for the MII register 16 (DS3)  */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_DS3_ZERO
value|0x0001
end_define

begin_define
define|#
directive|define
name|LMC_MII16_DS3_TRLBK
value|0x0002
end_define

begin_define
define|#
directive|define
name|LMC_MII16_DS3_LNLBK
value|0x0004
end_define

begin_define
define|#
directive|define
name|LMC_MII16_DS3_RAIS
value|0x0008
end_define

begin_define
define|#
directive|define
name|LMC_MII16_DS3_TAIS
value|0x0010
end_define

begin_define
define|#
directive|define
name|LMC_MII16_DS3_BIST
value|0x0020
end_define

begin_define
define|#
directive|define
name|LMC_MII16_DS3_DLOS
value|0x0040
end_define

begin_define
define|#
directive|define
name|LMC_MII16_DS3_CRC
value|0x1000
end_define

begin_define
define|#
directive|define
name|LMC_MII16_DS3_SCRAM
value|0x2000
end_define

begin_comment
comment|/*  * And SSI  */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_SSI_DTR
value|0x0001
end_define

begin_comment
comment|/* DTR output RW */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_SSI_DSR
value|0x0002
end_define

begin_comment
comment|/* DSR input RO */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_SSI_RTS
value|0x0004
end_define

begin_comment
comment|/* RTS output RW */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_SSI_CTS
value|0x0008
end_define

begin_comment
comment|/* CTS input RO */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_SSI_DCD
value|0x0010
end_define

begin_comment
comment|/* DCD input RO */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_SSI_RI
value|0x0020
end_define

begin_comment
comment|/* RI input RO */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_SSI_CRC
value|0x0040
end_define

begin_comment
comment|/* CRC select */
end_comment

begin_comment
comment|/*  * bits 0x0080 through 0x0800 are generic, and described  * above with LMC_MII16_LED[0123] _LED_ALL, and _FIFO_RESET  */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_SSI_LL
value|0x1000
end_define

begin_comment
comment|/* LL output RW */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_SSI_RL
value|0x2000
end_define

begin_comment
comment|/* RL output RW */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_SSI_TM
value|0x4000
end_define

begin_comment
comment|/* TM input RO */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_SSI_LOOP
value|0x8000
end_define

begin_comment
comment|/* loopback enable RW */
end_comment

begin_comment
comment|/*  * Some of the MII16 bits are mirrored in the MII17 register as well,  * but let's keep thing seperate for now, and get only the cable from  * the MII17.  */
end_comment

begin_define
define|#
directive|define
name|LMC_MII17_SSI_CABLE_MASK
value|0x0038
end_define

begin_comment
comment|/* mask to extract the cable type */
end_comment

begin_define
define|#
directive|define
name|LMC_MII17_SSI_CABLE_SHIFT
value|3
end_define

begin_comment
comment|/* shift to extract the cable type */
end_comment

begin_comment
comment|/*  * framer register 0 and 7 (7 is latched and reset on read)  */
end_comment

begin_define
define|#
directive|define
name|LMC_FRAMER_REG0_DLOS
value|0x80
end_define

begin_comment
comment|/* digital loss of service */
end_comment

begin_define
define|#
directive|define
name|LMC_FRAMER_REG0_OOFS
value|0x40
end_define

begin_comment
comment|/* out of frame sync */
end_comment

begin_define
define|#
directive|define
name|LMC_FRAMER_REG0_AIS
value|0x20
end_define

begin_comment
comment|/* alarm indication signal */
end_comment

begin_define
define|#
directive|define
name|LMC_FRAMER_REG0_CIS
value|0x10
end_define

begin_comment
comment|/* channel idle */
end_comment

begin_define
define|#
directive|define
name|LMC_FRAMER_REG0_LOC
value|0x08
end_define

begin_comment
comment|/* loss of clock */
end_comment

begin_define
define|#
directive|define
name|LMC_CARDTYPE_UNKNOWN
value|-1
end_define

begin_define
define|#
directive|define
name|LMC_CARDTYPE_HSSI
value|1
end_define

begin_comment
comment|/* probed card is a HSSI card */
end_comment

begin_define
define|#
directive|define
name|LMC_CARDTYPE_DS3
value|2
end_define

begin_comment
comment|/* probed card is a DS3 card */
end_comment

begin_define
define|#
directive|define
name|LMC_CARDTYPE_SSI
value|3
end_define

begin_comment
comment|/* probed card is a SSI card */
end_comment

begin_define
define|#
directive|define
name|LMC_CARDTYPE_T1
value|4
end_define

begin_comment
comment|/* probed card is a T1 card */
end_comment

begin_comment
comment|/*  * framer register 0 and 7 (7 is latched and reset on read)  */
end_comment

begin_define
define|#
directive|define
name|LMC_FRAMER_REG0_DLOS
value|0x80
end_define

begin_comment
comment|/* digital loss of service */
end_comment

begin_define
define|#
directive|define
name|LMC_FRAMER_REG0_OOFS
value|0x40
end_define

begin_comment
comment|/* out of frame sync */
end_comment

begin_define
define|#
directive|define
name|LMC_FRAMER_REG0_AIS
value|0x20
end_define

begin_comment
comment|/* alarm indication signal */
end_comment

begin_define
define|#
directive|define
name|LMC_FRAMER_REG0_CIS
value|0x10
end_define

begin_comment
comment|/* channel idle */
end_comment

begin_define
define|#
directive|define
name|LMC_FRAMER_REG0_LOC
value|0x08
end_define

begin_comment
comment|/* loss of clock */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_T1_UNUSED1
value|0x0003
end_define

begin_define
define|#
directive|define
name|LMC_MII16_T1_XOE
value|0x0004
end_define

begin_define
define|#
directive|define
name|LMC_MII16_T1_RST
value|0x0008
end_define

begin_comment
comment|/* T1 chip reset - RW */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_T1_Z
value|0x0010
end_define

begin_comment
comment|/* output impedance T1=1, E1=0 output - RW */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_T1_INTR
value|0x0020
end_define

begin_comment
comment|/* interrupt from 8370 - RO */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_T1_ONESEC
value|0x0040
end_define

begin_comment
comment|/* one second square wave - ro */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_T1_LED0
value|0x0100
end_define

begin_define
define|#
directive|define
name|LMC_MII16_T1_LED1
value|0x0080
end_define

begin_define
define|#
directive|define
name|LMC_MII16_T1_LED2
value|0x0400
end_define

begin_define
define|#
directive|define
name|LMC_MII16_T1_LED3
value|0x0200
end_define

begin_define
define|#
directive|define
name|LMC_MII16_T1_FIFO_RESET
value|0x0800
end_define

begin_define
define|#
directive|define
name|LMC_MII16_T1_CRC
value|0x1000
end_define

begin_comment
comment|/* CRC select - RW */
end_comment

begin_define
define|#
directive|define
name|LMC_MII16_T1_UNUSED2
value|0xe000
end_define

begin_define
define|#
directive|define
name|T1FRAMER_ALARM1_STATUS
value|0x47
end_define

begin_define
define|#
directive|define
name|T1FRAMER_ALARM2_STATUS
value|0x48
end_define

begin_define
define|#
directive|define
name|T1FRAMER_FERR_LSB
value|0x50
end_define

begin_define
define|#
directive|define
name|T1FRAMER_FERR_MSB
value|0x51
end_define

begin_comment
comment|/* framing bit error counter */
end_comment

begin_define
define|#
directive|define
name|T1FRAMER_LCV_LSB
value|0x54
end_define

begin_define
define|#
directive|define
name|T1FRAMER_LCV_MSB
value|0x55
end_define

begin_comment
comment|/* line code violation counter */
end_comment

begin_define
define|#
directive|define
name|T1FRAMER_AERR
value|0x5A
end_define

begin_comment
comment|/* mask for the above AERR register */
end_comment

begin_define
define|#
directive|define
name|T1FRAMER_LOF_MASK
value|(0x0f0)
end_define

begin_comment
comment|/* receive loss of frame */
end_comment

begin_define
define|#
directive|define
name|T1FRAMER_COFA_MASK
value|(0x0c0)
end_define

begin_comment
comment|/* change of frame alignment */
end_comment

begin_define
define|#
directive|define
name|T1FRAMER_SEF_MASK
value|(0x03)
end_define

begin_comment
comment|/* severely errored frame  */
end_comment

begin_comment
comment|/* 8370 framer register ALM1 (0x47) values  * used to determine link status  */
end_comment

begin_define
define|#
directive|define
name|T1F_SIGFRZ
value|0x01
end_define

begin_comment
comment|/* signaling freeze */
end_comment

begin_define
define|#
directive|define
name|T1F_RLOF
value|0x02
end_define

begin_comment
comment|/* receive loss of frame alignment */
end_comment

begin_define
define|#
directive|define
name|T1F_RLOS
value|0x04
end_define

begin_comment
comment|/* receive loss of signal */
end_comment

begin_define
define|#
directive|define
name|T1F_RALOS
value|0x08
end_define

begin_comment
comment|/* receive analog loss of signal or RCKI loss of clock */
end_comment

begin_define
define|#
directive|define
name|T1F_RAIS
value|0x10
end_define

begin_comment
comment|/* receive alarm indication signal */
end_comment

begin_define
define|#
directive|define
name|T1F_UNUSED
value|0x20
end_define

begin_define
define|#
directive|define
name|T1F_RYEL
value|0x40
end_define

begin_comment
comment|/* receive yellow alarm */
end_comment

begin_define
define|#
directive|define
name|T1F_RMYEL
value|0x80
end_define

begin_comment
comment|/* receive multiframe yellow alarm */
end_comment

begin_comment
comment|/* ------------------ end T1 defs ------------------- */
end_comment

begin_define
define|#
directive|define
name|LMC_MII_LedMask
value|0x0780
end_define

begin_define
define|#
directive|define
name|LMC_MII_LedBitPos
value|7
end_define

begin_comment
comment|/*  * NetBSD uses _KERNEL, FreeBSD uses KERNEL.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|__KERNEL__
argument_list|)
end_if

begin_comment
comment|/*  * media independent methods to check on media status, link, light LEDs,  * etc.  */
end_comment

begin_struct
struct|struct
name|lmc___media
block|{
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|defaults
function_decl|)
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_status
function_decl|)
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
parameter_list|,
name|lmc_ctl_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_clock_source
function_decl|)
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_speed
function_decl|)
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
parameter_list|,
name|lmc_ctl_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_cable_length
function_decl|)
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_scrambler
function_decl|)
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|get_link_status
function_decl|)
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_link_status
function_decl|)
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_crc_length
function_decl|)
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_circuit_type
function_decl|)
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
specifier|static
name|unsigned
name|lmc_mii_readreg
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
name|sc
parameter_list|,
name|unsigned
name|devaddr
parameter_list|,
name|unsigned
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|lmc_mii_writereg
parameter_list|(
name|lmc_softc_t
modifier|*
specifier|const
name|sc
parameter_list|,
name|unsigned
name|devaddr
parameter_list|,
name|unsigned
name|regno
parameter_list|,
name|unsigned
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

