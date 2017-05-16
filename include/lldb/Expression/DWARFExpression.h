begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- DWARFExpression.h ---------------------------------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|liblldb_DWARFExpression_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_DWARFExpression_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/Address.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Disassembler.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Scalar.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/DataExtractor.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Status.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|class
name|DWARFCompileUnit
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ClangExpressionDeclMap
decl_stmt|;
name|class
name|ClangExpressionVariable
decl_stmt|;
name|class
name|ClangExpressionVariableList
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class DWARFExpression DWARFExpression.h "lldb/Expression/DWARFExpression.h"
comment|/// @brief Encapsulates a DWARF location expression and interprets it.
comment|///
comment|/// DWARF location expressions are used in two ways by LLDB.  The first
comment|/// use is to find entities specified in the debug information, since
comment|/// their locations are specified in precisely this language.  The second
comment|/// is to interpret expressions without having to run the target in cases
comment|/// where the overhead from copying JIT-compiled code into the target is
comment|/// too high or where the target cannot be run.  This class encapsulates
comment|/// a single DWARF location expression or a location list and interprets
comment|/// it.
comment|//----------------------------------------------------------------------
name|class
name|DWARFExpression
block|{
name|public
label|:
enum|enum
name|LocationListFormat
enum|:
name|uint8_t
block|{
name|NonLocationList
block|,
comment|// Not a location list
name|RegularLocationList
block|,
comment|// Location list format used in non-split dwarf files
name|SplitDwarfLocationList
block|,
comment|// Location list format used in split dwarf files
block|}
enum|;
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|//------------------------------------------------------------------
name|explicit
name|DWARFExpression
parameter_list|(
name|DWARFCompileUnit
modifier|*
name|dwarf_cu
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param[in] data
comment|///     A data extractor configured to read the DWARF location expression's
comment|///     bytecode.
comment|///
comment|/// @param[in] data_offset
comment|///     The offset of the location expression in the extractor.
comment|///
comment|/// @param[in] data_length
comment|///     The byte length of the location expression.
comment|//------------------------------------------------------------------
name|DWARFExpression
argument_list|(
argument|lldb::ModuleSP module
argument_list|,
argument|const DataExtractor&data
argument_list|,
argument|DWARFCompileUnit *dwarf_cu
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|lldb::offset_t data_length
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Copy constructor
comment|//------------------------------------------------------------------
name|DWARFExpression
argument_list|(
specifier|const
name|DWARFExpression
operator|&
name|rhs
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|DWARFExpression
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Print the description of the expression to a stream
comment|///
comment|/// @param[in] s
comment|///     The stream to print to.
comment|///
comment|/// @param[in] level
comment|///     The level of verbosity to use.
comment|///
comment|/// @param[in] location_list_base_addr
comment|///     If this is a location list based expression, this is the
comment|///     address of the object that owns it. NOTE: this value is
comment|///     different from the DWARF version of the location list base
comment|///     address which is compile unit relative. This base address
comment|///     is the address of the object that owns the location list.
comment|///
comment|/// @param[in] abi
comment|///     An optional ABI plug-in that can be used to resolve register
comment|///     names.
comment|//------------------------------------------------------------------
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|,
name|lldb
operator|::
name|addr_t
name|location_list_base_addr
argument_list|,
name|ABI
operator|*
name|abi
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return true if the location expression contains data
comment|//------------------------------------------------------------------
name|bool
name|IsValid
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return true if a location list was provided
comment|//------------------------------------------------------------------
name|bool
name|IsLocationList
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Search for a load address in the location list
comment|///
comment|/// @param[in] process
comment|///     The process to use when resolving the load address
comment|///
comment|/// @param[in] addr
comment|///     The address to resolve
comment|///
comment|/// @return
comment|///     True if IsLocationList() is true and the address was found;
comment|///     false otherwise.
comment|//------------------------------------------------------------------
comment|//    bool
comment|//    LocationListContainsLoadAddress (Process* process, const Address&addr)
comment|//    const;
comment|//
name|bool
name|LocationListContainsAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|loclist_base_addr
argument_list|,
name|lldb
operator|::
name|addr_t
name|addr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// If a location is not a location list, return true if the location
comment|/// contains a DW_OP_addr () opcode in the stream that matches \a
comment|/// file_addr. If file_addr is LLDB_INVALID_ADDRESS, the this
comment|/// function will return true if the variable there is any DW_OP_addr
comment|/// in a location that (yet still is NOT a location list). This helps
comment|/// us detect if a variable is a global or static variable since
comment|/// there is no other indication from DWARF debug info.
comment|///
comment|/// @param[in] op_addr_idx
comment|///     The DW_OP_addr index to retrieve in case there is more than
comment|///     one DW_OP_addr opcode in the location byte stream.
comment|///
comment|/// @param[out] error
comment|///     If the location stream contains unknown DW_OP opcodes or the
comment|///     data is missing, \a error will be set to \b true.
comment|///
comment|/// @return
comment|///     LLDB_INVALID_ADDRESS if the location doesn't contain a
comment|///     DW_OP_addr for \a op_addr_idx, otherwise a valid file address
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|addr_t
name|GetLocation_DW_OP_addr
argument_list|(
argument|uint32_t op_addr_idx
argument_list|,
argument|bool&error
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|Update_DW_OP_addr
argument_list|(
name|lldb
operator|::
name|addr_t
name|file_addr
argument_list|)
decl_stmt|;
name|bool
name|ContainsThreadLocalStorage
argument_list|()
specifier|const
expr_stmt|;
name|bool
name|LinkThreadLocalStorage
argument_list|(
name|lldb
operator|::
name|ModuleSP
name|new_module_sp
argument_list|,
name|std
operator|::
name|function
operator|<
name|lldb
operator|::
name|addr_t
argument_list|(
argument|lldb::addr_t file_addr
argument_list|)
operator|>
specifier|const
operator|&
name|link_address_callback
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Make the expression parser read its location information from a
comment|/// given data source.  Does not change the offset and length
comment|///
comment|/// @param[in] data
comment|///     A data extractor configured to read the DWARF location expression's
comment|///     bytecode.
comment|//------------------------------------------------------------------
name|void
name|SetOpcodeData
parameter_list|(
specifier|const
name|DataExtractor
modifier|&
name|data
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Make the expression parser read its location information from a
comment|/// given data source
comment|///
comment|/// @param[in] module_sp
comment|///     The module that defines the DWARF expression.
comment|///
comment|/// @param[in] data
comment|///     A data extractor configured to read the DWARF location expression's
comment|///     bytecode.
comment|///
comment|/// @param[in] data_offset
comment|///     The offset of the location expression in the extractor.
comment|///
comment|/// @param[in] data_length
comment|///     The byte length of the location expression.
comment|//------------------------------------------------------------------
name|void
name|SetOpcodeData
argument_list|(
name|lldb
operator|::
name|ModuleSP
name|module_sp
argument_list|,
specifier|const
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb
operator|::
name|offset_t
name|data_offset
argument_list|,
name|lldb
operator|::
name|offset_t
name|data_length
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Copy the DWARF location expression into a local buffer.
comment|///
comment|/// It is a good idea to copy the data so we don't keep the entire
comment|/// object file worth of data around just for a few bytes of location
comment|/// expression. LLDB typically will mmap the entire contents of debug
comment|/// information files, and if we use SetOpcodeData, it will get a
comment|/// shared reference to all of this data for the and cause the object
comment|/// file to have to stay around. Even worse, a very very large ".a"
comment|/// that contains one or more .o files could end up being referenced.
comment|/// Location lists are typically small so even though we are copying
comment|/// the data, it shouldn't amount to that much for the variables we
comment|/// end up parsing.
comment|///
comment|/// @param[in] module_sp
comment|///     The module that defines the DWARF expression.
comment|///
comment|/// @param[in] data
comment|///     A data extractor configured to read and copy the DWARF
comment|///     location expression's bytecode.
comment|///
comment|/// @param[in] data_offset
comment|///     The offset of the location expression in the extractor.
comment|///
comment|/// @param[in] data_length
comment|///     The byte length of the location expression.
comment|//------------------------------------------------------------------
name|void
name|CopyOpcodeData
argument_list|(
name|lldb
operator|::
name|ModuleSP
name|module_sp
argument_list|,
specifier|const
name|DataExtractor
operator|&
name|data
argument_list|,
name|lldb
operator|::
name|offset_t
name|data_offset
argument_list|,
name|lldb
operator|::
name|offset_t
name|data_length
argument_list|)
decl_stmt|;
name|void
name|CopyOpcodeData
argument_list|(
specifier|const
name|void
operator|*
name|data
argument_list|,
name|lldb
operator|::
name|offset_t
name|data_length
argument_list|,
name|lldb
operator|::
name|ByteOrder
name|byte_order
argument_list|,
name|uint8_t
name|addr_byte_size
argument_list|)
decl_stmt|;
name|void
name|CopyOpcodeData
argument_list|(
name|uint64_t
name|const_value
argument_list|,
name|lldb
operator|::
name|offset_t
name|const_value_byte_size
argument_list|,
name|uint8_t
name|addr_byte_size
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Tells the expression that it refers to a location list.
comment|///
comment|/// @param[in] slide
comment|///     This value should be a slide that is applied to any values
comment|///     in the location list data so the values become zero based
comment|///     offsets into the object that owns the location list. We need
comment|///     to make location lists relative to the objects that own them
comment|///     so we can relink addresses on the fly.
comment|//------------------------------------------------------------------
name|void
name|SetLocationListSlide
argument_list|(
name|lldb
operator|::
name|addr_t
name|slide
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Return the call-frame-info style register kind
comment|//------------------------------------------------------------------
name|int
name|GetRegisterKind
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Set the call-frame-info style register kind
comment|///
comment|/// @param[in] reg_kind
comment|///     The register kind.
comment|//------------------------------------------------------------------
name|void
name|SetRegisterKind
argument_list|(
name|lldb
operator|::
name|RegisterKind
name|reg_kind
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Wrapper for the static evaluate function that accepts an
comment|/// ExecutionContextScope instead of an ExecutionContext and uses
comment|/// member variables to populate many operands
comment|//------------------------------------------------------------------
name|bool
name|Evaluate
argument_list|(
name|ExecutionContextScope
operator|*
name|exe_scope
argument_list|,
name|ClangExpressionVariableList
operator|*
name|expr_locals
argument_list|,
name|ClangExpressionDeclMap
operator|*
name|decl_map
argument_list|,
name|lldb
operator|::
name|addr_t
name|loclist_base_load_addr
argument_list|,
specifier|const
name|Value
operator|*
name|initial_value_ptr
argument_list|,
specifier|const
name|Value
operator|*
name|object_address_ptr
argument_list|,
name|Value
operator|&
name|result
argument_list|,
name|Status
operator|*
name|error_ptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Wrapper for the static evaluate function that uses member
comment|/// variables to populate many operands
comment|//------------------------------------------------------------------
name|bool
name|Evaluate
argument_list|(
name|ExecutionContext
operator|*
name|exe_ctx
argument_list|,
name|ClangExpressionVariableList
operator|*
name|expr_locals
argument_list|,
name|ClangExpressionDeclMap
operator|*
name|decl_map
argument_list|,
name|RegisterContext
operator|*
name|reg_ctx
argument_list|,
name|lldb
operator|::
name|addr_t
name|loclist_base_load_addr
argument_list|,
specifier|const
name|Value
operator|*
name|initial_value_ptr
argument_list|,
specifier|const
name|Value
operator|*
name|object_address_ptr
argument_list|,
name|Value
operator|&
name|result
argument_list|,
name|Status
operator|*
name|error_ptr
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Evaluate a DWARF location expression in a particular context
comment|///
comment|/// @param[in] exe_ctx
comment|///     The execution context in which to evaluate the location
comment|///     expression.  The location expression may access the target's
comment|///     memory, especially if it comes from the expression parser.
comment|///
comment|/// @param[in] opcode_ctx
comment|///     The module which defined the expression.
comment|///
comment|/// @param[in] opcodes
comment|///     This is a static method so the opcodes need to be provided
comment|///     explicitly.
comment|///
comment|/// @param[in] expr_locals
comment|///     If the location expression was produced by the expression parser,
comment|///     the list of local variables referenced by the DWARF expression.
comment|///     This list should already have been populated during parsing;
comment|///     the DWARF expression refers to variables by index.  Can be NULL if
comment|///     the location expression uses no locals.
comment|///
comment|/// @param[in] decl_map
comment|///     If the location expression was produced by the expression parser,
comment|///     the list of external variables referenced by the location
comment|///     expression.  Can be NULL if the location expression uses no
comment|///     external variables.
comment|///
comment|///  @param[in] reg_ctx
comment|///     An optional parameter which provides a RegisterContext for use
comment|///     when evaluating the expression (i.e. for fetching register values).
comment|///     Normally this will come from the ExecutionContext's StackFrame but
comment|///     in the case where an expression needs to be evaluated while building
comment|///     the stack frame list, this short-cut is available.
comment|///
comment|/// @param[in] offset
comment|///     The offset of the location expression in the data extractor.
comment|///
comment|/// @param[in] length
comment|///     The length in bytes of the location expression.
comment|///
comment|/// @param[in] reg_set
comment|///     The call-frame-info style register kind.
comment|///
comment|/// @param[in] initial_value_ptr
comment|///     A value to put on top of the interpreter stack before evaluating
comment|///     the expression, if the expression is parametrized.  Can be NULL.
comment|///
comment|/// @param[in] result
comment|///     A value into which the result of evaluating the expression is
comment|///     to be placed.
comment|///
comment|/// @param[in] error_ptr
comment|///     If non-NULL, used to report errors in expression evaluation.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.  If error_ptr is non-NULL,
comment|///     details of the failure are provided through it.
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|Evaluate
argument_list|(
name|ExecutionContext
operator|*
name|exe_ctx
argument_list|,
name|ClangExpressionVariableList
operator|*
name|expr_locals
argument_list|,
name|ClangExpressionDeclMap
operator|*
name|decl_map
argument_list|,
name|RegisterContext
operator|*
name|reg_ctx
argument_list|,
name|lldb
operator|::
name|ModuleSP
name|opcode_ctx
argument_list|,
specifier|const
name|DataExtractor
operator|&
name|opcodes
argument_list|,
name|DWARFCompileUnit
operator|*
name|dwarf_cu
argument_list|,
specifier|const
name|lldb
operator|::
name|offset_t
name|offset
argument_list|,
specifier|const
name|lldb
operator|::
name|offset_t
name|length
argument_list|,
specifier|const
name|lldb
operator|::
name|RegisterKind
name|reg_set
argument_list|,
specifier|const
name|Value
operator|*
name|initial_value_ptr
argument_list|,
specifier|const
name|Value
operator|*
name|object_address_ptr
argument_list|,
name|Value
operator|&
name|result
argument_list|,
name|Status
operator|*
name|error_ptr
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Loads a ClangExpressionVariableList into the object
comment|///
comment|/// @param[in] locals
comment|///     If non-NULL, the list of locals used by this expression.
comment|///     See Evaluate().
comment|//------------------------------------------------------------------
name|void
name|SetExpressionLocalVariableList
parameter_list|(
name|ClangExpressionVariableList
modifier|*
name|locals
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Loads a ClangExpressionDeclMap into the object
comment|///
comment|/// @param[in] locals
comment|///     If non-NULL, the list of external variables used by this
comment|///     expression.  See Evaluate().
comment|//------------------------------------------------------------------
name|void
name|SetExpressionDeclMap
parameter_list|(
name|ClangExpressionDeclMap
modifier|*
name|decl_map
parameter_list|)
function_decl|;
name|bool
name|GetExpressionData
argument_list|(
name|DataExtractor
operator|&
name|data
argument_list|)
decl|const
block|{
name|data
operator|=
name|m_data
expr_stmt|;
return|return
name|data
operator|.
name|GetByteSize
argument_list|()
operator|>
literal|0
return|;
block|}
name|bool
name|DumpLocationForAddress
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|,
name|lldb
operator|::
name|addr_t
name|loclist_base_load_addr
argument_list|,
name|lldb
operator|::
name|addr_t
name|address
argument_list|,
name|ABI
operator|*
name|abi
argument_list|)
decl_stmt|;
specifier|static
name|size_t
name|LocationListSize
argument_list|(
specifier|const
name|DWARFCompileUnit
operator|*
name|dwarf_cu
argument_list|,
specifier|const
name|DataExtractor
operator|&
name|debug_loc_data
argument_list|,
name|lldb
operator|::
name|offset_t
name|offset
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|PrintDWARFExpression
parameter_list|(
name|Stream
modifier|&
name|s
parameter_list|,
specifier|const
name|DataExtractor
modifier|&
name|data
parameter_list|,
name|int
name|address_size
parameter_list|,
name|int
name|dwarf_ref_size
parameter_list|,
name|bool
name|location_expression
parameter_list|)
function_decl|;
specifier|static
name|void
name|PrintDWARFLocationList
argument_list|(
name|Stream
operator|&
name|s
argument_list|,
specifier|const
name|DWARFCompileUnit
operator|*
name|cu
argument_list|,
specifier|const
name|DataExtractor
operator|&
name|debug_loc_data
argument_list|,
name|lldb
operator|::
name|offset_t
name|offset
argument_list|)
decl_stmt|;
name|bool
name|MatchesOperand
argument_list|(
name|StackFrame
operator|&
name|frame
argument_list|,
specifier|const
name|Instruction
operator|::
name|Operand
operator|&
name|op
argument_list|)
decl_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|/// Pretty-prints the location expression to a stream
comment|///
comment|/// @param[in] stream
comment|///     The stream to use for pretty-printing.
comment|///
comment|/// @param[in] offset
comment|///     The offset into the data buffer of the opcodes to be printed.
comment|///
comment|/// @param[in] length
comment|///     The length in bytes of the opcodes to be printed.
comment|///
comment|/// @param[in] level
comment|///     The level of detail to use in pretty-printing.
comment|///
comment|/// @param[in] abi
comment|///     An optional ABI plug-in that can be used to resolve register
comment|///     names.
comment|//------------------------------------------------------------------
name|void
name|DumpLocation
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|offset_t
name|offset
argument_list|,
name|lldb
operator|::
name|offset_t
name|length
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|,
name|ABI
operator|*
name|abi
argument_list|)
decl|const
decl_stmt|;
name|bool
name|GetLocation
argument_list|(
name|lldb
operator|::
name|addr_t
name|base_addr
argument_list|,
name|lldb
operator|::
name|addr_t
name|pc
argument_list|,
name|lldb
operator|::
name|offset_t
operator|&
name|offset
argument_list|,
name|lldb
operator|::
name|offset_t
operator|&
name|len
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|AddressRangeForLocationListEntry
argument_list|(
specifier|const
name|DWARFCompileUnit
operator|*
name|dwarf_cu
argument_list|,
specifier|const
name|DataExtractor
operator|&
name|debug_loc_data
argument_list|,
name|lldb
operator|::
name|offset_t
operator|*
name|offset_ptr
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|low_pc
argument_list|,
name|lldb
operator|::
name|addr_t
operator|&
name|high_pc
argument_list|)
decl_stmt|;
name|bool
name|GetOpAndEndOffsets
argument_list|(
name|StackFrame
operator|&
name|frame
argument_list|,
name|lldb
operator|::
name|offset_t
operator|&
name|op_offset
argument_list|,
name|lldb
operator|::
name|offset_t
operator|&
name|end_offset
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Classes that inherit from DWARFExpression can see and modify these
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ModuleWP
name|m_module_wp
expr_stmt|;
comment|///< Module which defined this expression.
name|DataExtractor
name|m_data
decl_stmt|;
comment|///< A data extractor capable of reading opcode bytes
name|DWARFCompileUnit
modifier|*
name|m_dwarf_cu
decl_stmt|;
comment|///< The DWARF compile unit this expression
comment|///belongs to. It is used
comment|///< to evaluate values indexing into the .debug_addr section (e.g.
comment|///< DW_OP_GNU_addr_index, DW_OP_GNU_const_index)
name|lldb
operator|::
name|RegisterKind
name|m_reg_kind
expr_stmt|;
comment|///< One of the defines that starts with LLDB_REGKIND_
name|lldb
operator|::
name|addr_t
name|m_loclist_slide
expr_stmt|;
comment|///< A value used to slide the location list
comment|///offsets so that
comment|///< they are relative to the object that owns the location list
comment|///< (the function for frame base and variable location lists)
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_DWARFExpression_h_
end_comment

end_unit

