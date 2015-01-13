begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMMCExpr.h - ARM specific MC expression classes --------*- C++ -*-===//
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
name|ARMMCEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|ARMMCEXPR_H
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
name|class
name|ARMMCExpr
range|:
name|public
name|MCTargetExpr
block|{
name|public
operator|:
expr|enum
name|VariantKind
block|{
name|VK_ARM_None
block|,
name|VK_ARM_HI16
block|,
comment|// The R_ARM_MOVT_ABS relocation (:upper16: in the .s file)
name|VK_ARM_LO16
comment|// The R_ARM_MOVW_ABS_NC relocation (:lower16: in the .s file)
block|}
block|;
name|private
operator|:
specifier|const
name|VariantKind
name|Kind
block|;
specifier|const
name|MCExpr
operator|*
name|Expr
block|;
name|explicit
name|ARMMCExpr
argument_list|(
argument|VariantKind _Kind
argument_list|,
argument|const MCExpr *_Expr
argument_list|)
operator|:
name|Kind
argument_list|(
name|_Kind
argument_list|)
block|,
name|Expr
argument_list|(
argument|_Expr
argument_list|)
block|{}
name|public
operator|:
comment|/// @name Construction
comment|/// @{
specifier|static
specifier|const
name|ARMMCExpr
operator|*
name|Create
argument_list|(
argument|VariantKind Kind
argument_list|,
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
specifier|static
specifier|const
name|ARMMCExpr
operator|*
name|CreateUpper16
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_ARM_HI16
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|ARMMCExpr
operator|*
name|CreateLower16
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_ARM_LO16
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
comment|/// @}
comment|/// @name Accessors
comment|/// @{
comment|/// getOpcode - Get the kind of this expression.
name|VariantKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// getSubExpr - Get the child of this expression.
specifier|const
name|MCExpr
operator|*
name|getSubExpr
argument_list|()
specifier|const
block|{
return|return
name|Expr
return|;
block|}
comment|/// @}
name|void
name|PrintImpl
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|;
name|bool
name|EvaluateAsRelocatableImpl
argument_list|(
argument|MCValue&Res
argument_list|,
argument|const MCAsmLayout *Layout
argument_list|)
specifier|const
name|override
block|;
name|void
name|visitUsedExpr
argument_list|(
argument|MCStreamer&Streamer
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|MCSection
operator|*
name|FindAssociatedSection
argument_list|()
specifier|const
name|override
block|{
return|return
name|getSubExpr
argument_list|()
operator|->
name|FindAssociatedSection
argument_list|()
return|;
block|}
comment|// There are no TLS ARMMCExprs at the moment.
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
expr|}
block|; }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

