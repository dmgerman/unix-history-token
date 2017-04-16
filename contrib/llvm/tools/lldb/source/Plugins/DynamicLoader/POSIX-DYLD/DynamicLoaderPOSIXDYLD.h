begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DynamicLoaderPOSIXDYLD.h --------------------------------*- C++ -*-===//
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
name|liblldb_DynamicLoaderPOSIXDYLD_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DynamicLoaderPOSIXDYLD_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Breakpoint/StoppointCallbackContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/DynamicLoader.h"
end_include

begin_include
include|#
directive|include
file|"DYLDRendezvous.h"
end_include

begin_decl_stmt
name|class
name|AuxVector
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DynamicLoaderPOSIXDYLD
range|:
name|public
name|lldb_private
operator|::
name|DynamicLoader
block|{
name|public
operator|:
name|DynamicLoaderPOSIXDYLD
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
block|;
operator|~
name|DynamicLoaderPOSIXDYLD
argument_list|()
name|override
block|;
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
specifier|const
name|char
operator|*
name|GetPluginDescriptionStatic
argument_list|()
block|;
specifier|static
name|lldb_private
operator|::
name|DynamicLoader
operator|*
name|CreateInstance
argument_list|(
argument|lldb_private::Process *process
argument_list|,
argument|bool force
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|// DynamicLoader protocol
comment|//------------------------------------------------------------------
name|void
name|DidAttach
argument_list|()
name|override
block|;
name|void
name|DidLaunch
argument_list|()
name|override
block|;
name|lldb
operator|::
name|ThreadPlanSP
name|GetStepThroughTrampolinePlan
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|bool stop_others
argument_list|)
name|override
block|;
name|lldb_private
operator|::
name|Error
name|CanLoadImage
argument_list|()
name|override
block|;
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
name|override
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface protocol
comment|//------------------------------------------------------------------
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
name|protected
operator|:
comment|/// Runtime linker rendezvous structure.
name|DYLDRendezvous
name|m_rendezvous
block|;
comment|/// Virtual load address of the inferior process.
name|lldb
operator|::
name|addr_t
name|m_load_offset
block|;
comment|/// Virtual entry address of the inferior process.
name|lldb
operator|::
name|addr_t
name|m_entry_point
block|;
comment|/// Auxiliary vector of the inferior process.
name|std
operator|::
name|unique_ptr
operator|<
name|AuxVector
operator|>
name|m_auxv
block|;
comment|/// Rendezvous breakpoint.
name|lldb
operator|::
name|break_id_t
name|m_dyld_bid
block|;
comment|/// Contains AT_SYSINFO_EHDR, which means a vDSO has been
comment|/// mapped to the address space
name|lldb
operator|::
name|addr_t
name|m_vdso_base
block|;
comment|/// Loaded module list. (link map for each module)
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|ModuleWP
block|,
name|lldb
operator|::
name|addr_t
block|,
name|std
operator|::
name|owner_less
operator|<
name|lldb
operator|::
name|ModuleWP
operator|>>
name|m_loaded_modules
block|;
comment|/// Enables a breakpoint on a function called by the runtime
comment|/// linker each time a module is loaded or unloaded.
name|virtual
name|void
name|SetRendezvousBreakpoint
argument_list|()
block|;
comment|/// Callback routine which updates the current list of loaded modules based
comment|/// on the information supplied by the runtime linker.
specifier|static
name|bool
name|RendezvousBreakpointHit
argument_list|(
argument|void *baton
argument_list|,
argument|lldb_private::StoppointCallbackContext *context
argument_list|,
argument|lldb::user_id_t break_id
argument_list|,
argument|lldb::user_id_t break_loc_id
argument_list|)
block|;
comment|/// Helper method for RendezvousBreakpointHit.  Updates LLDB's current set
comment|/// of loaded modules.
name|void
name|RefreshModules
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
name|override
block|;
comment|/// Removes the loaded sections from the target in @p module.
comment|///
comment|/// @param module The module to traverse.
name|void
name|UnloadSections
argument_list|(
argument|const lldb::ModuleSP module
argument_list|)
name|override
block|;
comment|/// Resolves the entry point for the current inferior process and sets a
comment|/// breakpoint at that address.
name|void
name|ProbeEntry
argument_list|()
block|;
comment|/// Callback routine invoked when we hit the breakpoint on process entry.
comment|///
comment|/// This routine is responsible for resolving the load addresses of all
comment|/// dependent modules required by the inferior and setting up the rendezvous
comment|/// breakpoint.
specifier|static
name|bool
name|EntryBreakpointHit
argument_list|(
argument|void *baton
argument_list|,
argument|lldb_private::StoppointCallbackContext *context
argument_list|,
argument|lldb::user_id_t break_id
argument_list|,
argument|lldb::user_id_t break_loc_id
argument_list|)
block|;
comment|/// Helper for the entry breakpoint callback.  Resolves the load addresses
comment|/// of all dependent modules.
name|virtual
name|void
name|LoadAllCurrentModules
argument_list|()
block|;
comment|/// Computes a value for m_load_offset returning the computed address on
comment|/// success and LLDB_INVALID_ADDRESS on failure.
name|lldb
operator|::
name|addr_t
name|ComputeLoadOffset
argument_list|()
block|;
comment|/// Computes a value for m_entry_point returning the computed address on
comment|/// success and LLDB_INVALID_ADDRESS on failure.
name|lldb
operator|::
name|addr_t
name|GetEntryPoint
argument_list|()
block|;
comment|/// Evaluate if Aux vectors contain vDSO information
comment|/// in case they do, read and assign the address to m_vdso_base
name|void
name|EvalVdsoStatus
argument_list|()
block|;
comment|/// Loads Module from inferior process.
name|void
name|ResolveExecutableModule
argument_list|(
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
block|;
name|bool
name|AlwaysRelyOnEHUnwindInfo
argument_list|(
argument|lldb_private::SymbolContext&sym_ctx
argument_list|)
name|override
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|DynamicLoaderPOSIXDYLD
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DynamicLoaderPOSIXDYLD_h_
end_comment

end_unit

