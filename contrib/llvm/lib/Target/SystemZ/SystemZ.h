begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- SystemZ.h - Top-Level Interface for SystemZ representation -*- C++ -*-==//
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
comment|// This file contains the entry points for global functions defined in
end_comment

begin_comment
comment|// the LLVM SystemZ backend.
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
name|SYSTEMZ_H
end_ifndef

begin_define
define|#
directive|define
name|SYSTEMZ_H
end_define

begin_include
include|#
directive|include
file|"MCTargetDesc/SystemZMCTargetDesc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CodeGen.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|SystemZTargetMachine
decl_stmt|;
name|class
name|FunctionPass
decl_stmt|;
name|namespace
name|SystemZ
block|{
comment|// Condition-code mask values.
specifier|const
name|unsigned
name|CCMASK_0
init|=
literal|1
operator|<<
literal|3
decl_stmt|;
specifier|const
name|unsigned
name|CCMASK_1
init|=
literal|1
operator|<<
literal|2
decl_stmt|;
specifier|const
name|unsigned
name|CCMASK_2
init|=
literal|1
operator|<<
literal|1
decl_stmt|;
specifier|const
name|unsigned
name|CCMASK_3
init|=
literal|1
operator|<<
literal|0
decl_stmt|;
specifier|const
name|unsigned
name|CCMASK_ANY
init|=
name|CCMASK_0
operator||
name|CCMASK_1
operator||
name|CCMASK_2
operator||
name|CCMASK_3
decl_stmt|;
comment|// Condition-code mask assignments for floating-point comparisons.
specifier|const
name|unsigned
name|CCMASK_CMP_EQ
init|=
name|CCMASK_0
decl_stmt|;
specifier|const
name|unsigned
name|CCMASK_CMP_LT
init|=
name|CCMASK_1
decl_stmt|;
specifier|const
name|unsigned
name|CCMASK_CMP_GT
init|=
name|CCMASK_2
decl_stmt|;
specifier|const
name|unsigned
name|CCMASK_CMP_UO
init|=
name|CCMASK_3
decl_stmt|;
specifier|const
name|unsigned
name|CCMASK_CMP_NE
init|=
name|CCMASK_CMP_LT
operator||
name|CCMASK_CMP_GT
decl_stmt|;
specifier|const
name|unsigned
name|CCMASK_CMP_LE
init|=
name|CCMASK_CMP_EQ
operator||
name|CCMASK_CMP_LT
decl_stmt|;
specifier|const
name|unsigned
name|CCMASK_CMP_GE
init|=
name|CCMASK_CMP_EQ
operator||
name|CCMASK_CMP_GT
decl_stmt|;
specifier|const
name|unsigned
name|CCMASK_CMP_O
init|=
name|CCMASK_ANY
operator|^
name|CCMASK_CMP_UO
decl_stmt|;
comment|// Return true if Val fits an LLILL operand.
specifier|static
specifier|inline
name|bool
name|isImmLL
parameter_list|(
name|uint64_t
name|Val
parameter_list|)
block|{
return|return
operator|(
name|Val
operator|&
operator|~
literal|0x000000000000ffffULL
operator|)
operator|==
literal|0
return|;
block|}
comment|// Return true if Val fits an LLILH operand.
specifier|static
specifier|inline
name|bool
name|isImmLH
parameter_list|(
name|uint64_t
name|Val
parameter_list|)
block|{
return|return
operator|(
name|Val
operator|&
operator|~
literal|0x00000000ffff0000ULL
operator|)
operator|==
literal|0
return|;
block|}
comment|// Return true if Val fits an LLIHL operand.
specifier|static
specifier|inline
name|bool
name|isImmHL
parameter_list|(
name|uint64_t
name|Val
parameter_list|)
block|{
return|return
operator|(
name|Val
operator|&
operator|~
literal|0x00000ffff00000000ULL
operator|)
operator|==
literal|0
return|;
block|}
comment|// Return true if Val fits an LLIHH operand.
specifier|static
specifier|inline
name|bool
name|isImmHH
parameter_list|(
name|uint64_t
name|Val
parameter_list|)
block|{
return|return
operator|(
name|Val
operator|&
operator|~
literal|0xffff000000000000ULL
operator|)
operator|==
literal|0
return|;
block|}
comment|// Return true if Val fits an LLILF operand.
specifier|static
specifier|inline
name|bool
name|isImmLF
parameter_list|(
name|uint64_t
name|Val
parameter_list|)
block|{
return|return
operator|(
name|Val
operator|&
operator|~
literal|0x00000000ffffffffULL
operator|)
operator|==
literal|0
return|;
block|}
comment|// Return true if Val fits an LLIHF operand.
specifier|static
specifier|inline
name|bool
name|isImmHF
parameter_list|(
name|uint64_t
name|Val
parameter_list|)
block|{
return|return
operator|(
name|Val
operator|&
operator|~
literal|0xffffffff00000000ULL
operator|)
operator|==
literal|0
return|;
block|}
block|}
name|FunctionPass
modifier|*
name|createSystemZISelDag
argument_list|(
name|SystemZTargetMachine
operator|&
name|TM
argument_list|,
name|CodeGenOpt
operator|::
name|Level
name|OptLevel
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm;
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

