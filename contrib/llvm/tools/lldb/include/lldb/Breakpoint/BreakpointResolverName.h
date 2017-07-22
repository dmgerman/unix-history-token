begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointResolverName.h --------------------------------*- C++ -*-===//
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
name|liblldb_BreakpointResolverName_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointResolverName_h_
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
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Breakpoint/BreakpointResolver.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Module.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class BreakpointResolverName BreakpointResolverName.h
comment|/// "lldb/Breakpoint/BreakpointResolverName.h"
comment|/// @brief This class sets breakpoints on a given function name, either by exact
comment|/// match
comment|/// or by regular expression.
comment|//----------------------------------------------------------------------
name|class
name|BreakpointResolverName
range|:
name|public
name|BreakpointResolver
block|{
name|public
operator|:
name|BreakpointResolverName
argument_list|(
argument|Breakpoint *bkpt
argument_list|,
argument|const char *name
argument_list|,
argument|uint32_t name_type_mask
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|Breakpoint::MatchType type
argument_list|,
argument|lldb::addr_t offset
argument_list|,
argument|bool skip_prologue
argument_list|)
block|;
comment|// This one takes an array of names.  It is always MatchType = Exact.
name|BreakpointResolverName
argument_list|(
argument|Breakpoint *bkpt
argument_list|,
argument|const char *names[]
argument_list|,
argument|size_t num_names
argument_list|,
argument|uint32_t name_type_mask
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|lldb::addr_t offset
argument_list|,
argument|bool skip_prologue
argument_list|)
block|;
comment|// This one takes a C++ array of names.  It is always MatchType = Exact.
name|BreakpointResolverName
argument_list|(
argument|Breakpoint *bkpt
argument_list|,
argument|std::vector<std::string> names
argument_list|,
argument|uint32_t name_type_mask
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|lldb::addr_t offset
argument_list|,
argument|bool skip_prologue
argument_list|)
block|;
comment|// Creates a function breakpoint by regular expression.  Takes over control of
comment|// the lifespan of func_regex.
name|BreakpointResolverName
argument_list|(
argument|Breakpoint *bkpt
argument_list|,
argument|RegularExpression&func_regex
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|lldb::addr_t offset
argument_list|,
argument|bool skip_prologue
argument_list|)
block|;
specifier|static
name|BreakpointResolver
operator|*
name|CreateFromStructuredData
argument_list|(
name|Breakpoint
operator|*
name|bkpt
argument_list|,
specifier|const
name|StructuredData
operator|::
name|Dictionary
operator|&
name|data_dict
argument_list|,
name|Status
operator|&
name|error
argument_list|)
block|;
name|StructuredData
operator|::
name|ObjectSP
name|SerializeToStructuredData
argument_list|()
name|override
block|;
operator|~
name|BreakpointResolverName
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
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
name|override
block|;
comment|/// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const BreakpointResolverName *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
argument_list|(
argument|const BreakpointResolver *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getResolverID
argument_list|()
operator|==
name|BreakpointResolver
operator|::
name|NameResolver
return|;
block|}
name|lldb
operator|::
name|BreakpointResolverSP
name|CopyForBreakpoint
argument_list|(
argument|Breakpoint&breakpoint
argument_list|)
name|override
block|;
name|protected
operator|:
name|BreakpointResolverName
argument_list|(
specifier|const
name|BreakpointResolverName
operator|&
name|rhs
argument_list|)
block|;
name|std
operator|::
name|vector
operator|<
name|Module
operator|::
name|LookupInfo
operator|>
name|m_lookups
block|;
name|ConstString
name|m_class_name
block|;
name|RegularExpression
name|m_regex
block|;
name|Breakpoint
operator|::
name|MatchType
name|m_match_type
block|;
name|lldb
operator|::
name|LanguageType
name|m_language
block|;
name|bool
name|m_skip_prologue
block|;
name|void
name|AddNameLookup
argument_list|(
argument|const ConstString&name
argument_list|,
argument|uint32_t name_type_mask
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
comment|// liblldb_BreakpointResolverName_h_
end_comment

end_unit

