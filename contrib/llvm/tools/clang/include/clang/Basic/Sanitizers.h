begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Sanitizers.h - C Language Family Language Options ------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::SanitizerKind enum.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_SANITIZERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_SANITIZERS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|enum
name|class
name|SanitizerKind
block|{
define|#
directive|define
name|SANITIZER
parameter_list|(
name|NAME
parameter_list|,
name|ID
parameter_list|)
value|ID,
include|#
directive|include
file|"clang/Basic/Sanitizers.def"
name|Unknown
block|}
empty_stmt|;
name|class
name|SanitizerSet
block|{
comment|/// \brief Bitmask of enabled sanitizers.
name|unsigned
name|Kinds
decl_stmt|;
name|public
label|:
name|SanitizerSet
argument_list|()
expr_stmt|;
comment|/// \brief Check if a certain sanitizer is enabled.
name|bool
name|has
argument_list|(
name|SanitizerKind
name|K
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Enable or disable a certain sanitizer.
name|void
name|set
parameter_list|(
name|SanitizerKind
name|K
parameter_list|,
name|bool
name|Value
parameter_list|)
function_decl|;
comment|/// \brief Disable all sanitizers.
name|void
name|clear
parameter_list|()
function_decl|;
comment|/// \brief Returns true if at least one sanitizer is enabled.
name|bool
name|empty
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
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

