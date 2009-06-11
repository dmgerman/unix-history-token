begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2007 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_EXTDIRENT_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_EXTDIRENT_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
include|#
directive|include
file|<sys/types.h>
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
comment|/*  * Extended file-system independent directory entry.  This style of  * dirent provides additional informational flag bits for each  * directory entry.  This dirent will be returned instead of the  * standard dirent if a VOP_READDIR() requests dirent flags via  * V_RDDIR_ENTFLAGS, and if the file system supports the flags.  */
typedef|typedef
struct|struct
name|edirent
block|{
name|ino64_t
name|ed_ino
decl_stmt|;
comment|/* "inode number" of entry */
name|off64_t
name|ed_off
decl_stmt|;
comment|/* offset of disk directory entry */
name|uint32_t
name|ed_eflags
decl_stmt|;
comment|/* per-entry flags */
name|unsigned
name|short
name|ed_reclen
decl_stmt|;
comment|/* length of this record */
name|char
name|ed_name
index|[
literal|1
index|]
decl_stmt|;
comment|/* name of file */
block|}
name|edirent_t
typedef|;
define|#
directive|define
name|EDIRENT_RECLEN
parameter_list|(
name|namelen
parameter_list|)
define|\
value|((offsetof(edirent_t, ed_name[0]) + 1 + (namelen) + 7)& ~ 7)
define|#
directive|define
name|EDIRENT_NAMELEN
parameter_list|(
name|reclen
parameter_list|)
define|\
value|((reclen) - (offsetof(edirent_t, ed_name[0])))
comment|/*  * Extended entry flags  *	Extended entries include a bitfield of extra information  *	regarding that entry.  */
define|#
directive|define
name|ED_CASE_CONFLICT
value|0x10
comment|/* Disconsidering case, entry is not unique */
comment|/*  * Extended flags accessor function  */
define|#
directive|define
name|ED_CASE_CONFLICTS
parameter_list|(
name|x
parameter_list|)
value|((x)->ed_eflags& ED_CASE_CONFLICT)
endif|#
directive|endif
comment|/* defined(_KERNEL) */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_EXTDIRENT_H */
end_comment

end_unit

