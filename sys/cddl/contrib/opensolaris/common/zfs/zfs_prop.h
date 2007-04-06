begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * The contents of this file are subject to the terms of the  * Common Development and Distribution License (the "License").  * You may not use this file except in compliance with the License.  *  * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE  * or http://www.opensolaris.org/os/licensing.  * See the License for the specific language governing permissions  * and limitations under the License.  *  * When distributing Covered Code, include this CDDL HEADER in each  * file and include the License file at usr/src/OPENSOLARIS.LICENSE.  * If applicable, add the following below this CDDL HEADER, with the  * fields enclosed by brackets "[]" replaced with your own identifying  * information: Portions Copyright [yyyy] [name of copyright owner]  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright 2006 Sun Microsystems, Inc.  All rights reserved.  * Use is subject to license terms.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ZFS_PROP_H
end_ifndef

begin_define
define|#
directive|define
name|_ZFS_PROP_H
end_define

begin_pragma
pragma|#
directive|pragma
name|ident
literal|"%Z%%M%	%I%	%E% SMI"
end_pragma

begin_include
include|#
directive|include
file|<sys/fs/zfs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
comment|/*  * For index types (e.g. compression and checksum), we want the numeric value  * in the kernel, but the string value in userland.  */
typedef|typedef
enum|enum
block|{
name|prop_type_number
block|,
comment|/* numeric value */
name|prop_type_string
block|,
comment|/* string value */
name|prop_type_boolean
block|,
comment|/* boolean value */
name|prop_type_index
comment|/* numeric value indexed by string */
block|}
name|zfs_proptype_t
typedef|;
name|zfs_proptype_t
name|zfs_prop_get_type
parameter_list|(
name|zfs_prop_t
parameter_list|)
function_decl|;
name|size_t
name|zfs_prop_width
parameter_list|(
name|zfs_prop_t
parameter_list|,
name|boolean_t
modifier|*
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
comment|/* _ZFS_PROP_H */
end_comment

end_unit

