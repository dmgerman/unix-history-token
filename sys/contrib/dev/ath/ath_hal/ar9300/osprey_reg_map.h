begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Qualcomm Atheros, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* File:       /trees/yli/yli-dev/chips/osprey/2.0/blueprint/top/osprey_reg_map.h*/
end_comment

begin_comment
comment|/* Creator:    yli                                                           */
end_comment

begin_comment
comment|/* Time:       Wednesday Jan 6, 2010 [2:09:02 pm]                            */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Path:       /trees/yli/yli-dev/chips/osprey/2.0/blueprint/top             */
end_comment

begin_comment
comment|/* Arguments:  /cad/denali/blueprint/3.7//Linux/blueprint -codegen           */
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/env/blueprint/ath_ansic.codegen*/
end_comment

begin_comment
comment|/*             -ath_ansic -Wdesc -I                                          */
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/top -I          */
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint -I              */
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/env/blueprint -I          */
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig -odir */
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/top -eval       */
end_comment

begin_comment
comment|/*             {$INCLUDE_SYSCONFIG_FILES=1} -eval                            */
end_comment

begin_comment
comment|/*             $WAR_EV58615_for_ansic_codegen=1 osprey_reg.rdl               */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Sources:    /trees/yli/yli-dev/chips/osprey/2.0/blueprint/top/emulation_misc.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/mac_dma_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/rtl/amba_mac/svd/blueprint/svd_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/mac_pcu_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/top/merlin2_0_radio_reg_map.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/rtl/mac/rtl/mac_dma/blueprint/mac_dma_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/rtl/host_intf/rtl/blueprint/efuse_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/rtl/mac/rtl/mac_dma/blueprint/mac_dcu_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/ip/pcie_axi/blueprint/DWC_pcie_ep.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/rtl/apb_analog/analog_intf_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/rtl/mac/rtl/mac_pcu/blueprint/mac_pcu_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/rtl/rtc/blueprint/rtc_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/DWC_pcie_dbi_axi_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/rtl/host_intf/rtl/blueprint/host_intf_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/rtl/mac/rtl/mac_dma/blueprint/mac_qcu_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/rtl/bb/blueprint/bb_reg_map.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/rtc_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/efuse_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/bb_reg_map_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/osprey_pcieconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/top/osprey_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/radio_65_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/merlin2_0_radio_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/mac_qcu_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/mac_dcu_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/rtl/amba_mac/blueprint/rtc_sync_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/analog_intf_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/svd_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/top/osprey_radio_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/blueprint/sysconfig/host_intf_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/yli/yli-dev/chips/osprey/2.0/env/blueprint/ath_ansic.pm*/
end_comment

begin_comment
comment|/*             /cad/local/lib/perl/Pinfo.pm                                  */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Blueprint:   3.7 (Fri Oct 5 10:32:33 PDT 2007)                            */
end_comment

begin_comment
comment|/* Machine:    artemis                                                       */
end_comment

begin_comment
comment|/* OS:         Linux 2.6.9-78.0.5.ELlargesmp                                 */
end_comment

begin_comment
comment|/* Description:                                                              */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*This Register Map contains the complete register set for OSPREY.           */
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
name|__REG_OSPREY_REG_MAP_H__
end_ifndef

begin_define
define|#
directive|define
name|__REG_OSPREY_REG_MAP_H__
end_define

begin_include
include|#
directive|include
file|"osprey_reg_map_macro.h"
end_include

begin_include
include|#
directive|include
file|"poseidon_reg_map_macro.h"
end_include

begin_struct
struct|struct
name|mac_dma_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*        0x0 - 0x8        */
specifier|volatile
name|u_int32_t
name|MAC_DMA_CR
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*        0xc - 0x14       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_CFG
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_RXBUFPTR_THRESH
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TXDPPTR_THRESH
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_MIRT
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_GLOBAL_IER
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TIMT
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_RIMT
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TXCFG
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_RXCFG
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_RXJLA
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_MIBC
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TOPS
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_RXNPTO
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TXNPTO
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_RPGTO
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_MACMISC
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_INTER
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_DATABUF
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_GTT
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_GTTM
decl_stmt|;
comment|/*       0x68 - 0x6c       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_CST
decl_stmt|;
comment|/*       0x6c - 0x70       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_RXDP_SIZE
decl_stmt|;
comment|/*       0x70 - 0x74       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_RX_QUEUE_HP_RXDP
decl_stmt|;
comment|/*       0x74 - 0x78       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_RX_QUEUE_LP_RXDP
decl_stmt|;
comment|/*       0x78 - 0x7c       */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x7c - 0x80       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_P
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S0
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S1
decl_stmt|;
comment|/*       0x88 - 0x8c       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S2
decl_stmt|;
comment|/*       0x8c - 0x90       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S3
decl_stmt|;
comment|/*       0x90 - 0x94       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S4
decl_stmt|;
comment|/*       0x94 - 0x98       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S5
decl_stmt|;
comment|/*       0x98 - 0x9c       */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S6
decl_stmt|;
comment|/*       0x9c - 0xa0       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_IMR_P
decl_stmt|;
comment|/*       0xa0 - 0xa4       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_IMR_S0
decl_stmt|;
comment|/*       0xa4 - 0xa8       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_IMR_S1
decl_stmt|;
comment|/*       0xa8 - 0xac       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_IMR_S2
decl_stmt|;
comment|/*       0xac - 0xb0       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_IMR_S3
decl_stmt|;
comment|/*       0xb0 - 0xb4       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_IMR_S4
decl_stmt|;
comment|/*       0xb4 - 0xb8       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_IMR_S5
decl_stmt|;
comment|/*       0xb8 - 0xbc       */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_DMA_IMR_S6
decl_stmt|;
comment|/*       0xbc - 0xc0       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_P_RAC
decl_stmt|;
comment|/*       0xc0 - 0xc4       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S0_S
decl_stmt|;
comment|/*       0xc4 - 0xc8       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S1_S
decl_stmt|;
comment|/*       0xc8 - 0xcc       */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S6_S
decl_stmt|;
comment|/*       0xcc - 0xd0       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S2_S
decl_stmt|;
comment|/*       0xd0 - 0xd4       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S3_S
decl_stmt|;
comment|/*       0xd4 - 0xd8       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S4_S
decl_stmt|;
comment|/*       0xd8 - 0xdc       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_ISR_S5_S
decl_stmt|;
comment|/*       0xdc - 0xe0       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_DMADBG_0
decl_stmt|;
comment|/*       0xe0 - 0xe4       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_DMADBG_1
decl_stmt|;
comment|/*       0xe4 - 0xe8       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_DMADBG_2
decl_stmt|;
comment|/*       0xe8 - 0xec       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_DMADBG_3
decl_stmt|;
comment|/*       0xec - 0xf0       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_DMADBG_4
decl_stmt|;
comment|/*       0xf0 - 0xf4       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_DMADBG_5
decl_stmt|;
comment|/*       0xf4 - 0xf8       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_DMADBG_6
decl_stmt|;
comment|/*       0xf8 - 0xfc       */
specifier|volatile
name|u_int32_t
name|MAC_DMA_DMADBG_7
decl_stmt|;
comment|/*       0xfc - 0x100      */
specifier|volatile
name|u_int32_t
name|MAC_DMA_QCU_TXDP_REMAINING_QCU_7_0
decl_stmt|;
comment|/*      0x100 - 0x104      */
specifier|volatile
name|u_int32_t
name|MAC_DMA_QCU_TXDP_REMAINING_QCU_9_8
decl_stmt|;
comment|/*      0x104 - 0x108      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mac_qcu_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x800
index|]
decl_stmt|;
comment|/*        0x0 - 0x800      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_TXDP
index|[
literal|10
index|]
decl_stmt|;
comment|/*      0x800 - 0x828      */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*      0x828 - 0x830      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_STATUS_RING_START
decl_stmt|;
comment|/*      0x830 - 0x834      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_STATUS_RING_END
decl_stmt|;
comment|/*      0x834 - 0x838      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_STATUS_RING_CURRENT
decl_stmt|;
comment|/*      0x838 - 0x83c      */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x83c - 0x840      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_TXE
decl_stmt|;
comment|/*      0x840 - 0x844      */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x844 - 0x880      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_TXD
decl_stmt|;
comment|/*      0x880 - 0x884      */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x884 - 0x8c0      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_CBR
index|[
literal|10
index|]
decl_stmt|;
comment|/*      0x8c0 - 0x8e8      */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x18
index|]
decl_stmt|;
comment|/*      0x8e8 - 0x900      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_RDYTIME
index|[
literal|10
index|]
decl_stmt|;
comment|/*      0x900 - 0x928      */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x18
index|]
decl_stmt|;
comment|/*      0x928 - 0x940      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_ONESHOT_ARM_SC
decl_stmt|;
comment|/*      0x940 - 0x944      */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x944 - 0x980      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_ONESHOT_ARM_CC
decl_stmt|;
comment|/*      0x980 - 0x984      */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x984 - 0x9c0      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_MISC
index|[
literal|10
index|]
decl_stmt|;
comment|/*      0x9c0 - 0x9e8      */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x18
index|]
decl_stmt|;
comment|/*      0x9e8 - 0xa00      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_CNT
index|[
literal|10
index|]
decl_stmt|;
comment|/*      0xa00 - 0xa28      */
specifier|volatile
name|char
name|pad__10
index|[
literal|0x18
index|]
decl_stmt|;
comment|/*      0xa28 - 0xa40      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_RDYTIME_SHDN
decl_stmt|;
comment|/*      0xa40 - 0xa44      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_DESC_CRC_CHK
decl_stmt|;
comment|/*      0xa44 - 0xa48      */
comment|/* Jupiter_20 */
specifier|volatile
name|u_int32_t
name|MAC_QCU_EOL
decl_stmt|;
comment|/*      0xa48 - 0xa4c      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mac_dcu_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x1000
index|]
decl_stmt|;
comment|/*        0x0 - 0x1000     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_QCUMASK
index|[
literal|10
index|]
decl_stmt|;
comment|/*     0x1000 - 0x1028     */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*     0x1028 - 0x1030     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_GBL_IFS_SIFS
decl_stmt|;
comment|/*     0x1030 - 0x1034     */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x1034 - 0x1038     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU0_31_0
decl_stmt|;
comment|/*     0x1038 - 0x103c     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU8_31_0
decl_stmt|;
comment|/*     0x103c - 0x1040     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_LCL_IFS
index|[
literal|10
index|]
decl_stmt|;
comment|/*     0x1040 - 0x1068     */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*     0x1068 - 0x1070     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_GBL_IFS_SLOT
decl_stmt|;
comment|/*     0x1070 - 0x1074     */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x1074 - 0x1078     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU0_63_32
decl_stmt|;
comment|/*     0x1078 - 0x107c     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU8_63_32
decl_stmt|;
comment|/*     0x107c - 0x1080     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_RETRY_LIMIT
index|[
literal|10
index|]
decl_stmt|;
comment|/*     0x1080 - 0x10a8     */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*     0x10a8 - 0x10b0     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_GBL_IFS_EIFS
decl_stmt|;
comment|/*     0x10b0 - 0x10b4     */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x10b4 - 0x10b8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU0_95_64
decl_stmt|;
comment|/*     0x10b8 - 0x10bc     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU8_95_64
decl_stmt|;
comment|/*     0x10bc - 0x10c0     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_CHANNEL_TIME
index|[
literal|10
index|]
decl_stmt|;
comment|/*     0x10c0 - 0x10e8     */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*     0x10e8 - 0x10f0     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_GBL_IFS_MISC
decl_stmt|;
comment|/*     0x10f0 - 0x10f4     */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x10f4 - 0x10f8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU0_127_96
decl_stmt|;
comment|/*     0x10f8 - 0x10fc     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU8_127_96
decl_stmt|;
comment|/*     0x10fc - 0x1100     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_MISC
index|[
literal|10
index|]
decl_stmt|;
comment|/*     0x1100 - 0x1128     */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*     0x1128 - 0x1138     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU1_31_0
decl_stmt|;
comment|/*     0x1138 - 0x113c     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU9_31_0
decl_stmt|;
comment|/*     0x113c - 0x1140     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_SEQ
decl_stmt|;
comment|/*     0x1140 - 0x1144     */
specifier|volatile
name|char
name|pad__10
index|[
literal|0x34
index|]
decl_stmt|;
comment|/*     0x1144 - 0x1178     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU1_63_32
decl_stmt|;
comment|/*     0x1178 - 0x117c     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU9_63_32
decl_stmt|;
comment|/*     0x117c - 0x1180     */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*     0x1180 - 0x11b8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU1_95_64
decl_stmt|;
comment|/*     0x11b8 - 0x11bc     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU9_95_64
decl_stmt|;
comment|/*     0x11bc - 0x11c0     */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*     0x11c0 - 0x11f8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU1_127_96
decl_stmt|;
comment|/*     0x11f8 - 0x11fc     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU9_127_96
decl_stmt|;
comment|/*     0x11fc - 0x1200     */
specifier|volatile
name|char
name|pad__13
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*     0x1200 - 0x1238     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU2_31_0
decl_stmt|;
comment|/*     0x1238 - 0x123c     */
specifier|volatile
name|char
name|pad__14
index|[
literal|0x34
index|]
decl_stmt|;
comment|/*     0x123c - 0x1270     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_PAUSE
decl_stmt|;
comment|/*     0x1270 - 0x1274     */
specifier|volatile
name|char
name|pad__15
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x1274 - 0x1278     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU2_63_32
decl_stmt|;
comment|/*     0x1278 - 0x127c     */
specifier|volatile
name|char
name|pad__16
index|[
literal|0x34
index|]
decl_stmt|;
comment|/*     0x127c - 0x12b0     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_WOW_KACFG
decl_stmt|;
comment|/*     0x12b0 - 0x12b4     */
specifier|volatile
name|char
name|pad__17
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x12b4 - 0x12b8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU2_95_64
decl_stmt|;
comment|/*     0x12b8 - 0x12bc     */
specifier|volatile
name|char
name|pad__18
index|[
literal|0x34
index|]
decl_stmt|;
comment|/*     0x12bc - 0x12f0     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXSLOT
decl_stmt|;
comment|/*     0x12f0 - 0x12f4     */
specifier|volatile
name|char
name|pad__19
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x12f4 - 0x12f8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU2_127_96
decl_stmt|;
comment|/*     0x12f8 - 0x12fc     */
specifier|volatile
name|char
name|pad__20
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x12fc - 0x1338     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU3_31_0
decl_stmt|;
comment|/*     0x1338 - 0x133c     */
specifier|volatile
name|char
name|pad__21
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x133c - 0x1378     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU3_63_32
decl_stmt|;
comment|/*     0x1378 - 0x137c     */
specifier|volatile
name|char
name|pad__22
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x137c - 0x13b8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU3_95_64
decl_stmt|;
comment|/*     0x13b8 - 0x13bc     */
specifier|volatile
name|char
name|pad__23
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x13bc - 0x13f8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU3_127_96
decl_stmt|;
comment|/*     0x13f8 - 0x13fc     */
specifier|volatile
name|char
name|pad__24
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x13fc - 0x1438     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU4_31_0
decl_stmt|;
comment|/*     0x1438 - 0x143c     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_CLEAR
decl_stmt|;
comment|/*     0x143c - 0x1440     */
specifier|volatile
name|char
name|pad__25
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*     0x1440 - 0x1478     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU4_63_32
decl_stmt|;
comment|/*     0x1478 - 0x147c     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_SET
decl_stmt|;
comment|/*     0x147c - 0x1480     */
specifier|volatile
name|char
name|pad__26
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*     0x1480 - 0x14b8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU4_95_64
decl_stmt|;
comment|/*     0x14b8 - 0x14bc     */
specifier|volatile
name|char
name|pad__27
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x14bc - 0x14f8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU4_127_96
decl_stmt|;
comment|/*     0x14f8 - 0x14fc     */
specifier|volatile
name|char
name|pad__28
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x14fc - 0x1538     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU5_31_0
decl_stmt|;
comment|/*     0x1538 - 0x153c     */
specifier|volatile
name|char
name|pad__29
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x153c - 0x1578     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU5_63_32
decl_stmt|;
comment|/*     0x1578 - 0x157c     */
specifier|volatile
name|char
name|pad__30
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x157c - 0x15b8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU5_95_64
decl_stmt|;
comment|/*     0x15b8 - 0x15bc     */
specifier|volatile
name|char
name|pad__31
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x15bc - 0x15f8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU5_127_96
decl_stmt|;
comment|/*     0x15f8 - 0x15fc     */
specifier|volatile
name|char
name|pad__32
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x15fc - 0x1638     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU6_31_0
decl_stmt|;
comment|/*     0x1638 - 0x163c     */
specifier|volatile
name|char
name|pad__33
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x163c - 0x1678     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU6_63_32
decl_stmt|;
comment|/*     0x1678 - 0x167c     */
specifier|volatile
name|char
name|pad__34
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x167c - 0x16b8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU6_95_64
decl_stmt|;
comment|/*     0x16b8 - 0x16bc     */
specifier|volatile
name|char
name|pad__35
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x16bc - 0x16f8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU6_127_96
decl_stmt|;
comment|/*     0x16f8 - 0x16fc     */
specifier|volatile
name|char
name|pad__36
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x16fc - 0x1738     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU7_31_0
decl_stmt|;
comment|/*     0x1738 - 0x173c     */
specifier|volatile
name|char
name|pad__37
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x173c - 0x1778     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU7_63_32
decl_stmt|;
comment|/*     0x1778 - 0x177c     */
specifier|volatile
name|char
name|pad__38
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x177c - 0x17b8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU7_95_64
decl_stmt|;
comment|/*     0x17b8 - 0x17bc     */
specifier|volatile
name|char
name|pad__39
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*     0x17bc - 0x17f8     */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU7_127_96
decl_stmt|;
comment|/*     0x17f8 - 0x17fc     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|host_intf_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x4000
index|]
decl_stmt|;
comment|/*        0x0 - 0x4000     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_RESET_CONTROL
decl_stmt|;
comment|/*     0x4000 - 0x4004     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_WORK_AROUND
decl_stmt|;
comment|/*     0x4004 - 0x4008     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_PM_STATE
decl_stmt|;
comment|/*     0x4008 - 0x400c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_CXPL_DEBUG_INFOL
decl_stmt|;
comment|/*     0x400c - 0x4010     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_CXPL_DEBUG_INFOH
decl_stmt|;
comment|/*     0x4010 - 0x4014     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_PM_CTRL
decl_stmt|;
comment|/*     0x4014 - 0x4018     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_TIMEOUT
decl_stmt|;
comment|/*     0x4018 - 0x401c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_EEPROM_CTRL
decl_stmt|;
comment|/*     0x401c - 0x4020     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_SREV
decl_stmt|;
comment|/*     0x4020 - 0x4024     */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x4024 - 0x4028     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_SYNC_CAUSE
decl_stmt|;
comment|/*     0x4028 - 0x402c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_SYNC_ENABLE
decl_stmt|;
comment|/*     0x402c - 0x4030     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_ASYNC_MASK
decl_stmt|;
comment|/*     0x4030 - 0x4034     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_SYNC_MASK
decl_stmt|;
comment|/*     0x4034 - 0x4038     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_ASYNC_CAUSE
decl_stmt|;
comment|/*     0x4038 - 0x403c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_ASYNC_ENABLE
decl_stmt|;
comment|/*     0x403c - 0x4040     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_PCIE_PHY_RW
decl_stmt|;
comment|/*     0x4040 - 0x4044     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_PCIE_PHY_LOAD
decl_stmt|;
comment|/*     0x4044 - 0x4048     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OUT
decl_stmt|;
comment|/*     0x4048 - 0x404c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_IN
decl_stmt|;
comment|/*     0x404c - 0x4050     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OE
decl_stmt|;
comment|/*     0x4050 - 0x4054     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OE1
decl_stmt|;
comment|/*     0x4054 - 0x4058     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_INTR_POLAR
decl_stmt|;
comment|/*     0x4058 - 0x405c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_INPUT_VALUE
decl_stmt|;
comment|/*     0x405c - 0x4060     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_INPUT_MUX1
decl_stmt|;
comment|/*     0x4060 - 0x4064     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_INPUT_MUX2
decl_stmt|;
comment|/*     0x4064 - 0x4068     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OUTPUT_MUX1
decl_stmt|;
comment|/*     0x4068 - 0x406c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OUTPUT_MUX2
decl_stmt|;
comment|/*     0x406c - 0x4070     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_OUTPUT_MUX3
decl_stmt|;
comment|/*     0x4070 - 0x4074     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_INPUT_STATE
decl_stmt|;
comment|/*     0x4074 - 0x4078     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_SPARE
decl_stmt|;
comment|/*     0x4078 - 0x407c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_PCIE_CORE_RST_EN
decl_stmt|;
comment|/*     0x407c - 0x4080     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_CLKRUN
decl_stmt|;
comment|/*     0x4080 - 0x4084     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_EEPROM_STS
decl_stmt|;
comment|/*     0x4084 - 0x4088     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_OBS_CTRL
decl_stmt|;
comment|/*     0x4088 - 0x408c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_RFSILENT
decl_stmt|;
comment|/*     0x408c - 0x4090     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_PDPU
decl_stmt|;
comment|/*     0x4090 - 0x4094     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_PDPU1
decl_stmt|;
comment|/*     0x4094 - 0x4098     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_DS
decl_stmt|;
comment|/*     0x4098 - 0x409c     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_GPIO_DS1
decl_stmt|;
comment|/*     0x409c - 0x40a0     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_MISC
decl_stmt|;
comment|/*     0x40a0 - 0x40a4     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_PCIE_MSI
decl_stmt|;
comment|/*     0x40a4 - 0x40a8     */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*     0x40a8 - 0x40b0     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_PCIE_PHY_LATENCY_NFTS_ADJ
decl_stmt|;
comment|/*     0x40b0 - 0x40b4     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_MAC_TDMA_CCA_CNTL
decl_stmt|;
comment|/*     0x40b4 - 0x40b8     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_MAC_TXAPSYNC
decl_stmt|;
comment|/*     0x40b8 - 0x40bc     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_MAC_TXSYNC_INITIAL_SYNC_TMR
decl_stmt|;
comment|/*     0x40bc - 0x40c0     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_SYNC_CAUSE
decl_stmt|;
comment|/*     0x40c0 - 0x40c4     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_SYNC_ENABLE
decl_stmt|;
comment|/*     0x40c4 - 0x40c8     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_ASYNC_MASK
decl_stmt|;
comment|/*     0x40c8 - 0x40cc     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_SYNC_MASK
decl_stmt|;
comment|/*     0x40cc - 0x40d0     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_ASYNC_CAUSE
decl_stmt|;
comment|/*     0x40d0 - 0x40d4     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_INTR_PRIORITY_ASYNC_ENABLE
decl_stmt|;
comment|/*     0x40d4 - 0x40d8     */
specifier|volatile
name|u_int32_t
name|HOST_INTF_OTP
decl_stmt|;
comment|/*     0x40d8 - 0x40dc     */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x40dc - 0x40e0     */
specifier|volatile
name|u_int32_t
name|PCIE_CO_ERR_CTR0
decl_stmt|;
comment|/*     0x40e0 - 0x40e4     */
specifier|volatile
name|u_int32_t
name|PCIE_CO_ERR_CTR1
decl_stmt|;
comment|/*     0x40e4 - 0x40e8     */
specifier|volatile
name|u_int32_t
name|PCIE_CO_ERR_CTR_CTRL
decl_stmt|;
comment|/*     0x40e8 - 0x40ec     */
comment|/* Poseidon, Jupiter */
specifier|volatile
name|u_int32_t
name|AXI_INTERCONNECT_CTRL
decl_stmt|;
comment|/*     0x40ec - 0x40f0     */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|PCIE_AXI_BRIDGE_CTRL
decl_stmt|;
comment|/*     0x40f0 - 0x40f4     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|emulation_misc_regs
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x4f00
index|]
decl_stmt|;
comment|/*        0x0 - 0x4f00     */
specifier|volatile
name|u_int32_t
name|FPGA_PHY_LAYER_REVID
decl_stmt|;
comment|/*     0x4f00 - 0x4f04     */
specifier|volatile
name|u_int32_t
name|FPGA_LINK_LAYER_REVID
decl_stmt|;
comment|/*     0x4f04 - 0x4f08     */
specifier|volatile
name|u_int32_t
name|FPGA_REG1
decl_stmt|;
comment|/*     0x4f08 - 0x4f0c     */
specifier|volatile
name|u_int32_t
name|FPGA_REG2
decl_stmt|;
comment|/*     0x4f0c - 0x4f10     */
specifier|volatile
name|u_int32_t
name|FPGA_REG3
decl_stmt|;
comment|/*     0x4f10 - 0x4f14     */
specifier|volatile
name|u_int32_t
name|FPGA_REG4
decl_stmt|;
comment|/*     0x4f14 - 0x4f18     */
specifier|volatile
name|u_int32_t
name|FPGA_REG5
decl_stmt|;
comment|/*     0x4f18 - 0x4f1c     */
specifier|volatile
name|u_int32_t
name|FPGA_REG6
decl_stmt|;
comment|/*     0x4f1c - 0x4f20     */
specifier|volatile
name|u_int32_t
name|FPGA_REG7
decl_stmt|;
comment|/*     0x4f20 - 0x4f24     */
specifier|volatile
name|u_int32_t
name|FPGA_REG8
decl_stmt|;
comment|/*     0x4f24 - 0x4f28     */
specifier|volatile
name|u_int32_t
name|FPGA_REG9
decl_stmt|;
comment|/*     0x4f28 - 0x4f2c     */
specifier|volatile
name|u_int32_t
name|FPGA_REG10
decl_stmt|;
comment|/*     0x4f2c - 0x4f30     */
comment|/* Aphrodite-start */
specifier|volatile
name|u_int32_t
name|FPGA_REG11
decl_stmt|;
comment|/*     0x4f30 - 0x4f34     */
specifier|volatile
name|u_int32_t
name|FPGA_REG12
decl_stmt|;
comment|/*     0x4f34 - 0x4f38     */
specifier|volatile
name|u_int32_t
name|FPGA_REG13
decl_stmt|;
comment|/*     0x4f38 - 0x4f3c     */
specifier|volatile
name|u_int32_t
name|FPGA_REG14
decl_stmt|;
comment|/*     0x4f3c - 0x4f40     */
comment|/* Aphrodite-end */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_0
block|{
specifier|volatile
name|u_int32_t
name|ID
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|STS_CMD_RGSTR
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|CLS_REV_ID
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|BIST_HEAD_LAT_CACH
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|BAS_ADR_0
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|BAS_ADR_1
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|BAS_ADR_2
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|BAS_ADR_3
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|BAS_ADR_4
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|BAS_ADR_5
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|CRD_CIS_PTR
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|Sub_VenID
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|EXP_ROM_ADDR
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|CAPPTR
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|RESERVE2
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|LAT_INT
decl_stmt|;
comment|/*       0x3c - 0x40       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_1
block|{
specifier|volatile
name|u_int32_t
name|CFG_PWR_CAP
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|PWR_CSR
decl_stmt|;
comment|/*        0x4 - 0x8        */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_2
block|{
specifier|volatile
name|u_int32_t
name|MSG_CTR
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|MSI_L32
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|MSI_U32
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|MSI_DATA
decl_stmt|;
comment|/*        0xc - 0x10       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_3
block|{
specifier|volatile
name|u_int32_t
name|PCIE_CAP
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|DEV_CAP
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|DEV_STS_CTRL
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|LNK_CAP
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|LNK_STS_CTRL
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|SLT_CAP
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|SLT_STS_CTRL
decl_stmt|;
comment|/*       0x18 - 0x1c       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_5
block|{
specifier|volatile
name|u_int32_t
name|VPD_CAP
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|VPD_DATA
decl_stmt|;
comment|/*        0x4 - 0x8        */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_6
block|{
specifier|volatile
name|u_int32_t
name|PCIE_EN_CAP_AER
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|UN_ERR_ST_R
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|UN_ERR_MS_R
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|UN_ERR_SV_R
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|CO_ERR_ST_R
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|CO_ERR_MS_R
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|ADERR_CAP_CR
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|HD_L_R0
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|HD_L_R4
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|HD_L_R8
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|HD_L_R12
decl_stmt|;
comment|/*       0x28 - 0x2c       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_7
block|{
specifier|volatile
name|u_int32_t
name|PCIE_EN_CAP_VC
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|PVC_CAP_R1
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|P_CAP_R2
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|PVC_STS_CTRL
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|VC_CAP_R
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|VC_CTL_R
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|VC_STS_RSV
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|VCR_CAP_R1
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|VCR_CTRL_R1
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|VCR_STS_R1
decl_stmt|;
comment|/*       0x24 - 0x28       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_7_Jupiter
block|{
specifier|volatile
name|u_int32_t
name|PCIE_EN_CAP_VC
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|PVC_CAP_R1
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|P_CAP_R2
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|PVC_STS_CTRL
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|VC_CAP_R
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|VC_CTL_R
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|VC_STS_RSV
decl_stmt|;
comment|/*       0x18 - 0x1c       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_8
block|{
specifier|volatile
name|u_int32_t
name|DEV_EN_CAP
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|SN_R1
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|SN_R2
decl_stmt|;
comment|/*        0x8 - 0xc        */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_9
block|{
specifier|volatile
name|u_int32_t
name|LAT_REL_TIM
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|OT_MSG_R
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|PT_LNK_R
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|ACk_FREQ_R
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|PT_LNK_CTRL_R
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|LN_SKW_R
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|SYMB_N_R
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|SYMB_T_R
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|FL_MSK_R2
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|DB_R0
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|DB_R1
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|TR_P_STS_R
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|TR_NP_STS_R
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|TR_C_STS_R
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|Q_STS_R
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|VC_TR_A_R1
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|VC_TR_A_R2
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|VC0_PR_Q_C
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|VC0_NPR_Q_C
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|VC0_CR_Q_C
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|VC1_PR_Q_C
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|u_int32_t
name|VC1_NPR_Q_C
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|VC1_CR_Q_C
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|VC2_PR_Q_C
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|VC2_NPR_Q_C
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|u_int32_t
name|VC2_CR_Q_C
decl_stmt|;
comment|/*       0x68 - 0x6c       */
specifier|volatile
name|u_int32_t
name|VC3_PR_Q_C
decl_stmt|;
comment|/*       0x6c - 0x70       */
specifier|volatile
name|u_int32_t
name|VC3_NPR_Q_C
decl_stmt|;
comment|/*       0x70 - 0x74       */
specifier|volatile
name|u_int32_t
name|VC3_CR_Q_C
decl_stmt|;
comment|/*       0x74 - 0x78       */
specifier|volatile
name|u_int32_t
name|VC4_PR_Q_C
decl_stmt|;
comment|/*       0x78 - 0x7c       */
specifier|volatile
name|u_int32_t
name|VC4_NPR_Q_C
decl_stmt|;
comment|/*       0x7c - 0x80       */
specifier|volatile
name|u_int32_t
name|VC4_CR_Q_C
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|VC5_PR_Q_C
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|u_int32_t
name|VC5_NPR_Q_C
decl_stmt|;
comment|/*       0x88 - 0x8c       */
specifier|volatile
name|u_int32_t
name|VC5_CR_Q_C
decl_stmt|;
comment|/*       0x8c - 0x90       */
specifier|volatile
name|u_int32_t
name|VC6_PR_Q_C
decl_stmt|;
comment|/*       0x90 - 0x94       */
specifier|volatile
name|u_int32_t
name|VC6_NPR_Q_C
decl_stmt|;
comment|/*       0x94 - 0x98       */
specifier|volatile
name|u_int32_t
name|VC6_CR_Q_C
decl_stmt|;
comment|/*       0x98 - 0x9c       */
specifier|volatile
name|u_int32_t
name|VC7_PR_Q_C
decl_stmt|;
comment|/*       0x9c - 0xa0       */
specifier|volatile
name|u_int32_t
name|VC7_NPR_Q_C
decl_stmt|;
comment|/*       0xa0 - 0xa4       */
specifier|volatile
name|u_int32_t
name|VC7_CR_Q_C
decl_stmt|;
comment|/*       0xa4 - 0xa8       */
specifier|volatile
name|u_int32_t
name|VC0_PB_D
decl_stmt|;
comment|/*       0xa8 - 0xac       */
specifier|volatile
name|u_int32_t
name|VC0_NPB_D
decl_stmt|;
comment|/*       0xac - 0xb0       */
specifier|volatile
name|u_int32_t
name|VC0_CB_D
decl_stmt|;
comment|/*       0xb0 - 0xb4       */
specifier|volatile
name|u_int32_t
name|VC1_PB_D
decl_stmt|;
comment|/*       0xb4 - 0xb8       */
specifier|volatile
name|u_int32_t
name|VC1_NPB_D
decl_stmt|;
comment|/*       0xb8 - 0xbc       */
specifier|volatile
name|u_int32_t
name|VC1_CB_D
decl_stmt|;
comment|/*       0xbc - 0xc0       */
specifier|volatile
name|u_int32_t
name|VC2_PB_D
decl_stmt|;
comment|/*       0xc0 - 0xc4       */
specifier|volatile
name|u_int32_t
name|VC2_NPB_D
decl_stmt|;
comment|/*       0xc4 - 0xc8       */
specifier|volatile
name|u_int32_t
name|VC2_CB_D
decl_stmt|;
comment|/*       0xc8 - 0xcc       */
specifier|volatile
name|u_int32_t
name|VC3_PB_D
decl_stmt|;
comment|/*       0xcc - 0xd0       */
specifier|volatile
name|u_int32_t
name|VC3_NPB_D
decl_stmt|;
comment|/*       0xd0 - 0xd4       */
specifier|volatile
name|u_int32_t
name|VC3_CB_D
decl_stmt|;
comment|/*       0xd4 - 0xd8       */
specifier|volatile
name|u_int32_t
name|VC4_PB_D
decl_stmt|;
comment|/*       0xd8 - 0xdc       */
specifier|volatile
name|u_int32_t
name|VC4_NPB_D
decl_stmt|;
comment|/*       0xdc - 0xe0       */
specifier|volatile
name|u_int32_t
name|VC4_CB_D
decl_stmt|;
comment|/*       0xe0 - 0xe4       */
specifier|volatile
name|u_int32_t
name|VC5_PB_D
decl_stmt|;
comment|/*       0xe4 - 0xe8       */
specifier|volatile
name|u_int32_t
name|VC5_NPB_D
decl_stmt|;
comment|/*       0xe8 - 0xec       */
specifier|volatile
name|u_int32_t
name|VC5_CB_D
decl_stmt|;
comment|/*       0xec - 0xf0       */
specifier|volatile
name|u_int32_t
name|VC6_PB_D
decl_stmt|;
comment|/*       0xf0 - 0xf4       */
specifier|volatile
name|u_int32_t
name|VC6_NPB_D
decl_stmt|;
comment|/*       0xf4 - 0xf8       */
specifier|volatile
name|u_int32_t
name|VC6_CB_D
decl_stmt|;
comment|/*       0xf8 - 0xfc       */
specifier|volatile
name|u_int32_t
name|VC7_PB_D
decl_stmt|;
comment|/*       0xfc - 0x100      */
specifier|volatile
name|u_int32_t
name|VC7_NPB_D
decl_stmt|;
comment|/*      0x100 - 0x104      */
specifier|volatile
name|u_int32_t
name|VC7_CB_D
decl_stmt|;
comment|/*      0x104 - 0x108      */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x108 - 0x10c      */
specifier|volatile
name|u_int32_t
name|GEN2
decl_stmt|;
comment|/*      0x10c - 0x110      */
specifier|volatile
name|u_int32_t
name|PHY_STS_R
decl_stmt|;
comment|/*      0x110 - 0x114      */
specifier|volatile
name|u_int32_t
name|PHY_CTRL_R
decl_stmt|;
comment|/*      0x114 - 0x118      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|DWC_pcie_dbi_axi
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x5000
index|]
decl_stmt|;
comment|/*        0x0 - 0x5000     */
name|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_0
name|DWC_pcie_dbi_axi_0
decl_stmt|;
comment|/*     0x5000 - 0x5040     */
name|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_1
name|DWC_pcie_dbi_axi_1
decl_stmt|;
comment|/*     0x5040 - 0x5048     */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*     0x5048 - 0x5050     */
name|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_2
name|DWC_pcie_dbi_axi_2
decl_stmt|;
comment|/*     0x5050 - 0x5060     */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*     0x5060 - 0x5070     */
name|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_3
name|DWC_pcie_dbi_axi_3
decl_stmt|;
comment|/*     0x5070 - 0x508c     */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x44
index|]
decl_stmt|;
comment|/*     0x508c - 0x50d0     */
name|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_5
name|DWC_pcie_dbi_axi_5
decl_stmt|;
comment|/*     0x50d0 - 0x50d8     */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x28
index|]
decl_stmt|;
comment|/*     0x50d8 - 0x5100     */
name|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_6
name|DWC_pcie_dbi_axi_6
decl_stmt|;
comment|/*     0x5100 - 0x512c     */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x14
index|]
decl_stmt|;
comment|/*     0x512c - 0x5140     */
union|union
block|{
struct|struct
block|{
name|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_7
name|DWC_pcie_dbi_axi_7
decl_stmt|;
comment|/*     0x5140 - 0x5168     */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x198
index|]
decl_stmt|;
comment|/*     0x5168 - 0x5300     */
name|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_8
name|DWC_pcie_dbi_axi_8
decl_stmt|;
comment|/*     0x5300 - 0x530c     */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x3f4
index|]
decl_stmt|;
comment|/*     0x530c - 0x5700     */
block|}
name|Osprey
struct|;
struct|struct
name|pcie_dbi_axi
block|{
name|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_7_Jupiter
name|DWC_pcie_dbi_axi_7
decl_stmt|;
comment|/*     0x5140 - 0x515c     */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x515c - 0x5160     */
name|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_8
name|DWC_pcie_dbi_axi_8
decl_stmt|;
comment|/*     0x5160 - 0x516c     */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x594
index|]
decl_stmt|;
comment|/*     0x516c - 0x5700     */
block|}
name|Jupiter
struct|;
block|}
name|overlay_0x5140
union|;
comment|/*     0x5140 - 0x5700     */
name|struct
name|DWC_pcie_dbi_axi__DWC_pcie_dbi_axi_9
name|DWC_pcie_dbi_axi_9
decl_stmt|;
comment|/*     0x5700 - 0x5818     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rtc_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x7000
index|]
decl_stmt|;
comment|/*        0x0 - 0x7000     */
specifier|volatile
name|u_int32_t
name|RESET_CONTROL
decl_stmt|;
comment|/*     0x7000 - 0x7004     */
specifier|volatile
name|u_int32_t
name|XTAL_CONTROL
decl_stmt|;
comment|/*     0x7004 - 0x7008     */
specifier|volatile
name|u_int32_t
name|REG_CONTROL0
decl_stmt|;
comment|/*     0x7008 - 0x700c     */
specifier|volatile
name|u_int32_t
name|REG_CONTROL1
decl_stmt|;
comment|/*     0x700c - 0x7010     */
specifier|volatile
name|u_int32_t
name|QUADRATURE
decl_stmt|;
comment|/*     0x7010 - 0x7014     */
specifier|volatile
name|u_int32_t
name|PLL_CONTROL
decl_stmt|;
comment|/*     0x7014 - 0x7018     */
specifier|volatile
name|u_int32_t
name|PLL_SETTLE
decl_stmt|;
comment|/*     0x7018 - 0x701c     */
specifier|volatile
name|u_int32_t
name|XTAL_SETTLE
decl_stmt|;
comment|/*     0x701c - 0x7020     */
specifier|volatile
name|u_int32_t
name|CLOCK_OUT
decl_stmt|;
comment|/*     0x7020 - 0x7024     */
specifier|volatile
name|u_int32_t
name|BIAS_OVERRIDE
decl_stmt|;
comment|/*     0x7024 - 0x7028     */
specifier|volatile
name|u_int32_t
name|RESET_CAUSE
decl_stmt|;
comment|/*     0x7028 - 0x702c     */
specifier|volatile
name|u_int32_t
name|SYSTEM_SLEEP
decl_stmt|;
comment|/*     0x702c - 0x7030     */
specifier|volatile
name|u_int32_t
name|MAC_SLEEP_CONTROL
decl_stmt|;
comment|/*     0x7030 - 0x7034     */
specifier|volatile
name|u_int32_t
name|KEEP_AWAKE
decl_stmt|;
comment|/*     0x7034 - 0x7038     */
specifier|volatile
name|u_int32_t
name|DERIVED_RTC_CLK
decl_stmt|;
comment|/*     0x7038 - 0x703c     */
specifier|volatile
name|u_int32_t
name|PLL_CONTROL2
decl_stmt|;
comment|/*     0x703c - 0x7040     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rtc_sync_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x7040
index|]
decl_stmt|;
comment|/*        0x0 - 0x7040     */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_RESET
decl_stmt|;
comment|/*     0x7040 - 0x7044     */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_STATUS
decl_stmt|;
comment|/*     0x7044 - 0x7048     */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_DERIVED
decl_stmt|;
comment|/*     0x7048 - 0x704c     */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_FORCE_WAKE
decl_stmt|;
comment|/*     0x704c - 0x7050     */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_INTR_CAUSE
decl_stmt|;
comment|/*     0x7050 - 0x7054     */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_INTR_ENABLE
decl_stmt|;
comment|/*     0x7054 - 0x7058     */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_INTR_MASK
decl_stmt|;
comment|/*     0x7058 - 0x705c     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|merlin2_0_radio_reg_map
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x7800
index|]
decl_stmt|;
comment|/*        0x0 - 0x7800     */
specifier|volatile
name|u_int32_t
name|RXTXBB1_CH1
decl_stmt|;
comment|/*     0x7800 - 0x7804     */
specifier|volatile
name|u_int32_t
name|RXTXBB2_CH1
decl_stmt|;
comment|/*     0x7804 - 0x7808     */
specifier|volatile
name|u_int32_t
name|RXTXBB3_CH1
decl_stmt|;
comment|/*     0x7808 - 0x780c     */
specifier|volatile
name|u_int32_t
name|RXTXBB4_CH1
decl_stmt|;
comment|/*     0x780c - 0x7810     */
specifier|volatile
name|u_int32_t
name|RF2G1_CH1
decl_stmt|;
comment|/*     0x7810 - 0x7814     */
specifier|volatile
name|u_int32_t
name|RF2G2_CH1
decl_stmt|;
comment|/*     0x7814 - 0x7818     */
specifier|volatile
name|u_int32_t
name|RF5G1_CH1
decl_stmt|;
comment|/*     0x7818 - 0x781c     */
specifier|volatile
name|u_int32_t
name|RF5G2_CH1
decl_stmt|;
comment|/*     0x781c - 0x7820     */
specifier|volatile
name|u_int32_t
name|RF5G3_CH1
decl_stmt|;
comment|/*     0x7820 - 0x7824     */
specifier|volatile
name|u_int32_t
name|RXTXBB1_CH0
decl_stmt|;
comment|/*     0x7824 - 0x7828     */
specifier|volatile
name|u_int32_t
name|RXTXBB2_CH0
decl_stmt|;
comment|/*     0x7828 - 0x782c     */
specifier|volatile
name|u_int32_t
name|RXTXBB3_CH0
decl_stmt|;
comment|/*     0x782c - 0x7830     */
specifier|volatile
name|u_int32_t
name|RXTXBB4_CH0
decl_stmt|;
comment|/*     0x7830 - 0x7834     */
specifier|volatile
name|u_int32_t
name|RF5G1_CH0
decl_stmt|;
comment|/*     0x7834 - 0x7838     */
specifier|volatile
name|u_int32_t
name|RF5G2_CH0
decl_stmt|;
comment|/*     0x7838 - 0x783c     */
specifier|volatile
name|u_int32_t
name|RF5G3_CH0
decl_stmt|;
comment|/*     0x783c - 0x7840     */
specifier|volatile
name|u_int32_t
name|RF2G1_CH0
decl_stmt|;
comment|/*     0x7840 - 0x7844     */
specifier|volatile
name|u_int32_t
name|RF2G2_CH0
decl_stmt|;
comment|/*     0x7844 - 0x7848     */
specifier|volatile
name|u_int32_t
name|SYNTH1
decl_stmt|;
comment|/*     0x7848 - 0x784c     */
specifier|volatile
name|u_int32_t
name|SYNTH2
decl_stmt|;
comment|/*     0x784c - 0x7850     */
specifier|volatile
name|u_int32_t
name|SYNTH3
decl_stmt|;
comment|/*     0x7850 - 0x7854     */
specifier|volatile
name|u_int32_t
name|SYNTH4
decl_stmt|;
comment|/*     0x7854 - 0x7858     */
specifier|volatile
name|u_int32_t
name|SYNTH5
decl_stmt|;
comment|/*     0x7858 - 0x785c     */
specifier|volatile
name|u_int32_t
name|SYNTH6
decl_stmt|;
comment|/*     0x785c - 0x7860     */
specifier|volatile
name|u_int32_t
name|SYNTH7
decl_stmt|;
comment|/*     0x7860 - 0x7864     */
specifier|volatile
name|u_int32_t
name|SYNTH8
decl_stmt|;
comment|/*     0x7864 - 0x7868     */
specifier|volatile
name|u_int32_t
name|SYNTH9
decl_stmt|;
comment|/*     0x7868 - 0x786c     */
specifier|volatile
name|u_int32_t
name|SYNTH10
decl_stmt|;
comment|/*     0x786c - 0x7870     */
specifier|volatile
name|u_int32_t
name|SYNTH11
decl_stmt|;
comment|/*     0x7870 - 0x7874     */
specifier|volatile
name|u_int32_t
name|BIAS1
decl_stmt|;
comment|/*     0x7874 - 0x7878     */
specifier|volatile
name|u_int32_t
name|BIAS2
decl_stmt|;
comment|/*     0x7878 - 0x787c     */
specifier|volatile
name|u_int32_t
name|BIAS3
decl_stmt|;
comment|/*     0x787c - 0x7880     */
specifier|volatile
name|u_int32_t
name|BIAS4
decl_stmt|;
comment|/*     0x7880 - 0x7884     */
specifier|volatile
name|u_int32_t
name|GAIN0
decl_stmt|;
comment|/*     0x7884 - 0x7888     */
specifier|volatile
name|u_int32_t
name|GAIN1
decl_stmt|;
comment|/*     0x7888 - 0x788c     */
specifier|volatile
name|u_int32_t
name|TOP0
decl_stmt|;
comment|/*     0x788c - 0x7890     */
specifier|volatile
name|u_int32_t
name|TOP1
decl_stmt|;
comment|/*     0x7890 - 0x7894     */
specifier|volatile
name|u_int32_t
name|TOP2
decl_stmt|;
comment|/*     0x7894 - 0x7898     */
specifier|volatile
name|u_int32_t
name|TOP3
decl_stmt|;
comment|/*     0x7898 - 0x789c     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|analog_intf_reg_csr
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x7900
index|]
decl_stmt|;
comment|/*        0x0 - 0x7900     */
specifier|volatile
name|u_int32_t
name|SW_OVERRIDE
decl_stmt|;
comment|/*     0x7900 - 0x7904     */
specifier|volatile
name|u_int32_t
name|SIN_VAL
decl_stmt|;
comment|/*     0x7904 - 0x7908     */
specifier|volatile
name|u_int32_t
name|SW_SCLK
decl_stmt|;
comment|/*     0x7908 - 0x790c     */
specifier|volatile
name|u_int32_t
name|SW_CNTL
decl_stmt|;
comment|/*     0x790c - 0x7910     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mac_pcu_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x8000
index|]
decl_stmt|;
comment|/*        0x0 - 0x8000     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_STA_ADDR_L32
decl_stmt|;
comment|/*     0x8000 - 0x8004     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_STA_ADDR_U16
decl_stmt|;
comment|/*     0x8004 - 0x8008     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BSSID_L32
decl_stmt|;
comment|/*     0x8008 - 0x800c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BSSID_U16
decl_stmt|;
comment|/*     0x800c - 0x8010     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BCN_RSSI_AVE
decl_stmt|;
comment|/*     0x8010 - 0x8014     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_ACK_CTS_TIMEOUT
decl_stmt|;
comment|/*     0x8014 - 0x8018     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BCN_RSSI_CTL
decl_stmt|;
comment|/*     0x8018 - 0x801c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_USEC_LATENCY
decl_stmt|;
comment|/*     0x801c - 0x8020     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RESET_TSF
decl_stmt|;
comment|/*     0x8020 - 0x8024     */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x14
index|]
decl_stmt|;
comment|/*     0x8024 - 0x8038     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MAX_CFP_DUR
decl_stmt|;
comment|/*     0x8038 - 0x803c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RX_FILTER
decl_stmt|;
comment|/*     0x803c - 0x8040     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MCAST_FILTER_L32
decl_stmt|;
comment|/*     0x8040 - 0x8044     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MCAST_FILTER_U32
decl_stmt|;
comment|/*     0x8044 - 0x8048     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_DIAG_SW
decl_stmt|;
comment|/*     0x8048 - 0x804c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TSF_L32
decl_stmt|;
comment|/*     0x804c - 0x8050     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TSF_U32
decl_stmt|;
comment|/*     0x8050 - 0x8054     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TST_ADDAC
decl_stmt|;
comment|/*     0x8054 - 0x8058     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_DEF_ANTENNA
decl_stmt|;
comment|/*     0x8058 - 0x805c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AES_MUTE_MASK_0
decl_stmt|;
comment|/*     0x805c - 0x8060     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AES_MUTE_MASK_1
decl_stmt|;
comment|/*     0x8060 - 0x8064     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_GATED_CLKS
decl_stmt|;
comment|/*     0x8064 - 0x8068     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_OBS_BUS_2
decl_stmt|;
comment|/*     0x8068 - 0x806c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_OBS_BUS_1
decl_stmt|;
comment|/*     0x806c - 0x8070     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_DYM_MIMO_PWR_SAVE
decl_stmt|;
comment|/*     0x8070 - 0x8074     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB
decl_stmt|;
comment|/*     0x8074 - 0x8078     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB
decl_stmt|;
comment|/*     0x8078 - 0x807c     */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x807c - 0x8080     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LAST_BEACON_TSF
decl_stmt|;
comment|/*     0x8080 - 0x8084     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_NAV
decl_stmt|;
comment|/*     0x8084 - 0x8088     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RTS_SUCCESS_CNT
decl_stmt|;
comment|/*     0x8088 - 0x808c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RTS_FAIL_CNT
decl_stmt|;
comment|/*     0x808c - 0x8090     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_ACK_FAIL_CNT
decl_stmt|;
comment|/*     0x8090 - 0x8094     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_FCS_FAIL_CNT
decl_stmt|;
comment|/*     0x8094 - 0x8098     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BEACON_CNT
decl_stmt|;
comment|/*     0x8098 - 0x809c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TDMA_SLOT_ALERT_CNTL
decl_stmt|;
comment|/*     0x809c - 0x80a0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BASIC_SET
decl_stmt|;
comment|/*     0x80a0 - 0x80a4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MGMT_SEQ
decl_stmt|;
comment|/*     0x80a4 - 0x80a8     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BF_RPT1
decl_stmt|;
comment|/*     0x80a8 - 0x80ac     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BF_RPT2
decl_stmt|;
comment|/*     0x80ac - 0x80b0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_ANT_1
decl_stmt|;
comment|/*     0x80b0 - 0x80b4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_ANT_2
decl_stmt|;
comment|/*     0x80b4 - 0x80b8     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_ANT_3
decl_stmt|;
comment|/*     0x80b8 - 0x80bc     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_ANT_4
decl_stmt|;
comment|/*     0x80bc - 0x80c0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRMODE
decl_stmt|;
comment|/*     0x80c0 - 0x80c4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRDEL
decl_stmt|;
comment|/*     0x80c4 - 0x80c8     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRTO
decl_stmt|;
comment|/*     0x80c8 - 0x80cc     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRCRP
decl_stmt|;
comment|/*     0x80cc - 0x80d0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRSTMP
decl_stmt|;
comment|/*     0x80d0 - 0x80d4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP1
decl_stmt|;
comment|/*     0x80d4 - 0x80d8     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP2
decl_stmt|;
comment|/*     0x80d8 - 0x80dc     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SELF_GEN_DEFAULT
decl_stmt|;
comment|/*     0x80dc - 0x80e0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_ADDR1_MASK_L32
decl_stmt|;
comment|/*     0x80e0 - 0x80e4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_ADDR1_MASK_U16
decl_stmt|;
comment|/*     0x80e4 - 0x80e8     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TPC
decl_stmt|;
comment|/*     0x80e8 - 0x80ec     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_FRAME_CNT
decl_stmt|;
comment|/*     0x80ec - 0x80f0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RX_FRAME_CNT
decl_stmt|;
comment|/*     0x80f0 - 0x80f4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RX_CLEAR_CNT
decl_stmt|;
comment|/*     0x80f4 - 0x80f8     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_CYCLE_CNT
decl_stmt|;
comment|/*     0x80f8 - 0x80fc     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_QUIET_TIME_1
decl_stmt|;
comment|/*     0x80fc - 0x8100     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_QUIET_TIME_2
decl_stmt|;
comment|/*     0x8100 - 0x8104     */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x8104 - 0x8108     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_QOS_NO_ACK
decl_stmt|;
comment|/*     0x8108 - 0x810c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERROR_MASK
decl_stmt|;
comment|/*     0x810c - 0x8110     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRLAT
decl_stmt|;
comment|/*     0x8110 - 0x8114     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RXBUF
decl_stmt|;
comment|/*     0x8114 - 0x8118     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MIC_QOS_CONTROL
decl_stmt|;
comment|/*     0x8118 - 0x811c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MIC_QOS_SELECT
decl_stmt|;
comment|/*     0x811c - 0x8120     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MISC_MODE
decl_stmt|;
comment|/*     0x8120 - 0x8124     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_FILTER_OFDM_CNT
decl_stmt|;
comment|/*     0x8124 - 0x8128     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_FILTER_CCK_CNT
decl_stmt|;
comment|/*     0x8128 - 0x812c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_1
decl_stmt|;
comment|/*     0x812c - 0x8130     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_1_MASK
decl_stmt|;
comment|/*     0x8130 - 0x8134     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_2
decl_stmt|;
comment|/*     0x8134 - 0x8138     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_2_MASK
decl_stmt|;
comment|/*     0x8138 - 0x813c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TSF_THRESHOLD
decl_stmt|;
comment|/*     0x813c - 0x8140     */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x8140 - 0x8144     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERROR_EIFS_MASK
decl_stmt|;
comment|/*     0x8144 - 0x8148     */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x20
index|]
decl_stmt|;
comment|/*     0x8148 - 0x8168     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_3
decl_stmt|;
comment|/*     0x8168 - 0x816c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_3_MASK
decl_stmt|;
comment|/*     0x816c - 0x8170     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_MODE
decl_stmt|;
comment|/*     0x8170 - 0x8174     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_WL_WEIGHTS0
decl_stmt|;
comment|/*     0x8174 - 0x8178     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_HCF_TIMEOUT
decl_stmt|;
comment|/*     0x8178 - 0x817c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_MODE2
decl_stmt|;
comment|/*     0x817c - 0x8180     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_GENERIC_TIMERS2
index|[
literal|16
index|]
decl_stmt|;
comment|/*     0x8180 - 0x81c0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_GENERIC_TIMERS2_MODE
decl_stmt|;
comment|/*     0x81c0 - 0x81c4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_WL_WEIGHTS1
decl_stmt|;
comment|/*     0x81c4 - 0x81c8     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE
decl_stmt|;
comment|/*     0x81c8 - 0x81cc     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY
decl_stmt|;
comment|/*     0x81cc - 0x81d0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXSIFS
decl_stmt|;
comment|/*     0x81d0 - 0x81d4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_MODE3
decl_stmt|;
comment|/*     0x81d4 - 0x81d8     */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x14
index|]
decl_stmt|;
comment|/*     0x81d8 - 0x81ec     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXOP_X
decl_stmt|;
comment|/*     0x81ec - 0x81f0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXOP_0_3
decl_stmt|;
comment|/*     0x81f0 - 0x81f4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXOP_4_7
decl_stmt|;
comment|/*     0x81f4 - 0x81f8     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXOP_8_11
decl_stmt|;
comment|/*     0x81f8 - 0x81fc     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXOP_12_15
decl_stmt|;
comment|/*     0x81fc - 0x8200     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_GENERIC_TIMERS
index|[
literal|16
index|]
decl_stmt|;
comment|/*     0x8200 - 0x8240     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_GENERIC_TIMERS_MODE
decl_stmt|;
comment|/*     0x8240 - 0x8244     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP32_MODE
decl_stmt|;
comment|/*     0x8244 - 0x8248     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP32_WAKE
decl_stmt|;
comment|/*     0x8248 - 0x824c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP32_INC
decl_stmt|;
comment|/*     0x824c - 0x8250     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP_MIB1
decl_stmt|;
comment|/*     0x8250 - 0x8254     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP_MIB2
decl_stmt|;
comment|/*     0x8254 - 0x8258     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP_MIB3
decl_stmt|;
comment|/*     0x8258 - 0x825c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW1
decl_stmt|;
comment|/*     0x825c - 0x8260     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW2
decl_stmt|;
comment|/*     0x8260 - 0x8264     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LOGIC_ANALYZER
decl_stmt|;
comment|/*     0x8264 - 0x8268     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LOGIC_ANALYZER_32L
decl_stmt|;
comment|/*     0x8268 - 0x826c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LOGIC_ANALYZER_16U
decl_stmt|;
comment|/*     0x826c - 0x8270     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW3_BEACON_FAIL
decl_stmt|;
comment|/*     0x8270 - 0x8274     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW3_BEACON
decl_stmt|;
comment|/*     0x8274 - 0x8278     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW3_KEEP_ALIVE
decl_stmt|;
comment|/*     0x8278 - 0x827c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW_KA
decl_stmt|;
comment|/*     0x827c - 0x8280     */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x8280 - 0x8284     */
specifier|volatile
name|u_int32_t
name|PCU_1US
decl_stmt|;
comment|/*     0x8284 - 0x8288     */
specifier|volatile
name|u_int32_t
name|PCU_KA
decl_stmt|;
comment|/*     0x8288 - 0x828c     */
specifier|volatile
name|u_int32_t
name|WOW_EXACT
decl_stmt|;
comment|/*     0x828c - 0x8290     */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x8290 - 0x8294     */
specifier|volatile
name|u_int32_t
name|PCU_WOW4
decl_stmt|;
comment|/*     0x8294 - 0x8298     */
specifier|volatile
name|u_int32_t
name|PCU_WOW5
decl_stmt|;
comment|/*     0x8298 - 0x829c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_MASK_CONT
decl_stmt|;
comment|/*     0x829c - 0x82a0     */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x60
index|]
decl_stmt|;
comment|/*     0x82a0 - 0x8300     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AZIMUTH_MODE
decl_stmt|;
comment|/*     0x8300 - 0x8304     */
specifier|volatile
name|char
name|pad__10
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*     0x8304 - 0x8314     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AZIMUTH_TIME_STAMP
decl_stmt|;
comment|/*     0x8314 - 0x8318     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_20_40_MODE
decl_stmt|;
comment|/*     0x8318 - 0x831c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_H_XFER_TIMEOUT
decl_stmt|;
comment|/*     0x831c - 0x8320     */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*     0x8320 - 0x8328     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RX_CLEAR_DIFF_CNT
decl_stmt|;
comment|/*     0x8328 - 0x832c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SELF_GEN_ANTENNA_MASK
decl_stmt|;
comment|/*     0x832c - 0x8330     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BA_BAR_CONTROL
decl_stmt|;
comment|/*     0x8330 - 0x8334     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LEGACY_PLCP_SPOOF
decl_stmt|;
comment|/*     0x8334 - 0x8338     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERROR_MASK_CONT
decl_stmt|;
comment|/*     0x8338 - 0x833c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_TIMER
decl_stmt|;
comment|/*     0x833c - 0x8340     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXBUF_CTRL
decl_stmt|;
comment|/*     0x8340 - 0x8344     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MISC_MODE2
decl_stmt|;
comment|/*     0x8344 - 0x8348     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_ALT_AES_MUTE_MASK
decl_stmt|;
comment|/*     0x8348 - 0x834c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW6
decl_stmt|;
comment|/*     0x834c - 0x8350     */
specifier|volatile
name|u_int32_t
name|ASYNC_FIFO_REG1
decl_stmt|;
comment|/*     0x8350 - 0x8354     */
specifier|volatile
name|u_int32_t
name|ASYNC_FIFO_REG2
decl_stmt|;
comment|/*     0x8354 - 0x8358     */
specifier|volatile
name|u_int32_t
name|ASYNC_FIFO_REG3
decl_stmt|;
comment|/*     0x8358 - 0x835c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW5
decl_stmt|;
comment|/*     0x835c - 0x8360     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW_LENGTH1
decl_stmt|;
comment|/*     0x8360 - 0x8364     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW_LENGTH2
decl_stmt|;
comment|/*     0x8364 - 0x8368     */
specifier|volatile
name|u_int32_t
name|WOW_PATTERN_MATCH_LESS_THAN_256_BYTES
decl_stmt|;
comment|/*     0x8368 - 0x836c     */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x836c - 0x8370     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW4
decl_stmt|;
comment|/*     0x8370 - 0x8374     */
specifier|volatile
name|u_int32_t
name|WOW2_EXACT
decl_stmt|;
comment|/*     0x8374 - 0x8378     */
specifier|volatile
name|u_int32_t
name|PCU_WOW6
decl_stmt|;
comment|/*     0x8378 - 0x837c     */
specifier|volatile
name|u_int32_t
name|PCU_WOW7
decl_stmt|;
comment|/*     0x837c - 0x8380     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW_LENGTH3
decl_stmt|;
comment|/*     0x8380 - 0x8384     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW_LENGTH4
decl_stmt|;
comment|/*     0x8384 - 0x8388     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LOCATION_MODE_CONTROL
decl_stmt|;
comment|/*     0x8388 - 0x838c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LOCATION_MODE_TIMER
decl_stmt|;
comment|/*     0x838c - 0x8390     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TSF2_L32
decl_stmt|;
comment|/*     0x8390 - 0x8394     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TSF2_U32
decl_stmt|;
comment|/*     0x8394 - 0x8398     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BSSID2_L32
decl_stmt|;
comment|/*     0x8398 - 0x839c     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BSSID2_U16
decl_stmt|;
comment|/*     0x839c - 0x83a0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_DIRECT_CONNECT
decl_stmt|;
comment|/*     0x83a0 - 0x83a4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TID_TO_AC
decl_stmt|;
comment|/*     0x83a4 - 0x83a8     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_HP_QUEUE
decl_stmt|;
comment|/*     0x83a8 - 0x83ac     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_BT_WEIGHTS0
decl_stmt|;
comment|/*     0x83ac - 0x83b0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_BT_WEIGHTS1
decl_stmt|;
comment|/*     0x83b0 - 0x83b4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_BT_WEIGHTS2
decl_stmt|;
comment|/*     0x83b4 - 0x83b8     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_BT_WEIGHTS3
decl_stmt|;
comment|/*     0x83b8 - 0x83bc     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AGC_SATURATION_CNT0
decl_stmt|;
comment|/*     0x83bc - 0x83c0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AGC_SATURATION_CNT1
decl_stmt|;
comment|/*     0x83c0 - 0x83c4     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AGC_SATURATION_CNT2
decl_stmt|;
comment|/*     0x83c4 - 0x83c8     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_HW_BCN_PROC1
decl_stmt|;
comment|/*     0x83c8 - 0x83cc     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_HW_BCN_PROC2
decl_stmt|;
comment|/*     0x83cc - 0x83d0     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MISC_MODE3
decl_stmt|;
comment|/*     0x83d0 - 0x83d4     */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_PCU_FILTER_RSSI_AVE
decl_stmt|;
comment|/*     0x83d4 - 0x83d8     */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_PCU_GENERIC_TIMERS_TSF_SEL
decl_stmt|;
comment|/*     0x83d8 - 0x83dc     */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BEACON2_CNT
decl_stmt|;
comment|/*     0x83dc - 0x83e0     */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LAST_BEACON2_TSF
decl_stmt|;
comment|/*     0x83e0 - 0x83e4     */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BMISS_TIMEOUT
decl_stmt|;
comment|/*     0x83e4 - 0x83e8     */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BMISS2_TIMEOUT
decl_stmt|;
comment|/*     0x83e8 - 0x83ec     */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP3
decl_stmt|;
comment|/*     0x83ec - 0x83f0     */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BCN_RSSI_CTL2
decl_stmt|;
comment|/*     0x83f0 - 0x83f4     */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERROR_AIFS_MASK
decl_stmt|;
comment|/*     0x83f4 - 0x83f8     */
comment|/* Jupiter_20 */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TBD_FILTER
decl_stmt|;
comment|/*     0x83f8 - 0x83fc     */
comment|/* Jupiter_20 */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MISC_MODE4
decl_stmt|;
comment|/*     0x83fc - 0x8400     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXBUF_BA
index|[
literal|64
index|]
decl_stmt|;
comment|/*     0x8400 - 0x8500     */
comment|/* Jupiter_20 */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP4
decl_stmt|;
comment|/*     0x8500 - 0x8504     */
specifier|volatile
name|char
name|pad__13
index|[
literal|0x2fc
index|]
decl_stmt|;
comment|/*     0x8504 - 0x8800     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_KEY_CACHE
index|[
literal|1024
index|]
decl_stmt|;
comment|/*     0x8800 - 0x9800     */
specifier|volatile
name|char
name|pad__14
index|[
literal|0x4800
index|]
decl_stmt|;
comment|/*     0x9800 - 0xe000     */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BUF
index|[
literal|2048
index|]
decl_stmt|;
comment|/*     0xe000 - 0x10000    */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|chn_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_timing_controls_1
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BB_timing_controls_2
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|BB_timing_controls_3
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|BB_timing_control_4
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|BB_timing_control_5
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|BB_timing_control_6
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|BB_timing_control_11
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|BB_spur_mask_controls
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|BB_find_signal_low
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|BB_sfcorr
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|BB_self_corr_low
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|BB_ext_chan_scorr_thr
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|BB_ext_chan_pwr_thr_2_b0
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|BB_radar_detection
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|BB_radar_detection_2
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|BB_extension_radar
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x40
index|]
decl_stmt|;
comment|/*       0x40 - 0x80       */
specifier|volatile
name|u_int32_t
name|BB_multichain_control
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|BB_per_chain_csd
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x18
index|]
decl_stmt|;
comment|/*       0x88 - 0xa0       */
specifier|volatile
name|u_int32_t
name|BB_tx_crc
decl_stmt|;
comment|/*       0xa0 - 0xa4       */
specifier|volatile
name|u_int32_t
name|BB_tstdac_constant
decl_stmt|;
comment|/*       0xa4 - 0xa8       */
specifier|volatile
name|u_int32_t
name|BB_spur_report_b0
decl_stmt|;
comment|/*       0xa8 - 0xac       */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xac - 0xb0       */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_3
decl_stmt|;
comment|/*       0xb0 - 0xb4       */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*       0xb4 - 0xbc       */
comment|/* Poseidon, Jupiter */
specifier|volatile
name|u_int32_t
name|BB_green_tx_control_1
decl_stmt|;
comment|/*       0xbc - 0xc0       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_0_b0
decl_stmt|;
comment|/*       0xc0 - 0xc4       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_1_b0
decl_stmt|;
comment|/*       0xc4 - 0xc8       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_2_b0
decl_stmt|;
comment|/*       0xc8 - 0xcc       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_3_b0
decl_stmt|;
comment|/*       0xcc - 0xd0       */
specifier|volatile
name|u_int32_t
name|BB_tx_phase_ramp_b0
decl_stmt|;
comment|/*       0xd0 - 0xd4       */
specifier|volatile
name|u_int32_t
name|BB_adc_gain_dc_corr_b0
decl_stmt|;
comment|/*       0xd4 - 0xd8       */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xd8 - 0xdc       */
specifier|volatile
name|u_int32_t
name|BB_rx_iq_corr_b0
decl_stmt|;
comment|/*       0xdc - 0xe0       */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xe0 - 0xe4       */
specifier|volatile
name|u_int32_t
name|BB_paprd_am2am_mask
decl_stmt|;
comment|/*       0xe4 - 0xe8       */
specifier|volatile
name|u_int32_t
name|BB_paprd_am2pm_mask
decl_stmt|;
comment|/*       0xe8 - 0xec       */
specifier|volatile
name|u_int32_t
name|BB_paprd_ht40_mask
decl_stmt|;
comment|/*       0xec - 0xf0       */
specifier|volatile
name|u_int32_t
name|BB_paprd_ctrl0_b0
decl_stmt|;
comment|/*       0xf0 - 0xf4       */
specifier|volatile
name|u_int32_t
name|BB_paprd_ctrl1_b0
decl_stmt|;
comment|/*       0xf4 - 0xf8       */
specifier|volatile
name|u_int32_t
name|BB_pa_gain123_b0
decl_stmt|;
comment|/*       0xf8 - 0xfc       */
specifier|volatile
name|u_int32_t
name|BB_pa_gain45_b0
decl_stmt|;
comment|/*       0xfc - 0x100      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_0_b0
decl_stmt|;
comment|/*      0x100 - 0x104      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_1_b0
decl_stmt|;
comment|/*      0x104 - 0x108      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_2_b0
decl_stmt|;
comment|/*      0x108 - 0x10c      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_3_b0
decl_stmt|;
comment|/*      0x10c - 0x110      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_4_b0
decl_stmt|;
comment|/*      0x110 - 0x114      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_5_b0
decl_stmt|;
comment|/*      0x114 - 0x118      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_6_b0
decl_stmt|;
comment|/*      0x118 - 0x11c      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_7_b0
decl_stmt|;
comment|/*      0x11c - 0x120      */
specifier|volatile
name|u_int32_t
name|BB_paprd_mem_tab_b0
index|[
literal|120
index|]
decl_stmt|;
comment|/*      0x120 - 0x300      */
specifier|volatile
name|u_int32_t
name|BB_chan_info_chan_tab_b0
index|[
literal|60
index|]
decl_stmt|;
comment|/*      0x300 - 0x3f0      */
comment|/* Jupiter_20 */
specifier|volatile
name|u_int32_t
name|BB_chn_tables_intf_addr
decl_stmt|;
comment|/*      0x3f0 - 0x3f4      */
comment|/* Jupiter_20 */
specifier|volatile
name|u_int32_t
name|BB_chn_tables_intf_data
decl_stmt|;
comment|/*      0x3f4 - 0x3f8      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mrc_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_timing_control_3a
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BB_ldpc_cntl1
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|BB_ldpc_cntl2
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|BB_pilot_spur_mask
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|BB_chan_spur_mask
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|BB_short_gi_delta_slope
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|BB_ml_cntl1
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|BB_ml_cntl2
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|BB_tstadc
decl_stmt|;
comment|/*       0x20 - 0x24       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bbb_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_bbb_rx_ctrl_1
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BB_bbb_rx_ctrl_2
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|BB_bbb_rx_ctrl_3
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|BB_bbb_rx_ctrl_4
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|BB_bbb_rx_ctrl_5
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|BB_bbb_rx_ctrl_6
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|BB_force_clken_cck
decl_stmt|;
comment|/*       0x18 - 0x1c       */
comment|/* Poseidon, Jupiter_10 */
specifier|volatile
name|u_int32_t
name|BB_bb_reg_page_control
decl_stmt|;
comment|/*       0x1c - 0x20       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|agc_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_settling_time
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BB_gain_force_max_gains_b0
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|BB_gains_min_offsets
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|BB_desired_sigsize
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|BB_find_signal
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|BB_agc
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|BB_ext_atten_switch_ctl_b0
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|BB_cca_b0
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|BB_cca_ctrl_2_b0
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|BB_restart
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|BB_multichain_gain_ctrl
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|BB_ext_chan_pwr_thr_1
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|BB_ext_chan_detect_win
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|BB_pwr_thr_20_40_det
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|BB_rifs_srch
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|BB_peak_det_ctrl_1
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|BB_peak_det_ctrl_2
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|BB_rx_gain_bounds_1
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|BB_rx_gain_bounds_2
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|BB_peak_det_cal_ctrl
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|BB_agc_dig_dc_ctrl
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|BB_bt_coex_1
decl_stmt|;
comment|/*       0x54 - 0x58       */
comment|/* Poseidon, Jupiter */
specifier|volatile
name|u_int32_t
name|BB_bt_coex_2
decl_stmt|;
comment|/*       0x58 - 0x5c       */
comment|/* Poseidon, Jupiter */
specifier|volatile
name|u_int32_t
name|BB_bt_coex_3
decl_stmt|;
comment|/*       0x5c - 0x60       */
comment|/* Poseidon, Jupiter */
specifier|volatile
name|u_int32_t
name|BB_bt_coex_4
decl_stmt|;
comment|/*       0x60 - 0x64       */
comment|/* Poseidon, Jupiter */
specifier|volatile
name|u_int32_t
name|BB_bt_coex_5
decl_stmt|;
comment|/*       0x64 - 0x68       */
comment|/* Jupiter_20 */
specifier|volatile
name|u_int32_t
name|BB_redpwr_ctrl_1
decl_stmt|;
comment|/*       0x68 - 0x6c       */
comment|/* Jupiter_20 */
specifier|volatile
name|u_int32_t
name|BB_redpwr_ctrl_2
decl_stmt|;
comment|/*       0x6c - 0x70       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x110
index|]
decl_stmt|;
comment|/*       0x70 - 0x180      */
specifier|volatile
name|u_int32_t
name|BB_rssi_b0
decl_stmt|;
comment|/*      0x180 - 0x184      */
specifier|volatile
name|u_int32_t
name|BB_spur_est_cck_report_b0
decl_stmt|;
comment|/*      0x184 - 0x188      */
specifier|volatile
name|u_int32_t
name|BB_agc_dig_dc_status_i_b0
decl_stmt|;
comment|/*      0x188 - 0x18c      */
specifier|volatile
name|u_int32_t
name|BB_agc_dig_dc_status_q_b0
decl_stmt|;
comment|/*      0x18c - 0x190      */
comment|/* Poseidon, Jupiter */
specifier|volatile
name|u_int32_t
name|BB_dc_cal_status_b0
decl_stmt|;
comment|/*      0x190 - 0x194      */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x2c
index|]
decl_stmt|;
comment|/*      0x194 - 0x1c0      */
specifier|volatile
name|u_int32_t
name|BB_bbb_sig_detect
decl_stmt|;
comment|/*      0x1c0 - 0x1c4      */
specifier|volatile
name|u_int32_t
name|BB_bbb_dagc_ctrl
decl_stmt|;
comment|/*      0x1c4 - 0x1c8      */
specifier|volatile
name|u_int32_t
name|BB_iqcorr_ctrl_cck
decl_stmt|;
comment|/*      0x1c8 - 0x1cc      */
specifier|volatile
name|u_int32_t
name|BB_cck_spur_mit
decl_stmt|;
comment|/*      0x1cc - 0x1d0      */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|BB_mrc_cck_ctrl
decl_stmt|;
comment|/*      0x1d0 - 0x1d4      */
comment|/* Jupiter_20 */
specifier|volatile
name|u_int32_t
name|BB_cck_blocker_det
decl_stmt|;
comment|/*      0x1d4 - 0x1d8      */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x28
index|]
decl_stmt|;
comment|/*      0x1d8 - 0x200      */
specifier|volatile
name|u_int32_t
name|BB_rx_ocgain
index|[
literal|128
index|]
decl_stmt|;
comment|/*      0x200 - 0x400      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sm_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_D2_chip_id
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BB_gen_controls
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|BB_modes_select
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|BB_active
decl_stmt|;
comment|/*        0xc - 0x10       */
comment|/* Poseidon, Jupiter_10 */
specifier|volatile
name|u_int32_t
name|BB_bb_reg_page
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0xc
index|]
decl_stmt|;
comment|/*       0x14 - 0x20       */
specifier|volatile
name|u_int32_t
name|BB_vit_spur_mask_A
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|BB_vit_spur_mask_B
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|BB_spectral_scan
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|BB_radar_bw_filter
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|BB_search_start_delay
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|BB_max_rx_length
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|BB_frame_control
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|BB_rfbus_request
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|BB_rfbus_grant
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|BB_rifs
decl_stmt|;
comment|/*       0x44 - 0x48       */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|BB_spectral_scan_2
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|BB_rx_clear_delay
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|BB_analog_power_on_time
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|u_int32_t
name|BB_tx_timing_1
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|BB_tx_timing_2
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|BB_tx_timing_3
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|BB_xpa_timing_control
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x18
index|]
decl_stmt|;
comment|/*       0x68 - 0x80       */
specifier|volatile
name|u_int32_t
name|BB_misc_pa_control
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|BB_switch_table_chn_b0
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|u_int32_t
name|BB_switch_table_com1
decl_stmt|;
comment|/*       0x88 - 0x8c       */
specifier|volatile
name|u_int32_t
name|BB_switch_table_com2
decl_stmt|;
comment|/*       0x8c - 0x90       */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*       0x90 - 0xa0       */
specifier|volatile
name|u_int32_t
name|BB_multichain_enable
decl_stmt|;
comment|/*       0xa0 - 0xa4       */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x1c
index|]
decl_stmt|;
comment|/*       0xa4 - 0xc0       */
specifier|volatile
name|u_int32_t
name|BB_cal_chain_mask
decl_stmt|;
comment|/*       0xc0 - 0xc4       */
specifier|volatile
name|u_int32_t
name|BB_agc_control
decl_stmt|;
comment|/*       0xc4 - 0xc8       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_cal_mode
decl_stmt|;
comment|/*       0xc8 - 0xcc       */
specifier|volatile
name|u_int32_t
name|BB_fcal_1
decl_stmt|;
comment|/*       0xcc - 0xd0       */
specifier|volatile
name|u_int32_t
name|BB_fcal_2_b0
decl_stmt|;
comment|/*       0xd0 - 0xd4       */
specifier|volatile
name|u_int32_t
name|BB_dft_tone_ctrl_b0
decl_stmt|;
comment|/*       0xd4 - 0xd8       */
specifier|volatile
name|u_int32_t
name|BB_cl_cal_ctrl
decl_stmt|;
comment|/*       0xd8 - 0xdc       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_0_b0
decl_stmt|;
comment|/*       0xdc - 0xe0       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_1_b0
decl_stmt|;
comment|/*       0xe0 - 0xe4       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_2_b0
decl_stmt|;
comment|/*       0xe4 - 0xe8       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_3_b0
decl_stmt|;
comment|/*       0xe8 - 0xec       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_0_b0
decl_stmt|;
comment|/*       0xec - 0xf0       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_1_b0
decl_stmt|;
comment|/*       0xf0 - 0xf4       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_2_b0
decl_stmt|;
comment|/*       0xf4 - 0xf8       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_3_b0
decl_stmt|;
comment|/*       0xf8 - 0xfc       */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xfc - 0x100      */
specifier|volatile
name|u_int32_t
name|BB_cl_tab_b0
index|[
literal|16
index|]
decl_stmt|;
comment|/*      0x100 - 0x140      */
specifier|volatile
name|u_int32_t
name|BB_synth_control
decl_stmt|;
comment|/*      0x140 - 0x144      */
specifier|volatile
name|u_int32_t
name|BB_addac_clk_select
decl_stmt|;
comment|/*      0x144 - 0x148      */
specifier|volatile
name|u_int32_t
name|BB_pll_cntl
decl_stmt|;
comment|/*      0x148 - 0x14c      */
specifier|volatile
name|u_int32_t
name|BB_analog_swap
decl_stmt|;
comment|/*      0x14c - 0x150      */
specifier|volatile
name|u_int32_t
name|BB_addac_parallel_control
decl_stmt|;
comment|/*      0x150 - 0x154      */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x154 - 0x158      */
specifier|volatile
name|u_int32_t
name|BB_force_analog
decl_stmt|;
comment|/*      0x158 - 0x15c      */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x15c - 0x160      */
specifier|volatile
name|u_int32_t
name|BB_test_controls
decl_stmt|;
comment|/*      0x160 - 0x164      */
specifier|volatile
name|u_int32_t
name|BB_test_controls_status
decl_stmt|;
comment|/*      0x164 - 0x168      */
specifier|volatile
name|u_int32_t
name|BB_tstdac
decl_stmt|;
comment|/*      0x168 - 0x16c      */
specifier|volatile
name|u_int32_t
name|BB_channel_status
decl_stmt|;
comment|/*      0x16c - 0x170      */
specifier|volatile
name|u_int32_t
name|BB_chaninfo_ctrl
decl_stmt|;
comment|/*      0x170 - 0x174      */
specifier|volatile
name|u_int32_t
name|BB_chan_info_noise_pwr
decl_stmt|;
comment|/*      0x174 - 0x178      */
specifier|volatile
name|u_int32_t
name|BB_chan_info_gain_diff
decl_stmt|;
comment|/*      0x178 - 0x17c      */
specifier|volatile
name|u_int32_t
name|BB_chan_info_fine_timing
decl_stmt|;
comment|/*      0x17c - 0x180      */
specifier|volatile
name|u_int32_t
name|BB_chan_info_gain_b0
decl_stmt|;
comment|/*      0x180 - 0x184      */
specifier|volatile
name|char
name|pad__8
index|[
literal|0xc
index|]
decl_stmt|;
comment|/*      0x184 - 0x190      */
specifier|volatile
name|u_int32_t
name|BB_scrambler_seed
decl_stmt|;
comment|/*      0x190 - 0x194      */
specifier|volatile
name|u_int32_t
name|BB_bbb_tx_ctrl
decl_stmt|;
comment|/*      0x194 - 0x198      */
specifier|volatile
name|u_int32_t
name|BB_bbb_txfir_0
decl_stmt|;
comment|/*      0x198 - 0x19c      */
specifier|volatile
name|u_int32_t
name|BB_bbb_txfir_1
decl_stmt|;
comment|/*      0x19c - 0x1a0      */
specifier|volatile
name|u_int32_t
name|BB_bbb_txfir_2
decl_stmt|;
comment|/*      0x1a0 - 0x1a4      */
specifier|volatile
name|u_int32_t
name|BB_heavy_clip_ctrl
decl_stmt|;
comment|/*      0x1a4 - 0x1a8      */
specifier|volatile
name|u_int32_t
name|BB_heavy_clip_20
decl_stmt|;
comment|/*      0x1a8 - 0x1ac      */
specifier|volatile
name|u_int32_t
name|BB_heavy_clip_40
decl_stmt|;
comment|/*      0x1ac - 0x1b0      */
specifier|volatile
name|u_int32_t
name|BB_illegal_tx_rate
decl_stmt|;
comment|/*      0x1b0 - 0x1b4      */
specifier|volatile
name|char
name|pad__9
index|[
literal|0xc
index|]
decl_stmt|;
comment|/*      0x1b4 - 0x1c0      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate1
decl_stmt|;
comment|/*      0x1c0 - 0x1c4      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate2
decl_stmt|;
comment|/*      0x1c4 - 0x1c8      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate3
decl_stmt|;
comment|/*      0x1c8 - 0x1cc      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate4
decl_stmt|;
comment|/*      0x1cc - 0x1d0      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate5
decl_stmt|;
comment|/*      0x1d0 - 0x1d4      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate6
decl_stmt|;
comment|/*      0x1d4 - 0x1d8      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate7
decl_stmt|;
comment|/*      0x1d8 - 0x1dc      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate8
decl_stmt|;
comment|/*      0x1dc - 0x1e0      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate9
decl_stmt|;
comment|/*      0x1e0 - 0x1e4      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate10
decl_stmt|;
comment|/*      0x1e4 - 0x1e8      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate11
decl_stmt|;
comment|/*      0x1e8 - 0x1ec      */
specifier|volatile
name|u_int32_t
name|BB_powertx_rate12
decl_stmt|;
comment|/*      0x1ec - 0x1f0      */
specifier|volatile
name|u_int32_t
name|BB_powertx_max
decl_stmt|;
comment|/*      0x1f0 - 0x1f4      */
specifier|volatile
name|u_int32_t
name|BB_powertx_sub
decl_stmt|;
comment|/*      0x1f4 - 0x1f8      */
specifier|volatile
name|u_int32_t
name|BB_tpc_1
decl_stmt|;
comment|/*      0x1f8 - 0x1fc      */
specifier|volatile
name|u_int32_t
name|BB_tpc_2
decl_stmt|;
comment|/*      0x1fc - 0x200      */
specifier|volatile
name|u_int32_t
name|BB_tpc_3
decl_stmt|;
comment|/*      0x200 - 0x204      */
specifier|volatile
name|u_int32_t
name|BB_tpc_4_b0
decl_stmt|;
comment|/*      0x204 - 0x208      */
specifier|volatile
name|u_int32_t
name|BB_tpc_5_b0
decl_stmt|;
comment|/*      0x208 - 0x20c      */
specifier|volatile
name|u_int32_t
name|BB_tpc_6_b0
decl_stmt|;
comment|/*      0x20c - 0x210      */
specifier|volatile
name|u_int32_t
name|BB_tpc_7
decl_stmt|;
comment|/*      0x210 - 0x214      */
specifier|volatile
name|u_int32_t
name|BB_tpc_8
decl_stmt|;
comment|/*      0x214 - 0x218      */
specifier|volatile
name|u_int32_t
name|BB_tpc_9
decl_stmt|;
comment|/*      0x218 - 0x21c      */
specifier|volatile
name|u_int32_t
name|BB_tpc_10
decl_stmt|;
comment|/*      0x21c - 0x220      */
specifier|volatile
name|u_int32_t
name|BB_tpc_11_b0
decl_stmt|;
comment|/*      0x220 - 0x224      */
specifier|volatile
name|u_int32_t
name|BB_tpc_12
decl_stmt|;
comment|/*      0x224 - 0x228      */
specifier|volatile
name|u_int32_t
name|BB_tpc_13
decl_stmt|;
comment|/*      0x228 - 0x22c      */
specifier|volatile
name|u_int32_t
name|BB_tpc_14
decl_stmt|;
comment|/*      0x22c - 0x230      */
specifier|volatile
name|u_int32_t
name|BB_tpc_15
decl_stmt|;
comment|/*      0x230 - 0x234      */
specifier|volatile
name|u_int32_t
name|BB_tpc_16
decl_stmt|;
comment|/*      0x234 - 0x238      */
specifier|volatile
name|u_int32_t
name|BB_tpc_17
decl_stmt|;
comment|/*      0x238 - 0x23c      */
specifier|volatile
name|u_int32_t
name|BB_tpc_18
decl_stmt|;
comment|/*      0x23c - 0x240      */
specifier|volatile
name|u_int32_t
name|BB_tpc_19
decl_stmt|;
comment|/*      0x240 - 0x244      */
specifier|volatile
name|u_int32_t
name|BB_tpc_20
decl_stmt|;
comment|/*      0x244 - 0x248      */
specifier|volatile
name|u_int32_t
name|BB_therm_adc_1
decl_stmt|;
comment|/*      0x248 - 0x24c      */
specifier|volatile
name|u_int32_t
name|BB_therm_adc_2
decl_stmt|;
comment|/*      0x24c - 0x250      */
specifier|volatile
name|u_int32_t
name|BB_therm_adc_3
decl_stmt|;
comment|/*      0x250 - 0x254      */
specifier|volatile
name|u_int32_t
name|BB_therm_adc_4
decl_stmt|;
comment|/*      0x254 - 0x258      */
specifier|volatile
name|u_int32_t
name|BB_tx_forced_gain
decl_stmt|;
comment|/*      0x258 - 0x25c      */
specifier|volatile
name|char
name|pad__10
index|[
literal|0x24
index|]
decl_stmt|;
comment|/*      0x25c - 0x280      */
specifier|volatile
name|u_int32_t
name|BB_pdadc_tab_b0
index|[
literal|32
index|]
decl_stmt|;
comment|/*      0x280 - 0x300      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_1
decl_stmt|;
comment|/*      0x300 - 0x304      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_2
decl_stmt|;
comment|/*      0x304 - 0x308      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_3
decl_stmt|;
comment|/*      0x308 - 0x30c      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_4
decl_stmt|;
comment|/*      0x30c - 0x310      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_5
decl_stmt|;
comment|/*      0x310 - 0x314      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_6
decl_stmt|;
comment|/*      0x314 - 0x318      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_7
decl_stmt|;
comment|/*      0x318 - 0x31c      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_8
decl_stmt|;
comment|/*      0x31c - 0x320      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_9
decl_stmt|;
comment|/*      0x320 - 0x324      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_10
decl_stmt|;
comment|/*      0x324 - 0x328      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_11
decl_stmt|;
comment|/*      0x328 - 0x32c      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_12
decl_stmt|;
comment|/*      0x32c - 0x330      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_13
decl_stmt|;
comment|/*      0x330 - 0x334      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_14
decl_stmt|;
comment|/*      0x334 - 0x338      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_15
decl_stmt|;
comment|/*      0x338 - 0x33c      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_16
decl_stmt|;
comment|/*      0x33c - 0x340      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_17
decl_stmt|;
comment|/*      0x340 - 0x344      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_18
decl_stmt|;
comment|/*      0x344 - 0x348      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_19
decl_stmt|;
comment|/*      0x348 - 0x34c      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_20
decl_stmt|;
comment|/*      0x34c - 0x350      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_21
decl_stmt|;
comment|/*      0x350 - 0x354      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_22
decl_stmt|;
comment|/*      0x354 - 0x358      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_23
decl_stmt|;
comment|/*      0x358 - 0x35c      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_24
decl_stmt|;
comment|/*      0x35c - 0x360      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_25
decl_stmt|;
comment|/*      0x360 - 0x364      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_26
decl_stmt|;
comment|/*      0x364 - 0x368      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_27
decl_stmt|;
comment|/*      0x368 - 0x36c      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_28
decl_stmt|;
comment|/*      0x36c - 0x370      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_29
decl_stmt|;
comment|/*      0x370 - 0x374      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_30
decl_stmt|;
comment|/*      0x374 - 0x378      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_31
decl_stmt|;
comment|/*      0x378 - 0x37c      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_32
decl_stmt|;
comment|/*      0x37c - 0x380      */
union|union
block|{
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_1
decl_stmt|;
comment|/*      0x380 - 0x384      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_2
decl_stmt|;
comment|/*      0x384 - 0x388      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_3
decl_stmt|;
comment|/*      0x388 - 0x38c      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_4
decl_stmt|;
comment|/*      0x38c - 0x390      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_5
decl_stmt|;
comment|/*      0x390 - 0x394      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_6
decl_stmt|;
comment|/*      0x394 - 0x398      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_7
decl_stmt|;
comment|/*      0x398 - 0x39c      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_8
decl_stmt|;
comment|/*      0x39c - 0x3a0      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_9
decl_stmt|;
comment|/*      0x3a0 - 0x3a4      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_10
decl_stmt|;
comment|/*      0x3a4 - 0x3a8      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_11
decl_stmt|;
comment|/*      0x3a8 - 0x3ac      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_12
decl_stmt|;
comment|/*      0x3ac - 0x3b0      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_13
decl_stmt|;
comment|/*      0x3b0 - 0x3b4      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_14
decl_stmt|;
comment|/*      0x3b4 - 0x3b8      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_15
decl_stmt|;
comment|/*      0x3b8 - 0x3bc      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_16
decl_stmt|;
comment|/*      0x3bc - 0x3c0      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_17
decl_stmt|;
comment|/*      0x3c0 - 0x3c4      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_18
decl_stmt|;
comment|/*      0x3c4 - 0x3c8      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_19
decl_stmt|;
comment|/*      0x3c8 - 0x3cc      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_20
decl_stmt|;
comment|/*      0x3cc - 0x3d0      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_21
decl_stmt|;
comment|/*      0x3d0 - 0x3d4      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_22
decl_stmt|;
comment|/*      0x3d4 - 0x3d8      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_23
decl_stmt|;
comment|/*      0x3d8 - 0x3dc      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_24
decl_stmt|;
comment|/*      0x3dc - 0x3e0      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_25
decl_stmt|;
comment|/*      0x3e0 - 0x3e4      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_26
decl_stmt|;
comment|/*      0x3e4 - 0x3e8      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_27
decl_stmt|;
comment|/*      0x3e8 - 0x3ec      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_28
decl_stmt|;
comment|/*      0x3ec - 0x3f0      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_29
decl_stmt|;
comment|/*      0x3f0 - 0x3f4      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_30
decl_stmt|;
comment|/*      0x3f4 - 0x3f8      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_31
decl_stmt|;
comment|/*      0x3f8 - 0x3fc      */
specifier|volatile
name|u_int32_t
name|BB_tx_gain_tab_pal_32
decl_stmt|;
comment|/*      0x3fc - 0x400      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_0
decl_stmt|;
comment|/*      0x400 - 0x404      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_2
decl_stmt|;
comment|/*      0x404 - 0x408      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_4
decl_stmt|;
comment|/*      0x408 - 0x40c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_6
decl_stmt|;
comment|/*      0x40c - 0x410      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_8
decl_stmt|;
comment|/*      0x410 - 0x414      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_10
decl_stmt|;
comment|/*      0x414 - 0x418      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_12
decl_stmt|;
comment|/*      0x418 - 0x41c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_14
decl_stmt|;
comment|/*      0x41c - 0x420      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_16
decl_stmt|;
comment|/*      0x420 - 0x424      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_18
decl_stmt|;
comment|/*      0x424 - 0x428      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_20
decl_stmt|;
comment|/*      0x428 - 0x42c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_22
decl_stmt|;
comment|/*      0x42c - 0x430      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_24
decl_stmt|;
comment|/*      0x430 - 0x434      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_26
decl_stmt|;
comment|/*      0x434 - 0x438      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_28
decl_stmt|;
comment|/*      0x438 - 0x43c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_30
decl_stmt|;
comment|/*      0x43c - 0x440      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_start
decl_stmt|;
comment|/*      0x440 - 0x444      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_0
decl_stmt|;
comment|/*      0x444 - 0x448      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_1
decl_stmt|;
comment|/*      0x448 - 0x44c      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_2
decl_stmt|;
comment|/*      0x44c - 0x450      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_01_b0
decl_stmt|;
comment|/*      0x450 - 0x454      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_23_b0
decl_stmt|;
comment|/*      0x454 - 0x458      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_45_b0
decl_stmt|;
comment|/*      0x458 - 0x45c      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_67_b0
decl_stmt|;
comment|/*      0x45c - 0x460      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_89_b0
decl_stmt|;
comment|/*      0x460 - 0x464      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ab_b0
decl_stmt|;
comment|/*      0x464 - 0x468      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_cd_b0
decl_stmt|;
comment|/*      0x468 - 0x46c      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ef_b0
decl_stmt|;
comment|/*      0x46c - 0x470      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_0
decl_stmt|;
comment|/*      0x470 - 0x474      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_4
decl_stmt|;
comment|/*      0x474 - 0x478      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_8
decl_stmt|;
comment|/*      0x478 - 0x47c      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_12
decl_stmt|;
comment|/*      0x47c - 0x480      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_16
decl_stmt|;
comment|/*      0x480 - 0x484      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_20
decl_stmt|;
comment|/*      0x484 - 0x488      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_24
decl_stmt|;
comment|/*      0x488 - 0x48c      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_status_b0
decl_stmt|;
comment|/*      0x48c - 0x490      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl1
decl_stmt|;
comment|/*      0x490 - 0x494      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl2
decl_stmt|;
comment|/*      0x494 - 0x498      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl3
decl_stmt|;
comment|/*      0x498 - 0x49c      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl4
decl_stmt|;
comment|/*      0x49c - 0x4a0      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat1
decl_stmt|;
comment|/*      0x4a0 - 0x4a4      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat2
decl_stmt|;
comment|/*      0x4a4 - 0x4a8      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat3
decl_stmt|;
comment|/*      0x4a8 - 0x4ac      */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x114
index|]
decl_stmt|;
comment|/*      0x4ac - 0x5c0      */
block|}
name|Osprey
struct|;
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_0
decl_stmt|;
comment|/*      0x380 - 0x384      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_2
decl_stmt|;
comment|/*      0x384 - 0x388      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_4
decl_stmt|;
comment|/*      0x388 - 0x38c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_6
decl_stmt|;
comment|/*      0x38c - 0x390      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_8
decl_stmt|;
comment|/*      0x390 - 0x394      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_10
decl_stmt|;
comment|/*      0x394 - 0x398      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_12
decl_stmt|;
comment|/*      0x398 - 0x39c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_14
decl_stmt|;
comment|/*      0x39c - 0x3a0      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_16
decl_stmt|;
comment|/*      0x3a0 - 0x3a4      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_18
decl_stmt|;
comment|/*      0x3a4 - 0x3a8      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_20
decl_stmt|;
comment|/*      0x3a8 - 0x3ac      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_22
decl_stmt|;
comment|/*      0x3ac - 0x3b0      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_24
decl_stmt|;
comment|/*      0x3b0 - 0x3b4      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_26
decl_stmt|;
comment|/*      0x3b4 - 0x3b8      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_28
decl_stmt|;
comment|/*      0x3b8 - 0x3bc      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_30
decl_stmt|;
comment|/*      0x3bc - 0x3c0      */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x3c0 - 0x3c4      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_0
decl_stmt|;
comment|/*      0x3c4 - 0x3c8      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_1
decl_stmt|;
comment|/*      0x3c8 - 0x3cc      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_2
decl_stmt|;
comment|/*      0x3cc - 0x3d0      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_01_b0
decl_stmt|;
comment|/*      0x3d0 - 0x3d4      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_23_b0
decl_stmt|;
comment|/*      0x3d4 - 0x3d8      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_45_b0
decl_stmt|;
comment|/*      0x3d8 - 0x3dc      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_67_b0
decl_stmt|;
comment|/*      0x3dc - 0x3e0      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_89_b0
decl_stmt|;
comment|/*      0x3e0 - 0x3e4      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ab_b0
decl_stmt|;
comment|/*      0x3e4 - 0x3e8      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_cd_b0
decl_stmt|;
comment|/*      0x3e8 - 0x3ec      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ef_b0
decl_stmt|;
comment|/*      0x3ec - 0x3f0      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_status_b0
decl_stmt|;
comment|/*      0x3f0 - 0x3f4      */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x16c
index|]
decl_stmt|;
comment|/*      0x3f4 - 0x560      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_0
decl_stmt|;
comment|/*      0x560 - 0x564      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_4
decl_stmt|;
comment|/*      0x564 - 0x568      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_8
decl_stmt|;
comment|/*      0x568 - 0x56c      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_12
decl_stmt|;
comment|/*      0x56c - 0x570      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_16
decl_stmt|;
comment|/*      0x570 - 0x574      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_20
decl_stmt|;
comment|/*      0x574 - 0x578      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_24
decl_stmt|;
comment|/*      0x578 - 0x57c      */
specifier|volatile
name|char
name|pad__13
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x57c - 0x580      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl1
decl_stmt|;
comment|/*      0x580 - 0x584      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl2
decl_stmt|;
comment|/*      0x584 - 0x588      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl3
decl_stmt|;
comment|/*      0x588 - 0x58c      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl4
decl_stmt|;
comment|/*      0x58c - 0x590      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat1
decl_stmt|;
comment|/*      0x590 - 0x594      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat2
decl_stmt|;
comment|/*      0x594 - 0x598      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat3
decl_stmt|;
comment|/*      0x598 - 0x59c      */
specifier|volatile
name|char
name|pad__14
index|[
literal|0x24
index|]
decl_stmt|;
comment|/*      0x59c - 0x5c0      */
block|}
name|Poseidon
struct|;
struct|struct
block|{
specifier|volatile
name|char
name|pad__11
index|[
literal|0x80
index|]
decl_stmt|;
comment|/*      0x380 - 0x400      */
comment|/* 0x400 - 0x4b0 same as Osprey - start */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_0
decl_stmt|;
comment|/*      0x400 - 0x404      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_2
decl_stmt|;
comment|/*      0x404 - 0x408      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_4
decl_stmt|;
comment|/*      0x408 - 0x40c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_6
decl_stmt|;
comment|/*      0x40c - 0x410      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_8
decl_stmt|;
comment|/*      0x410 - 0x414      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_10
decl_stmt|;
comment|/*      0x414 - 0x418      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_12
decl_stmt|;
comment|/*      0x418 - 0x41c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_14
decl_stmt|;
comment|/*      0x41c - 0x420      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_16
decl_stmt|;
comment|/*      0x420 - 0x424      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_18
decl_stmt|;
comment|/*      0x424 - 0x428      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_20
decl_stmt|;
comment|/*      0x428 - 0x42c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_22
decl_stmt|;
comment|/*      0x42c - 0x430      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_24
decl_stmt|;
comment|/*      0x430 - 0x434      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_26
decl_stmt|;
comment|/*      0x434 - 0x438      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_28
decl_stmt|;
comment|/*      0x438 - 0x43c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_30
decl_stmt|;
comment|/*      0x43c - 0x440      */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x440 - 0x444      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_0
decl_stmt|;
comment|/*      0x444 - 0x448      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_1
decl_stmt|;
comment|/*      0x448 - 0x44c      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_2
decl_stmt|;
comment|/*      0x44c - 0x450      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_01_b0
decl_stmt|;
comment|/*      0x450 - 0x454      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_23_b0
decl_stmt|;
comment|/*      0x454 - 0x458      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_45_b0
decl_stmt|;
comment|/*      0x458 - 0x45c      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_67_b0
decl_stmt|;
comment|/*      0x45c - 0x460      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_89_b0
decl_stmt|;
comment|/*      0x460 - 0x464      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ab_b0
decl_stmt|;
comment|/*      0x464 - 0x468      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_cd_b0
decl_stmt|;
comment|/*      0x468 - 0x46c      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ef_b0
decl_stmt|;
comment|/*      0x46c - 0x470      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_0
decl_stmt|;
comment|/*      0x470 - 0x474      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_4
decl_stmt|;
comment|/*      0x474 - 0x478      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_8
decl_stmt|;
comment|/*      0x478 - 0x47c      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_12
decl_stmt|;
comment|/*      0x47c - 0x480      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_16
decl_stmt|;
comment|/*      0x480 - 0x484      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_20
decl_stmt|;
comment|/*      0x484 - 0x488      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_24
decl_stmt|;
comment|/*      0x488 - 0x48c      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_status_b0
decl_stmt|;
comment|/*      0x48c - 0x490      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl1
decl_stmt|;
comment|/*      0x490 - 0x494      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl2
decl_stmt|;
comment|/*      0x494 - 0x498      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl3
decl_stmt|;
comment|/*      0x498 - 0x49c      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl4
decl_stmt|;
comment|/*      0x49c - 0x4a0      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat1
decl_stmt|;
comment|/*      0x4a0 - 0x4a4      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat2
decl_stmt|;
comment|/*      0x4a4 - 0x4a8      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat3
decl_stmt|;
comment|/*      0x4a8 - 0x4ac      */
specifier|volatile
name|char
name|pad__13
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x4ac - 0x4b0      */
comment|/* 0x400 - 0x4b0 same as Osprey - end */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_0_b0
decl_stmt|;
comment|/*      0x4b0 - 0x4b4      */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_1_b0
decl_stmt|;
comment|/*      0x4b4 - 0x4b8      */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_2_b0
decl_stmt|;
comment|/*      0x4b8 - 0x4bc      */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_3_b0
decl_stmt|;
comment|/*      0x4bc - 0x4c0      */
specifier|volatile
name|u_int32_t
name|BB_aic_stat_0_b0
decl_stmt|;
comment|/*      0x4c0 - 0x4c4      */
specifier|volatile
name|u_int32_t
name|BB_aic_stat_1_b0
decl_stmt|;
comment|/*      0x4c4 - 0x4c8      */
specifier|volatile
name|char
name|pad__14
index|[
literal|0xf8
index|]
decl_stmt|;
comment|/*      0x4c8 - 0x5c0      */
block|}
name|Jupiter_10
struct|;
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|BB_rtt_ctrl
decl_stmt|;
comment|/*      0x380 - 0x384      */
specifier|volatile
name|u_int32_t
name|BB_rtt_table_sw_intf_b0
decl_stmt|;
comment|/*      0x384 - 0x388      */
specifier|volatile
name|u_int32_t
name|BB_rtt_table_sw_intf_1_b0
decl_stmt|;
comment|/*      0x388 - 0x38c      */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x74
index|]
decl_stmt|;
comment|/*      0x38c - 0x400      */
comment|/* 0x400 - 0x4b0 same as Osprey - start */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_0
decl_stmt|;
comment|/*      0x400 - 0x404      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_2
decl_stmt|;
comment|/*      0x404 - 0x408      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_4
decl_stmt|;
comment|/*      0x408 - 0x40c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_6
decl_stmt|;
comment|/*      0x40c - 0x410      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_8
decl_stmt|;
comment|/*      0x410 - 0x414      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_10
decl_stmt|;
comment|/*      0x414 - 0x418      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_12
decl_stmt|;
comment|/*      0x418 - 0x41c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_14
decl_stmt|;
comment|/*      0x41c - 0x420      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_16
decl_stmt|;
comment|/*      0x420 - 0x424      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_18
decl_stmt|;
comment|/*      0x424 - 0x428      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_20
decl_stmt|;
comment|/*      0x428 - 0x42c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_22
decl_stmt|;
comment|/*      0x42c - 0x430      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_24
decl_stmt|;
comment|/*      0x430 - 0x434      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_26
decl_stmt|;
comment|/*      0x434 - 0x438      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_28
decl_stmt|;
comment|/*      0x438 - 0x43c      */
specifier|volatile
name|u_int32_t
name|BB_caltx_gain_set_30
decl_stmt|;
comment|/*      0x43c - 0x440      */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x440 - 0x444      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_0
decl_stmt|;
comment|/*      0x444 - 0x448      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_1
decl_stmt|;
comment|/*      0x448 - 0x44c      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_control_2
decl_stmt|;
comment|/*      0x44c - 0x450      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_01_b0
decl_stmt|;
comment|/*      0x450 - 0x454      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_23_b0
decl_stmt|;
comment|/*      0x454 - 0x458      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_45_b0
decl_stmt|;
comment|/*      0x458 - 0x45c      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_67_b0
decl_stmt|;
comment|/*      0x45c - 0x460      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_89_b0
decl_stmt|;
comment|/*      0x460 - 0x464      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ab_b0
decl_stmt|;
comment|/*      0x464 - 0x468      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_cd_b0
decl_stmt|;
comment|/*      0x468 - 0x46c      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ef_b0
decl_stmt|;
comment|/*      0x46c - 0x470      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_0
decl_stmt|;
comment|/*      0x470 - 0x474      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_4
decl_stmt|;
comment|/*      0x474 - 0x478      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_8
decl_stmt|;
comment|/*      0x478 - 0x47c      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_12
decl_stmt|;
comment|/*      0x47c - 0x480      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_16
decl_stmt|;
comment|/*      0x480 - 0x484      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_20
decl_stmt|;
comment|/*      0x484 - 0x488      */
specifier|volatile
name|u_int32_t
name|BB_cal_rxbb_gain_tbl_24
decl_stmt|;
comment|/*      0x488 - 0x48c      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_status_b0
decl_stmt|;
comment|/*      0x48c - 0x490      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl1
decl_stmt|;
comment|/*      0x490 - 0x494      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl2
decl_stmt|;
comment|/*      0x494 - 0x498      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl3
decl_stmt|;
comment|/*      0x498 - 0x49c      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_cntl4
decl_stmt|;
comment|/*      0x49c - 0x4a0      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat1
decl_stmt|;
comment|/*      0x4a0 - 0x4a4      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat2
decl_stmt|;
comment|/*      0x4a4 - 0x4a8      */
specifier|volatile
name|u_int32_t
name|BB_paprd_trainer_stat3
decl_stmt|;
comment|/*      0x4a8 - 0x4ac      */
specifier|volatile
name|char
name|pad__13
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x4ac - 0x4b0      */
comment|/* 0x400 - 0x4b0 same as Osprey - end */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_0_b0
decl_stmt|;
comment|/*      0x4b0 - 0x4b4      */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_1_b0
decl_stmt|;
comment|/*      0x4b4 - 0x4b8      */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_2_b0
decl_stmt|;
comment|/*      0x4b8 - 0x4bc      */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_3_b0
decl_stmt|;
comment|/*      0x4bc - 0x4c0      */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_4_b0
decl_stmt|;
comment|/*      0x4c0 - 0x4c4      */
specifier|volatile
name|u_int32_t
name|BB_aic_stat_0_b0
decl_stmt|;
comment|/*      0x4c4 - 0x4c8      */
specifier|volatile
name|u_int32_t
name|BB_aic_stat_1_b0
decl_stmt|;
comment|/*      0x4c8 - 0x4cc      */
specifier|volatile
name|u_int32_t
name|BB_aic_stat_2_b0
decl_stmt|;
comment|/*      0x4cc - 0x4d0      */
specifier|volatile
name|char
name|pad__14
index|[
literal|0xf0
index|]
decl_stmt|;
comment|/*      0x4d0 - 0x5c0      */
block|}
name|Jupiter_20
struct|;
block|}
name|overlay_0xa580
union|;
specifier|volatile
name|u_int32_t
name|BB_panic_watchdog_status
decl_stmt|;
comment|/*      0x5c0 - 0x5c4      */
specifier|volatile
name|u_int32_t
name|BB_panic_watchdog_ctrl_1
decl_stmt|;
comment|/*      0x5c4 - 0x5c8      */
specifier|volatile
name|u_int32_t
name|BB_panic_watchdog_ctrl_2
decl_stmt|;
comment|/*      0x5c8 - 0x5cc      */
specifier|volatile
name|u_int32_t
name|BB_bluetooth_cntl
decl_stmt|;
comment|/*      0x5cc - 0x5d0      */
specifier|volatile
name|u_int32_t
name|BB_phyonly_warm_reset
decl_stmt|;
comment|/*      0x5d0 - 0x5d4      */
specifier|volatile
name|u_int32_t
name|BB_phyonly_control
decl_stmt|;
comment|/*      0x5d4 - 0x5d8      */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x5d8 - 0x5dc      */
specifier|volatile
name|u_int32_t
name|BB_eco_ctrl
decl_stmt|;
comment|/*      0x5dc - 0x5e0      */
specifier|volatile
name|char
name|pad__13
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*      0x5e0 - 0x5f0      */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|BB_tables_intf_addr_b0
decl_stmt|;
comment|/*      0x5f0 - 0x5f4      */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|BB_tables_intf_data_b0
decl_stmt|;
comment|/*      0x5f4 - 0x5f8      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|chn1_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_dummy_DONOTACCESS1
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x2c
index|]
decl_stmt|;
comment|/*        0x4 - 0x30       */
specifier|volatile
name|u_int32_t
name|BB_ext_chan_pwr_thr_2_b1
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x74
index|]
decl_stmt|;
comment|/*       0x34 - 0xa8       */
specifier|volatile
name|u_int32_t
name|BB_spur_report_b1
decl_stmt|;
comment|/*       0xa8 - 0xac       */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x14
index|]
decl_stmt|;
comment|/*       0xac - 0xc0       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_0_b1
decl_stmt|;
comment|/*       0xc0 - 0xc4       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_1_b1
decl_stmt|;
comment|/*       0xc4 - 0xc8       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_2_b1
decl_stmt|;
comment|/*       0xc8 - 0xcc       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_3_b1
decl_stmt|;
comment|/*       0xcc - 0xd0       */
specifier|volatile
name|u_int32_t
name|BB_tx_phase_ramp_b1
decl_stmt|;
comment|/*       0xd0 - 0xd4       */
specifier|volatile
name|u_int32_t
name|BB_adc_gain_dc_corr_b1
decl_stmt|;
comment|/*       0xd4 - 0xd8       */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xd8 - 0xdc       */
specifier|volatile
name|u_int32_t
name|BB_rx_iq_corr_b1
decl_stmt|;
comment|/*       0xdc - 0xe0       */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*       0xe0 - 0xf0       */
specifier|volatile
name|u_int32_t
name|BB_paprd_ctrl0_b1
decl_stmt|;
comment|/*       0xf0 - 0xf4       */
specifier|volatile
name|u_int32_t
name|BB_paprd_ctrl1_b1
decl_stmt|;
comment|/*       0xf4 - 0xf8       */
specifier|volatile
name|u_int32_t
name|BB_pa_gain123_b1
decl_stmt|;
comment|/*       0xf8 - 0xfc       */
specifier|volatile
name|u_int32_t
name|BB_pa_gain45_b1
decl_stmt|;
comment|/*       0xfc - 0x100      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_0_b1
decl_stmt|;
comment|/*      0x100 - 0x104      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_1_b1
decl_stmt|;
comment|/*      0x104 - 0x108      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_2_b1
decl_stmt|;
comment|/*      0x108 - 0x10c      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_3_b1
decl_stmt|;
comment|/*      0x10c - 0x110      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_4_b1
decl_stmt|;
comment|/*      0x110 - 0x114      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_5_b1
decl_stmt|;
comment|/*      0x114 - 0x118      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_6_b1
decl_stmt|;
comment|/*      0x118 - 0x11c      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_7_b1
decl_stmt|;
comment|/*      0x11c - 0x120      */
specifier|volatile
name|u_int32_t
name|BB_paprd_mem_tab_b1
index|[
literal|120
index|]
decl_stmt|;
comment|/*      0x120 - 0x300      */
specifier|volatile
name|u_int32_t
name|BB_chan_info_chan_tab_b1
index|[
literal|60
index|]
decl_stmt|;
comment|/*      0x300 - 0x3f0      */
comment|/* Jupiter_20 */
specifier|volatile
name|u_int32_t
name|BB_chn1_tables_intf_addr
decl_stmt|;
comment|/*      0x3f0 - 0x3f4      */
comment|/* Jupiter_20 */
specifier|volatile
name|u_int32_t
name|BB_chn1_tables_intf_data
decl_stmt|;
comment|/*      0x3f4 - 0x3f8      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|chn_ext_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_0_1_b0
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_1_1_b0
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_2_1_b0
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_3_1_b0
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_4_1_b0
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_5_1_b0
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_6_1_b0
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_7_1_b0
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_0_2_b0
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_1_2_b0
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_2_2_b0
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_3_2_b0
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_4_2_b0
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_5_2_b0
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_6_2_b0
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_7_2_b0
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_0_3_b0
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_1_3_b0
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_2_3_b0
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_3_3_b0
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_4_3_b0
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_5_3_b0
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_6_3_b0
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_7_3_b0
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_0_4_b0
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_1_4_b0
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_2_4_b0
decl_stmt|;
comment|/*       0x68 - 0x6c       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_3_4_b0
decl_stmt|;
comment|/*       0x6c - 0x70       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_4_4_b0
decl_stmt|;
comment|/*       0x70 - 0x74       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_5_4_b0
decl_stmt|;
comment|/*       0x74 - 0x78       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_6_4_b0
decl_stmt|;
comment|/*       0x78 - 0x7c       */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_7_4_b0
decl_stmt|;
comment|/*       0x7c - 0x80       */
specifier|volatile
name|u_int32_t
name|BB_paprd_power_at_am2am_cal_b0
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|BB_paprd_valid_obdb_b0
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x374
index|]
decl_stmt|;
comment|/*       0x88 - 0x3fc      */
specifier|volatile
name|u_int32_t
name|BB_chn_ext_dummy_2
decl_stmt|;
comment|/*      0x3fc - 0x400      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sm_ext_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_sm_ext_dummy1
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x2fc
index|]
decl_stmt|;
comment|/*        0x4 - 0x300      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_1
decl_stmt|;
comment|/*      0x300 - 0x304      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_2
decl_stmt|;
comment|/*      0x304 - 0x308      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_3
decl_stmt|;
comment|/*      0x308 - 0x30c      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_4
decl_stmt|;
comment|/*      0x30c - 0x310      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_5
decl_stmt|;
comment|/*      0x310 - 0x314      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_6
decl_stmt|;
comment|/*      0x314 - 0x318      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_7
decl_stmt|;
comment|/*      0x318 - 0x31c      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_8
decl_stmt|;
comment|/*      0x31c - 0x320      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_9
decl_stmt|;
comment|/*      0x320 - 0x324      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_10
decl_stmt|;
comment|/*      0x324 - 0x328      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_11
decl_stmt|;
comment|/*      0x328 - 0x32c      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_12
decl_stmt|;
comment|/*      0x32c - 0x330      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_13
decl_stmt|;
comment|/*      0x330 - 0x334      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_14
decl_stmt|;
comment|/*      0x334 - 0x338      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_15
decl_stmt|;
comment|/*      0x338 - 0x33c      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_16
decl_stmt|;
comment|/*      0x33c - 0x340      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_17
decl_stmt|;
comment|/*      0x340 - 0x344      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_18
decl_stmt|;
comment|/*      0x344 - 0x348      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_19
decl_stmt|;
comment|/*      0x348 - 0x34c      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_20
decl_stmt|;
comment|/*      0x34c - 0x350      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_21
decl_stmt|;
comment|/*      0x350 - 0x354      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_22
decl_stmt|;
comment|/*      0x354 - 0x358      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_23
decl_stmt|;
comment|/*      0x358 - 0x35c      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_24
decl_stmt|;
comment|/*      0x35c - 0x360      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_25
decl_stmt|;
comment|/*      0x360 - 0x364      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_26
decl_stmt|;
comment|/*      0x364 - 0x368      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_27
decl_stmt|;
comment|/*      0x368 - 0x36c      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_28
decl_stmt|;
comment|/*      0x36c - 0x370      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_29
decl_stmt|;
comment|/*      0x370 - 0x374      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_30
decl_stmt|;
comment|/*      0x374 - 0x378      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_31
decl_stmt|;
comment|/*      0x378 - 0x37c      */
specifier|volatile
name|u_int32_t
name|BB_green_tx_gain_tab_32
decl_stmt|;
comment|/*      0x37c - 0x380      */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x27c
index|]
decl_stmt|;
comment|/*      0x380 - 0x5fc      */
specifier|volatile
name|u_int32_t
name|BB_sm_ext_dummy2
decl_stmt|;
comment|/*      0x5fc - 0x600      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|agc1_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_dummy_DONOTACCESS3
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BB_gain_force_max_gains_b1
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*        0x8 - 0x18       */
specifier|volatile
name|u_int32_t
name|BB_ext_atten_switch_ctl_b1
decl_stmt|;
comment|/*       0x18 - 0x1c       */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|BB_cca_b1
decl_stmt|;
comment|/*       0x1c - 0x20       */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|BB_cca_ctrl_2_b1
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x15c
index|]
decl_stmt|;
comment|/*       0x24 - 0x180      */
specifier|volatile
name|u_int32_t
name|BB_rssi_b1
decl_stmt|;
comment|/*      0x180 - 0x184      */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|BB_spur_est_cck_report_b1
decl_stmt|;
comment|/*      0x184 - 0x188      */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|BB_agc_dig_dc_status_i_b1
decl_stmt|;
comment|/*      0x188 - 0x18c      */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|BB_agc_dig_dc_status_q_b1
decl_stmt|;
comment|/*      0x18c - 0x190      */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|BB_dc_cal_status_b1
decl_stmt|;
comment|/*      0x190 - 0x194      */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x6c
index|]
decl_stmt|;
comment|/*      0x194 - 0x200      */
specifier|volatile
name|u_int32_t
name|BB_rx_ocgain2
index|[
literal|128
index|]
decl_stmt|;
comment|/*      0x200 - 0x400      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sm1_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_dummy_DONOTACCESS5
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x80
index|]
decl_stmt|;
comment|/*        0x4 - 0x84       */
specifier|volatile
name|u_int32_t
name|BB_switch_table_chn_b1
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x48
index|]
decl_stmt|;
comment|/*       0x88 - 0xd0       */
specifier|volatile
name|u_int32_t
name|BB_fcal_2_b1
decl_stmt|;
comment|/*       0xd0 - 0xd4       */
specifier|volatile
name|u_int32_t
name|BB_dft_tone_ctrl_b1
decl_stmt|;
comment|/*       0xd4 - 0xd8       */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xd8 - 0xdc       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_0_b1
decl_stmt|;
comment|/*       0xdc - 0xe0       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_1_b1
decl_stmt|;
comment|/*       0xe0 - 0xe4       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_2_b1
decl_stmt|;
comment|/*       0xe4 - 0xe8       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_3_b1
decl_stmt|;
comment|/*       0xe8 - 0xec       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_0_b1
decl_stmt|;
comment|/*       0xec - 0xf0       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_1_b1
decl_stmt|;
comment|/*       0xf0 - 0xf4       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_2_b1
decl_stmt|;
comment|/*       0xf4 - 0xf8       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_3_b1
decl_stmt|;
comment|/*       0xf8 - 0xfc       */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xfc - 0x100      */
specifier|volatile
name|u_int32_t
name|BB_cl_tab_b1
index|[
literal|16
index|]
decl_stmt|;
comment|/*      0x100 - 0x140      */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x40
index|]
decl_stmt|;
comment|/*      0x140 - 0x180      */
specifier|volatile
name|u_int32_t
name|BB_chan_info_gain_b1
decl_stmt|;
comment|/*      0x180 - 0x184      */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x80
index|]
decl_stmt|;
comment|/*      0x184 - 0x204      */
specifier|volatile
name|u_int32_t
name|BB_tpc_4_b1
decl_stmt|;
comment|/*      0x204 - 0x208      */
specifier|volatile
name|u_int32_t
name|BB_tpc_5_b1
decl_stmt|;
comment|/*      0x208 - 0x20c      */
specifier|volatile
name|u_int32_t
name|BB_tpc_6_b1
decl_stmt|;
comment|/*      0x20c - 0x210      */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*      0x210 - 0x220      */
specifier|volatile
name|u_int32_t
name|BB_tpc_11_b1
decl_stmt|;
comment|/*      0x220 - 0x224      */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x1c
index|]
decl_stmt|;
comment|/*      0x224 - 0x240      */
union|union
block|{
specifier|volatile
name|u_int32_t
name|BB_pdadc_tab_b1
index|[
literal|32
index|]
decl_stmt|;
comment|/*      0x240 - 0x2c0      */
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|BB_tpc_19_b1
decl_stmt|;
comment|/*      0x240 - 0x244      */
specifier|volatile
name|u_int32_t
name|pad__7_1
index|[
literal|31
index|]
decl_stmt|;
comment|/*      0x244 - 0x2c0      */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x190
index|]
decl_stmt|;
comment|/*      0x2c0 - 0x450      */
block|}
name|Scorpion
struct|;
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|BB_pdadc_tab_b1
index|[
literal|32
index|]
decl_stmt|;
comment|/*      0x240 - 0x2c0      */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x190
index|]
decl_stmt|;
comment|/*      0x2c0 - 0x450      */
block|}
name|Osprey
struct|;
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|BB_tpc_19_b1
decl_stmt|;
comment|/*      0x240 - 0x244      */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x244 - 0x280      */
specifier|volatile
name|u_int32_t
name|BB_pdadc_tab_b1
index|[
literal|32
index|]
decl_stmt|;
comment|/*      0x280 - 0x300      */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x84
index|]
decl_stmt|;
comment|/*      0x300 - 0x384      */
specifier|volatile
name|u_int32_t
name|BB_rtt_table_sw_intf_b1
decl_stmt|;
comment|/*      0x384 - 0x388      */
specifier|volatile
name|u_int32_t
name|BB_rtt_table_sw_intf_1_b1
decl_stmt|;
comment|/*      0x388 - 0x38c      */
specifier|volatile
name|char
name|pad__10
index|[
literal|0xc4
index|]
decl_stmt|;
comment|/*      0x38c - 0x450      */
block|}
name|Jupiter_20
struct|;
block|}
name|overlay_b440
union|;
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_01_b1
decl_stmt|;
comment|/*      0x450 - 0x454      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_23_b1
decl_stmt|;
comment|/*      0x454 - 0x458      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_45_b1
decl_stmt|;
comment|/*      0x458 - 0x45c      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_67_b1
decl_stmt|;
comment|/*      0x45c - 0x460      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_89_b1
decl_stmt|;
comment|/*      0x460 - 0x464      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ab_b1
decl_stmt|;
comment|/*      0x464 - 0x468      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_cd_b1
decl_stmt|;
comment|/*      0x468 - 0x46c      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ef_b1
decl_stmt|;
comment|/*      0x46c - 0x470      */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x1c
index|]
decl_stmt|;
comment|/*      0x470 - 0x48c      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_status_b1
decl_stmt|;
comment|/*      0x48c - 0x490      */
specifier|volatile
name|char
name|pad__10
index|[
literal|0x20
index|]
decl_stmt|;
comment|/*      0x490 - 0x4b0      */
union|union
block|{
struct|struct
block|{
specifier|volatile
name|char
name|pad__11
index|[
literal|0x150
index|]
decl_stmt|;
comment|/*      0x4b0 - 0x600     */
block|}
name|Osprey
struct|;
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_0_b1
decl_stmt|;
comment|/*      0x4b0 - 0x4b4      */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_1_b1
decl_stmt|;
comment|/*      0x4b4 - 0x4b8      */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*      0x4b8 - 0x4c0      */
specifier|volatile
name|u_int32_t
name|BB_aic_stat_0_b1
decl_stmt|;
comment|/*      0x4c0 - 0x4c4      */
specifier|volatile
name|u_int32_t
name|BB_aic_stat_1_b1
decl_stmt|;
comment|/*      0x4c4 - 0x4c8      */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x128
index|]
decl_stmt|;
comment|/*      0x4c8 - 0x5f0      */
specifier|volatile
name|u_int32_t
name|BB_tables_intf_addr_b1
decl_stmt|;
comment|/*      0x5f0 - 0x5f4      */
specifier|volatile
name|u_int32_t
name|BB_tables_intf_data_b1
decl_stmt|;
comment|/*      0x5f4 - 0x5f8      */
specifier|volatile
name|char
name|pad__13
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*      0x5f8 - 0x600      */
block|}
name|Jupiter_10
struct|;
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_0_b1
decl_stmt|;
comment|/*      0x4b0 - 0x4b4      */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_1_b1
decl_stmt|;
comment|/*      0x4b4 - 0x4b8      */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*      0x4b8 - 0x4c0      */
specifier|volatile
name|u_int32_t
name|BB_aic_ctrl_4_b1
decl_stmt|;
comment|/*      0x4c0 - 0x4c4      */
specifier|volatile
name|u_int32_t
name|BB_aic_stat_0_b1
decl_stmt|;
comment|/*      0x4c4 - 0x4c8      */
specifier|volatile
name|u_int32_t
name|BB_aic_stat_1_b1
decl_stmt|;
comment|/*      0x4c8 - 0x4cc      */
specifier|volatile
name|u_int32_t
name|BB_aic_stat_2_b1
decl_stmt|;
comment|/*      0x4cc - 0x4d0      */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x120
index|]
decl_stmt|;
comment|/*      0x4d0 - 0x5f0      */
specifier|volatile
name|u_int32_t
name|BB_tables_intf_addr_b1
decl_stmt|;
comment|/*      0x5f0 - 0x5f4      */
specifier|volatile
name|u_int32_t
name|BB_tables_intf_data_b1
decl_stmt|;
comment|/*      0x5f4 - 0x5f8      */
specifier|volatile
name|char
name|pad__13
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*      0x5f8 - 0x600      */
block|}
name|Jupiter_20
struct|;
block|}
name|overlay_0x4b0
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|chn2_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_dummy_DONOTACCESS2
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x2c
index|]
decl_stmt|;
comment|/*        0x4 - 0x30       */
specifier|volatile
name|u_int32_t
name|BB_ext_chan_pwr_thr_2_b2
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x74
index|]
decl_stmt|;
comment|/*       0x34 - 0xa8       */
specifier|volatile
name|u_int32_t
name|BB_spur_report_b2
decl_stmt|;
comment|/*       0xa8 - 0xac       */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x14
index|]
decl_stmt|;
comment|/*       0xac - 0xc0       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_0_b2
decl_stmt|;
comment|/*       0xc0 - 0xc4       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_1_b2
decl_stmt|;
comment|/*       0xc4 - 0xc8       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_2_b2
decl_stmt|;
comment|/*       0xc8 - 0xcc       */
specifier|volatile
name|u_int32_t
name|BB_iq_adc_meas_3_b2
decl_stmt|;
comment|/*       0xcc - 0xd0       */
specifier|volatile
name|u_int32_t
name|BB_tx_phase_ramp_b2
decl_stmt|;
comment|/*       0xd0 - 0xd4       */
specifier|volatile
name|u_int32_t
name|BB_adc_gain_dc_corr_b2
decl_stmt|;
comment|/*       0xd4 - 0xd8       */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xd8 - 0xdc       */
specifier|volatile
name|u_int32_t
name|BB_rx_iq_corr_b2
decl_stmt|;
comment|/*       0xdc - 0xe0       */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*       0xe0 - 0xf0       */
specifier|volatile
name|u_int32_t
name|BB_paprd_ctrl0_b2
decl_stmt|;
comment|/*       0xf0 - 0xf4       */
specifier|volatile
name|u_int32_t
name|BB_paprd_ctrl1_b2
decl_stmt|;
comment|/*       0xf4 - 0xf8       */
specifier|volatile
name|u_int32_t
name|BB_pa_gain123_b2
decl_stmt|;
comment|/*       0xf8 - 0xfc       */
specifier|volatile
name|u_int32_t
name|BB_pa_gain45_b2
decl_stmt|;
comment|/*       0xfc - 0x100      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_0_b2
decl_stmt|;
comment|/*      0x100 - 0x104      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_1_b2
decl_stmt|;
comment|/*      0x104 - 0x108      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_2_b2
decl_stmt|;
comment|/*      0x108 - 0x10c      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_3_b2
decl_stmt|;
comment|/*      0x10c - 0x110      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_4_b2
decl_stmt|;
comment|/*      0x110 - 0x114      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_5_b2
decl_stmt|;
comment|/*      0x114 - 0x118      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_6_b2
decl_stmt|;
comment|/*      0x118 - 0x11c      */
specifier|volatile
name|u_int32_t
name|BB_paprd_pre_post_scale_7_b2
decl_stmt|;
comment|/*      0x11c - 0x120      */
specifier|volatile
name|u_int32_t
name|BB_paprd_mem_tab_b2
index|[
literal|120
index|]
decl_stmt|;
comment|/*      0x120 - 0x300      */
specifier|volatile
name|u_int32_t
name|BB_chan_info_chan_tab_b2
index|[
literal|60
index|]
decl_stmt|;
comment|/*      0x300 - 0x3f0      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|agc2_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_dummy_DONOTACCESS4
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BB_gain_force_max_gains_b2
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*        0x8 - 0x18       */
specifier|volatile
name|u_int32_t
name|BB_ext_atten_switch_ctl_b2
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|BB_cca_b2
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|BB_cca_ctrl_2_b2
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x15c
index|]
decl_stmt|;
comment|/*       0x24 - 0x180      */
specifier|volatile
name|u_int32_t
name|BB_rssi_b2
decl_stmt|;
comment|/*      0x180 - 0x184      */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x184 - 0x188      */
specifier|volatile
name|u_int32_t
name|BB_agc_dig_dc_status_i_b2
decl_stmt|;
comment|/*      0x188 - 0x18c      */
specifier|volatile
name|u_int32_t
name|BB_agc_dig_dc_status_q_b2
decl_stmt|;
comment|/*      0x18c - 0x190      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sm2_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_dummy_DONOTACCESS6
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x80
index|]
decl_stmt|;
comment|/*        0x4 - 0x84       */
specifier|volatile
name|u_int32_t
name|BB_switch_table_chn_b2
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x48
index|]
decl_stmt|;
comment|/*       0x88 - 0xd0       */
specifier|volatile
name|u_int32_t
name|BB_fcal_2_b2
decl_stmt|;
comment|/*       0xd0 - 0xd4       */
specifier|volatile
name|u_int32_t
name|BB_dft_tone_ctrl_b2
decl_stmt|;
comment|/*       0xd4 - 0xd8       */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xd8 - 0xdc       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_0_b2
decl_stmt|;
comment|/*       0xdc - 0xe0       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_1_b2
decl_stmt|;
comment|/*       0xe0 - 0xe4       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_2_b2
decl_stmt|;
comment|/*       0xe4 - 0xe8       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_3_b2
decl_stmt|;
comment|/*       0xe8 - 0xec       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_0_b2
decl_stmt|;
comment|/*       0xec - 0xf0       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_1_b2
decl_stmt|;
comment|/*       0xf0 - 0xf4       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_2_b2
decl_stmt|;
comment|/*       0xf4 - 0xf8       */
specifier|volatile
name|u_int32_t
name|BB_cl_map_pal_3_b2
decl_stmt|;
comment|/*       0xf8 - 0xfc       */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xfc - 0x100      */
specifier|volatile
name|u_int32_t
name|BB_cl_tab_b2
index|[
literal|16
index|]
decl_stmt|;
comment|/*      0x100 - 0x140      */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x40
index|]
decl_stmt|;
comment|/*      0x140 - 0x180      */
specifier|volatile
name|u_int32_t
name|BB_chan_info_gain_b2
decl_stmt|;
comment|/*      0x180 - 0x184      */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x80
index|]
decl_stmt|;
comment|/*      0x184 - 0x204      */
specifier|volatile
name|u_int32_t
name|BB_tpc_4_b2
decl_stmt|;
comment|/*      0x204 - 0x208      */
specifier|volatile
name|u_int32_t
name|BB_tpc_5_b2
decl_stmt|;
comment|/*      0x208 - 0x20c      */
specifier|volatile
name|u_int32_t
name|BB_tpc_6_b2
decl_stmt|;
comment|/*      0x20c - 0x210      */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*      0x210 - 0x220      */
specifier|volatile
name|u_int32_t
name|BB_tpc_11_b2
decl_stmt|;
comment|/*      0x220 - 0x224      */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x1c
index|]
decl_stmt|;
comment|/*      0x224 - 0x240      */
union|union
block|{
specifier|volatile
name|u_int32_t
name|BB_pdadc_tab_b2
index|[
literal|32
index|]
decl_stmt|;
comment|/*      0x240 - 0x2c0      */
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|BB_tpc_19_b2
decl_stmt|;
comment|/*      0x240 - 0x244      */
specifier|volatile
name|u_int32_t
name|pad__7_1
index|[
literal|31
index|]
decl_stmt|;
comment|/*      0x244 - 0x2c0      */
block|}
name|Scorpion
struct|;
block|}
name|overlay_c440
union|;
specifier|volatile
name|char
name|pad__8
index|[
literal|0x190
index|]
decl_stmt|;
comment|/*      0x2c0 - 0x450      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_01_b2
decl_stmt|;
comment|/*      0x450 - 0x454      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_23_b2
decl_stmt|;
comment|/*      0x454 - 0x458      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_45_b2
decl_stmt|;
comment|/*      0x458 - 0x45c      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_67_b2
decl_stmt|;
comment|/*      0x45c - 0x460      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_89_b2
decl_stmt|;
comment|/*      0x460 - 0x464      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ab_b2
decl_stmt|;
comment|/*      0x464 - 0x468      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_cd_b2
decl_stmt|;
comment|/*      0x468 - 0x46c      */
specifier|volatile
name|u_int32_t
name|BB_txiq_corr_coeff_ef_b2
decl_stmt|;
comment|/*      0x46c - 0x470      */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x1c
index|]
decl_stmt|;
comment|/*      0x470 - 0x48c      */
specifier|volatile
name|u_int32_t
name|BB_txiqcal_status_b2
decl_stmt|;
comment|/*      0x48c - 0x490      */
specifier|volatile
name|char
name|pad__10
index|[
literal|0x16c
index|]
decl_stmt|;
comment|/*      0x490 - 0x5fc      */
specifier|volatile
name|u_int32_t
name|BB_dummy_sm2
decl_stmt|;
comment|/*      0x5fc - 0x600      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|chn3_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_dummy1
index|[
literal|256
index|]
decl_stmt|;
comment|/*        0x0 - 0x400      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|agc3_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_dummy
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x17c
index|]
decl_stmt|;
comment|/*        0x4 - 0x180      */
specifier|volatile
name|u_int32_t
name|BB_rssi_b3
decl_stmt|;
comment|/*      0x180 - 0x184      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sm3_reg_map
block|{
specifier|volatile
name|u_int32_t
name|BB_dummy2
index|[
literal|384
index|]
decl_stmt|;
comment|/*        0x0 - 0x600      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bb_reg_map
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x9800
index|]
decl_stmt|;
comment|/*        0x0 - 0x9800     */
name|struct
name|chn_reg_map
name|bb_chn_reg_map
decl_stmt|;
comment|/*     0x9800 - 0x9bf8     */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*     0x9bf8 - 0x9c00     */
name|struct
name|mrc_reg_map
name|bb_mrc_reg_map
decl_stmt|;
comment|/*     0x9c00 - 0x9c24     */
specifier|volatile
name|char
name|pad__2
index|[
literal|0xdc
index|]
decl_stmt|;
comment|/*     0x9c24 - 0x9d00     */
name|struct
name|bbb_reg_map
name|bb_bbb_reg_map
decl_stmt|;
comment|/*     0x9d00 - 0x9d20     */
specifier|volatile
name|char
name|pad__3
index|[
literal|0xe0
index|]
decl_stmt|;
comment|/*     0x9d20 - 0x9e00     */
name|struct
name|agc_reg_map
name|bb_agc_reg_map
decl_stmt|;
comment|/*     0x9e00 - 0xa200     */
name|struct
name|sm_reg_map
name|bb_sm_reg_map
decl_stmt|;
comment|/*     0xa200 - 0xa7f8     */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*     0xa7f8 - 0xa800     */
union|union
block|{
struct|struct
block|{
name|struct
name|chn1_reg_map
name|bb_chn1_reg_map
decl_stmt|;
comment|/*     0xa800 - 0xabf8     */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x208
index|]
decl_stmt|;
comment|/*     0xabf8 - 0xae00     */
name|struct
name|agc1_reg_map
name|bb_agc1_reg_map
decl_stmt|;
comment|/*     0xae00 - 0xb200     */
name|struct
name|sm1_reg_map
name|bb_sm1_reg_map
decl_stmt|;
comment|/*     0xb200 - 0xb800     */
name|struct
name|chn2_reg_map
name|bb_chn2_reg_map
decl_stmt|;
comment|/*     0xb800 - 0xbbf0     */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x210
index|]
decl_stmt|;
comment|/*     0xbbf0 - 0xbe00     */
name|struct
name|agc2_reg_map
name|bb_agc2_reg_map
decl_stmt|;
comment|/*     0xbe00 - 0xbf90     */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x270
index|]
decl_stmt|;
comment|/*     0xbf90 - 0xc200     */
name|struct
name|sm2_reg_map
name|bb_sm2_reg_map
decl_stmt|;
comment|/*     0xc200 - 0xc800     */
block|}
name|Osprey
struct|;
struct|struct
block|{
name|struct
name|chn_ext_reg_map
name|bb_chn_ext_reg_map
decl_stmt|;
comment|/*     0xa800 - 0xac00     */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x600
index|]
decl_stmt|;
comment|/*     0xac00 - 0xb200     */
name|struct
name|sm_ext_reg_map
name|bb_sm_ext_reg_map
decl_stmt|;
comment|/*     0xb200 - 0xb800     */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x600
index|]
decl_stmt|;
comment|/*     0xb800 - 0xbe00     */
name|struct
name|agc1_reg_map
name|bb_agc1_reg_map
decl_stmt|;
comment|/*     0xbe00 - 0xc1fc     */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0xc1fc - 0xc200     */
name|struct
name|sm1_reg_map
name|bb_sm1_reg_map
decl_stmt|;
comment|/*     0xc200 - 0xc800     */
block|}
name|Poseidon
struct|;
block|}
name|overlay_0xa800
union|;
name|struct
name|chn3_reg_map
name|bb_chn3_reg_map
decl_stmt|;
comment|/*     0xc800 - 0xcc00     */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x200
index|]
decl_stmt|;
comment|/*     0xcc00 - 0xce00     */
name|struct
name|agc3_reg_map
name|bb_agc3_reg_map
decl_stmt|;
comment|/*     0xce00 - 0xcf84     */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x27c
index|]
decl_stmt|;
comment|/*     0xcf84 - 0xd200     */
name|struct
name|sm3_reg_map
name|bb_sm3_reg_map
decl_stmt|;
comment|/*     0xd200 - 0xd800     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svd_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x10000
index|]
decl_stmt|;
comment|/*        0x0 - 0x10000    */
specifier|volatile
name|u_int32_t
name|TXBF_DBG
decl_stmt|;
comment|/*    0x10000 - 0x10004    */
specifier|volatile
name|u_int32_t
name|TXBF
decl_stmt|;
comment|/*    0x10004 - 0x10008    */
specifier|volatile
name|u_int32_t
name|TXBF_TIMER
decl_stmt|;
comment|/*    0x10008 - 0x1000c    */
specifier|volatile
name|u_int32_t
name|TXBF_SW
decl_stmt|;
comment|/*    0x1000c - 0x10010    */
specifier|volatile
name|u_int32_t
name|TXBF_SM
decl_stmt|;
comment|/*    0x10010 - 0x10014    */
specifier|volatile
name|u_int32_t
name|TXBF1_CNTL
decl_stmt|;
comment|/*    0x10014 - 0x10018    */
specifier|volatile
name|u_int32_t
name|TXBF2_CNTL
decl_stmt|;
comment|/*    0x10018 - 0x1001c    */
specifier|volatile
name|u_int32_t
name|TXBF3_CNTL
decl_stmt|;
comment|/*    0x1001c - 0x10020    */
specifier|volatile
name|u_int32_t
name|TXBF4_CNTL
decl_stmt|;
comment|/*    0x10020 - 0x10024    */
specifier|volatile
name|u_int32_t
name|TXBF5_CNTL
decl_stmt|;
comment|/*    0x10024 - 0x10028    */
specifier|volatile
name|u_int32_t
name|TXBF6_CNTL
decl_stmt|;
comment|/*    0x10028 - 0x1002c    */
specifier|volatile
name|u_int32_t
name|TXBF7_CNTL
decl_stmt|;
comment|/*    0x1002c - 0x10030    */
specifier|volatile
name|u_int32_t
name|TXBF8_CNTL
decl_stmt|;
comment|/*    0x10030 - 0x10034    */
specifier|volatile
name|char
name|pad__1
index|[
literal|0xfcc
index|]
decl_stmt|;
comment|/*    0x10034 - 0x11000    */
specifier|volatile
name|u_int32_t
name|RC0
index|[
literal|118
index|]
decl_stmt|;
comment|/*    0x11000 - 0x111d8    */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x28
index|]
decl_stmt|;
comment|/*    0x111d8 - 0x11200    */
specifier|volatile
name|u_int32_t
name|RC1
index|[
literal|118
index|]
decl_stmt|;
comment|/*    0x11200 - 0x113d8    */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x28
index|]
decl_stmt|;
comment|/*    0x113d8 - 0x11400    */
specifier|volatile
name|u_int32_t
name|SVD_MEM0
index|[
literal|114
index|]
decl_stmt|;
comment|/*    0x11400 - 0x115c8    */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*    0x115c8 - 0x11600    */
specifier|volatile
name|u_int32_t
name|SVD_MEM1
index|[
literal|114
index|]
decl_stmt|;
comment|/*    0x11600 - 0x117c8    */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*    0x117c8 - 0x11800    */
specifier|volatile
name|u_int32_t
name|SVD_MEM2
index|[
literal|114
index|]
decl_stmt|;
comment|/*    0x11800 - 0x119c8    */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*    0x119c8 - 0x11a00    */
specifier|volatile
name|u_int32_t
name|SVD_MEM3
index|[
literal|114
index|]
decl_stmt|;
comment|/*    0x11a00 - 0x11bc8    */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*    0x11bc8 - 0x11c00    */
specifier|volatile
name|u_int32_t
name|SVD_MEM4
index|[
literal|114
index|]
decl_stmt|;
comment|/*    0x11c00 - 0x11dc8    */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x638
index|]
decl_stmt|;
comment|/*    0x11dc8 - 0x12400    */
specifier|volatile
name|u_int32_t
name|CVCACHE
index|[
literal|512
index|]
decl_stmt|;
comment|/*    0x12400 - 0x12c00    */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|efuse_reg_WLAN
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x14000
index|]
decl_stmt|;
comment|/*        0x0 - 0x14000    */
specifier|volatile
name|u_int32_t
name|OTP_MEM
index|[
literal|256
index|]
decl_stmt|;
comment|/*    0x14000 - 0x14400    */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x1b00
index|]
decl_stmt|;
comment|/*    0x14400 - 0x15f00    */
specifier|volatile
name|u_int32_t
name|OTP_INTF0
decl_stmt|;
comment|/*    0x15f00 - 0x15f04    */
specifier|volatile
name|u_int32_t
name|OTP_INTF1
decl_stmt|;
comment|/*    0x15f04 - 0x15f08    */
specifier|volatile
name|u_int32_t
name|OTP_INTF2
decl_stmt|;
comment|/*    0x15f08 - 0x15f0c    */
specifier|volatile
name|u_int32_t
name|OTP_INTF3
decl_stmt|;
comment|/*    0x15f0c - 0x15f10    */
specifier|volatile
name|u_int32_t
name|OTP_INTF4
decl_stmt|;
comment|/*    0x15f10 - 0x15f14    */
specifier|volatile
name|u_int32_t
name|OTP_INTF5
decl_stmt|;
comment|/*    0x15f14 - 0x15f18    */
specifier|volatile
name|u_int32_t
name|OTP_STATUS0
decl_stmt|;
comment|/*    0x15f18 - 0x15f1c    */
specifier|volatile
name|u_int32_t
name|OTP_STATUS1
decl_stmt|;
comment|/*    0x15f1c - 0x15f20    */
specifier|volatile
name|u_int32_t
name|OTP_INTF6
decl_stmt|;
comment|/*    0x15f20 - 0x15f24    */
specifier|volatile
name|u_int32_t
name|OTP_LDO_CONTROL
decl_stmt|;
comment|/*    0x15f24 - 0x15f28    */
specifier|volatile
name|u_int32_t
name|OTP_LDO_POWER_GOOD
decl_stmt|;
comment|/*    0x15f28 - 0x15f2c    */
specifier|volatile
name|u_int32_t
name|OTP_LDO_STATUS
decl_stmt|;
comment|/*    0x15f2c - 0x15f30    */
specifier|volatile
name|u_int32_t
name|OTP_VDDQ_HOLD_TIME
decl_stmt|;
comment|/*    0x15f30 - 0x15f34    */
specifier|volatile
name|u_int32_t
name|OTP_PGENB_SETUP_HOLD_TIME
decl_stmt|;
comment|/*    0x15f34 - 0x15f38    */
specifier|volatile
name|u_int32_t
name|OTP_STROBE_PULSE_INTERVAL
decl_stmt|;
comment|/*    0x15f38 - 0x15f3c    */
specifier|volatile
name|u_int32_t
name|OTP_CSB_ADDR_LOAD_SETUP_HOLD
decl_stmt|;
comment|/*    0x15f3c - 0x15f40    */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|radio65_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x16000
index|]
decl_stmt|;
comment|/*        0x0 - 0x16000    */
specifier|volatile
name|u_int32_t
name|ch0_RXRF_BIAS1
decl_stmt|;
comment|/*    0x16000 - 0x16004    */
specifier|volatile
name|u_int32_t
name|ch0_RXRF_BIAS2
decl_stmt|;
comment|/*    0x16004 - 0x16008    */
specifier|volatile
name|u_int32_t
name|ch0_RXRF_GAINSTAGES
decl_stmt|;
comment|/*    0x16008 - 0x1600c    */
specifier|volatile
name|u_int32_t
name|ch0_RXRF_AGC
decl_stmt|;
comment|/*    0x1600c - 0x16010    */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|ch0_RXRF_BIAS3
decl_stmt|;
comment|/*    0x16010 - 0x16014    */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x2c
index|]
decl_stmt|;
comment|/*    0x16014 - 0x16040    */
specifier|volatile
name|u_int32_t
name|ch0_TXRF1
decl_stmt|;
comment|/*    0x16040 - 0x16044    */
specifier|volatile
name|u_int32_t
name|ch0_TXRF2
decl_stmt|;
comment|/*    0x16044 - 0x16048    */
specifier|volatile
name|u_int32_t
name|ch0_TXRF3
decl_stmt|;
comment|/*    0x16048 - 0x1604c    */
specifier|volatile
name|u_int32_t
name|ch0_TXRF4
decl_stmt|;
comment|/*    0x1604c - 0x16050    */
specifier|volatile
name|u_int32_t
name|ch0_TXRF5
decl_stmt|;
comment|/*    0x16050 - 0x16054    */
specifier|volatile
name|u_int32_t
name|ch0_TXRF6
decl_stmt|;
comment|/*    0x16054 - 0x16058    */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|ch0_TXRF7
decl_stmt|;
comment|/*    0x16058 - 0x1605c    */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|ch0_TXRF8
decl_stmt|;
comment|/*    0x1605c - 0x16060    */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|ch0_TXRF9
decl_stmt|;
comment|/*    0x16060 - 0x16064    */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|ch0_TXRF10
decl_stmt|;
comment|/*    0x16064 - 0x16068    */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|ch0_TXRF11
decl_stmt|;
comment|/*    0x16068 - 0x1606c    */
comment|/* Not Poseidon */
specifier|volatile
name|u_int32_t
name|ch0_TXRF12
decl_stmt|;
comment|/*    0x1606c - 0x16070    */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*    0x16070 - 0x16080    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH1
decl_stmt|;
comment|/*    0x16080 - 0x16084    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH2
decl_stmt|;
comment|/*    0x16084 - 0x16088    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH3
decl_stmt|;
comment|/*    0x16088 - 0x1608c    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH4
decl_stmt|;
comment|/*    0x1608c - 0x16090    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH5
decl_stmt|;
comment|/*    0x16090 - 0x16094    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH6
decl_stmt|;
comment|/*    0x16094 - 0x16098    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH7
decl_stmt|;
comment|/*    0x16098 - 0x1609c    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH8
decl_stmt|;
comment|/*    0x1609c - 0x160a0    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH9
decl_stmt|;
comment|/*    0x160a0 - 0x160a4    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH10
decl_stmt|;
comment|/*    0x160a4 - 0x160a8    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH11
decl_stmt|;
comment|/*    0x160a8 - 0x160ac    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH12
decl_stmt|;
comment|/*    0x160ac - 0x160b0    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH13
decl_stmt|;
comment|/*    0x160b0 - 0x160b4    */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH14
decl_stmt|;
comment|/*    0x160b4 - 0x160b8    */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH15
decl_stmt|;
comment|/*    0x160b8 - 0x160bc    */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH16
decl_stmt|;
comment|/*    0x160bc - 0x160c0    */
specifier|volatile
name|u_int32_t
name|ch0_BIAS1
decl_stmt|;
comment|/*    0x160c0 - 0x160c4    */
specifier|volatile
name|u_int32_t
name|ch0_BIAS2
decl_stmt|;
comment|/*    0x160c4 - 0x160c8    */
specifier|volatile
name|u_int32_t
name|ch0_BIAS3
decl_stmt|;
comment|/*    0x160c8 - 0x160cc    */
specifier|volatile
name|u_int32_t
name|ch0_BIAS4
decl_stmt|;
comment|/*    0x160cc - 0x160d0    */
comment|/* Poseidon */
specifier|volatile
name|u_int32_t
name|ch0_BIAS5
decl_stmt|;
comment|/*    0x160d0 - 0x160d4    */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x2c
index|]
decl_stmt|;
comment|/*    0x160d4 - 0x16100    */
specifier|volatile
name|u_int32_t
name|ch0_RXTX1
decl_stmt|;
comment|/*    0x16100 - 0x16104    */
specifier|volatile
name|u_int32_t
name|ch0_RXTX2
decl_stmt|;
comment|/*    0x16104 - 0x16108    */
specifier|volatile
name|u_int32_t
name|ch0_RXTX3
decl_stmt|;
comment|/*    0x16108 - 0x1610c    */
specifier|volatile
name|u_int32_t
name|ch0_RXTX4
decl_stmt|;
comment|/*    0x1610c - 0x16110    */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|ch0_RXTX5
decl_stmt|;
comment|/*    0x16110 - 0x16114    */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x2c
index|]
decl_stmt|;
comment|/*    0x16114 - 0x16140    */
specifier|volatile
name|u_int32_t
name|ch0_BB1
decl_stmt|;
comment|/*    0x16140 - 0x16144    */
specifier|volatile
name|u_int32_t
name|ch0_BB2
decl_stmt|;
comment|/*    0x16144 - 0x16148    */
specifier|volatile
name|u_int32_t
name|ch0_BB3
decl_stmt|;
comment|/*    0x16148 - 0x1614c    */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x34
index|]
decl_stmt|;
comment|/*    0x1614c - 0x16180    */
union|union
block|{
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|ch0_pll_cntl
decl_stmt|;
comment|/*    0x16180 - 0x16184    */
specifier|volatile
name|u_int32_t
name|ch0_pll_mode
decl_stmt|;
comment|/*    0x16184 - 0x16188    */
specifier|volatile
name|u_int32_t
name|ch0_bb_dpll3
decl_stmt|;
comment|/*    0x16188 - 0x1618c    */
specifier|volatile
name|u_int32_t
name|ch0_bb_dpll4
decl_stmt|;
comment|/*    0x1618c - 0x16190    */
specifier|volatile
name|char
name|pad__6_1
index|[
literal|0xf0
index|]
decl_stmt|;
comment|/*    0x16190 - 0x16280    */
specifier|volatile
name|u_int32_t
name|ch0_PLLCLKMODA
decl_stmt|;
comment|/*    0x16280 - 0x16284    */
specifier|volatile
name|u_int32_t
name|ch0_PLLCLKMODA2
decl_stmt|;
comment|/*    0x16284 - 0x16288    */
specifier|volatile
name|u_int32_t
name|ch0_TOP
decl_stmt|;
comment|/*    0x16288 - 0x1628c    */
specifier|volatile
name|u_int32_t
name|ch0_TOP2
decl_stmt|;
comment|/*    0x1628c - 0x16290    */
specifier|volatile
name|u_int32_t
name|ch0_THERM
decl_stmt|;
comment|/*    0x16290 - 0x16294    */
specifier|volatile
name|u_int32_t
name|ch0_XTAL
decl_stmt|;
comment|/*    0x16294 - 0x16298    */
specifier|volatile
name|char
name|pad__7
index|[
literal|0xe8
index|]
decl_stmt|;
comment|/*    0x16298 - 0x16380    */
block|}
name|Osprey
struct|;
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|ch0_BB_DPLL1
decl_stmt|;
comment|/*    0x16180 - 0x16184    */
specifier|volatile
name|u_int32_t
name|ch0_BB_DPLL2
decl_stmt|;
comment|/*    0x16184 - 0x16188    */
specifier|volatile
name|u_int32_t
name|ch0_BB_DPLL3
decl_stmt|;
comment|/*    0x16188 - 0x1618c    */
specifier|volatile
name|u_int32_t
name|ch0_BB_DPLL4
decl_stmt|;
comment|/*    0x1618c - 0x16190    */
specifier|volatile
name|char
name|pad__7
index|[
literal|0xb0
index|]
decl_stmt|;
comment|/*    0x16190 - 0x16240    */
specifier|volatile
name|u_int32_t
name|ch0_DDR_DPLL1
decl_stmt|;
comment|/*    0x16240 - 0x16244    */
specifier|volatile
name|u_int32_t
name|ch0_DDR_DPLL2
decl_stmt|;
comment|/*    0x16244 - 0x16248    */
specifier|volatile
name|u_int32_t
name|ch0_DDR_DPLL3
decl_stmt|;
comment|/*    0x16248 - 0x1624c    */
specifier|volatile
name|u_int32_t
name|ch0_DDR_DPLL4
decl_stmt|;
comment|/*    0x1624c - 0x16250    */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*    0x16250 - 0x16280    */
specifier|volatile
name|u_int32_t
name|ch0_TOP
decl_stmt|;
comment|/*    0x16280 - 0x16284    */
specifier|volatile
name|u_int32_t
name|ch0_TOP2
decl_stmt|;
comment|/*    0x16284 - 0x16288    */
specifier|volatile
name|u_int32_t
name|ch0_TOP3
decl_stmt|;
comment|/*    0x16288 - 0x1628c    */
specifier|volatile
name|u_int32_t
name|ch0_THERM
decl_stmt|;
comment|/*    0x1628c - 0x16290    */
specifier|volatile
name|u_int32_t
name|ch0_XTAL
decl_stmt|;
comment|/*    0x16290 - 0x16294    */
specifier|volatile
name|char
name|pad__9
index|[
literal|0xec
index|]
decl_stmt|;
comment|/*    0x16294 - 0x16380    */
block|}
name|Poseidon
struct|;
struct|struct
block|{
specifier|volatile
name|char
name|pad__6_1
index|[
literal|0x100
index|]
decl_stmt|;
comment|/*    0x16180 - 0x16280    */
specifier|volatile
name|u_int32_t
name|ch0_PLLCLKMODA1
decl_stmt|;
comment|/*    0x16280 - 0x16284    */
specifier|volatile
name|u_int32_t
name|ch0_PLLCLKMODA2
decl_stmt|;
comment|/*    0x16284 - 0x16288    */
specifier|volatile
name|u_int32_t
name|ch0_PLLCLKMODA3
decl_stmt|;
comment|/*    0x16288 - 0x1628c    */
specifier|volatile
name|u_int32_t
name|ch0_TOP1
decl_stmt|;
comment|/*    0x1628c - 0x16290    */
specifier|volatile
name|u_int32_t
name|ch0_TOP2
decl_stmt|;
comment|/*    0x16290 - 0x16294    */
specifier|volatile
name|u_int32_t
name|ch0_THERM
decl_stmt|;
comment|/*    0x16294 - 0x16298    */
specifier|volatile
name|u_int32_t
name|ch0_XTAL
decl_stmt|;
comment|/*    0x16298 - 0x1629c    */
specifier|volatile
name|char
name|pad__7
index|[
literal|0xa4
index|]
decl_stmt|;
comment|/*    0x1629c - 0x16340    */
specifier|volatile
name|u_int32_t
name|ch0_PMU1
decl_stmt|;
comment|/*    0x16340 - 0x16344    */
specifier|volatile
name|u_int32_t
name|ch0_PMU2
decl_stmt|;
comment|/*    0x16344 - 0x16348    */
specifier|volatile
name|u_int32_t
name|ch0_PMU3
decl_stmt|;
comment|/*    0x16348 - 0x1634c    */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x34
index|]
decl_stmt|;
comment|/*    0x1634c - 0x16380    */
block|}
name|Jupiter
struct|;
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|ch0_DPLL
decl_stmt|;
comment|/*    0x16180 - 0x16184    */
specifier|volatile
name|u_int32_t
name|ch0_DPLL2
decl_stmt|;
comment|/*    0x16184 - 0x16188    */
specifier|volatile
name|u_int32_t
name|ch0_DPLL3
decl_stmt|;
comment|/*    0x16188 - 0x1618c    */
specifier|volatile
name|u_int32_t
name|ch0_DPLL4
decl_stmt|;
comment|/*    0x1618c - 0x16190    */
specifier|volatile
name|u_int32_t
name|ch0_DPLL5
decl_stmt|;
comment|/*    0x16190 - 0x16194    */
specifier|volatile
name|char
name|pad__6
index|[
literal|0xec
index|]
decl_stmt|;
comment|/*    0x16194 - 0x16280    */
specifier|volatile
name|u_int32_t
name|ch0_PLLCLKMODA1
decl_stmt|;
comment|/*    0x16280 - 0x16284    */
specifier|volatile
name|u_int32_t
name|ch0_PLLCLKMODA2
decl_stmt|;
comment|/*    0x16284 - 0x16288    */
specifier|volatile
name|u_int32_t
name|ch0_PLLCLKMODA3
decl_stmt|;
comment|/*    0x16288 - 0x1628c    */
specifier|volatile
name|u_int32_t
name|ch0_TOP1
decl_stmt|;
comment|/*    0x1628c - 0x16290    */
specifier|volatile
name|u_int32_t
name|ch0_TOP2
decl_stmt|;
comment|/*    0x16290 - 0x16294    */
specifier|volatile
name|u_int32_t
name|ch0_THERM
decl_stmt|;
comment|/*    0x16294 - 0x16298    */
specifier|volatile
name|u_int32_t
name|ch0_XTAL
decl_stmt|;
comment|/*    0x16298 - 0x1629c    */
specifier|volatile
name|char
name|pad__7
index|[
literal|0xa4
index|]
decl_stmt|;
comment|/*    0x1629c - 0x16340    */
specifier|volatile
name|u_int32_t
name|ch0_PMU1
decl_stmt|;
comment|/*    0x16340 - 0x16344    */
specifier|volatile
name|u_int32_t
name|ch0_PMU2
decl_stmt|;
comment|/*    0x16344 - 0x16348    */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*    0x16348 - 0x16380    */
block|}
name|Aphrodite
struct|;
block|}
name|overlay_0x16180
union|;
specifier|volatile
name|u_int32_t
name|ch0_rbist_cntrl
decl_stmt|;
comment|/*    0x16380 - 0x16384    */
specifier|volatile
name|u_int32_t
name|ch0_tx_dc_offset
decl_stmt|;
comment|/*    0x16384 - 0x16388    */
specifier|volatile
name|u_int32_t
name|ch0_tx_tonegen0
decl_stmt|;
comment|/*    0x16388 - 0x1638c    */
specifier|volatile
name|u_int32_t
name|ch0_tx_tonegen1
decl_stmt|;
comment|/*    0x1638c - 0x16390    */
specifier|volatile
name|u_int32_t
name|ch0_tx_lftonegen0
decl_stmt|;
comment|/*    0x16390 - 0x16394    */
specifier|volatile
name|u_int32_t
name|ch0_tx_linear_ramp_i
decl_stmt|;
comment|/*    0x16394 - 0x16398    */
specifier|volatile
name|u_int32_t
name|ch0_tx_linear_ramp_q
decl_stmt|;
comment|/*    0x16398 - 0x1639c    */
specifier|volatile
name|u_int32_t
name|ch0_tx_prbs_mag
decl_stmt|;
comment|/*    0x1639c - 0x163a0    */
specifier|volatile
name|u_int32_t
name|ch0_tx_prbs_seed_i
decl_stmt|;
comment|/*    0x163a0 - 0x163a4    */
specifier|volatile
name|u_int32_t
name|ch0_tx_prbs_seed_q
decl_stmt|;
comment|/*    0x163a4 - 0x163a8    */
specifier|volatile
name|u_int32_t
name|ch0_cmac_dc_cancel
decl_stmt|;
comment|/*    0x163a8 - 0x163ac    */
specifier|volatile
name|u_int32_t
name|ch0_cmac_dc_offset
decl_stmt|;
comment|/*    0x163ac - 0x163b0    */
specifier|volatile
name|u_int32_t
name|ch0_cmac_corr
decl_stmt|;
comment|/*    0x163b0 - 0x163b4    */
specifier|volatile
name|u_int32_t
name|ch0_cmac_power
decl_stmt|;
comment|/*    0x163b4 - 0x163b8    */
specifier|volatile
name|u_int32_t
name|ch0_cmac_cross_corr
decl_stmt|;
comment|/*    0x163b8 - 0x163bc    */
specifier|volatile
name|u_int32_t
name|ch0_cmac_i2q2
decl_stmt|;
comment|/*    0x163bc - 0x163c0    */
specifier|volatile
name|u_int32_t
name|ch0_cmac_power_hpf
decl_stmt|;
comment|/*    0x163c0 - 0x163c4    */
specifier|volatile
name|u_int32_t
name|ch0_rxdac_set1
decl_stmt|;
comment|/*    0x163c4 - 0x163c8    */
specifier|volatile
name|u_int32_t
name|ch0_rxdac_set2
decl_stmt|;
comment|/*    0x163c8 - 0x163cc    */
specifier|volatile
name|u_int32_t
name|ch0_rxdac_long_shift
decl_stmt|;
comment|/*    0x163cc - 0x163d0    */
specifier|volatile
name|u_int32_t
name|ch0_cmac_results_i
decl_stmt|;
comment|/*    0x163d0 - 0x163d4    */
specifier|volatile
name|u_int32_t
name|ch0_cmac_results_q
decl_stmt|;
comment|/*    0x163d4 - 0x163d8    */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x28
index|]
decl_stmt|;
comment|/*    0x163d8 - 0x16400    */
specifier|volatile
name|u_int32_t
name|ch1_RXRF_BIAS1
decl_stmt|;
comment|/*    0x16400 - 0x16404    */
specifier|volatile
name|u_int32_t
name|ch1_RXRF_BIAS2
decl_stmt|;
comment|/*    0x16404 - 0x16408    */
specifier|volatile
name|u_int32_t
name|ch1_RXRF_GAINSTAGES
decl_stmt|;
comment|/*    0x16408 - 0x1640c    */
specifier|volatile
name|u_int32_t
name|ch1_RXRF_AGC
decl_stmt|;
comment|/*    0x1640c - 0x16410    */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|ch1_RXRF_BIAS3
decl_stmt|;
comment|/*    0x16410 - 0x16414    */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x2c
index|]
decl_stmt|;
comment|/*    0x16414 - 0x16440    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF1
decl_stmt|;
comment|/*    0x16440 - 0x16444    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF2
decl_stmt|;
comment|/*    0x16444 - 0x16448    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF3
decl_stmt|;
comment|/*    0x16448 - 0x1644c    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF4
decl_stmt|;
comment|/*    0x1644c - 0x16450    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF5
decl_stmt|;
comment|/*    0x16450 - 0x16454    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF6
decl_stmt|;
comment|/*    0x16454 - 0x16458    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF7
decl_stmt|;
comment|/*    0x16458 - 0x1645c    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF8
decl_stmt|;
comment|/*    0x1645c - 0x16460    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF9
decl_stmt|;
comment|/*    0x16460 - 0x16464    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF10
decl_stmt|;
comment|/*    0x16464 - 0x16468    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF11
decl_stmt|;
comment|/*    0x16468 - 0x1646c    */
specifier|volatile
name|u_int32_t
name|ch1_TXRF12
decl_stmt|;
comment|/*    0x1646c - 0x16470    */
specifier|volatile
name|char
name|pad__10
index|[
literal|0x90
index|]
decl_stmt|;
comment|/*    0x16470 - 0x16500    */
specifier|volatile
name|u_int32_t
name|ch1_RXTX1
decl_stmt|;
comment|/*    0x16500 - 0x16504    */
specifier|volatile
name|u_int32_t
name|ch1_RXTX2
decl_stmt|;
comment|/*    0x16504 - 0x16508    */
specifier|volatile
name|u_int32_t
name|ch1_RXTX3
decl_stmt|;
comment|/*    0x16508 - 0x1650c    */
specifier|volatile
name|u_int32_t
name|ch1_RXTX4
decl_stmt|;
comment|/*    0x1650c - 0x16510    */
comment|/* Jupiter */
specifier|volatile
name|u_int32_t
name|ch1_RXTX5
decl_stmt|;
comment|/*    0x16510 - 0x16514    */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x2c
index|]
decl_stmt|;
comment|/*    0x16514 - 0x16540    */
specifier|volatile
name|u_int32_t
name|ch1_BB1
decl_stmt|;
comment|/*    0x16540 - 0x16544    */
specifier|volatile
name|u_int32_t
name|ch1_BB2
decl_stmt|;
comment|/*    0x16544 - 0x16548    */
specifier|volatile
name|u_int32_t
name|ch1_BB3
decl_stmt|;
comment|/*    0x16548 - 0x1654c    */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x234
index|]
decl_stmt|;
comment|/*    0x1654c - 0x16780    */
specifier|volatile
name|u_int32_t
name|ch1_rbist_cntrl
decl_stmt|;
comment|/*    0x16780 - 0x16784    */
specifier|volatile
name|u_int32_t
name|ch1_tx_dc_offset
decl_stmt|;
comment|/*    0x16784 - 0x16788    */
specifier|volatile
name|u_int32_t
name|ch1_tx_tonegen0
decl_stmt|;
comment|/*    0x16788 - 0x1678c    */
specifier|volatile
name|u_int32_t
name|ch1_tx_tonegen1
decl_stmt|;
comment|/*    0x1678c - 0x16790    */
specifier|volatile
name|u_int32_t
name|ch1_tx_lftonegen0
decl_stmt|;
comment|/*    0x16790 - 0x16794    */
specifier|volatile
name|u_int32_t
name|ch1_tx_linear_ramp_i
decl_stmt|;
comment|/*    0x16794 - 0x16798    */
specifier|volatile
name|u_int32_t
name|ch1_tx_linear_ramp_q
decl_stmt|;
comment|/*    0x16798 - 0x1679c    */
specifier|volatile
name|u_int32_t
name|ch1_tx_prbs_mag
decl_stmt|;
comment|/*    0x1679c - 0x167a0    */
specifier|volatile
name|u_int32_t
name|ch1_tx_prbs_seed_i
decl_stmt|;
comment|/*    0x167a0 - 0x167a4    */
specifier|volatile
name|u_int32_t
name|ch1_tx_prbs_seed_q
decl_stmt|;
comment|/*    0x167a4 - 0x167a8    */
specifier|volatile
name|u_int32_t
name|ch1_cmac_dc_cancel
decl_stmt|;
comment|/*    0x167a8 - 0x167ac    */
specifier|volatile
name|u_int32_t
name|ch1_cmac_dc_offset
decl_stmt|;
comment|/*    0x167ac - 0x167b0    */
specifier|volatile
name|u_int32_t
name|ch1_cmac_corr
decl_stmt|;
comment|/*    0x167b0 - 0x167b4    */
specifier|volatile
name|u_int32_t
name|ch1_cmac_power
decl_stmt|;
comment|/*    0x167b4 - 0x167b8    */
specifier|volatile
name|u_int32_t
name|ch1_cmac_cross_corr
decl_stmt|;
comment|/*    0x167b8 - 0x167bc    */
specifier|volatile
name|u_int32_t
name|ch1_cmac_i2q2
decl_stmt|;
comment|/*    0x167bc - 0x167c0    */
specifier|volatile
name|u_int32_t
name|ch1_cmac_power_hpf
decl_stmt|;
comment|/*    0x167c0 - 0x167c4    */
specifier|volatile
name|u_int32_t
name|ch1_rxdac_set1
decl_stmt|;
comment|/*    0x167c4 - 0x167c8    */
specifier|volatile
name|u_int32_t
name|ch1_rxdac_set2
decl_stmt|;
comment|/*    0x167c8 - 0x167cc    */
specifier|volatile
name|u_int32_t
name|ch1_rxdac_long_shift
decl_stmt|;
comment|/*    0x167cc - 0x167d0    */
specifier|volatile
name|u_int32_t
name|ch1_cmac_results_i
decl_stmt|;
comment|/*    0x167d0 - 0x167d4    */
specifier|volatile
name|u_int32_t
name|ch1_cmac_results_q
decl_stmt|;
comment|/*    0x167d4 - 0x167d8    */
specifier|volatile
name|char
name|pad__13
index|[
literal|0x28
index|]
decl_stmt|;
comment|/*    0x167d8 - 0x16800    */
specifier|volatile
name|u_int32_t
name|ch2_RXRF_BIAS1
decl_stmt|;
comment|/*    0x16800 - 0x16804    */
specifier|volatile
name|u_int32_t
name|ch2_RXRF_BIAS2
decl_stmt|;
comment|/*    0x16804 - 0x16808    */
specifier|volatile
name|u_int32_t
name|ch2_RXRF_GAINSTAGES
decl_stmt|;
comment|/*    0x16808 - 0x1680c    */
specifier|volatile
name|u_int32_t
name|ch2_RXRF_AGC
decl_stmt|;
comment|/*    0x1680c - 0x16810    */
specifier|volatile
name|char
name|pad__14
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*    0x16810 - 0x16840    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF1
decl_stmt|;
comment|/*    0x16840 - 0x16844    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF2
decl_stmt|;
comment|/*    0x16844 - 0x16848    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF3
decl_stmt|;
comment|/*    0x16848 - 0x1684c    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF4
decl_stmt|;
comment|/*    0x1684c - 0x16850    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF5
decl_stmt|;
comment|/*    0x16850 - 0x16854    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF6
decl_stmt|;
comment|/*    0x16854 - 0x16858    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF7
decl_stmt|;
comment|/*    0x16858 - 0x1685c    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF8
decl_stmt|;
comment|/*    0x1685c - 0x16860    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF9
decl_stmt|;
comment|/*    0x16860 - 0x16864    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF10
decl_stmt|;
comment|/*    0x16864 - 0x16868    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF11
decl_stmt|;
comment|/*    0x16868 - 0x1686c    */
specifier|volatile
name|u_int32_t
name|ch2_TXRF12
decl_stmt|;
comment|/*    0x1686c - 0x16870    */
specifier|volatile
name|char
name|pad__15
index|[
literal|0x90
index|]
decl_stmt|;
comment|/*    0x16870 - 0x16900    */
specifier|volatile
name|u_int32_t
name|ch2_RXTX1
decl_stmt|;
comment|/*    0x16900 - 0x16904    */
specifier|volatile
name|u_int32_t
name|ch2_RXTX2
decl_stmt|;
comment|/*    0x16904 - 0x16908    */
specifier|volatile
name|u_int32_t
name|ch2_RXTX3
decl_stmt|;
comment|/*    0x16908 - 0x1690c    */
specifier|volatile
name|u_int32_t
name|ch2_RXTX4
decl_stmt|;
comment|/*    0x1690c - 0x16910    */
specifier|volatile
name|char
name|pad__16
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*    0x16910 - 0x16940    */
specifier|volatile
name|u_int32_t
name|ch2_BB1
decl_stmt|;
comment|/*    0x16940 - 0x16944    */
specifier|volatile
name|u_int32_t
name|ch2_BB2
decl_stmt|;
comment|/*    0x16944 - 0x16948    */
specifier|volatile
name|u_int32_t
name|ch2_BB3
decl_stmt|;
comment|/*    0x16948 - 0x1694c    */
specifier|volatile
name|char
name|pad__17
index|[
literal|0x234
index|]
decl_stmt|;
comment|/*    0x1694c - 0x16b80    */
specifier|volatile
name|u_int32_t
name|ch2_rbist_cntrl
decl_stmt|;
comment|/*    0x16b80 - 0x16b84    */
specifier|volatile
name|u_int32_t
name|ch2_tx_dc_offset
decl_stmt|;
comment|/*    0x16b84 - 0x16b88    */
specifier|volatile
name|u_int32_t
name|ch2_tx_tonegen0
decl_stmt|;
comment|/*    0x16b88 - 0x16b8c    */
specifier|volatile
name|u_int32_t
name|ch2_tx_tonegen1
decl_stmt|;
comment|/*    0x16b8c - 0x16b90    */
specifier|volatile
name|u_int32_t
name|ch2_tx_lftonegen0
decl_stmt|;
comment|/*    0x16b90 - 0x16b94    */
specifier|volatile
name|u_int32_t
name|ch2_tx_linear_ramp_i
decl_stmt|;
comment|/*    0x16b94 - 0x16b98    */
specifier|volatile
name|u_int32_t
name|ch2_tx_linear_ramp_q
decl_stmt|;
comment|/*    0x16b98 - 0x16b9c    */
specifier|volatile
name|u_int32_t
name|ch2_tx_prbs_mag
decl_stmt|;
comment|/*    0x16b9c - 0x16ba0    */
specifier|volatile
name|u_int32_t
name|ch2_tx_prbs_seed_i
decl_stmt|;
comment|/*    0x16ba0 - 0x16ba4    */
specifier|volatile
name|u_int32_t
name|ch2_tx_prbs_seed_q
decl_stmt|;
comment|/*    0x16ba4 - 0x16ba8    */
specifier|volatile
name|u_int32_t
name|ch2_cmac_dc_cancel
decl_stmt|;
comment|/*    0x16ba8 - 0x16bac    */
specifier|volatile
name|u_int32_t
name|ch2_cmac_dc_offset
decl_stmt|;
comment|/*    0x16bac - 0x16bb0    */
specifier|volatile
name|u_int32_t
name|ch2_cmac_corr
decl_stmt|;
comment|/*    0x16bb0 - 0x16bb4    */
specifier|volatile
name|u_int32_t
name|ch2_cmac_power
decl_stmt|;
comment|/*    0x16bb4 - 0x16bb8    */
specifier|volatile
name|u_int32_t
name|ch2_cmac_cross_corr
decl_stmt|;
comment|/*    0x16bb8 - 0x16bbc    */
specifier|volatile
name|u_int32_t
name|ch2_cmac_i2q2
decl_stmt|;
comment|/*    0x16bbc - 0x16bc0    */
specifier|volatile
name|u_int32_t
name|ch2_cmac_power_hpf
decl_stmt|;
comment|/*    0x16bc0 - 0x16bc4    */
specifier|volatile
name|u_int32_t
name|ch2_rxdac_set1
decl_stmt|;
comment|/*    0x16bc4 - 0x16bc8    */
specifier|volatile
name|u_int32_t
name|ch2_rxdac_set2
decl_stmt|;
comment|/*    0x16bc8 - 0x16bcc    */
specifier|volatile
name|u_int32_t
name|ch2_rxdac_long_shift
decl_stmt|;
comment|/*    0x16bcc - 0x16bd0    */
specifier|volatile
name|u_int32_t
name|ch2_cmac_results_i
decl_stmt|;
comment|/*    0x16bd0 - 0x16bd4    */
specifier|volatile
name|u_int32_t
name|ch2_cmac_results_q
decl_stmt|;
comment|/*    0x16bd4 - 0x16bd8    */
specifier|volatile
name|char
name|pad__18
index|[
literal|0x4c4a8
index|]
decl_stmt|;
comment|/*    0x16bd8 - 0x63080    */
comment|/* Jupiter-start */
specifier|volatile
name|u_int32_t
name|chbt_SYNTH1
decl_stmt|;
comment|/*    0x63080 - 0x63084    */
specifier|volatile
name|u_int32_t
name|chbt_SYNTH2
decl_stmt|;
comment|/*    0x63084 - 0x63088    */
specifier|volatile
name|u_int32_t
name|chbt_SYNTH3
decl_stmt|;
comment|/*    0x63088 - 0x6308c    */
specifier|volatile
name|u_int32_t
name|chbt_SYNTH4
decl_stmt|;
comment|/*    0x6308c - 0x63090    */
specifier|volatile
name|u_int32_t
name|chbt_SYNTH5
decl_stmt|;
comment|/*    0x63090 - 0x63094    */
specifier|volatile
name|u_int32_t
name|chbt_SYNTH6
decl_stmt|;
comment|/*    0x63094 - 0x63098    */
specifier|volatile
name|u_int32_t
name|chbt_SYNTH7
decl_stmt|;
comment|/*    0x63098 - 0x6309c    */
specifier|volatile
name|u_int32_t
name|chbt_SYNTH8
decl_stmt|;
comment|/*    0x6309c - 0x630a0    */
specifier|volatile
name|char
name|pad__19
index|[
literal|0x20
index|]
decl_stmt|;
comment|/*    0x630a0 - 0x630c0    */
specifier|volatile
name|u_int32_t
name|chbt_BIAS1
decl_stmt|;
comment|/*    0x630c0 - 0x630c4    */
specifier|volatile
name|u_int32_t
name|chbt_BIAS2
decl_stmt|;
comment|/*    0x630c4 - 0x630c8    */
specifier|volatile
name|u_int32_t
name|chbt_BIAS3
decl_stmt|;
comment|/*    0x630c8 - 0x630cc    */
specifier|volatile
name|u_int32_t
name|chbt_BIAS4
decl_stmt|;
comment|/*    0x630cc - 0x630d0    */
specifier|volatile
name|u_int32_t
name|chbt_BIAS5
decl_stmt|;
comment|/*    0x630d0 - 0x630d4    */
specifier|volatile
name|char
name|pad__20
index|[
literal|0x2c
index|]
decl_stmt|;
comment|/*    0x630d4 - 0x63100    */
specifier|volatile
name|u_int32_t
name|chbt_TOP1
decl_stmt|;
comment|/*    0x63100 - 0x63104    */
specifier|volatile
name|u_int32_t
name|chbt_TOP2
decl_stmt|;
comment|/*    0x63104 - 0x63108    */
specifier|volatile
name|u_int32_t
name|chbt_TOP3
decl_stmt|;
comment|/*    0x63108 - 0x6310c    */
specifier|volatile
name|u_int32_t
name|chbt_TOP4
decl_stmt|;
comment|/*    0x6310c - 0x63110    */
specifier|volatile
name|u_int32_t
name|chbt_TOP5
decl_stmt|;
comment|/*    0x63110 - 0x63114    */
specifier|volatile
name|u_int32_t
name|chbt_TOP6
decl_stmt|;
comment|/*    0x63114 - 0x63118    */
specifier|volatile
name|u_int32_t
name|chbt_TOP7
decl_stmt|;
comment|/*    0x63118 - 0x6311c    */
specifier|volatile
name|u_int32_t
name|chbt_TOP8
decl_stmt|;
comment|/*    0x6311c - 0x63120    */
specifier|volatile
name|u_int32_t
name|chbt_TOP9
decl_stmt|;
comment|/*    0x63120 - 0x63124    */
specifier|volatile
name|u_int32_t
name|chbt_TOP10
decl_stmt|;
comment|/*    0x63124 - 0x63128    */
specifier|volatile
name|char
name|pad__21
index|[
literal|0x158
index|]
decl_stmt|;
comment|/*    0x63128 - 0x63280    */
specifier|volatile
name|u_int32_t
name|chbt_CLK1
decl_stmt|;
comment|/*    0x63280 - 0x63284    */
specifier|volatile
name|u_int32_t
name|chbt_CLK2
decl_stmt|;
comment|/*    0x63284 - 0x63288    */
specifier|volatile
name|u_int32_t
name|chbt_CLK3
decl_stmt|;
comment|/*    0x63288 - 0x6328c    */
specifier|volatile
name|char
name|pad__22
index|[
literal|0xb4
index|]
decl_stmt|;
comment|/*    0x6328c - 0x63340    */
specifier|volatile
name|u_int32_t
name|chbt_PMU1
decl_stmt|;
comment|/*    0x63340 - 0x63344    */
specifier|volatile
name|u_int32_t
name|chbt_PMU2
decl_stmt|;
comment|/*    0x63344 - 0x63348    */
comment|/* Jupiter-end */
comment|/* Aphrodite-start */
specifier|volatile
name|char
name|pad__23
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*    0x63348 - 0x63380    */
specifier|volatile
name|u_int32_t
name|chbt_rbist_cntrl
decl_stmt|;
comment|/*    0x63380 - 0x63384    */
specifier|volatile
name|u_int32_t
name|chbt_tx_dc_offset
decl_stmt|;
comment|/*    0x63384 - 0x63388    */
specifier|volatile
name|u_int32_t
name|chbt_tx_tonegen0
decl_stmt|;
comment|/*    0x63388 - 0x6338c    */
specifier|volatile
name|u_int32_t
name|chbt_tx_tonegen1
decl_stmt|;
comment|/*    0x6338c - 0x63390    */
specifier|volatile
name|u_int32_t
name|chbt_tx_lftonegen0
decl_stmt|;
comment|/*    0x63390 - 0x63394    */
specifier|volatile
name|u_int32_t
name|chbt_tx_linear_ramp_i
decl_stmt|;
comment|/*    0x63394 - 0x63398    */
specifier|volatile
name|u_int32_t
name|chbt_tx_linear_ramp_q
decl_stmt|;
comment|/*    0x63398 - 0x6339c    */
specifier|volatile
name|u_int32_t
name|chbt_tx_prbs_mag
decl_stmt|;
comment|/*    0x6339c - 0x633a0    */
specifier|volatile
name|u_int32_t
name|chbt_tx_prbs_seed_i
decl_stmt|;
comment|/*    0x633a0 - 0x633a4    */
specifier|volatile
name|u_int32_t
name|chbt_tx_prbs_seed_q
decl_stmt|;
comment|/*    0x633a4 - 0x633a8    */
specifier|volatile
name|u_int32_t
name|chbt_cmac_dc_cancel
decl_stmt|;
comment|/*    0x633a8 - 0x633ac    */
specifier|volatile
name|u_int32_t
name|chbt_cmac_dc_offset
decl_stmt|;
comment|/*    0x633ac - 0x633b0    */
specifier|volatile
name|u_int32_t
name|chbt_cmac_corr
decl_stmt|;
comment|/*    0x633b0 - 0x633b4    */
specifier|volatile
name|u_int32_t
name|chbt_cmac_power
decl_stmt|;
comment|/*    0x633b4 - 0x633b8    */
specifier|volatile
name|u_int32_t
name|chbt_cmac_cross_corr
decl_stmt|;
comment|/*    0x633b8 - 0x633bc    */
specifier|volatile
name|u_int32_t
name|chbt_cmac_i2q2
decl_stmt|;
comment|/*    0x633bc - 0x633c0    */
specifier|volatile
name|u_int32_t
name|chbt_cmac_power_hpf
decl_stmt|;
comment|/*    0x633c0 - 0x633c4    */
specifier|volatile
name|u_int32_t
name|chbt_rxdac_set1
decl_stmt|;
comment|/*    0x633c4 - 0x633c8    */
specifier|volatile
name|u_int32_t
name|chbt_rxdac_set2
decl_stmt|;
comment|/*    0x633c8 - 0x633cc    */
specifier|volatile
name|u_int32_t
name|chbt_rxdac_long_shift
decl_stmt|;
comment|/*    0x633cc - 0x633d0    */
specifier|volatile
name|u_int32_t
name|chbt_cmac_results_i
decl_stmt|;
comment|/*    0x633d0 - 0x633d4    */
specifier|volatile
name|u_int32_t
name|chbt_cmac_results_q
decl_stmt|;
comment|/*    0x633d4 - 0x633d8    */
comment|/* Aphrodite-end */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pcie_phy_reg_csr
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x18c00
index|]
decl_stmt|;
comment|/*        0x0 - 0x18c00    */
specifier|volatile
name|u_int32_t
name|pcie_phy_reg_1
decl_stmt|;
comment|/*    0x18c00 - 0x18c04    */
specifier|volatile
name|u_int32_t
name|pcie_phy_reg_2
decl_stmt|;
comment|/*    0x18c04 - 0x18c08    */
specifier|volatile
name|u_int32_t
name|pcie_phy_reg_3
decl_stmt|;
comment|/*    0x18c08 - 0x18c0c    */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmu_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x16c40
index|]
decl_stmt|;
comment|/*        0x0 - 0x16c40    */
specifier|volatile
name|u_int32_t
name|ch0_PMU1
decl_stmt|;
comment|/*    0x16c40 - 0x16c44    */
specifier|volatile
name|u_int32_t
name|ch0_PMU2
decl_stmt|;
comment|/*    0x16c44 - 0x16c48    */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wlan_coex_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x1800
index|]
decl_stmt|;
comment|/*        0x0 - 0x1800     */
specifier|volatile
name|u_int32_t
name|MCI_COMMAND0
decl_stmt|;
comment|/*     0x1800 - 0x1804     */
specifier|volatile
name|u_int32_t
name|MCI_COMMAND1
decl_stmt|;
comment|/*     0x1804 - 0x1808     */
specifier|volatile
name|u_int32_t
name|MCI_COMMAND2
decl_stmt|;
comment|/*     0x1808 - 0x180c     */
specifier|volatile
name|u_int32_t
name|MCI_RX_CTRL
decl_stmt|;
comment|/*     0x180c - 0x1810     */
specifier|volatile
name|u_int32_t
name|MCI_TX_CTRL
decl_stmt|;
comment|/*     0x1810 - 0x1814     */
specifier|volatile
name|u_int32_t
name|MCI_MSG_ATTRIBUTES_TABLE
decl_stmt|;
comment|/*     0x1814 - 0x1818     */
specifier|volatile
name|u_int32_t
name|MCI_SCHD_TABLE_0
decl_stmt|;
comment|/*     0x1818 - 0x181c     */
specifier|volatile
name|u_int32_t
name|MCI_SCHD_TABLE_1
decl_stmt|;
comment|/*     0x181c - 0x1820     */
specifier|volatile
name|u_int32_t
name|MCI_GPM_0
decl_stmt|;
comment|/*     0x1820 - 0x1824     */
specifier|volatile
name|u_int32_t
name|MCI_GPM_1
decl_stmt|;
comment|/*     0x1824 - 0x1828     */
specifier|volatile
name|u_int32_t
name|MCI_INTERRUPT_RAW
decl_stmt|;
comment|/*     0x1828 - 0x182c     */
specifier|volatile
name|u_int32_t
name|MCI_INTERRUPT_EN
decl_stmt|;
comment|/*     0x182c - 0x1830     */
specifier|volatile
name|u_int32_t
name|MCI_REMOTE_CPU_INT
decl_stmt|;
comment|/*     0x1830 - 0x1834     */
specifier|volatile
name|u_int32_t
name|MCI_REMOTE_CPU_INT_EN
decl_stmt|;
comment|/*     0x1834 - 0x1838     */
specifier|volatile
name|u_int32_t
name|MCI_INTERRUPT_RX_MSG_RAW
decl_stmt|;
comment|/*     0x1838 - 0x183c     */
specifier|volatile
name|u_int32_t
name|MCI_INTERRUPT_RX_MSG_EN
decl_stmt|;
comment|/*     0x183c - 0x1840     */
specifier|volatile
name|u_int32_t
name|MCI_CPU_INT
decl_stmt|;
comment|/*     0x1840 - 0x1844     */
specifier|volatile
name|u_int32_t
name|MCI_RX_STATUS
decl_stmt|;
comment|/*     0x1844 - 0x1848     */
specifier|volatile
name|u_int32_t
name|MCI_CONT_STATUS
decl_stmt|;
comment|/*     0x1848 - 0x184c     */
specifier|volatile
name|u_int32_t
name|MCI_BT_PRI0
decl_stmt|;
comment|/*     0x184c - 0x1850     */
specifier|volatile
name|u_int32_t
name|MCI_BT_PRI1
decl_stmt|;
comment|/*     0x1850 - 0x1854     */
specifier|volatile
name|u_int32_t
name|MCI_BT_PRI2
decl_stmt|;
comment|/*     0x1854 - 0x1858     */
specifier|volatile
name|u_int32_t
name|MCI_BT_PRI3
decl_stmt|;
comment|/*     0x1858 - 0x185c     */
specifier|volatile
name|u_int32_t
name|MCI_BT_PRI
decl_stmt|;
comment|/*     0x185c - 0x1860     */
specifier|volatile
name|u_int32_t
name|MCI_WL_FREQ0
decl_stmt|;
comment|/*     0x1860 - 0x1864     */
specifier|volatile
name|u_int32_t
name|MCI_WL_FREQ1
decl_stmt|;
comment|/*     0x1864 - 0x1868     */
specifier|volatile
name|u_int32_t
name|MCI_WL_FREQ2
decl_stmt|;
comment|/*     0x1868 - 0x186c     */
specifier|volatile
name|u_int32_t
name|MCI_GAIN
decl_stmt|;
comment|/*     0x186c - 0x1870     */
specifier|volatile
name|u_int32_t
name|MCI_WBTIMER1
decl_stmt|;
comment|/*     0x1870 - 0x1874     */
specifier|volatile
name|u_int32_t
name|MCI_WBTIMER2
decl_stmt|;
comment|/*     0x1874 - 0x1878     */
specifier|volatile
name|u_int32_t
name|MCI_WBTIMER3
decl_stmt|;
comment|/*     0x1878 - 0x187c     */
specifier|volatile
name|u_int32_t
name|MCI_WBTIMER4
decl_stmt|;
comment|/*     0x187c - 0x1880     */
specifier|volatile
name|u_int32_t
name|MCI_MAXGAIN
decl_stmt|;
comment|/*     0x1880 - 0x1884     */
specifier|volatile
name|u_int32_t
name|MCI_HW_SCHD_TBL_CTL
decl_stmt|;
comment|/*     0x1884 - 0x1888     */
specifier|volatile
name|u_int32_t
name|MCI_HW_SCHD_TBL_D0
decl_stmt|;
comment|/*     0x1888 - 0x188c     */
specifier|volatile
name|u_int32_t
name|MCI_HW_SCHD_TBL_D1
decl_stmt|;
comment|/*     0x188c - 0x1890     */
specifier|volatile
name|u_int32_t
name|MCI_HW_SCHD_TBL_D2
decl_stmt|;
comment|/*     0x1890 - 0x1894     */
specifier|volatile
name|u_int32_t
name|MCI_HW_SCHD_TBL_D3
decl_stmt|;
comment|/*     0x1894 - 0x1898     */
specifier|volatile
name|u_int32_t
name|MCI_TX_PAYLOAD0
decl_stmt|;
comment|/*     0x1898 - 0x189c     */
specifier|volatile
name|u_int32_t
name|MCI_TX_PAYLOAD1
decl_stmt|;
comment|/*     0x189c - 0x18a0     */
specifier|volatile
name|u_int32_t
name|MCI_TX_PAYLOAD2
decl_stmt|;
comment|/*     0x18a0 - 0x18a4     */
specifier|volatile
name|u_int32_t
name|MCI_TX_PAYLOAD3
decl_stmt|;
comment|/*     0x18a4 - 0x18a8     */
specifier|volatile
name|u_int32_t
name|BTCOEX_WBTIMER
decl_stmt|;
comment|/*     0x18a8 - 0x18ac     */
specifier|volatile
name|u_int32_t
name|BTCOEX_CTRL
decl_stmt|;
comment|/*     0x18ac - 0x18b0     */
specifier|volatile
name|u_int32_t
name|BTCOEX_WL_WEIGHTS0
decl_stmt|;
comment|/*     0x18b0 - 0x18b4     */
specifier|volatile
name|u_int32_t
name|BTCOEX_WL_WEIGHTS1
decl_stmt|;
comment|/*     0x18b4 - 0x18b8     */
specifier|volatile
name|u_int32_t
name|BTCOEX_WL_WEIGHTS2
decl_stmt|;
comment|/*     0x18b8 - 0x18bc     */
specifier|volatile
name|u_int32_t
name|BTCOEX_WL_WEIGHTS3
decl_stmt|;
comment|/*     0x18bc - 0x18c0     */
specifier|volatile
name|u_int32_t
name|BTCOEX_MAX_TXPWR
index|[
literal|8
index|]
decl_stmt|;
comment|/*     0x18c0 - 0x18e0     */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x60
index|]
decl_stmt|;
comment|/*     0x18e0 - 0x1940     */
specifier|volatile
name|u_int32_t
name|BTCOEX_WL_LNA
decl_stmt|;
comment|/*     0x1940 - 0x1944     */
specifier|volatile
name|u_int32_t
name|BTCOEX_RFGAIN_CTRL
decl_stmt|;
comment|/*     0x1944 - 0x1948     */
specifier|volatile
name|u_int32_t
name|BTCOEX_CTRL2
decl_stmt|;
comment|/*     0x1948 - 0x194c     */
specifier|volatile
name|u_int32_t
name|BTCOEX_RC
decl_stmt|;
comment|/*     0x194c - 0x1950     */
specifier|volatile
name|u_int32_t
name|BTCOEX_MAX_RFGAIN
index|[
literal|16
index|]
decl_stmt|;
comment|/*     0x1950 - 0x1990     */
specifier|volatile
name|char
name|pad__2
index|[
literal|0xc0
index|]
decl_stmt|;
comment|/*     0x1990 - 0x1a50     */
specifier|volatile
name|u_int32_t
name|BTCOEX_DBG
decl_stmt|;
comment|/*     0x1a50 - 0x1a54     */
specifier|volatile
name|u_int32_t
name|MCI_LAST_HW_MSG_HDR
decl_stmt|;
comment|/*     0x1a54 - 0x1a58     */
specifier|volatile
name|u_int32_t
name|MCI_LAST_HW_MSG_BDY
decl_stmt|;
comment|/*     0x1a58 - 0x1a5c     */
specifier|volatile
name|u_int32_t
name|MCI_SCHD_TABLE_2
decl_stmt|;
comment|/*     0x1a5c - 0x1a60     */
specifier|volatile
name|u_int32_t
name|BTCOEX_CTRL3
decl_stmt|;
comment|/*     0x1a60 - 0x1a64     */
comment|/* Aphrodite-start */
specifier|volatile
name|u_int32_t
name|BTCOEX_WL_LNADIV
decl_stmt|;
comment|/*     0x1a64 - 0x1a68     */
specifier|volatile
name|u_int32_t
name|BTCOEX_TXTX_RANGE
decl_stmt|;
comment|/*     0x1a68 - 0x1a6c     */
specifier|volatile
name|u_int32_t
name|MCI_INTERRUPT_1_RAW
decl_stmt|;
comment|/*     0x1a6c - 0x1a70     */
specifier|volatile
name|u_int32_t
name|MCI_INTERRUPT_1_EN
decl_stmt|;
comment|/*     0x1a70 - 0x1a74     */
specifier|volatile
name|u_int32_t
name|MCI_EV_MISC
decl_stmt|;
comment|/*     0x1a74 - 0x1a78     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT_CTRL
decl_stmt|;
comment|/*     0x1a78 - 0x1a7c     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT1
decl_stmt|;
comment|/*     0x1a7c - 0x1a80     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT2
decl_stmt|;
comment|/*     0x1a80 - 0x1a84     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT3
decl_stmt|;
comment|/*     0x1a84 - 0x1a88     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT4
decl_stmt|;
comment|/*     0x1a88 - 0x1a8c     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT5
decl_stmt|;
comment|/*     0x1a8c - 0x1a90     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT6
decl_stmt|;
comment|/*     0x1a90 - 0x1a94     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT7
decl_stmt|;
comment|/*     0x1a94 - 0x1a98     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT8
decl_stmt|;
comment|/*     0x1a98 - 0x1a9c     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT9
decl_stmt|;
comment|/*     0x1a9c - 0x1aa0     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT10
decl_stmt|;
comment|/*     0x1aa0 - 0x1aa4     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT11
decl_stmt|;
comment|/*     0x1aa4 - 0x1aa8     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT12
decl_stmt|;
comment|/*     0x1aa8 - 0x1aac     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT13
decl_stmt|;
comment|/*     0x1aac - 0x1ab0     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT14
decl_stmt|;
comment|/*     0x1ab0 - 0x1ab4     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT15
decl_stmt|;
comment|/*     0x1ab4 - 0x1ab8     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT16
decl_stmt|;
comment|/*     0x1ab8 - 0x1abc     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT17
decl_stmt|;
comment|/*     0x1abc - 0x1ac0     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT18
decl_stmt|;
comment|/*     0x1ac0 - 0x1ac4     */
specifier|volatile
name|u_int32_t
name|MCI_DBG_CNT19
decl_stmt|;
comment|/*     0x1ac4 - 0x1ac8     */
comment|/* Aphrodite-end */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|uart1_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|UART_DATA
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|UART_CONTROL
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|UART_CLKDIV
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|UART_INT
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|UART_INT_EN
decl_stmt|;
comment|/*       0x10 - 0x14       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|wlan_bt_glb_reg_pcie
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x20000
index|]
decl_stmt|;
comment|/*        0x0 - 0x20000    */
specifier|volatile
name|u_int32_t
name|GLB_GPIO_CONTROL
decl_stmt|;
comment|/*    0x20000 - 0x20004    */
specifier|volatile
name|u_int32_t
name|GLB_WLAN_WOW_STATUS
decl_stmt|;
comment|/*    0x20004 - 0x20008    */
specifier|volatile
name|u_int32_t
name|GLB_WLAN_WOW_ENABLE
decl_stmt|;
comment|/*    0x20008 - 0x2000c    */
specifier|volatile
name|u_int32_t
name|GLB_EMB_CPU_WOW_STATUS
decl_stmt|;
comment|/*    0x2000c - 0x20010    */
specifier|volatile
name|u_int32_t
name|GLB_EMB_CPU_WOW_ENABLE
decl_stmt|;
comment|/*    0x20010 - 0x20014    */
specifier|volatile
name|u_int32_t
name|GLB_MBOX_CONTROL_STATUS
decl_stmt|;
comment|/*    0x20014 - 0x20018    */
specifier|volatile
name|u_int32_t
name|GLB_SW_WOW_CONTROL
decl_stmt|;
comment|/*    0x20018 - 0x2001c    */
specifier|volatile
name|u_int32_t
name|GLB_APB_TIMEOUT
decl_stmt|;
comment|/*    0x2001c - 0x20020    */
specifier|volatile
name|u_int32_t
name|GLB_OTP_LDO_CONTROL
decl_stmt|;
comment|/*    0x20020 - 0x20024    */
specifier|volatile
name|u_int32_t
name|GLB_OTP_LDO_POWER_GOOD
decl_stmt|;
comment|/*    0x20024 - 0x20028    */
specifier|volatile
name|u_int32_t
name|GLB_OTP_LDO_STATUS
decl_stmt|;
comment|/*    0x20028 - 0x2002c    */
specifier|volatile
name|u_int32_t
name|GLB_SWREG_DISCONT_MODE
decl_stmt|;
comment|/*    0x2002c - 0x20030    */
specifier|volatile
name|u_int32_t
name|GLB_BT_GPIO_REMAP_OUT_CONTROL0
decl_stmt|;
comment|/*    0x20030 - 0x20034    */
specifier|volatile
name|u_int32_t
name|GLB_BT_GPIO_REMAP_OUT_CONTROL1
decl_stmt|;
comment|/*    0x20034 - 0x20038    */
specifier|volatile
name|u_int32_t
name|GLB_BT_GPIO_REMAP_IN_CONTROL0
decl_stmt|;
comment|/*    0x20038 - 0x2003c    */
specifier|volatile
name|u_int32_t
name|GLB_BT_GPIO_REMAP_IN_CONTROL1
decl_stmt|;
comment|/*    0x2003c - 0x20040    */
specifier|volatile
name|u_int32_t
name|GLB_BT_GPIO_REMAP_IN_CONTROL2
decl_stmt|;
comment|/*    0x20040 - 0x20044    */
union|union
block|{
struct|struct
block|{
specifier|volatile
name|char
name|pad__1
index|[
literal|0xc
index|]
decl_stmt|;
comment|/*    0x20044 - 0x20050    */
specifier|volatile
name|u_int32_t
name|GLB_SCRATCH
index|[
literal|16
index|]
decl_stmt|;
comment|/*    0x20050 - 0x20090    */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x370
index|]
decl_stmt|;
comment|/*    0x20090 - 0x20400    */
block|}
name|Jupiter_10
struct|;
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|GLB_CONTROL
decl_stmt|;
comment|/*    0x20044 - 0x20048    */
specifier|volatile
name|u_int32_t
name|GLB_STATUS
decl_stmt|;
comment|/*    0x20048 - 0x2004c    */
specifier|volatile
name|u_int32_t
name|GLB_SCRATCH
index|[
literal|16
index|]
decl_stmt|;
comment|/*    0x2004c - 0x2008c    */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x354
index|]
decl_stmt|;
comment|/*    0x2008c - 0x203e0    */
name|struct
name|uart1_reg_csr
name|shared_uart1
decl_stmt|;
comment|/*    0x203e0 - 0x203f4    */
specifier|volatile
name|char
name|pad__2
index|[
literal|0xc
index|]
decl_stmt|;
comment|/*    0x203f4 - 0x20400    */
block|}
name|Jupiter_20
struct|;
struct|struct
block|{
specifier|volatile
name|u_int32_t
name|GLB_CONTROL
decl_stmt|;
comment|/*    0x20044 - 0x20048    */
specifier|volatile
name|u_int32_t
name|GLB_STATUS
decl_stmt|;
comment|/*    0x20048 - 0x2004c    */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*    0x2004c - 0x20050    */
specifier|volatile
name|u_int32_t
name|GLB_SCRATCH
index|[
literal|16
index|]
decl_stmt|;
comment|/*    0x20050 - 0x20090    */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x70
index|]
decl_stmt|;
comment|/*    0x20090 - 0x20100    */
specifier|volatile
name|u_int32_t
name|PLLOSC_CTRL
decl_stmt|;
comment|/*    0x20100 - 0x20104    */
specifier|volatile
name|u_int32_t
name|PLLOSC_CFG
decl_stmt|;
comment|/*    0x20104 - 0x20108    */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*    0x20108 - 0x2010c    */
specifier|volatile
name|u_int32_t
name|INNOP_MEM_CONTROL
decl_stmt|;
comment|/*    0x2010c - 0x20110    */
specifier|volatile
name|u_int32_t
name|USB_CONFIG
decl_stmt|;
comment|/*    0x20110 - 0x20114    */
specifier|volatile
name|u_int32_t
name|USB_SPARE32
decl_stmt|;
comment|/*    0x20114 - 0x20118    */
specifier|volatile
name|u_int32_t
name|PCIE_AHB_BRIDGE_CFG
decl_stmt|;
comment|/*    0x20118 - 0x2011c    */
specifier|volatile
name|u_int32_t
name|PCIE_AHB_BRIDGE_CTRL
decl_stmt|;
comment|/*    0x2011c - 0x20120    */
specifier|volatile
name|u_int32_t
name|OPTIONAL_CTL_REG
decl_stmt|;
comment|/*    0x20120 - 0x20124    */
specifier|volatile
name|u_int32_t
name|PCIE_PWR_CTRL_REG
decl_stmt|;
comment|/*    0x20124 - 0x20128    */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*    0x20128 - 0x2012c    */
specifier|volatile
name|u_int32_t
name|USBDEV_CLK_CTL_REG
decl_stmt|;
comment|/*    0x2012c - 0x20130    */
specifier|volatile
name|u_int32_t
name|UHOST_DEBUG_FSM
decl_stmt|;
comment|/*    0x20130 - 0x20134    */
specifier|volatile
name|u_int32_t
name|BRIDGE_DEBUG_FSM
decl_stmt|;
comment|/*    0x20134 - 0x20138    */
specifier|volatile
name|u_int32_t
name|BRIDGE_DEBUG_PTR
decl_stmt|;
comment|/*    0x20138 - 0x2013c    */
specifier|volatile
name|u_int32_t
name|BRIDGE_DEBUG_CLIENT_LOG0
decl_stmt|;
comment|/*    0x2013c - 0x20140    */
specifier|volatile
name|u_int32_t
name|BRIDGE_DEBUG_CLIENT_LOG1
decl_stmt|;
comment|/*    0x20140 - 0x20144    */
specifier|volatile
name|u_int32_t
name|BRIDGE_DEBUG_CLIENT_LOG2
decl_stmt|;
comment|/*    0x20144 - 0x20148    */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x298
index|]
decl_stmt|;
comment|/*    0x20148 - 0x203e0    */
specifier|volatile
name|u_int32_t
name|GLB_UART
index|[
literal|8
index|]
decl_stmt|;
comment|/*    0x203e0 - 0x20400    */
block|}
name|Aphrodite
struct|;
block|}
name|overlay_0x20044
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__rtc_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|RESET_CONTROL
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|PLL_SETTLE
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|VDD_SETTLE
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|PWR_CONTROL
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|XTAL_SETTLE
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|RTC_CLOCK
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|CORE_CLOCK
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|CLKBOOT
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|UART_CLOCK
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|SI_CLOCK
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|CLOCK_CONTROL
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|WDT_CONTROL
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|WDT_STATUS
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|WDT
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|WDT_COUNT
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|WDT_RESET
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|RTC_INT_STATUS
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|INT_SRC_MAPPING
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|UART_SI_GPIO_INT_STATUS
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|LF_TIMER0
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|LF_TIMER_COUNT0
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|LF_TIMER_CONTROL0
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|u_int32_t
name|LF_TIMER_STATUS0
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|LF_TIMER1
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|LF_TIMER_COUNT1
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|LF_TIMER_CONTROL1
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|u_int32_t
name|LF_TIMER_STATUS1
decl_stmt|;
comment|/*       0x68 - 0x6c       */
specifier|volatile
name|u_int32_t
name|RESET_CAUSE
decl_stmt|;
comment|/*       0x6c - 0x70       */
specifier|volatile
name|u_int32_t
name|SYSTEM_SLEEP
decl_stmt|;
comment|/*       0x70 - 0x74       */
specifier|volatile
name|u_int32_t
name|KEEP_AWAKE
decl_stmt|;
comment|/*       0x74 - 0x78       */
specifier|volatile
name|u_int32_t
name|LPO_CAL
decl_stmt|;
comment|/*       0x78 - 0x7c       */
specifier|volatile
name|u_int32_t
name|OBS_CLOCK
decl_stmt|;
comment|/*       0x7c - 0x80       */
specifier|volatile
name|u_int32_t
name|CHIP_REV
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|PWR_ON_TIME
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|u_int32_t
name|PWD_TIME
decl_stmt|;
comment|/*       0x88 - 0x8c       */
specifier|volatile
name|u_int32_t
name|USB_SUSPEND_POWER_REG
decl_stmt|;
comment|/*       0x8c - 0x90       */
specifier|volatile
name|u_int32_t
name|USB_SUSPEND_WAKEUP_COUNTER_REG
decl_stmt|;
comment|/*       0x90 - 0x94       */
specifier|volatile
name|u_int32_t
name|LPO_STEP_CFG
decl_stmt|;
comment|/*       0x94 - 0x98       */
specifier|volatile
name|u_int32_t
name|LPO_FAST_CYL
decl_stmt|;
comment|/*       0x98 - 0x9c       */
specifier|volatile
name|u_int32_t
name|LPO_LPO1
decl_stmt|;
comment|/*       0x9c - 0xa0       */
specifier|volatile
name|u_int32_t
name|LPO_LPO2
decl_stmt|;
comment|/*       0xa0 - 0xa4       */
specifier|volatile
name|u_int32_t
name|LPO_INT_RAW
decl_stmt|;
comment|/*       0xa4 - 0xa8       */
specifier|volatile
name|u_int32_t
name|LPO_N1TARGET
decl_stmt|;
comment|/*       0xa8 - 0xac       */
specifier|volatile
name|u_int32_t
name|LPO_N2TARGET
decl_stmt|;
comment|/*       0xac - 0xb0       */
specifier|volatile
name|u_int32_t
name|LPO_DN1_MULT
decl_stmt|;
comment|/*       0xb0 - 0xb4       */
specifier|volatile
name|u_int32_t
name|LPO_DN2_MULT
decl_stmt|;
comment|/*       0xb4 - 0xb8       */
specifier|volatile
name|u_int32_t
name|LPO_NTARGET_MIN
decl_stmt|;
comment|/*       0xb8 - 0xbc       */
specifier|volatile
name|u_int32_t
name|LPO_NTARGET_MAX
decl_stmt|;
comment|/*       0xbc - 0xc0       */
specifier|volatile
name|u_int32_t
name|LPO_N1TARGET_DEBUG
decl_stmt|;
comment|/*       0xc0 - 0xc4       */
specifier|volatile
name|u_int32_t
name|LPO_N2TARGET_DEBUG
decl_stmt|;
comment|/*       0xc4 - 0xc8       */
specifier|volatile
name|u_int32_t
name|OTP
decl_stmt|;
comment|/*       0xc8 - 0xcc       */
specifier|volatile
name|u_int32_t
name|OTP_STATUS
decl_stmt|;
comment|/*       0xcc - 0xd0       */
specifier|volatile
name|u_int32_t
name|USB_PHY_TEST
decl_stmt|;
comment|/*       0xd0 - 0xd4       */
specifier|volatile
name|u_int32_t
name|USB_PHY_CONFIG
decl_stmt|;
comment|/*       0xd4 - 0xd8       */
specifier|volatile
name|u_int32_t
name|ADDAC_CLOCK_PHASE
decl_stmt|;
comment|/*       0xd8 - 0xdc       */
specifier|volatile
name|u_int32_t
name|THERM_CONTROL
decl_stmt|;
comment|/*       0xdc - 0xe0       */
specifier|volatile
name|u_int32_t
name|THERM_TRIGGER_INTERVAL1
decl_stmt|;
comment|/*       0xe0 - 0xe4       */
specifier|volatile
name|u_int32_t
name|THERM_TRIGGER_INTERVAL2
decl_stmt|;
comment|/*       0xe4 - 0xe8       */
specifier|volatile
name|u_int32_t
name|THERM_CORRECTION
decl_stmt|;
comment|/*       0xe8 - 0xec       */
specifier|volatile
name|u_int32_t
name|THERM_CORRECTION_VALUE1
decl_stmt|;
comment|/*       0xec - 0xf0       */
specifier|volatile
name|u_int32_t
name|THERM_CORRECTION_VALUE2
decl_stmt|;
comment|/*       0xf0 - 0xf4       */
specifier|volatile
name|u_int32_t
name|PLL_CONTROL
decl_stmt|;
comment|/*       0xf4 - 0xf8       */
specifier|volatile
name|u_int32_t
name|VDD12D_SENSE
decl_stmt|;
comment|/*       0xf8 - 0xfc       */
specifier|volatile
name|u_int32_t
name|RBIAS
decl_stmt|;
comment|/*       0xfc - 0x100      */
specifier|volatile
name|u_int32_t
name|THERM_CONTROL_VAL
decl_stmt|;
comment|/*      0x100 - 0x104      */
specifier|volatile
name|u_int32_t
name|PLL_OSC_CONTROL
decl_stmt|;
comment|/*      0x104 - 0x108      */
specifier|volatile
name|u_int32_t
name|AHB_ERR_INT
decl_stmt|;
comment|/*      0x108 - 0x10c      */
specifier|volatile
name|u_int32_t
name|INT_P2_EN
decl_stmt|;
comment|/*      0x10c - 0x110      */
specifier|volatile
name|u_int32_t
name|XTAL_CLOCK
decl_stmt|;
comment|/*      0x110 - 0x114      */
specifier|volatile
name|u_int32_t
name|CHIP_MODES
decl_stmt|;
comment|/*      0x114 - 0x118      */
specifier|volatile
name|u_int32_t
name|XTAL_FREQ
decl_stmt|;
comment|/*      0x118 - 0x11c      */
specifier|volatile
name|u_int32_t
name|DEBUGGER_RESET
decl_stmt|;
comment|/*      0x11c - 0x120      */
specifier|volatile
name|u_int32_t
name|LPO_3_2K_CLK
decl_stmt|;
comment|/*      0x120 - 0x124      */
specifier|volatile
name|u_int32_t
name|LPO1_CLK_DEBUG
decl_stmt|;
comment|/*      0x124 - 0x128      */
specifier|volatile
name|u_int32_t
name|LPO2_CLK_DEBUG
decl_stmt|;
comment|/*      0x128 - 0x12c      */
specifier|volatile
name|u_int32_t
name|ADDR_CHECK
decl_stmt|;
comment|/*      0x12c - 0x130      */
specifier|volatile
name|u_int32_t
name|RTC_DUMMY
decl_stmt|;
comment|/*      0x130 - 0x134      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__vmc_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|BANK0_ADDR
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BANK1_ADDR
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|BANK_CONFIG
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|MC_BCAM_CONFLICT_ERROR
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*       0x10 - 0x20       */
specifier|volatile
name|u_int32_t
name|MC_BCAM_COMPARE
index|[
literal|128
index|]
decl_stmt|;
comment|/*       0x20 - 0x220      */
specifier|volatile
name|u_int32_t
name|MC_BCAM_VALID
index|[
literal|128
index|]
decl_stmt|;
comment|/*      0x220 - 0x420      */
specifier|volatile
name|u_int32_t
name|MC_BCAM_TARGET
index|[
literal|128
index|]
decl_stmt|;
comment|/*      0x420 - 0x620      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__apb_map_csr__uart_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|UART_DATA
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|UART_CONTROL
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|UART_CLKDIV
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|UART_INT
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|UART_INT_EN
decl_stmt|;
comment|/*       0x10 - 0x14       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__si_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|SI_CONFIG
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|SI_CS
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|SI_TX_DATA0
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|SI_TX_DATA1
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|SI_RX_DATA0
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|SI_RX_DATA1
decl_stmt|;
comment|/*       0x14 - 0x18       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__gpio_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|GPIO_OUT
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|GPIO_OUT_W1TS
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|GPIO_OUT_W1TC
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|GPIO_ENABLE
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|GPIO_ENABLE_W1TS
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|GPIO_ENABLE_W1TC
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|GPIO_IN
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|GPIO_STATUS
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|GPIO_STATUS_W1TS
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|GPIO_STATUS_W1TC
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|GPIO_INT_ENABLE
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|GPIO_INT_ENABLE_W1TS
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|GPIO_INT_ENABLE_W1TC
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN0
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN1
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN2
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN3
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN4
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN5
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN6
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN7
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN8
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN9
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN10
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN11
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN12
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN13
decl_stmt|;
comment|/*       0x68 - 0x6c       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN14
decl_stmt|;
comment|/*       0x6c - 0x70       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN15
decl_stmt|;
comment|/*       0x70 - 0x74       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN16
decl_stmt|;
comment|/*       0x74 - 0x78       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN17
decl_stmt|;
comment|/*       0x78 - 0x7c       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN18
decl_stmt|;
comment|/*       0x7c - 0x80       */
specifier|volatile
name|u_int32_t
name|GPIO_PIN19
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|SIGMA_DELTA
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|u_int32_t
name|DEBUG_CONTROL
decl_stmt|;
comment|/*       0x88 - 0x8c       */
specifier|volatile
name|u_int32_t
name|DEBUG_INPUT_SEL
decl_stmt|;
comment|/*       0x8c - 0x90       */
specifier|volatile
name|u_int32_t
name|DEBUG_PIN_SEL
decl_stmt|;
comment|/*       0x90 - 0x94       */
specifier|volatile
name|u_int32_t
name|DEBUG_OBS_BUS
decl_stmt|;
comment|/*       0x94 - 0x98       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__mbox_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|MBOX_FIFO
index|[
literal|4
index|]
decl_stmt|;
comment|/*        0x0 - 0x10       */
specifier|volatile
name|u_int32_t
name|MBOX_FIFO_STATUS
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|MBOX_DMA_POLICY
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|MBOX0_DMA_RX_DESCRIPTOR_BASE
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|MBOX0_DMA_RX_CONTROL
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|MBOX0_DMA_TX_DESCRIPTOR_BASE
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|MBOX0_DMA_TX_CONTROL
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|MBOX1_DMA_RX_DESCRIPTOR_BASE
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|MBOX1_DMA_RX_CONTROL
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|MBOX1_DMA_TX_DESCRIPTOR_BASE
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|MBOX1_DMA_TX_CONTROL
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|MBOX2_DMA_RX_DESCRIPTOR_BASE
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|MBOX2_DMA_RX_CONTROL
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|MBOX2_DMA_TX_DESCRIPTOR_BASE
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|MBOX2_DMA_TX_CONTROL
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|MBOX3_DMA_RX_DESCRIPTOR_BASE
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|MBOX3_DMA_RX_CONTROL
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|MBOX3_DMA_TX_DESCRIPTOR_BASE
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|MBOX3_DMA_TX_CONTROL
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|u_int32_t
name|FIFO_TIMEOUT
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|MBOX_INT_STATUS
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|MBOX_INT_ENABLE
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|MBOX_DEBUG
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|u_int32_t
name|MBOX_FIFO_RESET
decl_stmt|;
comment|/*       0x68 - 0x6c       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x6c - 0x70       */
specifier|volatile
name|u_int32_t
name|MBOX_TXFIFO_POP
index|[
literal|4
index|]
decl_stmt|;
comment|/*       0x70 - 0x80       */
specifier|volatile
name|u_int32_t
name|HCI_FRAMER
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|STEREO_CONFIG
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|u_int32_t
name|STEREO_CONFIG1
decl_stmt|;
comment|/*       0x88 - 0x8c       */
specifier|volatile
name|u_int32_t
name|STEREO_CONFIG2
decl_stmt|;
comment|/*       0x8c - 0x90       */
specifier|volatile
name|u_int32_t
name|STEREO_VOLUME
decl_stmt|;
comment|/*       0x90 - 0x94       */
specifier|volatile
name|u_int32_t
name|STEREO_DEBUG
decl_stmt|;
comment|/*       0x94 - 0x98       */
specifier|volatile
name|u_int32_t
name|STEREO_CONFIG3
decl_stmt|;
comment|/*       0x98 - 0x9c       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__lc_dma_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|LC_DMA_MASTER
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|LC_DMA_TX_CONTROL
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|LC_DMA_RX_CONTROL
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|LC_DMA_TX_HW
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|LC_DMA_RX_HW
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|LC_DMA_INT_STATUS
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|LC_DMA_TX_STATUS
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|LC_DMA_TX_STATUS_W1TC
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|LC_DMA_TX_ENABLE
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|LC_DMA_RX_STATUS
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|LC_DMA_RX_STATUS_W1TC
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|LC_DMA_RX_ENABLE
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|LC_DMA_DEBUG
decl_stmt|;
comment|/*       0x30 - 0x34       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__lc_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_DAC_L
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_DAC_U
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_BD_ADDR
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_FHS
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_CTL
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_TIMING
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_TIMING_1
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|LC_MISC
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_COMMAND1
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_COMMAND2
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_COMMAND3
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_COMMAND4
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_COMMAND5
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_COMMAND6
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_COMMAND7
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_COMMAND8
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_AC1_L
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_AC1_U
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_AC2_L
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_AC2_U
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_CLOCK_OFFSET
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|LC_FREQUENCY
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|u_int32_t
name|LC_CH_ASSESS_1
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|LC_CH_ASSESS_2
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_ENCRYPTION_KEY0
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_ENCRYPTION_KEY1
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_ENCRYPTION_KEY2
decl_stmt|;
comment|/*       0x68 - 0x6c       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_ENCRYPTION_KEY3
decl_stmt|;
comment|/*       0x6c - 0x70       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_TX_CONTROL
decl_stmt|;
comment|/*       0x70 - 0x74       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_RX_CONTROL
decl_stmt|;
comment|/*       0x74 - 0x78       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_RX_STATUS1
decl_stmt|;
comment|/*       0x78 - 0x7c       */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_RX_STATUS2
decl_stmt|;
comment|/*       0x7c - 0x80       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|LC_BT_CLOCK0
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|u_int32_t
name|LC_BT_CLOCK1
decl_stmt|;
comment|/*       0x88 - 0x8c       */
specifier|volatile
name|u_int32_t
name|LC_BT_CLOCK2
decl_stmt|;
comment|/*       0x8c - 0x90       */
specifier|volatile
name|u_int32_t
name|LC_BT_CLOCK3
decl_stmt|;
comment|/*       0x90 - 0x94       */
specifier|volatile
name|u_int32_t
name|LC_SYM_TIME0
decl_stmt|;
comment|/*       0x94 - 0x98       */
specifier|volatile
name|u_int32_t
name|LC_SYM_TIME1
decl_stmt|;
comment|/*       0x98 - 0x9c       */
specifier|volatile
name|u_int32_t
name|LC_SYM_TIME2
decl_stmt|;
comment|/*       0x9c - 0xa0       */
specifier|volatile
name|u_int32_t
name|LC_SYM_TIME3
decl_stmt|;
comment|/*       0xa0 - 0xa4       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xa4 - 0xa8       */
specifier|volatile
name|u_int32_t
name|LC_ABORT
decl_stmt|;
comment|/*       0xa8 - 0xac       */
specifier|volatile
name|u_int32_t
name|LC_PRBS
decl_stmt|;
comment|/*       0xac - 0xb0       */
specifier|volatile
name|u_int32_t
name|LC_LAST_CORR_HECOK
decl_stmt|;
comment|/*       0xb0 - 0xb4       */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x4c
index|]
decl_stmt|;
comment|/*       0xb4 - 0x100      */
specifier|volatile
name|u_int32_t
name|LC_SM_AFH_TABLE
index|[
literal|24
index|]
decl_stmt|;
comment|/*      0x100 - 0x160      */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x20
index|]
decl_stmt|;
comment|/*      0x160 - 0x180      */
specifier|volatile
name|u_int32_t
name|LC_SM_AFH_BITMAP_0
decl_stmt|;
comment|/*      0x180 - 0x184      */
specifier|volatile
name|u_int32_t
name|LC_SM_AFH_BITMAP_1
decl_stmt|;
comment|/*      0x184 - 0x188      */
specifier|volatile
name|u_int32_t
name|LC_SM_AFH_BITMAP_2
decl_stmt|;
comment|/*      0x188 - 0x18c      */
specifier|volatile
name|u_int32_t
name|LC_STAT0
decl_stmt|;
comment|/*      0x18c - 0x190      */
specifier|volatile
name|u_int32_t
name|LC_STAT1
decl_stmt|;
comment|/*      0x190 - 0x194      */
specifier|volatile
name|u_int32_t
name|LC_STAT2
decl_stmt|;
comment|/*      0x194 - 0x198      */
specifier|volatile
name|u_int32_t
name|LC_STAT3
decl_stmt|;
comment|/*      0x198 - 0x19c      */
specifier|volatile
name|u_int32_t
name|LC_STAT4
decl_stmt|;
comment|/*      0x19c - 0x1a0      */
specifier|volatile
name|u_int32_t
name|LC_STAT5
decl_stmt|;
comment|/*      0x1a0 - 0x1a4      */
specifier|volatile
name|u_int32_t
name|LC_STAT6
decl_stmt|;
comment|/*      0x1a4 - 0x1a8      */
specifier|volatile
name|u_int32_t
name|LC_STAT7
decl_stmt|;
comment|/*      0x1a8 - 0x1ac      */
specifier|volatile
name|u_int32_t
name|LC_STAT8
decl_stmt|;
comment|/*      0x1ac - 0x1b0      */
specifier|volatile
name|u_int32_t
name|LC_STAT9
decl_stmt|;
comment|/*      0x1b0 - 0x1b4      */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x14c
index|]
decl_stmt|;
comment|/*      0x1b4 - 0x300      */
specifier|volatile
name|u_int32_t
name|LC_INTERRUPT_RAW
decl_stmt|;
comment|/*      0x300 - 0x304      */
specifier|volatile
name|u_int32_t
name|LC_INTERRUPT_EN
decl_stmt|;
comment|/*      0x304 - 0x308      */
specifier|volatile
name|u_int32_t
name|LC_INTERRUPT_RX_STATUS
decl_stmt|;
comment|/*      0x308 - 0x30c      */
specifier|volatile
name|u_int32_t
name|LC_AUDIO_DATAPATH
decl_stmt|;
comment|/*      0x30c - 0x310      */
specifier|volatile
name|u_int32_t
name|LC_VOICE_CHAN0
decl_stmt|;
comment|/*      0x310 - 0x314      */
specifier|volatile
name|u_int32_t
name|LC_VOICE_CHAN1
decl_stmt|;
comment|/*      0x314 - 0x318      */
specifier|volatile
name|u_int32_t
name|LC_VOICE_CHAN0_RX_ENERGY
decl_stmt|;
comment|/*      0x318 - 0x31c      */
specifier|volatile
name|u_int32_t
name|LC_VOICE_CHAN1_RX_ENERGY
decl_stmt|;
comment|/*      0x31c - 0x320      */
specifier|volatile
name|u_int32_t
name|LC_VOICE_CHAN0_TX_ENERGY
decl_stmt|;
comment|/*      0x320 - 0x324      */
specifier|volatile
name|u_int32_t
name|LC_VOICE_CHAN1_TX_ENERGY
decl_stmt|;
comment|/*      0x324 - 0x328      */
specifier|volatile
name|u_int32_t
name|LC_VOICE_CHAN0_ZERO_CROSS
decl_stmt|;
comment|/*      0x328 - 0x32c      */
specifier|volatile
name|u_int32_t
name|LC_VOICE_CHAN1_ZERO_CROSS
decl_stmt|;
comment|/*      0x32c - 0x330      */
specifier|volatile
name|char
name|pad__5
index|[
literal|0xd0
index|]
decl_stmt|;
comment|/*      0x330 - 0x400      */
specifier|volatile
name|u_int32_t
name|LC_RX_CTRL_DATAPATH
decl_stmt|;
comment|/*      0x400 - 0x404      */
specifier|volatile
name|u_int32_t
name|LC_DEBUG
decl_stmt|;
comment|/*      0x404 - 0x408      */
specifier|volatile
name|u_int32_t
name|LC_TX_CTRL_DATAPATH
decl_stmt|;
comment|/*      0x408 - 0x40c      */
specifier|volatile
name|u_int32_t
name|LC_COMMAND9
decl_stmt|;
comment|/*      0x40c - 0x410      */
specifier|volatile
name|u_int32_t
name|BT_CLOCK0_FREE_RUN
decl_stmt|;
comment|/*      0x410 - 0x414      */
specifier|volatile
name|u_int32_t
name|BT_CLOCK1_FREE_RUN
decl_stmt|;
comment|/*      0x414 - 0x418      */
specifier|volatile
name|u_int32_t
name|BT_CLOCK2_FREE_RUN
decl_stmt|;
comment|/*      0x418 - 0x41c      */
specifier|volatile
name|u_int32_t
name|BT_CLOCK3_FREE_RUN
decl_stmt|;
comment|/*      0x41c - 0x420      */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_COMMAND10
decl_stmt|;
comment|/*      0x420 - 0x424      */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_TIMING_2
decl_stmt|;
comment|/*      0x424 - 0x428      */
specifier|volatile
name|u_int32_t
name|LC_DEV_PARAM_COMMAND11
decl_stmt|;
comment|/*      0x428 - 0x42c      */
specifier|volatile
name|u_int32_t
name|MCI_SUB_PRIORITY_TABLE_0
decl_stmt|;
comment|/*      0x42c - 0x430      */
specifier|volatile
name|u_int32_t
name|MCI_SUB_PRIORITY_TABLE_1
decl_stmt|;
comment|/*      0x430 - 0x434      */
specifier|volatile
name|u_int32_t
name|MCI_SUB_PRIORITY_TABLE_2
decl_stmt|;
comment|/*      0x434 - 0x438      */
specifier|volatile
name|u_int32_t
name|MCI_SUB_PRIORITY_TABLE_3
decl_stmt|;
comment|/*      0x438 - 0x43c      */
specifier|volatile
name|u_int32_t
name|MCI_SUB_PRIORITY_TABLE_4
decl_stmt|;
comment|/*      0x43c - 0x440      */
specifier|volatile
name|u_int32_t
name|MCI_COMMAND0
decl_stmt|;
comment|/*      0x440 - 0x444      */
specifier|volatile
name|u_int32_t
name|MCI_COMMAND1
decl_stmt|;
comment|/*      0x444 - 0x448      */
specifier|volatile
name|u_int32_t
name|MCI_COMMAND2
decl_stmt|;
comment|/*      0x448 - 0x44c      */
specifier|volatile
name|u_int32_t
name|MCI_RX_CTRL
decl_stmt|;
comment|/*      0x44c - 0x450      */
specifier|volatile
name|u_int32_t
name|MCI_TX_CTRL
decl_stmt|;
comment|/*      0x450 - 0x454      */
specifier|volatile
name|u_int32_t
name|MCI_MSG_ATTRIBUTES_TABLE
decl_stmt|;
comment|/*      0x454 - 0x458      */
specifier|volatile
name|u_int32_t
name|MCI_SCHD_TABLE_0
decl_stmt|;
comment|/*      0x458 - 0x45c      */
specifier|volatile
name|u_int32_t
name|MCI_SCHD_TABLE_1
decl_stmt|;
comment|/*      0x45c - 0x460      */
specifier|volatile
name|u_int32_t
name|MCI_GPM_0
decl_stmt|;
comment|/*      0x460 - 0x464      */
specifier|volatile
name|u_int32_t
name|MCI_GPM_1
decl_stmt|;
comment|/*      0x464 - 0x468      */
specifier|volatile
name|u_int32_t
name|MCI_INTERRUPT_RAW
decl_stmt|;
comment|/*      0x468 - 0x46c      */
specifier|volatile
name|u_int32_t
name|MCI_INTERRUPT_EN
decl_stmt|;
comment|/*      0x46c - 0x470      */
specifier|volatile
name|u_int32_t
name|MCI_REMOTE_CPU_INT
decl_stmt|;
comment|/*      0x470 - 0x474      */
specifier|volatile
name|u_int32_t
name|MCI_REMOTE_CPU_INT_EN
decl_stmt|;
comment|/*      0x474 - 0x478      */
specifier|volatile
name|u_int32_t
name|MCI_INTERRUPT_RX_MSG_RAW
decl_stmt|;
comment|/*      0x478 - 0x47c      */
specifier|volatile
name|u_int32_t
name|MCI_INTERRUPT_RX_MSG_EN
decl_stmt|;
comment|/*      0x47c - 0x480      */
specifier|volatile
name|u_int32_t
name|MCI_CPU_INT
decl_stmt|;
comment|/*      0x480 - 0x484      */
specifier|volatile
name|u_int32_t
name|MCI_RX_STATUS
decl_stmt|;
comment|/*      0x484 - 0x488      */
specifier|volatile
name|u_int32_t
name|WBTIMER
decl_stmt|;
comment|/*      0x488 - 0x48c      */
specifier|volatile
name|u_int32_t
name|WB_BTCLK_SYNC_PN0
decl_stmt|;
comment|/*      0x48c - 0x490      */
specifier|volatile
name|u_int32_t
name|WB_BTCLK_SYNC_PN1
decl_stmt|;
comment|/*      0x490 - 0x494      */
specifier|volatile
name|u_int32_t
name|WB_BTCLK_SYNC_PN2
decl_stmt|;
comment|/*      0x494 - 0x498      */
specifier|volatile
name|u_int32_t
name|WB_BTCLK_SYNC_PN3
decl_stmt|;
comment|/*      0x498 - 0x49c      */
specifier|volatile
name|u_int32_t
name|LC_SERIAL
decl_stmt|;
comment|/*      0x49c - 0x4a0      */
specifier|volatile
name|u_int32_t
name|LC_PHY_ERR
decl_stmt|;
comment|/*      0x4a0 - 0x4a4      */
specifier|volatile
name|u_int32_t
name|LC_PHY_ERR_0
decl_stmt|;
comment|/*      0x4a4 - 0x4a8      */
specifier|volatile
name|u_int32_t
name|LC_PHY_ERR_1
decl_stmt|;
comment|/*      0x4a8 - 0x4ac      */
specifier|volatile
name|u_int32_t
name|LC_PHY_ERR_2
decl_stmt|;
comment|/*      0x4ac - 0x4b0      */
specifier|volatile
name|u_int32_t
name|LC_PHY_ERR_3
decl_stmt|;
comment|/*      0x4b0 - 0x4b4      */
specifier|volatile
name|u_int32_t
name|LC_PHY_ERR_4
decl_stmt|;
comment|/*      0x4b4 - 0x4b8      */
specifier|volatile
name|u_int32_t
name|LC_PHY_ERR_5
decl_stmt|;
comment|/*      0x4b8 - 0x4bc      */
specifier|volatile
name|u_int32_t
name|LC_SF_CTRL
decl_stmt|;
comment|/*      0x4bc - 0x4c0      */
specifier|volatile
name|u_int32_t
name|LC_DUMMY
decl_stmt|;
comment|/*      0x4c0 - 0x4c4      */
specifier|volatile
name|u_int32_t
name|LC_FOR_BQB
decl_stmt|;
comment|/*      0x4c4 - 0x4c8      */
specifier|volatile
name|u_int32_t
name|SHARED_LNA_PARAM
decl_stmt|;
comment|/*      0x4c8 - 0x4cc      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS0_SUB1
decl_stmt|;
comment|/*      0x4cc - 0x4d0      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS1_SUB1
decl_stmt|;
comment|/*      0x4d0 - 0x4d4      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS0_SUB2
decl_stmt|;
comment|/*      0x4d4 - 0x4d8      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS1_SUB2
decl_stmt|;
comment|/*      0x4d8 - 0x4dc      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS0_SUB3
decl_stmt|;
comment|/*      0x4dc - 0x4e0      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS1_SUB3
decl_stmt|;
comment|/*      0x4e0 - 0x4e4      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS0_SUB4
decl_stmt|;
comment|/*      0x4e4 - 0x4e8      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS1_SUB4
decl_stmt|;
comment|/*      0x4e8 - 0x4ec      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS0_SUB5
decl_stmt|;
comment|/*      0x4ec - 0x4f0      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS1_SUB5
decl_stmt|;
comment|/*      0x4f0 - 0x4f4      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS0_SUB6
decl_stmt|;
comment|/*      0x4f4 - 0x4f8      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS1_SUB6
decl_stmt|;
comment|/*      0x4f8 - 0x4fc      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS0_SUB7
decl_stmt|;
comment|/*      0x4fc - 0x500      */
specifier|volatile
name|u_int32_t
name|LC_CHNASS1_SUB7
decl_stmt|;
comment|/*      0x500 - 0x504      */
specifier|volatile
name|u_int32_t
name|LC_LE
decl_stmt|;
comment|/*      0x504 - 0x508      */
specifier|volatile
name|u_int32_t
name|MCI_SCHD_TABLE_2
decl_stmt|;
comment|/*      0x508 - 0x50c      */
specifier|volatile
name|u_int32_t
name|WB_BTCLK_SYNC_LE_PN0
decl_stmt|;
comment|/*      0x50c - 0x510      */
specifier|volatile
name|u_int32_t
name|WB_BTCLK_SYNC_LE_PN1
decl_stmt|;
comment|/*      0x510 - 0x514      */
specifier|volatile
name|u_int32_t
name|LC_TB_LLR
decl_stmt|;
comment|/*      0x514 - 0x518      */
specifier|volatile
name|u_int32_t
name|LC_SYM_TIME0_FREE_RUN
decl_stmt|;
comment|/*      0x518 - 0x51c      */
specifier|volatile
name|u_int32_t
name|LC_SYM_TIME1_FREE_RUN
decl_stmt|;
comment|/*      0x51c - 0x520      */
specifier|volatile
name|u_int32_t
name|LC_SYM_TIME2_FREE_RUN
decl_stmt|;
comment|/*      0x520 - 0x524      */
specifier|volatile
name|u_int32_t
name|LC_SYM_TIME3_FREE_RUN
decl_stmt|;
comment|/*      0x524 - 0x528      */
specifier|volatile
name|u_int32_t
name|WBTIMERCLK
decl_stmt|;
comment|/*      0x528 - 0x52c      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__synthBT_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|SYNTHBT1
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|SYNTHBT2
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|SYNTHBT3
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|SYNTHBT4
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|SYNTHBT5
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|SYNTHBT6
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|SYNTHBT7
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|SYNTHBT8
decl_stmt|;
comment|/*       0x1c - 0x20       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__BIASBT_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|BIASBT1
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BIASBT2
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|BIASBT3
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|BIASBT4
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|BIASBT5
decl_stmt|;
comment|/*       0x10 - 0x14       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__TOPBT_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|TOPBT1
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|TOPBT2
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|TOPBT3
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|TOPBT4
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|TOPBT5
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|TOPBT6
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|TOPBT7
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|TOPBT8
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|TOPBT9
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|TOPBT10
decl_stmt|;
comment|/*       0x24 - 0x28       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__CLK_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|CLK1
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|CLK2
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|CLK3
decl_stmt|;
comment|/*        0x8 - 0xc        */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__analog_intf_athr_wlan_reg_csr
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x880
index|]
decl_stmt|;
comment|/*        0x0 - 0x880      */
name|struct
name|jupiter_reg_map__synthBT_reg_csr
name|synth_reg_map
decl_stmt|;
comment|/*      0x880 - 0x8a0      */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x20
index|]
decl_stmt|;
comment|/*      0x8a0 - 0x8c0      */
name|struct
name|jupiter_reg_map__BIASBT_reg_csr
name|BIAS_reg_map
decl_stmt|;
comment|/*      0x8c0 - 0x8d4      */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x2c
index|]
decl_stmt|;
comment|/*      0x8d4 - 0x900      */
name|struct
name|jupiter_reg_map__TOPBT_reg_csr
name|TOP_reg_map
decl_stmt|;
comment|/*      0x900 - 0x928      */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x158
index|]
decl_stmt|;
comment|/*      0x928 - 0xa80      */
name|struct
name|jupiter_reg_map__CLK_reg_csr
name|CLK_reg_map
decl_stmt|;
comment|/*      0xa80 - 0xa8c      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__efuse_reg
block|{
specifier|volatile
name|u_int32_t
name|OTP_MEM
index|[
literal|128
index|]
decl_stmt|;
comment|/*        0x0 - 0x200      */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x1d00
index|]
decl_stmt|;
comment|/*      0x200 - 0x1f00     */
specifier|volatile
name|u_int32_t
name|OTP_INTF0
decl_stmt|;
comment|/*     0x1f00 - 0x1f04     */
specifier|volatile
name|u_int32_t
name|OTP_INTF1
decl_stmt|;
comment|/*     0x1f04 - 0x1f08     */
specifier|volatile
name|u_int32_t
name|OTP_INTF2
decl_stmt|;
comment|/*     0x1f08 - 0x1f0c     */
specifier|volatile
name|u_int32_t
name|OTP_INTF3
decl_stmt|;
comment|/*     0x1f0c - 0x1f10     */
specifier|volatile
name|u_int32_t
name|OTP_INTF4
decl_stmt|;
comment|/*     0x1f10 - 0x1f14     */
specifier|volatile
name|u_int32_t
name|OTP_INTF5
decl_stmt|;
comment|/*     0x1f14 - 0x1f18     */
specifier|volatile
name|u_int32_t
name|OTP_STATUS0
decl_stmt|;
comment|/*     0x1f18 - 0x1f1c     */
specifier|volatile
name|u_int32_t
name|OTP_STATUS1
decl_stmt|;
comment|/*     0x1f1c - 0x1f20     */
specifier|volatile
name|u_int32_t
name|OTP_INTF6
decl_stmt|;
comment|/*     0x1f20 - 0x1f24     */
specifier|volatile
name|u_int32_t
name|OTP_LDO_CONTROL
decl_stmt|;
comment|/*     0x1f24 - 0x1f28     */
specifier|volatile
name|u_int32_t
name|OTP_LDO_POWER_GOOD
decl_stmt|;
comment|/*     0x1f28 - 0x1f2c     */
specifier|volatile
name|u_int32_t
name|OTP_LDO_STATUS
decl_stmt|;
comment|/*     0x1f2c - 0x1f30     */
specifier|volatile
name|u_int32_t
name|OTP_VDDQ_HOLD_TIME
decl_stmt|;
comment|/*     0x1f30 - 0x1f34     */
specifier|volatile
name|u_int32_t
name|OTP_PGENB_SETUP_HOLD_TIME
decl_stmt|;
comment|/*     0x1f34 - 0x1f38     */
specifier|volatile
name|u_int32_t
name|OTP_STROBE_PULSE_INTERVAL
decl_stmt|;
comment|/*     0x1f38 - 0x1f3c     */
specifier|volatile
name|u_int32_t
name|OTP_CSB_ADDR_LOAD_SETUP_HOLD
decl_stmt|;
comment|/*     0x1f3c - 0x1f40     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__modem_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|START_REG
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|RX_STATUS
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|AC1_L
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|AC1_U
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|AC2_L
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|AC2_U
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|TX_LATE
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|RF_SYNTH
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|RF_RX_CONTROL
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|RF_TX_CONTROL
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|RF_FORCE
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|MODEM_CONTROL
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|DC_FREQ_TRACK
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|PSK_TRACK
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|PSK_TRACK2
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|DEMOD_CTRL1
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|DEMOD_CTRL2
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|CORR_PARAM1
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|CORR_PARAM2
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|RX_LFDATA
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|ROT
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|TX
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|u_int32_t
name|TX_GFSK1
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|TX_GFSK2
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|TX_POWER_CORR0
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|TX_POWER_CORR1
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|u_int32_t
name|SYNTH_CHN0
decl_stmt|;
comment|/*       0x68 - 0x6c       */
specifier|volatile
name|u_int32_t
name|SYNTH_OFFSET
decl_stmt|;
comment|/*       0x6c - 0x70       */
specifier|volatile
name|u_int32_t
name|MODEM_DEBUG
decl_stmt|;
comment|/*       0x70 - 0x74       */
specifier|volatile
name|u_int32_t
name|AGC_BYPASS
decl_stmt|;
comment|/*       0x74 - 0x78       */
specifier|volatile
name|u_int32_t
name|AGC_SAT
decl_stmt|;
comment|/*       0x78 - 0x7c       */
specifier|volatile
name|u_int32_t
name|AGC_DET1
decl_stmt|;
comment|/*       0x7c - 0x80       */
specifier|volatile
name|u_int32_t
name|AGC_DET2
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|AGC_GAIN1
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|u_int32_t
name|AGC_GAIN2
decl_stmt|;
comment|/*       0x88 - 0x8c       */
specifier|volatile
name|u_int32_t
name|AGC_LINEAR_BLK
decl_stmt|;
comment|/*       0x8c - 0x90       */
specifier|volatile
name|u_int32_t
name|AGC_NONLIN_BLK
decl_stmt|;
comment|/*       0x90 - 0x94       */
specifier|volatile
name|u_int32_t
name|AGC_MIN_POWER
decl_stmt|;
comment|/*       0x94 - 0x98       */
specifier|volatile
name|u_int32_t
name|AGC_SLNA_SET0
decl_stmt|;
comment|/*       0x98 - 0x9c       */
specifier|volatile
name|u_int32_t
name|AGC_SLNA_SET1
decl_stmt|;
comment|/*       0x9c - 0xa0       */
specifier|volatile
name|u_int32_t
name|AGC_SLNA_SET2
decl_stmt|;
comment|/*       0xa0 - 0xa4       */
specifier|volatile
name|u_int32_t
name|AGC_SLNA_SET3
decl_stmt|;
comment|/*       0xa4 - 0xa8       */
specifier|volatile
name|u_int32_t
name|AGC_GAIN1_LEAN
decl_stmt|;
comment|/*       0xa8 - 0xac       */
specifier|volatile
name|u_int32_t
name|MODEM_CTRL
decl_stmt|;
comment|/*       0xac - 0xb0       */
specifier|volatile
name|u_int32_t
name|DEMOD_CTRL3
decl_stmt|;
comment|/*       0xb0 - 0xb4       */
specifier|volatile
name|u_int32_t
name|DEMOD_CTRL4
decl_stmt|;
comment|/*       0xb4 - 0xb8       */
specifier|volatile
name|u_int32_t
name|TX_GFSK3
decl_stmt|;
comment|/*       0xb8 - 0xbc       */
specifier|volatile
name|u_int32_t
name|LE_DEMOD
decl_stmt|;
comment|/*       0xbc - 0xc0       */
specifier|volatile
name|u_int32_t
name|AGC_LE1
decl_stmt|;
comment|/*       0xc0 - 0xc4       */
specifier|volatile
name|u_int32_t
name|AGC_LE2
decl_stmt|;
comment|/*       0xc4 - 0xc8       */
specifier|volatile
name|u_int32_t
name|AGC_LE3
decl_stmt|;
comment|/*       0xc8 - 0xcc       */
specifier|volatile
name|u_int32_t
name|AGC_LE4
decl_stmt|;
comment|/*       0xcc - 0xd0       */
specifier|volatile
name|u_int32_t
name|AGC_LE5
decl_stmt|;
comment|/*       0xd0 - 0xd4       */
specifier|volatile
name|u_int32_t
name|AGC_LE6
decl_stmt|;
comment|/*       0xd4 - 0xd8       */
specifier|volatile
name|u_int32_t
name|LE_FREQ
decl_stmt|;
comment|/*       0xd8 - 0xdc       */
specifier|volatile
name|u_int32_t
name|LE_BLOCKER
decl_stmt|;
comment|/*       0xdc - 0xe0       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x420
index|]
decl_stmt|;
comment|/*       0xe0 - 0x500      */
specifier|volatile
name|u_int32_t
name|AGC_GAIN_TABLE
index|[
literal|128
index|]
decl_stmt|;
comment|/*      0x500 - 0x700      */
specifier|volatile
name|u_int32_t
name|TX_ULP_CNTRL
decl_stmt|;
comment|/*      0x700 - 0x704      */
specifier|volatile
name|u_int32_t
name|SS_MANUAL1
decl_stmt|;
comment|/*      0x704 - 0x708      */
specifier|volatile
name|u_int32_t
name|SS_MANUAL2
decl_stmt|;
comment|/*      0x708 - 0x70c      */
specifier|volatile
name|u_int32_t
name|SS_RADIO_CTRL
decl_stmt|;
comment|/*      0x70c - 0x710      */
specifier|volatile
name|u_int32_t
name|PHY_ERR_CTRL1
decl_stmt|;
comment|/*      0x710 - 0x714      */
specifier|volatile
name|u_int32_t
name|PHY_ERR_CTRL2
decl_stmt|;
comment|/*      0x714 - 0x718      */
specifier|volatile
name|u_int32_t
name|PHY_ERR_CTRL3
decl_stmt|;
comment|/*      0x718 - 0x71c      */
specifier|volatile
name|u_int32_t
name|PHY_ERR_CTRL4
decl_stmt|;
comment|/*      0x71c - 0x720      */
specifier|volatile
name|u_int32_t
name|PHY_ERR_STATUS
decl_stmt|;
comment|/*      0x720 - 0x724      */
specifier|volatile
name|u_int32_t
name|RBIST_ENABLE_CONTROL
decl_stmt|;
comment|/*      0x724 - 0x728      */
specifier|volatile
name|u_int32_t
name|RBIST_TX_DC
decl_stmt|;
comment|/*      0x728 - 0x72c      */
specifier|volatile
name|u_int32_t
name|RBIST_TX_TONE0
decl_stmt|;
comment|/*      0x72c - 0x730      */
specifier|volatile
name|u_int32_t
name|RBIST_TX_TONE1
decl_stmt|;
comment|/*      0x730 - 0x734      */
specifier|volatile
name|u_int32_t
name|RBIST_TX_TONE2
decl_stmt|;
comment|/*      0x734 - 0x738      */
specifier|volatile
name|u_int32_t
name|RBIST_TX_RAMP_I
decl_stmt|;
comment|/*      0x738 - 0x73c      */
specifier|volatile
name|u_int32_t
name|RBIST_TX_RAMP_Q
decl_stmt|;
comment|/*      0x73c - 0x740      */
specifier|volatile
name|u_int32_t
name|RBIST_TX_PRBS_MAG
decl_stmt|;
comment|/*      0x740 - 0x744      */
specifier|volatile
name|u_int32_t
name|RBIST_TX_PRBS_SEED_I
decl_stmt|;
comment|/*      0x744 - 0x748      */
specifier|volatile
name|u_int32_t
name|RBIST_TX_PRBS_SEED_Q
decl_stmt|;
comment|/*      0x748 - 0x74c      */
specifier|volatile
name|u_int32_t
name|RBIST_RX_DC_OFFSET
decl_stmt|;
comment|/*      0x74c - 0x750      */
specifier|volatile
name|u_int32_t
name|RBIST_RX_DC_OFFSET_CANCEL
decl_stmt|;
comment|/*      0x750 - 0x754      */
specifier|volatile
name|u_int32_t
name|RBIST_RX_DFT
decl_stmt|;
comment|/*      0x754 - 0x758      */
specifier|volatile
name|u_int32_t
name|RBIST_RX_POWER
decl_stmt|;
comment|/*      0x758 - 0x75c      */
specifier|volatile
name|u_int32_t
name|RBIST_RX_IQ
decl_stmt|;
comment|/*      0x75c - 0x760      */
specifier|volatile
name|u_int32_t
name|RBIST_RX_I2Q2
decl_stmt|;
comment|/*      0x760 - 0x764      */
specifier|volatile
name|u_int32_t
name|RBIST_RX_HPF
decl_stmt|;
comment|/*      0x764 - 0x768      */
specifier|volatile
name|u_int32_t
name|RBIST_RX_RESULT_Q
decl_stmt|;
comment|/*      0x768 - 0x76c      */
specifier|volatile
name|u_int32_t
name|RBIST_RX_RESULT_I
decl_stmt|;
comment|/*      0x76c - 0x770      */
specifier|volatile
name|u_int32_t
name|CAL_EN
decl_stmt|;
comment|/*      0x770 - 0x774      */
specifier|volatile
name|u_int32_t
name|CAL_CONFIG
decl_stmt|;
comment|/*      0x774 - 0x778      */
specifier|volatile
name|u_int32_t
name|PASSIVE_RXIQ
decl_stmt|;
comment|/*      0x778 - 0x77c      */
specifier|volatile
name|u_int32_t
name|TX_CORR1
decl_stmt|;
comment|/*      0x77c - 0x780      */
specifier|volatile
name|u_int32_t
name|TX_CORR2
decl_stmt|;
comment|/*      0x780 - 0x784      */
specifier|volatile
name|u_int32_t
name|TX_CORR3
decl_stmt|;
comment|/*      0x784 - 0x788      */
specifier|volatile
name|u_int32_t
name|TX_CORR4
decl_stmt|;
comment|/*      0x788 - 0x78c      */
specifier|volatile
name|u_int32_t
name|RX_IQCORR_0
decl_stmt|;
comment|/*      0x78c - 0x790      */
specifier|volatile
name|u_int32_t
name|RX_IQCORR_1
decl_stmt|;
comment|/*      0x790 - 0x794      */
specifier|volatile
name|u_int32_t
name|RX_IQCORR_2
decl_stmt|;
comment|/*      0x794 - 0x798      */
specifier|volatile
name|u_int32_t
name|RX_IQCORR_3
decl_stmt|;
comment|/*      0x798 - 0x79c      */
specifier|volatile
name|u_int32_t
name|CAL_MEAS_I2_L
decl_stmt|;
comment|/*      0x79c - 0x7a0      */
specifier|volatile
name|u_int32_t
name|CAL_MEAS_I2_U
decl_stmt|;
comment|/*      0x7a0 - 0x7a4      */
specifier|volatile
name|u_int32_t
name|CAL_MEAS_IQ_L
decl_stmt|;
comment|/*      0x7a4 - 0x7a8      */
specifier|volatile
name|u_int32_t
name|CAL_MEAS_IQ_U
decl_stmt|;
comment|/*      0x7a8 - 0x7ac      */
specifier|volatile
name|u_int32_t
name|CAL_MEAS_Q2_L
decl_stmt|;
comment|/*      0x7ac - 0x7b0      */
specifier|volatile
name|u_int32_t
name|CAL_MEAS_Q2_U
decl_stmt|;
comment|/*      0x7b0 - 0x7b4      */
specifier|volatile
name|u_int32_t
name|CAP_SFT_DEBUG
decl_stmt|;
comment|/*      0x7b4 - 0x7b8      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_0
decl_stmt|;
comment|/*      0x7b8 - 0x7bc      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_1
decl_stmt|;
comment|/*      0x7bc - 0x7c0      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_2
decl_stmt|;
comment|/*      0x7c0 - 0x7c4      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_INDEX_0
decl_stmt|;
comment|/*      0x7c4 - 0x7c8      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_INDEX_1
decl_stmt|;
comment|/*      0x7c8 - 0x7cc      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_INDEX_2
decl_stmt|;
comment|/*      0x7cc - 0x7d0      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_INDEX_3
decl_stmt|;
comment|/*      0x7d0 - 0x7d4      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_INDEX_4
decl_stmt|;
comment|/*      0x7d4 - 0x7d8      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_INDEX_5
decl_stmt|;
comment|/*      0x7d8 - 0x7dc      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_INDEX_6
decl_stmt|;
comment|/*      0x7dc - 0x7e0      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_INDEX_7
decl_stmt|;
comment|/*      0x7e0 - 0x7e4      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_PARAMS_0
decl_stmt|;
comment|/*      0x7e4 - 0x7e8      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_PARAMS_1
decl_stmt|;
comment|/*      0x7e8 - 0x7ec      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_PARAMS_2
decl_stmt|;
comment|/*      0x7ec - 0x7f0      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_PARAMS_3
decl_stmt|;
comment|/*      0x7f0 - 0x7f4      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_PARAMS_4
decl_stmt|;
comment|/*      0x7f4 - 0x7f8      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_PARAMS_5
decl_stmt|;
comment|/*      0x7f8 - 0x7fc      */
specifier|volatile
name|u_int32_t
name|RX_NOTCH_PARAMS_6
decl_stmt|;
comment|/*      0x7fc - 0x800      */
specifier|volatile
name|u_int32_t
name|CHNASS_CTRL
decl_stmt|;
comment|/*      0x800 - 0x804      */
specifier|volatile
name|u_int32_t
name|CHNASS_SETUP_0
decl_stmt|;
comment|/*      0x804 - 0x808      */
specifier|volatile
name|u_int32_t
name|CHNASS_SETUP_1
decl_stmt|;
comment|/*      0x808 - 0x80c      */
specifier|volatile
name|u_int32_t
name|CHNASS_SETUP_2
decl_stmt|;
comment|/*      0x80c - 0x810      */
specifier|volatile
name|u_int32_t
name|CHNASS_SETUP_3
decl_stmt|;
comment|/*      0x810 - 0x814      */
specifier|volatile
name|u_int32_t
name|CHNASS_RSSI_0
decl_stmt|;
comment|/*      0x814 - 0x818      */
specifier|volatile
name|u_int32_t
name|CHNASS_RSSI_1
decl_stmt|;
comment|/*      0x818 - 0x81c      */
specifier|volatile
name|u_int32_t
name|SW_CTRL
decl_stmt|;
comment|/*      0x81c - 0x820      */
specifier|volatile
name|u_int32_t
name|JUPITER_CTRL
decl_stmt|;
comment|/*      0x820 - 0x824      */
specifier|volatile
name|u_int32_t
name|JUPITER_GAIN
decl_stmt|;
comment|/*      0x824 - 0x828      */
specifier|volatile
name|u_int32_t
name|AGC_HIST_SETUP
decl_stmt|;
comment|/*      0x828 - 0x82c      */
specifier|volatile
name|u_int32_t
name|AGC_HIST_BANK_0
decl_stmt|;
comment|/*      0x82c - 0x830      */
specifier|volatile
name|u_int32_t
name|AGC_HIST_BANK_1
decl_stmt|;
comment|/*      0x830 - 0x834      */
specifier|volatile
name|u_int32_t
name|AGC_HIST_BANK_2
decl_stmt|;
comment|/*      0x834 - 0x838      */
specifier|volatile
name|u_int32_t
name|AGC_HIST_BANK_3
decl_stmt|;
comment|/*      0x838 - 0x83c      */
specifier|volatile
name|u_int32_t
name|AGC_HIST_BANK_4
decl_stmt|;
comment|/*      0x83c - 0x840      */
specifier|volatile
name|u_int32_t
name|SPARE
decl_stmt|;
comment|/*      0x840 - 0x844      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__le_dma_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|LE_DMA_MASTER
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|LE_DMA_TX_CONTROL
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|LE_DMA_RX_CONTROL
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|LE_DMA_TX_HW
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|LE_DMA_RX_HW
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|LE_DMA_INT_STATUS
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|LE_DMA_TX_STATUS
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|LE_DMA_TX_STATUS_W1TC
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|LE_DMA_TX_ENABLE
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|LE_DMA_RX_STATUS
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|LE_DMA_RX_STATUS_W1TC
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|LE_DMA_RX_ENABLE
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|LE_DMA_DEBUG
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|LE_DMA_DUMMY
decl_stmt|;
comment|/*       0x34 - 0x38       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__le_reg_csr
block|{
specifier|volatile
name|u_int32_t
name|LE_PUBLIC_ADDRESS_L
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|LE_PUBLIC_ADDRESS_U
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|LE_RANDOM_ADDRESS_L
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|LE_RANDOM_ADDRESS_U
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|LE_DEV_PARAM
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|COMMAND1
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|COMMAND2
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|COMMAND3
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|COMMAND4
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|COMMAND5
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|COMMAND6
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|COMMAND7
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|COMMAND8
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|COMMAND9
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|COMMAND10
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|COMMAND11
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|COMMAND12
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|COMMAND13
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|LE_ABORT
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|LE_RX_STATUS1
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|LE_RX_STATUS2
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|LE_RX_STATUS3
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|u_int32_t
name|LE_RX_STATUS4
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|LE_RX_STATUS5
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|LE_RX_STATUS6
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|LE_RX_STATUS7
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|u_int32_t
name|LE_RX_STATUS8
decl_stmt|;
comment|/*       0x68 - 0x6c       */
specifier|volatile
name|u_int32_t
name|LE_RX_STATUS9
decl_stmt|;
comment|/*       0x6c - 0x70       */
specifier|volatile
name|u_int32_t
name|LE_INTERRUPT_EN
decl_stmt|;
comment|/*       0x70 - 0x74       */
specifier|volatile
name|u_int32_t
name|LE_INTERRUPT
decl_stmt|;
comment|/*       0x74 - 0x78       */
specifier|volatile
name|u_int32_t
name|LE_DATAPATH_CNTL
decl_stmt|;
comment|/*       0x78 - 0x7c       */
specifier|volatile
name|u_int32_t
name|LE_BT_CLOCK0
decl_stmt|;
comment|/*       0x7c - 0x80       */
specifier|volatile
name|u_int32_t
name|LE_BT_CLOCK1
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|LE_SYM_TIME0
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|u_int32_t
name|LE_SYM_TIME1
decl_stmt|;
comment|/*       0x88 - 0x8c       */
specifier|volatile
name|u_int32_t
name|LE_TIMER0
decl_stmt|;
comment|/*       0x8c - 0x90       */
specifier|volatile
name|u_int32_t
name|LE_TIMER0_FRAME
decl_stmt|;
comment|/*       0x90 - 0x94       */
specifier|volatile
name|u_int32_t
name|LE_TIMER1
decl_stmt|;
comment|/*       0x94 - 0x98       */
specifier|volatile
name|u_int32_t
name|LE_TIMER1_FRAME
decl_stmt|;
comment|/*       0x98 - 0x9c       */
specifier|volatile
name|u_int32_t
name|LE_WL_TABLE
index|[
literal|256
index|]
decl_stmt|;
comment|/*       0x9c - 0x49c      */
specifier|volatile
name|u_int32_t
name|LE_TIM
decl_stmt|;
comment|/*      0x49c - 0x4a0      */
specifier|volatile
name|u_int32_t
name|TX_ERROR_GENERATION
decl_stmt|;
comment|/*      0x4a0 - 0x4a4      */
specifier|volatile
name|u_int32_t
name|LE_FREQ_MAP0
decl_stmt|;
comment|/*      0x4a4 - 0x4a8      */
specifier|volatile
name|u_int32_t
name|LE_FREQ_MAP1
decl_stmt|;
comment|/*      0x4a8 - 0x4ac      */
specifier|volatile
name|u_int32_t
name|LE_FREQ_MAP2
decl_stmt|;
comment|/*      0x4ac - 0x4b0      */
specifier|volatile
name|u_int32_t
name|LE_FREQ_MAP3
decl_stmt|;
comment|/*      0x4b0 - 0x4b4      */
specifier|volatile
name|u_int32_t
name|LE_FREQ_MAP4
decl_stmt|;
comment|/*      0x4b4 - 0x4b8      */
specifier|volatile
name|u_int32_t
name|LE_FREQ_MAP5
decl_stmt|;
comment|/*      0x4b8 - 0x4bc      */
specifier|volatile
name|u_int32_t
name|LE_FREQ_MAP6
decl_stmt|;
comment|/*      0x4bc - 0x4c0      */
specifier|volatile
name|u_int32_t
name|LE_FREQ_MAP7
decl_stmt|;
comment|/*      0x4c0 - 0x4c4      */
specifier|volatile
name|u_int32_t
name|LE_FREQ_MAP8
decl_stmt|;
comment|/*      0x4c4 - 0x4c8      */
specifier|volatile
name|u_int32_t
name|LE_FREQ_MAP9
decl_stmt|;
comment|/*      0x4c8 - 0x4cc      */
specifier|volatile
name|u_int32_t
name|LE_DEBUG_CTRL
decl_stmt|;
comment|/*      0x4cc - 0x4d0      */
specifier|volatile
name|u_int32_t
name|LE_DEBUG_OBS
decl_stmt|;
comment|/*      0x4d0 - 0x4d4      */
specifier|volatile
name|u_int32_t
name|LE_PHY_ERR
decl_stmt|;
comment|/*      0x4d4 - 0x4d8      */
specifier|volatile
name|u_int32_t
name|LE_PHY_ERR_0
decl_stmt|;
comment|/*      0x4d8 - 0x4dc      */
specifier|volatile
name|u_int32_t
name|LE_PHY_ERR_1
decl_stmt|;
comment|/*      0x4dc - 0x4e0      */
specifier|volatile
name|u_int32_t
name|LE_PHY_ERR_2
decl_stmt|;
comment|/*      0x4e0 - 0x4e4      */
specifier|volatile
name|u_int32_t
name|LE_PHY_ERR_3
decl_stmt|;
comment|/*      0x4e4 - 0x4e8      */
specifier|volatile
name|u_int32_t
name|LE_PHY_ERR_4
decl_stmt|;
comment|/*      0x4e8 - 0x4ec      */
specifier|volatile
name|u_int32_t
name|LE_DUMMY
decl_stmt|;
comment|/*      0x4ec - 0x4f0      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|jupiter_reg_map__apb_map_csr
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x4000
index|]
decl_stmt|;
comment|/*        0x0 - 0x4000     */
name|struct
name|jupiter_reg_map__rtc_reg_csr
name|rtc
decl_stmt|;
comment|/*     0x4000 - 0x4134     */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x3ecc
index|]
decl_stmt|;
comment|/*     0x4134 - 0x8000     */
name|struct
name|jupiter_reg_map__vmc_reg_csr
name|vmc
decl_stmt|;
comment|/*     0x8000 - 0x8620     */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x39e0
index|]
decl_stmt|;
comment|/*     0x8620 - 0xc000     */
name|struct
name|jupiter_reg_map__apb_map_csr__uart_reg_csr
name|uart
decl_stmt|;
comment|/*     0xc000 - 0xc014     */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x3fec
index|]
decl_stmt|;
comment|/*     0xc014 - 0x10000    */
name|struct
name|jupiter_reg_map__si_reg_csr
name|si
decl_stmt|;
comment|/*    0x10000 - 0x10018    */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x3fe8
index|]
decl_stmt|;
comment|/*    0x10018 - 0x14000    */
name|struct
name|jupiter_reg_map__gpio_reg_csr
name|gpio
decl_stmt|;
comment|/*    0x14000 - 0x14098    */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x3f68
index|]
decl_stmt|;
comment|/*    0x14098 - 0x18000    */
name|struct
name|jupiter_reg_map__mbox_reg_csr
name|mbox
decl_stmt|;
comment|/*    0x18000 - 0x1809c    */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x3f64
index|]
decl_stmt|;
comment|/*    0x1809c - 0x1c000    */
name|struct
name|jupiter_reg_map__lc_dma_reg_csr
name|lc_dma
decl_stmt|;
comment|/*    0x1c000 - 0x1c034    */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x3fcc
index|]
decl_stmt|;
comment|/*    0x1c034 - 0x20000    */
name|struct
name|jupiter_reg_map__lc_reg_csr
name|lc
decl_stmt|;
comment|/*    0x20000 - 0x2052c    */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x2ad4
index|]
decl_stmt|;
comment|/*    0x2052c - 0x23000    */
name|struct
name|jupiter_reg_map__analog_intf_athr_wlan_reg_csr
name|analog
decl_stmt|;
comment|/*    0x23000 - 0x23a90    */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x570
index|]
decl_stmt|;
comment|/*    0x23a90 - 0x24000    */
name|struct
name|jupiter_reg_map__efuse_reg
name|efuse
decl_stmt|;
comment|/*    0x24000 - 0x25f40    */
specifier|volatile
name|char
name|pad__10
index|[
literal|0xc0
index|]
decl_stmt|;
comment|/*    0x25f40 - 0x26000    */
name|struct
name|jupiter_reg_map__modem_reg_csr
name|modem
decl_stmt|;
comment|/*    0x26000 - 0x26844    */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x37bc
index|]
decl_stmt|;
comment|/*    0x26844 - 0x2a000    */
name|struct
name|jupiter_reg_map__le_dma_reg_csr
name|le_dma
decl_stmt|;
comment|/*    0x2a000 - 0x2a038    */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x1fc8
index|]
decl_stmt|;
comment|/*    0x2a038 - 0x2c000    */
name|struct
name|jupiter_reg_map__le_reg_csr
name|le
decl_stmt|;
comment|/*    0x2c000 - 0x2c4f0    */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bt_apb_reg
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x40000
index|]
decl_stmt|;
comment|/*        0x0 - 0x40000    */
name|struct
name|jupiter_reg_map__apb_map_csr
name|bt_apb_map_block
decl_stmt|;
comment|/*    0x40000 - 0x6c800    */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|osprey_reg_map
block|{
name|struct
name|mac_dma_reg
name|mac_dma_reg_block
decl_stmt|;
comment|/*        0x0 - 0x108      */
specifier|volatile
name|char
name|pad__0
decl_stmt|;
comment|/*      0x108 - 0x0        */
name|struct
name|mac_qcu_reg
name|mac_qcu_reg_block
decl_stmt|;
comment|/*        0x0 - 0x24c      */
specifier|volatile
name|char
name|pad__1
decl_stmt|;
comment|/*      0x24c - 0x0        */
name|struct
name|mac_dcu_reg
name|mac_dcu_reg_block
decl_stmt|;
comment|/*        0x0 - 0x7fc      */
specifier|volatile
name|char
name|pad__2
decl_stmt|;
comment|/*      0x7fc - 0x0        */
name|struct
name|host_intf_reg
name|host_intf_reg_block
decl_stmt|;
comment|/*        0x0 - 0xf4       */
specifier|volatile
name|char
name|pad__3
decl_stmt|;
comment|/*       0xf4 - 0x0        */
name|struct
name|emulation_misc_regs
name|emulation_misc_reg_block
decl_stmt|;
comment|/*        0x0 - 0x30       */
specifier|volatile
name|char
name|pad__4
decl_stmt|;
comment|/*      Osprey: 0x30 - 0x0        */
name|struct
name|DWC_pcie_dbi_axi
name|DWC_pcie_dbi_axi_block
decl_stmt|;
comment|/*      Osprey: 0x0  - 0x818      */
specifier|volatile
name|char
name|pad__5
decl_stmt|;
comment|/*      0x818 - 0x0        */
name|struct
name|rtc_reg
name|rtc_reg_block
decl_stmt|;
comment|/*      Osprey: 0x0  - 0x3c, Poseidon: 0x0  - 0x40       */
specifier|volatile
name|char
name|pad__6
decl_stmt|;
comment|/*      Osprey: 0x3c - 0x0,  Poseidon: 0x40 - 0x0        */
name|struct
name|rtc_sync_reg
name|rtc_sync_reg_block
decl_stmt|;
comment|/*        0x0 - 0x1c       */
specifier|volatile
name|char
name|pad__7
decl_stmt|;
comment|/*       0x1c - 0x0        */
name|struct
name|merlin2_0_radio_reg_map
name|merlin2_0_radio_reg_map
decl_stmt|;
comment|/*        0x0 - 0x9c       */
specifier|volatile
name|char
name|pad__8
decl_stmt|;
comment|/*       0x9c - 0x0        */
name|struct
name|analog_intf_reg_csr
name|analog_intf_reg_csr_block
decl_stmt|;
comment|/*        0x0 - 0x10       */
specifier|volatile
name|char
name|pad__9
decl_stmt|;
comment|/*       0x10 - 0x0        */
name|struct
name|mac_pcu_reg
name|mac_pcu_reg_block
decl_stmt|;
comment|/*        0x0 - 0x8000     */
specifier|volatile
name|char
name|pad__10
decl_stmt|;
comment|/*     0x8000 - 0x0        */
name|struct
name|bb_reg_map
name|bb_reg_block
decl_stmt|;
comment|/*        0x0 - 0x4000     */
specifier|volatile
name|char
name|pad__11
decl_stmt|;
comment|/*     0x4000 - 0x0        */
name|struct
name|svd_reg
name|svd_reg_block
decl_stmt|;
comment|/*        0x0 - 0x2c00     */
specifier|volatile
name|char
name|pad__12
decl_stmt|;
comment|/*     0x2c00 - 0x0        */
name|struct
name|efuse_reg_WLAN
name|efuse_reg_block
decl_stmt|;
comment|/*        0x0 - 0x1f40     */
specifier|volatile
name|char
name|pad__13
decl_stmt|;
comment|/*     0x1f40 - 0x0        */
name|struct
name|radio65_reg
name|radio65_reg_block
decl_stmt|;
comment|/*     Osprey:   0x0 - 0xbd8, Poseidon: 0x0   - 0x3d8      */
specifier|volatile
name|char
name|pad__14
decl_stmt|;
comment|/*     Osprey: 0xbd8 - 0x0,   Poseidon: 0x3d8 - 0x0        */
name|struct
name|pmu_reg
name|pmu_reg_block
decl_stmt|;
comment|/*     Osprey:   0x0 - 0x8        */
specifier|volatile
name|char
name|pad__15
decl_stmt|;
comment|/*     Osprey:   0x8 - 0x0        */
name|struct
name|pcie_phy_reg_csr
name|pcie_phy_reg_block
decl_stmt|;
comment|/*        0x0 - 0xc        */
specifier|volatile
name|char
name|pad__16
decl_stmt|;
comment|/*        0xc - 0x0        */
name|struct
name|wlan_coex_reg
name|wlan_coex_reg_block
decl_stmt|;
comment|/*        0x0 - 0x264      */
specifier|volatile
name|char
name|pad__17
decl_stmt|;
comment|/*      0x264 - 0x0        */
name|struct
name|wlan_bt_glb_reg_pcie
name|glb_reg_block
decl_stmt|;
comment|/*        0x0 - 0x400      */
specifier|volatile
name|char
name|pad__18
decl_stmt|;
comment|/*      0x400 - 0x0        */
name|struct
name|bt_apb_reg
name|bt_apb_reg_block
decl_stmt|;
comment|/*     Jupiter:  0x0 - 0x2c800    */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __REG_OSPREY_REG_MAP_H__ */
end_comment

end_unit

