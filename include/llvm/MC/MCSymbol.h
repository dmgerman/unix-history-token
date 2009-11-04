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

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCSection
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|raw_ostream
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
comment|// Special sentinal value for the absolute pseudo section.
comment|//
comment|// FIXME: Use a PointerInt wrapper for this?
specifier|static
specifier|const
name|MCSection
modifier|*
name|AbsolutePseudoSection
decl_stmt|;
comment|/// Name - The name of the symbol.
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|/// Section - The section the symbol is defined in. This is null for
comment|/// undefined symbols, and the special AbsolutePseudoSection value for
comment|/// absolute symbols.
specifier|const
name|MCSection
modifier|*
name|Section
decl_stmt|;
comment|/// Value - If non-null, the value for a variable symbol.
specifier|const
name|MCExpr
modifier|*
name|Value
decl_stmt|;
comment|/// IsTemporary - True if this is an assembler temporary label, which
comment|/// typically does not survive in the .o file's symbol table.  Usually
comment|/// "Lfoo" or ".foo".
name|unsigned
name|IsTemporary
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
argument|const StringRef&_Name
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
name|Value
argument_list|(
literal|0
argument_list|)
operator|,
name|IsTemporary
argument_list|(
argument|_IsTemporary
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
comment|/// getName - Get the symbol name.
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
comment|/// @name Symbol Type
comment|/// @{
comment|/// isTemporary - Check if this is an assembler temporary symbol.
name|bool
name|isTemporary
argument_list|()
specifier|const
block|{
return|return
name|IsTemporary
return|;
block|}
comment|/// @}
comment|/// @name Associated Sections
comment|/// @{
comment|/// isDefined - Check if this symbol is defined (i.e., it has an address).
comment|///
comment|/// Defined symbols are either absolute or in some section.
name|bool
name|isDefined
argument_list|()
specifier|const
block|{
return|return
name|Section
operator|!=
literal|0
return|;
block|}
comment|/// isUndefined - Check if this symbol undefined (i.e., implicitly defined).
name|bool
name|isUndefined
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isDefined
argument_list|()
return|;
block|}
comment|/// isAbsolute - Check if this this is an absolute symbol.
name|bool
name|isAbsolute
argument_list|()
specifier|const
block|{
return|return
name|Section
operator|==
name|AbsolutePseudoSection
return|;
block|}
comment|/// getSection - Get the section associated with a defined, non-absolute
comment|/// symbol.
specifier|const
name|MCSection
operator|&
name|getSection
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isUndefined
argument_list|()
operator|&&
operator|!
name|isAbsolute
argument_list|()
operator|&&
literal|"Invalid accessor!"
argument_list|)
block|;
return|return
operator|*
name|Section
return|;
block|}
comment|/// setSection - Mark the symbol as defined in the section \arg S.
name|void
name|setSection
parameter_list|(
specifier|const
name|MCSection
modifier|&
name|S
parameter_list|)
block|{
name|Section
operator|=
operator|&
name|S
expr_stmt|;
block|}
comment|/// setUndefined - Mark the symbol as undefined.
name|void
name|setUndefined
parameter_list|()
block|{
name|Section
operator|=
literal|0
expr_stmt|;
block|}
comment|/// setAbsolute - Mark the symbol as absolute.
name|void
name|setAbsolute
parameter_list|()
block|{
name|Section
operator|=
name|AbsolutePseudoSection
expr_stmt|;
block|}
comment|/// @}
comment|/// @name Variable Symbols
comment|/// @{
comment|/// isVariable - Check if this is a variable symbol.
name|bool
name|isVariable
argument_list|()
specifier|const
block|{
return|return
name|Value
operator|!=
literal|0
return|;
block|}
comment|/// getValue() - Get the value for variable symbols, or null if the symbol
comment|/// is not a variable.
specifier|const
name|MCExpr
operator|*
name|getValue
argument_list|()
specifier|const
block|{
return|return
name|Value
return|;
block|}
name|void
name|setValue
parameter_list|(
specifier|const
name|MCExpr
modifier|*
name|Value
parameter_list|)
block|{
name|this
operator|->
name|Value
operator|=
name|Value
expr_stmt|;
block|}
comment|/// @}
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

