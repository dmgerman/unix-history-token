begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Michael Smith  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Mailbox commands  */
end_comment

begin_define
define|#
directive|define
name|AMR_CMD_LREAD
value|0x01
end_define

begin_define
define|#
directive|define
name|AMR_CMD_LWRITE
value|0x02
end_define

begin_define
define|#
directive|define
name|AMR_CMD_ENQUIRY
value|0x05
end_define

begin_define
define|#
directive|define
name|AMR_CMD_FLUSH
value|0x0a
end_define

begin_define
define|#
directive|define
name|AMR_CMD_CONFIG
value|0xa1
end_define

begin_define
define|#
directive|define
name|AMR_CONFIG_PRODINFO
value|0x0e
end_define

begin_define
define|#
directive|define
name|AMR_CONFIG_ENQ3
value|0x0f
end_define

begin_define
define|#
directive|define
name|AMR_CONFIG_ENQ3_SOLICITED_NOTIFY
value|0x01
end_define

begin_define
define|#
directive|define
name|AMR_CONFIG_ENQ3_SOLICITED_FULL
value|0x02
end_define

begin_define
define|#
directive|define
name|AMR_CONFIG_ENQ3_UNSOLICITED
value|0x03
end_define

begin_comment
comment|/*  * Command results  */
end_comment

begin_define
define|#
directive|define
name|AMR_STATUS_SUCCESS
value|0x00
end_define

begin_define
define|#
directive|define
name|AMR_STATUS_ABORTED
value|0x02
end_define

begin_define
define|#
directive|define
name|AMR_STATUS_FAILED
value|0x80
end_define

begin_comment
comment|/*  * Quartz doorbell registers  */
end_comment

begin_define
define|#
directive|define
name|AMR_QIDB
value|0x20
end_define

begin_define
define|#
directive|define
name|AMR_QODB
value|0x2c
end_define

begin_define
define|#
directive|define
name|AMR_QIDB_SUBMIT
value|0x00000001
end_define

begin_comment
comment|/* mailbox ready for work */
end_comment

begin_define
define|#
directive|define
name|AMR_QIDB_ACK
value|0x00000002
end_define

begin_comment
comment|/* mailbox done */
end_comment

begin_define
define|#
directive|define
name|AMR_QODB_READY
value|0x10001234
end_define

begin_comment
comment|/* work ready to be processed */
end_comment

begin_comment
comment|/*  * Standard I/O registers  */
end_comment

begin_define
define|#
directive|define
name|AMR_SCMD
value|0x10
end_define

begin_comment
comment|/* command/ack register (write) */
end_comment

begin_define
define|#
directive|define
name|AMR_SMBOX_BUSY
value|0x10
end_define

begin_comment
comment|/* mailbox status (read) */
end_comment

begin_define
define|#
directive|define
name|AMR_STOGGLE
value|0x11
end_define

begin_comment
comment|/* interrupt enable bit here */
end_comment

begin_define
define|#
directive|define
name|AMR_SMBOX_0
value|0x14
end_define

begin_comment
comment|/* mailbox physical address low byte */
end_comment

begin_define
define|#
directive|define
name|AMR_SMBOX_1
value|0x15
end_define

begin_define
define|#
directive|define
name|AMR_SMBOX_2
value|0x16
end_define

begin_define
define|#
directive|define
name|AMR_SMBOX_3
value|0x17
end_define

begin_comment
comment|/*                          high byte */
end_comment

begin_define
define|#
directive|define
name|AMR_SMBOX_ENABLE
value|0x18
end_define

begin_comment
comment|/* atomic mailbox address enable */
end_comment

begin_define
define|#
directive|define
name|AMR_SINTR
value|0x1a
end_define

begin_comment
comment|/* interrupt status */
end_comment

begin_comment
comment|/*  * Standard I/O magic numbers  */
end_comment

begin_define
define|#
directive|define
name|AMR_SCMD_POST
value|0x10
end_define

begin_comment
comment|/* -> SCMD to initiate action on mailbox */
end_comment

begin_define
define|#
directive|define
name|AMR_SCMD_ACKINTR
value|0x08
end_define

begin_comment
comment|/* -> SCMD to ack mailbox retrieved */
end_comment

begin_define
define|#
directive|define
name|AMR_STOGL_IENABLE
value|0xc0
end_define

begin_comment
comment|/* in STOGGLE */
end_comment

begin_define
define|#
directive|define
name|AMR_SINTR_VALID
value|0x40
end_define

begin_comment
comment|/* in SINTR */
end_comment

begin_define
define|#
directive|define
name|AMR_SMBOX_BUSYFLAG
value|0x10
end_define

begin_comment
comment|/* in SMBOX_BUSY */
end_comment

begin_define
define|#
directive|define
name|AMR_SMBOX_ADDR
value|0x00
end_define

begin_comment
comment|/* -> SMBOX_ENABLE */
end_comment

begin_comment
comment|/*  * Old Enquiry results  */
end_comment

begin_define
define|#
directive|define
name|AMR_8LD_MAXDRIVES
value|8
end_define

begin_define
define|#
directive|define
name|AMR_8LD_MAXCHAN
value|5
end_define

begin_define
define|#
directive|define
name|AMR_8LD_MAXTARG
value|15
end_define

begin_define
define|#
directive|define
name|AMR_8LD_MAXPHYSDRIVES
value|(AMR_8LD_MAXCHAN * AMR_8LD_MAXTARG)
end_define

begin_struct
struct|struct
name|amr_adapter_info
block|{
name|u_int8_t
name|aa_maxio
decl_stmt|;
name|u_int8_t
name|aa_rebuild_rate
decl_stmt|;
name|u_int8_t
name|aa_maxtargchan
decl_stmt|;
name|u_int8_t
name|aa_channels
decl_stmt|;
name|u_int8_t
name|aa_firmware
index|[
literal|4
index|]
decl_stmt|;
name|u_int16_t
name|aa_flashage
decl_stmt|;
name|u_int8_t
name|aa_chipsetvalue
decl_stmt|;
name|u_int8_t
name|aa_memorysize
decl_stmt|;
name|u_int8_t
name|aa_cacheflush
decl_stmt|;
name|u_int8_t
name|aa_bios
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|7
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|amr_logdrive_info
block|{
name|u_int8_t
name|al_numdrives
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|3
index|]
decl_stmt|;
name|u_int32_t
name|al_size
index|[
name|AMR_8LD_MAXDRIVES
index|]
decl_stmt|;
name|u_int8_t
name|al_properties
index|[
name|AMR_8LD_MAXDRIVES
index|]
decl_stmt|;
name|u_int8_t
name|al_state
index|[
name|AMR_8LD_MAXDRIVES
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|amr_physdrive_info
block|{
name|u_int8_t
name|ap_state
index|[
name|AMR_8LD_MAXPHYSDRIVES
index|]
decl_stmt|;
name|u_int8_t
name|res1
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|amr_enquiry
block|{
name|struct
name|amr_adapter_info
name|ae_adapter
decl_stmt|;
name|struct
name|amr_logdrive_info
name|ae_ldrv
decl_stmt|;
name|struct
name|amr_physdrive_info
name|ae_pdrv
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|amr_prodinfo
block|{
name|u_int32_t
name|ap_size
decl_stmt|;
comment|/* current size in bytes (not including resvd) */
name|u_int32_t
name|ap_configsig
decl_stmt|;
comment|/* default is 0x00282008, indicating 0x28 maximum 					 * logical drives, 0x20 maximum stripes and 0x08 					 * maximum spans */
name|u_int8_t
name|ap_firmware
index|[
literal|16
index|]
decl_stmt|;
comment|/* printable identifiers */
name|u_int8_t
name|ap_bios
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|ap_product
index|[
literal|80
index|]
decl_stmt|;
name|u_int8_t
name|ap_maxio
decl_stmt|;
comment|/* maximum number of concurrent commands supported */
name|u_int8_t
name|ap_nschan
decl_stmt|;
comment|/* number of SCSI channels present */
name|u_int8_t
name|ap_fcloops
decl_stmt|;
comment|/* number of fibre loops present */
name|u_int8_t
name|ap_memtype
decl_stmt|;
comment|/* memory type */
name|u_int32_t
name|ap_signature
decl_stmt|;
name|u_int16_t
name|ap_memsize
decl_stmt|;
comment|/* onboard memory in MB */
name|u_int16_t
name|ap_subsystem
decl_stmt|;
comment|/* subsystem identifier */
name|u_int16_t
name|ap_subvendor
decl_stmt|;
comment|/* subsystem vendor ID */
name|u_int8_t
name|ap_numnotifyctr
decl_stmt|;
comment|/* number of notify counters */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_define
define|#
directive|define
name|AMR_MBOX_CMDSIZE
value|0x10
end_define

begin_comment
comment|/* portion worth copying for controller */
end_comment

begin_struct
struct|struct
name|amr_mailbox
block|{
name|u_int8_t
name|mb_command
decl_stmt|;
name|u_int8_t
name|mb_ident
decl_stmt|;
name|u_int16_t
name|mb_blkcount
decl_stmt|;
name|u_int32_t
name|mb_lba
decl_stmt|;
name|u_int32_t
name|mb_physaddr
decl_stmt|;
name|u_int8_t
name|mb_drive
decl_stmt|;
name|u_int8_t
name|mb_nsgelem
decl_stmt|;
name|u_int8_t
name|res1
decl_stmt|;
name|u_int8_t
name|mb_busy
decl_stmt|;
name|u_int8_t
name|mb_nstatus
decl_stmt|;
name|u_int8_t
name|mb_status
decl_stmt|;
name|u_int8_t
name|mb_completed
index|[
literal|46
index|]
decl_stmt|;
name|u_int8_t
name|mb_poll
decl_stmt|;
name|u_int8_t
name|mb_ack
decl_stmt|;
name|u_int8_t
name|res2
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|amr_mailbox64
block|{
name|u_int32_t
name|mb64_segment
decl_stmt|;
comment|/* for 64-bit controllers */
name|struct
name|amr_mailbox
name|mb
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|amr_mailbox_ioctl
block|{
name|u_int8_t
name|mb_command
decl_stmt|;
name|u_int8_t
name|mb_ident
decl_stmt|;
name|u_int8_t
name|mb_channel
decl_stmt|;
name|u_int8_t
name|mb_param
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|mb_physaddr
decl_stmt|;
name|u_int8_t
name|mb_drive
decl_stmt|;
name|u_int8_t
name|mb_nsgelem
decl_stmt|;
name|u_int8_t
name|res2
decl_stmt|;
name|u_int8_t
name|mb_busy
decl_stmt|;
name|u_int8_t
name|mb_nstatus
decl_stmt|;
name|u_int8_t
name|mb_completed
index|[
literal|46
index|]
decl_stmt|;
name|u_int8_t
name|mb_poll
decl_stmt|;
name|u_int8_t
name|mb_ack
decl_stmt|;
name|u_int8_t
name|res3
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_struct
struct|struct
name|amr_sgentry
block|{
name|u_int32_t
name|sg_addr
decl_stmt|;
name|u_int32_t
name|sg_count
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

end_unit

