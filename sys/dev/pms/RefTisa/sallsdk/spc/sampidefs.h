begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file sampidefs.h  *  \brief The file defines the constants used by SAS/SATA LL layer  *  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SAMPIDEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__SAMPIDEFS_H__
end_define

begin_comment
comment|/* for Request Opcode of IOMB */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_ECHO
value|0x001
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_PHYSTART
value|0x004
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_PHYSTOP
value|0x005
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SSPINIIOSTART
value|0x006
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SSPINITMSTART
value|0x007
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SSPINIEXTIOSTART
value|0x008
end_define

begin_comment
comment|/*  V reserved */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_DEV_HANDLE_ACCEPT
value|0x009
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SSPTGTIOSTART
value|0x00a
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SSPTGTRSPSTART
value|0x00b
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SSP_ABORT
value|0x00f
end_define

begin_comment
comment|/*  */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_DEREG_DEV_HANDLE
value|0x010
end_define

begin_comment
comment|/* 16 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_GET_DEV_HANDLE
value|0x011
end_define

begin_comment
comment|/* 17 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SMP_REQUEST
value|0x012
end_define

begin_comment
comment|/* 18 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SMP_ABORT
value|0x014
end_define

begin_comment
comment|/* 20 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SPC_REG_DEV
value|0x016
end_define

begin_comment
comment|/* 22 V reserved */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SATA_HOST_OPSTART
value|0x017
end_define

begin_comment
comment|/* 23 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SATA_ABORT
value|0x018
end_define

begin_comment
comment|/* 24 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_LOCAL_PHY_CONTROL
value|0x019
end_define

begin_comment
comment|/* 25 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SPC_GET_DEV_INFO
value|0x01a
end_define

begin_comment
comment|/* 26 V reserved */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_FW_FLASH_UPDATE
value|0x020
end_define

begin_comment
comment|/* 32 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_GPIO
value|0x022
end_define

begin_comment
comment|/* 34 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SAS_DIAG_MODE_START_END
value|0x023
end_define

begin_comment
comment|/* 35 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SAS_DIAG_EXECUTE
value|0x024
end_define

begin_comment
comment|/* 36 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SPC_SAS_HW_EVENT_ACK
value|0x025
end_define

begin_comment
comment|/* 37 V reserved */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_GET_TIME_STAMP
value|0x026
end_define

begin_comment
comment|/* 38 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_PORT_CONTROL
value|0x027
end_define

begin_comment
comment|/* 39 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_GET_NVMD_DATA
value|0x028
end_define

begin_comment
comment|/* 40 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SET_NVMD_DATA
value|0x029
end_define

begin_comment
comment|/* 41 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SET_DEVICE_STATE
value|0x02a
end_define

begin_comment
comment|/* 42 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_GET_DEVICE_STATE
value|0x02b
end_define

begin_comment
comment|/* 43 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SET_DEV_INFO
value|0x02c
end_define

begin_comment
comment|/* 44 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SAS_RE_INITIALIZE
value|0x02d
end_define

begin_comment
comment|/* 45 V reserved */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SGPIO
value|0x02e
end_define

begin_comment
comment|/* 46 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_PCIE_DIAG_EXECUTE
value|0x02f
end_define

begin_comment
comment|/* 47 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SET_CONTROLLER_CONFIG
value|0x030
end_define

begin_comment
comment|/* 48 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_GET_CONTROLLER_CONFIG
value|0x031
end_define

begin_comment
comment|/* 49 */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_REG_DEV
value|0x032
end_define

begin_comment
comment|/* 50 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SAS_HW_EVENT_ACK
value|0x033
end_define

begin_comment
comment|/* 51 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_GET_DEV_INFO
value|0x034
end_define

begin_comment
comment|/* 52 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_GET_PHY_PROFILE
value|0x035
end_define

begin_comment
comment|/* 53 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_FLASH_OP_EXT
value|0x036
end_define

begin_comment
comment|/* 54 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SET_PHY_PROFILE
value|0x037
end_define

begin_comment
comment|/* 55 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_GET_DFE_DATA
value|0x038
end_define

begin_comment
comment|/* 56 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_GET_VHIST_CAP
value|0x039
end_define

begin_comment
comment|/* 57 SPCV12g */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_KEK_MANAGEMENT
value|0x100
end_define

begin_comment
comment|/* 256 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_DEK_MANAGEMENT
value|0x101
end_define

begin_comment
comment|/* 257 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SSP_DIF_ENC_OPSTART
value|0x102
end_define

begin_comment
comment|/* 258 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SATA_DIF_ENC_OPSTART
value|0x103
end_define

begin_comment
comment|/* 259 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_OPR_MGMT
value|0x104
end_define

begin_comment
comment|/* 260 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_ENC_TEST_EXECUTE
value|0x105
end_define

begin_comment
comment|/* 261 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_SET_OPERATOR
value|0x106
end_define

begin_comment
comment|/* 262 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_GET_OPERATOR
value|0x107
end_define

begin_comment
comment|/* 263 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_DIF_ENC_OFFLOAD_CMD
value|0x110
end_define

begin_comment
comment|/* 272 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_INB_FW_PROFILE
value|0x888
end_define

begin_comment
comment|/* 2184 SPCV */
end_comment

begin_comment
comment|/* for Response Opcode of IOMB */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_ECHO
value|0x001
end_define

begin_comment
comment|/* 1 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SPC_HW_EVENT
value|0x004
end_define

begin_comment
comment|/*  4 V reserved Now OPC_OUB_HW_EVENT */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SSP_COMP
value|0x005
end_define

begin_comment
comment|/* 5 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SMP_COMP
value|0x006
end_define

begin_comment
comment|/* 6 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_LOCAL_PHY_CNTRL
value|0x007
end_define

begin_comment
comment|/* 7 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SPC_DEV_REGIST
value|0x00a
end_define

begin_comment
comment|/* 10 V reserved Now OPC_OUB_DEV_REGIST */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_DEREG_DEV
value|0x00b
end_define

begin_comment
comment|/* 11 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GET_DEV_HANDLE
value|0x00c
end_define

begin_comment
comment|/* 12 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SATA_COMP
value|0x00d
end_define

begin_comment
comment|/* 13 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SATA_EVENT
value|0x00e
end_define

begin_comment
comment|/* 14 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SSP_EVENT
value|0x00f
end_define

begin_comment
comment|/* 15 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SPC_DEV_HANDLE_ARRIV
value|0x010
end_define

begin_comment
comment|/* 16 V reserved Now OPC_OUB_DEV_HANDLE_ARRIV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SSP_RECV_EVENT
value|0x012
end_define

begin_comment
comment|/* 18 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SPC_DEV_INFO
value|0x013
end_define

begin_comment
comment|/* 19 V reserved Now OPC_OUB_DEV_INFO*/
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_FW_FLASH_UPDATE
value|0x014
end_define

begin_comment
comment|/* 20 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GPIO_RESPONSE
value|0x016
end_define

begin_comment
comment|/* 22 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GPIO_EVENT
value|0x017
end_define

begin_comment
comment|/* 23 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GENERAL_EVENT
value|0x018
end_define

begin_comment
comment|/* 24 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SSP_ABORT_RSP
value|0x01a
end_define

begin_comment
comment|/* 26 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SATA_ABORT_RSP
value|0x01b
end_define

begin_comment
comment|/* 27 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SAS_DIAG_MODE_START_END
value|0x01c
end_define

begin_comment
comment|/* 28 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SAS_DIAG_EXECUTE
value|0x01d
end_define

begin_comment
comment|/* 29 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GET_TIME_STAMP
value|0x01e
end_define

begin_comment
comment|/* 30 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SPC_SAS_HW_EVENT_ACK
value|0x01f
end_define

begin_comment
comment|/* 31 V reserved Now OPC_OUB_SAS_HW_EVENT_ACK*/
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_PORT_CONTROL
value|0x020
end_define

begin_comment
comment|/* 32 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SKIP_ENTRY
value|0x021
end_define

begin_comment
comment|/* 33 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SMP_ABORT_RSP
value|0x022
end_define

begin_comment
comment|/* 34 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GET_NVMD_DATA
value|0x023
end_define

begin_comment
comment|/* 35 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SET_NVMD_DATA
value|0x024
end_define

begin_comment
comment|/* 36 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_DEVICE_HANDLE_REMOVAL
value|0x025
end_define

begin_comment
comment|/* 37 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SET_DEVICE_STATE
value|0x026
end_define

begin_comment
comment|/* 38 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GET_DEVICE_STATE
value|0x027
end_define

begin_comment
comment|/* 39 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SET_DEV_INFO
value|0x028
end_define

begin_comment
comment|/* 40 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SAS_RE_INITIALIZE
value|0x029
end_define

begin_comment
comment|/* 41 V reserved not replaced */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_HW_EVENT
value|0x700
end_define

begin_comment
comment|/* 1792 SPCV Was OPC_OUB_SPC_HW_EVENT*/
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_DEV_HANDLE_ARRIV
value|0x720
end_define

begin_comment
comment|/* 1824 SPCV Was OPC_OUB_SPC_DEV_HANDLE_ARRIV*/
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_PHY_START_RESPONSE
value|0x804
end_define

begin_comment
comment|/* 2052 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_PHY_STOP_RESPONSE
value|0x805
end_define

begin_comment
comment|/* 2053 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SGPIO_RESPONSE
value|0x82E
end_define

begin_comment
comment|/* 2094 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_PCIE_DIAG_EXECUTE
value|0x82F
end_define

begin_comment
comment|/* 2095 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SET_CONTROLLER_CONFIG
value|0x830
end_define

begin_comment
comment|/* 2096 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GET_CONTROLLER_CONFIG
value|0x831
end_define

begin_comment
comment|/* 2097 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_DEV_REGIST
value|0x832
end_define

begin_comment
comment|/* 2098 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SAS_HW_EVENT_ACK
value|0x833
end_define

begin_comment
comment|/* 2099 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_DEV_INFO
value|0x834
end_define

begin_comment
comment|/* 2100 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GET_PHY_PROFILE_RSP
value|0x835
end_define

begin_comment
comment|/* 2101 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_FLASH_OP_EXT_RSP
value|0x836
end_define

begin_comment
comment|/* 2102 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SET_PHY_PROFILE_RSP
value|0x837
end_define

begin_comment
comment|/* 2103 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GET_DFE_DATA_RSP
value|0x838
end_define

begin_comment
comment|/* 2104 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GET_VIST_CAP_RSP
value|0x839
end_define

begin_comment
comment|/* Can be 2104 for SPCV12g  */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_FW_PROFILE
value|0x888
end_define

begin_comment
comment|/* 2184 */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_KEK_MANAGEMENT
value|0x900
end_define

begin_comment
comment|/* 2304 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_DEK_MANAGEMENT
value|0x901
end_define

begin_comment
comment|/* 2305 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_COMBINED_SSP_COMP
value|0x902
end_define

begin_comment
comment|/* 2306 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_COMBINED_SATA_COMP
value|0x903
end_define

begin_comment
comment|/* 2307 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_OPR_MGMT
value|0x904
end_define

begin_comment
comment|/* 2308 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_ENC_TEST_EXECUTE
value|0x905
end_define

begin_comment
comment|/* 2309 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_SET_OPERATOR
value|0x906
end_define

begin_comment
comment|/* 2310 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_GET_OPERATOR
value|0x907
end_define

begin_comment
comment|/* 2311 SPCV */
end_comment

begin_define
define|#
directive|define
name|OPC_OUB_DIF_ENC_OFFLOAD_RSP
value|0x910
end_define

begin_comment
comment|/* 2320 SPCV */
end_comment

begin_comment
comment|/* Definitions for encryption key management */
end_comment

begin_define
define|#
directive|define
name|KEK_MGMT_SUBOP_INVALIDATE
value|0x1
end_define

begin_define
define|#
directive|define
name|KEK_MGMT_SUBOP_UPDATE
value|0x2
end_define

begin_define
define|#
directive|define
name|KEK_MGMT_SUBOP_KEYCARDINVALIDATE
value|0x3
end_define

begin_define
define|#
directive|define
name|KEK_MGMT_SUBOP_KEYCARDUPDATE
value|0x4
end_define

begin_define
define|#
directive|define
name|DEK_MGMT_SUBOP_INVALIDATE
value|0x1
end_define

begin_define
define|#
directive|define
name|DEK_MGMT_SUBOP_UPDATE
value|0x2
end_define

begin_comment
comment|/***************************************************  *           typedef for IOMB structure  ***************************************************/
end_comment

begin_comment
comment|/** \brief the data structure of Echo Command  *  * use to describe MPI Echo Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaEchoCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|payload
index|[
literal|14
index|]
decl_stmt|;
block|}
name|agsaEchoCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of PHY Start Command  *  * use to describe MPI PHY Start Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyStartCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|SscdAseSHLmMlrPhyId
decl_stmt|;
name|agsaSASIdentify_t
name|sasIdentify
decl_stmt|;
name|bit32
name|analogSetupIdx
decl_stmt|;
name|bit32
name|SAWT_DAWT
decl_stmt|;
name|bit32
name|reserved
index|[
literal|5
index|]
decl_stmt|;
block|}
name|agsaPhyStartCmd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SPINHOLD_DISABLE
value|(0x00<< 14)
end_define

begin_define
define|#
directive|define
name|SPINHOLD_ENABLE
value|(0x01<< 14)
end_define

begin_define
define|#
directive|define
name|LINKMODE_SAS
value|(0x01<< 12)
end_define

begin_define
define|#
directive|define
name|LINKMODE_DSATA
value|(0x02<< 12)
end_define

begin_define
define|#
directive|define
name|LINKMODE_AUTO
value|(0x03<< 12)
end_define

begin_define
define|#
directive|define
name|LINKRATE_15
value|(0x01<< 8)
end_define

begin_define
define|#
directive|define
name|LINKRATE_30
value|(0x02<< 8)
end_define

begin_define
define|#
directive|define
name|LINKRATE_60
value|(0x04<< 8)
end_define

begin_define
define|#
directive|define
name|LINKRATE_12
value|(0x08<< 8)
end_define

begin_comment
comment|/** \brief the data structure of PHY Stop Command  *  * use to describe MPI PHY Start Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPhyStopCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|phyId
decl_stmt|;
name|bit32
name|reserved
index|[
literal|13
index|]
decl_stmt|;
block|}
name|agsaPhyStopCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SSP INI IO Start Command  *  * use to describe MPI SSP INI IO Start Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPIniIOStartCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|dataLen
decl_stmt|;
name|bit32
name|dirMTlr
decl_stmt|;
name|agsaSSPCmdInfoUnit_t
name|SSPInfoUnit
decl_stmt|;
name|bit32
name|AddrLow0
decl_stmt|;
name|bit32
name|AddrHi0
decl_stmt|;
name|bit32
name|Len0
decl_stmt|;
name|bit32
name|E0
decl_stmt|;
block|}
name|agsaSSPIniIOStartCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SSP INI TM Start Command  *  * use to describe MPI SSP INI TM Start Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPIniTMStartCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|relatedTag
decl_stmt|;
name|bit32
name|TMfunction
decl_stmt|;
name|bit8
name|lun
index|[
literal|8
index|]
decl_stmt|;
name|bit32
name|dsAdsMReport
decl_stmt|;
name|bit32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
name|agsaSSPIniTMStartCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SSP INI Extended IO Start Command  *  * use to describe MPI SSP INI Extended CDB Start Command (96 bytes to support 32 CDB)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPIniExtIOStartCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|dataLen
decl_stmt|;
name|bit32
name|SSPIuLendirMTlr
decl_stmt|;
name|bit8
name|SSPIu
index|[
literal|1
index|]
decl_stmt|;
comment|/* variable lengh */
comment|/*  bit32            AddrLow0; */
comment|/*  bit32            AddrHi0;  */
comment|/*  bit32            Len0;     */
comment|/*  bit32            E0;       */
block|}
name|agsaSSPIniExtIOStartCmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPIniEncryptIOStartCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|deviceId
decl_stmt|;
comment|/* 2 */
name|bit32
name|dataLen
decl_stmt|;
comment|/* 3 */
name|bit32
name|dirMTlr
decl_stmt|;
comment|/* 4 */
name|bit32
name|sspiu_0_3_indcdbalL
decl_stmt|;
comment|/* 5 */
name|bit32
name|sspiu_4_7_indcdbalH
decl_stmt|;
comment|/* 6 */
name|bit32
name|sspiu_8_11
decl_stmt|;
comment|/* 7 */
name|bit32
name|sspiu_12_15
decl_stmt|;
comment|/* 8 */
name|bit32
name|sspiu_16_19
decl_stmt|;
comment|/* 9 */
name|bit32
name|sspiu_19_23
decl_stmt|;
comment|/* 10 */
name|bit32
name|sspiu_24_27
decl_stmt|;
comment|/* 11 */
name|bit32
name|epl_descL
decl_stmt|;
comment|/* 12 */
name|bit32
name|dpl_descL
decl_stmt|;
comment|/* 13 */
name|bit32
name|edpl_descH
decl_stmt|;
comment|/* 14 */
name|bit32
name|DIF_flags
decl_stmt|;
comment|/* 15 */
name|bit32
name|udt
decl_stmt|;
comment|/* 16 0x10 */
name|bit32
name|udtReplacementLo
decl_stmt|;
comment|/* 17 */
name|bit32
name|udtReplacementHi
decl_stmt|;
comment|/* 18 */
name|bit32
name|DIF_seed
decl_stmt|;
comment|/* 19 */
name|bit32
name|encryptFlagsLo
decl_stmt|;
comment|/* 20 0x14 */
name|bit32
name|encryptFlagsHi
decl_stmt|;
comment|/* 21 */
name|bit32
name|keyTag_W0
decl_stmt|;
comment|/* 22 */
name|bit32
name|keyTag_W1
decl_stmt|;
comment|/* 23 */
name|bit32
name|tweakVal_W0
decl_stmt|;
comment|/* 24 0x18 */
name|bit32
name|tweakVal_W1
decl_stmt|;
comment|/* 25 */
name|bit32
name|tweakVal_W2
decl_stmt|;
comment|/* 26 */
name|bit32
name|tweakVal_W3
decl_stmt|;
comment|/* 27 */
name|bit32
name|AddrLow0
decl_stmt|;
comment|/* 28 0x1C */
name|bit32
name|AddrHi0
decl_stmt|;
comment|/* 29 */
name|bit32
name|Len0
decl_stmt|;
comment|/* 30 */
name|bit32
name|E0
decl_stmt|;
comment|/* 31 */
block|}
name|agsaSSPIniEncryptIOStartCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SSP Abort Command  *  * use to describe MPI SSP Abort Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPAbortCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|HTagAbort
decl_stmt|;
name|bit32
name|abortAll
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaSSPAbortCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Register Device Command  *  * use to describe MPI DEVICE REGISTER Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaRegDevCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|phyIdportId
decl_stmt|;
name|bit32
name|dTypeLRateAwtHa
decl_stmt|;
name|bit32
name|ITNexusTimeOut
decl_stmt|;
name|bit32
name|sasAddrHi
decl_stmt|;
name|bit32
name|sasAddrLo
decl_stmt|;
name|bit32
name|DeviceId
decl_stmt|;
name|bit32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
name|agsaRegDevCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Deregister Device Handle Command  *  * use to describe MPI DEREGISTER DEVIDE HANDLE Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDeregDevHandleCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|portId
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaDeregDevHandleCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Get Device Handle Command  *  * use to describe MPI GET DEVIDE HANDLE Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetDevHandleCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|DevADevTMaxDIDportId
decl_stmt|;
name|bit32
name|skipCount
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaGetDevHandleCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SMP Request Command  *  * use to describe MPI SMP REQUEST Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSMPCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|IR_IP_OV_res_phyId_DPdLen_res
decl_stmt|;
comment|/* Bits [0]  - IR */
comment|/* Bits [1] - IP */
comment|/* Bits [15:2] - Reserved */
comment|/* Bits [23:16] - Len */
comment|/* Bits [31:24] - Reserved */
name|bit32
name|SMPCmd
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaSMPCmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaSMPCmd_V_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|deviceId
decl_stmt|;
comment|/* 2 */
name|bit32
name|IR_IP_OV_res_phyId_DPdLen_res
decl_stmt|;
comment|/* 3 */
comment|/* Bits [0]  - IR */
comment|/* Bits [1] - IP */
comment|/* Bits [15:2] - Reserved */
comment|/* Bits [23:16] - Len */
comment|/* Bits [31:24] - Reserved */
name|bit32
name|SMPHDR
decl_stmt|;
comment|/* 4 */
name|bit32
name|SMP3_0
decl_stmt|;
comment|/* 5 */
name|bit32
name|SMP7_4
decl_stmt|;
comment|/* 6 */
name|bit32
name|SMP11_8
decl_stmt|;
comment|/* 7 */
name|bit32
name|IndirL_SMPRF15_12
decl_stmt|;
comment|/* 8 */
name|bit32
name|IndirH_or_SMPRF19_16
decl_stmt|;
comment|/* 9 */
name|bit32
name|IndirLen_or_SMPRF23_20
decl_stmt|;
comment|/* 10 */
name|bit32
name|R_or_SMPRF27_24
decl_stmt|;
comment|/* 11 */
name|bit32
name|ISRAL_or_SMPRF31_28
decl_stmt|;
comment|/* 12 */
name|bit32
name|ISRAH_or_SMPRF35_32
decl_stmt|;
comment|/* 13 */
name|bit32
name|ISRL_or_SMPRF39_36
decl_stmt|;
comment|/* 14 */
name|bit32
name|R_or_SMPRF43_40
decl_stmt|;
comment|/* 15 */
block|}
name|agsaSMPCmd_V_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SMP Abort Command  *  * use to describe MPI SMP Abort Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSMPAbortCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|HTagAbort
decl_stmt|;
name|bit32
name|Scp
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaSMPAbortCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SATA Start Command  *  * use to describe MPI SATA Start Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSATAStartCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|deviceId
decl_stmt|;
comment|/* 2 */
name|bit32
name|dataLen
decl_stmt|;
comment|/* 3 */
name|bit32
name|optNCQTagataProt
decl_stmt|;
comment|/* 4 */
name|agsaFisRegHostToDevice_t
name|sataFis
decl_stmt|;
comment|/* 5 6 7 8 9 */
name|bit32
name|reserved1
decl_stmt|;
comment|/* 10 */
name|bit32
name|reserved2
decl_stmt|;
comment|/* 11 */
name|bit32
name|AddrLow0
decl_stmt|;
comment|/* 12 */
name|bit32
name|AddrHi0
decl_stmt|;
comment|/* 13 */
name|bit32
name|Len0
decl_stmt|;
comment|/* 14 */
name|bit32
name|E0
decl_stmt|;
comment|/* 15 */
name|bit32
name|ATAPICDB
index|[
literal|4
index|]
decl_stmt|;
comment|/* 16-19 */
block|}
name|agsaSATAStartCmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaSATAEncryptStartCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|IniDeviceId
decl_stmt|;
comment|/* 2 */
name|bit32
name|dataLen
decl_stmt|;
comment|/* 3 */
name|bit32
name|optNCQTagataProt
decl_stmt|;
comment|/* 4 */
name|agsaFisRegHostToDevice_t
name|sataFis
decl_stmt|;
comment|/* 5 6 7 8 9 */
name|bit32
name|reserved1
decl_stmt|;
comment|/* 10 */
name|bit32
name|Res_EPL_DESCL
decl_stmt|;
comment|/* 11 */
name|bit32
name|resSKIPBYTES
decl_stmt|;
comment|/* 12 */
name|bit32
name|Res_DPL_DESCL_NDPLR
decl_stmt|;
comment|/* 13 DIF per LA Address lo if DPLE is 1 */
name|bit32
name|Res_EDPL_DESCH
decl_stmt|;
comment|/* 14 DIF per LA Address hi if DPLE is 1 */
name|bit32
name|DIF_flags
decl_stmt|;
comment|/* 15 */
name|bit32
name|udt
decl_stmt|;
comment|/* 16 */
name|bit32
name|udtReplacementLo
decl_stmt|;
comment|/* 17 */
name|bit32
name|udtReplacementHi
decl_stmt|;
comment|/* 18 */
name|bit32
name|DIF_seed
decl_stmt|;
comment|/* 19 */
name|bit32
name|encryptFlagsLo
decl_stmt|;
comment|/* 20 */
name|bit32
name|encryptFlagsHi
decl_stmt|;
comment|/* 21 */
name|bit32
name|keyTagLo
decl_stmt|;
comment|/* 22 */
name|bit32
name|keyTagHi
decl_stmt|;
comment|/* 23 */
name|bit32
name|tweakVal_W0
decl_stmt|;
comment|/* 24 */
name|bit32
name|tweakVal_W1
decl_stmt|;
comment|/* 25 */
name|bit32
name|tweakVal_W2
decl_stmt|;
comment|/* 26 */
name|bit32
name|tweakVal_W3
decl_stmt|;
comment|/* 27 */
name|bit32
name|AddrLow0
decl_stmt|;
comment|/* 28 */
name|bit32
name|AddrHi0
decl_stmt|;
comment|/* 29 */
name|bit32
name|Len0
decl_stmt|;
comment|/* 30 */
name|bit32
name|E0
decl_stmt|;
comment|/* 31 */
block|}
name|agsaSATAEncryptStartCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SATA Abort Command  *  * use to describe MPI SATA Abort Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSATAAbortCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|HTagAbort
decl_stmt|;
name|bit32
name|abortAll
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaSATAAbortCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Local PHY Control Command  *  * use to describe MPI LOCAL PHY CONTROL Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaLocalPhyCntrlCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|phyOpPhyId
decl_stmt|;
name|bit32
name|reserved1
index|[
literal|14
index|]
decl_stmt|;
block|}
name|agsaLocalPhyCntrlCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Get Device Info Command  *  * use to describe MPI GET DEVIDE INFO Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetDevInfoCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|DeviceId
decl_stmt|;
name|bit32
name|reserved
index|[
literal|13
index|]
decl_stmt|;
block|}
name|agsaGetDevInfoCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of HW Reset Command  *  * use to describe MPI HW Reset Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaHWResetCmd_s
block|{
name|bit32
name|option
decl_stmt|;
name|bit32
name|reserved
index|[
literal|14
index|]
decl_stmt|;
block|}
name|agsaHWResetCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Firmware download  *  * use to describe MPI FW DOWNLOAD Command (64 bytes)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFwFlashUpdate_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|curImageOffset
decl_stmt|;
name|bit32
name|curImageLen
decl_stmt|;
name|bit32
name|totalImageLen
decl_stmt|;
name|bit32
name|reserved0
index|[
literal|7
index|]
decl_stmt|;
name|bit32
name|SGLAL
decl_stmt|;
name|bit32
name|SGLAH
decl_stmt|;
name|bit32
name|Len
decl_stmt|;
name|bit32
name|extReserved
decl_stmt|;
block|}
name|agsaFwFlashUpdate_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure EXT Flash Op  *  * use to describe Extented Flash Operation Command (128 bytes)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFwFlashOpExt_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|Command
decl_stmt|;
name|bit32
name|PartOffset
decl_stmt|;
name|bit32
name|DataLength
decl_stmt|;
name|bit32
name|Reserved0
index|[
literal|7
index|]
decl_stmt|;
name|bit32
name|SGLAL
decl_stmt|;
name|bit32
name|SGLAH
decl_stmt|;
name|bit32
name|Len
decl_stmt|;
name|bit32
name|E_sgl
decl_stmt|;
name|bit32
name|Reserved
index|[
literal|15
index|]
decl_stmt|;
block|}
name|agsaFwFlashOpExt_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure EXT Flash Op  *  * use to describe Extented Flash Operation Command (64 bytes)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFwFlashOpExtRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|Command
decl_stmt|;
name|bit32
name|Status
decl_stmt|;
name|bit32
name|Epart_Size
decl_stmt|;
name|bit32
name|EpartSectSize
decl_stmt|;
name|bit32
name|Reserved
index|[
literal|10
index|]
decl_stmt|;
block|}
name|agsaFwFlashOpExtRsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FWFLASH_IOMB_RESERVED_LEN
value|0x07
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SPC_ENABLE_PROFILE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|agsaFwProfileIOMB_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|tcid_processor_cmd
decl_stmt|;
name|bit32
name|codeStartAdd
decl_stmt|;
name|bit32
name|codeEndAdd
decl_stmt|;
name|bit32
name|reserved0
index|[
literal|7
index|]
decl_stmt|;
name|bit32
name|SGLAL
decl_stmt|;
name|bit32
name|SGLAH
decl_stmt|;
name|bit32
name|Len
decl_stmt|;
name|bit32
name|extReserved
decl_stmt|;
block|}
name|agsaFwProfileIOMB_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FWPROFILE_IOMB_RESERVED_LEN
value|0x07
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** \brief the data structure of GPIO Commannd  *  * use to describe MPI GPIO Command (64 bytes)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGPIOCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|eOBIDGeGsGrGw
decl_stmt|;
name|bit32
name|GpioWrMsk
decl_stmt|;
name|bit32
name|GpioWrVal
decl_stmt|;
name|bit32
name|GpioIe
decl_stmt|;
name|bit32
name|OT11_0
decl_stmt|;
name|bit32
name|OT19_12
decl_stmt|;
comment|/* reserved for SPCv controller */
name|bit32
name|GPIEVChange
decl_stmt|;
name|bit32
name|GPIEVRise
decl_stmt|;
name|bit32
name|GPIEVFall
decl_stmt|;
name|bit32
name|reserved
index|[
literal|5
index|]
decl_stmt|;
block|}
name|agsaGPIOCmd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GPIO_GW_BIT
value|0x1
end_define

begin_define
define|#
directive|define
name|GPIO_GR_BIT
value|0x2
end_define

begin_define
define|#
directive|define
name|GPIO_GS_BIT
value|0x4
end_define

begin_define
define|#
directive|define
name|GPIO_GE_BIT
value|0x8
end_define

begin_comment
comment|/** \brief the data structure of SAS Diagnostic Start/End Command  *  * use to describe MPI SAS Diagnostic Start/End Command (64 bytes)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASDiagStartEndCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|OperationPhyId
decl_stmt|;
name|bit32
name|reserved
index|[
literal|13
index|]
decl_stmt|;
block|}
name|agsaSASDiagStartEndCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SAS Diagnostic Execute Command  *  * use to describe MPI SAS Diagnostic Execute Command for SPCv (128 bytes)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASDiagExecuteCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|CmdTypeDescPhyId
decl_stmt|;
comment|/* 2 */
name|bit32
name|Pat1Pat2
decl_stmt|;
comment|/* 3 */
name|bit32
name|Threshold
decl_stmt|;
comment|/* 4 */
name|bit32
name|CodePatErrMsk
decl_stmt|;
comment|/* 5 */
name|bit32
name|Pmon
decl_stmt|;
comment|/* 6 */
name|bit32
name|PERF1CTL
decl_stmt|;
comment|/* 7 */
name|bit32
name|THRSHLD1
decl_stmt|;
comment|/* 8 */
name|bit32
name|reserved
index|[
literal|23
index|]
decl_stmt|;
comment|/* 9 31 */
block|}
name|agsaSASDiagExecuteCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SAS Diagnostic Execute Command  *  * use to describe MPI SAS Diagnostic Execute Command for SPC (64 bytes)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsa_SPC_SASDiagExecuteCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|CmdTypeDescPhyId
decl_stmt|;
comment|/* 2 */
name|bit32
name|Pat1Pat2
decl_stmt|;
comment|/* 3 */
name|bit32
name|Threshold
decl_stmt|;
comment|/* 4 */
name|bit32
name|CodePatErrMsk
decl_stmt|;
comment|/* 5 */
name|bit32
name|Pmon
decl_stmt|;
comment|/* 6 */
name|bit32
name|PERF1CTL
decl_stmt|;
comment|/* 7 */
name|bit32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
comment|/* 8 15 */
block|}
name|agsa_SPC_SASDiagExecuteCmd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SAS_DIAG_PARAM_BYTES
value|24
end_define

begin_comment
comment|/** \brief the data structure of SSP TGT IO Start Command  *  * use to describe MPI SSP TGT IO Start Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPTgtIOStartCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/*  1 */
name|bit32
name|deviceId
decl_stmt|;
comment|/*  2 */
name|bit32
name|dataLen
decl_stmt|;
comment|/*  3 */
name|bit32
name|dataOffset
decl_stmt|;
comment|/*  4 */
name|bit32
name|INITagAgrDir
decl_stmt|;
comment|/*  5 */
name|bit32
name|reserved
decl_stmt|;
comment|/*  6 */
name|bit32
name|DIF_flags
decl_stmt|;
comment|/*  7 */
name|bit32
name|udt
decl_stmt|;
comment|/*  8 */
name|bit32
name|udtReplacementLo
decl_stmt|;
comment|/*  9 */
name|bit32
name|udtReplacementHi
decl_stmt|;
comment|/* 10 */
name|bit32
name|DIF_seed
decl_stmt|;
comment|/* 11 */
name|bit32
name|AddrLow0
decl_stmt|;
comment|/* 12 */
name|bit32
name|AddrHi0
decl_stmt|;
comment|/* 13 */
name|bit32
name|Len0
decl_stmt|;
comment|/* 14 */
name|bit32
name|E0
decl_stmt|;
comment|/* 15 */
block|}
name|agsaSSPTgtIOStartCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SSP TGT Response Start Command  *  * use to describe MPI SSP TGT Response Start Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPTgtRspStartCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|RspLen
decl_stmt|;
name|bit32
name|INITag_IP_AN
decl_stmt|;
name|bit32
name|reserved
index|[
literal|7
index|]
decl_stmt|;
name|bit32
name|AddrLow0
decl_stmt|;
name|bit32
name|AddrHi0
decl_stmt|;
name|bit32
name|Len0
decl_stmt|;
name|bit32
name|E0
decl_stmt|;
block|}
name|agsaSSPTgtRspStartCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Device Handle Accept Command  *  * use to describe MPI Device Handle Accept Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDevHandleAcceptCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|Ctag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|DevA_MCN_R_R_HA_ITNT
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaDevHandleAcceptCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SAS HW Event Ack Command  *  * use to describe MPI SAS HW Event Ack Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASHwEventAckCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|sEaPhyIdPortId
decl_stmt|;
name|bit32
name|Param0
decl_stmt|;
name|bit32
name|Param1
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaSASHwEventAckCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Get Time Stamp Command  *  * use to describe MPI Get Time Stamp Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetTimeStampCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|reserved
index|[
literal|14
index|]
decl_stmt|;
block|}
name|agsaGetTimeStampCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Port Control Command  *  * use to describe MPI Port Control Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPortControlCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|portOPPortId
decl_stmt|;
name|bit32
name|Param0
decl_stmt|;
name|bit32
name|Param1
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaPortControlCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Set NVM Data Command  *  * use to describe MPI Set NVM Data Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agNVMIndirect_s
block|{
name|bit32
name|signature
decl_stmt|;
name|bit32
name|reserved
index|[
literal|7
index|]
decl_stmt|;
name|bit32
name|ISglAL
decl_stmt|;
name|bit32
name|ISglAH
decl_stmt|;
name|bit32
name|ILen
decl_stmt|;
name|bit32
name|reserved1
decl_stmt|;
block|}
name|agNVMIndirect_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|agsaSetNVMData_s
block|{
name|bit32
name|NVMData
index|[
literal|12
index|]
decl_stmt|;
name|agNVMIndirect_t
name|indirectData
decl_stmt|;
block|}
name|agsaSetNVMData_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaSetNVMDataCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|LEN_IR_VPDD
decl_stmt|;
name|bit32
name|VPDOffset
decl_stmt|;
name|agsaSetNVMData_t
name|Data
decl_stmt|;
block|}
name|agsaSetNVMDataCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Get NVM Data Command  *  * use to describe MPI Get NVM Data Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetNVMDataCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|LEN_IR_VPDD
decl_stmt|;
name|bit32
name|VPDOffset
decl_stmt|;
name|bit32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
name|bit32
name|respAddrLo
decl_stmt|;
name|bit32
name|respAddrHi
decl_stmt|;
name|bit32
name|respLen
decl_stmt|;
name|bit32
name|reserved1
decl_stmt|;
block|}
name|agsaGetNVMDataCmd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TWI_DEVICE
value|0x0
end_define

begin_define
define|#
directive|define
name|C_SEEPROM
value|0x1
end_define

begin_define
define|#
directive|define
name|VPD_FLASH
value|0x4
end_define

begin_define
define|#
directive|define
name|AAP1_RDUMP
value|0x5
end_define

begin_define
define|#
directive|define
name|IOP_RDUMP
value|0x6
end_define

begin_define
define|#
directive|define
name|EXPAN_ROM
value|0x7
end_define

begin_define
define|#
directive|define
name|DIRECT_MODE
value|0x0
end_define

begin_define
define|#
directive|define
name|INDIRECT_MODE
value|0x1
end_define

begin_define
define|#
directive|define
name|IRMode
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IPMode
value|0x80000000
end_define

begin_define
define|#
directive|define
name|NVMD_TYPE
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|NVMD_STAT
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|NVMD_LEN
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|TWI_DEVICE
value|0x0
end_define

begin_define
define|#
directive|define
name|SEEPROM
value|0x1
end_define

begin_comment
comment|/** \brief the data structure of Set Device State Command  *  * use to describe MPI Set Device State Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSetDeviceStateCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|NDS
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaSetDeviceStateCmd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DS_OPERATIONAL
value|0x01
end_define

begin_define
define|#
directive|define
name|DS_IN_RECOVERY
value|0x03
end_define

begin_define
define|#
directive|define
name|DS_IN_ERROR
value|0x04
end_define

begin_define
define|#
directive|define
name|DS_NON_OPERATIONAL
value|0x07
end_define

begin_comment
comment|/** \brief the data structure of Get Device State Command  *  * use to describe MPI Get Device State Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetDeviceStateCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|reserved
index|[
literal|13
index|]
decl_stmt|;
block|}
name|agsaGetDeviceStateCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Set Device Info Command  *  * use to describe MPI OPC_INB_SET_DEV_INFO (0x02c) Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSetDevInfoCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|SA_SR_SI
decl_stmt|;
name|bit32
name|DEVA_MCN_R_ITNT
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaSetDevInfoCmd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SET_DEV_INFO_V_DW3_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|SET_DEV_INFO_V_DW4_MASK
value|0xFF07FFFF
end_define

begin_define
define|#
directive|define
name|SET_DEV_INFO_SPC_DW3_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|SET_DEV_INFO_SPC_DW4_MASK
value|0x003FFFF
end_define

begin_define
define|#
directive|define
name|SET_DEV_INFO_V_DW3_SM_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|SET_DEV_INFO_V_DW3_SA_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|SET_DEV_INFO_V_DW3_SR_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|SET_DEV_INFO_V_DW3_SI_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|SET_DEV_INFO_V_DW4_MCN_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|SET_DEV_INFO_V_DW4_AWT_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|SET_DEV_INFO_V_DW4_RETRY_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|SET_DEV_INFO_V_DW4_ITNEXUS_SHIFT
value|0
end_define

begin_comment
comment|/** \brief the data structure of SAS Re_Initialize Command  *  * use to describe MPI SAS RE_INITIALIZE Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSasReInitializeCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|setFlags
decl_stmt|;
name|bit32
name|MaxPorts
decl_stmt|;
name|bit32
name|openRejReCmdData
decl_stmt|;
name|bit32
name|sataHOLTMO
decl_stmt|;
name|bit32
name|reserved
index|[
literal|10
index|]
decl_stmt|;
block|}
name|agsaSasReInitializeCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SGPIO Command  *  * use to describe MPI serial GPIO Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSGpioCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|regIndexRegTypeFunctionFrameType
decl_stmt|;
name|bit32
name|regCount
decl_stmt|;
name|bit32
name|writeData
index|[
name|OSSA_SGPIO_MAX_WRITE_DATA_COUNT
index|]
decl_stmt|;
block|}
name|agsaSGpioCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of PCIE Diagnostic Command  *  * use to describe MPI PCIE Diagnostic Command for SPCv (128 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPCIeDiagExecuteCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|CmdTypeDesc
decl_stmt|;
comment|/* 2 */
name|bit32
name|UUM_EDA
decl_stmt|;
comment|/* 3 */
name|bit32
name|UDTR1_UDT0
decl_stmt|;
comment|/* 4 */
name|bit32
name|UDT5_UDT2
decl_stmt|;
comment|/* 5 */
name|bit32
name|UDTR5_UDTR2
decl_stmt|;
comment|/* 6 */
name|bit32
name|Res_IOS
decl_stmt|;
comment|/* 7 */
name|bit32
name|rdAddrLower
decl_stmt|;
comment|/* 8 */
name|bit32
name|rdAddrUpper
decl_stmt|;
comment|/* 9 */
name|bit32
name|wrAddrLower
decl_stmt|;
comment|/* 10 */
name|bit32
name|wrAddrUpper
decl_stmt|;
comment|/* 11 */
name|bit32
name|len
decl_stmt|;
comment|/* 12 */
name|bit32
name|pattern
decl_stmt|;
comment|/* 13 */
name|bit32
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
comment|/* 14 15 */
name|bit32
name|reserved3
index|[
literal|16
index|]
decl_stmt|;
comment|/* 15 31 */
block|}
name|agsaPCIeDiagExecuteCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of PCI Diagnostic Command for SPC  *  * use to describe MPI PCI Diagnostic Command for SPC (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsa_SPC_PCIDiagExecuteCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|CmdTypeDesc
decl_stmt|;
name|bit32
name|reserved1
index|[
literal|5
index|]
decl_stmt|;
name|bit32
name|rdAddrLower
decl_stmt|;
name|bit32
name|rdAddrUpper
decl_stmt|;
name|bit32
name|wrAddrLower
decl_stmt|;
name|bit32
name|wrAddrUpper
decl_stmt|;
name|bit32
name|len
decl_stmt|;
name|bit32
name|pattern
decl_stmt|;
name|bit32
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
block|}
name|agsa_SPC_PCIDiagExecuteCmd_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of GET DFE Data Command  *  * use to describe GET DFE Data Command for SPCv (128 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetDDEFDataCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|reserved_In_Ln
decl_stmt|;
comment|/* 2 */
name|bit32
name|MCNT
decl_stmt|;
comment|/* 3 */
name|bit32
name|reserved1
index|[
literal|3
index|]
decl_stmt|;
comment|/* 4 - 6 */
name|bit32
name|Buf_AddrL
decl_stmt|;
comment|/* 7 */
name|bit32
name|Buf_AddrH
decl_stmt|;
comment|/* 8 */
name|bit32
name|Buf_Len
decl_stmt|;
comment|/* 9 */
name|bit32
name|E_reserved
decl_stmt|;
comment|/* 10 */
name|bit32
name|reserved2
index|[
literal|21
index|]
decl_stmt|;
comment|/* 11 - 31 */
block|}
name|agsaGetDDEFDataCmd_t
typedef|;
end_typedef

begin_comment
comment|/***********************************************  * outbound IOMBs  ***********************************************/
end_comment

begin_comment
comment|/** \brief the data structure of Echo Response  *  * use to describe MPI Echo Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaEchoRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|payload
index|[
literal|14
index|]
decl_stmt|;
block|}
name|agsaEchoRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of HW Event from Outbound  *  * use to describe MPI HW Event (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaHWEvent_SPC_OUB_s
block|{
name|bit32
name|LRStatusEventPhyIdPortId
decl_stmt|;
name|bit32
name|EVParam
decl_stmt|;
name|bit32
name|NpipPortState
decl_stmt|;
name|agsaSASIdentify_t
name|sasIdentify
decl_stmt|;
name|agsaFisRegDeviceToHost_t
name|sataFis
decl_stmt|;
block|}
name|agsaHWEvent_SPC_OUB_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PHY_ID_BITS
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|LINK_RATE_MASK
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|STATUS_BITS
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|HW_EVENT_BITS
value|0x00FFFF00
end_define

begin_typedef
typedef|typedef
struct|struct
name|agsaHWEvent_Phy_OUB_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|Status
decl_stmt|;
name|bit32
name|ReservedPhyId
decl_stmt|;
block|}
name|agsaHWEvent_Phy_OUB_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of HW Event from Outbound  *  * use to describe MPI HW Event (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaHWEvent_V_OUB_s
block|{
name|bit32
name|LRStatEventPortId
decl_stmt|;
name|bit32
name|EVParam
decl_stmt|;
name|bit32
name|RsvPhyIdNpipRsvPortState
decl_stmt|;
name|agsaSASIdentify_t
name|sasIdentify
decl_stmt|;
name|agsaFisRegDeviceToHost_t
name|sataFis
decl_stmt|;
block|}
name|agsaHWEvent_V_OUB_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|PHY_ID_V_BITS
value|0x00FF0000
end_define

begin_define
define|#
directive|define
name|NIPP_V_BITS
value|0x0000FF00
end_define

begin_comment
comment|/** \brief the data structure of SSP Completion Response  *  * use to describe MPI SSP Completion Response (1024 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPCompletionRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|param
decl_stmt|;
name|bit32
name|SSPTag
decl_stmt|;
name|agsaSSPResponseInfoUnit_t
name|SSPrsp
decl_stmt|;
name|bit32
name|respData
decl_stmt|;
name|bit32
name|senseData
index|[
literal|5
index|]
decl_stmt|;
name|bit32
name|respData1
index|[
literal|239
index|]
decl_stmt|;
block|}
name|agsaSSPCompletionRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SSP Completion DIF Response  *  * use to describe MPI SSP Completion DIF Response (1024 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPCompletionDifRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|param
decl_stmt|;
name|bit32
name|SSPTag
decl_stmt|;
name|bit32
name|Device_Id
decl_stmt|;
name|bit32
name|UpperLBA
decl_stmt|;
name|bit32
name|LowerLBA
decl_stmt|;
name|bit32
name|sasAddressHi
decl_stmt|;
name|bit32
name|sasAddressLo
decl_stmt|;
name|bit32
name|ExpectedCRCUDT01
decl_stmt|;
name|bit32
name|ExpectedUDT2345
decl_stmt|;
name|bit32
name|ActualCRCUDT01
decl_stmt|;
name|bit32
name|ActualUDT2345
decl_stmt|;
name|bit32
name|DIFErrDevID
decl_stmt|;
name|bit32
name|ErrBoffsetEDataLen
decl_stmt|;
name|bit32
name|EDATA_FRM
decl_stmt|;
block|}
name|agsaSSPCompletionDifRsp_t
typedef|;
end_typedef

begin_comment
comment|/* SSPTag bit fields Bits [31:16] */
end_comment

begin_define
define|#
directive|define
name|SSP_RESCV_BIT
value|0x00010000
end_define

begin_comment
comment|/* Bits [16] */
end_comment

begin_define
define|#
directive|define
name|SSP_RESCV_PAD
value|0x00060000
end_define

begin_comment
comment|/* Bits [18:17] */
end_comment

begin_define
define|#
directive|define
name|SSP_RESCV_PAD_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|SSP_AGR_S_BIT
value|(1<< 19)
end_define

begin_comment
comment|/* Bits [19] */
end_comment

begin_comment
comment|/** \brief the data structure of SMP Completion Response  *  * use to describe MPI SMP Completion Response (1024 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSMPCompletionRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|param
decl_stmt|;
name|bit32
name|SMPrsp
index|[
literal|252
index|]
decl_stmt|;
block|}
name|agsaSMPCompletionRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Deregister Device Response  *  * use to describe MPI Deregister Device Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDeregDevHandleRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaDeregDevHandleRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Get Device Handle Response  *  * use to describe MPI Get Device Handle Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetDevHandleRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|DeviceIdcPortId
decl_stmt|;
name|bit32
name|deviceId
index|[
literal|13
index|]
decl_stmt|;
block|}
name|agsaGetDevHandleRsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|DEVICE_IDC_BITS
value|0x00FFFF00
end_define

begin_define
define|#
directive|define
name|DEVICE_ID_BITS
value|0x00000FFF
end_define

begin_comment
comment|/** \brief the data structure of Local Phy Control Response  *  * use to describe MPI Local Phy Control Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaLocalPhyCntrlRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|phyOpId
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaLocalPhyCntrlRsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|LOCAL_PHY_OP_BITS
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|LOCAL_PHY_PHYID
value|0x000000FF
end_define

begin_comment
comment|/** \brief the data structure of DEVICE_REGISTRATION Response  *  * use to describe device registration response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDeviceRegistrationRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaDeviceRegistrationRsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|FAILURE_OUT_OF_RESOURCE
value|0x01
end_define

begin_comment
comment|/* The device registration failed because the SPC 8x6G is running out of device handle resources. The parameter DEVICE_ID is not used. */
end_comment

begin_define
define|#
directive|define
name|FAILURE_DEVICE_ALREADY_REGISTERED
value|0x02
end_define

begin_comment
comment|/* The device registration failed because the SPC 8x6G detected an existing device handle with a similar SAS address. The parameter DEVICE_ID contains the existing  DEVICE _ID assigned to the SAS device. */
end_comment

begin_define
define|#
directive|define
name|FAILURE_INVALID_PHY_ID
value|0x03
end_define

begin_comment
comment|/* Only for directly-attached SATA registration. The device registration failed because the SPC 8x6G detected an invalid (out-of-range) PHY ID. */
end_comment

begin_define
define|#
directive|define
name|FAILURE_PHY_ID_ALREADY_REGISTERED
value|0x04
end_define

begin_comment
comment|/* Only for directly-attached SATA registration. The device registration failed because the SPC 8x6G detected an already -registered PHY ID for a directly attached SATA drive. */
end_comment

begin_define
define|#
directive|define
name|FAILURE_PORT_ID_OUT_OF_RANGE
value|0x05
end_define

begin_comment
comment|/* PORT_ID specified in the REGISTER_DEVICE Command is out-of range (0-7).  */
end_comment

begin_define
define|#
directive|define
name|FAILURE_PORT_NOT_VALID_STATE
value|0x06
end_define

begin_comment
comment|/* The PORT_ID specified in the REGISTER_DEVICE Command is not in PORT_VALID state. */
end_comment

begin_define
define|#
directive|define
name|FAILURE_DEVICE_TYPE_NOT_VALID
value|0x07
end_define

begin_comment
comment|/* The device type, specified in the S field in the REGISTER_DEVICE Command is not valid. */
end_comment

begin_define
define|#
directive|define
name|MPI_ERR_DEVICE_HANDLE_UNAVAILABLE
value|0x1020
end_define

begin_comment
comment|/* The device registration failed because the SPCv controller is running out of device handle resources. The parameter DEVICE_ID is not used. */
end_comment

begin_define
define|#
directive|define
name|MPI_ERR_DEVICE_ALREADY_REGISTERED
value|0x1021
end_define

begin_comment
comment|/* The device registration failed because the SPCv controller detected an existing device handle with the same SAS address. The parameter DEVICE_ID contains the existing DEVICE _ID assigned to the SAS device. */
end_comment

begin_define
define|#
directive|define
name|MPI_ERR_DEVICE_TYPE_NOT_VALID
value|0x1022
end_define

begin_comment
comment|/* The device type, specified in the S field in the REGISTER_DEVICE_HANDLE Command (page 274) is not valid. */
end_comment

begin_define
define|#
directive|define
name|MPI_ERR_PORT_INVALID_PORT_ID
value|0x1041
end_define

begin_comment
comment|/* specified in the REGISTER_DEVICE_HANDLE Command (page 274) is invalid. i.e Out of supported range  */
end_comment

begin_define
define|#
directive|define
name|MPI_ERR_PORT_STATE_NOT_VALID
value|0x1042
end_define

begin_comment
comment|/* The PORT_ID specified in the REGISTER_DEVICE_HANDLE Command (page 274) is not in PORT_VALID state.  */
end_comment

begin_define
define|#
directive|define
name|MPI_ERR_PORT_STATE_NOT_IN_USE
value|0x1043
end_define

begin_define
define|#
directive|define
name|MPI_ERR_PORT_OP_NOT_SUPPORTED
value|0x1044
end_define

begin_define
define|#
directive|define
name|MPI_ERR_PORT_SMP_PHY_WIDTH_EXCEED
value|0x1045
end_define

begin_define
define|#
directive|define
name|MPI_ERR_PORT_NOT_IN_CORRECT_STATE
value|0x1047
end_define

begin_comment
comment|/*MPI_ERR_DEVICE_ACCEPT_PENDING*/
end_comment

begin_define
define|#
directive|define
name|MPI_ERR_PHY_ID_INVALID
value|0x1061
end_define

begin_comment
comment|/* Only for directly-attached SATA registration. The device registration failed because the SPCv controller detected an invalid (out-of-range) PHY ID. */
end_comment

begin_define
define|#
directive|define
name|MPI_ERR_PHY_ID_ALREADY_REGISTERED
value|0x1062
end_define

begin_comment
comment|/* Only for directly-attached SATA registration. The device registration failed because the SPCv controller detected an alreadyregistered PHY ID for a directly-attached SATA drive. */
end_comment

begin_comment
comment|/** \brief the data structure of SATA Completion Response  *  * use to describe MPI SATA Completion Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSATACompletionRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|param
decl_stmt|;
name|bit32
name|FSATArsp
decl_stmt|;
name|bit32
name|respData
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaSATACompletionRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SATA Event Response  *  * use to describe MPI SATA Event Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSATAEventRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|event
decl_stmt|;
name|bit32
name|portId
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaSATAEventRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SSP Event Response  *  * use to describe MPI SSP Event Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPEventRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|event
decl_stmt|;
name|bit32
name|portId
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|SSPTag
decl_stmt|;
name|bit32
name|EVT_PARAM0_or_LBAH
decl_stmt|;
name|bit32
name|EVT_PARAM1_or_LBAL
decl_stmt|;
name|bit32
name|SAS_ADDRH
decl_stmt|;
name|bit32
name|SAS_ADDRL
decl_stmt|;
name|bit32
name|UDT1_E_UDT0_E_CRC_E
decl_stmt|;
name|bit32
name|UDT5_E_UDT4_E_UDT3_E_UDT2_E
decl_stmt|;
name|bit32
name|UDT1_A_UDT0_A_CRC_A
decl_stmt|;
name|bit32
name|UDT5_A_UDT4_A_UDT3_A_UDT2_A
decl_stmt|;
name|bit32
name|HW_DEVID_Reserved_DIF_ERR
decl_stmt|;
name|bit32
name|EDATA_LEN_ERR_BOFF
decl_stmt|;
name|bit32
name|EDATA_FRM
decl_stmt|;
block|}
name|agsaSSPEventRsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SSPTAG_BITS
value|0x0000FFFF
end_define

begin_comment
comment|/** \brief the data structure of Get Device Info Response  *  * use to describe MPI Get Device Info Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetDevInfoRspSpc_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|dTypeSrateSMPTOArPortID
decl_stmt|;
name|bit32
name|FirstBurstSizeITNexusTimeOut
decl_stmt|;
name|bit8
name|sasAddrHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasAddrLow
index|[
literal|4
index|]
decl_stmt|;
name|bit32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
name|agsaGetDevInfoRsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SMPTO_BITS
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|NEXUSTO_BITS
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|FIRST_BURST
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|FLAG_BITS
value|0x3
end_define

begin_define
define|#
directive|define
name|LINK_RATE_BITS
value|0xFF
end_define

begin_define
define|#
directive|define
name|DEV_TYPE_BITS
value|0x30000000
end_define

begin_comment
comment|/** \brief the data structure of Get Device Info Response V  *  * use to describe MPI Get Device Info Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetDevInfoRspV_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|ARSrateSMPTimeOutPortID
decl_stmt|;
name|bit32
name|IRMcnITNexusTimeOut
decl_stmt|;
name|bit8
name|sasAddrHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasAddrLow
index|[
literal|4
index|]
decl_stmt|;
name|bit32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
name|agsaGetDevInfoRspV_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SMPTO_VBITS
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|NEXUSTO_VBITS
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|FIRST_BURST_MCN
value|0xF
end_define

begin_define
define|#
directive|define
name|FLAG_VBITS
value|0x3
end_define

begin_define
define|#
directive|define
name|LINK_RATE_VBITS
value|0xFF
end_define

begin_define
define|#
directive|define
name|DEV_TYPE_VBITS
value|0x10000000
end_define

begin_comment
comment|/** \brief the data structure of Get Phy Profile Command IOMB V  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetPhyProfileCmd_V_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|Reserved_Ppc_SOP_PHYID
decl_stmt|;
name|bit32
name|reserved
index|[
literal|29
index|]
decl_stmt|;
block|}
name|agsaGetPhyProfileCmd_V_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Get Phy Profile Response IOMB V  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetPhyProfileRspV_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|Reserved_Ppc_SOP_PHYID
decl_stmt|;
name|bit32
name|PageSpecificArea
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaGetPhyProfileRspV_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Set Phy Profile Command IOMB V  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSetPhyProfileCmd_V_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|Reserved_Ppc_SOP_PHYID
decl_stmt|;
name|bit32
name|PageSpecificArea
index|[
literal|29
index|]
decl_stmt|;
block|}
name|agsaSetPhyProfileCmd_V_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of GetVis Command IOMB V  *  OPC_OUB_GET_VIST_CAP_RSP  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetVHistCap_V_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|Channel
decl_stmt|;
name|bit32
name|NumBitLo
decl_stmt|;
name|bit32
name|NumBitHi
decl_stmt|;
name|bit32
name|reserved0
decl_stmt|;
name|bit32
name|reserved1
decl_stmt|;
name|bit32
name|PcieAddrLo
decl_stmt|;
name|bit32
name|PcieAddrHi
decl_stmt|;
name|bit32
name|ByteCount
decl_stmt|;
name|bit32
name|reserved2
index|[
literal|22
index|]
decl_stmt|;
block|}
name|agsaGetVHistCap_V_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Set Phy Profile Response IOMB V  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSetPhyProfileRspV_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|Reserved_Ppc_PHYID
decl_stmt|;
name|bit32
name|PageSpecificArea
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaSetPhyProfileRspV_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaGetPhyInfoV_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|Reserved_SOP_PHYID
decl_stmt|;
name|bit32
name|reserved
index|[
literal|28
index|]
decl_stmt|;
block|}
name|agsaGetPhyInfoV_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SPC_GET_SAS_PHY_ERR_COUNTERS
value|1
end_define

begin_define
define|#
directive|define
name|SPC_GET_SAS_PHY_ERR_COUNTERS_CLR
value|2
end_define

begin_define
define|#
directive|define
name|SPC_GET_SAS_PHY_BW_COUNTERS
value|3
end_define

begin_comment
comment|/** \brief the data structure of FW_FLASH_UPDATE Response  *  * use to describe MPI FW_FLASH_UPDATE Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaFwFlashUpdateRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|reserved
index|[
literal|13
index|]
decl_stmt|;
block|}
name|agsaFwFlashUpdateRsp_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|SPC_ENABLE_PROFILE
end_ifdef

begin_typedef
typedef|typedef
struct|struct
name|agsaFwProfileRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|len
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaFwProfileRsp_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** \brief the data structure of GPIO Response  *  * use to describe MPI GPIO Response (64 bytes)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGPIORsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|bit32
name|GpioRdVal
decl_stmt|;
name|bit32
name|GpioIe
decl_stmt|;
name|bit32
name|OT11_0
decl_stmt|;
name|bit32
name|OT19_12
decl_stmt|;
name|bit32
name|GPIEVChange
decl_stmt|;
name|bit32
name|GPIEVRise
decl_stmt|;
name|bit32
name|GPIEVFall
decl_stmt|;
name|bit32
name|reserved1
index|[
literal|5
index|]
decl_stmt|;
block|}
name|agsaGPIORsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of GPIO Event  *  * use to describe MPI GPIO Event Response (64 bytes)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGPIOEvent_s
block|{
name|bit32
name|GpioEvent
decl_stmt|;
name|bit32
name|reserved
index|[
literal|14
index|]
decl_stmt|;
block|}
name|agsaGPIOEvent_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of GENERAL_EVENT Response  *  * use to describe MPI GENERNAL_EVENT Notification (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGenernalEventRsp_s
block|{
name|bit32
name|status
decl_stmt|;
name|bit32
name|inboundIOMB
index|[
literal|14
index|]
decl_stmt|;
block|}
name|agsaGenernalEventRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SSP_ABORT Response  *  * use to describe MPI SSP_ABORT (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPAbortRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|scp
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaSSPAbortRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SATA_ABORT Response  *  * use to describe MPI SATA_ABORT (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSATAAbortRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|scp
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaSATAAbortRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SAS Diagnostic Start/End Response  *  * use to describe MPI SAS Diagnostic Start/End Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASDiagStartEndRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|Status
decl_stmt|;
name|bit32
name|reserved
index|[
literal|13
index|]
decl_stmt|;
block|}
name|agsaSASDiagStartEndRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SAS Diagnostic Execute Response  *  * use to describe MPI SAS Diagnostic Execute Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASDiagExecuteRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|CmdTypeDescPhyId
decl_stmt|;
name|bit32
name|Status
decl_stmt|;
name|bit32
name|ReportData
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaSASDiagExecuteRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of General Event Notification Response  *  * use to describe MPI General Event Notification Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGeneralEventRsp_s
block|{
name|bit32
name|status
decl_stmt|;
name|bit32
name|inbIOMBpayload
index|[
literal|14
index|]
decl_stmt|;
block|}
name|agsaGeneralEventRsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GENERAL_EVENT_PAYLOAD
value|14
end_define

begin_define
define|#
directive|define
name|OPCODE_BITS
value|0x00000fff
end_define

begin_comment
comment|/* Table 171 GENERAL_EVENT Notification Status Field Codes Value Name Description */
end_comment

begin_define
define|#
directive|define
name|GEN_EVENT_IOMB_V_BIT_NOT_SET
value|0x01
end_define

begin_comment
comment|/* INBOUND_ Inbound IOMB is received with the V bit in the IOMB header not set. */
end_comment

begin_define
define|#
directive|define
name|GEN_EVENT_INBOUND_IOMB_OPC_NOT_SUPPORTED
value|0x02
end_define

begin_comment
comment|/* Inbound IOMB is received with an unsupported OPC. */
end_comment

begin_define
define|#
directive|define
name|GEN_EVENT_IOMB_INVALID_OBID
value|0x03
end_define

begin_comment
comment|/* INBOUND Inbound IOMB is received with an invalid OBID. */
end_comment

begin_define
define|#
directive|define
name|GEN_EVENT_DS_IN_NON_OPERATIONAL
value|0x39
end_define

begin_comment
comment|/* DEVICE_HANDLE_ACCEPT command failed due to the device being in DS_NON_OPERATIONAL state. */
end_comment

begin_define
define|#
directive|define
name|GEN_EVENT_DS_IN_RECOVERY
value|0x3A
end_define

begin_comment
comment|/* DEVICE_HANDLE_ACCEPT command failed due to device being in DS_IN_RECOVERY state. */
end_comment

begin_define
define|#
directive|define
name|GEN_EVENT_DS_INVALID
value|0x49
end_define

begin_comment
comment|/* DEVICE_HANDLE_ACCEPT command failed due to device being in DS_INVALID state. */
end_comment

begin_define
define|#
directive|define
name|GEN_EVENT_IO_XFER_READ_COMPL_ERR
value|0x50
end_define

begin_comment
comment|/* Indicates the PCIe Read Request to fetch one or more inbound IOMBs received                                                         a failed completion response. The first and second Dwords of the                                                         INBOUND IOMB field ( Dwords 2 and 3) contains information to identifying                                                         the location in the inbound queue where the error occurred.                                                         Dword 2 bits[15:0] contains the inbound queue number.                                                         Dword 2 bits[31:16] specifies how many consecutive IOMBs were affected                                                         by the failed DMA.                                                         Dword 3 specifies the Consumer Index [CI] of the inbound queue where                                                         the DMA operation failed.*/
end_comment

begin_comment
comment|/** \brief the data structure of SSP Request Received Notification  *  * use to describe MPI SSP Request Received Notification ( 1024 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPReqReceivedNotify_s
block|{
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|iniTagSSPIul
decl_stmt|;
name|bit32
name|frameTypeHssa
decl_stmt|;
name|bit32
name|TlrHdsa
decl_stmt|;
name|bit32
name|SSPIu
index|[
literal|251
index|]
decl_stmt|;
block|}
name|agsaSSPReqReceivedNotify_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SSPIUL_BITS
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|INITTAG_BITS
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|FRAME_TYPE
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|TLR_BITS
value|0x00000300
end_define

begin_comment
comment|/** \brief the data structure of Device Handle Arrived Notification  *  * use to describe MPI Device Handle Arrived Notification ( 64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDeviceHandleArrivedNotify_s
block|{
name|bit32
name|CTag
decl_stmt|;
name|bit32
name|HostAssignedIdFwdDeviceId
decl_stmt|;
name|bit32
name|ProtConrPortId
decl_stmt|;
name|bit8
name|sasAddrHi
index|[
literal|4
index|]
decl_stmt|;
name|bit8
name|sasAddrLow
index|[
literal|4
index|]
decl_stmt|;
name|bit32
name|reserved
index|[
literal|10
index|]
decl_stmt|;
block|}
name|agsaDeviceHandleArrivedNotify_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|Conrate_V_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|Conrate_V_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|Conrate_SPC_MASK
value|0x0000F000
end_define

begin_define
define|#
directive|define
name|Conrate_SPC_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|Protocol_SPC_MASK
value|0x00000700
end_define

begin_define
define|#
directive|define
name|Protocol_SPC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|Protocol_SPC_MASK
value|0x00000700
end_define

begin_define
define|#
directive|define
name|Protocol_SPC_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|PortId_V_MASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|PortId_SPC_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|PROTOCOL_BITS
value|0x00000700
end_define

begin_define
define|#
directive|define
name|PROTOCOL_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SHIFT_REG_64K_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|SHIFT_REG_BIT_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|SPC_GSM_SM_OFFSET
value|0x400000
end_define

begin_define
define|#
directive|define
name|SPCV_GSM_SM_OFFSET
value|0x0
end_define

begin_comment
comment|/** \brief the data structure of Get Time Stamp Response  *  * use to describe MPI Get TIme Stamp Response ( 64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetTimeStampRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|timeStampLower
decl_stmt|;
name|bit32
name|timeStampUpper
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaGetTimeStampRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SAS HW Event Ack Response  *  * use to describe SAS HW Event Ack Response ( 64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSASHwEventAckRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|reserved
index|[
literal|13
index|]
decl_stmt|;
block|}
name|agsaSASHwEventAckRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Port Control Response  *  * use to describe Port Control Response ( 64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPortControlRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|portOPPortId
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|rsvdPortState
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaPortControlRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SMP Abort Response  *  * use to describe SMP Abort Response ( 64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSMPAbortRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|scp
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaSMPAbortRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Get NVMD Data Response  *  * use to describe MPI Get NVMD Data Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetNVMDataRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|iRTdaBnDpsAsNvm
decl_stmt|;
name|bit32
name|DlenStatus
decl_stmt|;
name|bit32
name|NVMData
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaGetNVMDataRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Set NVMD Data Response  *  * use to describe MPI Set NVMD Data Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSetNVMDataRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|iPTdaBnDpsAsNvm
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaSetNVMDataRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Device Handle Removal  *  * use to describe MPI Device Handle Removel Notification (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDeviceHandleRemoval_s
block|{
name|bit32
name|portId
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|reserved
index|[
literal|13
index|]
decl_stmt|;
block|}
name|agsaDeviceHandleRemoval_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Set Device State Response  *  * use to describe MPI Set Device State Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSetDeviceStateRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|pds_nds
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaSetDeviceStateRsp_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NDS_BITS
value|0x0F
end_define

begin_define
define|#
directive|define
name|PDS_BITS
value|0xF0
end_define

begin_comment
comment|/** \brief the data structure of Get Device State Response  *  * use to describe MPI Get Device State Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetDeviceStateRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|ds
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaGetDeviceStateRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Set Device Info Response  *  * use to describe MPI Set Device Info Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSetDeviceInfoRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|deviceId
decl_stmt|;
name|bit32
name|SA_SR_SI
decl_stmt|;
name|bit32
name|A_R_ITNT
decl_stmt|;
name|bit32
name|reserved
index|[
literal|10
index|]
decl_stmt|;
block|}
name|agsaSetDeviceInfoRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SAS Re_Initialize Response  *  * use to describe MPI SAS RE_INITIALIZE Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSasReInitializeRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|setFlags
decl_stmt|;
name|bit32
name|MaxPorts
decl_stmt|;
name|bit32
name|openRejReCmdData
decl_stmt|;
name|bit32
name|sataHOLTMO
decl_stmt|;
name|bit32
name|reserved
index|[
literal|9
index|]
decl_stmt|;
block|}
name|agsaSasReInitializeRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SGPIO Response  *  * use to describe MPI serial GPIO Response IOMB (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSGpioRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|resultFunctionFrameType
decl_stmt|;
name|bit32
name|readData
index|[
name|OSSA_SGPIO_MAX_READ_DATA_COUNT
index|]
decl_stmt|;
block|}
name|agsaSGpioRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of PCIe diag response  *  * use to describe PCIe diag response IOMB (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaPCIeDiagExecuteRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|CmdTypeDesc
decl_stmt|;
comment|/* 2 */
name|bit32
name|Status
decl_stmt|;
comment|/* 3 */
name|bit32
name|reservedDW4
decl_stmt|;
comment|/* 4 */
name|bit32
name|reservedDW5
decl_stmt|;
comment|/* 5 */
name|bit32
name|ERR_BLKH
decl_stmt|;
comment|/* 6 */
name|bit32
name|ERR_BLKL
decl_stmt|;
comment|/* 7 */
name|bit32
name|DWord8
decl_stmt|;
comment|/* 8 */
name|bit32
name|DWord9
decl_stmt|;
comment|/* 9 */
name|bit32
name|DWord10
decl_stmt|;
comment|/* 10 */
name|bit32
name|DWord11
decl_stmt|;
comment|/* 11 */
name|bit32
name|DIF_ERR
decl_stmt|;
comment|/* 12 */
name|bit32
name|reservedDW13
decl_stmt|;
comment|/* 13 */
name|bit32
name|reservedDW14
decl_stmt|;
comment|/* 14 */
name|bit32
name|reservedDW15
decl_stmt|;
comment|/* 15 */
block|}
name|agsaPCIeDiagExecuteRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of PCI diag response  *  * use to describe PCI diag response IOMB  for SPC (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsa_SPC_PCIeDiagExecuteRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|CmdTypeDesc
decl_stmt|;
comment|/* 2 */
name|bit32
name|Status
decl_stmt|;
comment|/* 3 */
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
comment|/* 4 15 */
block|}
name|agsa_SPC_PCIeDiagExecuteRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of GET DFE Data Response  *  * use to describe GET DFE Data Response for SPCv (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetDDEFDataRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|status
decl_stmt|;
comment|/* 2 */
name|bit32
name|reserved_In_Ln
decl_stmt|;
comment|/* 3 */
name|bit32
name|MCNT
decl_stmt|;
comment|/* 4 */
name|bit32
name|NBT
decl_stmt|;
comment|/* 5 */
name|bit32
name|reserved
index|[
literal|10
index|]
decl_stmt|;
comment|/* 6 - 15 */
block|}
name|agsaGetDDEFDataRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of GET Vis Data Response  *  * use to describe GET Vis Data Response for SPCv (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetVHistCapRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|status
decl_stmt|;
comment|/* 2 */
name|bit32
name|channel
decl_stmt|;
comment|/* 3 */
name|bit32
name|BistLo
decl_stmt|;
comment|/* 4 */
name|bit32
name|BistHi
decl_stmt|;
comment|/* 5 */
name|bit32
name|BytesXfered
decl_stmt|;
comment|/* 6 */
name|bit32
name|PciLo
decl_stmt|;
comment|/* 7 */
name|bit32
name|PciHi
decl_stmt|;
comment|/* 8 */
name|bit32
name|PciBytecount
decl_stmt|;
comment|/* 9 */
name|bit32
name|reserved
index|[
literal|5
index|]
decl_stmt|;
comment|/* 10 - 15 */
block|}
name|agsaGetVHistCapRsp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaSetControllerConfigCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|pageCode
decl_stmt|;
name|bit32
name|configPage
index|[
literal|13
index|]
decl_stmt|;
comment|/* Page code specific fields */
block|}
name|agsaSetControllerConfigCmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaSetControllerConfigRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|errorQualifierPage
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaSetControllerConfigRsp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaGetControllerConfigCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|pageCode
decl_stmt|;
name|bit32
name|INT_VEC_MSK0
decl_stmt|;
name|bit32
name|INT_VEC_MSK1
decl_stmt|;
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
block|}
name|agsaGetControllerConfigCmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaGetControllerConfigRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|errorQualifier
decl_stmt|;
name|bit32
name|configPage
index|[
literal|12
index|]
decl_stmt|;
comment|/* Page code specific fields */
block|}
name|agsaGetControllerConfigRsp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaDekManagementCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|KEKIDX_Reserved_TBLS_DSOP
decl_stmt|;
name|bit32
name|dekIndex
decl_stmt|;
name|bit32
name|tableAddrLo
decl_stmt|;
name|bit32
name|tableAddrHi
decl_stmt|;
name|bit32
name|tableEntries
decl_stmt|;
name|bit32
name|Reserved_DBF_TBL_SIZE
decl_stmt|;
block|}
name|agsaDekManagementCmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaDekManagementRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|flags
decl_stmt|;
name|bit32
name|dekIndex
decl_stmt|;
name|bit32
name|errorQualifier
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaDekManagementRsp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaKekManagementCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|NEWKIDX_CURKIDX_KBF_Reserved_SKNV_KSOP
decl_stmt|;
name|bit32
name|reserved
decl_stmt|;
name|bit32
name|kekBlob
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaKekManagementCmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaKekManagementRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|flags
decl_stmt|;
name|bit32
name|errorQualifier
decl_stmt|;
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
block|}
name|agsaKekManagementRsp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaCoalSspComplCxt_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit16
name|SSPTag
decl_stmt|;
name|bit16
name|reserved
decl_stmt|;
block|}
name|agsaCoalSspComplCxt_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SSP Completion Response  *  * use to describe MPI SSP Completion Response (1024 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSSPCoalescedCompletionRsp_s
block|{
name|bit32
name|coalescedCount
decl_stmt|;
name|agsaCoalSspComplCxt_t
name|sspComplCxt
index|[
literal|1
index|]
decl_stmt|;
comment|/* Open ended array */
block|}
name|agsaSSPCoalescedCompletionRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of SATA Completion Response  *  * use to describe MPI SATA Completion Response (1024 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaCoalStpComplCxt_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit16
name|reserved
decl_stmt|;
block|}
name|agsaCoalStpComplCxt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|agsaSATACoalescedCompletionRsp_s
block|{
name|bit32
name|coalescedCount
decl_stmt|;
name|agsaCoalStpComplCxt_t
name|stpComplCxt
index|[
literal|1
index|]
decl_stmt|;
comment|/* Open ended array */
block|}
name|agsaSATACoalescedCompletionRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Operator Mangement Command  *  * use to describe OPR_MGMT  Command (128 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaOperatorMangmentCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|OPRIDX_AUTIDX_R_KBF_PKT_OMO
decl_stmt|;
comment|/* 2 */
name|bit8
name|IDString_Role
index|[
literal|32
index|]
decl_stmt|;
comment|/*  3 10 */
ifndef|#
directive|ifndef
name|HAILEAH_HOST_6G_COMPITIBILITY_FLAG
name|agsaEncryptKekBlob_t
name|Kblob
decl_stmt|;
comment|/* 11 22 */
endif|#
directive|endif
name|bit32
name|reserved
index|[
literal|8
index|]
decl_stmt|;
comment|/* 23 31 */
block|}
name|agsaOperatorMangmentCmd_t
typedef|;
end_typedef

begin_comment
comment|/*  *  * use to describe OPR_MGMT Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaOperatorMangmentRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|status
decl_stmt|;
comment|/* 2 */
name|bit32
name|OPRIDX_AUTIDX_R_OMO
decl_stmt|;
comment|/* 3 */
name|bit32
name|errorQualifier
decl_stmt|;
comment|/* 4 */
name|bit32
name|reserved
index|[
literal|10
index|]
decl_stmt|;
comment|/* 5 15 */
block|}
name|agsaOperatorMangmenRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Set Operator Command  *  * use to describe Set Operator  Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSetOperatorCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|OPRIDX_PIN_ACS
decl_stmt|;
comment|/* 2 */
name|bit32
name|cert
index|[
literal|10
index|]
decl_stmt|;
comment|/* 3 12 */
name|bit32
name|reserved
index|[
literal|3
index|]
decl_stmt|;
comment|/* 13 15 */
block|}
name|agsaSetOperatorCmd_t
typedef|;
end_typedef

begin_comment
comment|/*  *  * use to describe Set Operator Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaSetOperatorRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|status
decl_stmt|;
comment|/* 2 */
name|bit32
name|ERR_QLFR_OPRIDX_PIN_ACS
decl_stmt|;
comment|/* 3 */
name|bit32
name|reserved
index|[
literal|12
index|]
decl_stmt|;
comment|/* 4 15 */
block|}
name|agsaSetOperatorRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of Get Operator Command  *  * use to describe Get Operator Command (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetOperatorCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|option
decl_stmt|;
comment|/* 2 */
name|bit32
name|OprBufAddrLo
decl_stmt|;
comment|/* 3 */
name|bit32
name|OprBufAddrHi
decl_stmt|;
comment|/* 4*/
name|bit32
name|reserved
index|[
literal|11
index|]
decl_stmt|;
comment|/*5 15*/
block|}
name|agsaGetOperatorCmd_t
typedef|;
end_typedef

begin_comment
comment|/*  *  * use to describe Get Operator Response (64 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaGetOperatorRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|status
decl_stmt|;
comment|/* 2 */
name|bit32
name|Num_Option
decl_stmt|;
comment|/* 3 */
name|bit32
name|IDString
index|[
literal|8
index|]
decl_stmt|;
comment|/* 4 11*/
name|bit32
name|reserved
index|[
literal|4
index|]
decl_stmt|;
comment|/* 12 15*/
block|}
name|agsaGetOperatorRsp_t
typedef|;
end_typedef

begin_comment
comment|/*  *  * use to start Encryption BIST (128 bytes)  * 0x105  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptBist_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|r_subop
decl_stmt|;
comment|/* 2 */
name|bit32
name|testDiscption
index|[
literal|28
index|]
decl_stmt|;
comment|/* 3 31 */
block|}
name|agsaEncryptBist_t
typedef|;
end_typedef

begin_comment
comment|/*  *  * use to describe Encryption BIST Response (64 bytes)  * 0x905  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaEncryptBistRsp_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|status
decl_stmt|;
comment|/* 2 */
name|bit32
name|subop
decl_stmt|;
comment|/* 3 */
name|bit32
name|testResults
index|[
literal|11
index|]
decl_stmt|;
comment|/* 4 15 */
block|}
name|agsaEncryptBistRsp_t
typedef|;
end_typedef

begin_comment
comment|/** \brief the data structure of DifEncOffload Command  *  * use to describe Set DifEncOffload Command (128 bytes)  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDifEncOffloadCmd_s
block|{
name|bit32
name|tag
decl_stmt|;
comment|/* 1 */
name|bit32
name|option
decl_stmt|;
comment|/* 2 */
name|bit32
name|reserved
index|[
literal|2
index|]
decl_stmt|;
comment|/* 3-4 */
name|bit32
name|Src_Data_Len
decl_stmt|;
comment|/* 5 */
name|bit32
name|Dst_Data_Len
decl_stmt|;
comment|/* 6 */
name|bit32
name|flags
decl_stmt|;
comment|/* 7 */
name|bit32
name|UDTR01UDT01
decl_stmt|;
comment|/* 8 */
name|bit32
name|UDT2345
decl_stmt|;
comment|/* 9 */
name|bit32
name|UDTR2345
decl_stmt|;
comment|/* 10 */
name|bit32
name|DPLR0SecCnt_IOSeed
decl_stmt|;
comment|/* 11 */
name|bit32
name|DPL_Addr_Lo
decl_stmt|;
comment|/* 12 */
name|bit32
name|DPL_Addr_Hi
decl_stmt|;
comment|/* 13 */
name|bit32
name|KeyIndex_CMode_KTS_ENT_R
decl_stmt|;
comment|/* 14 */
name|bit32
name|EPLR0SecCnt_KS_ENSS
decl_stmt|;
comment|/* 15 */
name|bit32
name|keyTag_W0
decl_stmt|;
comment|/* 16 */
name|bit32
name|keyTag_W1
decl_stmt|;
comment|/* 17 */
name|bit32
name|tweakVal_W0
decl_stmt|;
comment|/* 18 */
name|bit32
name|tweakVal_W1
decl_stmt|;
comment|/* 19 */
name|bit32
name|tweakVal_W2
decl_stmt|;
comment|/* 20 */
name|bit32
name|tweakVal_W3
decl_stmt|;
comment|/* 21 */
name|bit32
name|EPL_Addr_Lo
decl_stmt|;
comment|/* 22 */
name|bit32
name|EPL_Addr_Hi
decl_stmt|;
comment|/* 23 */
name|agsaSgl_t
name|SrcSgl
decl_stmt|;
comment|/* 24-27 */
name|agsaSgl_t
name|DstSgl
decl_stmt|;
comment|/* 28-31 */
block|}
name|agsaDifEncOffloadCmd_t
typedef|;
end_typedef

begin_comment
comment|/*  *  * use to describe DIF/Encryption Offload Response (32 bytes)  * 0x910  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|agsaDifEncOffloadRspV_s
block|{
name|bit32
name|tag
decl_stmt|;
name|bit32
name|status
decl_stmt|;
name|bit32
name|ExpectedCRCUDT01
decl_stmt|;
name|bit32
name|ExpectedUDT2345
decl_stmt|;
name|bit32
name|ActualCRCUDT01
decl_stmt|;
name|bit32
name|ActualUDT2345
decl_stmt|;
name|bit32
name|DIFErr
decl_stmt|;
name|bit32
name|ErrBoffset
decl_stmt|;
block|}
name|agsaDifEncOffloadRspV_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__SAMPIDEFS_H__ */
end_comment

end_unit

