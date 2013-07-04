begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MachineLocation.h -------------------------------*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// The MachineMove class is used to represent abstract move operations in the
end_comment

begin_comment
comment|// prolog/epilog of a compiled function.  A collection of these objects can be
end_comment

begin_comment
comment|// used by a debug consumer to track the location of values when unwinding stack
end_comment

begin_comment
comment|// frames.
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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCSymbol
decl_stmt|;
name|class
name|MachineLocation
block|{
name|private
label|:
name|bool
name|IsRegister
decl_stmt|;
comment|// True if location is a register.
name|unsigned
name|Register
decl_stmt|;
comment|// gcc/gdb register number.
name|int
name|Offset
decl_stmt|;
comment|// Displacement if not register.
name|public
label|:
enum|enum
block|{
comment|// The target register number for an abstract frame pointer. The value is
comment|// an arbitrary value that doesn't collide with any real target register.
name|VirtualFP
init|=
operator|~
literal|0U
block|}
enum|;
name|MachineLocation
argument_list|()
operator|:
name|IsRegister
argument_list|(
name|false
argument_list|)
operator|,
name|Register
argument_list|(
literal|0
argument_list|)
operator|,
name|Offset
argument_list|(
literal|0
argument_list|)
block|{}
comment|/// Create a direct register location.
name|explicit
name|MachineLocation
argument_list|(
argument|unsigned R
argument_list|)
operator|:
name|IsRegister
argument_list|(
name|true
argument_list|)
operator|,
name|Register
argument_list|(
name|R
argument_list|)
operator|,
name|Offset
argument_list|(
literal|0
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
name|IsRegister
argument_list|(
name|false
argument_list|)
operator|,
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
comment|// Accessors
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
ifndef|#
directive|ifndef
name|NDEBUG
name|void
name|dump
parameter_list|()
function_decl|;
endif|#
directive|endif
block|}
empty_stmt|;
comment|/// MachineMove - This class represents the save or restore of a callee saved
comment|/// register that exception or debug info needs to know about.
name|class
name|MachineMove
block|{
name|private
label|:
comment|/// Label - Symbol for post-instruction address when result of move takes
comment|/// effect.
name|MCSymbol
modifier|*
name|Label
decl_stmt|;
comment|// Move to& from location.
name|MachineLocation
name|Destination
decl_stmt|,
name|Source
decl_stmt|;
name|public
label|:
name|MachineMove
argument_list|()
operator|:
name|Label
argument_list|(
literal|0
argument_list|)
block|{}
name|MachineMove
argument_list|(
name|MCSymbol
operator|*
name|label
argument_list|,
specifier|const
name|MachineLocation
operator|&
name|D
argument_list|,
specifier|const
name|MachineLocation
operator|&
name|S
argument_list|)
operator|:
name|Label
argument_list|(
name|label
argument_list|)
operator|,
name|Destination
argument_list|(
name|D
argument_list|)
operator|,
name|Source
argument_list|(
argument|S
argument_list|)
block|{}
comment|// Accessors
name|MCSymbol
operator|*
name|getLabel
argument_list|()
specifier|const
block|{
return|return
name|Label
return|;
block|}
specifier|const
name|MachineLocation
operator|&
name|getDestination
argument_list|()
specifier|const
block|{
return|return
name|Destination
return|;
block|}
specifier|const
name|MachineLocation
operator|&
name|getSource
argument_list|()
specifier|const
block|{
return|return
name|Source
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

