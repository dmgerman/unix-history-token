begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- AddressResolver.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_AddressResolver_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_AddressResolver_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/SearchFilter.h"
end_include

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
file|<stddef.h>
end_include

begin_comment
comment|// for size_t
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

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
name|Stream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class AddressResolver AddressResolver.h "lldb/Core/AddressResolver.h"
comment|/// @brief This class works with SearchFilter to resolve function names and
comment|/// source file locations to their concrete addresses.
comment|//----------------------------------------------------------------------
comment|//----------------------------------------------------------------------
comment|/// General Outline:
comment|/// The AddressResolver is a Searcher.  In that protocol,
comment|/// the SearchFilter asks the question "At what depth of the symbol context
comment|/// descent do you want your callback to get called?" of the filter.  The
comment|/// resolver
comment|/// answers this question (in the GetDepth method) and provides the resolution
comment|/// callback.
comment|//----------------------------------------------------------------------
name|class
name|AddressResolver
range|:
name|public
name|Searcher
block|{
name|public
operator|:
typedef|typedef
enum|enum
block|{
name|Exact
block|,
name|Regexp
block|,
name|Glob
decl|}
name|MatchType
empty_stmt|;
name|AddressResolver
argument_list|()
empty_stmt|;
operator|~
name|AddressResolver
argument_list|()
name|override
expr_stmt|;
name|virtual
name|void
name|ResolveAddress
parameter_list|(
name|SearchFilter
modifier|&
name|filter
parameter_list|)
function_decl|;
name|virtual
name|void
name|ResolveAddressInModules
parameter_list|(
name|SearchFilter
modifier|&
name|filter
parameter_list|,
name|ModuleList
modifier|&
name|modules
parameter_list|)
function_decl|;
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
name|override
init|=
literal|0
block|;
name|std
decl|::
name|vector
decl|<
name|AddressRange
decl|>
modifier|&
name|GetAddressRanges
argument_list|()
empty_stmt|;
name|size_t
name|GetNumberOfAddresses
parameter_list|()
function_decl|;
name|AddressRange
modifier|&
name|GetAddressRangeAtIndex
parameter_list|(
name|size_t
name|idx
parameter_list|)
function_decl|;
name|protected
label|:
name|std
decl|::
name|vector
decl|<
name|AddressRange
decl|>
name|m_address_ranges
empty_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|AddressResolver
argument_list|)
empty_stmt|;
block|}
enum|;
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
comment|// liblldb_AddressResolver_h_
end_comment

end_unit

