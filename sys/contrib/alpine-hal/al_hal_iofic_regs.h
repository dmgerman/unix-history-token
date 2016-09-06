begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*_ ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__AL_HAL_IOFIC_REG_H
end_ifndef

begin_define
define|#
directive|define
name|__AL_HAL_IOFIC_REG_H
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
comment|/* * Unit Registers */
struct|struct
name|al_iofic_grp_ctrl
block|{
name|uint32_t
name|int_cause_grp
decl_stmt|;
comment|/* Interrupt Cause RegisterSet by hardware */
name|uint32_t
name|rsrvd1
decl_stmt|;
name|uint32_t
name|int_cause_set_grp
decl_stmt|;
comment|/* Interrupt Cause Set RegisterWriting 1 to a bit in t ... */
name|uint32_t
name|rsrvd2
decl_stmt|;
name|uint32_t
name|int_mask_grp
decl_stmt|;
comment|/* Interrupt Mask RegisterIf Auto-mask control bit =TR ... */
name|uint32_t
name|rsrvd3
decl_stmt|;
name|uint32_t
name|int_mask_clear_grp
decl_stmt|;
comment|/* Interrupt Mask Clear RegisterUsed when auto-mask co ... */
name|uint32_t
name|rsrvd4
decl_stmt|;
name|uint32_t
name|int_status_grp
decl_stmt|;
comment|/* Interrupt status RegisterThis register latch the st ... */
name|uint32_t
name|rsrvd5
decl_stmt|;
name|uint32_t
name|int_control_grp
decl_stmt|;
comment|/* Interrupt Control Register */
name|uint32_t
name|rsrvd6
decl_stmt|;
name|uint32_t
name|int_abort_msk_grp
decl_stmt|;
comment|/* Interrupt Mask RegisterEach bit in this register ma ... */
name|uint32_t
name|rsrvd7
decl_stmt|;
name|uint32_t
name|int_log_msk_grp
decl_stmt|;
comment|/* Interrupt Log RegisterEach bit in this register mas ... */
name|uint32_t
name|rsrvd8
decl_stmt|;
block|}
struct|;
struct|struct
name|al_iofic_grp_mod
block|{
name|uint32_t
name|grp_int_mod_reg
decl_stmt|;
comment|/* Interrupt moderation registerDedicated moderation in ... */
name|uint32_t
name|grp_int_tgtid_reg
decl_stmt|;
block|}
struct|;
struct|struct
name|al_iofic_regs
block|{
name|struct
name|al_iofic_grp_ctrl
name|ctrl
index|[
literal|0
index|]
decl_stmt|;
name|uint32_t
name|rsrvd1
index|[
literal|0x400
operator|>>
literal|2
index|]
expr_stmt|;
name|struct
name|al_iofic_grp_mod
name|grp_int_mod
index|[
literal|0
index|]
index|[
literal|32
index|]
decl_stmt|;
block|}
struct|;
comment|/* * Registers Fields */
comment|/**** int_control_grp register ****/
comment|/* When Clear_on_Read =1, All bits of  Cause register  ... */
define|#
directive|define
name|INT_CONTROL_GRP_CLEAR_ON_READ
value|(1<< 0)
comment|/* (must be set only when MSIX is enabled)When Auto-Ma ... */
define|#
directive|define
name|INT_CONTROL_GRP_AUTO_MASK
value|(1<< 1)
comment|/* Auto_Clear (RW)When Auto-Clear =1, the bits in the  ... */
define|#
directive|define
name|INT_CONTROL_GRP_AUTO_CLEAR
value|(1<< 2)
comment|/* When Set_on_Posedge =1, the bits in the interrupt c ... */
define|#
directive|define
name|INT_CONTROL_GRP_SET_ON_POSEDGE
value|(1<< 3)
comment|/* When Moderation_Reset =1, all Moderation timers ass ... */
define|#
directive|define
name|INT_CONTROL_GRP_MOD_RST
value|(1<< 4)
comment|/* When mask_msi_x =1, No MSI-X from this group is sen ... */
define|#
directive|define
name|INT_CONTROL_GRP_MASK_MSI_X
value|(1<< 5)
comment|/* MSI-X AWID value, same ID for all cause bits */
define|#
directive|define
name|INT_CONTROL_GRP_AWID_MASK
value|0x00000F00
define|#
directive|define
name|INT_CONTROL_GRP_AWID_SHIFT
value|8
comment|/* This value determines the interval between interrup ... */
define|#
directive|define
name|INT_CONTROL_GRP_MOD_INTV_MASK
value|0x00FF0000
define|#
directive|define
name|INT_CONTROL_GRP_MOD_INTV_SHIFT
value|16
comment|/* This value determines the Moderation_Timer_Clock sp ... */
define|#
directive|define
name|INT_CONTROL_GRP_MOD_RES_MASK
value|0x0F000000
define|#
directive|define
name|INT_CONTROL_GRP_MOD_RES_SHIFT
value|24
comment|/**** grp_int_mod_reg register ****/
comment|/* Interrupt Moderation Interval registerDedicated reg ... */
define|#
directive|define
name|INT_MOD_INTV_MASK
value|0x000000FF
define|#
directive|define
name|INT_MOD_INTV_SHIFT
value|0
comment|/**** grp_int_tgtid_reg register ****/
comment|/* Interrupt tgtid value registerDedicated reg ... */
define|#
directive|define
name|INT_MSIX_TGTID_MASK
value|0x0000FFFF
define|#
directive|define
name|INT_MSIX_TGTID_SHIFT
value|0
comment|/* Interrupt tgtid_en value registerDedicated reg ... */
define|#
directive|define
name|INT_MSIX_TGTID_EN_SHIFT
value|31
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
comment|/* __AL_HAL_IOFIC_REG_H */
end_comment

end_unit

