begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AVRMCExpr.h - AVR specific MC expression classes --------*- C++ -*-===//
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
name|LLVM_AVR_MCEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AVR_MCEXPR_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_include
include|#
directive|include
file|"MCTargetDesc/AVRFixupKinds.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// A expression in AVR machine code.
name|class
name|AVRMCExpr
range|:
name|public
name|MCTargetExpr
block|{
name|public
operator|:
comment|/// Specifies the type of an expression.
expr|enum
name|VariantKind
block|{
name|VK_AVR_None
block|,
name|VK_AVR_HI8
block|,
comment|///< Corresponds to `hi8()`.
name|VK_AVR_LO8
block|,
comment|///< Corresponds to `lo8()`.
name|VK_AVR_HH8
block|,
comment|///< Corresponds to `hlo8() and hh8()`.
name|VK_AVR_HHI8
block|,
comment|///< Corresponds to `hhi8()`.
name|VK_AVR_PM_LO8
block|,
comment|///< Corresponds to `pm_lo8()`.
name|VK_AVR_PM_HI8
block|,
comment|///< Corresponds to `pm_hi8()`.
name|VK_AVR_PM_HH8
comment|///< Corresponds to `pm_hh8()`.
block|}
block|;
name|public
operator|:
comment|/// Creates an AVR machine code expression.
specifier|static
specifier|const
name|AVRMCExpr
operator|*
name|create
argument_list|(
argument|VariantKind Kind
argument_list|,
argument|const MCExpr *Expr
argument_list|,
argument|bool isNegated
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
comment|/// Gets the type of the expression.
name|VariantKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// Gets the name of the expression.
specifier|const
name|char
operator|*
name|getName
argument_list|()
specifier|const
block|;
specifier|const
name|MCExpr
operator|*
name|getSubExpr
argument_list|()
specifier|const
block|{
return|return
name|SubExpr
return|;
block|}
comment|/// Gets the fixup which corresponds to the expression.
name|AVR
operator|::
name|Fixups
name|getFixupKind
argument_list|()
specifier|const
block|;
comment|/// Evaluates the fixup as a constant value.
name|bool
name|evaluateAsConstant
argument_list|(
argument|int64_t&Result
argument_list|)
specifier|const
block|;
name|bool
name|isNegated
argument_list|()
specifier|const
block|{
return|return
name|Negated
return|;
block|}
name|void
name|setNegated
argument_list|(
argument|bool negated = true
argument_list|)
block|{
name|Negated
operator|=
name|negated
block|; }
name|void
name|printImpl
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const MCAsmInfo *MAI
argument_list|)
specifier|const
name|override
block|;
name|bool
name|evaluateAsRelocatableImpl
argument_list|(
argument|MCValue&Res
argument_list|,
argument|const MCAsmLayout *Layout
argument_list|,
argument|const MCFixup *Fixup
argument_list|)
specifier|const
name|override
block|;
name|void
name|visitUsedExpr
argument_list|(
argument|MCStreamer&streamer
argument_list|)
specifier|const
name|override
block|;
name|MCFragment
operator|*
name|findAssociatedFragment
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubExpr
argument_list|()
operator|->
name|findAssociatedFragment
argument_list|()
return|;
block|}
name|void
name|fixELFSymbolsInTLSFixups
argument_list|(
argument|MCAssembler&Asm
argument_list|)
specifier|const
name|override
block|{}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MCExpr *E
argument_list|)
block|{
return|return
name|E
operator|->
name|getKind
argument_list|()
operator|==
name|MCExpr
operator|::
name|Target
return|;
block|}
name|public
operator|:
specifier|static
name|VariantKind
name|getKindByName
argument_list|(
argument|StringRef Name
argument_list|)
block|;
name|private
operator|:
name|int64_t
name|evaluateAsInt64
argument_list|(
argument|int64_t Value
argument_list|)
specifier|const
block|;
specifier|const
name|VariantKind
name|Kind
block|;
specifier|const
name|MCExpr
operator|*
name|SubExpr
block|;
name|bool
name|Negated
block|;
name|private
operator|:
name|explicit
name|AVRMCExpr
argument_list|(
argument|VariantKind Kind
argument_list|,
argument|const MCExpr *Expr
argument_list|,
argument|bool Negated
argument_list|)
operator|:
name|Kind
argument_list|(
name|Kind
argument_list|)
block|,
name|SubExpr
argument_list|(
name|Expr
argument_list|)
block|,
name|Negated
argument_list|(
argument|Negated
argument_list|)
block|{}
operator|~
name|AVRMCExpr
argument_list|()
block|{}
block|}
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

begin_comment
comment|// LLVM_AVR_MCEXPR_H
end_comment

end_unit

