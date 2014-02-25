begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * CAM ioctl compatibility shims  *  * Copyright (c) 2013 Scott Long  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_COMPAT_H
end_define

begin_comment
comment|/* No user-servicable parts in here. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_function_decl
name|int
name|cam_compat_ioctl
parameter_list|(
name|struct
name|cdev
modifier|*
name|dev
parameter_list|,
name|u_long
name|cmd
parameter_list|,
name|caddr_t
name|addr
parameter_list|,
name|int
name|flag
parameter_list|,
name|struct
name|thread
modifier|*
name|td
parameter_list|,
name|int
function_decl|(
modifier|*
name|cbfnp
function_decl|)
parameter_list|(
name|struct
name|cdev
modifier|*
parameter_list|,
name|u_long
parameter_list|,
name|caddr_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|thread
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Version 0x16 compatibility */
end_comment

begin_define
define|#
directive|define
name|CAM_VERSION_0x16
value|0x16
end_define

begin_comment
comment|/* The size of the union ccb didn't change when going to 0x17 */
end_comment

begin_define
define|#
directive|define
name|CAMIOCOMMAND_0x16
value|_IOWR(CAM_VERSION_0x16, 2, union ccb)
end_define

begin_define
define|#
directive|define
name|CAMGETPASSTHRU_0x16
value|_IOWR(CAM_VERSION_0x16, 3, union ccb)
end_define

begin_define
define|#
directive|define
name|CAM_SCATTER_VALID_0x16
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CAM_SG_LIST_PHYS_0x16
value|0x00040000
end_define

begin_define
define|#
directive|define
name|CAM_DATA_PHYS_0x16
value|0x00200000
end_define

begin_comment
comment|/* Version 0x17 compatibility */
end_comment

begin_define
define|#
directive|define
name|CAM_VERSION_0x17
value|0x17
end_define

begin_struct
struct|struct
name|ccb_hdr_0x17
block|{
name|cam_pinfo
name|pinfo
decl_stmt|;
comment|/* Info for priority scheduling */
name|camq_entry
name|xpt_links
decl_stmt|;
comment|/* For chaining in the XPT layer */
name|camq_entry
name|sim_links
decl_stmt|;
comment|/* For chaining in the SIM layer */
name|camq_entry
name|periph_links
decl_stmt|;
comment|/* For chaining in the type driver */
name|u_int32_t
name|retry_count
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cbfcnp
function_decl|)
parameter_list|(
name|struct
name|cam_periph
modifier|*
parameter_list|,
name|union
name|ccb
modifier|*
parameter_list|)
function_decl|;
name|xpt_opcode
name|func_code
decl_stmt|;
comment|/* XPT function code */
name|u_int32_t
name|status
decl_stmt|;
comment|/* Status returned by CAM subsystem */
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
comment|/* Compiled path for this ccb */
name|path_id_t
name|path_id
decl_stmt|;
comment|/* Path ID for the request */
name|target_id_t
name|target_id
decl_stmt|;
comment|/* Target device ID */
name|u_int
name|target_lun
decl_stmt|;
comment|/* Target LUN number */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* ccb_flags */
name|ccb_ppriv_area
name|periph_priv
decl_stmt|;
name|ccb_spriv_area
name|sim_priv
decl_stmt|;
name|u_int32_t
name|timeout
decl_stmt|;
comment|/* Hard timeout value in seconds */
name|struct
name|callout_handle
name|timeout_ch
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ccb_pathinq_0x17
block|{
name|struct
name|ccb_hdr_0x17
name|ccb_h
decl_stmt|;
name|u_int8_t
name|version_num
decl_stmt|;
comment|/* Version number for the SIM/HBA */
name|u_int8_t
name|hba_inquiry
decl_stmt|;
comment|/* Mimic of INQ byte 7 for the HBA */
name|u_int8_t
name|target_sprt
decl_stmt|;
comment|/* Flags for target mode support */
name|u_int8_t
name|hba_misc
decl_stmt|;
comment|/* Misc HBA features */
name|u_int16_t
name|hba_eng_cnt
decl_stmt|;
comment|/* HBA engine count */
comment|/* Vendor Unique capabilities */
name|u_int8_t
name|vuhba_flags
index|[
name|VUHBALEN
index|]
decl_stmt|;
name|u_int32_t
name|max_target
decl_stmt|;
comment|/* Maximum supported Target */
name|u_int32_t
name|max_lun
decl_stmt|;
comment|/* Maximum supported Lun */
name|u_int32_t
name|async_flags
decl_stmt|;
comment|/* Installed Async handlers */
name|path_id_t
name|hpath_id
decl_stmt|;
comment|/* Highest Path ID in the subsystem */
name|target_id_t
name|initiator_id
decl_stmt|;
comment|/* ID of the HBA on the SCSI bus */
name|char
name|sim_vid
index|[
name|SIM_IDLEN
index|]
decl_stmt|;
comment|/* Vendor ID of the SIM */
name|char
name|hba_vid
index|[
name|HBA_IDLEN
index|]
decl_stmt|;
comment|/* Vendor ID of the HBA */
name|char
name|dev_name
index|[
name|DEV_IDLEN
index|]
decl_stmt|;
comment|/* Device name for SIM */
name|u_int32_t
name|unit_number
decl_stmt|;
comment|/* Unit number for SIM */
name|u_int32_t
name|bus_id
decl_stmt|;
comment|/* Bus ID for SIM */
name|u_int32_t
name|base_transfer_speed
decl_stmt|;
comment|/* Base bus speed in KB/sec */
name|cam_proto
name|protocol
decl_stmt|;
name|u_int
name|protocol_version
decl_stmt|;
name|cam_xport
name|transport
decl_stmt|;
name|u_int
name|transport_version
decl_stmt|;
union|union
block|{
name|struct
name|ccb_pathinq_settings_spi
name|spi
decl_stmt|;
name|struct
name|ccb_pathinq_settings_fc
name|fc
decl_stmt|;
name|struct
name|ccb_pathinq_settings_sas
name|sas
decl_stmt|;
name|char
name|ccb_pathinq_settings_opaque
index|[
name|PATHINQ_SETTINGS_SIZE
index|]
decl_stmt|;
block|}
name|xport_specific
union|;
name|u_int
name|maxio
decl_stmt|;
comment|/* Max supported I/O size, in bytes. */
name|u_int16_t
name|hba_vendor
decl_stmt|;
comment|/* HBA vendor ID */
name|u_int16_t
name|hba_device
decl_stmt|;
comment|/* HBA device ID */
name|u_int16_t
name|hba_subvendor
decl_stmt|;
comment|/* HBA subvendor ID */
name|u_int16_t
name|hba_subdevice
decl_stmt|;
comment|/* HBA subdevice ID */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CAM_0X17_LEN
value|(sizeof(union ccb) - sizeof(struct ccb_hdr) + sizeof(struct ccb_hdr_0x17))
end_define

begin_define
define|#
directive|define
name|CAM_0X17_DATA_LEN
value|(sizeof(union ccb) - sizeof(struct ccb_hdr_0x17))
end_define

begin_define
define|#
directive|define
name|CAMIOCOMMAND_0x17
value|_IOC(IOC_INOUT, CAM_VERSION_0x17, 2, CAM_0X17_LEN)
end_define

begin_define
define|#
directive|define
name|CAMGETPASSTHRU_0x17
value|_IOC(IOC_INOUT, CAM_VERSION_0x17, 3, CAM_0X17_LEN)
end_define

begin_comment
comment|/* Version 0x18 compatibility */
end_comment

begin_define
define|#
directive|define
name|CAM_VERSION_0x18
value|0x18
end_define

begin_struct
struct|struct
name|ccb_hdr_0x18
block|{
name|cam_pinfo
name|pinfo
decl_stmt|;
comment|/* Info for priority scheduling */
name|camq_entry
name|xpt_links
decl_stmt|;
comment|/* For chaining in the XPT layer */
name|camq_entry
name|sim_links
decl_stmt|;
comment|/* For chaining in the SIM layer */
name|camq_entry
name|periph_links
decl_stmt|;
comment|/* For chaining in the type driver */
name|u_int32_t
name|retry_count
decl_stmt|;
name|void
function_decl|(
modifier|*
name|cbfcnp
function_decl|)
parameter_list|(
name|struct
name|cam_periph
modifier|*
parameter_list|,
name|union
name|ccb
modifier|*
parameter_list|)
function_decl|;
name|xpt_opcode
name|func_code
decl_stmt|;
comment|/* XPT function code */
name|u_int32_t
name|status
decl_stmt|;
comment|/* Status returned by CAM subsystem */
name|struct
name|cam_path
modifier|*
name|path
decl_stmt|;
comment|/* Compiled path for this ccb */
name|path_id_t
name|path_id
decl_stmt|;
comment|/* Path ID for the request */
name|target_id_t
name|target_id
decl_stmt|;
comment|/* Target device ID */
name|u_int
name|target_lun
decl_stmt|;
comment|/* Target LUN number */
name|u_int64_t
name|ext_lun
decl_stmt|;
comment|/* 64-bit LUN, more or less */
name|u_int32_t
name|flags
decl_stmt|;
comment|/* ccb_flags */
name|u_int32_t
name|xflags
decl_stmt|;
comment|/* extended ccb_flags */
name|ccb_ppriv_area
name|periph_priv
decl_stmt|;
name|ccb_spriv_area
name|sim_priv
decl_stmt|;
name|ccb_qos_area
name|qos
decl_stmt|;
name|u_int32_t
name|timeout
decl_stmt|;
comment|/* Hard timeout value in seconds */
name|struct
name|timeval
name|softtimeout
decl_stmt|;
comment|/* Soft timeout value in sec + usec */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_EXTLUN_VALID_0x18
init|=
literal|0x00000001
block|,
comment|/* 64bit lun field is valid      */
block|}
name|ccb_xflags_0x18
typedef|;
end_typedef

begin_struct
struct|struct
name|dev_match_result_0x18
block|{
name|dev_match_type
name|type
decl_stmt|;
union|union
block|{
struct|struct
block|{
name|char
name|periph_name
index|[
name|DEV_IDLEN
index|]
decl_stmt|;
name|u_int32_t
name|unit_number
decl_stmt|;
name|path_id_t
name|path_id
decl_stmt|;
name|target_id_t
name|target_id
decl_stmt|;
name|u_int
name|target_lun
decl_stmt|;
block|}
name|periph_result
struct|;
struct|struct
block|{
name|path_id_t
name|path_id
decl_stmt|;
name|target_id_t
name|target_id
decl_stmt|;
name|u_int
name|target_lun
decl_stmt|;
name|cam_proto
name|protocol
decl_stmt|;
name|struct
name|scsi_inquiry_data
name|inq_data
decl_stmt|;
name|struct
name|ata_params
name|ident_data
decl_stmt|;
name|dev_result_flags
name|flags
decl_stmt|;
block|}
name|device_result
struct|;
name|struct
name|bus_match_result
name|bus_result
decl_stmt|;
block|}
name|result
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CAM_0X18_LEN
value|(sizeof(union ccb) - sizeof(struct ccb_hdr) + sizeof(struct ccb_hdr_0x18))
end_define

begin_define
define|#
directive|define
name|CAM_0X18_DATA_LEN
value|(sizeof(union ccb) - sizeof(struct ccb_hdr_0x18))
end_define

begin_define
define|#
directive|define
name|CAMIOCOMMAND_0x18
value|_IOC(IOC_INOUT, CAM_VERSION_0x18, 2, CAM_0X18_LEN)
end_define

begin_define
define|#
directive|define
name|CAMGETPASSTHRU_0x18
value|_IOC(IOC_INOUT, CAM_VERSION_0x18, 3, CAM_0X18_LEN)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

