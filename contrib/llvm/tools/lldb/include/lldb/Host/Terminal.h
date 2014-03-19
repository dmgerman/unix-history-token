begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Terminal.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_Terminal_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Terminal_h_
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Config.h"
end_include

begin_struct_decl
struct_decl|struct
name|termios
struct_decl|;
end_struct_decl

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Terminal
block|{
name|public
label|:
name|Terminal
argument_list|(
argument|int fd = -
literal|1
argument_list|)
block|:
name|m_fd
argument_list|(
argument|fd
argument_list|)
block|{     }
operator|~
name|Terminal
argument_list|()
block|{     }
name|bool
name|IsATerminal
argument_list|()
specifier|const
expr_stmt|;
name|int
name|GetFileDescriptor
argument_list|()
specifier|const
block|{
return|return
name|m_fd
return|;
block|}
name|void
name|SetFileDescriptor
parameter_list|(
name|int
name|fd
parameter_list|)
block|{
name|m_fd
operator|=
name|fd
expr_stmt|;
block|}
name|bool
name|FileDescriptorIsValid
argument_list|()
specifier|const
block|{
return|return
name|m_fd
operator|!=
operator|-
literal|1
return|;
block|}
name|void
name|Clear
parameter_list|()
block|{
name|m_fd
operator|=
operator|-
literal|1
expr_stmt|;
block|}
name|bool
name|SetEcho
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|bool
name|SetCanonical
parameter_list|(
name|bool
name|enabled
parameter_list|)
function_decl|;
name|protected
label|:
name|int
name|m_fd
decl_stmt|;
comment|// This may or may not be a terminal file descriptor
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class State Terminal.h "lldb/Host/Terminal.h"
comment|/// @brief A terminal state saving/restoring class.
comment|///
comment|/// This class can be used to remember the terminal state for a file
comment|/// descriptor and later restore that state as it originally was.
comment|//----------------------------------------------------------------------
name|class
name|TerminalState
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor
comment|//------------------------------------------------------------------
name|TerminalState
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|TerminalState
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Save the TTY state for \a fd.
comment|///
comment|/// Save the current state of the TTY for the file descriptor "fd"
comment|/// and if "save_process_group" is true, attempt to save the process
comment|/// group info for the TTY.
comment|///
comment|/// @param[in] fd
comment|///     The file descriptor to save the state of.
comment|///
comment|/// @param[in] save_process_group
comment|///     If \b true, save the process group settings, else do not
comment|///     save the process group setttings for a TTY.
comment|///
comment|/// @return
comment|///     Returns \b true if \a fd describes a TTY and if the state
comment|///     was able to be saved, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Save
parameter_list|(
name|int
name|fd
parameter_list|,
name|bool
name|save_process_group
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Restore the TTY state to the cached state.
comment|///
comment|/// Restore the state of the TTY using the cached values from a
comment|/// previous call to TerminalState::Save(int,bool).
comment|///
comment|/// @return
comment|///     Returns \b true if the TTY state was successfully restored,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Restore
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Test for valid cached TTY state information.
comment|///
comment|/// @return
comment|///     Returns \b true if this object has valid saved TTY state
comment|///     settings that can be used to restore a previous state,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|/// Test if tflags is valid.
comment|///
comment|/// @return
comment|///     Returns \b true if \a m_tflags is valid and can be restored,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|TFlagsIsValid
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Test if ttystate is valid.
comment|///
comment|/// @return
comment|///     Returns \b true if \a m_ttystate is valid and can be
comment|///     restored, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|TTYStateIsValid
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Test if the process group information is valid.
comment|///
comment|/// @return
comment|///     Returns \b true if \a m_process_group is valid and can be
comment|///     restored, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|ProcessGroupIsValid
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|Terminal
name|m_tty
decl_stmt|;
comment|///< A terminal
name|int
name|m_tflags
decl_stmt|;
comment|///< Cached tflags information.
ifdef|#
directive|ifdef
name|LLDB_CONFIG_TERMIOS_SUPPORTED
name|std
operator|::
name|unique_ptr
operator|<
expr|struct
name|termios
operator|>
name|m_termios_ap
expr_stmt|;
comment|///< Cached terminal state information.
endif|#
directive|endif
name|lldb
operator|::
name|pid_t
name|m_process_group
expr_stmt|;
comment|///< Cached process group information.
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class TerminalStateSwitcher Terminal.h "lldb/Host/Terminal.h"
comment|/// @brief A TTY state switching class.
comment|///
comment|/// This class can be used to remember 2 TTY states for a given file
comment|/// descriptor and switch between the two states.
comment|//----------------------------------------------------------------------
name|class
name|TerminalStateSwitcher
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|//------------------------------------------------------------------
name|TerminalStateSwitcher
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|TerminalStateSwitcher
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the number of possible states to save.
comment|///
comment|/// @return
comment|///     The number of states that this TTY switcher object contains.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetNumberOfStates
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Restore the TTY state for state at index \a idx.
comment|///
comment|/// @return
comment|///     Returns \b true if the TTY state was successfully restored,
comment|///     \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Restore
argument_list|(
name|uint32_t
name|idx
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Save the TTY state information for the state at index \a idx.
comment|/// The TTY state is saved for the file descriptor \a fd and
comment|/// the process group information will also be saved if requested
comment|/// by \a save_process_group.
comment|///
comment|/// @param[in] idx
comment|///     The index into the state array where the state should be
comment|///     saved.
comment|///
comment|/// @param[in] fd
comment|///     The file descriptor for which to save the settings.
comment|///
comment|/// @param[in] save_process_group
comment|///     If \b true, save the process group information for the TTY.
comment|///
comment|/// @return
comment|///     Returns \b true if the save was successful, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Save
parameter_list|(
name|uint32_t
name|idx
parameter_list|,
name|int
name|fd
parameter_list|,
name|bool
name|save_process_group
parameter_list|)
function_decl|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables
comment|//------------------------------------------------------------------
name|mutable
name|uint32_t
name|m_currentState
decl_stmt|;
comment|///< The currently active TTY state index.
name|TerminalState
name|m_ttystates
index|[
literal|2
index|]
decl_stmt|;
comment|///< The array of TTY states that holds saved TTY info.
block|}
empty_stmt|;
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
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_Terminal_h_
end_comment

end_unit

