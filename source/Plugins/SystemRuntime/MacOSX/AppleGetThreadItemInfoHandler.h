begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AppleGetThreadItemInfoHandler.h ----------------------------*- C++ -*-===//
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
name|lldb_AppleGetThreadItemInfoHandler_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_AppleGetThreadItemInfoHandler_h_
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
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerType.h"
end_include

begin_comment
comment|// This class will insert a UtilityFunction into the inferior process for
end_comment

begin_comment
comment|// calling libBacktraceRecording's __introspection_dispatch_thread_get_item_info()
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
comment|//     struct get_thread_item_info_return_values
end_comment

begin_comment
comment|//     {
end_comment

begin_comment
comment|//         introspection_dispatch_item_info_ref *item_buffer;
end_comment

begin_comment
comment|//         uint64_t item_buffer_size;
end_comment

begin_comment
comment|//     };
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The item_buffer pointer is an address in the inferior program's address
end_comment

begin_comment
comment|// space (item_buffer_size in size) which must be mach_vm_deallocate'd by
end_comment

begin_comment
comment|// lldb.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The AppleGetThreadItemInfoHandler object should persist so that the UtilityFunction
end_comment

begin_comment
comment|// can be reused multiple times.
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|AppleGetThreadItemInfoHandler
block|{
name|public
label|:
name|AppleGetThreadItemInfoHandler
argument_list|(
name|lldb_private
operator|::
name|Process
operator|*
name|process
argument_list|)
expr_stmt|;
operator|~
name|AppleGetThreadItemInfoHandler
argument_list|()
expr_stmt|;
struct|struct
name|GetThreadItemInfoReturnInfo
block|{
name|lldb
operator|::
name|addr_t
name|item_buffer_ptr
expr_stmt|;
comment|/* the address of the item buffer from libBacktraceRecording */
name|lldb
operator|::
name|addr_t
name|item_buffer_size
expr_stmt|;
comment|/* the size of the item buffer from libBacktraceRecording */
name|GetThreadItemInfoReturnInfo
argument_list|()
operator|:
name|item_buffer_ptr
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|item_buffer_size
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
comment|//----------------------------------------------------------
comment|/// Get the information about a work item by calling
comment|/// __introspection_dispatch_thread_get_item_info.  If there's a page of
comment|/// memory that needs to be freed, pass in the address and size and it will
comment|/// be freed before getting the list of queues.
comment|///
comment|/// @param [in] thread_id
comment|///     The thread to get the extended backtrace for.
comment|///
comment|/// @param [in] page_to_free
comment|///     An address of an inferior process vm page that needs to be deallocated,
comment|///     LLDB_INVALID_ADDRESS if this is not needed.
comment|///
comment|/// @param [in] page_to_free_size
comment|///     The size of the vm page that needs to be deallocated if an address was
comment|///     passed in to page_to_free.
comment|///
comment|/// @param [out] error
comment|///     This object will be updated with the error status / error string from any failures encountered.
comment|///
comment|/// @returns
comment|///     The result of the inferior function call execution.  If there was a failure of any kind while getting
comment|///     the information, the item_buffer_ptr value will be LLDB_INVALID_ADDRESS.
comment|//----------------------------------------------------------
name|GetThreadItemInfoReturnInfo
name|GetThreadItemInfo
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
name|lldb
operator|::
name|tid_t
name|thread_id
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
name|SetupGetThreadItemInfoFunction
argument_list|(
name|Thread
operator|&
name|thread
argument_list|,
name|ValueList
operator|&
name|get_thread_item_info_arglist
argument_list|)
expr_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|g_get_thread_item_info_function_name
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|g_get_thread_item_info_function_code
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
name|m_get_thread_item_info_impl_code
expr_stmt|;
name|std
operator|::
name|mutex
name|m_get_thread_item_info_function_mutex
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|m_get_thread_item_info_return_buffer_addr
expr_stmt|;
name|std
operator|::
name|mutex
name|m_get_thread_item_info_retbuffer_mutex
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
comment|// lldb_AppleGetThreadItemInfoHandler_h_
end_comment

end_unit

