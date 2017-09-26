begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SafeMachO.h -----------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_SafeMachO_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SafeMachO_h_
end_define

begin_comment
comment|// This header file is required to work around collisions between the defines in
end_comment

begin_comment
comment|// mach/machine.h, and enum members
end_comment

begin_comment
comment|// of the same name in llvm's MachO.h.  If you want to use llvm/Support/MachO.h,
end_comment

begin_comment
comment|// use this file instead.
end_comment

begin_comment
comment|// The caveats are:
end_comment

begin_comment
comment|// 1) You can only use the MachO.h enums, you can't use the defines.  That won't
end_comment

begin_comment
comment|// make a difference since the values
end_comment

begin_comment
comment|//    are the same.
end_comment

begin_comment
comment|// 2) If you need any header file that relies on mach/machine.h, you must
end_comment

begin_comment
comment|// include that first.
end_comment

begin_comment
comment|// 3) This isn't a total solution, it doesn't undef every define that MachO.h
end_comment

begin_comment
comment|// has borrowed from various system headers,
end_comment

begin_comment
comment|//    only the ones that come from mach/machine.h because that is the one we
end_comment

begin_comment
comment|//    ended up pulling in from various places.
end_comment

begin_comment
comment|//
end_comment

begin_undef
undef|#
directive|undef
name|CPU_ARCH_MASK
end_undef

begin_undef
undef|#
directive|undef
name|CPU_ARCH_ABI64
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TYPE_ANY
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TYPE_X86
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TYPE_I386
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TYPE_X86_64
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TYPE_MC98000
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TYPE_ARM
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TYPE_ARM64
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TYPE_SPARC
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TYPE_POWERPC
end_undef

begin_undef
undef|#
directive|undef
name|CPU_TYPE_POWERPC64
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUB_TYPE_MASK
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUB_TYPE_LIB64
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_MULTIPLE
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_I386_ALL
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_386
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_486
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_486SX
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_586
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_PENT
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_PENTPRO
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_PENTII_M3
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_PENTII_M5
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_CELERON
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_CELERON_MOBILE
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_PENTIUM_3
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_PENTIUM_3_M
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_PENTIUM_3_XEON
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_PENTIUM_M
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_PENTIUM_4
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_PENTIUM_4_M
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ITANIUM
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ITANIUM_2
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_XEON
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_XEON_MP
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_X86_ALL
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_X86_64_ALL
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_X86_ARCH1
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_X86_64_H
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_INTEL
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_INTEL_FAMILY
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_INTEL_FAMILY_MAX
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_INTEL_MODEL
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_INTEL_MODEL_ALL
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_ALL
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_V4T
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_V6
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_V5
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_V5TEJ
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_XSCALE
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_V7
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_V7S
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_V7K
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_V6M
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_V7M
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM_V7EM
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_ARM64_ALL
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_SPARC_ALL
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_ALL
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_601
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_602
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_603
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_603e
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_603ev
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_604
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_604e
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_620
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_750
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_7400
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_7450
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_POWERPC_970
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_MC980000_ALL
end_undef

begin_undef
undef|#
directive|undef
name|CPU_SUBTYPE_MC98601
end_undef

begin_include
include|#
directive|include
file|"llvm/BinaryFormat/MachO.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_SafeMachO_h_
end_comment

end_unit

