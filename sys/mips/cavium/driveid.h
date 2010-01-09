begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * driveid.h  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DRIVEID_H__
end_ifndef

begin_define
define|#
directive|define
name|__DRIVEID_H__
end_define

begin_struct
struct|struct
name|hd_driveid
block|{
name|unsigned
name|short
name|config
decl_stmt|;
comment|/* lots of obsolete bit flags */
name|unsigned
name|short
name|cyls
decl_stmt|;
comment|/* Obsolete, "physical" cyls */
name|unsigned
name|short
name|reserved2
decl_stmt|;
comment|/* reserved (word 2) */
name|unsigned
name|short
name|heads
decl_stmt|;
comment|/* Obsolete, "physical" heads */
name|unsigned
name|short
name|track_bytes
decl_stmt|;
comment|/* unformatted bytes per track */
name|unsigned
name|short
name|sector_bytes
decl_stmt|;
comment|/* unformatted bytes per sector */
name|unsigned
name|short
name|sectors
decl_stmt|;
comment|/* Obsolete, "physical" sectors per track */
name|unsigned
name|short
name|vendor0
decl_stmt|;
comment|/* vendor unique */
name|unsigned
name|short
name|vendor1
decl_stmt|;
comment|/* vendor unique */
name|unsigned
name|short
name|vendor2
decl_stmt|;
comment|/* Retired vendor unique */
name|unsigned
name|char
name|serial_no
index|[
literal|20
index|]
decl_stmt|;
comment|/* 0 = not_specified */
name|unsigned
name|short
name|buf_type
decl_stmt|;
comment|/* Retired */
name|unsigned
name|short
name|buf_size
decl_stmt|;
comment|/* Retired, 512 byte increments                                          * 0 = not_specified                                          */
name|unsigned
name|short
name|ecc_bytes
decl_stmt|;
comment|/* for r/w long cmds; 0 = not_specified */
name|unsigned
name|char
name|fw_rev
index|[
literal|8
index|]
decl_stmt|;
comment|/* 0 = not_specified */
name|unsigned
name|char
name|model
index|[
literal|40
index|]
decl_stmt|;
comment|/* 0 = not_specified */
name|unsigned
name|char
name|max_multsect
decl_stmt|;
comment|/* 0=not_implemented */
name|unsigned
name|char
name|vendor3
decl_stmt|;
comment|/* vendor unique */
name|unsigned
name|short
name|dword_io
decl_stmt|;
comment|/* 0=not_implemented; 1=implemented */
name|unsigned
name|char
name|vendor4
decl_stmt|;
comment|/* vendor unique */
name|unsigned
name|char
name|capability
decl_stmt|;
comment|/* (upper byte of word 49)                                          *  3:  IORDYsup                                          *  2:  IORDYsw                                          *  1:  LBA                                          *  0:  DMA                                          */
name|unsigned
name|short
name|reserved50
decl_stmt|;
comment|/* reserved (word 50) */
name|unsigned
name|char
name|vendor5
decl_stmt|;
comment|/* Obsolete, vendor unique */
name|unsigned
name|char
name|tPIO
decl_stmt|;
comment|/* Obsolete, 0=slow, 1=medium, 2=fast */
name|unsigned
name|char
name|vendor6
decl_stmt|;
comment|/* Obsolete, vendor unique */
name|unsigned
name|char
name|tDMA
decl_stmt|;
comment|/* Obsolete, 0=slow, 1=medium, 2=fast */
name|unsigned
name|short
name|field_valid
decl_stmt|;
comment|/* (word 53)                                          *  2:  ultra_ok        word  88                                          *  1:  eide_ok         words 64-70                                          *  0:  cur_ok          words 54-58                                          */
name|unsigned
name|short
name|cur_cyls
decl_stmt|;
comment|/* Obsolete, logical cylinders */
name|unsigned
name|short
name|cur_heads
decl_stmt|;
comment|/* Obsolete, l heads */
name|unsigned
name|short
name|cur_sectors
decl_stmt|;
comment|/* Obsolete, l sectors per track */
name|unsigned
name|short
name|cur_capacity0
decl_stmt|;
comment|/* Obsolete, l total sectors on drive */
name|unsigned
name|short
name|cur_capacity1
decl_stmt|;
comment|/* Obsolete, (2 words, misaligned int)     */
name|unsigned
name|char
name|multsect
decl_stmt|;
comment|/* current multiple sector count */
name|unsigned
name|char
name|multsect_valid
decl_stmt|;
comment|/* when (bit0==1) multsect is ok */
name|unsigned
name|int
name|lba_capacity
decl_stmt|;
comment|/* Obsolete, total number of sectors */
name|unsigned
name|short
name|dma_1word
decl_stmt|;
comment|/* Obsolete, single-word dma info */
name|unsigned
name|short
name|dma_mword
decl_stmt|;
comment|/* multiple-word dma info */
name|unsigned
name|short
name|eide_pio_modes
decl_stmt|;
comment|/* bits 0:mode3 1:mode4 */
name|unsigned
name|short
name|eide_dma_min
decl_stmt|;
comment|/* min mword dma cycle time (ns) */
name|unsigned
name|short
name|eide_dma_time
decl_stmt|;
comment|/* recommended mword dma cycle time (ns) */
name|unsigned
name|short
name|eide_pio
decl_stmt|;
comment|/* min cycle time (ns), no IORDY  */
name|unsigned
name|short
name|eide_pio_iordy
decl_stmt|;
comment|/* min cycle time (ns), with IORDY */
name|unsigned
name|short
name|words69_70
index|[
literal|2
index|]
decl_stmt|;
comment|/* reserved words 69-70                                          * future command overlap and queuing                                          */
comment|/* HDIO_GET_IDENTITY currently returns only words 0 through 70 */
name|unsigned
name|short
name|words71_74
index|[
literal|4
index|]
decl_stmt|;
comment|/* reserved words 71-74                                          * for IDENTIFY PACKET DEVICE command                                          */
name|unsigned
name|short
name|queue_depth
decl_stmt|;
comment|/* (word 75)                                          * 15:5 reserved                                          *  4:0 Maximum queue depth -1                                          */
name|unsigned
name|short
name|words76_79
index|[
literal|4
index|]
decl_stmt|;
comment|/* reserved words 76-79 */
name|unsigned
name|short
name|major_rev_num
decl_stmt|;
comment|/* (word 80) */
name|unsigned
name|short
name|minor_rev_num
decl_stmt|;
comment|/* (word 81) */
name|unsigned
name|short
name|command_set_1
decl_stmt|;
comment|/* (word 82) supported                                          * 15:  Obsolete                                          * 14:  NOP command                                          * 13:  READ_BUFFER                                          * 12:  WRITE_BUFFER                                          * 11:  Obsolete                                          * 10:  Host Protected Area                                          *  9:  DEVICE Reset                                          *  8:  SERVICE Interrupt                                          *  7:  Release Interrupt                                          *  6:  look-ahead                                          *  5:  write cache                                          *  4:  PACKET Command                                          *  3:  Power Management Feature Set                                          *  2:  Removable Feature Set                                          *  1:  Security Feature Set                                          *  0:  SMART Feature Set                                          */
name|unsigned
name|short
name|command_set_2
decl_stmt|;
comment|/* (word 83)                                          * 15:  Shall be ZERO                                          * 14:  Shall be ONE                                          * 13:  FLUSH CACHE EXT                                          * 12:  FLUSH CACHE                                          * 11:  Device Configuration Overlay                                          * 10:  48-bit Address Feature Set                                          *  9:  Automatic Acoustic Management                                          *  8:  SET MAX security                                          *  7:  reserved 1407DT PARTIES                                          *  6:  SetF sub-command Power-Up                                          *  5:  Power-Up in Standby Feature Set                                          *  4:  Removable Media Notification                                          *  3:  APM Feature Set                                          *  2:  CFA Feature Set                                          *  1:  READ/WRITE DMA QUEUED                                          *  0:  Download MicroCode                                          */
name|unsigned
name|short
name|cfsse
decl_stmt|;
comment|/* (word 84)                                          * cmd set-feature supported extensions                                          * 15:  Shall be ZERO                                          * 14:  Shall be ONE                                          * 13:6 reserved                                          *  5:  General Purpose Logging                                          *  4:  Streaming Feature Set                                          *  3:  Media Card Pass Through                                          *  2:  Media Serial Number Valid                                          *  1:  SMART selt-test supported                                          *  0:  SMART error logging                                          */
name|unsigned
name|short
name|cfs_enable_1
decl_stmt|;
comment|/* (word 85)                                          * command set-feature enabled                                          * 15:  Obsolete                                          * 14:  NOP command                                          * 13:  READ_BUFFER                                          * 12:  WRITE_BUFFER                                          * 11:  Obsolete                                          * 10:  Host Protected Area                                          *  9:  DEVICE Reset                                          *  8:  SERVICE Interrupt                                          *  7:  Release Interrupt                                          *  6:  look-ahead                                          *  5:  write cache                                          *  4:  PACKET Command 					 *  3:  Power Management Feature Set                                          *  2:  Removable Feature Set                                          *  1:  Security Feature Set                                          *  0:  SMART Feature Set                                          */
name|unsigned
name|short
name|cfs_enable_2
decl_stmt|;
comment|/* (word 86)                                          * command set-feature enabled                                          * 15:  Shall be ZERO                                          * 14:  Shall be ONE                                          * 13:  FLUSH CACHE EXT                                          * 12:  FLUSH CACHE                                          * 11:  Device Configuration Overlay                                          * 10:  48-bit Address Feature Set                                          *  9:  Automatic Acoustic Management                                          *  8:  SET MAX security                                          *  7:  reserved 1407DT PARTIES                                          *  6:  SetF sub-command Power-Up                                          *  5:  Power-Up in Standby Feature Set                                          *  4:  Removable Media Notification                                          *  3:  APM Feature Set                                          *  2:  CFA Feature Set                                          *  1:  READ/WRITE DMA QUEUED                                          *  0:  Download MicroCode                                          */
name|unsigned
name|short
name|csf_default
decl_stmt|;
comment|/* (word 87)                                          * command set-feature default                                          * 15:  Shall be ZERO                                          * 14:  Shall be ONE                                          * 13:6 reserved                                          *  5:  General Purpose Logging enabled                                          *  4:  Valid CONFIGURE STREAM executed                                          *  3:  Media Card Pass Through enabled                                          *  2:  Media Serial Number Valid                                          *  1:  SMART selt-test supported                                          *  0:  SMART error logging                                          */
name|unsigned
name|short
name|dma_ultra
decl_stmt|;
comment|/* (word 88) */
name|unsigned
name|short
name|trseuc
decl_stmt|;
comment|/* time required for security erase */
name|unsigned
name|short
name|trsEuc
decl_stmt|;
comment|/* time required for enhanced erase */
name|unsigned
name|short
name|CurAPMvalues
decl_stmt|;
comment|/* current APM values */
name|unsigned
name|short
name|mprc
decl_stmt|;
comment|/* master password revision code */
name|unsigned
name|short
name|hw_config
decl_stmt|;
comment|/* hardware config (word 93)  					 * 15:  Shall be ZERO                                          * 14:  Shall be ONE                                          * 13:                                          * 12:                                          * 11:                                          * 10:                                          *  9:                                          *  8:                                          *  7:                                          *  6:                                          *  5:                                          *  4:                                          *  3:                                          *  2:                                          *  1:                                          *  0:  Shall be ONE                                          */
name|unsigned
name|short
name|acoustic
decl_stmt|;
comment|/* (word 94)                                          * 15:8 Vendor's recommended value                                          *  7:0 current value                                          */
name|unsigned
name|short
name|msrqs
decl_stmt|;
comment|/* min stream request size */
name|unsigned
name|short
name|sxfert
decl_stmt|;
comment|/* stream transfer time */
name|unsigned
name|short
name|sal
decl_stmt|;
comment|/* stream access latency */
name|unsigned
name|int
name|spg
decl_stmt|;
comment|/* stream performance granularity */
name|unsigned
name|long
name|long
name|lba_capacity_2
decl_stmt|;
comment|/* 48-bit total number of sectors */
name|unsigned
name|short
name|words104_125
index|[
literal|22
index|]
decl_stmt|;
comment|/* reserved words 104-125 */
name|unsigned
name|short
name|last_lun
decl_stmt|;
comment|/* (word 126) */
name|unsigned
name|short
name|word127
decl_stmt|;
comment|/* (word 127) Feature Set                                          * Removable Media Notification                                          * 15:2 reserved                                          *  1:0 00 = not supported                                          *      01 = supported                                          *      10 = reserved                                          *      11 = reserved                                          */
name|unsigned
name|short
name|dlf
decl_stmt|;
comment|/* (word 128)                                          * device lock function                                          * 15:9 reserved                                          *  8   security level 1:max 0:high                                          *  7:6 reserved 					 *  5   enhanced erase                                          *  4   expire                                          *  3   frozen                                          *  2   locked                                          *  1   en/disabled                                          *  0   capability                                          */
name|unsigned
name|short
name|csfo
decl_stmt|;
comment|/*  (word 129)                                          * current set features options                                          * 15:4 reserved                                          *  3:  auto reassign                                          *  2:  reverting                                          *  1:  read-look-ahead                                          *  0:  write cache                                          */
name|unsigned
name|short
name|words130_155
index|[
literal|26
index|]
decl_stmt|;
comment|/* reserved vendor words 130-155 */
name|unsigned
name|short
name|word156
decl_stmt|;
comment|/* reserved vendor word 156 */
name|unsigned
name|short
name|words157_159
index|[
literal|3
index|]
decl_stmt|;
comment|/* reserved vendor words 157-159 */
name|unsigned
name|short
name|cfa_power
decl_stmt|;
comment|/* (word 160) CFA Power Mode                                          * 15 word 160 supported                                          * 14 reserved                                          * 13                                          * 12                                          * 11:0                                          */
name|unsigned
name|short
name|words161_175
index|[
literal|15
index|]
decl_stmt|;
comment|/* Reserved for CFA */
name|unsigned
name|short
name|words176_205
index|[
literal|30
index|]
decl_stmt|;
comment|/* Current Media Serial Number */
name|unsigned
name|short
name|words206_254
index|[
literal|49
index|]
decl_stmt|;
comment|/* reserved words 206-254 */
name|unsigned
name|short
name|integrity_word
decl_stmt|;
comment|/* (word 255)                                          * 15:8 Checksum                                          *  7:0 Signature                                          */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __DRIVEID_H__ */
end_comment

end_unit

