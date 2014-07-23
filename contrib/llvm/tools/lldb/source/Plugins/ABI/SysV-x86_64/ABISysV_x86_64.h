begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ABISysV_x86_64.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_ABISysV_x86_64_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ABISysV_x86_64_h_
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

begin_decl_stmt
name|class
name|ABISysV_x86_64
range|:
name|public
name|lldb_private
operator|::
name|ABI
block|{
name|public
operator|:
operator|~
name|ABISysV_x86_64
argument_list|()
block|{     }
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
argument|lldb::addr_t functionAddress
argument_list|,
argument|lldb::addr_t returnAddress
argument_list|,
argument|llvm::ArrayRef<lldb::addr_t> args
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
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObjectSimple
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
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObjectImpl
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb_private::ClangASTType&type
argument_list|)
specifier|const
block|;
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
comment|// The SysV x86_64 ABI requires that stack frames be 16 byte aligned.
comment|// When there is a trap handler on the stack, e.g. _sigtramp in userland
comment|// code, we've seen that the stack pointer is often not aligned properly
comment|// before the handler is invoked.  This means that lldb will stop the unwind
comment|// early -- before the function which caused the trap.
comment|//
comment|// To work around this, we relax that alignment to be just word-size (8-bytes).
comment|// Whitelisting the trap handlers for user space would be easy (_sigtramp) but
comment|// in other environments there can be a large number of different functions
comment|// involved in async traps.
name|virtual
name|bool
name|CallFrameAddressIsValid
argument_list|(
argument|lldb::addr_t cfa
argument_list|)
block|{
comment|// Make sure the stack call frame addresses are 8 byte aligned
if|if
condition|(
name|cfa
operator|&
operator|(
literal|8ull
operator|-
literal|1ull
operator|)
condition|)
return|return
name|false
return|;
comment|// Not 8 byte aligned
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

begin_decl_stmt
unit|}          virtual
name|bool
name|CodeAddressIsValid
argument_list|(
name|lldb
operator|::
name|addr_t
name|pc
argument_list|)
block|{
comment|// We have a 64 bit address space, so anything is valid as opcodes
comment|// aren't fixed width...
return|return
name|true
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

begin_function_decl
name|void
name|CreateRegisterMapIfNeeded
parameter_list|()
function_decl|;
end_function_decl

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

begin_expr_stmt
name|ABISysV_x86_64
argument_list|()
operator|:
name|lldb_private
operator|::
name|ABI
argument_list|()
block|{ }
end_expr_stmt

begin_comment
comment|// Call CreateInstance instead.
end_comment

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ABI_h_
end_comment

end_unit

