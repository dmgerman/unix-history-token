begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file drm_sarea.h   * \brief SAREA definitions  *  * \author Michel Dänzer<michel@daenzer.net>  */
end_comment

begin_comment
comment|/*  * Copyright 2002 Tungsten Graphics, Inc., Cedar Park, Texas.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * TUNGSTEN GRAPHICS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DRM_SAREA_H_
end_ifndef

begin_define
define|#
directive|define
name|_DRM_SAREA_H_
end_define

begin_comment
comment|/** Maximum number of drawables in the SAREA */
end_comment

begin_define
define|#
directive|define
name|SAREA_MAX_DRAWABLES
value|256
end_define

begin_comment
comment|/** SAREA drawable */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_sarea_drawable
block|{
name|unsigned
name|int
name|stamp
decl_stmt|;
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
name|drm_sarea_drawable_t
typedef|;
end_typedef

begin_comment
comment|/** SAREA frame */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_sarea_frame
block|{
name|unsigned
name|int
name|x
decl_stmt|;
name|unsigned
name|int
name|y
decl_stmt|;
name|unsigned
name|int
name|width
decl_stmt|;
name|unsigned
name|int
name|height
decl_stmt|;
name|unsigned
name|int
name|fullscreen
decl_stmt|;
block|}
name|drm_sarea_frame_t
typedef|;
end_typedef

begin_comment
comment|/** SAREA */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|drm_sarea
block|{
comment|/** first thing is always the DRM locking structure */
name|drm_hw_lock_t
name|lock
decl_stmt|;
comment|/** \todo Use readers/writer lock for drm_sarea::drawable_lock */
name|drm_hw_lock_t
name|drawable_lock
decl_stmt|;
name|drm_sarea_drawable_t
name|drawableTable
index|[
name|SAREA_MAX_DRAWABLES
index|]
decl_stmt|;
comment|/**< drawables */
name|drm_sarea_frame_t
name|frame
decl_stmt|;
comment|/**< frame */
name|drm_context_t
name|dummy_context
decl_stmt|;
block|}
name|drm_sarea_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DRM_SAREA_H_ */
end_comment

end_unit

