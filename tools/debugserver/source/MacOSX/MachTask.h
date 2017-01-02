begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MachTask.h ----------------------------------------------*- C++ -*-===//
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
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  MachTask.h
end_comment

begin_comment
comment|//  debugserver
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Created by Greg Clayton on 12/5/08.
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
name|__MachTask_h__
end_ifndef

begin_define
define|#
directive|define
name|__MachTask_h__
end_define

begin_comment
comment|// C Includes
end_comment

begin_include
include|#
directive|include
file|<mach/mach.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

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
file|<string>
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
file|"DNBDefs.h"
end_include

begin_include
include|#
directive|include
file|"MachException.h"
end_include

begin_include
include|#
directive|include
file|"MachVMMemory.h"
end_include

begin_include
include|#
directive|include
file|"PThreadMutex.h"
end_include

begin_decl_stmt
name|class
name|MachProcess
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|uint64_t
name|MachMallocEventId
typedef|;
end_typedef

begin_enum
enum|enum
name|MachMallocEventType
block|{
name|eMachMallocEventTypeAlloc
init|=
literal|2
block|,
name|eMachMallocEventTypeDealloc
init|=
literal|4
block|,
name|eMachMallocEventTypeOther
init|=
literal|1
block|}
enum|;
end_enum

begin_struct
struct|struct
name|MachMallocEvent
block|{
name|mach_vm_address_t
name|m_base_address
decl_stmt|;
name|uint64_t
name|m_size
decl_stmt|;
name|MachMallocEventType
name|m_event_type
decl_stmt|;
name|MachMallocEventId
name|m_event_id
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|class
name|MachTask
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|MachTask
argument_list|(
name|MachProcess
operator|*
name|process
argument_list|)
expr_stmt|;
name|virtual
operator|~
name|MachTask
argument_list|()
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|kern_return_t
name|Suspend
parameter_list|()
function_decl|;
name|kern_return_t
name|Resume
parameter_list|()
function_decl|;
name|nub_size_t
name|ReadMemory
parameter_list|(
name|nub_addr_t
name|addr
parameter_list|,
name|nub_size_t
name|size
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
name|nub_size_t
name|WriteMemory
parameter_list|(
name|nub_addr_t
name|addr
parameter_list|,
name|nub_size_t
name|size
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
name|int
name|GetMemoryRegionInfo
parameter_list|(
name|nub_addr_t
name|addr
parameter_list|,
name|DNBRegionInfo
modifier|*
name|region_info
parameter_list|)
function_decl|;
name|std
operator|::
name|string
name|GetProfileData
argument_list|(
argument|DNBProfileDataScanType scanType
argument_list|)
expr_stmt|;
name|nub_addr_t
name|AllocateMemory
parameter_list|(
name|nub_size_t
name|size
parameter_list|,
name|uint32_t
name|permissions
parameter_list|)
function_decl|;
name|nub_bool_t
name|DeallocateMemory
parameter_list|(
name|nub_addr_t
name|addr
parameter_list|)
function_decl|;
name|mach_port_t
name|ExceptionPort
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|ExceptionPortIsValid
argument_list|()
specifier|const
expr_stmt|;
name|kern_return_t
name|SaveExceptionPortInfo
parameter_list|()
function_decl|;
name|kern_return_t
name|RestoreExceptionPortInfo
parameter_list|()
function_decl|;
name|kern_return_t
name|ShutDownExcecptionThread
parameter_list|()
function_decl|;
name|bool
name|StartExceptionThread
parameter_list|(
name|DNBError
modifier|&
name|err
parameter_list|)
function_decl|;
name|nub_addr_t
name|GetDYLDAllImageInfosAddress
parameter_list|(
name|DNBError
modifier|&
name|err
parameter_list|)
function_decl|;
name|kern_return_t
name|BasicInfo
parameter_list|(
name|struct
name|task_basic_info
modifier|*
name|info
parameter_list|)
function_decl|;
specifier|static
name|kern_return_t
name|BasicInfo
parameter_list|(
name|task_t
name|task
parameter_list|,
name|struct
name|task_basic_info
modifier|*
name|info
parameter_list|)
function_decl|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
specifier|static
name|bool
name|IsValid
parameter_list|(
name|task_t
name|task
parameter_list|)
function_decl|;
specifier|static
name|void
modifier|*
name|ExceptionThread
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
name|void
name|TaskPortChanged
parameter_list|(
name|task_t
name|task
parameter_list|)
function_decl|;
name|task_t
name|TaskPort
argument_list|()
specifier|const
block|{
return|return
name|m_task
return|;
block|}
name|task_t
name|TaskPortForProcessID
parameter_list|(
name|DNBError
modifier|&
name|err
parameter_list|,
name|bool
name|force
init|=
name|false
parameter_list|)
function_decl|;
specifier|static
name|task_t
name|TaskPortForProcessID
parameter_list|(
name|pid_t
name|pid
parameter_list|,
name|DNBError
modifier|&
name|err
parameter_list|,
name|uint32_t
name|num_retries
init|=
literal|10
parameter_list|,
name|uint32_t
name|usec_interval
init|=
literal|10000
parameter_list|)
function_decl|;
name|MachProcess
modifier|*
name|Process
parameter_list|()
block|{
return|return
name|m_process
return|;
block|}
specifier|const
name|MachProcess
operator|*
name|Process
argument_list|()
specifier|const
block|{
return|return
name|m_process
return|;
block|}
name|nub_size_t
name|PageSize
parameter_list|()
function_decl|;
name|protected
label|:
name|MachProcess
modifier|*
name|m_process
decl_stmt|;
comment|// The mach process that owns this MachTask
name|task_t
name|m_task
decl_stmt|;
name|MachVMMemory
name|m_vm_memory
decl_stmt|;
comment|// Special mach memory reading class that will take
comment|// care of watching for page and region boundaries
name|MachException
operator|::
name|PortInfo
name|m_exc_port_info
expr_stmt|;
comment|// Saved settings for all exception ports
name|pthread_t
name|m_exception_thread
decl_stmt|;
comment|// Thread ID for the exception thread in case we
comment|// need it
name|mach_port_t
name|m_exception_port
decl_stmt|;
comment|// Exception port on which we will receive child
comment|// exceptions
typedef|typedef
name|std
operator|::
name|map
operator|<
name|mach_vm_address_t
operator|,
name|size_t
operator|>
name|allocation_collection
expr_stmt|;
name|allocation_collection
name|m_allocations
decl_stmt|;
name|private
label|:
name|MachTask
argument_list|(
specifier|const
name|MachTask
operator|&
argument_list|)
expr_stmt|;
comment|// Outlaw
name|MachTask
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MachTask
operator|&
name|rhs
operator|)
decl_stmt|;
comment|// Outlaw
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __MachTask_h__
end_comment

end_unit

