begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Advanced Computing Technologies LLC  * Written by: John H. Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/pciio.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|"pciconf.h"
end_include

begin_struct
struct|struct
name|bit_table
block|{
name|uint32_t
name|mask
decl_stmt|;
specifier|const
name|char
modifier|*
name|desc
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Error indicators in the PCI status register (PCIR_STATUS). */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|bit_table
name|pci_status
index|[]
init|=
block|{
block|{
name|PCIM_STATUS_MDPERR
block|,
literal|"Master Data Parity Error"
block|}
block|,
block|{
name|PCIM_STATUS_STABORT
block|,
literal|"Sent Target-Abort"
block|}
block|,
block|{
name|PCIM_STATUS_RTABORT
block|,
literal|"Received Target-Abort"
block|}
block|,
block|{
name|PCIM_STATUS_RMABORT
block|,
literal|"Received Master-Abort"
block|}
block|,
block|{
name|PCIM_STATUS_SERR
block|,
literal|"Signalled System Error"
block|}
block|,
block|{
name|PCIM_STATUS_PERR
block|,
literal|"Detected Parity Error"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Valid error indicator bits in PCIR_STATUS. */
end_comment

begin_define
define|#
directive|define
name|PCI_ERRORS
value|(PCIM_STATUS_MDPERR | PCIM_STATUS_STABORT |	\ 			 PCIM_STATUS_RTABORT | PCIM_STATUS_RMABORT |	\ 			 PCIM_STATUS_SERR | PCIM_STATUS_PERR)
end_define

begin_comment
comment|/* Error indicators in the PCI-Express device status register. */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|bit_table
name|pcie_device_status
index|[]
init|=
block|{
block|{
name|PCIEM_STA_CORRECTABLE_ERROR
block|,
literal|"Correctable Error Detected"
block|}
block|,
block|{
name|PCIEM_STA_NON_FATAL_ERROR
block|,
literal|"Non-Fatal Error Detected"
block|}
block|,
block|{
name|PCIEM_STA_FATAL_ERROR
block|,
literal|"Fatal Error Detected"
block|}
block|,
block|{
name|PCIEM_STA_UNSUPPORTED_REQ
block|,
literal|"Unsupported Request Detected"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Valid error indicator bits in the PCI-Express device status register. */
end_comment

begin_define
define|#
directive|define
name|PCIE_ERRORS
value|(PCIEM_STA_CORRECTABLE_ERROR |		\ 			 PCIEM_STA_NON_FATAL_ERROR |			\ 			 PCIEM_STA_FATAL_ERROR |			\ 			 PCIEM_STA_UNSUPPORTED_REQ)
end_define

begin_comment
comment|/* AER Uncorrected errors. */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|bit_table
name|aer_uc
index|[]
init|=
block|{
block|{
name|PCIM_AER_UC_TRAINING_ERROR
block|,
literal|"Link Training Error"
block|}
block|,
block|{
name|PCIM_AER_UC_DL_PROTOCOL_ERROR
block|,
literal|"Data Link Protocol Error"
block|}
block|,
block|{
name|PCIM_AER_UC_SURPRISE_LINK_DOWN
block|,
literal|"Surprise Link Down Error"
block|}
block|,
block|{
name|PCIM_AER_UC_POISONED_TLP
block|,
literal|"Poisoned TLP"
block|}
block|,
block|{
name|PCIM_AER_UC_FC_PROTOCOL_ERROR
block|,
literal|"Flow Control Protocol Error"
block|}
block|,
block|{
name|PCIM_AER_UC_COMPLETION_TIMEOUT
block|,
literal|"Completion Timeout"
block|}
block|,
block|{
name|PCIM_AER_UC_COMPLETER_ABORT
block|,
literal|"Completer Abort"
block|}
block|,
block|{
name|PCIM_AER_UC_UNEXPECTED_COMPLETION
block|,
literal|"Unexpected Completion"
block|}
block|,
block|{
name|PCIM_AER_UC_RECEIVER_OVERFLOW
block|,
literal|"Receiver Overflow Error"
block|}
block|,
block|{
name|PCIM_AER_UC_MALFORMED_TLP
block|,
literal|"Malformed TLP"
block|}
block|,
block|{
name|PCIM_AER_UC_ECRC_ERROR
block|,
literal|"ECRC Error"
block|}
block|,
block|{
name|PCIM_AER_UC_UNSUPPORTED_REQUEST
block|,
literal|"Unsupported Request"
block|}
block|,
block|{
name|PCIM_AER_UC_ACS_VIOLATION
block|,
literal|"ACS Violation"
block|}
block|,
block|{
name|PCIM_AER_UC_INTERNAL_ERROR
block|,
literal|"Uncorrectable Internal Error"
block|}
block|,
block|{
name|PCIM_AER_UC_MC_BLOCKED_TLP
block|,
literal|"MC Blocked TLP"
block|}
block|,
block|{
name|PCIM_AER_UC_ATOMIC_EGRESS_BLK
block|,
literal|"AtomicOp Egress Blocked"
block|}
block|,
block|{
name|PCIM_AER_UC_TLP_PREFIX_BLOCKED
block|,
literal|"TLP Prefix Blocked Error"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* AER Corrected errors. */
end_comment

begin_decl_stmt
specifier|static
name|struct
name|bit_table
name|aer_cor
index|[]
init|=
block|{
block|{
name|PCIM_AER_COR_RECEIVER_ERROR
block|,
literal|"Receiver Error"
block|}
block|,
block|{
name|PCIM_AER_COR_BAD_TLP
block|,
literal|"Bad TLP"
block|}
block|,
block|{
name|PCIM_AER_COR_BAD_DLLP
block|,
literal|"Bad DLLP"
block|}
block|,
block|{
name|PCIM_AER_COR_REPLAY_ROLLOVER
block|,
literal|"REPLAY_NUM Rollover"
block|}
block|,
block|{
name|PCIM_AER_COR_REPLAY_TIMEOUT
block|,
literal|"Replay Timer Timeout"
block|}
block|,
block|{
name|PCIM_AER_COR_ADVISORY_NF_ERROR
block|,
literal|"Advisory Non-Fatal Error"
block|}
block|,
block|{
name|PCIM_AER_COR_INTERNAL_ERROR
block|,
literal|"Corrected Internal Error"
block|}
block|,
block|{
name|PCIM_AER_COR_HEADER_LOG_OVFLOW
block|,
literal|"Header Log Overflow"
block|}
block|,
block|{
literal|0
block|,
name|NULL
block|}
block|, }
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|void
name|print_bits
parameter_list|(
specifier|const
name|char
modifier|*
name|header
parameter_list|,
name|struct
name|bit_table
modifier|*
name|table
parameter_list|,
name|uint32_t
name|mask
parameter_list|)
block|{
name|int
name|first
decl_stmt|;
name|first
operator|=
literal|1
expr_stmt|;
for|for
control|(
init|;
name|table
operator|->
name|desc
operator|!=
name|NULL
condition|;
name|table
operator|++
control|)
if|if
condition|(
name|mask
operator|&
name|table
operator|->
name|mask
condition|)
block|{
if|if
condition|(
name|first
condition|)
block|{
name|printf
argument_list|(
literal|"%14s = "
argument_list|,
name|header
argument_list|)
expr_stmt|;
name|first
operator|=
literal|0
expr_stmt|;
block|}
else|else
name|printf
argument_list|(
literal|"                 "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s\n"
argument_list|,
name|table
operator|->
name|desc
argument_list|)
expr_stmt|;
name|mask
operator|&=
operator|~
name|table
operator|->
name|mask
expr_stmt|;
block|}
if|if
condition|(
name|mask
operator|!=
literal|0
condition|)
block|{
if|if
condition|(
name|first
condition|)
name|printf
argument_list|(
literal|"%14s = "
argument_list|,
name|header
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
literal|"                 "
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Unknown: 0x%08x\n"
argument_list|,
name|mask
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|list_errors
parameter_list|(
name|int
name|fd
parameter_list|,
name|struct
name|pci_conf
modifier|*
name|p
parameter_list|)
block|{
name|uint32_t
name|mask
decl_stmt|,
name|severity
decl_stmt|;
name|uint16_t
name|sta
decl_stmt|,
name|aer
decl_stmt|;
name|uint8_t
name|pcie
decl_stmt|;
comment|/* First check for standard PCI errors. */
name|sta
operator|=
name|read_config
argument_list|(
name|fd
argument_list|,
operator|&
name|p
operator|->
name|pc_sel
argument_list|,
name|PCIR_STATUS
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|print_bits
argument_list|(
literal|"PCI errors"
argument_list|,
name|pci_status
argument_list|,
name|sta
operator|&
name|PCI_ERRORS
argument_list|)
expr_stmt|;
comment|/* See if this is a PCI-express device. */
name|pcie
operator|=
name|pci_find_cap
argument_list|(
name|fd
argument_list|,
name|p
argument_list|,
name|PCIY_EXPRESS
argument_list|)
expr_stmt|;
if|if
condition|(
name|pcie
operator|==
literal|0
condition|)
return|return;
comment|/* Check for PCI-e errors. */
name|sta
operator|=
name|read_config
argument_list|(
name|fd
argument_list|,
operator|&
name|p
operator|->
name|pc_sel
argument_list|,
name|pcie
operator|+
name|PCIER_DEVICE_STA
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|print_bits
argument_list|(
literal|"PCI-e errors"
argument_list|,
name|pcie_device_status
argument_list|,
name|sta
operator|&
name|PCIE_ERRORS
argument_list|)
expr_stmt|;
comment|/* See if this device supports AER. */
name|aer
operator|=
name|pcie_find_cap
argument_list|(
name|fd
argument_list|,
name|p
argument_list|,
name|PCIZ_AER
argument_list|)
expr_stmt|;
if|if
condition|(
name|aer
operator|==
literal|0
condition|)
return|return;
comment|/* Check for uncorrected errors. */
name|mask
operator|=
name|read_config
argument_list|(
name|fd
argument_list|,
operator|&
name|p
operator|->
name|pc_sel
argument_list|,
name|aer
operator|+
name|PCIR_AER_UC_STATUS
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|severity
operator|=
name|read_config
argument_list|(
name|fd
argument_list|,
operator|&
name|p
operator|->
name|pc_sel
argument_list|,
name|aer
operator|+
name|PCIR_AER_UC_SEVERITY
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|print_bits
argument_list|(
literal|"Fatal"
argument_list|,
name|aer_uc
argument_list|,
name|mask
operator|&
name|severity
argument_list|)
expr_stmt|;
name|print_bits
argument_list|(
literal|"Non-fatal"
argument_list|,
name|aer_uc
argument_list|,
name|mask
operator|&
operator|~
name|severity
argument_list|)
expr_stmt|;
comment|/* Check for corrected errors. */
name|mask
operator|=
name|read_config
argument_list|(
name|fd
argument_list|,
operator|&
name|p
operator|->
name|pc_sel
argument_list|,
name|aer
operator|+
name|PCIR_AER_COR_STATUS
argument_list|,
literal|4
argument_list|)
expr_stmt|;
name|print_bits
argument_list|(
literal|"Corrected"
argument_list|,
name|aer_cor
argument_list|,
name|mask
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

