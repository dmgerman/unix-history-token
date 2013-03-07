begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  *  * Copyright 2008-2009 VMware, Inc., Palo Alto, CA., USA  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the  * "Software"), to deal in the Software without restriction, including  * without limitation the rights to use, copy, modify, merge, publish,  * distribute, sub license, and/or sell copies of the Software, and to  * permit persons to whom the Software is furnished to do so, subject to  * the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS, AUTHORS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM,  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE  * USE OR OTHER DEALINGS IN THE SOFTWARE.  *  **************************************************************************/
end_comment

begin_comment
comment|/*  * Authors: Thomas Hellstrom<thellstrom-at-vmware-dot-com>  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DRM_GLOBAL_H_
end_ifndef

begin_define
define|#
directive|define
name|_DRM_GLOBAL_H_
end_define

begin_enum
enum|enum
name|drm_global_types
block|{
name|DRM_GLOBAL_TTM_MEM
init|=
literal|0
block|,
name|DRM_GLOBAL_TTM_BO
block|,
name|DRM_GLOBAL_TTM_OBJECT
block|,
name|DRM_GLOBAL_NUM
block|}
enum|;
end_enum

begin_struct
struct|struct
name|drm_global_reference
block|{
name|enum
name|drm_global_types
name|global_type
decl_stmt|;
name|size_t
name|size
decl_stmt|;
name|void
modifier|*
name|object
decl_stmt|;
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|drm_global_reference
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|release
function_decl|)
parameter_list|(
name|struct
name|drm_global_reference
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|drm_global_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|drm_global_release
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|drm_global_item_ref
parameter_list|(
name|struct
name|drm_global_reference
modifier|*
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|drm_global_item_unref
parameter_list|(
name|struct
name|drm_global_reference
modifier|*
name|ref
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_DRM_GLOBAL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

