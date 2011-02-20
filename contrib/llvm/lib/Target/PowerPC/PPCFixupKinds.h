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
name|LLVM_PPC_PPCFIXUPKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_PPC_PPCFIXUPKINDS_H
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
name|PPC
block|{
enum|enum
name|Fixups
block|{
comment|// fixup_ppc_br24 - 24-bit PC relative relocation for direct branches like 'b'
comment|// and 'bl'.
name|fixup_ppc_br24
init|=
name|FirstTargetFixupKind
block|,
comment|/// fixup_ppc_brcond14 - 14-bit PC relative relocation for conditional
comment|/// branches.
name|fixup_ppc_brcond14
block|,
comment|/// fixup_ppc_lo16 - A 16-bit fixup corresponding to lo16(_foo) for instrs
comment|/// like 'li'.
name|fixup_ppc_lo16
block|,
comment|/// fixup_ppc_ha16 - A 16-bit fixup corresponding to ha16(_foo) for instrs
comment|/// like 'lis'.
name|fixup_ppc_ha16
block|,
comment|/// fixup_ppc_lo14 - A 14-bit fixup corresponding to lo16(_foo) for instrs
comment|/// like 'std'.
name|fixup_ppc_lo14
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

