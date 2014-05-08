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
name|LLVM_CLANG_FRONTEND_CODEGENOPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_CODEGENOPTIONS_H
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
comment|/// \brief Bitfields of CodeGenOptions, split out from CodeGenOptions to ensure
comment|/// that this large collection of bitfields is a trivial class type.
name|class
name|CodeGenOptionsBase
block|{
name|public
label|:
define|#
directive|define
name|CODEGENOPT
parameter_list|(
name|Name
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
value|unsigned Name : Bits;
define|#
directive|define
name|ENUM_CODEGENOPT
parameter_list|(
name|Name
parameter_list|,
name|Type
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
include|#
directive|include
file|"clang/Frontend/CodeGenOptions.def"
name|protected
label|:
define|#
directive|define
name|CODEGENOPT
parameter_list|(
name|Name
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
define|#
directive|define
name|ENUM_CODEGENOPT
parameter_list|(
name|Name
parameter_list|,
name|Type
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
value|unsigned Name : Bits;
include|#
directive|include
file|"clang/Frontend/CodeGenOptions.def"
block|}
empty_stmt|;
comment|/// CodeGenOptions - Track various options which control how the code
comment|/// is optimized and passed to the backend.
name|class
name|CodeGenOptions
range|:
name|public
name|CodeGenOptionsBase
block|{
name|public
operator|:
expr|enum
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
block|;    enum
name|ObjCDispatchMethodKind
block|{
name|Legacy
operator|=
literal|0
block|,
name|NonLegacy
operator|=
literal|1
block|,
name|Mixed
operator|=
literal|2
block|}
block|;    enum
name|DebugInfoKind
block|{
name|NoDebugInfo
block|,
comment|/// Don't generate debug info.
name|DebugLineTablesOnly
block|,
comment|/// Emit only debug info necessary for generating
comment|/// line number tables (-gline-tables-only).
name|LimitedDebugInfo
block|,
comment|/// Limit generated debug info to reduce size
comment|/// (-fno-standalone-debug). This emits
comment|/// forward decls for types that could be
comment|/// replaced with forward decls in the source
comment|/// code. For dynamic C++ classes type info
comment|/// is only emitted int the module that
comment|/// contains the classe's vtable.
name|FullDebugInfo
comment|/// Generate complete debug info.
block|}
block|;    enum
name|TLSModel
block|{
name|GeneralDynamicTLSModel
block|,
name|LocalDynamicTLSModel
block|,
name|InitialExecTLSModel
block|,
name|LocalExecTLSModel
block|}
block|;    enum
name|FPContractModeKind
block|{
name|FPC_Off
block|,
comment|// Form fused FP ops only where result will not be affected.
name|FPC_On
block|,
comment|// Form fused FP ops according to FP_CONTRACT rules.
name|FPC_Fast
comment|// Aggressively fuse FP ops (E.g. FMA).
block|}
block|;    enum
name|StructReturnConventionKind
block|{
name|SRCK_Default
block|,
comment|// No special option was passed.
name|SRCK_OnStack
block|,
comment|// Small structs on the stack (-fpcc-struct-return).
name|SRCK_InRegs
comment|// Small structs in registers (-freg-struct-return).
block|}
block|;
comment|/// The code model to use (-mcmodel).
name|std
operator|::
name|string
name|CodeModel
block|;
comment|/// The filename with path we use for coverage files. The extension will be
comment|/// replaced.
name|std
operator|::
name|string
name|CoverageFile
block|;
comment|/// The version string to put into coverage files.
name|char
name|CoverageVersion
index|[
literal|4
index|]
block|;
comment|/// Enable additional debugging information.
name|std
operator|::
name|string
name|DebugPass
block|;
comment|/// The string to embed in debug information as the current working directory.
name|std
operator|::
name|string
name|DebugCompilationDir
block|;
comment|/// The string to embed in the debug information for the compile unit, if
comment|/// non-empty.
name|std
operator|::
name|string
name|DwarfDebugFlags
block|;
comment|/// The ABI to use for passing floating point arguments.
name|std
operator|::
name|string
name|FloatABI
block|;
comment|/// The float precision limit to use, if non-empty.
name|std
operator|::
name|string
name|LimitFloatPrecision
block|;
comment|/// The name of the bitcode file to link before optzns.
name|std
operator|::
name|string
name|LinkBitcodeFile
block|;
comment|/// The user provided name for the "main file", if non-empty. This is useful
comment|/// in situations where the input file name does not match the original input
comment|/// file, for example with -save-temps.
name|std
operator|::
name|string
name|MainFileName
block|;
comment|/// The name for the split debug info file that we'll break out. This is used
comment|/// in the backend for setting the name in the skeleton cu.
name|std
operator|::
name|string
name|SplitDwarfFile
block|;
comment|/// The name of the relocation model to use.
name|std
operator|::
name|string
name|RelocationModel
block|;
comment|/// Path to blacklist file for sanitizers.
name|std
operator|::
name|string
name|SanitizerBlacklistFile
block|;
comment|/// If not an empty string, trap intrinsics are lowered to calls to this
comment|/// function instead of to trap instructions.
name|std
operator|::
name|string
name|TrapFuncName
block|;
comment|/// A list of command-line options to forward to the LLVM backend.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|BackendOptions
block|;
comment|/// A list of dependent libraries.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|DependentLibraries
block|;
comment|/// Name of the profile file to use with -fprofile-sample-use.
name|std
operator|::
name|string
name|SampleProfileFile
block|;
name|public
operator|:
comment|// Define accessors/mutators for code generation options of enumeration type.
define|#
directive|define
name|CODEGENOPT
parameter_list|(
name|Name
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
define|#
directive|define
name|ENUM_CODEGENOPT
parameter_list|(
name|Name
parameter_list|,
name|Type
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
define|\
value|Type get##Name() const { return static_cast<Type>(Name); } \   void set##Name(Type Value) { Name = static_cast<unsigned>(Value); }
include|#
directive|include
file|"clang/Frontend/CodeGenOptions.def"
name|CodeGenOptions
argument_list|()
block|{
define|#
directive|define
name|CODEGENOPT
parameter_list|(
name|Name
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
value|Name = Default;
define|#
directive|define
name|ENUM_CODEGENOPT
parameter_list|(
name|Name
parameter_list|,
name|Type
parameter_list|,
name|Bits
parameter_list|,
name|Default
parameter_list|)
define|\
value|set##Name(Default);
include|#
directive|include
file|"clang/Frontend/CodeGenOptions.def"
name|RelocationModel
operator|=
literal|"pic"
block|;
name|memcpy
argument_list|(
name|CoverageVersion
argument_list|,
literal|"402*"
argument_list|,
literal|4
argument_list|)
block|;   }
block|}
decl_stmt|;
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

