begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* via_dmablit.h -- PCI DMA BitBlt support for the VIA Unichrome/Pro  *  * Copyright 2005 Thomas Hellstrom.  * All Rights Reserved.  *  * Permission is hereby granted, free of charge, to any person obtaining a  * copy of this software and associated documentation files (the "Software"),  * to deal in the Software without restriction, including without limitation  * the rights to use, copy, modify, merge, publish, distribute, sub license,  * and/or sell copies of the Software, and to permit persons to whom the  * Software is furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice (including the  * next paragraph) shall be included in all copies or substantial portions  * of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS, AUTHORS AND/OR ITS SUPPLIERS BE LIABLE FOR ANY CLAIM,  * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR  * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE  * USE OR OTHER DEALINGS IN THE SOFTWARE.  *  * Authors:  *    Thomas Hellstrom.  *    Register info from Digeo Inc.  */
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
name|_VIA_DMABLIT_H
end_ifndef

begin_define
define|#
directive|define
name|_VIA_DMABLIT_H
end_define

begin_define
define|#
directive|define
name|VIA_NUM_BLIT_ENGINES
value|2
end_define

begin_define
define|#
directive|define
name|VIA_NUM_BLIT_SLOTS
value|8
end_define

begin_struct_decl
struct_decl|struct
name|_drm_via_descriptor
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
struct|struct
name|_drm_via_sg_info
block|{
name|vm_page_t
modifier|*
name|pages
decl_stmt|;
name|unsigned
name|long
name|num_pages
decl_stmt|;
name|struct
name|_drm_via_descriptor
modifier|*
modifier|*
name|desc_pages
decl_stmt|;
name|int
name|num_desc_pages
decl_stmt|;
name|int
name|num_desc
decl_stmt|;
name|unsigned
name|char
modifier|*
name|bounce_buffer
decl_stmt|;
name|dma_addr_t
name|chain_start
decl_stmt|;
name|uint32_t
name|free_on_sequence
decl_stmt|;
name|unsigned
name|int
name|descriptors_per_page
decl_stmt|;
name|int
name|aborted
decl_stmt|;
enum|enum
block|{
name|dr_via_device_mapped
block|,
name|dr_via_desc_pages_alloc
block|,
name|dr_via_pages_locked
block|,
name|dr_via_pages_alloc
block|,
name|dr_via_sg_init
block|}
name|state
enum|;
block|}
name|drm_via_sg_info_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_drm_via_blitq
block|{
name|struct
name|drm_device
modifier|*
name|dev
decl_stmt|;
name|uint32_t
name|cur_blit_handle
decl_stmt|;
name|uint32_t
name|done_blit_handle
decl_stmt|;
name|unsigned
name|serviced
decl_stmt|;
name|unsigned
name|head
decl_stmt|;
name|unsigned
name|cur
decl_stmt|;
name|unsigned
name|num_free
decl_stmt|;
name|unsigned
name|num_outstanding
decl_stmt|;
name|unsigned
name|long
name|end
decl_stmt|;
name|int
name|aborting
decl_stmt|;
name|int
name|is_active
decl_stmt|;
name|drm_via_sg_info_t
modifier|*
name|blits
index|[
name|VIA_NUM_BLIT_SLOTS
index|]
decl_stmt|;
name|struct
name|mtx
name|blit_lock
decl_stmt|;
name|wait_queue_head_t
name|blit_queue
index|[
name|VIA_NUM_BLIT_SLOTS
index|]
decl_stmt|;
name|wait_queue_head_t
name|busy_queue
decl_stmt|;
name|struct
name|task
name|wq
decl_stmt|;
name|struct
name|callout
name|poll_timer
decl_stmt|;
block|}
name|drm_via_blitq_t
typedef|;
end_typedef

begin_comment
comment|/*  *  PCI DMA Registers  *  Channels 2& 3 don't seem to be implemented in hardware.  */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_MAR0
value|0xE40
end_define

begin_comment
comment|/* Memory Address Register of Channel 0 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_DAR0
value|0xE44
end_define

begin_comment
comment|/* Device Address Register of Channel 0 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_BCR0
value|0xE48
end_define

begin_comment
comment|/* Byte Count Register of Channel 0 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_DPR0
value|0xE4C
end_define

begin_comment
comment|/* Descriptor Pointer Register of Channel 0 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_MAR1
value|0xE50
end_define

begin_comment
comment|/* Memory Address Register of Channel 1 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_DAR1
value|0xE54
end_define

begin_comment
comment|/* Device Address Register of Channel 1 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_BCR1
value|0xE58
end_define

begin_comment
comment|/* Byte Count Register of Channel 1 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_DPR1
value|0xE5C
end_define

begin_comment
comment|/* Descriptor Pointer Register of Channel 1 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_MAR2
value|0xE60
end_define

begin_comment
comment|/* Memory Address Register of Channel 2 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_DAR2
value|0xE64
end_define

begin_comment
comment|/* Device Address Register of Channel 2 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_BCR2
value|0xE68
end_define

begin_comment
comment|/* Byte Count Register of Channel 2 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_DPR2
value|0xE6C
end_define

begin_comment
comment|/* Descriptor Pointer Register of Channel 2 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_MAR3
value|0xE70
end_define

begin_comment
comment|/* Memory Address Register of Channel 3 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_DAR3
value|0xE74
end_define

begin_comment
comment|/* Device Address Register of Channel 3 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_BCR3
value|0xE78
end_define

begin_comment
comment|/* Byte Count Register of Channel 3 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_DPR3
value|0xE7C
end_define

begin_comment
comment|/* Descriptor Pointer Register of Channel 3 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_MR0
value|0xE80
end_define

begin_comment
comment|/* Mode Register of Channel 0 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_MR1
value|0xE84
end_define

begin_comment
comment|/* Mode Register of Channel 1 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_MR2
value|0xE88
end_define

begin_comment
comment|/* Mode Register of Channel 2 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_MR3
value|0xE8C
end_define

begin_comment
comment|/* Mode Register of Channel 3 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_CSR0
value|0xE90
end_define

begin_comment
comment|/* Command/Status Register of Channel 0 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_CSR1
value|0xE94
end_define

begin_comment
comment|/* Command/Status Register of Channel 1 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_CSR2
value|0xE98
end_define

begin_comment
comment|/* Command/Status Register of Channel 2 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_CSR3
value|0xE9C
end_define

begin_comment
comment|/* Command/Status Register of Channel 3 */
end_comment

begin_define
define|#
directive|define
name|VIA_PCI_DMA_PTR
value|0xEA0
end_define

begin_comment
comment|/* Priority Type Register */
end_comment

begin_comment
comment|/* Define for DMA engine */
end_comment

begin_comment
comment|/* DPR */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_DPR_EC
value|(1<<1)
end_define

begin_comment
comment|/* end of chain */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_DPR_DDIE
value|(1<<2)
end_define

begin_comment
comment|/* descriptor done interrupt enable */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_DPR_DT
value|(1<<3)
end_define

begin_comment
comment|/* direction of transfer (RO) */
end_comment

begin_comment
comment|/* MR */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_MR_CM
value|(1<<0)
end_define

begin_comment
comment|/* chaining mode */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_MR_TDIE
value|(1<<1)
end_define

begin_comment
comment|/* transfer done interrupt enable */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_MR_HENDMACMD
value|(1<<7)
end_define

begin_comment
comment|/* ? */
end_comment

begin_comment
comment|/* CSR */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_CSR_DE
value|(1<<0)
end_define

begin_comment
comment|/* DMA enable */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_CSR_TS
value|(1<<1)
end_define

begin_comment
comment|/* transfer start */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_CSR_TA
value|(1<<2)
end_define

begin_comment
comment|/* transfer abort */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_CSR_TD
value|(1<<3)
end_define

begin_comment
comment|/* transfer done */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_CSR_DD
value|(1<<4)
end_define

begin_comment
comment|/* descriptor done */
end_comment

begin_define
define|#
directive|define
name|VIA_DMA_DPR_EC
value|(1<<1)
end_define

begin_comment
comment|/* end of chain */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

