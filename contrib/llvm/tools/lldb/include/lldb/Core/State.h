begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- State.h -------------------------------------------------*- C++ -*-===//
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
name|liblldb_State_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_State_h_
end_define

begin_include
include|#
directive|include
file|"llvm/Support/FormatProviders.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for StateType
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_comment
comment|// for raw_ostream
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//------------------------------------------------------------------
comment|/// Converts a StateType to a C string.
comment|///
comment|/// @param[in] state
comment|///     The StateType object to convert.
comment|///
comment|/// @return
comment|///     A NULL terminated C string that describes \a state. The
comment|///     returned string comes from constant string buffers and does
comment|///     not need to be freed.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|StateAsCString
argument_list|(
name|lldb
operator|::
name|StateType
name|state
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if a state represents a state where the process or thread
comment|/// is running.
comment|///
comment|/// @param[in] state
comment|///     The StateType enumeration value
comment|///
comment|/// @return
comment|///     \b true if the state represents a process or thread state
comment|///     where the process or thread is running, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|StateIsRunningState
argument_list|(
name|lldb
operator|::
name|StateType
name|state
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if a state represents a state where the process or thread
comment|/// is stopped. Stopped can mean stopped when the process is still
comment|/// around, or stopped when the process has exited or doesn't exist
comment|/// yet. The \a must_exist argument tells us which of these cases is
comment|/// desired.
comment|///
comment|/// @param[in] state
comment|///     The StateType enumeration value
comment|///
comment|/// @param[in] must_exist
comment|///     A boolean that indicates the thread must also be alive
comment|///     so states like unloaded or exited won't return true.
comment|///
comment|/// @return
comment|///     \b true if the state represents a process or thread state
comment|///     where the process or thread is stopped. If \a must_exist is
comment|///     \b true, then the process can't be exited or unloaded,
comment|///     otherwise exited and unloaded or other states where the
comment|///     process no longer exists are considered to be stopped.
comment|//------------------------------------------------------------------
name|bool
name|StateIsStoppedState
argument_list|(
name|lldb
operator|::
name|StateType
name|state
argument_list|,
name|bool
name|must_exist
argument_list|)
decl_stmt|;
specifier|const
name|char
modifier|*
name|GetPermissionsAsCString
parameter_list|(
name|uint32_t
name|permissions
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|format_provider
operator|<
name|lldb
operator|::
name|StateType
operator|>
block|{
specifier|static
name|void
name|format
argument_list|(
argument|const lldb::StateType&state
argument_list|,
argument|raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
block|{
name|Stream
operator|<<
name|lldb_private
operator|::
name|StateAsCString
argument_list|(
name|state
argument_list|)
block|;   }
block|}
expr_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_State_h_
end_comment

end_unit

