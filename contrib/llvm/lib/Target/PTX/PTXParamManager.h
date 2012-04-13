begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PTXParamManager.h - Manager for .param variables ----------*- C++ -*-==//
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
comment|// This file defines the PTXParamManager class, which manages all defined .param
end_comment

begin_comment
comment|// variables for a particular function.
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
name|PTX_PARAM_MANAGER_H
end_ifndef

begin_define
define|#
directive|define
name|PTX_PARAM_MANAGER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// PTXParamManager - This class manages all .param variables defined for a
comment|/// particular function.
name|class
name|PTXParamManager
block|{
name|private
label|:
comment|/// PTXParamType - Type of a .param variable
enum|enum
name|PTXParamType
block|{
name|PTX_PARAM_TYPE_ARGUMENT
block|,
name|PTX_PARAM_TYPE_RETURN
block|,
name|PTX_PARAM_TYPE_LOCAL
block|}
enum|;
comment|/// PTXParam - Definition of a PTX .param variable
struct|struct
name|PTXParam
block|{
name|PTXParamType
name|Type
decl_stmt|;
name|unsigned
name|Size
decl_stmt|;
name|std
operator|::
name|string
name|Name
expr_stmt|;
block|}
struct|;
name|DenseMap
operator|<
name|unsigned
operator|,
name|PTXParam
operator|>
name|AllParams
expr_stmt|;
name|SmallVector
operator|<
name|unsigned
operator|,
literal|4
operator|>
name|ArgumentParams
expr_stmt|;
name|SmallVector
operator|<
name|unsigned
operator|,
literal|4
operator|>
name|ReturnParams
expr_stmt|;
name|SmallVector
operator|<
name|unsigned
operator|,
literal|4
operator|>
name|LocalParams
expr_stmt|;
name|public
label|:
typedef|typedef
name|SmallVector
operator|<
name|unsigned
operator|,
literal|4
operator|>
operator|::
name|const_iterator
name|param_iterator
expr_stmt|;
name|PTXParamManager
argument_list|()
expr_stmt|;
name|param_iterator
name|arg_begin
argument_list|()
specifier|const
block|{
return|return
name|ArgumentParams
operator|.
name|begin
argument_list|()
return|;
block|}
name|param_iterator
name|arg_end
argument_list|()
specifier|const
block|{
return|return
name|ArgumentParams
operator|.
name|end
argument_list|()
return|;
block|}
name|param_iterator
name|ret_begin
argument_list|()
specifier|const
block|{
return|return
name|ReturnParams
operator|.
name|begin
argument_list|()
return|;
block|}
name|param_iterator
name|ret_end
argument_list|()
specifier|const
block|{
return|return
name|ReturnParams
operator|.
name|end
argument_list|()
return|;
block|}
name|param_iterator
name|local_begin
argument_list|()
specifier|const
block|{
return|return
name|LocalParams
operator|.
name|begin
argument_list|()
return|;
block|}
name|param_iterator
name|local_end
argument_list|()
specifier|const
block|{
return|return
name|LocalParams
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// addArgumentParam - Returns a new .param used as an argument.
name|unsigned
name|addArgumentParam
parameter_list|(
name|unsigned
name|Size
parameter_list|)
function_decl|;
comment|/// addReturnParam - Returns a new .param used as a return argument.
name|unsigned
name|addReturnParam
parameter_list|(
name|unsigned
name|Size
parameter_list|)
function_decl|;
comment|/// addLocalParam - Returns a new .param used as a local .param variable.
name|unsigned
name|addLocalParam
parameter_list|(
name|unsigned
name|Size
parameter_list|)
function_decl|;
comment|/// getParamName - Returns the name of the parameter as a string.
specifier|const
name|std
operator|::
name|string
operator|&
name|getParamName
argument_list|(
argument|unsigned Param
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|AllParams
operator|.
name|count
argument_list|(
name|Param
argument_list|)
operator|==
literal|1
operator|&&
literal|"Param has not been defined!"
argument_list|)
block|;
return|return
name|AllParams
operator|.
name|find
argument_list|(
name|Param
argument_list|)
operator|->
name|second
operator|.
name|Name
return|;
block|}
comment|/// getParamSize - Returns the size of the parameter in bits.
name|unsigned
name|getParamSize
argument_list|(
name|unsigned
name|Param
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|AllParams
operator|.
name|count
argument_list|(
name|Param
argument_list|)
operator|==
literal|1
operator|&&
literal|"Param has not been defined!"
argument_list|)
expr_stmt|;
return|return
name|AllParams
operator|.
name|find
argument_list|(
name|Param
argument_list|)
operator|->
name|second
operator|.
name|Size
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

