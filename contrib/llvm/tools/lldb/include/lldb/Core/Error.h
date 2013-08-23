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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<mach/mach.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string>
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
name|class
name|Log
decl_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class Error Error.h "lldb/Core/Error.h"
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
name|explicit
name|Error
parameter_list|(
specifier|const
name|char
modifier|*
name|err_str
parameter_list|)
function_decl|;
name|Error
argument_list|(
specifier|const
name|Error
operator|&
name|rhs
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Assignment operator.
comment|///
comment|/// @param[in] err
comment|///     An error code.
comment|///
comment|/// @return
comment|///     A const reference to this object.
comment|//------------------------------------------------------------------
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
comment|//------------------------------------------------------------------
comment|/// Assignment operator from a kern_return_t.
comment|///
comment|/// Sets the type to \c MachKernel and the error code to \a err.
comment|///
comment|/// @param[in] err
comment|///     A mach error code.
comment|///
comment|/// @return
comment|///     A const reference to this object.
comment|//------------------------------------------------------------------
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
operator|~
name|Error
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Get the error string associated with the current error.
comment|//
comment|/// Gets the error value as a NULL terminated C string. The error
comment|/// string will be fetched and cached on demand. The error string
comment|/// will be retrieved from a callback that is appropriate for the
comment|/// type of the error and will be cached until the error value is
comment|/// changed or cleared.
comment|///
comment|/// @return
comment|///     The error as a NULL terminated C string value if the error
comment|///     is valid and is able to be converted to a string value,
comment|///     NULL otherwise.
comment|//------------------------------------------------------------------
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
comment|//------------------------------------------------------------------
comment|/// Clear the object state.
comment|///
comment|/// Reverts the state of this object to contain a generic success
comment|/// value and frees any cached error string value.
comment|//------------------------------------------------------------------
name|void
name|Clear
parameter_list|()
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Test for error condition.
comment|///
comment|/// @return
comment|///     \b true if this object contains an error, \b false
comment|///     otherwise.
comment|//------------------------------------------------------------------
name|bool
name|Fail
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Access the error value.
comment|///
comment|/// @return
comment|///     The error value.
comment|//------------------------------------------------------------------
name|ValueType
name|GetError
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Access the error type.
comment|///
comment|/// @return
comment|///     The error type enumeration value.
comment|//------------------------------------------------------------------
name|lldb
operator|::
name|ErrorType
name|GetType
argument_list|()
specifier|const
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Log an error to Log().
comment|///
comment|/// Log the error given a formatted string \a format. If the this
comment|/// object contains an error code, update the error string to
comment|/// contain the prefix "error: ", followed by the formatted string,
comment|/// followed by the error value and any string that describes the
comment|/// error value. This allows more context to be given to an error
comment|/// string that remains cached in this object. Logging always occurs
comment|/// even when the error code contains a non-error value.
comment|///
comment|/// @param[in] format
comment|///     A printf style format string.
comment|///
comment|/// @param[in] ...
comment|///     Variable arguments that are needed for the printf style
comment|///     format string \a format.
comment|//------------------------------------------------------------------
name|void
name|PutToLog
parameter_list|(
name|Log
modifier|*
name|log
parameter_list|,
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
function_decl|3
operator|,
function_decl|4
block|)
decl_stmt|)
block|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Log an error to Log() if the error value is an error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Log the error given a formatted string \a format only if the
end_comment

begin_comment
comment|/// error value in this object describes an error condition. If the
end_comment

begin_comment
comment|/// this object contains an error, update the error string to
end_comment

begin_comment
comment|/// contain the prefix "error: " followed by the formatted string,
end_comment

begin_comment
comment|/// followed by the error value and any string that describes the
end_comment

begin_comment
comment|/// error value. This allows more context to be given to an error
end_comment

begin_comment
comment|/// string that remains cached in this object.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] format
end_comment

begin_comment
comment|///     A printf style format string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param[in] ...
end_comment

begin_comment
comment|///     Variable arguments that are needed for the printf style
end_comment

begin_comment
comment|///     format string \a format.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_function_decl
name|void
name|LogIfError
parameter_list|(
name|Log
modifier|*
name|log
parameter_list|,
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
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

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

begin_function_decl
name|void
name|SetErrorString
parameter_list|(
specifier|const
name|char
modifier|*
name|err_str
parameter_list|)
function_decl|;
end_function_decl

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

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_comment
comment|/// Test for success condition.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Returns true if the error code in this object is considered a
end_comment

begin_comment
comment|/// successful return value.
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
comment|///     success (non-erro), \b false otherwise.
end_comment

begin_comment
comment|//------------------------------------------------------------------
end_comment

begin_expr_stmt
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

