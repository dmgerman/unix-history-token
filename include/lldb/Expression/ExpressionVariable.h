begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ExpressionVariable.h ------------------------------------*- C++ -*-===//
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
name|liblldb_ExpressionVariable_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ExpressionVariable_h_
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
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/ValueObject.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ClangExpressionVariable
decl_stmt|;
name|class
name|ExpressionVariable
range|:
name|public
name|std
operator|::
name|enable_shared_from_this
operator|<
name|ExpressionVariable
operator|>
block|{
name|public
operator|:
comment|//----------------------------------------------------------------------
comment|// See TypeSystem.h for how to add subclasses to this.
comment|//----------------------------------------------------------------------
expr|enum
name|LLVMCastKind
block|{
name|eKindClang
block|,
name|eKindSwift
block|,
name|eKindGo
block|,
name|kNumKinds
block|}
block|;
name|LLVMCastKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|m_kind
return|;
block|}
name|ExpressionVariable
argument_list|(
argument|LLVMCastKind kind
argument_list|)
operator|:
name|m_flags
argument_list|(
literal|0
argument_list|)
block|,
name|m_kind
argument_list|(
argument|kind
argument_list|)
block|{}
name|virtual
operator|~
name|ExpressionVariable
argument_list|()
block|;
name|size_t
name|GetByteSize
argument_list|()
block|{
return|return
name|m_frozen_sp
operator|->
name|GetByteSize
argument_list|()
return|;
block|}
specifier|const
name|ConstString
operator|&
name|GetName
argument_list|()
block|{
return|return
name|m_frozen_sp
operator|->
name|GetName
argument_list|()
return|;
block|}
name|lldb
operator|::
name|ValueObjectSP
name|GetValueObject
argument_list|()
block|{
return|return
name|m_frozen_sp
return|;
block|}
name|uint8_t
operator|*
name|GetValueBytes
argument_list|()
block|;
name|void
name|ValueUpdated
argument_list|()
block|{
name|m_frozen_sp
operator|->
name|ValueUpdated
argument_list|()
block|; }
name|RegisterInfo
operator|*
name|GetRegisterInfo
argument_list|()
block|{
return|return
name|m_frozen_sp
operator|->
name|GetValue
argument_list|()
operator|.
name|GetRegisterInfo
argument_list|()
return|;
block|}
name|void
name|SetRegisterInfo
argument_list|(
argument|const RegisterInfo *reg_info
argument_list|)
block|{
return|return
name|m_frozen_sp
operator|->
name|GetValue
argument_list|()
operator|.
name|SetContext
argument_list|(
name|Value
operator|::
name|eContextTypeRegisterInfo
argument_list|,
name|const_cast
operator|<
name|RegisterInfo
operator|*
operator|>
operator|(
name|reg_info
operator|)
argument_list|)
return|;
block|}
name|CompilerType
name|GetCompilerType
argument_list|()
block|{
return|return
name|m_frozen_sp
operator|->
name|GetCompilerType
argument_list|()
return|;
block|}
name|void
name|SetCompilerType
argument_list|(
argument|const CompilerType&compiler_type
argument_list|)
block|{
name|m_frozen_sp
operator|->
name|GetValue
argument_list|()
operator|.
name|SetCompilerType
argument_list|(
name|compiler_type
argument_list|)
block|;   }
name|void
name|SetName
argument_list|(
argument|const ConstString&name
argument_list|)
block|{
name|m_frozen_sp
operator|->
name|SetName
argument_list|(
name|name
argument_list|)
block|; }
comment|// this function is used to copy the address-of m_live_sp into m_frozen_sp
comment|// this is necessary because the results of certain cast and
comment|// pointer-arithmetic
comment|// operations (such as those described in bugzilla issues 11588 and 11618)
comment|// generate
comment|// frozen objects that do not have a valid address-of, which can be
comment|// troublesome when
comment|// using synthetic children providers. Transferring the address-of the live
comment|// object
comment|// solves these issues and provides the expected user-level behavior
name|void
name|TransferAddress
argument_list|(
argument|bool force = false
argument_list|)
block|{
if|if
condition|(
name|m_live_sp
operator|.
name|get
argument_list|()
operator|==
name|nullptr
condition|)
return|return;
if|if
condition|(
name|m_frozen_sp
operator|.
name|get
argument_list|()
operator|==
name|nullptr
condition|)
return|return;
if|if
condition|(
name|force
operator|||
operator|(
name|m_frozen_sp
operator|->
name|GetLiveAddress
argument_list|()
operator|==
name|LLDB_INVALID_ADDRESS
operator|)
condition|)
name|m_frozen_sp
operator|->
name|SetLiveAddress
argument_list|(
name|m_live_sp
operator|->
name|GetLiveAddress
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_enum
enum|enum
name|Flags
block|{
name|EVNone
init|=
literal|0
block|,
name|EVIsLLDBAllocated
init|=
literal|1
operator|<<
literal|0
block|,
comment|///< This variable is resident in a location
comment|///specifically allocated for it by LLDB in the
comment|///target process
name|EVIsProgramReference
init|=
literal|1
operator|<<
literal|1
block|,
comment|///< This variable is a reference to a
comment|///(possibly invalid) area managed by the
comment|///target program
name|EVNeedsAllocation
init|=
literal|1
operator|<<
literal|2
block|,
comment|///< Space for this variable has yet to be
comment|///allocated in the target process
name|EVIsFreezeDried
init|=
literal|1
operator|<<
literal|3
block|,
comment|///< This variable's authoritative version is in
comment|///m_frozen_sp (for example, for
comment|///statically-computed results)
name|EVNeedsFreezeDry
init|=
literal|1
operator|<<
literal|4
block|,
comment|///< Copy from m_live_sp to m_frozen_sp during dematerialization
name|EVKeepInTarget
init|=
literal|1
operator|<<
literal|5
block|,
comment|///< Keep the allocation after the expression is
comment|///complete rather than freeze drying its contents
comment|///and freeing it
name|EVTypeIsReference
init|=
literal|1
operator|<<
literal|6
block|,
comment|///< The original type of this variable is a
comment|///reference, so materialize the value rather
comment|///than the location
name|EVUnknownType
init|=
literal|1
operator|<<
literal|7
block|,
comment|///< This is a symbol of unknown type, and the type
comment|///must be resolved after parsing is complete
name|EVBareRegister
init|=
literal|1
operator|<<
literal|8
comment|///< This variable is a direct reference to $pc or
comment|///some other entity.
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|uint16_t
name|FlagType
typedef|;
end_typedef

begin_decl_stmt
name|FlagType
name|m_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|// takes elements of Flags
end_comment

begin_comment
comment|// these should be private
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ValueObjectSP
name|m_frozen_sp
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|ValueObjectSP
name|m_live_sp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|LLVMCastKind
name|m_kind
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class ExpressionVariableList ExpressionVariable.h
end_comment

begin_comment
comment|/// "lldb/Expression/ExpressionVariable.h"
end_comment

begin_comment
comment|/// @brief A list of variable references.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class stores variables internally, acting as the permanent store.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_decl_stmt
name|class
name|ExpressionVariableList
block|{
name|public
label|:
comment|//----------------------------------------------------------------------
comment|/// Implementation of methods in ExpressionVariableListBase
comment|//----------------------------------------------------------------------
name|size_t
name|GetSize
parameter_list|()
block|{
return|return
name|m_variables
operator|.
name|size
argument_list|()
return|;
block|}
name|lldb
operator|::
name|ExpressionVariableSP
name|GetVariableAtIndex
argument_list|(
argument|size_t index
argument_list|)
block|{
name|lldb
operator|::
name|ExpressionVariableSP
name|var_sp
block|;
if|if
condition|(
name|index
operator|<
name|m_variables
operator|.
name|size
argument_list|()
condition|)
name|var_sp
operator|=
name|m_variables
index|[
name|index
index|]
expr_stmt|;
return|return
name|var_sp
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|size_t
name|AddVariable
argument_list|(
specifier|const
name|lldb
operator|::
name|ExpressionVariableSP
operator|&
name|var_sp
argument_list|)
block|{
name|m_variables
operator|.
name|push_back
argument_list|(
name|var_sp
argument_list|)
expr_stmt|;
return|return
name|m_variables
operator|.
name|size
argument_list|()
operator|-
literal|1
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|ExpressionVariableSP
name|AddNewlyConstructedVariable
argument_list|(
argument|ExpressionVariable *var
argument_list|)
block|{
name|lldb
operator|::
name|ExpressionVariableSP
name|var_sp
argument_list|(
name|var
argument_list|)
block|;
name|m_variables
operator|.
name|push_back
argument_list|(
name|var_sp
argument_list|)
block|;
return|return
name|m_variables
operator|.
name|back
argument_list|()
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|ContainsVariable
argument_list|(
specifier|const
name|lldb
operator|::
name|ExpressionVariableSP
operator|&
name|var_sp
argument_list|)
block|{
specifier|const
name|size_t
name|size
init|=
name|m_variables
operator|.
name|size
argument_list|()
decl_stmt|;
for|for
control|(
name|size_t
name|index
init|=
literal|0
init|;
name|index
operator|<
name|size
condition|;
operator|++
name|index
control|)
block|{
if|if
condition|(
name|m_variables
index|[
name|index
index|]
operator|.
name|get
argument_list|()
operator|==
name|var_sp
operator|.
name|get
argument_list|()
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_decl_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// Finds a variable by name in the list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] name
end_comment

begin_comment
comment|///     The name of the requested variable.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The variable requested, or nullptr if that variable is not in the
end_comment

begin_comment
comment|///     list.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ExpressionVariableSP
name|GetVariable
argument_list|(
argument|const ConstString&name
argument_list|)
block|{
name|lldb
operator|::
name|ExpressionVariableSP
name|var_sp
block|;
for|for
control|(
name|size_t
name|index
init|=
literal|0
init|,
name|size
init|=
name|GetSize
argument_list|()
init|;
name|index
operator|<
name|size
condition|;
operator|++
name|index
control|)
block|{
name|var_sp
operator|=
name|GetVariableAtIndex
argument_list|(
name|index
argument_list|)
expr_stmt|;
if|if
condition|(
name|var_sp
operator|->
name|GetName
argument_list|()
operator|==
name|name
condition|)
return|return
name|var_sp
return|;
block|}
name|var_sp
operator|.
name|reset
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|var_sp
return|;
end_return

begin_expr_stmt
unit|}    lldb
operator|::
name|ExpressionVariableSP
name|GetVariable
argument_list|(
argument|llvm::StringRef name
argument_list|)
block|{
if|if
condition|(
name|name
operator|.
name|empty
argument_list|()
condition|)
return|return
name|nullptr
return|;
end_expr_stmt

begin_for
for|for
control|(
name|size_t
name|index
init|=
literal|0
init|,
name|size
init|=
name|GetSize
argument_list|()
init|;
name|index
operator|<
name|size
condition|;
operator|++
name|index
control|)
block|{
name|auto
name|var_sp
init|=
name|GetVariableAtIndex
argument_list|(
name|index
argument_list|)
decl_stmt|;
name|llvm
operator|::
name|StringRef
name|var_name_str
operator|=
name|var_sp
operator|->
name|GetName
argument_list|()
operator|.
name|GetStringRef
argument_list|()
expr_stmt|;
if|if
condition|(
name|var_name_str
operator|==
name|name
condition|)
return|return
name|var_sp
return|;
block|}
end_for

begin_return
return|return
name|nullptr
return|;
end_return

begin_macro
unit|}    void
name|RemoveVariable
argument_list|(
argument|lldb::ExpressionVariableSP var_sp
argument_list|)
end_macro

begin_block
block|{
for|for
control|(
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ExpressionVariableSP
operator|>
operator|::
name|iterator
name|vi
operator|=
name|m_variables
operator|.
name|begin
argument_list|()
operator|,
name|ve
operator|=
name|m_variables
operator|.
name|end
argument_list|()
init|;
name|vi
operator|!=
name|ve
condition|;
operator|++
name|vi
control|)
block|{
if|if
condition|(
name|vi
operator|->
name|get
argument_list|()
operator|==
name|var_sp
operator|.
name|get
argument_list|()
condition|)
block|{
name|m_variables
operator|.
name|erase
argument_list|(
name|vi
argument_list|)
expr_stmt|;
return|return;
block|}
block|}
block|}
end_block

begin_function
name|void
name|Clear
parameter_list|()
block|{
name|m_variables
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|ExpressionVariableSP
operator|>
name|m_variables
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|class
name|PersistentExpressionState
range|:
name|public
name|ExpressionVariableList
block|{
name|public
operator|:
comment|//----------------------------------------------------------------------
comment|// See TypeSystem.h for how to add subclasses to this.
comment|//----------------------------------------------------------------------
expr|enum
name|LLVMCastKind
block|{
name|eKindClang
block|,
name|eKindSwift
block|,
name|eKindGo
block|,
name|kNumKinds
block|}
block|;
name|LLVMCastKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|m_kind
return|;
block|}
name|PersistentExpressionState
argument_list|(
argument|LLVMCastKind kind
argument_list|)
operator|:
name|m_kind
argument_list|(
argument|kind
argument_list|)
block|{}
name|virtual
operator|~
name|PersistentExpressionState
argument_list|()
block|;
name|virtual
name|lldb
operator|::
name|ExpressionVariableSP
name|CreatePersistentVariable
argument_list|(
specifier|const
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|valobj_sp
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|ExpressionVariableSP
name|CreatePersistentVariable
argument_list|(
argument|ExecutionContextScope *exe_scope
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const CompilerType&type
argument_list|,
argument|lldb::ByteOrder byte_order
argument_list|,
argument|uint32_t addr_byte_size
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ConstString
name|GetNextPersistentVariableName
argument_list|()
operator|=
literal|0
block|;
name|virtual
name|void
name|RemovePersistentVariable
argument_list|(
argument|lldb::ExpressionVariableSP variable
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|LookupSymbol
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
name|void
name|RegisterExecutionUnit
argument_list|(
name|lldb
operator|::
name|IRExecutionUnitSP
operator|&
name|execution_unit_sp
argument_list|)
block|;
name|private
operator|:
name|LLVMCastKind
name|m_kind
block|;
typedef|typedef
name|std
operator|::
name|set
operator|<
name|lldb
operator|::
name|IRExecutionUnitSP
operator|>
name|ExecutionUnitSet
expr_stmt|;
name|ExecutionUnitSet
name|m_execution_units
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The execution units that contain valuable symbols.
end_comment

begin_typedef
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|char
operator|*
operator|,
name|lldb
operator|::
name|addr_t
operator|>
name|SymbolMap
expr_stmt|;
end_typedef

begin_decl_stmt
name|SymbolMap
name|m_symbol_map
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< The addresses of the symbols in m_execution_units.
end_comment

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ExpressionVariable_h_
end_comment

end_unit

