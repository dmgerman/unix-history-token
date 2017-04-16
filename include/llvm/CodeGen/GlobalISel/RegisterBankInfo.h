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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Hashing.h"
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
comment|///
comment|/// \note: So far we do not have any users of the complex mappings
comment|/// (mappings with more than one partial mapping), but when we do,
comment|/// we would have needed to duplicate partial mappings.
comment|/// The alternative could be to use an array of pointers of partial
comment|/// mapping (i.e., PartialMapping **BreakDown) and duplicate the
comment|/// pointers instead.
comment|///
comment|/// E.g.,
comment|/// Let say we have a 32-bit add and a<2 x 32-bit> vadd. We
comment|/// can expand the
comment|///<2 x 32-bit> add into 2 x 32-bit add.
comment|///
comment|/// Currently the TableGen-like file would look like:
comment|/// \code
comment|/// PartialMapping[] = {
comment|/// /*32-bit add*/ {0, 32, GPR},
comment|/// /*2x32-bit add*/ {0, 32, GPR}, {0, 32, GPR}, //<-- Same entry 3x
comment|/// /*<2x32-bit> vadd {0, 64, VPR}
comment|/// }; // PartialMapping duplicated.
comment|///
comment|/// ValueMapping[] {
comment|///   /*plain 32-bit add*/ {&PartialMapping[0], 1},
comment|///   /*expanded vadd on 2xadd*/ {&PartialMapping[1], 2},
comment|///   /*plain<2x32-bit> vadd*/ {&PartialMapping[3], 1}
comment|/// };
comment|/// \endcode
comment|///
comment|/// With the array of pointer, we would have:
comment|/// \code
comment|/// PartialMapping[] = {
comment|/// /*32-bit add*/ {0, 32, GPR},
comment|/// /*<2x32-bit> vadd {0, 64, VPR}
comment|/// }; // No more duplication.
comment|///
comment|/// BreakDowns[] = {
comment|/// /*AddBreakDown*/&PartialMapping[0],
comment|/// /*2xAddBreakDown*/&PartialMapping[0],&PartialMapping[0],
comment|/// /*VAddBreakDown*/&PartialMapping[1]
comment|/// }; // Addresses of PartialMapping duplicated (smaller).
comment|///
comment|/// ValueMapping[] {
comment|///   /*plain 32-bit add*/ {&BreakDowns[0], 1},
comment|///   /*expanded vadd on 2xadd*/ {&BreakDowns[1], 2},
comment|///   /*plain<2x32-bit> vadd*/ {&BreakDowns[3], 1}
comment|/// };
comment|/// \endcode
comment|///
comment|/// Given that a PartialMapping is actually small, the code size
comment|/// impact is actually a degradation. Moreover the compile time will
comment|/// be hit by the additional indirection.
comment|/// If PartialMapping gets bigger we may reconsider.
struct|struct
name|ValueMapping
block|{
comment|/// How the value is broken down between the different register banks.
specifier|const
name|PartialMapping
modifier|*
name|BreakDown
decl_stmt|;
comment|/// Number of partial mapping to break down this value.
name|unsigned
name|NumBreakDowns
decl_stmt|;
comment|/// The default constructor creates an invalid (isValid() == false)
comment|/// instance.
name|ValueMapping
argument_list|()
operator|:
name|ValueMapping
argument_list|(
argument|nullptr
argument_list|,
literal|0
argument_list|)
block|{}
comment|/// Initialize a ValueMapping with the given parameter.
comment|/// \p BreakDown needs to have a life time at least as long
comment|/// as this instance.
name|ValueMapping
argument_list|(
argument|const PartialMapping *BreakDown
argument_list|,
argument|unsigned NumBreakDowns
argument_list|)
operator|:
name|BreakDown
argument_list|(
name|BreakDown
argument_list|)
operator|,
name|NumBreakDowns
argument_list|(
argument|NumBreakDowns
argument_list|)
block|{}
comment|/// Iterators through the PartialMappings.
specifier|const
name|PartialMapping
operator|*
name|begin
argument_list|()
specifier|const
block|{
return|return
name|BreakDown
return|;
block|}
specifier|const
name|PartialMapping
operator|*
name|end
argument_list|()
specifier|const
block|{
return|return
name|BreakDown
operator|+
name|NumBreakDowns
return|;
block|}
comment|/// Check if this ValueMapping is valid.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|BreakDown
operator|&&
name|NumBreakDowns
return|;
block|}
comment|/// Verify that this mapping makes sense for a value of
comment|/// \p MeaningfulBitWidth.
comment|/// \note This method does not check anything when assertions are disabled.
comment|///
comment|/// \return True is the check was successful.
name|bool
name|verify
argument_list|(
name|unsigned
name|MeaningfulBitWidth
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
specifier|const
name|ValueMapping
modifier|*
name|OperandsMapping
decl_stmt|;
comment|/// Number of operands.
name|unsigned
name|NumOperands
decl_stmt|;
specifier|const
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
argument|const ValueMapping *OperandsMapping
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
name|OperandsMapping
argument_list|(
name|OperandsMapping
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
comment|/// \pre The mapping for the ith operand has been set.
comment|/// \pre The ith operand is a register.
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
specifier|const
name|ValueMapping
modifier|&
name|ValMapping
init|=
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
decl_stmt|;
return|return
name|ValMapping
return|;
block|}
comment|/// Set the mapping for all the operands.
comment|/// In other words, OpdsMapping should hold at least getNumOperands
comment|/// ValueMapping.
name|void
name|setOperandsMapping
parameter_list|(
specifier|const
name|ValueMapping
modifier|*
name|OpdsMapping
parameter_list|)
block|{
name|OperandsMapping
operator|=
name|OpdsMapping
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
operator|&&
name|OperandsMapping
return|;
block|}
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
comment|/// Helper class used to get/create the virtual registers that will be used
comment|/// to replace the MachineOperand when applying a mapping.
name|class
name|OperandsMapper
block|{
comment|/// The OpIdx-th cell contains the index in NewVRegs where the VRegs of the
comment|/// OpIdx-th operand starts. -1 means we do not have such mapping yet.
comment|/// Note: We use a SmallVector to avoid heap allocation for most cases.
name|SmallVector
operator|<
name|int
operator|,
literal|8
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
comment|/// The MachineRegisterInfo we used to realize the mapping.
name|MachineRegisterInfo
operator|&
name|getMRI
argument_list|()
specifier|const
block|{
return|return
name|MRI
return|;
block|}
comment|/// @}
comment|/// Create as many new virtual registers as needed for the mapping of the \p
comment|/// OpIdx-th operand.
comment|/// The number of registers is determined by the number of breakdown for the
comment|/// related operand in the instruction mapping.
comment|/// The type of the new registers is a plain scalar of the right size.
comment|/// The proper type is expected to be set when the mapping is applied to
comment|/// the instruction(s) that realizes the mapping.
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
name|RegisterBank
modifier|*
modifier|*
name|RegBanks
decl_stmt|;
comment|/// Total number of register banks.
name|unsigned
name|NumRegBanks
decl_stmt|;
comment|/// Keep dynamically allocated PartialMapping in a separate map.
comment|/// This shouldn't be needed when everything gets TableGen'ed.
name|mutable
name|DenseMap
operator|<
name|unsigned
operator|,
name|std
operator|::
name|unique_ptr
operator|<
specifier|const
name|PartialMapping
operator|>>
name|MapOfPartialMappings
expr_stmt|;
comment|/// Keep dynamically allocated ValueMapping in a separate map.
comment|/// This shouldn't be needed when everything gets TableGen'ed.
name|mutable
name|DenseMap
operator|<
name|unsigned
operator|,
name|std
operator|::
name|unique_ptr
operator|<
specifier|const
name|ValueMapping
operator|>
expr|>
name|MapOfValueMappings
expr_stmt|;
comment|/// Keep dynamically allocated array of ValueMapping in a separate map.
comment|/// This shouldn't be needed when everything gets TableGen'ed.
name|mutable
name|DenseMap
operator|<
name|unsigned
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|ValueMapping
index|[]
operator|>>
name|MapOfOperandsMappings
expr_stmt|;
comment|/// Create a RegisterBankInfo that can accomodate up to \p NumRegBanks
comment|/// RegisterBank instances.
name|RegisterBankInfo
argument_list|(
argument|RegisterBank **RegBanks
argument_list|,
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
operator|*
name|RegBanks
index|[
name|ID
index|]
return|;
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
comment|/// - Any instruction if all the register operands have already been assigned
comment|///   a register, a register class, or a register bank.
comment|/// - Copies and phis if at least one of the operands has been assigned a
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
comment|/// Get the uniquely generated PartialMapping for the
comment|/// given arguments.
specifier|const
name|PartialMapping
modifier|&
name|getPartialMapping
argument_list|(
name|unsigned
name|StartIdx
argument_list|,
name|unsigned
name|Length
argument_list|,
specifier|const
name|RegisterBank
operator|&
name|RegBank
argument_list|)
decl|const
decl_stmt|;
comment|/// Methods to get a uniquely generated ValueMapping.
comment|/// @{
comment|/// The most common ValueMapping consists of a single PartialMapping.
comment|/// Feature a method for that.
specifier|const
name|ValueMapping
modifier|&
name|getValueMapping
argument_list|(
name|unsigned
name|StartIdx
argument_list|,
name|unsigned
name|Length
argument_list|,
specifier|const
name|RegisterBank
operator|&
name|RegBank
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the ValueMapping for the given arguments.
specifier|const
name|ValueMapping
modifier|&
name|getValueMapping
argument_list|(
specifier|const
name|PartialMapping
operator|*
name|BreakDown
argument_list|,
name|unsigned
name|NumBreakDowns
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
comment|/// Methods to get a uniquely generated array of ValueMapping.
comment|/// @{
comment|/// Get the uniquely generated array of ValueMapping for the
comment|/// elements of between \p Begin and \p End.
comment|///
comment|/// Elements that are nullptr will be replaced by
comment|/// invalid ValueMapping (ValueMapping::isValid == false).
comment|///
comment|/// \pre The pointers on ValueMapping between \p Begin and \p End
comment|/// must uniquely identify a ValueMapping. Otherwise, there is no
comment|/// guarantee that the return instance will be unique, i.e., another
comment|/// OperandsMapping could have the same content.
name|template
operator|<
name|typename
name|Iterator
operator|>
specifier|const
name|ValueMapping
operator|*
name|getOperandsMapping
argument_list|(
argument|Iterator Begin
argument_list|,
argument|Iterator End
argument_list|)
specifier|const
expr_stmt|;
comment|/// Get the uniquely generated array of ValueMapping for the
comment|/// elements of \p OpdsMapping.
comment|///
comment|/// Elements of \p OpdsMapping that are nullptr will be replaced by
comment|/// invalid ValueMapping (ValueMapping::isValid == false).
specifier|const
name|ValueMapping
modifier|*
name|getOperandsMapping
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
specifier|const
name|ValueMapping
operator|*
operator|>
operator|&
name|OpdsMapping
argument_list|)
decl|const
decl_stmt|;
comment|/// Get the uniquely generated array of ValueMapping for the
comment|/// given arguments.
comment|///
comment|/// Arguments that are nullptr will be replaced by invalid
comment|/// ValueMapping (ValueMapping::isValid == false).
specifier|const
name|ValueMapping
modifier|*
name|getOperandsMapping
argument_list|(
name|std
operator|::
name|initializer_list
operator|<
specifier|const
name|ValueMapping
operator|*
operator|>
name|OpdsMapping
argument_list|)
decl|const
decl_stmt|;
comment|/// @}
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
comment|///
comment|/// The type of all the new registers that have been created by the
comment|/// mapper are properly remapped to the type of the original registers
comment|/// they replace. In other words, the semantic of the instruction does
comment|/// not change, only the register banks.
comment|///
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
operator|=
expr|default
expr_stmt|;
comment|/// Get the register bank identified by \p ID.
specifier|const
name|RegisterBank
modifier|&
name|getRegBank
argument_list|(
name|unsigned
name|ID
argument_list|)
decl|const
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
comment|/// Constrain the (possibly generic) virtual register \p Reg to \p RC.
comment|///
comment|/// \pre \p Reg is a virtual register that either has a bank or a class.
comment|/// \returns The constrained register class, or nullptr if there is none.
comment|/// \note This is a generic variant of MachineRegisterInfo::constrainRegClass
specifier|static
specifier|const
name|TargetRegisterClass
modifier|*
name|constrainGenericRegister
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|TargetRegisterClass
modifier|&
name|RC
parameter_list|,
name|MachineRegisterInfo
modifier|&
name|MRI
parameter_list|)
function_decl|;
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
comment|/// In particular, neither the opcode nor the type of \p MI needs to be
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
comment|/// Hashing function for PartialMapping.
comment|/// It is required for the hashing of ValueMapping.
name|hash_code
name|hash_value
argument_list|(
specifier|const
name|RegisterBankInfo
operator|::
name|PartialMapping
operator|&
name|PartMapping
argument_list|)
decl_stmt|;
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

