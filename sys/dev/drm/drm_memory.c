begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  *Copyright 1999 Precision Insight, Inc., Cedar Park, Texas.  * Copyright 2000 VA Linux Systems, Inc., Sunnyvale, California.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL  * VA LINUX SYSTEMS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM, DAMAGES OR  * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,  * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR  * OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Rickard E. (Rik) Faith<faith@valinux.com>  *    Gareth Hughes<gareth@valinux.com>  *  */
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

begin_comment
comment|/** @file drm_memory.c  * Wrappers for kernel memory allocation routines, and MTRR management support.  *  * This file previously implemented a memory consumption tracking system using  * the "area" argument for various different types of allocations, but that  * has been stripped out for now.  */
end_comment

begin_include
include|#
directive|include
file|"dev/drm/drmP.h"
end_include

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_DMA
argument_list|,
literal|"drm_dma"
argument_list|,
literal|"DRM DMA Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_SAREA
argument_list|,
literal|"drm_sarea"
argument_list|,
literal|"DRM SAREA Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_DRIVER
argument_list|,
literal|"drm_driver"
argument_list|,
literal|"DRM DRIVER Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_MAGIC
argument_list|,
literal|"drm_magic"
argument_list|,
literal|"DRM MAGIC Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_IOCTLS
argument_list|,
literal|"drm_ioctls"
argument_list|,
literal|"DRM IOCTL Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_MAPS
argument_list|,
literal|"drm_maps"
argument_list|,
literal|"DRM MAP Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_BUFS
argument_list|,
literal|"drm_bufs"
argument_list|,
literal|"DRM BUFFER Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_SEGS
argument_list|,
literal|"drm_segs"
argument_list|,
literal|"DRM SEGMENTS Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_PAGES
argument_list|,
literal|"drm_pages"
argument_list|,
literal|"DRM PAGES Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_FILES
argument_list|,
literal|"drm_files"
argument_list|,
literal|"DRM FILE Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_QUEUES
argument_list|,
literal|"drm_queues"
argument_list|,
literal|"DRM QUEUE Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_CMDS
argument_list|,
literal|"drm_cmds"
argument_list|,
literal|"DRM COMMAND Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_MAPPINGS
argument_list|,
literal|"drm_mapping"
argument_list|,
literal|"DRM MAPPING Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_BUFLISTS
argument_list|,
literal|"drm_buflists"
argument_list|,
literal|"DRM BUFLISTS Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_AGPLISTS
argument_list|,
literal|"drm_agplists"
argument_list|,
literal|"DRM AGPLISTS Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_CTXBITMAP
argument_list|,
literal|"drm_ctxbitmap"
argument_list|,
literal|"DRM CTXBITMAP Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_SGLISTS
argument_list|,
literal|"drm_sglists"
argument_list|,
literal|"DRM SGLISTS Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_DRAWABLE
argument_list|,
literal|"drm_drawable"
argument_list|,
literal|"DRM DRAWABLE Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_MM
argument_list|,
literal|"drm_sman"
argument_list|,
literal|"DRM MEMORY MANAGER Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|MALLOC_DEFINE
argument_list|(
name|DRM_MEM_HASHTAB
argument_list|,
literal|"drm_hashtab"
argument_list|,
literal|"DRM HASHTABLE Data Structures"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|drm_mem_init
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
name|drm_mem_uninit
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_function
name|void
modifier|*
name|drm_ioremap_wc
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|drm_local_map_t
modifier|*
name|map
parameter_list|)
block|{
return|return
name|pmap_mapdev_attr
argument_list|(
name|map
operator|->
name|offset
argument_list|,
name|map
operator|->
name|size
argument_list|,
name|PAT_WRITE_COMBINING
argument_list|)
return|;
block|}
end_function

begin_function
name|void
modifier|*
name|drm_ioremap
parameter_list|(
name|struct
name|drm_device
modifier|*
name|dev
parameter_list|,
name|drm_local_map_t
modifier|*
name|map
parameter_list|)
block|{
return|return
name|pmap_mapdev
argument_list|(
name|map
operator|->
name|offset
argument_list|,
name|map
operator|->
name|size
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|drm_ioremapfree
parameter_list|(
name|drm_local_map_t
modifier|*
name|map
parameter_list|)
block|{
name|pmap_unmapdev
argument_list|(
operator|(
name|vm_offset_t
operator|)
name|map
operator|->
name|handle
argument_list|,
name|map
operator|->
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|drm_mtrr_add
parameter_list|(
name|unsigned
name|long
name|offset
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|int
name|act
decl_stmt|;
name|struct
name|mem_range_desc
name|mrdesc
decl_stmt|;
name|mrdesc
operator|.
name|mr_base
operator|=
name|offset
expr_stmt|;
name|mrdesc
operator|.
name|mr_len
operator|=
name|size
expr_stmt|;
name|mrdesc
operator|.
name|mr_flags
operator|=
name|flags
expr_stmt|;
name|act
operator|=
name|MEMRANGE_SET_UPDATE
expr_stmt|;
name|strlcpy
argument_list|(
name|mrdesc
operator|.
name|mr_owner
argument_list|,
literal|"drm"
argument_list|,
sizeof|sizeof
argument_list|(
name|mrdesc
operator|.
name|mr_owner
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|mem_range_attr_set
argument_list|(
operator|&
name|mrdesc
argument_list|,
operator|&
name|act
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|drm_mtrr_del
parameter_list|(
name|int
name|__unused
name|handle
parameter_list|,
name|unsigned
name|long
name|offset
parameter_list|,
name|size_t
name|size
parameter_list|,
name|int
name|flags
parameter_list|)
block|{
name|int
name|act
decl_stmt|;
name|struct
name|mem_range_desc
name|mrdesc
decl_stmt|;
name|mrdesc
operator|.
name|mr_base
operator|=
name|offset
expr_stmt|;
name|mrdesc
operator|.
name|mr_len
operator|=
name|size
expr_stmt|;
name|mrdesc
operator|.
name|mr_flags
operator|=
name|flags
expr_stmt|;
name|act
operator|=
name|MEMRANGE_SET_REMOVE
expr_stmt|;
name|strlcpy
argument_list|(
name|mrdesc
operator|.
name|mr_owner
argument_list|,
literal|"drm"
argument_list|,
sizeof|sizeof
argument_list|(
name|mrdesc
operator|.
name|mr_owner
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|mem_range_attr_set
argument_list|(
operator|&
name|mrdesc
argument_list|,
operator|&
name|act
argument_list|)
return|;
block|}
end_function

end_unit

