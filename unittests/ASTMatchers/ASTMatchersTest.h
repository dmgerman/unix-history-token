begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- unittest/Tooling/ASTMatchersTest.h - Matcher tests helpers ------===//
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
name|LLVM_CLANG_UNITTESTS_ASTMATCHERS_ASTMATCHERSTEST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_UNITTESTS_ASTMATCHERS_ASTMATCHERSTEST_H
end_define

begin_include
include|#
directive|include
file|"clang/ASTMatchers/ASTMatchFinder.h"
end_include

begin_include
include|#
directive|include
file|"clang/Frontend/ASTUnit.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/Tooling.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ast_matchers
block|{
name|using
name|clang
operator|::
name|tooling
operator|::
name|buildASTFromCodeWithArgs
expr_stmt|;
name|using
name|clang
operator|::
name|tooling
operator|::
name|newFrontendActionFactory
expr_stmt|;
name|using
name|clang
operator|::
name|tooling
operator|::
name|runToolOnCodeWithArgs
expr_stmt|;
name|using
name|clang
operator|::
name|tooling
operator|::
name|FrontendActionFactory
expr_stmt|;
name|using
name|clang
operator|::
name|tooling
operator|::
name|FileContentMappings
expr_stmt|;
name|class
name|BoundNodesCallback
block|{
name|public
label|:
name|virtual
operator|~
name|BoundNodesCallback
argument_list|()
block|{}
name|virtual
name|bool
name|run
argument_list|(
specifier|const
name|BoundNodes
operator|*
name|BoundNodes
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|bool
name|run
parameter_list|(
specifier|const
name|BoundNodes
modifier|*
name|BoundNodes
parameter_list|,
name|ASTContext
modifier|*
name|Context
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|void
name|onEndOfTranslationUnit
parameter_list|()
block|{}
block|}
empty_stmt|;
comment|// If 'FindResultVerifier' is not NULL, sets *Verified to the result of
comment|// running 'FindResultVerifier' with the bound nodes as argument.
comment|// If 'FindResultVerifier' is NULL, sets *Verified to true when Run is called.
name|class
name|VerifyMatch
range|:
name|public
name|MatchFinder
operator|::
name|MatchCallback
block|{
name|public
operator|:
name|VerifyMatch
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|BoundNodesCallback
operator|>
name|FindResultVerifier
argument_list|,
name|bool
operator|*
name|Verified
argument_list|)
operator|:
name|Verified
argument_list|(
name|Verified
argument_list|)
block|,
name|FindResultReviewer
argument_list|(
argument|std::move(FindResultVerifier)
argument_list|)
block|{}
name|void
name|run
argument_list|(
argument|const MatchFinder::MatchResult&Result
argument_list|)
name|override
block|{
if|if
condition|(
name|FindResultReviewer
operator|!=
name|nullptr
condition|)
block|{
operator|*
name|Verified
operator||=
name|FindResultReviewer
operator|->
name|run
argument_list|(
operator|&
name|Result
operator|.
name|Nodes
argument_list|,
name|Result
operator|.
name|Context
argument_list|)
expr_stmt|;
block|}
else|else
block|{
operator|*
name|Verified
operator|=
name|true
expr_stmt|;
block|}
block|}
name|void
name|onEndOfTranslationUnit
argument_list|()
name|override
block|{
if|if
condition|(
name|FindResultReviewer
condition|)
name|FindResultReviewer
operator|->
name|onEndOfTranslationUnit
argument_list|()
expr_stmt|;
block|}
name|private
operator|:
name|bool
operator|*
specifier|const
name|Verified
block|;
specifier|const
name|std
operator|::
name|unique_ptr
operator|<
name|BoundNodesCallback
operator|>
name|FindResultReviewer
block|; }
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|matchesConditionally
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|,
argument|bool ExpectMatch
argument_list|,
argument|llvm::ArrayRef<llvm::StringRef> CompileArgs
argument_list|,
argument|const FileContentMappings&VirtualMappedFiles = FileContentMappings()
argument_list|,
argument|const std::string&Filename =
literal|"input.cc"
argument_list|)
block|{
name|bool
name|Found
operator|=
name|false
block|,
name|DynamicFound
operator|=
name|false
block|;
name|MatchFinder
name|Finder
block|;
name|VerifyMatch
name|VerifyFound
argument_list|(
name|nullptr
argument_list|,
operator|&
name|Found
argument_list|)
block|;
name|Finder
operator|.
name|addMatcher
argument_list|(
name|AMatcher
argument_list|,
operator|&
name|VerifyFound
argument_list|)
block|;
name|VerifyMatch
name|VerifyDynamicFound
argument_list|(
name|nullptr
argument_list|,
operator|&
name|DynamicFound
argument_list|)
block|;
if|if
condition|(
operator|!
name|Finder
operator|.
name|addDynamicMatcher
argument_list|(
name|AMatcher
argument_list|,
operator|&
name|VerifyDynamicFound
argument_list|)
condition|)
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Could not add dynamic matcher"
return|;
name|std
operator|::
name|unique_ptr
operator|<
name|FrontendActionFactory
operator|>
name|Factory
argument_list|(
name|newFrontendActionFactory
argument_list|(
operator|&
name|Finder
argument_list|)
argument_list|)
expr_stmt|;
comment|// Some tests need rtti/exceptions on.  Use an unknown-unknown triple so we
comment|// don't instantiate the full system toolchain.  On Linux, instantiating the
comment|// toolchain involves stat'ing large portions of /usr/lib, and this slows down
comment|// not only this test, but all other tests, via contention in the kernel.
comment|//
comment|// FIXME: This is a hack to work around the fact that there's no way to do the
comment|// equivalent of runToolOnCodeWithArgs without instantiating a full Driver.
comment|// We should consider having a function, at least for tests, that invokes cc1.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Args
argument_list|(
name|CompileArgs
operator|.
name|begin
argument_list|()
argument_list|,
name|CompileArgs
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|Args
operator|.
name|insert
argument_list|(
name|Args
operator|.
name|end
argument_list|()
argument_list|,
block|{
literal|"-frtti"
operator|,
literal|"-fexceptions"
operator|,
literal|"-target"
operator|,
literal|"i386-unknown-unknown"
block|}
block|)
decl_stmt|;
if|if
condition|(
operator|!
name|runToolOnCodeWithArgs
argument_list|(
name|Factory
operator|->
name|create
argument_list|()
argument_list|,
name|Code
argument_list|,
name|Args
argument_list|,
name|Filename
argument_list|,
literal|"clang-tool"
argument_list|,
name|std
operator|::
name|make_shared
operator|<
name|PCHContainerOperations
operator|>
operator|(
operator|)
argument_list|,
name|VirtualMappedFiles
argument_list|)
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Parsing error in \""
operator|<<
name|Code
operator|<<
literal|"\""
return|;
block|}
if|if
condition|(
name|Found
operator|!=
name|DynamicFound
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Dynamic match result ("
operator|<<
name|DynamicFound
operator|<<
literal|") does not match static result ("
operator|<<
name|Found
operator|<<
literal|")"
return|;
block|}
if|if
condition|(
operator|!
name|Found
operator|&&
name|ExpectMatch
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Could not find match in \""
operator|<<
name|Code
operator|<<
literal|"\""
return|;
block|}
elseif|else
if|if
condition|(
name|Found
operator|&&
operator|!
name|ExpectMatch
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Found unexpected match in \""
operator|<<
name|Code
operator|<<
literal|"\""
return|;
block|}
return|return
name|testing
operator|::
name|AssertionSuccess
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|matchesConditionally
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|,
argument|bool ExpectMatch
argument_list|,
argument|llvm::StringRef CompileArg
argument_list|,
argument|const FileContentMappings&VirtualMappedFiles = FileContentMappings()
argument_list|,
argument|const std::string&Filename =
literal|"input.cc"
argument_list|)
block|{
return|return
name|matchesConditionally
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|ExpectMatch
argument_list|,
name|llvm
operator|::
name|makeArrayRef
argument_list|(
name|CompileArg
argument_list|)
argument_list|,
name|VirtualMappedFiles
argument_list|,
name|Filename
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|matches
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|)
block|{
return|return
name|matchesConditionally
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|true
argument_list|,
literal|"-std=c++11"
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|notMatches
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|)
block|{
return|return
name|matchesConditionally
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|false
argument_list|,
literal|"-std=c++11"
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|matchesObjC
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|,
argument|bool ExpectMatch = true
argument_list|)
block|{
return|return
name|matchesConditionally
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|ExpectMatch
argument_list|,
block|{
literal|"-fobjc-nonfragile-abi"
operator|,
literal|"-Wno-objc-root-class"
operator|,
literal|"-Wno-incomplete-implementation"
block|}
operator|,
name|FileContentMappings
argument_list|()
operator|,
literal|"input.m"
end_expr_stmt

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|matchesC
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|)
block|{
return|return
name|matchesConditionally
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|true
argument_list|,
literal|""
argument_list|,
name|FileContentMappings
argument_list|()
argument_list|,
literal|"input.c"
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|matchesC99
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|)
block|{
return|return
name|matchesConditionally
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|true
argument_list|,
literal|"-std=c99"
argument_list|,
name|FileContentMappings
argument_list|()
argument_list|,
literal|"input.c"
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|notMatchesC
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|)
block|{
return|return
name|matchesConditionally
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|false
argument_list|,
literal|""
argument_list|,
name|FileContentMappings
argument_list|()
argument_list|,
literal|"input.c"
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|notMatchesObjC
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|)
block|{
return|return
name|matchesObjC
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|false
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Function based on matchesConditionally with "-x cuda" argument added and
end_comment

begin_comment
comment|// small CUDA header prepended to the code string.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|matchesConditionallyWithCuda
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|,
argument|bool ExpectMatch
argument_list|,
argument|llvm::StringRef CompileArg
argument_list|)
block|{
specifier|const
name|std
operator|::
name|string
name|CudaHeader
operator|=
literal|"typedef unsigned int size_t;\n"
literal|"#define __constant__ __attribute__((constant))\n"
literal|"#define __device__ __attribute__((device))\n"
literal|"#define __global__ __attribute__((global))\n"
literal|"#define __host__ __attribute__((host))\n"
literal|"#define __shared__ __attribute__((shared))\n"
literal|"struct dim3 {"
literal|"  unsigned x, y, z;"
literal|"  __host__ __device__ dim3(unsigned x, unsigned y = 1, unsigned z = 1)"
literal|"      : x(x), y(y), z(z) {}"
literal|"};"
literal|"typedef struct cudaStream *cudaStream_t;"
literal|"int cudaConfigureCall(dim3 gridSize, dim3 blockSize,"
literal|"                      size_t sharedSize = 0,"
literal|"                      cudaStream_t stream = 0);"
block|;
name|bool
name|Found
operator|=
name|false
block|,
name|DynamicFound
operator|=
name|false
block|;
name|MatchFinder
name|Finder
block|;
name|VerifyMatch
name|VerifyFound
argument_list|(
name|nullptr
argument_list|,
operator|&
name|Found
argument_list|)
block|;
name|Finder
operator|.
name|addMatcher
argument_list|(
name|AMatcher
argument_list|,
operator|&
name|VerifyFound
argument_list|)
block|;
name|VerifyMatch
name|VerifyDynamicFound
argument_list|(
name|nullptr
argument_list|,
operator|&
name|DynamicFound
argument_list|)
block|;
if|if
condition|(
operator|!
name|Finder
operator|.
name|addDynamicMatcher
argument_list|(
name|AMatcher
argument_list|,
operator|&
name|VerifyDynamicFound
argument_list|)
condition|)
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Could not add dynamic matcher"
return|;
name|std
operator|::
name|unique_ptr
operator|<
name|FrontendActionFactory
operator|>
name|Factory
argument_list|(
name|newFrontendActionFactory
argument_list|(
operator|&
name|Finder
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Some tests use typeof, which is a gnu extension.  Using an explicit
end_comment

begin_comment
comment|// unknown-unknown triple is good for a large speedup, because it lets us
end_comment

begin_comment
comment|// avoid constructing a full system triple.
end_comment

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Args
operator|=
block|{
literal|"-xcuda"
block|,
literal|"-fno-ms-extensions"
block|,
literal|"--cuda-host-only"
block|,
literal|"-nocudainc"
block|,
literal|"-target"
block|,
literal|"x86_64-unknown-unknown"
block|,
name|CompileArg
block|}
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|runToolOnCodeWithArgs
argument_list|(
name|Factory
operator|->
name|create
argument_list|()
argument_list|,
name|CudaHeader
operator|+
name|Code
argument_list|,
name|Args
argument_list|)
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Parsing error in \""
operator|<<
name|Code
operator|<<
literal|"\""
return|;
block|}
end_if

begin_if
if|if
condition|(
name|Found
operator|!=
name|DynamicFound
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Dynamic match result ("
operator|<<
name|DynamicFound
operator|<<
literal|") does not match static result ("
operator|<<
name|Found
operator|<<
literal|")"
return|;
block|}
end_if

begin_if
if|if
condition|(
operator|!
name|Found
operator|&&
name|ExpectMatch
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Could not find match in \""
operator|<<
name|Code
operator|<<
literal|"\""
return|;
block|}
elseif|else
if|if
condition|(
name|Found
operator|&&
operator|!
name|ExpectMatch
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Found unexpected match in \""
operator|<<
name|Code
operator|<<
literal|"\""
return|;
block|}
end_if

begin_return
return|return
name|testing
operator|::
name|AssertionSuccess
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}  template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|matchesWithCuda
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|)
block|{
return|return
name|matchesConditionallyWithCuda
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|true
argument_list|,
literal|"-std=c++11"
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|notMatchesWithCuda
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|)
block|{
return|return
name|matchesConditionallyWithCuda
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|false
argument_list|,
literal|"-std=c++11"
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|matchAndVerifyResultConditionally
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|,
argument|std::unique_ptr<BoundNodesCallback> FindResultVerifier
argument_list|,
argument|bool ExpectResult
argument_list|)
block|{
name|bool
name|VerifiedResult
operator|=
name|false
block|;
name|MatchFinder
name|Finder
block|;
name|VerifyMatch
name|VerifyVerifiedResult
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|FindResultVerifier
argument_list|)
argument_list|,
operator|&
name|VerifiedResult
argument_list|)
block|;
name|Finder
operator|.
name|addMatcher
argument_list|(
name|AMatcher
argument_list|,
operator|&
name|VerifyVerifiedResult
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|FrontendActionFactory
operator|>
name|Factory
argument_list|(
name|newFrontendActionFactory
argument_list|(
operator|&
name|Finder
argument_list|)
argument_list|)
block|;
comment|// Some tests use typeof, which is a gnu extension.  Using an explicit
comment|// unknown-unknown triple is good for a large speedup, because it lets us
comment|// avoid constructing a full system triple.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Args
operator|=
block|{
literal|"-std=gnu++98"
block|,
literal|"-target"
block|,
literal|"i386-unknown-unknown"
block|}
block|;
if|if
condition|(
operator|!
name|runToolOnCodeWithArgs
argument_list|(
name|Factory
operator|->
name|create
argument_list|()
argument_list|,
name|Code
argument_list|,
name|Args
argument_list|)
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Parsing error in \""
operator|<<
name|Code
operator|<<
literal|"\""
return|;
block|}
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|VerifiedResult
operator|&&
name|ExpectResult
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Could not verify result in \""
operator|<<
name|Code
operator|<<
literal|"\""
return|;
block|}
elseif|else
if|if
condition|(
name|VerifiedResult
operator|&&
operator|!
name|ExpectResult
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Verified unexpected result in \""
operator|<<
name|Code
operator|<<
literal|"\""
return|;
block|}
end_if

begin_expr_stmt
name|VerifiedResult
operator|=
name|false
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|ASTUnit
operator|>
name|AST
argument_list|(
name|buildASTFromCodeWithArgs
argument_list|(
name|Code
argument_list|,
name|Args
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|AST
operator|.
name|get
argument_list|()
condition|)
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Parsing error in \""
operator|<<
name|Code
operator|<<
literal|"\" while building AST"
return|;
end_if

begin_expr_stmt
name|Finder
operator|.
name|matchAST
argument_list|(
name|AST
operator|->
name|getASTContext
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
operator|!
name|VerifiedResult
operator|&&
name|ExpectResult
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Could not verify result in \""
operator|<<
name|Code
operator|<<
literal|"\" with AST"
return|;
block|}
elseif|else
if|if
condition|(
name|VerifiedResult
operator|&&
operator|!
name|ExpectResult
condition|)
block|{
return|return
name|testing
operator|::
name|AssertionFailure
argument_list|()
operator|<<
literal|"Verified unexpected result in \""
operator|<<
name|Code
operator|<<
literal|"\" with AST"
return|;
block|}
end_if

begin_return
return|return
name|testing
operator|::
name|AssertionSuccess
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|// FIXME: Find better names for these functions (or document what they
end_comment

begin_comment
comment|// do more precisely).
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|matchAndVerifyResultTrue
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|,
argument|std::unique_ptr<BoundNodesCallback> FindResultVerifier
argument_list|)
block|{
return|return
name|matchAndVerifyResultConditionally
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|FindResultVerifier
argument_list|)
argument_list|,
name|true
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|testing
operator|::
name|AssertionResult
name|matchAndVerifyResultFalse
argument_list|(
argument|const std::string&Code
argument_list|,
argument|const T&AMatcher
argument_list|,
argument|std::unique_ptr<BoundNodesCallback> FindResultVerifier
argument_list|)
block|{
return|return
name|matchAndVerifyResultConditionally
argument_list|(
name|Code
argument_list|,
name|AMatcher
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|FindResultVerifier
argument_list|)
argument_list|,
name|false
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Implements a run method that returns whether BoundNodes contains a
end_comment

begin_comment
comment|// Decl bound to Id that can be dynamically cast to T.
end_comment

begin_comment
comment|// Optionally checks that the check succeeded a specific number of times.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|VerifyIdIsBoundTo
operator|:
name|public
name|BoundNodesCallback
block|{
name|public
operator|:
comment|// Create an object that checks that a node of type \c T was bound to \c Id.
comment|// Does not check for a certain number of matches.
name|explicit
name|VerifyIdIsBoundTo
argument_list|(
argument|llvm::StringRef Id
argument_list|)
operator|:
name|Id
argument_list|(
name|Id
argument_list|)
block|,
name|ExpectedCount
argument_list|(
operator|-
literal|1
argument_list|)
block|,
name|Count
argument_list|(
literal|0
argument_list|)
block|{}
comment|// Create an object that checks that a node of type \c T was bound to \c Id.
comment|// Checks that there were exactly \c ExpectedCount matches.
name|VerifyIdIsBoundTo
argument_list|(
argument|llvm::StringRef Id
argument_list|,
argument|int ExpectedCount
argument_list|)
operator|:
name|Id
argument_list|(
name|Id
argument_list|)
block|,
name|ExpectedCount
argument_list|(
name|ExpectedCount
argument_list|)
block|,
name|Count
argument_list|(
literal|0
argument_list|)
block|{}
comment|// Create an object that checks that a node of type \c T was bound to \c Id.
comment|// Checks that there was exactly one match with the name \c ExpectedName.
comment|// Note that \c T must be a NamedDecl for this to work.
name|VerifyIdIsBoundTo
argument_list|(
argument|llvm::StringRef Id
argument_list|,
argument|llvm::StringRef ExpectedName
argument_list|,
argument|int ExpectedCount =
literal|1
argument_list|)
operator|:
name|Id
argument_list|(
name|Id
argument_list|)
block|,
name|ExpectedCount
argument_list|(
name|ExpectedCount
argument_list|)
block|,
name|Count
argument_list|(
literal|0
argument_list|)
block|,
name|ExpectedName
argument_list|(
argument|ExpectedName
argument_list|)
block|{}
name|void
name|onEndOfTranslationUnit
argument_list|()
name|override
block|{
if|if
condition|(
name|ExpectedCount
operator|!=
operator|-
literal|1
condition|)
name|EXPECT_EQ
argument_list|(
name|ExpectedCount
argument_list|,
name|Count
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ExpectedName
operator|.
name|empty
argument_list|()
condition|)
name|EXPECT_EQ
argument_list|(
name|ExpectedName
argument_list|,
name|Name
argument_list|)
expr_stmt|;
name|Count
operator|=
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|Name
operator|.
name|clear
argument_list|()
expr_stmt|;
end_expr_stmt

begin_macro
unit|}    ~
name|VerifyIdIsBoundTo
argument_list|()
end_macro

begin_macro
name|override
end_macro

begin_block
block|{
name|EXPECT_EQ
argument_list|(
literal|0
argument_list|,
name|Count
argument_list|)
expr_stmt|;
name|EXPECT_EQ
argument_list|(
literal|""
argument_list|,
name|Name
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|bool
name|run
parameter_list|(
specifier|const
name|BoundNodes
modifier|*
name|Nodes
parameter_list|)
function|override
block|{
specifier|const
name|BoundNodes
operator|::
name|IDToNodeMap
operator|&
name|M
operator|=
name|Nodes
operator|->
name|getMap
argument_list|()
expr_stmt|;
if|if
condition|(
name|Nodes
operator|->
name|getNodeAs
operator|<
name|T
operator|>
operator|(
name|Id
operator|)
condition|)
block|{
operator|++
name|Count
expr_stmt|;
if|if
condition|(
specifier|const
name|NamedDecl
modifier|*
name|Named
init|=
name|Nodes
operator|->
name|getNodeAs
operator|<
name|NamedDecl
operator|>
operator|(
name|Id
operator|)
condition|)
block|{
name|Name
operator|=
name|Named
operator|->
name|getNameAsString
argument_list|()
expr_stmt|;
block|}
elseif|else
if|if
condition|(
specifier|const
name|NestedNameSpecifier
modifier|*
name|NNS
init|=
name|Nodes
operator|->
name|getNodeAs
operator|<
name|NestedNameSpecifier
operator|>
operator|(
name|Id
operator|)
condition|)
block|{
name|llvm
operator|::
name|raw_string_ostream
name|OS
argument_list|(
name|Name
argument_list|)
expr_stmt|;
name|NNS
operator|->
name|print
argument_list|(
name|OS
argument_list|,
name|PrintingPolicy
argument_list|(
name|LangOptions
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|BoundNodes
operator|::
name|IDToNodeMap
operator|::
name|const_iterator
name|I
operator|=
name|M
operator|.
name|find
argument_list|(
name|Id
argument_list|)
expr_stmt|;
name|EXPECT_NE
argument_list|(
name|M
operator|.
name|end
argument_list|()
argument_list|,
name|I
argument_list|)
expr_stmt|;
if|if
condition|(
name|I
operator|!=
name|M
operator|.
name|end
argument_list|()
condition|)
name|EXPECT_EQ
argument_list|(
name|Nodes
operator|->
name|getNodeAs
operator|<
name|T
operator|>
operator|(
name|Id
operator|)
argument_list|,
name|I
operator|->
name|second
operator|.
name|get
operator|<
name|T
operator|>
operator|(
operator|)
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
name|EXPECT_TRUE
argument_list|(
argument|M.count(Id) ==
literal|0
argument|||       M.find(Id)->second.template get<T>() == nullptr
argument_list|)
empty_stmt|;
return|return
name|false
return|;
block|}
end_function

begin_function
name|bool
name|run
parameter_list|(
specifier|const
name|BoundNodes
modifier|*
name|Nodes
parameter_list|,
name|ASTContext
modifier|*
name|Context
parameter_list|)
function|override
block|{
return|return
name|run
argument_list|(
name|Nodes
argument_list|)
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|std
operator|::
name|string
name|Id
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|int
name|ExpectedCount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Count
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|std
operator|::
name|string
name|ExpectedName
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|string
name|Name
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace ast_matchers
end_comment

begin_comment
unit|}
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_UNITTESTS_AST_MATCHERS_AST_MATCHERS_TEST_H
end_comment

end_unit

