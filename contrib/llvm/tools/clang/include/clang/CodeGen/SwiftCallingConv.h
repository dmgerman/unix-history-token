begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- SwiftCallingConv.h - Swift ABI lowering -----------------------------==//
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
comment|// Defines constants and types related to Swift ABI lowering.
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
name|LLVM_CLANG_CODEGEN_SWIFTCALLINGCONV_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_CODEGEN_SWIFTCALLINGCONV_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/CanonicalType.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/CharUnits.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/TrailingObjects.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|IntegerType
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|StructType
decl_stmt|;
name|class
name|VectorType
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Decl
decl_stmt|;
name|class
name|FieldDecl
decl_stmt|;
name|class
name|ASTRecordLayout
decl_stmt|;
name|namespace
name|CodeGen
block|{
name|class
name|ABIArgInfo
decl_stmt|;
name|class
name|CodeGenModule
decl_stmt|;
name|class
name|CGFunctionInfo
decl_stmt|;
name|namespace
name|swiftcall
block|{
name|class
name|SwiftAggLowering
block|{
name|CodeGenModule
modifier|&
name|CGM
decl_stmt|;
struct|struct
name|StorageEntry
block|{
name|CharUnits
name|Begin
decl_stmt|;
name|CharUnits
name|End
decl_stmt|;
name|llvm
operator|::
name|Type
operator|*
name|Type
expr_stmt|;
name|CharUnits
name|getWidth
argument_list|()
specifier|const
block|{
return|return
name|End
operator|-
name|Begin
return|;
block|}
block|}
struct|;
name|SmallVector
operator|<
name|StorageEntry
operator|,
literal|4
operator|>
name|Entries
expr_stmt|;
name|bool
name|Finished
init|=
name|false
decl_stmt|;
name|public
label|:
name|SwiftAggLowering
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|)
operator|:
name|CGM
argument_list|(
argument|CGM
argument_list|)
block|{}
name|void
name|addOpaqueData
argument_list|(
argument|CharUnits begin
argument_list|,
argument|CharUnits end
argument_list|)
block|{
name|addEntry
argument_list|(
name|nullptr
argument_list|,
name|begin
argument_list|,
name|end
argument_list|)
block|;   }
name|void
name|addTypedData
argument_list|(
argument|QualType type
argument_list|,
argument|CharUnits begin
argument_list|)
expr_stmt|;
name|void
name|addTypedData
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|record
parameter_list|,
name|CharUnits
name|begin
parameter_list|)
function_decl|;
name|void
name|addTypedData
parameter_list|(
specifier|const
name|RecordDecl
modifier|*
name|record
parameter_list|,
name|CharUnits
name|begin
parameter_list|,
specifier|const
name|ASTRecordLayout
modifier|&
name|layout
parameter_list|)
function_decl|;
name|void
name|addTypedData
argument_list|(
name|llvm
operator|::
name|Type
operator|*
name|type
argument_list|,
name|CharUnits
name|begin
argument_list|)
decl_stmt|;
name|void
name|addTypedData
argument_list|(
name|llvm
operator|::
name|Type
operator|*
name|type
argument_list|,
name|CharUnits
name|begin
argument_list|,
name|CharUnits
name|end
argument_list|)
decl_stmt|;
name|void
name|finish
parameter_list|()
function_decl|;
comment|/// Does this lowering require passing any data?
name|bool
name|empty
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Finished
operator|&&
literal|"didn't finish lowering before calling empty()"
argument_list|)
block|;
return|return
name|Entries
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// According to the target Swift ABI, should a value with this lowering
comment|/// be passed indirectly?
comment|///
comment|/// Note that this decision is based purely on the data layout of the
comment|/// value and does not consider whether the type is address-only,
comment|/// must be passed indirectly to match a function abstraction pattern, or
comment|/// anything else that is expected to be handled by high-level lowering.
comment|///
comment|/// \param asReturnValue - if true, answer whether it should be passed
comment|///   indirectly as a return value; if false, answer whether it should be
comment|///   passed indirectly as an argument
name|bool
name|shouldPassIndirectly
argument_list|(
name|bool
name|asReturnValue
argument_list|)
decl|const
decl_stmt|;
name|using
name|EnumerationCallback
init|=
name|llvm
operator|::
name|function_ref
operator|<
name|void
argument_list|(
argument|CharUnits offset
argument_list|,
argument|CharUnits end
argument_list|,
argument|llvm::Type *type
argument_list|)
operator|>
decl_stmt|;
comment|/// Enumerate the expanded components of this type.
comment|///
comment|/// The component types will always be legal vector, floating-point,
comment|/// integer, or pointer types.
name|void
name|enumerateComponents
argument_list|(
name|EnumerationCallback
name|callback
argument_list|)
decl|const
decl_stmt|;
comment|/// Return the types for a coerce-and-expand operation.
comment|///
comment|/// The first type matches the memory layout of the data that's been
comment|/// added to this structure, including explicit [N x i8] arrays for any
comment|/// internal padding.
comment|///
comment|/// The second type removes any internal padding members and, if only
comment|/// one element remains, is simply that element type.
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|StructType
operator|*
operator|,
name|llvm
operator|::
name|Type
operator|*
operator|>
name|getCoerceAndExpandTypes
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|addBitFieldData
parameter_list|(
specifier|const
name|FieldDecl
modifier|*
name|field
parameter_list|,
name|CharUnits
name|begin
parameter_list|,
name|uint64_t
name|bitOffset
parameter_list|)
function_decl|;
name|void
name|addLegalTypedData
argument_list|(
name|llvm
operator|::
name|Type
operator|*
name|type
argument_list|,
name|CharUnits
name|begin
argument_list|,
name|CharUnits
name|end
argument_list|)
decl_stmt|;
name|void
name|addEntry
argument_list|(
name|llvm
operator|::
name|Type
operator|*
name|type
argument_list|,
name|CharUnits
name|begin
argument_list|,
name|CharUnits
name|end
argument_list|)
decl_stmt|;
name|void
name|splitVectorEntry
parameter_list|(
name|unsigned
name|index
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// Return the maximum voluntary integer size for the current target.
name|CharUnits
name|getMaximumVoluntaryIntegerSize
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|)
function_decl|;
comment|/// Return the Swift CC's notion of the natural alignment of a type.
name|CharUnits
name|getNaturalAlignment
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
name|llvm
operator|::
name|Type
operator|*
name|type
argument_list|)
decl_stmt|;
comment|/// Is the given integer type "legal" for Swift's perspective on the
comment|/// current platform?
name|bool
name|isLegalIntegerType
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
name|llvm
operator|::
name|IntegerType
operator|*
name|type
argument_list|)
decl_stmt|;
comment|/// Is the given vector type "legal" for Swift's perspective on the
comment|/// current platform?
name|bool
name|isLegalVectorType
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
name|CharUnits
name|vectorSize
argument_list|,
name|llvm
operator|::
name|VectorType
operator|*
name|vectorTy
argument_list|)
decl_stmt|;
name|bool
name|isLegalVectorType
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
name|CharUnits
name|vectorSize
argument_list|,
name|llvm
operator|::
name|Type
operator|*
name|eltTy
argument_list|,
name|unsigned
name|numElts
argument_list|)
decl_stmt|;
comment|/// Minimally split a legal vector type.
name|std
operator|::
name|pair
operator|<
name|llvm
operator|::
name|Type
operator|*
operator|,
name|unsigned
operator|>
name|splitLegalVectorType
argument_list|(
argument|CodeGenModule&CGM
argument_list|,
argument|CharUnits vectorSize
argument_list|,
argument|llvm::VectorType *vectorTy
argument_list|)
expr_stmt|;
comment|/// Turn a vector type in a sequence of legal component vector types.
comment|///
comment|/// The caller may assume that the sum of the data sizes of the resulting
comment|/// types will equal the data size of the vector type.
name|void
name|legalizeVectorType
argument_list|(
name|CodeGenModule
operator|&
name|CGM
argument_list|,
name|CharUnits
name|vectorSize
argument_list|,
name|llvm
operator|::
name|VectorType
operator|*
name|vectorTy
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|llvm
operator|::
name|Type
operator|*
operator|>
operator|&
name|types
argument_list|)
decl_stmt|;
comment|/// Should a C++ record type be passed and returned indirectly?
name|bool
name|shouldPassCXXRecordIndirectly
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|,
specifier|const
name|CXXRecordDecl
modifier|*
name|record
parameter_list|)
function_decl|;
comment|/// Classify the rules for how to return a particular type.
name|ABIArgInfo
name|classifyReturnType
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|,
name|CanQualType
name|type
parameter_list|)
function_decl|;
comment|/// Classify the rules for how to pass a particular type.
name|ABIArgInfo
name|classifyArgumentType
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|,
name|CanQualType
name|type
parameter_list|)
function_decl|;
comment|/// Compute the ABI information of a swiftcall function.  This is a
comment|/// private interface for Clang.
name|void
name|computeABIInfo
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|,
name|CGFunctionInfo
modifier|&
name|FI
parameter_list|)
function_decl|;
comment|/// Is swifterror lowered to a register by the target ABI.
name|bool
name|isSwiftErrorLoweredInRegister
parameter_list|(
name|CodeGenModule
modifier|&
name|CGM
parameter_list|)
function_decl|;
block|}
comment|// end namespace swiftcall
block|}
comment|// end namespace CodeGen
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

