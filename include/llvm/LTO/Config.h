begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-Config.h - LLVM Link Time Optimizer Configuration -------------------===//
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
comment|// This file defines the lto::Config data structure, which allows clients to
end_comment

begin_comment
comment|// configure LTO.
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
name|LLVM_LTO_CONFIG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LTO_CONFIG_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
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
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Error
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|ModuleSummaryIndex
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
name|namespace
name|lto
block|{
comment|/// LTO configuration. A linker can configure LTO by setting fields in this data
comment|/// structure and passing it to the lto::LTO constructor.
struct|struct
name|Config
block|{
comment|// Note: when adding fields here, consider whether they need to be added to
comment|// computeCacheKey in LTO.cpp.
name|std
operator|::
name|string
name|CPU
expr_stmt|;
name|TargetOptions
name|Options
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|MAttrs
expr_stmt|;
name|Reloc
operator|::
name|Model
name|RelocModel
operator|=
name|Reloc
operator|::
name|PIC_
expr_stmt|;
name|CodeModel
operator|::
name|Model
name|CodeModel
operator|=
name|CodeModel
operator|::
name|Default
expr_stmt|;
name|CodeGenOpt
operator|::
name|Level
name|CGOptLevel
operator|=
name|CodeGenOpt
operator|::
name|Default
expr_stmt|;
name|TargetMachine
operator|::
name|CodeGenFileType
name|CGFileType
operator|=
name|TargetMachine
operator|::
name|CGFT_ObjectFile
expr_stmt|;
name|unsigned
name|OptLevel
init|=
literal|2
decl_stmt|;
name|bool
name|DisableVerify
init|=
name|false
decl_stmt|;
comment|/// Disable entirely the optimizer, including importing for ThinLTO
name|bool
name|CodeGenOnly
init|=
name|false
decl_stmt|;
comment|/// If this field is set, the set of passes run in the middle-end optimizer
comment|/// will be the one specified by the string. Only works with the new pass
comment|/// manager as the old one doesn't have this ability.
name|std
operator|::
name|string
name|OptPipeline
expr_stmt|;
comment|// If this field is set, it has the same effect of specifying an AA pipeline
comment|// identified by the string. Only works with the new pass manager, in
comment|// conjunction OptPipeline.
name|std
operator|::
name|string
name|AAPipeline
expr_stmt|;
comment|/// Setting this field will replace target triples in input files with this
comment|/// triple.
name|std
operator|::
name|string
name|OverrideTriple
expr_stmt|;
comment|/// Setting this field will replace unspecified target triples in input files
comment|/// with this triple.
name|std
operator|::
name|string
name|DefaultTriple
expr_stmt|;
comment|/// Sample PGO profile path.
name|std
operator|::
name|string
name|SampleProfile
expr_stmt|;
comment|/// Optimization remarks file path.
name|std
operator|::
name|string
name|RemarksFilename
operator|=
literal|""
expr_stmt|;
comment|/// Whether to emit optimization remarks with hotness informations.
name|bool
name|RemarksWithHotness
init|=
name|false
decl_stmt|;
name|bool
name|ShouldDiscardValueNames
init|=
name|true
decl_stmt|;
name|DiagnosticHandlerFunction
name|DiagHandler
decl_stmt|;
comment|/// If this field is set, LTO will write input file paths and symbol
comment|/// resolutions here in llvm-lto2 command line flag format. This can be
comment|/// used for testing and for running the LTO pipeline outside of the linker
comment|/// with llvm-lto2.
name|std
operator|::
name|unique_ptr
operator|<
name|raw_ostream
operator|>
name|ResolutionFile
expr_stmt|;
comment|/// The following callbacks deal with tasks, which normally represent the
comment|/// entire optimization and code generation pipeline for what will become a
comment|/// single native object file. Each task has a unique identifier between 0 and
comment|/// getMaxTasks()-1, which is supplied to the callback via the Task parameter.
comment|/// A task represents the entire pipeline for ThinLTO and regular
comment|/// (non-parallel) LTO, but a parallel code generation task will be split into
comment|/// N tasks before code generation, where N is the parallelism level.
comment|///
comment|/// LTO may decide to stop processing a task at any time, for example if the
comment|/// module is empty or if a module hook (see below) returns false. For this
comment|/// reason, the client should not expect to receive exactly getMaxTasks()
comment|/// native object files.
comment|/// A module hook may be used by a linker to perform actions during the LTO
comment|/// pipeline. For example, a linker may use this function to implement
comment|/// -save-temps. If this function returns false, any further processing for
comment|/// that task is aborted.
comment|///
comment|/// Module hooks must be thread safe with respect to the linker's internal
comment|/// data structures. A module hook will never be called concurrently from
comment|/// multiple threads with the same task ID, or the same module.
comment|///
comment|/// Note that in out-of-process backend scenarios, none of the hooks will be
comment|/// called for ThinLTO tasks.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
argument|unsigned Task
argument_list|,
argument|const Module&
argument_list|)
operator|>
name|ModuleHookFn
expr_stmt|;
comment|/// This module hook is called after linking (regular LTO) or loading
comment|/// (ThinLTO) the module, before modifying it.
name|ModuleHookFn
name|PreOptModuleHook
decl_stmt|;
comment|/// This hook is called after promoting any internal functions
comment|/// (ThinLTO-specific).
name|ModuleHookFn
name|PostPromoteModuleHook
decl_stmt|;
comment|/// This hook is called after internalizing the module.
name|ModuleHookFn
name|PostInternalizeModuleHook
decl_stmt|;
comment|/// This hook is called after importing from other modules (ThinLTO-specific).
name|ModuleHookFn
name|PostImportModuleHook
decl_stmt|;
comment|/// This module hook is called after optimization is complete.
name|ModuleHookFn
name|PostOptModuleHook
decl_stmt|;
comment|/// This module hook is called before code generation. It is similar to the
comment|/// PostOptModuleHook, but for parallel code generation it is called after
comment|/// splitting the module.
name|ModuleHookFn
name|PreCodeGenModuleHook
decl_stmt|;
comment|/// A combined index hook is called after all per-module indexes have been
comment|/// combined (ThinLTO-specific). It can be used to implement -save-temps for
comment|/// the combined index.
comment|///
comment|/// If this function returns false, any further processing for ThinLTO tasks
comment|/// is aborted.
comment|///
comment|/// It is called regardless of whether the backend is in-process, although it
comment|/// is not called from individual backend processes.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
specifier|const
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|)
operator|>
name|CombinedIndexHookFn
expr_stmt|;
name|CombinedIndexHookFn
name|CombinedIndexHook
decl_stmt|;
comment|/// This is a convenience function that configures this Config object to write
comment|/// temporary files named after the given OutputFileName for each of the LTO
comment|/// phases to disk. A client can use this function to implement -save-temps.
comment|///
comment|/// FIXME: Temporary files derived from ThinLTO backends are currently named
comment|/// after the input file name, rather than the output file name, when
comment|/// UseInputModulePath is set to true.
comment|///
comment|/// Specifically, it (1) sets each of the above module hooks and the combined
comment|/// index hook to a function that calls the hook function (if any) that was
comment|/// present in the appropriate field when the addSaveTemps function was
comment|/// called, and writes the module to a bitcode file with a name prefixed by
comment|/// the given output file name, and (2) creates a resolution file whose name
comment|/// is prefixed by the given output file name and sets ResolutionFile to its
comment|/// file handle.
name|Error
name|addSaveTemps
argument_list|(
name|std
operator|::
name|string
name|OutputFileName
argument_list|,
name|bool
name|UseInputModulePath
operator|=
name|false
argument_list|)
decl_stmt|;
block|}
struct|;
comment|/// A derived class of LLVMContext that initializes itself according to a given
comment|/// Config object. The purpose of this class is to tie ownership of the
comment|/// diagnostic handler to the context, as opposed to the Config object (which
comment|/// may be ephemeral).
name|struct
name|LTOLLVMContext
range|:
name|LLVMContext
block|{
specifier|static
name|void
name|funcDiagHandler
argument_list|(
argument|const DiagnosticInfo&DI
argument_list|,
argument|void *Context
argument_list|)
block|{
name|auto
operator|*
name|Fn
operator|=
name|static_cast
operator|<
name|DiagnosticHandlerFunction
operator|*
operator|>
operator|(
name|Context
operator|)
block|;
call|(
modifier|*
name|Fn
call|)
argument_list|(
name|DI
argument_list|)
block|;   }
name|LTOLLVMContext
argument_list|(
specifier|const
name|Config
operator|&
name|C
argument_list|)
operator|:
name|DiagHandler
argument_list|(
argument|C.DiagHandler
argument_list|)
block|{
name|setDiscardValueNames
argument_list|(
name|C
operator|.
name|ShouldDiscardValueNames
argument_list|)
block|;
name|enableDebugTypeODRUniquing
argument_list|()
block|;
name|setDiagnosticHandler
argument_list|(
name|funcDiagHandler
argument_list|,
operator|&
name|DiagHandler
argument_list|,
name|true
argument_list|)
block|;   }
name|DiagnosticHandlerFunction
name|DiagHandler
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

