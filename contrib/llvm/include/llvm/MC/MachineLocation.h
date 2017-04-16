begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/MC/MachineLocation.h --------------------------------*- C++ -*-===//
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
comment|// The MachineLocation class is used to represent a simple location in a machine
end_comment

begin_comment
comment|// frame.  Locations will be one of two forms; a register or an address formed
end_comment

begin_comment
comment|// from a base address plus an offset.  Register indirection can be specified by
end_comment

begin_comment
comment|// explicitly passing an offset to the constructor.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_MC_MACHINELOCATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MACHINELOCATION_H
end_define

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineLocation
block|{
name|private
label|:
name|bool
name|IsRegister
init|=
name|false
decl_stmt|;
comment|// True if location is a register.
name|unsigned
name|Register
init|=
literal|0
decl_stmt|;
comment|// gcc/gdb register number.
name|int
name|Offset
init|=
literal|0
decl_stmt|;
comment|// Displacement if not register.
name|public
label|:
enum_decl|enum :
name|uint32_t
block|{
comment|// The target register number for an abstract frame pointer. The value is
comment|// an arbitrary value that doesn't collide with any real target register.
name|VirtualFP
init|=
operator|~
literal|0U
block|}
enum_decl|;
name|MachineLocation
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Create a direct register location.
name|explicit
name|MachineLocation
argument_list|(
argument|unsigned R
argument_list|)
block|:
name|IsRegister
argument_list|(
name|true
argument_list|)
operator|,
name|Register
argument_list|(
argument|R
argument_list|)
block|{}
comment|/// Create a register-indirect location with an offset.
name|MachineLocation
argument_list|(
argument|unsigned R
argument_list|,
argument|int O
argument_list|)
operator|:
name|Register
argument_list|(
name|R
argument_list|)
operator|,
name|Offset
argument_list|(
argument|O
argument_list|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MachineLocation
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|IsRegister
operator|==
name|Other
operator|.
name|IsRegister
operator|&&
name|Register
operator|==
name|Other
operator|.
name|Register
operator|&&
name|Offset
operator|==
name|Other
operator|.
name|Offset
return|;
block|}
comment|// Accessors.
comment|/// \return true iff this is a register-indirect location.
name|bool
name|isIndirect
argument_list|()
specifier|const
block|{
return|return
operator|!
name|IsRegister
return|;
block|}
name|bool
name|isReg
argument_list|()
specifier|const
block|{
return|return
name|IsRegister
return|;
block|}
name|unsigned
name|getReg
argument_list|()
specifier|const
block|{
return|return
name|Register
return|;
block|}
name|int
name|getOffset
argument_list|()
specifier|const
block|{
return|return
name|Offset
return|;
block|}
name|void
name|setIsRegister
parameter_list|(
name|bool
name|Is
parameter_list|)
block|{
name|IsRegister
operator|=
name|Is
expr_stmt|;
block|}
name|void
name|setRegister
parameter_list|(
name|unsigned
name|R
parameter_list|)
block|{
name|Register
operator|=
name|R
expr_stmt|;
block|}
name|void
name|setOffset
parameter_list|(
name|int
name|O
parameter_list|)
block|{
name|Offset
operator|=
name|O
expr_stmt|;
block|}
comment|/// Make this location a direct register location.
name|void
name|set
parameter_list|(
name|unsigned
name|R
parameter_list|)
block|{
name|IsRegister
operator|=
name|true
expr_stmt|;
name|Register
operator|=
name|R
expr_stmt|;
name|Offset
operator|=
literal|0
expr_stmt|;
block|}
comment|/// Make this location a register-indirect+offset location.
name|void
name|set
parameter_list|(
name|unsigned
name|R
parameter_list|,
name|int
name|O
parameter_list|)
block|{
name|IsRegister
operator|=
name|false
expr_stmt|;
name|Register
operator|=
name|R
expr_stmt|;
name|Offset
operator|=
name|O
expr_stmt|;
block|}
block|}
empty_stmt|;
specifier|inline
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|MachineLocation
operator|&
name|LHS
operator|,
specifier|const
name|MachineLocation
operator|&
name|RHS
operator|)
block|{
return|return
operator|!
operator|(
name|LHS
operator|==
name|RHS
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MACHINELOCATION_H
end_comment

end_unit

