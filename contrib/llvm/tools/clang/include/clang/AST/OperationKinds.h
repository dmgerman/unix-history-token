begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- OperationKinds.h - Operation enums -----------------------*- C++ -*-===//
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
comment|// This file enumerates the different kinds of operations that can be
end_comment

begin_comment
comment|// performed by various expressions.
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
name|LLVM_CLANG_AST_OPERATIONKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_OPERATIONKINDS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// CastKind - The kind of operation required for a conversion.
enum|enum
name|CastKind
block|{
define|#
directive|define
name|CAST_OPERATION
parameter_list|(
name|Name
parameter_list|)
value|CK_##Name,
include|#
directive|include
file|"clang/AST/OperationKinds.def"
block|}
enum|;
specifier|static
specifier|const
name|CastKind
name|CK_Invalid
init|=
name|static_cast
operator|<
name|CastKind
operator|>
operator|(
operator|-
literal|1
operator|)
decl_stmt|;
enum|enum
name|BinaryOperatorKind
block|{
define|#
directive|define
name|BINARY_OPERATION
parameter_list|(
name|Name
parameter_list|,
name|Spelling
parameter_list|)
value|BO_##Name,
include|#
directive|include
file|"clang/AST/OperationKinds.def"
block|}
enum|;
enum|enum
name|UnaryOperatorKind
block|{
define|#
directive|define
name|UNARY_OPERATION
parameter_list|(
name|Name
parameter_list|,
name|Spelling
parameter_list|)
value|UO_##Name,
include|#
directive|include
file|"clang/AST/OperationKinds.def"
block|}
enum|;
comment|/// \brief The kind of bridging performed by the Objective-C bridge cast.
enum|enum
name|ObjCBridgeCastKind
block|{
comment|/// \brief Bridging via __bridge, which does nothing but reinterpret
comment|/// the bits.
name|OBC_Bridge
block|,
comment|/// \brief Bridging via __bridge_transfer, which transfers ownership of an
comment|/// Objective-C pointer into ARC.
name|OBC_BridgeTransfer
block|,
comment|/// \brief Bridging via __bridge_retain, which makes an ARC object available
comment|/// as a +1 C pointer.
name|OBC_BridgeRetained
block|}
enum|;
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

