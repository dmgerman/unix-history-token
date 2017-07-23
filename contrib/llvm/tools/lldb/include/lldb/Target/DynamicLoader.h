begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DynamicLoader.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_DynamicLoader_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DynamicLoader_h_
end_define

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_comment
comment|// for FileSpec
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UUID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for LLDB_INVALID_ADDRESS
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for ModuleSP, ThreadPlanSP
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private-enumerations.h"
end_include

begin_comment
comment|// for LazyBool, LazyBool::eLaz...
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_comment
comment|// for addr_t
end_comment

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for int64_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ModuleList
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Process
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SectionList
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Symbol
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SymbolContext
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SymbolContextList
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Thread
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class DynamicLoader DynamicLoader.h "lldb/Target/DynamicLoader.h"
comment|/// @brief A plug-in interface definition class for dynamic loaders.
comment|///
comment|/// Dynamic loader plug-ins track image (shared library) loading and
comment|/// unloading. The class is initialized given a live process that is
comment|/// halted at its entry point or just after attaching.
comment|///
comment|/// Dynamic loader plug-ins can track the process by registering
comment|/// callbacks using the:
comment|/// Process::RegisterNotificationCallbacks (const Notifications&)
comment|/// function.
comment|///
comment|/// Breakpoints can also be set in the process which can register
comment|/// functions that get called using:
comment|/// Process::BreakpointSetCallback (lldb::user_id_t, BreakpointHitCallback, void
comment|/// *).
comment|/// These breakpoint callbacks return a boolean value that indicates if
comment|/// the process should continue or halt and should return the global
comment|/// setting for this using:
comment|/// DynamicLoader::StopWhenImagesChange() const.
comment|//----------------------------------------------------------------------
name|class
name|DynamicLoader
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Find a dynamic loader plugin for a given process.
comment|///
comment|/// Scans the installed DynamicLoader plug-ins and tries to find
comment|/// an instance that can be used to track image changes in \a
comment|/// process.
comment|///
comment|/// @param[in] process
comment|///     The process for which to try and locate a dynamic loader
comment|///     plug-in instance.
comment|///
comment|/// @param[in] plugin_name
comment|///     An optional name of a specific dynamic loader plug-in that
comment|///     should be used. If NULL, pick the best plug-in.
comment|//------------------------------------------------------------------
specifier|static
name|DynamicLoader
operator|*
name|FindPlugin
argument_list|(
name|Process
operator|*
name|process
argument_list|,
specifier|const
name|char
operator|*
name|plugin_name
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Construct with a process.
comment|//------------------------------------------------------------------
name|DynamicLoader
argument_list|(
name|Process
operator|*
name|process
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual since this class is designed to be
comment|/// inherited from by the plug-in instance.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|DynamicLoader
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Called after attaching a process.
comment|///
comment|/// Allow DynamicLoader plug-ins to execute some code after
comment|/// attaching to a process.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidAttach
argument_list|()
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Called after launching a process.
comment|///
comment|/// Allow DynamicLoader plug-ins to execute some code after
comment|/// the process has stopped for the first time on launch.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|DidLaunch
argument_list|()
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Helper function that can be used to detect when a process has
comment|/// called exec and is now a new and different process. This can
comment|/// be called when necessary to try and detect the exec. The process
comment|/// might be able to answer this question, but sometimes it might
comment|/// not be able and the dynamic loader often knows what the program
comment|/// entry point is. So the process and the dynamic loader can work
comment|/// together to detect this.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|ProcessDidExec
argument_list|()
block|{
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get whether the process should stop when images change.
comment|///
comment|/// When images (executables and shared libraries) get loaded or
comment|/// unloaded, often debug sessions will want to try and resolve or
comment|/// unresolve breakpoints that are set in these images. Any
comment|/// breakpoints set by DynamicLoader plug-in instances should
comment|/// return this value to ensure consistent debug session behaviour.
comment|///
comment|/// @return
comment|///     Returns \b true if the process should stop when images
comment|///     change, \b false if the process should resume.
comment|//------------------------------------------------------------------
name|bool
name|GetStopWhenImagesChange
argument_list|()
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// Set whether the process should stop when images change.
comment|///
comment|/// When images (executables and shared libraries) get loaded or
comment|/// unloaded, often debug sessions will want to try and resolve or
comment|/// unresolve breakpoints that are set in these images. The default
comment|/// is set so that the process stops when images change, but this
comment|/// can be overridden using this function callback.
comment|///
comment|/// @param[in] stop
comment|///     Boolean value that indicates whether the process should stop
comment|///     when images change.
comment|//------------------------------------------------------------------
name|void
name|SetStopWhenImagesChange
argument_list|(
argument|bool stop
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Provides a plan to step through the dynamic loader trampoline
comment|/// for the current state of \a thread.
comment|///
comment|///
comment|/// @param[in] stop_others
comment|///     Whether the plan should be set to stop other threads.
comment|///
comment|/// @return
comment|///    A pointer to the plan (caller owned) or NULL if we are not at such
comment|///    a trampoline.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|ThreadPlanSP
name|GetStepThroughTrampolinePlan
argument_list|(
argument|Thread&thread
argument_list|,
argument|bool stop_others
argument_list|)
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Some dynamic loaders provide features where there are a group of symbols
comment|/// "equivalent to"
comment|/// a given symbol one of which will be chosen when the symbol is bound.  If
comment|/// you want to
comment|/// set a breakpoint on one of these symbols, you really need to set it on all
comment|/// the
comment|/// equivalent symbols.
comment|///
comment|///
comment|/// @param[in] original_symbol
comment|///     The symbol for which we are finding equivalences.
comment|///
comment|/// @param[in] module_list
comment|///     The set of modules in which to search.
comment|///
comment|/// @param[out] equivalent_symbols
comment|///     The equivalent symbol list - any equivalent symbols found are appended
comment|///     to this list.
comment|///
comment|/// @return
comment|///    Number of equivalent symbols found.
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|FindEquivalentSymbols
argument_list|(
argument|Symbol *original_symbol
argument_list|,
argument|ModuleList&module_list
argument_list|,
argument|SymbolContextList&equivalent_symbols
argument_list|)
block|{
return|return
literal|0
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Ask if it is ok to try and load or unload an shared library
comment|/// (image).
comment|///
comment|/// The dynamic loader often knows when it would be ok to try and
comment|/// load or unload a shared library. This function call allows the
comment|/// dynamic loader plug-ins to check any current dyld state to make
comment|/// sure it is an ok time to load a shared library.
comment|///
comment|/// @return
comment|///     \b true if it is currently ok to try and load a shared
comment|///     library into the process, \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|Status
name|CanLoadImage
argument_list|()
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Ask if the eh_frame information for the given SymbolContext should
comment|/// be relied on even when it's the first frame in a stack unwind.
comment|///
comment|/// The CFI instructions from the eh_frame section are normally only
comment|/// valid at call sites -- places where a program could throw an
comment|/// exception and need to unwind out.  But some Modules may be known
comment|/// to the system as having reliable eh_frame information at all call
comment|/// sites.  This would be the case if the Module's contents are largely
comment|/// hand-written assembly with hand-written eh_frame information.
comment|/// Normally when unwinding from a function at the beginning of a stack
comment|/// unwind lldb will examine the assembly instructions to understand
comment|/// how the stack frame is set up and where saved registers are stored.
comment|/// But with hand-written assembly this is not reliable enough -- we need
comment|/// to consult those function's hand-written eh_frame information.
comment|///
comment|/// @return
comment|///     \b True if the symbol context should use eh_frame instructions
comment|///     unconditionally when unwinding from this frame.  Else \b false,
comment|///     the normal lldb unwind behavior of only using eh_frame when the
comment|///     function appears in the middle of the stack.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|AlwaysRelyOnEHUnwindInfo
argument_list|(
argument|SymbolContext&sym_ctx
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Retrieves the per-module TLS block for a given thread.
comment|///
comment|/// @param[in] module
comment|///     The module to query TLS data for.
comment|///
comment|/// @param[in] thread
comment|///     The specific thread to query TLS data for.
comment|///
comment|/// @return
comment|///     If the given thread has TLS data allocated for the
comment|///     module, the address of the TLS block. Otherwise
comment|///     LLDB_INVALID_ADDRESS is returned.
comment|//------------------------------------------------------------------
name|virtual
name|lldb
operator|::
name|addr_t
name|GetThreadLocalData
argument_list|(
argument|const lldb::ModuleSP module
argument_list|,
argument|const lldb::ThreadSP thread
argument_list|,
argument|lldb::addr_t tls_file_addr
argument_list|)
block|{
return|return
name|LLDB_INVALID_ADDRESS
return|;
block|}
comment|/// Locates or creates a module given by @p file and updates/loads the
comment|/// resulting module at the virtual base address @p base_addr.
name|virtual
name|lldb
operator|::
name|ModuleSP
name|LoadModuleAtAddress
argument_list|(
argument|const lldb_private::FileSpec&file
argument_list|,
argument|lldb::addr_t link_map_addr
argument_list|,
argument|lldb::addr_t base_addr
argument_list|,
argument|bool base_addr_is_offset
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Get information about the shared cache for a process, if possible.
comment|///
comment|/// On some systems (e.g. Darwin based systems), a set of libraries
comment|/// that are common to most processes may be put in a single region
comment|/// of memory and mapped into every process, this is called the
comment|/// shared cache, as a performance optimization.
comment|///
comment|/// Many targets will not have the concept of a shared cache.
comment|///
comment|/// Depending on how the DynamicLoader gathers information about the
comment|/// shared cache, it may be able to only return basic information -
comment|/// like the UUID of the cache - or it may be able to return additional
comment|/// information about the cache.
comment|///
comment|/// @param[out] base_address
comment|///     The base address (load address) of the shared cache.
comment|///     LLDB_INVALID_ADDRESS if it cannot be determined.
comment|///
comment|/// @param[out] uuid
comment|///     The UUID of the shared cache, if it can be determined.
comment|///     If the UUID cannot be fetched, IsValid() will be false.
comment|///
comment|/// @param[out] using_shared_cache
comment|///     If this process is using a shared cache.
comment|///     If unknown, eLazyBoolCalculate is returned.
comment|///
comment|/// @param[out] private_shared_cache
comment|///     A LazyBool indicating whether this process is using a
comment|///     private shared cache.
comment|///     If this information cannot be fetched, eLazyBoolCalculate.
comment|///
comment|/// @return
comment|///     Returns false if this DynamicLoader cannot gather information
comment|///     about the shared cache / has no concept of a shared cache.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|GetSharedCacheInformation
argument_list|(
argument|lldb::addr_t&base_address
argument_list|,
argument|UUID&uuid
argument_list|,
argument|LazyBool&using_shared_cache
argument_list|,
argument|LazyBool&private_shared_cache
argument_list|)
block|{
name|base_address
operator|=
name|LLDB_INVALID_ADDRESS
block|;
name|uuid
operator|.
name|Clear
argument_list|()
block|;
name|using_shared_cache
operator|=
name|eLazyBoolCalculate
block|;
name|private_shared_cache
operator|=
name|eLazyBoolCalculate
block|;
return|return
name|false
return|;
block|}
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Utility methods for derived classes
comment|//------------------------------------------------------------------
comment|/// Checks to see if the target module has changed, updates the target
comment|/// accordingly and returns the target executable module.
name|lldb
operator|::
name|ModuleSP
name|GetTargetExecutable
argument_list|()
block|;
comment|/// Updates the load address of every allocatable section in @p module.
comment|///
comment|/// @param module The module to traverse.
comment|///
comment|/// @param link_map_addr The virtual address of the link map for the @p
comment|/// module.
comment|///
comment|/// @param base_addr The virtual base address @p module is loaded at.
name|virtual
name|void
name|UpdateLoadedSections
argument_list|(
argument|lldb::ModuleSP module
argument_list|,
argument|lldb::addr_t link_map_addr
argument_list|,
argument|lldb::addr_t base_addr
argument_list|,
argument|bool base_addr_is_offset
argument_list|)
block|;
comment|// Utility method so base classes can share implementation of
comment|// UpdateLoadedSections
name|void
name|UpdateLoadedSectionsCommon
argument_list|(
argument|lldb::ModuleSP module
argument_list|,
argument|lldb::addr_t base_addr
argument_list|,
argument|bool base_addr_is_offset
argument_list|)
block|;
comment|/// Removes the loaded sections from the target in @p module.
comment|///
comment|/// @param module The module to traverse.
name|virtual
name|void
name|UnloadSections
argument_list|(
argument|const lldb::ModuleSP module
argument_list|)
block|;
comment|// Utility method so base classes can share implementation of UnloadSections
name|void
name|UnloadSectionsCommon
argument_list|(
argument|const lldb::ModuleSP module
argument_list|)
block|;
specifier|const
name|lldb_private
operator|::
name|SectionList
operator|*
name|GetSectionListFromModule
argument_list|(
argument|const lldb::ModuleSP module
argument_list|)
specifier|const
block|;
comment|// Read an unsigned int of the given size from memory at the given addr.
comment|// Return -1 if the read fails, otherwise return the result as an int64_t.
name|int64_t
name|ReadUnsignedIntWithSizeInBytes
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|int size_in_bytes
argument_list|)
block|;
comment|// Read a pointer from memory at the given addr.
comment|// Return LLDB_INVALID_ADDRESS if the read fails.
name|lldb
operator|::
name|addr_t
name|ReadPointer
argument_list|(
argument|lldb::addr_t addr
argument_list|)
block|;
comment|// Calls into the Process protected method LoadOperatingSystemPlugin:
name|void
name|LoadOperatingSystemPlugin
argument_list|(
argument|bool flush
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|Process
operator|*
name|m_process
block|;
comment|///< The process that this dynamic loader plug-in is tracking.
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DynamicLoader
argument_list|)
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DynamicLoader_h_
end_comment

end_unit

