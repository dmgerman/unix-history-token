begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/ObjectCodeEmitter.h - Object Code Emitter -*- C++ -*-===//
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
comment|//  Generalized Object Code Emitter, works with ObjectModule and BinaryObject.
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
name|LLVM_CODEGEN_OBJECTCODEEMITTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_OBJECTCODEEMITTER_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineCodeEmitter.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BinaryObject
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
name|class
name|MachineCodeEmitter
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|MachineConstantPool
decl_stmt|;
name|class
name|MachineJumpTableInfo
decl_stmt|;
name|class
name|MachineModuleInfo
decl_stmt|;
name|class
name|ObjectCodeEmitter
range|:
name|public
name|MachineCodeEmitter
block|{
name|protected
operator|:
comment|/// Binary Object (Section or Segment) we are emitting to.
name|BinaryObject
operator|*
name|BO
block|;
comment|/// MBBLocations - This vector is a mapping from MBB ID's to their address.
comment|/// It is filled in by the StartMachineBasicBlock callback and queried by
comment|/// the getMachineBasicBlockAddress callback.
name|std
operator|::
name|vector
operator|<
name|uintptr_t
operator|>
name|MBBLocations
block|;
comment|/// LabelLocations - This vector is a mapping from Label ID's to their
comment|/// address.
name|std
operator|::
name|vector
operator|<
name|uintptr_t
operator|>
name|LabelLocations
block|;
comment|/// CPLocations - This is a map of constant pool indices to offsets from the
comment|/// start of the section for that constant pool index.
name|std
operator|::
name|vector
operator|<
name|uintptr_t
operator|>
name|CPLocations
block|;
comment|/// CPSections - This is a map of constant pool indices to the Section
comment|/// containing the constant pool entry for that index.
name|std
operator|::
name|vector
operator|<
name|uintptr_t
operator|>
name|CPSections
block|;
comment|/// JTLocations - This is a map of jump table indices to offsets from the
comment|/// start of the section for that jump table index.
name|std
operator|::
name|vector
operator|<
name|uintptr_t
operator|>
name|JTLocations
block|;
name|public
operator|:
name|ObjectCodeEmitter
argument_list|()
block|;
name|ObjectCodeEmitter
argument_list|(
name|BinaryObject
operator|*
name|bo
argument_list|)
block|;
name|virtual
operator|~
name|ObjectCodeEmitter
argument_list|()
block|;
comment|/// setBinaryObject - set the BinaryObject we are writting to
name|void
name|setBinaryObject
argument_list|(
name|BinaryObject
operator|*
name|bo
argument_list|)
block|;
comment|/// emitByte - This callback is invoked when a byte needs to be
comment|/// written to the data stream, without buffer overflow testing.
name|void
name|emitByte
argument_list|(
argument|uint8_t B
argument_list|)
block|;
comment|/// emitWordLE - This callback is invoked when a 32-bit word needs to be
comment|/// written to the data stream in little-endian format.
name|void
name|emitWordLE
argument_list|(
argument|uint32_t W
argument_list|)
block|;
comment|/// emitWordBE - This callback is invoked when a 32-bit word needs to be
comment|/// written to the data stream in big-endian format.
name|void
name|emitWordBE
argument_list|(
argument|uint32_t W
argument_list|)
block|;
comment|/// emitDWordLE - This callback is invoked when a 64-bit word needs to be
comment|/// written to the data stream in little-endian format.
name|void
name|emitDWordLE
argument_list|(
argument|uint64_t W
argument_list|)
block|;
comment|/// emitDWordBE - This callback is invoked when a 64-bit word needs to be
comment|/// written to the data stream in big-endian format.
name|void
name|emitDWordBE
argument_list|(
argument|uint64_t W
argument_list|)
block|;
comment|/// emitAlignment - Move the CurBufferPtr pointer up the the specified
comment|/// alignment (saturated to BufferEnd of course).
name|void
name|emitAlignment
argument_list|(
argument|unsigned Alignment =
literal|0
argument_list|,
argument|uint8_t fill =
literal|0
argument_list|)
block|;
comment|/// emitULEB128Bytes - This callback is invoked when a ULEB128 needs to be
comment|/// written to the data stream.
name|void
name|emitULEB128Bytes
argument_list|(
argument|uint64_t Value
argument_list|)
block|;
comment|/// emitSLEB128Bytes - This callback is invoked when a SLEB128 needs to be
comment|/// written to the data stream.
name|void
name|emitSLEB128Bytes
argument_list|(
argument|uint64_t Value
argument_list|)
block|;
comment|/// emitString - This callback is invoked when a String needs to be
comment|/// written to the data stream.
name|void
name|emitString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|String
argument_list|)
block|;
comment|/// getCurrentPCValue - This returns the address that the next emitted byte
comment|/// will be output to.
name|uintptr_t
name|getCurrentPCValue
argument_list|()
specifier|const
block|;
comment|/// getCurrentPCOffset - Return the offset from the start of the emitted
comment|/// buffer that we are currently writing to.
name|uintptr_t
name|getCurrentPCOffset
argument_list|()
specifier|const
block|;
comment|/// addRelocation - Whenever a relocatable address is needed, it should be
comment|/// noted with this interface.
name|void
name|addRelocation
argument_list|(
specifier|const
name|MachineRelocation
operator|&
name|relocation
argument_list|)
block|;
comment|/// earlyResolveAddresses - True if the code emitter can use symbol addresses
comment|/// during code emission time. The JIT is capable of doing this because it
comment|/// creates jump tables or constant pools in memory on the fly while the
comment|/// object code emitters rely on a linker to have real addresses and should
comment|/// use relocations instead.
name|bool
name|earlyResolveAddresses
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// startFunction - This callback is invoked when the specified function is
comment|/// about to be code generated.  This initializes the BufferBegin/End/Ptr
comment|/// fields.
name|virtual
name|void
name|startFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
operator|=
literal|0
block|;
comment|/// finishFunction - This callback is invoked when the specified function has
comment|/// finished code generation.  If a buffer overflow has occurred, this method
comment|/// returns true (the callee is required to try again), otherwise it returns
comment|/// false.
name|virtual
name|bool
name|finishFunction
argument_list|(
name|MachineFunction
operator|&
name|F
argument_list|)
operator|=
literal|0
block|;
comment|/// StartMachineBasicBlock - This should be called by the target when a new
comment|/// basic block is about to be emitted.  This way the MCE knows where the
comment|/// start of the block is, and can implement getMachineBasicBlockAddress.
name|virtual
name|void
name|StartMachineBasicBlock
argument_list|(
name|MachineBasicBlock
operator|*
name|MBB
argument_list|)
block|;
comment|/// getMachineBasicBlockAddress - Return the address of the specified
comment|/// MachineBasicBlock, only usable after the label for the MBB has been
comment|/// emitted.
name|virtual
name|uintptr_t
name|getMachineBasicBlockAddress
argument_list|(
argument|MachineBasicBlock *MBB
argument_list|)
specifier|const
block|;
comment|/// emitLabel - Emits a label
name|virtual
name|void
name|emitLabel
argument_list|(
argument|uint64_t LabelID
argument_list|)
operator|=
literal|0
block|;
comment|/// getLabelAddress - Return the address of the specified LabelID, only usable
comment|/// after the LabelID has been emitted.
name|virtual
name|uintptr_t
name|getLabelAddress
argument_list|(
argument|uint64_t LabelID
argument_list|)
specifier|const
operator|=
literal|0
block|;
comment|/// emitJumpTables - Emit all the jump tables for a given jump table info
comment|/// record to the appropriate section.
name|virtual
name|void
name|emitJumpTables
argument_list|(
name|MachineJumpTableInfo
operator|*
name|MJTI
argument_list|)
operator|=
literal|0
block|;
comment|/// getJumpTableEntryAddress - Return the address of the jump table with index
comment|/// 'Index' in the function that last called initJumpTableInfo.
name|virtual
name|uintptr_t
name|getJumpTableEntryAddress
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|/// emitConstantPool - For each constant pool entry, figure out which section
comment|/// the constant should live in, allocate space for it, and emit it to the
comment|/// Section data buffer.
name|virtual
name|void
name|emitConstantPool
argument_list|(
name|MachineConstantPool
operator|*
name|MCP
argument_list|)
operator|=
literal|0
block|;
comment|/// getConstantPoolEntryAddress - Return the address of the 'Index' entry in
comment|/// the constant pool that was last emitted with the emitConstantPool method.
name|virtual
name|uintptr_t
name|getConstantPoolEntryAddress
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|/// getConstantPoolEntrySection - Return the section of the 'Index' entry in
comment|/// the constant pool that was last emitted with the emitConstantPool method.
name|virtual
name|uintptr_t
name|getConstantPoolEntrySection
argument_list|(
argument|unsigned Index
argument_list|)
specifier|const
block|;
comment|/// Specifies the MachineModuleInfo object. This is used for exception handling
comment|/// purposes.
name|virtual
name|void
name|setModuleInfo
argument_list|(
name|MachineModuleInfo
operator|*
name|Info
argument_list|)
operator|=
literal|0
block|;
comment|// to be implemented or depreciated with MachineModuleInfo
block|}
decl_stmt|;
comment|// end class ObjectCodeEmitter
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

