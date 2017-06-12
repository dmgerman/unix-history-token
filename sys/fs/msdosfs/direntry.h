begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: direntry.h,v 1.14 1997/11/17 15:36:32 ws Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1994, 1995, 1997 Wolfgang Solfrank.  * Copyright (C) 1994, 1995, 1997 TooLs GmbH.  * All rights reserved.  * Original code by Paul Popelka (paulp@uts.amdahl.com) (see below).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*-  * Written by Paul Popelka (paulp@uts.amdahl.com)  *  * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *  * This software is provided "as is".  *  * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *  * October 1992  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FS_MSDOSFS_DIRENTRY_H_
end_ifndef

begin_define
define|#
directive|define
name|_FS_MSDOSFS_DIRENTRY_H_
end_define

begin_comment
comment|/*  * Structure of a dos directory entry.  */
end_comment

begin_struct
struct|struct
name|direntry
block|{
name|uint8_t
name|deName
index|[
literal|11
index|]
decl_stmt|;
comment|/* filename, blank filled */
define|#
directive|define
name|SLOT_EMPTY
value|0x00
comment|/* slot has never been used */
define|#
directive|define
name|SLOT_E5
value|0x05
comment|/* the real value is 0xe5 */
define|#
directive|define
name|SLOT_DELETED
value|0xe5
comment|/* file in this slot deleted */
name|uint8_t
name|deAttributes
decl_stmt|;
comment|/* file attributes */
define|#
directive|define
name|ATTR_NORMAL
value|0x00
comment|/* normal file */
define|#
directive|define
name|ATTR_READONLY
value|0x01
comment|/* file is readonly */
define|#
directive|define
name|ATTR_HIDDEN
value|0x02
comment|/* file is hidden */
define|#
directive|define
name|ATTR_SYSTEM
value|0x04
comment|/* file is a system file */
define|#
directive|define
name|ATTR_VOLUME
value|0x08
comment|/* entry is a volume label */
define|#
directive|define
name|ATTR_DIRECTORY
value|0x10
comment|/* entry is a directory name */
define|#
directive|define
name|ATTR_ARCHIVE
value|0x20
comment|/* file is new or modified */
name|uint8_t
name|deLowerCase
decl_stmt|;
comment|/* NT VFAT lower case flags */
define|#
directive|define
name|LCASE_BASE
value|0x08
comment|/* filename base in lower case */
define|#
directive|define
name|LCASE_EXT
value|0x10
comment|/* filename extension in lower case */
name|uint8_t
name|deCHundredth
decl_stmt|;
comment|/* hundredth of seconds in CTime */
name|uint8_t
name|deCTime
index|[
literal|2
index|]
decl_stmt|;
comment|/* create time */
name|uint8_t
name|deCDate
index|[
literal|2
index|]
decl_stmt|;
comment|/* create date */
name|uint8_t
name|deADate
index|[
literal|2
index|]
decl_stmt|;
comment|/* access date */
name|uint8_t
name|deHighClust
index|[
literal|2
index|]
decl_stmt|;
comment|/* high bytes of cluster number */
name|uint8_t
name|deMTime
index|[
literal|2
index|]
decl_stmt|;
comment|/* last update time */
name|uint8_t
name|deMDate
index|[
literal|2
index|]
decl_stmt|;
comment|/* last update date */
name|uint8_t
name|deStartCluster
index|[
literal|2
index|]
decl_stmt|;
comment|/* starting cluster of file */
name|uint8_t
name|deFileSize
index|[
literal|4
index|]
decl_stmt|;
comment|/* size of file in bytes */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Structure of a Win95 long name directory entry  */
end_comment

begin_struct
struct|struct
name|winentry
block|{
name|uint8_t
name|weCnt
decl_stmt|;
define|#
directive|define
name|WIN_LAST
value|0x40
define|#
directive|define
name|WIN_CNT
value|0x3f
name|uint8_t
name|wePart1
index|[
literal|10
index|]
decl_stmt|;
name|uint8_t
name|weAttributes
decl_stmt|;
define|#
directive|define
name|ATTR_WIN95
value|0x0f
name|uint8_t
name|weReserved1
decl_stmt|;
name|uint8_t
name|weChksum
decl_stmt|;
name|uint8_t
name|wePart2
index|[
literal|12
index|]
decl_stmt|;
name|uint16_t
name|weReserved2
decl_stmt|;
name|uint8_t
name|wePart3
index|[
literal|4
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|WIN_CHARS
value|13
end_define

begin_comment
comment|/* Number of chars per winentry */
end_comment

begin_comment
comment|/*  * Maximum number of winentries for a filename.  */
end_comment

begin_define
define|#
directive|define
name|WIN_MAXSUBENTRIES
value|20
end_define

begin_comment
comment|/*  * Maximum filename length in Win95  * Note: Must be< sizeof(dirent.d_name)  */
end_comment

begin_define
define|#
directive|define
name|WIN_MAXLEN
value|255
end_define

begin_comment
comment|/*  * This is the format of the contents of the deTime field in the direntry  * structure.  * We don't use bitfields because we don't know how compilers for  * arbitrary machines will lay them out.  */
end_comment

begin_define
define|#
directive|define
name|DT_2SECONDS_MASK
value|0x1F
end_define

begin_comment
comment|/* seconds divided by 2 */
end_comment

begin_define
define|#
directive|define
name|DT_2SECONDS_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DT_MINUTES_MASK
value|0x7E0
end_define

begin_comment
comment|/* minutes */
end_comment

begin_define
define|#
directive|define
name|DT_MINUTES_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|DT_HOURS_MASK
value|0xF800
end_define

begin_comment
comment|/* hours */
end_comment

begin_define
define|#
directive|define
name|DT_HOURS_SHIFT
value|11
end_define

begin_comment
comment|/*  * This is the format of the contents of the deDate field in the direntry  * structure.  */
end_comment

begin_define
define|#
directive|define
name|DD_DAY_MASK
value|0x1F
end_define

begin_comment
comment|/* day of month */
end_comment

begin_define
define|#
directive|define
name|DD_DAY_SHIFT
value|0
end_define

begin_define
define|#
directive|define
name|DD_MONTH_MASK
value|0x1E0
end_define

begin_comment
comment|/* month */
end_comment

begin_define
define|#
directive|define
name|DD_MONTH_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|DD_YEAR_MASK
value|0xFE00
end_define

begin_comment
comment|/* year - 1980 */
end_comment

begin_define
define|#
directive|define
name|DD_YEAR_SHIFT
value|9
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|MAKEFS
argument_list|)
end_if

begin_struct
struct|struct
name|mbnambuf
block|{
name|size_t
name|nb_len
decl_stmt|;
name|int
name|nb_last_id
decl_stmt|;
name|char
name|nb_buf
index|[
name|WIN_MAXLEN
operator|+
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|dirent
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|msdosfsmount
struct_decl|;
end_struct_decl

begin_function_decl
name|char
modifier|*
name|mbnambuf_flush
parameter_list|(
name|struct
name|mbnambuf
modifier|*
name|nbp
parameter_list|,
name|struct
name|dirent
modifier|*
name|dp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mbnambuf_init
parameter_list|(
name|struct
name|mbnambuf
modifier|*
name|nbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mbnambuf_write
parameter_list|(
name|struct
name|mbnambuf
modifier|*
name|nbp
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dos2unixfn
parameter_list|(
name|u_char
name|dn
index|[
literal|11
index|]
parameter_list|,
name|u_char
modifier|*
name|un
parameter_list|,
name|int
name|lower
parameter_list|,
name|struct
name|msdosfsmount
modifier|*
name|pmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unix2dosfn
parameter_list|(
specifier|const
name|u_char
modifier|*
name|un
parameter_list|,
name|u_char
name|dn
index|[
literal|12
index|]
parameter_list|,
name|size_t
name|unlen
parameter_list|,
name|u_int
name|gen
parameter_list|,
name|struct
name|msdosfsmount
modifier|*
name|pmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unix2winfn
parameter_list|(
specifier|const
name|u_char
modifier|*
name|un
parameter_list|,
name|size_t
name|unlen
parameter_list|,
name|struct
name|winentry
modifier|*
name|wep
parameter_list|,
name|int
name|cnt
parameter_list|,
name|int
name|chksum
parameter_list|,
name|struct
name|msdosfsmount
modifier|*
name|pmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|winChkName
parameter_list|(
name|struct
name|mbnambuf
modifier|*
name|nbp
parameter_list|,
specifier|const
name|u_char
modifier|*
name|un
parameter_list|,
name|size_t
name|unlen
parameter_list|,
name|int
name|chksum
parameter_list|,
name|struct
name|msdosfsmount
modifier|*
name|pmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|win2unixfn
parameter_list|(
name|struct
name|mbnambuf
modifier|*
name|nbp
parameter_list|,
name|struct
name|winentry
modifier|*
name|wep
parameter_list|,
name|int
name|chksum
parameter_list|,
name|struct
name|msdosfsmount
modifier|*
name|pmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint8_t
name|winChksum
parameter_list|(
name|uint8_t
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|winSlotCnt
parameter_list|(
specifier|const
name|u_char
modifier|*
name|un
parameter_list|,
name|size_t
name|unlen
parameter_list|,
name|struct
name|msdosfsmount
modifier|*
name|pmp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|winLenFixup
parameter_list|(
specifier|const
name|u_char
modifier|*
name|un
parameter_list|,
name|size_t
name|unlen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL || MAKEFS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_FS_MSDOSFS_DIRENTRY_H_ */
end_comment

end_unit

