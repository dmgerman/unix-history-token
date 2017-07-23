begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NVPTXMCExpr.h - NVPTX specific MC expression classes ----*- C++ -*-===//
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
comment|// Modeled after ARMMCExpr
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_NVPTX_NVPTXMCEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_NVPTX_NVPTXMCEXPR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APFloat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|NVPTXFloatMCExpr
range|:
name|public
name|MCTargetExpr
block|{
name|public
operator|:
expr|enum
name|VariantKind
block|{
name|VK_NVPTX_None
block|,
name|VK_NVPTX_HALF_PREC_FLOAT
block|,
comment|// FP constant in half-precision
name|VK_NVPTX_SINGLE_PREC_FLOAT
block|,
comment|// FP constant in single-precision
name|VK_NVPTX_DOUBLE_PREC_FLOAT
comment|// FP constant in double-precision
block|}
block|;
name|private
operator|:
specifier|const
name|VariantKind
name|Kind
block|;
specifier|const
name|APFloat
name|Flt
block|;
name|explicit
name|NVPTXFloatMCExpr
argument_list|(
argument|VariantKind Kind
argument_list|,
argument|APFloat Flt
argument_list|)
operator|:
name|Kind
argument_list|(
name|Kind
argument_list|)
block|,
name|Flt
argument_list|(
argument|std::move(Flt)
argument_list|)
block|{}
name|public
operator|:
comment|/// @name Construction
comment|/// @{
specifier|static
specifier|const
name|NVPTXFloatMCExpr
operator|*
name|create
argument_list|(
argument|VariantKind Kind
argument_list|,
argument|const APFloat&Flt
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
specifier|static
specifier|const
name|NVPTXFloatMCExpr
operator|*
name|createConstantFPHalf
argument_list|(
argument|const APFloat&Flt
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|VK_NVPTX_HALF_PREC_FLOAT
argument_list|,
name|Flt
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|NVPTXFloatMCExpr
operator|*
name|createConstantFPSingle
argument_list|(
argument|const APFloat&Flt
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|VK_NVPTX_SINGLE_PREC_FLOAT
argument_list|,
name|Flt
argument_list|,
name|Ctx
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|NVPTXFloatMCExpr
operator|*
name|createConstantFPDouble
argument_list|(
argument|const APFloat&Flt
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|{
return|return
name|create
argument_list|(
name|VK_NVPTX_DOUBLE_PREC_FLOAT
argument_list|,
name|Flt
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
name|APFloat
name|getAPFloat
argument_list|()
specifier|const
block|{
return|return
name|Flt
return|;
block|}
comment|/// @}
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
block|{
return|return
name|false
return|;
block|}
name|void
name|visitUsedExpr
argument_list|(
argument|MCStreamer&Streamer
argument_list|)
specifier|const
name|override
block|{}
block|;
name|MCFragment
operator|*
name|findAssociatedFragment
argument_list|()
specifier|const
name|override
block|{
return|return
name|nullptr
return|;
block|}
comment|// There are no TLS NVPTXMCExprs at the moment.
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
block|;
comment|/// A wrapper for MCSymbolRefExpr that tells the assembly printer that the
comment|/// symbol should be enclosed by generic().
name|class
name|NVPTXGenericMCSymbolRefExpr
operator|:
name|public
name|MCTargetExpr
block|{
name|private
operator|:
specifier|const
name|MCSymbolRefExpr
operator|*
name|SymExpr
block|;
name|explicit
name|NVPTXGenericMCSymbolRefExpr
argument_list|(
specifier|const
name|MCSymbolRefExpr
operator|*
name|_SymExpr
argument_list|)
operator|:
name|SymExpr
argument_list|(
argument|_SymExpr
argument_list|)
block|{}
name|public
operator|:
comment|/// @name Construction
comment|/// @{
specifier|static
specifier|const
name|NVPTXGenericMCSymbolRefExpr
operator|*
name|create
argument_list|(
specifier|const
name|MCSymbolRefExpr
operator|*
name|SymExpr
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|)
block|;
comment|/// @}
comment|/// @name Accessors
comment|/// @{
comment|/// getOpcode - Get the kind of this expression.
specifier|const
name|MCSymbolRefExpr
operator|*
name|getSymbolExpr
argument_list|()
specifier|const
block|{
return|return
name|SymExpr
return|;
block|}
comment|/// @}
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
block|{
return|return
name|false
return|;
block|}
name|void
name|visitUsedExpr
argument_list|(
argument|MCStreamer&Streamer
argument_list|)
specifier|const
name|override
block|{}
block|;
name|MCFragment
operator|*
name|findAssociatedFragment
argument_list|()
specifier|const
name|override
block|{
return|return
name|nullptr
return|;
block|}
comment|// There are no TLS NVPTXMCExprs at the moment.
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

