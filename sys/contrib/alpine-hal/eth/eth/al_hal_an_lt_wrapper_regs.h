begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, 	  this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright 	  notice, this list of conditions and the following disclaimer in 	  the documentation and/or other materials provided with the 	  distribution.   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  *  @{  * @file   al_hal_an_lt_wrapper_regs.h  *  * @brief ... registers  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_AN_LT_wrapper_REGS_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_AN_LT_wrapper_REGS_H__
end_define

begin_include
include|#
directive|include
file|"al_hal_plat_types.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* * Unit Registers */
struct|struct
name|al_an_lt_wrapper_gen
block|{
comment|/* [0x0] AN LT wrapper Version */
name|uint32_t
name|version
decl_stmt|;
comment|/* [0x4] AN LT general configuration */
name|uint32_t
name|cfg
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|14
index|]
decl_stmt|;
block|}
struct|;
struct|struct
name|al_an_lt_wrapper_an_lt
block|{
comment|/* [0x0] AN LT register file address */
name|uint32_t
name|addr
decl_stmt|;
comment|/* [0x4] PCS register file data */
name|uint32_t
name|data
decl_stmt|;
comment|/* [0x8] AN LT control signals */
name|uint32_t
name|ctrl
decl_stmt|;
comment|/* [0xc] AN LT status signals */
name|uint32_t
name|status
decl_stmt|;
name|uint32_t
name|rsrvd
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
enum|enum
name|al_eth_an_lt_unit
block|{
name|AL_ETH_AN_LT_UNIT_32_BIT
init|=
literal|0
block|,
name|AL_ETH_AN_LT_UNIT_20_BIT
init|=
literal|1
block|,
name|AL_ETH_AN_LT_UNIT_16_BIT
init|=
literal|2
block|, }
enum|;
struct|struct
name|al_an_lt_wrapper_regs
block|{
name|uint32_t
name|rsrvd_0
index|[
literal|64
index|]
decl_stmt|;
name|struct
name|al_an_lt_wrapper_gen
name|gen
decl_stmt|;
comment|/* [0x100] */
name|struct
name|al_an_lt_wrapper_an_lt
name|an_lt
index|[
literal|3
index|]
decl_stmt|;
comment|/* [0x140] */
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** version register ****/
comment|/*  Revision number (Minor) */
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_RELEASE_NUM_MINOR_MASK
value|0x000000FF
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_RELEASE_NUM_MINOR_SHIFT
value|0
comment|/*  Revision number (Major) */
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_RELEASE_NUM_MAJOR_MASK
value|0x0000FF00
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_RELEASE_NUM_MAJOR_SHIFT
value|8
comment|/*  Date of release */
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_DATE_DAY_MASK
value|0x001F0000
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_DATE_DAY_SHIFT
value|16
comment|/*  Month of release */
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_DATA_MONTH_MASK
value|0x01E00000
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_DATA_MONTH_SHIFT
value|21
comment|/*  Year of release (starting from 2000) */
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_DATE_YEAR_MASK
value|0x3E000000
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_DATE_YEAR_SHIFT
value|25
comment|/*  Reserved */
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_RESERVED_MASK
value|0xC0000000
define|#
directive|define
name|AN_LT_WRAPPER_GEN_VERSION_RESERVED_SHIFT
value|30
comment|/**** cfg register ****/
comment|/*  * selection between different bus widths:  * 0 â 16  * 1 â 20  * 2 â 32  * 3 â N/A  */
define|#
directive|define
name|AN_LT_WRAPPER_GEN_CFG_AN_LT_SEL_RX_MASK
value|0x00000003
define|#
directive|define
name|AN_LT_WRAPPER_GEN_CFG_AN_LT_SEL_RX_SHIFT
value|0
comment|/*  * selection between different bus widths:  * 0 â 16  * 1 â 20  * 2 â 32  * 3 â N/A  */
define|#
directive|define
name|AN_LT_WRAPPER_GEN_CFG_AN_LT_SEL_TX_MASK
value|0x0000000C
define|#
directive|define
name|AN_LT_WRAPPER_GEN_CFG_AN_LT_SEL_TX_SHIFT
value|2
comment|/* bypass the AN/LT block */
define|#
directive|define
name|AN_LT_WRAPPER_GEN_CFG_BYPASS_RX
value|(1<< 4)
comment|/* bypass the AN/LT block */
define|#
directive|define
name|AN_LT_WRAPPER_GEN_CFG_BYPASS_TX
value|(1<< 5)
comment|/**** addr register ****/
comment|/* Address value */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_ADDR_VAL_MASK
value|0x000007FF
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_ADDR_VAL_SHIFT
value|0
comment|/**** data register ****/
comment|/* Data value */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_DATA_VAL_MASK
value|0x0000FFFF
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_DATA_VAL_SHIFT
value|0
comment|/**** ctrl register ****/
comment|/*  * Default Auto-Negotiation Enable. If â1â, the auto-negotiation process will  * start after reset de-assertion. The application can also start the  * auto-negotiation process by writing the KXAN_CONTROL.an_enable bit with â1â.  * Important: This signal is OR'ed with the KXAN_CONTROL.an_enable bit. Hence,  * when asserted (1) the application is unable to disable autonegotiation and  * writing the an_enable bit has no effect.  * Note: Even if enabled by this pin, the application must write the correct  * abilities in the KXAN_ABILITY_1/2/3 registers within 60ms from reset  * deassertion (break_link_timer).  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_AN_ENA
value|(1<< 0)
comment|/*  * If set to 1, the Arbitration State Machine reached the TRANSMIT_DISABLE  * state.  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_AN_DIS_TIMER
value|(1<< 1)
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_LINK_STATUS_KX
value|(1<< 4)
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_LINK_STATUS_KX4
value|(1<< 5)
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_LINK_STATUS
value|(1<< 6)
comment|/*  * PHY LOS indication selection  * 0 - Select input from the SerDes  * 1 - Select register value from phy_los_in_def  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_PHY_LOS_IN_SEL
value|(1<< 8)
comment|/* PHY LOS default value */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_PHY_LOS_IN_DEF
value|(1<< 9)
comment|/* PHY LOS polarity */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_PHY_LOS_IN_POL
value|(1<< 10)
comment|/*  * PHY LOS indication selection  * 0 â select AN output  * 1 - Select register value from phy_los_out_def  * 2 - Select input from the SerDes  * 3 â 0  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_PHY_LOS_OUT_SEL_MASK
value|0x00003000
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_PHY_LOS_OUT_SEL_SHIFT
value|12
comment|/* PHY LOS default value */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_PHY_LOS_OUT_DEF
value|(1<< 14)
comment|/* PHY LOS polarity */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_CTRL_PHY_LOS_OUT_POL
value|(1<< 15)
comment|/**** status register ****/
comment|/* Auto-Negotiation Done. If â1â, the auto-negotiation process has completed. */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_STATUS_AN_DONE
value|(1<< 0)
comment|/*  * If set to 1, auto-negotiation is enabled on the link. It represents the  * enable control bit KXAN_CONTROL.an_enable. When set to 1, the signals  * an_status/an_select are valid.  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_STATUS_AN_VAL
value|(1<< 1)
comment|/*  * If set to 0, auto-negotiation is in progress, if set to 1, the Arbitration  * State Machine reached the AN_GOOD_CHECK state (i.e. before autonegotiation is  * done, but the link no longer is used to transfer DME pages). Stays asserted  * also during AN_GOOD (autoneg done).  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_STATUS_AN_STATUS
value|(1<< 2)
comment|/*  * Selected Technology. Becomes valid when an_status is 1.  * The selection mode number (from 0 to 24) corresponds to the Technology  * Ability (A0-A24) from the ability pages (see 4.3.2.3 page 13). The mode  * selection is based on the matching technology abilities and priority.  * A value of 31 is an invalid setting that indicates that no common technology  * could be resolved. The application should then inspect the base page results  * to determine if the link is operable or not.  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_STATUS_AN_SELECT_MASK
value|0x000001F0
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_STATUS_AN_SELECT_SHIFT
value|4
comment|/*  * If set to 1, the Arbitration State Machine reached the TRANSMIT_DISABLE state  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_STATUS_AN_TR_DIS_STATUS
value|(1<< 16)
comment|/*  * FEC Enable. Asserts when autonegotiation base page exchange identified both  * link partners advertising FEC capability and at least one is requesting FEC.  * The signal stays constant following base page exchange until autonegotiation  * is disabled or restarted.  * Note: the information can also be extracted from the base page exchange or  * the BP_ETH_STATUS register.  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_STATUS_FEC_ENA
value|(1<< 17)
comment|/*  * Link Training Frame Lock. If set to 1 the training frame delineation has been  * acquired.  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_STATUS_LT_LOCK
value|(1<< 20)
comment|/*  * If set to 0, link-training is in progress, if set to 1, the training is  * completed and the PCS datapath has been enabled (phy_los_out no longer  * gated).  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_STATUS_LT_STATUS
value|(1<< 21)
comment|/*  * If set to 1, link-training is enabled on the link. It represents the enable  * control bit PMD Control.taining enable. When set to 1, the signal lt_status  * is valid  */
define|#
directive|define
name|AN_LT_WRAPPER_AN_LT_STATUS_LT_VAL
value|(1<< 22)
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_AN_LT_wrapper_REGS_H__ */
end_comment

begin_comment
comment|/** @} end of ... group */
end_comment

end_unit

