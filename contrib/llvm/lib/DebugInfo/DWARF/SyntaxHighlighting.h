begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SyntaxHighlighting.h ------------------------------------*- C++ -*-===//
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
name|LLVM_LIB_DEBUGINFO_SYNTAXHIGHLIGHTING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_DEBUGINFO_SYNTAXHIGHLIGHTING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|dwarf
block|{
name|namespace
name|syntax
block|{
comment|// Symbolic names for various syntax elements.
enum|enum
name|HighlightColor
block|{
name|Address
block|,
name|String
block|,
name|Tag
block|,
name|Attribute
block|,
name|Enumerator
block|}
enum|;
comment|/// An RAII object that temporarily switches an output stream to a
comment|/// specific color.
name|class
name|WithColor
block|{
name|llvm
operator|::
name|raw_ostream
operator|&
name|OS
expr_stmt|;
name|public
label|:
comment|/// To be used like this: WithColor(OS, syntax::String)<< "text";
name|WithColor
argument_list|(
argument|llvm::raw_ostream&OS
argument_list|,
argument|enum HighlightColor Type
argument_list|)
empty_stmt|;
operator|~
name|WithColor
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|raw_ostream
operator|&
name|get
argument_list|()
block|{
return|return
name|OS
return|;
block|}
name|operator
name|llvm
operator|::
name|raw_ostream
operator|&
operator|(
operator|)
block|{
return|return
name|OS
return|;
block|}
block|}
empty_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

