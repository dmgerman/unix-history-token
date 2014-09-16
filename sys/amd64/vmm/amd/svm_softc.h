begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Anish Gupta (akgupt3@gmail.com)  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SVM_SOFTC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SVM_SOFTC_H_
end_define

begin_define
define|#
directive|define
name|SVM_IO_BITMAP_SIZE
value|(3 * PAGE_SIZE)
end_define

begin_define
define|#
directive|define
name|SVM_MSR_BITMAP_SIZE
value|(2 * PAGE_SIZE)
end_define

begin_struct
struct|struct
name|asid
block|{
name|uint64_t
name|gen
decl_stmt|;
comment|/* range is [1, ~0UL] */
name|uint32_t
name|num
decl_stmt|;
comment|/* range is [1, nasid - 1] */
block|}
struct|;
end_struct

begin_comment
comment|/*  * svm_vpcu contains SVM VMCB state and vcpu register state.  */
end_comment

begin_struct
struct|struct
name|svm_vcpu
block|{
name|struct
name|vmcb
name|vmcb
decl_stmt|;
comment|/* hardware saved vcpu context */
name|struct
name|svm_regctx
name|swctx
decl_stmt|;
comment|/* software saved vcpu context */
name|uint64_t
name|vmcb_pa
decl_stmt|;
comment|/* VMCB physical address */
name|int
name|lastcpu
decl_stmt|;
comment|/* host cpu that the vcpu last ran on */
name|uint32_t
name|dirty
decl_stmt|;
comment|/* state cache bits that must be cleared */
name|long
name|eptgen
decl_stmt|;
comment|/* pmap->pm_eptgen when the vcpu last ran */
name|struct
name|asid
name|asid
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|PAGE_SIZE
argument_list|)
struct|;
end_struct

begin_comment
comment|/*  * SVM softc, one per virtual machine.  */
end_comment

begin_struct
struct|struct
name|svm_softc
block|{
comment|/* 	 * IO permission map, VMCB.ctrl.iopm_base_pa should point to this. 	 * If a bit is set, access to I/O port is intercepted. 	 */
name|uint8_t
name|iopm_bitmap
index|[
name|SVM_IO_BITMAP_SIZE
index|]
decl_stmt|;
comment|/* 	 * MSR permission bitmap, VMCB.ctrl.msrpm_base_pa should point to this. 	 * Two bits are used for each MSR with the LSB used for read access 	 * and the MSB used for write access. A value of '1' indicates that 	 * the operation is intercepted. 	 */
name|uint8_t
name|msr_bitmap
index|[
name|SVM_MSR_BITMAP_SIZE
index|]
decl_stmt|;
name|uint8_t
name|apic_page
index|[
name|VM_MAXCPU
index|]
index|[
name|PAGE_SIZE
index|]
decl_stmt|;
comment|/* Nested Paging */
name|vm_offset_t
name|nptp
decl_stmt|;
comment|/* Virtual machine pointer. */
name|struct
name|vm
modifier|*
name|vm
decl_stmt|;
comment|/* Guest VCPU h/w and s/w context. */
name|struct
name|svm_vcpu
name|vcpu
index|[
name|VM_MAXCPU
index|]
decl_stmt|;
block|}
name|__aligned
argument_list|(
name|PAGE_SIZE
argument_list|)
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
operator|(
name|offsetof
argument_list|(
expr|struct
name|svm_softc
argument_list|,
name|nptp
argument_list|)
operator|&
name|PAGE_MASK
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|svm_vcpu
operator|*
name|svm_get_vcpu
argument_list|(
argument|struct svm_softc *sc
argument_list|,
argument|int vcpu
argument_list|)
block|{
return|return
operator|(
operator|&
operator|(
name|sc
operator|->
name|vcpu
index|[
name|vcpu
index|]
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|vmcb
operator|*
name|svm_get_vmcb
argument_list|(
argument|struct svm_softc *sc
argument_list|,
argument|int vcpu
argument_list|)
block|{
return|return
operator|(
operator|&
operator|(
name|sc
operator|->
name|vcpu
index|[
name|vcpu
index|]
operator|.
name|vmcb
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|vmcb_state
operator|*
name|svm_get_vmcb_state
argument_list|(
argument|struct svm_softc *sc
argument_list|,
argument|int vcpu
argument_list|)
block|{
return|return
operator|(
operator|&
operator|(
name|sc
operator|->
name|vcpu
index|[
name|vcpu
index|]
operator|.
name|vmcb
operator|.
name|state
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|vmcb_ctrl
operator|*
name|svm_get_vmcb_ctrl
argument_list|(
argument|struct svm_softc *sc
argument_list|,
argument|int vcpu
argument_list|)
block|{
return|return
operator|(
operator|&
operator|(
name|sc
operator|->
name|vcpu
index|[
name|vcpu
index|]
operator|.
name|vmcb
operator|.
name|ctrl
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|static
name|__inline
expr|struct
name|svm_regctx
operator|*
name|svm_get_guest_regctx
argument_list|(
argument|struct svm_softc *sc
argument_list|,
argument|int vcpu
argument_list|)
block|{
return|return
operator|(
operator|&
operator|(
name|sc
operator|->
name|vcpu
index|[
name|vcpu
index|]
operator|.
name|swctx
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_function_decl
name|void
name|svm_dump_vmcb
parameter_list|(
name|struct
name|svm_softc
modifier|*
name|svm_sc
parameter_list|,
name|int
name|vcpu
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SVM_SOFTC_H_ */
end_comment

end_unit

