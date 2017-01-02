begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- lld/Core/LinkingContext.h - Linker Target Info Interface -*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_CORE_LINKING_CONTEXT_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_CORE_LINKING_CONTEXT_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/Node.h"
end_include

begin_include
include|#
directive|include
file|"lld/Core/Reader.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
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
name|lld
block|{
name|class
name|PassManager
decl_stmt|;
name|class
name|File
decl_stmt|;
name|class
name|Writer
decl_stmt|;
name|class
name|Node
decl_stmt|;
name|class
name|SharedLibraryFile
decl_stmt|;
comment|/// \brief The LinkingContext class encapsulates "what and how" to link.
comment|///
comment|/// The base class LinkingContext contains the options needed by core linking.
comment|/// Subclasses of LinkingContext have additional options needed by specific
comment|/// Writers.
name|class
name|LinkingContext
block|{
name|public
label|:
name|virtual
operator|~
name|LinkingContext
argument_list|()
expr_stmt|;
comment|/// \name Methods needed by core linking
comment|/// @{
comment|/// Name of symbol linker should use as "entry point" to program,
comment|/// usually "main" or "start".
name|virtual
name|StringRef
name|entrySymbolName
argument_list|()
specifier|const
block|{
return|return
name|_entrySymbolName
return|;
block|}
comment|/// Whether core linking should remove Atoms not reachable by following
comment|/// References from the entry point Atom or from all global scope Atoms
comment|/// if globalsAreDeadStripRoots() is true.
name|bool
name|deadStrip
argument_list|()
specifier|const
block|{
return|return
name|_deadStrip
return|;
block|}
comment|/// Only used if deadStrip() returns true.  Means all global scope Atoms
comment|/// should be marked live (along with all Atoms they reference).  Usually
comment|/// this method returns false for main executables, but true for dynamic
comment|/// shared libraries.
name|bool
name|globalsAreDeadStripRoots
argument_list|()
specifier|const
block|{
return|return
name|_globalsAreDeadStripRoots
return|;
block|}
comment|/// Only used if deadStrip() returns true.  This method returns the names
comment|/// of DefinedAtoms that should be marked live (along with all Atoms they
comment|/// reference). Only Atoms with scope scopeLinkageUnit or scopeGlobal can
comment|/// be kept live using this method.
specifier|const
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
operator|&
name|deadStripRoots
argument_list|()
specifier|const
block|{
return|return
name|_deadStripRoots
return|;
block|}
comment|/// Add the given symbol name to the dead strip root set. Only used if
comment|/// deadStrip() returns true.
name|void
name|addDeadStripRoot
parameter_list|(
name|StringRef
name|symbolName
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|symbolName
operator|.
name|empty
argument_list|()
operator|&&
literal|"Empty symbol cannot be a dead strip root"
argument_list|)
expr_stmt|;
name|_deadStripRoots
operator|.
name|push_back
argument_list|(
name|symbolName
argument_list|)
expr_stmt|;
block|}
comment|/// Normally, every UndefinedAtom must be replaced by a DefinedAtom or a
comment|/// SharedLibraryAtom for the link to be successful.  This method controls
comment|/// whether core linking prints out a list of remaining UndefinedAtoms.
comment|///
comment|/// \todo This should be a method core linking calls with a list of the
comment|/// UndefinedAtoms so that different drivers can format the error message
comment|/// as needed.
name|bool
name|printRemainingUndefines
argument_list|()
specifier|const
block|{
return|return
name|_printRemainingUndefines
return|;
block|}
comment|/// Normally, every UndefinedAtom must be replaced by a DefinedAtom or a
comment|/// SharedLibraryAtom for the link to be successful.  This method controls
comment|/// whether core linking considers remaining undefines to be an error.
name|bool
name|allowRemainingUndefines
argument_list|()
specifier|const
block|{
return|return
name|_allowRemainingUndefines
return|;
block|}
comment|/// Normally, every UndefinedAtom must be replaced by a DefinedAtom or a
comment|/// SharedLibraryAtom for the link to be successful.  This method controls
comment|/// whether core linking considers remaining undefines from the shared library
comment|/// to be an error.
name|bool
name|allowShlibUndefines
argument_list|()
specifier|const
block|{
return|return
name|_allowShlibUndefines
return|;
block|}
comment|/// If true, core linking will write the path to each input file to stdout
comment|/// (i.e. llvm::outs()) as it is used.  This is used to implement the -t
comment|/// linker option.
comment|///
comment|/// \todo This should be a method core linking calls so that drivers can
comment|/// format the line as needed.
name|bool
name|logInputFiles
argument_list|()
specifier|const
block|{
return|return
name|_logInputFiles
return|;
block|}
comment|/// Parts of LLVM use global variables which are bound to command line
comment|/// options (see llvm::cl::Options). This method returns "command line"
comment|/// options which are used to configure LLVM's command line settings.
comment|/// For instance the -debug-only XXX option can be used to dynamically
comment|/// trace different parts of LLVM and lld.
specifier|const
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
operator|>
operator|&
name|llvmOptions
argument_list|()
specifier|const
block|{
return|return
name|_llvmOptions
return|;
block|}
comment|/// \name Methods used by Drivers to configure TargetInfo
comment|/// @{
name|void
name|setOutputPath
parameter_list|(
name|StringRef
name|str
parameter_list|)
block|{
name|_outputPath
operator|=
name|str
expr_stmt|;
block|}
comment|// Set the entry symbol name. You may also need to call addDeadStripRoot() for
comment|// the symbol if your platform supports dead-stripping, so that the symbol
comment|// will not be removed from the output.
name|void
name|setEntrySymbolName
parameter_list|(
name|StringRef
name|name
parameter_list|)
block|{
name|_entrySymbolName
operator|=
name|name
expr_stmt|;
block|}
name|void
name|setDeadStripping
parameter_list|(
name|bool
name|enable
parameter_list|)
block|{
name|_deadStrip
operator|=
name|enable
expr_stmt|;
block|}
name|void
name|setGlobalsAreDeadStripRoots
parameter_list|(
name|bool
name|v
parameter_list|)
block|{
name|_globalsAreDeadStripRoots
operator|=
name|v
expr_stmt|;
block|}
name|void
name|setPrintRemainingUndefines
parameter_list|(
name|bool
name|print
parameter_list|)
block|{
name|_printRemainingUndefines
operator|=
name|print
expr_stmt|;
block|}
name|void
name|setAllowRemainingUndefines
parameter_list|(
name|bool
name|allow
parameter_list|)
block|{
name|_allowRemainingUndefines
operator|=
name|allow
expr_stmt|;
block|}
name|void
name|setAllowShlibUndefines
parameter_list|(
name|bool
name|allow
parameter_list|)
block|{
name|_allowShlibUndefines
operator|=
name|allow
expr_stmt|;
block|}
name|void
name|setLogInputFiles
parameter_list|(
name|bool
name|log
parameter_list|)
block|{
name|_logInputFiles
operator|=
name|log
expr_stmt|;
block|}
name|void
name|appendLLVMOption
parameter_list|(
specifier|const
name|char
modifier|*
name|opt
parameter_list|)
block|{
name|_llvmOptions
operator|.
name|push_back
argument_list|(
name|opt
argument_list|)
expr_stmt|;
block|}
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Node
operator|>>
operator|&
name|getNodes
argument_list|()
block|{
return|return
name|_nodes
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Node
operator|>>
operator|&
name|getNodes
argument_list|()
specifier|const
block|{
return|return
name|_nodes
return|;
block|}
comment|/// This method adds undefined symbols specified by the -u option to the to
comment|/// the list of undefined symbols known to the linker. This option essentially
comment|/// forces an undefined symbol to be created. You may also need to call
comment|/// addDeadStripRoot() for the symbol if your platform supports dead
comment|/// stripping, so that the symbol will not be removed from the output.
name|void
name|addInitialUndefinedSymbol
parameter_list|(
name|StringRef
name|symbolName
parameter_list|)
block|{
name|_initialUndefinedSymbols
operator|.
name|push_back
argument_list|(
name|symbolName
argument_list|)
expr_stmt|;
block|}
comment|/// Iterators for symbols that appear on the command line.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|StringRefVector
expr_stmt|;
typedef|typedef
name|StringRefVector
operator|::
name|iterator
name|StringRefVectorIter
expr_stmt|;
typedef|typedef
name|StringRefVector
operator|::
name|const_iterator
name|StringRefVectorConstIter
expr_stmt|;
comment|/// Create linker internal files containing atoms for the linker to include
comment|/// during link. Flavors can override this function in their LinkingContext
comment|/// to add more internal files. These internal files are positioned before
comment|/// the actual input files.
name|virtual
name|void
name|createInternalFiles
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
operator|&
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the list of undefined symbols that are specified in the
comment|/// linker command line, using the -u option.
name|ArrayRef
operator|<
name|StringRef
operator|>
name|initialUndefinedSymbols
argument_list|()
specifier|const
block|{
return|return
name|_initialUndefinedSymbols
return|;
block|}
comment|/// After all set* methods are called, the Driver calls this method
comment|/// to validate that there are no missing options or invalid combinations
comment|/// of options.  If there is a problem, a description of the problem
comment|/// is written to the supplied stream.
comment|///
comment|/// \returns true if there is an error with the current settings.
name|bool
name|validate
parameter_list|(
name|raw_ostream
modifier|&
name|diagnostics
parameter_list|)
function_decl|;
comment|/// Formats symbol name for use in error messages.
name|virtual
name|std
operator|::
name|string
name|demangle
argument_list|(
argument|StringRef symbolName
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// @}
comment|/// \name Methods used by Driver::link()
comment|/// @{
comment|/// Returns the file system path to which the linked output should be written.
comment|///
comment|/// \todo To support in-memory linking, we need an abstraction that allows
comment|/// the linker to write to an in-memory buffer.
name|StringRef
name|outputPath
argument_list|()
specifier|const
block|{
return|return
name|_outputPath
return|;
block|}
comment|/// Accessor for Register object embedded in LinkingContext.
specifier|const
name|Registry
operator|&
name|registry
argument_list|()
specifier|const
block|{
return|return
name|_registry
return|;
block|}
name|Registry
modifier|&
name|registry
parameter_list|()
block|{
return|return
name|_registry
return|;
block|}
comment|/// This method is called by core linking to give the Writer a chance
comment|/// to add file format specific "files" to set of files to be linked. This is
comment|/// how file format specific atoms can be added to the link.
name|virtual
name|void
name|createImplicitFiles
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>>
operator|&
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// This method is called by core linking to build the list of Passes to be
comment|/// run on the merged/linked graph of all input files.
name|virtual
name|void
name|addPasses
parameter_list|(
name|PassManager
modifier|&
name|pm
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Calls through to the writeFile() method on the specified Writer.
comment|///
comment|/// \param linkedFile This is the merged/linked graph of all input file Atoms.
name|virtual
name|llvm
operator|::
name|Error
name|writeFile
argument_list|(
argument|const File&linkedFile
argument_list|)
specifier|const
expr_stmt|;
comment|/// Return the next ordinal and Increment it.
name|virtual
name|uint64_t
name|getNextOrdinalAndIncrement
argument_list|()
specifier|const
block|{
return|return
name|_nextOrdinal
operator|++
return|;
block|}
comment|// This function is called just before the Resolver kicks in.
comment|// Derived classes may use it to change the list of input files.
name|virtual
name|void
name|finalizeInputFiles
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// Callback invoked for each file the Resolver decides we are going to load.
comment|/// This can be used to update context state based on the file, and emit
comment|/// errors for any differences between the context state and a loaded file.
comment|/// For example, we can error if we try to load a file which is a different
comment|/// arch from that being linked.
name|virtual
name|llvm
operator|::
name|Error
name|handleLoadedFile
argument_list|(
name|File
operator|&
name|file
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// @}
name|protected
label|:
name|LinkingContext
argument_list|()
expr_stmt|;
comment|// Must be subclassed
comment|/// Abstract method to lazily instantiate the Writer.
name|virtual
name|Writer
operator|&
name|writer
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Method to create an internal file for the entry symbol
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>
name|createEntrySymbolFile
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>
name|createEntrySymbolFile
argument_list|(
argument|StringRef filename
argument_list|)
specifier|const
expr_stmt|;
comment|/// Method to create an internal file for an undefined symbol
name|virtual
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>
name|createUndefinedSymbolFile
argument_list|()
specifier|const
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|File
operator|>
name|createUndefinedSymbolFile
argument_list|(
argument|StringRef filename
argument_list|)
specifier|const
expr_stmt|;
name|StringRef
name|_outputPath
decl_stmt|;
name|StringRef
name|_entrySymbolName
decl_stmt|;
name|bool
name|_deadStrip
init|=
name|false
decl_stmt|;
name|bool
name|_globalsAreDeadStripRoots
init|=
name|false
decl_stmt|;
name|bool
name|_printRemainingUndefines
init|=
name|true
decl_stmt|;
name|bool
name|_allowRemainingUndefines
init|=
name|false
decl_stmt|;
name|bool
name|_logInputFiles
init|=
name|false
decl_stmt|;
name|bool
name|_allowShlibUndefines
init|=
name|false
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|_deadStripRoots
expr_stmt|;
name|std
operator|::
name|vector
operator|<
specifier|const
name|char
operator|*
operator|>
name|_llvmOptions
expr_stmt|;
name|StringRefVector
name|_initialUndefinedSymbols
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|Node
operator|>>
name|_nodes
expr_stmt|;
name|mutable
name|llvm
operator|::
name|BumpPtrAllocator
name|_allocator
expr_stmt|;
name|mutable
name|uint64_t
name|_nextOrdinal
init|=
literal|0
decl_stmt|;
name|Registry
name|_registry
decl_stmt|;
name|private
label|:
comment|/// Validate the subclass bits. Only called by validate.
name|virtual
name|bool
name|validateImpl
parameter_list|(
name|raw_ostream
modifier|&
name|diagnostics
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLD_CORE_LINKING_CONTEXT_H
end_comment

end_unit

