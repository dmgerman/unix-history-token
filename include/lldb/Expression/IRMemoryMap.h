begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- IRExecutionUnit.h ---------------------------------------*- C++ -*-===//
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
name|lldb_IRMemoryMap_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_IRMemoryMap_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/DataBufferHeap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class IRMemoryMap IRMemoryMap.h "lldb/Expression/IRMemoryMap.h"
comment|/// @brief Encapsulates memory that may exist in the process but must
comment|///     also be available in the host process.
comment|///
comment|/// This class encapsulates a group of memory objects that must be readable
comment|/// or writable from the host process regardless of whether the process
comment|/// exists.  This allows the IR interpreter as well as JITted code to access
comment|/// the same memory.  All allocations made by this class are represented as
comment|/// disjoint intervals.
comment|///
comment|/// Point queries against this group of memory objects can be made by the
comment|/// address in the tar at which they reside.  If the inferior does not
comment|/// exist, allocations still get made-up addresses.  If an inferior appears
comment|/// at some point, then those addresses need to be re-mapped.
comment|//----------------------------------------------------------------------
name|class
name|IRMemoryMap
block|{
name|public
label|:
name|IRMemoryMap
argument_list|(
argument|lldb::TargetSP target_sp
argument_list|)
empty_stmt|;
operator|~
name|IRMemoryMap
argument_list|()
expr_stmt|;
enum|enum
name|AllocationPolicy
block|{
name|eAllocationPolicyInvalid
init|=
literal|0
block|,
comment|///< It is an error for an allocation to have this policy.
name|eAllocationPolicyHostOnly
block|,
comment|///< This allocation was created in the host and
comment|///will never make it into the process.
comment|///< It is an error to create other types of allocations while such
comment|///allocations exist.
name|eAllocationPolicyMirror
block|,
comment|///< The intent is that this allocation exist both
comment|///in the host and the process and have
comment|///< the same content in both.
name|eAllocationPolicyProcessOnly
comment|///< The intent is that this allocation exist
comment|///only in the process.
block|}
enum|;
name|lldb
operator|::
name|addr_t
name|Malloc
argument_list|(
argument|size_t size
argument_list|,
argument|uint8_t alignment
argument_list|,
argument|uint32_t permissions
argument_list|,
argument|AllocationPolicy policy
argument_list|,
argument|bool zero_memory
argument_list|,
argument|Error&error
argument_list|)
expr_stmt|;
name|void
name|Leak
argument_list|(
name|lldb
operator|::
name|addr_t
name|process_address
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|void
name|Free
argument_list|(
name|lldb
operator|::
name|addr_t
name|process_address
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|void
name|WriteMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|process_address
argument_list|,
specifier|const
name|uint8_t
operator|*
name|bytes
argument_list|,
name|size_t
name|size
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|void
name|WriteScalarToMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|process_address
argument_list|,
name|Scalar
operator|&
name|scalar
argument_list|,
name|size_t
name|size
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|void
name|WritePointerToMemory
argument_list|(
name|lldb
operator|::
name|addr_t
name|process_address
argument_list|,
name|lldb
operator|::
name|addr_t
name|address
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|void
name|ReadMemory
argument_list|(
name|uint8_t
operator|*
name|bytes
argument_list|,
name|lldb
operator|::
name|addr_t
name|process_address
argument_list|,
name|size_t
name|size
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|void
name|ReadScalarFromMemory
argument_list|(
name|Scalar
operator|&
name|scalar
argument_list|,
name|lldb
operator|::
name|addr_t
name|process_address
argument_list|,
name|size_t
name|size
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|void
name|ReadPointerFromMemory
argument_list|(
name|lldb
operator|::
name|addr_t
operator|*
name|address
argument_list|,
name|lldb
operator|::
name|addr_t
name|process_address
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|bool
name|GetAllocSize
argument_list|(
name|lldb
operator|::
name|addr_t
name|address
argument_list|,
name|size_t
operator|&
name|size
argument_list|)
decl_stmt|;
name|void
name|GetMemoryData
argument_list|(
name|DataExtractor
operator|&
name|extractor
argument_list|,
name|lldb
operator|::
name|addr_t
name|process_address
argument_list|,
name|size_t
name|size
argument_list|,
name|Error
operator|&
name|error
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|ByteOrder
name|GetByteOrder
argument_list|()
expr_stmt|;
name|uint32_t
name|GetAddressByteSize
parameter_list|()
function_decl|;
comment|// This function can return NULL.
name|ExecutionContextScope
operator|*
name|GetBestExecutionContextScope
argument_list|()
specifier|const
expr_stmt|;
name|lldb
operator|::
name|TargetSP
name|GetTarget
argument_list|()
block|{
return|return
name|m_target_wp
operator|.
name|lock
argument_list|()
return|;
block|}
name|protected
label|:
comment|// This function should only be used if you know you are using the JIT.
comment|// Any other cases should use GetBestExecutionContextScope().
name|lldb
operator|::
name|ProcessWP
operator|&
name|GetProcessWP
argument_list|()
block|{
return|return
name|m_process_wp
return|;
block|}
name|private
label|:
struct|struct
name|Allocation
block|{
name|lldb
operator|::
name|addr_t
name|m_process_alloc
expr_stmt|;
comment|///< The (unaligned) base for the remote allocation
name|lldb
operator|::
name|addr_t
name|m_process_start
expr_stmt|;
comment|///< The base address of the allocation in the process
name|size_t
name|m_size
decl_stmt|;
comment|///< The size of the requested allocation
name|uint32_t
name|m_permissions
decl_stmt|;
comment|///< The access permissions on the memory in the
comment|///process.  In the host, the memory is always
comment|///read/write.
name|uint8_t
name|m_alignment
decl_stmt|;
comment|///< The alignment of the requested allocation
name|DataBufferHeap
name|m_data
decl_stmt|;
comment|///< Flags
name|AllocationPolicy
name|m_policy
decl_stmt|;
name|bool
name|m_leak
decl_stmt|;
name|public
label|:
name|Allocation
argument_list|(
argument|lldb::addr_t process_alloc
argument_list|,
argument|lldb::addr_t process_start
argument_list|,
argument|size_t size
argument_list|,
argument|uint32_t permissions
argument_list|,
argument|uint8_t alignment
argument_list|,
argument|AllocationPolicy m_policy
argument_list|)
empty_stmt|;
name|Allocation
argument_list|()
operator|:
name|m_process_alloc
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|m_process_start
argument_list|(
name|LLDB_INVALID_ADDRESS
argument_list|)
operator|,
name|m_size
argument_list|(
literal|0
argument_list|)
operator|,
name|m_permissions
argument_list|(
literal|0
argument_list|)
operator|,
name|m_alignment
argument_list|(
literal|0
argument_list|)
operator|,
name|m_data
argument_list|()
operator|,
name|m_policy
argument_list|(
name|eAllocationPolicyInvalid
argument_list|)
operator|,
name|m_leak
argument_list|(
argument|false
argument_list|)
block|{}
block|}
struct|;
name|lldb
operator|::
name|ProcessWP
name|m_process_wp
expr_stmt|;
name|lldb
operator|::
name|TargetWP
name|m_target_wp
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|addr_t
operator|,
name|Allocation
operator|>
name|AllocationMap
expr_stmt|;
name|AllocationMap
name|m_allocations
decl_stmt|;
name|lldb
operator|::
name|addr_t
name|FindSpace
argument_list|(
argument|size_t size
argument_list|)
expr_stmt|;
name|bool
name|ContainsHostOnlyAllocations
parameter_list|()
function_decl|;
name|AllocationMap
operator|::
name|iterator
name|FindAllocation
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|)
expr_stmt|;
comment|// Returns true if the given allocation intersects any allocation in the
comment|// memory map.
name|bool
name|IntersectsAllocation
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr
argument_list|,
name|size_t
name|size
argument_list|)
decl|const
decl_stmt|;
comment|// Returns true if the two given allocations intersect each other.
specifier|static
name|bool
name|AllocationsIntersect
argument_list|(
name|lldb
operator|::
name|addr_t
name|addr1
argument_list|,
name|size_t
name|size1
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr2
argument_list|,
name|size_t
name|size2
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

