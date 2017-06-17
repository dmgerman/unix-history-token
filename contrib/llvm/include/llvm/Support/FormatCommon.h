begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FormatAdapters.h - Formatters for common LLVM types -----*- C++ -*-===//
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
name|LLVM_SUPPORT_FORMATCOMMON_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_FORMATCOMMON_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/FormatVariadicDetails.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|enum
name|class
name|AlignStyle
block|{
name|Left
operator|,
name|Center
operator|,
name|Right
block|}
empty_stmt|;
struct|struct
name|FmtAlign
block|{
name|detail
operator|::
name|format_adapter
operator|&
name|Adapter
expr_stmt|;
name|AlignStyle
name|Where
decl_stmt|;
name|size_t
name|Amount
decl_stmt|;
name|char
name|Fill
decl_stmt|;
name|FmtAlign
argument_list|(
argument|detail::format_adapter&Adapter
argument_list|,
argument|AlignStyle Where
argument_list|,
argument|size_t Amount
argument_list|,
argument|char Fill =
literal|' '
argument_list|)
block|:
name|Adapter
argument_list|(
name|Adapter
argument_list|)
operator|,
name|Where
argument_list|(
name|Where
argument_list|)
operator|,
name|Amount
argument_list|(
name|Amount
argument_list|)
operator|,
name|Fill
argument_list|(
argument|Fill
argument_list|)
block|{}
name|void
name|format
argument_list|(
argument|raw_ostream&S
argument_list|,
argument|StringRef Options
argument_list|)
block|{
comment|// If we don't need to align, we can format straight into the underlying
comment|// stream.  Otherwise we have to go through an intermediate stream first
comment|// in order to calculate how long the output is so we can align it.
comment|// TODO: Make the format method return the number of bytes written, that
comment|// way we can also skip the intermediate stream for left-aligned output.
if|if
condition|(
name|Amount
operator|==
literal|0
condition|)
block|{
name|Adapter
operator|.
name|format
argument_list|(
name|S
argument_list|,
name|Options
argument_list|)
expr_stmt|;
return|return;
block|}
name|SmallString
operator|<
literal|64
operator|>
name|Item
expr_stmt|;
name|raw_svector_ostream
name|Stream
argument_list|(
name|Item
argument_list|)
expr_stmt|;
name|Adapter
operator|.
name|format
argument_list|(
name|Stream
argument_list|,
name|Options
argument_list|)
expr_stmt|;
if|if
condition|(
name|Amount
operator|<=
name|Item
operator|.
name|size
argument_list|()
condition|)
block|{
name|S
operator|<<
name|Item
expr_stmt|;
return|return;
block|}
name|size_t
name|PadAmount
init|=
name|Amount
operator|-
name|Item
operator|.
name|size
argument_list|()
decl_stmt|;
switch|switch
condition|(
name|Where
condition|)
block|{
case|case
name|AlignStyle
operator|::
name|Left
case|:
name|S
operator|<<
name|Item
expr_stmt|;
name|fill
argument_list|(
name|S
argument_list|,
name|PadAmount
argument_list|)
expr_stmt|;
break|break;
case|case
name|AlignStyle
operator|::
name|Center
case|:
block|{
name|size_t
name|X
init|=
name|PadAmount
operator|/
literal|2
decl_stmt|;
name|fill
argument_list|(
name|S
argument_list|,
name|X
argument_list|)
expr_stmt|;
name|S
operator|<<
name|Item
expr_stmt|;
name|fill
argument_list|(
name|S
argument_list|,
name|PadAmount
operator|-
name|X
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
name|fill
argument_list|(
name|S
argument_list|,
name|PadAmount
argument_list|)
expr_stmt|;
name|S
operator|<<
name|Item
expr_stmt|;
break|break;
block|}
block|}
name|private
range|:
name|void
name|fill
argument_list|(
argument|llvm::raw_ostream&S
argument_list|,
argument|uint32_t Count
argument_list|)
block|{
for|for
control|(
name|uint32_t
name|I
init|=
literal|0
init|;
name|I
operator|<
name|Count
condition|;
operator|++
name|I
control|)
name|S
operator|<<
name|Fill
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

