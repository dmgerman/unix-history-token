begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/MachineRelocation.h - Target Relocation ----*- C++ -*-===//
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
comment|// This file defines the MachineRelocation class.
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
name|LLVM_CODEGEN_MACHINERELOCATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_MACHINERELOCATION_H
end_define

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|GlobalValue
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
comment|/// MachineRelocation - This represents a target-specific relocation value,
comment|/// produced by the code emitter.  This relocation is resolved after the has
comment|/// been emitted, either to an object file or to memory, when the target of the
comment|/// relocation can be resolved.
comment|///
comment|/// A relocation is made up of the following logical portions:
comment|///   1. An offset in the machine code buffer, the location to modify.
comment|///   2. A target specific relocation type (a number from 0 to 63).
comment|///   3. A symbol being referenced, either as a GlobalValue* or as a string.
comment|///   4. An optional constant value to be added to the reference.
comment|///   5. A bit, CanRewrite, which indicates to the JIT that a function stub is
comment|///      not needed for the relocation.
comment|///   6. An index into the GOT, if the target uses a GOT
comment|///
name|class
name|MachineRelocation
block|{
enum|enum
name|AddressType
block|{
name|isResult
block|,
comment|// Relocation has be transformed into its result pointer.
name|isGV
block|,
comment|// The Target.GV field is valid.
name|isIndirectSym
block|,
comment|// Relocation of an indirect symbol.
name|isBB
block|,
comment|// Relocation of BB address.
name|isExtSym
block|,
comment|// The Target.ExtSym field is valid.
name|isConstPool
block|,
comment|// Relocation of constant pool address.
name|isJumpTable
block|,
comment|// Relocation of jump table address.
name|isGOTIndex
comment|// The Target.GOTIndex field is valid.
block|}
enum|;
comment|/// Offset - This is the offset from the start of the code buffer of the
comment|/// relocation to perform.
name|uintptr_t
name|Offset
decl_stmt|;
comment|/// ConstantVal - A field that may be used by the target relocation type.
name|intptr_t
name|ConstantVal
decl_stmt|;
union|union
block|{
name|void
modifier|*
name|Result
decl_stmt|;
comment|// If this has been resolved to a resolved pointer
name|GlobalValue
modifier|*
name|GV
decl_stmt|;
comment|// If this is a pointer to a GV or an indirect ref.
name|MachineBasicBlock
modifier|*
name|MBB
decl_stmt|;
comment|// If this is a pointer to a LLVM BB
specifier|const
name|char
modifier|*
name|ExtSym
decl_stmt|;
comment|// If this is a pointer to a named symbol
name|unsigned
name|Index
decl_stmt|;
comment|// Constant pool / jump table index
name|unsigned
name|GOTIndex
decl_stmt|;
comment|// Index in the GOT of this symbol/global
block|}
name|Target
union|;
name|unsigned
name|TargetReloType
range|:
literal|6
decl_stmt|;
comment|// The target relocation ID
name|AddressType
name|AddrType
range|:
literal|4
decl_stmt|;
comment|// The field of Target to use
name|bool
name|NeedStub
range|:
literal|1
decl_stmt|;
comment|// True if this relocation requires a stub
name|bool
name|GOTRelative
range|:
literal|1
decl_stmt|;
comment|// Should this relocation be relative to the GOT?
name|bool
name|TargetResolve
range|:
literal|1
decl_stmt|;
comment|// True if target should resolve the address
name|public
label|:
comment|// Relocation types used in a generic implementation.  Currently, relocation
comment|// entries for all things use the generic VANILLA type until they are refined
comment|// into target relocation types.
enum|enum
name|RelocationType
block|{
name|VANILLA
block|}
enum|;
comment|/// MachineRelocation::getGV - Return a relocation entry for a GlobalValue.
comment|///
specifier|static
name|MachineRelocation
name|getGV
parameter_list|(
name|uintptr_t
name|offset
parameter_list|,
name|unsigned
name|RelocationType
parameter_list|,
name|GlobalValue
modifier|*
name|GV
parameter_list|,
name|intptr_t
name|cst
init|=
literal|0
parameter_list|,
name|bool
name|NeedStub
init|=
literal|0
parameter_list|,
name|bool
name|GOTrelative
init|=
literal|0
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|RelocationType
operator|&
operator|~
literal|63
operator|)
operator|==
literal|0
operator|&&
literal|"Relocation type too large!"
argument_list|)
expr_stmt|;
name|MachineRelocation
name|Result
decl_stmt|;
name|Result
operator|.
name|Offset
operator|=
name|offset
expr_stmt|;
name|Result
operator|.
name|ConstantVal
operator|=
name|cst
expr_stmt|;
name|Result
operator|.
name|TargetReloType
operator|=
name|RelocationType
expr_stmt|;
name|Result
operator|.
name|AddrType
operator|=
name|isGV
expr_stmt|;
name|Result
operator|.
name|NeedStub
operator|=
name|NeedStub
expr_stmt|;
name|Result
operator|.
name|GOTRelative
operator|=
name|GOTrelative
expr_stmt|;
name|Result
operator|.
name|TargetResolve
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|Target
operator|.
name|GV
operator|=
name|GV
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// MachineRelocation::getIndirectSymbol - Return a relocation entry for an
comment|/// indirect symbol.
specifier|static
name|MachineRelocation
name|getIndirectSymbol
parameter_list|(
name|uintptr_t
name|offset
parameter_list|,
name|unsigned
name|RelocationType
parameter_list|,
name|GlobalValue
modifier|*
name|GV
parameter_list|,
name|intptr_t
name|cst
init|=
literal|0
parameter_list|,
name|bool
name|NeedStub
init|=
literal|0
parameter_list|,
name|bool
name|GOTrelative
init|=
literal|0
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|RelocationType
operator|&
operator|~
literal|63
operator|)
operator|==
literal|0
operator|&&
literal|"Relocation type too large!"
argument_list|)
expr_stmt|;
name|MachineRelocation
name|Result
decl_stmt|;
name|Result
operator|.
name|Offset
operator|=
name|offset
expr_stmt|;
name|Result
operator|.
name|ConstantVal
operator|=
name|cst
expr_stmt|;
name|Result
operator|.
name|TargetReloType
operator|=
name|RelocationType
expr_stmt|;
name|Result
operator|.
name|AddrType
operator|=
name|isIndirectSym
expr_stmt|;
name|Result
operator|.
name|NeedStub
operator|=
name|NeedStub
expr_stmt|;
name|Result
operator|.
name|GOTRelative
operator|=
name|GOTrelative
expr_stmt|;
name|Result
operator|.
name|TargetResolve
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|Target
operator|.
name|GV
operator|=
name|GV
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// MachineRelocation::getBB - Return a relocation entry for a BB.
comment|///
specifier|static
name|MachineRelocation
name|getBB
parameter_list|(
name|uintptr_t
name|offset
parameter_list|,
name|unsigned
name|RelocationType
parameter_list|,
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|intptr_t
name|cst
init|=
literal|0
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|RelocationType
operator|&
operator|~
literal|63
operator|)
operator|==
literal|0
operator|&&
literal|"Relocation type too large!"
argument_list|)
expr_stmt|;
name|MachineRelocation
name|Result
decl_stmt|;
name|Result
operator|.
name|Offset
operator|=
name|offset
expr_stmt|;
name|Result
operator|.
name|ConstantVal
operator|=
name|cst
expr_stmt|;
name|Result
operator|.
name|TargetReloType
operator|=
name|RelocationType
expr_stmt|;
name|Result
operator|.
name|AddrType
operator|=
name|isBB
expr_stmt|;
name|Result
operator|.
name|NeedStub
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|GOTRelative
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|TargetResolve
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|Target
operator|.
name|MBB
operator|=
name|MBB
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// MachineRelocation::getExtSym - Return a relocation entry for an external
comment|/// symbol, like "free".
comment|///
specifier|static
name|MachineRelocation
name|getExtSym
parameter_list|(
name|uintptr_t
name|offset
parameter_list|,
name|unsigned
name|RelocationType
parameter_list|,
specifier|const
name|char
modifier|*
name|ES
parameter_list|,
name|intptr_t
name|cst
init|=
literal|0
parameter_list|,
name|bool
name|GOTrelative
init|=
literal|0
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|RelocationType
operator|&
operator|~
literal|63
operator|)
operator|==
literal|0
operator|&&
literal|"Relocation type too large!"
argument_list|)
expr_stmt|;
name|MachineRelocation
name|Result
decl_stmt|;
name|Result
operator|.
name|Offset
operator|=
name|offset
expr_stmt|;
name|Result
operator|.
name|ConstantVal
operator|=
name|cst
expr_stmt|;
name|Result
operator|.
name|TargetReloType
operator|=
name|RelocationType
expr_stmt|;
name|Result
operator|.
name|AddrType
operator|=
name|isExtSym
expr_stmt|;
name|Result
operator|.
name|NeedStub
operator|=
name|true
expr_stmt|;
name|Result
operator|.
name|GOTRelative
operator|=
name|GOTrelative
expr_stmt|;
name|Result
operator|.
name|TargetResolve
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|Target
operator|.
name|ExtSym
operator|=
name|ES
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// MachineRelocation::getConstPool - Return a relocation entry for a constant
comment|/// pool entry.
comment|///
specifier|static
name|MachineRelocation
name|getConstPool
parameter_list|(
name|uintptr_t
name|offset
parameter_list|,
name|unsigned
name|RelocationType
parameter_list|,
name|unsigned
name|CPI
parameter_list|,
name|intptr_t
name|cst
init|=
literal|0
parameter_list|,
name|bool
name|letTargetResolve
init|=
name|false
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|RelocationType
operator|&
operator|~
literal|63
operator|)
operator|==
literal|0
operator|&&
literal|"Relocation type too large!"
argument_list|)
expr_stmt|;
name|MachineRelocation
name|Result
decl_stmt|;
name|Result
operator|.
name|Offset
operator|=
name|offset
expr_stmt|;
name|Result
operator|.
name|ConstantVal
operator|=
name|cst
expr_stmt|;
name|Result
operator|.
name|TargetReloType
operator|=
name|RelocationType
expr_stmt|;
name|Result
operator|.
name|AddrType
operator|=
name|isConstPool
expr_stmt|;
name|Result
operator|.
name|NeedStub
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|GOTRelative
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|TargetResolve
operator|=
name|letTargetResolve
expr_stmt|;
name|Result
operator|.
name|Target
operator|.
name|Index
operator|=
name|CPI
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// MachineRelocation::getJumpTable - Return a relocation entry for a jump
comment|/// table entry.
comment|///
specifier|static
name|MachineRelocation
name|getJumpTable
parameter_list|(
name|uintptr_t
name|offset
parameter_list|,
name|unsigned
name|RelocationType
parameter_list|,
name|unsigned
name|JTI
parameter_list|,
name|intptr_t
name|cst
init|=
literal|0
parameter_list|,
name|bool
name|letTargetResolve
init|=
name|false
parameter_list|)
block|{
name|assert
argument_list|(
operator|(
name|RelocationType
operator|&
operator|~
literal|63
operator|)
operator|==
literal|0
operator|&&
literal|"Relocation type too large!"
argument_list|)
expr_stmt|;
name|MachineRelocation
name|Result
decl_stmt|;
name|Result
operator|.
name|Offset
operator|=
name|offset
expr_stmt|;
name|Result
operator|.
name|ConstantVal
operator|=
name|cst
expr_stmt|;
name|Result
operator|.
name|TargetReloType
operator|=
name|RelocationType
expr_stmt|;
name|Result
operator|.
name|AddrType
operator|=
name|isJumpTable
expr_stmt|;
name|Result
operator|.
name|NeedStub
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|GOTRelative
operator|=
name|false
expr_stmt|;
name|Result
operator|.
name|TargetResolve
operator|=
name|letTargetResolve
expr_stmt|;
name|Result
operator|.
name|Target
operator|.
name|Index
operator|=
name|JTI
expr_stmt|;
return|return
name|Result
return|;
block|}
comment|/// getMachineCodeOffset - Return the offset into the code buffer that the
comment|/// relocation should be performed.
name|intptr_t
name|getMachineCodeOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
comment|/// getRelocationType - Return the target-specific relocation ID for this
comment|/// relocation.
name|unsigned
name|getRelocationType
argument_list|()
specifier|const
block|{
return|return
name|TargetReloType
return|;
block|}
comment|/// getConstantVal - Get the constant value associated with this relocation.
comment|/// This is often an offset from the symbol.
comment|///
name|intptr_t
name|getConstantVal
argument_list|()
specifier|const
block|{
return|return
name|ConstantVal
return|;
block|}
comment|/// setConstantVal - Set the constant value associated with this relocation.
comment|/// This is often an offset from the symbol.
comment|///
name|void
name|setConstantVal
parameter_list|(
name|intptr_t
name|val
parameter_list|)
block|{
name|ConstantVal
operator|=
name|val
expr_stmt|;
block|}
comment|/// isGlobalValue - Return true if this relocation is a GlobalValue, as
comment|/// opposed to a constant string.
name|bool
name|isGlobalValue
argument_list|()
specifier|const
block|{
return|return
name|AddrType
operator|==
name|isGV
return|;
block|}
comment|/// isIndirectSymbol - Return true if this relocation is the address an
comment|/// indirect symbol
name|bool
name|isIndirectSymbol
argument_list|()
specifier|const
block|{
return|return
name|AddrType
operator|==
name|isIndirectSym
return|;
block|}
comment|/// isBasicBlock - Return true if this relocation is a basic block reference.
comment|///
name|bool
name|isBasicBlock
argument_list|()
specifier|const
block|{
return|return
name|AddrType
operator|==
name|isBB
return|;
block|}
comment|/// isExternalSymbol - Return true if this is a constant string.
comment|///
name|bool
name|isExternalSymbol
argument_list|()
specifier|const
block|{
return|return
name|AddrType
operator|==
name|isExtSym
return|;
block|}
comment|/// isConstantPoolIndex - Return true if this is a constant pool reference.
comment|///
name|bool
name|isConstantPoolIndex
argument_list|()
specifier|const
block|{
return|return
name|AddrType
operator|==
name|isConstPool
return|;
block|}
comment|/// isJumpTableIndex - Return true if this is a jump table reference.
comment|///
name|bool
name|isJumpTableIndex
argument_list|()
specifier|const
block|{
return|return
name|AddrType
operator|==
name|isJumpTable
return|;
block|}
comment|/// isGOTRelative - Return true the target wants the index into the GOT of
comment|/// the symbol rather than the address of the symbol.
name|bool
name|isGOTRelative
argument_list|()
specifier|const
block|{
return|return
name|GOTRelative
return|;
block|}
comment|/// doesntNeedStub - This function returns true if the JIT for this target
comment|/// target is capable of directly handling the relocated GlobalValue reference
comment|/// without using either a stub function or issuing an extra load to get the
comment|/// GV address.
name|bool
name|doesntNeedStub
argument_list|()
specifier|const
block|{
return|return
operator|!
name|NeedStub
return|;
block|}
comment|/// letTargetResolve - Return true if the target JITInfo is usually
comment|/// responsible for resolving the address of this relocation.
name|bool
name|letTargetResolve
argument_list|()
specifier|const
block|{
return|return
name|TargetResolve
return|;
block|}
comment|/// getGlobalValue - If this is a global value reference, return the
comment|/// referenced global.
name|GlobalValue
operator|*
name|getGlobalValue
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|(
name|isGlobalValue
argument_list|()
operator|||
name|isIndirectSymbol
argument_list|()
operator|)
operator|&&
literal|"This is not a global value reference!"
argument_list|)
block|;
return|return
name|Target
operator|.
name|GV
return|;
block|}
name|MachineBasicBlock
operator|*
name|getBasicBlock
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isBasicBlock
argument_list|()
operator|&&
literal|"This is not a basic block reference!"
argument_list|)
block|;
return|return
name|Target
operator|.
name|MBB
return|;
block|}
comment|/// getString - If this is a string value, return the string reference.
comment|///
specifier|const
name|char
operator|*
name|getExternalSymbol
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isExternalSymbol
argument_list|()
operator|&&
literal|"This is not an external symbol reference!"
argument_list|)
block|;
return|return
name|Target
operator|.
name|ExtSym
return|;
block|}
comment|/// getConstantPoolIndex - If this is a const pool reference, return
comment|/// the index into the constant pool.
name|unsigned
name|getConstantPoolIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isConstantPoolIndex
argument_list|()
operator|&&
literal|"This is not a constant pool reference!"
argument_list|)
block|;
return|return
name|Target
operator|.
name|Index
return|;
block|}
comment|/// getJumpTableIndex - If this is a jump table reference, return
comment|/// the index into the jump table.
name|unsigned
name|getJumpTableIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isJumpTableIndex
argument_list|()
operator|&&
literal|"This is not a jump table reference!"
argument_list|)
block|;
return|return
name|Target
operator|.
name|Index
return|;
block|}
comment|/// getResultPointer - Once this has been resolved to point to an actual
comment|/// address, this returns the pointer.
name|void
operator|*
name|getResultPointer
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|AddrType
operator|==
name|isResult
operator|&&
literal|"Result pointer isn't set yet!"
argument_list|)
block|;
return|return
name|Target
operator|.
name|Result
return|;
block|}
comment|/// setResultPointer - Set the result to the specified pointer value.
comment|///
name|void
name|setResultPointer
parameter_list|(
name|void
modifier|*
name|Ptr
parameter_list|)
block|{
name|Target
operator|.
name|Result
operator|=
name|Ptr
expr_stmt|;
name|AddrType
operator|=
name|isResult
expr_stmt|;
block|}
comment|/// setGOTIndex - Set the GOT index to a specific value.
name|void
name|setGOTIndex
parameter_list|(
name|unsigned
name|idx
parameter_list|)
block|{
name|AddrType
operator|=
name|isGOTIndex
expr_stmt|;
name|Target
operator|.
name|GOTIndex
operator|=
name|idx
expr_stmt|;
block|}
comment|/// getGOTIndex - Once this has been resolved to an entry in the GOT,
comment|/// this returns that index.  The index is from the lowest address entry
comment|/// in the GOT.
name|unsigned
name|getGOTIndex
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|AddrType
operator|==
name|isGOTIndex
argument_list|)
block|;
return|return
name|Target
operator|.
name|GOTIndex
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

