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
file|"lldb/Core/FileSpecList.h"
end_include

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
comment|/// The search is done by cooperation between the search filter and the searcher.
comment|/// The search filter does the heavy work of recursing through the SymbolContext
comment|/// space of the target program's symbol space.  The Searcher specifies the depth
comment|/// at which it wants its callback to be invoked.  Note that since the resolution
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
name|virtual
operator|~
name|SearchFilter
argument_list|()
expr_stmt|;
specifier|const
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
comment|/// Call this method with a CompileUnit to see if \a comp unit passes the filter.
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
comment|/// symbols that have no compilation unit can't pass  So return eSymbolContextCU
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
name|protected
label|:
comment|// These are utility functions to assist with the search iteration.  They are used by the
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
name|lldb
operator|::
name|TargetSP
name|m_target_sp
expr_stmt|;
comment|// Every filter has to be associated with a target for
comment|// now since you need a starting place for the search.
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class SearchFilterForNonModuleSpecificSearches SearchFilter.h "lldb/Core/SearchFilter.h"
comment|/// @brief This is a SearchFilter that searches through all modules.  It also consults the Target::ModuleIsExcludedForNonModuleSpecificSearches.
comment|//----------------------------------------------------------------------
name|class
name|SearchFilterForNonModuleSpecificSearches
range|:
name|public
name|SearchFilter
block|{
name|public
operator|:
name|SearchFilterForNonModuleSpecificSearches
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|targetSP
argument_list|)
operator|:
name|SearchFilter
argument_list|(
argument|targetSP
argument_list|)
block|{}
operator|~
name|SearchFilterForNonModuleSpecificSearches
argument_list|()
block|{}
name|virtual
name|bool
name|ModulePasses
argument_list|(
specifier|const
name|FileSpec
operator|&
name|module_spec
argument_list|)
block|;
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
name|virtual
operator|~
name|SearchFilterByModule
argument_list|()
block|;
specifier|const
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
block|;
name|virtual
name|bool
name|ModulePasses
argument_list|(
specifier|const
name|FileSpec
operator|&
name|spec
argument_list|)
block|;
name|virtual
name|bool
name|AddressPasses
argument_list|(
name|Address
operator|&
name|address
argument_list|)
block|;
name|virtual
name|bool
name|CompUnitPasses
argument_list|(
name|FileSpec
operator|&
name|fileSpec
argument_list|)
block|;
name|virtual
name|bool
name|CompUnitPasses
argument_list|(
name|CompileUnit
operator|&
name|compUnit
argument_list|)
block|;
name|virtual
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
block|;
name|virtual
name|uint32_t
name|GetFilterRequiredItems
argument_list|()
block|;
name|virtual
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|Search
argument_list|(
name|Searcher
operator|&
name|searcher
argument_list|)
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
specifier|const
name|SearchFilterByModuleList
operator|&
name|rhs
argument_list|)
block|;
name|virtual
operator|~
name|SearchFilterByModuleList
argument_list|()
block|;
specifier|const
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
block|;
name|virtual
name|bool
name|ModulePasses
argument_list|(
specifier|const
name|FileSpec
operator|&
name|spec
argument_list|)
block|;
name|virtual
name|bool
name|AddressPasses
argument_list|(
name|Address
operator|&
name|address
argument_list|)
block|;
name|virtual
name|bool
name|CompUnitPasses
argument_list|(
name|FileSpec
operator|&
name|fileSpec
argument_list|)
block|;
name|virtual
name|bool
name|CompUnitPasses
argument_list|(
name|CompileUnit
operator|&
name|compUnit
argument_list|)
block|;
name|virtual
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
block|;
name|virtual
name|uint32_t
name|GetFilterRequiredItems
argument_list|()
block|;
name|virtual
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|Search
argument_list|(
name|Searcher
operator|&
name|searcher
argument_list|)
block|;
name|private
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
name|virtual
operator|~
name|SearchFilterByModuleListAndCU
argument_list|()
block|;
specifier|const
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
name|virtual
name|bool
name|AddressPasses
argument_list|(
name|Address
operator|&
name|address
argument_list|)
block|;
name|virtual
name|bool
name|CompUnitPasses
argument_list|(
name|FileSpec
operator|&
name|fileSpec
argument_list|)
block|;
name|virtual
name|bool
name|CompUnitPasses
argument_list|(
name|CompileUnit
operator|&
name|compUnit
argument_list|)
block|;
name|virtual
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
block|;
name|virtual
name|uint32_t
name|GetFilterRequiredItems
argument_list|()
block|;
name|virtual
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|)
specifier|const
block|;
name|virtual
name|void
name|Search
argument_list|(
name|Searcher
operator|&
name|searcher
argument_list|)
block|;
name|private
operator|:
name|FileSpecList
name|m_module_spec_list
block|;
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

