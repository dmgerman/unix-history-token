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
name|Module
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
comment|/// This class provides the core functionality of linking in LLVM. It retains a
comment|/// Module object which is the composite of the modules and libraries linked
comment|/// into it. The composite Module can be retrieved via the getModule() method.
comment|/// In this case the Linker still retains ownership of the Module. If the
comment|/// releaseModule() method is used, the ownership of the Module is transferred
comment|/// to the caller and the Linker object is only suitable for destruction.
comment|/// The Linker can link Modules from memory. By default, the linker
comment|/// will generate error and warning messages to stderr but this capability can
comment|/// be turned off with the QuietWarnings and QuietErrors flags. It can also be
comment|/// instructed to verbosely print out the linking actions it is taking with
comment|/// the Verbose flag.
comment|/// @brief The LLVM Linker.
name|class
name|Linker
block|{
comment|/// @name Types
comment|/// @{
name|public
label|:
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
enum|enum
name|LinkerMode
block|{
name|DestroySource
init|=
literal|0
block|,
comment|// Allow source module to be destroyed.
name|PreserveSource
init|=
literal|1
comment|// Preserve the source module.
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
comment|/// subsequent linking as if the constructor had been called.
comment|/// @brief Release the linked/composite module.
name|Module
modifier|*
name|releaseModule
parameter_list|()
function_decl|;
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
comment|/// This method links the \p Src module into the Linker's Composite module
comment|/// by calling LinkModules.
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
name|Linker
operator|::
name|DestroySource
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
name|unsigned
name|Mode
argument_list|,
name|std
operator|::
name|string
operator|*
name|ErrorMsg
argument_list|)
decl_stmt|;
comment|/// @}
comment|/// @name Implementation
comment|/// @{
name|private
label|:
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

