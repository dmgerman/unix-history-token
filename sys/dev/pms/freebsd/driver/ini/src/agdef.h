begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  **  ** *Copyright (c) 2014 PMC-Sierra, Inc.  All rights reserved.   * *Redistribution and use in source and binary forms, with or without modification, are permitted provided  *that the following conditions are met:  *1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.  *2. Redistributions in binary form must reproduce the above copyright notice,  *this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  * *THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, * *INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  *ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  *SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  *OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, *WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF *THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE * * $FreeBSD$ * ** *******************************************************************************/
end_comment

begin_comment
comment|/****************************************************************************** Note: ******************************************************************************* Module Name:     agdef.h Abstract:     Linux iSCSI/FC Initiator driver module constant define header file Authors:     EW - Yiding(Eddie) Wang Environment:     Kernel or loadable module    Version Control Information:     $ver. 1.0.0      Revision History:   $Revision: 115514 $0.1.0   $Date: 2012-01-06 17:12:27 -0800 (Fri, 06 Jan 2012) $09-27-2001   $Modtime: 11/12/01 11:15a $15:56:00  Notes: **************************** MODIFICATION HISTORY *****************************  NAME     DATE         Rev.          DESCRIPTION ----     ----         ----          ----------- EW     09-17-2004     1.0.0     Constant definitions ******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AGTIAPI_DEF_H__
end_ifndef

begin_define
define|#
directive|define
name|__AGTIAPI_DEF_H__
end_define

begin_comment
comment|/* ** Max device supported */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_HW_LIMIT_DEVICE
value|4096
end_define

begin_define
define|#
directive|define
name|AGTIAPI_MAX_LUN
value|256
end_define

begin_comment
comment|/* Max # luns per target */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_MAX_DEVICE
value|128
end_define

begin_comment
comment|//64 //2048//1024 /* Max # device per channel */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_MAX_DEVICE_7H
value|256
end_define

begin_comment
comment|/*Max devices per channel in 7H */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_MAX_DEVICE_8H
value|512
end_define

begin_comment
comment|/*Max devices per channel in 8H*/
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_MAX_CAM_Q_DEPTH
value|1024
end_define

begin_define
define|#
directive|define
name|AGTIAPI_NSEGS
value|(MAXPHYS / PAGE_SIZE)
end_define

begin_comment
comment|/* ** Adapter specific defines  */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_IO_RANGE
value|256
end_define

begin_comment
comment|/* IO mapped address range */
end_comment

begin_comment
comment|/* **  Scatter/Gather DMA Segment Descriptor **  Note, MAX_Q_DEPTH could be set larger for iscsi "AcceptQueueSize" **  parameter matching.  One thing to do is to make it to be an adjustable  **  parameter.  Currently suggest this value set to be same as  **  "AcceptQueueSize" but not required.   */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_MAX_DMA_SEGS
value|128
end_define

begin_comment
comment|//256
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_DEFAULT_Q_DEPTH
value|4
end_define

begin_define
define|#
directive|define
name|AGTIAPI_MAX_Q_DEPTH
value|AGSA_MAX_INBOUND_Q * 512
end_define

begin_comment
comment|// *INBOUND_DEPTH_SIZE
end_comment

begin_comment
comment|/* ** CCB and device flags defines */
end_comment

begin_define
define|#
directive|define
name|ACTIVE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|TIMEDOUT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|REQ_DONE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|AGTIAPI_INQUIRY
value|0x00000008
end_define

begin_define
define|#
directive|define
name|AGTIAPI_ABORT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|AGTIAPI_RETRY
value|0x00000020
end_define

begin_define
define|#
directive|define
name|TASK_SUCCESS
value|0x00000040
end_define

begin_comment
comment|/* reserved for card flag #define AGTIAPI_RESERVED 0x00000080   */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_CNX_UP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|DEV_RESET
value|0x00000400
end_define

begin_comment
comment|/* device reset */
end_comment

begin_define
define|#
directive|define
name|DEV_SHIFT
value|0x00000800
end_define

begin_comment
comment|/* device shift physical position */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_YAM
value|0x00001000
end_define

begin_define
define|#
directive|define
name|TASK_TIMEOUT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|ENCRYPTED_IO
value|0x00010000
end_define

begin_comment
comment|/* encrypted IO */
end_comment

begin_define
define|#
directive|define
name|SATA_DIF
value|0x00020000
end_define

begin_comment
comment|/* SATA DIF */
end_comment

begin_define
define|#
directive|define
name|EDC_DATA
value|0x00040000
end_define

begin_define
define|#
directive|define
name|EDC_DATA_CRC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|TAG_SMP
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TASK_MANAGEMENT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|AGTIAPI_CCB_PER_DEVICE
value|64
end_define

begin_define
define|#
directive|define
name|AGTIAPI_CMD_PER_LUN
value|512
end_define

begin_comment
comment|/* ** Max time to call agtiapi_GetDevHandle ** to make sure that no devices are attached */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_GET_DEV_MAX
value|2
end_define

begin_comment
comment|/* ** Device address mode */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_ADDRMODE_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|AGTIAPI_PERIPHERAL
value|0x00
end_define

begin_define
define|#
directive|define
name|AGTIAPI_VOLUME_SET
value|0x01
end_define

begin_define
define|#
directive|define
name|AGTIAPI_LUN_ADDR
value|0x02
end_define

begin_comment
comment|/*       ** Device mapping method */
end_comment

begin_define
define|#
directive|define
name|SOFT_MAPPED
value|0x0001
end_define

begin_define
define|#
directive|define
name|HARD_MAPPED
value|0x0002
end_define

begin_comment
comment|/* ** bd_dev_type definitions */
end_comment

begin_define
define|#
directive|define
name|DIRECT_DEVICE
value|0x00
end_define

begin_define
define|#
directive|define
name|TAPE_DEVICE
value|0x01
end_define

begin_define
define|#
directive|define
name|SLOW_DEVICE
value|0x02
end_define

begin_define
define|#
directive|define
name|ARRAY_DEVICE
value|0x04
end_define

begin_comment
comment|/*  ** SCSI CDB   */
end_comment

begin_define
define|#
directive|define
name|SCSI_CDB_SIZE
value|16
end_define

begin_comment
comment|/*  ** SCSI status   */
end_comment

begin_define
define|#
directive|define
name|SCSI_GOOD
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_CHECK_CONDITION
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_CONDITION_MET
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_INTERMEDIATE
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_INTERMEDIATE_COND_MET
value|0x14
end_define

begin_define
define|#
directive|define
name|SCSI_RESERVATION_CONFLICT
value|0x18
end_define

begin_define
define|#
directive|define
name|SCSI_TASK_ABORTED
value|0x40
end_define

begin_define
define|#
directive|define
name|SCSI_TASK_SET_FULL
value|0x28
end_define

begin_define
define|#
directive|define
name|SCSI_ACA_ACTIVE
value|0x30
end_define

begin_comment
comment|/* ** Peripheral device types */
end_comment

begin_define
define|#
directive|define
name|DTYPE_DIRECT
value|0x00
end_define

begin_define
define|#
directive|define
name|DTYPE_SEQUENTIAL
value|0x01
end_define

begin_define
define|#
directive|define
name|DTYPE_PRINTER
value|0x02
end_define

begin_define
define|#
directive|define
name|DTYPE_PROCESSOR
value|0x03
end_define

begin_define
define|#
directive|define
name|DTYPE_WORM
value|0x04
end_define

begin_define
define|#
directive|define
name|DTYPE_RODIRECT
value|0x05
end_define

begin_define
define|#
directive|define
name|DTYPE_SCANNER
value|0x06
end_define

begin_define
define|#
directive|define
name|DTYPE_OPTICAL
value|0x07
end_define

begin_define
define|#
directive|define
name|DTYPE_CHANGER
value|0x08
end_define

begin_define
define|#
directive|define
name|DTYPE_COMM
value|0x09
end_define

begin_define
define|#
directive|define
name|DTYPE_ARRAY_CTRL
value|0x0C
end_define

begin_define
define|#
directive|define
name|DTYPE_ESI
value|0x0D
end_define

begin_comment
comment|/* ** Device types 0x0E-0x1E are reserved */
end_comment

begin_define
define|#
directive|define
name|DTYPE_MASK
value|0x1F
end_define

begin_comment
comment|/* ** Driver capability defines */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_TIMEOUT_SECS
value|10
end_define

begin_comment
comment|/* Default timer interval */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_RESET_MAX
value|0x7FFFFFFF
end_define

begin_comment
comment|/* Default max. reset */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_DEV_RESET_MAX
value|0x10
end_define

begin_comment
comment|/* Default max. reset */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_RETRY_MAX
value|10
end_define

begin_comment
comment|/* Default ccb retry cnt */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_MAX_CHANNEL_NUM
value|0
end_define

begin_comment
comment|/* Max channel # per card */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_PERIPHERAL_CHANNEL
value|0
end_define

begin_define
define|#
directive|define
name|AGTIAPI_VOLUMESET_CHANNEL
value|1
end_define

begin_define
define|#
directive|define
name|AGTIAPI_LUNADDR_CHANNEL
value|2
end_define

begin_define
define|#
directive|define
name|AGTIAPI_EXTRA_DELAY
value|10000
end_define

begin_comment
comment|/* extra 10 seconds delay */
end_comment

begin_comment
comment|/* ** Scsi ioctl test case only */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_TEST_ABORT
value|0xabcd
end_define

begin_define
define|#
directive|define
name|AGTIAPI_TEST_ABORT_DONE
value|0xabce
end_define

begin_define
define|#
directive|define
name|AGTIAPI_IOCTL_SIGNATURE
value|"AGTIAPI_IOCTL"
end_define

begin_define
define|#
directive|define
name|AGTIAPI_HBA_SCSI_ID
value|(AGTIAPI_MAX_DEVICE - 1)
end_define

begin_define
define|#
directive|define
name|AGTIAPI_NO_RESEND
value|0x01
end_define

begin_comment
comment|/* Don't resend command */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_RESEND
value|0x02
end_define

begin_comment
comment|/* Resend command */
end_comment

begin_comment
comment|//#define AGTIAPI_UPPER               0x04   /* Call from upper layer */
end_comment

begin_define
define|#
directive|define
name|AGTIAPI_CALLBACK
value|0x08
end_define

begin_comment
comment|/* CMD call back required */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AGTIAPI_DEF_H__ */
end_comment

end_unit

