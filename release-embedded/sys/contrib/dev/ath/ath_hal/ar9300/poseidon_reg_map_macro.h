begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Qualcomm Atheros, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* File:       /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top/poseidon_reg_map_macro.h*/
end_comment

begin_comment
comment|/* Creator:    kcwo                                                          */
end_comment

begin_comment
comment|/* Time:       Tuesday Nov 2, 2010 [5:38:25 pm]                              */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Path:       /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top   */
end_comment

begin_comment
comment|/* Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -codegen   */
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/env/blueprint/ath_ansic.codegen*/
end_comment

begin_comment
comment|/*             -ath_ansic -Wdesc -I                                          */
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top -I*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint -I    */
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/env/blueprint -I*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig*/
end_comment

begin_comment
comment|/*             -odir                                                         */
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top   */
end_comment

begin_comment
comment|/*             -eval {$INCLUDE_SYSCONFIG_FILES=1} -eval                      */
end_comment

begin_comment
comment|/*             $WAR_EV58615_for_ansic_codegen=1 poseidon_reg.rdl             */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Sources:    /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/rtc/blueprint/rtc_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/mac_pcu_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/host_intf/rtl/blueprint/host_intf_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/merlin2_0_radio_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/rtc_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/mac/rtl/mac_dma/blueprint/mac_dma_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top/poseidon_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/efuse_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top/merlin2_0_radio_reg_map.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/mac/rtl/mac_dma/blueprint/mac_dcu_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/mac_dma_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/mac/rtl/mac_pcu/blueprint/mac_pcu_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/bb/blueprint/bb_reg_map.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/mac/rtl/mac_dma/blueprint/mac_qcu_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/apb_analog/analog_intf_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top/emulation_misc.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top/pcie_phy_reg_csr.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/analog_intf_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/svd_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top/poseidon_radio_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/host_intf/rtl/blueprint/efuse_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/amba_mac/svd/blueprint/svd_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/mac_qcu_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/radio_65_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/rtc_sync_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/amba_mac/blueprint/rtc_sync_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/pcie_phy_reg_csr_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/bb_reg_map_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/mac_dcu_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/env/blueprint/ath_ansic.pm*/
end_comment

begin_comment
comment|/*             /cad/local/lib/perl/Pinfo.pm                                  */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Blueprint:   3.7.3 (Fri Aug 29 12:39:16 PDT 2008)                         */
end_comment

begin_comment
comment|/* Machine:    zydasc19                                                      */
end_comment

begin_comment
comment|/* OS:         Linux 2.6.9-78.0.8.ELsmp                                      */
end_comment

begin_comment
comment|/* Description:                                                              */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*This Register Map contains the complete register set for Poseidon.         */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Copyright (C) 2010 Denali Software Inc.  All rights reserved              */
end_comment

begin_comment
comment|/* THIS FILE IS AUTOMATICALLY GENERATED BY DENALI BLUEPRINT, DO NOT EDIT     */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__REG_POSEIDON_REG_MAP_MACRO_H__
end_ifndef

begin_define
define|#
directive|define
name|__REG_POSEIDON_REG_MAP_MACRO_H__
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::AXI_INTERCONNECT_CTRL */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AXI_INTERCONNECT_CTRL_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__AXI_INTERCONNECT_CTRL_MACRO__
end_define

begin_comment
comment|/* macros for field FORCE_SEL_ON */
end_comment

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__FORCE_SEL_ON__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__FORCE_SEL_ON__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__FORCE_SEL_ON__MASK
value|0x00000001U
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__FORCE_SEL_ON__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x00000001U
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__FORCE_SEL_ON__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x00000001U)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__FORCE_SEL_ON__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | ((u_int32_t)(src)&\                     0x00000001U)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__FORCE_SEL_ON__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x00000001U)))
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__FORCE_SEL_ON__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | (u_int32_t)(1)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__FORCE_SEL_ON__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | (u_int32_t)(0)
end_define

begin_comment
comment|/* macros for field SELECT_SLV_PCIE */
end_comment

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SELECT_SLV_PCIE__SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SELECT_SLV_PCIE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SELECT_SLV_PCIE__MASK
value|0x00000002U
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SELECT_SLV_PCIE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000002U)>> 1)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SELECT_SLV_PCIE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 1)& 0x00000002U)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SELECT_SLV_PCIE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000002U) | (((u_int32_t)(src)<<\                     1)& 0x00000002U)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SELECT_SLV_PCIE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 1)& ~0x00000002U)))
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SELECT_SLV_PCIE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000002U) | ((u_int32_t)(1)<< 1)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SELECT_SLV_PCIE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000002U) | ((u_int32_t)(0)<< 1)
end_define

begin_comment
comment|/* macros for field SW_WOW_ENABLE */
end_comment

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SW_WOW_ENABLE__SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SW_WOW_ENABLE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SW_WOW_ENABLE__MASK
value|0x00000004U
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SW_WOW_ENABLE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000004U)>> 2)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SW_WOW_ENABLE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 2)& 0x00000004U)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SW_WOW_ENABLE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000004U) | (((u_int32_t)(src)<<\                     2)& 0x00000004U)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SW_WOW_ENABLE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 2)& ~0x00000004U)))
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SW_WOW_ENABLE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000004U) | ((u_int32_t)(1)<< 2)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__SW_WOW_ENABLE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000004U) | ((u_int32_t)(0)<< 2)
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__READ
value|0x00000007U
end_define

begin_define
define|#
directive|define
name|AXI_INTERCONNECT_CTRL__WRITE
value|0x00000007U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AXI_INTERCONNECT_CTRL_MACRO__ */
end_comment

begin_comment
comment|/* macros for host_intf_reg_block.AXI_INTERCONNECT_CTRL */
end_comment

begin_define
define|#
directive|define
name|INST_HOST_INTF_REG_BLOCK__AXI_INTERCONNECT_CTRL__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_control_1 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_CONTROL_1_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_CONTROL_1_MACRO__
end_define

begin_comment
comment|/* macros for field green_tx_enable */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_TX_ENABLE__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_TX_ENABLE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_TX_ENABLE__MASK
value|0x00000001U
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_TX_ENABLE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x00000001U
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_TX_ENABLE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x00000001U)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_TX_ENABLE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | ((u_int32_t)(src)&\                     0x00000001U)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_TX_ENABLE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x00000001U)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_TX_ENABLE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | (u_int32_t)(1)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_TX_ENABLE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | (u_int32_t)(0)
end_define

begin_comment
comment|/* macros for field green_cases */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_CASES__SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_CASES__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_CASES__MASK
value|0x00000002U
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_CASES__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000002U)>> 1)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_CASES__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 1)& 0x00000002U)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_CASES__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000002U) | (((u_int32_t)(src)<<\                     1)& 0x00000002U)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_CASES__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 1)& ~0x00000002U)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_CASES__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000002U) | ((u_int32_t)(1)<< 1)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__GREEN_CASES__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000002U) | ((u_int32_t)(0)<< 1)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__READ
value|0x00000003U
end_define

begin_define
define|#
directive|define
name|GREEN_TX_CONTROL_1__WRITE
value|0x00000003U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_CONTROL_1_MACRO__ */
end_comment

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::bb_reg_page_control */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BB_REG_PAGE_CONTROL_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__BB_REG_PAGE_CONTROL_MACRO__
end_define

begin_comment
comment|/* macros for field disable_bb_reg_page */
end_comment

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__MASK
value|0x00000001U
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x00000001U
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x00000001U)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | ((u_int32_t)(src)&\                     0x00000001U)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x00000001U)))
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | (u_int32_t)(1)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | (u_int32_t)(0)
end_define

begin_comment
comment|/* macros for field bb_register_page */
end_comment

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__MASK
value|0x0000000eU
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x0000000eU)>> 1)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 1)& 0x0000000eU)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000000eU) | (((u_int32_t)(src)<<\                     1)& 0x0000000eU)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 1)& ~0x0000000eU)))
end_define

begin_comment
comment|/* macros for field direct_access_page */
end_comment

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__MASK
value|0x00000010U
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000010U)>> 4)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 4)& 0x00000010U)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000010U) | (((u_int32_t)(src)<<\                     4)& 0x00000010U)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 4)& ~0x00000010U)))
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000010U) | ((u_int32_t)(1)<< 4)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000010U) | ((u_int32_t)(0)<< 4)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__READ
value|0x0000001fU
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__WRITE
value|0x0000001fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BB_REG_PAGE_CONTROL_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_bbb_reg_map.BB_bb_reg_page_control */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_BBB_REG_MAP__BB_BB_REG_PAGE_CONTROL__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::peak_det_ctrl_1 */
end_comment

begin_comment
comment|/* macros for field peak_det_tally_thr_low_0 */
end_comment

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_LOW_0__SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_LOW_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_LOW_0__MASK
value|0x00001f00U
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_LOW_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00001f00U)>> 8)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_LOW_0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 8)& 0x00001f00U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_LOW_0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00001f00U) | (((u_int32_t)(src)<<\                     8)& 0x00001f00U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_LOW_0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 8)& ~0x00001f00U)))
end_define

begin_comment
comment|/* macros for field peak_det_tally_thr_med_0 */
end_comment

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_MED_0__SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_MED_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_MED_0__MASK
value|0x0003e000U
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_MED_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x0003e000U)>> 13)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_MED_0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 13)& 0x0003e000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_MED_0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003e000U) | (((u_int32_t)(src)<<\                     13)& 0x0003e000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_MED_0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 13)& ~0x0003e000U)))
end_define

begin_comment
comment|/* macros for field peak_det_tally_thr_high_0 */
end_comment

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_HIGH_0__SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_HIGH_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_HIGH_0__MASK
value|0x007c0000U
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_HIGH_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x007c0000U)>> 18)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_HIGH_0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 18)& 0x007c0000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_HIGH_0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x007c0000U) | (((u_int32_t)(src)<<\                     18)& 0x007c0000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_1__PEAK_DET_TALLY_THR_HIGH_0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 18)& ~0x007c0000U)))
end_define

begin_comment
comment|/* macros for bb_reg_block.bb_agc_reg_map.BB_peak_det_ctrl_1 */
end_comment

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::peak_det_ctrl_2 */
end_comment

begin_comment
comment|/* macros for field rf_gain_drop_db_low_0 */
end_comment

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_LOW_0__SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_LOW_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_LOW_0__MASK
value|0x00007c00U
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_LOW_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00007c00U)>> 10)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_LOW_0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 10)& 0x00007c00U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_LOW_0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00007c00U) | (((u_int32_t)(src)<<\                     10)& 0x00007c00U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_LOW_0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 10)& ~0x00007c00U)))
end_define

begin_comment
comment|/* macros for field rf_gain_drop_db_med_0 */
end_comment

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_MED_0__SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_MED_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_MED_0__MASK
value|0x000f8000U
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_MED_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x000f8000U)>> 15)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_MED_0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 15)& 0x000f8000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_MED_0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x000f8000U) | (((u_int32_t)(src)<<\                     15)& 0x000f8000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_MED_0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 15)& ~0x000f8000U)))
end_define

begin_comment
comment|/* macros for field rf_gain_drop_db_high_0 */
end_comment

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_HIGH_0__SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_HIGH_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_HIGH_0__MASK
value|0x01f00000U
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_HIGH_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x01f00000U)>> 20)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_HIGH_0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 20)& 0x01f00000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_HIGH_0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x01f00000U) | (((u_int32_t)(src)<<\                     20)& 0x01f00000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_HIGH_0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 20)& ~0x01f00000U)))
end_define

begin_comment
comment|/* macros for field rf_gain_drop_db_non_0 */
end_comment

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_NON_0__SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_NON_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_NON_0__MASK
value|0x3e000000U
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_NON_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x3e000000U)>> 25)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_NON_0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 25)& 0x3e000000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_NON_0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x3e000000U) | (((u_int32_t)(src)<<\                     25)& 0x3e000000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__RF_GAIN_DROP_DB_NON_0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 25)& ~0x3e000000U)))
end_define

begin_comment
comment|/* macros for field enable_rfsat_restart */
end_comment

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__ENABLE_RFSAT_RESTART__SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__ENABLE_RFSAT_RESTART__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__ENABLE_RFSAT_RESTART__MASK
value|0x40000000U
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__ENABLE_RFSAT_RESTART__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x40000000U)>> 30)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__ENABLE_RFSAT_RESTART__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 30)& 0x40000000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__ENABLE_RFSAT_RESTART__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x40000000U) | (((u_int32_t)(src)<<\                     30)& 0x40000000U)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__ENABLE_RFSAT_RESTART__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 30)& ~0x40000000U)))
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__ENABLE_RFSAT_RESTART__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x40000000U) | ((u_int32_t)(1)<< 30)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__ENABLE_RFSAT_RESTART__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x40000000U) | ((u_int32_t)(0)<< 30)
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__READ
value|0x7fffffffU
end_define

begin_define
define|#
directive|define
name|PEAK_DET_CTRL_2__WRITE
value|0x7fffffffU
end_define

begin_comment
comment|/* macros for bb_reg_block.bb_agc_reg_map.BB_peak_det_ctrl_2 */
end_comment

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::bt_coex_1 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BT_COEX_1_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__BT_COEX_1_MACRO__
end_define

begin_comment
comment|/* macros for field peak_det_tally_thr_low_1 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_LOW_1__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_LOW_1__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_LOW_1__MASK
value|0x0000001fU
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_LOW_1__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000001fU
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_LOW_1__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000001fU)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_LOW_1__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000001fU) | ((u_int32_t)(src)&\                     0x0000001fU)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_LOW_1__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000001fU)))
end_define

begin_comment
comment|/* macros for field peak_det_tally_thr_med_1 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_MED_1__SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_MED_1__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_MED_1__MASK
value|0x000003e0U
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_MED_1__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x000003e0U)>> 5)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_MED_1__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 5)& 0x000003e0U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_MED_1__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x000003e0U) | (((u_int32_t)(src)<<\                     5)& 0x000003e0U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_MED_1__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 5)& ~0x000003e0U)))
end_define

begin_comment
comment|/* macros for field peak_det_tally_thr_high_1 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_HIGH_1__SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_HIGH_1__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_HIGH_1__MASK
value|0x00007c00U
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_HIGH_1__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00007c00U)>> 10)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_HIGH_1__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 10)& 0x00007c00U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_HIGH_1__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00007c00U) | (((u_int32_t)(src)<<\                     10)& 0x00007c00U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__PEAK_DET_TALLY_THR_HIGH_1__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 10)& ~0x00007c00U)))
end_define

begin_comment
comment|/* macros for field rf_gain_drop_db_low_1 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_LOW_1__SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_LOW_1__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_LOW_1__MASK
value|0x000f8000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_LOW_1__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x000f8000U)>> 15)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_LOW_1__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 15)& 0x000f8000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_LOW_1__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x000f8000U) | (((u_int32_t)(src)<<\                     15)& 0x000f8000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_LOW_1__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 15)& ~0x000f8000U)))
end_define

begin_comment
comment|/* macros for field rf_gain_drop_db_med_1 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_MED_1__SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_MED_1__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_MED_1__MASK
value|0x01f00000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_MED_1__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x01f00000U)>> 20)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_MED_1__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 20)& 0x01f00000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_MED_1__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x01f00000U) | (((u_int32_t)(src)<<\                     20)& 0x01f00000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_MED_1__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 20)& ~0x01f00000U)))
end_define

begin_comment
comment|/* macros for field rf_gain_drop_db_high_1 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_HIGH_1__SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_HIGH_1__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_HIGH_1__MASK
value|0x3e000000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_HIGH_1__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x3e000000U)>> 25)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_HIGH_1__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 25)& 0x3e000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_HIGH_1__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x3e000000U) | (((u_int32_t)(src)<<\                     25)& 0x3e000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__RF_GAIN_DROP_DB_HIGH_1__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 25)& ~0x3e000000U)))
end_define

begin_comment
comment|/* macros for field bt_tx_disable_NF_cal */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_1__BT_TX_DISABLE_NF_CAL__SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__BT_TX_DISABLE_NF_CAL__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__BT_TX_DISABLE_NF_CAL__MASK
value|0x40000000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__BT_TX_DISABLE_NF_CAL__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x40000000U)>> 30)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__BT_TX_DISABLE_NF_CAL__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 30)& 0x40000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__BT_TX_DISABLE_NF_CAL__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x40000000U) | (((u_int32_t)(src)<<\                     30)& 0x40000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__BT_TX_DISABLE_NF_CAL__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 30)& ~0x40000000U)))
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__BT_TX_DISABLE_NF_CAL__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x40000000U) | ((u_int32_t)(1)<< 30)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__BT_TX_DISABLE_NF_CAL__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x40000000U) | ((u_int32_t)(0)<< 30)
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__READ
value|0x7fffffffU
end_define

begin_define
define|#
directive|define
name|BT_COEX_1__WRITE
value|0x7fffffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BT_COEX_1_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_agc_reg_map.BB_bt_coex_1 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_AGC_REG_MAP__BB_BT_COEX_1__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::bt_coex_2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BT_COEX_2_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__BT_COEX_2_MACRO__
end_define

begin_comment
comment|/* macros for field peak_det_tally_thr_low_2 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_LOW_2__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_LOW_2__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_LOW_2__MASK
value|0x0000001fU
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_LOW_2__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000001fU
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_LOW_2__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000001fU)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_LOW_2__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000001fU) | ((u_int32_t)(src)&\                     0x0000001fU)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_LOW_2__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000001fU)))
end_define

begin_comment
comment|/* macros for field peak_det_tally_thr_med_2 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_MED_2__SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_MED_2__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_MED_2__MASK
value|0x000003e0U
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_MED_2__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x000003e0U)>> 5)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_MED_2__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 5)& 0x000003e0U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_MED_2__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x000003e0U) | (((u_int32_t)(src)<<\                     5)& 0x000003e0U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_MED_2__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 5)& ~0x000003e0U)))
end_define

begin_comment
comment|/* macros for field peak_det_tally_thr_high_2 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_HIGH_2__SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_HIGH_2__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_HIGH_2__MASK
value|0x00007c00U
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_HIGH_2__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00007c00U)>> 10)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_HIGH_2__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 10)& 0x00007c00U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_HIGH_2__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00007c00U) | (((u_int32_t)(src)<<\                     10)& 0x00007c00U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__PEAK_DET_TALLY_THR_HIGH_2__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 10)& ~0x00007c00U)))
end_define

begin_comment
comment|/* macros for field rf_gain_drop_db_low_2 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_LOW_2__SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_LOW_2__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_LOW_2__MASK
value|0x000f8000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_LOW_2__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x000f8000U)>> 15)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_LOW_2__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 15)& 0x000f8000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_LOW_2__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x000f8000U) | (((u_int32_t)(src)<<\                     15)& 0x000f8000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_LOW_2__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 15)& ~0x000f8000U)))
end_define

begin_comment
comment|/* macros for field rf_gain_drop_db_med_2 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_MED_2__SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_MED_2__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_MED_2__MASK
value|0x01f00000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_MED_2__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x01f00000U)>> 20)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_MED_2__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 20)& 0x01f00000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_MED_2__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x01f00000U) | (((u_int32_t)(src)<<\                     20)& 0x01f00000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_MED_2__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 20)& ~0x01f00000U)))
end_define

begin_comment
comment|/* macros for field rf_gain_drop_db_high_2 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_HIGH_2__SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_HIGH_2__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_HIGH_2__MASK
value|0x3e000000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_HIGH_2__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x3e000000U)>> 25)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_HIGH_2__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 25)& 0x3e000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_HIGH_2__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x3e000000U) | (((u_int32_t)(src)<<\                     25)& 0x3e000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RF_GAIN_DROP_DB_HIGH_2__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 25)& ~0x3e000000U)))
end_define

begin_comment
comment|/* macros for field rfsat_rx_rx */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_2__RFSAT_RX_RX__SHIFT
value|30
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RFSAT_RX_RX__WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RFSAT_RX_RX__MASK
value|0xc0000000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RFSAT_RX_RX__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0xc0000000U)>> 30)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RFSAT_RX_RX__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 30)& 0xc0000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RFSAT_RX_RX__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0xc0000000U) | (((u_int32_t)(src)<<\                     30)& 0xc0000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__RFSAT_RX_RX__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 30)& ~0xc0000000U)))
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__READ
value|0xffffffffU
end_define

begin_define
define|#
directive|define
name|BT_COEX_2__WRITE
value|0xffffffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BT_COEX_2_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_agc_reg_map.BB_bt_coex_2 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_AGC_REG_MAP__BB_BT_COEX_2__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::bt_coex_3 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BT_COEX_3_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__BT_COEX_3_MACRO__
end_define

begin_comment
comment|/* macros for field rfsat_bt_srch_srch */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_SRCH__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_SRCH__WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_SRCH__MASK
value|0x00000003U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_SRCH__READ
parameter_list|(
name|src
parameter_list|)
value|(u_int32_t)(src)& 0x00000003U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_SRCH__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x00000003U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_SRCH__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000003U) | ((u_int32_t)(src)&\                     0x00000003U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_SRCH__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x00000003U)))
end_define

begin_comment
comment|/* macros for field rfsat_bt_rx_srch */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_RX_SRCH__SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_RX_SRCH__WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_RX_SRCH__MASK
value|0x0000000cU
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_RX_SRCH__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x0000000cU)>> 2)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_RX_SRCH__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 2)& 0x0000000cU)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_RX_SRCH__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000000cU) | (((u_int32_t)(src)<<\                     2)& 0x0000000cU)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_RX_SRCH__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 2)& ~0x0000000cU)))
end_define

begin_comment
comment|/* macros for field rfsat_bt_srch_rx */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_RX__SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_RX__WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_RX__MASK
value|0x00000030U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_RX__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000030U)>> 4)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_RX__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 4)& 0x00000030U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_RX__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000030U) | (((u_int32_t)(src)<<\                     4)& 0x00000030U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_BT_SRCH_RX__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 4)& ~0x00000030U)))
end_define

begin_comment
comment|/* macros for field rfsat_wlan_srch_srch */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_SRCH__SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_SRCH__WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_SRCH__MASK
value|0x000000c0U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_SRCH__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x000000c0U)>> 6)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_SRCH__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 6)& 0x000000c0U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_SRCH__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x000000c0U) | (((u_int32_t)(src)<<\                     6)& 0x000000c0U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_SRCH__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 6)& ~0x000000c0U)))
end_define

begin_comment
comment|/* macros for field rfsat_wlan_rx_srch */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_RX_SRCH__SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_RX_SRCH__WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_RX_SRCH__MASK
value|0x00000300U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_RX_SRCH__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000300U)>> 8)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_RX_SRCH__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 8)& 0x00000300U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_RX_SRCH__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000300U) | (((u_int32_t)(src)<<\                     8)& 0x00000300U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_RX_SRCH__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 8)& ~0x00000300U)))
end_define

begin_comment
comment|/* macros for field rfsat_wlan_srch_rx */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_RX__SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_RX__WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_RX__MASK
value|0x00000c00U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_RX__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000c00U)>> 10)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_RX__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 10)& 0x00000c00U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_RX__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000c00U) | (((u_int32_t)(src)<<\                     10)& 0x00000c00U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_WLAN_SRCH_RX__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 10)& ~0x00000c00U)))
end_define

begin_comment
comment|/* macros for field rfsat_eq_srch_srch */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_SRCH__SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_SRCH__WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_SRCH__MASK
value|0x00003000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_SRCH__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00003000U)>> 12)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_SRCH__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 12)& 0x00003000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_SRCH__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00003000U) | (((u_int32_t)(src)<<\                     12)& 0x00003000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_SRCH__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 12)& ~0x00003000U)))
end_define

begin_comment
comment|/* macros for field rfsat_eq_rx_srch */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_RX_SRCH__SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_RX_SRCH__WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_RX_SRCH__MASK
value|0x0000c000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_RX_SRCH__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x0000c000U)>> 14)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_RX_SRCH__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 14)& 0x0000c000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_RX_SRCH__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000c000U) | (((u_int32_t)(src)<<\                     14)& 0x0000c000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_RX_SRCH__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 14)& ~0x0000c000U)))
end_define

begin_comment
comment|/* macros for field rfsat_eq_srch_rx */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_RX__SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_RX__WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_RX__MASK
value|0x00030000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_RX__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00030000U)>> 16)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_RX__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 16)& 0x00030000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_RX__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00030000U) | (((u_int32_t)(src)<<\                     16)& 0x00030000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RFSAT_EQ_SRCH_RX__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 16)& ~0x00030000U)))
end_define

begin_comment
comment|/* macros for field rf_gain_drop_db_non_1 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_1__SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_1__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_1__MASK
value|0x007c0000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_1__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x007c0000U)>> 18)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_1__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 18)& 0x007c0000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_1__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x007c0000U) | (((u_int32_t)(src)<<\                     18)& 0x007c0000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_1__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 18)& ~0x007c0000U)))
end_define

begin_comment
comment|/* macros for field rf_gain_drop_db_non_2 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_2__SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_2__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_2__MASK
value|0x0f800000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_2__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x0f800000U)>> 23)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_2__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 23)& 0x0f800000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_2__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0f800000U) | (((u_int32_t)(src)<<\                     23)& 0x0f800000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__RF_GAIN_DROP_DB_NON_2__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 23)& ~0x0f800000U)))
end_define

begin_comment
comment|/* macros for field bt_rx_firpwr_incr */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_3__BT_RX_FIRPWR_INCR__SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__BT_RX_FIRPWR_INCR__WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__BT_RX_FIRPWR_INCR__MASK
value|0xf0000000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__BT_RX_FIRPWR_INCR__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0xf0000000U)>> 28)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__BT_RX_FIRPWR_INCR__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 28)& 0xf0000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__BT_RX_FIRPWR_INCR__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0xf0000000U) | (((u_int32_t)(src)<<\                     28)& 0xf0000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__BT_RX_FIRPWR_INCR__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 28)& ~0xf0000000U)))
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__READ
value|0xffffffffU
end_define

begin_define
define|#
directive|define
name|BT_COEX_3__WRITE
value|0xffffffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BT_COEX_3_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_agc_reg_map.BB_bt_coex_3 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_AGC_REG_MAP__BB_BT_COEX_3__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::bt_coex_4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BT_COEX_4_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__BT_COEX_4_MACRO__
end_define

begin_comment
comment|/* macros for field rfgain_eqv_lna_0 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_0__WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_0__MASK
value|0x000000ffU
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_0__READ
parameter_list|(
name|src
parameter_list|)
value|(u_int32_t)(src)& 0x000000ffU
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x000000ffU)
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x000000ffU) | ((u_int32_t)(src)&\                     0x000000ffU)
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x000000ffU)))
end_define

begin_comment
comment|/* macros for field rfgain_eqv_lna_1 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_1__SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_1__WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_1__MASK
value|0x0000ff00U
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_1__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x0000ff00U)>> 8)
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_1__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 8)& 0x0000ff00U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_1__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000ff00U) | (((u_int32_t)(src)<<\                     8)& 0x0000ff00U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_1__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 8)& ~0x0000ff00U)))
end_define

begin_comment
comment|/* macros for field rfgain_eqv_lna_2 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_2__SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_2__WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_2__MASK
value|0x00ff0000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_2__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00ff0000U)>> 16)
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_2__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 16)& 0x00ff0000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_2__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00ff0000U) | (((u_int32_t)(src)<<\                     16)& 0x00ff0000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_2__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 16)& ~0x00ff0000U)))
end_define

begin_comment
comment|/* macros for field rfgain_eqv_lna_3 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_3__SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_3__WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_3__MASK
value|0xff000000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_3__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0xff000000U)>> 24)
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_3__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 24)& 0xff000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_3__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0xff000000U) | (((u_int32_t)(src)<<\                     24)& 0xff000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__RFGAIN_EQV_LNA_3__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 24)& ~0xff000000U)))
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__READ
value|0xffffffffU
end_define

begin_define
define|#
directive|define
name|BT_COEX_4__WRITE
value|0xffffffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BT_COEX_4_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_agc_reg_map.BB_bt_coex_4 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_AGC_REG_MAP__BB_BT_COEX_4__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::bt_coex_5 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BT_COEX_5_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__BT_COEX_5_MACRO__
end_define

begin_comment
comment|/* macros for field rfgain_eqv_lna_4 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_4__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_4__WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_4__MASK
value|0x000000ffU
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_4__READ
parameter_list|(
name|src
parameter_list|)
value|(u_int32_t)(src)& 0x000000ffU
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_4__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x000000ffU)
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_4__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x000000ffU) | ((u_int32_t)(src)&\                     0x000000ffU)
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_4__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x000000ffU)))
end_define

begin_comment
comment|/* macros for field rfgain_eqv_lna_5 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_5__SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_5__WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_5__MASK
value|0x0000ff00U
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_5__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x0000ff00U)>> 8)
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_5__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 8)& 0x0000ff00U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_5__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000ff00U) | (((u_int32_t)(src)<<\                     8)& 0x0000ff00U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_5__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 8)& ~0x0000ff00U)))
end_define

begin_comment
comment|/* macros for field rfgain_eqv_lna_6 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_6__SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_6__WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_6__MASK
value|0x00ff0000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_6__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00ff0000U)>> 16)
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_6__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 16)& 0x00ff0000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_6__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00ff0000U) | (((u_int32_t)(src)<<\                     16)& 0x00ff0000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_6__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 16)& ~0x00ff0000U)))
end_define

begin_comment
comment|/* macros for field rfgain_eqv_lna_7 */
end_comment

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_7__SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_7__WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_7__MASK
value|0xff000000U
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_7__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0xff000000U)>> 24)
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_7__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 24)& 0xff000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_7__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0xff000000U) | (((u_int32_t)(src)<<\                     24)& 0xff000000U)
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__RFGAIN_EQV_LNA_7__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 24)& ~0xff000000U)))
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__READ
value|0xffffffffU
end_define

begin_define
define|#
directive|define
name|BT_COEX_5__WRITE
value|0xffffffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BT_COEX_5_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_agc_reg_map.BB_bt_coex_5 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_AGC_REG_MAP__BB_BT_COEX_5__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::dc_cal_status_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DC_CAL_STATUS_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__DC_CAL_STATUS_B0_MACRO__
end_define

begin_comment
comment|/* macros for field offsetC1I_0 */
end_comment

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC1I_0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC1I_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC1I_0__MASK
value|0x0000001fU
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC1I_0__READ
parameter_list|(
name|src
parameter_list|)
value|(u_int32_t)(src)& 0x0000001fU
end_define

begin_comment
comment|/* macros for field offsetC1Q_0 */
end_comment

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC1Q_0__SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC1Q_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC1Q_0__MASK
value|0x000003e0U
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC1Q_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x000003e0U)>> 5)
end_define

begin_comment
comment|/* macros for field offsetC2I_0 */
end_comment

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC2I_0__SHIFT
value|10
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC2I_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC2I_0__MASK
value|0x00007c00U
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC2I_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00007c00U)>> 10)
end_define

begin_comment
comment|/* macros for field offsetC2Q_0 */
end_comment

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC2Q_0__SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC2Q_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC2Q_0__MASK
value|0x000f8000U
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC2Q_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x000f8000U)>> 15)
end_define

begin_comment
comment|/* macros for field offsetC3I_0 */
end_comment

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC3I_0__SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC3I_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC3I_0__MASK
value|0x01f00000U
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC3I_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x01f00000U)>> 20)
end_define

begin_comment
comment|/* macros for field offsetC3Q_0 */
end_comment

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC3Q_0__SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC3Q_0__WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC3Q_0__MASK
value|0x3e000000U
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__OFFSETC3Q_0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x3e000000U)>> 25)
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|DC_CAL_STATUS_B0__READ
value|0x3fffffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DC_CAL_STATUS_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_agc_reg_map.BB_dc_cal_status_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_AGC_REG_MAP__BB_DC_CAL_STATUS_B0__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::bbb_sig_detect */
end_comment

begin_comment
comment|/* macros for field bbb_mrc_off_no_swap */
end_comment

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__BBB_MRC_OFF_NO_SWAP__SHIFT
value|23
end_define

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__BBB_MRC_OFF_NO_SWAP__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__BBB_MRC_OFF_NO_SWAP__MASK
value|0x00800000U
end_define

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__BBB_MRC_OFF_NO_SWAP__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00800000U)>> 23)
end_define

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__BBB_MRC_OFF_NO_SWAP__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 23)& 0x00800000U)
end_define

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__BBB_MRC_OFF_NO_SWAP__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00800000U) | (((u_int32_t)(src)<<\                     23)& 0x00800000U)
end_define

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__BBB_MRC_OFF_NO_SWAP__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 23)& ~0x00800000U)))
end_define

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__BBB_MRC_OFF_NO_SWAP__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00800000U) | ((u_int32_t)(1)<< 23)
end_define

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__BBB_MRC_OFF_NO_SWAP__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00800000U) | ((u_int32_t)(0)<< 23)
end_define

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__READ
value|0x80ffffffU
end_define

begin_define
define|#
directive|define
name|BBB_SIG_DETECT__WRITE
value|0x80ffffffU
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::gen_controls */
end_comment

begin_comment
comment|/* macros for field enable_dac_async_fifo */
end_comment

begin_define
define|#
directive|define
name|GEN_CONTROLS__ENABLE_DAC_ASYNC_FIFO__SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__ENABLE_DAC_ASYNC_FIFO__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__ENABLE_DAC_ASYNC_FIFO__MASK
value|0x00000800U
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__ENABLE_DAC_ASYNC_FIFO__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000800U)>> 11)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__ENABLE_DAC_ASYNC_FIFO__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 11)& 0x00000800U)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__ENABLE_DAC_ASYNC_FIFO__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000800U) | (((u_int32_t)(src)<<\                     11)& 0x00000800U)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__ENABLE_DAC_ASYNC_FIFO__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 11)& ~0x00000800U)))
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__ENABLE_DAC_ASYNC_FIFO__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000800U) | ((u_int32_t)(1)<< 11)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__ENABLE_DAC_ASYNC_FIFO__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000800U) | ((u_int32_t)(0)<< 11)
end_define

begin_comment
comment|/* macros for field static20_mode_ht40_packet_handling */
end_comment

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_HANDLING__SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_HANDLING__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_HANDLING__MASK
value|0x00008000U
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_HANDLING__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00008000U)>> 15)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_HANDLING__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 15)& 0x00008000U)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_HANDLING__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00008000U) | (((u_int32_t)(src)<<\                     15)& 0x00008000U)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_HANDLING__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 15)& ~0x00008000U)))
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_HANDLING__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00008000U) | ((u_int32_t)(1)<< 15)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_HANDLING__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00008000U) | ((u_int32_t)(0)<< 15)
end_define

begin_comment
comment|/* macros for field static20_mode_ht40_packet_error_rpt */
end_comment

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_ERROR_RPT__SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_ERROR_RPT__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_ERROR_RPT__MASK
value|0x00010000U
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_ERROR_RPT__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00010000U)>> 16)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_ERROR_RPT__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 16)& 0x00010000U)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_ERROR_RPT__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00010000U) | (((u_int32_t)(src)<<\                     16)& 0x00010000U)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_ERROR_RPT__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 16)& ~0x00010000U)))
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_ERROR_RPT__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00010000U) | ((u_int32_t)(1)<< 16)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__STATIC20_MODE_HT40_PACKET_ERROR_RPT__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00010000U) | ((u_int32_t)(0)<< 16)
end_define

begin_comment
comment|/* macros for field unsupp_ht_rate_threshold */
end_comment

begin_define
define|#
directive|define
name|GEN_CONTROLS__UNSUPP_HT_RATE_THRESHOLD__SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__UNSUPP_HT_RATE_THRESHOLD__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__UNSUPP_HT_RATE_THRESHOLD__MASK
value|0x01fc0000U
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__UNSUPP_HT_RATE_THRESHOLD__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x01fc0000U)>> 18)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__UNSUPP_HT_RATE_THRESHOLD__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 18)& 0x01fc0000U)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__UNSUPP_HT_RATE_THRESHOLD__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x01fc0000U) | (((u_int32_t)(src)<<\                     18)& 0x01fc0000U)
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__UNSUPP_HT_RATE_THRESHOLD__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 18)& ~0x01fc0000U)))
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__READ
value|0x01fdffffU
end_define

begin_define
define|#
directive|define
name|GEN_CONTROLS__WRITE
value|0x01fdffffU
end_define

begin_comment
comment|/* macros for bb_reg_block.bb_sm_reg_map.BB_gen_controls */
end_comment

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::bb_reg_page_control */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BB_REG_PAGE_CONTROL_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__BB_REG_PAGE_CONTROL_MACRO__
end_define

begin_comment
comment|/* macros for field disable_bb_reg_page */
end_comment

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__MASK
value|0x00000001U
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x00000001U
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x00000001U)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | ((u_int32_t)(src)&\                     0x00000001U)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x00000001U)))
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | (u_int32_t)(1)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DISABLE_BB_REG_PAGE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000001U) | (u_int32_t)(0)
end_define

begin_comment
comment|/* macros for field bb_register_page */
end_comment

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__MASK
value|0x0000000eU
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x0000000eU)>> 1)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 1)& 0x0000000eU)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000000eU) | (((u_int32_t)(src)<<\                     1)& 0x0000000eU)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__BB_REGISTER_PAGE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 1)& ~0x0000000eU)))
end_define

begin_comment
comment|/* macros for field direct_access_page */
end_comment

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__MASK
value|0x00000010U
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000010U)>> 4)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 4)& 0x00000010U)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000010U) | (((u_int32_t)(src)<<\                     4)& 0x00000010U)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 4)& ~0x00000010U)))
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000010U) | ((u_int32_t)(1)<< 4)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__DIRECT_ACCESS_PAGE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000010U) | ((u_int32_t)(0)<< 4)
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__READ
value|0x0000001fU
end_define

begin_define
define|#
directive|define
name|BB_REG_PAGE_CONTROL__WRITE
value|0x0000001fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __BB_REG_PAGE_CONTROL_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_bbb_reg_map.BB_bb_reg_page_control */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_BBB_REG_MAP__BB_BB_REG_PAGE_CONTROL__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::spectral_scan */
end_comment

begin_comment
comment|/* macros for field spectral_scan_compressed_rpt */
end_comment

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__SPECTRAL_SCAN_COMPRESSED_RPT__SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__SPECTRAL_SCAN_COMPRESSED_RPT__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__SPECTRAL_SCAN_COMPRESSED_RPT__MASK
value|0x80000000U
end_define

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__SPECTRAL_SCAN_COMPRESSED_RPT__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x80000000U)>> 31)
end_define

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__SPECTRAL_SCAN_COMPRESSED_RPT__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 31)& 0x80000000U)
end_define

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__SPECTRAL_SCAN_COMPRESSED_RPT__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | (((u_int32_t)(src)<<\                     31)& 0x80000000U)
end_define

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__SPECTRAL_SCAN_COMPRESSED_RPT__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 31)& ~0x80000000U)))
end_define

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__SPECTRAL_SCAN_COMPRESSED_RPT__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | ((u_int32_t)(1)<< 31)
end_define

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__SPECTRAL_SCAN_COMPRESSED_RPT__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | ((u_int32_t)(0)<< 31)
end_define

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__READ
value|0xffffffffU
end_define

begin_define
define|#
directive|define
name|SPECTRAL_SCAN__WRITE
value|0xffffffffU
end_define

begin_comment
comment|/* macros for bb_reg_block.bb_sm_reg_map.BB_spectral_scan */
end_comment

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::search_start_delay */
end_comment

begin_comment
comment|/* macros for field rx_sounding_enable */
end_comment

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RX_SOUNDING_ENABLE__SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RX_SOUNDING_ENABLE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RX_SOUNDING_ENABLE__MASK
value|0x00004000U
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RX_SOUNDING_ENABLE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00004000U)>> 14)
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RX_SOUNDING_ENABLE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 14)& 0x00004000U)
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RX_SOUNDING_ENABLE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00004000U) | (((u_int32_t)(src)<<\                     14)& 0x00004000U)
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RX_SOUNDING_ENABLE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 14)& ~0x00004000U)))
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RX_SOUNDING_ENABLE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00004000U) | ((u_int32_t)(1)<< 14)
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RX_SOUNDING_ENABLE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00004000U) | ((u_int32_t)(0)<< 14)
end_define

begin_comment
comment|/* macros for field rm_hcsd4svd */
end_comment

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RM_HCSD4SVD__SHIFT
value|15
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RM_HCSD4SVD__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RM_HCSD4SVD__MASK
value|0x00008000U
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RM_HCSD4SVD__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00008000U)>> 15)
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RM_HCSD4SVD__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 15)& 0x00008000U)
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RM_HCSD4SVD__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00008000U) | (((u_int32_t)(src)<<\                     15)& 0x00008000U)
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RM_HCSD4SVD__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 15)& ~0x00008000U)))
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RM_HCSD4SVD__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00008000U) | ((u_int32_t)(1)<< 15)
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__RM_HCSD4SVD__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00008000U) | ((u_int32_t)(0)<< 15)
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__READ
value|0x0000ffffU
end_define

begin_define
define|#
directive|define
name|SEARCH_START_DELAY__WRITE
value|0x0000ffffU
end_define

begin_comment
comment|/* macros for bb_reg_block.bb_sm_reg_map.BB_search_start_delay */
end_comment

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::frame_control */
end_comment

begin_comment
comment|/* macros for field en_err_static20_mode_ht40_packet */
end_comment

begin_define
define|#
directive|define
name|FRAME_CONTROL__EN_ERR_STATIC20_MODE_HT40_PACKET__SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|FRAME_CONTROL__EN_ERR_STATIC20_MODE_HT40_PACKET__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|FRAME_CONTROL__EN_ERR_STATIC20_MODE_HT40_PACKET__MASK
value|0x00080000U
end_define

begin_define
define|#
directive|define
name|FRAME_CONTROL__EN_ERR_STATIC20_MODE_HT40_PACKET__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00080000U)>> 19)
end_define

begin_define
define|#
directive|define
name|FRAME_CONTROL__EN_ERR_STATIC20_MODE_HT40_PACKET__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 19)& 0x00080000U)
end_define

begin_define
define|#
directive|define
name|FRAME_CONTROL__EN_ERR_STATIC20_MODE_HT40_PACKET__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00080000U) | (((u_int32_t)(src)<<\                     19)& 0x00080000U)
end_define

begin_define
define|#
directive|define
name|FRAME_CONTROL__EN_ERR_STATIC20_MODE_HT40_PACKET__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 19)& ~0x00080000U)))
end_define

begin_define
define|#
directive|define
name|FRAME_CONTROL__EN_ERR_STATIC20_MODE_HT40_PACKET__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00080000U) | ((u_int32_t)(1)<< 19)
end_define

begin_define
define|#
directive|define
name|FRAME_CONTROL__EN_ERR_STATIC20_MODE_HT40_PACKET__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00080000U) | ((u_int32_t)(0)<< 19)
end_define

begin_comment
comment|/* macros for bb_reg_block.bb_sm_reg_map.BB_frame_control */
end_comment

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::switch_table_com1 */
end_comment

begin_comment
comment|/* macros for field switch_table_com_spdt */
end_comment

begin_define
define|#
directive|define
name|SWITCH_TABLE_COM1__SWITCH_TABLE_COM_SPDT__SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|SWITCH_TABLE_COM1__SWITCH_TABLE_COM_SPDT__WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|SWITCH_TABLE_COM1__SWITCH_TABLE_COM_SPDT__MASK
value|0x00f00000U
end_define

begin_define
define|#
directive|define
name|SWITCH_TABLE_COM1__SWITCH_TABLE_COM_SPDT__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00f00000U)>> 20)
end_define

begin_define
define|#
directive|define
name|SWITCH_TABLE_COM1__SWITCH_TABLE_COM_SPDT__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 20)& 0x00f00000U)
end_define

begin_define
define|#
directive|define
name|SWITCH_TABLE_COM1__SWITCH_TABLE_COM_SPDT__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00f00000U) | (((u_int32_t)(src)<<\                     20)& 0x00f00000U)
end_define

begin_define
define|#
directive|define
name|SWITCH_TABLE_COM1__SWITCH_TABLE_COM_SPDT__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 20)& ~0x00f00000U)))
end_define

begin_define
define|#
directive|define
name|SWITCH_TABLE_COM1__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|SWITCH_TABLE_COM1__READ
value|0x00ffffffU
end_define

begin_define
define|#
directive|define
name|SWITCH_TABLE_COM1__WRITE
value|0x00ffffffU
end_define

begin_comment
comment|/* macros for bb_reg_block.bb_sm_reg_map.BB_switch_table_com1 */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_reg_map.BB_powertx_rate12 */
end_comment

begin_comment
comment|/* macros for field use_per_packet_olpc_gain_delta_adj */
end_comment

begin_define
define|#
directive|define
name|POWERTX_MAX__USE_PER_PACKET_OLPC_GAIN_DELTA_ADJ__SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|POWERTX_MAX__USE_PER_PACKET_OLPC_GAIN_DELTA_ADJ__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|POWERTX_MAX__USE_PER_PACKET_OLPC_GAIN_DELTA_ADJ__MASK
value|0x00000080U
end_define

begin_define
define|#
directive|define
name|POWERTX_MAX__USE_PER_PACKET_OLPC_GAIN_DELTA_ADJ__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000080U)>> 7)
end_define

begin_define
define|#
directive|define
name|POWERTX_MAX__USE_PER_PACKET_OLPC_GAIN_DELTA_ADJ__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 7)& 0x00000080U)
end_define

begin_define
define|#
directive|define
name|POWERTX_MAX__USE_PER_PACKET_OLPC_GAIN_DELTA_ADJ__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000080U) | (((u_int32_t)(src)<<\                     7)& 0x00000080U)
end_define

begin_define
define|#
directive|define
name|POWERTX_MAX__USE_PER_PACKET_OLPC_GAIN_DELTA_ADJ__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 7)& ~0x00000080U)))
end_define

begin_define
define|#
directive|define
name|POWERTX_MAX__USE_PER_PACKET_OLPC_GAIN_DELTA_ADJ__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000080U) | ((u_int32_t)(1)<< 7)
end_define

begin_define
define|#
directive|define
name|POWERTX_MAX__USE_PER_PACKET_OLPC_GAIN_DELTA_ADJ__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000080U) | ((u_int32_t)(0)<< 7)
end_define

begin_define
define|#
directive|define
name|POWERTX_MAX__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|POWERTX_MAX__READ
value|0x000000c0U
end_define

begin_define
define|#
directive|define
name|POWERTX_MAX__WRITE
value|0x000000c0U
end_define

begin_comment
comment|/* macros for bb_reg_block.bb_sm_reg_map.BB_powertx_max */
end_comment

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::tx_forced_gain */
end_comment

begin_comment
comment|/* macros for field forced_ob2G */
end_comment

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_OB2G__SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_OB2G__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_OB2G__MASK
value|0x0e000000U
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_OB2G__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x0e000000U)>> 25)
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_OB2G__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 25)& 0x0e000000U)
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_OB2G__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0e000000U) | (((u_int32_t)(src)<<\                     25)& 0x0e000000U)
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_OB2G__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 25)& ~0x0e000000U)))
end_define

begin_comment
comment|/* macros for field forced_db2G */
end_comment

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_DB2G__SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_DB2G__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_DB2G__MASK
value|0x70000000U
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_DB2G__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x70000000U)>> 28)
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_DB2G__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 28)& 0x70000000U)
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_DB2G__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x70000000U) | (((u_int32_t)(src)<<\                     28)& 0x70000000U)
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_DB2G__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 28)& ~0x70000000U)))
end_define

begin_comment
comment|/* macros for field forced_green_paprd_enable */
end_comment

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_GREEN_PAPRD_ENABLE__SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_GREEN_PAPRD_ENABLE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_GREEN_PAPRD_ENABLE__MASK
value|0x80000000U
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_GREEN_PAPRD_ENABLE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x80000000U)>> 31)
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_GREEN_PAPRD_ENABLE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 31)& 0x80000000U)
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_GREEN_PAPRD_ENABLE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | (((u_int32_t)(src)<<\                     31)& 0x80000000U)
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_GREEN_PAPRD_ENABLE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 31)& ~0x80000000U)))
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_GREEN_PAPRD_ENABLE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | ((u_int32_t)(1)<< 31)
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__FORCED_GREEN_PAPRD_ENABLE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | ((u_int32_t)(0)<< 31)
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__READ
value|0xffffffffU
end_define

begin_define
define|#
directive|define
name|TX_FORCED_GAIN__WRITE
value|0xffffffffU
end_define

begin_comment
comment|/* macros for bb_reg_block.bb_sm_reg_map.BB_tx_forced_gain */
end_comment

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::txiqcal_control_0 */
end_comment

begin_comment
comment|/* macros for field enable_txiq_calibrate */
end_comment

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__MASK
value|0x80000000U
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x80000000U)>> 31)
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 31)& 0x80000000U)
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | (((u_int32_t)(src)<<\                     31)& 0x80000000U)
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 31)& ~0x80000000U)))
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | ((u_int32_t)(1)<< 31)
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | ((u_int32_t)(0)<< 31)
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__READ
value|0xffffffffU
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__WRITE
value|0xffffffffU
end_define

begin_comment
comment|/* macros for bb_reg_block.bb_sm_reg_map.BB_txiqcal_control_0 */
end_comment

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::txiqcal_control_0 */
end_comment

begin_comment
comment|/* macros for field enable_txiq_calibrate */
end_comment

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__SHIFT
value|31
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__MASK
value|0x80000000U
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x80000000U)>> 31)
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 31)& 0x80000000U)
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | (((u_int32_t)(src)<<\                     31)& 0x80000000U)
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 31)& ~0x80000000U)))
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | ((u_int32_t)(1)<< 31)
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__ENABLE_TXIQ_CALIBRATE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x80000000U) | ((u_int32_t)(0)<< 31)
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__READ
value|0xffffffffU
end_define

begin_define
define|#
directive|define
name|TXIQCAL_CONTROL_0__WRITE
value|0xffffffffU
end_define

begin_comment
comment|/* macros for bb_reg_block.bb_sm_reg_map.BB_txiqcal_control_0 */
end_comment

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_0_1_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_0_1_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_0_1_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_0_1_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_1_B0__PAPRD_PRE_POST_SCALING_0_1_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_1_B0__PAPRD_PRE_POST_SCALING_0_1_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_1_B0__PAPRD_PRE_POST_SCALING_0_1_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_1_B0__PAPRD_PRE_POST_SCALING_0_1_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_1_B0__PAPRD_PRE_POST_SCALING_0_1_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_1_B0__PAPRD_PRE_POST_SCALING_0_1_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_1_B0__PAPRD_PRE_POST_SCALING_0_1_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_1_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_1_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_1_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_0_1_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_0_1_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_0_1_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_1_1_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_1_1_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_1_1_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_1_1_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_1_B0__PAPRD_PRE_POST_SCALING_1_1_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_1_B0__PAPRD_PRE_POST_SCALING_1_1_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_1_B0__PAPRD_PRE_POST_SCALING_1_1_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_1_B0__PAPRD_PRE_POST_SCALING_1_1_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_1_B0__PAPRD_PRE_POST_SCALING_1_1_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_1_B0__PAPRD_PRE_POST_SCALING_1_1_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_1_B0__PAPRD_PRE_POST_SCALING_1_1_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_1_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_1_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_1_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_1_1_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_1_1_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_1_1_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_2_1_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_2_1_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_2_1_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_2_1_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_1_B0__PAPRD_PRE_POST_SCALING_2_1_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_1_B0__PAPRD_PRE_POST_SCALING_2_1_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_1_B0__PAPRD_PRE_POST_SCALING_2_1_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_1_B0__PAPRD_PRE_POST_SCALING_2_1_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_1_B0__PAPRD_PRE_POST_SCALING_2_1_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_1_B0__PAPRD_PRE_POST_SCALING_2_1_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_1_B0__PAPRD_PRE_POST_SCALING_2_1_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_1_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_1_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_1_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_2_1_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_2_1_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_2_1_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_3_1_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_3_1_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_3_1_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_3_1_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_1_B0__PAPRD_PRE_POST_SCALING_3_1_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_1_B0__PAPRD_PRE_POST_SCALING_3_1_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_1_B0__PAPRD_PRE_POST_SCALING_3_1_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_1_B0__PAPRD_PRE_POST_SCALING_3_1_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_1_B0__PAPRD_PRE_POST_SCALING_3_1_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_1_B0__PAPRD_PRE_POST_SCALING_3_1_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_1_B0__PAPRD_PRE_POST_SCALING_3_1_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_1_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_1_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_1_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_3_1_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_3_1_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_3_1_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_4_1_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_4_1_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_4_1_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_4_1_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_1_B0__PAPRD_PRE_POST_SCALING_4_1_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_1_B0__PAPRD_PRE_POST_SCALING_4_1_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_1_B0__PAPRD_PRE_POST_SCALING_4_1_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_1_B0__PAPRD_PRE_POST_SCALING_4_1_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_1_B0__PAPRD_PRE_POST_SCALING_4_1_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_1_B0__PAPRD_PRE_POST_SCALING_4_1_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_1_B0__PAPRD_PRE_POST_SCALING_4_1_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_1_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_1_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_1_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_4_1_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_4_1_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_4_1_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_5_1_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_5_1_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_5_1_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_5_1_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_1_B0__PAPRD_PRE_POST_SCALING_5_1_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_1_B0__PAPRD_PRE_POST_SCALING_5_1_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_1_B0__PAPRD_PRE_POST_SCALING_5_1_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_1_B0__PAPRD_PRE_POST_SCALING_5_1_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_1_B0__PAPRD_PRE_POST_SCALING_5_1_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_1_B0__PAPRD_PRE_POST_SCALING_5_1_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_1_B0__PAPRD_PRE_POST_SCALING_5_1_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_1_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_1_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_1_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_5_1_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_5_1_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_5_1_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_6_1_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_6_1_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_6_1_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_6_1_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_1_B0__PAPRD_PRE_POST_SCALING_6_1_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_1_B0__PAPRD_PRE_POST_SCALING_6_1_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_1_B0__PAPRD_PRE_POST_SCALING_6_1_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_1_B0__PAPRD_PRE_POST_SCALING_6_1_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_1_B0__PAPRD_PRE_POST_SCALING_6_1_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_1_B0__PAPRD_PRE_POST_SCALING_6_1_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_1_B0__PAPRD_PRE_POST_SCALING_6_1_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_1_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_1_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_1_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_6_1_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_6_1_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_6_1_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_7_1_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_7_1_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_7_1_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_7_1_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_1_B0__PAPRD_PRE_POST_SCALING_7_1_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_1_B0__PAPRD_PRE_POST_SCALING_7_1_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_1_B0__PAPRD_PRE_POST_SCALING_7_1_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_1_B0__PAPRD_PRE_POST_SCALING_7_1_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_1_B0__PAPRD_PRE_POST_SCALING_7_1_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_1_B0__PAPRD_PRE_POST_SCALING_7_1_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_1_B0__PAPRD_PRE_POST_SCALING_7_1_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_1_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_1_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_1_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_7_1_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_7_1_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_7_1_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_0_2_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_0_2_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_0_2_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_0_2_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_2_B0__PAPRD_PRE_POST_SCALING_0_2_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_2_B0__PAPRD_PRE_POST_SCALING_0_2_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_2_B0__PAPRD_PRE_POST_SCALING_0_2_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_2_B0__PAPRD_PRE_POST_SCALING_0_2_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_2_B0__PAPRD_PRE_POST_SCALING_0_2_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_2_B0__PAPRD_PRE_POST_SCALING_0_2_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_2_B0__PAPRD_PRE_POST_SCALING_0_2_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_2_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_2_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_2_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_0_2_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_0_2_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_0_2_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_1_2_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_1_2_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_1_2_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_1_2_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_2_B0__PAPRD_PRE_POST_SCALING_1_2_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_2_B0__PAPRD_PRE_POST_SCALING_1_2_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_2_B0__PAPRD_PRE_POST_SCALING_1_2_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_2_B0__PAPRD_PRE_POST_SCALING_1_2_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_2_B0__PAPRD_PRE_POST_SCALING_1_2_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_2_B0__PAPRD_PRE_POST_SCALING_1_2_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_2_B0__PAPRD_PRE_POST_SCALING_1_2_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_2_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_2_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_2_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_1_2_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_1_2_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_1_2_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_2_2_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_2_2_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_2_2_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_2_2_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_2_B0__PAPRD_PRE_POST_SCALING_2_2_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_2_B0__PAPRD_PRE_POST_SCALING_2_2_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_2_B0__PAPRD_PRE_POST_SCALING_2_2_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_2_B0__PAPRD_PRE_POST_SCALING_2_2_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_2_B0__PAPRD_PRE_POST_SCALING_2_2_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_2_B0__PAPRD_PRE_POST_SCALING_2_2_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_2_B0__PAPRD_PRE_POST_SCALING_2_2_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_2_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_2_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_2_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_2_2_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_2_2_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_2_2_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_3_2_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_3_2_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_3_2_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_3_2_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_2_B0__PAPRD_PRE_POST_SCALING_3_2_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_2_B0__PAPRD_PRE_POST_SCALING_3_2_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_2_B0__PAPRD_PRE_POST_SCALING_3_2_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_2_B0__PAPRD_PRE_POST_SCALING_3_2_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_2_B0__PAPRD_PRE_POST_SCALING_3_2_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_2_B0__PAPRD_PRE_POST_SCALING_3_2_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_2_B0__PAPRD_PRE_POST_SCALING_3_2_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_2_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_2_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_2_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_3_2_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_3_2_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_3_2_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_4_2_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_4_2_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_4_2_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_4_2_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_2_B0__PAPRD_PRE_POST_SCALING_4_2_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_2_B0__PAPRD_PRE_POST_SCALING_4_2_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_2_B0__PAPRD_PRE_POST_SCALING_4_2_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_2_B0__PAPRD_PRE_POST_SCALING_4_2_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_2_B0__PAPRD_PRE_POST_SCALING_4_2_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_2_B0__PAPRD_PRE_POST_SCALING_4_2_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_2_B0__PAPRD_PRE_POST_SCALING_4_2_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_2_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_2_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_2_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_4_2_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_4_2_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_4_2_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_5_2_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_5_2_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_5_2_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_5_2_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_2_B0__PAPRD_PRE_POST_SCALING_5_2_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_2_B0__PAPRD_PRE_POST_SCALING_5_2_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_2_B0__PAPRD_PRE_POST_SCALING_5_2_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_2_B0__PAPRD_PRE_POST_SCALING_5_2_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_2_B0__PAPRD_PRE_POST_SCALING_5_2_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_2_B0__PAPRD_PRE_POST_SCALING_5_2_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_2_B0__PAPRD_PRE_POST_SCALING_5_2_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_2_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_2_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_2_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_5_2_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_5_2_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_5_2_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_6_2_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_6_2_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_6_2_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_6_2_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_2_B0__PAPRD_PRE_POST_SCALING_6_2_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_2_B0__PAPRD_PRE_POST_SCALING_6_2_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_2_B0__PAPRD_PRE_POST_SCALING_6_2_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_2_B0__PAPRD_PRE_POST_SCALING_6_2_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_2_B0__PAPRD_PRE_POST_SCALING_6_2_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_2_B0__PAPRD_PRE_POST_SCALING_6_2_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_2_B0__PAPRD_PRE_POST_SCALING_6_2_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_2_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_2_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_2_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_6_2_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_6_2_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_6_2_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_7_2_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_7_2_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_7_2_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_7_2_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_2_B0__PAPRD_PRE_POST_SCALING_7_2_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_2_B0__PAPRD_PRE_POST_SCALING_7_2_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_2_B0__PAPRD_PRE_POST_SCALING_7_2_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_2_B0__PAPRD_PRE_POST_SCALING_7_2_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_2_B0__PAPRD_PRE_POST_SCALING_7_2_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_2_B0__PAPRD_PRE_POST_SCALING_7_2_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_2_B0__PAPRD_PRE_POST_SCALING_7_2_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_2_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_2_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_2_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_7_2_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_7_2_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_7_2_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_0_3_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_0_3_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_0_3_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_0_3_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_3_B0__PAPRD_PRE_POST_SCALING_0_3_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_3_B0__PAPRD_PRE_POST_SCALING_0_3_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_3_B0__PAPRD_PRE_POST_SCALING_0_3_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_3_B0__PAPRD_PRE_POST_SCALING_0_3_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_3_B0__PAPRD_PRE_POST_SCALING_0_3_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_3_B0__PAPRD_PRE_POST_SCALING_0_3_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_3_B0__PAPRD_PRE_POST_SCALING_0_3_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_3_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_3_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_3_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_0_3_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_0_3_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_0_3_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_1_3_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_1_3_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_1_3_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_1_3_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_3_B0__PAPRD_PRE_POST_SCALING_1_3_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_3_B0__PAPRD_PRE_POST_SCALING_1_3_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_3_B0__PAPRD_PRE_POST_SCALING_1_3_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_3_B0__PAPRD_PRE_POST_SCALING_1_3_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_3_B0__PAPRD_PRE_POST_SCALING_1_3_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_3_B0__PAPRD_PRE_POST_SCALING_1_3_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_3_B0__PAPRD_PRE_POST_SCALING_1_3_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_3_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_3_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_3_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_1_3_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_1_3_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_1_3_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_2_3_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_2_3_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_2_3_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_2_3_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_3_B0__PAPRD_PRE_POST_SCALING_2_3_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_3_B0__PAPRD_PRE_POST_SCALING_2_3_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_3_B0__PAPRD_PRE_POST_SCALING_2_3_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_3_B0__PAPRD_PRE_POST_SCALING_2_3_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_3_B0__PAPRD_PRE_POST_SCALING_2_3_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_3_B0__PAPRD_PRE_POST_SCALING_2_3_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_3_B0__PAPRD_PRE_POST_SCALING_2_3_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_3_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_3_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_3_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_2_3_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_2_3_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_2_3_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_3_3_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_3_3_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_3_3_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_3_3_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_3_B0__PAPRD_PRE_POST_SCALING_3_3_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_3_B0__PAPRD_PRE_POST_SCALING_3_3_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_3_B0__PAPRD_PRE_POST_SCALING_3_3_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_3_B0__PAPRD_PRE_POST_SCALING_3_3_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_3_B0__PAPRD_PRE_POST_SCALING_3_3_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_3_B0__PAPRD_PRE_POST_SCALING_3_3_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_3_B0__PAPRD_PRE_POST_SCALING_3_3_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_3_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_3_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_3_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_3_3_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_3_3_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_3_3_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_4_3_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_4_3_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_4_3_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_4_3_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_3_B0__PAPRD_PRE_POST_SCALING_4_3_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_3_B0__PAPRD_PRE_POST_SCALING_4_3_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_3_B0__PAPRD_PRE_POST_SCALING_4_3_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_3_B0__PAPRD_PRE_POST_SCALING_4_3_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_3_B0__PAPRD_PRE_POST_SCALING_4_3_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_3_B0__PAPRD_PRE_POST_SCALING_4_3_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_3_B0__PAPRD_PRE_POST_SCALING_4_3_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_3_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_3_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_3_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_4_3_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_4_3_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_4_3_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_5_3_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_5_3_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_5_3_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_5_3_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_3_B0__PAPRD_PRE_POST_SCALING_5_3_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_3_B0__PAPRD_PRE_POST_SCALING_5_3_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_3_B0__PAPRD_PRE_POST_SCALING_5_3_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_3_B0__PAPRD_PRE_POST_SCALING_5_3_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_3_B0__PAPRD_PRE_POST_SCALING_5_3_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_3_B0__PAPRD_PRE_POST_SCALING_5_3_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_3_B0__PAPRD_PRE_POST_SCALING_5_3_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_3_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_3_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_3_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_5_3_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_5_3_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_5_3_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_6_3_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_6_3_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_6_3_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_6_3_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_3_B0__PAPRD_PRE_POST_SCALING_6_3_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_3_B0__PAPRD_PRE_POST_SCALING_6_3_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_3_B0__PAPRD_PRE_POST_SCALING_6_3_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_3_B0__PAPRD_PRE_POST_SCALING_6_3_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_3_B0__PAPRD_PRE_POST_SCALING_6_3_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_3_B0__PAPRD_PRE_POST_SCALING_6_3_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_3_B0__PAPRD_PRE_POST_SCALING_6_3_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_3_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_3_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_3_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_6_3_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_6_3_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_6_3_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_7_3_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_7_3_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_7_3_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_7_3_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_3_B0__PAPRD_PRE_POST_SCALING_7_3_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_3_B0__PAPRD_PRE_POST_SCALING_7_3_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_3_B0__PAPRD_PRE_POST_SCALING_7_3_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_3_B0__PAPRD_PRE_POST_SCALING_7_3_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_3_B0__PAPRD_PRE_POST_SCALING_7_3_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_3_B0__PAPRD_PRE_POST_SCALING_7_3_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_3_B0__PAPRD_PRE_POST_SCALING_7_3_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_3_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_3_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_3_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_7_3_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_7_3_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_7_3_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_0_4_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_0_4_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_0_4_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_0_4_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_4_B0__PAPRD_PRE_POST_SCALING_0_4_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_4_B0__PAPRD_PRE_POST_SCALING_0_4_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_4_B0__PAPRD_PRE_POST_SCALING_0_4_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_4_B0__PAPRD_PRE_POST_SCALING_0_4_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_4_B0__PAPRD_PRE_POST_SCALING_0_4_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_4_B0__PAPRD_PRE_POST_SCALING_0_4_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_4_B0__PAPRD_PRE_POST_SCALING_0_4_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_4_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_4_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_0_4_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_0_4_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_0_4_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_0_4_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_1_4_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_1_4_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_1_4_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_1_4_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_4_B0__PAPRD_PRE_POST_SCALING_1_4_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_4_B0__PAPRD_PRE_POST_SCALING_1_4_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_4_B0__PAPRD_PRE_POST_SCALING_1_4_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_4_B0__PAPRD_PRE_POST_SCALING_1_4_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_4_B0__PAPRD_PRE_POST_SCALING_1_4_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_4_B0__PAPRD_PRE_POST_SCALING_1_4_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_4_B0__PAPRD_PRE_POST_SCALING_1_4_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_4_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_4_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_1_4_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_1_4_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_1_4_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_1_4_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_2_4_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_2_4_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_2_4_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_2_4_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_4_B0__PAPRD_PRE_POST_SCALING_2_4_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_4_B0__PAPRD_PRE_POST_SCALING_2_4_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_4_B0__PAPRD_PRE_POST_SCALING_2_4_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_4_B0__PAPRD_PRE_POST_SCALING_2_4_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_4_B0__PAPRD_PRE_POST_SCALING_2_4_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_4_B0__PAPRD_PRE_POST_SCALING_2_4_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_4_B0__PAPRD_PRE_POST_SCALING_2_4_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_4_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_4_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_2_4_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_2_4_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_2_4_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_2_4_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_3_4_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_3_4_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_3_4_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_3_4_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_4_B0__PAPRD_PRE_POST_SCALING_3_4_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_4_B0__PAPRD_PRE_POST_SCALING_3_4_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_4_B0__PAPRD_PRE_POST_SCALING_3_4_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_4_B0__PAPRD_PRE_POST_SCALING_3_4_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_4_B0__PAPRD_PRE_POST_SCALING_3_4_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_4_B0__PAPRD_PRE_POST_SCALING_3_4_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_4_B0__PAPRD_PRE_POST_SCALING_3_4_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_4_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_4_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_3_4_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_3_4_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_3_4_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_3_4_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_4_4_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_4_4_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_4_4_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_4_4_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_4_B0__PAPRD_PRE_POST_SCALING_4_4_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_4_B0__PAPRD_PRE_POST_SCALING_4_4_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_4_B0__PAPRD_PRE_POST_SCALING_4_4_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_4_B0__PAPRD_PRE_POST_SCALING_4_4_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_4_B0__PAPRD_PRE_POST_SCALING_4_4_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_4_B0__PAPRD_PRE_POST_SCALING_4_4_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_4_B0__PAPRD_PRE_POST_SCALING_4_4_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_4_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_4_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_4_4_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_4_4_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_4_4_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_4_4_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_5_4_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_5_4_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_5_4_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_5_4_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_4_B0__PAPRD_PRE_POST_SCALING_5_4_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_4_B0__PAPRD_PRE_POST_SCALING_5_4_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_4_B0__PAPRD_PRE_POST_SCALING_5_4_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_4_B0__PAPRD_PRE_POST_SCALING_5_4_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_4_B0__PAPRD_PRE_POST_SCALING_5_4_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_4_B0__PAPRD_PRE_POST_SCALING_5_4_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_4_B0__PAPRD_PRE_POST_SCALING_5_4_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_4_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_4_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_5_4_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_5_4_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_5_4_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_5_4_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_6_4_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_6_4_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_6_4_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_6_4_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_4_B0__PAPRD_PRE_POST_SCALING_6_4_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_4_B0__PAPRD_PRE_POST_SCALING_6_4_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_4_B0__PAPRD_PRE_POST_SCALING_6_4_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_4_B0__PAPRD_PRE_POST_SCALING_6_4_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_4_B0__PAPRD_PRE_POST_SCALING_6_4_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_4_B0__PAPRD_PRE_POST_SCALING_6_4_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_4_B0__PAPRD_PRE_POST_SCALING_6_4_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_4_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_4_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_6_4_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_6_4_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_6_4_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_6_4_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_pre_post_scale_7_4_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_PRE_POST_SCALE_7_4_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_PRE_POST_SCALE_7_4_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_pre_post_scaling_7_4_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_4_B0__PAPRD_PRE_POST_SCALING_7_4_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_4_B0__PAPRD_PRE_POST_SCALING_7_4_B0__WIDTH
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_4_B0__PAPRD_PRE_POST_SCALING_7_4_B0__MASK
define|\
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_4_B0__PAPRD_PRE_POST_SCALING_7_4_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_4_B0__PAPRD_PRE_POST_SCALING_7_4_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_4_B0__PAPRD_PRE_POST_SCALING_7_4_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003ffffU) | ((u_int32_t)(src)&\                     0x0003ffffU)
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_4_B0__PAPRD_PRE_POST_SCALING_7_4_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0003ffffU)))
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_4_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_4_B0__READ
value|0x0003ffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_PRE_POST_SCALE_7_4_B0__WRITE
value|0x0003ffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_PRE_POST_SCALE_7_4_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_pre_post_scale_7_4_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_PRE_POST_SCALE_7_4_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_power_at_am2am_cal_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_POWER_AT_AM2AM_CAL_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_POWER_AT_AM2AM_CAL_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_power_at_am2am_cal_1_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__MASK
define|\
value|0x0000003fU
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000003fU
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000003fU)
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000003fU) | ((u_int32_t)(src)&\                     0x0000003fU)
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_1_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000003fU)))
end_define

begin_comment
comment|/* macros for field paprd_power_at_am2am_cal_2_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__MASK
define|\
value|0x00000fc0U
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000fc0U)>> 6)
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 6)& 0x00000fc0U)
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000fc0U) | (((u_int32_t)(src)<<\                     6)& 0x00000fc0U)
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_2_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 6)& ~0x00000fc0U)))
end_define

begin_comment
comment|/* macros for field paprd_power_at_am2am_cal_3_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__MASK
define|\
value|0x0003f000U
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x0003f000U)>> 12)
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 12)& 0x0003f000U)
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003f000U) | (((u_int32_t)(src)<<\                     12)& 0x0003f000U)
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_3_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 12)& ~0x0003f000U)))
end_define

begin_comment
comment|/* macros for field paprd_power_at_am2am_cal_4_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__MASK
define|\
value|0x00fc0000U
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00fc0000U)>> 18)
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 18)& 0x00fc0000U)
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00fc0000U) | (((u_int32_t)(src)<<\                     18)& 0x00fc0000U)
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__PAPRD_POWER_AT_AM2AM_CAL_4_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 18)& ~0x00fc0000U)))
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__READ
value|0x00ffffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_POWER_AT_AM2AM_CAL_B0__WRITE
value|0x00ffffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_POWER_AT_AM2AM_CAL_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_power_at_am2am_cal_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_POWER_AT_AM2AM_CAL_B0__NUM
define|\
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::paprd_valid_obdb_b0 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PAPRD_VALID_OBDB_B0_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PAPRD_VALID_OBDB_B0_MACRO__
end_define

begin_comment
comment|/* macros for field paprd_valid_obdb_0_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__MASK
value|0x0000003fU
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000003fU
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000003fU)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000003fU) | ((u_int32_t)(src)&\                     0x0000003fU)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_0_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000003fU)))
end_define

begin_comment
comment|/* macros for field paprd_valid_obdb_1_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__MASK
value|0x00000fc0U
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00000fc0U)>> 6)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 6)& 0x00000fc0U)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000fc0U) | (((u_int32_t)(src)<<\                     6)& 0x00000fc0U)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_1_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 6)& ~0x00000fc0U)))
end_define

begin_comment
comment|/* macros for field paprd_valid_obdb_2_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__MASK
value|0x0003f000U
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x0003f000U)>> 12)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 12)& 0x0003f000U)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0003f000U) | (((u_int32_t)(src)<<\                     12)& 0x0003f000U)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_2_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 12)& ~0x0003f000U)))
end_define

begin_comment
comment|/* macros for field paprd_valid_obdb_3_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__SHIFT
value|18
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__MASK
value|0x00fc0000U
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x00fc0000U)>> 18)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 18)& 0x00fc0000U)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00fc0000U) | (((u_int32_t)(src)<<\                     18)& 0x00fc0000U)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_3_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 18)& ~0x00fc0000U)))
end_define

begin_comment
comment|/* macros for field paprd_valid_obdb_4_b0 */
end_comment

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__MASK
value|0x3f000000U
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x3f000000U)>> 24)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 24)& 0x3f000000U)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x3f000000U) | (((u_int32_t)(src)<<\                     24)& 0x3f000000U)
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__PAPRD_VALID_OBDB_4_B0__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 24)& ~0x3f000000U)))
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__READ
value|0x3fffffffU
end_define

begin_define
define|#
directive|define
name|PAPRD_VALID_OBDB_B0__WRITE
value|0x3fffffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PAPRD_VALID_OBDB_B0_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_chn_ext_reg_map.BB_paprd_valid_obdb_b0 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_CHN_EXT_REG_MAP__BB_PAPRD_VALID_OBDB_B0__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_1 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_1_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_1_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table1 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_1__GREEN_TG_TABLE1__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_1__GREEN_TG_TABLE1__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_1__GREEN_TG_TABLE1__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_1__GREEN_TG_TABLE1__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_1__GREEN_TG_TABLE1__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_1__GREEN_TG_TABLE1__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_1__GREEN_TG_TABLE1__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_1__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_1__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_1__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_1_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_1 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_1__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_2_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_2_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table2 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_2__GREEN_TG_TABLE2__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_2__GREEN_TG_TABLE2__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_2__GREEN_TG_TABLE2__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_2__GREEN_TG_TABLE2__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_2__GREEN_TG_TABLE2__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_2__GREEN_TG_TABLE2__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_2__GREEN_TG_TABLE2__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_2__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_2__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_2__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_2_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_2 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_2__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_3 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_3_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_3_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table3 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_3__GREEN_TG_TABLE3__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_3__GREEN_TG_TABLE3__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_3__GREEN_TG_TABLE3__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_3__GREEN_TG_TABLE3__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_3__GREEN_TG_TABLE3__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_3__GREEN_TG_TABLE3__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_3__GREEN_TG_TABLE3__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_3__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_3__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_3__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_3_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_3 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_3__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_4 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_4_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_4_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table4 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_4__GREEN_TG_TABLE4__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_4__GREEN_TG_TABLE4__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_4__GREEN_TG_TABLE4__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_4__GREEN_TG_TABLE4__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_4__GREEN_TG_TABLE4__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_4__GREEN_TG_TABLE4__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_4__GREEN_TG_TABLE4__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_4__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_4__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_4__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_4_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_4 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_4__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_5 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_5_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_5_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table5 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_5__GREEN_TG_TABLE5__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_5__GREEN_TG_TABLE5__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_5__GREEN_TG_TABLE5__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_5__GREEN_TG_TABLE5__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_5__GREEN_TG_TABLE5__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_5__GREEN_TG_TABLE5__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_5__GREEN_TG_TABLE5__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_5__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_5__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_5__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_5_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_5 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_5__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_6 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_6_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_6_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table6 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_6__GREEN_TG_TABLE6__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_6__GREEN_TG_TABLE6__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_6__GREEN_TG_TABLE6__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_6__GREEN_TG_TABLE6__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_6__GREEN_TG_TABLE6__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_6__GREEN_TG_TABLE6__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_6__GREEN_TG_TABLE6__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_6__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_6__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_6__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_6_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_6 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_6__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_7 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_7_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_7_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table7 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_7__GREEN_TG_TABLE7__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_7__GREEN_TG_TABLE7__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_7__GREEN_TG_TABLE7__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_7__GREEN_TG_TABLE7__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_7__GREEN_TG_TABLE7__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_7__GREEN_TG_TABLE7__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_7__GREEN_TG_TABLE7__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_7__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_7__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_7__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_7_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_7 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_7__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_8_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_8_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table8 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_8__GREEN_TG_TABLE8__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_8__GREEN_TG_TABLE8__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_8__GREEN_TG_TABLE8__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_8__GREEN_TG_TABLE8__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_8__GREEN_TG_TABLE8__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_8__GREEN_TG_TABLE8__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_8__GREEN_TG_TABLE8__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_8__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_8__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_8__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_8_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_8 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_8__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_9 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_9_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_9_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table9 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_9__GREEN_TG_TABLE9__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_9__GREEN_TG_TABLE9__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_9__GREEN_TG_TABLE9__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_9__GREEN_TG_TABLE9__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_9__GREEN_TG_TABLE9__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_9__GREEN_TG_TABLE9__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_9__GREEN_TG_TABLE9__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_9__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_9__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_9__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_9_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_9 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_9__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_10 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_10_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_10_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table10 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_10__GREEN_TG_TABLE10__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_10__GREEN_TG_TABLE10__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_10__GREEN_TG_TABLE10__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_10__GREEN_TG_TABLE10__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_10__GREEN_TG_TABLE10__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_10__GREEN_TG_TABLE10__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_10__GREEN_TG_TABLE10__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_10__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_10__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_10__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_10_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_10 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_10__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_11 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_11_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_11_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table11 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_11__GREEN_TG_TABLE11__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_11__GREEN_TG_TABLE11__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_11__GREEN_TG_TABLE11__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_11__GREEN_TG_TABLE11__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_11__GREEN_TG_TABLE11__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_11__GREEN_TG_TABLE11__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_11__GREEN_TG_TABLE11__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_11__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_11__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_11__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_11_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_11 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_11__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_12 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_12_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_12_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table12 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_12__GREEN_TG_TABLE12__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_12__GREEN_TG_TABLE12__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_12__GREEN_TG_TABLE12__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_12__GREEN_TG_TABLE12__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_12__GREEN_TG_TABLE12__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_12__GREEN_TG_TABLE12__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_12__GREEN_TG_TABLE12__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_12__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_12__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_12__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_12_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_12 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_12__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_13 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_13_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_13_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table13 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_13__GREEN_TG_TABLE13__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_13__GREEN_TG_TABLE13__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_13__GREEN_TG_TABLE13__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_13__GREEN_TG_TABLE13__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_13__GREEN_TG_TABLE13__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_13__GREEN_TG_TABLE13__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_13__GREEN_TG_TABLE13__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_13__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_13__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_13__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_13_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_13 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_13__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_14 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_14_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_14_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table14 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_14__GREEN_TG_TABLE14__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_14__GREEN_TG_TABLE14__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_14__GREEN_TG_TABLE14__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_14__GREEN_TG_TABLE14__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_14__GREEN_TG_TABLE14__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_14__GREEN_TG_TABLE14__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_14__GREEN_TG_TABLE14__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_14__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_14__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_14__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_14_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_14 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_14__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_15 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_15_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_15_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table15 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_15__GREEN_TG_TABLE15__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_15__GREEN_TG_TABLE15__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_15__GREEN_TG_TABLE15__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_15__GREEN_TG_TABLE15__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_15__GREEN_TG_TABLE15__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_15__GREEN_TG_TABLE15__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_15__GREEN_TG_TABLE15__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_15__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_15__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_15__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_15_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_15 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_15__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_16 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_16_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_16_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table16 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_16__GREEN_TG_TABLE16__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_16__GREEN_TG_TABLE16__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_16__GREEN_TG_TABLE16__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_16__GREEN_TG_TABLE16__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_16__GREEN_TG_TABLE16__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_16__GREEN_TG_TABLE16__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_16__GREEN_TG_TABLE16__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_16__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_16__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_16__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_16_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_16 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_16__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_17 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_17_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_17_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table17 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_17__GREEN_TG_TABLE17__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_17__GREEN_TG_TABLE17__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_17__GREEN_TG_TABLE17__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_17__GREEN_TG_TABLE17__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_17__GREEN_TG_TABLE17__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_17__GREEN_TG_TABLE17__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_17__GREEN_TG_TABLE17__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_17__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_17__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_17__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_17_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_17 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_17__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_18 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_18_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_18_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table18 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_18__GREEN_TG_TABLE18__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_18__GREEN_TG_TABLE18__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_18__GREEN_TG_TABLE18__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_18__GREEN_TG_TABLE18__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_18__GREEN_TG_TABLE18__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_18__GREEN_TG_TABLE18__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_18__GREEN_TG_TABLE18__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_18__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_18__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_18__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_18_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_18 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_18__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_19 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_19_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_19_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table19 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_19__GREEN_TG_TABLE19__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_19__GREEN_TG_TABLE19__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_19__GREEN_TG_TABLE19__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_19__GREEN_TG_TABLE19__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_19__GREEN_TG_TABLE19__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_19__GREEN_TG_TABLE19__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_19__GREEN_TG_TABLE19__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_19__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_19__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_19__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_19_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_19 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_19__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_20 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_20_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_20_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table20 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_20__GREEN_TG_TABLE20__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_20__GREEN_TG_TABLE20__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_20__GREEN_TG_TABLE20__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_20__GREEN_TG_TABLE20__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_20__GREEN_TG_TABLE20__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_20__GREEN_TG_TABLE20__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_20__GREEN_TG_TABLE20__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_20__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_20__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_20__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_20_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_20 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_20__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_21 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_21_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_21_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table21 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_21__GREEN_TG_TABLE21__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_21__GREEN_TG_TABLE21__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_21__GREEN_TG_TABLE21__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_21__GREEN_TG_TABLE21__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_21__GREEN_TG_TABLE21__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_21__GREEN_TG_TABLE21__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_21__GREEN_TG_TABLE21__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_21__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_21__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_21__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_21_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_21 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_21__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_22 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_22_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_22_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table22 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_22__GREEN_TG_TABLE22__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_22__GREEN_TG_TABLE22__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_22__GREEN_TG_TABLE22__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_22__GREEN_TG_TABLE22__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_22__GREEN_TG_TABLE22__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_22__GREEN_TG_TABLE22__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_22__GREEN_TG_TABLE22__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_22__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_22__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_22__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_22_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_22 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_22__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_23 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_23_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_23_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table23 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_23__GREEN_TG_TABLE23__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_23__GREEN_TG_TABLE23__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_23__GREEN_TG_TABLE23__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_23__GREEN_TG_TABLE23__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_23__GREEN_TG_TABLE23__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_23__GREEN_TG_TABLE23__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_23__GREEN_TG_TABLE23__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_23__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_23__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_23__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_23_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_23 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_23__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_24 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_24_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_24_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table24 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_24__GREEN_TG_TABLE24__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_24__GREEN_TG_TABLE24__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_24__GREEN_TG_TABLE24__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_24__GREEN_TG_TABLE24__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_24__GREEN_TG_TABLE24__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_24__GREEN_TG_TABLE24__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_24__GREEN_TG_TABLE24__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_24__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_24__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_24__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_24_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_24 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_24__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_25 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_25_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_25_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table25 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_25__GREEN_TG_TABLE25__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_25__GREEN_TG_TABLE25__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_25__GREEN_TG_TABLE25__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_25__GREEN_TG_TABLE25__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_25__GREEN_TG_TABLE25__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_25__GREEN_TG_TABLE25__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_25__GREEN_TG_TABLE25__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_25__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_25__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_25__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_25_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_25 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_25__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_26 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_26_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_26_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table26 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_26__GREEN_TG_TABLE26__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_26__GREEN_TG_TABLE26__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_26__GREEN_TG_TABLE26__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_26__GREEN_TG_TABLE26__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_26__GREEN_TG_TABLE26__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_26__GREEN_TG_TABLE26__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_26__GREEN_TG_TABLE26__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_26__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_26__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_26__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_26_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_26 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_26__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_27 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_27_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_27_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table27 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_27__GREEN_TG_TABLE27__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_27__GREEN_TG_TABLE27__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_27__GREEN_TG_TABLE27__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_27__GREEN_TG_TABLE27__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_27__GREEN_TG_TABLE27__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_27__GREEN_TG_TABLE27__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_27__GREEN_TG_TABLE27__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_27__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_27__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_27__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_27_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_27 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_27__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_28 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_28_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_28_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table28 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_28__GREEN_TG_TABLE28__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_28__GREEN_TG_TABLE28__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_28__GREEN_TG_TABLE28__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_28__GREEN_TG_TABLE28__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_28__GREEN_TG_TABLE28__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_28__GREEN_TG_TABLE28__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_28__GREEN_TG_TABLE28__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_28__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_28__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_28__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_28_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_28 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_28__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_29 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_29_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_29_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table29 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_29__GREEN_TG_TABLE29__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_29__GREEN_TG_TABLE29__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_29__GREEN_TG_TABLE29__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_29__GREEN_TG_TABLE29__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_29__GREEN_TG_TABLE29__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_29__GREEN_TG_TABLE29__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_29__GREEN_TG_TABLE29__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_29__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_29__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_29__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_29_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_29 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_29__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_30 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_30_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_30_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table30 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_30__GREEN_TG_TABLE30__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_30__GREEN_TG_TABLE30__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_30__GREEN_TG_TABLE30__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_30__GREEN_TG_TABLE30__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_30__GREEN_TG_TABLE30__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_30__GREEN_TG_TABLE30__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_30__GREEN_TG_TABLE30__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_30__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_30__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_30__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_30_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_30 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_30__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_31 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_31_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_31_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table31 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_31__GREEN_TG_TABLE31__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_31__GREEN_TG_TABLE31__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_31__GREEN_TG_TABLE31__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_31__GREEN_TG_TABLE31__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_31__GREEN_TG_TABLE31__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_31__GREEN_TG_TABLE31__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_31__GREEN_TG_TABLE31__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_31__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_31__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_31__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_31_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_31 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_31__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::green_tx_gain_tab_32 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GREEN_TX_GAIN_TAB_32_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__GREEN_TX_GAIN_TAB_32_MACRO__
end_define

begin_comment
comment|/* macros for field green_tg_table32 */
end_comment

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_32__GREEN_TG_TABLE32__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_32__GREEN_TG_TABLE32__WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_32__GREEN_TG_TABLE32__MASK
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_32__GREEN_TG_TABLE32__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(u_int32_t)(src)\& 0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_32__GREEN_TG_TABLE32__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|((u_int32_t)(src)\& 0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_32__GREEN_TG_TABLE32__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0000007fU) | ((u_int32_t)(src)&\                     0x0000007fU)
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_32__GREEN_TG_TABLE32__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!(((u_int32_t)(src)\& ~0x0000007fU)))
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_32__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_32__READ
value|0x0000007fU
end_define

begin_define
define|#
directive|define
name|GREEN_TX_GAIN_TAB_32__WRITE
value|0x0000007fU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GREEN_TX_GAIN_TAB_32_MACRO__ */
end_comment

begin_comment
comment|/* macros for bb_reg_block.bb_sm_ext_reg_map.BB_green_tx_gain_tab_32 */
end_comment

begin_define
define|#
directive|define
name|INST_BB_REG_BLOCK__BB_SM_EXT_REG_MAP__BB_GREEN_TX_GAIN_TAB_32__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::PMU1 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PMU1_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PMU1_MACRO__
end_define

begin_comment
comment|/* macros for field pwd */
end_comment

begin_define
define|#
directive|define
name|PMU1__PWD__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PMU1__PWD__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|PMU1__PWD__MASK
value|0x00000007U
end_define

begin_define
define|#
directive|define
name|PMU1__PWD__READ
parameter_list|(
name|src
parameter_list|)
value|(u_int32_t)(src)& 0x00000007U
end_define

begin_define
define|#
directive|define
name|PMU1__PWD__WRITE
parameter_list|(
name|src
parameter_list|)
value|((u_int32_t)(src)& 0x00000007U)
end_define

begin_define
define|#
directive|define
name|PMU1__PWD__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000007U) | ((u_int32_t)(src)&\                     0x00000007U)
end_define

begin_define
define|#
directive|define
name|PMU1__PWD__VERIFY
parameter_list|(
name|src
parameter_list|)
value|(!(((u_int32_t)(src)& ~0x00000007U)))
end_define

begin_comment
comment|/* macros for field Nfdiv */
end_comment

begin_define
define|#
directive|define
name|PMU1__NFDIV__SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|PMU1__NFDIV__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|PMU1__NFDIV__MASK
value|0x00000008U
end_define

begin_define
define|#
directive|define
name|PMU1__NFDIV__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x00000008U)>> 3)
end_define

begin_define
define|#
directive|define
name|PMU1__NFDIV__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 3)& 0x00000008U)
end_define

begin_define
define|#
directive|define
name|PMU1__NFDIV__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000008U) | (((u_int32_t)(src)<<\                     3)& 0x00000008U)
end_define

begin_define
define|#
directive|define
name|PMU1__NFDIV__VERIFY
parameter_list|(
name|src
parameter_list|)
value|(!((((u_int32_t)(src)<< 3)& ~0x00000008U)))
end_define

begin_define
define|#
directive|define
name|PMU1__NFDIV__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000008U) | ((u_int32_t)(1)<< 3)
end_define

begin_define
define|#
directive|define
name|PMU1__NFDIV__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000008U) | ((u_int32_t)(0)<< 3)
end_define

begin_comment
comment|/* macros for field Refv */
end_comment

begin_define
define|#
directive|define
name|PMU1__REFV__SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PMU1__REFV__WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|PMU1__REFV__MASK
value|0x000000f0U
end_define

begin_define
define|#
directive|define
name|PMU1__REFV__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x000000f0U)>> 4)
end_define

begin_define
define|#
directive|define
name|PMU1__REFV__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 4)& 0x000000f0U)
end_define

begin_define
define|#
directive|define
name|PMU1__REFV__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x000000f0U) | (((u_int32_t)(src)<<\                     4)& 0x000000f0U)
end_define

begin_define
define|#
directive|define
name|PMU1__REFV__VERIFY
parameter_list|(
name|src
parameter_list|)
value|(!((((u_int32_t)(src)<< 4)& ~0x000000f0U)))
end_define

begin_comment
comment|/* macros for field Gm1 */
end_comment

begin_define
define|#
directive|define
name|PMU1__GM1__SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PMU1__GM1__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|PMU1__GM1__MASK
value|0x00000700U
end_define

begin_define
define|#
directive|define
name|PMU1__GM1__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x00000700U)>> 8)
end_define

begin_define
define|#
directive|define
name|PMU1__GM1__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 8)& 0x00000700U)
end_define

begin_define
define|#
directive|define
name|PMU1__GM1__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00000700U) | (((u_int32_t)(src)<<\                     8)& 0x00000700U)
end_define

begin_define
define|#
directive|define
name|PMU1__GM1__VERIFY
parameter_list|(
name|src
parameter_list|)
value|(!((((u_int32_t)(src)<< 8)& ~0x00000700U)))
end_define

begin_comment
comment|/* macros for field Classb */
end_comment

begin_define
define|#
directive|define
name|PMU1__CLASSB__SHIFT
value|11
end_define

begin_define
define|#
directive|define
name|PMU1__CLASSB__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|PMU1__CLASSB__MASK
value|0x00003800U
end_define

begin_define
define|#
directive|define
name|PMU1__CLASSB__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x00003800U)>> 11)
end_define

begin_define
define|#
directive|define
name|PMU1__CLASSB__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 11)& 0x00003800U)
end_define

begin_define
define|#
directive|define
name|PMU1__CLASSB__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00003800U) | (((u_int32_t)(src)<<\                     11)& 0x00003800U)
end_define

begin_define
define|#
directive|define
name|PMU1__CLASSB__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 11)& ~0x00003800U)))
end_define

begin_comment
comment|/* macros for field Cc */
end_comment

begin_define
define|#
directive|define
name|PMU1__CC__SHIFT
value|14
end_define

begin_define
define|#
directive|define
name|PMU1__CC__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|PMU1__CC__MASK
value|0x0001c000U
end_define

begin_define
define|#
directive|define
name|PMU1__CC__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x0001c000U)>> 14)
end_define

begin_define
define|#
directive|define
name|PMU1__CC__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 14)& 0x0001c000U)
end_define

begin_define
define|#
directive|define
name|PMU1__CC__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0001c000U) | (((u_int32_t)(src)<<\                     14)& 0x0001c000U)
end_define

begin_define
define|#
directive|define
name|PMU1__CC__VERIFY
parameter_list|(
name|src
parameter_list|)
value|(!((((u_int32_t)(src)<< 14)& ~0x0001c000U)))
end_define

begin_comment
comment|/* macros for field Rc */
end_comment

begin_define
define|#
directive|define
name|PMU1__RC__SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|PMU1__RC__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|PMU1__RC__MASK
value|0x000e0000U
end_define

begin_define
define|#
directive|define
name|PMU1__RC__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x000e0000U)>> 17)
end_define

begin_define
define|#
directive|define
name|PMU1__RC__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 17)& 0x000e0000U)
end_define

begin_define
define|#
directive|define
name|PMU1__RC__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x000e0000U) | (((u_int32_t)(src)<<\                     17)& 0x000e0000U)
end_define

begin_define
define|#
directive|define
name|PMU1__RC__VERIFY
parameter_list|(
name|src
parameter_list|)
value|(!((((u_int32_t)(src)<< 17)& ~0x000e0000U)))
end_define

begin_comment
comment|/* macros for field Rampslope */
end_comment

begin_define
define|#
directive|define
name|PMU1__RAMPSLOPE__SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|PMU1__RAMPSLOPE__WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|PMU1__RAMPSLOPE__MASK
value|0x00f00000U
end_define

begin_define
define|#
directive|define
name|PMU1__RAMPSLOPE__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x00f00000U)>> 20)
end_define

begin_define
define|#
directive|define
name|PMU1__RAMPSLOPE__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 20)& 0x00f00000U)
end_define

begin_define
define|#
directive|define
name|PMU1__RAMPSLOPE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00f00000U) | (((u_int32_t)(src)<<\                     20)& 0x00f00000U)
end_define

begin_define
define|#
directive|define
name|PMU1__RAMPSLOPE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 20)& ~0x00f00000U)))
end_define

begin_comment
comment|/* macros for field Segm */
end_comment

begin_define
define|#
directive|define
name|PMU1__SEGM__SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|PMU1__SEGM__WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|PMU1__SEGM__MASK
value|0x03000000U
end_define

begin_define
define|#
directive|define
name|PMU1__SEGM__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x03000000U)>> 24)
end_define

begin_define
define|#
directive|define
name|PMU1__SEGM__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 24)& 0x03000000U)
end_define

begin_define
define|#
directive|define
name|PMU1__SEGM__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x03000000U) | (((u_int32_t)(src)<<\                     24)& 0x03000000U)
end_define

begin_define
define|#
directive|define
name|PMU1__SEGM__VERIFY
parameter_list|(
name|src
parameter_list|)
value|(!((((u_int32_t)(src)<< 24)& ~0x03000000U)))
end_define

begin_comment
comment|/* macros for field UseLocalOsc */
end_comment

begin_define
define|#
directive|define
name|PMU1__USELOCALOSC__SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|PMU1__USELOCALOSC__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|PMU1__USELOCALOSC__MASK
value|0x04000000U
end_define

begin_define
define|#
directive|define
name|PMU1__USELOCALOSC__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x04000000U)>> 26)
end_define

begin_define
define|#
directive|define
name|PMU1__USELOCALOSC__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 26)& 0x04000000U)
end_define

begin_define
define|#
directive|define
name|PMU1__USELOCALOSC__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x04000000U) | (((u_int32_t)(src)<<\                     26)& 0x04000000U)
end_define

begin_define
define|#
directive|define
name|PMU1__USELOCALOSC__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 26)& ~0x04000000U)))
end_define

begin_define
define|#
directive|define
name|PMU1__USELOCALOSC__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x04000000U) | ((u_int32_t)(1)<< 26)
end_define

begin_define
define|#
directive|define
name|PMU1__USELOCALOSC__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x04000000U) | ((u_int32_t)(0)<< 26)
end_define

begin_comment
comment|/* macros for field ForceXoscStable */
end_comment

begin_define
define|#
directive|define
name|PMU1__FORCEXOSCSTABLE__SHIFT
value|27
end_define

begin_define
define|#
directive|define
name|PMU1__FORCEXOSCSTABLE__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|PMU1__FORCEXOSCSTABLE__MASK
value|0x08000000U
end_define

begin_define
define|#
directive|define
name|PMU1__FORCEXOSCSTABLE__READ
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\& 0x08000000U)>> 27)
end_define

begin_define
define|#
directive|define
name|PMU1__FORCEXOSCSTABLE__WRITE
parameter_list|(
name|src
parameter_list|)
define|\
value|(((u_int32_t)(src)\<< 27)& 0x08000000U)
end_define

begin_define
define|#
directive|define
name|PMU1__FORCEXOSCSTABLE__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x08000000U) | (((u_int32_t)(src)<<\                     27)& 0x08000000U)
end_define

begin_define
define|#
directive|define
name|PMU1__FORCEXOSCSTABLE__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 27)& ~0x08000000U)))
end_define

begin_define
define|#
directive|define
name|PMU1__FORCEXOSCSTABLE__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x08000000U) | ((u_int32_t)(1)<< 27)
end_define

begin_define
define|#
directive|define
name|PMU1__FORCEXOSCSTABLE__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x08000000U) | ((u_int32_t)(0)<< 27)
end_define

begin_comment
comment|/* macros for field SelFb */
end_comment

begin_define
define|#
directive|define
name|PMU1__SELFB__SHIFT
value|28
end_define

begin_define
define|#
directive|define
name|PMU1__SELFB__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|PMU1__SELFB__MASK
value|0x10000000U
end_define

begin_define
define|#
directive|define
name|PMU1__SELFB__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x10000000U)>> 28)
end_define

begin_define
define|#
directive|define
name|PMU1__SELFB__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 28)& 0x10000000U)
end_define

begin_define
define|#
directive|define
name|PMU1__SELFB__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x10000000U) | (((u_int32_t)(src)<<\                     28)& 0x10000000U)
end_define

begin_define
define|#
directive|define
name|PMU1__SELFB__VERIFY
parameter_list|(
name|src
parameter_list|)
value|(!((((u_int32_t)(src)<< 28)& ~0x10000000U)))
end_define

begin_define
define|#
directive|define
name|PMU1__SELFB__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x10000000U) | ((u_int32_t)(1)<< 28)
end_define

begin_define
define|#
directive|define
name|PMU1__SELFB__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x10000000U) | ((u_int32_t)(0)<< 28)
end_define

begin_comment
comment|/* macros for field FilterFb */
end_comment

begin_define
define|#
directive|define
name|PMU1__FILTERFB__SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|PMU1__FILTERFB__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|PMU1__FILTERFB__MASK
value|0xe0000000U
end_define

begin_define
define|#
directive|define
name|PMU1__FILTERFB__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0xe0000000U)>> 29)
end_define

begin_define
define|#
directive|define
name|PMU1__FILTERFB__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 29)& 0xe0000000U)
end_define

begin_define
define|#
directive|define
name|PMU1__FILTERFB__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0xe0000000U) | (((u_int32_t)(src)<<\                     29)& 0xe0000000U)
end_define

begin_define
define|#
directive|define
name|PMU1__FILTERFB__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 29)& ~0xe0000000U)))
end_define

begin_define
define|#
directive|define
name|PMU1__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PMU1__READ
value|0xffffffffU
end_define

begin_define
define|#
directive|define
name|PMU1__WRITE
value|0xffffffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PMU1_MACRO__ */
end_comment

begin_comment
comment|/* macros for radio65_reg_block.ch0_PMU1 */
end_comment

begin_define
define|#
directive|define
name|INST_RADIO65_REG_BLOCK__CH0_PMU1__NUM
value|1
end_define

begin_comment
comment|/* macros for BlueprintGlobalNameSpace::PMU2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PMU2_MACRO__
end_ifndef

begin_define
define|#
directive|define
name|__PMU2_MACRO__
end_define

begin_comment
comment|/* macros for field SPARE2 */
end_comment

begin_define
define|#
directive|define
name|PMU2__SPARE2__SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE2__WIDTH
value|19
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE2__MASK
value|0x0007ffffU
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE2__READ
parameter_list|(
name|src
parameter_list|)
value|(u_int32_t)(src)& 0x0007ffffU
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE2__WRITE
parameter_list|(
name|src
parameter_list|)
value|((u_int32_t)(src)& 0x0007ffffU)
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE2__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x0007ffffU) | ((u_int32_t)(src)&\                     0x0007ffffU)
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE2__VERIFY
parameter_list|(
name|src
parameter_list|)
value|(!(((u_int32_t)(src)& ~0x0007ffffU)))
end_define

begin_comment
comment|/* macros for field pwdlpo_pwd */
end_comment

begin_define
define|#
directive|define
name|PMU2__PWDLPO_PWD__SHIFT
value|19
end_define

begin_define
define|#
directive|define
name|PMU2__PWDLPO_PWD__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|PMU2__PWDLPO_PWD__MASK
value|0x00080000U
end_define

begin_define
define|#
directive|define
name|PMU2__PWDLPO_PWD__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x00080000U)>> 19)
end_define

begin_define
define|#
directive|define
name|PMU2__PWDLPO_PWD__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 19)& 0x00080000U)
end_define

begin_define
define|#
directive|define
name|PMU2__PWDLPO_PWD__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00080000U) | (((u_int32_t)(src)<<\                     19)& 0x00080000U)
end_define

begin_define
define|#
directive|define
name|PMU2__PWDLPO_PWD__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 19)& ~0x00080000U)))
end_define

begin_define
define|#
directive|define
name|PMU2__PWDLPO_PWD__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00080000U) | ((u_int32_t)(1)<< 19)
end_define

begin_define
define|#
directive|define
name|PMU2__PWDLPO_PWD__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00080000U) | ((u_int32_t)(0)<< 19)
end_define

begin_comment
comment|/* macros for field disc_ovr */
end_comment

begin_define
define|#
directive|define
name|PMU2__DISC_OVR__SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|PMU2__DISC_OVR__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|PMU2__DISC_OVR__MASK
value|0x00100000U
end_define

begin_define
define|#
directive|define
name|PMU2__DISC_OVR__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x00100000U)>> 20)
end_define

begin_define
define|#
directive|define
name|PMU2__DISC_OVR__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 20)& 0x00100000U)
end_define

begin_define
define|#
directive|define
name|PMU2__DISC_OVR__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00100000U) | (((u_int32_t)(src)<<\                     20)& 0x00100000U)
end_define

begin_define
define|#
directive|define
name|PMU2__DISC_OVR__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 20)& ~0x00100000U)))
end_define

begin_define
define|#
directive|define
name|PMU2__DISC_OVR__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00100000U) | ((u_int32_t)(1)<< 20)
end_define

begin_define
define|#
directive|define
name|PMU2__DISC_OVR__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00100000U) | ((u_int32_t)(0)<< 20)
end_define

begin_comment
comment|/* macros for field pgm */
end_comment

begin_define
define|#
directive|define
name|PMU2__PGM__SHIFT
value|21
end_define

begin_define
define|#
directive|define
name|PMU2__PGM__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|PMU2__PGM__MASK
value|0x00200000U
end_define

begin_define
define|#
directive|define
name|PMU2__PGM__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x00200000U)>> 21)
end_define

begin_define
define|#
directive|define
name|PMU2__PGM__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 21)& 0x00200000U)
end_define

begin_define
define|#
directive|define
name|PMU2__PGM__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00200000U) | (((u_int32_t)(src)<<\                     21)& 0x00200000U)
end_define

begin_define
define|#
directive|define
name|PMU2__PGM__VERIFY
parameter_list|(
name|src
parameter_list|)
value|(!((((u_int32_t)(src)<< 21)& ~0x00200000U)))
end_define

begin_define
define|#
directive|define
name|PMU2__PGM__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00200000U) | ((u_int32_t)(1)<< 21)
end_define

begin_define
define|#
directive|define
name|PMU2__PGM__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x00200000U) | ((u_int32_t)(0)<< 21)
end_define

begin_comment
comment|/* macros for field FilterVc */
end_comment

begin_define
define|#
directive|define
name|PMU2__FILTERVC__SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|PMU2__FILTERVC__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|PMU2__FILTERVC__MASK
value|0x01c00000U
end_define

begin_define
define|#
directive|define
name|PMU2__FILTERVC__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x01c00000U)>> 22)
end_define

begin_define
define|#
directive|define
name|PMU2__FILTERVC__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 22)& 0x01c00000U)
end_define

begin_define
define|#
directive|define
name|PMU2__FILTERVC__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x01c00000U) | (((u_int32_t)(src)<<\                     22)& 0x01c00000U)
end_define

begin_define
define|#
directive|define
name|PMU2__FILTERVC__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 22)& ~0x01c00000U)))
end_define

begin_comment
comment|/* macros for field Disc */
end_comment

begin_define
define|#
directive|define
name|PMU2__DISC__SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|PMU2__DISC__WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|PMU2__DISC__MASK
value|0x02000000U
end_define

begin_define
define|#
directive|define
name|PMU2__DISC__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x02000000U)>> 25)
end_define

begin_define
define|#
directive|define
name|PMU2__DISC__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 25)& 0x02000000U)
end_define

begin_define
define|#
directive|define
name|PMU2__DISC__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x02000000U) | (((u_int32_t)(src)<<\                     25)& 0x02000000U)
end_define

begin_define
define|#
directive|define
name|PMU2__DISC__VERIFY
parameter_list|(
name|src
parameter_list|)
value|(!((((u_int32_t)(src)<< 25)& ~0x02000000U)))
end_define

begin_define
define|#
directive|define
name|PMU2__DISC__SET
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x02000000U) | ((u_int32_t)(1)<< 25)
end_define

begin_define
define|#
directive|define
name|PMU2__DISC__CLR
parameter_list|(
name|dst
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x02000000U) | ((u_int32_t)(0)<< 25)
end_define

begin_comment
comment|/* macros for field DiscDel */
end_comment

begin_define
define|#
directive|define
name|PMU2__DISCDEL__SHIFT
value|26
end_define

begin_define
define|#
directive|define
name|PMU2__DISCDEL__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|PMU2__DISCDEL__MASK
value|0x1c000000U
end_define

begin_define
define|#
directive|define
name|PMU2__DISCDEL__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0x1c000000U)>> 26)
end_define

begin_define
define|#
directive|define
name|PMU2__DISCDEL__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 26)& 0x1c000000U)
end_define

begin_define
define|#
directive|define
name|PMU2__DISCDEL__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0x1c000000U) | (((u_int32_t)(src)<<\                     26)& 0x1c000000U)
end_define

begin_define
define|#
directive|define
name|PMU2__DISCDEL__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 26)& ~0x1c000000U)))
end_define

begin_comment
comment|/* macros for field SPARE1 */
end_comment

begin_define
define|#
directive|define
name|PMU2__SPARE1__SHIFT
value|29
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE1__WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE1__MASK
value|0xe0000000U
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE1__READ
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)& 0xe0000000U)>> 29)
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE1__WRITE
parameter_list|(
name|src
parameter_list|)
value|(((u_int32_t)(src)<< 29)& 0xe0000000U)
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE1__MODIFY
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
define|\
value|(dst) = ((dst)&\                     ~0xe0000000U) | (((u_int32_t)(src)<<\                     29)& 0xe0000000U)
end_define

begin_define
define|#
directive|define
name|PMU2__SPARE1__VERIFY
parameter_list|(
name|src
parameter_list|)
define|\
value|(!((((u_int32_t)(src)\<< 29)& ~0xe0000000U)))
end_define

begin_define
define|#
directive|define
name|PMU2__TYPE
value|u_int32_t
end_define

begin_define
define|#
directive|define
name|PMU2__READ
value|0xffffffffU
end_define

begin_define
define|#
directive|define
name|PMU2__WRITE
value|0xffffffffU
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PMU2_MACRO__ */
end_comment

begin_comment
comment|/* macros for radio65_reg_block.ch0_PMU2 */
end_comment

begin_define
define|#
directive|define
name|INST_RADIO65_REG_BLOCK__CH0_PMU2__NUM
value|1
end_define

begin_define
define|#
directive|define
name|POSEIDON_REG_MAP__VERSION
define|\
value|"/cad/local/lib/perl/Pinfo.pm\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/analog_intf_reg_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/bb_reg_map_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/efuse_reg_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/mac_dcu_reg_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/mac_dma_reg_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/mac_pcu_reg_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/mac_qcu_reg_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/merlin2_0_radio_reg_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/pcie_phy_reg_csr_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/radio_65_reg_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/rtc_reg_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/rtc_sync_reg_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/sysconfig/svd_reg_sysconfig.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top/emulation_misc.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top/merlin2_0_radio_reg_map.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top/pcie_phy_reg_csr.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top/poseidon_radio_reg.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/blueprint/top/poseidon_reg.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/env/blueprint/ath_ansic.pm\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/amba_mac/blueprint/rtc_sync_reg.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/amba_mac/svd/blueprint/svd_reg.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/apb_analog/analog_intf_reg.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/bb/blueprint/bb_reg_map.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/host_intf/rtl/blueprint/efuse_reg.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/host_intf/rtl/blueprint/host_intf_reg.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/mac/rtl/mac_dma/blueprint/mac_dcu_reg.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/mac/rtl/mac_dma/blueprint/mac_dma_reg.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/mac/rtl/mac_dma/blueprint/mac_qcu_reg.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/mac/rtl/mac_pcu/blueprint/mac_pcu_reg.rdl\n\                     /trees/kcwo/kcwo-dev/depot/chips/poseidon/1.0/rtl/rtc/blueprint/rtc_reg.rdl"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __REG_POSEIDON_REG_MAP_MACRO_H__ */
end_comment

end_unit

