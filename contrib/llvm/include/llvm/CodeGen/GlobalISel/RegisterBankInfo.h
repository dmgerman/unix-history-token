begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/CodeGen/GlobalISel/RegisterBankInfo.h ----------------*- C++ -*-==//
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
comment|/// \file This file declares the API for the register bank info.
end_comment

begin_comment
comment|/// This API is responsible for handling the register banks.
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
name|LLVM_CODEGEN_GLOBALISEL_REGBANKINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_REGBANKINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/RegisterBank.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineValueType.h"
end_include

begin_comment
comment|// For SimpleValueType.
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/ErrorHandling.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_comment
comment|// For unique_ptr.
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// Holds all the information related to register banks.
name|class
name|RegisterBankInfo
block|{
name|public
label|:
comment|/// Helper struct that represents how a value is partially mapped
comment|/// into a register.
comment|/// The StartIdx and Length represent what region of the orginal
comment|/// value this partial mapping covers.
comment|/// This can be represented as a Mask of contiguous bit starting
comment|/// at StartIdx bit and spanning Length bits.
comment|/// StartIdx is the number of bits from the less significant bits.
struct|struct
name|PartialMapping
block|{
comment|/// Number of bits at which this partial mapping starts in the
comment|/// original value.  The bits are counted from less significant
comment|/// bits to most significant bits.
name|unsigned
name|StartIdx
decl_stmt|;
comment|/// Length of this mapping in bits. This is how many bits this
comment|/// partial mapping covers in the original value:
comment|/// from StartIdx to StartIdx + Length -1.
name|unsigned
name|Length
decl_stmt|;
comment|/// Register bank where the partial value lives.
specifier|const
name|RegisterBank
modifier|*
name|RegBank
decl_stmt|;
name|PartialMapping
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Provide a shortcut for quickly building PartialMapping.
name|PartialMapping
argument_list|(
argument|unsigned StartIdx
argument_list|,
argument|unsigned Length
argument_list|,
argument|const RegisterBank&RegBank
argument_list|)
block|:
name|StartIdx
argument_list|(
name|StartIdx
argument_list|)
operator|,
name|Length
argument_list|(
name|Length
argument_list|)
operator|,
name|RegBank
argument_list|(
argument|&RegBank
argument_list|)
block|{}
comment|/// \return the index of in the original value of the most
comment|/// significant bit that this partial mapping covers.
name|unsigned
name|getHighBitIdx
argument_list|()
specifier|const
block|{
return|return
name|StartIdx
operator|+
name|Length
operator|-
literal|1
return|;
block|}
comment|/// Print this partial mapping on dbgs() stream.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// Print this partial mapping on \p OS;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// Check that the Mask is compatible with the RegBank.
comment|/// Indeed, if the RegBank cannot accomadate the "active bits" of the mask,
comment|/// there is no way this mapping is valid.
comment|///
comment|/// \note This method does not check anything when assertions are disabled.
comment|///
comment|/// \return True is the check was successful.
name|bool
name|verify
argument_list|()
specifier|const
expr_stmt|;
block|}
struct|;
comment|/// Helper struct that represents how a value is mapped through
comment|/// different register banks.
struct|struct
name|ValueMapping
block|{
comment|/// How the value is broken down between the different register banks.
name|SmallVector
operator|<
name|PartialMapping
operator|,
literal|2
operator|>
name|BreakDown
expr_stmt|;
comment|/// Verify that this mapping makes sense for a value of \p ExpectedBitWidth.
comment|/// \note This method does not check anything when assertions are disabled.
comment|///
comment|/// \return True is the check was successful.
name|bool
name|verify
argument_list|(
name|unsigned
name|ExpectedBitWidth
argument_list|)
decl|const
decl_stmt|;
comment|/// Print this on dbgs() stream.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// Print this on \p OS;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
struct|;
comment|/// Helper class that represents how the value of an instruction may be
comment|/// mapped and what is the related cost of such mapping.
name|class
name|InstructionMapping
block|{
comment|/// Identifier of the mapping.
comment|/// This is used to communicate between the target and the optimizers
comment|/// which mapping should be realized.
name|unsigned
name|ID
decl_stmt|;
comment|/// Cost of this mapping.
name|unsigned
name|Cost
decl_stmt|;
comment|/// Mapping of all the operands.
name|std
operator|::
name|unique_ptr
operator|<
name|ValueMapping
index|[]
operator|>
name|OperandsMapping
expr_stmt|;
comment|/// Number of operands.
name|unsigned
name|NumOperands
decl_stmt|;
name|ValueMapping
modifier|&
name|getOperandMapping
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|getNumOperands
argument_list|()
operator|&&
literal|"Out of bound operand"
argument_list|)
expr_stmt|;
return|return
name|OperandsMapping
index|[
name|i
index|]
return|;
block|}
name|public
label|:
comment|/// Constructor for the mapping of an instruction.
comment|/// \p NumOperands must be equal to number of all the operands of
comment|/// the related instruction.
comment|/// The rationale is that it is more efficient for the optimizers
comment|/// to be able to assume that the mapping of the ith operand is
comment|/// at the index i.
comment|///
comment|/// \pre ID != InvalidMappingID
name|InstructionMapping
argument_list|(
argument|unsigned ID
argument_list|,
argument|unsigned Cost
argument_list|,
argument|unsigned NumOperands
argument_list|)
block|:
name|ID
argument_list|(
name|ID
argument_list|)
operator|,
name|Cost
argument_list|(
name|Cost
argument_list|)
operator|,
name|NumOperands
argument_list|(
argument|NumOperands
argument_list|)
block|{
name|assert
argument_list|(
name|getID
argument_list|()
operator|!=
name|InvalidMappingID
operator|&&
literal|"Use the default constructor for invalid mapping"
argument_list|)
block|;
name|OperandsMapping
operator|.
name|reset
argument_list|(
argument|new ValueMapping[getNumOperands()]
argument_list|)
block|;     }
comment|/// Default constructor.
comment|/// Use this constructor to express that the mapping is invalid.
name|InstructionMapping
argument_list|()
operator|:
name|ID
argument_list|(
name|InvalidMappingID
argument_list|)
operator|,
name|Cost
argument_list|(
literal|0
argument_list|)
operator|,
name|NumOperands
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Get the cost.
name|unsigned
name|getCost
argument_list|()
specifier|const
block|{
return|return
name|Cost
return|;
block|}
comment|/// Get the ID.
name|unsigned
name|getID
argument_list|()
specifier|const
block|{
return|return
name|ID
return|;
block|}
comment|/// Get the number of operands.
name|unsigned
name|getNumOperands
argument_list|()
specifier|const
block|{
return|return
name|NumOperands
return|;
block|}
comment|/// Get the value mapping of the ith operand.
specifier|const
name|ValueMapping
modifier|&
name|getOperandMapping
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|InstructionMapping
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getOperandMapping
argument_list|(
name|i
argument_list|)
return|;
block|}
comment|/// Get the value mapping of the ith operand.
name|void
name|setOperandMapping
parameter_list|(
name|unsigned
name|i
parameter_list|,
specifier|const
name|ValueMapping
modifier|&
name|ValMapping
parameter_list|)
block|{
name|getOperandMapping
argument_list|(
name|i
argument_list|)
operator|=
name|ValMapping
expr_stmt|;
block|}
comment|/// Check whether this object is valid.
comment|/// This is a lightweight check for obvious wrong instance.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|getID
argument_list|()
operator|!=
name|InvalidMappingID
return|;
block|}
comment|/// Set the operand mapping for the \p OpIdx-th operand.
comment|/// The mapping will consist of only one element in the break down list.
comment|/// This element will map to \p RegBank and fully define a mask, whose
comment|/// bitwidth matches the size of \p MaskSize.
name|void
name|setOperandMapping
parameter_list|(
name|unsigned
name|OpIdx
parameter_list|,
name|unsigned
name|MaskSize
parameter_list|,
specifier|const
name|RegisterBank
modifier|&
name|RegBank
parameter_list|)
function_decl|;
comment|/// Verifiy that this mapping makes sense for \p MI.
comment|/// \pre \p MI must be connected to a MachineFunction.
comment|///
comment|/// \note This method does not check anything when assertions are disabled.
comment|///
comment|/// \return True is the check was successful.
name|bool
name|verify
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// Print this on dbgs() stream.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// Print this on \p OS;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
comment|/// Convenient type to represent the alternatives for mapping an
comment|/// instruction.
comment|/// \todo When we move to TableGen this should be an array ref.
typedef|typedef
name|SmallVector
operator|<
name|InstructionMapping
operator|,
literal|4
operator|>
name|InstructionMappings
expr_stmt|;
comment|/// Helper class use to get/create the virtual registers that will be used
comment|/// to replace the MachineOperand when applying a mapping.
name|class
name|OperandsMapper
block|{
comment|/// The OpIdx-th cell contains the index in NewVRegs where the VRegs of the
comment|/// OpIdx-th operand starts. -1 means we do not have such mapping yet.
name|std
operator|::
name|unique_ptr
operator|<
name|int
index|[]
operator|>
name|OpToNewVRegIdx
expr_stmt|;
comment|/// Hold the registers that will be used to map MI with InstrMapping.
name|SmallVector
operator|<
name|unsigned
operator|,
literal|8
operator|>
name|NewVRegs
expr_stmt|;
comment|/// Current MachineRegisterInfo, used to create new virtual registers.
name|MachineRegisterInfo
modifier|&
name|MRI
decl_stmt|;
comment|/// Instruction being remapped.
name|MachineInstr
modifier|&
name|MI
decl_stmt|;
comment|/// New mapping of the instruction.
specifier|const
name|InstructionMapping
modifier|&
name|InstrMapping
decl_stmt|;
comment|/// Constant value identifying that the index in OpToNewVRegIdx
comment|/// for an operand has not been set yet.
specifier|static
specifier|const
name|int
name|DontKnowIdx
decl_stmt|;
comment|/// Get the range in NewVRegs to store all the partial
comment|/// values for the \p OpIdx-th operand.
comment|///
comment|/// \return The iterator range for the space created.
comment|//
comment|/// \pre getMI().getOperand(OpIdx).isReg()
name|iterator_range
operator|<
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|::
name|iterator
operator|>
name|getVRegsMem
argument_list|(
argument|unsigned OpIdx
argument_list|)
expr_stmt|;
comment|/// Get the end iterator for a range starting at \p StartIdx and
comment|/// spannig \p NumVal in NewVRegs.
comment|/// \pre StartIdx + NumVal<= NewVRegs.size()
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
name|getNewVRegsEnd
argument_list|(
argument|unsigned StartIdx
argument_list|,
argument|unsigned NumVal
argument_list|)
specifier|const
expr_stmt|;
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|::
name|iterator
name|getNewVRegsEnd
argument_list|(
argument|unsigned StartIdx
argument_list|,
argument|unsigned NumVal
argument_list|)
expr_stmt|;
name|public
label|:
comment|/// Create an OperandsMapper that will hold the information to apply \p
comment|/// InstrMapping to \p MI.
comment|/// \pre InstrMapping.verify(MI)
name|OperandsMapper
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
specifier|const
name|InstructionMapping
operator|&
name|InstrMapping
argument_list|,
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|)
expr_stmt|;
comment|/// Getters.
comment|/// @{
comment|/// The MachineInstr being remapped.
name|MachineInstr
operator|&
name|getMI
argument_list|()
specifier|const
block|{
return|return
name|MI
return|;
block|}
comment|/// The final mapping of the instruction.
specifier|const
name|InstructionMapping
operator|&
name|getInstrMapping
argument_list|()
specifier|const
block|{
return|return
name|InstrMapping
return|;
block|}
comment|/// @}
comment|/// Create as many new virtual registers as needed for the mapping of the \p
comment|/// OpIdx-th operand.
comment|/// The number of registers is determined by the number of breakdown for the
comment|/// related operand in the instruction mapping.
comment|///
comment|/// \pre getMI().getOperand(OpIdx).isReg()
comment|///
comment|/// \post All the partial mapping of the \p OpIdx-th operand have been
comment|/// assigned a new virtual register.
name|void
name|createVRegs
parameter_list|(
name|unsigned
name|OpIdx
parameter_list|)
function_decl|;
comment|/// Set the virtual register of the \p PartialMapIdx-th partial mapping of
comment|/// the OpIdx-th operand to \p NewVReg.
comment|///
comment|/// \pre getMI().getOperand(OpIdx).isReg()
comment|/// \pre getInstrMapping().getOperandMapping(OpIdx).BreakDown.size()>
comment|/// PartialMapIdx
comment|/// \pre NewReg != 0
comment|///
comment|/// \post the \p PartialMapIdx-th register of the value mapping of the \p
comment|/// OpIdx-th operand has been set.
name|void
name|setVRegs
parameter_list|(
name|unsigned
name|OpIdx
parameter_list|,
name|unsigned
name|PartialMapIdx
parameter_list|,
name|unsigned
name|NewVReg
parameter_list|)
function_decl|;
comment|/// Get all the virtual registers required to map the \p OpIdx-th operand of
comment|/// the instruction.
comment|///
comment|/// This return an empty range when createVRegs or setVRegs has not been
comment|/// called.
comment|/// The iterator may be invalidated by a call to setVRegs or createVRegs.
comment|///
comment|/// When \p ForDebug is true, we will not check that the list of new virtual
comment|/// registers does not contain uninitialized values.
comment|///
comment|/// \pre getMI().getOperand(OpIdx).isReg()
comment|/// \pre ForDebug || All partial mappings have been set a register
name|iterator_range
operator|<
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
operator|>
name|getVRegs
argument_list|(
argument|unsigned OpIdx
argument_list|,
argument|bool ForDebug = false
argument_list|)
specifier|const
expr_stmt|;
comment|/// Print this operands mapper on dbgs() stream.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// Print this operands mapper on \p OS stream.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|bool
name|ForDebug
operator|=
name|false
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
name|protected
label|:
comment|/// Hold the set of supported register banks.
name|std
operator|::
name|unique_ptr
operator|<
name|RegisterBank
index|[]
operator|>
name|RegBanks
expr_stmt|;
comment|/// Total number of register banks.
name|unsigned
name|NumRegBanks
decl_stmt|;
comment|/// Mapping from MVT::SimpleValueType to register banks.
name|std
operator|::
name|unique_ptr
operator|<
specifier|const
name|RegisterBank
operator|*
index|[]
operator|>
name|VTToRegBank
expr_stmt|;
comment|/// Create a RegisterBankInfo that can accomodate up to \p NumRegBanks
comment|/// RegisterBank instances.
comment|///
comment|/// \note For the verify method to succeed all the \p NumRegBanks
comment|/// must be initialized by createRegisterBank and updated with
comment|/// addRegBankCoverage RegisterBank.
name|RegisterBankInfo
argument_list|(
argument|unsigned NumRegBanks
argument_list|)
empty_stmt|;
comment|/// This constructor is meaningless.
comment|/// It just provides a default constructor that can be used at link time
comment|/// when GlobalISel is not built.
comment|/// That way, targets can still inherit from this class without doing
comment|/// crazy gymnastic to avoid link time failures.
comment|/// \note That works because the constructor is inlined.
name|RegisterBankInfo
argument_list|()
block|{
name|llvm_unreachable
argument_list|(
literal|"This constructor should not be executed"
argument_list|)
expr_stmt|;
block|}
comment|/// Create a new register bank with the given parameter and add it
comment|/// to RegBanks.
comment|/// \pre \p ID must not already be used.
comment|/// \pre \p ID< NumRegBanks.
name|void
name|createRegisterBank
parameter_list|(
name|unsigned
name|ID
parameter_list|,
specifier|const
name|char
modifier|*
name|Name
parameter_list|)
function_decl|;
comment|/// Add \p RCId to the set of register class that the register bank,
comment|/// identified \p ID, covers.
comment|/// This method transitively adds all the sub classes and the subreg-classes
comment|/// of \p RCId to the set of covered register classes.
comment|/// It also adjusts the size of the register bank to reflect the maximal
comment|/// size of a value that can be hold into that register bank.
comment|///
comment|/// If \p AddTypeMapping is true, this method also records what types can
comment|/// be mapped to \p ID. Although this done by default, targets may want to
comment|/// disable it, espicially if a given type may be mapped on different
comment|/// register bank. Indeed, in such case, this method only records the
comment|/// first register bank where the type matches.
comment|/// This information is only used to provide default mapping
comment|/// (see getInstrMappingImpl).
comment|///
comment|/// \note This method does *not* add the super classes of \p RCId.
comment|/// The rationale is if \p ID covers the registers of \p RCId, that
comment|/// does not necessarily mean that \p ID covers the set of registers
comment|/// of RCId's superclasses.
comment|/// This method does *not* add the superreg classes as well for consistents.
comment|/// The expected use is to add the coverage top-down with respect to the
comment|/// register hierarchy.
comment|///
comment|/// \todo TableGen should just generate the BitSet vector for us.
name|void
name|addRegBankCoverage
parameter_list|(
name|unsigned
name|ID
parameter_list|,
name|unsigned
name|RCId
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
parameter_list|,
name|bool
name|AddTypeMapping
init|=
name|true
parameter_list|)
function_decl|;
comment|/// Get the register bank identified by \p ID.
name|RegisterBank
modifier|&
name|getRegBank
parameter_list|(
name|unsigned
name|ID
parameter_list|)
block|{
name|assert
argument_list|(
name|ID
operator|<
name|getNumRegBanks
argument_list|()
operator|&&
literal|"Accessing an unknown register bank"
argument_list|)
expr_stmt|;
return|return
name|RegBanks
index|[
name|ID
index|]
return|;
block|}
comment|/// Get the register bank that has been recorded to cover \p SVT.
specifier|const
name|RegisterBank
modifier|*
name|getRegBankForType
argument_list|(
name|MVT
operator|::
name|SimpleValueType
name|SVT
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|VTToRegBank
condition|)
return|return
name|nullptr
return|;
name|assert
argument_list|(
name|SVT
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|::
name|LAST_VALUETYPE
operator|&&
literal|"Out-of-bound access"
argument_list|)
expr_stmt|;
return|return
name|VTToRegBank
operator|.
name|get
argument_list|()
index|[
name|SVT
index|]
return|;
block|}
comment|/// Record \p RegBank as the register bank that covers \p SVT.
comment|/// If a record was already set for \p SVT, the mapping is not
comment|/// updated, unless \p Force == true
comment|///
comment|/// \post if getRegBankForType(SVT)\@pre == nullptr then
comment|///                       getRegBankForType(SVT) ==&RegBank
comment|/// \post if Force == true then getRegBankForType(SVT) ==&RegBank
name|void
name|recordRegBankForType
argument_list|(
specifier|const
name|RegisterBank
operator|&
name|RegBank
argument_list|,
name|MVT
operator|::
name|SimpleValueType
name|SVT
argument_list|,
name|bool
name|Force
operator|=
name|false
argument_list|)
block|{
if|if
condition|(
operator|!
name|VTToRegBank
condition|)
block|{
name|VTToRegBank
operator|.
name|reset
argument_list|(
name|new
specifier|const
name|RegisterBank
operator|*
index|[
name|MVT
operator|::
name|SimpleValueType
operator|::
name|LAST_VALUETYPE
index|]
argument_list|)
expr_stmt|;
name|std
operator|::
name|fill
argument_list|(
operator|&
name|VTToRegBank
index|[
literal|0
index|]
argument_list|,
operator|&
name|VTToRegBank
index|[
name|MVT
operator|::
name|SimpleValueType
operator|::
name|LAST_VALUETYPE
index|]
argument_list|,
name|nullptr
argument_list|)
expr_stmt|;
block|}
name|assert
argument_list|(
name|SVT
operator|<
name|MVT
operator|::
name|SimpleValueType
operator|::
name|LAST_VALUETYPE
operator|&&
literal|"Out-of-bound access"
argument_list|)
expr_stmt|;
comment|// If we want to override the mapping or the mapping does not exits yet,
comment|// set the register bank for SVT.
if|if
condition|(
name|Force
operator|||
operator|!
name|getRegBankForType
argument_list|(
name|SVT
argument_list|)
condition|)
name|VTToRegBank
operator|.
name|get
argument_list|()
index|[
name|SVT
index|]
operator|=
operator|&
name|RegBank
expr_stmt|;
block|}
comment|/// Try to get the mapping of \p MI.
comment|/// See getInstrMapping for more details on what a mapping represents.
comment|///
comment|/// Unlike getInstrMapping the returned InstructionMapping may be invalid
comment|/// (isValid() == false).
comment|/// This means that the target independent code is not smart enough
comment|/// to get the mapping of \p MI and thus, the target has to provide the
comment|/// information for \p MI.
comment|///
comment|/// This implementation is able to get the mapping of:
comment|/// - Target specific instructions by looking at the encoding constraints.
comment|/// - Any instruction if all the register operands are already been assigned
comment|///   a register, a register class, or a register bank.
comment|/// - Copies and phis if at least one of the operand has been assigned a
comment|///   register, a register class, or a register bank.
comment|/// In other words, this method will likely fail to find a mapping for
comment|/// any generic opcode that has not been lowered by target specific code.
name|InstructionMapping
name|getInstrMappingImpl
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the register bank for the \p OpIdx-th operand of \p MI form
comment|/// the encoding constraints, if any.
comment|///
comment|/// \return A register bank that covers the register class of the
comment|/// related encoding constraints or nullptr if \p MI did not provide
comment|/// enough information to deduce it.
specifier|const
name|RegisterBank
modifier|*
name|getRegBankFromConstraints
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|,
name|unsigned
name|OpIdx
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|TII
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|)
decl|const
decl_stmt|;
comment|/// Helper method to apply something that is like the default mapping.
comment|/// Basically, that means that \p OpdMapper.getMI() is left untouched
comment|/// aside from the reassignment of the register operand that have been
comment|/// remapped.
comment|/// If the mapping of one of the operand spans several registers, this
comment|/// method will abort as this is not like a default mapping anymore.
comment|///
comment|/// \pre For OpIdx in {0..\p OpdMapper.getMI().getNumOperands())
comment|///        the range OpdMapper.getVRegs(OpIdx) is empty or of size 1.
specifier|static
name|void
name|applyDefaultMapping
parameter_list|(
specifier|const
name|OperandsMapper
modifier|&
name|OpdMapper
parameter_list|)
function_decl|;
comment|/// See ::applyMapping.
name|virtual
name|void
name|applyMappingImpl
argument_list|(
specifier|const
name|OperandsMapper
operator|&
name|OpdMapper
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"The target has to implement that part"
argument_list|)
expr_stmt|;
block|}
name|public
label|:
name|virtual
operator|~
name|RegisterBankInfo
argument_list|()
block|{}
comment|/// Get the register bank identified by \p ID.
specifier|const
name|RegisterBank
operator|&
name|getRegBank
argument_list|(
argument|unsigned ID
argument_list|)
specifier|const
block|{
return|return
name|const_cast
operator|<
name|RegisterBankInfo
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getRegBank
argument_list|(
name|ID
argument_list|)
return|;
block|}
comment|/// Get the register bank of \p Reg.
comment|/// If Reg has not been assigned a register, a register class,
comment|/// or a register bank, then this returns nullptr.
comment|///
comment|/// \pre Reg != 0 (NoRegister)
specifier|const
name|RegisterBank
modifier|*
name|getRegBank
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the total number of register banks.
name|unsigned
name|getNumRegBanks
argument_list|()
specifier|const
block|{
return|return
name|NumRegBanks
return|;
block|}
comment|/// Get a register bank that covers \p RC.
comment|///
comment|/// \pre \p RC is a user-defined register class (as opposed as one
comment|/// generated by TableGen).
comment|///
comment|/// \note The mapping RC -> RegBank could be built while adding the
comment|/// coverage for the register banks. However, we do not do it, because,
comment|/// at least for now, we only need this information for register classes
comment|/// that are used in the description of instruction. In other words,
comment|/// there are just a handful of them and we do not want to waste space.
comment|///
comment|/// \todo This should be TableGen'ed.
name|virtual
specifier|const
name|RegisterBank
modifier|&
name|getRegBankFromRegClass
argument_list|(
specifier|const
name|TargetRegisterClass
operator|&
name|RC
argument_list|)
decl|const
block|{
name|llvm_unreachable
argument_list|(
literal|"The target must override this method"
argument_list|)
expr_stmt|;
block|}
comment|/// Get the cost of a copy from \p B to \p A, or put differently,
comment|/// get the cost of A = COPY B. Since register banks may cover
comment|/// different size, \p Size specifies what will be the size in bits
comment|/// that will be copied around.
comment|///
comment|/// \note Since this is a copy, both registers have the same size.
name|virtual
name|unsigned
name|copyCost
argument_list|(
specifier|const
name|RegisterBank
operator|&
name|A
argument_list|,
specifier|const
name|RegisterBank
operator|&
name|B
argument_list|,
name|unsigned
name|Size
argument_list|)
decl|const
block|{
comment|// Optimistically assume that copies are coalesced. I.e., when
comment|// they are on the same bank, they are free.
comment|// Otherwise assume a non-zero cost of 1. The targets are supposed
comment|// to override that properly anyway if they care.
return|return
operator|&
name|A
operator|!=
operator|&
name|B
return|;
block|}
comment|/// Identifier used when the related instruction mapping instance
comment|/// is generated by target independent code.
comment|/// Make sure not to use that identifier to avoid possible collision.
specifier|static
specifier|const
name|unsigned
name|DefaultMappingID
decl_stmt|;
comment|/// Identifier used when the related instruction mapping instance
comment|/// is generated by the default constructor.
comment|/// Make sure not to use that identifier.
specifier|static
specifier|const
name|unsigned
name|InvalidMappingID
decl_stmt|;
comment|/// Get the mapping of the different operands of \p MI
comment|/// on the register bank.
comment|/// This mapping should be the direct translation of \p MI.
comment|/// In other words, when \p MI is mapped with the returned mapping,
comment|/// only the register banks of the operands of \p MI need to be updated.
comment|/// In particular, neither the opcode or the type of \p MI needs to be
comment|/// updated for this direct mapping.
comment|///
comment|/// The target independent implementation gives a mapping based on
comment|/// the register classes for the target specific opcode.
comment|/// It uses the ID RegisterBankInfo::DefaultMappingID for that mapping.
comment|/// Make sure you do not use that ID for the alternative mapping
comment|/// for MI. See getInstrAlternativeMappings for the alternative
comment|/// mappings.
comment|///
comment|/// For instance, if \p MI is a vector add, the mapping should
comment|/// not be a scalarization of the add.
comment|///
comment|/// \post returnedVal.verify(MI).
comment|///
comment|/// \note If returnedVal does not verify MI, this would probably mean
comment|/// that the target does not support that instruction.
name|virtual
name|InstructionMapping
name|getInstrMapping
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the alternative mappings for \p MI.
comment|/// Alternative in the sense different from getInstrMapping.
name|virtual
name|InstructionMappings
name|getInstrAlternativeMappings
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the possible mapping for \p MI.
comment|/// A mapping defines where the different operands may live and at what cost.
comment|/// For instance, let us consider:
comment|/// v0(16) = G_ADD<2 x i8> v1, v2
comment|/// The possible mapping could be:
comment|///
comment|/// {/*ID*/VectorAdd, /*Cost*/1, /*v0*/{(0xFFFF, VPR)}, /*v1*/{(0xFFFF, VPR)},
comment|///                              /*v2*/{(0xFFFF, VPR)}}
comment|/// {/*ID*/ScalarAddx2, /*Cost*/2, /*v0*/{(0x00FF, GPR),(0xFF00, GPR)},
comment|///                                /*v1*/{(0x00FF, GPR),(0xFF00, GPR)},
comment|///                                /*v2*/{(0x00FF, GPR),(0xFF00, GPR)}}
comment|///
comment|/// \note The first alternative of the returned mapping should be the
comment|/// direct translation of \p MI current form.
comment|///
comment|/// \post !returnedVal.empty().
name|InstructionMappings
name|getInstrPossibleMappings
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|)
decl|const
decl_stmt|;
comment|/// Apply \p OpdMapper.getInstrMapping() to \p OpdMapper.getMI().
comment|/// After this call \p OpdMapper.getMI() may not be valid anymore.
comment|/// \p OpdMapper.getInstrMapping().getID() carries the information of
comment|/// what has been chosen to map \p OpdMapper.getMI(). This ID is set
comment|/// by the various getInstrXXXMapping method.
comment|///
comment|/// Therefore, getting the mapping and applying it should be kept in
comment|/// sync.
name|void
name|applyMapping
argument_list|(
specifier|const
name|OperandsMapper
operator|&
name|OpdMapper
argument_list|)
decl|const
block|{
comment|// The only mapping we know how to handle is the default mapping.
if|if
condition|(
name|OpdMapper
operator|.
name|getInstrMapping
argument_list|()
operator|.
name|getID
argument_list|()
operator|==
name|DefaultMappingID
condition|)
return|return
name|applyDefaultMapping
argument_list|(
name|OpdMapper
argument_list|)
return|;
comment|// For other mapping, the target needs to do the right thing.
comment|// If that means calling applyDefaultMapping, fine, but this
comment|// must be explicitly stated.
name|applyMappingImpl
argument_list|(
name|OpdMapper
argument_list|)
expr_stmt|;
block|}
comment|/// Get the size in bits of \p Reg.
comment|/// Utility method to get the size of any registers. Unlike
comment|/// MachineRegisterInfo::getSize, the register does not need to be a
comment|/// virtual register.
comment|///
comment|/// \pre \p Reg != 0 (NoRegister).
specifier|static
name|unsigned
name|getSizeInBits
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|MachineRegisterInfo
modifier|&
name|MRI
parameter_list|,
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
parameter_list|)
function_decl|;
comment|/// Check that information hold by this instance make sense for the
comment|/// given \p TRI.
comment|///
comment|/// \note This method does not check anything when assertions are disabled.
comment|///
comment|/// \return True is the check was successful.
name|bool
name|verify
argument_list|(
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|RegisterBankInfo
operator|::
name|PartialMapping
operator|&
name|PartMapping
operator|)
block|{
name|PartMapping
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|RegisterBankInfo
operator|::
name|ValueMapping
operator|&
name|ValMapping
operator|)
block|{
name|ValMapping
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|RegisterBankInfo
operator|::
name|InstructionMapping
operator|&
name|InstrMapping
operator|)
block|{
name|InstrMapping
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|RegisterBankInfo
operator|::
name|OperandsMapper
operator|&
name|OpdMapper
operator|)
block|{
name|OpdMapper
operator|.
name|print
argument_list|(
name|OS
argument_list|,
comment|/*ForDebug*/
name|false
argument_list|)
block|;
return|return
name|OS
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

