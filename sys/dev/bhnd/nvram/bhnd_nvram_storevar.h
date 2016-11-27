begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landonf@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *   * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_NVRAM_BHND_NVRAM_STOREVAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_NVRAM_BHND_NVRAM_STOREVAR_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"bhnd_nvram_store.h"
end_include

begin_comment
comment|/** Index is only generated if minimum variable count is met */
end_comment

begin_define
define|#
directive|define
name|NVRAM_IDX_VAR_THRESH
value|15
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_PATH_ALIAS_NONE
value|ULONG_MAX
end_define

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|bhnd_nvstore_paths
argument_list|,
name|bhnd_nvstore_path
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/**  * NVRAM store path.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvstore_path
block|{
name|char
modifier|*
name|path
decl_stmt|;
comment|/** relative path */
name|u_long
name|index
decl_stmt|;
comment|/** aliased path index, or 			    BHND_NVSTORE_PATH_IDX_INVALID */
name|LIST_ENTRY
argument_list|(
argument|bhnd_nvstore_path
argument_list|)
name|dp_link
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * NVRAM store index.  *   * Provides effecient name-based lookup by maintaining an array of cached  * cookiep values, sorted lexicographically by variable name.  */
end_comment

begin_struct
struct|struct
name|bhnd_nvstore_index
block|{
name|size_t
name|num_cookiep
decl_stmt|;
comment|/**< cookiep count */
name|void
modifier|*
name|cookiep
index|[]
decl_stmt|;
comment|/**< cookiep values */
block|}
struct|;
end_struct

begin_comment
comment|/** bhnd nvram store instance state */
end_comment

begin_struct
struct|struct
name|bhnd_nvram_store
block|{
ifdef|#
directive|ifdef
name|_KERNEL
name|struct
name|mtx
name|mtx
decl_stmt|;
else|#
directive|else
name|pthread_mutex_t
name|mtx
decl_stmt|;
endif|#
directive|endif
name|struct
name|bhnd_nvram_data
modifier|*
name|nv
decl_stmt|;
comment|/**< backing data */
name|struct
name|bhnd_nvstore_index
modifier|*
name|idx
decl_stmt|;
comment|/**< index, or NULL */
name|struct
name|bhnd_nvstore_paths
name|paths
decl_stmt|;
comment|/**< paths */
name|nvlist_t
modifier|*
name|pending
decl_stmt|;
comment|/**< uncommitted writes */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
define|\
value|mtx_init(&(sc)->mtx, "BHND NVRAM store lock", NULL, MTX_DEF)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|mtx_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
value|mtx_assert(&(sc)->mtx, what)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|mtx_destroy(&(sc)->mtx)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_INIT
parameter_list|(
name|sc
parameter_list|)
value|do {				\ 	int error = pthread_mutex_init(&(sc)->mtx, NULL);		\ 	if (error)							\ 		BHND_NV_PANIC("pthread_mutex_init() failed: %d",	\ 		    error);						\ } while(0)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK
parameter_list|(
name|sc
parameter_list|)
value|pthread_mutex_lock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_UNLOCK
parameter_list|(
name|sc
parameter_list|)
value|pthread_mutex_unlock(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_DESTROY
parameter_list|(
name|sc
parameter_list|)
value|pthread_mutex_destroy(&(sc)->mtx)
end_define

begin_define
define|#
directive|define
name|BHND_NVSTORE_LOCK_ASSERT
parameter_list|(
name|sc
parameter_list|,
name|what
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_NVRAM_BHND_NVRAM_STOREVAR_H_ */
end_comment

end_unit

