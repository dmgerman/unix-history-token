begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointResolverFileRegex.h ----------------------------*- C++ -*-===//
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
name|liblldb_BreakpointResolverFileRegex_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointResolverFileRegex_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

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

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class BreakpointResolverFileRegex BreakpointResolverFileRegex.h "lldb/Breakpoint/BreakpointResolverFileRegex.h"
comment|/// @brief This class sets breakpoints by file and line.  Optionally, it will look for inlined
comment|/// instances of the file and line specification.
comment|//----------------------------------------------------------------------
name|class
name|BreakpointResolverFileRegex
range|:
name|public
name|BreakpointResolver
block|{
name|public
operator|:
name|BreakpointResolverFileRegex
argument_list|(
name|Breakpoint
operator|*
name|bkpt
argument_list|,
name|RegularExpression
operator|&
name|regex
argument_list|)
block|;
name|virtual
operator|~
name|BreakpointResolverFileRegex
argument_list|()
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
argument|const BreakpointResolverFileRegex *
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
name|FileRegexResolver
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
name|friend
name|class
name|Breakpoint
block|;
name|RegularExpression
name|m_regex
block|;
comment|// This is the line expression that we are looking for.
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|BreakpointResolverFileRegex
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
comment|// liblldb_BreakpointResolverFileRegex_h_
end_comment

end_unit

