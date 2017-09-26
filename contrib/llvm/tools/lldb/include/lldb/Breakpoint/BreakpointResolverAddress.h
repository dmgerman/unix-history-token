begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointResolverAddress.h -----------------------------*- C++ -*-===//
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
name|liblldb_BreakpointResolverAddress_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointResolverAddress_h_
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

begin_include
include|#
directive|include
file|"lldb/Core/ModuleSpec.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class BreakpointResolverAddress BreakpointResolverAddress.h
comment|/// "lldb/Breakpoint/BreakpointResolverAddress.h"
comment|/// @brief This class sets breakpoints on a given Address.  This breakpoint only
comment|/// takes
comment|/// once, and then it won't attempt to reset itself.
comment|//----------------------------------------------------------------------
name|class
name|BreakpointResolverAddress
range|:
name|public
name|BreakpointResolver
block|{
name|public
operator|:
name|BreakpointResolverAddress
argument_list|(
name|Breakpoint
operator|*
name|bkpt
argument_list|,
specifier|const
name|Address
operator|&
name|addr
argument_list|)
block|;
name|BreakpointResolverAddress
argument_list|(
name|Breakpoint
operator|*
name|bkpt
argument_list|,
specifier|const
name|Address
operator|&
name|addr
argument_list|,
specifier|const
name|FileSpec
operator|&
name|module_spec
argument_list|)
block|;
operator|~
name|BreakpointResolverAddress
argument_list|()
name|override
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
name|options_dict
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
name|void
name|ResolveBreakpoint
argument_list|(
argument|SearchFilter&filter
argument_list|)
name|override
block|;
name|void
name|ResolveBreakpointInModules
argument_list|(
argument|SearchFilter&filter
argument_list|,
argument|ModuleList&modules
argument_list|)
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
argument|const BreakpointResolverAddress *
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
name|AddressResolver
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
name|Address
name|m_addr
block|;
comment|// The address - may be Section Offset or may be just an offset
name|lldb
operator|::
name|addr_t
name|m_resolved_addr
block|;
comment|// The current value of the resolved load
comment|// address for this breakpoint,
name|FileSpec
name|m_module_filespec
block|;
comment|// If this filespec is Valid, and m_addr is an
comment|// offset, then it will be converted
comment|// to a Section+Offset address in this module, whenever that module gets
comment|// around to
comment|// being loaded.
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|BreakpointResolverAddress
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
comment|// liblldb_BreakpointResolverAddress_h_
end_comment

end_unit

