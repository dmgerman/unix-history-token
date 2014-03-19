begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ABIMacOSX_i386.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_ABIMacOSX_i386_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ABIMacOSX_i386_h_
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
file|"lldb/Target/ABI.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Value.h"
end_include

begin_decl_stmt
name|class
name|ABIMacOSX_i386
range|:
name|public
name|lldb_private
operator|::
name|ABI
block|{
name|public
operator|:
operator|~
name|ABIMacOSX_i386
argument_list|()
block|{ }
name|virtual
name|size_t
name|GetRedZoneSize
argument_list|()
specifier|const
block|;
name|virtual
name|bool
name|PrepareTrivialCall
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb::addr_t sp
argument_list|,
argument|lldb::addr_t func_addr
argument_list|,
argument|lldb::addr_t return_addr
argument_list|,
argument|lldb::addr_t *arg1_ptr = NULL
argument_list|,
argument|lldb::addr_t *arg2_ptr = NULL
argument_list|,
argument|lldb::addr_t *arg3_ptr = NULL
argument_list|,
argument|lldb::addr_t *arg4_ptr = NULL
argument_list|,
argument|lldb::addr_t *arg5_ptr = NULL
argument_list|,
argument|lldb::addr_t *arg6_ptr = NULL
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|PrepareNormalCall
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb::addr_t sp
argument_list|,
argument|lldb::addr_t func_addr
argument_list|,
argument|lldb::addr_t return_addr
argument_list|,
argument|lldb_private::ValueList&args
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|GetArgumentValues
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb_private::ValueList&values
argument_list|)
specifier|const
block|;
name|virtual
name|lldb_private
operator|::
name|Error
name|SetReturnValueObject
argument_list|(
name|lldb
operator|::
name|StackFrameSP
operator|&
name|frame_sp
argument_list|,
name|lldb
operator|::
name|ValueObjectSP
operator|&
name|new_value
argument_list|)
block|;
name|protected
operator|:
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObjectImpl
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb_private::ClangASTType&ast_type
argument_list|)
specifier|const
block|;
name|public
operator|:
name|virtual
name|bool
name|CreateFunctionEntryUnwindPlan
argument_list|(
name|lldb_private
operator|::
name|UnwindPlan
operator|&
name|unwind_plan
argument_list|)
block|;
name|virtual
name|bool
name|CreateDefaultUnwindPlan
argument_list|(
name|lldb_private
operator|::
name|UnwindPlan
operator|&
name|unwind_plan
argument_list|)
block|;
name|virtual
name|bool
name|RegisterIsVolatile
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|)
block|;
name|virtual
name|bool
name|StackUsesFrames
argument_list|()
block|{
return|return
name|true
return|;
block|}
name|virtual
name|bool
name|CallFrameAddressIsValid
argument_list|(
argument|lldb::addr_t cfa
argument_list|)
block|{
comment|// Darwin call frame addresses must be 16-byte aligned, but other OS's
comment|// only need 4-byte alignment.  Otherwise the ABI matches, so we have
comment|// this one minor override here.
if|if
condition|(
name|target_is_darwin
condition|)
block|{
comment|// Make sure the stack call frame addresses are are 16 byte aligned
if|if
condition|(
name|cfa
operator|&
operator|(
literal|16ull
operator|-
literal|1ull
operator|)
condition|)
return|return
name|false
return|;
comment|// Not 16 byte aligned
block|}
else|else
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
block|}
if|if
condition|(
name|cfa
operator|==
literal|0
condition|)
return|return
name|false
return|;
comment|// Zero is not a valid stack address
return|return
name|true
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|virtual
name|bool
name|CodeAddressIsValid
argument_list|(
name|lldb
operator|::
name|addr_t
name|pc
argument_list|)
block|{
comment|// Just make sure the address is a valid 32 bit address.
return|return
name|pc
operator|<=
name|UINT32_MAX
return|;
block|}
end_decl_stmt

begin_function
name|virtual
name|bool
name|FunctionCallsChangeCFA
parameter_list|()
block|{
return|return
name|true
return|;
block|}
end_function

begin_expr_stmt
name|virtual
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|GetRegisterInfoArray
argument_list|(
name|uint32_t
operator|&
name|count
argument_list|)
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
specifier|const
name|lldb_private
operator|::
name|ArchSpec
operator|&
name|arch
argument_list|)
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
specifier|static
name|lldb_private
operator|::
name|ConstString
name|GetPluginNameStatic
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
name|lldb_private
operator|::
name|ConstString
name|GetPluginName
argument_list|()
expr_stmt|;
end_expr_stmt

begin_function_decl
name|virtual
name|uint32_t
name|GetPluginVersion
parameter_list|()
function_decl|;
end_function_decl

begin_label
name|protected
label|:
end_label

begin_decl_stmt
name|bool
name|RegisterIsCalleeSaved
argument_list|(
specifier|const
name|lldb_private
operator|::
name|RegisterInfo
operator|*
name|reg_info
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|private
label|:
end_label

begin_macro
name|ABIMacOSX_i386
argument_list|(
argument|bool is_darwin
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|lldb_private
operator|::
name|ABI
argument_list|()
operator|,
name|target_is_darwin
argument_list|(
argument|is_darwin
argument_list|)
block|{ }
comment|// Call CreateInstance instead.
name|bool
name|target_is_darwin
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ABI_h_
end_comment

end_unit

