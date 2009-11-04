begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ARMConstantPoolValue.h - ARM constantpool value ----------*- C++ -*-===//
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
comment|// This file implements the ARM specific constantpool value class.
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
name|LLVM_TARGET_ARM_CONSTANTPOOLVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_ARM_CONSTANTPOOLVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineConstantPool.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Constant
decl_stmt|;
name|class
name|BlockAddress
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|namespace
name|ARMCP
block|{
enum|enum
name|ARMCPKind
block|{
name|CPValue
block|,
name|CPExtSymbol
block|,
name|CPBlockAddress
block|,
name|CPLSDA
block|}
enum|;
block|}
comment|/// ARMConstantPoolValue - ARM specific constantpool value. This is used to
comment|/// represent PC-relative displacement between the address of the load
comment|/// instruction and the constant being loaded, i.e. (&GV-(LPIC+8)).
name|class
name|ARMConstantPoolValue
range|:
name|public
name|MachineConstantPoolValue
block|{
name|Constant
operator|*
name|CVal
block|;
comment|// Constant being loaded.
specifier|const
name|char
operator|*
name|S
block|;
comment|// ExtSymbol being loaded.
name|unsigned
name|LabelId
block|;
comment|// Label id of the load.
name|ARMCP
operator|::
name|ARMCPKind
name|Kind
block|;
comment|// Kind of constant.
name|unsigned
name|char
name|PCAdjust
block|;
comment|// Extra adjustment if constantpool is pc-relative.
comment|// 8 for ARM, 4 for Thumb.
specifier|const
name|char
operator|*
name|Modifier
block|;
comment|// GV modifier i.e. (&GV(modifier)-(LPIC+8))
name|bool
name|AddCurrentAddress
block|;
name|public
operator|:
name|ARMConstantPoolValue
argument_list|(
argument|Constant *cval
argument_list|,
argument|unsigned id
argument_list|,
argument|ARMCP::ARMCPKind Kind = ARMCP::CPValue
argument_list|,
argument|unsigned char PCAdj =
literal|0
argument_list|,
argument|const char *Modifier = NULL
argument_list|,
argument|bool AddCurrentAddress = false
argument_list|)
block|;
name|ARMConstantPoolValue
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|const char *s
argument_list|,
argument|unsigned id
argument_list|,
argument|unsigned char PCAdj =
literal|0
argument_list|,
argument|const char *Modifier = NULL
argument_list|,
argument|bool AddCurrentAddress = false
argument_list|)
block|;
name|ARMConstantPoolValue
argument_list|(
name|GlobalValue
operator|*
name|GV
argument_list|,
specifier|const
name|char
operator|*
name|Modifier
argument_list|)
block|;
name|ARMConstantPoolValue
argument_list|()
block|;
operator|~
name|ARMConstantPoolValue
argument_list|()
block|;
name|GlobalValue
operator|*
name|getGV
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
name|S
return|;
block|}
name|BlockAddress
operator|*
name|getBlockAddress
argument_list|()
specifier|const
block|;
specifier|const
name|char
operator|*
name|getModifier
argument_list|()
specifier|const
block|{
return|return
name|Modifier
return|;
block|}
name|bool
name|hasModifier
argument_list|()
specifier|const
block|{
return|return
name|Modifier
operator|!=
name|NULL
return|;
block|}
name|bool
name|mustAddCurrentAddress
argument_list|()
specifier|const
block|{
return|return
name|AddCurrentAddress
return|;
block|}
name|unsigned
name|getLabelId
argument_list|()
specifier|const
block|{
return|return
name|LabelId
return|;
block|}
name|unsigned
name|char
name|getPCAdjustment
argument_list|()
specifier|const
block|{
return|return
name|PCAdjust
return|;
block|}
name|bool
name|isGlobalValue
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|ARMCP
operator|::
name|CPValue
return|;
block|}
name|bool
name|isExtSymbol
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|ARMCP
operator|::
name|CPExtSymbol
return|;
block|}
name|bool
name|isBlockAddress
argument_list|()
block|{
return|return
name|Kind
operator|==
name|ARMCP
operator|::
name|CPBlockAddress
return|;
block|}
name|bool
name|isLSDA
argument_list|()
block|{
return|return
name|Kind
operator|==
name|ARMCP
operator|::
name|CPLSDA
return|;
block|}
name|virtual
name|unsigned
name|getRelocationInfo
argument_list|()
specifier|const
block|{
comment|// FIXME: This is conservatively claiming that these entries require a
comment|// relocation, we may be able to do better than this.
return|return
literal|2
return|;
block|}
name|virtual
name|int
name|getExistingMachineCPValue
argument_list|(
argument|MachineConstantPool *CP
argument_list|,
argument|unsigned Alignment
argument_list|)
block|;
name|virtual
name|void
name|AddSelectionDAGCSEId
argument_list|(
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
block|;
name|void
name|print
argument_list|(
argument|raw_ostream *O
argument_list|)
specifier|const
block|{
if|if
condition|(
name|O
condition|)
name|print
argument_list|(
operator|*
name|O
argument_list|)
expr_stmt|;
block|}
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
block|;
name|void
name|dump
argument_list|()
specifier|const
block|; }
decl_stmt|;
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|O
operator|,
specifier|const
name|ARMConstantPoolValue
operator|&
name|V
operator|)
block|{
name|V
operator|.
name|print
argument_list|(
name|O
argument_list|)
block|;
return|return
name|O
return|;
block|}
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

