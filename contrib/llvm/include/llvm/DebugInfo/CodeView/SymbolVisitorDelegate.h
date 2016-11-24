begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- SymbolVisitorDelegate.h ---------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLVISITORDELEGATE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_SYMBOLVISITORDELEGATE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|SymbolVisitorDelegate
block|{
name|public
label|:
name|virtual
operator|~
name|SymbolVisitorDelegate
argument_list|()
block|{}
name|virtual
name|uint32_t
name|getRecordOffset
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Record
argument_list|)
operator|=
literal|0
expr_stmt|;
name|virtual
name|StringRef
name|getFileNameForFileOffset
parameter_list|(
name|uint32_t
name|FileOffset
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|StringRef
name|getStringTable
parameter_list|()
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
block|}
comment|// end namespace codeview
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_CODEVIEW_SYMBOLVISITORDELEGATE_H
end_comment

end_unit

