begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCValue.h - MCValue class -----------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCValue class.
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
name|LLVM_MC_MCVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/MC/MCExpr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief This represents an "assembler immediate".
comment|///
comment|///  In its most general form, this can hold ":Kind:(SymbolA - SymbolB +
comment|///  imm64)".  Not all targets supports relocations of this general form, but we
comment|///  need to represent this anyway.
comment|///
comment|/// In general both SymbolA and SymbolB will also have a modifier
comment|/// analogous to the top-level Kind. Current targets are not expected
comment|/// to make use of both though. The choice comes down to whether
comment|/// relocation modifiers apply to the closest symbol or the whole
comment|/// expression.
comment|///
comment|/// Note that this class must remain a simple POD value class, because we need
comment|/// it to live in unions etc.
name|class
name|MCValue
block|{
specifier|const
name|MCSymbolRefExpr
modifier|*
name|SymA
decl_stmt|,
modifier|*
name|SymB
decl_stmt|;
name|int64_t
name|Cst
decl_stmt|;
name|uint32_t
name|RefKind
decl_stmt|;
name|public
label|:
name|MCValue
argument_list|()
operator|:
name|SymA
argument_list|(
name|nullptr
argument_list|)
operator|,
name|SymB
argument_list|(
name|nullptr
argument_list|)
operator|,
name|Cst
argument_list|(
literal|0
argument_list|)
operator|,
name|RefKind
argument_list|(
literal|0
argument_list|)
block|{}
name|int64_t
name|getConstant
argument_list|()
specifier|const
block|{
return|return
name|Cst
return|;
block|}
specifier|const
name|MCSymbolRefExpr
operator|*
name|getSymA
argument_list|()
specifier|const
block|{
return|return
name|SymA
return|;
block|}
specifier|const
name|MCSymbolRefExpr
operator|*
name|getSymB
argument_list|()
specifier|const
block|{
return|return
name|SymB
return|;
block|}
name|uint32_t
name|getRefKind
argument_list|()
specifier|const
block|{
return|return
name|RefKind
return|;
block|}
comment|/// \brief Is this an absolute (as opposed to relocatable) value.
name|bool
name|isAbsolute
argument_list|()
specifier|const
block|{
return|return
operator|!
name|SymA
operator|&&
operator|!
name|SymB
return|;
block|}
comment|/// \brief Print the value to the stream \p OS.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Print the value to stderr.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|MCSymbolRefExpr
operator|::
name|VariantKind
name|getAccessVariant
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|MCValue
name|get
parameter_list|(
specifier|const
name|MCSymbolRefExpr
modifier|*
name|SymA
parameter_list|,
specifier|const
name|MCSymbolRefExpr
modifier|*
name|SymB
init|=
name|nullptr
parameter_list|,
name|int64_t
name|Val
init|=
literal|0
parameter_list|,
name|uint32_t
name|RefKind
init|=
literal|0
parameter_list|)
block|{
name|MCValue
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
name|R
operator|.
name|RefKind
operator|=
name|RefKind
expr_stmt|;
return|return
name|R
return|;
block|}
specifier|static
name|MCValue
name|get
parameter_list|(
name|int64_t
name|Val
parameter_list|)
block|{
name|MCValue
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
name|nullptr
expr_stmt|;
name|R
operator|.
name|SymB
operator|=
name|nullptr
expr_stmt|;
name|R
operator|.
name|RefKind
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

