begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeGenRegisters.h - Register and RegisterClass Info -----*- C++ -*-===//
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
comment|// This file defines structures to encapsulate information gleaned from the
end_comment

begin_comment
comment|// target register and register class definitions.
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
name|CODEGEN_REGISTERS_H
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_REGISTERS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Record
decl_stmt|;
comment|/// CodeGenRegister - Represents a register definition.
struct|struct
name|CodeGenRegister
block|{
name|Record
modifier|*
name|TheDef
decl_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|DeclaredSpillSize
decl_stmt|,
name|DeclaredSpillAlignment
decl_stmt|;
name|CodeGenRegister
argument_list|(
name|Record
operator|*
name|R
argument_list|)
expr_stmt|;
block|}
struct|;
struct|struct
name|CodeGenRegisterClass
block|{
name|Record
modifier|*
name|TheDef
decl_stmt|;
name|std
operator|::
name|string
name|Namespace
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
name|Elements
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|>
name|VTs
expr_stmt|;
name|unsigned
name|SpillSize
decl_stmt|;
name|unsigned
name|SpillAlignment
decl_stmt|;
name|int
name|CopyCost
decl_stmt|;
comment|// Map SubRegIndex -> RegisterClass
name|DenseMap
operator|<
name|Record
operator|*
operator|,
name|Record
operator|*
operator|>
name|SubRegClasses
expr_stmt|;
name|std
operator|::
name|string
name|MethodProtos
operator|,
name|MethodBodies
expr_stmt|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getName
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|>
operator|&
name|getValueTypes
argument_list|()
specifier|const
block|{
return|return
name|VTs
return|;
block|}
name|unsigned
name|getNumValueTypes
argument_list|()
specifier|const
block|{
return|return
name|VTs
operator|.
name|size
argument_list|()
return|;
block|}
name|MVT
operator|::
name|SimpleValueType
name|getValueTypeNum
argument_list|(
argument|unsigned VTNum
argument_list|)
specifier|const
block|{
if|if
condition|(
name|VTNum
operator|<
name|VTs
operator|.
name|size
argument_list|()
condition|)
return|return
name|VTs
index|[
name|VTNum
index|]
return|;
name|assert
argument_list|(
literal|0
operator|&&
literal|"VTNum greater than number of ValueTypes in RegClass!"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
name|CodeGenRegisterClass
argument_list|(
name|Record
operator|*
name|R
argument_list|)
struct|;
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

