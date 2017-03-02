begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//= OSLog.h - Analysis of calls to os_log builtins --*- C++ -*-===============//
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
comment|// This file defines APIs for determining the layout of the data buffer for
end_comment

begin_comment
comment|// os_log() and os_trace().
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
name|LLVM_CLANG_ANALYSIS_ANALYSES_OSLOG_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_ANALYSES_OSLOG_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Expr.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|analyze_os_log
block|{
comment|/// An OSLogBufferItem represents a single item in the data written by a call
comment|/// to os_log() or os_trace().
name|class
name|OSLogBufferItem
block|{
name|public
label|:
enum|enum
name|Kind
block|{
comment|// The item is a scalar (int, float, raw pointer, etc.). No further copying
comment|// is required. This is the only kind allowed by os_trace().
name|ScalarKind
init|=
literal|0
block|,
comment|// The item is a count, which describes the length of the following item to
comment|// be copied. A count may only be followed by an item of kind StringKind,
comment|// WideStringKind, or PointerKind.
name|CountKind
block|,
comment|// The item is a pointer to a C string. If preceded by a count 'n',
comment|// os_log() will copy at most 'n' bytes from the pointer.
name|StringKind
block|,
comment|// The item is a pointer to a block of raw data. This item must be preceded
comment|// by a count 'n'. os_log() will copy exactly 'n' bytes from the pointer.
name|PointerKind
block|,
comment|// The item is a pointer to an Objective-C object. os_log() may retain the
comment|// object for later processing.
name|ObjCObjKind
block|,
comment|// The item is a pointer to wide-char string.
name|WideStringKind
block|,
comment|// The item is corresponding to the '%m' format specifier, no value is
comment|// populated in the buffer and the runtime is loading the errno value.
name|ErrnoKind
block|}
enum|;
enum|enum
block|{
comment|// The item is marked "private" in the format string.
name|IsPrivate
init|=
literal|0x1
block|,
comment|// The item is marked "public" in the format string.
name|IsPublic
init|=
literal|0x2
block|}
enum|;
name|private
label|:
name|Kind
name|TheKind
init|=
name|ScalarKind
decl_stmt|;
specifier|const
name|Expr
modifier|*
name|TheExpr
init|=
name|nullptr
decl_stmt|;
name|CharUnits
name|ConstValue
decl_stmt|;
name|CharUnits
name|Size
decl_stmt|;
comment|// size of the data, not including the header bytes
name|unsigned
name|Flags
init|=
literal|0
decl_stmt|;
name|public
label|:
name|OSLogBufferItem
argument_list|(
argument|Kind kind
argument_list|,
argument|const Expr *expr
argument_list|,
argument|CharUnits size
argument_list|,
argument|unsigned flags
argument_list|)
block|:
name|TheKind
argument_list|(
name|kind
argument_list|)
operator|,
name|TheExpr
argument_list|(
name|expr
argument_list|)
operator|,
name|Size
argument_list|(
name|size
argument_list|)
operator|,
name|Flags
argument_list|(
argument|flags
argument_list|)
block|{}
name|OSLogBufferItem
argument_list|(
argument|ASTContext&Ctx
argument_list|,
argument|CharUnits value
argument_list|,
argument|unsigned flags
argument_list|)
operator|:
name|TheKind
argument_list|(
name|CountKind
argument_list|)
operator|,
name|ConstValue
argument_list|(
name|value
argument_list|)
operator|,
name|Size
argument_list|(
name|Ctx
operator|.
name|getTypeSizeInChars
argument_list|(
name|Ctx
operator|.
name|IntTy
argument_list|)
argument_list|)
operator|,
name|Flags
argument_list|(
argument|flags
argument_list|)
block|{}
name|unsigned
name|char
name|getDescriptorByte
argument_list|()
specifier|const
block|{
name|unsigned
name|char
name|result
operator|=
literal|0
block|;
if|if
condition|(
name|getIsPrivate
argument_list|()
condition|)
name|result
operator||=
name|IsPrivate
expr_stmt|;
if|if
condition|(
name|getIsPublic
argument_list|()
condition|)
name|result
operator||=
name|IsPublic
expr_stmt|;
name|result
operator||=
operator|(
operator|(
name|unsigned
operator|)
name|getKind
argument_list|()
operator|)
operator|<<
literal|4
expr_stmt|;
return|return
name|result
return|;
block|}
name|unsigned
name|char
name|getSizeByte
argument_list|()
specifier|const
block|{
return|return
name|size
argument_list|()
operator|.
name|getQuantity
argument_list|()
return|;
block|}
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|TheKind
return|;
block|}
name|bool
name|getIsPrivate
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|IsPrivate
operator|)
operator|!=
literal|0
return|;
block|}
name|bool
name|getIsPublic
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Flags
operator|&
name|IsPublic
operator|)
operator|!=
literal|0
return|;
block|}
specifier|const
name|Expr
operator|*
name|getExpr
argument_list|()
specifier|const
block|{
return|return
name|TheExpr
return|;
block|}
name|CharUnits
name|getConstValue
argument_list|()
specifier|const
block|{
return|return
name|ConstValue
return|;
block|}
name|CharUnits
name|size
argument_list|()
specifier|const
block|{
return|return
name|Size
return|;
block|}
block|}
empty_stmt|;
name|class
name|OSLogBufferLayout
block|{
name|public
label|:
name|SmallVector
operator|<
name|OSLogBufferItem
operator|,
literal|4
operator|>
name|Items
expr_stmt|;
enum|enum
name|Flags
block|{
name|HasPrivateItems
init|=
literal|1
block|,
name|HasNonScalarItems
init|=
literal|1
operator|<<
literal|1
block|}
enum|;
name|CharUnits
name|size
argument_list|()
specifier|const
block|{
name|CharUnits
name|result
block|;
name|result
operator|+=
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
literal|2
argument_list|)
block|;
comment|// summary byte, num-args byte
for|for
control|(
name|auto
operator|&
name|item
operator|:
name|Items
control|)
block|{
comment|// descriptor byte, size byte
name|result
operator|+=
name|item
operator|.
name|size
argument_list|()
operator|+
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
literal|2
argument_list|)
expr_stmt|;
block|}
return|return
name|result
return|;
block|}
name|bool
name|hasPrivateItems
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|any_of
argument_list|(
name|Items
argument_list|,
index|[]
operator|(
specifier|const
name|OSLogBufferItem
operator|&
name|Item
operator|)
block|{
return|return
name|Item
operator|.
name|getIsPrivate
argument_list|()
return|;
block|}
argument_list|)
return|;
block|}
name|bool
name|hasPublicItems
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|any_of
argument_list|(
name|Items
argument_list|,
index|[]
operator|(
specifier|const
name|OSLogBufferItem
operator|&
name|Item
operator|)
block|{
return|return
name|Item
operator|.
name|getIsPublic
argument_list|()
return|;
block|}
argument_list|)
return|;
block|}
name|bool
name|hasNonScalar
argument_list|()
specifier|const
block|{
return|return
name|llvm
operator|::
name|any_of
argument_list|(
name|Items
argument_list|,
index|[]
operator|(
specifier|const
name|OSLogBufferItem
operator|&
name|Item
operator|)
block|{
return|return
name|Item
operator|.
name|getKind
argument_list|()
operator|!=
name|OSLogBufferItem
operator|::
name|ScalarKind
return|;
block|}
argument_list|)
return|;
block|}
name|unsigned
name|char
name|getSummaryByte
argument_list|()
specifier|const
block|{
name|unsigned
name|char
name|result
operator|=
literal|0
block|;
if|if
condition|(
name|hasPrivateItems
argument_list|()
condition|)
name|result
operator||=
name|HasPrivateItems
expr_stmt|;
if|if
condition|(
name|hasNonScalar
argument_list|()
condition|)
name|result
operator||=
name|HasNonScalarItems
expr_stmt|;
return|return
name|result
return|;
block|}
name|unsigned
name|char
name|getNumArgsByte
argument_list|()
specifier|const
block|{
return|return
name|Items
operator|.
name|size
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Given a call 'E' to one of the builtins __builtin_os_log_format() or
end_comment

begin_comment
comment|// __builtin_os_log_format_buffer_size(), compute the layout of the buffer that
end_comment

begin_comment
comment|// the call will write into and store it in 'layout'. Returns 'false' if there
end_comment

begin_comment
comment|// was some error encountered while computing the layout, and 'true' otherwise.
end_comment

begin_decl_stmt
name|bool
name|computeOSLogBufferLayout
argument_list|(
name|clang
operator|::
name|ASTContext
operator|&
name|Ctx
argument_list|,
specifier|const
name|clang
operator|::
name|CallExpr
operator|*
name|E
argument_list|,
name|OSLogBufferLayout
operator|&
name|layout
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
unit|}
comment|// namespace analyze_os_log
end_comment

begin_comment
unit|}
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

