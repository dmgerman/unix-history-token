begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Error.h -------------------------------------------------*- C++ -*-===//
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
name|__DCError_h__
end_ifndef

begin_define
define|#
directive|define
name|__DCError_h__
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__cplusplus
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/lldb-defines.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_comment
comment|// for ErrorType, ErrorType...
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_comment
comment|// for StringRef
end_comment

begin_include
include|#
directive|include
file|"llvm/Support/FormatVariadic.h"
end_include

begin_include
include|#
directive|include
file|<cstdarg>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_comment
comment|// for error_code
end_comment

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_comment
comment|// for forward
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|// for uint32_t
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class Error Error.h "lldb/Utility/Error.h"
comment|/// @brief An error handling class.
comment|///
comment|/// This class is designed to be able to hold any error code that can be
comment|/// encountered on a given platform. The errors are stored as a value
comment|/// of type Error::ValueType. This value should be large enough to hold
comment|/// any and all errors that the class supports. Each error has an
comment|/// associated type that is of type lldb::ErrorType. New types
comment|/// can be added to support new error types, and architecture specific
comment|/// types can be enabled. In the future we may wish to switch to a
comment|/// registration mechanism where new error types can be registered at
comment|/// runtime instead of a hard coded scheme.
comment|///
comment|/// All errors in this class also know how to generate a string
comment|/// representation of themselves for printing results and error codes.
comment|/// The string value will be fetched on demand and its string value will
comment|/// be cached until the error is cleared of the value of the error
comment|/// changes.
comment|//----------------------------------------------------------------------
name|class
name|Error
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Every error value that this object can contain needs to be able
comment|/// to fit into ValueType.
comment|//------------------------------------------------------------------
typedef|typedef
name|uint32_t
name|ValueType
typedef|;
comment|//------------------------------------------------------------------
comment|/// Default constructor.
comment|///
comment|/// Initialize the error object with a generic success value.
comment|///
comment|/// @param[in] err
comment|///     An error code.
comment|///
comment|/// @param[in] type
comment|///     The type for \a err.
comment|//------------------------------------------------------------------
name|Error
argument_list|()
expr_stmt|;
name|explicit
name|Error
argument_list|(
name|ValueType
name|err
argument_list|,
name|lldb
operator|::
name|ErrorType
name|type
operator|=
name|lldb
operator|::
name|eErrorTypeGeneric
argument_list|)
decl_stmt|;
comment|/* implicit */
name|Error
argument_list|(
argument|std::error_code EC
argument_list|)
empty_stmt|;
name|explicit
name|Error
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
block|)
decl_stmt|)
block|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Error
argument_list|(
specifier|const
name|Error
operator|&
name|rhs
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Assignment operator.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] err
end_comment

begin_comment
comment|///     An error code.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A const reference to this object.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
specifier|const
name|Error
modifier|&
name|operator
init|=
operator|(
specifier|const
name|Error
operator|&
name|rhs
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Assignment operator from a kern_return_t.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Sets the type to \c MachKernel and the error code to \a err.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] err
end_comment

begin_comment
comment|///     A mach error code.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     A const reference to this object.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
specifier|const
name|Error
modifier|&
name|operator
init|=
operator|(
name|uint32_t
name|err
operator|)
decl_stmt|;
end_decl_stmt

begin_expr_stmt
operator|~
name|Error
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Get the error string associated with the current error.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// Gets the error value as a NULL terminated C string. The error
end_comment

begin_comment
comment|/// string will be fetched and cached on demand. The error string
end_comment

begin_comment
comment|/// will be retrieved from a callback that is appropriate for the
end_comment

begin_comment
comment|/// type of the error and will be cached until the error value is
end_comment

begin_comment
comment|/// changed or cleared.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The error as a NULL terminated C string value if the error
end_comment

begin_comment
comment|///     is valid and is able to be converted to a string value,
end_comment

begin_comment
comment|///     NULL otherwise.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|AsCString
argument_list|(
specifier|const
name|char
operator|*
name|default_error_str
operator|=
literal|"unknown error"
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Clear the object state.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Reverts the state of this object to contain a generic success
end_comment

begin_comment
comment|/// value and frees any cached error string value.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|Clear
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Test for error condition.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     \b true if this object contains an error, \b false
end_comment

begin_comment
comment|///     otherwise.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|bool
name|Fail
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Access the error value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The error value.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|ValueType
name|GetError
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Access the error type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     The error type enumeration value.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ErrorType
name|GetType
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Set accessor from a kern_return_t.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Set accesssor for the error value to \a err and the error type
end_comment

begin_comment
comment|/// to \c MachKernel.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] err
end_comment

begin_comment
comment|///     A mach error code.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|SetMachError
parameter_list|(
name|uint32_t
name|err
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|SetExpressionError
argument_list|(
name|lldb
operator|::
name|ExpressionResults
argument_list|,
specifier|const
name|char
operator|*
name|mssg
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|SetExpressionErrorWithFormat
argument_list|(
name|lldb
operator|::
name|ExpressionResults
argument_list|,
specifier|const
name|char
operator|*
name|format
argument_list|,
operator|...
argument_list|)
name|__attribute__
argument_list|(
operator|(
name|format
argument_list|(
name|printf
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Set accesssor with an error value and type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Set accesssor for the error value to \a err and the error type
end_comment

begin_comment
comment|/// to \a type.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] err
end_comment

begin_comment
comment|///     A mach error code.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] type
end_comment

begin_comment
comment|///     The type for \a err.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|void
name|SetError
argument_list|(
name|ValueType
name|err
argument_list|,
name|lldb
operator|::
name|ErrorType
name|type
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Set the current error to errno.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Update the error value to be \c errno and update the type to
end_comment

begin_comment
comment|/// be \c Error::POSIX.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|SetErrorToErrno
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Set the current error to a generic error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Update the error value to be \c LLDB_GENERIC_ERROR and update the
end_comment

begin_comment
comment|/// type to be \c Error::Generic.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|SetErrorToGenericError
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Set the current error string to \a err_str.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Set accessor for the error string value for a generic errors,
end_comment

begin_comment
comment|/// or to supply additional details above and beyond the standard
end_comment

begin_comment
comment|/// error strings that the standard type callbacks typically
end_comment

begin_comment
comment|/// provide. This allows custom strings to be supplied as an
end_comment

begin_comment
comment|/// error explanation. The error string value will remain until the
end_comment

begin_comment
comment|/// error value is cleared or a new error value/type is assigned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param err_str
end_comment

begin_comment
comment|///     The new custom error string to copy and cache.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|void
name|SetErrorString
argument_list|(
name|llvm
operator|::
name|StringRef
name|err_str
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Set the current error string to a formatted error string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param format
end_comment

begin_comment
comment|///     A printf style format string
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|int
name|SetErrorStringWithFormat
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(format
parameter_list|(
name|printf
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|SetErrorStringWithVarArg
parameter_list|(
specifier|const
name|char
modifier|*
name|format
parameter_list|,
name|va_list
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|template
operator|<
name|typename
operator|...
name|Args
operator|>
name|void
name|SetErrorStringWithFormatv
argument_list|(
argument|const char *format
argument_list|,
argument|Args&&... args
argument_list|)
block|{
name|SetErrorString
argument_list|(
name|llvm
operator|::
name|formatv
argument_list|(
name|format
argument_list|,
name|std
operator|::
name|forward
operator|<
name|Args
operator|>
operator|(
name|args
operator|)
operator|...
argument_list|)
operator|.
name|str
argument_list|()
argument_list|)
block|;   }
comment|//------------------------------------------------------------------
comment|/// Test for success condition.
comment|///
comment|/// Returns true if the error code in this object is considered a
comment|/// successful return value.
comment|///
comment|/// @return
comment|///     \b true if this object contains an value that describes
comment|///     success (non-erro), \b false otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Success
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Test for a failure due to a generic interrupt.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns true if the error code in this object was caused by an interrupt.
end_comment

begin_comment
comment|/// At present only supports Posix EINTR.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return
end_comment

begin_comment
comment|///     \b true if this object contains an value that describes
end_comment

begin_comment
comment|///     failure due to interrupt, \b false otherwise.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
name|bool
name|WasInterrupted
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Member variables
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_decl_stmt
name|ValueType
name|m_code
decl_stmt|;
end_decl_stmt

begin_comment
comment|///< Error code as an integer value.
end_comment

begin_expr_stmt
name|lldb
operator|::
name|ErrorType
name|m_type
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< The type of the above error code.
end_comment

begin_expr_stmt
name|mutable
name|std
operator|::
name|string
name|m_string
expr_stmt|;
end_expr_stmt

begin_comment
comment|///< A string representation of the error code.
end_comment

begin_comment
unit|};  }
comment|// namespace lldb_private
end_comment

begin_macro
unit|namespace
name|llvm
end_macro

begin_block
block|{
name|template
operator|<
operator|>
expr|struct
name|format_provider
operator|<
name|lldb_private
operator|::
name|Error
operator|>
block|{
specifier|static
name|void
name|format
argument_list|(
argument|const lldb_private::Error&error
argument_list|,
argument|llvm::raw_ostream&OS
argument_list|,
argument|llvm::StringRef Options
argument_list|)
block|; }
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #if defined(__cplusplus)
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef __DCError_h__
end_comment

end_unit

