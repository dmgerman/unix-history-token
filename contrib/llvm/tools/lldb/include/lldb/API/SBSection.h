begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBSection.h ---------------------------------------------*- C++ -*-===//
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
name|LLDB_SBSection_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBSection_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBData.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|SBSection
block|{
name|public
label|:
name|SBSection
argument_list|()
expr_stmt|;
name|SBSection
argument_list|(
specifier|const
name|lldb
operator|::
name|SBSection
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SBSection
argument_list|()
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBSection
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBSection
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|char
modifier|*
name|GetName
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBSection
name|GetParent
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBSection
name|FindSubSection
argument_list|(
specifier|const
name|char
operator|*
name|sect_name
argument_list|)
expr_stmt|;
name|size_t
name|GetNumSubSections
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBSection
name|GetSubSectionAtIndex
argument_list|(
argument|size_t idx
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|GetFileAddress
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|GetLoadAddress
argument_list|(
name|lldb
operator|::
name|SBTarget
operator|&
name|target
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|GetByteSize
argument_list|()
expr_stmt|;
name|uint64_t
name|GetFileOffset
parameter_list|()
function_decl|;
name|uint64_t
name|GetFileByteSize
parameter_list|()
function_decl|;
name|lldb
operator|::
name|SBData
name|GetSectionData
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBData
name|GetSectionData
argument_list|(
argument|uint64_t offset
argument_list|,
argument|uint64_t size
argument_list|)
expr_stmt|;
name|SectionType
name|GetSectionType
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Return the size of a target's byte represented by this section
comment|/// in numbers of host bytes. Note that certain architectures have
comment|/// varying minimum addressable unit (i.e. byte) size for their
comment|/// CODE or DATA buses.
comment|///
comment|/// @return
comment|///     The number of host (8-bit) bytes needed to hold a target byte
comment|//------------------------------------------------------------------
name|uint32_t
name|GetTargetByteSize
parameter_list|()
function_decl|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|lldb
operator|::
name|SBSection
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|lldb
operator|::
name|SBSection
operator|&
name|rhs
operator|)
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
name|SBAddress
decl_stmt|;
name|friend
name|class
name|SBModule
decl_stmt|;
name|friend
name|class
name|SBTarget
decl_stmt|;
name|SBSection
argument_list|(
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|)
expr_stmt|;
name|lldb
operator|::
name|SectionSP
name|GetSP
argument_list|()
specifier|const
expr_stmt|;
name|void
name|SetSP
argument_list|(
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|)
decl_stmt|;
name|lldb
operator|::
name|SectionWP
name|m_opaque_wp
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
comment|// LLDB_SBSection_h_
end_comment

end_unit

