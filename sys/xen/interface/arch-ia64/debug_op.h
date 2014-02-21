begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************  * debug_op.h  *  * Copyright (c) 2007 Tristan Gingold<tgingold@free.fr>  *  * Permission is hereby granted, free of charge, to any person obtaining a copy  * of this software and associated documentation files (the "Software"), to  * deal in the Software without restriction, including without limitation the  * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or  * sell copies of the Software, and to permit persons to whom the Software is  * furnished to do so, subject to the following conditions:  *  * The above copyright notice and this permission notice shall be included in  * all copies or substantial portions of the Software.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING  * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER  * DEALINGS IN THE SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__XEN_PUBLIC_IA64_DEBUG_OP_H__
end_ifndef

begin_define
define|#
directive|define
name|__XEN_PUBLIC_IA64_DEBUG_OP_H__
end_define

begin_comment
comment|/* Set/Get extra conditions to break.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_OP_SET_FLAGS
value|1
end_define

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_OP_GET_FLAGS
value|2
end_define

begin_comment
comment|/* Break on kernel single step.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_KERN_SSTEP
value|(1<< 0)
end_define

begin_comment
comment|/* Break on kernel debug (breakpoint or watch point).  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_KERN_DEBUG
value|(1<< 1)
end_define

begin_comment
comment|/* Break on kernel taken branch.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_KERN_TBRANCH
value|(1<< 2)
end_define

begin_comment
comment|/* Break on interrupt injection.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_EXTINT
value|(1<< 3)
end_define

begin_comment
comment|/* Break on interrupt injection.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_EXCEPT
value|(1<< 4)
end_define

begin_comment
comment|/* Break on event injection.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_EVENT
value|(1<< 5)
end_define

begin_comment
comment|/* Break on privop/virtualized instruction (slow path only).  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_PRIVOP
value|(1<< 6)
end_define

begin_comment
comment|/* Break on emulated PAL call (at entry).  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_PAL
value|(1<< 7)
end_define

begin_comment
comment|/* Break on emulated SAL call (at entry).  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_SAL
value|(1<< 8)
end_define

begin_comment
comment|/* Break on emulated EFI call (at entry).  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_EFI
value|(1<< 9)
end_define

begin_comment
comment|/* Break on rfi emulation (slow path only, before exec).  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_RFI
value|(1<< 10)
end_define

begin_comment
comment|/* Break on address translation switch.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_MMU
value|(1<< 11)
end_define

begin_comment
comment|/* Break on bad guest physical address.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_BAD_MPA
value|(1<< 12)
end_define

begin_comment
comment|/* Force psr.ss bit.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_FORCE_SS
value|(1<< 13)
end_define

begin_comment
comment|/* Force psr.db bit.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_FORCE_DB
value|(1<< 14)
end_define

begin_comment
comment|/* Break on ITR/PTR.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_TR
value|(1<< 15)
end_define

begin_comment
comment|/* Break on ITC/PTC.L/PTC.G/PTC.GA.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_ON_TC
value|(1<< 16)
end_define

begin_comment
comment|/* Get translation cache.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_OP_GET_TC
value|3
end_define

begin_comment
comment|/* Translate virtual address to guest physical address.  */
end_comment

begin_define
define|#
directive|define
name|XEN_IA64_DEBUG_OP_TRANSLATE
value|4
end_define

begin_union
union|union
name|xen_ia64_debug_op
block|{
name|uint64_t
name|flags
decl_stmt|;
struct|struct
name|xen_ia64_debug_vtlb
block|{
name|uint64_t
name|nbr
decl_stmt|;
comment|/* IN/OUT */
name|XEN_GUEST_HANDLE_64
argument_list|(
argument|ia64_tr_entry_t
argument_list|)
name|tr
expr_stmt|;
comment|/* IN/OUT */
block|}
name|vtlb
struct|;
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|xen_ia64_debug_op
name|xen_ia64_debug_op_t
typedef|;
end_typedef

begin_expr_stmt
name|DEFINE_XEN_GUEST_HANDLE
argument_list|(
name|xen_ia64_debug_op_t
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __XEN_PUBLIC_IA64_DEBUG_OP_H__ */
end_comment

end_unit

