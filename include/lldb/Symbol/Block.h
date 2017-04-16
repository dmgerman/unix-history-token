begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Block.h -------------------------------------------------*- C++ -*-===//
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
name|liblldb_Block_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Block_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/RangeMap.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/LineEntry.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolContext.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/SymbolContextScope.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/Stream.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Block Block.h "lldb/Symbol/Block.h"
comment|/// @brief A class that describes a single lexical block.
comment|///
comment|/// A Function object owns a BlockList object which owns one or more
comment|/// Block objects. The BlockList object contains a section offset
comment|/// address range, and Block objects contain one or more ranges
comment|/// which are offsets into that range. Blocks are can have discontiguous
comment|/// ranges within the BlockList address range, and each block can
comment|/// contain child blocks each with their own sets of ranges.
comment|///
comment|/// Each block has a variable list that represents local, argument, and
comment|/// static variables that are scoped to the block.
comment|///
comment|/// Inlined functions are represented by attaching a
comment|/// InlineFunctionInfo shared pointer object to a block. Inlined
comment|/// functions are represented as named blocks.
comment|//----------------------------------------------------------------------
name|class
name|Block
range|:
name|public
name|UserID
decl_stmt|,
name|public
name|SymbolContextScope
block|{
name|public
label|:
typedef|typedef
name|RangeArray
operator|<
name|uint32_t
operator|,
name|uint32_t
operator|,
literal|1
operator|>
name|RangeList
expr_stmt|;
typedef|typedef
name|RangeList
operator|::
name|Entry
name|Range
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with a User ID \a uid, \a depth.
comment|///
comment|/// Initialize this block with the specified UID \a uid. The
comment|/// \a depth in the \a block_list is used to represent the parent,
comment|/// sibling, and child block information and also allows for partial
comment|/// parsing at the block level.
comment|///
comment|/// @param[in] uid
comment|///     The UID for a given block. This value is given by the
comment|///     SymbolFile plug-in and can be any value that helps the
comment|///     SymbolFile plug-in to match this block back to the debug
comment|///     information data that it parses for further or more in
comment|///     depth parsing. Common values would be the index into a
comment|///     table, or an offset into the debug information.
comment|///
comment|/// @param[in] depth
comment|///     The integer depth of this block in the block list hierarchy.
comment|///
comment|/// @param[in] block_list
comment|///     The block list that this object belongs to.
comment|///
comment|/// @see BlockList
comment|//------------------------------------------------------------------
name|Block
argument_list|(
argument|lldb::user_id_t uid
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|Block
argument_list|()
name|override
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add a child to this object.
comment|///
comment|/// @param[in] child_block_sp
comment|///     A shared pointer to a child block that will get added to
comment|///     this block.
comment|//------------------------------------------------------------------
name|void
name|AddChild
argument_list|(
specifier|const
name|lldb
operator|::
name|BlockSP
operator|&
name|child_block_sp
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add a new offset range to this block.
comment|///
comment|/// @param[in] start_offset
comment|///     An offset into this Function's address range that
comment|///     describes the start address of a range for this block.
comment|///
comment|/// @param[in] end_offset
comment|///     An offset into this Function's address range that
comment|///     describes the end address of a range for this block.
comment|//------------------------------------------------------------------
name|void
name|AddRange
parameter_list|(
specifier|const
name|Range
modifier|&
name|range
parameter_list|)
function_decl|;
name|void
name|FinalizeRanges
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// @copydoc SymbolContextScope::CalculateSymbolContext(SymbolContext*)
comment|///
comment|/// @see SymbolContextScope
comment|//------------------------------------------------------------------
name|void
name|CalculateSymbolContext
argument_list|(
name|SymbolContext
operator|*
name|sc
argument_list|)
name|override
decl_stmt|;
name|lldb
operator|::
name|ModuleSP
name|CalculateSymbolContextModule
argument_list|()
name|override
expr_stmt|;
name|CompileUnit
operator|*
name|CalculateSymbolContextCompileUnit
argument_list|()
name|override
expr_stmt|;
name|Function
operator|*
name|CalculateSymbolContextFunction
argument_list|()
name|override
expr_stmt|;
name|Block
operator|*
name|CalculateSymbolContextBlock
argument_list|()
name|override
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if an offset is in one of the block offset ranges.
comment|///
comment|/// @param[in] range_offset
comment|///     An offset into the Function's address range.
comment|///
comment|/// @return
comment|///     Returns \b true if \a range_offset falls in one of this
comment|///     block's ranges, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Contains
argument_list|(
name|lldb
operator|::
name|addr_t
name|range_offset
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if a offset range is in one of the block offset ranges.
comment|///
comment|/// @param[in] range
comment|///     An offset range into the Function's address range.
comment|///
comment|/// @return
comment|///     Returns \b true if \a range falls in one of this
comment|///     block's ranges, \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Contains
argument_list|(
specifier|const
name|Range
operator|&
name|range
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Check if this object contains "block" as a child block at any
comment|/// depth.
comment|///
comment|/// @param[in] block
comment|///     A potential child block.
comment|///
comment|/// @return
comment|///     Returns \b true if \a block is a child of this block, \b
comment|///     false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Contains
argument_list|(
specifier|const
name|Block
operator|*
name|block
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Dump the block contents.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|///
comment|/// @param[in] base_addr
comment|///     The resolved start address of the Function's address
comment|///     range. This should be resolved as the file or load address
comment|///     prior to passing the value into this function for dumping.
comment|///
comment|/// @param[in] depth
comment|///     Limit the number of levels deep that this function should
comment|///     print as this block can contain child blocks. Specify
comment|///     INT_MAX to dump all child blocks.
comment|///
comment|/// @param[in] show_context
comment|///     If \b true, variables will dump their context information.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|addr_t
name|base_addr
argument_list|,
name|int32_t
name|depth
argument_list|,
name|bool
name|show_context
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// @copydoc SymbolContextScope::DumpSymbolContext(Stream*)
comment|///
comment|/// @see SymbolContextScope
comment|//------------------------------------------------------------------
name|void
name|DumpSymbolContext
argument_list|(
name|Stream
operator|*
name|s
argument_list|)
name|override
decl_stmt|;
name|void
name|DumpAddressRanges
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|lldb
operator|::
name|addr_t
name|base_addr
argument_list|)
decl_stmt|;
name|void
name|GetDescription
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|Function
operator|*
name|function
argument_list|,
name|lldb
operator|::
name|DescriptionLevel
name|level
argument_list|,
name|Target
operator|*
name|target
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the parent block.
comment|///
comment|/// @return
comment|///     The parent block pointer, or nullptr if this block has no
comment|///     parent.
comment|//------------------------------------------------------------------
name|Block
operator|*
name|GetParent
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the inlined block that contains this block.
comment|///
comment|/// @return
comment|///     If this block contains inlined function info, it will return
comment|///     this block, else parent blocks will be searched to see if
comment|///     any contain this block. nullptr will be returned if this block
comment|///     nor any parent blocks are inlined function blocks.
comment|//------------------------------------------------------------------
name|Block
modifier|*
name|GetContainingInlinedBlock
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the inlined parent block for this block.
comment|///
comment|/// @return
comment|///     The parent block pointer, or nullptr if this block has no
comment|///     parent.
comment|//------------------------------------------------------------------
name|Block
modifier|*
name|GetInlinedParent
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the sibling block for this block.
comment|///
comment|/// @return
comment|///     The sibling block pointer, or nullptr if this block has no
comment|///     sibling.
comment|//------------------------------------------------------------------
name|Block
operator|*
name|GetSibling
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the first child block.
comment|///
comment|/// @return
comment|///     The first child block pointer, or nullptr if this block has no
comment|///     children.
comment|//------------------------------------------------------------------
name|Block
operator|*
name|GetFirstChild
argument_list|()
specifier|const
block|{
return|return
operator|(
name|m_children
operator|.
name|empty
argument_list|()
operator|?
name|nullptr
operator|:
name|m_children
operator|.
name|front
argument_list|()
operator|.
name|get
argument_list|()
operator|)
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the variable list for this block only.
comment|///
comment|/// @param[in] can_create
comment|///     If \b true, the variables can be parsed if they already
comment|///     haven't been, else the current state of the block will be
comment|///     returned.
comment|///
comment|/// @return
comment|///     A variable list shared pointer that contains all variables
comment|///     for this block.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|VariableListSP
name|GetBlockVariableList
argument_list|(
argument|bool can_create
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the variable list for this block and optionally all child
comment|/// blocks if \a get_child_variables is \b true.
comment|///
comment|/// @param[in] get_child_variables
comment|///     If \b true, all variables from all child blocks will be
comment|///     added to the variable list.
comment|///
comment|/// @param[in] can_create
comment|///     If \b true, the variables can be parsed if they already
comment|///     haven't been, else the current state of the block will be
comment|///     returned. Passing \b true for this parameter can be used
comment|///     to see the current state of what has been parsed up to this
comment|///     point.
comment|///
comment|/// @param[in] add_inline_child_block_variables
comment|///     If this is \b false, no child variables of child blocks
comment|///     that are inlined functions will be gotten. If \b true then
comment|///     all child variables will be added regardless of whether they
comment|///     come from inlined functions or not.
comment|///
comment|/// @return
comment|///     A variable list shared pointer that contains all variables
comment|///     for this block.
comment|//------------------------------------------------------------------
name|uint32_t
name|AppendBlockVariables
argument_list|(
name|bool
name|can_create
argument_list|,
name|bool
name|get_child_block_variables
argument_list|,
name|bool
name|stop_if_child_block_is_inlined_function
argument_list|,
specifier|const
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
name|Variable
operator|*
argument_list|)
operator|>
operator|&
name|filter
argument_list|,
name|VariableList
operator|*
name|variable_list
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Appends the variables from this block, and optionally from all
comment|/// parent blocks, to \a variable_list.
comment|///
comment|/// @param[in] can_create
comment|///     If \b true, the variables can be parsed if they already
comment|///     haven't been, else the current state of the block will be
comment|///     returned. Passing \b true for this parameter can be used
comment|///     to see the current state of what has been parsed up to this
comment|///     point.
comment|///
comment|/// @param[in] get_parent_variables
comment|///     If \b true, all variables from all parent blocks will be
comment|///     added to the variable list.
comment|///
comment|/// @param[in] stop_if_block_is_inlined_function
comment|///     If \b true, all variables from all parent blocks will be
comment|///     added to the variable list until there are no parent blocks
comment|///     or the parent block has inlined function info.
comment|///
comment|/// @param[in,out] variable_list
comment|///     All variables in this block, and optionally all parent
comment|///     blocks will be added to this list.
comment|///
comment|/// @return
comment|///     The number of variable that were appended to \a
comment|///     variable_list.
comment|//------------------------------------------------------------------
name|uint32_t
name|AppendVariables
argument_list|(
name|bool
name|can_create
argument_list|,
name|bool
name|get_parent_variables
argument_list|,
name|bool
name|stop_if_block_is_inlined_function
argument_list|,
specifier|const
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
name|Variable
operator|*
argument_list|)
operator|>
operator|&
name|filter
argument_list|,
name|VariableList
operator|*
name|variable_list
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for any inlined function information.
comment|///
comment|/// @return
comment|///     A const pointer to any inlined function information, or nullptr
comment|///     if this is a regular block.
comment|//------------------------------------------------------------------
specifier|const
name|InlineFunctionInfo
operator|*
name|GetInlinedFunctionInfo
argument_list|()
specifier|const
block|{
return|return
name|m_inlineInfoSP
operator|.
name|get
argument_list|()
return|;
block|}
name|CompilerDeclContext
name|GetDeclContext
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the memory cost of this object.
comment|///
comment|/// Returns the cost of this object plus any owned objects from the
comment|/// ranges, variables, and inline function information.
comment|///
comment|/// @return
comment|///     The number of bytes that this object occupies in memory.
comment|//------------------------------------------------------------------
name|size_t
name|MemorySize
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Set accessor for any inlined function information.
comment|///
comment|/// @param[in] name
comment|///     The method name for the inlined function. This value should
comment|///     not be nullptr.
comment|///
comment|/// @param[in] mangled
comment|///     The mangled method name for the inlined function. This can
comment|///     be nullptr if there is no mangled name for an inlined function
comment|///     or if the name is the same as \a name.
comment|///
comment|/// @param[in] decl_ptr
comment|///     A optional pointer to declaration information for the
comment|///     inlined function information. This value can be nullptr to
comment|///     indicate that no declaration information is available.
comment|///
comment|/// @param[in] call_decl_ptr
comment|///     Optional calling location declaration information that
comment|///     describes from where this inlined function was called.
comment|//------------------------------------------------------------------
name|void
name|SetInlinedFunctionInfo
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|mangled
parameter_list|,
specifier|const
name|Declaration
modifier|*
name|decl_ptr
parameter_list|,
specifier|const
name|Declaration
modifier|*
name|call_decl_ptr
parameter_list|)
function_decl|;
name|void
name|SetParentScope
parameter_list|(
name|SymbolContextScope
modifier|*
name|parent_scope
parameter_list|)
block|{
name|m_parent_scope
operator|=
name|parent_scope
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set accessor for the variable list.
comment|///
comment|/// Called by the SymbolFile plug-ins after they have parsed the
comment|/// variable lists and are ready to hand ownership of the list over
comment|/// to this object.
comment|///
comment|/// @param[in] variable_list_sp
comment|///     A shared pointer to a VariableList.
comment|//------------------------------------------------------------------
name|void
name|SetVariableList
argument_list|(
name|lldb
operator|::
name|VariableListSP
operator|&
name|variable_list_sp
argument_list|)
block|{
name|m_variable_list_sp
operator|=
name|variable_list_sp
expr_stmt|;
block|}
name|bool
name|BlockInfoHasBeenParsed
argument_list|()
specifier|const
block|{
return|return
name|m_parsed_block_info
return|;
block|}
name|void
name|SetBlockInfoHasBeenParsed
parameter_list|(
name|bool
name|b
parameter_list|,
name|bool
name|set_children
parameter_list|)
function_decl|;
name|Block
modifier|*
name|FindBlockByID
argument_list|(
name|lldb
operator|::
name|user_id_t
name|block_id
argument_list|)
decl_stmt|;
name|size_t
name|GetNumRanges
argument_list|()
specifier|const
block|{
return|return
name|m_ranges
operator|.
name|GetSize
argument_list|()
return|;
block|}
name|bool
name|GetRangeContainingOffset
argument_list|(
specifier|const
name|lldb
operator|::
name|addr_t
name|offset
argument_list|,
name|Range
operator|&
name|range
argument_list|)
decl_stmt|;
name|bool
name|GetRangeContainingAddress
parameter_list|(
specifier|const
name|Address
modifier|&
name|addr
parameter_list|,
name|AddressRange
modifier|&
name|range
parameter_list|)
function_decl|;
name|bool
name|GetRangeContainingLoadAddress
argument_list|(
name|lldb
operator|::
name|addr_t
name|load_addr
argument_list|,
name|Target
operator|&
name|target
argument_list|,
name|AddressRange
operator|&
name|range
argument_list|)
decl_stmt|;
name|uint32_t
name|GetRangeIndexContainingAddress
parameter_list|(
specifier|const
name|Address
modifier|&
name|addr
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|// Since blocks might have multiple discontiguous address ranges,
comment|// we need to be able to get at any of the address ranges in a block.
comment|//------------------------------------------------------------------
name|bool
name|GetRangeAtIndex
parameter_list|(
name|uint32_t
name|range_idx
parameter_list|,
name|AddressRange
modifier|&
name|range
parameter_list|)
function_decl|;
name|bool
name|GetStartAddress
parameter_list|(
name|Address
modifier|&
name|addr
parameter_list|)
function_decl|;
name|void
name|SetDidParseVariables
parameter_list|(
name|bool
name|b
parameter_list|,
name|bool
name|set_children
parameter_list|)
function_decl|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|lldb
operator|::
name|BlockSP
operator|>
name|collection
expr_stmt|;
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|SymbolContextScope
modifier|*
name|m_parent_scope
decl_stmt|;
name|collection
name|m_children
decl_stmt|;
name|RangeList
name|m_ranges
decl_stmt|;
name|lldb
operator|::
name|InlineFunctionInfoSP
name|m_inlineInfoSP
expr_stmt|;
comment|///< Inlined function information.
name|lldb
operator|::
name|VariableListSP
name|m_variable_list_sp
expr_stmt|;
comment|///< The variable list for all local,
comment|///static and parameter variables
comment|///scoped to this block.
name|bool
name|m_parsed_block_info
range|:
literal|1
decl_stmt|,
comment|///< Set to true if this block and it's children
comment|///have all been parsed
name|m_parsed_block_variables
range|:
literal|1
decl_stmt|,
name|m_parsed_child_blocks
range|:
literal|1
decl_stmt|;
comment|// A parent of child blocks can be asked to find a sibling block given
comment|// one of its child blocks
name|Block
modifier|*
name|GetSiblingForChild
argument_list|(
specifier|const
name|Block
operator|*
name|child_block
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Block
argument_list|)
expr_stmt|;
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
comment|// liblldb_Block_h_
end_comment

end_unit

