begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  * @defgroup group_common HAL Common Layer  *  @{  * @file   al_hal_reg_utils.h  *  * @brief  Register utilities used by HALs and platform layer  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_REG_UTILS_H__
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_REG_UTILS_H__
end_define

begin_include
include|#
directive|include
file|"al_hal_plat_types.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_plat_services.h"
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
name|AL_BIT
parameter_list|(
name|b
parameter_list|)
value|(1UL<< (b))
define|#
directive|define
name|AL_ADDR_LOW
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)((al_phys_addr_t)(x)))
define|#
directive|define
name|AL_ADDR_HIGH
parameter_list|(
name|x
parameter_list|)
value|((uint32_t)((((al_phys_addr_t)(x))>> 16)>> 16))
comment|/** get field out of 32 bit register */
define|#
directive|define
name|AL_REG_FIELD_GET
parameter_list|(
name|reg
parameter_list|,
name|mask
parameter_list|,
name|shift
parameter_list|)
value|(((reg)& (mask))>> (shift))
comment|/** set field of 32 bit register */
define|#
directive|define
name|AL_REG_FIELD_SET
parameter_list|(
name|reg
parameter_list|,
name|mask
parameter_list|,
name|shift
parameter_list|,
name|val
parameter_list|)
define|\
value|(reg) =							\ 		(((reg)& (~(mask))) |				\ 		((((unsigned)(val))<< (shift))& (mask)))
comment|/** set field of 64 bit register */
define|#
directive|define
name|AL_REG_FIELD_SET_64
parameter_list|(
name|reg
parameter_list|,
name|mask
parameter_list|,
name|shift
parameter_list|,
name|val
parameter_list|)
define|\
value|((reg) =						\ 		(((reg)& (~(mask))) |				\ 		((((uint64_t)(val))<< (shift))& (mask))))
comment|/** get single bit out of 32 bit register */
define|#
directive|define
name|AL_REG_BIT_GET
parameter_list|(
name|reg
parameter_list|,
name|shift
parameter_list|)
define|\
value|AL_REG_FIELD_GET(reg, AL_BIT(shift), shift)
define|#
directive|define
name|AL_REG_BITS_FIELD
parameter_list|(
name|shift
parameter_list|,
name|val
parameter_list|)
define|\
value|(((unsigned)(val))<< (shift))
comment|/** set single bit field of 32 bit register to a given value */
define|#
directive|define
name|AL_REG_BIT_VAL_SET
parameter_list|(
name|reg
parameter_list|,
name|shift
parameter_list|,
name|val
parameter_list|)
define|\
value|AL_REG_FIELD_SET(reg, AL_BIT(shift), shift, val)
comment|/** set single bit of 32 bit register to 1 */
define|#
directive|define
name|AL_REG_BIT_SET
parameter_list|(
name|reg
parameter_list|,
name|shift
parameter_list|)
define|\
value|AL_REG_BIT_VAL_SET(reg, shift, 1)
comment|/** clear single bit of 32 bit register */
define|#
directive|define
name|AL_REG_BIT_CLEAR
parameter_list|(
name|reg
parameter_list|,
name|shift
parameter_list|)
define|\
value|AL_REG_BIT_VAL_SET(reg, shift, 0)
define|#
directive|define
name|AL_BIT_MASK
parameter_list|(
name|n
parameter_list|)
define|\
value|(AL_BIT(n) - 1)
define|#
directive|define
name|AL_FIELD_MASK
parameter_list|(
name|msb
parameter_list|,
name|lsb
parameter_list|)
define|\
value|(AL_BIT(msb) + AL_BIT_MASK(msb) - AL_BIT_MASK(lsb))
comment|/** clear bits specified by clear_mask */
define|#
directive|define
name|AL_REG_MASK_CLEAR
parameter_list|(
name|reg
parameter_list|,
name|clear_mask
parameter_list|)
define|\
value|((reg) = (((reg)& (~(clear_mask)))))
comment|/** set bits specified by clear_mask */
define|#
directive|define
name|AL_REG_MASK_SET
parameter_list|(
name|reg
parameter_list|,
name|clear_mask
parameter_list|)
define|\
value|((reg) = (((reg) | (clear_mask))))
comment|/** clear bits specified by clear_mask, and set bits specified by set_mask */
define|#
directive|define
name|AL_REG_CLEAR_AND_SET
parameter_list|(
name|reg
parameter_list|,
name|clear_mask
parameter_list|,
name|set_mask
parameter_list|)
define|\
value|(reg) =	(((reg)& (~(clear_mask))) | (set_mask))
define|#
directive|define
name|AL_ALIGN_UP
parameter_list|(
name|val
parameter_list|,
name|size
parameter_list|)
define|\
value|((size) * (((val) + (size) - 1) / (size)))
comment|/** take bits selected by mask from one data, the rest from background */
define|#
directive|define
name|AL_MASK_VAL
parameter_list|(
name|mask
parameter_list|,
name|data
parameter_list|,
name|background
parameter_list|)
define|\
value|(((mask)& (data)) | ((~mask)& (background)))
comment|/**  * 8 bits register masked write  *  * @param	reg  *	register address  * @param	mask  *	bits not selected (1) by mask will be left unchanged  * @param	data  *	data to write. bits not selected by mask ignored.  */
specifier|static
specifier|inline
name|void
name|al_reg_write8_masked
parameter_list|(
name|uint8_t
name|__iomem
modifier|*
name|reg
parameter_list|,
name|uint8_t
name|mask
parameter_list|,
name|uint8_t
name|data
parameter_list|)
block|{
name|uint8_t
name|temp
decl_stmt|;
name|temp
operator|=
name|al_reg_read8
argument_list|(
name|reg
argument_list|)
expr_stmt|;
name|al_reg_write8
argument_list|(
name|reg
argument_list|,
name|AL_MASK_VAL
argument_list|(
name|mask
argument_list|,
name|data
argument_list|,
name|temp
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/**  * 16 bits register masked write  *  * @param	reg  *	register address  * @param	mask  *	bits not selected (1) by mask will be left unchanged  * @param	data  *	data to write. bits not selected by mask ignored.  */
specifier|static
specifier|inline
name|void
name|al_reg_write16_masked
parameter_list|(
name|uint16_t
name|__iomem
modifier|*
name|reg
parameter_list|,
name|uint16_t
name|mask
parameter_list|,
name|uint16_t
name|data
parameter_list|)
block|{
name|uint16_t
name|temp
decl_stmt|;
name|temp
operator|=
name|al_reg_read16
argument_list|(
name|reg
argument_list|)
expr_stmt|;
name|al_reg_write16
argument_list|(
name|reg
argument_list|,
name|AL_MASK_VAL
argument_list|(
name|mask
argument_list|,
name|data
argument_list|,
name|temp
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/**  * 32 bits register masked write  *  * @param	reg  *	register address  * @param	mask  *	bits not selected (1) by mask will be left unchanged  * @param	data  *	data to write. bits not selected by mask ignored.  */
specifier|static
specifier|inline
name|void
name|al_reg_write32_masked
parameter_list|(
name|uint32_t
name|__iomem
modifier|*
name|reg
parameter_list|,
name|uint32_t
name|mask
parameter_list|,
name|uint32_t
name|data
parameter_list|)
block|{
name|uint32_t
name|temp
decl_stmt|;
name|temp
operator|=
name|al_reg_read32
argument_list|(
name|reg
argument_list|)
expr_stmt|;
name|al_reg_write32
argument_list|(
name|reg
argument_list|,
name|AL_MASK_VAL
argument_list|(
name|mask
argument_list|,
name|data
argument_list|,
name|temp
argument_list|)
argument_list|)
expr_stmt|;
block|}
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

begin_comment
comment|/** @} end of Common group */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

