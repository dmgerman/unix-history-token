begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Anish Gupta (anish@freebsd.org)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_AMDVI_PRIV_H_
end_ifndef

begin_define
define|#
directive|define
name|_AMDVI_PRIV_H_
end_define

begin_define
define|#
directive|define
name|BIT
parameter_list|(
name|n
parameter_list|)
value|(1ULL<< (n))
end_define

begin_comment
comment|/* Return value of bits[n:m] where n and (n>= ) m are bit positions. */
end_comment

begin_define
define|#
directive|define
name|REG_BITS
parameter_list|(
name|x
parameter_list|,
name|n
parameter_list|,
name|m
parameter_list|)
value|(((x)>> (m))& 		\ 				((1<< (((n) - (m)) + 1)) - 1))
end_define

begin_comment
comment|/*  * IOMMU PCI capability.  */
end_comment

begin_define
define|#
directive|define
name|AMDVI_PCI_CAP_IOTLB
value|BIT(0)
end_define

begin_comment
comment|/* IOTLB is supported. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_PCI_CAP_HT
value|BIT(1)
end_define

begin_comment
comment|/* HyperTransport tunnel support. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_PCI_CAP_NPCACHE
value|BIT(2)
end_define

begin_comment
comment|/* Not present page cached. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_PCI_CAP_EFR
value|BIT(3)
end_define

begin_comment
comment|/* Extended features. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_PCI_CAP_EXT
value|BIT(4)
end_define

begin_comment
comment|/* Miscellaneous information reg. */
end_comment

begin_comment
comment|/*  * IOMMU extended features.  */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EX_FEA_PREFSUP
value|BIT(0)
end_define

begin_comment
comment|/* Prefetch command support. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EX_FEA_PPRSUP
value|BIT(1)
end_define

begin_comment
comment|/* PPR support */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EX_FEA_XTSUP
value|BIT(2)
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EX_FEA_NXSUP
value|BIT(3)
end_define

begin_comment
comment|/* No-execute. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EX_FEA_GTSUP
value|BIT(4)
end_define

begin_comment
comment|/* Guest translation support. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EX_FEA_EFRW
value|BIT(5)
end_define

begin_comment
comment|/* Reserved */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EX_FEA_IASUP
value|BIT(6)
end_define

begin_comment
comment|/* Invalidate all command supp. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EX_FEA_GASUP
value|BIT(7)
end_define

begin_comment
comment|/* Guest APIC or AVIC support. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EX_FEA_HESUP
value|BIT(8)
end_define

begin_comment
comment|/* Hardware Error. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EX_FEA_PCSUP
value|BIT(9)
end_define

begin_comment
comment|/* Performance counters support. */
end_comment

begin_comment
comment|/* XXX: add more EFER bits. */
end_comment

begin_comment
comment|/*  * Device table entry or DTE  * NOTE: Must be 256-bits/32 bytes aligned.  */
end_comment

begin_struct
struct|struct
name|amdvi_dte
block|{
name|uint32_t
name|dt_valid
range|:
literal|1
decl_stmt|;
comment|/* Device Table valid. */
name|uint32_t
name|pt_valid
range|:
literal|1
decl_stmt|;
comment|/* Page translation valid. */
name|uint8_t
label|:
literal|7
expr_stmt|;
comment|/* Reserved[8:2] */
name|uint8_t
name|pt_level
range|:
literal|3
decl_stmt|;
comment|/* Paging level, 0 to disable. */
name|uint64_t
name|pt_base
range|:
literal|40
decl_stmt|;
comment|/* Page table root pointer. */
name|uint8_t
label|:
literal|3
expr_stmt|;
comment|/* Reserved[54:52] */
name|uint8_t
name|gv_valid
range|:
literal|1
decl_stmt|;
comment|/* Revision 2, GVA to SPA. */
name|uint8_t
name|gv_level
range|:
literal|2
decl_stmt|;
comment|/* Revision 2, GLX level. */
name|uint8_t
name|gv_cr3_lsb
range|:
literal|3
decl_stmt|;
comment|/* Revision 2, GCR3[14:12] */
name|uint8_t
name|read_allow
range|:
literal|1
decl_stmt|;
comment|/* I/O read enabled. */
name|uint8_t
name|write_allow
range|:
literal|1
decl_stmt|;
comment|/* I/O write enabled. */
name|uint8_t
label|:
literal|1
expr_stmt|;
comment|/* Reserved[63] */
name|uint16_t
name|domain_id
range|:
literal|16
decl_stmt|;
comment|/* Domain ID */
name|uint16_t
name|gv_cr3_lsb2
range|:
literal|16
decl_stmt|;
comment|/* Revision 2, GCR3[30:15] */
name|uint8_t
name|iotlb_enable
range|:
literal|1
decl_stmt|;
comment|/* Device support IOTLB */
name|uint8_t
name|sup_second_io_fault
range|:
literal|1
decl_stmt|;
comment|/* Suppress subsequent I/O faults. */
name|uint8_t
name|sup_all_io_fault
range|:
literal|1
decl_stmt|;
comment|/* Suppress all I/O page faults. */
name|uint8_t
name|IOctl
range|:
literal|2
decl_stmt|;
comment|/* Port I/O control. */
name|uint8_t
name|iotlb_cache_disable
range|:
literal|1
decl_stmt|;
comment|/* IOTLB cache hints. */
name|uint8_t
name|snoop_disable
range|:
literal|1
decl_stmt|;
comment|/* Snoop disable. */
name|uint8_t
name|allow_ex
range|:
literal|1
decl_stmt|;
comment|/* Allow exclusion. */
name|uint8_t
name|sysmgmt
range|:
literal|2
decl_stmt|;
comment|/* System management message.*/
name|uint8_t
label|:
literal|1
expr_stmt|;
comment|/* Reserved[106] */
name|uint32_t
name|gv_cr3_msb
range|:
literal|21
decl_stmt|;
comment|/* Revision 2, GCR3[51:31] */
name|uint8_t
name|intmap_valid
range|:
literal|1
decl_stmt|;
comment|/* Interrupt map valid. */
name|uint8_t
name|intmap_len
range|:
literal|4
decl_stmt|;
comment|/* Interrupt map table length. */
name|uint8_t
name|intmap_ign
range|:
literal|1
decl_stmt|;
comment|/* Ignore unmapped interrupts. */
name|uint64_t
name|intmap_base
range|:
literal|46
decl_stmt|;
comment|/* IntMap base. */
name|uint8_t
label|:
literal|4
expr_stmt|;
comment|/* Reserved[183:180] */
name|uint8_t
name|init_pass
range|:
literal|1
decl_stmt|;
comment|/* INIT pass through or PT */
name|uint8_t
name|extintr_pass
range|:
literal|1
decl_stmt|;
comment|/* External Interrupt PT */
name|uint8_t
name|nmi_pass
range|:
literal|1
decl_stmt|;
comment|/* NMI PT */
name|uint8_t
label|:
literal|1
expr_stmt|;
comment|/* Reserved[187] */
name|uint8_t
name|intr_ctrl
range|:
literal|2
decl_stmt|;
comment|/* Interrupt control */
name|uint8_t
name|lint0_pass
range|:
literal|1
decl_stmt|;
comment|/* LINT0 PT */
name|uint8_t
name|lint1_pass
range|:
literal|1
decl_stmt|;
comment|/* LINT1 PT */
name|uint64_t
label|:
literal|64
expr_stmt|;
comment|/* Reserved[255:192] */
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
name|amdvi_dte
argument_list|)
operator|==
literal|32
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * IOMMU command entry.  */
end_comment

begin_struct
struct|struct
name|amdvi_cmd
block|{
name|uint32_t
name|word0
decl_stmt|;
name|uint32_t
name|word1
range|:
literal|28
decl_stmt|;
name|uint8_t
name|opcode
range|:
literal|4
decl_stmt|;
name|uint64_t
name|addr
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

begin_comment
comment|/* Command opcodes. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CMP_WAIT_OPCODE
value|0x1
end_define

begin_comment
comment|/* Completion wait. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INVD_DTE_OPCODE
value|0x2
end_define

begin_comment
comment|/* Invalidate device table entry. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INVD_PAGE_OPCODE
value|0x3
end_define

begin_comment
comment|/* Invalidate pages. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INVD_IOTLB_OPCODE
value|0x4
end_define

begin_comment
comment|/* Invalidate IOTLB pages. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INVD_INTR_OPCODE
value|0x5
end_define

begin_comment
comment|/* Invalidate Interrupt table. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_PREFETCH_PAGES_OPCODE
value|0x6
end_define

begin_comment
comment|/* Prefetch IOMMU pages. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_COMP_PPR_OPCODE
value|0x7
end_define

begin_comment
comment|/* Complete PPR request. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INV_ALL_OPCODE
value|0x8
end_define

begin_comment
comment|/* Invalidate all. */
end_comment

begin_comment
comment|/* Completion wait attributes. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CMP_WAIT_STORE
value|BIT(0)
end_define

begin_comment
comment|/* Write back data. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CMP_WAIT_INTR
value|BIT(1)
end_define

begin_comment
comment|/* Completion wait interrupt. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CMP_WAIT_FLUSH
value|BIT(2)
end_define

begin_comment
comment|/* Flush queue. */
end_comment

begin_comment
comment|/* Invalidate page. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INVD_PAGE_S
value|BIT(0)
end_define

begin_comment
comment|/* Invalidation size. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INVD_PAGE_PDE
value|BIT(1)
end_define

begin_comment
comment|/* Invalidate PDE. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INVD_PAGE_GN_GVA
value|BIT(2)
end_define

begin_comment
comment|/* GPA or GVA. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INVD_PAGE_ALL_ADDR
value|(0x7FFFFFFFFFFFFULL<< 12)
end_define

begin_comment
comment|/* Invalidate IOTLB. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INVD_IOTLB_S
value|BIT(0)
end_define

begin_comment
comment|/* Invalidation size 4k or addr */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INVD_IOTLB_GN_GVA
value|BIT(2)
end_define

begin_comment
comment|/* GPA or GVA. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_INVD_IOTLB_ALL_ADDR
value|(0x7FFFFFFFFFFFFULL<< 12)
end_define

begin_comment
comment|/* XXX: add more command entries. */
end_comment

begin_comment
comment|/*  * IOMMU event entry.  */
end_comment

begin_struct
struct|struct
name|amdvi_event
block|{
name|uint16_t
name|devid
decl_stmt|;
name|uint16_t
name|pasid_hi
decl_stmt|;
name|uint16_t
name|pasid_domid
decl_stmt|;
comment|/* PASID low or DomainID */
name|uint16_t
name|flag
range|:
literal|12
decl_stmt|;
name|uint8_t
name|opcode
range|:
literal|4
decl_stmt|;
name|uint64_t
name|addr
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
name|amdvi_event
argument_list|)
operator|==
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* Various event types. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EVENT_INVALID_DTE
value|0x1
end_define

begin_define
define|#
directive|define
name|AMDVI_EVENT_PFAULT
value|0x2
end_define

begin_define
define|#
directive|define
name|AMDVI_EVENT_DTE_HW_ERROR
value|0x3
end_define

begin_define
define|#
directive|define
name|AMDVI_EVENT_PAGE_HW_ERROR
value|0x4
end_define

begin_define
define|#
directive|define
name|AMDVI_EVENT_ILLEGAL_CMD
value|0x5
end_define

begin_define
define|#
directive|define
name|AMDVI_EVENT_CMD_HW_ERROR
value|0x6
end_define

begin_define
define|#
directive|define
name|AMDVI_EVENT_IOTLB_TIMEOUT
value|0x7
end_define

begin_define
define|#
directive|define
name|AMDVI_EVENT_INVALID_DTE_REQ
value|0x8
end_define

begin_define
define|#
directive|define
name|AMDVI_EVENT_INVALID_PPR_REQ
value|0x9
end_define

begin_define
define|#
directive|define
name|AMDVI_EVENT_COUNTER_ZERO
value|0xA
end_define

begin_define
define|#
directive|define
name|AMDVI_EVENT_FLAG_MASK
value|0x1FF
end_define

begin_comment
comment|/* Mask for event flags. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_EVENT_FLAG_TYPE
parameter_list|(
name|x
parameter_list|)
value|(((x)>> 9)& 0x3)
end_define

begin_comment
comment|/*  * IOMMU control block.  */
end_comment

begin_struct
struct|struct
name|amdvi_ctrl
block|{
struct|struct
block|{
name|uint16_t
name|size
range|:
literal|9
decl_stmt|;
name|uint16_t
label|:
literal|3
expr_stmt|;
name|uint64_t
name|base
range|:
literal|40
decl_stmt|;
comment|/* Devtable register base. */
name|uint16_t
label|:
literal|12
expr_stmt|;
block|}
name|dte
struct|;
struct|struct
block|{
name|uint16_t
label|:
literal|12
expr_stmt|;
name|uint64_t
name|base
range|:
literal|40
decl_stmt|;
name|uint8_t
label|:
literal|4
expr_stmt|;
name|uint8_t
name|len
range|:
literal|4
decl_stmt|;
name|uint8_t
label|:
literal|4
expr_stmt|;
block|}
name|cmd
struct|;
struct|struct
block|{
name|uint16_t
label|:
literal|12
expr_stmt|;
name|uint64_t
name|base
range|:
literal|40
decl_stmt|;
name|uint8_t
label|:
literal|4
expr_stmt|;
name|uint8_t
name|len
range|:
literal|4
decl_stmt|;
name|uint8_t
label|:
literal|4
expr_stmt|;
block|}
name|event
struct|;
name|uint16_t
name|control
range|:
literal|13
decl_stmt|;
name|uint64_t
label|:
literal|51
expr_stmt|;
struct|struct
block|{
name|uint8_t
name|enable
range|:
literal|1
decl_stmt|;
name|uint8_t
name|allow
range|:
literal|1
decl_stmt|;
name|uint16_t
label|:
literal|10
expr_stmt|;
name|uint64_t
name|base
range|:
literal|40
decl_stmt|;
name|uint16_t
label|:
literal|12
expr_stmt|;
name|uint16_t
label|:
literal|12
expr_stmt|;
name|uint64_t
name|limit
range|:
literal|40
decl_stmt|;
name|uint16_t
label|:
literal|12
expr_stmt|;
block|}
name|excl
struct|;
comment|/*  	 * Revision 2 only.  	 */
name|uint64_t
name|ex_feature
decl_stmt|;
struct|struct
block|{
name|uint16_t
label|:
literal|12
expr_stmt|;
name|uint64_t
name|base
range|:
literal|40
decl_stmt|;
name|uint8_t
label|:
literal|4
expr_stmt|;
name|uint8_t
name|len
range|:
literal|4
decl_stmt|;
name|uint8_t
label|:
literal|4
expr_stmt|;
block|}
name|ppr
struct|;
name|uint64_t
name|first_event
decl_stmt|;
name|uint64_t
name|second_event
decl_stmt|;
name|uint64_t
name|event_status
decl_stmt|;
comment|/* Revision 2 only, end. */
name|uint8_t
name|pad1
index|[
literal|0x1FA8
index|]
decl_stmt|;
comment|/* Padding. */
name|uint32_t
name|cmd_head
range|:
literal|19
decl_stmt|;
name|uint64_t
label|:
literal|45
expr_stmt|;
name|uint32_t
name|cmd_tail
range|:
literal|19
decl_stmt|;
name|uint64_t
label|:
literal|45
expr_stmt|;
name|uint32_t
name|evt_head
range|:
literal|19
decl_stmt|;
name|uint64_t
label|:
literal|45
expr_stmt|;
name|uint32_t
name|evt_tail
range|:
literal|19
decl_stmt|;
name|uint64_t
label|:
literal|45
expr_stmt|;
name|uint64_t
label|:
literal|56
expr_stmt|;
name|uint8_t
name|status
range|:
literal|8
decl_stmt|;
name|uint64_t
name|pad2
decl_stmt|;
name|uint8_t
label|:
literal|4
expr_stmt|;
name|uint16_t
name|ppr_head
range|:
literal|15
decl_stmt|;
name|uint64_t
label|:
literal|45
expr_stmt|;
name|uint8_t
label|:
literal|4
expr_stmt|;
name|uint16_t
name|ppr_tail
range|:
literal|15
decl_stmt|;
name|uint64_t
label|:
literal|45
expr_stmt|;
name|uint8_t
name|pad3
index|[
literal|0x1FC0
index|]
decl_stmt|;
comment|/* Padding. */
comment|/* XXX: More for rev2. */
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
name|offsetof
argument_list|(
expr|struct
name|amdvi_ctrl
argument_list|,
name|pad1
argument_list|)
operator|==
literal|0x58
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|amdvi_ctrl
argument_list|,
name|pad2
argument_list|)
operator|==
literal|0x2028
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
name|offsetof
argument_list|(
expr|struct
name|amdvi_ctrl
argument_list|,
name|pad3
argument_list|)
operator|==
literal|0x2040
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|AMDVI_MMIO_V1_SIZE
value|(4 * PAGE_SIZE)
end_define

begin_comment
comment|/* v1 size */
end_comment

begin_comment
comment|/*   * AMF IOMMU v2 size including event counters   */
end_comment

begin_define
define|#
directive|define
name|AMDVI_MMIO_V2_SIZE
value|(8 * PAGE_SIZE)
end_define

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|amdvi_ctrl
argument_list|)
operator|==
literal|0x4000
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|amdvi_ctrl
argument_list|)
operator|==
name|AMDVI_MMIO_V1_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* IVHD flag */
end_comment

begin_define
define|#
directive|define
name|IVHD_FLAG_HTT
value|BIT(0)
end_define

begin_comment
comment|/* Hypertransport Tunnel. */
end_comment

begin_define
define|#
directive|define
name|IVHD_FLAG_PPW
value|BIT(1)
end_define

begin_comment
comment|/* Pass posted write. */
end_comment

begin_define
define|#
directive|define
name|IVHD_FLAG_RPPW
value|BIT(2)
end_define

begin_comment
comment|/* Response pass posted write. */
end_comment

begin_define
define|#
directive|define
name|IVHD_FLAG_ISOC
value|BIT(3)
end_define

begin_comment
comment|/* Isoc support. */
end_comment

begin_define
define|#
directive|define
name|IVHD_FLAG_IOTLB
value|BIT(4)
end_define

begin_comment
comment|/* IOTLB support. */
end_comment

begin_define
define|#
directive|define
name|IVHD_FLAG_COH
value|BIT(5)
end_define

begin_comment
comment|/* Coherent control, default 1 */
end_comment

begin_define
define|#
directive|define
name|IVHD_FLAG_PFS
value|BIT(6)
end_define

begin_comment
comment|/* Prefetch IOMMU pages. */
end_comment

begin_define
define|#
directive|define
name|IVHD_FLAG_PPRS
value|BIT(7)
end_define

begin_comment
comment|/* Peripheral page support. */
end_comment

begin_comment
comment|/* IVHD device entry data setting. */
end_comment

begin_define
define|#
directive|define
name|IVHD_DEV_LINT0_PASS
value|BIT(6)
end_define

begin_comment
comment|/* LINT0 interrupts. */
end_comment

begin_define
define|#
directive|define
name|IVHD_DEV_LINT1_PASS
value|BIT(7)
end_define

begin_comment
comment|/* LINT1 interrupts. */
end_comment

begin_comment
comment|/* Bit[5:4] for System Mgmt. Bit3 is reserved. */
end_comment

begin_define
define|#
directive|define
name|IVHD_DEV_INIT_PASS
value|BIT(0)
end_define

begin_comment
comment|/* INIT */
end_comment

begin_define
define|#
directive|define
name|IVHD_DEV_EXTINTR_PASS
value|BIT(1)
end_define

begin_comment
comment|/* ExtInt */
end_comment

begin_define
define|#
directive|define
name|IVHD_DEV_NMI_PASS
value|BIT(2)
end_define

begin_comment
comment|/* NMI */
end_comment

begin_comment
comment|/* IVHD 8-byte extended data settings. */
end_comment

begin_define
define|#
directive|define
name|IVHD_DEV_EXT_ATS_DISABLE
value|BIT(31)
end_define

begin_comment
comment|/* Disable ATS */
end_comment

begin_comment
comment|/* IOMMU control register. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_EN
value|BIT(0)
end_define

begin_comment
comment|/* IOMMU enable. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_HTT
value|BIT(1)
end_define

begin_comment
comment|/* Hypertransport tunnel enable. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_ELOG
value|BIT(2)
end_define

begin_comment
comment|/* Event log enable. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_ELOGINT
value|BIT(3)
end_define

begin_comment
comment|/* Event log interrupt. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_COMINT
value|BIT(4)
end_define

begin_comment
comment|/* Completion wait interrupt. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_PPW
value|BIT(8)
end_define

begin_define
define|#
directive|define
name|AMDVI_CTRL_RPPW
value|BIT(9)
end_define

begin_define
define|#
directive|define
name|AMDVI_CTRL_COH
value|BIT(10)
end_define

begin_define
define|#
directive|define
name|AMDVI_CTRL_ISOC
value|BIT(11)
end_define

begin_define
define|#
directive|define
name|AMDVI_CTRL_CMD
value|BIT(12)
end_define

begin_comment
comment|/* Command buffer enable. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_PPRLOG
value|BIT(13)
end_define

begin_define
define|#
directive|define
name|AMDVI_CTRL_PPRINT
value|BIT(14)
end_define

begin_define
define|#
directive|define
name|AMDVI_CTRL_PPREN
value|BIT(15)
end_define

begin_define
define|#
directive|define
name|AMDVI_CTRL_GTE
value|BIT(16)
end_define

begin_comment
comment|/* Guest translation enable. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_GAE
value|BIT(17)
end_define

begin_comment
comment|/* Guest APIC enable. */
end_comment

begin_comment
comment|/* Invalidation timeout. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_INV_NO_TO
value|0
end_define

begin_comment
comment|/* No timeout. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_INV_TO_1ms
value|1
end_define

begin_comment
comment|/* 1 ms */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_INV_TO_10ms
value|2
end_define

begin_comment
comment|/* 10 ms */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_INV_TO_100ms
value|3
end_define

begin_comment
comment|/* 100 ms */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_INV_TO_1S
value|4
end_define

begin_comment
comment|/* 1 second */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_INV_TO_10S
value|5
end_define

begin_comment
comment|/* 10 second */
end_comment

begin_define
define|#
directive|define
name|AMDVI_CTRL_INV_TO_100S
value|6
end_define

begin_comment
comment|/* 100 second */
end_comment

begin_comment
comment|/*  * Max number of PCI devices.  * 256 bus x 32 slot/devices x 8 functions.  */
end_comment

begin_define
define|#
directive|define
name|PCI_NUM_DEV_MAX
value|0x10000
end_define

begin_comment
comment|/* Maximum number of domains supported by IOMMU. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_MAX_DOMAIN
value|(BIT(16) - 1)
end_define

begin_comment
comment|/*  * IOMMU Page Table attributes.  */
end_comment

begin_define
define|#
directive|define
name|AMDVI_PT_PRESENT
value|BIT(0)
end_define

begin_define
define|#
directive|define
name|AMDVI_PT_COHERENT
value|BIT(60)
end_define

begin_define
define|#
directive|define
name|AMDVI_PT_READ
value|BIT(61)
end_define

begin_define
define|#
directive|define
name|AMDVI_PT_WRITE
value|BIT(62)
end_define

begin_define
define|#
directive|define
name|AMDVI_PT_RW
value|(AMDVI_PT_READ | AMDVI_PT_WRITE)
end_define

begin_define
define|#
directive|define
name|AMDVI_PT_MASK
value|0xFFFFFFFFFF000UL
end_define

begin_comment
comment|/* Only [51:12] for PA */
end_comment

begin_define
define|#
directive|define
name|AMDVI_PD_LEVEL_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|AMDVI_PD_SUPER
parameter_list|(
name|x
parameter_list|)
value|(((x)>> AMDVI_PD_LEVEL_SHIFT) == 7)
end_define

begin_comment
comment|/*  * IOMMU Status, offset 0x2020  */
end_comment

begin_define
define|#
directive|define
name|AMDVI_STATUS_EV_OF
value|BIT(0)
end_define

begin_comment
comment|/* Event overflow. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_STATUS_EV_INTR
value|BIT(1)
end_define

begin_comment
comment|/* Event interrupt. */
end_comment

begin_comment
comment|/* Completion wait command completed. */
end_comment

begin_define
define|#
directive|define
name|AMDVI_STATUS_CMP
value|BIT(2)
end_define

begin_define
define|#
directive|define
name|IVRS_CTRL_RID
value|1
end_define

begin_comment
comment|/* MMIO RID */
end_comment

begin_comment
comment|/* ACPI IVHD */
end_comment

begin_struct
struct|struct
name|ivhd_dev_cfg
block|{
name|uint32_t
name|start_id
decl_stmt|;
name|uint32_t
name|end_id
decl_stmt|;
name|uint8_t
name|data
decl_stmt|;
comment|/* Device configuration. */
name|bool
name|enable_ats
decl_stmt|;
comment|/* ATS enabled for the device. */
name|int
name|ats_qlen
decl_stmt|;
comment|/* ATS invalidation queue depth. */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|amdvi_domain
block|{
name|uint64_t
modifier|*
name|ptp
decl_stmt|;
comment|/* Highest level page table */
name|int
name|ptp_level
decl_stmt|;
comment|/* Level of page tables */
name|u_int
name|id
decl_stmt|;
comment|/* Domain id */
name|SLIST_ENTRY
argument_list|(
argument|amdvi_domain
argument_list|)
name|next
expr_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * AMD IOMMU softc.  */
end_comment

begin_struct
struct|struct
name|amdvi_softc
block|{
name|struct
name|amdvi_ctrl
modifier|*
name|ctrl
decl_stmt|;
comment|/* Control area. */
name|device_t
name|dev
decl_stmt|;
comment|/* IOMMU device. */
name|bool
name|iotlb
decl_stmt|;
comment|/* IOTLB supported by IOMMU */
name|struct
name|amdvi_cmd
modifier|*
name|cmd
decl_stmt|;
comment|/* Command descriptor area. */
name|int
name|cmd_max
decl_stmt|;
comment|/* Max number of commands. */
name|uint64_t
name|cmp_data
decl_stmt|;
comment|/* Command completion write back. */
name|struct
name|amdvi_event
modifier|*
name|event
decl_stmt|;
comment|/* Event descriptor area. */
name|struct
name|resource
modifier|*
name|event_res
decl_stmt|;
comment|/* Event interrupt resource. */
name|void
modifier|*
name|event_tag
decl_stmt|;
comment|/* Event interrupt tag. */
name|int
name|event_max
decl_stmt|;
comment|/* Max number of events. */
name|int
name|event_irq
decl_stmt|;
name|int
name|event_rid
decl_stmt|;
comment|/* ACPI various flags. */
name|uint32_t
name|ivhd_flag
decl_stmt|;
comment|/* ACPI IVHD flag. */
name|uint32_t
name|ivhd_efr
decl_stmt|;
comment|/* ACPI v1 Reserved or v2 EFR . */
comment|/* PCI related. */
name|uint16_t
name|cap_off
decl_stmt|;
comment|/* PCI Capability offset. */
name|uint8_t
name|pci_cap
decl_stmt|;
comment|/* PCI capability. */
name|uint64_t
name|pci_efr
decl_stmt|;
comment|/* PCI EFR for rev2.0 */
name|uint16_t
name|pci_seg
decl_stmt|;
comment|/* IOMMU PCI domain/segment. */
name|uint16_t
name|pci_rid
decl_stmt|;
comment|/* PCI BDF of IOMMU */
comment|/* Device range under this IOMMU. */
name|uint16_t
name|start_dev_rid
decl_stmt|;
comment|/* First device under this IOMMU. */
name|uint16_t
name|end_dev_rid
decl_stmt|;
comment|/* Last device under this IOMMU. */
comment|/* BIOS provided device configuration for end points. */
name|struct
name|ivhd_dev_cfg
name|dev_cfg
index|[
literal|10
index|]
decl_stmt|;
name|int
name|dev_cfg_cnt
decl_stmt|;
comment|/* Software statistics. */
name|uint64_t
name|event_intr_cnt
decl_stmt|;
comment|/* Total event INTR count. */
name|uint64_t
name|total_cmd
decl_stmt|;
comment|/* Total number of commands. */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|amdvi_setup_hw
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|amdvi_teardown_hw
parameter_list|(
name|struct
name|amdvi_softc
modifier|*
name|softc
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _AMDVI_PRIV_H_ */
end_comment

end_unit

