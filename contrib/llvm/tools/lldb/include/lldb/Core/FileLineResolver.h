begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FileLineResolver.h --------------------------------------*- C++ -*-===//
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
name|liblldb_FileLineResolver_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_FileLineResolver_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/SearchFilter.h"
end_include

begin_comment
comment|// for Searcher, Searcher::CallbackR...
end_comment

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_comment
comment|// for FileSpec
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t, UINT32_MAX
end_comment

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Address
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class FileLineResolver FileLineResolver.h "lldb/Core/FileLineResolver.h"
comment|/// @brief This class finds address for source file and line.  Optionally, it
comment|/// will look for inlined
comment|/// instances of the file and line specification.
comment|//----------------------------------------------------------------------
name|class
name|FileLineResolver
range|:
name|public
name|Searcher
block|{
name|public
operator|:
name|FileLineResolver
argument_list|()
operator|:
name|m_file_spec
argument_list|()
block|,
name|m_line_number
argument_list|(
name|UINT32_MAX
argument_list|)
block|,
comment|// Set this to zero for all lines in a file
name|m_sc_list
argument_list|()
block|,
name|m_inlines
argument_list|(
argument|true
argument_list|)
block|{}
name|FileLineResolver
argument_list|(
argument|const FileSpec&resolver
argument_list|,
argument|uint32_t line_no
argument_list|,
argument|bool check_inlines
argument_list|)
block|;
operator|~
name|FileLineResolver
argument_list|()
name|override
block|;
name|Searcher
operator|::
name|CallbackReturn
name|SearchCallback
argument_list|(
argument|SearchFilter&filter
argument_list|,
argument|SymbolContext&context
argument_list|,
argument|Address *addr
argument_list|,
argument|bool containing
argument_list|)
name|override
block|;
name|Searcher
operator|::
name|Depth
name|GetDepth
argument_list|()
name|override
block|;
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|)
name|override
block|;
specifier|const
name|SymbolContextList
operator|&
name|GetFileLineMatches
argument_list|()
block|{
return|return
name|m_sc_list
return|;
block|}
name|void
name|Clear
argument_list|()
block|;
name|void
name|Reset
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t line
argument_list|,
argument|bool check_inlines
argument_list|)
block|;
name|protected
operator|:
name|FileSpec
name|m_file_spec
block|;
comment|// This is the file spec we are looking for.
name|uint32_t
name|m_line_number
block|;
comment|// This is the line number that we are looking for.
name|SymbolContextList
name|m_sc_list
block|;
name|bool
name|m_inlines
block|;
comment|// This determines whether the resolver looks for inlined
comment|// functions or not.
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|FileLineResolver
argument_list|)
block|; }
decl_stmt|;
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
comment|// liblldb_FileLineResolver_h_
end_comment

end_unit

