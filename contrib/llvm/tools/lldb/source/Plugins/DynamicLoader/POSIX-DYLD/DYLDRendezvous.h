begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DYLDRendezvous.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_Rendezvous_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Rendezvous_H_
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
file|<list>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-types.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/LoadedModuleInfoList.h"
end_include

begin_expr_stmt
name|using
name|lldb_private
operator|::
name|LoadedModuleInfoList
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Process
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|/// @class DYLDRendezvous
end_comment

begin_comment
comment|/// @brief Interface to the runtime linker.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A structure is present in a processes memory space which is updated by the
end_comment

begin_comment
comment|/// runtime liker each time a module is loaded or unloaded.  This class provides
end_comment

begin_comment
comment|/// an interface to this structure and maintains a consistent snapshot of the
end_comment

begin_comment
comment|/// currently loaded modules.
end_comment

begin_decl_stmt
name|class
name|DYLDRendezvous
block|{
comment|// This structure is used to hold the contents of the debug rendezvous
comment|// information (struct r_debug) as found in the inferiors memory.  Note that
comment|// the layout of this struct is not binary compatible, it is simply large
comment|// enough to hold the information on both 32 and 64 bit platforms.
struct|struct
name|Rendezvous
block|{
name|uint64_t
name|version
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|map_addr
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|brk
expr_stmt|;
name|uint64_t
name|state
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|ldbase
expr_stmt|;
name|Rendezvous
argument_list|()
operator|:
name|version
argument_list|(
literal|0
argument_list|)
operator|,
name|map_addr
argument_list|(
literal|0
argument_list|)
operator|,
name|brk
argument_list|(
literal|0
argument_list|)
operator|,
name|state
argument_list|(
literal|0
argument_list|)
operator|,
name|ldbase
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
name|public
label|:
comment|// Various metadata supplied by the inferior's threading library to describe
comment|// the per-thread state.
struct|struct
name|ThreadInfo
block|{
name|bool
name|valid
decl_stmt|;
comment|// whether we read valid metadata
name|uint32_t
name|dtv_offset
decl_stmt|;
comment|// offset of DTV pointer within pthread
name|uint32_t
name|dtv_slot_size
decl_stmt|;
comment|// size of one DTV slot
name|uint32_t
name|modid_offset
decl_stmt|;
comment|// offset of module ID within link_map
name|uint32_t
name|tls_offset
decl_stmt|;
comment|// offset of TLS pointer within DTV slot
block|}
struct|;
name|DYLDRendezvous
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
comment|/// Update the internal snapshot of runtime linker rendezvous and recompute
comment|/// the currently loaded modules.
comment|///
comment|/// This method should be called once one start up, then once each time the
comment|/// runtime linker enters the function given by GetBreakAddress().
comment|///
comment|/// @returns true on success and false on failure.
comment|///
comment|/// @see GetBreakAddress().
name|bool
name|Resolve
parameter_list|()
function_decl|;
comment|/// @returns true if this rendezvous has been located in the inferiors
comment|/// address space and false otherwise.
name|bool
name|IsValid
parameter_list|()
function_decl|;
comment|/// @returns the address of the rendezvous structure in the inferiors
comment|/// address space.
name|lldb
operator|::
name|addr_t
name|GetRendezvousAddress
argument_list|()
specifier|const
block|{
return|return
name|m_rendezvous_addr
return|;
block|}
comment|/// @returns the version of the rendezvous protocol being used.
name|uint64_t
name|GetVersion
argument_list|()
specifier|const
block|{
return|return
name|m_current
operator|.
name|version
return|;
block|}
comment|/// @returns address in the inferiors address space containing the linked
comment|/// list of shared object descriptors.
name|lldb
operator|::
name|addr_t
name|GetLinkMapAddress
argument_list|()
specifier|const
block|{
return|return
name|m_current
operator|.
name|map_addr
return|;
block|}
comment|/// A breakpoint should be set at this address and Resolve called on each
comment|/// hit.
comment|///
comment|/// @returns the address of a function called by the runtime linker each
comment|/// time a module is loaded/unloaded, or about to be loaded/unloaded.
comment|///
comment|/// @see Resolve()
name|lldb
operator|::
name|addr_t
name|GetBreakAddress
argument_list|()
specifier|const
block|{
return|return
name|m_current
operator|.
name|brk
return|;
block|}
comment|/// Returns the current state of the rendezvous structure.
name|uint64_t
name|GetState
argument_list|()
specifier|const
block|{
return|return
name|m_current
operator|.
name|state
return|;
block|}
comment|/// @returns the base address of the runtime linker in the inferiors address
comment|/// space.
name|lldb
operator|::
name|addr_t
name|GetLDBase
argument_list|()
specifier|const
block|{
return|return
name|m_current
operator|.
name|ldbase
return|;
block|}
comment|/// @returns the thread layout metadata from the inferiors thread library.
specifier|const
name|ThreadInfo
modifier|&
name|GetThreadInfo
parameter_list|()
function_decl|;
comment|/// @returns true if modules have been loaded into the inferior since the
comment|/// last call to Resolve().
name|bool
name|ModulesDidLoad
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_added_soentries
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// @returns true if modules have been unloaded from the inferior since the
comment|/// last call to Resolve().
name|bool
name|ModulesDidUnload
argument_list|()
specifier|const
block|{
return|return
operator|!
name|m_removed_soentries
operator|.
name|empty
argument_list|()
return|;
block|}
name|void
name|DumpToLog
argument_list|(
name|lldb_private
operator|::
name|Log
operator|*
name|log
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Constants describing the state of the rendezvous.
comment|///
comment|/// @see GetState().
enum|enum
name|RendezvousState
block|{
name|eConsistent
block|,
name|eAdd
block|,
name|eDelete
block|}
enum|;
comment|/// @brief Structure representing the shared objects currently loaded into
comment|/// the inferior process.
comment|///
comment|/// This object is a rough analogue to the struct link_map object which
comment|/// actually lives in the inferiors memory.
struct|struct
name|SOEntry
block|{
name|lldb
operator|::
name|addr_t
name|link_addr
expr_stmt|;
comment|///< Address of this link_map.
name|lldb
operator|::
name|addr_t
name|base_addr
expr_stmt|;
comment|///< Base address of the loaded object.
name|lldb
operator|::
name|addr_t
name|path_addr
expr_stmt|;
comment|///< String naming the shared object.
name|lldb
operator|::
name|addr_t
name|dyn_addr
expr_stmt|;
comment|///< Dynamic section of shared object.
name|lldb
operator|::
name|addr_t
name|next
expr_stmt|;
comment|///< Address of next so_entry.
name|lldb
operator|::
name|addr_t
name|prev
expr_stmt|;
comment|///< Address of previous so_entry.
name|lldb_private
operator|::
name|FileSpec
name|file_spec
expr_stmt|;
comment|///< File spec of shared object.
name|SOEntry
argument_list|()
block|{
name|clear
argument_list|()
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SOEntry
operator|&
name|entry
operator|)
block|{
return|return
name|file_spec
operator|==
name|entry
operator|.
name|file_spec
return|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|link_addr
operator|=
literal|0
expr_stmt|;
name|base_addr
operator|=
literal|0
expr_stmt|;
name|path_addr
operator|=
literal|0
expr_stmt|;
name|dyn_addr
operator|=
literal|0
expr_stmt|;
name|next
operator|=
literal|0
expr_stmt|;
name|prev
operator|=
literal|0
expr_stmt|;
name|file_spec
operator|.
name|Clear
argument_list|()
expr_stmt|;
block|}
block|}
struct|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|list
operator|<
name|SOEntry
operator|>
name|SOEntryList
expr_stmt|;
name|public
label|:
typedef|typedef
name|SOEntryList
operator|::
name|const_iterator
name|iterator
expr_stmt|;
comment|/// Iterators over all currently loaded modules.
name|iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|m_soentries
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|m_soentries
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Iterators over all modules loaded into the inferior since the last call
comment|/// to Resolve().
name|iterator
name|loaded_begin
argument_list|()
specifier|const
block|{
return|return
name|m_added_soentries
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|loaded_end
argument_list|()
specifier|const
block|{
return|return
name|m_added_soentries
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Iterators over all modules unloaded from the inferior since the last
comment|/// call to Resolve().
name|iterator
name|unloaded_begin
argument_list|()
specifier|const
block|{
return|return
name|m_removed_soentries
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|unloaded_end
argument_list|()
specifier|const
block|{
return|return
name|m_removed_soentries
operator|.
name|end
argument_list|()
return|;
block|}
name|protected
label|:
name|lldb_private
operator|::
name|Process
operator|*
name|m_process
expr_stmt|;
comment|// Cached copy of executable file spec
name|lldb_private
operator|::
name|FileSpec
name|m_exe_file_spec
expr_stmt|;
comment|/// Location of the r_debug structure in the inferiors address space.
name|lldb
operator|::
name|addr_t
name|m_rendezvous_addr
expr_stmt|;
comment|/// Current and previous snapshots of the rendezvous structure.
name|Rendezvous
name|m_current
decl_stmt|;
name|Rendezvous
name|m_previous
decl_stmt|;
comment|/// List of currently loaded SO modules
name|LoadedModuleInfoList
name|m_loaded_modules
decl_stmt|;
comment|/// List of SOEntry objects corresponding to the current link map state.
name|SOEntryList
name|m_soentries
decl_stmt|;
comment|/// List of SOEntry's added to the link map since the last call to Resolve().
name|SOEntryList
name|m_added_soentries
decl_stmt|;
comment|/// List of SOEntry's removed from the link map since the last call to
comment|/// Resolve().
name|SOEntryList
name|m_removed_soentries
decl_stmt|;
comment|/// Threading metadata read from the inferior.
name|ThreadInfo
name|m_thread_info
decl_stmt|;
comment|/// Reads an unsigned integer of @p size bytes from the inferior's address
comment|/// space starting at @p addr.
comment|///
comment|/// @returns addr + size if the read was successful and false otherwise.
name|lldb
operator|::
name|addr_t
name|ReadWord
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|uint64_t *dst
argument_list|,
argument|size_t size
argument_list|)
expr_stmt|;
comment|/// Reads an address from the inferior's address space starting at @p addr.
comment|///
comment|/// @returns addr + target address size if the read was successful and
comment|/// 0 otherwise.
name|lldb
operator|::
name|addr_t
name|ReadPointer
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|lldb::addr_t *dst
argument_list|)
expr_stmt|;
comment|/// Reads a null-terminated C string from the memory location starting at @p
comment|/// addr.
name|std
operator|::
name|string
name|ReadStringFromMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|)
expr_stmt|;
comment|/// Reads an SOEntry starting at @p addr.
name|bool
name|ReadSOEntryFromMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|SOEntry
operator|&
name|entry
argument_list|)
decl_stmt|;
comment|/// Updates the current set of SOEntries, the set of added entries, and the
comment|/// set of removed entries.
name|bool
name|UpdateSOEntries
parameter_list|(
name|bool
name|fromRemote
init|=
name|false
parameter_list|)
function_decl|;
name|bool
name|FillSOEntryFromModuleInfo
argument_list|(
name|LoadedModuleInfoList
operator|::
name|LoadedModuleInfo
specifier|const
operator|&
name|modInfo
argument_list|,
name|SOEntry
operator|&
name|entry
argument_list|)
decl_stmt|;
name|bool
name|SaveSOEntriesFromRemote
parameter_list|(
name|LoadedModuleInfoList
modifier|&
name|module_list
parameter_list|)
function_decl|;
name|bool
name|AddSOEntriesFromRemote
parameter_list|(
name|LoadedModuleInfoList
modifier|&
name|module_list
parameter_list|)
function_decl|;
name|bool
name|RemoveSOEntriesFromRemote
parameter_list|(
name|LoadedModuleInfoList
modifier|&
name|module_list
parameter_list|)
function_decl|;
name|bool
name|AddSOEntries
parameter_list|()
function_decl|;
name|bool
name|RemoveSOEntries
parameter_list|()
function_decl|;
name|void
name|UpdateBaseAddrIfNecessary
argument_list|(
name|SOEntry
operator|&
name|entry
argument_list|,
name|std
operator|::
name|string
specifier|const
operator|&
name|file_path
argument_list|)
decl_stmt|;
name|bool
name|SOEntryIsMainExecutable
parameter_list|(
specifier|const
name|SOEntry
modifier|&
name|entry
parameter_list|)
function_decl|;
comment|/// Reads the current list of shared objects according to the link map
comment|/// supplied by the runtime linker.
name|bool
name|TakeSnapshot
parameter_list|(
name|SOEntryList
modifier|&
name|entry_list
parameter_list|)
function_decl|;
enum|enum
name|PThreadField
block|{
name|eSize
block|,
name|eNElem
block|,
name|eOffset
block|}
enum|;
name|bool
name|FindMetadata
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|PThreadField
name|field
parameter_list|,
name|uint32_t
modifier|&
name|value
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

