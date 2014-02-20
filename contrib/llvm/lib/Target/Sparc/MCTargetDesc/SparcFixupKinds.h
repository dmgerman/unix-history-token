begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SparcFixupKinds.h - Sparc Specific Fixup Entries --------*- C++ -*-===//
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
name|LLVM_SPARC_FIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SPARC_FIXUPKINDS_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCFixup.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|Sparc
block|{
enum|enum
name|Fixups
block|{
comment|// fixup_sparc_call30 - 30-bit PC relative relocation for call
name|fixup_sparc_call30
init|=
name|FirstTargetFixupKind
block|,
comment|/// fixup_sparc_br22 - 22-bit PC relative relocation for
comment|/// branches
name|fixup_sparc_br22
block|,
comment|/// fixup_sparc_br19 - 19-bit PC relative relocation for
comment|/// branches on icc/xcc
name|fixup_sparc_br19
block|,
comment|/// fixup_sparc_hi22  - 22-bit fixup corresponding to %hi(foo)
comment|/// for sethi
name|fixup_sparc_hi22
block|,
comment|/// fixup_sparc_lo10  - 10-bit fixup corresponding to %lo(foo)
name|fixup_sparc_lo10
block|,
comment|/// fixup_sparc_h44  - 22-bit fixup corresponding to %h44(foo)
name|fixup_sparc_h44
block|,
comment|/// fixup_sparc_m44  - 10-bit fixup corresponding to %m44(foo)
name|fixup_sparc_m44
block|,
comment|/// fixup_sparc_l44  - 12-bit fixup corresponding to %l44(foo)
name|fixup_sparc_l44
block|,
comment|/// fixup_sparc_hh  -  22-bit fixup corresponding to %hh(foo)
name|fixup_sparc_hh
block|,
comment|/// fixup_sparc_hm  -  10-bit fixup corresponding to %hm(foo)
name|fixup_sparc_hm
block|,
comment|/// fixup_sparc_pc22 - 22-bit fixup corresponding to %pc22(foo)
name|fixup_sparc_pc22
block|,
comment|/// fixup_sparc_pc10 - 10-bit fixup corresponding to %pc10(foo)
name|fixup_sparc_pc10
block|,
comment|/// fixup_sparc_got22 - 22-bit fixup corresponding to %got22(foo)
name|fixup_sparc_got22
block|,
comment|/// fixup_sparc_got10 - 10-bit fixup corresponding to %got10(foo)
name|fixup_sparc_got10
block|,
comment|/// fixup_sparc_wplt30
name|fixup_sparc_wplt30
block|,
comment|/// fixups for Thread Local Storage
name|fixup_sparc_tls_gd_hi22
block|,
name|fixup_sparc_tls_gd_lo10
block|,
name|fixup_sparc_tls_gd_add
block|,
name|fixup_sparc_tls_gd_call
block|,
name|fixup_sparc_tls_ldm_hi22
block|,
name|fixup_sparc_tls_ldm_lo10
block|,
name|fixup_sparc_tls_ldm_add
block|,
name|fixup_sparc_tls_ldm_call
block|,
name|fixup_sparc_tls_ldo_hix22
block|,
name|fixup_sparc_tls_ldo_lox10
block|,
name|fixup_sparc_tls_ldo_add
block|,
name|fixup_sparc_tls_ie_hi22
block|,
name|fixup_sparc_tls_ie_lo10
block|,
name|fixup_sparc_tls_ie_ld
block|,
name|fixup_sparc_tls_ie_ldx
block|,
name|fixup_sparc_tls_ie_add
block|,
name|fixup_sparc_tls_le_hix22
block|,
name|fixup_sparc_tls_le_lox10
block|,
comment|// Marker
name|LastTargetFixupKind
block|,
name|NumTargetFixupKinds
init|=
name|LastTargetFixupKind
operator|-
name|FirstTargetFixupKind
block|}
enum|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

