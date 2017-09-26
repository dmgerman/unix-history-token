begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Symtab.h ------------------------------------------------*- C++ -*-===//
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
name|liblldb_UnwindTable_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_UnwindTable_h
end_define

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
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// A class which holds all the FuncUnwinders objects for a given ObjectFile.
comment|// The UnwindTable is populated with FuncUnwinders objects lazily during
comment|// the debug session.
name|class
name|UnwindTable
block|{
name|public
label|:
name|UnwindTable
argument_list|(
name|ObjectFile
operator|&
name|objfile
argument_list|)
expr_stmt|;
operator|~
name|UnwindTable
argument_list|()
expr_stmt|;
name|lldb_private
operator|::
name|DWARFCallFrameInfo
operator|*
name|GetEHFrameInfo
argument_list|()
expr_stmt|;
name|lldb_private
operator|::
name|DWARFCallFrameInfo
operator|*
name|GetDebugFrameInfo
argument_list|()
expr_stmt|;
name|lldb_private
operator|::
name|CompactUnwindInfo
operator|*
name|GetCompactUnwindInfo
argument_list|()
expr_stmt|;
name|ArmUnwindInfo
modifier|*
name|GetArmUnwindInfo
parameter_list|()
function_decl|;
name|lldb
operator|::
name|FuncUnwindersSP
name|GetFuncUnwindersContainingAddress
argument_list|(
specifier|const
name|Address
operator|&
name|addr
argument_list|,
name|SymbolContext
operator|&
name|sc
argument_list|)
expr_stmt|;
name|bool
name|GetAllowAssemblyEmulationUnwindPlans
parameter_list|()
function_decl|;
comment|// Normally when we create a new FuncUnwinders object we track it in this
comment|// UnwindTable so it can
comment|// be reused later.  But for the target modules show-unwind we want to create
comment|// brand new
comment|// UnwindPlans for the function of interest - so ignore any existing
comment|// FuncUnwinders for that
comment|// function and don't add this new one to our UnwindTable.
comment|// This FuncUnwinders object does have a reference to the UnwindTable but the
comment|// lifetime of this
comment|// uncached FuncUnwinders is expected to be short so in practice this will not
comment|// be a problem.
name|lldb
operator|::
name|FuncUnwindersSP
name|GetUncachedFuncUnwindersContainingAddress
argument_list|(
specifier|const
name|Address
operator|&
name|addr
argument_list|,
name|SymbolContext
operator|&
name|sc
argument_list|)
expr_stmt|;
name|bool
name|GetArchitecture
argument_list|(
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
decl_stmt|;
name|private
label|:
name|void
name|Dump
parameter_list|(
name|Stream
modifier|&
name|s
parameter_list|)
function_decl|;
name|void
name|Initialize
parameter_list|()
function_decl|;
name|llvm
operator|::
name|Optional
operator|<
name|AddressRange
operator|>
name|GetAddressRange
argument_list|(
specifier|const
name|Address
operator|&
name|addr
argument_list|,
name|SymbolContext
operator|&
name|sc
argument_list|)
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
name|lldb
operator|::
name|FuncUnwindersSP
operator|>
name|collection
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|collection
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
name|ObjectFile
modifier|&
name|m_object_file
decl_stmt|;
name|collection
name|m_unwinds
decl_stmt|;
name|bool
name|m_initialized
decl_stmt|;
comment|// delay some initialization until ObjectFile is set up
name|std
operator|::
name|mutex
name|m_mutex
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|DWARFCallFrameInfo
operator|>
name|m_eh_frame_up
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|DWARFCallFrameInfo
operator|>
name|m_debug_frame_up
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|CompactUnwindInfo
operator|>
name|m_compact_unwind_up
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|ArmUnwindInfo
operator|>
name|m_arm_unwind_up
expr_stmt|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|UnwindTable
argument_list|)
expr_stmt|;
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
comment|// liblldb_UnwindTable_h
end_comment

end_unit

