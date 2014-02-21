begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- PPCMCExpr.h - PPC specific MC expression classes --------*- C++ -*-===//
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
name|PPCMCEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|PPCMCEXPR_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmLayout.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|PPCMCExpr
range|:
name|public
name|MCTargetExpr
block|{
name|public
operator|:
expr|enum
name|VariantKind
block|{
name|VK_PPC_None
block|,
name|VK_PPC_LO
block|,
name|VK_PPC_HI
block|,
name|VK_PPC_HA
block|,
name|VK_PPC_HIGHER
block|,
name|VK_PPC_HIGHERA
block|,
name|VK_PPC_HIGHEST
block|,
name|VK_PPC_HIGHESTA
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
name|bool
name|IsDarwin
block|;
name|explicit
name|PPCMCExpr
argument_list|(
argument|VariantKind _Kind
argument_list|,
argument|const MCExpr *_Expr
argument_list|,
argument|bool _IsDarwin
argument_list|)
operator|:
name|Kind
argument_list|(
name|_Kind
argument_list|)
block|,
name|Expr
argument_list|(
name|_Expr
argument_list|)
block|,
name|IsDarwin
argument_list|(
argument|_IsDarwin
argument_list|)
block|{}
name|public
operator|:
comment|/// @name Construction
comment|/// @{
specifier|static
specifier|const
name|PPCMCExpr
operator|*
name|Create
argument_list|(
argument|VariantKind Kind
argument_list|,
argument|const MCExpr *Expr
argument_list|,
argument|bool isDarwin
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
specifier|static
specifier|const
name|PPCMCExpr
operator|*
name|CreateLo
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|bool isDarwin
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_PPC_LO
argument_list|,
name|Expr
argument_list|,
name|isDarwin
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|PPCMCExpr
operator|*
name|CreateHi
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|bool isDarwin
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_PPC_HI
argument_list|,
name|Expr
argument_list|,
name|isDarwin
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|PPCMCExpr
operator|*
name|CreateHa
argument_list|(
argument|const MCExpr *Expr
argument_list|,
argument|bool isDarwin
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|Create
argument_list|(
name|VK_PPC_HA
argument_list|,
name|Expr
argument_list|,
name|isDarwin
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
comment|/// isDarwinSyntax - True if expression is to be printed using Darwin syntax.
name|bool
name|isDarwinSyntax
argument_list|()
specifier|const
block|{
return|return
name|IsDarwin
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
comment|// There are no TLS PPCMCExprs at the moment.
name|void
name|fixELFSymbolsInTLSFixups
argument_list|(
argument|MCAssembler&Asm
argument_list|)
specifier|const
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

