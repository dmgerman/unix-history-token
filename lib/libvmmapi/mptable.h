begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MPTABLE_h_
end_ifndef

begin_define
define|#
directive|define
name|_MPTABLE_h_
end_define

begin_define
define|#
directive|define
name|MP_SPECREV
value|(4)
end_define

begin_comment
comment|// MP spec revision 1.1
end_comment

begin_comment
comment|/*  * MP Floating Pointer Structure  */
end_comment

begin_define
define|#
directive|define
name|MPFP_SIGNATURE
value|"_MP_"
end_define

begin_define
define|#
directive|define
name|MPFP_SIGNATURE_LEN
value|(4)
end_define

begin_define
define|#
directive|define
name|MPFP_FEATURE2
value|(0x80)
end_define

begin_comment
comment|// IMCR is present
end_comment

begin_struct
struct|struct
name|mp_floating_pointer
block|{
name|uint8_t
name|signature
index|[
name|MPFP_SIGNATURE_LEN
index|]
decl_stmt|;
name|uint32_t
name|mptable_paddr
decl_stmt|;
name|uint8_t
name|length
decl_stmt|;
name|uint8_t
name|specrev
decl_stmt|;
name|uint8_t
name|checksum
decl_stmt|;
name|uint8_t
name|feature1
decl_stmt|;
name|uint8_t
name|feature2
decl_stmt|;
name|uint8_t
name|feature3
decl_stmt|;
name|uint8_t
name|feature4
decl_stmt|;
name|uint8_t
name|feature5
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MP Configuration Table Header  */
end_comment

begin_define
define|#
directive|define
name|MPCH_SIGNATURE
value|"PCMP"
end_define

begin_define
define|#
directive|define
name|MPCH_SIGNATURE_LEN
value|(4)
end_define

begin_define
define|#
directive|define
name|MPCH_OEMID
value|"NETAPP  "
end_define

begin_define
define|#
directive|define
name|MPCH_OEMID_LEN
value|(8)
end_define

begin_define
define|#
directive|define
name|MPCH_PRODID
value|"vFiler      "
end_define

begin_define
define|#
directive|define
name|MPCH_PRODID_LEN
value|(12)
end_define

begin_struct
struct|struct
name|mp_config_hdr
block|{
name|uint8_t
name|signature
index|[
name|MPCH_SIGNATURE_LEN
index|]
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
name|uint8_t
name|specrev
decl_stmt|;
name|uint8_t
name|checksum
decl_stmt|;
name|uint8_t
name|oemid
index|[
name|MPCH_OEMID_LEN
index|]
decl_stmt|;
name|uint8_t
name|prodid
index|[
name|MPCH_PRODID_LEN
index|]
decl_stmt|;
name|uint32_t
name|oem_ptr
decl_stmt|;
name|uint16_t
name|oem_sz
decl_stmt|;
name|uint16_t
name|nr_entries
decl_stmt|;
name|uint32_t
name|lapic_paddr
decl_stmt|;
name|uint16_t
name|ext_length
decl_stmt|;
name|uint8_t
name|ext_checksum
decl_stmt|;
name|uint8_t
name|reserved
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MP_ENTRY_PROC
value|(0)
end_define

begin_define
define|#
directive|define
name|MP_ENTRY_BUS
value|(1)
end_define

begin_define
define|#
directive|define
name|MP_ENTRY_IOAPIC
value|(2)
end_define

begin_define
define|#
directive|define
name|MP_ENTRY_IOINT
value|(3)
end_define

begin_define
define|#
directive|define
name|MP_ENTRY_LINT
value|(4)
end_define

begin_comment
comment|/*  * MP Processor Entry  */
end_comment

begin_define
define|#
directive|define
name|MPEP_FLAGS_EN
value|(0x1)
end_define

begin_define
define|#
directive|define
name|MPEP_FLAGS_BSP
value|(0x2)
end_define

begin_define
define|#
directive|define
name|MPEP_SIG_FAMILY
value|(6)
end_define

begin_define
define|#
directive|define
name|MPEP_SIG_MODEL
value|(26)
end_define

begin_define
define|#
directive|define
name|MPEP_SIG_STEPPING
value|(5)
end_define

begin_define
define|#
directive|define
name|MPEP_SIGNATURE
value|((MPEP_SIG_FAMILY<< 8) | (MPEP_SIG_MODEL<< 4)  \ 				| (MPEP_SIG_STEPPING))
end_define

begin_define
define|#
directive|define
name|MPEP_FEATURES
value|(0xBFEBFBFF)
end_define

begin_comment
comment|// Value from Intel i7 CPUID
end_comment

begin_struct
struct|struct
name|mpe_proc
block|{
name|uint8_t
name|entry_type
decl_stmt|;
name|uint8_t
name|lapic_id
decl_stmt|;
name|uint8_t
name|lapic_version
decl_stmt|;
name|uint8_t
name|proc_flags
decl_stmt|;
name|uint32_t
name|proc_signature
decl_stmt|;
name|uint32_t
name|feature_flags
decl_stmt|;
name|uint8_t
name|reserved
index|[
literal|8
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MP Bus Entry  */
end_comment

begin_define
define|#
directive|define
name|MPE_NUM_BUSES
value|(2)
end_define

begin_define
define|#
directive|define
name|MPE_BUSNAME_LEN
value|(6)
end_define

begin_define
define|#
directive|define
name|MPE_BUSID_ISA
value|(0)
end_define

begin_define
define|#
directive|define
name|MPE_BUSID_PCI
value|(1)
end_define

begin_define
define|#
directive|define
name|MPE_BUSNAME_ISA
value|"ISA   "
end_define

begin_define
define|#
directive|define
name|MPE_BUSNAME_PCI
value|"PCI   "
end_define

begin_struct
struct|struct
name|mpe_bus
block|{
name|uint8_t
name|entry_type
decl_stmt|;
name|uint8_t
name|busid
decl_stmt|;
name|uint8_t
name|busname
index|[
name|MPE_BUSNAME_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MP IO APIC Entry  */
end_comment

begin_define
define|#
directive|define
name|MPE_IOAPIC_ID
value|(2)
end_define

begin_define
define|#
directive|define
name|MPE_IOAPIC_FLAG_EN
value|(1)
end_define

begin_struct
struct|struct
name|mpe_ioapic
block|{
name|uint8_t
name|entry_type
decl_stmt|;
name|uint8_t
name|ioapic_id
decl_stmt|;
name|uint8_t
name|ioapic_version
decl_stmt|;
name|uint8_t
name|ioapic_flags
decl_stmt|;
name|uint32_t
name|ioapic_paddr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MP IO Interrupt Assignment Entry  */
end_comment

begin_define
define|#
directive|define
name|MPEII_INTR_INT
value|(0)
end_define

begin_define
define|#
directive|define
name|MPEII_INTR_NMI
value|(1)
end_define

begin_define
define|#
directive|define
name|MPEII_INTR_SMI
value|(2)
end_define

begin_define
define|#
directive|define
name|MPEII_INTR_EXTINT
value|(3)
end_define

begin_define
define|#
directive|define
name|MPEII_PCI_IRQ_MASK
value|(0x0c20U)
end_define

begin_comment
comment|/* IRQ 5,10,11 are PCI connected */
end_comment

begin_define
define|#
directive|define
name|MPEII_MAX_IRQ
value|(16)
end_define

begin_define
define|#
directive|define
name|MPEII_FLAGS_TRIGMODE_LEVEL
value|(0x3)
end_define

begin_struct
struct|struct
name|mpe_ioint
block|{
name|uint8_t
name|entry_type
decl_stmt|;
name|uint8_t
name|intr_type
decl_stmt|;
name|uint16_t
name|intr_flags
decl_stmt|;
name|uint8_t
name|src_bus_id
decl_stmt|;
name|uint8_t
name|src_bus_irq
decl_stmt|;
name|uint8_t
name|dst_apic_id
decl_stmt|;
name|uint8_t
name|dst_apic_intin
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * MP Local Interrupt Assignment Entry  */
end_comment

begin_struct
struct|struct
name|mpe_lint
block|{
name|uint8_t
name|entry_type
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|vm_build_mptable
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctxt
parameter_list|,
name|vm_paddr_t
name|gpa
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|ncpu
parameter_list|,
name|void
modifier|*
name|oemp
parameter_list|,
name|int
name|oemsz
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MPTABLE_h_ */
end_comment

end_unit

