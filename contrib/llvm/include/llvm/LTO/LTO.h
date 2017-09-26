begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-LTO.h - LLVM Link Time Optimizer ------------------------------------===//
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
comment|// This file declares functions and classes used to support LTO. It is intended
end_comment

begin_comment
comment|// to be used both by LTO classes as well as by clients (gold-plugin) that
end_comment

begin_comment
comment|// don't utilize the LTO code generator interfaces.
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
name|LLVM_LTO_LTO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LTO_LTO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
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
file|"llvm/Analysis/ObjectUtils.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/DiagnosticInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/ModuleSummaryIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/LTO/Config.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Linker/IRMover.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Object/IRSymtab.h"
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
file|"llvm/Support/thread.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Transforms/IPO/FunctionImport.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BitcodeModule
decl_stmt|;
name|class
name|Error
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MemoryBufferRef
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|raw_pwrite_stream
decl_stmt|;
comment|/// Resolve Weak and LinkOnce values in the \p Index. Linkage changes recorded
comment|/// in the index and the ThinLTO backends must apply the changes to the Module
comment|/// via thinLTOResolveWeakForLinkerModule.
comment|///
comment|/// This is done for correctness (if value exported, ensure we always
comment|/// emit a copy), and compile-time optimization (allow drop of duplicates).
name|void
name|thinLTOResolveWeakForLinkerInIndex
argument_list|(
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|,
name|function_ref
operator|<
name|bool
argument_list|(
name|GlobalValue
operator|::
name|GUID
argument_list|,
specifier|const
name|GlobalValueSummary
operator|*
argument_list|)
operator|>
name|isPrevailing
argument_list|,
name|function_ref
operator|<
name|void
argument_list|(
name|StringRef
argument_list|,
name|GlobalValue
operator|::
name|GUID
argument_list|,
name|GlobalValue
operator|::
name|LinkageTypes
argument_list|)
operator|>
name|recordNewLinkage
argument_list|)
decl_stmt|;
comment|/// Update the linkages in the given \p Index to mark exported values
comment|/// as external and non-exported values as internal. The ThinLTO backends
comment|/// must apply the changes to the Module via thinLTOInternalizeModule.
name|void
name|thinLTOInternalizeAndPromoteInIndex
argument_list|(
name|ModuleSummaryIndex
operator|&
name|Index
argument_list|,
name|function_ref
operator|<
name|bool
argument_list|(
name|StringRef
argument_list|,
name|GlobalValue
operator|::
name|GUID
argument_list|)
operator|>
name|isExported
argument_list|)
decl_stmt|;
name|namespace
name|lto
block|{
comment|/// Given the original \p Path to an output file, replace any path
comment|/// prefix matching \p OldPrefix with \p NewPrefix. Also, create the
comment|/// resulting directory if it does not yet exist.
name|std
operator|::
name|string
name|getThinLTOOutputFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Path
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|OldPrefix
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|NewPrefix
argument_list|)
expr_stmt|;
comment|/// Setup optimization remarks.
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|tool_output_file
operator|>>
name|setupOptimizationRemarks
argument_list|(
argument|LLVMContext&Context
argument_list|,
argument|StringRef LTORemarksFilename
argument_list|,
argument|bool LTOPassRemarksWithHotness
argument_list|,
argument|int Count = -
literal|1
argument_list|)
expr_stmt|;
name|class
name|LTO
decl_stmt|;
struct_decl|struct
name|SymbolResolution
struct_decl|;
name|class
name|ThinBackendProc
decl_stmt|;
comment|/// An input file. This is a symbol table wrapper that only exposes the
comment|/// information that an LTO client should need in order to do symbol resolution.
name|class
name|InputFile
block|{
name|public
label|:
name|class
name|Symbol
decl_stmt|;
name|private
label|:
comment|// FIXME: Remove LTO class friendship once we have bitcode symbol tables.
name|friend
name|LTO
decl_stmt|;
name|InputFile
argument_list|()
operator|=
expr|default
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|BitcodeModule
operator|>
name|Mods
expr_stmt|;
name|SmallVector
operator|<
name|char
operator|,
literal|0
operator|>
name|Strtab
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Symbol
operator|>
name|Symbols
expr_stmt|;
comment|// [begin, end) for each module
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|size_t
operator|,
name|size_t
operator|>>
name|ModuleSymIndices
expr_stmt|;
name|StringRef
name|TargetTriple
decl_stmt|,
name|SourceFileName
decl_stmt|,
name|COFFLinkerOpts
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|ComdatTable
expr_stmt|;
name|public
label|:
operator|~
name|InputFile
argument_list|()
expr_stmt|;
comment|/// Create an InputFile.
specifier|static
name|Expected
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>>
name|create
argument_list|(
argument|MemoryBufferRef Object
argument_list|)
expr_stmt|;
comment|/// The purpose of this class is to only expose the symbol information that an
comment|/// LTO client should need in order to do symbol resolution.
name|class
name|Symbol
range|:
name|irsymtab
operator|::
name|Symbol
block|{
name|friend
name|LTO
block|;
name|public
operator|:
name|Symbol
argument_list|(
specifier|const
name|irsymtab
operator|::
name|Symbol
operator|&
name|S
argument_list|)
operator|:
name|irsymtab
operator|::
name|Symbol
argument_list|(
argument|S
argument_list|)
block|{}
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|isUndefined
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|isCommon
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|isWeak
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|isIndirect
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|getName
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|getVisibility
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|canBeOmittedFromSymbolTable
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|isTLS
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|getComdatIndex
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|getCommonSize
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|getCommonAlignment
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|getCOFFWeakExternalFallback
block|;
name|using
name|irsymtab
operator|::
name|Symbol
operator|::
name|isExecutable
block|;   }
decl_stmt|;
comment|/// A range over the symbols in this InputFile.
name|ArrayRef
operator|<
name|Symbol
operator|>
name|symbols
argument_list|()
specifier|const
block|{
return|return
name|Symbols
return|;
block|}
comment|/// Returns linker options specified in the input file.
name|StringRef
name|getCOFFLinkerOpts
argument_list|()
specifier|const
block|{
return|return
name|COFFLinkerOpts
return|;
block|}
comment|/// Returns the path to the InputFile.
name|StringRef
name|getName
argument_list|()
specifier|const
expr_stmt|;
comment|/// Returns the input file's target triple.
name|StringRef
name|getTargetTriple
argument_list|()
specifier|const
block|{
return|return
name|TargetTriple
return|;
block|}
comment|/// Returns the source file path specified at compile time.
name|StringRef
name|getSourceFileName
argument_list|()
specifier|const
block|{
return|return
name|SourceFileName
return|;
block|}
comment|// Returns a table with all the comdats used by this file.
name|ArrayRef
operator|<
name|StringRef
operator|>
name|getComdatTable
argument_list|()
specifier|const
block|{
return|return
name|ComdatTable
return|;
block|}
name|private
label|:
name|ArrayRef
operator|<
name|Symbol
operator|>
name|module_symbols
argument_list|(
argument|unsigned I
argument_list|)
specifier|const
block|{
specifier|const
name|auto
operator|&
name|Indices
operator|=
name|ModuleSymIndices
index|[
name|I
index|]
block|;
return|return
block|{
name|Symbols
operator|.
name|data
argument_list|()
operator|+
name|Indices
operator|.
name|first
block|,
name|Symbols
operator|.
name|data
argument_list|()
operator|+
name|Indices
operator|.
name|second
block|}
return|;
block|}
block|}
empty_stmt|;
comment|/// This class wraps an output stream for a native object. Most clients should
comment|/// just be able to return an instance of this base class from the stream
comment|/// callback, but if a client needs to perform some action after the stream is
comment|/// written to, that can be done by deriving from this class and overriding the
comment|/// destructor.
name|class
name|NativeObjectStream
block|{
name|public
label|:
name|NativeObjectStream
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|raw_pwrite_stream
operator|>
name|OS
argument_list|)
operator|:
name|OS
argument_list|(
argument|std::move(OS)
argument_list|)
block|{}
name|std
operator|::
name|unique_ptr
operator|<
name|raw_pwrite_stream
operator|>
name|OS
expr_stmt|;
name|virtual
operator|~
name|NativeObjectStream
argument_list|()
operator|=
expr|default
expr_stmt|;
block|}
empty_stmt|;
comment|/// This type defines the callback to add a native object that is generated on
comment|/// the fly.
comment|///
comment|/// Stream callbacks must be thread safe.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|NativeObjectStream
operator|>
operator|(
name|unsigned
name|Task
operator|)
operator|>
name|AddStreamFn
expr_stmt|;
comment|/// This is the type of a native object cache. To request an item from the
comment|/// cache, pass a unique string as the Key. For hits, the cached file will be
comment|/// added to the link and this function will return AddStreamFn(). For misses,
comment|/// the cache will return a stream callback which must be called at most once to
comment|/// produce content for the stream. The native object stream produced by the
comment|/// stream callback will add the file to the link after the stream is written
comment|/// to.
comment|///
comment|/// Clients generally look like this:
comment|///
comment|/// if (AddStreamFn AddStream = Cache(Task, Key))
comment|///   ProduceContent(AddStream);
typedef|typedef
name|std
operator|::
name|function
operator|<
name|AddStreamFn
argument_list|(
argument|unsigned Task
argument_list|,
argument|StringRef Key
argument_list|)
operator|>
name|NativeObjectCache
expr_stmt|;
comment|/// A ThinBackend defines what happens after the thin-link phase during ThinLTO.
comment|/// The details of this type definition aren't important; clients can only
comment|/// create a ThinBackend using one of the create*ThinBackend() functions below.
typedef|typedef
name|std
operator|::
name|function
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ThinBackendProc
operator|>
operator|(
name|Config
operator|&
name|C
operator|,
name|ModuleSummaryIndex
operator|&
name|CombinedIndex
operator|,
name|StringMap
operator|<
name|GVSummaryMapTy
operator|>
operator|&
name|ModuleToDefinedGVSummaries
operator|,
name|AddStreamFn
name|AddStream
operator|,
name|NativeObjectCache
name|Cache
operator|)
operator|>
name|ThinBackend
expr_stmt|;
comment|/// This ThinBackend runs the individual backend jobs in-process.
name|ThinBackend
name|createInProcessThinBackend
parameter_list|(
name|unsigned
name|ParallelismLevel
parameter_list|)
function_decl|;
comment|/// This ThinBackend writes individual module indexes to files, instead of
comment|/// running the individual backend jobs. This backend is for distributed builds
comment|/// where separate processes will invoke the real backends.
comment|///
comment|/// To find the path to write the index to, the backend checks if the path has a
comment|/// prefix of OldPrefix; if so, it replaces that prefix with NewPrefix. It then
comment|/// appends ".thinlto.bc" and writes the index to that path. If
comment|/// ShouldEmitImportsFiles is true it also writes a list of imported files to a
comment|/// similar path with ".imports" appended instead.
name|ThinBackend
name|createWriteIndexesThinBackend
argument_list|(
name|std
operator|::
name|string
name|OldPrefix
argument_list|,
name|std
operator|::
name|string
name|NewPrefix
argument_list|,
name|bool
name|ShouldEmitImportsFiles
argument_list|,
name|std
operator|::
name|string
name|LinkedObjectsFile
argument_list|)
decl_stmt|;
comment|/// This class implements a resolution-based interface to LLVM's LTO
comment|/// functionality. It supports regular LTO, parallel LTO code generation and
comment|/// ThinLTO. You can use it from a linker in the following way:
comment|/// - Set hooks and code generation options (see lto::Config struct defined in
comment|///   Config.h), and use the lto::Config object to create an lto::LTO object.
comment|/// - Create lto::InputFile objects using lto::InputFile::create(), then use
comment|///   the symbols() function to enumerate its symbols and compute a resolution
comment|///   for each symbol (see SymbolResolution below).
comment|/// - After the linker has visited each input file (and each regular object
comment|///   file) and computed a resolution for each symbol, take each lto::InputFile
comment|///   and pass it and an array of symbol resolutions to the add() function.
comment|/// - Call the getMaxTasks() function to get an upper bound on the number of
comment|///   native object files that LTO may add to the link.
comment|/// - Call the run() function. This function will use the supplied AddStream
comment|///   and Cache functions to add up to getMaxTasks() native object files to
comment|///   the link.
name|class
name|LTO
block|{
name|friend
name|InputFile
decl_stmt|;
name|public
label|:
comment|/// Create an LTO object. A default constructed LTO object has a reasonable
comment|/// production configuration, but you can customize it by passing arguments to
comment|/// this constructor.
comment|/// FIXME: We do currently require the DiagHandler field to be set in Conf.
comment|/// Until that is fixed, a Config argument is required.
name|LTO
argument_list|(
argument|Config Conf
argument_list|,
argument|ThinBackend Backend = nullptr
argument_list|,
argument|unsigned ParallelCodeGenParallelismLevel =
literal|1
argument_list|)
empty_stmt|;
operator|~
name|LTO
argument_list|()
expr_stmt|;
comment|/// Add an input file to the LTO link, using the provided symbol resolutions.
comment|/// The symbol resolutions must appear in the enumeration order given by
comment|/// InputFile::symbols().
name|Error
name|add
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|InputFile
operator|>
name|Obj
argument_list|,
name|ArrayRef
operator|<
name|SymbolResolution
operator|>
name|Res
argument_list|)
decl_stmt|;
comment|/// Returns an upper bound on the number of tasks that the client may expect.
comment|/// This may only be called after all IR object files have been added. For a
comment|/// full description of tasks see LTOBackend.h.
name|unsigned
name|getMaxTasks
argument_list|()
specifier|const
expr_stmt|;
comment|/// Runs the LTO pipeline. This function calls the supplied AddStream
comment|/// function to add native object files to the link.
comment|///
comment|/// The Cache parameter is optional. If supplied, it will be used to cache
comment|/// native object files and add them to the link.
comment|///
comment|/// The client will receive at most one callback (via either AddStream or
comment|/// Cache) for each task identifier.
name|Error
name|run
parameter_list|(
name|AddStreamFn
name|AddStream
parameter_list|,
name|NativeObjectCache
name|Cache
init|=
name|nullptr
parameter_list|)
function_decl|;
name|private
label|:
name|Config
name|Conf
decl_stmt|;
struct|struct
name|RegularLTOState
block|{
name|RegularLTOState
argument_list|(
argument|unsigned ParallelCodeGenParallelismLevel
argument_list|,
argument|Config&Conf
argument_list|)
empty_stmt|;
struct|struct
name|CommonResolution
block|{
name|uint64_t
name|Size
init|=
literal|0
decl_stmt|;
name|unsigned
name|Align
init|=
literal|0
decl_stmt|;
comment|/// Record if at least one instance of the common was marked as prevailing
name|bool
name|Prevailing
init|=
name|false
decl_stmt|;
block|}
struct|;
name|std
operator|::
name|map
operator|<
name|std
operator|::
name|string
operator|,
name|CommonResolution
operator|>
name|Commons
expr_stmt|;
name|unsigned
name|ParallelCodeGenParallelismLevel
decl_stmt|;
name|LTOLLVMContext
name|Ctx
decl_stmt|;
name|bool
name|HasModule
init|=
name|false
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|CombinedModule
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|IRMover
operator|>
name|Mover
expr_stmt|;
comment|// This stores the information about a regular LTO module that we have added
comment|// to the link. It will either be linked immediately (for modules without
comment|// summaries) or after summary-based dead stripping (for modules with
comment|// summaries).
struct|struct
name|AddedModule
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|Module
operator|>
name|M
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|GlobalValue
operator|*
operator|>
name|Keep
expr_stmt|;
block|}
struct|;
name|std
operator|::
name|vector
operator|<
name|AddedModule
operator|>
name|ModsWithSummaries
expr_stmt|;
block|}
name|RegularLTO
struct|;
struct|struct
name|ThinLTOState
block|{
name|ThinLTOState
argument_list|(
argument|ThinBackend Backend
argument_list|)
empty_stmt|;
name|ThinBackend
name|Backend
decl_stmt|;
name|ModuleSummaryIndex
name|CombinedIndex
decl_stmt|;
name|MapVector
operator|<
name|StringRef
operator|,
name|BitcodeModule
operator|>
name|ModuleMap
expr_stmt|;
name|DenseMap
operator|<
name|GlobalValue
operator|::
name|GUID
operator|,
name|StringRef
operator|>
name|PrevailingModuleForGUID
expr_stmt|;
block|}
name|ThinLTO
struct|;
comment|// The global resolution for a particular (mangled) symbol name. This is in
comment|// particular necessary to track whether each symbol can be internalized.
comment|// Because any input file may introduce a new cross-partition reference, we
comment|// cannot make any final internalization decisions until all input files have
comment|// been added and the client has called run(). During run() we apply
comment|// internalization decisions either directly to the module (for regular LTO)
comment|// or to the combined index (for ThinLTO).
struct|struct
name|GlobalResolution
block|{
comment|/// The unmangled name of the global.
name|std
operator|::
name|string
name|IRName
expr_stmt|;
comment|/// Keep track if the symbol is visible outside of a module with a summary
comment|/// (i.e. in either a regular object or a regular LTO module without a
comment|/// summary).
name|bool
name|VisibleOutsideSummary
init|=
name|false
decl_stmt|;
name|bool
name|UnnamedAddr
init|=
name|true
decl_stmt|;
comment|/// This field keeps track of the partition number of this global. The
comment|/// regular LTO object is partition 0, while each ThinLTO object has its own
comment|/// partition number from 1 onwards.
comment|///
comment|/// Any global that is defined or used by more than one partition, or that
comment|/// is referenced externally, may not be internalized.
comment|///
comment|/// Partitions generally have a one-to-one correspondence with tasks, except
comment|/// that we use partition 0 for all parallel LTO code generation partitions.
comment|/// Any partitioning of the combined LTO object is done internally by the
comment|/// LTO backend.
name|unsigned
name|Partition
init|=
name|Unknown
decl_stmt|;
comment|/// Special partition numbers.
enum_decl|enum :
name|unsigned
block|{
comment|/// A partition number has not yet been assigned to this global.
name|Unknown
init|=
operator|-
literal|1u
block|,
comment|/// This global is either used by more than one partition or has an
comment|/// external reference, and therefore cannot be internalized.
name|External
init|=
operator|-
literal|2u
block|,
comment|/// The RegularLTO partition
name|RegularLTO
init|=
literal|0
block|,     }
enum_decl|;
block|}
struct|;
comment|// Global mapping from mangled symbol names to resolutions.
name|StringMap
operator|<
name|GlobalResolution
operator|>
name|GlobalResolutions
expr_stmt|;
name|void
name|addModuleToGlobalRes
argument_list|(
name|ArrayRef
operator|<
name|InputFile
operator|::
name|Symbol
operator|>
name|Syms
argument_list|,
name|ArrayRef
operator|<
name|SymbolResolution
operator|>
name|Res
argument_list|,
name|unsigned
name|Partition
argument_list|,
name|bool
name|InSummary
argument_list|)
decl_stmt|;
comment|// These functions take a range of symbol resolutions [ResI, ResE) and consume
comment|// the resolutions used by a single input module by incrementing ResI. After
comment|// these functions return, [ResI, ResE) will refer to the resolution range for
comment|// the remaining modules in the InputFile.
name|Error
name|addModule
parameter_list|(
name|InputFile
modifier|&
name|Input
parameter_list|,
name|unsigned
name|ModI
parameter_list|,
specifier|const
name|SymbolResolution
modifier|*
modifier|&
name|ResI
parameter_list|,
specifier|const
name|SymbolResolution
modifier|*
name|ResE
parameter_list|)
function_decl|;
name|Expected
operator|<
name|RegularLTOState
operator|::
name|AddedModule
operator|>
name|addRegularLTO
argument_list|(
argument|BitcodeModule BM
argument_list|,
argument|ArrayRef<InputFile::Symbol> Syms
argument_list|,
argument|const SymbolResolution *&ResI
argument_list|,
argument|const SymbolResolution *ResE
argument_list|)
expr_stmt|;
name|Error
name|linkRegularLTO
argument_list|(
name|RegularLTOState
operator|::
name|AddedModule
name|Mod
argument_list|,
name|bool
name|LivenessFromIndex
argument_list|)
decl_stmt|;
name|Error
name|addThinLTO
argument_list|(
name|BitcodeModule
name|BM
argument_list|,
name|ArrayRef
operator|<
name|InputFile
operator|::
name|Symbol
operator|>
name|Syms
argument_list|,
specifier|const
name|SymbolResolution
operator|*
operator|&
name|ResI
argument_list|,
specifier|const
name|SymbolResolution
operator|*
name|ResE
argument_list|)
decl_stmt|;
name|Error
name|runRegularLTO
parameter_list|(
name|AddStreamFn
name|AddStream
parameter_list|)
function_decl|;
name|Error
name|runThinLTO
parameter_list|(
name|AddStreamFn
name|AddStream
parameter_list|,
name|NativeObjectCache
name|Cache
parameter_list|,
name|bool
name|HasRegularLTO
parameter_list|)
function_decl|;
name|mutable
name|bool
name|CalledGetMaxTasks
init|=
name|false
decl_stmt|;
block|}
empty_stmt|;
comment|/// The resolution for a symbol. The linker must provide a SymbolResolution for
comment|/// each global symbol based on its internal resolution of that symbol.
struct|struct
name|SymbolResolution
block|{
name|SymbolResolution
argument_list|()
operator|:
name|Prevailing
argument_list|(
literal|0
argument_list|)
operator|,
name|FinalDefinitionInLinkageUnit
argument_list|(
literal|0
argument_list|)
operator|,
name|VisibleToRegularObj
argument_list|(
literal|0
argument_list|)
operator|,
name|LinkerRedefined
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// The linker has chosen this definition of the symbol.
name|unsigned
name|Prevailing
operator|:
literal|1
expr_stmt|;
comment|/// The definition of this symbol is unpreemptable at runtime and is known to
comment|/// be in this linkage unit.
name|unsigned
name|FinalDefinitionInLinkageUnit
range|:
literal|1
decl_stmt|;
comment|/// The definition of this symbol is visible outside of the LTO unit.
name|unsigned
name|VisibleToRegularObj
range|:
literal|1
decl_stmt|;
comment|/// Linker redefined version of the symbol which appeared in -wrap or -defsym
comment|/// linker option.
name|unsigned
name|LinkerRedefined
range|:
literal|1
decl_stmt|;
block|}
struct|;
block|}
comment|// namespace lto
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

