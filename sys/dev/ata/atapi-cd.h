begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998,1999,2000,2001,2002 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* CDROM Table Of Contents */
end_comment

begin_define
define|#
directive|define
name|MAXTRK
value|99
end_define

begin_struct
struct|struct
name|toc
block|{
name|struct
name|ioc_toc_header
name|hdr
decl_stmt|;
name|struct
name|cd_toc_entry
name|tab
index|[
name|MAXTRK
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* CDROM Audio Control Parameters Page */
end_comment

begin_struct
struct|struct
name|audiopage
block|{
comment|/* mode page data header */
name|u_int16_t
name|data_length
decl_stmt|;
name|u_int8_t
name|medium_type
decl_stmt|;
name|u_int8_t
name|dev_spec
decl_stmt|;
name|u_int8_t
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|u_int16_t
name|blk_desc_len
decl_stmt|;
comment|/* audio control page */
name|u_int8_t
name|page_code
decl_stmt|;
define|#
directive|define
name|ATAPI_CDROM_AUDIO_PAGE
value|0x0e
define|#
directive|define
name|ATAPI_CDROM_AUDIO_PAGE_MASK
value|0x4e
name|u_int8_t
name|param_len
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
define|#
directive|define
name|CD_PA_SOTC
value|0x02
define|#
directive|define
name|CD_PA_IMMED
value|0x04
name|u_int8_t
name|reserved3
decl_stmt|;
name|u_int8_t
name|reserved4
decl_stmt|;
name|u_int8_t
name|reserved5
decl_stmt|;
name|u_int16_t
name|lb_per_sec
decl_stmt|;
struct|struct
name|port_control
block|{
name|u_int8_t
name|channels
range|:
literal|4
decl_stmt|;
define|#
directive|define
name|CHANNEL_0
value|1
define|#
directive|define
name|CHANNEL_1
value|2
define|#
directive|define
name|CHANNEL_2
value|4
define|#
directive|define
name|CHANNEL_3
value|8
name|u_int8_t
name|volume
decl_stmt|;
block|}
name|port
index|[
literal|4
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* CDROM Capabilities and Mechanical Status Page */
end_comment

begin_struct
struct|struct
name|cappage
block|{
comment|/* mode page data header */
name|u_int16_t
name|data_length
decl_stmt|;
name|u_int8_t
name|medium_type
decl_stmt|;
define|#
directive|define
name|MST_TYPE_MASK_LOW
value|0x0f
define|#
directive|define
name|MST_FMT_NONE
value|0x00
define|#
directive|define
name|MST_DATA_120
value|0x01
define|#
directive|define
name|MST_AUDIO_120
value|0x02
define|#
directive|define
name|MST_COMB_120
value|0x03
define|#
directive|define
name|MST_PHOTO_120
value|0x04
define|#
directive|define
name|MST_DATA_80
value|0x05
define|#
directive|define
name|MST_AUDIO_80
value|0x06
define|#
directive|define
name|MST_COMB_80
value|0x07
define|#
directive|define
name|MST_PHOTO_80
value|0x08
define|#
directive|define
name|MST_TYPE_MASK_HIGH
value|0x70
define|#
directive|define
name|MST_CDROM
value|0x00
define|#
directive|define
name|MST_CDR
value|0x10
define|#
directive|define
name|MST_CDRW
value|0x20
define|#
directive|define
name|MST_NO_DISC
value|0x70
define|#
directive|define
name|MST_DOOR_OPEN
value|0x71
define|#
directive|define
name|MST_FMT_ERROR
value|0x72
name|u_int8_t
name|dev_spec
decl_stmt|;
name|u_int8_t
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|u_int16_t
name|blk_desc_len
decl_stmt|;
comment|/* capabilities page */
name|u_int8_t
name|page_code
decl_stmt|;
define|#
directive|define
name|ATAPI_CDROM_CAP_PAGE
value|0x2a
name|u_int8_t
name|param_len
decl_stmt|;
name|u_int8_t
name|read_cdr
range|:
literal|1
decl_stmt|;
comment|/* supports CD-R read */
name|u_int8_t
name|read_cdrw
range|:
literal|1
decl_stmt|;
comment|/* supports CD-RW read */
name|u_int8_t
name|read_packet
range|:
literal|1
decl_stmt|;
comment|/* supports reading packet tracks */
name|u_int8_t
name|read_dvdrom
range|:
literal|1
decl_stmt|;
comment|/* supports DVD-ROM read */
name|u_int8_t
name|read_dvdr
range|:
literal|1
decl_stmt|;
comment|/* supports DVD-R read */
name|u_int8_t
name|read_dvdram
range|:
literal|1
decl_stmt|;
comment|/* supports DVD-RAM read */
name|u_int8_t
name|reserved2_67
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|write_cdr
range|:
literal|1
decl_stmt|;
comment|/* supports CD-R write */
name|u_int8_t
name|write_cdrw
range|:
literal|1
decl_stmt|;
comment|/* supports CD-RW write */
name|u_int8_t
name|test_write
range|:
literal|1
decl_stmt|;
comment|/* supports test writing */
name|u_int8_t
name|reserved3_3
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|write_dvdr
range|:
literal|1
decl_stmt|;
comment|/* supports DVD-R write */
name|u_int8_t
name|write_dvdram
range|:
literal|1
decl_stmt|;
comment|/* supports DVD-RAM write */
name|u_int8_t
name|reserved3_67
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|audio_play
range|:
literal|1
decl_stmt|;
comment|/* audio play supported */
name|u_int8_t
name|composite
range|:
literal|1
decl_stmt|;
comment|/* composite audio/video supported */
name|u_int8_t
name|dport1
range|:
literal|1
decl_stmt|;
comment|/* digital audio on port 1 */
name|u_int8_t
name|dport2
range|:
literal|1
decl_stmt|;
comment|/* digital audio on port 2 */
name|u_int8_t
name|mode2_form1
range|:
literal|1
decl_stmt|;
comment|/* mode 2 form 1 (XA) read */
name|u_int8_t
name|mode2_form2
range|:
literal|1
decl_stmt|;
comment|/* mode 2 form 2 format */
name|u_int8_t
name|multisession
range|:
literal|1
decl_stmt|;
comment|/* multi-session photo-CD */
name|u_int8_t
name|burnproof
range|:
literal|1
decl_stmt|;
comment|/* supports burnproof */
name|u_int8_t
name|cd_da
range|:
literal|1
decl_stmt|;
comment|/* audio-CD read supported */
name|u_int8_t
name|cd_da_stream
range|:
literal|1
decl_stmt|;
comment|/* CD-DA streaming */
name|u_int8_t
name|rw
range|:
literal|1
decl_stmt|;
comment|/* combined R-W subchannels */
name|u_int8_t
name|rw_corr
range|:
literal|1
decl_stmt|;
comment|/* R-W subchannel data corrected */
name|u_int8_t
name|c2
range|:
literal|1
decl_stmt|;
comment|/* C2 error pointers supported */
name|u_int8_t
name|isrc
range|:
literal|1
decl_stmt|;
comment|/* can return the ISRC info */
name|u_int8_t
name|upc
range|:
literal|1
decl_stmt|;
comment|/* can return the catalog number UPC */
name|u_int8_t
label|:
literal|1
expr_stmt|;
name|u_int8_t
name|lock
range|:
literal|1
decl_stmt|;
comment|/* can be locked */
name|u_int8_t
name|locked
range|:
literal|1
decl_stmt|;
comment|/* current lock state */
name|u_int8_t
name|prevent
range|:
literal|1
decl_stmt|;
comment|/* prevent jumper installed */
name|u_int8_t
name|eject
range|:
literal|1
decl_stmt|;
comment|/* can eject */
name|u_int8_t
label|:
literal|1
expr_stmt|;
name|u_int8_t
name|mech
range|:
literal|3
decl_stmt|;
comment|/* loading mechanism type */
define|#
directive|define
name|MST_MECH_CADDY
value|0
define|#
directive|define
name|MST_MECH_TRAY
value|1
define|#
directive|define
name|MST_MECH_POPUP
value|2
define|#
directive|define
name|MST_MECH_CHANGER
value|4
define|#
directive|define
name|MST_MECH_CARTRIDGE
value|5
name|u_int8_t
name|sep_vol
range|:
literal|1
decl_stmt|;
comment|/* independent volume of channels */
name|u_int8_t
name|sep_mute
range|:
literal|1
decl_stmt|;
comment|/* independent mute of channels */
name|u_int8_t
label|:
literal|6
expr_stmt|;
name|u_int16_t
name|max_read_speed
decl_stmt|;
comment|/* max raw data rate in bytes/1000 */
name|u_int16_t
name|max_vol_levels
decl_stmt|;
comment|/* number of discrete volume levels */
name|u_int16_t
name|buf_size
decl_stmt|;
comment|/* internal buffer size in bytes/1024 */
name|u_int16_t
name|cur_read_speed
decl_stmt|;
comment|/* current data rate in bytes/1000  */
name|u_int8_t
name|reserved3
decl_stmt|;
name|u_int8_t
name|bckf
range|:
literal|1
decl_stmt|;
comment|/* data valid on failing edge of BCK */
name|u_int8_t
name|rch
range|:
literal|1
decl_stmt|;
comment|/* high LRCK indicates left channel */
name|u_int8_t
name|lsbf
range|:
literal|1
decl_stmt|;
comment|/* set if LSB first */
name|u_int8_t
name|dlen
range|:
literal|2
decl_stmt|;
define|#
directive|define
name|MST_DLEN_32
value|0
define|#
directive|define
name|MST_DLEN_16
value|1
define|#
directive|define
name|MST_DLEN_24
value|2
define|#
directive|define
name|MST_DLEN_24_I2S
value|3
name|u_int8_t
label|:
literal|3
expr_stmt|;
name|u_int16_t
name|max_write_speed
decl_stmt|;
comment|/* max raw data rate in bytes/1000 */
name|u_int16_t
name|cur_write_speed
decl_stmt|;
comment|/* current data rate in bytes/1000  */
name|u_int16_t
name|copy_protect_rev
decl_stmt|;
name|u_int16_t
name|reserved4
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* CDROM Changer mechanism status structure */
end_comment

begin_struct
struct|struct
name|changer
block|{
name|u_int8_t
name|current_slot
range|:
literal|5
decl_stmt|;
comment|/* active changer slot */
name|u_int8_t
name|mech_state
range|:
literal|2
decl_stmt|;
comment|/* current changer state */
define|#
directive|define
name|CH_READY
value|0
define|#
directive|define
name|CH_LOADING
value|1
define|#
directive|define
name|CH_UNLOADING
value|2
define|#
directive|define
name|CH_INITIALIZING
value|3
name|u_int8_t
name|fault
range|:
literal|1
decl_stmt|;
comment|/* fault in last operation */
name|u_int8_t
name|reserved0
range|:
literal|5
decl_stmt|;
name|u_int8_t
name|cd_state
range|:
literal|3
decl_stmt|;
comment|/* current mechanism state */
define|#
directive|define
name|CD_IDLE
value|0
define|#
directive|define
name|CD_AUDIO_ACTIVE
value|1
define|#
directive|define
name|CD_AUDIO_SCAN
value|2
define|#
directive|define
name|CD_HOST_ACTIVE
value|3
define|#
directive|define
name|CD_NO_STATE
value|7
name|u_int8_t
name|current_lba
index|[
literal|3
index|]
decl_stmt|;
comment|/* current LBA */
name|u_int8_t
name|slots
decl_stmt|;
comment|/* number of available slots */
name|u_int16_t
name|table_length
decl_stmt|;
comment|/* slot table length */
struct|struct
block|{
name|u_int8_t
name|changed
range|:
literal|1
decl_stmt|;
comment|/* media has changed in this slot */
name|u_int8_t
name|unused
range|:
literal|6
decl_stmt|;
name|u_int8_t
name|present
range|:
literal|1
decl_stmt|;
comment|/* slot has a CD present */
name|u_int8_t
name|reserved0
decl_stmt|;
name|u_int8_t
name|reserved1
decl_stmt|;
name|u_int8_t
name|reserved2
decl_stmt|;
block|}
name|slot
index|[
literal|32
index|]
struct|;
block|}
struct|;
end_struct

begin_comment
comment|/* CDROM Write Parameters Mode Page (Burners ONLY) */
end_comment

begin_struct
struct|struct
name|write_param
block|{
comment|/* mode page data header */
name|u_int16_t
name|data_length
decl_stmt|;
name|u_int8_t
name|medium_type
decl_stmt|;
name|u_int8_t
name|dev_spec
decl_stmt|;
name|u_int8_t
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|u_int16_t
name|blk_desc_len
decl_stmt|;
comment|/* write parameters page */
name|u_int8_t
name|page_code
decl_stmt|;
define|#
directive|define
name|ATAPI_CDROM_WRITE_PARAMETERS_PAGE
value|0x05
name|u_int8_t
name|page_length
decl_stmt|;
comment|/* 0x32 */
name|u_int8_t
name|write_type
range|:
literal|4
decl_stmt|;
comment|/* write stream type */
define|#
directive|define
name|CDR_WTYPE_PACKET
value|0x00
define|#
directive|define
name|CDR_WTYPE_TRACK
value|0x01
define|#
directive|define
name|CDR_WTYPE_SESSION
value|0x02
define|#
directive|define
name|CDR_WTYPE_RAW
value|0x03
name|u_int8_t
name|test_write
range|:
literal|1
decl_stmt|;
comment|/* test write enable */
name|u_int8_t
name|reserved2_5
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|burnproof
range|:
literal|1
decl_stmt|;
comment|/* BurnProof enable */
name|u_int8_t
name|reserved2_7
range|:
literal|1
decl_stmt|;
name|u_int8_t
name|track_mode
range|:
literal|4
decl_stmt|;
comment|/* track mode */
define|#
directive|define
name|CDR_TMODE_AUDIO
value|0x00
define|#
directive|define
name|CDR_TMODE_AUDIO_PREEMP
value|0x01
define|#
directive|define
name|CDR_TMODE_ALLOW_COPY
value|0x02
define|#
directive|define
name|CDR_TMODE_DATA
value|0x04
define|#
directive|define
name|CDR_TMODE_QUAD_AUDIO
value|0x08
name|u_int8_t
name|copy
range|:
literal|1
decl_stmt|;
comment|/* generation stamp */
name|u_int8_t
name|fp
range|:
literal|1
decl_stmt|;
comment|/* fixed packet type */
name|u_int8_t
name|session_type
range|:
literal|2
decl_stmt|;
comment|/* session type */
define|#
directive|define
name|CDR_SESS_NONE
value|0x00
define|#
directive|define
name|CDR_SESS_FINAL
value|0x01
define|#
directive|define
name|CDR_SESS_RESERVED
value|0x02
define|#
directive|define
name|CDR_SESS_MULTI
value|0x03
name|u_int8_t
name|datablock_type
range|:
literal|4
decl_stmt|;
comment|/* data type code (see cdrio.h) */
name|u_int8_t
name|reserved4_4567
range|:
literal|4
decl_stmt|;
name|u_int8_t
name|reserved5
decl_stmt|;
name|u_int8_t
name|reserved6
decl_stmt|;
name|u_int8_t
name|host_app_code
range|:
literal|6
decl_stmt|;
comment|/* host application code */
name|u_int8_t
name|reserved7_67
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|session_format
decl_stmt|;
comment|/* session format */
define|#
directive|define
name|CDR_SESS_CDROM
value|0x00
define|#
directive|define
name|CDR_SESS_CDI
value|0x10
define|#
directive|define
name|CDR_SESS_CDROM_XA
value|0x20
name|u_int8_t
name|reserved9
decl_stmt|;
name|u_int32_t
name|packet_size
decl_stmt|;
comment|/* packet size in bytes */
name|u_int16_t
name|audio_pause_length
decl_stmt|;
comment|/* audio pause length in secs */
name|u_int8_t
name|media_catalog_number
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|isr_code
index|[
literal|16
index|]
decl_stmt|;
name|u_int8_t
name|sub_hdr_byte0
decl_stmt|;
name|u_int8_t
name|sub_hdr_byte1
decl_stmt|;
name|u_int8_t
name|sub_hdr_byte2
decl_stmt|;
name|u_int8_t
name|sub_hdr_byte3
decl_stmt|;
name|u_int8_t
name|vendor_specific_byte0
decl_stmt|;
name|u_int8_t
name|vendor_specific_byte1
decl_stmt|;
name|u_int8_t
name|vendor_specific_byte2
decl_stmt|;
name|u_int8_t
name|vendor_specific_byte3
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
comment|/* CDROM Read Track Information structure */
end_comment

begin_struct
struct|struct
name|acd_track_info
block|{
name|u_int16_t
name|data_length
decl_stmt|;
name|u_int8_t
name|track_number
decl_stmt|;
comment|/* current track number */
name|u_int8_t
name|session_number
decl_stmt|;
comment|/* current session number */
name|u_int8_t
name|reserved4
decl_stmt|;
name|u_int8_t
name|track_mode
range|:
literal|4
decl_stmt|;
comment|/* mode of this track */
name|u_int8_t
name|copy
range|:
literal|1
decl_stmt|;
comment|/* generation stamp */
name|u_int8_t
name|damage
range|:
literal|1
decl_stmt|;
comment|/* damaged track */
name|u_int8_t
name|reserved5_67
range|:
literal|2
decl_stmt|;
name|u_int8_t
name|data_mode
range|:
literal|4
decl_stmt|;
comment|/* data mode of this disc */
name|u_int8_t
name|fp
range|:
literal|1
decl_stmt|;
comment|/* fixed packet */
name|u_int8_t
name|packet
range|:
literal|1
decl_stmt|;
comment|/* packet track */
name|u_int8_t
name|blank
range|:
literal|1
decl_stmt|;
comment|/* blank (empty) track */
name|u_int8_t
name|rt
range|:
literal|1
decl_stmt|;
comment|/* reserved track */
name|u_int8_t
name|nwa_valid
range|:
literal|1
decl_stmt|;
comment|/* next_writeable_addr field valid */
name|u_int8_t
name|reserved7_17
range|:
literal|7
decl_stmt|;
name|u_int
name|track_start_addr
decl_stmt|;
comment|/* start of this track */
name|u_int
name|next_writeable_addr
decl_stmt|;
comment|/* next writeable addr on this disc */
name|u_int
name|free_blocks
decl_stmt|;
comment|/* free block on this disc */
name|u_int
name|fixed_packet_size
decl_stmt|;
comment|/* size of packets on this track */
name|u_int
name|track_length
decl_stmt|;
comment|/* length of this track */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure describing an ATAPI CDROM device */
end_comment

begin_struct
struct|struct
name|acd_softc
block|{
name|struct
name|atapi_softc
modifier|*
name|atp
decl_stmt|;
comment|/* controller structure */
name|int
name|lun
decl_stmt|;
comment|/* logical device unit */
name|int
name|flags
decl_stmt|;
comment|/* device state flags */
define|#
directive|define
name|F_LOCKED
value|0x0001
comment|/* this unit is locked */
name|struct
name|buf_queue_head
name|bio_queue
decl_stmt|;
comment|/* Queue of i/o requests */
name|struct
name|toc
name|toc
decl_stmt|;
comment|/* table of disc contents */
name|struct
name|audiopage
name|au
decl_stmt|;
comment|/* audio page info */
name|struct
name|audiopage
name|aumask
decl_stmt|;
comment|/* audio page mask */
name|struct
name|cappage
name|cap
decl_stmt|;
comment|/* capabilities page info */
struct|struct
block|{
comment|/* subchannel info */
name|u_int8_t
name|void0
decl_stmt|;
name|u_int8_t
name|audio_status
decl_stmt|;
name|u_int16_t
name|data_length
decl_stmt|;
name|u_int8_t
name|data_format
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
name|u_int8_t
name|track
decl_stmt|;
name|u_int8_t
name|indx
decl_stmt|;
name|u_int32_t
name|abslba
decl_stmt|;
name|u_int32_t
name|rellba
decl_stmt|;
block|}
name|subchan
struct|;
name|struct
name|changer
modifier|*
name|changer_info
decl_stmt|;
comment|/* changer info */
name|struct
name|acd_softc
modifier|*
modifier|*
name|driver
decl_stmt|;
comment|/* softc's of changer slots */
name|int
name|slot
decl_stmt|;
comment|/* this instance slot number */
name|time_t
name|timestamp
decl_stmt|;
comment|/* this instance timestamp */
name|int
name|disk_size
decl_stmt|;
comment|/* size of current media */
name|int
name|block_size
decl_stmt|;
comment|/* blocksize currently used */
name|struct
name|disklabel
name|disklabel
decl_stmt|;
comment|/* fake disk label */
name|struct
name|devstat
modifier|*
name|stats
decl_stmt|;
comment|/* devstat entry */
name|dev_t
name|dev1
decl_stmt|,
name|dev2
decl_stmt|;
comment|/* device place holders */
block|}
struct|;
end_struct

end_unit

