begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AddressResolverName.h -----------------------------------*- C++ -*-===//
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
name|liblldb_AddressResolverName_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AddressResolverName_h_
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
comment|// for Searcher, Searcher::Call...
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_comment
comment|// for ConstString
end_comment

begin_include
include|#
directive|include
file|"lldb/Utility/RegularExpression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_comment
comment|// for DISALLOW_COPY_AND_ASSIGN
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
comment|/// @class AddressResolverName AddressResolverName.h
comment|/// "lldb/Core/AddressResolverName.h"
comment|/// @brief This class finds addresses for a given function name, either by exact
comment|/// match
comment|/// or by regular expression.
comment|//----------------------------------------------------------------------
name|class
name|AddressResolverName
range|:
name|public
name|AddressResolver
block|{
name|public
operator|:
name|AddressResolverName
argument_list|(
argument|const char *func_name
argument_list|,
argument|AddressResolver::MatchType type = Exact
argument_list|)
block|;
comment|// Creates a function breakpoint by regular expression.  Takes over control of
comment|// the lifespan of func_regex.
name|AddressResolverName
argument_list|(
name|RegularExpression
operator|&
name|func_regex
argument_list|)
block|;
name|AddressResolverName
argument_list|(
argument|const char *class_name
argument_list|,
argument|const char *method
argument_list|,
argument|AddressResolver::MatchType type
argument_list|)
block|;
operator|~
name|AddressResolverName
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
name|ConstString
name|m_func_name
block|;
name|ConstString
name|m_class_name
block|;
comment|// FIXME: Not used yet.  The idea would be to stop
comment|// on methods of this class.
name|RegularExpression
name|m_regex
block|;
name|AddressResolver
operator|::
name|MatchType
name|m_match_type
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|AddressResolverName
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
comment|// liblldb_AddressResolverName_h_
end_comment

end_unit

