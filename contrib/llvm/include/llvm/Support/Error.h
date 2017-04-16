begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- llvm/Support/Error.h - Recoverable error handling ----*- C++ -*-===//
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
comment|// This file defines an API used to report recoverable errors.
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
name|LLVM_SUPPORT_ERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_ERROR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Config/abi-breaking.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Debug.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ErrorOr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<cstdlib>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<new>
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

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|ErrorSuccess
decl_stmt|;
comment|/// Base class for error info classes. Do not extend this directly: Extend
comment|/// the ErrorInfo template subclass instead.
name|class
name|ErrorInfoBase
block|{
name|public
label|:
name|virtual
operator|~
name|ErrorInfoBase
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Print an error message to an output stream.
name|virtual
name|void
name|log
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// Return the error message as a string.
name|virtual
name|std
operator|::
name|string
name|message
argument_list|()
specifier|const
block|{
name|std
operator|::
name|string
name|Msg
block|;
name|raw_string_ostream
name|OS
argument_list|(
name|Msg
argument_list|)
block|;
name|log
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
operator|.
name|str
argument_list|()
return|;
block|}
comment|/// Convert this error to a std::error_code.
comment|///
comment|/// This is a temporary crutch to enable interaction with code still
comment|/// using std::error_code. It will be removed in the future.
name|virtual
name|std
operator|::
name|error_code
name|convertToErrorCode
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Returns the class ID for this type.
specifier|static
specifier|const
name|void
modifier|*
name|classID
parameter_list|()
block|{
return|return
operator|&
name|ID
return|;
block|}
comment|// Returns the class ID for the dynamic type of this ErrorInfoBase instance.
name|virtual
specifier|const
name|void
operator|*
name|dynamicClassID
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|// Check whether this instance is a subclass of the class identified by
comment|// ClassID.
name|virtual
name|bool
name|isA
argument_list|(
specifier|const
name|void
operator|*
specifier|const
name|ClassID
argument_list|)
decl|const
block|{
return|return
name|ClassID
operator|==
name|classID
argument_list|()
return|;
block|}
comment|// Check whether this instance is a subclass of ErrorInfoT.
name|template
operator|<
name|typename
name|ErrorInfoT
operator|>
name|bool
name|isA
argument_list|()
specifier|const
block|{
return|return
name|isA
argument_list|(
name|ErrorInfoT
operator|::
name|classID
argument_list|()
argument_list|)
return|;
block|}
name|private
label|:
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
specifier|static
name|char
name|ID
decl_stmt|;
block|}
empty_stmt|;
comment|/// Lightweight error class with error context and mandatory checking.
comment|///
comment|/// Instances of this class wrap a ErrorInfoBase pointer. Failure states
comment|/// are represented by setting the pointer to a ErrorInfoBase subclass
comment|/// instance containing information describing the failure. Success is
comment|/// represented by a null pointer value.
comment|///
comment|/// Instances of Error also contains a 'Checked' flag, which must be set
comment|/// before the destructor is called, otherwise the destructor will trigger a
comment|/// runtime error. This enforces at runtime the requirement that all Error
comment|/// instances be checked or returned to the caller.
comment|///
comment|/// There are two ways to set the checked flag, depending on what state the
comment|/// Error instance is in. For Error instances indicating success, it
comment|/// is sufficient to invoke the boolean conversion operator. E.g.:
comment|///
comment|///   @code{.cpp}
comment|///   Error foo(<...>);
comment|///
comment|///   if (auto E = foo(<...>))
comment|///     return E; //<- Return E if it is in the error state.
comment|///   // We have verified that E was in the success state. It can now be safely
comment|///   // destroyed.
comment|///   @endcode
comment|///
comment|/// A success value *can not* be dropped. For example, just calling 'foo(<...>)'
comment|/// without testing the return value will raise a runtime error, even if foo
comment|/// returns success.
comment|///
comment|/// For Error instances representing failure, you must use either the
comment|/// handleErrors or handleAllErrors function with a typed handler. E.g.:
comment|///
comment|///   @code{.cpp}
comment|///   class MyErrorInfo : public ErrorInfo<MyErrorInfo> {
comment|///     // Custom error info.
comment|///   };
comment|///
comment|///   Error foo(<...>) { return make_error<MyErrorInfo>(...); }
comment|///
comment|///   auto E = foo(<...>); //<- foo returns failure with MyErrorInfo.
comment|///   auto NewE =
comment|///     handleErrors(E,
comment|///       [](const MyErrorInfo&M) {
comment|///         // Deal with the error.
comment|///       },
comment|///       [](std::unique_ptr<OtherError> M) -> Error {
comment|///         if (canHandle(*M)) {
comment|///           // handle error.
comment|///           return Error::success();
comment|///         }
comment|///         // Couldn't handle this error instance. Pass it up the stack.
comment|///         return Error(std::move(M));
comment|///       );
comment|///   // Note - we must check or return NewE in case any of the handlers
comment|///   // returned a new error.
comment|///   @endcode
comment|///
comment|/// The handleAllErrors function is identical to handleErrors, except
comment|/// that it has a void return type, and requires all errors to be handled and
comment|/// no new errors be returned. It prevents errors (assuming they can all be
comment|/// handled) from having to be bubbled all the way to the top-level.
comment|///
comment|/// *All* Error instances must be checked before destruction, even if
comment|/// they're moved-assigned or constructed from Success values that have already
comment|/// been checked. This enforces checking through all levels of the call stack.
name|class
name|LLVM_NODISCARD
name|Error
block|{
comment|// ErrorList needs to be able to yank ErrorInfoBase pointers out of this
comment|// class to add to the error list.
name|friend
name|class
name|ErrorList
decl_stmt|;
comment|// handleErrors needs to be able to set the Checked flag.
name|template
operator|<
name|typename
operator|...
name|HandlerTs
operator|>
name|friend
name|Error
name|handleErrors
argument_list|(
argument|Error E
argument_list|,
argument|HandlerTs&&... Handlers
argument_list|)
expr_stmt|;
comment|// Expected<T> needs to be able to steal the payload when constructed from an
comment|// error.
name|template
operator|<
name|typename
name|T
operator|>
name|friend
name|class
name|Expected
expr_stmt|;
name|protected
label|:
comment|/// Create a success value. Prefer using 'Error::success()' for readability
name|Error
argument_list|()
operator|:
name|Payload
argument_list|(
argument|nullptr
argument_list|)
block|{
name|setPtr
argument_list|(
name|nullptr
argument_list|)
block|;
name|setChecked
argument_list|(
name|false
argument_list|)
block|;   }
name|public
operator|:
comment|/// Create a success value.
specifier|static
name|ErrorSuccess
name|success
argument_list|()
expr_stmt|;
comment|// Errors are not copy-constructable.
name|Error
argument_list|(
specifier|const
name|Error
operator|&
name|Other
argument_list|)
operator|=
name|delete
expr_stmt|;
comment|/// Move-construct an error value. The newly constructed error is considered
comment|/// unchecked, even if the source error had been checked. The original error
comment|/// becomes a checked Success value, regardless of its original state.
name|Error
argument_list|(
name|Error
operator|&&
name|Other
argument_list|)
operator|:
name|Payload
argument_list|(
argument|nullptr
argument_list|)
block|{
name|setChecked
argument_list|(
name|true
argument_list|)
block|;
operator|*
name|this
operator|=
name|std
operator|::
name|move
argument_list|(
name|Other
argument_list|)
block|;   }
comment|/// Create an error value. Prefer using the 'make_error' function, but
comment|/// this constructor can be useful when "re-throwing" errors from handlers.
name|Error
argument_list|(
argument|std::unique_ptr<ErrorInfoBase> Payload
argument_list|)
block|{
name|setPtr
argument_list|(
name|Payload
operator|.
name|release
argument_list|()
argument_list|)
block|;
name|setChecked
argument_list|(
name|false
argument_list|)
block|;   }
comment|// Errors are not copy-assignable.
name|Error
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Error
operator|&
name|Other
operator|)
operator|=
name|delete
expr_stmt|;
comment|/// Move-assign an error value. The current error must represent success, you
comment|/// you cannot overwrite an unhandled error. The current error is then
comment|/// considered unchecked. The source error becomes a checked success value,
comment|/// regardless of its original state.
name|Error
modifier|&
name|operator
init|=
operator|(
name|Error
operator|&&
name|Other
operator|)
block|{
comment|// Don't allow overwriting of unchecked values.
name|assertIsChecked
argument_list|()
block|;
name|setPtr
argument_list|(
name|Other
operator|.
name|getPtr
argument_list|()
argument_list|)
block|;
comment|// This Error is unchecked, even if the source error was checked.
name|setChecked
argument_list|(
name|false
argument_list|)
block|;
comment|// Null out Other's payload and set its checked bit.
name|Other
operator|.
name|setPtr
argument_list|(
name|nullptr
argument_list|)
block|;
name|Other
operator|.
name|setChecked
argument_list|(
name|true
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// Destroy a Error. Fails with a call to abort() if the error is
comment|/// unchecked.
operator|~
name|Error
argument_list|()
block|{
name|assertIsChecked
argument_list|()
block|;
name|delete
name|getPtr
argument_list|()
block|;   }
comment|/// Bool conversion. Returns true if this Error is in a failure state,
comment|/// and false if it is in an accept state. If the error is in a Success state
comment|/// it will be considered checked.
name|explicit
name|operator
name|bool
argument_list|()
block|{
name|setChecked
argument_list|(
name|getPtr
argument_list|()
operator|==
name|nullptr
argument_list|)
block|;
return|return
name|getPtr
argument_list|()
operator|!=
name|nullptr
return|;
block|}
comment|/// Check whether one error is a subclass of another.
name|template
operator|<
name|typename
name|ErrT
operator|>
name|bool
name|isA
argument_list|()
specifier|const
block|{
return|return
name|getPtr
argument_list|()
operator|&&
name|getPtr
argument_list|()
operator|->
name|isA
argument_list|(
name|ErrT
operator|::
name|classID
argument_list|()
argument_list|)
return|;
block|}
comment|/// Returns the dynamic class id of this error, or null if this is a success
comment|/// value.
specifier|const
name|void
operator|*
name|dynamicClassID
argument_list|()
specifier|const
block|{
if|if
condition|(
operator|!
name|getPtr
argument_list|()
condition|)
return|return
name|nullptr
return|;
return|return
name|getPtr
argument_list|()
operator|->
name|dynamicClassID
argument_list|()
return|;
block|}
name|private
label|:
name|void
name|assertIsChecked
parameter_list|()
block|{
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
if|if
condition|(
operator|!
name|getChecked
argument_list|()
operator|||
name|getPtr
argument_list|()
condition|)
block|{
name|dbgs
argument_list|()
operator|<<
literal|"Program aborted due to an unhandled Error:\n"
expr_stmt|;
if|if
condition|(
name|getPtr
argument_list|()
condition|)
name|getPtr
argument_list|()
operator|->
name|log
argument_list|(
name|dbgs
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|dbgs
argument_list|()
operator|<<
literal|"Error value was Success. (Note: Success values must still be "
literal|"checked prior to being destroyed).\n"
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
name|ErrorInfoBase
operator|*
name|getPtr
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|ErrorInfoBase
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Payload
operator|)
operator|&
operator|~
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
literal|0x1
operator|)
operator|)
return|;
block|}
name|void
name|setPtr
parameter_list|(
name|ErrorInfoBase
modifier|*
name|EI
parameter_list|)
block|{
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
name|Payload
operator|=
name|reinterpret_cast
operator|<
name|ErrorInfoBase
operator|*
operator|>
operator|(
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|EI
operator|)
operator|&
operator|~
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
literal|0x1
operator|)
operator|)
operator||
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Payload
operator|)
operator|&
literal|0x1
operator|)
operator|)
expr_stmt|;
else|#
directive|else
name|Payload
operator|=
name|EI
expr_stmt|;
endif|#
directive|endif
block|}
name|bool
name|getChecked
argument_list|()
specifier|const
block|{
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
return|return
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Payload
operator|)
operator|&
literal|0x1
operator|)
operator|==
literal|0
return|;
else|#
directive|else
return|return
name|true
return|;
endif|#
directive|endif
block|}
end_decl_stmt

begin_function
name|void
name|setChecked
parameter_list|(
name|bool
name|V
parameter_list|)
block|{
name|Payload
operator|=
name|reinterpret_cast
operator|<
name|ErrorInfoBase
operator|*
operator|>
operator|(
operator|(
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|Payload
operator|)
operator|&
operator|~
name|static_cast
operator|<
name|uintptr_t
operator|>
operator|(
literal|0x1
operator|)
operator|)
operator||
operator|(
name|V
condition|?
literal|0
else|:
literal|1
operator|)
operator|)
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|ErrorInfoBase
operator|>
name|takePayload
argument_list|()
block|{
name|std
operator|::
name|unique_ptr
operator|<
name|ErrorInfoBase
operator|>
name|Tmp
argument_list|(
name|getPtr
argument_list|()
argument_list|)
block|;
name|setPtr
argument_list|(
name|nullptr
argument_list|)
block|;
name|setChecked
argument_list|(
name|true
argument_list|)
block|;
return|return
name|Tmp
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|ErrorInfoBase
modifier|*
name|Payload
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|/// Subclass of Error for the sole purpose of identifying the success path in
end_comment

begin_comment
comment|/// the type system. This allows to catch invalid conversion to Expected<T> at
end_comment

begin_comment
comment|/// compile time.
end_comment

begin_decl_stmt
name|class
name|ErrorSuccess
range|:
name|public
name|Error
block|{}
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|inline
name|ErrorSuccess
name|Error
operator|::
name|success
argument_list|()
block|{
return|return
name|ErrorSuccess
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Make a Error instance representing failure using the given error info
end_comment

begin_comment
comment|/// type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ErrT
operator|,
name|typename
operator|...
name|ArgTs
operator|>
name|Error
name|make_error
argument_list|(
argument|ArgTs&&... Args
argument_list|)
block|{
return|return
name|Error
argument_list|(
name|llvm
operator|::
name|make_unique
operator|<
name|ErrT
operator|>
operator|(
name|std
operator|::
name|forward
operator|<
name|ArgTs
operator|>
operator|(
name|Args
operator|)
operator|...
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Base class for user error types. Users should declare their error types
end_comment

begin_comment
comment|/// like:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// class MyError : public ErrorInfo<MyError> {
end_comment

begin_comment
comment|///   ....
end_comment

begin_comment
comment|/// };
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class provides an implementation of the ErrorInfoBase::kind
end_comment

begin_comment
comment|/// method, which is used by the Error RTTI system.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ThisErrT
operator|,
name|typename
name|ParentErrT
operator|=
name|ErrorInfoBase
operator|>
name|class
name|ErrorInfo
operator|:
name|public
name|ParentErrT
block|{
name|public
operator|:
specifier|static
specifier|const
name|void
operator|*
name|classID
argument_list|()
block|{
return|return
operator|&
name|ThisErrT
operator|::
name|ID
return|;
block|}
specifier|const
name|void
operator|*
name|dynamicClassID
argument_list|()
specifier|const
name|override
block|{
return|return
operator|&
name|ThisErrT
operator|::
name|ID
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|bool
name|isA
argument_list|(
specifier|const
name|void
operator|*
specifier|const
name|ClassID
argument_list|)
decl|const
name|override
block|{
return|return
name|ClassID
operator|==
name|classID
argument_list|()
operator|||
name|ParentErrT
operator|::
name|isA
argument_list|(
name|ClassID
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
unit|};
comment|/// Special ErrorInfo subclass representing a list of ErrorInfos.
end_comment

begin_comment
comment|/// Instances of this class are constructed by joinError.
end_comment

begin_decl_stmt
name|class
name|ErrorList
name|final
range|:
name|public
name|ErrorInfo
operator|<
name|ErrorList
operator|>
block|{
comment|// handleErrors needs to be able to iterate the payload list of an
comment|// ErrorList.
name|template
operator|<
name|typename
operator|...
name|HandlerTs
operator|>
name|friend
name|Error
name|handleErrors
argument_list|(
argument|Error E
argument_list|,
argument|HandlerTs&&... Handlers
argument_list|)
block|;
comment|// joinErrors is implemented in terms of join.
name|friend
name|Error
name|joinErrors
argument_list|(
name|Error
argument_list|,
name|Error
argument_list|)
block|;
name|public
operator|:
name|void
name|log
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|{
name|OS
operator|<<
literal|"Multiple errors:\n"
block|;
for|for
control|(
name|auto
operator|&
name|ErrPayload
operator|:
name|Payloads
control|)
block|{
name|ErrPayload
operator|->
name|log
argument_list|(
name|OS
argument_list|)
expr_stmt|;
name|OS
operator|<<
literal|"\n"
expr_stmt|;
block|}
block|}
name|std
operator|::
name|error_code
name|convertToErrorCode
argument_list|()
specifier|const
name|override
block|;
comment|// Used by ErrorInfo::classID.
specifier|static
name|char
name|ID
block|;
name|private
operator|:
name|ErrorList
argument_list|(
argument|std::unique_ptr<ErrorInfoBase> Payload1
argument_list|,
argument|std::unique_ptr<ErrorInfoBase> Payload2
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|Payload1
operator|->
name|isA
operator|<
name|ErrorList
operator|>
operator|(
operator|)
operator|&&
operator|!
name|Payload2
operator|->
name|isA
operator|<
name|ErrorList
operator|>
operator|(
operator|)
operator|&&
literal|"ErrorList constructor payloads should be singleton errors"
argument_list|)
block|;
name|Payloads
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Payload1
argument_list|)
argument_list|)
block|;
name|Payloads
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Payload2
argument_list|)
argument_list|)
block|;   }
specifier|static
name|Error
name|join
argument_list|(
argument|Error E1
argument_list|,
argument|Error E2
argument_list|)
block|{
if|if
condition|(
operator|!
name|E1
condition|)
return|return
name|E2
return|;
if|if
condition|(
operator|!
name|E2
condition|)
return|return
name|E1
return|;
end_decl_stmt

begin_if
if|if
condition|(
name|E1
operator|.
name|isA
operator|<
name|ErrorList
operator|>
operator|(
operator|)
condition|)
block|{
name|auto
operator|&
name|E1List
operator|=
name|static_cast
operator|<
name|ErrorList
operator|&
operator|>
operator|(
operator|*
name|E1
operator|.
name|getPtr
argument_list|()
operator|)
expr_stmt|;
if|if
condition|(
name|E2
operator|.
name|isA
operator|<
name|ErrorList
operator|>
operator|(
operator|)
condition|)
block|{
name|auto
name|E2Payload
init|=
name|E2
operator|.
name|takePayload
argument_list|()
decl_stmt|;
name|auto
operator|&
name|E2List
operator|=
name|static_cast
operator|<
name|ErrorList
operator|&
operator|>
operator|(
operator|*
name|E2Payload
operator|)
expr_stmt|;
for|for
control|(
name|auto
operator|&
name|Payload
operator|:
name|E2List
operator|.
name|Payloads
control|)
name|E1List
operator|.
name|Payloads
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Payload
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
name|E1List
operator|.
name|Payloads
operator|.
name|push_back
argument_list|(
name|E2
operator|.
name|takePayload
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|E1
return|;
block|}
end_if

begin_if
if|if
condition|(
name|E2
operator|.
name|isA
operator|<
name|ErrorList
operator|>
operator|(
operator|)
condition|)
block|{
name|auto
operator|&
name|E2List
operator|=
name|static_cast
operator|<
name|ErrorList
operator|&
operator|>
operator|(
operator|*
name|E2
operator|.
name|getPtr
argument_list|()
operator|)
expr_stmt|;
name|E2List
operator|.
name|Payloads
operator|.
name|insert
argument_list|(
name|E2List
operator|.
name|Payloads
operator|.
name|begin
argument_list|()
argument_list|,
name|E1
operator|.
name|takePayload
argument_list|()
argument_list|)
expr_stmt|;
return|return
name|E2
return|;
block|}
end_if

begin_return
return|return
name|Error
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ErrorList
operator|>
operator|(
name|new
name|ErrorList
argument_list|(
name|E1
operator|.
name|takePayload
argument_list|()
argument_list|,
name|E2
operator|.
name|takePayload
argument_list|()
argument_list|)
operator|)
argument_list|)
return|;
end_return

begin_expr_stmt
unit|}    std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|ErrorInfoBase
operator|>>
name|Payloads
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// Concatenate errors. The resulting Error is unchecked, and contains the
end_comment

begin_comment
comment|/// ErrorInfo(s), if any, contained in E1, followed by the
end_comment

begin_comment
comment|/// ErrorInfo(s), if any, contained in E2.
end_comment

begin_function
specifier|inline
name|Error
name|joinErrors
parameter_list|(
name|Error
name|E1
parameter_list|,
name|Error
name|E2
parameter_list|)
block|{
return|return
name|ErrorList
operator|::
name|join
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|E1
argument_list|)
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|E2
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// Helper for testing applicability of, and applying, handlers for
end_comment

begin_comment
comment|/// ErrorInfo types.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|HandlerT
operator|>
name|class
name|ErrorHandlerTraits
operator|:
name|public
name|ErrorHandlerTraits
operator|<
name|decltype
argument_list|(
operator|&
name|std
operator|::
name|remove_reference
operator|<
name|HandlerT
operator|>
operator|::
name|type
operator|::
name|operator
argument_list|()
argument_list|)
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Specialization functions of the form 'Error (const ErrT&)'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ErrT
operator|>
name|class
name|ErrorHandlerTraits
operator|<
name|Error
argument_list|(
operator|&
argument_list|)
argument_list|(
name|ErrT
operator|&
argument_list|)
operator|>
block|{
name|public
operator|:
specifier|static
name|bool
name|appliesTo
argument_list|(
argument|const ErrorInfoBase&E
argument_list|)
block|{
return|return
name|E
operator|.
name|template
name|isA
operator|<
name|ErrT
operator|>
operator|(
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|HandlerT
operator|>
specifier|static
name|Error
name|apply
argument_list|(
argument|HandlerT&&H
argument_list|,
argument|std::unique_ptr<ErrorInfoBase> E
argument_list|)
block|{
name|assert
argument_list|(
name|appliesTo
argument_list|(
operator|*
name|E
argument_list|)
operator|&&
literal|"Applying incorrect handler"
argument_list|)
block|;
return|return
name|H
argument_list|(
name|static_cast
operator|<
name|ErrT
operator|&
operator|>
operator|(
operator|*
name|E
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Specialization functions of the form 'void (const ErrT&)'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ErrT
operator|>
name|class
name|ErrorHandlerTraits
operator|<
name|void
argument_list|(
operator|&
argument_list|)
argument_list|(
name|ErrT
operator|&
argument_list|)
operator|>
block|{
name|public
operator|:
specifier|static
name|bool
name|appliesTo
argument_list|(
argument|const ErrorInfoBase&E
argument_list|)
block|{
return|return
name|E
operator|.
name|template
name|isA
operator|<
name|ErrT
operator|>
operator|(
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|HandlerT
operator|>
specifier|static
name|Error
name|apply
argument_list|(
argument|HandlerT&&H
argument_list|,
argument|std::unique_ptr<ErrorInfoBase> E
argument_list|)
block|{
name|assert
argument_list|(
name|appliesTo
argument_list|(
operator|*
name|E
argument_list|)
operator|&&
literal|"Applying incorrect handler"
argument_list|)
block|;
name|H
argument_list|(
name|static_cast
operator|<
name|ErrT
operator|&
operator|>
operator|(
operator|*
name|E
operator|)
argument_list|)
block|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// Specialization for functions of the form 'Error (std::unique_ptr<ErrT>)'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ErrT
operator|>
name|class
name|ErrorHandlerTraits
operator|<
name|Error
argument_list|(
operator|&
argument_list|)
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ErrT
operator|>
argument_list|)
operator|>
block|{
name|public
operator|:
specifier|static
name|bool
name|appliesTo
argument_list|(
argument|const ErrorInfoBase&E
argument_list|)
block|{
return|return
name|E
operator|.
name|template
name|isA
operator|<
name|ErrT
operator|>
operator|(
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|HandlerT
operator|>
specifier|static
name|Error
name|apply
argument_list|(
argument|HandlerT&&H
argument_list|,
argument|std::unique_ptr<ErrorInfoBase> E
argument_list|)
block|{
name|assert
argument_list|(
name|appliesTo
argument_list|(
operator|*
name|E
argument_list|)
operator|&&
literal|"Applying incorrect handler"
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ErrT
operator|>
name|SubE
argument_list|(
name|static_cast
operator|<
name|ErrT
operator|*
operator|>
operator|(
name|E
operator|.
name|release
argument_list|()
operator|)
argument_list|)
block|;
return|return
name|H
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|SubE
argument_list|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// Specialization for functions of the form 'Error (std::unique_ptr<ErrT>)'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ErrT
operator|>
name|class
name|ErrorHandlerTraits
operator|<
name|void
argument_list|(
operator|&
argument_list|)
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ErrT
operator|>
argument_list|)
operator|>
block|{
name|public
operator|:
specifier|static
name|bool
name|appliesTo
argument_list|(
argument|const ErrorInfoBase&E
argument_list|)
block|{
return|return
name|E
operator|.
name|template
name|isA
operator|<
name|ErrT
operator|>
operator|(
operator|)
return|;
block|}
name|template
operator|<
name|typename
name|HandlerT
operator|>
specifier|static
name|Error
name|apply
argument_list|(
argument|HandlerT&&H
argument_list|,
argument|std::unique_ptr<ErrorInfoBase> E
argument_list|)
block|{
name|assert
argument_list|(
name|appliesTo
argument_list|(
operator|*
name|E
argument_list|)
operator|&&
literal|"Applying incorrect handler"
argument_list|)
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|ErrT
operator|>
name|SubE
argument_list|(
name|static_cast
operator|<
name|ErrT
operator|*
operator|>
operator|(
name|E
operator|.
name|release
argument_list|()
operator|)
argument_list|)
block|;
name|H
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|SubE
argument_list|)
argument_list|)
block|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|// Specialization for member functions of the form 'RetT (const ErrT&)'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|C
operator|,
name|typename
name|RetT
operator|,
name|typename
name|ErrT
operator|>
name|class
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
name|C
operator|::
operator|*
argument_list|)
argument_list|(
name|ErrT
operator|&
argument_list|)
operator|>
operator|:
name|public
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
operator|&
argument_list|)
argument_list|(
name|ErrT
operator|&
argument_list|)
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Specialization for member functions of the form 'RetT (const ErrT&) const'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|C
operator|,
name|typename
name|RetT
operator|,
name|typename
name|ErrT
operator|>
name|class
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
argument|C::*
argument_list|)
operator|(
name|ErrT
operator|&
operator|)
specifier|const
operator|>
operator|:
name|public
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
operator|&
argument_list|)
argument_list|(
name|ErrT
operator|&
argument_list|)
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Specialization for member functions of the form 'RetT (const ErrT&)'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|C
operator|,
name|typename
name|RetT
operator|,
name|typename
name|ErrT
operator|>
name|class
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
name|C
operator|::
operator|*
argument_list|)
argument_list|(
specifier|const
name|ErrT
operator|&
argument_list|)
operator|>
operator|:
name|public
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
operator|&
argument_list|)
argument_list|(
name|ErrT
operator|&
argument_list|)
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Specialization for member functions of the form 'RetT (const ErrT&) const'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|C
operator|,
name|typename
name|RetT
operator|,
name|typename
name|ErrT
operator|>
name|class
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
argument|C::*
argument_list|)
operator|(
specifier|const
name|ErrT
operator|&
operator|)
specifier|const
operator|>
operator|:
name|public
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
operator|&
argument_list|)
argument_list|(
name|ErrT
operator|&
argument_list|)
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Specialization for member functions of the form
end_comment

begin_comment
comment|/// 'RetT (std::unique_ptr<ErrT>) const'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|C
operator|,
name|typename
name|RetT
operator|,
name|typename
name|ErrT
operator|>
name|class
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
name|C
operator|::
operator|*
argument_list|)
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ErrT
operator|>
argument_list|)
operator|>
operator|:
name|public
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
operator|&
argument_list|)
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ErrT
operator|>
argument_list|)
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Specialization for member functions of the form
end_comment

begin_comment
comment|/// 'RetT (std::unique_ptr<ErrT>) const'.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|C
operator|,
name|typename
name|RetT
operator|,
name|typename
name|ErrT
operator|>
name|class
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
argument|C::*
argument_list|)
operator|(
name|std
operator|::
name|unique_ptr
operator|<
name|ErrT
operator|>
operator|)
specifier|const
operator|>
operator|:
name|public
name|ErrorHandlerTraits
operator|<
name|RetT
argument_list|(
operator|&
argument_list|)
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ErrT
operator|>
argument_list|)
operator|>
block|{}
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|inline
name|Error
name|handleErrorImpl
argument_list|(
name|std
operator|::
name|unique_ptr
operator|<
name|ErrorInfoBase
operator|>
name|Payload
argument_list|)
block|{
return|return
name|Error
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Payload
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|HandlerT
operator|,
name|typename
operator|...
name|HandlerTs
operator|>
name|Error
name|handleErrorImpl
argument_list|(
argument|std::unique_ptr<ErrorInfoBase> Payload
argument_list|,
argument|HandlerT&&Handler
argument_list|,
argument|HandlerTs&&... Handlers
argument_list|)
block|{
if|if
condition|(
name|ErrorHandlerTraits
operator|<
name|HandlerT
operator|>
operator|::
name|appliesTo
argument_list|(
operator|*
name|Payload
argument_list|)
condition|)
return|return
name|ErrorHandlerTraits
operator|<
name|HandlerT
operator|>
operator|::
name|apply
argument_list|(
name|std
operator|::
name|forward
operator|<
name|HandlerT
operator|>
operator|(
name|Handler
operator|)
argument_list|,
name|std
operator|::
name|move
argument_list|(
name|Payload
argument_list|)
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|handleErrorImpl
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Payload
argument_list|)
argument_list|,
name|std
operator|::
name|forward
operator|<
name|HandlerTs
operator|>
operator|(
name|Handlers
operator|)
operator|...
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// Pass the ErrorInfo(s) contained in E to their respective handlers. Any
end_comment

begin_comment
comment|/// unhandled errors (or Errors returned by handlers) are re-concatenated and
end_comment

begin_comment
comment|/// returned.
end_comment

begin_comment
comment|/// Because this function returns an error, its result must also be checked
end_comment

begin_comment
comment|/// or returned. If you intend to handle all errors use handleAllErrors
end_comment

begin_comment
comment|/// (which returns void, and will abort() on unhandled errors) instead.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
operator|...
name|HandlerTs
operator|>
name|Error
name|handleErrors
argument_list|(
argument|Error E
argument_list|,
argument|HandlerTs&&... Hs
argument_list|)
block|{
if|if
condition|(
operator|!
name|E
condition|)
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
name|std
operator|::
name|unique_ptr
operator|<
name|ErrorInfoBase
operator|>
name|Payload
operator|=
name|E
operator|.
name|takePayload
argument_list|()
expr_stmt|;
end_expr_stmt

begin_if
if|if
condition|(
name|Payload
operator|->
name|isA
operator|<
name|ErrorList
operator|>
operator|(
operator|)
condition|)
block|{
name|ErrorList
modifier|&
name|List
init|=
name|static_cast
operator|<
name|ErrorList
operator|&
operator|>
operator|(
operator|*
name|Payload
operator|)
decl_stmt|;
name|Error
name|R
decl_stmt|;
for|for
control|(
name|auto
operator|&
name|P
operator|:
name|List
operator|.
name|Payloads
control|)
name|R
operator|=
name|ErrorList
operator|::
name|join
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|R
argument_list|)
argument_list|,
name|handleErrorImpl
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|P
argument_list|)
argument_list|,
name|std
operator|::
name|forward
operator|<
name|HandlerTs
operator|>
operator|(
name|Hs
operator|)
operator|...
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|R
return|;
block|}
end_if

begin_return
return|return
name|handleErrorImpl
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Payload
argument_list|)
argument_list|,
name|std
operator|::
name|forward
operator|<
name|HandlerTs
operator|>
operator|(
name|Hs
operator|)
operator|...
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// Behaves the same as handleErrors, except that it requires that all
end_comment

begin_comment
comment|/// errors be handled by the given handlers. If any unhandled error remains
end_comment

begin_comment
comment|/// after the handlers have run, abort() will be called.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
operator|...
name|HandlerTs
operator|>
name|void
name|handleAllErrors
argument_list|(
argument|Error E
argument_list|,
argument|HandlerTs&&... Handlers
argument_list|)
block|{
name|auto
name|F
operator|=
name|handleErrors
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|E
argument_list|)
argument_list|,
name|std
operator|::
name|forward
operator|<
name|HandlerTs
operator|>
operator|(
name|Handlers
operator|)
operator|...
argument_list|)
block|;
comment|// Cast 'F' to bool to set the 'Checked' flag if it's a success value:
operator|(
name|void
operator|)
operator|!
name|F
block|; }
comment|/// Check that E is a non-error, then drop it.
specifier|inline
name|void
name|handleAllErrors
argument_list|(
argument|Error E
argument_list|)
block|{
comment|// Cast 'E' to a bool to set the 'Checked' flag if it's a success value:
operator|(
name|void
operator|)
operator|!
name|E
block|; }
comment|/// Log all errors (if any) in E to OS. If there are any errors, ErrorBanner
comment|/// will be printed before the first one is logged. A newline will be printed
comment|/// after each error.
comment|///
comment|/// This is useful in the base level of your program to allow clean termination
comment|/// (allowing clean deallocation of resources, etc.), while reporting error
comment|/// information to the user.
name|void
name|logAllUnhandledErrors
argument_list|(
argument|Error E
argument_list|,
argument|raw_ostream&OS
argument_list|,
argument|Twine ErrorBanner
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Write all error messages (if any) in E to a string. The newline character
end_comment

begin_comment
comment|/// is used to separate error messages.
end_comment

begin_expr_stmt
specifier|inline
name|std
operator|::
name|string
name|toString
argument_list|(
argument|Error E
argument_list|)
block|{
name|SmallVector
operator|<
name|std
operator|::
name|string
block|,
literal|2
operator|>
name|Errors
block|;
name|handleAllErrors
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|E
argument_list|)
argument_list|,
index|[
operator|&
name|Errors
index|]
operator|(
specifier|const
name|ErrorInfoBase
operator|&
name|EI
operator|)
block|{
name|Errors
operator|.
name|push_back
argument_list|(
name|EI
operator|.
name|message
argument_list|()
argument_list|)
block|;   }
argument_list|)
block|;
return|return
name|join
argument_list|(
name|Errors
operator|.
name|begin
argument_list|()
argument_list|,
name|Errors
operator|.
name|end
argument_list|()
argument_list|,
literal|"\n"
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Consume a Error without doing anything. This method should be used
end_comment

begin_comment
comment|/// only where an error can be considered a reasonable and expected return
end_comment

begin_comment
comment|/// value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Uses of this method are potentially indicative of design problems: If it's
end_comment

begin_comment
comment|/// legitimate to do nothing while processing an "error", the error-producer
end_comment

begin_comment
comment|/// might be more clearly refactored to return an Optional<T>.
end_comment

begin_function
specifier|inline
name|void
name|consumeError
parameter_list|(
name|Error
name|Err
parameter_list|)
block|{
name|handleAllErrors
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
argument_list|,
index|[]
operator|(
specifier|const
name|ErrorInfoBase
operator|&
operator|)
block|{}
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Helper for Errors used as out-parameters.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This helper is for use with the Error-as-out-parameter idiom, where an error
end_comment

begin_comment
comment|/// is passed to a function or method by reference, rather than being returned.
end_comment

begin_comment
comment|/// In such cases it is helpful to set the checked bit on entry to the function
end_comment

begin_comment
comment|/// so that the error can be written to (unchecked Errors abort on assignment)
end_comment

begin_comment
comment|/// and clear the checked bit on exit so that clients cannot accidentally forget
end_comment

begin_comment
comment|/// to check the result. This helper performs these actions automatically using
end_comment

begin_comment
comment|/// RAII:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   @code{.cpp}
end_comment

begin_comment
comment|///   Result foo(Error&Err) {
end_comment

begin_comment
comment|///     ErrorAsOutParameter ErrAsOutParam(&Err); // 'Checked' flag set
end_comment

begin_comment
comment|///     //<body of foo>
end_comment

begin_comment
comment|///     //<- 'Checked' flag auto-cleared when ErrAsOutParam is destructed.
end_comment

begin_comment
comment|///   }
end_comment

begin_comment
comment|///   @endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// ErrorAsOutParameter takes an Error* rather than Error& so that it can be
end_comment

begin_comment
comment|/// used with optional Errors (Error pointers that are allowed to be null). If
end_comment

begin_comment
comment|/// ErrorAsOutParameter took an Error reference, an instance would have to be
end_comment

begin_comment
comment|/// created inside every condition that verified that Error was non-null. By
end_comment

begin_comment
comment|/// taking an Error pointer we can just create one instance at the top of the
end_comment

begin_comment
comment|/// function.
end_comment

begin_decl_stmt
name|class
name|ErrorAsOutParameter
block|{
name|public
label|:
name|ErrorAsOutParameter
argument_list|(
name|Error
operator|*
name|Err
argument_list|)
operator|:
name|Err
argument_list|(
argument|Err
argument_list|)
block|{
comment|// Raise the checked bit if Err is success.
if|if
condition|(
name|Err
condition|)
operator|(
name|void
operator|)
operator|!
operator|!
operator|*
name|Err
expr_stmt|;
block|}
operator|~
name|ErrorAsOutParameter
argument_list|()
block|{
comment|// Clear the checked bit.
if|if
condition|(
name|Err
operator|&&
operator|!
operator|*
name|Err
condition|)
operator|*
name|Err
operator|=
name|Error
operator|::
name|success
argument_list|()
expr_stmt|;
block|}
name|private
label|:
name|Error
modifier|*
name|Err
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Tagged union holding either a T or a Error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This class parallels ErrorOr, but replaces error_code with Error. Since
end_comment

begin_comment
comment|/// Error cannot be copied, this class replaces getError() with
end_comment

begin_comment
comment|/// takeError(). It also adds an bool errorIsA<ErrT>() method for testing the
end_comment

begin_comment
comment|/// error class type.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|LLVM_NODISCARD
name|Expected
block|{
name|template
operator|<
name|class
name|T1
operator|>
name|friend
name|class
name|ExpectedAsOutParameter
block|;
name|template
operator|<
name|class
name|OtherT
operator|>
name|friend
name|class
name|Expected
block|;
specifier|static
specifier|const
name|bool
name|isRef
operator|=
name|std
operator|::
name|is_reference
operator|<
name|T
operator|>
operator|::
name|value
block|;
typedef|typedef
name|ReferenceStorage
operator|<
name|typename
name|std
operator|::
name|remove_reference
operator|<
name|T
operator|>
operator|::
name|type
operator|>
name|wrap
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|unique_ptr
operator|<
name|ErrorInfoBase
operator|>
name|error_type
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|conditional
operator|<
name|isRef
operator|,
name|wrap
operator|,
name|T
operator|>
operator|::
name|type
name|storage_type
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|T
name|value_type
typedef|;
end_typedef

begin_label
name|private
label|:
end_label

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|remove_reference
operator|<
name|T
operator|>
operator|::
name|type
operator|&
name|reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|typename
name|std
operator|::
name|remove_reference
operator|<
name|T
operator|>
operator|::
name|type
operator|&
name|const_reference
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|std
operator|::
name|remove_reference
operator|<
name|T
operator|>
operator|::
name|type
operator|*
name|pointer
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
specifier|const
name|typename
name|std
operator|::
name|remove_reference
operator|<
name|T
operator|>
operator|::
name|type
operator|*
name|const_pointer
expr_stmt|;
end_typedef

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Create an Expected<T> error value from the given Error.
end_comment

begin_macro
name|Expected
argument_list|(
argument|Error Err
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|HasError
argument_list|(
name|true
argument_list|)
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
comment|// Expected is unchecked upon construction in Debug builds.
operator|,
name|Unchecked
argument_list|(
argument|true
argument_list|)
endif|#
directive|endif
block|{
name|assert
argument_list|(
name|Err
operator|&&
literal|"Cannot create Expected<T> from Error success value."
argument_list|)
block|;
name|new
argument_list|(
argument|getErrorStorage()
argument_list|)
name|error_type
argument_list|(
name|Err
operator|.
name|takePayload
argument_list|()
argument_list|)
block|;   }
comment|/// Forbid to convert from Error::success() implicitly, this avoids having
comment|/// Expected<T> foo() { return Error::success(); } which compiles otherwise
comment|/// but triggers the assertion above.
name|Expected
argument_list|(
name|ErrorSuccess
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Create an Expected<T> success value from the given OtherT value, which
end_comment

begin_comment
comment|/// must be convertible to T.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|OtherT
operator|>
name|Expected
argument_list|(
argument|OtherT&&Val
argument_list|,
argument|typename std::enable_if<std::is_convertible<OtherT
argument_list|,
argument|T>::value>::type                * = nullptr
argument_list|)
operator|:
name|HasError
argument_list|(
name|false
argument_list|)
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
comment|// Expected is unchecked upon construction in Debug builds.
operator|,
name|Unchecked
argument_list|(
argument|true
argument_list|)
endif|#
directive|endif
block|{
name|new
argument_list|(
argument|getStorage()
argument_list|)
name|storage_type
argument_list|(
name|std
operator|::
name|forward
operator|<
name|OtherT
operator|>
operator|(
name|Val
operator|)
argument_list|)
block|;   }
comment|/// Move construct an Expected<T> value.
name|Expected
argument_list|(
argument|Expected&&Other
argument_list|)
block|{
name|moveConstruct
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Other
argument_list|)
argument_list|)
block|; }
comment|/// Move construct an Expected<T> value from an Expected<OtherT>, where OtherT
comment|/// must be convertible to T.
name|template
operator|<
name|class
name|OtherT
operator|>
name|Expected
argument_list|(
argument|Expected<OtherT>&&Other
argument_list|,
argument|typename std::enable_if<std::is_convertible<OtherT
argument_list|,
argument|T>::value>::type                * = nullptr
argument_list|)
block|{
name|moveConstruct
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Other
argument_list|)
argument_list|)
block|;   }
comment|/// Move construct an Expected<T> value from an Expected<OtherT>, where OtherT
comment|/// isn't convertible to T.
name|template
operator|<
name|class
name|OtherT
operator|>
name|explicit
name|Expected
argument_list|(
argument|Expected<OtherT>&&Other
argument_list|,
argument|typename std::enable_if<!std::is_convertible<OtherT
argument_list|,
argument|T>::value>::type * =           nullptr
argument_list|)
block|{
name|moveConstruct
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Other
argument_list|)
argument_list|)
block|;   }
comment|/// Move-assign from another Expected<T>.
name|Expected
operator|&
name|operator
operator|=
operator|(
name|Expected
operator|&&
name|Other
operator|)
block|{
name|moveAssign
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Other
argument_list|)
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Destroy an Expected<T>.
end_comment

begin_expr_stmt
operator|~
name|Expected
argument_list|()
block|{
name|assertIsChecked
argument_list|()
block|;
if|if
condition|(
operator|!
name|HasError
condition|)
name|getStorage
argument_list|()
operator|->
operator|~
name|storage_type
argument_list|()
expr_stmt|;
else|else
name|getErrorStorage
argument_list|()
operator|->
operator|~
name|error_type
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Return false if there is an error.
end_comment

begin_function
name|explicit
name|operator
name|bool
parameter_list|()
block|{
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
name|Unchecked
operator|=
name|HasError
expr_stmt|;
endif|#
directive|endif
return|return
operator|!
name|HasError
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns a reference to the stored T value.
end_comment

begin_function
name|reference
name|get
parameter_list|()
block|{
name|assertIsChecked
argument_list|()
expr_stmt|;
return|return
operator|*
name|getStorage
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns a const reference to the stored T value.
end_comment

begin_expr_stmt
name|const_reference
name|get
argument_list|()
specifier|const
block|{
name|assertIsChecked
argument_list|()
block|;
return|return
name|const_cast
operator|<
name|Expected
operator|<
name|T
operator|>
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|get
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Check that this Expected<T> is an error of type ErrT.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|ErrT
operator|>
name|bool
name|errorIsA
argument_list|()
specifier|const
block|{
return|return
name|HasError
operator|&&
operator|(
operator|*
name|getErrorStorage
argument_list|()
operator|)
operator|->
name|template
name|isA
operator|<
name|ErrT
operator|>
operator|(
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Take ownership of the stored error.
end_comment

begin_comment
comment|/// After calling this the Expected<T> is in an indeterminate state that can
end_comment

begin_comment
comment|/// only be safely destructed. No further calls (beside the destructor) should
end_comment

begin_comment
comment|/// be made on the Expected<T> vaule.
end_comment

begin_function
name|Error
name|takeError
parameter_list|()
block|{
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
name|Unchecked
operator|=
name|false
expr_stmt|;
endif|#
directive|endif
return|return
name|HasError
condition|?
name|Error
argument_list|(
name|std
operator|::
name|move
argument_list|(
operator|*
name|getErrorStorage
argument_list|()
argument_list|)
argument_list|)
else|:
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns a pointer to the stored T value.
end_comment

begin_expr_stmt
name|pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_block
unit|)
block|{
name|assertIsChecked
argument_list|()
expr_stmt|;
return|return
name|toPointer
argument_list|(
name|getStorage
argument_list|()
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/// \brief Returns a const pointer to the stored T value.
end_comment

begin_expr_stmt
name|const_pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
name|assertIsChecked
argument_list|()
block|;
return|return
name|toPointer
argument_list|(
name|getStorage
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// \brief Returns a reference to the stored T value.
end_comment

begin_function
name|reference
name|operator
modifier|*
parameter_list|()
block|{
name|assertIsChecked
argument_list|()
expr_stmt|;
return|return
operator|*
name|getStorage
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// \brief Returns a const reference to the stored T value.
end_comment

begin_expr_stmt
name|const_reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
name|assertIsChecked
argument_list|()
block|;
return|return
operator|*
name|getStorage
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|template
operator|<
name|class
name|T1
operator|>
specifier|static
name|bool
name|compareThisIfSameType
argument_list|(
argument|const T1&a
argument_list|,
argument|const T1&b
argument_list|)
block|{
return|return
operator|&
name|a
operator|==
operator|&
name|b
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|T1
operator|,
name|class
name|T2
operator|>
specifier|static
name|bool
name|compareThisIfSameType
argument_list|(
argument|const T1&a
argument_list|,
argument|const T2&b
argument_list|)
block|{
return|return
name|false
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|OtherT
operator|>
name|void
name|moveConstruct
argument_list|(
argument|Expected<OtherT>&&Other
argument_list|)
block|{
name|HasError
operator|=
name|Other
operator|.
name|HasError
block|;
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
name|Unchecked
operator|=
name|true
block|;
name|Other
operator|.
name|Unchecked
operator|=
name|false
block|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|HasError
condition|)
name|new
argument_list|(
argument|getStorage()
argument_list|)
name|storage_type
argument_list|(
name|std
operator|::
name|move
argument_list|(
operator|*
name|Other
operator|.
name|getStorage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
else|else
name|new
argument_list|(
argument|getErrorStorage()
argument_list|)
name|error_type
argument_list|(
name|std
operator|::
name|move
argument_list|(
operator|*
name|Other
operator|.
name|getErrorStorage
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|OtherT
operator|>
name|void
name|moveAssign
argument_list|(
argument|Expected<OtherT>&&Other
argument_list|)
block|{
name|assertIsChecked
argument_list|()
block|;
if|if
condition|(
name|compareThisIfSameType
argument_list|(
operator|*
name|this
argument_list|,
name|Other
argument_list|)
condition|)
return|return;
name|this
operator|->
block|~
name|Expected
argument_list|()
expr_stmt|;
end_expr_stmt

begin_macro
name|new
argument_list|(
argument|this
argument_list|)
end_macro

begin_expr_stmt
name|Expected
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Other
argument_list|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_macro
unit|}    pointer
name|toPointer
argument_list|(
argument|pointer Val
argument_list|)
end_macro

begin_block
block|{
return|return
name|Val
return|;
block|}
end_block

begin_decl_stmt
name|const_pointer
name|toPointer
argument_list|(
name|const_pointer
name|Val
argument_list|)
decl|const
block|{
return|return
name|Val
return|;
block|}
end_decl_stmt

begin_function
name|pointer
name|toPointer
parameter_list|(
name|wrap
modifier|*
name|Val
parameter_list|)
block|{
return|return
operator|&
name|Val
operator|->
name|get
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|const_pointer
name|toPointer
argument_list|(
specifier|const
name|wrap
operator|*
name|Val
argument_list|)
decl|const
block|{
return|return
operator|&
name|Val
operator|->
name|get
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|storage_type
modifier|*
name|getStorage
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|HasError
operator|&&
literal|"Cannot get value when an error exists!"
argument_list|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
name|storage_type
operator|*
operator|>
operator|(
name|TStorage
operator|.
name|buffer
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|storage_type
operator|*
name|getStorage
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|HasError
operator|&&
literal|"Cannot get value when an error exists!"
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|storage_type
operator|*
operator|>
operator|(
name|TStorage
operator|.
name|buffer
operator|)
return|;
block|}
end_expr_stmt

begin_function
name|error_type
modifier|*
name|getErrorStorage
parameter_list|()
block|{
name|assert
argument_list|(
name|HasError
operator|&&
literal|"Cannot get error when a value exists!"
argument_list|)
expr_stmt|;
return|return
name|reinterpret_cast
operator|<
name|error_type
operator|*
operator|>
operator|(
name|ErrorStorage
operator|.
name|buffer
operator|)
return|;
block|}
end_function

begin_expr_stmt
specifier|const
name|error_type
operator|*
name|getErrorStorage
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|HasError
operator|&&
literal|"Cannot get error when a value exists!"
argument_list|)
block|;
return|return
name|reinterpret_cast
operator|<
specifier|const
name|error_type
operator|*
operator|>
operator|(
name|ErrorStorage
operator|.
name|buffer
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Used by ExpectedAsOutParameter to reset the checked flag.
end_comment

begin_function
name|void
name|setUnchecked
parameter_list|()
block|{
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
name|Unchecked
operator|=
name|true
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|assertIsChecked
parameter_list|()
block|{
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
if|if
condition|(
name|Unchecked
condition|)
block|{
name|dbgs
argument_list|()
operator|<<
literal|"Expected<T> must be checked before access or destruction.\n"
expr_stmt|;
if|if
condition|(
name|HasError
condition|)
block|{
name|dbgs
argument_list|()
operator|<<
literal|"Unchecked Expected<T> contained error:\n"
expr_stmt|;
operator|(
operator|*
name|getErrorStorage
argument_list|()
operator|)
operator|->
name|log
argument_list|(
name|dbgs
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
name|dbgs
argument_list|()
operator|<<
literal|"Expected<T> value was in success state. (Note: Expected<T> "
literal|"values in success mode must still be checked prior to being "
literal|"destroyed).\n"
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
endif|#
directive|endif
block|}
end_function

begin_union
union|union
block|{
name|AlignedCharArrayUnion
operator|<
name|storage_type
operator|>
name|TStorage
expr_stmt|;
name|AlignedCharArrayUnion
operator|<
name|error_type
operator|>
name|ErrorStorage
expr_stmt|;
block|}
union|;
end_union

begin_decl_stmt
name|bool
name|HasError
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|LLVM_ENABLE_ABI_BREAKING_CHECKS
end_if

begin_decl_stmt
name|bool
name|Unchecked
range|:
literal|1
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
unit|};
comment|/// Helper for Expected<T>s used as out-parameters.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// See ErrorAsOutParameter.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ExpectedAsOutParameter
block|{
name|public
operator|:
name|ExpectedAsOutParameter
argument_list|(
name|Expected
operator|<
name|T
operator|>
operator|*
name|ValOrErr
argument_list|)
operator|:
name|ValOrErr
argument_list|(
argument|ValOrErr
argument_list|)
block|{
if|if
condition|(
name|ValOrErr
condition|)
operator|(
name|void
operator|)
operator|!
operator|!
operator|*
name|ValOrErr
expr_stmt|;
block|}
operator|~
name|ExpectedAsOutParameter
argument_list|()
block|{
if|if
condition|(
name|ValOrErr
condition|)
name|ValOrErr
operator|->
name|setUnchecked
argument_list|()
expr_stmt|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|Expected
operator|<
name|T
operator|>
operator|*
name|ValOrErr
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// This class wraps a std::error_code in a Error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is useful if you're writing an interface that returns a Error
end_comment

begin_comment
comment|/// (or Expected) and you want to call code that still returns
end_comment

begin_comment
comment|/// std::error_codes.
end_comment

begin_decl_stmt
name|class
name|ECError
range|:
name|public
name|ErrorInfo
operator|<
name|ECError
operator|>
block|{
name|friend
name|Error
name|errorCodeToError
argument_list|(
name|std
operator|::
name|error_code
argument_list|)
block|;
name|public
operator|:
name|void
name|setErrorCode
argument_list|(
argument|std::error_code EC
argument_list|)
block|{
name|this
operator|->
name|EC
operator|=
name|EC
block|; }
name|std
operator|::
name|error_code
name|convertToErrorCode
argument_list|()
specifier|const
name|override
block|{
return|return
name|EC
return|;
block|}
name|void
name|log
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|{
name|OS
operator|<<
name|EC
operator|.
name|message
argument_list|()
block|; }
comment|// Used by ErrorInfo::classID.
specifier|static
name|char
name|ID
block|;
name|protected
operator|:
name|ECError
argument_list|()
operator|=
expr|default
block|;
name|ECError
argument_list|(
argument|std::error_code EC
argument_list|)
operator|:
name|EC
argument_list|(
argument|EC
argument_list|)
block|{}
name|std
operator|::
name|error_code
name|EC
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The value returned by this function can be returned from convertToErrorCode
end_comment

begin_comment
comment|/// for Error values where no sensible translation to std::error_code exists.
end_comment

begin_comment
comment|/// It should only be used in this situation, and should never be used where a
end_comment

begin_comment
comment|/// sensible conversion to std::error_code is available, as attempts to convert
end_comment

begin_comment
comment|/// to/from this error will result in a fatal error. (i.e. it is a programmatic
end_comment

begin_comment
comment|///error to try to convert such a value).
end_comment

begin_expr_stmt
name|std
operator|::
name|error_code
name|inconvertibleErrorCode
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Helper for converting an std::error_code to a Error.
end_comment

begin_decl_stmt
name|Error
name|errorCodeToError
argument_list|(
name|std
operator|::
name|error_code
name|EC
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Helper for converting an ECError to a std::error_code.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This method requires that Err be Error() or an ECError, otherwise it
end_comment

begin_comment
comment|/// will trigger a call to abort().
end_comment

begin_expr_stmt
name|std
operator|::
name|error_code
name|errorToErrorCode
argument_list|(
argument|Error Err
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Convert an ErrorOr<T> to an Expected<T>.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|Expected
operator|<
name|T
operator|>
name|errorOrToExpected
argument_list|(
argument|ErrorOr<T>&&EO
argument_list|)
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|EO
operator|.
name|getError
argument_list|()
condition|)
return|return
name|errorCodeToError
argument_list|(
name|EC
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|EO
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// Convert an Expected<T> to an ErrorOr<T>.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|T
operator|>
name|ErrorOr
operator|<
name|T
operator|>
name|expectedToErrorOr
argument_list|(
argument|Expected<T>&&E
argument_list|)
block|{
if|if
condition|(
name|auto
name|Err
init|=
name|E
operator|.
name|takeError
argument_list|()
condition|)
return|return
name|errorToErrorCode
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
argument_list|)
return|;
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|E
argument_list|)
return|;
end_return

begin_comment
unit|}
comment|/// This class wraps a string in an Error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// StringError is useful in cases where the client is not expected to be able
end_comment

begin_comment
comment|/// to consume the specific error message programmatically (for example, if the
end_comment

begin_comment
comment|/// error message is to be presented to the user).
end_comment

begin_label
unit|class
name|StringError
label|:
end_label

begin_expr_stmt
name|public
name|ErrorInfo
operator|<
name|StringError
operator|>
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|StringError
argument_list|(
argument|const Twine&S
argument_list|,
argument|std::error_code EC
argument_list|)
block|;
name|void
name|log
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|;
name|std
operator|::
name|error_code
name|convertToErrorCode
argument_list|()
specifier|const
name|override
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getMessage
argument_list|()
specifier|const
block|{
return|return
name|Msg
return|;
block|}
name|private
operator|:
name|std
operator|::
name|string
name|Msg
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|std
operator|::
name|error_code
name|EC
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|/// Helper for check-and-exit error handling.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For tool use only. NOT FOR USE IN LIBRARY CODE.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|ExitOnError
block|{
name|public
label|:
comment|/// Create an error on exit helper.
name|ExitOnError
argument_list|(
argument|std::string Banner =
literal|""
argument_list|,
argument|int DefaultErrorExitCode =
literal|1
argument_list|)
block|:
name|Banner
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Banner
argument_list|)
argument_list|)
operator|,
name|GetExitCode
argument_list|(
argument|[=](const Error&) { return DefaultErrorExitCode; }
argument_list|)
block|{}
comment|/// Set the banner string for any errors caught by operator().
name|void
name|setBanner
argument_list|(
argument|std::string Banner
argument_list|)
block|{
name|this
operator|->
name|Banner
operator|=
name|std
operator|::
name|move
argument_list|(
name|Banner
argument_list|)
block|; }
comment|/// Set the exit-code mapper function.
name|void
name|setExitCodeMapper
argument_list|(
argument|std::function<int(const Error&)> GetExitCode
argument_list|)
block|{
name|this
operator|->
name|GetExitCode
operator|=
name|std
operator|::
name|move
argument_list|(
name|GetExitCode
argument_list|)
block|;   }
comment|/// Check Err. If it's in a failure state log the error(s) and exit.
name|void
name|operator
argument_list|()
operator|(
name|Error
name|Err
operator|)
specifier|const
block|{
name|checkError
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
argument_list|)
block|; }
comment|/// Check E. If it's in a success state then return the contained value. If
comment|/// it's in a failure state log the error(s) and exit.
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|operator
argument_list|()
operator|(
name|Expected
operator|<
name|T
operator|>
operator|&&
name|E
operator|)
specifier|const
block|{
name|checkError
argument_list|(
name|E
operator|.
name|takeError
argument_list|()
argument_list|)
block|;
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|E
argument_list|)
return|;
block|}
comment|/// Check E. If it's in a success state then return the contained reference. If
comment|/// it's in a failure state log the error(s) and exit.
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|&
name|operator
argument_list|()
operator|(
name|Expected
operator|<
name|T
operator|&
operator|>
operator|&&
name|E
operator|)
specifier|const
block|{
name|checkError
argument_list|(
name|E
operator|.
name|takeError
argument_list|()
argument_list|)
block|;
return|return
operator|*
name|E
return|;
block|}
name|private
label|:
name|void
name|checkError
argument_list|(
name|Error
name|Err
argument_list|)
decl|const
block|{
if|if
condition|(
name|Err
condition|)
block|{
name|int
name|ExitCode
init|=
name|GetExitCode
argument_list|(
name|Err
argument_list|)
decl_stmt|;
name|logAllUnhandledErrors
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
argument_list|,
name|errs
argument_list|()
argument_list|,
name|Banner
argument_list|)
expr_stmt|;
name|exit
argument_list|(
name|ExitCode
argument_list|)
expr_stmt|;
block|}
block|}
name|std
operator|::
name|string
name|Banner
expr_stmt|;
name|std
operator|::
name|function
operator|<
name|int
argument_list|(
specifier|const
name|Error
operator|&
argument_list|)
operator|>
name|GetExitCode
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Report a serious error, calling any installed error handler. See
end_comment

begin_comment
comment|/// ErrorHandling.h.
end_comment

begin_function_decl
name|LLVM_ATTRIBUTE_NORETURN
name|void
name|report_fatal_error
parameter_list|(
name|Error
name|Err
parameter_list|,
name|bool
name|gen_crash_diag
init|=
name|true
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Report a fatal error if Err is a failure value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be used to wrap calls to fallible functions ONLY when it
end_comment

begin_comment
comment|/// is known that the Error will always be a success value. E.g.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   @code{.cpp}
end_comment

begin_comment
comment|///   // foo only attempts the fallible operation if DoFallibleOperation is
end_comment

begin_comment
comment|///   // true. If DoFallibleOperation is false then foo always returns
end_comment

begin_comment
comment|///   // Error::success().
end_comment

begin_comment
comment|///   Error foo(bool DoFallibleOperation);
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   cantFail(foo(false));
end_comment

begin_comment
comment|///   @endcode
end_comment

begin_function
specifier|inline
name|void
name|cantFail
parameter_list|(
name|Error
name|Err
parameter_list|)
block|{
if|if
condition|(
name|Err
condition|)
name|llvm_unreachable
argument_list|(
literal|"Failure value returned from cantFail wrapped call"
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// Report a fatal error if ValOrErr is a failure value, otherwise unwraps and
end_comment

begin_comment
comment|/// returns the contained value.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function can be used to wrap calls to fallible functions ONLY when it
end_comment

begin_comment
comment|/// is known that the Error will always be a success value. E.g.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   @code{.cpp}
end_comment

begin_comment
comment|///   // foo only attempts the fallible operation if DoFallibleOperation is
end_comment

begin_comment
comment|///   // true. If DoFallibleOperation is false then foo always returns an int.
end_comment

begin_comment
comment|///   Expected<int> foo(bool DoFallibleOperation);
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   int X = cantFail(foo(false));
end_comment

begin_comment
comment|///   @endcode
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|T
name|cantFail
argument_list|(
argument|Expected<T> ValOrErr
argument_list|)
block|{
if|if
condition|(
name|ValOrErr
condition|)
return|return
name|std
operator|::
name|move
argument_list|(
operator|*
name|ValOrErr
argument_list|)
return|;
else|else
name|llvm_unreachable
argument_list|(
literal|"Failure value returned from cantFail wrapped call"
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_ERROR_H
end_comment

end_unit

