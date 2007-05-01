begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: if_stgereg.h,v 1.3 2003/02/10 21:10:07 christos Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Jason R. Thorpe.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Sundance Technology PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDOR_SUNDANCETI
value|0x13f0
end_define

begin_comment
comment|/*  * Tamarack Microelectronics PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDOR_TAMARACK
value|0x143d
end_define

begin_comment
comment|/*  * D-Link Systems PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDOR_DLINK
value|0x1186
end_define

begin_comment
comment|/*  * Antares Microsystems PCI vendor ID  */
end_comment

begin_define
define|#
directive|define
name|VENDOR_ANTARES
value|0x1754
end_define

begin_comment
comment|/*  * Sundance Technology device ID  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_SUNDANCETI_ST1023
value|0x1023
end_define

begin_define
define|#
directive|define
name|DEVICEID_SUNDANCETI_ST2021
value|0x2021
end_define

begin_define
define|#
directive|define
name|DEVICEID_TAMARACK_TC9021
value|0x1021
end_define

begin_define
define|#
directive|define
name|DEVICEID_TAMARACK_TC9021_ALT
value|0x9021
end_define

begin_comment
comment|/*  * D-Link Systems device ID  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_DLINK_DL4000
value|0x4000
end_define

begin_comment
comment|/*  * Antares Microsystems device ID  */
end_comment

begin_define
define|#
directive|define
name|DEVICEID_ANTARES_TC9021
value|0x1021
end_define

begin_comment
comment|/*  * Register description for the Sundance Tech. TC9021 10/100/1000  * Ethernet controller.  *  * Note that while DMA addresses are all in 64-bit fields, only  * the lower 40 bits of a DMA address are valid.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|BUS_SPACE_MAXADDR
operator|<
literal|0xFFFFFFFFFF
operator|)
end_if

begin_define
define|#
directive|define
name|STGE_DMA_MAXADDR
value|BUS_SPACE_MAXADDR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STGE_DMA_MAXADDR
value|0xFFFFFFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Register access macros  */
end_comment

begin_define
define|#
directive|define
name|CSR_WRITE_4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_4((_sc)->sc_res[0], (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_2
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_2((_sc)->sc_res[0], (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_WRITE_1
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
define|\
value|bus_write_1((_sc)->sc_res[0], (reg), (val))
end_define

begin_define
define|#
directive|define
name|CSR_READ_4
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_4((_sc)->sc_res[0], (reg))
end_define

begin_define
define|#
directive|define
name|CSR_READ_2
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_2((_sc)->sc_res[0], (reg))
end_define

begin_define
define|#
directive|define
name|CSR_READ_1
parameter_list|(
name|_sc
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_read_1((_sc)->sc_res[0], (reg))
end_define

begin_comment
comment|/*  * TC9021 buffer fragment descriptor.  */
end_comment

begin_struct
struct|struct
name|stge_frag
block|{
name|uint64_t
name|frag_word0
decl_stmt|;
comment|/* address, length */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FRAG_ADDR
parameter_list|(
name|x
parameter_list|)
value|(((uint64_t)(x))<< 0)
end_define

begin_define
define|#
directive|define
name|FRAG_ADDR_MASK
value|FRAG_ADDR(0xfffffffffULL)
end_define

begin_define
define|#
directive|define
name|FRAG_LEN
parameter_list|(
name|x
parameter_list|)
value|(((uint64_t)(x))<< 48)
end_define

begin_define
define|#
directive|define
name|FRAG_LEN_MASK
value|FRAG_LEN(0xffffULL)
end_define

begin_comment
comment|/*  * TC9021 Transmit Frame Descriptor.  Note the number of fragments  * here is arbitrary, but we can't have any more than 15.  */
end_comment

begin_define
define|#
directive|define
name|STGE_NTXFRAGS
value|15
end_define

begin_struct
struct|struct
name|stge_tfd
block|{
name|uint64_t
name|tfd_next
decl_stmt|;
comment|/* next TFD in list */
name|uint64_t
name|tfd_control
decl_stmt|;
comment|/* control bits */
comment|/* the buffer fragments */
name|struct
name|stge_frag
name|tfd_frags
index|[
name|STGE_NTXFRAGS
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TFD_FrameId
parameter_list|(
name|x
parameter_list|)
value|((x)<< 0)
end_define

begin_define
define|#
directive|define
name|TFD_FrameId_MAX
value|0xffff
end_define

begin_define
define|#
directive|define
name|TFD_WordAlign
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_define
define|#
directive|define
name|TFD_WordAlign_dword
value|0
end_define

begin_comment
comment|/* align to dword in TxFIFO */
end_comment

begin_define
define|#
directive|define
name|TFD_WordAlign_word
value|2
end_define

begin_comment
comment|/* align to word in TxFIFO */
end_comment

begin_define
define|#
directive|define
name|TFD_WordAlign_disable
value|1
end_define

begin_comment
comment|/* disable alignment */
end_comment

begin_define
define|#
directive|define
name|TFD_TCPChecksumEnable
value|(1ULL<< 18)
end_define

begin_define
define|#
directive|define
name|TFD_UDPChecksumEnable
value|(1ULL<< 19)
end_define

begin_define
define|#
directive|define
name|TFD_IPChecksumEnable
value|(1ULL<< 20)
end_define

begin_define
define|#
directive|define
name|TFD_FcsAppendDisable
value|(1ULL<< 21)
end_define

begin_define
define|#
directive|define
name|TFD_TxIndicate
value|(1ULL<< 22)
end_define

begin_define
define|#
directive|define
name|TFD_TxDMAIndicate
value|(1ULL<< 23)
end_define

begin_define
define|#
directive|define
name|TFD_FragCount
parameter_list|(
name|x
parameter_list|)
value|((x)<< 24)
end_define

begin_define
define|#
directive|define
name|TFD_VLANTagInsert
value|(1ULL<< 28)
end_define

begin_define
define|#
directive|define
name|TFD_TFDDone
value|(1ULL<< 31)
end_define

begin_define
define|#
directive|define
name|TFD_VID
parameter_list|(
name|x
parameter_list|)
value|(((uint64_t)(x))<< 32)
end_define

begin_define
define|#
directive|define
name|TFD_CFI
value|(1ULL<< 44)
end_define

begin_define
define|#
directive|define
name|TFD_UserPriority
parameter_list|(
name|x
parameter_list|)
value|(((uint64_t)(x))<< 45)
end_define

begin_comment
comment|/*  * TC9021 Receive Frame Descriptor.  Each RFD has a single fragment  * in it, and the chip tells us the beginning and end of the frame.  */
end_comment

begin_struct
struct|struct
name|stge_rfd
block|{
name|uint64_t
name|rfd_next
decl_stmt|;
comment|/* next RFD in list */
name|uint64_t
name|rfd_status
decl_stmt|;
comment|/* status bits */
name|struct
name|stge_frag
name|rfd_frag
decl_stmt|;
comment|/* the buffer */
block|}
struct|;
end_struct

begin_comment
comment|/* Low word of rfd_status */
end_comment

begin_define
define|#
directive|define
name|RFD_RxStatus
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffffffff)
end_define

begin_define
define|#
directive|define
name|RFD_RxDMAFrameLen
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffff)
end_define

begin_define
define|#
directive|define
name|RFD_RxFIFOOverrun
value|0x00010000
end_define

begin_define
define|#
directive|define
name|RFD_RxRuntFrame
value|0x00020000
end_define

begin_define
define|#
directive|define
name|RFD_RxAlignmentError
value|0x00040000
end_define

begin_define
define|#
directive|define
name|RFD_RxFCSError
value|0x00080000
end_define

begin_define
define|#
directive|define
name|RFD_RxOversizedFrame
value|0x00100000
end_define

begin_define
define|#
directive|define
name|RFD_RxLengthError
value|0x00200000
end_define

begin_define
define|#
directive|define
name|RFD_VLANDetected
value|0x00400000
end_define

begin_define
define|#
directive|define
name|RFD_TCPDetected
value|0x00800000
end_define

begin_define
define|#
directive|define
name|RFD_TCPError
value|0x01000000
end_define

begin_define
define|#
directive|define
name|RFD_UDPDetected
value|0x02000000
end_define

begin_define
define|#
directive|define
name|RFD_UDPError
value|0x04000000
end_define

begin_define
define|#
directive|define
name|RFD_IPDetected
value|0x08000000
end_define

begin_define
define|#
directive|define
name|RFD_IPError
value|0x10000000
end_define

begin_define
define|#
directive|define
name|RFD_FrameStart
value|0x20000000
end_define

begin_define
define|#
directive|define
name|RFD_FrameEnd
value|0x40000000
end_define

begin_define
define|#
directive|define
name|RFD_RFDDone
value|0x80000000
end_define

begin_comment
comment|/* High word of rfd_status */
end_comment

begin_define
define|#
directive|define
name|RFD_TCI
parameter_list|(
name|x
parameter_list|)
value|((((uint64_t)(x))>> 32)& 0xffff)
end_define

begin_comment
comment|/*  * EEPROM offsets.  */
end_comment

begin_define
define|#
directive|define
name|STGE_EEPROM_ConfigParam
value|0x00
end_define

begin_define
define|#
directive|define
name|STGE_EEPROM_AsicCtrl
value|0x01
end_define

begin_define
define|#
directive|define
name|STGE_EEPROM_SubSystemVendorId
value|0x02
end_define

begin_define
define|#
directive|define
name|STGE_EEPROM_SubSystemId
value|0x03
end_define

begin_define
define|#
directive|define
name|STGE_EEPROM_LEDMode
value|0x06
end_define

begin_define
define|#
directive|define
name|STGE_EEPROM_StationAddress0
value|0x10
end_define

begin_define
define|#
directive|define
name|STGE_EEPROM_StationAddress1
value|0x11
end_define

begin_define
define|#
directive|define
name|STGE_EEPROM_StationAddress2
value|0x12
end_define

begin_comment
comment|/*  * The TC9021 register space.  */
end_comment

begin_define
define|#
directive|define
name|STGE_DMACtrl
value|0x00
end_define

begin_define
define|#
directive|define
name|DMAC_RxDMAComplete
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|DMAC_RxDMAPollNow
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|DMAC_TxDMAComplete
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|DMAC_TxDMAPollNow
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|DMAC_TxDMAInProg
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|DMAC_RxEarlyDisable
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|DMAC_MWIDisable
value|(1U<< 18)
end_define

begin_define
define|#
directive|define
name|DMAC_TxWriteBackDisable
value|(1U<< 19)
end_define

begin_define
define|#
directive|define
name|DMAC_TxBurstLimit
parameter_list|(
name|x
parameter_list|)
value|((x)<< 20)
end_define

begin_define
define|#
directive|define
name|DMAC_TargetAbort
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|DMAC_MasterAbort
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|STGE_RxDMAStatus
value|0x08
end_define

begin_define
define|#
directive|define
name|STGE_TFDListPtrLo
value|0x10
end_define

begin_define
define|#
directive|define
name|STGE_TFDListPtrHi
value|0x14
end_define

begin_define
define|#
directive|define
name|STGE_TxDMABurstThresh
value|0x18
end_define

begin_comment
comment|/* 8-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_TxDMAUrgentThresh
value|0x19
end_define

begin_comment
comment|/* 8-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_TxDMAPollPeriod
value|0x1a
end_define

begin_comment
comment|/* 8-bit, 320ns increments */
end_comment

begin_define
define|#
directive|define
name|STGE_RFDListPtrLo
value|0x1c
end_define

begin_define
define|#
directive|define
name|STGE_RFDListPtrHi
value|0x20
end_define

begin_define
define|#
directive|define
name|STGE_RxDMABurstThresh
value|0x24
end_define

begin_comment
comment|/* 8-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_RxDMAUrgentThresh
value|0x25
end_define

begin_comment
comment|/* 8-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_RxDMAPollPeriod
value|0x26
end_define

begin_comment
comment|/* 8-bit, 320ns increments */
end_comment

begin_define
define|#
directive|define
name|STGE_RxDMAIntCtrl
value|0x28
end_define

begin_define
define|#
directive|define
name|RDIC_RxFrameCount
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_define
define|#
directive|define
name|RDIC_PriorityThresh
parameter_list|(
name|x
parameter_list|)
value|((x)<< 10)
end_define

begin_define
define|#
directive|define
name|RDIC_RxDMAWaitTime
parameter_list|(
name|x
parameter_list|)
value|((x)<< 16)
end_define

begin_comment
comment|/*  * Number of receive frames transferred via DMA before a Rx interrupt is issued.  */
end_comment

begin_define
define|#
directive|define
name|STGE_RXINT_NFRAME_DEFAULT
value|8
end_define

begin_define
define|#
directive|define
name|STGE_RXINT_NFRAME_MIN
value|1
end_define

begin_define
define|#
directive|define
name|STGE_RXINT_NFRAME_MAX
value|255
end_define

begin_comment
comment|/*  * Maximum amount of time (in 64ns increments) to wait before issuing a Rx  * interrupt if number of frames recevied is less than STGE_RXINT_NFRAME  * (STGE_RXINT_NFRAME_MIN<= STGE_RXINT_NFRAME<= STGE_RXINT_NFRAME_MAX)  */
end_comment

begin_define
define|#
directive|define
name|STGE_RXINT_DMAWAIT_DEFAULT
value|30
end_define

begin_comment
comment|/* 30us */
end_comment

begin_define
define|#
directive|define
name|STGE_RXINT_DMAWAIT_MIN
value|0
end_define

begin_define
define|#
directive|define
name|STGE_RXINT_DMAWAIT_MAX
value|4194
end_define

begin_define
define|#
directive|define
name|STGE_RXINT_USECS2TICK
parameter_list|(
name|x
parameter_list|)
value|(((x) * 1000)/64)
end_define

begin_define
define|#
directive|define
name|STGE_DebugCtrl
value|0x2c
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|DC_GPIO0Ctrl
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|DC_GPIO1Ctrl
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|DC_GPIO0
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|DC_GPIO1
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|STGE_AsicCtrl
value|0x30
end_define

begin_define
define|#
directive|define
name|AC_ExpRomDisable
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|AC_ExpRomSize
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|AC_PhySpeed10
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|AC_PhySpeed100
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|AC_PhySpeed1000
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|AC_PhyMedia
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|AC_ForcedConfig
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|AC_ForcedConfig_MASK
value|AC_ForcedConfig(7)
end_define

begin_define
define|#
directive|define
name|AC_D3ResetDisable
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|AC_SpeedupMode
value|(1U<< 13)
end_define

begin_define
define|#
directive|define
name|AC_LEDMode
value|(1U<< 14)
end_define

begin_define
define|#
directive|define
name|AC_RstOutPolarity
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|AC_GlobalReset
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|AC_RxReset
value|(1U<< 17)
end_define

begin_define
define|#
directive|define
name|AC_TxReset
value|(1U<< 18)
end_define

begin_define
define|#
directive|define
name|AC_DMA
value|(1U<< 19)
end_define

begin_define
define|#
directive|define
name|AC_FIFO
value|(1U<< 20)
end_define

begin_define
define|#
directive|define
name|AC_Network
value|(1U<< 21)
end_define

begin_define
define|#
directive|define
name|AC_Host
value|(1U<< 22)
end_define

begin_define
define|#
directive|define
name|AC_AutoInit
value|(1U<< 23)
end_define

begin_define
define|#
directive|define
name|AC_RstOut
value|(1U<< 24)
end_define

begin_define
define|#
directive|define
name|AC_InterruptRequest
value|(1U<< 25)
end_define

begin_define
define|#
directive|define
name|AC_ResetBusy
value|(1U<< 26)
end_define

begin_define
define|#
directive|define
name|AC_LEDSpeed
value|(1U<< 27)
end_define

begin_define
define|#
directive|define
name|AC_LEDModeBit1
value|(1U<< 29)
end_define

begin_define
define|#
directive|define
name|STGE_FIFOCtrl
value|0x38
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|FC_RAMTestMode
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|FC_Transmitting
value|(1U<< 14)
end_define

begin_define
define|#
directive|define
name|FC_Receiving
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|STGE_RxEarlyThresh
value|0x3a
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_FlowOffThresh
value|0x3c
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_FlowOnTresh
value|0x3e
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_TxStartThresh
value|0x44
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_EepromData
value|0x48
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_EepromCtrl
value|0x4a
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|EC_EepromAddress
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xff)
end_define

begin_define
define|#
directive|define
name|EC_EepromOpcode
parameter_list|(
name|x
parameter_list|)
value|((x)<< 8)
end_define

begin_define
define|#
directive|define
name|EC_OP_WE
value|0
end_define

begin_define
define|#
directive|define
name|EC_OP_WR
value|1
end_define

begin_define
define|#
directive|define
name|EC_OP_RR
value|2
end_define

begin_define
define|#
directive|define
name|EC_OP_ER
value|3
end_define

begin_define
define|#
directive|define
name|EC_EepromBusy
value|(1U<< 15)
end_define

begin_define
define|#
directive|define
name|STGE_ExpRomAddr
value|0x4c
end_define

begin_define
define|#
directive|define
name|STGE_ExpRomData
value|0x50
end_define

begin_comment
comment|/* 8-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_WakeEvent
value|0x51
end_define

begin_comment
comment|/* 8-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_Countdown
value|0x54
end_define

begin_define
define|#
directive|define
name|CD_Count
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xffff)
end_define

begin_define
define|#
directive|define
name|CD_CountdownSpeed
value|(1U<< 24)
end_define

begin_define
define|#
directive|define
name|CD_CountdownMode
value|(1U<< 25)
end_define

begin_define
define|#
directive|define
name|CD_CountdownIntEnabled
value|(1U<< 26)
end_define

begin_define
define|#
directive|define
name|STGE_IntStatusAck
value|0x5a
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_IntEnable
value|0x5c
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_IntStatus
value|0x5e
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|IS_InterruptStatus
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|IS_HostError
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|IS_TxComplete
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|IS_MACControlFrame
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|IS_RxComplete
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|IS_RxEarly
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|IS_InRequested
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|IS_UpdateStats
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|IS_LinkEvent
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|IS_TxDMAComplete
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|IS_RxDMAComplete
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|IS_RFDListEnd
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|IS_RxDMAPriority
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|STGE_TxStatus
value|0x60
end_define

begin_define
define|#
directive|define
name|TS_TxError
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|TS_LateCollision
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|TS_MaxCollisions
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|TS_TxUnderrun
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|TS_TxIndicateReqd
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|TS_TxComplete
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|TS_TxFrameId_get
parameter_list|(
name|x
parameter_list|)
value|((x)>> 16)
end_define

begin_define
define|#
directive|define
name|STGE_MACCtrl
value|0x6c
end_define

begin_define
define|#
directive|define
name|MC_IFSSelect
parameter_list|(
name|x
parameter_list|)
value|((x)& 3)
end_define

begin_define
define|#
directive|define
name|MC_IFS96bit
value|0
end_define

begin_define
define|#
directive|define
name|MC_IFS1024bit
value|1
end_define

begin_define
define|#
directive|define
name|MC_IFS1792bit
value|2
end_define

begin_define
define|#
directive|define
name|MC_IFS4352bit
value|3
end_define

begin_define
define|#
directive|define
name|MC_DuplexSelect
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|MC_RcvLargeFrames
value|(1U<< 6)
end_define

begin_define
define|#
directive|define
name|MC_TxFlowControlEnable
value|(1U<< 7)
end_define

begin_define
define|#
directive|define
name|MC_RxFlowControlEnable
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|MC_RcvFCS
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|MC_FIFOLoopback
value|(1U<< 10)
end_define

begin_define
define|#
directive|define
name|MC_MACLoopback
value|(1U<< 11)
end_define

begin_define
define|#
directive|define
name|MC_AutoVLANtagging
value|(1U<< 12)
end_define

begin_define
define|#
directive|define
name|MC_AutoVLANuntagging
value|(1U<< 13)
end_define

begin_define
define|#
directive|define
name|MC_CollisionDetect
value|(1U<< 16)
end_define

begin_define
define|#
directive|define
name|MC_CarrierSense
value|(1U<< 17)
end_define

begin_define
define|#
directive|define
name|MC_StatisticsEnable
value|(1U<< 21)
end_define

begin_define
define|#
directive|define
name|MC_StatisticsDisable
value|(1U<< 22)
end_define

begin_define
define|#
directive|define
name|MC_StatisticsEnabled
value|(1U<< 23)
end_define

begin_define
define|#
directive|define
name|MC_TxEnable
value|(1U<< 24)
end_define

begin_define
define|#
directive|define
name|MC_TxDisable
value|(1U<< 25)
end_define

begin_define
define|#
directive|define
name|MC_TxEnabled
value|(1U<< 26)
end_define

begin_define
define|#
directive|define
name|MC_RxEnable
value|(1U<< 27)
end_define

begin_define
define|#
directive|define
name|MC_RxDisable
value|(1U<< 28)
end_define

begin_define
define|#
directive|define
name|MC_RxEnabled
value|(1U<< 29)
end_define

begin_define
define|#
directive|define
name|MC_Paused
value|(1U<< 30)
end_define

begin_define
define|#
directive|define
name|MC_MASK
value|0x7fe33fa3
end_define

begin_define
define|#
directive|define
name|STGE_VLANTag
value|0x70
end_define

begin_define
define|#
directive|define
name|STGE_PhySet
value|0x75
end_define

begin_comment
comment|/* 8-bit */
end_comment

begin_define
define|#
directive|define
name|PS_MemLenb9b
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|PS_MemLen
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|PS_NonCompdet
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|STGE_PhyCtrl
value|0x76
end_define

begin_comment
comment|/* 8-bit */
end_comment

begin_define
define|#
directive|define
name|PC_MgmtClk
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|PC_MgmtData
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|PC_MgmtDir
value|(1U<< 2)
end_define

begin_comment
comment|/* MAC->PHY */
end_comment

begin_define
define|#
directive|define
name|PC_PhyDuplexPolarity
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|PC_PhyDuplexStatus
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|PC_PhyLnkPolarity
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|PC_LinkSpeed
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 6)& 3)
end_define

begin_define
define|#
directive|define
name|PC_LinkSpeed_Down
value|0
end_define

begin_define
define|#
directive|define
name|PC_LinkSpeed_10
value|1
end_define

begin_define
define|#
directive|define
name|PC_LinkSpeed_100
value|2
end_define

begin_define
define|#
directive|define
name|PC_LinkSpeed_1000
value|3
end_define

begin_define
define|#
directive|define
name|STGE_StationAddress0
value|0x78
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_StationAddress1
value|0x7a
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_StationAddress2
value|0x7c
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_VLANHashTable
value|0x7e
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_VLANId
value|0x80
end_define

begin_define
define|#
directive|define
name|STGE_MaxFrameSize
value|0x86
end_define

begin_define
define|#
directive|define
name|STGE_ReceiveMode
value|0x88
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|RM_ReceiveUnicast
value|(1U<< 0)
end_define

begin_define
define|#
directive|define
name|RM_ReceiveMulticast
value|(1U<< 1)
end_define

begin_define
define|#
directive|define
name|RM_ReceiveBroadcast
value|(1U<< 2)
end_define

begin_define
define|#
directive|define
name|RM_ReceiveAllFrames
value|(1U<< 3)
end_define

begin_define
define|#
directive|define
name|RM_ReceiveMulticastHash
value|(1U<< 4)
end_define

begin_define
define|#
directive|define
name|RM_ReceiveIPMulticast
value|(1U<< 5)
end_define

begin_define
define|#
directive|define
name|RM_ReceiveVLANMatch
value|(1U<< 8)
end_define

begin_define
define|#
directive|define
name|RM_ReceiveVLANHash
value|(1U<< 9)
end_define

begin_define
define|#
directive|define
name|STGE_HashTable0
value|0x8c
end_define

begin_define
define|#
directive|define
name|STGE_HashTable1
value|0x90
end_define

begin_define
define|#
directive|define
name|STGE_RMONStatisticsMask
value|0x98
end_define

begin_comment
comment|/* set to disable */
end_comment

begin_define
define|#
directive|define
name|STGE_StatisticsMask
value|0x9c
end_define

begin_comment
comment|/* set to disable */
end_comment

begin_define
define|#
directive|define
name|STGE_RxJumboFrames
value|0xbc
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_TCPCheckSumErrors
value|0xc0
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_IPCheckSumErrors
value|0xc2
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_UDPCheckSumErrors
value|0xc4
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_TxJumboFrames
value|0xf4
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_comment
comment|/*  * TC9021 statistics.  Available memory and I/O mapped.  */
end_comment

begin_define
define|#
directive|define
name|STGE_OctetRcvOk
value|0xa8
end_define

begin_define
define|#
directive|define
name|STGE_McstOctetRcvdOk
value|0xac
end_define

begin_define
define|#
directive|define
name|STGE_BcstOctetRcvdOk
value|0xb0
end_define

begin_define
define|#
directive|define
name|STGE_FramesRcvdOk
value|0xb4
end_define

begin_define
define|#
directive|define
name|STGE_McstFramesRcvdOk
value|0xb8
end_define

begin_define
define|#
directive|define
name|STGE_BcstFramesRcvdOk
value|0xbe
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_MacControlFramesRcvd
value|0xc6
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_FrameTooLongErrors
value|0xc8
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_InRangeLengthErrors
value|0xca
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_FramesCheckSeqErrors
value|0xcc
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_FramesLostRxErrors
value|0xce
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_OctetXmtdOk
value|0xd0
end_define

begin_define
define|#
directive|define
name|STGE_McstOctetXmtdOk
value|0xd4
end_define

begin_define
define|#
directive|define
name|STGE_BcstOctetXmtdOk
value|0xd8
end_define

begin_define
define|#
directive|define
name|STGE_FramesXmtdOk
value|0xdc
end_define

begin_define
define|#
directive|define
name|STGE_McstFramesXmtdOk
value|0xe0
end_define

begin_define
define|#
directive|define
name|STGE_FramesWDeferredXmt
value|0xe4
end_define

begin_define
define|#
directive|define
name|STGE_LateCollisions
value|0xe8
end_define

begin_define
define|#
directive|define
name|STGE_MultiColFrames
value|0xec
end_define

begin_define
define|#
directive|define
name|STGE_SingleColFrames
value|0xf0
end_define

begin_define
define|#
directive|define
name|STGE_BcstFramesXmtdOk
value|0xf6
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_CarrierSenseErrors
value|0xf8
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_MacControlFramesXmtd
value|0xfa
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_FramesAbortXSColls
value|0xfc
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_define
define|#
directive|define
name|STGE_FramesWEXDeferal
value|0xfe
end_define

begin_comment
comment|/* 16-bit */
end_comment

begin_comment
comment|/*  * RMON-compatible statistics.  Only accessible if memory-mapped.  */
end_comment

begin_define
define|#
directive|define
name|STGE_EtherStatsCollisions
value|0x100
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsOctetsTransmit
value|0x104
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPktsTransmit
value|0x108
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts64OctetsTransmit
value|0x10c
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts64to127OctetsTransmit
value|0x110
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts128to255OctetsTransmit
value|0x114
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts256to511OctetsTransmit
value|0x118
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts512to1023OctetsTransmit
value|0x11c
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts1024to1518OctetsTransmit
value|0x120
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsCRCAlignErrors
value|0x124
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsUndersizePkts
value|0x128
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsFragments
value|0x12c
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsJabbers
value|0x130
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsOctets
value|0x134
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts
value|0x138
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts64Octets
value|0x13c
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts65to127Octets
value|0x140
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts128to255Octets
value|0x144
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts256to511Octets
value|0x148
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts512to1023Octets
value|0x14c
end_define

begin_define
define|#
directive|define
name|STGE_EtherStatsPkts1024to1518Octets
value|0x150
end_define

begin_comment
comment|/*  * Transmit descriptor list size.  */
end_comment

begin_define
define|#
directive|define
name|STGE_TX_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|STGE_TX_LOWAT
value|(STGE_TX_RING_CNT/32)
end_define

begin_define
define|#
directive|define
name|STGE_TX_HIWAT
value|(STGE_TX_RING_CNT - STGE_TX_LOWAT)
end_define

begin_comment
comment|/*  * Receive descriptor list size.  */
end_comment

begin_define
define|#
directive|define
name|STGE_RX_RING_CNT
value|256
end_define

begin_define
define|#
directive|define
name|STGE_MAXTXSEGS
value|STGE_NTXFRAGS
end_define

begin_define
define|#
directive|define
name|STGE_JUMBO_FRAMELEN
value|9022
end_define

begin_define
define|#
directive|define
name|STGE_JUMBO_MTU
define|\
value|(STGE_JUMBO_FRAMELEN - ETHER_HDR_LEN - ETHER_CRC_LEN)
end_define

begin_struct
struct|struct
name|stge_txdesc
block|{
name|struct
name|mbuf
modifier|*
name|tx_m
decl_stmt|;
comment|/* head of our mbuf chain */
name|bus_dmamap_t
name|tx_dmamap
decl_stmt|;
comment|/* our DMA map */
name|STAILQ_ENTRY
argument_list|(
argument|stge_txdesc
argument_list|)
name|tx_q
expr_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|STAILQ_HEAD
argument_list|(
name|stge_txdq
argument_list|,
name|stge_txdesc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|stge_rxdesc
block|{
name|struct
name|mbuf
modifier|*
name|rx_m
decl_stmt|;
name|bus_dmamap_t
name|rx_dmamap
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STGE_ADDR_LO
parameter_list|(
name|x
parameter_list|)
value|((u_int64_t) (x)& 0xffffffff)
end_define

begin_define
define|#
directive|define
name|STGE_ADDR_HI
parameter_list|(
name|x
parameter_list|)
value|((u_int64_t) (x)>> 32)
end_define

begin_define
define|#
directive|define
name|STGE_RING_ALIGN
value|8
end_define

begin_struct
struct|struct
name|stge_chain_data
block|{
name|bus_dma_tag_t
name|stge_parent_tag
decl_stmt|;
name|bus_dma_tag_t
name|stge_tx_tag
decl_stmt|;
name|struct
name|stge_txdesc
name|stge_txdesc
index|[
name|STGE_TX_RING_CNT
index|]
decl_stmt|;
name|struct
name|stge_txdq
name|stge_txfreeq
decl_stmt|;
name|struct
name|stge_txdq
name|stge_txbusyq
decl_stmt|;
name|bus_dma_tag_t
name|stge_rx_tag
decl_stmt|;
name|struct
name|stge_rxdesc
name|stge_rxdesc
index|[
name|STGE_RX_RING_CNT
index|]
decl_stmt|;
name|bus_dma_tag_t
name|stge_tx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|stge_tx_ring_map
decl_stmt|;
name|bus_dma_tag_t
name|stge_rx_ring_tag
decl_stmt|;
name|bus_dmamap_t
name|stge_rx_ring_map
decl_stmt|;
name|bus_dmamap_t
name|stge_rx_sparemap
decl_stmt|;
name|int
name|stge_tx_prod
decl_stmt|;
name|int
name|stge_tx_cons
decl_stmt|;
name|int
name|stge_tx_cnt
decl_stmt|;
name|int
name|stge_rx_cons
decl_stmt|;
ifdef|#
directive|ifdef
name|DEVICE_POLLING
name|int
name|stge_rxcycles
decl_stmt|;
endif|#
directive|endif
name|int
name|stge_rxlen
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|stge_rxhead
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|stge_rxtail
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|stge_ring_data
block|{
name|struct
name|stge_tfd
modifier|*
name|stge_tx_ring
decl_stmt|;
name|bus_addr_t
name|stge_tx_ring_paddr
decl_stmt|;
name|struct
name|stge_rfd
modifier|*
name|stge_rx_ring
decl_stmt|;
name|bus_addr_t
name|stge_rx_ring_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STGE_TX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->sc_rdata.stge_tx_ring_paddr + sizeof(struct stge_tfd) * (i))
end_define

begin_define
define|#
directive|define
name|STGE_RX_RING_ADDR
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|((sc)->sc_rdata.stge_rx_ring_paddr + sizeof(struct stge_rfd) * (i))
end_define

begin_define
define|#
directive|define
name|STGE_TX_RING_SZ
define|\
value|(sizeof(struct stge_tfd) * STGE_TX_RING_CNT)
end_define

begin_define
define|#
directive|define
name|STGE_RX_RING_SZ
define|\
value|(sizeof(struct stge_rfd) * STGE_RX_RING_CNT)
end_define

begin_comment
comment|/*  * Software state per device.  */
end_comment

begin_struct
struct|struct
name|stge_softc
block|{
name|struct
name|ifnet
modifier|*
name|sc_ifp
decl_stmt|;
comment|/* interface info */
name|device_t
name|sc_dev
decl_stmt|;
name|device_t
name|sc_miibus
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_res
index|[
literal|2
index|]
decl_stmt|;
name|struct
name|resource_spec
modifier|*
name|sc_spec
decl_stmt|;
name|void
modifier|*
name|sc_ih
decl_stmt|;
comment|/* interrupt cookie */
name|int
name|sc_rev
decl_stmt|;
comment|/* silicon revision */
name|struct
name|callout
name|sc_tick_ch
decl_stmt|;
comment|/* tick callout */
name|struct
name|stge_chain_data
name|sc_cdata
decl_stmt|;
name|struct
name|stge_ring_data
name|sc_rdata
decl_stmt|;
name|int
name|sc_if_flags
decl_stmt|;
name|int
name|sc_if_framesize
decl_stmt|;
name|int
name|sc_txthresh
decl_stmt|;
comment|/* Tx threshold */
name|uint32_t
name|sc_usefiber
range|:
literal|1
decl_stmt|;
comment|/* if we're fiber */
name|uint32_t
name|sc_stge1023
range|:
literal|1
decl_stmt|;
comment|/* are we a 1023 */
name|uint32_t
name|sc_DMACtrl
decl_stmt|;
comment|/* prototype DMACtrl reg. */
name|uint32_t
name|sc_MACCtrl
decl_stmt|;
comment|/* prototype MacCtrl reg. */
name|uint16_t
name|sc_IntEnable
decl_stmt|;
comment|/* prototype IntEnable reg. */
name|uint16_t
name|sc_led
decl_stmt|;
comment|/* LED conf. from EEPROM */
name|uint8_t
name|sc_PhyCtrl
decl_stmt|;
comment|/* prototype PhyCtrl reg. */
name|int
name|sc_suspended
decl_stmt|;
name|int
name|sc_detach
decl_stmt|;
name|int
name|sc_rxint_nframe
decl_stmt|;
name|int
name|sc_rxint_dmawait
decl_stmt|;
name|int
name|sc_nerr
decl_stmt|;
name|int
name|sc_watchdog_timer
decl_stmt|;
name|struct
name|task
name|sc_link_task
decl_stmt|;
name|struct
name|mtx
name|sc_mii_mtx
decl_stmt|;
comment|/* MII mutex */
name|struct
name|mtx
name|sc_mtx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|STGE_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|STGE_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mtx)
end_define

begin_define
define|#
directive|define
name|STGE_LOCK_ASSERT
parameter_list|(
name|_sc
parameter_list|)
value|mtx_assert(&(_sc)->sc_mtx, MA_OWNED)
end_define

begin_define
define|#
directive|define
name|STGE_MII_LOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_lock(&(_sc)->sc_mii_mtx)
end_define

begin_define
define|#
directive|define
name|STGE_MII_UNLOCK
parameter_list|(
name|_sc
parameter_list|)
value|mtx_unlock(&(_sc)->sc_mii_mtx)
end_define

begin_define
define|#
directive|define
name|STGE_MAXERR
value|5
end_define

begin_define
define|#
directive|define
name|STGE_RXCHAIN_RESET
parameter_list|(
name|_sc
parameter_list|)
define|\
value|do {									\ 	(_sc)->sc_cdata.stge_rxhead = NULL;				\ 	(_sc)->sc_cdata.stge_rxtail = NULL;				\ 	(_sc)->sc_cdata.stge_rxlen = 0;					\ } while (
comment|/*CONSTCOND*/
value|0)
end_define

begin_define
define|#
directive|define
name|STGE_TIMEOUT
value|1000
end_define

begin_struct
struct|struct
name|stge_mii_frame
block|{
name|uint8_t
name|mii_stdelim
decl_stmt|;
name|uint8_t
name|mii_opcode
decl_stmt|;
name|uint8_t
name|mii_phyaddr
decl_stmt|;
name|uint8_t
name|mii_regaddr
decl_stmt|;
name|uint8_t
name|mii_turnaround
decl_stmt|;
name|uint16_t
name|mii_data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MII constants  */
end_comment

begin_define
define|#
directive|define
name|STGE_MII_STARTDELIM
value|0x01
end_define

begin_define
define|#
directive|define
name|STGE_MII_READOP
value|0x02
end_define

begin_define
define|#
directive|define
name|STGE_MII_WRITEOP
value|0x01
end_define

begin_define
define|#
directive|define
name|STGE_MII_TURNAROUND
value|0x02
end_define

begin_define
define|#
directive|define
name|STGE_RESET_NONE
value|0x00
end_define

begin_define
define|#
directive|define
name|STGE_RESET_TX
value|0x01
end_define

begin_define
define|#
directive|define
name|STGE_RESET_RX
value|0x02
end_define

begin_define
define|#
directive|define
name|STGE_RESET_FULL
value|0x04
end_define

end_unit

