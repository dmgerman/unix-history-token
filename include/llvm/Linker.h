begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Linker.h - Module Linker Interface ------------------*- C++ -*-===//
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
comment|// This file defines the interface to the module/file/archive linker.
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
name|LLVM_LINKER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LINKER_H
end_define

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|sys
block|{
name|class
name|Path
decl_stmt|;
block|}
name|class
name|Module
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
comment|/// This class provides the core functionality of linking in LLVM. It retains a
comment|/// Module object which is the composite of the modules and libraries linked
comment|/// into it. The composite Module can be retrieved via the getModule() method.
comment|/// In this case the Linker still retains ownership of the Module. If the
comment|/// releaseModule() method is used, the ownership of the Module is transferred
comment|/// to the caller and the Linker object is only suitable for destruction.
comment|/// The Linker can link Modules from memory, bitcode files, or bitcode
comment|/// archives.  It retains a set of search paths in which to find any libraries
comment|/// presented to it. By default, the linker will generate error and warning
comment|/// messages to stderr but this capability can be turned off with the
comment|/// QuietWarnings and QuietErrors flags. It can also be instructed to verbosely
comment|/// print out the linking actions it is taking with the Verbose flag.
comment|/// @brief The LLVM Linker.
name|class
name|Linker
block|{
comment|/// @name Types
comment|/// @{
name|public
label|:
comment|/// This type is used to pass the linkage items (libraries and files) to
comment|/// the LinkItems function. It is composed of string/bool pairs. The string
comment|/// provides the name of the file or library (as with the -l option). The
comment|/// bool should be true for libraries and false for files, signifying
comment|/// "isLibrary".
comment|/// @brief A list of linkage items
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|std
operator|::
name|string
operator|,
name|bool
operator|>
expr|>
name|ItemList
expr_stmt|;
comment|/// This enumeration is used to control various optional features of the
comment|/// linker.
enum|enum
name|ControlFlags
block|{
name|Verbose
init|=
literal|1
block|,
comment|///< Print to stderr what steps the linker is taking
name|QuietWarnings
init|=
literal|2
block|,
comment|///< Don't print warnings to stderr.
name|QuietErrors
init|=
literal|4
comment|///< Don't print errors to stderr.
block|}
enum|;
comment|/// @}
comment|/// @name Constructors
comment|/// @{
name|public
label|:
comment|/// Construct the Linker with an empty module which will be given the
comment|/// name \p progname. \p progname will also be used for error messages.
comment|/// @brief Construct with empty module
name|Linker
argument_list|(
argument|StringRef progname
argument_list|,
comment|///< name of tool running linker
argument|StringRef modulename
argument_list|,
comment|///< name of linker's end-result module
argument|LLVMContext&C
argument_list|,
comment|///< Context for global info
argument|unsigned Flags =
literal|0
comment|///< ControlFlags (one or more |'d together)
argument_list|)
empty_stmt|;
comment|/// Construct the Linker with a previously defined module, \p aModule. Use
comment|/// \p progname for the name of the program in error messages.
comment|/// @brief Construct with existing module
name|Linker
argument_list|(
argument|StringRef progname
argument_list|,
argument|Module* aModule
argument_list|,
argument|unsigned Flags =
literal|0
argument_list|)
empty_stmt|;
comment|/// Destruct the Linker.
comment|/// @brief Destructor
operator|~
name|Linker
argument_list|()
expr_stmt|;
comment|/// @}
comment|/// @name Accessors
comment|/// @{
name|public
label|:
comment|/// This method gets the composite module into which linking is being
comment|/// done. The Composite module starts out empty and accumulates modules
comment|/// linked into it via the various LinkIn* methods. This method does not
comment|/// release the Module to the caller. The Linker retains ownership and will
comment|/// destruct the Module when the Linker is destructed.
comment|/// @see releaseModule
comment|/// @brief Get the linked/composite module.
name|Module
operator|*
name|getModule
argument_list|()
specifier|const
block|{
return|return
name|Composite
return|;
block|}
comment|/// This method releases the composite Module into which linking is being
comment|/// done. Ownership of the composite Module is transferred to the caller who
comment|/// must arrange for its destruct. After this method is called, the Linker
comment|/// terminates the linking session for the returned Module. It will no
comment|/// longer utilize the returned Module but instead resets itself for
comment|/// subsequent linking as if the constructor had been called. The Linker's
comment|/// LibPaths and flags to be reset, and memory will be released.
comment|/// @brief Release the linked/composite module.
name|Module
modifier|*
name|releaseModule
parameter_list|()
function_decl|;
comment|/// This method gets the list of libraries that form the path that the
comment|/// Linker will search when it is presented with a library name.
comment|/// @brief Get the Linkers library path
specifier|const
name|std
operator|::
name|vector
operator|<
name|sys
operator|::
name|Path
operator|>
operator|&
name|getLibPaths
argument_list|()
specifier|const
block|{
return|return
name|LibPaths
return|;
block|}
comment|/// This method returns an error string suitable for printing to the user.
comment|/// The return value will be empty unless an error occurred in one of the
comment|/// LinkIn* methods. In those cases, the LinkIn* methods will have returned
comment|/// true, indicating an error occurred. At most one error is retained so
comment|/// this function always returns the last error that occurred. Note that if
comment|/// the Quiet control flag is not set, the error string will have already
comment|/// been printed to stderr.
comment|/// @brief Get the text of the last error that occurred.
specifier|const
name|std
operator|::
name|string
operator|&
name|getLastError
argument_list|()
specifier|const
block|{
return|return
name|Error
return|;
block|}
comment|/// @}
comment|/// @name Mutators
comment|/// @{
name|public
label|:
comment|/// Add a path to the list of paths that the Linker will search. The Linker
comment|/// accumulates the set of libraries added
comment|/// library paths for the target platform. The standard libraries will
comment|/// always be searched last. The added libraries will be searched in the
comment|/// order added.
comment|/// @brief Add a path.
name|void
name|addPath
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|path
argument_list|)
decl_stmt|;
comment|/// Add a set of paths to the list of paths that the linker will search. The
comment|/// Linker accumulates the set of libraries added. The \p paths will be
comment|/// added to the end of the Linker's list. Order will be retained.
comment|/// @brief Add a set of paths.
name|void
name|addPaths
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|paths
argument_list|)
decl_stmt|;
comment|/// This method augments the Linker's list of library paths with the system
comment|/// paths of the host operating system, include LLVM_LIB_SEARCH_PATH.
comment|/// @brief Add the system paths.
name|void
name|addSystemPaths
parameter_list|()
function_decl|;
comment|/// Control optional linker behavior by setting a group of flags. The flags
comment|/// are defined in the ControlFlags enumeration.
comment|/// @see ControlFlags
comment|/// @brief Set control flags.
name|void
name|setFlags
parameter_list|(
name|unsigned
name|flags
parameter_list|)
block|{
name|Flags
operator|=
name|flags
expr_stmt|;
block|}
comment|/// This method is the main interface to the linker. It can be used to
comment|/// link a set of linkage items into a module. A linkage item is either a
comment|/// file name with fully qualified path, or a library for which the Linker's
comment|/// LibraryPath will be utilized to locate the library. The bool value in
comment|/// the LinkItemKind should be set to true for libraries.  This function
comment|/// allows linking to preserve the order of specification associated with
comment|/// the command line, or for other purposes. Each item will be linked in
comment|/// turn as it occurs in \p Items.
comment|/// @returns true if an error occurred, false otherwise
comment|/// @see LinkItemKind
comment|/// @see getLastError
comment|/// @throws nothing
name|bool
name|LinkInItems
parameter_list|(
specifier|const
name|ItemList
modifier|&
name|Items
parameter_list|,
comment|///< Set of libraries/files to link in
name|ItemList
modifier|&
name|NativeItems
comment|///< Output list of native files/libs
parameter_list|)
function_decl|;
comment|/// This function links the bitcode \p Files into the composite module.
comment|/// Note that this does not do any linking of unresolved symbols. The \p
comment|/// Files are all completely linked into \p HeadModule regardless of
comment|/// unresolved symbols. This function just loads each bitcode file and
comment|/// calls LinkInModule on them.
comment|/// @returns true if an error occurs, false otherwise
comment|/// @see getLastError
comment|/// @brief Link in multiple files.
name|bool
name|LinkInFiles
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|sys
operator|::
name|Path
operator|>
operator|&
name|Files
comment|///< Files to link in
argument_list|)
decl_stmt|;
comment|/// This function links a single bitcode file, \p File, into the composite
comment|/// module. Note that this does not attempt to resolve symbols. This method
comment|/// just loads the bitcode file and calls LinkInModule on it. If an error
comment|/// occurs, the Linker's error string is set.
comment|/// @returns true if an error occurs, false otherwise
comment|/// @see getLastError
comment|/// @brief Link in a single file.
name|bool
name|LinkInFile
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|File
argument_list|,
comment|///< File to link in.
name|bool
operator|&
name|is_native
comment|///< Indicates if the file is native object file
argument_list|)
decl_stmt|;
comment|/// This function provides a way to selectively link in a set of modules,
comment|/// found in libraries, based on the unresolved symbols in the composite
comment|/// module. Each item in \p Libraries should be the base name of a library,
comment|/// as if given with the -l option of a linker tool.  The Linker's LibPaths
comment|/// are searched for the \p Libraries and any found will be linked in with
comment|/// LinkInArchive.  If an error occurs, the Linker's error string is set.
comment|/// @see LinkInArchive
comment|/// @see getLastError
comment|/// @returns true if an error occurs, false otherwise
comment|/// @brief Link libraries into the module
name|bool
name|LinkInLibraries
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
operator|&
name|Libraries
comment|///< Libraries to link in
argument_list|)
decl_stmt|;
comment|/// This function provides a way to selectively link in a set of modules,
comment|/// found in one library, based on the unresolved symbols in the composite
comment|/// module.The \p Library should be the base name of a library, as if given
comment|/// with the -l option of a linker tool. The Linker's LibPaths are searched
comment|/// for the \p Library and if found, it will be linked in with via the
comment|/// LinkInArchive method. If an error occurs, the Linker's error string is
comment|/// set.
comment|/// @see LinkInArchive
comment|/// @see getLastError
comment|/// @returns true if an error occurs, false otherwise
comment|/// @brief Link one library into the module
name|bool
name|LinkInLibrary
parameter_list|(
name|StringRef
name|Library
parameter_list|,
comment|///< The library to link in
name|bool
modifier|&
name|is_native
comment|///< Indicates if lib a native library
parameter_list|)
function_decl|;
comment|/// This function links one bitcode archive, \p Filename, into the module.
comment|/// The archive is searched to resolve outstanding symbols. Any modules in
comment|/// the archive that resolve outstanding symbols will be linked in. The
comment|/// library is searched repeatedly until no more modules that resolve
comment|/// symbols can be found. If an error occurs, the error string is  set.
comment|/// To speed up this function, ensure the the archive has been processed
comment|/// llvm-ranlib or the S option was given to llvm-ar when the archive was
comment|/// created. These tools add a symbol table to the archive which makes the
comment|/// search for undefined symbols much faster.
comment|/// @see getLastError
comment|/// @returns true if an error occurs, otherwise false.
comment|/// @brief Link in one archive.
name|bool
name|LinkInArchive
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|Filename
argument_list|,
comment|///< Filename of the archive to link
name|bool
operator|&
name|is_native
comment|///<  Indicates if archive is a native archive
argument_list|)
decl_stmt|;
comment|/// This method links the \p Src module into the Linker's Composite module
comment|/// by calling LinkModules.  All the other LinkIn* methods eventually
comment|/// result in calling this method to link a Module into the Linker's
comment|/// composite.
comment|/// @see LinkModules
comment|/// @returns True if an error occurs, false otherwise.
comment|/// @brief Link in a module.
name|bool
name|LinkInModule
argument_list|(
name|Module
operator|*
name|Src
argument_list|,
comment|///< Module linked into \p Dest
name|std
operator|::
name|string
operator|*
name|ErrorMsg
operator|=
literal|0
comment|/// Error/diagnostic string
argument_list|)
block|{
return|return
name|LinkModules
argument_list|(
name|Composite
argument_list|,
name|Src
argument_list|,
name|ErrorMsg
argument_list|)
return|;
block|}
comment|/// This is the heart of the linker. This method will take unconditional
comment|/// control of the \p Src module and link it into the \p Dest module. The
comment|/// \p Src module will be destructed or subsumed by this method. In either
comment|/// case it is not usable by the caller after this method is invoked. Only
comment|/// the \p Dest module will remain. The \p Src module is linked into the
comment|/// Linker's composite module such that types, global variables, functions,
comment|/// and etc. are matched and resolved.  If an error occurs, this function
comment|/// returns true and ErrorMsg is set to a descriptive message about the
comment|/// error.
comment|/// @returns True if an error occurs, false otherwise.
comment|/// @brief Generically link two modules together.
specifier|static
name|bool
name|LinkModules
argument_list|(
name|Module
operator|*
name|Dest
argument_list|,
name|Module
operator|*
name|Src
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrorMsg
argument_list|)
decl_stmt|;
comment|/// This function looks through the Linker's LibPaths to find a library with
comment|/// the name \p Filename. If the library cannot be found, the returned path
comment|/// will be empty (i.e. sys::Path::isEmpty() will return true).
comment|/// @returns A sys::Path to the found library
comment|/// @brief Find a library from its short name.
name|sys
operator|::
name|Path
name|FindLib
argument_list|(
argument|StringRef Filename
argument_list|)
expr_stmt|;
comment|/// @}
comment|/// @name Implementation
comment|/// @{
name|private
label|:
comment|/// Read in and parse the bitcode file named by FN and return the
comment|/// Module it contains (wrapped in an auto_ptr), or 0 if an error occurs.
name|std
operator|::
name|auto_ptr
operator|<
name|Module
operator|>
name|LoadObject
argument_list|(
specifier|const
name|sys
operator|::
name|Path
operator|&
name|FN
argument_list|)
expr_stmt|;
name|bool
name|warning
parameter_list|(
name|StringRef
name|message
parameter_list|)
function_decl|;
name|bool
name|error
parameter_list|(
name|StringRef
name|message
parameter_list|)
function_decl|;
name|void
name|verbose
parameter_list|(
name|StringRef
name|message
parameter_list|)
function_decl|;
comment|/// @}
comment|/// @name Data
comment|/// @{
name|private
label|:
name|LLVMContext
modifier|&
name|Context
decl_stmt|;
comment|///< The context for global information
name|Module
modifier|*
name|Composite
decl_stmt|;
comment|///< The composite module linked together
name|std
operator|::
name|vector
operator|<
name|sys
operator|::
name|Path
operator|>
name|LibPaths
expr_stmt|;
comment|///< The library search paths
name|unsigned
name|Flags
decl_stmt|;
comment|///< Flags to control optional behavior.
name|std
operator|::
name|string
name|Error
expr_stmt|;
comment|///< Text of error that occurred.
name|std
operator|::
name|string
name|ProgramName
expr_stmt|;
comment|///< Name of the program being linked
comment|/// @}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

