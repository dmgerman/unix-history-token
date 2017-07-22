begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- X86InstrFMA3Info.h - X86 FMA3 Instruction Information ----*- C++ -*-===//
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
comment|// This file contains the implementation of the classes providing information
end_comment

begin_comment
comment|// about existing X86 FMA3 opcodes, classifying and grouping them.
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
name|LLVM_LIB_TARGET_X86_UTILS_X86INSTRFMA3INFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_X86_UTILS_X86INSTRFMA3INFO_H
end_define

begin_include
include|#
directive|include
file|"X86.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// This class is used to group {132, 213, 231} forms of FMA opcodes together.
comment|/// Each of the groups has either 3 register opcodes, 3 memory opcodes,
comment|/// or 6 register and memory opcodes. Also, each group has an attrubutes field
comment|/// describing it.
name|class
name|X86InstrFMA3Group
block|{
name|private
label|:
comment|/// Reference to an array holding 3 forms of register FMA opcodes.
comment|/// It may be set to nullptr if the group of FMA opcodes does not have
comment|/// any register form opcodes.
specifier|const
name|uint16_t
modifier|*
name|RegOpcodes
decl_stmt|;
comment|/// Reference to an array holding 3 forms of memory FMA opcodes.
comment|/// It may be set to nullptr if the group of FMA opcodes does not have
comment|/// any register form opcodes.
specifier|const
name|uint16_t
modifier|*
name|MemOpcodes
decl_stmt|;
comment|/// This bitfield specifies the attributes associated with the created
comment|/// FMA groups of opcodes.
name|unsigned
name|Attributes
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|Form132
init|=
literal|0
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|Form213
init|=
literal|1
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|Form231
init|=
literal|2
decl_stmt|;
name|public
label|:
comment|/// This bit must be set in the 'Attributes' field of FMA group if such
comment|/// group of FMA opcodes consists of FMA intrinsic opcodes.
specifier|static
specifier|const
name|unsigned
name|X86FMA3Intrinsic
init|=
literal|0x1
decl_stmt|;
comment|/// This bit must be set in the 'Attributes' field of FMA group if such
comment|/// group of FMA opcodes consists of AVX512 opcodes accepting a k-mask and
comment|/// passing the elements from the 1st operand to the result of the operation
comment|/// when the correpondings bits in the k-mask are unset.
specifier|static
specifier|const
name|unsigned
name|X86FMA3KMergeMasked
init|=
literal|0x2
decl_stmt|;
comment|/// This bit must be set in the 'Attributes' field of FMA group if such
comment|/// group of FMA opcodes consists of AVX512 opcodes accepting a k-zeromask.
specifier|static
specifier|const
name|unsigned
name|X86FMA3KZeroMasked
init|=
literal|0x4
decl_stmt|;
comment|/// Constructor. Creates a new group of FMA opcodes with three register form
comment|/// FMA opcodes \p RegOpcodes and three memory form FMA opcodes \p MemOpcodes.
comment|/// The parameters \p RegOpcodes and \p MemOpcodes may be set to nullptr,
comment|/// which means that the created group of FMA opcodes does not have the
comment|/// corresponding (register or memory) opcodes.
comment|/// The parameter \p Attr specifies the attributes describing the created
comment|/// group.
name|X86InstrFMA3Group
argument_list|(
argument|const uint16_t *RegOpcodes
argument_list|,
argument|const uint16_t *MemOpcodes
argument_list|,
argument|unsigned Attr
argument_list|)
block|:
name|RegOpcodes
argument_list|(
name|RegOpcodes
argument_list|)
operator|,
name|MemOpcodes
argument_list|(
name|MemOpcodes
argument_list|)
operator|,
name|Attributes
argument_list|(
argument|Attr
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|RegOpcodes
operator|||
name|MemOpcodes
operator|)
operator|&&
literal|"Cannot create a group not having any opcodes."
argument_list|)
block|;   }
comment|/// Returns a memory form opcode that is the equivalent of the given register
comment|/// form opcode \p RegOpcode. 0 is returned if the group does not have
comment|/// either register of memory opcodes.
name|unsigned
name|getMemOpcode
argument_list|(
argument|unsigned RegOpcode
argument_list|)
specifier|const
block|{
if|if
condition|(
operator|!
name|RegOpcodes
operator|||
operator|!
name|MemOpcodes
condition|)
return|return
literal|0
return|;
for|for
control|(
name|unsigned
name|Form
init|=
literal|0
init|;
name|Form
operator|<
literal|3
condition|;
name|Form
operator|++
control|)
if|if
condition|(
name|RegOpcodes
index|[
name|Form
index|]
operator|==
name|RegOpcode
condition|)
return|return
name|MemOpcodes
index|[
name|Form
index|]
return|;
return|return
literal|0
return|;
block|}
comment|/// Returns the 132 form of FMA register opcode.
name|unsigned
name|getReg132Opcode
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|RegOpcodes
operator|&&
literal|"The group does not have register opcodes."
argument_list|)
block|;
return|return
name|RegOpcodes
index|[
name|Form132
index|]
return|;
block|}
comment|/// Returns the 213 form of FMA register opcode.
name|unsigned
name|getReg213Opcode
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|RegOpcodes
operator|&&
literal|"The group does not have register opcodes."
argument_list|)
block|;
return|return
name|RegOpcodes
index|[
name|Form213
index|]
return|;
block|}
comment|/// Returns the 231 form of FMA register opcode.
name|unsigned
name|getReg231Opcode
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|RegOpcodes
operator|&&
literal|"The group does not have register opcodes."
argument_list|)
block|;
return|return
name|RegOpcodes
index|[
name|Form231
index|]
return|;
block|}
comment|/// Returns the 132 form of FMA memory opcode.
name|unsigned
name|getMem132Opcode
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|MemOpcodes
operator|&&
literal|"The group does not have memory opcodes."
argument_list|)
block|;
return|return
name|MemOpcodes
index|[
name|Form132
index|]
return|;
block|}
comment|/// Returns the 213 form of FMA memory opcode.
name|unsigned
name|getMem213Opcode
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|MemOpcodes
operator|&&
literal|"The group does not have memory opcodes."
argument_list|)
block|;
return|return
name|MemOpcodes
index|[
name|Form213
index|]
return|;
block|}
comment|/// Returns the 231 form of FMA memory opcode.
name|unsigned
name|getMem231Opcode
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|MemOpcodes
operator|&&
literal|"The group does not have memory opcodes."
argument_list|)
block|;
return|return
name|MemOpcodes
index|[
name|Form231
index|]
return|;
block|}
comment|/// Returns true iff the group of FMA opcodes holds intrinsic opcodes.
name|bool
name|isIntrinsic
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Attributes
operator|&
name|X86FMA3Intrinsic
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// Returns true iff the group of FMA opcodes holds k-merge-masked opcodes.
name|bool
name|isKMergeMasked
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Attributes
operator|&
name|X86FMA3KMergeMasked
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// Returns true iff the group of FMA opcodes holds k-zero-masked opcodes.
name|bool
name|isKZeroMasked
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Attributes
operator|&
name|X86FMA3KZeroMasked
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// Returns true iff the group of FMA opcodes holds any of k-masked opcodes.
name|bool
name|isKMasked
argument_list|()
specifier|const
block|{
return|return
operator|(
name|Attributes
operator|&
operator|(
name|X86FMA3KMergeMasked
operator||
name|X86FMA3KZeroMasked
operator|)
operator|)
operator|!=
literal|0
return|;
block|}
comment|/// Returns true iff the given \p Opcode is a register opcode from the
comment|/// groups of FMA opcodes.
name|bool
name|isRegOpcodeFromGroup
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|RegOpcodes
condition|)
return|return
name|false
return|;
for|for
control|(
name|unsigned
name|Form
init|=
literal|0
init|;
name|Form
operator|<
literal|3
condition|;
name|Form
operator|++
control|)
if|if
condition|(
name|Opcode
operator|==
name|RegOpcodes
index|[
name|Form
index|]
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
comment|/// Returns true iff the given \p Opcode is a memory opcode from the
comment|/// groups of FMA opcodes.
name|bool
name|isMemOpcodeFromGroup
argument_list|(
name|unsigned
name|Opcode
argument_list|)
decl|const
block|{
if|if
condition|(
operator|!
name|MemOpcodes
condition|)
return|return
name|false
return|;
for|for
control|(
name|unsigned
name|Form
init|=
literal|0
init|;
name|Form
operator|<
literal|3
condition|;
name|Form
operator|++
control|)
if|if
condition|(
name|Opcode
operator|==
name|MemOpcodes
index|[
name|Form
index|]
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// This class provides information about all existing FMA3 opcodes
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|X86InstrFMA3Info
block|{
name|private
label|:
comment|/// A map that is used to find the group of FMA opcodes using any FMA opcode
comment|/// from the group.
name|DenseMap
operator|<
name|unsigned
operator|,
specifier|const
name|X86InstrFMA3Group
operator|*
operator|>
name|OpcodeToGroup
expr_stmt|;
comment|/// Creates groups of FMA opcodes and initializes Opcode-to-Group map.
comment|/// This method can be called many times, but the actual initialization is
comment|/// called only once.
specifier|static
name|void
name|initGroupsOnce
parameter_list|()
function_decl|;
comment|/// Creates groups of FMA opcodes and initializes Opcode-to-Group map.
comment|/// This method must be called ONLY from initGroupsOnce(). Otherwise, such
comment|/// call is not thread safe.
name|void
name|initGroupsOnceImpl
parameter_list|()
function_decl|;
comment|/// Creates one group of FMA opcodes having the register opcodes
comment|/// \p RegOpcodes and memory opcodes \p MemOpcodes. The parameter \p Attr
comment|/// specifies the attributes describing the created group.
name|void
name|initRMGroup
parameter_list|(
specifier|const
name|uint16_t
modifier|*
name|RegOpcodes
parameter_list|,
specifier|const
name|uint16_t
modifier|*
name|MemOpcodes
parameter_list|,
name|unsigned
name|Attr
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Creates one group of FMA opcodes having only the register opcodes
comment|/// \p RegOpcodes. The parameter \p Attr specifies the attributes describing
comment|/// the created group.
name|void
name|initRGroup
parameter_list|(
specifier|const
name|uint16_t
modifier|*
name|RegOpcodes
parameter_list|,
name|unsigned
name|Attr
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Creates one group of FMA opcodes having only the memory opcodes
comment|/// \p MemOpcodes. The parameter \p Attr specifies the attributes describing
comment|/// the created group.
name|void
name|initMGroup
parameter_list|(
specifier|const
name|uint16_t
modifier|*
name|MemOpcodes
parameter_list|,
name|unsigned
name|Attr
init|=
literal|0
parameter_list|)
function_decl|;
name|public
label|:
comment|/// Returns the reference to an object of this class. It is assumed that
comment|/// only one object may exist.
specifier|static
name|X86InstrFMA3Info
modifier|*
name|getX86InstrFMA3Info
parameter_list|()
function_decl|;
comment|/// Constructor. Just creates an object of the class.
name|X86InstrFMA3Info
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Destructor. Deallocates the memory used for FMA3 Groups.
operator|~
name|X86InstrFMA3Info
argument_list|()
block|{
name|std
operator|::
name|set
operator|<
specifier|const
name|X86InstrFMA3Group
operator|*
operator|>
name|DeletedGroups
block|;
name|auto
name|E
operator|=
name|OpcodeToGroup
operator|.
name|end
argument_list|()
block|;
for|for
control|(
name|auto
name|I
init|=
name|OpcodeToGroup
operator|.
name|begin
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
name|I
operator|++
control|)
block|{
specifier|const
name|X86InstrFMA3Group
modifier|*
name|G
init|=
name|I
operator|->
name|second
decl_stmt|;
if|if
condition|(
name|DeletedGroups
operator|.
name|find
argument_list|(
name|G
argument_list|)
operator|==
name|DeletedGroups
operator|.
name|end
argument_list|()
condition|)
block|{
name|DeletedGroups
operator|.
name|insert
argument_list|(
name|G
argument_list|)
expr_stmt|;
name|delete
name|G
decl_stmt|;
block|}
block|}
block|}
comment|/// Returns a reference to a group of FMA3 opcodes to where the given
comment|/// \p Opcode is included. If the given \p Opcode is not recognized as FMA3
comment|/// and not included into any FMA3 group, then nullptr is returned.
specifier|static
specifier|const
name|X86InstrFMA3Group
operator|*
name|getFMA3Group
argument_list|(
argument|unsigned Opcode
argument_list|)
block|{
comment|// Ensure that the groups of opcodes are initialized.
name|initGroupsOnce
argument_list|()
block|;
comment|// Find the group including the given opcode.
specifier|const
name|X86InstrFMA3Info
operator|*
name|FMA3Info
operator|=
name|getX86InstrFMA3Info
argument_list|()
block|;
name|auto
name|I
operator|=
name|FMA3Info
operator|->
name|OpcodeToGroup
operator|.
name|find
argument_list|(
name|Opcode
argument_list|)
block|;
if|if
condition|(
name|I
operator|==
name|FMA3Info
operator|->
name|OpcodeToGroup
operator|.
name|end
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
name|I
operator|->
name|second
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Returns true iff the given \p Opcode is recognized as FMA3 by this class.
end_comment

begin_function
specifier|static
name|bool
name|isFMA3
parameter_list|(
name|unsigned
name|Opcode
parameter_list|)
block|{
return|return
name|getFMA3Group
argument_list|(
name|Opcode
argument_list|)
operator|!=
name|nullptr
return|;
block|}
end_function

begin_comment
comment|/// Iterator that is used to walk on FMA register opcodes having memory
end_comment

begin_comment
comment|/// form equivalents.
end_comment

begin_decl_stmt
name|class
name|rm_iterator
block|{
name|private
label|:
comment|/// Iterator associated with the OpcodeToGroup map. It must always be
comment|/// initialized with an entry from OpcodeToGroup for which I->first
comment|/// points to a register FMA opcode and I->second points to a group of
comment|/// FMA opcodes having memory form equivalent of I->first.
name|DenseMap
operator|<
name|unsigned
operator|,
specifier|const
name|X86InstrFMA3Group
operator|*
operator|>
operator|::
name|const_iterator
name|I
expr_stmt|;
name|public
label|:
comment|/// Constructor. Creates rm_iterator. The parameter \p I must be an
comment|/// iterator to OpcodeToGroup map entry having I->first pointing to
comment|/// register form FMA opcode and I->second pointing to a group of FMA
comment|/// opcodes holding memory form equivalent for I->fist.
name|rm_iterator
argument_list|(
argument|DenseMap<unsigned
argument_list|,
argument|const X86InstrFMA3Group *>::const_iterator I
argument_list|)
block|:
name|I
argument_list|(
argument|I
argument_list|)
block|{}
comment|/// Returns the register form FMA opcode.
name|unsigned
name|getRegOpcode
argument_list|()
specifier|const
block|{
return|return
name|I
operator|->
name|first
return|;
block|}
empty_stmt|;
comment|/// Returns the memory form equivalent opcode for FMA register opcode
comment|/// referenced by I->first.
name|unsigned
name|getMemOpcode
argument_list|()
specifier|const
block|{
name|unsigned
name|Opcode
operator|=
name|I
operator|->
name|first
block|;
specifier|const
name|X86InstrFMA3Group
operator|*
name|Group
operator|=
name|I
operator|->
name|second
block|;
return|return
name|Group
operator|->
name|getMemOpcode
argument_list|(
name|Opcode
argument_list|)
return|;
block|}
comment|/// Returns a reference to a group of FMA opcodes.
specifier|const
name|X86InstrFMA3Group
operator|*
name|getGroup
argument_list|()
specifier|const
block|{
return|return
name|I
operator|->
name|second
return|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|rm_iterator
operator|&
name|OtherIt
operator|)
specifier|const
block|{
return|return
name|I
operator|==
name|OtherIt
operator|.
name|I
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|rm_iterator
operator|&
name|OtherIt
operator|)
specifier|const
block|{
return|return
name|I
operator|!=
name|OtherIt
operator|.
name|I
return|;
block|}
comment|/// Increment. Advances the 'I' iterator to the next OpcodeToGroup entry
comment|/// having I->first pointing to register form FMA and I->second pointing
comment|/// to a group of FMA opcodes holding memory form equivalen for I->first.
name|rm_iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|auto
name|E
operator|=
name|getX86InstrFMA3Info
argument_list|()
operator|->
name|OpcodeToGroup
operator|.
name|end
argument_list|()
block|;
for|for
control|(
operator|++
name|I
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|unsigned
name|RegOpcode
init|=
name|I
operator|->
name|first
decl_stmt|;
specifier|const
name|X86InstrFMA3Group
modifier|*
name|Group
init|=
name|I
operator|->
name|second
decl_stmt|;
if|if
condition|(
name|Group
operator|->
name|getMemOpcode
argument_list|(
name|RegOpcode
argument_list|)
operator|!=
literal|0
condition|)
break|break;
block|}
return|return
operator|*
name|this
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Returns rm_iterator pointing to the first entry of OpcodeToGroup map
end_comment

begin_comment
comment|/// with a register FMA opcode having memory form opcode equivalent.
end_comment

begin_function
specifier|static
name|rm_iterator
name|rm_begin
parameter_list|()
block|{
name|initGroupsOnce
argument_list|()
expr_stmt|;
specifier|const
name|X86InstrFMA3Info
modifier|*
name|FMA3Info
init|=
name|getX86InstrFMA3Info
argument_list|()
decl_stmt|;
name|auto
name|I
init|=
name|FMA3Info
operator|->
name|OpcodeToGroup
operator|.
name|begin
argument_list|()
decl_stmt|;
name|auto
name|E
init|=
name|FMA3Info
operator|->
name|OpcodeToGroup
operator|.
name|end
argument_list|()
decl_stmt|;
while|while
condition|(
name|I
operator|!=
name|E
condition|)
block|{
name|unsigned
name|Opcode
init|=
name|I
operator|->
name|first
decl_stmt|;
specifier|const
name|X86InstrFMA3Group
modifier|*
name|G
init|=
name|I
operator|->
name|second
decl_stmt|;
if|if
condition|(
name|G
operator|->
name|getMemOpcode
argument_list|(
name|Opcode
argument_list|)
operator|!=
literal|0
condition|)
break|break;
name|I
operator|++
expr_stmt|;
block|}
return|return
name|rm_iterator
argument_list|(
name|I
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Returns the last rm_iterator.
end_comment

begin_function
specifier|static
name|rm_iterator
name|rm_end
parameter_list|()
block|{
name|initGroupsOnce
argument_list|()
expr_stmt|;
return|return
name|rm_iterator
argument_list|(
name|getX86InstrFMA3Info
argument_list|()
operator|->
name|OpcodeToGroup
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_LIB_TARGET_X86_UTILS_X86INSTRFMA3INFO_H
end_comment

end_unit

