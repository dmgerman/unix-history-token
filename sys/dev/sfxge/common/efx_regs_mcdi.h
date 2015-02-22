begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2008-2011 Solarflare Communications Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SIENA_MC_DRIVER_PCOL_H
end_ifndef

begin_define
define|#
directive|define
name|_SIENA_MC_DRIVER_PCOL_H
end_define

begin_comment
comment|/* Values to be written into FMCR_CZ_RESET_STATE_REG to control boot. */
end_comment

begin_comment
comment|/* Power-on reset state */
end_comment

begin_define
define|#
directive|define
name|MC_FW_STATE_POR
value|(1)
end_define

begin_comment
comment|/* If this is set in MC_RESET_STATE_REG then it should be  * possible to jump into IMEM without loading code from flash. */
end_comment

begin_define
define|#
directive|define
name|MC_FW_WARM_BOOT_OK
value|(2)
end_define

begin_comment
comment|/* The MC main image has started to boot. */
end_comment

begin_define
define|#
directive|define
name|MC_FW_STATE_BOOTING
value|(4)
end_define

begin_comment
comment|/* The Scheduler has started. */
end_comment

begin_define
define|#
directive|define
name|MC_FW_STATE_SCHED
value|(8)
end_define

begin_comment
comment|/* Siena MC shared memmory offsets */
end_comment

begin_comment
comment|/* The 'doorbell' addresses are hard-wired to alert the MC when written */
end_comment

begin_define
define|#
directive|define
name|MC_SMEM_P0_DOORBELL_OFST
value|0x000
end_define

begin_define
define|#
directive|define
name|MC_SMEM_P1_DOORBELL_OFST
value|0x004
end_define

begin_comment
comment|/* The rest of these are firmware-defined */
end_comment

begin_define
define|#
directive|define
name|MC_SMEM_P0_PDU_OFST
value|0x008
end_define

begin_define
define|#
directive|define
name|MC_SMEM_P1_PDU_OFST
value|0x108
end_define

begin_define
define|#
directive|define
name|MC_SMEM_PDU_LEN
value|0x100
end_define

begin_define
define|#
directive|define
name|MC_SMEM_P0_PTP_TIME_OFST
value|0x7f0
end_define

begin_define
define|#
directive|define
name|MC_SMEM_P0_STATUS_OFST
value|0x7f8
end_define

begin_define
define|#
directive|define
name|MC_SMEM_P1_STATUS_OFST
value|0x7fc
end_define

begin_comment
comment|/* Values to be written to the per-port status dword in shared  * memory on reboot and assert */
end_comment

begin_define
define|#
directive|define
name|MC_STATUS_DWORD_REBOOT
value|(0xb007b007)
end_define

begin_define
define|#
directive|define
name|MC_STATUS_DWORD_ASSERT
value|(0xdeaddead)
end_define

begin_comment
comment|/* The current version of the MCDI protocol.  *  * Note that the ROM burnt into the card only talks V0, so at the very  * least every driver must support version 0 and MCDI_PCOL_VERSION  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_MCDI_V2
end_ifdef

begin_define
define|#
directive|define
name|MCDI_PCOL_VERSION
value|2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCDI_PCOL_VERSION
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Unused commands: 0x23, 0x27, 0x30, 0x31 */
end_comment

begin_comment
comment|/* MCDI version 1  *  * Each MCDI request starts with an MCDI_HEADER, which is a 32byte  * structure, filled in by the client.  *  *       0       7  8     16    20     22  23  24    31  *      | CODE | R | LEN | SEQ | Rsvd | E | R | XFLAGS |  *               |                      |   |  *               |                      |   \--- Response  *               |                      \------- Error  *               \------------------------------ Resync (always set)  *  * The client writes it's request into MC shared memory, and rings the  * doorbell. Each request is completed by either by the MC writting  * back into shared memory, or by writting out an event.  *  * All MCDI commands support completion by shared memory response. Each  * request may also contain additional data (accounted for by HEADER.LEN),  * and some response's may also contain additional data (again, accounted  * for by HEADER.LEN).  *  * Some MCDI commands support completion by event, in which any associated  * response data is included in the event.  *  * The protocol requires one response to be delivered for every request, a  * request should not be sent unless the response for the previous request  * has been received (either by polling shared memory, or by receiving  * an event).  */
end_comment

begin_comment
comment|/** Request/Response structure */
end_comment

begin_define
define|#
directive|define
name|MCDI_HEADER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_CODE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_CODE_WIDTH
value|7
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_RESYNC_LBN
value|7
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_RESYNC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_DATALEN_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_DATALEN_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_SEQ_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_RSVD_LBN
value|20
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_RSVD_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_SEQ_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_ERROR_LBN
value|22
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_ERROR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_RESPONSE_LBN
value|23
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_RESPONSE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_XFLAGS_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_XFLAGS_WIDTH
value|8
end_define

begin_comment
comment|/* Request response using event */
end_comment

begin_define
define|#
directive|define
name|MCDI_HEADER_XFLAGS_EVREQ
value|0x01
end_define

begin_comment
comment|/* Maximum number of payload bytes */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_MCDI_V2
end_ifdef

begin_define
define|#
directive|define
name|MCDI_CTL_SDU_LEN_MAX
value|0x400
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCDI_CTL_SDU_LEN_MAX
value|0xfc
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The MC can generate events for two reasons:  *   - To complete a shared memory request if XFLAGS_EVREQ was set  *   - As a notification (link state, i2c event), controlled  *     via MC_CMD_LOG_CTRL  *  * Both events share a common structure:  *  *  0      32     33      36    44     52     60  * | Data | Cont | Level | Src | Code | Rsvd |  *           |  *           \ There is another event pending in this notification  *  * If Code==CMDDONE, then the fields are further interpreted as:  *  *   - LEVEL==INFO    Command succeeded  *   - LEVEL==ERR     Command failed  *  *    0     8         16      24     32  *   | Seq | Datalen | Errno | Rsvd |  *  *   These fields are taken directly out of the standard MCDI header, i.e.,  *   LEVEL==ERR, Datalen == 0 => Reboot  *  * Events can be squirted out of the UART (using LOG_CTRL) without a  * MCDI header.  An event can be distinguished from a MCDI response by  * examining the first byte which is 0xc0.  This corresponds to the  * non-existent MCDI command MC_CMD_DEBUG_LOG.  *  *      0         7        8  *     | command | Resync |     = 0xc0  *  * Since the event is written in big-endian byte order, this works  * providing bits 56-63 of the event are 0xc0.  *  *      56     60  63  *     | Rsvd | Code |    = 0xc0  *  * Which means for convenience the event code is 0xc for all MC  * generated events.  */
end_comment

begin_define
define|#
directive|define
name|FSE_AZ_EV_CODE_MCDI_EVRESPONSE
value|0xc
end_define

begin_comment
comment|/* Non-existent command target */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ENOENT
value|2
end_define

begin_comment
comment|/* assert() has killed the MC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EINTR
value|4
end_define

begin_comment
comment|/* Caller does not hold required locks */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EACCES
value|13
end_define

begin_comment
comment|/* Resource is currently unavailable (e.g. lock contention) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EBUSY
value|16
end_define

begin_comment
comment|/* Invalid argument to target */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EINVAL
value|22
end_define

begin_comment
comment|/* Non-recursive resource is already acquired */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EDEADLK
value|35
end_define

begin_comment
comment|/* Operation not implemented */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ENOSYS
value|38
end_define

begin_comment
comment|/* Operation timed out */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ETIME
value|62
end_define

begin_define
define|#
directive|define
name|MC_CMD_ERR_CODE_OFST
value|0
end_define

begin_comment
comment|/* We define 8 "escape" commands to allow    for command number space extension */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CMD_SPACE_ESCAPE_0
value|0x78
end_define

begin_define
define|#
directive|define
name|MC_CMD_CMD_SPACE_ESCAPE_1
value|0x79
end_define

begin_define
define|#
directive|define
name|MC_CMD_CMD_SPACE_ESCAPE_2
value|0x7A
end_define

begin_define
define|#
directive|define
name|MC_CMD_CMD_SPACE_ESCAPE_3
value|0x7B
end_define

begin_define
define|#
directive|define
name|MC_CMD_CMD_SPACE_ESCAPE_4
value|0x7C
end_define

begin_define
define|#
directive|define
name|MC_CMD_CMD_SPACE_ESCAPE_5
value|0x7D
end_define

begin_define
define|#
directive|define
name|MC_CMD_CMD_SPACE_ESCAPE_6
value|0x7E
end_define

begin_define
define|#
directive|define
name|MC_CMD_CMD_SPACE_ESCAPE_7
value|0x7F
end_define

begin_comment
comment|/* Vectors in the boot ROM */
end_comment

begin_comment
comment|/* Point to the copycode entry point. */
end_comment

begin_define
define|#
directive|define
name|MC_BOOTROM_COPYCODE_VEC
value|(0x7f4)
end_define

begin_comment
comment|/* Points to the recovery mode entry point. */
end_comment

begin_define
define|#
directive|define
name|MC_BOOTROM_NOFLASH_VEC
value|(0x7f8)
end_define

begin_comment
comment|/* The command set exported by the boot ROM (MCDI v0) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_V0_SUPPORTED_FUNCS
value|{		\ 	(1<< MC_CMD_READ32)	|			\ 	(1<< MC_CMD_WRITE32)	|			\ 	(1<< MC_CMD_COPYCODE)	|			\ 	(1<< MC_CMD_GET_VERSION),			\ 	0, 0, 0 }
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_OUT_OFFSET_OFST
parameter_list|(
name|_x
parameter_list|)
define|\
value|(MC_CMD_SENSOR_ENTRY_OFST + (_x))
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_ADDRESS_OFST
parameter_list|(
name|n
parameter_list|)
value|(  \         (MC_CMD_DBI_WRITE_IN_DBIWROP_OFST+     \          MC_CMD_DBIWROP_TYPEDEF_ADDRESS_OFST)+ \          ((n)*MC_CMD_DBIWROP_TYPEDEF_LEN))
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_BYTE_MASK_OFST
parameter_list|(
name|n
parameter_list|)
value|(  \         (MC_CMD_DBI_WRITE_IN_DBIWROP_OFST+     \          MC_CMD_DBIWROP_TYPEDEF_BYTE_MASK_OFST)+ \          ((n)*MC_CMD_DBIWROP_TYPEDEF_LEN))
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_VALUE_OFST
parameter_list|(
name|n
parameter_list|)
value|(  \         (MC_CMD_DBI_WRITE_IN_DBIWROP_OFST+     \          MC_CMD_DBIWROP_TYPEDEF_VALUE_OFST)+ \          ((n)*MC_CMD_DBIWROP_TYPEDEF_LEN))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_MCDI_V2
end_ifdef

begin_comment
comment|/* Version 2 adds an optional argument to error returns: the errno value  * may be followed by the (0-based) number of the first argument that  * could not be processed.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ARG_OFST
value|4
end_define

begin_comment
comment|/* Try again */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EAGAIN
value|11
end_define

begin_comment
comment|/* No space */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ENOSPC
value|28
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MCDI_EVENT structuredef */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CONT_LBN
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CONT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LEVEL_LBN
value|33
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LEVEL_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LEVEL_INFO
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LEVEL_WARN
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LEVEL_ERR
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LEVEL_FATAL
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CMDDONE_SEQ_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CMDDONE_SEQ_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CMDDONE_DATALEN_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CMDDONE_DATALEN_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CMDDONE_ERRNO_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CMDDONE_ERRNO_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_LP_CAP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_LP_CAP_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_SPEED_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_SPEED_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_SPEED_100M
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_SPEED_1G
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_SPEED_10G
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_FCNTL_LBN
value|20
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_FCNTL_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_LINK_FLAGS_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_LINK_FLAGS_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_SENSOREVT_MONITOR_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_SENSOREVT_MONITOR_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_SENSOREVT_STATE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_SENSOREVT_STATE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_SENSOREVT_VALUE_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_SENSOREVT_VALUE_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_FWALERT_DATA_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_FWALERT_DATA_WIDTH
value|24
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_FWALERT_REASON_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_FWALERT_REASON_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_FWALERT_REASON_SRAM_ACCESS
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_FLR_VF_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_FLR_VF_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_TXQ_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_TXQ_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_TYPE_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_TYPE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_DL_FAIL
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_NO_EOP
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_2BIG
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_INFO_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_INFO_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_FLUSH_TXQ_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_FLUSH_TXQ_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_ERR_TYPE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_ERR_TYPE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_ERR_PLL_LOST
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_ERR_FILTER
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_ERR_FIFO
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_ERR_QUEUE
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_ERR_TYPE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_ERR_TYPE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_NO_LOAD
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_FC_ASSERT
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_FC_WATCHDOG
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_FC_NO_START
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_FAULT
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_CPLD_REPROGRAMMED
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_LOAD
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_DMA
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_BYTEBLASTER
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_DDR_ECC_STATUS
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_PTP_STATUS
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_ERR_DATA_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_ERR_DATA_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_SRC_LBN
value|36
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_SRC_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_EV_CODE_LBN
value|60
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_EV_CODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_LBN
value|44
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_BADSSERT
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PMNOTICE
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_CMDDONE
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_LINKCHANGE
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_SENSOREVT
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_SCHEDERR
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_REBOOT
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_MAC_STATS_DMA
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_FWALERT
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_FLR
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_TX_ERR
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_TX_FLUSH
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PTP_RX
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PTP_FAULT
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PTP_PPS
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_AOE
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_VCAL_FAIL
value|0x13
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_HW_PPS
value|0x14
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CMDDONE_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CMDDONE_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_CMDDONE_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_SENSOREVT_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_SENSOREVT_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_SENSOREVT_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_MAC_STATS_DMA_GENERATION_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_MAC_STATS_DMA_GENERATION_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_MAC_STATS_DMA_GENERATION_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_SECONDS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_SECONDS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_SECONDS_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_NANOSECONDS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_NANOSECONDS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_NANOSECONDS_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_UUID_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_UUID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_UUID_WIDTH
value|32
end_define

begin_comment
comment|/* FCDI_EVENT structuredef */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_CONT_LBN
value|32
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_CONT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_LEVEL_LBN
value|33
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_LEVEL_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_LEVEL_INFO
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_LEVEL_WARN
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_LEVEL_ERR
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_LEVEL_FATAL
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_LINK_STATE_STATUS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_LINK_STATE_STATUS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_LINK_DOWN
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_LINK_UP
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_SRC_LBN
value|36
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_SRC_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_EV_CODE_LBN
value|60
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_EV_CODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_LBN
value|44
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_REBOOT
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_ASSERT
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_DDR_TEST_RESULT
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_LINK_STATE
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_TIMED_READ
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_PPS_IN
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_PTP_TICK
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_DDR_ECC_STATUS
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_PTP_STATUS
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_ASSERT_INSTR_ADDRESS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_ASSERT_INSTR_ADDRESS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_ASSERT_INSTR_ADDRESS_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_ASSERT_TYPE_LBN
value|36
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_ASSERT_TYPE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_DDR_TEST_RESULT_STATUS_CODE_LBN
value|36
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_DDR_TEST_RESULT_STATUS_CODE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_DDR_TEST_RESULT_RESULT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_DDR_TEST_RESULT_RESULT_LBN
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_DDR_TEST_RESULT_RESULT_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_LINK_STATE_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_LINK_STATE_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_LINK_STATE_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_PTP_STATE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_PTP_UNDEFINED
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_PTP_SETUP_FAILED
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_PTP_OPERATIONAL
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_PTP_STATE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_PTP_STATE_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_DDR_ECC_STATUS_BANK_ID_LBN
value|36
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_DDR_ECC_STATUS_BANK_ID_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_DDR_ECC_STATUS_STATUS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_DDR_ECC_STATUS_STATUS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_DDR_ECC_STATUS_STATUS_WIDTH
value|32
end_define

begin_comment
comment|/* FCDI_EXTENDED_EVENT_PPS structuredef */
end_comment

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_LENMIN
value|16
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_LENMAX
value|248
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_LEN
parameter_list|(
name|num
parameter_list|)
value|(8+8*(num))
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_COUNT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_COUNT_LBN
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_COUNT_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_SECONDS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_SECONDS_LBN
value|64
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_SECONDS_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_NANOSECONDS_OFST
value|12
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_NANOSECONDS_LBN
value|96
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_NANOSECONDS_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_TIMESTAMPS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_TIMESTAMPS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_TIMESTAMPS_LO_OFST
value|8
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_TIMESTAMPS_HI_OFST
value|12
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_TIMESTAMPS_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_TIMESTAMPS_MAXNUM
value|30
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_TIMESTAMPS_LBN
value|64
end_define

begin_define
define|#
directive|define
name|FCDI_EXTENDED_EVENT_PPS_TIMESTAMPS_WIDTH
value|64
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_READ32  * Read multiple 32byte words from MC memory.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ32
value|0x1
end_define

begin_comment
comment|/* MC_CMD_READ32_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ32_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ32_IN_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ32_IN_NUMWORDS_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_READ32_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ32_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ32_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ32_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ32_OUT_BUFFER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ32_OUT_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ32_OUT_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ32_OUT_BUFFER_MAXNUM
value|63
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_WRITE32  * Write multiple 32byte words to MC memory.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WRITE32
value|0x2
end_define

begin_comment
comment|/* MC_CMD_WRITE32_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WRITE32_IN_LENMIN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_WRITE32_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_WRITE32_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_WRITE32_IN_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_WRITE32_IN_BUFFER_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_WRITE32_IN_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_WRITE32_IN_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_WRITE32_IN_BUFFER_MAXNUM
value|62
end_define

begin_comment
comment|/* MC_CMD_WRITE32_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WRITE32_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_COPYCODE  * Copy MC code between two locations and jump.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE
value|0x3
end_define

begin_comment
comment|/* MC_CMD_COPYCODE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_SRC_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_DEST_ADDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_NUMWORDS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_JUMP_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_JUMP_NONE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_COPYCODE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_FUNC   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_FUNC
value|0x4
end_define

begin_comment
comment|/* MC_CMD_SET_FUNC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_FUNC_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_FUNC_IN_FUNC_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_SET_FUNC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_FUNC_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_BOOT_STATUS  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS
value|0x5
end_define

begin_comment
comment|/* MC_CMD_GET_BOOT_STATUS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_BOOT_STATUS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_OUT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_OUT_BOOT_OFFSET_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_OUT_FLAGS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_OUT_FLAGS_WATCHDOG_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_OUT_FLAGS_WATCHDOG_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_OUT_FLAGS_PRIMARY_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_OUT_FLAGS_PRIMARY_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_OUT_FLAGS_BACKUP_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_OUT_FLAGS_BACKUP_WIDTH
value|1
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_ASSERTS   * Get and clear any assertion status.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS
value|0x6
end_define

begin_comment
comment|/* MC_CMD_GET_ASSERTS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_IN_CLEAR_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_ASSERTS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_OUT_LEN
value|140
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_OUT_GLOBAL_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_FLAGS_NO_FAILS
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_FLAGS_SYS_FAIL
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_FLAGS_THR_FAIL
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_FLAGS_WDOG_FIRED
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_OUT_SAVED_PC_OFFS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_OUT_GP_REGS_OFFS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_OUT_GP_REGS_OFFS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_OUT_GP_REGS_OFFS_NUM
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_OUT_THREAD_OFFS_OFST
value|132
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_OUT_RESERVED_OFST
value|136
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_LOG_CTRL   * Configure the output stream for various events and messages.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOG_CTRL
value|0x7
end_define

begin_comment
comment|/* MC_CMD_LOG_CTRL_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOG_CTRL_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_LOG_CTRL_IN_LOG_DEST_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LOG_CTRL_IN_LOG_DEST_UART
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOG_CTRL_IN_LOG_DEST_EVQ
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOG_CTRL_IN_LOG_DEST_EVQ_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_LOG_CTRL_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOG_CTRL_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_VERSION   * Get version information about the MC firmware.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION
value|0x8
end_define

begin_comment
comment|/* MC_CMD_GET_VERSION_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_VERSION_V0_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_V0_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_FIRMWARE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_FIRMWARE_ANY
value|0xffffffff
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_FIRMWARE_BOOTROM
value|0xb0070000
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_FIRMWARE_SIENA_BOOTROM
value|0xb0070000
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_FIRMWARE_HUNT_BOOTROM
value|0xb0070001
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_GET_VERSION_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_LEN
value|32
end_define

begin_comment
comment|/*            MC_CMD_GET_VERSION_OUT_FIRMWARE_OFST 0 */
end_comment

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_GET_VERSION_V0_OUT/MC_CMD_GET_VERSION_OUT_FIRMWARE */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_PCOL_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_SUPPORTED_FUNCS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_SUPPORTED_FUNCS_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_VERSION_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_VERSION_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_VERSION_LO_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_VERSION_HI_OFST
value|28
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FC   * Perform an FC operation  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC
value|0x9
end_define

begin_comment
comment|/* MC_CMD_FC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_OP_HDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_OP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_OP_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_NULL
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UNUSED
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_READ32
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_WRITE32
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TRC_READ
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TRC_WRITE
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_GET_VERSION
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TRC_RX_READ
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TRC_RX_WRITE
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_SFP
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_GET_ASSERT
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_FPGA_BUILD
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_READ_MAP
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_CAPABILITIES
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_GLOBAL_FLAGS
value|0x11
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_IO_REL
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK
value|0x13
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_SET_LINK
value|0x14
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_LICENSE
value|0x15
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_STARTUP
value|0x16
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DMA
value|0x17
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TIMED_READ
value|0x18
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_LOG
value|0x19
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_CLOCK
value|0x1a
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR
value|0x1b
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TIMESTAMP
value|0x1c
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_SPI
value|0x1d
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DIAG
value|0x1e
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_PORT_EXT_OFST
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_PORT_INT_OFST
value|0x40
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_NULL msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_NULL_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CMD_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_IN_MAC msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_HEADER_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_OP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_OP_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_RECONFIGURE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_SET_LINK
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_GET_STATS
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_GET_RX_STATS
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_GET_TX_STATS
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_READ_STATUS
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_PORT_TYPE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_PORT_TYPE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_PORT_EXT
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_PORT_INT
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_PORT_IDX_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_PORT_IDX_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_CMD_FORMAT_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_CMD_FORMAT_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_CMD_FORMAT_DEFAULT
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_CMD_FORMAT_PORT_OVERRIDE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_MAC_RECONFIGURE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_RECONFIGURE_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_MAC_SET_LINK msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_LEN
value|32
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_MTU_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_DRAIN_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_ADDR_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_ADDR_LO_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_ADDR_HI_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_REJECT_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_REJECT_UNICAST_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_REJECT_UNICAST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_REJECT_BRDCAST_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_REJECT_BRDCAST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_FCNTL_OFST
value|28
end_define

begin_comment
comment|/* MC_CMD_FC_IN_MAC_READ_STATUS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_READ_STATUS_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_MAC_GET_RX_STATS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_RX_STATS_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_MAC_GET_TX_STATS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_TX_STATS_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_MAC_GET_STATS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_STATS_LEN
value|20
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_MAC_HEADER_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_STATS_STATS_INDEX_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_STATS_FLAGS_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_STATS_CLEAR_ALL_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_STATS_CLEAR_ALL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_STATS_CLEAR_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_STATS_CLEAR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_STATS_UPDATE_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_STATS_UPDATE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_GET_STATS_NUM_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_NSTATS_PER_BLOCK
value|0x1e
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_NBYTES_PER_STAT
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_READ32 msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_READ32_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_READ32_ADDR_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_READ32_ADDR_LO_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_READ32_NUMWORDS_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_FC_IN_WRITE32 msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_WRITE32_LENMIN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_WRITE32_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_WRITE32_LEN
parameter_list|(
name|num
parameter_list|)
value|(12+4*(num))
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_WRITE32_ADDR_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_WRITE32_ADDR_LO_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_WRITE32_BUFFER_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_WRITE32_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_WRITE32_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_WRITE32_BUFFER_MAXNUM
value|60
end_define

begin_comment
comment|/* MC_CMD_FC_IN_TRC_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_READ_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_READ_TRC_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_READ_CHANNEL_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_FC_IN_TRC_WRITE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_WRITE_LEN
value|28
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_WRITE_TRC_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_WRITE_CHANNEL_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_WRITE_DATA_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_WRITE_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_WRITE_DATA_NUM
value|4
end_define

begin_comment
comment|/* MC_CMD_FC_IN_GET_VERSION msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GET_VERSION_LEN
value|4
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_TRC_RX_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_RX_READ_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_RX_READ_TRC_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_RX_READ_CHANNEL_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_FC_IN_TRC_RX_WRITE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_RX_WRITE_LEN
value|20
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_RX_WRITE_TRC_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_RX_WRITE_CHANNEL_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_RX_WRITE_DATA_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_RX_WRITE_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TRC_RX_WRITE_DATA_NUM
value|2
end_define

begin_comment
comment|/* MC_CMD_FC_IN_SFP msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_LEN
value|24
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_SPEED_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_COPPER_LEN_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_DUAL_SPEED_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_PRESENT_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_TYPE_OFST
value|20
end_define

begin_comment
comment|/* MC_CMD_FC_IN_DDR_TEST msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_HEADER_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_OP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_OP_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_START
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_POLL
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_DDR_TEST_START msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_START_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_DDR_TEST_HEADER_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_START_MASK_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_START_T0_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_START_T0_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_START_T1_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_START_T1_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_START_B0_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_START_B0_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_START_B1_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_START_B1_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_FC_IN_DDR_TEST_POLL msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_POLL_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_TEST_CMD_OFST
value|0
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_DDR_TEST_HEADER_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_GET_ASSERT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GET_ASSERT_LEN
value|4
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_FPGA_BUILD msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_FPGA_BUILD_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_FPGA_BUILD_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_FPGA_BUILD_BUILD
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_FPGA_BUILD_SERVICES
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_FPGA_BUILD_BSP_VERSION
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_READ_MAP msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_READ_MAP_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_READ_MAP_HEADER_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_READ_MAP_OP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_READ_MAP_OP_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_READ_MAP_COUNT
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_READ_MAP_INDEX
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_READ_MAP_COUNT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_READ_MAP_COUNT_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_READ_MAP_HEADER_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_READ_MAP_INDEX msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_READ_MAP_INDEX_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_READ_MAP_HEADER_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAP_INDEX_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_FC_IN_CAPABILITIES msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CAPABILITIES_LEN
value|4
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_GLOBAL_FLAGS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_FLAGS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_RX_TUNING_CABLE_PLUGGED_IN_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_RX_TUNING_CABLE_PLUGGED_IN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_RX_TUNING_LINK_MONITORING_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_RX_TUNING_LINK_MONITORING_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_DFE_ENABLE_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_DFE_ENABLE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_1D_EYE_ENABLE_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_1D_EYE_ENABLE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_1D_TUNING_ENABLE_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_1D_TUNING_ENABLE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_OFFCAL_ENABLE_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_GLOBAL_FLAGS_OFFCAL_ENABLE_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_FC_IN_IO_REL msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_HEADER_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_OP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_OP_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_GET_ADDR
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_READ32
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_WRITE32
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_COMP_TYPE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_COMP_TYPE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_COMP_TYPE_APP_ADDR_SPACE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_COMP_TYPE_FLASH
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_IO_REL_GET_ADDR msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_GET_ADDR_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_IO_REL_HEADER_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_IO_REL_READ32 msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_READ32_LEN
value|20
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_IO_REL_HEADER_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_READ32_ADDR_HI_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_READ32_ADDR_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_READ32_NUMWORDS_OFST
value|16
end_define

begin_comment
comment|/* MC_CMD_FC_IN_IO_REL_WRITE32 msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_WRITE32_LENMIN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_WRITE32_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_WRITE32_LEN
parameter_list|(
name|num
parameter_list|)
value|(16+4*(num))
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_IO_REL_HEADER_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_WRITE32_ADDR_HI_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_WRITE32_ADDR_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_WRITE32_BUFFER_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_WRITE32_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_WRITE32_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_WRITE32_BUFFER_MAXNUM
value|59
end_define

begin_comment
comment|/* MC_CMD_FC_IN_UHLINK msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_UHLINK_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_UHLINK_HEADER_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_UHLINK_OP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_UHLINK_OP_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_PHY
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_MAC
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_RX_EYE
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_DUMP_RX_EYE_PLOT
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_RX_TUNE
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_LOOPBACK_SET
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_LOOPBACK_GET
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_UHLINK_PORT_TYPE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_UHLINK_PORT_TYPE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_UHLINK_PORT_IDX_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_UHLINK_PORT_IDX_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_UHLINK_CMD_FORMAT_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_UHLINK_CMD_FORMAT_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_CMD_FORMAT_DEFAULT
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_CMD_FORMAT_PORT_OVERRIDE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_OP_UHLINK_PHY msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_PHY_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_FC_OP_UHLINK_MAC msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_MAC_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_FC_OP_UHLINK_RX_EYE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_RX_EYE_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_RX_EYE_INDEX_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_UHLINK_RX_EYE_PER_BLOCK
value|0x30
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_OP_UHLINK_DUMP_RX_EYE_PLOT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_DUMP_RX_EYE_PLOT_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT_LEN
value|20
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT_DC_GAIN_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT_EQ_CONTROL_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT_INDEX_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_UHLINK_RX_EYE_PLOT_ROWS_PER_BLOCK
value|0x1e
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_OP_UHLINK_RX_TUNE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_RX_TUNE_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_FC_OP_UHLINK_LOOPBACK_SET msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_LOOPBACK_SET_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_LOOPBACK_SET_TYPE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_UHLINK_LOOPBACK_TYPE_PCS_SERIAL
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_UHLINK_LOOPBACK_TYPE_PMA_PRE_CDR
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_UHLINK_LOOPBACK_TYPE_PMA_POST_CDR
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_LOOPBACK_SET_STATE_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_UHLINK_LOOPBACK_STATE_OFF
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_UHLINK_LOOPBACK_STATE_ON
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_OP_UHLINK_LOOPBACK_GET msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_LOOPBACK_GET_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_UHLINK_HEADER_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_LOOPBACK_GET_TYPE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_FC_IN_SET_LINK msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SET_LINK_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SET_LINK_MODE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SET_LINK_SPEED_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SET_LINK_FLAGS_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SET_LINK_LOWPOWER_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SET_LINK_LOWPOWER_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SET_LINK_POWEROFF_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SET_LINK_POWEROFF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SET_LINK_TXDIS_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SET_LINK_TXDIS_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_FC_IN_LICENSE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LICENSE_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LICENSE_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LICENSE_UPDATE_LICENSE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LICENSE_GET_KEY_STATS
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_STARTUP msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_STARTUP_LEN
value|40
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_STARTUP_BASE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_STARTUP_LENGTH_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_STARTUP_IDLENGTH_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_STARTUP_ID_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_STARTUP_ID_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_STARTUP_ID_NUM
value|24
end_define

begin_comment
comment|/* MC_CMD_FC_IN_DMA msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DMA_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DMA_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DMA_STOP
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DMA_READ
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_DMA_STOP msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DMA_STOP_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_DMA_OP_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DMA_STOP_FC_HANDLE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_FC_IN_DMA_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DMA_READ_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_DMA_OP_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DMA_READ_OFFSET_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DMA_READ_LENGTH_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_FC_IN_TIMED_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_GET
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_CLEAR
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_TIMED_READ_SET msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_LEN
value|52
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_TIMED_READ_OP_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_HOST_HANDLE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_HOST_DMA_ADDRESS_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_HOST_DMA_ADDRESS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_HOST_DMA_ADDRESS_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_HOST_DMA_ADDRESS_HI_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_AOE_ADDRESS_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_AOE_ADDRESS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_AOE_ADDRESS_LO_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_AOE_ADDRESS_HI_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_AOE_LENGTH_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_HOST_LENGTH_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_OFFSET_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_DATA_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_FLAGS_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_INDIRECT_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_INDIRECT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_DOUBLE_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_DOUBLE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_EVENT_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_EVENT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_PREREAD_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_PREREAD_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_NONE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_READ
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_WRITE
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_READWRITE
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_PERIOD_OFST
value|48
end_define

begin_comment
comment|/* MC_CMD_FC_IN_TIMED_READ_GET msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_GET_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_TIMED_READ_OP_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_GET_FC_HANDLE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_FC_IN_TIMED_READ_CLEAR msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_CLEAR_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_TIMED_READ_OP_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_CLEAR_FC_HANDLE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_FC_IN_LOG msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_ADDR_RANGE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_JTAG_UART
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_LOG_ADDR_RANGE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_ADDR_RANGE_LEN
value|20
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_LOG_OP_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_ADDR_RANGE_OFFSET_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_ADDR_RANGE_LENGTH_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_ADDR_RANGE_ERASE_SIZE_OFST
value|16
end_define

begin_comment
comment|/* MC_CMD_FC_IN_LOG_JTAG_UART msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_JTAG_UART_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_LOG_OP_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_JTAG_UART_ENABLE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_FC_IN_CLOCK msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_GET_TIME
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_SET_TIME
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_ID_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_STATS
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_MAC
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_CLOCK_GET_TIME msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_GET_TIME_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_CLOCK_OP_OFST 4 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_CLOCK_ID_OFST 8 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_CLOCK_SET_TIME msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_SET_TIME_LEN
value|24
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_CLOCK_OP_OFST 4 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_CLOCK_ID_OFST 8 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_SET_TIME_SECONDS_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_SET_TIME_SECONDS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_SET_TIME_SECONDS_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_SET_TIME_SECONDS_HI_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_CLOCK_SET_TIME_NANOSECONDS_OFST
value|20
end_define

begin_comment
comment|/* MC_CMD_FC_IN_DDR msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_SET_SPD
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_GET_STATUS
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_BANK_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_BANK_B0
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_BANK_B1
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_BANK_T0
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_BANK_T1
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_NUM_BANKS
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_DDR_SET_SPD msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_SET_SPD_LEN
value|148
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_DDR_OP_OFST 4 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_DDR_BANK_OFST 8 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_FLAGS_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_SET_SPD_ACTIVE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_SPD_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_SPD_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_SPD_NUM
value|128
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_SPD_PAGE_ID_OFST
value|144
end_define

begin_comment
comment|/* MC_CMD_FC_IN_DDR_GET_STATUS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DDR_GET_STATUS_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_DDR_OP_OFST 4 */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_DDR_BANK_OFST 8 */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_TIMESTAMP msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_SNAPSHOT
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_CLEAR_TRANSMIT
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_LEN
value|28
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_FILTER_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_LATEST
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_MATCH
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_CLOCK_ID_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_CLOCK_ID_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_CLOCK_ID_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_CLOCK_ID_HI_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_PORT_NUM_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_SEQ_NUM_OFST
value|24
end_define

begin_comment
comment|/* MC_CMD_FC_IN_TIMESTAMP_READ_SNAPSHOT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_SNAPSHOT_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_SNAPSHOT_OP_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_FC_IN_TIMESTAMP_CLEAR_TRANSMIT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_CLEAR_TRANSMIT_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_CLEAR_TRANSMIT_OP_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_FC_IN_SPI msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_READ
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_WRITE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_ERASE
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_SPI_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_READ_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_READ_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_READ_ADDR_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_READ_NUMBYTES_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_FC_IN_SPI_WRITE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_WRITE_LENMIN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_WRITE_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_WRITE_LEN
parameter_list|(
name|num
parameter_list|)
value|(12+4*(num))
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_WRITE_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_WRITE_ADDR_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_WRITE_BUFFER_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_WRITE_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_WRITE_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_WRITE_BUFFER_MAXNUM
value|60
end_define

begin_comment
comment|/* MC_CMD_FC_IN_SPI_ERASE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_ERASE_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_ERASE_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_ERASE_ADDR_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_ERASE_NUMBYTES_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_FC_IN_DIAG msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_DIAG_POWER_NOISE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_SUB_OP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_READ_CONFIG
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_WRITE_CONFIG
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_DIAG_POWER_NOISE_READ_CONFIG msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_READ_CONFIG_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_READ_CONFIG_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_READ_CONFIG_SUB_OP_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_FC_IN_DIAG_POWER_NOISE_WRITE_CONFIG msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_WRITE_CONFIG_LEN
value|20
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_WRITE_CONFIG_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_WRITE_CONFIG_SUB_OP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_WRITE_CONFIG_TOGGLE_COUNT_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_WRITE_CONFIG_CLKEN_COUNT_OFST
value|16
end_define

begin_comment
comment|/* MC_CMD_FC_IN_DIAG_DDR_SOAK msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_SUB_OP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_RESULT
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_STOP
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_ERROR
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_DIAG_DDR_SOAK_START msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START_LEN
value|24
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START_SUB_OP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START_BANK_MASK_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START_TEST_PATTERN_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START_ZEROS
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START_ONES
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START_TEST_TYPE_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START_ONGOING_TEST
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START_SINGLE_TEST
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_DIAG_DDR_SOAK_RESULT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_RESULT_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_RESULT_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_RESULT_SUB_OP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_RESULT_BANK_ID_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_DDR_BANK0
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_DDR_BANK1
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_DDR_BANK2
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_DDR_BANK3
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_DDR_AOEMEM_MAX_BANKS
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_DIAG_DDR_SOAK_STOP msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_STOP_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_STOP_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_STOP_SUB_OP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_STOP_BANK_MASK_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_FC_IN_DIAG_DDR_SOAK_ERROR msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_ERROR_LEN
value|20
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_ERROR_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_ERROR_SUB_OP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_ERROR_BANK_MASK_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_ERROR_FLAG_ACTION_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_ERROR_CLEAR
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_ERROR_SET
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_DIAG_DATAPATH_CTRL msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_SUB_OP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_SET_MODE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_RAW_CONFIG
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_SET_MODE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_SET_MODE_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_SET_MODE_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_SET_MODE_SUB_OP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_SET_MODE_MODE_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_SET_MODE_PASSTHROUGH
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_SET_MODE_SNAKE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_RAW_CONFIG msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_RAW_CONFIG_LEN
value|24
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_RAW_CONFIG_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_RAW_CONFIG_SUB_OP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_RAW_CONFIG_CONTROL1_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_RAW_CONFIG_CONTROL2_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_RAW_CONFIG_CONTROL3_OFST
value|20
end_define

begin_comment
comment|/* MC_CMD_FC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_NULL msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_NULL_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_READ32 msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ32_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ32_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ32_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ32_BUFFER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ32_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ32_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ32_BUFFER_MAXNUM
value|63
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_WRITE32 msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_WRITE32_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_TRC_READ msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TRC_READ_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TRC_READ_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TRC_READ_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TRC_READ_DATA_NUM
value|4
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_TRC_WRITE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TRC_WRITE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_GET_VERSION msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_VERSION_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_VERSION_FIRMWARE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_VERSION_VERSION_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_VERSION_VERSION_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_VERSION_VERSION_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_VERSION_VERSION_HI_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_TRC_RX_READ msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TRC_RX_READ_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TRC_RX_READ_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TRC_RX_READ_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TRC_RX_READ_DATA_NUM
value|2
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_TRC_RX_WRITE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TRC_RX_WRITE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_MAC_RECONFIGURE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_RECONFIGURE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_MAC_SET_LINK msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_SET_LINK_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_MAC_READ_STATUS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_READ_STATUS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_READ_STATUS_STATUS_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_MAC_GET_RX_STATS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_RX_STATS_LEN
value|((((0-1+(64*MC_CMD_FC_MAC_RX_NSTATS))+1))>>3)
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_RX_STATS_STATISTICS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_RX_STATS_STATISTICS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_RX_STATS_STATISTICS_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_RX_STATS_STATISTICS_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_RX_STATS_STATISTICS_NUM
value|MC_CMD_FC_MAC_RX_NSTATS
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_OCTETS
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_OCTETS_OK
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_ALIGNMENT_ERRORS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_PAUSE_MAC_CTRL_FRAMES
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_FRAMES_OK
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_CRC_ERRORS
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_VLAN_OK
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_ERRORS
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_UCAST_PKTS
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_MULTICAST_PKTS
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_BROADCAST_PKTS
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_DROP_EVENTS
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_PKTS
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_UNDERSIZE_PKTS
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_PKTS_64
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_PKTS_65_127
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_PKTS_128_255
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_PKTS_256_511
value|0x11
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_PKTS_512_1023
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_PKTS_1024_1518
value|0x13
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_PKTS_1519_MAX
value|0x14
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_OVERSIZE_PKTS
value|0x15
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_JABBERS
value|0x16
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_STATS_FRAGMENTS
value|0x17
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_MAC_CONTROL_FRAMES
value|0x18
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_NSTATS
value|0x19
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_OUT_MAC_GET_TX_STATS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_TX_STATS_LEN
value|((((0-1+(64*MC_CMD_FC_MAC_TX_NSTATS))+1))>>3)
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_TX_STATS_STATISTICS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_TX_STATS_STATISTICS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_TX_STATS_STATISTICS_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_TX_STATS_STATISTICS_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_TX_STATS_STATISTICS_NUM
value|MC_CMD_FC_MAC_TX_NSTATS
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_STATS_OCTETS
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_OCTETS_OK
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_ALIGNMENT_ERRORS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_PAUSE_MAC_CTRL_FRAMES
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_FRAMES_OK
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_CRC_ERRORS
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_VLAN_OK
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_ERRORS
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_UCAST_PKTS
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_MULTICAST_PKTS
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_BROADCAST_PKTS
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_STATS_DROP_EVENTS
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_STATS_PKTS
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_STATS_UNDERSIZE_PKTS
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_STATS_PKTS_64
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_STATS_PKTS_65_127
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_STATS_PKTS_128_255
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_STATS_PKTS_256_511
value|0x11
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_STATS_PKTS_512_1023
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_STATS_PKTS_1024_1518
value|0x13
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_STATS_PKTS_1519_TX_MTU
value|0x14
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_MAC_CONTROL_FRAMES
value|0x15
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_NSTATS
value|0x16
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_OUT_MAC_GET_STATS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_STATS_LEN
value|((((0-1+(64*MC_CMD_FC_MAC_NSTATS_PER_BLOCK))+1))>>3)
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_STATS_STATISTICS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_STATS_STATISTICS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_STATS_STATISTICS_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_STATS_STATISTICS_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_STATS_STATISTICS_NUM
value|MC_CMD_FC_MAC_NSTATS_PER_BLOCK
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_MAC msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_SFP msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_SFP_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DDR_TEST_START msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_START_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DDR_TEST_POLL msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_STATUS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_CODE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_CODE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_NONE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_INPROGRESS
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_SUCCESS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_TIMER_EXPIRED
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_T0_LBN
value|11
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_T0_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_T1_LBN
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_T1_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_B0_LBN
value|9
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_B0_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_B1_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_PRESENT_B1_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_RESULT_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_T0_LBN
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_T0_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_T1_LBN
value|30
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_T1_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_B0_LBN
value|29
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_B0_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_B1_LBN
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_FPGA_SUPPORTS_B1_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_T0_LBN
value|15
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_T0_WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_T1_LBN
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_T1_WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_B0_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_B0_WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_B1_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_B1_WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_TEST_COMPLETE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_TEST_FAIL
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_TEST_PASS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_CAL_FAIL
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_POLL_CAL_SUCCESS
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_FC_OUT_DDR_TEST msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_TEST_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_GET_ASSERT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_LEN
value|144
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_GLOBAL_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_STATE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_STATE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_STATE_CLEAR
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_STATE_NEW
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_STATE_NOTIFIED
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_TYPE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_TYPE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_TYPE_NONE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_TYPE_EXCEPTION
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_TYPE_ASSERTION
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_SAVED_PC_OFFS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_GP_REGS_OFFS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_GP_REGS_OFFS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_GP_REGS_OFFS_NUM
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_EXCEPTION_TYPE_OFFS_OFST
value|132
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_EXCEPTION_PC_ADDR_OFFS_OFST
value|136
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_EXCEPTION_BAD_ADDR_OFFS_OFST
value|140
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_FPGA_BUILD msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_COMPONENT_INFO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_IS_APPLICATION_LBN
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_IS_APPLICATION_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_IS_LICENSED_LBN
value|30
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_IS_LICENSED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_COMPONENT_ID_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_COMPONENT_ID_WIDTH
value|14
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_VERSION_MAJOR_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_VERSION_MAJOR_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_VERSION_MINOR_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_VERSION_MINOR_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_BUILD_NUM_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_BUILD_NUM_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_TIMESTAMP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_PARAMETERS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_FPGA_TYPE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_FPGA_TYPE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_FPGA_TYPE_A7
value|0xa7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_FPGA_TYPE_A5
value|0xa5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_RESERVED1_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_RESERVED1_WIDTH
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_PTP_ENABLED_LBN
value|18
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_PTP_ENABLED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM1_RLDRAM_DEF_LBN
value|19
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM1_RLDRAM_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM2_RLDRAM_DEF_LBN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM2_RLDRAM_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM3_RLDRAM_DEF_LBN
value|21
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM3_RLDRAM_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM4_RLDRAM_DEF_LBN
value|22
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM4_RLDRAM_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T0_DDR3_DEF_LBN
value|23
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T0_DDR3_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T1_DDR3_DEF_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T1_DDR3_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_B0_DDR3_DEF_LBN
value|25
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_B0_DDR3_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_B1_DDR3_DEF_LBN
value|26
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_B1_DDR3_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_DDR3_ECC_ENABLED_LBN
value|27
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_DDR3_ECC_ENABLED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T1_QDR_DEF_LBN
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_SODIMM_T1_QDR_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_RESERVED2_LBN
value|29
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_RESERVED2_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_CRC_APPEND_LBN
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_CRC_APPEND_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_IDENTIFIER_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_CHANGESET_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_CHANGESET_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_BUILD_FLAG_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_BUILD_FLAG_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_FPGA_BUILD_FLAG_INTERNAL
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_FPGA_BUILD_FLAG_RELEASE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_RESERVED3_LBN
value|17
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_RESERVED3_WIDTH
value|15
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_VERSION_HI_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MINOR_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MINOR_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MAJOR_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MAJOR_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_VERSION_LO_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_BUILD_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_BUILD_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MICRO_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_DEPLOYMENT_VERSION_MICRO_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_RESERVED4_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_RESERVED4_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_RESERVED4_LO_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_RESERVED4_HI_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_REVISION_LO_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_REVISION_HI_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_REVISION_HIGH_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_BUILD_REVISION_HIGH_WIDTH
value|16
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_FPGA_SERVICES msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_COMPONENT_INFO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_IS_APPLICATION_LBN
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_IS_APPLICATION_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_IS_LICENSED_LBN
value|30
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_IS_LICENSED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_COMPONENT_ID_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_COMPONENT_ID_WIDTH
value|14
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_VERSION_MAJOR_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_VERSION_MAJOR_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_VERSION_MINOR_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_VERSION_MINOR_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_BUILD_NUM_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_BUILD_NUM_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_TIMESTAMP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_PARAMETERS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_FC_FLASH_BOOTED_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_FC_FLASH_BOOTED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_NIC0_DEF_LBN
value|27
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_NIC0_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_NIC1_DEF_LBN
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_NIC1_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_SFP0_DEF_LBN
value|29
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_SFP0_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_SFP1_DEF_LBN
value|30
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_SFP1_DEF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_RESERVED_LBN
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_RESERVED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_IDENTIFIER_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_CHANGESET_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_CHANGESET_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_BUILD_FLAG_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_BUILD_FLAG_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_MEMORY_SIZE_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_MEMORY_SIZE_WIDTH_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_MEMORY_SIZE_WIDTH_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_MEMORY_SIZE_COUNT_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_MEMORY_SIZE_COUNT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_INSTANCE_SIZE_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_INSTANCE_SIZE_WIDTH_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_INSTANCE_SIZE_WIDTH_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_INSTANCE_SIZE_COUNT_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_INSTANCE_SIZE_COUNT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_REVISION_LO_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_REVISION_HI_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_REVISION_HIGH_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_FPGA_SERVICES_REVISION_HIGH_WIDTH
value|16
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_BSP_VERSION msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_BSP_VERSION_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_BSP_VERSION_SYSID_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_BSP_VERSION_VERSION_MAJOR_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_BSP_VERSION_VERSION_MAJOR_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_BSP_VERSION_VERSION_MINOR_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_BSP_VERSION_VERSION_MINOR_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_BSP_VERSION_BUILD_NUM_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_BSP_VERSION_BUILD_NUM_WIDTH
value|4
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_READ_MAP_COUNT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_COUNT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_COUNT_NUM_MAPS_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_READ_MAP_INDEX msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_LEN
value|164
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_INDEX_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_OPTIONS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_ALIGN_8
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_ALIGN_16
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_ALIGN_32
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_ALIGN_64
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_ALIGN_MASK
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_PATH_FC
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_PATH_MEM
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_PERM_READ
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_PERM_WRITE
value|0x20
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_FREE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_LICENSED
value|0x40
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_ADDRESS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_ADDRESS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_ADDRESS_LO_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_ADDRESS_HI_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_LEN_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_LEN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_LEN_LO_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_LEN_HI_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_COMP_INFO_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_DATE_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_DATE_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_DATE_LO_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_LICENSE_DATE_HI_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_NAME_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_NAME_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_NAME_NUM
value|128
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_READ_MAP msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_CAPABILITIES msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CAPABILITIES_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CAPABILITIES_INTERNAL_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CAPABILITIES_EXTERNAL_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_GLOBAL_FLAGS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GLOBAL_FLAGS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GLOBAL_FLAGS_FLAGS_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_IO_REL msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_IO_REL_GET_ADDR msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_GET_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_GET_ADDR_ADDR_HI_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_GET_ADDR_ADDR_LO_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_IO_REL_READ32 msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_READ32_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_READ32_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_READ32_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_READ32_BUFFER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_READ32_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_READ32_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_READ32_BUFFER_MAXNUM
value|63
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_IO_REL_WRITE32 msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_IO_REL_WRITE32_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_UHLINK_PHY msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_LEN
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_SETTINGS_0_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_VOD_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_VOD_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_1STPOSTTAP_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_1STPOSTTAP_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_SETTINGS_1_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_PRETAP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_PRETAP_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_2NDPOSTTAP_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_TX_PREEMP_2NDPOSTTAP_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_RX_SETTINGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_RX_DC_GAIN_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_RX_DC_GAIN_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_RX_EQ_CONTROL_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_TRC_RX_EQ_CONTROL_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_RX_EYE_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_RX_EYE_WIDTH_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_RX_EYE_WIDTH_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_RX_EYE_HEIGHT_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_RX_EYE_HEIGHT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_PCS_STATUS_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_LINK_STATE_WORD_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_LINK_STATE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_LINK_STATE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_LINK_CONFIGURED_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_LINK_CONFIGURED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_PARAMS_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_PARAMS_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_SPEED_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_COPPER_LEN_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_DUAL_SPEED_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_PRESENT_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_TYPE_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_DFE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_DFE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_AEQ_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_AEQ_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_RX_TUNING_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_PHY_CFG_RX_TUNING_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_UHLINK_MAC msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_MAC_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_MAC_CONFIG_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_MAC_MTU_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_MAC_IF_STATUS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_MAC_ADDR_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_MAC_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_MAC_ADDR_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_MAC_ADDR_HI_OFST
value|16
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_UHLINK_RX_EYE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_RX_EYE_LEN
value|((((0-1+(32*MC_CMD_FC_UHLINK_RX_EYE_PER_BLOCK))+1))>>3)
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_RX_EYE_RX_EYE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_RX_EYE_RX_EYE_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_RX_EYE_RX_EYE_NUM
value|MC_CMD_FC_UHLINK_RX_EYE_PER_BLOCK
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_UHLINK_DUMP_RX_EYE_PLOT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_DUMP_RX_EYE_PLOT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_LEN
value|((((32-1+(64*MC_CMD_FC_UHLINK_RX_EYE_PLOT_ROWS_PER_BLOCK))+1))>>3)
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_VALID_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_ROWS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_ROWS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_ROWS_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_ROWS_HI_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_ROWS_NUM
value|MC_CMD_FC_UHLINK_RX_EYE_PLOT_ROWS_PER_BLOCK
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_UHLINK_RX_TUNE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_RX_TUNE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_UHLINK_LOOPBACK_SET msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_LOOPBACK_SET_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_UHLINK_LOOPBACK_GET msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_LOOPBACK_GET_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_LOOPBACK_GET_STATE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_UHLINK msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_SET_LINK msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_SET_LINK_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_LICENSE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_LICENSE_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_LICENSE_VALID_KEYS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_LICENSE_INVALID_KEYS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_LICENSE_BLACKLISTED_KEYS_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_STARTUP msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_STARTUP_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_STARTUP_CAPABILITIES_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_STARTUP_CAN_ACCESS_FLASH_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_STARTUP_CAN_ACCESS_FLASH_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DMA_READ msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DMA_READ_LENMIN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DMA_READ_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DMA_READ_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+1*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DMA_READ_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DMA_READ_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DMA_READ_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DMA_READ_DATA_MAXNUM
value|252
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_TIMED_READ_SET msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_SET_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_SET_FC_HANDLE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_TIMED_READ_GET msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_LEN
value|52
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_HOST_HANDLE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_HOST_DMA_ADDRESS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_HOST_DMA_ADDRESS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_HOST_DMA_ADDRESS_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_HOST_DMA_ADDRESS_HI_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_AOE_ADDRESS_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_AOE_ADDRESS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_AOE_ADDRESS_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_AOE_ADDRESS_HI_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_AOE_LENGTH_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_HOST_LENGTH_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_FLAGS_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_PERIOD_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_START_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_START_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_START_LO_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_START_HI_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_END_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_END_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_END_LO_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_CLOCK_END_HI_OFST
value|48
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_LOG_ADDR_RANGE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_LOG_ADDR_RANGE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_LOG msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_LOG_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_CLOCK_GET_TIME msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CLOCK_GET_TIME_LEN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CLOCK_GET_TIME_CLOCK_ID_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CLOCK_GET_TIME_SECONDS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CLOCK_GET_TIME_SECONDS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CLOCK_GET_TIME_SECONDS_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CLOCK_GET_TIME_SECONDS_HI_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CLOCK_GET_TIME_NANOSECONDS_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CLOCK_GET_TIME_RANGE_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CLOCK_GET_TIME_PRECISION_OFST
value|20
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_CLOCK_SET_TIME msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CLOCK_SET_TIME_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DDR_SET_SPD msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_SET_SPD_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DDR_GET_STATUS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_GET_STATUS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_GET_STATUS_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_GET_STATUS_READY_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_GET_STATUS_READY_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_GET_STATUS_CALIBRATED_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DDR_GET_STATUS_CALIBRATED_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_TIMESTAMP_READ_TRANSMIT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_TRANSMIT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_TRANSMIT_SECONDS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_TRANSMIT_NANOSECONDS_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_LENMIN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_LENMAX
value|248
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+8*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_SECONDS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_NANOSECONDS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMESTAMP_READ_SNAPSHOT_TIMESTAMP_MAXNUM
value|31
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_SPI_READ msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_SPI_READ_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_SPI_READ_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_SPI_READ_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_SPI_READ_BUFFER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_SPI_READ_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_SPI_READ_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_SPI_READ_BUFFER_MAXNUM
value|63
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_SPI_WRITE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_SPI_WRITE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_SPI_ERASE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_SPI_ERASE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DIAG_POWER_NOISE_READ_CONFIG msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_POWER_NOISE_READ_CONFIG_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_POWER_NOISE_READ_CONFIG_TOGGLE_COUNT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_POWER_NOISE_READ_CONFIG_CLKEN_COUNT_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DIAG_POWER_NOISE_WRITE_CONFIG msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_POWER_NOISE_WRITE_CONFIG_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DIAG_DDR_SOAK_START msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_START_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_STATUS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_PASSED_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_PASSED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_FAILED_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_FAILED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_COMPLETED_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_COMPLETED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_TIMEOUT_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_TIMEOUT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_PNF_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_PNF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_RESULT_ERR_COUNT_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DIAG_DDR_SOAK_STOP msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_STOP_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DIAG_DDR_SOAK_ERROR msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DDR_SOAK_ERROR_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DIAG_DATAPATH_CTRL_SET_MODE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DATAPATH_CTRL_SET_MODE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_DIAG_DATAPATH_CTRL_RAW_CONFIG msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_DATAPATH_CTRL_RAW_CONFIG_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_AOE   * AOE operations (on MC rather than FC)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE
value|0xa
end_define

begin_comment
comment|/* MC_CMD_AOE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_OP_HDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_OP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_OP_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_INFO
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CURRENTS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_TEMPERATURES
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CPLD_IDLE
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CPLD_READ
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CPLD_WRITE
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CPLD_INSTRUCTION
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CPLD_REPROGRAM
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_POWER
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_LOAD
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_FAN_CONTROL
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_FAN_FAILURES
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_MAC_STATS
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_GET_PHY_MEDIA_INFO
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_JTAG_WRITE
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_FPGA_ACCESS
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_SET_MTU_OFFSET
value|0x11
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_LINK_STATE
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_SIENA_STATS
value|0x13
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_DDR
value|0x14
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_FC
value|0x15
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_DDR_ECC_STATUS
value|0x16
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_MC_SPI_MASTER
value|0x17
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_AOE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_INFO msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_INFO_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CMD_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_CURRENTS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CURRENTS_LEN
value|4
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_AOE_IN_TEMPERATURES msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_TEMPERATURES_LEN
value|4
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_AOE_IN_CPLD_IDLE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_IDLE_LEN
value|4
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_AOE_IN_CPLD_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_READ_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_READ_REGISTER_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_READ_WIDTH_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_CPLD_WRITE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_WRITE_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_WRITE_REGISTER_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_WRITE_WIDTH_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_WRITE_VALUE_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_CPLD_INSTRUCTION msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_INSTRUCTION_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_INSTRUCTION_INSTRUCTION_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_CPLD_REPROGRAM msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_REPROGRAM_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_REPROGRAM_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_REPROGRAM_REPROGRAM
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_REPROGRAM_REPROGRAM_EVENT
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_REPROGRAM_STATUS
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_AOE_IN_POWER msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_OFF
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_ON
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_CLEAR
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_SHOW_CURRENT
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_SHOW_PEAK
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_DDR_LAST
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_DDR_PEAK
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_DDR_CLEAR
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_AOE_IN_LOAD msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LOAD_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LOAD_IMAGE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_FAN_CONTROL msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FAN_CONTROL_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FAN_CONTROL_REAL_RPM_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_FAN_FAILURES msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FAN_FAILURES_LEN
value|4
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_AOE_IN_MAC_STATS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_LEN
value|24
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PORT_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_DMA_ADDR_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_DMA_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_DMA_ADDR_LO_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_DMA_ADDR_HI_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_CMD_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_DMA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_DMA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_CLEAR_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_CLEAR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PERIODIC_CHANGE_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PERIODIC_CHANGE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PERIODIC_ENABLE_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PERIODIC_ENABLE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PERIODIC_CLEAR_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PERIODIC_CLEAR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PERIODIC_NOEVENT_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PERIODIC_NOEVENT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PERIOD_MS_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PERIOD_MS_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_DMA_LEN_OFST
value|20
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_GET_PHY_MEDIA_INFO msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_GET_PHY_MEDIA_INFO_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_GET_PHY_MEDIA_INFO_PORT_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_GET_PHY_MEDIA_INFO_PAGE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_JTAG_WRITE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_JTAG_WRITE_LENMIN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_JTAG_WRITE_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_JTAG_WRITE_LEN
parameter_list|(
name|num
parameter_list|)
value|(8+4*(num))
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_JTAG_WRITE_DATALEN_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_JTAG_WRITE_DATA_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_JTAG_WRITE_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_JTAG_WRITE_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_JTAG_WRITE_DATA_MAXNUM
value|61
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_FPGA_ACCESS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FPGA_ACCESS_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FPGA_ACCESS_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FPGA_ACCESS_ENABLE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FPGA_ACCESS_DISABLE
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_AOE_IN_SET_MTU_OFFSET msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SET_MTU_OFFSET_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SET_MTU_OFFSET_PORT_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SET_MTU_OFFSET_ALL_EXTERNAL
value|0x8000
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SET_MTU_OFFSET_ALL_INTERNAL
value|0x4000
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SET_MTU_OFFSET_OFFSET_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_LINK_STATE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_MODE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_CONFIG_MODE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_CONFIG_MODE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_SIMPLE_SEPARATE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_SIMPLE_COMBINED
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_DIAGNOSTIC
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_CUSTOM
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_OPERATION_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_OPERATION_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_OP_NONE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_OP_OR
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_OP_AND
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_SFP_MASK_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_SFP_MASK_WIDTH
value|16
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_SIENA_STATS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SIENA_STATS_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SIENA_STATS_MODE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SIENA_STATS_STATS_SIENA
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SIENA_STATS_STATS_AOE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_AOE_IN_DDR msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_DDR_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_DDR_BANK_OFST
value|4
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_FC_IN_DDR_BANK */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_DDR_SPD_PAGE_ID_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_FC msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FC_LEN
value|4
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_AOE_IN_DDR_ECC_STATUS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_DDR_ECC_STATUS_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_DDR_ECC_STATUS_BANK_OFST
value|4
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_FC_IN_DDR_BANK */
end_comment

begin_comment
comment|/* MC_CMD_AOE_IN_MC_SPI_MASTER msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_READ
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_WRITE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_AOE_IN_MC_SPI_MASTER_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_READ_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_READ_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_READ_OFFSET_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_MC_SPI_MASTER_WRITE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_WRITE_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_WRITE_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_WRITE_OFFSET_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_WRITE_DATA_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_INFO msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_LEN
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_CPLD_IDCODE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_CPLD_VERSION_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_IDCODE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_VERSION_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_TYPE_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_STATE_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_IMAGE_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_STATE_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_WATCHDOG
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_COMMS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FLAGS_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_PEG_POWER
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_CPLD_GOOD
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_GOOD
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_POWER
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_BAD_SODIMM
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_HAS_BYTEBLASTER
value|0x20
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_BOARD_REVISION_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_UNKNOWN
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_R1_0
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_R1_1
value|0x11
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_R1_2
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_RESULT_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_NO_ERROR
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_ADDRESS
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_MAGIC
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_TEXT
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_CHECKSUM
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_BSP
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_APP_EXECUTE
value|0x80
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_NO_BOOTROM
value|0xff
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_AOE_OUT_CURRENTS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_LEN
value|68
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_VALUES_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_VALUES_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_VALUES_NUM
value|17
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_I_2V5
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_I_1V8
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_I_GXB
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_I_PGM
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_I_XCVR
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_I_1V5
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_V_3V3
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_V_1V5
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_I_IN
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_I_OUT
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_V_IN
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_I_OUT_DDR1
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_V_OUT_DDR1
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_I_OUT_DDR2
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_V_OUT_DDR2
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_I_OUT_DDR3
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_V_OUT_DDR3
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_AOE_OUT_TEMPERATURES msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_LEN
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_VALUES_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_VALUES_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_VALUES_NUM
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_MAIN_0
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_MAIN_1
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_IND_0
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_IND_1
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_VCCIO1
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_VCCIO2
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_VCCIO3
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_PSU
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_FPGA
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_SIENA
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_AOE_OUT_CPLD_READ msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CPLD_READ_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CPLD_READ_VALUE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_FAN_FAILURES msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_FAN_FAILURES_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_FAN_FAILURES_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_FAN_FAILURES_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_FAN_FAILURES_COUNT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_FAN_FAILURES_COUNT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_FAN_FAILURES_COUNT_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_FAN_FAILURES_COUNT_MAXNUM
value|63
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_CPLD_REPROGRAM msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CPLD_REPROGRAM_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CPLD_REPROGRAM_STATUS_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_MAC_STATS_DMA msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_MAC_STATS_DMA_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_MAC_STATS_NO_DMA msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_LEN
value|(((MC_CMD_MAC_NSTATS*64))>>3)
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_STATISTICS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_STATISTICS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_STATISTICS_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_STATISTICS_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_MAC_STATS_NO_DMA_STATISTICS_NUM
value|MC_CMD_MAC_NSTATS
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_LENMIN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+1*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_DATALEN_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_DATA_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_GET_PHY_MEDIA_INFO_DATA_MAXNUM
value|248
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_JTAG_WRITE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_JTAG_WRITE_LENMIN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_JTAG_WRITE_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_JTAG_WRITE_LEN
parameter_list|(
name|num
parameter_list|)
value|(8+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_JTAG_WRITE_DATALEN_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_JTAG_WRITE_PAD_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_JTAG_WRITE_DATA_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_JTAG_WRITE_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_JTAG_WRITE_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_JTAG_WRITE_DATA_MAXNUM
value|61
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_FPGA_ACCESS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_FPGA_ACCESS_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_DDR msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_LENMIN
value|17
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_LEN
parameter_list|(
name|num
parameter_list|)
value|(16+1*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_PRESENT_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_PRESENT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_POWERED_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_POWERED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_OPERATIONAL_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_OPERATIONAL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_CAPACITY_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_TYPE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_VOLTAGE_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_SPD_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_SPD_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_SPD_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_SPD_MAXNUM
value|236
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_LINK_STATE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_LINK_STATE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_FC msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_FC_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_DDR_ECC_STATUS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_VALID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_VALID_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_STATUS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_SBE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_SBE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_DBE_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_DBE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_CORDROP_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_CORDROP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_SBE_COUNT_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_SBE_COUNT_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_DBE_COUNT_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_DBE_COUNT_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_CORDROP_COUNT_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_ECC_STATUS_CORDROP_COUNT_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_MC_SPI_MASTER_READ msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_MC_SPI_MASTER_READ_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_MC_SPI_MASTER_READ_DATA_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_MC_SPI_MASTER_WRITE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_MC_SPI_MASTER_WRITE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_MC_SPI_MASTER msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_MC_SPI_MASTER_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PTP   * Perform PTP operation  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP
value|0xb
end_define

begin_comment
comment|/* MC_CMD_PTP_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_OP_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_ENABLE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_DISABLE
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_TRANSMIT
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_READ_NIC_TIME
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_STATUS
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_ADJUST
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_SYNCHRONIZE
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_MANFTEST_BASIC
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_MANFTEST_PACKET
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_RESET_STATS
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_DEBUG
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_FPGAREAD
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_FPGAWRITE
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_CLOCK_OFFSET_ADJUST
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_CLOCK_FREQ_ADJUST
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_RX_SET_VLAN_FILTER
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_RX_SET_UUID_FILTER
value|0x11
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_RX_SET_DOMAIN_FILTER
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_SET_CLK_SRC
value|0x13
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_RST_CLK
value|0x14
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_PPS_ENABLE
value|0x15
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_MAX
value|0x16
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_PTP_IN_ENABLE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ENABLE_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CMD_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_PERIPH_ID_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ENABLE_QUEUE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ENABLE_MODE_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_MODE_V1
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MODE_V1_VLAN
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MODE_V2
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MODE_V2_VLAN
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MODE_V2_ENHANCED
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_PTP_IN_DISABLE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_DISABLE_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_PTP_IN_TRANSMIT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TRANSMIT_LENMIN
value|13
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TRANSMIT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TRANSMIT_LEN
parameter_list|(
name|num
parameter_list|)
value|(12+1*(num))
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TRANSMIT_LENGTH_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TRANSMIT_PACKET_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TRANSMIT_PACKET_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TRANSMIT_PACKET_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TRANSMIT_PACKET_MAXNUM
value|240
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_READ_NIC_TIME msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_READ_NIC_TIME_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_PTP_IN_STATUS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_STATUS_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_PTP_IN_ADJUST msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_LEN
value|24
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_FREQ_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_FREQ_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_FREQ_LO_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_FREQ_HI_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_BITS
value|0x28
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_SECONDS_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_NANOSECONDS_OFST
value|20
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_SYNCHRONIZE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SYNCHRONIZE_LEN
value|20
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SYNCHRONIZE_NUMTIMESETS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SYNCHRONIZE_START_ADDR_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SYNCHRONIZE_START_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SYNCHRONIZE_START_ADDR_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SYNCHRONIZE_START_ADDR_HI_OFST
value|16
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_MANFTEST_BASIC msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_MANFTEST_BASIC_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_PTP_IN_MANFTEST_PACKET msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_MANFTEST_PACKET_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_MANFTEST_PACKET_TEST_ENABLE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_RESET_STATS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RESET_STATS_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_PTP_IN_DEBUG msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_DEBUG_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_DEBUG_DEBUG_PARAM_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_FPGAREAD msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_FPGAREAD_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_FPGAREAD_ADDR_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_FPGAREAD_NUMBYTES_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_FPGAWRITE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_FPGAWRITE_LENMIN
value|13
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_FPGAWRITE_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_FPGAWRITE_LEN
parameter_list|(
name|num
parameter_list|)
value|(12+1*(num))
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_FPGAWRITE_ADDR_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_FPGAWRITE_BUFFER_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_FPGAWRITE_BUFFER_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_FPGAWRITE_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_FPGAWRITE_BUFFER_MAXNUM
value|240
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_CLOCK_OFFSET_ADJUST msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_OFFSET_ADJUST_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_OFFSET_ADJUST_SECONDS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_OFFSET_ADJUST_NANOSECONDS_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_CLOCK_FREQ_ADJUST msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_FREQ_ADJUST_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_FREQ_ADJUST_FREQ_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_FREQ_ADJUST_FREQ_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_FREQ_ADJUST_FREQ_LO_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_FREQ_ADJUST_FREQ_HI_OFST
value|12
end_define

begin_comment
comment|/*               MC_CMD_PTP_IN_ADJUST_BITS 0x28 */
end_comment

begin_comment
comment|/* MC_CMD_PTP_IN_RX_SET_VLAN_FILTER msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_VLAN_FILTER_LEN
value|24
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_VLAN_FILTER_NUM_VLAN_TAGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_VLAN_FILTER_VLAN_TAG_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_VLAN_FILTER_VLAN_TAG_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_VLAN_FILTER_VLAN_TAG_NUM
value|3
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_RX_SET_UUID_FILTER msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_UUID_FILTER_LEN
value|20
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_UUID_FILTER_ENABLE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_UUID_FILTER_UUID_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_UUID_FILTER_UUID_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_UUID_FILTER_UUID_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_UUID_FILTER_UUID_HI_OFST
value|16
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_RX_SET_DOMAIN_FILTER msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_DOMAIN_FILTER_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_DOMAIN_FILTER_ENABLE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_DOMAIN_FILTER_DOMAIN_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_PPS_ENABLE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_PPS_ENABLE_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_PPS_ENABLE_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_ENABLE_PPS
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_DISABLE_PPS
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_PPS_ENABLE_QUEUE_ID_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_TRANSMIT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_TRANSMIT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_TRANSMIT_SECONDS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_TRANSMIT_NANOSECONDS_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_READ_NIC_TIME msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_READ_NIC_TIME_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_READ_NIC_TIME_SECONDS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_READ_NIC_TIME_NANOSECONDS_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_STATUS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_LEN
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_CLOCK_FREQ_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_TX_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_RX_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_TS_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_FM_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_NFM_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_OFLOW_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_BAD_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_PER_MIN_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_PER_MAX_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_PER_LAST_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_PER_MEAN_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_OFF_MIN_OFST
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_OFF_MAX_OFST
value|52
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_OFF_LAST_OFST
value|56
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_OFF_MEAN_OFST
value|60
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_SYNCHRONIZE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_LENMIN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_LENMAX
value|240
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+20*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_TIMESET_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_TIMESET_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_TIMESET_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_TIMESET_MAXNUM
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_HOSTSTART_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_SECONDS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_NANOSECONDS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_HOSTEND_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_WAITNS_OFST
value|16
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_MANFTEST_BASIC msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_BASIC_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_BASIC_TEST_RESULT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_SUCCESS
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_FPGA_LOAD
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_FPGA_VERSION
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_FPGA_REGISTERS
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_OSCILLATOR
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_TIMESTAMPS
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_PACKET_COUNT
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_FILTER_COUNT
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_PACKET_ENOUGH
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_GPIO_TRIGGER
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_BASIC_TEST_EXTOSC_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_MANFTEST_PACKET msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_PACKET_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_PACKET_TEST_RESULT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_PACKET_TEST_FPGACOUNT_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_PACKET_TEST_FILTERCOUNT_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_FPGAREAD msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_FPGAREAD_LENMIN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_FPGAREAD_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_FPGAREAD_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+1*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_FPGAREAD_BUFFER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_FPGAREAD_BUFFER_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_FPGAREAD_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_FPGAREAD_BUFFER_MAXNUM
value|252
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_CSR_READ32   * Read 32bit words from the indirect memory map.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32
value|0xc
end_define

begin_comment
comment|/* MC_CMD_CSR_READ32_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32_IN_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32_IN_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32_IN_STEP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32_IN_NUMWORDS_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_CSR_READ32_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32_OUT_BUFFER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32_OUT_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32_OUT_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32_OUT_BUFFER_MAXNUM
value|63
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_CSR_WRITE32   * Write 32bit dwords to the indirect memory map.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32
value|0xd
end_define

begin_comment
comment|/* MC_CMD_CSR_WRITE32_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32_IN_LENMIN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(8+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32_IN_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32_IN_STEP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32_IN_BUFFER_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32_IN_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32_IN_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32_IN_BUFFER_MAXNUM
value|61
end_define

begin_comment
comment|/* MC_CMD_CSR_WRITE32_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32_OUT_STATUS_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_HP   * HP specific commands.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP
value|0x54
end_define

begin_comment
comment|/* MC_CMD_HP_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_SUBCMD_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_OCSD_SUBCMD
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_LAST_SUBCMD
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_OCSD_ADDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_OCSD_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_OCSD_ADDR_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_OCSD_ADDR_HI_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_OCSD_INTERVAL_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_HP_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_HP_OUT_OCSD_STATUS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_HP_OUT_OCSD_STOPPED
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_OUT_OCSD_STARTED
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_OUT_OCSD_ALREADY_STARTED
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_STACKINFO   * Get stack information.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_STACKINFO
value|0xf
end_define

begin_comment
comment|/* MC_CMD_STACKINFO_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_STACKINFO_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_STACKINFO_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_STACKINFO_OUT_LENMIN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_STACKINFO_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_STACKINFO_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+12*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_STACKINFO_OUT_THREAD_INFO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_STACKINFO_OUT_THREAD_INFO_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_STACKINFO_OUT_THREAD_INFO_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_STACKINFO_OUT_THREAD_INFO_MAXNUM
value|21
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_MDIO_READ   * MDIO register read.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ
value|0x10
end_define

begin_comment
comment|/* MC_CMD_MDIO_READ_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_IN_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_IN_BUS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MDIO_BUS_INTERNAL
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_BUS_EXTERNAL
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_IN_PRTAD_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_IN_DEVAD_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MDIO_CLAUSE22
value|0x20
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_IN_ADDR_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_MDIO_READ_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_OUT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_OUT_VALUE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_OUT_STATUS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MDIO_STATUS_GOOD
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_MDIO_WRITE   * MDIO register write.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE
value|0x11
end_define

begin_comment
comment|/* MC_CMD_MDIO_WRITE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_IN_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_IN_BUS_OFST
value|0
end_define

begin_comment
comment|/*               MC_CMD_MDIO_BUS_INTERNAL 0x0 */
end_comment

begin_comment
comment|/*               MC_CMD_MDIO_BUS_EXTERNAL 0x1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_IN_PRTAD_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_IN_DEVAD_OFST
value|8
end_define

begin_comment
comment|/*               MC_CMD_MDIO_CLAUSE22 0x20 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_IN_ADDR_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_IN_VALUE_OFST
value|16
end_define

begin_comment
comment|/* MC_CMD_MDIO_WRITE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_OUT_STATUS_OFST
value|0
end_define

begin_comment
comment|/*               MC_CMD_MDIO_STATUS_GOOD 0x8 */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DBI_WRITE   * Write DBI register(s).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE
value|0x12
end_define

begin_comment
comment|/* MC_CMD_DBI_WRITE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_LENMIN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+12*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_DBIWROP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_DBIWROP_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_DBIWROP_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_DBIWROP_MAXNUM
value|21
end_define

begin_comment
comment|/* MC_CMD_DBI_WRITE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_DBIWROP_TYPEDEF structuredef */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_ADDRESS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_ADDRESS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_ADDRESS_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_BYTE_MASK_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_BYTE_MASK_LBN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_BYTE_MASK_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_VALUE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_VALUE_LBN
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_VALUE_WIDTH
value|32
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PORT_READ32   * Read a 32-bit register from the indirect port register map.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ32
value|0x14
end_define

begin_comment
comment|/* MC_CMD_PORT_READ32_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ32_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ32_IN_ADDR_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_PORT_READ32_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ32_OUT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ32_OUT_VALUE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ32_OUT_STATUS_OFST
value|4
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PORT_WRITE32   * Write a 32-bit register to the indirect port register map.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE32
value|0x15
end_define

begin_comment
comment|/* MC_CMD_PORT_WRITE32_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE32_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE32_IN_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE32_IN_VALUE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_PORT_WRITE32_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE32_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE32_OUT_STATUS_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PORT_READ128   * Read a 128-bit register from the indirect port register map.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ128
value|0x16
end_define

begin_comment
comment|/* MC_CMD_PORT_READ128_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ128_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ128_IN_ADDR_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_PORT_READ128_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ128_OUT_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ128_OUT_VALUE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ128_OUT_VALUE_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ128_OUT_STATUS_OFST
value|16
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PORT_WRITE128   * Write a 128-bit register to the indirect port register map.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE128
value|0x17
end_define

begin_comment
comment|/* MC_CMD_PORT_WRITE128_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE128_IN_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE128_IN_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE128_IN_VALUE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE128_IN_VALUE_LEN
value|16
end_define

begin_comment
comment|/* MC_CMD_PORT_WRITE128_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE128_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE128_OUT_STATUS_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_BOARD_CFG   * Returns the MC firmware configuration structure.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG
value|0x18
end_define

begin_comment
comment|/* MC_CMD_GET_BOARD_CFG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_BOARD_CFG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_LENMIN
value|96
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_LENMAX
value|136
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(72+2*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_BOARD_TYPE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_BOARD_NAME_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_BOARD_NAME_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_CAPABILITIES_PORT0_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_SMALL_BUF_TBL_LBN
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_SMALL_BUF_TBL_WIDTH
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_TURBO_LBN
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_TURBO_WIDTH
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_TURBO_ACTIVE_LBN
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_TURBO_ACTIVE_WIDTH
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_PTP_LBN
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_PTP_WIDTH
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_AOE_LBN
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_AOE_WIDTH
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_AOE_ACTIVE_LBN
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_AOE_ACTIVE_WIDTH
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_FC_ACTIVE_LBN
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_FC_ACTIVE_WIDTH
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_CAPABILITIES_PORT1_OFST
value|40
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               CAPABILITIES_PORT0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_MAC_ADDR_BASE_PORT0_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_MAC_ADDR_BASE_PORT0_LEN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_MAC_ADDR_BASE_PORT1_OFST
value|50
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_MAC_ADDR_BASE_PORT1_LEN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_MAC_COUNT_PORT0_OFST
value|56
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_MAC_COUNT_PORT1_OFST
value|60
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_MAC_STRIDE_PORT0_OFST
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_MAC_STRIDE_PORT1_OFST
value|68
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_FW_SUBTYPE_LIST_OFST
value|72
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_FW_SUBTYPE_LIST_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_FW_SUBTYPE_LIST_MINNUM
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_FW_SUBTYPE_LIST_MAXNUM
value|32
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DBI_READX   * Read DBI register(s).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX
value|0x19
end_define

begin_comment
comment|/* MC_CMD_DBI_READX_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_IN_LENMIN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_IN_LENMAX
value|248
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+8*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_IN_DBIRDOP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_IN_DBIRDOP_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_IN_DBIRDOP_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_IN_DBIRDOP_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_IN_DBIRDOP_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_IN_DBIRDOP_MAXNUM
value|31
end_define

begin_comment
comment|/* MC_CMD_DBI_READX_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_OUT_VALUE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_OUT_VALUE_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_OUT_VALUE_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX_OUT_VALUE_MAXNUM
value|63
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_RAND_SEED   * Set the 16byte seed for the MC pseudo-random generator.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_RAND_SEED
value|0x1a
end_define

begin_comment
comment|/* MC_CMD_SET_RAND_SEED_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_RAND_SEED_IN_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_RAND_SEED_IN_SEED_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_RAND_SEED_IN_SEED_LEN
value|16
end_define

begin_comment
comment|/* MC_CMD_SET_RAND_SEED_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_RAND_SEED_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_LTSSM_HIST   * Retrieve the history of the PCIE LTSSM.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LTSSM_HIST
value|0x1b
end_define

begin_comment
comment|/* MC_CMD_LTSSM_HIST_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LTSSM_HIST_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_LTSSM_HIST_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LTSSM_HIST_OUT_LENMIN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LTSSM_HIST_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_LTSSM_HIST_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_LTSSM_HIST_OUT_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LTSSM_HIST_OUT_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_LTSSM_HIST_OUT_DATA_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LTSSM_HIST_OUT_DATA_MAXNUM
value|63
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DRV_ATTACH   * Inform MCPU that this port is managed on the host.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH
value|0x1c
end_define

begin_comment
comment|/* MC_CMD_DRV_ATTACH_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_IN_NEW_STATE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_IN_UPDATE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_DRV_ATTACH_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_OUT_OLD_STATE_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SHMUART   * Route UART output to circular buffer in shared memory instead.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SHMUART
value|0x1f
end_define

begin_comment
comment|/* MC_CMD_SHMUART_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SHMUART_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SHMUART_IN_FLAG_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_SHMUART_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SHMUART_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PORT_RESET   * Generic per-port reset.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_RESET
value|0x20
end_define

begin_comment
comment|/* MC_CMD_PORT_RESET_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_RESET_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_PORT_RESET_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_RESET_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PCIE_CREDITS   * Read instantaneous and minimum flow control thresholds.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS
value|0x21
end_define

begin_comment
comment|/* MC_CMD_PCIE_CREDITS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_IN_POLL_PERIOD_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_IN_WIPE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_PCIE_CREDITS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_CURRENT_P_HDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_CURRENT_P_HDR_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_CURRENT_P_DATA_OFST
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_CURRENT_P_DATA_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_CURRENT_NP_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_CURRENT_NP_HDR_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_CURRENT_NP_DATA_OFST
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_CURRENT_NP_DATA_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_MINIMUM_P_HDR_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_MINIMUM_P_HDR_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_MINIMUM_P_DATA_OFST
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_MINIMUM_P_DATA_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_MINIMUM_NP_HDR_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_MINIMUM_NP_HDR_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_MINIMUM_NP_DATA_OFST
value|14
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_OUT_MINIMUM_NP_DATA_LEN
value|2
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_RXD_MONITOR   * Get histogram of RX queue fill level.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR
value|0x22
end_define

begin_comment
comment|/* MC_CMD_RXD_MONITOR_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_IN_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_IN_QID_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_IN_POLL_PERIOD_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_IN_WIPE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_RXD_MONITOR_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_LEN
value|80
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_QID_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_RING_FILL_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_CACHE_FILL_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_RING_LT_1_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_RING_LT_2_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_RING_LT_4_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_RING_LT_8_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_RING_LT_16_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_RING_LT_32_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_RING_LT_64_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_RING_LT_128_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_RING_LT_256_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_RING_GE_256_OFST
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_CACHE_LT_1_OFST
value|52
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_CACHE_LT_2_OFST
value|56
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_CACHE_LT_4_OFST
value|60
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_CACHE_LT_8_OFST
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_CACHE_LT_16_OFST
value|68
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_CACHE_LT_32_OFST
value|72
end_define

begin_define
define|#
directive|define
name|MC_CMD_RXD_MONITOR_OUT_CACHE_GE_32_OFST
value|76
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PUTS   * puts(3) implementation over MCDI  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PUTS
value|0x23
end_define

begin_comment
comment|/* MC_CMD_PUTS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_LENMIN
value|13
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(12+1*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_DEST_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_UART_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_UART_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_PORT_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_PORT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_DHOST_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_DHOST_LEN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_STRING_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_STRING_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_STRING_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PUTS_IN_STRING_MAXNUM
value|240
end_define

begin_comment
comment|/* MC_CMD_PUTS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PUTS_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PHY_CFG   * Report PHY configuration.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG
value|0x24
end_define

begin_comment
comment|/* MC_CMD_GET_PHY_CFG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_PHY_CFG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_LEN
value|72
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_PRESENT_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_PRESENT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_BIST_CABLE_SHORT_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_BIST_CABLE_SHORT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_BIST_CABLE_LONG_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_BIST_CABLE_LONG_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_LOWPOWER_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_LOWPOWER_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_POWEROFF_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_POWEROFF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_TXDIS_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_TXDIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_BIST_LBN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_BIST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_TYPE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_SUPPORTED_CAP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_10HDX_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_10HDX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_10FDX_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_10FDX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_100HDX_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_100HDX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_100FDX_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_100FDX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_1000HDX_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_1000HDX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_1000FDX_LBN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_1000FDX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_10000FDX_LBN
value|7
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_10000FDX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_PAUSE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_PAUSE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_ASYM_LBN
value|9
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_ASYM_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_AN_LBN
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_AN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_DDM_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_DDM_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_CHANNEL_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_PRT_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_STATS_MASK_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_NAME_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_NAME_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_MEDIA_TYPE_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_XAUI
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_CX4
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_KX4
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_XFP
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_SFP_PLUS
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_BASE_T
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_MMD_MASK_OFST
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE22
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE45_PMAPMD
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE45_WIS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE45_PCS
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE45_PHYXS
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE45_DTEXS
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE45_TC
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE45_AN
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE45_C22EXT
value|0x1d
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE45_VEND1
value|0x1e
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE45_VEND2
value|0x1f
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_REVISION_OFST
value|52
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_REVISION_LEN
value|20
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_START_BIST   * Start a BIST test on the PHY.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_START_BIST
value|0x25
end_define

begin_comment
comment|/* MC_CMD_START_BIST_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_START_BIST_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_START_BIST_IN_TYPE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_BIST_CABLE_SHORT
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_BIST_CABLE_LONG
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_BPX_SERDES_BIST
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MC_LOOPBACK_BIST
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_BIST
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_START_BIST_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_START_BIST_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_POLL_BIST   * Poll for BIST completion.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST
value|0x26
end_define

begin_comment
comment|/* MC_CMD_POLL_BIST_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_POLL_BIST_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_RESULT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_RUNNING
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_PASSED
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_FAILED
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_TIMEOUT
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_PRIVATE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_POLL_BIST_OUT_SFT9001 msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_SFT9001_LEN
value|36
end_define

begin_comment
comment|/*            MC_CMD_POLL_BIST_OUT_RESULT_OFST 0 */
end_comment

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_POLL_BIST_OUT/MC_CMD_POLL_BIST_OUT_RESULT */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_SFT9001_CABLE_LENGTH_A_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_SFT9001_CABLE_LENGTH_B_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_SFT9001_CABLE_LENGTH_C_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_SFT9001_CABLE_LENGTH_D_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_SFT9001_CABLE_STATUS_A_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_SFT9001_PAIR_OK
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_SFT9001_PAIR_OPEN
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_SFT9001_INTRA_PAIR_SHORT
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_SFT9001_INTER_PAIR_SHORT
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_SFT9001_PAIR_BUSY
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_SFT9001_CABLE_STATUS_B_OFST
value|24
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               CABLE_STATUS_A */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_SFT9001_CABLE_STATUS_C_OFST
value|28
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               CABLE_STATUS_A */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_SFT9001_CABLE_STATUS_D_OFST
value|32
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               CABLE_STATUS_A */
end_comment

begin_comment
comment|/* MC_CMD_POLL_BIST_OUT_MRSFP msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_MRSFP_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_POLL_BIST_OUT_RESULT_OFST 0 */
end_comment

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_POLL_BIST_OUT/MC_CMD_POLL_BIST_OUT_RESULT */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_MRSFP_TEST_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_COMPLETE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_BUS_SWITCH_OFF_I2C_WRITE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_BUS_SWITCH_OFF_I2C_NO_ACCESS_IO_EXP
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_BUS_SWITCH_OFF_I2C_NO_ACCESS_MODULE
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_IO_EXP_I2C_CONFIGURE
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_BUS_SWITCH_I2C_NO_CROSSTALK
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_MODULE_PRESENCE
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_MODULE_ID_I2C_ACCESS
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_MODULE_ID_SANE_VALUE
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FLUSH_RX_QUEUES   * Flush receive queue(s).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FLUSH_RX_QUEUES
value|0x27
end_define

begin_comment
comment|/* MC_CMD_FLUSH_RX_QUEUES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FLUSH_RX_QUEUES_IN_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FLUSH_RX_QUEUES_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_FLUSH_RX_QUEUES_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_FLUSH_RX_QUEUES_IN_QID_OFST_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FLUSH_RX_QUEUES_IN_QID_OFST_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FLUSH_RX_QUEUES_IN_QID_OFST_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FLUSH_RX_QUEUES_IN_QID_OFST_MAXNUM
value|63
end_define

begin_comment
comment|/* MC_CMD_FLUSH_RX_QUEUES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FLUSH_RX_QUEUES_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_LOOPBACK_MODES   * Get port's loopback modes.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES
value|0x28
end_define

begin_comment
comment|/* MC_CMD_GET_LOOPBACK_MODES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_LOOPBACK_MODES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_100M_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_100M_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_100M_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_100M_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_NONE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_DATA
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_GMAC
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XGMII
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XGXS
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XAUI
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_GMII
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_SGMII
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XGBR
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XFI
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XAUI_FAR
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_GMII_FAR
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_SGMII_FAR
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XFI_FAR
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_GPHY
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_PHYXS
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_PCS
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_PMAPMD
value|0x11
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XPORT
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XGMII_WS
value|0x13
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XAUI_WS
value|0x14
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XAUI_WS_FAR
value|0x15
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XAUI_WS_NEAR
value|0x16
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_GMII_WS
value|0x17
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XFI_WS
value|0x18
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XFI_WS_FAR
value|0x19
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_PHYXS_WS
value|0x1a
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_AOE_INT_NEAR
value|0x23
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_1G_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_1G_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_1G_LO_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_1G_HI_OFST
value|12
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               100M */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_10G_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_10G_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_10G_LO_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_10G_HI_OFST
value|20
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               100M */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_SUGGESTED_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_SUGGESTED_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_SUGGESTED_LO_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_SUGGESTED_HI_OFST
value|28
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               100M */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_LINK   * Read the unified MAC/PHY link state.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK
value|0x29
end_define

begin_comment
comment|/* MC_CMD_GET_LINK_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_LINK_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LEN
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_CAP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LP_CAP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LINK_SPEED_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LOOPBACK_MODE_OFST
value|12
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_GET_LOOPBACK_MODES/MC_CMD_GET_LOOPBACK_MODES_OUT/100M */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_FLAGS_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LINK_UP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LINK_UP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_FULL_DUPLEX_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_FULL_DUPLEX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_BPX_LINK_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_BPX_LINK_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_PHY_LINK_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_PHY_LINK_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LINK_FAULT_RX_LBN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LINK_FAULT_RX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LINK_FAULT_TX_LBN
value|7
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LINK_FAULT_TX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_FCNTL_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FCNTL_OFF
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FCNTL_RESPOND
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FCNTL_BIDIR
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_MAC_FAULT_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_FAULT_XGMII_LOCAL_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_FAULT_XGMII_LOCAL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_FAULT_XGMII_REMOTE_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_FAULT_XGMII_REMOTE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_FAULT_SGMII_REMOTE_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_FAULT_SGMII_REMOTE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_FAULT_PENDING_RECONFIG_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_FAULT_PENDING_RECONFIG_WIDTH
value|1
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_LINK   * Write the unified MAC/PHY link configuration.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK
value|0x2a
end_define

begin_comment
comment|/* MC_CMD_SET_LINK_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_CAP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_FLAGS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_LOWPOWER_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_LOWPOWER_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_POWEROFF_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_POWEROFF_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_TXDIS_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_TXDIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_LOOPBACK_MODE_OFST
value|8
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_GET_LOOPBACK_MODES/MC_CMD_GET_LOOPBACK_MODES_OUT/100M */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_LOOPBACK_SPEED_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_SET_LINK_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_ID_LED   * Set indentification LED state.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_ID_LED
value|0x2b
end_define

begin_comment
comment|/* MC_CMD_SET_ID_LED_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_ID_LED_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_ID_LED_IN_STATE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LED_OFF
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LED_ON
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LED_DEFAULT
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_SET_ID_LED_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_ID_LED_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_MAC   * Set MAC configuration.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC
value|0x2c
end_define

begin_comment
comment|/* MC_CMD_SET_MAC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_LEN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_MTU_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_DRAIN_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_ADDR_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_ADDR_LO_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_ADDR_HI_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_REJECT_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_REJECT_UNCST_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_REJECT_UNCST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_REJECT_BRDCST_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_REJECT_BRDCST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_FCNTL_OFST
value|20
end_define

begin_comment
comment|/*               MC_CMD_FCNTL_OFF 0x0 */
end_comment

begin_comment
comment|/*               MC_CMD_FCNTL_RESPOND 0x1 */
end_comment

begin_comment
comment|/*               MC_CMD_FCNTL_BIDIR 0x2 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FCNTL_AUTO
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_SET_MAC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PHY_STATS   * Get generic PHY statistics.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS
value|0x2d
end_define

begin_comment
comment|/* MC_CMD_PHY_STATS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS_IN_DMA_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS_IN_DMA_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS_IN_DMA_ADDR_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS_IN_DMA_ADDR_HI_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_PHY_STATS_OUT_DMA msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS_OUT_DMA_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_PHY_STATS_OUT_NO_DMA msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS_OUT_NO_DMA_LEN
value|(((MC_CMD_PHY_NSTATS*32))>>3)
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS_OUT_NO_DMA_STATISTICS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS_OUT_NO_DMA_STATISTICS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS_OUT_NO_DMA_STATISTICS_NUM
value|MC_CMD_PHY_NSTATS
end_define

begin_define
define|#
directive|define
name|MC_CMD_OUI
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_LINK_UP
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_RX_FAULT
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_TX_FAULT
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_SIGNAL
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_SNR_A
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_SNR_B
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_SNR_C
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_SNR_D
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCS_LINK_UP
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCS_RX_FAULT
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCS_TX_FAULT
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCS_BER
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCS_BLOCK_ERRORS
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHYXS_LINK_UP
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHYXS_RX_FAULT
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHYXS_TX_FAULT
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHYXS_ALIGN
value|0x11
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHYXS_SYNC
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AN_LINK_UP
value|0x13
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AN_COMPLETE
value|0x14
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AN_10GBT_STATUS
value|0x15
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CL22_LINK_UP
value|0x16
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_NSTATS
value|0x17
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_MAC_STATS   * Get generic MAC statistics.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS
value|0x2e
end_define

begin_comment
comment|/* MC_CMD_MAC_STATS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_DMA_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_DMA_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_DMA_ADDR_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_DMA_ADDR_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_CMD_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_DMA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_DMA_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_CLEAR_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_CLEAR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_PERIODIC_CHANGE_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_PERIODIC_CHANGE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_PERIODIC_ENABLE_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_PERIODIC_ENABLE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_PERIODIC_CLEAR_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_PERIODIC_CLEAR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_PERIODIC_NOEVENT_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_PERIODIC_NOEVENT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_PERIOD_MS_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_PERIOD_MS_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_DMA_LEN_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_MAC_STATS_OUT_DMA msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_OUT_DMA_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MAC_STATS_OUT_NO_DMA msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_OUT_NO_DMA_LEN
value|(((MC_CMD_MAC_NSTATS*64))>>3)
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_OUT_NO_DMA_STATISTICS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_OUT_NO_DMA_STATISTICS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_OUT_NO_DMA_STATISTICS_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_OUT_NO_DMA_STATISTICS_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_OUT_NO_DMA_STATISTICS_NUM
value|MC_CMD_MAC_NSTATS
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_GENERATION_START
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_PKTS
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_PAUSE_PKTS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_CONTROL_PKTS
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_UNICAST_PKTS
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_MULTICAST_PKTS
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_BROADCAST_PKTS
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_BYTES
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_BAD_BYTES
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_LT64_PKTS
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_64_PKTS
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_65_TO_127_PKTS
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_128_TO_255_PKTS
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_256_TO_511_PKTS
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_512_TO_1023_PKTS
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_1024_TO_15XX_PKTS
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_15XX_TO_JUMBO_PKTS
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_GTJUMBO_PKTS
value|0x11
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_BAD_FCS_PKTS
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_SINGLE_COLLISION_PKTS
value|0x13
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_MULTIPLE_COLLISION_PKTS
value|0x14
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_EXCESSIVE_COLLISION_PKTS
value|0x15
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_LATE_COLLISION_PKTS
value|0x16
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_DEFERRED_PKTS
value|0x17
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_EXCESSIVE_DEFERRED_PKTS
value|0x18
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_NON_TCPUDP_PKTS
value|0x19
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_MAC_SRC_ERR_PKTS
value|0x1a
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_TX_IP_SRC_ERR_PKTS
value|0x1b
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_PKTS
value|0x1c
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_PAUSE_PKTS
value|0x1d
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_GOOD_PKTS
value|0x1e
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_CONTROL_PKTS
value|0x1f
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_UNICAST_PKTS
value|0x20
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_MULTICAST_PKTS
value|0x21
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_BROADCAST_PKTS
value|0x22
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_BYTES
value|0x23
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_BAD_BYTES
value|0x24
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_64_PKTS
value|0x25
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_65_TO_127_PKTS
value|0x26
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_128_TO_255_PKTS
value|0x27
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_256_TO_511_PKTS
value|0x28
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_512_TO_1023_PKTS
value|0x29
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_1024_TO_15XX_PKTS
value|0x2a
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_15XX_TO_JUMBO_PKTS
value|0x2b
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_GTJUMBO_PKTS
value|0x2c
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_UNDERSIZE_PKTS
value|0x2d
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_BAD_FCS_PKTS
value|0x2e
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_OVERFLOW_PKTS
value|0x2f
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_FALSE_CARRIER_PKTS
value|0x30
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_SYMBOL_ERROR_PKTS
value|0x31
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_ALIGN_ERROR_PKTS
value|0x32
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_LENGTH_ERROR_PKTS
value|0x33
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_INTERNAL_ERROR_PKTS
value|0x34
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_JABBER_PKTS
value|0x35
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_NODESC_DROPS
value|0x36
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_LANES01_CHAR_ERR
value|0x37
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_LANES23_CHAR_ERR
value|0x38
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_LANES01_DISP_ERR
value|0x39
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_LANES23_DISP_ERR
value|0x3a
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RX_MATCH_FAULT
value|0x3b
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GMAC_DMABUF_START
value|0x40
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GMAC_DMABUF_END
value|0x5f
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_GENERATION_END
value|0x60
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_NSTATS
value|0x61
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SRIOV   * to be documented  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SRIOV
value|0x30
end_define

begin_comment
comment|/* MC_CMD_SRIOV_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SRIOV_IN_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_SRIOV_IN_ENABLE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SRIOV_IN_VI_BASE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SRIOV_IN_VF_COUNT_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_SRIOV_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SRIOV_OUT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SRIOV_OUT_VI_SCALE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SRIOV_OUT_VF_TOTAL_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_MEMCPY_RECORD_TYPEDEF structuredef */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_NUM_RECORDS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_NUM_RECORDS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_NUM_RECORDS_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_TO_RID_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_TO_RID_LBN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_TO_RID_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_TO_ADDR_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_TO_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_TO_ADDR_LO_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_TO_ADDR_HI_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_TO_ADDR_LBN
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_TO_ADDR_WIDTH
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_FROM_RID_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_RID_INLINE
value|0x100
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_FROM_RID_LBN
value|128
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_FROM_RID_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_FROM_ADDR_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_FROM_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_FROM_ADDR_LO_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_FROM_ADDR_HI_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_FROM_ADDR_LBN
value|160
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_FROM_ADDR_WIDTH
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_LENGTH_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_LENGTH_LBN
value|224
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_RECORD_TYPEDEF_LENGTH_WIDTH
value|32
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_MEMCPY   * Perform memory copy operation.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY
value|0x31
end_define

begin_comment
comment|/* MC_CMD_MEMCPY_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_IN_LENMIN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_IN_LENMAX
value|224
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+32*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_IN_RECORD_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_IN_RECORD_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_IN_RECORD_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_IN_RECORD_MAXNUM
value|7
end_define

begin_comment
comment|/* MC_CMD_MEMCPY_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEMCPY_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_WOL_FILTER_SET   * Set a WoL filter.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET
value|0x32
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_SET_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_LEN
value|192
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_FILTER_MODE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_MODE_SIMPLE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_MODE_STRUCTURED
value|0xffffffff
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_WOL_TYPE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_MAGIC
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_WIN_MAGIC
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_IPV4_SYN
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_IPV6_SYN
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_BITMAP
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_LINK
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_MAX
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_DATA_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_DATA_NUM
value|46
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_SET_IN_MAGIC msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_MAGIC_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_WOL_FILTER_SET_IN_FILTER_MODE_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_WOL_FILTER_SET_IN_WOL_TYPE_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_MAGIC_MAC_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_MAGIC_MAC_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_MAGIC_MAC_LO_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_MAGIC_MAC_HI_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_SET_IN_IPV4_SYN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV4_SYN_LEN
value|20
end_define

begin_comment
comment|/*            MC_CMD_WOL_FILTER_SET_IN_FILTER_MODE_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_WOL_FILTER_SET_IN_WOL_TYPE_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV4_SYN_SRC_IP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV4_SYN_DST_IP_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV4_SYN_SRC_PORT_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV4_SYN_SRC_PORT_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV4_SYN_DST_PORT_OFST
value|18
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV4_SYN_DST_PORT_LEN
value|2
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_SET_IN_IPV6_SYN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV6_SYN_LEN
value|44
end_define

begin_comment
comment|/*            MC_CMD_WOL_FILTER_SET_IN_FILTER_MODE_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_WOL_FILTER_SET_IN_WOL_TYPE_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV6_SYN_SRC_IP_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV6_SYN_SRC_IP_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV6_SYN_DST_IP_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV6_SYN_DST_IP_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV6_SYN_SRC_PORT_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV6_SYN_SRC_PORT_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV6_SYN_DST_PORT_OFST
value|42
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_IPV6_SYN_DST_PORT_LEN
value|2
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_SET_IN_BITMAP msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_BITMAP_LEN
value|187
end_define

begin_comment
comment|/*            MC_CMD_WOL_FILTER_SET_IN_FILTER_MODE_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_WOL_FILTER_SET_IN_WOL_TYPE_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_BITMAP_MASK_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_BITMAP_MASK_LEN
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_BITMAP_BITMAP_OFST
value|56
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_BITMAP_BITMAP_LEN
value|128
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_BITMAP_LEN_OFST
value|184
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_BITMAP_LEN_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_BITMAP_LAYER3_OFST
value|185
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_BITMAP_LAYER3_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_BITMAP_LAYER4_OFST
value|186
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_BITMAP_LAYER4_LEN
value|1
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_SET_IN_LINK msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_LINK_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_WOL_FILTER_SET_IN_FILTER_MODE_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_WOL_FILTER_SET_IN_WOL_TYPE_OFST 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_LINK_MASK_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_LINK_UP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_LINK_UP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_LINK_DOWN_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_LINK_DOWN_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_SET_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_OUT_FILTER_ID_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_WOL_FILTER_REMOVE   * Remove a WoL filter.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_REMOVE
value|0x33
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_REMOVE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_REMOVE_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_REMOVE_IN_FILTER_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_REMOVE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_REMOVE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_WOL_FILTER_RESET   * Reset (i.e. remove all) WoL filters.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_RESET
value|0x34
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_RESET_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_RESET_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_RESET_IN_MASK_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_RESET_IN_WAKE_FILTERS
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_RESET_IN_LIGHTSOUT_OFFLOADS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_WOL_FILTER_RESET_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_RESET_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_MCAST_HASH   * Set the MCASH hash value.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_MCAST_HASH
value|0x35
end_define

begin_comment
comment|/* MC_CMD_SET_MCAST_HASH_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_MCAST_HASH_IN_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MCAST_HASH_IN_HASH0_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MCAST_HASH_IN_HASH0_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MCAST_HASH_IN_HASH1_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MCAST_HASH_IN_HASH1_LEN
value|16
end_define

begin_comment
comment|/* MC_CMD_SET_MCAST_HASH_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_MCAST_HASH_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_TYPES   * Get virtual NVRAM partitions information.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPES
value|0x36
end_define

begin_comment
comment|/* MC_CMD_NVRAM_TYPES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPES_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_NVRAM_TYPES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPES_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPES_OUT_TYPES_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_DISABLED_CALLISTO
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_MC_FW
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_MC_FW_BACKUP
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_STATIC_CFG_PORT0
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_STATIC_CFG_PORT1
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_DYNAMIC_CFG_PORT0
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_DYNAMIC_CFG_PORT1
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_EXP_ROM
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_EXP_ROM_CFG_PORT0
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_EXP_ROM_CFG_PORT1
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_PHY_PORT0
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_PHY_PORT1
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_LOG
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FPGA
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FPGA_BACKUP
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FC_FW
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FC_FW_BACKUP
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_CPLD
value|0x11
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_LICENSE
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FC_LOG
value|0x13
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FC_EXTRA
value|0x14
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_INFO   * Read info about a virtual NVRAM partition.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO
value|0x37
end_define

begin_comment
comment|/* MC_CMD_NVRAM_INFO_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_NVRAM_TYPES/MC_CMD_NVRAM_TYPES_OUT/TYPES */
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_INFO_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_LEN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_TYPE_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_NVRAM_TYPES/MC_CMD_NVRAM_TYPES_OUT/TYPES */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_SIZE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_ERASESIZE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_FLAGS_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_PROTECTED_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_PROTECTED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_PHYSDEV_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_PHYSADDR_OFST
value|20
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_UPDATE_START   * Start a group of update operations on a virtual NVRAM partition.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_UPDATE_START
value|0x38
end_define

begin_comment
comment|/* MC_CMD_NVRAM_UPDATE_START_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_UPDATE_START_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_UPDATE_START_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_NVRAM_TYPES/MC_CMD_NVRAM_TYPES_OUT/TYPES */
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_UPDATE_START_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_UPDATE_START_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_READ   * Read data from a virtual NVRAM partition.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ
value|0x39
end_define

begin_comment
comment|/* MC_CMD_NVRAM_READ_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ_IN_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_NVRAM_TYPES/MC_CMD_NVRAM_TYPES_OUT/TYPES */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ_IN_OFFSET_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ_IN_LENGTH_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_NVRAM_READ_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ_OUT_LENMIN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+1*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ_OUT_READ_BUFFER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ_OUT_READ_BUFFER_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ_OUT_READ_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ_OUT_READ_BUFFER_MAXNUM
value|252
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_WRITE   * Write data to a virtual NVRAM partition.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE
value|0x3a
end_define

begin_comment
comment|/* MC_CMD_NVRAM_WRITE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE_IN_LENMIN
value|13
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(12+1*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_NVRAM_TYPES/MC_CMD_NVRAM_TYPES_OUT/TYPES */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE_IN_OFFSET_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE_IN_LENGTH_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE_IN_WRITE_BUFFER_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE_IN_WRITE_BUFFER_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE_IN_WRITE_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE_IN_WRITE_BUFFER_MAXNUM
value|240
end_define

begin_comment
comment|/* MC_CMD_NVRAM_WRITE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_ERASE   * Erase sector(s) from a virtual NVRAM partition.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_ERASE
value|0x3b
end_define

begin_comment
comment|/* MC_CMD_NVRAM_ERASE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_ERASE_IN_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_ERASE_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_NVRAM_TYPES/MC_CMD_NVRAM_TYPES_OUT/TYPES */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_ERASE_IN_OFFSET_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_ERASE_IN_LENGTH_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_NVRAM_ERASE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_ERASE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_UPDATE_FINISH   * Finish a group of update operations on a virtual NVRAM partition.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_UPDATE_FINISH
value|0x3c
end_define

begin_comment
comment|/* MC_CMD_NVRAM_UPDATE_FINISH_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_UPDATE_FINISH_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_UPDATE_FINISH_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_NVRAM_TYPES/MC_CMD_NVRAM_TYPES_OUT/TYPES */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_UPDATE_FINISH_IN_REBOOT_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_NVRAM_UPDATE_FINISH_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_UPDATE_FINISH_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_REBOOT   * Reboot the MC.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT
value|0x3d
end_define

begin_comment
comment|/* MC_CMD_REBOOT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_IN_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_FLAGS_AFTER_ASSERTION
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_REBOOT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SCHEDINFO   * Request scheduler info.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SCHEDINFO
value|0x3e
end_define

begin_comment
comment|/* MC_CMD_SCHEDINFO_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SCHEDINFO_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_SCHEDINFO_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SCHEDINFO_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SCHEDINFO_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_SCHEDINFO_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_SCHEDINFO_OUT_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SCHEDINFO_OUT_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SCHEDINFO_OUT_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SCHEDINFO_OUT_DATA_MAXNUM
value|63
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_REBOOT_MODE   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE
value|0x3f
end_define

begin_comment
comment|/* MC_CMD_REBOOT_MODE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_IN_VALUE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_NORMAL
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_SNAPPER
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_REBOOT_MODE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_OUT_VALUE_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SENSOR_INFO   * Returns information about every available sensor.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO
value|0x41
end_define

begin_comment
comment|/* MC_CMD_SENSOR_INFO_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_SENSOR_INFO_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_OUT_LENMIN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+8*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_OUT_MASK_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_TEMP
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY_COMMON_TEMP
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_COOLING
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY0_TEMP
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY0_COOLING
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY1_TEMP
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY1_COOLING
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_1V0
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_1V2
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_1V8
value|0x9
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_2V5
value|0xa
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_3V3
value|0xb
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_12V0
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_1V2A
value|0xd
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_VREF
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_OUT_VAOE
value|0xf
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_AOE_TEMP
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PSU_AOE_TEMP
value|0x11
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PSU_TEMP
value|0x12
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_FAN_0
value|0x13
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_FAN_1
value|0x14
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_FAN_2
value|0x15
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_FAN_3
value|0x16
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_FAN_4
value|0x17
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_VAOE
value|0x18
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_OUT_IAOE
value|0x19
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_IAOE
value|0x1a
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_NIC_POWER
value|0x1b
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_ENTRY_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_ENTRY_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_ENTRY_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_ENTRY_HI_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_ENTRY_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_ENTRY_MAXNUM
value|31
end_define

begin_comment
comment|/* MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF structuredef */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MIN1_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MIN1_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MIN1_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MIN1_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MAX1_OFST
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MAX1_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MAX1_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MAX1_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MIN2_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MIN2_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MIN2_LBN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MIN2_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MAX2_OFST
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MAX2_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MAX2_LBN
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF_MAX2_WIDTH
value|16
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_READ_SENSORS   * Returns the current reading from each sensor.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS
value|0x42
end_define

begin_comment
comment|/* MC_CMD_READ_SENSORS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_IN_DMA_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_IN_DMA_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_IN_DMA_ADDR_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_IN_DMA_ADDR_HI_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_READ_SENSORS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF structuredef */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_LEN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_VALUE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_VALUE_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_VALUE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_VALUE_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_STATE_OFST
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_STATE_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_STATE_OK
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_STATE_WARNING
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_STATE_FATAL
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_STATE_BROKEN
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_STATE_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_STATE_WIDTH
value|8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PHY_STATE   * Report current state of PHY.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_STATE
value|0x43
end_define

begin_comment
comment|/* MC_CMD_GET_PHY_STATE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_STATE_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_PHY_STATE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_STATE_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_STATE_OUT_STATE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATE_OK
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATE_ZOMBIE
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SETUP_8021QBB   * 802.1Qbb control.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SETUP_8021QBB
value|0x44
end_define

begin_comment
comment|/* MC_CMD_SETUP_8021QBB_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SETUP_8021QBB_IN_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_SETUP_8021QBB_IN_TXQS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SETUP_8021QBB_IN_TXQS_LEN
value|32
end_define

begin_comment
comment|/* MC_CMD_SETUP_8021QBB_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SETUP_8021QBB_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_WOL_FILTER_GET   * Retrieve ID of any WoL filters.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_GET
value|0x45
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_GET_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_GET_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_WOL_FILTER_GET_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_GET_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_GET_OUT_FILTER_ID_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_ADD_LIGHTSOUT_OFFLOAD   * Add a protocol offload to NIC for lights-out state.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD
value|0x46
end_define

begin_comment
comment|/* MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_LENMIN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_PROTOCOL_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LIGHTSOUT_OFFLOAD_PROTOCOL_ARP
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LIGHTSOUT_OFFLOAD_PROTOCOL_NS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_DATA_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_DATA_MAXNUM
value|62
end_define

begin_comment
comment|/* MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_ARP msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_ARP_LEN
value|14
end_define

begin_comment
comment|/*            MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_PROTOCOL_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_ARP_MAC_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_ARP_MAC_LEN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_ARP_IP_OFST
value|10
end_define

begin_comment
comment|/* MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_NS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_NS_LEN
value|42
end_define

begin_comment
comment|/*            MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_PROTOCOL_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_NS_MAC_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_NS_MAC_LEN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_NS_SNIPV6_OFST
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_NS_SNIPV6_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_NS_IPV6_OFST
value|26
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_IN_NS_IPV6_LEN
value|16
end_define

begin_comment
comment|/* MC_CMD_ADD_LIGHTSOUT_OFFLOAD_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD_OUT_FILTER_ID_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_REMOVE_LIGHTSOUT_OFFLOAD   * Remove a protocol offload from NIC for lights-out state.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REMOVE_LIGHTSOUT_OFFLOAD
value|0x47
end_define

begin_comment
comment|/* MC_CMD_REMOVE_LIGHTSOUT_OFFLOAD_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REMOVE_LIGHTSOUT_OFFLOAD_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_REMOVE_LIGHTSOUT_OFFLOAD_IN_PROTOCOL_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_REMOVE_LIGHTSOUT_OFFLOAD_IN_FILTER_ID_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_REMOVE_LIGHTSOUT_OFFLOAD_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REMOVE_LIGHTSOUT_OFFLOAD_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_MAC_RESET_RESTORE   * Restore MAC after block reset.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RESET_RESTORE
value|0x48
end_define

begin_comment
comment|/* MC_CMD_MAC_RESET_RESTORE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RESET_RESTORE_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MAC_RESET_RESTORE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RESET_RESTORE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_TESTASSERT    */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TESTASSERT
value|0x49
end_define

begin_comment
comment|/* MC_CMD_TESTASSERT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TESTASSERT_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_TESTASSERT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TESTASSERT_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_WORKAROUND   * Enable/Disable a given workaround.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND
value|0x4a
end_define

begin_comment
comment|/* MC_CMD_WORKAROUND_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_IN_TYPE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_BUG17230
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_IN_ENABLED_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_WORKAROUND_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PHY_MEDIA_INFO   * Read media-specific data from PHY.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO
value|0x4b
end_define

begin_comment
comment|/* MC_CMD_GET_PHY_MEDIA_INFO_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO_IN_PAGE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_PHY_MEDIA_INFO_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO_OUT_LENMIN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+1*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO_OUT_DATALEN_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO_OUT_DATA_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO_OUT_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO_OUT_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO_OUT_DATA_MAXNUM
value|248
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_TEST   * Test a particular NVRAM partition.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST
value|0x4c
end_define

begin_comment
comment|/* MC_CMD_NVRAM_TEST_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_NVRAM_TYPES/MC_CMD_NVRAM_TYPES_OUT/TYPES */
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_TEST_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST_OUT_RESULT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST_PASS
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST_FAIL
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST_NOTSUPP
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_MRSFP_TWEAK   * Read status and/or set parameters for the 'mrsfp' driver.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK
value|0x4d
end_define

begin_comment
comment|/* MC_CMD_MRSFP_TWEAK_IN_EQ_CONFIG msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_IN_EQ_CONFIG_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_IN_EQ_CONFIG_TXEQ_LEVEL_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_IN_EQ_CONFIG_TXEQ_DT_CFG_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_IN_EQ_CONFIG_RXEQ_BOOST_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_IN_EQ_CONFIG_RXEQ_DT_CFG_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_MRSFP_TWEAK_IN_READ_ONLY msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_IN_READ_ONLY_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MRSFP_TWEAK_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_OUT_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_OUT_IOEXP_INPUTS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_OUT_IOEXP_OUTPUTS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_OUT_IOEXP_DIRECTION_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_OUT_IOEXP_DIRECTION_OUT
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_OUT_IOEXP_DIRECTION_IN
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SENSOR_SET_LIMS   * Adjusts the sensor limits.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS
value|0x4e
end_define

begin_comment
comment|/* MC_CMD_SENSOR_SET_LIMS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS_IN_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS_IN_SENSOR_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_SENSOR_INFO/MC_CMD_SENSOR_INFO_OUT/MASK */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS_IN_LOW0_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS_IN_HI0_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS_IN_LOW1_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS_IN_HI1_OFST
value|16
end_define

begin_comment
comment|/* MC_CMD_SENSOR_SET_LIMS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_RESOURCE_LIMITS   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_RESOURCE_LIMITS
value|0x4f
end_define

begin_comment
comment|/* MC_CMD_GET_RESOURCE_LIMITS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_RESOURCE_LIMITS_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_RESOURCE_LIMITS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_RESOURCE_LIMITS_OUT_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_RESOURCE_LIMITS_OUT_BUFTBL_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_RESOURCE_LIMITS_OUT_EVQ_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_RESOURCE_LIMITS_OUT_RXQ_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_RESOURCE_LIMITS_OUT_TXQ_OFST
value|12
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_CLP   * CLP support operations  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP
value|0x56
end_define

begin_comment
comment|/* MC_CMD_CLP_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_OP_DEFAULT
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OP_SET_MAC
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OP_GET_MAC
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OP_SET_BOOT
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OP_GET_BOOT
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_CLP_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_CLP_IN_DEFAULT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_DEFAULT_LEN
value|4
end_define

begin_comment
comment|/*            MC_CMD_CLP_IN_OP_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_CLP_OUT_DEFAULT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_DEFAULT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_CLP_IN_SET_MAC msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_SET_MAC_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_CLP_IN_OP_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_SET_MAC_ADDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_SET_MAC_ADDR_LEN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_SET_MAC_RESERVED_OFST
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_SET_MAC_RESERVED_LEN
value|2
end_define

begin_comment
comment|/* MC_CMD_CLP_OUT_SET_MAC msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_SET_MAC_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_CLP_IN_GET_MAC msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_GET_MAC_LEN
value|4
end_define

begin_comment
comment|/*            MC_CMD_CLP_IN_OP_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_CLP_OUT_GET_MAC msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_GET_MAC_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_GET_MAC_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_GET_MAC_ADDR_LEN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_GET_MAC_RESERVED_OFST
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_GET_MAC_RESERVED_LEN
value|2
end_define

begin_comment
comment|/* MC_CMD_CLP_IN_SET_BOOT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_SET_BOOT_LEN
value|5
end_define

begin_comment
comment|/*            MC_CMD_CLP_IN_OP_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_SET_BOOT_FLAG_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_SET_BOOT_FLAG_LEN
value|1
end_define

begin_comment
comment|/* MC_CMD_CLP_OUT_SET_BOOT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_SET_BOOT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_CLP_IN_GET_BOOT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_GET_BOOT_LEN
value|4
end_define

begin_comment
comment|/*            MC_CMD_CLP_IN_OP_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_CLP_OUT_GET_BOOT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_GET_BOOT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_GET_BOOT_FLAG_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_GET_BOOT_FLAG_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_GET_BOOT_RESERVED_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_CLP_OUT_GET_BOOT_RESERVED_LEN
value|3
end_define

begin_comment
comment|/* MC_CMD_RESOURCE_SPECIFIER enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RESOURCE_INSTANCE_ANY
value|0xffffffff
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RESOURCE_INSTANCE_NONE
value|0xfffffffe
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_INIT_EVQ   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ
value|0x50
end_define

begin_comment
comment|/* MC_CMD_INIT_EVQ_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_LENMIN
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_LENMAX
value|540
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(28+8*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_SIZE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_INSTANCE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_LOAD_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_RELOAD_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAGS_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAG_INTERRUPTING_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAG_INTERRUPTING_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAG_RPTR_DOS_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAG_RPTR_DOS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_MODE_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_MODE_DIS
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_IMMED_START
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_TRIG_START
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_INT_HLDOFF
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TARGET_EVQ_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_IRQ_NUM_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_DMA_ADDR_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_DMA_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_DMA_ADDR_LO_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_DMA_ADDR_HI_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_DMA_ADDR_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_DMA_ADDR_MAXNUM
value|64
end_define

begin_comment
comment|/* MC_CMD_INIT_EVQ_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_OUT_IRQ_OFST
value|0
end_define

begin_comment
comment|/* QUEUE_CRC_MODE structuredef */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_LEN
value|1
end_define

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_MODE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_NONE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_FCOE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_ISCSI_HDR
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_ISCSI
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_FCOIPOE
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_MPA
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_SPARE_LBN
value|4
end_define

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_SPARE_WIDTH
value|4
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_INIT_RXQ   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ
value|0x51
end_define

begin_comment
comment|/* MC_CMD_INIT_RXQ_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_LENMIN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_LENMAX
value|248
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(24+8*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_SIZE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_TARGET_EVQ_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_LABEL_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_INSTANCE_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAGS_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_BUFF_MODE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_BUFF_MODE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_HDR_SPLIT_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_HDR_SPLIT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_PKT_EDIT_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_PKT_EDIT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_CRC_MODE_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_CRC_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_OWNER_ID_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_DMA_ADDR_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_DMA_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_DMA_ADDR_LO_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_DMA_ADDR_HI_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_DMA_ADDR_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_DMA_ADDR_MAXNUM
value|28
end_define

begin_comment
comment|/* MC_CMD_INIT_RXQ_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_INIT_TXQ   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ
value|0x52
end_define

begin_comment
comment|/* MC_CMD_INIT_TXQ_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_LENMIN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_LENMAX
value|248
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(24+8*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_SIZE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_TARGET_EVQ_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_LABEL_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_INSTANCE_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAGS_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_BUFF_MODE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_BUFF_MODE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_IP_CSUM_DIS_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_IP_CSUM_DIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_TCP_CSUM_DIS_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_TCP_CSUM_DIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_TCP_UDP_ONLY_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_TCP_UDP_ONLY_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_CRC_MODE_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_CRC_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_OWNER_ID_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_DMA_ADDR_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_DMA_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_DMA_ADDR_LO_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_DMA_ADDR_HI_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_DMA_ADDR_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_DMA_ADDR_MAXNUM
value|28
end_define

begin_comment
comment|/* MC_CMD_INIT_TXQ_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FINI_EVQ   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_EVQ
value|0x55
end_define

begin_comment
comment|/* MC_CMD_FINI_EVQ_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_EVQ_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FINI_EVQ_IN_INSTANCE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FINI_EVQ_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_EVQ_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FINI_RXQ   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_RXQ
value|0x56
end_define

begin_comment
comment|/* MC_CMD_FINI_RXQ_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_RXQ_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FINI_RXQ_IN_INSTANCE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FINI_RXQ_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_RXQ_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FINI_TXQ   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_TXQ
value|0x57
end_define

begin_comment
comment|/* MC_CMD_FINI_TXQ_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_TXQ_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FINI_TXQ_IN_INSTANCE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FINI_TXQ_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_TXQ_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DRIVER_EVENT   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRIVER_EVENT
value|0x5a
end_define

begin_comment
comment|/* MC_CMD_DRIVER_EVENT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRIVER_EVENT_IN_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DRIVER_EVENT_IN_EVQ_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DRIVER_EVENT_IN_DATA_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DRIVER_EVENT_IN_DATA_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DRIVER_EVENT_IN_DATA_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DRIVER_EVENT_IN_DATA_HI_OFST
value|8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PROXY_CMD   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CMD
value|0x5b
end_define

begin_comment
comment|/* MC_CMD_PROXY_CMD_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CMD_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CMD_IN_TARGET_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_ALLOC_OWNER_IDS   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_OWNER_IDS
value|0x54
end_define

begin_comment
comment|/* MC_CMD_ALLOC_OWNER_IDS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_OWNER_IDS_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_OWNER_IDS_IN_NIDS_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_ALLOC_OWNER_IDS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_OWNER_IDS_OUT_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_OWNER_IDS_OUT_HANDLE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_OWNER_IDS_OUT_NIDS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_OWNER_IDS_OUT_BASE_OFST
value|8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FREE_OWNER_IDS   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_OWNER_IDS
value|0x59
end_define

begin_comment
comment|/* MC_CMD_FREE_OWNER_IDS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_OWNER_IDS_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FREE_OWNER_IDS_IN_HANDLE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FREE_OWNER_IDS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_OWNER_IDS_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_ALLOC_BUFTBL_CHUNK   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_BUFTBL_CHUNK
value|0x5c
end_define

begin_comment
comment|/* MC_CMD_ALLOC_BUFTBL_CHUNK_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_BUFTBL_CHUNK_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_BUFTBL_CHUNK_IN_OWNER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_BUFTBL_CHUNK_IN_PAGE_SIZE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_ALLOC_BUFTBL_CHUNK_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_BUFTBL_CHUNK_OUT_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_BUFTBL_CHUNK_OUT_HANDLE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_BUFTBL_CHUNK_OUT_NUMENTRIES_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_BUFTBL_CHUNK_OUT_ID_OFST
value|8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PROGRAM_BUFTBL_ENTRIES   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES
value|0x5d
end_define

begin_comment
comment|/* MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_LENMIN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(12+8*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_HANDLE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_FIRSTID_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_NUMENTRIES_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_ENTRY_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_ENTRY_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_ENTRY_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_ENTRY_HI_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_ENTRY_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_ENTRY_MAXNUM
value|30
end_define

begin_comment
comment|/* MC_CMD_PROGRAM_BUFTBL_ENTRIES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FREE_BUFTBL_CHUNK   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_BUFTBL_CHUNK
value|0x5e
end_define

begin_comment
comment|/* MC_CMD_FREE_BUFTBL_CHUNK_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_BUFTBL_CHUNK_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FREE_BUFTBL_CHUNK_IN_HANDLE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FREE_BUFTBL_CHUNK_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_BUFTBL_CHUNK_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PF_COUNT   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PF_COUNT
value|0x60
end_define

begin_comment
comment|/* MC_CMD_GET_PF_COUNT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PF_COUNT_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_PF_COUNT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PF_COUNT_OUT_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PF_COUNT_OUT_PF_COUNT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PF_COUNT_OUT_PF_COUNT_LEN
value|1
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FILTER_OP   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP
value|0x61
end_define

begin_comment
comment|/* MC_CMD_FILTER_OP_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_LEN
value|100
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OP_INSERT
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OP_REMOVE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OP_SUBSCRIBE
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OP_UNSUBSCRIBE
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_HANDLE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_FIELDS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_SRC_IP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_SRC_IP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_DST_IP_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_DST_IP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_SRC_MAC_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_SRC_MAC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_SRC_PORT_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_SRC_PORT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_DST_MAC_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_DST_MAC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_DST_PORT_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_DST_PORT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_ETHER_TYPE_LBN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_ETHER_TYPE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_INNER_VLAN_LBN
value|7
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_INNER_VLAN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_OUTER_VLAN_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_OUTER_VLAN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_IP_PROTO_LBN
value|9
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_IP_PROTO_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_FWDEF0_LBN
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_FWDEF0_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_FWDEF1_LBN
value|11
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_FWDEF1_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_DROP
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_HOST
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_MC
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_TX0
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_TX1
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_QUEUE_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_FLAGS_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_FLAG_RSS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_FLAG_RSS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RSS_CONTEXT_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_TX_DOMAIN_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_TX_DEST_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_TX_DEST_MAC_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_TX_DEST_MAC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_TX_DEST_PM_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_TX_DEST_PM_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_MAC_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_MAC_LEN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_PORT_OFST
value|42
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_PORT_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_MAC_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_MAC_LEN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_PORT_OFST
value|50
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_PORT_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_ETHER_TYPE_OFST
value|52
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_ETHER_TYPE_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_INNER_VLAN_OFST
value|54
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_INNER_VLAN_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OUTER_VLAN_OFST
value|56
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OUTER_VLAN_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_IP_PROTO_OFST
value|58
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_IP_PROTO_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_FWDEF0_OFST
value|60
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_FWDEF1_OFST
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_IP_OFST
value|68
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_IP_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_IP_OFST
value|84
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_IP_LEN
value|16
end_define

begin_comment
comment|/* MC_CMD_FILTER_OP_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_OP_INSERT
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_OP_REMOVE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_OP_SUBSCRIBE
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_OP_UNSUBSCRIBE
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_HANDLE_OFST
value|4
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_PF_COUNT   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PF_COUNT
value|0x62
end_define

begin_comment
comment|/* MC_CMD_SET_PF_COUNT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PF_COUNT_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PF_COUNT_IN_PF_COUNT_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_SET_PF_COUNT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PF_COUNT_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PORT_ASSIGNMENT   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_ASSIGNMENT
value|0x63
end_define

begin_comment
comment|/* MC_CMD_GET_PORT_ASSIGNMENT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_ASSIGNMENT_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_PORT_ASSIGNMENT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_ASSIGNMENT_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_ASSIGNMENT_OUT_PORT_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_PORT_ASSIGNMENT   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_ASSIGNMENT
value|0x64
end_define

begin_comment
comment|/* MC_CMD_SET_PORT_ASSIGNMENT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_ASSIGNMENT_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_ASSIGNMENT_IN_PORT_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_SET_PORT_ASSIGNMENT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_ASSIGNMENT_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_ALLOC_VIS   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS
value|0x65
end_define

begin_comment
comment|/* MC_CMD_ALLOC_VIS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_IN_VI_COUNT_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_ALLOC_VIS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FREE_VIS   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_VIS
value|0x66
end_define

begin_comment
comment|/* MC_CMD_FREE_VIS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_VIS_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FREE_VIS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_VIS_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_SRIOV_CFG   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG
value|0x67
end_define

begin_comment
comment|/* MC_CMD_GET_SRIOV_CFG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_SRIOV_CFG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG_OUT_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG_OUT_VF_CURRENT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG_OUT_VF_MAX_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG_OUT_FLAGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG_OUT_VF_ENABLED_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG_OUT_VF_ENABLED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG_OUT_VF_OFFSET_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG_OUT_VF_STRIDE_OFST
value|16
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_SRIOV_CFG   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG
value|0x68
end_define

begin_comment
comment|/* MC_CMD_SET_SRIOV_CFG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG_IN_LEN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG_IN_VF_CURRENT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG_IN_VF_MAX_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG_IN_FLAGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG_IN_VF_ENABLED_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG_IN_VF_ENABLED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG_IN_VF_OFFSET_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG_IN_VF_STRIDE_OFST
value|16
end_define

begin_comment
comment|/* MC_CMD_SET_SRIOV_CFG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_VI_COUNT   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_COUNT
value|0x69
end_define

begin_comment
comment|/* MC_CMD_GET_VI_COUNT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_COUNT_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_VI_COUNT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_COUNT_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_COUNT_OUT_VI_COUNT_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_VECTOR_CFG   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VECTOR_CFG
value|0x70
end_define

begin_comment
comment|/* MC_CMD_GET_VECTOR_CFG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VECTOR_CFG_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_VECTOR_CFG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VECTOR_CFG_OUT_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VECTOR_CFG_OUT_VEC_BASE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VECTOR_CFG_OUT_VECS_PER_PF_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VECTOR_CFG_OUT_VECS_PER_VF_OFST
value|8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_VECTOR_CFG   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VECTOR_CFG
value|0x71
end_define

begin_comment
comment|/* MC_CMD_SET_VECTOR_CFG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VECTOR_CFG_IN_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_VECTOR_CFG_IN_VEC_BASE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_VECTOR_CFG_IN_VECS_PER_PF_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_VECTOR_CFG_IN_VECS_PER_VF_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_SET_VECTOR_CFG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VECTOR_CFG_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_ALLOC_PIOBUF   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_PIOBUF
value|0x72
end_define

begin_comment
comment|/* MC_CMD_ALLOC_PIOBUF_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_PIOBUF_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_ALLOC_PIOBUF_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_PIOBUF_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_PIOBUF_OUT_PIOBUF_HANDLE_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FREE_PIOBUF   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_PIOBUF
value|0x73
end_define

begin_comment
comment|/* MC_CMD_FREE_PIOBUF_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_PIOBUF_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FREE_PIOBUF_IN_PIOBUF_HANDLE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_FREE_PIOBUF_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_PIOBUF_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_V2_EXTN   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_V2_EXTN
value|0x7f
end_define

begin_comment
comment|/* MC_CMD_V2_EXTN_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_V2_EXTN_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_V2_EXTN_IN_EXTENDED_CMD_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_V2_EXTN_IN_EXTENDED_CMD_WIDTH
value|15
end_define

begin_define
define|#
directive|define
name|MC_CMD_V2_EXTN_IN_UNUSED_LBN
value|15
end_define

begin_define
define|#
directive|define
name|MC_CMD_V2_EXTN_IN_UNUSED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_V2_EXTN_IN_ACTUAL_LEN_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_V2_EXTN_IN_ACTUAL_LEN_WIDTH
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_V2_EXTN_IN_UNUSED2_LBN
value|26
end_define

begin_define
define|#
directive|define
name|MC_CMD_V2_EXTN_IN_UNUSED2_WIDTH
value|6
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_TCM_BUCKET_ALLOC   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_ALLOC
value|0x80
end_define

begin_comment
comment|/* MC_CMD_TCM_BUCKET_ALLOC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_ALLOC_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_TCM_BUCKET_ALLOC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_ALLOC_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_ALLOC_OUT_BUCKET_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_TCM_BUCKET_FREE   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_FREE
value|0x81
end_define

begin_comment
comment|/* MC_CMD_TCM_BUCKET_FREE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_FREE_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_FREE_IN_BUCKET_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_TCM_BUCKET_FREE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_FREE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_TCM_BUCKET_INIT   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT
value|0x82
end_define

begin_comment
comment|/* MC_CMD_TCM_BUCKET_INIT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT_IN_BUCKET_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT_IN_RATE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_TCM_BUCKET_INIT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_TCM_TXQ_INIT   */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT
value|0x83
end_define

begin_comment
comment|/* MC_CMD_TCM_TXQ_INIT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_LEN
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_QID_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_LABEL_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_PQ_FLAGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_RP_BKT_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_MAX_BKT1_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_MAX_BKT2_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_MIN_BKT_OFST
value|24
end_define

begin_comment
comment|/* MC_CMD_TCM_TXQ_INIT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_OUT_LEN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SIENA_MC_DRIVER_PCOL_H */
end_comment

end_unit

