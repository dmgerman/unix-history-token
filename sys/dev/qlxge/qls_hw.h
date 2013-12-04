begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2013-2014 Qlogic Corporation  * All rights reserved.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE  *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  *  POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * File: qls_hw.h  * Author : David C Somayajulu, Qlogic Corporation, Aliso Viejo, CA 92656.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_QLS_HW_H_
end_ifndef

begin_define
define|#
directive|define
name|_QLS_HW_H_
end_define

begin_define
define|#
directive|define
name|Q8_MAX_NUM_MULTICAST_ADDRS
value|32
end_define

begin_define
define|#
directive|define
name|Q8_MAC_ADDR_LEN
value|6
end_define

begin_define
define|#
directive|define
name|BIT_0
value|(0x1<< 0)
end_define

begin_define
define|#
directive|define
name|BIT_1
value|(0x1<< 1)
end_define

begin_define
define|#
directive|define
name|BIT_2
value|(0x1<< 2)
end_define

begin_define
define|#
directive|define
name|BIT_3
value|(0x1<< 3)
end_define

begin_define
define|#
directive|define
name|BIT_4
value|(0x1<< 4)
end_define

begin_define
define|#
directive|define
name|BIT_5
value|(0x1<< 5)
end_define

begin_define
define|#
directive|define
name|BIT_6
value|(0x1<< 6)
end_define

begin_define
define|#
directive|define
name|BIT_7
value|(0x1<< 7)
end_define

begin_define
define|#
directive|define
name|BIT_8
value|(0x1<< 8)
end_define

begin_define
define|#
directive|define
name|BIT_9
value|(0x1<< 9)
end_define

begin_define
define|#
directive|define
name|BIT_10
value|(0x1<< 10)
end_define

begin_define
define|#
directive|define
name|BIT_11
value|(0x1<< 11)
end_define

begin_define
define|#
directive|define
name|BIT_12
value|(0x1<< 12)
end_define

begin_define
define|#
directive|define
name|BIT_13
value|(0x1<< 13)
end_define

begin_define
define|#
directive|define
name|BIT_14
value|(0x1<< 14)
end_define

begin_define
define|#
directive|define
name|BIT_15
value|(0x1<< 15)
end_define

begin_define
define|#
directive|define
name|BIT_16
value|(0x1<< 16)
end_define

begin_define
define|#
directive|define
name|BIT_17
value|(0x1<< 17)
end_define

begin_define
define|#
directive|define
name|BIT_18
value|(0x1<< 18)
end_define

begin_define
define|#
directive|define
name|BIT_19
value|(0x1<< 19)
end_define

begin_define
define|#
directive|define
name|BIT_20
value|(0x1<< 20)
end_define

begin_define
define|#
directive|define
name|BIT_21
value|(0x1<< 21)
end_define

begin_define
define|#
directive|define
name|BIT_22
value|(0x1<< 22)
end_define

begin_define
define|#
directive|define
name|BIT_23
value|(0x1<< 23)
end_define

begin_define
define|#
directive|define
name|BIT_24
value|(0x1<< 24)
end_define

begin_define
define|#
directive|define
name|BIT_25
value|(0x1<< 25)
end_define

begin_define
define|#
directive|define
name|BIT_11
value|(0x1<< 11)
end_define

begin_define
define|#
directive|define
name|BIT_12
value|(0x1<< 12)
end_define

begin_define
define|#
directive|define
name|BIT_13
value|(0x1<< 13)
end_define

begin_define
define|#
directive|define
name|BIT_14
value|(0x1<< 14)
end_define

begin_define
define|#
directive|define
name|BIT_15
value|(0x1<< 15)
end_define

begin_define
define|#
directive|define
name|BIT_16
value|(0x1<< 16)
end_define

begin_define
define|#
directive|define
name|BIT_17
value|(0x1<< 17)
end_define

begin_define
define|#
directive|define
name|BIT_18
value|(0x1<< 18)
end_define

begin_define
define|#
directive|define
name|BIT_19
value|(0x1<< 19)
end_define

begin_define
define|#
directive|define
name|BIT_20
value|(0x1<< 20)
end_define

begin_define
define|#
directive|define
name|BIT_21
value|(0x1<< 21)
end_define

begin_define
define|#
directive|define
name|BIT_22
value|(0x1<< 22)
end_define

begin_define
define|#
directive|define
name|BIT_23
value|(0x1<< 23)
end_define

begin_define
define|#
directive|define
name|BIT_24
value|(0x1<< 24)
end_define

begin_define
define|#
directive|define
name|BIT_25
value|(0x1<< 25)
end_define

begin_define
define|#
directive|define
name|BIT_26
value|(0x1<< 26)
end_define

begin_define
define|#
directive|define
name|BIT_27
value|(0x1<< 27)
end_define

begin_define
define|#
directive|define
name|BIT_28
value|(0x1<< 28)
end_define

begin_define
define|#
directive|define
name|BIT_29
value|(0x1<< 29)
end_define

begin_define
define|#
directive|define
name|BIT_30
value|(0x1<< 30)
end_define

begin_define
define|#
directive|define
name|BIT_31
value|(0x1<< 31)
end_define

begin_comment
comment|/*  * Firmware Interface  */
end_comment

begin_comment
comment|/*********************************************************************  * Work Queue Register Map  *********************************************************************/
end_comment

begin_define
define|#
directive|define
name|Q81_WRKQ_INDEX_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|Q81_WRKQ_CONS_INDEX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|Q81_WRKQ_PROD_INDEX_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|Q81_WRKQ_VALID_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|Q81_WRKQ_VALID_ONQ
value|BIT_25
end_define

begin_define
define|#
directive|define
name|Q81_WRKQ_VALID_V
value|BIT_4
end_define

begin_comment
comment|/*********************************************************************  * Completion Queue Register Map  *********************************************************************/
end_comment

begin_define
define|#
directive|define
name|Q81_COMPQ_INDEX_REG
value|0x00
end_define

begin_define
define|#
directive|define
name|Q81_COMPQ_PROD_INDEX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|Q81_COMPQ_CONS_INDEX_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|Q81_COMPQ_VALID_REG
value|0x04
end_define

begin_define
define|#
directive|define
name|Q81_COMPQ_VALID_V
value|BIT_4
end_define

begin_define
define|#
directive|define
name|Q81_LRGBQ_INDEX_REG
value|0x18
end_define

begin_define
define|#
directive|define
name|Q81_LRGBQ_CONS_INDEX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|Q81_LRGBQ_PROD_INDEX_MASK
value|0x0000FFFF
end_define

begin_define
define|#
directive|define
name|Q81_SMBQ_INDEX_REG
value|0x1C
end_define

begin_define
define|#
directive|define
name|Q81_SMBQ_CONS_INDEX_MASK
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|Q81_SMBQ_PROD_INDEX_MASK
value|0x0000FFFF
end_define

begin_comment
comment|/*********************************************************************  * Control Register Definitions  * (Access, Function Specific, Shared via Semaphore, Control by MPI FW)  *********************************************************************/
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_PROC_ADDR
value|0x00
end_define

begin_comment
comment|/* R/W  - Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_PROC_DATA
value|0x04
end_define

begin_comment
comment|/* R/W  - Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_SYSTEM
value|0x08
end_define

begin_comment
comment|/* MWR  - - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_RESET
value|0x0C
end_define

begin_comment
comment|/* MWR  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC
value|0x10
end_define

begin_comment
comment|/* MWR  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_HOST_CMD_STATUS
value|0x14
end_define

begin_comment
comment|/* R/W  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_LED
value|0x18
end_define

begin_comment
comment|/* R/W  Y - Y */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_ICB_ACCESS_ADDR_LO
value|0x20
end_define

begin_comment
comment|/* R/W  - Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_ICB_ACCESS_ADDR_HI
value|0x24
end_define

begin_comment
comment|/* R/W  - Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_CONFIG
value|0x28
end_define

begin_comment
comment|/* MWR  - - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_STATUS
value|0x30
end_define

begin_comment
comment|/* MWR  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTR_ENABLE
value|0x34
end_define

begin_comment
comment|/* MWR  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTR_MASK
value|0x38
end_define

begin_comment
comment|/* MWR  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTR_STATUS1
value|0x3C
end_define

begin_comment
comment|/* RO   Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTR_STATUS2
value|0x40
end_define

begin_comment
comment|/* RO   Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTR_STATUS3
value|0x44
end_define

begin_comment
comment|/* RO   Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTR_STATUS4
value|0x48
end_define

begin_comment
comment|/* RO   Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_REV_ID
value|0x4C
end_define

begin_comment
comment|/* RO   - - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_FATAL_ERR_STATUS
value|0x54
end_define

begin_comment
comment|/* RO   Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_COR_ECC_ERR_COUNTER
value|0x60
end_define

begin_comment
comment|/* RO   Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_SEMAPHORE
value|0x64
end_define

begin_comment
comment|/* MWR  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_GPIO1
value|0x68
end_define

begin_comment
comment|/* MWR  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_GPIO2
value|0x6C
end_define

begin_comment
comment|/* MWR  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_GPIO3
value|0x70
end_define

begin_comment
comment|/* MWR  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_XGMAC_ADDR
value|0x78
end_define

begin_comment
comment|/* R/W  Y Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_XGMAC_DATA
value|0x7C
end_define

begin_comment
comment|/* R/W  Y Y Y */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_NIC_ENH_TX_SCHD
value|0x80
end_define

begin_comment
comment|/* R/W  Y - Y */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_CNA_ENH_TX_SCHD
value|0x84
end_define

begin_comment
comment|/* R/W  Y - Y */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_FLASH_ADDR
value|0x88
end_define

begin_comment
comment|/* R/W  - Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_FLASH_DATA
value|0x8C
end_define

begin_comment
comment|/* R/W  - Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_STOP_CQ_PROCESSING
value|0x90
end_define

begin_comment
comment|/* MWR  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_ADDR_INDEX
value|0xA8
end_define

begin_comment
comment|/* R/W  - Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_ADDR_DATA
value|0xAC
end_define

begin_comment
comment|/* R/W  - Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_COS_DEF_CQ1
value|0xB0
end_define

begin_comment
comment|/* R/W  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_COS_DEF_CQ2
value|0xB4
end_define

begin_comment
comment|/* R/W  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_ETHERTYPE_SKIP_1
value|0xB8
end_define

begin_comment
comment|/* R/W  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_ETHERTYPE_SKIP_2
value|0xBC
end_define

begin_comment
comment|/* R/W  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_SPLIT_HDR
value|0xC0
end_define

begin_comment
comment|/* R/W  Y - - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_NIC_PAUSE_THRES
value|0xC8
end_define

begin_comment
comment|/* R/W  Y - Y */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCV_CONFIG
value|0xD4
end_define

begin_comment
comment|/* MWR  Y - Y */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_COS_TAGS_IN_NIC_FIFO
value|0xDC
end_define

begin_comment
comment|/* R/W  Y - Y */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_MGMT_RCV_CONFIG
value|0xE0
end_define

begin_comment
comment|/* MWR  Y - Y */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_ROUTING_INDEX
value|0xE4
end_define

begin_comment
comment|/* R/W  Y Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_ROUTING_DATA
value|0xE8
end_define

begin_comment
comment|/* R/W  Y Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_XG_SERDES_ADDR
value|0xF0
end_define

begin_comment
comment|/* R/W  Y Y Y */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_XG_SERDES_DATA
value|0xF4
end_define

begin_comment
comment|/* R/W  Y Y Y */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_XG_PROBE_MUX_ADDR
value|0xF8
end_define

begin_comment
comment|/* R/W  - Y - */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_XG_PROBE_MUX_DATA
value|0xFC
end_define

begin_comment
comment|/* R/W  - Y - */
end_comment

begin_comment
comment|/*  * Process Address Register (0x00)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_PROC_ADDR_RDY
value|BIT_31
end_define

begin_define
define|#
directive|define
name|Q81_CTL_PROC_ADDR_READ
value|BIT_30
end_define

begin_define
define|#
directive|define
name|Q81_CTL_PROC_ADDR_ERR
value|BIT_29
end_define

begin_define
define|#
directive|define
name|Q81_CTL_PROC_ADDR_MPI_RISC
value|(0x00<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_PROC_ADDR_MDE
value|(0x01<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_PROC_ADDR_REG_BLOCK
value|(0x02<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_PROC_ADDR_RISC_INT_REG
value|(0x03<< 16)
end_define

begin_comment
comment|/*  * System Register (0x08)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_SYSTEM_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SYSTEM_ENABLE_VQM_WR
value|BIT_5
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SYSTEM_ENABLE_DWC
value|BIT_4
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SYSTEM_ENABLE_DA_SINGLE_THRD
value|BIT_3
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SYSTEM_ENABLE_MDC
value|BIT_2
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SYSTEM_ENABLE_FAE
value|BIT_1
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SYSTEM_ENABLE_EFE
value|BIT_0
end_define

begin_comment
comment|/*  * Reset Register (0x0C)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_RESET_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RESET_FUNC
value|BIT_15
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RESET_RR_SHIFT
value|1
end_define

begin_comment
comment|/*  * Function Specific Control Register (0x10)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_FE
value|BIT_15
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_STE
value|BIT_13
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_DSB
value|BIT_12
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_SH
value|BIT_11
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_VM_PGSIZE_MASK
value|(0x7<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_VM_PGSIZE_2K
value|(0x1<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_VM_PGSIZE_4K
value|(0x2<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_VM_PGSIZE_8K
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_VM_PGSIZE_64K
value|(0x6<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_EPC_O
value|BIT_7
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_EPC_I
value|BIT_6
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_EC
value|BIT_5
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_DBL_DBRST
value|(0x00<< 3)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_DBL_MAX_PAYLDSZ
value|(0x01<< 3)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_DBL_MAX_RDBRSTSZ
value|(0x02<< 3)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_DBL_128
value|(0x03<< 3)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_DBRST_256
value|0x00
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_DBRST_512
value|0x01
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_DBRST_768
value|0x02
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FUNC_SPECIFIC_DBRST_1024
value|0x03
end_define

begin_comment
comment|/*  * Host Command/Status Register (0x14)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_NOP
value|(0x00<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_SET_RISC_RESET
value|(0x01<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_CLR_RISC_RESET
value|(0x02<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_SET_RISC_PAUSE
value|(0x03<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_CLR_RISC_PAUSE
value|(0x04<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_SET_HTR_INTR
value|(0x05<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_CLR_HTR_INTR
value|(0x06<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_SET_PARITY_EN
value|(0x07<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_FORCE_BAD_PARITY
value|(0x08<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_CLR_BAD_PARITY
value|(0x09<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_CLR_RTH_INTR
value|(0x0A<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_CMD_PAR_SHIFT
value|22
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_RISC_PAUSED
value|BIT_10
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_HTR_INTR
value|BIT_9
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_RISC_RESET
value|BIT_8
end_define

begin_define
define|#
directive|define
name|Q81_CTL_HCS_ERR_STATUS_MASK
value|0x3F
end_define

begin_comment
comment|/*  * Configuration Register (0x28)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_CONFIG_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_CONFIG_Q_NUM_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|Q81_CTL_CONFIG_Q_NUM_MASK
value|(0x7F<< Q81_CTL_CONFIG_Q_NUM_SHIFT)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_CONFIG_DCQ
value|BIT_7
end_define

begin_define
define|#
directive|define
name|Q81_CTL_CONFIG_LCQ
value|BIT_6
end_define

begin_define
define|#
directive|define
name|Q81_CTL_CONFIG_LE
value|BIT_5
end_define

begin_define
define|#
directive|define
name|Q81_CTL_CONFIG_DR
value|BIT_3
end_define

begin_define
define|#
directive|define
name|Q81_CTL_CONFIG_LR
value|BIT_2
end_define

begin_define
define|#
directive|define
name|Q81_CTL_CONFIG_DRQ
value|BIT_1
end_define

begin_define
define|#
directive|define
name|Q81_CTL_CONFIG_LRQ
value|BIT_0
end_define

begin_comment
comment|/*  * Status Register (0x30)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_NFE
value|BIT_12
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_F3E
value|BIT_11
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_F2E
value|BIT_10
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_F1E
value|BIT_9
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_F0E
value|BIT_8
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_FUNC_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_PI1
value|BIT_5
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_PI0
value|BIT_4
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_PL1
value|BIT_3
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_PL0
value|BIT_2
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_PI
value|BIT_1
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STATUS_FE
value|BIT_0
end_define

begin_comment
comment|/*  * Interrupt Enable Register (0x34)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTRE_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRE_EN
value|BIT_15
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRE_EI
value|BIT_14
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRE_IHD
value|BIT_13
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRE_RTYPE_MASK
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRE_RTYPE_ENABLE
value|(0x1<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRE_RTYPE_DISABLE
value|(0x2<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRE_RTYPE_SETUP_TO_RD
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRE_HOST_INTR_MASK
value|0x7F
end_define

begin_comment
comment|/*  * Interrupt Mask Register (0x38)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTRM_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRM_MC
value|BIT_7
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRM_LSC
value|BIT_6
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRM_LH1
value|BIT_4
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRM_HL1
value|BIT_3
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRM_LH0
value|BIT_2
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRM_HL0
value|BIT_1
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRM_PI
value|BIT_0
end_define

begin_comment
comment|/*  * Interrupt Status 1 Register (0x3C)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTRS1_COMPQ
parameter_list|(
name|i
parameter_list|)
value|(0x1<< i)
end_define

begin_comment
comment|/*  * Interrupt Status 2 Register (0x40)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTRS2_COMPQ
parameter_list|(
name|i
parameter_list|)
value|(0x1<< i)
end_define

begin_comment
comment|/*  * Interrupt Status 3 Register (0x44)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTRS3_COMPQ
parameter_list|(
name|i
parameter_list|)
value|(0x1<< i)
end_define

begin_comment
comment|/*  * Interrupt Status 4 Register (0x48)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_INTRS4_COMPQ
parameter_list|(
name|i
parameter_list|)
value|(0x1<< i)
end_define

begin_comment
comment|/*  * Revision ID Register (0x4C)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_REV_ID_CHIP_REV_MASK
value|(0xF<< 28)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_REV_ID_XGMAC_RCV_MASK
value|(0xF<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_REV_ID_XGMAC_ROLL_MASK
value|(0xF<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_REV_ID_NIC_REV_MASK
value|(0xF<< 4)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_REV_ID_NIC_ROLL_MASK
value|(0xF<< 0)
end_define

begin_comment
comment|/*  * Semaphore Register (0x64)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_SEM_MASK_PROC_ADDR_NIC_RCV
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_MASK_RIDX_DATAREG
value|0x30000000
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_MASK_FLASH
value|0x03000000
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_MASK_MAC_SERDES
value|0x00C00000
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_MASK_ICB
value|0x00300000
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_MASK_XGMAC1
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_MASK_XGMAC0
value|0x00030000
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_SET_PROC_ADDR_NIC_RCV
value|0x4000
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_SET_RIDX_DATAREG
value|0x1000
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_SET_FLASH
value|0x0100
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_SET_MAC_SERDES
value|0x0040
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_SET_ICB
value|0x0010
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_SET_XGMAC1
value|0x0004
end_define

begin_define
define|#
directive|define
name|Q81_CTL_SEM_SET_XGMAC0
value|0x0001
end_define

begin_comment
comment|/*  * Flash Address Register (0x88)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_FLASH_ADDR_RDY
value|BIT_31
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FLASH_ADDR_R
value|BIT_30
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FLASH_ADDR_ERR
value|BIT_29
end_define

begin_define
define|#
directive|define
name|Q81_CTL_FLASH_ADDR_MASK
value|0x7FFFFF
end_define

begin_comment
comment|/*  * Stop CQ Processing Register (0x90)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_STOP_CQ_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STOP_CQ_EN
value|BIT_15
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STOP_CQ_RQ_STARTQ
value|(0x1<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STOP_CQ_RQ_STOPQ
value|(0x2<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STOP_CQ_RQ_READ
value|(0x3<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_STOP_CQ_MASK
value|0x7F
end_define

begin_comment
comment|/*  * MAC Protocol Address Index Register (0xA8)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_MW
value|BIT_31
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_MR
value|BIT_30
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_E
value|BIT_27
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_RS
value|BIT_26
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_ADR
value|BIT_25
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_TYPE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_TYPE_MASK
value|0xF0000
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_IDX_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_IDX_MASK
value|0xFFF0
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_OFF_MASK
value|0xF
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_TYPE_CAM_MAC
value|(0<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_TYPE_MCAST
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_TYPE_VLAN
value|(2<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_TYPE_MCAST_FILTER
value|(3<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_TYPE_MGMT_MAC
value|(5<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_TYPE_MGMMT_VLAN
value|(6<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_TYPE_MGMT_IPV4
value|(7<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_TYPE_MGMT_IPV6
value|(8<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_MAC_PROTO_AI_TYPE_MGMT_PORT
value|(9<< 16)
end_define

begin_comment
comment|/* TCP/UDP Port */
end_comment

begin_comment
comment|/*  * CAM MAC offset 2 definitions  */
end_comment

begin_define
define|#
directive|define
name|Q81_CAM_MAC_OFF2_ROUTE_FC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|Q81_CAM_MAC_OFF2_ROUTE_NIC
value|0x00000001
end_define

begin_define
define|#
directive|define
name|Q81_CAM_MAC_OFF2_FUNC_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|Q81_CAM_MAC_OFF2_RV
value|0x00000010
end_define

begin_define
define|#
directive|define
name|Q81_CAM_MAC_OFF2_CQID_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|Q81_CAM_MAC_OFF2_SH
value|0x00008000
end_define

begin_define
define|#
directive|define
name|Q81_CAM_MAC_OFF2_MHT
value|0x40000000
end_define

begin_define
define|#
directive|define
name|Q81_CAM_MAC_OFF2_VLD
value|0x80000000
end_define

begin_comment
comment|/*  * NIC Pause Threshold Register (0xC8)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_NIC_PAUSE_THRES_PAUSE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_NIC_PAUSE_THRES_RESUME_SHIFT
value|0
end_define

begin_comment
comment|/*  * NIC Receive Configuration Register (0xD4)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCVC_MASK_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCVC_DCQ_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCVC_DCQ_MASK
value|0x7F00
end_define

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCVC_DTP
value|BIT_5
end_define

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCVC_R4T
value|BIT_4
end_define

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCVC_RV
value|BIT_3
end_define

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCVC_VLAN_ALL
value|(0x0<< 1)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCVC_VLAN_ONLY
value|(0x1<< 1)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCVC_VLAN_NON_VLAN
value|(0x2<< 1)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCVC_VLAN_REJECT
value|(0x3<< 1)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_NIC_RCVC_PPE
value|BIT_0
end_define

begin_comment
comment|/*  * Routing Index Register (0xE4)  */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_RI_MW
value|BIT_31
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_MR
value|BIT_30
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_E
value|BIT_27
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_RS
value|BIT_26
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_DST_RSS
value|(0x00<< 20)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_DST_CAMQ
value|(0x01<< 20)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_DST_COSQ
value|(0x02<< 20)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_DST_DFLTQ
value|(0x03<< 20)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_DST_DESTQ
value|(0x04<< 20)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_DST_DROP
value|(0x07<< 20)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_TYPE_RTMASK
value|(0x00<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_TYPE_RTINVMASK
value|(0x01<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_TYPE_NICQMASK
value|(0x02<< 16)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_TYPE_NICQINVMASK
value|(0x03<< 16)
end_define

begin_comment
comment|/* these indices for the Routing Index Register are user defined */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_ALL_ERROR
value|(0x00<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_MAC_ERROR
value|(0x00<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_IPCSUM_ERROR
value|(0x01<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_TCPCSUM_ERROR
value|(0x02<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_BCAST
value|(0x03<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_MCAST_MATCH
value|(0x04<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_ALLMULTI
value|(0x05<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_RSS_MATCH
value|(0x08<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_RSS_IPV4
value|(0x08<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_RSS_IPV6
value|(0x09<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_RSS_TCPV4
value|(0x0A<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_RSS_TCPV6
value|(0x0B<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_CAM_HIT
value|(0x0C<< 8)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RI_IDX_PROMISCUOUS
value|(0x0F<< 8)
end_define

begin_comment
comment|/* Routing Masks to be loaded into Routing Data Register */
end_comment

begin_define
define|#
directive|define
name|Q81_CTL_RD_BCAST
value|BIT_0
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_MCAST
value|BIT_1
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_MCAST_MATCH
value|BIT_2
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_MCAST_REG_MATCH
value|BIT_3
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_MCAST_HASH_MATCH
value|BIT_4
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_CAM_HIT
value|BIT_7
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_CAM_BIT0
value|BIT_8
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_CAM_BIT1
value|BIT_9
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_VLAN_TAG_PRESENT
value|BIT_10
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_VLAN_MATCH
value|BIT_11
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_VLAN_FILTER_PASS
value|BIT_12
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_SKIP_ETHERTYPE_1
value|BIT_13
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_SKIP_ETHERTYPE_2
value|BIT_14
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_BCAST_OR_MCAST_MATCH
value|BIT_15
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_802_3_PKT
value|BIT_16
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_LLDP_PKT
value|BIT_17
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_TUNNELED_PKT
value|BIT_18
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_ERROR_PKT
value|BIT_22
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_VALID_PKT
value|BIT_23
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_TCP_UDP_CSUM_ERR
value|BIT_24
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_IPCSUM_ERR
value|BIT_25
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_MAC_ERR
value|BIT_26
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_RSS_TCP_IPV6
value|BIT_27
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_RSS_TCP_IPV4
value|BIT_28
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_RSS_IPV6
value|BIT_29
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_RSS_IPV4
value|BIT_30
end_define

begin_define
define|#
directive|define
name|Q81_CTL_RD_RSS_MATCH
value|BIT_31
end_define

begin_comment
comment|/*********************************************************************  * Host Data Structures *  *********************************************************************/
end_comment

begin_comment
comment|/*  * Work Queue Initialization Control Block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q81_wq_icb
block|{
name|uint16_t
name|length_v
decl_stmt|;
define|#
directive|define
name|Q81_WQ_ICB_VALID
value|BIT_4
name|uint8_t
name|pri
decl_stmt|;
define|#
directive|define
name|Q81_WQ_ICB_PRI_SHIFT
value|1
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q81_WQ_ICB_FLAGS_LO
value|BIT_7
define|#
directive|define
name|Q81_WQ_ICB_FLAGS_LI
value|BIT_6
define|#
directive|define
name|Q81_WQ_ICB_FLAGS_LB
value|BIT_5
define|#
directive|define
name|Q81_WQ_ICB_FLAGS_LC
value|BIT_4
name|uint16_t
name|wqcqid_rss
decl_stmt|;
define|#
directive|define
name|Q81_WQ_ICB_RSS_V
value|BIT_15
name|uint16_t
name|rsrvd
decl_stmt|;
name|uint32_t
name|baddr_lo
decl_stmt|;
name|uint32_t
name|baddr_hi
decl_stmt|;
name|uint32_t
name|ci_addr_lo
decl_stmt|;
name|uint32_t
name|ci_addr_hi
decl_stmt|;
block|}
name|__packed
name|q81_wq_icb_t
typedef|;
end_typedef

begin_comment
comment|/*  * Completion Queue Initialization Control Block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q81_cq_icb
block|{
name|uint8_t
name|msix_vector
decl_stmt|;
name|uint16_t
name|rsrvd0
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q81_CQ_ICB_FLAGS_LC
value|BIT_7
define|#
directive|define
name|Q81_CQ_ICB_FLAGS_LI
value|BIT_6
define|#
directive|define
name|Q81_CQ_ICB_FLAGS_LL
value|BIT_5
define|#
directive|define
name|Q81_CQ_ICB_FLAGS_LS
value|BIT_4
define|#
directive|define
name|Q81_CQ_ICB_FLAGS_LV
value|BIT_3
name|uint16_t
name|length_v
decl_stmt|;
define|#
directive|define
name|Q81_CQ_ICB_VALID
value|BIT_4
name|uint16_t
name|rsrvd1
decl_stmt|;
name|uint32_t
name|cq_baddr_lo
decl_stmt|;
name|uint32_t
name|cq_baddr_hi
decl_stmt|;
name|uint32_t
name|cqi_addr_lo
decl_stmt|;
name|uint32_t
name|cqi_addr_hi
decl_stmt|;
name|uint16_t
name|pkt_idelay
decl_stmt|;
name|uint16_t
name|idelay
decl_stmt|;
name|uint32_t
name|lbq_baddr_lo
decl_stmt|;
name|uint32_t
name|lbq_baddr_hi
decl_stmt|;
name|uint16_t
name|lbq_bsize
decl_stmt|;
name|uint16_t
name|lbq_length
decl_stmt|;
name|uint32_t
name|sbq_baddr_lo
decl_stmt|;
name|uint32_t
name|sbq_baddr_hi
decl_stmt|;
name|uint16_t
name|sbq_bsize
decl_stmt|;
name|uint16_t
name|sbq_length
decl_stmt|;
block|}
name|__packed
name|q81_cq_icb_t
typedef|;
end_typedef

begin_comment
comment|/*  * RSS Initialization Control Block  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q81_rss_icb
block|{
name|uint16_t
name|flags_base_cq_num
decl_stmt|;
define|#
directive|define
name|Q81_RSS_ICB_FLAGS_L4K
value|BIT_7
define|#
directive|define
name|Q81_RSS_ICB_FLAGS_L6K
value|BIT_8
define|#
directive|define
name|Q81_RSS_ICB_FLAGS_LI
value|BIT_9
define|#
directive|define
name|Q81_RSS_ICB_FLAGS_LB
value|BIT_10
define|#
directive|define
name|Q81_RSS_ICB_FLAGS_LM
value|BIT_11
define|#
directive|define
name|Q81_RSS_ICB_FLAGS_RI4
value|BIT_12
define|#
directive|define
name|Q81_RSS_ICB_FLAGS_RT4
value|BIT_13
define|#
directive|define
name|Q81_RSS_ICB_FLAGS_RI6
value|BIT_14
define|#
directive|define
name|Q81_RSS_ICB_FLAGS_RT6
value|BIT_15
name|uint16_t
name|mask
decl_stmt|;
comment|/* bits 9-0 are valid */
define|#
directive|define
name|Q81_RSS_ICB_NUM_INDTBL_ENTRIES
value|1024
comment|/* Indirection Table */
name|uint8_t
name|cq_id
index|[
name|Q81_RSS_ICB_NUM_INDTBL_ENTRIES
index|]
decl_stmt|;
comment|/* Hash Keys */
name|uint32_t
name|ipv6_rss_hash_key
index|[
literal|10
index|]
decl_stmt|;
name|uint32_t
name|ipv4_rss_hash_key
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__packed
name|q81_rss_icb_t
typedef|;
end_typedef

begin_comment
comment|/*  * Transmit Buffer Descriptor  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q81_txb_desc
block|{
name|uint64_t
name|baddr
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q81_TXB_DESC_FLAGS_E
value|BIT_15
define|#
directive|define
name|Q81_TXB_DESC_FLAGS_C
value|BIT_14
block|}
name|__packed
name|q81_txb_desc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Receive Buffer Descriptor  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q81_rxb_desc
block|{
name|uint32_t
name|baddr_lo
decl_stmt|;
define|#
directive|define
name|Q81_RXB_DESC_BADDR_LO_S
value|BIT_1
name|uint64_t
name|baddr
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q81_RXB_DESC_FLAGS_E
value|BIT_15
define|#
directive|define
name|Q81_RXB_DESC_FLAGS_C
value|BIT_14
block|}
name|__packed
name|q81_rxb_desc_t
typedef|;
end_typedef

begin_comment
comment|/*  * IOCB Types  */
end_comment

begin_define
define|#
directive|define
name|Q81_IOCB_TX_MAC
value|0x01
end_define

begin_define
define|#
directive|define
name|Q81_IOCB_TX_TSO
value|0x02
end_define

begin_define
define|#
directive|define
name|Q81_IOCB_RX
value|0x20
end_define

begin_define
define|#
directive|define
name|Q81_IOCB_MPI
value|0x21
end_define

begin_define
define|#
directive|define
name|Q81_IOCB_SYS
value|0x3F
end_define

begin_comment
comment|/*  * IOCB Definitions  */
end_comment

begin_comment
comment|/*  * MAC Tx Frame IOCB  * Total Size of each IOCB Entry = 4 * 32 = 128 bytes  */
end_comment

begin_define
define|#
directive|define
name|MAX_TX_MAC_DESC
value|8
end_define

begin_typedef
typedef|typedef
struct|struct
name|_q81_tx_mac
block|{
name|uint8_t
name|opcode
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q81_TX_MAC_FLAGS_D
value|BIT_3
define|#
directive|define
name|Q81_TX_MAC_FLAGS_I
value|BIT_1
define|#
directive|define
name|Q81_TX_MAC_FLAGS_OI
value|BIT_0
name|uint8_t
name|vlan_off
decl_stmt|;
define|#
directive|define
name|Q81_TX_MAC_VLAN_OFF_SHIFT
value|3
define|#
directive|define
name|Q81_TX_MAC_VLAN_OFF_V
value|BIT_2
define|#
directive|define
name|Q81_TX_MAC_VLAN_OFF_DFP
value|BIT_1
name|uint32_t
name|rsrvd1
decl_stmt|;
name|uint32_t
name|rsrvd2
decl_stmt|;
name|uint16_t
name|frame_length
decl_stmt|;
comment|/* only bits0-13 are valid */
name|uint16_t
name|rsrvd3
decl_stmt|;
name|uint32_t
name|tid_lo
decl_stmt|;
name|uint32_t
name|tid_hi
decl_stmt|;
name|uint32_t
name|rsrvd4
decl_stmt|;
name|uint16_t
name|vlan_tci
decl_stmt|;
name|uint16_t
name|rsrvd5
decl_stmt|;
name|q81_txb_desc_t
name|txd
index|[
name|MAX_TX_MAC_DESC
index|]
decl_stmt|;
block|}
name|__packed
name|q81_tx_mac_t
typedef|;
end_typedef

begin_comment
comment|/*  * MAC Tx Frame with TSO IOCB  * Total Size of each IOCB Entry = 4 * 32 = 128 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q81_tx_tso
block|{
name|uint8_t
name|opcode
decl_stmt|;
name|uint16_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q81_TX_TSO_FLAGS_OI
value|BIT_0
define|#
directive|define
name|Q81_TX_TSO_FLAGS_I
value|BIT_1
define|#
directive|define
name|Q81_TX_TSO_FLAGS_D
value|BIT_3
define|#
directive|define
name|Q81_TX_TSO_FLAGS_IPV4
value|BIT_6
define|#
directive|define
name|Q81_TX_TSO_FLAGS_IPV6
value|BIT_7
define|#
directive|define
name|Q81_TX_TSO_FLAGS_LSO
value|BIT_13
define|#
directive|define
name|Q81_TX_TSO_FLAGS_UC
value|BIT_14
define|#
directive|define
name|Q81_TX_TSO_FLAGS_TC
value|BIT_15
name|uint8_t
name|vlan_off
decl_stmt|;
define|#
directive|define
name|Q81_TX_TSO_VLAN_OFF_SHIFT
value|3
define|#
directive|define
name|Q81_TX_TSO_VLAN_OFF_V
value|BIT_2
define|#
directive|define
name|Q81_TX_TSO_VLAN_OFF_DFP
value|BIT_1
define|#
directive|define
name|Q81_TX_TSO_VLAN_OFF_IC
value|BIT_0
name|uint32_t
name|rsrvd1
decl_stmt|;
name|uint32_t
name|rsrvd2
decl_stmt|;
name|uint32_t
name|length
decl_stmt|;
name|uint32_t
name|tid_lo
decl_stmt|;
name|uint32_t
name|tid_hi
decl_stmt|;
name|uint16_t
name|phdr_length
decl_stmt|;
name|uint16_t
name|phdr_offsets
decl_stmt|;
define|#
directive|define
name|Q81_TX_TSO_PHDR_SHIFT
value|6
name|uint16_t
name|vlan_tci
decl_stmt|;
name|uint16_t
name|mss
decl_stmt|;
name|q81_txb_desc_t
name|txd
index|[
name|MAX_TX_MAC_DESC
index|]
decl_stmt|;
block|}
name|__packed
name|q81_tx_tso_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q81_tx_cmd
block|{
name|uint8_t
name|bytes
index|[
literal|128
index|]
decl_stmt|;
block|}
name|__packed
name|q81_tx_cmd_t
typedef|;
end_typedef

begin_comment
comment|/*  * MAC TX Frame Completion  * Total Size of each IOCB Entry = 4 * 16 = 64 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q81_tx_mac_comp
block|{
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q81_TX_MAC_COMP_FLAGS_OI
value|BIT_0
define|#
directive|define
name|Q81_TX_MAC_COMP_FLAGS_I
value|BIT_1
define|#
directive|define
name|Q81_TX_MAC_COMP_FLAGS_E
value|BIT_3
define|#
directive|define
name|Q81_TX_MAC_COMP_FLAGS_S
value|BIT_4
define|#
directive|define
name|Q81_TX_MAC_COMP_FLAGS_L
value|BIT_5
define|#
directive|define
name|Q81_TX_MAC_COMP_FLAGS_P
value|BIT_6
name|uint8_t
name|rsrvd0
decl_stmt|;
name|uint8_t
name|err
decl_stmt|;
define|#
directive|define
name|Q81_TX_MAC_COMP_ERR_B
value|BIT_7
name|uint32_t
name|tid_lo
decl_stmt|;
name|uint32_t
name|tid_hi
decl_stmt|;
name|uint32_t
name|rsrvd1
index|[
literal|13
index|]
decl_stmt|;
block|}
name|__packed
name|q81_tx_mac_comp_t
typedef|;
end_typedef

begin_comment
comment|/*  * MAC TX Frame with LSO Completion  * Total Size of each IOCB Entry = 4 * 16 = 64 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q81_tx_tso_comp
block|{
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q81_TX_TSO_COMP_FLAGS_OI
value|BIT_0
define|#
directive|define
name|Q81_TX_TSO_COMP_FLAGS_I
value|BIT_1
define|#
directive|define
name|Q81_TX_TSO_COMP_FLAGS_E
value|BIT_3
define|#
directive|define
name|Q81_TX_TSO_COMP_FLAGS_S
value|BIT_4
define|#
directive|define
name|Q81_TX_TSO_COMP_FLAGS_P
value|BIT_6
name|uint8_t
name|rsrvd0
decl_stmt|;
name|uint8_t
name|err
decl_stmt|;
define|#
directive|define
name|Q81_TX_TSO_COMP_ERR_B
value|BIT_7
name|uint32_t
name|tid_lo
decl_stmt|;
name|uint32_t
name|tid_hi
decl_stmt|;
name|uint32_t
name|rsrvd1
index|[
literal|13
index|]
decl_stmt|;
block|}
name|__packed
name|q81_tx_tso_comp_t
typedef|;
end_typedef

begin_comment
comment|/*  * SYS - Chip Event Notification Completion  * Total Size of each IOCB Entry = 4 * 16 = 64 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q81_sys_comp
block|{
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|flags
decl_stmt|;
define|#
directive|define
name|Q81_SYS_COMP_FLAGS_OI
value|BIT_0
define|#
directive|define
name|Q81_SYS_COMP_FLAGS_I
value|BIT_1
name|uint8_t
name|etype
decl_stmt|;
define|#
directive|define
name|Q81_SYS_COMPE_LINK_UP
value|0x00
define|#
directive|define
name|Q81_SYS_COMPE_LINK_DOWN
value|0x01
define|#
directive|define
name|Q81_SYS_COMPE_MULTI_CAM_LOOKUP
value|0x06
define|#
directive|define
name|Q81_SYS_COMPE_SOFT_ECC
value|0x07
define|#
directive|define
name|Q81_SYS_COMPE_MPI_FATAL_ERROR
value|0x08
define|#
directive|define
name|Q81_SYS_COMPE_MAC_INTR
value|0x09
define|#
directive|define
name|Q81_SYS_COMPE_GPI0_HTOL
value|0x10
define|#
directive|define
name|Q81_SYS_COMPE_GPI0_LTOH
value|0x20
define|#
directive|define
name|Q81_SYS_COMPE_GPI1_HTOL
value|0x11
define|#
directive|define
name|Q81_SYS_COMPE_GPI1_LTOH
value|0x21
name|uint8_t
name|q_id
decl_stmt|;
comment|/* only bits 0-6 are valid */
name|uint32_t
name|rsrvd1
index|[
literal|15
index|]
decl_stmt|;
block|}
name|__packed
name|q81_sys_comp_t
typedef|;
end_typedef

begin_comment
comment|/*  * Mac Rx Packet Completion  * Total Size of each IOCB Entry = 4 * 16 = 64 bytes  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_q81_rx
block|{
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|flags0
decl_stmt|;
define|#
directive|define
name|Q81_RX_FLAGS0_OI
value|BIT_0
define|#
directive|define
name|Q81_RX_FLAGS0_I
value|BIT_1
define|#
directive|define
name|Q81_RX_FLAGS0_TE
value|BIT_2
define|#
directive|define
name|Q81_RX_FLAGS0_NU
value|BIT_3
define|#
directive|define
name|Q81_RX_FLAGS0_IE
value|BIT_4
define|#
directive|define
name|Q81_RX_FLAGS0_MCAST_MASK
value|(0x03<< 5)
define|#
directive|define
name|Q81_RX_FLAGS0_MCAST_NONE
value|(0x00<< 5)
define|#
directive|define
name|Q81_RX_FLAGS0_MCAST_HASH_MATCH
value|(0x01<< 5)
define|#
directive|define
name|Q81_RX_FLAGS0_MCAST_REG_MATCH
value|(0x02<< 5)
define|#
directive|define
name|Q81_RX_FLAGS0_MCAST_PROMISC
value|(0x03<< 5)
define|#
directive|define
name|Q81_RX_FLAGS0_B
value|BIT_7
name|uint16_t
name|flags1
decl_stmt|;
define|#
directive|define
name|Q81_RX_FLAGS1_P
value|BIT_0
define|#
directive|define
name|Q81_RX_FLAGS1_V
value|BIT_1
define|#
directive|define
name|Q81_RX_FLAGS1_ERR_NONE
value|(0x00<< 2)
define|#
directive|define
name|Q81_RX_FLAGS1_ERR_CODE
value|(0x01<< 2)
define|#
directive|define
name|Q81_RX_FLAGS1_ERR_OSIZE
value|(0x02<< 2)
define|#
directive|define
name|Q81_RX_FLAGS1_ERR_USIZE
value|(0x04<< 2)
define|#
directive|define
name|Q81_RX_FLAGS1_ERR_PREAMBLE
value|(0x05<< 2)
define|#
directive|define
name|Q81_RX_FLAGS1_ERR_FRAMELENGTH
value|(0x06<< 2)
define|#
directive|define
name|Q81_RX_FLAGS1_ERR_CRC
value|(0x07<< 2)
define|#
directive|define
name|Q81_RX_FLAGS1_ERR_MASK
value|(0x07<< 2)
define|#
directive|define
name|Q81_RX_FLAGS1_U
value|BIT_5
define|#
directive|define
name|Q81_RX_FLAGS1_T
value|BIT_6
define|#
directive|define
name|Q81_RX_FLAGS1_FO
value|BIT_7
define|#
directive|define
name|Q81_RX_FLAGS1_RSS_NO_MATCH
value|(0x00<< 8)
define|#
directive|define
name|Q81_RX_FLAGS1_RSS_IPV4_MATCH
value|(0x04<< 8)
define|#
directive|define
name|Q81_RX_FLAGS1_RSS_IPV6_MATCH
value|(0x02<< 8)
define|#
directive|define
name|Q81_RX_FLAGS1_RSS_TCPIPV4_MATCH
value|(0x05<< 8)
define|#
directive|define
name|Q81_RX_FLAGS1_RSS_TCPIPV4_MATCH
value|(0x05<< 8)
define|#
directive|define
name|Q81_RX_FLAGS1_RSS_MATCH_MASK
value|(0x07<< 8)
define|#
directive|define
name|Q81_RX_FLAGS1_V4
value|BIT_11
define|#
directive|define
name|Q81_RX_FLAGS1_V6
value|BIT_12
define|#
directive|define
name|Q81_RX_FLAGS1_IH
value|BIT_13
define|#
directive|define
name|Q81_RX_FLAGS1_DS
value|BIT_14
define|#
directive|define
name|Q81_RX_FLAGS1_DL
value|BIT_15
name|uint32_t
name|length
decl_stmt|;
name|uint64_t
name|b_paddr
decl_stmt|;
name|uint32_t
name|rss
decl_stmt|;
name|uint16_t
name|vlan_tag
decl_stmt|;
name|uint16_t
name|rsrvd
decl_stmt|;
name|uint32_t
name|rsrvd1
decl_stmt|;
name|uint32_t
name|flags2
decl_stmt|;
define|#
directive|define
name|Q81_RX_FLAGS2_HV
value|BIT_13
define|#
directive|define
name|Q81_RX_FLAGS2_HS
value|BIT_14
define|#
directive|define
name|Q81_RX_FLAGS2_HL
value|BIT_15
name|uint32_t
name|hdr_length
decl_stmt|;
name|uint32_t
name|hdr_baddr_lo
decl_stmt|;
name|uint32_t
name|hdr_baddr_hi
decl_stmt|;
block|}
name|__packed
name|q81_rx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q81_cq_e
block|{
name|uint8_t
name|opcode
decl_stmt|;
name|uint8_t
name|bytes
index|[
literal|63
index|]
decl_stmt|;
block|}
name|__packed
name|q81_cq_e_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_q81_bq_addr_e
block|{
name|uint32_t
name|addr_lo
decl_stmt|;
name|uint32_t
name|addr_hi
decl_stmt|;
block|}
name|__packed
name|q81_bq_addr_e_t
typedef|;
end_typedef

begin_comment
comment|/*  * Macros for reading and writing registers  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|Q8_MB
parameter_list|()
value|__asm volatile("mfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|Q8_WMB
parameter_list|()
value|__asm volatile("sfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|Q8_RMB
parameter_list|()
value|__asm volatile("lfence" ::: "memory")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|Q8_MB
parameter_list|()
end_define

begin_define
define|#
directive|define
name|Q8_WMB
parameter_list|()
end_define

begin_define
define|#
directive|define
name|Q8_RMB
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|READ_REG32
parameter_list|(
name|ha
parameter_list|,
name|reg
parameter_list|)
value|bus_read_4((ha->pci_reg), reg)
end_define

begin_define
define|#
directive|define
name|READ_REG64
parameter_list|(
name|ha
parameter_list|,
name|reg
parameter_list|)
value|bus_read_8((ha->pci_reg), reg)
end_define

begin_define
define|#
directive|define
name|WRITE_REG32_ONLY
parameter_list|(
name|ha
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_4((ha->pci_reg), reg, val)
end_define

begin_define
define|#
directive|define
name|WRITE_REG32
parameter_list|(
name|ha
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_write_4((ha->pci_reg), reg, val)
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRE_MASK_VALUE
define|\
value|(((Q81_CTL_INTRE_RTYPE_MASK | Q81_CTL_INTRE_HOST_INTR_MASK)<< \ 		Q81_CTL_INTRE_MASK_SHIFT) | Q81_CTL_INTRE_RTYPE_ENABLE)
end_define

begin_define
define|#
directive|define
name|Q81_ENABLE_INTR
parameter_list|(
name|ha
parameter_list|,
name|idx
parameter_list|)
define|\
value|WRITE_REG32(ha, Q81_CTL_INTR_ENABLE, (Q81_CTL_INTRE_MASK_VALUE | idx))
end_define

begin_define
define|#
directive|define
name|Q81_CTL_INTRD_MASK_VALUE
define|\
value|(((Q81_CTL_INTRE_RTYPE_MASK | Q81_CTL_INTRE_HOST_INTR_MASK)<< \ 		Q81_CTL_INTRE_MASK_SHIFT) | Q81_CTL_INTRE_RTYPE_DISABLE)
end_define

begin_define
define|#
directive|define
name|Q81_DISABLE_INTR
parameter_list|(
name|ha
parameter_list|,
name|idx
parameter_list|)
define|\
value|WRITE_REG32(ha, Q81_CTL_INTR_ENABLE, (Q81_CTL_INTRD_MASK_VALUE | idx))
end_define

begin_define
define|#
directive|define
name|Q81_WR_WQ_PROD_IDX
parameter_list|(
name|wq_idx
parameter_list|,
name|idx
parameter_list|)
value|bus_write_4((ha->pci_reg1),\ 		(ha->tx_ring[wq_idx].wq_db_offset + Q81_WRKQ_INDEX_REG), idx)
end_define

begin_define
define|#
directive|define
name|Q81_RD_WQ_IDX
parameter_list|(
name|wq_idx
parameter_list|)
value|bus_read_4((ha->pci_reg1),\ 		(ha->tx_ring[wq_idx].wq_db_offset + Q81_WRKQ_INDEX_REG))
end_define

begin_define
define|#
directive|define
name|Q81_SET_WQ_VALID
parameter_list|(
name|wq_idx
parameter_list|)
value|bus_write_4((ha->pci_reg1),\ 		(ha->tx_ring[wq_idx].wq_db_offset + Q81_WRKQ_VALID_REG),\ 			Q81_COMPQ_VALID_V)
end_define

begin_define
define|#
directive|define
name|Q81_SET_WQ_INVALID
parameter_list|(
name|wq_idx
parameter_list|)
value|bus_write_4((ha->pci_reg1),\ 		(ha->tx_ring[wq_idx].wq_db_offset + Q81_WRKQ_VALID_REG),\ 			(~Q81_COMPQ_VALID_V))
end_define

begin_define
define|#
directive|define
name|Q81_WR_CQ_CONS_IDX
parameter_list|(
name|cq_idx
parameter_list|,
name|idx
parameter_list|)
value|bus_write_4((ha->pci_reg1),\ 		(ha->rx_ring[cq_idx].cq_db_offset + Q81_COMPQ_INDEX_REG), idx)
end_define

begin_define
define|#
directive|define
name|Q81_RD_CQ_IDX
parameter_list|(
name|cq_idx
parameter_list|)
value|bus_read_4((ha->pci_reg1),\ 		(ha->rx_ring[cq_idx].cq_db_offset + Q81_COMPQ_INDEX_REG))
end_define

begin_define
define|#
directive|define
name|Q81_SET_CQ_VALID
parameter_list|(
name|cq_idx
parameter_list|)
value|bus_write_4((ha->pci_reg1),\ 		(ha->rx_ring[cq_idx].cq_db_offset + Q81_COMPQ_VALID_REG),\ 			Q81_COMPQ_VALID_V)
end_define

begin_define
define|#
directive|define
name|Q81_SET_CQ_INVALID
parameter_list|(
name|cq_idx
parameter_list|)
value|bus_write_4((ha->pci_reg1),\ 		(ha->rx_ring[cq_idx].cq_db_offset + Q81_COMPQ_VALID_REG),\ 			~Q81_COMPQ_VALID_V)
end_define

begin_define
define|#
directive|define
name|Q81_WR_LBQ_PROD_IDX
parameter_list|(
name|cq_idx
parameter_list|,
name|idx
parameter_list|)
value|bus_write_4((ha->pci_reg1),\ 		(ha->rx_ring[cq_idx].cq_db_offset + Q81_LRGBQ_INDEX_REG), idx)
end_define

begin_define
define|#
directive|define
name|Q81_RD_LBQ_IDX
parameter_list|(
name|cq_idx
parameter_list|)
value|bus_read_4((ha->pci_reg1),\ 		(ha->rx_ring[cq_idx].cq_db_offset + Q81_LRGBQ_INDEX_REG))
end_define

begin_define
define|#
directive|define
name|Q81_WR_SBQ_PROD_IDX
parameter_list|(
name|cq_idx
parameter_list|,
name|idx
parameter_list|)
value|bus_write_4((ha->pci_reg1),\ 		(ha->rx_ring[cq_idx].cq_db_offset + Q81_SMBQ_INDEX_REG), idx)
end_define

begin_define
define|#
directive|define
name|Q81_RD_SBQ_IDX
parameter_list|(
name|cq_idx
parameter_list|)
value|bus_read_4((ha->pci_reg1),\ 		(ha->rx_ring[cq_idx].cq_db_offset + Q81_SMBQ_INDEX_REG))
end_define

begin_comment
comment|/*  * Flash Related  */
end_comment

begin_define
define|#
directive|define
name|Q81_F0_FLASH_OFFSET
value|0x140200
end_define

begin_define
define|#
directive|define
name|Q81_F1_FLASH_OFFSET
value|0x140600
end_define

begin_define
define|#
directive|define
name|Q81_FLASH_ID
value|"8000"
end_define

begin_typedef
typedef|typedef
struct|struct
name|_q81_flash
block|{
name|uint8_t
name|id
index|[
literal|4
index|]
decl_stmt|;
comment|/* equal to "8000" */
name|uint16_t
name|version
decl_stmt|;
name|uint16_t
name|size
decl_stmt|;
name|uint16_t
name|csum
decl_stmt|;
name|uint16_t
name|rsrvd0
decl_stmt|;
name|uint16_t
name|total_size
decl_stmt|;
name|uint16_t
name|nentries
decl_stmt|;
name|uint8_t
name|dtype0
decl_stmt|;
name|uint8_t
name|dsize0
decl_stmt|;
name|uint8_t
name|mac_addr0
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|dtype1
decl_stmt|;
name|uint8_t
name|dsize1
decl_stmt|;
name|uint8_t
name|mac_addr1
index|[
literal|6
index|]
decl_stmt|;
name|uint8_t
name|dtype2
decl_stmt|;
name|uint8_t
name|dsize2
decl_stmt|;
name|uint16_t
name|vlan_id
decl_stmt|;
name|uint8_t
name|dtype3
decl_stmt|;
name|uint8_t
name|dsize3
decl_stmt|;
name|uint16_t
name|last
decl_stmt|;
name|uint8_t
name|rsrvd1
index|[
literal|464
index|]
decl_stmt|;
name|uint16_t
name|subsys_vid
decl_stmt|;
name|uint16_t
name|subsys_did
decl_stmt|;
name|uint8_t
name|rsrvd2
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__packed
name|q81_flash_t
typedef|;
end_typedef

begin_comment
comment|/*  * MPI Related   */
end_comment

begin_define
define|#
directive|define
name|Q81_NUM_MBX_REGISTERS
value|16
end_define

begin_define
define|#
directive|define
name|Q81_NUM_AEN_REGISTERS
value|9
end_define

begin_define
define|#
directive|define
name|Q81_FUNC0_MBX_IN_REG0
value|0x1180
end_define

begin_define
define|#
directive|define
name|Q81_FUNC0_MBX_OUT_REG0
value|0x1190
end_define

begin_define
define|#
directive|define
name|Q81_FUNC1_MBX_IN_REG0
value|0x1280
end_define

begin_define
define|#
directive|define
name|Q81_FUNC1_MBX_OUT_REG0
value|0x1290
end_define

begin_define
define|#
directive|define
name|Q81_MBX_NOP
value|0x0000
end_define

begin_define
define|#
directive|define
name|Q81_MBX_EXEC_FW
value|0x0002
end_define

begin_define
define|#
directive|define
name|Q81_MBX_REG_TEST
value|0x0006
end_define

begin_define
define|#
directive|define
name|Q81_MBX_VERIFY_CHKSUM
value|0x0007
end_define

begin_define
define|#
directive|define
name|Q81_MBX_ABOUT_FW
value|0x0008
end_define

begin_define
define|#
directive|define
name|Q81_MBX_RISC_MEMCPY
value|0x000A
end_define

begin_define
define|#
directive|define
name|Q81_MBX_LOAD_RISC_RAM
value|0x000B
end_define

begin_define
define|#
directive|define
name|Q81_MBX_DUMP_RISC_RAM
value|0x000C
end_define

begin_define
define|#
directive|define
name|Q81_MBX_WR_RAM_WORD
value|0x000D
end_define

begin_define
define|#
directive|define
name|Q81_MBX_INIT_RISC_RAM
value|0x000E
end_define

begin_define
define|#
directive|define
name|Q81_MBX_RD_RAM_WORD
value|0x000F
end_define

begin_define
define|#
directive|define
name|Q81_MBX_STOP_FW
value|0x0014
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GEN_SYS_ERR
value|0x002A
end_define

begin_define
define|#
directive|define
name|Q81_MBX_WR_SFP_PLUS
value|0x0030
end_define

begin_define
define|#
directive|define
name|Q81_MBX_RD_SFP_PLUS
value|0x0031
end_define

begin_define
define|#
directive|define
name|Q81_MBX_INIT_FW
value|0x0060
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GET_IFCB
value|0x0061
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GET_FW_STATE
value|0x0069
end_define

begin_define
define|#
directive|define
name|Q81_MBX_IDC_REQ
value|0x0100
end_define

begin_define
define|#
directive|define
name|Q81_MBX_IDC_ACK
value|0x0101
end_define

begin_define
define|#
directive|define
name|Q81_MBX_IDC_TIME_EXTEND
value|0x0102
end_define

begin_define
define|#
directive|define
name|Q81_MBX_WOL_MODE
value|0x0110
end_define

begin_define
define|#
directive|define
name|Q81_MBX_SET_WOL_FILTER
value|0x0111
end_define

begin_define
define|#
directive|define
name|Q81_MBX_CLR_WOL_FILTER
value|0x0112
end_define

begin_define
define|#
directive|define
name|Q81_MBX_SET_WOL_MAGIC
value|0x0113
end_define

begin_define
define|#
directive|define
name|Q81_MBX_WOL_MODE_IMM
value|0x0115
end_define

begin_define
define|#
directive|define
name|Q81_MBX_PORT_RESET
value|0x0120
end_define

begin_define
define|#
directive|define
name|Q81_MBX_SET_PORT_CFG
value|0x0122
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GET_PORT_CFG
value|0x0123
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GET_LNK_STATUS
value|0x0124
end_define

begin_define
define|#
directive|define
name|Q81_MBX_SET_LED_CFG
value|0x0125
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GET_LED_CFG
value|0x0126
end_define

begin_define
define|#
directive|define
name|Q81_MBX_SET_DCBX_CTLB
value|0x0130
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GET_DCBX_CTLB
value|0x0131
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GET_DCBX_TLV
value|0x0132
end_define

begin_define
define|#
directive|define
name|Q81_MBX_DIAG_CMDS
value|0x0150
end_define

begin_define
define|#
directive|define
name|Q81_MBX_SET_MGMT_CTL
value|0x0160
end_define

begin_define
define|#
directive|define
name|Q81_MBX_SET_MGMT_CTL_STOP
value|0x01
end_define

begin_define
define|#
directive|define
name|Q81_MBX_SET_MGMT_CTL_RESUME
value|0x02
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GET_MGMT_CTL
value|0x0161
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GET_MGMT_CTL_MASK
value|~0x3
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GET_MGMT_CTL_FIFO_EMPTY
value|0x02
end_define

begin_define
define|#
directive|define
name|Q81_MBX_GET_MGMT_CTL_SET_MGMT
value|0x01
end_define

begin_define
define|#
directive|define
name|Q81_MBX_CMD_COMPLETE
value|0x4000
end_define

begin_define
define|#
directive|define
name|Q81_MBX_CMD_INVALID
value|0x4001
end_define

begin_define
define|#
directive|define
name|Q81_MBX_CMD_TEST_FAILED
value|0x4003
end_define

begin_define
define|#
directive|define
name|Q81_MBX_CMD_ERROR
value|0x4005
end_define

begin_define
define|#
directive|define
name|Q81_MBX_CMD_PARAM_ERROR
value|0x4006
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _QLS_HW_H_ */
end_comment

end_unit

