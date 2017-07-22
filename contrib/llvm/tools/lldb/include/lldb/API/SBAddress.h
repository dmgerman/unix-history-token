begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SBAddress.h ---------------------------------------------*- C++ -*-===//
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
name|LLDB_SBAddress_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SBAddress_h_
end_define

begin_include
include|#
directive|include
file|"lldb/API/SBDefines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/API/SBModule.h"
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
name|class
name|LLDB_API
name|SBAddress
block|{
name|public
label|:
name|SBAddress
argument_list|()
expr_stmt|;
name|SBAddress
argument_list|(
specifier|const
name|lldb
operator|::
name|SBAddress
operator|&
name|rhs
argument_list|)
expr_stmt|;
name|SBAddress
argument_list|(
argument|lldb::SBSection section
argument_list|,
argument|lldb::addr_t offset
argument_list|)
empty_stmt|;
comment|// Create an address by resolving a load address using the supplied target
name|SBAddress
argument_list|(
argument|lldb::addr_t load_addr
argument_list|,
argument|lldb::SBTarget&target
argument_list|)
empty_stmt|;
operator|~
name|SBAddress
argument_list|()
expr_stmt|;
specifier|const
name|lldb
operator|::
name|SBAddress
operator|&
name|operator
operator|=
operator|(
specifier|const
name|lldb
operator|::
name|SBAddress
operator|&
name|rhs
operator|)
expr_stmt|;
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|addr_t
name|GetFileAddress
argument_list|()
specifier|const
expr_stmt|;
name|addr_t
name|GetLoadAddress
argument_list|(
specifier|const
name|lldb
operator|::
name|SBTarget
operator|&
name|target
argument_list|)
decl|const
decl_stmt|;
name|void
name|SetAddress
argument_list|(
name|lldb
operator|::
name|SBSection
name|section
argument_list|,
name|lldb
operator|::
name|addr_t
name|offset
argument_list|)
decl_stmt|;
name|void
name|SetLoadAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|lldb
operator|::
name|SBTarget
operator|&
name|target
argument_list|)
decl_stmt|;
name|bool
name|OffsetAddress
parameter_list|(
name|addr_t
name|offset
parameter_list|)
function_decl|;
name|bool
name|GetDescription
argument_list|(
name|lldb
operator|::
name|SBStream
operator|&
name|description
argument_list|)
decl_stmt|;
comment|// The following queries can lookup symbol information for a given address.
comment|// An address might refer to code or data from an existing module, or it
comment|// might refer to something on the stack or heap. The following functions
comment|// will only return valid values if the address has been resolved to a code
comment|// or data address using "void SBAddress::SetLoadAddress(...)" or
comment|// "lldb::SBAddress SBTarget::ResolveLoadAddress (...)".
name|lldb
operator|::
name|SBSymbolContext
name|GetSymbolContext
argument_list|(
argument|uint32_t resolve_scope
argument_list|)
expr_stmt|;
comment|// The following functions grab individual objects for a given address and
comment|// are less efficient if you want more than one symbol related objects.
comment|// Use one of the following when you want multiple debug symbol related
comment|// objects for an address:
comment|//    lldb::SBSymbolContext SBAddress::GetSymbolContext (uint32_t
comment|//    resolve_scope);
comment|//    lldb::SBSymbolContext SBTarget::ResolveSymbolContextForAddress (const
comment|//    SBAddress&addr, uint32_t resolve_scope);
comment|// One or more bits from the SymbolContextItem enumerations can be logically
comment|// OR'ed together to more efficiently retrieve multiple symbol objects.
name|lldb
operator|::
name|SBSection
name|GetSection
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|GetOffset
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBModule
name|GetModule
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBCompileUnit
name|GetCompileUnit
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBFunction
name|GetFunction
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBBlock
name|GetBlock
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBSymbol
name|GetSymbol
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|SBLineEntry
name|GetLineEntry
argument_list|()
expr_stmt|;
name|lldb
operator|::
name|AddressClass
name|GetAddressClass
argument_list|()
expr_stmt|;
name|protected
label|:
name|friend
name|class
name|SBBlock
decl_stmt|;
name|friend
name|class
name|SBBreakpointLocation
decl_stmt|;
name|friend
name|class
name|SBFrame
decl_stmt|;
name|friend
name|class
name|SBFunction
decl_stmt|;
name|friend
name|class
name|SBLineEntry
decl_stmt|;
name|friend
name|class
name|SBInstruction
decl_stmt|;
name|friend
name|class
name|SBModule
decl_stmt|;
name|friend
name|class
name|SBSection
decl_stmt|;
name|friend
name|class
name|SBSymbol
decl_stmt|;
name|friend
name|class
name|SBSymbolContext
decl_stmt|;
name|friend
name|class
name|SBTarget
decl_stmt|;
name|friend
name|class
name|SBThread
decl_stmt|;
name|friend
name|class
name|SBThreadPlan
decl_stmt|;
name|friend
name|class
name|SBValue
decl_stmt|;
name|friend
name|class
name|SBQueueItem
decl_stmt|;
name|lldb_private
operator|::
name|Address
operator|*
name|operator
operator|->
expr|(
block|)
decl_stmt|;
specifier|const
name|lldb_private
operator|::
name|Address
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SBAddress
operator|&
name|lhs
operator|,
specifier|const
name|SBAddress
operator|&
name|rhs
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Address
operator|*
name|get
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|Address
operator|&
name|ref
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|lldb_private
operator|::
name|Address
operator|&
name|ref
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SBAddress
argument_list|(
specifier|const
name|lldb_private
operator|::
name|Address
operator|*
name|lldb_object_ptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|SetAddress
argument_list|(
specifier|const
name|lldb_private
operator|::
name|Address
operator|*
name|lldb_object_ptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|lldb_private
operator|::
name|Address
operator|>
name|m_opaque_ap
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|bool
name|operator
operator|==
operator|(
specifier|const
name|SBAddress
operator|&
name|lhs
operator|,
specifier|const
name|SBAddress
operator|&
name|rhs
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_SBAddress_h_
end_comment

end_unit

