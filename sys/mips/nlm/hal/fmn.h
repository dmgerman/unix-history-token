begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2003-2011 Netlogic Microsystems (Netlogic). All rights  * reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions are  * met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * THIS SOFTWARE IS PROVIDED BY Netlogic Microsystems ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL NETLOGIC OR CONTRIBUTORS BE  * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * NETLOGIC_BSD  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NLM_FMNV2_H__
end_ifndef

begin_define
define|#
directive|define
name|__NLM_FMNV2_H__
end_define

begin_comment
comment|/** * @file_name fmn.h * @author Netlogic Microsystems * @brief HAL for Fast message network V2 */
end_comment

begin_comment
comment|/* FMN configuration registers */
end_comment

begin_define
define|#
directive|define
name|CMS_OUTPUTQ_CONFIG
parameter_list|(
name|i
parameter_list|)
value|((i)*2)
end_define

begin_define
define|#
directive|define
name|CMS_MAX_OUTPUTQ
value|1024
end_define

begin_define
define|#
directive|define
name|CMS_OUTPUTQ_CREDIT_CFG
value|(0x2000/4)
end_define

begin_define
define|#
directive|define
name|CMS_MSG_CONFIG
value|(0x2008/4)
end_define

begin_define
define|#
directive|define
name|CMS_MSG_ERR
value|(0x2010/4)
end_define

begin_define
define|#
directive|define
name|CMS_TRACE_CONFIG
value|(0x2018/4)
end_define

begin_define
define|#
directive|define
name|CMS_TRACE_BASE_ADDR
value|(0x2020/4)
end_define

begin_define
define|#
directive|define
name|CMS_TRACE_LIMIT_ADDR
value|(0x2028/4)
end_define

begin_define
define|#
directive|define
name|CMS_TRACE_CURRENT_ADDR
value|(0x2030/4)
end_define

begin_define
define|#
directive|define
name|CMS_MSG_ENDIAN_SWAP
value|(0x2038/4)
end_define

begin_define
define|#
directive|define
name|CMS_CPU_PUSHQ
parameter_list|(
name|node
parameter_list|,
name|core
parameter_list|,
name|thread
parameter_list|,
name|vc
parameter_list|)
define|\
value|(((node)<<10) | ((core)<<4) | ((thread)<<2) | ((vc)<<0))
end_define

begin_define
define|#
directive|define
name|CMS_POPQ
parameter_list|(
name|node
parameter_list|,
name|queue
parameter_list|)
value|(((node)<<10) | (queue))
end_define

begin_define
define|#
directive|define
name|CMS_IO_PUSHQ
parameter_list|(
name|node
parameter_list|,
name|queue
parameter_list|)
value|(((node)<<10) | (queue))
end_define

begin_define
define|#
directive|define
name|CMS_POPQ_QID
parameter_list|(
name|i
parameter_list|)
value|(128+(i))
end_define

begin_comment
comment|/* FMN Level Interrupt Type */
end_comment

begin_define
define|#
directive|define
name|CMS_LVL_INTR_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|CMS_LVL_LOW_WATERMARK
value|1
end_define

begin_define
define|#
directive|define
name|CMS_LVL_HI_WATERMARK
value|2
end_define

begin_comment
comment|/* FMN Level interrupt trigger values */
end_comment

begin_define
define|#
directive|define
name|CMS_QUEUE_NON_EMPTY
value|0
end_define

begin_define
define|#
directive|define
name|CMS_QUEUE_QUARTER_FULL
value|1
end_define

begin_define
define|#
directive|define
name|CMS_QUEUE_HALF_FULL
value|2
end_define

begin_define
define|#
directive|define
name|CMS_QUEUE_THREE_QUARTER_FULL
value|3
end_define

begin_define
define|#
directive|define
name|CMS_QUEUE_FULL
value|4
end_define

begin_comment
comment|/* FMN Timer Interrupt Type */
end_comment

begin_define
define|#
directive|define
name|CMS_TIMER_INTR_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|CMS_TIMER_CONSUMER
value|1
end_define

begin_define
define|#
directive|define
name|CMS_TIMER_PRODUCER
value|1
end_define

begin_comment
comment|/* FMN timer interrupt trigger values */
end_comment

begin_define
define|#
directive|define
name|CMS_TWO_POW_EIGHT_CYCLES
value|0
end_define

begin_define
define|#
directive|define
name|CMS_TWO_POW_TEN_CYCLES
value|1
end_define

begin_define
define|#
directive|define
name|CMS_TWO_POW_TWELVE_CYCLES
value|2
end_define

begin_define
define|#
directive|define
name|CMS_TWO_POW_FOURTEEN_CYCLES
value|3
end_define

begin_define
define|#
directive|define
name|CMS_TWO_POW_SIXTEEN_CYCLES
value|4
end_define

begin_define
define|#
directive|define
name|CMS_TWO_POW_EIGHTTEEN_CYCLES
value|5
end_define

begin_define
define|#
directive|define
name|CMS_TWO_POW_TWENTY_CYCLES
value|6
end_define

begin_define
define|#
directive|define
name|CMS_TWO_POW_TWENTYTWO_CYCLES
value|7
end_define

begin_define
define|#
directive|define
name|CMS_QUEUE_ENA
value|1ULL
end_define

begin_define
define|#
directive|define
name|CMS_QUEUE_DIS
value|0
end_define

begin_define
define|#
directive|define
name|CMS_SPILL_ENA
value|1ULL
end_define

begin_define
define|#
directive|define
name|CMS_SPILL_DIS
value|0
end_define

begin_define
define|#
directive|define
name|CMS_MAX_VCPU_VC
value|4
end_define

begin_comment
comment|/* Each XLP chip can hold upto 32K messages on the chip itself */
end_comment

begin_define
define|#
directive|define
name|CMS_ON_CHIP_MESG_SPACE
value|(32*1024)
end_define

begin_define
define|#
directive|define
name|CMS_MAX_ONCHIP_SEGMENTS
value|1024
end_define

begin_define
define|#
directive|define
name|CMS_MAX_SPILL_SEGMENTS_PER_QUEUE
value|64
end_define

begin_comment
comment|/* FMN Network error */
end_comment

begin_define
define|#
directive|define
name|CMS_ILLEGAL_DST_ERROR
value|0x100
end_define

begin_define
define|#
directive|define
name|CMS_BIU_TIMEOUT_ERROR
value|0x080
end_define

begin_define
define|#
directive|define
name|CMS_BIU_ERROR
value|0x040
end_define

begin_define
define|#
directive|define
name|CMS_SPILL_FILL_UNCORRECT_ECC_ERROR
value|0x020
end_define

begin_define
define|#
directive|define
name|CMS_SPILL_FILL_CORRECT_ECC_ERROR
value|0x010
end_define

begin_define
define|#
directive|define
name|CMS_SPILL_UNCORRECT_ECC_ERROR
value|0x008
end_define

begin_define
define|#
directive|define
name|CMS_SPILL_CORRECT_ECC_ERROR
value|0x004
end_define

begin_define
define|#
directive|define
name|CMS_OUTPUTQ_UNCORRECT_ECC_ERROR
value|0x002
end_define

begin_define
define|#
directive|define
name|CMS_OUTPUTQ_CORRECT_ECC_ERROR
value|0x001
end_define

begin_comment
comment|/* worst case, a single entry message consists of a 4 byte header  * and an 8-byte entry = 12 bytes in total  */
end_comment

begin_define
define|#
directive|define
name|CMS_SINGLE_ENTRY_MSG_SIZE
value|12
end_define

begin_comment
comment|/* total spill memory needed for one FMN queue */
end_comment

begin_define
define|#
directive|define
name|CMS_PER_QUEUE_SPILL_MEM
parameter_list|(
name|spilltotmsgs
parameter_list|)
define|\
value|((spilltotmsgs) * (CMS_SINGLE_ENTRY_MSG_SIZE))
end_define

begin_comment
comment|/* FMN Src station id's */
end_comment

begin_define
define|#
directive|define
name|CMS_CPU0_SRC_STID
value|(0<< 4)
end_define

begin_define
define|#
directive|define
name|CMS_CPU1_SRC_STID
value|(1<< 4)
end_define

begin_define
define|#
directive|define
name|CMS_CPU2_SRC_STID
value|(2<< 4)
end_define

begin_define
define|#
directive|define
name|CMS_CPU3_SRC_STID
value|(3<< 4)
end_define

begin_define
define|#
directive|define
name|CMS_CPU4_SRC_STID
value|(4<< 4)
end_define

begin_define
define|#
directive|define
name|CMS_CPU5_SRC_STID
value|(5<< 4)
end_define

begin_define
define|#
directive|define
name|CMS_CPU6_SRC_STID
value|(6<< 4)
end_define

begin_define
define|#
directive|define
name|CMS_CPU7_SRC_STID
value|(7<< 4)
end_define

begin_define
define|#
directive|define
name|CMS_PCIE0_SRC_STID
value|256
end_define

begin_define
define|#
directive|define
name|CMS_PCIE1_SRC_STID
value|258
end_define

begin_define
define|#
directive|define
name|CMS_PCIE2_SRC_STID
value|260
end_define

begin_define
define|#
directive|define
name|CMS_PCIE3_SRC_STID
value|262
end_define

begin_define
define|#
directive|define
name|CMS_DTE_SRC_STID
value|264
end_define

begin_define
define|#
directive|define
name|CMS_RSA_ECC_SRC_STID
value|272
end_define

begin_define
define|#
directive|define
name|CMS_CRYPTO_SRC_STID
value|281
end_define

begin_define
define|#
directive|define
name|CMS_CMP_SRC_STID
value|298
end_define

begin_define
define|#
directive|define
name|CMS_POE_SRC_STID
value|384
end_define

begin_define
define|#
directive|define
name|CMS_NAE_SRC_STID
value|476
end_define

begin_comment
comment|/* POPQ related defines */
end_comment

begin_define
define|#
directive|define
name|CMS_POPQID_START
value|128
end_define

begin_define
define|#
directive|define
name|CMS_POPQID_END
value|255
end_define

begin_define
define|#
directive|define
name|CMS_INT_RCVD
value|0x800000000000000ULL
end_define

begin_define
define|#
directive|define
name|nlm_read_cms_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|)
value|nlm_read_reg64_xkphys(b,r)
end_define

begin_define
define|#
directive|define
name|nlm_write_cms_reg
parameter_list|(
name|b
parameter_list|,
name|r
parameter_list|,
name|v
parameter_list|)
value|nlm_write_reg64_xkphys(b,r,v)
end_define

begin_define
define|#
directive|define
name|nlm_get_cms_pcibase
parameter_list|(
name|node
parameter_list|)
define|\
value|nlm_pcicfg_base(XLP_IO_CMS_OFFSET(node))
end_define

begin_define
define|#
directive|define
name|nlm_get_cms_regbase
parameter_list|(
name|node
parameter_list|)
define|\
value|nlm_xkphys_map_pcibar0(nlm_get_cms_pcibase(node))
end_define

begin_define
define|#
directive|define
name|XLP_CMS_ON_CHIP_PER_QUEUE_SPACE
parameter_list|(
name|node
parameter_list|)
define|\
value|((XLP_CMS_ON_CHIP_MESG_SPACE)/			\ 		(nlm_read_reg(nlm_pcibase_cms(node),		\ 		XLP_PCI_DEVINFO_REG0))
end_define

begin_comment
comment|/* total spill memory needed */
end_comment

begin_define
define|#
directive|define
name|XLP_CMS_TOTAL_SPILL_MEM
parameter_list|(
name|node
parameter_list|,
name|spilltotmsgs
parameter_list|)
define|\
value|((XLP_CMS_PER_QUEUE_SPILL_MEM(spilltotmsgs)) *	\ 		(nlm_read_reg(nlm_pcibase_cms(node),		\ 		XLP_PCI_DEVINFO_REG0))
end_define

begin_define
define|#
directive|define
name|CMS_TOTAL_QUEUE_SIZE
parameter_list|(
name|node
parameter_list|,
name|spilltotmsgs
parameter_list|)
define|\
value|((spilltotmsgs) + (CMS_ON_CHIP_PER_QUEUE_SPACE(node)))
end_define

begin_enum
enum|enum
name|fmn_swcode
block|{
name|FMN_SWCODE_CPU0
init|=
literal|1
block|,
name|FMN_SWCODE_CPU1
block|,
name|FMN_SWCODE_CPU2
block|,
name|FMN_SWCODE_CPU3
block|,
name|FMN_SWCODE_CPU4
block|,
name|FMN_SWCODE_CPU5
block|,
name|FMN_SWCODE_CPU6
block|,
name|FMN_SWCODE_CPU7
block|,
name|FMN_SWCODE_CPU8
block|,
name|FMN_SWCODE_CPU9
block|,
name|FMN_SWCODE_CPU10
block|,
name|FMN_SWCODE_CPU11
block|,
name|FMN_SWCODE_CPU12
block|,
name|FMN_SWCODE_CPU13
block|,
name|FMN_SWCODE_CPU14
block|,
name|FMN_SWCODE_CPU15
block|,
name|FMN_SWCODE_CPU16
block|,
name|FMN_SWCODE_CPU17
block|,
name|FMN_SWCODE_CPU18
block|,
name|FMN_SWCODE_CPU19
block|,
name|FMN_SWCODE_CPU20
block|,
name|FMN_SWCODE_CPU21
block|,
name|FMN_SWCODE_CPU22
block|,
name|FMN_SWCODE_CPU23
block|,
name|FMN_SWCODE_CPU24
block|,
name|FMN_SWCODE_CPU25
block|,
name|FMN_SWCODE_CPU26
block|,
name|FMN_SWCODE_CPU27
block|,
name|FMN_SWCODE_CPU28
block|,
name|FMN_SWCODE_CPU29
block|,
name|FMN_SWCODE_CPU30
block|,
name|FMN_SWCODE_CPU31
block|,
name|FMN_SWCODE_CPU32
block|,
name|FMN_SWCODE_PCIE0
block|,
name|FMN_SWCODE_PCIE1
block|,
name|FMN_SWCODE_PCIE2
block|,
name|FMN_SWCODE_PCIE3
block|,
name|FMN_SWCODE_DTE
block|,
name|FMN_SWCODE_CRYPTO
block|,
name|FMN_SWCODE_RSA
block|,
name|FMN_SWCODE_CMP
block|,
name|FMN_SWCODE_POE
block|,
name|FMN_SWCODE_NAE
block|, }
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|uint64_t
name|nlm_cms_spill_total_messages
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint32_t
name|nlm_cms_total_stations
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|uint64_t
name|cms_base_addr
parameter_list|(
name|int
name|node
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nlm_cms_verify_credit_config
parameter_list|(
name|int
name|spill_en
parameter_list|,
name|int
name|tot_credit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nlm_cms_get_oc_space
parameter_list|(
name|int
name|qsize
parameter_list|,
name|int
name|max_queues
parameter_list|,
name|int
name|qid
parameter_list|,
name|int
modifier|*
name|ocbase
parameter_list|,
name|int
modifier|*
name|ocstart
parameter_list|,
name|int
modifier|*
name|ocend
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_setup_credits
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|destid
parameter_list|,
name|int
name|srcid
parameter_list|,
name|int
name|credit
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nlm_cms_config_onchip_queue
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|uint64_t
name|cms_spill_base
parameter_list|,
name|int
name|qid
parameter_list|,
name|int
name|spill_en
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_default_setup
parameter_list|(
name|int
name|node
parameter_list|,
name|uint64_t
name|spill_base
parameter_list|,
name|int
name|spill_en
parameter_list|,
name|int
name|popq_en
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|nlm_cms_get_onchip_queue
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|qid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_set_onchip_queue
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|qid
parameter_list|,
name|uint64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_per_queue_level_intr
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|qid
parameter_list|,
name|int
name|sub_type
parameter_list|,
name|int
name|intr_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_level_intr
parameter_list|(
name|int
name|node
parameter_list|,
name|int
name|sub_type
parameter_list|,
name|int
name|intr_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_per_queue_timer_intr
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|qid
parameter_list|,
name|int
name|sub_type
parameter_list|,
name|int
name|intr_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_timer_intr
parameter_list|(
name|int
name|node
parameter_list|,
name|int
name|en
parameter_list|,
name|int
name|sub_type
parameter_list|,
name|int
name|intr_val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nlm_cms_outputq_intr_check
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|qid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_outputq_clr_intr
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|qid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_illegal_dst_error_intr
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_timeout_error_intr
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_biu_error_resp_intr
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_spill_uncorrectable_ecc_error_intr
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_spill_correctable_ecc_error_intr
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_outputq_uncorrectable_ecc_error_intr
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_outputq_correctable_ecc_error_intr
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint64_t
name|nlm_cms_network_error_status
parameter_list|(
name|uint64_t
name|base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nlm_cms_get_net_error_code
parameter_list|(
name|uint64_t
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nlm_cms_get_net_error_syndrome
parameter_list|(
name|uint64_t
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nlm_cms_get_net_error_ramindex
parameter_list|(
name|uint64_t
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nlm_cms_get_net_error_outputq
parameter_list|(
name|uint64_t
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_trace_setup
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|en
parameter_list|,
name|uint64_t
name|trace_base
parameter_list|,
name|uint64_t
name|trace_limit
parameter_list|,
name|int
name|match_dstid_en
parameter_list|,
name|int
name|dst_id
parameter_list|,
name|int
name|match_srcid_en
parameter_list|,
name|int
name|src_id
parameter_list|,
name|int
name|wrap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|nlm_cms_endian_byte_swap
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|en
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint8_t
name|xlp_msg_send
parameter_list|(
name|uint8_t
name|vc
parameter_list|,
name|uint8_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nlm_cms_alloc_spill_q
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|qid
parameter_list|,
name|uint64_t
name|spill_base
parameter_list|,
name|int
name|nsegs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|nlm_cms_alloc_onchip_q
parameter_list|(
name|uint64_t
name|base
parameter_list|,
name|int
name|qid
parameter_list|,
name|int
name|nsegs
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

