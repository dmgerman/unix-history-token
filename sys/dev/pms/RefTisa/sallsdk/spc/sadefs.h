begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************* *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.  * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the *following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided *with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED  *WARRANTIES,INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS *FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE *FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  *NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  *LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  *SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ********************************************************************************/
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_comment
comment|/*! \file  sadefs.h  *  \brief The file defines the constants used by LL layer  */
end_comment

begin_comment
comment|/*******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SADEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__SADEFS_H__
end_define

begin_define
define|#
directive|define
name|SA_LL_IBQ_PROTECT
end_define

begin_define
define|#
directive|define
name|AGSA_MAX_VALID_PORTS
value|AGSA_MAX_VALID_PHYS
end_define

begin_comment
comment|/**< defines the maximum number of ports */
end_comment

begin_define
define|#
directive|define
name|NUM_TIMERS
value|2
end_define

begin_comment
comment|/**< defines the maximum number of timers */
end_comment

begin_define
define|#
directive|define
name|SA_USECS_PER_TICK
value|1000000
end_define

begin_comment
comment|/**< defines the heart beat of the LL layer 1us */
end_comment

begin_define
define|#
directive|define
name|MAX_ACTIVE_IO_REQUESTS
value|4096
end_define

begin_comment
comment|/**< Maximum Active IO Requests */
end_comment

begin_define
define|#
directive|define
name|SMP_RESPONSE_FRAMES
value|AGSA_MAX_VALID_PHYS
end_define

begin_comment
comment|/**< SMP Response Frame Buffer */
end_comment

begin_define
define|#
directive|define
name|MAX_NUM_VECTOR
value|64
end_define

begin_comment
comment|/**< Maximum Number of Interrupt Vectors */
end_comment

begin_define
define|#
directive|define
name|REGISTER_DUMP_BUFF_SIZE
value|0x4000
end_define

begin_comment
comment|/**< Maximum Fatal Error Register Dump Buffer Size */
end_comment

begin_define
define|#
directive|define
name|KBYTES
value|1024
end_define

begin_comment
comment|/* number of IQ/OQ */
end_comment

begin_define
define|#
directive|define
name|IQ_NUM_32
value|32
end_define

begin_define
define|#
directive|define
name|OQ_NUM_32
value|32
end_define

begin_comment
comment|/* default value of Inbound/Outbound element size */
end_comment

begin_define
define|#
directive|define
name|INBOUND_DEPTH_SIZE
value|512
end_define

begin_define
define|#
directive|define
name|OUTBOUND_DEPTH_SIZE
value|512
end_define

begin_comment
comment|/* Priority of Queue */
end_comment

begin_define
define|#
directive|define
name|MPI_QUEUE_NORMAL
value|0
end_define

begin_define
define|#
directive|define
name|MPI_QUEUE_PRIORITY
value|1
end_define

begin_comment
comment|/* size of IOMB - multiple with 32 bytes */
end_comment

begin_define
define|#
directive|define
name|IOMB_SIZE64
value|64
end_define

begin_define
define|#
directive|define
name|IOMB_SIZE96
value|96
end_define

begin_define
define|#
directive|define
name|IOMB_SIZE128
value|128
end_define

begin_define
define|#
directive|define
name|IOMB_SIZE256
value|256
end_define

begin_comment
comment|/* DIR bit of IOMB for SSP read/write command */
end_comment

begin_define
define|#
directive|define
name|DIR_NODATA
value|0x000
end_define

begin_define
define|#
directive|define
name|DIR_READ
value|0x100
end_define

begin_define
define|#
directive|define
name|DIR_WRITE
value|0x200
end_define

begin_comment
comment|/* TLR bits mask */
end_comment

begin_define
define|#
directive|define
name|TLR_MASK
value|0x00000003
end_define

begin_comment
comment|/* port and phy Id bits Mask */
end_comment

begin_define
define|#
directive|define
name|PORTID_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|PORTID_V_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|PHYID_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|PHYID_V_MASK
value|0x000000FF
end_define

begin_define
define|#
directive|define
name|PORT_STATE_MASK
value|0x0000000F
end_define

begin_define
define|#
directive|define
name|PHY_IN_PORT_MASK
value|0x000000F0
end_define

begin_define
define|#
directive|define
name|SM_PHYID_MASK
value|(smIS_SPC(agRoot) ? PHYID_MASK  : PHYID_V_MASK )
end_define

begin_define
define|#
directive|define
name|SM_PORTID_MASK
value|(smIS_SPC(agRoot) ? PORTID_MASK : PORTID_V_MASK )
end_define

begin_comment
comment|/* the index for memory requirement, must be continious */
end_comment

begin_define
define|#
directive|define
name|LLROOT_MEM_INDEX
value|0
end_define

begin_comment
comment|/**< the index of root memory */
end_comment

begin_define
define|#
directive|define
name|DEVICELINK_MEM_INDEX
value|(LLROOT_MEM_INDEX + 1)
end_define

begin_comment
comment|/**< the index of device descriptors memory */
end_comment

begin_define
define|#
directive|define
name|IOREQLINK_MEM_INDEX
value|(DEVICELINK_MEM_INDEX+1)
end_define

begin_comment
comment|/**< the index of IO requests memory */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SA_ENABLE_HDA_FUNCTIONS
end_ifdef

begin_define
define|#
directive|define
name|HDA_DMA_BUFFER
value|(IOREQLINK_MEM_INDEX+1)
end_define

begin_comment
comment|/** HDA Buffer */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SA_ENABLE_HDA_FUNCTIONS */
end_comment

begin_define
define|#
directive|define
name|HDA_DMA_BUFFER
value|(IOREQLINK_MEM_INDEX)
end_define

begin_comment
comment|/** HDA Buffer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SA_ENABLE_HDA_FUNCTIONS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SA_ENABLE_TRACE_FUNCTIONS
end_ifdef

begin_define
define|#
directive|define
name|LL_FUNCTION_TRACE
value|(HDA_DMA_BUFFER+1)
end_define

begin_comment
comment|/**TraceLog */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SA_ENABLE_TRACE_FUNCTIONS */
end_comment

begin_define
define|#
directive|define
name|LL_FUNCTION_TRACE
value|HDA_DMA_BUFFER
end_define

begin_comment
comment|/**TraceLog */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END SA_ENABLE_TRACE_FUNCTIONS */
end_comment

begin_define
define|#
directive|define
name|TIMERLINK_MEM_INDEX
value|(LL_FUNCTION_TRACE+1)
end_define

begin_comment
comment|/**< the index of timers memory */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FAST_IO_TEST
end_ifdef

begin_define
define|#
directive|define
name|LL_FAST_IO
value|(TIMERLINK_MEM_INDEX+1)
end_define

begin_define
define|#
directive|define
name|MPI_IBQ_OBQ_INDEX
value|(LL_FAST_IO + 1)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FAST_IO_TEST */
end_comment

begin_define
define|#
directive|define
name|LL_FAST_IO
value|TIMERLINK_MEM_INDEX
end_define

begin_define
define|#
directive|define
name|MPI_IBQ_OBQ_INDEX
value|(LL_FAST_IO + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FAST_IO_TEST */
end_comment

begin_define
define|#
directive|define
name|MPI_MEM_INDEX
value|(MPI_IBQ_OBQ_INDEX - LLROOT_MEM_INDEX)
end_define

begin_define
define|#
directive|define
name|MPI_EVENTLOG_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|MPI_IOP_EVENTLOG_INDEX
value|1
end_define

begin_define
define|#
directive|define
name|MPI_CI_INDEX
value|2
end_define

begin_comment
comment|/* The following is a reference index */
end_comment

begin_define
define|#
directive|define
name|MPI_PI_INDEX
value|(MPI_CI_INDEX + 1)
end_define

begin_define
define|#
directive|define
name|MPI_IBQ_INDEX
value|(MPI_PI_INDEX + 1)
end_define

begin_define
define|#
directive|define
name|MPI_OBQ_INDEX
value|(MPI_IBQ_INDEX + MPI_MAX_INBOUND_QUEUES)
end_define

begin_define
define|#
directive|define
name|TOTAL_MPI_MEM_CHUNKS
value|(MPI_MAX_INBOUND_QUEUES * 2) + MPI_IBQ_INDEX
end_define

begin_define
define|#
directive|define
name|LL_DEVICE_LOCK
value|0
end_define

begin_define
define|#
directive|define
name|LL_PORT_LOCK
value|(LL_DEVICE_LOCK+1)
end_define

begin_define
define|#
directive|define
name|LL_TIMER_LOCK
value|(LL_PORT_LOCK+1)
end_define

begin_define
define|#
directive|define
name|LL_IOREQ_LOCKEQ_LOCK
value|(LL_TIMER_LOCK+1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FAST_IO_TEST
end_ifdef

begin_define
define|#
directive|define
name|LL_FAST_IO_LOCK
value|(LL_IOREQ_LOCKEQ_LOCK+1)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* FAST_IO_TEST   */
end_comment

begin_define
define|#
directive|define
name|LL_FAST_IO_LOCK
value|(LL_IOREQ_LOCKEQ_LOCK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FAST_IO_TEST   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SA_ENABLE_TRACE_FUNCTIONS
end_ifdef

begin_define
define|#
directive|define
name|LL_TRACE_LOCK
value|(LL_FAST_IO_LOCK+1)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SA_ENABLE_TRACE_FUNCTIONS   */
end_comment

begin_define
define|#
directive|define
name|LL_TRACE_LOCK
value|(LL_FAST_IO_LOCK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SA_ENABLE_TRACE_FUNCTIONS   */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MPI_DEBUG_TRACE_ENABLE
end_ifdef

begin_define
define|#
directive|define
name|LL_IOMB_TRACE_LOCK
value|(LL_TRACE_LOCK+1)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* MPI_DEBUG_TRACE_ENABLE */
end_comment

begin_define
define|#
directive|define
name|LL_IOMB_TRACE_LOCK
value|(LL_TRACE_LOCK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MPI_DEBUG_TRACE_ENABLE */
end_comment

begin_define
define|#
directive|define
name|LL_IOREQ_OBQ_LOCK
value|(LL_IOMB_TRACE_LOCK+1)
end_define

begin_define
define|#
directive|define
name|LL_IOREQ_IBQ_LOCK
value|(LL_IOREQ_OBQ_LOCK +1)
end_define

begin_define
define|#
directive|define
name|LL_IOREQ_IBQ_LOCK_PARM
value|(LL_IOREQ_OBQ_LOCK + queueConfig->numOutboundQueues  +1)
end_define

begin_define
define|#
directive|define
name|LL_IOREQ_IBQ0_LOCK
value|(LL_IOREQ_OBQ_LOCK + saRoot->QueueConfig.numOutboundQueues  +1)
end_define

begin_comment
comment|/* define phy states */
end_comment

begin_define
define|#
directive|define
name|PHY_STOPPED
value|0x00000000
end_define

begin_comment
comment|/**< flag indicates phy stopped */
end_comment

begin_define
define|#
directive|define
name|PHY_UP
value|0x00000001
end_define

begin_comment
comment|/**< flag indicates phy up */
end_comment

begin_define
define|#
directive|define
name|PHY_DOWN
value|0x00000002
end_define

begin_comment
comment|/**< flag indicates phy down */
end_comment

begin_comment
comment|/* define port states */
end_comment

begin_define
define|#
directive|define
name|PORT_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|PORT_INVALIDATING
value|0x0002
end_define

begin_comment
comment|/* define chip status */
end_comment

begin_define
define|#
directive|define
name|CHIP_NORMAL
value|0x0000
end_define

begin_define
define|#
directive|define
name|CHIP_SHUTDOWN
value|0x0001
end_define

begin_define
define|#
directive|define
name|CHIP_RESETTING
value|0x0002
end_define

begin_define
define|#
directive|define
name|CHIP_RESET_FW
value|0x0004
end_define

begin_define
define|#
directive|define
name|CHIP_FATAL_ERROR
value|0x0008
end_define

begin_comment
comment|/* define device types */
end_comment

begin_define
define|#
directive|define
name|SAS_SATA_UNKNOWN_DEVICE
value|0xFF
end_define

begin_comment
comment|/**< SAS SATA unknown device type */
end_comment

begin_define
define|#
directive|define
name|STP_DEVICE
value|0x00
end_define

begin_comment
comment|/**< SATA device behind an expander */
end_comment

begin_define
define|#
directive|define
name|SSP_SMP_DEVICE
value|0x01
end_define

begin_comment
comment|/**< SSP or SMP device type */
end_comment

begin_define
define|#
directive|define
name|DIRECT_SATA_DEVICE
value|0x02
end_define

begin_comment
comment|/**< SATA direct device type */
end_comment

begin_comment
comment|/* SATA */
end_comment

begin_define
define|#
directive|define
name|SATA_FIS_MASK
value|0x00000001
end_define

begin_define
define|#
directive|define
name|MAX_SATARESP_SUPPORT_BYTES
value|44
end_define

begin_define
define|#
directive|define
name|MARK_OFF
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|PORT_MARK_OFF
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|NO_FATAL_ERROR_VECTOR
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|SATA_PROTOCOL_RSRT_ASSERT
value|0x01
end_define

begin_define
define|#
directive|define
name|SATA_PROTOCOL_RSRT_DEASSERT
value|0x02
end_define

begin_define
define|#
directive|define
name|SATA_NON_DATA_PROTOCOL
value|0x0d
end_define

begin_define
define|#
directive|define
name|SATA_PIO_READ_PROTOCOL
value|0x0e
end_define

begin_define
define|#
directive|define
name|SATA_DMA_READ_PROTOCOL
value|0x0f
end_define

begin_define
define|#
directive|define
name|SATA_FPDMA_READ_PROTOCOL
value|0x10
end_define

begin_define
define|#
directive|define
name|SATA_PIO_WRITE_PROTOCOL
value|0x11
end_define

begin_define
define|#
directive|define
name|SATA_DMA_WRITE_PROTOCOL
value|0x12
end_define

begin_define
define|#
directive|define
name|SATA_FPDMA_WRITE_PROTOCOL
value|0x13
end_define

begin_define
define|#
directive|define
name|SATA_DEVICE_RESET_PROTOCOL
value|0x14
end_define

begin_comment
comment|/* Definition for bit shift */
end_comment

begin_define
define|#
directive|define
name|SHIFT0
value|0
end_define

begin_define
define|#
directive|define
name|SHIFT1
value|1
end_define

begin_define
define|#
directive|define
name|SHIFT2
value|2
end_define

begin_define
define|#
directive|define
name|SHIFT3
value|3
end_define

begin_define
define|#
directive|define
name|SHIFT4
value|4
end_define

begin_define
define|#
directive|define
name|SHIFT5
value|5
end_define

begin_define
define|#
directive|define
name|SHIFT6
value|6
end_define

begin_define
define|#
directive|define
name|SHIFT7
value|7
end_define

begin_define
define|#
directive|define
name|SHIFT8
value|8
end_define

begin_define
define|#
directive|define
name|SHIFT9
value|9
end_define

begin_define
define|#
directive|define
name|SHIFT10
value|10
end_define

begin_define
define|#
directive|define
name|SHIFT11
value|11
end_define

begin_define
define|#
directive|define
name|SHIFT12
value|12
end_define

begin_define
define|#
directive|define
name|SHIFT13
value|13
end_define

begin_define
define|#
directive|define
name|SHIFT14
value|14
end_define

begin_define
define|#
directive|define
name|SHIFT15
value|15
end_define

begin_define
define|#
directive|define
name|SHIFT16
value|16
end_define

begin_define
define|#
directive|define
name|SHIFT17
value|17
end_define

begin_define
define|#
directive|define
name|SHIFT18
value|18
end_define

begin_define
define|#
directive|define
name|SHIFT19
value|19
end_define

begin_define
define|#
directive|define
name|SHIFT20
value|20
end_define

begin_define
define|#
directive|define
name|SHIFT21
value|21
end_define

begin_define
define|#
directive|define
name|SHIFT22
value|22
end_define

begin_define
define|#
directive|define
name|SHIFT23
value|23
end_define

begin_define
define|#
directive|define
name|SHIFT24
value|24
end_define

begin_define
define|#
directive|define
name|SHIFT25
value|25
end_define

begin_define
define|#
directive|define
name|SHIFT26
value|26
end_define

begin_define
define|#
directive|define
name|SHIFT27
value|27
end_define

begin_define
define|#
directive|define
name|SHIFT28
value|28
end_define

begin_define
define|#
directive|define
name|SHIFT29
value|29
end_define

begin_define
define|#
directive|define
name|SHIFT30
value|30
end_define

begin_define
define|#
directive|define
name|SHIFT31
value|31
end_define

begin_comment
comment|/* These flags used for saSSPAbort(), saSATAAbort() */
end_comment

begin_define
define|#
directive|define
name|ABORT_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|ABORT_SINGLE
value|0x0
end_define

begin_define
define|#
directive|define
name|ABORT_SCOPE
value|0x3
end_define

begin_comment
comment|/* bits 0-1*/
end_comment

begin_define
define|#
directive|define
name|ABORT_ALL
value|0x1
end_define

begin_define
define|#
directive|define
name|ABORT_TSDK_QUARANTINE
value|0x4
end_define

begin_define
define|#
directive|define
name|ABORT_QUARANTINE_SPC
value|0x4
end_define

begin_define
define|#
directive|define
name|ABORT_QUARANTINE_SPCV
value|0x8
end_define

begin_comment
comment|/* These flags used for saGetRegDump() */
end_comment

begin_define
define|#
directive|define
name|REG_DUMP_NUM0
value|0x0
end_define

begin_define
define|#
directive|define
name|REG_DUMP_NUM1
value|0x1
end_define

begin_define
define|#
directive|define
name|REG_DUMP_NONFLASH
value|0x0
end_define

begin_define
define|#
directive|define
name|REG_DUMP_FLASH
value|0x1
end_define

begin_comment
comment|/* MSIX Interupts */
end_comment

begin_define
define|#
directive|define
name|MSIX_TABLE_OFFSET
value|0x2000
end_define

begin_define
define|#
directive|define
name|MSIX_TABLE_ELEMENT_SIZE
value|0x10
end_define

begin_define
define|#
directive|define
name|MSIX_INTERRUPT_CONTROL_OFFSET
value|0xC
end_define

begin_define
define|#
directive|define
name|MSIX_TABLE_BASE
value|(MSIX_TABLE_OFFSET+MSIX_INTERRUPT_CONTROL_OFFSET)
end_define

begin_define
define|#
directive|define
name|MSIX_INTERRUPT_DISABLE
value|0x1
end_define

begin_define
define|#
directive|define
name|MSIX_INTERRUPT_ENABLE
value|0x0
end_define

begin_define
define|#
directive|define
name|MAX_QUEUE_EACH_MEM
value|8
end_define

begin_define
define|#
directive|define
name|NUM_MEM_CHUNKS
parameter_list|(
name|Q
parameter_list|,
name|rem
parameter_list|)
value|((((bit32)Q % rem)> 0) ? (bit32)(Q/rem+1) : (bit32)(Q/rem))
end_define

begin_define
define|#
directive|define
name|NUM_QUEUES_IN_MEM
parameter_list|(
name|Q
parameter_list|,
name|rem
parameter_list|)
value|((((bit32)Q % rem)> 0) ? (bit32)(Q%rem) : (bit32)(MAX_QUEUE_EACH_MEM))
end_define

begin_define
define|#
directive|define
name|MAX_DEV_BITS
value|0xFFFF0000
end_define

begin_define
define|#
directive|define
name|PHY_COUNT_BITS
value|0x01f80000
end_define

begin_define
define|#
directive|define
name|Q_SUPPORT_BITS
value|0x0007ffff
end_define

begin_define
define|#
directive|define
name|SAS_SPEC_BITS
value|0xfe000000
end_define

begin_define
define|#
directive|define
name|HP_SUPPORT_BIT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|INT_COL_BIT
value|0x00040000
end_define

begin_define
define|#
directive|define
name|INT_DELAY_BITS
value|0xFFFF
end_define

begin_define
define|#
directive|define
name|INT_THR_BITS
value|0xFF
end_define

begin_define
define|#
directive|define
name|INT_VEC_BITS
value|0xFF
end_define

begin_define
define|#
directive|define
name|AUTO_HARD_RESET_DEREG_FLAG
value|0x00000001
end_define

begin_define
define|#
directive|define
name|AUTO_FW_CLEANUP_DEREG_FLAG
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BYTE_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|INT_OPTION
value|0x7FFF
end_define

begin_define
define|#
directive|define
name|SMP_TO_DEFAULT
value|100
end_define

begin_define
define|#
directive|define
name|ITL_TO_DEFAULT
value|0xFFFF
end_define

begin_comment
comment|/* agsaHwConfig_s  hwOption */
end_comment

begin_define
define|#
directive|define
name|HW_CFG_PICI_EFFECTIVE_ADDRESS
value|0x1
end_define

begin_comment
comment|/* SPC or SPCv ven dev Id */
end_comment

begin_define
define|#
directive|define
name|SUBID_SPC
value|0x00000000
end_define

begin_define
define|#
directive|define
name|SUBID_SPCV
value|0x56781234
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPC
value|0x80010000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_HIL
value|0x80810000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPCV
value|0x80080000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPCVE
value|0x80090000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPCVP
value|0x80180000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPCVEP
value|0x80190000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPC12V
value|0x80700000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPC12VE
value|0x80710000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPC12VP
value|0x80720000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SPC12VEP
value|0x80730000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_9015
value|0x90150000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_9060
value|0x90600000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_ADAPVEP
value|0x80890000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_ADAPVP
value|0x80880000
end_define

begin_define
define|#
directive|define
name|VEN_DEV_SFC
value|0x80250000
end_define

begin_comment
comment|/*DelRay PCIid */
end_comment

begin_define
define|#
directive|define
name|VEN_DEV_SPC12ADP
value|0x80740000
end_define

begin_comment
comment|/* 8 ports */
end_comment

begin_define
define|#
directive|define
name|VEN_DEV_SPC12ADPE
value|0x80750000
end_define

begin_comment
comment|/* 8 ports encrypt */
end_comment

begin_define
define|#
directive|define
name|VEN_DEV_SPC12ADPP
value|0x80760000
end_define

begin_comment
comment|/* 16 ports  */
end_comment

begin_define
define|#
directive|define
name|VEN_DEV_SPC12ADPEP
value|0x80770000
end_define

begin_comment
comment|/* 16 ports encrypt */
end_comment

begin_define
define|#
directive|define
name|VEN_DEV_SPC12SATA
value|0x80060000
end_define

begin_comment
comment|/* SATA HBA */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*__SADEFS_H__ */
end_comment

end_unit

