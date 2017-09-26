begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCFixupKinds.h - PPC Specific Fixup Entries ------------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_POWERPC_MCTARGETDESC_PPCFIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_POWERPC_MCTARGETDESC_PPCFIXUPKINDS_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCFixup.h"
end_include

begin_undef
undef|#
directive|undef
name|PPC
end_undef

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|PPC
block|{
enum|enum
name|Fixups
block|{
comment|// 24-bit PC relative relocation for direct branches like 'b' and 'bl'.
name|fixup_ppc_br24
init|=
name|FirstTargetFixupKind
block|,
comment|/// 14-bit PC relative relocation for conditional branches.
name|fixup_ppc_brcond14
block|,
comment|/// 24-bit absolute relocation for direct branches like 'ba' and 'bla'.
name|fixup_ppc_br24abs
block|,
comment|/// 14-bit absolute relocation for conditional branches.
name|fixup_ppc_brcond14abs
block|,
comment|/// A 16-bit fixup corresponding to lo16(_foo) or ha16(_foo) for instrs like
comment|/// 'li' or 'addis'.
name|fixup_ppc_half16
block|,
comment|/// A 14-bit fixup corresponding to lo16(_foo) with implied 2 zero bits for
comment|/// instrs like 'std'.
name|fixup_ppc_half16ds
block|,
comment|/// Not a true fixup, but ties a symbol to a call to __tls_get_addr for the
comment|/// TLS general and local dynamic models, or inserts the thread-pointer
comment|/// register number.
name|fixup_ppc_nofixup
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

