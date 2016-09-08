begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************* Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_comment
comment|/**  *  @{  * @file   al_hal_udma_regs.h  *  * @brief  udma registers definition  *  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_UDMA_REG_H
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_UDMA_REG_H
end_define

begin_include
include|#
directive|include
file|"al_hal_udma_regs_m2s.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_udma_regs_s2m.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_udma_regs_gen.h"
end_include

begin_define
define|#
directive|define
name|AL_UDMA_REV_ID_REV0
value|0
end_define

begin_define
define|#
directive|define
name|AL_UDMA_REV_ID_REV1
value|1
end_define

begin_define
define|#
directive|define
name|AL_UDMA_REV_ID_REV2
value|2
end_define

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
comment|/** UDMA registers, either m2s or s2m */
union|union
name|udma_regs
block|{
name|struct
name|udma_m2s_regs
name|m2s
decl_stmt|;
name|struct
name|udma_s2m_regs
name|s2m
decl_stmt|;
block|}
union|;
struct|struct
name|unit_regs
block|{
name|struct
name|udma_m2s_regs
name|m2s
decl_stmt|;
name|uint32_t
name|rsrvd0
index|[
operator|(
literal|0x10000
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|udma_m2s_regs
argument_list|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|udma_s2m_regs
name|s2m
decl_stmt|;
name|uint32_t
name|rsrvd1
index|[
operator|(
operator|(
literal|0x1C000
operator|-
literal|0x10000
operator|)
operator|-
sizeof|sizeof
argument_list|(
expr|struct
name|udma_s2m_regs
argument_list|)
operator|)
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|udma_gen_regs
name|gen
decl_stmt|;
block|}
struct|;
comment|/** UDMA submission and completion registers, M2S and S2M UDMAs have same stucture */
struct|struct
name|udma_rings_regs
block|{
name|uint32_t
name|rsrvd0
index|[
literal|8
index|]
decl_stmt|;
name|uint32_t
name|cfg
decl_stmt|;
comment|/* Descriptor ring configuration */
name|uint32_t
name|status
decl_stmt|;
comment|/* Descriptor ring status and information */
name|uint32_t
name|drbp_low
decl_stmt|;
comment|/* Descriptor Ring Base Pointer [31:4] */
name|uint32_t
name|drbp_high
decl_stmt|;
comment|/* Descriptor Ring Base Pointer [63:32] */
name|uint32_t
name|drl
decl_stmt|;
comment|/* Descriptor Ring Length[23:2] */
name|uint32_t
name|drhp
decl_stmt|;
comment|/* Descriptor Ring Head Pointer */
name|uint32_t
name|drtp_inc
decl_stmt|;
comment|/* Descriptor Tail Pointer increment */
name|uint32_t
name|drtp
decl_stmt|;
comment|/* Descriptor Tail Pointer */
name|uint32_t
name|dcp
decl_stmt|;
comment|/* Descriptor Current Pointer */
name|uint32_t
name|crbp_low
decl_stmt|;
comment|/* Completion Ring Base Pointer [31:4] */
name|uint32_t
name|crbp_high
decl_stmt|;
comment|/* Completion Ring Base Pointer [63:32] */
name|uint32_t
name|crhp
decl_stmt|;
comment|/* Completion Ring Head Pointer */
name|uint32_t
name|crhp_internal
decl_stmt|;
comment|/* Completion Ring Head Pointer internal, before AX ... */
block|}
struct|;
comment|/** M2S and S2M generic structure of Q registers */
union|union
name|udma_q_regs
block|{
name|struct
name|udma_rings_regs
name|rings
decl_stmt|;
name|struct
name|udma_m2s_q
name|m2s_q
decl_stmt|;
name|struct
name|udma_s2m_q
name|s2m_q
decl_stmt|;
block|}
union|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __AL_HAL_UDMA_REG_H */
end_comment

begin_comment
comment|/** @} end of UDMA group */
end_comment

end_unit

