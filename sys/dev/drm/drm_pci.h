begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file drm_pci.h  * \brief PCI consistent, DMA-accessible memory functions.  *  * \author Eric Anholt<anholt@FreeBSD.org>  */
end_comment

begin_comment
comment|/*  * Copyright 2003 Eric Anholt.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sublicense,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the next  * paragraph) shall be included in all copies or substantial portions of the  * Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE  * AUTHOR BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION  * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"dev/drm/drmP.h"
end_include

begin_comment
comment|/**********************************************************************/
end_comment

begin_comment
comment|/** \name PCI memory */
end_comment

begin_comment
comment|/*@{*/
end_comment

begin_comment
comment|/**  * \brief Allocate a physically contiguous DMA-accessible consistent   * memory block.  */
end_comment

begin_function
name|void
modifier|*
name|DRM
function|(
name|pci_alloc
function|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|size_t
name|size
parameter_list|,
name|size_t
name|align
parameter_list|,
name|dma_addr_t
name|maxaddr
parameter_list|,
name|dma_addr_t
modifier|*
name|busaddr
parameter_list|)
block|{
name|void
modifier|*
name|vaddr
decl_stmt|;
name|vaddr
operator|=
name|contigmalloc
argument_list|(
name|size
argument_list|,
name|DRM
argument_list|(
name|M_DRM
argument_list|)
argument_list|,
name|M_WAITOK
argument_list|,
literal|0ul
argument_list|,
name|maxaddr
argument_list|,
name|align
argument_list|,
literal|0
argument_list|)
expr_stmt|;
operator|*
name|busaddr
operator|=
name|vtophys
argument_list|(
name|vaddr
argument_list|)
expr_stmt|;
return|return
name|vaddr
return|;
block|}
end_function

begin_comment
comment|/**  * \brief Free a DMA-accessible consistent memory block.  */
end_comment

begin_function
name|void
name|DRM
function|(
name|pci_free
function|)
parameter_list|(
name|drm_device_t
modifier|*
name|dev
parameter_list|,
name|size_t
name|size
parameter_list|,
name|void
modifier|*
name|vaddr
parameter_list|,
name|dma_addr_t
name|busaddr
parameter_list|)
block|{
if|#
directive|if
name|__FreeBSD_version
operator|>
literal|500000
name|contigfree
argument_list|(
name|vaddr
argument_list|,
name|size
argument_list|,
name|DRM
argument_list|(
name|M_DRM
argument_list|)
argument_list|)
expr_stmt|;
comment|/* Not available on 4.x */
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*@}*/
end_comment

end_unit

