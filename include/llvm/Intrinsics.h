begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Instrinsics.h - LLVM Intrinsic Function Handling ---*- C++ -*-===//
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
comment|// This file defines a set of enums which allow processing of intrinsic
end_comment

begin_comment
comment|// functions.  Values of these enum types are returned by
end_comment

begin_comment
comment|// Function::getIntrinsicID.
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
name|LLVM_INTRINSICS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INTRINSICS_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Type
decl_stmt|;
name|class
name|FunctionType
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|AttrListPtr
decl_stmt|;
comment|/// Intrinsic Namespace - This namespace contains an enum with a value for
comment|/// every intrinsic/builtin function known by LLVM.  These enum values are
comment|/// returned by Function::getIntrinsicID().
comment|///
name|namespace
name|Intrinsic
block|{
enum|enum
name|ID
block|{
name|not_intrinsic
init|=
literal|0
block|,
comment|// Must be zero
comment|// Get the intrinsic enums generated from Intrinsics.td
define|#
directive|define
name|GET_INTRINSIC_ENUM_VALUES
include|#
directive|include
file|"llvm/Intrinsics.gen"
undef|#
directive|undef
name|GET_INTRINSIC_ENUM_VALUES
block|,
name|num_intrinsics
block|}
enum|;
comment|/// Intrinsic::getName(ID) - Return the LLVM name for an intrinsic, such as
comment|/// "llvm.ppc.altivec.lvx".
name|std
operator|::
name|string
name|getName
argument_list|(
argument|ID id
argument_list|,
argument|const Type **Tys =
literal|0
argument_list|,
argument|unsigned numTys =
literal|0
argument_list|)
expr_stmt|;
comment|/// Intrinsic::getType(ID) - Return the function type for an intrinsic.
comment|///
specifier|const
name|FunctionType
modifier|*
name|getType
parameter_list|(
name|LLVMContext
modifier|&
name|Context
parameter_list|,
name|ID
name|id
parameter_list|,
specifier|const
name|Type
modifier|*
modifier|*
name|Tys
init|=
literal|0
parameter_list|,
name|unsigned
name|numTys
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Intrinsic::isOverloaded(ID) - Returns true if the intrinsic can be
comment|/// overloaded.
name|bool
name|isOverloaded
parameter_list|(
name|ID
name|id
parameter_list|)
function_decl|;
comment|/// Intrinsic::getAttributes(ID) - Return the attributes for an intrinsic.
comment|///
name|AttrListPtr
name|getAttributes
parameter_list|(
name|ID
name|id
parameter_list|)
function_decl|;
comment|/// Intrinsic::getDeclaration(M, ID) - Create or insert an LLVM Function
comment|/// declaration for an intrinsic, and return it.
comment|///
comment|/// The Tys and numTys parameters are for intrinsics with overloaded types
comment|/// (e.g., those using iAny or fAny). For a declaration for an overloaded
comment|/// intrinsic, Tys should point to an array of numTys pointers to Type,
comment|/// and must provide exactly one type for each overloaded type in the
comment|/// intrinsic.
name|Function
modifier|*
name|getDeclaration
parameter_list|(
name|Module
modifier|*
name|M
parameter_list|,
name|ID
name|id
parameter_list|,
specifier|const
name|Type
modifier|*
modifier|*
name|Tys
init|=
literal|0
parameter_list|,
name|unsigned
name|numTys
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Map a GCC builtin name to an intrinsic ID.
name|ID
name|getIntrinsicForGCCBuiltin
parameter_list|(
specifier|const
name|char
modifier|*
name|Prefix
parameter_list|,
specifier|const
name|char
modifier|*
name|BuiltinName
parameter_list|)
function_decl|;
block|}
comment|// End Intrinsic namespace
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

