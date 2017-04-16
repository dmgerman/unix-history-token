begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- MinidumpParser.h -----------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_MinidumpParser_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_MinidumpParser_h_
end_define

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"MinidumpTypes.h"
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataBuffer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// C includes
end_comment

begin_comment
comment|// C++ includes
end_comment

begin_include
include|#
directive|include
file|<cstring>
end_include

begin_include
include|#
directive|include
file|<unordered_map>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|minidump
block|{
comment|// Describes a range of memory captured in the Minidump
struct|struct
name|Range
block|{
name|lldb
operator|::
name|addr_t
name|start
expr_stmt|;
comment|// virtual address of the beginning of the range
comment|// range_ref - absolute pointer to the first byte of the range and size
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|range_ref
expr_stmt|;
name|Range
argument_list|(
argument|lldb::addr_t start
argument_list|,
argument|llvm::ArrayRef<uint8_t> range_ref
argument_list|)
block|:
name|start
argument_list|(
name|start
argument_list|)
operator|,
name|range_ref
argument_list|(
argument|range_ref
argument_list|)
block|{}
block|}
struct|;
name|class
name|MinidumpParser
block|{
name|public
label|:
specifier|static
name|llvm
operator|::
name|Optional
operator|<
name|MinidumpParser
operator|>
name|Create
argument_list|(
specifier|const
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_buf_sp
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|GetData
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|GetStream
argument_list|(
argument|MinidumpStreamType stream_type
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Optional
operator|<
name|std
operator|::
name|string
operator|>
name|GetMinidumpString
argument_list|(
argument|uint32_t rva
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|MinidumpThread
operator|>
name|GetThreads
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|GetThreadContext
argument_list|(
specifier|const
name|MinidumpThread
operator|&
name|td
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|GetThreadContextWow64
argument_list|(
specifier|const
name|MinidumpThread
operator|&
name|td
argument_list|)
expr_stmt|;
specifier|const
name|MinidumpSystemInfo
modifier|*
name|GetSystemInfo
parameter_list|()
function_decl|;
name|ArchSpec
name|GetArchitecture
parameter_list|()
function_decl|;
specifier|const
name|MinidumpMiscInfo
modifier|*
name|GetMiscInfo
parameter_list|()
function_decl|;
name|llvm
operator|::
name|Optional
operator|<
name|LinuxProcStatus
operator|>
name|GetLinuxProcStatus
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|Optional
operator|<
name|lldb
operator|::
name|pid_t
operator|>
name|GetPid
argument_list|()
expr_stmt|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|MinidumpModule
operator|>
name|GetModuleList
argument_list|()
expr_stmt|;
comment|// There are cases in which there is more than one record in the ModuleList
comment|// for the same module name.(e.g. when the binary has non contiguous segments)
comment|// So this function returns a filtered module list - if it finds records that
comment|// have the same name, it keeps the copy with the lowest load address.
name|std
operator|::
name|vector
operator|<
specifier|const
name|MinidumpModule
operator|*
operator|>
name|GetFilteredModuleList
argument_list|()
expr_stmt|;
specifier|const
name|MinidumpExceptionStream
modifier|*
name|GetExceptionStream
parameter_list|()
function_decl|;
name|llvm
operator|::
name|Optional
operator|<
name|Range
operator|>
name|FindMemoryRange
argument_list|(
argument|lldb::addr_t addr
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|GetMemory
argument_list|(
argument|lldb::addr_t addr
argument_list|,
argument|size_t size
argument_list|)
expr_stmt|;
name|llvm
operator|::
name|Optional
operator|<
name|MemoryRegionInfo
operator|>
name|GetMemoryRegionInfo
argument_list|(
name|lldb
operator|::
name|addr_t
argument_list|)
expr_stmt|;
name|private
label|:
name|lldb
operator|::
name|DataBufferSP
name|m_data_sp
expr_stmt|;
specifier|const
name|MinidumpHeader
modifier|*
name|m_header
decl_stmt|;
name|llvm
operator|::
name|DenseMap
operator|<
name|uint32_t
operator|,
name|MinidumpLocationDescriptor
operator|>
name|m_directory_map
expr_stmt|;
name|MinidumpParser
argument_list|(
specifier|const
name|lldb
operator|::
name|DataBufferSP
operator|&
name|data_buf_sp
argument_list|,
specifier|const
name|MinidumpHeader
operator|*
name|header
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
name|uint32_t
argument_list|,
name|MinidumpLocationDescriptor
operator|>
operator|&&
name|directory_map
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// end namespace minidump
block|}
end_decl_stmt

begin_comment
comment|// end namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_MinidumpParser_h_
end_comment

end_unit

