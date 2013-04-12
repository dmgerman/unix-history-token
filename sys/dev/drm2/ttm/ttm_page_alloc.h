begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) Red Hat Inc.   * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sub license,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL  * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Authors: Dave Airlie<airlied@redhat.com>  *          Jerome Glisse<jglisse@redhat.com>  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TTM_PAGE_ALLOC
end_ifndef

begin_define
define|#
directive|define
name|TTM_PAGE_ALLOC
end_define

begin_include
include|#
directive|include
file|<dev/drm2/ttm/ttm_bo_driver.h>
end_include

begin_include
include|#
directive|include
file|<dev/drm2/ttm/ttm_memory.h>
end_include

begin_comment
comment|/**  * Initialize pool allocator.  */
end_comment

begin_function_decl
name|int
name|ttm_page_alloc_init
parameter_list|(
name|struct
name|ttm_mem_global
modifier|*
name|glob
parameter_list|,
name|unsigned
name|max_pages
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Free pool allocator.  */
end_comment

begin_function_decl
name|void
name|ttm_page_alloc_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_pool_populate:  *  * @ttm: The struct ttm_tt to contain the backing pages.  *  * Add backing pages to all of @ttm  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_pool_populate
parameter_list|(
name|struct
name|ttm_tt
modifier|*
name|ttm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ttm_pool_unpopulate:  *  * @ttm: The struct ttm_tt which to free backing pages.  *  * Free all pages of @ttm  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ttm_pool_unpopulate
parameter_list|(
name|struct
name|ttm_tt
modifier|*
name|ttm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Output the state of pools to debugfs file  */
end_comment

begin_comment
comment|/* XXXKIB extern int ttm_page_alloc_debugfs(struct seq_file *m, void *data); */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_SWIOTLB
end_ifdef

begin_comment
comment|/**  * Initialize pool allocator.  */
end_comment

begin_function_decl
name|int
name|ttm_dma_page_alloc_init
parameter_list|(
name|struct
name|ttm_mem_global
modifier|*
name|glob
parameter_list|,
name|unsigned
name|max_pages
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Free pool allocator.  */
end_comment

begin_function_decl
name|void
name|ttm_dma_page_alloc_fini
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Output the state of pools to debugfs file  */
end_comment

begin_function_decl
specifier|extern
name|int
name|ttm_dma_page_alloc_debugfs
parameter_list|(
name|struct
name|seq_file
modifier|*
name|m
parameter_list|,
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ttm_dma_populate
parameter_list|(
name|struct
name|ttm_dma_tt
modifier|*
name|ttm_dma
parameter_list|,
name|struct
name|device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ttm_dma_unpopulate
parameter_list|(
name|struct
name|ttm_dma_tt
modifier|*
name|ttm_dma
parameter_list|,
name|struct
name|device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function
specifier|static
specifier|inline
name|int
name|ttm_dma_page_alloc_init
parameter_list|(
name|struct
name|ttm_mem_global
modifier|*
name|glob
parameter_list|,
name|unsigned
name|max_pages
parameter_list|)
block|{
return|return
operator|-
name|ENODEV
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|ttm_dma_page_alloc_fini
parameter_list|(
name|void
parameter_list|)
block|{
return|return;
block|}
end_function

begin_comment
comment|/* XXXKIB static inline int ttm_dma_page_alloc_debugfs(struct seq_file *m, void *data) { 	return 0; } */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

