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
comment|/// Holds a DIExpression and keeps track of how many operands have been consumed
comment|/// so far.
name|class
name|DIExpressionCursor
block|{
name|DIExpression
operator|::
name|expr_op_iterator
name|Start
operator|,
name|End
expr_stmt|;
name|public
label|:
name|DIExpressionCursor
argument_list|(
argument|const DIExpression *Expr
argument_list|)
block|{
if|if
condition|(
operator|!
name|Expr
condition|)
block|{
name|assert
argument_list|(
name|Start
operator|==
name|End
argument_list|)
expr_stmt|;
return|return;
block|}
name|Start
operator|=
name|Expr
operator|->
name|expr_op_begin
argument_list|()
expr_stmt|;
name|End
operator|=
name|Expr
operator|->
name|expr_op_end
argument_list|()
expr_stmt|;
block|}
name|DIExpressionCursor
argument_list|(
name|ArrayRef
operator|<
name|uint64_t
operator|>
name|Expr
argument_list|)
operator|:
name|Start
argument_list|(
name|Expr
operator|.
name|begin
argument_list|()
argument_list|)
operator|,
name|End
argument_list|(
argument|Expr.end()
argument_list|)
block|{}
comment|/// Consume one operation.
name|Optional
operator|<
name|DIExpression
operator|::
name|ExprOperand
operator|>
name|take
argument_list|()
block|{
if|if
condition|(
name|Start
operator|==
name|End
condition|)
return|return
name|None
return|;
return|return
operator|*
operator|(
name|Start
operator|++
operator|)
return|;
block|}
comment|/// Consume N operations.
name|void
name|consume
parameter_list|(
name|unsigned
name|N
parameter_list|)
block|{
name|std
operator|::
name|advance
argument_list|(
name|Start
argument_list|,
name|N
argument_list|)
expr_stmt|;
block|}
comment|/// Return the current operation.
name|Optional
operator|<
name|DIExpression
operator|::
name|ExprOperand
operator|>
name|peek
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Start
operator|==
name|End
condition|)
return|return
name|None
return|;
return|return
operator|*
operator|(
name|Start
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// Return the next operation.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|DIExpression
operator|::
name|ExprOperand
operator|>
name|peekNext
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Start
operator|==
name|End
condition|)
return|return
name|None
return|;
name|auto
name|Next
operator|=
name|Start
operator|.
name|getNext
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Next
operator|==
name|End
condition|)
return|return
name|None
return|;
end_if

begin_return
return|return
operator|*
name|Next
return|;
end_return

begin_comment
unit|}
comment|/// Determine whether there are any operations left in this expression.
end_comment

begin_macro
unit|operator
name|bool
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|Start
operator|!=
name|End
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|DIExpression
operator|::
name|expr_op_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|Start
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|DIExpression
operator|::
name|expr_op_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|End
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Retrieve the fragment information, if any.
end_comment

begin_expr_stmt
name|Optional
operator|<
name|DIExpression
operator|::
name|FragmentInfo
operator|>
name|getFragmentInfo
argument_list|()
specifier|const
block|{
return|return
name|DIExpression
operator|::
name|getFragmentInfo
argument_list|(
name|Start
argument_list|,
name|End
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// Base class containing the logic for constructing DWARF expressions
end_comment

begin_comment
comment|/// independently of whether they are emitted into a DIE or into a .debug_loc
end_comment

begin_comment
comment|/// entry.
end_comment

begin_decl_stmt
name|class
name|DwarfExpression
block|{
name|protected
label|:
comment|/// Holds information about all subregisters comprising a register location.
struct|struct
name|Register
block|{
name|int
name|DwarfRegNo
decl_stmt|;
name|unsigned
name|Size
decl_stmt|;
specifier|const
name|char
modifier|*
name|Comment
decl_stmt|;
block|}
struct|;
comment|/// The register location, if any.
name|SmallVector
operator|<
name|Register
operator|,
literal|2
operator|>
name|DwarfRegs
expr_stmt|;
comment|/// Current Fragment Offset in Bits.
name|uint64_t
name|OffsetInBits
init|=
literal|0
decl_stmt|;
name|unsigned
name|DwarfVersion
decl_stmt|;
comment|/// Sometimes we need to add a DW_OP_bit_piece to describe a subregister.
name|unsigned
name|SubRegisterSizeInBits
init|=
literal|0
decl_stmt|;
name|unsigned
name|SubRegisterOffsetInBits
init|=
literal|0
decl_stmt|;
comment|/// The kind of location description being produced.
enum|enum
block|{
name|Unknown
init|=
literal|0
block|,
name|Register
block|,
name|Memory
block|,
name|Implicit
block|}
name|LocationKind
init|=
name|Unknown
enum|;
comment|/// Push a DW_OP_piece / DW_OP_bit_piece for emitting later, if one is needed
comment|/// to represent a subregister.
name|void
name|setSubRegisterPiece
parameter_list|(
name|unsigned
name|SizeInBits
parameter_list|,
name|unsigned
name|OffsetInBits
parameter_list|)
block|{
name|SubRegisterSizeInBits
operator|=
name|SizeInBits
expr_stmt|;
name|SubRegisterOffsetInBits
operator|=
name|OffsetInBits
expr_stmt|;
block|}
comment|/// Add masking operations to stencil out a subregister.
name|void
name|maskSubRegister
parameter_list|()
function_decl|;
comment|/// Output a dwarf operand and an optional assembler comment.
name|virtual
name|void
name|emitOp
parameter_list|(
name|uint8_t
name|Op
parameter_list|,
specifier|const
name|char
modifier|*
name|Comment
init|=
name|nullptr
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Emit a raw signed value.
name|virtual
name|void
name|emitSigned
parameter_list|(
name|int64_t
name|Value
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Emit a raw unsigned value.
name|virtual
name|void
name|emitUnsigned
parameter_list|(
name|uint64_t
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
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
parameter_list|,
name|unsigned
name|MachineReg
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Emit a DW_OP_reg operation. Note that this is only legal inside a DWARF
comment|/// register location description.
name|void
name|addReg
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
comment|/// Emit a DW_OP_breg operation.
name|void
name|addBReg
parameter_list|(
name|int
name|DwarfReg
parameter_list|,
name|int
name|Offset
parameter_list|)
function_decl|;
comment|/// Emit DW_OP_fbreg<Offset>.
name|void
name|addFBReg
parameter_list|(
name|int
name|Offset
parameter_list|)
function_decl|;
comment|/// Emit a partial DWARF register operation.
comment|///
comment|/// \param MachineReg           The register number.
comment|/// \param MaxSize              If the register must be composed from
comment|///                             sub-registers this is an upper bound
comment|///                             for how many bits the emitted DW_OP_piece
comment|///                             may cover.
comment|///
comment|/// If size and offset is zero an operation for the entire register is
comment|/// emitted: Some targets do not provide a DWARF register number for every
comment|/// register.  If this is the case, this function will attempt to emit a DWARF
comment|/// register by emitting a fragment of a super-register or by piecing together
comment|/// multiple subregisters that alias the register.
comment|///
comment|/// \return false if no DWARF register exists for MachineReg.
name|bool
name|addMachineReg
parameter_list|(
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
parameter_list|,
name|unsigned
name|MachineReg
parameter_list|,
name|unsigned
name|MaxSize
init|=
operator|~
literal|1U
parameter_list|)
function_decl|;
comment|/// Emit a DW_OP_piece or DW_OP_bit_piece operation for a variable fragment.
comment|/// \param OffsetInBits    This is an optional offset into the location that
comment|/// is at the top of the DWARF stack.
name|void
name|addOpPiece
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
comment|/// Emit a shift-right dwarf operation.
name|void
name|addShr
parameter_list|(
name|unsigned
name|ShiftBy
parameter_list|)
function_decl|;
comment|/// Emit a bitwise and dwarf operation.
name|void
name|addAnd
parameter_list|(
name|unsigned
name|Mask
parameter_list|)
function_decl|;
comment|/// Emit a DW_OP_stack_value, if supported.
comment|///
comment|/// The proper way to describe a constant value is DW_OP_constu<const>,
comment|/// DW_OP_stack_value.  Unfortunately, DW_OP_stack_value was not available
comment|/// until DWARF 4, so we will continue to generate DW_OP_constu<const> for
comment|/// DWARF 2 and DWARF 3. Technically, this is incorrect since DW_OP_const
comment|///<const> actually describes a value at a constant addess, not a constant
comment|/// value.  However, in the past there was no better way to describe a
comment|/// constant value, so the producers and consumers started to rely on
comment|/// heuristics to disambiguate the value vs. location status of the
comment|/// expression.  See PR21176 for more details.
name|void
name|addStackValue
parameter_list|()
function_decl|;
operator|~
name|DwarfExpression
argument_list|()
operator|=
expr|default
expr_stmt|;
name|public
label|:
name|DwarfExpression
argument_list|(
argument|unsigned DwarfVersion
argument_list|)
block|:
name|DwarfVersion
argument_list|(
argument|DwarfVersion
argument_list|)
block|{}
comment|/// This needs to be called last to commit any pending changes.
name|void
name|finalize
parameter_list|()
function_decl|;
comment|/// Emit a signed constant.
name|void
name|addSignedConstant
parameter_list|(
name|int64_t
name|Value
parameter_list|)
function_decl|;
comment|/// Emit an unsigned constant.
name|void
name|addUnsignedConstant
parameter_list|(
name|uint64_t
name|Value
parameter_list|)
function_decl|;
comment|/// Emit an unsigned constant.
name|void
name|addUnsignedConstant
parameter_list|(
specifier|const
name|APInt
modifier|&
name|Value
parameter_list|)
function_decl|;
comment|/// Lock this down to become a memory location description.
name|void
name|setMemoryLocationKind
parameter_list|()
block|{
name|assert
argument_list|(
name|LocationKind
operator|==
name|Unknown
argument_list|)
expr_stmt|;
name|LocationKind
operator|=
name|Memory
expr_stmt|;
block|}
comment|/// Emit a machine register location. As an optimization this may also consume
comment|/// the prefix of a DwarfExpression if a more efficient representation for
comment|/// combining the register location and the first operation exists.
comment|///
comment|/// \param FragmentOffsetInBits     If this is one fragment out of a
comment|/// fragmented
comment|///                                 location, this is the offset of the
comment|///                                 fragment inside the entire variable.
comment|/// \return                         false if no DWARF register exists
comment|///                                 for MachineReg.
name|bool
name|addMachineRegExpression
parameter_list|(
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
parameter_list|,
name|DIExpressionCursor
modifier|&
name|Expr
parameter_list|,
name|unsigned
name|MachineReg
parameter_list|,
name|unsigned
name|FragmentOffsetInBits
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// Emit all remaining operations in the DIExpressionCursor.
comment|///
comment|/// \param FragmentOffsetInBits     If this is one fragment out of multiple
comment|///                                 locations, this is the offset of the
comment|///                                 fragment inside the entire variable.
name|void
name|addExpression
argument_list|(
name|DIExpressionCursor
operator|&&
name|Expr
argument_list|,
name|unsigned
name|FragmentOffsetInBits
operator|=
literal|0
argument_list|)
decl_stmt|;
comment|/// If applicable, emit an empty DW_OP_piece / DW_OP_bit_piece to advance to
comment|/// the fragment described by \c Expr.
name|void
name|addFragmentOffset
parameter_list|(
specifier|const
name|DIExpression
modifier|*
name|Expr
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// DwarfExpression implementation for .debug_loc entries.
end_comment

begin_decl_stmt
name|class
name|DebugLocDwarfExpression
name|final
range|:
name|public
name|DwarfExpression
block|{
name|ByteStreamer
operator|&
name|BS
block|;
name|void
name|emitOp
argument_list|(
argument|uint8_t Op
argument_list|,
argument|const char *Comment = nullptr
argument_list|)
name|override
block|;
name|void
name|emitSigned
argument_list|(
argument|int64_t Value
argument_list|)
name|override
block|;
name|void
name|emitUnsigned
argument_list|(
argument|uint64_t Value
argument_list|)
name|override
block|;
name|bool
name|isFrameRegister
argument_list|(
argument|const TargetRegisterInfo&TRI
argument_list|,
argument|unsigned MachineReg
argument_list|)
name|override
block|;
name|public
operator|:
name|DebugLocDwarfExpression
argument_list|(
argument|unsigned DwarfVersion
argument_list|,
argument|ByteStreamer&BS
argument_list|)
operator|:
name|DwarfExpression
argument_list|(
name|DwarfVersion
argument_list|)
block|,
name|BS
argument_list|(
argument|BS
argument_list|)
block|{}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// DwarfExpression implementation for singular DW_AT_location.
end_comment

begin_decl_stmt
name|class
name|DIEDwarfExpression
name|final
range|:
name|public
name|DwarfExpression
block|{
specifier|const
name|AsmPrinter
operator|&
name|AP
block|;
name|DwarfUnit
operator|&
name|DU
block|;
name|DIELoc
operator|&
name|DIE
block|;
name|void
name|emitOp
argument_list|(
argument|uint8_t Op
argument_list|,
argument|const char *Comment = nullptr
argument_list|)
name|override
block|;
name|void
name|emitSigned
argument_list|(
argument|int64_t Value
argument_list|)
name|override
block|;
name|void
name|emitUnsigned
argument_list|(
argument|uint64_t Value
argument_list|)
name|override
block|;
name|bool
name|isFrameRegister
argument_list|(
argument|const TargetRegisterInfo&TRI
argument_list|,
argument|unsigned MachineReg
argument_list|)
name|override
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
block|;
name|DIELoc
operator|*
name|finalize
argument_list|()
block|{
name|DwarfExpression
operator|::
name|finalize
argument_list|()
block|;
return|return
operator|&
name|DIE
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

