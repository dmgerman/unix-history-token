begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- OProfileWrapper.h - OProfile JIT API Wrapper ------------*- C++ -*-===//
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
comment|// This file defines a OProfileWrapper object that detects if the oprofile
end_comment

begin_comment
comment|// daemon is running, and provides wrappers for opagent functions used to
end_comment

begin_comment
comment|// communicate with the oprofile JIT interface. The dynamic library libopagent
end_comment

begin_comment
comment|// does not need to be linked directly as this object lazily loads the library
end_comment

begin_comment
comment|// when the first op_ function is called.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// See http://oprofile.sourceforge.net/doc/devel/jit-interface.html for the
end_comment

begin_comment
comment|// definition of the interface.
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
name|LLVM_EXECUTIONENGINE_OPROFILEWRAPPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_OPROFILEWRAPPER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<opagent.h>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|OProfileWrapper
block|{
typedef|typedef
name|op_agent_t
function_decl|(
modifier|*
name|op_open_agent_ptr_t
function_decl|)
parameter_list|()
function_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|op_close_agent_ptr_t
function_decl|)
parameter_list|(
name|op_agent_t
parameter_list|)
function_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|op_write_native_code_ptr_t
function_decl|)
parameter_list|(
name|op_agent_t
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|uint64_t
parameter_list|,
name|void
specifier|const
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|int
parameter_list|)
function_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|op_write_debug_line_info_ptr_t
function_decl|)
parameter_list|(
name|op_agent_t
parameter_list|,
name|void
specifier|const
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|struct
name|debug_line_info
specifier|const
modifier|*
parameter_list|)
function_decl|;
typedef|typedef
name|int
function_decl|(
modifier|*
name|op_unload_native_code_ptr_t
function_decl|)
parameter_list|(
name|op_agent_t
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
comment|// Also used for op_minor_version function which has the same signature
typedef|typedef
name|int
function_decl|(
modifier|*
name|op_major_version_ptr_t
function_decl|)
parameter_list|()
function_decl|;
comment|// This is not a part of the opagent API, but is useful nonetheless
typedef|typedef
name|bool
function_decl|(
modifier|*
name|IsOProfileRunningPtrT
function_decl|)
parameter_list|()
function_decl|;
name|op_agent_t
name|Agent
decl_stmt|;
name|op_open_agent_ptr_t
name|OpenAgentFunc
decl_stmt|;
name|op_close_agent_ptr_t
name|CloseAgentFunc
decl_stmt|;
name|op_write_native_code_ptr_t
name|WriteNativeCodeFunc
decl_stmt|;
name|op_write_debug_line_info_ptr_t
name|WriteDebugLineInfoFunc
decl_stmt|;
name|op_unload_native_code_ptr_t
name|UnloadNativeCodeFunc
decl_stmt|;
name|op_major_version_ptr_t
name|MajorVersionFunc
decl_stmt|;
name|op_major_version_ptr_t
name|MinorVersionFunc
decl_stmt|;
name|IsOProfileRunningPtrT
name|IsOProfileRunningFunc
decl_stmt|;
name|bool
name|Initialized
decl_stmt|;
name|public
label|:
name|OProfileWrapper
argument_list|()
expr_stmt|;
comment|// For testing with a mock opagent implementation, skips the dynamic load and
comment|// the function resolution.
name|OProfileWrapper
argument_list|(
argument|op_open_agent_ptr_t OpenAgentImpl
argument_list|,
argument|op_close_agent_ptr_t CloseAgentImpl
argument_list|,
argument|op_write_native_code_ptr_t WriteNativeCodeImpl
argument_list|,
argument|op_write_debug_line_info_ptr_t WriteDebugLineInfoImpl
argument_list|,
argument|op_unload_native_code_ptr_t UnloadNativeCodeImpl
argument_list|,
argument|op_major_version_ptr_t MajorVersionImpl
argument_list|,
argument|op_major_version_ptr_t MinorVersionImpl
argument_list|,
argument|IsOProfileRunningPtrT MockIsOProfileRunningImpl =
literal|0
argument_list|)
block|:
name|OpenAgentFunc
argument_list|(
name|OpenAgentImpl
argument_list|)
operator|,
name|CloseAgentFunc
argument_list|(
name|CloseAgentImpl
argument_list|)
operator|,
name|WriteNativeCodeFunc
argument_list|(
name|WriteNativeCodeImpl
argument_list|)
operator|,
name|WriteDebugLineInfoFunc
argument_list|(
name|WriteDebugLineInfoImpl
argument_list|)
operator|,
name|UnloadNativeCodeFunc
argument_list|(
name|UnloadNativeCodeImpl
argument_list|)
operator|,
name|MajorVersionFunc
argument_list|(
name|MajorVersionImpl
argument_list|)
operator|,
name|MinorVersionFunc
argument_list|(
name|MinorVersionImpl
argument_list|)
operator|,
name|IsOProfileRunningFunc
argument_list|(
name|MockIsOProfileRunningImpl
argument_list|)
operator|,
name|Initialized
argument_list|(
argument|true
argument_list|)
block|{   }
comment|// Calls op_open_agent in the oprofile JIT library and saves the returned
comment|// op_agent_t handle internally so it can be used when calling all the other
comment|// op_* functions. Callers of this class do not need to keep track of
comment|// op_agent_t objects.
name|bool
name|op_open_agent
argument_list|()
expr_stmt|;
name|int
name|op_close_agent
parameter_list|()
function_decl|;
name|int
name|op_write_native_code
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|uint64_t
name|addr
parameter_list|,
name|void
specifier|const
modifier|*
name|code
parameter_list|,
specifier|const
name|unsigned
name|int
name|size
parameter_list|)
function_decl|;
name|int
name|op_write_debug_line_info
parameter_list|(
name|void
specifier|const
modifier|*
name|code
parameter_list|,
name|size_t
name|num_entries
parameter_list|,
name|struct
name|debug_line_info
specifier|const
modifier|*
name|info
parameter_list|)
function_decl|;
name|int
name|op_unload_native_code
parameter_list|(
name|uint64_t
name|addr
parameter_list|)
function_decl|;
name|int
name|op_major_version
parameter_list|()
function_decl|;
name|int
name|op_minor_version
parameter_list|()
function_decl|;
comment|// Returns true if the oprofiled process is running, the opagent library is
comment|// loaded and a connection to the agent has been established, and false
comment|// otherwise.
name|bool
name|isAgentAvailable
parameter_list|()
function_decl|;
name|private
label|:
comment|// Loads the libopagent library and initializes this wrapper if the oprofile
comment|// daemon is running
name|bool
name|initialize
parameter_list|()
function_decl|;
comment|// Searches /proc for the oprofile daemon and returns true if the process if
comment|// found, or false otherwise.
name|bool
name|checkForOProfileProcEntry
parameter_list|()
function_decl|;
name|bool
name|isOProfileRunning
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_OPROFILEWRAPPER_H
end_comment

end_unit

