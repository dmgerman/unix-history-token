begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm-lib/LibDriver.h - lib.exe-compatible driver ---------*- C++ -*-===//
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
comment|// Defines an interface to a lib.exe-compatible driver that also understands
end_comment

begin_comment
comment|// bitcode files. Used by llvm-lib and lld-link /lib.
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
name|LLVM_TOOLDRIVERS_LLVM_LIB_LIBDRIVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLDRIVERS_LLVM_LIB_LIBDRIVER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
name|int
name|libDriverMain
argument_list|(
name|ArrayRef
operator|<
specifier|const
name|char
operator|*
operator|>
name|ARgs
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

