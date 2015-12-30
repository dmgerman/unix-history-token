begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Lookup.h - Framework for clang refactoring tools --*- C++ -*------===//
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
comment|//  This file defines helper methods for clang tools performing name lookup.
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
name|LLVM_CLANG_TOOLING_CORE_LOOKUP_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_CORE_LOOKUP_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DeclContext
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|NestedNameSpecifier
decl_stmt|;
name|namespace
name|tooling
block|{
comment|/// Emulate a lookup to replace one nested name specifier with another using as
comment|/// few additional namespace qualifications as possible.
comment|///
comment|/// This does not perform a full C++ lookup so ADL will not work.
comment|///
comment|/// \param Use The nested name to be replaced.
comment|/// \param UseContext The context in which the nested name is contained. This
comment|///                   will be used to minimize namespace qualifications.
comment|/// \param FromDecl The declaration to which the nested name points.
comment|/// \param ReplacementString The replacement nested name. Must be fully
comment|///                          qualified including a leading "::".
comment|/// \returns The new name to be inserted in place of the current nested name.
name|std
operator|::
name|string
name|replaceNestedName
argument_list|(
argument|const NestedNameSpecifier *Use
argument_list|,
argument|const DeclContext *UseContext
argument_list|,
argument|const NamedDecl *FromDecl
argument_list|,
argument|StringRef ReplacementString
argument_list|)
expr_stmt|;
block|}
comment|// end namespace tooling
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_TOOLING_CORE_LOOKUP_H
end_comment

end_unit

