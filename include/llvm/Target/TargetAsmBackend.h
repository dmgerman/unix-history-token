begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetAsmBackend.h - Target Asm Backend -----*- C++ -*-===//
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
name|LLVM_TARGET_TARGETASMBACKEND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETASMBACKEND_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Target
decl_stmt|;
comment|/// TargetAsmBackend - Generic interface to target specific assembler backends.
name|class
name|TargetAsmBackend
block|{
name|TargetAsmBackend
argument_list|(
specifier|const
name|TargetAsmBackend
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetAsmBackend
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
comment|// Can only create subclasses.
name|TargetAsmBackend
argument_list|(
specifier|const
name|Target
operator|&
argument_list|)
expr_stmt|;
comment|/// TheTarget - The Target that this machine was created for.
specifier|const
name|Target
modifier|&
name|TheTarget
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|TargetAsmBackend
argument_list|()
expr_stmt|;
specifier|const
name|Target
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|TheTarget
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

