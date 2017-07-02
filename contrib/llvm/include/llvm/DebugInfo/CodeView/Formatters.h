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
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormatAdapters.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormatVariadic.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
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
argument|raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
comment|// end namespace detail
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
comment|// end namespace codeview
name|template
operator|<
operator|>
expr|struct
name|format_provider
operator|<
name|codeview
operator|::
name|TypeIndex
operator|>
block|{
name|public
operator|:
specifier|static
name|void
name|format
argument_list|(
argument|const codeview::TypeIndex&V
argument_list|,
argument|raw_ostream&Stream
argument_list|,
argument|StringRef Style
argument_list|)
block|{
if|if
condition|(
name|V
operator|.
name|isNoneType
argument_list|()
condition|)
name|Stream
operator|<<
literal|"<no type>"
expr_stmt|;
else|else
block|{
name|Stream
operator|<<
name|formatv
argument_list|(
literal|"{0:X+4}"
argument_list|,
name|V
operator|.
name|getIndex
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|V
operator|.
name|isSimple
argument_list|()
condition|)
name|Stream
operator|<<
literal|" ("
operator|<<
name|codeview
operator|::
name|TypeIndex
operator|::
name|simpleTypeName
argument_list|(
name|V
argument_list|)
operator|<<
literal|")"
expr_stmt|;
block|}
block|}
block|}
expr_stmt|;
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
comment|// LLVM_DEBUGINFO_CODEVIEW_FORMATTERS_H
end_comment

end_unit

