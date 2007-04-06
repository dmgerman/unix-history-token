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
name|_SYS_ZFS_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_ZFS_DEBUG_H
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
ifndef|#
directive|ifndef
name|TRUE
define|#
directive|define
name|TRUE
value|1
endif|#
directive|endif
ifndef|#
directive|ifndef
name|FALSE
define|#
directive|define
name|FALSE
value|0
endif|#
directive|endif
comment|/*  * ZFS debugging  */
if|#
directive|if
name|defined
argument_list|(
name|DEBUG
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|_KERNEL
argument_list|)
define|#
directive|define
name|ZFS_DEBUG
endif|#
directive|endif
specifier|extern
name|int
name|zfs_flags
decl_stmt|;
define|#
directive|define
name|ZFS_DEBUG_DPRINTF
value|0x0001
define|#
directive|define
name|ZFS_DEBUG_DBUF_VERIFY
value|0x0002
define|#
directive|define
name|ZFS_DEBUG_DNODE_VERIFY
value|0x0004
define|#
directive|define
name|ZFS_DEBUG_SNAPNAMES
value|0x0008
define|#
directive|define
name|ZFS_DEBUG_MODIFY
value|0x0010
ifdef|#
directive|ifdef
name|ZFS_DEBUG
specifier|extern
name|void
name|__dprintf
parameter_list|(
specifier|const
name|char
modifier|*
name|file
parameter_list|,
specifier|const
name|char
modifier|*
name|func
parameter_list|,
name|int
name|line
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
define|#
directive|define
name|dprintf
parameter_list|(
modifier|...
parameter_list|)
define|\
value|if (zfs_flags& ZFS_DEBUG_DPRINTF) \ 		__dprintf(__FILE__, __func__, __LINE__, __VA_ARGS__)
else|#
directive|else
define|#
directive|define
name|dprintf
parameter_list|(
modifier|...
parameter_list|)
value|((void)0)
endif|#
directive|endif
comment|/* ZFS_DEBUG */
specifier|extern
name|void
name|zfs_panic_recover
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
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
comment|/* _SYS_ZFS_DEBUG_H */
end_comment

end_unit

