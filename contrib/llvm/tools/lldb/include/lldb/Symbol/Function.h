begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Function.h ----------------------------------------------*- C++ -*-===//
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
name|liblldb_Function_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Function_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/AddressRange.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/Mangled.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/DWARFExpression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/Block.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/Declaration.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/UserID.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class FunctionInfo Function.h "lldb/Symbol/Function.h"
comment|/// @brief A class that contains generic function information.
comment|///
comment|/// This provides generic function information that gets reused between
comment|/// inline functions and function types.
comment|//----------------------------------------------------------------------
name|class
name|FunctionInfo
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Construct with the function method name and optional declaration
comment|/// information.
comment|///
comment|/// @param[in] name
comment|///     A C string name for the method name for this function. This
comment|///     value should not be the mangled named, but the simple method
comment|///     name.
comment|///
comment|/// @param[in] decl_ptr
comment|///     Optional declaration information that describes where the
comment|///     function was declared. This can be NULL.
comment|//------------------------------------------------------------------
name|FunctionInfo
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|Declaration
operator|*
name|decl_ptr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with the function method name and optional declaration
comment|/// information.
comment|///
comment|/// @param[in] name
comment|///     A name for the method name for this function. This value
comment|///     should not be the mangled named, but the simple method name.
comment|///
comment|/// @param[in] decl_ptr
comment|///     Optional declaration information that describes where the
comment|///     function was declared. This can be NULL.
comment|//------------------------------------------------------------------
name|FunctionInfo
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
specifier|const
name|Declaration
operator|*
name|decl_ptr
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|///
comment|/// The destructor is virtual since classes inherit from this class.
comment|//------------------------------------------------------------------
name|virtual
operator|~
name|FunctionInfo
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Compare two function information objects.
comment|///
comment|/// First compares the method names, and if equal, then compares
comment|/// the declaration information.
comment|///
comment|/// @param[in] lhs
comment|///     The Left Hand Side const FunctionInfo object reference.
comment|///
comment|/// @param[in] rhs
comment|///     The Right Hand Side const FunctionInfo object reference.
comment|///
comment|/// @return
comment|///     @li -1 if lhs< rhs
comment|///     @li 0 if lhs == rhs
comment|///     @li 1 if lhs> rhs
comment|//------------------------------------------------------------------
specifier|static
name|int
name|Compare
parameter_list|(
specifier|const
name|FunctionInfo
modifier|&
name|lhs
parameter_list|,
specifier|const
name|FunctionInfo
modifier|&
name|rhs
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream.
comment|///
comment|/// Dump a description of the contents of this object to the
comment|/// supplied stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
argument_list|,
name|bool
name|show_fullpaths
argument_list|)
decl|const
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the declaration information.
comment|///
comment|/// @return
comment|///     A reference to the declaration object.
comment|//------------------------------------------------------------------
name|Declaration
modifier|&
name|GetDeclaration
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the declaration information.
comment|///
comment|/// @return
comment|///     A const reference to the declaration object.
comment|//------------------------------------------------------------------
specifier|const
name|Declaration
operator|&
name|GetDeclaration
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the method name.
comment|///
comment|/// @return
comment|///     A const reference to the method name object.
comment|//------------------------------------------------------------------
name|ConstString
name|GetName
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the memory cost of this object.
comment|///
comment|/// @return
comment|///     The number of bytes that this object occupies in memory.
comment|///     The returned value does not include the bytes for any
comment|///     shared string values.
comment|///
comment|/// @see ConstString::StaticMemorySize ()
comment|//------------------------------------------------------------------
name|virtual
name|size_t
name|MemorySize
argument_list|()
specifier|const
expr_stmt|;
name|protected
label|:
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|ConstString
name|m_name
decl_stmt|;
comment|///< Function method name (not a mangled name).
name|Declaration
name|m_declaration
decl_stmt|;
comment|///< Information describing where this function
comment|///information was defined.
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class InlineFunctionInfo Function.h "lldb/Symbol/Function.h"
comment|/// @brief A class that describes information for an inlined function.
comment|//----------------------------------------------------------------------
name|class
name|InlineFunctionInfo
range|:
name|public
name|FunctionInfo
block|{
name|public
operator|:
comment|//------------------------------------------------------------------
comment|/// Construct with the function method name, mangled name, and
comment|/// optional declaration information.
comment|///
comment|/// @param[in] name
comment|///     A C string name for the method name for this function. This
comment|///     value should not be the mangled named, but the simple method
comment|///     name.
comment|///
comment|/// @param[in] mangled
comment|///     A C string name for the mangled name for this function. This
comment|///     value can be NULL if there is no mangled information.
comment|///
comment|/// @param[in] decl_ptr
comment|///     Optional declaration information that describes where the
comment|///     function was declared. This can be NULL.
comment|///
comment|/// @param[in] call_decl_ptr
comment|///     Optional calling location declaration information that
comment|///     describes from where this inlined function was called.
comment|//------------------------------------------------------------------
name|InlineFunctionInfo
argument_list|(
specifier|const
name|char
operator|*
name|name
argument_list|,
specifier|const
name|char
operator|*
name|mangled
argument_list|,
specifier|const
name|Declaration
operator|*
name|decl_ptr
argument_list|,
specifier|const
name|Declaration
operator|*
name|call_decl_ptr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Construct with the function method name, mangled name, and
comment|/// optional declaration information.
comment|///
comment|/// @param[in] name
comment|///     A name for the method name for this function. This value
comment|///     should not be the mangled named, but the simple method name.
comment|///
comment|/// @param[in] mangled
comment|///     A name for the mangled name for this function. This value
comment|///     can be empty if there is no mangled information.
comment|///
comment|/// @param[in] decl_ptr
comment|///     Optional declaration information that describes where the
comment|///     function was declared. This can be NULL.
comment|///
comment|/// @param[in] call_decl_ptr
comment|///     Optional calling location declaration information that
comment|///     describes from where this inlined function was called.
comment|//------------------------------------------------------------------
name|InlineFunctionInfo
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
specifier|const
name|Mangled
operator|&
name|mangled
argument_list|,
specifier|const
name|Declaration
operator|*
name|decl_ptr
argument_list|,
specifier|const
name|Declaration
operator|*
name|call_decl_ptr
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|InlineFunctionInfo
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|/// Compare two inlined function information objects.
comment|///
comment|/// First compares the FunctionInfo objects, and if equal,
comment|/// compares the mangled names.
comment|///
comment|/// @param[in] lhs
comment|///     The Left Hand Side const InlineFunctionInfo object
comment|///     reference.
comment|///
comment|/// @param[in] rhs
comment|///     The Right Hand Side const InlineFunctionInfo object
comment|///     reference.
comment|///
comment|/// @return
comment|///     @li -1 if lhs< rhs
comment|///     @li 0 if lhs == rhs
comment|///     @li 1 if lhs> rhs
comment|//------------------------------------------------------------------
name|int
name|Compare
argument_list|(
specifier|const
name|InlineFunctionInfo
operator|&
name|lhs
argument_list|,
specifier|const
name|InlineFunctionInfo
operator|&
name|rhs
argument_list|)
block|;
comment|//------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream.
comment|///
comment|/// Dump a description of the contents of this object to the
comment|/// supplied stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
argument|Stream *s
argument_list|,
argument|bool show_fullpaths
argument_list|)
specifier|const
block|;
name|void
name|DumpStopContext
argument_list|(
argument|Stream *s
argument_list|,
argument|lldb::LanguageType language
argument_list|)
specifier|const
block|;
name|ConstString
name|GetName
argument_list|(
argument|lldb::LanguageType language
argument_list|)
specifier|const
block|;
name|ConstString
name|GetDisplayName
argument_list|(
argument|lldb::LanguageType language
argument_list|)
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the call site declaration information.
comment|///
comment|/// @return
comment|///     A reference to the declaration object.
comment|//------------------------------------------------------------------
name|Declaration
operator|&
name|GetCallSite
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the call site declaration information.
comment|///
comment|/// @return
comment|///     A const reference to the declaration object.
comment|//------------------------------------------------------------------
specifier|const
name|Declaration
operator|&
name|GetCallSite
argument_list|()
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the mangled name object.
comment|///
comment|/// @return
comment|///     A reference to the mangled name object.
comment|//------------------------------------------------------------------
name|Mangled
operator|&
name|GetMangled
argument_list|()
block|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the mangled name object.
comment|///
comment|/// @return
comment|///     A const reference to the mangled name object.
comment|//------------------------------------------------------------------
specifier|const
name|Mangled
operator|&
name|GetMangled
argument_list|()
specifier|const
block|;
comment|//------------------------------------------------------------------
comment|/// Get the memory cost of this object.
comment|///
comment|/// @return
comment|///     The number of bytes that this object occupies in memory.
comment|///     The returned value does not include the bytes for any
comment|///     shared string values.
comment|///
comment|/// @see ConstString::StaticMemorySize ()
comment|//------------------------------------------------------------------
name|size_t
name|MemorySize
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|Mangled
name|m_mangled
block|;
comment|///< Mangled inlined function name (can be empty if there
comment|///is no mangled information).
name|Declaration
name|m_call_decl
block|; }
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class Function Function.h "lldb/Symbol/Function.h"
comment|/// @brief A class that describes a function.
comment|///
comment|/// Functions belong to CompileUnit objects (Function::m_comp_unit),
comment|/// have unique user IDs (Function::UserID), know how to reconstruct
comment|/// their symbol context (Function::SymbolContextScope), have a
comment|/// specific function type (Function::m_type_uid), have a simple
comment|/// method name (FunctionInfo::m_name), be declared at a specific
comment|/// location (FunctionInfo::m_declaration), possibly have mangled
comment|/// names (Function::m_mangled), an optional return type
comment|/// (Function::m_type), and contains lexical blocks
comment|/// (Function::m_blocks).
comment|///
comment|/// The function information is split into a few pieces:
comment|///     @li The concrete instance information
comment|///     @li The abstract information
comment|///
comment|/// The abstract information is found in the function type (Type) that
comment|/// describes a function information, return type and parameter types.
comment|///
comment|/// The concrete information is the address range information and
comment|/// specific locations for an instance of this function.
comment|//----------------------------------------------------------------------
name|class
name|Function
range|:
name|public
name|UserID
decl_stmt|,
name|public
name|SymbolContextScope
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Construct with a compile unit, function UID, function type UID,
comment|/// optional mangled name, function type, and a section offset
comment|/// based address range.
comment|///
comment|/// @param[in] comp_unit
comment|///     The compile unit to which this function belongs.
comment|///
comment|/// @param[in] func_uid
comment|///     The UID for this function. This value is provided by the
comment|///     SymbolFile plug-in and can be any value that allows
comment|///     the plug-in to quickly find and parse more detailed
comment|///     information when and if more information is needed.
comment|///
comment|/// @param[in] func_type_uid
comment|///     The type UID for the function Type to allow for lazy type
comment|///     parsing from the debug information.
comment|///
comment|/// @param[in] mangled
comment|///     The optional mangled name for this function. If empty, there
comment|///     is no mangled information.
comment|///
comment|/// @param[in] func_type
comment|///     The optional function type. If NULL, the function type will
comment|///     be parsed on demand when accessed using the
comment|///     Function::GetType() function by asking the SymbolFile
comment|///     plug-in to get the type for \a func_type_uid.
comment|///
comment|/// @param[in] range
comment|///     The section offset based address for this function.
comment|//------------------------------------------------------------------
name|Function
argument_list|(
argument|CompileUnit *comp_unit
argument_list|,
argument|lldb::user_id_t func_uid
argument_list|,
argument|lldb::user_id_t func_type_uid
argument_list|,
argument|const Mangled&mangled
argument_list|,
argument|Type *func_type
argument_list|,
argument|const AddressRange&range
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Construct with a compile unit, function UID, function type UID,
comment|/// optional mangled name, function type, and a section offset
comment|/// based address range.
comment|///
comment|/// @param[in] comp_unit
comment|///     The compile unit to which this function belongs.
comment|///
comment|/// @param[in] func_uid
comment|///     The UID for this function. This value is provided by the
comment|///     SymbolFile plug-in and can be any value that allows
comment|///     the plug-in to quickly find and parse more detailed
comment|///     information when and if more information is needed.
comment|///
comment|/// @param[in] func_type_uid
comment|///     The type UID for the function Type to allow for lazy type
comment|///     parsing from the debug information.
comment|///
comment|/// @param[in] mangled
comment|///     The optional mangled name for this function. If empty, there
comment|///     is no mangled information.
comment|///
comment|/// @param[in] func_type
comment|///     The optional function type. If NULL, the function type will
comment|///     be parsed on demand when accessed using the
comment|///     Function::GetType() function by asking the SymbolFile
comment|///     plug-in to get the type for \a func_type_uid.
comment|///
comment|/// @param[in] range
comment|///     The section offset based address for this function.
comment|//------------------------------------------------------------------
name|Function
argument_list|(
argument|CompileUnit *comp_unit
argument_list|,
argument|lldb::user_id_t func_uid
argument_list|,
argument|lldb::user_id_t func_type_uid
argument_list|,
argument|const char *mangled
argument_list|,
argument|Type *func_type
argument_list|,
argument|const AddressRange&range
argument_list|)
empty_stmt|;
comment|//------------------------------------------------------------------
comment|/// Destructor.
comment|//------------------------------------------------------------------
operator|~
name|Function
argument_list|()
name|override
expr_stmt|;
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
specifier|const
name|AddressRange
modifier|&
name|GetAddressRange
parameter_list|()
block|{
return|return
name|m_range
return|;
block|}
name|lldb
operator|::
name|LanguageType
name|GetLanguage
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find the file and line number of the source location of the start
comment|/// of the function.  This will use the declaration if present and fall
comment|/// back on the line table if that fails.  So there may NOT be a line
comment|/// table entry for this source file/line combo.
comment|///
comment|/// @param[out] source_file
comment|///     The source file.
comment|///
comment|/// @param[out] line_no
comment|///     The line number.
comment|//------------------------------------------------------------------
name|void
name|GetStartLineSourceInfo
parameter_list|(
name|FileSpec
modifier|&
name|source_file
parameter_list|,
name|uint32_t
modifier|&
name|line_no
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find the file and line number of the source location of the end
comment|/// of the function.
comment|///
comment|///
comment|/// @param[out] source_file
comment|///     The source file.
comment|///
comment|/// @param[out] line_no
comment|///     The line number.
comment|//------------------------------------------------------------------
name|void
name|GetEndLineSourceInfo
parameter_list|(
name|FileSpec
modifier|&
name|source_file
parameter_list|,
name|uint32_t
modifier|&
name|line_no
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the block list.
comment|///
comment|/// @return
comment|///     The block list object that describes all lexical blocks
comment|///     in the function.
comment|///
comment|/// @see BlockList
comment|//------------------------------------------------------------------
name|Block
modifier|&
name|GetBlock
parameter_list|(
name|bool
name|can_create
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the compile unit that owns this function.
comment|///
comment|/// @return
comment|///     A compile unit object pointer.
comment|//------------------------------------------------------------------
name|CompileUnit
modifier|*
name|GetCompileUnit
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the compile unit that owns this function.
comment|///
comment|/// @return
comment|///     A const compile unit object pointer.
comment|//------------------------------------------------------------------
specifier|const
name|CompileUnit
operator|*
name|GetCompileUnit
argument_list|()
specifier|const
expr_stmt|;
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
name|Target
operator|*
name|target
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the frame base location.
comment|///
comment|/// @return
comment|///     A location expression that describes the function frame
comment|///     base.
comment|//------------------------------------------------------------------
name|DWARFExpression
modifier|&
name|GetFrameBaseExpression
parameter_list|()
block|{
return|return
name|m_frame_base
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the frame base location.
comment|///
comment|/// @return
comment|///     A const compile unit object pointer.
comment|//------------------------------------------------------------------
specifier|const
name|DWARFExpression
operator|&
name|GetFrameBaseExpression
argument_list|()
specifier|const
block|{
return|return
name|m_frame_base
return|;
block|}
name|ConstString
name|GetName
argument_list|()
specifier|const
expr_stmt|;
name|ConstString
name|GetNameNoArguments
argument_list|()
specifier|const
expr_stmt|;
name|ConstString
name|GetDisplayName
argument_list|()
specifier|const
expr_stmt|;
specifier|const
name|Mangled
operator|&
name|GetMangled
argument_list|()
specifier|const
block|{
return|return
name|m_mangled
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get the DeclContext for this function, if available.
comment|///
comment|/// @return
comment|///     The DeclContext, or NULL if none exists.
comment|//------------------------------------------------------------------
name|CompilerDeclContext
name|GetDeclContext
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get accessor for the type that describes the function
comment|/// return value type, and parameter types.
comment|///
comment|/// @return
comment|///     A type object pointer.
comment|//------------------------------------------------------------------
name|Type
modifier|*
name|GetType
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get const accessor for the type that describes the function
comment|/// return value type, and parameter types.
comment|///
comment|/// @return
comment|///     A const type object pointer.
comment|//------------------------------------------------------------------
specifier|const
name|Type
operator|*
name|GetType
argument_list|()
specifier|const
expr_stmt|;
name|CompilerType
name|GetCompilerType
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get the size of the prologue instructions for this function.  The
comment|/// "prologue"
comment|/// instructions include any instructions given line number 0 immediately
comment|/// following
comment|/// the prologue end.
comment|///
comment|/// @return
comment|///     The size of the prologue.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetPrologueByteSize
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Dump a description of this object to a Stream.
comment|///
comment|/// Dump a description of the contents of this object to the
comment|/// supplied stream \a s.
comment|///
comment|/// @param[in] s
comment|///     The stream to which to dump the object description.
comment|///
comment|/// @param[in] show_context
comment|///     If \b true, variables will dump their symbol context
comment|///     information.
comment|//------------------------------------------------------------------
name|void
name|Dump
argument_list|(
name|Stream
operator|*
name|s
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
comment|//------------------------------------------------------------------
comment|/// Get the memory cost of this object.
comment|///
comment|/// @return
comment|///     The number of bytes that this object occupies in memory.
comment|///     The returned value does not include the bytes for any
comment|///     shared string values.
comment|///
comment|/// @see ConstString::StaticMemorySize ()
comment|//------------------------------------------------------------------
name|size_t
name|MemorySize
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get whether compiler optimizations were enabled for this function
comment|///
comment|/// The debug information may provide information about whether this
comment|/// function was compiled with optimization or not.  In this case,
comment|/// "optimized" means that the debug experience may be difficult
comment|/// for the user to understand.  Variables may not be available when
comment|/// the developer would expect them, stepping through the source lines
comment|/// in the function may appear strange, etc.
comment|///
comment|/// @return
comment|///     Returns 'true' if this function was compiled with
comment|///     optimization.  'false' indicates that either the optimization
comment|///     is unknown, or this function was built without optimization.
comment|//------------------------------------------------------------------
name|bool
name|GetIsOptimized
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Get whether this function represents a 'top-level' function
comment|///
comment|/// The concept of a top-level function is language-specific, mostly
comment|/// meant to represent the notion of scripting-style code that has
comment|/// global visibility of the variables/symbols/functions/...
comment|/// defined within the containing file/module
comment|///
comment|/// If stopped in a top-level function, LLDB will expose global variables
comment|/// as-if locals in the 'frame variable' command
comment|///
comment|/// @return
comment|///     Returns 'true' if this function is a top-level function,
comment|///     'false' otherwise.
comment|//------------------------------------------------------------------
name|bool
name|IsTopLevelFunction
parameter_list|()
function_decl|;
name|lldb
operator|::
name|DisassemblerSP
name|GetInstructions
argument_list|(
argument|const ExecutionContext&exe_ctx
argument_list|,
argument|const char *flavor
argument_list|,
argument|bool prefer_file_cache
argument_list|)
expr_stmt|;
name|bool
name|GetDisassembly
parameter_list|(
specifier|const
name|ExecutionContext
modifier|&
name|exe_ctx
parameter_list|,
specifier|const
name|char
modifier|*
name|flavor
parameter_list|,
name|bool
name|prefer_file_cache
parameter_list|,
name|Stream
modifier|&
name|strm
parameter_list|)
function_decl|;
name|protected
label|:
enum|enum
block|{
name|flagsCalculatedPrologueSize
init|=
operator|(
literal|1
operator|<<
literal|0
operator|)
comment|///< Have we already tried to calculate the prologue size?
block|}
enum|;
comment|//------------------------------------------------------------------
comment|// Member variables.
comment|//------------------------------------------------------------------
name|CompileUnit
modifier|*
name|m_comp_unit
decl_stmt|;
comment|///< The compile unit that owns this function.
name|lldb
operator|::
name|user_id_t
name|m_type_uid
expr_stmt|;
comment|///< The user ID of for the prototype Type for this function.
name|Type
modifier|*
name|m_type
decl_stmt|;
comment|///< The function prototype type for this function that include
comment|///the function info (FunctionInfo), return type and parameters.
name|Mangled
name|m_mangled
decl_stmt|;
comment|///< The mangled function name if any, if empty, there is
comment|///no mangled information.
name|Block
name|m_block
decl_stmt|;
comment|///< All lexical blocks contained in this function.
name|AddressRange
name|m_range
decl_stmt|;
comment|///< The function address range that covers the widest
comment|///range needed to contain all blocks
name|DWARFExpression
name|m_frame_base
decl_stmt|;
comment|///< The frame base expression for variables
comment|///that are relative to the frame pointer.
name|Flags
name|m_flags
decl_stmt|;
name|uint32_t
name|m_prologue_byte_size
decl_stmt|;
comment|///< Compute the prologue size once and cache it
name|private
label|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|Function
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
comment|// liblldb_Function_h_
end_comment

end_unit

