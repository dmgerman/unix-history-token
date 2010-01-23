begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCDirectives.h - Enums for directives on various targets -*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file defines various enums that represent target-specific directives.
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
name|LLVM_MC_MCDIRECTIVES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCDIRECTIVES_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
enum|enum
name|MCSymbolAttr
block|{
name|MCSA_Invalid
init|=
literal|0
block|,
comment|/// Not a valid directive.
comment|// Various directives in alphabetical order.
name|MCSA_Global
block|,
comment|/// .globl
name|MCSA_Hidden
block|,
comment|/// .hidden (ELF)
name|MCSA_IndirectSymbol
block|,
comment|/// .indirect_symbol (MachO)
name|MCSA_Internal
block|,
comment|/// .internal (ELF)
name|MCSA_LazyReference
block|,
comment|/// .lazy_reference (MachO)
name|MCSA_Local
block|,
comment|/// .local (ELF)
name|MCSA_NoDeadStrip
block|,
comment|/// .no_dead_strip (MachO)
name|MCSA_PrivateExtern
block|,
comment|/// .private_extern (MachO)
name|MCSA_Protected
block|,
comment|/// .protected (ELF)
name|MCSA_Reference
block|,
comment|/// .reference (MachO)
name|MCSA_Weak
block|,
comment|/// .weak
name|MCSA_WeakDefinition
block|,
comment|/// .weak_definition (MachO)
name|MCSA_WeakReference
comment|/// .weak_reference (MachO)
block|}
enum|;
enum|enum
name|MCAssemblerFlag
block|{
name|MCAF_SubsectionsViaSymbols
comment|/// .subsections_via_symbols (MachO)
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

