begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008-2013 Freescale Semiconductor Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are met:  *     * Redistributions of source code must retain the above copyright  *       notice, this list of conditions and the following disclaimer.  *     * Redistributions in binary form must reproduce the above copyright  *       notice, this list of conditions and the following disclaimer in the  *       documentation and/or other materials provided with the distribution.  *     * Neither the name of Freescale Semiconductor nor the  *       names of its contributors may be used to endorse or promote products  *       derived from this software without specific prior written permission.  *  *  * ALTERNATIVELY, this software may be distributed under the terms of the  * GNU General Public License ("GPL") as published by the Free Software  * Foundation, either version 2 of that License or (at your option) any  * later version.  *  * THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/******************************************************************************  @File          dtsec.h   @Description   FM dTSEC ... */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DTSEC_H
end_ifndef

begin_define
define|#
directive|define
name|__DTSEC_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"error_ext.h"
end_include

begin_include
include|#
directive|include
file|"list_ext.h"
end_include

begin_include
include|#
directive|include
file|"enet_ext.h"
end_include

begin_include
include|#
directive|include
file|"dtsec_mii_acc.h"
end_include

begin_include
include|#
directive|include
file|"fm_mac.h"
end_include

begin_define
define|#
directive|define
name|DEFAULT_exceptions
define|\
value|((uint32_t)(DTSEC_IMASK_BREN    | \                 DTSEC_IMASK_RXCEN   | \                 DTSEC_IMASK_BTEN    | \                 DTSEC_IMASK_TXCEN   | \                 DTSEC_IMASK_TXEEN   | \                 DTSEC_IMASK_ABRTEN  | \                 DTSEC_IMASK_LCEN    | \                 DTSEC_IMASK_CRLEN   | \                 DTSEC_IMASK_XFUNEN  | \                 DTSEC_IMASK_IFERREN | \                 DTSEC_IMASK_MAGEN   | \                 DTSEC_IMASK_TDPEEN  | \                 DTSEC_IMASK_RDPEEN))
end_define

begin_define
define|#
directive|define
name|GET_EXCEPTION_FLAG
parameter_list|(
name|bitMask
parameter_list|,
name|exception
parameter_list|)
value|switch (exception){ \     case e_FM_MAC_EX_1G_BAB_RX:                                     \         bitMask = DTSEC_IMASK_BREN; break;                          \     case e_FM_MAC_EX_1G_RX_CTL:                                     \         bitMask = DTSEC_IMASK_RXCEN; break;                         \     case e_FM_MAC_EX_1G_GRATEFUL_TX_STP_COMPLET:                    \         bitMask = DTSEC_IMASK_GTSCEN ; break;                       \     case e_FM_MAC_EX_1G_BAB_TX:                                     \         bitMask = DTSEC_IMASK_BTEN   ; break;                       \     case e_FM_MAC_EX_1G_TX_CTL:                                     \         bitMask = DTSEC_IMASK_TXCEN  ; break;                       \     case e_FM_MAC_EX_1G_TX_ERR:                                     \         bitMask = DTSEC_IMASK_TXEEN  ; break;                       \     case e_FM_MAC_EX_1G_LATE_COL:                                   \         bitMask = DTSEC_IMASK_LCEN   ; break;                       \     case e_FM_MAC_EX_1G_COL_RET_LMT:                                \         bitMask = DTSEC_IMASK_CRLEN  ; break;                       \     case e_FM_MAC_EX_1G_TX_FIFO_UNDRN:                              \         bitMask = DTSEC_IMASK_XFUNEN ; break;                       \     case e_FM_MAC_EX_1G_MAG_PCKT:                                   \         bitMask = DTSEC_IMASK_MAGEN ; break;                        \     case e_FM_MAC_EX_1G_MII_MNG_RD_COMPLET:                         \         bitMask = DTSEC_IMASK_MMRDEN; break;                        \     case e_FM_MAC_EX_1G_MII_MNG_WR_COMPLET:                         \         bitMask = DTSEC_IMASK_MMWREN  ; break;                      \     case e_FM_MAC_EX_1G_GRATEFUL_RX_STP_COMPLET:                    \         bitMask = DTSEC_IMASK_GRSCEN; break;                        \     case e_FM_MAC_EX_1G_TX_DATA_ERR:                                \         bitMask = DTSEC_IMASK_TDPEEN; break;                        \     case e_FM_MAC_EX_1G_RX_MIB_CNT_OVFL:                            \         bitMask = DTSEC_IMASK_MSROEN ; break;                       \     default: bitMask = 0;break;}
end_define

begin_define
define|#
directive|define
name|MAX_PACKET_ALIGNMENT
value|31
end_define

begin_define
define|#
directive|define
name|MAX_INTER_PACKET_GAP
value|0x7f
end_define

begin_define
define|#
directive|define
name|MAX_INTER_PALTERNATE_BEB
value|0x0f
end_define

begin_define
define|#
directive|define
name|MAX_RETRANSMISSION
value|0x0f
end_define

begin_define
define|#
directive|define
name|MAX_COLLISION_WINDOW
value|0x03ff
end_define

begin_comment
comment|/********************* From mac ext ******************************************/
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|t_ErrorDisable
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ERROR_DISABLE_TRANSMIT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_LATE_COLLISION
value|0x00040000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_COLLISION_RETRY_LIMIT
value|0x00020000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_TxFIFO_UNDERRUN
value|0x00010000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_TxABORT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_INTERFACE
value|0x00004000
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_TxDATA_PARITY
value|0x00000002
end_define

begin_define
define|#
directive|define
name|ERROR_DISABLE_RxDATA_PARITY
value|0x00000001
end_define

begin_comment
comment|/*****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DTSEC_NUM_OF_PADDRS
value|15
end_define

begin_comment
comment|/* number of pattern match registers (entries) */
end_comment

begin_define
define|#
directive|define
name|GROUP_ADDRESS
value|0x0000010000000000LL
end_define

begin_comment
comment|/* Group address bit indication */
end_comment

begin_define
define|#
directive|define
name|HASH_TABLE_SIZE
value|256
end_define

begin_comment
comment|/* Hash table size (= 32 bits * 8 regs) */
end_comment

begin_define
define|#
directive|define
name|HASH_TABLE_SIZE
value|256
end_define

begin_comment
comment|/* Hash table size (32 bits * 8 regs) */
end_comment

begin_define
define|#
directive|define
name|EXTENDED_HASH_TABLE_SIZE
value|512
end_define

begin_comment
comment|/* Extended Hash table size (32 bits * 16 regs) */
end_comment

begin_define
define|#
directive|define
name|DTSEC_TO_MII_OFFSET
value|0x1000
end_define

begin_comment
comment|/* number of pattern match registers (entries) */
end_comment

begin_define
define|#
directive|define
name|MAX_PHYS
value|32
end_define

begin_comment
comment|/* maximum number of phys */
end_comment

begin_define
define|#
directive|define
name|VAL32BIT
value|0x100000000LL
end_define

begin_define
define|#
directive|define
name|VAL22BIT
value|0x00400000
end_define

begin_define
define|#
directive|define
name|VAL16BIT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|VAL12BIT
value|0x00001000
end_define

begin_comment
comment|/* CAR1/2 bits */
end_comment

begin_define
define|#
directive|define
name|CAR1_TR64
value|0x80000000
end_define

begin_define
define|#
directive|define
name|CAR1_TR127
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CAR1_TR255
value|0x20000000
end_define

begin_define
define|#
directive|define
name|CAR1_TR511
value|0x10000000
end_define

begin_define
define|#
directive|define
name|CAR1_TRK1
value|0x08000000
end_define

begin_define
define|#
directive|define
name|CAR1_TRMAX
value|0x04000000
end_define

begin_define
define|#
directive|define
name|CAR1_TRMGV
value|0x02000000
end_define

begin_define
define|#
directive|define
name|CAR1_RBYT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|CAR1_RPKT
value|0x00008000
end_define

begin_define
define|#
directive|define
name|CAR1_RMCA
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CAR1_RBCA
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CAR1_RXPF
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CAR1_RALN
value|0x00000100
end_define

begin_define
define|#
directive|define
name|CAR1_RFLR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|CAR1_RCDE
value|0x00000040
end_define

begin_define
define|#
directive|define
name|CAR1_RCSE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CAR1_RUND
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CAR1_ROVR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CAR1_RFRG
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CAR1_RJBR
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CAR1_RDRP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CAR2_TFCS
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CAR2_TBYT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|CAR2_TPKT
value|0x00001000
end_define

begin_define
define|#
directive|define
name|CAR2_TMCA
value|0x00000800
end_define

begin_define
define|#
directive|define
name|CAR2_TBCA
value|0x00000400
end_define

begin_define
define|#
directive|define
name|CAR2_TXPF
value|0x00000200
end_define

begin_define
define|#
directive|define
name|CAR2_TDRP
value|0x00000001
end_define

begin_typedef
typedef|typedef
struct|struct
name|t_InternalStatistics
block|{
name|uint64_t
name|tr64
decl_stmt|;
name|uint64_t
name|tr127
decl_stmt|;
name|uint64_t
name|tr255
decl_stmt|;
name|uint64_t
name|tr511
decl_stmt|;
name|uint64_t
name|tr1k
decl_stmt|;
name|uint64_t
name|trmax
decl_stmt|;
name|uint64_t
name|trmgv
decl_stmt|;
name|uint64_t
name|rfrg
decl_stmt|;
name|uint64_t
name|rjbr
decl_stmt|;
name|uint64_t
name|rdrp
decl_stmt|;
name|uint64_t
name|raln
decl_stmt|;
name|uint64_t
name|rund
decl_stmt|;
name|uint64_t
name|rovr
decl_stmt|;
name|uint64_t
name|rxpf
decl_stmt|;
name|uint64_t
name|txpf
decl_stmt|;
name|uint64_t
name|rbyt
decl_stmt|;
name|uint64_t
name|rpkt
decl_stmt|;
name|uint64_t
name|rmca
decl_stmt|;
name|uint64_t
name|rbca
decl_stmt|;
name|uint64_t
name|rflr
decl_stmt|;
name|uint64_t
name|rcde
decl_stmt|;
name|uint64_t
name|rcse
decl_stmt|;
name|uint64_t
name|tbyt
decl_stmt|;
name|uint64_t
name|tpkt
decl_stmt|;
name|uint64_t
name|tmca
decl_stmt|;
name|uint64_t
name|tbca
decl_stmt|;
name|uint64_t
name|tdrp
decl_stmt|;
name|uint64_t
name|tfcs
decl_stmt|;
block|}
name|t_InternalStatistics
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|t_FmMacControllerDriver
name|fmMacControllerDriver
decl_stmt|;
name|t_Handle
name|h_App
decl_stmt|;
comment|/**< Handle to the upper layer application              */
name|struct
name|dtsec_regs
modifier|*
name|p_MemMap
decl_stmt|;
comment|/**< pointer to dTSEC memory mapped registers.          */
name|struct
name|dtsec_mii_reg
modifier|*
name|p_MiiMemMap
decl_stmt|;
comment|/**< pointer to dTSEC MII memory mapped registers.          */
name|uint64_t
name|addr
decl_stmt|;
comment|/**< MAC address of device;                             */
name|e_EnetMode
name|enetMode
decl_stmt|;
comment|/**< Ethernet physical interface  */
name|t_FmMacExceptionCallback
modifier|*
name|f_Exception
decl_stmt|;
name|int
name|mdioIrq
decl_stmt|;
name|t_FmMacExceptionCallback
modifier|*
name|f_Event
decl_stmt|;
name|bool
name|indAddrRegUsed
index|[
name|DTSEC_NUM_OF_PADDRS
index|]
decl_stmt|;
comment|/**< Whether a particular individual address recognition register is being used */
name|uint64_t
name|paddr
index|[
name|DTSEC_NUM_OF_PADDRS
index|]
decl_stmt|;
comment|/**< MAC address for particular individual address recognition register */
name|uint8_t
name|numOfIndAddrInRegs
decl_stmt|;
comment|/**< Number of individual addresses in registers for this station. */
name|bool
name|halfDuplex
decl_stmt|;
name|t_InternalStatistics
name|internalStatistics
decl_stmt|;
name|t_EthHash
modifier|*
name|p_MulticastAddrHash
decl_stmt|;
comment|/* pointer to driver's global address hash table  */
name|t_EthHash
modifier|*
name|p_UnicastAddrHash
decl_stmt|;
comment|/* pointer to driver's individual address hash table  */
name|uint8_t
name|macId
decl_stmt|;
name|uint8_t
name|tbi_phy_addr
decl_stmt|;
name|uint32_t
name|exceptions
decl_stmt|;
name|bool
name|ptpTsuEnabled
decl_stmt|;
name|bool
name|enTsuErrExeption
decl_stmt|;
name|e_FmMacStatisticsLevel
name|statisticsLevel
decl_stmt|;
name|struct
name|dtsec_cfg
modifier|*
name|p_DtsecDriverParam
decl_stmt|;
block|}
name|t_Dtsec
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DTSEC_H */
end_comment

end_unit

