begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBMemoryRegionInfo.h ------------------------------------*- C++ -*-===//
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
name|LLDB_SBMemoryRegionInfo_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBMemoryRegionInfo_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBData.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|LLDB_API
name|SBMemoryRegionInfo
block|{
name|public
label|:
name|SBMemoryRegionInfo
argument_list|()
expr_stmt|;
name|SBMemoryRegionInfo
argument_list|(
specifier|const
name|lldb
operator|::
name|SBMemoryRegionInfo
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBMemoryRegionInfo
argument_list|()
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBMemoryRegionInfo
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBMemoryRegionInfo
operator|&
name|rhs
operator|)
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the base address of this memory range.
comment|///
comment|/// @return
comment|///     The base address of this memory range.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetRegionBase
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the end address of this memory range.
comment|///
comment|/// @return
comment|///     The base address of this memory range.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetRegionEnd
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if this memory address is marked readable to the process.
comment|///
comment|/// @return
comment|///     true if this memory address is marked readable
comment|//------------------------------------------------------------------
name|bool
name|IsReadable
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Check if this memory address is marked writable to the process.
comment|///
comment|/// @return
comment|///     true if this memory address is marked writable
comment|//------------------------------------------------------------------
name|bool
name|IsWritable
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Check if this memory address is marked executable to the process.
comment|///
comment|/// @return
comment|///     true if this memory address is marked executable
comment|//------------------------------------------------------------------
name|bool
name|IsExecutable
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Check if this memory address is mapped into the process address
comment|/// space.
comment|///
comment|/// @return
comment|///     true if this memory address is in the process address space.
comment|//------------------------------------------------------------------
name|bool
name|IsMapped
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Returns the name of the memory region mapped at the given
comment|/// address.
comment|///
comment|/// @return
comment|///     In case of memory mapped files it is the absolute path of
comment|///     the file otherwise it is a name associated with the memory
comment|///     region. If no name can be determined the returns nullptr.
comment|//------------------------------------------------------------------
specifier|const
name|char
modifier|*
name|GetName
parameter_list|()
function_decl|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|lldb
operator|::
name|SBMemoryRegionInfo
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|lldb
operator|::
name|SBMemoryRegionInfo
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
name|private
label|:
name|friend
name|class
name|SBProcess
decl_stmt|;
name|friend
name|class
name|SBMemoryRegionInfoList
decl_stmt|;
name|lldb_private
operator|::
name|MemoryRegionInfo
operator|&
name|ref
argument_list|()
expr_stmt|;
specifier|const
name|lldb_private
operator|::
name|MemoryRegionInfo
operator|&
name|ref
argument_list|()
specifier|const
expr_stmt|;
name|SBMemoryRegionInfo
argument_list|(
specifier|const
name|lldb_private
operator|::
name|MemoryRegionInfo
operator|*
name|lldb_object_ptr
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|MemoryRegionInfoUP
name|m_opaque_ap
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBMemoryRegionInfo_h_
end_comment

end_unit

