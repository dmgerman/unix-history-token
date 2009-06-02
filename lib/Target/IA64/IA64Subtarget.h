begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//====---- IA64Subtarget.h - Define Subtarget for the IA64 -----*- C++ -*--===//
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
comment|// This file declares the IA64 specific subclass of TargetSubtarget.
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
name|IA64SUBTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|IA64SUBTARGET_H
end_define

begin_include
include|#
directive|include
file|"llvm/Target/TargetSubtarget.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|IA64Subtarget
range|:
name|public
name|TargetSubtarget
block|{
name|public
operator|:
name|IA64Subtarget
argument_list|()
block|; }
decl_stmt|;
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

