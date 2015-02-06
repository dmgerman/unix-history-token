begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_UnwindPlan_h
end_ifndef

begin_define
define|#
directive|define
name|liblldb_UnwindPlan_h
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Stream.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ConstString.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|// The UnwindPlan object specifies how to unwind out of a function - where
comment|// this function saves the caller's register values before modifying them
comment|// (for non-volatile aka saved registers) and how to find this frame's
comment|// Canonical Frame Address (CFA).
comment|// Most commonly, registers are saved on the stack, offset some bytes from
comment|// the Canonical Frame Address, or CFA, which is the starting address of
comment|// this function's stack frame (the CFA is same as the eh_frame's CFA,
comment|// whatever that may be on a given architecture).
comment|// The CFA address for the stack frame does not change during
comment|// the lifetime of the function.
comment|// Internally, the UnwindPlan is structured as a vector of register locations
comment|// organized by code address in the function, showing which registers have been
comment|// saved at that point and where they are saved.
comment|// It can be thought of as the expanded table form of the DWARF CFI
comment|// encoded information.
comment|// Other unwind information sources will be converted into UnwindPlans before
comment|// being added to a FuncUnwinders object.  The unwind source may be
comment|// an eh_frame FDE, a DWARF debug_frame FDE, or assembly language based
comment|// prologue analysis.
comment|// The UnwindPlan is the canonical form of this information that the unwinder
comment|// code will use when walking the stack.
name|class
name|UnwindPlan
block|{
name|public
label|:
name|class
name|Row
block|{
name|public
label|:
name|class
name|RegisterLocation
block|{
name|public
label|:
enum|enum
name|RestoreType
block|{
name|unspecified
block|,
comment|// not specified, we may be able to assume this
comment|// is the same register. gcc doesn't specify all
comment|// initial values so we really don't know...
name|undefined
block|,
comment|// reg is not available, e.g. volatile reg
name|same
block|,
comment|// reg is unchanged
name|atCFAPlusOffset
block|,
comment|// reg = deref(CFA + offset)
name|isCFAPlusOffset
block|,
comment|// reg = CFA + offset
name|inOtherRegister
block|,
comment|// reg = other reg
name|atDWARFExpression
block|,
comment|// reg = deref(eval(dwarf_expr))
name|isDWARFExpression
comment|// reg = eval(dwarf_expr)
block|}
enum|;
name|RegisterLocation
argument_list|()
operator|:
name|m_type
argument_list|(
name|unspecified
argument_list|)
operator|,
name|m_location
argument_list|()
block|{             }
name|bool
name|operator
operator|==
operator|(
specifier|const
name|RegisterLocation
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|RegisterLocation
operator|&
name|rhs
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|rhs
operator|)
return|;
block|}
name|void
name|SetUnspecified
parameter_list|()
block|{
name|m_type
operator|=
name|unspecified
expr_stmt|;
block|}
name|void
name|SetUndefined
parameter_list|()
block|{
name|m_type
operator|=
name|undefined
expr_stmt|;
block|}
name|void
name|SetSame
parameter_list|()
block|{
name|m_type
operator|=
name|same
expr_stmt|;
block|}
name|bool
name|IsSame
argument_list|()
specifier|const
block|{
return|return
name|m_type
operator|==
name|same
return|;
block|}
name|bool
name|IsUnspecified
argument_list|()
specifier|const
block|{
return|return
name|m_type
operator|==
name|unspecified
return|;
block|}
name|bool
name|IsCFAPlusOffset
argument_list|()
specifier|const
block|{
return|return
name|m_type
operator|==
name|isCFAPlusOffset
return|;
block|}
name|bool
name|IsAtCFAPlusOffset
argument_list|()
specifier|const
block|{
return|return
name|m_type
operator|==
name|atCFAPlusOffset
return|;
block|}
name|bool
name|IsInOtherRegister
argument_list|()
specifier|const
block|{
return|return
name|m_type
operator|==
name|inOtherRegister
return|;
block|}
name|bool
name|IsAtDWARFExpression
argument_list|()
specifier|const
block|{
return|return
name|m_type
operator|==
name|atDWARFExpression
return|;
block|}
name|bool
name|IsDWARFExpression
argument_list|()
specifier|const
block|{
return|return
name|m_type
operator|==
name|isDWARFExpression
return|;
block|}
name|void
name|SetAtCFAPlusOffset
parameter_list|(
name|int32_t
name|offset
parameter_list|)
block|{
name|m_type
operator|=
name|atCFAPlusOffset
expr_stmt|;
name|m_location
operator|.
name|offset
operator|=
name|offset
expr_stmt|;
block|}
name|void
name|SetIsCFAPlusOffset
parameter_list|(
name|int32_t
name|offset
parameter_list|)
block|{
name|m_type
operator|=
name|isCFAPlusOffset
expr_stmt|;
name|m_location
operator|.
name|offset
operator|=
name|offset
expr_stmt|;
block|}
name|void
name|SetInRegister
parameter_list|(
name|uint32_t
name|reg_num
parameter_list|)
block|{
name|m_type
operator|=
name|inOtherRegister
expr_stmt|;
name|m_location
operator|.
name|reg_num
operator|=
name|reg_num
expr_stmt|;
block|}
name|uint32_t
name|GetRegisterNumber
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_type
operator|==
name|inOtherRegister
condition|)
return|return
name|m_location
operator|.
name|reg_num
return|;
return|return
name|LLDB_INVALID_REGNUM
return|;
block|}
name|RestoreType
name|GetLocationType
argument_list|()
specifier|const
block|{
return|return
name|m_type
return|;
block|}
name|int32_t
name|GetOffset
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_type
operator|==
name|atCFAPlusOffset
operator|||
name|m_type
operator|==
name|isCFAPlusOffset
condition|)
return|return
name|m_location
operator|.
name|offset
return|;
return|return
literal|0
return|;
block|}
name|void
name|GetDWARFExpr
argument_list|(
specifier|const
name|uint8_t
operator|*
operator|*
name|opcodes
argument_list|,
name|uint16_t
operator|&
name|len
argument_list|)
decl|const
block|{
if|if
condition|(
name|m_type
operator|==
name|atDWARFExpression
operator|||
name|m_type
operator|==
name|isDWARFExpression
condition|)
block|{
operator|*
name|opcodes
operator|=
name|m_location
operator|.
name|expr
operator|.
name|opcodes
expr_stmt|;
name|len
operator|=
name|m_location
operator|.
name|expr
operator|.
name|length
expr_stmt|;
block|}
else|else
block|{
operator|*
name|opcodes
operator|=
name|NULL
expr_stmt|;
name|len
operator|=
literal|0
expr_stmt|;
block|}
block|}
name|void
name|SetAtDWARFExpression
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|opcodes
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
name|void
name|SetIsDWARFExpression
parameter_list|(
specifier|const
name|uint8_t
modifier|*
name|opcodes
parameter_list|,
name|uint32_t
name|len
parameter_list|)
function_decl|;
specifier|const
name|uint8_t
modifier|*
name|GetDWARFExpressionBytes
parameter_list|()
block|{
if|if
condition|(
name|m_type
operator|==
name|atDWARFExpression
operator|||
name|m_type
operator|==
name|isDWARFExpression
condition|)
return|return
name|m_location
operator|.
name|expr
operator|.
name|opcodes
return|;
return|return
name|NULL
return|;
block|}
name|int
name|GetDWARFExpressionLength
parameter_list|()
block|{
if|if
condition|(
name|m_type
operator|==
name|atDWARFExpression
operator|||
name|m_type
operator|==
name|isDWARFExpression
condition|)
return|return
name|m_location
operator|.
name|expr
operator|.
name|length
return|;
return|return
literal|0
return|;
block|}
name|void
name|Dump
argument_list|(
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|UnwindPlan
operator|*
name|unwind_plan
argument_list|,
specifier|const
name|UnwindPlan
operator|::
name|Row
operator|*
name|row
argument_list|,
name|Thread
operator|*
name|thread
argument_list|,
name|bool
name|verbose
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|RestoreType
name|m_type
decl_stmt|;
comment|// How do we locate this register?
union|union
block|{
comment|// For m_type == atCFAPlusOffset or m_type == isCFAPlusOffset
name|int32_t
name|offset
decl_stmt|;
comment|// For m_type == inOtherRegister
name|uint32_t
name|reg_num
decl_stmt|;
comment|// The register number
comment|// For m_type == atDWARFExpression or m_type == isDWARFExpression
struct|struct
block|{
specifier|const
name|uint8_t
modifier|*
name|opcodes
decl_stmt|;
name|uint16_t
name|length
decl_stmt|;
block|}
name|expr
struct|;
block|}
name|m_location
union|;
block|}
empty_stmt|;
name|public
label|:
name|Row
argument_list|()
expr_stmt|;
name|Row
argument_list|(
specifier|const
name|UnwindPlan
operator|::
name|Row
operator|&
name|rhs
argument_list|)
operator|:
name|m_offset
argument_list|(
name|rhs
operator|.
name|m_offset
argument_list|)
operator|,
name|m_cfa_type
argument_list|(
name|rhs
operator|.
name|m_cfa_type
argument_list|)
operator|,
name|m_cfa_reg_num
argument_list|(
name|rhs
operator|.
name|m_cfa_reg_num
argument_list|)
operator|,
name|m_cfa_offset
argument_list|(
name|rhs
operator|.
name|m_cfa_offset
argument_list|)
operator|,
name|m_register_locations
argument_list|(
argument|rhs.m_register_locations
argument_list|)
block|{         }
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Row
operator|&
name|rhs
operator|)
specifier|const
expr_stmt|;
name|bool
name|GetRegisterInfo
argument_list|(
name|uint32_t
name|reg_num
argument_list|,
name|RegisterLocation
operator|&
name|register_location
argument_list|)
decl|const
decl_stmt|;
name|void
name|SetRegisterInfo
parameter_list|(
name|uint32_t
name|reg_num
parameter_list|,
specifier|const
name|RegisterLocation
name|register_location
parameter_list|)
function_decl|;
name|void
name|RemoveRegisterInfo
parameter_list|(
name|uint32_t
name|reg_num
parameter_list|)
function_decl|;
name|lldb
operator|::
name|addr_t
name|GetOffset
argument_list|()
specifier|const
block|{
return|return
name|m_offset
return|;
block|}
name|void
name|SetOffset
argument_list|(
name|lldb
operator|::
name|addr_t
name|offset
argument_list|)
block|{
name|m_offset
operator|=
name|offset
expr_stmt|;
block|}
name|void
name|SlideOffset
argument_list|(
name|lldb
operator|::
name|addr_t
name|offset
argument_list|)
block|{
name|m_offset
operator|+=
name|offset
expr_stmt|;
block|}
comment|// How we can reconstruct the CFA address for this stack frame, at this location
enum|enum
name|CFAType
block|{
name|CFAIsRegisterPlusOffset
block|,
comment|// the CFA value in a register plus (or minus) an offset
name|CFAIsRegisterDereferenced
comment|// the address in a register is dereferenced to get CFA value
block|}
enum|;
name|CFAType
name|GetCFAType
argument_list|()
specifier|const
block|{
return|return
name|m_cfa_type
return|;
block|}
name|void
name|SetCFAType
parameter_list|(
name|CFAType
name|cfa_type
parameter_list|)
block|{
name|m_cfa_type
operator|=
name|cfa_type
expr_stmt|;
block|}
comment|// If GetCFAType() is CFAIsRegisterPlusOffset, add GetCFAOffset to the reg value to get CFA value
comment|// If GetCFAType() is CFAIsRegisterDereferenced, dereference the addr in the reg to get CFA value
name|uint32_t
name|GetCFARegister
argument_list|()
specifier|const
block|{
return|return
name|m_cfa_reg_num
return|;
block|}
name|void
name|SetCFARegister
parameter_list|(
name|uint32_t
name|reg_num
parameter_list|)
function_decl|;
comment|// This should not be used when GetCFAType() is CFAIsRegisterDereferenced; will return 0 in that case.
name|int32_t
name|GetCFAOffset
argument_list|()
specifier|const
block|{
return|return
name|m_cfa_offset
return|;
block|}
name|void
name|SetCFAOffset
parameter_list|(
name|int32_t
name|offset
parameter_list|)
block|{
name|m_cfa_offset
operator|=
name|offset
expr_stmt|;
block|}
name|bool
name|SetRegisterLocationToAtCFAPlusOffset
parameter_list|(
name|uint32_t
name|reg_num
parameter_list|,
name|int32_t
name|offset
parameter_list|,
name|bool
name|can_replace
parameter_list|)
function_decl|;
name|bool
name|SetRegisterLocationToIsCFAPlusOffset
parameter_list|(
name|uint32_t
name|reg_num
parameter_list|,
name|int32_t
name|offset
parameter_list|,
name|bool
name|can_replace
parameter_list|)
function_decl|;
name|bool
name|SetRegisterLocationToUndefined
parameter_list|(
name|uint32_t
name|reg_num
parameter_list|,
name|bool
name|can_replace
parameter_list|,
name|bool
name|can_replace_only_if_unspecified
parameter_list|)
function_decl|;
name|bool
name|SetRegisterLocationToUnspecified
parameter_list|(
name|uint32_t
name|reg_num
parameter_list|,
name|bool
name|can_replace
parameter_list|)
function_decl|;
name|bool
name|SetRegisterLocationToRegister
parameter_list|(
name|uint32_t
name|reg_num
parameter_list|,
name|uint32_t
name|other_reg_num
parameter_list|,
name|bool
name|can_replace
parameter_list|)
function_decl|;
name|bool
name|SetRegisterLocationToSame
parameter_list|(
name|uint32_t
name|reg_num
parameter_list|,
name|bool
name|must_replace
parameter_list|)
function_decl|;
name|void
name|Clear
parameter_list|()
function_decl|;
name|void
name|Dump
argument_list|(
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|UnwindPlan
operator|*
name|unwind_plan
argument_list|,
name|Thread
operator|*
name|thread
argument_list|,
name|lldb
operator|::
name|addr_t
name|base_addr
argument_list|)
decl|const
decl_stmt|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|uint32_t
operator|,
name|RegisterLocation
operator|>
name|collection
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|m_offset
expr_stmt|;
comment|// Offset into the function for this row
name|CFAType
name|m_cfa_type
decl_stmt|;
comment|// If m_cfa_type == CFAIsRegisterPlusOffset, the CFA address is computed as m_cfa_reg_num + m_cfa_offset
comment|// If m_cfa_type == CFAIsRegisterDereferenced, the CFA address is computed as *(m_cfa_reg_num) - i.e. the
comment|// address in m_cfa_reg_num is dereferenced and the pointer value read is the CFA addr.
name|uint32_t
name|m_cfa_reg_num
decl_stmt|;
comment|// The Call Frame Address register number
name|int32_t
name|m_cfa_offset
decl_stmt|;
comment|// The offset from the CFA for this row
name|collection
name|m_register_locations
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// class Row
end_comment

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|std
operator|::
name|shared_ptr
operator|<
name|Row
operator|>
name|RowSP
expr_stmt|;
end_typedef

begin_macro
name|UnwindPlan
argument_list|(
argument|lldb::RegisterKind reg_kind
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|m_row_list
argument_list|()
operator|,
name|m_plan_valid_address_range
argument_list|()
operator|,
name|m_register_kind
argument_list|(
name|reg_kind
argument_list|)
operator|,
name|m_return_addr_register
argument_list|(
name|LLDB_INVALID_REGNUM
argument_list|)
operator|,
name|m_source_name
argument_list|()
operator|,
name|m_plan_is_sourced_from_compiler
argument_list|(
name|eLazyBoolCalculate
argument_list|)
operator|,
name|m_plan_is_valid_at_all_instruction_locations
argument_list|(
name|eLazyBoolCalculate
argument_list|)
operator|,
name|m_lsda_address
argument_list|()
operator|,
name|m_personality_func_addr
argument_list|()
block|{     }
operator|~
name|UnwindPlan
argument_list|()
block|{ 	}
name|void
name|Dump
argument_list|(
argument|Stream& s
argument_list|,
argument|Thread* thread
argument_list|,
argument|lldb::addr_t base_addr
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|AppendRow
parameter_list|(
specifier|const
name|RowSP
modifier|&
name|row_sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|InsertRow
parameter_list|(
specifier|const
name|RowSP
modifier|&
name|row_sp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Returns a pointer to the best row for the given offset into the function's instructions.
end_comment

begin_comment
comment|// If offset is -1 it indicates that the function start is unknown - the final row in the UnwindPlan is returned.
end_comment

begin_comment
comment|// In practice, the UnwindPlan for a function with no known start address will be the architectural default
end_comment

begin_comment
comment|// UnwindPlan which will only have one row.
end_comment

begin_expr_stmt
name|UnwindPlan
operator|::
name|RowSP
name|GetRowForFunctionOffset
argument_list|(
argument|int offset
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb
operator|::
name|RegisterKind
name|GetRegisterKind
argument_list|()
specifier|const
block|{
return|return
name|m_register_kind
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|SetRegisterKind
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|kind
argument_list|)
block|{
name|m_register_kind
operator|=
name|kind
expr_stmt|;
block|}
end_decl_stmt

begin_function
name|void
name|SetReturnAddressRegister
parameter_list|(
name|uint32_t
name|regnum
parameter_list|)
block|{
name|m_return_addr_register
operator|=
name|regnum
expr_stmt|;
block|}
end_function

begin_function
name|uint32_t
name|GetReturnAddressRegister
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|m_return_addr_register
return|;
block|}
end_function

begin_expr_stmt
name|uint32_t
name|GetInitialCFARegister
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_row_list
operator|.
name|empty
argument_list|()
condition|)
return|return
name|LLDB_INVALID_REGNUM
return|;
end_expr_stmt

begin_return
return|return
name|m_row_list
operator|.
name|front
argument_list|()
operator|->
name|GetCFARegister
argument_list|()
return|;
end_return

begin_comment
unit|}
comment|// This UnwindPlan may not be valid at every address of the function span.
end_comment

begin_comment
comment|// For instance, a FastUnwindPlan will not be valid at the prologue setup
end_comment

begin_comment
comment|// instructions - only in the body of the function.
end_comment

begin_expr_stmt
unit|void
name|SetPlanValidAddressRange
argument_list|(
specifier|const
name|AddressRange
operator|&
name|range
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|AddressRange
operator|&
name|GetAddressRange
argument_list|()
specifier|const
block|{
return|return
name|m_plan_valid_address_range
return|;
block|}
end_expr_stmt

begin_function_decl
name|bool
name|PlanValidAtAddress
parameter_list|(
name|Address
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|bool
name|IsValidRowIndex
argument_list|(
name|uint32_t
name|idx
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|UnwindPlan
operator|::
name|RowSP
name|GetRowAtIndex
argument_list|(
argument|uint32_t idx
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|UnwindPlan
operator|::
name|RowSP
name|GetLastRow
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|ConstString
name|GetSourceName
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|SetSourceName
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Was this UnwindPlan emitted by a compiler?
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|LazyBool
name|GetSourcedFromCompiler
argument_list|()
specifier|const
block|{
return|return
name|m_plan_is_sourced_from_compiler
return|;
block|}
end_expr_stmt

begin_comment
comment|// Was this UnwindPlan emitted by a compiler?
end_comment

begin_decl_stmt
name|void
name|SetSourcedFromCompiler
argument_list|(
name|lldb_private
operator|::
name|LazyBool
name|from_compiler
argument_list|)
block|{
name|m_plan_is_sourced_from_compiler
operator|=
name|from_compiler
expr_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// Is this UnwindPlan valid at all instructions?  If not, then it is assumed valid at call sites,
end_comment

begin_comment
comment|// e.g. for exception handling.
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|LazyBool
name|GetUnwindPlanValidAtAllInstructions
argument_list|()
specifier|const
block|{
return|return
name|m_plan_is_valid_at_all_instruction_locations
return|;
block|}
end_expr_stmt

begin_comment
comment|// Is this UnwindPlan valid at all instructions?  If not, then it is assumed valid at call sites,
end_comment

begin_comment
comment|// e.g. for exception handling.
end_comment

begin_decl_stmt
name|void
name|SetUnwindPlanValidAtAllInstructions
argument_list|(
name|lldb_private
operator|::
name|LazyBool
name|valid_at_all_insn
argument_list|)
block|{
name|m_plan_is_valid_at_all_instruction_locations
operator|=
name|valid_at_all_insn
expr_stmt|;
block|}
end_decl_stmt

begin_expr_stmt
name|int
name|GetRowCount
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_function
name|void
name|Clear
parameter_list|()
block|{
name|m_row_list
operator|.
name|clear
argument_list|()
expr_stmt|;
name|m_plan_valid_address_range
operator|.
name|Clear
argument_list|()
expr_stmt|;
name|m_register_kind
operator|=
name|lldb
operator|::
name|eRegisterKindDWARF
expr_stmt|;
name|m_source_name
operator|.
name|Clear
argument_list|()
expr_stmt|;
name|m_plan_is_sourced_from_compiler
operator|=
name|eLazyBoolCalculate
expr_stmt|;
name|m_plan_is_valid_at_all_instruction_locations
operator|=
name|eLazyBoolCalculate
expr_stmt|;
name|m_lsda_address
operator|.
name|Clear
argument_list|()
expr_stmt|;
name|m_personality_func_addr
operator|.
name|Clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_decl_stmt
specifier|const
name|RegisterInfo
modifier|*
name|GetRegisterInfo
argument_list|(
name|Thread
operator|*
name|thread
argument_list|,
name|uint32_t
name|reg_num
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Address
name|GetLSDAAddress
argument_list|()
specifier|const
block|{
return|return
name|m_lsda_address
return|;
block|}
end_expr_stmt

begin_function
name|void
name|SetLSDAAddress
parameter_list|(
name|Address
name|lsda_addr
parameter_list|)
block|{
name|m_lsda_address
operator|=
name|lsda_addr
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|Address
name|GetPersonalityFunctionPtr
argument_list|()
specifier|const
block|{
return|return
name|m_personality_func_addr
return|;
block|}
end_expr_stmt

begin_function
name|void
name|SetPersonalityFunctionPtr
parameter_list|(
name|Address
name|presonality_func_ptr
parameter_list|)
block|{
name|m_personality_func_addr
operator|=
name|presonality_func_ptr
expr_stmt|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|RowSP
operator|>
name|collection
expr_stmt|;
end_typedef

begin_decl_stmt
name|collection
name|m_row_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|AddressRange
name|m_plan_valid_address_range
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lldb
operator|::
name|RegisterKind
name|m_register_kind
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The RegisterKind these register numbers are in terms of - will need to be
end_comment

begin_comment
comment|// translated to lldb native reg nums at unwind time
end_comment

begin_decl_stmt
name|uint32_t
name|m_return_addr_register
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The register that has the return address for the caller frame
end_comment

begin_comment
comment|// e.g. the lr on arm
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|ConstString
name|m_source_name
expr_stmt|;
end_expr_stmt

begin_comment
comment|// for logging, where this UnwindPlan originated from
end_comment

begin_expr_stmt
name|lldb_private
operator|::
name|LazyBool
name|m_plan_is_sourced_from_compiler
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|lldb_private
operator|::
name|LazyBool
name|m_plan_is_valid_at_all_instruction_locations
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|Address
name|m_lsda_address
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Where the language specific data area exists in the module - used
end_comment

begin_comment
comment|// in exception handling.
end_comment

begin_decl_stmt
name|Address
name|m_personality_func_addr
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The address of a pointer to the personality function - used in
end_comment

begin_comment
comment|// exception handling.
end_comment

begin_comment
unit|};
comment|// class UnwindPlan
end_comment

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//liblldb_UnwindPlan_h
end_comment

end_unit

