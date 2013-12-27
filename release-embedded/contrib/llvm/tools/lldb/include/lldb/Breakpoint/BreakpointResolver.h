begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- BreakpointResolver.h ------------------------------------*- C++ -*-===//
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
name|liblldb_BreakpointResolver_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_BreakpointResolver_h_
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
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/Breakpoint.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Breakpoint/BreakpointResolver.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/RegularExpression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/SearchFilter.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class BreakpointResolver BreakpointResolver.h "lldb/Breakpoint/BreakpointResolver.h"
comment|/// @brief This class works with SearchFilter to resolve logical breakpoints to their
comment|/// of concrete breakpoint locations.
comment|//----------------------------------------------------------------------
comment|//----------------------------------------------------------------------
comment|/// General Outline:
comment|/// The BreakpointResolver is a Searcher.  In that protocol,
comment|/// the SearchFilter asks the question "At what depth of the symbol context
comment|/// descent do you want your callback to get called?" of the filter.  The resolver
comment|/// answers this question (in the GetDepth method) and provides the resolution callback.
comment|/// Each Breakpoint has a BreakpointResolver, and it calls either ResolveBreakpoint
comment|/// or ResolveBreakpointInModules to tell it to look for new breakpoint locations.
comment|//----------------------------------------------------------------------
name|class
name|BreakpointResolver
range|:
name|public
name|Searcher
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// The breakpoint resolver need to have a breakpoint for "ResolveBreakpoint
comment|/// to make sense.  It can be constructed without a breakpoint, but you have to
comment|/// call SetBreakpoint before ResolveBreakpoint.
comment|///
comment|/// @param[in] bkpt
comment|///   The breakpoint that owns this resolver.
comment|/// @param[in] resolverType
comment|///   The concrete breakpoint resolver type for this breakpoint.
comment|///
comment|/// @result
comment|///   Returns breakpoint location id.
comment|//------------------------------------------------------------------
name|BreakpointResolver
argument_list|(
argument|Breakpoint *bkpt
argument_list|,
argument|unsigned char resolverType
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// The Destructor is virtual, all significant breakpoint resolvers derive
comment|/// from this class.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|BreakpointResolver
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// This sets the breakpoint for this resolver.
comment|///
comment|/// @param[in] bkpt
comment|///   The breakpoint that owns this resolver.
comment|//------------------------------------------------------------------
name|void
name|SetBreakpoint
argument_list|(
name|Breakpoint
operator|*
name|bkpt
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// In response to this method the resolver scans all the modules in the breakpoint's
comment|/// target, and adds any new locations it finds.
comment|///
comment|/// @param[in] filter
comment|///   The filter that will manage the search for this resolver.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|ResolveBreakpoint
argument_list|(
name|SearchFilter
operator|&
name|filter
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// In response to this method the resolver scans the modules in the module list
comment|/// \a modules, and adds any new locations it finds.
comment|///
comment|/// @param[in] filter
comment|///   The filter that will manage the search for this resolver.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|ResolveBreakpointInModules
argument_list|(
name|SearchFilter
operator|&
name|filter
argument_list|,
name|ModuleList
operator|&
name|modules
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Prints a canonical description for the breakpoint to the stream \a s.
comment|///
comment|/// @param[in] s
comment|///   Stream to which the output is copied.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// Standard "Dump" method.  At present it does nothing.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|//------------------------------------------------------------------
comment|/// An enumeration for keeping track of the concrete subclass that
comment|/// is actually instantiated. Values of this enumeration are kept in the
comment|/// BreakpointResolver's SubclassID field. They are used for concrete type
comment|/// identification.
block|enum
name|ResolverTy
block|{
name|FileLineResolver
block|,
comment|// This is an instance of BreakpointResolverFileLine
name|AddressResolver
block|,
comment|// This is an instance of BreakpointResolverAddress
name|NameResolver
block|,
comment|// This is an instance of BreakpointResolverName
name|FileRegexResolver
block|,
name|ExceptionResolver
block|}
block|;
comment|//------------------------------------------------------------------
comment|/// getResolverID - Return an ID for the concrete type of this object.  This
comment|/// is used to implement the LLVM classof checks.  This should not be used
comment|/// for any other purpose, as the values may change as LLDB evolves.
name|unsigned
name|getResolverID
argument_list|()
specifier|const
block|{
return|return
name|SubclassID
return|;
block|}
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|/// SetSCMatchesByLine - Takes a symbol context list of matches which supposedly represent the same file and
comment|/// line number in a CU, and find the nearest actual line number that matches, and then filter down the
comment|/// matching addresses to unique entries, and skip the prologue if asked to do so, and then set
comment|/// breakpoint locations in this breakpoint for all the resultant addresses.
name|void
name|SetSCMatchesByLine
argument_list|(
argument|SearchFilter&filter
argument_list|,
argument|SymbolContextList&sc_list
argument_list|,
argument|bool skip_prologue
argument_list|,
argument|const char *log_ident
argument_list|)
block|;
name|Breakpoint
operator|*
name|m_breakpoint
block|;
comment|// This is the breakpoint we add locations to.
name|private
operator|:
comment|// Subclass identifier (for llvm isa/dyn_cast)
specifier|const
name|unsigned
name|char
name|SubclassID
block|;
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|BreakpointResolver
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
comment|// liblldb_BreakpointResolver_h_
end_comment

end_unit

