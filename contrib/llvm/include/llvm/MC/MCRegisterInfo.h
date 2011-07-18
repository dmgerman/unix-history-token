begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=== MC/MCRegisterInfo.h - Target Register Description ---------*- C++ -*-===//
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
comment|// This file describes an abstract interface used to get information about a
end_comment

begin_comment
comment|// target machines register file.  This information is used for a variety of
end_comment

begin_comment
comment|// purposed, especially register allocation.
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
name|LLVM_MC_MCREGISTERINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCREGISTERINFO_H
end_define

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// MCRegisterDesc - This record contains all of the information known about
comment|/// a particular register.  The Overlaps field contains a pointer to a zero
comment|/// terminated array of registers that this register aliases, starting with
comment|/// itself. This is needed for architectures like X86 which have AL alias AX
comment|/// alias EAX. The SubRegs field is a zero terminated array of registers that
comment|/// are sub-registers of the specific register, e.g. AL, AH are sub-registers of
comment|/// AX. The SuperRegs field is a zero terminated array of registers that are
comment|/// super-registers of the specific register, e.g. RAX, EAX, are super-registers
comment|/// of AX.
comment|///
struct|struct
name|MCRegisterDesc
block|{
specifier|const
name|char
modifier|*
name|Name
decl_stmt|;
comment|// Printable name for the reg (for debugging)
specifier|const
name|unsigned
modifier|*
name|Overlaps
decl_stmt|;
comment|// Overlapping registers, described above
specifier|const
name|unsigned
modifier|*
name|SubRegs
decl_stmt|;
comment|// Sub-register set, described above
specifier|const
name|unsigned
modifier|*
name|SuperRegs
decl_stmt|;
comment|// Super-register set, described above
block|}
struct|;
comment|/// MCRegisterInfo base class - We assume that the target defines a static
comment|/// array of MCRegisterDesc objects that represent all of the machine
comment|/// registers that the target has.  As such, we simply have to track a pointer
comment|/// to this array so that we can turn register number into a register
comment|/// descriptor.
comment|///
comment|/// Note this class is designed to be a base class of TargetRegisterInfo, which
comment|/// is the interface used by codegen. However, specific targets *should never*
comment|/// specialize this class. MCRegisterInfo should only contain getters to access
comment|/// TableGen generated physical register data. It must not be extended with
comment|/// virtual methods.
comment|///
name|class
name|MCRegisterInfo
block|{
name|private
label|:
specifier|const
name|MCRegisterDesc
modifier|*
name|Desc
decl_stmt|;
comment|// Pointer to the descriptor array
name|unsigned
name|NumRegs
decl_stmt|;
comment|// Number of entries in the array
name|public
label|:
comment|/// InitMCRegisterInfo - Initialize MCRegisterInfo, called by TableGen
comment|/// auto-generated routines. *DO NOT USE*.
name|void
name|InitMCRegisterInfo
parameter_list|(
specifier|const
name|MCRegisterDesc
modifier|*
name|D
parameter_list|,
name|unsigned
name|NR
parameter_list|)
block|{
name|Desc
operator|=
name|D
expr_stmt|;
name|NumRegs
operator|=
name|NR
expr_stmt|;
block|}
specifier|const
name|MCRegisterDesc
modifier|&
name|operator
index|[]
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|RegNo
operator|<
name|NumRegs
operator|&&
literal|"Attempting to access record for invalid register number!"
argument_list|)
expr_stmt|;
return|return
name|Desc
index|[
name|RegNo
index|]
return|;
block|}
comment|/// Provide a get method, equivalent to [], but more useful if we have a
comment|/// pointer to this object.
comment|///
specifier|const
name|MCRegisterDesc
modifier|&
name|get
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|operator
index|[]
operator|(
name|RegNo
operator|)
return|;
block|}
comment|/// getAliasSet - Return the set of registers aliased by the specified
comment|/// register, or a null list of there are none.  The list returned is zero
comment|/// terminated.
comment|///
specifier|const
name|unsigned
modifier|*
name|getAliasSet
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
comment|// The Overlaps set always begins with Reg itself.
return|return
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|Overlaps
operator|+
literal|1
return|;
block|}
comment|/// getOverlaps - Return a list of registers that overlap Reg, including
comment|/// itself. This is the same as the alias set except Reg is included in the
comment|/// list.
comment|/// These are exactly the registers in { x | regsOverlap(x, Reg) }.
comment|///
specifier|const
name|unsigned
modifier|*
name|getOverlaps
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|Overlaps
return|;
block|}
comment|/// getSubRegisters - Return the list of registers that are sub-registers of
comment|/// the specified register, or a null list of there are none. The list
comment|/// returned is zero terminated and sorted according to super-sub register
comment|/// relations. e.g. X86::RAX's sub-register list is EAX, AX, AL, AH.
comment|///
specifier|const
name|unsigned
modifier|*
name|getSubRegisters
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|SubRegs
return|;
block|}
comment|/// getSuperRegisters - Return the list of registers that are super-registers
comment|/// of the specified register, or a null list of there are none. The list
comment|/// returned is zero terminated and sorted according to super-sub register
comment|/// relations. e.g. X86::AL's super-register list is AX, EAX, RAX.
comment|///
specifier|const
name|unsigned
modifier|*
name|getSuperRegisters
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|SuperRegs
return|;
block|}
comment|/// getName - Return the human-readable symbolic target-specific name for the
comment|/// specified physical register.
specifier|const
name|char
modifier|*
name|getName
argument_list|(
name|unsigned
name|RegNo
argument_list|)
decl|const
block|{
return|return
name|get
argument_list|(
name|RegNo
argument_list|)
operator|.
name|Name
return|;
block|}
comment|/// getNumRegs - Return the number of registers this target has (useful for
comment|/// sizing arrays holding per register information)
name|unsigned
name|getNumRegs
argument_list|()
specifier|const
block|{
return|return
name|NumRegs
return|;
block|}
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

