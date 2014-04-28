begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Util.h - Common Driver Utilities -----------------------*- C++ -*-===//
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
name|CLANG_DRIVER_UTIL_H_
end_ifndef

begin_define
define|#
directive|define
name|CLANG_DRIVER_UTIL_H_
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DiagnosticsEngine
decl_stmt|;
name|namespace
name|driver
block|{
name|class
name|Action
decl_stmt|;
name|class
name|JobAction
decl_stmt|;
comment|/// ArgStringMap - Type used to map a JobAction to its result file.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|JobAction
operator|*
operator|,
specifier|const
name|char
operator|*
operator|>
name|ArgStringMap
expr_stmt|;
comment|/// ActionList - Type used for lists of actions.
typedef|typedef
name|SmallVector
operator|<
name|Action
operator|*
operator|,
literal|3
operator|>
name|ActionList
expr_stmt|;
block|}
comment|// end namespace driver
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

