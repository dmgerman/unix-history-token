begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//====- SparcMCExpr.h - Sparc specific MC expression classes --*- C++ -*-=====//
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
comment|// This file describes Sparc-specific MCExprs, used for modifiers like
end_comment

begin_comment
comment|// "%hi" or "%lo" etc.,
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
name|LLVM_SPARCMCEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SPARCMCEXPR_H
end_define

begin_include
include|#
directive|include
file|"SparcFixupKinds.h"
end_include

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
name|StringRef
decl_stmt|;
name|class
name|SparcMCExpr
range|:
name|public
name|MCTargetExpr
block|{
name|public
operator|:
expr|enum
name|VariantKind
block|{
name|VK_Sparc_None
block|,
name|VK_Sparc_LO
block|,
name|VK_Sparc_HI
block|,
name|VK_Sparc_H44
block|,
name|VK_Sparc_M44
block|,
name|VK_Sparc_L44
block|,
name|VK_Sparc_HH
block|,
name|VK_Sparc_HM
block|,
name|VK_Sparc_PC22
block|,
name|VK_Sparc_PC10
block|,
name|VK_Sparc_GOT22
block|,
name|VK_Sparc_GOT10
block|,
name|VK_Sparc_WPLT30
block|,
name|VK_Sparc_R_DISP32
block|,
name|VK_Sparc_TLS_GD_HI22
block|,
name|VK_Sparc_TLS_GD_LO10
block|,
name|VK_Sparc_TLS_GD_ADD
block|,
name|VK_Sparc_TLS_GD_CALL
block|,
name|VK_Sparc_TLS_LDM_HI22
block|,
name|VK_Sparc_TLS_LDM_LO10
block|,
name|VK_Sparc_TLS_LDM_ADD
block|,
name|VK_Sparc_TLS_LDM_CALL
block|,
name|VK_Sparc_TLS_LDO_HIX22
block|,
name|VK_Sparc_TLS_LDO_LOX10
block|,
name|VK_Sparc_TLS_LDO_ADD
block|,
name|VK_Sparc_TLS_IE_HI22
block|,
name|VK_Sparc_TLS_IE_LO10
block|,
name|VK_Sparc_TLS_IE_LD
block|,
name|VK_Sparc_TLS_IE_LDX
block|,
name|VK_Sparc_TLS_IE_ADD
block|,
name|VK_Sparc_TLS_LE_HIX22
block|,
name|VK_Sparc_TLS_LE_LOX10
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
name|SparcMCExpr
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
name|SparcMCExpr
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
comment|/// getFixupKind - Get the fixup kind of this expression.
name|Sparc
operator|::
name|Fixups
name|getFixupKind
argument_list|()
specifier|const
block|{
return|return
name|getFixupKind
argument_list|(
name|Kind
argument_list|)
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
argument|const SparcMCExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
name|VariantKind
name|parseVariantKind
argument_list|(
argument|StringRef name
argument_list|)
block|;
specifier|static
name|bool
name|printVariantKind
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|VariantKind Kind
argument_list|)
block|;
specifier|static
name|Sparc
operator|::
name|Fixups
name|getFixupKind
argument_list|(
argument|VariantKind Kind
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

