begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Ralph Campbell.  *  * %sccs.include.redist.c%  *  *	@(#)scsi.h	7.4 (Berkeley) %G%  *  * scsi.h --  *  *	Common declarations for SCSI command formaters. This file only covers  *	definitions pertaining to the SCSI common command set that are  *	common to all SCSI device types (ie disk, tapes, WORM, printers, etc).  *	Some of the references from the proceedings of the  *	1984 Mini/Micro Northeast conference might help in understanding SCSI.   *  * from: $Header: /sprite/src/kernel/dev/RCS/scsi.h,  *	v 9.1 90/02/13 23:11:24 jhh Exp $ SPRITE (Berkeley)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_H
end_define

begin_comment
comment|/*  * "Standard" SCSI Commands.  * SCSI commands are divided into 8 groups as follows:  *	Group0	(0x00 - 0x1f).	Basic commands. 6 bytes long  *	Group1	(0x20 - 0x3f).	Extended command. 10 bytes.  *	Group2	(0x40 - 0x5f).	Reserved.  *	Group2	(0x60 - 0x7f).	Reserved.  *	Group2	(0x80 - 0x9f).	Reserved.  *	Group2	(0xa0 - 0xbf).	Reserved.  *	Group6	(0xc0 - 0xdf).	Vendor Unique  *	Group7	(0xe0 - 0xff).	Vendor Unique  */
end_comment

begin_comment
comment|/*  * Scsi Group0 commands all are 6 bytes and have a format according to   * struct ScsiGroup0Cmd.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_TEST_UNIT_READY
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_REZERO_UNIT
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_REWIND
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_REQUEST_SENSE
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSI_FORMAT_UNIT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_READ_BLOCK_LIMITS
value|0x05
end_define

begin_define
define|#
directive|define
name|SCSI_REASSIGN_BLOCKS
value|0x07
end_define

begin_define
define|#
directive|define
name|SCSI_READ
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE
value|0x0a
end_define

begin_define
define|#
directive|define
name|SCSI_SEEK
value|0x0b
end_define

begin_define
define|#
directive|define
name|SCSI_TRACK_SELECT
value|0x0b
end_define

begin_define
define|#
directive|define
name|SCSI_READ_REVERSE
value|0x0f
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_EOF
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_SPACE
value|0x11
end_define

begin_define
define|#
directive|define
name|SCSI_INQUIRY
value|0x12
end_define

begin_define
define|#
directive|define
name|SCSI_VERIFY
value|0x13
end_define

begin_define
define|#
directive|define
name|SCSI_READ_BUFFER
value|0x14
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SELECT
value|0x15
end_define

begin_define
define|#
directive|define
name|SCSI_RESERVE_UNIT
value|0x16
end_define

begin_define
define|#
directive|define
name|SCSI_RELEASE_UNIT
value|0x17
end_define

begin_define
define|#
directive|define
name|SCSI_COPY
value|0x18
end_define

begin_define
define|#
directive|define
name|SCSI_ERASE_TAPE
value|0x19
end_define

begin_define
define|#
directive|define
name|SCSI_MODE_SENSE
value|0x1a
end_define

begin_define
define|#
directive|define
name|SCSI_START_STOP
value|0x1b
end_define

begin_define
define|#
directive|define
name|SCSI_LOAD_UNLOAD
value|0x1b
end_define

begin_define
define|#
directive|define
name|SCSI_RECV_DIAG_RESULTS
value|0x1c
end_define

begin_define
define|#
directive|define
name|SCSI_SEND_DIAGNOSTIC
value|0x1d
end_define

begin_define
define|#
directive|define
name|SCSI_PREVENT_ALLOW
value|0x1e
end_define

begin_comment
comment|/*  * Group1 commands are all 10 bytes and have a format according to  * struct ScsiGroup1Cmd.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_READ_CAPACITY
value|0x25
end_define

begin_define
define|#
directive|define
name|SCSI_READ_EXT
value|0x28
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_EXT
value|0x2a
end_define

begin_define
define|#
directive|define
name|SCSI_SEEK_EXT
value|0x2b
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_VERIFY
value|0x2e
end_define

begin_define
define|#
directive|define
name|SCSI_VERIFY_EXT
value|0x2f
end_define

begin_define
define|#
directive|define
name|SCSI_SEARCH_HIGH
value|0x30
end_define

begin_define
define|#
directive|define
name|SCSI_SEARCH_EQUAL
value|0x31
end_define

begin_define
define|#
directive|define
name|SCSI_SEARCH_LOW
value|0x32
end_define

begin_define
define|#
directive|define
name|SCSI_SET_LIMITS
value|0x33
end_define

begin_define
define|#
directive|define
name|SCSI_COMPARE
value|0x39
end_define

begin_define
define|#
directive|define
name|SCSI_COPY_VERIFY
value|0x3a
end_define

begin_comment
comment|/*  * Control byte flags for Group0 and Group1 commands.  *  * SCSI_CTRL_LINK - This is used to prevent a bus free phase between commands.  *	If the command terminates successfully, a SCSI_LINKED_CMD_COMPLETE  *	message is returned instead of the normal SCSI_COMMAND_COMPLETE message. *	The last command in a chain should not have this bit set  *	(and consequently gets a normal SCSI_COMMAND_COMPLETE message).  * SCSI_CTRL_LINK_FLAG - This bit should only set when SCSI_CTRL_LINK is set and  *	causes a SCSI_LINKED_FLAGED_CMD_COMPLETE to be returned instead of  *	a SCSI_LINKED_CMD_COMPLETE.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_CTRL_LINK
value|0x01
end_define

begin_comment
comment|/* Link commands (no bus free phase) */
end_comment

begin_define
define|#
directive|define
name|SCSI_CTRL_LINK_INTR
value|0x02
end_define

begin_comment
comment|/* Interrupt after linked command */
end_comment

begin_comment
comment|/*  * The standard group0 6-byte SCSI control block.  Note that the   * fields between highAddr and blockCount inclusive are command dependent.  * The definitions Addr and BlockCount cover most of the commands we will  * use.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ScsiGroup0Cmd
block|{
name|u_char
name|command
decl_stmt|;
comment|/* command code, defined below.  The 					 * upper three bits of this are zero 					 * to indicate the control block is 					 * only 6 bytes long */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_char
name|unitNumber
range|:
literal|3
decl_stmt|;
comment|/* Logical Unit (LUN) to which to 					 * pass the command.  The device 					 * has already been selected using 					 * the "targetID" bit. */
name|u_char
name|highAddr
range|:
literal|5
decl_stmt|;
comment|/* High bits of address */
else|#
directive|else
name|u_char
name|highAddr
range|:
literal|5
decl_stmt|;
comment|/* High bits of address */
name|u_char
name|unitNumber
range|:
literal|3
decl_stmt|;
comment|/* Logical Unit (LUN) to which to 					 * pass the command.  The device 					 * has already been selected using 					 * the "targetID" bit. */
endif|#
directive|endif
name|u_char
name|midAddr
decl_stmt|;
comment|/* Middle bits of address */
name|u_char
name|lowAddr
decl_stmt|;
comment|/* Low bits of address */
name|u_char
name|blockCount
decl_stmt|;
comment|/* Blocks to transfer */
name|u_char
name|control
decl_stmt|;
comment|/* See flags for common bits */
block|}
name|ScsiGroup0Cmd
typedef|;
end_typedef

begin_comment
comment|/*  * Format of a SCSI_START_STOP command. This is a group 0 command, but  * the command contents are different.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ScsiStartStopCmd
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_char
name|command
decl_stmt|;
comment|/* command code, defined below.  The 					 * upper three bits of this are zero 					 * to indicate the control block is 					 * only 6 bytes long */
name|u_char
name|unitNumber
range|:
literal|3
decl_stmt|;
comment|/* Logical Unit (LUN) to which to 					 * pass the command.  The device 					 * has already been selected using 					 * the "targetID" bit. */
name|u_char
name|pad1
range|:
literal|4
decl_stmt|;
comment|/* Reserved */
name|u_char
name|immed
range|:
literal|1
decl_stmt|;
comment|/* Immediate status bit */
name|u_char
name|pad2
decl_stmt|;
comment|/* Reserved */
name|u_char
name|pad3
decl_stmt|;
comment|/* Reserved */
name|u_char
name|pad4
range|:
literal|6
decl_stmt|;
comment|/* Reserved */
name|u_char
name|loadEject
range|:
literal|1
decl_stmt|;
comment|/* Load or eject medium */
name|u_char
name|start
range|:
literal|1
decl_stmt|;
comment|/* Start or stop medium */
name|u_char
name|control
decl_stmt|;
comment|/* See flags for common bits */
else|#
directive|else
name|u_char
name|command
decl_stmt|;
comment|/* command code, defined below.  The 					 * upper three bits of this are zero 					 * to indicate the control block is 					 * only 6 bytes long */
name|u_char
name|immed
range|:
literal|1
decl_stmt|;
comment|/* Immediate status bit */
name|u_char
name|pad1
range|:
literal|4
decl_stmt|;
comment|/* Reserved */
name|u_char
name|unitNumber
range|:
literal|3
decl_stmt|;
comment|/* Logical Unit (LUN) to which to 					 * pass the command.  The device 					 * has already been selected using 					 * the "targetID" bit. */
name|u_char
name|pad2
decl_stmt|;
comment|/* Reserved */
name|u_char
name|pad3
decl_stmt|;
comment|/* Reserved */
name|u_char
name|start
range|:
literal|1
decl_stmt|;
comment|/* Start or stop medium */
name|u_char
name|loadEject
range|:
literal|1
decl_stmt|;
comment|/* Load or eject medium */
name|u_char
name|pad4
range|:
literal|6
decl_stmt|;
comment|/* Reserved */
name|u_char
name|control
decl_stmt|;
comment|/* See flags for common bits */
endif|#
directive|endif
block|}
name|ScsiStartStopCmd
typedef|;
end_typedef

begin_comment
comment|/*  * The standard group1 10-byte SCSI control block.  Note that the   * fields between highAddr and blockCount inclusive are command dependent.  * The definitions Addr and BlockCount cover most of the commands we will  * use.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ScsiGroup1Cmd
block|{
name|u_char
name|command
decl_stmt|;
comment|/* command code, defined below.  The 					 * upper three bits of this are zero 					 * to indicate the control block is 					 * only 6 bytes long */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_char
name|unitNumber
range|:
literal|3
decl_stmt|;
comment|/* Logical Unit (LUN) to which to 					 * pass the command.  The device 					 * has already been selected using 					 * the "targetID" bit. */
name|u_char
name|pad1
range|:
literal|5
decl_stmt|;
comment|/* Reserved */
else|#
directive|else
name|u_char
name|pad1
range|:
literal|5
decl_stmt|;
comment|/* Reserved */
name|u_char
name|unitNumber
range|:
literal|3
decl_stmt|;
comment|/* Logical Unit (LUN) to which to 					 * pass the command.  The device 					 * has already been selected using 					 * the "targetID" bit. */
endif|#
directive|endif
name|u_char
name|highAddr
decl_stmt|;
comment|/* High bits of address */
name|u_char
name|midHighAddr
decl_stmt|;
comment|/* Middle high bits of address */
name|u_char
name|midLowAddr
decl_stmt|;
comment|/* Middle low bits of address */
name|u_char
name|lowAddr
decl_stmt|;
comment|/* Low bits of address */
name|u_char
name|pad2
decl_stmt|;
comment|/* Reserved */
name|u_char
name|highBlockCount
decl_stmt|;
comment|/* High bits of blocks to transfer */
name|u_char
name|lowBlockCount
decl_stmt|;
comment|/* Low bits of blocks to transfer */
name|u_char
name|control
decl_stmt|;
comment|/* See flags for common bits */
block|}
name|ScsiGroup1Cmd
typedef|;
end_typedef

begin_comment
comment|/*  * SCSI status completion information.  * This is returned by the device when a command completes.   */
end_comment

begin_define
define|#
directive|define
name|SCSI_STATUS_CHECKCOND
value|0x02
end_define

begin_comment
comment|/* Check Condition (ie., read sense) */
end_comment

begin_define
define|#
directive|define
name|SCSI_STATUS_CONDMET
value|0x04
end_define

begin_comment
comment|/* Condition Met (ie., search worked) */
end_comment

begin_define
define|#
directive|define
name|SCSI_STATUS_BUSY
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_STATUS_INTERMED
value|0x10
end_define

begin_comment
comment|/* Intermediate status sent */
end_comment

begin_define
define|#
directive|define
name|SCSI_STATUS_EXT
value|0x80
end_define

begin_comment
comment|/* Extended status valid */
end_comment

begin_comment
comment|/*  * Sense information provided after some errors.  This is divided into  * two kinds, classes 0-6, and class 7.  This is 30 bytes big to allow  * for the drive specific sense bytes that follow the standard 4 byte header.  *  * For extended sense, this buffer may be cast into another type.  Also  * The actual size of the sense data returned is used to detect what  * kind of tape drive is out there.  Kludgy, but true.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ScsiClass0Sense
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_char
name|valid
range|:
literal|1
decl_stmt|;
comment|/* Sense data is valid */
name|u_char
name|error
range|:
literal|7
decl_stmt|;
comment|/* 3 bits class and 4 bits code */
else|#
directive|else
name|u_char
name|error
range|:
literal|7
decl_stmt|;
comment|/* 3 bits class and 4 bits code */
name|u_char
name|valid
range|:
literal|1
decl_stmt|;
comment|/* Sense data is valid */
endif|#
directive|endif
name|u_char
name|highAddr
decl_stmt|;
comment|/* High byte of block address */
name|u_char
name|midAddr
decl_stmt|;
comment|/* Middle byte of block address */
name|u_char
name|lowAddr
decl_stmt|;
comment|/* Low byte of block address */
name|u_char
name|sense
index|[
literal|26
index|]
decl_stmt|;
comment|/* Target specific sense data */
block|}
name|ScsiClass0Sense
typedef|;
end_typedef

begin_comment
comment|/*  * Definitions for errors in the sense data.  The error field is specified  * as a 3 bit class and 4 bit code, but it is easier to treat it as a  * single 7 bit field.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_NO_SENSE_DATA
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_NOT_READY
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_NOT_LOADED
value|0x09
end_define

begin_define
define|#
directive|define
name|SCSI_INSUF_CAPACITY
value|0x0a
end_define

begin_define
define|#
directive|define
name|SCSI_HARD_DATA_ERROR
value|0x11
end_define

begin_define
define|#
directive|define
name|SCSI_WRITE_PROTECT
value|0x17
end_define

begin_define
define|#
directive|define
name|SCSI_CORRECTABLE_ERROR
value|0x18
end_define

begin_define
define|#
directive|define
name|SCSI_FILE_MARK
value|0x1c
end_define

begin_define
define|#
directive|define
name|SCSI_INVALID_COMMAND
value|0x20
end_define

begin_define
define|#
directive|define
name|SCSI_UNIT_ATTENTION
value|0x30
end_define

begin_define
define|#
directive|define
name|SCSI_END_OF_MEDIA
value|0x34
end_define

begin_comment
comment|/*  * The standard "extended" sense data returned by SCSI devices.  This  * has an error field of 0x70, for a "class 7" error.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ScsiClass7Sense
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_char
name|valid
range|:
literal|1
decl_stmt|;
comment|/* Sense data is valid */
name|u_char
name|error7
range|:
literal|7
decl_stmt|;
comment|/* == 0x70 */
name|u_char
name|pad1
decl_stmt|;
comment|/* Also "segment number" for copy */
name|u_char
name|fileMark
range|:
literal|1
decl_stmt|;
comment|/* File mark on device */
name|u_char
name|endOfMedia
range|:
literal|1
decl_stmt|;
comment|/* End of media reached */
name|u_char
name|badBlockLen
range|:
literal|1
decl_stmt|;
comment|/* Block length mis-match (Exabyte) */
name|u_char
name|pad2
range|:
literal|1
decl_stmt|;
name|u_char
name|key
range|:
literal|4
decl_stmt|;
comment|/* Sense keys defined below */
name|u_char
name|info1
decl_stmt|;
comment|/* Information byte 1 */
name|u_char
name|info2
decl_stmt|;
comment|/* Information byte 2 */
name|u_char
name|info3
decl_stmt|;
comment|/* Information byte 3 */
name|u_char
name|info4
decl_stmt|;
comment|/* Information byte 4 */
name|u_char
name|length
decl_stmt|;
comment|/* Number of additional info bytes */
else|#
directive|else
name|u_char
name|error7
range|:
literal|7
decl_stmt|;
comment|/* == 0x70 */
name|u_char
name|valid
range|:
literal|1
decl_stmt|;
comment|/* Sense data is valid */
name|u_char
name|pad1
decl_stmt|;
comment|/* Also "segment number" for copy */
name|u_char
name|key
range|:
literal|4
decl_stmt|;
comment|/* Sense keys defined below */
name|u_char
name|pad2
range|:
literal|1
decl_stmt|;
name|u_char
name|badBlockLen
range|:
literal|1
decl_stmt|;
comment|/* Block length mis-match (Exabyte) */
name|u_char
name|endOfMedia
range|:
literal|1
decl_stmt|;
comment|/* End of media reached */
name|u_char
name|fileMark
range|:
literal|1
decl_stmt|;
comment|/* File mark on device */
name|u_char
name|info1
decl_stmt|;
comment|/* Information byte 1 */
name|u_char
name|info2
decl_stmt|;
comment|/* Information byte 2 */
name|u_char
name|info3
decl_stmt|;
comment|/* Information byte 3 */
name|u_char
name|info4
decl_stmt|;
comment|/* Information byte 4 */
name|u_char
name|length
decl_stmt|;
comment|/* Number of additional info bytes */
endif|#
directive|endif
block|}
name|ScsiClass7Sense
typedef|;
end_typedef

begin_comment
comment|/* 8 Bytes */
end_comment

begin_comment
comment|/*  * Key values for standardized sense class 7.   */
end_comment

begin_define
define|#
directive|define
name|SCSI_CLASS7_NO_SENSE
value|0
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_RECOVERABLE
value|1
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_NOT_READY
value|2
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_MEDIA_ERROR
value|3
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_HARDWARE_ERROR
value|4
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_ILLEGAL_REQUEST
value|5
end_define

begin_comment
comment|/*  * These seem to have different meanings to different vendors....  */
end_comment

begin_define
define|#
directive|define
name|SCSI_CLASS7_MEDIA_CHANGE
value|6
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_UNIT_ATTN
value|6
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_WRITE_PROTECT
value|7
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_BLANK_CHECK
value|8
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_VENDOR
value|9
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_POWER_UP_FAILURE
value|10
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_ABORT
value|11
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_EQUAL
value|12
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_OVERFLOW
value|13
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_RESERVED_14
value|14
end_define

begin_define
define|#
directive|define
name|SCSI_CLASS7_RESERVED_15
value|15
end_define

begin_comment
comment|/*  * Data return by the SCSI inquiry command.   */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ScsiInquiryData
block|{
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_char
name|type
decl_stmt|;
comment|/* Peripheral Device type. See below. */
name|u_char
name|rmb
range|:
literal|1
decl_stmt|;
comment|/* Removable Medium bit. */
name|u_char
name|qualifier
range|:
literal|7
decl_stmt|;
comment|/* Device type qualifier. */
name|u_char
name|version
decl_stmt|;
comment|/* Version info. */
name|u_char
name|reserved
range|:
literal|4
decl_stmt|;
comment|/* reserved. */
name|u_char
name|format
range|:
literal|4
decl_stmt|;
comment|/* Response format. */
name|u_char
name|length
decl_stmt|;
comment|/* length of data returned. */
name|u_char
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
comment|/* Reserved */
name|u_char
name|flags
decl_stmt|;
comment|/* SCSI II flags (see below) */
name|u_char
name|vendorID
index|[
literal|8
index|]
decl_stmt|;
comment|/* Vendor ID (ASCII) */
name|u_char
name|productID
index|[
literal|16
index|]
decl_stmt|;
comment|/* Product ID (ASCII) */
name|u_char
name|revLevel
index|[
literal|4
index|]
decl_stmt|;
comment|/* Revision level (ASCII) */
name|u_char
name|revData
index|[
literal|8
index|]
decl_stmt|;
comment|/* Revision data (ASCII) */
else|#
directive|else
name|u_char
name|type
decl_stmt|;
comment|/* Peripheral Device type. See below. */
name|u_char
name|qualifier
range|:
literal|7
decl_stmt|;
comment|/* Device type qualifier. */
name|u_char
name|rmb
range|:
literal|1
decl_stmt|;
comment|/* Removable Medium bit. */
name|u_char
name|version
decl_stmt|;
comment|/* Version info. */
name|u_char
name|format
range|:
literal|4
decl_stmt|;
comment|/* Response format. */
name|u_char
name|reserved
range|:
literal|4
decl_stmt|;
comment|/* reserved. */
name|u_char
name|length
decl_stmt|;
comment|/* length of data returned. */
name|u_char
name|reserved2
index|[
literal|2
index|]
decl_stmt|;
comment|/* Reserved */
name|u_char
name|flags
decl_stmt|;
comment|/* SCSI II flags (see below) */
name|u_char
name|vendorID
index|[
literal|8
index|]
decl_stmt|;
comment|/* Vendor ID (ASCII) */
name|u_char
name|productID
index|[
literal|16
index|]
decl_stmt|;
comment|/* Product ID (ASCII) */
name|u_char
name|revLevel
index|[
literal|4
index|]
decl_stmt|;
comment|/* Revision level (ASCII) */
name|u_char
name|revData
index|[
literal|8
index|]
decl_stmt|;
comment|/* Revision data (ASCII) */
endif|#
directive|endif
block|}
name|ScsiInquiryData
typedef|;
end_typedef

begin_comment
comment|/*  * The SCSI Peripheral type ID codes as return by the SCSI_INQUIRY command.  *  * SCSI_DISK_TYPE - Direct Access Device.  * SCSI_TAPE_TYPE - Sequential Access Device.  * SCSI_PRINTER_TYPE - Printer Device.  * SCSI_HOST_TYPE - Processor Device.  * SCSI_WORM_TYPE - Write-Once Read-Multiple Device.  * SCSI_ROM_TYPE - Read-Only Direct Access Device.  * SCSI_SCANNER_TYPE - Scanner device.  * SCSI_OPTICAL_MEM_TYPE - Optical memory device.  * SCSI_MEDIUM_CHANGER_TYPE - Medium changer device.  * SCSI_COMMUNICATIONS_TYPE - Communications device.  * SCSI_NODEVICE_TYPE - Logical Unit not present or implemented.  *  * Note that codes 0xa-0x7e are reserved and 0x80-0xff are vendor unique.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_DISK_TYPE
value|0
end_define

begin_define
define|#
directive|define
name|SCSI_TAPE_TYPE
value|1
end_define

begin_define
define|#
directive|define
name|SCSI_PRINTER_TYPE
value|2
end_define

begin_define
define|#
directive|define
name|SCSI_HOST_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|SCSI_WORM_TYPE
value|4
end_define

begin_define
define|#
directive|define
name|SCSI_ROM_TYPE
value|5
end_define

begin_define
define|#
directive|define
name|SCSI_SCANNER_TYPE
value|6
end_define

begin_define
define|#
directive|define
name|SCSI_OPTICAL_MEM_TYPE
value|7
end_define

begin_define
define|#
directive|define
name|SCSI_MEDIUM_CHANGER_TYPE
value|8
end_define

begin_define
define|#
directive|define
name|SCSI_COMMUNICATIONS_TYPE
value|9
end_define

begin_define
define|#
directive|define
name|SCSI_NODEVICE_TYPE
value|0x7f
end_define

begin_comment
comment|/*  * The SCSI I& II inquiry flags.  *  * SCSI_REL_ADR - Relative addressing supported.  * SCSI_WIDE_32 - 32 bit wide SCSI bus transfers supported.  * SCSI_WIDE_16 - 16 bit wide SCSI bus transfers supported.  * SCSI_SYNC - Synchronous data transfers supported.  * SCSI_LINKED - Linked commands supported.  * SCSI_CMD_QUEUE - Tagged command queuing supported.  * SCSI_SOFT_RESET - Soft RESET alternative suported.  */
end_comment

begin_define
define|#
directive|define
name|SCSI_REL_ADR
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_WIDE_32
value|0x40
end_define

begin_define
define|#
directive|define
name|SCSI_WIDE_16
value|0x20
end_define

begin_define
define|#
directive|define
name|SCSI_SYNC
value|0x10
end_define

begin_define
define|#
directive|define
name|SCSI_LINKED
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_CMD_QUEUE
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_SOFT_RESET
value|0x01
end_define

begin_comment
comment|/*  * Standard header for SCSI_MODE_SENSE and SCSI_MODE_SELECT commands for tapes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ScsiTapeModeSelectHdr
block|{
name|u_char
name|len
decl_stmt|;
comment|/* length */
name|u_char
name|media
decl_stmt|;
comment|/* media type */
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
name|u_char
name|writeprot
range|:
literal|1
decl_stmt|;
comment|/* Write protected media */
name|u_char
name|bufferedMode
range|:
literal|3
decl_stmt|;
comment|/* Type of buffer to be done. */
name|u_char
name|speed
range|:
literal|4
decl_stmt|;
comment|/* Drive speed. */
else|#
directive|else
name|u_char
name|speed
range|:
literal|4
decl_stmt|;
comment|/* Drive speed. */
name|u_char
name|bufferedMode
range|:
literal|3
decl_stmt|;
comment|/* Type of buffer to be done. */
name|u_char
name|writeprot
range|:
literal|1
decl_stmt|;
comment|/* Write protected media */
endif|#
directive|endif
name|u_char
name|length
decl_stmt|;
comment|/* Block descriptor length. */
name|u_char
name|density
decl_stmt|;
comment|/* tape density code */
name|u_char
name|blocks_2
decl_stmt|;
comment|/* number of blocks (MSB) */
name|u_char
name|blocks_1
decl_stmt|;
comment|/* number of blocks */
name|u_char
name|blocks_0
decl_stmt|;
comment|/* number of blocks (LSB) */
name|u_char
name|reserved
decl_stmt|;
comment|/* */
name|u_char
name|block_size2
decl_stmt|;
comment|/* Tape block size (MSB) */
name|u_char
name|block_size1
decl_stmt|;
comment|/* Tape block size */
name|u_char
name|block_size0
decl_stmt|;
comment|/* Tape block size (LSB) */
name|u_char
name|vendor
index|[
literal|6
index|]
decl_stmt|;
comment|/* vendor specific data */
block|}
name|ScsiTapeModeSelectHdr
typedef|;
end_typedef

begin_comment
comment|/*  * Definitions of SCSI messages.  *  * SCSI_COMMAND_COMPLETE - After a command has completed, successfully  *	or not, this is returned to the host from the target.  *  * SCSI_EXTENDED_MSG - Indicates that a multi-byte message is being sent.  *  * The following messages are used with connect/disconnect:  * SCSI_SAVE_DATA_POINTER - Sent from target to host to request saving  *	of current DMA address and count.  Indicates a pending dis-connect.  * SCSI_RESTORE_POINTER - Sent from the target to the host to request  *	restoring pointers saved before a disconnect  * SCSI_DISCONNECT - Sent from the target to the host to disconnect.  * SCSI_ABORT - Sent from the host to the target to abort current request.  * SCSI_MESSAGE_REJECT -  Indicates receipt, by either host or target, of  *	an unimplemented message.  * SCSI_NO_OP - Sent from host to target if it has no real message to send.  * SCSI_MESSAGE_PARITY_ERROR - Sent from host to target on message parity error  * SCSI_BUS_RESET - Sent from host to target to reset all current I/O  *  * SCSI_IDENTIFY - The low order two bits of this message type indicate  *	the Logical Unit of the Target which is requesting a reconnect.  * SCSI_DIS_REC_IDENTIFY - Sent from the host to a target to indicate  *	is supports connect/dis-connect  *	  */
end_comment

begin_define
define|#
directive|define
name|SCSI_COMMAND_COMPLETE
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_EXTENDED_MSG
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_SAVE_DATA_POINTER
value|0x02
end_define

begin_define
define|#
directive|define
name|SCSI_RESTORE_POINTERS
value|0x03
end_define

begin_define
define|#
directive|define
name|SCSI_DISCONNECT
value|0x04
end_define

begin_define
define|#
directive|define
name|SCSI_ABORT
value|0x06
end_define

begin_define
define|#
directive|define
name|SCSI_MESSAGE_REJECT
value|0x07
end_define

begin_define
define|#
directive|define
name|SCSI_NO_OP
value|0x08
end_define

begin_define
define|#
directive|define
name|SCSI_MESSAGE_PARITY_ERROR
value|0x09
end_define

begin_define
define|#
directive|define
name|SCSI_LINKED_CMD_COMPLETE
value|0x0A
end_define

begin_define
define|#
directive|define
name|SCSI_LINKED_FLAGED_CMD_COMPLETE
value|0x0B
end_define

begin_define
define|#
directive|define
name|SCSI_BUS_RESET
value|0x0C
end_define

begin_define
define|#
directive|define
name|SCSI_IDENTIFY
value|0x80
end_define

begin_define
define|#
directive|define
name|SCSI_DIS_REC_IDENTIFY
value|0xc0
end_define

begin_comment
comment|/*  * Extended message types (2nd byte of SCSI_EXTENDED_MSG).  */
end_comment

begin_define
define|#
directive|define
name|SCSI_MODIFY_DATA_PTR
value|0x00
end_define

begin_define
define|#
directive|define
name|SCSI_SYNCHRONOUS_XFER
value|0x01
end_define

begin_define
define|#
directive|define
name|SCSI_EXTENDED_IDENTIFY
value|0x02
end_define

begin_comment
comment|/* only in SCSI I */
end_comment

begin_define
define|#
directive|define
name|SCSI_WIDE_XFER
value|0x03
end_define

begin_comment
comment|/*  * Driver ioctl's for various scsi operations.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IOCTL_
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Control for SCSI "format" mode.  *  * "Format" mode allows a privileged process to issue direct SCSI  * commands to a drive (it is intended primarily to allow on-line  * formatting).  SDIOCSFORMAT with a non-zero arg will put the drive  * into format mode; a zero arg will take it out.  When in format  * mode, only the process that issued the SDIOCFORMAT can read or  * write the drive.  *  * In format mode, process is expected to  *	- do SDIOCSCSICOMMAND to supply cdb for next SCSI op  *	- do read or write as appropriate for cdb  *	- if i/o error, optionally do SDIOCSENSE to get completion  *	  status and sense data from last scsi operation.  */
end_comment

begin_struct
struct|struct
name|scsi_fmt_cdb
block|{
name|int
name|len
decl_stmt|;
comment|/* cdb length (in bytes) */
name|u_char
name|cdb
index|[
literal|28
index|]
decl_stmt|;
comment|/* cdb to use on next read/write */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_fmt_sense
block|{
name|u_int
name|status
decl_stmt|;
comment|/* completion status of last op */
name|u_char
name|sense
index|[
literal|32
index|]
decl_stmt|;
comment|/* sense data (if any) from last op */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SDIOCSFORMAT
value|_IOW('S', 0x1, int)
end_define

begin_define
define|#
directive|define
name|SDIOCGFORMAT
value|_IOR('S', 0x2, int)
end_define

begin_define
define|#
directive|define
name|SDIOCSCSICOMMAND
value|_IOW('S', 0x3, struct scsi_fmt_cdb)
end_define

begin_define
define|#
directive|define
name|SDIOCSENSE
value|_IOR('S', 0x4, struct scsi_fmt_sense)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_comment
comment|/*  * Routines.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|scsiGroup0Cmd
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scsiGroup1Cmd
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSI_H */
end_comment

end_unit

