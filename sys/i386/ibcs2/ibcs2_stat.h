begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: ibcs2_stat.h,v 1.2 1994/10/26 02:53:03 cgd Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 1994 Scott Bartram  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *      This product includes software developed by Scott Bartram.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBCS2_STAT_H
end_ifndef

begin_define
define|#
directive|define
name|_IBCS2_STAT_H
end_define

begin_include
include|#
directive|include
file|<i386/ibcs2/ibcs2_types.h>
end_include

begin_struct
struct|struct
name|ibcs2_stat
block|{
name|ibcs2_dev_t
name|st_dev
decl_stmt|;
name|ibcs2_ino_t
name|st_ino
decl_stmt|;
name|ibcs2_mode_t
name|st_mode
decl_stmt|;
name|ibcs2_nlink_t
name|st_nlink
decl_stmt|;
name|ibcs2_uid_t
name|st_uid
decl_stmt|;
name|ibcs2_gid_t
name|st_gid
decl_stmt|;
name|ibcs2_dev_t
name|st_rdev
decl_stmt|;
name|ibcs2_off_t
name|st_size
decl_stmt|;
name|ibcs2_time_t
name|st_atim
decl_stmt|;
name|ibcs2_time_t
name|st_mtim
decl_stmt|;
name|ibcs2_time_t
name|st_ctim
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ibcs2_stat_len
value|(sizeof(struct ibcs2_stat))
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IFMT
value|0xf000
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IFIFO
value|0x1000
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IFCHR
value|0x2000
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IFDIR
value|0x4000
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IFBLK
value|0x6000
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IFREG
value|0x8000
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IFSOCK
value|0xc000
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IFNAM
value|0x5000
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IFLNK
value|0xa000
end_define

begin_define
define|#
directive|define
name|IBCS2_S_ISUID
value|0x0800
end_define

begin_define
define|#
directive|define
name|IBCS2_S_ISGID
value|0x0400
end_define

begin_define
define|#
directive|define
name|IBCS2_S_ISVTX
value|0x0200
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IRWXU
value|0x01c0
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IRUSR
value|0x0100
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IWUSR
value|0x0080
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IXUSR
value|0x0040
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IRWXG
value|0x0038
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IRGRP
value|0x0020
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IWGRP
value|0x000f
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IXGRP
value|0x0008
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IRWXO
value|0x0007
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IROTH
value|0x0004
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IWOTH
value|0x0002
end_define

begin_define
define|#
directive|define
name|IBCS2_S_IXOTH
value|0x0001
end_define

begin_define
define|#
directive|define
name|IBCS2_S_ISFIFO
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& IBCS2_S_IFMT) == IBCS2_S_IFIFO)
end_define

begin_define
define|#
directive|define
name|IBCS2_S_ISCHR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& IBCS2_S_IFMT) == IBCS2_S_IFCHR)
end_define

begin_define
define|#
directive|define
name|IBCS2_S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& IBCS2_S_IFMT) == IBCS2_S_IFDIR)
end_define

begin_define
define|#
directive|define
name|IBCS2_S_ISBLK
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& IBCS2_S_IFMT) == IBCS2_S_IFBLK)
end_define

begin_define
define|#
directive|define
name|IBCS2_S_ISREG
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& IBCS2_S_IFMT) == IBCS2_S_IFREG)
end_define

begin_define
define|#
directive|define
name|IBCS2_S_ISSOCK
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& IBCS2_S_IFMT) == IBCS2_S_IFSOCK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBCS2_STAT_H */
end_comment

end_unit

