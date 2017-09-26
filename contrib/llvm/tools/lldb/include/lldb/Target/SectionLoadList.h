begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SectionLoadList.h -----------------------------------------------*- C++
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
name|liblldb_SectionLoadList_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SectionLoadList_h_
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

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/Section.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SectionLoadList
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//------------------------------------------------------------------
name|SectionLoadList
argument_list|()
operator|:
name|m_addr_to_sect
argument_list|()
operator|,
name|m_sect_to_addr
argument_list|()
operator|,
name|m_mutex
argument_list|()
block|{}
name|SectionLoadList
argument_list|(
specifier|const
name|SectionLoadList
operator|&
name|rhs
argument_list|)
expr_stmt|;
operator|~
name|SectionLoadList
argument_list|()
block|{
comment|// Call clear since this takes a lock and clears the section load list
comment|// in case another thread is currently using this section load list
name|Clear
argument_list|()
block|;   }
name|void
name|operator
operator|=
operator|(
specifier|const
name|SectionLoadList
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsEmpty
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|lldb
operator|::
name|addr_t
name|GetSectionLoadAddress
argument_list|(
argument|const lldb::SectionSP&section_sp
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|ResolveLoadAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|Address
operator|&
name|so_addr
argument_list|,
name|bool
name|allow_section_end
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
name|bool
name|SetSectionLoadAddress
argument_list|(
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|,
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|bool
name|warn_multiple
operator|=
name|false
argument_list|)
decl_stmt|;
comment|// The old load address should be specified when unloading to ensure we get
comment|// the correct instance of the section as a shared library could be loaded
comment|// at more than one location.
name|bool
name|SetSectionUnloaded
argument_list|(
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|,
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|)
decl_stmt|;
comment|// Unload all instances of a section. This function can be used on systems
comment|// that don't support multiple copies of the same shared library to be
comment|// loaded at the same time.
name|size_t
name|SetSectionUnloaded
argument_list|(
specifier|const
name|lldb
operator|::
name|SectionSP
operator|&
name|section_sp
argument_list|)
decl_stmt|;
name|void
name|Dump
parameter_list|(
name|Stream
modifier|&
name|s
parameter_list|,
name|Target
modifier|*
name|target
parameter_list|)
function_decl|;
name|protected
label|:
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
name|SectionSP
operator|>
name|addr_to_sect_collection
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Section
operator|*
operator|,
name|lldb
operator|::
name|addr_t
operator|>
name|sect_to_addr_collection
expr_stmt|;
name|addr_to_sect_collection
name|m_addr_to_sect
decl_stmt|;
name|sect_to_addr_collection
name|m_sect_to_addr
decl_stmt|;
name|mutable
name|std
operator|::
name|recursive_mutex
name|m_mutex
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
comment|// liblldb_SectionLoadList_h_
end_comment

end_unit

