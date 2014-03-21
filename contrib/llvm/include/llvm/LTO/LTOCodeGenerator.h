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
name|LTO_CODE_GENERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LTO_CODE_GENERATOR_H
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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Linker.h"
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
block|}
end_decl_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// LTOCodeGenerator - C++ class which implements the opaque lto_code_gen_t
end_comment

begin_comment
comment|/// type.
end_comment

begin_comment
comment|///
end_comment

begin_struct
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
operator|~
name|LTOCodeGenerator
argument_list|()
expr_stmt|;
comment|// Merge given module, return true on success.
name|bool
name|addModule
argument_list|(
expr|struct
name|LTOModule
operator|*
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
name|void
name|setTargetOptions
argument_list|(
name|llvm
operator|::
name|TargetOptions
name|options
argument_list|)
decl_stmt|;
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
name|addMustPreserveSymbol
parameter_list|(
specifier|const
name|char
modifier|*
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
comment|//
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
comment|//
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
name|disableOpt
argument_list|,
name|bool
name|disableInline
argument_list|,
name|bool
name|disableGVNLoadPRE
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
comment|//
specifier|const
name|void
modifier|*
name|compile
argument_list|(
name|size_t
operator|*
name|length
argument_list|,
name|bool
name|disableOpt
argument_list|,
name|bool
name|disableInline
argument_list|,
name|bool
name|disableGVNLoadPRE
argument_list|,
name|std
operator|::
name|string
operator|&
name|errMsg
argument_list|)
decl_stmt|;
name|private
label|:
name|void
name|initializeLTOPasses
parameter_list|()
function_decl|;
name|bool
name|generateObjectFile
argument_list|(
name|llvm
operator|::
name|raw_ostream
operator|&
name|out
argument_list|,
name|bool
name|disableOpt
argument_list|,
name|bool
name|disableInline
argument_list|,
name|bool
name|disableGVNLoadPRE
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
name|llvm
operator|::
name|GlobalValue
operator|&
name|GV
argument_list|,
specifier|const
name|llvm
operator|::
name|ArrayRef
operator|<
name|llvm
operator|::
name|StringRef
operator|>
operator|&
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
name|llvm
operator|::
name|SmallPtrSet
operator|<
name|llvm
operator|::
name|GlobalValue
operator|*
argument_list|,
literal|8
operator|>
operator|&
name|AsmUsed
argument_list|,
name|llvm
operator|::
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
typedef|typedef
name|llvm
operator|::
name|StringMap
operator|<
name|uint8_t
operator|>
name|StringSet
expr_stmt|;
name|llvm
operator|::
name|LLVMContext
operator|&
name|Context
expr_stmt|;
name|llvm
operator|::
name|Linker
name|Linker
expr_stmt|;
name|llvm
operator|::
name|TargetMachine
operator|*
name|TargetMach
expr_stmt|;
name|bool
name|EmitDwarfDebugInfo
decl_stmt|;
name|bool
name|ScopeRestrictionsDone
decl_stmt|;
name|lto_codegen_model
name|CodeModel
decl_stmt|;
name|StringSet
name|MustPreserveSymbols
decl_stmt|;
name|StringSet
name|AsmUndefinedRefs
decl_stmt|;
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|NativeObjectFile
expr_stmt|;
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
name|NativeObjectPath
expr_stmt|;
name|llvm
operator|::
name|TargetOptions
name|Options
expr_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LTO_CODE_GENERATOR_H
end_comment

end_unit

