begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * SCSI tape interface description  */
end_comment

begin_comment
comment|/*  * Written by Julian Elischer (julian@tfs.com)  * for TRW Financial Systems.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with   * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  */
end_comment

begin_comment
comment|/*  * Ported to run under 386BSD by Julian Elischer (julian@tfs.com) Sept 1992  *  *	$Id: scsi_tape.h,v 1.9 1994/09/28 20:16:42 se Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCSI_SCSI_TAPE_H
end_ifndef

begin_define
define|#
directive|define
name|SCSI_SCSI_TAPE_H
value|1
end_define

begin_comment
comment|/*  * SCSI command formats  */
end_comment

begin_struct
struct|struct
name|scsi_rw_tape
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
define|#
directive|define
name|SRWT_FIXED
value|0x01
name|u_char
name|len
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
name|rw_tape
struct|;
end_struct

begin_struct
struct|struct
name|scsi_space
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
define|#
directive|define
name|SS_CODE
value|0x03
name|u_char
name|number
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
name|space
struct|;
end_struct

begin_define
define|#
directive|define
name|SP_BLKS
value|0
end_define

begin_define
define|#
directive|define
name|SP_FILEMARKS
value|1
end_define

begin_define
define|#
directive|define
name|SP_SEQ_FILEMARKS
value|2
end_define

begin_define
define|#
directive|define
name|SP_EOM
value|3
end_define

begin_struct
struct|struct
name|scsi_write_filemarks
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|number
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
name|write_filemarks
struct|;
end_struct

begin_struct
struct|struct
name|scsi_rewind
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
define|#
directive|define
name|SR_IMMED
value|0x01
name|u_char
name|unused
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
name|rewind
struct|;
end_struct

begin_comment
comment|/* ** Tape erase - AKL: Andreas Klemm<andreas@knobel.gun.de> */
end_comment

begin_struct
struct|struct
name|scsi_erase
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
define|#
directive|define
name|SE_LONG
value|0x01
comment|/* 				** Archive Viper 2525 doesn't allow short  				** erase, other tapes possibly don't allow  				** that, too. 				*/
define|#
directive|define
name|SE_IMMED
value|0x02
name|u_char
name|unused
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
name|erase
struct|;
end_struct

begin_struct
struct|struct
name|scsi_load
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
define|#
directive|define
name|SL_IMMED
value|0x01
name|u_char
name|unused
index|[
literal|2
index|]
decl_stmt|;
name|u_char
name|how
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
name|load
struct|;
end_struct

begin_define
define|#
directive|define
name|LD_UNLOAD
value|0
end_define

begin_define
define|#
directive|define
name|LD_LOAD
value|1
end_define

begin_define
define|#
directive|define
name|LD_RETEN
value|2
end_define

begin_struct
struct|struct
name|scsi_blk_limits
block|{
name|u_char
name|op_code
decl_stmt|;
name|u_char
name|byte2
decl_stmt|;
name|u_char
name|unused
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|control
decl_stmt|;
block|}
name|blk_limits
struct|;
end_struct

begin_comment
comment|/*  * Opcodes  */
end_comment

begin_define
define|#
directive|define
name|REWIND
value|0x01
end_define

begin_define
define|#
directive|define
name|READ_BLK_LIMITS
value|0x05
end_define

begin_define
define|#
directive|define
name|READ_COMMAND_TAPE
value|0x08
end_define

begin_define
define|#
directive|define
name|WRITE_COMMAND_TAPE
value|0x0a
end_define

begin_define
define|#
directive|define
name|WRITE_FILEMARKS
value|0x10
end_define

begin_define
define|#
directive|define
name|SPACE
value|0x11
end_define

begin_define
define|#
directive|define
name|ERASE
value|0x19
end_define

begin_comment
comment|/* AKL */
end_comment

begin_define
define|#
directive|define
name|LOAD_UNLOAD
value|0x1b
end_define

begin_comment
comment|/* same as above */
end_comment

begin_struct
struct|struct
name|scsi_blk_limits_data
block|{
name|u_char
name|reserved
decl_stmt|;
name|u_char
name|max_length_2
decl_stmt|;
comment|/* Most significant */
name|u_char
name|max_length_1
decl_stmt|;
name|u_char
name|max_length_0
decl_stmt|;
comment|/* Least significant */
name|u_char
name|min_length_1
decl_stmt|;
comment|/* Most significant */
name|u_char
name|min_length_0
decl_stmt|;
comment|/* Least significant */
block|}
struct|;
end_struct

begin_comment
comment|/* defines for the device specific byte in the mode select/sense header */
end_comment

begin_define
define|#
directive|define
name|SMH_DSP_SPEED
value|0x0F
end_define

begin_define
define|#
directive|define
name|SMH_DSP_BUFF_MODE
value|0x70
end_define

begin_define
define|#
directive|define
name|SMH_DSP_BUFF_MODE_OFF
value|0x00
end_define

begin_define
define|#
directive|define
name|SMH_DSP_BUFF_MODE_ON
value|0x10
end_define

begin_define
define|#
directive|define
name|SMH_DSP_BUFF_MODE_MLTI
value|0x20
end_define

begin_define
define|#
directive|define
name|SMH_DSP_WRITE_PROT
value|0x80
end_define

begin_comment
comment|/* A special for the CIPHER ST150S(old drive) */
end_comment

begin_struct
struct|struct
name|blk_desc_cipher
block|{
name|u_char
name|density
decl_stmt|;
name|u_char
name|nblocks
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|reserved
decl_stmt|;
name|u_char
name|blklen
index|[
literal|3
index|]
decl_stmt|;
name|u_char
name|other
decl_stmt|;
define|#
directive|define
name|ST150_SEC
value|0x01
comment|/* soft error count */
define|#
directive|define
name|SR150_AUI
value|0x02
comment|/* autoload inhibit */
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|NEW_SCSICONF
end_ifndef

begin_comment
comment|/********************************************************************** 			from the scsi2 spec                 Value Tracks Density(bpi) Code Type  Reference     Note                 0x1     9       800       NRZI  R    X3.22-1983    2                 0x2     9      1600       PE    R    X3.39-1986    2                 0x3     9      6250       GCR   R    X3.54-1986    2                 0x5    4/9     8000       GCR   C    X3.136-1986   1                 0x6     9      3200       PE    R    X3.157-1987   2                 0x7     4      6400       IMFM  C    X3.116-1986   1                 0x8     4      8000       GCR   CS   X3.158-1986   1                 0x9    18     37871       GCR   C    X3B5/87-099   2                 0xA    22      6667       MFM   C    X3B5/86-199   1                 0xB     4      1600       PE    C    X3.56-1986    1                 0xC    24     12690       GCR   C    HI-TC1        1,5                 0xD    24     25380       GCR   C    HI-TC2        1,5                 0xF    15     10000       GCR   C    QIC-120       1,5                 0x10   18     10000       GCR   C    QIC-150       1,5                 0x11   26     16000       GCR   C    QIC-320(525?) 1,5                 0x12   30     51667       RLL   C    QIC-1350      1,5                 0x13    1     61000       DDS   CS    X3B5/88-185A 4                 0x14    1     43245       RLL   CS    X3.202-1991  4                 0x15    1     45434       RLL   CS    ECMA TC17    4                 0x16   48     10000       MFM   C     X3.193-1990  1                 0x17   48     42500       MFM   C     X3B5/91-174  1                  where Code means:                 NRZI Non Return to Zero, change on ones                 GCR  Group Code Recording                 PE   Phase Encoded                 IMFM Inverted Modified Frequency Modulation                 MFM  Modified Frequency Modulation                 DDS  Dat Data Storage                 RLL  Run Length Encoding                  where Type means:                 R    Real-to-Real                 C    Cartridge                 CS   cassette                  where Notes means:                 1    Serial Recorded                 2    Parallel Recorded                 3    Old format know as QIC-11                 4    Helical Scan                 5    Not ANSI standard, rather industry standard.  ********************************************************************/
end_comment

begin_define
define|#
directive|define
name|HALFINCH_800
value|0x01
end_define

begin_define
define|#
directive|define
name|HALFINCH_1600
value|0x02
end_define

begin_define
define|#
directive|define
name|HALFINCH_6250
value|0x03
end_define

begin_define
define|#
directive|define
name|QIC_11
value|0x04
end_define

begin_comment
comment|/* from Archive 150S Theory of Op. XXX	*/
end_comment

begin_define
define|#
directive|define
name|QIC_24
value|0x05
end_define

begin_comment
comment|/* may be bad, works for CIPHER ST150S XXX */
end_comment

begin_define
define|#
directive|define
name|QIC_120
value|0x0f
end_define

begin_define
define|#
directive|define
name|QIC_150
value|0x10
end_define

begin_define
define|#
directive|define
name|QIC_320
value|0x11
end_define

begin_define
define|#
directive|define
name|QIC_525
value|0x11
end_define

begin_define
define|#
directive|define
name|QIC_1320
value|0x12
end_define

begin_define
define|#
directive|define
name|DDS
value|0x13
end_define

begin_define
define|#
directive|define
name|DAT_1
value|0x13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEW_SCSICONF */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*SCSI_SCSI_TAPE_H*/
end_comment

end_unit

