begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1996  *	Berkeley Software Design, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Berkeley Software  *	Design, Inc.  *  * THIS SOFTWARE IS PROVIDED BY Berkeley Software Design, Inc. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL Berkeley Software Design, Inc. BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	BSDI dos.h,v 2.2 1996/04/08 19:32:28 bostic Exp  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * DOS Error codes  */
end_comment

begin_comment
comment|/* MS-DOS version 2 error codes */
end_comment

begin_define
define|#
directive|define
name|FUNC_NUM_IVALID
value|0x01
end_define

begin_define
define|#
directive|define
name|FILE_NOT_FOUND
value|0x02
end_define

begin_define
define|#
directive|define
name|PATH_NOT_FOUND
value|0x03
end_define

begin_define
define|#
directive|define
name|TOO_MANY_OPEN_FILES
value|0x04
end_define

begin_define
define|#
directive|define
name|ACCESS_DENIED
value|0x05
end_define

begin_define
define|#
directive|define
name|HANDLE_INVALID
value|0x06
end_define

begin_define
define|#
directive|define
name|MEM_CB_DEST
value|0x07
end_define

begin_define
define|#
directive|define
name|INSUF_MEM
value|0x08
end_define

begin_define
define|#
directive|define
name|MEM_BLK_ADDR_IVALID
value|0x09
end_define

begin_define
define|#
directive|define
name|ENV_INVALID
value|0x0a
end_define

begin_define
define|#
directive|define
name|FORMAT_INVALID
value|0x0b
end_define

begin_define
define|#
directive|define
name|ACCESS_CODE_INVALID
value|0x0c
end_define

begin_define
define|#
directive|define
name|DATA_INVALID
value|0x0d
end_define

begin_define
define|#
directive|define
name|UNKNOWN_UNIT
value|0x0e
end_define

begin_define
define|#
directive|define
name|DISK_DRIVE_INVALID
value|0x0f
end_define

begin_define
define|#
directive|define
name|ATT_REM_CUR_DIR
value|0x10
end_define

begin_define
define|#
directive|define
name|NOT_SAME_DEV
value|0x11
end_define

begin_define
define|#
directive|define
name|NO_MORE_FILES
value|0x12
end_define

begin_comment
comment|/* mappings to critical-error codes */
end_comment

begin_define
define|#
directive|define
name|WRITE_PROT_DISK
value|0x13
end_define

begin_define
define|#
directive|define
name|UNKNOWN_UNIT_CERR
value|0x14
end_define

begin_define
define|#
directive|define
name|DRIVE_NOT_READY
value|0x15
end_define

begin_define
define|#
directive|define
name|UNKNOWN_COMMAND
value|0x16
end_define

begin_define
define|#
directive|define
name|DATA_ERROR_CRC
value|0x17
end_define

begin_define
define|#
directive|define
name|BAD_REQ_STRUCT_LEN
value|0x18
end_define

begin_define
define|#
directive|define
name|SEEK_ERROR
value|0x19
end_define

begin_define
define|#
directive|define
name|UNKNOWN_MEDIA_TYPE
value|0x1a
end_define

begin_define
define|#
directive|define
name|SECTOR_NOT_FOUND
value|0x1b
end_define

begin_define
define|#
directive|define
name|PRINTER_OUT_OF_PAPER
value|0x1c
end_define

begin_define
define|#
directive|define
name|WRITE_FAULT
value|0x1d
end_define

begin_define
define|#
directive|define
name|READ_FAULT
value|0x1e
end_define

begin_define
define|#
directive|define
name|GENERAL_FAILURE
value|0x1f
end_define

begin_comment
comment|/* MS-DOS version 3 and later extended error codes */
end_comment

begin_define
define|#
directive|define
name|SHARING_VIOLATION
value|0x20
end_define

begin_define
define|#
directive|define
name|FILE_LOCK_VIOLATION
value|0x21
end_define

begin_define
define|#
directive|define
name|DISK_CHANGE_INVALID
value|0x22
end_define

begin_define
define|#
directive|define
name|FCB_UNAVAILABLE
value|0x23
end_define

begin_define
define|#
directive|define
name|SHARING_BUF_EXCEEDED
value|0x24
end_define

begin_define
define|#
directive|define
name|NETWORK_NAME_NOT_FOUND
value|0x35
end_define

begin_define
define|#
directive|define
name|FILE_ALREADY_EXISTS
value|0x50
end_define

begin_define
define|#
directive|define
name|DUPLICATE_REDIR
value|0x55
end_define

begin_comment
comment|/*  * dos attribute byte flags  */
end_comment

begin_define
define|#
directive|define
name|REGULAR_FILE
value|0x00
end_define

begin_define
define|#
directive|define
name|READ_ONLY_FILE
value|0x01
end_define

begin_define
define|#
directive|define
name|HIDDEN_FILE
value|0x02
end_define

begin_define
define|#
directive|define
name|SYSTEM_FILE
value|0x04
end_define

begin_define
define|#
directive|define
name|VOLUME_LABEL
value|0x08
end_define

begin_define
define|#
directive|define
name|DIRECTORY
value|0x10
end_define

begin_define
define|#
directive|define
name|ARCHIVE_NEEDED
value|0x20
end_define

begin_comment
comment|/*  * Internal structure used for get_space()  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|bytes_sector
decl_stmt|;
name|long
name|sectors_cluster
decl_stmt|;
name|long
name|total_clusters
decl_stmt|;
name|long
name|avail_clusters
decl_stmt|;
block|}
name|fsstat_t
typedef|;
end_typedef

begin_comment
comment|/*  * Several DOS structures used by the file redirector  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|DIR
modifier|*
name|dp
decl_stmt|;
name|u_char
modifier|*
name|searchend
decl_stmt|;
name|u_char
name|searchdir
index|[
literal|1024
index|]
decl_stmt|;
block|}
name|search_t
typedef|;
end_typedef

begin_comment
comment|/*  * This is really the format of the DTA.  The file redirector will only  * use the first 21 bytes.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|drive
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_decl_stmt
name|u_char
name|pattern
index|[
literal|11
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|flag
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|reserved1
index|[
literal|4
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|search_t
modifier|*
name|searchptr
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|attr
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|time
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|date
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|size
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|name
index|[
literal|13
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|/*  __attribute__((__packed__))*/
end_comment

begin_empty_stmt
unit|find_block_t
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * DOS directory entry structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|name
index|[
literal|8
index|]
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_decl_stmt
name|u_char
name|ext
index|[
literal|3
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|attr
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|reserved
index|[
literal|10
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|time
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|date
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|start
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_long
name|size
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_empty_stmt
unit|} dosdir_t
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * The Current Drive Structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|path
index|[
literal|0x43
index|]
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_decl_stmt
name|u_short
name|flag
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|dpb_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|dpb_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|redirector_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|redirector_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|paramter_int21
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|offset
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|dummy
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|ifs_driver
index|[
literal|4
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|dummy2
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|/* __attribute__((__packed__))*/
end_comment

begin_empty_stmt
unit|CDS
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|CDS_remote
value|0x8000
end_define

begin_define
define|#
directive|define
name|CDS_ready
value|0x4000
end_define

begin_define
define|#
directive|define
name|CDS_joined
value|0x2000
end_define

begin_define
define|#
directive|define
name|CDS_substed
value|0x1000
end_define

begin_define
define|#
directive|define
name|CDS_notnet
value|0x0080
end_define

begin_comment
comment|/*   * The List of Lists (used to get the CDS and a few other numbers)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|dummy1
index|[
literal|0x16
index|]
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_decl_stmt
name|u_short
name|cds_offset
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|cds_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|dummy2
index|[
literal|6
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|numberbdev
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|lastdrive
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_empty_stmt
unit|} LOL
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * The System File Table  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/*00*/
name|u_short
name|nfiles
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_comment
comment|/* Number file handles referring to this file */
end_comment

begin_comment
comment|/*02*/
end_comment

begin_decl_stmt
name|u_short
name|open_mode
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Open mode (bit 15 -> by FCB) */
end_comment

begin_comment
comment|/*04*/
end_comment

begin_decl_stmt
name|u_char
name|attribute
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*05*/
end_comment

begin_decl_stmt
name|u_short
name|info
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 15 -> remote, 14 ->  dont set date */
end_comment

begin_comment
comment|/*07*/
end_comment

begin_decl_stmt
name|u_char
name|ddr_dpb
index|[
literal|4
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Device Driver Header/Drive Paramter Block */
end_comment

begin_comment
comment|/*0b*/
end_comment

begin_decl_stmt
name|u_short
name|fd
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*0d*/
end_comment

begin_decl_stmt
name|u_short
name|time
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*0f*/
end_comment

begin_decl_stmt
name|u_short
name|date
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*11*/
end_comment

begin_decl_stmt
name|u_long
name|size
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*15*/
end_comment

begin_decl_stmt
name|u_long
name|offset
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*19*/
end_comment

begin_decl_stmt
name|u_short
name|rel_cluster
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1b*/
end_comment

begin_decl_stmt
name|u_short
name|abs_cluster
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1d*/
end_comment

begin_decl_stmt
name|u_char
name|dir_sector
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*1f*/
end_comment

begin_decl_stmt
name|u_char
name|dir_entry
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*20*/
end_comment

begin_decl_stmt
name|u_char
name|name
index|[
literal|8
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*28*/
end_comment

begin_decl_stmt
name|u_char
name|ext
index|[
literal|3
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*2b*/
end_comment

begin_decl_stmt
name|u_char
name|sharesft
index|[
literal|4
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*2f*/
end_comment

begin_decl_stmt
name|u_char
name|sharenet
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*31*/
end_comment

begin_decl_stmt
name|u_short
name|psp
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*33*/
end_comment

begin_decl_stmt
name|u_char
name|share_off
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*35*/
end_comment

begin_decl_stmt
name|u_char
name|local_end
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*37*/
end_comment

begin_decl_stmt
name|u_char
name|ifd_driver
index|[
literal|4
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|/*__attribute__((__packed__))*/
end_comment

begin_empty_stmt
unit|SFT
empty_stmt|;
end_empty_stmt

begin_comment
comment|/*  * Format of PCDOS 4.01 swappable data area  * (Sorry, but you need a wide screen to make this look nice)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|err_crit
name|__attribute__
decl|((
name|packed
decl_stmt|)
block|)
struct|;
end_typedef

begin_comment
comment|/*   00h    BYTE    critical error flag */
end_comment

begin_decl_stmt
name|u_char
name|InDOS
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   01h    BYTE    InDOS flag (count of active INT 21 calls) */
end_comment

begin_decl_stmt
name|u_char
name|err_drive
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   02h    BYTE    ??? drive number or FFh */
end_comment

begin_decl_stmt
name|u_char
name|err_locus
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   03h    BYTE    locus of last error */
end_comment

begin_decl_stmt
name|u_short
name|err_code
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   04h    WORD    extended error code of last error */
end_comment

begin_decl_stmt
name|u_char
name|err_suggest
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   06h    BYTE    suggested action for last error */
end_comment

begin_decl_stmt
name|u_char
name|err_class
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   07h    BYTE    class of last error */
end_comment

begin_decl_stmt
name|u_short
name|err_di
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|err_es
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   08h    DWORD   ES:DI pointer for last error */
end_comment

begin_decl_stmt
name|u_short
name|dta_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|dta_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   0Ch    DWORD   current DTA */
end_comment

begin_decl_stmt
name|u_short
name|psp
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   10h    WORD    current PSP */
end_comment

begin_decl_stmt
name|u_short
name|int_23_sp
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   12h    WORD    stores SP across an INT 23 */
end_comment

begin_decl_stmt
name|u_short
name|wait_status
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   14h    WORD    return code from last process termination (zerod after reading with AH=4Dh) */
end_comment

begin_decl_stmt
name|u_char
name|current_drive
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   16h    BYTE    current drive */
end_comment

begin_decl_stmt
name|u_char
name|break_flag
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   17h    BYTE    extended break flag */
end_comment

begin_decl_stmt
name|u_char
name|unknown1
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   18h  2 BYTEs   ??? */
end_comment

begin_decl_stmt
name|u_short
name|int_21_ax
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   1Ah    WORD    value of AX on call to INT 21 */
end_comment

begin_decl_stmt
name|u_short
name|net_psp
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   1Ch    WORD    PSP segment for sharing/network */
end_comment

begin_decl_stmt
name|u_short
name|net_number
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   1Eh    WORD    network machine number for sharing/network (0000h = us) */
end_comment

begin_decl_stmt
name|u_short
name|first_mem
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   20h    WORD    first usable memory block found when allocating memory */
end_comment

begin_decl_stmt
name|u_short
name|best_mem
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   22h    WORD    best usable memory block found when allocating memory */
end_comment

begin_decl_stmt
name|u_short
name|last_mem
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   24h    WORD    last usable memory block found when allocating memory */
end_comment

begin_decl_stmt
name|u_char
name|unknown
index|[
literal|10
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   26h  2 BYTEs   ??? (don't seem to be referenced) */
end_comment

begin_decl_stmt
name|u_char
name|monthday
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   30h    BYTE    day of month */
end_comment

begin_decl_stmt
name|u_char
name|month
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   31h    BYTE    month */
end_comment

begin_decl_stmt
name|u_short
name|year
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   32h    WORD    year - 1980 */
end_comment

begin_decl_stmt
name|u_short
name|days
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   34h    WORD    number of days since 1-1-1980 */
end_comment

begin_decl_stmt
name|u_char
name|weekday
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   36h    BYTE    day of week (0 = Sunday) */
end_comment

begin_decl_stmt
name|u_char
name|unknown2
index|[
literal|3
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   37h    BYTE    ??? */
end_comment

begin_decl_stmt
name|u_char
name|ddr_head
index|[
literal|30
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   38h 30 BYTEs   device driver request header */
end_comment

begin_decl_stmt
name|u_short
name|ddre_ip
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|ddre_cs
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   58h    DWORD   pointer to device driver entry point (used in calling driver) */
end_comment

begin_decl_stmt
name|u_char
name|ddr_head2
index|[
literal|22
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   5Ch 22 BYTEs   device driver request header */
end_comment

begin_decl_stmt
name|u_char
name|ddr_head3
index|[
literal|30
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   72h 30 BYTEs   device driver request header */
end_comment

begin_decl_stmt
name|u_char
name|unknown3
index|[
literal|6
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   90h  6 BYTEs   ??? */
end_comment

begin_decl_stmt
name|u_char
name|clock_xfer
index|[
literal|6
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   96h  6 BYTEs   CLOCK$ transfer record (see AH=52h) */
end_comment

begin_decl_stmt
name|u_char
name|unknown4
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   9Ch  2 BYTEs   ??? */
end_comment

begin_decl_stmt
name|u_char
name|filename1
index|[
literal|128
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*   9Eh 128 BYTEs  buffer for filename */
end_comment

begin_decl_stmt
name|u_char
name|filename2
index|[
literal|128
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  11Eh 128 BYTEs  buffer for filename */
end_comment

begin_decl_stmt
name|u_char
name|findfirst
index|[
literal|21
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  19Eh 21 BYTEs   findfirst/findnext search data block (see AH=4Eh) */
end_comment

begin_decl_stmt
name|u_char
name|foundentry
index|[
literal|32
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  1B3h 32 BYTEs   directory entry for found file */
end_comment

begin_decl_stmt
name|u_char
name|cds
index|[
literal|88
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  1D3h 88 BYTEs   copy of current directory structure for drive being accessed */
end_comment

begin_decl_stmt
name|u_char
name|fcbname
index|[
literal|11
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  22Bh 11 BYTEs   ??? FCB-format filename */
end_comment

begin_decl_stmt
name|u_char
name|unknown5
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  236h    BYTE    ??? */
end_comment

begin_decl_stmt
name|u_char
name|wildcard
index|[
literal|11
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  237h 11 BYTEs   wildcard destination specification for rename (FCB format) */
end_comment

begin_decl_stmt
name|u_char
name|unknown6
index|[
literal|11
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  242h  2 BYTEs   ??? */
end_comment

begin_decl_stmt
name|u_char
name|attrmask
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  24Dh    BYTE    attribute mask for directory search??? */
end_comment

begin_decl_stmt
name|u_char
name|open_mode
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  24Eh    BYTE    open mode */
end_comment

begin_decl_stmt
name|u_char
name|unknown7
index|[
literal|3
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  24fh    BYTE    ??? */
end_comment

begin_decl_stmt
name|u_char
name|virtual_dos
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  252h    BYTE    flag indicating how DOS function was invoked (00h = direct INT 20/INT 21, FFh = server call AX=5D00h) */
end_comment

begin_decl_stmt
name|u_char
name|unknown8
index|[
literal|9
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  253h    BYTE    ??? */
end_comment

begin_decl_stmt
name|u_char
name|term_type
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  25Ch    BYTE    type of process termination (00h-03h) */
end_comment

begin_decl_stmt
name|u_char
name|unknown9
index|[
literal|3
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  25Dh    BYTE    ??? */
end_comment

begin_decl_stmt
name|u_short
name|dpb_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|dpb_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  260h    DWORD   pointer to Drive Parameter Block for critical error invocation */
end_comment

begin_decl_stmt
name|u_short
name|int21_sf_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|int21_sf_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  264h    DWORD   pointer to stack frame containing user registers on INT 21 */
end_comment

begin_decl_stmt
name|u_short
name|store_sp
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  268h    WORD    stores SP??? */
end_comment

begin_decl_stmt
name|u_short
name|dosdpb_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|dosdpb_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  26Ah    DWORD   pointer to DOS Drive Parameter Block for ??? */
end_comment

begin_decl_stmt
name|u_short
name|disk_buf_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  26Eh    WORD    segment of disk buffer */
end_comment

begin_decl_stmt
name|u_short
name|unknown10
index|[
literal|4
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  270h    WORD    ??? */
end_comment

begin_decl_stmt
name|u_char
name|media_id
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  278h    BYTE    Media ID byte returned by AH=1Bh,1Ch */
end_comment

begin_decl_stmt
name|u_char
name|unknown11
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  279h    BYTE    ??? (doesn't seem to be referenced) */
end_comment

begin_decl_stmt
name|u_short
name|unknown12
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  27Ah    DWORD   pointer to ??? */
end_comment

begin_decl_stmt
name|u_short
name|sft_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|sft_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  27Eh    DWORD   pointer to current SFT */
end_comment

begin_decl_stmt
name|u_short
name|cds_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|cds_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  282h    DWORD   pointer to current directory structure for drive being accessed */
end_comment

begin_decl_stmt
name|u_short
name|fcb_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|fcb_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  286h    DWORD   pointer to caller's FCB */
end_comment

begin_decl_stmt
name|u_short
name|unknown13
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  28Ah    WORD    ??? */
end_comment

begin_decl_stmt
name|u_short
name|jft_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|jft_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  28Eh    DWORD   pointer to a JFT entry in process handle table (see AH=26h) */
end_comment

begin_decl_stmt
name|u_short
name|filename1_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  292h    WORD    offset in DOS CS of first filename argument */
end_comment

begin_decl_stmt
name|u_short
name|filename2_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  294h    WORD    offset in DOS CS of second filename argument */
end_comment

begin_decl_stmt
name|u_short
name|unknown14
index|[
literal|12
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  296h    WORD    ??? */
end_comment

begin_decl_stmt
name|u_short
name|file_offset_lo
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|file_offset_hi
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2AEh    DWORD   offset in file??? */
end_comment

begin_decl_stmt
name|u_short
name|unknown15
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2B2h    WORD    ??? */
end_comment

begin_decl_stmt
name|u_short
name|partial_bytes
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2B4h    WORD    bytes in partial sector */
end_comment

begin_decl_stmt
name|u_short
name|number_sectors
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2B6h    WORD    number of sectors */
end_comment

begin_decl_stmt
name|u_short
name|unknown16
index|[
literal|3
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2B8h    WORD    ??? */
end_comment

begin_decl_stmt
name|u_short
name|nbytes_lo
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|nbytes_hi
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2BEh    DWORD   number of bytes appended to file */
end_comment

begin_decl_stmt
name|u_short
name|qpdb_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|qpdb_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2C2h    DWORD   pointer to ??? disk buffer */
end_comment

begin_decl_stmt
name|u_short
name|asft_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|asft_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2C6h    DWORD   pointer to ??? SFT */
end_comment

begin_decl_stmt
name|u_short
name|int21_bx
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2CAh    WORD    used by INT 21 dispatcher to store caller's BX */
end_comment

begin_decl_stmt
name|u_short
name|int21_ds
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2CCh    WORD    used by INT 21 dispatcher to store caller's DS */
end_comment

begin_decl_stmt
name|u_short
name|temporary
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2CEh    WORD    temporary storage while saving/restoring caller's registers */
end_comment

begin_decl_stmt
name|u_short
name|prevcall_off
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|prevcall_seg
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2D0h    DWORD   pointer to prev call frame (offset 264h) if INT 21 reentered also switched to for duration of INT 24 */
end_comment

begin_decl_stmt
name|u_char
name|unknown17
index|[
literal|9
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2D4h    WORD    ??? */
end_comment

begin_decl_stmt
name|u_short
name|ext_action
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2DDh    WORD    multipurpose open action */
end_comment

begin_decl_stmt
name|u_short
name|ext_attr
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2DFh    WORD    multipurpose attribute */
end_comment

begin_decl_stmt
name|u_short
name|ext_mode
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2E1h    WORD    multipurpose mode */
end_comment

begin_decl_stmt
name|u_char
name|unknown17a
index|[
literal|9
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_short
name|lol_ds
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2ECh    WORD    stores DS during call to [List-of-Lists + 37h] */
end_comment

begin_decl_stmt
name|u_char
name|unknown18
index|[
literal|5
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2EEh    WORD    ??? */
end_comment

begin_decl_stmt
name|u_char
name|usernameptr
index|[
literal|4
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2F3h    DWORD   pointer to user-supplied filename */
end_comment

begin_decl_stmt
name|u_char
name|unknown19
index|[
literal|4
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2F7h    DWORD   pointer to ??? */
end_comment

begin_decl_stmt
name|u_char
name|lol_ss
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2FBh    WORD    stores SS during call to [List-of-Lists + 37h] */
end_comment

begin_decl_stmt
name|u_char
name|lol_sp
index|[
literal|2
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2FDh    WORD    stores SP during call to [List-of-Lists + 37h] */
end_comment

begin_decl_stmt
name|u_char
name|lol_flag
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  2FFh    BYTE    flag, nonzero if stack switched in calling [List-of-Lists+37h] */
end_comment

begin_decl_stmt
name|u_char
name|searchdata
index|[
literal|21
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  300h 21 BYTEs   FindFirst search data for source file(s) of a rename operation (see AH=4Eh) */
end_comment

begin_decl_stmt
name|u_char
name|renameentry
index|[
literal|32
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  315h 32 BYTEs   directory entry for file being renamed */
end_comment

begin_decl_stmt
name|u_char
name|errstack
index|[
literal|331
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  335h 331 BYTEs  critical error stack */
end_comment

begin_decl_stmt
name|u_char
name|diskstack
index|[
literal|384
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  480h 384 BYTEs  disk stack (functions greater than 0Ch, INT 25, INT 26) */
end_comment

begin_decl_stmt
name|u_char
name|iostack
index|[
literal|384
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  600h 384 BYTEs  character I/O stack (functions 01h through 0Ch) */
end_comment

begin_decl_stmt
name|u_char
name|int_21_08_flag
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  780h    BYTE    flag affecting AH=08h (see AH=64h) */
end_comment

begin_decl_stmt
name|u_char
name|unknown20
index|[
literal|11
index|]
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  781h    BYTE    ??? looks like a drive number */
end_comment

begin_comment
unit|}
comment|/*__attribute__((__packed__))*/
end_comment

begin_empty_stmt
unit|SDA
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|exehdr
block|{
name|u_short
name|magic
decl_stmt|;
name|u_short
name|bytes_on_last_page
decl_stmt|;
name|u_short
name|size
decl_stmt|;
comment|/* 512 byte blocks */
name|u_short
name|nreloc
decl_stmt|;
name|u_short
name|hdr_size
decl_stmt|;
comment|/* paragraphs */
name|u_short
name|min_memory
decl_stmt|;
comment|/* paragraphs */
name|u_short
name|max_memory
decl_stmt|;
comment|/* pargraphs */
name|u_short
name|init_ss
decl_stmt|;
name|u_short
name|init_sp
decl_stmt|;
name|u_short
name|checksum
decl_stmt|;
name|u_short
name|init_ip
decl_stmt|;
name|u_short
name|init_cs
decl_stmt|;
name|u_short
name|reloc_offset
decl_stmt|;
name|u_short
name|overlay_num
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|reloc_entry
block|{
name|u_short
name|off
decl_stmt|;
name|u_short
name|seg
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* ** DOS-related shrapnel */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|from_dos_attr
parameter_list|(
name|int
name|attr
parameter_list|)
block|{
return|return
operator|(
operator|(
name|attr
operator|&
name|READ_ONLY_FILE
operator|)
condition|?
literal|0444
else|:
literal|0666
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|int
name|to_dos_attr
parameter_list|(
name|int
name|mode
parameter_list|)
block|{
name|int
name|attr
decl_stmt|;
name|attr
operator|=
operator|(
name|mode
operator|&
literal|0200
operator|)
condition|?
literal|0
else|:
name|READ_ONLY_FILE
expr_stmt|;
name|attr
operator||=
name|S_ISDIR
argument_list|(
name|mode
argument_list|)
condition|?
name|DIRECTORY
else|:
literal|0
expr_stmt|;
return|return
operator|(
name|attr
operator|)
return|;
block|}
end_function

begin_comment
comment|/* prototypes */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dos_return
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* names of DOS return codes */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|dos_ret_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* length of above */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|InDOS
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|diskdrive
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current drive */
end_comment

begin_decl_stmt
name|unsigned
name|long
name|disk_transfer_addr
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|encode_dos_file_time
parameter_list|(
name|time_t
parameter_list|,
name|u_short
modifier|*
parameter_list|,
name|u_short
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|time_t
name|decode_dos_file_time
parameter_list|(
name|u_short
name|dosdate
parameter_list|,
name|u_short
name|dostime
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|translate_filename
parameter_list|(
name|u_char
modifier|*
name|dname
parameter_list|,
name|u_char
modifier|*
name|uname
parameter_list|,
name|int
modifier|*
name|drivep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|parse_filename
parameter_list|(
name|int
name|flag
parameter_list|,
name|char
modifier|*
name|str
parameter_list|,
name|char
modifier|*
name|fcb
parameter_list|,
name|int
modifier|*
name|nb
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dos_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* from exe.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|pspseg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* segment # of PSP */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|curpsp
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|exec_command
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|,
name|int
name|run
parameter_list|,
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|cmdname
parameter_list|,
name|u_short
modifier|*
name|param
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|load_overlay
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|start_segment
parameter_list|,
name|int
name|reloc_segment
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|load_command
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|,
name|int
name|run
parameter_list|,
name|int
name|fd
parameter_list|,
name|char
modifier|*
name|cmdname
parameter_list|,
name|u_short
modifier|*
name|param
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|,
name|char
modifier|*
modifier|*
name|envs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|exec_return
parameter_list|(
name|regcontext_t
modifier|*
name|REGS
parameter_list|,
name|int
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_env
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* from setver.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|setver
parameter_list|(
name|char
modifier|*
name|cmd
parameter_list|,
name|short
name|version
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|short
name|getver
parameter_list|(
name|char
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

end_unit

