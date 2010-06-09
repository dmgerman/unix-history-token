begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MacroBuilder.h - CPP Macro building utility ------------*- C++ -*-===//
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
comment|//  This file defines the MacroBuilder utility class.
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
name|LLVM_CLANG_BASIC_MACROBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_MACROBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|MacroBuilder
block|{
name|llvm
operator|::
name|raw_ostream
operator|&
name|Out
expr_stmt|;
name|public
label|:
name|MacroBuilder
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|Output
argument_list|)
operator|:
name|Out
argument_list|(
argument|Output
argument_list|)
block|{}
comment|/// Append a #define line for macro of the form "#define Name Value\n".
name|void
name|defineMacro
argument_list|(
argument|const llvm::Twine&Name
argument_list|,
argument|const llvm::Twine&Value =
literal|"1"
argument_list|)
block|{
name|Out
operator|<<
literal|"#define "
operator|<<
name|Name
operator|<<
literal|' '
operator|<<
name|Value
operator|<<
literal|'\n'
block|;   }
comment|/// Append a #undef line for Name.  Name should be of the form XXX
comment|/// and we emit "#undef XXX".
name|void
name|undefineMacro
argument_list|(
argument|const llvm::Twine&Name
argument_list|)
block|{
name|Out
operator|<<
literal|"#undef "
operator|<<
name|Name
operator|<<
literal|'\n'
block|;   }
comment|/// Directly append Str and a newline to the underlying buffer.
name|void
name|append
argument_list|(
argument|const llvm::Twine&Str
argument_list|)
block|{
name|Out
operator|<<
name|Str
operator|<<
literal|'\n'
block|;   }
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

