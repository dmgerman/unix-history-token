begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 John H. Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KVM_AMD64_H__
end_ifndef

begin_define
define|#
directive|define
name|__KVM_AMD64_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
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
name|uint64_t
name|amd64_physaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|amd64_pte_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|amd64_pde_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|amd64_pdpe_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|amd64_pml4e_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AMD64_NPTEPG
value|(AMD64_PAGE_SIZE / sizeof(amd64_pte_t))
end_define

begin_define
define|#
directive|define
name|AMD64_PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AMD64_PAGE_SIZE
value|(1<< AMD64_PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|AMD64_PAGE_MASK
value|(AMD64_PAGE_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|AMD64_NPDEPG
value|(AMD64_PAGE_SIZE / sizeof(amd64_pde_t))
end_define

begin_define
define|#
directive|define
name|AMD64_PDRSHIFT
value|21
end_define

begin_define
define|#
directive|define
name|AMD64_NBPDR
value|(1<< AMD64_PDRSHIFT)
end_define

begin_define
define|#
directive|define
name|AMD64_PDRMASK
value|(AMD64_NBPDR - 1)
end_define

begin_define
define|#
directive|define
name|AMD64_NPDPEPG
value|(AMD64_PAGE_SIZE / sizeof(amd64_pdpe_t))
end_define

begin_define
define|#
directive|define
name|AMD64_PDPSHIFT
value|30
end_define

begin_define
define|#
directive|define
name|AMD64_NBPDP
value|(1<< AMD64_PDPSHIFT)
end_define

begin_define
define|#
directive|define
name|AMD64_PDPMASK
value|(AMD64_NBPDP - 1)
end_define

begin_define
define|#
directive|define
name|AMD64_NPML4EPG
value|(AMD64_PAGE_SIZE / sizeof(amd64_pml4e_t))
end_define

begin_define
define|#
directive|define
name|AMD64_PML4SHIFT
value|39
end_define

begin_define
define|#
directive|define
name|AMD64_PG_NX
value|(1ULL<< 63)
end_define

begin_define
define|#
directive|define
name|AMD64_PG_V
value|0x001
end_define

begin_define
define|#
directive|define
name|AMD64_PG_RW
value|0x002
end_define

begin_define
define|#
directive|define
name|AMD64_PG_PS
value|0x080
end_define

begin_define
define|#
directive|define
name|AMD64_PG_FRAME
value|(0x000ffffffffff000)
end_define

begin_define
define|#
directive|define
name|AMD64_PG_PS_FRAME
value|(0x000fffffffe00000)
end_define

begin_define
define|#
directive|define
name|AMD64_PG_1GB_FRAME
value|(0x000fffffc0000000)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__amd64__
end_ifdef

begin_assert
assert|_Static_assert
argument_list|(
name|NPTEPG
operator|==
name|AMD64_NPTEPG
argument_list|,
literal|"NPTEPG mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PAGE_SHIFT
operator|==
name|AMD64_PAGE_SHIFT
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
name|AMD64_PAGE_SIZE
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
name|AMD64_PAGE_MASK
argument_list|,
literal|"PAGE_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|NPDEPG
operator|==
name|AMD64_NPDEPG
argument_list|,
literal|"NPDEPG mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PDRSHIFT
operator|==
name|AMD64_PDRSHIFT
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
name|AMD64_NBPDR
argument_list|,
literal|"NBPDR mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PDRMASK
operator|==
name|AMD64_PDRMASK
argument_list|,
literal|"PDRMASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|NPDPEPG
operator|==
name|AMD64_NPDPEPG
argument_list|,
literal|"NPDPEPG mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PDPSHIFT
operator|==
name|AMD64_PDPSHIFT
argument_list|,
literal|"PDPSHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|NBPDP
operator|==
name|AMD64_NBPDP
argument_list|,
literal|"NBPDP mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PDPMASK
operator|==
name|AMD64_PDPMASK
argument_list|,
literal|"PDPMASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|NPML4EPG
operator|==
name|AMD64_NPML4EPG
argument_list|,
literal|"NPML4EPG mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PML4SHIFT
operator|==
name|AMD64_PML4SHIFT
argument_list|,
literal|"PML4SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PG_V
operator|==
name|AMD64_PG_V
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
name|AMD64_PG_PS
argument_list|,
literal|"PG_PS mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|PG_FRAME
operator|==
name|AMD64_PG_FRAME
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
name|AMD64_PG_PS_FRAME
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
name|_amd64_native
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
comment|/* !__KVM_AMD64_H__ */
end_comment

end_unit

