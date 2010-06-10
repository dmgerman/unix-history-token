begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/System/AIXDataTypesFix.h - Fix datatype defs ------*- C++ -*-===//
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
comment|// This file overrides default system-defined types and limits which cannot be
end_comment

begin_comment
comment|// done in DataTypes.h.in because it is processed by autoheader first, which
end_comment

begin_comment
comment|// comments out any #undef statement
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// No include guards desired!
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_DATATYPES_H
end_ifndef

begin_error
error|#
directive|error
literal|"AIXDataTypesFix.h must only be included via DataTypes.h!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GCC is strict about defining large constants: they must have LL modifier.
end_comment

begin_comment
comment|// These will be defined properly at the end of DataTypes.h
end_comment

begin_undef
undef|#
directive|undef
name|INT64_MAX
end_undef

begin_undef
undef|#
directive|undef
name|INT64_MIN
end_undef

end_unit

