begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AppleGetQueuesHandler.h ----------------------------*- C++ -*-===//
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
name|lldb_AppleGetQueuesHandler_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_AppleGetQueuesHandler_h_
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
file|"lldb/Symbol/CompilerType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_comment
comment|// This class will insert a UtilityFunction into the inferior process for
end_comment

begin_comment
comment|// calling libBacktraceRecording's introspection_get_dispatch_queues()
end_comment

begin_comment
comment|// function.  The function in the inferior will return a struct by value
end_comment

begin_comment
comment|// with these members:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     struct get_current_queues_return_values
end_comment

begin_comment
comment|//     {
end_comment

begin_comment
comment|//         introspection_dispatch_queue_info_t *queues_buffer;
end_comment

begin_comment
comment|//         uint64_t queues_buffer_size;
end_comment

begin_comment
comment|//         uint64_t count;
end_comment

begin_comment
comment|//     };
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The queues_buffer pointer is an address in the inferior program's address
end_comment

begin_comment
comment|// space (queues_buffer_size in size) which must be mach_vm_deallocate'd by
end_comment

begin_comment
comment|// lldb.  count is the number of queues that were stored in the buffer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The AppleGetQueuesHandler object should persist so that the UtilityFunction
end_comment

begin_comment
comment|// can be reused multiple times.
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|AppleGetQueuesHandler
block|{
name|public
label|:
name|AppleGetQueuesHandler
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
operator|~
name|AppleGetQueuesHandler
argument_list|()
expr_stmt|;
struct|struct
name|GetQueuesReturnInfo
block|{
name|lldb
operator|::
name|addr_t
name|queues_buffer_ptr
expr_stmt|;
comment|/* the address of the queues buffer from                                         libBacktraceRecording */
name|lldb
operator|::
name|addr_t
name|queues_buffer_size
expr_stmt|;
comment|/* the size of the queues buffer from                                         libBacktraceRecording */
name|uint64_t
name|count
decl_stmt|;
comment|/* the number of queues included in the queues buffer */
name|GetQueuesReturnInfo
argument_list|()
operator|:
name|queues_buffer_ptr
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|queues_buffer_size
argument_list|(
literal|0
argument_list|)
operator|,
name|count
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
comment|//----------------------------------------------------------
comment|/// Get the list of queues that exist (with any active or pending items) via
comment|/// a call to introspection_get_dispatch_queues().  If there's a page of
comment|/// memory that needs to be freed, pass in the address and size and it will
comment|/// be freed before getting the list of queues.
comment|///
comment|/// @param [in] thread
comment|///     The thread to run this plan on.
comment|///
comment|/// @param [in] page_to_free
comment|///     An address of an inferior process vm page that needs to be
comment|///     deallocated,
comment|///     LLDB_INVALID_ADDRESS if this is not needed.
comment|///
comment|/// @param [in] page_to_free_size
comment|///     The size of the vm page that needs to be deallocated if an address was
comment|///     passed in to page_to_free.
comment|///
comment|/// @param [out] error
comment|///     This object will be updated with the error status / error string from
comment|///     any failures encountered.
comment|///
comment|/// @returns
comment|///     The result of the inferior function call execution.  If there was a
comment|///     failure of any kind while getting
comment|///     the information, the queues_buffer_ptr value will be
comment|///     LLDB_INVALID_ADDRESS.
comment|//----------------------------------------------------------
name|GetQueuesReturnInfo
name|GetCurrentQueues
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
name|lldb
operator|::
name|addr_t
name|page_to_free
argument_list|,
name|uint64_t
name|page_to_free_size
argument_list|,
name|lldb_private
operator|::
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|void
name|Detach
parameter_list|()
function_decl|;
name|private
label|:
name|lldb
operator|::
name|addr_t
name|SetupGetQueuesFunction
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
name|ValueList
operator|&
name|get_queues_arglist
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|g_get_current_queues_function_name
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|g_get_current_queues_function_code
decl_stmt|;
name|lldb_private
operator|::
name|Process
operator|*
name|m_process
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|UtilityFunction
operator|>
name|m_get_queues_impl_code_up
expr_stmt|;
name|std
operator|::
name|mutex
name|m_get_queues_function_mutex
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|m_get_queues_return_buffer_addr
expr_stmt|;
name|std
operator|::
name|mutex
name|m_get_queues_retbuffer_mutex
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// using namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// lldb_AppleGetQueuesHandler_h_
end_comment

end_unit

