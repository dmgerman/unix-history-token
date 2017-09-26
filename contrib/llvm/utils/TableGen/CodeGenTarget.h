begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeGenTarget.h - Target Class Wrapper -------------------*- C++ -*-===//
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
comment|// This file defines wrappers for the Target class and related global
end_comment

begin_comment
comment|// functionality.  This makes it easier to access the data and provides a single
end_comment

begin_comment
comment|// place that needs to check it for validity.  All of these classes abort
end_comment

begin_comment
comment|// on error conditions.
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
name|LLVM_UTILS_TABLEGEN_CODEGENTARGET_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_UTILS_TABLEGEN_CODEGENTARGET_H
end_define

begin_include
include|#
directive|include
file|"CodeGenInstruction.h"
end_include

begin_include
include|#
directive|include
file|"CodeGenRegisters.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|"llvm/TableGen/Record.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
struct_decl|struct
name|CodeGenRegister
struct_decl|;
name|class
name|CodeGenSchedModels
decl_stmt|;
name|class
name|CodeGenTarget
decl_stmt|;
comment|// SelectionDAG node properties.
comment|//  SDNPMemOperand: indicates that a node touches memory and therefore must
comment|//                  have an associated memory operand that describes the access.
enum|enum
name|SDNP
block|{
name|SDNPCommutative
block|,
name|SDNPAssociative
block|,
name|SDNPHasChain
block|,
name|SDNPOutGlue
block|,
name|SDNPInGlue
block|,
name|SDNPOptInGlue
block|,
name|SDNPMayLoad
block|,
name|SDNPMayStore
block|,
name|SDNPSideEffect
block|,
name|SDNPMemOperand
block|,
name|SDNPVariadic
block|,
name|SDNPWantRoot
block|,
name|SDNPWantParent
block|}
enum|;
comment|/// getValueType - Return the MVT::SimpleValueType that the specified TableGen
comment|/// record corresponds to.
name|MVT
operator|::
name|SimpleValueType
name|getValueType
argument_list|(
name|Record
operator|*
name|Rec
argument_list|)
expr_stmt|;
name|StringRef
name|getName
argument_list|(
name|MVT
operator|::
name|SimpleValueType
name|T
argument_list|)
decl_stmt|;
name|StringRef
name|getEnumName
argument_list|(
name|MVT
operator|::
name|SimpleValueType
name|T
argument_list|)
decl_stmt|;
comment|/// getQualifiedName - Return the name of the specified record, with a
comment|/// namespace qualifier if the record contains one.
name|std
operator|::
name|string
name|getQualifiedName
argument_list|(
specifier|const
name|Record
operator|*
name|R
argument_list|)
expr_stmt|;
comment|/// CodeGenTarget - This class corresponds to the Target class in the .td files.
comment|///
name|class
name|CodeGenTarget
block|{
name|RecordKeeper
modifier|&
name|Records
decl_stmt|;
name|Record
modifier|*
name|TargetRec
decl_stmt|;
name|mutable
name|DenseMap
operator|<
specifier|const
name|Record
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|CodeGenInstruction
operator|>>
name|Instructions
expr_stmt|;
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|CodeGenRegBank
operator|>
name|RegBank
expr_stmt|;
name|mutable
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
name|RegAltNameIndices
expr_stmt|;
name|mutable
name|SmallVector
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|,
literal|8
operator|>
name|LegalValueTypes
expr_stmt|;
name|void
name|ReadRegAltNameIndices
argument_list|()
specifier|const
expr_stmt|;
name|void
name|ReadInstructions
argument_list|()
specifier|const
expr_stmt|;
name|void
name|ReadLegalValueTypes
argument_list|()
specifier|const
expr_stmt|;
name|mutable
name|std
operator|::
name|unique_ptr
operator|<
name|CodeGenSchedModels
operator|>
name|SchedModels
expr_stmt|;
name|mutable
name|std
operator|::
name|vector
operator|<
specifier|const
name|CodeGenInstruction
operator|*
operator|>
name|InstrsByEnum
expr_stmt|;
name|public
label|:
name|CodeGenTarget
argument_list|(
name|RecordKeeper
operator|&
name|Records
argument_list|)
expr_stmt|;
operator|~
name|CodeGenTarget
argument_list|()
expr_stmt|;
name|Record
operator|*
name|getTargetRecord
argument_list|()
specifier|const
block|{
return|return
name|TargetRec
return|;
block|}
specifier|const
name|StringRef
name|getName
argument_list|()
specifier|const
expr_stmt|;
comment|/// getInstNamespace - Return the target-specific instruction namespace.
comment|///
name|StringRef
name|getInstNamespace
argument_list|()
specifier|const
expr_stmt|;
comment|/// getInstructionSet - Return the InstructionSet object.
comment|///
name|Record
operator|*
name|getInstructionSet
argument_list|()
specifier|const
expr_stmt|;
comment|/// getAsmParser - Return the AssemblyParser definition for this target.
comment|///
name|Record
operator|*
name|getAsmParser
argument_list|()
specifier|const
expr_stmt|;
comment|/// getAsmParserVariant - Return the AssmblyParserVariant definition for
comment|/// this target.
comment|///
name|Record
modifier|*
name|getAsmParserVariant
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
decl_stmt|;
comment|/// getAsmParserVariantCount - Return the AssmblyParserVariant definition
comment|/// available for this target.
comment|///
name|unsigned
name|getAsmParserVariantCount
argument_list|()
specifier|const
expr_stmt|;
comment|/// getAsmWriter - Return the AssemblyWriter definition for this target.
comment|///
name|Record
operator|*
name|getAsmWriter
argument_list|()
specifier|const
expr_stmt|;
comment|/// getRegBank - Return the register bank description.
name|CodeGenRegBank
operator|&
name|getRegBank
argument_list|()
specifier|const
expr_stmt|;
comment|/// getRegisterByName - If there is a register with the specific AsmName,
comment|/// return it.
specifier|const
name|CodeGenRegister
modifier|*
name|getRegisterByName
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
operator|&
name|getRegAltNameIndices
argument_list|()
specifier|const
block|{
if|if
condition|(
name|RegAltNameIndices
operator|.
name|empty
argument_list|()
condition|)
name|ReadRegAltNameIndices
argument_list|()
expr_stmt|;
return|return
name|RegAltNameIndices
return|;
block|}
specifier|const
name|CodeGenRegisterClass
modifier|&
name|getRegisterClass
argument_list|(
name|Record
operator|*
name|R
argument_list|)
decl|const
block|{
return|return
operator|*
name|getRegBank
argument_list|()
operator|.
name|getRegClass
argument_list|(
name|R
argument_list|)
return|;
block|}
comment|/// getRegisterVTs - Find the union of all possible SimpleValueTypes for the
comment|/// specified physical register.
name|std
operator|::
name|vector
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|>
name|getRegisterVTs
argument_list|(
argument|Record *R
argument_list|)
specifier|const
expr_stmt|;
name|ArrayRef
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|>
name|getLegalValueTypes
argument_list|()
specifier|const
block|{
if|if
condition|(
name|LegalValueTypes
operator|.
name|empty
argument_list|()
condition|)
name|ReadLegalValueTypes
argument_list|()
expr_stmt|;
return|return
name|LegalValueTypes
return|;
block|}
end_decl_stmt

begin_comment
comment|/// isLegalValueType - Return true if the specified value type is natively
end_comment

begin_comment
comment|/// supported by the target (i.e. there are registers that directly hold it).
end_comment

begin_decl_stmt
name|bool
name|isLegalValueType
argument_list|(
name|MVT
operator|::
name|SimpleValueType
name|VT
argument_list|)
decl|const
block|{
name|ArrayRef
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|>
name|LegalVTs
operator|=
name|getLegalValueTypes
argument_list|()
expr_stmt|;
return|return
name|is_contained
argument_list|(
name|LegalVTs
argument_list|,
name|VT
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|CodeGenSchedModels
operator|&
name|getSchedModels
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|DenseMap
operator|<
specifier|const
name|Record
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|CodeGenInstruction
operator|>>
operator|&
name|getInstructions
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Instructions
operator|.
name|empty
argument_list|()
condition|)
name|ReadInstructions
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|Instructions
return|;
end_return

begin_decl_stmt
unit|} public:
name|CodeGenInstruction
modifier|&
name|getInstruction
argument_list|(
specifier|const
name|Record
operator|*
name|InstRec
argument_list|)
decl|const
block|{
if|if
condition|(
name|Instructions
operator|.
name|empty
argument_list|()
condition|)
name|ReadInstructions
argument_list|()
expr_stmt|;
name|auto
name|I
init|=
name|Instructions
operator|.
name|find
argument_list|(
name|InstRec
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|Instructions
operator|.
name|end
argument_list|()
operator|&&
literal|"Not an instruction"
argument_list|)
expr_stmt|;
return|return
operator|*
name|I
operator|->
name|second
return|;
block|}
end_decl_stmt

begin_comment
comment|/// getInstructionsByEnumValue - Return all of the instructions defined by the
end_comment

begin_comment
comment|/// target, ordered by their enum value.
end_comment

begin_expr_stmt
name|ArrayRef
operator|<
specifier|const
name|CodeGenInstruction
operator|*
operator|>
name|getInstructionsByEnumValue
argument_list|()
specifier|const
block|{
if|if
condition|(
name|InstrsByEnum
operator|.
name|empty
argument_list|()
condition|)
name|ComputeInstrsByEnum
argument_list|()
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|InstrsByEnum
return|;
end_return

begin_expr_stmt
unit|}    typedef
name|ArrayRef
operator|<
specifier|const
name|CodeGenInstruction
operator|*
operator|>
operator|::
name|const_iterator
name|inst_iterator
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|inst_iterator
name|inst_begin
argument_list|()
specifier|const
block|{
return|return
name|getInstructionsByEnumValue
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|inst_iterator
name|inst_end
argument_list|()
specifier|const
block|{
return|return
name|getInstructionsByEnumValue
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// isLittleEndianEncoding - are instruction bit patterns defined as  [0..n]?
end_comment

begin_comment
comment|///
end_comment

begin_expr_stmt
name|bool
name|isLittleEndianEncoding
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// reverseBitsForLittleEndianEncoding - For little-endian instruction bit
end_comment

begin_comment
comment|/// encodings, reverse the bit order of all instructions.
end_comment

begin_function_decl
name|void
name|reverseBitsForLittleEndianEncoding
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// guessInstructionProperties - should we just guess unset instruction
end_comment

begin_comment
comment|/// properties?
end_comment

begin_expr_stmt
name|bool
name|guessInstructionProperties
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|void
name|ComputeInstrsByEnum
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// ComplexPattern - ComplexPattern info, corresponding to the ComplexPattern
end_comment

begin_comment
comment|/// tablegen class in TargetSelectionDAG.td
end_comment

begin_decl_stmt
name|class
name|ComplexPattern
block|{
name|MVT
operator|::
name|SimpleValueType
name|Ty
expr_stmt|;
name|unsigned
name|NumOperands
decl_stmt|;
name|std
operator|::
name|string
name|SelectFunc
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
name|RootNodes
expr_stmt|;
name|unsigned
name|Properties
decl_stmt|;
comment|// Node properties
name|unsigned
name|Complexity
decl_stmt|;
name|public
label|:
name|ComplexPattern
argument_list|(
name|Record
operator|*
name|R
argument_list|)
expr_stmt|;
name|MVT
operator|::
name|SimpleValueType
name|getValueType
argument_list|()
specifier|const
block|{
return|return
name|Ty
return|;
block|}
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
block|{
return|return
name|NumOperands
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getSelectFunc
argument_list|()
specifier|const
block|{
return|return
name|SelectFunc
return|;
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
operator|&
name|getRootNodes
argument_list|()
specifier|const
block|{
return|return
name|RootNodes
return|;
block|}
name|bool
name|hasProperty
argument_list|(
expr|enum
name|SDNP
name|Prop
argument_list|)
decl|const
block|{
return|return
name|Properties
operator|&
operator|(
literal|1
operator|<<
name|Prop
operator|)
return|;
block|}
name|unsigned
name|getComplexity
argument_list|()
specifier|const
block|{
return|return
name|Complexity
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

