begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998, 1999 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * CDROM Table Of Contents  */
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
comment|/*  * CDROM Audio Control Parameters Page  */
end_comment

begin_struct
struct|struct
name|audiopage
block|{
comment|/* Mode Page data header */
name|u_short
name|data_length
decl_stmt|;
name|u_char
name|medium_type
decl_stmt|;
name|u_char
name|dev_spec
decl_stmt|;
name|u_char
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|blk_desc_len
decl_stmt|;
comment|/* Audio control page */
name|u_char
name|page_code
decl_stmt|;
define|#
directive|define
name|CDROM_AUDIO_PAGE
value|0x0e
define|#
directive|define
name|CDROM_AUDIO_PAGE_MASK
value|0x4e
name|u_char
name|param_len
decl_stmt|;
name|u_char
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
name|u_char
name|reserved3
decl_stmt|;
name|u_char
name|reserved4
decl_stmt|;
name|u_char
name|reserved5
decl_stmt|;
name|u_short
name|lb_per_sec
decl_stmt|;
struct|struct
name|port_control
block|{
name|u_char
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
name|u_char
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
comment|/*  * CDROM Capabilities and Mechanical Status Page  */
end_comment

begin_struct
struct|struct
name|cappage
block|{
comment|/* Mode data header */
name|u_short
name|data_length
decl_stmt|;
name|u_char
name|medium_type
decl_stmt|;
comment|/* Present media type */
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
name|u_char
name|dev_spec
decl_stmt|;
name|u_char
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|blk_desc_len
decl_stmt|;
comment|/* Capabilities page */
name|u_char
name|page_code
decl_stmt|;
define|#
directive|define
name|ATAPI_CDROM_CAP_PAGE
value|0x2a
name|u_char
name|param_len
decl_stmt|;
name|u_char
name|read_cdr
range|:
literal|1
decl_stmt|;
comment|/* Supports CD-R read */
name|u_char
name|read_cdrw
range|:
literal|1
decl_stmt|;
comment|/* Supports CD-RW read */
name|u_char
name|method2
range|:
literal|1
decl_stmt|;
comment|/* Supports reading packet tracks */
name|u_char
name|byte2_37
range|:
literal|5
decl_stmt|;
name|u_char
name|write_cdr
range|:
literal|1
decl_stmt|;
comment|/* Supports CD-R write */
name|u_char
name|write_cdrw
range|:
literal|1
decl_stmt|;
comment|/* Supports CD-RW write */
name|u_char
name|test_write
range|:
literal|1
decl_stmt|;
comment|/* Supports test writing */
name|u_char
name|byte3_37
range|:
literal|5
decl_stmt|;
name|u_char
name|audio_play
range|:
literal|1
decl_stmt|;
comment|/* Audio play supported */
name|u_char
name|composite
range|:
literal|1
decl_stmt|;
comment|/* Composite audio/video supported */
name|u_char
name|dport1
range|:
literal|1
decl_stmt|;
comment|/* Digital audio on port 1 */
name|u_char
name|dport2
range|:
literal|1
decl_stmt|;
comment|/* Digital audio on port 2 */
name|u_char
name|mode2_form1
range|:
literal|1
decl_stmt|;
comment|/* Mode 2 form 1 (XA) read */
name|u_char
name|mode2_form2
range|:
literal|1
decl_stmt|;
comment|/* Mode 2 form 2 format */
name|u_char
name|multisession
range|:
literal|1
decl_stmt|;
comment|/* Multi-session photo-CD */
name|u_char
label|:
literal|1
expr_stmt|;
name|u_char
name|cd_da
range|:
literal|1
decl_stmt|;
comment|/* Audio-CD read supported */
name|u_char
name|cd_da_stream
range|:
literal|1
decl_stmt|;
comment|/* CD-DA streaming */
name|u_char
name|rw
range|:
literal|1
decl_stmt|;
comment|/* Combined R-W subchannels */
name|u_char
name|rw_corr
range|:
literal|1
decl_stmt|;
comment|/* R-W subchannel data corrected */
name|u_char
name|c2
range|:
literal|1
decl_stmt|;
comment|/* C2 error pointers supported */
name|u_char
name|isrc
range|:
literal|1
decl_stmt|;
comment|/* Can return the ISRC info */
name|u_char
name|upc
range|:
literal|1
decl_stmt|;
comment|/* Can return the catalog number UPC */
name|u_char
label|:
literal|1
expr_stmt|;
name|u_char
name|lock
range|:
literal|1
decl_stmt|;
comment|/* Can be locked */
name|u_char
name|locked
range|:
literal|1
decl_stmt|;
comment|/* Current lock state */
name|u_char
name|prevent
range|:
literal|1
decl_stmt|;
comment|/* Prevent jumper installed */
name|u_char
name|eject
range|:
literal|1
decl_stmt|;
comment|/* Can eject */
name|u_char
label|:
literal|1
expr_stmt|;
name|u_char
name|mech
range|:
literal|3
decl_stmt|;
comment|/* Loading mechanism type */
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
name|u_char
name|sep_vol
range|:
literal|1
decl_stmt|;
comment|/* Independent volume of channels */
name|u_char
name|sep_mute
range|:
literal|1
decl_stmt|;
comment|/* Independent mute of channels */
name|u_char
label|:
literal|6
expr_stmt|;
name|u_short
name|max_speed
decl_stmt|;
comment|/* Max raw data rate in bytes/1000 */
name|u_short
name|max_vol_levels
decl_stmt|;
comment|/* Number of discrete volume levels */
name|u_short
name|buf_size
decl_stmt|;
comment|/* Internal buffer size in bytes/1024 */
name|u_short
name|cur_speed
decl_stmt|;
comment|/* Current data rate in bytes/1000  */
name|u_char
name|reserved3
decl_stmt|;
name|u_char
name|bckf
range|:
literal|1
decl_stmt|;
comment|/* Data valid on failing edge of BCK */
name|u_char
name|rch
range|:
literal|1
decl_stmt|;
comment|/* High LRCK indicates left channel */
name|u_char
name|lsbf
range|:
literal|1
decl_stmt|;
comment|/* Set if LSB first */
name|u_char
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
name|u_char
label|:
literal|3
expr_stmt|;
name|u_char
name|reserved4
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * CDROM Changer mechanism status structure  */
end_comment

begin_struct
struct|struct
name|changer
block|{
name|u_char
name|current_slot
range|:
literal|5
decl_stmt|;
comment|/* Active changer slot */
name|u_char
name|mech_state
range|:
literal|2
decl_stmt|;
comment|/* Current changer state */
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
name|u_char
name|fault
range|:
literal|1
decl_stmt|;
comment|/* Fault in last operation */
name|u_char
name|reserved0
range|:
literal|5
decl_stmt|;
name|u_char
name|cd_state
range|:
literal|3
decl_stmt|;
comment|/* Current mechanism state */
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
name|u_char
name|current_lba
index|[
literal|3
index|]
decl_stmt|;
comment|/* Current LBA */
name|u_char
name|slots
decl_stmt|;
comment|/* Number of available slots */
name|u_short
name|table_length
decl_stmt|;
comment|/* Slot table length */
struct|struct
block|{
name|u_char
name|changed
range|:
literal|1
decl_stmt|;
comment|/* Media has changed in this slot */
name|u_char
name|unused
range|:
literal|6
decl_stmt|;
name|u_char
name|present
range|:
literal|1
decl_stmt|;
comment|/* Slot has a CD present */
name|u_char
name|reserved0
decl_stmt|;
name|u_char
name|reserved1
decl_stmt|;
name|u_char
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
comment|/*  * CDROM Write Parameters Mode Page (Burners ONLY)  */
end_comment

begin_struct
struct|struct
name|write_param
block|{
comment|/* Mode Page data header */
name|u_short
name|data_length
decl_stmt|;
name|u_char
name|medium_type
decl_stmt|;
name|u_char
name|dev_spec
decl_stmt|;
name|u_char
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|u_short
name|blk_desc_len
decl_stmt|;
comment|/* Write Parameters mode page */
name|u_char
name|page_code
decl_stmt|;
comment|/* 0x05 */
name|u_char
name|page_length
decl_stmt|;
comment|/* 0x32 */
name|u_char
name|write_type
range|:
literal|4
decl_stmt|;
comment|/* Write stream type */
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
name|u_char
name|test_write
range|:
literal|1
decl_stmt|;
comment|/* Test write enable */
name|u_char
name|reserved2_567
range|:
literal|3
decl_stmt|;
name|u_char
name|track_mode
range|:
literal|4
decl_stmt|;
comment|/* Track mode */
define|#
directive|define
name|CDR_TMODE_AUDIO
value|0x01
define|#
directive|define
name|CDR_TMODE_INCR_DATA
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
name|u_char
name|copy
range|:
literal|1
decl_stmt|;
comment|/* Generation stamp */
name|u_char
name|fp
range|:
literal|1
decl_stmt|;
comment|/* Fixed packet type */
name|u_char
name|multi_session
range|:
literal|2
decl_stmt|;
comment|/* Multi-session type */
define|#
directive|define
name|CDR_MSES_NONE
value|0x00
define|#
directive|define
name|CDR_MSES_FINAL
value|0x01
define|#
directive|define
name|CDR_MSES_RESERVED
value|0x02
define|#
directive|define
name|CDR_MSES_NULTI
value|0x03
name|u_char
name|data_block_type
range|:
literal|4
decl_stmt|;
comment|/* Data block type code */
define|#
directive|define
name|CDR_DB_RAW
value|0x0
comment|/* 2352 bytes of raw data */
define|#
directive|define
name|CDR_DB_RAW_PQ
value|0x1
comment|/* 2368 bytes raw data + P/Q subchan */
define|#
directive|define
name|CDR_DB_RAW_PW
value|0x2
comment|/* 2448 bytes raw data + P-W subchan */
define|#
directive|define
name|CDR_DB_RAW_PW_R
value|0x3
comment|/* 2448 bytes raw data + P-W raw sub */
define|#
directive|define
name|CDR_DB_RES_4
value|0x4
comment|/* Reserved */
define|#
directive|define
name|CDR_DB_RES_5
value|0x5
comment|/* Reserved */
define|#
directive|define
name|CDR_DB_RES_6
value|0x6
comment|/* Reserved */
define|#
directive|define
name|CDR_DB_VS_7
value|0x7
comment|/* Vendor specific */
define|#
directive|define
name|CDR_DB_ROM_MODE1
value|0x8
comment|/* 2048 bytes Mode 1 (ISO/IEC 10149) */
define|#
directive|define
name|CDR_DB_ROM_MODE2
value|0x9
comment|/* 2336 bytes Mode 2 (ISO/IEC 10149) */
define|#
directive|define
name|CDR_DB_XA_MODE1
value|0x10
comment|/* 2048 bytes Mode 1 (CD-ROM XA 1) */
define|#
directive|define
name|CDR_DB_XA_MODE2_F1
value|0x11
comment|/* 2056 bytes Mode 2 (CD-ROM XA 1) */
define|#
directive|define
name|CDR_DB_XA_MODE2_F2
value|0x12
comment|/* 2324 bytes Mode 2 (CD-ROM XA 2) */
define|#
directive|define
name|CDR_DB_XA_MODE2_MIX
value|0x13
comment|/* 2332 bytes Mode 2 (CD-ROM XA 1/2) */
define|#
directive|define
name|CDR_DB_RES_14
value|0x14
comment|/* Reserved */
define|#
directive|define
name|CDR_DB_VS_15
value|0x15
comment|/* Vendor specific */
name|u_char
name|reserved4_4567
range|:
literal|4
decl_stmt|;
name|u_char
name|reserved5
decl_stmt|;
name|u_char
name|reserved6
decl_stmt|;
name|u_char
name|host_app_code
range|:
literal|6
decl_stmt|;
comment|/* Host application code */
name|u_char
name|reserved7_67
range|:
literal|2
decl_stmt|;
name|u_char
name|session_format
decl_stmt|;
comment|/* Session format */
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
name|u_char
name|reserved9
decl_stmt|;
name|u_int
name|packet_size
decl_stmt|;
comment|/* Packet size in bytes */
name|u_short
name|audio_pause_length
decl_stmt|;
comment|/* Audio pause length in secs */
name|u_char
name|media_catalog_number
index|[
literal|16
index|]
decl_stmt|;
name|u_char
name|isr_code
index|[
literal|16
index|]
decl_stmt|;
name|u_char
name|sub_hdr_byte0
decl_stmt|;
name|u_char
name|sub_hdr_byte1
decl_stmt|;
name|u_char
name|sub_hdr_byte2
decl_stmt|;
name|u_char
name|sub_hdr_byte3
decl_stmt|;
comment|/* 	u_char 	vendor_specific_byte0; 	u_char 	vendor_specific_byte1; 	u_char 	vendor_specific_byte2; 	u_char 	vendor_specific_byte3; */
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
comment|/*  * CDROM Read Track Information structure  */
end_comment

begin_struct
struct|struct
name|acd_track_info
block|{
name|u_short
name|data_length
decl_stmt|;
name|u_char
name|track_number
decl_stmt|;
comment|/* Current track number */
name|u_char
name|session_number
decl_stmt|;
comment|/* Current session number */
name|u_char
name|reserved4
decl_stmt|;
name|u_char
name|track_mode
range|:
literal|4
decl_stmt|;
comment|/* Mode of this track */
name|u_char
name|copy
range|:
literal|1
decl_stmt|;
comment|/* Generation stamp */
name|u_char
name|damage
range|:
literal|1
decl_stmt|;
comment|/* Damaged track */
name|u_char
name|reserved5_67
range|:
literal|2
decl_stmt|;
name|u_char
name|data_mode
range|:
literal|4
decl_stmt|;
comment|/* Data mode of this disc */
name|u_char
name|fp
range|:
literal|1
decl_stmt|;
comment|/* Fixed packet */
name|u_char
name|packet
range|:
literal|1
decl_stmt|;
comment|/* Packet track */
name|u_char
name|blank
range|:
literal|1
decl_stmt|;
comment|/* Blank (empty) track */
name|u_char
name|rt
range|:
literal|1
decl_stmt|;
comment|/* Reserved track */
name|u_char
name|nwa_valid
range|:
literal|1
decl_stmt|;
comment|/* next_writeable_addr field valid */
name|u_char
name|reserved7_17
range|:
literal|7
decl_stmt|;
name|u_int
name|track_start_addr
decl_stmt|;
comment|/* Start of this track */
name|u_int
name|next_writeable_addr
decl_stmt|;
comment|/* Next writeable addr on this disc */
name|u_int
name|free_blocks
decl_stmt|;
comment|/* Free block on this disc */
name|u_int
name|fixed_packet_size
decl_stmt|;
comment|/* Size of packets on this track */
name|u_int
name|track_length
decl_stmt|;
comment|/* Length of this track */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure describing an ATAPI CDROM device  */
end_comment

begin_struct
struct|struct
name|acd
block|{
name|int
name|unit
decl_stmt|;
comment|/* IDE bus drive unit */
name|int
name|lun
decl_stmt|;
comment|/* Logical device unit */
name|int
name|flags
decl_stmt|;
comment|/* Device state flags */
name|int
name|refcnt
decl_stmt|;
comment|/* The number of raw opens */
name|struct
name|atapi
modifier|*
name|ata
decl_stmt|;
comment|/* Controller structure */
name|struct
name|buf_queue_head
name|buf_queue
decl_stmt|;
comment|/* Queue of i/o requests */
name|struct
name|atapi_params
modifier|*
name|param
decl_stmt|;
comment|/* Drive parameters table */
name|struct
name|toc
name|toc
decl_stmt|;
comment|/* Table of disc contents */
struct|struct
block|{
name|u_long
name|volsize
decl_stmt|;
comment|/* Volume size in blocks */
name|u_long
name|blksize
decl_stmt|;
comment|/* Block size in bytes */
block|}
name|info
struct|;
name|struct
name|audiopage
name|au
decl_stmt|;
comment|/* Audio page info */
name|struct
name|cappage
name|cap
decl_stmt|;
comment|/* Capabilities page info */
name|struct
name|audiopage
name|aumask
decl_stmt|;
comment|/* Audio page mask */
struct|struct
block|{
comment|/* Subchannel info */
name|u_char
name|void0
decl_stmt|;
name|u_char
name|audio_status
decl_stmt|;
name|u_short
name|data_length
decl_stmt|;
name|u_char
name|data_format
decl_stmt|;
name|u_char
name|control
decl_stmt|;
name|u_char
name|track
decl_stmt|;
name|u_char
name|indx
decl_stmt|;
name|u_long
name|abslba
decl_stmt|;
name|u_long
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
comment|/* Changer info */
name|int
name|slot
decl_stmt|;
comment|/* This lun's slot number */
name|struct
name|devstat
modifier|*
name|device_stats
decl_stmt|;
comment|/* Devstat parameters */
name|u_int
name|block_size
decl_stmt|;
comment|/* Blocksize currently used */
name|u_char
name|dummy
decl_stmt|;
comment|/* Use dummy writes */
name|u_char
name|speed
decl_stmt|;
comment|/* Select drive speed */
name|u_int
name|next_writeable_lba
decl_stmt|;
comment|/* Next writable position */
name|struct
name|wormio_prepare_track
name|preptrack
decl_stmt|;
comment|/* Scratch region */
block|}
struct|;
end_struct

end_unit

