begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ARMConstantPoolValue.h - ARM constantpool value ---------*- C++ -*-===//
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
name|LLVM_LIB_TARGET_ARM_ARMCONSTANTPOOLVALUE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_ARM_ARMCONSTANTPOOLVALUE_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineConstantPool.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BlockAddress
decl_stmt|;
name|class
name|Constant
decl_stmt|;
name|class
name|GlobalValue
decl_stmt|;
name|class
name|GlobalVariable
decl_stmt|;
name|class
name|LLVMContext
decl_stmt|;
name|class
name|MachineBasicBlock
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
block|,
name|CPMachineBasicBlock
block|,
name|CPPromotedGlobal
block|}
enum|;
enum|enum
name|ARMCPModifier
block|{
name|no_modifier
block|,
comment|/// None
name|TLSGD
block|,
comment|/// Thread Local Storage (General Dynamic Mode)
name|GOT_PREL
block|,
comment|/// Global Offset Table, PC Relative
name|GOTTPOFF
block|,
comment|/// Global Offset Table, Thread Pointer Offset
name|TPOFF
block|,
comment|/// Thread Pointer Offset
name|SECREL
block|,
comment|/// Section Relative (Windows TLS)
name|SBREL
block|,
comment|/// Static Base Relative (RWPI)
block|}
enum|;
block|}
comment|// end namespace ARMCP
comment|/// ARMConstantPoolValue - ARM specific constantpool value. This is used to
comment|/// represent PC-relative displacement between the address of the load
comment|/// instruction and the constant being loaded, i.e. (&GV-(LPIC+8)).
name|class
name|ARMConstantPoolValue
range|:
name|public
name|MachineConstantPoolValue
block|{
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
name|ARMCP
operator|::
name|ARMCPModifier
name|Modifier
block|;
comment|// GV modifier i.e. (&GV(modifier)-(LPIC+8))
name|bool
name|AddCurrentAddress
block|;
name|protected
operator|:
name|ARMConstantPoolValue
argument_list|(
argument|Type *Ty
argument_list|,
argument|unsigned id
argument_list|,
argument|ARMCP::ARMCPKind Kind
argument_list|,
argument|unsigned char PCAdj
argument_list|,
argument|ARMCP::ARMCPModifier Modifier
argument_list|,
argument|bool AddCurrentAddress
argument_list|)
block|;
name|ARMConstantPoolValue
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|unsigned id
argument_list|,
argument|ARMCP::ARMCPKind Kind
argument_list|,
argument|unsigned char PCAdj
argument_list|,
argument|ARMCP::ARMCPModifier Modifier
argument_list|,
argument|bool AddCurrentAddress
argument_list|)
block|;
name|template
operator|<
name|typename
name|Derived
operator|>
name|int
name|getExistingMachineCPValueImpl
argument_list|(
argument|MachineConstantPool *CP
argument_list|,
argument|unsigned Alignment
argument_list|)
block|{
name|unsigned
name|AlignMask
operator|=
name|Alignment
operator|-
literal|1
block|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|MachineConstantPoolEntry
operator|>
operator|&
name|Constants
operator|=
name|CP
operator|->
name|getConstants
argument_list|()
block|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|Constants
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|Constants
index|[
name|i
index|]
operator|.
name|isMachineConstantPoolEntry
argument_list|()
operator|&&
operator|(
name|Constants
index|[
name|i
index|]
operator|.
name|getAlignment
argument_list|()
operator|&
name|AlignMask
operator|)
operator|==
literal|0
condition|)
block|{
name|ARMConstantPoolValue
modifier|*
name|CPV
init|=
operator|(
name|ARMConstantPoolValue
operator|*
operator|)
name|Constants
index|[
name|i
index|]
operator|.
name|Val
operator|.
name|MachineCPVal
decl_stmt|;
if|if
condition|(
name|Derived
modifier|*
name|APC
init|=
name|dyn_cast
operator|<
name|Derived
operator|>
operator|(
name|CPV
operator|)
condition|)
if|if
condition|(
name|cast
operator|<
name|Derived
operator|>
operator|(
name|this
operator|)
operator|->
name|equals
argument_list|(
name|APC
argument_list|)
condition|)
return|return
name|i
return|;
block|}
block|}
return|return
operator|-
literal|1
return|;
block|}
name|public
operator|:
operator|~
name|ARMConstantPoolValue
argument_list|()
name|override
block|;
name|ARMCP
operator|::
name|ARMCPModifier
name|getModifier
argument_list|()
specifier|const
block|{
return|return
name|Modifier
return|;
block|}
name|StringRef
name|getModifierText
argument_list|()
specifier|const
block|;
name|bool
name|hasModifier
argument_list|()
specifier|const
block|{
return|return
name|Modifier
operator|!=
name|ARMCP
operator|::
name|no_modifier
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
specifier|const
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
specifier|const
block|{
return|return
name|Kind
operator|==
name|ARMCP
operator|::
name|CPLSDA
return|;
block|}
name|bool
name|isMachineBasicBlock
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|ARMCP
operator|::
name|CPMachineBasicBlock
return|;
block|}
name|bool
name|isPromotedGlobal
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|ARMCP
operator|::
name|CPPromotedGlobal
return|;
block|}
name|int
name|getExistingMachineCPValue
argument_list|(
argument|MachineConstantPool *CP
argument_list|,
argument|unsigned Alignment
argument_list|)
name|override
block|;
name|void
name|addSelectionDAGCSEId
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|)
name|override
block|;
comment|/// hasSameValue - Return true if this ARM constpool value can share the same
comment|/// constantpool entry as another ARM constpool value.
name|virtual
name|bool
name|hasSameValue
argument_list|(
name|ARMConstantPoolValue
operator|*
name|ACPV
argument_list|)
block|;
name|bool
name|equals
argument_list|(
argument|const ARMConstantPoolValue *A
argument_list|)
specifier|const
block|{
return|return
name|this
operator|->
name|LabelId
operator|==
name|A
operator|->
name|LabelId
operator|&&
name|this
operator|->
name|PCAdjust
operator|==
name|A
operator|->
name|PCAdjust
operator|&&
name|this
operator|->
name|Modifier
operator|==
name|A
operator|->
name|Modifier
return|;
block|}
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
name|override
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
comment|/// ARMConstantPoolConstant - ARM-specific constant pool values for Constants,
comment|/// Functions, and BlockAddresses.
name|class
name|ARMConstantPoolConstant
range|:
name|public
name|ARMConstantPoolValue
block|{
specifier|const
name|Constant
operator|*
name|CVal
block|;
comment|// Constant being loaded.
specifier|const
name|GlobalVariable
operator|*
name|GVar
operator|=
name|nullptr
block|;
name|ARMConstantPoolConstant
argument_list|(
argument|const Constant *C
argument_list|,
argument|unsigned ID
argument_list|,
argument|ARMCP::ARMCPKind Kind
argument_list|,
argument|unsigned char PCAdj
argument_list|,
argument|ARMCP::ARMCPModifier Modifier
argument_list|,
argument|bool AddCurrentAddress
argument_list|)
block|;
name|ARMConstantPoolConstant
argument_list|(
argument|Type *Ty
argument_list|,
argument|const Constant *C
argument_list|,
argument|unsigned ID
argument_list|,
argument|ARMCP::ARMCPKind Kind
argument_list|,
argument|unsigned char PCAdj
argument_list|,
argument|ARMCP::ARMCPModifier Modifier
argument_list|,
argument|bool AddCurrentAddress
argument_list|)
block|;
name|ARMConstantPoolConstant
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|,
specifier|const
name|Constant
operator|*
name|Init
argument_list|)
block|;
name|public
operator|:
specifier|static
name|ARMConstantPoolConstant
operator|*
name|Create
argument_list|(
argument|const Constant *C
argument_list|,
argument|unsigned ID
argument_list|)
block|;
specifier|static
name|ARMConstantPoolConstant
operator|*
name|Create
argument_list|(
argument|const GlobalValue *GV
argument_list|,
argument|ARMCP::ARMCPModifier Modifier
argument_list|)
block|;
specifier|static
name|ARMConstantPoolConstant
operator|*
name|Create
argument_list|(
specifier|const
name|GlobalVariable
operator|*
name|GV
argument_list|,
specifier|const
name|Constant
operator|*
name|Initializer
argument_list|)
block|;
specifier|static
name|ARMConstantPoolConstant
operator|*
name|Create
argument_list|(
argument|const Constant *C
argument_list|,
argument|unsigned ID
argument_list|,
argument|ARMCP::ARMCPKind Kind
argument_list|,
argument|unsigned char PCAdj
argument_list|)
block|;
specifier|static
name|ARMConstantPoolConstant
operator|*
name|Create
argument_list|(
argument|const Constant *C
argument_list|,
argument|unsigned ID
argument_list|,
argument|ARMCP::ARMCPKind Kind
argument_list|,
argument|unsigned char PCAdj
argument_list|,
argument|ARMCP::ARMCPModifier Modifier
argument_list|,
argument|bool AddCurrentAddress
argument_list|)
block|;
specifier|const
name|GlobalValue
operator|*
name|getGV
argument_list|()
specifier|const
block|;
specifier|const
name|BlockAddress
operator|*
name|getBlockAddress
argument_list|()
specifier|const
block|;
specifier|const
name|GlobalVariable
operator|*
name|getPromotedGlobal
argument_list|()
specifier|const
block|{
return|return
name|dyn_cast_or_null
operator|<
name|GlobalVariable
operator|>
operator|(
name|GVar
operator|)
return|;
block|}
specifier|const
name|Constant
operator|*
name|getPromotedGlobalInit
argument_list|()
specifier|const
block|{
return|return
name|CVal
return|;
block|}
name|int
name|getExistingMachineCPValue
argument_list|(
argument|MachineConstantPool *CP
argument_list|,
argument|unsigned Alignment
argument_list|)
name|override
block|;
comment|/// hasSameValue - Return true if this ARM constpool value can share the same
comment|/// constantpool entry as another ARM constpool value.
name|bool
name|hasSameValue
argument_list|(
argument|ARMConstantPoolValue *ACPV
argument_list|)
name|override
block|;
name|void
name|addSelectionDAGCSEId
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|)
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const ARMConstantPoolValue *APV
argument_list|)
block|{
return|return
name|APV
operator|->
name|isGlobalValue
argument_list|()
operator|||
name|APV
operator|->
name|isBlockAddress
argument_list|()
operator|||
name|APV
operator|->
name|isLSDA
argument_list|()
operator|||
name|APV
operator|->
name|isPromotedGlobal
argument_list|()
return|;
block|}
name|bool
name|equals
argument_list|(
argument|const ARMConstantPoolConstant *A
argument_list|)
specifier|const
block|{
return|return
name|CVal
operator|==
name|A
operator|->
name|CVal
operator|&&
name|ARMConstantPoolValue
operator|::
name|equals
argument_list|(
name|A
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// ARMConstantPoolSymbol - ARM-specific constantpool values for external
comment|/// symbols.
name|class
name|ARMConstantPoolSymbol
operator|:
name|public
name|ARMConstantPoolValue
block|{
specifier|const
name|std
operator|::
name|string
name|S
block|;
comment|// ExtSymbol being loaded.
name|ARMConstantPoolSymbol
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|StringRef s
argument_list|,
argument|unsigned id
argument_list|,
argument|unsigned char PCAdj
argument_list|,
argument|ARMCP::ARMCPModifier Modifier
argument_list|,
argument|bool AddCurrentAddress
argument_list|)
block|;
name|public
operator|:
specifier|static
name|ARMConstantPoolSymbol
operator|*
name|Create
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|StringRef s
argument_list|,
argument|unsigned ID
argument_list|,
argument|unsigned char PCAdj
argument_list|)
block|;
name|StringRef
name|getSymbol
argument_list|()
specifier|const
block|{
return|return
name|S
return|;
block|}
name|int
name|getExistingMachineCPValue
argument_list|(
argument|MachineConstantPool *CP
argument_list|,
argument|unsigned Alignment
argument_list|)
name|override
block|;
name|void
name|addSelectionDAGCSEId
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|)
name|override
block|;
comment|/// hasSameValue - Return true if this ARM constpool value can share the same
comment|/// constantpool entry as another ARM constpool value.
name|bool
name|hasSameValue
argument_list|(
argument|ARMConstantPoolValue *ACPV
argument_list|)
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const ARMConstantPoolValue *ACPV
argument_list|)
block|{
return|return
name|ACPV
operator|->
name|isExtSymbol
argument_list|()
return|;
block|}
name|bool
name|equals
argument_list|(
argument|const ARMConstantPoolSymbol *A
argument_list|)
specifier|const
block|{
return|return
name|S
operator|==
name|A
operator|->
name|S
operator|&&
name|ARMConstantPoolValue
operator|::
name|equals
argument_list|(
name|A
argument_list|)
return|;
block|}
expr|}
block|;
comment|/// ARMConstantPoolMBB - ARM-specific constantpool value of a machine basic
comment|/// block.
name|class
name|ARMConstantPoolMBB
operator|:
name|public
name|ARMConstantPoolValue
block|{
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
block|;
comment|// Machine basic block.
name|ARMConstantPoolMBB
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|const MachineBasicBlock *mbb
argument_list|,
argument|unsigned id
argument_list|,
argument|unsigned char PCAdj
argument_list|,
argument|ARMCP::ARMCPModifier Modifier
argument_list|,
argument|bool AddCurrentAddress
argument_list|)
block|;
name|public
operator|:
specifier|static
name|ARMConstantPoolMBB
operator|*
name|Create
argument_list|(
argument|LLVMContext&C
argument_list|,
argument|const MachineBasicBlock *mbb
argument_list|,
argument|unsigned ID
argument_list|,
argument|unsigned char PCAdj
argument_list|)
block|;
specifier|const
name|MachineBasicBlock
operator|*
name|getMBB
argument_list|()
specifier|const
block|{
return|return
name|MBB
return|;
block|}
name|int
name|getExistingMachineCPValue
argument_list|(
argument|MachineConstantPool *CP
argument_list|,
argument|unsigned Alignment
argument_list|)
name|override
block|;
name|void
name|addSelectionDAGCSEId
argument_list|(
argument|FoldingSetNodeID&ID
argument_list|)
name|override
block|;
comment|/// hasSameValue - Return true if this ARM constpool value can share the same
comment|/// constantpool entry as another ARM constpool value.
name|bool
name|hasSameValue
argument_list|(
argument|ARMConstantPoolValue *ACPV
argument_list|)
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&O
argument_list|)
specifier|const
name|override
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const ARMConstantPoolValue *ACPV
argument_list|)
block|{
return|return
name|ACPV
operator|->
name|isMachineBasicBlock
argument_list|()
return|;
block|}
name|bool
name|equals
argument_list|(
argument|const ARMConstantPoolMBB *A
argument_list|)
specifier|const
block|{
return|return
name|MBB
operator|==
name|A
operator|->
name|MBB
operator|&&
name|ARMConstantPoolValue
operator|::
name|equals
argument_list|(
name|A
argument_list|)
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_ARM_ARMCONSTANTPOOLVALUE_H
end_comment

end_unit

