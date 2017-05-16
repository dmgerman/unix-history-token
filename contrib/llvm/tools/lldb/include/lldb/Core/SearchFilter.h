begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SearchFilter.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_SearchFilter_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_SearchFilter_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/FileSpecList.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/StructuredData.h"
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
file|"lldb/lldb-forward.h"
end_include

begin_comment
comment|// for SearchFilterSP, TargetSP, Modu...
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
name|Breakpoint
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|CompileUnit
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Status
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Function
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ModuleList
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|SearchFilter
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
name|class
name|Target
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Searcher SearchFilter.h "lldb/Core/SearchFilter.h"
comment|/// @brief Class that is driven by the SearchFilter to search the
comment|/// SymbolContext space of the target program.
comment|//----------------------------------------------------------------------
comment|//----------------------------------------------------------------------
comment|/// General Outline:
comment|/// Provides the callback and search depth for the SearchFilter search.
comment|//----------------------------------------------------------------------
name|class
name|Searcher
block|{
name|public
label|:
typedef|typedef
enum|enum
block|{
name|eCallbackReturnStop
init|=
literal|0
block|,
comment|// Stop the iteration
name|eCallbackReturnContinue
block|,
comment|// Continue the iteration
name|eCallbackReturnPop
comment|// Pop one level up and continue iterating
block|}
name|CallbackReturn
typedef|;
typedef|typedef
enum|enum
block|{
name|eDepthTarget
block|,
name|eDepthModule
block|,
name|eDepthCompUnit
block|,
name|eDepthFunction
block|,
name|eDepthBlock
block|,
name|eDepthAddress
block|}
name|Depth
typedef|;
name|Searcher
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|Searcher
argument_list|()
expr_stmt|;
name|virtual
name|CallbackReturn
name|SearchCallback
parameter_list|(
name|SearchFilter
modifier|&
name|filter
parameter_list|,
name|SymbolContext
modifier|&
name|context
parameter_list|,
name|Address
modifier|*
name|addr
parameter_list|,
name|bool
name|complete
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|Depth
name|GetDepth
parameter_list|()
init|=
literal|0
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Prints a canonical description for the searcher to the stream \a s.
comment|///
comment|/// @param[in] s
comment|///   Stream to which the output is copied.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|GetDescription
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class SearchFilter SearchFilter.h "lldb/Core/SearchFilter.h"
comment|/// @brief Class descends through the SymbolContext space of the target,
comment|/// applying a filter at each stage till it reaches the depth specified by
comment|/// the GetDepth method of the searcher, and calls its callback at that point.
comment|//----------------------------------------------------------------------
comment|//----------------------------------------------------------------------
comment|/// General Outline:
comment|/// Provides the callback and search depth for the SearchFilter search.
comment|///
comment|/// The search is done by cooperation between the search filter and the
comment|/// searcher.
comment|/// The search filter does the heavy work of recursing through the SymbolContext
comment|/// space of the target program's symbol space.  The Searcher specifies the
comment|/// depth
comment|/// at which it wants its callback to be invoked.  Note that since the
comment|/// resolution
comment|/// of the Searcher may be greater than that of the SearchFilter, before the
comment|/// Searcher qualifies an address it should pass it to "AddressPasses."
comment|/// The default implementation is "Everything Passes."
comment|//----------------------------------------------------------------------
name|class
name|SearchFilter
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// The basic constructor takes a Target, which gives the space to search.
comment|///
comment|/// @param[in] target
comment|///    The Target that provides the module list to search.
comment|//------------------------------------------------------------------
name|SearchFilter
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|)
expr_stmt|;
name|SearchFilter
argument_list|(
specifier|const
name|SearchFilter
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|SearchFilter
argument_list|(
argument|const lldb::TargetSP&target_sp
argument_list|,
argument|unsigned char filterType
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|SearchFilter
argument_list|()
expr_stmt|;
name|SearchFilter
modifier|&
name|operator
init|=
operator|(
specifier|const
name|SearchFilter
operator|&
name|rhs
operator|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Call this method with a file spec to see if that spec passes the filter.
comment|///
comment|/// @param[in] spec
comment|///    The file spec to check against the filter.
comment|/// @return
comment|///    \b true if \a spec passes, and \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|ModulePasses
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|spec
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Call this method with a Module to see if that module passes the filter.
comment|///
comment|/// @param[in] module
comment|///    The Module to check against the filter.
comment|///
comment|/// @return
comment|///    \b true if \a module passes, and \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|ModulePasses
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Call this method with a Address to see if \a address passes the filter.
comment|///
comment|/// @param[in] addr
comment|///    The address to check against the filter.
comment|///
comment|/// @return
comment|///    \b true if \a address passes, and \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|AddressPasses
parameter_list|(
name|Address
modifier|&
name|addr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Call this method with a FileSpec to see if \a file spec passes the filter
comment|/// as the name of a compilation unit.
comment|///
comment|/// @param[in] fileSpec
comment|///    The file spec to check against the filter.
comment|///
comment|/// @return
comment|///    \b true if \a file spec passes, and \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|CompUnitPasses
parameter_list|(
name|FileSpec
modifier|&
name|fileSpec
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Call this method with a CompileUnit to see if \a comp unit passes the
comment|/// filter.
comment|///
comment|/// @param[in] compUnit
comment|///    The CompileUnit to check against the filter.
comment|///
comment|/// @return
comment|///    \b true if \a Comp Unit passes, and \b false otherwise.
comment|//------------------------------------------------------------------
name|virtual
name|bool
name|CompUnitPasses
parameter_list|(
name|CompileUnit
modifier|&
name|compUnit
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Call this method to do the search using the Searcher.
comment|///
comment|/// @param[in] searcher
comment|///    The searcher to drive with this search.
comment|///
comment|//------------------------------------------------------------------
name|virtual
name|void
name|Search
parameter_list|(
name|Searcher
modifier|&
name|searcher
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Call this method to do the search using the Searcher in the module list
comment|/// \a modules.
comment|///
comment|/// @param[in] searcher
comment|///    The searcher to drive with this search.
comment|///
comment|/// @param[in] modules
comment|///    The module list within which to restrict the search.
comment|///
comment|//------------------------------------------------------------------
name|virtual
name|void
name|SearchInModuleList
parameter_list|(
name|Searcher
modifier|&
name|searcher
parameter_list|,
name|ModuleList
modifier|&
name|modules
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// This determines which items are REQUIRED for the filter to pass.
comment|/// For instance, if you are filtering by Compilation Unit, obviously
comment|/// symbols that have no compilation unit can't pass  So return
comment|/// eSymbolContextCU
comment|/// and search callbacks can then short cut the search to avoid looking at
comment|/// things that obviously won't pass.
comment|///
comment|/// @return
comment|///    The required elements for the search, which is an or'ed together
comment|///    set of lldb:SearchContextItem enum's.
comment|///
comment|//------------------------------------------------------------------
name|virtual
name|uint32_t
name|GetFilterRequiredItems
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Prints a canonical description for the search filter to the stream \a s.
comment|///
comment|/// @param[in] s
comment|///   Stream to which the output is copied.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|GetDescription
parameter_list|(
name|Stream
modifier|*
name|s
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Standard "Dump" method.  At present it does nothing.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
decl|const
decl_stmt|;
name|lldb
operator|::
name|SearchFilterSP
name|CopyForBreakpoint
argument_list|(
name|Breakpoint
operator|&
name|breakpoint
argument_list|)
expr_stmt|;
specifier|static
name|lldb
operator|::
name|SearchFilterSP
name|CreateFromStructuredData
argument_list|(
name|Target
operator|&
name|target
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
expr_stmt|;
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
modifier|*
name|GetSerializationKey
parameter_list|()
block|{
return|return
literal|"SearchFilter"
return|;
block|}
specifier|static
specifier|const
name|char
modifier|*
name|GetSerializationSubclassKey
parameter_list|()
block|{
return|return
literal|"Type"
return|;
block|}
specifier|static
specifier|const
name|char
modifier|*
name|GetSerializationSubclassOptionsKey
parameter_list|()
block|{
return|return
literal|"Options"
return|;
block|}
enum|enum
name|FilterTy
block|{
name|Unconstrained
init|=
literal|0
block|,
name|Exception
block|,
name|ByModule
block|,
name|ByModules
block|,
name|ByModulesAndCU
block|,
name|LastKnownFilterType
init|=
name|ByModulesAndCU
block|,
name|UnknownFilter
block|}
enum|;
specifier|static
specifier|const
name|char
modifier|*
name|g_ty_to_name
index|[
name|LastKnownFilterType
operator|+
literal|2
index|]
decl_stmt|;
name|enum
name|FilterTy
name|GetFilterTy
parameter_list|()
block|{
if|if
condition|(
name|SubclassID
operator|>
name|FilterTy
operator|::
name|LastKnownFilterType
condition|)
return|return
name|FilterTy
operator|::
name|UnknownFilter
return|;
else|else
return|return
operator|(
expr|enum
name|FilterTy
operator|)
name|SubclassID
return|;
block|}
specifier|const
name|char
modifier|*
name|GetFilterName
parameter_list|()
block|{
return|return
name|FilterTyToName
argument_list|(
name|GetFilterTy
argument_list|()
argument_list|)
return|;
block|}
specifier|static
specifier|const
name|char
modifier|*
name|FilterTyToName
parameter_list|(
name|enum
name|FilterTy
parameter_list|)
function_decl|;
specifier|static
name|FilterTy
name|NameToFilterTy
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|)
decl_stmt|;
name|protected
label|:
comment|// Serialization of SearchFilter options:
enum|enum
name|OptionNames
block|{
name|ModList
init|=
literal|0
block|,
name|CUList
block|,
name|LanguageName
block|,
name|LastOptionName
block|}
enum|;
specifier|static
specifier|const
name|char
modifier|*
name|g_option_names
index|[
name|LastOptionName
index|]
decl_stmt|;
specifier|static
specifier|const
name|char
modifier|*
name|GetKey
parameter_list|(
name|enum
name|OptionNames
name|enum_value
parameter_list|)
block|{
return|return
name|g_option_names
index|[
name|enum_value
index|]
return|;
block|}
name|StructuredData
operator|::
name|DictionarySP
name|WrapOptionsDict
argument_list|(
argument|StructuredData::DictionarySP options_dict_sp
argument_list|)
expr_stmt|;
name|void
name|SerializeFileSpecList
argument_list|(
name|StructuredData
operator|::
name|DictionarySP
operator|&
name|options_dict_sp
argument_list|,
name|OptionNames
name|name
argument_list|,
name|FileSpecList
operator|&
name|file_list
argument_list|)
decl_stmt|;
comment|// These are utility functions to assist with the search iteration.  They are
comment|// used by the
comment|// default Search method.
name|Searcher
operator|::
name|CallbackReturn
name|DoModuleIteration
argument_list|(
specifier|const
name|SymbolContext
operator|&
name|context
argument_list|,
name|Searcher
operator|&
name|searcher
argument_list|)
expr_stmt|;
name|Searcher
operator|::
name|CallbackReturn
name|DoModuleIteration
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
name|Searcher
operator|&
name|searcher
argument_list|)
expr_stmt|;
name|Searcher
operator|::
name|CallbackReturn
name|DoCUIteration
argument_list|(
specifier|const
name|lldb
operator|::
name|ModuleSP
operator|&
name|module_sp
argument_list|,
specifier|const
name|SymbolContext
operator|&
name|context
argument_list|,
name|Searcher
operator|&
name|searcher
argument_list|)
expr_stmt|;
name|Searcher
operator|::
name|CallbackReturn
name|DoFunctionIteration
argument_list|(
name|Function
operator|*
name|function
argument_list|,
specifier|const
name|SymbolContext
operator|&
name|context
argument_list|,
name|Searcher
operator|&
name|searcher
argument_list|)
expr_stmt|;
name|virtual
name|lldb
operator|::
name|SearchFilterSP
name|DoCopyForBreakpoint
argument_list|(
name|Breakpoint
operator|&
name|breakpoint
argument_list|)
operator|=
literal|0
expr_stmt|;
name|void
name|SetTarget
argument_list|(
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|)
block|{
name|m_target_sp
operator|=
name|target_sp
expr_stmt|;
block|}
name|lldb
operator|::
name|TargetSP
name|m_target_sp
expr_stmt|;
comment|// Every filter has to be associated with a target for
comment|// now since you need a starting place for the search.
name|private
label|:
name|unsigned
name|char
name|SubclassID
decl_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class SearchFilterForUnconstrainedSearches SearchFilter.h
comment|/// "lldb/Core/SearchFilter.h"
comment|/// @brief This is a SearchFilter that searches through all modules.  It also
comment|/// consults the Target::ModuleIsExcludedForUnconstrainedSearches.
comment|//----------------------------------------------------------------------
name|class
name|SearchFilterForUnconstrainedSearches
range|:
name|public
name|SearchFilter
block|{
name|public
operator|:
name|SearchFilterForUnconstrainedSearches
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target_sp
argument_list|)
operator|:
name|SearchFilter
argument_list|(
argument|target_sp
argument_list|,
argument|FilterTy::Unconstrained
argument_list|)
block|{}
operator|~
name|SearchFilterForUnconstrainedSearches
argument_list|()
name|override
operator|=
expr|default
block|;
name|bool
name|ModulePasses
argument_list|(
argument|const FileSpec&module_spec
argument_list|)
name|override
block|;
name|bool
name|ModulePasses
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|)
name|override
block|;
specifier|static
name|lldb
operator|::
name|SearchFilterSP
name|CreateFromStructuredData
argument_list|(
name|Target
operator|&
name|target
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
name|protected
operator|:
name|lldb
operator|::
name|SearchFilterSP
name|DoCopyForBreakpoint
argument_list|(
argument|Breakpoint&breakpoint
argument_list|)
name|override
block|; }
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class SearchFilterByModule SearchFilter.h "lldb/Core/SearchFilter.h"
comment|/// @brief This is a SearchFilter that restricts the search to a given module.
comment|//----------------------------------------------------------------------
name|class
name|SearchFilterByModule
range|:
name|public
name|SearchFilter
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// The basic constructor takes a Target, which gives the space to search,
comment|/// and the module to restrict the search to.
comment|///
comment|/// @param[in] target
comment|///    The Target that provides the module list to search.
comment|///
comment|/// @param[in] module
comment|///    The Module that limits the search.
comment|//------------------------------------------------------------------
name|SearchFilterByModule
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|targetSP
argument_list|,
specifier|const
name|FileSpec
operator|&
name|module
argument_list|)
block|;
name|SearchFilterByModule
argument_list|(
specifier|const
name|SearchFilterByModule
operator|&
name|rhs
argument_list|)
block|;
operator|~
name|SearchFilterByModule
argument_list|()
name|override
block|;
name|SearchFilterByModule
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SearchFilterByModule
operator|&
name|rhs
operator|)
block|;
name|bool
name|ModulePasses
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|)
name|override
block|;
name|bool
name|ModulePasses
argument_list|(
argument|const FileSpec&spec
argument_list|)
name|override
block|;
name|bool
name|AddressPasses
argument_list|(
argument|Address&address
argument_list|)
name|override
block|;
name|bool
name|CompUnitPasses
argument_list|(
argument|FileSpec&fileSpec
argument_list|)
name|override
block|;
name|bool
name|CompUnitPasses
argument_list|(
argument|CompileUnit&compUnit
argument_list|)
name|override
block|;
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|)
name|override
block|;
name|uint32_t
name|GetFilterRequiredItems
argument_list|()
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
name|void
name|Search
argument_list|(
argument|Searcher&searcher
argument_list|)
name|override
block|;
specifier|static
name|lldb
operator|::
name|SearchFilterSP
name|CreateFromStructuredData
argument_list|(
name|Target
operator|&
name|target
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
name|protected
operator|:
name|lldb
operator|::
name|SearchFilterSP
name|DoCopyForBreakpoint
argument_list|(
argument|Breakpoint&breakpoint
argument_list|)
name|override
block|;
name|private
operator|:
name|FileSpec
name|m_module_spec
block|; }
decl_stmt|;
name|class
name|SearchFilterByModuleList
range|:
name|public
name|SearchFilter
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// The basic constructor takes a Target, which gives the space to search,
comment|/// and the module list to restrict the search to.
comment|///
comment|/// @param[in] target
comment|///    The Target that provides the module list to search.
comment|///
comment|/// @param[in] module
comment|///    The Module that limits the search.
comment|//------------------------------------------------------------------
name|SearchFilterByModuleList
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|targetSP
argument_list|,
specifier|const
name|FileSpecList
operator|&
name|module_list
argument_list|)
block|;
name|SearchFilterByModuleList
argument_list|(
argument|const lldb::TargetSP&targetSP
argument_list|,
argument|const FileSpecList&module_list
argument_list|,
argument|enum FilterTy filter_ty
argument_list|)
block|;
name|SearchFilterByModuleList
argument_list|(
specifier|const
name|SearchFilterByModuleList
operator|&
name|rhs
argument_list|)
block|;
operator|~
name|SearchFilterByModuleList
argument_list|()
name|override
block|;
name|SearchFilterByModuleList
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SearchFilterByModuleList
operator|&
name|rhs
operator|)
block|;
name|bool
name|ModulePasses
argument_list|(
argument|const lldb::ModuleSP&module_sp
argument_list|)
name|override
block|;
name|bool
name|ModulePasses
argument_list|(
argument|const FileSpec&spec
argument_list|)
name|override
block|;
name|bool
name|AddressPasses
argument_list|(
argument|Address&address
argument_list|)
name|override
block|;
name|bool
name|CompUnitPasses
argument_list|(
argument|FileSpec&fileSpec
argument_list|)
name|override
block|;
name|bool
name|CompUnitPasses
argument_list|(
argument|CompileUnit&compUnit
argument_list|)
name|override
block|;
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|)
name|override
block|;
name|uint32_t
name|GetFilterRequiredItems
argument_list|()
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
name|void
name|Search
argument_list|(
argument|Searcher&searcher
argument_list|)
name|override
block|;
specifier|static
name|lldb
operator|::
name|SearchFilterSP
name|CreateFromStructuredData
argument_list|(
name|Target
operator|&
name|target
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
name|void
name|SerializeUnwrapped
argument_list|(
name|StructuredData
operator|::
name|DictionarySP
operator|&
name|options_dict_sp
argument_list|)
block|;
name|protected
operator|:
name|lldb
operator|::
name|SearchFilterSP
name|DoCopyForBreakpoint
argument_list|(
argument|Breakpoint&breakpoint
argument_list|)
name|override
block|;
name|protected
operator|:
name|FileSpecList
name|m_module_spec_list
block|; }
decl_stmt|;
name|class
name|SearchFilterByModuleListAndCU
range|:
name|public
name|SearchFilterByModuleList
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// The basic constructor takes a Target, which gives the space to search,
comment|/// and the module list to restrict the search to.
comment|///
comment|/// @param[in] target
comment|///    The Target that provides the module list to search.
comment|///
comment|/// @param[in] module
comment|///    The Module that limits the search.
comment|//------------------------------------------------------------------
name|SearchFilterByModuleListAndCU
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|targetSP
argument_list|,
specifier|const
name|FileSpecList
operator|&
name|module_list
argument_list|,
specifier|const
name|FileSpecList
operator|&
name|cu_list
argument_list|)
block|;
name|SearchFilterByModuleListAndCU
argument_list|(
specifier|const
name|SearchFilterByModuleListAndCU
operator|&
name|rhs
argument_list|)
block|;
operator|~
name|SearchFilterByModuleListAndCU
argument_list|()
name|override
block|;
name|SearchFilterByModuleListAndCU
operator|&
name|operator
operator|=
operator|(
specifier|const
name|SearchFilterByModuleListAndCU
operator|&
name|rhs
operator|)
block|;
name|bool
name|AddressPasses
argument_list|(
argument|Address&address
argument_list|)
name|override
block|;
name|bool
name|CompUnitPasses
argument_list|(
argument|FileSpec&fileSpec
argument_list|)
name|override
block|;
name|bool
name|CompUnitPasses
argument_list|(
argument|CompileUnit&compUnit
argument_list|)
name|override
block|;
name|void
name|GetDescription
argument_list|(
argument|Stream *s
argument_list|)
name|override
block|;
name|uint32_t
name|GetFilterRequiredItems
argument_list|()
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
name|void
name|Search
argument_list|(
argument|Searcher&searcher
argument_list|)
name|override
block|;
specifier|static
name|lldb
operator|::
name|SearchFilterSP
name|CreateFromStructuredData
argument_list|(
name|Target
operator|&
name|target
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
name|protected
operator|:
name|lldb
operator|::
name|SearchFilterSP
name|DoCopyForBreakpoint
argument_list|(
argument|Breakpoint&breakpoint
argument_list|)
name|override
block|;
name|private
operator|:
name|FileSpecList
name|m_cu_spec_list
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
comment|// liblldb_SearchFilter_h_
end_comment

end_unit

