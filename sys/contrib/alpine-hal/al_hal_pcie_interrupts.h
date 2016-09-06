begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- ******************************************************************************** Copyright (C) 2015 Annapurna Labs Ltd.  This file may be licensed under the terms of the Annapurna Labs Commercial License Agreement.  Alternatively, this file can be distributed under the terms of the GNU General Public License V2 as published by the Free Software Foundation and can be found at http://www.gnu.org/licenses/gpl-2.0.html  Alternatively, redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:      *     Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.      *     Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *******************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AL_HAL_PCIE_INTERRUPTS_H_
end_ifndef

begin_define
define|#
directive|define
name|_AL_HAL_PCIE_INTERRUPTS_H_
end_define

begin_include
include|#
directive|include
file|"al_hal_common.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_pcie.h"
end_include

begin_include
include|#
directive|include
file|"al_hal_iofic.h"
end_include

begin_comment
comment|/**  * @defgroup group_pcie_interrupts PCIe interrupts  * @ingroup grouppcie  *  @{  *  The PCIe interrupts HAL can be used to control PCIe unit interrupts.  *  There are 5 groups of interrupts: app group A, B, C, D and AXI.  *  Only 2 interrupts go from the pcie unit to the GIC:  *  1. Summary for all the int groups (AXI+APP CORE).  *  2. INTA assert/deassert (RC only).  *  For the specific GIC interrupt line, please check the architecture reference  *  manual.  *  The reset mask state of all interrupts is: Masked  *  * @file   al_hal_pcie_interrupts.h  *  */
end_comment

begin_comment
comment|/**  * PCIe interrupt groups  */
end_comment

begin_enum
enum|enum
name|al_pcie_int_group
block|{
name|AL_PCIE_INT_GRP_A
block|,
name|AL_PCIE_INT_GRP_B
block|,
name|AL_PCIE_INT_GRP_C
block|,
comment|/* Rev3 only */
name|AL_PCIE_INT_GRP_D
block|,
comment|/* Rev3 only */
name|AL_PCIE_INT_GRP_AXI_A
block|, }
enum|;
end_enum

begin_comment
comment|/**  * App group A interrupts mask - don't change  * All interrupts not listed below should be masked  */
end_comment

begin_enum
enum|enum
name|al_pcie_app_int_grp_a
block|{
comment|/** [RC only] Deassert_INTD received */
name|AL_PCIE_APP_INT_DEASSERT_INTD
init|=
name|AL_BIT
argument_list|(
literal|0
argument_list|)
block|,
comment|/** [RC only] Deassert_INTC received */
name|AL_PCIE_APP_INT_DEASSERT_INTC
init|=
name|AL_BIT
argument_list|(
literal|1
argument_list|)
block|,
comment|/** [RC only] Deassert_INTB received */
name|AL_PCIE_APP_INT_DEASSERT_INTB
init|=
name|AL_BIT
argument_list|(
literal|2
argument_list|)
block|,
comment|/** 	 * [RC only] Deassert_INTA received - there's a dedicated GIC interrupt 	 * line that reflects the status of ASSERT/DEASSERT of INTA 	 */
name|AL_PCIE_APP_INT_DEASSERT_INTA
init|=
name|AL_BIT
argument_list|(
literal|3
argument_list|)
block|,
comment|/** [RC only] Assert_INTD received */
name|AL_PCIE_APP_INT_ASSERT_INTD
init|=
name|AL_BIT
argument_list|(
literal|4
argument_list|)
block|,
comment|/** [RC only] Assert_INTC received */
name|AL_PCIE_APP_INT_ASSERT_INTC
init|=
name|AL_BIT
argument_list|(
literal|5
argument_list|)
block|,
comment|/** [RC only] Assert_INTB received */
name|AL_PCIE_APP_INT_ASSERT_INTB
init|=
name|AL_BIT
argument_list|(
literal|6
argument_list|)
block|,
comment|/** 	 * [RC only] Assert_INTA received - there's a dedicated GIC interrupt 	 * line that reflects the status of ASSERT/DEASSERT of INTA 	 */
name|AL_PCIE_APP_INT_ASSERT_INTA
init|=
name|AL_BIT
argument_list|(
literal|7
argument_list|)
block|,
comment|/** [RC only] MSI Controller Interrupt */
name|AL_PCIE_APP_INT_MSI_CNTR_RCV_INT
init|=
name|AL_BIT
argument_list|(
literal|8
argument_list|)
block|,
comment|/** [EP only] MSI sent grant */
name|AL_PCIE_APP_INT_MSI_TRNS_GNT
init|=
name|AL_BIT
argument_list|(
literal|9
argument_list|)
block|,
comment|/** [RC only] System error detected  (ERR_COR, ERR_FATAL, ERR_NONFATAL) */
name|AL_PCIE_APP_INT_SYS_ERR_RC
init|=
name|AL_BIT
argument_list|(
literal|10
argument_list|)
block|,
comment|/** [EP only] Software initiates FLR on a Physical Function */
name|AL_PCIE_APP_INT_FLR_PF_ACTIVE
init|=
name|AL_BIT
argument_list|(
literal|11
argument_list|)
block|,
comment|/** [RC only] Root Error Command register assertion notification */
name|AL_PCIE_APP_INT_AER_RC_ERR
init|=
name|AL_BIT
argument_list|(
literal|12
argument_list|)
block|,
comment|/** [RC only] Root Error Command register assertion notification With MSI or MSIX enabled */
name|AL_PCIE_APP_INT_AER_RC_ERR_MSI
init|=
name|AL_BIT
argument_list|(
literal|13
argument_list|)
block|,
comment|/** [RC only] PME Status bit assertion in the Root Status register With INTA */
name|AL_PCIE_APP_INT_PME_INT
init|=
name|AL_BIT
argument_list|(
literal|15
argument_list|)
block|,
comment|/** [RC only] PME Status bit assertion in the Root Status register With MSI or MSIX enabled */
name|AL_PCIE_APP_INT_PME_MSI
init|=
name|AL_BIT
argument_list|(
literal|16
argument_list|)
block|,
comment|/** [RC/EP] The core assert link down event, whenever the link is going down */
name|AL_PCIE_APP_INT_LINK_DOWN
init|=
name|AL_BIT
argument_list|(
literal|21
argument_list|)
block|,
comment|/** [EP only] When the EP gets a command to shut down, signal the software to block any new TLP. */
name|AL_PCIE_APP_INT_PM_XTLH_BLOCK_TLP
init|=
name|AL_BIT
argument_list|(
literal|22
argument_list|)
block|,
comment|/** [RC/EP] PHY/MAC link up */
name|AL_PCIE_APP_INT_XMLH_LINK_UP
init|=
name|AL_BIT
argument_list|(
literal|23
argument_list|)
block|,
comment|/** [RC/EP] Data link up */
name|AL_PCIE_APP_INT_RDLH_LINK_UP
init|=
name|AL_BIT
argument_list|(
literal|24
argument_list|)
block|,
comment|/** [RC/EP] The LTSSM is in RCVRY_LOCK state. */
name|AL_PCIE_APP_INT_LTSSM_RCVRY_STATE
init|=
name|AL_BIT
argument_list|(
literal|25
argument_list|)
block|,
comment|/** 	 * [RC/EP] CFG write transaction to the configuration space by the RC peer 	 * For RC the int/ will be set from DBI write (internal SoC write)] 	 */
name|AL_PCIE_APP_INT_CFG_WR
init|=
name|AL_BIT
argument_list|(
literal|26
argument_list|)
block|,
comment|/** [EP only] CFG access in EP mode */
name|AL_PCIE_APP_INT_CFG_ACCESS
init|=
name|AL_BIT
argument_list|(
literal|31
argument_list|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * App group B interrupts mask - don't change  * All interrupts not listed below should be masked  */
end_comment

begin_enum
enum|enum
name|al_pcie_app_int_grp_b
block|{
comment|/** [RC only] PM_PME Message received */
name|AL_PCIE_APP_INT_GRP_B_PM_PME_MSG_RCVD
init|=
name|AL_BIT
argument_list|(
literal|0
argument_list|)
block|,
comment|/** [RC only] PME_TO_Ack Message received */
name|AL_PCIE_APP_INT_GRP_B_PME_TO_ACK_MSG_RCVD
init|=
name|AL_BIT
argument_list|(
literal|1
argument_list|)
block|,
comment|/** [EP only] PME_Turn_Off Message received */
name|AL_PCIE_APP_INT_GRP_B_PME_TURN_OFF_MSG_RCVD
init|=
name|AL_BIT
argument_list|(
literal|2
argument_list|)
block|,
comment|/** [RC only] ERR_CORR Message received */
name|AL_PCIE_APP_INT_GRP_B_CORR_ERR_MSG_RCVD
init|=
name|AL_BIT
argument_list|(
literal|3
argument_list|)
block|,
comment|/** [RC only] ERR_NONFATAL Message received */
name|AL_PCIE_APP_INT_GRP_B_NON_FTL_ERR_MSG_RCVD
init|=
name|AL_BIT
argument_list|(
literal|4
argument_list|)
block|,
comment|/** [RC only] ERR_FATAL Message received */
name|AL_PCIE_APP_INT_GRP_B_FTL_ERR_MSG_RCVD
init|=
name|AL_BIT
argument_list|(
literal|5
argument_list|)
block|,
comment|/** 	 * [RC/EP] Vendor Defined Message received 	 * Asserted when a vendor message is received (with no data), buffers 2 	 * messages only, and latch the headers in registers 	 */
name|AL_PCIE_APP_INT_GRP_B_VNDR_MSG_A_RCVD
init|=
name|AL_BIT
argument_list|(
literal|6
argument_list|)
block|,
comment|/** 	 * [RC/EP] Vendor Defined Message received 	 * Asserted when a vendor message is received (with no data), buffers 2 	 * messages only, and latch the headers in registers 	 */
name|AL_PCIE_APP_INT_GRP_B_VNDR_MSG_B_RCVD
init|=
name|AL_BIT
argument_list|(
literal|7
argument_list|)
block|,
comment|/** [EP only] Link Autonomous Bandwidth Status is updated */
name|AL_PCIE_APP_INT_GRP_B_LNK_BW_UPD
init|=
name|AL_BIT
argument_list|(
literal|12
argument_list|)
block|,
comment|/** [EP only] Link Equalization Request bit in the Link Status 2 Register has been set */
name|AL_PCIE_APP_INT_GRP_B_LNK_EQ_REQ
init|=
name|AL_BIT
argument_list|(
literal|13
argument_list|)
block|,
comment|/** [RC/EP] OB Vendor message request is granted by the PCIe core */
name|AL_PCIE_APP_INT_GRP_B_OB_VNDR_MSG_REQ_GRNT
init|=
name|AL_BIT
argument_list|(
literal|14
argument_list|)
block|,
comment|/** [RC only] CPL timeout from the PCIe core indication */
name|AL_PCIE_APP_INT_GRP_B_CPL_TO
init|=
name|AL_BIT
argument_list|(
literal|15
argument_list|)
block|,
comment|/** [RC/EP] Slave Response Composer Lookup Error */
name|AL_PCIE_APP_INT_GRP_B_SLV_RESP_COMP_LKUP_ERR
init|=
name|AL_BIT
argument_list|(
literal|16
argument_list|)
block|,
comment|/** [RC/EP] Parity Error */
name|AL_PCIE_APP_INT_GRP_B_PARITY_ERR
init|=
name|AL_BIT
argument_list|(
literal|17
argument_list|)
block|,
comment|/** [EP only] Speed change request */
name|AL_PCIE_APP_INT_GRP_B_SPEED_CHANGE
init|=
name|AL_BIT
argument_list|(
literal|31
argument_list|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * AXI interrupts mask - don't change  * These are internal errors that can happen on the internal chip interface  * between the PCIe port and the I/O Fabric over the AXI bus. The notion of  * master and slave refer to the PCIe port master interface towards the I/O  * Fabric (i.e. for inbound PCIe writes/reads toward the I/O Fabric), while the  * slave interface refer to the I/O Fabric to PCIe port interface where the  * internal chip DMAs and CPU cluster is initiating transactions.  * All interrupts not listed below should be masked.  */
end_comment

begin_enum
enum|enum
name|al_pcie_axi_int
block|{
comment|/** [RC/EP] Master Response Composer Lookup Error */
name|AL_PCIE_AXI_INT_MSTR_RESP_COMP_LKUP_ERR
init|=
name|AL_BIT
argument_list|(
literal|0
argument_list|)
block|,
comment|/** [RC/EP] PARITY ERROR on the master data read channel */
name|AL_PCIE_AXI_INT_PARITY_ERR_MSTR_DATA_RD_CHNL
init|=
name|AL_BIT
argument_list|(
literal|2
argument_list|)
block|,
comment|/** [RC/EP] PARITY ERROR on the slave addr read channel */
name|AL_PCIE_AXI_INT_PARITY_ERR_SLV_ADDR_RD_CHNL
init|=
name|AL_BIT
argument_list|(
literal|3
argument_list|)
block|,
comment|/** [RC/EP] PARITY ERROR on the slave addr write channel */
name|AL_PCIE_AXI_INT_PARITY_ERR_SLV_ADDR_WR_CHNL
init|=
name|AL_BIT
argument_list|(
literal|4
argument_list|)
block|,
comment|/** [RC/EP] PARITY ERROR on the slave data write channel */
name|AL_PCIE_AXI_INT_PARITY_ERR_SLV_DATA_WR_CHNL
init|=
name|AL_BIT
argument_list|(
literal|5
argument_list|)
block|,
comment|/** [RC only] Software error: ECAM write request with invalid bus number */
name|AL_PCIE_AXI_INT_ECAM_WR_REQ_INVLD_BUS_NUM
init|=
name|AL_BIT
argument_list|(
literal|7
argument_list|)
block|,
comment|/** [RC only] Software error: ECAM read request with invalid bus number */
name|AL_PCIE_AXI_INT_ECAM_RD_REQ_INVLD_BUS_NUM
init|=
name|AL_BIT
argument_list|(
literal|8
argument_list|)
block|,
comment|/** [RC/EP] Read AXI completion has ERROR */
name|AL_PCIE_AXI_INT_RD_AXI_COMPL_ERR
init|=
name|AL_BIT
argument_list|(
literal|11
argument_list|)
block|,
comment|/** [RC/EP] Write AXI completion has ERROR */
name|AL_PCIE_AXI_INT_WR_AXI_COMPL_ERR
init|=
name|AL_BIT
argument_list|(
literal|12
argument_list|)
block|,
comment|/** [RC/EP] Read AXI completion has timed out */
name|AL_PCIE_AXI_INT_RD_AXI_COMPL_TO
init|=
name|AL_BIT
argument_list|(
literal|13
argument_list|)
block|,
comment|/** [RC/EP] Write AXI completion has timed out */
name|AL_PCIE_AXI_INT_WR_AXI_COMPL_TO
init|=
name|AL_BIT
argument_list|(
literal|14
argument_list|)
block|,
comment|/** [RC/EP] Parity error AXI domain */
name|AL_PCIE_AXI_INT_AXI_DOM_PARITY_ERR
init|=
name|AL_BIT
argument_list|(
literal|15
argument_list|)
block|,
comment|/** [RC/EP] POS error interrupt */
name|AL_PCIE_AXI_INT_POS_ERR
init|=
name|AL_BIT
argument_list|(
literal|16
argument_list|)
block|, }
enum|;
end_enum

begin_comment
comment|/**  * @brief   Initialize and configure PCIe controller interrupts  * 	    Doesn't change the mask state of the interrupts  * 	    The reset mask state of all interrupts is: Masked  *  * @param   pcie_port pcie port handle  */
end_comment

begin_function_decl
name|void
name|al_pcie_ints_config
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Unmask PCIe app group interrupts  * @param  pcie_port pcie_port pcie port handle  * @param  int_group interrupt group  * @param  int_mask  int_mask interrupts to unmask ('1' to unmask)  */
end_comment

begin_function_decl
name|void
name|al_pcie_app_int_grp_unmask
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|enum
name|al_pcie_int_group
name|int_group
parameter_list|,
name|uint32_t
name|int_mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Mask PCIe app group interrupts  * @param  pcie_port pcie_port pcie port handle  * @param  int_group interrupt group  * @param  int_mask  int_mask interrupts to unmask ('1' to mask)  */
end_comment

begin_function_decl
name|void
name|al_pcie_app_int_grp_mask
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|enum
name|al_pcie_int_group
name|int_group
parameter_list|,
name|uint32_t
name|int_mask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Clear the PCIe app group interrupt cause  * @param  pcie_port pcie port handle  * @param  int_group interrupt group  * @param  int_cause interrupt cause  */
end_comment

begin_function_decl
name|void
name|al_pcie_app_int_grp_cause_clear
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|enum
name|al_pcie_int_group
name|int_group
parameter_list|,
name|uint32_t
name|int_cause
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read PCIe app group interrupt cause  * @param  pcie_port pcie port handle  * @param  int_group interrupt group  * @return interrupt cause or 0 in case the group is not supported  */
end_comment

begin_function_decl
name|uint32_t
name|al_pcie_app_int_grp_cause_read
parameter_list|(
name|struct
name|al_pcie_port
modifier|*
name|pcie_port
parameter_list|,
name|enum
name|al_pcie_int_group
name|int_group
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** @} end of group_pcie_interrupts group */
end_comment

end_unit

