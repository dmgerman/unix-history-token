begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CleanUp.h -----------------------------------------------*- C++ -*-===//
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
name|liblldb_CleanUp_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_CleanUp_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-public.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|lldb_utility
block|{
comment|//----------------------------------------------------------------------
comment|// Templated class that guarantees that a cleanup callback function will
comment|// be called. The cleanup function will be called once under the
comment|// following conditions:
comment|// - when the object goes out of scope
comment|// - when the user explicitly calls clean.
comment|// - the current value will be cleaned up when a new value is set using
comment|//   set(T value) as long as the current value hasn't already been cleaned.
comment|//
comment|// This class is designed to be used with simple types for type T (like
comment|// file descriptors, opaque handles, pointers, etc). If more complex
comment|// type T objects are desired, we need to probably specialize this class
comment|// to take "const T&" for all input T parameters. Yet if a type T is
comment|// complex already it might be better to build the cleanup functionality
comment|// into T.
comment|//
comment|// The cleanup function must take one argument that is of type T.
comment|// The calback function return type is R. The return value is currently
comment|// needed for "CallbackType". If there is an easy way to get around the
comment|// need for the return value we can change this class.
comment|//
comment|// The two template parameters are:
comment|//    T - The variable type of value that will be stored and used as the
comment|//      sole argument for the cleanup callback.
comment|//    R - The return type for the cleanup function.
comment|//
comment|// EXAMPLES
comment|//  // Use with file handles that get opened where you want to close
comment|//  // them. Below we use "int open(const char *path, int oflag, ...)"
comment|//  // which returns an integer file descriptor. -1 is the invalid file
comment|//  // descriptor so to make an object that will call "int close(int fd)"
comment|//  // automatically we can use:
comment|//
comment|//  CleanUp<int, int> fd(open("/tmp/a.txt", O_RDONLY, 0), -1, close);
comment|//
comment|//  // malloc/free example
comment|//  CleanUp<void *, void> malloced_bytes(malloc(32), NULL, free);
comment|//----------------------------------------------------------------------
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|R
operator|=
name|void
operator|>
name|class
name|CleanUp
block|{
name|public
operator|:
typedef|typedef
name|T
name|value_type
typedef|;
typedef|typedef
name|std
operator|::
name|function
operator|<
name|R
argument_list|(
name|value_type
argument_list|)
operator|>
name|CallbackType
expr_stmt|;
comment|//----------------------------------------------------------------------
comment|// Constructor that sets the current value only. No values are
comment|// considered to be invalid and the cleanup function will be called
comment|// regardless of the value of m_current_value.
comment|//----------------------------------------------------------------------
name|CleanUp
argument_list|(
argument|value_type value
argument_list|,
argument|CallbackType callback
argument_list|)
block|:
name|m_current_value
argument_list|(
name|value
argument_list|)
operator|,
name|m_invalid_value
argument_list|()
operator|,
name|m_callback
argument_list|(
name|callback
argument_list|)
operator|,
name|m_callback_called
argument_list|(
name|false
argument_list|)
operator|,
name|m_invalid_value_is_valid
argument_list|(
argument|false
argument_list|)
block|{     }
comment|//----------------------------------------------------------------------
comment|// Constructor that sets the current value and also the invalid value.
comment|// The cleanup function will be called on "m_value" as long as it isn't
comment|// equal to "m_invalid_value".
comment|//----------------------------------------------------------------------
name|CleanUp
argument_list|(
argument|value_type value
argument_list|,
argument|value_type invalid
argument_list|,
argument|CallbackType callback
argument_list|)
operator|:
name|m_current_value
argument_list|(
name|value
argument_list|)
operator|,
name|m_invalid_value
argument_list|(
name|invalid
argument_list|)
operator|,
name|m_callback
argument_list|(
name|callback
argument_list|)
operator|,
name|m_callback_called
argument_list|(
name|false
argument_list|)
operator|,
name|m_invalid_value_is_valid
argument_list|(
argument|true
argument_list|)
block|{     }
comment|//----------------------------------------------------------------------
comment|// Automatically cleanup when this object goes out of scope.
comment|//----------------------------------------------------------------------
operator|~
name|CleanUp
argument_list|()
block|{
name|clean
argument_list|()
block|;     }
comment|//----------------------------------------------------------------------
comment|// Access the value stored in this class
comment|//----------------------------------------------------------------------
name|value_type
name|get
argument_list|()
block|{
return|return
name|m_current_value
return|;
block|}
comment|//----------------------------------------------------------------------
comment|// Access the value stored in this class
comment|//----------------------------------------------------------------------
specifier|const
name|value_type
name|get
argument_list|()
specifier|const
block|{
return|return
name|m_current_value
return|;
block|}
comment|//----------------------------------------------------------------------
comment|// Reset the owned value to "value". If a current value is valid and
comment|// the cleanup callback hasn't been called, the previous value will
comment|// be cleaned up (see void CleanUp::clean()).
comment|//----------------------------------------------------------------------
name|void
name|set
parameter_list|(
specifier|const
name|value_type
name|value
parameter_list|)
block|{
comment|// Cleanup the current value if needed
name|clean
argument_list|()
expr_stmt|;
comment|// Now set the new value and mark our callback as not called
name|m_callback_called
operator|=
name|false
expr_stmt|;
name|m_current_value
operator|=
name|value
expr_stmt|;
block|}
comment|//----------------------------------------------------------------------
comment|// Checks is "m_current_value" is valid. The value is considered valid
comment|// no invalid value was supplied during construction of this object or
comment|// if an invalid value was supplied and "m_current_value" is not equal
comment|// to "m_invalid_value".
comment|//
comment|// Returns true if "m_current_value" is valid, false otherwise.
comment|//----------------------------------------------------------------------
name|bool
name|is_valid
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_invalid_value_is_valid
condition|)
return|return
name|m_current_value
operator|!=
name|m_invalid_value
return|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// This function will call the cleanup callback provided in the
end_comment

begin_comment
comment|// constructor one time if the value is considered valid (See is_valid()).
end_comment

begin_comment
comment|// This function sets m_callback_called to true so we don't call the
end_comment

begin_comment
comment|// cleanup callback multiple times on the same value.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function
name|void
name|clean
parameter_list|()
block|{
if|if
condition|(
name|m_callback
operator|&&
operator|!
name|m_callback_called
condition|)
block|{
name|m_callback_called
operator|=
name|true
expr_stmt|;
if|if
condition|(
name|is_valid
argument_list|()
condition|)
name|m_callback
argument_list|(
name|m_current_value
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Cancels the cleanup that would have been called on "m_current_value"
end_comment

begin_comment
comment|// if it was valid. This function can be used to release the value
end_comment

begin_comment
comment|// contained in this object so ownership can be transferred to the caller.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function
name|value_type
name|release
parameter_list|()
block|{
name|m_callback_called
operator|=
name|true
expr_stmt|;
return|return
name|m_current_value
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|value_type
name|m_current_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|value_type
name|m_invalid_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CallbackType
name|m_callback
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_callback_called
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_invalid_value_is_valid
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Outlaw default constructor, copy constructor and the assignment operator
end_comment

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|CleanUp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|R
operator|,
name|typename
name|A0
operator|>
name|class
name|CleanUp2
block|{
name|public
operator|:
typedef|typedef
name|T
name|value_type
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|function
operator|<
name|R
argument_list|(
name|value_type
argument_list|,
name|A0
argument_list|)
operator|>
name|CallbackType
expr_stmt|;
end_typedef

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Constructor that sets the current value only. No values are
end_comment

begin_comment
comment|// considered to be invalid and the cleanup function will be called
end_comment

begin_comment
comment|// regardless of the value of m_current_value.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_macro
name|CleanUp2
argument_list|(
argument|value_type value
argument_list|,
argument|CallbackType callback
argument_list|,
argument|A0 arg
argument_list|)
end_macro

begin_expr_stmt
unit|:
name|m_current_value
argument_list|(
name|value
argument_list|)
operator|,
name|m_invalid_value
argument_list|()
operator|,
name|m_callback
argument_list|(
name|callback
argument_list|)
operator|,
name|m_callback_called
argument_list|(
name|false
argument_list|)
operator|,
name|m_invalid_value_is_valid
argument_list|(
name|false
argument_list|)
operator|,
name|m_argument
argument_list|(
argument|arg
argument_list|)
block|{     }
comment|//----------------------------------------------------------------------
comment|// Constructor that sets the current value and also the invalid value.
comment|// The cleanup function will be called on "m_value" as long as it isn't
comment|// equal to "m_invalid_value".
comment|//----------------------------------------------------------------------
name|CleanUp2
argument_list|(
argument|value_type value
argument_list|,
argument|value_type invalid
argument_list|,
argument|CallbackType callback
argument_list|,
argument|A0 arg
argument_list|)
operator|:
name|m_current_value
argument_list|(
name|value
argument_list|)
operator|,
name|m_invalid_value
argument_list|(
name|invalid
argument_list|)
operator|,
name|m_callback
argument_list|(
name|callback
argument_list|)
operator|,
name|m_callback_called
argument_list|(
name|false
argument_list|)
operator|,
name|m_invalid_value_is_valid
argument_list|(
name|true
argument_list|)
operator|,
name|m_argument
argument_list|(
argument|arg
argument_list|)
block|{     }
comment|//----------------------------------------------------------------------
comment|// Automatically cleanup when this object goes out of scope.
comment|//----------------------------------------------------------------------
operator|~
name|CleanUp2
argument_list|()
block|{
name|clean
argument_list|()
block|;     }
comment|//----------------------------------------------------------------------
comment|// Access the value stored in this class
comment|//----------------------------------------------------------------------
name|value_type
name|get
argument_list|()
block|{
return|return
name|m_current_value
return|;
block|}
end_expr_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Access the value stored in this class
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_expr_stmt
specifier|const
name|value_type
name|get
argument_list|()
specifier|const
block|{
return|return
name|m_current_value
return|;
block|}
end_expr_stmt

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Reset the owned value to "value". If a current value is valid and
end_comment

begin_comment
comment|// the cleanup callback hasn't been called, the previous value will
end_comment

begin_comment
comment|// be cleaned up (see void CleanUp::clean()).
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function
name|void
name|set
parameter_list|(
specifier|const
name|value_type
name|value
parameter_list|)
block|{
comment|// Cleanup the current value if needed
name|clean
argument_list|()
expr_stmt|;
comment|// Now set the new value and mark our callback as not called
name|m_callback_called
operator|=
name|false
expr_stmt|;
name|m_current_value
operator|=
name|value
expr_stmt|;
block|}
end_function

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Checks is "m_current_value" is valid. The value is considered valid
end_comment

begin_comment
comment|// no invalid value was supplied during construction of this object or
end_comment

begin_comment
comment|// if an invalid value was supplied and "m_current_value" is not equal
end_comment

begin_comment
comment|// to "m_invalid_value".
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Returns true if "m_current_value" is valid, false otherwise.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_expr_stmt
name|bool
name|is_valid
argument_list|()
specifier|const
block|{
if|if
condition|(
name|m_invalid_value_is_valid
condition|)
return|return
name|m_current_value
operator|!=
name|m_invalid_value
return|;
end_expr_stmt

begin_return
return|return
name|true
return|;
end_return

begin_comment
unit|}
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// This function will call the cleanup callback provided in the
end_comment

begin_comment
comment|// constructor one time if the value is considered valid (See is_valid()).
end_comment

begin_comment
comment|// This function sets m_callback_called to true so we don't call the
end_comment

begin_comment
comment|// cleanup callback multiple times on the same value.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_macro
unit|void
name|clean
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
name|m_callback
operator|&&
operator|!
name|m_callback_called
condition|)
block|{
name|m_callback_called
operator|=
name|true
expr_stmt|;
if|if
condition|(
name|is_valid
argument_list|()
condition|)
name|m_callback
argument_list|(
name|m_current_value
argument_list|,
name|m_argument
argument_list|)
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Cancels the cleanup that would have been called on "m_current_value"
end_comment

begin_comment
comment|// if it was valid. This function can be used to release the value
end_comment

begin_comment
comment|// contained in this object so ownership can be transferred to the caller.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_function
name|value_type
name|release
parameter_list|()
block|{
name|m_callback_called
operator|=
name|true
expr_stmt|;
return|return
name|m_current_value
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|value_type
name|m_current_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|value_type
name|m_invalid_value
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|CallbackType
name|m_callback
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_callback_called
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|bool
name|m_invalid_value_is_valid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|A0
name|m_argument
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Outlaw default constructor, copy constructor and the assignment operator
end_comment

begin_expr_stmt
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|CleanUp2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace lldb_utility
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_CleanUp_h_
end_comment

end_unit

