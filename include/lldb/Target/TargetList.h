begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TargetList.h --------------------------------------------*- C++ -*-===//
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
name|liblldb_TargetList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_TargetList_h_
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
file|<mutex>
end_include

begin_include
include|#
directive|include
file|<vector>
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
file|"lldb/Core/Broadcaster.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Target.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|TargetList
range|:
name|public
name|Broadcaster
block|{
name|private
operator|:
name|friend
name|class
name|Debugger
block|;
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// The constructor for the target list is private. Clients can
comment|/// get ahold of of the one and only target list through the
comment|/// lldb_private::Debugger::GetSharedInstance().GetTargetList().
comment|///
comment|/// @see static TargetList& lldb_private::Debugger::GetTargetList().
comment|//------------------------------------------------------------------
name|TargetList
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|)
block|;
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Broadcaster event bits definitions.
comment|//------------------------------------------------------------------
expr|enum
block|{
name|eBroadcastBitInterrupt
operator|=
operator|(
literal|1
operator|<<
literal|0
operator|)
block|}
block|;
comment|// These two functions fill out the Broadcaster interface:
specifier|static
name|ConstString
operator|&
name|GetStaticBroadcasterClass
argument_list|()
block|;
name|ConstString
operator|&
name|GetBroadcasterClass
argument_list|()
specifier|const
name|override
block|{
return|return
name|GetStaticBroadcasterClass
argument_list|()
return|;
block|}
operator|~
name|TargetList
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Create a new Target.
comment|///
comment|/// Clients must use this function to create a Target. This allows
comment|/// a global list of targets to be maintained in a central location
comment|/// so signal handlers and other global functions can use it to
comment|/// locate an appropriate target to deliver asynchronous information
comment|/// to.
comment|///
comment|/// @param[in] debugger
comment|///     The debugger to associate this target with
comment|///
comment|/// @param[in] file_spec
comment|///     The main executable file for a debug target. This value
comment|///     can be nullptr and the file can be set later using:
comment|///     Target::SetExecutableModule (ModuleSP&)
comment|///
comment|/// @param[in] triple_cstr
comment|///     A target triple string to be used for the target. This can
comment|///     be nullptr if the triple is not known or when attaching to a
comment|///     process.
comment|///
comment|/// @param[in] get_dependent_modules
comment|///     Track down the dependent modules for an executable and
comment|///     load those into the module list.
comment|///
comment|/// @param[in] platform_options
comment|///     A pointer to the platform options to use when creating this
comment|///     target. If this value is nullptr, then the currently selected
comment|///     platform will be used.
comment|///
comment|/// @param[out] target_sp
comment|///     A shared pointer to a target that will be filled in if
comment|///     this call is successful.
comment|///
comment|/// @return
comment|///     An error object that indicates success or failure
comment|//------------------------------------------------------------------
name|Status
name|CreateTarget
argument_list|(
argument|Debugger&debugger
argument_list|,
argument|llvm::StringRef user_exe_path
argument_list|,
argument|llvm::StringRef triple_str
argument_list|,
argument|bool get_dependent_modules
argument_list|,
argument|const OptionGroupPlatform *platform_options
argument_list|,
argument|lldb::TargetSP&target_sp
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Create a new Target.
comment|///
comment|/// Same as the function above, but used when you already know the
comment|/// platform you will be using
comment|//------------------------------------------------------------------
name|Status
name|CreateTarget
argument_list|(
argument|Debugger&debugger
argument_list|,
argument|llvm::StringRef user_exe_path
argument_list|,
argument|const ArchSpec&arch
argument_list|,
argument|bool get_dependent_modules
argument_list|,
argument|lldb::PlatformSP&platform_sp
argument_list|,
argument|lldb::TargetSP&target_sp
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Delete a Target object from the list.
comment|///
comment|/// When clients are done with the Target objects, this function
comment|/// should be called to release the memory associated with a target
comment|/// object.
comment|///
comment|/// @param[in] target_sp
comment|///     The shared pointer to a target.
comment|///
comment|/// @return
comment|///     Returns \b true if the target was successfully removed from
comment|///     from this target list, \b false otherwise. The client will
comment|///     be left with the last remaining shared pointer to the target
comment|///     in \a target_sp which can then be properly released.
comment|//------------------------------------------------------------------
name|bool
name|DeleteTarget
argument_list|(
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|)
block|;
name|int
name|GetNumTargets
argument_list|()
specifier|const
block|;
name|lldb
operator|::
name|TargetSP
name|GetTargetAtIndex
argument_list|(
argument|uint32_t index
argument_list|)
specifier|const
block|;
name|uint32_t
name|GetIndexOfTarget
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|)
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// Find the target that contains has an executable whose path
comment|/// matches \a exe_file_spec, and whose architecture matches
comment|/// \a arch_ptr if arch_ptr is not nullptr.
comment|///
comment|/// @param[in] exe_file_spec
comment|///     A file spec containing a basename, or a full path (directory
comment|///     and basename). If \a exe_file_spec contains only a filename
comment|///     (empty GetDirectory() value) then matching will be done
comment|///     solely based on the filenames and directories won't be
comment|///     compared. If \a exe_file_spec contains a filename and a
comment|///     directory, then both must match.
comment|///
comment|/// @param[in] exe_arch_ptr
comment|///     If not nullptr then the architecture also needs to match, else
comment|///     the architectures will be compared.
comment|///
comment|/// @return
comment|///     A shared pointer to a target object. The returned shared
comment|///     pointer will contain nullptr if no target objects have a
comment|///     executable whose full or partial path matches
comment|///     with a matching process ID.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetSP
name|FindTargetWithExecutableAndArchitecture
argument_list|(
argument|const FileSpec&exe_file_spec
argument_list|,
argument|const ArchSpec *exe_arch_ptr = nullptr
argument_list|)
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// Find the target that contains a process with process ID \a
comment|/// pid.
comment|///
comment|/// @param[in] pid
comment|///     The process ID to search our target list for.
comment|///
comment|/// @return
comment|///     A shared pointer to a target object. The returned shared
comment|///     pointer will contain nullptr if no target objects own a process
comment|///     with a matching process ID.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|TargetSP
name|FindTargetWithProcessID
argument_list|(
argument|lldb::pid_t pid
argument_list|)
specifier|const
block|;
name|lldb
operator|::
name|TargetSP
name|FindTargetWithProcess
argument_list|(
argument|lldb_private::Process *process
argument_list|)
specifier|const
block|;
name|lldb
operator|::
name|TargetSP
name|GetTargetSP
argument_list|(
argument|Target *target
argument_list|)
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// Send an async interrupt to one or all processes.
comment|///
comment|/// Find the target that contains the process with process ID \a
comment|/// pid and send a LLDB_EVENT_ASYNC_INTERRUPT event to the process's
comment|/// event queue.
comment|///
comment|/// @param[in] pid
comment|///     The process ID to search our target list for, if \a pid is
comment|///     LLDB_INVALID_PROCESS_ID, then the interrupt will be sent to
comment|///     all processes.
comment|///
comment|/// @return
comment|///     The number of async interrupts sent.
comment|//------------------------------------------------------------------
name|uint32_t
name|SendAsyncInterrupt
argument_list|(
argument|lldb::pid_t pid = LLDB_INVALID_PROCESS_ID
argument_list|)
block|;
name|uint32_t
name|SignalIfRunning
argument_list|(
argument|lldb::pid_t pid
argument_list|,
argument|int signo
argument_list|)
block|;
name|uint32_t
name|SetSelectedTarget
argument_list|(
name|Target
operator|*
name|target
argument_list|)
block|;
name|lldb
operator|::
name|TargetSP
name|GetSelectedTarget
argument_list|()
block|;
name|protected
operator|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|TargetSP
operator|>
name|collection
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|collection
name|m_target_list
decl_stmt|;
name|lldb
operator|::
name|TargetSP
name|m_dummy_target_sp
expr_stmt|;
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_target_list_mutex
expr_stmt|;
name|uint32_t
name|m_selected_target_idx
decl_stmt|;
name|private
label|:
name|lldb
operator|::
name|TargetSP
name|GetDummyTarget
argument_list|(
name|lldb_private
operator|::
name|Debugger
operator|&
name|debugger
argument_list|)
expr_stmt|;
name|Status
name|CreateDummyTarget
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|,
name|llvm
operator|::
name|StringRef
name|specified_arch_name
argument_list|,
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|)
decl_stmt|;
name|Status
name|CreateTargetInternal
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|,
name|llvm
operator|::
name|StringRef
name|user_exe_path
argument_list|,
name|llvm
operator|::
name|StringRef
name|triple_str
argument_list|,
name|bool
name|get_dependent_files
argument_list|,
specifier|const
name|OptionGroupPlatform
operator|*
name|platform_options
argument_list|,
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|,
name|bool
name|is_dummy_target
argument_list|)
decl_stmt|;
name|Status
name|CreateTargetInternal
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|,
name|llvm
operator|::
name|StringRef
name|user_exe_path
argument_list|,
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|,
name|bool
name|get_dependent_modules
argument_list|,
name|lldb
operator|::
name|PlatformSP
operator|&
name|platform_sp
argument_list|,
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|,
name|bool
name|is_dummy_target
argument_list|)
decl_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|TargetList
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_TargetList_h_
end_comment

end_unit

