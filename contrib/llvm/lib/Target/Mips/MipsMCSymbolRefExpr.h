begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MipsMCSymbolRefExpr.h - Mips specific MCSymbolRefExpr class -------===//
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
name|MIPSMCSYMBOLREFEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|MIPSMCSYMBOLREFEXPR_H
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
name|MipsMCSymbolRefExpr
range|:
name|public
name|MCTargetExpr
block|{
name|public
operator|:
expr|enum
name|VariantKind
block|{
name|VK_Mips_None
block|,
name|VK_Mips_GPREL
block|,
name|VK_Mips_GOT_CALL
block|,
name|VK_Mips_GOT
block|,
name|VK_Mips_ABS_HI
block|,
name|VK_Mips_ABS_LO
block|,
name|VK_Mips_TLSGD
block|,
name|VK_Mips_GOTTPREL
block|,
name|VK_Mips_TPREL_HI
block|,
name|VK_Mips_TPREL_LO
block|,
name|VK_Mips_GPOFF_HI
block|,
name|VK_Mips_GPOFF_LO
block|,
name|VK_Mips_GOT_DISP
block|,
name|VK_Mips_GOT_PAGE
block|,
name|VK_Mips_GOT_OFST
block|}
block|;
name|private
operator|:
specifier|const
name|VariantKind
name|Kind
block|;
specifier|const
name|MCSymbol
operator|*
name|Symbol
block|;
name|int
name|Offset
block|;
name|explicit
name|MipsMCSymbolRefExpr
argument_list|(
argument|VariantKind _Kind
argument_list|,
argument|const MCSymbol *_Symbol
argument_list|,
argument|int _Offset
argument_list|)
operator|:
name|Kind
argument_list|(
name|_Kind
argument_list|)
block|,
name|Symbol
argument_list|(
name|_Symbol
argument_list|)
block|,
name|Offset
argument_list|(
argument|_Offset
argument_list|)
block|{}
name|public
operator|:
specifier|static
specifier|const
name|MipsMCSymbolRefExpr
operator|*
name|Create
argument_list|(
argument|VariantKind Kind
argument_list|,
argument|const MCSymbol *Symbol
argument_list|,
argument|int Offset
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
argument|const MipsMCSymbolRefExpr *
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|int
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|void
name|setOffset
argument_list|(
argument|int O
argument_list|)
block|{
name|Offset
operator|=
name|O
block|; }
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

