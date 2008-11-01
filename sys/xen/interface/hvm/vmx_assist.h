begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * vmx_assist.h: Context definitions for the VMXASSIST world switch.  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  *  * Leendert van Doorn, leendert@watson.ibm.com  * Copyright (c) 2005, International Business Machines Corporation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMX_ASSIST_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMX_ASSIST_H_
end_define

begin_define
define|#
directive|define
name|VMXASSIST_BASE
value|0xD0000
end_define

begin_define
define|#
directive|define
name|VMXASSIST_MAGIC
value|0x17101966
end_define

begin_define
define|#
directive|define
name|VMXASSIST_MAGIC_OFFSET
value|(VMXASSIST_BASE+8)
end_define

begin_define
define|#
directive|define
name|VMXASSIST_NEW_CONTEXT
value|(VMXASSIST_BASE + 12)
end_define

begin_define
define|#
directive|define
name|VMXASSIST_OLD_CONTEXT
value|(VMXASSIST_NEW_CONTEXT + 4)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|__ASSEMBLY__
end_ifndef

begin_define
define|#
directive|define
name|NR_EXCEPTION_HANDLER
value|32
end_define

begin_define
define|#
directive|define
name|NR_INTERRUPT_HANDLERS
value|16
end_define

begin_define
define|#
directive|define
name|NR_TRAPS
value|(NR_EXCEPTION_HANDLER+NR_INTERRUPT_HANDLERS)
end_define

begin_union
union|union
name|vmcs_arbytes
block|{
struct|struct
name|arbyte_fields
block|{
name|unsigned
name|int
name|seg_type
range|:
literal|4
decl_stmt|,
name|s
range|:
literal|1
decl_stmt|,
name|dpl
range|:
literal|2
decl_stmt|,
name|p
range|:
literal|1
decl_stmt|,
name|reserved0
range|:
literal|4
decl_stmt|,
name|avl
range|:
literal|1
decl_stmt|,
name|reserved1
range|:
literal|1
decl_stmt|,
name|default_ops_size
range|:
literal|1
decl_stmt|,
name|g
range|:
literal|1
decl_stmt|,
name|null_bit
range|:
literal|1
decl_stmt|,
name|reserved2
range|:
literal|15
decl_stmt|;
block|}
name|fields
struct|;
name|unsigned
name|int
name|bytes
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/*  * World switch state  */
end_comment

begin_struct
struct|struct
name|vmx_assist_context
block|{
name|uint32_t
name|eip
decl_stmt|;
comment|/* execution pointer */
name|uint32_t
name|esp
decl_stmt|;
comment|/* stack pointer */
name|uint32_t
name|eflags
decl_stmt|;
comment|/* flags register */
name|uint32_t
name|cr0
decl_stmt|;
name|uint32_t
name|cr3
decl_stmt|;
comment|/* page table directory */
name|uint32_t
name|cr4
decl_stmt|;
name|uint32_t
name|idtr_limit
decl_stmt|;
comment|/* idt */
name|uint32_t
name|idtr_base
decl_stmt|;
name|uint32_t
name|gdtr_limit
decl_stmt|;
comment|/* gdt */
name|uint32_t
name|gdtr_base
decl_stmt|;
name|uint32_t
name|cs_sel
decl_stmt|;
comment|/* cs selector */
name|uint32_t
name|cs_limit
decl_stmt|;
name|uint32_t
name|cs_base
decl_stmt|;
name|union
name|vmcs_arbytes
name|cs_arbytes
decl_stmt|;
name|uint32_t
name|ds_sel
decl_stmt|;
comment|/* ds selector */
name|uint32_t
name|ds_limit
decl_stmt|;
name|uint32_t
name|ds_base
decl_stmt|;
name|union
name|vmcs_arbytes
name|ds_arbytes
decl_stmt|;
name|uint32_t
name|es_sel
decl_stmt|;
comment|/* es selector */
name|uint32_t
name|es_limit
decl_stmt|;
name|uint32_t
name|es_base
decl_stmt|;
name|union
name|vmcs_arbytes
name|es_arbytes
decl_stmt|;
name|uint32_t
name|ss_sel
decl_stmt|;
comment|/* ss selector */
name|uint32_t
name|ss_limit
decl_stmt|;
name|uint32_t
name|ss_base
decl_stmt|;
name|union
name|vmcs_arbytes
name|ss_arbytes
decl_stmt|;
name|uint32_t
name|fs_sel
decl_stmt|;
comment|/* fs selector */
name|uint32_t
name|fs_limit
decl_stmt|;
name|uint32_t
name|fs_base
decl_stmt|;
name|union
name|vmcs_arbytes
name|fs_arbytes
decl_stmt|;
name|uint32_t
name|gs_sel
decl_stmt|;
comment|/* gs selector */
name|uint32_t
name|gs_limit
decl_stmt|;
name|uint32_t
name|gs_base
decl_stmt|;
name|union
name|vmcs_arbytes
name|gs_arbytes
decl_stmt|;
name|uint32_t
name|tr_sel
decl_stmt|;
comment|/* task selector */
name|uint32_t
name|tr_limit
decl_stmt|;
name|uint32_t
name|tr_base
decl_stmt|;
name|union
name|vmcs_arbytes
name|tr_arbytes
decl_stmt|;
name|uint32_t
name|ldtr_sel
decl_stmt|;
comment|/* ldtr selector */
name|uint32_t
name|ldtr_limit
decl_stmt|;
name|uint32_t
name|ldtr_base
decl_stmt|;
name|union
name|vmcs_arbytes
name|ldtr_arbytes
decl_stmt|;
name|unsigned
name|char
name|rm_irqbase
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|vmx_assist_context
name|vmx_assist_context_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ASSEMBLY__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _VMX_ASSIST_H_ */
end_comment

begin_comment
comment|/*  * Local variables:  * mode: C  * c-set-style: "BSD"  * c-basic-offset: 4  * tab-width: 4  * indent-tabs-mode: nil  * End:  */
end_comment

end_unit

