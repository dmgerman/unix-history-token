begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetOpcodes.h - Target Indep Opcodes ------*- C++ -*-===//
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
comment|// This file defines the target independent instruction opcodes.
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
name|LLVM_TARGET_TARGETOPCODES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETOPCODES_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Invariant opcodes: All instruction sets have these as their low opcodes.
comment|///
name|namespace
name|TargetOpcode
block|{
enum|enum
block|{
define|#
directive|define
name|HANDLE_TARGET_OPCODE
parameter_list|(
name|OPC
parameter_list|)
value|OPC,
define|#
directive|define
name|HANDLE_TARGET_OPCODE_MARKER
parameter_list|(
name|IDENT
parameter_list|,
name|OPC
parameter_list|)
value|IDENT = OPC,
include|#
directive|include
file|"llvm/Target/TargetOpcodes.def"
block|}
enum|;
block|}
comment|// end namespace TargetOpcode
comment|/// Check whether the given Opcode is a generic opcode that is not supposed
comment|/// to appear after ISel.
specifier|static
specifier|inline
name|bool
name|isPreISelGenericOpcode
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
return|return
name|Opcode
operator|>=
name|TargetOpcode
operator|::
name|PRE_ISEL_GENERIC_OPCODE_START
operator|&&
name|Opcode
operator|<=
name|TargetOpcode
operator|::
name|PRE_ISEL_GENERIC_OPCODE_END
return|;
block|}
comment|/// Check whether the given Opcode is a target-specific opcode.
specifier|static
specifier|inline
name|bool
name|isTargetSpecificOpcode
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
return|return
name|Opcode
operator|>
name|TargetOpcode
operator|::
name|PRE_ISEL_GENERIC_OPCODE_END
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

