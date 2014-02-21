begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013 Qualcomm Atheros, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR  * OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* File:       /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/top/scorpion_reg_map.h*/
end_comment

begin_comment
comment|/* Creator:    irshad                                                        */
end_comment

begin_comment
comment|/* Time:       Wednesday Feb 15, 2012 [5:06:37 pm]                           */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Path:       /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/top*/
end_comment

begin_comment
comment|/* Arguments:  /cad/denali/blueprint/3.7.3//Linux-64bit/blueprint -dump      */
end_comment

begin_comment
comment|/*             -codegen                                                      */
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/flow/blueprint/ath_ansic.codegen*/
end_comment

begin_comment
comment|/*             -ath_ansic -Wdesc -I                                          */
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/top*/
end_comment

begin_comment
comment|/*             -I /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint */
end_comment

begin_comment
comment|/*             -I                                                            */
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/flow/blueprint*/
end_comment

begin_comment
comment|/*             -I                                                            */
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/sysconfig*/
end_comment

begin_comment
comment|/*             -odir                                                         */
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/top*/
end_comment

begin_comment
comment|/*             -eval {$INCLUDE_SYSCONFIG_FILES=1} -eval                      */
end_comment

begin_comment
comment|/*             $WAR_EV58615_for_ansic_codegen=1 scorpion_reg.rdl             */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Sources:    /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/sysconfig/mac_dcu_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/rtl/rtc/rtc_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/rtl/mac/rtl/mac_dma/blueprint/mac_dma_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/sysconfig/rtc_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/sysconfig/mac_pcu_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/rtl/mac/rtl/mac_dma/blueprint/mac_dcu_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/rtl/mac/rtl/mac_pcu/blueprint/mac_pcu_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/rtl/wmac_wrap/rtc_sync_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/rtl/mac/rtl/mac_dma/blueprint/mac_qcu_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/sysconfig/mac_dma_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/top/scorpion_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/sysconfig/bb_reg_map_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/top/scorpion_radio_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/sysconfig/svd_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/sysconfig/radio_65_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/rtl/bb/blueprint/bb_reg_map.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/sysconfig/rtc_sync_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/rtl/svd/svd_reg.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/blueprint/sysconfig/mac_qcu_reg_sysconfig.rdl*/
end_comment

begin_comment
comment|/*             /trees/irshad/irshad-scorpion/chips/scorpion/1.0/flow/blueprint/ath_ansic.pm*/
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
comment|/* Machine:    rupavathi.users.atheros.com                                   */
end_comment

begin_comment
comment|/* OS:         Linux 2.6.9-89.ELsmp                                          */
end_comment

begin_comment
comment|/* Description:                                                              */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/*This Register Map contains the complete register set for scorpion.         */
end_comment

begin_comment
comment|/*                                                                           */
end_comment

begin_comment
comment|/* Copyright (C) 2012 Denali Software Inc.  All rights reserved              */
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
name|__REG_SCORPION_REG_MAP_H__
end_ifndef

begin_define
define|#
directive|define
name|__REG_SCORPION_REG_MAP_H__
end_define

begin_include
include|#
directive|include
file|"scorpion_reg_map_macro.h"
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
specifier|volatile
name|char
name|pad__5
index|[
literal|0x4
index|]
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
specifier|volatile
name|char
name|pad__6
index|[
literal|0x4
index|]
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
specifier|volatile
name|char
name|pad__7
index|[
literal|0x4
index|]
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
specifier|volatile
name|u_int32_t
name|MAC_DMA_TIMT_0
decl_stmt|;
comment|/*      0x108 - 0x10c      */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TIMT_1
decl_stmt|;
comment|/*      0x10c - 0x110      */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TIMT_2
decl_stmt|;
comment|/*      0x110 - 0x114      */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TIMT_3
decl_stmt|;
comment|/*      0x114 - 0x118      */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TIMT_4
decl_stmt|;
comment|/*      0x118 - 0x11c      */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TIMT_5
decl_stmt|;
comment|/*      0x11c - 0x120      */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TIMT_6
decl_stmt|;
comment|/*      0x120 - 0x124      */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TIMT_7
decl_stmt|;
comment|/*      0x124 - 0x128      */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TIMT_8
decl_stmt|;
comment|/*      0x128 - 0x12c      */
specifier|volatile
name|u_int32_t
name|MAC_DMA_TIMT_9
decl_stmt|;
comment|/*      0x12c - 0x130      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mac_qcu_reg
block|{
specifier|volatile
name|u_int32_t
name|MAC_QCU_TXDP
index|[
literal|10
index|]
decl_stmt|;
comment|/*        0x0 - 0x28       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*       0x28 - 0x30       */
specifier|volatile
name|u_int32_t
name|MAC_QCU_STATUS_RING_START
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|MAC_QCU_STATUS_RING_END
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|MAC_QCU_STATUS_RING_CURRENT
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|MAC_QCU_TXE
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*       0x44 - 0x80       */
specifier|volatile
name|u_int32_t
name|MAC_QCU_TXD
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*       0x84 - 0xc0       */
specifier|volatile
name|u_int32_t
name|MAC_QCU_CBR
index|[
literal|10
index|]
decl_stmt|;
comment|/*       0xc0 - 0xe8       */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x18
index|]
decl_stmt|;
comment|/*       0xe8 - 0x100      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_RDYTIME
index|[
literal|10
index|]
decl_stmt|;
comment|/*      0x100 - 0x128      */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x18
index|]
decl_stmt|;
comment|/*      0x128 - 0x140      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_ONESHOT_ARM_SC
decl_stmt|;
comment|/*      0x140 - 0x144      */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x144 - 0x180      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_ONESHOT_ARM_CC
decl_stmt|;
comment|/*      0x180 - 0x184      */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x184 - 0x1c0      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_MISC
index|[
literal|10
index|]
decl_stmt|;
comment|/*      0x1c0 - 0x1e8      */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x18
index|]
decl_stmt|;
comment|/*      0x1e8 - 0x200      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_CNT
index|[
literal|10
index|]
decl_stmt|;
comment|/*      0x200 - 0x228      */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x18
index|]
decl_stmt|;
comment|/*      0x228 - 0x240      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_RDYTIME_SHDN
decl_stmt|;
comment|/*      0x240 - 0x244      */
specifier|volatile
name|u_int32_t
name|MAC_QCU_DESC_CRC_CHK
decl_stmt|;
comment|/*      0x244 - 0x248      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mac_dcu_reg
block|{
specifier|volatile
name|u_int32_t
name|MAC_DCU_QCUMASK
index|[
literal|10
index|]
decl_stmt|;
comment|/*        0x0 - 0x28       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*       0x28 - 0x30       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_GBL_IFS_SIFS
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU0_31_0
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU8_31_0
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_LCL_IFS
index|[
literal|10
index|]
decl_stmt|;
comment|/*       0x40 - 0x68       */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*       0x68 - 0x70       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_GBL_IFS_SLOT
decl_stmt|;
comment|/*       0x70 - 0x74       */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x74 - 0x78       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU0_63_32
decl_stmt|;
comment|/*       0x78 - 0x7c       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU8_63_32
decl_stmt|;
comment|/*       0x7c - 0x80       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_RETRY_LIMIT
index|[
literal|10
index|]
decl_stmt|;
comment|/*       0x80 - 0xa8       */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*       0xa8 - 0xb0       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_GBL_IFS_EIFS
decl_stmt|;
comment|/*       0xb0 - 0xb4       */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xb4 - 0xb8       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU0_95_64
decl_stmt|;
comment|/*       0xb8 - 0xbc       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU8_95_64
decl_stmt|;
comment|/*       0xbc - 0xc0       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_CHANNEL_TIME
index|[
literal|10
index|]
decl_stmt|;
comment|/*       0xc0 - 0xe8       */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*       0xe8 - 0xf0       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_GBL_IFS_MISC
decl_stmt|;
comment|/*       0xf0 - 0xf4       */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0xf4 - 0xf8       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU0_127_96
decl_stmt|;
comment|/*       0xf8 - 0xfc       */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU8_127_96
decl_stmt|;
comment|/*       0xfc - 0x100      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_MISC
index|[
literal|10
index|]
decl_stmt|;
comment|/*      0x100 - 0x128      */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*      0x128 - 0x138      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU1_31_0
decl_stmt|;
comment|/*      0x138 - 0x13c      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU9_31_0
decl_stmt|;
comment|/*      0x13c - 0x140      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_SEQ
decl_stmt|;
comment|/*      0x140 - 0x144      */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x34
index|]
decl_stmt|;
comment|/*      0x144 - 0x178      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU1_63_32
decl_stmt|;
comment|/*      0x178 - 0x17c      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU9_63_32
decl_stmt|;
comment|/*      0x17c - 0x180      */
specifier|volatile
name|char
name|pad__10
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*      0x180 - 0x1b8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU1_95_64
decl_stmt|;
comment|/*      0x1b8 - 0x1bc      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU9_95_64
decl_stmt|;
comment|/*      0x1bc - 0x1c0      */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*      0x1c0 - 0x1f8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU1_127_96
decl_stmt|;
comment|/*      0x1f8 - 0x1fc      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU9_127_96
decl_stmt|;
comment|/*      0x1fc - 0x200      */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*      0x200 - 0x238      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU2_31_0
decl_stmt|;
comment|/*      0x238 - 0x23c      */
specifier|volatile
name|char
name|pad__13
index|[
literal|0x34
index|]
decl_stmt|;
comment|/*      0x23c - 0x270      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_PAUSE
decl_stmt|;
comment|/*      0x270 - 0x274      */
specifier|volatile
name|char
name|pad__14
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x274 - 0x278      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU2_63_32
decl_stmt|;
comment|/*      0x278 - 0x27c      */
specifier|volatile
name|char
name|pad__15
index|[
literal|0x34
index|]
decl_stmt|;
comment|/*      0x27c - 0x2b0      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_WOW_KACFG
decl_stmt|;
comment|/*      0x2b0 - 0x2b4      */
specifier|volatile
name|char
name|pad__16
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x2b4 - 0x2b8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU2_95_64
decl_stmt|;
comment|/*      0x2b8 - 0x2bc      */
specifier|volatile
name|char
name|pad__17
index|[
literal|0x34
index|]
decl_stmt|;
comment|/*      0x2bc - 0x2f0      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXSLOT
decl_stmt|;
comment|/*      0x2f0 - 0x2f4      */
specifier|volatile
name|char
name|pad__18
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x2f4 - 0x2f8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU2_127_96
decl_stmt|;
comment|/*      0x2f8 - 0x2fc      */
specifier|volatile
name|char
name|pad__19
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x2fc - 0x338      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU3_31_0
decl_stmt|;
comment|/*      0x338 - 0x33c      */
specifier|volatile
name|char
name|pad__20
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x33c - 0x378      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU3_63_32
decl_stmt|;
comment|/*      0x378 - 0x37c      */
specifier|volatile
name|char
name|pad__21
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x37c - 0x3b8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU3_95_64
decl_stmt|;
comment|/*      0x3b8 - 0x3bc      */
specifier|volatile
name|char
name|pad__22
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x3bc - 0x3f8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU3_127_96
decl_stmt|;
comment|/*      0x3f8 - 0x3fc      */
specifier|volatile
name|char
name|pad__23
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x3fc - 0x438      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU4_31_0
decl_stmt|;
comment|/*      0x438 - 0x43c      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_CLEAR
decl_stmt|;
comment|/*      0x43c - 0x440      */
specifier|volatile
name|char
name|pad__24
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*      0x440 - 0x478      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU4_63_32
decl_stmt|;
comment|/*      0x478 - 0x47c      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_SET
decl_stmt|;
comment|/*      0x47c - 0x480      */
specifier|volatile
name|char
name|pad__25
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*      0x480 - 0x4b8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU4_95_64
decl_stmt|;
comment|/*      0x4b8 - 0x4bc      */
specifier|volatile
name|char
name|pad__26
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x4bc - 0x4f8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU4_127_96
decl_stmt|;
comment|/*      0x4f8 - 0x4fc      */
specifier|volatile
name|char
name|pad__27
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x4fc - 0x538      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU5_31_0
decl_stmt|;
comment|/*      0x538 - 0x53c      */
specifier|volatile
name|char
name|pad__28
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x53c - 0x578      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU5_63_32
decl_stmt|;
comment|/*      0x578 - 0x57c      */
specifier|volatile
name|char
name|pad__29
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x57c - 0x5b8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU5_95_64
decl_stmt|;
comment|/*      0x5b8 - 0x5bc      */
specifier|volatile
name|char
name|pad__30
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x5bc - 0x5f8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU5_127_96
decl_stmt|;
comment|/*      0x5f8 - 0x5fc      */
specifier|volatile
name|char
name|pad__31
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x5fc - 0x638      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU6_31_0
decl_stmt|;
comment|/*      0x638 - 0x63c      */
specifier|volatile
name|char
name|pad__32
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x63c - 0x678      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU6_63_32
decl_stmt|;
comment|/*      0x678 - 0x67c      */
specifier|volatile
name|char
name|pad__33
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x67c - 0x6b8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU6_95_64
decl_stmt|;
comment|/*      0x6b8 - 0x6bc      */
specifier|volatile
name|char
name|pad__34
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x6bc - 0x6f8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU6_127_96
decl_stmt|;
comment|/*      0x6f8 - 0x6fc      */
specifier|volatile
name|char
name|pad__35
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x6fc - 0x738      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU7_31_0
decl_stmt|;
comment|/*      0x738 - 0x73c      */
specifier|volatile
name|char
name|pad__36
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x73c - 0x778      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU7_63_32
decl_stmt|;
comment|/*      0x778 - 0x77c      */
specifier|volatile
name|char
name|pad__37
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x77c - 0x7b8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU7_95_64
decl_stmt|;
comment|/*      0x7b8 - 0x7bc      */
specifier|volatile
name|char
name|pad__38
index|[
literal|0x3c
index|]
decl_stmt|;
comment|/*      0x7bc - 0x7f8      */
specifier|volatile
name|u_int32_t
name|MAC_DCU_TXFILTER_DCU7_127_96
decl_stmt|;
comment|/*      0x7f8 - 0x7fc      */
specifier|volatile
name|char
name|pad__39
index|[
literal|0x704
index|]
decl_stmt|;
comment|/*      0x7fc - 0xf00      */
specifier|volatile
name|u_int32_t
name|MAC_SLEEP_STATUS
decl_stmt|;
comment|/*      0xf00 - 0xf04      */
specifier|volatile
name|u_int32_t
name|MAC_LED_CONFIG
decl_stmt|;
comment|/*      0xf04 - 0xf08      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rtc_reg
block|{
specifier|volatile
name|u_int32_t
name|RESET_CONTROL
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|XTAL_CONTROL
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|REG_CONTROL0
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|REG_CONTROL1
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|QUADRATURE
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|PLL_CONTROL
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|PLL_SETTLE
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|XTAL_SETTLE
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|CLOCK_OUT
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|BIAS_OVERRIDE
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|RESET_CAUSE
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|SYSTEM_SLEEP
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|MAC_SLEEP_CONTROL
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|u_int32_t
name|KEEP_AWAKE
decl_stmt|;
comment|/*       0x34 - 0x38       */
specifier|volatile
name|u_int32_t
name|DERIVED_RTC_CLK
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|PLL_CONTROL2
decl_stmt|;
comment|/*       0x3c - 0x40       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rtc_sync_reg
block|{
specifier|volatile
name|u_int32_t
name|RTC_SYNC_RESET
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_STATUS
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_DERIVED
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_FORCE_WAKE
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_INTR_CAUSE
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_INTR_ENABLE
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|RTC_SYNC_INTR_MASK
decl_stmt|;
comment|/*       0x18 - 0x1c       */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mac_pcu_reg
block|{
specifier|volatile
name|u_int32_t
name|MAC_PCU_STA_ADDR_L32
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|MAC_PCU_STA_ADDR_U16
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BSSID_L32
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BSSID_U16
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BCN_RSSI_AVE
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_ACK_CTS_TIMEOUT
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BCN_RSSI_CTL
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_USEC_LATENCY
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RESET_TSF
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x14
index|]
decl_stmt|;
comment|/*       0x24 - 0x38       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MAX_CFP_DUR
decl_stmt|;
comment|/*       0x38 - 0x3c       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RX_FILTER
decl_stmt|;
comment|/*       0x3c - 0x40       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MCAST_FILTER_L32
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MCAST_FILTER_U32
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_DIAG_SW
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TSF_L32
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TSF_U32
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TST_ADDAC
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_DEF_ANTENNA
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AES_MUTE_MASK_0
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AES_MUTE_MASK_1
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_GATED_CLKS
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_OBS_BUS_2
decl_stmt|;
comment|/*       0x68 - 0x6c       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_OBS_BUS_1
decl_stmt|;
comment|/*       0x6c - 0x70       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_DYM_MIMO_PWR_SAVE
decl_stmt|;
comment|/*       0x70 - 0x74       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_LSB
decl_stmt|;
comment|/*       0x74 - 0x78       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TDMA_TXFRAME_START_TIME_TRIGGER_MSB
decl_stmt|;
comment|/*       0x78 - 0x7c       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*       0x7c - 0x80       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LAST_BEACON_TSF
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_NAV
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RTS_SUCCESS_CNT
decl_stmt|;
comment|/*       0x88 - 0x8c       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RTS_FAIL_CNT
decl_stmt|;
comment|/*       0x8c - 0x90       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_ACK_FAIL_CNT
decl_stmt|;
comment|/*       0x90 - 0x94       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_FCS_FAIL_CNT
decl_stmt|;
comment|/*       0x94 - 0x98       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BEACON_CNT
decl_stmt|;
comment|/*       0x98 - 0x9c       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TDMA_SLOT_ALERT_CNTL
decl_stmt|;
comment|/*       0x9c - 0xa0       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BASIC_SET
decl_stmt|;
comment|/*       0xa0 - 0xa4       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MGMT_SEQ
decl_stmt|;
comment|/*       0xa4 - 0xa8       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BF_RPT1
decl_stmt|;
comment|/*       0xa8 - 0xac       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BF_RPT2
decl_stmt|;
comment|/*       0xac - 0xb0       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_ANT_1
decl_stmt|;
comment|/*       0xb0 - 0xb4       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_ANT_2
decl_stmt|;
comment|/*       0xb4 - 0xb8       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_ANT_3
decl_stmt|;
comment|/*       0xb8 - 0xbc       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_ANT_4
decl_stmt|;
comment|/*       0xbc - 0xc0       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRMODE
decl_stmt|;
comment|/*       0xc0 - 0xc4       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRDEL
decl_stmt|;
comment|/*       0xc4 - 0xc8       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRTO
decl_stmt|;
comment|/*       0xc8 - 0xcc       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRCRP
decl_stmt|;
comment|/*       0xcc - 0xd0       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRSTMP
decl_stmt|;
comment|/*       0xd0 - 0xd4       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP1
decl_stmt|;
comment|/*       0xd4 - 0xd8       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP2
decl_stmt|;
comment|/*       0xd8 - 0xdc       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SELF_GEN_DEFAULT
decl_stmt|;
comment|/*       0xdc - 0xe0       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_ADDR1_MASK_L32
decl_stmt|;
comment|/*       0xe0 - 0xe4       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_ADDR1_MASK_U16
decl_stmt|;
comment|/*       0xe4 - 0xe8       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TPC
decl_stmt|;
comment|/*       0xe8 - 0xec       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_FRAME_CNT
decl_stmt|;
comment|/*       0xec - 0xf0       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RX_FRAME_CNT
decl_stmt|;
comment|/*       0xf0 - 0xf4       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RX_CLEAR_CNT
decl_stmt|;
comment|/*       0xf4 - 0xf8       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_CYCLE_CNT
decl_stmt|;
comment|/*       0xf8 - 0xfc       */
specifier|volatile
name|u_int32_t
name|MAC_PCU_QUIET_TIME_1
decl_stmt|;
comment|/*       0xfc - 0x100      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_QUIET_TIME_2
decl_stmt|;
comment|/*      0x100 - 0x104      */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x104 - 0x108      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_QOS_NO_ACK
decl_stmt|;
comment|/*      0x108 - 0x10c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERROR_MASK
decl_stmt|;
comment|/*      0x10c - 0x110      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_XRLAT
decl_stmt|;
comment|/*      0x110 - 0x114      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RXBUF
decl_stmt|;
comment|/*      0x114 - 0x118      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MIC_QOS_CONTROL
decl_stmt|;
comment|/*      0x118 - 0x11c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MIC_QOS_SELECT
decl_stmt|;
comment|/*      0x11c - 0x120      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MISC_MODE
decl_stmt|;
comment|/*      0x120 - 0x124      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_FILTER_OFDM_CNT
decl_stmt|;
comment|/*      0x124 - 0x128      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_FILTER_CCK_CNT
decl_stmt|;
comment|/*      0x128 - 0x12c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_1
decl_stmt|;
comment|/*      0x12c - 0x130      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_1_MASK
decl_stmt|;
comment|/*      0x130 - 0x134      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_2
decl_stmt|;
comment|/*      0x134 - 0x138      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_2_MASK
decl_stmt|;
comment|/*      0x138 - 0x13c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TSF_THRESHOLD
decl_stmt|;
comment|/*      0x13c - 0x140      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MISC_MODE4
decl_stmt|;
comment|/*      0x140 - 0x144      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERROR_EIFS_MASK
decl_stmt|;
comment|/*      0x144 - 0x148      */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x20
index|]
decl_stmt|;
comment|/*      0x148 - 0x168      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_3
decl_stmt|;
comment|/*      0x168 - 0x16c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_3_MASK
decl_stmt|;
comment|/*      0x16c - 0x170      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_MODE
decl_stmt|;
comment|/*      0x170 - 0x174      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_WL_WEIGHTS0
decl_stmt|;
comment|/*      0x174 - 0x178      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_HCF_TIMEOUT
decl_stmt|;
comment|/*      0x178 - 0x17c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_MODE2
decl_stmt|;
comment|/*      0x17c - 0x180      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_GENERIC_TIMERS2
index|[
literal|16
index|]
decl_stmt|;
comment|/*      0x180 - 0x1c0      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_GENERIC_TIMERS2_MODE
decl_stmt|;
comment|/*      0x1c0 - 0x1c4      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_WL_WEIGHTS1
decl_stmt|;
comment|/*      0x1c4 - 0x1c8      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_TSF_BT_ACTIVE
decl_stmt|;
comment|/*      0x1c8 - 0x1cc      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_TSF_BT_PRIORITY
decl_stmt|;
comment|/*      0x1cc - 0x1d0      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXSIFS
decl_stmt|;
comment|/*      0x1d0 - 0x1d4      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_MODE3
decl_stmt|;
comment|/*      0x1d4 - 0x1d8      */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x14
index|]
decl_stmt|;
comment|/*      0x1d8 - 0x1ec      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXOP_X
decl_stmt|;
comment|/*      0x1ec - 0x1f0      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXOP_0_3
decl_stmt|;
comment|/*      0x1f0 - 0x1f4      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXOP_4_7
decl_stmt|;
comment|/*      0x1f4 - 0x1f8      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXOP_8_11
decl_stmt|;
comment|/*      0x1f8 - 0x1fc      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXOP_12_15
decl_stmt|;
comment|/*      0x1fc - 0x200      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_GENERIC_TIMERS
index|[
literal|16
index|]
decl_stmt|;
comment|/*      0x200 - 0x240      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_GENERIC_TIMERS_MODE
decl_stmt|;
comment|/*      0x240 - 0x244      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP32_MODE
decl_stmt|;
comment|/*      0x244 - 0x248      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP32_WAKE
decl_stmt|;
comment|/*      0x248 - 0x24c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP32_INC
decl_stmt|;
comment|/*      0x24c - 0x250      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP_MIB1
decl_stmt|;
comment|/*      0x250 - 0x254      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP_MIB2
decl_stmt|;
comment|/*      0x254 - 0x258      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SLP_MIB3
decl_stmt|;
comment|/*      0x258 - 0x25c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW1
decl_stmt|;
comment|/*      0x25c - 0x260      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW2
decl_stmt|;
comment|/*      0x260 - 0x264      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LOGIC_ANALYZER
decl_stmt|;
comment|/*      0x264 - 0x268      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LOGIC_ANALYZER_32L
decl_stmt|;
comment|/*      0x268 - 0x26c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LOGIC_ANALYZER_16U
decl_stmt|;
comment|/*      0x26c - 0x270      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW3_BEACON_FAIL
decl_stmt|;
comment|/*      0x270 - 0x274      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW3_BEACON
decl_stmt|;
comment|/*      0x274 - 0x278      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW3_KEEP_ALIVE
decl_stmt|;
comment|/*      0x278 - 0x27c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW_KA
decl_stmt|;
comment|/*      0x27c - 0x280      */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x280 - 0x284      */
specifier|volatile
name|u_int32_t
name|PCU_1US
decl_stmt|;
comment|/*      0x284 - 0x288      */
specifier|volatile
name|u_int32_t
name|PCU_KA
decl_stmt|;
comment|/*      0x288 - 0x28c      */
specifier|volatile
name|u_int32_t
name|WOW_EXACT
decl_stmt|;
comment|/*      0x28c - 0x290      */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x290 - 0x294      */
specifier|volatile
name|u_int32_t
name|PCU_WOW4
decl_stmt|;
comment|/*      0x294 - 0x298      */
specifier|volatile
name|u_int32_t
name|PCU_WOW5
decl_stmt|;
comment|/*      0x298 - 0x29c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERR_CNT_MASK_CONT
decl_stmt|;
comment|/*      0x29c - 0x2a0      */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x60
index|]
decl_stmt|;
comment|/*      0x2a0 - 0x300      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AZIMUTH_MODE
decl_stmt|;
comment|/*      0x300 - 0x304      */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*      0x304 - 0x314      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AZIMUTH_TIME_STAMP
decl_stmt|;
comment|/*      0x314 - 0x318      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_20_40_MODE
decl_stmt|;
comment|/*      0x318 - 0x31c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_H_XFER_TIMEOUT
decl_stmt|;
comment|/*      0x31c - 0x320      */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*      0x320 - 0x328      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_RX_CLEAR_DIFF_CNT
decl_stmt|;
comment|/*      0x328 - 0x32c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_SELF_GEN_ANTENNA_MASK
decl_stmt|;
comment|/*      0x32c - 0x330      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BA_BAR_CONTROL
decl_stmt|;
comment|/*      0x330 - 0x334      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LEGACY_PLCP_SPOOF
decl_stmt|;
comment|/*      0x334 - 0x338      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERROR_MASK_CONT
decl_stmt|;
comment|/*      0x338 - 0x33c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TX_TIMER
decl_stmt|;
comment|/*      0x33c - 0x340      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXBUF_CTRL
decl_stmt|;
comment|/*      0x340 - 0x344      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MISC_MODE2
decl_stmt|;
comment|/*      0x344 - 0x348      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_ALT_AES_MUTE_MASK
decl_stmt|;
comment|/*      0x348 - 0x34c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW6
decl_stmt|;
comment|/*      0x34c - 0x350      */
specifier|volatile
name|u_int32_t
name|ASYNC_FIFO_REG1
decl_stmt|;
comment|/*      0x350 - 0x354      */
specifier|volatile
name|u_int32_t
name|ASYNC_FIFO_REG2
decl_stmt|;
comment|/*      0x354 - 0x358      */
specifier|volatile
name|u_int32_t
name|ASYNC_FIFO_REG3
decl_stmt|;
comment|/*      0x358 - 0x35c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW5
decl_stmt|;
comment|/*      0x35c - 0x360      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW_LENGTH1
decl_stmt|;
comment|/*      0x360 - 0x364      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW_LENGTH2
decl_stmt|;
comment|/*      0x364 - 0x368      */
specifier|volatile
name|u_int32_t
name|WOW_PATTERN_MATCH_LESS_THAN_256_BYTES
decl_stmt|;
comment|/*      0x368 - 0x36c      */
specifier|volatile
name|char
name|pad__10
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*      0x36c - 0x370      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW4
decl_stmt|;
comment|/*      0x370 - 0x374      */
specifier|volatile
name|u_int32_t
name|WOW2_EXACT
decl_stmt|;
comment|/*      0x374 - 0x378      */
specifier|volatile
name|u_int32_t
name|PCU_WOW6
decl_stmt|;
comment|/*      0x378 - 0x37c      */
specifier|volatile
name|u_int32_t
name|PCU_WOW7
decl_stmt|;
comment|/*      0x37c - 0x380      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW_LENGTH3
decl_stmt|;
comment|/*      0x380 - 0x384      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_WOW_LENGTH4
decl_stmt|;
comment|/*      0x384 - 0x388      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LOCATION_MODE_CONTROL
decl_stmt|;
comment|/*      0x388 - 0x38c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_LOCATION_MODE_TIMER
decl_stmt|;
comment|/*      0x38c - 0x390      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TSF2_L32
decl_stmt|;
comment|/*      0x390 - 0x394      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TSF2_U32
decl_stmt|;
comment|/*      0x394 - 0x398      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BSSID2_L32
decl_stmt|;
comment|/*      0x398 - 0x39c      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BSSID2_U16
decl_stmt|;
comment|/*      0x39c - 0x3a0      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_DIRECT_CONNECT
decl_stmt|;
comment|/*      0x3a0 - 0x3a4      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TID_TO_AC
decl_stmt|;
comment|/*      0x3a4 - 0x3a8      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_HP_QUEUE
decl_stmt|;
comment|/*      0x3a8 - 0x3ac      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_BT_WEIGHTS0
decl_stmt|;
comment|/*      0x3ac - 0x3b0      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_BT_WEIGHTS1
decl_stmt|;
comment|/*      0x3b0 - 0x3b4      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_BT_WEIGHTS2
decl_stmt|;
comment|/*      0x3b4 - 0x3b8      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_BLUETOOTH_BT_WEIGHTS3
decl_stmt|;
comment|/*      0x3b8 - 0x3bc      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AGC_SATURATION_CNT0
decl_stmt|;
comment|/*      0x3bc - 0x3c0      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AGC_SATURATION_CNT1
decl_stmt|;
comment|/*      0x3c0 - 0x3c4      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_AGC_SATURATION_CNT2
decl_stmt|;
comment|/*      0x3c4 - 0x3c8      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_HW_BCN_PROC1
decl_stmt|;
comment|/*      0x3c8 - 0x3cc      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_HW_BCN_PROC2
decl_stmt|;
comment|/*      0x3cc - 0x3d0      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_MISC_MODE3
decl_stmt|;
comment|/*      0x3d0 - 0x3d4      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_FILTER_RSSI_AVE
decl_stmt|;
comment|/*      0x3d4 - 0x3d8      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PHY_ERROR_AIFS_MASK
decl_stmt|;
comment|/*      0x3d8 - 0x3dc      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_PS_FILTER
decl_stmt|;
comment|/*      0x3dc - 0x3e0      */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x20
index|]
decl_stmt|;
comment|/*      0x3e0 - 0x400      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_TXBUF_BA
index|[
literal|64
index|]
decl_stmt|;
comment|/*      0x400 - 0x500      */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x300
index|]
decl_stmt|;
comment|/*      0x500 - 0x800      */
specifier|volatile
name|u_int32_t
name|MAC_PCU_KEY_CACHE
index|[
literal|1024
index|]
decl_stmt|;
comment|/*      0x800 - 0x1800     */
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
specifier|volatile
name|u_int32_t
name|BB_chn_tables_intf_addr
decl_stmt|;
comment|/*      0x3f0 - 0x3f4      */
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
specifier|volatile
name|u_int32_t
name|BB_bt_coex_2
decl_stmt|;
comment|/*       0x58 - 0x5c       */
specifier|volatile
name|u_int32_t
name|BB_bt_coex_3
decl_stmt|;
comment|/*       0x5c - 0x60       */
specifier|volatile
name|u_int32_t
name|BB_bt_coex_4
decl_stmt|;
comment|/*       0x60 - 0x64       */
specifier|volatile
name|u_int32_t
name|BB_bt_coex_5
decl_stmt|;
comment|/*       0x64 - 0x68       */
specifier|volatile
name|u_int32_t
name|BB_redpwr_ctrl_1
decl_stmt|;
comment|/*       0x68 - 0x6c       */
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
specifier|volatile
name|u_int32_t
name|BB_mrc_cck_ctrl
decl_stmt|;
comment|/*      0x1d0 - 0x1d4      */
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
name|BB_tpc_19_b0
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
literal|0x114
index|]
decl_stmt|;
comment|/*      0x4ac - 0x5c0      */
specifier|volatile
name|u_int32_t
name|BB_watchdog_status
decl_stmt|;
comment|/*      0x5c0 - 0x5c4      */
specifier|volatile
name|u_int32_t
name|BB_watchdog_ctrl_1
decl_stmt|;
comment|/*      0x5c4 - 0x5c8      */
specifier|volatile
name|u_int32_t
name|BB_watchdog_ctrl_2
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
name|pad__14
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
name|pad__15
index|[
literal|0x10
index|]
decl_stmt|;
comment|/*      0x5e0 - 0x5f0      */
specifier|volatile
name|u_int32_t
name|BB_tables_intf_addr_b0
decl_stmt|;
comment|/*      0x5f0 - 0x5f4      */
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
name|char
name|pad__0
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*        0x0 - 0x30       */
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
specifier|volatile
name|u_int32_t
name|BB_chn1_tables_intf_addr
decl_stmt|;
comment|/*      0x3f0 - 0x3f4      */
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
name|agc1_reg_map
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BB_gain_force_max_gains_b1
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|char
name|pad__1
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
specifier|volatile
name|u_int32_t
name|BB_cca_b1
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|BB_cca_ctrl_2_b1
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|char
name|pad__2
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
specifier|volatile
name|u_int32_t
name|BB_spur_est_cck_report_b1
decl_stmt|;
comment|/*      0x184 - 0x188      */
specifier|volatile
name|u_int32_t
name|BB_agc_dig_dc_status_i_b1
decl_stmt|;
comment|/*      0x188 - 0x18c      */
specifier|volatile
name|u_int32_t
name|BB_agc_dig_dc_status_q_b1
decl_stmt|;
comment|/*      0x18c - 0x190      */
specifier|volatile
name|u_int32_t
name|BB_dc_cal_status_b1
decl_stmt|;
comment|/*      0x190 - 0x194      */
specifier|volatile
name|char
name|pad__3
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
name|char
name|pad__0
index|[
literal|0x84
index|]
decl_stmt|;
comment|/*        0x0 - 0x84       */
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
name|pad__11
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
name|pad__12
index|[
literal|0x160
index|]
decl_stmt|;
comment|/*      0x490 - 0x5f0      */
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
block|}
struct|;
end_struct

begin_struct
struct|struct
name|chn2_reg_map
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*        0x0 - 0x30       */
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
specifier|volatile
name|u_int32_t
name|BB_chn2_tables_intf_addr
decl_stmt|;
comment|/*      0x3f0 - 0x3f4      */
specifier|volatile
name|u_int32_t
name|BB_chn2_tables_intf_data
decl_stmt|;
comment|/*      0x3f4 - 0x3f8      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|agc2_reg_map
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|BB_gain_force_max_gains_b2
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|char
name|pad__1
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
name|pad__2
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
name|pad__3
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
specifier|volatile
name|u_int32_t
name|BB_dc_cal_status_b2
decl_stmt|;
comment|/*      0x190 - 0x194      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|sm2_reg_map
block|{
specifier|volatile
name|char
name|pad__0
index|[
literal|0x84
index|]
decl_stmt|;
comment|/*        0x0 - 0x84       */
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
specifier|volatile
name|u_int32_t
name|BB_tpc_19_b2
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
name|BB_pdadc_tab_b2
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
name|BB_rtt_table_sw_intf_b2
decl_stmt|;
comment|/*      0x384 - 0x388      */
specifier|volatile
name|u_int32_t
name|BB_rtt_table_sw_intf_1_b2
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
name|pad__11
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
name|pad__12
index|[
literal|0x160
index|]
decl_stmt|;
comment|/*      0x490 - 0x5f0      */
specifier|volatile
name|u_int32_t
name|BB_tables_intf_addr_b2
decl_stmt|;
comment|/*      0x5f0 - 0x5f4      */
specifier|volatile
name|u_int32_t
name|BB_tables_intf_data_b2
decl_stmt|;
comment|/*      0x5f4 - 0x5f8      */
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
name|struct
name|chn_reg_map
name|bb_chn_reg_map
decl_stmt|;
comment|/*        0x0 - 0x3f8      */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*      0x3f8 - 0x400      */
name|struct
name|mrc_reg_map
name|bb_mrc_reg_map
decl_stmt|;
comment|/*      0x400 - 0x424      */
specifier|volatile
name|char
name|pad__1
index|[
literal|0xdc
index|]
decl_stmt|;
comment|/*      0x424 - 0x500      */
name|struct
name|bbb_reg_map
name|bb_bbb_reg_map
decl_stmt|;
comment|/*      0x500 - 0x51c      */
specifier|volatile
name|char
name|pad__2
index|[
literal|0xe4
index|]
decl_stmt|;
comment|/*      0x51c - 0x600      */
name|struct
name|agc_reg_map
name|bb_agc_reg_map
decl_stmt|;
comment|/*      0x600 - 0xa00      */
name|struct
name|sm_reg_map
name|bb_sm_reg_map
decl_stmt|;
comment|/*      0xa00 - 0xff8      */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*      0xff8 - 0x1000     */
name|struct
name|chn1_reg_map
name|bb_chn1_reg_map
decl_stmt|;
comment|/*     0x1000 - 0x13c8     */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x238
index|]
decl_stmt|;
comment|/*     0x13c8 - 0x1600     */
name|struct
name|agc1_reg_map
name|bb_agc1_reg_map
decl_stmt|;
comment|/*     0x1600 - 0x19fc     */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x4
index|]
decl_stmt|;
comment|/*     0x19fc - 0x1a00     */
name|struct
name|sm1_reg_map
name|bb_sm1_reg_map
decl_stmt|;
comment|/*     0x1a00 - 0x1f74     */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x8c
index|]
decl_stmt|;
comment|/*     0x1f74 - 0x2000     */
name|struct
name|chn2_reg_map
name|bb_chn2_reg_map
decl_stmt|;
comment|/*     0x2000 - 0x23c8     */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x238
index|]
decl_stmt|;
comment|/*     0x23c8 - 0x2600     */
name|struct
name|agc2_reg_map
name|bb_agc2_reg_map
decl_stmt|;
comment|/*     0x2600 - 0x2790     */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x270
index|]
decl_stmt|;
comment|/*     0x2790 - 0x2a00     */
name|struct
name|sm2_reg_map
name|bb_sm2_reg_map
decl_stmt|;
comment|/*     0x2a00 - 0x2f74     */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x8c
index|]
decl_stmt|;
comment|/*     0x2f74 - 0x3000     */
name|struct
name|chn3_reg_map
name|bb_chn3_reg_map
decl_stmt|;
comment|/*     0x3000 - 0x3400     */
specifier|volatile
name|char
name|pad__10
index|[
literal|0x200
index|]
decl_stmt|;
comment|/*     0x3400 - 0x3600     */
name|struct
name|agc3_reg_map
name|bb_agc3_reg_map
decl_stmt|;
comment|/*     0x3600 - 0x3784     */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x27c
index|]
decl_stmt|;
comment|/*     0x3784 - 0x3a00     */
name|struct
name|sm3_reg_map
name|bb_sm3_reg_map
decl_stmt|;
comment|/*     0x3a00 - 0x4000     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mac_pcu_buf_reg
block|{
specifier|volatile
name|u_int32_t
name|MAC_PCU_BUF
index|[
literal|2048
index|]
decl_stmt|;
comment|/*        0x0 - 0x2000     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|svd_reg
block|{
specifier|volatile
name|u_int32_t
name|TXBF_DBG
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|TXBF
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|TXBF_TIMER
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|TXBF_SW
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|u_int32_t
name|TXBF_SM
decl_stmt|;
comment|/*       0x10 - 0x14       */
specifier|volatile
name|u_int32_t
name|TXBF1_CNTL
decl_stmt|;
comment|/*       0x14 - 0x18       */
specifier|volatile
name|u_int32_t
name|TXBF2_CNTL
decl_stmt|;
comment|/*       0x18 - 0x1c       */
specifier|volatile
name|u_int32_t
name|TXBF3_CNTL
decl_stmt|;
comment|/*       0x1c - 0x20       */
specifier|volatile
name|u_int32_t
name|TXBF4_CNTL
decl_stmt|;
comment|/*       0x20 - 0x24       */
specifier|volatile
name|u_int32_t
name|TXBF5_CNTL
decl_stmt|;
comment|/*       0x24 - 0x28       */
specifier|volatile
name|u_int32_t
name|TXBF6_CNTL
decl_stmt|;
comment|/*       0x28 - 0x2c       */
specifier|volatile
name|u_int32_t
name|TXBF7_CNTL
decl_stmt|;
comment|/*       0x2c - 0x30       */
specifier|volatile
name|u_int32_t
name|TXBF8_CNTL
decl_stmt|;
comment|/*       0x30 - 0x34       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0xfcc
index|]
decl_stmt|;
comment|/*       0x34 - 0x1000     */
specifier|volatile
name|u_int32_t
name|RC0
index|[
literal|118
index|]
decl_stmt|;
comment|/*     0x1000 - 0x11d8     */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x28
index|]
decl_stmt|;
comment|/*     0x11d8 - 0x1200     */
specifier|volatile
name|u_int32_t
name|RC1
index|[
literal|118
index|]
decl_stmt|;
comment|/*     0x1200 - 0x13d8     */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x28
index|]
decl_stmt|;
comment|/*     0x13d8 - 0x1400     */
specifier|volatile
name|u_int32_t
name|SVD_MEM0
index|[
literal|114
index|]
decl_stmt|;
comment|/*     0x1400 - 0x15c8     */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*     0x15c8 - 0x1600     */
specifier|volatile
name|u_int32_t
name|SVD_MEM1
index|[
literal|114
index|]
decl_stmt|;
comment|/*     0x1600 - 0x17c8     */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*     0x17c8 - 0x1800     */
specifier|volatile
name|u_int32_t
name|SVD_MEM2
index|[
literal|114
index|]
decl_stmt|;
comment|/*     0x1800 - 0x19c8     */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*     0x19c8 - 0x1a00     */
specifier|volatile
name|u_int32_t
name|SVD_MEM3
index|[
literal|114
index|]
decl_stmt|;
comment|/*     0x1a00 - 0x1bc8     */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x38
index|]
decl_stmt|;
comment|/*     0x1bc8 - 0x1c00     */
specifier|volatile
name|u_int32_t
name|SVD_MEM4
index|[
literal|114
index|]
decl_stmt|;
comment|/*     0x1c00 - 0x1dc8     */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x638
index|]
decl_stmt|;
comment|/*     0x1dc8 - 0x2400     */
specifier|volatile
name|u_int32_t
name|CVCACHE
index|[
literal|512
index|]
decl_stmt|;
comment|/*     0x2400 - 0x2c00     */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|radio65_reg
block|{
specifier|volatile
name|u_int32_t
name|ch0_RXRF_BIAS1
decl_stmt|;
comment|/*        0x0 - 0x4        */
specifier|volatile
name|u_int32_t
name|ch0_RXRF_BIAS2
decl_stmt|;
comment|/*        0x4 - 0x8        */
specifier|volatile
name|u_int32_t
name|ch0_RXRF_GAINSTAGES
decl_stmt|;
comment|/*        0x8 - 0xc        */
specifier|volatile
name|u_int32_t
name|ch0_RXRF_AGC
decl_stmt|;
comment|/*        0xc - 0x10       */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*       0x10 - 0x40       */
specifier|volatile
name|u_int32_t
name|ch0_TXRF1
decl_stmt|;
comment|/*       0x40 - 0x44       */
specifier|volatile
name|u_int32_t
name|ch0_TXRF2
decl_stmt|;
comment|/*       0x44 - 0x48       */
specifier|volatile
name|u_int32_t
name|ch0_TXRF3
decl_stmt|;
comment|/*       0x48 - 0x4c       */
specifier|volatile
name|u_int32_t
name|ch0_TXRF4
decl_stmt|;
comment|/*       0x4c - 0x50       */
specifier|volatile
name|u_int32_t
name|ch0_TXRF5
decl_stmt|;
comment|/*       0x50 - 0x54       */
specifier|volatile
name|u_int32_t
name|ch0_TXRF6
decl_stmt|;
comment|/*       0x54 - 0x58       */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x28
index|]
decl_stmt|;
comment|/*       0x58 - 0x80       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH1
decl_stmt|;
comment|/*       0x80 - 0x84       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH2
decl_stmt|;
comment|/*       0x84 - 0x88       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH3
decl_stmt|;
comment|/*       0x88 - 0x8c       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH4
decl_stmt|;
comment|/*       0x8c - 0x90       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH5
decl_stmt|;
comment|/*       0x90 - 0x94       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH6
decl_stmt|;
comment|/*       0x94 - 0x98       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH7
decl_stmt|;
comment|/*       0x98 - 0x9c       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH8
decl_stmt|;
comment|/*       0x9c - 0xa0       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH9
decl_stmt|;
comment|/*       0xa0 - 0xa4       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH10
decl_stmt|;
comment|/*       0xa4 - 0xa8       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH11
decl_stmt|;
comment|/*       0xa8 - 0xac       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH12
decl_stmt|;
comment|/*       0xac - 0xb0       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH13
decl_stmt|;
comment|/*       0xb0 - 0xb4       */
specifier|volatile
name|u_int32_t
name|ch0_SYNTH14
decl_stmt|;
comment|/*       0xb4 - 0xb8       */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x8
index|]
decl_stmt|;
comment|/*       0xb8 - 0xc0       */
specifier|volatile
name|u_int32_t
name|ch0_BIAS1
decl_stmt|;
comment|/*       0xc0 - 0xc4       */
specifier|volatile
name|u_int32_t
name|ch0_BIAS2
decl_stmt|;
comment|/*       0xc4 - 0xc8       */
specifier|volatile
name|u_int32_t
name|ch0_BIAS3
decl_stmt|;
comment|/*       0xc8 - 0xcc       */
specifier|volatile
name|u_int32_t
name|ch0_BIAS4
decl_stmt|;
comment|/*       0xcc - 0xd0       */
specifier|volatile
name|char
name|pad__3
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*       0xd0 - 0x100      */
specifier|volatile
name|u_int32_t
name|ch0_RXTX1
decl_stmt|;
comment|/*      0x100 - 0x104      */
specifier|volatile
name|u_int32_t
name|ch0_RXTX2
decl_stmt|;
comment|/*      0x104 - 0x108      */
specifier|volatile
name|u_int32_t
name|ch0_RXTX3
decl_stmt|;
comment|/*      0x108 - 0x10c      */
specifier|volatile
name|u_int32_t
name|ch0_RXTX4
decl_stmt|;
comment|/*      0x10c - 0x110      */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*      0x110 - 0x140      */
specifier|volatile
name|u_int32_t
name|ch0_BB1
decl_stmt|;
comment|/*      0x140 - 0x144      */
specifier|volatile
name|u_int32_t
name|ch0_BB2
decl_stmt|;
comment|/*      0x144 - 0x148      */
specifier|volatile
name|u_int32_t
name|ch0_BB3
decl_stmt|;
comment|/*      0x148 - 0x14c      */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x34
index|]
decl_stmt|;
comment|/*      0x14c - 0x180      */
specifier|volatile
name|u_int32_t
name|ch0_BB_PLL
decl_stmt|;
comment|/*      0x180 - 0x184      */
specifier|volatile
name|u_int32_t
name|ch0_BB_PLL2
decl_stmt|;
comment|/*      0x184 - 0x188      */
specifier|volatile
name|u_int32_t
name|ch0_BB_PLL3
decl_stmt|;
comment|/*      0x188 - 0x18c      */
specifier|volatile
name|u_int32_t
name|ch0_BB_PLL4
decl_stmt|;
comment|/*      0x18c - 0x190      */
specifier|volatile
name|char
name|pad__6
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*      0x190 - 0x1c0      */
specifier|volatile
name|u_int32_t
name|ch0_CPU_PLL
decl_stmt|;
comment|/*      0x1c0 - 0x1c4      */
specifier|volatile
name|u_int32_t
name|ch0_CPU_PLL2
decl_stmt|;
comment|/*      0x1c4 - 0x1c8      */
specifier|volatile
name|u_int32_t
name|ch0_CPU_PLL3
decl_stmt|;
comment|/*      0x1c8 - 0x1cc      */
specifier|volatile
name|u_int32_t
name|ch0_CPU_PLL4
decl_stmt|;
comment|/*      0x1cc - 0x1d0      */
specifier|volatile
name|char
name|pad__7
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*      0x1d0 - 0x200      */
specifier|volatile
name|u_int32_t
name|ch0_AUDIO_PLL
decl_stmt|;
comment|/*      0x200 - 0x204      */
specifier|volatile
name|u_int32_t
name|ch0_AUDIO_PLL2
decl_stmt|;
comment|/*      0x204 - 0x208      */
specifier|volatile
name|u_int32_t
name|ch0_AUDIO_PLL3
decl_stmt|;
comment|/*      0x208 - 0x20c      */
specifier|volatile
name|u_int32_t
name|ch0_AUDIO_PLL4
decl_stmt|;
comment|/*      0x20c - 0x210      */
specifier|volatile
name|char
name|pad__8
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*      0x210 - 0x240      */
specifier|volatile
name|u_int32_t
name|ch0_DDR_PLL
decl_stmt|;
comment|/*      0x240 - 0x244      */
specifier|volatile
name|u_int32_t
name|ch0_DDR_PLL2
decl_stmt|;
comment|/*      0x244 - 0x248      */
specifier|volatile
name|u_int32_t
name|ch0_DDR_PLL3
decl_stmt|;
comment|/*      0x248 - 0x24c      */
specifier|volatile
name|u_int32_t
name|ch0_DDR_PLL4
decl_stmt|;
comment|/*      0x24c - 0x250      */
specifier|volatile
name|char
name|pad__9
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*      0x250 - 0x280      */
specifier|volatile
name|u_int32_t
name|ch0_TOP
decl_stmt|;
comment|/*      0x280 - 0x284      */
specifier|volatile
name|u_int32_t
name|ch0_TOP2
decl_stmt|;
comment|/*      0x284 - 0x288      */
specifier|volatile
name|u_int32_t
name|ch0_TOP3
decl_stmt|;
comment|/*      0x288 - 0x28c      */
specifier|volatile
name|u_int32_t
name|ch0_THERM
decl_stmt|;
comment|/*      0x28c - 0x290      */
specifier|volatile
name|u_int32_t
name|ch0_XTAL
decl_stmt|;
comment|/*      0x290 - 0x294      */
specifier|volatile
name|char
name|pad__10
index|[
literal|0xec
index|]
decl_stmt|;
comment|/*      0x294 - 0x380      */
specifier|volatile
name|u_int32_t
name|ch0_rbist_cntrl
decl_stmt|;
comment|/*      0x380 - 0x384      */
specifier|volatile
name|u_int32_t
name|ch0_tx_dc_offset
decl_stmt|;
comment|/*      0x384 - 0x388      */
specifier|volatile
name|u_int32_t
name|ch0_tx_tonegen0
decl_stmt|;
comment|/*      0x388 - 0x38c      */
specifier|volatile
name|u_int32_t
name|ch0_tx_tonegen1
decl_stmt|;
comment|/*      0x38c - 0x390      */
specifier|volatile
name|u_int32_t
name|ch0_tx_lftonegen0
decl_stmt|;
comment|/*      0x390 - 0x394      */
specifier|volatile
name|u_int32_t
name|ch0_tx_linear_ramp_i
decl_stmt|;
comment|/*      0x394 - 0x398      */
specifier|volatile
name|u_int32_t
name|ch0_tx_linear_ramp_q
decl_stmt|;
comment|/*      0x398 - 0x39c      */
specifier|volatile
name|u_int32_t
name|ch0_tx_prbs_mag
decl_stmt|;
comment|/*      0x39c - 0x3a0      */
specifier|volatile
name|u_int32_t
name|ch0_tx_prbs_seed_i
decl_stmt|;
comment|/*      0x3a0 - 0x3a4      */
specifier|volatile
name|u_int32_t
name|ch0_tx_prbs_seed_q
decl_stmt|;
comment|/*      0x3a4 - 0x3a8      */
specifier|volatile
name|u_int32_t
name|ch0_cmac_dc_cancel
decl_stmt|;
comment|/*      0x3a8 - 0x3ac      */
specifier|volatile
name|u_int32_t
name|ch0_cmac_dc_offset
decl_stmt|;
comment|/*      0x3ac - 0x3b0      */
specifier|volatile
name|u_int32_t
name|ch0_cmac_corr
decl_stmt|;
comment|/*      0x3b0 - 0x3b4      */
specifier|volatile
name|u_int32_t
name|ch0_cmac_power
decl_stmt|;
comment|/*      0x3b4 - 0x3b8      */
specifier|volatile
name|u_int32_t
name|ch0_cmac_cross_corr
decl_stmt|;
comment|/*      0x3b8 - 0x3bc      */
specifier|volatile
name|u_int32_t
name|ch0_cmac_i2q2
decl_stmt|;
comment|/*      0x3bc - 0x3c0      */
specifier|volatile
name|u_int32_t
name|ch0_cmac_power_hpf
decl_stmt|;
comment|/*      0x3c0 - 0x3c4      */
specifier|volatile
name|u_int32_t
name|ch0_rxdac_set1
decl_stmt|;
comment|/*      0x3c4 - 0x3c8      */
specifier|volatile
name|u_int32_t
name|ch0_rxdac_set2
decl_stmt|;
comment|/*      0x3c8 - 0x3cc      */
specifier|volatile
name|u_int32_t
name|ch0_rxdac_long_shift
decl_stmt|;
comment|/*      0x3cc - 0x3d0      */
specifier|volatile
name|u_int32_t
name|ch0_cmac_results_i
decl_stmt|;
comment|/*      0x3d0 - 0x3d4      */
specifier|volatile
name|u_int32_t
name|ch0_cmac_results_q
decl_stmt|;
comment|/*      0x3d4 - 0x3d8      */
specifier|volatile
name|char
name|pad__11
index|[
literal|0x28
index|]
decl_stmt|;
comment|/*      0x3d8 - 0x400      */
specifier|volatile
name|u_int32_t
name|ch1_RXRF_BIAS1
decl_stmt|;
comment|/*      0x400 - 0x404      */
specifier|volatile
name|u_int32_t
name|ch1_RXRF_BIAS2
decl_stmt|;
comment|/*      0x404 - 0x408      */
specifier|volatile
name|u_int32_t
name|ch1_RXRF_GAINSTAGES
decl_stmt|;
comment|/*      0x408 - 0x40c      */
specifier|volatile
name|u_int32_t
name|ch1_RXRF_AGC
decl_stmt|;
comment|/*      0x40c - 0x410      */
specifier|volatile
name|char
name|pad__12
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*      0x410 - 0x440      */
specifier|volatile
name|u_int32_t
name|ch1_TXRF1
decl_stmt|;
comment|/*      0x440 - 0x444      */
specifier|volatile
name|u_int32_t
name|ch1_TXRF2
decl_stmt|;
comment|/*      0x444 - 0x448      */
specifier|volatile
name|u_int32_t
name|ch1_TXRF3
decl_stmt|;
comment|/*      0x448 - 0x44c      */
specifier|volatile
name|u_int32_t
name|ch1_TXRF4
decl_stmt|;
comment|/*      0x44c - 0x450      */
specifier|volatile
name|u_int32_t
name|ch1_TXRF5
decl_stmt|;
comment|/*      0x450 - 0x454      */
specifier|volatile
name|u_int32_t
name|ch1_TXRF6
decl_stmt|;
comment|/*      0x454 - 0x458      */
specifier|volatile
name|char
name|pad__13
index|[
literal|0xa8
index|]
decl_stmt|;
comment|/*      0x458 - 0x500      */
specifier|volatile
name|u_int32_t
name|ch1_RXTX1
decl_stmt|;
comment|/*      0x500 - 0x504      */
specifier|volatile
name|u_int32_t
name|ch1_RXTX2
decl_stmt|;
comment|/*      0x504 - 0x508      */
specifier|volatile
name|u_int32_t
name|ch1_RXTX3
decl_stmt|;
comment|/*      0x508 - 0x50c      */
specifier|volatile
name|u_int32_t
name|ch1_RXTX4
decl_stmt|;
comment|/*      0x50c - 0x510      */
specifier|volatile
name|char
name|pad__14
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*      0x510 - 0x540      */
specifier|volatile
name|u_int32_t
name|ch1_BB1
decl_stmt|;
comment|/*      0x540 - 0x544      */
specifier|volatile
name|u_int32_t
name|ch1_BB2
decl_stmt|;
comment|/*      0x544 - 0x548      */
specifier|volatile
name|u_int32_t
name|ch1_BB3
decl_stmt|;
comment|/*      0x548 - 0x54c      */
specifier|volatile
name|char
name|pad__15
index|[
literal|0x234
index|]
decl_stmt|;
comment|/*      0x54c - 0x780      */
specifier|volatile
name|u_int32_t
name|ch1_rbist_cntrl
decl_stmt|;
comment|/*      0x780 - 0x784      */
specifier|volatile
name|u_int32_t
name|ch1_tx_dc_offset
decl_stmt|;
comment|/*      0x784 - 0x788      */
specifier|volatile
name|u_int32_t
name|ch1_tx_tonegen0
decl_stmt|;
comment|/*      0x788 - 0x78c      */
specifier|volatile
name|u_int32_t
name|ch1_tx_tonegen1
decl_stmt|;
comment|/*      0x78c - 0x790      */
specifier|volatile
name|u_int32_t
name|ch1_tx_lftonegen0
decl_stmt|;
comment|/*      0x790 - 0x794      */
specifier|volatile
name|u_int32_t
name|ch1_tx_linear_ramp_i
decl_stmt|;
comment|/*      0x794 - 0x798      */
specifier|volatile
name|u_int32_t
name|ch1_tx_linear_ramp_q
decl_stmt|;
comment|/*      0x798 - 0x79c      */
specifier|volatile
name|u_int32_t
name|ch1_tx_prbs_mag
decl_stmt|;
comment|/*      0x79c - 0x7a0      */
specifier|volatile
name|u_int32_t
name|ch1_tx_prbs_seed_i
decl_stmt|;
comment|/*      0x7a0 - 0x7a4      */
specifier|volatile
name|u_int32_t
name|ch1_tx_prbs_seed_q
decl_stmt|;
comment|/*      0x7a4 - 0x7a8      */
specifier|volatile
name|u_int32_t
name|ch1_cmac_dc_cancel
decl_stmt|;
comment|/*      0x7a8 - 0x7ac      */
specifier|volatile
name|u_int32_t
name|ch1_cmac_dc_offset
decl_stmt|;
comment|/*      0x7ac - 0x7b0      */
specifier|volatile
name|u_int32_t
name|ch1_cmac_corr
decl_stmt|;
comment|/*      0x7b0 - 0x7b4      */
specifier|volatile
name|u_int32_t
name|ch1_cmac_power
decl_stmt|;
comment|/*      0x7b4 - 0x7b8      */
specifier|volatile
name|u_int32_t
name|ch1_cmac_cross_corr
decl_stmt|;
comment|/*      0x7b8 - 0x7bc      */
specifier|volatile
name|u_int32_t
name|ch1_cmac_i2q2
decl_stmt|;
comment|/*      0x7bc - 0x7c0      */
specifier|volatile
name|u_int32_t
name|ch1_cmac_power_hpf
decl_stmt|;
comment|/*      0x7c0 - 0x7c4      */
specifier|volatile
name|u_int32_t
name|ch1_rxdac_set1
decl_stmt|;
comment|/*      0x7c4 - 0x7c8      */
specifier|volatile
name|u_int32_t
name|ch1_rxdac_set2
decl_stmt|;
comment|/*      0x7c8 - 0x7cc      */
specifier|volatile
name|u_int32_t
name|ch1_rxdac_long_shift
decl_stmt|;
comment|/*      0x7cc - 0x7d0      */
specifier|volatile
name|u_int32_t
name|ch1_cmac_results_i
decl_stmt|;
comment|/*      0x7d0 - 0x7d4      */
specifier|volatile
name|u_int32_t
name|ch1_cmac_results_q
decl_stmt|;
comment|/*      0x7d4 - 0x7d8      */
specifier|volatile
name|char
name|pad__16
index|[
literal|0x28
index|]
decl_stmt|;
comment|/*      0x7d8 - 0x800      */
specifier|volatile
name|u_int32_t
name|ch2_RXRF_BIAS1
decl_stmt|;
comment|/*      0x800 - 0x804      */
specifier|volatile
name|u_int32_t
name|ch2_RXRF_BIAS2
decl_stmt|;
comment|/*      0x804 - 0x808      */
specifier|volatile
name|u_int32_t
name|ch2_RXRF_GAINSTAGES
decl_stmt|;
comment|/*      0x808 - 0x80c      */
specifier|volatile
name|u_int32_t
name|ch2_RXRF_AGC
decl_stmt|;
comment|/*      0x80c - 0x810      */
specifier|volatile
name|char
name|pad__17
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*      0x810 - 0x840      */
specifier|volatile
name|u_int32_t
name|ch2_TXRF1
decl_stmt|;
comment|/*      0x840 - 0x844      */
specifier|volatile
name|u_int32_t
name|ch2_TXRF2
decl_stmt|;
comment|/*      0x844 - 0x848      */
specifier|volatile
name|u_int32_t
name|ch2_TXRF3
decl_stmt|;
comment|/*      0x848 - 0x84c      */
specifier|volatile
name|u_int32_t
name|ch2_TXRF4
decl_stmt|;
comment|/*      0x84c - 0x850      */
specifier|volatile
name|u_int32_t
name|ch2_TXRF5
decl_stmt|;
comment|/*      0x850 - 0x854      */
specifier|volatile
name|u_int32_t
name|ch2_TXRF6
decl_stmt|;
comment|/*      0x854 - 0x858      */
specifier|volatile
name|char
name|pad__18
index|[
literal|0xa8
index|]
decl_stmt|;
comment|/*      0x858 - 0x900      */
specifier|volatile
name|u_int32_t
name|ch2_RXTX1
decl_stmt|;
comment|/*      0x900 - 0x904      */
specifier|volatile
name|u_int32_t
name|ch2_RXTX2
decl_stmt|;
comment|/*      0x904 - 0x908      */
specifier|volatile
name|u_int32_t
name|ch2_RXTX3
decl_stmt|;
comment|/*      0x908 - 0x90c      */
specifier|volatile
name|u_int32_t
name|ch2_RXTX4
decl_stmt|;
comment|/*      0x90c - 0x910      */
specifier|volatile
name|char
name|pad__19
index|[
literal|0x30
index|]
decl_stmt|;
comment|/*      0x910 - 0x940      */
specifier|volatile
name|u_int32_t
name|ch2_BB1
decl_stmt|;
comment|/*      0x940 - 0x944      */
specifier|volatile
name|u_int32_t
name|ch2_BB2
decl_stmt|;
comment|/*      0x944 - 0x948      */
specifier|volatile
name|u_int32_t
name|ch2_BB3
decl_stmt|;
comment|/*      0x948 - 0x94c      */
specifier|volatile
name|char
name|pad__20
index|[
literal|0x234
index|]
decl_stmt|;
comment|/*      0x94c - 0xb80      */
specifier|volatile
name|u_int32_t
name|ch2_rbist_cntrl
decl_stmt|;
comment|/*      0xb80 - 0xb84      */
specifier|volatile
name|u_int32_t
name|ch2_tx_dc_offset
decl_stmt|;
comment|/*      0xb84 - 0xb88      */
specifier|volatile
name|u_int32_t
name|ch2_tx_tonegen0
decl_stmt|;
comment|/*      0xb88 - 0xb8c      */
specifier|volatile
name|u_int32_t
name|ch2_tx_tonegen1
decl_stmt|;
comment|/*      0xb8c - 0xb90      */
specifier|volatile
name|u_int32_t
name|ch2_tx_lftonegen0
decl_stmt|;
comment|/*      0xb90 - 0xb94      */
specifier|volatile
name|u_int32_t
name|ch2_tx_linear_ramp_i
decl_stmt|;
comment|/*      0xb94 - 0xb98      */
specifier|volatile
name|u_int32_t
name|ch2_tx_linear_ramp_q
decl_stmt|;
comment|/*      0xb98 - 0xb9c      */
specifier|volatile
name|u_int32_t
name|ch2_tx_prbs_mag
decl_stmt|;
comment|/*      0xb9c - 0xba0      */
specifier|volatile
name|u_int32_t
name|ch2_tx_prbs_seed_i
decl_stmt|;
comment|/*      0xba0 - 0xba4      */
specifier|volatile
name|u_int32_t
name|ch2_tx_prbs_seed_q
decl_stmt|;
comment|/*      0xba4 - 0xba8      */
specifier|volatile
name|u_int32_t
name|ch2_cmac_dc_cancel
decl_stmt|;
comment|/*      0xba8 - 0xbac      */
specifier|volatile
name|u_int32_t
name|ch2_cmac_dc_offset
decl_stmt|;
comment|/*      0xbac - 0xbb0      */
specifier|volatile
name|u_int32_t
name|ch2_cmac_corr
decl_stmt|;
comment|/*      0xbb0 - 0xbb4      */
specifier|volatile
name|u_int32_t
name|ch2_cmac_power
decl_stmt|;
comment|/*      0xbb4 - 0xbb8      */
specifier|volatile
name|u_int32_t
name|ch2_cmac_cross_corr
decl_stmt|;
comment|/*      0xbb8 - 0xbbc      */
specifier|volatile
name|u_int32_t
name|ch2_cmac_i2q2
decl_stmt|;
comment|/*      0xbbc - 0xbc0      */
specifier|volatile
name|u_int32_t
name|ch2_cmac_power_hpf
decl_stmt|;
comment|/*      0xbc0 - 0xbc4      */
specifier|volatile
name|u_int32_t
name|ch2_rxdac_set1
decl_stmt|;
comment|/*      0xbc4 - 0xbc8      */
specifier|volatile
name|u_int32_t
name|ch2_rxdac_set2
decl_stmt|;
comment|/*      0xbc8 - 0xbcc      */
specifier|volatile
name|u_int32_t
name|ch2_rxdac_long_shift
decl_stmt|;
comment|/*      0xbcc - 0xbd0      */
specifier|volatile
name|u_int32_t
name|ch2_cmac_results_i
decl_stmt|;
comment|/*      0xbd0 - 0xbd4      */
specifier|volatile
name|u_int32_t
name|ch2_cmac_results_q
decl_stmt|;
comment|/*      0xbd4 - 0xbd8      */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scorpion_reg_map
block|{
name|struct
name|mac_dma_reg
name|mac_dma_reg_map
decl_stmt|;
comment|/*        0x0 - 0x128      */
specifier|volatile
name|char
name|pad__0
index|[
literal|0x6d8
index|]
decl_stmt|;
comment|/*      0x128 - 0x800      */
name|struct
name|mac_qcu_reg
name|mac_qcu_reg_map
decl_stmt|;
comment|/*      0x800 - 0xa48      */
specifier|volatile
name|char
name|pad__1
index|[
literal|0x5b8
index|]
decl_stmt|;
comment|/*      0xa48 - 0x1000     */
name|struct
name|mac_dcu_reg
name|mac_dcu_reg_map
decl_stmt|;
comment|/*     0x1000 - 0x1f08     */
specifier|volatile
name|char
name|pad__2
index|[
literal|0x50f8
index|]
decl_stmt|;
comment|/*     0x1f08 - 0x7000     */
name|struct
name|rtc_reg
name|rtc_reg_map
decl_stmt|;
comment|/*     0x7000 - 0x7040     */
name|struct
name|rtc_sync_reg
name|rtc_sync_reg_map
decl_stmt|;
comment|/*     0x7040 - 0x705c     */
specifier|volatile
name|char
name|pad__3
index|[
literal|0xfa4
index|]
decl_stmt|;
comment|/*     0x705c - 0x8000     */
name|struct
name|mac_pcu_reg
name|mac_pcu_reg_map
decl_stmt|;
comment|/*     0x8000 - 0x9800     */
name|struct
name|bb_reg_map
name|bb_reg_map
decl_stmt|;
comment|/*     0x9800 - 0xd800     */
specifier|volatile
name|char
name|pad__4
index|[
literal|0x800
index|]
decl_stmt|;
comment|/*     0xd800 - 0xe000     */
name|struct
name|mac_pcu_buf_reg
name|mac_pcu_buf_reg_map
decl_stmt|;
comment|/*     0xe000 - 0x10000    */
name|struct
name|svd_reg
name|svd_reg_map
decl_stmt|;
comment|/*    0x10000 - 0x12c00    */
specifier|volatile
name|char
name|pad__5
index|[
literal|0x3400
index|]
decl_stmt|;
comment|/*    0x12c00 - 0x16000    */
name|struct
name|radio65_reg
name|radio65_reg_map
decl_stmt|;
comment|/*    0x16000 - 0x16bd8    */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __REG_SCORPION_REG_MAP_H__ */
end_comment

end_unit

