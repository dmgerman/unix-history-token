begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetIntrinsicInfo.h - Instruction Info ----*- C++ -*-===//
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
comment|// This file describes the target intrinsic instructions to the code generator.
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
name|LLVM_TARGET_TARGETINTRINSICINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETINTRINSICINFO_H
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
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|Type
decl_stmt|;
comment|//---------------------------------------------------------------------------
comment|///
comment|/// TargetIntrinsicInfo - Interface to description of machine instruction set
comment|///
name|class
name|TargetIntrinsicInfo
block|{
name|TargetIntrinsicInfo
argument_list|(
specifier|const
name|TargetIntrinsicInfo
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetIntrinsicInfo
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|public
label|:
name|TargetIntrinsicInfo
argument_list|()
expr_stmt|;
name|virtual
operator|~
name|TargetIntrinsicInfo
argument_list|()
expr_stmt|;
comment|/// Return the name of a target intrinsic, e.g. "llvm.bfin.ssync".
comment|/// The Tys and numTys parameters are for intrinsics with overloaded types
comment|/// (e.g., those using iAny or fAny). For a declaration for an overloaded
comment|/// intrinsic, Tys should point to an array of numTys pointers to Type,
comment|/// and must provide exactly one type for each overloaded type in the
comment|/// intrinsic.
name|virtual
name|std
operator|::
name|string
name|getName
argument_list|(
argument|unsigned IID
argument_list|,
argument|const Type **Tys =
literal|0
argument_list|,
argument|unsigned numTys =
literal|0
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// Look up target intrinsic by name. Return intrinsic ID or 0 for unknown
comment|/// names.
name|virtual
name|unsigned
name|lookupName
argument_list|(
specifier|const
name|char
operator|*
name|Name
argument_list|,
name|unsigned
name|Len
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Return the target intrinsic ID of a function, or 0.
name|virtual
name|unsigned
name|getIntrinsicID
argument_list|(
name|Function
operator|*
name|F
argument_list|)
decl|const
decl_stmt|;
comment|/// Returns true if the intrinsic can be overloaded.
name|virtual
name|bool
name|isOverloaded
argument_list|(
name|unsigned
name|IID
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Create or insert an LLVM Function declaration for an intrinsic,
comment|/// and return it. The Tys and numTys are for intrinsics with overloaded
comment|/// types. See above for more information.
name|virtual
name|Function
modifier|*
name|getDeclaration
argument_list|(
name|Module
operator|*
name|M
argument_list|,
name|unsigned
name|ID
argument_list|,
specifier|const
name|Type
operator|*
operator|*
name|Tys
operator|=
literal|0
argument_list|,
name|unsigned
name|numTys
operator|=
literal|0
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
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

