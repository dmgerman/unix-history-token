begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000 Michael Smith  * Copyright (c) 2000 BSDi  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$FreeBSD$  */
end_comment

begin_comment
comment|/*  * Section numbers in this document refer to the Mylex "Firmware Software Interface"  * document ('FSI'), revision 0.11 04/11/00 unless otherwise qualified.  *  * Reference is made to the Mylex "Programming Guide for 6.x Controllers" document  * ('PG6'), document #771242 revision 0.02, 04/11/00  *  * Note that fields marked N/A are not supported by the PCI controllers, but are  * defined here to hold place in datastructures that are shared with the SCSI  * controllers.  Items not relevant to PCI controllers are not described here.  *  * Ordering of items in this file is a little odd due to the constraints of  * nested declarations.  */
end_comment

begin_comment
comment|/*  * 2.1 (Scatter Gather List Format)  */
end_comment

begin_struct
struct|struct
name|mly_sg_entry
block|{
name|u_int64_t
name|physaddr
decl_stmt|;
name|u_int64_t
name|length
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
comment|/*  * 5.2 System Device Access  *  * This is corroborated by the layout of the MDACIOCTL_GETCONTROLLERINFO data  * in 21.8  */
end_comment

begin_define
define|#
directive|define
name|MLY_MAX_CHANNELS
value|6
end_define

begin_define
define|#
directive|define
name|MLY_MAX_TARGETS
value|16
end_define

begin_define
define|#
directive|define
name|MLY_MAX_LUNS
value|1
end_define

begin_comment
comment|/*  * 8.1 Different Device States  */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_STATE_OFFLINE
value|0x08
end_define

begin_comment
comment|/* DEAD/OFFLINE */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_STATE_UNCONFIGURED
value|0x00
end_define

begin_define
define|#
directive|define
name|MLY_DEVICE_STATE_ONLINE
value|0x01
end_define

begin_define
define|#
directive|define
name|MLY_DEVICE_STATE_CRITICAL
value|0x09
end_define

begin_define
define|#
directive|define
name|MLY_DEVICE_STATE_WRITEONLY
value|0x03
end_define

begin_define
define|#
directive|define
name|MLY_DEVICE_STATE_STANDBY
value|0x21
end_define

begin_define
define|#
directive|define
name|MLY_DEVICE_STATE_MISSING
value|0x04
end_define

begin_comment
comment|/* or-ed with (ONLINE or WRITEONLY or STANDBY) */
end_comment

begin_comment
comment|/*  * 8.2 Device Type Field definitions  */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_RAID0
value|0x0
end_define

begin_comment
comment|/* RAID 0 */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_RAID1
value|0x1
end_define

begin_comment
comment|/* RAID 1 */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_RAID3
value|0x3
end_define

begin_comment
comment|/* RAID 3 right asymmetric parity */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_RAID5
value|0x5
end_define

begin_comment
comment|/* RAID 5 right asymmetric parity */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_RAID6
value|0x6
end_define

begin_comment
comment|/* RAID 6 (Mylex RAID 6) */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_RAID7
value|0x7
end_define

begin_comment
comment|/* RAID 7 (JBOD) */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_NEWSPAN
value|0x8
end_define

begin_comment
comment|/* New Mylex SPAN */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_RAID3F
value|0x9
end_define

begin_comment
comment|/* RAID 3 fixed parity */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_RAID3L
value|0xb
end_define

begin_comment
comment|/* RAID 3 left symmetric parity */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_SPAN
value|0xc
end_define

begin_comment
comment|/* current spanning implementation */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_RAID5L
value|0xd
end_define

begin_comment
comment|/* RAID 5 left symmetric parity */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_RAIDE
value|0xe
end_define

begin_comment
comment|/* RAID E (concatenation) */
end_comment

begin_define
define|#
directive|define
name|MLY_DEVICE_TYPE_PHYSICAL
value|0xf
end_define

begin_comment
comment|/* physical device */
end_comment

begin_comment
comment|/*  * 8.3 Stripe Size  */
end_comment

begin_define
define|#
directive|define
name|MLY_STRIPE_ZERO
value|0x0
end_define

begin_comment
comment|/* no stripe (RAID 1, RAID 7, etc) */
end_comment

begin_define
define|#
directive|define
name|MLY_STRIPE_512b
value|0x1
end_define

begin_define
define|#
directive|define
name|MLY_STRIPE_1k
value|0x2
end_define

begin_define
define|#
directive|define
name|MLY_STRIPE_2k
value|0x3
end_define

begin_define
define|#
directive|define
name|MLY_STRIPE_4k
value|0x4
end_define

begin_define
define|#
directive|define
name|MLY_STRIPE_8k
value|0x5
end_define

begin_define
define|#
directive|define
name|MLY_STRIPE_16k
value|0x6
end_define

begin_define
define|#
directive|define
name|MLY_STRIPE_32k
value|0x7
end_define

begin_define
define|#
directive|define
name|MLY_STRIPE_64k
value|0x8
end_define

begin_define
define|#
directive|define
name|MLY_STRIPE_128k
value|0x9
end_define

begin_define
define|#
directive|define
name|MLY_STRIPE_256k
value|0xa
end_define

begin_define
define|#
directive|define
name|MLY_STRIPE_512k
value|0xb
end_define

begin_define
define|#
directive|define
name|MLY_STRIPE_1m
value|0xc
end_define

begin_comment
comment|/*  * 8.4 Cacheline Size  */
end_comment

begin_define
define|#
directive|define
name|MLY_CACHELINE_ZERO
value|0x0
end_define

begin_comment
comment|/* caching cannot be enabled */
end_comment

begin_define
define|#
directive|define
name|MLY_CACHELINE_512b
value|0x1
end_define

begin_define
define|#
directive|define
name|MLY_CACHELINE_1k
value|0x2
end_define

begin_define
define|#
directive|define
name|MLY_CACHELINE_2k
value|0x3
end_define

begin_define
define|#
directive|define
name|MLY_CACHELINE_4k
value|0x4
end_define

begin_define
define|#
directive|define
name|MLY_CACHELINE_8k
value|0x5
end_define

begin_define
define|#
directive|define
name|MLY_CACHELINE_16k
value|0x6
end_define

begin_define
define|#
directive|define
name|MLY_CACHELINE_32k
value|0x7
end_define

begin_define
define|#
directive|define
name|MLY_CACHELINE_64k
value|0x8
end_define

begin_comment
comment|/*  * 8.5 Read/Write control  */
end_comment

begin_define
define|#
directive|define
name|MLY_RWCtl_INITTED
value|(1<<7)
end_define

begin_comment
comment|/* if set, the logical device is initialised */
end_comment

begin_comment
comment|/* write control */
end_comment

begin_define
define|#
directive|define
name|MLY_RWCtl_WCD
value|(0)
end_define

begin_comment
comment|/* write cache disabled */
end_comment

begin_define
define|#
directive|define
name|MLY_RWCtl_WDISABLE
value|(1<<3)
end_define

begin_comment
comment|/* writing disabled */
end_comment

begin_define
define|#
directive|define
name|MLY_RWCtl_WCE
value|(2<<3)
end_define

begin_comment
comment|/* write cache enabled */
end_comment

begin_define
define|#
directive|define
name|MLY_RWCtl_IWCE
value|(3<<3)
end_define

begin_comment
comment|/* intelligent write cache enabled */
end_comment

begin_comment
comment|/* read control */
end_comment

begin_define
define|#
directive|define
name|MLY_RWCtl_RCD
value|(0)
end_define

begin_comment
comment|/* read cache is disabled */
end_comment

begin_define
define|#
directive|define
name|MLY_RWCtl_RCE
value|(1)
end_define

begin_comment
comment|/* read cache enabled */
end_comment

begin_define
define|#
directive|define
name|MLY_RWCtl_RAHEAD
value|(2)
end_define

begin_comment
comment|/* readahead enabled */
end_comment

begin_define
define|#
directive|define
name|MLY_RWCtl_IRAHEAD
value|(3)
end_define

begin_comment
comment|/* intelligent readahead enabled */
end_comment

begin_comment
comment|/*  * 9.0 LUN Map Format  */
end_comment

begin_struct
struct|struct
name|mly_lun_map
block|{
name|u_int8_t
name|res1
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|host_port_mapped
range|:
literal|1
decl_stmt|;
comment|/* this system drive visibile to host on this controller/port combination */
name|u_int8_t
name|tid_valid
range|:
literal|1
decl_stmt|;
comment|/* target ID valid */
name|u_int8_t
name|hid_valid
range|:
literal|1
decl_stmt|;
comment|/* host ID valid */
name|u_int8_t
name|lun_valid
range|:
literal|1
decl_stmt|;
comment|/* LUN valid */
name|u_int8_t
name|res2
decl_stmt|;
name|u_int8_t
name|lun
decl_stmt|;
comment|/* LUN */
name|u_int8_t
name|tid
decl_stmt|;
comment|/* TID */
name|u_int8_t
name|hid
index|[
literal|32
index|]
decl_stmt|;
comment|/* HID (one bit for each host) */
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
comment|/*  * 10.1 Controller Parameters  */
end_comment

begin_struct
struct|struct
name|mly_param_controller
block|{
name|u_int8_t
name|rdahen
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|bilodly
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|fua_disable
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|reass1s
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|truvrfy
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|dwtvrfy
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|background_initialisation
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|clustering
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|bios_disable
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|boot_from_cdrom
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|drive_coercion
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|write_same_disable
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|hba_mode
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|bios_geometry
range|:
literal|2
decl_stmt|;
define|#
directive|define
name|MLY_BIOSGEOM_2G
value|0x0
define|#
directive|define
name|MLY_BIOSGEOM_8G
value|0x1
name|u_int8_t
name|res1
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res2
index|[
literal|2
index|]
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|v_dec
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|safte
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ses
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res3
range|:
literal|2
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|v_arm
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|v_ofm
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res4
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|rebuild_check_rate
decl_stmt|;
name|u_int8_t
name|cache_line_size
decl_stmt|;
comment|/* see 8.4 */
name|u_int8_t
name|oem_code
decl_stmt|;
define|#
directive|define
name|MLY_OEM_MYLEX
value|0x00
define|#
directive|define
name|MLY_OEM_IBM
value|0x08
define|#
directive|define
name|MLY_OEM_HP
value|0x0a
define|#
directive|define
name|MLY_OEM_DEC
value|0x0c
define|#
directive|define
name|MLY_OEM_SIEMENS
value|0x10
define|#
directive|define
name|MLY_OEM_INTEL
value|0x12
name|u_int8_t
name|spinup_mode
decl_stmt|;
define|#
directive|define
name|MLY_SPIN_AUTO
value|0
define|#
directive|define
name|MLY_SPIN_PWRSPIN
value|1
define|#
directive|define
name|MLY_SPIN_WSSUSPIN
value|2
name|u_int8_t
name|spinup_devices
decl_stmt|;
name|u_int8_t
name|spinup_interval
decl_stmt|;
name|u_int8_t
name|spinup_wait_time
decl_stmt|;
name|u_int8_t
name|res5
range|:
literal|3
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|vutursns
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|dccfil
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|nopause
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|disqfull
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|disbusy
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res6
range|:
literal|2
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|failover_node_name
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res7
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ftopo
range|:
literal|3
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|disable_ups
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res8
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|propagate_reset
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|nonstd_mp_reset
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res9
range|:
literal|5
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res10
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|serial_port_baud_rate
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|serial_port_control
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|change_stripe_ok_developer_flag_only
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|small_large_host_transfers
range|:
literal|2
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|frame_control
range|:
literal|2
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|pci_latency_control
range|:
literal|2
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|treat_lip_as_reset
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res11
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ms_autorest
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res12
range|:
literal|7
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ms_aa_fsim
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ms_aa_ccach
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ms_aa_fault_signals
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ms_aa_c4_faults
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ms_aa_host_reset_delay_mask
range|:
literal|4
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ms_flg_simplex_no_rstcom
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res13
range|:
literal|7
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res14
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|hardloopid
index|[
literal|2
index|]
index|[
literal|2
index|]
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ctrlname
index|[
literal|2
index|]
index|[
literal|16
operator|+
literal|1
index|]
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|initiator_id
decl_stmt|;
name|u_int8_t
name|startup_option
decl_stmt|;
define|#
directive|define
name|MLY_STARTUP_IF_NO_CHANGE
value|0x0
define|#
directive|define
name|MLY_STARTUP_IF_NO_LUN_CHANGE
value|0x1
define|#
directive|define
name|MLY_STARTUP_IF_NO_LUN_OFFLINE
value|0x2
define|#
directive|define
name|MLY_STARTUP_IF_LUN0_NO_CHANGE
value|0x3
define|#
directive|define
name|MLY_STARTUP_IF_LUN0_NOT_OFFLINE
value|0x4
define|#
directive|define
name|MLY_STARTUP_ALWAYS
value|0x5
name|u_int8_t
name|res15
index|[
literal|62
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
comment|/*  * 10.2 Physical Device Parameters  */
end_comment

begin_struct
struct|struct
name|mly_param_physical_device
block|{
name|u_int16_t
name|tags
decl_stmt|;
name|u_int16_t
name|speed
decl_stmt|;
name|u_int8_t
name|width
decl_stmt|;
name|u_int8_t
name|combing
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res1
range|:
literal|7
decl_stmt|;
name|u_int8_t
name|res2
index|[
literal|3
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
comment|/*  * 10.3 Logical Device Parameters  */
end_comment

begin_struct
struct|struct
name|mly_param_logical_device
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* see 8.2 */
name|u_int8_t
name|state
decl_stmt|;
comment|/* see 8.1 */
name|u_int16_t
name|raid_device
decl_stmt|;
name|u_int8_t
name|res1
decl_stmt|;
name|u_int8_t
name|bios_geometry
decl_stmt|;
comment|/* BIOS control word? */
name|u_int8_t
name|stripe_size
decl_stmt|;
comment|/* see 8.3 */
name|u_int8_t
name|read_write_control
decl_stmt|;
comment|/* see 8.5 */
name|u_int8_t
name|res2
index|[
literal|8
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
comment|/*  * 12.3 Health Status Buffer  *  * Pad to 128 bytes.  */
end_comment

begin_struct
struct|struct
name|mly_health_status
block|{
name|u_int32_t
name|uptime_us
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|uptime_ms
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|realtime
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|res1
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|change_counter
decl_stmt|;
name|u_int32_t
name|res2
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|debug_message_index
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|bios_message_index
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|trace_page
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|profiler_page
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|next_event
decl_stmt|;
name|u_int8_t
name|res3
index|[
literal|4
operator|+
literal|16
operator|+
literal|64
index|]
decl_stmt|;
comment|/* N/A */
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
comment|/*  * 14.2 Timeout Bit Format  */
end_comment

begin_struct
struct|struct
name|mly_timeout
block|{
name|u_int8_t
name|value
range|:
literal|6
decl_stmt|;
name|u_int8_t
name|scale
range|:
literal|2
decl_stmt|;
define|#
directive|define
name|MLY_TIMEOUT_SECONDS
value|0x0
define|#
directive|define
name|MLY_TIMEOUT_MINUTES
value|0x1
define|#
directive|define
name|MLY_TIMEOUT_HOURS
value|0x2
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
comment|/*  * 14.3 Operation Device  */
end_comment

begin_define
define|#
directive|define
name|MLY_OPDEVICE_PHYSICAL_DEVICE
value|0x0
end_define

begin_define
define|#
directive|define
name|MLY_OPDEVICE_RAID_DEVICE
value|0x1
end_define

begin_define
define|#
directive|define
name|MLY_OPDEVICE_PHYSICAL_CHANNEL
value|0x2
end_define

begin_define
define|#
directive|define
name|MLY_OPDEVICE_RAID_CHANNEL
value|0x3
end_define

begin_define
define|#
directive|define
name|MLY_OPDEVICE_PHYSICAL_CONTROLLER
value|0x4
end_define

begin_define
define|#
directive|define
name|MLY_OPDEVICE_RAID_CONTROLLER
value|0x5
end_define

begin_define
define|#
directive|define
name|MLY_OPDEVICE_CONFIGURATION_GROUP
value|0x10
end_define

begin_comment
comment|/*  * 14.4 Status Bit Format  *  * AKA Status Mailbox Format  *  * XXX format conflict between FSI and PG6 over the ordering of the  * status and sense length fields.  */
end_comment

begin_struct
struct|struct
name|mly_status
block|{
name|u_int16_t
name|command_id
decl_stmt|;
name|u_int8_t
name|status
decl_stmt|;
name|u_int8_t
name|sense_length
decl_stmt|;
name|int32_t
name|residue
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
comment|/*  * 14.5 Command Control Bit (CCB) format  *  * This byte is unfortunately named.  */
end_comment

begin_struct
struct|struct
name|mly_command_control
block|{
name|u_int8_t
name|force_unit_access
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|disable_page_out
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res1
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|extended_sg_table
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|data_direction
range|:
literal|1
decl_stmt|;
define|#
directive|define
name|MLY_CCB_WRITE
value|1
define|#
directive|define
name|MLY_CCB_READ
value|0
name|u_int8_t
name|res2
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|no_auto_sense
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|disable_disconnect
range|:
literal|1
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
comment|/*  * 15.0 Commands  *  * We use the command names as given by Mylex  */
end_comment

begin_define
define|#
directive|define
name|MDACMD_MEMCOPY
value|0x1
end_define

begin_comment
comment|/* memory to memory copy */
end_comment

begin_define
define|#
directive|define
name|MDACMD_SCSIPT
value|0x2
end_define

begin_comment
comment|/* SCSI passthrough (small command) */
end_comment

begin_define
define|#
directive|define
name|MDACMD_SCSILCPT
value|0x3
end_define

begin_comment
comment|/* SCSI passthrough (large command) */
end_comment

begin_define
define|#
directive|define
name|MDACMD_SCSI
value|0x4
end_define

begin_comment
comment|/* SCSI command for logical/phyiscal device (small command) */
end_comment

begin_define
define|#
directive|define
name|MDACMD_SCSILC
value|0x5
end_define

begin_comment
comment|/* SCSI command for logical/phyiscal device (large command) */
end_comment

begin_define
define|#
directive|define
name|MDACMD_IOCTL
value|0x20
end_define

begin_comment
comment|/* Management command */
end_comment

begin_define
define|#
directive|define
name|MDACMD_IOCTLCHECK
value|0x23
end_define

begin_comment
comment|/* Validate management command (not implemented) */
end_comment

begin_comment
comment|/*  * 16.0 IOCTL command  *  * We use the IOCTL names as given by Mylex  * Note that only ioctls supported by the PCI controller family are listed  */
end_comment

begin_define
define|#
directive|define
name|MDACIOCTL_GETCONTROLLERINFO
value|0x1
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETLOGDEVINFOVALID
value|0x3
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETPHYSDEVINFOVALID
value|0x5
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETCONTROLLERSTATISTICS
value|0xb
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETLOGDEVSTATISTICS
value|0xd
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETPHYSDEVSTATISTICS
value|0xf
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETHEALTHSTATUS
value|0x11
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETEVENT
value|0x15
end_define

begin_comment
comment|/* flash update */
end_comment

begin_define
define|#
directive|define
name|MDACIOCTL_STOREIMAGE
value|0x2c
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_READIMAGE
value|0x2d
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_FLASHIMAGES
value|0x2e
end_define

begin_comment
comment|/* battery backup unit */
end_comment

begin_define
define|#
directive|define
name|MDACIOCTL_GET_SUBSYSTEM_DATA
value|0x70
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_SET_SUBSYSTEM_DATA
value|0x71
end_define

begin_comment
comment|/* non-data commands */
end_comment

begin_define
define|#
directive|define
name|MDACIOCTL_STARTDISOCVERY
value|0x81
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_SETRAIDDEVSTATE
value|0x82
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_INITPHYSDEVSTART
value|0x84
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_INITPHYSDEVSTOP
value|0x85
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_INITRAIDDEVSTART
value|0x86
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_INITRAIDDEVSTOP
value|0x87
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_REBUILDRAIDDEVSTART
value|0x88
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_REBUILDRAIDDEVSTOP
value|0x89
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_MAKECONSISTENTDATASTART
value|0x8a
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_MAKECONSISTENTDATASTOP
value|0x8b
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_CONSISTENCYCHECKSTART
value|0x8c
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_CONSISTENCYCHECKSTOP
value|0x8d
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_SETMEMORYMAILBOX
value|0x8e
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_RESETDEVICE
value|0x90
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_FLUSHDEVICEDATA
value|0x91
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_PAUSEDEVICE
value|0x92
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_UNPAUSEDEVICE
value|0x93
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_LOCATEDEVICE
value|0x94
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_SETMASTERSLAVEMODE
value|0x95
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_SETREALTIMECLOCK
value|0xac
end_define

begin_comment
comment|/* RAID configuration */
end_comment

begin_define
define|#
directive|define
name|MDACIOCTL_CREATENEWCONF
value|0xc0
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_DELETERAIDDEV
value|0xc1
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_REPLACEINTERNALDEV
value|0xc2
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_RENAMERAIDDEV
value|0xc3
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_ADDNEWCONF
value|0xc4
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_XLATEPHYSDEVTORAIDDEV
value|0xc5
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_MORE
value|0xc6
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_SETPHYSDEVPARAMETER
value|0xc8
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETPHYSDEVPARAMETER
value|0xc9
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_CLEARCONF
value|0xca
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETDEVCONFINFO
value|0xcb
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETGROUPCONFINFO
value|0xcc
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETFREESPACELIST
value|0xcd
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETLOGDEVPARAMETER
value|0xce
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_SETLOGDEVPARAMETER
value|0xcf
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETCONTROLLERPARAMETER
value|0xd0
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_SETCONTRLLERPARAMETER
value|0xd1
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_CLEARCONFSUSPMODE
value|0xd2
end_define

begin_define
define|#
directive|define
name|MDACIOCTL_GETBDT_FOR_SYSDRIVE
value|0xe0
end_define

begin_comment
comment|/*  * 17.1.4 Data Transfer Memory Address Without SG List  */
end_comment

begin_struct
struct|struct
name|mly_short_transfer
block|{
name|struct
name|mly_sg_entry
name|sg
index|[
literal|2
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
comment|/*  * 17.1.5 Data Transfer Memory Address With SG List  *  * Note that only the first s/g table is currently used.  */
end_comment

begin_struct
struct|struct
name|mly_sg_transfer
block|{
name|u_int16_t
name|entries
index|[
literal|3
index|]
decl_stmt|;
name|u_int16_t
name|res1
decl_stmt|;
name|u_int64_t
name|table_physaddr
index|[
literal|3
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
comment|/*  * 17.1.3 Data Transfer Memory Address Format  */
end_comment

begin_union
union|union
name|mly_command_transfer
block|{
name|struct
name|mly_short_transfer
name|direct
decl_stmt|;
name|struct
name|mly_sg_transfer
name|indirect
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * 21.1  MDACIOCTL_SETREALTIMECLOCK  * 21.7  MDACIOCTL_GETHEALTHSTATUS  * 21.8  MDACIOCTL_GETCONTROLLERINFO  * 21.9  MDACIOCTL_GETLOGDEVINFOVALID  * 21.10 MDACIOCTL_GETPHYSDEVINFOVALID  * 21.11 MDACIOCTL_GETPHYSDEVSTATISTICS  * 21.12 MDACIOCTL_GETLOGDEVSTATISTICS  * 21.13 MDACIOCTL_GETCONTROLLERSTATISTICS  * 21.27 MDACIOCTL_GETBDT_FOR_SYSDRIVE  * 23.4  MDACIOCTL_CREATENEWCONF  * 23.5  MDACIOCTL_ADDNEWCONF  * 23.8  MDACIOCTL_GETDEVCONFINFO  * 23.9  MDACIOCTL_GETFREESPACELIST  * 24.1  MDACIOCTL_MORE  * 25.1  MDACIOCTL_GETPHYSDEVPARAMETER  * 25.2  MDACIOCTL_SETPHYSDEVPARAMETER  * 25.3  MDACIOCTL_GETLOGDEVPARAMETER  * 25.4  MDACIOCTL_SETLOGDEVPARAMETER  * 25.5  MDACIOCTL_GETCONTROLLERPARAMETER  * 25.6  MDACIOCTL_SETCONTROLLERPARAMETER  *  * These commands just transfer data  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_param_data
block|{
name|u_int8_t
name|param
index|[
literal|10
index|]
decl_stmt|;
name|union
name|mly_command_transfer
name|transfer
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
comment|/*  * 21.2 MDACIOCTL_SETMEMORYMAILBOX  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_param_setmemorymailbox
block|{
name|u_int8_t
name|health_buffer_size
decl_stmt|;
name|u_int8_t
name|res1
decl_stmt|;
name|u_int64_t
name|health_buffer_physaddr
decl_stmt|;
name|u_int64_t
name|command_mailbox_physaddr
decl_stmt|;
name|u_int64_t
name|status_mailbox_physaddr
decl_stmt|;
name|u_int64_t
name|res2
index|[
literal|2
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
comment|/*  * 21.8.2 MDACIOCTL_GETCONTROLLERINFO: Data Format  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_getcontrollerinfo
block|{
name|u_int8_t
name|res1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|interface_type
decl_stmt|;
name|u_int8_t
name|controller_type
decl_stmt|;
name|u_int8_t
name|res2
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|interface_speed
decl_stmt|;
name|u_int8_t
name|interface_width
decl_stmt|;
name|u_int8_t
name|res3
index|[
literal|9
index|]
decl_stmt|;
comment|/* N/A */
name|char
name|interface_name
index|[
literal|16
index|]
decl_stmt|;
name|char
name|controller_name
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|res4
index|[
literal|16
index|]
decl_stmt|;
comment|/* N/A */
comment|/* firmware release information */
name|u_int8_t
name|fw_major
decl_stmt|;
name|u_int8_t
name|fw_minor
decl_stmt|;
name|u_int8_t
name|fw_turn
decl_stmt|;
name|u_int8_t
name|fw_build
decl_stmt|;
name|u_int8_t
name|fw_day
decl_stmt|;
name|u_int8_t
name|fw_month
decl_stmt|;
name|u_int8_t
name|fw_century
decl_stmt|;
name|u_int8_t
name|fw_year
decl_stmt|;
comment|/* hardware release information */
name|u_int8_t
name|hw_revision
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res5
index|[
literal|3
index|]
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|hw_release_day
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|hw_release_month
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|hw_release_century
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|hw_release_year
decl_stmt|;
comment|/* N/A */
comment|/* hardware manufacturing information */
name|u_int8_t
name|batch_number
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res6
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|plant_number
decl_stmt|;
name|u_int8_t
name|res7
decl_stmt|;
name|u_int8_t
name|hw_manuf_day
decl_stmt|;
name|u_int8_t
name|hw_manuf_month
decl_stmt|;
name|u_int8_t
name|hw_manuf_century
decl_stmt|;
name|u_int8_t
name|hw_manuf_year
decl_stmt|;
name|u_int8_t
name|max_pdd_per_xldd
decl_stmt|;
name|u_int8_t
name|max_ildd_per_xldd
decl_stmt|;
name|u_int16_t
name|nvram_size
decl_stmt|;
name|u_int8_t
name|max_number_of_xld
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res8
index|[
literal|3
index|]
decl_stmt|;
comment|/* N/A */
comment|/* unique information per controller */
name|char
name|serial_number
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|res9
index|[
literal|16
index|]
decl_stmt|;
comment|/* N/A */
comment|/* vendor information */
name|u_int8_t
name|res10
index|[
literal|3
index|]
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|oem_information
decl_stmt|;
name|char
name|vendor_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* N/A */
comment|/* other physical/controller/operation information */
name|u_int8_t
name|bbu_present
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|active_clustering
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res11
range|:
literal|6
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res12
index|[
literal|3
index|]
decl_stmt|;
comment|/* N/A */
comment|/* physical device scan information */
name|u_int8_t
name|physical_scan_active
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res13
range|:
literal|7
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|physical_scan_channel
decl_stmt|;
name|u_int8_t
name|physical_scan_target
decl_stmt|;
name|u_int8_t
name|physical_scan_lun
decl_stmt|;
comment|/* maximum command data transfer size */
name|u_int16_t
name|maximum_block_count
decl_stmt|;
name|u_int16_t
name|maximum_sg_entries
decl_stmt|;
comment|/* logical/physical device counts */
name|u_int16_t
name|logical_devices_present
decl_stmt|;
name|u_int16_t
name|logical_devices_critical
decl_stmt|;
name|u_int16_t
name|logical_devices_offline
decl_stmt|;
name|u_int16_t
name|physical_devices_present
decl_stmt|;
name|u_int16_t
name|physical_disks_present
decl_stmt|;
name|u_int16_t
name|physical_disks_critical
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_disks_offline
decl_stmt|;
name|u_int16_t
name|maximum_parallel_commands
decl_stmt|;
comment|/* channel and target ID information */
name|u_int8_t
name|physical_channels_present
decl_stmt|;
name|u_int8_t
name|virtual_channels_present
decl_stmt|;
name|u_int8_t
name|physical_channels_possible
decl_stmt|;
name|u_int8_t
name|virtual_channels_possible
decl_stmt|;
name|u_int8_t
name|maximum_targets_possible
index|[
literal|16
index|]
decl_stmt|;
comment|/* N/A (6 and up) */
name|u_int8_t
name|res14
index|[
literal|12
index|]
decl_stmt|;
comment|/* N/A */
comment|/* memory/cache information */
name|u_int16_t
name|memory_size
decl_stmt|;
name|u_int16_t
name|cache_size
decl_stmt|;
name|u_int32_t
name|valid_cache_size
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|dirty_cache_size
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|memory_speed
decl_stmt|;
name|u_int8_t
name|memory_width
decl_stmt|;
name|u_int8_t
name|memory_type
range|:
literal|5
decl_stmt|;
name|u_int8_t
name|res15
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|memory_parity
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|memory_ecc
range|:
literal|1
decl_stmt|;
name|char
name|memory_information
index|[
literal|16
index|]
decl_stmt|;
comment|/* N/A */
comment|/* execution memory information */
name|u_int16_t
name|exmemory_size
decl_stmt|;
name|u_int16_t
name|l2cache_size
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res16
index|[
literal|8
index|]
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|exmemory_speed
decl_stmt|;
name|u_int8_t
name|exmemory_width
decl_stmt|;
name|u_int8_t
name|exmemory_type
range|:
literal|5
decl_stmt|;
name|u_int8_t
name|res17
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|exmemory_parity
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|exmemory_ecc
range|:
literal|1
decl_stmt|;
name|char
name|exmemory_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* N/A */
comment|/* CPU information */
struct|struct
block|{
name|u_int16_t
name|speed
decl_stmt|;
name|u_int8_t
name|type
decl_stmt|;
name|u_int8_t
name|number
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|12
index|]
decl_stmt|;
comment|/* N/A */
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|/* N/A */
block|}
name|cpu
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
comment|/* debugging/profiling/command time tracing information */
name|u_int16_t
name|profiling_page
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|profiling_programs
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|time_trace_page
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|time_trace_programs
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res18
index|[
literal|8
index|]
decl_stmt|;
comment|/* N/A */
comment|/* error counters on physical devices */
name|u_int16_t
name|physical_device_bus_resets
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_device_parity_errors
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_device_soft_errors
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_device_commands_failed
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_device_miscellaneous_errors
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_device_command_timeouts
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_device_selection_timeouts
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_device_retries
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_device_aborts
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_device_host_command_aborts
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_device_PFAs_detected
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|physical_device_host_commands_failed
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res19
index|[
literal|8
index|]
decl_stmt|;
comment|/* N/A */
comment|/* error counters on logical devices */
name|u_int16_t
name|logical_device_soft_errors
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|logical_device_commands_failed
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|logical_device_host_command_aborts
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|res20
decl_stmt|;
comment|/* N/A */
comment|/* error counters on controller */
name|u_int16_t
name|controller_parity_ecc_errors
decl_stmt|;
name|u_int16_t
name|controller_host_command_aborts
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res21
index|[
literal|4
index|]
decl_stmt|;
comment|/* N/A */
comment|/* long duration activity information */
name|u_int16_t
name|background_inits_active
decl_stmt|;
name|u_int16_t
name|logical_inits_active
decl_stmt|;
name|u_int16_t
name|physical_inits_active
decl_stmt|;
name|u_int16_t
name|consistency_checks_active
decl_stmt|;
name|u_int16_t
name|rebuilds_active
decl_stmt|;
name|u_int16_t
name|MORE_active
decl_stmt|;
name|u_int16_t
name|patrol_active
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|long_operation_status
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res22
decl_stmt|;
comment|/* N/A */
comment|/* flash ROM information */
name|u_int8_t
name|flash_type
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res23
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|flash_size
decl_stmt|;
name|u_int32_t
name|flash_maximum_age
decl_stmt|;
name|u_int32_t
name|flash_age
decl_stmt|;
name|u_int8_t
name|res24
index|[
literal|4
index|]
decl_stmt|;
comment|/* N/A */
name|char
name|flash_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* N/A */
comment|/* firmware runtime information */
name|u_int8_t
name|rebuild_rate
decl_stmt|;
name|u_int8_t
name|background_init_rate
decl_stmt|;
name|u_int8_t
name|init_rate
decl_stmt|;
name|u_int8_t
name|consistency_check_rate
decl_stmt|;
name|u_int8_t
name|res25
index|[
literal|4
index|]
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|maximum_dp
decl_stmt|;
name|u_int32_t
name|free_dp
decl_stmt|;
name|u_int32_t
name|maximum_iop
decl_stmt|;
name|u_int32_t
name|free_iop
decl_stmt|;
name|u_int16_t
name|maximum_comb_length
decl_stmt|;
name|u_int16_t
name|maximum_configuration_groups
decl_stmt|;
name|u_int8_t
name|installation_abort
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|maintenance
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res26
range|:
literal|6
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res27
index|[
literal|3
index|]
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res28
index|[
literal|32
operator|+
literal|512
index|]
decl_stmt|;
comment|/* N/A */
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
comment|/*  * 21.9.2 MDACIOCTL_GETLOGDEVINFOVALID  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_getlogdevinfovalid
block|{
name|u_int8_t
name|res1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|channel
decl_stmt|;
name|u_int8_t
name|target
decl_stmt|;
name|u_int8_t
name|lun
decl_stmt|;
name|u_int8_t
name|state
decl_stmt|;
comment|/* see 8.1 */
name|u_int8_t
name|raid_level
decl_stmt|;
comment|/* see 8.2 */
name|u_int8_t
name|stripe_size
decl_stmt|;
comment|/* see 8.3 */
name|u_int8_t
name|cache_line_size
decl_stmt|;
comment|/* see 8.4 */
name|u_int8_t
name|read_write_control
decl_stmt|;
comment|/* see 8.5 */
name|u_int8_t
name|consistency_check
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|rebuild
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|make_consistent
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|initialisation
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|migration
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|patrol
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res2
range|:
literal|2
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ar5_limit
decl_stmt|;
name|u_int8_t
name|ar5_algo
decl_stmt|;
name|u_int16_t
name|logical_device_number
decl_stmt|;
name|u_int16_t
name|bios_control
decl_stmt|;
comment|/* erorr counters */
name|u_int16_t
name|soft_errors
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|commands_failed
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|host_command_aborts
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|deferred_write_errors
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res3
index|[
literal|8
index|]
decl_stmt|;
comment|/* N/A */
comment|/* device size information */
name|u_int8_t
name|res4
index|[
literal|2
index|]
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|device_block_size
decl_stmt|;
name|u_int32_t
name|original_device_size
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|device_size
decl_stmt|;
comment|/* XXX "blocks or MB" Huh? */
name|u_int8_t
name|res5
index|[
literal|4
index|]
decl_stmt|;
comment|/* N/A */
name|char
name|device_name
index|[
literal|32
index|]
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|inquiry
index|[
literal|36
index|]
decl_stmt|;
name|u_int8_t
name|res6
index|[
literal|12
index|]
decl_stmt|;
comment|/* N/A */
name|u_int64_t
name|last_read_block
decl_stmt|;
comment|/* N/A */
name|u_int64_t
name|last_written_block
decl_stmt|;
comment|/* N/A */
name|u_int64_t
name|consistency_check_block
decl_stmt|;
name|u_int64_t
name|rebuild_block
decl_stmt|;
name|u_int64_t
name|make_consistent_block
decl_stmt|;
name|u_int64_t
name|initialisation_block
decl_stmt|;
name|u_int64_t
name|migration_block
decl_stmt|;
name|u_int64_t
name|patrol_block
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res7
index|[
literal|64
index|]
decl_stmt|;
comment|/* N/A */
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
comment|/*  * 21.10.2 MDACIOCTL_GETPHYSDEVINFOVALID: Data Format  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_getphysdevinfovalid
block|{
name|u_int8_t
name|res1
decl_stmt|;
name|u_int8_t
name|channel
decl_stmt|;
name|u_int8_t
name|target
decl_stmt|;
name|u_int8_t
name|lun
decl_stmt|;
name|u_int8_t
name|raid_ft
range|:
literal|1
decl_stmt|;
comment|/* configuration status */
name|u_int8_t
name|res2
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|local
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|res3
range|:
literal|5
decl_stmt|;
name|u_int8_t
name|host_dead
range|:
literal|1
decl_stmt|;
comment|/* multiple host/controller status */
comment|/* N/A */
name|u_int8_t
name|host_connection_dead
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res4
range|:
literal|6
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|state
decl_stmt|;
comment|/* see 8.1 */
name|u_int8_t
name|width
decl_stmt|;
name|u_int16_t
name|speed
decl_stmt|;
comment|/* multiported physical device information */
name|u_int8_t
name|ports_available
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|ports_inuse
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res5
index|[
literal|4
index|]
decl_stmt|;
name|u_int8_t
name|ether_address
index|[
literal|16
index|]
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|command_tags
decl_stmt|;
name|u_int8_t
name|consistency_check
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|rebuild
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|make_consistent
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|initialisation
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|migration
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|patrol
range|:
literal|1
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res6
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|long_operation_status
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|parity_errors
decl_stmt|;
name|u_int8_t
name|soft_errors
decl_stmt|;
name|u_int8_t
name|hard_errors
decl_stmt|;
name|u_int8_t
name|miscellaneous_errors
decl_stmt|;
name|u_int8_t
name|command_timeouts
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|retries
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|aborts
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|PFAs_detected
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res7
index|[
literal|6
index|]
decl_stmt|;
name|u_int16_t
name|block_size
decl_stmt|;
name|u_int32_t
name|original_device_size
decl_stmt|;
comment|/* XXX "blocks or MB" Huh? */
name|u_int32_t
name|device_size
decl_stmt|;
comment|/* XXX "blocks or MB" Huh? */
name|u_int8_t
name|res8
index|[
literal|4
index|]
decl_stmt|;
name|char
name|name
index|[
literal|16
index|]
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res9
index|[
literal|16
operator|+
literal|32
index|]
decl_stmt|;
name|u_int8_t
name|inquiry
index|[
literal|36
index|]
decl_stmt|;
name|u_int8_t
name|res10
index|[
literal|12
operator|+
literal|16
index|]
decl_stmt|;
name|u_int64_t
name|last_read_block
decl_stmt|;
comment|/* N/A */
name|u_int64_t
name|last_written_block
decl_stmt|;
comment|/* N/A */
name|u_int64_t
name|consistency_check_block
decl_stmt|;
comment|/* N/A */
name|u_int64_t
name|rebuild_block
decl_stmt|;
comment|/* N/A */
name|u_int64_t
name|make_consistent_block
decl_stmt|;
comment|/* N/A */
name|u_int64_t
name|initialisation_block
decl_stmt|;
comment|/* N/A */
name|u_int64_t
name|migration_block
decl_stmt|;
comment|/* N/A */
name|u_int64_t
name|patrol_block
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res11
index|[
literal|256
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

begin_union
union|union
name|mly_devinfo
block|{
name|struct
name|mly_ioctl_getlogdevinfovalid
name|logdev
decl_stmt|;
name|struct
name|mly_ioctl_getphysdevinfovalid
name|physdev
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * 21.11.2 MDACIOCTL_GETPHYSDEVSTATISTICS: Data Format  * 21.12.2 MDACIOCTL_GETLOGDEVSTATISTICS: Data Format  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_getdevstatistics
block|{
name|u_int32_t
name|uptime_ms
decl_stmt|;
comment|/* getphysedevstatistics only */
name|u_int8_t
name|res1
index|[
literal|5
index|]
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|channel
decl_stmt|;
name|u_int8_t
name|target
decl_stmt|;
name|u_int8_t
name|lun
decl_stmt|;
name|u_int16_t
name|raid_device
decl_stmt|;
comment|/* getlogdevstatistics only */
name|u_int8_t
name|res2
index|[
literal|2
index|]
decl_stmt|;
comment|/* N/A */
comment|/* total read/write performance including cache data */
name|u_int32_t
name|total_reads
decl_stmt|;
name|u_int32_t
name|total_writes
decl_stmt|;
name|u_int32_t
name|total_read_size
decl_stmt|;
name|u_int32_t
name|total_write_size
decl_stmt|;
comment|/* cache read/write performance */
name|u_int32_t
name|cache_reads
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|cache_writes
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|cache_read_size
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|cache_write_size
decl_stmt|;
comment|/* N/A */
comment|/* commands active/wait information */
name|u_int32_t
name|command_waits_done
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|active_commands
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|waiting_commands
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res3
index|[
literal|8
index|]
decl_stmt|;
comment|/* N/A */
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
comment|/*  * 21.13.2 MDACIOCTL_GETCONTROLLERSTATISTICS: Data Format  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_getcontrollerstatistics
block|{
name|u_int32_t
name|uptime_ms
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res1
index|[
literal|12
index|]
decl_stmt|;
comment|/* N/A */
comment|/* target physical device performance data information */
name|u_int32_t
name|target_physical_device_interrupts
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|target_physical_device_stray_interrupts
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res2
index|[
literal|8
index|]
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|target_physical_device_reads
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|target_physical_device_writes
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|target_physical_device_read_size
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|target_physical_device_write_size
decl_stmt|;
comment|/* N/A */
comment|/* host system performance data information */
name|u_int32_t
name|host_system_interrupts
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|host_system_stray_interrupts
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|host_system_sent_interrupts
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res3
index|[
literal|4
index|]
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|physical_device_reads
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|physical_device_writes
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|physical_device_read_size
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|physical_device_write_size
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|physical_device_cache_reads
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|physical_device_cache_writes
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|physical_device_cache_read_size
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|physical_device_cache_write_size
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|logical_device_reads
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|logical_device_writes
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|logical_device_read_size
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|logical_device_write_size
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|logical_device_cache_reads
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|logical_device_cache_writes
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|logical_device_cache_read_size
decl_stmt|;
comment|/* N/A */
name|u_int32_t
name|logical_device_cache_write_size
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|target_physical_device_commands_active
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|target_physical_device_commands_waiting
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|host_system_commands_active
decl_stmt|;
comment|/* N/A */
name|u_int16_t
name|host_system_commands_waiting
decl_stmt|;
comment|/* N/A */
name|u_int8_t
name|res4
index|[
literal|48
operator|+
literal|64
index|]
decl_stmt|;
comment|/* N/A */
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
comment|/*  * 21.2 MDACIOCTL_SETRAIDDEVSTATE  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_param_setraiddevstate
block|{
name|u_int8_t
name|state
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
comment|/*  * 21.27.2 MDACIOCTL_GETBDT_FOR_SYSDRIVE: Data Format  */
end_comment

begin_define
define|#
directive|define
name|MLY_MAX_BDT_ENTRIES
value|1022
end_define

begin_struct
struct|struct
name|mly_ioctl_getbdt_for_sysdrive
block|{
name|u_int32_t
name|num_of_bdt_entries
decl_stmt|;
name|u_int32_t
name|bad_data_block_address
index|[
name|MLY_MAX_BDT_ENTRIES
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
comment|/*  * 22.1 Physical Device Definition (PDD)  */
end_comment

begin_struct
struct|struct
name|mly_pdd
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* see 8.2 */
name|u_int8_t
name|state
decl_stmt|;
comment|/* see 8.1 */
name|u_int16_t
name|raid_device
decl_stmt|;
name|u_int32_t
name|device_size
decl_stmt|;
comment|/* XXX "block or MB" Huh? */
name|u_int8_t
name|controller
decl_stmt|;
name|u_int8_t
name|channel
decl_stmt|;
name|u_int8_t
name|target
decl_stmt|;
name|u_int8_t
name|lun
decl_stmt|;
name|u_int32_t
name|start_address
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
comment|/*  * 22.2 RAID Device Use Definition (UDD)  */
end_comment

begin_struct
struct|struct
name|mly_udd
block|{
name|u_int8_t
name|res1
decl_stmt|;
name|u_int8_t
name|state
decl_stmt|;
comment|/* see 8.1 */
name|u_int16_t
name|raid_device
decl_stmt|;
name|u_int32_t
name|start_address
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
comment|/*  * RAID Device Definition (LDD)  */
end_comment

begin_struct
struct|struct
name|mly_ldd
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* see 8.2 */
name|u_int8_t
name|state
decl_stmt|;
comment|/* see 8.1 */
name|u_int16_t
name|raid_device
decl_stmt|;
name|u_int32_t
name|device_size
decl_stmt|;
comment|/* XXX "block or MB" Huh? */
name|u_int8_t
name|devices_used_count
decl_stmt|;
name|u_int8_t
name|stripe_size
decl_stmt|;
comment|/* see 8.3 */
name|u_int8_t
name|cache_line_size
decl_stmt|;
comment|/* see 8.4 */
name|u_int8_t
name|read_write_control
decl_stmt|;
comment|/* see 8.5 */
name|u_int32_t
name|devices_used_size
decl_stmt|;
comment|/* XXX "block or MB" Huh? */
name|u_int16_t
name|devices_used
index|[
literal|32
index|]
decl_stmt|;
comment|/* XXX actual size of this field unknown! */
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
comment|/*  * Define a datastructure giving the smallest allocation that will hold  * a PDD, UDD or LDD for MDACIOCTL_GETDEVCONFINFO.  */
end_comment

begin_struct
struct|struct
name|mly_devconf_hdr
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* see 8.2 */
name|u_int8_t
name|state
decl_stmt|;
comment|/* see 8.1 */
name|u_int16_t
name|raid_device
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|mly_ioctl_devconfinfo
block|{
name|struct
name|mly_pdd
name|pdd
decl_stmt|;
name|struct
name|mly_udd
name|udd
decl_stmt|;
name|struct
name|mly_ldd
name|ldd
decl_stmt|;
name|struct
name|mly_devconf_hdr
name|hdr
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * 22.3 MDACIOCTL_RENAMERAIDDEV  *  * XXX this command is listed as transferring data, but does not define the data.  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_param_renameraiddev
block|{
name|u_int8_t
name|new_raid_device
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
comment|/*  * 23.6.2 MDACIOCTL_XLATEPHYSDEVTORAIDDEV  *  * XXX documentation suggests this format will change  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_param_xlatephysdevtoraiddev
block|{
name|u_int16_t
name|raid_device
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|controller
decl_stmt|;
name|u_int8_t
name|channel
decl_stmt|;
name|u_int8_t
name|target
decl_stmt|;
name|u_int8_t
name|lun
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
comment|/*  * 23.7 MDACIOCTL_GETGROUPCONFINFO  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_param_getgroupconfinfo
block|{
name|u_int16_t
name|group
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|8
index|]
decl_stmt|;
name|union
name|mly_command_transfer
name|transfer
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
comment|/*  * 23.9.2 MDACIOCTL_GETFREESPACELIST: Data Format  *  * The controller will populate as much of this structure as is provided,  * or as is required to fully list the free space available.  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_getfreespacelist_entry
block|{
name|u_int16_t
name|raid_device
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|6
index|]
decl_stmt|;
name|u_int32_t
name|address
decl_stmt|;
comment|/* XXX "blocks or MB" Huh? */
name|u_int32_t
name|size
decl_stmt|;
comment|/* XXX "blocks or MB" Huh? */
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
name|mly_ioctl_getfrespacelist
block|{
name|u_int16_t
name|returned_entries
decl_stmt|;
name|u_int16_t
name|total_entries
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|12
index|]
decl_stmt|;
name|struct
name|mly_ioctl_getfreespacelist_entry
name|space
index|[
literal|0
index|]
decl_stmt|;
comment|/* expand to suit */
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
comment|/*  * 27.1 MDACIOCTL_GETSUBSYSTEMDATA  * 27.2 MDACIOCTL_SETSUBSYSTEMDATA  *  * PCI controller only supports a limited subset of the possible operations.  *  * XXX where does the status end up? (the command transfers no data)  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_param_subsystemdata
block|{
name|u_int8_t
name|operation
range|:
literal|4
decl_stmt|;
define|#
directive|define
name|MLY_BBU_GETSTATUS
value|0x00
define|#
directive|define
name|MLY_BBU_SET_THRESHOLD
value|0x00
comment|/* minutes in param[0,1] */
name|u_int8_t
name|subsystem
range|:
literal|4
decl_stmt|;
define|#
directive|define
name|MLY_SUBSYSTEM_BBU
value|0x01
name|u_int
name|parameter
index|[
literal|3
index|]
decl_stmt|;
comment|/* only for SETSUBSYSTEMDATA */
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
name|mly_ioctl_getsubsystemdata_bbustatus
block|{
name|u_int16_t
name|current_power
decl_stmt|;
name|u_int16_t
name|maximum_power
decl_stmt|;
name|u_int16_t
name|power_threshold
decl_stmt|;
name|u_int8_t
name|charge_level
decl_stmt|;
name|u_int8_t
name|hardware_version
decl_stmt|;
name|u_int8_t
name|battery_type
decl_stmt|;
define|#
directive|define
name|MLY_BBU_TYPE_UNKNOWN
value|0x00
define|#
directive|define
name|MLY_BBU_TYPE_NICAD
value|0x01
define|#
directive|define
name|MLY_BBU_TYPE_MISSING
value|0xfe
name|u_int8_t
name|res1
decl_stmt|;
name|u_int8_t
name|operation_status
decl_stmt|;
define|#
directive|define
name|MLY_BBU_STATUS_NO_SYNC
value|0x01
define|#
directive|define
name|MLY_BBU_STATUS_OUT_OF_SYNC
value|0x02
define|#
directive|define
name|MLY_BBU_STATUS_FIRST_WARNING
value|0x04
define|#
directive|define
name|MLY_BBU_STATUS_SECOND_WARNING
value|0x08
define|#
directive|define
name|MLY_BBU_STATUS_RECONDITIONING
value|0x10
define|#
directive|define
name|MLY_BBU_STATUS_DISCHARGING
value|0x20
define|#
directive|define
name|MLY_BBU_STATUS_FASTCHARGING
value|0x40
name|u_int8_t
name|res2
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
comment|/*  * 28.9  MDACIOCTL_RESETDEVICE  * 28.10 MDACIOCTL_FLUSHDEVICEDATA  * 28.11 MDACIOCTL_PAUSEDEVICE  * 28.12 MDACIOCTL_UNPAUSEDEVICE  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_param_deviceoperation
block|{
name|u_int8_t
name|operation_device
decl_stmt|;
comment|/* see 14.3 */
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
comment|/*  * 31.1 Event Data Format  */
end_comment

begin_struct
struct|struct
name|mly_event
block|{
name|u_int32_t
name|sequence_number
decl_stmt|;
name|u_int32_t
name|timestamp
decl_stmt|;
name|u_int32_t
name|code
decl_stmt|;
name|u_int8_t
name|controller
decl_stmt|;
name|u_int8_t
name|channel
decl_stmt|;
name|u_int8_t
name|target
decl_stmt|;
comment|/* also enclosure */
name|u_int8_t
name|lun
decl_stmt|;
comment|/* also enclosure unit */
name|u_int8_t
name|res1
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|param
decl_stmt|;
name|u_int8_t
name|sense
index|[
literal|40
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
comment|/*  * 31.2 MDACIOCTL_GETEVENT  */
end_comment

begin_struct
struct|struct
name|mly_ioctl_param_getevent
block|{
name|u_int16_t
name|sequence_number_low
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|8
index|]
decl_stmt|;
name|union
name|mly_command_transfer
name|transfer
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

begin_union
union|union
name|mly_ioctl_param
block|{
name|struct
name|mly_ioctl_param_data
name|data
decl_stmt|;
name|struct
name|mly_ioctl_param_setmemorymailbox
name|setmemorymailbox
decl_stmt|;
name|struct
name|mly_ioctl_param_setraiddevstate
name|setraiddevstate
decl_stmt|;
name|struct
name|mly_ioctl_param_renameraiddev
name|renameraiddev
decl_stmt|;
name|struct
name|mly_ioctl_param_xlatephysdevtoraiddev
name|xlatephysdevtoraiddev
decl_stmt|;
name|struct
name|mly_ioctl_param_getgroupconfinfo
name|getgroupconfinfo
decl_stmt|;
name|struct
name|mly_ioctl_param_subsystemdata
name|subsystemdata
decl_stmt|;
name|struct
name|mly_ioctl_param_deviceoperation
name|deviceoperation
decl_stmt|;
name|struct
name|mly_ioctl_param_getevent
name|getevent
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * 19 SCSI Command Format  */
end_comment

begin_struct
struct|struct
name|mly_command_address_physical
block|{
name|u_int8_t
name|lun
decl_stmt|;
name|u_int8_t
name|target
decl_stmt|;
name|u_int8_t
name|channel
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|controller
range|:
literal|5
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
name|mly_command_address_logical
block|{
name|u_int16_t
name|logdev
decl_stmt|;
name|u_int8_t
name|res1
range|:
literal|3
decl_stmt|;
name|u_int8_t
name|controller
range|:
literal|5
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

begin_union
union|union
name|mly_command_address
block|{
name|struct
name|mly_command_address_physical
name|phys
decl_stmt|;
name|struct
name|mly_command_address_logical
name|log
decl_stmt|;
block|}
union|;
end_union

begin_struct
struct|struct
name|mly_command_generic
block|{
name|u_int16_t
name|command_id
decl_stmt|;
name|u_int8_t
name|opcode
decl_stmt|;
name|struct
name|mly_command_control
name|command_control
decl_stmt|;
name|u_int32_t
name|data_size
decl_stmt|;
name|u_int64_t
name|sense_buffer_address
decl_stmt|;
name|union
name|mly_command_address
name|addr
decl_stmt|;
name|struct
name|mly_timeout
name|timeout
decl_stmt|;
name|u_int8_t
name|maximum_sense_size
decl_stmt|;
name|u_int8_t
name|res1
index|[
literal|11
index|]
decl_stmt|;
name|union
name|mly_command_transfer
name|transfer
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
comment|/*  * 19.1 MDACMD_SCSI& MDACMD_SCSIPT  */
end_comment

begin_define
define|#
directive|define
name|MLY_CMD_SCSI_SMALL_CDB
value|10
end_define

begin_struct
struct|struct
name|mly_command_scsi_small
block|{
name|u_int16_t
name|command_id
decl_stmt|;
name|u_int8_t
name|opcode
decl_stmt|;
name|struct
name|mly_command_control
name|command_control
decl_stmt|;
name|u_int32_t
name|data_size
decl_stmt|;
name|u_int64_t
name|sense_buffer_address
decl_stmt|;
name|union
name|mly_command_address
name|addr
decl_stmt|;
name|struct
name|mly_timeout
name|timeout
decl_stmt|;
name|u_int8_t
name|maximum_sense_size
decl_stmt|;
name|u_int8_t
name|cdb_length
decl_stmt|;
name|u_int8_t
name|cdb
index|[
name|MLY_CMD_SCSI_SMALL_CDB
index|]
decl_stmt|;
name|union
name|mly_command_transfer
name|transfer
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
comment|/*  * 19.2 MDACMD_SCSILC& MDACMD_SCSILCPT  */
end_comment

begin_struct
struct|struct
name|mly_command_scsi_large
block|{
name|u_int16_t
name|command_id
decl_stmt|;
name|u_int8_t
name|opcode
decl_stmt|;
name|struct
name|mly_command_control
name|command_control
decl_stmt|;
name|u_int32_t
name|data_size
decl_stmt|;
name|u_int64_t
name|sense_buffer_address
decl_stmt|;
name|union
name|mly_command_address
name|addr
decl_stmt|;
name|struct
name|mly_timeout
name|timeout
decl_stmt|;
name|u_int8_t
name|maximum_sense_size
decl_stmt|;
name|u_int8_t
name|cdb_length
decl_stmt|;
name|u_int16_t
name|res1
decl_stmt|;
name|u_int64_t
name|cdb_physaddr
decl_stmt|;
name|union
name|mly_command_transfer
name|transfer
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
comment|/*  * 20.1 IOCTL Command Format: Internal Bus  */
end_comment

begin_struct
struct|struct
name|mly_command_ioctl
block|{
name|u_int16_t
name|command_id
decl_stmt|;
name|u_int8_t
name|opcode
decl_stmt|;
name|struct
name|mly_command_control
name|command_control
decl_stmt|;
name|u_int32_t
name|data_size
decl_stmt|;
name|u_int64_t
name|sense_buffer_address
decl_stmt|;
name|union
name|mly_command_address
name|addr
decl_stmt|;
name|struct
name|mly_timeout
name|timeout
decl_stmt|;
name|u_int8_t
name|maximum_sense_size
decl_stmt|;
name|u_int8_t
name|sub_ioctl
decl_stmt|;
name|union
name|mly_ioctl_param
name|param
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
comment|/*  * PG6: 8.2.2  */
end_comment

begin_struct
struct|struct
name|mly_command_mmbox
block|{
name|u_int32_t
name|flag
decl_stmt|;
name|u_int8_t
name|data
index|[
literal|60
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

begin_union
union|union
name|mly_command_packet
block|{
name|struct
name|mly_command_generic
name|generic
decl_stmt|;
name|struct
name|mly_command_scsi_small
name|scsi_small
decl_stmt|;
name|struct
name|mly_command_scsi_large
name|scsi_large
decl_stmt|;
name|struct
name|mly_command_ioctl
name|ioctl
decl_stmt|;
name|struct
name|mly_command_mmbox
name|mmbox
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * PG6: 5.3  */
end_comment

begin_define
define|#
directive|define
name|MLY_I960RX_COMMAND_MAILBOX
value|0x10
end_define

begin_define
define|#
directive|define
name|MLY_I960RX_STATUS_MAILBOX
value|0x18
end_define

begin_define
define|#
directive|define
name|MLY_I960RX_IDBR
value|0x20
end_define

begin_define
define|#
directive|define
name|MLY_I960RX_ODBR
value|0x2c
end_define

begin_define
define|#
directive|define
name|MLY_I960RX_ERROR_STATUS
value|0x2e
end_define

begin_define
define|#
directive|define
name|MLY_I960RX_INTERRUPT_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|MLY_I960RX_INTERRUPT_MASK
value|0x34
end_define

begin_define
define|#
directive|define
name|MLY_STRONGARM_COMMAND_MAILBOX
value|0x50
end_define

begin_define
define|#
directive|define
name|MLY_STRONGARM_STATUS_MAILBOX
value|0x58
end_define

begin_define
define|#
directive|define
name|MLY_STRONGARM_IDBR
value|0x60
end_define

begin_define
define|#
directive|define
name|MLY_STRONGARM_ODBR
value|0x61
end_define

begin_define
define|#
directive|define
name|MLY_STRONGARM_ERROR_STATUS
value|0x63
end_define

begin_define
define|#
directive|define
name|MLY_STRONGARM_INTERRUPT_STATUS
value|0x30
end_define

begin_define
define|#
directive|define
name|MLY_STRONGARM_INTERRUPT_MASK
value|0x34
end_define

begin_comment
comment|/*  * PG6: 5.4.3 Doorbell 0  */
end_comment

begin_define
define|#
directive|define
name|MLY_HM_CMDSENT
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|MLY_HM_STSACK
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|MLY_SOFT_RST
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|MLY_AM_CMDSENT
value|(1<<4)
end_define

begin_comment
comment|/*  * PG6: 5.4.4 Doorbell 1  *  * Note that the documentation claims that these bits are set when the  * status queue(s) are empty, wheras the Linux driver and experience   * suggest they are set when there is status available.  */
end_comment

begin_define
define|#
directive|define
name|MLY_HM_STSREADY
value|(1<<0)
end_define

begin_define
define|#
directive|define
name|MLY_AM_STSREADY
value|(1<<1)
end_define

begin_comment
comment|/*  * PG6: 5.4.6 Doorbell 3  */
end_comment

begin_define
define|#
directive|define
name|MLY_MSG_EMPTY
value|(1<<3)
end_define

begin_define
define|#
directive|define
name|MLY_MSG_SPINUP
value|0x08
end_define

begin_define
define|#
directive|define
name|MLY_MSG_RACE_RECOVERY_FAIL
value|0x60
end_define

begin_define
define|#
directive|define
name|MLY_MSG_RACE_IN_PROGRESS
value|0x70
end_define

begin_define
define|#
directive|define
name|MLY_MSG_RACE_ON_CRITICAL
value|0xb0
end_define

begin_define
define|#
directive|define
name|MLY_MSG_PARITY_ERROR
value|0xf0
end_define

begin_comment
comment|/*  * PG6: 5.4.8 Outbound Interrupt Mask  */
end_comment

begin_define
define|#
directive|define
name|MLY_INTERRUPT_MASK_DISABLE
value|0xff
end_define

begin_define
define|#
directive|define
name|MLY_INTERRUPT_MASK_ENABLE
value|(0xff& ~(1<<2))
end_define

begin_comment
comment|/*  * PG6: 8.2 Advanced Mailbox Scheme  *  * Note that this must be allocated on a 4k boundary, and all internal  * fields must also reside on a 4k boundary.  * We could dynamically size this structure, but the extra effort  * is probably unjustified.  Note that these buffers do not need to be  * adjacent - we just group them to simplify allocation of the bus-visible  * buffer.  *  * XXX Note that for some reason, if MLY_MMBOX_COMMANDS is> 64, the controller  * fails to respond to the command at (MLY_MMBOX_COMMANDS - 64).  It's not  * wrapping to 0 at this point (determined by experimentation).  This is not  * consistent with the Linux driver's implementation.  * Whilst it's handy to have lots of room for status returns in case we end up  * being slow getting back to completed commands, it seems unlikely that we   * would get 64 commands ahead of the controller on the submissions side, so  * the current workaround is to simply limit the command ring to 64 entries.  */
end_comment

begin_union
union|union
name|mly_status_packet
block|{
name|struct
name|mly_status
name|status
decl_stmt|;
struct|struct
block|{
name|u_int32_t
name|flag
decl_stmt|;
name|u_int8_t
name|data
index|[
literal|4
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
name|mmbox
struct|;
block|}
union|;
end_union

begin_union
union|union
name|mly_health_region
block|{
name|struct
name|mly_health_status
name|status
decl_stmt|;
name|u_int8_t
name|pad
index|[
literal|1024
index|]
decl_stmt|;
block|}
union|;
end_union

begin_define
define|#
directive|define
name|MLY_MMBOX_COMMANDS
value|64
end_define

begin_define
define|#
directive|define
name|MLY_MMBOX_STATUS
value|512
end_define

begin_struct
struct|struct
name|mly_mmbox
block|{
name|union
name|mly_command_packet
name|mmm_command
index|[
name|MLY_MMBOX_COMMANDS
index|]
decl_stmt|;
name|union
name|mly_status_packet
name|mmm_status
index|[
name|MLY_MMBOX_STATUS
index|]
decl_stmt|;
name|union
name|mly_health_region
name|mmm_health
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

