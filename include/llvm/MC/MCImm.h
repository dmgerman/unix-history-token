begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCImm.h - MCImm class ---------------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCInst and MCOperand classes, which
end_comment

begin_comment
comment|// is the basic representation used to represent low-level machine code
end_comment

begin_comment
comment|// instructions.
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
name|LLVM_MC_MCIMM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCIMM_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSymbol
decl_stmt|;
comment|/// MCImm - This represents an "assembler immediate".  In its most general form,
comment|/// this can hold "SymbolA - SymbolB + imm64".  Not all targets supports
comment|/// relocations of this general form, but we need to represent this anyway.
name|class
name|MCImm
block|{
name|MCSymbol
modifier|*
name|SymA
decl_stmt|,
modifier|*
name|SymB
decl_stmt|;
name|int64_t
name|Cst
decl_stmt|;
name|public
label|:
name|int64_t
name|getCst
argument_list|()
specifier|const
block|{
return|return
name|Cst
return|;
block|}
name|MCSymbol
operator|*
name|getSymA
argument_list|()
specifier|const
block|{
return|return
name|SymA
return|;
block|}
name|MCSymbol
operator|*
name|getSymB
argument_list|()
specifier|const
block|{
return|return
name|SymB
return|;
block|}
specifier|static
name|MCImm
name|get
parameter_list|(
name|MCSymbol
modifier|*
name|SymA
parameter_list|,
name|MCSymbol
modifier|*
name|SymB
init|=
literal|0
parameter_list|,
name|int64_t
name|Val
init|=
literal|0
parameter_list|)
block|{
name|MCImm
name|R
decl_stmt|;
name|R
operator|.
name|Cst
operator|=
name|Val
expr_stmt|;
name|R
operator|.
name|SymA
operator|=
name|SymA
expr_stmt|;
name|R
operator|.
name|SymB
operator|=
name|SymB
expr_stmt|;
return|return
name|R
return|;
block|}
specifier|static
name|MCImm
name|get
parameter_list|(
name|int64_t
name|Val
parameter_list|)
block|{
name|MCImm
name|R
decl_stmt|;
name|R
operator|.
name|Cst
operator|=
name|Val
expr_stmt|;
name|R
operator|.
name|SymA
operator|=
literal|0
expr_stmt|;
name|R
operator|.
name|SymB
operator|=
literal|0
expr_stmt|;
return|return
name|R
return|;
block|}
block|}
empty_stmt|;
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

