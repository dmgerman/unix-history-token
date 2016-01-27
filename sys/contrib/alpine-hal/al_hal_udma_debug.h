begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_udma_debug UDMA Debug  * @ingroup group_udma_api  *  UDMA Debug  *  @{  * @file   al_hal_udma_debug.h  *  * @brief C Header file for the Universal DMA HAL driver for debug APIs  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_UDMA_DEBUG_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_UDMA_DEBUG_H__
end_define

begin_include
include|#
directive|include
file|<al_hal_udma.h>
end_include

begin_comment
comment|/* *INDENT-OFF* */
end_comment

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
comment|/* *INDENT-ON* */
comment|/* UDMA register print helper macros */
define|#
directive|define
name|AL_UDMA_PRINT_REG
parameter_list|(
name|UDMA
parameter_list|,
name|PREFIX
parameter_list|,
name|POSTFIX
parameter_list|,
name|TYPE
parameter_list|,
name|GROUP
parameter_list|,
name|REG
parameter_list|)
define|\
value|al_dbg(PREFIX #REG " = 0x%08x" POSTFIX, al_reg_read32( \&(UDMA->udma_regs->TYPE.GROUP.REG)))
define|#
directive|define
name|AL_UDMA_PRINT_REG_FIELD
parameter_list|( \
name|UDMA
parameter_list|,
name|PREFIX
parameter_list|,
name|POSTFIX
parameter_list|,
name|FMT
parameter_list|,
name|TYPE
parameter_list|,
name|GROUP
parameter_list|,
name|REG
parameter_list|,
name|LBL
parameter_list|,
name|FIELD
parameter_list|)
define|\
value|al_dbg(PREFIX #LBL " = " FMT POSTFIX, al_reg_read32( \&(UDMA->udma_regs->TYPE.GROUP.REG)) \& FIELD ## _MASK>> FIELD ## _SHIFT)
define|#
directive|define
name|AL_UDMA_PRINT_REG_BIT
parameter_list|( \
name|UDMA
parameter_list|,
name|PREFIX
parameter_list|,
name|POSTFIX
parameter_list|,
name|TYPE
parameter_list|,
name|GROUP
parameter_list|,
name|REG
parameter_list|,
name|LBL
parameter_list|,
name|FIELD
parameter_list|)
define|\
value|al_dbg(PREFIX #LBL " = %d" POSTFIX, ((al_reg_read32( \&(UDMA->udma_regs->TYPE.GROUP.REG)) \& FIELD) != 0))
comment|/* UDMA register print mask definitions */
define|#
directive|define
name|AL_UDMA_DEBUG_QUEUE
parameter_list|(
name|n
parameter_list|)
value|AL_BIT(n)
define|#
directive|define
name|AL_UDMA_DEBUG_AXI
value|AL_BIT(DMA_MAX_Q)
define|#
directive|define
name|AL_UDMA_DEBUG_GENERAL
value|AL_BIT(DMA_MAX_Q + 1)
define|#
directive|define
name|AL_UDMA_DEBUG_READ
value|AL_BIT(DMA_MAX_Q + 2)
define|#
directive|define
name|AL_UDMA_DEBUG_WRITE
value|AL_BIT(DMA_MAX_Q + 3)
define|#
directive|define
name|AL_UDMA_DEBUG_DWRR
value|AL_BIT(DMA_MAX_Q + 4)
define|#
directive|define
name|AL_UDMA_DEBUG_RATE_LIMITER
value|AL_BIT(DMA_MAX_Q + 5)
define|#
directive|define
name|AL_UDMA_DEBUG_STREAM_RATE_LIMITER
value|AL_BIT(DMA_MAX_Q + 6)
define|#
directive|define
name|AL_UDMA_DEBUG_COMP
value|AL_BIT(DMA_MAX_Q + 7)
define|#
directive|define
name|AL_UDMA_DEBUG_STAT
value|AL_BIT(DMA_MAX_Q + 8)
define|#
directive|define
name|AL_UDMA_DEBUG_FEATURE
value|AL_BIT(DMA_MAX_Q + 9)
define|#
directive|define
name|AL_UDMA_DEBUG_ALL
value|0xFFFFFFFF
comment|/* Debug functions */
comment|/**  * Print udma registers according to the provided mask  *  * @param udma udma data structure  * @param mask mask that specifies which registers groups to print  * e.g. AL_UDMA_DEBUG_AXI prints AXI registers, AL_UDMA_DEBUG_ALL prints all  * registers  */
name|void
name|al_udma_regs_print
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|unsigned
name|int
name|mask
parameter_list|)
function_decl|;
comment|/**  * Print udma queue software structure  *  * @param udma udma data structure  * @param qid queue index  */
name|void
name|al_udma_q_struct_print
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|uint32_t
name|qid
parameter_list|)
function_decl|;
comment|/** UDMA ring type */
enum|enum
name|al_udma_ring_type
block|{
name|AL_RING_SUBMISSION
block|,
name|AL_RING_COMPLETION
block|}
enum|;
comment|/**  * Print the ring entries for the specified queue index and ring type  * (submission/completion)  *  * @param udma udma data structure  * @param qid queue index  * @param rtype udma ring type  */
name|void
name|al_udma_ring_print
parameter_list|(
name|struct
name|al_udma
modifier|*
name|udma
parameter_list|,
name|uint32_t
name|qid
parameter_list|,
name|enum
name|al_udma_ring_type
name|rtype
parameter_list|)
function_decl|;
comment|/* *INDENT-OFF* */
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* *INDENT-ON* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_UDMA_DEBUG_H__ */
end_comment

begin_comment
comment|/** @} end of UDMA debug group */
end_comment

end_unit

