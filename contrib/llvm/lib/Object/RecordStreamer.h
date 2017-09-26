begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RecordStreamer.h - Record asm defined and used symbols ---*- C++ -*-===//
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
name|LLVM_LIB_OBJECT_RECORDSTREAMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_OBJECT_RECORDSTREAMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCDirectives.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SMLoc.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|RecordStreamer
range|:
name|public
name|MCStreamer
block|{
name|public
operator|:
expr|enum
name|State
block|{
name|NeverSeen
block|,
name|Global
block|,
name|Defined
block|,
name|DefinedGlobal
block|,
name|DefinedWeak
block|,
name|Used
block|,
name|UndefinedWeak
block|}
block|;
name|private
operator|:
name|StringMap
operator|<
name|State
operator|>
name|Symbols
block|;
comment|// Map of aliases created by .symver directives, saved so we can update
comment|// their symbol binding after parsing complete. This maps from each
comment|// aliasee to its list of aliases.
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
block|,
name|std
operator|::
name|vector
operator|<
name|MCSymbol
operator|*
operator|>>
name|SymverAliasMap
block|;
name|void
name|markDefined
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|Symbol
argument_list|)
block|;
name|void
name|markGlobal
argument_list|(
argument|const MCSymbol&Symbol
argument_list|,
argument|MCSymbolAttr Attribute
argument_list|)
block|;
name|void
name|markUsed
argument_list|(
specifier|const
name|MCSymbol
operator|&
name|Symbol
argument_list|)
block|;
name|void
name|visitUsedSymbol
argument_list|(
argument|const MCSymbol&Sym
argument_list|)
name|override
block|;
name|public
operator|:
name|RecordStreamer
argument_list|(
name|MCContext
operator|&
name|Context
argument_list|)
block|;
name|using
name|const_iterator
operator|=
name|StringMap
operator|<
name|State
operator|>
operator|::
name|const_iterator
block|;
name|const_iterator
name|begin
argument_list|()
block|;
name|const_iterator
name|end
argument_list|()
block|;
name|void
name|EmitInstruction
argument_list|(
argument|const MCInst&Inst
argument_list|,
argument|const MCSubtargetInfo&STI
argument_list|,
argument|bool
argument_list|)
name|override
block|;
name|void
name|EmitLabel
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|SMLoc Loc = SMLoc()
argument_list|)
name|override
block|;
name|void
name|EmitAssignment
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|const MCExpr *Value
argument_list|)
name|override
block|;
name|bool
name|EmitSymbolAttribute
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|MCSymbolAttr Attribute
argument_list|)
name|override
block|;
name|void
name|EmitZerofill
argument_list|(
argument|MCSection *Section
argument_list|,
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment
argument_list|)
name|override
block|;
name|void
name|EmitCommonSymbol
argument_list|(
argument|MCSymbol *Symbol
argument_list|,
argument|uint64_t Size
argument_list|,
argument|unsigned ByteAlignment
argument_list|)
name|override
block|;
comment|/// Record .symver aliases for later processing.
name|void
name|emitELFSymverDirective
argument_list|(
argument|MCSymbol *Alias
argument_list|,
argument|const MCSymbol *Aliasee
argument_list|)
name|override
block|;
comment|/// Return the map of .symver aliasee to associated aliases.
name|DenseMap
operator|<
specifier|const
name|MCSymbol
operator|*
block|,
name|std
operator|::
name|vector
operator|<
name|MCSymbol
operator|*
operator|>>
operator|&
name|symverAliases
argument_list|()
block|{
return|return
name|SymverAliasMap
return|;
block|}
comment|/// Get the state recorded for the given symbol.
name|State
name|getSymbolState
argument_list|(
argument|const MCSymbol *Sym
argument_list|)
block|{
name|auto
name|SI
operator|=
name|Symbols
operator|.
name|find
argument_list|(
name|Sym
operator|->
name|getName
argument_list|()
argument_list|)
block|;
if|if
condition|(
name|SI
operator|==
name|Symbols
operator|.
name|end
argument_list|()
condition|)
return|return
name|NeverSeen
return|;
return|return
name|SI
operator|->
name|second
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_OBJECT_RECORDSTREAMER_H
end_comment

end_unit

