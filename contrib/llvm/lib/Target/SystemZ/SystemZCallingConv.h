begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SystemZCallingConv.h - Calling conventions for SystemZ --*- C++ -*-===//
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
name|SYSTEMZCALLINGCONV_H
end_ifndef

begin_define
define|#
directive|define
name|SYSTEMZCALLINGCONV_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|SystemZ
block|{
specifier|const
name|unsigned
name|NumArgGPRs
init|=
literal|5
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|ArgGPRs
index|[
name|NumArgGPRs
index|]
decl_stmt|;
specifier|const
name|unsigned
name|NumArgFPRs
init|=
literal|4
decl_stmt|;
specifier|extern
specifier|const
name|unsigned
name|ArgFPRs
index|[
name|NumArgFPRs
index|]
decl_stmt|;
block|}
comment|// end namespace SystemZ
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

