begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2008-2013 Solarflare Communications Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
comment|/* If this is set in MC_RESET_STATE_REG then it should be  * possible to jump into IMEM without loading code from flash.  * Unlike a warm boot, assume DMEM has been reloaded, so that  * the MC persistent data must be reinitialised. */
end_comment

begin_define
define|#
directive|define
name|MC_FW_TEPID_BOOT_OK
value|(16)
end_define

begin_comment
comment|/* We have entered the main firmware via recovery mode.  This  * means that MC persistent data must be reinitialised, but that  * we shouldn't touch PCIe config. */
end_comment

begin_define
define|#
directive|define
name|MC_FW_RECOVERY_MODE_PCIE_INIT_OK
value|(32)
end_define

begin_comment
comment|/* BIST state has been initialized */
end_comment

begin_define
define|#
directive|define
name|MC_FW_BIST_INIT_OK
value|(128)
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
comment|/* Check whether an mcfw version (in host order) belongs to a bootloader */
end_comment

begin_define
define|#
directive|define
name|MC_FW_VERSION_IS_BOOTLOADER
parameter_list|(
name|_v
parameter_list|)
value|(((_v)>> 16) == 0xb007)
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
comment|/* MCDI version 1  *  * Each MCDI request starts with an MCDI_HEADER, which is a 32bit  * structure, filled in by the client.  *  *       0       7  8     16    20     22  23  24    31  *      | CODE | R | LEN | SEQ | Rsvd | E | R | XFLAGS |  *               |                      |   |  *               |                      |   \--- Response  *               |                      \------- Error  *               \------------------------------ Resync (always set)  *  * The client writes it's request into MC shared memory, and rings the  * doorbell. Each request is completed by either by the MC writting  * back into shared memory, or by writting out an event.  *  * All MCDI commands support completion by shared memory response. Each  * request may also contain additional data (accounted for by HEADER.LEN),  * and some response's may also contain additional data (again, accounted  * for by HEADER.LEN).  *  * Some MCDI commands support completion by event, in which any associated  * response data is included in the event.  *  * The protocol requires one response to be delivered for every request, a  * request should not be sent unless the response for the previous request  * has been received (either by polling shared memory, or by receiving  * an event).  */
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
name|MCDI_HEADER_SEQ_WIDTH
value|4
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
value|1
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_NOT_EPOCH_LBN
value|21
end_define

begin_define
define|#
directive|define
name|MCDI_HEADER_NOT_EPOCH_WIDTH
value|1
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

begin_define
define|#
directive|define
name|MCDI_CTL_SDU_LEN_MAX_V1
value|0xfc
end_define

begin_define
define|#
directive|define
name|MCDI_CTL_SDU_LEN_MAX_V2
value|0x400
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|WITH_MCDI_V2
end_ifdef

begin_define
define|#
directive|define
name|MCDI_CTL_SDU_LEN_MAX
value|MCDI_CTL_SDU_LEN_MAX_V2
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MCDI_CTL_SDU_LEN_MAX
value|MCDI_CTL_SDU_LEN_MAX_V1
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
comment|/* Operation not permitted. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EPERM
value|1
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
comment|/* I/O failure */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EIO
value|5
end_define

begin_comment
comment|/* Already exists */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EEXIST
value|6
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
comment|/* Out of memory */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ENOMEM
value|12
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
comment|/* No such device */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ENODEV
value|19
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
comment|/* Broken pipe */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EPIPE
value|32
end_define

begin_comment
comment|/* Read-only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EROFS
value|30
end_define

begin_comment
comment|/* Out of range */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ERANGE
value|34
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

begin_comment
comment|/* Link has been severed */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ENOLINK
value|67
end_define

begin_comment
comment|/* Protocol error */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EPROTO
value|71
end_define

begin_comment
comment|/* Operation not supported */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ENOTSUP
value|95
end_define

begin_comment
comment|/* Address not available */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EADDRNOTAVAIL
value|99
end_define

begin_comment
comment|/* Not connected */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ENOTCONN
value|107
end_define

begin_comment
comment|/* Operation already in progress */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_EALREADY
value|114
end_define

begin_comment
comment|/* Resource allocation failed. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_ALLOC_FAIL
value|0x1000
end_define

begin_comment
comment|/* V-adaptor not found. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_NO_VADAPTOR
value|0x1001
end_define

begin_comment
comment|/* EVB port not found. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_NO_EVB_PORT
value|0x1002
end_define

begin_comment
comment|/* V-switch not found. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_NO_VSWITCH
value|0x1003
end_define

begin_comment
comment|/* Too many VLAN tags. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_VLAN_LIMIT
value|0x1004
end_define

begin_comment
comment|/* Bad PCI function number. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_BAD_PCI_FUNC
value|0x1005
end_define

begin_comment
comment|/* Invalid VLAN mode. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_BAD_VLAN_MODE
value|0x1006
end_define

begin_comment
comment|/* Invalid v-switch type. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_BAD_VSWITCH_TYPE
value|0x1007
end_define

begin_comment
comment|/* Invalid v-port type. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_BAD_VPORT_TYPE
value|0x1008
end_define

begin_comment
comment|/* MAC address exists. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_MAC_EXIST
value|0x1009
end_define

begin_comment
comment|/* Slave core not present */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_SLAVE_NOT_PRESENT
value|0x100a
end_define

begin_comment
comment|/* The datapath is disabled. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_DATAPATH_DISABLED
value|0x100b
end_define

begin_comment
comment|/* The requesting client is not a function */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_CLIENT_NOT_FN
value|0x100c
end_define

begin_comment
comment|/* The requested operation might require the    command to be passed between MCs, and the    transport doesn't support that.  Should    only ever been seen over the UART. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_TRANSPORT_NOPROXY
value|0x100d
end_define

begin_comment
comment|/* VLAN tag(s) exists */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_VLAN_EXIST
value|0x100e
end_define

begin_comment
comment|/* No MAC address assigned to an EVB port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_NO_MAC_ADDR
value|0x100f
end_define

begin_comment
comment|/* Notifies the driver that the request has been relayed  * to an admin function for authorization. The driver should  * wait for a PROXY_RESPONSE event and then resend its request.  * This error code is followed by a 32-bit handle that  * helps matching it with the respective PROXY_RESPONSE event. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_PROXY_PENDING
value|0x1010
end_define

begin_define
define|#
directive|define
name|MC_CMD_ERR_PROXY_PENDING_HANDLE_OFST
value|4
end_define

begin_comment
comment|/* The request cannot be passed for authorization because  * another request from the same function is currently being  * authorized. The drvier should try again later. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_PROXY_INPROGRESS
value|0x1011
end_define

begin_comment
comment|/* Returned by MC_CMD_PROXY_COMPLETE if the caller is not the function  * that has enabled proxying or BLOCK_INDEX points to a function that  * doesn't await an authorization. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_PROXY_UNEXPECTED
value|0x1012
end_define

begin_comment
comment|/* This code is currently only used internally in FW. Its meaning is that  * an operation failed due to lack of SR-IOV privilege.  * Normally it is translated to EPERM by send_cmd_err(),  * but it may also be used to trigger some special mechanism  * for handling such case, e.g. to relay the failed request  * to a designated admin function for authorization. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_NO_PRIVILEGE
value|0x1013
end_define

begin_comment
comment|/* Workaround 26807 could not be turned on/off because some functions  * have already installed filters. See the comment at  * MC_CMD_WORKAROUND_BUG26807. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ERR_FILTERS_PRESENT
value|0x1014
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
name|SIENA_MC_BOOTROM_COPYCODE_VEC
value|(0x800 - 3 * 0x4)
end_define

begin_define
define|#
directive|define
name|HUNT_MC_BOOTROM_COPYCODE_VEC
value|(0x8000 - 3 * 0x4)
end_define

begin_comment
comment|/* Points to the recovery mode entry point. */
end_comment

begin_define
define|#
directive|define
name|SIENA_MC_BOOTROM_NOFLASH_VEC
value|(0x800 - 2 * 0x4)
end_define

begin_define
define|#
directive|define
name|HUNT_MC_BOOTROM_NOFLASH_VEC
value|(0x8000 - 2 * 0x4)
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
define|\
value|(MC_CMD_DBI_WRITE_IN_DBIWROP_OFST +		\ 	 MC_CMD_DBIWROP_TYPEDEF_ADDRESS_OFST +		\ 	 (n) * MC_CMD_DBIWROP_TYPEDEF_LEN)
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_BYTE_MASK_OFST
parameter_list|(
name|n
parameter_list|)
define|\
value|(MC_CMD_DBI_WRITE_IN_DBIWROP_OFST +		\ 	 MC_CMD_DBIWROP_TYPEDEF_BYTE_MASK_OFST +	\ 	 (n) * MC_CMD_DBIWROP_TYPEDEF_LEN)
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE_IN_VALUE_OFST
parameter_list|(
name|n
parameter_list|)
define|\
value|(MC_CMD_DBI_WRITE_IN_DBIWROP_OFST +		\ 	 MC_CMD_DBIWROP_TYPEDEF_VALUE_OFST +		\ 	 (n) * MC_CMD_DBIWROP_TYPEDEF_LEN)
end_define

begin_comment
comment|/* This may be ORed with an EVB_PORT_ID_xxx constant to pass a non-default  * stack ID (which must be in the range 1-255) along with an EVB port ID.  */
end_comment

begin_define
define|#
directive|define
name|EVB_STACK_ID
parameter_list|(
name|n
parameter_list|)
value|(((n)& 0xff)<< 16)
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

begin_comment
comment|/* enum: Info. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LEVEL_INFO
value|0x0
end_define

begin_comment
comment|/* enum: Warning. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LEVEL_WARN
value|0x1
end_define

begin_comment
comment|/* enum: Error. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LEVEL_ERR
value|0x2
end_define

begin_comment
comment|/* enum: Fatal. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LEVEL_FATAL
value|0x3
end_define

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

begin_comment
comment|/* enum: 100Mbs */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_SPEED_100M
value|0x1
end_define

begin_comment
comment|/* enum: 1Gbs */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_SPEED_1G
value|0x2
end_define

begin_comment
comment|/* enum: 10Gbs */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_SPEED_10G
value|0x3
end_define

begin_comment
comment|/* enum: 40Gbs */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_LINKCHANGE_SPEED_40G
value|0x4
end_define

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

begin_comment
comment|/* enum: SRAM Access. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_FWALERT_REASON_SRAM_ACCESS
value|0x1
end_define

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

begin_comment
comment|/* enum: Descriptor loader reported failure */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_DL_FAIL
value|0x1
end_define

begin_comment
comment|/* enum: Descriptor ring empty and no EOP seen for packet */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_NO_EOP
value|0x2
end_define

begin_comment
comment|/* enum: Overlength packet */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_2BIG
value|0x3
end_define

begin_comment
comment|/* enum: Malformed option descriptor */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_BAD_OPTDESC
value|0x5
end_define

begin_comment
comment|/* enum: Option descriptor part way through a packet */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_OPT_IN_PKT
value|0x8
end_define

begin_comment
comment|/* enum: DMA or PIO data access error */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_ERR_BAD_DMA_OR_PIO
value|0x9
end_define

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
name|MCDI_EVENT_TX_FLUSH_TO_DRIVER_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_TX_FLUSH_TO_DRIVER_WIDTH
value|1
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

begin_comment
comment|/* enum: PLL lost lock */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_ERR_PLL_LOST
value|0x1
end_define

begin_comment
comment|/* enum: Filter overflow (PDMA) */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_ERR_FILTER
value|0x2
end_define

begin_comment
comment|/* enum: FIFO overflow (FPGA) */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_ERR_FIFO
value|0x3
end_define

begin_comment
comment|/* enum: Merge queue overflow */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_ERR_QUEUE
value|0x4
end_define

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

begin_comment
comment|/* enum: AOE failed to load - no valid image? */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_NO_LOAD
value|0x1
end_define

begin_comment
comment|/* enum: AOE FC reported an exception */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_FC_ASSERT
value|0x2
end_define

begin_comment
comment|/* enum: AOE FC watchdogged */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_FC_WATCHDOG
value|0x3
end_define

begin_comment
comment|/* enum: AOE FC failed to start */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_FC_NO_START
value|0x4
end_define

begin_comment
comment|/* enum: Generic AOE fault - likely to have been reported via other means too  * but intended for use by aoex driver.  */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_FAULT
value|0x5
end_define

begin_comment
comment|/* enum: Results of reprogramming the CPLD (status in AOE_ERR_DATA) */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_CPLD_REPROGRAMMED
value|0x6
end_define

begin_comment
comment|/* enum: AOE loaded successfully */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_LOAD
value|0x7
end_define

begin_comment
comment|/* enum: AOE DMA operation completed (LSB of HOST_HANDLE in AOE_ERR_DATA) */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_DMA
value|0x8
end_define

begin_comment
comment|/* enum: AOE byteblaster connected/disconnected (Connection status in  * AOE_ERR_DATA)  */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_BYTEBLASTER
value|0x9
end_define

begin_comment
comment|/* enum: DDR ECC status update */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_DDR_ECC_STATUS
value|0xa
end_define

begin_comment
comment|/* enum: PTP status update */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_AOE_PTP_STATUS
value|0xb
end_define

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
name|MCDI_EVENT_RX_ERR_RXQ_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_ERR_RXQ_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_ERR_TYPE_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_ERR_TYPE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_ERR_INFO_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_ERR_INFO_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_FLUSH_TO_DRIVER_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_FLUSH_TO_DRIVER_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_FLUSH_RXQ_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_FLUSH_RXQ_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_MC_REBOOT_COUNT_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_MC_REBOOT_COUNT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_MUM_ERR_TYPE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_MUM_ERR_TYPE_WIDTH
value|8
end_define

begin_comment
comment|/* enum: MUM failed to load - no valid image? */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_MUM_NO_LOAD
value|0x1
end_define

begin_comment
comment|/* enum: MUM f/w reported an exception */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_MUM_ASSERT
value|0x2
end_define

begin_comment
comment|/* enum: MUM not kicking watchdog */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_MUM_WATCHDOG
value|0x3
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_MUM_ERR_DATA_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_MUM_ERR_DATA_WIDTH
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

begin_comment
comment|/* enum: Event generated by host software */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_SW_EVENT
value|0x0
end_define

begin_comment
comment|/* enum: Bad assert. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_BADSSERT
value|0x1
end_define

begin_comment
comment|/* enum: PM Notice. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PMNOTICE
value|0x2
end_define

begin_comment
comment|/* enum: Command done. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_CMDDONE
value|0x3
end_define

begin_comment
comment|/* enum: Link change. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_LINKCHANGE
value|0x4
end_define

begin_comment
comment|/* enum: Sensor Event. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_SENSOREVT
value|0x5
end_define

begin_comment
comment|/* enum: Schedule error. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_SCHEDERR
value|0x6
end_define

begin_comment
comment|/* enum: Reboot. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_REBOOT
value|0x7
end_define

begin_comment
comment|/* enum: Mac stats DMA. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_MAC_STATS_DMA
value|0x8
end_define

begin_comment
comment|/* enum: Firmware alert. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_FWALERT
value|0x9
end_define

begin_comment
comment|/* enum: Function level reset. */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_FLR
value|0xa
end_define

begin_comment
comment|/* enum: Transmit error */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_TX_ERR
value|0xb
end_define

begin_comment
comment|/* enum: Tx flush has completed */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_TX_FLUSH
value|0xc
end_define

begin_comment
comment|/* enum: PTP packet received timestamp */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PTP_RX
value|0xd
end_define

begin_comment
comment|/* enum: PTP NIC failure */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PTP_FAULT
value|0xe
end_define

begin_comment
comment|/* enum: PTP PPS event */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PTP_PPS
value|0xf
end_define

begin_comment
comment|/* enum: Rx flush has completed */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_RX_FLUSH
value|0x10
end_define

begin_comment
comment|/* enum: Receive error */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_RX_ERR
value|0x11
end_define

begin_comment
comment|/* enum: AOE fault */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_AOE
value|0x12
end_define

begin_comment
comment|/* enum: Network port calibration failed (VCAL). */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_VCAL_FAIL
value|0x13
end_define

begin_comment
comment|/* enum: HW PPS event */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_HW_PPS
value|0x14
end_define

begin_comment
comment|/* enum: The MC has rebooted (huntington and later, siena uses CODE_REBOOT and  * a different format)  */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_MC_REBOOT
value|0x15
end_define

begin_comment
comment|/* enum: the MC has detected a parity error */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PAR_ERR
value|0x16
end_define

begin_comment
comment|/* enum: the MC has detected a correctable error */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_ECC_CORR_ERR
value|0x17
end_define

begin_comment
comment|/* enum: the MC has detected an uncorrectable error */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_ECC_FATAL_ERR
value|0x18
end_define

begin_comment
comment|/* enum: The MC has entered offline BIST mode */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_MC_BIST
value|0x19
end_define

begin_comment
comment|/* enum: PTP tick event providing current NIC time */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PTP_TIME
value|0x1a
end_define

begin_comment
comment|/* enum: MUM fault */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_MUM
value|0x1b
end_define

begin_comment
comment|/* enum: notify the designated PF of a new authorization request */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PROXY_REQUEST
value|0x1c
end_define

begin_comment
comment|/* enum: notify a function that awaits an authorization that its request has  * been processed and it may now resend the command  */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_PROXY_RESPONSE
value|0x1d
end_define

begin_comment
comment|/* enum: Artificial event generated by host and posted via MC for test  * purposes.  */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_CODE_TESTGEN
value|0xfa
end_define

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

begin_comment
comment|/* For CODE_PTP_RX, CODE_PTP_PPS and CODE_HW_PPS events the seconds field of  * timestamp  */
end_comment

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

begin_comment
comment|/* For CODE_PTP_RX, CODE_PTP_PPS and CODE_HW_PPS events the major field of  * timestamp  */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_MAJOR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_MAJOR_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_MAJOR_WIDTH
value|32
end_define

begin_comment
comment|/* For CODE_PTP_RX, CODE_PTP_PPS and CODE_HW_PPS events the nanoseconds field  * of timestamp  */
end_comment

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

begin_comment
comment|/* For CODE_PTP_RX, CODE_PTP_PPS and CODE_HW_PPS events the minor field of  * timestamp  */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_MINOR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_MINOR_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_MINOR_WIDTH
value|32
end_define

begin_comment
comment|/* For CODE_PTP_RX events, the lowest four bytes of sourceUUID from PTP packet  */
end_comment

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

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_ERR_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_ERR_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_RX_ERR_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PAR_ERR_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PAR_ERR_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PAR_ERR_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_ECC_CORR_ERR_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_ECC_CORR_ERR_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_ECC_CORR_ERR_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_ECC_FATAL_ERR_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_ECC_FATAL_ERR_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_ECC_FATAL_ERR_DATA_WIDTH
value|32
end_define

begin_comment
comment|/* For CODE_PTP_TIME events, the major value of the PTP clock */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_TIME_MAJOR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_TIME_MAJOR_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_TIME_MAJOR_WIDTH
value|32
end_define

begin_comment
comment|/* For CODE_PTP_TIME events, bits 19-26 of the minor value of the PTP clock */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_TIME_MINOR_26_19_LBN
value|36
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_TIME_MINOR_26_19_WIDTH
value|8
end_define

begin_comment
comment|/* For CODE_PTP_TIME events where report sync status is enabled, indicates  * whether the NIC clock has ever been set  */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_TIME_NIC_CLOCK_VALID_LBN
value|36
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_TIME_NIC_CLOCK_VALID_WIDTH
value|1
end_define

begin_comment
comment|/* For CODE_PTP_TIME events where report sync status is enabled, indicates  * whether the NIC and System clocks are in sync  */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_TIME_HOST_NIC_IN_SYNC_LBN
value|37
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_TIME_HOST_NIC_IN_SYNC_WIDTH
value|1
end_define

begin_comment
comment|/* For CODE_PTP_TIME events where report sync status is enabled, bits 21-26 of  * the minor value of the PTP clock  */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_TIME_MINOR_26_21_LBN
value|38
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PTP_TIME_MINOR_26_21_WIDTH
value|6
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PROXY_REQUEST_BUFF_INDEX_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PROXY_REQUEST_BUFF_INDEX_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PROXY_REQUEST_BUFF_INDEX_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PROXY_RESPONSE_HANDLE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PROXY_RESPONSE_HANDLE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PROXY_RESPONSE_HANDLE_WIDTH
value|32
end_define

begin_comment
comment|/* Zero means that the request has been completed or authorized, and the driver  * should resend it. A non-zero value means that the authorization has been  * denied, and gives the reason. Typically it will be EPERM.  */
end_comment

begin_define
define|#
directive|define
name|MCDI_EVENT_PROXY_RESPONSE_RC_LBN
value|36
end_define

begin_define
define|#
directive|define
name|MCDI_EVENT_PROXY_RESPONSE_RC_WIDTH
value|8
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

begin_comment
comment|/* enum: Info. */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_LEVEL_INFO
value|0x0
end_define

begin_comment
comment|/* enum: Warning. */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_LEVEL_WARN
value|0x1
end_define

begin_comment
comment|/* enum: Error. */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_LEVEL_ERR
value|0x2
end_define

begin_comment
comment|/* enum: Fatal. */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_LEVEL_FATAL
value|0x3
end_define

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

begin_comment
comment|/* enum: The FC was rebooted. */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_REBOOT
value|0x1
end_define

begin_comment
comment|/* enum: Bad assert. */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_ASSERT
value|0x2
end_define

begin_comment
comment|/* enum: DDR3 test result. */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_DDR_TEST_RESULT
value|0x3
end_define

begin_comment
comment|/* enum: Link status. */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_LINK_STATE
value|0x4
end_define

begin_comment
comment|/* enum: A timed read is ready to be serviced. */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_TIMED_READ
value|0x5
end_define

begin_comment
comment|/* enum: One or more PPS IN events */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_PPS_IN
value|0x6
end_define

begin_comment
comment|/* enum: Tick event from PTP clock */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_PTP_TICK
value|0x7
end_define

begin_comment
comment|/* enum: ECC error counters */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_DDR_ECC_STATUS
value|0x8
end_define

begin_comment
comment|/* enum: Current status of PTP */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_PTP_STATUS
value|0x9
end_define

begin_comment
comment|/* enum: Port id config to map MC-FC port idx */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_CODE_PORT_CONFIG
value|0xa
end_define

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
comment|/* Index of MC port being referred to */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_PORT_CONFIG_SRC_LBN
value|36
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_PORT_CONFIG_SRC_WIDTH
value|8
end_define

begin_comment
comment|/* FC Port index that matches the MC port index in SRC */
end_comment

begin_define
define|#
directive|define
name|FCDI_EVENT_PORT_CONFIG_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_PORT_CONFIG_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|FCDI_EVENT_PORT_CONFIG_DATA_WIDTH
value|32
end_define

begin_comment
comment|/* FCDI_EXTENDED_EVENT_PPS structuredef: Extended FCDI event to send PPS events  * to the MC. Note that this structure | is overlayed over a normal FCDI event  * such that bits 32-63 containing | event code, level, source etc remain the  * same. In this case the data | field of the header is defined to be the  * number of timestamps  */
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

begin_comment
comment|/* Number of timestamps following */
end_comment

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

begin_comment
comment|/* Seconds field of a timestamp record */
end_comment

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

begin_comment
comment|/* Nanoseconds field of a timestamp record */
end_comment

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

begin_comment
comment|/* Timestamp records comprising the event */
end_comment

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
comment|/* MUM_EVENT structuredef */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_CONT_LBN
value|32
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_CONT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_LEVEL_LBN
value|33
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_LEVEL_WIDTH
value|3
end_define

begin_comment
comment|/* enum: Info. */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_LEVEL_INFO
value|0x0
end_define

begin_comment
comment|/* enum: Warning. */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_LEVEL_WARN
value|0x1
end_define

begin_comment
comment|/* enum: Error. */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_LEVEL_ERR
value|0x2
end_define

begin_comment
comment|/* enum: Fatal. */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_LEVEL_FATAL
value|0x3
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_SENSOR_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_SENSOR_ID_WIDTH
value|8
end_define

begin_comment
comment|/*             Enum values, see field(s): */
end_comment

begin_comment
comment|/*                MC_CMD_SENSOR_INFO/MC_CMD_SENSOR_INFO_OUT/MASK */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_SENSOR_STATE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_SENSOR_STATE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_READY_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_READY_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_LINK_UP_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_LINK_UP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_TX_LOL_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_TX_LOL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_RX_LOL_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_RX_LOL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_TX_LOS_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_TX_LOS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_RX_LOS_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_RX_LOS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_TX_FAULT_LBN
value|6
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_TX_FAULT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_SRC_LBN
value|36
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_SRC_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_EV_CODE_LBN
value|60
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_EV_CODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_CODE_LBN
value|44
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_CODE_WIDTH
value|8
end_define

begin_comment
comment|/* enum: The MUM was rebooted. */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_CODE_REBOOT
value|0x1
end_define

begin_comment
comment|/* enum: Bad assert. */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_CODE_ASSERT
value|0x2
end_define

begin_comment
comment|/* enum: Sensor failure. */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_CODE_SENSOR
value|0x3
end_define

begin_comment
comment|/* enum: Link fault has been asserted, or has cleared. */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_CODE_QSFP_LASI_INTERRUPT
value|0x4
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_SENSOR_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_SENSOR_DATA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_SENSOR_DATA_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_FLAGS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_FLAGS_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_COPPER_LEN_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_COPPER_LEN_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_COPPER_LEN_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_CAPS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_CAPS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_CAPS_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_TECH_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_STATE_QSFP_MODULE_TECH_UNKNOWN
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_STATE_QSFP_MODULE_TECH_OPTICAL
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_STATE_QSFP_MODULE_TECH_COPPER_PASSIVE
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_STATE_QSFP_MODULE_TECH_COPPER_PASSIVE_EQUALIZED
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_STATE_QSFP_MODULE_TECH_COPPER_ACTIVE_LIMITING
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_STATE_QSFP_MODULE_TECH_COPPER_ACTIVE_LINEAR
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_STATE_QSFP_MODULE_TECH_BASE_T
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_STATE_QSFP_MODULE_TECH_LOOPBACK_PASSIVE
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_TECH_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_TECH_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_SRC_DATA_ID_LBN
value|36
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_SRC_DATA_ID_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_SRC_DATA_ID_FLAGS
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_SRC_DATA_ID_COPPER_LEN
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_SRC_DATA_ID_CAPS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_SRC_DATA_ID_TECH
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_SRC_DATA_ID_MAX
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_SRC_PORT_NO_LBN
value|40
end_define

begin_define
define|#
directive|define
name|MUM_EVENT_PORT_PHY_SRC_PORT_NO_WIDTH
value|4
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

begin_undef
undef|#
directive|undef
name|MC_CMD_0x1_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x1_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_undef
undef|#
directive|undef
name|MC_CMD_0x2_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x2_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_undef
undef|#
directive|undef
name|MC_CMD_0x3_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x3_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Source address  *  * The main image should be entered via a copy of a single word from and to a  * magic address, which controls various aspects of the boot. The magic address  * is a bitfield, with each bit as documented below.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_SRC_ADDR_OFST
value|0
end_define

begin_comment
comment|/* enum: Deprecated; equivalent to setting BOOT_MAGIC_PRESENT (see below) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_HUNT_NO_MAGIC_ADDR
value|0x10000
end_define

begin_comment
comment|/* enum: Deprecated; equivalent to setting BOOT_MAGIC_PRESENT and  * BOOT_MAGIC_SATELLITE_CPUS_NOT_LOADED (see below)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_HUNT_NO_DATAPATH_MAGIC_ADDR
value|0x1d0d0
end_define

begin_comment
comment|/* enum: Deprecated; equivalent to setting BOOT_MAGIC_PRESENT,  * BOOT_MAGIC_SATELLITE_CPUS_NOT_LOADED and BOOT_MAGIC_IGNORE_CONFIG (see  * below)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_HUNT_IGNORE_CONFIG_MAGIC_ADDR
value|0x1badc
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_BOOT_MAGIC_PRESENT_LBN
value|17
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_BOOT_MAGIC_PRESENT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_BOOT_MAGIC_SATELLITE_CPUS_NOT_LOADED_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_BOOT_MAGIC_SATELLITE_CPUS_NOT_LOADED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_BOOT_MAGIC_IGNORE_CONFIG_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_BOOT_MAGIC_IGNORE_CONFIG_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_BOOT_MAGIC_SKIP_BOOT_ICORE_SYNC_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_BOOT_MAGIC_SKIP_BOOT_ICORE_SYNC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_BOOT_MAGIC_FORCE_STANDALONE_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_BOOT_MAGIC_FORCE_STANDALONE_WIDTH
value|1
end_define

begin_comment
comment|/* Destination address */
end_comment

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

begin_comment
comment|/* Address of where to jump after copy. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_IN_JUMP_OFST
value|12
end_define

begin_comment
comment|/* enum: Control should return to the caller rather than jumping */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_COPYCODE_JUMP_NONE
value|0x1
end_define

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
comment|/* MC_CMD_SET_FUNC  * Select function for function-specific commands.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_FUNC
value|0x4
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x4_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x4_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Set function */
end_comment

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
comment|/* MC_CMD_GET_BOOT_STATUS  * Get the instruction address from which the MC booted.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS
value|0x5
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x5_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x5_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* ?? */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_OUT_BOOT_OFFSET_OFST
value|0
end_define

begin_comment
comment|/* enum: indicates that the MC wasn't flash booted */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOOT_STATUS_OUT_BOOT_OFFSET_NULL
value|0xdeadbeef
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
comment|/* MC_CMD_GET_ASSERTS  * Get (and optionally clear) the current assertion status. Only  * OUT.GLOBAL_FLAGS is guaranteed to exist in the completion payload. The other  * fields will only be present if OUT.GLOBAL_FLAGS != NO_FAILS  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS
value|0x6
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x6_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x6_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Set to clear assertion */
end_comment

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

begin_comment
comment|/* Assertion status flag. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_OUT_GLOBAL_FLAGS_OFST
value|0
end_define

begin_comment
comment|/* enum: No assertions have failed. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_FLAGS_NO_FAILS
value|0x1
end_define

begin_comment
comment|/* enum: A system-level assertion has failed. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_FLAGS_SYS_FAIL
value|0x2
end_define

begin_comment
comment|/* enum: A thread-level assertion has failed. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_FLAGS_THR_FAIL
value|0x3
end_define

begin_comment
comment|/* enum: The system was reset by the watchdog. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_FLAGS_WDOG_FIRED
value|0x4
end_define

begin_comment
comment|/* enum: An illegal address trap stopped the system (huntington and later) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_FLAGS_ADDR_TRAP
value|0x5
end_define

begin_comment
comment|/* Failing PC value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_OUT_SAVED_PC_OFFS_OFST
value|4
end_define

begin_comment
comment|/* Saved GP regs */
end_comment

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

begin_comment
comment|/* enum: A magic value hinting that the value in this register at the time of  * the failure has likely been lost.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_ASSERTS_REG_NO_DATA
value|0xda7a1057
end_define

begin_comment
comment|/* Failing thread address */
end_comment

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
comment|/* MC_CMD_LOG_CTRL  * Configure the output stream for log events such as link state changes,  * sensor notifications and MCDI completions  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOG_CTRL
value|0x7
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x7_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x7_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* Log destination */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOG_CTRL_IN_LOG_DEST_OFST
value|0
end_define

begin_comment
comment|/* enum: UART. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOG_CTRL_IN_LOG_DEST_UART
value|0x1
end_define

begin_comment
comment|/* enum: Event queue. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOG_CTRL_IN_LOG_DEST_EVQ
value|0x2
end_define

begin_comment
comment|/* Legacy argument. Must be zero. */
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
comment|/* MC_CMD_GET_VERSION  * Get version information about the MC firmware.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION
value|0x8
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x8_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x8_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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
comment|/* MC_CMD_GET_VERSION_EXT_IN msgrequest: Asks for the extended version */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_EXT_IN_LEN
value|4
end_define

begin_comment
comment|/* placeholder, set to 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_EXT_IN_EXT_FLAGS_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_VERSION_V0_OUT msgresponse: deprecated version format */
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

begin_comment
comment|/* enum: Reserved version number to indicate "any" version. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_FIRMWARE_ANY
value|0xffffffff
end_define

begin_comment
comment|/* enum: Bootrom version value for Siena. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_FIRMWARE_SIENA_BOOTROM
value|0xb0070000
end_define

begin_comment
comment|/* enum: Bootrom version value for Huntington. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_OUT_FIRMWARE_HUNT_BOOTROM
value|0xb0070001
end_define

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

begin_comment
comment|/* 128bit mask of functions supported by the current firmware */
end_comment

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
comment|/* MC_CMD_GET_VERSION_EXT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_EXT_OUT_LEN
value|48
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
name|MC_CMD_GET_VERSION_EXT_OUT_PCOL_OFST
value|4
end_define

begin_comment
comment|/* 128bit mask of functions supported by the current firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_EXT_OUT_SUPPORTED_FUNCS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_EXT_OUT_SUPPORTED_FUNCS_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_EXT_OUT_VERSION_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_EXT_OUT_VERSION_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_EXT_OUT_VERSION_LO_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_EXT_OUT_VERSION_HI_OFST
value|28
end_define

begin_comment
comment|/* extra info */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_EXT_OUT_EXTRA_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VERSION_EXT_OUT_EXTRA_LEN
value|16
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FC  * Perform an FC operation  */
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

begin_comment
comment|/* enum: NULL MCDI command to FC. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_NULL
value|0x1
end_define

begin_comment
comment|/* enum: Unused opcode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UNUSED
value|0x2
end_define

begin_comment
comment|/* enum: MAC driver commands */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC
value|0x3
end_define

begin_comment
comment|/* enum: Read FC memory */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_READ32
value|0x4
end_define

begin_comment
comment|/* enum: Write to FC memory */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_WRITE32
value|0x5
end_define

begin_comment
comment|/* enum: Read FC memory */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TRC_READ
value|0x6
end_define

begin_comment
comment|/* enum: Write to FC memory */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TRC_WRITE
value|0x7
end_define

begin_comment
comment|/* enum: FC firmware Version */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_GET_VERSION
value|0x8
end_define

begin_comment
comment|/* enum: Read FC memory */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TRC_RX_READ
value|0x9
end_define

begin_comment
comment|/* enum: Write to FC memory */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TRC_RX_WRITE
value|0xa
end_define

begin_comment
comment|/* enum: SFP parameters */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_SFP
value|0xb
end_define

begin_comment
comment|/* enum: DDR3 test */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST
value|0xc
end_define

begin_comment
comment|/* enum: Get Crash context from FC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_GET_ASSERT
value|0xd
end_define

begin_comment
comment|/* enum: Get FPGA Build registers */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_FPGA_BUILD
value|0xe
end_define

begin_comment
comment|/* enum: Read map support commands */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_READ_MAP
value|0xf
end_define

begin_comment
comment|/* enum: FC Capabilities */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_CAPABILITIES
value|0x10
end_define

begin_comment
comment|/* enum: FC Global flags */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_GLOBAL_FLAGS
value|0x11
end_define

begin_comment
comment|/* enum: FC IO using relative addressing modes */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_IO_REL
value|0x12
end_define

begin_comment
comment|/* enum: FPGA link information */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK
value|0x13
end_define

begin_comment
comment|/* enum: Configure loopbacks and link on FPGA ports */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_SET_LINK
value|0x14
end_define

begin_comment
comment|/* enum: Licensing operations relating to AOE */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_LICENSE
value|0x15
end_define

begin_comment
comment|/* enum: Startup information to the FC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_STARTUP
value|0x16
end_define

begin_comment
comment|/* enum: Configure a DMA read */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DMA
value|0x17
end_define

begin_comment
comment|/* enum: Configure a timed read */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TIMED_READ
value|0x18
end_define

begin_comment
comment|/* enum: Control UART logging */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_LOG
value|0x19
end_define

begin_comment
comment|/* enum: Get the value of a given clock_id */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_CLOCK
value|0x1a
end_define

begin_comment
comment|/* enum: DDR3/QDR3 parameters */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR
value|0x1b
end_define

begin_comment
comment|/* enum: PTP and timestamp control */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_TIMESTAMP
value|0x1c
end_define

begin_comment
comment|/* enum: Commands for SPI Flash interface */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_SPI
value|0x1d
end_define

begin_comment
comment|/* enum: Commands for diagnostic components */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DIAG
value|0x1e
end_define

begin_comment
comment|/* enum: External AOE port. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_PORT_EXT_OFST
value|0x0
end_define

begin_comment
comment|/* enum: Internal AOE port. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_PORT_INT_OFST
value|0x40
end_define

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
comment|/* MC_CMD_FC_IN_PHY msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_PHY_LEN
value|5
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* FC PHY driver operation code */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_PHY_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_PHY_OP_LEN
value|1
end_define

begin_comment
comment|/* enum: PHY init handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_INIT
value|0x1
end_define

begin_comment
comment|/* enum: PHY reconfigure handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_RECONFIGURE
value|0x2
end_define

begin_comment
comment|/* enum: PHY reboot handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_REBOOT
value|0x3
end_define

begin_comment
comment|/* enum: PHY get_supported_cap handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_GET_SUPPORTED_CAP
value|0x4
end_define

begin_comment
comment|/* enum: PHY get_config handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_GET_CONFIG
value|0x5
end_define

begin_comment
comment|/* enum: PHY get_media_info handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_GET_MEDIA_INFO
value|0x6
end_define

begin_comment
comment|/* enum: PHY set_led handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_SET_LED
value|0x7
end_define

begin_comment
comment|/* enum: PHY lasi_interrupt handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_LASI_INTERRUPT
value|0x8
end_define

begin_comment
comment|/* enum: PHY check_link handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_CHECK_LINK
value|0x9
end_define

begin_comment
comment|/* enum: PHY fill_stats handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_FILL_STATS
value|0xa
end_define

begin_comment
comment|/* enum: PHY bpx_link_state_changed handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_BPX_LINK_STATE_CHANGED
value|0xb
end_define

begin_comment
comment|/* enum: PHY get_state handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_GET_STATE
value|0xc
end_define

begin_comment
comment|/* enum: PHY start_bist handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_START_BIST
value|0xd
end_define

begin_comment
comment|/* enum: PHY poll_bist handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_POLL_BIST
value|0xe
end_define

begin_comment
comment|/* enum: PHY nvram_test handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_NVRAM_TEST
value|0xf
end_define

begin_comment
comment|/* enum: PHY relinquish handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_RELINQUISH_SPI
value|0x10
end_define

begin_comment
comment|/* enum: PHY read connection from FC - may be not required */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_GET_CONNECTION
value|0x11
end_define

begin_comment
comment|/* enum: PHY read flags from FC - may be not required */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_PHY_OP_GET_FLAGS
value|0x12
end_define

begin_comment
comment|/* MC_CMD_FC_IN_PHY_INIT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_PHY_INIT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_PHY_CMD_OFST
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

begin_comment
comment|/* enum: MAC reconfigure handler */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_RECONFIGURE
value|0x1
end_define

begin_comment
comment|/* enum: MAC Set command - same as MC_CMD_SET_MAC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_SET_LINK
value|0x2
end_define

begin_comment
comment|/* enum: MAC statistics */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_GET_STATS
value|0x3
end_define

begin_comment
comment|/* enum: MAC RX statistics */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_GET_RX_STATS
value|0x6
end_define

begin_comment
comment|/* enum: MAC TX statistics */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_GET_TX_STATS
value|0x7
end_define

begin_comment
comment|/* enum: MAC Read status */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_OP_READ_STATUS
value|0x8
end_define

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

begin_comment
comment|/* enum: External FPGA port. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_PORT_EXT
value|0x0
end_define

begin_comment
comment|/* enum: Internal Siena-facing FPGA ports. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_PORT_INT
value|0x1
end_define

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

begin_comment
comment|/* enum: Default FC command format; the fields PORT_TYPE and PORT_IDX are  * irrelevant. Port number is derived from pci_fn; passed in FC header.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_CMD_FORMAT_DEFAULT
value|0x0
end_define

begin_comment
comment|/* enum: Override default port number. Port number determined by fields  * PORT_TYPE and PORT_IDX.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_MAC_CMD_FORMAT_PORT_OVERRIDE
value|0x1
end_define

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

begin_comment
comment|/* MTU size */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_MAC_SET_LINK_MTU_OFST
value|8
end_define

begin_comment
comment|/* Drain Tx FIFO */
end_comment

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

begin_comment
comment|/* MC Statistics index */
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

begin_comment
comment|/* Number of statistics to read */
end_comment

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
value|28
end_define

begin_comment
comment|/*            MC_CMD_FC_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* Link speed is 100, 1000, 10000, 40000 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_SPEED_OFST
value|4
end_define

begin_comment
comment|/* Length of copper cable - zero when not relevant (e.g. if cable is fibre) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_COPPER_LEN_OFST
value|8
end_define

begin_comment
comment|/* Not relevant for cards with QSFP modules. For older cards, true if module is  * a dual speed SFP+ module.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_DUAL_SPEED_OFST
value|12
end_define

begin_comment
comment|/* True if an SFP Module is present (other fields valid when true) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_PRESENT_OFST
value|16
end_define

begin_comment
comment|/* The type of the SFP+ Module. For later cards with QSFP modules, this field  * is unused and the type is communicated by other means.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_TYPE_OFST
value|20
end_define

begin_comment
comment|/* Capabilities corresponding to 1 bits. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SFP_CAPS_OFST
value|24
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

begin_comment
comment|/* enum: DRAM Test Start */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_START
value|0x1
end_define

begin_comment
comment|/* enum: DRAM Test Poll */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_POLL
value|0x2
end_define

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

begin_comment
comment|/* FPGA build info operation code */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_FPGA_BUILD_OP_OFST
value|4
end_define

begin_comment
comment|/* enum: Get the build registers */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_FPGA_BUILD_BUILD
value|0x1
end_define

begin_comment
comment|/* enum: Get the services registers */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_FPGA_BUILD_SERVICES
value|0x2
end_define

begin_comment
comment|/* enum: Get the BSP version */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_FPGA_BUILD_BSP_VERSION
value|0x3
end_define

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

begin_comment
comment|/* enum: Get the number of map regions */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_READ_MAP_COUNT
value|0x1
end_define

begin_comment
comment|/* enum: Get the specified map */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_READ_MAP_INDEX
value|0x2
end_define

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

begin_comment
comment|/* enum: Get the base address that the FC applies to relative commands */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_GET_ADDR
value|0x1
end_define

begin_comment
comment|/* enum: Read data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_READ32
value|0x2
end_define

begin_comment
comment|/* enum: Write data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_IO_REL_WRITE32
value|0x3
end_define

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

begin_comment
comment|/* enum: Application address space */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_COMP_TYPE_APP_ADDR_SPACE
value|0x1
end_define

begin_comment
comment|/* enum: Flash address space */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_COMP_TYPE_FLASH
value|0x2
end_define

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

begin_comment
comment|/* enum: Get PHY configuration info */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_PHY
value|0x1
end_define

begin_comment
comment|/* enum: Get MAC configuration info */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_MAC
value|0x2
end_define

begin_comment
comment|/* enum: Get Rx eye table */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_RX_EYE
value|0x3
end_define

begin_comment
comment|/* enum: Get Rx eye plot */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_DUMP_RX_EYE_PLOT
value|0x4
end_define

begin_comment
comment|/* enum: Get Rx eye plot */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_READ_RX_EYE_PLOT
value|0x5
end_define

begin_comment
comment|/* enum: Retune Rx settings */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_RX_TUNE
value|0x6
end_define

begin_comment
comment|/* enum: Set loopback mode on fpga port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_LOOPBACK_SET
value|0x7
end_define

begin_comment
comment|/* enum: Get loopback mode config state on fpga port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_LOOPBACK_GET
value|0x8
end_define

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

begin_comment
comment|/* enum: Default FC command format; the fields PORT_TYPE and PORT_IDX are  * irrelevant. Port number is derived from pci_fn; passed in FC header.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_CMD_FORMAT_DEFAULT
value|0x0
end_define

begin_comment
comment|/* enum: Override default port number. Port number determined by fields  * PORT_TYPE and PORT_IDX.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_UHLINK_CMD_FORMAT_PORT_OVERRIDE
value|0x1
end_define

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

begin_comment
comment|/* See MC_CMD_GET_LOOPBACK_MODES/MC_CMD_GET_LOOPBACK_MODES_OUT/100M */
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

begin_comment
comment|/* Length of identifier */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_STARTUP_IDLENGTH_OFST
value|12
end_define

begin_comment
comment|/* Identifier for AOE FPGA */
end_comment

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

begin_comment
comment|/* FC supplied handle */
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

begin_comment
comment|/* Host supplied handle (unique) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_HOST_HANDLE_OFST
value|8
end_define

begin_comment
comment|/* Address into which to transfer data in host */
end_comment

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

begin_comment
comment|/* AOE address from which to transfer data */
end_comment

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

begin_comment
comment|/* Length of AOE transfer (total) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_AOE_LENGTH_OFST
value|28
end_define

begin_comment
comment|/* Length of host transfer (total) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_HOST_LENGTH_OFST
value|32
end_define

begin_comment
comment|/* Offset back from aoe_address to apply operation to */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMED_READ_SET_OFFSET_OFST
value|36
end_define

begin_comment
comment|/* Data to apply at offset */
end_comment

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

begin_comment
comment|/* Period at which reads are performed (100ms units) */
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

begin_comment
comment|/* FC supplied handle */
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

begin_comment
comment|/* FC supplied handle */
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

begin_comment
comment|/* Partition offset into flash */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_ADDR_RANGE_OFFSET_OFST
value|8
end_define

begin_comment
comment|/* Partition length */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_LOG_ADDR_RANGE_LENGTH_OFST
value|12
end_define

begin_comment
comment|/* Partition erase size */
end_comment

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

begin_comment
comment|/* Enable/disable printing to JTAG UART */
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

begin_comment
comment|/* Perform a clock operation */
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
comment|/* Retrieve the clock value of the specified clock */
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

begin_comment
comment|/* Set the clock value of the specified clock */
end_comment

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
comment|/* Affected bank */
end_comment

begin_comment
comment|/*            MC_CMD_FC_IN_DDR_BANK_OFST 8 */
end_comment

begin_comment
comment|/* Flags */
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

begin_comment
comment|/* 128-byte page of serial presence detect data read from module's EEPROM */
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

begin_comment
comment|/* Page index of the spd data copied into MC_CMD_FC_IN_DDR_SPD */
end_comment

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
comment|/* Affected bank */
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

begin_comment
comment|/* FC timestamp operation code */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_OP_OFST
value|4
end_define

begin_comment
comment|/* enum: Read transmit timestamp(s) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT
value|0x0
end_define

begin_comment
comment|/* enum: Read snapshot timestamps */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_SNAPSHOT
value|0x1
end_define

begin_comment
comment|/* enum: Clear all transmit timestamps */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_CLEAR_TRANSMIT
value|0x2
end_define

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

begin_comment
comment|/* Control filtering of the returned timestamp and sequence number specified  * here  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_FILTER_OFST
value|8
end_define

begin_comment
comment|/* enum: Return most recent timestamp. No filtering */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_LATEST
value|0x0
end_define

begin_comment
comment|/* enum: Match timestamp against the PTP clock ID, port number and sequence  * number specified  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_MATCH
value|0x1
end_define

begin_comment
comment|/* Clock identity of PTP packet for which timestamp required */
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

begin_comment
comment|/* Port number of PTP packet for which timestamp required */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_TIMESTAMP_READ_TRANSMIT_PORT_NUM_OFST
value|20
end_define

begin_comment
comment|/* Sequence number of PTP packet for which timestamp required */
end_comment

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

begin_comment
comment|/* Basic commands for SPI Flash. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_OP_OFST
value|4
end_define

begin_comment
comment|/* enum: SPI Flash read */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_READ
value|0x0
end_define

begin_comment
comment|/* enum: SPI Flash write */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_WRITE
value|0x1
end_define

begin_comment
comment|/* enum: SPI Flash erase */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_SPI_ERASE
value|0x2
end_define

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

begin_comment
comment|/* Operation code indicating component type */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_OP_OFST
value|4
end_define

begin_comment
comment|/* enum: Power noise generator. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE
value|0x0
end_define

begin_comment
comment|/* enum: DDR soak test component. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK
value|0x1
end_define

begin_comment
comment|/* enum: Diagnostics datapath control component. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL
value|0x2
end_define

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

begin_comment
comment|/* Sub-opcode describing the operation to be carried out */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_SUB_OP_OFST
value|8
end_define

begin_comment
comment|/* enum: Read the configuration (the 32-bit values in each of the clock enable  * count and toggle count registers)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_READ_CONFIG
value|0x0
end_define

begin_comment
comment|/* enum: Write a new configuration to the clock enable count and toggle count  * registers  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_WRITE_CONFIG
value|0x1
end_define

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

begin_comment
comment|/* The 32-bit value to be written to the toggle count register */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_POWER_NOISE_WRITE_CONFIG_TOGGLE_COUNT_OFST
value|12
end_define

begin_comment
comment|/* The 32-bit value to be written to the clock enable count register */
end_comment

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

begin_comment
comment|/* Sub-opcode describing the operation to be carried out */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_SUB_OP_OFST
value|8
end_define

begin_comment
comment|/* enum: Starts DDR soak test on selected banks */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START
value|0x0
end_define

begin_comment
comment|/* enum: Read status of DDR soak test */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_RESULT
value|0x1
end_define

begin_comment
comment|/* enum: Stop test */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_STOP
value|0x2
end_define

begin_comment
comment|/* enum: Set or clear bit that triggers fake errors. These cause subsequent  * tests to fail until the bit is cleared.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_ERROR
value|0x3
end_define

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

begin_comment
comment|/* Mask of DDR banks to be tested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DDR_SOAK_START_BANK_MASK_OFST
value|12
end_define

begin_comment
comment|/* Pattern to use in the soak test */
end_comment

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

begin_comment
comment|/* Either multiple automatic tests until a STOP command is issued, or one  * single test  */
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

begin_comment
comment|/* DDR bank to read status from */
end_comment

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

begin_comment
comment|/* Mask of DDR banks to be tested */
end_comment

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

begin_comment
comment|/* Mask of DDR banks to set/clear error flag on */
end_comment

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

begin_comment
comment|/* Sub-opcode describing the operation to be carried out */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_SUB_OP_OFST
value|8
end_define

begin_comment
comment|/* enum: Set a known datapath configuration */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_SET_MODE
value|0x0
end_define

begin_comment
comment|/* enum: Apply raw config to datapath control registers */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_RAW_CONFIG
value|0x1
end_define

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

begin_comment
comment|/* Datapath configuration identifier */
end_comment

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

begin_comment
comment|/* Value to write into control register 1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_RAW_CONFIG_CONTROL1_OFST
value|12
end_define

begin_comment
comment|/* Value to write into control register 2 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_IN_DIAG_DATAPATH_CTRL_RAW_CONFIG_CONTROL2_OFST
value|16
end_define

begin_comment
comment|/* Value to write into control register 3 */
end_comment

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

begin_comment
comment|/* enum: (Last entry) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_RX_NSTATS
value|0x19
end_define

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

begin_comment
comment|/* enum: (Last entry) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_MAC_TX_NSTATS
value|0x16
end_define

begin_comment
comment|/* MC_CMD_FC_OUT_MAC_GET_STATS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_MAC_GET_STATS_LEN
value|((((0-1+(64*MC_CMD_FC_MAC_NSTATS_PER_BLOCK))+1))>>3)
end_define

begin_comment
comment|/* MAC Statistics */
end_comment

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

begin_comment
comment|/* enum: Test not yet initiated */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_NONE
value|0x0
end_define

begin_comment
comment|/* enum: Test is in progress */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_INPROGRESS
value|0x1
end_define

begin_comment
comment|/* enum: Timed completed */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_SUCCESS
value|0x2
end_define

begin_comment
comment|/* enum: Test did not complete in specified time */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OP_DDR_TEST_TIMER_EXPIRED
value|0x3
end_define

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

begin_comment
comment|/* Test result from FPGA */
end_comment

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

begin_comment
comment|/* Assertion status flag. */
end_comment

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

begin_comment
comment|/* enum: No crash data available */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_STATE_CLEAR
value|0x0
end_define

begin_comment
comment|/* enum: New crash data available */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_STATE_NEW
value|0x1
end_define

begin_comment
comment|/* enum: Crash data has been sent */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_STATE_NOTIFIED
value|0x2
end_define

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

begin_comment
comment|/* enum: No crash has been recorded. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_TYPE_NONE
value|0x0
end_define

begin_comment
comment|/* enum: Crash due to exception. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_TYPE_EXCEPTION
value|0x1
end_define

begin_comment
comment|/* enum: Crash due to assertion. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_GET_ASSERT_FLAGS_TYPE_ASSERTION
value|0x2
end_define

begin_comment
comment|/* Failing PC value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_SAVED_PC_OFFS_OFST
value|4
end_define

begin_comment
comment|/* Saved GP regs */
end_comment

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

begin_comment
comment|/* Exception Type */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_EXCEPTION_TYPE_OFFS_OFST
value|132
end_define

begin_comment
comment|/* Instruction at which exception occurred */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_GET_ASSERT_EXCEPTION_PC_ADDR_OFFS_OFST
value|136
end_define

begin_comment
comment|/* BAD Address that triggered address-based exception */
end_comment

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

begin_comment
comment|/* Build timestamp (seconds since epoch) */
end_comment

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

begin_comment
comment|/* Build timestamp (seconds since epoch) */
end_comment

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

begin_comment
comment|/* Qsys system ID */
end_comment

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

begin_comment
comment|/* Number of maps */
end_comment

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

begin_comment
comment|/* Index of the map */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_INDEX_OFST
value|0
end_define

begin_comment
comment|/* Options for the map */
end_comment

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

begin_comment
comment|/* Address of start of map */
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

begin_comment
comment|/* Length of address map */
end_comment

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

begin_comment
comment|/* Component information field */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_READ_MAP_INDEX_COMP_INFO_OFST
value|24
end_define

begin_comment
comment|/* License expiry data for map */
end_comment

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

begin_comment
comment|/* Name of the component */
end_comment

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

begin_comment
comment|/* Number of internal ports */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_CAPABILITIES_INTERNAL_OFST
value|0
end_define

begin_comment
comment|/* Number of external ports */
end_comment

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

begin_comment
comment|/* Transceiver Transmit settings */
end_comment

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

begin_comment
comment|/* Transceiver Receive settings */
end_comment

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

begin_comment
comment|/* Rx eye opening */
end_comment

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

begin_comment
comment|/* PCS status word */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_PCS_STATUS_OFST
value|16
end_define

begin_comment
comment|/* Link status word */
end_comment

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

begin_comment
comment|/* Current SFp parameters applied */
end_comment

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

begin_comment
comment|/* Link speed is 100, 1000, 10000 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_SPEED_OFST
value|24
end_define

begin_comment
comment|/* Length of copper cable - zero when not relevant */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_COPPER_LEN_OFST
value|28
end_define

begin_comment
comment|/* True if a dual speed SFP+ module */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_DUAL_SPEED_OFST
value|32
end_define

begin_comment
comment|/* True if an SFP Module is present (other fields valid when true) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_PRESENT_OFST
value|36
end_define

begin_comment
comment|/* The type of the SFP+ Module */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_PHY_SFP_TYPE_OFST
value|40
end_define

begin_comment
comment|/* PHY config flags */
end_comment

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

begin_comment
comment|/* MAC configuration applied */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_MAC_CONFIG_OFST
value|0
end_define

begin_comment
comment|/* MTU size */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_MAC_MTU_OFST
value|4
end_define

begin_comment
comment|/* IF Mode status */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_MAC_IF_STATUS_OFST
value|8
end_define

begin_comment
comment|/* MAC address configured */
end_comment

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

begin_comment
comment|/* Rx Eye measurements */
end_comment

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

begin_comment
comment|/* Has the eye plot dump completed and data returned is valid? */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_UHLINK_READ_RX_EYE_PLOT_VALID_OFST
value|0
end_define

begin_comment
comment|/* Rx Eye binary plot */
end_comment

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

begin_comment
comment|/* Count of valid keys */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_LICENSE_VALID_KEYS_OFST
value|0
end_define

begin_comment
comment|/* Count of invalid keys */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_LICENSE_INVALID_KEYS_OFST
value|4
end_define

begin_comment
comment|/* Count of blacklisted keys */
end_comment

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

begin_comment
comment|/* Capabilities of the FPGA/FC */
end_comment

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

begin_comment
comment|/* The data read */
end_comment

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

begin_comment
comment|/* Timer handle */
end_comment

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

begin_comment
comment|/* Host supplied handle (unique) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_HOST_HANDLE_OFST
value|0
end_define

begin_comment
comment|/* Address into which to transfer data in host */
end_comment

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

begin_comment
comment|/* AOE address from which to transfer data */
end_comment

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

begin_comment
comment|/* Length of AOE transfer (total) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_AOE_LENGTH_OFST
value|20
end_define

begin_comment
comment|/* Length of host transfer (total) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_TIMED_READ_GET_HOST_LENGTH_OFST
value|24
end_define

begin_comment
comment|/* See FLAGS entry for MC_CMD_FC_IN_TIMED_READ_SET */
end_comment

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

begin_comment
comment|/* When active, start read time */
end_comment

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

begin_comment
comment|/* When active, end read time */
end_comment

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

begin_comment
comment|/* The 32-bit value read from the toggle count register */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FC_OUT_DIAG_POWER_NOISE_READ_CONFIG_TOGGLE_COUNT_OFST
value|0
end_define

begin_comment
comment|/* The 32-bit value read from the clock enable count register */
end_comment

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

begin_comment
comment|/* DDR soak test status word; bits [4:0] are relevant. */
end_comment

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

begin_comment
comment|/* DDR soak test error count */
end_comment

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
comment|/* MC_CMD_AOE  * AOE operations on MC  */
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

begin_comment
comment|/* enum: FPGA and CPLD information */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_INFO
value|0x1
end_define

begin_comment
comment|/* enum: Currents and voltages read from MCP3424s; DEBUG */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CURRENTS
value|0x2
end_define

begin_comment
comment|/* enum: Temperatures at locations around the PCB; DEBUG */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_TEMPERATURES
value|0x3
end_define

begin_comment
comment|/* enum: Set CPLD to idle */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CPLD_IDLE
value|0x4
end_define

begin_comment
comment|/* enum: Read from CPLD register */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CPLD_READ
value|0x5
end_define

begin_comment
comment|/* enum: Write to CPLD register */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CPLD_WRITE
value|0x6
end_define

begin_comment
comment|/* enum: Execute CPLD instruction */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CPLD_INSTRUCTION
value|0x7
end_define

begin_comment
comment|/* enum: Reprogram the CPLD on the AOE device */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_CPLD_REPROGRAM
value|0x8
end_define

begin_comment
comment|/* enum: AOE power control */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_POWER
value|0x9
end_define

begin_comment
comment|/* enum: AOE image loading */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_LOAD
value|0xa
end_define

begin_comment
comment|/* enum: Fan monitoring */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_FAN_CONTROL
value|0xb
end_define

begin_comment
comment|/* enum: Fan failures since last reset */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_FAN_FAILURES
value|0xc
end_define

begin_comment
comment|/* enum: Get generic AOE MAC statistics */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_MAC_STATS
value|0xd
end_define

begin_comment
comment|/* enum: Retrieve PHY specific information */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_GET_PHY_MEDIA_INFO
value|0xe
end_define

begin_comment
comment|/* enum: Write a number of JTAG primitive commands, return will give data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_JTAG_WRITE
value|0xf
end_define

begin_comment
comment|/* enum: Control access to the FPGA via the Siena JTAG Chain */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_FPGA_ACCESS
value|0x10
end_define

begin_comment
comment|/* enum: Set the MTU offset between Siena and AOE MACs */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_SET_MTU_OFFSET
value|0x11
end_define

begin_comment
comment|/* enum: How link state is handled */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_LINK_STATE
value|0x12
end_define

begin_comment
comment|/* enum: How Siena MAC statistics are reported (deprecated - use  * MC_CMD_AOE_OP_ASIC_STATS)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_SIENA_STATS
value|0x13
end_define

begin_comment
comment|/* enum: How native ASIC MAC statistics are reported - replaces the deprecated  * command MC_CMD_AOE_OP_SIENA_STATS  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_ASIC_STATS
value|0x13
end_define

begin_comment
comment|/* enum: DDR memory information */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_DDR
value|0x14
end_define

begin_comment
comment|/* enum: FC control */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_FC
value|0x15
end_define

begin_comment
comment|/* enum: DDR ECC status reads */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_DDR_ECC_STATUS
value|0x16
end_define

begin_comment
comment|/* enum: Commands for MC-SPI Master emulation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_MC_SPI_MASTER
value|0x17
end_define

begin_comment
comment|/* enum: Commands for FC boot control */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OP_FC_BOOT
value|0x18
end_define

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

begin_comment
comment|/* enum: Reprogram CPLD, poll for completion */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_REPROGRAM_REPROGRAM
value|0x1
end_define

begin_comment
comment|/* enum: Reprogram CPLD, send event on completion */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_REPROGRAM_REPROGRAM_EVENT
value|0x3
end_define

begin_comment
comment|/* enum: Get status of reprogramming operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_CPLD_REPROGRAM_STATUS
value|0x4
end_define

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

begin_comment
comment|/* Turn on or off AOE power */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_OP_OFST
value|4
end_define

begin_comment
comment|/* enum: Turn off FPGA power */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_OFF
value|0x0
end_define

begin_comment
comment|/* enum: Turn on FPGA power */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_ON
value|0x1
end_define

begin_comment
comment|/* enum: Clear peak power measurement */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_CLEAR
value|0x2
end_define

begin_comment
comment|/* enum: Show current power in sensors output */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_SHOW_CURRENT
value|0x3
end_define

begin_comment
comment|/* enum: Show peak power in sensors output */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_SHOW_PEAK
value|0x4
end_define

begin_comment
comment|/* enum: Show current DDR current */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_DDR_LAST
value|0x5
end_define

begin_comment
comment|/* enum: Show peak DDR current */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_DDR_PEAK
value|0x6
end_define

begin_comment
comment|/* enum: Clear peak DDR current */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_POWER_DDR_CLEAR
value|0x7
end_define

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

begin_comment
comment|/* Image to be loaded (0 - main or 1 - diagnostic) to load in normal sequence  */
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

begin_comment
comment|/* If non zero report measured fan RPM rather than nominal */
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

begin_comment
comment|/* AOE port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MAC_STATS_PORT_OFST
value|4
end_define

begin_comment
comment|/* Host memory address for statistics */
end_comment

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

begin_comment
comment|/* Length of DMA data (optional) */
end_comment

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

begin_comment
comment|/* AOE port */
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

begin_comment
comment|/* Enable or disable access */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FPGA_ACCESS_OP_OFST
value|4
end_define

begin_comment
comment|/* enum: Enable access */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FPGA_ACCESS_ENABLE
value|0x1
end_define

begin_comment
comment|/* enum: Disable access */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FPGA_ACCESS_DISABLE
value|0x2
end_define

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

begin_comment
comment|/* AOE port - when not ALL_EXTERNAL or ALL_INTERNAL specifies port number */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SET_MTU_OFFSET_PORT_OFST
value|4
end_define

begin_comment
comment|/* enum: Apply to all external ports */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SET_MTU_OFFSET_ALL_EXTERNAL
value|0x8000
end_define

begin_comment
comment|/* enum: Apply to all internal ports */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SET_MTU_OFFSET_ALL_INTERNAL
value|0x4000
end_define

begin_comment
comment|/* The MTU offset to be applied to the external ports */
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

begin_comment
comment|/* enum: AOE and associated external port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_SIMPLE_SEPARATE
value|0x0
end_define

begin_comment
comment|/* enum: AOE and OR of all external ports */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_SIMPLE_COMBINED
value|0x1
end_define

begin_comment
comment|/* enum: Individual ports */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_DIAGNOSTIC
value|0x2
end_define

begin_comment
comment|/* enum: Configure link state mode on given AOE port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_CUSTOM
value|0x3
end_define

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

begin_comment
comment|/* enum: No-op */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_OP_NONE
value|0x0
end_define

begin_comment
comment|/* enum: logical OR of all SFP ports link status */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_OP_OR
value|0x1
end_define

begin_comment
comment|/* enum: logical AND of all SFP ports link status */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_LINK_STATE_OP_AND
value|0x2
end_define

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

begin_comment
comment|/* How MAC statistics are reported */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SIENA_STATS_MODE_OFST
value|4
end_define

begin_comment
comment|/* enum: Statistics from Siena (default) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SIENA_STATS_STATS_SIENA
value|0x0
end_define

begin_comment
comment|/* enum: Statistics from AOE external ports */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_SIENA_STATS_STATS_AOE
value|0x1
end_define

begin_comment
comment|/* MC_CMD_AOE_IN_ASIC_STATS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_ASIC_STATS_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* How MAC statistics are reported */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_ASIC_STATS_MODE_OFST
value|4
end_define

begin_comment
comment|/* enum: Statistics from the ASIC (default) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_ASIC_STATS_STATS_ASIC
value|0x0
end_define

begin_comment
comment|/* enum: Statistics from AOE external ports */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_ASIC_STATS_STATS_AOE
value|0x1
end_define

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
comment|/*               MC_CMD_FC/MC_CMD_FC_IN_DDR/MC_CMD_FC_IN_DDR_BANK */
end_comment

begin_comment
comment|/* Page index of SPD data */
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
comment|/*               MC_CMD_FC/MC_CMD_FC_IN_DDR/MC_CMD_FC_IN_DDR_BANK */
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

begin_comment
comment|/* Basic commands for MC SPI Master emulation. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_OP_OFST
value|4
end_define

begin_comment
comment|/* enum: MC SPI read */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_READ
value|0x0
end_define

begin_comment
comment|/* enum: MC SPI write */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_MC_SPI_MASTER_WRITE
value|0x1
end_define

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
comment|/* MC_CMD_AOE_IN_FC_BOOT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FC_BOOT_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_AOE_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* FC boot control flags */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FC_BOOT_CONTROL_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FC_BOOT_CONTROL_BOOT_ENABLE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_IN_FC_BOOT_CONTROL_BOOT_ENABLE_WIDTH
value|1
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

begin_comment
comment|/* JTAG IDCODE of CPLD */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_CPLD_IDCODE_OFST
value|0
end_define

begin_comment
comment|/* Version of CPLD */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_CPLD_VERSION_OFST
value|4
end_define

begin_comment
comment|/* JTAG IDCODE of FPGA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_IDCODE_OFST
value|8
end_define

begin_comment
comment|/* JTAG USERCODE of FPGA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_VERSION_OFST
value|12
end_define

begin_comment
comment|/* FPGA type - read from CPLD straps */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_TYPE_OFST
value|16
end_define

begin_comment
comment|/* FPGA state (debug) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_STATE_OFST
value|20
end_define

begin_comment
comment|/* FPGA image - partition from which loaded */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_IMAGE_OFST
value|24
end_define

begin_comment
comment|/* FC state */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_STATE_OFST
value|28
end_define

begin_comment
comment|/* enum: Set if watchdog working */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_WATCHDOG
value|0x1
end_define

begin_comment
comment|/* enum: Set if MC-FC communications working */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_COMMS
value|0x2
end_define

begin_comment
comment|/* Random pieces of information */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FLAGS_OFST
value|32
end_define

begin_comment
comment|/* enum: Power to FPGA supplied by PEG connector, not PCIe bus */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_PEG_POWER
value|0x1
end_define

begin_comment
comment|/* enum: CPLD apparently good */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_CPLD_GOOD
value|0x2
end_define

begin_comment
comment|/* enum: FPGA working normally */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_GOOD
value|0x4
end_define

begin_comment
comment|/* enum: FPGA is powered */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FPGA_POWER
value|0x8
end_define

begin_comment
comment|/* enum: Board has incompatible SODIMMs fitted */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_BAD_SODIMM
value|0x10
end_define

begin_comment
comment|/* enum: Board has ByteBlaster connected */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_HAS_BYTEBLASTER
value|0x20
end_define

begin_comment
comment|/* Revision of Modena board */
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

begin_comment
comment|/* Result of FC booting - not valid while a ByteBlaster is connected. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_RESULT_OFST
value|40
end_define

begin_comment
comment|/* enum: No error */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_NO_ERROR
value|0x0
end_define

begin_comment
comment|/* enum: Bad address set in CPLD */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_ADDRESS
value|0x1
end_define

begin_comment
comment|/* enum: Bad header */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_MAGIC
value|0x2
end_define

begin_comment
comment|/* enum: Bad text section details */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_TEXT
value|0x3
end_define

begin_comment
comment|/* enum: Bad checksum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_CHECKSUM
value|0x4
end_define

begin_comment
comment|/* enum: Bad BSP */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_FAIL_BAD_BSP
value|0x5
end_define

begin_comment
comment|/* enum: FC application loaded and execution attempted */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_APP_EXECUTE
value|0x80
end_define

begin_comment
comment|/* enum: FC application Started */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_APP_STARTED
value|0x81
end_define

begin_comment
comment|/* enum: No bootrom in FPGA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_INFO_FC_BOOT_NO_BOOTROM
value|0xff
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_CURRENTS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CURRENTS_LEN
value|68
end_define

begin_comment
comment|/* Set of currents and voltages (mA or mV as appropriate) */
end_comment

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

begin_comment
comment|/* Set of temperatures */
end_comment

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

begin_comment
comment|/* enum: The first set of enum values are for Modena code. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_MAIN_0
value|0x0
end_define

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
comment|/* enum: The second set of enum values are for Sorrento code. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_SORRENTO_MAIN_0
value|0x0
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_SORRENTO_MAIN_1
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_SORRENTO_IND_0
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_SORRENTO_IND_1
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_SORRENTO_SODIMM_0
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_SORRENTO_SODIMM_1
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_SORRENTO_FPGA
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_SORRENTO_PHY0
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_TEMPERATURES_SORRENTO_PHY1
value|0x8
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

begin_comment
comment|/* The value read from the CPLD */
end_comment

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

begin_comment
comment|/* Failure counts for each fan */
end_comment

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

begin_comment
comment|/* Results of status command (only) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_CPLD_REPROGRAM_STATUS_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_POWER_OFF msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_POWER_OFF_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_POWER_ON msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_POWER_ON_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_LOAD msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_LOAD_LEN
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
comment|/* MC_CMD_AOE_OUT_MAC_STATS_NO_DMA msgresponse: See MC_CMD_MAC_STATS_OUT_NO_DMA  * for details  */
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

begin_comment
comment|/* in bytes */
end_comment

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

begin_comment
comment|/* Used to align the in and out data blocks so the MC can re-use the cmd */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_JTAG_WRITE_DATALEN_OFST
value|0
end_define

begin_comment
comment|/* out bytes */
end_comment

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

begin_comment
comment|/* Information on the module. */
end_comment

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
name|MC_CMD_AOE_OUT_DDR_NOT_REACHABLE_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_NOT_REACHABLE_WIDTH
value|1
end_define

begin_comment
comment|/* Memory size, in MB. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_CAPACITY_OFST
value|4
end_define

begin_comment
comment|/* The memory type, as reported from SPD information */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_TYPE_OFST
value|8
end_define

begin_comment
comment|/* Nominal voltage of the module (as applied) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_DDR_VOLTAGE_OFST
value|12
end_define

begin_comment
comment|/* SPD data read from the module */
end_comment

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
comment|/* MC_CMD_AOE_OUT_SET_MTU_OFFSET msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_SET_MTU_OFFSET_LEN
value|0
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
comment|/* MC_CMD_AOE_OUT_SIENA_STATS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_SIENA_STATS_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_AOE_OUT_ASIC_STATS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_ASIC_STATS_LEN
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

begin_comment
comment|/* Flags describing status info on the module. */
end_comment

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

begin_comment
comment|/* DDR ECC status on the module. */
end_comment

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
comment|/* MC_CMD_AOE_OUT_FC_BOOT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AOE_OUT_FC_BOOT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PTP  * Perform PTP operation  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP
value|0xb
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xb_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xb_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* PTP operation code */
end_comment

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

begin_comment
comment|/* enum: Enable PTP packet timestamping operation. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_ENABLE
value|0x1
end_define

begin_comment
comment|/* enum: Disable PTP packet timestamping operation. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_DISABLE
value|0x2
end_define

begin_comment
comment|/* enum: Send a PTP packet. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_TRANSMIT
value|0x3
end_define

begin_comment
comment|/* enum: Read the current NIC time. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_READ_NIC_TIME
value|0x4
end_define

begin_comment
comment|/* enum: Get the current PTP status. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_STATUS
value|0x5
end_define

begin_comment
comment|/* enum: Adjust the PTP NIC's time. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_ADJUST
value|0x6
end_define

begin_comment
comment|/* enum: Synchronize host and NIC time. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_SYNCHRONIZE
value|0x7
end_define

begin_comment
comment|/* enum: Basic manufacturing tests. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_MANFTEST_BASIC
value|0x8
end_define

begin_comment
comment|/* enum: Packet based manufacturing tests. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_MANFTEST_PACKET
value|0x9
end_define

begin_comment
comment|/* enum: Reset some of the PTP related statistics */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_RESET_STATS
value|0xa
end_define

begin_comment
comment|/* enum: Debug operations to MC. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_DEBUG
value|0xb
end_define

begin_comment
comment|/* enum: Read an FPGA register */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_FPGAREAD
value|0xc
end_define

begin_comment
comment|/* enum: Write an FPGA register */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_FPGAWRITE
value|0xd
end_define

begin_comment
comment|/* enum: Apply an offset to the NIC clock */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_CLOCK_OFFSET_ADJUST
value|0xe
end_define

begin_comment
comment|/* enum: Change Apply an offset to the NIC clock */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_CLOCK_FREQ_ADJUST
value|0xf
end_define

begin_comment
comment|/* enum: Set the MC packet filter VLAN tags for received PTP packets */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_RX_SET_VLAN_FILTER
value|0x10
end_define

begin_comment
comment|/* enum: Set the MC packet filter UUID for received PTP packets */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_RX_SET_UUID_FILTER
value|0x11
end_define

begin_comment
comment|/* enum: Set the MC packet filter Domain for received PTP packets */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_RX_SET_DOMAIN_FILTER
value|0x12
end_define

begin_comment
comment|/* enum: Set the clock source */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_SET_CLK_SRC
value|0x13
end_define

begin_comment
comment|/* enum: Reset value of Timer Reg. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_RST_CLK
value|0x14
end_define

begin_comment
comment|/* enum: Enable the forwarding of PPS events to the host */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_PPS_ENABLE
value|0x15
end_define

begin_comment
comment|/* enum: Get the time format used by this NIC for PTP operations */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_GET_TIME_FORMAT
value|0x16
end_define

begin_comment
comment|/* enum: Get the clock attributes. NOTE- extended version of  * MC_CMD_PTP_OP_GET_TIME_FORMAT  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_GET_ATTRIBUTES
value|0x16
end_define

begin_comment
comment|/* enum: Get corrections that should be applied to the various different  * timestamps  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_GET_TIMESTAMP_CORRECTIONS
value|0x17
end_define

begin_comment
comment|/* enum: Subscribe to receive periodic time events indicating the current NIC  * time  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_TIME_EVENT_SUBSCRIBE
value|0x18
end_define

begin_comment
comment|/* enum: Unsubscribe to stop receiving time events */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_TIME_EVENT_UNSUBSCRIBE
value|0x19
end_define

begin_comment
comment|/* enum: PPS based manfacturing tests. Requires PPS output to be looped to PPS  * input on the same NIC.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_MANFTEST_PPS
value|0x1a
end_define

begin_comment
comment|/* enum: Set the PTP sync status. Status is used by firmware to report to event  * subscribers.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_SET_SYNC_STATUS
value|0x1b
end_define

begin_comment
comment|/* enum: Above this for future use. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OP_MAX
value|0x1c
end_define

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

begin_comment
comment|/* Event queue for PTP events */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ENABLE_QUEUE_OFST
value|8
end_define

begin_comment
comment|/* PTP timestamping mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ENABLE_MODE_OFST
value|12
end_define

begin_comment
comment|/* enum: PTP, version 1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MODE_V1
value|0x0
end_define

begin_comment
comment|/* enum: PTP, version 1, with VLAN headers - deprecated */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MODE_V1_VLAN
value|0x1
end_define

begin_comment
comment|/* enum: PTP, version 2 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MODE_V2
value|0x2
end_define

begin_comment
comment|/* enum: PTP, version 2, with VLAN headers - deprecated */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MODE_V2_VLAN
value|0x3
end_define

begin_comment
comment|/* enum: PTP, version 2, with improved UUID filtering */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MODE_V2_ENHANCED
value|0x4
end_define

begin_comment
comment|/* enum: FCoE (seconds and microseconds) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MODE_FCOE
value|0x5
end_define

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

begin_comment
comment|/* Transmit packet length */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TRANSMIT_LENGTH_OFST
value|8
end_define

begin_comment
comment|/* Transmit packet data */
end_comment

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

begin_comment
comment|/* Frequency adjustment 40 bit fixed point ns */
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

begin_comment
comment|/* enum: Number of fractional bits in frequency adjustment */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_BITS
value|0x28
end_define

begin_comment
comment|/* Time adjustment in seconds */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_SECONDS_OFST
value|16
end_define

begin_comment
comment|/* Time adjustment major value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_MAJOR_OFST
value|16
end_define

begin_comment
comment|/* Time adjustment in nanoseconds */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_NANOSECONDS_OFST
value|20
end_define

begin_comment
comment|/* Time adjustment minor value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_ADJUST_MINOR_OFST
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

begin_comment
comment|/* Number of time readings to capture */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SYNCHRONIZE_NUMTIMESETS_OFST
value|8
end_define

begin_comment
comment|/* Host address in which to write "synchronization started" indication (64  * bits)  */
end_comment

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

begin_comment
comment|/* Enable or disable packet testing */
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
comment|/* Reset PTP statistics */
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

begin_comment
comment|/* Debug operations */
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

begin_comment
comment|/* Time adjustment in seconds */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_OFFSET_ADJUST_SECONDS_OFST
value|8
end_define

begin_comment
comment|/* Time adjustment major value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_OFFSET_ADJUST_MAJOR_OFST
value|8
end_define

begin_comment
comment|/* Time adjustment in nanoseconds */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_OFFSET_ADJUST_NANOSECONDS_OFST
value|12
end_define

begin_comment
comment|/* Time adjustment minor value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_CLOCK_OFFSET_ADJUST_MINOR_OFST
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

begin_comment
comment|/* Frequency adjustment 40 bit fixed point ns */
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
comment|/* enum: Number of fractional bits in frequency adjustment */
end_comment

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

begin_comment
comment|/* Number of VLAN tags, 0 if not VLAN */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_VLAN_FILTER_NUM_VLAN_TAGS_OFST
value|8
end_define

begin_comment
comment|/* Set of VLAN tags to filter against */
end_comment

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

begin_comment
comment|/* 1 to enable UUID filtering, 0 to disable */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_UUID_FILTER_ENABLE_OFST
value|8
end_define

begin_comment
comment|/* UUID to filter against */
end_comment

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

begin_comment
comment|/* 1 to enable Domain filtering, 0 to disable */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_DOMAIN_FILTER_ENABLE_OFST
value|8
end_define

begin_comment
comment|/* Domain number to filter against */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RX_SET_DOMAIN_FILTER_DOMAIN_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_SET_CLK_SRC msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SET_CLK_SRC_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* Set the clock source. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SET_CLK_SRC_CLK_OFST
value|8
end_define

begin_comment
comment|/* enum: Internal. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_CLK_SRC_INTERNAL
value|0x0
end_define

begin_comment
comment|/* enum: External. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_CLK_SRC_EXTERNAL
value|0x1
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_RST_CLK msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_RST_CLK_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* Reset value of Timer Reg. */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

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

begin_comment
comment|/* Enable or disable */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_PPS_ENABLE_OP_OFST
value|4
end_define

begin_comment
comment|/* enum: Enable */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_ENABLE_PPS
value|0x0
end_define

begin_comment
comment|/* enum: Disable */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_DISABLE_PPS
value|0x1
end_define

begin_comment
comment|/* Queue id to send events back */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_PPS_ENABLE_QUEUE_ID_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_GET_TIME_FORMAT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_GET_TIME_FORMAT_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_PTP_IN_GET_ATTRIBUTES msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_GET_ATTRIBUTES_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_PTP_IN_GET_TIMESTAMP_CORRECTIONS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_GET_TIMESTAMP_CORRECTIONS_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* MC_CMD_PTP_IN_TIME_EVENT_SUBSCRIBE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TIME_EVENT_SUBSCRIBE_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* Original field containing queue ID. Now extended to include flags. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TIME_EVENT_SUBSCRIBE_QUEUE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TIME_EVENT_SUBSCRIBE_QUEUE_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TIME_EVENT_SUBSCRIBE_QUEUE_ID_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TIME_EVENT_SUBSCRIBE_REPORT_SYNC_STATUS_LBN
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TIME_EVENT_SUBSCRIBE_REPORT_SYNC_STATUS_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_TIME_EVENT_UNSUBSCRIBE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TIME_EVENT_UNSUBSCRIBE_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* Unsubscribe options */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TIME_EVENT_UNSUBSCRIBE_CONTROL_OFST
value|8
end_define

begin_comment
comment|/* enum: Unsubscribe a single queue */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TIME_EVENT_UNSUBSCRIBE_SINGLE
value|0x0
end_define

begin_comment
comment|/* enum: Unsubscribe all queues */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TIME_EVENT_UNSUBSCRIBE_ALL
value|0x1
end_define

begin_comment
comment|/* Event queue ID */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_TIME_EVENT_UNSUBSCRIBE_QUEUE_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_MANFTEST_PPS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_MANFTEST_PPS_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* 1 to enable PPS test mode, 0 to disable and return result. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_MANFTEST_PPS_TEST_ENABLE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_PTP_IN_SET_SYNC_STATUS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SET_SYNC_STATUS_LEN
value|24
end_define

begin_comment
comment|/*            MC_CMD_PTP_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_PTP_IN_PERIPH_ID_OFST 4 */
end_comment

begin_comment
comment|/* NIC - Host System Clock Synchronization status */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SET_SYNC_STATUS_STATUS_OFST
value|8
end_define

begin_comment
comment|/* enum: Host System clock and NIC clock are not in sync */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SET_SYNC_STATUS_NOT_IN_SYNC
value|0x0
end_define

begin_comment
comment|/* enum: Host System clock and NIC clock are synchronized */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SET_SYNC_STATUS_IN_SYNC
value|0x1
end_define

begin_comment
comment|/* If synchronized, number of seconds until clocks should be considered to be  * no longer in sync.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SET_SYNC_STATUS_TIMEOUT_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SET_SYNC_STATUS_RESERVED0_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_IN_SET_SYNC_STATUS_RESERVED1_OFST
value|20
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

begin_comment
comment|/* Value of seconds timestamp */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_TRANSMIT_SECONDS_OFST
value|0
end_define

begin_comment
comment|/* Timestamp major value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_TRANSMIT_MAJOR_OFST
value|0
end_define

begin_comment
comment|/* Value of nanoseconds timestamp */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_TRANSMIT_NANOSECONDS_OFST
value|4
end_define

begin_comment
comment|/* Timestamp minor value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_TRANSMIT_MINOR_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_TIME_EVENT_SUBSCRIBE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_TIME_EVENT_SUBSCRIBE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_TIME_EVENT_UNSUBSCRIBE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_TIME_EVENT_UNSUBSCRIBE_LEN
value|0
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

begin_comment
comment|/* Value of seconds timestamp */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_READ_NIC_TIME_SECONDS_OFST
value|0
end_define

begin_comment
comment|/* Timestamp major value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_READ_NIC_TIME_MAJOR_OFST
value|0
end_define

begin_comment
comment|/* Value of nanoseconds timestamp */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_READ_NIC_TIME_NANOSECONDS_OFST
value|4
end_define

begin_comment
comment|/* Timestamp minor value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_READ_NIC_TIME_MINOR_OFST
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

begin_comment
comment|/* Frequency of NIC's hardware clock */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_CLOCK_FREQ_OFST
value|0
end_define

begin_comment
comment|/* Number of packets transmitted and timestamped */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_TX_OFST
value|4
end_define

begin_comment
comment|/* Number of packets received and timestamped */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_RX_OFST
value|8
end_define

begin_comment
comment|/* Number of packets timestamped by the FPGA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_TS_OFST
value|12
end_define

begin_comment
comment|/* Number of packets filter matched */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_FM_OFST
value|16
end_define

begin_comment
comment|/* Number of packets not filter matched */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_NFM_OFST
value|20
end_define

begin_comment
comment|/* Number of PPS overflows (noise on input?) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_OFLOW_OFST
value|24
end_define

begin_comment
comment|/* Number of PPS bad periods */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_BAD_OFST
value|28
end_define

begin_comment
comment|/* Minimum period of PPS pulse in nanoseconds */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_PER_MIN_OFST
value|32
end_define

begin_comment
comment|/* Maximum period of PPS pulse in nanoseconds */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_PER_MAX_OFST
value|36
end_define

begin_comment
comment|/* Last period of PPS pulse in nanoseconds */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_PER_LAST_OFST
value|40
end_define

begin_comment
comment|/* Mean period of PPS pulse in nanoseconds */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_PER_MEAN_OFST
value|44
end_define

begin_comment
comment|/* Minimum offset of PPS pulse in nanoseconds (signed) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_OFF_MIN_OFST
value|48
end_define

begin_comment
comment|/* Maximum offset of PPS pulse in nanoseconds (signed) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_OFF_MAX_OFST
value|52
end_define

begin_comment
comment|/* Last offset of PPS pulse in nanoseconds (signed) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_STATUS_STATS_PPS_OFF_LAST_OFST
value|56
end_define

begin_comment
comment|/* Mean offset of PPS pulse in nanoseconds (signed) */
end_comment

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

begin_comment
comment|/* A set of host and NIC times */
end_comment

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

begin_comment
comment|/* Host time immediately before NIC's hardware clock read */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_HOSTSTART_OFST
value|0
end_define

begin_comment
comment|/* Value of seconds timestamp */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_SECONDS_OFST
value|4
end_define

begin_comment
comment|/* Timestamp major value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_MAJOR_OFST
value|4
end_define

begin_comment
comment|/* Value of nanoseconds timestamp */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_NANOSECONDS_OFST
value|8
end_define

begin_comment
comment|/* Timestamp minor value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_MINOR_OFST
value|8
end_define

begin_comment
comment|/* Host time immediately after NIC's hardware clock read */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SYNCHRONIZE_HOSTEND_OFST
value|12
end_define

begin_comment
comment|/* Number of nanoseconds waited after reading NIC's hardware clock */
end_comment

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

begin_comment
comment|/* Results of testing */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_BASIC_TEST_RESULT_OFST
value|0
end_define

begin_comment
comment|/* enum: Successful test */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_SUCCESS
value|0x0
end_define

begin_comment
comment|/* enum: FPGA load failed */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_FPGA_LOAD
value|0x1
end_define

begin_comment
comment|/* enum: FPGA version invalid */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_FPGA_VERSION
value|0x2
end_define

begin_comment
comment|/* enum: FPGA registers incorrect */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_FPGA_REGISTERS
value|0x3
end_define

begin_comment
comment|/* enum: Oscillator possibly not working? */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_OSCILLATOR
value|0x4
end_define

begin_comment
comment|/* enum: Timestamps not increasing */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_TIMESTAMPS
value|0x5
end_define

begin_comment
comment|/* enum: Mismatched packet count */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_PACKET_COUNT
value|0x6
end_define

begin_comment
comment|/* enum: Mismatched packet count (Siena filter and FPGA) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_FILTER_COUNT
value|0x7
end_define

begin_comment
comment|/* enum: Not enough packets to perform timestamp check */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_PACKET_ENOUGH
value|0x8
end_define

begin_comment
comment|/* enum: Timestamp trigger GPIO not working */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_GPIO_TRIGGER
value|0x9
end_define

begin_comment
comment|/* enum: Insufficient PPS events to perform checks */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_PPS_ENOUGH
value|0xa
end_define

begin_comment
comment|/* enum: PPS time event period not sufficiently close to 1s. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_PPS_PERIOD
value|0xb
end_define

begin_comment
comment|/* enum: PPS time event nS reading not sufficiently close to zero. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_PPS_NS
value|0xc
end_define

begin_comment
comment|/* enum: PTP peripheral registers incorrect */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_REGISTERS
value|0xd
end_define

begin_comment
comment|/* enum: Failed to read time from PTP peripheral */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_MANF_CLOCK_READ
value|0xe
end_define

begin_comment
comment|/* Presence of external oscillator */
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

begin_comment
comment|/* Results of testing */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_PACKET_TEST_RESULT_OFST
value|0
end_define

begin_comment
comment|/* Number of packets received by FPGA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_PACKET_TEST_FPGACOUNT_OFST
value|4
end_define

begin_comment
comment|/* Number of packets received by Siena filters */
end_comment

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
comment|/* MC_CMD_PTP_OUT_GET_TIME_FORMAT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_TIME_FORMAT_LEN
value|4
end_define

begin_comment
comment|/* Time format required/used by for this NIC. Applies to all PTP MCDI  * operations that pass times between the host and firmware. If this operation  * is not supported (older firmware) a format of seconds and nanoseconds should  * be assumed.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_TIME_FORMAT_FORMAT_OFST
value|0
end_define

begin_comment
comment|/* enum: Times are in seconds and nanoseconds */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_TIME_FORMAT_SECONDS_NANOSECONDS
value|0x0
end_define

begin_comment
comment|/* enum: Major register has units of 16 second per tick, minor 8 ns per tick */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_TIME_FORMAT_16SECONDS_8NANOSECONDS
value|0x1
end_define

begin_comment
comment|/* enum: Major register has units of seconds, minor 2^-27s per tick */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_TIME_FORMAT_SECONDS_27FRACTION
value|0x2
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_GET_ATTRIBUTES msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_LEN
value|24
end_define

begin_comment
comment|/* Time format required/used by for this NIC. Applies to all PTP MCDI  * operations that pass times between the host and firmware. If this operation  * is not supported (older firmware) a format of seconds and nanoseconds should  * be assumed.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_TIME_FORMAT_OFST
value|0
end_define

begin_comment
comment|/* enum: Times are in seconds and nanoseconds */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_SECONDS_NANOSECONDS
value|0x0
end_define

begin_comment
comment|/* enum: Major register has units of 16 second per tick, minor 8 ns per tick */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_16SECONDS_8NANOSECONDS
value|0x1
end_define

begin_comment
comment|/* enum: Major register has units of seconds, minor 2^-27s per tick */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_SECONDS_27FRACTION
value|0x2
end_define

begin_comment
comment|/* Minimum acceptable value for a corrected synchronization timeset. When  * comparing host and NIC clock times, the MC returns a set of samples that  * contain the host start and end time, the MC time when the host start was  * detected and the time the MC waited between reading the time and detecting  * the host end. The corrected sync window is the difference between the host  * end and start times minus the time that the MC waited for host end.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_SYNC_WINDOW_MIN_OFST
value|4
end_define

begin_comment
comment|/* Various PTP capabilities */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_CAPABILITIES_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_REPORT_SYNC_STATUS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_REPORT_SYNC_STATUS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_RESERVED0_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_RESERVED1_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_ATTRIBUTES_RESERVED2_OFST
value|20
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_GET_TIMESTAMP_CORRECTIONS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_TIMESTAMP_CORRECTIONS_LEN
value|16
end_define

begin_comment
comment|/* Uncorrected error on transmit timestamps in NIC clock format */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_TIMESTAMP_CORRECTIONS_TRANSMIT_OFST
value|0
end_define

begin_comment
comment|/* Uncorrected error on receive timestamps in NIC clock format */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_TIMESTAMP_CORRECTIONS_RECEIVE_OFST
value|4
end_define

begin_comment
comment|/* Uncorrected error on PPS output in NIC clock format */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_TIMESTAMP_CORRECTIONS_PPS_OUT_OFST
value|8
end_define

begin_comment
comment|/* Uncorrected error on PPS input in NIC clock format */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_GET_TIMESTAMP_CORRECTIONS_PPS_IN_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_PTP_OUT_MANFTEST_PPS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_PPS_LEN
value|4
end_define

begin_comment
comment|/* Results of testing */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_MANFTEST_PPS_TEST_RESULT_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_PTP_OUT_MANFTEST_BASIC/TEST_RESULT */
end_comment

begin_comment
comment|/* MC_CMD_PTP_OUT_SET_SYNC_STATUS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PTP_OUT_SET_SYNC_STATUS_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_CSR_READ32  * Read 32bit words from the indirect memory map.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CSR_READ32
value|0xc
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xc_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xc_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Address */
end_comment

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

begin_comment
comment|/* The last dword is the status, not a value read */
end_comment

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
comment|/* MC_CMD_CSR_WRITE32  * Write 32bit dwords to the indirect memory map.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CSR_WRITE32
value|0xd
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xd_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xd_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Address */
end_comment

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
comment|/* MC_CMD_HP  * These commands are used for HP related features. They are grouped under one  * MCDI command to avoid creating too many MCDI commands.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP
value|0x54
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x54_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x54_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* HP OCSD sub-command. When address is not NULL, request activation of OCSD at  * the specified address with the specified interval.When address is NULL,  * INTERVAL is interpreted as a command: 0: stop OCSD / 1: Report OCSD current  * state / 2: (debug) Show temperature reported by one of the supported  * sensors.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_SUBCMD_OFST
value|0
end_define

begin_comment
comment|/* enum: OCSD (Option Card Sensor Data) sub-command. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_OCSD_SUBCMD
value|0x0
end_define

begin_comment
comment|/* enum: Last known valid HP sub-command. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_IN_LAST_SUBCMD
value|0x0
end_define

begin_comment
comment|/* The address to the array of sensor fields. (Or NULL to use a sub-command.)  */
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

begin_comment
comment|/* The requested update interval, in seconds. (Or the sub-command if ADDR is  * NULL.)  */
end_comment

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

begin_comment
comment|/* enum: OCSD stopped for this card. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_OUT_OCSD_STOPPED
value|0x1
end_define

begin_comment
comment|/* enum: OCSD was successfully started with the address provided. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_OUT_OCSD_STARTED
value|0x2
end_define

begin_comment
comment|/* enum: OCSD was already started for this card. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_HP_OUT_OCSD_ALREADY_STARTED
value|0x3
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_STACKINFO  * Get stack information.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_STACKINFO
value|0xf
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xf_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xf_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* (thread ptr, stack size, free space) for each thread in system */
end_comment

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
comment|/* MC_CMD_MDIO_READ  * MDIO register read.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ
value|0x10
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x10_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x10_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* Bus number; there are two MDIO buses: one for the internal PHY, and one for  * external devices.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_IN_BUS_OFST
value|0
end_define

begin_comment
comment|/* enum: Internal. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_BUS_INTERNAL
value|0x0
end_define

begin_comment
comment|/* enum: External. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_BUS_EXTERNAL
value|0x1
end_define

begin_comment
comment|/* Port address */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_IN_PRTAD_OFST
value|4
end_define

begin_comment
comment|/* Device Address or clause 22. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_IN_DEVAD_OFST
value|8
end_define

begin_comment
comment|/* enum: By default all the MCDI MDIO operations perform clause45 mode. If you  * want to use clause22 then set DEVAD = MC_CMD_MDIO_CLAUSE22.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_CLAUSE22
value|0x20
end_define

begin_comment
comment|/* Address */
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

begin_comment
comment|/* Value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_OUT_VALUE_OFST
value|0
end_define

begin_comment
comment|/* Status the MDIO commands return the raw status bits from the MDIO block. A  * "good" transaction should have the DONE bit set and all other bits clear.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_READ_OUT_STATUS_OFST
value|4
end_define

begin_comment
comment|/* enum: Good. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_STATUS_GOOD
value|0x8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_MDIO_WRITE  * MDIO register write.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE
value|0x11
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x11_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x11_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Bus number; there are two MDIO buses: one for the internal PHY, and one for  * external devices.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_IN_BUS_OFST
value|0
end_define

begin_comment
comment|/* enum: Internal. */
end_comment

begin_comment
comment|/*               MC_CMD_MDIO_BUS_INTERNAL 0x0 */
end_comment

begin_comment
comment|/* enum: External. */
end_comment

begin_comment
comment|/*               MC_CMD_MDIO_BUS_EXTERNAL 0x1 */
end_comment

begin_comment
comment|/* Port address */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_IN_PRTAD_OFST
value|4
end_define

begin_comment
comment|/* Device Address or clause 22. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_IN_DEVAD_OFST
value|8
end_define

begin_comment
comment|/* enum: By default all the MCDI MDIO operations perform clause45 mode. If you  * want to use clause22 then set DEVAD = MC_CMD_MDIO_CLAUSE22.  */
end_comment

begin_comment
comment|/*               MC_CMD_MDIO_CLAUSE22 0x20 */
end_comment

begin_comment
comment|/* Address */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_IN_ADDR_OFST
value|12
end_define

begin_comment
comment|/* Value */
end_comment

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

begin_comment
comment|/* Status; the MDIO commands return the raw status bits from the MDIO block. A  * "good" transaction should have the DONE bit set and all other bits clear.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MDIO_WRITE_OUT_STATUS_OFST
value|0
end_define

begin_comment
comment|/* enum: Good. */
end_comment

begin_comment
comment|/*               MC_CMD_MDIO_STATUS_GOOD 0x8 */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DBI_WRITE  * Write DBI register(s).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DBI_WRITE
value|0x12
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x12_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x12_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Each write op consists of an address (offset 0), byte enable/VF/CS2 (offset  * 32) and value (offset 64). See MC_CMD_DBIWROP_TYPEDEF.  */
end_comment

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
name|MC_CMD_DBIWROP_TYPEDEF_PARMS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_VF_NUM_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_VF_NUM_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_VF_ACTIVE_LBN
value|15
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_VF_ACTIVE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_CS2_LBN
value|14
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_CS2_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_PARMS_LBN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIWROP_TYPEDEF_PARMS_WIDTH
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
comment|/* MC_CMD_PORT_READ32  * Read a 32-bit register from the indirect port register map. The port to  * access is implied by the Shared memory channel used.  */
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

begin_comment
comment|/* Address */
end_comment

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

begin_comment
comment|/* Value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_READ32_OUT_VALUE_OFST
value|0
end_define

begin_comment
comment|/* Status */
end_comment

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
comment|/* MC_CMD_PORT_WRITE32  * Write a 32-bit register to the indirect port register map. The port to  * access is implied by the Shared memory channel used.  */
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

begin_comment
comment|/* Address */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE32_IN_ADDR_OFST
value|0
end_define

begin_comment
comment|/* Value */
end_comment

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

begin_comment
comment|/* Status */
end_comment

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
comment|/* MC_CMD_PORT_READ128  * Read a 128-bit register from the indirect port register map. The port to  * access is implied by the Shared memory channel used.  */
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

begin_comment
comment|/* Address */
end_comment

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

begin_comment
comment|/* Value */
end_comment

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

begin_comment
comment|/* Status */
end_comment

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
comment|/* MC_CMD_PORT_WRITE128  * Write a 128-bit register to the indirect port register map. The port to  * access is implied by the Shared memory channel used.  */
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

begin_comment
comment|/* Address */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE128_IN_ADDR_OFST
value|0
end_define

begin_comment
comment|/* Value */
end_comment

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

begin_comment
comment|/* Status */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_WRITE128_OUT_STATUS_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_CAPABILITIES structuredef */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_LEN
value|4
end_define

begin_comment
comment|/* Small buf table. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_SMALL_BUF_TBL_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_SMALL_BUF_TBL_WIDTH
value|1
end_define

begin_comment
comment|/* Turbo mode (for Maranello). */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_TURBO_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_TURBO_WIDTH
value|1
end_define

begin_comment
comment|/* Turbo mode active (for Maranello). */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_TURBO_ACTIVE_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_TURBO_ACTIVE_WIDTH
value|1
end_define

begin_comment
comment|/* PTP offload. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_PTP_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_PTP_WIDTH
value|1
end_define

begin_comment
comment|/* AOE mode. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_AOE_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_AOE_WIDTH
value|1
end_define

begin_comment
comment|/* AOE mode active. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_AOE_ACTIVE_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_AOE_ACTIVE_WIDTH
value|1
end_define

begin_comment
comment|/* AOE mode active. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_FC_ACTIVE_LBN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_FC_ACTIVE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_RESERVED_LBN
value|7
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAPABILITIES_RESERVED_WIDTH
value|25
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_BOARD_CFG  * Returns the MC firmware configuration structure.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG
value|0x18
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x18_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x18_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* See MC_CMD_CAPABILITIES */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_CAPABILITIES_PORT0_OFST
value|36
end_define

begin_comment
comment|/* See MC_CMD_CAPABILITIES */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_BOARD_CFG_OUT_CAPABILITIES_PORT1_OFST
value|40
end_define

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

begin_comment
comment|/* This field contains a 16-bit value for each of the types of NVRAM area. The  * values are defined in the firmware/mc/platform/.c file for a specific board  * type, but otherwise have no meaning to the MC; they are used by the driver  * to manage selection of appropriate firmware updates.  */
end_comment

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
comment|/* MC_CMD_DBI_READX  * Read DBI register(s) -- extended functionality  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DBI_READX
value|0x19
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x19_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x19_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Each Read op consists of an address (offset 0), VF/CS2) */
end_comment

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

begin_comment
comment|/* Value */
end_comment

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
comment|/* MC_CMD_DBIRDOP_TYPEDEF structuredef */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_ADDRESS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_ADDRESS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_ADDRESS_WIDTH
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_PARMS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_VF_NUM_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_VF_NUM_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_VF_ACTIVE_LBN
value|15
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_VF_ACTIVE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_CS2_LBN
value|14
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_CS2_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_PARMS_LBN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DBIRDOP_TYPEDEF_PARMS_WIDTH
value|32
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_RAND_SEED  * Set the 16byte seed for the MC pseudo-random generator.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_RAND_SEED
value|0x1a
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x1a_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x1a_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Seed value. */
end_comment

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
comment|/* MC_CMD_LTSSM_HIST  * Retrieve the history of the LTSSM, if the build supports it.  */
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

begin_comment
comment|/* variable number of LTSSM values, as bytes. The history is read-to-clear. */
end_comment

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
comment|/* MC_CMD_DRV_ATTACH  * Inform MCPU that this port is managed on the host (i.e. driver active). For  * Huntington, also request the preferred datapath firmware to use if possible  * (it may not be possible for this request to be fulfilled; the driver must  * issue a subsequent MC_CMD_GET_CAPABILITIES command to determine which  * features are actually available). The FIRMWARE_ID field is ignored by older  * platforms.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH
value|0x1c
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x1c_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x1c_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_DRV_ATTACH_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_IN_LEN
value|12
end_define

begin_comment
comment|/* new state (0=detached, 1=attached) to set if UPDATE=1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_IN_NEW_STATE_OFST
value|0
end_define

begin_comment
comment|/* 1 to set new state, or 0 to just report the existing state */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_IN_UPDATE_OFST
value|4
end_define

begin_comment
comment|/* preferred datapath firmware (for Huntington; ignored for Siena) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_IN_FIRMWARE_ID_OFST
value|8
end_define

begin_comment
comment|/* enum: Prefer to use full featured firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FW_FULL_FEATURED
value|0x0
end_define

begin_comment
comment|/* enum: Prefer to use firmware with fewer features but lower latency */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FW_LOW_LATENCY
value|0x1
end_define

begin_comment
comment|/* enum: Prefer to use firmware for SolarCapture packed stream mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FW_PACKED_STREAM
value|0x2
end_define

begin_comment
comment|/* enum: Prefer to use firmware with fewer features and simpler TX event  * batching but higher TX packet rate  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FW_HIGH_TX_RATE
value|0x3
end_define

begin_comment
comment|/* enum: Reserved value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FW_PACKED_STREAM_HASH_MODE_1
value|0x4
end_define

begin_comment
comment|/* enum: Only this option is allowed for non-admin functions */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FW_DONT_CARE
value|0xffffffff
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

begin_comment
comment|/* previous or existing state (0=detached, 1=attached) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_OUT_OLD_STATE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_DRV_ATTACH_EXT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_EXT_OUT_LEN
value|8
end_define

begin_comment
comment|/* previous or existing state (0=detached, 1=attached) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_EXT_OUT_OLD_STATE_OFST
value|0
end_define

begin_comment
comment|/* Flags associated with this function */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_EXT_OUT_FUNC_FLAGS_OFST
value|4
end_define

begin_comment
comment|/* enum: Labels the lowest-numbered function visible to the OS */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_EXT_OUT_FLAG_PRIMARY
value|0x0
end_define

begin_comment
comment|/* enum: The function can control the link state of the physical port it is  * bound to.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_EXT_OUT_FLAG_LINKCTRL
value|0x1
end_define

begin_comment
comment|/* enum: The function can perform privileged operations */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRV_ATTACH_EXT_OUT_FLAG_TRUSTED
value|0x2
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SHMUART  * Route UART output to circular buffer in shared memory instead.  */
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

begin_comment
comment|/* ??? */
end_comment

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
comment|/* MC_CMD_PORT_RESET  * Generic per-port reset. There is no equivalent for per-board reset. Locks  * required: None; Return code: 0, ETIME. NOTE: This command is deprecated -  * use MC_CMD_ENTITY_RESET instead.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_RESET
value|0x20
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x20_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x20_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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
comment|/* MC_CMD_ENTITY_RESET  * Generic per-resource reset. There is no equivalent for per-board reset.  * Locks required: None; Return code: 0, ETIME. NOTE: This command is an  * extended version of the deprecated MC_CMD_PORT_RESET with added fields.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ENTITY_RESET
value|0x20
end_define

begin_comment
comment|/*      MC_CMD_0x20_PRIVILEGE_CTG SRIOV_CTG_GENERAL */
end_comment

begin_comment
comment|/* MC_CMD_ENTITY_RESET_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ENTITY_RESET_IN_LEN
value|4
end_define

begin_comment
comment|/* Optional flags field. Omitting this will perform a "legacy" reset action  * (TBD).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ENTITY_RESET_IN_FLAG_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_ENTITY_RESET_IN_FUNCTION_RESOURCE_RESET_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_ENTITY_RESET_IN_FUNCTION_RESOURCE_RESET_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_ENTITY_RESET_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ENTITY_RESET_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PCIE_CREDITS  * Read instantaneous and minimum flow control thresholds.  */
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

begin_comment
comment|/* poll period. 0 is disabled */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_CREDITS_IN_POLL_PERIOD_OFST
value|0
end_define

begin_comment
comment|/* wipe statistics */
end_comment

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
comment|/* MC_CMD_RXD_MONITOR  * Get histogram of RX queue fill level.  */
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
comment|/* MC_CMD_PUTS  * Copy the given ASCII string out onto UART and/or out of the network port.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PUTS
value|0x23
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x23_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x23_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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
comment|/* MC_CMD_GET_PHY_CFG  * Report PHY configuration. This guarantees to succeed even if the PHY is in a  * 'zombie' state. Locks required: None  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG
value|0x24
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x24_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x24_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* flags */
end_comment

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

begin_comment
comment|/* ?? */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_TYPE_OFST
value|4
end_define

begin_comment
comment|/* Bitmask of supported capabilities */
end_comment

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
name|MC_CMD_PHY_CAP_40000FDX_LBN
value|11
end_define

begin_define
define|#
directive|define
name|MC_CMD_PHY_CAP_40000FDX_WIDTH
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

begin_comment
comment|/* ?? */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_CHANNEL_OFST
value|12
end_define

begin_comment
comment|/* ?? */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_PRT_OFST
value|16
end_define

begin_comment
comment|/* ?? */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_STATS_MASK_OFST
value|20
end_define

begin_comment
comment|/* ?? */
end_comment

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

begin_comment
comment|/* ?? */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_MEDIA_TYPE_OFST
value|44
end_define

begin_comment
comment|/* enum: Xaui. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_XAUI
value|0x1
end_define

begin_comment
comment|/* enum: CX4. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_CX4
value|0x2
end_define

begin_comment
comment|/* enum: KX4. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_KX4
value|0x3
end_define

begin_comment
comment|/* enum: XFP Far. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_XFP
value|0x4
end_define

begin_comment
comment|/* enum: SFP+. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_SFP_PLUS
value|0x5
end_define

begin_comment
comment|/* enum: 10GBaseT. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_BASE_T
value|0x6
end_define

begin_comment
comment|/* enum: QSFP+. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MEDIA_QSFP_PLUS
value|0x7
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_CFG_OUT_MMD_MASK_OFST
value|48
end_define

begin_comment
comment|/* enum: Native clause 22 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE22
value|0x0
end_define

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

begin_comment
comment|/* enum: Clause22 proxied over clause45 by PHY. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MMD_CLAUSE45_C22EXT
value|0x1d
end_define

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
comment|/* MC_CMD_START_BIST  * Start a BIST test on the PHY. Locks required: PHY_LOCK if doing a PHY BIST  * Return code: 0, EINVAL, EACCES (if PHY_LOCK is not held)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_START_BIST
value|0x25
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x25_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x25_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Type of test. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_START_BIST_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/* enum: Run the PHY's short cable BIST. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_BIST_CABLE_SHORT
value|0x1
end_define

begin_comment
comment|/* enum: Run the PHY's long cable BIST. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_BIST_CABLE_LONG
value|0x2
end_define

begin_comment
comment|/* enum: Run BIST on the currently selected BPX Serdes (XAUI or XFI) . */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_BPX_SERDES_BIST
value|0x3
end_define

begin_comment
comment|/* enum: Run the MC loopback tests. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MC_LOOPBACK_BIST
value|0x4
end_define

begin_comment
comment|/* enum: Run the PHY's standard BIST. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_BIST
value|0x5
end_define

begin_comment
comment|/* enum: Run MC RAM test. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MC_MEM_BIST
value|0x6
end_define

begin_comment
comment|/* enum: Run Port RAM test. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PORT_MEM_BIST
value|0x7
end_define

begin_comment
comment|/* enum: Run register test. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REG_BIST
value|0x8
end_define

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
comment|/* MC_CMD_POLL_BIST  * Poll for BIST completion. Returns a single status code, and optionally some  * PHY specific bist output. The driver should only consume the BIST output  * after validating OUTLEN and MC_CMD_GET_PHY_CFG.TYPE. If a driver can't  * successfully parse the BIST output, it should still respect the pass/Fail in  * OUT.RESULT. Locks required: PHY_LOCK if doing a PHY BIST. Return code: 0,  * EACCES (if PHY_LOCK is not held).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST
value|0x26
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x26_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x26_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* result */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_RESULT_OFST
value|0
end_define

begin_comment
comment|/* enum: Running. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_RUNNING
value|0x1
end_define

begin_comment
comment|/* enum: Passed. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_PASSED
value|0x2
end_define

begin_comment
comment|/* enum: Failed. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_FAILED
value|0x3
end_define

begin_comment
comment|/* enum: Timed-out. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_TIMEOUT
value|0x4
end_define

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
comment|/* result */
end_comment

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

begin_comment
comment|/* Status of each channel A */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_SFT9001_CABLE_STATUS_A_OFST
value|20
end_define

begin_comment
comment|/* enum: Ok. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_SFT9001_PAIR_OK
value|0x1
end_define

begin_comment
comment|/* enum: Open. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_SFT9001_PAIR_OPEN
value|0x2
end_define

begin_comment
comment|/* enum: Intra-pair short. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_SFT9001_INTRA_PAIR_SHORT
value|0x3
end_define

begin_comment
comment|/* enum: Inter-pair short. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_SFT9001_INTER_PAIR_SHORT
value|0x4
end_define

begin_comment
comment|/* enum: Busy. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_SFT9001_PAIR_BUSY
value|0x9
end_define

begin_comment
comment|/* Status of each channel B */
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

begin_comment
comment|/* Status of each channel C */
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

begin_comment
comment|/* Status of each channel D */
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
comment|/* result */
end_comment

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

begin_comment
comment|/* enum: Complete. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_COMPLETE
value|0x0
end_define

begin_comment
comment|/* enum: Bus switch off I2C write. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_BUS_SWITCH_OFF_I2C_WRITE
value|0x1
end_define

begin_comment
comment|/* enum: Bus switch off I2C no access IO exp. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_BUS_SWITCH_OFF_I2C_NO_ACCESS_IO_EXP
value|0x2
end_define

begin_comment
comment|/* enum: Bus switch off I2C no access module. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_BUS_SWITCH_OFF_I2C_NO_ACCESS_MODULE
value|0x3
end_define

begin_comment
comment|/* enum: IO exp I2C configure. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_IO_EXP_I2C_CONFIGURE
value|0x4
end_define

begin_comment
comment|/* enum: Bus switch I2C no cross talk. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_BUS_SWITCH_I2C_NO_CROSSTALK
value|0x5
end_define

begin_comment
comment|/* enum: Module presence. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_MODULE_PRESENCE
value|0x6
end_define

begin_comment
comment|/* enum: Module ID I2C access. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_MODULE_ID_I2C_ACCESS
value|0x7
end_define

begin_comment
comment|/* enum: Module ID sane value. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MRSFP_TEST_MODULE_ID_SANE_VALUE
value|0x8
end_define

begin_comment
comment|/* MC_CMD_POLL_BIST_OUT_MEM msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_MEM_LEN
value|36
end_define

begin_comment
comment|/* result */
end_comment

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
name|MC_CMD_POLL_BIST_OUT_MEM_TEST_OFST
value|4
end_define

begin_comment
comment|/* enum: Test has completed. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_COMPLETE
value|0x0
end_define

begin_comment
comment|/* enum: RAM test - walk ones. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_MEM_WALK_ONES
value|0x1
end_define

begin_comment
comment|/* enum: RAM test - walk zeros. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_MEM_WALK_ZEROS
value|0x2
end_define

begin_comment
comment|/* enum: RAM test - walking inversions zeros/ones. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_MEM_INV_ZERO_ONE
value|0x3
end_define

begin_comment
comment|/* enum: RAM test - walking inversions checkerboard. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_MEM_INV_CHKBOARD
value|0x4
end_define

begin_comment
comment|/* enum: Register test - set / clear individual bits. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_REG
value|0x5
end_define

begin_comment
comment|/* enum: ECC error detected. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_ECC
value|0x6
end_define

begin_comment
comment|/* Failure address, only valid if result is POLL_BIST_FAILED */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_MEM_ADDR_OFST
value|8
end_define

begin_comment
comment|/* Bus or address space to which the failure address corresponds */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_MEM_BUS_OFST
value|12
end_define

begin_comment
comment|/* enum: MC MIPS bus. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_BUS_MC
value|0x0
end_define

begin_comment
comment|/* enum: CSR IREG bus. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_BUS_CSR
value|0x1
end_define

begin_comment
comment|/* enum: RX DPCPU bus. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_BUS_DPCPU_RX
value|0x2
end_define

begin_comment
comment|/* enum: TX0 DPCPU bus. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_BUS_DPCPU_TX0
value|0x3
end_define

begin_comment
comment|/* enum: TX1 DPCPU bus. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_BUS_DPCPU_TX1
value|0x4
end_define

begin_comment
comment|/* enum: RX DICPU bus. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_BUS_DICPU_RX
value|0x5
end_define

begin_comment
comment|/* enum: TX DICPU bus. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_MEM_BUS_DICPU_TX
value|0x6
end_define

begin_comment
comment|/* Pattern written to RAM / register */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_MEM_EXPECT_OFST
value|16
end_define

begin_comment
comment|/* Actual value read from RAM / register */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_MEM_ACTUAL_OFST
value|20
end_define

begin_comment
comment|/* ECC error mask */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_MEM_ECC_OFST
value|24
end_define

begin_comment
comment|/* ECC parity error mask */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_MEM_ECC_PARITY_OFST
value|28
end_define

begin_comment
comment|/* ECC fatal error mask */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_POLL_BIST_OUT_MEM_ECC_FATAL_OFST
value|32
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FLUSH_RX_QUEUES  * Flush receive queue(s). If SRIOV is enabled (via MC_CMD_SRIOV), then RXQ  * flushes should be initiated via this MCDI operation, rather than via  * directly writing FLUSH_CMD.  *  * The flush is completed (either done/fail) asynchronously (after this command  * returns). The driver must still wait for flush done/failure events as usual.  */
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
comment|/* MC_CMD_GET_LOOPBACK_MODES  * Returns a bitmask of loopback modes available at each speed.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES
value|0x28
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x28_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x28_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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
value|40
end_define

begin_comment
comment|/* Supported loopbacks. */
end_comment

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

begin_comment
comment|/* enum: None. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_NONE
value|0x0
end_define

begin_comment
comment|/* enum: Data. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_DATA
value|0x1
end_define

begin_comment
comment|/* enum: GMAC. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_GMAC
value|0x2
end_define

begin_comment
comment|/* enum: XGMII. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XGMII
value|0x3
end_define

begin_comment
comment|/* enum: XGXS. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XGXS
value|0x4
end_define

begin_comment
comment|/* enum: XAUI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XAUI
value|0x5
end_define

begin_comment
comment|/* enum: GMII. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_GMII
value|0x6
end_define

begin_comment
comment|/* enum: SGMII. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_SGMII
value|0x7
end_define

begin_comment
comment|/* enum: XGBR. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XGBR
value|0x8
end_define

begin_comment
comment|/* enum: XFI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XFI
value|0x9
end_define

begin_comment
comment|/* enum: XAUI Far. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XAUI_FAR
value|0xa
end_define

begin_comment
comment|/* enum: GMII Far. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_GMII_FAR
value|0xb
end_define

begin_comment
comment|/* enum: SGMII Far. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_SGMII_FAR
value|0xc
end_define

begin_comment
comment|/* enum: XFI Far. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XFI_FAR
value|0xd
end_define

begin_comment
comment|/* enum: GPhy. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_GPHY
value|0xe
end_define

begin_comment
comment|/* enum: PhyXS. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_PHYXS
value|0xf
end_define

begin_comment
comment|/* enum: PCS. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_PCS
value|0x10
end_define

begin_comment
comment|/* enum: PMA-PMD. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_PMAPMD
value|0x11
end_define

begin_comment
comment|/* enum: Cross-Port. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XPORT
value|0x12
end_define

begin_comment
comment|/* enum: XGMII-Wireside. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XGMII_WS
value|0x13
end_define

begin_comment
comment|/* enum: XAUI Wireside. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XAUI_WS
value|0x14
end_define

begin_comment
comment|/* enum: XAUI Wireside Far. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XAUI_WS_FAR
value|0x15
end_define

begin_comment
comment|/* enum: XAUI Wireside near. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XAUI_WS_NEAR
value|0x16
end_define

begin_comment
comment|/* enum: GMII Wireside. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_GMII_WS
value|0x17
end_define

begin_comment
comment|/* enum: XFI Wireside. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XFI_WS
value|0x18
end_define

begin_comment
comment|/* enum: XFI Wireside Far. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_XFI_WS_FAR
value|0x19
end_define

begin_comment
comment|/* enum: PhyXS Wireside. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_PHYXS_WS
value|0x1a
end_define

begin_comment
comment|/* enum: PMA lanes MAC-Serdes. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_PMA_INT
value|0x1b
end_define

begin_comment
comment|/* enum: KR Serdes Parallel (Encoder). */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_SD_NEAR
value|0x1c
end_define

begin_comment
comment|/* enum: KR Serdes Serial. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_SD_FAR
value|0x1d
end_define

begin_comment
comment|/* enum: PMA lanes MAC-Serdes Wireside. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_PMA_INT_WS
value|0x1e
end_define

begin_comment
comment|/* enum: KR Serdes Parallel Wireside (Full PCS). */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_SD_FEP2_WS
value|0x1f
end_define

begin_comment
comment|/* enum: KR Serdes Parallel Wireside (Sym Aligner to TX). */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_SD_FEP1_5_WS
value|0x20
end_define

begin_comment
comment|/* enum: KR Serdes Parallel Wireside (Deserializer to Serializer). */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_SD_FEP_WS
value|0x21
end_define

begin_comment
comment|/* enum: KR Serdes Serial Wireside. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_SD_FES_WS
value|0x22
end_define

begin_comment
comment|/* enum: Near side of AOE Siena side port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_AOE_INT_NEAR
value|0x23
end_define

begin_comment
comment|/* enum: Medford Wireside datapath loopback */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_DATA_WS
value|0x24
end_define

begin_comment
comment|/* enum: Force link up without setting up any physical loopback (snapper use  * only)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LOOPBACK_FORCE_EXT_LINK
value|0x25
end_define

begin_comment
comment|/* Supported loopbacks. */
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

begin_comment
comment|/* Supported loopbacks. */
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

begin_comment
comment|/* Supported loopbacks. */
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
comment|/* Supported loopbacks. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_40G_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_40G_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_40G_LO_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_LOOPBACK_MODES_OUT_40G_HI_OFST
value|36
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
comment|/* MC_CMD_GET_LINK  * Read the unified MAC/PHY link state. Locks required: None Return code: 0,  * ETIME.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK
value|0x29
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x29_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x29_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* near-side advertised capabilities */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_CAP_OFST
value|0
end_define

begin_comment
comment|/* link-partner advertised capabilities */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LP_CAP_OFST
value|4
end_define

begin_comment
comment|/* Autonegotiated speed in mbit/s. The link may still be down even if this  * reads non-zero.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_LINK_SPEED_OFST
value|8
end_define

begin_comment
comment|/* Current loopback setting. */
end_comment

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

begin_comment
comment|/* This returns the negotiated flow control value. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LINK_OUT_FCNTL_OFST
value|20
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_SET_MAC/MC_CMD_SET_MAC_IN/FCNTL */
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
comment|/* MC_CMD_SET_LINK  * Write the unified MAC/PHY link configuration. Locks required: None. Return  * code: 0, EINVAL, ETIME  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK
value|0x2a
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x2a_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x2a_PRIVILEGE_CTG
value|SRIOV_CTG_LINK
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

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_LINK_IN_CAP_OFST
value|0
end_define

begin_comment
comment|/* Flags */
end_comment

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

begin_comment
comment|/* Loopback mode. */
end_comment

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

begin_comment
comment|/* A loopback speed of "0" is supported, and means (choose any available  * speed).  */
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
comment|/* MC_CMD_SET_ID_LED  * Set identification LED state. Locks required: None. Return code: 0, EINVAL  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_ID_LED
value|0x2b
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x2b_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x2b_PRIVILEGE_CTG
value|SRIOV_CTG_LINK
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

begin_comment
comment|/* Set LED state. */
end_comment

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
comment|/* MC_CMD_SET_MAC  * Set MAC configuration. Locks required: None. Return code: 0, EINVAL  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC
value|0x2c
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x2c_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x2c_PRIVILEGE_CTG
value|SRIOV_CTG_LINK
end_define

begin_comment
comment|/* MC_CMD_SET_MAC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_LEN
value|28
end_define

begin_comment
comment|/* The MTU is the MTU programmed directly into the XMAC/GMAC (inclusive of  * EtherII, VLAN, bug16011 padding).  */
end_comment

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
comment|/* enum: Flow control is off. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FCNTL_OFF
value|0x0
end_define

begin_comment
comment|/* enum: Respond to flow control. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FCNTL_RESPOND
value|0x1
end_define

begin_comment
comment|/* enum: Respond to and Issue flow control. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FCNTL_BIDIR
value|0x2
end_define

begin_comment
comment|/* enum: Auto neg flow control. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FCNTL_AUTO
value|0x3
end_define

begin_comment
comment|/* enum: Priority flow control (eftest builds only). */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FCNTL_QBB
value|0x4
end_define

begin_comment
comment|/* enum: Issue flow control. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FCNTL_GENERATE
value|0x5
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_FLAGS_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_FLAG_INCLUDE_FCS_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_MAC_IN_FLAG_INCLUDE_FCS_WIDTH
value|1
end_define

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
comment|/* MC_CMD_PHY_STATS  * Get generic PHY statistics. This call returns the statistics for a generic  * PHY in a sparse array (indexed by the enumerate). Each value is represented  * by a 32bit number. If the DMA_ADDR is 0, then no DMA is performed, and the  * statistics may be read from the message response. If DMA_ADDR != 0, then the  * statistics are dmad to that (page-aligned location). Locks required: None.  * Returns: 0, ETIME  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATS
value|0x2d
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x2d_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x2d_PRIVILEGE_CTG
value|SRIOV_CTG_LINK
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

begin_comment
comment|/* ??? */
end_comment

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

begin_comment
comment|/* enum: OUI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_OUI
value|0x0
end_define

begin_comment
comment|/* enum: PMA-PMD Link Up. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_LINK_UP
value|0x1
end_define

begin_comment
comment|/* enum: PMA-PMD RX Fault. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_RX_FAULT
value|0x2
end_define

begin_comment
comment|/* enum: PMA-PMD TX Fault. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_TX_FAULT
value|0x3
end_define

begin_comment
comment|/* enum: PMA-PMD Signal */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_SIGNAL
value|0x4
end_define

begin_comment
comment|/* enum: PMA-PMD SNR A. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_SNR_A
value|0x5
end_define

begin_comment
comment|/* enum: PMA-PMD SNR B. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_SNR_B
value|0x6
end_define

begin_comment
comment|/* enum: PMA-PMD SNR C. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_SNR_C
value|0x7
end_define

begin_comment
comment|/* enum: PMA-PMD SNR D. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PMA_PMD_SNR_D
value|0x8
end_define

begin_comment
comment|/* enum: PCS Link Up. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCS_LINK_UP
value|0x9
end_define

begin_comment
comment|/* enum: PCS RX Fault. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCS_RX_FAULT
value|0xa
end_define

begin_comment
comment|/* enum: PCS TX Fault. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCS_TX_FAULT
value|0xb
end_define

begin_comment
comment|/* enum: PCS BER. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCS_BER
value|0xc
end_define

begin_comment
comment|/* enum: PCS Block Errors. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCS_BLOCK_ERRORS
value|0xd
end_define

begin_comment
comment|/* enum: PhyXS Link Up. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHYXS_LINK_UP
value|0xe
end_define

begin_comment
comment|/* enum: PhyXS RX Fault. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHYXS_RX_FAULT
value|0xf
end_define

begin_comment
comment|/* enum: PhyXS TX Fault. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHYXS_TX_FAULT
value|0x10
end_define

begin_comment
comment|/* enum: PhyXS Align. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHYXS_ALIGN
value|0x11
end_define

begin_comment
comment|/* enum: PhyXS Sync. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHYXS_SYNC
value|0x12
end_define

begin_comment
comment|/* enum: AN link-up. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AN_LINK_UP
value|0x13
end_define

begin_comment
comment|/* enum: AN Complete. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AN_COMPLETE
value|0x14
end_define

begin_comment
comment|/* enum: AN 10GBaseT Status. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_AN_10GBT_STATUS
value|0x15
end_define

begin_comment
comment|/* enum: Clause 22 Link-Up. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CL22_LINK_UP
value|0x16
end_define

begin_comment
comment|/* enum: (Last entry) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_NSTATS
value|0x17
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_MAC_STATS  * Get generic MAC statistics. This call returns unified statistics maintained  * by the MC as it switches between the GMAC and XMAC. The MC will write out  * all supported stats. The driver should zero initialise the buffer to  * guarantee consistent results. If the DMA_ADDR is 0, then no DMA is  * performed, and the statistics may be read from the message response. If  * DMA_ADDR != 0, then the statistics are dmad to that (page-aligned location).  * Locks required: None. The PERIODIC_CLEAR option is not used and now has no  * effect. Returns: 0, ETIME  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS
value|0x2e
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x2e_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x2e_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_MAC_STATS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_LEN
value|20
end_define

begin_comment
comment|/* ??? */
end_comment

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
comment|/* port id so vadapter stats can be provided */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_STATS_IN_PORT_ID_OFST
value|16
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
name|MC_CMD_MAC_DMABUF_START
value|0x1
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

begin_comment
comment|/* enum: PM trunc_bb_overflow counter. Valid for EF10 with PM_AND_RXDP_COUNTERS  * capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_PM_TRUNC_BB_OVERFLOW
value|0x3c
end_define

begin_comment
comment|/* enum: PM discard_bb_overflow counter. Valid for EF10 with  * PM_AND_RXDP_COUNTERS capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_PM_DISCARD_BB_OVERFLOW
value|0x3d
end_define

begin_comment
comment|/* enum: PM trunc_vfifo_full counter. Valid for EF10 with PM_AND_RXDP_COUNTERS  * capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_PM_TRUNC_VFIFO_FULL
value|0x3e
end_define

begin_comment
comment|/* enum: PM discard_vfifo_full counter. Valid for EF10 with  * PM_AND_RXDP_COUNTERS capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_PM_DISCARD_VFIFO_FULL
value|0x3f
end_define

begin_comment
comment|/* enum: PM trunc_qbb counter. Valid for EF10 with PM_AND_RXDP_COUNTERS  * capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_PM_TRUNC_QBB
value|0x40
end_define

begin_comment
comment|/* enum: PM discard_qbb counter. Valid for EF10 with PM_AND_RXDP_COUNTERS  * capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_PM_DISCARD_QBB
value|0x41
end_define

begin_comment
comment|/* enum: PM discard_mapping counter. Valid for EF10 with PM_AND_RXDP_COUNTERS  * capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_PM_DISCARD_MAPPING
value|0x42
end_define

begin_comment
comment|/* enum: RXDP counter: Number of packets dropped due to the queue being  * disabled. Valid for EF10 with PM_AND_RXDP_COUNTERS capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RXDP_Q_DISABLED_PKTS
value|0x43
end_define

begin_comment
comment|/* enum: RXDP counter: Number of packets dropped by the DICPU. Valid for EF10  * with PM_AND_RXDP_COUNTERS capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RXDP_DI_DROPPED_PKTS
value|0x45
end_define

begin_comment
comment|/* enum: RXDP counter: Number of non-host packets. Valid for EF10 with  * PM_AND_RXDP_COUNTERS capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RXDP_STREAMING_PKTS
value|0x46
end_define

begin_comment
comment|/* enum: RXDP counter: Number of times an hlb descriptor fetch was performed.  * Valid for EF10 with PM_AND_RXDP_COUNTERS capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RXDP_HLB_FETCH_CONDITIONS
value|0x47
end_define

begin_comment
comment|/* enum: RXDP counter: Number of times the DPCPU waited for an existing  * descriptor fetch. Valid for EF10 with PM_AND_RXDP_COUNTERS capability only.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_RXDP_HLB_WAIT_CONDITIONS
value|0x48
end_define

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_RX_DMABUF_START
value|0x4c
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_RX_UNICAST_PACKETS
value|0x4c
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_RX_UNICAST_BYTES
value|0x4d
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_RX_MULTICAST_PACKETS
value|0x4e
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_RX_MULTICAST_BYTES
value|0x4f
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_RX_BROADCAST_PACKETS
value|0x50
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_RX_BROADCAST_BYTES
value|0x51
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_RX_BAD_PACKETS
value|0x52
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_RX_BAD_BYTES
value|0x53
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_RX_OVERFLOW
value|0x54
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_TX_DMABUF_START
value|0x57
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_TX_UNICAST_PACKETS
value|0x57
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_TX_UNICAST_BYTES
value|0x58
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_TX_MULTICAST_PACKETS
value|0x59
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_TX_MULTICAST_BYTES
value|0x5a
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_TX_BROADCAST_PACKETS
value|0x5b
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_TX_BROADCAST_BYTES
value|0x5c
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_TX_BAD_PACKETS
value|0x5d
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_TX_BAD_BYTES
value|0x5e
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MAC_VADAPTER_TX_OVERFLOW
value|0x5f
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* enum: Start of GMAC stats buffer space, for Siena only. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GMAC_DMABUF_START
value|0x40
end_define

begin_comment
comment|/* enum: End of GMAC stats buffer space, for Siena only. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GMAC_DMABUF_END
value|0x5f
end_define

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
comment|/* MC_CMD_SRIOV  * to be documented  */
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

begin_comment
comment|/* this is only used for the first record */
end_comment

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
comment|/* MC_CMD_MEMCPY  * DMA write data into (Rid,Addr), either by dma reading (Rid,Addr), or by data  * embedded directly in the command.  *  * A common pattern is for a client to use generation counts to signal a dma  * update of a datastructure. To facilitate this, this MCDI operation can  * contain multiple requests which are executed in strict order. Requests take  * the form of duplicating the entire MCDI request continuously (including the  * requests record, which is ignored in all but the first structure)  *  * The source data can either come from a DMA from the host, or it can be  * embedded within the request directly, thereby eliminating a DMA read. To  * indicate this, the client sets FROM_RID=%RID_INLINE, ADDR_HI=0, and  * ADDR_LO=offset, and inserts the data at %offset from the start of the  * payload. It's the callers responsibility to ensure that the embedded data  * doesn't overlap the records.  *  * Returns: 0, EINVAL (invalid RID)  */
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

begin_comment
comment|/* see MC_CMD_MEMCPY_RECORD_TYPEDEF */
end_comment

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
comment|/* MC_CMD_WOL_FILTER_SET  * Set a WoL filter.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET
value|0x32
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x32_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x32_PRIVILEGE_CTG
value|SRIOV_CTG_LINK
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

begin_comment
comment|/* A type value of 1 is unused. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_SET_IN_WOL_TYPE_OFST
value|4
end_define

begin_comment
comment|/* enum: Magic */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_MAGIC
value|0x0
end_define

begin_comment
comment|/* enum: MS Windows Magic */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_WIN_MAGIC
value|0x2
end_define

begin_comment
comment|/* enum: IPv4 Syn */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_IPV4_SYN
value|0x3
end_define

begin_comment
comment|/* enum: IPv6 Syn */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_IPV6_SYN
value|0x4
end_define

begin_comment
comment|/* enum: Bitmap */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_BITMAP
value|0x5
end_define

begin_comment
comment|/* enum: Link */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_LINK
value|0x6
end_define

begin_comment
comment|/* enum: (Above this for future use) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_TYPE_MAX
value|0x7
end_define

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
comment|/* MC_CMD_WOL_FILTER_REMOVE  * Remove a WoL filter. Locks required: None. Returns: 0, EINVAL, ENOSYS  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_REMOVE
value|0x33
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x33_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x33_PRIVILEGE_CTG
value|SRIOV_CTG_LINK
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
comment|/* MC_CMD_WOL_FILTER_RESET  * Reset (i.e. remove all) WoL filters. Locks required: None. Returns: 0,  * ENOSYS  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_RESET
value|0x34
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x34_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x34_PRIVILEGE_CTG
value|SRIOV_CTG_LINK
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
comment|/* MC_CMD_SET_MCAST_HASH  * Set the MCAST hash value without otherwise reconfiguring the MAC  */
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
comment|/* MC_CMD_NVRAM_TYPES  * Return bitfield indicating available types of virtual NVRAM partitions.  * Locks required: none. Returns: 0  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPES
value|0x36
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x36_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x36_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Bit mask of supported types. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPES_OUT_TYPES_OFST
value|0
end_define

begin_comment
comment|/* enum: Disabled callisto. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_DISABLED_CALLISTO
value|0x0
end_define

begin_comment
comment|/* enum: MC firmware. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_MC_FW
value|0x1
end_define

begin_comment
comment|/* enum: MC backup firmware. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_MC_FW_BACKUP
value|0x2
end_define

begin_comment
comment|/* enum: Static configuration Port0. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_STATIC_CFG_PORT0
value|0x3
end_define

begin_comment
comment|/* enum: Static configuration Port1. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_STATIC_CFG_PORT1
value|0x4
end_define

begin_comment
comment|/* enum: Dynamic configuration Port0. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_DYNAMIC_CFG_PORT0
value|0x5
end_define

begin_comment
comment|/* enum: Dynamic configuration Port1. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_DYNAMIC_CFG_PORT1
value|0x6
end_define

begin_comment
comment|/* enum: Expansion Rom. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_EXP_ROM
value|0x7
end_define

begin_comment
comment|/* enum: Expansion Rom Configuration Port0. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_EXP_ROM_CFG_PORT0
value|0x8
end_define

begin_comment
comment|/* enum: Expansion Rom Configuration Port1. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_EXP_ROM_CFG_PORT1
value|0x9
end_define

begin_comment
comment|/* enum: Phy Configuration Port0. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_PHY_PORT0
value|0xa
end_define

begin_comment
comment|/* enum: Phy Configuration Port1. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_PHY_PORT1
value|0xb
end_define

begin_comment
comment|/* enum: Log. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_LOG
value|0xc
end_define

begin_comment
comment|/* enum: FPGA image. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FPGA
value|0xd
end_define

begin_comment
comment|/* enum: FPGA backup image */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FPGA_BACKUP
value|0xe
end_define

begin_comment
comment|/* enum: FC firmware. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FC_FW
value|0xf
end_define

begin_comment
comment|/* enum: FC backup firmware. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FC_FW_BACKUP
value|0x10
end_define

begin_comment
comment|/* enum: CPLD image. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_CPLD
value|0x11
end_define

begin_comment
comment|/* enum: Licensing information. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_LICENSE
value|0x12
end_define

begin_comment
comment|/* enum: FC Log. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FC_LOG
value|0x13
end_define

begin_comment
comment|/* enum: Additional flash on FPGA. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TYPE_FC_EXTRA
value|0x14
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_INFO  * Read info about a virtual NVRAM partition. Locks required: none. Returns: 0,  * EINVAL (bad type).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO
value|0x37
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x37_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x37_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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
name|MC_CMD_NVRAM_INFO_OUT_TLV_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_TLV_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_A_B_LBN
value|7
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_INFO_OUT_A_B_WIDTH
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
comment|/* MC_CMD_NVRAM_UPDATE_START  * Start a group of update operations on a virtual NVRAM partition. Locks  * required: PHY_LOCK if type==*PHY*. Returns: 0, EINVAL (bad type), EACCES (if  * PHY_LOCK required and not held).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_UPDATE_START
value|0x38
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x38_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x38_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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
comment|/* MC_CMD_NVRAM_READ  * Read data from a virtual NVRAM partition. Locks required: PHY_LOCK if  * type==*PHY*. Returns: 0, EINVAL (bad type/offset/length), EACCES (if  * PHY_LOCK required and not held)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_READ
value|0x39
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x39_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x39_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* amount to read in bytes */
end_comment

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
comment|/* MC_CMD_NVRAM_WRITE  * Write data to a virtual NVRAM partition. Locks required: PHY_LOCK if  * type==*PHY*. Returns: 0, EINVAL (bad type/offset/length), EACCES (if  * PHY_LOCK required and not held)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_WRITE
value|0x3a
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x3a_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x3a_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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
comment|/* MC_CMD_NVRAM_ERASE  * Erase sector(s) from a virtual NVRAM partition. Locks required: PHY_LOCK if  * type==*PHY*. Returns: 0, EINVAL (bad type/offset/length), EACCES (if  * PHY_LOCK required and not held)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_ERASE
value|0x3b
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x3b_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x3b_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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
comment|/* MC_CMD_NVRAM_UPDATE_FINISH  * Finish a group of update operations on a virtual NVRAM partition. Locks  * required: PHY_LOCK if type==*PHY*. Returns: 0, EINVAL (bad  * type/offset/length), EACCES (if PHY_LOCK required and not held)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_UPDATE_FINISH
value|0x3c
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x3c_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x3c_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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
comment|/* MC_CMD_REBOOT  * Reboot the MC.  *  * The AFTER_ASSERTION flag is intended to be used when the driver notices an  * assertion failure (at which point it is expected to perform a complete tear  * down and reinitialise), to allow both ports to reset the MC once in an  * atomic fashion.  *  * Production mc firmwares are generally compiled with REBOOT_ON_ASSERT=1,  * which means that they will automatically reboot out of the assertion  * handler, so this is in practise an optional operation. It is still  * recommended that drivers execute this to support custom firmwares with  * REBOOT_ON_ASSERT=0.  *  * Locks required: NONE Returns: Nothing. You get back a response with ERR=1,  * DATALEN=0  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT
value|0x3d
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x3d_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x3d_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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
comment|/* MC_CMD_SCHEDINFO  * Request scheduler info. Locks required: NONE. Returns: An array of  * (timeslice,maximum overrun), one for each thread, in ascending order of  * thread address.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SCHEDINFO
value|0x3e
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x3e_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x3e_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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
comment|/* MC_CMD_REBOOT_MODE  * Set the mode for the next MC reboot. Locks required: NONE. Sets the reboot  * mode to the specified value. Returns the old mode.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE
value|0x3f
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x3f_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x3f_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* enum: Normal. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_NORMAL
value|0x0
end_define

begin_comment
comment|/* enum: Power-on Reset. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_POR
value|0x2
end_define

begin_comment
comment|/* enum: Snapper. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_SNAPPER
value|0x3
end_define

begin_comment
comment|/* enum: snapper fake POR */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_SNAPPER_POR
value|0x4
end_define

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_IN_FAKE_LBN
value|7
end_define

begin_define
define|#
directive|define
name|MC_CMD_REBOOT_MODE_IN_FAKE_WIDTH
value|1
end_define

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
comment|/* MC_CMD_SENSOR_INFO  * Returns information about every available sensor.  *  * Each sensor has a single (16bit) value, and a corresponding state. The  * mapping between value and state is nominally determined by the MC, but may  * be implemented using up to 2 ranges per sensor.  *  * This call returns a mask (32bit) of the sensors that are supported by this  * platform, then an array of sensor information structures, in order of sensor  * type (but without gaps for unimplemented sensors). Each structure defines  * the ranges for the corresponding sensor. An unused range is indicated by  * equal limit values. If one range is used, a value outside that range results  * in STATE_FATAL. If two ranges are used, a value outside the second range  * results in STATE_FATAL while a value outside the first and inside the second  * range results in STATE_WARNING.  *  * Sensor masks and sensor information arrays are organised into pages. For  * backward compatibility, older host software can only use sensors in page 0.  * Bit 32 in the sensor mask was previously unused, and is no reserved for use  * as the next page flag.  *  * If the request does not contain a PAGE value then firmware will only return  * page 0 of sensor information, with bit 31 in the sensor mask cleared.  *  * If the request contains a PAGE value then firmware responds with the sensor  * mask and sensor information array for that page of sensors. In this case bit  * 31 in the mask is set if another page exists.  *  * Locks required: None Returns: 0  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO
value|0x41
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x41_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x41_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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
comment|/* MC_CMD_SENSOR_INFO_EXT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_EXT_IN_LEN
value|4
end_define

begin_comment
comment|/* Which page of sensors to report.  *  * Page 0 contains sensors 0 to 30 (sensor 31 is the next page bit).  *  * Page 1 contains sensors 32 to 62 (sensor 63 is the next page bit). etc.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_EXT_IN_PAGE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_SENSOR_INFO_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_OUT_LENMIN
value|4
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

begin_comment
comment|/* enum: Controller temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_TEMP
value|0x0
end_define

begin_comment
comment|/* enum: Phy common temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY_COMMON_TEMP
value|0x1
end_define

begin_comment
comment|/* enum: Controller cooling: bool */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_COOLING
value|0x2
end_define

begin_comment
comment|/* enum: Phy 0 temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY0_TEMP
value|0x3
end_define

begin_comment
comment|/* enum: Phy 0 cooling: bool */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY0_COOLING
value|0x4
end_define

begin_comment
comment|/* enum: Phy 1 temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY1_TEMP
value|0x5
end_define

begin_comment
comment|/* enum: Phy 1 cooling: bool */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY1_COOLING
value|0x6
end_define

begin_comment
comment|/* enum: 1.0v power: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_1V0
value|0x7
end_define

begin_comment
comment|/* enum: 1.2v power: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_1V2
value|0x8
end_define

begin_comment
comment|/* enum: 1.8v power: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_1V8
value|0x9
end_define

begin_comment
comment|/* enum: 2.5v power: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_2V5
value|0xa
end_define

begin_comment
comment|/* enum: 3.3v power: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_3V3
value|0xb
end_define

begin_comment
comment|/* enum: 12v power: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_12V0
value|0xc
end_define

begin_comment
comment|/* enum: 1.2v analogue power: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_1V2A
value|0xd
end_define

begin_comment
comment|/* enum: reference voltage: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_VREF
value|0xe
end_define

begin_comment
comment|/* enum: AOE FPGA power: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_OUT_VAOE
value|0xf
end_define

begin_comment
comment|/* enum: AOE FPGA temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_AOE_TEMP
value|0x10
end_define

begin_comment
comment|/* enum: AOE FPGA PSU temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PSU_AOE_TEMP
value|0x11
end_define

begin_comment
comment|/* enum: AOE PSU temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PSU_TEMP
value|0x12
end_define

begin_comment
comment|/* enum: Fan 0 speed: RPM */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_FAN_0
value|0x13
end_define

begin_comment
comment|/* enum: Fan 1 speed: RPM */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_FAN_1
value|0x14
end_define

begin_comment
comment|/* enum: Fan 2 speed: RPM */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_FAN_2
value|0x15
end_define

begin_comment
comment|/* enum: Fan 3 speed: RPM */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_FAN_3
value|0x16
end_define

begin_comment
comment|/* enum: Fan 4 speed: RPM */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_FAN_4
value|0x17
end_define

begin_comment
comment|/* enum: AOE FPGA input power: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_VAOE
value|0x18
end_define

begin_comment
comment|/* enum: AOE FPGA current: mA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_OUT_IAOE
value|0x19
end_define

begin_comment
comment|/* enum: AOE FPGA input current: mA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_IAOE
value|0x1a
end_define

begin_comment
comment|/* enum: NIC power consumption: W */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_NIC_POWER
value|0x1b
end_define

begin_comment
comment|/* enum: 0.9v power voltage: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_0V9
value|0x1c
end_define

begin_comment
comment|/* enum: 0.9v power current: mA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_I0V9
value|0x1d
end_define

begin_comment
comment|/* enum: 1.2v power current: mA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_I1V2
value|0x1e
end_define

begin_comment
comment|/* enum: Not a sensor: reserved for the next page flag */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PAGE0_NEXT
value|0x1f
end_define

begin_comment
comment|/* enum: 0.9v power voltage (at ADC): mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_0V9_ADC
value|0x20
end_define

begin_comment
comment|/* enum: Controller temperature 2: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_2_TEMP
value|0x21
end_define

begin_comment
comment|/* enum: Voltage regulator internal temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VREG_INTERNAL_TEMP
value|0x22
end_define

begin_comment
comment|/* enum: 0.9V voltage regulator temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VREG_0V9_TEMP
value|0x23
end_define

begin_comment
comment|/* enum: 1.2V voltage regulator temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VREG_1V2_TEMP
value|0x24
end_define

begin_comment
comment|/* enum: controller internal temperature sensor voltage (internal ADC): mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_VPTAT
value|0x25
end_define

begin_comment
comment|/* enum: controller internal temperature (internal ADC): degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_INTERNAL_TEMP
value|0x26
end_define

begin_comment
comment|/* enum: controller internal temperature sensor voltage (external ADC): mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_VPTAT_EXTADC
value|0x27
end_define

begin_comment
comment|/* enum: controller internal temperature (external ADC): degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_INTERNAL_TEMP_EXTADC
value|0x28
end_define

begin_comment
comment|/* enum: ambient temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_AMBIENT_TEMP
value|0x29
end_define

begin_comment
comment|/* enum: air flow: bool */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_AIRFLOW
value|0x2a
end_define

begin_comment
comment|/* enum: voltage between VSS08D and VSS08D at CSR: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VDD08D_VSS08D_CSR
value|0x2b
end_define

begin_comment
comment|/* enum: voltage between VSS08D and VSS08D at CSR (external ADC): mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VDD08D_VSS08D_CSR_EXTADC
value|0x2c
end_define

begin_comment
comment|/* enum: Hotpoint temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_HOTPOINT_TEMP
value|0x2d
end_define

begin_comment
comment|/* enum: Port 0 PHY power switch over-current: bool */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY_POWER_PORT0
value|0x2e
end_define

begin_comment
comment|/* enum: Port 1 PHY power switch over-current: bool */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY_POWER_PORT1
value|0x2f
end_define

begin_comment
comment|/* enum: Mop-up microcontroller reference voltage (millivolts) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_MUM_VCC
value|0x30
end_define

begin_comment
comment|/* enum: 0.9v power phase A voltage: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_0V9_A
value|0x31
end_define

begin_comment
comment|/* enum: 0.9v power phase A current: mA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_I0V9_A
value|0x32
end_define

begin_comment
comment|/* enum: 0.9V voltage regulator phase A temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VREG_0V9_A_TEMP
value|0x33
end_define

begin_comment
comment|/* enum: 0.9v power phase B voltage: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_0V9_B
value|0x34
end_define

begin_comment
comment|/* enum: 0.9v power phase B current: mA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_IN_I0V9_B
value|0x35
end_define

begin_comment
comment|/* enum: 0.9V voltage regulator phase B temperature: degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VREG_0V9_B_TEMP
value|0x36
end_define

begin_comment
comment|/* enum: CCOM AVREG 1v2 supply (interval ADC): mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CCOM_AVREG_1V2_SUPPLY
value|0x37
end_define

begin_comment
comment|/* enum: CCOM AVREG 1v2 supply (external ADC): mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CCOM_AVREG_1V2_SUPPLY_EXTADC
value|0x38
end_define

begin_comment
comment|/* enum: CCOM AVREG 1v8 supply (interval ADC): mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CCOM_AVREG_1V8_SUPPLY
value|0x39
end_define

begin_comment
comment|/* enum: CCOM AVREG 1v8 supply (external ADC): mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CCOM_AVREG_1V8_SUPPLY_EXTADC
value|0x3a
end_define

begin_comment
comment|/* enum: Not a sensor: reserved for the next page flag */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PAGE1_NEXT
value|0x3f
end_define

begin_comment
comment|/* enum: controller internal temperature sensor voltage on master core  * (internal ADC): mV  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_MASTER_VPTAT
value|0x40
end_define

begin_comment
comment|/* enum: controller internal temperature on master core (internal ADC): degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_MASTER_INTERNAL_TEMP
value|0x41
end_define

begin_comment
comment|/* enum: controller internal temperature sensor voltage on master core  * (external ADC): mV  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_MASTER_VPTAT_EXTADC
value|0x42
end_define

begin_comment
comment|/* enum: controller internal temperature on master core (external ADC): degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_MASTER_INTERNAL_TEMP_EXTADC
value|0x43
end_define

begin_comment
comment|/* enum: controller internal temperature on slave core sensor voltage (internal  * ADC): mV  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_SLAVE_VPTAT
value|0x44
end_define

begin_comment
comment|/* enum: controller internal temperature on slave core (internal ADC): degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_SLAVE_INTERNAL_TEMP
value|0x45
end_define

begin_comment
comment|/* enum: controller internal temperature on slave core sensor voltage (external  * ADC): mV  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_SLAVE_VPTAT_EXTADC
value|0x46
end_define

begin_comment
comment|/* enum: controller internal temperature on slave core (external ADC): degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_CONTROLLER_SLAVE_INTERNAL_TEMP_EXTADC
value|0x47
end_define

begin_comment
comment|/* enum: Voltage supplied to the SODIMMs from their power supply: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SODIMM_VOUT
value|0x49
end_define

begin_comment
comment|/* enum: Temperature of SODIMM 0 (if installed): degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SODIMM_0_TEMP
value|0x4a
end_define

begin_comment
comment|/* enum: Temperature of SODIMM 1 (if installed): degC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SODIMM_1_TEMP
value|0x4b
end_define

begin_comment
comment|/* enum: Voltage supplied to the QSFP #0 from their power supply: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY0_VCC
value|0x4c
end_define

begin_comment
comment|/* enum: Voltage supplied to the QSFP #1 from their power supply: mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_PHY1_VCC
value|0x4d
end_define

begin_comment
comment|/* MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF */
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
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_ENTRY_MAXNUM
value|31
end_define

begin_comment
comment|/* MC_CMD_SENSOR_INFO_EXT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_EXT_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_EXT_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_EXT_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+8*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_EXT_OUT_MASK_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_SENSOR_INFO_OUT */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_EXT_OUT_NEXT_PAGE_LBN
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_INFO_EXT_OUT_NEXT_PAGE_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_SENSOR_INFO_ENTRY_TYPEDEF */
end_comment

begin_comment
comment|/*            MC_CMD_SENSOR_ENTRY_OFST 4 */
end_comment

begin_comment
comment|/*            MC_CMD_SENSOR_ENTRY_LEN 8 */
end_comment

begin_comment
comment|/*            MC_CMD_SENSOR_ENTRY_LO_OFST 4 */
end_comment

begin_comment
comment|/*            MC_CMD_SENSOR_ENTRY_HI_OFST 8 */
end_comment

begin_comment
comment|/*            MC_CMD_SENSOR_ENTRY_MINNUM 0 */
end_comment

begin_comment
comment|/*            MC_CMD_SENSOR_ENTRY_MAXNUM 31 */
end_comment

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
comment|/* MC_CMD_READ_SENSORS  * Returns the current reading from each sensor. DMAs an array of sensor  * readings, in order of sensor type (but without gaps for unimplemented  * sensors), into host memory. Each array element is a  * MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF dword.  *  * If the request does not contain the LENGTH field then only sensors 0 to 30  * are reported, to avoid DMA buffer overflow in older host software. If the  * sensor reading require more space than the LENGTH allows, then return  * EINVAL.  *  * The MC will send a SENSOREVT event every time any sensor changes state. The  * driver is responsible for ensuring that it doesn't miss any events. The  * board will function normally if all sensors are in STATE_OK or  * STATE_WARNING. Otherwise the board should not be expected to function.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS
value|0x42
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x42_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x42_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* DMA address of host buffer for sensor readings (must be 4Kbyte aligned). */
end_comment

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
comment|/* MC_CMD_READ_SENSORS_EXT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_EXT_IN_LEN
value|12
end_define

begin_comment
comment|/* DMA address of host buffer for sensor readings */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_EXT_IN_DMA_ADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_EXT_IN_DMA_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_EXT_IN_DMA_ADDR_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_EXT_IN_DMA_ADDR_HI_OFST
value|4
end_define

begin_comment
comment|/* Size in bytes of host buffer. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_EXT_IN_LENGTH_OFST
value|8
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
comment|/* MC_CMD_READ_SENSORS_EXT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_SENSORS_EXT_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF structuredef */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_LEN
value|4
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

begin_comment
comment|/* enum: Ok. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_STATE_OK
value|0x0
end_define

begin_comment
comment|/* enum: Breached warning threshold. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_STATE_WARNING
value|0x1
end_define

begin_comment
comment|/* enum: Breached fatal threshold. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_STATE_FATAL
value|0x2
end_define

begin_comment
comment|/* enum: Fault with sensor. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_STATE_BROKEN
value|0x3
end_define

begin_comment
comment|/* enum: Sensor is working but does not currently have a reading. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_STATE_NO_READING
value|0x4
end_define

begin_comment
comment|/* enum: Sensor initialisation failed. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_STATE_INIT_FAILED
value|0x5
end_define

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

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_TYPE_OFST
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_TYPE_LEN
value|1
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
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_TYPE_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_VALUE_ENTRY_TYPEDEF_TYPE_WIDTH
value|8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PHY_STATE  * Report current state of PHY. A 'zombie' PHY is a PHY that has failed to boot  * (e.g. due to missing or corrupted firmware). Locks required: None. Return  * code: 0  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_STATE
value|0x43
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x43_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x43_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* enum: Ok. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATE_OK
value|0x1
end_define

begin_comment
comment|/* enum: Faulty. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PHY_STATE_ZOMBIE
value|0x2
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SETUP_8021QBB  * 802.1Qbb control. 8 Tx queues that map to priorities 0 - 7. Use all 1s to  * disable 802.Qbb for a given priority.  */
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
comment|/* MC_CMD_WOL_FILTER_GET  * Retrieve ID of any WoL filters. Locks required: None. Returns: 0, ENOSYS  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WOL_FILTER_GET
value|0x45
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x45_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x45_PRIVILEGE_CTG
value|SRIOV_CTG_LINK
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
comment|/* MC_CMD_ADD_LIGHTSOUT_OFFLOAD  * Add a protocol offload to NIC for lights-out state. Locks required: None.  * Returns: 0, ENOSYS  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ADD_LIGHTSOUT_OFFLOAD
value|0x46
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x46_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x46_PRIVILEGE_CTG
value|SRIOV_CTG_LINK
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
comment|/* MC_CMD_REMOVE_LIGHTSOUT_OFFLOAD  * Remove a protocol offload from NIC for lights-out state. Locks required:  * None. Returns: 0, ENOSYS  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_REMOVE_LIGHTSOUT_OFFLOAD
value|0x47
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x47_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x47_PRIVILEGE_CTG
value|SRIOV_CTG_LINK
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
comment|/* MC_CMD_MAC_RESET_RESTORE  * Restore MAC after block reset. Locks required: None. Returns: 0.  */
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
comment|/* MC_CMD_TESTASSERT  * Deliberately trigger an assert-detonation in the firmware for testing  * purposes (i.e. to allow tests that the driver copes gracefully). Locks  * required: None Returns: 0  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TESTASSERT
value|0x49
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x49_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x49_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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
comment|/* MC_CMD_WORKAROUND  * Enable/Disable a given workaround. The mcfw will return EINVAL if it doesn't  * understand the given workaround number - which should not be treated as a  * hard error by client code. This op does not imply any semantics about each  * workaround, that's between the driver and the mcfw on a per-workaround  * basis. Locks required: None. Returns: 0, EINVAL .  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND
value|0x4a
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x4a_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x4a_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* The enums here must correspond with those in MC_CMD_GET_WORKAROUND. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/* enum: Bug 17230 work around. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_BUG17230
value|0x1
end_define

begin_comment
comment|/* enum: Bug 35388 work around (unsafe EVQ writes). */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_BUG35388
value|0x2
end_define

begin_comment
comment|/* enum: Bug35017 workaround (A64 tables must be identity map) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_BUG35017
value|0x3
end_define

begin_comment
comment|/* enum: Bug 41750 present (MC_CMD_TRIGGER_INTERRUPT won't work) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_BUG41750
value|0x4
end_define

begin_comment
comment|/* enum: Bug 42008 present (Interrupts can overtake associated events). Caution  * - before adding code that queries this workaround, remember that there's  * released Monza firmware that doesn't understand MC_CMD_WORKAROUND_BUG42008,  * and will hence (incorrectly) report that the bug doesn't exist.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_BUG42008
value|0x5
end_define

begin_comment
comment|/* enum: Bug 26807 features present in firmware (multicast filter chaining)  * This feature cannot be turned on/off while there are any filters already  * present. The behaviour in such case depends on the acting client's privilege  * level. If the client has the admin privilege, then all functions that have  * filters installed will be FLRed and the FLR_DONE flag will be set. Otherwise  * the command will fail with MC_CMD_ERR_FILTERS_PRESENT.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_BUG26807
value|0x6
end_define

begin_comment
comment|/* 0 = disable the workaround indicated by TYPE; any non-zero value = enable  * the workaround  */
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
comment|/* MC_CMD_WORKAROUND_EXT_OUT msgresponse: This response format will be used  * when (TYPE == MC_CMD_WORKAROUND_BUG26807)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_EXT_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_EXT_OUT_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_EXT_OUT_FLR_DONE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_WORKAROUND_EXT_OUT_FLR_DONE_WIDTH
value|1
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PHY_MEDIA_INFO  * Read media-specific data from PHY (e.g. SFP/SFP+ module ID information for  * SFP+ PHYs). The 'media type' can be found via GET_PHY_CFG  * (GET_PHY_CFG_OUT_MEDIA_TYPE); the valid 'page number' input values, and the  * output data, are interpreted on a per-type basis. For SFP+: PAGE=0 or 1  * returns a 128-byte block read from module I2C address 0xA0 offset 0 or 0x80.  * Anything else: currently undefined. Locks required: None. Return code: 0.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PHY_MEDIA_INFO
value|0x4b
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x4b_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x4b_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* in bytes */
end_comment

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
comment|/* MC_CMD_NVRAM_TEST  * Test a particular NVRAM partition for valid contents (where "valid" depends  * on the type of partition).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST
value|0x4c
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x4c_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x4c_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* enum: Passed. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST_PASS
value|0x0
end_define

begin_comment
comment|/* enum: Failed. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST_FAIL
value|0x1
end_define

begin_comment
comment|/* enum: Not supported. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_TEST_NOTSUPP
value|0x2
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_MRSFP_TWEAK  * Read status and/or set parameters for the 'mrsfp' driver in mr_rusty builds.  * I2C I/O expander bits are always read; if equaliser parameters are supplied,  * they are configured first. Locks required: None. Return code: 0, EINVAL.  */
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

begin_comment
comment|/* 0-6 low->high de-emph. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_IN_EQ_CONFIG_TXEQ_LEVEL_OFST
value|0
end_define

begin_comment
comment|/* 0-8 low->high ref.V */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_IN_EQ_CONFIG_TXEQ_DT_CFG_OFST
value|4
end_define

begin_comment
comment|/* 0-8 0-8 low->high boost */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_IN_EQ_CONFIG_RXEQ_BOOST_OFST
value|8
end_define

begin_comment
comment|/* 0-8 low->high ref.V */
end_comment

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

begin_comment
comment|/* input bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_OUT_IOEXP_INPUTS_OFST
value|0
end_define

begin_comment
comment|/* output bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_OUT_IOEXP_OUTPUTS_OFST
value|4
end_define

begin_comment
comment|/* direction */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_OUT_IOEXP_DIRECTION_OFST
value|8
end_define

begin_comment
comment|/* enum: Out. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_OUT_IOEXP_DIRECTION_OUT
value|0x0
end_define

begin_comment
comment|/* enum: In. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MRSFP_TWEAK_OUT_IOEXP_DIRECTION_IN
value|0x1
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SENSOR_SET_LIMS  * Adjusts the sensor limits. This is a warranty-voiding operation. Returns:  * ENOENT if the sensor specified does not exist, EINVAL if the limits are out  * of range.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS
value|0x4e
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x4e_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x4e_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* interpretation is is sensor-specific. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS_IN_LOW0_OFST
value|4
end_define

begin_comment
comment|/* interpretation is is sensor-specific. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS_IN_HI0_OFST
value|8
end_define

begin_comment
comment|/* interpretation is is sensor-specific. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SENSOR_SET_LIMS_IN_LOW1_OFST
value|12
end_define

begin_comment
comment|/* interpretation is is sensor-specific. */
end_comment

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
comment|/* MC_CMD_GET_RESOURCE_LIMITS  */
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
comment|/* MC_CMD_NVRAM_PARTITIONS  * Reads the list of available virtual NVRAM partition types. Locks required:  * none. Returns: 0, EINVAL (bad type).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_PARTITIONS
value|0x51
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x51_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x51_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_NVRAM_PARTITIONS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_PARTITIONS_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_NVRAM_PARTITIONS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_PARTITIONS_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_PARTITIONS_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_PARTITIONS_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+4*(num))
end_define

begin_comment
comment|/* total number of partitions */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_PARTITIONS_OUT_NUM_PARTITIONS_OFST
value|0
end_define

begin_comment
comment|/* type ID code for each of NUM_PARTITIONS partitions */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_PARTITIONS_OUT_TYPE_ID_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_PARTITIONS_OUT_TYPE_ID_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_PARTITIONS_OUT_TYPE_ID_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_PARTITIONS_OUT_TYPE_ID_MAXNUM
value|62
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_NVRAM_METADATA  * Reads soft metadata for a virtual NVRAM partition type. Locks required:  * none. Returns: 0, EINVAL (bad type).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA
value|0x52
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x52_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x52_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_NVRAM_METADATA_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_IN_LEN
value|4
end_define

begin_comment
comment|/* Partition type ID code */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_NVRAM_METADATA_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_LENMIN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(20+1*(num))
end_define

begin_comment
comment|/* Partition type ID code */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_TYPE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_FLAGS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_SUBTYPE_VALID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_SUBTYPE_VALID_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_VERSION_VALID_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_VERSION_VALID_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_DESCRIPTION_VALID_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_DESCRIPTION_VALID_WIDTH
value|1
end_define

begin_comment
comment|/* Subtype ID code for content of this partition */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_SUBTYPE_OFST
value|8
end_define

begin_comment
comment|/* 1st component of W.X.Y.Z version number for content of this partition */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_VERSION_W_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_VERSION_W_LEN
value|2
end_define

begin_comment
comment|/* 2nd component of W.X.Y.Z version number for content of this partition */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_VERSION_X_OFST
value|14
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_VERSION_X_LEN
value|2
end_define

begin_comment
comment|/* 3rd component of W.X.Y.Z version number for content of this partition */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_VERSION_Y_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_VERSION_Y_LEN
value|2
end_define

begin_comment
comment|/* 4th component of W.X.Y.Z version number for content of this partition */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_VERSION_Z_OFST
value|18
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_VERSION_Z_LEN
value|2
end_define

begin_comment
comment|/* Zero-terminated string describing the content of this partition */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_DESCRIPTION_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_DESCRIPTION_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_DESCRIPTION_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_NVRAM_METADATA_OUT_DESCRIPTION_MAXNUM
value|232
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_MAC_ADDRESSES  * Returns the base MAC, count and stride for the requesting function  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_MAC_ADDRESSES
value|0x55
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x55_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x55_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_MAC_ADDRESSES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_MAC_ADDRESSES_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_MAC_ADDRESSES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_MAC_ADDRESSES_OUT_LEN
value|16
end_define

begin_comment
comment|/* Base MAC address */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_MAC_ADDRESSES_OUT_MAC_ADDR_BASE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_MAC_ADDRESSES_OUT_MAC_ADDR_BASE_LEN
value|6
end_define

begin_comment
comment|/* Padding */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_MAC_ADDRESSES_OUT_RESERVED_OFST
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_MAC_ADDRESSES_OUT_RESERVED_LEN
value|2
end_define

begin_comment
comment|/* Number of allocated MAC addresses */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_MAC_ADDRESSES_OUT_MAC_COUNT_OFST
value|8
end_define

begin_comment
comment|/* Spacing of allocated MAC addresses */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_MAC_ADDRESSES_OUT_MAC_STRIDE_OFST
value|12
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_CLP  * Perform a CLP related operation  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP
value|0x56
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x56_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x56_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Sub operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_IN_OP_OFST
value|0
end_define

begin_comment
comment|/* enum: Return to factory default settings */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OP_DEFAULT
value|0x1
end_define

begin_comment
comment|/* enum: Set MAC address */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OP_SET_MAC
value|0x2
end_define

begin_comment
comment|/* enum: Get MAC address */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OP_GET_MAC
value|0x3
end_define

begin_comment
comment|/* enum: Set UEFI/GPXE boot mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OP_SET_BOOT
value|0x4
end_define

begin_comment
comment|/* enum: Get UEFI/GPXE boot mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CLP_OP_GET_BOOT
value|0x5
end_define

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

begin_comment
comment|/* MAC address assigned to port */
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

begin_comment
comment|/* Padding */
end_comment

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

begin_comment
comment|/* MAC address assigned to port */
end_comment

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

begin_comment
comment|/* Padding */
end_comment

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

begin_comment
comment|/* Boot flag */
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

begin_comment
comment|/* Boot flag */
end_comment

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

begin_comment
comment|/* Padding */
end_comment

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
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_MUM  * Perform a MUM operation  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM
value|0x57
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x57_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x57_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_MUM_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_OP_HDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_OP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_OP_WIDTH
value|8
end_define

begin_comment
comment|/* enum: NULL MCDI command to MUM */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_NULL
value|0x1
end_define

begin_comment
comment|/* enum: Get MUM version */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_GET_VERSION
value|0x2
end_define

begin_comment
comment|/* enum: Issue raw I2C command to MUM */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_RAW_CMD
value|0x3
end_define

begin_comment
comment|/* enum: Read from registers on devices connected to MUM. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_READ
value|0x4
end_define

begin_comment
comment|/* enum: Write to registers on devices connected to MUM. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_WRITE
value|0x5
end_define

begin_comment
comment|/* enum: Control UART logging. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_LOG
value|0x6
end_define

begin_comment
comment|/* enum: Operations on MUM GPIO lines */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_GPIO
value|0x7
end_define

begin_comment
comment|/* enum: Get sensor readings from MUM */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_READ_SENSORS
value|0x8
end_define

begin_comment
comment|/* enum: Initiate clock programming on the MUM */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_PROGRAM_CLOCKS
value|0x9
end_define

begin_comment
comment|/* enum: Initiate FPGA load from flash on the MUM */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_FPGA_LOAD
value|0xa
end_define

begin_comment
comment|/* enum: Request sensor reading from MUM ADC resulting from earlier request via  * MUM ATB  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_READ_ATB_SENSOR
value|0xb
end_define

begin_comment
comment|/* enum: Send commands relating to the QSFP ports via the MUM for PHY  * operations  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OP_QSFP
value|0xc
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_NULL msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_NULL_LEN
value|4
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_CMD_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_GET_VERSION msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GET_VERSION_LEN
value|4
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_MUM_IN_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_READ_LEN
value|16
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* ID of (device connected to MUM) to read from registers of */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_READ_DEVICE_OFST
value|4
end_define

begin_comment
comment|/* enum: Hittite HMC1035 clock generator on Sorrento board */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_DEV_HITTITE
value|0x1
end_define

begin_comment
comment|/* enum: Hittite HMC1035 clock generator for NIC-side on Sorrento board */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_DEV_HITTITE_NIC
value|0x2
end_define

begin_comment
comment|/* 32-bit address to read from */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_READ_ADDR_OFST
value|8
end_define

begin_comment
comment|/* Number of words to read. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_READ_NUMWORDS_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_WRITE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_WRITE_LENMIN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_WRITE_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_WRITE_LEN
parameter_list|(
name|num
parameter_list|)
value|(12+4*(num))
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* ID of (device connected to MUM) to write to registers of */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_WRITE_DEVICE_OFST
value|4
end_define

begin_comment
comment|/* enum: Hittite HMC1035 clock generator on Sorrento board */
end_comment

begin_comment
comment|/*               MC_CMD_MUM_DEV_HITTITE 0x1 */
end_comment

begin_comment
comment|/* 32-bit address to write to */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_WRITE_ADDR_OFST
value|8
end_define

begin_comment
comment|/* Words to write */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_WRITE_BUFFER_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_WRITE_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_WRITE_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_WRITE_BUFFER_MAXNUM
value|60
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_RAW_CMD msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_RAW_CMD_LENMIN
value|17
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_RAW_CMD_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_RAW_CMD_LEN
parameter_list|(
name|num
parameter_list|)
value|(16+1*(num))
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* MUM I2C cmd code */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_RAW_CMD_CMD_CODE_OFST
value|4
end_define

begin_comment
comment|/* Number of bytes to write */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_RAW_CMD_NUM_WRITE_OFST
value|8
end_define

begin_comment
comment|/* Number of bytes to read */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_RAW_CMD_NUM_READ_OFST
value|12
end_define

begin_comment
comment|/* Bytes to write */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_RAW_CMD_WRITE_DATA_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_RAW_CMD_WRITE_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_RAW_CMD_WRITE_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_RAW_CMD_WRITE_DATA_MAXNUM
value|236
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_LOG msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_LOG_LEN
value|8
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_LOG_OP_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_LOG_OP_UART
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_MUM_IN_LOG_OP_UART msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_LOG_OP_UART_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_LOG_OP_OFST 4 */
end_comment

begin_comment
comment|/* Enable/disable debug output to UART */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_LOG_OP_UART_ENABLE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_GPIO msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_LEN
value|8
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OPCODE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OPCODE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_IN_READ
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_WRITE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_READ
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_ENABLE_WRITE
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_ENABLE_READ
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_MUM_IN_GPIO_IN_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_IN_READ_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_IN_READ_HDR_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_GPIO_OUT_WRITE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_WRITE_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_WRITE_HDR_OFST
value|4
end_define

begin_comment
comment|/* The first 32-bit word to be written to the GPIO OUT register. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_WRITE_GPIOMASK1_OFST
value|8
end_define

begin_comment
comment|/* The second 32-bit word to be written to the GPIO OUT register. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_WRITE_GPIOMASK2_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_GPIO_OUT_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_READ_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_READ_HDR_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_GPIO_OUT_ENABLE_WRITE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_ENABLE_WRITE_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_ENABLE_WRITE_HDR_OFST
value|4
end_define

begin_comment
comment|/* The first 32-bit word to be written to the GPIO OUT ENABLE register. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_ENABLE_WRITE_GPIOMASK1_OFST
value|8
end_define

begin_comment
comment|/* The second 32-bit word to be written to the GPIO OUT ENABLE register. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_ENABLE_WRITE_GPIOMASK2_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_GPIO_OUT_ENABLE_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_ENABLE_READ_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OUT_ENABLE_READ_HDR_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_GPIO_OP msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_BITWISE_OP_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_BITWISE_OP_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_READ
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_WRITE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_CONFIG
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_ENABLE
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_GPIO_NUMBER_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_GPIO_NUMBER_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_GPIO_OP_OUT_READ msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_READ_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_READ_HDR_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_GPIO_OP_OUT_WRITE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_WRITE_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_WRITE_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_WRITE_WRITEBIT_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_WRITE_WRITEBIT_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_GPIO_OP_OUT_CONFIG msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_CONFIG_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_CONFIG_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_CONFIG_CFG_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_CONFIG_CFG_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_GPIO_OP_OUT_ENABLE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_ENABLE_LEN
value|8
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_ENABLE_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_ENABLE_ENABLEBIT_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_GPIO_OP_OUT_ENABLE_ENABLEBIT_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_READ_SENSORS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_READ_SENSORS_LEN
value|8
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_READ_SENSORS_PARAMS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_READ_SENSORS_SENSOR_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_READ_SENSORS_SENSOR_ID_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_READ_SENSORS_NUM_SENSORS_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_READ_SENSORS_NUM_SENSORS_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_PROGRAM_CLOCKS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_PROGRAM_CLOCKS_LEN
value|12
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* Bit-mask of clocks to be programmed */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_PROGRAM_CLOCKS_MASK_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_CLOCK_ID_FPGA
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_CLOCK_ID_DDR
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_CLOCK_ID_NIC
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* Control flags for clock programming */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_PROGRAM_CLOCKS_FLAGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_PROGRAM_CLOCKS_OVERCLOCK_110_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_PROGRAM_CLOCKS_OVERCLOCK_110_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_FPGA_LOAD msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_FPGA_LOAD_LEN
value|8
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* Enable/Disable FPGA config from flash */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_FPGA_LOAD_ENABLE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_READ_ATB_SENSOR msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_READ_ATB_SENSOR_LEN
value|4
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_comment
comment|/* MC_CMD_MUM_IN_QSFP msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_LEN
value|12
end_define

begin_comment
comment|/* MUM cmd header */
end_comment

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_OPCODE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_OPCODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_INIT
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_RECONFIGURE
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_GET_SUPPORTED_CAP
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_GET_MEDIA_INFO
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_FILL_STATS
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_POLL_BIST
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_IDX_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_QSFP_INIT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_INIT_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_INIT_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_INIT_IDX_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_INIT_CAGE_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_QSFP_RECONFIGURE msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_RECONFIGURE_LEN
value|24
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_RECONFIGURE_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_RECONFIGURE_IDX_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_RECONFIGURE_TX_DISABLE_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_RECONFIGURE_PORT_LANES_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_RECONFIGURE_PORT_LINK_SPEED_OFST
value|20
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_QSFP_GET_SUPPORTED_CAP msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_GET_SUPPORTED_CAP_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_GET_SUPPORTED_CAP_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_GET_SUPPORTED_CAP_IDX_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_QSFP_GET_MEDIA_INFO msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_GET_MEDIA_INFO_LEN
value|16
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_GET_MEDIA_INFO_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_GET_MEDIA_INFO_IDX_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_GET_MEDIA_INFO_PAGE_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_QSFP_FILL_STATS msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_FILL_STATS_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_FILL_STATS_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_FILL_STATS_IDX_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_IN_QSFP_POLL_BIST msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_POLL_BIST_LEN
value|12
end_define

begin_comment
comment|/*            MC_CMD_MUM_IN_CMD_OFST 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_POLL_BIST_HDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_IN_QSFP_POLL_BIST_IDX_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_NULL msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_NULL_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_GET_VERSION msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GET_VERSION_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GET_VERSION_FIRMWARE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GET_VERSION_VERSION_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GET_VERSION_VERSION_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GET_VERSION_VERSION_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GET_VERSION_VERSION_HI_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_RAW_CMD msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_RAW_CMD_LENMIN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_RAW_CMD_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_RAW_CMD_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+1*(num))
end_define

begin_comment
comment|/* returned data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_RAW_CMD_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_RAW_CMD_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_RAW_CMD_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_RAW_CMD_DATA_MAXNUM
value|252
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_READ msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_BUFFER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_BUFFER_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_BUFFER_MAXNUM
value|63
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_WRITE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_WRITE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_LOG msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_LOG_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_LOG_OP_UART msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_LOG_OP_UART_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_GPIO_IN_READ msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_IN_READ_LEN
value|8
end_define

begin_comment
comment|/* The first 32-bit word read from the GPIO IN register. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_IN_READ_GPIOMASK1_OFST
value|0
end_define

begin_comment
comment|/* The second 32-bit word read from the GPIO IN register. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_IN_READ_GPIOMASK2_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_GPIO_OUT_WRITE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OUT_WRITE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_GPIO_OUT_READ msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OUT_READ_LEN
value|8
end_define

begin_comment
comment|/* The first 32-bit word read from the GPIO OUT register. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OUT_READ_GPIOMASK1_OFST
value|0
end_define

begin_comment
comment|/* The second 32-bit word read from the GPIO OUT register. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OUT_READ_GPIOMASK2_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_GPIO_OUT_ENABLE_WRITE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OUT_ENABLE_WRITE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_GPIO_OUT_ENABLE_READ msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OUT_ENABLE_READ_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OUT_ENABLE_READ_GPIOMASK1_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OUT_ENABLE_READ_GPIOMASK2_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_GPIO_OP_OUT_READ msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OP_OUT_READ_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OP_OUT_READ_BIT_READ_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_GPIO_OP_OUT_WRITE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OP_OUT_WRITE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_GPIO_OP_OUT_CONFIG msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OP_OUT_CONFIG_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_GPIO_OP_OUT_ENABLE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_GPIO_OP_OUT_ENABLE_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_READ_SENSORS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_DATA_MAXNUM
value|63
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_READING_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_READING_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_STATE_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_STATE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_TYPE_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_SENSORS_TYPE_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_PROGRAM_CLOCKS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_PROGRAM_CLOCKS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_PROGRAM_CLOCKS_OK_MASK_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_FPGA_LOAD msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_FPGA_LOAD_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_READ_ATB_SENSOR msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_ATB_SENSOR_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_READ_ATB_SENSOR_RESULT_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_QSFP_INIT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_INIT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_QSFP_RECONFIGURE msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_RECONFIGURE_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_RECONFIGURE_PORT_PHY_LP_CAP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_RECONFIGURE_PORT_PHY_FLAGS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_RECONFIGURE_PORT_PHY_READY_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_RECONFIGURE_PORT_PHY_READY_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_RECONFIGURE_PORT_PHY_LINK_UP_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_RECONFIGURE_PORT_PHY_LINK_UP_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_QSFP_GET_SUPPORTED_CAP msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_GET_SUPPORTED_CAP_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_GET_SUPPORTED_CAP_PORT_PHY_LP_CAP_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_QSFP_GET_MEDIA_INFO msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_GET_MEDIA_INFO_LENMIN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_GET_MEDIA_INFO_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_GET_MEDIA_INFO_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+1*(num))
end_define

begin_comment
comment|/* in bytes */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_GET_MEDIA_INFO_DATALEN_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_GET_MEDIA_INFO_DATA_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_GET_MEDIA_INFO_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_GET_MEDIA_INFO_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_GET_MEDIA_INFO_DATA_MAXNUM
value|248
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_QSFP_FILL_STATS msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_FILL_STATS_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_FILL_STATS_PORT_PHY_STATS_PMA_PMD_LINK_UP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_FILL_STATS_PORT_PHY_STATS_PCS_LINK_UP_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_MUM_OUT_QSFP_POLL_BIST msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_POLL_BIST_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_MUM_OUT_QSFP_POLL_BIST_TEST_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_RESOURCE_SPECIFIER enum */
end_comment

begin_comment
comment|/* enum: Any */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RESOURCE_INSTANCE_ANY
value|0xffffffff
end_define

begin_comment
comment|/* enum: None */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RESOURCE_INSTANCE_NONE
value|0xfffffffe
end_define

begin_comment
comment|/* EVB_PORT_ID structuredef */
end_comment

begin_define
define|#
directive|define
name|EVB_PORT_ID_LEN
value|4
end_define

begin_define
define|#
directive|define
name|EVB_PORT_ID_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* enum: An invalid port handle. */
end_comment

begin_define
define|#
directive|define
name|EVB_PORT_ID_NULL
value|0x0
end_define

begin_comment
comment|/* enum: The port assigned to this function.. */
end_comment

begin_define
define|#
directive|define
name|EVB_PORT_ID_ASSIGNED
value|0x1000000
end_define

begin_comment
comment|/* enum: External network port 0 */
end_comment

begin_define
define|#
directive|define
name|EVB_PORT_ID_MAC0
value|0x2000000
end_define

begin_comment
comment|/* enum: External network port 1 */
end_comment

begin_define
define|#
directive|define
name|EVB_PORT_ID_MAC1
value|0x2000001
end_define

begin_comment
comment|/* enum: External network port 2 */
end_comment

begin_define
define|#
directive|define
name|EVB_PORT_ID_MAC2
value|0x2000002
end_define

begin_comment
comment|/* enum: External network port 3 */
end_comment

begin_define
define|#
directive|define
name|EVB_PORT_ID_MAC3
value|0x2000003
end_define

begin_define
define|#
directive|define
name|EVB_PORT_ID_PORT_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|EVB_PORT_ID_PORT_ID_WIDTH
value|32
end_define

begin_comment
comment|/* EVB_VLAN_TAG structuredef */
end_comment

begin_define
define|#
directive|define
name|EVB_VLAN_TAG_LEN
value|2
end_define

begin_comment
comment|/* The VLAN tag value */
end_comment

begin_define
define|#
directive|define
name|EVB_VLAN_TAG_VLAN_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|EVB_VLAN_TAG_VLAN_ID_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|EVB_VLAN_TAG_MODE_LBN
value|12
end_define

begin_define
define|#
directive|define
name|EVB_VLAN_TAG_MODE_WIDTH
value|4
end_define

begin_comment
comment|/* enum: Insert the VLAN. */
end_comment

begin_define
define|#
directive|define
name|EVB_VLAN_TAG_INSERT
value|0x0
end_define

begin_comment
comment|/* enum: Replace the VLAN if already present. */
end_comment

begin_define
define|#
directive|define
name|EVB_VLAN_TAG_REPLACE
value|0x1
end_define

begin_comment
comment|/* BUFTBL_ENTRY structuredef */
end_comment

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_LEN
value|12
end_define

begin_comment
comment|/* the owner ID */
end_comment

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_OID_OFST
value|0
end_define

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_OID_LEN
value|2
end_define

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_OID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_OID_WIDTH
value|16
end_define

begin_comment
comment|/* the page parameter as one of ESE_DZ_SMC_PAGE_SIZE_ */
end_comment

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_PGSZ_OFST
value|2
end_define

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_PGSZ_LEN
value|2
end_define

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_PGSZ_LBN
value|16
end_define

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_PGSZ_WIDTH
value|16
end_define

begin_comment
comment|/* the raw 64-bit address field from the SMC, not adjusted for page size */
end_comment

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_RAWADDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_RAWADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_RAWADDR_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_RAWADDR_HI_OFST
value|8
end_define

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_RAWADDR_LBN
value|32
end_define

begin_define
define|#
directive|define
name|BUFTBL_ENTRY_RAWADDR_WIDTH
value|64
end_define

begin_comment
comment|/* NVRAM_PARTITION_TYPE structuredef */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_LEN
value|2
end_define

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_ID_OFST
value|0
end_define

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_ID_LEN
value|2
end_define

begin_comment
comment|/* enum: Primary MC firmware partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_MC_FIRMWARE
value|0x100
end_define

begin_comment
comment|/* enum: Secondary MC firmware partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_MC_FIRMWARE_BACKUP
value|0x200
end_define

begin_comment
comment|/* enum: Expansion ROM partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_EXPANSION_ROM
value|0x300
end_define

begin_comment
comment|/* enum: Static configuration TLV partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_STATIC_CONFIG
value|0x400
end_define

begin_comment
comment|/* enum: Dynamic configuration TLV partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_DYNAMIC_CONFIG
value|0x500
end_define

begin_comment
comment|/* enum: Expansion ROM configuration data for port 0 */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_EXPROM_CONFIG_PORT0
value|0x600
end_define

begin_comment
comment|/* enum: Expansion ROM configuration data for port 1 */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_EXPROM_CONFIG_PORT1
value|0x601
end_define

begin_comment
comment|/* enum: Expansion ROM configuration data for port 2 */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_EXPROM_CONFIG_PORT2
value|0x602
end_define

begin_comment
comment|/* enum: Expansion ROM configuration data for port 3 */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_EXPROM_CONFIG_PORT3
value|0x603
end_define

begin_comment
comment|/* enum: Non-volatile log output partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_LOG
value|0x700
end_define

begin_comment
comment|/* enum: Device state dump output partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_DUMP
value|0x800
end_define

begin_comment
comment|/* enum: Application license key storage partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_LICENSE
value|0x900
end_define

begin_comment
comment|/* enum: Start of range used for PHY partitions (low 8 bits are the PHY ID) */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_PHY_MIN
value|0xa00
end_define

begin_comment
comment|/* enum: End of range used for PHY partitions (low 8 bits are the PHY ID) */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_PHY_MAX
value|0xaff
end_define

begin_comment
comment|/* enum: Primary FPGA partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_FPGA
value|0xb00
end_define

begin_comment
comment|/* enum: Secondary FPGA partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_FPGA_BACKUP
value|0xb01
end_define

begin_comment
comment|/* enum: FC firmware partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_FC_FIRMWARE
value|0xb02
end_define

begin_comment
comment|/* enum: FC License partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_FC_LICENSE
value|0xb03
end_define

begin_comment
comment|/* enum: Non-volatile log output partition for FC */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_FC_LOG
value|0xb04
end_define

begin_comment
comment|/* enum: MUM firmware partition */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_MUM_FIRMWARE
value|0xc00
end_define

begin_comment
comment|/* enum: MUM Non-volatile log output partition. */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_MUM_LOG
value|0xc01
end_define

begin_comment
comment|/* enum: MUM Application table partition. */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_MUM_APPTABLE
value|0xc02
end_define

begin_comment
comment|/* enum: MUM boot rom partition. */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_MUM_BOOT_ROM
value|0xc03
end_define

begin_comment
comment|/* enum: MUM production signatures& calibration rom partition. */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_MUM_PROD_ROM
value|0xc04
end_define

begin_comment
comment|/* enum: MUM user signatures& calibration rom partition. */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_MUM_USER_ROM
value|0xc05
end_define

begin_comment
comment|/* enum: MUM fuses and lockbits partition. */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_MUM_FUSELOCK
value|0xc06
end_define

begin_comment
comment|/* enum: Start of reserved value range (firmware may use for any purpose) */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_RESERVED_VALUES_MIN
value|0xff00
end_define

begin_comment
comment|/* enum: End of reserved value range (firmware may use for any purpose) */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_RESERVED_VALUES_MAX
value|0xfffd
end_define

begin_comment
comment|/* enum: Recovery partition map (provided if real map is missing or corrupt) */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_RECOVERY_MAP
value|0xfffe
end_define

begin_comment
comment|/* enum: Partition map (real map as stored in flash) */
end_comment

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_PARTITION_MAP
value|0xffff
end_define

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|NVRAM_PARTITION_TYPE_ID_WIDTH
value|16
end_define

begin_comment
comment|/* LICENSED_APP_ID structuredef */
end_comment

begin_define
define|#
directive|define
name|LICENSED_APP_ID_LEN
value|4
end_define

begin_define
define|#
directive|define
name|LICENSED_APP_ID_ID_OFST
value|0
end_define

begin_comment
comment|/* enum: OpenOnload */
end_comment

begin_define
define|#
directive|define
name|LICENSED_APP_ID_ONLOAD
value|0x1
end_define

begin_comment
comment|/* enum: PTP timestamping */
end_comment

begin_define
define|#
directive|define
name|LICENSED_APP_ID_PTP
value|0x2
end_define

begin_comment
comment|/* enum: SolarCapture Pro */
end_comment

begin_define
define|#
directive|define
name|LICENSED_APP_ID_SOLARCAPTURE_PRO
value|0x4
end_define

begin_comment
comment|/* enum: SolarSecure filter engine */
end_comment

begin_define
define|#
directive|define
name|LICENSED_APP_ID_SOLARSECURE
value|0x8
end_define

begin_comment
comment|/* enum: Performance monitor */
end_comment

begin_define
define|#
directive|define
name|LICENSED_APP_ID_PERF_MONITOR
value|0x10
end_define

begin_comment
comment|/* enum: SolarCapture Live */
end_comment

begin_define
define|#
directive|define
name|LICENSED_APP_ID_SOLARCAPTURE_LIVE
value|0x20
end_define

begin_comment
comment|/* enum: Capture SolarSystem */
end_comment

begin_define
define|#
directive|define
name|LICENSED_APP_ID_CAPTURE_SOLARSYSTEM
value|0x40
end_define

begin_comment
comment|/* enum: Network Access Control */
end_comment

begin_define
define|#
directive|define
name|LICENSED_APP_ID_NETWORK_ACCESS_CONTROL
value|0x80
end_define

begin_define
define|#
directive|define
name|LICENSED_APP_ID_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|LICENSED_APP_ID_ID_WIDTH
value|32
end_define

begin_comment
comment|/* TX_TIMESTAMP_EVENT structuredef */
end_comment

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_LEN
value|6
end_define

begin_comment
comment|/* lower 16 bits of timestamp data */
end_comment

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TSTAMP_DATA_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TSTAMP_DATA_LO_LEN
value|2
end_define

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TSTAMP_DATA_LO_LBN
value|0
end_define

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TSTAMP_DATA_LO_WIDTH
value|16
end_define

begin_comment
comment|/* Type of TX event, ordinary TX completion, low or high part of TX timestamp  */
end_comment

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TX_EV_TYPE_OFST
value|3
end_define

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TX_EV_TYPE_LEN
value|1
end_define

begin_comment
comment|/* enum: This is a TX completion event, not a timestamp */
end_comment

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TX_EV_COMPLETION
value|0x0
end_define

begin_comment
comment|/* enum: This is the low part of a TX timestamp event */
end_comment

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TX_EV_TSTAMP_LO
value|0x51
end_define

begin_comment
comment|/* enum: This is the high part of a TX timestamp event */
end_comment

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TX_EV_TSTAMP_HI
value|0x52
end_define

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TX_EV_TYPE_LBN
value|24
end_define

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TX_EV_TYPE_WIDTH
value|8
end_define

begin_comment
comment|/* upper 16 bits of timestamp data */
end_comment

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TSTAMP_DATA_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TSTAMP_DATA_HI_LEN
value|2
end_define

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TSTAMP_DATA_HI_LBN
value|32
end_define

begin_define
define|#
directive|define
name|TX_TIMESTAMP_EVENT_TSTAMP_DATA_HI_WIDTH
value|16
end_define

begin_comment
comment|/* RSS_MODE structuredef */
end_comment

begin_define
define|#
directive|define
name|RSS_MODE_LEN
value|1
end_define

begin_comment
comment|/* The RSS mode for a particular packet type is a value from 0 - 15 which can  * be considered as 4 bits selecting which fields are included in the hash. (A  * value 0 effectively disables RSS spreading for the packet type.) The YAML  * generation tools require this structure to be a whole number of bytes wide,  * but only 4 bits are relevant.  */
end_comment

begin_define
define|#
directive|define
name|RSS_MODE_HASH_SELECTOR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|RSS_MODE_HASH_SELECTOR_LEN
value|1
end_define

begin_define
define|#
directive|define
name|RSS_MODE_HASH_SRC_ADDR_LBN
value|0
end_define

begin_define
define|#
directive|define
name|RSS_MODE_HASH_SRC_ADDR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RSS_MODE_HASH_DST_ADDR_LBN
value|1
end_define

begin_define
define|#
directive|define
name|RSS_MODE_HASH_DST_ADDR_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RSS_MODE_HASH_SRC_PORT_LBN
value|2
end_define

begin_define
define|#
directive|define
name|RSS_MODE_HASH_SRC_PORT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RSS_MODE_HASH_DST_PORT_LBN
value|3
end_define

begin_define
define|#
directive|define
name|RSS_MODE_HASH_DST_PORT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|RSS_MODE_HASH_SELECTOR_LBN
value|0
end_define

begin_define
define|#
directive|define
name|RSS_MODE_HASH_SELECTOR_WIDTH
value|8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_READ_REGS  * Get a dump of the MCPU registers  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_REGS
value|0x50
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x50_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x50_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_READ_REGS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_REGS_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_READ_REGS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_REGS_OUT_LEN
value|308
end_define

begin_comment
comment|/* Whether the corresponding register entry contains a valid value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_REGS_OUT_MASK_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_REGS_OUT_MASK_LEN
value|16
end_define

begin_comment
comment|/* Same order as MIPS GDB (r0-r31, sr, lo, hi, bad, cause, 32 x float, fsr,  * fir, fp)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_REGS_OUT_REGS_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_REGS_OUT_REGS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_REGS_OUT_REGS_NUM
value|73
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_INIT_EVQ  * Set up an event queue according to the supplied parameters. The IN arguments  * end with an address for each 4k of host memory required to back the EVQ.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ
value|0x80
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x80_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x80_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_INIT_EVQ_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_LENMIN
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_LENMAX
value|548
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(36+8*(num))
end_define

begin_comment
comment|/* Size, in entries */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_SIZE_OFST
value|0
end_define

begin_comment
comment|/* Desired instance. Must be set to a specific instance, which is a function  * local queue index.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_INSTANCE_OFST
value|4
end_define

begin_comment
comment|/* The initial timer value. The load value is ignored if the timer mode is DIS.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_LOAD_OFST
value|8
end_define

begin_comment
comment|/* The reload value is ignored in one-shot modes */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_RELOAD_OFST
value|12
end_define

begin_comment
comment|/* tbd */
end_comment

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
name|MC_CMD_INIT_EVQ_IN_FLAG_INT_ARMD_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAG_INT_ARMD_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAG_CUT_THRU_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAG_CUT_THRU_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAG_RX_MERGE_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAG_RX_MERGE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAG_TX_MERGE_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_FLAG_TX_MERGE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_MODE_OFST
value|20
end_define

begin_comment
comment|/* enum: Disabled */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_MODE_DIS
value|0x0
end_define

begin_comment
comment|/* enum: Immediate */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_IMMED_START
value|0x1
end_define

begin_comment
comment|/* enum: Triggered */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_TRIG_START
value|0x2
end_define

begin_comment
comment|/* enum: Hold-off */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TMR_INT_HLDOFF
value|0x3
end_define

begin_comment
comment|/* Target EVQ for wakeups if in wakeup mode. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_TARGET_EVQ_OFST
value|24
end_define

begin_comment
comment|/* Target interrupt if in interrupting mode (note union with target EVQ). Use  * MC_CMD_RESOURCE_INSTANCE_ANY unless a specific one required for test  * purposes.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_IRQ_NUM_OFST
value|24
end_define

begin_comment
comment|/* Event Counter Mode. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_COUNT_MODE_OFST
value|28
end_define

begin_comment
comment|/* enum: Disabled */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_COUNT_MODE_DIS
value|0x0
end_define

begin_comment
comment|/* enum: Disabled */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_COUNT_MODE_RX
value|0x1
end_define

begin_comment
comment|/* enum: Disabled */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_COUNT_MODE_TX
value|0x2
end_define

begin_comment
comment|/* enum: Disabled */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_COUNT_MODE_RXTX
value|0x3
end_define

begin_comment
comment|/* Event queue packet count threshold. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_COUNT_THRSHLD_OFST
value|32
end_define

begin_comment
comment|/* 64-bit address of 4k of 4k-aligned host memory buffer */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_DMA_ADDR_OFST
value|36
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
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_EVQ_IN_DMA_ADDR_HI_OFST
value|40
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

begin_comment
comment|/* Only valid if INTRFLAG was true */
end_comment

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

begin_comment
comment|/* enum: No CRC. */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_NONE
value|0x0
end_define

begin_comment
comment|/* enum: CRC Fiber channel over ethernet. */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_FCOE
value|0x1
end_define

begin_comment
comment|/* enum: CRC (digest) iSCSI header only. */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_ISCSI_HDR
value|0x2
end_define

begin_comment
comment|/* enum: CRC (digest) iSCSI header and payload. */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_ISCSI
value|0x3
end_define

begin_comment
comment|/* enum: CRC Fiber channel over IP over ethernet. */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_FCOIPOE
value|0x4
end_define

begin_comment
comment|/* enum: CRC MPA. */
end_comment

begin_define
define|#
directive|define
name|QUEUE_CRC_MODE_MPA
value|0x5
end_define

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
comment|/* MC_CMD_INIT_RXQ  * set up a receive queue according to the supplied parameters. The IN  * arguments end with an address for each 4k of host memory required to back  * the RXQ.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ
value|0x81
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x81_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x81_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_INIT_RXQ_IN msgrequest: Legacy RXQ_INIT request. Use extended version  * in new code.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_LENMIN
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(28+8*(num))
end_define

begin_comment
comment|/* Size, in entries */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_SIZE_OFST
value|0
end_define

begin_comment
comment|/* The EVQ to send events to. This is an index originally specified to INIT_EVQ  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_TARGET_EVQ_OFST
value|4
end_define

begin_comment
comment|/* The value to put in the event data. Check hardware spec. for valid range. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_LABEL_OFST
value|8
end_define

begin_comment
comment|/* Desired instance. Must be set to a specific instance, which is a function  * local queue index.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_INSTANCE_OFST
value|12
end_define

begin_comment
comment|/* There will be more flags here. */
end_comment

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
name|MC_CMD_INIT_RXQ_IN_FLAG_TIMESTAMP_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_TIMESTAMP_WIDTH
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
name|MC_CMD_INIT_RXQ_IN_FLAG_CHAIN_LBN
value|7
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_CHAIN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_PREFIX_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_PREFIX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_DISABLE_SCATTER_LBN
value|9
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_FLAG_DISABLE_SCATTER_WIDTH
value|1
end_define

begin_comment
comment|/* Owner ID to use if in buffer mode (zero if physical) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_OWNER_ID_OFST
value|20
end_define

begin_comment
comment|/* The port ID associated with the v-adaptor which should contain this DMAQ. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_PORT_ID_OFST
value|24
end_define

begin_comment
comment|/* 64-bit address of 4k of 4k-aligned host memory buffer */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_DMA_ADDR_OFST
value|28
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
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_IN_DMA_ADDR_HI_OFST
value|32
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
comment|/* MC_CMD_INIT_RXQ_EXT_IN msgrequest: Extended RXQ_INIT with additional mode  * flags  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_LEN
value|544
end_define

begin_comment
comment|/* Size, in entries */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_SIZE_OFST
value|0
end_define

begin_comment
comment|/* The EVQ to send events to. This is an index originally specified to INIT_EVQ  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_TARGET_EVQ_OFST
value|4
end_define

begin_comment
comment|/* The value to put in the event data. Check hardware spec. for valid range. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_LABEL_OFST
value|8
end_define

begin_comment
comment|/* Desired instance. Must be set to a specific instance, which is a function  * local queue index.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_INSTANCE_OFST
value|12
end_define

begin_comment
comment|/* There will be more flags here. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAGS_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_BUFF_MODE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_BUFF_MODE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_HDR_SPLIT_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_HDR_SPLIT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_TIMESTAMP_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_TIMESTAMP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_CRC_MODE_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_CRC_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_CHAIN_LBN
value|7
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_CHAIN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_PREFIX_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_PREFIX_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_DISABLE_SCATTER_LBN
value|9
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_DISABLE_SCATTER_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_DMA_MODE_LBN
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_DMA_MODE_WIDTH
value|4
end_define

begin_comment
comment|/* enum: One packet per descriptor (for normal networking) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_SINGLE_PACKET
value|0x0
end_define

begin_comment
comment|/* enum: Pack multiple packets into large descriptors (for SolarCapture) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_PACKED_STREAM
value|0x1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_SNAPSHOT_MODE_LBN
value|14
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_SNAPSHOT_MODE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_PACKED_STREAM_BUFF_SIZE_LBN
value|15
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_PACKED_STREAM_BUFF_SIZE_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_PS_BUFF_1M
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_PS_BUFF_512K
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_PS_BUFF_256K
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_PS_BUFF_128K
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_PS_BUFF_64K
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_WANT_OUTER_CLASSES_LBN
value|18
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_FLAG_WANT_OUTER_CLASSES_WIDTH
value|1
end_define

begin_comment
comment|/* Owner ID to use if in buffer mode (zero if physical) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_OWNER_ID_OFST
value|20
end_define

begin_comment
comment|/* The port ID associated with the v-adaptor which should contain this DMAQ. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_PORT_ID_OFST
value|24
end_define

begin_comment
comment|/* 64-bit address of 4k of 4k-aligned host memory buffer */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_DMA_ADDR_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_DMA_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_DMA_ADDR_LO_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_DMA_ADDR_HI_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_DMA_ADDR_NUM
value|64
end_define

begin_comment
comment|/* Maximum length of packet to receive, if SNAPSHOT_MODE flag is set */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_IN_SNAPSHOT_LENGTH_OFST
value|540
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
comment|/* MC_CMD_INIT_RXQ_EXT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_RXQ_EXT_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_INIT_TXQ  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ
value|0x82
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x82_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x82_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_INIT_TXQ_IN msgrequest: Legacy INIT_TXQ request. Use extended version  * in new code.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_LENMIN
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(28+8*(num))
end_define

begin_comment
comment|/* Size, in entries */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_SIZE_OFST
value|0
end_define

begin_comment
comment|/* The EVQ to send events to. This is an index originally specified to  * INIT_EVQ.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_TARGET_EVQ_OFST
value|4
end_define

begin_comment
comment|/* The value to put in the event data. Check hardware spec. for valid range. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_LABEL_OFST
value|8
end_define

begin_comment
comment|/* Desired instance. Must be set to a specific instance, which is a function  * local queue index.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_INSTANCE_OFST
value|12
end_define

begin_comment
comment|/* There will be more flags here. */
end_comment

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
name|MC_CMD_INIT_TXQ_IN_FLAG_TIMESTAMP_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_TIMESTAMP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_PACER_BYPASS_LBN
value|9
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_PACER_BYPASS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_INNER_IP_CSUM_EN_LBN
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_INNER_IP_CSUM_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_INNER_TCP_CSUM_EN_LBN
value|11
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_FLAG_INNER_TCP_CSUM_EN_WIDTH
value|1
end_define

begin_comment
comment|/* Owner ID to use if in buffer mode (zero if physical) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_OWNER_ID_OFST
value|20
end_define

begin_comment
comment|/* The port ID associated with the v-adaptor which should contain this DMAQ. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_PORT_ID_OFST
value|24
end_define

begin_comment
comment|/* 64-bit address of 4k of 4k-aligned host memory buffer */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_DMA_ADDR_OFST
value|28
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
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_IN_DMA_ADDR_HI_OFST
value|32
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
comment|/* MC_CMD_INIT_TXQ_EXT_IN msgrequest: Extended INIT_TXQ with additional mode  * flags  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_LEN
value|544
end_define

begin_comment
comment|/* Size, in entries */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_SIZE_OFST
value|0
end_define

begin_comment
comment|/* The EVQ to send events to. This is an index originally specified to  * INIT_EVQ.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_TARGET_EVQ_OFST
value|4
end_define

begin_comment
comment|/* The value to put in the event data. Check hardware spec. for valid range. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_LABEL_OFST
value|8
end_define

begin_comment
comment|/* Desired instance. Must be set to a specific instance, which is a function  * local queue index.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_INSTANCE_OFST
value|12
end_define

begin_comment
comment|/* There will be more flags here. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAGS_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_BUFF_MODE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_BUFF_MODE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_IP_CSUM_DIS_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_IP_CSUM_DIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_TCP_CSUM_DIS_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_TCP_CSUM_DIS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_TCP_UDP_ONLY_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_TCP_UDP_ONLY_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_CRC_MODE_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_CRC_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_TIMESTAMP_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_TIMESTAMP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_PACER_BYPASS_LBN
value|9
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_PACER_BYPASS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_INNER_IP_CSUM_EN_LBN
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_INNER_IP_CSUM_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_INNER_TCP_CSUM_EN_LBN
value|11
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_FLAG_INNER_TCP_CSUM_EN_WIDTH
value|1
end_define

begin_comment
comment|/* Owner ID to use if in buffer mode (zero if physical) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_OWNER_ID_OFST
value|20
end_define

begin_comment
comment|/* The port ID associated with the v-adaptor which should contain this DMAQ. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_PORT_ID_OFST
value|24
end_define

begin_comment
comment|/* 64-bit address of 4k of 4k-aligned host memory buffer */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_DMA_ADDR_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_DMA_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_DMA_ADDR_LO_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_DMA_ADDR_HI_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_DMA_ADDR_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_DMA_ADDR_MAXNUM
value|64
end_define

begin_comment
comment|/* Flags related to Qbb flow control mode. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_QBB_FLAGS_OFST
value|540
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_QBB_ENABLE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_QBB_ENABLE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_QBB_PRIORITY_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_INIT_TXQ_EXT_IN_QBB_PRIORITY_WIDTH
value|3
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
comment|/* MC_CMD_FINI_EVQ  * Teardown an EVQ.  *  * All DMAQs or EVQs that point to the EVQ to tear down must be torn down first  * or the operation will fail with EBUSY  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_EVQ
value|0x83
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x83_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x83_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* Instance of EVQ to destroy. Should be the same instance as that previously  * passed to INIT_EVQ  */
end_comment

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
comment|/* MC_CMD_FINI_RXQ  * Teardown a RXQ.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_RXQ
value|0x84
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x84_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x84_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* Instance of RXQ to destroy */
end_comment

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
comment|/* MC_CMD_FINI_TXQ  * Teardown a TXQ.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FINI_TXQ
value|0x85
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x85_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x85_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* Instance of TXQ to destroy */
end_comment

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
comment|/* MC_CMD_DRIVER_EVENT  * Generate an event on an EVQ belonging to the function issuing the command.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRIVER_EVENT
value|0x86
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x86_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x86_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* Handle of target EVQ */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRIVER_EVENT_IN_EVQ_OFST
value|0
end_define

begin_comment
comment|/* Bits 0 - 63 of event */
end_comment

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
comment|/* MC_CMD_DRIVER_EVENT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DRIVER_EVENT_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PROXY_CMD  * Execute an arbitrary MCDI command on behalf of a different function, subject  * to security restrictions. The command to be proxied follows immediately  * afterward in the host buffer (or on the UART). This command supercedes  * MC_CMD_SET_FUNC, which remains available for Siena but now deprecated.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CMD
value|0x5b
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x5b_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x5b_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* The handle of the target function. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CMD_IN_TARGET_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CMD_IN_TARGET_PF_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CMD_IN_TARGET_PF_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CMD_IN_TARGET_VF_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CMD_IN_TARGET_VF_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CMD_IN_VF_NULL
value|0xffff
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* MC_CMD_PROXY_CMD_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CMD_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_PROXY_STATUS_BUFFER structuredef: Host memory status buffer used to  * manage proxied requests  */
end_comment

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_LEN
value|16
end_define

begin_comment
comment|/* Handle allocated by the firmware for this proxy transaction */
end_comment

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_HANDLE_OFST
value|0
end_define

begin_comment
comment|/* enum: An invalid handle. */
end_comment

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_HANDLE_INVALID
value|0x0
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_HANDLE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_HANDLE_WIDTH
value|32
end_define

begin_comment
comment|/* The requesting physical function number */
end_comment

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_PF_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_PF_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_PF_LBN
value|32
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_PF_WIDTH
value|16
end_define

begin_comment
comment|/* The requesting virtual function number. Set to VF_NULL if the target is a  * PF.  */
end_comment

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_VF_OFST
value|6
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_VF_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_VF_LBN
value|48
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_VF_WIDTH
value|16
end_define

begin_comment
comment|/* The target function RID. */
end_comment

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_RID_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_RID_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_RID_LBN
value|64
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_RID_WIDTH
value|16
end_define

begin_comment
comment|/* The status of the proxy as described in MC_CMD_PROXY_COMPLETE. */
end_comment

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_STATUS_OFST
value|10
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_STATUS_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_STATUS_LBN
value|80
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_STATUS_WIDTH
value|16
end_define

begin_comment
comment|/* If a request is authorized rather than carried out by the host, this is the  * elevated privilege mask granted to the requesting function.  */
end_comment

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_GRANTED_PRIVILEGES_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_GRANTED_PRIVILEGES_LBN
value|96
end_define

begin_define
define|#
directive|define
name|MC_PROXY_STATUS_BUFFER_GRANTED_PRIVILEGES_WIDTH
value|32
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PROXY_CONFIGURE  * Enable/disable authorization of MCDI requests from unprivileged functions by  * a designated admin function  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE
value|0x58
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x58_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x58_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_PROXY_CONFIGURE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_LEN
value|108
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_ENABLE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_ENABLE_WIDTH
value|1
end_define

begin_comment
comment|/* Host provides a contiguous memory buffer that contains at least NUM_BLOCKS  * of blocks, each of the size REQUEST_BLOCK_SIZE.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_STATUS_BUFF_ADDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_STATUS_BUFF_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_STATUS_BUFF_ADDR_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_STATUS_BUFF_ADDR_HI_OFST
value|8
end_define

begin_comment
comment|/* Must be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_STATUS_BLOCK_SIZE_OFST
value|12
end_define

begin_comment
comment|/* Host provides a contiguous memory buffer that contains at least NUM_BLOCKS  * of blocks, each of the size REPLY_BLOCK_SIZE.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_REQUEST_BUFF_ADDR_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_REQUEST_BUFF_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_REQUEST_BUFF_ADDR_LO_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_REQUEST_BUFF_ADDR_HI_OFST
value|20
end_define

begin_comment
comment|/* Must be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_REQUEST_BLOCK_SIZE_OFST
value|24
end_define

begin_comment
comment|/* Host provides a contiguous memory buffer that contains at least NUM_BLOCKS  * of blocks, each of the size STATUS_BLOCK_SIZE. This buffer is only needed if  * host intends to complete proxied operations by using MC_CMD_PROXY_CMD.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_REPLY_BUFF_ADDR_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_REPLY_BUFF_ADDR_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_REPLY_BUFF_ADDR_LO_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_REPLY_BUFF_ADDR_HI_OFST
value|32
end_define

begin_comment
comment|/* Must be a power of 2, or zero if this buffer is not provided */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_REPLY_BLOCK_SIZE_OFST
value|36
end_define

begin_comment
comment|/* Applies to all three buffers */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_NUM_BLOCKS_OFST
value|40
end_define

begin_comment
comment|/* A bit mask defining which MCDI operations may be proxied */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_ALLOWED_MCDI_MASK_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_IN_ALLOWED_MCDI_MASK_LEN
value|64
end_define

begin_comment
comment|/* MC_CMD_PROXY_CONFIGURE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_CONFIGURE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PROXY_COMPLETE  * Tells FW that a requested proxy operation has either been completed (by  * using MC_CMD_PROXY_CMD) or authorized/declined. May only be sent by the  * function that enabled proxying/authorization (by using  * MC_CMD_PROXY_CONFIGURE).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_COMPLETE
value|0x5f
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x5f_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x5f_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_PROXY_COMPLETE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_COMPLETE_IN_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_COMPLETE_IN_BLOCK_INDEX_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_COMPLETE_IN_STATUS_OFST
value|4
end_define

begin_comment
comment|/* enum: The operation has been completed by using MC_CMD_PROXY_CMD, the reply  * is stored in the REPLY_BUFF.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_COMPLETE_IN_COMPLETE
value|0x0
end_define

begin_comment
comment|/* enum: The operation has been authorized. The originating function may now  * try again.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_COMPLETE_IN_AUTHORIZED
value|0x1
end_define

begin_comment
comment|/* enum: The operation has been declined. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_COMPLETE_IN_DECLINED
value|0x2
end_define

begin_comment
comment|/* enum: The authorization failed because the relevant application did not  * respond in time.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_COMPLETE_IN_TIMEDOUT
value|0x3
end_define

begin_define
define|#
directive|define
name|MC_CMD_PROXY_COMPLETE_IN_HANDLE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_PROXY_COMPLETE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROXY_COMPLETE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_ALLOC_BUFTBL_CHUNK  * Allocate a set of buffer table entries using the specified owner ID. This  * operation allocates the required buffer table entries (and fails if it  * cannot do so). The buffer table entries will initially be zeroed.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_BUFTBL_CHUNK
value|0x87
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x87_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x87_PRIVILEGE_CTG
value|SRIOV_CTG_ONLOAD
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

begin_comment
comment|/* Owner ID to use */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_BUFTBL_CHUNK_IN_OWNER_OFST
value|0
end_define

begin_comment
comment|/* Size of buffer table pages to use, in bytes (note that only a few values are  * legal on any specific hardware).  */
end_comment

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

begin_comment
comment|/* Buffer table IDs for use in DMA descriptors. */
end_comment

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
comment|/* MC_CMD_PROGRAM_BUFTBL_ENTRIES  * Reprogram a set of buffer table entries in the specified chunk.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES
value|0x88
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x88_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x88_PRIVILEGE_CTG
value|SRIOV_CTG_ONLOAD
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
value|268
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

begin_comment
comment|/* ID */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_FIRSTID_OFST
value|4
end_define

begin_comment
comment|/* Num entries */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PROGRAM_BUFTBL_ENTRIES_IN_NUMENTRIES_OFST
value|8
end_define

begin_comment
comment|/* Buffer table entry address */
end_comment

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
value|32
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
comment|/* MC_CMD_FREE_BUFTBL_CHUNK  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_BUFTBL_CHUNK
value|0x89
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x89_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x89_PRIVILEGE_CTG
value|SRIOV_CTG_ONLOAD
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
comment|/* PORT_CONFIG_ENTRY structuredef */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_LEN
value|16
end_define

begin_comment
comment|/* External port number (label) */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_EXT_NUMBER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_EXT_NUMBER_LEN
value|1
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_EXT_NUMBER_LBN
value|0
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_EXT_NUMBER_WIDTH
value|8
end_define

begin_comment
comment|/* Port core location */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_CORE_OFST
value|1
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_CORE_LEN
value|1
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_STANDALONE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_MASTER
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_SLAVE
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_CORE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_CORE_WIDTH
value|8
end_define

begin_comment
comment|/* Internal number (HW resource) relative to the core */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_INT_NUMBER_OFST
value|2
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_INT_NUMBER_LEN
value|1
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_INT_NUMBER_LBN
value|16
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_INT_NUMBER_WIDTH
value|8
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_RSVD_OFST
value|3
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_RSVD_LEN
value|1
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_RSVD_LBN
value|24
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_RSVD_WIDTH
value|8
end_define

begin_comment
comment|/* Bitmask of KR lanes used by the port */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_LANES_OFST
value|4
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_LANES_LBN
value|32
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_LANES_WIDTH
value|32
end_define

begin_comment
comment|/* Port capabilities (MC_CMD_PHY_CAP_*) */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_SUPPORTED_CAPS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_SUPPORTED_CAPS_LBN
value|64
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_SUPPORTED_CAPS_WIDTH
value|32
end_define

begin_comment
comment|/* Reserved (align to 16 bytes) */
end_comment

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_RSVD2_OFST
value|12
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_RSVD2_LBN
value|96
end_define

begin_define
define|#
directive|define
name|PORT_CONFIG_ENTRY_RSVD2_WIDTH
value|32
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FILTER_OP  * Multiplexed MCDI call for filter operations  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP
value|0x8a
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x8a_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x8a_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_FILTER_OP_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_LEN
value|108
end_define

begin_comment
comment|/* identifies the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OP_OFST
value|0
end_define

begin_comment
comment|/* enum: single-recipient filter insert */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OP_INSERT
value|0x0
end_define

begin_comment
comment|/* enum: single-recipient filter remove */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OP_REMOVE
value|0x1
end_define

begin_comment
comment|/* enum: multi-recipient filter subscribe */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OP_SUBSCRIBE
value|0x2
end_define

begin_comment
comment|/* enum: multi-recipient filter unsubscribe */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OP_UNSUBSCRIBE
value|0x3
end_define

begin_comment
comment|/* enum: replace one recipient with another (warning - the filter handle may  * change)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OP_REPLACE
value|0x4
end_define

begin_comment
comment|/* filter handle (for remove / unsubscribe operations) */
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
name|MC_CMD_FILTER_OP_IN_HANDLE_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_HANDLE_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_HANDLE_HI_OFST
value|8
end_define

begin_comment
comment|/* The port ID associated with the v-adaptor which should contain this filter.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_PORT_ID_OFST
value|12
end_define

begin_comment
comment|/* fields to include in match criteria */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_FIELDS_OFST
value|16
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
name|MC_CMD_FILTER_OP_IN_MATCH_UNKNOWN_MCAST_DST_LBN
value|30
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_UNKNOWN_MCAST_DST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_UNKNOWN_UCAST_DST_LBN
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_MATCH_UNKNOWN_UCAST_DST_WIDTH
value|1
end_define

begin_comment
comment|/* receive destination */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_OFST
value|20
end_define

begin_comment
comment|/* enum: drop packets */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_DROP
value|0x0
end_define

begin_comment
comment|/* enum: receive to host */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_HOST
value|0x1
end_define

begin_comment
comment|/* enum: receive to MC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_MC
value|0x2
end_define

begin_comment
comment|/* enum: loop back to TXDP 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_TX0
value|0x3
end_define

begin_comment
comment|/* enum: loop back to TXDP 1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_DEST_TX1
value|0x4
end_define

begin_comment
comment|/* receive queue handle (for multiple queue modes, this is the base queue) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_QUEUE_OFST
value|24
end_define

begin_comment
comment|/* receive mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_MODE_OFST
value|28
end_define

begin_comment
comment|/* enum: receive to just the specified queue */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_MODE_SIMPLE
value|0x0
end_define

begin_comment
comment|/* enum: receive to multiple queues using RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_MODE_RSS
value|0x1
end_define

begin_comment
comment|/* enum: receive to multiple queues using .1p mapping */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_MODE_DOT1P_MAPPING
value|0x2
end_define

begin_comment
comment|/* enum: install a filter entry that will never match; for test purposes only  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_MODE_TEST_NEVER_MATCH
value|0x80000000
end_define

begin_comment
comment|/* RSS context (for RX_MODE_RSS) or .1p mapping handle (for  * RX_MODE_DOT1P_MAPPING), as returned by MC_CMD_RSS_CONTEXT_ALLOC or  * MC_CMD_DOT1P_MAPPING_ALLOC.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_RX_CONTEXT_OFST
value|32
end_define

begin_comment
comment|/* transmit domain (reserved; set to 0) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_TX_DOMAIN_OFST
value|36
end_define

begin_comment
comment|/* transmit destination (either set the MAC and/or PM bits for explicit  * control, or set this field to TX_DEST_DEFAULT for sensible default  * behaviour)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_TX_DEST_OFST
value|40
end_define

begin_comment
comment|/* enum: request default behaviour (based on filter type) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_TX_DEST_DEFAULT
value|0xffffffff
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

begin_comment
comment|/* source MAC address to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_MAC_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_MAC_LEN
value|6
end_define

begin_comment
comment|/* source port to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_PORT_OFST
value|50
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_PORT_LEN
value|2
end_define

begin_comment
comment|/* destination MAC address to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_MAC_OFST
value|52
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_MAC_LEN
value|6
end_define

begin_comment
comment|/* destination port to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_PORT_OFST
value|58
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_PORT_LEN
value|2
end_define

begin_comment
comment|/* Ethernet type to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_ETHER_TYPE_OFST
value|60
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_ETHER_TYPE_LEN
value|2
end_define

begin_comment
comment|/* Inner VLAN tag to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_INNER_VLAN_OFST
value|62
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_INNER_VLAN_LEN
value|2
end_define

begin_comment
comment|/* Outer VLAN tag to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OUTER_VLAN_OFST
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_OUTER_VLAN_LEN
value|2
end_define

begin_comment
comment|/* IP protocol to match (in low byte; set high byte to 0) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_IP_PROTO_OFST
value|66
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_IP_PROTO_LEN
value|2
end_define

begin_comment
comment|/* Firmware defined register 0 to match (reserved; set to 0) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_FWDEF0_OFST
value|68
end_define

begin_comment
comment|/* Firmware defined register 1 to match (reserved; set to 0) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_FWDEF1_OFST
value|72
end_define

begin_comment
comment|/* source IP address to match (as bytes in network order; set last 12 bytes to  * 0 for IPv4 address)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_IP_OFST
value|76
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_SRC_IP_LEN
value|16
end_define

begin_comment
comment|/* destination IP address to match (as bytes in network order; set last 12  * bytes to 0 for IPv4 address)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_IP_OFST
value|92
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_IN_DST_IP_LEN
value|16
end_define

begin_comment
comment|/* MC_CMD_FILTER_OP_EXT_IN msgrequest: Extension to MC_CMD_FILTER_OP_IN to  * include handling of VXLAN/NVGRE encapsulated frame filtering (which is  * supported on Medford only).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_LEN
value|172
end_define

begin_comment
comment|/* identifies the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_OP_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_FILTER_OP_IN/OP */
end_comment

begin_comment
comment|/* filter handle (for remove / unsubscribe operations) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_HANDLE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_HANDLE_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_HANDLE_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_HANDLE_HI_OFST
value|8
end_define

begin_comment
comment|/* The port ID associated with the v-adaptor which should contain this filter.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_PORT_ID_OFST
value|12
end_define

begin_comment
comment|/* fields to include in match criteria */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_FIELDS_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_SRC_IP_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_SRC_IP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_DST_IP_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_DST_IP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_SRC_MAC_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_SRC_MAC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_SRC_PORT_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_SRC_PORT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_DST_MAC_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_DST_MAC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_DST_PORT_LBN
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_DST_PORT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_ETHER_TYPE_LBN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_ETHER_TYPE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_INNER_VLAN_LBN
value|7
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_INNER_VLAN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_OUTER_VLAN_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_OUTER_VLAN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IP_PROTO_LBN
value|9
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IP_PROTO_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_FWDEF0_LBN
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_FWDEF0_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_VNI_OR_VSID_LBN
value|11
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_VNI_OR_VSID_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_SRC_IP_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_SRC_IP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_DST_IP_LBN
value|13
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_DST_IP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_SRC_MAC_LBN
value|14
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_SRC_MAC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_SRC_PORT_LBN
value|15
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_SRC_PORT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_DST_MAC_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_DST_MAC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_DST_PORT_LBN
value|17
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_DST_PORT_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_ETHER_TYPE_LBN
value|18
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_ETHER_TYPE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_INNER_VLAN_LBN
value|19
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_INNER_VLAN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_OUTER_VLAN_LBN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_OUTER_VLAN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_IP_PROTO_LBN
value|21
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_IP_PROTO_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_FWDEF0_LBN
value|22
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_FWDEF0_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_FWDEF1_LBN
value|23
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_FWDEF1_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_UNKNOWN_MCAST_DST_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_UNKNOWN_MCAST_DST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_UNKNOWN_UCAST_DST_LBN
value|25
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_IFRM_UNKNOWN_UCAST_DST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_UNKNOWN_MCAST_DST_LBN
value|30
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_UNKNOWN_MCAST_DST_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_UNKNOWN_UCAST_DST_LBN
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_MATCH_UNKNOWN_UCAST_DST_WIDTH
value|1
end_define

begin_comment
comment|/* receive destination */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_DEST_OFST
value|20
end_define

begin_comment
comment|/* enum: drop packets */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_DEST_DROP
value|0x0
end_define

begin_comment
comment|/* enum: receive to host */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_DEST_HOST
value|0x1
end_define

begin_comment
comment|/* enum: receive to MC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_DEST_MC
value|0x2
end_define

begin_comment
comment|/* enum: loop back to TXDP 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_DEST_TX0
value|0x3
end_define

begin_comment
comment|/* enum: loop back to TXDP 1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_DEST_TX1
value|0x4
end_define

begin_comment
comment|/* receive queue handle (for multiple queue modes, this is the base queue) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_QUEUE_OFST
value|24
end_define

begin_comment
comment|/* receive mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_MODE_OFST
value|28
end_define

begin_comment
comment|/* enum: receive to just the specified queue */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_MODE_SIMPLE
value|0x0
end_define

begin_comment
comment|/* enum: receive to multiple queues using RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_MODE_RSS
value|0x1
end_define

begin_comment
comment|/* enum: receive to multiple queues using .1p mapping */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_MODE_DOT1P_MAPPING
value|0x2
end_define

begin_comment
comment|/* enum: install a filter entry that will never match; for test purposes only  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_MODE_TEST_NEVER_MATCH
value|0x80000000
end_define

begin_comment
comment|/* RSS context (for RX_MODE_RSS) or .1p mapping handle (for  * RX_MODE_DOT1P_MAPPING), as returned by MC_CMD_RSS_CONTEXT_ALLOC or  * MC_CMD_DOT1P_MAPPING_ALLOC.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_RX_CONTEXT_OFST
value|32
end_define

begin_comment
comment|/* transmit domain (reserved; set to 0) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_TX_DOMAIN_OFST
value|36
end_define

begin_comment
comment|/* transmit destination (either set the MAC and/or PM bits for explicit  * control, or set this field to TX_DEST_DEFAULT for sensible default  * behaviour)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_TX_DEST_OFST
value|40
end_define

begin_comment
comment|/* enum: request default behaviour (based on filter type) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_TX_DEST_DEFAULT
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_TX_DEST_MAC_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_TX_DEST_MAC_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_TX_DEST_PM_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_TX_DEST_PM_WIDTH
value|1
end_define

begin_comment
comment|/* source MAC address to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_SRC_MAC_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_SRC_MAC_LEN
value|6
end_define

begin_comment
comment|/* source port to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_SRC_PORT_OFST
value|50
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_SRC_PORT_LEN
value|2
end_define

begin_comment
comment|/* destination MAC address to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_DST_MAC_OFST
value|52
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_DST_MAC_LEN
value|6
end_define

begin_comment
comment|/* destination port to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_DST_PORT_OFST
value|58
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_DST_PORT_LEN
value|2
end_define

begin_comment
comment|/* Ethernet type to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_ETHER_TYPE_OFST
value|60
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_ETHER_TYPE_LEN
value|2
end_define

begin_comment
comment|/* Inner VLAN tag to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_INNER_VLAN_OFST
value|62
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_INNER_VLAN_LEN
value|2
end_define

begin_comment
comment|/* Outer VLAN tag to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_OUTER_VLAN_OFST
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_OUTER_VLAN_LEN
value|2
end_define

begin_comment
comment|/* IP protocol to match (in low byte; set high byte to 0) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IP_PROTO_OFST
value|66
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IP_PROTO_LEN
value|2
end_define

begin_comment
comment|/* Firmware defined register 0 to match (reserved; set to 0) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_FWDEF0_OFST
value|68
end_define

begin_comment
comment|/* VNI (for VXLAN/Geneve, when IP protocol is UDP) or VSID (for NVGRE, when IP  * protocol is GRE) to match (as bytes in network order; set last byte to 0 for  * VXLAN/NVGRE, or 1 for Geneve)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VNI_OR_VSID_OFST
value|72
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VNI_VALUE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VNI_VALUE_WIDTH
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VNI_TYPE_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VNI_TYPE_WIDTH
value|8
end_define

begin_comment
comment|/* enum: Match VXLAN traffic with this VNI */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VNI_TYPE_VXLAN
value|0x0
end_define

begin_comment
comment|/* enum: Match Geneve traffic with this VNI */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VNI_TYPE_GENEVE
value|0x1
end_define

begin_comment
comment|/* enum: Reserved for experimental development use */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VNI_TYPE_EXPERIMENTAL
value|0xfe
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VSID_VALUE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VSID_VALUE_WIDTH
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VSID_TYPE_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VSID_TYPE_WIDTH
value|8
end_define

begin_comment
comment|/* enum: Match NVGRE traffic with this VSID */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_VSID_TYPE_NVGRE
value|0x0
end_define

begin_comment
comment|/* source IP address to match (as bytes in network order; set last 12 bytes to  * 0 for IPv4 address)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_SRC_IP_OFST
value|76
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_SRC_IP_LEN
value|16
end_define

begin_comment
comment|/* destination IP address to match (as bytes in network order; set last 12  * bytes to 0 for IPv4 address)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_DST_IP_OFST
value|92
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_DST_IP_LEN
value|16
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame source MAC address to match (as bytes in network  * order)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_SRC_MAC_OFST
value|108
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_SRC_MAC_LEN
value|6
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame source port to match (as bytes in network order) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_SRC_PORT_OFST
value|114
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_SRC_PORT_LEN
value|2
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame destination MAC address to match (as bytes in  * network order)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_DST_MAC_OFST
value|116
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_DST_MAC_LEN
value|6
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame destination port to match (as bytes in network  * order)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_DST_PORT_OFST
value|122
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_DST_PORT_LEN
value|2
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame Ethernet type to match (as bytes in network order)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_ETHER_TYPE_OFST
value|124
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_ETHER_TYPE_LEN
value|2
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame Inner VLAN tag to match (as bytes in network order)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_INNER_VLAN_OFST
value|126
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_INNER_VLAN_LEN
value|2
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame Outer VLAN tag to match (as bytes in network order)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_OUTER_VLAN_OFST
value|128
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_OUTER_VLAN_LEN
value|2
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame IP protocol to match (in low byte; set high byte to  * 0)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_IP_PROTO_OFST
value|130
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_IP_PROTO_LEN
value|2
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame Firmware defined register 0 to match (reserved; set  * to 0)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_FWDEF0_OFST
value|132
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame Firmware defined register 1 to match (reserved; set  * to 0)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_FWDEF1_OFST
value|136
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame source IP address to match (as bytes in network  * order; set last 12 bytes to 0 for IPv4 address)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_SRC_IP_OFST
value|140
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_SRC_IP_LEN
value|16
end_define

begin_comment
comment|/* VXLAN/NVGRE inner frame destination IP address to match (as bytes in network  * order; set last 12 bytes to 0 for IPv4 address)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_DST_IP_OFST
value|156
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_IN_IFRM_DST_IP_LEN
value|16
end_define

begin_comment
comment|/* MC_CMD_FILTER_OP_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_LEN
value|12
end_define

begin_comment
comment|/* identifies the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_OP_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_FILTER_OP_IN/OP */
end_comment

begin_comment
comment|/* Returned filter handle (for insert / subscribe operations). Note that these  * handles should be considered opaque to the host, although a value of  * 0xFFFFFFFF_FFFFFFFF is guaranteed never to be a valid handle.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_HANDLE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_HANDLE_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_HANDLE_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_HANDLE_HI_OFST
value|8
end_define

begin_comment
comment|/* enum: guaranteed invalid filter handle (low 32 bits) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_HANDLE_LO_INVALID
value|0xffffffff
end_define

begin_comment
comment|/* enum: guaranteed invalid filter handle (high 32 bits) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_OUT_HANDLE_HI_INVALID
value|0xffffffff
end_define

begin_comment
comment|/* MC_CMD_FILTER_OP_EXT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_OUT_LEN
value|12
end_define

begin_comment
comment|/* identifies the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_OUT_OP_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_FILTER_OP_EXT_IN/OP */
end_comment

begin_comment
comment|/* Returned filter handle (for insert / subscribe operations). Note that these  * handles should be considered opaque to the host, although a value of  * 0xFFFFFFFF_FFFFFFFF is guaranteed never to be a valid handle.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_OUT_HANDLE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_OUT_HANDLE_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_OUT_HANDLE_LO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_FILTER_OP_EXT_OUT_HANDLE_HI_OFST
value|8
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_FILTER_OP_OUT/HANDLE */
end_comment

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PARSER_DISP_INFO  * Get information related to the parser-dispatcher subsystem  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO
value|0xe4
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xe4_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xe4_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_PARSER_DISP_INFO_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_IN_LEN
value|4
end_define

begin_comment
comment|/* identifies the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_IN_OP_OFST
value|0
end_define

begin_comment
comment|/* enum: read the list of supported RX filter matches */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_IN_OP_GET_SUPPORTED_RX_MATCHES
value|0x1
end_define

begin_comment
comment|/* enum: read flags indicating restrictions on filter insertion for the calling  * client  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_IN_OP_GET_RESTRICTIONS
value|0x2
end_define

begin_comment
comment|/* MC_CMD_GET_PARSER_DISP_INFO_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_OUT_LENMIN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(8+4*(num))
end_define

begin_comment
comment|/* identifies the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_OUT_OP_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_GET_PARSER_DISP_INFO_IN/OP */
end_comment

begin_comment
comment|/* number of supported match types */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_OUT_NUM_SUPPORTED_MATCHES_OFST
value|4
end_define

begin_comment
comment|/* array of supported match types (valid MATCH_FIELDS values for  * MC_CMD_FILTER_OP) sorted in decreasing priority order  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_OUT_SUPPORTED_MATCHES_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_OUT_SUPPORTED_MATCHES_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_OUT_SUPPORTED_MATCHES_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_INFO_OUT_SUPPORTED_MATCHES_MAXNUM
value|61
end_define

begin_comment
comment|/* MC_CMD_GET_PARSER_DISP_RESTRICTIONS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_RESTRICTIONS_OUT_LEN
value|8
end_define

begin_comment
comment|/* identifies the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_RESTRICTIONS_OUT_OP_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_GET_PARSER_DISP_INFO_IN/OP */
end_comment

begin_comment
comment|/* bitfield of filter insertion restrictions */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_RESTRICTIONS_OUT_RESTRICTION_FLAGS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_RESTRICTIONS_OUT_DST_IP_MCAST_ONLY_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_RESTRICTIONS_OUT_DST_IP_MCAST_ONLY_WIDTH
value|1
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PARSER_DISP_RW  * Direct read/write of parser-dispatcher state (DICPUs and LUE) for debugging  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW
value|0xe5
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xe5_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xe5_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_PARSER_DISP_RW_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_LEN
value|32
end_define

begin_comment
comment|/* identifies the target of the operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_TARGET_OFST
value|0
end_define

begin_comment
comment|/* enum: RX dispatcher CPU */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_RX_DICPU
value|0x0
end_define

begin_comment
comment|/* enum: TX dispatcher CPU */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_TX_DICPU
value|0x1
end_define

begin_comment
comment|/* enum: Lookup engine (with original metadata format) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_LUE
value|0x2
end_define

begin_comment
comment|/* enum: Lookup engine (with requested metadata format) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_LUE_VERSIONED_METADATA
value|0x3
end_define

begin_comment
comment|/* identifies the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_OP_OFST
value|4
end_define

begin_comment
comment|/* enum: read a word of DICPU DMEM or a LUE entry */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_READ
value|0x0
end_define

begin_comment
comment|/* enum: write a word of DICPU DMEM or a LUE entry */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_WRITE
value|0x1
end_define

begin_comment
comment|/* enum: read-modify-write a word of DICPU DMEM (not valid for LUE) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_RMW
value|0x2
end_define

begin_comment
comment|/* data memory address or LUE index */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_ADDRESS_OFST
value|8
end_define

begin_comment
comment|/* value to write (for DMEM writes) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_DMEM_WRITE_VALUE_OFST
value|12
end_define

begin_comment
comment|/* XOR value (for DMEM read-modify-writes: new = (old& mask) ^ value) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_DMEM_RMW_XOR_VALUE_OFST
value|12
end_define

begin_comment
comment|/* AND mask (for DMEM read-modify-writes: new = (old& mask) ^ value) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_DMEM_RMW_AND_MASK_OFST
value|16
end_define

begin_comment
comment|/* metadata format (for LUE reads using LUE_VERSIONED_METADATA) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_LUE_READ_METADATA_VERSION_OFST
value|12
end_define

begin_comment
comment|/* value to write (for LUE writes) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_LUE_WRITE_VALUE_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_IN_LUE_WRITE_VALUE_LEN
value|20
end_define

begin_comment
comment|/* MC_CMD_PARSER_DISP_RW_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_OUT_LEN
value|52
end_define

begin_comment
comment|/* value read (for DMEM reads) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_OUT_DMEM_READ_VALUE_OFST
value|0
end_define

begin_comment
comment|/* value read (for LUE reads) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_OUT_LUE_READ_VALUE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_OUT_LUE_READ_VALUE_LEN
value|20
end_define

begin_comment
comment|/* up to 8 32-bit words of additional soft state from the LUE manager (the  * exact content is firmware-dependent and intended only for debug use)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_OUT_LUE_MGR_STATE_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_PARSER_DISP_RW_OUT_LUE_MGR_STATE_LEN
value|32
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PF_COUNT  * Get number of PFs on the device.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PF_COUNT
value|0xb6
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xb6_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xb6_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* Identifies the number of PFs on the device. */
end_comment

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
comment|/* MC_CMD_SET_PF_COUNT  * Set number of PFs on the device.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PF_COUNT
value|0xb7
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

begin_comment
comment|/* New number of PFs on the device. */
end_comment

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
comment|/* MC_CMD_GET_PORT_ASSIGNMENT  * Get port assignment for current PCI function.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_ASSIGNMENT
value|0xb8
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xb8_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xb8_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* Identifies the port assignment for this function. */
end_comment

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
comment|/* MC_CMD_SET_PORT_ASSIGNMENT  * Set port assignment for current PCI function.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_ASSIGNMENT
value|0xb9
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xb9_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xb9_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Identifies the port assignment for this function. */
end_comment

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
comment|/* MC_CMD_ALLOC_VIS  * Allocate VIs for current PCI function.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS
value|0x8b
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x8b_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x8b_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_ALLOC_VIS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_IN_LEN
value|8
end_define

begin_comment
comment|/* The minimum number of VIs that is acceptable */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_IN_MIN_VI_COUNT_OFST
value|0
end_define

begin_comment
comment|/* The maximum number of VIs that would be useful */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_IN_MAX_VI_COUNT_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_ALLOC_VIS_OUT msgresponse: Huntington-compatible VI_ALLOC request.  * Use extended version in new code.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_OUT_LEN
value|8
end_define

begin_comment
comment|/* The number of VIs allocated on this function */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_OUT_VI_COUNT_OFST
value|0
end_define

begin_comment
comment|/* The base absolute VI number allocated to this function. Required to  * correctly interpret wakeup events.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_OUT_VI_BASE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_ALLOC_VIS_EXT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_EXT_OUT_LEN
value|12
end_define

begin_comment
comment|/* The number of VIs allocated on this function */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_EXT_OUT_VI_COUNT_OFST
value|0
end_define

begin_comment
comment|/* The base absolute VI number allocated to this function. Required to  * correctly interpret wakeup events.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_EXT_OUT_VI_BASE_OFST
value|4
end_define

begin_comment
comment|/* Function's port vi_shift value (always 0 on Huntington) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_VIS_EXT_OUT_VI_SHIFT_OFST
value|8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FREE_VIS  * Free VIs for current PCI function. Any linked PIO buffers will be unlinked,  * but not freed.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_VIS
value|0x8c
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x8c_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x8c_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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
comment|/* MC_CMD_GET_SRIOV_CFG  * Get SRIOV config for this PF.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG
value|0xba
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xba_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xba_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* Number of VFs currently enabled. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG_OUT_VF_CURRENT_OFST
value|0
end_define

begin_comment
comment|/* Max number of VFs before sriov stride and offset may need to be changed. */
end_comment

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

begin_comment
comment|/* RID offset of first VF from PF. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_SRIOV_CFG_OUT_VF_OFFSET_OFST
value|12
end_define

begin_comment
comment|/* RID offset of each subsequent VF from the previous. */
end_comment

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
comment|/* MC_CMD_SET_SRIOV_CFG  * Set SRIOV config for this PF.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG
value|0xbb
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xbb_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xbb_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
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

begin_comment
comment|/* Number of VFs currently enabled. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG_IN_VF_CURRENT_OFST
value|0
end_define

begin_comment
comment|/* Max number of VFs before sriov stride and offset may need to be changed. */
end_comment

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

begin_comment
comment|/* RID offset of first VF from PF, or 0 for no change, or  * MC_CMD_RESOURCE_INSTANCE_ANY to allow the system to allocate an offset.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_SRIOV_CFG_IN_VF_OFFSET_OFST
value|12
end_define

begin_comment
comment|/* RID offset of each subsequent VF from the previous, 0 for no change, or  * MC_CMD_RESOURCE_INSTANCE_ANY to allow the system to allocate a stride.  */
end_comment

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
comment|/* MC_CMD_GET_VI_ALLOC_INFO  * Get information about number of VI's and base VI number allocated to this  * function.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_ALLOC_INFO
value|0x8d
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x8d_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x8d_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_VI_ALLOC_INFO_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_ALLOC_INFO_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_VI_ALLOC_INFO_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_ALLOC_INFO_OUT_LEN
value|12
end_define

begin_comment
comment|/* The number of VIs allocated on this function */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_ALLOC_INFO_OUT_VI_COUNT_OFST
value|0
end_define

begin_comment
comment|/* The base absolute VI number allocated to this function. Required to  * correctly interpret wakeup events.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_ALLOC_INFO_OUT_VI_BASE_OFST
value|4
end_define

begin_comment
comment|/* Function's port vi_shift value (always 0 on Huntington) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_ALLOC_INFO_OUT_VI_SHIFT_OFST
value|8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DUMP_VI_STATE  * For CmdClient use. Dump pertinent information on a specific absolute VI.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE
value|0x8e
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x8e_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x8e_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_DUMP_VI_STATE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_IN_LEN
value|4
end_define

begin_comment
comment|/* The VI number to query. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_IN_VI_NUMBER_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_DUMP_VI_STATE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_LEN
value|96
end_define

begin_comment
comment|/* The PF part of the function owning this VI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_OWNER_PF_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_OWNER_PF_LEN
value|2
end_define

begin_comment
comment|/* The VF part of the function owning this VI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_OWNER_VF_OFST
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_OWNER_VF_LEN
value|2
end_define

begin_comment
comment|/* Base of VIs allocated to this function. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_FUNC_VI_BASE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_FUNC_VI_BASE_LEN
value|2
end_define

begin_comment
comment|/* Count of VIs allocated to the owner function. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_FUNC_VI_COUNT_OFST
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_FUNC_VI_COUNT_LEN
value|2
end_define

begin_comment
comment|/* Base interrupt vector allocated to this function. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_FUNC_VECTOR_BASE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_FUNC_VECTOR_BASE_LEN
value|2
end_define

begin_comment
comment|/* Number of interrupt vectors allocated to this function. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_FUNC_VECTOR_COUNT_OFST
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_FUNC_VECTOR_COUNT_LEN
value|2
end_define

begin_comment
comment|/* Raw evq ptr table data. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EVQ_PTR_RAW_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EVQ_PTR_RAW_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EVQ_PTR_RAW_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EVQ_PTR_RAW_HI_OFST
value|16
end_define

begin_comment
comment|/* Raw evq timer table data. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EV_TIMER_RAW_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EV_TIMER_RAW_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EV_TIMER_RAW_LO_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EV_TIMER_RAW_HI_OFST
value|24
end_define

begin_comment
comment|/* Combined metadata field. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EV_META_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EV_META_BUFS_BASE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EV_META_BUFS_BASE_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EV_META_BUFS_NPAGES_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EV_META_BUFS_NPAGES_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EV_META_WKUP_REF_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_EV_META_WKUP_REF_WIDTH
value|8
end_define

begin_comment
comment|/* TXDPCPU raw table data for queue. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_0_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_0_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_0_LO_OFST
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_0_HI_OFST
value|36
end_define

begin_comment
comment|/* TXDPCPU raw table data for queue. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_1_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_1_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_1_LO_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_1_HI_OFST
value|44
end_define

begin_comment
comment|/* TXDPCPU raw table data for queue. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_2_OFST
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_2_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_2_LO_OFST
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_RAW_TBL_2_HI_OFST
value|52
end_define

begin_comment
comment|/* Combined metadata field. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_OFST
value|56
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_LO_OFST
value|56
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_HI_OFST
value|60
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_BUFS_BASE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_BUFS_BASE_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_BUFS_NPAGES_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_BUFS_NPAGES_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_QSTATE_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_QSTATE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_WAITCOUNT_LBN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_TX_META_WAITCOUNT_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_PADDING_LBN
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_PADDING_WIDTH
value|24
end_define

begin_comment
comment|/* RXDPCPU raw table data for queue. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_0_OFST
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_0_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_0_LO_OFST
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_0_HI_OFST
value|68
end_define

begin_comment
comment|/* RXDPCPU raw table data for queue. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_1_OFST
value|72
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_1_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_1_LO_OFST
value|72
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_1_HI_OFST
value|76
end_define

begin_comment
comment|/* Reserved, currently 0. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_2_OFST
value|80
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_2_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_2_LO_OFST
value|80
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_RAW_TBL_2_HI_OFST
value|84
end_define

begin_comment
comment|/* Combined metadata field. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_OFST
value|88
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_LO_OFST
value|88
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_HI_OFST
value|92
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_BUFS_BASE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_BUFS_BASE_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_BUFS_NPAGES_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_BUFS_NPAGES_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_QSTATE_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_QSTATE_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_WAITCOUNT_LBN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_VI_STATE_OUT_VI_RX_META_WAITCOUNT_WIDTH
value|8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_ALLOC_PIOBUF  * Allocate a push I/O buffer for later use with a tx queue.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ALLOC_PIOBUF
value|0x8f
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x8f_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x8f_PRIVILEGE_CTG
value|SRIOV_CTG_ONLOAD
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

begin_comment
comment|/* Handle for allocated push I/O buffer. */
end_comment

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
comment|/* MC_CMD_FREE_PIOBUF  * Free a push I/O buffer.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FREE_PIOBUF
value|0x90
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x90_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x90_PRIVILEGE_CTG
value|SRIOV_CTG_ONLOAD
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

begin_comment
comment|/* Handle for allocated push I/O buffer. */
end_comment

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
comment|/* MC_CMD_GET_VI_TLP_PROCESSING  * Get TLP steering and ordering information for a VI.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING
value|0xb0
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xb0_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xb0_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_VI_TLP_PROCESSING_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_IN_LEN
value|4
end_define

begin_comment
comment|/* VI number to get information for. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_IN_INSTANCE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_VI_TLP_PROCESSING_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_LEN
value|4
end_define

begin_comment
comment|/* Transaction processing steering hint 1 for use with the Rx Queue. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_TPH_TAG1_RX_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_TPH_TAG1_RX_LEN
value|1
end_define

begin_comment
comment|/* Transaction processing steering hint 2 for use with the Ev Queue. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_TPH_TAG2_EV_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_TPH_TAG2_EV_LEN
value|1
end_define

begin_comment
comment|/* Use Relaxed ordering model for TLPs on this VI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_RELAXED_ORDERING_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_RELAXED_ORDERING_WIDTH
value|1
end_define

begin_comment
comment|/* Use ID based ordering for TLPs on this VI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_ID_BASED_ORDERING_LBN
value|17
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_ID_BASED_ORDERING_WIDTH
value|1
end_define

begin_comment
comment|/* Set no snoop bit for TLPs on this VI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_NO_SNOOP_LBN
value|18
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_NO_SNOOP_WIDTH
value|1
end_define

begin_comment
comment|/* Enable TPH for TLPs on this VI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_TPH_ON_LBN
value|19
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_TPH_ON_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_VI_TLP_PROCESSING_OUT_DATA_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_VI_TLP_PROCESSING  * Set TLP steering and ordering information for a VI.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING
value|0xb1
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xb1_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xb1_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_SET_VI_TLP_PROCESSING_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_LEN
value|8
end_define

begin_comment
comment|/* VI number to set information for. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_INSTANCE_OFST
value|0
end_define

begin_comment
comment|/* Transaction processing steering hint 1 for use with the Rx Queue. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_TPH_TAG1_RX_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_TPH_TAG1_RX_LEN
value|1
end_define

begin_comment
comment|/* Transaction processing steering hint 2 for use with the Ev Queue. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_TPH_TAG2_EV_OFST
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_TPH_TAG2_EV_LEN
value|1
end_define

begin_comment
comment|/* Use Relaxed ordering model for TLPs on this VI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_RELAXED_ORDERING_LBN
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_RELAXED_ORDERING_WIDTH
value|1
end_define

begin_comment
comment|/* Use ID based ordering for TLPs on this VI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_ID_BASED_ORDERING_LBN
value|49
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_ID_BASED_ORDERING_WIDTH
value|1
end_define

begin_comment
comment|/* Set the no snoop bit for TLPs on this VI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_NO_SNOOP_LBN
value|50
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_NO_SNOOP_WIDTH
value|1
end_define

begin_comment
comment|/* Enable TPH for TLPs on this VI. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_TPH_ON_LBN
value|51
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_TPH_ON_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_IN_DATA_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_SET_VI_TLP_PROCESSING_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VI_TLP_PROCESSING_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_TLP_PROCESSING_GLOBALS  * Get global PCIe steering and transaction processing configuration.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS
value|0xbc
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xbc_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xbc_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_GET_TLP_PROCESSING_GLOBALS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_IN_TLP_GLOBAL_CATEGORY_OFST
value|0
end_define

begin_comment
comment|/* enum: MISC. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_IN_TLP_GLOBAL_CATEGORY_MISC
value|0x0
end_define

begin_comment
comment|/* enum: IDO. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_IN_TLP_GLOBAL_CATEGORY_IDO
value|0x1
end_define

begin_comment
comment|/* enum: RO. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_IN_TLP_GLOBAL_CATEGORY_RO
value|0x2
end_define

begin_comment
comment|/* enum: TPH Type. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_IN_TLP_GLOBAL_CATEGORY_TPH_TYPE
value|0x3
end_define

begin_comment
comment|/* MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_GLOBAL_CATEGORY_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_GET_TLP_PROCESSING_GLOBALS_IN/TLP_GLOBAL_CATEGORY */
end_comment

begin_comment
comment|/* Amalgamated TLP info word. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_WORD_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_MISC_WTAG_EN_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_MISC_WTAG_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_MISC_SPARE_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_MISC_SPARE_WIDTH
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_IDO_DL_EN_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_IDO_DL_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_IDO_TX_EN_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_IDO_TX_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_IDO_EV_EN_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_IDO_EV_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_IDO_RX_EN_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_IDO_RX_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_IDO_SPARE_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_IDO_SPARE_WIDTH
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_RO_RXDMA_EN_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_RO_RXDMA_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_RO_TXDMA_EN_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_RO_TXDMA_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_RO_DL_EN_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_RO_DL_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_RO_SPARE_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_RO_SPARE_WIDTH
value|29
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TPH_TYPE_MSIX_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TPH_TYPE_MSIX_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TPH_TYPE_DL_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TPH_TYPE_DL_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TPH_TYPE_TX_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TPH_TYPE_TX_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TPH_TYPE_EV_LBN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TPH_TYPE_EV_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TPH_TYPE_RX_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TPH_TYPE_RX_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TLP_TYPE_SPARE_LBN
value|9
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TLP_PROCESSING_GLOBALS_OUT_TLP_INFO_TLP_TYPE_SPARE_WIDTH
value|23
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_TLP_PROCESSING_GLOBALS  * Set global PCIe steering and transaction processing configuration.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS
value|0xbd
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xbd_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xbd_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_GLOBAL_CATEGORY_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_GET_TLP_PROCESSING_GLOBALS/MC_CMD_GET_TLP_PROCESSING_GLOBALS_IN/TLP_GLOBAL_CATEGORY */
end_comment

begin_comment
comment|/* Amalgamated TLP info word. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_WORD_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_MISC_WTAG_EN_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_MISC_WTAG_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_IDO_DL_EN_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_IDO_DL_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_IDO_TX_EN_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_IDO_TX_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_IDO_EV_EN_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_IDO_EV_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_IDO_RX_EN_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_IDO_RX_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_RO_RXDMA_EN_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_RO_RXDMA_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_RO_TXDMA_EN_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_RO_TXDMA_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_RO_DL_EN_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_RO_DL_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_TPH_TYPE_MSIX_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_TPH_TYPE_MSIX_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_TPH_TYPE_DL_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_TPH_TYPE_DL_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_TPH_TYPE_TX_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_TPH_TYPE_TX_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_TPH_TYPE_EV_LBN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_TPH_TYPE_EV_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_TPH_TYPE_RX_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_TPH_TYPE_RX_WIDTH
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_SPARE_LBN
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_IN_TLP_INFO_SPARE_WIDTH
value|22
end_define

begin_comment
comment|/* MC_CMD_SET_TLP_PROCESSING_GLOBALS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TLP_PROCESSING_GLOBALS_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SATELLITE_DOWNLOAD  * Download a new set of images to the satellite CPUs from the host.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD
value|0x91
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x91_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x91_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_SATELLITE_DOWNLOAD_IN msgrequest: The reset requirements for the CPUs  * are subtle, and so downloads must proceed in a number of phases.  *  * 1) PHASE_RESET with a target of TARGET_ALL and chunk ID/length of 0.  *  * 2) PHASE_IMEMS for each of the IMEM targets (target IDs 0-11). Each download  * may consist of multiple chunks. The final chunk (with CHUNK_ID_LAST) should  * be a checksum (a simple 32-bit sum) of the transferred data. An individual  * download may be aborted using CHUNK_ID_ABORT.  *  * 3) PHASE_VECTORS for each of the vector table targets (target IDs 12-15),  * similar to PHASE_IMEMS.  *  * 4) PHASE_READY with a target of TARGET_ALL and chunk ID/length of 0.  *  * After any error (a requested abort is not considered to be an error) the  * sequence must be restarted from PHASE_RESET.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_LENMIN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(16+4*(num))
end_define

begin_comment
comment|/* Download phase. (Note: the IDLE phase is used internally and is never valid  * in a command from the host.)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_PHASE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_PHASE_IDLE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_PHASE_RESET
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_PHASE_IMEMS
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_PHASE_VECTORS
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_PHASE_READY
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* Target for download. (These match the blob numbers defined in  * mc_flash_layout.h.)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_OFST
value|4
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_TXDI_TEXT
value|0x0
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_RXDI_TEXT
value|0x1
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_TXDP_TEXT
value|0x2
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_RXDP_TEXT
value|0x3
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_RXHRSL_HR_LUT
value|0x4
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_RXHRSL_HR_LUT_CFG
value|0x5
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_TXHRSL_HR_LUT
value|0x6
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_TXHRSL_HR_LUT_CFG
value|0x7
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_RXHRSL_HR_PGM
value|0x8
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_RXHRSL_SL_PGM
value|0x9
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_TXHRSL_HR_PGM
value|0xa
end_define

begin_comment
comment|/* enum: Valid in phase 2 (PHASE_IMEMS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_TXHRSL_SL_PGM
value|0xb
end_define

begin_comment
comment|/* enum: Valid in phase 3 (PHASE_VECTORS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_RXDI_VTBL0
value|0xc
end_define

begin_comment
comment|/* enum: Valid in phase 3 (PHASE_VECTORS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_TXDI_VTBL0
value|0xd
end_define

begin_comment
comment|/* enum: Valid in phase 3 (PHASE_VECTORS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_RXDI_VTBL1
value|0xe
end_define

begin_comment
comment|/* enum: Valid in phase 3 (PHASE_VECTORS) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_TXDI_VTBL1
value|0xf
end_define

begin_comment
comment|/* enum: Valid in phases 1 (PHASE_RESET) and 4 (PHASE_READY) only */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_TARGET_ALL
value|0xffffffff
end_define

begin_comment
comment|/* Chunk ID, or CHUNK_ID_LAST or CHUNK_ID_ABORT */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_CHUNK_ID_OFST
value|8
end_define

begin_comment
comment|/* enum: Last chunk, containing checksum rather than data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_CHUNK_ID_LAST
value|0xffffffff
end_define

begin_comment
comment|/* enum: Abort download of this item */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_CHUNK_ID_ABORT
value|0xfffffffe
end_define

begin_comment
comment|/* Length of this chunk in bytes */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_CHUNK_LEN_OFST
value|12
end_define

begin_comment
comment|/* Data for this chunk */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_CHUNK_DATA_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_CHUNK_DATA_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_CHUNK_DATA_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_IN_CHUNK_DATA_MAXNUM
value|59
end_define

begin_comment
comment|/* MC_CMD_SATELLITE_DOWNLOAD_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_OUT_LEN
value|8
end_define

begin_comment
comment|/* Same as MC_CMD_ERR field, but included as 0 in success cases */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_OUT_RESULT_OFST
value|0
end_define

begin_comment
comment|/* Extra status information */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_OUT_INFO_OFST
value|4
end_define

begin_comment
comment|/* enum: Code download OK, completed. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_OUT_OK_COMPLETE
value|0x0
end_define

begin_comment
comment|/* enum: Code download aborted as requested. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_OUT_OK_ABORTED
value|0x1
end_define

begin_comment
comment|/* enum: Code download OK so far, send next chunk. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_OUT_OK_NEXT_CHUNK
value|0x2
end_define

begin_comment
comment|/* enum: Download phases out of sequence */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_OUT_ERR_BAD_PHASE
value|0x100
end_define

begin_comment
comment|/* enum: Bad target for this phase */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_OUT_ERR_BAD_TARGET
value|0x101
end_define

begin_comment
comment|/* enum: Chunk ID out of sequence */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_OUT_ERR_BAD_CHUNK_ID
value|0x200
end_define

begin_comment
comment|/* enum: Chunk length zero or too large */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_OUT_ERR_BAD_CHUNK_LEN
value|0x201
end_define

begin_comment
comment|/* enum: Checksum was incorrect */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SATELLITE_DOWNLOAD_OUT_ERR_BAD_CHECKSUM
value|0x300
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_CAPABILITIES  * Get device capabilities.  *  * This is supplementary to the MC_CMD_GET_BOARD_CFG command, and intended to  * reference inherent device capabilities as opposed to current NVRAM config.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES
value|0xbe
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xbe_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xbe_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_CAPABILITIES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_CAPABILITIES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_LEN
value|20
end_define

begin_comment
comment|/* First word of flags. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_FLAGS1_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TX_MAC_SECURITY_FILTERING_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TX_MAC_SECURITY_FILTERING_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_ADDITIONAL_RSS_MODES_LBN
value|13
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_ADDITIONAL_RSS_MODES_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_QBB_LBN
value|14
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_QBB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_PACKED_STREAM_VAR_BUFFERS_LBN
value|15
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_PACKED_STREAM_VAR_BUFFERS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_RSS_LIMITED_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_RSS_LIMITED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_PACKED_STREAM_LBN
value|17
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_PACKED_STREAM_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_INCLUDE_FCS_LBN
value|18
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_INCLUDE_FCS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TX_VLAN_INSERTION_LBN
value|19
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TX_VLAN_INSERTION_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_VLAN_STRIPPING_LBN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_VLAN_STRIPPING_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TX_TSO_LBN
value|21
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TX_TSO_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_PREFIX_LEN_0_LBN
value|22
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_PREFIX_LEN_0_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_PREFIX_LEN_14_LBN
value|23
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_PREFIX_LEN_14_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_TIMESTAMP_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_TIMESTAMP_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_BATCHING_LBN
value|25
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_BATCHING_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_MCAST_FILTER_CHAINING_LBN
value|26
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_MCAST_FILTER_CHAINING_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_PM_AND_RXDP_COUNTERS_LBN
value|27
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_PM_AND_RXDP_COUNTERS_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_DISABLE_SCATTER_LBN
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_DISABLE_SCATTER_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TX_MCAST_UDP_LOOPBACK_LBN
value|29
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TX_MCAST_UDP_LOOPBACK_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_EVB_LBN
value|30
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_EVB_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_VXLAN_NVGRE_LBN
value|31
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_VXLAN_NVGRE_WIDTH
value|1
end_define

begin_comment
comment|/* RxDPCPU firmware id. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_DPCPU_FW_ID_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RX_DPCPU_FW_ID_LEN
value|2
end_define

begin_comment
comment|/* enum: Standard RXDP firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP
value|0x0
end_define

begin_comment
comment|/* enum: Low latency RXDP firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP_LOW_LATENCY
value|0x1
end_define

begin_comment
comment|/* enum: Packed stream RXDP firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP_PACKED_STREAM
value|0x2
end_define

begin_comment
comment|/* enum: BIST RXDP firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP_BIST
value|0x10a
end_define

begin_comment
comment|/* enum: RXDP Test firmware image 1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP_TEST_FW_TO_MC_CUT_THROUGH
value|0x101
end_define

begin_comment
comment|/* enum: RXDP Test firmware image 2 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP_TEST_FW_TO_MC_STORE_FORWARD
value|0x102
end_define

begin_comment
comment|/* enum: RXDP Test firmware image 3 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP_TEST_FW_TO_MC_STORE_FORWARD_FIRST
value|0x103
end_define

begin_comment
comment|/* enum: RXDP Test firmware image 4 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP_TEST_EVERY_EVENT_BATCHABLE
value|0x104
end_define

begin_comment
comment|/* enum: RXDP Test firmware image 5 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP_TEST_BACKPRESSURE
value|0x105
end_define

begin_comment
comment|/* enum: RXDP Test firmware image 6 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP_TEST_FW_PACKET_EDITS
value|0x106
end_define

begin_comment
comment|/* enum: RXDP Test firmware image 7 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP_TEST_FW_RX_HDR_SPLIT
value|0x107
end_define

begin_comment
comment|/* enum: RXDP Test firmware image 8 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXDP_TEST_FW_DISABLE_DL
value|0x108
end_define

begin_comment
comment|/* TxDPCPU firmware id. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TX_DPCPU_FW_ID_OFST
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TX_DPCPU_FW_ID_LEN
value|2
end_define

begin_comment
comment|/* enum: Standard TXDP firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXDP
value|0x0
end_define

begin_comment
comment|/* enum: Low latency TXDP firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXDP_LOW_LATENCY
value|0x1
end_define

begin_comment
comment|/* enum: High packet rate TXDP firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXDP_HIGH_PACKET_RATE
value|0x3
end_define

begin_comment
comment|/* enum: BIST TXDP firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXDP_BIST
value|0x12d
end_define

begin_comment
comment|/* enum: TXDP Test firmware image 1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXDP_TEST_FW_TSO_EDIT
value|0x101
end_define

begin_comment
comment|/* enum: TXDP Test firmware image 2 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXDP_TEST_FW_PACKET_EDITS
value|0x102
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_VERSION_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_VERSION_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_VERSION_REV_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_VERSION_REV_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_VERSION_TYPE_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_VERSION_TYPE_WIDTH
value|4
end_define

begin_comment
comment|/* enum: reserved value - do not use (may indicate alternative interpretation  * of REV field in future)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_TYPE_RESERVED
value|0x0
end_define

begin_comment
comment|/* enum: Trivial RX PD firmware for early Huntington development (Huntington  * development only)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_TYPE_FIRST_PKT
value|0x1
end_define

begin_comment
comment|/* enum: RX PD firmware with approximately Siena-compatible behaviour  * (Huntington development only)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_TYPE_SIENA_COMPAT
value|0x2
end_define

begin_comment
comment|/* enum: Virtual switching (full feature) RX PD production firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_TYPE_VSWITCH
value|0x3
end_define

begin_comment
comment|/* enum: siena_compat variant RX PD firmware using PM rather than MAC  * (Huntington development only)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_TYPE_SIENA_COMPAT_PM
value|0x4
end_define

begin_comment
comment|/* enum: Low latency RX PD production firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_TYPE_LOW_LATENCY
value|0x5
end_define

begin_comment
comment|/* enum: Packed stream RX PD production firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_TYPE_PACKED_STREAM
value|0x6
end_define

begin_comment
comment|/* enum: RX PD firmware handling layer 2 only for high packet rate performance  * tests (Medford development only)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_TYPE_LAYER2_PERF
value|0x7
end_define

begin_comment
comment|/* enum: RX PD firmware for GUE parsing prototype (Medford development only) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_TYPE_TESTFW_GUE_PROTOTYPE
value|0xe
end_define

begin_comment
comment|/* enum: RX PD firmware parsing but not filtering network overlay tunnel  * encapsulations (Medford development only)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_RXPD_FW_TYPE_TESTFW_ENCAP_PARSING_ONLY
value|0xf
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_VERSION_OFST
value|10
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_VERSION_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_VERSION_REV_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_VERSION_REV_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_VERSION_TYPE_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_VERSION_TYPE_WIDTH
value|4
end_define

begin_comment
comment|/* enum: reserved value - do not use (may indicate alternative interpretation  * of REV field in future)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_TYPE_RESERVED
value|0x0
end_define

begin_comment
comment|/* enum: Trivial TX PD firmware for early Huntington development (Huntington  * development only)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_TYPE_FIRST_PKT
value|0x1
end_define

begin_comment
comment|/* enum: TX PD firmware with approximately Siena-compatible behaviour  * (Huntington development only)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_TYPE_SIENA_COMPAT
value|0x2
end_define

begin_comment
comment|/* enum: Virtual switching (full feature) TX PD production firmware */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_TYPE_VSWITCH
value|0x3
end_define

begin_comment
comment|/* enum: siena_compat variant TX PD firmware using PM rather than MAC  * (Huntington development only)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_TYPE_SIENA_COMPAT_PM
value|0x4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_TYPE_LOW_LATENCY
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* enum: TX PD firmware handling layer 2 only for high packet rate performance  * tests (Medford development only)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_TYPE_LAYER2_PERF
value|0x7
end_define

begin_comment
comment|/* enum: RX PD firmware for GUE parsing prototype (Medford development only) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_TXPD_FW_TYPE_TESTFW_GUE_PROTOTYPE
value|0xe
end_define

begin_comment
comment|/* Hardware capabilities of NIC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_HW_CAPABILITIES_OFST
value|12
end_define

begin_comment
comment|/* Licensed capabilities */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CAPABILITIES_OUT_LICENSE_CAPABILITIES_OFST
value|16
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_V2_EXTN  * Encapsulation for a v2 extended command  */
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

begin_comment
comment|/* the extended command number */
end_comment

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

begin_comment
comment|/* the actual length of the encapsulated command (which is not in the v1  * header)  */
end_comment

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
comment|/* MC_CMD_TCM_BUCKET_ALLOC  * Allocate a pacer bucket (for qau rp or a snapper test)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_ALLOC
value|0xb2
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xb2_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xb2_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* the bucket id */
end_comment

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
comment|/* MC_CMD_TCM_BUCKET_FREE  * Free a pacer bucket  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_FREE
value|0xb3
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xb3_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xb3_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* the bucket id */
end_comment

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
comment|/* MC_CMD_TCM_BUCKET_INIT  * Initialise pacer bucket with a given rate  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT
value|0xb4
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xb4_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xb4_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* the bucket id */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT_IN_BUCKET_OFST
value|0
end_define

begin_comment
comment|/* the rate in mbps */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT_IN_RATE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_TCM_BUCKET_INIT_EXT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT_EXT_IN_LEN
value|12
end_define

begin_comment
comment|/* the bucket id */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT_EXT_IN_BUCKET_OFST
value|0
end_define

begin_comment
comment|/* the rate in mbps */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT_EXT_IN_RATE_OFST
value|4
end_define

begin_comment
comment|/* the desired maximum fill level */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_BUCKET_INIT_EXT_IN_MAX_FILL_OFST
value|8
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
comment|/* MC_CMD_TCM_TXQ_INIT  * Initialise txq in pacer with given options or set options  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT
value|0xb5
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xb5_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xb5_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* the txq id */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_QID_OFST
value|0
end_define

begin_comment
comment|/* the static priority associated with the txq */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_LABEL_OFST
value|4
end_define

begin_comment
comment|/* bitmask of the priority queues this txq is inserted into when inserted. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_PQ_FLAGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_PQ_FLAG_GUARANTEED_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_PQ_FLAG_GUARANTEED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_PQ_FLAG_NORMAL_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_PQ_FLAG_NORMAL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_PQ_FLAG_LOW_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_PQ_FLAG_LOW_WIDTH
value|1
end_define

begin_comment
comment|/* the reaction point (RP) bucket */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_RP_BKT_OFST
value|12
end_define

begin_comment
comment|/* an already reserved bucket (typically set to bucket associated with outer  * vswitch)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_MAX_BKT1_OFST
value|16
end_define

begin_comment
comment|/* an already reserved bucket (typically set to bucket associated with inner  * vswitch)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_MAX_BKT2_OFST
value|20
end_define

begin_comment
comment|/* the min bucket (typically for ETS/minimum bandwidth) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_IN_MIN_BKT_OFST
value|24
end_define

begin_comment
comment|/* MC_CMD_TCM_TXQ_INIT_EXT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_LEN
value|32
end_define

begin_comment
comment|/* the txq id */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_QID_OFST
value|0
end_define

begin_comment
comment|/* the static priority associated with the txq */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_LABEL_NORMAL_OFST
value|4
end_define

begin_comment
comment|/* bitmask of the priority queues this txq is inserted into when inserted. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_PQ_FLAGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_PQ_FLAG_GUARANTEED_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_PQ_FLAG_GUARANTEED_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_PQ_FLAG_NORMAL_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_PQ_FLAG_NORMAL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_PQ_FLAG_LOW_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_PQ_FLAG_LOW_WIDTH
value|1
end_define

begin_comment
comment|/* the reaction point (RP) bucket */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_RP_BKT_OFST
value|12
end_define

begin_comment
comment|/* an already reserved bucket (typically set to bucket associated with outer  * vswitch)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_MAX_BKT1_OFST
value|16
end_define

begin_comment
comment|/* an already reserved bucket (typically set to bucket associated with inner  * vswitch)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_MAX_BKT2_OFST
value|20
end_define

begin_comment
comment|/* the min bucket (typically for ETS/minimum bandwidth) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_MIN_BKT_OFST
value|24
end_define

begin_comment
comment|/* the static priority associated with the txq */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TCM_TXQ_INIT_EXT_IN_LABEL_GUARANTEED_OFST
value|28
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

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_LINK_PIOBUF  * Link a push I/O buffer to a TxQ  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_PIOBUF
value|0x92
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x92_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x92_PRIVILEGE_CTG
value|SRIOV_CTG_ONLOAD
end_define

begin_comment
comment|/* MC_CMD_LINK_PIOBUF_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_PIOBUF_IN_LEN
value|8
end_define

begin_comment
comment|/* Handle for allocated push I/O buffer. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_PIOBUF_IN_PIOBUF_HANDLE_OFST
value|0
end_define

begin_comment
comment|/* Function Local Instance (VI) number. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_PIOBUF_IN_TXQ_INSTANCE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_LINK_PIOBUF_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_PIOBUF_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_UNLINK_PIOBUF  * Unlink a push I/O buffer from a TxQ  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UNLINK_PIOBUF
value|0x93
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x93_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x93_PRIVILEGE_CTG
value|SRIOV_CTG_ONLOAD
end_define

begin_comment
comment|/* MC_CMD_UNLINK_PIOBUF_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UNLINK_PIOBUF_IN_LEN
value|4
end_define

begin_comment
comment|/* Function Local Instance (VI) number. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UNLINK_PIOBUF_IN_TXQ_INSTANCE_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_UNLINK_PIOBUF_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UNLINK_PIOBUF_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_VSWITCH_ALLOC  * allocate and initialise a v-switch.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC
value|0x94
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x94_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x94_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_VSWITCH_ALLOC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_LEN
value|16
end_define

begin_comment
comment|/* The port to connect to the v-switch's upstream port. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_UPSTREAM_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* The type of v-switch to create. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_TYPE_OFST
value|4
end_define

begin_comment
comment|/* enum: VLAN */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_VSWITCH_TYPE_VLAN
value|0x1
end_define

begin_comment
comment|/* enum: VEB */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_VSWITCH_TYPE_VEB
value|0x2
end_define

begin_comment
comment|/* enum: VEPA (obsolete) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_VSWITCH_TYPE_VEPA
value|0x3
end_define

begin_comment
comment|/* enum: MUX */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_VSWITCH_TYPE_MUX
value|0x4
end_define

begin_comment
comment|/* enum: Snapper specific; semantics TBD */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_VSWITCH_TYPE_TEST
value|0x5
end_define

begin_comment
comment|/* Flags controlling v-port creation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_FLAGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_FLAG_AUTO_PORT_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_FLAG_AUTO_PORT_WIDTH
value|1
end_define

begin_comment
comment|/* The number of VLAN tags to allow for attached v-ports. For VLAN aggregators,  * this must be one or greated, and the attached v-ports must have exactly this  * number of tags. For other v-switch types, this must be zero of greater, and  * is an upper limit on the number of VLAN tags for attached v-ports. An error  * will be returned if existing configuration means we can't support attached  * v-ports with this number of tags.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_IN_NUM_VLAN_TAGS_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_VSWITCH_ALLOC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_ALLOC_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_VSWITCH_FREE  * de-allocate a v-switch.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_FREE
value|0x95
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x95_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x95_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_VSWITCH_FREE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_FREE_IN_LEN
value|4
end_define

begin_comment
comment|/* The port to which the v-switch is connected. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_FREE_IN_UPSTREAM_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_VSWITCH_FREE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VSWITCH_FREE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_VPORT_ALLOC  * allocate a v-port.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC
value|0x96
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x96_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x96_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_VPORT_ALLOC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_LEN
value|20
end_define

begin_comment
comment|/* The port to which the v-switch is connected. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_UPSTREAM_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* The type of the new v-port. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_TYPE_OFST
value|4
end_define

begin_comment
comment|/* enum: VLAN (obsolete) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_VPORT_TYPE_VLAN
value|0x1
end_define

begin_comment
comment|/* enum: VEB (obsolete) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_VPORT_TYPE_VEB
value|0x2
end_define

begin_comment
comment|/* enum: VEPA (obsolete) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_VPORT_TYPE_VEPA
value|0x3
end_define

begin_comment
comment|/* enum: A normal v-port receives packets which match a specified MAC and/or  * VLAN.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_VPORT_TYPE_NORMAL
value|0x4
end_define

begin_comment
comment|/* enum: An expansion v-port packets traffic which don't match any other  * v-port.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_VPORT_TYPE_EXPANSION
value|0x5
end_define

begin_comment
comment|/* enum: An test v-port receives packets which match any filters installed by  * its downstream components.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_VPORT_TYPE_TEST
value|0x6
end_define

begin_comment
comment|/* Flags controlling v-port creation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_FLAGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_FLAG_AUTO_PORT_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_FLAG_AUTO_PORT_WIDTH
value|1
end_define

begin_comment
comment|/* The number of VLAN tags to insert/remove. An error will be returned if  * incompatible with the number of VLAN tags specified for the upstream  * v-switch.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_NUM_VLAN_TAGS_OFST
value|12
end_define

begin_comment
comment|/* The actual VLAN tags to insert/remove */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_VLAN_TAGS_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_VLAN_TAG_0_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_VLAN_TAG_0_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_VLAN_TAG_1_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_IN_VLAN_TAG_1_WIDTH
value|16
end_define

begin_comment
comment|/* MC_CMD_VPORT_ALLOC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_OUT_LEN
value|4
end_define

begin_comment
comment|/* The handle of the new v-port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ALLOC_OUT_VPORT_ID_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_VPORT_FREE  * de-allocate a v-port.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_FREE
value|0x97
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x97_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x97_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_VPORT_FREE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_FREE_IN_LEN
value|4
end_define

begin_comment
comment|/* The handle of the v-port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_FREE_IN_VPORT_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_VPORT_FREE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_FREE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_VADAPTOR_ALLOC  * allocate a v-adaptor.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC
value|0x98
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x98_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x98_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_VADAPTOR_ALLOC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_LEN
value|30
end_define

begin_comment
comment|/* The port to connect to the v-adaptor's port. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_UPSTREAM_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* Flags controlling v-adaptor creation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_FLAGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_FLAG_AUTO_VADAPTOR_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_FLAG_AUTO_VADAPTOR_WIDTH
value|1
end_define

begin_comment
comment|/* The number of VLAN tags to strip on receive */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_NUM_VLANS_OFST
value|12
end_define

begin_comment
comment|/* The number of VLAN tags to transparently insert/remove. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_NUM_VLAN_TAGS_OFST
value|16
end_define

begin_comment
comment|/* The actual VLAN tags to insert/remove */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_VLAN_TAGS_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_VLAN_TAG_0_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_VLAN_TAG_0_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_VLAN_TAG_1_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_VLAN_TAG_1_WIDTH
value|16
end_define

begin_comment
comment|/* The MAC address to assign to this v-adaptor */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_MACADDR_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_MACADDR_LEN
value|6
end_define

begin_comment
comment|/* enum: Derive the MAC address from the upstream port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_IN_AUTO_MAC
value|0x0
end_define

begin_comment
comment|/* MC_CMD_VADAPTOR_ALLOC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_ALLOC_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_VADAPTOR_FREE  * de-allocate a v-adaptor.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_FREE
value|0x99
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x99_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x99_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_VADAPTOR_FREE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_FREE_IN_LEN
value|4
end_define

begin_comment
comment|/* The port to which the v-adaptor is connected. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_FREE_IN_UPSTREAM_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_VADAPTOR_FREE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_FREE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_VADAPTOR_SET_MAC  * assign a new MAC address to a v-adaptor.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_SET_MAC
value|0x5d
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x5d_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x5d_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_VADAPTOR_SET_MAC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_SET_MAC_IN_LEN
value|10
end_define

begin_comment
comment|/* The port to which the v-adaptor is connected. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_SET_MAC_IN_UPSTREAM_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* The new MAC address to assign to this v-adaptor */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_SET_MAC_IN_MACADDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_SET_MAC_IN_MACADDR_LEN
value|6
end_define

begin_comment
comment|/* MC_CMD_VADAPTOR_SET_MAC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_SET_MAC_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_VADAPTOR_GET_MAC  * read the MAC address assigned to a v-adaptor.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_GET_MAC
value|0x5e
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x5e_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x5e_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_VADAPTOR_GET_MAC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_GET_MAC_IN_LEN
value|4
end_define

begin_comment
comment|/* The port to which the v-adaptor is connected. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_GET_MAC_IN_UPSTREAM_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_VADAPTOR_GET_MAC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_GET_MAC_OUT_LEN
value|6
end_define

begin_comment
comment|/* The MAC address assigned to this v-adaptor */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_GET_MAC_OUT_MACADDR_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_VADAPTOR_GET_MAC_OUT_MACADDR_LEN
value|6
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_EVB_PORT_ASSIGN  * assign a port to a PCI function.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_EVB_PORT_ASSIGN
value|0x9a
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x9a_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x9a_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_EVB_PORT_ASSIGN_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_EVB_PORT_ASSIGN_IN_LEN
value|8
end_define

begin_comment
comment|/* The port to assign. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_EVB_PORT_ASSIGN_IN_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* The target function to modify. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_EVB_PORT_ASSIGN_IN_FUNCTION_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_EVB_PORT_ASSIGN_IN_PF_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_EVB_PORT_ASSIGN_IN_PF_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_EVB_PORT_ASSIGN_IN_VF_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_EVB_PORT_ASSIGN_IN_VF_WIDTH
value|16
end_define

begin_comment
comment|/* MC_CMD_EVB_PORT_ASSIGN_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_EVB_PORT_ASSIGN_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_RDWR_A64_REGIONS  * Assign the 64 bit region addresses.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS
value|0x9b
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x9b_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x9b_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_RDWR_A64_REGIONS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_IN_LEN
value|17
end_define

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_IN_REGION0_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_IN_REGION1_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_IN_REGION2_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_IN_REGION3_OFST
value|12
end_define

begin_comment
comment|/* Write enable bits 0-3, set to write, clear to read. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_IN_WRITE_MASK_LBN
value|128
end_define

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_IN_WRITE_MASK_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_IN_WRITE_MASK_BYTE_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_IN_WRITE_MASK_BYTE_LEN
value|1
end_define

begin_comment
comment|/* MC_CMD_RDWR_A64_REGIONS_OUT msgresponse: This data always included  * regardless of state of write bits in the request.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_OUT_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_OUT_REGION0_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_OUT_REGION1_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_OUT_REGION2_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_RDWR_A64_REGIONS_OUT_REGION3_OFST
value|12
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_ONLOAD_STACK_ALLOC  * Allocate an Onload stack ID.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ONLOAD_STACK_ALLOC
value|0x9c
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x9c_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x9c_PRIVILEGE_CTG
value|SRIOV_CTG_ONLOAD
end_define

begin_comment
comment|/* MC_CMD_ONLOAD_STACK_ALLOC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ONLOAD_STACK_ALLOC_IN_LEN
value|4
end_define

begin_comment
comment|/* The handle of the owning upstream port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ONLOAD_STACK_ALLOC_IN_UPSTREAM_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_ONLOAD_STACK_ALLOC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ONLOAD_STACK_ALLOC_OUT_LEN
value|4
end_define

begin_comment
comment|/* The handle of the new Onload stack */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ONLOAD_STACK_ALLOC_OUT_ONLOAD_STACK_ID_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_ONLOAD_STACK_FREE  * Free an Onload stack ID.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ONLOAD_STACK_FREE
value|0x9d
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x9d_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x9d_PRIVILEGE_CTG
value|SRIOV_CTG_ONLOAD
end_define

begin_comment
comment|/* MC_CMD_ONLOAD_STACK_FREE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ONLOAD_STACK_FREE_IN_LEN
value|4
end_define

begin_comment
comment|/* The handle of the Onload stack */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ONLOAD_STACK_FREE_IN_ONLOAD_STACK_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_ONLOAD_STACK_FREE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ONLOAD_STACK_FREE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_ALLOC  * Allocate an RSS context.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_ALLOC
value|0x9e
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x9e_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x9e_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_ALLOC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_ALLOC_IN_LEN
value|12
end_define

begin_comment
comment|/* The handle of the owning upstream port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_ALLOC_IN_UPSTREAM_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* The type of context to allocate */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_ALLOC_IN_TYPE_OFST
value|4
end_define

begin_comment
comment|/* enum: Allocate a context for exclusive use. The key and indirection table  * must be explicitly configured.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_ALLOC_IN_TYPE_EXCLUSIVE
value|0x0
end_define

begin_comment
comment|/* enum: Allocate a context for shared use; this will spread across a range of  * queues, but the key and indirection table are pre-configured and may not be  * changed. For this mode, NUM_QUEUES must 2, 4, 8, 16, 32 or 64.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_ALLOC_IN_TYPE_SHARED
value|0x1
end_define

begin_comment
comment|/* Number of queues spanned by this context, in the range 1-64; valid offsets  * in the indirection table will be in the range 0 to NUM_QUEUES-1.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_ALLOC_IN_NUM_QUEUES_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_ALLOC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_ALLOC_OUT_LEN
value|4
end_define

begin_comment
comment|/* The handle of the new RSS context. This should be considered opaque to the  * host, although a value of 0xFFFFFFFF is guaranteed never to be a valid  * handle.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_ALLOC_OUT_RSS_CONTEXT_ID_OFST
value|0
end_define

begin_comment
comment|/* enum: guaranteed invalid RSS context handle value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_ALLOC_OUT_RSS_CONTEXT_ID_INVALID
value|0xffffffff
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_FREE  * Free an RSS context.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_FREE
value|0x9f
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x9f_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x9f_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_FREE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_FREE_IN_LEN
value|4
end_define

begin_comment
comment|/* The handle of the RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_FREE_IN_RSS_CONTEXT_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_FREE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_FREE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_SET_KEY  * Set the Toeplitz hash key for an RSS context.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_KEY
value|0xa0
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xa0_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xa0_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_SET_KEY_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_KEY_IN_LEN
value|44
end_define

begin_comment
comment|/* The handle of the RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_KEY_IN_RSS_CONTEXT_ID_OFST
value|0
end_define

begin_comment
comment|/* The 40-byte Toeplitz hash key (TBD endianness issues?) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_KEY_IN_TOEPLITZ_KEY_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_KEY_IN_TOEPLITZ_KEY_LEN
value|40
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_SET_KEY_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_KEY_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_GET_KEY  * Get the Toeplitz hash key for an RSS context.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_KEY
value|0xa1
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xa1_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xa1_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_GET_KEY_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_KEY_IN_LEN
value|4
end_define

begin_comment
comment|/* The handle of the RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_KEY_IN_RSS_CONTEXT_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_GET_KEY_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_KEY_OUT_LEN
value|44
end_define

begin_comment
comment|/* The 40-byte Toeplitz hash key (TBD endianness issues?) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_KEY_OUT_TOEPLITZ_KEY_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_KEY_OUT_TOEPLITZ_KEY_LEN
value|40
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_SET_TABLE  * Set the indirection table for an RSS context.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_TABLE
value|0xa2
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xa2_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xa2_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_SET_TABLE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_TABLE_IN_LEN
value|132
end_define

begin_comment
comment|/* The handle of the RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_TABLE_IN_RSS_CONTEXT_ID_OFST
value|0
end_define

begin_comment
comment|/* The 128-byte indirection table (1 byte per entry) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_TABLE_IN_INDIRECTION_TABLE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_TABLE_IN_INDIRECTION_TABLE_LEN
value|128
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_SET_TABLE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_TABLE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_GET_TABLE  * Get the indirection table for an RSS context.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_TABLE
value|0xa3
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xa3_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xa3_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_GET_TABLE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_TABLE_IN_LEN
value|4
end_define

begin_comment
comment|/* The handle of the RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_TABLE_IN_RSS_CONTEXT_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_GET_TABLE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_TABLE_OUT_LEN
value|132
end_define

begin_comment
comment|/* The 128-byte indirection table (1 byte per entry) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_TABLE_OUT_INDIRECTION_TABLE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_TABLE_OUT_INDIRECTION_TABLE_LEN
value|128
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_SET_FLAGS  * Set various control flags for an RSS context.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS
value|0xe1
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xe1_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xe1_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_SET_FLAGS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_LEN
value|8
end_define

begin_comment
comment|/* The handle of the RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_RSS_CONTEXT_ID_OFST
value|0
end_define

begin_comment
comment|/* Hash control flags. The _EN bits are always supported. The _MODE bits only  * work when the firmware reports ADDITIONAL_RSS_MODES in  * MC_CMD_GET_CAPABILITIES and override the _EN bits if any of them are not 0.  * See the RSS_MODE structure for the meaning of the mode bits.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_FLAGS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_IPV4_EN_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_IPV4_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_TCPV4_EN_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_TCPV4_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_IPV6_EN_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_IPV6_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_TCPV6_EN_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TOEPLITZ_TCPV6_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_RESERVED_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_RESERVED_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TCP_IPV4_RSS_MODE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TCP_IPV4_RSS_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_UDP_IPV4_RSS_MODE_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_UDP_IPV4_RSS_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_OTHER_IPV4_RSS_MODE_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_OTHER_IPV4_RSS_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TCP_IPV6_RSS_MODE_LBN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_TCP_IPV6_RSS_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_UDP_IPV6_RSS_MODE_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_UDP_IPV6_RSS_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_OTHER_IPV6_RSS_MODE_LBN
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_IN_OTHER_IPV6_RSS_MODE_WIDTH
value|4
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_SET_FLAGS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_SET_FLAGS_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_GET_FLAGS  * Get various control flags for an RSS context.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS
value|0xe2
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xe2_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xe2_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_GET_FLAGS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_IN_LEN
value|4
end_define

begin_comment
comment|/* The handle of the RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_IN_RSS_CONTEXT_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_LEN
value|8
end_define

begin_comment
comment|/* Hash control flags. If any _MODE bits are non-zero (which will only be true  * when the firmware reports ADDITIONAL_RSS_MODES) then the _EN bits should be  * disregarded (but are guaranteed to be consistent with the _MODE bits if  * RSS_CONTEXT_SET_FLAGS has never been called for this context since it was  * allocated).  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_FLAGS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TOEPLITZ_IPV4_EN_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TOEPLITZ_IPV4_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TOEPLITZ_TCPV4_EN_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TOEPLITZ_TCPV4_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TOEPLITZ_IPV6_EN_LBN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TOEPLITZ_IPV6_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TOEPLITZ_TCPV6_EN_LBN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TOEPLITZ_TCPV6_EN_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_RESERVED_LBN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_RESERVED_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TCP_IPV4_RSS_MODE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TCP_IPV4_RSS_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_UDP_IPV4_RSS_MODE_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_UDP_IPV4_RSS_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_OTHER_IPV4_RSS_MODE_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_OTHER_IPV4_RSS_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TCP_IPV6_RSS_MODE_LBN
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_TCP_IPV6_RSS_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_UDP_IPV6_RSS_MODE_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_UDP_IPV6_RSS_MODE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_OTHER_IPV6_RSS_MODE_LBN
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_RSS_CONTEXT_GET_FLAGS_OUT_OTHER_IPV6_RSS_MODE_WIDTH
value|4
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_ALLOC  * Allocate a .1p mapping.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_ALLOC
value|0xa4
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xa4_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xa4_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_ALLOC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_ALLOC_IN_LEN
value|8
end_define

begin_comment
comment|/* The handle of the owning upstream port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_ALLOC_IN_UPSTREAM_PORT_ID_OFST
value|0
end_define

begin_comment
comment|/* Number of queues spanned by this mapping, in the range 1-64; valid fixed  * offsets in the mapping table will be in the range 0 to NUM_QUEUES-1, and  * referenced RSS contexts must span no more than this number.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_ALLOC_IN_NUM_QUEUES_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_ALLOC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_ALLOC_OUT_LEN
value|4
end_define

begin_comment
comment|/* The handle of the new .1p mapping. This should be considered opaque to the  * host, although a value of 0xFFFFFFFF is guaranteed never to be a valid  * handle.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_ALLOC_OUT_DOT1P_MAPPING_ID_OFST
value|0
end_define

begin_comment
comment|/* enum: guaranteed invalid .1p mapping handle value */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_ALLOC_OUT_DOT1P_MAPPING_ID_INVALID
value|0xffffffff
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_FREE  * Free a .1p mapping.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_FREE
value|0xa5
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xa5_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xa5_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_FREE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_FREE_IN_LEN
value|4
end_define

begin_comment
comment|/* The handle of the .1p mapping */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_FREE_IN_DOT1P_MAPPING_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_FREE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_FREE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_SET_TABLE  * Set the mapping table for a .1p mapping.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_SET_TABLE
value|0xa6
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xa6_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xa6_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_SET_TABLE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_SET_TABLE_IN_LEN
value|36
end_define

begin_comment
comment|/* The handle of the .1p mapping */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_SET_TABLE_IN_DOT1P_MAPPING_ID_OFST
value|0
end_define

begin_comment
comment|/* Per-priority mappings (1 32-bit word per entry - an offset or RSS context  * handle)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_SET_TABLE_IN_MAPPING_TABLE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_SET_TABLE_IN_MAPPING_TABLE_LEN
value|32
end_define

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_SET_TABLE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_SET_TABLE_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_GET_TABLE  * Get the mapping table for a .1p mapping.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_GET_TABLE
value|0xa7
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xa7_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xa7_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_GET_TABLE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_GET_TABLE_IN_LEN
value|4
end_define

begin_comment
comment|/* The handle of the .1p mapping */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_GET_TABLE_IN_DOT1P_MAPPING_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_DOT1P_MAPPING_GET_TABLE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_GET_TABLE_OUT_LEN
value|36
end_define

begin_comment
comment|/* Per-priority mappings (1 32-bit word per entry - an offset or RSS context  * handle)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_GET_TABLE_OUT_MAPPING_TABLE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DOT1P_MAPPING_GET_TABLE_OUT_MAPPING_TABLE_LEN
value|32
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_VECTOR_CFG  * Get Interrupt Vector config for this PF.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VECTOR_CFG
value|0xbf
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xbf_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xbf_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* Base absolute interrupt vector number. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VECTOR_CFG_OUT_VEC_BASE_OFST
value|0
end_define

begin_comment
comment|/* Number of interrupt vectors allocate to this PF. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_VECTOR_CFG_OUT_VECS_PER_PF_OFST
value|4
end_define

begin_comment
comment|/* Number of interrupt vectors to allocate per VF. */
end_comment

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
comment|/* MC_CMD_SET_VECTOR_CFG  * Set Interrupt Vector config for this PF.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VECTOR_CFG
value|0xc0
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xc0_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xc0_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
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

begin_comment
comment|/* Base absolute interrupt vector number, or MC_CMD_RESOURCE_INSTANCE_ANY to  * let the system find a suitable base.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VECTOR_CFG_IN_VEC_BASE_OFST
value|0
end_define

begin_comment
comment|/* Number of interrupt vectors allocate to this PF. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_VECTOR_CFG_IN_VECS_PER_PF_OFST
value|4
end_define

begin_comment
comment|/* Number of interrupt vectors to allocate per VF. */
end_comment

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
comment|/* MC_CMD_VPORT_ADD_MAC_ADDRESS  * Add a MAC address to a v-port  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ADD_MAC_ADDRESS
value|0xa8
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xa8_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xa8_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_VPORT_ADD_MAC_ADDRESS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ADD_MAC_ADDRESS_IN_LEN
value|10
end_define

begin_comment
comment|/* The handle of the v-port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ADD_MAC_ADDRESS_IN_VPORT_ID_OFST
value|0
end_define

begin_comment
comment|/* MAC address to add */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ADD_MAC_ADDRESS_IN_MACADDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ADD_MAC_ADDRESS_IN_MACADDR_LEN
value|6
end_define

begin_comment
comment|/* MC_CMD_VPORT_ADD_MAC_ADDRESS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_ADD_MAC_ADDRESS_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_VPORT_DEL_MAC_ADDRESS  * Delete a MAC address from a v-port  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_DEL_MAC_ADDRESS
value|0xa9
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xa9_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xa9_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_VPORT_DEL_MAC_ADDRESS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_DEL_MAC_ADDRESS_IN_LEN
value|10
end_define

begin_comment
comment|/* The handle of the v-port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_DEL_MAC_ADDRESS_IN_VPORT_ID_OFST
value|0
end_define

begin_comment
comment|/* MAC address to add */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_DEL_MAC_ADDRESS_IN_MACADDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_DEL_MAC_ADDRESS_IN_MACADDR_LEN
value|6
end_define

begin_comment
comment|/* MC_CMD_VPORT_DEL_MAC_ADDRESS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_DEL_MAC_ADDRESS_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_VPORT_GET_MAC_ADDRESSES  * Delete a MAC address from a v-port  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_GET_MAC_ADDRESSES
value|0xaa
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xaa_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xaa_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_VPORT_GET_MAC_ADDRESSES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_GET_MAC_ADDRESSES_IN_LEN
value|4
end_define

begin_comment
comment|/* The handle of the v-port */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_GET_MAC_ADDRESSES_IN_VPORT_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_VPORT_GET_MAC_ADDRESSES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_GET_MAC_ADDRESSES_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_GET_MAC_ADDRESSES_OUT_LENMAX
value|250
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_GET_MAC_ADDRESSES_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+6*(num))
end_define

begin_comment
comment|/* The number of MAC addresses returned */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_GET_MAC_ADDRESSES_OUT_MACADDR_COUNT_OFST
value|0
end_define

begin_comment
comment|/* Array of MAC addresses */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_VPORT_GET_MAC_ADDRESSES_OUT_MACADDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_GET_MAC_ADDRESSES_OUT_MACADDR_LEN
value|6
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_GET_MAC_ADDRESSES_OUT_MACADDR_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_VPORT_GET_MAC_ADDRESSES_OUT_MACADDR_MAXNUM
value|41
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DUMP_BUFTBL_ENTRIES  * Dump buffer table entries, mainly for command client debug use. Dumps  * absolute entries, and does not use chunk handles. All entries must be in  * range, and used for q page mapping, Although the latter restriction may be  * lifted in future.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_BUFTBL_ENTRIES
value|0xab
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xab_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xab_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_DUMP_BUFTBL_ENTRIES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_BUFTBL_ENTRIES_IN_LEN
value|8
end_define

begin_comment
comment|/* Index of the first buffer table entry. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_BUFTBL_ENTRIES_IN_FIRSTID_OFST
value|0
end_define

begin_comment
comment|/* Number of buffer table entries to dump. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_BUFTBL_ENTRIES_IN_NUMENTRIES_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_DUMP_BUFTBL_ENTRIES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_BUFTBL_ENTRIES_OUT_LENMIN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_BUFTBL_ENTRIES_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_BUFTBL_ENTRIES_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+12*(num))
end_define

begin_comment
comment|/* Raw buffer table entries, layed out as BUFTBL_ENTRY. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_BUFTBL_ENTRIES_OUT_ENTRY_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_BUFTBL_ENTRIES_OUT_ENTRY_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_BUFTBL_ENTRIES_OUT_ENTRY_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_BUFTBL_ENTRIES_OUT_ENTRY_MAXNUM
value|21
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_RXDP_CONFIG  * Set global RXDP configuration settings  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_RXDP_CONFIG
value|0xc1
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xc1_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xc1_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_SET_RXDP_CONFIG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_RXDP_CONFIG_IN_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_RXDP_CONFIG_IN_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_RXDP_CONFIG_IN_PAD_HOST_DMA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_RXDP_CONFIG_IN_PAD_HOST_DMA_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_SET_RXDP_CONFIG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_RXDP_CONFIG_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_RXDP_CONFIG  * Get global RXDP configuration settings  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_RXDP_CONFIG
value|0xc2
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xc2_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xc2_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_GET_RXDP_CONFIG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_RXDP_CONFIG_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_RXDP_CONFIG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_RXDP_CONFIG_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_RXDP_CONFIG_OUT_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_RXDP_CONFIG_OUT_PAD_HOST_DMA_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_RXDP_CONFIG_OUT_PAD_HOST_DMA_WIDTH
value|1
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_CLOCK  * Return the system and PDCPU clock frequencies.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CLOCK
value|0xac
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xac_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xac_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_CLOCK_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CLOCK_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_CLOCK_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CLOCK_OUT_LEN
value|8
end_define

begin_comment
comment|/* System frequency, MHz */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CLOCK_OUT_SYS_FREQ_OFST
value|0
end_define

begin_comment
comment|/* DPCPU frequency, MHz */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_CLOCK_OUT_DPCPU_FREQ_OFST
value|4
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_CLOCK  * Control the system and DPCPU clock frequencies. Changes are lost reboot.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK
value|0xad
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xad_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xad_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_SET_CLOCK_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_LEN
value|28
end_define

begin_comment
comment|/* Requested frequency in MHz for system clock domain */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_SYS_FREQ_OFST
value|0
end_define

begin_comment
comment|/* enum: Leave the system clock domain frequency unchanged */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_SYS_DOMAIN_DONT_CHANGE
value|0x0
end_define

begin_comment
comment|/* Requested frequency in MHz for inter-core clock domain */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_ICORE_FREQ_OFST
value|4
end_define

begin_comment
comment|/* enum: Leave the inter-core clock domain frequency unchanged */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_ICORE_DOMAIN_DONT_CHANGE
value|0x0
end_define

begin_comment
comment|/* Requested frequency in MHz for DPCPU clock domain */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_DPCPU_FREQ_OFST
value|8
end_define

begin_comment
comment|/* enum: Leave the DPCPU clock domain frequency unchanged */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_DPCPU_DOMAIN_DONT_CHANGE
value|0x0
end_define

begin_comment
comment|/* Requested frequency in MHz for PCS clock domain */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_PCS_FREQ_OFST
value|12
end_define

begin_comment
comment|/* enum: Leave the PCS clock domain frequency unchanged */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_PCS_DOMAIN_DONT_CHANGE
value|0x0
end_define

begin_comment
comment|/* Requested frequency in MHz for MC clock domain */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_MC_FREQ_OFST
value|16
end_define

begin_comment
comment|/* enum: Leave the MC clock domain frequency unchanged */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_MC_DOMAIN_DONT_CHANGE
value|0x0
end_define

begin_comment
comment|/* Requested frequency in MHz for rmon clock domain */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_RMON_FREQ_OFST
value|20
end_define

begin_comment
comment|/* enum: Leave the rmon clock domain frequency unchanged */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_RMON_DOMAIN_DONT_CHANGE
value|0x0
end_define

begin_comment
comment|/* Requested frequency in MHz for vswitch clock domain */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_VSWITCH_FREQ_OFST
value|24
end_define

begin_comment
comment|/* enum: Leave the vswitch clock domain frequency unchanged */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_IN_VSWITCH_DOMAIN_DONT_CHANGE
value|0x0
end_define

begin_comment
comment|/* MC_CMD_SET_CLOCK_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_LEN
value|28
end_define

begin_comment
comment|/* Resulting system frequency in MHz */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_SYS_FREQ_OFST
value|0
end_define

begin_comment
comment|/* enum: The system clock domain doesn't exist */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_SYS_DOMAIN_UNSUPPORTED
value|0x0
end_define

begin_comment
comment|/* Resulting inter-core frequency in MHz */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_ICORE_FREQ_OFST
value|4
end_define

begin_comment
comment|/* enum: The inter-core clock domain doesn't exist / isn't used */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_ICORE_DOMAIN_UNSUPPORTED
value|0x0
end_define

begin_comment
comment|/* Resulting DPCPU frequency in MHz */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_DPCPU_FREQ_OFST
value|8
end_define

begin_comment
comment|/* enum: The dpcpu clock domain doesn't exist */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_DPCPU_DOMAIN_UNSUPPORTED
value|0x0
end_define

begin_comment
comment|/* Resulting PCS frequency in MHz */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_PCS_FREQ_OFST
value|12
end_define

begin_comment
comment|/* enum: The PCS clock domain doesn't exist / isn't controlled */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_PCS_DOMAIN_UNSUPPORTED
value|0x0
end_define

begin_comment
comment|/* Resulting MC frequency in MHz */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_MC_FREQ_OFST
value|16
end_define

begin_comment
comment|/* enum: The MC clock domain doesn't exist / isn't controlled */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_MC_DOMAIN_UNSUPPORTED
value|0x0
end_define

begin_comment
comment|/* Resulting rmon frequency in MHz */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_RMON_FREQ_OFST
value|20
end_define

begin_comment
comment|/* enum: The rmon clock domain doesn't exist / isn't controlled */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_RMON_DOMAIN_UNSUPPORTED
value|0x0
end_define

begin_comment
comment|/* Resulting vswitch frequency in MHz */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_VSWITCH_FREQ_OFST
value|24
end_define

begin_comment
comment|/* enum: The vswitch clock domain doesn't exist / isn't controlled */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_CLOCK_OUT_VSWITCH_DOMAIN_UNSUPPORTED
value|0x0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DPCPU_RPC  * Send an arbitrary DPCPU message.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC
value|0xae
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xae_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xae_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_DPCPU_RPC_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_LEN
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CPU_OFST
value|0
end_define

begin_comment
comment|/* enum: RxDPCPU0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_DPCPU_RX0
value|0x0
end_define

begin_comment
comment|/* enum: TxDPCPU0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_DPCPU_TX0
value|0x1
end_define

begin_comment
comment|/* enum: TxDPCPU1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_DPCPU_TX1
value|0x2
end_define

begin_comment
comment|/* enum: RxDPCPU1 (Medford only) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_DPCPU_RX1
value|0x3
end_define

begin_comment
comment|/* enum: RxDPCPU (will be for the calling function; for now, just an alias of  * DPCPU_RX0)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_DPCPU_RX
value|0x80
end_define

begin_comment
comment|/* enum: TxDPCPU (will be for the calling function; for now, just an alias of  * DPCPU_TX0)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_DPCPU_TX
value|0x81
end_define

begin_comment
comment|/* First 8 bits [39:32] of DATA are consumed by MC-DPCPU protocol and must be  * initialised to zero  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_DATA_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_DATA_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_HDR_CMD_CMDNUM_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_HDR_CMD_CMDNUM_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CMDNUM_TXDPCPU_READ
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CMDNUM_TXDPCPU_WRITE
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CMDNUM_TXDPCPU_SELF_TEST
value|0xc
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CMDNUM_TXDPCPU_CSR_ACCESS
value|0xe
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CMDNUM_RXDPCPU_READ
value|0x46
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CMDNUM_RXDPCPU_WRITE
value|0x47
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CMDNUM_RXDPCPU_SELF_TEST
value|0x4a
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CMDNUM_RXDPCPU_CSR_ACCESS
value|0x4c
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CMDNUM_RXDPCPU_SET_MC_REPLAY_CNTXT
value|0x4d
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_HDR_CMD_REQ_OBJID_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_HDR_CMD_REQ_OBJID_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_HDR_CMD_REQ_ADDR_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_HDR_CMD_REQ_ADDR_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_HDR_CMD_REQ_COUNT_LBN
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_HDR_CMD_REQ_COUNT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_INFO_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_INFO_WIDTH
value|240
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_CMD_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_CMD_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_CMD_STOP_RETURN_RESULT
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_CMD_START_READ
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_CMD_START_WRITE
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_CMD_START_WRITE_READ
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_CMD_START_PIPELINED_READ
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_START_DELAY_LBN
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_START_DELAY_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_RPT_COUNT_LBN
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_RPT_COUNT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_GAP_DELAY_LBN
value|80
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_GAP_DELAY_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_MC_REPLAY_MODE_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_MC_REPLAY_MODE_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_MC_REPLAY_MODE_CUT_THROUGH
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_MC_REPLAY_MODE_STORE_FORWARD
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_MC_REPLAY_MODE_STORE_FORWARD_FIRST
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_MC_REPLAY_CNTXT_LBN
value|64
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_MC_REPLAY_CNTXT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_WDATA_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_WDATA_LEN
value|24
end_define

begin_comment
comment|/* Register data to write. Only valid in write/write-read. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_DATA_OFST
value|16
end_define

begin_comment
comment|/* Register address. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_IN_CSR_ACCESS_ADDRESS_OFST
value|20
end_define

begin_comment
comment|/* MC_CMD_DPCPU_RPC_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_LEN
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_RC_OFST
value|0
end_define

begin_comment
comment|/* DATA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_DATA_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_DATA_LEN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_HDR_CMD_RESP_ERRCODE_LBN
value|32
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_HDR_CMD_RESP_ERRCODE_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_CSR_ACCESS_READ_COUNT_LBN
value|48
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_CSR_ACCESS_READ_COUNT_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_RDATA_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_RDATA_LEN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_CSR_ACCESS_READ_VAL_1_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_CSR_ACCESS_READ_VAL_2_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_CSR_ACCESS_READ_VAL_3_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_DPCPU_RPC_OUT_CSR_ACCESS_READ_VAL_4_OFST
value|24
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_TRIGGER_INTERRUPT  * Trigger an interrupt by prodding the BIU.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TRIGGER_INTERRUPT
value|0xe3
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xe3_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xe3_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_TRIGGER_INTERRUPT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TRIGGER_INTERRUPT_IN_LEN
value|4
end_define

begin_comment
comment|/* Interrupt level relative to base for function. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TRIGGER_INTERRUPT_IN_INTR_LEVEL_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_TRIGGER_INTERRUPT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_TRIGGER_INTERRUPT_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SHMBOOT_OP  * Special operations to support (for now) shmboot.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SHMBOOT_OP
value|0xe6
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xe6_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xe6_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_SHMBOOT_OP_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SHMBOOT_OP_IN_LEN
value|4
end_define

begin_comment
comment|/* Identifies the operation to perform */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SHMBOOT_OP_IN_SHMBOOT_OP_OFST
value|0
end_define

begin_comment
comment|/* enum: Copy slave_data section to the slave core. (Greenport only) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SHMBOOT_OP_IN_PUSH_SLAVE_DATA
value|0x0
end_define

begin_comment
comment|/* MC_CMD_SHMBOOT_OP_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SHMBOOT_OP_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_CAP_BLK_READ  * Read multiple 64bit words from capture block memory  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ
value|0xe7
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xe7_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xe7_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_CAP_BLK_READ_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_IN_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_IN_CAP_REG_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_IN_ADDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_IN_COUNT_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_CAP_BLK_READ_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_OUT_LENMIN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_OUT_LENMAX
value|248
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+8*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_OUT_BUFFER_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_OUT_BUFFER_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_OUT_BUFFER_LO_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_OUT_BUFFER_HI_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_OUT_BUFFER_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_CAP_BLK_READ_OUT_BUFFER_MAXNUM
value|31
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DUMP_DO  * Take a dump of the DUT state  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO
value|0xe8
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xe8_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xe8_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_DUMP_DO_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_LEN
value|52
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_PADDING_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_CUSTOM
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_DEFAULT
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_CUSTOM_TYPE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMP_LOCATION_NVRAM
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMP_LOCATION_HOST_MEMORY
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMP_LOCATION_HOST_MEMORY_MLI
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMP_LOCATION_UART
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_CUSTOM_NVRAM_PARTITION_TYPE_ID_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_CUSTOM_NVRAM_OFFSET_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_CUSTOM_HOST_MEMORY_ADDR_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_CUSTOM_HOST_MEMORY_ADDR_HI_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_CUSTOM_HOST_MEMORY_MLI_ROOT_ADDR_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_HOST_MEMORY_MLI_PAGE_SIZE
value|0x1000
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_CUSTOM_HOST_MEMORY_MLI_ROOT_ADDR_HI_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_CUSTOM_HOST_MEMORY_MLI_DEPTH_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_HOST_MEMORY_MLI_MAX_DEPTH
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_CUSTOM_UART_PORT_OFST
value|12
end_define

begin_comment
comment|/* enum: The uart port this command was received over (if using a uart  * transport)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_UART_PORT_SRC
value|0xff
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPSPEC_SRC_CUSTOM_SIZE_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_OFST
value|28
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_CUSTOM
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_NVRAM_DUMP_PARTITION
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_CUSTOM_TYPE_OFST
value|32
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_DUMP_DO_IN/DUMPSPEC_SRC_CUSTOM_TYPE */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_CUSTOM_NVRAM_PARTITION_TYPE_ID_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_CUSTOM_NVRAM_OFFSET_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_CUSTOM_HOST_MEMORY_ADDR_LO_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_CUSTOM_HOST_MEMORY_ADDR_HI_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_CUSTOM_HOST_MEMORY_MLI_ROOT_ADDR_LO_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_CUSTOM_HOST_MEMORY_MLI_ROOT_ADDR_HI_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_CUSTOM_HOST_MEMORY_MLI_DEPTH_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_CUSTOM_UART_PORT_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_IN_DUMPFILE_DST_CUSTOM_SIZE_OFST
value|48
end_define

begin_comment
comment|/* MC_CMD_DUMP_DO_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_DO_OUT_DUMPFILE_SIZE_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_DUMP_CONFIGURE_UNSOLICITED  * Configure unsolicited dumps  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED
value|0xe9
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xe9_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xe9_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_LEN
value|52
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_ENABLE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPSPEC_SRC_OFST
value|4
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_DUMP_DO/MC_CMD_DUMP_DO_IN/DUMPSPEC_SRC */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPSPEC_SRC_CUSTOM_TYPE_OFST
value|8
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_DUMP_DO/MC_CMD_DUMP_DO_IN/DUMPSPEC_SRC_CUSTOM_TYPE */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPSPEC_SRC_CUSTOM_NVRAM_PARTITION_TYPE_ID_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPSPEC_SRC_CUSTOM_NVRAM_OFFSET_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPSPEC_SRC_CUSTOM_HOST_MEMORY_ADDR_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPSPEC_SRC_CUSTOM_HOST_MEMORY_ADDR_HI_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPSPEC_SRC_CUSTOM_HOST_MEMORY_MLI_ROOT_ADDR_LO_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPSPEC_SRC_CUSTOM_HOST_MEMORY_MLI_ROOT_ADDR_HI_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPSPEC_SRC_CUSTOM_HOST_MEMORY_MLI_DEPTH_OFST
value|20
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPSPEC_SRC_CUSTOM_UART_PORT_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPSPEC_SRC_CUSTOM_SIZE_OFST
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPFILE_DST_OFST
value|28
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_DUMP_DO/MC_CMD_DUMP_DO_IN/DUMPFILE_DST */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPFILE_DST_CUSTOM_TYPE_OFST
value|32
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_DUMP_DO/MC_CMD_DUMP_DO_IN/DUMPSPEC_SRC_CUSTOM_TYPE */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPFILE_DST_CUSTOM_NVRAM_PARTITION_TYPE_ID_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPFILE_DST_CUSTOM_NVRAM_OFFSET_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPFILE_DST_CUSTOM_HOST_MEMORY_ADDR_LO_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPFILE_DST_CUSTOM_HOST_MEMORY_ADDR_HI_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPFILE_DST_CUSTOM_HOST_MEMORY_MLI_ROOT_ADDR_LO_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPFILE_DST_CUSTOM_HOST_MEMORY_MLI_ROOT_ADDR_HI_OFST
value|40
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPFILE_DST_CUSTOM_HOST_MEMORY_MLI_DEPTH_OFST
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPFILE_DST_CUSTOM_UART_PORT_OFST
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_DUMP_CONFIGURE_UNSOLICITED_IN_DUMPFILE_DST_CUSTOM_SIZE_OFST
value|48
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_PSU  * Adjusts power supply parameters. This is a warranty-voiding operation.  * Returns: ENOENT if the parameter or rail specified does not exist, EINVAL if  * the parameter is out of range.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PSU
value|0xea
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xea_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xea_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_SET_PSU_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PSU_IN_LEN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PSU_IN_PARAM_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PSU_IN_PARAM_SUPPLY_VOLTAGE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PSU_IN_RAIL_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PSU_IN_RAIL_0V9
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PSU_IN_RAIL_1V2
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* desired value, eg voltage in mV */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PSU_IN_VALUE_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_SET_PSU_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PSU_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_FUNCTION_INFO  * Get function information. PF and VF number.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_FUNCTION_INFO
value|0xec
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xec_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xec_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_FUNCTION_INFO_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_FUNCTION_INFO_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_FUNCTION_INFO_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_FUNCTION_INFO_OUT_LEN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_FUNCTION_INFO_OUT_PF_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_FUNCTION_INFO_OUT_VF_OFST
value|4
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_ENABLE_OFFLINE_BIST  * Enters offline BIST mode. All queues are torn down, chip enters quiescent  * mode, calling function gets exclusive MCDI ownership. The only way out is  * reboot.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ENABLE_OFFLINE_BIST
value|0xed
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xed_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xed_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_ENABLE_OFFLINE_BIST_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ENABLE_OFFLINE_BIST_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_ENABLE_OFFLINE_BIST_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_ENABLE_OFFLINE_BIST_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_UART_SEND_DATA  * Send checksummed[sic] block of data over the uart. Response is a placeholder  * should we wish to make this reliable; currently requests are fire-and-  * forget.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA
value|0xee
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xee_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xee_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_UART_SEND_DATA_OUT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_OUT_LENMIN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(16+1*(num))
end_define

begin_comment
comment|/* CRC32 over OFFSET, LENGTH, RESERVED, DATA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_OUT_CHECKSUM_OFST
value|0
end_define

begin_comment
comment|/* Offset at which to write the data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_OUT_OFFSET_OFST
value|4
end_define

begin_comment
comment|/* Length of data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_OUT_LENGTH_OFST
value|8
end_define

begin_comment
comment|/* Reserved for future use */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_OUT_RESERVED_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_OUT_DATA_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_OUT_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_OUT_DATA_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_OUT_DATA_MAXNUM
value|236
end_define

begin_comment
comment|/* MC_CMD_UART_SEND_DATA_IN msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_SEND_DATA_IN_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_UART_RECV_DATA  * Request checksummed[sic] block of data over the uart. Only a placeholder,  * subject to change and not currently implemented.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA
value|0xef
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xef_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xef_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_UART_RECV_DATA_OUT msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_OUT_LEN
value|16
end_define

begin_comment
comment|/* CRC32 over OFFSET, LENGTH, RESERVED */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_OUT_CHECKSUM_OFST
value|0
end_define

begin_comment
comment|/* Offset from which to read the data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_OUT_OFFSET_OFST
value|4
end_define

begin_comment
comment|/* Length of data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_OUT_LENGTH_OFST
value|8
end_define

begin_comment
comment|/* Reserved for future use */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_OUT_RESERVED_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_UART_RECV_DATA_IN msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_IN_LENMIN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(16+1*(num))
end_define

begin_comment
comment|/* CRC32 over RESERVED1, RESERVED2, RESERVED3, DATA */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_IN_CHECKSUM_OFST
value|0
end_define

begin_comment
comment|/* Offset at which to write the data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_IN_RESERVED1_OFST
value|4
end_define

begin_comment
comment|/* Length of data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_IN_RESERVED2_OFST
value|8
end_define

begin_comment
comment|/* Reserved for future use */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_IN_RESERVED3_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_IN_DATA_OFST
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_IN_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_IN_DATA_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_UART_RECV_DATA_IN_DATA_MAXNUM
value|236
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_READ_FUSES  * Read data programmed into the device One-Time-Programmable (OTP) Fuses  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES
value|0xf0
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xf0_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xf0_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_READ_FUSES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES_IN_LEN
value|8
end_define

begin_comment
comment|/* Offset in OTP to read */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES_IN_OFFSET_OFST
value|0
end_define

begin_comment
comment|/* Length of data to read in bytes */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES_IN_LENGTH_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_READ_FUSES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+1*(num))
end_define

begin_comment
comment|/* Length of returned OTP data in bytes */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES_OUT_LENGTH_OFST
value|0
end_define

begin_comment
comment|/* Returned data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES_OUT_DATA_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES_OUT_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES_OUT_DATA_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_FUSES_OUT_DATA_MAXNUM
value|248
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_KR_TUNE  * Get or set KR Serdes RXEQ and TX Driver settings  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE
value|0xf1
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xf1_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xf1_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+4*(num))
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_KR_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_KR_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* enum: Get current RXEQ settings */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_RXEQ_GET
value|0x0
end_define

begin_comment
comment|/* enum: Override RXEQ settings */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_RXEQ_SET
value|0x1
end_define

begin_comment
comment|/* enum: Get current TX Driver settings */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_TXEQ_GET
value|0x2
end_define

begin_comment
comment|/* enum: Override TX Driver settings */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_TXEQ_SET
value|0x3
end_define

begin_comment
comment|/* enum: Force KR Serdes reset / recalibration */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_RECAL
value|0x4
end_define

begin_comment
comment|/* enum: Start KR Serdes Eye diagram plot on a given lane. Lane must have valid  * signal.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_START_EYE_PLOT
value|0x5
end_define

begin_comment
comment|/* enum: Poll KR Serdes Eye diagram plot. Returns one row of BER data. The  * caller should call this command repeatedly after starting eye plot, until no  * more data is returned.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_POLL_EYE_PLOT
value|0x6
end_define

begin_comment
comment|/* enum: Read Figure Of Merit (eye quality, higher is better). */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_READ_FOM
value|0x7
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_KR_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_KR_TUNE_RSVD_LEN
value|3
end_define

begin_comment
comment|/* Arguments specific to the operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_KR_TUNE_ARGS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_KR_TUNE_ARGS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_KR_TUNE_ARGS_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_IN_KR_TUNE_ARGS_MAXNUM
value|62
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_RXEQ_GET_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_IN_LEN
value|4
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_IN_KR_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_IN_KR_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_IN_KR_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_IN_KR_TUNE_RSVD_LEN
value|3
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_RXEQ_GET_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_comment
comment|/* RXEQ Parameter */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_MAXNUM
value|63
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_ID_WIDTH
value|8
end_define

begin_comment
comment|/* enum: Attenuation (0-15, TBD for Medford) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_ATT
value|0x0
end_define

begin_comment
comment|/* enum: CTLE Boost (0-15, TBD for Medford) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_BOOST
value|0x1
end_define

begin_comment
comment|/* enum: Edge DFE Tap1 (0 - max negative, 64 - zero, 127 - max positive, TBD  * for Medford)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_EDFE_TAP1
value|0x2
end_define

begin_comment
comment|/* enum: Edge DFE Tap2 (0 - max negative, 32 - zero, 63 - max positive, TBD for  * Medford)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_EDFE_TAP2
value|0x3
end_define

begin_comment
comment|/* enum: Edge DFE Tap3 (0 - max negative, 32 - zero, 63 - max positive, TBD for  * Medford)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_EDFE_TAP3
value|0x4
end_define

begin_comment
comment|/* enum: Edge DFE Tap4 (0 - max negative, 32 - zero, 63 - max positive, TBD for  * Medford)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_EDFE_TAP4
value|0x5
end_define

begin_comment
comment|/* enum: Edge DFE Tap5 (0 - max negative, 32 - zero, 63 - max positive, TBD for  * Medford)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_EDFE_TAP5
value|0x6
end_define

begin_comment
comment|/* enum: Edge DFE DLEV (TBD for Medford) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_EDFE_DLEV
value|0x7
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_LANE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_LANE_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_LANE_0
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_LANE_1
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_LANE_2
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_LANE_3
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_LANE_ALL
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_AUTOCAL_LBN
value|11
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_AUTOCAL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_RESERVED_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_RESERVED_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_INITIAL_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_INITIAL_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_CURRENT_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_GET_OUT_PARAM_CURRENT_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_RXEQ_SET_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_LENMIN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+4*(num))
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_KR_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_KR_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_KR_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_KR_TUNE_RSVD_LEN
value|3
end_define

begin_comment
comment|/* RXEQ Parameter */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_MAXNUM
value|62
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_ID_WIDTH
value|8
end_define

begin_comment
comment|/*             Enum values, see field(s): */
end_comment

begin_comment
comment|/*                MC_CMD_KR_TUNE_RXEQ_GET_OUT/PARAM_ID */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_LANE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_LANE_WIDTH
value|3
end_define

begin_comment
comment|/*             Enum values, see field(s): */
end_comment

begin_comment
comment|/*                MC_CMD_KR_TUNE_RXEQ_GET_OUT/PARAM_LANE */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_AUTOCAL_LBN
value|11
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_AUTOCAL_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_RESERVED_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_RESERVED_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_INITIAL_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_PARAM_INITIAL_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_RESERVED2_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_IN_RESERVED2_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_RXEQ_SET_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RXEQ_SET_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_TXEQ_GET_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_IN_LEN
value|4
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_IN_KR_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_IN_KR_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_IN_KR_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_IN_KR_TUNE_RSVD_LEN
value|3
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_TXEQ_GET_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_comment
comment|/* TXEQ Parameter */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_PARAM_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_PARAM_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_PARAM_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_PARAM_MAXNUM
value|63
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_PARAM_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_PARAM_ID_WIDTH
value|8
end_define

begin_comment
comment|/* enum: TX Amplitude */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_TX_LEV
value|0x0
end_define

begin_comment
comment|/* enum: De-Emphasis Tap1 Magnitude (0-7) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_TX_MODE
value|0x1
end_define

begin_comment
comment|/* enum: De-Emphasis Tap1 Fine */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_TX_DTLEV
value|0x2
end_define

begin_comment
comment|/* enum: De-Emphasis Tap2 Magnitude (0-6) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_TX_D2
value|0x3
end_define

begin_comment
comment|/* enum: De-Emphasis Tap2 Fine */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_TX_D2TLEV
value|0x4
end_define

begin_comment
comment|/* enum: Pre-Emphasis Magnitude */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_TX_E
value|0x5
end_define

begin_comment
comment|/* enum: Pre-Emphasis Fine */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_TX_ETLEV
value|0x6
end_define

begin_comment
comment|/* enum: TX Slew Rate Coarse control */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_TX_PREDRV_DLY
value|0x7
end_define

begin_comment
comment|/* enum: TX Slew Rate Fine control */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_TX_SR_SET
value|0x8
end_define

begin_comment
comment|/* enum: TX Termination Impedance control */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_TX_RT_SET
value|0x9
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_PARAM_LANE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_PARAM_LANE_WIDTH
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_LANE_0
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_LANE_1
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_LANE_2
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_LANE_3
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_LANE_ALL
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_RESERVED_LBN
value|11
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_RESERVED_WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_PARAM_INITIAL_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_PARAM_INITIAL_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_RESERVED2_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_GET_OUT_RESERVED2_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_TXEQ_SET_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_LENMIN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+4*(num))
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_KR_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_KR_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_KR_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_KR_TUNE_RSVD_LEN
value|3
end_define

begin_comment
comment|/* TXEQ Parameter */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_PARAM_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_PARAM_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_PARAM_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_PARAM_MAXNUM
value|62
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_PARAM_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_PARAM_ID_WIDTH
value|8
end_define

begin_comment
comment|/*             Enum values, see field(s): */
end_comment

begin_comment
comment|/*                MC_CMD_KR_TUNE_TXEQ_GET_OUT/PARAM_ID */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_PARAM_LANE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_PARAM_LANE_WIDTH
value|3
end_define

begin_comment
comment|/*             Enum values, see field(s): */
end_comment

begin_comment
comment|/*                MC_CMD_KR_TUNE_TXEQ_GET_OUT/PARAM_LANE */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_RESERVED_LBN
value|11
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_RESERVED_WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_PARAM_INITIAL_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_PARAM_INITIAL_WIDTH
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_RESERVED2_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_IN_RESERVED2_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_TXEQ_SET_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_TXEQ_SET_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_RECAL_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RECAL_IN_LEN
value|4
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RECAL_IN_KR_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RECAL_IN_KR_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RECAL_IN_KR_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RECAL_IN_KR_TUNE_RSVD_LEN
value|3
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_RECAL_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_RECAL_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_START_EYE_PLOT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_START_EYE_PLOT_IN_LEN
value|8
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_START_EYE_PLOT_IN_KR_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_START_EYE_PLOT_IN_KR_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_START_EYE_PLOT_IN_KR_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_START_EYE_PLOT_IN_KR_TUNE_RSVD_LEN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_START_EYE_PLOT_IN_LANE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_START_EYE_PLOT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_START_EYE_PLOT_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_POLL_EYE_PLOT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_IN_LEN
value|4
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_IN_KR_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_IN_KR_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_IN_KR_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_IN_KR_TUNE_RSVD_LEN
value|3
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_POLL_EYE_PLOT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_OUT_LENMIN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+2*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_OUT_SAMPLES_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_OUT_SAMPLES_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_OUT_SAMPLES_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_POLL_EYE_PLOT_OUT_SAMPLES_MAXNUM
value|126
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_READ_FOM_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_READ_FOM_IN_LEN
value|8
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_READ_FOM_IN_KR_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_READ_FOM_IN_KR_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_READ_FOM_IN_KR_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_READ_FOM_IN_KR_TUNE_RSVD_LEN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_READ_FOM_IN_LANE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_KR_TUNE_READ_FOM_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_READ_FOM_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_KR_TUNE_READ_FOM_OUT_FOM_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PCIE_TUNE  * Get or set PCIE Serdes RXEQ and TX Driver settings  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE
value|0xf2
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xf2_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xf2_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_PCIE_TUNE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+4*(num))
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_PCIE_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_PCIE_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* enum: Get current RXEQ settings */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_RXEQ_GET
value|0x0
end_define

begin_comment
comment|/* enum: Override RXEQ settings */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_RXEQ_SET
value|0x1
end_define

begin_comment
comment|/* enum: Get current TX Driver settings */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_TXEQ_GET
value|0x2
end_define

begin_comment
comment|/* enum: Override TX Driver settings */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_TXEQ_SET
value|0x3
end_define

begin_comment
comment|/* enum: Start PCIe Serdes Eye diagram plot on a given lane. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_START_EYE_PLOT
value|0x5
end_define

begin_comment
comment|/* enum: Poll PCIe Serdes Eye diagram plot. Returns one row of BER data. The  * caller should call this command repeatedly after starting eye plot, until no  * more data is returned.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_POLL_EYE_PLOT
value|0x6
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_PCIE_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_PCIE_TUNE_RSVD_LEN
value|3
end_define

begin_comment
comment|/* Arguments specific to the operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_PCIE_TUNE_ARGS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_PCIE_TUNE_ARGS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_PCIE_TUNE_ARGS_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_IN_PCIE_TUNE_ARGS_MAXNUM
value|62
end_define

begin_comment
comment|/* MC_CMD_PCIE_TUNE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_PCIE_TUNE_RXEQ_GET_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_IN_LEN
value|4
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_IN_PCIE_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_IN_PCIE_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_IN_PCIE_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_IN_PCIE_TUNE_RSVD_LEN
value|3
end_define

begin_comment
comment|/* MC_CMD_PCIE_TUNE_RXEQ_GET_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_comment
comment|/* RXEQ Parameter */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_PARAM_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_PARAM_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_PARAM_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_PARAM_MAXNUM
value|63
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_PARAM_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_PARAM_ID_WIDTH
value|8
end_define

begin_comment
comment|/* enum: Attenuation (0-15) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_ATT
value|0x0
end_define

begin_comment
comment|/* enum: CTLE Boost (0-15) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_BOOST
value|0x1
end_define

begin_comment
comment|/* enum: DFE Tap1 (0 - max negative, 64 - zero, 127 - max positive) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_DFE_TAP1
value|0x2
end_define

begin_comment
comment|/* enum: DFE Tap2 (0 - max negative, 32 - zero, 63 - max positive) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_DFE_TAP2
value|0x3
end_define

begin_comment
comment|/* enum: DFE Tap3 (0 - max negative, 32 - zero, 63 - max positive) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_DFE_TAP3
value|0x4
end_define

begin_comment
comment|/* enum: DFE Tap4 (0 - max negative, 32 - zero, 63 - max positive) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_DFE_TAP4
value|0x5
end_define

begin_comment
comment|/* enum: DFE Tap5 (0 - max negative, 32 - zero, 63 - max positive) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_DFE_TAP5
value|0x6
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_PARAM_LANE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_PARAM_LANE_WIDTH
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LANE_0
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LANE_1
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LANE_2
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LANE_3
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LANE_4
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LANE_5
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LANE_6
value|0x6
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LANE_7
value|0x7
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_LANE_ALL
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_RESERVED_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_RESERVED_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_PARAM_CURRENT_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_RXEQ_GET_OUT_PARAM_CURRENT_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_PCIE_TUNE_TXEQ_GET_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_IN_LEN
value|4
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_IN_PCIE_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_IN_PCIE_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_IN_PCIE_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_IN_PCIE_TUNE_RSVD_LEN
value|3
end_define

begin_comment
comment|/* MC_CMD_PCIE_TUNE_TXEQ_GET_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_comment
comment|/* RXEQ Parameter */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_PARAM_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_PARAM_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_PARAM_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_PARAM_MAXNUM
value|63
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_PARAM_ID_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_PARAM_ID_WIDTH
value|8
end_define

begin_comment
comment|/* enum: TxMargin (PIPE) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_TXMARGIN
value|0x0
end_define

begin_comment
comment|/* enum: TxSwing (PIPE) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_TXSWING
value|0x1
end_define

begin_comment
comment|/* enum: De-emphasis coefficient C(-1) (PIPE) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_CM1
value|0x2
end_define

begin_comment
comment|/* enum: De-emphasis coefficient C(0) (PIPE) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_C0
value|0x3
end_define

begin_comment
comment|/* enum: De-emphasis coefficient C(+1) (PIPE) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_CP1
value|0x4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_PARAM_LANE_LBN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_PARAM_LANE_WIDTH
value|4
end_define

begin_comment
comment|/*             Enum values, see field(s): */
end_comment

begin_comment
comment|/*                MC_CMD_PCIE_TUNE_RXEQ_GET_OUT/PARAM_LANE */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_RESERVED_LBN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_RESERVED_WIDTH
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_PARAM_CURRENT_LBN
value|24
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_TXEQ_GET_OUT_PARAM_CURRENT_WIDTH
value|8
end_define

begin_comment
comment|/* MC_CMD_PCIE_TUNE_START_EYE_PLOT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_START_EYE_PLOT_IN_LEN
value|8
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_START_EYE_PLOT_IN_PCIE_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_START_EYE_PLOT_IN_PCIE_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_START_EYE_PLOT_IN_PCIE_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_START_EYE_PLOT_IN_PCIE_TUNE_RSVD_LEN
value|3
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_START_EYE_PLOT_IN_LANE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_PCIE_TUNE_START_EYE_PLOT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_START_EYE_PLOT_OUT_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_IN_LEN
value|4
end_define

begin_comment
comment|/* Requested operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_IN_PCIE_TUNE_OP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_IN_PCIE_TUNE_OP_LEN
value|1
end_define

begin_comment
comment|/* Align the arguments to 32 bits */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_IN_PCIE_TUNE_RSVD_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_IN_PCIE_TUNE_RSVD_LEN
value|3
end_define

begin_comment
comment|/* MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_OUT_LENMIN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+2*(num))
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_OUT_SAMPLES_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_OUT_SAMPLES_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_OUT_SAMPLES_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PCIE_TUNE_POLL_EYE_PLOT_OUT_SAMPLES_MAXNUM
value|126
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_LICENSING  * Operations on the NVRAM_PARTITION_TYPE_LICENSE application license partition  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING
value|0xf3
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xf3_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xf3_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_LICENSING_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_IN_LEN
value|4
end_define

begin_comment
comment|/* identifies the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_IN_OP_OFST
value|0
end_define

begin_comment
comment|/* enum: re-read and apply licenses after a license key partition update; note  * that this operation returns a zero-length response  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_IN_OP_UPDATE_LICENSE
value|0x0
end_define

begin_comment
comment|/* enum: report counts of installed licenses */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_IN_OP_GET_KEY_STATS
value|0x1
end_define

begin_comment
comment|/* MC_CMD_LICENSING_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_OUT_LEN
value|28
end_define

begin_comment
comment|/* count of application keys which are valid */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_OUT_VALID_APP_KEYS_OFST
value|0
end_define

begin_comment
comment|/* sum of UNVERIFIABLE_APP_KEYS + WRONG_NODE_APP_KEYS (for compatibility with  * MC_CMD_FC_OP_LICENSE)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_OUT_INVALID_APP_KEYS_OFST
value|4
end_define

begin_comment
comment|/* count of application keys which are invalid due to being blacklisted */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_OUT_BLACKLISTED_APP_KEYS_OFST
value|8
end_define

begin_comment
comment|/* count of application keys which are invalid due to being unverifiable */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_OUT_UNVERIFIABLE_APP_KEYS_OFST
value|12
end_define

begin_comment
comment|/* count of application keys which are invalid due to being for the wrong node  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_OUT_WRONG_NODE_APP_KEYS_OFST
value|16
end_define

begin_comment
comment|/* licensing state (for diagnostics; the exact meaning of the bits in this  * field are private to the firmware)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_OUT_LICENSING_STATE_OFST
value|20
end_define

begin_comment
comment|/* licensing subsystem self-test report (for manftest) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_OUT_LICENSING_SELF_TEST_OFST
value|24
end_define

begin_comment
comment|/* enum: licensing subsystem self-test failed */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_OUT_SELF_TEST_FAIL
value|0x0
end_define

begin_comment
comment|/* enum: licensing subsystem self-test passed */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSING_OUT_SELF_TEST_PASS
value|0x1
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_MC2MC_PROXY  * Execute an arbitrary MCDI command on the slave MC of a dual-core device.  * This will fail on a single-core system.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MC2MC_PROXY
value|0xf4
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xf4_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xf4_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_MC2MC_PROXY_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MC2MC_PROXY_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_MC2MC_PROXY_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_MC2MC_PROXY_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_LICENSED_APP_STATE  * Query the state of an individual licensed application. (Note that the actual  * state may be invalidated by the MC_CMD_LICENSING OP_UPDATE_LICENSE operation  * or a reboot of the MC.)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LICENSED_APP_STATE
value|0xf5
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xf5_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xf5_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_LICENSED_APP_STATE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LICENSED_APP_STATE_IN_LEN
value|4
end_define

begin_comment
comment|/* application ID to query (LICENSED_APP_ID_xxx) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LICENSED_APP_STATE_IN_APP_ID_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_LICENSED_APP_STATE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LICENSED_APP_STATE_OUT_LEN
value|4
end_define

begin_comment
comment|/* state of this application */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LICENSED_APP_STATE_OUT_STATE_OFST
value|0
end_define

begin_comment
comment|/* enum: no (or invalid) license is present for the application */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LICENSED_APP_STATE_OUT_NOT_LICENSED
value|0x0
end_define

begin_comment
comment|/* enum: a valid license is present for the application */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_LICENSED_APP_STATE_OUT_LICENSED
value|0x1
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_LICENSED_APP_OP  * Perform an action for an individual licensed application.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP
value|0xf6
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xf6_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xf6_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_LICENSED_APP_OP_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_IN_LENMIN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(8+4*(num))
end_define

begin_comment
comment|/* application ID */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_IN_APP_ID_OFST
value|0
end_define

begin_comment
comment|/* the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_IN_OP_OFST
value|4
end_define

begin_comment
comment|/* enum: validate application */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_IN_OP_VALIDATE
value|0x0
end_define

begin_comment
comment|/* enum: mask application */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_IN_OP_MASK
value|0x1
end_define

begin_comment
comment|/* arguments specific to this particular operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_IN_ARGS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_IN_ARGS_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_IN_ARGS_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_IN_ARGS_MAXNUM
value|61
end_define

begin_comment
comment|/* MC_CMD_LICENSED_APP_OP_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_OUT_LENMIN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_comment
comment|/* result specific to this particular operation */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_OUT_RESULT_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_OUT_RESULT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_OUT_RESULT_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_OUT_RESULT_MAXNUM
value|63
end_define

begin_comment
comment|/* MC_CMD_LICENSED_APP_OP_VALIDATE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_VALIDATE_IN_LEN
value|72
end_define

begin_comment
comment|/* application ID */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_VALIDATE_IN_APP_ID_OFST
value|0
end_define

begin_comment
comment|/* the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_VALIDATE_IN_OP_OFST
value|4
end_define

begin_comment
comment|/* validation challenge */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_VALIDATE_IN_CHALLENGE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_VALIDATE_IN_CHALLENGE_LEN
value|64
end_define

begin_comment
comment|/* MC_CMD_LICENSED_APP_OP_VALIDATE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_VALIDATE_OUT_LEN
value|68
end_define

begin_comment
comment|/* feature expiry (time_t) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_VALIDATE_OUT_EXPIRY_OFST
value|0
end_define

begin_comment
comment|/* validation response */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_VALIDATE_OUT_RESPONSE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_VALIDATE_OUT_RESPONSE_LEN
value|64
end_define

begin_comment
comment|/* MC_CMD_LICENSED_APP_OP_MASK_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_MASK_IN_LEN
value|12
end_define

begin_comment
comment|/* application ID */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_MASK_IN_APP_ID_OFST
value|0
end_define

begin_comment
comment|/* the type of operation requested */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_MASK_IN_OP_OFST
value|4
end_define

begin_comment
comment|/* flag */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_MASK_IN_FLAG_OFST
value|8
end_define

begin_comment
comment|/* MC_CMD_LICENSED_APP_OP_MASK_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LICENSED_APP_OP_MASK_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_PORT_SNIFF_CONFIG  * Configure RX port sniffing for the physical port associated with the calling  * function. Only a privileged function may change the port sniffing  * configuration. A copy of all traffic delivered to the host (non-promiscuous  * mode) or all traffic arriving at the port (promiscuous mode) may be  * delivered to a specific queue, or a set of queues with RSS.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG
value|0xf7
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xf7_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xf7_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_SET_PORT_SNIFF_CONFIG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_IN_LEN
value|16
end_define

begin_comment
comment|/* configuration flags */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_IN_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_IN_ENABLE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_IN_ENABLE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_IN_PROMISCUOUS_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_IN_PROMISCUOUS_WIDTH
value|1
end_define

begin_comment
comment|/* receive queue handle (for RSS mode, this is the base queue) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_IN_RX_QUEUE_OFST
value|4
end_define

begin_comment
comment|/* receive mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_IN_RX_MODE_OFST
value|8
end_define

begin_comment
comment|/* enum: receive to just the specified queue */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_IN_RX_MODE_SIMPLE
value|0x0
end_define

begin_comment
comment|/* enum: receive to multiple queues using RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_IN_RX_MODE_RSS
value|0x1
end_define

begin_comment
comment|/* RSS context (for RX_MODE_RSS) as returned by MC_CMD_RSS_CONTEXT_ALLOC. Note  * that these handles should be considered opaque to the host, although a value  * of 0xFFFFFFFF is guaranteed never to be a valid handle.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_IN_RX_CONTEXT_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_SET_PORT_SNIFF_CONFIG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PORT_SNIFF_CONFIG_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PORT_SNIFF_CONFIG  * Obtain the current RX port sniffing configuration for the physical port  * associated with the calling function. Only a privileged function may read  * the configuration.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG
value|0xf8
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xf8_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xf8_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_GET_PORT_SNIFF_CONFIG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_PORT_SNIFF_CONFIG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_OUT_LEN
value|16
end_define

begin_comment
comment|/* configuration flags */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_OUT_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_OUT_ENABLE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_OUT_ENABLE_WIDTH
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_OUT_PROMISCUOUS_LBN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_OUT_PROMISCUOUS_WIDTH
value|1
end_define

begin_comment
comment|/* receiving queue handle (for RSS mode, this is the base queue) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_OUT_RX_QUEUE_OFST
value|4
end_define

begin_comment
comment|/* receive mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_OUT_RX_MODE_OFST
value|8
end_define

begin_comment
comment|/* enum: receiving to just the specified queue */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_OUT_RX_MODE_SIMPLE
value|0x0
end_define

begin_comment
comment|/* enum: receiving to multiple queues using RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_OUT_RX_MODE_RSS
value|0x1
end_define

begin_comment
comment|/* RSS context (for RX_MODE_RSS) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_SNIFF_CONFIG_OUT_RX_CONTEXT_OFST
value|12
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_PARSER_DISP_CONFIG  * Change configuration related to the parser-dispatcher subsystem.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG
value|0xf9
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xf9_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xf9_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_SET_PARSER_DISP_CONFIG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_IN_LENMIN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(8+4*(num))
end_define

begin_comment
comment|/* the type of configuration setting to change */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/* enum: Per-TXQ enable for multicast UDP destination lookup for possible  * internal loopback. (ENTITY is a queue handle, VALUE is a single boolean.)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_IN_TXQ_MCAST_UDP_DST_LOOKUP_EN
value|0x0
end_define

begin_comment
comment|/* enum: Per-v-adaptor enable for suppression of self-transmissions on the  * internal loopback path. (ENTITY is an EVB_PORT_ID, VALUE is a single  * boolean.)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_IN_VADAPTOR_SUPPRESS_SELF_TX
value|0x1
end_define

begin_comment
comment|/* handle for the entity to update: queue handle, EVB port ID, etc. depending  * on the type of configuration setting being changed  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_IN_ENTITY_OFST
value|4
end_define

begin_comment
comment|/* new value: the details depend on the type of configuration setting being  * changed  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_IN_VALUE_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_IN_VALUE_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_IN_VALUE_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_IN_VALUE_MAXNUM
value|61
end_define

begin_comment
comment|/* MC_CMD_SET_PARSER_DISP_CONFIG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_PARSER_DISP_CONFIG_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PARSER_DISP_CONFIG  * Read configuration related to the parser-dispatcher subsystem.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_CONFIG
value|0xfa
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xfa_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xfa_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_PARSER_DISP_CONFIG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_CONFIG_IN_LEN
value|8
end_define

begin_comment
comment|/* the type of configuration setting to read */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_CONFIG_IN_TYPE_OFST
value|0
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_SET_PARSER_DISP_CONFIG/MC_CMD_SET_PARSER_DISP_CONFIG_IN/TYPE */
end_comment

begin_comment
comment|/* handle for the entity to query: queue handle, EVB port ID, etc. depending on  * the type of configuration setting being read  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_CONFIG_IN_ENTITY_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_GET_PARSER_DISP_CONFIG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_CONFIG_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_CONFIG_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_CONFIG_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+4*(num))
end_define

begin_comment
comment|/* current value: the details depend on the type of configuration setting being  * read  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_CONFIG_OUT_VALUE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_CONFIG_OUT_VALUE_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_CONFIG_OUT_VALUE_MINNUM
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_PARSER_DISP_CONFIG_OUT_VALUE_MAXNUM
value|63
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_SET_TX_PORT_SNIFF_CONFIG  * Configure TX port sniffing for the physical port associated with the calling  * function. Only a privileged function may change the port sniffing  * configuration. A copy of all traffic transmitted through the port may be  * delivered to a specific queue, or a set of queues with RSS. Note that these  * packets are delivered with transmit timestamps in the packet prefix, not  * receive timestamps, so it is likely that the queue(s) will need to be  * dedicated as TX sniff receivers.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TX_PORT_SNIFF_CONFIG
value|0xfb
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xfb_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xfb_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_SET_TX_PORT_SNIFF_CONFIG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TX_PORT_SNIFF_CONFIG_IN_LEN
value|16
end_define

begin_comment
comment|/* configuration flags */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TX_PORT_SNIFF_CONFIG_IN_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TX_PORT_SNIFF_CONFIG_IN_ENABLE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_SET_TX_PORT_SNIFF_CONFIG_IN_ENABLE_WIDTH
value|1
end_define

begin_comment
comment|/* receive queue handle (for RSS mode, this is the base queue) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TX_PORT_SNIFF_CONFIG_IN_RX_QUEUE_OFST
value|4
end_define

begin_comment
comment|/* receive mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TX_PORT_SNIFF_CONFIG_IN_RX_MODE_OFST
value|8
end_define

begin_comment
comment|/* enum: receive to just the specified queue */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TX_PORT_SNIFF_CONFIG_IN_RX_MODE_SIMPLE
value|0x0
end_define

begin_comment
comment|/* enum: receive to multiple queues using RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TX_PORT_SNIFF_CONFIG_IN_RX_MODE_RSS
value|0x1
end_define

begin_comment
comment|/* RSS context (for RX_MODE_RSS) as returned by MC_CMD_RSS_CONTEXT_ALLOC. Note  * that these handles should be considered opaque to the host, although a value  * of 0xFFFFFFFF is guaranteed never to be a valid handle.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TX_PORT_SNIFF_CONFIG_IN_RX_CONTEXT_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_SET_TX_PORT_SNIFF_CONFIG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_SET_TX_PORT_SNIFF_CONFIG_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_TX_PORT_SNIFF_CONFIG  * Obtain the current TX port sniffing configuration for the physical port  * associated with the calling function. Only a privileged function may read  * the configuration.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TX_PORT_SNIFF_CONFIG
value|0xfc
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xfc_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xfc_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_GET_TX_PORT_SNIFF_CONFIG_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TX_PORT_SNIFF_CONFIG_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_TX_PORT_SNIFF_CONFIG_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TX_PORT_SNIFF_CONFIG_OUT_LEN
value|16
end_define

begin_comment
comment|/* configuration flags */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TX_PORT_SNIFF_CONFIG_OUT_FLAGS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TX_PORT_SNIFF_CONFIG_OUT_ENABLE_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_TX_PORT_SNIFF_CONFIG_OUT_ENABLE_WIDTH
value|1
end_define

begin_comment
comment|/* receiving queue handle (for RSS mode, this is the base queue) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TX_PORT_SNIFF_CONFIG_OUT_RX_QUEUE_OFST
value|4
end_define

begin_comment
comment|/* receive mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TX_PORT_SNIFF_CONFIG_OUT_RX_MODE_OFST
value|8
end_define

begin_comment
comment|/* enum: receiving to just the specified queue */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TX_PORT_SNIFF_CONFIG_OUT_RX_MODE_SIMPLE
value|0x0
end_define

begin_comment
comment|/* enum: receiving to multiple queues using RSS context */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TX_PORT_SNIFF_CONFIG_OUT_RX_MODE_RSS
value|0x1
end_define

begin_comment
comment|/* RSS context (for RX_MODE_RSS) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_TX_PORT_SNIFF_CONFIG_OUT_RX_CONTEXT_OFST
value|12
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_RMON_STATS_RX_ERRORS  * Per queue rx error stats.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RMON_STATS_RX_ERRORS
value|0xfe
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xfe_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xfe_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_RMON_STATS_RX_ERRORS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RMON_STATS_RX_ERRORS_IN_LEN
value|8
end_define

begin_comment
comment|/* The rx queue to get stats for. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RMON_STATS_RX_ERRORS_IN_RX_QUEUE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_RMON_STATS_RX_ERRORS_IN_FLAGS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RMON_STATS_RX_ERRORS_IN_RST_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_RMON_STATS_RX_ERRORS_IN_RST_WIDTH
value|1
end_define

begin_comment
comment|/* MC_CMD_RMON_STATS_RX_ERRORS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_RMON_STATS_RX_ERRORS_OUT_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_RMON_STATS_RX_ERRORS_OUT_CRC_ERRORS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_RMON_STATS_RX_ERRORS_OUT_TRUNC_ERRORS_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_RMON_STATS_RX_ERRORS_OUT_RX_NO_DESC_DROPS_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_RMON_STATS_RX_ERRORS_OUT_RX_ABORT_OFST
value|12
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PCIE_RESOURCE_INFO  * Find out about available PCIE resources  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PCIE_RESOURCE_INFO
value|0xfd
end_define

begin_comment
comment|/* MC_CMD_GET_PCIE_RESOURCE_INFO_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PCIE_RESOURCE_INFO_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_PCIE_RESOURCE_INFO_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PCIE_RESOURCE_INFO_OUT_LEN
value|28
end_define

begin_comment
comment|/* The maximum number of PFs the device can expose */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PCIE_RESOURCE_INFO_OUT_MAX_PFS_OFST
value|0
end_define

begin_comment
comment|/* The maximum number of VFs the device can expose in total */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PCIE_RESOURCE_INFO_OUT_MAX_VFS_OFST
value|4
end_define

begin_comment
comment|/* The maximum number of MSI-X vectors the device can provide in total */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PCIE_RESOURCE_INFO_OUT_MAX_VECTORS_OFST
value|8
end_define

begin_comment
comment|/* the number of MSI-X vectors the device will allocate by default to each PF  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PCIE_RESOURCE_INFO_OUT_DEFAULT_PF_VECTORS_OFST
value|12
end_define

begin_comment
comment|/* the number of MSI-X vectors the device will allocate by default to each VF  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PCIE_RESOURCE_INFO_OUT_DEFAULT_VF_VECTORS_OFST
value|16
end_define

begin_comment
comment|/* the maximum number of MSI-X vectors the device can allocate to any one PF */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PCIE_RESOURCE_INFO_OUT_MAX_PF_VECTORS_OFST
value|20
end_define

begin_comment
comment|/* the maximum number of MSI-X vectors the device can allocate to any one VF */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PCIE_RESOURCE_INFO_OUT_MAX_VF_VECTORS_OFST
value|24
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_PORT_MODES  * Find out about available port modes  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_MODES
value|0xff
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0xff_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0xff_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_PORT_MODES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_MODES_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_PORT_MODES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_MODES_OUT_LEN
value|12
end_define

begin_comment
comment|/* Bitmask of port modes available on the board (indexed by TLV_PORT_MODE_*) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_MODES_OUT_MODES_OFST
value|0
end_define

begin_comment
comment|/* Default (canonical) board mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_MODES_OUT_DEFAULT_MODE_OFST
value|4
end_define

begin_comment
comment|/* Current board mode */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_PORT_MODES_OUT_CURRENT_MODE_OFST
value|8
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_READ_ATB  * Sample voltages on the ATB  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_ATB
value|0x100
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x100_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x100_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_READ_ATB_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_ATB_IN_LEN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_ATB_IN_SIGNAL_BUS_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_ATB_IN_BUS_CCOM
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_ATB_IN_BUS_CKR
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_ATB_IN_BUS_CPCIE
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_ATB_IN_SIGNAL_EN_BITNO_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_ATB_IN_SIGNAL_SEL_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_ATB_IN_SETTLING_TIME_US_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_READ_ATB_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_READ_ATB_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_READ_ATB_OUT_SAMPLE_MV_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_WORKAROUNDS  * Read the list of all implemented and all currently enabled workarounds. The  * enums here must correspond with those in MC_CMD_WORKAROUND.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_WORKAROUNDS
value|0x59
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x59_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x59_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_WORKAROUNDS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_WORKAROUNDS_OUT_LEN
value|8
end_define

begin_comment
comment|/* Each workaround is represented by a single bit according to the enums below.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_WORKAROUNDS_OUT_IMPLEMENTED_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_GET_WORKAROUNDS_OUT_ENABLED_OFST
value|4
end_define

begin_comment
comment|/* enum: Bug 17230 work around. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_WORKAROUNDS_OUT_BUG17230
value|0x2
end_define

begin_comment
comment|/* enum: Bug 35388 work around (unsafe EVQ writes). */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_WORKAROUNDS_OUT_BUG35388
value|0x4
end_define

begin_comment
comment|/* enum: Bug35017 workaround (A64 tables must be identity map) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_WORKAROUNDS_OUT_BUG35017
value|0x8
end_define

begin_comment
comment|/* enum: Bug 41750 present (MC_CMD_TRIGGER_INTERRUPT won't work) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_WORKAROUNDS_OUT_BUG41750
value|0x10
end_define

begin_comment
comment|/* enum: Bug 42008 present (Interrupts can overtake associated events). Caution  * - before adding code that queries this workaround, remember that there's  * released Monza firmware that doesn't understand MC_CMD_WORKAROUND_BUG42008,  * and will hence (incorrectly) report that the bug doesn't exist.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_WORKAROUNDS_OUT_BUG42008
value|0x20
end_define

begin_comment
comment|/* enum: Bug 26807 features present in firmware (multicast filter chaining) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_WORKAROUNDS_OUT_BUG26807
value|0x40
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PRIVILEGE_MASK  * Read/set privileges of an arbitrary PCIe function  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK
value|0x5a
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x5a_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x5a_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_PRIVILEGE_MASK_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_LEN
value|8
end_define

begin_comment
comment|/* The target function to have its mask read or set e.g. PF 0 = 0xFFFF0000, VF  * 1,3 = 0x00030001  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_FUNCTION_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_FUNCTION_PF_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_FUNCTION_PF_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_FUNCTION_VF_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_FUNCTION_VF_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_VF_NULL
value|0xffff
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* New privilege mask to be set. The mask will only be changed if the MSB is  * set to 1.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_NEW_MASK_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_GRP_ADMIN
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_GRP_LINK
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_GRP_ONLOAD
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_GRP_PTP
value|0x8
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_GRP_INSECURE_FILTERS
value|0x10
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_GRP_MAC_SPOOFING
value|0x20
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_GRP_UNICAST
value|0x40
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_GRP_MULTICAST
value|0x80
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_GRP_BROADCAST
value|0x100
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_GRP_ALL_MULTICAST
value|0x200
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_GRP_PROMISCUOUS
value|0x400
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* enum: Set this bit to indicate that a new privilege mask is to be set,  * otherwise the command will only read the existing mask.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_IN_DO_CHANGE
value|0x80000000
end_define

begin_comment
comment|/* MC_CMD_PRIVILEGE_MASK_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_OUT_LEN
value|4
end_define

begin_comment
comment|/* For an admin function, always all the privileges are reported. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MASK_OUT_OLD_MASK_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_LINK_STATE_MODE  * Read/set link state mode of a VF  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE
value|0x5c
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x5c_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x5c_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_LINK_STATE_MODE_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_IN_LEN
value|8
end_define

begin_comment
comment|/* The target function to have its link state mode read or set, must be a VF  * e.g. VF 1,3 = 0x00030001  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_IN_FUNCTION_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_IN_FUNCTION_PF_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_IN_FUNCTION_PF_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_IN_FUNCTION_VF_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_IN_FUNCTION_VF_WIDTH
value|16
end_define

begin_comment
comment|/* New link state mode to be set */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_IN_NEW_MODE_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_IN_LINK_STATE_AUTO
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_IN_LINK_STATE_UP
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_IN_LINK_STATE_DOWN
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* enum: Use this value to just read the existing setting without modifying it.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_IN_DO_NOT_CHANGE
value|0xffffffff
end_define

begin_comment
comment|/* MC_CMD_LINK_STATE_MODE_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_OUT_LEN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_LINK_STATE_MODE_OUT_OLD_MODE_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_GET_SNAPSHOT_LENGTH  * Obtain the curent range of allowable values for the SNAPSHOT_LENGTH  * parameter to MC_CMD_INIT_RXQ.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_SNAPSHOT_LENGTH
value|0x101
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x101_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x101_PRIVILEGE_CTG
value|SRIOV_CTG_GENERAL
end_define

begin_comment
comment|/* MC_CMD_GET_SNAPSHOT_LENGTH_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_SNAPSHOT_LENGTH_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_GET_SNAPSHOT_LENGTH_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_SNAPSHOT_LENGTH_OUT_LEN
value|8
end_define

begin_comment
comment|/* Minimum acceptable snapshot length. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_SNAPSHOT_LENGTH_OUT_RX_SNAPLEN_MIN_OFST
value|0
end_define

begin_comment
comment|/* Maximum acceptable snapshot length. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_GET_SNAPSHOT_LENGTH_OUT_RX_SNAPLEN_MAX_OFST
value|4
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_FUSE_DIAGS  * Additional fuse diagnostics  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS
value|0x102
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x102_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x102_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_FUSE_DIAGS_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_FUSE_DIAGS_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_LEN
value|48
end_define

begin_comment
comment|/* Total number of mismatched bits between pairs in area 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA0_MISMATCH_BITS_OFST
value|0
end_define

begin_comment
comment|/* Total number of unexpectedly clear (set in B but not A) bits in area 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA0_PAIR_A_BAD_BITS_OFST
value|4
end_define

begin_comment
comment|/* Total number of unexpectedly clear (set in A but not B) bits in area 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA0_PAIR_B_BAD_BITS_OFST
value|8
end_define

begin_comment
comment|/* Checksum of data after logical OR of pairs in area 0 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA0_CHECKSUM_OFST
value|12
end_define

begin_comment
comment|/* Total number of mismatched bits between pairs in area 1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA1_MISMATCH_BITS_OFST
value|16
end_define

begin_comment
comment|/* Total number of unexpectedly clear (set in B but not A) bits in area 1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA1_PAIR_A_BAD_BITS_OFST
value|20
end_define

begin_comment
comment|/* Total number of unexpectedly clear (set in A but not B) bits in area 1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA1_PAIR_B_BAD_BITS_OFST
value|24
end_define

begin_comment
comment|/* Checksum of data after logical OR of pairs in area 1 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA1_CHECKSUM_OFST
value|28
end_define

begin_comment
comment|/* Total number of mismatched bits between pairs in area 2 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA2_MISMATCH_BITS_OFST
value|32
end_define

begin_comment
comment|/* Total number of unexpectedly clear (set in B but not A) bits in area 2 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA2_PAIR_A_BAD_BITS_OFST
value|36
end_define

begin_comment
comment|/* Total number of unexpectedly clear (set in A but not B) bits in area 2 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA2_PAIR_B_BAD_BITS_OFST
value|40
end_define

begin_comment
comment|/* Checksum of data after logical OR of pairs in area 2 */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_FUSE_DIAGS_OUT_AREA2_CHECKSUM_OFST
value|44
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_PRIVILEGE_MODIFY  * Modify the privileges of a set of PCIe functions. Note that this operation  * only effects non-admin functions unless the admin privilege itself is  * included in one of the masks provided.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY
value|0x60
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x60_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x60_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_PRIVILEGE_MODIFY_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_LEN
value|16
end_define

begin_comment
comment|/* The groups of functions to have their privilege masks modified. */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_FN_GROUP_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_NONE
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_ALL
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_PFS_ONLY
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_VFS_ONLY
value|0x3
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_VFS_OF_PF
value|0x4
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_ONE
value|0x5
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* For VFS_OF_PF specify the PF, for ONE specify the target function */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_FUNCTION_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_FUNCTION_PF_LBN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_FUNCTION_PF_WIDTH
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_FUNCTION_VF_LBN
value|16
end_define

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_FUNCTION_VF_WIDTH
value|16
end_define

begin_comment
comment|/* Privileges to be added to the target functions. For privilege definitions  * refer to the command MC_CMD_PRIVILEGE_MASK  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_ADD_MASK_OFST
value|8
end_define

begin_comment
comment|/* Privileges to be removed from the target functions. For privilege  * definitions refer to the command MC_CMD_PRIVILEGE_MASK  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_IN_REMOVE_MASK_OFST
value|12
end_define

begin_comment
comment|/* MC_CMD_PRIVILEGE_MODIFY_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_PRIVILEGE_MODIFY_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_XPM_READ_BYTES  * Read XPM memory  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_BYTES
value|0x103
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x103_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x103_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_XPM_READ_BYTES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_BYTES_IN_LEN
value|8
end_define

begin_comment
comment|/* Start address (byte) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_BYTES_IN_ADDR_OFST
value|0
end_define

begin_comment
comment|/* Count (bytes) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_BYTES_IN_COUNT_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_XPM_READ_BYTES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_BYTES_OUT_LENMIN
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_BYTES_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_BYTES_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(0+1*(num))
end_define

begin_comment
comment|/* Data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_BYTES_OUT_DATA_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_BYTES_OUT_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_BYTES_OUT_DATA_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_BYTES_OUT_DATA_MAXNUM
value|252
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_XPM_WRITE_BYTES  * Write XPM memory  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_BYTES
value|0x104
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x104_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x104_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_XPM_WRITE_BYTES_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_BYTES_IN_LENMIN
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_BYTES_IN_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_BYTES_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(8+1*(num))
end_define

begin_comment
comment|/* Start address (byte) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_BYTES_IN_ADDR_OFST
value|0
end_define

begin_comment
comment|/* Count (bytes) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_BYTES_IN_COUNT_OFST
value|4
end_define

begin_comment
comment|/* Data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_BYTES_IN_DATA_OFST
value|8
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_BYTES_IN_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_BYTES_IN_DATA_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_BYTES_IN_DATA_MAXNUM
value|244
end_define

begin_comment
comment|/* MC_CMD_XPM_WRITE_BYTES_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_BYTES_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_XPM_READ_SECTOR  * Read XPM sector  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR
value|0x105
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x105_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x105_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_XPM_READ_SECTOR_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_IN_LEN
value|8
end_define

begin_comment
comment|/* Sector index */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_IN_INDEX_OFST
value|0
end_define

begin_comment
comment|/* Sector size */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_IN_SIZE_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_XPM_READ_SECTOR_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_LENMAX
value|36
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+1*(num))
end_define

begin_comment
comment|/* Sector type */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_TYPE_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_BLANK
value|0x0
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_CRYPTO_KEY_128
value|0x1
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_CRYPTO_KEY_256
value|0x2
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_INVALID
value|0xff
end_define

begin_comment
comment|/* enum */
end_comment

begin_comment
comment|/* Sector data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_DATA_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_DATA_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_READ_SECTOR_OUT_DATA_MAXNUM
value|32
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_XPM_WRITE_SECTOR  * Write XPM sector  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR
value|0x106
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x106_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x106_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_XPM_WRITE_SECTOR_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_LENMIN
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_LENMAX
value|44
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_LEN
parameter_list|(
name|num
parameter_list|)
value|(12+1*(num))
end_define

begin_comment
comment|/* If writing fails due to an uncorrectable error, try up to RETRIES following  * sectors (or until no more space available). If 0, only one write attempt is  * made. Note that uncorrectable errors are unlikely, thanks to XPM self-repair  * mechanism.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_RETRIES_OFST
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_RETRIES_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_RESERVED_OFST
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_RESERVED_LEN
value|3
end_define

begin_comment
comment|/* Sector type */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_TYPE_OFST
value|4
end_define

begin_comment
comment|/*            Enum values, see field(s): */
end_comment

begin_comment
comment|/*               MC_CMD_XPM_READ_SECTOR_OUT/TYPE */
end_comment

begin_comment
comment|/* Sector size */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_SIZE_OFST
value|8
end_define

begin_comment
comment|/* Sector data */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_DATA_OFST
value|12
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_DATA_LEN
value|1
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_DATA_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_IN_DATA_MAXNUM
value|32
end_define

begin_comment
comment|/* MC_CMD_XPM_WRITE_SECTOR_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_OUT_LEN
value|4
end_define

begin_comment
comment|/* New sector index */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_SECTOR_OUT_INDEX_OFST
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_XPM_INVALIDATE_SECTOR  * Invalidate XPM sector  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_INVALIDATE_SECTOR
value|0x107
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x107_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x107_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_XPM_INVALIDATE_SECTOR_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_INVALIDATE_SECTOR_IN_LEN
value|4
end_define

begin_comment
comment|/* Sector index */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_INVALIDATE_SECTOR_IN_INDEX_OFST
value|0
end_define

begin_comment
comment|/* MC_CMD_XPM_INVALIDATE_SECTOR_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_INVALIDATE_SECTOR_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_XPM_BLANK_CHECK  * Blank-check XPM memory and report bad locations  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK
value|0x108
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x108_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x108_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_XPM_BLANK_CHECK_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK_IN_LEN
value|8
end_define

begin_comment
comment|/* Start address (byte) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK_IN_ADDR_OFST
value|0
end_define

begin_comment
comment|/* Count (bytes) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK_IN_COUNT_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_XPM_BLANK_CHECK_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK_OUT_LENMIN
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK_OUT_LENMAX
value|252
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK_OUT_LEN
parameter_list|(
name|num
parameter_list|)
value|(4+2*(num))
end_define

begin_comment
comment|/* Total number of bad (non-blank) locations */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK_OUT_BAD_COUNT_OFST
value|0
end_define

begin_comment
comment|/* Addresses of bad locations (may be less than BAD_COUNT, if all cannot fit  * into MCDI response)  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK_OUT_BAD_ADDR_OFST
value|4
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK_OUT_BAD_ADDR_LEN
value|2
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK_OUT_BAD_ADDR_MINNUM
value|0
end_define

begin_define
define|#
directive|define
name|MC_CMD_XPM_BLANK_CHECK_OUT_BAD_ADDR_MAXNUM
value|124
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_XPM_REPAIR  * Blank-check and repair XPM memory  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_REPAIR
value|0x109
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x109_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x109_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_XPM_REPAIR_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_REPAIR_IN_LEN
value|8
end_define

begin_comment
comment|/* Start address (byte) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_REPAIR_IN_ADDR_OFST
value|0
end_define

begin_comment
comment|/* Count (bytes) */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_REPAIR_IN_COUNT_OFST
value|4
end_define

begin_comment
comment|/* MC_CMD_XPM_REPAIR_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_REPAIR_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_XPM_DECODER_TEST  * Test XPM memory address decoders for gross manufacturing defects. Can only  * be performed on an unprogrammed part.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_DECODER_TEST
value|0x10a
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x10a_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x10a_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_XPM_DECODER_TEST_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_DECODER_TEST_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_XPM_DECODER_TEST_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_DECODER_TEST_OUT_LEN
value|0
end_define

begin_comment
comment|/***********************************/
end_comment

begin_comment
comment|/* MC_CMD_XPM_WRITE_TEST  * XPM memory write test. Test XPM write logic for gross manufacturing defects  * by writing to a dedicated test row. There are 16 locations in the test row  * and the test can only be performed on locations that have not been  * previously used (i.e. can be run at most 16 times). The test will pick the  * first available location to use, or fail with ENOSPC if none left.  */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_TEST
value|0x10b
end_define

begin_undef
undef|#
directive|undef
name|MC_CMD_0x10b_PRIVILEGE_CTG
end_undef

begin_define
define|#
directive|define
name|MC_CMD_0x10b_PRIVILEGE_CTG
value|SRIOV_CTG_ADMIN
end_define

begin_comment
comment|/* MC_CMD_XPM_WRITE_TEST_IN msgrequest */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_TEST_IN_LEN
value|0
end_define

begin_comment
comment|/* MC_CMD_XPM_WRITE_TEST_OUT msgresponse */
end_comment

begin_define
define|#
directive|define
name|MC_CMD_XPM_WRITE_TEST_OUT_LEN
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

