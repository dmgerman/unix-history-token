begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AddressResolverFileLine.h -------------------------------*- C++ -*-===//
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
name|liblldb_AddressResolverFileLine_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AddressResolverFileLine_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/AddressResolver.h"
end_include

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
comment|// for uint32_t
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
name|class
name|SymbolContext
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class AddressResolverFileLine AddressResolverFileLine.h
comment|/// "lldb/Core/AddressResolverFileLine.h"
comment|/// @brief This class finds address for source file and line.  Optionally, it
comment|/// will look for inlined
comment|/// instances of the file and line specification.
comment|//----------------------------------------------------------------------
name|class
name|AddressResolverFileLine
range|:
name|public
name|AddressResolver
block|{
name|public
operator|:
name|AddressResolverFileLine
argument_list|(
argument|const FileSpec&resolver
argument_list|,
argument|uint32_t line_no
argument_list|,
argument|bool check_inlines
argument_list|)
block|;
operator|~
name|AddressResolverFileLine
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
name|bool
name|m_inlines
block|;
comment|// This determines whether the resolver looks for inlined
comment|// functions or not.
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|AddressResolverFileLine
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
comment|// liblldb_AddressResolverFileLine_h_
end_comment

end_unit

