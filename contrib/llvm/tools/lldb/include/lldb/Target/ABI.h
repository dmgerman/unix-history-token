begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ABI.h ---------------------------------------------------*- C++ -*-===//
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
name|liblldb_ABI_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ABI_h_
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
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/UnwindPlan.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_comment
comment|// forward define the llvm::Type class
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Type
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ABI
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
expr|struct
name|CallArgument
block|{     enum
name|eType
block|{
name|HostPointer
operator|=
literal|0
block|,
comment|/* pointer to host data */
name|TargetValue
block|,
comment|/* value is on the target or literal */
block|}
block|;
name|eType
name|type
block|;
comment|/* value of eType */
name|size_t
name|size
block|;
comment|/* size in bytes of this argument */
name|lldb
operator|::
name|addr_t
name|value
block|;
comment|/* literal value */
name|std
operator|::
name|unique_ptr
operator|<
name|uint8_t
index|[]
operator|>
name|data_ap
block|;
comment|/* host data pointer */
block|}
block|;
operator|~
name|ABI
argument_list|()
name|override
block|;
name|virtual
name|size_t
name|GetRedZoneSize
argument_list|()
specifier|const
operator|=
literal|0
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
operator|=
literal|0
block|;
comment|// Prepare trivial call used from ThreadPlanFunctionCallUsingABI
comment|// AD:
comment|//  . Because i don't want to change other ABI's this is not declared pure
comment|//  virtual.
comment|//    The dummy implementation will simply fail.  Only HexagonABI will
comment|//    currently
comment|//    use this method.
comment|//  . Two PrepareTrivialCall's is not good design so perhaps this should be
comment|//  combined.
comment|//
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
argument|llvm::Type&prototype
argument_list|,
argument|llvm::ArrayRef<CallArgument> args
argument_list|)
specifier|const
block|;
name|virtual
name|bool
name|GetArgumentValues
argument_list|(
argument|Thread&thread
argument_list|,
argument|ValueList&values
argument_list|)
specifier|const
operator|=
literal|0
block|;
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObject
argument_list|(
argument|Thread&thread
argument_list|,
argument|CompilerType&type
argument_list|,
argument|bool persistent = true
argument_list|)
specifier|const
block|;
comment|// specialized to work with llvm IR types
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObject
argument_list|(
argument|Thread&thread
argument_list|,
argument|llvm::Type&type
argument_list|,
argument|bool persistent = true
argument_list|)
specifier|const
block|;
comment|// Set the Return value object in the current frame as though a function with
name|virtual
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
operator|=
literal|0
block|;
name|protected
operator|:
comment|// This is the method the ABI will call to actually calculate the return
comment|// value.
comment|// Don't put it in a persistent value object, that will be done by the
comment|// ABI::GetReturnValueObject.
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObjectImpl
argument_list|(
argument|Thread&thread
argument_list|,
argument|CompilerType&ast_type
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|// specialized to work with llvm IR types
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObjectImpl
argument_list|(
argument|Thread&thread
argument_list|,
argument|llvm::Type&ir_type
argument_list|)
specifier|const
block|;
name|public
operator|:
name|virtual
name|bool
name|CreateFunctionEntryUnwindPlan
argument_list|(
name|UnwindPlan
operator|&
name|unwind_plan
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|CreateDefaultUnwindPlan
argument_list|(
name|UnwindPlan
operator|&
name|unwind_plan
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|RegisterIsVolatile
argument_list|(
specifier|const
name|RegisterInfo
operator|*
name|reg_info
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|GetFallbackRegisterLocation
argument_list|(
specifier|const
name|RegisterInfo
operator|*
name|reg_info
argument_list|,
name|UnwindPlan
operator|::
name|Row
operator|::
name|RegisterLocation
operator|&
name|unwind_regloc
argument_list|)
block|;
comment|// Should take a look at a call frame address (CFA) which is just the stack
comment|// pointer value upon entry to a function. ABIs usually impose alignment
comment|// restrictions (4, 8 or 16 byte aligned), and zero is usually not allowed.
comment|// This function should return true if "cfa" is valid call frame address for
comment|// the ABI, and false otherwise. This is used by the generic stack frame
comment|// unwinding
comment|// code to help determine when a stack ends.
name|virtual
name|bool
name|CallFrameAddressIsValid
argument_list|(
argument|lldb::addr_t cfa
argument_list|)
operator|=
literal|0
block|;
comment|// Validates a possible PC value and returns true if an opcode can be at "pc".
name|virtual
name|bool
name|CodeAddressIsValid
argument_list|(
argument|lldb::addr_t pc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|addr_t
name|FixCodeAddress
argument_list|(
argument|lldb::addr_t pc
argument_list|)
block|{
comment|// Some targets might use bits in a code address to indicate
comment|// a mode switch. ARM uses bit zero to signify a code address is
comment|// thumb, so any ARM ABI plug-ins would strip those bits.
return|return
name|pc
return|;
block|}
name|virtual
specifier|const
name|RegisterInfo
operator|*
name|GetRegisterInfoArray
argument_list|(
name|uint32_t
operator|&
name|count
argument_list|)
operator|=
literal|0
block|;
name|bool
name|GetRegisterInfoByName
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
name|RegisterInfo
operator|&
name|info
argument_list|)
block|;
name|bool
name|GetRegisterInfoByKind
argument_list|(
argument|lldb::RegisterKind reg_kind
argument_list|,
argument|uint32_t reg_num
argument_list|,
argument|RegisterInfo&info
argument_list|)
block|;
name|virtual
name|bool
name|GetPointerReturnRegister
argument_list|(
argument|const char *&name
argument_list|)
block|{
return|return
name|false
return|;
block|}
specifier|static
name|lldb
operator|::
name|ABISP
name|FindPlugin
argument_list|(
specifier|const
name|ArchSpec
operator|&
name|arch
argument_list|)
block|;
name|protected
operator|:
comment|//------------------------------------------------------------------
comment|// Classes that inherit from ABI can see and modify these
comment|//------------------------------------------------------------------
name|ABI
argument_list|()
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|ABI
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
comment|// liblldb_ABI_h_
end_comment

end_unit

