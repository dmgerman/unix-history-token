begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_PLISTVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_PLISTVAR_H_
end_define

begin_include
include|#
directive|include
file|"bhnd_nvram_plist.h"
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|bhnd_nvram_plist_entry_list
argument_list|,
name|bhnd_nvram_plist_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvram_plist_entry
name|bhnd_nvram_plist_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|bhnd_nvram_plist_entry_list
name|bhnd_nvram_plist_entry_list
typedef|;
end_typedef

begin_comment
comment|/**  * NVRAM property.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_prop
block|{
specifier|volatile
name|u_int
name|refs
decl_stmt|;
comment|/**< refcount */
name|char
modifier|*
name|name
decl_stmt|;
comment|/**< property name */
name|bhnd_nvram_val
modifier|*
name|val
decl_stmt|;
comment|/**< property value */
block|}
struct|;
end_struct

begin_comment
comment|/**  * NVRAM property list entry.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_plist_entry
block|{
name|bhnd_nvram_prop
modifier|*
name|prop
decl_stmt|;
name|TAILQ_ENTRY
argument_list|(
argument|bhnd_nvram_plist_entry
argument_list|)
name|pl_link
expr_stmt|;
name|LIST_ENTRY
argument_list|(
argument|bhnd_nvram_plist_entry
argument_list|)
name|pl_hash_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * NVRAM property list.  *   * Provides an ordered list of property values.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_plist
block|{
specifier|volatile
name|u_int
name|refs
decl_stmt|;
comment|/**< refcount */
name|TAILQ_HEAD
argument_list|(
argument_list|,
argument|bhnd_nvram_plist_entry
argument_list|)
name|entries
expr_stmt|;
comment|/**< all properties */
name|size_t
name|num_entries
decl_stmt|;
comment|/**< entry count */
name|bhnd_nvram_plist_entry_list
name|names
index|[
literal|16
index|]
decl_stmt|;
comment|/**< name-based hash table */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_PLISTVAR_H_ */
end_comment

end_unit

