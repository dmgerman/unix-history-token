begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CodeGenOptions.h ---------------------------------------*- C++ -*-===//
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
comment|//  This file defines the CodeGenOptions interface.
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
name|LLVM_CLANG_CODEGEN_CODEGENOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CODEGEN_CODEGENOPTIONS_H
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
comment|/// CodeGenOptions - Track various options which control how the code
comment|/// is optimized and passed to the backend.
name|class
name|CodeGenOptions
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
name|AsmVerbose
range|:
literal|1
decl_stmt|;
comment|/// -dA, -fverbose-asm.
name|unsigned
name|DebugInfo
range|:
literal|1
decl_stmt|;
comment|/// Should generate deubg info (-g).
name|unsigned
name|DisableFPElim
range|:
literal|1
decl_stmt|;
comment|/// Set when -fomit-frame-pointer is enabled.
name|unsigned
name|DisableLLVMOpts
range|:
literal|1
decl_stmt|;
comment|/// Don't run any optimizations, for use in
comment|/// getting .bc files that correspond to the
comment|/// internal state before optimizations are
comment|/// done.
name|unsigned
name|DisableRedZone
range|:
literal|1
decl_stmt|;
comment|/// Set when -mno-red-zone is enabled.
name|unsigned
name|MergeAllConstants
range|:
literal|1
decl_stmt|;
comment|/// Merge identical constants.
name|unsigned
name|NoCommon
range|:
literal|1
decl_stmt|;
comment|/// Set when -fno-common or C++ is enabled.
name|unsigned
name|NoImplicitFloat
range|:
literal|1
decl_stmt|;
comment|/// Set when -mno-implicit-float is enabled.
name|unsigned
name|NoZeroInitializedInBSS
range|:
literal|1
decl_stmt|;
comment|/// -fno-zero-initialized-in-bss
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
name|SoftFloat
range|:
literal|1
decl_stmt|;
comment|/// -soft-float.
name|unsigned
name|TimePasses
range|:
literal|1
decl_stmt|;
comment|/// Set when -ftime-report is enabled.
name|unsigned
name|UnitAtATime
range|:
literal|1
decl_stmt|;
comment|/// Unused. For mirroring GCC optimization
comment|/// selection.
name|unsigned
name|UnrollLoops
range|:
literal|1
decl_stmt|;
comment|/// Control whether loops are unrolled.
name|unsigned
name|UnwindTables
range|:
literal|1
decl_stmt|;
comment|/// Emit unwind tables.
name|unsigned
name|VerifyModule
range|:
literal|1
decl_stmt|;
comment|/// Control whether the module should be run
comment|/// through the LLVM Verifier.
comment|/// The code model to use (-mcmodel).
name|std
operator|::
name|string
name|CodeModel
expr_stmt|;
comment|/// Enable additional debugging information.
name|std
operator|::
name|string
name|DebugPass
expr_stmt|;
comment|/// The string to embed in the debug information for the compile unit, if
comment|/// non-empty.
name|std
operator|::
name|string
name|DwarfDebugFlags
expr_stmt|;
comment|/// The ABI to use for passing floating point arguments.
name|std
operator|::
name|string
name|FloatABI
expr_stmt|;
comment|/// The float precision limit to use, if non-empty.
name|std
operator|::
name|string
name|LimitFloatPrecision
expr_stmt|;
comment|/// The kind of inlining to perform.
name|InliningMethod
name|Inlining
decl_stmt|;
comment|/// The user provided name for the "main file", if non-empty. This is useful
comment|/// in situations where the input file name does not match the original input
comment|/// file, for example with -save-temps.
name|std
operator|::
name|string
name|MainFileName
expr_stmt|;
comment|/// The name of the relocation model to use.
name|std
operator|::
name|string
name|RelocationModel
expr_stmt|;
name|public
label|:
name|CodeGenOptions
argument_list|()
block|{
name|AsmVerbose
operator|=
literal|0
expr_stmt|;
name|DebugInfo
operator|=
literal|0
expr_stmt|;
name|DisableFPElim
operator|=
literal|0
expr_stmt|;
name|DisableLLVMOpts
operator|=
literal|0
expr_stmt|;
name|DisableRedZone
operator|=
literal|0
expr_stmt|;
name|MergeAllConstants
operator|=
literal|1
expr_stmt|;
name|NoCommon
operator|=
literal|0
expr_stmt|;
name|NoImplicitFloat
operator|=
literal|0
expr_stmt|;
name|NoZeroInitializedInBSS
operator|=
literal|0
expr_stmt|;
name|OptimizationLevel
operator|=
literal|0
expr_stmt|;
name|OptimizeSize
operator|=
literal|0
expr_stmt|;
name|UnrollLoops
operator|=
literal|0
expr_stmt|;
name|SoftFloat
operator|=
literal|0
expr_stmt|;
name|TimePasses
operator|=
literal|0
expr_stmt|;
name|UnitAtATime
operator|=
literal|1
expr_stmt|;
name|UnwindTables
operator|=
literal|0
expr_stmt|;
name|VerifyModule
operator|=
literal|1
expr_stmt|;
name|Inlining
operator|=
name|NoInlining
expr_stmt|;
name|RelocationModel
operator|=
literal|"pic"
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

