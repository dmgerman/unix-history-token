begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- GenericValue.h - Represent any type of LLVM value --------*- C++ -*-===//
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
comment|// The GenericValue class is used to represent an LLVM value of arbitrary type.
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
name|LLVM_EXECUTIONENGINE_GENERICVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_GENERICVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|using
name|PointerTy
init|=
name|void
operator|*
decl_stmt|;
struct|struct
name|GenericValue
block|{
struct|struct
name|IntPair
block|{
name|unsigned
name|int
name|first
decl_stmt|;
name|unsigned
name|int
name|second
decl_stmt|;
block|}
struct|;
union|union
block|{
name|double
name|DoubleVal
decl_stmt|;
name|float
name|FloatVal
decl_stmt|;
name|PointerTy
name|PointerVal
decl_stmt|;
name|struct
name|IntPair
name|UIntPairVal
decl_stmt|;
name|unsigned
name|char
name|Untyped
index|[
literal|8
index|]
decl_stmt|;
block|}
union|;
name|APInt
name|IntVal
decl_stmt|;
comment|// also used for long doubles.
comment|// For aggregate data types.
name|std
operator|::
name|vector
operator|<
name|GenericValue
operator|>
name|AggregateVal
expr_stmt|;
comment|// to make code faster, set GenericValue to zero could be omitted, but it is
comment|// potentially can cause problems, since GenericValue to store garbage
comment|// instead of zero.
name|GenericValue
argument_list|()
operator|:
name|IntVal
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
block|{
name|UIntPairVal
operator|.
name|first
operator|=
literal|0
block|;
name|UIntPairVal
operator|.
name|second
operator|=
literal|0
block|;   }
name|explicit
name|GenericValue
argument_list|(
name|void
operator|*
name|V
argument_list|)
operator|:
name|PointerVal
argument_list|(
name|V
argument_list|)
operator|,
name|IntVal
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
block|{}
block|}
struct|;
specifier|inline
name|GenericValue
name|PTOGV
parameter_list|(
name|void
modifier|*
name|P
parameter_list|)
block|{
return|return
name|GenericValue
argument_list|(
name|P
argument_list|)
return|;
block|}
specifier|inline
name|void
modifier|*
name|GVTOP
parameter_list|(
specifier|const
name|GenericValue
modifier|&
name|GV
parameter_list|)
block|{
return|return
name|GV
operator|.
name|PointerVal
return|;
block|}
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
comment|// LLVM_EXECUTIONENGINE_GENERICVALUE_H
end_comment

end_unit

