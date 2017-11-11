begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 John H. Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KVM_I386_H__
end_ifndef

begin_define
define|#
directive|define
name|__KVM_I386_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint32_t
name|i386_physaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|i386_pte_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|i386_pde_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|i386_physaddr_pae_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|i386_pte_pae_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|i386_pde_pae_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|I386_PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|I386_PAGE_SIZE
value|(1<< I386_PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|I386_PAGE_MASK
value|(I386_PAGE_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|I386_NPTEPG
value|(I386_PAGE_SIZE / sizeof(i386_pte_t))
end_define

begin_define
define|#
directive|define
name|I386_PDRSHIFT
value|22
end_define

begin_define
define|#
directive|define
name|I386_NBPDR
value|(1<< I386_PDRSHIFT)
end_define

begin_define
define|#
directive|define
name|I386_PAGE_PS_MASK
value|(I386_NBPDR - 1)
end_define

begin_define
define|#
directive|define
name|I386_NPTEPG_PAE
value|(I386_PAGE_SIZE / sizeof(i386_pte_pae_t))
end_define

begin_define
define|#
directive|define
name|I386_PDRSHIFT_PAE
value|21
end_define

begin_define
define|#
directive|define
name|I386_NBPDR_PAE
value|(1<< I386_PDRSHIFT_PAE)
end_define

begin_define
define|#
directive|define
name|I386_PAGE_PS_MASK_PAE
value|(I386_NBPDR_PAE - 1)
end_define

begin_comment
comment|/* Source: i386/include/pmap.h */
end_comment

begin_define
define|#
directive|define
name|I386_PG_V
value|0x001
end_define

begin_define
define|#
directive|define
name|I386_PG_RW
value|0x002
end_define

begin_define
define|#
directive|define
name|I386_PG_PS
value|0x080
end_define

begin_define
define|#
directive|define
name|I386_PG_NX
value|(1ULL<< 63)
end_define

begin_define
define|#
directive|define
name|I386_PG_FRAME_PAE
value|(0x000ffffffffff000ull)
end_define

begin_define
define|#
directive|define
name|I386_PG_PS_FRAME_PAE
value|(0x000fffffffe00000ull)
end_define

begin_define
define|#
directive|define
name|I386_PG_FRAME
value|(0xfffff000)
end_define

begin_define
define|#
directive|define
name|I386_PG_PS_FRAME
value|(0xffc00000)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__i386__
end_ifdef

begin_assert
assert|_Static_assert
argument_list|(
name|PAGE_SHIFT
operator|==
name|I386_PAGE_SHIFT
argument_list|,
literal|"PAGE_SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PAGE_SIZE
operator|==
name|I386_PAGE_SIZE
argument_list|,
literal|"PAGE_SIZE mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PAGE_MASK
operator|==
name|I386_PAGE_MASK
argument_list|,
literal|"PAGE_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|NPTEPG
operator|==
name|I386_NPTEPG
argument_list|,
literal|"NPTEPG mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PDRSHIFT
operator|==
name|I386_PDRSHIFT
argument_list|,
literal|"PDRSHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|NBPDR
operator|==
name|I386_NBPDR
argument_list|,
literal|"NBPDR mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PG_V
operator|==
name|I386_PG_V
argument_list|,
literal|"PG_V mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PG_PS
operator|==
name|I386_PG_PS
argument_list|,
literal|"PG_PS mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
operator|(
name|u_int
operator|)
name|PG_FRAME
operator|==
name|I386_PG_FRAME
argument_list|,
literal|"PG_FRAME mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PG_PS_FRAME
operator|==
name|I386_PG_PS_FRAME
argument_list|,
literal|"PG_PS_FRAME mismatch"
argument_list|)
assert|;
end_assert

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|_i386_native
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__KVM_I386_H__ */
end_comment

end_unit

