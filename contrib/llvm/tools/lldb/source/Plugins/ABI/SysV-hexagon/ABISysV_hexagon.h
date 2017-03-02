begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ABISysV_hexagon.h ----------------------------------------*- C++
end_comment

begin_comment
comment|//-*-===//
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
name|liblldb_ABISysV_hexagon_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ABISysV_hexagon_h_
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
name|ABISysV_hexagon
range|:
name|public
name|lldb_private
operator|::
name|ABI
block|{
name|public
operator|:
operator|~
name|ABISysV_hexagon
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
argument|lldb::addr_t functionAddress
argument_list|,
argument|lldb::addr_t returnAddress
argument_list|,
argument|llvm::ArrayRef<lldb::addr_t> args
argument_list|)
specifier|const
name|override
block|;
comment|// special thread plan for GDB style non-jit function calls
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
argument|llvm::Type&prototype
argument_list|,
argument|llvm::ArrayRef<ABI::CallArgument> args
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
name|Error
name|SetReturnValueObject
argument_list|(
argument|lldb::StackFrameSP&frame_sp
argument_list|,
argument|lldb::ValueObjectSP&new_value
argument_list|)
name|override
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObjectImpl
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb_private::CompilerType&type
argument_list|)
specifier|const
name|override
block|;
comment|// specialized to work with llvm IR types
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObjectImpl
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|llvm::Type&type
argument_list|)
specifier|const
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
comment|// Make sure the stack call frame addresses are 8 byte aligned
if|if
condition|(
name|cfa
operator|&
literal|0x07
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
comment|// We have a 64 bit address space, so anything is valid as opcodes
comment|// aren't fixed width...
return|return
name|true
return|;
block|}
end_block

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

begin_function_decl
name|void
name|CreateRegisterMapIfNeeded
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObjectSimple
argument_list|(
argument|lldb_private::Thread&thread
argument_list|,
argument|lldb_private::CompilerType&ast_type
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

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
name|ABISysV_hexagon
argument_list|()
operator|:
name|lldb_private
operator|::
name|ABI
argument_list|()
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
comment|// liblldb_ABISysV_hexagon_h_
end_comment

end_unit

