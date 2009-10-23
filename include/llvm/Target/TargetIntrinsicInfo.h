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
name|virtual
specifier|const
name|char
modifier|*
name|getName
argument_list|(
name|unsigned
name|IntrID
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
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

