begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MipsMCExpr.h - Mips specific MC expression classes -------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSMCEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSMCEXPR_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCAsmLayout.h"
end_include

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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MipsMCExpr
range|:
name|public
name|MCTargetExpr
block|{
name|public
operator|:
expr|enum
name|MipsExprKind
block|{
name|MEK_None
block|,
name|MEK_CALL_HI16
block|,
name|MEK_CALL_LO16
block|,
name|MEK_DTPREL_HI
block|,
name|MEK_DTPREL_LO
block|,
name|MEK_GOT
block|,
name|MEK_GOTTPREL
block|,
name|MEK_GOT_CALL
block|,
name|MEK_GOT_DISP
block|,
name|MEK_GOT_HI16
block|,
name|MEK_GOT_LO16
block|,
name|MEK_GOT_OFST
block|,
name|MEK_GOT_PAGE
block|,
name|MEK_GPREL
block|,
name|MEK_HI
block|,
name|MEK_HIGHER
block|,
name|MEK_HIGHEST
block|,
name|MEK_LO
block|,
name|MEK_NEG
block|,
name|MEK_PCREL_HI16
block|,
name|MEK_PCREL_LO16
block|,
name|MEK_TLSGD
block|,
name|MEK_TLSLDM
block|,
name|MEK_TPREL_HI
block|,
name|MEK_TPREL_LO
block|,
name|MEK_Special
block|,   }
block|;
name|private
operator|:
specifier|const
name|MipsExprKind
name|Kind
block|;
specifier|const
name|MCExpr
operator|*
name|Expr
block|;
name|explicit
name|MipsMCExpr
argument_list|(
argument|MipsExprKind Kind
argument_list|,
argument|const MCExpr *Expr
argument_list|)
operator|:
name|Kind
argument_list|(
name|Kind
argument_list|)
block|,
name|Expr
argument_list|(
argument|Expr
argument_list|)
block|{}
name|public
operator|:
specifier|static
specifier|const
name|MipsMCExpr
operator|*
name|create
argument_list|(
argument|MipsExprKind Kind
argument_list|,
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
specifier|static
specifier|const
name|MipsMCExpr
operator|*
name|createGpOff
argument_list|(
argument|MipsExprKind Kind
argument_list|,
argument|const MCExpr *Expr
argument_list|,
argument|MCContext&Ctx
argument_list|)
block|;
comment|/// Get the kind of this expression.
name|MipsExprKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
comment|/// Get the child of this expression.
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
argument|MCStreamer&Streamer
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
name|bool
name|isGpOff
argument_list|(
argument|MipsExprKind&Kind
argument_list|)
specifier|const
block|;
name|bool
name|isGpOff
argument_list|()
specifier|const
block|{
name|MipsExprKind
name|Kind
block|;
return|return
name|isGpOff
argument_list|(
name|Kind
argument_list|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_MIPS_MCTARGETDESC_MIPSMCEXPR_H
end_comment

end_unit

