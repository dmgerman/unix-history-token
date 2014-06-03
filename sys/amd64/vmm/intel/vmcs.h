begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMCS_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMCS_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|vmcs
block|{
name|uint32_t
name|identifier
decl_stmt|;
name|uint32_t
name|abort_code
decl_stmt|;
name|char
name|_impl_specific
index|[
name|PAGE_SIZE
operator|-
sizeof|sizeof
argument_list|(
name|uint32_t
argument_list|)
operator|*
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|vmcs
argument_list|)
operator|==
name|PAGE_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* MSR save region is composed of an array of 'struct msr_entry' */
end_comment

begin_struct
struct|struct
name|msr_entry
block|{
name|uint32_t
name|index
decl_stmt|;
name|uint32_t
name|reserved
decl_stmt|;
name|uint64_t
name|val
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|vmcs_set_msr_save
parameter_list|(
name|struct
name|vmcs
modifier|*
name|vmcs
parameter_list|,
name|u_long
name|g_area
parameter_list|,
name|u_int
name|g_count
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmcs_init
parameter_list|(
name|struct
name|vmcs
modifier|*
name|vmcs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmcs_getreg
parameter_list|(
name|struct
name|vmcs
modifier|*
name|vmcs
parameter_list|,
name|int
name|running
parameter_list|,
name|int
name|ident
parameter_list|,
name|uint64_t
modifier|*
name|rv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmcs_setreg
parameter_list|(
name|struct
name|vmcs
modifier|*
name|vmcs
parameter_list|,
name|int
name|running
parameter_list|,
name|int
name|ident
parameter_list|,
name|uint64_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmcs_getdesc
parameter_list|(
name|struct
name|vmcs
modifier|*
name|vmcs
parameter_list|,
name|int
name|running
parameter_list|,
name|int
name|ident
parameter_list|,
name|struct
name|seg_desc
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmcs_setdesc
parameter_list|(
name|struct
name|vmcs
modifier|*
name|vmcs
parameter_list|,
name|int
name|running
parameter_list|,
name|int
name|ident
parameter_list|,
name|struct
name|seg_desc
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|uint64_t
name|vmcs_read
parameter_list|(
name|uint32_t
name|encoding
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|uint64_t
name|val
decl_stmt|;
name|error
operator|=
name|vmread
argument_list|(
name|encoding
argument_list|,
operator|&
name|val
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|error
operator|==
literal|0
argument_list|,
operator|(
literal|"vmcs_read(%u) error %d"
operator|,
name|encoding
operator|,
name|error
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|val
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|vmcs_write
parameter_list|(
name|uint32_t
name|encoding
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|error
operator|=
name|vmwrite
argument_list|(
name|encoding
argument_list|,
name|val
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
name|error
operator|==
literal|0
argument_list|,
operator|(
literal|"vmcs_write(%u) error %d"
operator|,
name|encoding
operator|,
name|error
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|vmexit_instruction_length
parameter_list|()
value|vmcs_read(VMCS_EXIT_INSTRUCTION_LENGTH)
end_define

begin_define
define|#
directive|define
name|vmcs_guest_rip
parameter_list|()
value|vmcs_read(VMCS_GUEST_RIP)
end_define

begin_define
define|#
directive|define
name|vmcs_instruction_error
parameter_list|()
value|vmcs_read(VMCS_INSTRUCTION_ERROR)
end_define

begin_define
define|#
directive|define
name|vmcs_exit_reason
parameter_list|()
value|(vmcs_read(VMCS_EXIT_REASON)& 0xffff)
end_define

begin_define
define|#
directive|define
name|vmcs_exit_qualification
parameter_list|()
value|vmcs_read(VMCS_EXIT_QUALIFICATION)
end_define

begin_define
define|#
directive|define
name|vmcs_guest_cr3
parameter_list|()
value|vmcs_read(VMCS_GUEST_CR3)
end_define

begin_define
define|#
directive|define
name|vmcs_gpa
parameter_list|()
value|vmcs_read(VMCS_GUEST_PHYSICAL_ADDRESS)
end_define

begin_define
define|#
directive|define
name|vmcs_gla
parameter_list|()
value|vmcs_read(VMCS_GUEST_LINEAR_ADDRESS)
end_define

begin_define
define|#
directive|define
name|vmcs_idt_vectoring_info
parameter_list|()
value|vmcs_read(VMCS_IDT_VECTORING_INFO)
end_define

begin_define
define|#
directive|define
name|vmcs_idt_vectoring_err
parameter_list|()
value|vmcs_read(VMCS_IDT_VECTORING_ERROR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|VMCS_INITIAL
value|0xffffffffffffffff
end_define

begin_define
define|#
directive|define
name|VMCS_IDENT
parameter_list|(
name|encoding
parameter_list|)
value|((encoding) | 0x80000000)
end_define

begin_comment
comment|/*  * VMCS field encodings from Appendix H, Intel Architecture Manual Vol3B.  */
end_comment

begin_define
define|#
directive|define
name|VMCS_INVALID_ENCODING
value|0xffffffff
end_define

begin_comment
comment|/* 16-bit control fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_VPID
value|0x00000000
end_define

begin_define
define|#
directive|define
name|VMCS_PIR_VECTOR
value|0x00000002
end_define

begin_comment
comment|/* 16-bit guest-state fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_GUEST_ES_SELECTOR
value|0x00000800
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_CS_SELECTOR
value|0x00000802
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_SS_SELECTOR
value|0x00000804
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_DS_SELECTOR
value|0x00000806
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_FS_SELECTOR
value|0x00000808
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_GS_SELECTOR
value|0x0000080A
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_LDTR_SELECTOR
value|0x0000080C
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_TR_SELECTOR
value|0x0000080E
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_INTR_STATUS
value|0x00000810
end_define

begin_comment
comment|/* 16-bit host-state fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_HOST_ES_SELECTOR
value|0x00000C00
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_CS_SELECTOR
value|0x00000C02
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_SS_SELECTOR
value|0x00000C04
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_DS_SELECTOR
value|0x00000C06
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_FS_SELECTOR
value|0x00000C08
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_GS_SELECTOR
value|0x00000C0A
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_TR_SELECTOR
value|0x00000C0C
end_define

begin_comment
comment|/* 64-bit control fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_IO_BITMAP_A
value|0x00002000
end_define

begin_define
define|#
directive|define
name|VMCS_IO_BITMAP_B
value|0x00002002
end_define

begin_define
define|#
directive|define
name|VMCS_MSR_BITMAP
value|0x00002004
end_define

begin_define
define|#
directive|define
name|VMCS_EXIT_MSR_STORE
value|0x00002006
end_define

begin_define
define|#
directive|define
name|VMCS_EXIT_MSR_LOAD
value|0x00002008
end_define

begin_define
define|#
directive|define
name|VMCS_ENTRY_MSR_LOAD
value|0x0000200A
end_define

begin_define
define|#
directive|define
name|VMCS_EXECUTIVE_VMCS
value|0x0000200C
end_define

begin_define
define|#
directive|define
name|VMCS_TSC_OFFSET
value|0x00002010
end_define

begin_define
define|#
directive|define
name|VMCS_VIRTUAL_APIC
value|0x00002012
end_define

begin_define
define|#
directive|define
name|VMCS_APIC_ACCESS
value|0x00002014
end_define

begin_define
define|#
directive|define
name|VMCS_PIR_DESC
value|0x00002016
end_define

begin_define
define|#
directive|define
name|VMCS_EPTP
value|0x0000201A
end_define

begin_define
define|#
directive|define
name|VMCS_EOI_EXIT0
value|0x0000201C
end_define

begin_define
define|#
directive|define
name|VMCS_EOI_EXIT1
value|0x0000201E
end_define

begin_define
define|#
directive|define
name|VMCS_EOI_EXIT2
value|0x00002020
end_define

begin_define
define|#
directive|define
name|VMCS_EOI_EXIT3
value|0x00002022
end_define

begin_define
define|#
directive|define
name|VMCS_EOI_EXIT
parameter_list|(
name|vector
parameter_list|)
value|(VMCS_EOI_EXIT0 + ((vector) / 64) * 2)
end_define

begin_comment
comment|/* 64-bit read-only fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_GUEST_PHYSICAL_ADDRESS
value|0x00002400
end_define

begin_comment
comment|/* 64-bit guest-state fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_LINK_POINTER
value|0x00002800
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_IA32_DEBUGCTL
value|0x00002802
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_IA32_PAT
value|0x00002804
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_IA32_EFER
value|0x00002806
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_IA32_PERF_GLOBAL_CTRL
value|0x00002808
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_PDPTE0
value|0x0000280A
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_PDPTE1
value|0x0000280C
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_PDPTE2
value|0x0000280E
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_PDPTE3
value|0x00002810
end_define

begin_comment
comment|/* 64-bit host-state fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_HOST_IA32_PAT
value|0x00002C00
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_IA32_EFER
value|0x00002C02
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_IA32_PERF_GLOBAL_CTRL
value|0x00002C04
end_define

begin_comment
comment|/* 32-bit control fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_PIN_BASED_CTLS
value|0x00004000
end_define

begin_define
define|#
directive|define
name|VMCS_PRI_PROC_BASED_CTLS
value|0x00004002
end_define

begin_define
define|#
directive|define
name|VMCS_EXCEPTION_BITMAP
value|0x00004004
end_define

begin_define
define|#
directive|define
name|VMCS_PF_ERROR_MASK
value|0x00004006
end_define

begin_define
define|#
directive|define
name|VMCS_PF_ERROR_MATCH
value|0x00004008
end_define

begin_define
define|#
directive|define
name|VMCS_CR3_TARGET_COUNT
value|0x0000400A
end_define

begin_define
define|#
directive|define
name|VMCS_EXIT_CTLS
value|0x0000400C
end_define

begin_define
define|#
directive|define
name|VMCS_EXIT_MSR_STORE_COUNT
value|0x0000400E
end_define

begin_define
define|#
directive|define
name|VMCS_EXIT_MSR_LOAD_COUNT
value|0x00004010
end_define

begin_define
define|#
directive|define
name|VMCS_ENTRY_CTLS
value|0x00004012
end_define

begin_define
define|#
directive|define
name|VMCS_ENTRY_MSR_LOAD_COUNT
value|0x00004014
end_define

begin_define
define|#
directive|define
name|VMCS_ENTRY_INTR_INFO
value|0x00004016
end_define

begin_define
define|#
directive|define
name|VMCS_ENTRY_EXCEPTION_ERROR
value|0x00004018
end_define

begin_define
define|#
directive|define
name|VMCS_ENTRY_INST_LENGTH
value|0x0000401A
end_define

begin_define
define|#
directive|define
name|VMCS_TPR_THRESHOLD
value|0x0000401C
end_define

begin_define
define|#
directive|define
name|VMCS_SEC_PROC_BASED_CTLS
value|0x0000401E
end_define

begin_define
define|#
directive|define
name|VMCS_PLE_GAP
value|0x00004020
end_define

begin_define
define|#
directive|define
name|VMCS_PLE_WINDOW
value|0x00004022
end_define

begin_comment
comment|/* 32-bit read-only data fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_INSTRUCTION_ERROR
value|0x00004400
end_define

begin_define
define|#
directive|define
name|VMCS_EXIT_REASON
value|0x00004402
end_define

begin_define
define|#
directive|define
name|VMCS_EXIT_INTR_INFO
value|0x00004404
end_define

begin_define
define|#
directive|define
name|VMCS_EXIT_INTR_ERRCODE
value|0x00004406
end_define

begin_define
define|#
directive|define
name|VMCS_IDT_VECTORING_INFO
value|0x00004408
end_define

begin_define
define|#
directive|define
name|VMCS_IDT_VECTORING_ERROR
value|0x0000440A
end_define

begin_define
define|#
directive|define
name|VMCS_EXIT_INSTRUCTION_LENGTH
value|0x0000440C
end_define

begin_define
define|#
directive|define
name|VMCS_EXIT_INSTRUCTION_INFO
value|0x0000440E
end_define

begin_comment
comment|/* 32-bit guest-state fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_GUEST_ES_LIMIT
value|0x00004800
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_CS_LIMIT
value|0x00004802
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_SS_LIMIT
value|0x00004804
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_DS_LIMIT
value|0x00004806
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_FS_LIMIT
value|0x00004808
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_GS_LIMIT
value|0x0000480A
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_LDTR_LIMIT
value|0x0000480C
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_TR_LIMIT
value|0x0000480E
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_GDTR_LIMIT
value|0x00004810
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_IDTR_LIMIT
value|0x00004812
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_ES_ACCESS_RIGHTS
value|0x00004814
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_CS_ACCESS_RIGHTS
value|0x00004816
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_SS_ACCESS_RIGHTS
value|0x00004818
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_DS_ACCESS_RIGHTS
value|0x0000481A
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_FS_ACCESS_RIGHTS
value|0x0000481C
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_GS_ACCESS_RIGHTS
value|0x0000481E
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_LDTR_ACCESS_RIGHTS
value|0x00004820
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_TR_ACCESS_RIGHTS
value|0x00004822
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_INTERRUPTIBILITY
value|0x00004824
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_ACTIVITY
value|0x00004826
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_SMBASE
value|0x00004828
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_IA32_SYSENTER_CS
value|0x0000482A
end_define

begin_define
define|#
directive|define
name|VMCS_PREEMPTION_TIMER_VALUE
value|0x0000482E
end_define

begin_comment
comment|/* 32-bit host state fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_HOST_IA32_SYSENTER_CS
value|0x00004C00
end_define

begin_comment
comment|/* Natural Width control fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_CR0_MASK
value|0x00006000
end_define

begin_define
define|#
directive|define
name|VMCS_CR4_MASK
value|0x00006002
end_define

begin_define
define|#
directive|define
name|VMCS_CR0_SHADOW
value|0x00006004
end_define

begin_define
define|#
directive|define
name|VMCS_CR4_SHADOW
value|0x00006006
end_define

begin_define
define|#
directive|define
name|VMCS_CR3_TARGET0
value|0x00006008
end_define

begin_define
define|#
directive|define
name|VMCS_CR3_TARGET1
value|0x0000600A
end_define

begin_define
define|#
directive|define
name|VMCS_CR3_TARGET2
value|0x0000600C
end_define

begin_define
define|#
directive|define
name|VMCS_CR3_TARGET3
value|0x0000600E
end_define

begin_comment
comment|/* Natural Width read-only fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_EXIT_QUALIFICATION
value|0x00006400
end_define

begin_define
define|#
directive|define
name|VMCS_IO_RCX
value|0x00006402
end_define

begin_define
define|#
directive|define
name|VMCS_IO_RSI
value|0x00006404
end_define

begin_define
define|#
directive|define
name|VMCS_IO_RDI
value|0x00006406
end_define

begin_define
define|#
directive|define
name|VMCS_IO_RIP
value|0x00006408
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_LINEAR_ADDRESS
value|0x0000640A
end_define

begin_comment
comment|/* Natural Width guest-state fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_GUEST_CR0
value|0x00006800
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_CR3
value|0x00006802
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_CR4
value|0x00006804
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_ES_BASE
value|0x00006806
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_CS_BASE
value|0x00006808
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_SS_BASE
value|0x0000680A
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_DS_BASE
value|0x0000680C
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_FS_BASE
value|0x0000680E
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_GS_BASE
value|0x00006810
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_LDTR_BASE
value|0x00006812
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_TR_BASE
value|0x00006814
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_GDTR_BASE
value|0x00006816
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_IDTR_BASE
value|0x00006818
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_DR7
value|0x0000681A
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_RSP
value|0x0000681C
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_RIP
value|0x0000681E
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_RFLAGS
value|0x00006820
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_PENDING_DBG_EXCEPTIONS
value|0x00006822
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_IA32_SYSENTER_ESP
value|0x00006824
end_define

begin_define
define|#
directive|define
name|VMCS_GUEST_IA32_SYSENTER_EIP
value|0x00006826
end_define

begin_comment
comment|/* Natural Width host-state fields */
end_comment

begin_define
define|#
directive|define
name|VMCS_HOST_CR0
value|0x00006C00
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_CR3
value|0x00006C02
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_CR4
value|0x00006C04
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_FS_BASE
value|0x00006C06
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_GS_BASE
value|0x00006C08
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_TR_BASE
value|0x00006C0A
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_GDTR_BASE
value|0x00006C0C
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_IDTR_BASE
value|0x00006C0E
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_IA32_SYSENTER_ESP
value|0x00006C10
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_IA32_SYSENTER_EIP
value|0x00006C12
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_RSP
value|0x00006C14
end_define

begin_define
define|#
directive|define
name|VMCS_HOST_RIP
value|0x00006c16
end_define

begin_comment
comment|/*  * VM instruction error numbers  */
end_comment

begin_define
define|#
directive|define
name|VMRESUME_WITH_NON_LAUNCHED_VMCS
value|5
end_define

begin_comment
comment|/*  * VMCS exit reasons  */
end_comment

begin_define
define|#
directive|define
name|EXIT_REASON_EXCEPTION
value|0
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_EXT_INTR
value|1
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_TRIPLE_FAULT
value|2
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_INIT
value|3
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_SIPI
value|4
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_IO_SMI
value|5
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_SMI
value|6
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_INTR_WINDOW
value|7
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_NMI_WINDOW
value|8
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_TASK_SWITCH
value|9
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_CPUID
value|10
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_GETSEC
value|11
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_HLT
value|12
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_INVD
value|13
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_INVLPG
value|14
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_RDPMC
value|15
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_RDTSC
value|16
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_RSM
value|17
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VMCALL
value|18
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VMCLEAR
value|19
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VMLAUNCH
value|20
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VMPTRLD
value|21
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VMPTRST
value|22
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VMREAD
value|23
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VMRESUME
value|24
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VMWRITE
value|25
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VMXOFF
value|26
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VMXON
value|27
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_CR_ACCESS
value|28
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_DR_ACCESS
value|29
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_INOUT
value|30
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_RDMSR
value|31
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_WRMSR
value|32
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_INVAL_VMCS
value|33
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_INVAL_MSR
value|34
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_MWAIT
value|36
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_MTF
value|37
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_MONITOR
value|39
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_PAUSE
value|40
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_MCE
value|41
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_TPR
value|43
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_APIC_ACCESS
value|44
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VIRTUALIZED_EOI
value|45
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_GDTR_IDTR
value|46
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_LDTR_TR
value|47
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_EPT_FAULT
value|48
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_EPT_MISCONFIG
value|49
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_INVEPT
value|50
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_RDTSCP
value|51
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_VMX_PREEMPT
value|52
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_INVVPID
value|53
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_WBINVD
value|54
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_XSETBV
value|55
end_define

begin_define
define|#
directive|define
name|EXIT_REASON_APIC_WRITE
value|56
end_define

begin_comment
comment|/*  * NMI unblocking due to IRET.  *  * Applies to VM-exits due to hardware exception or EPT fault.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_QUAL_NMIUDTI
value|(1<< 12)
end_define

begin_comment
comment|/*  * VMCS interrupt information fields  */
end_comment

begin_define
define|#
directive|define
name|VMCS_INTR_VALID
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|VMCS_INTR_T_MASK
value|0x700
end_define

begin_comment
comment|/* Interruption-info type */
end_comment

begin_define
define|#
directive|define
name|VMCS_INTR_T_HWINTR
value|(0<< 8)
end_define

begin_define
define|#
directive|define
name|VMCS_INTR_T_NMI
value|(2<< 8)
end_define

begin_define
define|#
directive|define
name|VMCS_INTR_T_HWEXCEPTION
value|(3<< 8)
end_define

begin_define
define|#
directive|define
name|VMCS_INTR_DEL_ERRCODE
value|(1<< 11)
end_define

begin_comment
comment|/*  * VMCS IDT-Vectoring information fields  */
end_comment

begin_define
define|#
directive|define
name|VMCS_IDT_VEC_VALID
value|(1U<< 31)
end_define

begin_define
define|#
directive|define
name|VMCS_IDT_VEC_ERRCODE_VALID
value|(1<< 11)
end_define

begin_comment
comment|/*  * VMCS Guest interruptibility field  */
end_comment

begin_define
define|#
directive|define
name|VMCS_INTERRUPTIBILITY_STI_BLOCKING
value|(1<< 0)
end_define

begin_define
define|#
directive|define
name|VMCS_INTERRUPTIBILITY_MOVSS_BLOCKING
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|VMCS_INTERRUPTIBILITY_SMI_BLOCKING
value|(1<< 2)
end_define

begin_define
define|#
directive|define
name|VMCS_INTERRUPTIBILITY_NMI_BLOCKING
value|(1<< 3)
end_define

begin_comment
comment|/*  * Exit qualification for EXIT_REASON_INVAL_VMCS  */
end_comment

begin_define
define|#
directive|define
name|EXIT_QUAL_NMI_WHILE_STI_BLOCKING
value|3
end_define

begin_comment
comment|/*  * Exit qualification for EPT violation  */
end_comment

begin_define
define|#
directive|define
name|EPT_VIOLATION_DATA_READ
value|(1UL<< 0)
end_define

begin_define
define|#
directive|define
name|EPT_VIOLATION_DATA_WRITE
value|(1UL<< 1)
end_define

begin_define
define|#
directive|define
name|EPT_VIOLATION_INST_FETCH
value|(1UL<< 2)
end_define

begin_define
define|#
directive|define
name|EPT_VIOLATION_GPA_READABLE
value|(1UL<< 3)
end_define

begin_define
define|#
directive|define
name|EPT_VIOLATION_GPA_WRITEABLE
value|(1UL<< 4)
end_define

begin_define
define|#
directive|define
name|EPT_VIOLATION_GPA_EXECUTABLE
value|(1UL<< 5)
end_define

begin_define
define|#
directive|define
name|EPT_VIOLATION_GLA_VALID
value|(1UL<< 7)
end_define

begin_define
define|#
directive|define
name|EPT_VIOLATION_XLAT_VALID
value|(1UL<< 8)
end_define

begin_comment
comment|/*  * Exit qualification for APIC-access VM exit  */
end_comment

begin_define
define|#
directive|define
name|APIC_ACCESS_OFFSET
parameter_list|(
name|qual
parameter_list|)
value|((qual)& 0xFFF)
end_define

begin_define
define|#
directive|define
name|APIC_ACCESS_TYPE
parameter_list|(
name|qual
parameter_list|)
value|(((qual)>> 12)& 0xF)
end_define

begin_comment
comment|/*  * Exit qualification for APIC-write VM exit  */
end_comment

begin_define
define|#
directive|define
name|APIC_WRITE_OFFSET
parameter_list|(
name|qual
parameter_list|)
value|((qual)& 0xFFF)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

