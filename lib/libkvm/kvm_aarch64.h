begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 John H. Baldwin<jhb@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__KVM_AARCH64_H__
end_ifndef

begin_define
define|#
directive|define
name|__KVM_AARCH64_H__
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__aarch64__
end_ifdef

begin_include
include|#
directive|include
file|<machine/pte.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|uint64_t
name|aarch64_physaddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|aarch64_pte_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|AARCH64_PAGE_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AARCH64_PAGE_SIZE
value|(1<< AARCH64_PAGE_SHIFT)
end_define

begin_define
define|#
directive|define
name|AARCH64_PAGE_MASK
value|(AARCH64_PAGE_SIZE - 1)
end_define

begin_comment
comment|/* Source: arm64/include/pte.h */
end_comment

begin_define
define|#
directive|define
name|AARCH64_ATTR_MASK
value|0xfff0000000000fff
end_define

begin_define
define|#
directive|define
name|AARCH64_ATTR_UXN
value|(1ULL<< 54)
end_define

begin_define
define|#
directive|define
name|AARCH64_ATTR_PXN
value|(1ULL<< 53)
end_define

begin_define
define|#
directive|define
name|AARCH64_ATTR_XN
value|(AARCH64_ATTR_PXN | AARCH64_ATTR_UXN)
end_define

begin_define
define|#
directive|define
name|AARCH64_ATTR_AP
parameter_list|(
name|x
parameter_list|)
value|((x)<< 6)
end_define

begin_define
define|#
directive|define
name|AARCH64_ATTR_AP_RO
value|(1<< 1)
end_define

begin_define
define|#
directive|define
name|AARCH64_ATTR_DESCR_MASK
value|3
end_define

begin_define
define|#
directive|define
name|AARCH64_L3_SHIFT
value|12
end_define

begin_define
define|#
directive|define
name|AARCH64_L3_PAGE
value|0x3
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__aarch64__
end_ifdef

begin_assert
assert|_Static_assert
argument_list|(
name|PAGE_SHIFT
operator|==
name|AARCH64_PAGE_SHIFT
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
name|AARCH64_PAGE_SIZE
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
name|AARCH64_PAGE_MASK
argument_list|,
literal|"PAGE_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|ATTR_MASK
operator|==
name|AARCH64_ATTR_MASK
argument_list|,
literal|"ATTR_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|ATTR_DESCR_MASK
operator|==
name|AARCH64_ATTR_DESCR_MASK
argument_list|,
literal|"ATTR_DESCR_MASK mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L3_SHIFT
operator|==
name|AARCH64_L3_SHIFT
argument_list|,
literal|"L3_SHIFT mismatch"
argument_list|)
assert|;
end_assert

begin_assert
assert|_Static_assert
argument_list|(
name|L3_PAGE
operator|==
name|AARCH64_L3_PAGE
argument_list|,
literal|"L3_PAGE mismatch"
argument_list|)
assert|;
end_assert

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__KVM_AARCH64_H__ */
end_comment

end_unit

