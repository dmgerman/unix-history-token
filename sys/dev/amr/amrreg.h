begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999,2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *      $FreeBSD$  */
end_comment

begin_comment
comment|/********************************************************************************  ********************************************************************************                                                                 Driver parameters  ********************************************************************************  ********************************************************************************/
end_comment

begin_comment
comment|/*  * We could actually use all 17 segments, but using only 16 means that  * each scatter/gather map is 128 bytes in size, and thus we don't have to worry about  * maps crossing page boundaries.  *  * The AMI documentation says that the limit is 26.  Unfortunately, there's no way to  * cleanly fit more than 16 entries in without a page boundary.  But is this a concern,  * since we allocate the s/g maps contiguously anyway?  */
end_comment

begin_define
define|#
directive|define
name|AMR_NSEG
value|16
end_define

begin_define
define|#
directive|define
name|AMR_MAXCMD
value|255
end_define

begin_comment
comment|/* ident = 0 not allowed */
end_comment

begin_define
define|#
directive|define
name|AMR_LIMITCMD
value|120
end_define

begin_comment
comment|/* maximum count of outstanding commands */
end_comment

begin_define
define|#
directive|define
name|AMR_MAXLD
value|40
end_define

begin_define
define|#
directive|define
name|AMR_MAX_CHANNELS
value|4
end_define

begin_define
define|#
directive|define
name|AMR_MAX_TARGETS
value|15
end_define

begin_define
define|#
directive|define
name|AMR_MAX_LUNS
value|7
end_define

begin_define
define|#
directive|define
name|AMR_MAX_SCSI_CMDS
value|(15 * AMR_MAX_CHANNELS)
end_define

begin_comment
comment|/* one for every target? */
end_comment

begin_define
define|#
directive|define
name|AMR_MAX_CDB_LEN
value|0x0a
end_define

begin_define
define|#
directive|define
name|AMR_MAX_REQ_SENSE_LEN
value|0x20
end_define

begin_define
define|#
directive|define
name|AMR_BLKSIZE
value|512
end_define

begin_comment
comment|/* constant for all controllers */
end_comment

begin_comment
comment|/*  * Perform at-startup board initialisation.  * At this point in time, this code doesn't work correctly, so leave it disabled.  */
end_comment

begin_comment
comment|/*#define AMR_BOARD_INIT*/
end_comment

begin_comment
comment|/********************************************************************************  ********************************************************************************                                                           Interface Magic Numbers  ********************************************************************************  ********************************************************************************/
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
name|AMR_CMD_PASS
value|0x03
end_define

begin_define
define|#
directive|define
name|AMR_CMD_EXT_ENQUIRY
value|0x04
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
name|AMR_CMD_EXT_ENQUIRY2
value|0x0c
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
name|AMR_CMD_GET_MACHINEID
value|0x36
end_define

begin_define
define|#
directive|define
name|AMR_CMD_GET_INITIATOR
value|0x7d
end_define

begin_comment
comment|/* returns one byte */
end_comment

begin_define
define|#
directive|define
name|AMR_CMD_CONFIG
value|0xa1
end_define

begin_define
define|#
directive|define
name|AMR_CONFIG_PRODUCT_INFO
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
comment|/*  * Physical/logical drive states  */
end_comment

begin_define
define|#
directive|define
name|AMR_DRV_CURSTATE
parameter_list|(
name|x
parameter_list|)
value|((x)& 0x0f)
end_define

begin_define
define|#
directive|define
name|AMR_DRV_PREVSTATE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 4)& 0x0f)
end_define

begin_define
define|#
directive|define
name|AMR_DRV_OFFLINE
value|0x00
end_define

begin_define
define|#
directive|define
name|AMR_DRV_DEGRADED
value|0x01
end_define

begin_define
define|#
directive|define
name|AMR_DRV_OPTIMAL
value|0x02
end_define

begin_define
define|#
directive|define
name|AMR_DRV_ONLINE
value|0x03
end_define

begin_define
define|#
directive|define
name|AMR_DRV_FAILED
value|0x04
end_define

begin_define
define|#
directive|define
name|AMR_DRV_REBUILD
value|0x05
end_define

begin_define
define|#
directive|define
name|AMR_DRV_HOTSPARE
value|0x06
end_define

begin_comment
comment|/*  * Logical drive properties  */
end_comment

begin_define
define|#
directive|define
name|AMR_DRV_RAID_MASK
value|0x0f
end_define

begin_comment
comment|/* RAID level 0, 1, 3, 5, etc. */
end_comment

begin_define
define|#
directive|define
name|AMR_DRV_WRITEBACK
value|0x10
end_define

begin_comment
comment|/* write-back enabled */
end_comment

begin_define
define|#
directive|define
name|AMR_DRV_READHEAD
value|0x20
end_define

begin_comment
comment|/* readhead policy enabled */
end_comment

begin_define
define|#
directive|define
name|AMR_DRV_ADAPTIVE
value|0x40
end_define

begin_comment
comment|/* adaptive I/O policy enabled */
end_comment

begin_comment
comment|/*  * Battery status  */
end_comment

begin_define
define|#
directive|define
name|AMR_BATT_MODULE_MISSING
value|0x01
end_define

begin_define
define|#
directive|define
name|AMR_BATT_LOW_VOLTAGE
value|0x02
end_define

begin_define
define|#
directive|define
name|AMR_BATT_TEMP_HIGH
value|0x04
end_define

begin_define
define|#
directive|define
name|AMR_BATT_PACK_MISSING
value|0x08
end_define

begin_define
define|#
directive|define
name|AMR_BATT_CHARGE_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|AMR_BATT_CHARGE_DONE
value|0x00
end_define

begin_define
define|#
directive|define
name|AMR_BATT_CHARGE_INPROG
value|0x10
end_define

begin_define
define|#
directive|define
name|AMR_BATT_CHARGE_FAIL
value|0x20
end_define

begin_define
define|#
directive|define
name|AMR_BATT_CYCLES_EXCEEDED
value|0x40
end_define

begin_comment
comment|/********************************************************************************  ********************************************************************************                                                            8LD Firmware Interface  ********************************************************************************  ********************************************************************************/
end_comment

begin_comment
comment|/*  * Array constraints  */
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

begin_comment
comment|/*  * Adapter Info structure  */
end_comment

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
name|aa_boardtype
decl_stmt|;
name|u_int8_t
name|aa_scsisensealert
decl_stmt|;
name|u_int8_t
name|aa_writeconfigcount
decl_stmt|;
name|u_int8_t
name|aa_driveinsertioncount
decl_stmt|;
name|u_int8_t
name|aa_inserteddrive
decl_stmt|;
name|u_int8_t
name|aa_batterystatus
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

begin_comment
comment|/*  * Logical Drive info structure  */
end_comment

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

begin_comment
comment|/*  * Physical Drive info structure  */
end_comment

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
comment|/* low nibble current state, high nibble previous state */
name|u_int8_t
name|ap_predictivefailure
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

begin_comment
comment|/*  * Enquiry response structure for AMR_CMD_ENQUIRY, AMR_CMD_EXT_ENQUIRY and  * AMR_CMD_EXT_ENQUIRY2.  *								ENQUIRY EXT_ENQUIRY EXT_ENQUIRY2   */
end_comment

begin_struct
struct|struct
name|amr_enquiry
block|{
name|struct
name|amr_adapter_info
name|ae_adapter
decl_stmt|;
comment|/* X	  X		X */
name|struct
name|amr_logdrive_info
name|ae_ldrv
decl_stmt|;
comment|/* X	  X		X */
name|struct
name|amr_physdrive_info
name|ae_pdrv
decl_stmt|;
comment|/* X	  X		X */
name|u_int8_t
name|ae_formatting
index|[
name|AMR_8LD_MAXDRIVES
index|]
decl_stmt|;
comment|/*	  X		X */
name|u_int8_t
name|res1
index|[
name|AMR_8LD_MAXDRIVES
index|]
decl_stmt|;
comment|/*	  X		X */
name|u_int32_t
name|ae_extlen
decl_stmt|;
comment|/*			X */
name|u_int16_t
name|ae_subsystem
decl_stmt|;
comment|/*			X */
name|u_int16_t
name|ae_subvendor
decl_stmt|;
comment|/*			X */
name|u_int32_t
name|ae_signature
decl_stmt|;
comment|/*			X */
define|#
directive|define
name|AMR_SIG_431
value|0xfffe0001
define|#
directive|define
name|AMR_SIG_438
value|0xfffd0002
define|#
directive|define
name|AMR_SIG_762
value|0xfffc0003
define|#
directive|define
name|AMR_SIG_T5
value|0xfffb0004
define|#
directive|define
name|AMR_SIG_466
value|0xfffa0005
define|#
directive|define
name|AMR_SIG_467
value|0xfff90006
define|#
directive|define
name|AMR_SIG_T7
value|0xfff80007
define|#
directive|define
name|AMR_SIG_490
value|0xfff70008
name|u_int8_t
name|res2
index|[
literal|844
index|]
decl_stmt|;
comment|/*			X */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/********************************************************************************  ********************************************************************************                                                           40LD Firmware Interface  ********************************************************************************  ********************************************************************************/
end_comment

begin_comment
comment|/*  * Array constraints  */
end_comment

begin_define
define|#
directive|define
name|AMR_40LD_MAXDRIVES
value|40
end_define

begin_define
define|#
directive|define
name|AMR_40LD_MAXCHAN
value|16
end_define

begin_define
define|#
directive|define
name|AMR_40LD_MAXTARG
value|16
end_define

begin_define
define|#
directive|define
name|AMR_40LD_MAXPHYSDRIVES
value|256
end_define

begin_comment
comment|/*  * Product Info structure  */
end_comment

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

begin_comment
comment|/*  * Notify structure  */
end_comment

begin_struct
struct|struct
name|amr_notify
block|{
name|u_int32_t
name|an_globalcounter
decl_stmt|;
comment|/* change counter */
name|u_int8_t
name|an_paramcounter
decl_stmt|;
comment|/* parameter change counter */
name|u_int8_t
name|an_paramid
decl_stmt|;
define|#
directive|define
name|AMR_PARAM_REBUILD_RATE
value|0x01
comment|/* value = new rebuild rate */
define|#
directive|define
name|AMR_PARAM_FLUSH_INTERVAL
value|0x02
comment|/* value = new flush interval */
define|#
directive|define
name|AMR_PARAM_SENSE_ALERT
value|0x03
comment|/* value = last physical drive with check condition set */
define|#
directive|define
name|AMR_PARAM_DRIVE_INSERTED
value|0x04
comment|/* value = last physical drive inserted */
define|#
directive|define
name|AMR_PARAM_BATTERY_STATUS
value|0x05
comment|/* value = battery status */
name|u_int16_t
name|an_paramval
decl_stmt|;
name|u_int8_t
name|an_writeconfigcounter
decl_stmt|;
comment|/* write config occurred */
name|u_int8_t
name|res1
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|an_ldrvopcounter
decl_stmt|;
comment|/* logical drive operation started/completed */
name|u_int8_t
name|an_ldrvopid
decl_stmt|;
name|u_int8_t
name|an_ldrvopcmd
decl_stmt|;
define|#
directive|define
name|AMR_LDRVOP_CHECK
value|0x01
define|#
directive|define
name|AMR_LDRVOP_INIT
value|0x02
define|#
directive|define
name|AMR_LDRVOP_REBUILD
value|0x03
name|u_int8_t
name|an_ldrvopstatus
decl_stmt|;
define|#
directive|define
name|AMR_LDRVOP_SUCCESS
value|0x00
define|#
directive|define
name|AMR_LDRVOP_FAILED
value|0x01
define|#
directive|define
name|AMR_LDRVOP_ABORTED
value|0x02
define|#
directive|define
name|AMR_LDRVOP_CORRECTED
value|0x03
define|#
directive|define
name|AMR_LDRVOP_STARTED
value|0x04
name|u_int8_t
name|an_ldrvstatecounter
decl_stmt|;
comment|/* logical drive state change occurred */
name|u_int8_t
name|an_ldrvstateid
decl_stmt|;
name|u_int8_t
name|an_ldrvstatenew
decl_stmt|;
name|u_int8_t
name|an_ldrvstateold
decl_stmt|;
name|u_int8_t
name|an_pdrvstatecounter
decl_stmt|;
comment|/* physical drive state change occurred */
name|u_int8_t
name|an_pdrvstateid
decl_stmt|;
name|u_int8_t
name|an_pdrvstatenew
decl_stmt|;
name|u_int8_t
name|an_pdrvstateold
decl_stmt|;
name|u_int8_t
name|an_pdrvfmtcounter
decl_stmt|;
name|u_int8_t
name|an_pdrvfmtid
decl_stmt|;
name|u_int8_t
name|an_pdrvfmtval
decl_stmt|;
define|#
directive|define
name|AMR_FORMAT_START
value|0x01
define|#
directive|define
name|AMR_FORMAT_COMPLETE
value|0x02
name|u_int8_t
name|res2
decl_stmt|;
name|u_int8_t
name|an_targxfercounter
decl_stmt|;
comment|/* scsi xfer rate change */
name|u_int8_t
name|an_targxferid
decl_stmt|;
name|u_int8_t
name|an_targxferval
decl_stmt|;
name|u_int8_t
name|res3
decl_stmt|;
name|u_int8_t
name|an_fcloopidcounter
decl_stmt|;
comment|/* FC/AL loop ID changed */
name|u_int8_t
name|an_fcloopidpdrvid
decl_stmt|;
name|u_int8_t
name|an_fcloopid0
decl_stmt|;
name|u_int8_t
name|an_fcloopid1
decl_stmt|;
name|u_int8_t
name|an_fcloopstatecounter
decl_stmt|;
comment|/* FC/AL loop status changed */
name|u_int8_t
name|an_fcloopstate0
decl_stmt|;
name|u_int8_t
name|an_fcloopstate1
decl_stmt|;
name|u_int8_t
name|res4
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

begin_comment
comment|/*  * Enquiry3 structure  */
end_comment

begin_struct
struct|struct
name|amr_enquiry3
block|{
name|u_int32_t
name|ae_datasize
decl_stmt|;
comment|/* valid data size in this structure */
union|union
block|{
comment|/* event notify structure */
name|struct
name|amr_notify
name|n
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|0x80
index|]
decl_stmt|;
block|}
name|ae_notify
union|;
name|u_int8_t
name|ae_rebuildrate
decl_stmt|;
comment|/* current rebuild rate in % */
name|u_int8_t
name|ae_cacheflush
decl_stmt|;
comment|/* flush interval in seconds */
name|u_int8_t
name|ae_sensealert
decl_stmt|;
name|u_int8_t
name|ae_driveinsertcount
decl_stmt|;
comment|/* count of inserted drives */
name|u_int8_t
name|ae_batterystatus
decl_stmt|;
name|u_int8_t
name|ae_numldrives
decl_stmt|;
name|u_int8_t
name|ae_reconstate
index|[
name|AMR_40LD_MAXDRIVES
operator|/
literal|8
index|]
decl_stmt|;
comment|/* reconstruction state */
name|u_int16_t
name|ae_opstatus
index|[
name|AMR_40LD_MAXDRIVES
operator|/
literal|8
index|]
decl_stmt|;
comment|/* operation status per drive */
name|u_int32_t
name|ae_drivesize
index|[
name|AMR_40LD_MAXDRIVES
index|]
decl_stmt|;
comment|/* logical drive size */
name|u_int8_t
name|ae_driveprop
index|[
name|AMR_40LD_MAXDRIVES
index|]
decl_stmt|;
comment|/* logical drive properties */
name|u_int8_t
name|ae_drivestate
index|[
name|AMR_40LD_MAXDRIVES
index|]
decl_stmt|;
comment|/* physical drive state */
name|u_int16_t
name|ae_driveformat
index|[
name|AMR_40LD_MAXPHYSDRIVES
index|]
decl_stmt|;
name|u_int8_t
name|ae_targxfer
index|[
literal|80
index|]
decl_stmt|;
comment|/* physical drive transfer rates */
name|u_int8_t
name|res1
index|[
literal|263
index|]
decl_stmt|;
comment|/* pad to 1024 bytes */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_comment
comment|/********************************************************************************  ********************************************************************************                                                    Mailbox and Command Structures  ********************************************************************************  ********************************************************************************/
end_comment

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
name|mb_pad
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
name|res1
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
name|res4
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

begin_struct
struct|struct
name|amr_passthrough
block|{
name|u_int8_t
name|ap_timeout
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|ap_ars
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|ap_dummy
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|ap_islogical
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|ap_logical_drive_no
decl_stmt|;
name|u_int8_t
name|ap_channel
decl_stmt|;
name|u_int8_t
name|ap_scsi_id
decl_stmt|;
name|u_int8_t
name|ap_queue_tag
decl_stmt|;
name|u_int8_t
name|ap_queue_action
decl_stmt|;
name|u_int8_t
name|ap_cdb
index|[
name|AMR_MAX_CDB_LEN
index|]
decl_stmt|;
name|u_int8_t
name|ap_cdb_length
decl_stmt|;
name|u_int8_t
name|ap_request_sense_length
decl_stmt|;
name|u_int8_t
name|ap_request_sense_area
index|[
name|AMR_MAX_REQ_SENSE_LEN
index|]
decl_stmt|;
name|u_int8_t
name|ap_no_sg_elements
decl_stmt|;
name|u_int8_t
name|ap_scsi_status
decl_stmt|;
name|u_int32_t
name|ap_data_transfer_address
decl_stmt|;
name|u_int32_t
name|ap_data_transfer_length
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

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/********************************************************************************  ********************************************************************************                                                "Quartz" i960 PCI bridge interface  ********************************************************************************  ********************************************************************************/
end_comment

begin_define
define|#
directive|define
name|AMR_CFG_SIG
value|0xa0
end_define

begin_comment
comment|/* PCI config register for signature */
end_comment

begin_define
define|#
directive|define
name|AMR_SIGNATURE_1
value|0xCCCC
end_define

begin_comment
comment|/* i960 signature (older adapters) */
end_comment

begin_define
define|#
directive|define
name|AMR_SIGNATURE_2
value|0x3344
end_define

begin_comment
comment|/* i960 signature (newer adapters) */
end_comment

begin_comment
comment|/*  * Doorbell registers  */
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
comment|/*  * Initialisation status  */
end_comment

begin_define
define|#
directive|define
name|AMR_QINIT_SCAN
value|0x01
end_define

begin_comment
comment|/* init scanning drives */
end_comment

begin_define
define|#
directive|define
name|AMR_QINIT_SCANINIT
value|0x02
end_define

begin_comment
comment|/* init scanning initialising */
end_comment

begin_define
define|#
directive|define
name|AMR_QINIT_FIRMWARE
value|0x03
end_define

begin_comment
comment|/* init firmware initing */
end_comment

begin_define
define|#
directive|define
name|AMR_QINIT_INPROG
value|0xdc
end_define

begin_comment
comment|/* init in progress */
end_comment

begin_define
define|#
directive|define
name|AMR_QINIT_SPINUP
value|0x2c
end_define

begin_comment
comment|/* init spinning drives */
end_comment

begin_define
define|#
directive|define
name|AMR_QINIT_NOMEM
value|0xac
end_define

begin_comment
comment|/* insufficient memory */
end_comment

begin_define
define|#
directive|define
name|AMR_QINIT_CACHEFLUSH
value|0xbc
end_define

begin_comment
comment|/* init flushing cache */
end_comment

begin_define
define|#
directive|define
name|AMR_QINIT_DONE
value|0x9c
end_define

begin_comment
comment|/* init successfully done */
end_comment

begin_comment
comment|/*  * I/O primitives  */
end_comment

begin_define
define|#
directive|define
name|AMR_QPUT_IDB
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->amr_btag, sc->amr_bhandle, AMR_QIDB, val)
end_define

begin_define
define|#
directive|define
name|AMR_QGET_IDB
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_4 (sc->amr_btag, sc->amr_bhandle, AMR_QIDB)
end_define

begin_define
define|#
directive|define
name|AMR_QPUT_ODB
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->amr_btag, sc->amr_bhandle, AMR_QODB, val)
end_define

begin_define
define|#
directive|define
name|AMR_QGET_ODB
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_4 (sc->amr_btag, sc->amr_bhandle, AMR_QODB)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AMR_BOARD_INIT
end_ifdef

begin_define
define|#
directive|define
name|AMR_QRESET
parameter_list|(
name|sc
parameter_list|)
define|\
value|do { 												\ 	    pci_write_config((sc)->amr_dev, 0x40, pci_read_config((sc)->amr_dev, 0x40, 1) | 0x20, 1); 	\ 	    pci_write_config((sc)->amr_dev, 0x64, 0x1122, 1);						\ 	} while (0)
end_define

begin_define
define|#
directive|define
name|AMR_QGET_INITSTATUS
parameter_list|(
name|sc
parameter_list|)
value|pci_read_config((sc)->amr_dev, 0x9c, 1)
end_define

begin_define
define|#
directive|define
name|AMR_QGET_INITCHAN
parameter_list|(
name|sc
parameter_list|)
value|pci_read_config((sc)->amr_dev, 0x9f, 1)
end_define

begin_define
define|#
directive|define
name|AMR_QGET_INITTARG
parameter_list|(
name|sc
parameter_list|)
value|pci_read_config((sc)->amr_dev, 0x9e, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/********************************************************************************  ********************************************************************************                                        "Standard" old-style ASIC bridge interface  ********************************************************************************  ********************************************************************************/
end_comment

begin_comment
comment|/*  * I/O registers  */
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
comment|/*  * I/O magic numbers  */
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
comment|/*  * Initialisation status  */
end_comment

begin_define
define|#
directive|define
name|AMR_SINIT_ABEND
value|0xee
end_define

begin_comment
comment|/* init abnormal terminated */
end_comment

begin_define
define|#
directive|define
name|AMR_SINIT_NOMEM
value|0xca
end_define

begin_comment
comment|/* insufficient memory */
end_comment

begin_define
define|#
directive|define
name|AMR_SINIT_CACHEFLUSH
value|0xbb
end_define

begin_comment
comment|/* firmware flushing cache */
end_comment

begin_define
define|#
directive|define
name|AMR_SINIT_INPROG
value|0x11
end_define

begin_comment
comment|/* init in progress */
end_comment

begin_define
define|#
directive|define
name|AMR_SINIT_SPINUP
value|0x22
end_define

begin_comment
comment|/* firmware spinning drives */
end_comment

begin_define
define|#
directive|define
name|AMR_SINIT_DONE
value|0x99
end_define

begin_comment
comment|/* init successfully done */
end_comment

begin_comment
comment|/*  * I/O primitives  */
end_comment

begin_define
define|#
directive|define
name|AMR_SPUT_ISTAT
parameter_list|(
name|sc
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, AMR_SINTR, val)
end_define

begin_define
define|#
directive|define
name|AMR_SGET_ISTAT
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_1 (sc->amr_btag, sc->amr_bhandle, AMR_SINTR)
end_define

begin_define
define|#
directive|define
name|AMR_SACK_INTERRUPT
parameter_list|(
name|sc
parameter_list|)
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, AMR_SCMD, AMR_SCMD_ACKINTR)
end_define

begin_define
define|#
directive|define
name|AMR_SPOST_COMMAND
parameter_list|(
name|sc
parameter_list|)
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, AMR_SCMD, AMR_SCMD_POST)
end_define

begin_define
define|#
directive|define
name|AMR_SGET_MBSTAT
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_1 (sc->amr_btag, sc->amr_bhandle, AMR_SMBOX_BUSY)
end_define

begin_define
define|#
directive|define
name|AMR_SENABLE_INTR
parameter_list|(
name|sc
parameter_list|)
define|\
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, AMR_STOGGLE, 						\ 			  bus_space_read_1(sc->amr_btag, sc->amr_bhandle, AMR_STOGGLE) | AMR_STOGL_IENABLE)
end_define

begin_define
define|#
directive|define
name|AMR_SDISABLE_INTR
parameter_list|(
name|sc
parameter_list|)
define|\
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, AMR_STOGGLE, 						\ 			  bus_space_read_1(sc->amr_btag, sc->amr_bhandle, AMR_STOGGLE)& ~AMR_STOGL_IENABLE)
end_define

begin_define
define|#
directive|define
name|AMR_SBYTE_SET
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, reg, val)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|AMR_BOARD_INIT
end_ifdef

begin_define
define|#
directive|define
name|AMR_SRESET
parameter_list|(
name|sc
parameter_list|)
value|bus_space_write_1(sc->amr_btag, sc->amr_bhandle, 0, 0x80)
end_define

begin_define
define|#
directive|define
name|AMR_SGET_INITSTATUS
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_1 (sc->amr_btag, sc->amr_bhandle, AMR_SMBOX_ENABLE)
end_define

begin_define
define|#
directive|define
name|AMR_SGET_FAILDRIVE
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_1 (sc->amr_btag, sc->amr_bhandle, AMR_SMBOX_ENABLE + 1)
end_define

begin_define
define|#
directive|define
name|AMR_SGET_INITCHAN
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_1 (sc->amr_btag, sc->amr_bhandle, AMR_SMBOX_ENABLE + 2)
end_define

begin_define
define|#
directive|define
name|AMR_SGET_INITTARG
parameter_list|(
name|sc
parameter_list|)
value|bus_space_read_1 (sc->amr_btag, sc->amr_bhandle, AMR_SMBOX_ENABLE + 3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
endif|_KERNEL
end_endif

end_unit

