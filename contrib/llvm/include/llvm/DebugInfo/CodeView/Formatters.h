begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Formatters.h ---------------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_FORMATTERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_FORMATTERS_H
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
file|"llvm/Support/FormatAdapters.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|namespace
name|detail
block|{
name|class
name|GuidAdapter
name|final
range|:
name|public
name|llvm
operator|::
name|FormatAdapter
operator|<
name|ArrayRef
operator|<
name|uint8_t
operator|>>
block|{
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Guid
block|;
name|public
operator|:
name|explicit
name|GuidAdapter
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Guid
argument_list|)
block|;
name|explicit
name|GuidAdapter
argument_list|(
argument|StringRef Guid
argument_list|)
block|;
name|void
name|format
argument_list|(
argument|llvm::raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
block|; }
decl_stmt|;
block|}
specifier|inline
name|detail
operator|::
name|GuidAdapter
name|fmt_guid
argument_list|(
argument|StringRef Item
argument_list|)
block|{
return|return
name|detail
operator|::
name|GuidAdapter
argument_list|(
name|Item
argument_list|)
return|;
block|}
specifier|inline
name|detail
operator|::
name|GuidAdapter
name|fmt_guid
argument_list|(
argument|ArrayRef<uint8_t> Item
argument_list|)
block|{
return|return
name|detail
operator|::
name|GuidAdapter
argument_list|(
name|Item
argument_list|)
return|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

