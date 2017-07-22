begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Declaration.h -------------------------------------------*- C++ -*-===//
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
name|liblldb_Declaration_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Declaration_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/FileSpec.h"
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
comment|/// @class Declaration Declaration.h "lldb/Symbol/Declaration.h"
comment|/// @brief A class that describes the declaration location of a
comment|///        lldb object.
comment|///
comment|/// The declarations include the file specification, line number, and
comment|/// the column info and can help track where functions, blocks, inlined
comment|/// functions, types, variables, any many other debug core objects were
comment|/// declared.
comment|//----------------------------------------------------------------------
name|class
name|Declaration
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|//------------------------------------------------------------------
name|Declaration
argument_list|()
operator|:
name|m_file
argument_list|()
operator|,
name|m_line
argument_list|(
literal|0
argument_list|)
ifdef|#
directive|ifdef
name|LLDB_ENABLE_DECLARATION_COLUMNS
operator|,
name|m_column
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{   }
comment|//------------------------------------------------------------------
comment|/// Construct with file specification, and optional line and column.
comment|///
comment|/// @param[in] file_spec
comment|///     The file specification that describes where this was
comment|///     declared.
comment|///
comment|/// @param[in] line
comment|///     The line number that describes where this was declared. Set
comment|///     to zero if there is no line number information.
comment|///
comment|/// @param[in] column
comment|///     The column number that describes where this was declared.
comment|///     Set to zero if there is no column number information.
comment|//------------------------------------------------------------------
name|Declaration
argument_list|(
argument|const FileSpec&file_spec
argument_list|,
argument|uint32_t line =
literal|0
argument_list|,
argument|uint32_t column =
literal|0
argument_list|)
operator|:
name|m_file
argument_list|(
name|file_spec
argument_list|)
operator|,
name|m_line
argument_list|(
name|line
argument_list|)
ifdef|#
directive|ifdef
name|LLDB_ENABLE_DECLARATION_COLUMNS
operator|,
name|m_column
argument_list|(
argument|column
argument_list|)
endif|#
directive|endif
block|{   }
comment|//------------------------------------------------------------------
comment|/// Construct with a reference to another Declaration object.
comment|//------------------------------------------------------------------
name|Declaration
argument_list|(
specifier|const
name|Declaration
operator|&
name|rhs
argument_list|)
operator|:
name|m_file
argument_list|(
name|rhs
operator|.
name|m_file
argument_list|)
operator|,
name|m_line
argument_list|(
name|rhs
operator|.
name|m_line
argument_list|)
ifdef|#
directive|ifdef
name|LLDB_ENABLE_DECLARATION_COLUMNS
operator|,
name|m_column
argument_list|(
argument|rhs.m_column
argument_list|)
endif|#
directive|endif
block|{   }
comment|//------------------------------------------------------------------
comment|/// Construct with a pointer to another Declaration object.
comment|//------------------------------------------------------------------
name|Declaration
argument_list|(
specifier|const
name|Declaration
operator|*
name|decl_ptr
argument_list|)
operator|:
name|m_file
argument_list|()
operator|,
name|m_line
argument_list|(
literal|0
argument_list|)
ifdef|#
directive|ifdef
name|LLDB_ENABLE_DECLARATION_COLUMNS
operator|,
name|m_column
argument_list|(
literal|0
argument_list|)
endif|#
directive|endif
block|{
if|if
condition|(
name|decl_ptr
condition|)
operator|*
name|this
operator|=
operator|*
name|decl_ptr
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Clear the object's state.
comment|///
comment|/// Sets the file specification to be empty, and the line and column
comment|/// to zero.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
block|{
name|m_file
operator|.
name|Clear
argument_list|()
expr_stmt|;
name|m_line
operator|=
literal|0
expr_stmt|;
ifdef|#
directive|ifdef
name|LLDB_ENABLE_DECLARATION_COLUMNS
name|m_column
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
block|}
comment|//------------------------------------------------------------------
comment|/// Compare two declaration objects.
comment|///
comment|/// Compares the two file specifications from \a lhs and \a rhs. If
comment|/// the file specifications are equal, then continue to compare the
comment|/// line number and column numbers respectively.
comment|///
comment|/// @param[in] lhs
comment|///     The Left Hand Side const Declaration object reference.
comment|///
comment|/// @param[in] rhs
comment|///     The Right Hand Side const Declaration object reference.
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
name|Declaration
modifier|&
name|lhs
parameter_list|,
specifier|const
name|Declaration
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
name|bool
name|DumpStopContext
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
comment|/// Get accessor for the declaration column number.
comment|///
comment|/// @return
comment|///     Non-zero indicates a valid column number, zero indicates no
comment|///     column information is available.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetColumn
argument_list|()
specifier|const
block|{
ifdef|#
directive|ifdef
name|LLDB_ENABLE_DECLARATION_COLUMNS
return|return
name|m_column
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
comment|//------------------------------------------------------------------
comment|/// Get accessor for file specification.
comment|///
comment|/// @return
comment|///     A reference to the file specification object.
comment|//------------------------------------------------------------------
name|FileSpec
modifier|&
name|GetFile
parameter_list|()
block|{
return|return
name|m_file
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get const accessor for file specification.
comment|///
comment|/// @return
comment|///     A const reference to the file specification object.
comment|//------------------------------------------------------------------
specifier|const
name|FileSpec
operator|&
name|GetFile
argument_list|()
specifier|const
block|{
return|return
name|m_file
return|;
block|}
comment|//------------------------------------------------------------------
comment|/// Get accessor for the declaration line number.
comment|///
comment|/// @return
comment|///     Non-zero indicates a valid line number, zero indicates no
comment|///     line information is available.
comment|//------------------------------------------------------------------
name|uint32_t
name|GetLine
argument_list|()
specifier|const
block|{
return|return
name|m_line
return|;
block|}
name|bool
name|IsValid
argument_list|()
specifier|const
block|{
return|return
name|m_file
operator|&&
name|m_line
operator|!=
literal|0
return|;
block|}
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
comment|/// Set accessor for the declaration column number.
comment|///
comment|/// @param[in] column
comment|///     Non-zero indicates a valid column number, zero indicates no
comment|///     column information is available.
comment|//------------------------------------------------------------------
name|void
name|SetColumn
parameter_list|(
name|uint32_t
name|column
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|LLDB_ENABLE_DECLARATION_COLUMNS
name|m_column
operator|=
name|col
expr_stmt|;
endif|#
directive|endif
block|}
comment|//------------------------------------------------------------------
comment|/// Set accessor for the declaration file specification.
comment|///
comment|/// @param[in] file_spec
comment|///     The new declaration file specification.
comment|//------------------------------------------------------------------
name|void
name|SetFile
parameter_list|(
specifier|const
name|FileSpec
modifier|&
name|file_spec
parameter_list|)
block|{
name|m_file
operator|=
name|file_spec
expr_stmt|;
block|}
comment|//------------------------------------------------------------------
comment|/// Set accessor for the declaration line number.
comment|///
comment|/// @param[in] line
comment|///     Non-zero indicates a valid line number, zero indicates no
comment|///     line information is available.
comment|//------------------------------------------------------------------
name|void
name|SetLine
parameter_list|(
name|uint32_t
name|line
parameter_list|)
block|{
name|m_line
operator|=
name|line
expr_stmt|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|/// Member variables.
comment|//------------------------------------------------------------------
name|FileSpec
name|m_file
decl_stmt|;
comment|///< The file specification that points to the
comment|///< source file where the declaration occurred.
name|uint32_t
name|m_line
decl_stmt|;
comment|///< Non-zero values indicates a valid line number,
comment|///< zero indicates no line number information is available.
ifdef|#
directive|ifdef
name|LLDB_ENABLE_DECLARATION_COLUMNS
name|uint32_t
name|m_column
decl_stmt|;
comment|///< Non-zero values indicates a valid column number,
comment|///< zero indicates no column information is available.
endif|#
directive|endif
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Declaration
operator|&
name|lhs
operator|,
specifier|const
name|Declaration
operator|&
name|rhs
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_Declaration_h_
end_comment

end_unit

