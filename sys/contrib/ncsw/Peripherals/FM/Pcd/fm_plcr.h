begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2012 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          fm_plcr.h   @Description   FM Policer private header */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FM_PLCR_H
end_ifndef

begin_define
define|#
directive|define
name|__FM_PLCR_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_comment
comment|/***********************************************************************/
end_comment

begin_comment
comment|/*          Policer defines                                            */
end_comment

begin_comment
comment|/***********************************************************************/
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_GO
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_R
value|0x40000000
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PNUM_SHIFT
value|16
end_define

begin_comment
comment|/* masks */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_PI
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_CBLND
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_ALG_MASK
value|0x30000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_ALG_RFC2698
value|0x10000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_ALG_RFC4115
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_DEFC_MASK
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_DEFC_Y
value|0x04000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_DEFC_R
value|0x08000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_DEFC_OVERRIDE
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_OVCLR_MASK
value|0x03000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_OVCLR_Y
value|0x01000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_OVCLR_R
value|0x02000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_OVCLR_G_NC
value|0x03000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_PKT
value|0x00800000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FPP_MASK
value|0x001F0000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FPP_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FLS_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FLS_L2
value|0x00003000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FLS_L3
value|0x0000B000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FLS_L4
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_FLS_FULL
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_RBFLS
value|0x00000800
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_TRA
value|0x00000004
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_TRB
value|0x00000002
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PEMODE_TRC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_DOUBLE_ECC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_INIT_ENTRY_ERROR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PRAM_SELF_INIT_COMPLETE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_ATOMIC_ACTION_COMPLETE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_NIA_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GCR_EN
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GCR_STEN
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GCR_DAR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GCR_DEFNIA
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_NIA_ABS
value|0x00000100
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_BSY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_DQS
value|0x60000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_RPB
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_FQS
value|0x0C000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_LPALG
value|0x0000C000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_LPCA
value|0x00003000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_GSR_LPNUM
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_EVR_PSIC
value|0x80000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_EVR_AAC
value|0x40000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PSI
value|0x20000000
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PNUM
value|0x00FF0000
end_define

begin_comment
comment|/* PWSEL Selctive select options */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEMODE
value|0x00008000
end_define

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEGNIA
value|0x00004000
end_define

begin_comment
comment|/* 1 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEYNIA
value|0x00002000
end_define

begin_comment
comment|/* 2 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PERNIA
value|0x00001000
end_define

begin_comment
comment|/* 3 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PECIR
value|0x00000800
end_define

begin_comment
comment|/* 4 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PECBS
value|0x00000400
end_define

begin_comment
comment|/* 5 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEPIR_EIR
value|0x00000200
end_define

begin_comment
comment|/* 6 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEPBS_EBS
value|0x00000100
end_define

begin_comment
comment|/* 7 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PELTS
value|0x00000080
end_define

begin_comment
comment|/* 8 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PECTS
value|0x00000040
end_define

begin_comment
comment|/* 9 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEPTS_ETS
value|0x00000020
end_define

begin_comment
comment|/* 10 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEGPC
value|0x00000010
end_define

begin_comment
comment|/* 11 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PEYPC
value|0x00000008
end_define

begin_comment
comment|/* 12 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PERPC
value|0x00000004
end_define

begin_comment
comment|/* 13 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PERYPC
value|0x00000002
end_define

begin_comment
comment|/* 14 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PWSEL_PERRPC
value|0x00000001
end_define

begin_comment
comment|/* 15 */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_1TO1
value|0x0000
end_define

begin_comment
comment|/* - Full bit replacement. {PBNUM[0:N-1]                                                            1-> 2^N specific locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_2TO2
value|0x1
end_define

begin_comment
comment|/* - {PBNUM[0:N-2],PNUM[N-1]}.                                                            2-> 2^(N-1) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_4TO4
value|0x2
end_define

begin_comment
comment|/* - {PBNUM[0:N-3],PNUM[N-2:N-1]}.                                                            4-> 2^(N-2) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_8TO8
value|0x3
end_define

begin_comment
comment|/* - {PBNUM[0:N-4],PNUM[N-3:N-1]}.                                                            8->2^(N-3) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_16TO16
value|0x4
end_define

begin_comment
comment|/* - {PBNUM[0:N-5],PNUM[N-4:N-1]}.                                                            16-> 2^(N-4) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_32TO32
value|0x5
end_define

begin_comment
comment|/* {PBNUM[0:N-6],PNUM[N-5:N-1]}.                                                            32-> 2^(N-5) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_64TO64
value|0x6
end_define

begin_comment
comment|/* {PBNUM[0:N-7],PNUM[N-6:N-1]}.                                                            64-> 2^(N-6) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_128TO128
value|0x7
end_define

begin_comment
comment|/* {PBNUM[0:N-8],PNUM[N-7:N-1]}.                                                             128-> 2^(N-7) base locations. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PAR_PMR_BRN_256TO256
value|0x8
end_define

begin_comment
comment|/* - No bit replacement for N=8. {PNUM[N-8:N-1]}.                                                             When N=8 this option maps all 256 profiles by the DISPATCH bus into one group. */
end_comment

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PMR_V
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_ECC_CAP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_ECC_TYPE_DOUBLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_ECC_PNUM_MASK
value|0x00000FF0
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_ECC_OFFSET_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_UNINIT_CAP
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_UNINIT_NUM_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_UNINIT_PID_MASK
value|0x003f0000
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_UNINIT_ABSOLUTE_MASK
value|0x00008000
end_define

begin_comment
comment|/* shifts */
end_comment

begin_define
define|#
directive|define
name|PLCR_ERR_ECC_PNUM_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|PLCR_ERR_UNINIT_PID_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|FM_PCD_PLCR_PMR_BRN_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|PLCR_PORT_WINDOW_SIZE
parameter_list|(
name|hardwarePortId
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __FM_PLCR_H */
end_comment

end_unit

