begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file drm_sarea.h  * \brief SAREA definitions  *  * \author Michel Dï¿½zer<michel@daenzer.net>  */
end_comment

begin_comment
comment|/*-  * Copyright 2002 Tungsten Graphics, Inc., Cedar Park, Texas.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * TUNGSTEN GRAPHICS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

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

begin_include
include|#
directive|include
file|<dev/drm2/drm.h>
end_include

begin_comment
comment|/* SAREA area needs to be at least a page */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha__
argument_list|)
end_if

begin_define
define|#
directive|define
name|SAREA_MAX
value|0x2000
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Intel 830M driver needs at least 8k SAREA */
end_comment

begin_define
define|#
directive|define
name|SAREA_MAX
value|0x2000UL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** Maximum number of drawables in the SAREA */
end_comment

begin_define
define|#
directive|define
name|SAREA_MAX_DRAWABLES
value|256
end_define

begin_define
define|#
directive|define
name|SAREA_DRAWABLE_CLAIMED_ENTRY
value|0x80000000
end_define

begin_comment
comment|/** SAREA drawable */
end_comment

begin_struct
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
struct|;
end_struct

begin_comment
comment|/** SAREA frame */
end_comment

begin_struct
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
struct|;
end_struct

begin_comment
comment|/** SAREA */
end_comment

begin_struct
struct|struct
name|drm_sarea
block|{
comment|/** first thing is always the DRM locking structure */
name|struct
name|drm_hw_lock
name|lock
decl_stmt|;
comment|/** \todo Use readers/writer lock for drm_sarea::drawable_lock */
name|struct
name|drm_hw_lock
name|drawable_lock
decl_stmt|;
name|struct
name|drm_sarea_drawable
name|drawableTable
index|[
name|SAREA_MAX_DRAWABLES
index|]
decl_stmt|;
comment|/**< drawables */
name|struct
name|drm_sarea_frame
name|frame
decl_stmt|;
comment|/**< frame */
name|drm_context_t
name|dummy_context
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|__KERNEL__
end_ifndef

begin_typedef
typedef|typedef
name|struct
name|drm_sarea_drawable
name|drm_sarea_drawable_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_sarea_frame
name|drm_sarea_frame_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|drm_sarea
name|drm_sarea_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DRM_SAREA_H_ */
end_comment

end_unit

