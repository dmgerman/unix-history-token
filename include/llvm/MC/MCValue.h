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
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCSymbol.h"
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
name|MCSymbol
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// MCValue - This represents an "assembler immediate".  In its most general
comment|/// form, this can hold "SymbolA - SymbolB + imm64".  Not all targets supports
comment|/// relocations of this general form, but we need to represent this anyway.
comment|///
comment|/// In the general form, SymbolB can only be defined if SymbolA is, and both
comment|/// must be in the same (non-external) section. The latter constraint is not
comment|/// enforced, since a symbol's section may not be known at construction.
comment|///
comment|/// Note that this class must remain a simple POD value class, because we need
comment|/// it to live in unions etc.
name|class
name|MCValue
block|{
specifier|const
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
name|getConstant
argument_list|()
specifier|const
block|{
return|return
name|Cst
return|;
block|}
specifier|const
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
specifier|const
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
comment|/// isAbsolute - Is this an absolute (as opposed to relocatable) value.
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
comment|/// getAssociatedSection - For relocatable values, return the section the
comment|/// value is associated with.
comment|///
comment|/// @result - The value's associated section, or null for external or constant
comment|/// values.
comment|//
comment|// FIXME: Switch to a tagged section, so this can return the tagged section
comment|// value.
specifier|const
name|MCSection
operator|*
name|getAssociatedSection
argument_list|()
specifier|const
expr_stmt|;
comment|/// print - Print the value to the stream \arg OS.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|MCAsmInfo
operator|*
name|MAI
argument_list|)
decl|const
decl_stmt|;
comment|/// dump - Print the value to stderr.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|MCValue
name|get
parameter_list|(
specifier|const
name|MCSymbol
modifier|*
name|SymA
parameter_list|,
specifier|const
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
name|MCValue
name|R
decl_stmt|;
name|assert
argument_list|(
operator|(
operator|!
name|SymB
operator|||
name|SymA
operator|)
operator|&&
literal|"Invalid relocatable MCValue!"
argument_list|)
expr_stmt|;
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

