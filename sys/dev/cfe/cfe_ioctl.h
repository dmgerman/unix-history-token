begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: cfe_ioctl.h,v 1.2 2003/02/07 17:52:08 cgd Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright 2000, 2001  * Broadcom Corporation. All rights reserved.  *  * This software is furnished under license and may be used and copied only  * in accordance with the following terms and conditions.  Subject to these  * conditions, you may download, copy, install, use, modify and distribute  * modified or unmodified copies of this software in source and/or binary  * form. No title or ownership is transferred hereby.  *  * 1) Any source code used, modified or distributed must reproduce and  *    retain this copyright notice and list of conditions as they appear in  *    the source file.  *  * 2) No right is granted to use any trade name, trademark, or logo of  *    Broadcom Corporation.  The "Broadcom Corporation" name may not be  *    used to endorse or promote products derived from this software  *    without the prior written permission of Broadcom Corporation.  *  * 3) THIS SOFTWARE IS PROVIDED "AS-IS" AND ANY EXPRESS OR IMPLIED  *    WARRANTIES, INCLUDING BUT NOT LIMITED TO, ANY IMPLIED WARRANTIES OF  *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR  *    NON-INFRINGEMENT ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM BE LIABLE  *    FOR ANY DAMAGES WHATSOEVER, AND IN PARTICULAR, BROADCOM SHALL NOT BE  *    LIABLE FOR DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  *    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  *    OR OTHERWISE), EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *********************************************************************     *  Broadcom Common Firmware Environment (CFE)     *       *  IOCTL definitions			File: cfe_ioctl.h     *       *  IOCTL function numbers and I/O data structures.     *       *  Author:  Mitch Lichtenberg (mpl@broadcom.com)     *       ********************************************************************* */
end_comment

begin_comment
comment|/*  *********************************************************************     *  NVFAM and FLASH stuff     ********************************************************************* */
end_comment

begin_define
define|#
directive|define
name|IOCTL_NVRAM_GETINFO
value|1
end_define

begin_comment
comment|/* return nvram_info_t */
end_comment

begin_define
define|#
directive|define
name|IOCTL_NVRAM_ERASE
value|2
end_define

begin_comment
comment|/* erase sector containing nvram_info_t area */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_ERASE_SECTOR
value|3
end_define

begin_comment
comment|/* erase an arbitrary sector */
end_comment

begin_define
define|#
directive|define
name|IOCTL_FLASH_ERASE_ALL
value|4
end_define

begin_comment
comment|/* Erase the entire flash */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|nvram_info_s
block|{
name|int
name|nvram_offset
decl_stmt|;
comment|/* offset of environment area */
name|int
name|nvram_size
decl_stmt|;
comment|/* size of environment area */
name|int
name|nvram_eraseflg
decl_stmt|;
comment|/* true if we need to erase first */
block|}
name|nvram_info_t
typedef|;
end_typedef

begin_comment
comment|/*  *********************************************************************     *  Ethernet stuff     ********************************************************************* */
end_comment

begin_define
define|#
directive|define
name|IOCTL_ETHER_GETHWADDR
value|1
end_define

begin_comment
comment|/*  *********************************************************************     *  Block device stuff     ********************************************************************* */
end_comment

begin_define
define|#
directive|define
name|IOCTL_BLOCK_GETBLOCKSIZE
value|1
end_define

begin_define
define|#
directive|define
name|IOCTL_BLOCK_GETTOTALBLOCKS
value|2
end_define

end_unit

