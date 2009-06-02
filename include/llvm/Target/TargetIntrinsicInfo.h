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
specifier|const
name|char
modifier|*
modifier|*
name|Intrinsics
decl_stmt|;
comment|// Raw array to allow static init'n
name|unsigned
name|NumIntrinsics
decl_stmt|;
comment|// Number of entries in the desc array
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
argument_list|(
argument|const char **desc
argument_list|,
argument|unsigned num
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|TargetIntrinsicInfo
argument_list|()
expr_stmt|;
name|unsigned
name|getNumIntrinsics
argument_list|()
specifier|const
block|{
return|return
name|NumIntrinsics
return|;
block|}
name|virtual
name|Function
modifier|*
name|getDeclaration
argument_list|(
name|Module
operator|*
name|M
argument_list|,
specifier|const
name|char
operator|*
name|BuiltinName
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
comment|// Returns the Function declaration for intrinsic BuiltinName.  If the
comment|// intrinsic can be overloaded, uses Tys to return the correct function.
name|virtual
name|Function
modifier|*
name|getDeclaration
argument_list|(
name|Module
operator|*
name|M
argument_list|,
specifier|const
name|char
operator|*
name|BuiltinName
argument_list|,
specifier|const
name|Type
operator|*
operator|*
name|Tys
argument_list|,
name|unsigned
name|numTys
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
comment|// Returns true if the Builtin can be overloaded.
name|virtual
name|bool
name|isOverloaded
argument_list|(
name|Module
operator|*
name|M
argument_list|,
specifier|const
name|char
operator|*
name|BuiltinName
argument_list|)
decl|const
block|{
return|return
name|false
return|;
block|}
name|virtual
name|unsigned
name|getIntrinsicID
argument_list|(
name|Function
operator|*
name|F
argument_list|)
decl|const
block|{
return|return
literal|0
return|;
block|}
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

