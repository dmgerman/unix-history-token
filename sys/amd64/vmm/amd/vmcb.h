begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Anish Gupta (akgupt3@gmail.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMCB_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMCB_H_
end_define

begin_comment
comment|/*  * Secure Virtual Machine: AMD64 Programmer's Manual Vol2, Chapter 15  * Layout of VMCB: AMD64 Programmer's Manual Vol2, Appendix B  */
end_comment

begin_comment
comment|/* VMCB Control offset 0xC */
end_comment

begin_define
define|#
directive|define
name|VMCB_INTCPT_INTR
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_NMI
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_SMI
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_INIT
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_VINTR
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_CR0_WRITE
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_IDTR_READ
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_GDTR_READ
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_LDTR_READ
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_TR_READ
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_IDTR_WRITE
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_GDTR_WRITE
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_LDTR_WRITE
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_TR_WRITE
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_RDTSC
value|BIT(14)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_RDPMC
value|BIT(15)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_PUSHF
value|BIT(16)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_POPF
value|BIT(17)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_CPUID
value|BIT(18)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_RSM
value|BIT(19)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_IRET
value|BIT(20)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_INTn
value|BIT(21)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_INVD
value|BIT(22)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_PAUSE
value|BIT(23)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_HLT
value|BIT(24)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_INVPG
value|BIT(25)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_INVPGA
value|BIT(26)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_IO
value|BIT(27)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_MSR
value|BIT(28)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_TASK_SWITCH
value|BIT(29)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_FERR_FREEZE
value|BIT(30)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_SHUTDOWN
value|BIT(31)
end_define

begin_comment
comment|/* VMCB Control offset 0x10 */
end_comment

begin_define
define|#
directive|define
name|VMCB_INTCPT_VMRUN
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_VMMCALL
value|BIT(1)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_VMLOAD
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_VMSAVE
value|BIT(3)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_STGI
value|BIT(4)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_CLGI
value|BIT(5)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_SKINIT
value|BIT(6)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_RDTSCP
value|BIT(7)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_ICEBP
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_WBINVD
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_MONITOR
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_MWAIT
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_MWAIT_ARMED
value|BIT(12)
end_define

begin_define
define|#
directive|define
name|VMCB_INTCPT_XSETBV
value|BIT(13)
end_define

begin_comment
comment|/* VMCB TLB control */
end_comment

begin_define
define|#
directive|define
name|VMCB_TLB_FLUSH_NOTHING
value|0
end_define

begin_comment
comment|/* Flush nothing */
end_comment

begin_define
define|#
directive|define
name|VMCB_TLB_FLUSH_ALL
value|1
end_define

begin_comment
comment|/* Flush entire TLB */
end_comment

begin_define
define|#
directive|define
name|VMCB_TLB_FLUSH_GUEST
value|3
end_define

begin_comment
comment|/* Flush all guest entries */
end_comment

begin_define
define|#
directive|define
name|VMCB_TLB_FLUSH_GUEST_NONGLOBAL
value|7
end_define

begin_comment
comment|/* Flush guest non-PG entries */
end_comment

begin_comment
comment|/* VMCB state caching */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_NONE
value|0
end_define

begin_comment
comment|/* No caching */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_I
value|BIT(0)
end_define

begin_comment
comment|/* Cache vectors, TSC offset */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_IOPM
value|BIT(1)
end_define

begin_comment
comment|/* I/O and MSR permission */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_ASID
value|BIT(2)
end_define

begin_comment
comment|/* ASID */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_TPR
value|BIT(3)
end_define

begin_comment
comment|/* V_TPR to V_INTR_VECTOR */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_NP
value|BIT(4)
end_define

begin_comment
comment|/* Nested Paging */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_CR
value|BIT(5)
end_define

begin_comment
comment|/* CR0, CR3, CR4& EFER */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_DR
value|BIT(6)
end_define

begin_comment
comment|/* Debug registers */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_DT
value|BIT(7)
end_define

begin_comment
comment|/* GDT/IDT */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_SEG
value|BIT(8)
end_define

begin_comment
comment|/* User segments, CPL */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_CR2
value|BIT(9)
end_define

begin_comment
comment|/* page fault address */
end_comment

begin_define
define|#
directive|define
name|VMCB_CACHE_LBR
value|BIT(10)
end_define

begin_comment
comment|/* Last branch */
end_comment

begin_comment
comment|/* VMCB control event injection */
end_comment

begin_define
define|#
directive|define
name|VMCB_EVENTINJ_EC_VALID
value|BIT(11)
end_define

begin_comment
comment|/* Error Code valid */
end_comment

begin_define
define|#
directive|define
name|VMCB_EVENTINJ_VALID
value|BIT(31)
end_define

begin_comment
comment|/* Event valid */
end_comment

begin_comment
comment|/* Event types that can be injected */
end_comment

begin_define
define|#
directive|define
name|VMCB_EVENTINJ_TYPE_INTR
value|0
end_define

begin_define
define|#
directive|define
name|VMCB_EVENTINJ_TYPE_NMI
value|2
end_define

begin_define
define|#
directive|define
name|VMCB_EVENTINJ_TYPE_EXCEPTION
value|3
end_define

begin_define
define|#
directive|define
name|VMCB_EVENTINJ_TYPE_INTn
value|4
end_define

begin_comment
comment|/* VMCB exit code, APM vol2 Appendix C */
end_comment

begin_define
define|#
directive|define
name|VMCB_EXIT_MC
value|0x52
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_INTR
value|0x60
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_VINTR
value|0x64
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_PUSHF
value|0x70
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_POPF
value|0x71
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_CPUID
value|0x72
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_IRET
value|0x74
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_PAUSE
value|0x77
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_HLT
value|0x78
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_IO
value|0x7B
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_MSR
value|0x7C
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_SHUTDOWN
value|0x7F
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_VMSAVE
value|0x83
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_NPF
value|0x400
end_define

begin_define
define|#
directive|define
name|VMCB_EXIT_INVALID
value|-1
end_define

begin_comment
comment|/*  * Nested page fault.  * Bit definitions to decode EXITINFO1.  */
end_comment

begin_define
define|#
directive|define
name|VMCB_NPF_INFO1_P
value|BIT(0)
end_define

begin_comment
comment|/* Nested page present. */
end_comment

begin_define
define|#
directive|define
name|VMCB_NPF_INFO1_W
value|BIT(1)
end_define

begin_comment
comment|/* Access was write. */
end_comment

begin_define
define|#
directive|define
name|VMCB_NPF_INFO1_U
value|BIT(2)
end_define

begin_comment
comment|/* Access was user access. */
end_comment

begin_define
define|#
directive|define
name|VMCB_NPF_INFO1_RSV
value|BIT(3)
end_define

begin_comment
comment|/* Reserved bits present. */
end_comment

begin_define
define|#
directive|define
name|VMCB_NPF_INFO1_ID
value|BIT(4)
end_define

begin_comment
comment|/* Code read. */
end_comment

begin_define
define|#
directive|define
name|VMCB_NPF_INFO1_GPA
value|BIT(32)
end_define

begin_comment
comment|/* Guest physical address. */
end_comment

begin_define
define|#
directive|define
name|VMCB_NPF_INFO1_GPT
value|BIT(33)
end_define

begin_comment
comment|/* Guest page table. */
end_comment

begin_comment
comment|/*  * EXITINTINFO, Interrupt exit info for all intrecepts.  * Section 15.7.2, Intercepts during IDT Interrupt Delivery.  */
end_comment

begin_define
define|#
directive|define
name|VMCB_EXITINTINFO_VECTOR
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_define
define|#
directive|define
name|VMCB_EXITINTINFO_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 8)& 0x7)
end_define

begin_define
define|#
directive|define
name|VMCB_EXITINTINFO_EC_VALID
parameter_list|(
name|x
parameter_list|)
value|(((x)& BIT(11)) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|VMCB_EXITINTINFO_VALID
parameter_list|(
name|x
parameter_list|)
value|(((x)& BIT(31)) ? 1 : 0)
end_define

begin_define
define|#
directive|define
name|VMCB_EXITINTINFO_EC
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 32)& 0xFFFFFFFF)
end_define

begin_comment
comment|/* VMCB save state area segment format */
end_comment

begin_struct
struct|struct
name|vmcb_segment
block|{
name|uint16_t
name|selector
decl_stmt|;
name|uint16_t
name|attrib
decl_stmt|;
name|uint32_t
name|limit
decl_stmt|;
name|uint64_t
name|base
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|vmcb_segment
argument_list|)
operator|==
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Code segment descriptor attribute in 12 bit format as saved by VMCB. */
end_comment

begin_define
define|#
directive|define
name|VMCB_CS_ATTRIB_L
value|BIT(9)
end_define

begin_comment
comment|/* Long mode. */
end_comment

begin_define
define|#
directive|define
name|VMCB_CS_ATTRIB_D
value|BIT(10)
end_define

begin_comment
comment|/* OPerand size bit. */
end_comment

begin_comment
comment|/*  * The VMCB is divided into two areas - the first one contains various  * control bits including the intercept vector and the second one contains  * the guest state.  */
end_comment

begin_comment
comment|/* VMCB control area - padded up to 1024 bytes */
end_comment

begin_struct
struct|struct
name|vmcb_ctrl
block|{
name|uint16_t
name|cr_read
decl_stmt|;
comment|/* Offset 0, CR0-15 read/write */
name|uint16_t
name|cr_write
decl_stmt|;
name|uint16_t
name|dr_read
decl_stmt|;
comment|/* Offset 4, DR0-DR15 */
name|uint16_t
name|dr_write
decl_stmt|;
name|uint32_t
name|exception
decl_stmt|;
comment|/* Offset 8, bit mask for exceptions. */
name|uint32_t
name|ctrl1
decl_stmt|;
comment|/* Offset 0xC, intercept events1 */
name|uint32_t
name|ctrl2
decl_stmt|;
comment|/* Offset 0x10, intercept event2 */
name|uint8_t
name|pad1
index|[
literal|0x28
index|]
decl_stmt|;
comment|/* Offsets 0x14-0x3B are reserved. */
name|uint16_t
name|pause_filthresh
decl_stmt|;
comment|/* Offset 0x3C, PAUSE filter threshold */
name|uint16_t
name|pause_filcnt
decl_stmt|;
comment|/* Offset 0x3E, PAUSE filter count */
name|uint64_t
name|iopm_base_pa
decl_stmt|;
comment|/* 0x40: IOPM_BASE_PA */
name|uint64_t
name|msrpm_base_pa
decl_stmt|;
comment|/* 0x48: MSRPM_BASE_PA */
name|uint64_t
name|tsc_offset
decl_stmt|;
comment|/* 0x50: TSC_OFFSET */
name|uint32_t
name|asid
decl_stmt|;
comment|/* 0x58: Guest ASID */
name|uint8_t
name|tlb_ctrl
decl_stmt|;
comment|/* 0x5C: TLB_CONTROL */
name|uint8_t
name|pad2
index|[
literal|3
index|]
decl_stmt|;
comment|/* 0x5D-0x5F: Reserved. */
name|uint8_t
name|v_tpr
decl_stmt|;
comment|/* 0x60: V_TPR, guest CR8 */
name|uint8_t
name|v_irq
range|:
literal|1
decl_stmt|;
comment|/* Is virtual interrupt pending? */
name|uint8_t
label|:
literal|7
expr_stmt|;
comment|/* Padding */
name|uint8_t
name|v_intr_prio
range|:
literal|4
decl_stmt|;
comment|/* 0x62: Priority for virtual interrupt. */
name|uint8_t
name|v_ign_tpr
range|:
literal|1
decl_stmt|;
name|uint8_t
label|:
literal|3
expr_stmt|;
name|uint8_t
name|v_intr_masking
range|:
literal|1
decl_stmt|;
comment|/* Guest and host sharing of RFLAGS. */
name|uint8_t
label|:
literal|7
expr_stmt|;
name|uint8_t
name|v_intr_vector
decl_stmt|;
comment|/* 0x65: Vector for virtual interrupt. */
name|uint8_t
name|pad3
index|[
literal|3
index|]
decl_stmt|;
comment|/* Bit64-40 Reserved. */
name|uint64_t
name|intr_shadow
range|:
literal|1
decl_stmt|;
comment|/* 0x68: Interrupt shadow, section15.2.1 APM2 */
name|uint64_t
label|:
literal|63
expr_stmt|;
name|uint64_t
name|exitcode
decl_stmt|;
comment|/* 0x70, Exitcode */
name|uint64_t
name|exitinfo1
decl_stmt|;
comment|/* 0x78, EXITINFO1 */
name|uint64_t
name|exitinfo2
decl_stmt|;
comment|/* 0x80, EXITINFO2 */
name|uint64_t
name|exitintinfo
decl_stmt|;
comment|/* 0x88, Interrupt exit value. */
name|uint64_t
name|np_enable
range|:
literal|1
decl_stmt|;
comment|/* 0x90, Nested paging enable. */
name|uint64_t
label|:
literal|63
expr_stmt|;
name|uint8_t
name|pad4
index|[
literal|0x10
index|]
decl_stmt|;
comment|/* 0x98-0xA7 reserved. */
name|uint64_t
name|eventinj
decl_stmt|;
comment|/* 0xA8, Event injection. */
name|uint64_t
name|n_cr3
decl_stmt|;
comment|/* B0, Nested page table. */
name|uint64_t
name|lbr_virt_en
range|:
literal|1
decl_stmt|;
comment|/* Enable LBR virtualization. */
name|uint64_t
label|:
literal|63
expr_stmt|;
name|uint32_t
name|vmcb_clean
decl_stmt|;
comment|/* 0xC0: VMCB clean bits for caching */
name|uint32_t
label|:
literal|32
expr_stmt|;
comment|/* 0xC4: Reserved */
name|uint64_t
name|nrip
decl_stmt|;
comment|/* 0xC8: Guest next nRIP. */
name|uint8_t
name|inst_decode_size
decl_stmt|;
comment|/* 0xD0: Instruction decode */
name|uint8_t
name|inst_decode_bytes
index|[
literal|15
index|]
decl_stmt|;
name|uint8_t
name|padd6
index|[
literal|0x320
index|]
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|vmcb_ctrl
argument_list|)
operator|==
literal|1024
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|vmcb_state
block|{
name|struct
name|vmcb_segment
name|es
decl_stmt|;
name|struct
name|vmcb_segment
name|cs
decl_stmt|;
name|struct
name|vmcb_segment
name|ss
decl_stmt|;
name|struct
name|vmcb_segment
name|ds
decl_stmt|;
name|struct
name|vmcb_segment
name|fs
decl_stmt|;
name|struct
name|vmcb_segment
name|gs
decl_stmt|;
name|struct
name|vmcb_segment
name|gdt
decl_stmt|;
name|struct
name|vmcb_segment
name|ldt
decl_stmt|;
name|struct
name|vmcb_segment
name|idt
decl_stmt|;
name|struct
name|vmcb_segment
name|tr
decl_stmt|;
name|uint8_t
name|pad1
index|[
literal|0x2b
index|]
decl_stmt|;
comment|/* Reserved: 0xA0-0xCA */
name|uint8_t
name|cpl
decl_stmt|;
name|uint8_t
name|pad2
index|[
literal|4
index|]
decl_stmt|;
name|uint64_t
name|efer
decl_stmt|;
name|uint8_t
name|pad3
index|[
literal|0x70
index|]
decl_stmt|;
comment|/* Reserved: 0xd8-0x147 */
name|uint64_t
name|cr4
decl_stmt|;
name|uint64_t
name|cr3
decl_stmt|;
comment|/* Guest CR3 */
name|uint64_t
name|cr0
decl_stmt|;
name|uint64_t
name|dr7
decl_stmt|;
name|uint64_t
name|dr6
decl_stmt|;
name|uint64_t
name|rflags
decl_stmt|;
name|uint64_t
name|rip
decl_stmt|;
name|uint8_t
name|pad4
index|[
literal|0x58
index|]
decl_stmt|;
comment|/* Reserved: 0x180-0x1D7 */
name|uint64_t
name|rsp
decl_stmt|;
name|uint8_t
name|pad5
index|[
literal|0x18
index|]
decl_stmt|;
comment|/* Reserved 0x1E0-0x1F7 */
name|uint64_t
name|rax
decl_stmt|;
name|uint64_t
name|star
decl_stmt|;
name|uint64_t
name|lstar
decl_stmt|;
name|uint64_t
name|cstar
decl_stmt|;
name|uint64_t
name|sfmask
decl_stmt|;
name|uint64_t
name|kernelgsbase
decl_stmt|;
name|uint64_t
name|sysenter_cs
decl_stmt|;
name|uint64_t
name|sysenter_esp
decl_stmt|;
name|uint64_t
name|sysenter_eip
decl_stmt|;
name|uint64_t
name|cr2
decl_stmt|;
name|uint8_t
name|pad6
index|[
literal|0x20
index|]
decl_stmt|;
name|uint64_t
name|g_pat
decl_stmt|;
name|uint64_t
name|dbgctl
decl_stmt|;
name|uint64_t
name|br_from
decl_stmt|;
name|uint64_t
name|br_to
decl_stmt|;
name|uint64_t
name|int_from
decl_stmt|;
name|uint64_t
name|int_to
decl_stmt|;
name|uint8_t
name|pad7
index|[
literal|0x968
index|]
decl_stmt|;
comment|/* Reserved upto end of VMCB */
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|vmcb_state
argument_list|)
operator|==
literal|0xC00
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|vmcb
block|{
name|struct
name|vmcb_ctrl
name|ctrl
decl_stmt|;
name|struct
name|vmcb_state
name|state
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|__packed__
operator|)
argument_list|)
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|vmcb
argument_list|)
operator|==
name|PAGE_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|vmcb
argument_list|,
name|state
argument_list|)
operator|==
literal|0x400
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|svm_init_vmcb
parameter_list|(
name|struct
name|vmcb
modifier|*
name|vmcb
parameter_list|,
name|uint64_t
name|iopm_base_pa
parameter_list|,
name|uint64_t
name|msrpm_base_pa
parameter_list|,
name|uint64_t
name|np_pml4
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmcb_read
parameter_list|(
name|struct
name|vmcb
modifier|*
name|vmcb
parameter_list|,
name|int
name|ident
parameter_list|,
name|uint64_t
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmcb_write
parameter_list|(
name|struct
name|vmcb
modifier|*
name|vmcb
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
name|struct
name|vmcb_segment
modifier|*
name|vmcb_seg
parameter_list|(
name|struct
name|vmcb
modifier|*
name|vmcb
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VMCB_H_ */
end_comment

end_unit

