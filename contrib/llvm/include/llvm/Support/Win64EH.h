begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/Win64EH.h ---Win64 EH Constants-------------*- C++ -*-===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// This file contains constants and structures used for implementing
end_comment

begin_comment
comment|// exception handling on Win64 platforms. For more information, see
end_comment

begin_comment
comment|// http://msdn.microsoft.com/en-us/library/1eyas8tf.aspx
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
name|LLVM_SUPPORT_WIN64EH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_WIN64EH_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|Win64EH
block|{
comment|/// UnwindOpcodes - Enumeration whose values specify a single operation in
comment|/// the prolog of a function.
enum|enum
name|UnwindOpcodes
block|{
name|UOP_PushNonVol
init|=
literal|0
block|,
name|UOP_AllocLarge
block|,
name|UOP_AllocSmall
block|,
name|UOP_SetFPReg
block|,
name|UOP_SaveNonVol
block|,
name|UOP_SaveNonVolBig
block|,
name|UOP_SaveXMM128
init|=
literal|8
block|,
name|UOP_SaveXMM128Big
block|,
name|UOP_PushMachFrame
block|}
enum|;
comment|/// UnwindCode - This union describes a single operation in a function prolog,
comment|/// or part thereof.
union|union
name|UnwindCode
block|{
struct|struct
block|{
name|uint8_t
name|codeOffset
decl_stmt|;
name|uint8_t
name|unwindOp
range|:
literal|4
decl_stmt|,
name|opInfo
range|:
literal|4
decl_stmt|;
block|}
name|u
struct|;
name|uint16_t
name|frameOffset
decl_stmt|;
block|}
union|;
enum|enum
block|{
comment|/// UNW_ExceptionHandler - Specifies that this function has an exception
comment|/// handler.
name|UNW_ExceptionHandler
init|=
literal|0x01
block|,
comment|/// UNW_TerminateHandler - Specifies that this function has a termination
comment|/// handler.
name|UNW_TerminateHandler
init|=
literal|0x02
block|,
comment|/// UNW_ChainInfo - Specifies that this UnwindInfo structure is chained to
comment|/// another one.
name|UNW_ChainInfo
init|=
literal|0x04
block|}
enum|;
comment|/// RuntimeFunction - An entry in the table of functions with unwind info.
struct|struct
name|RuntimeFunction
block|{
name|uint64_t
name|startAddress
decl_stmt|;
name|uint64_t
name|endAddress
decl_stmt|;
name|uint64_t
name|unwindInfoOffset
decl_stmt|;
block|}
struct|;
comment|/// UnwindInfo - An entry in the exception table.
struct|struct
name|UnwindInfo
block|{
name|uint8_t
name|version
range|:
literal|3
decl_stmt|,
name|flags
range|:
literal|5
decl_stmt|;
name|uint8_t
name|prologSize
decl_stmt|;
name|uint8_t
name|numCodes
decl_stmt|;
name|uint8_t
name|frameRegister
range|:
literal|4
decl_stmt|,
name|frameOffset
range|:
literal|4
decl_stmt|;
name|UnwindCode
name|unwindCodes
index|[
literal|1
index|]
decl_stmt|;
name|void
modifier|*
name|getLanguageSpecificData
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
operator|&
name|unwindCodes
index|[
operator|(
name|numCodes
operator|+
literal|1
operator|)
operator|&
operator|~
literal|1
index|]
operator|)
return|;
block|}
name|uint64_t
name|getLanguageSpecificHandlerOffset
parameter_list|()
block|{
return|return
operator|*
name|reinterpret_cast
operator|<
name|uint64_t
operator|*
operator|>
operator|(
name|getLanguageSpecificData
argument_list|()
operator|)
return|;
block|}
name|void
name|setLanguageSpecificHandlerOffset
parameter_list|(
name|uint64_t
name|offset
parameter_list|)
block|{
operator|*
name|reinterpret_cast
operator|<
name|uint64_t
operator|*
operator|>
operator|(
name|getLanguageSpecificData
argument_list|()
operator|)
operator|=
name|offset
expr_stmt|;
block|}
name|RuntimeFunction
modifier|*
name|getChainedFunctionEntry
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|RuntimeFunction
operator|*
operator|>
operator|(
name|getLanguageSpecificData
argument_list|()
operator|)
return|;
block|}
name|void
modifier|*
name|getExceptionData
parameter_list|()
block|{
return|return
name|reinterpret_cast
operator|<
name|void
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|uint64_t
operator|*
operator|>
operator|(
name|getLanguageSpecificData
argument_list|()
operator|)
operator|+
literal|1
operator|)
return|;
block|}
block|}
struct|;
block|}
comment|// End of namespace Win64EH
block|}
end_decl_stmt

begin_comment
comment|// End of namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

