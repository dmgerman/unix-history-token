begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  *       Copyright (c) 2000-01 Intel Corporation  *       All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_comment
comment|/*  *  * iir.h:       Definitions/Constants used by the Intel Integrated RAID driver  *  * Written by: 	Achim Leubner<achim.leubner@intel.com>  * Fixes/Additions:	Boji Tony Kannanthanam<boji.t.kannanthanam@intel.com>  *  * credits:     Niklas Hallqvist;       OpenBSD driver for the ICP Controllers.  *              FreeBSD.ORG;            Great O/S to work on and for.  */
end_comment

begin_empty
empty|#ident "$Id: iir.h 1.3 2001/07/03 11:28:57 achim Exp $"
end_empty

begin_ifndef
ifndef|#
directive|ifndef
name|_IIR_H
end_ifndef

begin_define
define|#
directive|define
name|_IIR_H
end_define

begin_define
define|#
directive|define
name|IIR_DRIVER_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|IIR_DRIVER_SUBVERSION
value|1
end_define

begin_define
define|#
directive|define
name|IIR_CDEV_MAJOR
value|164
end_define

begin_define
define|#
directive|define
name|GDT_VENDOR_ID
value|0x1119
end_define

begin_define
define|#
directive|define
name|GDT_DEVICE_ID_MIN
value|0x100
end_define

begin_define
define|#
directive|define
name|GDT_DEVICE_ID_MAX
value|0x2ff
end_define

begin_define
define|#
directive|define
name|GDT_DEVICE_ID_NEWRX
value|0x300
end_define

begin_define
define|#
directive|define
name|INTEL_VENDOR_ID
value|0x8086
end_define

begin_define
define|#
directive|define
name|INTEL_DEVICE_ID_IIR
value|0x600
end_define

begin_define
define|#
directive|define
name|GDT_MAXBUS
value|6
end_define

begin_comment
comment|/* XXX Why not 5? */
end_comment

begin_define
define|#
directive|define
name|GDT_MAX_HDRIVES
value|100
end_define

begin_comment
comment|/* max 100 host drives */
end_comment

begin_define
define|#
directive|define
name|GDT_MAXID_FC
value|127
end_define

begin_comment
comment|/* Fibre-channel IDs */
end_comment

begin_define
define|#
directive|define
name|GDT_MAXID
value|16
end_define

begin_comment
comment|/* SCSI IDs */
end_comment

begin_define
define|#
directive|define
name|GDT_MAXOFFSETS
value|128
end_define

begin_define
define|#
directive|define
name|GDT_MAXSG
value|32
end_define

begin_comment
comment|/* Max. s/g elements */
end_comment

begin_define
define|#
directive|define
name|GDT_PROTOCOL_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|GDT_LINUX_OS
value|8
end_define

begin_comment
comment|/* Used for cache optimization */
end_comment

begin_define
define|#
directive|define
name|GDT_SCATTER_GATHER
value|1
end_define

begin_comment
comment|/* s/g feature */
end_comment

begin_define
define|#
directive|define
name|GDT_SECS32
value|0x1f
end_define

begin_comment
comment|/* round capacity */
end_comment

begin_define
define|#
directive|define
name|GDT_LOCALBOARD
value|0
end_define

begin_comment
comment|/* Board node always 0 */
end_comment

begin_define
define|#
directive|define
name|GDT_MAXCMDS
value|124
end_define

begin_define
define|#
directive|define
name|GDT_SECTOR_SIZE
value|0x200
end_define

begin_comment
comment|/* Always 512 bytes for cache devs */
end_comment

begin_define
define|#
directive|define
name|GDT_MAX_EVENTS
value|0x100
end_define

begin_comment
comment|/* event buffer */
end_comment

begin_comment
comment|/* DPMEM constants */
end_comment

begin_define
define|#
directive|define
name|GDT_MPR_MAGIC
value|0xc0ffee11
end_define

begin_define
define|#
directive|define
name|GDT_IC_HEADER_BYTES
value|48
end_define

begin_define
define|#
directive|define
name|GDT_IC_QUEUE_BYTES
value|4
end_define

begin_define
define|#
directive|define
name|GDT_DPMEM_COMMAND_OFFSET
define|\
value|(GDT_IC_HEADER_BYTES + GDT_IC_QUEUE_BYTES * GDT_MAXOFFSETS)
end_define

begin_comment
comment|/* geometry constants */
end_comment

begin_define
define|#
directive|define
name|GDT_MAXCYLS
value|1024
end_define

begin_define
define|#
directive|define
name|GDT_HEADS
value|64
end_define

begin_define
define|#
directive|define
name|GDT_SECS
value|32
end_define

begin_comment
comment|/* mapping 64*32 */
end_comment

begin_define
define|#
directive|define
name|GDT_MEDHEADS
value|127
end_define

begin_define
define|#
directive|define
name|GDT_MEDSECS
value|63
end_define

begin_comment
comment|/* mapping 127*63 */
end_comment

begin_define
define|#
directive|define
name|GDT_BIGHEADS
value|255
end_define

begin_define
define|#
directive|define
name|GDT_BIGSECS
value|63
end_define

begin_comment
comment|/* mapping 255*63 */
end_comment

begin_comment
comment|/* data direction raw service */
end_comment

begin_define
define|#
directive|define
name|GDT_DATA_IN
value|0x01000000L
end_define

begin_define
define|#
directive|define
name|GDT_DATA_OUT
value|0x00000000L
end_define

begin_comment
comment|/* Cache/raw service commands */
end_comment

begin_define
define|#
directive|define
name|GDT_INIT
value|0
end_define

begin_comment
comment|/* service initialization */
end_comment

begin_define
define|#
directive|define
name|GDT_READ
value|1
end_define

begin_comment
comment|/* read command */
end_comment

begin_define
define|#
directive|define
name|GDT_WRITE
value|2
end_define

begin_comment
comment|/* write command */
end_comment

begin_define
define|#
directive|define
name|GDT_INFO
value|3
end_define

begin_comment
comment|/* information about devices */
end_comment

begin_define
define|#
directive|define
name|GDT_FLUSH
value|4
end_define

begin_comment
comment|/* flush dirty cache buffers */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL
value|5
end_define

begin_comment
comment|/* ioctl command */
end_comment

begin_define
define|#
directive|define
name|GDT_DEVTYPE
value|9
end_define

begin_comment
comment|/* additional information */
end_comment

begin_define
define|#
directive|define
name|GDT_MOUNT
value|10
end_define

begin_comment
comment|/* mount cache device */
end_comment

begin_define
define|#
directive|define
name|GDT_UNMOUNT
value|11
end_define

begin_comment
comment|/* unmount cache device */
end_comment

begin_define
define|#
directive|define
name|GDT_SET_FEAT
value|12
end_define

begin_comment
comment|/* set features (scatter/gather) */
end_comment

begin_define
define|#
directive|define
name|GDT_GET_FEAT
value|13
end_define

begin_comment
comment|/* get features */
end_comment

begin_define
define|#
directive|define
name|GDT_WRITE_THR
value|16
end_define

begin_comment
comment|/* write through */
end_comment

begin_define
define|#
directive|define
name|GDT_READ_THR
value|17
end_define

begin_comment
comment|/* read through */
end_comment

begin_define
define|#
directive|define
name|GDT_EXT_INFO
value|18
end_define

begin_comment
comment|/* extended info */
end_comment

begin_define
define|#
directive|define
name|GDT_RESET
value|19
end_define

begin_comment
comment|/* controller reset */
end_comment

begin_define
define|#
directive|define
name|GDT_FREEZE_IO
value|25
end_define

begin_comment
comment|/* freeze all IOs */
end_comment

begin_define
define|#
directive|define
name|GDT_UNFREEZE_IO
value|26
end_define

begin_comment
comment|/* unfreeze all IOs */
end_comment

begin_comment
comment|/* Additional raw service commands */
end_comment

begin_define
define|#
directive|define
name|GDT_RESERVE
value|14
end_define

begin_comment
comment|/* reserve device to raw service */
end_comment

begin_define
define|#
directive|define
name|GDT_RELEASE
value|15
end_define

begin_comment
comment|/* release device */
end_comment

begin_define
define|#
directive|define
name|GDT_RESERVE_ALL
value|16
end_define

begin_comment
comment|/* reserve all devices */
end_comment

begin_define
define|#
directive|define
name|GDT_RELEASE_ALL
value|17
end_define

begin_comment
comment|/* release all devices */
end_comment

begin_define
define|#
directive|define
name|GDT_RESET_BUS
value|18
end_define

begin_comment
comment|/* reset bus */
end_comment

begin_define
define|#
directive|define
name|GDT_SCAN_START
value|19
end_define

begin_comment
comment|/* start device scan */
end_comment

begin_define
define|#
directive|define
name|GDT_SCAN_END
value|20
end_define

begin_comment
comment|/* stop device scan */
end_comment

begin_comment
comment|/* IOCTL command defines */
end_comment

begin_define
define|#
directive|define
name|GDT_SCSI_DR_INFO
value|0x00
end_define

begin_comment
comment|/* SCSI drive info */
end_comment

begin_define
define|#
directive|define
name|GDT_SCSI_CHAN_CNT
value|0x05
end_define

begin_comment
comment|/* SCSI channel count */
end_comment

begin_define
define|#
directive|define
name|GDT_SCSI_DR_LIST
value|0x06
end_define

begin_comment
comment|/* SCSI drive list */
end_comment

begin_define
define|#
directive|define
name|GDT_SCSI_DEF_CNT
value|0x15
end_define

begin_comment
comment|/* grown/primary defects */
end_comment

begin_define
define|#
directive|define
name|GDT_DSK_STATISTICS
value|0x4b
end_define

begin_comment
comment|/* SCSI disk statistics */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCHAN_DESC
value|0x5d
end_define

begin_comment
comment|/* description of IO channel */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCHAN_RAW_DESC
value|0x5e
end_define

begin_comment
comment|/* description of raw IO channel */
end_comment

begin_define
define|#
directive|define
name|GDT_L_CTRL_PATTERN
value|0x20000000
end_define

begin_comment
comment|/* SCSI IOCTL mask */
end_comment

begin_define
define|#
directive|define
name|GDT_ARRAY_INFO
value|0x12
end_define

begin_comment
comment|/* array drive info */
end_comment

begin_define
define|#
directive|define
name|GDT_ARRAY_DRV_LIST
value|0x0f
end_define

begin_comment
comment|/* array drive list */
end_comment

begin_define
define|#
directive|define
name|GDT_LA_CTRL_PATTERN
value|0x10000000
end_define

begin_comment
comment|/* array IOCTL mask */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_DRV_CNT
value|0x01
end_define

begin_comment
comment|/* cache drive count */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_DRV_LIST
value|0x02
end_define

begin_comment
comment|/* cache drive list */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_INFO
value|0x04
end_define

begin_comment
comment|/* cache info */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_CONFIG
value|0x05
end_define

begin_comment
comment|/* cache configuration */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_DRV_INFO
value|0x07
end_define

begin_comment
comment|/* cache drive info */
end_comment

begin_define
define|#
directive|define
name|GDT_BOARD_FEATURES
value|0x15
end_define

begin_comment
comment|/* controller features */
end_comment

begin_define
define|#
directive|define
name|GDT_BOARD_INFO
value|0x28
end_define

begin_comment
comment|/* controller info */
end_comment

begin_define
define|#
directive|define
name|GDT_HOST_GET
value|0x10001
end_define

begin_comment
comment|/* get host drive list */
end_comment

begin_define
define|#
directive|define
name|GDT_IO_CHANNEL
value|0x20000
end_define

begin_comment
comment|/* default IO channel */
end_comment

begin_define
define|#
directive|define
name|GDT_INVALID_CHANNEL
value|0xffff
end_define

begin_comment
comment|/* invalid channel */
end_comment

begin_comment
comment|/* IOCTLs */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_GENERAL
value|_IOWR('J', 0, gdt_ucmd_t)
end_define

begin_comment
comment|/* general IOCTL */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_DRVERS
value|_IOWR('J', 1, int)
end_define

begin_comment
comment|/* get driver version */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_CTRTYPE
value|_IOR('J', 2, gdt_ctrt_t)
end_define

begin_comment
comment|/* get ctr. type */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_OSVERS
value|_IOR('J', 3, gdt_osv_t)
end_define

begin_comment
comment|/* get OS version */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_CTRCNT
value|_IOR('J', 5, int)
end_define

begin_comment
comment|/* get ctr. count */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_EVENT
value|_IOWR('J', 8, gdt_event_t)
end_define

begin_comment
comment|/* get event */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_STATIST
value|_IOR('J', 9, gdt_statist_t)
end_define

begin_comment
comment|/* get statistics */
end_comment

begin_comment
comment|/* Service errors */
end_comment

begin_define
define|#
directive|define
name|GDT_S_OK
value|1
end_define

begin_comment
comment|/* no error */
end_comment

begin_define
define|#
directive|define
name|GDT_S_BSY
value|7
end_define

begin_comment
comment|/* controller busy */
end_comment

begin_define
define|#
directive|define
name|GDT_S_RAW_SCSI
value|12
end_define

begin_comment
comment|/* raw service: target error */
end_comment

begin_define
define|#
directive|define
name|GDT_S_RAW_ILL
value|0xff
end_define

begin_comment
comment|/* raw service: illegal */
end_comment

begin_define
define|#
directive|define
name|GDT_S_NO_STATUS
value|0x1000
end_define

begin_comment
comment|/* got no status (driver-generated) */
end_comment

begin_comment
comment|/* Controller services */
end_comment

begin_define
define|#
directive|define
name|GDT_SCSIRAWSERVICE
value|3
end_define

begin_define
define|#
directive|define
name|GDT_CACHESERVICE
value|9
end_define

begin_define
define|#
directive|define
name|GDT_SCREENSERVICE
value|11
end_define

begin_comment
comment|/* Scatter/gather element */
end_comment

begin_define
define|#
directive|define
name|GDT_SG_PTR
value|0x00
end_define

begin_comment
comment|/* u_int32_t, address */
end_comment

begin_define
define|#
directive|define
name|GDT_SG_LEN
value|0x04
end_define

begin_comment
comment|/* u_int32_t, length */
end_comment

begin_define
define|#
directive|define
name|GDT_SG_SZ
value|0x08
end_define

begin_comment
comment|/* Cache service command */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_DEVICENO
value|0x00
end_define

begin_comment
comment|/* u_int16_t, number of cache drive */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_BLOCKNO
value|0x02
end_define

begin_comment
comment|/* u_int32_t, block number */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_BLOCKCNT
value|0x06
end_define

begin_comment
comment|/* u_int32_t, block count */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_DESTADDR
value|0x0a
end_define

begin_comment
comment|/* u_int32_t, dest. addr. (-1: s/g) */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_SG_CANZ
value|0x0e
end_define

begin_comment
comment|/* u_int32_t, s/g element count */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_SG_LST
value|0x12
end_define

begin_comment
comment|/* [GDT_MAXSG], s/g list */
end_comment

begin_define
define|#
directive|define
name|GDT_CACHE_SZ
value|(0x12 + GDT_MAXSG * GDT_SG_SZ)
end_define

begin_comment
comment|/* Ioctl command */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_PARAM_SIZE
value|0x00
end_define

begin_comment
comment|/* u_int16_t, size of buffer */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_SUBFUNC
value|0x02
end_define

begin_comment
comment|/* u_int32_t, ioctl function */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_CHANNEL
value|0x06
end_define

begin_comment
comment|/* u_int32_t, device */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_P_PARAM
value|0x0a
end_define

begin_comment
comment|/* u_int32_t, buffer */
end_comment

begin_define
define|#
directive|define
name|GDT_IOCTL_SZ
value|0x0e
end_define

begin_comment
comment|/* Screen service defines */
end_comment

begin_define
define|#
directive|define
name|GDT_MSG_INV_HANDLE
value|-1
end_define

begin_comment
comment|/* special message handle */
end_comment

begin_define
define|#
directive|define
name|GDT_MSGLEN
value|16
end_define

begin_comment
comment|/* size of message text */
end_comment

begin_define
define|#
directive|define
name|GDT_MSG_SIZE
value|34
end_define

begin_comment
comment|/* size of message structure */
end_comment

begin_define
define|#
directive|define
name|GDT_MSG_REQUEST
value|0
end_define

begin_comment
comment|/* async. event. message */
end_comment

begin_comment
comment|/* Screen service command */
end_comment

begin_define
define|#
directive|define
name|GDT_SCREEN_MSG_HANDLE
value|0x02
end_define

begin_comment
comment|/* u_int32_t, message handle */
end_comment

begin_define
define|#
directive|define
name|GDT_SCREEN_MSG_ADDR
value|0x06
end_define

begin_comment
comment|/* u_int32_t, message buffer address */
end_comment

begin_define
define|#
directive|define
name|GDT_SCREEN_SZ
value|0x0a
end_define

begin_comment
comment|/* Screen service message */
end_comment

begin_define
define|#
directive|define
name|GDT_SCR_MSG_HANDLE
value|0x00
end_define

begin_comment
comment|/* u_int32_t, message handle */
end_comment

begin_define
define|#
directive|define
name|GDT_SCR_MSG_LEN
value|0x04
end_define

begin_comment
comment|/* u_int32_t, size of message */
end_comment

begin_define
define|#
directive|define
name|GDT_SCR_MSG_ALEN
value|0x08
end_define

begin_comment
comment|/* u_int32_t, answer length */
end_comment

begin_define
define|#
directive|define
name|GDT_SCR_MSG_ANSWER
value|0x0c
end_define

begin_comment
comment|/* u_int8_t, answer flag */
end_comment

begin_define
define|#
directive|define
name|GDT_SCR_MSG_EXT
value|0x0d
end_define

begin_comment
comment|/* u_int8_t, more messages? */
end_comment

begin_define
define|#
directive|define
name|GDT_SCR_MSG_RES
value|0x0e
end_define

begin_comment
comment|/* u_int16_t, reserved */
end_comment

begin_define
define|#
directive|define
name|GDT_SCR_MSG_TEXT
value|0x10
end_define

begin_comment
comment|/* GDT_MSGLEN+2, message text */
end_comment

begin_define
define|#
directive|define
name|GDT_SCR_MSG_SZ
value|(0x12 + GDT_MSGLEN)
end_define

begin_comment
comment|/* Raw service command */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_DIRECTION
value|0x02
end_define

begin_comment
comment|/* u_int32_t, data direction */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_MDISC_TIME
value|0x06
end_define

begin_comment
comment|/* u_int32_t, disc. time (0: none) */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_MCON_TIME
value|0x0a
end_define

begin_comment
comment|/* u_int32_t, conn. time (0: none) */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_SDATA
value|0x0e
end_define

begin_comment
comment|/* u_int32_t, dest. addr. (-1: s/g) */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_SDLEN
value|0x12
end_define

begin_comment
comment|/* u_int32_t, data length */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_CLEN
value|0x16
end_define

begin_comment
comment|/* u_int32_t, SCSI cmd len (6/10/12) */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_CMD
value|0x1a
end_define

begin_comment
comment|/* u_int8_t [12], SCSI command */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_TARGET
value|0x26
end_define

begin_comment
comment|/* u_int8_t, target ID */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_LUN
value|0x27
end_define

begin_comment
comment|/* u_int8_t, LUN */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_BUS
value|0x28
end_define

begin_comment
comment|/* u_int8_t, SCSI bus number */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_PRIORITY
value|0x29
end_define

begin_comment
comment|/* u_int8_t, only 0 used */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_SENSE_LEN
value|0x2a
end_define

begin_comment
comment|/* u_int32_t, sense data length */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_SENSE_DATA
value|0x2e
end_define

begin_comment
comment|/* u_int32_t, sense data address */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_SG_RANZ
value|0x36
end_define

begin_comment
comment|/* u_int32_t, s/g element count */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_SG_LST
value|0x3a
end_define

begin_comment
comment|/* [GDT_MAXSG], s/g list */
end_comment

begin_define
define|#
directive|define
name|GDT_RAW_SZ
value|(0x3a + GDT_MAXSG * GDT_SG_SZ)
end_define

begin_comment
comment|/* Command structure */
end_comment

begin_define
define|#
directive|define
name|GDT_CMD_BOARDNODE
value|0x00
end_define

begin_comment
comment|/* u_int32_t, board node (always 0) */
end_comment

begin_define
define|#
directive|define
name|GDT_CMD_COMMANDINDEX
value|0x04
end_define

begin_comment
comment|/* u_int32_t, command number */
end_comment

begin_define
define|#
directive|define
name|GDT_CMD_OPCODE
value|0x08
end_define

begin_comment
comment|/* u_int16_t, opcode (READ, ...) */
end_comment

begin_define
define|#
directive|define
name|GDT_CMD_UNION
value|0x0a
end_define

begin_comment
comment|/* cache/screen/raw service command */
end_comment

begin_define
define|#
directive|define
name|GDT_CMD_UNION_SZ
value|GDT_RAW_SZ
end_define

begin_define
define|#
directive|define
name|GDT_CMD_SZ
value|(0x0a + GDT_CMD_UNION_SZ)
end_define

begin_comment
comment|/* Command queue entries */
end_comment

begin_define
define|#
directive|define
name|GDT_OFFSET
value|0x00
end_define

begin_comment
comment|/* u_int16_t, command offset in the DP RAM */
end_comment

begin_define
define|#
directive|define
name|GDT_SERV_ID
value|0x02
end_define

begin_comment
comment|/* u_int16_t, service */
end_comment

begin_define
define|#
directive|define
name|GDT_COMM_Q_SZ
value|0x04
end_define

begin_comment
comment|/* Interface area */
end_comment

begin_define
define|#
directive|define
name|GDT_S_CMD_INDX
value|0x00
end_define

begin_comment
comment|/* u_int8_t, special command */
end_comment

begin_define
define|#
directive|define
name|GDT_S_STATUS
value|0x01
end_define

begin_comment
comment|/* volatile u_int8_t, status special command */
end_comment

begin_define
define|#
directive|define
name|GDT_S_INFO
value|0x04
end_define

begin_comment
comment|/* u_int32_t [4], add. info special command */
end_comment

begin_define
define|#
directive|define
name|GDT_SEMA0
value|0x14
end_define

begin_comment
comment|/* volatile u_int8_t, command semaphore */
end_comment

begin_define
define|#
directive|define
name|GDT_CMD_INDEX
value|0x18
end_define

begin_comment
comment|/* u_int8_t, command number */
end_comment

begin_define
define|#
directive|define
name|GDT_STATUS
value|0x1c
end_define

begin_comment
comment|/* volatile u_int16_t, command status */
end_comment

begin_define
define|#
directive|define
name|GDT_SERVICE
value|0x1e
end_define

begin_comment
comment|/* u_int16_t, service (for asynch. events) */
end_comment

begin_define
define|#
directive|define
name|GDT_DPR_INFO
value|0x20
end_define

begin_comment
comment|/* u_int32_t [2], additional info */
end_comment

begin_define
define|#
directive|define
name|GDT_COMM_QUEUE
value|0x28
end_define

begin_comment
comment|/* command queue */
end_comment

begin_define
define|#
directive|define
name|GDT_DPR_CMD
value|(0x30 + GDT_MAXOFFSETS * GDT_COMM_Q_SZ)
end_define

begin_comment
comment|/* u_int8_t [], commands */
end_comment

begin_comment
comment|/* I/O channel header */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_VERSION
value|0x00
end_define

begin_comment
comment|/* u_int32_t, version (~0: newest) */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_LIST_ENTRIES
value|0x04
end_define

begin_comment
comment|/* u_int8_t, list entry count */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_FIRST_CHAN
value|0x05
end_define

begin_comment
comment|/* u_int8_t, first channel number */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_LAST_CHAN
value|0x06
end_define

begin_comment
comment|/* u_int8_t, last channel number */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_CHAN_COUNT
value|0x07
end_define

begin_comment
comment|/* u_int8_t, (R) channel count */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_LIST_OFFSET
value|0x08
end_define

begin_comment
comment|/* u_int32_t, offset of list[0] */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_HDR_SZ
value|0x0c
end_define

begin_define
define|#
directive|define
name|GDT_IOC_NEWEST
value|0xffffffff
end_define

begin_comment
comment|/* goes into GDT_IOC_VERSION */
end_comment

begin_comment
comment|/* Get I/O channel description */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_ADDRESS
value|0x00
end_define

begin_comment
comment|/* u_int32_t, channel address */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_TYPE
value|0x04
end_define

begin_comment
comment|/* u_int8_t, type (SCSI/FCSL) */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_LOCAL_NO
value|0x05
end_define

begin_comment
comment|/* u_int8_t, local number */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_FEATURES
value|0x06
end_define

begin_comment
comment|/* u_int16_t, channel features */
end_comment

begin_define
define|#
directive|define
name|GDT_IOC_SZ
value|0x08
end_define

begin_comment
comment|/* Get raw I/O channel description */
end_comment

begin_define
define|#
directive|define
name|GDT_RAWIOC_PROC_ID
value|0x00
end_define

begin_comment
comment|/* u_int8_t, processor id */
end_comment

begin_define
define|#
directive|define
name|GDT_RAWIOC_PROC_DEFECT
value|0x01
end_define

begin_comment
comment|/* u_int8_t, defect? */
end_comment

begin_define
define|#
directive|define
name|GDT_RAWIOC_SZ
value|0x04
end_define

begin_comment
comment|/* Get SCSI channel count */
end_comment

begin_define
define|#
directive|define
name|GDT_GETCH_CHANNEL_NO
value|0x00
end_define

begin_comment
comment|/* u_int32_t, channel number */
end_comment

begin_define
define|#
directive|define
name|GDT_GETCH_DRIVE_CNT
value|0x04
end_define

begin_comment
comment|/* u_int32_t, drive count */
end_comment

begin_define
define|#
directive|define
name|GDT_GETCH_SIOP_ID
value|0x08
end_define

begin_comment
comment|/* u_int8_t, SCSI processor ID */
end_comment

begin_define
define|#
directive|define
name|GDT_GETCH_SIOP_STATE
value|0x09
end_define

begin_comment
comment|/* u_int8_t, SCSI processor state */
end_comment

begin_define
define|#
directive|define
name|GDT_GETCH_SZ
value|0x0a
end_define

begin_comment
comment|/* Cache info/config IOCTL structures */
end_comment

begin_define
define|#
directive|define
name|GDT_CPAR_VERSION
value|0x00
end_define

begin_comment
comment|/* u_int32_t, firmware version */
end_comment

begin_define
define|#
directive|define
name|GDT_CPAR_STATE
value|0x04
end_define

begin_comment
comment|/* u_int16_t, cache state (on/off) */
end_comment

begin_define
define|#
directive|define
name|GDT_CPAR_STRATEGY
value|0x06
end_define

begin_comment
comment|/* u_int16_t, cache strategy */
end_comment

begin_define
define|#
directive|define
name|GDT_CPAR_WRITE_BACK
value|0x08
end_define

begin_comment
comment|/* u_int16_t, write back (on/off) */
end_comment

begin_define
define|#
directive|define
name|GDT_CPAR_BLOCK_SIZE
value|0x0a
end_define

begin_comment
comment|/* u_int16_t, cache block size */
end_comment

begin_define
define|#
directive|define
name|GDT_CPAR_SZ
value|0x0c
end_define

begin_define
define|#
directive|define
name|GDT_CSTAT_CSIZE
value|0x00
end_define

begin_comment
comment|/* u_int32_t, cache size */
end_comment

begin_define
define|#
directive|define
name|GDT_CSTAT_READ_CNT
value|0x04
end_define

begin_comment
comment|/* u_int32_t, read counter */
end_comment

begin_define
define|#
directive|define
name|GDT_CSTAT_WRITE_CNT
value|0x08
end_define

begin_comment
comment|/* u_int32_t, write counter */
end_comment

begin_define
define|#
directive|define
name|GDT_CSTAT_TR_HITS
value|0x0c
end_define

begin_comment
comment|/* u_int32_t, track hits */
end_comment

begin_define
define|#
directive|define
name|GDT_CSTAT_SEC_HITS
value|0x10
end_define

begin_comment
comment|/* u_int32_t, sector hits */
end_comment

begin_define
define|#
directive|define
name|GDT_CSTAT_SEC_MISS
value|0x14
end_define

begin_comment
comment|/* u_int32_t, sector misses */
end_comment

begin_define
define|#
directive|define
name|GDT_CSTAT_SZ
value|0x18
end_define

begin_comment
comment|/* Get cache info */
end_comment

begin_define
define|#
directive|define
name|GDT_CINFO_CPAR
value|0x00
end_define

begin_define
define|#
directive|define
name|GDT_CINFO_CSTAT
value|GDT_CPAR_SZ
end_define

begin_define
define|#
directive|define
name|GDT_CINFO_SZ
value|(GDT_CPAR_SZ + GDT_CSTAT_SZ)
end_define

begin_comment
comment|/* Get board info */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_SER_NO
value|0x00
end_define

begin_comment
comment|/* u_int32_t, serial number */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_OEM_ID
value|0x04
end_define

begin_comment
comment|/* u_int8_t [2], OEM ID */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_EP_FLAGS
value|0x06
end_define

begin_comment
comment|/* u_int16_t, eprom flags */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_PROC_ID
value|0x08
end_define

begin_comment
comment|/* u_int32_t, processor ID */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_MEMSIZE
value|0x0c
end_define

begin_comment
comment|/* u_int32_t, memory size (bytes) */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_MEM_BANKS
value|0x10
end_define

begin_comment
comment|/* u_int8_t, memory banks */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_CHAN_TYPE
value|0x11
end_define

begin_comment
comment|/* u_int8_t, channel type */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_CHAN_COUNT
value|0x12
end_define

begin_comment
comment|/* u_int8_t, channel count */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_RDONGLE_PRES
value|0x13
end_define

begin_comment
comment|/* u_int8_t, dongle present */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_EPR_FW_VER
value|0x14
end_define

begin_comment
comment|/* u_int32_t, (eprom) firmware ver */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_UPD_FW_VER
value|0x18
end_define

begin_comment
comment|/* u_int32_t, (update) firmware ver */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_UPD_REVISION
value|0x1c
end_define

begin_comment
comment|/* u_int32_t, update revision */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_TYPE_STRING
value|0x20
end_define

begin_comment
comment|/* char [16], controller name */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_RAID_STRING
value|0x30
end_define

begin_comment
comment|/* char [16], RAID firmware name */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_UPDATE_PRES
value|0x40
end_define

begin_comment
comment|/* u_int8_t, update present? */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_XOR_PRES
value|0x41
end_define

begin_comment
comment|/* u_int8_t, XOR engine present */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_PROM_TYPE
value|0x42
end_define

begin_comment
comment|/* u_int8_t, ROM type (eprom/flash) */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_PROM_COUNT
value|0x43
end_define

begin_comment
comment|/* u_int8_t, number of ROM devices */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_DUP_PRES
value|0x44
end_define

begin_comment
comment|/* u_int32_t, duplexing module pres? */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_CHAN_PRES
value|0x48
end_define

begin_comment
comment|/* u_int32_t, # of exp. channels */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_MEM_PRES
value|0x4c
end_define

begin_comment
comment|/* u_int32_t, memory expansion inst? */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_FT_BUS_SYSTEM
value|0x50
end_define

begin_comment
comment|/* u_int8_t, fault bus supported? */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_SUBTYPE_VALID
value|0x51
end_define

begin_comment
comment|/* u_int8_t, board_subtype valid */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_BOARD_SUBTYPE
value|0x52
end_define

begin_comment
comment|/* u_int8_t, subtype/hardware level */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_RAMPAR_PRES
value|0x53
end_define

begin_comment
comment|/* u_int8_t, RAM parity check hw? */
end_comment

begin_define
define|#
directive|define
name|GDT_BINFO_SZ
value|0x54
end_define

begin_comment
comment|/* Get board features */
end_comment

begin_define
define|#
directive|define
name|GDT_BFEAT_CHAINING
value|0x00
end_define

begin_comment
comment|/* u_int8_t, chaining supported */
end_comment

begin_define
define|#
directive|define
name|GDT_BFEAT_STRIPING
value|0x01
end_define

begin_comment
comment|/* u_int8_t, striping (RAID-0) supp. */
end_comment

begin_define
define|#
directive|define
name|GDT_BFEAT_MIRRORING
value|0x02
end_define

begin_comment
comment|/* u_int8_t, mirroring (RAID-1) supp */
end_comment

begin_define
define|#
directive|define
name|GDT_BFEAT_RAID
value|0x03
end_define

begin_comment
comment|/* u_int8_t, RAID-4/5/10 supported */
end_comment

begin_define
define|#
directive|define
name|GDT_BFEAT_SZ
value|0x04
end_define

begin_comment
comment|/* Other defines */
end_comment

begin_define
define|#
directive|define
name|GDT_ASYNCINDEX
value|0
end_define

begin_comment
comment|/* command index asynchronous event */
end_comment

begin_define
define|#
directive|define
name|GDT_SPEZINDEX
value|1
end_define

begin_comment
comment|/* command index unknown service */
end_comment

begin_comment
comment|/* Debugging */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GDT_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|GDT_D_INTR
value|0x01
end_define

begin_define
define|#
directive|define
name|GDT_D_MISC
value|0x02
end_define

begin_define
define|#
directive|define
name|GDT_D_CMD
value|0x04
end_define

begin_define
define|#
directive|define
name|GDT_D_QUEUE
value|0x08
end_define

begin_define
define|#
directive|define
name|GDT_D_TIMEOUT
value|0x10
end_define

begin_define
define|#
directive|define
name|GDT_D_INIT
value|0x20
end_define

begin_define
define|#
directive|define
name|GDT_D_INVALID
value|0x40
end_define

begin_define
define|#
directive|define
name|GDT_D_DEBUG
value|0x80
end_define

begin_decl_stmt
specifier|extern
name|int
name|gdt_debug
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__SERIAL__
end_ifdef

begin_function_decl
specifier|extern
name|int
name|ser_printf
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GDT_DPRINTF
parameter_list|(
name|mask
parameter_list|,
name|args
parameter_list|)
value|if (gdt_debug& (mask)) ser_printf args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GDT_DPRINTF
parameter_list|(
name|mask
parameter_list|,
name|args
parameter_list|)
value|if (gdt_debug& (mask)) printf args
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
name|GDT_DPRINTF
parameter_list|(
name|mask
parameter_list|,
name|args
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Miscellaneous constants */
end_comment

begin_define
define|#
directive|define
name|GDT_RETRIES
value|100000000
end_define

begin_comment
comment|/* 100000 * 1us = 100s */
end_comment

begin_define
define|#
directive|define
name|GDT_TIMEOUT
value|100000000
end_define

begin_comment
comment|/* 100000 * 1us = 100s */
end_comment

begin_define
define|#
directive|define
name|GDT_POLL_TIMEOUT
value|10000000
end_define

begin_comment
comment|/* 10000 * 1us = 10s */
end_comment

begin_define
define|#
directive|define
name|GDT_WATCH_TIMEOUT
value|10000000
end_define

begin_comment
comment|/* 10000 * 1us = 10s */
end_comment

begin_define
define|#
directive|define
name|GDT_SCRATCH_SZ
value|3072
end_define

begin_comment
comment|/* 3KB scratch buffer */
end_comment

begin_comment
comment|/* macros */
end_comment

begin_define
define|#
directive|define
name|letoh32
parameter_list|(
name|v
parameter_list|)
value|le32toh(v)
end_define

begin_define
define|#
directive|define
name|letoh16
parameter_list|(
name|v
parameter_list|)
value|le16toh(v)
end_define

begin_comment
comment|/* Map minor numbers to device identity */
end_comment

begin_define
define|#
directive|define
name|LUN_MASK
value|0x0007
end_define

begin_define
define|#
directive|define
name|TARGET_MASK
value|0x03f8
end_define

begin_define
define|#
directive|define
name|BUS_MASK
value|0x1c00
end_define

begin_define
define|#
directive|define
name|HBA_MASK
value|0xe000
end_define

begin_define
define|#
directive|define
name|minor2lun
parameter_list|(
name|minor
parameter_list|)
value|( minor& LUN_MASK )
end_define

begin_define
define|#
directive|define
name|minor2target
parameter_list|(
name|minor
parameter_list|)
value|( (minor& TARGET_MASK)>> 3 )
end_define

begin_define
define|#
directive|define
name|minor2bus
parameter_list|(
name|minor
parameter_list|)
value|( (minor& BUS_MASK)>> 10 )
end_define

begin_define
define|#
directive|define
name|minor2hba
parameter_list|(
name|minor
parameter_list|)
value|( (minor& HBA_MASK)>> 13 )
end_define

begin_define
define|#
directive|define
name|hba2minor
parameter_list|(
name|hba
parameter_list|)
value|( (hba<< 13)& HBA_MASK )
end_define

begin_comment
comment|/* struct for GDT_IOCTL_GENERAL */
end_comment

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_typedef
typedef|typedef
struct|struct
name|gdt_ucmd
block|{
name|u_int16_t
name|io_node
decl_stmt|;
name|u_int16_t
name|service
decl_stmt|;
name|u_int32_t
name|timeout
decl_stmt|;
name|u_int16_t
name|status
decl_stmt|;
name|u_int32_t
name|info
decl_stmt|;
name|u_int32_t
name|BoardNode
decl_stmt|;
comment|/* board node (always 0) */
name|u_int32_t
name|CommandIndex
decl_stmt|;
comment|/* command number */
name|u_int16_t
name|OpCode
decl_stmt|;
comment|/* the command (READ,..) */
union|union
block|{
struct|struct
block|{
name|u_int16_t
name|DeviceNo
decl_stmt|;
comment|/* number of cache drive */
name|u_int32_t
name|BlockNo
decl_stmt|;
comment|/* block number */
name|u_int32_t
name|BlockCnt
decl_stmt|;
comment|/* block count */
name|void
modifier|*
name|DestAddr
decl_stmt|;
comment|/* data */
block|}
name|cache
struct|;
comment|/* cache service cmd. str. */
struct|struct
block|{
name|u_int16_t
name|param_size
decl_stmt|;
comment|/* size of p_param buffer */
name|u_int32_t
name|subfunc
decl_stmt|;
comment|/* IOCTL function */
name|u_int32_t
name|channel
decl_stmt|;
comment|/* device */
name|void
modifier|*
name|p_param
decl_stmt|;
comment|/* data */
block|}
name|ioctl
struct|;
comment|/* IOCTL command structure */
struct|struct
block|{
name|u_int16_t
name|reserved
decl_stmt|;
name|u_int32_t
name|direction
decl_stmt|;
comment|/* data direction */
name|u_int32_t
name|mdisc_time
decl_stmt|;
comment|/* disc. time (0: no timeout)*/
name|u_int32_t
name|mcon_time
decl_stmt|;
comment|/* connect time(0: no to.) */
name|void
modifier|*
name|sdata
decl_stmt|;
comment|/* dest. addr. (if s/g: -1) */
name|u_int32_t
name|sdlen
decl_stmt|;
comment|/* data length (bytes) */
name|u_int32_t
name|clen
decl_stmt|;
comment|/* SCSI cmd. length(6,10,12) */
name|u_int8_t
name|cmd
index|[
literal|12
index|]
decl_stmt|;
comment|/* SCSI command */
name|u_int8_t
name|target
decl_stmt|;
comment|/* target ID */
name|u_int8_t
name|lun
decl_stmt|;
comment|/* LUN */
name|u_int8_t
name|bus
decl_stmt|;
comment|/* SCSI bus number */
name|u_int8_t
name|priority
decl_stmt|;
comment|/* only 0 used */
name|u_int32_t
name|sense_len
decl_stmt|;
comment|/* sense data length */
name|void
modifier|*
name|sense_data
decl_stmt|;
comment|/* sense data addr. */
name|u_int32_t
name|link_p
decl_stmt|;
comment|/* linked cmds (not supp.) */
block|}
name|raw
struct|;
comment|/* raw service cmd. struct. */
block|}
name|u
union|;
name|u_int8_t
name|data
index|[
name|GDT_SCRATCH_SZ
index|]
decl_stmt|;
name|int
name|complete_flag
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|gdt_ucmd
argument_list|)
name|links
expr_stmt|;
block|}
name|gdt_ucmd_t
typedef|;
end_typedef

begin_comment
comment|/* struct for GDT_IOCTL_CTRTYPE */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gdt_ctrt
block|{
name|u_int16_t
name|io_node
decl_stmt|;
name|u_int16_t
name|oem_id
decl_stmt|;
name|u_int16_t
name|type
decl_stmt|;
name|u_int32_t
name|info
decl_stmt|;
name|u_int8_t
name|access
decl_stmt|;
name|u_int8_t
name|remote
decl_stmt|;
name|u_int16_t
name|ext_type
decl_stmt|;
name|u_int16_t
name|device_id
decl_stmt|;
name|u_int16_t
name|sub_device_id
decl_stmt|;
block|}
name|gdt_ctrt_t
typedef|;
end_typedef

begin_comment
comment|/* struct for GDT_IOCTL_OSVERS */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gdt_osv
block|{
name|u_int8_t
name|oscode
decl_stmt|;
name|u_int8_t
name|version
decl_stmt|;
name|u_int8_t
name|subversion
decl_stmt|;
name|u_int16_t
name|revision
decl_stmt|;
name|char
name|name
index|[
literal|64
index|]
decl_stmt|;
block|}
name|gdt_osv_t
typedef|;
end_typedef

begin_comment
comment|/* controller event structure */
end_comment

begin_define
define|#
directive|define
name|GDT_ES_ASYNC
value|1
end_define

begin_define
define|#
directive|define
name|GDT_ES_DRIVER
value|2
end_define

begin_define
define|#
directive|define
name|GDT_ES_TEST
value|3
end_define

begin_define
define|#
directive|define
name|GDT_ES_SYNC
value|4
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|size
decl_stmt|;
comment|/* size of structure */
union|union
block|{
name|char
name|stream
index|[
literal|16
index|]
decl_stmt|;
struct|struct
block|{
name|u_int16_t
name|ionode
decl_stmt|;
name|u_int16_t
name|service
decl_stmt|;
name|u_int32_t
name|index
decl_stmt|;
block|}
name|driver
struct|;
struct|struct
block|{
name|u_int16_t
name|ionode
decl_stmt|;
name|u_int16_t
name|service
decl_stmt|;
name|u_int16_t
name|status
decl_stmt|;
name|u_int32_t
name|info
decl_stmt|;
name|u_int8_t
name|scsi_coord
index|[
literal|3
index|]
decl_stmt|;
block|}
name|async
struct|;
struct|struct
block|{
name|u_int16_t
name|ionode
decl_stmt|;
name|u_int16_t
name|service
decl_stmt|;
name|u_int16_t
name|status
decl_stmt|;
name|u_int32_t
name|info
decl_stmt|;
name|u_int16_t
name|hostdrive
decl_stmt|;
name|u_int8_t
name|scsi_coord
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|sense_key
decl_stmt|;
block|}
name|sync
struct|;
struct|struct
block|{
name|u_int32_t
name|l1
decl_stmt|,
name|l2
decl_stmt|,
name|l3
decl_stmt|,
name|l4
decl_stmt|;
block|}
name|test
struct|;
block|}
name|eu
union|;
name|u_int32_t
name|severity
decl_stmt|;
name|u_int8_t
name|event_string
index|[
literal|256
index|]
decl_stmt|;
block|}
name|gdt_evt_data
typedef|;
end_typedef

begin_comment
comment|/* dvrevt structure */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|first_stamp
decl_stmt|;
name|u_int32_t
name|last_stamp
decl_stmt|;
name|u_int16_t
name|same_count
decl_stmt|;
name|u_int16_t
name|event_source
decl_stmt|;
name|u_int16_t
name|event_idx
decl_stmt|;
name|u_int8_t
name|application
decl_stmt|;
name|u_int8_t
name|reserved
decl_stmt|;
name|gdt_evt_data
name|event_data
decl_stmt|;
block|}
name|gdt_evt_str
typedef|;
end_typedef

begin_comment
comment|/* struct for GDT_IOCTL_EVENT */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gdt_event
block|{
name|int
name|erase
decl_stmt|;
name|int
name|handle
decl_stmt|;
name|gdt_evt_str
name|dvr
decl_stmt|;
block|}
name|gdt_event_t
typedef|;
end_typedef

begin_comment
comment|/* struct for GDT_IOCTL_STATIST */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|gdt_statist
block|{
name|u_int16_t
name|io_count_act
decl_stmt|;
name|u_int16_t
name|io_count_max
decl_stmt|;
name|u_int16_t
name|req_queue_act
decl_stmt|;
name|u_int16_t
name|req_queue_max
decl_stmt|;
name|u_int16_t
name|cmd_index_act
decl_stmt|;
name|u_int16_t
name|cmd_index_max
decl_stmt|;
name|u_int16_t
name|sg_count_act
decl_stmt|;
name|u_int16_t
name|sg_count_max
decl_stmt|;
block|}
name|gdt_statist_t
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|/* Context structure for interrupt services */
end_comment

begin_struct
struct|struct
name|gdt_intr_ctx
block|{
name|u_int32_t
name|info
decl_stmt|,
name|info2
decl_stmt|;
name|u_int16_t
name|cmd_status
decl_stmt|,
name|service
decl_stmt|;
name|u_int8_t
name|istatus
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* softc structure */
end_comment

begin_struct
struct|struct
name|gdt_softc
block|{
name|int
name|sc_hanum
decl_stmt|;
name|int
name|sc_class
decl_stmt|;
comment|/* Controller class */
define|#
directive|define
name|GDT_MPR
value|0x05
define|#
directive|define
name|GDT_CLASS_MASK
value|0x07
define|#
directive|define
name|GDT_FC
value|0x10
define|#
directive|define
name|GDT_CLASS
parameter_list|(
name|gdt
parameter_list|)
value|((gdt)->sc_class& GDT_CLASS_MASK)
name|int
name|sc_bus
decl_stmt|,
name|sc_slot
decl_stmt|;
name|u_int16_t
name|sc_device
decl_stmt|,
name|sc_subdevice
decl_stmt|;
name|u_int16_t
name|sc_fw_vers
decl_stmt|;
name|int
name|sc_init_level
decl_stmt|;
name|int
name|sc_state
decl_stmt|;
define|#
directive|define
name|GDT_NORMAL
value|0x00
define|#
directive|define
name|GDT_POLLING
value|0x01
define|#
directive|define
name|GDT_SHUTDOWN
value|0x02
define|#
directive|define
name|GDT_POLL_WAIT
value|0x80
name|dev_t
name|sc_dev
decl_stmt|;
name|bus_space_tag_t
name|sc_dpmemt
decl_stmt|;
name|bus_space_handle_t
name|sc_dpmemh
decl_stmt|;
name|bus_addr_t
name|sc_dpmembase
decl_stmt|;
name|bus_dma_tag_t
name|sc_parent_dmat
decl_stmt|;
name|bus_dma_tag_t
name|sc_buffer_dmat
decl_stmt|;
name|bus_dma_tag_t
name|sc_gccb_dmat
decl_stmt|;
name|bus_dmamap_t
name|sc_gccb_dmamap
decl_stmt|;
name|bus_addr_t
name|sc_gccb_busbase
decl_stmt|;
name|struct
name|gdt_ccb
modifier|*
name|sc_gccbs
decl_stmt|;
name|SLIST_HEAD
argument_list|(
argument_list|,
argument|gdt_ccb
argument_list|)
name|sc_free_gccb
operator|,
name|sc_pending_gccb
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|ccb_hdr
argument_list|)
name|sc_ccb_queue
expr_stmt|;
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|gdt_ucmd
argument_list|)
name|sc_ucmd_queue
expr_stmt|;
name|u_int16_t
name|sc_ic_all_size
decl_stmt|;
name|u_int16_t
name|sc_cmd_len
decl_stmt|;
name|u_int16_t
name|sc_cmd_off
decl_stmt|;
name|u_int16_t
name|sc_cmd_cnt
decl_stmt|;
name|u_int8_t
name|sc_cmd
index|[
name|GDT_CMD_SZ
index|]
decl_stmt|;
name|u_int32_t
name|sc_info
decl_stmt|;
name|u_int32_t
name|sc_info2
decl_stmt|;
name|u_int16_t
name|sc_status
decl_stmt|;
name|u_int16_t
name|sc_service
decl_stmt|;
name|u_int8_t
name|sc_bus_cnt
decl_stmt|;
name|u_int8_t
name|sc_virt_bus
decl_stmt|;
name|u_int8_t
name|sc_bus_id
index|[
name|GDT_MAXBUS
index|]
decl_stmt|;
name|u_int8_t
name|sc_more_proc
decl_stmt|;
struct|struct
block|{
name|u_int8_t
name|hd_present
decl_stmt|;
name|u_int8_t
name|hd_is_logdrv
decl_stmt|;
name|u_int8_t
name|hd_is_arraydrv
decl_stmt|;
name|u_int8_t
name|hd_is_master
decl_stmt|;
name|u_int8_t
name|hd_is_parity
decl_stmt|;
name|u_int8_t
name|hd_is_hotfix
decl_stmt|;
name|u_int8_t
name|hd_master_no
decl_stmt|;
name|u_int8_t
name|hd_lock
decl_stmt|;
name|u_int8_t
name|hd_heads
decl_stmt|;
name|u_int8_t
name|hd_secs
decl_stmt|;
name|u_int16_t
name|hd_devtype
decl_stmt|;
name|u_int32_t
name|hd_size
decl_stmt|;
name|u_int8_t
name|hd_ldr_no
decl_stmt|;
name|u_int8_t
name|hd_rw_attribs
decl_stmt|;
name|u_int32_t
name|hd_start_sec
decl_stmt|;
block|}
name|sc_hdr
index|[
name|GDT_MAX_HDRIVES
index|]
struct|;
name|u_int16_t
name|sc_raw_feat
decl_stmt|;
name|u_int16_t
name|sc_cache_feat
decl_stmt|;
name|gdt_evt_data
name|sc_dvr
decl_stmt|;
name|struct
name|cam_sim
modifier|*
name|sims
index|[
name|GDT_MAXBUS
index|]
decl_stmt|;
name|struct
name|cam_path
modifier|*
name|paths
index|[
name|GDT_MAXBUS
index|]
decl_stmt|;
name|void
argument_list|(
argument|*sc_copy_cmd
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|gdt_softc
operator|*
operator|,
expr|struct
name|gdt_ccb
operator|*
operator|)
argument_list|)
expr_stmt|;
name|u_int8_t
argument_list|(
argument|*sc_get_status
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|gdt_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*sc_intr
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|gdt_softc
operator|*
operator|,
expr|struct
name|gdt_intr_ctx
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*sc_release_event
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|gdt_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|void
argument_list|(
argument|*sc_set_sema0
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|gdt_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|int
argument_list|(
argument|*sc_test_busy
argument_list|)
name|__P
argument_list|(
operator|(
expr|struct
name|gdt_softc
operator|*
operator|)
argument_list|)
expr_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|gdt_softc
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * A command control block, one for each corresponding command index of the  * controller.  */
end_comment

begin_struct
struct|struct
name|gdt_ccb
block|{
name|u_int8_t
name|gc_scratch
index|[
name|GDT_SCRATCH_SZ
index|]
decl_stmt|;
name|union
name|ccb
modifier|*
name|gc_ccb
decl_stmt|;
name|gdt_ucmd_t
modifier|*
name|gc_ucmd
decl_stmt|;
name|bus_dmamap_t
name|gc_dmamap
decl_stmt|;
name|int
name|gc_map_flag
decl_stmt|;
name|int
name|gc_timeout
decl_stmt|;
name|int
name|gc_state
decl_stmt|;
name|u_int8_t
name|gc_service
decl_stmt|;
name|u_int8_t
name|gc_cmd_index
decl_stmt|;
name|u_int8_t
name|gc_flags
decl_stmt|;
define|#
directive|define
name|GDT_GCF_UNUSED
value|0
define|#
directive|define
name|GDT_GCF_INTERNAL
value|1
define|#
directive|define
name|GDT_GCF_SCREEN
value|2
define|#
directive|define
name|GDT_GCF_SCSI
value|3
define|#
directive|define
name|GDT_GCF_IOCTL
value|4
name|SLIST_ENTRY
argument_list|(
argument|gdt_ccb
argument_list|)
name|sle
expr_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|iir_init
name|__P
argument_list|(
operator|(
expr|struct
name|gdt_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iir_free
name|__P
argument_list|(
operator|(
expr|struct
name|gdt_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iir_attach
name|__P
argument_list|(
operator|(
expr|struct
name|gdt_softc
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|iir_intr
name|__P
argument_list|(
operator|(
name|void
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|/* These all require correctly aligned buffers */
end_comment

begin_decl_stmt
specifier|static
name|__inline__
name|void
name|gdt_enc16
name|__P
argument_list|(
operator|(
name|u_int8_t
operator|*
operator|,
name|u_int16_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|void
name|gdt_enc32
name|__P
argument_list|(
operator|(
name|u_int8_t
operator|*
operator|,
name|u_int32_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|u_int16_t
name|gdt_dec16
name|__P
argument_list|(
operator|(
name|u_int8_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|__inline__
name|u_int32_t
name|gdt_dec32
name|__P
argument_list|(
operator|(
name|u_int8_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline__
name|void
name|gdt_enc16
parameter_list|(
name|addr
parameter_list|,
name|value
parameter_list|)
name|u_int8_t
modifier|*
name|addr
decl_stmt|;
name|u_int16_t
name|value
decl_stmt|;
block|{
operator|*
operator|(
name|u_int16_t
operator|*
operator|)
name|addr
operator|=
name|htole16
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|void
name|gdt_enc32
parameter_list|(
name|addr
parameter_list|,
name|value
parameter_list|)
name|u_int8_t
modifier|*
name|addr
decl_stmt|;
name|u_int32_t
name|value
decl_stmt|;
block|{
operator|*
operator|(
name|u_int32_t
operator|*
operator|)
name|addr
operator|=
name|htole32
argument_list|(
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|u_int16_t
name|gdt_dec16
parameter_list|(
name|addr
parameter_list|)
name|u_int8_t
modifier|*
name|addr
decl_stmt|;
block|{
return|return
name|letoh16
argument_list|(
operator|*
operator|(
name|u_int16_t
operator|*
operator|)
name|addr
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline__
name|u_int32_t
name|gdt_dec32
parameter_list|(
name|addr
parameter_list|)
name|u_int8_t
modifier|*
name|addr
decl_stmt|;
block|{
return|return
name|letoh32
argument_list|(
operator|*
operator|(
name|u_int32_t
operator|*
operator|)
name|addr
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_if

begin_comment
comment|/* XXX XXX NEED REAL DMA MAPPING SUPPORT XXX XXX */
end_comment

begin_undef
undef|#
directive|undef
name|vtophys
end_undef

begin_define
define|#
directive|define
name|vtophys
parameter_list|(
name|va
parameter_list|)
value|alpha_XXX_dmamap((vm_offset_t)(va))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_extern
extern|extern TAILQ_HEAD(gdt_softc_list
operator|,
extern|gdt_softc
end_extern

begin_expr_stmt
unit|)
name|gdt_softcs
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|u_int8_t
name|gdt_polling
decl_stmt|;
end_decl_stmt

begin_function_decl
name|dev_t
name|gdt_make_dev
parameter_list|(
name|int
name|unit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gdt_destroy_dev
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gdt_next
parameter_list|(
name|struct
name|gdt_softc
modifier|*
name|gdt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gdt_free_ccb
parameter_list|(
name|struct
name|gdt_softc
modifier|*
name|gdt
parameter_list|,
name|struct
name|gdt_ccb
modifier|*
name|gccb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|gdt_evt_str
modifier|*
name|gdt_store_event
parameter_list|(
name|u_int16_t
name|source
parameter_list|,
name|u_int16_t
name|idx
parameter_list|,
name|gdt_evt_data
modifier|*
name|evt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|gdt_read_event
parameter_list|(
name|int
name|handle
parameter_list|,
name|gdt_evt_str
modifier|*
name|estr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gdt_readapp_event
parameter_list|(
name|u_int8_t
name|app
parameter_list|,
name|gdt_evt_str
modifier|*
name|estr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|gdt_clear_events
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

