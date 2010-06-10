begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DependencyOutputOptions.h ------------------------------*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_DEPENDENCYOUTPUTOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_DEPENDENCYOUTPUTOPTIONS_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// DependencyOutputOptions - Options for controlling the compiler dependency
comment|/// file generation.
name|class
name|DependencyOutputOptions
block|{
name|public
label|:
name|unsigned
name|IncludeSystemHeaders
range|:
literal|1
decl_stmt|;
comment|///< Include system header dependencies.
name|unsigned
name|UsePhonyTargets
range|:
literal|1
decl_stmt|;
comment|///< Include phony targets for each
comment|/// dependency, which can avoid some 'make'
comment|/// problems.
comment|/// The file to write depencency output to.
name|std
operator|::
name|string
name|OutputFile
expr_stmt|;
comment|/// A list of names to use as the targets in the dependency file; this list
comment|/// must contain at least one entry.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Targets
expr_stmt|;
name|public
label|:
name|DependencyOutputOptions
argument_list|()
block|{
name|IncludeSystemHeaders
operator|=
literal|0
expr_stmt|;
name|UsePhonyTargets
operator|=
literal|0
expr_stmt|;
block|}
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

