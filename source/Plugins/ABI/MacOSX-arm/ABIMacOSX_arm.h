begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ABIMacOSX_arm.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_ABIMacOSX_arm_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ABIMacOSX_arm_h_
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
file|"lldb/Target/ABI.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|class
name|ABIMacOSX_arm
range|:
name|public
name|lldb_private
operator|::
name|ABI
block|{
name|public
operator|:
operator|~
name|ABIMacOSX_arm
argument_list|()
name|override
operator|=
expr|default
block|;
name|size_t
name|GetRedZoneSize
argument_list|()
specifier|const
name|override
block|;
name|bool
name|PrepareTrivialCall
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb::addr_t sp
argument_list|,
argument|lldb::addr_t func_addr
argument_list|,
argument|lldb::addr_t returnAddress
argument_list|,
argument|llvm::ArrayRef<lldb::addr_t> args
argument_list|)
specifier|const
name|override
block|;
name|bool
name|GetArgumentValues
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb_private::ValueList&values
argument_list|)
specifier|const
name|override
block|;
name|lldb_private
operator|::
name|Status
name|SetReturnValueObject
argument_list|(
argument|lldb::StackFrameSP&frame_sp
argument_list|,
argument|lldb::ValueObjectSP&new_value
argument_list|)
name|override
block|;
name|bool
name|CreateFunctionEntryUnwindPlan
argument_list|(
argument|lldb_private::UnwindPlan&unwind_plan
argument_list|)
name|override
block|;
name|bool
name|CreateDefaultUnwindPlan
argument_list|(
argument|lldb_private::UnwindPlan&unwind_plan
argument_list|)
name|override
block|;
name|bool
name|RegisterIsVolatile
argument_list|(
argument|const lldb_private::RegisterInfo *reg_info
argument_list|)
name|override
block|;
name|bool
name|CallFrameAddressIsValid
argument_list|(
argument|lldb::addr_t cfa
argument_list|)
name|override
block|{
comment|// Make sure the stack call frame addresses are are 4 byte aligned
if|if
condition|(
name|cfa
operator|&
operator|(
literal|4ull
operator|-
literal|1ull
operator|)
condition|)
return|return
name|false
return|;
comment|// Not 4 byte aligned
if|if
condition|(
name|cfa
operator|==
literal|0
condition|)
return|return
name|false
return|;
end_decl_stmt

begin_comment
comment|// Zero is not a valid stack address
end_comment

begin_return
return|return
name|true
return|;
end_return

begin_macro
unit|}    bool
name|CodeAddressIsValid
argument_list|(
argument|lldb::addr_t pc
argument_list|)
end_macro

begin_macro
name|override
end_macro

begin_block
block|{
comment|// Just make sure the address is a valid 32 bit address. Bit zero
comment|// might be set due to Thumb function calls, so don't enforce 2 byte
comment|// alignment
return|return
name|pc
operator|<=
name|UINT32_MAX
return|;
block|}
end_block

begin_expr_stmt
name|lldb
operator|::
name|addr_t
name|FixCodeAddress
argument_list|(
argument|lldb::addr_t pc
argument_list|)
name|override
block|{
comment|// ARM uses bit zero to signify a code address is thumb, so we must
comment|// strip bit zero in any code addresses.
return|return
name|pc
operator|&
operator|~
operator|(
name|lldb
operator|::
name|addr_t
operator|)
literal|1
return|;
block|}
end_expr_stmt

begin_expr_stmt
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfoArray
argument_list|(
argument|uint32_t&count
argument_list|)
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|bool
name|IsArmv7kProcess
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// Static Functions
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
specifier|static
name|void
name|Initialize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|Terminate
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
specifier|static
name|lldb
operator|::
name|ABISP
name|CreateInstance
argument_list|(
argument|lldb::ProcessSP process_sp
argument_list|,
argument|const lldb_private::ArchSpec&arch
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|// PluginInterface protocol
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_expr_stmt
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObjectImpl
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb_private::CompilerType&ast_type
argument_list|)
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_macro
name|ABIMacOSX_arm
argument_list|(
argument|lldb::ProcessSP process_sp
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|lldb_private
operator|::
name|ABI
argument_list|(
argument|process_sp
argument_list|)
block|{
comment|// Call CreateInstance instead.
block|}
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ABIMacOSX_arm_h_
end_comment

end_unit

