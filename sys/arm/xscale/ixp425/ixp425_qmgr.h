begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001-2005, Intel Corporation.  * All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the Intel Corporation nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ``AS IS''  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_XSCALE_IXP425_QMGR_H
end_ifndef

begin_define
define|#
directive|define
name|ARM_XSCALE_IXP425_QMGR_H
end_define

begin_define
define|#
directive|define
name|IX_QMGR_MAX_NUM_QUEUES
value|64
end_define

begin_define
define|#
directive|define
name|IX_QMGR_MIN_QUEUPP_QID
value|32
end_define

begin_define
define|#
directive|define
name|IX_QMGR_MIN_ENTRY_SIZE_IN_WORDS
value|16
end_define

begin_comment
comment|/* Total size of SRAM */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_AQM_SRAM_SIZE_IN_BYTES
value|0x4000
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_PRIORITY_0
value|0
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_PRIORITY_1
value|1
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_PRIORITY_2
value|2
end_define

begin_define
define|#
directive|define
name|IX_QMGR_NUM_PRIORITY_LEVELS
value|3
end_define

begin_comment
comment|/* number of priority levels */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_STATUS_E_BIT_MASK
value|0x1
end_define

begin_comment
comment|/* Empty */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_STATUS_NE_BIT_MASK
value|0x2
end_define

begin_comment
comment|/* Nearly Empty */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_STATUS_NF_BIT_MASK
value|0x4
end_define

begin_comment
comment|/* Nearly Full */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_STATUS_F_BIT_MASK
value|0x8
end_define

begin_comment
comment|/* Full */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_STATUS_UF_BIT_MASK
value|0x10
end_define

begin_comment
comment|/* Underflow */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_STATUS_OF_BIT_MASK
value|0x20
end_define

begin_comment
comment|/* Overflow */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_SOURCE_ID_E
value|0
end_define

begin_comment
comment|/* Q Empty after last read */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_SOURCE_ID_NE
value|1
end_define

begin_comment
comment|/* Q Nearly Empty after last read */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_SOURCE_ID_NF
value|2
end_define

begin_comment
comment|/* Q Nearly Full after last write */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_SOURCE_ID_F
value|3
end_define

begin_comment
comment|/* Q Full after last write */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_SOURCE_ID_NOT_E
value|4
end_define

begin_comment
comment|/* Q !Empty after last write */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_SOURCE_ID_NOT_NE
value|5
end_define

begin_comment
comment|/* Q !Nearly Empty after last write */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_SOURCE_ID_NOT_NF
value|6
end_define

begin_comment
comment|/* Q !Nearly Full after last read */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_SOURCE_ID_NOT_F
value|7
end_define

begin_comment
comment|/* Q !Full after last read */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_UNDERFLOW_BIT_OFFSET
value|0x0
end_define

begin_comment
comment|/* underflow bit mask */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_OVERFLOW_BIT_OFFSET
value|0x1
end_define

begin_comment
comment|/* overflow bit mask */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUEACC0_OFFSET
value|0x0000
end_define

begin_comment
comment|/* q 0 access register */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUEACC_SIZE
value|0x4
end_define

begin_comment
comment|/*words*/
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUELOWSTAT0_OFFSET
value|0x400
end_define

begin_comment
comment|/* Q status, q's 0-7 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUELOWSTAT1_OFFSET
value|0x404
end_define

begin_comment
comment|/* Q status, q's 8-15 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUELOWSTAT2_OFFSET
value|0x408
end_define

begin_comment
comment|/* Q status, q's 16-23 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUELOWSTAT3_OFFSET
value|0x40c
end_define

begin_comment
comment|/* Q status, q's 24-31 */
end_comment

begin_comment
comment|/* Queue status register Q status bits mask */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUELOWSTAT_QUE_STS_BITS_MASK
value|0xF
end_define

begin_comment
comment|/* Size of queue 0-31 status register */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUELOWSTAT_SIZE
value|0x4
end_define

begin_comment
comment|/*words*/
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUELOWSTAT_NUM_QUE_PER_WORD
value|8
end_define

begin_comment
comment|/* # status/word */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUEUOSTAT0_OFFSET
value|0x410
end_define

begin_comment
comment|/* Q UF/OF status, q's 0-15 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUEUOSTAT1_OFFSET
value|0x414
end_define

begin_comment
comment|/* Q UF/OF status, q's 16-31 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUEUOSTAT_NUM_QUE_PER_WORD
value|16
end_define

begin_comment
comment|/* # UF/OF status/word */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUEUPPSTAT0_OFFSET
value|0x418
end_define

begin_comment
comment|/* NE status, q's 32-63 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUEUPPSTAT1_OFFSET
value|0x41c
end_define

begin_comment
comment|/* F status, q's 32-63 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_INT0SRCSELREG0_OFFSET
value|0x420
end_define

begin_comment
comment|/* INT src select, q's 0-7 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_INT0SRCSELREG1_OFFSET
value|0x424
end_define

begin_comment
comment|/* INT src select, q's 8-15 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_INT0SRCSELREG2_OFFSET
value|0x428
end_define

begin_comment
comment|/* INT src select, q's 16-23 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_INT0SRCSELREG3_OFFSET
value|0x42c
end_define

begin_comment
comment|/* INT src select, q's 24-31 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_INTSRC_NUM_QUE_PER_WORD
value|8
end_define

begin_comment
comment|/* # INT src select/word */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUEIEREG0_OFFSET
value|0x430
end_define

begin_comment
comment|/* INT enable, q's 0-31 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUEIEREG1_OFFSET
value|0x434
end_define

begin_comment
comment|/* INT enable, q's 32-63 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QINTREG0_OFFSET
value|0x438
end_define

begin_comment
comment|/* INT status, q's 0-31 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QINTREG1_OFFSET
value|0x43c
end_define

begin_comment
comment|/* INT status, q's 32-63 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUECONFIG_BASE_OFFSET
value|0x2000
end_define

begin_comment
comment|/* Q config register, q 0 */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUECONFIG_SIZE
value|0x100
end_define

begin_comment
comment|/* total size of Q config regs*/
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUEBUFFER_SPACE_OFFSET
value|0x2100
end_define

begin_comment
comment|/* start of SRAM */
end_comment

begin_comment
comment|/* Total bits in a word */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|32
end_define

begin_comment
comment|/* Size of queue buffer space */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUE_BUFFER_SPACE_SIZE
value|0x1F00
end_define

begin_comment
comment|/*  * This macro will return the address of the access register for the  * queue  specified by qId  */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_ACCESS_ADDR_GET
parameter_list|(
name|qId
parameter_list|)
define|\
value|(((qId) * (IX_QMGR_QUEACC_SIZE * sizeof(uint32_t)))\ 	 + IX_QMGR_QUEACC0_OFFSET)
end_define

begin_comment
comment|/*   * Bit location of bit-3 of INT0SRCSELREG0 register to enabled  * sticky interrupt register.  */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_INT0SRCSELREG0_BIT3
value|3
end_define

begin_comment
comment|/*  * These defines are the bit offsets of the various fields of  * the queue configuration register.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_WRPTR_OFFSET
value|0x00
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_RDPTR_OFFSET
value|0x07
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_BADDR_OFFSET
value|0x0E
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_ESIZE_OFFSET
value|0x16
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_BSIZE_OFFSET
value|0x18
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_NE_OFFSET
value|0x1A
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_NF_OFFSET
value|0x1D
end_define

begin_define
define|#
directive|define
name|IX_QMGR_NE_NF_CLEAR_MASK
value|0x03FFFFFF
end_define

begin_define
define|#
directive|define
name|IX_QMGR_NE_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|IX_QMGR_NF_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|IX_QMGR_SIZE_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|IX_QMGR_ENTRY_SIZE_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|IX_QMGR_BADDR_MASK
value|0x003FC000
end_define

begin_define
define|#
directive|define
name|IX_QMGR_RDPTR_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|IX_QMGR_WRPTR_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|IX_QMGR_RDWRPTR_MASK
value|0x00003FFF
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_WRPTR_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|IX_QMGR_WRPTR_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_RDPTR_OFFSET
value|7
end_define

begin_define
define|#
directive|define
name|IX_QMGR_RDPTR_MASK
value|0x7F
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_BADDR_OFFSET
value|14
end_define

begin_define
define|#
directive|define
name|IX_QMGR_BADDR_MASK
value|0x3FC000
end_define

begin_comment
comment|/* XXX not used */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_ESIZE_OFFSET
value|22
end_define

begin_define
define|#
directive|define
name|IX_QMGR_ENTRY_SIZE_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_BSIZE_OFFSET
value|24
end_define

begin_define
define|#
directive|define
name|IX_QMGR_SIZE_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_NE_OFFSET
value|26
end_define

begin_define
define|#
directive|define
name|IX_QMGR_NE_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_NF_OFFSET
value|29
end_define

begin_define
define|#
directive|define
name|IX_QMGR_NF_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|IX_QMGR_RDWRPTR_MASK
value|0x00003FFF
end_define

begin_define
define|#
directive|define
name|IX_QMGR_NE_NF_CLEAR_MASK
value|0x03FFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IX_QMGR_BASE_ADDR_16_WORD_ALIGN
value|64
end_define

begin_define
define|#
directive|define
name|IX_QMGR_BASE_ADDR_16_WORD_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|IX_QMGR_AQM_ADDRESS_SPACE_SIZE_IN_WORDS
value|0x1000
end_define

begin_comment
comment|/* Base address of AQM SRAM */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_AQM_SRAM_BASE_ADDRESS_OFFSET
define|\
value|((IX_QMGR_QUECONFIG_BASE_OFFSET) + (IX_QMGR_QUECONFIG_SIZE))
end_define

begin_comment
comment|/* Min buffer size used for generating buffer size in QUECONFIG */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_MIN_BUFFER_SIZE
value|16
end_define

begin_comment
comment|/* Reset values of QMgr hardware registers */
end_comment

begin_define
define|#
directive|define
name|IX_QMGR_QUELOWSTAT_RESET_VALUE
value|0x33333333
end_define

begin_define
define|#
directive|define
name|IX_QMGR_QUEUOSTAT_RESET_VALUE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IX_QMGR_QUEUPPSTAT0_RESET_VALUE
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|IX_QMGR_QUEUPPSTAT1_RESET_VALUE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IX_QMGR_INT0SRCSELREG_RESET_VALUE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IX_QMGR_QUEIEREG_RESET_VALUE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IX_QMGR_QINTREG_RESET_VALUE
value|0xFFFFFFFF
end_define

begin_define
define|#
directive|define
name|IX_QMGR_QUECONFIG_RESET_VALUE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IX_QMGR_QUELOWSTAT_BITS_PER_Q
define|\
value|(BITS_PER_WORD/IX_QMGR_QUELOWSTAT_NUM_QUE_PER_WORD)
end_define

begin_define
define|#
directive|define
name|IX_QMGR_QUELOWSTAT_QID_MASK
value|0x7
end_define

begin_define
define|#
directive|define
name|IX_QMGR_Q_CONFIG_ADDR_GET
parameter_list|(
name|qId
parameter_list|)
define|\
value|(((qId) * sizeof(uint32_t)) + IX_QMGR_QUECONFIG_BASE_OFFSET)
end_define

begin_define
define|#
directive|define
name|IX_QMGR_ENTRY1_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|IX_QMGR_ENTRY2_OFFSET
value|1
end_define

begin_define
define|#
directive|define
name|IX_QMGR_ENTRY4_OFFSET
value|3
end_define

begin_function_decl
name|int
name|ixpqmgr_qconfig
parameter_list|(
name|int
name|qId
parameter_list|,
name|int
name|qSizeInWords
parameter_list|,
name|int
name|ne
parameter_list|,
name|int
name|nf
parameter_list|,
name|int
name|srcSel
parameter_list|,
name|void
function_decl|(
modifier|*
name|cb
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|cbarg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixpqmgr_qwrite
parameter_list|(
name|int
name|qId
parameter_list|,
name|uint32_t
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixpqmgr_qread
parameter_list|(
name|int
name|qId
parameter_list|,
name|uint32_t
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ixpqmgr_qreadm
parameter_list|(
name|int
name|qId
parameter_list|,
name|uint32_t
name|n
parameter_list|,
name|uint32_t
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ixpqmgr_getqstatus
parameter_list|(
name|int
name|qId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ixpqmgr_getqconfig
parameter_list|(
name|int
name|qId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixpqmgr_notify_enable
parameter_list|(
name|int
name|qId
parameter_list|,
name|int
name|srcSel
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixpqmgr_notify_disable
parameter_list|(
name|int
name|qId
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ixpqmgr_dump
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARM_XSCALE_IXP425_QMGR_H */
end_comment

end_unit

