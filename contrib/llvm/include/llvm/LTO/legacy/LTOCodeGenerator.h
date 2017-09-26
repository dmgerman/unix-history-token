begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-LTOCodeGenerator.h - LLVM Link Time Optimizer -----------------------===//
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
comment|// This file declares the LTOCodeGenerator class.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   LTO compilation consists of three phases: Pre-IPO, IPO and Post-IPO.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   The Pre-IPO phase compiles source code into bitcode file. The resulting
end_comment

begin_comment
comment|// bitcode files, along with object files and libraries, will be fed to the
end_comment

begin_comment
comment|// linker to through the IPO and Post-IPO phases. By using obj-file extension,
end_comment

begin_comment
comment|// the resulting bitcode file disguises itself as an object file, and therefore
end_comment

begin_comment
comment|// obviates the need of writing a special set of the make-rules only for LTO
end_comment

begin_comment
comment|// compilation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   The IPO phase perform inter-procedural analyses and optimizations, and
end_comment

begin_comment
comment|// the Post-IPO consists two sub-phases: intra-procedural scalar optimizations
end_comment

begin_comment
comment|// (SOPT), and intra-procedural target-dependent code generator (CG).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   As of this writing, we don't separate IPO and the Post-IPO SOPT. They
end_comment

begin_comment
comment|// are intermingled together, and are driven by a single pass manager (see
end_comment

begin_comment
comment|// PassManagerBuilder::populateLTOPassManager()).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   The "LTOCodeGenerator" is the driver for the IPO and Post-IPO stages.
end_comment

begin_comment
comment|// The "CodeGenerator" here is bit confusing. Don't confuse the "CodeGenerator"
end_comment

begin_comment
comment|// with the machine specific code generator.
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
name|LLVM_LTO_LTOCODEGENERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LTO_LTOCODEGENERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/lto.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalValue.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Module.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ToolOutputFile.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetMachine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOptions.h"
end_include

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
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|DiagnosticInfo
decl_stmt|;
name|class
name|Linker
decl_stmt|;
name|class
name|Mangler
decl_stmt|;
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|/// C++ class which implements the opaque lto_code_gen_t type.
comment|///
struct|struct
name|LTOCodeGenerator
block|{
specifier|static
specifier|const
name|char
modifier|*
name|getVersionString
parameter_list|()
function_decl|;
name|LTOCodeGenerator
argument_list|(
name|LLVMContext
operator|&
name|Context
argument_list|)
expr_stmt|;
operator|~
name|LTOCodeGenerator
argument_list|()
expr_stmt|;
comment|/// Merge given module.  Return true on success.
comment|///
comment|/// Resets \a HasVerifiedInput.
name|bool
name|addModule
parameter_list|(
name|struct
name|LTOModule
modifier|*
parameter_list|)
function_decl|;
comment|/// Set the destination module.
comment|///
comment|/// Resets \a HasVerifiedInput.
name|void
name|setModule
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|LTOModule
operator|>
name|M
argument_list|)
decl_stmt|;
name|void
name|setAsmUndefinedRefs
parameter_list|(
name|struct
name|LTOModule
modifier|*
parameter_list|)
function_decl|;
name|void
name|setTargetOptions
parameter_list|(
specifier|const
name|TargetOptions
modifier|&
name|Options
parameter_list|)
function_decl|;
name|void
name|setDebugInfo
parameter_list|(
name|lto_debug_model
parameter_list|)
function_decl|;
name|void
name|setCodePICModel
argument_list|(
name|Optional
operator|<
name|Reloc
operator|::
name|Model
operator|>
name|Model
argument_list|)
block|{
name|RelocModel
operator|=
name|Model
expr_stmt|;
block|}
comment|/// Set the file type to be emitted (assembly or object code).
comment|/// The default is TargetMachine::CGFT_ObjectFile.
name|void
name|setFileType
argument_list|(
name|TargetMachine
operator|::
name|CodeGenFileType
name|FT
argument_list|)
block|{
name|FileType
operator|=
name|FT
expr_stmt|;
block|}
name|void
name|setCpu
parameter_list|(
name|StringRef
name|MCpu
parameter_list|)
block|{
name|this
operator|->
name|MCpu
operator|=
name|MCpu
expr_stmt|;
block|}
name|void
name|setAttr
parameter_list|(
name|StringRef
name|MAttr
parameter_list|)
block|{
name|this
operator|->
name|MAttr
operator|=
name|MAttr
expr_stmt|;
block|}
name|void
name|setOptLevel
parameter_list|(
name|unsigned
name|OptLevel
parameter_list|)
function_decl|;
name|void
name|setShouldInternalize
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|ShouldInternalize
operator|=
name|Value
expr_stmt|;
block|}
name|void
name|setShouldEmbedUselists
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|ShouldEmbedUselists
operator|=
name|Value
expr_stmt|;
block|}
comment|/// Restore linkage of globals
comment|///
comment|/// When set, the linkage of globals will be restored prior to code
comment|/// generation. That is, a global symbol that had external linkage prior to
comment|/// LTO will be emitted with external linkage again; and a local will remain
comment|/// local. Note that this option only affects the end result - globals may
comment|/// still be internalized in the process of LTO and may be modified and/or
comment|/// deleted where legal.
comment|///
comment|/// The default behavior will internalize globals (unless on the preserve
comment|/// list) and, if parallel code generation is enabled, will externalize
comment|/// all locals.
name|void
name|setShouldRestoreGlobalsLinkage
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|ShouldRestoreGlobalsLinkage
operator|=
name|Value
expr_stmt|;
block|}
name|void
name|addMustPreserveSymbol
parameter_list|(
name|StringRef
name|Sym
parameter_list|)
block|{
name|MustPreserveSymbols
index|[
name|Sym
index|]
operator|=
literal|1
expr_stmt|;
block|}
comment|/// Pass options to the driver and optimization passes.
comment|///
comment|/// These options are not necessarily for debugging purpose (the function
comment|/// name is misleading).  This function should be called before
comment|/// LTOCodeGenerator::compilexxx(), and
comment|/// LTOCodeGenerator::writeMergedModules().
name|void
name|setCodeGenDebugOptions
parameter_list|(
name|StringRef
name|Opts
parameter_list|)
function_decl|;
comment|/// Parse the options set in setCodeGenDebugOptions.
comment|///
comment|/// Like \a setCodeGenDebugOptions(), this must be called before
comment|/// LTOCodeGenerator::compilexxx() and
comment|/// LTOCodeGenerator::writeMergedModules().
name|void
name|parseCodeGenDebugOptions
parameter_list|()
function_decl|;
comment|/// Write the merged module to the file specified by the given path.  Return
comment|/// true on success.
comment|///
comment|/// Calls \a verifyMergedModuleOnce().
name|bool
name|writeMergedModules
parameter_list|(
name|StringRef
name|Path
parameter_list|)
function_decl|;
comment|/// Compile the merged module into a *single* output file; the path to output
comment|/// file is returned to the caller via argument "name". Return true on
comment|/// success.
comment|///
comment|/// \note It is up to the linker to remove the intermediate output file.  Do
comment|/// not try to remove the object file in LTOCodeGenerator's destructor as we
comment|/// don't who (LTOCodeGenerator or the output file) will last longer.
name|bool
name|compile_to_file
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|Name
parameter_list|,
name|bool
name|DisableVerify
parameter_list|,
name|bool
name|DisableInline
parameter_list|,
name|bool
name|DisableGVNLoadPRE
parameter_list|,
name|bool
name|DisableVectorization
parameter_list|)
function_decl|;
comment|/// As with compile_to_file(), this function compiles the merged module into
comment|/// single output file. Instead of returning the output file path to the
comment|/// caller (linker), it brings the output to a buffer, and returns the buffer
comment|/// to the caller. This function should delete the intermediate file once
comment|/// its content is brought to memory. Return NULL if the compilation was not
comment|/// successful.
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|compile
argument_list|(
argument|bool DisableVerify
argument_list|,
argument|bool DisableInline
argument_list|,
argument|bool DisableGVNLoadPRE
argument_list|,
argument|bool DisableVectorization
argument_list|)
expr_stmt|;
comment|/// Optimizes the merged module.  Returns true on success.
comment|///
comment|/// Calls \a verifyMergedModuleOnce().
name|bool
name|optimize
parameter_list|(
name|bool
name|DisableVerify
parameter_list|,
name|bool
name|DisableInline
parameter_list|,
name|bool
name|DisableGVNLoadPRE
parameter_list|,
name|bool
name|DisableVectorization
parameter_list|)
function_decl|;
comment|/// Compiles the merged optimized module into a single output file. It brings
comment|/// the output to a buffer, and returns the buffer to the caller. Return NULL
comment|/// if the compilation was not successful.
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|compileOptimized
argument_list|()
expr_stmt|;
comment|/// Compile the merged optimized module into out.size() output files each
comment|/// representing a linkable partition of the module. If out contains more
comment|/// than one element, code generation is done in parallel with out.size()
comment|/// threads.  Output files will be written to members of out. Returns true on
comment|/// success.
comment|///
comment|/// Calls \a verifyMergedModuleOnce().
name|bool
name|compileOptimized
argument_list|(
name|ArrayRef
operator|<
name|raw_pwrite_stream
operator|*
operator|>
name|Out
argument_list|)
decl_stmt|;
comment|/// Enable the Freestanding mode: indicate that the optimizer should not
comment|/// assume builtins are present on the target.
name|void
name|setFreestanding
parameter_list|(
name|bool
name|Enabled
parameter_list|)
block|{
name|Freestanding
operator|=
name|Enabled
expr_stmt|;
block|}
name|void
name|setDiagnosticHandler
parameter_list|(
name|lto_diagnostic_handler_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|LLVMContext
modifier|&
name|getContext
parameter_list|()
block|{
return|return
name|Context
return|;
block|}
name|void
name|resetMergedModule
parameter_list|()
block|{
name|MergedModule
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
name|private
label|:
name|void
name|initializeLTOPasses
parameter_list|()
function_decl|;
comment|/// Verify the merged module on first call.
comment|///
comment|/// Sets \a HasVerifiedInput on first call and doesn't run again on the same
comment|/// input.
name|void
name|verifyMergedModuleOnce
parameter_list|()
function_decl|;
name|bool
name|compileOptimizedToFile
parameter_list|(
specifier|const
name|char
modifier|*
modifier|*
name|Name
parameter_list|)
function_decl|;
name|void
name|restoreLinkageForExternals
parameter_list|()
function_decl|;
name|void
name|applyScopeRestrictions
parameter_list|()
function_decl|;
name|void
name|preserveDiscardableGVs
argument_list|(
name|Module
operator|&
name|TheModule
argument_list|,
name|llvm
operator|::
name|function_ref
operator|<
name|bool
argument_list|(
specifier|const
name|GlobalValue
operator|&
argument_list|)
operator|>
name|mustPreserveGV
argument_list|)
decl_stmt|;
name|bool
name|determineTarget
parameter_list|()
function_decl|;
name|std
operator|::
name|unique_ptr
operator|<
name|TargetMachine
operator|>
name|createTargetMachine
argument_list|()
expr_stmt|;
specifier|static
name|void
name|DiagnosticHandler
parameter_list|(
specifier|const
name|DiagnosticInfo
modifier|&
name|DI
parameter_list|,
name|void
modifier|*
name|Context
parameter_list|)
function_decl|;
name|void
name|DiagnosticHandler2
parameter_list|(
specifier|const
name|DiagnosticInfo
modifier|&
name|DI
parameter_list|)
function_decl|;
name|void
name|emitError
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|ErrMsg
argument_list|)
decl_stmt|;
name|void
name|emitWarning
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|ErrMsg
argument_list|)
decl_stmt|;
name|void
name|finishOptimizationRemarks
parameter_list|()
function_decl|;
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|MergedModule
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Linker
operator|>
name|TheLinker
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|TargetMachine
operator|>
name|TargetMach
expr_stmt|;
name|bool
name|EmitDwarfDebugInfo
init|=
name|false
decl_stmt|;
name|bool
name|ScopeRestrictionsDone
init|=
name|false
decl_stmt|;
name|bool
name|HasVerifiedInput
init|=
name|false
decl_stmt|;
name|Optional
operator|<
name|Reloc
operator|::
name|Model
operator|>
name|RelocModel
expr_stmt|;
name|StringSet
operator|<
operator|>
name|MustPreserveSymbols
expr_stmt|;
name|StringSet
operator|<
operator|>
name|AsmUndefinedRefs
expr_stmt|;
name|StringMap
operator|<
name|GlobalValue
operator|::
name|LinkageTypes
operator|>
name|ExternalSymbols
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|CodegenOptions
expr_stmt|;
name|std
operator|::
name|string
name|FeatureStr
expr_stmt|;
name|std
operator|::
name|string
name|MCpu
expr_stmt|;
name|std
operator|::
name|string
name|MAttr
expr_stmt|;
name|std
operator|::
name|string
name|NativeObjectPath
expr_stmt|;
name|TargetOptions
name|Options
decl_stmt|;
name|CodeGenOpt
operator|::
name|Level
name|CGOptLevel
operator|=
name|CodeGenOpt
operator|::
name|Default
expr_stmt|;
specifier|const
name|Target
modifier|*
name|MArch
init|=
name|nullptr
decl_stmt|;
name|std
operator|::
name|string
name|TripleStr
expr_stmt|;
name|unsigned
name|OptLevel
init|=
literal|2
decl_stmt|;
name|lto_diagnostic_handler_t
name|DiagHandler
init|=
name|nullptr
decl_stmt|;
name|void
modifier|*
name|DiagContext
init|=
name|nullptr
decl_stmt|;
name|bool
name|ShouldInternalize
init|=
name|true
decl_stmt|;
name|bool
name|ShouldEmbedUselists
init|=
name|false
decl_stmt|;
name|bool
name|ShouldRestoreGlobalsLinkage
init|=
name|false
decl_stmt|;
name|TargetMachine
operator|::
name|CodeGenFileType
name|FileType
operator|=
name|TargetMachine
operator|::
name|CGFT_ObjectFile
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|tool_output_file
operator|>
name|DiagnosticOutputFile
expr_stmt|;
name|bool
name|Freestanding
init|=
name|false
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

