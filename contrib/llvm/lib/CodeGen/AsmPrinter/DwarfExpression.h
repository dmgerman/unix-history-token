begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/DwarfExpression.h - Dwarf Compile Unit ---*- C++ -*--===//
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
comment|// This file contains support for writing dwarf compile unit.
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
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFEXPRESSION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_CODEGEN_ASMPRINTER_DWARFEXPRESSION_H
end_define

begin_include
include|#
directive|include
file|"llvm/IR/DebugInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmPrinter
decl_stmt|;
name|class
name|ByteStreamer
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|DwarfUnit
decl_stmt|;
name|class
name|DIELoc
decl_stmt|;
comment|/// Base class containing the logic for constructing DWARF expressions
comment|/// independently of whether they are emitted into a DIE or into a .debug_loc
comment|/// entry.
name|class
name|DwarfExpression
block|{
name|protected
label|:
specifier|const
name|AsmPrinter
modifier|&
name|AP
decl_stmt|;
comment|// Various convenience accessors that extract things out of AsmPrinter.
specifier|const
name|TargetRegisterInfo
operator|*
name|getTRI
argument_list|()
specifier|const
expr_stmt|;
name|unsigned
name|getDwarfVersion
argument_list|()
specifier|const
expr_stmt|;
name|public
label|:
name|DwarfExpression
argument_list|(
specifier|const
name|AsmPrinter
operator|&
name|AP
argument_list|)
operator|:
name|AP
argument_list|(
argument|AP
argument_list|)
block|{}
name|virtual
operator|~
name|DwarfExpression
argument_list|()
block|{}
comment|/// Output a dwarf operand and an optional assembler comment.
name|virtual
name|void
name|EmitOp
argument_list|(
argument|uint8_t Op
argument_list|,
argument|const char *Comment = nullptr
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// Emit a raw signed value.
name|virtual
name|void
name|EmitSigned
parameter_list|(
name|int
name|Value
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Emit a raw unsigned value.
name|virtual
name|void
name|EmitUnsigned
parameter_list|(
name|unsigned
name|Value
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Return whether the given machine register is the frame register in the
comment|/// current function.
name|virtual
name|bool
name|isFrameRegister
parameter_list|(
name|unsigned
name|MachineReg
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Emit a dwarf register operation.
name|void
name|AddReg
parameter_list|(
name|int
name|DwarfReg
parameter_list|,
specifier|const
name|char
modifier|*
name|Comment
init|=
name|nullptr
parameter_list|)
function_decl|;
comment|/// Emit an (double-)indirect dwarf register operation.
name|void
name|AddRegIndirect
parameter_list|(
name|int
name|DwarfReg
parameter_list|,
name|int
name|Offset
parameter_list|,
name|bool
name|Deref
init|=
name|false
parameter_list|)
function_decl|;
comment|/// Emit a dwarf register operation for describing
comment|/// - a small value occupying only part of a register or
comment|/// - a register representing only part of a value.
name|void
name|AddOpPiece
parameter_list|(
name|unsigned
name|SizeInBits
parameter_list|,
name|unsigned
name|OffsetInBits
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Emit a shift-right dwarf expression.
name|void
name|AddShr
parameter_list|(
name|unsigned
name|ShiftBy
parameter_list|)
function_decl|;
comment|/// Emit an indirect dwarf register operation for the given machine register.
comment|/// \return false if no DWARF register exists for MachineReg.
name|bool
name|AddMachineRegIndirect
parameter_list|(
name|unsigned
name|MachineReg
parameter_list|,
name|int
name|Offset
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// \brief Emit a partial DWARF register operation.
comment|/// \param MachineReg        the register
comment|/// \param PieceSizeInBits   size and
comment|/// \param PieceOffsetInBits offset of the piece in bits, if this is one
comment|///                          piece of an aggregate value.
comment|///
comment|/// If size and offset is zero an operation for the entire
comment|/// register is emitted: Some targets do not provide a DWARF
comment|/// register number for every register.  If this is the case, this
comment|/// function will attempt to emit a DWARF register by emitting a
comment|/// piece of a super-register or by piecing together multiple
comment|/// subregisters that alias the register.
comment|///
comment|/// \return false if no DWARF register exists for MachineReg.
name|bool
name|AddMachineRegPiece
parameter_list|(
name|unsigned
name|MachineReg
parameter_list|,
name|unsigned
name|PieceSizeInBits
init|=
literal|0
parameter_list|,
name|unsigned
name|PieceOffsetInBits
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Emit a signed constant.
name|void
name|AddSignedConstant
parameter_list|(
name|int
name|Value
parameter_list|)
function_decl|;
comment|/// Emit an unsigned constant.
name|void
name|AddUnsignedConstant
parameter_list|(
name|unsigned
name|Value
parameter_list|)
function_decl|;
comment|/// Emit an entire DIExpression on top of a machine register location.
comment|/// \param PieceOffsetInBits If this is one piece out of a fragmented
comment|/// location, this is the offset of the piece inside the entire variable.
comment|/// \return false if no DWARF register exists for MachineReg.
name|bool
name|AddMachineRegExpression
parameter_list|(
name|DIExpression
name|Expr
parameter_list|,
name|unsigned
name|MachineReg
parameter_list|,
name|unsigned
name|PieceOffsetInBits
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Emit a the operations in a DIExpression, starting from element I.
comment|/// \param PieceOffsetInBits If this is one piece out of a fragmented
comment|/// location, this is the offset of the piece inside the entire variable.
name|void
name|AddExpression
parameter_list|(
name|DIExpression
name|Expr
parameter_list|,
name|unsigned
name|PieceOffsetInBits
init|=
literal|0
parameter_list|,
name|unsigned
name|I
init|=
literal|0
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// DwarfExpression implementation for .debug_loc entries.
name|class
name|DebugLocDwarfExpression
range|:
name|public
name|DwarfExpression
block|{
name|ByteStreamer
operator|&
name|BS
block|;
name|public
operator|:
name|DebugLocDwarfExpression
argument_list|(
specifier|const
name|AsmPrinter
operator|&
name|AP
argument_list|,
name|ByteStreamer
operator|&
name|BS
argument_list|)
operator|:
name|DwarfExpression
argument_list|(
name|AP
argument_list|)
block|,
name|BS
argument_list|(
argument|BS
argument_list|)
block|{}
name|void
name|EmitOp
argument_list|(
argument|uint8_t Op
argument_list|,
argument|const char *Comment = nullptr
argument_list|)
name|override
block|;
name|void
name|EmitSigned
argument_list|(
argument|int Value
argument_list|)
name|override
block|;
name|void
name|EmitUnsigned
argument_list|(
argument|unsigned Value
argument_list|)
name|override
block|;
name|bool
name|isFrameRegister
argument_list|(
argument|unsigned MachineReg
argument_list|)
name|override
block|; }
decl_stmt|;
comment|/// DwarfExpression implementation for singular DW_AT_location.
name|class
name|DIEDwarfExpression
range|:
name|public
name|DwarfExpression
block|{
name|DwarfUnit
operator|&
name|DU
block|;
name|DIELoc
operator|&
name|DIE
block|;
name|public
operator|:
name|DIEDwarfExpression
argument_list|(
specifier|const
name|AsmPrinter
operator|&
name|AP
argument_list|,
name|DwarfUnit
operator|&
name|DU
argument_list|,
name|DIELoc
operator|&
name|DIE
argument_list|)
operator|:
name|DwarfExpression
argument_list|(
name|AP
argument_list|)
block|,
name|DU
argument_list|(
name|DU
argument_list|)
block|,
name|DIE
argument_list|(
argument|DIE
argument_list|)
block|{}
name|void
name|EmitOp
argument_list|(
argument|uint8_t Op
argument_list|,
argument|const char *Comment = nullptr
argument_list|)
name|override
block|;
name|void
name|EmitSigned
argument_list|(
argument|int Value
argument_list|)
name|override
block|;
name|void
name|EmitUnsigned
argument_list|(
argument|unsigned Value
argument_list|)
name|override
block|;
name|bool
name|isFrameRegister
argument_list|(
argument|unsigned MachineReg
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

