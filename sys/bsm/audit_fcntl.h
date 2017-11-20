begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2009 Apple Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1.  Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  * 2.  Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  * 3.  Neither the name of Apple Inc. ("Apple") nor the names of  *     its contributors may be used to endorse or promote products derived  *     from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.   *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BSM_AUDIT_FCNTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_BSM_AUDIT_FCNTL_H_
end_define

begin_comment
comment|/*  * Shared and Solaris-specific: (0-99).  */
end_comment

begin_define
define|#
directive|define
name|BSM_F_DUPFD
value|0
end_define

begin_define
define|#
directive|define
name|BSM_F_GETFD
value|1
end_define

begin_define
define|#
directive|define
name|BSM_F_SETFD
value|2
end_define

begin_define
define|#
directive|define
name|BSM_F_GETFL
value|3
end_define

begin_define
define|#
directive|define
name|BSM_F_SETFL
value|4
end_define

begin_define
define|#
directive|define
name|BSM_F_O_GETLK
value|5
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_SETLK
value|6
end_define

begin_define
define|#
directive|define
name|BSM_F_SETLKW
value|7
end_define

begin_define
define|#
directive|define
name|BSM_F_CHKFL
value|8
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_DUP2FD
value|9
end_define

begin_comment
comment|/* FreeBSD/Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_ALLOCSP
value|10
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FREESP
value|11
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_ISSTREAM
value|13
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_GETLK
value|14
end_define

begin_define
define|#
directive|define
name|BSM_F_PRIV
value|15
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_NPRIV
value|16
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_QUOTACTL
value|17
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_BLOCKS
value|18
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_BLKSIZE
value|19
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_GETOWN
value|23
end_define

begin_define
define|#
directive|define
name|BSM_F_SETOWN
value|24
end_define

begin_define
define|#
directive|define
name|BSM_F_REVOKE
value|25
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_HASREMOTELOCKS
value|26
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FREESP64
value|27
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_ALLOCSP64
value|28
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_GETLK64
value|33
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_SETLK64
value|34
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_SETLKW64
value|35
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_SHARE
value|40
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_UNSHARE
value|41
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_SETLK_NBMAND
value|42
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_SHARE_NBMAND
value|43
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_SETLK64_NBMAND
value|44
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_GETXFL
value|45
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_BADFD
value|46
end_define

begin_comment
comment|/* Solaris-specific. */
end_comment

begin_comment
comment|/*  * FreeBSD-specific (100-199).  */
end_comment

begin_define
define|#
directive|define
name|BSM_F_OGETLK
value|107
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_OSETLK
value|108
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_OSETLKW
value|109
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_SETLK_REMOTE
value|114
end_define

begin_comment
comment|/* FreeBSD-specific. */
end_comment

begin_comment
comment|/*  * Linux-specific (200-299).  */
end_comment

begin_define
define|#
directive|define
name|BSM_F_SETSIG
value|210
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_GETSIG
value|211
end_define

begin_comment
comment|/* Linux-specific. */
end_comment

begin_comment
comment|/*  * Darwin-specific (300-399).  */
end_comment

begin_define
define|#
directive|define
name|BSM_F_CHKCLEAN
value|341
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_PREALLOCATE
value|342
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_SETSIZE
value|343
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_RDADVISE
value|344
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_RDAHEAD
value|345
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_READBOOTSTRAP
value|346
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_WRITEBOOTSTRAP
value|347
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_NOCACHE
value|348
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_LOG2PHYS
value|349
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_GETPATH
value|350
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FULLFSYNC
value|351
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_PATHPKG_CHECK
value|352
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FREEZE_FS
value|353
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_THAW_FS
value|354
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_GLOBAL_NOCACHE
value|355
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_OPENFROM
value|356
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_UNLINKFROM
value|357
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_CHECK_OPENEVT
value|358
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_ADDSIGS
value|359
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_MARKDEPENDENCY
value|360
end_define

begin_comment
comment|/* Darwin-specific. */
end_comment

begin_comment
comment|/*  * Darwin file system specific (400-499).  */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_0
value|400
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_1
value|401
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_2
value|402
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_3
value|403
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_4
value|404
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_5
value|405
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_6
value|406
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_7
value|407
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_8
value|408
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_9
value|409
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_10
value|410
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_11
value|411
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_12
value|412
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_13
value|413
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_14
value|414
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_FS_SPECIFIC_15
value|415
end_define

begin_comment
comment|/* Darwin-fs-specific. */
end_comment

begin_define
define|#
directive|define
name|BSM_F_UNKNOWN
value|0xFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BSM_AUDIT_FCNTL_H_ */
end_comment

end_unit

