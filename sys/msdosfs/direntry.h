begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*	$NetBSD: direntry.h,v 1.7 1994/08/21 18:43:54 ws Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (C) 1994 Wolfgang Solfrank.  * Copyright (C) 1994 TooLs GmbH.  * All rights reserved.  * Original code by Paul Popelka (paulp@uts.amdahl.com) (see below).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by TooLs GmbH.  * 4. The name of TooLs GmbH may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY TOOLS GMBH ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * Written by Paul Popelka (paulp@uts.amdahl.com)  *  * You can do anything you want with this software, just don't say you wrote  * it, and don't remove this notice.  *  * This software is provided "as is".  *  * The author supplies this software to be publicly redistributed on the  * understanding that the author is not responsible for the correct  * functioning of this software in any circumstances and is not liable for  * any damages caused by this software.  *  * October 1992  */
end_comment

begin_comment
comment|/*  * Structure of a dos directory entry.  */
end_comment

begin_struct
struct|struct
name|direntry
block|{
name|u_char
name|deName
index|[
literal|8
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
name|u_char
name|deExtension
index|[
literal|3
index|]
decl_stmt|;
comment|/* extension, blank filled */
name|u_char
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
name|u_char
name|deReserved
index|[
literal|10
index|]
decl_stmt|;
comment|/* reserved */
name|u_char
name|deTime
index|[
literal|2
index|]
decl_stmt|;
comment|/* create/last update time */
name|u_char
name|deDate
index|[
literal|2
index|]
decl_stmt|;
comment|/* create/last update date */
name|u_char
name|deStartCluster
index|[
literal|2
index|]
decl_stmt|;
comment|/* starting cluster of file */
name|u_char
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

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|void
name|unix2dostime
name|__P
argument_list|(
operator|(
expr|struct
name|timespec
operator|*
name|tsp
operator|,
name|u_short
operator|*
name|ddp
operator|,
name|u_short
operator|*
name|dtp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|dos2unixtime
name|__P
argument_list|(
operator|(
name|u_short
name|dd
operator|,
name|u_short
name|dt
operator|,
expr|struct
name|timespec
operator|*
name|tsp
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|dos2unixfn
name|__P
argument_list|(
operator|(
name|u_char
name|dn
index|[
literal|11
index|]
operator|,
name|u_char
operator|*
name|un
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unix2dosfn
name|__P
argument_list|(
operator|(
name|u_char
operator|*
name|un
operator|,
name|u_char
name|dn
index|[
literal|11
index|]
operator|,
name|int
name|unlen
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

end_unit

