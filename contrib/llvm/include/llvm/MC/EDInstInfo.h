begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/EDInstInfo.h - EDis instruction info ------------*- C++ -*-===//
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
name|EDINSTINFO_H
end_ifndef

begin_define
define|#
directive|define
name|EDINSTINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
define|#
directive|define
name|EDIS_MAX_OPERANDS
value|13
define|#
directive|define
name|EDIS_MAX_SYNTAXES
value|2
struct|struct
name|EDInstInfo
block|{
name|uint8_t
name|instructionType
decl_stmt|;
name|uint8_t
name|numOperands
decl_stmt|;
name|uint8_t
name|operandTypes
index|[
name|EDIS_MAX_OPERANDS
index|]
decl_stmt|;
name|uint8_t
name|operandFlags
index|[
name|EDIS_MAX_OPERANDS
index|]
decl_stmt|;
specifier|const
name|char
name|operandOrders
index|[
name|EDIS_MAX_SYNTAXES
index|]
index|[
name|EDIS_MAX_OPERANDS
index|]
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

