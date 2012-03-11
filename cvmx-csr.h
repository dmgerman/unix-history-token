begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************license start***************  * Copyright (c) 2003-2010  Cavium Inc. (support@cavium.com). All rights  * reserved.  *  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  *   * Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  *   * Redistributions in binary form must reproduce the above  *     copyright notice, this list of conditions and the following  *     disclaimer in the documentation and/or other materials provided  *     with the distribution.   *   * Neither the name of Cavium Inc. nor the names of  *     its contributors may be used to endorse or promote products  *     derived from this software without specific prior written  *     permission.   * This Software, including technical data, may be subject to U.S. export  control  * laws, including the U.S. Export Administration Act and its  associated  * regulations, and may be subject to export or import  regulations in other  * countries.   * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"  * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR  * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO  * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR  * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM  * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,  * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF  * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR  * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR  * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.  ***********************license end**************************************/
end_comment

begin_comment
comment|/**  * @file  *  * Configuration and status register (CSR) address and type definitions for  * Octoen.  *  *<hr>$Revision: 70030 $<hr>  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CVMX_CSR_H__
end_ifndef

begin_define
define|#
directive|define
name|__CVMX_CSR_H__
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CVMX_ENABLE_CSR_ADDRESS_CHECKING
end_ifndef

begin_define
define|#
directive|define
name|CVMX_ENABLE_CSR_ADDRESS_CHECKING
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"cvmx-platform.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-csr-enums.h"
end_include

begin_include
include|#
directive|include
file|"cvmx-csr-typedefs.h"
end_include

begin_comment
comment|/* Map the HW names to the SDK historical names */
end_comment

begin_typedef
typedef|typedef
name|cvmx_ciu_intx_en1_t
name|cvmx_ciu_int1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_ciu_intx_sum0_t
name|cvmx_ciu_intx0_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_ciu_mbox_setx_t
name|cvmx_ciu_mbox_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_fpa_fpfx_marks_t
name|cvmx_fpa_fpf_marks_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_fpa_quex_page_index_t
name|cvmx_fpa_que0_page_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_fpa_quex_page_index_t
name|cvmx_fpa_que1_page_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_fpa_quex_page_index_t
name|cvmx_fpa_que2_page_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_fpa_quex_page_index_t
name|cvmx_fpa_que3_page_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_fpa_quex_page_index_t
name|cvmx_fpa_que4_page_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_fpa_quex_page_index_t
name|cvmx_fpa_que5_page_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_fpa_quex_page_index_t
name|cvmx_fpa_que6_page_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_fpa_quex_page_index_t
name|cvmx_fpa_que7_page_index_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_ipd_1st_mbuff_skip_t
name|cvmx_ipd_mbuff_first_skip_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_ipd_1st_next_ptr_back_t
name|cvmx_ipd_first_next_ptr_back_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_ipd_packet_mbuff_size_t
name|cvmx_ipd_mbuff_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_ipd_qosx_red_marks_t
name|cvmx_ipd_qos_red_marks_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_ipd_wqe_fpa_queue_t
name|cvmx_ipd_wqe_fpa_pool_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_l2c_pfcx_t
name|cvmx_l2c_pfc0_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_l2c_pfcx_t
name|cvmx_l2c_pfc1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_l2c_pfcx_t
name|cvmx_l2c_pfc2_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_l2c_pfcx_t
name|cvmx_l2c_pfc3_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_bist_ctl_t
name|cvmx_lmc_bist_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_bist_result_t
name|cvmx_lmc_bist_result_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_comp_ctl_t
name|cvmx_lmc_comp_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_ctl_t
name|cvmx_lmc_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_ctl1_t
name|cvmx_lmc_ctl1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_dclk_cnt_hi_t
name|cvmx_lmc_dclk_cnt_hi_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_dclk_cnt_lo_t
name|cvmx_lmc_dclk_cnt_lo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_dclk_ctl_t
name|cvmx_lmc_dclk_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_ddr2_ctl_t
name|cvmx_lmc_ddr2_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_delay_cfg_t
name|cvmx_lmc_delay_cfg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_dll_ctl_t
name|cvmx_lmc_dll_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_dual_memcfg_t
name|cvmx_lmc_dual_memcfg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_ecc_synd_t
name|cvmx_lmc_ecc_synd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_fadr_t
name|cvmx_lmc_fadr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_ifb_cnt_hi_t
name|cvmx_lmc_ifb_cnt_hi_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_ifb_cnt_lo_t
name|cvmx_lmc_ifb_cnt_lo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_mem_cfg0_t
name|cvmx_lmc_mem_cfg0_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_mem_cfg1_t
name|cvmx_lmc_mem_cfg1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_wodt_ctl0_t
name|cvmx_lmc_odt_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_ops_cnt_hi_t
name|cvmx_lmc_ops_cnt_hi_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_ops_cnt_lo_t
name|cvmx_lmc_ops_cnt_lo_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_pll_bwctl_t
name|cvmx_lmc_pll_bwctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_pll_ctl_t
name|cvmx_lmc_pll_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_pll_status_t
name|cvmx_lmc_pll_status_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_read_level_ctl_t
name|cvmx_lmc_read_level_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_read_level_dbg_t
name|cvmx_lmc_read_level_dbg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_read_level_rankx_t
name|cvmx_lmc_read_level_rankx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_rodt_comp_ctl_t
name|cvmx_lmc_rodt_comp_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_rodt_ctl_t
name|cvmx_lmc_rodt_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_wodt_ctl0_t
name|cvmx_lmc_wodt_ctl_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_wodt_ctl0_t
name|cvmx_lmc_wodt_ctl0_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_lmcx_wodt_ctl1_t
name|cvmx_lmc_wodt_ctl1_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_mio_boot_reg_cfgx_t
name|cvmx_mio_boot_reg_cfg0_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_mio_boot_reg_timx_t
name|cvmx_mio_boot_reg_tim0_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_mio_twsx_int_t
name|cvmx_mio_tws_int_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_mio_twsx_sw_twsi_t
name|cvmx_mio_tws_sw_twsi_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_mio_twsx_sw_twsi_ext_t
name|cvmx_mio_tws_sw_twsi_ext_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_mio_twsx_twsi_sw_t
name|cvmx_mio_tws_twsi_sw_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_base_addr_inputx_t
name|cvmx_npi_base_addr_input_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_base_addr_outputx_t
name|cvmx_npi_base_addr_output_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_buff_size_outputx_t
name|cvmx_npi_buff_size_output_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_dma_highp_counts_t
name|cvmx_npi_dma_counts_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_dma_highp_naddr_t
name|cvmx_npi_dma_naddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_highp_dbell_t
name|cvmx_npi_dbell_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_highp_ibuff_saddr_t
name|cvmx_npi_dma_ibuff_saddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_mem_access_subidx_t
name|cvmx_npi_mem_access_subid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_num_desc_outputx_t
name|cvmx_npi_num_desc_output_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_px_dbpair_addr_t
name|cvmx_npi_dbpair_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_px_instr_addr_t
name|cvmx_npi_instr_addr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_px_instr_cnts_t
name|cvmx_npi_instr_cnts_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_px_pair_cnts_t
name|cvmx_npi_pair_cnts_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_npi_size_inputx_t
name|cvmx_npi_size_input_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pci_dbellx_t
name|cvmx_pci_dbell_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pci_dma_cntx_t
name|cvmx_pci_dma_cnt_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pci_dma_int_levx_t
name|cvmx_pci_dma_int_lev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pci_dma_timex_t
name|cvmx_pci_dma_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pci_instr_countx_t
name|cvmx_pci_instr_count_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pci_pkt_creditsx_t
name|cvmx_pci_pkt_credits_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pci_pkts_sent_int_levx_t
name|cvmx_pci_pkts_sent_int_lev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pci_pkts_sent_timex_t
name|cvmx_pci_pkts_sent_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pci_pkts_sentx_t
name|cvmx_pci_pkts_sent_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pip_prt_cfgx_t
name|cvmx_pip_port_cfg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pip_prt_tagx_t
name|cvmx_pip_port_tag_cfg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pip_qos_watchx_t
name|cvmx_pip_port_watcher_cfg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pko_mem_queue_ptrs_t
name|cvmx_pko_queue_cfg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_pko_reg_cmd_buf_t
name|cvmx_pko_pool_cfg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_smix_clk_t
name|cvmx_smi_clk_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_smix_cmd_t
name|cvmx_smi_cmd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_smix_en_t
name|cvmx_smi_en_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_smix_rd_dat_t
name|cvmx_smi_rd_dat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_smix_wr_dat_t
name|cvmx_smi_wr_dat_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|cvmx_tim_reg_flags_t
name|cvmx_tim_control_t
typedef|;
end_typedef

begin_comment
comment|/* The CSRs for bootbus region zero used to be independent of the     other 1-7. As of SDK 1.7.0 these were combined. These macros     are for backwards compactability */
end_comment

begin_define
define|#
directive|define
name|CVMX_MIO_BOOT_REG_CFG0
value|CVMX_MIO_BOOT_REG_CFGX(0)
end_define

begin_define
define|#
directive|define
name|CVMX_MIO_BOOT_REG_TIM0
value|CVMX_MIO_BOOT_REG_TIMX(0)
end_define

begin_comment
comment|/* The CN3XXX and CN58XX chips used to not have a LMC number     passed to the address macros. These are here to supply backwards     compatability with old code. Code should really use the new addresses     with bus arguments for support on other chips */
end_comment

begin_define
define|#
directive|define
name|CVMX_LMC_BIST_CTL
value|CVMX_LMCX_BIST_CTL(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_BIST_RESULT
value|CVMX_LMCX_BIST_RESULT(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_COMP_CTL
value|CVMX_LMCX_COMP_CTL(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_CTL
value|CVMX_LMCX_CTL(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_CTL1
value|CVMX_LMCX_CTL1(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_DCLK_CNT_HI
value|CVMX_LMCX_DCLK_CNT_HI(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_DCLK_CNT_LO
value|CVMX_LMCX_DCLK_CNT_LO(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_DCLK_CTL
value|CVMX_LMCX_DCLK_CTL(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_DDR2_CTL
value|CVMX_LMCX_DDR2_CTL(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_DELAY_CFG
value|CVMX_LMCX_DELAY_CFG(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_DLL_CTL
value|CVMX_LMCX_DLL_CTL(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_DUAL_MEMCFG
value|CVMX_LMCX_DUAL_MEMCFG(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_ECC_SYND
value|CVMX_LMCX_ECC_SYND(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_FADR
value|CVMX_LMCX_FADR(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_IFB_CNT_HI
value|CVMX_LMCX_IFB_CNT_HI(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_IFB_CNT_LO
value|CVMX_LMCX_IFB_CNT_LO(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_MEM_CFG0
value|CVMX_LMCX_MEM_CFG0(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_MEM_CFG1
value|CVMX_LMCX_MEM_CFG1(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_OPS_CNT_HI
value|CVMX_LMCX_OPS_CNT_HI(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_OPS_CNT_LO
value|CVMX_LMCX_OPS_CNT_LO(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_PLL_BWCTL
value|CVMX_LMCX_PLL_BWCTL(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_PLL_CTL
value|CVMX_LMCX_PLL_CTL(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_PLL_STATUS
value|CVMX_LMCX_PLL_STATUS(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_READ_LEVEL_CTL
value|CVMX_LMCX_READ_LEVEL_CTL(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_READ_LEVEL_DBG
value|CVMX_LMCX_READ_LEVEL_DBG(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_READ_LEVEL_RANKX
value|CVMX_LMCX_READ_LEVEL_RANKX(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_RODT_COMP_CTL
value|CVMX_LMCX_RODT_COMP_CTL(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_RODT_CTL
value|CVMX_LMCX_RODT_CTL(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_WODT_CTL
value|CVMX_LMCX_WODT_CTL0(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_WODT_CTL0
value|CVMX_LMCX_WODT_CTL0(0)
end_define

begin_define
define|#
directive|define
name|CVMX_LMC_WODT_CTL1
value|CVMX_LMCX_WODT_CTL1(0)
end_define

begin_comment
comment|/* The CN3XXX and CN58XX chips used to not have a TWSI bus number     passed to the address macros. These are here to supply backwards     compatability with old code. Code should really use the new addresses     with bus arguments for support on other chips */
end_comment

begin_define
define|#
directive|define
name|CVMX_MIO_TWS_INT
value|CVMX_MIO_TWSX_INT(0)
end_define

begin_define
define|#
directive|define
name|CVMX_MIO_TWS_SW_TWSI
value|CVMX_MIO_TWSX_SW_TWSI(0)
end_define

begin_define
define|#
directive|define
name|CVMX_MIO_TWS_SW_TWSI_EXT
value|CVMX_MIO_TWSX_SW_TWSI_EXT(0)
end_define

begin_define
define|#
directive|define
name|CVMX_MIO_TWS_TWSI_SW
value|CVMX_MIO_TWSX_TWSI_SW(0)
end_define

begin_comment
comment|/* The CN3XXX and CN58XX chips used to not have a SMI/MDIO bus number     passed to the address macros. These are here to supply backwards     compatability with old code. Code should really use the new addresses     with bus arguments for support on other chips */
end_comment

begin_define
define|#
directive|define
name|CVMX_SMI_CLK
value|CVMX_SMIX_CLK(0)
end_define

begin_define
define|#
directive|define
name|CVMX_SMI_CMD
value|CVMX_SMIX_CMD(0)
end_define

begin_define
define|#
directive|define
name|CVMX_SMI_EN
value|CVMX_SMIX_EN(0)
end_define

begin_define
define|#
directive|define
name|CVMX_SMI_RD_DAT
value|CVMX_SMIX_RD_DAT(0)
end_define

begin_define
define|#
directive|define
name|CVMX_SMI_WR_DAT
value|CVMX_SMIX_WR_DAT(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __CVMX_CSR_H__ */
end_comment

end_unit

