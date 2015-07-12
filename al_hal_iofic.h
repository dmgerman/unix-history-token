begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_interrupts Common I/O Fabric Interrupt Controller  * This HAL provides the API for programming the Common I/O Fabric Interrupt  * Controller (IOFIC) found in most of the units attached to the I/O Fabric of  * Alpine platform  *  @{  * @file   al_hal_iofic.h  *  * @brief Header file for the interrupt controller that's embedded in various units  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_IOFIC_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_IOFIC_H__
end_define

begin_include
include|#
directive|include
file|<al_hal_common.h>
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
define|#
directive|define
name|AL_IOFIC_MAX_GROUPS
value|4
comment|/*  * Configurations  */
comment|/**  * Configure the interrupt controller registers, actual interrupts are still  * masked at this stage.  *  * @param regs_base regs pointer to interrupt controller registers  * @param group the interrupt group.  * @param flags flags of Interrupt Control Register  *  * @return 0 on success. -EINVAL otherwise.  */
name|int
name|al_iofic_config
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
comment|/**  * configure the moderation timer resolution for a given group  * Applies for both msix and legacy mode.  *  * @param regs_base pointer to unit registers  * @param group the interrupt group  * @param resolution resolution of the timer interval, the resolution determines the rate  * of decrementing the interval timer, setting value N means that the interval  * timer will be decremented each (N+1) * (0.68) micro seconds.  *  * @return 0 on success. -EINVAL otherwise.  */
name|int
name|al_iofic_moder_res_config
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|,
name|uint8_t
name|resolution
parameter_list|)
function_decl|;
comment|/**  * configure the moderation timer interval for a given legacy interrupt group  *  * @param regs_base regs pointer to unit registers  * @param group the interrupt group  * @param interval between interrupts in resolution units. 0 disable  *  * @return 0 on success. -EINVAL otherwise.  */
name|int
name|al_iofic_legacy_moder_interval_config
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|,
name|uint8_t
name|interval
parameter_list|)
function_decl|;
comment|/**  * configure the moderation timer interval for a given msix vector  *  * @param regs_base pointer to unit registers  * @param group the interrupt group  * @param vector vector index  * @param interval interval between interrupts, 0 disable  *  * @return 0 on success. -EINVAL otherwise.  */
name|int
name|al_iofic_msix_moder_interval_config
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|,
name|uint8_t
name|vector
parameter_list|,
name|uint8_t
name|interval
parameter_list|)
function_decl|;
comment|/** * configure the vmid attributes for a given msix vector. * * @param group the interrupt group * @param vector index * @param vmid the vmid value * @param vmid_en take vmid from the intc * * @return 0 on success. -EINVAL otherwise. */
name|int
name|al_iofic_msix_vmid_attributes_config
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|,
name|uint8_t
name|vector
parameter_list|,
name|uint32_t
name|vmid
parameter_list|,
name|uint8_t
name|vmid_en
parameter_list|)
function_decl|;
comment|/**  * return the offset of the unmask register for a given group.  * this function can be used when the upper layer wants to directly  * access the unmask regiter and bypass the al_iofic_unmask() API.  *  * @param regs_base regs pointer to unit registers  * @param group the interrupt group  * @return the offset of the unmask register.  */
name|uint32_t
name|__iomem
modifier|*
name|al_iofic_unmask_offset_get
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|)
function_decl|;
comment|/**  * unmask specific interrupts for a given group  * this functions guarantees atomic operations, it is performance optimized as  * it will not require read-modify-write. The unmask done using the interrupt  * mask clear register, so it's safe to call it while the mask is changed by  * the HW (auto mask) or another core.  *  * @param regs_base pointer to unit registers  * @param group the interrupt group  * @param mask bitwise of interrupts to unmask, set bits will be unmasked.  */
name|void
name|al_iofic_unmask
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
comment|/**  * mask specific interrupts for a given group  * this functions modifies interrupt mask register, the callee must make sure  * the mask is not changed by another cpu.  *  * @param regs_base pointer to unit registers  * @param group the interrupt group  * @param mask bitwise of interrupts to mask, set bits will be masked.  */
name|void
name|al_iofic_mask
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
comment|/**  * read the mask register for a given group  * this functions return the interrupt mask register  *  * @param regs_base pointer to unit registers  * @param group the interrupt group  */
name|uint32_t
name|al_iofic_read_mask
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|)
function_decl|;
comment|/**  * read interrupt cause register for a given group  * this will clear the set bits if the Clear on Read mode enabled.  * @param regs_base pointer to unit registers  * @param group the interrupt group  */
name|uint32_t
name|al_iofic_read_cause
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|)
function_decl|;
comment|/**  * clear bits in the interrupt cause register for a given group  *  * @param regs_base pointer to unit registers  * @param group the interrupt group  * @param mask bitwise of bits to be cleared, set bits will be cleared.  */
name|void
name|al_iofic_clear_cause
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
comment|/**  * set the cause register for a given group  * this function set the cause register. It will generate an interrupt (if  * the the interrupt isn't masked )  *  * @param regs_base pointer to unit registers  * @param group the interrupt group  * @param mask bitwise of bits to be set.  */
name|void
name|al_iofic_set_cause
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
comment|/**  * unmask specific interrupts from aborting the udma a given group  *  * @param regs_base pointer to unit registers  * @param group the interrupt group  * @param mask bitwise of interrupts to mask  */
name|void
name|al_iofic_abort_mask
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
function_decl|;
comment|/**  * trigger all interrupts that are waiting for moderation timers to expire  *  * @param regs_base pointer to unit registers  * @param group the interrupt group  */
name|void
name|al_iofic_interrupt_moderation_reset
parameter_list|(
name|void
name|__iomem
modifier|*
name|regs_base
parameter_list|,
name|int
name|group
parameter_list|)
function_decl|;
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** @} end of interrupt controller group */
end_comment

end_unit

