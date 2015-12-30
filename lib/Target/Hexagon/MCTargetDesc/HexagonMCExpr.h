begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- HexagonMCExpr.h - Hexagon specific MC expression classes --*- C++ -*-===//
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
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONMCEXPR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_HEXAGON_HEXAGONMCEXPR_H
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
name|MCInst
decl_stmt|;
name|class
name|HexagonNoExtendOperand
range|:
name|public
name|MCTargetExpr
block|{
name|public
operator|:
specifier|static
name|HexagonNoExtendOperand
operator|*
name|Create
argument_list|(
name|MCExpr
specifier|const
operator|*
name|Expr
argument_list|,
name|MCContext
operator|&
name|Ctx
argument_list|)
block|;
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
block|;
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
name|MCExpr
specifier|const
operator|*
name|E
argument_list|)
block|;
name|MCExpr
specifier|const
operator|*
name|getExpr
argument_list|()
specifier|const
block|;
name|private
operator|:
name|HexagonNoExtendOperand
argument_list|(
name|MCExpr
specifier|const
operator|*
name|Expr
argument_list|)
block|;
name|MCExpr
specifier|const
operator|*
name|Expr
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

begin_comment
comment|// LLVM_LIB_TARGET_HEXAGON_HEXAGONMCEXPR_H
end_comment

end_unit

