begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * CDDL HEADER START  *  * This file and its contents are supplied under the terms of the  * Common Development and Distribution License ("CDDL"), version 1.0.  * You may only use this file in accordance with the terms of version  * 1.0 of the CDDL.  *  * A full copy of the text of the CDDL should have accompanied this  * source.  A copy of the CDDL is also available via the Internet at  * http://www.illumos.org/license/CDDL.  *  * CDDL HEADER END  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2013 by Delphix. All rights reserved.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DSL_BOOKMARK_H
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DSL_BOOKMARK_H
end_define

begin_include
include|#
directive|include
file|<sys/zfs_context.h>
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
struct_decl|struct
name|dsl_pool
struct_decl|;
struct_decl|struct
name|dsl_dataset
struct_decl|;
comment|/*  * On disk zap object.  */
typedef|typedef
struct|struct
name|zfs_bookmark_phys
block|{
name|uint64_t
name|zbm_guid
decl_stmt|;
comment|/* guid of bookmarked dataset */
name|uint64_t
name|zbm_creation_txg
decl_stmt|;
comment|/* birth transaction group */
name|uint64_t
name|zbm_creation_time
decl_stmt|;
comment|/* bookmark creation time */
block|}
name|zfs_bookmark_phys_t
typedef|;
name|int
name|dsl_bookmark_create
parameter_list|(
name|nvlist_t
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
name|int
name|dsl_get_bookmarks
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
name|int
name|dsl_get_bookmarks_impl
parameter_list|(
name|dsl_dataset_t
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
name|int
name|dsl_bookmark_destroy
parameter_list|(
name|nvlist_t
modifier|*
parameter_list|,
name|nvlist_t
modifier|*
parameter_list|)
function_decl|;
name|int
name|dsl_bookmark_lookup
parameter_list|(
name|struct
name|dsl_pool
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|dsl_dataset
modifier|*
parameter_list|,
name|zfs_bookmark_phys_t
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
comment|/* _SYS_DSL_BOOKMARK_H */
end_comment

end_unit

