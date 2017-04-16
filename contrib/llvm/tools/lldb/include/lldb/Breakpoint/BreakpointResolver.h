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
file|"lldb/Breakpoint/Breakpoint.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/SearchFilter.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/RegularExpression.h"
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
comment|//----------------------------------------------------------------------
comment|/// @class BreakpointResolver BreakpointResolver.h
comment|/// "lldb/Breakpoint/BreakpointResolver.h"
comment|/// @brief This class works with SearchFilter to resolve logical breakpoints to
comment|/// their
comment|/// of concrete breakpoint locations.
comment|//----------------------------------------------------------------------
comment|//----------------------------------------------------------------------
comment|/// General Outline:
comment|/// The BreakpointResolver is a Searcher.  In that protocol,
comment|/// the SearchFilter asks the question "At what depth of the symbol context
comment|/// descent do you want your callback to get called?" of the filter.  The
comment|/// resolver
comment|/// answers this question (in the GetDepth method) and provides the resolution
comment|/// callback.
comment|/// Each Breakpoint has a BreakpointResolver, and it calls either
comment|/// ResolveBreakpoint
comment|/// or ResolveBreakpointInModules to tell it to look for new breakpoint
comment|/// locations.
comment|//----------------------------------------------------------------------
name|class
name|BreakpointResolver
range|:
name|public
name|Searcher
block|{
name|friend
name|class
name|Breakpoint
block|;
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// The breakpoint resolver need to have a breakpoint for "ResolveBreakpoint
comment|/// to make sense.  It can be constructed without a breakpoint, but you have
comment|/// to
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
argument_list|,
argument|lldb::addr_t offset =
literal|0
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// The Destructor is virtual, all significant breakpoint resolvers derive
comment|/// from this class.
comment|//------------------------------------------------------------------
operator|~
name|BreakpointResolver
argument_list|()
name|override
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
comment|/// This updates the offset for this breakpoint.  All the locations currently
comment|/// set for this breakpoint will have their offset adjusted when this is
comment|/// called.
comment|///
comment|/// @param[in] offset
comment|///   The offset to add to all locations.
comment|//------------------------------------------------------------------
name|void
name|SetOffset
argument_list|(
argument|lldb::addr_t offset
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// This updates the offset for this breakpoint.  All the locations currently
comment|/// set for this breakpoint will have their offset adjusted when this is
comment|/// called.
comment|///
comment|/// @param[in] offset
comment|///   The offset to add to all locations.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetOffset
argument_list|()
specifier|const
block|{
return|return
name|m_offset
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// In response to this method the resolver scans all the modules in the
comment|/// breakpoint's
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
comment|/// In response to this method the resolver scans the modules in the module
comment|/// list
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
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|)
name|override
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
comment|/// This section handles serializing and deserializing from StructuredData
comment|/// objects.
specifier|static
name|lldb
operator|::
name|BreakpointResolverSP
name|CreateFromStructuredData
argument_list|(
specifier|const
name|StructuredData
operator|::
name|Dictionary
operator|&
name|resolver_dict
argument_list|,
name|Error
operator|&
name|error
argument_list|)
block|;
name|virtual
name|StructuredData
operator|::
name|ObjectSP
name|SerializeToStructuredData
argument_list|()
block|{
return|return
name|StructuredData
operator|::
name|ObjectSP
argument_list|()
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|GetSerializationKey
argument_list|()
block|{
return|return
literal|"BKPTResolver"
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|GetSerializationSubclassKey
argument_list|()
block|{
return|return
literal|"Type"
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|GetSerializationSubclassOptionsKey
argument_list|()
block|{
return|return
literal|"Options"
return|;
block|}
name|StructuredData
operator|::
name|DictionarySP
name|WrapOptionsDict
argument_list|(
argument|StructuredData::DictionarySP options_dict_sp
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|//------------------------------------------------------------------
comment|/// An enumeration for keeping track of the concrete subclass that
comment|/// is actually instantiated. Values of this enumeration are kept in the
comment|/// BreakpointResolver's SubclassID field. They are used for concrete type
comment|/// identification.
block|enum
name|ResolverTy
block|{
name|FileLineResolver
operator|=
literal|0
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
block|,
name|LastKnownResolverType
operator|=
name|ExceptionResolver
block|,
name|UnknownResolver
block|}
block|;
comment|// Translate the Ty to name for serialization,
comment|// the "+2" is one for size vrs. index, and one for UnknownResolver.
specifier|static
specifier|const
name|char
operator|*
name|g_ty_to_name
index|[
name|LastKnownResolverType
operator|+
literal|2
index|]
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
expr|enum
name|ResolverTy
name|GetResolverTy
argument_list|()
block|{
if|if
condition|(
name|SubclassID
operator|>
name|ResolverTy
operator|::
name|LastKnownResolverType
condition|)
return|return
name|ResolverTy
operator|::
name|UnknownResolver
return|;
else|else
return|return
operator|(
expr|enum
name|ResolverTy
operator|)
name|SubclassID
return|;
block|}
specifier|const
name|char
operator|*
name|GetResolverName
argument_list|()
block|{
return|return
name|ResolverTyToName
argument_list|(
name|GetResolverTy
argument_list|()
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|char
operator|*
name|ResolverTyToName
argument_list|(
expr|enum
name|ResolverTy
argument_list|)
block|;
specifier|static
name|ResolverTy
name|NameToResolverTy
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|BreakpointResolverSP
name|CopyForBreakpoint
argument_list|(
name|Breakpoint
operator|&
name|breakpoint
argument_list|)
operator|=
literal|0
block|;
name|protected
operator|:
comment|// Used for serializing resolver options:
comment|// The options in this enum and the strings in the
comment|// g_option_names must be kept in sync.
expr|enum
name|class
name|OptionNames
operator|:
name|uint32_t
block|{
name|AddressOffset
operator|=
literal|0
block|,
name|ExactMatch
block|,
name|FileName
block|,
name|Inlines
block|,
name|LanguageName
block|,
name|LineNumber
block|,
name|ModuleName
block|,
name|NameMaskArray
block|,
name|Offset
block|,
name|RegexString
block|,
name|SectionName
block|,
name|SkipPrologue
block|,
name|SymbolNameArray
block|,
name|LastOptionName
block|}
block|;
specifier|static
specifier|const
name|char
operator|*
name|g_option_names
index|[
name|static_cast
operator|<
name|uint32_t
operator|>
operator|(
name|OptionNames
operator|::
name|LastOptionName
operator|)
index|]
block|;
name|public
operator|:
specifier|static
specifier|const
name|char
operator|*
name|GetKey
argument_list|(
argument|OptionNames enum_value
argument_list|)
block|{
return|return
name|g_option_names
index|[
name|static_cast
operator|<
name|uint32_t
operator|>
operator|(
name|enum_value
operator|)
index|]
return|;
block|}
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|/// SetSCMatchesByLine - Takes a symbol context list of matches which
comment|/// supposedly represent the same file and
comment|/// line number in a CU, and find the nearest actual line number that matches,
comment|/// and then filter down the
comment|/// matching addresses to unique entries, and skip the prologue if asked to do
comment|/// so, and then set
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
argument|llvm::StringRef log_ident
argument_list|)
block|;
name|void
name|SetSCMatchesByLine
argument_list|(
name|SearchFilter
operator|&
argument_list|,
name|SymbolContextList
operator|&
argument_list|,
name|bool
argument_list|,
specifier|const
name|char
operator|*
argument_list|)
operator|=
name|delete
block|;
name|lldb
operator|::
name|BreakpointLocationSP
name|AddLocation
argument_list|(
argument|Address loc_addr
argument_list|,
argument|bool *new_location = NULL
argument_list|)
block|;
name|Breakpoint
operator|*
name|m_breakpoint
block|;
comment|// This is the breakpoint we add locations to.
name|lldb
operator|::
name|addr_t
name|m_offset
block|;
comment|// A random offset the user asked us to add to any
comment|// breakpoints we set.
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

