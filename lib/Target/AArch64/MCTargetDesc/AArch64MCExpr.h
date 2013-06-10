begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- AArch64MCExpr.h - AArch64 specific MC expression classes --*- C++ -*-===//
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
comment|// This file describes AArch64-specific MCExprs, used for modifiers like
end_comment

begin_comment
comment|// ":lo12:" or ":gottprel_g1:".
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
name|LLVM_AARCH64MCEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_AARCH64MCEXPR_H
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
name|AArch64MCExpr
range|:
name|public
name|MCTargetExpr
block|{
name|public
operator|:
expr|enum
name|VariantKind
block|{
name|VK_AARCH64_None
block|,
name|VK_AARCH64_GOT
block|,
comment|// :got: modifier in assembly
name|VK_AARCH64_GOT_LO12
block|,
comment|// :got_lo12:
name|VK_AARCH64_LO12
block|,
comment|// :lo12:
name|VK_AARCH64_ABS_G0
block|,
comment|// :abs_g0:
name|VK_AARCH64_ABS_G0_NC
block|,
comment|// :abs_g0_nc:
name|VK_AARCH64_ABS_G1
block|,
name|VK_AARCH64_ABS_G1_NC
block|,
name|VK_AARCH64_ABS_G2
block|,
name|VK_AARCH64_ABS_G2_NC
block|,
name|VK_AARCH64_ABS_G3
block|,
name|VK_AARCH64_SABS_G0
block|,
comment|// :abs_g0_s:
name|VK_AARCH64_SABS_G1
block|,
name|VK_AARCH64_SABS_G2
block|,
name|VK_AARCH64_DTPREL_G2
block|,
comment|// :dtprel_g2:
name|VK_AARCH64_DTPREL_G1
block|,
name|VK_AARCH64_DTPREL_G1_NC
block|,
name|VK_AARCH64_DTPREL_G0
block|,
name|VK_AARCH64_DTPREL_G0_NC
block|,
name|VK_AARCH64_DTPREL_HI12
block|,
name|VK_AARCH64_DTPREL_LO12
block|,
name|VK_AARCH64_DTPREL_LO12_NC
block|,
name|VK_AARCH64_GOTTPREL_G1
block|,
comment|// :gottprel:
name|VK_AARCH64_GOTTPREL_G0_NC
block|,
name|VK_AARCH64_GOTTPREL
block|,
name|VK_AARCH64_GOTTPREL_LO12
block|,
name|VK_AARCH64_TPREL_G2
block|,
comment|// :tprel:
name|VK_AARCH64_TPREL_G1
block|,
name|VK_AARCH64_TPREL_G1_NC
block|,
name|VK_AARCH64_TPREL_G0
block|,
name|VK_AARCH64_TPREL_G0_NC
block|,
name|VK_AARCH64_TPREL_HI12
block|,
name|VK_AARCH64_TPREL_LO12
block|,
name|VK_AARCH64_TPREL_LO12_NC
block|,
name|VK_AARCH64_TLSDESC
block|,
comment|// :tlsdesc:
name|VK_AARCH64_TLSDESC_LO12
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
name|AArch64MCExpr
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
name|AArch64MCExpr
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
name|AArch64MCExpr
operator|*
name|CreateLo12
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_LO12
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateGOT
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_GOT
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateGOTLo12
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_GOT_LO12
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateDTPREL_G1
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_DTPREL_G1
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateDTPREL_G0_NC
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_DTPREL_G0_NC
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateGOTTPREL
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_GOTTPREL
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateGOTTPRELLo12
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_GOTTPREL_LO12
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateTLSDesc
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_TLSDESC
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateTLSDescLo12
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_TLSDESC_LO12
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateTPREL_G1
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_TPREL_G1
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateTPREL_G0_NC
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_TPREL_G0_NC
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateABS_G3
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_ABS_G3
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateABS_G2_NC
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_ABS_G2_NC
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateABS_G1_NC
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_ABS_G1_NC
argument_list|,
name|Expr
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|AArch64MCExpr
operator|*
name|CreateABS_G0_NC
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_AARCH64_ABS_G0_NC
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
block|;
name|bool
name|EvaluateAsRelocatableImpl
argument_list|(
argument|MCValue&Res
argument_list|,
argument|const MCAsmLayout *Layout
argument_list|)
specifier|const
block|;
name|void
name|AddValueSymbols
argument_list|(
argument|MCAssembler *
argument_list|)
specifier|const
block|;
specifier|const
name|MCSection
operator|*
name|FindAssociatedSection
argument_list|()
specifier|const
block|{
return|return
name|getSubExpr
argument_list|()
operator|->
name|FindAssociatedSection
argument_list|()
return|;
block|}
name|void
name|fixELFSymbolsInTLSFixups
argument_list|(
argument|MCAssembler&Asm
argument_list|)
specifier|const
block|;
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
specifier|static
name|bool
name|classof
argument_list|(
argument|const AArch64MCExpr *
argument_list|)
block|{
return|return
name|true
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

