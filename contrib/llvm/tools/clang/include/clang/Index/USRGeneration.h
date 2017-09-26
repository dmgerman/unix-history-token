begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- USRGeneration.h - Routines for USR generation ----------------------===//
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
name|LLVM_CLANG_INDEX_USRGENERATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_INDEX_USRGENERATION_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|MacroDefinitionRecord
decl_stmt|;
name|class
name|SourceLocation
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|namespace
name|index
block|{
specifier|static
specifier|inline
name|StringRef
name|getUSRSpacePrefix
parameter_list|()
block|{
return|return
literal|"c:"
return|;
block|}
comment|/// \brief Generate a USR for a Decl, including the USR prefix.
comment|/// \returns true if the results should be ignored, false otherwise.
name|bool
name|generateUSRForDecl
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Buf
argument_list|)
decl_stmt|;
comment|/// \brief Generate a USR fragment for an Objective-C class.
name|void
name|generateUSRForObjCClass
parameter_list|(
name|StringRef
name|Cls
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|StringRef
name|ExtSymbolDefinedIn
init|=
literal|""
parameter_list|,
name|StringRef
name|CategoryContextExtSymbolDefinedIn
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// \brief Generate a USR fragment for an Objective-C class category.
name|void
name|generateUSRForObjCCategory
parameter_list|(
name|StringRef
name|Cls
parameter_list|,
name|StringRef
name|Cat
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|StringRef
name|ClsExtSymbolDefinedIn
init|=
literal|""
parameter_list|,
name|StringRef
name|CatExtSymbolDefinedIn
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// \brief Generate a USR fragment for an Objective-C instance variable.  The
comment|/// complete USR can be created by concatenating the USR for the
comment|/// encompassing class with this USR fragment.
name|void
name|generateUSRForObjCIvar
parameter_list|(
name|StringRef
name|Ivar
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// \brief Generate a USR fragment for an Objective-C method.
name|void
name|generateUSRForObjCMethod
parameter_list|(
name|StringRef
name|Sel
parameter_list|,
name|bool
name|IsInstanceMethod
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// \brief Generate a USR fragment for an Objective-C property.
name|void
name|generateUSRForObjCProperty
parameter_list|(
name|StringRef
name|Prop
parameter_list|,
name|bool
name|isClassProp
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// \brief Generate a USR fragment for an Objective-C protocol.
name|void
name|generateUSRForObjCProtocol
parameter_list|(
name|StringRef
name|Prot
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|StringRef
name|ExtSymbolDefinedIn
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// Generate USR fragment for a global (non-nested) enum.
name|void
name|generateUSRForGlobalEnum
parameter_list|(
name|StringRef
name|EnumName
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|StringRef
name|ExtSymbolDefinedIn
init|=
literal|""
parameter_list|)
function_decl|;
comment|/// Generate a USR fragment for an enum constant.
name|void
name|generateUSRForEnumConstant
parameter_list|(
name|StringRef
name|EnumConstantName
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
comment|/// \brief Generate a USR for a macro, including the USR prefix.
comment|///
comment|/// \returns true on error, false on success.
name|bool
name|generateUSRForMacro
argument_list|(
specifier|const
name|MacroDefinitionRecord
operator|*
name|MD
argument_list|,
specifier|const
name|SourceManager
operator|&
name|SM
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Buf
argument_list|)
decl_stmt|;
name|bool
name|generateUSRForMacro
argument_list|(
name|StringRef
name|MacroName
argument_list|,
name|SourceLocation
name|Loc
argument_list|,
specifier|const
name|SourceManager
operator|&
name|SM
argument_list|,
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Buf
argument_list|)
decl_stmt|;
block|}
comment|// namespace index
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_IDE_USRGENERATION_H
end_comment

end_unit

