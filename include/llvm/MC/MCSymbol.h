begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MCSymbol.h - Machine Code Symbols ------------------------*- C++ -*-===//
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
comment|// This file contains the declaration of the MCSymbol class.
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
name|LLVM_MC_MCSYMBOL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCSYMBOL_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSection
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
comment|/// MCSymbol - Instances of this class represent a symbol name in the MC file,
comment|/// and MCSymbols are created and unique'd by the MCContext class.
comment|///
comment|/// If the symbol is defined/emitted into the current translation unit, the
comment|/// Section member is set to indicate what section it lives in.  Otherwise, if
comment|/// it is a reference to an external entity, it has a null section.
comment|///
name|class
name|MCSymbol
block|{
comment|/// Name - The name of the symbol.
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|/// Section - The section the symbol is defined in, or null if the symbol
comment|/// has not been defined in the associated translation unit.
name|MCSection
modifier|*
name|Section
decl_stmt|;
comment|/// IsTemporary - True if this is an assembler temporary label, which
comment|/// typically does not survive in the .o file's symbol table.  Usually
comment|/// "Lfoo" or ".foo".
name|unsigned
name|IsTemporary
range|:
literal|1
decl_stmt|;
comment|/// IsExternal - True if this symbol has been implicitly defined as an
comment|/// external, for example by using it in an expression without ever emitting
comment|/// it as a label. The @var Section for an external symbol is always null.
name|unsigned
name|IsExternal
range|:
literal|1
decl_stmt|;
name|private
label|:
comment|// MCContext creates and uniques these.
name|friend
name|class
name|MCContext
decl_stmt|;
name|MCSymbol
argument_list|(
argument|const char *_Name
argument_list|,
argument|bool _IsTemporary
argument_list|)
block|:
name|Name
argument_list|(
name|_Name
argument_list|)
operator|,
name|Section
argument_list|(
literal|0
argument_list|)
operator|,
name|IsTemporary
argument_list|(
name|_IsTemporary
argument_list|)
operator|,
name|IsExternal
argument_list|(
argument|false
argument_list|)
block|{}
name|MCSymbol
argument_list|(
specifier|const
name|MCSymbol
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MCSymbol
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|MCSection
operator|*
name|getSection
argument_list|()
specifier|const
block|{
return|return
name|Section
return|;
block|}
name|void
name|setSection
parameter_list|(
name|MCSection
modifier|*
name|Value
parameter_list|)
block|{
name|Section
operator|=
name|Value
expr_stmt|;
block|}
name|bool
name|isExternal
argument_list|()
specifier|const
block|{
return|return
name|IsExternal
return|;
block|}
name|void
name|setExternal
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|IsExternal
operator|=
name|Value
expr_stmt|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
block|{
return|return
name|Name
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

