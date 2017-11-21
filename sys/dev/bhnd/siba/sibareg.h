begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Landon Fuller<landon@landonf.org>  * Copyright (c) 2010 Broadcom Corporation  *   * This file was derived from the sbconfig.h header distributed with  * Broadcom's initial brcm80211 Linux driver release, as  * contributed to the Linux staging repository.   *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_SIBA_SIBAREG_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_SIBA_SIBAREG_
end_define

begin_include
include|#
directive|include
file|<dev/bhnd/bhndreg.h>
end_include

begin_comment
comment|/*  * Broadcom SIBA Configuration Space Registers.  *   * Backplane configuration registers common to siba(4) core register  * blocks.  */
end_comment

begin_comment
comment|/**  * Extract a config attribute by applying _MASK and _SHIFT defines.  *   * @param _reg The register value containing the desired attribute  * @param _attr The BCMA EROM attribute name (e.g. ENTRY_ISVALID), to be  * concatenated with the `SB` prefix and `_MASK`/`_SHIFT` suffixes.  */
end_comment

begin_define
define|#
directive|define
name|SIBA_REG_GET
parameter_list|(
name|_entry
parameter_list|,
name|_attr
parameter_list|)
define|\
value|((_entry& SIBA_ ## _attr ## _MASK)	\>> SIBA_ ## _attr ## _SHIFT)
end_define

begin_define
define|#
directive|define
name|SIBA_ENUM_ADDR
value|BHND_DEFAULT_CHIPC_ADDR
end_define

begin_comment
comment|/**< enumeration space */
end_comment

begin_define
define|#
directive|define
name|SIBA_ENUM_SIZE
value|0x00100000
end_define

begin_comment
comment|/**< size of the enumeration space */
end_comment

begin_define
define|#
directive|define
name|SIBA_CORE_SIZE
value|BHND_DEFAULT_CORE_SIZE
end_define

begin_comment
comment|/**< per-core register block size */
end_comment

begin_define
define|#
directive|define
name|SIBA_MAX_INTR
value|32
end_define

begin_comment
comment|/**< maximum number of backplane interrupt vectors */
end_comment

begin_define
define|#
directive|define
name|SIBA_MAX_CORES
define|\
value|(SIBA_ENUM_SIZE/SIBA_CORE_SIZE)
end_define

begin_comment
comment|/**< Maximum number of cores */
end_comment

begin_comment
comment|/** Evaluates to the bus address offset of the @p idx core register block */
end_comment

begin_define
define|#
directive|define
name|SIBA_CORE_OFFSET
parameter_list|(
name|idx
parameter_list|)
value|((idx) * SIBA_CORE_SIZE)
end_define

begin_comment
comment|/** Evaluates to the bus address of the @p idx core register block */
end_comment

begin_define
define|#
directive|define
name|SIBA_CORE_ADDR
parameter_list|(
name|idx
parameter_list|)
value|(SIBA_ENUM_ADDR + SIBA_CORE_OFFSET(idx))
end_define

begin_comment
comment|/*  * Sonics configuration registers are mapped to each core's enumeration  * space, at the end of the 4kb device register block, in reverse  * order:  *   * [0x0000-0x0dff]	core registers  * [0x0e00-0x0eff]	SIBA_R1 registers	(sonics>= 2.3)  * [0x0f00-0x0fff]	SIBA_R0 registers  */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_OFFSET
value|0xf00
end_define

begin_comment
comment|/**< first configuration block */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG1_OFFSET
value|0xe00
end_define

begin_comment
comment|/**< second configuration block (sonics>= 2.3) */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG_SIZE
value|0x100
end_define

begin_comment
comment|/**< cfg register block size */
end_comment

begin_comment
comment|/* Return the SIBA_CORE_ADDR-relative offset for the given siba configuration  * register block; configuration blocks are allocated starting at  * SIBA_CFG0_OFFSET, growing downwards. */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG_OFFSET
parameter_list|(
name|_n
parameter_list|)
value|(SIBA_CFG0_OFFSET - ((_n) * SIBA_CFG_SIZE))
end_define

begin_comment
comment|/* Return the SIBA_CORE_ADDR-relative offset for a SIBA_CFG* register. */
end_comment

begin_define
define|#
directive|define
name|SB0_REG_ABS
parameter_list|(
name|off
parameter_list|)
value|((off) + SIBA_CFG0_OFFSET)
end_define

begin_define
define|#
directive|define
name|SB1_REG_ABS
parameter_list|(
name|off
parameter_list|)
value|((off) + SIBA_CFG1_OFFSET)
end_define

begin_comment
comment|/* SIBA_CFG0 registers */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_IPSFLAG
value|0x08
end_define

begin_comment
comment|/**< initiator port ocp slave flag */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_TPSFLAG
value|0x18
end_define

begin_comment
comment|/**< target port ocp slave flag */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_TMERRLOGA
value|0x48
end_define

begin_comment
comment|/**< sonics>= 2.3 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_TMERRLOG
value|0x50
end_define

begin_comment
comment|/**< sonics>= 2.3 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_ADMATCH3
value|0x60
end_define

begin_comment
comment|/**< address match3 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_ADMATCH2
value|0x68
end_define

begin_comment
comment|/**< address match2 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_ADMATCH1
value|0x70
end_define

begin_comment
comment|/**< address match1 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_IMSTATE
value|0x90
end_define

begin_comment
comment|/**< initiator agent state */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_INTVEC
value|0x94
end_define

begin_comment
comment|/**< interrupt mask */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_TMSTATELOW
value|0x98
end_define

begin_comment
comment|/**< target state */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_TMSTATEHIGH
value|0x9c
end_define

begin_comment
comment|/**< target state */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_BWA0
value|0xa0
end_define

begin_comment
comment|/**< bandwidth allocation table0 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_IMCONFIGLOW
value|0xa8
end_define

begin_comment
comment|/**< initiator configuration */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_IMCONFIGHIGH
value|0xac
end_define

begin_comment
comment|/**< initiator configuration */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_ADMATCH0
value|0xb0
end_define

begin_comment
comment|/**< address match0 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_TMCONFIGLOW
value|0xb8
end_define

begin_comment
comment|/**< target configuration */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_TMCONFIGHIGH
value|0xbc
end_define

begin_comment
comment|/**< target configuration */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_BCONFIG
value|0xc0
end_define

begin_comment
comment|/**< broadcast configuration */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_BSTATE
value|0xc8
end_define

begin_comment
comment|/**< broadcast state */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_ACTCNFG
value|0xd8
end_define

begin_comment
comment|/**< activate configuration */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_FLAGST
value|0xe8
end_define

begin_comment
comment|/**< current sbflags */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_IDLOW
value|0xf8
end_define

begin_comment
comment|/**< identification */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG0_IDHIGH
value|0xfc
end_define

begin_comment
comment|/**< identification */
end_comment

begin_comment
comment|/* SIBA_CFG1 registers (sonics>= 2.3) */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG1_IMERRLOGA
value|0xa8
end_define

begin_comment
comment|/**< (sonics>= 2.3) */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG1_IMERRLOG
value|0xb0
end_define

begin_comment
comment|/**< sbtmerrlog (sonics>= 2.3) */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG1_TMPORTCONNID0
value|0xd8
end_define

begin_comment
comment|/**< sonics>= 2.3 */
end_comment

begin_define
define|#
directive|define
name|SIBA_CFG1_TMPORTLOCK0
value|0xf8
end_define

begin_comment
comment|/**< sonics>= 2.3 */
end_comment

begin_comment
comment|/* sbipsflag */
end_comment

begin_define
define|#
directive|define
name|SIBA_IPS_INT1_MASK
value|0x3f
end_define

begin_comment
comment|/* which sbflags get routed to mips interrupt 1 */
end_comment

begin_define
define|#
directive|define
name|SIBA_IPS_INT1_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SIBA_IPS_INT2_MASK
value|0x3f00
end_define

begin_comment
comment|/* which sbflags get routed to mips interrupt 2 */
end_comment

begin_define
define|#
directive|define
name|SIBA_IPS_INT2_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SIBA_IPS_INT3_MASK
value|0x3f0000
end_define

begin_comment
comment|/* which sbflags get routed to mips interrupt 3 */
end_comment

begin_define
define|#
directive|define
name|SIBA_IPS_INT3_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SIBA_IPS_INT4_MASK
value|0x3f000000
end_define

begin_comment
comment|/* which sbflags get routed to mips interrupt 4 */
end_comment

begin_define
define|#
directive|define
name|SIBA_IPS_INT4_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SIBA_IPS_INT_SHIFT
parameter_list|(
name|_i
parameter_list|)
value|((_i - 1) * 8)
end_define

begin_define
define|#
directive|define
name|SIBA_IPS_INT_MASK
parameter_list|(
name|_i
parameter_list|)
value|(SIBA_IPS_INT1_MASK<< SIBA_IPS_INT_SHIFT(_i))
end_define

begin_comment
comment|/* sbtpsflag */
end_comment

begin_define
define|#
directive|define
name|SIBA_TPS_NUM0_MASK
value|0x3f
end_define

begin_comment
comment|/* interrupt sbFlag # generated by this core */
end_comment

begin_define
define|#
directive|define
name|SIBA_TPS_NUM0_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SIBA_TPS_F0EN0
value|0x40
end_define

begin_comment
comment|/* interrupt is always sent on the backplane */
end_comment

begin_comment
comment|/* sbtmerrlog */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMEL_CM
value|0x00000007
end_define

begin_comment
comment|/* command */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMEL_CI
value|0x0000ff00
end_define

begin_comment
comment|/* connection id */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMEL_EC
value|0x0f000000
end_define

begin_comment
comment|/* error code */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMEL_ME
value|0x80000000
end_define

begin_comment
comment|/* multiple error */
end_comment

begin_comment
comment|/* sbimstate */
end_comment

begin_define
define|#
directive|define
name|SIBA_IM_PC
value|0xf
end_define

begin_comment
comment|/* pipecount */
end_comment

begin_define
define|#
directive|define
name|SIBA_IM_AP_MASK
value|0x30
end_define

begin_comment
comment|/* arbitration policy */
end_comment

begin_define
define|#
directive|define
name|SIBA_IM_AP_BOTH
value|0x00
end_define

begin_comment
comment|/* use both timeslaces and token */
end_comment

begin_define
define|#
directive|define
name|SIBA_IM_AP_TS
value|0x10
end_define

begin_comment
comment|/* use timesliaces only */
end_comment

begin_define
define|#
directive|define
name|SIBA_IM_AP_TK
value|0x20
end_define

begin_comment
comment|/* use token only */
end_comment

begin_define
define|#
directive|define
name|SIBA_IM_AP_RSV
value|0x30
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|SIBA_IM_IBE
value|0x20000
end_define

begin_comment
comment|/* inbanderror */
end_comment

begin_define
define|#
directive|define
name|SIBA_IM_TO
value|0x40000
end_define

begin_comment
comment|/* timeout */
end_comment

begin_define
define|#
directive|define
name|SIBA_IM_BY
value|0x01800000
end_define

begin_comment
comment|/* busy (sonics>= 2.3) */
end_comment

begin_define
define|#
directive|define
name|SIBA_IM_RJ
value|0x02000000
end_define

begin_comment
comment|/* reject (sonics>= 2.3) */
end_comment

begin_comment
comment|/* sbtmstatelow */
end_comment

begin_define
define|#
directive|define
name|SIBA_TML_RESET
value|0x0001
end_define

begin_comment
comment|/* reset */
end_comment

begin_define
define|#
directive|define
name|SIBA_TML_REJ_MASK
value|0x0006
end_define

begin_comment
comment|/* reject field */
end_comment

begin_define
define|#
directive|define
name|SIBA_TML_REJ
value|0x0002
end_define

begin_comment
comment|/* reject */
end_comment

begin_define
define|#
directive|define
name|SIBA_TML_TMPREJ
value|0x0004
end_define

begin_comment
comment|/* temporary reject, for error recovery */
end_comment

begin_define
define|#
directive|define
name|SIBA_TML_SICF_MASK
value|0xFFFF0000
end_define

begin_comment
comment|/* core IOCTL flags */
end_comment

begin_define
define|#
directive|define
name|SIBA_TML_SICF_SHIFT
value|16
end_define

begin_comment
comment|/* sbtmstatehigh */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMH_SERR
value|0x0001
end_define

begin_comment
comment|/* serror */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMH_INT
value|0x0002
end_define

begin_comment
comment|/* interrupt */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMH_BUSY
value|0x0004
end_define

begin_comment
comment|/* busy */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMH_TO
value|0x0020
end_define

begin_comment
comment|/* timeout (sonics>= 2.3) */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMH_SISF_MASK
value|0xFFFF0000
end_define

begin_comment
comment|/* core IOST flags */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMH_SISF_SHIFT
value|16
end_define

begin_comment
comment|/* sbbwa0 */
end_comment

begin_define
define|#
directive|define
name|SIBA_BWA_TAB0_MASK
value|0xffff
end_define

begin_comment
comment|/* lookup table 0 */
end_comment

begin_define
define|#
directive|define
name|SIBA_BWA_TAB1_MASK
value|0xffff
end_define

begin_comment
comment|/* lookup table 1 */
end_comment

begin_define
define|#
directive|define
name|SIBA_BWA_TAB1_SHIFT
value|16
end_define

begin_comment
comment|/* sbimconfiglow */
end_comment

begin_define
define|#
directive|define
name|SIBA_IMCL_STO_MASK
value|0x7
end_define

begin_comment
comment|/* service timeout */
end_comment

begin_define
define|#
directive|define
name|SIBA_IMCL_RTO_MASK
value|0x70
end_define

begin_comment
comment|/* request timeout */
end_comment

begin_define
define|#
directive|define
name|SIBA_IMCL_RTO_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SIBA_IMCL_CID_MASK
value|0xff0000
end_define

begin_comment
comment|/* connection id */
end_comment

begin_define
define|#
directive|define
name|SIBA_IMCL_CID_SHIFT
value|16
end_define

begin_comment
comment|/* sbimconfighigh */
end_comment

begin_define
define|#
directive|define
name|SIBA_IMCH_IEM_MASK
value|0xc
end_define

begin_comment
comment|/* inband error mode */
end_comment

begin_define
define|#
directive|define
name|SIBA_IMCH_TEM_MASK
value|0x30
end_define

begin_comment
comment|/* timeout error mode */
end_comment

begin_define
define|#
directive|define
name|SIBA_IMCH_TEM_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SIBA_IMCH_BEM_MASK
value|0xc0
end_define

begin_comment
comment|/* bus error mode */
end_comment

begin_define
define|#
directive|define
name|SIBA_IMCH_BEM_SHIFT
value|6
end_define

begin_comment
comment|/* sbadmatch0-4 */
end_comment

begin_define
define|#
directive|define
name|SIBA_AM_TYPE_MASK
value|0x3
end_define

begin_comment
comment|/* address type */
end_comment

begin_define
define|#
directive|define
name|SIBA_AM_TYPE_SHIFT
value|0x0
end_define

begin_define
define|#
directive|define
name|SIBA_AM_AD64
value|0x4
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|SIBA_AM_ADINT0_MASK
value|0xf8
end_define

begin_comment
comment|/* type0 size */
end_comment

begin_define
define|#
directive|define
name|SIBA_AM_ADINT0_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|SIBA_AM_ADINT1_MASK
value|0x1f8
end_define

begin_comment
comment|/* type1 size */
end_comment

begin_define
define|#
directive|define
name|SIBA_AM_ADINT1_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|SIBA_AM_ADINT2_MASK
value|0x1f8
end_define

begin_comment
comment|/* type2 size */
end_comment

begin_define
define|#
directive|define
name|SIBA_AM_ADINT2_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|SIBA_AM_ADEN
value|0x400
end_define

begin_comment
comment|/* enable */
end_comment

begin_define
define|#
directive|define
name|SIBA_AM_ADNEG
value|0x800
end_define

begin_comment
comment|/* negative decode */
end_comment

begin_define
define|#
directive|define
name|SIBA_AM_BASE0_MASK
value|0xffffff00
end_define

begin_comment
comment|/* type0 base address */
end_comment

begin_define
define|#
directive|define
name|SIBA_AM_BASE0_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SIBA_AM_BASE1_MASK
value|0xfffff000
end_define

begin_comment
comment|/* type1 base address for the core */
end_comment

begin_define
define|#
directive|define
name|SIBA_AM_BASE1_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|SIBA_AM_BASE2_MASK
value|0xffff0000
end_define

begin_comment
comment|/* type2 base address for the core */
end_comment

begin_define
define|#
directive|define
name|SIBA_AM_BASE2_SHIFT
value|16
end_define

begin_comment
comment|/* sbtmconfiglow */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMCL_CD_MASK
value|0xff
end_define

begin_comment
comment|/* clock divide */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMCL_CO_MASK
value|0xf800
end_define

begin_comment
comment|/* clock offset */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMCL_CO_SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|SIBA_TMCL_IF_MASK
value|0xfc0000
end_define

begin_comment
comment|/* interrupt flags */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMCL_IF_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|SIBA_TMCL_IM_MASK
value|0x3000000
end_define

begin_comment
comment|/* interrupt mode */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMCL_IM_SHIFT
value|24
end_define

begin_comment
comment|/* sbtmconfighigh */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMCH_BM_MASK
value|0x3
end_define

begin_comment
comment|/* busy mode */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMCH_RM_MASK
value|0x3
end_define

begin_comment
comment|/* retry mode */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMCH_RM_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|SIBA_TMCH_SM_MASK
value|0x30
end_define

begin_comment
comment|/* stop mode */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMCH_SM_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SIBA_TMCH_EM_MASK
value|0x300
end_define

begin_comment
comment|/* sb error mode */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMCH_EM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SIBA_TMCH_IM_MASK
value|0xc00
end_define

begin_comment
comment|/* int mode */
end_comment

begin_define
define|#
directive|define
name|SIBA_TMCH_IM_SHIFT
value|10
end_define

begin_comment
comment|/* sbbconfig */
end_comment

begin_define
define|#
directive|define
name|SIBA_BC_LAT_MASK
value|0x3
end_define

begin_comment
comment|/* sb latency */
end_comment

begin_define
define|#
directive|define
name|SIBA_BC_MAX0_MASK
value|0xf0000
end_define

begin_comment
comment|/* maxccntr0 */
end_comment

begin_define
define|#
directive|define
name|SIBA_BC_MAX0_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SIBA_BC_MAX1_MASK
value|0xf00000
end_define

begin_comment
comment|/* maxccntr1 */
end_comment

begin_define
define|#
directive|define
name|SIBA_BC_MAX1_SHIFT
value|20
end_define

begin_comment
comment|/* sbbstate */
end_comment

begin_define
define|#
directive|define
name|SIBA_BS_SRD
value|0x1
end_define

begin_comment
comment|/* st reg disable */
end_comment

begin_define
define|#
directive|define
name|SIBA_BS_HRD
value|0x2
end_define

begin_comment
comment|/* hold reg disable */
end_comment

begin_comment
comment|/* sbidlow */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_CS_MASK
value|0x3
end_define

begin_comment
comment|/* config space */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_CS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SIBA_IDL_NRADDR_MASK
value|0x38
end_define

begin_comment
comment|/* # address ranges supported */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_NRADDR_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|SIBA_IDL_SYNCH
value|0x40
end_define

begin_comment
comment|/* sync */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_INIT
value|0x80
end_define

begin_comment
comment|/* initiator */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_MINLAT_MASK
value|0xf00
end_define

begin_comment
comment|/* minimum backplane latency */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_MINLAT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SIBA_IDL_MAXLAT_MASK
value|0xf000
end_define

begin_comment
comment|/* maximum backplane latency */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_MAXLAT_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|SIBA_IDL_FIRST_MASK
value|0x10000
end_define

begin_comment
comment|/* this initiator is first */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_FIRST_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SIBA_IDL_CW_MASK
value|0xc0000
end_define

begin_comment
comment|/* cycle counter width */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_CW_SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|SIBA_IDL_TP_MASK
value|0xf00000
end_define

begin_comment
comment|/* target ports */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_TP_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|SIBA_IDL_IP_MASK
value|0xf000000
end_define

begin_comment
comment|/* initiator ports */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_IP_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SIBA_IDL_SBREV_MASK
value|0xf0000000
end_define

begin_comment
comment|/* sonics backplane revision code */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_SBREV_SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|SIBA_IDL_SBREV_2_2
value|0x0
end_define

begin_comment
comment|/* version 2.2 or earlier */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDL_SBREV_2_3
value|0x1
end_define

begin_comment
comment|/* version 2.3 */
end_comment

begin_comment
comment|/* sbidhigh */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDH_RC_MASK
value|0x000f
end_define

begin_comment
comment|/* revision code */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDH_RCE_MASK
value|0x7000
end_define

begin_comment
comment|/* revision code extension field */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDH_RCE_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SIBA_IDH_DEVICE_MASK
value|0x8ff0
end_define

begin_comment
comment|/* core code */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDH_DEVICE_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|SIBA_IDH_VENDOR_MASK
value|0xffff0000
end_define

begin_comment
comment|/* vendor code */
end_comment

begin_define
define|#
directive|define
name|SIBA_IDH_VENDOR_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SIBA_IDH_CORE_REV
parameter_list|(
name|sbidh
parameter_list|)
define|\
value|(SIBA_REG_GET((sbidh), IDH_RCE) | ((sbidh)& SIBA_IDH_RC_MASK))
end_define

begin_define
define|#
directive|define
name|SIBA_COMMIT
value|0xfd8
end_define

begin_comment
comment|/* update buffered registers value */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_SIBA_SIBAREG_ */
end_comment

end_unit

