begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- SourceLanguage.h - Interact with source languages --------*- C++ -*-===//
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
comment|// This file defines the abstract SourceLanguage interface, which is used by the
end_comment

begin_comment
comment|// LLVM debugger to parse source-language expressions and render program objects
end_comment

begin_comment
comment|// into a human readable string.  In general, these classes perform all of the
end_comment

begin_comment
comment|// analysis and interpretation of the language-specific debugger information.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This interface is designed to be completely stateless, so all methods are
end_comment

begin_comment
comment|// const.
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
name|LLVM_DEBUGGER_SOURCELANGUAGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGGER_SOURCELANGUAGE_H
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
name|GlobalVariable
decl_stmt|;
name|class
name|SourceFileInfo
decl_stmt|;
name|class
name|SourceFunctionInfo
decl_stmt|;
name|class
name|ProgramInfo
decl_stmt|;
name|class
name|RuntimeInfo
decl_stmt|;
struct|struct
name|SourceLanguage
block|{
name|virtual
operator|~
name|SourceLanguage
argument_list|()
block|{}
comment|/// getSourceLanguageName - This method is used to implement the 'show
comment|/// language' command in the debugger.
name|virtual
specifier|const
name|char
operator|*
name|getSourceLanguageName
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Methods used to implement debugger hooks.
comment|//
comment|/// printInfo - Implementing this method allows the debugger to use
comment|/// language-specific 'info' extensions, e.g., 'info selectors' for objc.
comment|/// This method should return true if the specified string is recognized.
comment|///
name|virtual
name|bool
name|printInfo
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|What
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
comment|/// lookupFunction - Given a textual function name, return the
comment|/// SourceFunctionInfo descriptor for that function, or null if it cannot be
comment|/// found.  If the program is currently running, the RuntimeInfo object
comment|/// provides information about the current evaluation context, otherwise it
comment|/// will be null.
comment|///
name|virtual
name|SourceFunctionInfo
modifier|*
name|lookupFunction
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|FunctionName
argument_list|,
name|ProgramInfo
operator|&
name|PI
argument_list|,
name|RuntimeInfo
operator|*
name|RI
operator|=
literal|0
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
comment|//===------------------------------------------------------------------===//
comment|// Methods used to parse various pieces of program information.
comment|//
comment|/// createSourceFileInfo - This method can be implemented by the front-end
comment|/// if it needs to keep track of information beyond what the debugger
comment|/// requires.
name|virtual
name|SourceFileInfo
modifier|*
name|createSourceFileInfo
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|Desc
argument_list|,
name|ProgramInfo
operator|&
name|PI
argument_list|)
decl|const
decl_stmt|;
comment|/// createSourceFunctionInfo - This method can be implemented by the derived
comment|/// SourceLanguage if it needs to keep track of more information than the
comment|/// SourceFunctionInfo has.
name|virtual
name|SourceFunctionInfo
modifier|*
name|createSourceFunctionInfo
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|Desc
argument_list|,
name|ProgramInfo
operator|&
name|PI
argument_list|)
decl|const
decl_stmt|;
comment|//===------------------------------------------------------------------===//
comment|// Static methods used to get instances of various source languages.
comment|//
comment|/// get - This method returns a source-language instance for the specified
comment|/// Dwarf 3 language identifier.  If the language is unknown, an object is
comment|/// returned that can support some minimal operations, but is not terribly
comment|/// bright.
specifier|static
specifier|const
name|SourceLanguage
modifier|&
name|get
parameter_list|(
name|unsigned
name|ID
parameter_list|)
function_decl|;
comment|/// get*Instance() - These methods return specific instances of languages.
comment|///
specifier|static
specifier|const
name|SourceLanguage
modifier|&
name|getCFamilyInstance
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|SourceLanguage
modifier|&
name|getCPlusPlusInstance
parameter_list|()
function_decl|;
specifier|static
specifier|const
name|SourceLanguage
modifier|&
name|getUnknownLanguageInstance
parameter_list|()
function_decl|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

