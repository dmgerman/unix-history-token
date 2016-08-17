begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBMemoryRegionInfoList.h --------------------------------*- C++ -*-===//
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
name|LLDB_SBMemoryRegionInfoList_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBMemoryRegionInfoList_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_decl_stmt
name|class
name|MemoryRegionInfoListImpl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|LLDB_API
name|SBMemoryRegionInfoList
block|{
name|public
label|:
name|SBMemoryRegionInfoList
argument_list|()
expr_stmt|;
name|SBMemoryRegionInfoList
argument_list|(
specifier|const
name|lldb
operator|::
name|SBMemoryRegionInfoList
operator|&
name|rhs
argument_list|)
expr_stmt|;
specifier|const
name|SBMemoryRegionInfoList
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SBMemoryRegionInfoList
operator|&
name|rhs
operator|)
decl_stmt|;
operator|~
name|SBMemoryRegionInfoList
argument_list|()
expr_stmt|;
name|uint32_t
name|GetSize
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|GetMemoryRegionAtIndex
parameter_list|(
name|uint32_t
name|idx
parameter_list|,
name|SBMemoryRegionInfo
modifier|&
name|region_info
parameter_list|)
function_decl|;
name|void
name|Append
argument_list|(
name|lldb
operator|::
name|SBMemoryRegionInfo
operator|&
name|region
argument_list|)
decl_stmt|;
name|void
name|Append
argument_list|(
name|lldb
operator|::
name|SBMemoryRegionInfoList
operator|&
name|region_list
argument_list|)
decl_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|protected
label|:
specifier|const
name|MemoryRegionInfoListImpl
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
specifier|const
name|MemoryRegionInfoListImpl
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
expr_stmt|;
name|private
label|:
name|std
operator|::
name|unique_ptr
operator|<
name|MemoryRegionInfoListImpl
operator|>
name|m_opaque_ap
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBMemoryRegionInfoList_h_
end_comment

end_unit

