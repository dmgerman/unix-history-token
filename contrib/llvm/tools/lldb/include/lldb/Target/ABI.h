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
file|"lldb/Core/Error.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
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
name|virtual
operator|~
name|ABI
argument_list|()
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
argument|Thread&thread
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
argument|ClangASTType&type
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
comment|// This is the method the ABI will call to actually calculate the return value.
comment|// Don't put it in a persistant value object, that will be done by the ABI::GetReturnValueObject.
name|virtual
name|lldb
operator|::
name|ValueObjectSP
name|GetReturnValueObjectImpl
argument_list|(
argument|Thread&thread
argument_list|,
argument|ClangASTType&type
argument_list|)
specifier|const
operator|=
literal|0
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
comment|// Should return true if your ABI uses frames when doing stack backtraces. This
comment|// means a frame pointer is used that points to the previous stack frame in some
comment|// way or another.
name|virtual
name|bool
name|StackUsesFrames
argument_list|()
operator|=
literal|0
block|;
comment|// Should take a look at a call frame address (CFA) which is just the stack
comment|// pointer value upon entry to a function. ABIs usually impose alignment
comment|// restrictions (4, 8 or 16 byte aligned), and zero is usually not allowed.
comment|// This function should return true if "cfa" is valid call frame address for
comment|// the ABI, and false otherwise. This is used by the generic stack frame unwinding
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
comment|// Some architectures (e.g. x86) will push the return address on the stack and decrement
comment|// the stack pointer when making a function call.  This means that every stack frame will
comment|// have a unique CFA.
comment|// Other architectures (e.g. arm) pass the return address in a register so it is possible
comment|// to have a frame on a backtrace that does not push anything on the stack or change the
comment|// CFA.
name|virtual
name|bool
name|FunctionCallsChangeCFA
argument_list|()
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

