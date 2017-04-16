begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- VNCoercion.h - Value Numbering Coercion Utilities --------*- C++ -*-===//
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
comment|/// \file / This file provides routines used by LLVM's value numbering passes to
end_comment

begin_comment
comment|/// perform various forms of value extraction from memory when the types are not
end_comment

begin_comment
comment|/// identical.  For example, given
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// store i32 8, i32 *%foo
end_comment

begin_comment
comment|/// %a = bitcast i32 *%foo to i16
end_comment

begin_comment
comment|/// %val = load i16, i16 *%a
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// It possible to extract the value of the load of %a from the store to %foo.
end_comment

begin_comment
comment|/// These routines know how to tell whether they can do that (the analyze*
end_comment

begin_comment
comment|/// routines), and can also insert the necessary IR to do it (the get*
end_comment

begin_comment
comment|/// routines).
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_TRANSFORMS_UTILS_VNCOERCION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_VNCOERCION_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/IRBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Function
decl_stmt|;
name|class
name|StoreInst
decl_stmt|;
name|class
name|LoadInst
decl_stmt|;
name|class
name|MemIntrinsic
decl_stmt|;
name|class
name|Instruction
decl_stmt|;
name|class
name|Value
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|DataLayout
decl_stmt|;
name|namespace
name|VNCoercion
block|{
comment|/// Return true if CoerceAvailableValueToLoadType would succeed if it was
comment|/// called.
name|bool
name|canCoerceMustAliasedValueToLoad
parameter_list|(
name|Value
modifier|*
name|StoredVal
parameter_list|,
name|Type
modifier|*
name|LoadTy
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
comment|/// If we saw a store of a value to memory, and then a load from a must-aliased
comment|/// pointer of a different type, try to coerce the stored value to the loaded
comment|/// type.  LoadedTy is the type of the load we want to replace.  IRB is
comment|/// IRBuilder used to insert new instructions.
comment|///
comment|/// If we can't do it, return null.
name|Value
modifier|*
name|coerceAvailableValueToLoadType
argument_list|(
name|Value
operator|*
name|StoredVal
argument_list|,
name|Type
operator|*
name|LoadedTy
argument_list|,
name|IRBuilder
operator|<
operator|>
operator|&
name|IRB
argument_list|,
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|)
decl_stmt|;
comment|/// This function determines whether a value for the pointer LoadPtr can be
comment|/// extracted from the store at DepSI.
comment|///
comment|/// On success, it returns the offset into DepSI that extraction would start.
comment|/// On failure, it returns -1.
name|int
name|analyzeLoadFromClobberingStore
parameter_list|(
name|Type
modifier|*
name|LoadTy
parameter_list|,
name|Value
modifier|*
name|LoadPtr
parameter_list|,
name|StoreInst
modifier|*
name|DepSI
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
comment|/// This function determines whether a value for the pointer LoadPtr can be
comment|/// extracted from the load at DepLI.
comment|///
comment|/// On success, it returns the offset into DepLI that extraction would start.
comment|/// On failure, it returns -1.
name|int
name|analyzeLoadFromClobberingLoad
parameter_list|(
name|Type
modifier|*
name|LoadTy
parameter_list|,
name|Value
modifier|*
name|LoadPtr
parameter_list|,
name|LoadInst
modifier|*
name|DepLI
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
comment|/// This function determines whether a value for the pointer LoadPtr can be
comment|/// extracted from the memory intrinsic at DepMI.
comment|///
comment|/// On success, it returns the offset into DepMI that extraction would start.
comment|/// On failure, it returns -1.
name|int
name|analyzeLoadFromClobberingMemInst
parameter_list|(
name|Type
modifier|*
name|LoadTy
parameter_list|,
name|Value
modifier|*
name|LoadPtr
parameter_list|,
name|MemIntrinsic
modifier|*
name|DepMI
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
comment|/// If analyzeLoadFromClobberingStore returned an offset, this function can be
comment|/// used to actually perform the extraction of the bits from the store. It
comment|/// inserts instructions to do so at InsertPt, and returns the extracted value.
name|Value
modifier|*
name|getStoreValueForLoad
parameter_list|(
name|Value
modifier|*
name|SrcVal
parameter_list|,
name|unsigned
name|Offset
parameter_list|,
name|Type
modifier|*
name|LoadTy
parameter_list|,
name|Instruction
modifier|*
name|InsertPt
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
comment|// This is the same as getStoreValueForLoad, except it performs no insertion
comment|// It only allows constant inputs.
name|Constant
modifier|*
name|getConstantStoreValueForLoad
parameter_list|(
name|Constant
modifier|*
name|SrcVal
parameter_list|,
name|unsigned
name|Offset
parameter_list|,
name|Type
modifier|*
name|LoadTy
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
comment|/// If analyzeLoadFromClobberingLoad returned an offset, this function can be
comment|/// used to actually perform the extraction of the bits from the load, including
comment|/// any necessary load widening.  It inserts instructions to do so at InsertPt,
comment|/// and returns the extracted value.
name|Value
modifier|*
name|getLoadValueForLoad
parameter_list|(
name|LoadInst
modifier|*
name|SrcVal
parameter_list|,
name|unsigned
name|Offset
parameter_list|,
name|Type
modifier|*
name|LoadTy
parameter_list|,
name|Instruction
modifier|*
name|InsertPt
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
comment|// This is the same as getLoadValueForLoad, except it is given the load value as
comment|// a constant. It returns nullptr if it would require widening the load.
name|Constant
modifier|*
name|getConstantLoadValueForLoad
parameter_list|(
name|Constant
modifier|*
name|SrcVal
parameter_list|,
name|unsigned
name|Offset
parameter_list|,
name|Type
modifier|*
name|LoadTy
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
comment|/// If analyzeLoadFromClobberingMemInst returned an offset, this function can be
comment|/// used to actually perform the extraction of the bits from the memory
comment|/// intrinsic.  It inserts instructions to do so at InsertPt, and returns the
comment|/// extracted value.
name|Value
modifier|*
name|getMemInstValueForLoad
parameter_list|(
name|MemIntrinsic
modifier|*
name|SrcInst
parameter_list|,
name|unsigned
name|Offset
parameter_list|,
name|Type
modifier|*
name|LoadTy
parameter_list|,
name|Instruction
modifier|*
name|InsertPt
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
comment|// This is the same as getStoreValueForLoad, except it performs no insertion.
comment|// It returns nullptr if it cannot produce a constant.
name|Constant
modifier|*
name|getConstantMemInstValueForLoad
parameter_list|(
name|MemIntrinsic
modifier|*
name|SrcInst
parameter_list|,
name|unsigned
name|Offset
parameter_list|,
name|Type
modifier|*
name|LoadTy
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

