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
file|"llvm/ADT/ArrayRef.h"
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
file|"llvm/Linker/Linker.h"
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
name|class
name|LLVMContext
decl_stmt|;
name|class
name|DiagnosticInfo
decl_stmt|;
name|class
name|GlobalValue
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
argument_list|()
expr_stmt|;
name|LTOCodeGenerator
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|LLVMContext
operator|>
name|Context
argument_list|)
expr_stmt|;
operator|~
name|LTOCodeGenerator
argument_list|()
expr_stmt|;
comment|// Merge given module, return true on success.
name|bool
name|addModule
parameter_list|(
name|struct
name|LTOModule
modifier|*
parameter_list|)
function_decl|;
comment|// Set the destination module.
name|void
name|setModule
parameter_list|(
name|struct
name|LTOModule
modifier|*
parameter_list|)
function_decl|;
name|void
name|setTargetOptions
parameter_list|(
name|TargetOptions
name|options
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
parameter_list|(
name|lto_codegen_model
parameter_list|)
function_decl|;
name|void
name|setCpu
parameter_list|(
specifier|const
name|char
modifier|*
name|mCpu
parameter_list|)
block|{
name|MCpu
operator|=
name|mCpu
expr_stmt|;
block|}
name|void
name|setAttr
parameter_list|(
specifier|const
name|char
modifier|*
name|mAttr
parameter_list|)
block|{
name|MAttr
operator|=
name|mAttr
expr_stmt|;
block|}
name|void
name|setOptLevel
parameter_list|(
name|unsigned
name|optLevel
parameter_list|)
block|{
name|OptLevel
operator|=
name|optLevel
expr_stmt|;
block|}
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
name|void
name|addMustPreserveSymbol
parameter_list|(
name|StringRef
name|sym
parameter_list|)
block|{
name|MustPreserveSymbols
index|[
name|sym
index|]
operator|=
literal|1
expr_stmt|;
block|}
comment|// To pass options to the driver and optimization passes. These options are
comment|// not necessarily for debugging purpose (The function name is misleading).
comment|// This function should be called before LTOCodeGenerator::compilexxx(),
comment|// and LTOCodeGenerator::writeMergedModules().
name|void
name|setCodeGenDebugOptions
parameter_list|(
specifier|const
name|char
modifier|*
name|opts
parameter_list|)
function_decl|;
comment|// Parse the options set in setCodeGenDebugOptions. Like
comment|// setCodeGenDebugOptions, this must be called before
comment|// LTOCodeGenerator::compilexxx() and LTOCodeGenerator::writeMergedModules()
name|void
name|parseCodeGenDebugOptions
parameter_list|()
function_decl|;
comment|// Write the merged module to the file specified by the given path.
comment|// Return true on success.
name|bool
name|writeMergedModules
argument_list|(
specifier|const
name|char
operator|*
name|path
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
comment|// Compile the merged module into a *single* object file; the path to object
comment|// file is returned to the caller via argument "name". Return true on
comment|// success.
comment|//
comment|// NOTE that it is up to the linker to remove the intermediate object file.
comment|//  Do not try to remove the object file in LTOCodeGenerator's destructor
comment|//  as we don't who (LTOCodeGenerator or the obj file) will last longer.
name|bool
name|compile_to_file
argument_list|(
specifier|const
name|char
operator|*
operator|*
name|name
argument_list|,
name|bool
name|disableInline
argument_list|,
name|bool
name|disableGVNLoadPRE
argument_list|,
name|bool
name|disableVectorization
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
comment|// As with compile_to_file(), this function compiles the merged module into
comment|// single object file. Instead of returning the object-file-path to the caller
comment|// (linker), it brings the object to a buffer, and return the buffer to the
comment|// caller. This function should delete intermediate object file once its content
comment|// is brought to memory. Return NULL if the compilation was not successful.
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|compile
argument_list|(
argument|bool disableInline
argument_list|,
argument|bool disableGVNLoadPRE
argument_list|,
argument|bool disableVectorization
argument_list|,
argument|std::string&errMsg
argument_list|)
expr_stmt|;
comment|// Optimizes the merged module. Returns true on success.
name|bool
name|optimize
argument_list|(
name|bool
name|disableInline
argument_list|,
name|bool
name|disableGVNLoadPRE
argument_list|,
name|bool
name|disableVectorization
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
comment|// Compiles the merged optimized module into a single object file. It brings
comment|// the object to a buffer, and returns the buffer to the caller. Return NULL
comment|// if the compilation was not successful.
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|compileOptimized
argument_list|(
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
expr_stmt|;
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
name|private
label|:
name|void
name|initializeLTOPasses
parameter_list|()
function_decl|;
name|bool
name|compileOptimized
argument_list|(
name|raw_pwrite_stream
operator|&
name|out
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
name|bool
name|compileOptimizedToFile
argument_list|(
specifier|const
name|char
operator|*
operator|*
name|name
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
name|void
name|applyScopeRestrictions
parameter_list|()
function_decl|;
name|void
name|applyRestriction
argument_list|(
name|GlobalValue
operator|&
name|GV
argument_list|,
name|ArrayRef
operator|<
name|StringRef
operator|>
name|Libcalls
argument_list|,
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|MustPreserveList
argument_list|,
name|SmallPtrSetImpl
operator|<
name|GlobalValue
operator|*
operator|>
operator|&
name|AsmUsed
argument_list|,
name|Mangler
operator|&
name|Mangler
argument_list|)
decl_stmt|;
name|bool
name|determineTarget
argument_list|(
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
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
typedef|typedef
name|StringMap
operator|<
name|uint8_t
operator|>
name|StringSet
expr_stmt|;
name|void
name|destroyMergedModule
parameter_list|()
function_decl|;
name|std
operator|::
name|unique_ptr
operator|<
name|LLVMContext
operator|>
name|OwnedContext
expr_stmt|;
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
name|Linker
name|IRLinker
decl_stmt|;
name|TargetMachine
modifier|*
name|TargetMach
init|=
name|nullptr
decl_stmt|;
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
name|lto_codegen_model
name|CodeModel
init|=
name|LTO_CODEGEN_PIC_MODEL_DEFAULT
decl_stmt|;
name|StringSet
name|MustPreserveSymbols
decl_stmt|;
name|StringSet
name|AsmUndefinedRefs
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|char
operator|*
operator|>
name|CodegenOptions
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
name|LTOModule
modifier|*
name|OwnedModule
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
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

