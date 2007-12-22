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
name|ZFS_ITER_H
end_ifndef

begin_define
define|#
directive|define
name|ZFS_ITER_H
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
typedef|typedef
struct|struct
name|zfs_sort_column
block|{
name|struct
name|zfs_sort_column
modifier|*
name|sc_next
decl_stmt|;
name|struct
name|zfs_sort_column
modifier|*
name|sc_last
decl_stmt|;
name|zfs_prop_t
name|sc_prop
decl_stmt|;
name|char
modifier|*
name|sc_user_prop
decl_stmt|;
name|boolean_t
name|sc_reverse
decl_stmt|;
block|}
name|zfs_sort_column_t
typedef|;
name|int
name|zfs_for_each
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|boolean_t
parameter_list|,
name|zfs_type_t
parameter_list|,
name|zfs_sort_column_t
modifier|*
parameter_list|,
name|zfs_proplist_t
modifier|*
modifier|*
parameter_list|,
name|zfs_iter_f
parameter_list|,
name|void
modifier|*
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
name|int
name|zfs_add_sort_column
parameter_list|(
name|zfs_sort_column_t
modifier|*
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|boolean_t
parameter_list|)
function_decl|;
name|void
name|zfs_free_sort_columns
parameter_list|(
name|zfs_sort_column_t
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
comment|/* ZFS_ITER_H */
end_comment

end_unit

