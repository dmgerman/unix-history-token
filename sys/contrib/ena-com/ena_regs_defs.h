begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * BSD LICENSE  *  * Copyright (c) 2015-2017 Amazon.com, Inc. or its affiliates.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * * Redistributions of source code must retain the above copyright  * notice, this list of conditions and the following disclaimer.  * * Redistributions in binary form must reproduce the above copyright  * notice, this list of conditions and the following disclaimer in  * the documentation and/or other materials provided with the  * distribution.  * * Neither the name of copyright holder nor the names of its  * contributors may be used to endorse or promote products derived  * from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ENA_REGS_H_
end_ifndef

begin_define
define|#
directive|define
name|_ENA_REGS_H_
end_define

begin_comment
comment|/* ena_registers offsets */
end_comment

begin_define
define|#
directive|define
name|ENA_REGS_VERSION_OFF
value|0x0
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CONTROLLER_VERSION_OFF
value|0x4
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CAPS_OFF
value|0x8
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CAPS_EXT_OFF
value|0xc
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AQ_BASE_LO_OFF
value|0x10
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AQ_BASE_HI_OFF
value|0x14
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AQ_CAPS_OFF
value|0x18
end_define

begin_define
define|#
directive|define
name|ENA_REGS_ACQ_BASE_LO_OFF
value|0x20
end_define

begin_define
define|#
directive|define
name|ENA_REGS_ACQ_BASE_HI_OFF
value|0x24
end_define

begin_define
define|#
directive|define
name|ENA_REGS_ACQ_CAPS_OFF
value|0x28
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AQ_DB_OFF
value|0x2c
end_define

begin_define
define|#
directive|define
name|ENA_REGS_ACQ_TAIL_OFF
value|0x30
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AENQ_CAPS_OFF
value|0x34
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AENQ_BASE_LO_OFF
value|0x38
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AENQ_BASE_HI_OFF
value|0x3c
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AENQ_HEAD_DB_OFF
value|0x40
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AENQ_TAIL_OFF
value|0x44
end_define

begin_define
define|#
directive|define
name|ENA_REGS_INTR_MASK_OFF
value|0x4c
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_CTL_OFF
value|0x54
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_OFF
value|0x58
end_define

begin_define
define|#
directive|define
name|ENA_REGS_MMIO_REG_READ_OFF
value|0x5c
end_define

begin_define
define|#
directive|define
name|ENA_REGS_MMIO_RESP_LO_OFF
value|0x60
end_define

begin_define
define|#
directive|define
name|ENA_REGS_MMIO_RESP_HI_OFF
value|0x64
end_define

begin_define
define|#
directive|define
name|ENA_REGS_RSS_IND_ENTRY_UPDATE_OFF
value|0x68
end_define

begin_comment
comment|/* version register */
end_comment

begin_define
define|#
directive|define
name|ENA_REGS_VERSION_MINOR_VERSION_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|ENA_REGS_VERSION_MAJOR_VERSION_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ENA_REGS_VERSION_MAJOR_VERSION_MASK
value|0xff00
end_define

begin_comment
comment|/* controller_version register */
end_comment

begin_define
define|#
directive|define
name|ENA_REGS_CONTROLLER_VERSION_SUBMINOR_VERSION_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CONTROLLER_VERSION_MINOR_VERSION_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CONTROLLER_VERSION_MINOR_VERSION_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CONTROLLER_VERSION_MAJOR_VERSION_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CONTROLLER_VERSION_MAJOR_VERSION_MASK
value|0xff0000
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CONTROLLER_VERSION_IMPL_ID_SHIFT
value|24
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CONTROLLER_VERSION_IMPL_ID_MASK
value|0xff000000
end_define

begin_comment
comment|/* caps register */
end_comment

begin_define
define|#
directive|define
name|ENA_REGS_CAPS_CONTIGUOUS_QUEUE_REQUIRED_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CAPS_RESET_TIMEOUT_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CAPS_RESET_TIMEOUT_MASK
value|0x3e
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CAPS_DMA_ADDR_WIDTH_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CAPS_DMA_ADDR_WIDTH_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CAPS_ADMIN_CMD_TO_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ENA_REGS_CAPS_ADMIN_CMD_TO_MASK
value|0xf0000
end_define

begin_comment
comment|/* aq_caps register */
end_comment

begin_define
define|#
directive|define
name|ENA_REGS_AQ_CAPS_AQ_DEPTH_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AQ_CAPS_AQ_ENTRY_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AQ_CAPS_AQ_ENTRY_SIZE_MASK
value|0xffff0000
end_define

begin_comment
comment|/* acq_caps register */
end_comment

begin_define
define|#
directive|define
name|ENA_REGS_ACQ_CAPS_ACQ_DEPTH_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|ENA_REGS_ACQ_CAPS_ACQ_ENTRY_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ENA_REGS_ACQ_CAPS_ACQ_ENTRY_SIZE_MASK
value|0xffff0000
end_define

begin_comment
comment|/* aenq_caps register */
end_comment

begin_define
define|#
directive|define
name|ENA_REGS_AENQ_CAPS_AENQ_DEPTH_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AENQ_CAPS_AENQ_ENTRY_SIZE_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ENA_REGS_AENQ_CAPS_AENQ_ENTRY_SIZE_MASK
value|0xffff0000
end_define

begin_comment
comment|/* dev_ctl register */
end_comment

begin_define
define|#
directive|define
name|ENA_REGS_DEV_CTL_DEV_RESET_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_CTL_AQ_RESTART_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_CTL_AQ_RESTART_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_CTL_QUIESCENT_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_CTL_QUIESCENT_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_CTL_IO_RESUME_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_CTL_IO_RESUME_MASK
value|0x8
end_define

begin_comment
comment|/* dev_sts register */
end_comment

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_READY_MASK
value|0x1
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_AQ_RESTART_IN_PROGRESS_SHIFT
value|1
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_AQ_RESTART_IN_PROGRESS_MASK
value|0x2
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_AQ_RESTART_FINISHED_SHIFT
value|2
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_AQ_RESTART_FINISHED_MASK
value|0x4
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_RESET_IN_PROGRESS_SHIFT
value|3
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_RESET_IN_PROGRESS_MASK
value|0x8
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_RESET_FINISHED_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_RESET_FINISHED_MASK
value|0x10
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_FATAL_ERROR_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_FATAL_ERROR_MASK
value|0x20
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_QUIESCENT_STATE_IN_PROGRESS_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_QUIESCENT_STATE_IN_PROGRESS_MASK
value|0x40
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_QUIESCENT_STATE_ACHIEVED_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|ENA_REGS_DEV_STS_QUIESCENT_STATE_ACHIEVED_MASK
value|0x80
end_define

begin_comment
comment|/* mmio_reg_read register */
end_comment

begin_define
define|#
directive|define
name|ENA_REGS_MMIO_REG_READ_REQ_ID_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|ENA_REGS_MMIO_REG_READ_REG_OFF_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ENA_REGS_MMIO_REG_READ_REG_OFF_MASK
value|0xffff0000
end_define

begin_comment
comment|/* rss_ind_entry_update register */
end_comment

begin_define
define|#
directive|define
name|ENA_REGS_RSS_IND_ENTRY_UPDATE_INDEX_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|ENA_REGS_RSS_IND_ENTRY_UPDATE_CQ_IDX_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|ENA_REGS_RSS_IND_ENTRY_UPDATE_CQ_IDX_MASK
value|0xffff0000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*_ENA_REGS_H_ */
end_comment

end_unit

