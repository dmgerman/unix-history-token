begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-ThinLTOCodeGenerator.h - LLVM Link Time Optimizer -------------------===//
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
comment|// This file declares the ThinLTOCodeGenerator class, similar to the
end_comment

begin_comment
comment|// LTOCodeGenerator but for the ThinLTO scheme. It provides an interface for
end_comment

begin_comment
comment|// linker plugin.
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
name|LLVM_LTO_THINLTOCODEGENERATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LTO_THINLTOCODEGENERATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm-c/lto.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Triple.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ModuleSummaryIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/MemoryBuffer.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|StringRef
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|TargetMachine
decl_stmt|;
comment|/// Helper to gather options relevant to the target machine creation
struct|struct
name|TargetMachineBuilder
block|{
name|Triple
name|TheTriple
decl_stmt|;
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
name|TargetOptions
name|Options
decl_stmt|;
name|Optional
operator|<
name|Reloc
operator|::
name|Model
operator|>
name|RelocModel
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
name|std
operator|::
name|unique_ptr
operator|<
name|TargetMachine
operator|>
name|create
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
comment|/// This class define an interface similar to the LTOCodeGenerator, but adapted
comment|/// for ThinLTO processing.
comment|/// The ThinLTOCodeGenerator is not intended to be reuse for multiple
comment|/// compilation: the model is that the client adds modules to the generator and
comment|/// ask to perform the ThinLTO optimizations / codegen, and finally destroys the
comment|/// codegenerator.
name|class
name|ThinLTOCodeGenerator
block|{
name|public
label|:
comment|/// Add given module to the code generator.
name|void
name|addModule
parameter_list|(
name|StringRef
name|Identifier
parameter_list|,
name|StringRef
name|Data
parameter_list|)
function_decl|;
comment|/**    * Adds to a list of all global symbols that must exist in the final generated    * code. If a symbol is not listed there, it will be optimized away if it is    * inlined into every usage.    */
name|void
name|preserveSymbol
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/**    * Adds to a list of all global symbols that are cross-referenced between    * ThinLTO files. If the ThinLTO CodeGenerator can ensure that every    * references from a ThinLTO module to this symbol is optimized away, then    * the symbol can be discarded.    */
name|void
name|crossReferenceSymbol
parameter_list|(
name|StringRef
name|Name
parameter_list|)
function_decl|;
comment|/**    * Process all the modules that were added to the code generator in parallel.    *    * Client can access the resulting object files using getProducedBinaries()    */
name|void
name|run
parameter_list|()
function_decl|;
comment|/**    * Return the "in memory" binaries produced by the code generator.    */
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>
operator|&
name|getProducedBinaries
argument_list|()
block|{
return|return
name|ProducedBinaries
return|;
block|}
comment|/**    * \defgroup Options setters    * @{    */
comment|/**    * \defgroup Cache controlling options    *    * These entry points control the ThinLTO cache. The cache is intended to    * support incremental build, and thus needs to be persistent accross build.    * The client enabled the cache by supplying a path to an existing directory.    * The code generator will use this to store objects files that may be reused    * during a subsequent build.    * To avoid filling the disk space, a few knobs are provided:    *  - The pruning interval limit the frequency at which the garbage collector    *    will try to scan the cache directory to prune it from expired entries.    *    Setting to -1 disable the pruning (default).    *  - The pruning expiration time indicates to the garbage collector how old    *    an entry needs to be to be removed.    *  - Finally, the garbage collector can be instructed to prune the cache till    *    the occupied space goes below a threshold.    * @{    */
struct|struct
name|CachingOptions
block|{
name|std
operator|::
name|string
name|Path
expr_stmt|;
comment|// Path to the cache, empty to disable.
name|int
name|PruningInterval
init|=
literal|1200
decl_stmt|;
comment|// seconds, -1 to disable pruning.
name|unsigned
name|int
name|Expiration
init|=
literal|7
operator|*
literal|24
operator|*
literal|3600
decl_stmt|;
comment|// seconds (1w default).
name|unsigned
name|MaxPercentageOfAvailableSpace
init|=
literal|75
decl_stmt|;
comment|// percentage.
block|}
struct|;
comment|/// Provide a path to a directory where to store the cached files for
comment|/// incremental build.
name|void
name|setCacheDir
argument_list|(
name|std
operator|::
name|string
name|Path
argument_list|)
block|{
name|CacheOptions
operator|.
name|Path
operator|=
name|std
operator|::
name|move
argument_list|(
name|Path
argument_list|)
expr_stmt|;
block|}
comment|/// Cache policy: interval (seconds) between two prune of the cache. Set to a
comment|/// negative value (default) to disable pruning. A value of 0 will be ignored.
name|void
name|setCachePruningInterval
parameter_list|(
name|int
name|Interval
parameter_list|)
block|{
if|if
condition|(
name|Interval
condition|)
name|CacheOptions
operator|.
name|PruningInterval
operator|=
name|Interval
expr_stmt|;
block|}
comment|/// Cache policy: expiration (in seconds) for an entry.
comment|/// A value of 0 will be ignored.
name|void
name|setCacheEntryExpiration
parameter_list|(
name|unsigned
name|Expiration
parameter_list|)
block|{
if|if
condition|(
name|Expiration
condition|)
name|CacheOptions
operator|.
name|Expiration
operator|=
name|Expiration
expr_stmt|;
block|}
comment|/**    * Sets the maximum cache size that can be persistent across build, in terms    * of percentage of the available space on the the disk. Set to 100 to    * indicate no limit, 50 to indicate that the cache size will not be left over    * half the available space. A value over 100 will be reduced to 100, and a    * value of 0 will be ignored.    *    *    * The formula looks like:    *  AvailableSpace = FreeSpace + ExistingCacheSize    *  NewCacheSize = AvailableSpace * P/100    *    */
name|void
name|setMaxCacheSizeRelativeToAvailableSpace
parameter_list|(
name|unsigned
name|Percentage
parameter_list|)
block|{
if|if
condition|(
name|Percentage
condition|)
name|CacheOptions
operator|.
name|MaxPercentageOfAvailableSpace
operator|=
name|Percentage
expr_stmt|;
block|}
comment|/**@}*/
comment|/// Set the path to a directory where to save temporaries at various stages of
comment|/// the processing.
name|void
name|setSaveTempsDir
argument_list|(
name|std
operator|::
name|string
name|Path
argument_list|)
block|{
name|SaveTempsDir
operator|=
name|std
operator|::
name|move
argument_list|(
name|Path
argument_list|)
expr_stmt|;
block|}
comment|/// CPU to use to initialize the TargetMachine
name|void
name|setCpu
argument_list|(
name|std
operator|::
name|string
name|Cpu
argument_list|)
block|{
name|TMBuilder
operator|.
name|MCpu
operator|=
name|std
operator|::
name|move
argument_list|(
name|Cpu
argument_list|)
expr_stmt|;
block|}
comment|/// Subtarget attributes
name|void
name|setAttr
argument_list|(
name|std
operator|::
name|string
name|MAttr
argument_list|)
block|{
name|TMBuilder
operator|.
name|MAttr
operator|=
name|std
operator|::
name|move
argument_list|(
name|MAttr
argument_list|)
expr_stmt|;
block|}
comment|/// TargetMachine options
name|void
name|setTargetOptions
parameter_list|(
name|TargetOptions
name|Options
parameter_list|)
block|{
name|TMBuilder
operator|.
name|Options
operator|=
name|std
operator|::
name|move
argument_list|(
name|Options
argument_list|)
expr_stmt|;
block|}
comment|/// CodeModel
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
name|TMBuilder
operator|.
name|RelocModel
operator|=
name|Model
expr_stmt|;
block|}
comment|/// CodeGen optimization level
name|void
name|setCodeGenOptLevel
argument_list|(
name|CodeGenOpt
operator|::
name|Level
name|CGOptLevel
argument_list|)
block|{
name|TMBuilder
operator|.
name|CGOptLevel
operator|=
name|CGOptLevel
expr_stmt|;
block|}
comment|/// Disable CodeGen, only run the stages till codegen and stop. The output
comment|/// will be bitcode.
name|void
name|disableCodeGen
parameter_list|(
name|bool
name|Disable
parameter_list|)
block|{
name|DisableCodeGen
operator|=
name|Disable
expr_stmt|;
block|}
comment|/// Perform CodeGen only: disable all other stages.
name|void
name|setCodeGenOnly
parameter_list|(
name|bool
name|CGOnly
parameter_list|)
block|{
name|CodeGenOnly
operator|=
name|CGOnly
expr_stmt|;
block|}
comment|/**@}*/
comment|/**    * \defgroup Set of APIs to run individual stages in isolation.    * @{    */
comment|/**    * Produce the combined summary index from all the bitcode files:    * "thin-link".    */
name|std
operator|::
name|unique_ptr
operator|<
name|ModuleSummaryIndex
operator|>
name|linkCombinedIndex
argument_list|()
expr_stmt|;
comment|/**    * Perform promotion and renaming of exported internal functions,    * and additionally resolve weak and linkonce symbols.    * Index is updated to reflect linkage changes from weak resolution.    */
name|void
name|promote
parameter_list|(
name|Module
modifier|&
name|Module
parameter_list|,
name|ModuleSummaryIndex
modifier|&
name|Index
parameter_list|)
function_decl|;
comment|/**    * Compute and emit the imported files for module at \p ModulePath.    */
specifier|static
name|void
name|emitImports
parameter_list|(
name|StringRef
name|ModulePath
parameter_list|,
name|StringRef
name|OutputName
parameter_list|,
name|ModuleSummaryIndex
modifier|&
name|Index
parameter_list|)
function_decl|;
comment|/**    * Perform cross-module importing for the module identified by    * ModuleIdentifier.    */
name|void
name|crossModuleImport
parameter_list|(
name|Module
modifier|&
name|Module
parameter_list|,
name|ModuleSummaryIndex
modifier|&
name|Index
parameter_list|)
function_decl|;
comment|/**    * Compute the list of summaries needed for importing into module.    */
specifier|static
name|void
name|gatherImportedSummariesForModule
argument_list|(
name|StringRef
name|ModulePath
argument_list|,
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|,
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
argument_list|,
name|GVSummaryMapTy
operator|>
operator|&
name|ModuleToSummariesForIndex
argument_list|)
decl_stmt|;
comment|/**    * Perform internalization. Index is updated to reflect linkage changes.    */
name|void
name|internalize
parameter_list|(
name|Module
modifier|&
name|Module
parameter_list|,
name|ModuleSummaryIndex
modifier|&
name|Index
parameter_list|)
function_decl|;
comment|/**    * Perform post-importing ThinLTO optimizations.    */
name|void
name|optimize
parameter_list|(
name|Module
modifier|&
name|Module
parameter_list|)
function_decl|;
comment|/**    * Perform ThinLTO CodeGen.    */
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>
name|codegen
argument_list|(
name|Module
operator|&
name|Module
argument_list|)
expr_stmt|;
comment|/**@}*/
name|private
label|:
comment|/// Helper factory to build a TargetMachine
name|TargetMachineBuilder
name|TMBuilder
decl_stmt|;
comment|/// Vector holding the in-memory buffer containing the produced binaries.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryBuffer
operator|>>
name|ProducedBinaries
expr_stmt|;
comment|/// Vector holding the input buffers containing the bitcode modules to
comment|/// process.
name|std
operator|::
name|vector
operator|<
name|MemoryBufferRef
operator|>
name|Modules
expr_stmt|;
comment|/// Set of symbols that need to be preserved outside of the set of bitcode
comment|/// files.
name|StringSet
operator|<
operator|>
name|PreservedSymbols
expr_stmt|;
comment|/// Set of symbols that are cross-referenced between bitcode files.
name|StringSet
operator|<
operator|>
name|CrossReferencedSymbols
expr_stmt|;
comment|/// Control the caching behavior.
name|CachingOptions
name|CacheOptions
decl_stmt|;
comment|/// Path to a directory to save the temporary bitcode files.
name|std
operator|::
name|string
name|SaveTempsDir
expr_stmt|;
comment|/// Flag to enable/disable CodeGen. When set to true, the process stops after
comment|/// optimizations and a bitcode is produced.
name|bool
name|DisableCodeGen
init|=
name|false
decl_stmt|;
comment|/// Flag to indicate that only the CodeGen will be performed, no cross-module
comment|/// importing or optimization.
name|bool
name|CodeGenOnly
init|=
name|false
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

