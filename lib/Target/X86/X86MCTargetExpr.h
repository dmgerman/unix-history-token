begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86MCTargetExpr.h - X86 Target Specific MCExpr -----------*- C++ -*-===//
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
name|X86_MCTARGETEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|X86_MCTARGETEXPR_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// X86MCTargetExpr - This class represents symbol variants, like foo@GOT.
name|class
name|X86MCTargetExpr
range|:
name|public
name|MCTargetExpr
block|{
name|public
operator|:
expr|enum
name|VariantKind
block|{
name|Invalid
block|,
name|GOT
block|,
name|GOTOFF
block|,
name|GOTPCREL
block|,
name|GOTTPOFF
block|,
name|INDNTPOFF
block|,
name|NTPOFF
block|,
name|PLT
block|,
name|TLSGD
block|,
name|TPOFF
block|}
block|;
name|private
operator|:
comment|/// Sym - The symbol being referenced.
specifier|const
name|MCSymbol
operator|*
specifier|const
name|Sym
block|;
comment|/// Kind - The modifier.
specifier|const
name|VariantKind
name|Kind
block|;
name|X86MCTargetExpr
argument_list|(
argument|const MCSymbol *S
argument_list|,
argument|VariantKind K
argument_list|)
operator|:
name|Sym
argument_list|(
name|S
argument_list|)
block|,
name|Kind
argument_list|(
argument|K
argument_list|)
block|{}
name|public
operator|:
specifier|static
name|X86MCTargetExpr
operator|*
name|Create
argument_list|(
argument|const MCSymbol *Sym
argument_list|,
argument|VariantKind K
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
name|void
name|PrintImpl
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
name|bool
name|EvaluateAsRelocatableImpl
argument_list|(
argument|MCValue&Res
argument_list|)
specifier|const
block|; }
decl_stmt|;
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

