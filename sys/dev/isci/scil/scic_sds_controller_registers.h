begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This file is provided under a dual BSD/GPLv2 license.  When using or  * redistributing this file, you may do so under either license.  *  * GPL LICENSE SUMMARY  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  *  * This program is free software; you can redistribute it and/or modify  * it under the terms of version 2 of the GNU General Public License as  * published by the Free Software Foundation.  *  * This program is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *  * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.  * The full GNU General Public License is included in this distribution  * in the file called LICENSE.GPL.  *  * BSD LICENSE  *  * Copyright(c) 2008 - 2011 Intel Corporation. All rights reserved.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCIC_SDS_CONTROLLER_REGISTERS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCIC_SDS_CONTROLLER_REGISTERS_H_
end_define

begin_comment
comment|/**  * @file  *  * @brief This file contains macros used to perform the register reads/writes  *        to the SCU hardware.  */
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
comment|// __cplusplus
include|#
directive|include
file|<dev/isci/scil/scu_registers.h>
include|#
directive|include
file|<dev/isci/scil/scic_sds_controller.h>
comment|/**  * @name SMU_REGISTER_ACCESS_MACROS  */
comment|/*@{*/
define|#
directive|define
name|scic_sds_controller_smu_register_read
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|)
define|\
value|smu_register_read( \       (controller), \       (controller)->smu_registers->reg \    )
define|#
directive|define
name|scic_sds_controller_smu_register_write
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|smu_register_write( \       (controller), \       (controller)->smu_registers->reg, \       (value) \    )
comment|/*@}*/
comment|/**  * @name AFE_REGISTER_ACCESS_MACROS  */
comment|/*@{*/
define|#
directive|define
name|scu_afe_register_write
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       (controller), \       (controller)->scu_registers->afe.reg, \       (value) \    )
define|#
directive|define
name|scu_afe_register_read
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|)
define|\
value|scu_register_read( \       (controller), \       (controller)->scu_registers->afe.reg \    )
comment|/*@}*/
comment|/**  * @name SGPIO_PEG0_REGISTER_ACCESS_MACROS  */
comment|/*@{*/
define|#
directive|define
name|scu_sgpio_peg0_register_read
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|)
define|\
value|scu_register_read( \       (controller), \       (controller)->scu_registers->peg0.sgpio.reg \    )
define|#
directive|define
name|scu_sgpio_peg0_register_write
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       (controller), \       (controller)->scu_registers->peg0.sgpio.reg, \       (value) \    )
comment|/*@}*/
comment|/**  * @name VIIT_REGISTER_ACCESS_MACROS  */
comment|/*@{*/
define|#
directive|define
name|scu_controller_viit_register_write
parameter_list|(
name|controller
parameter_list|,
name|index
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       (controller), \       (controller)->scu_registers->peg0.viit[index].reg, \       value \    )
comment|/*@}*/
comment|/**  * @name SCRATCH_RAM_REGISTER_ACCESS_MACROS  */
comment|/*@{*/
comment|// Scratch RAM access may be needed before the scu_registers pointer
comment|//  has been initialized.  So instead, explicitly cast BAR1 to a
comment|//  SCU_REGISTERS_T data structure.
comment|// Scratch RAM is stored in the Zoning Permission Table for OROM use.
define|#
directive|define
name|scu_controller_scratch_ram_register_write
parameter_list|(
name|controller
parameter_list|,
name|index
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       (controller), \       ((SCU_REGISTERS_T *)scic_cb_pci_get_bar(controller, PATSBURG_SCU_BAR))->peg0.zpt0.table[index], \       value \    )
define|#
directive|define
name|scu_controller_scratch_ram_register_read
parameter_list|(
name|controller
parameter_list|,
name|index
parameter_list|)
define|\
value|scu_register_read( \       (controller), \       ((SCU_REGISTERS_T *)scic_cb_pci_get_bar(controller, PATSBURG_SCU_BAR))->peg0.zpt0.table[index] \    )
define|#
directive|define
name|scu_controller_scratch_ram_register_write_ext
parameter_list|(
name|controller
parameter_list|,
name|index
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       (controller), \       ((SCU_REGISTERS_T *)scic_cb_pci_get_bar(controller, PATSBURG_SCU_BAR))->peg0.zpt1.table[index], \       value \    )
define|#
directive|define
name|scu_controller_scratch_ram_register_read_ext
parameter_list|(
name|controller
parameter_list|,
name|index
parameter_list|)
define|\
value|scu_register_read( \       (controller), \       ((SCU_REGISTERS_T *)scic_cb_pci_get_bar(controller, PATSBURG_SCU_BAR))->peg0.zpt1.table[index] \    )
comment|/*@}*/
comment|//*****************************************************************************
comment|//* SMU REGISTERS
comment|//*****************************************************************************
comment|/**  * @name SMU_REGISTERS  */
comment|/*@{*/
define|#
directive|define
name|SMU_PCP_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scic_sds_controller_smu_register_write( \        controller, post_context_port, value \     )
define|#
directive|define
name|SMU_TCR_READ
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \        controller, task_context_range \     )
define|#
directive|define
name|SMU_TCR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scic_sds_controller_smu_register_write( \        controller, task_context_range, value \     )
define|#
directive|define
name|SMU_HTTBAR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|address
parameter_list|)
define|\
value|{ \    scic_sds_controller_smu_register_write( \       controller, \       host_task_table_lower, \       sci_cb_physical_address_lower(address) \    );\    scic_sds_controller_smu_register_write( \       controller, \       host_task_table_upper, \       sci_cb_physical_address_upper(address) \    ); \ }
define|#
directive|define
name|SMU_CQBAR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|address
parameter_list|)
define|\
value|{ \    scic_sds_controller_smu_register_write( \       controller, \       completion_queue_lower, \       sci_cb_physical_address_lower(address) \    ); \    scic_sds_controller_smu_register_write( \       controller, \       completion_queue_upper, \       sci_cb_physical_address_upper(address) \    ); \ }
define|#
directive|define
name|SMU_CQGR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scic_sds_controller_smu_register_write( \        controller, completion_queue_get, value \     )
define|#
directive|define
name|SMU_CQGR_READ
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \        controller, completion_queue_get \     )
define|#
directive|define
name|SMU_CQPR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scic_sds_controller_smu_register_write( \        controller, completion_queue_put, value \     )
define|#
directive|define
name|SMU_RNCBAR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|address
parameter_list|)
define|\
value|{ \    scic_sds_controller_smu_register_write( \       controller, \       remote_node_context_lower, \       sci_cb_physical_address_lower(address) \    ); \    scic_sds_controller_smu_register_write( \       controller, \       remote_node_context_upper, \       sci_cb_physical_address_upper(address) \    ); \ }
define|#
directive|define
name|SMU_AMR_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \       controller, address_modifier \    )
define|#
directive|define
name|SMU_IMR_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \       controller, interrupt_mask \    )
define|#
directive|define
name|SMU_IMR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|mask
parameter_list|)
define|\
value|scic_sds_controller_smu_register_write( \       controller, interrupt_mask, mask \    )
define|#
directive|define
name|SMU_ISR_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \       controller, interrupt_status \    )
define|#
directive|define
name|SMU_ISR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|status
parameter_list|)
define|\
value|scic_sds_controller_smu_register_write( \       controller, interrupt_status, status \    )
define|#
directive|define
name|SMU_ICC_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \       controller, interrupt_coalesce_control \    )
define|#
directive|define
name|SMU_ICC_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scic_sds_controller_smu_register_write( \       controller, interrupt_coalesce_control, value \    )
define|#
directive|define
name|SMU_CQC_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scic_sds_controller_smu_register_write( \        controller, completion_queue_control, value \     )
define|#
directive|define
name|SMU_SMUSRCR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scic_sds_controller_smu_register_write( \       controller, soft_reset_control, value \    )
define|#
directive|define
name|SMU_TCA_WRITE
parameter_list|(
name|controller
parameter_list|,
name|index
parameter_list|,
name|value
parameter_list|)
define|\
value|scic_sds_controller_smu_register_write( \        controller, task_context_assignment[index], value \     )
define|#
directive|define
name|SMU_TCA_READ
parameter_list|(
name|controller
parameter_list|,
name|index
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \        controller, task_context_assignment[index] \     )
define|#
directive|define
name|SMU_DCC_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \       controller, device_context_capacity \    )
define|#
directive|define
name|SMU_DFC_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \       controller, device_function_capacity \    )
define|#
directive|define
name|SMU_SMUCSR_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \       controller, control_status \    )
define|#
directive|define
name|SMU_CGUCR_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \       controller, clock_gating_control \    )
define|#
directive|define
name|SMU_CGUCR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scic_sds_controller_smu_register_write( \       controller, clock_gating_control, value \    )
define|#
directive|define
name|SMU_CQPR_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scic_sds_controller_smu_register_read( \        controller, completion_queue_put \     )
comment|/*@}*/
comment|/**  * @name SCU_REGISTER_ACCESS_MACROS  */
comment|/*@{*/
define|#
directive|define
name|scic_sds_controller_scu_register_read
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|)
define|\
value|scu_register_read( \       (controller), \       (controller)->scu_registers->reg \    )
define|#
directive|define
name|scic_sds_controller_scu_register_write
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       (controller), \       (controller)->scu_registers->reg, \       (value) \    )
comment|/*@}*/
comment|//****************************************************************************
comment|//*  SCU SDMA REGISTERS
comment|//****************************************************************************
comment|/**  * @name SCU_SDMA_REGISTER_ACCESS_MACROS  */
comment|/*@{*/
define|#
directive|define
name|scu_sdma_register_read
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|)
define|\
value|scu_register_read( \       (controller), \       (controller)->scu_registers->sdma.reg \    )
define|#
directive|define
name|scu_sdma_register_write
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       (controller), \       (controller)->scu_registers->sdma.reg, \       (value) \    )
comment|/*@}*/
comment|/**  * @name SCU_SDMA_REGISTERS  */
comment|/*@{*/
define|#
directive|define
name|SCU_PUFATHAR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|address
parameter_list|)
define|\
value|{ \    scu_sdma_register_write( \       controller, \       uf_address_table_lower, \       sci_cb_physical_address_lower(address) \    ); \    scu_sdma_register_write( \       controller, \       uf_address_table_upper, \       sci_cb_physical_address_upper(address) \    ); \ }
define|#
directive|define
name|SCU_UFHBAR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|address
parameter_list|)
define|\
value|{ \    scu_sdma_register_write( \       controller, \       uf_header_base_address_lower, \       sci_cb_physical_address_lower(address) \    ); \    scu_sdma_register_write( \       controller, \       uf_header_base_address_upper, \       sci_cb_physical_address_upper(address) \    ); \ }
define|#
directive|define
name|SCU_UFQC_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scu_sdma_register_read( \        controller,  \        unsolicited_frame_queue_control \     )
define|#
directive|define
name|SCU_UFQC_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_sdma_register_write( \        controller, \        unsolicited_frame_queue_control, \        value \     )
define|#
directive|define
name|SCU_UFQPP_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scu_sdma_register_read( \        controller, \        unsolicited_frame_put_pointer \     )
define|#
directive|define
name|SCU_UFQPP_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_sdma_register_write( \       controller, \       unsolicited_frame_put_pointer, \       value \    )
define|#
directive|define
name|SCU_UFQGP_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_sdma_register_write( \       controller, \       unsolicited_frame_get_pointer, \       value \    )
define|#
directive|define
name|SCU_PDMACR_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scu_sdma_register_read( \       controller, \       pdma_configuration \    )
define|#
directive|define
name|SCU_PDMACR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_sdma_register_write( \       controller, \       pdma_configuration, \       value \    )
define|#
directive|define
name|SCU_CDMACR_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scu_sdma_register_read( \      controller, \      cdma_configuration \    )
define|#
directive|define
name|SCU_CDMACR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_sdma_register_write( \       controller, \       cdma_configuration, \       value \    )
comment|/*@}*/
comment|//*****************************************************************************
comment|//* SCU CRAM AND FBRAM Registers
comment|//*****************************************************************************
comment|/**  * @name SCU_CRAM_REGISTER_ACCESS_MACROS  */
comment|/*@{*/
define|#
directive|define
name|scu_cram_register_read
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|)
define|\
value|scu_register_read( \       (controller), \       (controller)->scu_registers->cram.reg \    )
define|#
directive|define
name|scu_cram_register_write
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       (controller), \       (controller)->scu_registers->cram.reg, \       (value) \    )
comment|/*@}*/
comment|/**  * @name SCU_FBRAM_REGISTER_ACCESS_MACROS  */
comment|/*@{*/
define|#
directive|define
name|scu_fbram_register_read
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|)
define|\
value|scu_register_read( \       (controller), \       (controller)->scu_registers->fbram.reg \    )
define|#
directive|define
name|scu_fbram_register_write
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       (controller), \       (controller)->scu_registers->fbram.reg, \       (value) \    )
comment|/*@}*/
comment|/**  * @name SCU_CRAM_REGISTERS  */
comment|/*@{*/
comment|// SRAM ECC CONTROL REGISTER BITS
define|#
directive|define
name|SIGNLE_BIT_ERROR_CORRECTION_ENABLE
value|0x00000001
define|#
directive|define
name|MULTI_BIT_ERROR_REPORTING_ENABLE
value|0x00000002
define|#
directive|define
name|SINGLE_BIT_ERROR_REPORTING_ENABLE
value|0x00000004
comment|//SRAM ECC control register (SECR0)
define|#
directive|define
name|SCU_SECR0_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_cram_register_write( \       controller, \       sram_ecc_control_0, \       value \    )
comment|/*@}*/
comment|/**  * @name SCU_FBRAM_REGISTERS  */
comment|/*@{*/
comment|//SRAM ECC control register (SECR1)
define|#
directive|define
name|SCU_SECR1_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_fbram_register_write( \       controller, \       sram_ecc_control_1, \       value \    )
comment|/*@}*/
comment|//*****************************************************************************
comment|//* SCU Port Task Scheduler Group Registers
comment|//*****************************************************************************
comment|/**  * @name SCU_PTSG_REGISTER_ACCESS_MACROS  */
comment|/*@{*/
define|#
directive|define
name|scu_ptsg_register_read
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|)
define|\
value|scu_register_read( \       (controller), \       (controller)->scu_registers->peg0.ptsg.reg \    )
define|#
directive|define
name|scu_ptsg_register_write
parameter_list|(
name|controller
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_register_write( \       (controller), \       (controller)->scu_registers->peg0.ptsg.reg, \       (value) \    )
comment|/*@}*/
comment|/**  * @name SCU_PTSG_REGISTERS  */
comment|/*@{*/
define|#
directive|define
name|SCU_PTSGCR_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scu_ptsg_register_read( \        (controller), \        control \     )
define|#
directive|define
name|SCU_PTSGCR_WRITE
parameter_list|(
name|controller
parameter_list|,
name|value
parameter_list|)
define|\
value|scu_ptsg_register_write( \        (controller), \        control, \        value \     )
define|#
directive|define
name|SCU_PTSGRTC_READ
parameter_list|(
name|controller
parameter_list|)
define|\
value|scu_ptsg_register_read( \        contoller, \        real_time_clock \     )
comment|/*@}*/
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
comment|// __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// _SCIC_SDS_CONTROLLER_REGISTERS_H_
end_comment

end_unit

