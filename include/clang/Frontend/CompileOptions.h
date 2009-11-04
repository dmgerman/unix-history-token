begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CompileOptions.h ---------------------------------------*- C++ -*-===//
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
comment|//  This file defines the CompileOptions interface.
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
name|LLVM_CLANG_FRONTEND_COMPILEOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_COMPILEOPTIONS_H
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
comment|/// CompileOptions - Track various options which control how the code
comment|/// is optimized and passed to the backend.
name|class
name|CompileOptions
block|{
name|public
label|:
enum|enum
name|InliningMethod
block|{
name|NoInlining
block|,
comment|// Perform no inlining whatsoever.
name|NormalInlining
block|,
comment|// Use the standard function inlining pass.
name|OnlyAlwaysInlining
comment|// Only run the always inlining pass.
block|}
enum|;
name|unsigned
name|OptimizationLevel
range|:
literal|3
decl_stmt|;
comment|/// The -O[0-4] option specified.
name|unsigned
name|OptimizeSize
range|:
literal|1
decl_stmt|;
comment|/// If -Os is specified.
name|unsigned
name|DebugInfo
range|:
literal|1
decl_stmt|;
comment|/// Should generate deubg info (-g).
name|unsigned
name|UnitAtATime
range|:
literal|1
decl_stmt|;
comment|/// Unused. For mirroring GCC
comment|/// optimization selection.
name|unsigned
name|SimplifyLibCalls
range|:
literal|1
decl_stmt|;
comment|/// Should standard library calls be
comment|/// treated specially.
name|unsigned
name|UnrollLoops
range|:
literal|1
decl_stmt|;
comment|/// Control whether loops are unrolled.
name|unsigned
name|VerifyModule
range|:
literal|1
decl_stmt|;
comment|/// Control whether the module
comment|/// should be run through the LLVM Verifier.
name|unsigned
name|TimePasses
range|:
literal|1
decl_stmt|;
comment|/// Set when -ftime-report is enabled.
name|unsigned
name|NoCommon
range|:
literal|1
decl_stmt|;
comment|/// Set when -fno-common or C++ is enabled.
name|unsigned
name|DisableRedZone
range|:
literal|1
decl_stmt|;
comment|/// Set when -mno-red-zone is enabled.
name|unsigned
name|NoImplicitFloat
range|:
literal|1
decl_stmt|;
comment|/// Set when -mno-implicit-float is enabled.
name|unsigned
name|MergeAllConstants
range|:
literal|1
decl_stmt|;
comment|// Merge identical constants.
comment|/// Inlining - The kind of inlining to perform.
name|InliningMethod
name|Inlining
decl_stmt|;
comment|/// CPU - An optional CPU to target.
name|std
operator|::
name|string
name|CPU
expr_stmt|;
comment|/// Features - A list of subtarget features to pass to the code
comment|/// generator.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Features
expr_stmt|;
name|public
label|:
name|CompileOptions
argument_list|()
block|{
name|OptimizationLevel
operator|=
literal|0
expr_stmt|;
name|OptimizeSize
operator|=
literal|0
expr_stmt|;
name|DebugInfo
operator|=
literal|0
expr_stmt|;
name|UnitAtATime
operator|=
literal|1
expr_stmt|;
name|SimplifyLibCalls
operator|=
name|UnrollLoops
operator|=
literal|0
expr_stmt|;
name|VerifyModule
operator|=
literal|1
expr_stmt|;
name|TimePasses
operator|=
literal|0
expr_stmt|;
name|NoCommon
operator|=
literal|0
expr_stmt|;
name|Inlining
operator|=
name|NoInlining
expr_stmt|;
name|DisableRedZone
operator|=
literal|0
expr_stmt|;
name|NoImplicitFloat
operator|=
literal|0
expr_stmt|;
name|MergeAllConstants
operator|=
literal|1
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

