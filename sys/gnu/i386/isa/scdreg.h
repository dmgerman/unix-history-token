begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Mikael Hybsch  *  * The Linux driver cdu31a has been used as a reference when writing this  * code, therefor bringing it under the GNU Public License.  The following  * conditions of redistribution therefore apply:  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * This program is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCD_H
end_ifndef

begin_define
define|#
directive|define
name|SCD_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_if
if|#
directive|if
name|__GNUC__
operator|>=
literal|2
end_if

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|char
name|bcd_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|M_msf
parameter_list|(
name|msf
parameter_list|)
value|msf[0]
end_define

begin_define
define|#
directive|define
name|S_msf
parameter_list|(
name|msf
parameter_list|)
value|msf[1]
end_define

begin_define
define|#
directive|define
name|F_msf
parameter_list|(
name|msf
parameter_list|)
value|msf[2]
end_define

begin_define
define|#
directive|define
name|IS_ATTENTION
parameter_list|(
name|port
parameter_list|)
value|((inb(port+SCD_STATUS_REG)& SCD_ATTN_BIT) != 0)
end_define

begin_define
define|#
directive|define
name|IS_BUSY
parameter_list|(
name|port
parameter_list|)
value|((inb(port+SCD_STATUS_REG)& SCD_BUSY_BIT) != 0)
end_define

begin_define
define|#
directive|define
name|IS_DATA_RDY
parameter_list|(
name|port
parameter_list|)
value|((inb(port+SCD_STATUS_REG)& SCD_DATA_RDY_BIT) != 0)
end_define

begin_define
define|#
directive|define
name|STATUS_BIT
parameter_list|(
name|port
parameter_list|,
name|bit
parameter_list|)
value|((inb(port+SCD_STATUS_REG)& (bit)) != 0)
end_define

begin_define
define|#
directive|define
name|FIFOST_BIT
parameter_list|(
name|port
parameter_list|,
name|bit
parameter_list|)
value|((inb(port+SCD_FIFOST_REG)& (bit)) != 0)
end_define

begin_define
define|#
directive|define
name|SCD_CMD_REG
value|0
end_define

begin_define
define|#
directive|define
name|SCD_PARAM_REG
value|1
end_define

begin_define
define|#
directive|define
name|SCD_WRITE_REG
value|2
end_define

begin_define
define|#
directive|define
name|SCD_CONTROL_REG
value|3
end_define

begin_define
define|#
directive|define
name|SCD_ATTN_CLR_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|SCD_RES_RDY_CLR_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|SCD_DATA_RDY_CLR_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCD_ATTN_INT_EN_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|SCD_RES_RDY_INT_EN_BIT
value|0x10
end_define

begin_define
define|#
directive|define
name|SCD_DATA_RDY_INT_EN_BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|SCD_PARAM_CLR_BIT
value|0x40
end_define

begin_define
define|#
directive|define
name|SCD_DRIVE_RESET_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|SCD_STATUS_REG
value|0
end_define

begin_define
define|#
directive|define
name|SCD_ATTN_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|SCD_RES_RDY_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|SCD_DATA_RDY_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCD_ATTN_INT_ST_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|SCD_RES_RDY_INT_ST_BIT
value|0x10
end_define

begin_define
define|#
directive|define
name|SCD_DATA_RDY_INT_ST_BIT
value|0x20
end_define

begin_define
define|#
directive|define
name|SCD_DATA_REQUEST_BIT
value|0x40
end_define

begin_define
define|#
directive|define
name|SCD_BUSY_BIT
value|0x80
end_define

begin_define
define|#
directive|define
name|SCD_RESULT_REG
value|1
end_define

begin_define
define|#
directive|define
name|SCD_READ_REG
value|2
end_define

begin_define
define|#
directive|define
name|SCD_FIFOST_REG
value|3
end_define

begin_define
define|#
directive|define
name|SCD_PARAM_WRITE_RDY_BIT
value|0x01
end_define

begin_define
define|#
directive|define
name|SCD_PARAM_REG_EMPTY_BIT
value|0x02
end_define

begin_define
define|#
directive|define
name|SCD_RES_REG_NOT_EMP_BIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCD_RES_REG_FULL_BIT
value|0x08
end_define

begin_define
define|#
directive|define
name|SCD_REQ_DRIVE_CONFIG_CMD
value|0x00
end_define

begin_define
define|#
directive|define
name|SCD_REQ_DRIVE_MODE_CMD
value|0x01
end_define

begin_define
define|#
directive|define
name|SCD_REQ_DRIVE_PARAM_CMD
value|0x02
end_define

begin_define
define|#
directive|define
name|SCD_REQ_MECH_STATUS_CMD
value|0x03
end_define

begin_define
define|#
directive|define
name|SCD_REQ_AUDIO_STATUS_CMD
value|0x04
end_define

begin_define
define|#
directive|define
name|SCD_SET_DRIVE_PARAM_CMD
value|0x10
end_define

begin_define
define|#
directive|define
name|SCD_REQ_TOC_DATA_CMD
value|0x20
end_define

begin_define
define|#
directive|define
name|SCD_REQ_SUBCODE_ADDRESS_CMD
value|0x21
end_define

begin_define
define|#
directive|define
name|SCD_REQ_UPC_EAN_CMD
value|0x22
end_define

begin_define
define|#
directive|define
name|SCD_REQ_ISRC_CMD
value|0x23
end_define

begin_define
define|#
directive|define
name|SCD_REQ_TOC_DATA_SPEC_CMD
value|0x24
end_define

begin_define
define|#
directive|define
name|SCD_READ_TOC_CMD
value|0x30
end_define

begin_define
define|#
directive|define
name|SCD_SEEK_CMD
value|0x31
end_define

begin_define
define|#
directive|define
name|SCD_READ_CMD
value|0x32
end_define

begin_define
define|#
directive|define
name|SCD_READ_BLKERR_STAT_CMD
value|0x34
end_define

begin_define
define|#
directive|define
name|SCD_ABORT_CMD
value|0x35
end_define

begin_define
define|#
directive|define
name|SCD_READ_TOC_SPEC_CMD
value|0x36
end_define

begin_define
define|#
directive|define
name|SCD_AUDIO_PLAYBACK_CMD
value|0x40
end_define

begin_define
define|#
directive|define
name|SCD_AUDIO_STOP_CMD
value|0x41
end_define

begin_define
define|#
directive|define
name|SCD_AUDIO_SCAN_CMD
value|0x42
end_define

begin_define
define|#
directive|define
name|SCD_EJECT_CMD
value|0x50
end_define

begin_define
define|#
directive|define
name|SCD_SPIN_UP_CMD
value|0x51
end_define

begin_define
define|#
directive|define
name|SCD_SPIN_DOWN_CMD
value|0x52
end_define

begin_define
define|#
directive|define
name|SCD_SD_DECODE_PARAM
value|0x00
end_define

begin_define
define|#
directive|define
name|SCD_SD_INTERFACE_PARAM
value|0x01
end_define

begin_define
define|#
directive|define
name|SCD_SD_BUFFERING_PARAM
value|0x02
end_define

begin_define
define|#
directive|define
name|SCD_SD_AUDIO_PARAM
value|0x03
end_define

begin_define
define|#
directive|define
name|SCD_SD_AUDIO_VOLUME
value|0x04
end_define

begin_define
define|#
directive|define
name|SCD_SD_MECH_CONTROL
value|0x05
end_define

begin_define
define|#
directive|define
name|SCD_SD_AUTO_SPIN_DOWN_TIME
value|0x06
end_define

begin_define
define|#
directive|define
name|SONY_HWC_GET_LOAD_MECH
parameter_list|(
name|c
parameter_list|)
value|(c.hw_config[0]& 0x03)
end_define

begin_define
define|#
directive|define
name|SONY_HWC_EJECT
parameter_list|(
name|c
parameter_list|)
value|(c.hw_config[0]& 0x04)
end_define

begin_define
define|#
directive|define
name|SONY_HWC_LED_SUPPORT
parameter_list|(
name|c
parameter_list|)
value|(c.hw_config[0]& 0x08)
end_define

begin_define
define|#
directive|define
name|SONY_HWC_DOUBLE_SPEED
parameter_list|(
name|c
parameter_list|)
value|(c.hw_config[0]& 0x10)
end_define

begin_define
define|#
directive|define
name|SONY_HWC_GET_BUF_MEM_SIZE
parameter_list|(
name|c
parameter_list|)
value|((c.hw_config[0]& 0xc0)>> 6)
end_define

begin_define
define|#
directive|define
name|SONY_HWC_AUDIO_PLAYBACK
parameter_list|(
name|c
parameter_list|)
value|(c.hw_config[1]& 0x01)
end_define

begin_define
define|#
directive|define
name|SONY_HWC_ELECTRIC_VOLUME
parameter_list|(
name|c
parameter_list|)
value|(c.hw_config[1]& 0x02)
end_define

begin_define
define|#
directive|define
name|SONY_HWC_ELECTRIC_VOLUME_CTL
parameter_list|(
name|c
parameter_list|)
value|(c.hw_config[1]& 0x04)
end_define

begin_define
define|#
directive|define
name|SONY_HWC_CADDY_LOAD_MECH
value|0x00
end_define

begin_define
define|#
directive|define
name|SONY_HWC_TRAY_LOAD_MECH
value|0x01
end_define

begin_define
define|#
directive|define
name|SONY_HWC_POPUP_LOAD_MECH
value|0x02
end_define

begin_define
define|#
directive|define
name|SONY_HWC_UNKWN_LOAD_MECH
value|0x03
end_define

begin_define
define|#
directive|define
name|SONY_HWC_8KB_BUFFER
value|0x00
end_define

begin_define
define|#
directive|define
name|SONY_HWC_32KB_BUFFER
value|0x01
end_define

begin_define
define|#
directive|define
name|SONY_HWC_64KB_BUFFER
value|0x02
end_define

begin_define
define|#
directive|define
name|SONY_HWC_UNKWN_BUFFER
value|0x03
end_define

begin_comment
comment|/*  * The following are errors returned from the drive.  */
end_comment

begin_define
define|#
directive|define
name|SONY_ILL_CMD_ERR
value|0x10
end_define

begin_define
define|#
directive|define
name|SONY_ILL_PARAM_ERR
value|0x11
end_define

begin_define
define|#
directive|define
name|SONY_NOT_LOAD_ERR
value|0x20
end_define

begin_define
define|#
directive|define
name|SONY_NO_DISK_ERR
value|0x21
end_define

begin_define
define|#
directive|define
name|SONY_NOT_SPIN_ERR
value|0x22
end_define

begin_define
define|#
directive|define
name|SONY_SPIN_ERR
value|0x23
end_define

begin_define
define|#
directive|define
name|SONY_SPINDLE_SERVO_ERR
value|0x25
end_define

begin_define
define|#
directive|define
name|SONY_FOCUS_SERVO_ERR
value|0x26
end_define

begin_define
define|#
directive|define
name|SONY_EJECT_MECH_ERR
value|0x29
end_define

begin_define
define|#
directive|define
name|SONY_AUDIO_PLAYING_ERR
value|0x2a
end_define

begin_define
define|#
directive|define
name|SONY_EMERGENCY_EJECT_ERR
value|0x2c
end_define

begin_define
define|#
directive|define
name|SONY_FOCUS_ERR
value|0x30
end_define

begin_define
define|#
directive|define
name|SONY_FRAME_SYNC_ERR
value|0x31
end_define

begin_define
define|#
directive|define
name|SONY_SUBCODE_ADDR_ERR
value|0x32
end_define

begin_define
define|#
directive|define
name|SONY_BLOCK_SYNC_ERR
value|0x33
end_define

begin_define
define|#
directive|define
name|SONY_HEADER_ADDR_ERR
value|0x34
end_define

begin_define
define|#
directive|define
name|SONY_ILL_TRACK_R_ERR
value|0x40
end_define

begin_define
define|#
directive|define
name|SONY_MODE_0_R_ERR
value|0x41
end_define

begin_define
define|#
directive|define
name|SONY_ILL_MODE_R_ERR
value|0x42
end_define

begin_define
define|#
directive|define
name|SONY_ILL_BLOCK_SIZE_R_ERR
value|0x43
end_define

begin_define
define|#
directive|define
name|SONY_MODE_R_ERR
value|0x44
end_define

begin_define
define|#
directive|define
name|SONY_FORM_R_ERR
value|0x45
end_define

begin_define
define|#
directive|define
name|SONY_LEAD_OUT_R_ERR
value|0x46
end_define

begin_define
define|#
directive|define
name|SONY_BUFFER_OVERRUN_R_ERR
value|0x47
end_define

begin_define
define|#
directive|define
name|SONY_UNREC_CIRC_ERR
value|0x53
end_define

begin_define
define|#
directive|define
name|SONY_UNREC_LECC_ERR
value|0x57
end_define

begin_define
define|#
directive|define
name|SONY_NO_TOC_ERR
value|0x60
end_define

begin_define
define|#
directive|define
name|SONY_SUBCODE_DATA_NVAL_ERR
value|0x61
end_define

begin_define
define|#
directive|define
name|SONY_FOCUS_ON_TOC_READ_ERR
value|0x63
end_define

begin_define
define|#
directive|define
name|SONY_FRAME_SYNC_ON_TOC_READ_ERR
value|0x64
end_define

begin_define
define|#
directive|define
name|SONY_TOC_DATA_ERR
value|0x65
end_define

begin_define
define|#
directive|define
name|SONY_HW_FAILURE_ERR
value|0x70
end_define

begin_define
define|#
directive|define
name|SONY_LEAD_IN_A_ERR
value|0x91
end_define

begin_define
define|#
directive|define
name|SONY_LEAD_OUT_A_ERR
value|0x92
end_define

begin_define
define|#
directive|define
name|SONY_DATA_TRACK_A_ERR
value|0x93
end_define

begin_define
define|#
directive|define
name|SONY_NO_CIRC_ERR_BLK_STAT
value|0x50
end_define

begin_define
define|#
directive|define
name|SONY_NO_LECC_ERR_BLK_STAT
value|0x54
end_define

begin_define
define|#
directive|define
name|SONY_RECOV_LECC_ERR_BLK_STAT
value|0x55
end_define

begin_define
define|#
directive|define
name|SONY_NO_ERR_DETECTION_STAT
value|0x59
end_define

begin_define
define|#
directive|define
name|SONY_EMER_EJECT_ATTN
value|0x2c
end_define

begin_define
define|#
directive|define
name|SONY_HW_FAILURE_ATTN
value|0x70
end_define

begin_define
define|#
directive|define
name|SONY_MECH_LOADED_ATTN
value|0x80
end_define

begin_define
define|#
directive|define
name|SONY_EJECT_PUSHED_ATTN
value|0x81
end_define

begin_define
define|#
directive|define
name|SONY_AUDIO_PLAY_DONE_ATTN
value|0x90
end_define

begin_define
define|#
directive|define
name|SONY_LEAD_IN_ERR_ATTN
value|0x91
end_define

begin_define
define|#
directive|define
name|SONY_LEAD_OUT_ERR_ATTN
value|0x92
end_define

begin_define
define|#
directive|define
name|SONY_DATA_TRACK_ERR_ATTN
value|0x93
end_define

begin_define
define|#
directive|define
name|SONY_AUDIO_PLAYBACK_ERR_ATTN
value|0x94
end_define

begin_define
define|#
directive|define
name|SONY_SPIN_UP_COMPLETE_ATTN
value|0x24
end_define

begin_define
define|#
directive|define
name|SONY_SPINDLE_SERVO_ERR_ATTN
value|0x25
end_define

begin_define
define|#
directive|define
name|SONY_FOCUS_SERVO_ERR_ATTN
value|0x26
end_define

begin_define
define|#
directive|define
name|SONY_TOC_READ_DONE_ATTN
value|0x62
end_define

begin_define
define|#
directive|define
name|SONY_FOCUS_ON_TOC_READ_ERR_ATTN
value|0x63
end_define

begin_define
define|#
directive|define
name|SONY_SYNC_ON_TOC_READ_ERR_ATTN
value|0x65
end_define

begin_define
define|#
directive|define
name|SONY_SPIN_DOWN_COMPLETE_ATTN
value|0x27
end_define

begin_define
define|#
directive|define
name|SONY_EJECT_COMPLETE_ATTN
value|0x28
end_define

begin_define
define|#
directive|define
name|SONY_EJECT_MECH_ERR_ATTN
value|0x29
end_define

begin_struct
struct|struct
name|s_sony_drive_config
block|{
name|unsigned
name|char
name|exec_status
index|[
literal|2
index|]
decl_stmt|;
name|char
name|vendor_id
index|[
literal|8
index|]
decl_stmt|;
name|char
name|product_id
index|[
literal|16
index|]
decl_stmt|;
name|char
name|product_rev_level
index|[
literal|8
index|]
decl_stmt|;
name|unsigned
name|char
name|hw_config
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s_sony_subcode
block|{
name|unsigned
name|char
name|exec_status
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|address
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|control
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|track_num
decl_stmt|;
name|unsigned
name|char
name|index_num
decl_stmt|;
name|unsigned
name|char
name|rel_msf
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|reserved1
decl_stmt|;
name|unsigned
name|char
name|abs_msf
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_TRACKS
value|100
end_define

begin_struct
struct|struct
name|s_sony_session_toc
block|{
name|unsigned
name|char
name|exec_status
index|[
literal|2
index|]
decl_stmt|;
name|unsigned
name|char
name|session_number
decl_stmt|;
name|unsigned
name|char
name|address0
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|control0
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|point0
decl_stmt|;
name|unsigned
name|char
name|first_track_num
decl_stmt|;
name|unsigned
name|char
name|disk_type
decl_stmt|;
name|unsigned
name|char
name|dummy0
decl_stmt|;
name|unsigned
name|char
name|address1
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|control1
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|point1
decl_stmt|;
name|unsigned
name|char
name|last_track_num
decl_stmt|;
name|unsigned
name|char
name|dummy1
decl_stmt|;
name|unsigned
name|char
name|dummy2
decl_stmt|;
name|unsigned
name|char
name|address2
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|control2
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|point2
decl_stmt|;
name|unsigned
name|char
name|lead_out_start_msf
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|addressb0
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|controlb0
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|pointb0
decl_stmt|;
name|unsigned
name|char
name|next_poss_prog_area_msf
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|num_mode_5_pointers
decl_stmt|;
name|unsigned
name|char
name|max_start_outer_leadout_msf
index|[
literal|3
index|]
decl_stmt|;
name|unsigned
name|char
name|addressb1
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|controlb1
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|pointb1
decl_stmt|;
name|unsigned
name|char
name|dummyb0_1
index|[
literal|4
index|]
decl_stmt|;
name|unsigned
name|char
name|num_skip_interval_pointers
decl_stmt|;
name|unsigned
name|char
name|num_skip_track_assignments
decl_stmt|;
name|unsigned
name|char
name|dummyb0_2
decl_stmt|;
name|unsigned
name|char
name|addressb2
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|controlb2
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|pointb2
decl_stmt|;
name|unsigned
name|char
name|tracksb2
index|[
literal|7
index|]
decl_stmt|;
name|unsigned
name|char
name|addressb3
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|controlb3
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|pointb3
decl_stmt|;
name|unsigned
name|char
name|tracksb3
index|[
literal|7
index|]
decl_stmt|;
name|unsigned
name|char
name|addressb4
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|controlb4
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|pointb4
decl_stmt|;
name|unsigned
name|char
name|tracksb4
index|[
literal|7
index|]
decl_stmt|;
name|unsigned
name|char
name|addressc0
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|controlc0
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|pointc0
decl_stmt|;
name|unsigned
name|char
name|dummyc0
index|[
literal|7
index|]
decl_stmt|;
struct|struct
name|s_sony_tracklist
block|{
name|unsigned
name|char
name|address
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|control
range|:
literal|4
decl_stmt|;
name|unsigned
name|char
name|track
decl_stmt|;
name|unsigned
name|char
name|track_start_msf
index|[
literal|3
index|]
decl_stmt|;
block|}
name|tracks
index|[
name|MAX_TRACKS
index|]
struct|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SCD_H */
end_comment

end_unit

