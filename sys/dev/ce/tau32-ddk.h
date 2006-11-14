begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * DDK (Driver Development Kit) for Cronyx Tau32-PCI adapter.  *  * Copyright (C) 2003-2006 Cronyx Engineering, http://www.cronyx.ru  * All rights reserved.  *  * Author: Leo Yuriev<ly@cronyx.ru>, http://leo.yuriev.ru  *  * $Cronyx: tau32-ddk.h,v 1.2 2006/02/01 09:14:40 ly Exp $  * $Rik: tau32-ddk.h,v 1.7 2006/02/28 22:33:29 rik Exp $  * $FreeBSD$  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|||
name|defined
argument_list|(
name|__TURBOC__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|__int8
end_ifndef

begin_define
define|#
directive|define
name|__int8
value|char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__int16
end_ifndef

begin_define
define|#
directive|define
name|__int16
value|short
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__int32
end_ifndef

begin_define
define|#
directive|define
name|__int32
value|long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__int64
end_ifndef

begin_define
define|#
directive|define
name|__int64
value|long long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BOOLEAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_NTDDK_
argument_list|)
end_if

begin_define
define|#
directive|define
name|BOOLEAN
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__stdcall
argument_list|)
end_if

begin_define
define|#
directive|define
name|__stdcall
value|__attribute__((stdcall))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__cdecl
argument_list|)
end_if

begin_define
define|#
directive|define
name|__cdecl
value|__attribute__((cdecl))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TAU32_CALLBACK_TYPE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__WINDOWS__
argument_list|)
operator|||
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|TAU32_CALLBACK_TYPE
value|__stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TAU32_CALLBACK_TYPE
value|__cdecl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TAU32_CALL_TYPE
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__WINDOWS__
argument_list|)
operator|||
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN64
argument_list|)
end_if

begin_define
define|#
directive|define
name|TAU32_CALL_TYPE
value|__stdcall
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TAU32_CALL_TYPE
value|__cdecl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PCI_PHYSICAL_ADDRESS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PCI64
end_ifdef

begin_error
error|#
directive|error
error|PCI64 currently is not supported
end_error

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PCI_PHYSICAL_ADDRESS
value|unsigned __int32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TAU32_PCI_VENDOR_ID
value|0x110A
end_define

begin_define
define|#
directive|define
name|TAU32_PCI_DEVICE_ID
value|0x2101
end_define

begin_define
define|#
directive|define
name|TAU32_PCI_IO_BAR1_SIZE
value|0x0100
end_define

begin_define
define|#
directive|define
name|TAU32_PCI_RESET_ADDRESS
value|0x004C
end_define

begin_define
define|#
directive|define
name|TAU32_PCI_RESET_ON
value|0xF00F0000ul
end_define

begin_comment
comment|/*0xFFFFFFFFul */
end_comment

begin_define
define|#
directive|define
name|TAU32_PCI_RESET_OFF
value|0
end_define

begin_define
define|#
directive|define
name|TAU32_PCI_RESET_LENGTH
value|4
end_define

begin_comment
comment|/* TAU32_MODELS */
end_comment

begin_define
define|#
directive|define
name|TAU32_ERROR
value|(-1)
end_define

begin_define
define|#
directive|define
name|TAU32_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|TAU32_BASE
value|1
end_define

begin_define
define|#
directive|define
name|TAU32_LITE
value|2
end_define

begin_define
define|#
directive|define
name|TAU32_ADPCM
value|3
end_define

begin_comment
comment|/* TAU32_INIT_ERRORS */
end_comment

begin_define
define|#
directive|define
name|TAU32_IE_OK
value|0x0000u
end_define

begin_define
define|#
directive|define
name|TAU32_IE_FIRMWARE
value|0x0001u
end_define

begin_define
define|#
directive|define
name|TAU32_IE_MODEL
value|0x0002u
end_define

begin_define
define|#
directive|define
name|TAU32_IE_E1_A
value|0x0004u
end_define

begin_define
define|#
directive|define
name|TAU32_IE_E1_B
value|0x0008u
end_define

begin_define
define|#
directive|define
name|TAU32_IE_INTERNAL_BUS
value|0x0010u
end_define

begin_define
define|#
directive|define
name|TAU32_IE_HDLC
value|0x0020u
end_define

begin_define
define|#
directive|define
name|TAU32_IE_ADPCM
value|0x0040u
end_define

begin_define
define|#
directive|define
name|TAU32_IE_CLOCK
value|0x0080u
end_define

begin_define
define|#
directive|define
name|TAU32_IE_DXC
value|0x0100u
end_define

begin_define
define|#
directive|define
name|TAU32_IE_XIRQ
value|0x0200u
end_define

begin_comment
comment|/* TAU32_INTERFACES */
end_comment

begin_define
define|#
directive|define
name|TAU32_E1_ALL
value|(-1)
end_define

begin_define
define|#
directive|define
name|TAU32_E1_A
value|0
end_define

begin_define
define|#
directive|define
name|TAU32_E1_B
value|1
end_define

begin_comment
comment|/* TAU32_LIMITS */
end_comment

begin_define
define|#
directive|define
name|TAU32_CHANNELS
value|32
end_define

begin_define
define|#
directive|define
name|TAU32_TIMESLOTS
value|32
end_define

begin_define
define|#
directive|define
name|TAU32_MAX_INTERFACES
value|2
end_define

begin_define
define|#
directive|define
name|TAU32_MTU
value|8184
end_define

begin_define
define|#
directive|define
name|TAU32_FLAT_MTU
value|4096
end_define

begin_define
define|#
directive|define
name|TAU32_IO_QUEUE
value|4
end_define

begin_define
define|#
directive|define
name|TAU32_IO_QUEUE_BYTES
value|128
end_define

begin_define
define|#
directive|define
name|TAU32_MAX_REQUESTS
value|512
end_define

begin_define
define|#
directive|define
name|TAU32_MAX_BUFFERS
value|256
end_define

begin_define
define|#
directive|define
name|TAU32_FIFO_SIZE
value|256
end_define

begin_comment
comment|/* TAU32_REQUEST_COMMANDS */
end_comment

begin_define
define|#
directive|define
name|TAU32_Tx_Start
value|0x0001u
end_define

begin_define
define|#
directive|define
name|TAU32_Tx_Stop
value|0x0002u
end_define

begin_comment
comment|/*#define TAU32_Tx_Flush			  0x0004u // yet not implemented */
end_comment

begin_define
define|#
directive|define
name|TAU32_Tx_Data
value|0x0008u
end_define

begin_define
define|#
directive|define
name|TAU32_Rx_Start
value|0x0010u
end_define

begin_define
define|#
directive|define
name|TAU32_Rx_Stop
value|0x0020u
end_define

begin_define
define|#
directive|define
name|TAU32_Rx_Data
value|0x0080u
end_define

begin_define
define|#
directive|define
name|TAU32_Configure_Channel
value|0x0100u
end_define

begin_define
define|#
directive|define
name|TAU32_Timeslots_Complete
value|0x0200u
end_define

begin_define
define|#
directive|define
name|TAU32_Timeslots_Map
value|0x0400u
end_define

begin_define
define|#
directive|define
name|TAU32_Timeslots_Channel
value|0x0800u
end_define

begin_define
define|#
directive|define
name|TAU32_ConfigureDigitalLoop
value|0x1000u
end_define

begin_define
define|#
directive|define
name|TAU32_Configure_Commit
value|0x2000u
end_define

begin_define
define|#
directive|define
name|TAU32_Tx_FrameEnd
value|0x4000u
end_define

begin_define
define|#
directive|define
name|TAU32_Tx_NoCrc
value|0x8000u
end_define

begin_define
define|#
directive|define
name|TAU32_Configure_E1
value|0x0040u
end_define

begin_comment
comment|/* TAU32_ERRORS */
end_comment

begin_define
define|#
directive|define
name|TAU32_NOERROR
value|0x000000ul
end_define

begin_define
define|#
directive|define
name|TAU32_SUCCESSFUL
value|0x000000ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_ALLOCATION
value|0x000001ul
end_define

begin_comment
comment|/* not enough tx/rx descriptors */
end_comment

begin_define
define|#
directive|define
name|TAU32_ERROR_BUS
value|0x000002ul
end_define

begin_comment
comment|/* PEB could not access to host memory by PCI bus for load/store information */
end_comment

begin_define
define|#
directive|define
name|TAU32_ERROR_FAIL
value|0x000004ul
end_define

begin_comment
comment|/* PEB action request failed */
end_comment

begin_define
define|#
directive|define
name|TAU32_ERROR_TIMEOUT
value|0x000008ul
end_define

begin_comment
comment|/* PEB action request timeout */
end_comment

begin_define
define|#
directive|define
name|TAU32_ERROR_CANCELLED
value|0x000010ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_TX_UNDERFLOW
value|0x000020ul
end_define

begin_comment
comment|/* transmission underflow */
end_comment

begin_define
define|#
directive|define
name|TAU32_ERROR_TX_PROTOCOL
value|0x000040ul
end_define

begin_comment
comment|/* reserved */
end_comment

begin_define
define|#
directive|define
name|TAU32_ERROR_RX_OVERFLOW
value|0x000080ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_RX_ABORT
value|0x000100ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_RX_CRC
value|0x000200ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_RX_SHORT
value|0x000400ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_RX_SYNC
value|0x000800ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_RX_FRAME
value|0x001000ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_RX_LONG
value|0x002000ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_RX_SPLIT
value|0x004000ul
end_define

begin_comment
comment|/* frame has splitted between two requests due rx-gap allocation */
end_comment

begin_define
define|#
directive|define
name|TAU32_ERROR_RX_UNFIT
value|0x008000ul
end_define

begin_comment
comment|/* frame can't be fit into request buffer */
end_comment

begin_define
define|#
directive|define
name|TAU32_ERROR_TSP
value|0x010000ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_RSP
value|0x020000ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_INT_OVER_TX
value|0x040000ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_INT_OVER_RX
value|0x080000ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_INT_STORM
value|0x100000ul
end_define

begin_define
define|#
directive|define
name|TAU32_ERROR_INT_E1LOST
value|0x200000ul
end_define

begin_define
define|#
directive|define
name|TAU32_WARN_TX_JUMP
value|0x400000ul
end_define

begin_define
define|#
directive|define
name|TAU32_WARN_RX_JUMP
value|0x800000ul
end_define

begin_comment
comment|/* TAU32_CHANNEL_MODES */
end_comment

begin_define
define|#
directive|define
name|TAU32_HDLC
value|0
end_define

begin_define
define|#
directive|define
name|TAU32_V110_x30
value|1
end_define

begin_define
define|#
directive|define
name|TAU32_TMA
value|2
end_define

begin_define
define|#
directive|define
name|TAU32_TMB
value|3
end_define

begin_define
define|#
directive|define
name|TAU32_TMR
value|4
end_define

begin_comment
comment|/* TAU32_SYNC_MODES */
end_comment

begin_define
define|#
directive|define
name|TAU32_SYNC_INTERNAL
value|0
end_define

begin_define
define|#
directive|define
name|TAU32_SYNC_RCV_A
value|1
end_define

begin_define
define|#
directive|define
name|TAU32_SYNC_RCV_B
value|2
end_define

begin_define
define|#
directive|define
name|TAU32_SYNC_LYGEN
value|3
end_define

begin_define
define|#
directive|define
name|TAU32_LYGEN_RESET
value|0
end_define

begin_comment
comment|/* TAU32_CHANNEL_CONFIG_BITS */
end_comment

begin_define
define|#
directive|define
name|TAU32_channel_mode_mask
value|0x0000000Ful
end_define

begin_define
define|#
directive|define
name|TAU32_data_inversion
value|0x00000010ul
end_define

begin_define
define|#
directive|define
name|TAU32_fr_rx_splitcheck
value|0x00000020ul
end_define

begin_define
define|#
directive|define
name|TAU32_fr_rx_fitcheck
value|0x00000040ul
end_define

begin_define
define|#
directive|define
name|TAU32_fr_tx_auto
value|0x00000080ul
end_define

begin_define
define|#
directive|define
name|TAU32_hdlc_crc32
value|0x00000100ul
end_define

begin_define
define|#
directive|define
name|TAU32_hdlc_adjustment
value|0x00000200ul
end_define

begin_define
define|#
directive|define
name|TAU32_hdlc_interframe_fill
value|0x00000400ul
end_define

begin_define
define|#
directive|define
name|TAU32_hdlc_nocrc
value|0x00000800ul
end_define

begin_define
define|#
directive|define
name|TAU32_tma_flag_filtering
value|0x00001000ul
end_define

begin_define
define|#
directive|define
name|TAU32_tma_nopack
value|0x00002000ul
end_define

begin_define
define|#
directive|define
name|TAU32_tma_flags_mask
value|0x00FF0000ul
end_define

begin_define
define|#
directive|define
name|TAU32_tma_flags_shift
value|16u
end_define

begin_define
define|#
directive|define
name|TAU32_v110_x30_tr_mask
value|0x03000000ul
end_define

begin_define
define|#
directive|define
name|TAU32_v110_x30_tr_shift
value|24u
end_define

begin_typedef
typedef|typedef
struct|struct
name|tag_TAU32_TimeslotAssignment
block|{
name|unsigned
name|__int8
name|TxChannel
decl_stmt|,
name|RxChannel
decl_stmt|;
name|unsigned
name|__int8
name|TxFillmask
decl_stmt|,
name|RxFillmask
decl_stmt|;
block|}
name|TAU32_TimeslotAssignment
typedef|;
end_typedef

begin_define
define|#
directive|define
name|TAU32_CROSS_WIDTH
value|96
end_define

begin_define
define|#
directive|define
name|TAU32_CROSS_OFF
value|127
end_define

begin_typedef
typedef|typedef
name|unsigned
name|__int8
name|TAU32_CrossMatrix
index|[
name|TAU32_CROSS_WIDTH
index|]
typedef|;
end_typedef

begin_comment
comment|/* TAU32_INTERFACE_CONFIG_BITS */
end_comment

begin_define
define|#
directive|define
name|TAU32_LineOff
value|(0ul<< 0)
end_define

begin_define
define|#
directive|define
name|TAU32_LineLoopInt
value|(1ul<< 0)
end_define

begin_define
define|#
directive|define
name|TAU32_LineLoopExt
value|(2ul<< 0)
end_define

begin_define
define|#
directive|define
name|TAU32_LineNormal
value|(3ul<< 0)
end_define

begin_define
define|#
directive|define
name|TAU32_LineAIS
value|(4ul<< 0)
end_define

begin_define
define|#
directive|define
name|TAU32_line_mode_mask
value|0x0000000Ful
end_define

begin_define
define|#
directive|define
name|TAU32_unframed_64
value|(0ul<< 4)
end_define

begin_define
define|#
directive|define
name|TAU32_unframed_128
value|(1ul<< 4)
end_define

begin_define
define|#
directive|define
name|TAU32_unframed_256
value|(2ul<< 4)
end_define

begin_define
define|#
directive|define
name|TAU32_unframed_512
value|(3ul<< 4)
end_define

begin_define
define|#
directive|define
name|TAU32_unframed_1024
value|(4ul<< 4)
end_define

begin_define
define|#
directive|define
name|TAU32_unframed_2048
value|(5ul<< 4)
end_define

begin_define
define|#
directive|define
name|TAU32_unframed
value|TAU32_unframed_2048
end_define

begin_define
define|#
directive|define
name|TAU32_framed_no_cas
value|(6ul<< 4)
end_define

begin_define
define|#
directive|define
name|TAU32_framed_cas_set
value|(7ul<< 4)
end_define

begin_define
define|#
directive|define
name|TAU32_framed_cas_pass
value|(8ul<< 4)
end_define

begin_define
define|#
directive|define
name|TAU32_framed_cas_cross
value|(9ul<< 4)
end_define

begin_define
define|#
directive|define
name|TAU32_framing_mode_mask
value|0x000000F0ul
end_define

begin_define
define|#
directive|define
name|TAU32_monitor
value|0x00000100ul
end_define

begin_define
define|#
directive|define
name|TAU32_higain
value|0x00000200ul
end_define

begin_define
define|#
directive|define
name|TAU32_sa_bypass
value|0x00000400ul
end_define

begin_define
define|#
directive|define
name|TAU32_si_bypass
value|0x00000800ul
end_define

begin_define
define|#
directive|define
name|TAU32_cas_fe
value|0x00001000ul
end_define

begin_define
define|#
directive|define
name|TAU32_ais_on_loss
value|0x00002000ul
end_define

begin_define
define|#
directive|define
name|TAU32_cas_all_ones
value|0x00004000ul
end_define

begin_define
define|#
directive|define
name|TAU32_cas_io
value|0x00008000ul
end_define

begin_define
define|#
directive|define
name|TAU32_fas_io
value|0x00010000ul
end_define

begin_define
define|#
directive|define
name|TAU32_fas8_io
value|0x00020000ul
end_define

begin_define
define|#
directive|define
name|TAU32_auto_ais
value|0x00040000ul
end_define

begin_define
define|#
directive|define
name|TAU32_not_auto_ra
value|0x00080000ul
end_define

begin_define
define|#
directive|define
name|TAU32_not_auto_dmra
value|0x00100000ul
end_define

begin_define
define|#
directive|define
name|TAU32_ra
value|0x00200000ul
end_define

begin_define
define|#
directive|define
name|TAU32_dmra
value|0x00400000ul
end_define

begin_define
define|#
directive|define
name|TAU32_scrambler
value|0x00800000ul
end_define

begin_define
define|#
directive|define
name|TAU32_tx_ami
value|0x01000000ul
end_define

begin_define
define|#
directive|define
name|TAU32_rx_ami
value|0x02000000ul
end_define

begin_define
define|#
directive|define
name|TAU32_ja_tx
value|0x04000000ul
end_define

begin_define
define|#
directive|define
name|TAU32_crc4_mf_tx
value|0x08000000ul
end_define

begin_define
define|#
directive|define
name|TAU32_crc4_mf_rx
value|0x10000000ul
end_define

begin_define
define|#
directive|define
name|TAU32_crc4_mf
value|(TAU32_crc4_mf_rx | TAU32_crc4_mf_tx)
end_define

begin_comment
comment|/* TAU32_SA_CROSS_VALUES */
end_comment

begin_define
define|#
directive|define
name|TAU32_SaDisable
value|0u
end_define

begin_define
define|#
directive|define
name|TAU32_SaSystem
value|1u
end_define

begin_define
define|#
directive|define
name|TAU32_SaIntA
value|2u
end_define

begin_define
define|#
directive|define
name|TAU32_SaIntB
value|3u
end_define

begin_define
define|#
directive|define
name|TAU32_SaAllZeros
value|4u
end_define

begin_typedef
typedef|typedef
struct|struct
name|tag_TAU32_SaCross
block|{
name|unsigned
name|__int8
name|InterfaceA
decl_stmt|,
name|InterfaceB
decl_stmt|;
name|unsigned
name|__int8
name|SystemEnableTs0
decl_stmt|;
block|}
name|TAU32_SaCross
typedef|;
end_typedef

begin_comment
comment|/* TAU32_INTERFACE_STATUS_BITS */
end_comment

begin_define
define|#
directive|define
name|TAU32_RCL
value|0x0001u
end_define

begin_comment
comment|/* receive carrier lost */
end_comment

begin_define
define|#
directive|define
name|TAU32_RLOS
value|0x0002u
end_define

begin_comment
comment|/* receive sync lost */
end_comment

begin_define
define|#
directive|define
name|TAU32_RUA1
value|0x0004u
end_define

begin_comment
comment|/* received unframed all ones */
end_comment

begin_define
define|#
directive|define
name|TAU32_RRA
value|0x0008u
end_define

begin_comment
comment|/* receive remote alarm */
end_comment

begin_define
define|#
directive|define
name|TAU32_RSA1
value|0x0010u
end_define

begin_comment
comment|/* receive signaling all ones */
end_comment

begin_define
define|#
directive|define
name|TAU32_RSA0
value|0x0020u
end_define

begin_comment
comment|/* receive signaling all zeros */
end_comment

begin_define
define|#
directive|define
name|TAU32_RDMA
value|0x0040u
end_define

begin_comment
comment|/* receive distant multiframe alarm */
end_comment

begin_define
define|#
directive|define
name|TAU32_LOTC
value|0x0080u
end_define

begin_comment
comment|/* transmit clock lost */
end_comment

begin_define
define|#
directive|define
name|TAU32_RSLIP
value|0x0100u
end_define

begin_comment
comment|/* receiver slip event */
end_comment

begin_define
define|#
directive|define
name|TAU32_TSLIP
value|0x0200u
end_define

begin_comment
comment|/* transmitter slip event */
end_comment

begin_define
define|#
directive|define
name|TAU32_RFAS
value|0x0400u
end_define

begin_comment
comment|/* receiver lost and searching for FAS */
end_comment

begin_define
define|#
directive|define
name|TAU32_RCRC4
value|0x0800u
end_define

begin_comment
comment|/* receiver lost and searching for CRC4 MF */
end_comment

begin_define
define|#
directive|define
name|TAU32_RCAS
value|0x1000u
end_define

begin_comment
comment|/* received lost and searching for CAS MF */
end_comment

begin_define
define|#
directive|define
name|TAU32_JITTER
value|0x2000u
end_define

begin_comment
comment|/* jitter attenuator limit */
end_comment

begin_define
define|#
directive|define
name|TAU32_RCRC4LONG
value|0x4000u
end_define

begin_comment
comment|/* G.706 400ms limit of searching for CRC4 */
end_comment

begin_define
define|#
directive|define
name|TAU32_E1OFF
value|0x8000u
end_define

begin_comment
comment|/* E1 line power-off */
end_comment

begin_define
define|#
directive|define
name|TAU32_LOS
value|TAU32_RLOS
end_define

begin_define
define|#
directive|define
name|TAU32_AIS
value|TAU32_RUA1
end_define

begin_define
define|#
directive|define
name|TAU32_LOF
value|TAU32_RFAS
end_define

begin_define
define|#
directive|define
name|TAU32_AIS16
value|TAU32_RSA1
end_define

begin_define
define|#
directive|define
name|TAU32_LOFM
value|TAU32_RCAS
end_define

begin_define
define|#
directive|define
name|TAU32_FLOFM
value|TAU32_RDMA
end_define

begin_comment
comment|/* TAU32_STATUS */
end_comment

begin_define
define|#
directive|define
name|TAU32_FRLOFM
value|0x0001u
end_define

begin_comment
comment|/* CAS framer searching for CAS MF */
end_comment

begin_define
define|#
directive|define
name|TAU32_CMWAITING
value|0x0002u
end_define

begin_comment
comment|/* Connection memory swap waiting */
end_comment

begin_define
define|#
directive|define
name|TAU32_CMPENDING
value|0x0004u
end_define

begin_comment
comment|/* Connection memory swap pending */
end_comment

begin_define
define|#
directive|define
name|TAU32_LED
value|0x0008u
end_define

begin_comment
comment|/* Led status (on/off) */
end_comment

begin_typedef
typedef|typedef
name|struct
name|tag_TAU32_Controller
name|TAU32_Controller
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tag_TAU32_UserRequest
name|TAU32_UserRequest
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tag_TAU32_UserContext
name|TAU32_UserContext
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|union
name|tag_TAU32_tsc
name|TAU32_tsc
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|tag_TAU32_FlatIoContext
name|TAU32_FlatIoContext
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|TAU32_CALLBACK_TYPE
modifier|*
name|TAU32_RequestCallback
function_decl|)
parameter_list|(
name|TAU32_UserContext
modifier|*
name|pContext
parameter_list|,
name|TAU32_UserRequest
modifier|*
name|pUserRequest
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|TAU32_CALLBACK_TYPE
modifier|*
name|TAU32_NotifyCallback
function_decl|)
parameter_list|(
name|TAU32_UserContext
modifier|*
name|pContext
parameter_list|,
name|int
name|Item
parameter_list|,
name|unsigned
name|NotifyBits
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|TAU32_CALLBACK_TYPE
modifier|*
name|TAU32_FifoTrigger
function_decl|)
parameter_list|(
name|TAU32_UserContext
modifier|*
name|pContext
parameter_list|,
name|int
name|Interface
parameter_list|,
name|unsigned
name|FifoId
parameter_list|,
name|unsigned
name|Level
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|TAU32_CALLBACK_TYPE
modifier|*
name|TAU32_FlatIoCallback
function_decl|)
parameter_list|(
name|TAU32_UserContext
modifier|*
name|pContext
parameter_list|,
name|TAU32_FlatIoContext
modifier|*
name|pFlatIoContext
parameter_list|)
function_decl|;
end_typedef

begin_union
union|union
name|tag_TAU32_tsc
block|{
name|unsigned
name|__int32
name|osc
decl_stmt|,
name|sync
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|tag_TAU32_FlatIoContext
block|{
name|void
modifier|*
name|pInternal
decl_stmt|;
name|PCI_PHYSICAL_ADDRESS
name|PhysicalBufferAddress
decl_stmt|;
name|unsigned
name|Channel
decl_stmt|,
name|ItemsCount
decl_stmt|,
name|EachItemBufferSize
decl_stmt|;
name|unsigned
name|Received
decl_stmt|,
name|ActualOffset
decl_stmt|,
name|Errors
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_NTDDK_
argument_list|)
name|KDPC
name|CallbackDpc
decl_stmt|;
name|void
name|SetupCallback
parameter_list|(
name|PKDEFERRED_ROUTINE
name|DeferredCallbackRoutine
parameter_list|,
name|void
modifier|*
name|pContext
parameter_list|)
block|{
name|CallbackDpc
operator|.
name|DeferredRoutine
operator|=
name|DeferredCallbackRoutine
expr_stmt|;
name|CallbackDpc
operator|.
name|DeferredContext
operator|=
name|pContext
expr_stmt|;
block|}
name|void
name|SetupCallback
parameter_list|(
name|TAU32_FlatIoCallback
name|pCallback
parameter_list|)
block|{
name|CallbackDpc
operator|.
name|DeferredRoutine
operator|=
operator|(
name|PKDEFERRED_ROUTINE
operator|)
name|pCallback
expr_stmt|;
name|CallbackDpc
operator|.
name|DeferredContext
operator|=
literal|0
expr_stmt|;
block|}
else|#
directive|else
name|TAU32_FlatIoCallback
name|pCallback
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/* TAU32_FIFO_ID */
end_comment

begin_define
define|#
directive|define
name|TAU32_FifoId_CasRx
value|0u
end_define

begin_define
define|#
directive|define
name|TAU32_FifoId_CasTx
value|1u
end_define

begin_define
define|#
directive|define
name|TAU32_FifoId_FasRx
value|2u
end_define

begin_define
define|#
directive|define
name|TAU32_FifoId_FasTx
value|3u
end_define

begin_define
define|#
directive|define
name|TAU32_FifoId_Max
value|4u
end_define

begin_typedef
typedef|typedef
struct|struct
name|tag_TAU32_E1_State
block|{
name|unsigned
name|__int32
name|TickCounter
decl_stmt|;
name|unsigned
name|__int32
name|RxViolations
decl_stmt|;
name|unsigned
name|__int32
name|Crc4Errors
decl_stmt|;
name|unsigned
name|__int32
name|FarEndBlockErrors
decl_stmt|;
name|unsigned
name|__int32
name|FasErrors
decl_stmt|;
name|unsigned
name|__int32
name|TransmitSlips
decl_stmt|;
name|unsigned
name|__int32
name|ReceiveSlips
decl_stmt|;
name|unsigned
name|__int32
name|Status
decl_stmt|;
name|unsigned
name|__int32
name|FifoSlip
index|[
name|TAU32_FifoId_Max
index|]
decl_stmt|;
block|}
name|TAU32_E1_State
typedef|;
end_typedef

begin_struct
struct|struct
name|tag_TAU32_UserContext
block|{
comment|/* fields provided by user for for TAU32_Initiaize() */
name|TAU32_Controller
modifier|*
name|pControllerObject
decl_stmt|;
name|PCI_PHYSICAL_ADDRESS
name|ControllerObjectPhysicalAddress
decl_stmt|;
name|void
modifier|*
name|PciBar1VirtualAddress
decl_stmt|;
name|TAU32_NotifyCallback
name|pErrorNotifyCallback
decl_stmt|;
name|TAU32_NotifyCallback
name|pStatusNotifyCallback
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_NTDDK_
argument_list|)
name|PKINTERRUPT
name|InterruptObject
decl_stmt|;
endif|#
directive|endif
comment|/* TODO: remove from release */
define|#
directive|define
name|TAU32_CUSTOM_FIRMWARE
ifdef|#
directive|ifdef
name|TAU32_CUSTOM_FIRMWARE
name|void
modifier|*
name|pCustomFirmware
decl_stmt|;
name|unsigned
name|CustomFirmwareSize
decl_stmt|;
endif|#
directive|endif
comment|/* fields filled by TAU32_Initiaize() */
name|int
name|Model
decl_stmt|;
name|int
name|Interfaces
decl_stmt|;
name|unsigned
name|InitErrors
decl_stmt|;
name|unsigned
name|__int32
name|DeadBits
decl_stmt|;
comment|/* fields managed by DDK */
name|unsigned
name|AdapterStatus
decl_stmt|;
name|unsigned
name|CasIoLofCount
decl_stmt|;
name|unsigned
name|E1IntLostCount
decl_stmt|;
name|unsigned
name|CableTypeJumpers
decl_stmt|;
name|TAU32_E1_State
name|InterfacesInfo
index|[
name|TAU32_MAX_INTERFACES
index|]
decl_stmt|;
comment|/* fields which are't used by DDK, but nice for user */
ifdef|#
directive|ifdef
name|TAU32_UserContext_Add
name|TAU32_UserContext_Add
endif|#
directive|endif
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tag_TAU32_UserRequest
block|{
comment|/* required fields */
name|void
modifier|*
name|pInternal
decl_stmt|;
comment|/* internal */
name|unsigned
name|Command
decl_stmt|;
comment|/* in */
if|#
directive|if
name|defined
argument_list|(
name|_NTDDK_
argument_list|)
name|KDPC
name|CallbackDpc
decl_stmt|;
name|void
name|SetupCallback
parameter_list|(
name|PKDEFERRED_ROUTINE
name|DeferredCallbackRoutine
parameter_list|,
name|void
modifier|*
name|pContext
parameter_list|)
block|{
name|CallbackDpc
operator|.
name|DeferredRoutine
operator|=
name|DeferredCallbackRoutine
expr_stmt|;
name|CallbackDpc
operator|.
name|DeferredContext
operator|=
name|pContext
expr_stmt|;
block|}
name|void
name|SetupCallback
parameter_list|(
name|TAU32_RequestCallback
name|pCallback
parameter_list|)
block|{
name|CallbackDpc
operator|.
name|DeferredRoutine
operator|=
operator|(
name|PKDEFERRED_ROUTINE
operator|)
name|pCallback
expr_stmt|;
name|CallbackDpc
operator|.
name|DeferredContext
operator|=
literal|0
expr_stmt|;
block|}
else|#
directive|else
name|TAU32_RequestCallback
name|pCallback
decl_stmt|;
comment|/* in */
endif|#
directive|endif
name|unsigned
name|__int32
name|ErrorCode
decl_stmt|;
comment|/* out */
union|union
block|{
name|unsigned
name|ChannelNumber
decl_stmt|;
comment|/* just common field */
struct|struct
block|{
name|unsigned
name|Channel
decl_stmt|;
comment|/* in */
name|unsigned
name|__int32
name|Config
decl_stmt|;
comment|/* in */
name|unsigned
name|__int32
name|AssignedTsMask
decl_stmt|;
comment|/* build channel from timeslots which is selected by mask */
block|}
name|ChannelConfig
struct|;
struct|struct
block|{
name|int
name|Interface
decl_stmt|;
name|unsigned
name|__int32
name|Config
decl_stmt|;
comment|/* in */
name|unsigned
name|__int32
name|UnframedTsMask
decl_stmt|;
block|}
name|InterfaceConfig
struct|;
struct|struct
block|{
name|unsigned
name|Channel
decl_stmt|;
comment|/* in */
name|PCI_PHYSICAL_ADDRESS
name|PhysicalDataAddress
decl_stmt|;
comment|/* in */
name|unsigned
name|DataLength
decl_stmt|;
comment|/* in */
name|unsigned
name|Transmitted
decl_stmt|;
comment|/* out */
block|}
name|Tx
struct|;
struct|struct
block|{
name|unsigned
name|Channel
decl_stmt|;
comment|/* in */
name|PCI_PHYSICAL_ADDRESS
name|PhysicalDataAddress
decl_stmt|;
comment|/* in */
name|unsigned
name|BufferLength
decl_stmt|;
comment|/* in */
name|unsigned
name|Received
decl_stmt|;
comment|/* out */
name|BOOLEAN
name|FrameEnd
decl_stmt|;
comment|/* out */
block|}
name|Rx
struct|;
name|BOOLEAN
name|DigitalLoop
decl_stmt|;
comment|/* in, loop by PEB */
union|union
block|{
name|TAU32_TimeslotAssignment
name|Complete
index|[
name|TAU32_TIMESLOTS
index|]
decl_stmt|;
name|unsigned
name|__int32
name|Map
index|[
name|TAU32_CHANNELS
index|]
decl_stmt|;
block|}
name|TimeslotsAssignment
union|;
block|}
name|Io
union|;
comment|/* fields which are't used by DDK, but nice for user */
ifdef|#
directive|ifdef
name|TAU32_UserRequest_Add
name|TAU32_UserRequest_Add
endif|#
directive|endif
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TAU32_IS_REQUEST_RUNNING
parameter_list|(
name|pUserRequest
parameter_list|)
value|((pUserRequest)->pInternal != NULL)
end_define

begin_define
define|#
directive|define
name|TAU32_IS_REQUEST_NOT_RUNNING
parameter_list|(
name|pUserRequest
parameter_list|)
value|((pUserRequest)->pInternal == NULL)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TAU32_DDK_DLL
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_NTDDK_
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|TAU32_DDK_IMP
end_ifdef

begin_define
define|#
directive|define
name|TAU32_DDK_DLL
value|__declspec(dllexport)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TAU32_DDK_DLL
value|__declspec(dllimport)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TAU32_DDK_DLL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

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
name|void
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_BeforeReset
parameter_list|(
name|TAU32_UserContext
modifier|*
name|pUserContext
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_Initialize
parameter_list|(
name|TAU32_UserContext
modifier|*
name|pUserContext
parameter_list|,
name|BOOLEAN
name|CronyxDiag
parameter_list|)
function_decl|;
name|void
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_DestructiveHalt
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|BOOLEAN
name|CancelRequests
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_IsInterruptPending
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_HandleInterrupt
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|)
function_decl|;
specifier|extern
name|unsigned
specifier|const
name|TAU32_ControllerObjectSize
decl_stmt|;
comment|/* LY: ×ÓÅ ÆÕÎËÃÉÉ ÎÉÖÅ, ÍÏÇÕÔ ÒÅÅÎÔÅÒÁÂÅÌØÎÏ ×ÙÚÙ×ÁÔØÓÑ ÉÚ callback-Ï× */
name|void
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_EnableInterrupts
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|)
function_decl|;
name|void
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_DisableInterrupts
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_SubmitRequest
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|TAU32_UserRequest
modifier|*
name|pRequest
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_CancelRequest
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|TAU32_UserRequest
modifier|*
name|pRequest
parameter_list|,
name|BOOLEAN
name|BreakIfRunning
parameter_list|)
function_decl|;
name|void
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_LedBlink
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|)
function_decl|;
name|void
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_LedSet
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|BOOLEAN
name|On
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_SetCasIo
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|BOOLEAN
name|Enabled
parameter_list|)
function_decl|;
name|unsigned
name|__int64
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_ProbeGeneratorFrequency
parameter_list|(
name|unsigned
name|__int64
name|Frequency
parameter_list|)
function_decl|;
name|unsigned
name|__int64
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_SetGeneratorFrequency
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|unsigned
name|__int64
name|Frequency
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_SetSyncMode
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|unsigned
name|Mode
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_SetCrossMatrix
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|unsigned
name|__int8
modifier|*
name|pCrossMatrix
parameter_list|,
name|unsigned
name|__int32
name|ReverseMask
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_SetIdleCodes
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|unsigned
name|__int8
modifier|*
name|pIdleCodes
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_UpdateIdleCodes
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|int
name|Interface
parameter_list|,
name|unsigned
name|__int32
name|TimeslotMask
parameter_list|,
name|unsigned
name|__int8
name|IdleCode
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_SetSaCross
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|TAU32_SaCross
name|SaCross
parameter_list|)
function_decl|;
name|int
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_FifoPutCasAppend
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|int
name|Interface
parameter_list|,
name|unsigned
name|__int8
modifier|*
name|pBuffer
parameter_list|,
name|unsigned
name|Length
parameter_list|)
function_decl|;
name|int
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_FifoPutCasAhead
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|int
name|Interface
parameter_list|,
name|unsigned
name|__int8
modifier|*
name|pBuffer
parameter_list|,
name|unsigned
name|Length
parameter_list|)
function_decl|;
name|int
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_FifoGetCas
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|int
name|Interface
parameter_list|,
name|unsigned
name|__int8
modifier|*
name|pBuffer
parameter_list|,
name|unsigned
name|Length
parameter_list|)
function_decl|;
name|int
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_FifoPutFasAppend
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|int
name|Interface
parameter_list|,
name|unsigned
name|__int8
modifier|*
name|pBuffer
parameter_list|,
name|unsigned
name|Length
parameter_list|)
function_decl|;
name|int
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_FifoPutFasAhead
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|int
name|Interface
parameter_list|,
name|unsigned
name|__int8
modifier|*
name|pBuffer
parameter_list|,
name|unsigned
name|Length
parameter_list|)
function_decl|;
name|int
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_FifoGetFas
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|int
name|Interface
parameter_list|,
name|unsigned
name|__int8
modifier|*
name|pBuffer
parameter_list|,
name|unsigned
name|Length
parameter_list|)
function_decl|;
name|BOOLEAN
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_SetFifoTrigger
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|int
name|Interface
parameter_list|,
name|unsigned
name|FifoId
parameter_list|,
name|unsigned
name|Level
parameter_list|,
name|TAU32_FifoTrigger
name|Trigger
parameter_list|)
function_decl|;
name|void
name|TAU32_DDK_DLL
name|TAU32_CALL_TYPE
name|TAU32_ReadTsc
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|TAU32_tsc
modifier|*
name|pResult
parameter_list|)
function_decl|;
comment|/* for Cronyx Engineering use only !!! */
define|#
directive|define
name|TAU32_CRONYX_P
value|0
define|#
directive|define
name|TAU32_CRONYX_PS
value|1
define|#
directive|define
name|TAU32_CRONYX_PA
value|2
define|#
directive|define
name|TAU32_CRONYX_PB
value|3
define|#
directive|define
name|TAU32_CRONYX_I
value|4
define|#
directive|define
name|TAU32_CRONYX_O
value|5
define|#
directive|define
name|TAU32_CRONYX_U
value|6
define|#
directive|define
name|TAU32_CRONYX_R
value|7
define|#
directive|define
name|TAU32_CRONYX_W
value|8
define|#
directive|define
name|TAU32_CRONYX_RW
value|9
define|#
directive|define
name|TAU32_CRONYX_WR
value|10
define|#
directive|define
name|TAU32_CRONYX_S
value|11
define|#
directive|define
name|TAU32_CRONYX_G
value|12
name|unsigned
name|__int32
name|TAU32_CALL_TYPE
name|TAU32_Diag
parameter_list|(
name|TAU32_Controller
modifier|*
name|pControllerObject
parameter_list|,
name|unsigned
name|Operation
parameter_list|,
name|unsigned
name|__int32
name|Data
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

end_unit

