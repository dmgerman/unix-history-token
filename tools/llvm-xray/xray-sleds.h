begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- xray-sleds.h - XRay Sleds Data Structure ---------------------------===//
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
comment|// Defines the structure used to represent XRay instrumentation map entries.
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
name|LLVM_TOOLS_LLVM_XRAY_XRAY_SLEDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVM_XRAY_XRAY_SLEDS_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|xray
block|{
struct|struct
name|SledEntry
block|{
name|enum
name|class
name|FunctionKinds
block|{
name|ENTRY
operator|,
name|EXIT
operator|,
name|TAIL
block|}
empty_stmt|;
name|uint64_t
name|Address
decl_stmt|;
name|uint64_t
name|Function
decl_stmt|;
name|FunctionKinds
name|Kind
decl_stmt|;
name|bool
name|AlwaysInstrument
decl_stmt|;
block|}
struct|;
block|}
comment|// namespace xray
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TOOLS_LLVM_XRAY_XRAY_SLEDS_H
end_comment

end_unit

