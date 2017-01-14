begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2007, Google Inc.
end_comment

begin_comment
comment|// All rights reserved.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Redistribution and use in source and binary forms, with or without
end_comment

begin_comment
comment|// modification, are permitted provided that the following conditions are
end_comment

begin_comment
comment|// met:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//     * Redistributions of source code must retain the above copyright
end_comment

begin_comment
comment|// notice, this list of conditions and the following disclaimer.
end_comment

begin_comment
comment|//     * Redistributions in binary form must reproduce the above
end_comment

begin_comment
comment|// copyright notice, this list of conditions and the following disclaimer
end_comment

begin_comment
comment|// in the documentation and/or other materials provided with the
end_comment

begin_comment
comment|// distribution.
end_comment

begin_comment
comment|//     * Neither the name of Google Inc. nor the names of its
end_comment

begin_comment
comment|// contributors may be used to endorse or promote products derived from
end_comment

begin_comment
comment|// this software without specific prior written permission.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
end_comment

begin_comment
comment|// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
end_comment

begin_comment
comment|// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
end_comment

begin_comment
comment|// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
end_comment

begin_comment
comment|// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
end_comment

begin_comment
comment|// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
end_comment

begin_comment
comment|// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
end_comment

begin_comment
comment|// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
end_comment

begin_comment
comment|// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
end_comment

begin_comment
comment|// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Author: wan@google.com (Zhanyong Wan)
end_comment

begin_comment
comment|// Google Mock - a framework for writing C++ mock classes.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file implements some commonly used actions.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GMOCK_INCLUDE_GMOCK_GMOCK_ACTIONS_H_
end_ifndef

begin_define
define|#
directive|define
name|GMOCK_INCLUDE_GMOCK_GMOCK_ACTIONS_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_WIN32_WCE
end_ifndef

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|"gmock/internal/gmock-internal-utils.h"
end_include

begin_include
include|#
directive|include
file|"gmock/internal/gmock-port.h"
end_include

begin_if
if|#
directive|if
name|GTEST_HAS_STD_TYPE_TRAITS_
end_if

begin_comment
comment|// Defined by gtest-port.h via gmock-port.h.
end_comment

begin_include
include|#
directive|include
file|<type_traits>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|testing
block|{
comment|// To implement an action Foo, define:
comment|//   1. a class FooAction that implements the ActionInterface interface, and
comment|//   2. a factory function that creates an Action object from a
comment|//      const FooAction*.
comment|//
comment|// The two-level delegation design follows that of Matcher, providing
comment|// consistency for extension developers.  It also eases ownership
comment|// management as Action objects can now be copied like plain values.
name|namespace
name|internal
block|{
name|template
operator|<
name|typename
name|F1
operator|,
name|typename
name|F2
operator|>
name|class
name|ActionAdaptor
expr_stmt|;
comment|// BuiltInDefaultValueGetter<T, true>::Get() returns a
comment|// default-constructed T value.  BuiltInDefaultValueGetter<T,
comment|// false>::Get() crashes with an error.
comment|//
comment|// This primary template is used when kDefaultConstructible is true.
name|template
operator|<
name|typename
name|T
operator|,
name|bool
name|kDefaultConstructible
operator|>
expr|struct
name|BuiltInDefaultValueGetter
block|{
specifier|static
name|T
name|Get
argument_list|()
block|{
return|return
name|T
argument_list|()
return|;
block|}
expr|}
block|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|BuiltInDefaultValueGetter
operator|<
name|T
block|,
name|false
operator|>
block|{
specifier|static
name|T
name|Get
argument_list|()
block|{
name|Assert
argument_list|(
name|false
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|,
literal|"Default action undefined for the function return type."
argument_list|)
block|;
return|return
name|internal
operator|::
name|Invalid
operator|<
name|T
operator|>
operator|(
operator|)
return|;
comment|// The above statement will never be reached, but is required in
comment|// order for this function to compile.
block|}
expr|}
block|;
comment|// BuiltInDefaultValue<T>::Get() returns the "built-in" default value
comment|// for type T, which is NULL when T is a raw pointer type, 0 when T is
comment|// a numeric type, false when T is bool, or "" when T is string or
comment|// std::string.  In addition, in C++11 and above, it turns a
comment|// default-constructed T value if T is default constructible.  For any
comment|// other type T, the built-in default T value is undefined, and the
comment|// function will abort the process.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|BuiltInDefaultValue
block|{
name|public
operator|:
if|#
directive|if
name|GTEST_HAS_STD_TYPE_TRAITS_
comment|// This function returns true iff type T has a built-in default value.
specifier|static
name|bool
name|Exists
argument_list|()
block|{
return|return
operator|::
name|std
operator|::
name|is_default_constructible
operator|<
name|T
operator|>
operator|::
name|value
return|;
block|}
specifier|static
name|T
name|Get
argument_list|()
block|{
return|return
name|BuiltInDefaultValueGetter
operator|<
name|T
operator|,
operator|::
name|std
operator|::
name|is_default_constructible
operator|<
name|T
operator|>
operator|::
name|value
operator|>
operator|::
name|Get
argument_list|()
return|;
block|}
else|#
directive|else
comment|// GTEST_HAS_STD_TYPE_TRAITS_
comment|// This function returns true iff type T has a built-in default value.
specifier|static
name|bool
name|Exists
argument_list|()
block|{
return|return
name|false
return|;
block|}
specifier|static
name|T
name|Get
argument_list|()
block|{
return|return
name|BuiltInDefaultValueGetter
operator|<
name|T
operator|,
name|false
operator|>
operator|::
name|Get
argument_list|()
return|;
block|}
endif|#
directive|endif
comment|// GTEST_HAS_STD_TYPE_TRAITS_
expr|}
block|;
comment|// This partial specialization says that we use the same built-in
comment|// default value for T and const T.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|BuiltInDefaultValue
operator|<
specifier|const
name|T
operator|>
block|{
name|public
operator|:
specifier|static
name|bool
name|Exists
argument_list|()
block|{
return|return
name|BuiltInDefaultValue
operator|<
name|T
operator|>
operator|::
name|Exists
argument_list|()
return|;
block|}
specifier|static
name|T
name|Get
argument_list|()
block|{
return|return
name|BuiltInDefaultValue
operator|<
name|T
operator|>
operator|::
name|Get
argument_list|()
return|;
block|}
expr|}
block|;
comment|// This partial specialization defines the default values for pointer
comment|// types.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|BuiltInDefaultValue
operator|<
name|T
operator|*
operator|>
block|{
name|public
operator|:
specifier|static
name|bool
name|Exists
argument_list|()
block|{
return|return
name|true
return|;
block|}
specifier|static
name|T
operator|*
name|Get
argument_list|()
block|{
return|return
name|NULL
return|;
block|}
expr|}
block|;
comment|// The following specializations define the default values for
comment|// specific types we care about.
define|#
directive|define
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
parameter_list|(
name|type
parameter_list|,
name|value
parameter_list|)
define|\
value|template<> \   class BuiltInDefaultValue<type> { \    public: \     static bool Exists() { return true; } \     static type Get() { return value; } \   }
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
name|void
argument_list|, )
block|;
comment|// NOLINT
if|#
directive|if
name|GTEST_HAS_GLOBAL_STRING
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
operator|::
name|string
argument_list|,
literal|""
argument_list|)
block|;
endif|#
directive|endif
comment|// GTEST_HAS_GLOBAL_STRING
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
operator|::
name|std
operator|::
name|string
argument_list|,
literal|""
argument_list|)
block|;
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
name|bool
argument_list|,
name|false
argument_list|)
block|;
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
argument|unsigned char
argument_list|,
literal|'\0'
argument_list|)
block|;
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
argument|signed char
argument_list|,
literal|'\0'
argument_list|)
block|;
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
name|char
argument_list|,
literal|'\0'
argument_list|)
block|;
comment|// There's no need for a default action for signed wchar_t, as that
comment|// type is the same as wchar_t for gcc, and invalid for MSVC.
comment|//
comment|// There's also no need for a default action for unsigned wchar_t, as
comment|// that type is the same as unsigned int for gcc, and invalid for
comment|// MSVC.
if|#
directive|if
name|GMOCK_WCHAR_T_IS_NATIVE_
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
name|wchar_t
argument_list|,
literal|0U
argument_list|)
block|;
comment|// NOLINT
endif|#
directive|endif
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
argument|unsigned short
argument_list|,
literal|0U
argument_list|)
block|;
comment|// NOLINT
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
argument|signed short
argument_list|,
literal|0
argument_list|)
block|;
comment|// NOLINT
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
argument|unsigned int
argument_list|,
literal|0U
argument_list|)
block|;
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
argument|signed int
argument_list|,
literal|0
argument_list|)
block|;
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
argument|unsigned long
argument_list|,
literal|0UL
argument_list|)
block|;
comment|// NOLINT
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
argument|signed long
argument_list|,
literal|0L
argument_list|)
block|;
comment|// NOLINT
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
name|UInt64
argument_list|,
literal|0
argument_list|)
block|;
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
name|Int64
argument_list|,
literal|0
argument_list|)
block|;
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
name|float
argument_list|,
literal|0
argument_list|)
block|;
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
argument_list|(
name|double
argument_list|,
literal|0
argument_list|)
block|;
undef|#
directive|undef
name|GMOCK_DEFINE_DEFAULT_ACTION_FOR_RETURN_TYPE_
block|}
comment|// namespace internal
comment|// When an unexpected function call is encountered, Google Mock will
comment|// let it return a default value if the user has specified one for its
comment|// return type, or if the return type has a built-in default value;
comment|// otherwise Google Mock won't know what value to return and will have
comment|// to abort the process.
comment|//
comment|// The DefaultValue<T> class allows a user to specify the
comment|// default value for a type T that is both copyable and publicly
comment|// destructible (i.e. anything that can be used as a function return
comment|// type).  The usage is:
comment|//
comment|//   // Sets the default value for type T to be foo.
comment|//   DefaultValue<T>::Set(foo);
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|DefaultValue
block|{
name|public
operator|:
comment|// Sets the default value for type T; requires T to be
comment|// copy-constructable and have a public destructor.
specifier|static
name|void
name|Set
argument_list|(
argument|T x
argument_list|)
block|{
name|delete
name|producer_
block|;
name|producer_
operator|=
name|new
name|FixedValueProducer
argument_list|(
name|x
argument_list|)
block|;   }
comment|// Provides a factory function to be called to generate the default value.
comment|// This method can be used even if T is only move-constructible, but it is not
comment|// limited to that case.
typedef|typedef
name|T
function_decl|(
modifier|*
name|FactoryFunction
function_decl|)
parameter_list|()
function_decl|;
specifier|static
name|void
name|SetFactory
argument_list|(
argument|FactoryFunction factory
argument_list|)
block|{
name|delete
name|producer_
block|;
name|producer_
operator|=
name|new
name|FactoryValueProducer
argument_list|(
name|factory
argument_list|)
block|;   }
comment|// Unsets the default value for type T.
specifier|static
name|void
name|Clear
argument_list|()
block|{
name|delete
name|producer_
block|;
name|producer_
operator|=
name|NULL
block|;   }
comment|// Returns true iff the user has set the default value for type T.
specifier|static
name|bool
name|IsSet
argument_list|()
block|{
return|return
name|producer_
operator|!=
name|NULL
return|;
block|}
comment|// Returns true if T has a default return value set by the user or there
comment|// exists a built-in default value.
specifier|static
name|bool
name|Exists
argument_list|()
block|{
return|return
name|IsSet
argument_list|()
operator|||
name|internal
operator|::
name|BuiltInDefaultValue
operator|<
name|T
operator|>
operator|::
name|Exists
argument_list|()
return|;
block|}
comment|// Returns the default value for type T if the user has set one;
comment|// otherwise returns the built-in default value. Requires that Exists()
comment|// is true, which ensures that the return value is well-defined.
specifier|static
name|T
name|Get
argument_list|()
block|{
return|return
name|producer_
operator|==
name|NULL
operator|?
name|internal
operator|::
name|BuiltInDefaultValue
operator|<
name|T
operator|>
operator|::
name|Get
argument_list|()
operator|:
name|producer_
operator|->
name|Produce
argument_list|()
return|;
block|}
name|private
operator|:
name|class
name|ValueProducer
block|{
name|public
operator|:
name|virtual
operator|~
name|ValueProducer
argument_list|()
block|{}
name|virtual
name|T
name|Produce
argument_list|()
operator|=
literal|0
block|;   }
block|;
name|class
name|FixedValueProducer
operator|:
name|public
name|ValueProducer
block|{
name|public
operator|:
name|explicit
name|FixedValueProducer
argument_list|(
argument|T value
argument_list|)
operator|:
name|value_
argument_list|(
argument|value
argument_list|)
block|{}
name|virtual
name|T
name|Produce
argument_list|()
block|{
return|return
name|value_
return|;
block|}
name|private
operator|:
specifier|const
name|T
name|value_
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|FixedValueProducer
argument_list|)
block|;   }
block|;
name|class
name|FactoryValueProducer
operator|:
name|public
name|ValueProducer
block|{
name|public
operator|:
name|explicit
name|FactoryValueProducer
argument_list|(
argument|FactoryFunction factory
argument_list|)
operator|:
name|factory_
argument_list|(
argument|factory
argument_list|)
block|{}
name|virtual
name|T
name|Produce
argument_list|()
block|{
return|return
name|factory_
argument_list|()
return|;
block|}
name|private
operator|:
specifier|const
name|FactoryFunction
name|factory_
block|;
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|FactoryValueProducer
argument_list|)
block|;   }
block|;
specifier|static
name|ValueProducer
operator|*
name|producer_
block|; }
block|;
comment|// This partial specialization allows a user to set default values for
comment|// reference types.
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|DefaultValue
operator|<
name|T
operator|&
operator|>
block|{
name|public
operator|:
comment|// Sets the default value for type T&.
specifier|static
name|void
name|Set
argument_list|(
argument|T& x
argument_list|)
block|{
comment|// NOLINT
name|address_
operator|=
operator|&
name|x
block|;   }
comment|// Unsets the default value for type T&.
specifier|static
name|void
name|Clear
argument_list|()
block|{
name|address_
operator|=
name|NULL
block|;   }
comment|// Returns true iff the user has set the default value for type T&.
specifier|static
name|bool
name|IsSet
argument_list|()
block|{
return|return
name|address_
operator|!=
name|NULL
return|;
block|}
comment|// Returns true if T has a default return value set by the user or there
comment|// exists a built-in default value.
specifier|static
name|bool
name|Exists
argument_list|()
block|{
return|return
name|IsSet
argument_list|()
operator|||
name|internal
operator|::
name|BuiltInDefaultValue
operator|<
name|T
operator|&
operator|>
operator|::
name|Exists
argument_list|()
return|;
block|}
comment|// Returns the default value for type T& if the user has set one;
comment|// otherwise returns the built-in default value if there is one;
comment|// otherwise aborts the process.
specifier|static
name|T
operator|&
name|Get
argument_list|()
block|{
return|return
name|address_
operator|==
name|NULL
condition|?
name|internal
operator|::
name|BuiltInDefaultValue
operator|<
name|T
operator|&
operator|>
operator|::
name|Get
argument_list|()
else|:
operator|*
name|address_
return|;
block|}
name|private
operator|:
specifier|static
name|T
operator|*
name|address_
block|; }
block|;
comment|// This specialization allows DefaultValue<void>::Get() to
comment|// compile.
name|template
operator|<
operator|>
name|class
name|DefaultValue
operator|<
name|void
operator|>
block|{
name|public
operator|:
specifier|static
name|bool
name|Exists
argument_list|()
block|{
return|return
name|true
return|;
block|}
specifier|static
name|void
name|Get
argument_list|()
block|{}
expr|}
block|;
comment|// Points to the user-set default value for type T.
name|template
operator|<
name|typename
name|T
operator|>
name|typename
name|DefaultValue
operator|<
name|T
operator|>
operator|::
name|ValueProducer
operator|*
name|DefaultValue
operator|<
name|T
operator|>
operator|::
name|producer_
operator|=
name|NULL
block|;
comment|// Points to the user-set default value for type T&.
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|DefaultValue
operator|<
name|T
operator|&
operator|>
operator|::
name|address_
operator|=
name|NULL
block|;
comment|// Implement this interface to define an action for function type F.
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|ActionInterface
block|{
name|public
operator|:
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
name|ActionInterface
argument_list|()
block|{}
name|virtual
operator|~
name|ActionInterface
argument_list|()
block|{}
comment|// Performs the action.  This method is not const, as in general an
comment|// action can have side effects and be stateful.  For example, a
comment|// get-the-next-element-from-the-collection action will need to
comment|// remember the current element.
name|virtual
name|Result
name|Perform
argument_list|(
specifier|const
name|ArgumentTuple
operator|&
name|args
argument_list|)
operator|=
literal|0
block|;
name|private
operator|:
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|ActionInterface
argument_list|)
block|; }
block|;
comment|// An Action<F> is a copyable and IMMUTABLE (except by assignment)
comment|// object that represents an action to be taken when a mock function
comment|// of type F is called.  The implementation of Action<T> is just a
comment|// linked_ptr to const ActionInterface<T>, so copying is fairly cheap.
comment|// Don't inherit from Action!
comment|//
comment|// You can view an object implementing ActionInterface<F> as a
comment|// concrete action (including its current state), and an Action<F>
comment|// object as a handle to it.
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|Action
block|{
name|public
operator|:
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
comment|// Constructs a null Action.  Needed for storing Action objects in
comment|// STL containers.
name|Action
argument_list|()
operator|:
name|impl_
argument_list|(
argument|NULL
argument_list|)
block|{}
comment|// Constructs an Action from its implementation.  A NULL impl is
comment|// used to represent the "do-default" action.
name|explicit
name|Action
argument_list|(
name|ActionInterface
operator|<
name|F
operator|>
operator|*
name|impl
argument_list|)
operator|:
name|impl_
argument_list|(
argument|impl
argument_list|)
block|{}
comment|// Copy constructor.
name|Action
argument_list|(
specifier|const
name|Action
operator|&
name|action
argument_list|)
operator|:
name|impl_
argument_list|(
argument|action.impl_
argument_list|)
block|{}
comment|// This constructor allows us to turn an Action<Func> object into an
comment|// Action<F>, as long as F's arguments can be implicitly converted
comment|// to Func's and Func's return type can be implicitly converted to
comment|// F's.
name|template
operator|<
name|typename
name|Func
operator|>
name|explicit
name|Action
argument_list|(
specifier|const
name|Action
operator|<
name|Func
operator|>
operator|&
name|action
argument_list|)
block|;
comment|// Returns true iff this is the DoDefault() action.
name|bool
name|IsDoDefault
argument_list|()
specifier|const
block|{
return|return
name|impl_
operator|.
name|get
argument_list|()
operator|==
name|NULL
return|;
block|}
comment|// Performs the action.  Note that this method is const even though
comment|// the corresponding method in ActionInterface is not.  The reason
comment|// is that a const Action<F> means that it cannot be re-bound to
comment|// another concrete action, not that the concrete action it binds to
comment|// cannot change state.  (Think of the difference between a const
comment|// pointer and a pointer to const.)
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple& args
argument_list|)
specifier|const
block|{
name|internal
operator|::
name|Assert
argument_list|(
operator|!
name|IsDoDefault
argument_list|()
argument_list|,
name|__FILE__
argument_list|,
name|__LINE__
argument_list|,
literal|"You are using DoDefault() inside a composite action like "
literal|"DoAll() or WithArgs().  This is not supported for technical "
literal|"reasons.  Please instead spell out the default action, or "
literal|"assign the default action to an Action variable and use "
literal|"the variable in various places."
argument_list|)
block|;
return|return
name|impl_
operator|->
name|Perform
argument_list|(
name|args
argument_list|)
return|;
block|}
name|private
operator|:
name|template
operator|<
name|typename
name|F1
block|,
name|typename
name|F2
operator|>
name|friend
name|class
name|internal
operator|::
name|ActionAdaptor
block|;
name|internal
operator|::
name|linked_ptr
operator|<
name|ActionInterface
operator|<
name|F
operator|>
expr|>
name|impl_
block|; }
expr_stmt|;
comment|// The PolymorphicAction class template makes it easy to implement a
comment|// polymorphic action (i.e. an action that can be used in mock
comment|// functions of than one type, e.g. Return()).
comment|//
comment|// To define a polymorphic action, a user first provides a COPYABLE
comment|// implementation class that has a Perform() method template:
comment|//
comment|//   class FooAction {
comment|//    public:
comment|//     template<typename Result, typename ArgumentTuple>
comment|//     Result Perform(const ArgumentTuple& args) const {
comment|//       // Processes the arguments and returns a result, using
comment|//       // tr1::get<N>(args) to get the N-th (0-based) argument in the tuple.
comment|//     }
comment|//     ...
comment|//   };
comment|//
comment|// Then the user creates the polymorphic action using
comment|// MakePolymorphicAction(object) where object has type FooAction.  See
comment|// the definition of Return(void) and SetArgumentPointee<N>(value) for
comment|// complete examples.
name|template
operator|<
name|typename
name|Impl
operator|>
name|class
name|PolymorphicAction
block|{
name|public
operator|:
name|explicit
name|PolymorphicAction
argument_list|(
specifier|const
name|Impl
operator|&
name|impl
argument_list|)
operator|:
name|impl_
argument_list|(
argument|impl
argument_list|)
block|{}
name|template
operator|<
name|typename
name|F
operator|>
name|operator
name|Action
operator|<
name|F
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Action
operator|<
name|F
operator|>
operator|(
name|new
name|MonomorphicImpl
operator|<
name|F
operator|>
operator|(
name|impl_
operator|)
operator|)
return|;
block|}
name|private
operator|:
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|MonomorphicImpl
operator|:
name|public
name|ActionInterface
operator|<
name|F
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
name|explicit
name|MonomorphicImpl
argument_list|(
specifier|const
name|Impl
operator|&
name|impl
argument_list|)
operator|:
name|impl_
argument_list|(
argument|impl
argument_list|)
block|{}
name|virtual
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple& args
argument_list|)
block|{
return|return
name|impl_
operator|.
name|template
name|Perform
operator|<
name|Result
operator|>
operator|(
name|args
operator|)
return|;
block|}
name|private
label|:
name|Impl
name|impl_
decl_stmt|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|MonomorphicImpl
argument_list|)
expr_stmt|;
block|}
empty_stmt|;
name|Impl
name|impl_
decl_stmt|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|PolymorphicAction
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Creates an Action from its implementation and returns it.  The
end_comment

begin_comment
comment|// created Action object owns the implementation.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|F
operator|>
name|Action
operator|<
name|F
operator|>
name|MakeAction
argument_list|(
argument|ActionInterface<F>* impl
argument_list|)
block|{
return|return
name|Action
operator|<
name|F
operator|>
operator|(
name|impl
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a polymorphic action from its implementation.  This is
end_comment

begin_comment
comment|// easier to use than the PolymorphicAction<Impl> constructor as it
end_comment

begin_comment
comment|// doesn't require you to explicitly write the template argument, e.g.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   MakePolymorphicAction(foo);
end_comment

begin_comment
comment|// vs
end_comment

begin_comment
comment|//   PolymorphicAction<TypeOfFoo>(foo);
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|Impl
operator|>
specifier|inline
name|PolymorphicAction
operator|<
name|Impl
operator|>
name|MakePolymorphicAction
argument_list|(
argument|const Impl& impl
argument_list|)
block|{
return|return
name|PolymorphicAction
operator|<
name|Impl
operator|>
operator|(
name|impl
operator|)
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|namespace
name|internal
block|{
comment|// Allows an Action<F2> object to pose as an Action<F1>, as long as F2
comment|// and F1 are compatible.
name|template
operator|<
name|typename
name|F1
operator|,
name|typename
name|F2
operator|>
name|class
name|ActionAdaptor
operator|:
name|public
name|ActionInterface
operator|<
name|F1
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F1
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F1
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
name|explicit
name|ActionAdaptor
argument_list|(
specifier|const
name|Action
operator|<
name|F2
operator|>
operator|&
name|from
argument_list|)
range|:
name|impl_
argument_list|(
argument|from.impl_
argument_list|)
block|{}
name|virtual
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple& args
argument_list|)
block|{
return|return
name|impl_
operator|->
name|Perform
argument_list|(
name|args
argument_list|)
return|;
block|}
name|private
label|:
specifier|const
name|internal
operator|::
name|linked_ptr
operator|<
name|ActionInterface
operator|<
name|F2
operator|>
expr|>
name|impl_
expr_stmt|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ActionAdaptor
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Helper struct to specialize ReturnAction to execute a move instead of a copy
end_comment

begin_comment
comment|// on return. Useful for move-only types, but could be used on any type.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|ByMoveWrapper
block|{
name|explicit
name|ByMoveWrapper
argument_list|(
argument|T value
argument_list|)
operator|:
name|payload
argument_list|(
argument|internal::move(value)
argument_list|)
block|{}
name|T
name|payload
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Implements the polymorphic Return(x) action, which can be used in
end_comment

begin_comment
comment|// any function that returns the type of x, regardless of the argument
end_comment

begin_comment
comment|// types.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: The value passed into Return must be converted into
end_comment

begin_comment
comment|// Function<F>::Result when this action is cast to Action<F> rather than
end_comment

begin_comment
comment|// when that action is performed. This is important in scenarios like
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// MOCK_METHOD1(Method, T(U));
end_comment

begin_comment
comment|// ...
end_comment

begin_comment
comment|// {
end_comment

begin_comment
comment|//   Foo foo;
end_comment

begin_comment
comment|//   X x(&foo);
end_comment

begin_comment
comment|//   EXPECT_CALL(mock, Method(_)).WillOnce(Return(x));
end_comment

begin_comment
comment|// }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// In the example above the variable x holds reference to foo which leaves
end_comment

begin_comment
comment|// scope and gets destroyed.  If copying X just copies a reference to foo,
end_comment

begin_comment
comment|// that copy will be left with a hanging reference.  If conversion to T
end_comment

begin_comment
comment|// makes a copy of foo, the above code is safe. To support that scenario, we
end_comment

begin_comment
comment|// need to make sure that the type conversion happens inside the EXPECT_CALL
end_comment

begin_comment
comment|// statement, and conversion of the result of Return to Action<T(U)> is a
end_comment

begin_comment
comment|// good place for that.
end_comment

begin_comment
comment|//
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|R
operator|>
name|class
name|ReturnAction
block|{
name|public
operator|:
comment|// Constructs a ReturnAction object from the value to be returned.
comment|// 'value' is passed by value instead of by const reference in order
comment|// to allow Return("string literal") to compile.
name|explicit
name|ReturnAction
argument_list|(
argument|R value
argument_list|)
operator|:
name|value_
argument_list|(
argument|new R(internal::move(value))
argument_list|)
block|{}
comment|// This template type conversion operator allows Return(x) to be
comment|// used in ANY function that returns x's type.
name|template
operator|<
name|typename
name|F
operator|>
name|operator
name|Action
operator|<
name|F
operator|>
operator|(
operator|)
specifier|const
block|{
comment|// Assert statement belongs here because this is the best place to verify
comment|// conditions on F. It produces the clearest error messages
comment|// in most compilers.
comment|// Impl really belongs in this scope as a local class but can't
comment|// because MSVC produces duplicate symbols in different translation units
comment|// in this case. Until MS fixes that bug we put Impl into the class scope
comment|// and put the typedef both here (for use in assert statement) and
comment|// in the Impl class. But both definitions must be the same.
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
name|GTEST_COMPILE_ASSERT_
argument_list|(
operator|!
name|is_reference
operator|<
name|Result
operator|>
operator|::
name|value
argument_list|,
name|use_ReturnRef_instead_of_Return_to_return_a_reference
argument_list|)
block|;
return|return
name|Action
operator|<
name|F
operator|>
operator|(
name|new
name|Impl
operator|<
name|R
operator|,
name|F
operator|>
operator|(
name|value_
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Implements the Return(x) action for a particular function type F.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|R_
operator|,
name|typename
name|F
operator|>
name|class
name|Impl
operator|:
name|public
name|ActionInterface
operator|<
name|F
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
end_typedef

begin_comment
comment|// The implicit cast is necessary when Result has more than one
end_comment

begin_comment
comment|// single-argument constructor (e.g. Result is std::vector<int>) and R
end_comment

begin_comment
comment|// has a type conversion operator template.  In that case, value_(value)
end_comment

begin_comment
comment|// won't compile as the compiler doesn't known which constructor of
end_comment

begin_comment
comment|// Result to call.  ImplicitCast_ forces the compiler to convert R to
end_comment

begin_comment
comment|// Result without considering explicit constructors, thus resolving the
end_comment

begin_comment
comment|// ambiguity. value_ is then initialized using its copy constructor.
end_comment

begin_decl_stmt
name|explicit
name|Impl
argument_list|(
specifier|const
name|linked_ptr
operator|<
name|R
operator|>
operator|&
name|value
argument_list|)
range|:
name|value_before_cast_
argument_list|(
operator|*
name|value
argument_list|)
decl_stmt|,
name|value_
argument_list|(
name|ImplicitCast_
operator|<
name|Result
operator|>
operator|(
name|value_before_cast_
operator|)
argument_list|)
block|{}
end_decl_stmt

begin_function
name|virtual
name|Result
name|Perform
parameter_list|(
specifier|const
name|ArgumentTuple
modifier|&
parameter_list|)
block|{
return|return
name|value_
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|GTEST_COMPILE_ASSERT_
argument_list|(
operator|!
name|is_reference
operator|<
name|Result
operator|>
operator|::
name|value
argument_list|,
name|Result_cannot_be_a_reference_type
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// We save the value before casting just in case it is being cast to a
end_comment

begin_comment
comment|// wrapper type.
end_comment

begin_decl_stmt
name|R
name|value_before_cast_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Result
name|value_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_COPY_AND_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Partially specialize for ByMoveWrapper. This version of ReturnAction will
end_comment

begin_comment
comment|// move its contents instead.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|R_
operator|,
name|typename
name|F
operator|>
name|class
name|Impl
operator|<
name|ByMoveWrapper
operator|<
name|R_
operator|>
operator|,
name|F
operator|>
operator|:
name|public
name|ActionInterface
operator|<
name|F
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
end_typedef

begin_decl_stmt
name|explicit
name|Impl
argument_list|(
specifier|const
name|linked_ptr
operator|<
name|R
operator|>
operator|&
name|wrapper
argument_list|)
range|:
name|performed_
argument_list|(
name|false
argument_list|)
decl_stmt|,
name|wrapper_
argument_list|(
name|wrapper
argument_list|)
block|{}
end_decl_stmt

begin_function
name|virtual
name|Result
name|Perform
parameter_list|(
specifier|const
name|ArgumentTuple
modifier|&
parameter_list|)
block|{
name|GTEST_CHECK_
argument_list|(
operator|!
name|performed_
argument_list|)
operator|<<
literal|"A ByMove() action should only be performed once."
expr_stmt|;
name|performed_
operator|=
name|true
expr_stmt|;
return|return
name|internal
operator|::
name|move
argument_list|(
name|wrapper_
operator|->
name|payload
argument_list|)
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|bool
name|performed_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|const
name|linked_ptr
operator|<
name|R
operator|>
name|wrapper_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
unit|};
specifier|const
name|linked_ptr
operator|<
name|R
operator|>
name|value_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ReturnAction
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the ReturnNull() action.
end_comment

begin_decl_stmt
name|class
name|ReturnNullAction
block|{
name|public
label|:
comment|// Allows ReturnNull() to be used in any pointer-returning function. In C++11
comment|// this is enforced by returning nullptr, and in non-C++11 by asserting a
comment|// pointer type on compile time.
name|template
operator|<
name|typename
name|Result
operator|,
name|typename
name|ArgumentTuple
operator|>
specifier|static
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple&
argument_list|)
block|{
if|#
directive|if
name|GTEST_LANG_CXX11
return|return
name|nullptr
return|;
else|#
directive|else
name|GTEST_COMPILE_ASSERT_
argument_list|(
name|internal
operator|::
name|is_pointer
operator|<
name|Result
operator|>
operator|::
name|value
argument_list|,
name|ReturnNull_can_be_used_to_return_a_pointer_only
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
endif|#
directive|endif
comment|// GTEST_LANG_CXX11
block|}
end_decl_stmt

begin_comment
unit|};
comment|// Implements the Return() action.
end_comment

begin_decl_stmt
name|class
name|ReturnVoidAction
block|{
name|public
label|:
comment|// Allows Return() to be used in any void-returning function.
name|template
operator|<
name|typename
name|Result
operator|,
name|typename
name|ArgumentTuple
operator|>
specifier|static
name|void
name|Perform
argument_list|(
argument|const ArgumentTuple&
argument_list|)
block|{
name|CompileAssertTypesEqual
operator|<
name|void
block|,
name|Result
operator|>
operator|(
operator|)
block|;   }
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Implements the polymorphic ReturnRef(x) action, which can be used
end_comment

begin_comment
comment|// in any function that returns a reference to the type of x,
end_comment

begin_comment
comment|// regardless of the argument types.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ReturnRefAction
block|{
name|public
operator|:
comment|// Constructs a ReturnRefAction object from the reference to be returned.
name|explicit
name|ReturnRefAction
argument_list|(
name|T
operator|&
name|ref
argument_list|)
operator|:
name|ref_
argument_list|(
argument|ref
argument_list|)
block|{}
comment|// NOLINT
comment|// This template type conversion operator allows ReturnRef(x) to be
comment|// used in ANY function that returns a reference to x's type.
name|template
operator|<
name|typename
name|F
operator|>
name|operator
name|Action
operator|<
name|F
operator|>
operator|(
operator|)
specifier|const
block|{
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
comment|// Asserts that the function return type is a reference.  This
comment|// catches the user error of using ReturnRef(x) when Return(x)
comment|// should be used, and generates some helpful error message.
name|GTEST_COMPILE_ASSERT_
argument_list|(
name|internal
operator|::
name|is_reference
operator|<
name|Result
operator|>
operator|::
name|value
argument_list|,
name|use_Return_instead_of_ReturnRef_to_return_a_value
argument_list|)
block|;
return|return
name|Action
operator|<
name|F
operator|>
operator|(
name|new
name|Impl
operator|<
name|F
operator|>
operator|(
name|ref_
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Implements the ReturnRef(x) action for a particular function type F.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|Impl
operator|:
name|public
name|ActionInterface
operator|<
name|F
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
end_typedef

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|Impl
argument_list|(
name|T
operator|&
name|ref
argument_list|)
operator|:
name|ref_
argument_list|(
argument|ref
argument_list|)
block|{}
comment|// NOLINT
name|virtual
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple&
argument_list|)
block|{
return|return
name|ref_
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|T
modifier|&
name|ref_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|T
modifier|&
name|ref_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ReturnRefAction
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the polymorphic ReturnRefOfCopy(x) action, which can be
end_comment

begin_comment
comment|// used in any function that returns a reference to the type of x,
end_comment

begin_comment
comment|// regardless of the argument types.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ReturnRefOfCopyAction
block|{
name|public
operator|:
comment|// Constructs a ReturnRefOfCopyAction object from the reference to
comment|// be returned.
name|explicit
name|ReturnRefOfCopyAction
argument_list|(
specifier|const
name|T
operator|&
name|value
argument_list|)
operator|:
name|value_
argument_list|(
argument|value
argument_list|)
block|{}
comment|// NOLINT
comment|// This template type conversion operator allows ReturnRefOfCopy(x) to be
comment|// used in ANY function that returns a reference to x's type.
name|template
operator|<
name|typename
name|F
operator|>
name|operator
name|Action
operator|<
name|F
operator|>
operator|(
operator|)
specifier|const
block|{
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
comment|// Asserts that the function return type is a reference.  This
comment|// catches the user error of using ReturnRefOfCopy(x) when Return(x)
comment|// should be used, and generates some helpful error message.
name|GTEST_COMPILE_ASSERT_
argument_list|(
name|internal
operator|::
name|is_reference
operator|<
name|Result
operator|>
operator|::
name|value
argument_list|,
name|use_Return_instead_of_ReturnRefOfCopy_to_return_a_value
argument_list|)
block|;
return|return
name|Action
operator|<
name|F
operator|>
operator|(
name|new
name|Impl
operator|<
name|F
operator|>
operator|(
name|value_
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|// Implements the ReturnRefOfCopy(x) action for a particular function type F.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|Impl
operator|:
name|public
name|ActionInterface
operator|<
name|F
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
end_typedef

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|Impl
argument_list|(
specifier|const
name|T
operator|&
name|value
argument_list|)
operator|:
name|value_
argument_list|(
argument|value
argument_list|)
block|{}
comment|// NOLINT
name|virtual
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple&
argument_list|)
block|{
return|return
name|value_
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|T
name|value_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
specifier|const
name|T
name|value_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|ReturnRefOfCopyAction
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the polymorphic DoDefault() action.
end_comment

begin_decl_stmt
name|class
name|DoDefaultAction
block|{
name|public
label|:
comment|// This template type conversion operator allows DoDefault() to be
comment|// used in any function.
name|template
operator|<
name|typename
name|F
operator|>
name|operator
name|Action
operator|<
name|F
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Action
operator|<
name|F
operator|>
operator|(
name|NULL
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// Implements the Assign action to set a given pointer referent to a
end_comment

begin_comment
comment|// particular value.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|class
name|AssignAction
block|{
name|public
operator|:
name|AssignAction
argument_list|(
argument|T1* ptr
argument_list|,
argument|T2 value
argument_list|)
operator|:
name|ptr_
argument_list|(
name|ptr
argument_list|)
block|,
name|value_
argument_list|(
argument|value
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Result
block|,
name|typename
name|ArgumentTuple
operator|>
name|void
name|Perform
argument_list|(
argument|const ArgumentTuple&
comment|/* args */
argument_list|)
specifier|const
block|{
operator|*
name|ptr_
operator|=
name|value_
block|;   }
name|private
operator|:
name|T1
operator|*
specifier|const
name|ptr_
block|;
specifier|const
name|T2
name|value_
block|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|AssignAction
argument_list|)
block|; }
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
operator|!
name|GTEST_OS_WINDOWS_MOBILE
end_if

begin_comment
comment|// Implements the SetErrnoAndReturn action to simulate return from
end_comment

begin_comment
comment|// various system calls and libc functions.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SetErrnoAndReturnAction
block|{
name|public
operator|:
name|SetErrnoAndReturnAction
argument_list|(
argument|int errno_value
argument_list|,
argument|T result
argument_list|)
operator|:
name|errno_
argument_list|(
name|errno_value
argument_list|)
block|,
name|result_
argument_list|(
argument|result
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Result
block|,
name|typename
name|ArgumentTuple
operator|>
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple&
comment|/* args */
argument_list|)
specifier|const
block|{
name|errno
operator|=
name|errno_
block|;
return|return
name|result_
return|;
block|}
name|private
operator|:
specifier|const
name|int
name|errno_
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|T
name|result_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|SetErrnoAndReturnAction
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// !GTEST_OS_WINDOWS_MOBILE
end_comment

begin_comment
comment|// Implements the SetArgumentPointee<N>(x) action for any function
end_comment

begin_comment
comment|// whose N-th argument (0-based) is a pointer to x's type.  The
end_comment

begin_comment
comment|// template parameter kIsProto is true iff type A is ProtocolMessage,
end_comment

begin_comment
comment|// proto2::Message, or a sub-class of those.
end_comment

begin_expr_stmt
name|template
operator|<
name|size_t
name|N
operator|,
name|typename
name|A
operator|,
name|bool
name|kIsProto
operator|>
name|class
name|SetArgumentPointeeAction
block|{
name|public
operator|:
comment|// Constructs an action that sets the variable pointed to by the
comment|// N-th function argument to 'value'.
name|explicit
name|SetArgumentPointeeAction
argument_list|(
specifier|const
name|A
operator|&
name|value
argument_list|)
operator|:
name|value_
argument_list|(
argument|value
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Result
block|,
name|typename
name|ArgumentTuple
operator|>
name|void
name|Perform
argument_list|(
argument|const ArgumentTuple& args
argument_list|)
specifier|const
block|{
name|CompileAssertTypesEqual
operator|<
name|void
block|,
name|Result
operator|>
operator|(
operator|)
block|;
operator|*
operator|::
name|testing
operator|::
name|get
operator|<
name|N
operator|>
operator|(
name|args
operator|)
operator|=
name|value_
block|;   }
name|private
operator|:
specifier|const
name|A
name|value_
block|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|SetArgumentPointeeAction
argument_list|)
block|; }
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|size_t
name|N
operator|,
name|typename
name|Proto
operator|>
name|class
name|SetArgumentPointeeAction
operator|<
name|N
operator|,
name|Proto
operator|,
name|true
operator|>
block|{
name|public
operator|:
comment|// Constructs an action that sets the variable pointed to by the
comment|// N-th function argument to 'proto'.  Both ProtocolMessage and
comment|// proto2::Message have the CopyFrom() method, so the same
comment|// implementation works for both.
name|explicit
name|SetArgumentPointeeAction
argument_list|(
specifier|const
name|Proto
operator|&
name|proto
argument_list|)
operator|:
name|proto_
argument_list|(
argument|new Proto
argument_list|)
block|{
name|proto_
operator|->
name|CopyFrom
argument_list|(
name|proto
argument_list|)
block|;   }
name|template
operator|<
name|typename
name|Result
block|,
name|typename
name|ArgumentTuple
operator|>
name|void
name|Perform
argument_list|(
argument|const ArgumentTuple& args
argument_list|)
specifier|const
block|{
name|CompileAssertTypesEqual
operator|<
name|void
block|,
name|Result
operator|>
operator|(
operator|)
block|;
operator|::
name|testing
operator|::
name|get
operator|<
name|N
operator|>
operator|(
name|args
operator|)
operator|->
name|CopyFrom
argument_list|(
operator|*
name|proto_
argument_list|)
block|;   }
name|private
operator|:
specifier|const
name|internal
operator|::
name|linked_ptr
operator|<
name|Proto
operator|>
name|proto_
block|;
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|SetArgumentPointeeAction
argument_list|)
block|; }
expr_stmt|;
end_expr_stmt

begin_comment
comment|// Implements the InvokeWithoutArgs(f) action.  The template argument
end_comment

begin_comment
comment|// FunctionImpl is the implementation type of f, which can be either a
end_comment

begin_comment
comment|// function pointer or a functor.  InvokeWithoutArgs(f) can be used as an
end_comment

begin_comment
comment|// Action<F> as long as f's type is compatible with F (i.e. f can be
end_comment

begin_comment
comment|// assigned to a tr1::function<F>).
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|FunctionImpl
operator|>
name|class
name|InvokeWithoutArgsAction
block|{
name|public
operator|:
comment|// The c'tor makes a copy of function_impl (either a function
comment|// pointer or a functor).
name|explicit
name|InvokeWithoutArgsAction
argument_list|(
argument|FunctionImpl function_impl
argument_list|)
operator|:
name|function_impl_
argument_list|(
argument|function_impl
argument_list|)
block|{}
comment|// Allows InvokeWithoutArgs(f) to be used as any action whose type is
comment|// compatible with f.
name|template
operator|<
name|typename
name|Result
block|,
name|typename
name|ArgumentTuple
operator|>
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple&
argument_list|)
block|{
return|return
name|function_impl_
argument_list|()
return|;
block|}
name|private
operator|:
name|FunctionImpl
name|function_impl_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|InvokeWithoutArgsAction
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the InvokeWithoutArgs(object_ptr,&Class::Method) action.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Class
operator|,
name|typename
name|MethodPtr
operator|>
name|class
name|InvokeMethodWithoutArgsAction
block|{
name|public
operator|:
name|InvokeMethodWithoutArgsAction
argument_list|(
argument|Class* obj_ptr
argument_list|,
argument|MethodPtr method_ptr
argument_list|)
operator|:
name|obj_ptr_
argument_list|(
name|obj_ptr
argument_list|)
block|,
name|method_ptr_
argument_list|(
argument|method_ptr
argument_list|)
block|{}
name|template
operator|<
name|typename
name|Result
block|,
name|typename
name|ArgumentTuple
operator|>
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple&
argument_list|)
specifier|const
block|{
return|return
operator|(
name|obj_ptr_
operator|->*
name|method_ptr_
operator|)
operator|(
operator|)
return|;
block|}
name|private
operator|:
name|Class
operator|*
specifier|const
name|obj_ptr_
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|MethodPtr
name|method_ptr_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|InvokeMethodWithoutArgsAction
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Implements the IgnoreResult(action) action.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|A
operator|>
name|class
name|IgnoreResultAction
block|{
name|public
operator|:
name|explicit
name|IgnoreResultAction
argument_list|(
specifier|const
name|A
operator|&
name|action
argument_list|)
operator|:
name|action_
argument_list|(
argument|action
argument_list|)
block|{}
name|template
operator|<
name|typename
name|F
operator|>
name|operator
name|Action
operator|<
name|F
operator|>
operator|(
operator|)
specifier|const
block|{
comment|// Assert statement belongs here because this is the best place to verify
comment|// conditions on F. It produces the clearest error messages
comment|// in most compilers.
comment|// Impl really belongs in this scope as a local class but can't
comment|// because MSVC produces duplicate symbols in different translation units
comment|// in this case. Until MS fixes that bug we put Impl into the class scope
comment|// and put the typedef both here (for use in assert statement) and
comment|// in the Impl class. But both definitions must be the same.
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
comment|// Asserts at compile time that F returns void.
name|CompileAssertTypesEqual
operator|<
name|void
operator|,
name|Result
operator|>
operator|(
operator|)
block|;
return|return
name|Action
operator|<
name|F
operator|>
operator|(
name|new
name|Impl
operator|<
name|F
operator|>
operator|(
name|action_
operator|)
operator|)
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
name|typename
name|F
operator|>
name|class
name|Impl
operator|:
name|public
name|ActionInterface
operator|<
name|F
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
end_typedef

begin_macro
name|explicit
end_macro

begin_expr_stmt
name|Impl
argument_list|(
specifier|const
name|A
operator|&
name|action
argument_list|)
operator|:
name|action_
argument_list|(
argument|action
argument_list|)
block|{}
name|virtual
name|void
name|Perform
argument_list|(
argument|const ArgumentTuple& args
argument_list|)
block|{
comment|// Performs the action and ignores its result.
name|action_
operator|.
name|Perform
argument_list|(
name|args
argument_list|)
block|;     }
name|private
operator|:
end_expr_stmt

begin_comment
comment|// Type OriginalFunction is the same as F except that its return
end_comment

begin_comment
comment|// type is IgnoredValue.
end_comment

begin_typedef
typedef|typedef
name|typename
name|internal
operator|::
name|Function
operator|<
name|F
operator|>
operator|::
name|MakeResultIgnoredValue
name|OriginalFunction
expr_stmt|;
end_typedef

begin_expr_stmt
specifier|const
name|Action
operator|<
name|OriginalFunction
operator|>
name|action_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
specifier|const
name|A
name|action_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|IgnoreResultAction
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// A ReferenceWrapper<T> object represents a reference to type T,
end_comment

begin_comment
comment|// which can be either const or not.  It can be explicitly converted
end_comment

begin_comment
comment|// from, and implicitly converted to, a T&.  Unlike a reference,
end_comment

begin_comment
comment|// ReferenceWrapper<T> can be copied and can survive template type
end_comment

begin_comment
comment|// inference.  This is used to support by-reference arguments in the
end_comment

begin_comment
comment|// InvokeArgument<N>(...) action.  The idea was from "reference
end_comment

begin_comment
comment|// wrappers" in tr1, which we don't have in our source tree yet.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ReferenceWrapper
block|{
name|public
operator|:
comment|// Constructs a ReferenceWrapper<T> object from a T&.
name|explicit
name|ReferenceWrapper
argument_list|(
name|T
operator|&
name|l_value
argument_list|)
operator|:
name|pointer_
argument_list|(
argument|&l_value
argument_list|)
block|{}
comment|// NOLINT
comment|// Allows a ReferenceWrapper<T> object to be implicitly converted to
comment|// a T&.
name|operator
name|T
operator|&
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|pointer_
return|;
block|}
name|private
operator|:
name|T
operator|*
name|pointer_
expr_stmt|;
end_expr_stmt

begin_comment
unit|};
comment|// Allows the expression ByRef(x) to be printed as a reference to x.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|void
name|PrintTo
argument_list|(
argument|const ReferenceWrapper<T>& ref
argument_list|,
argument|::std::ostream* os
argument_list|)
block|{
name|T
operator|&
name|value
operator|=
name|ref
block|;
name|UniversalPrinter
operator|<
name|T
operator|&
operator|>
operator|::
name|Print
argument_list|(
name|value
argument_list|,
name|os
argument_list|)
block|; }
comment|// Does two actions sequentially.  Used for implementing the DoAll(a1,
comment|// a2, ...) action.
name|template
operator|<
name|typename
name|Action1
operator|,
name|typename
name|Action2
operator|>
name|class
name|DoBothAction
block|{
name|public
operator|:
name|DoBothAction
argument_list|(
argument|Action1 action1
argument_list|,
argument|Action2 action2
argument_list|)
operator|:
name|action1_
argument_list|(
name|action1
argument_list|)
block|,
name|action2_
argument_list|(
argument|action2
argument_list|)
block|{}
comment|// This template type conversion operator allows DoAll(a1, ..., a_n)
comment|// to be used in ANY function of compatible type.
name|template
operator|<
name|typename
name|F
operator|>
name|operator
name|Action
operator|<
name|F
operator|>
operator|(
operator|)
specifier|const
block|{
return|return
name|Action
operator|<
name|F
operator|>
operator|(
name|new
name|Impl
operator|<
name|F
operator|>
operator|(
name|action1_
operator|,
name|action2_
operator|)
operator|)
return|;
block|}
name|private
operator|:
comment|// Implements the DoAll(...) action for a particular function type F.
name|template
operator|<
name|typename
name|F
operator|>
name|class
name|Impl
operator|:
name|public
name|ActionInterface
operator|<
name|F
operator|>
block|{
name|public
operator|:
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|Result
name|Result
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|ArgumentTuple
name|ArgumentTuple
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Function
operator|<
name|F
operator|>
operator|::
name|MakeResultVoid
name|VoidResult
expr_stmt|;
end_typedef

begin_expr_stmt
name|Impl
argument_list|(
specifier|const
name|Action
operator|<
name|VoidResult
operator|>
operator|&
name|action1
argument_list|,
specifier|const
name|Action
operator|<
name|F
operator|>
operator|&
name|action2
argument_list|)
operator|:
name|action1_
argument_list|(
name|action1
argument_list|)
operator|,
name|action2_
argument_list|(
argument|action2
argument_list|)
block|{}
name|virtual
name|Result
name|Perform
argument_list|(
argument|const ArgumentTuple& args
argument_list|)
block|{
name|action1_
operator|.
name|Perform
argument_list|(
name|args
argument_list|)
block|;
return|return
name|action2_
operator|.
name|Perform
argument_list|(
name|args
argument_list|)
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_expr_stmt
specifier|const
name|Action
operator|<
name|VoidResult
operator|>
name|action1_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
specifier|const
name|Action
operator|<
name|F
operator|>
name|action2_
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|Impl
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|Action1
name|action1_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Action2
name|action2_
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|GTEST_DISALLOW_ASSIGN_
argument_list|(
name|DoBothAction
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
unit|};  }
comment|// namespace internal
end_comment

begin_comment
comment|// An Unused object can be implicitly constructed from ANY value.
end_comment

begin_comment
comment|// This is handy when defining actions that ignore some or all of the
end_comment

begin_comment
comment|// mock function arguments.  For example, given
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   MOCK_METHOD3(Foo, double(const string& label, double x, double y));
end_comment

begin_comment
comment|//   MOCK_METHOD3(Bar, double(int index, double x, double y));
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// instead of
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   double DistanceToOriginWithLabel(const string& label, double x, double y) {
end_comment

begin_comment
comment|//     return sqrt(x*x + y*y);
end_comment

begin_comment
comment|//   }
end_comment

begin_comment
comment|//   double DistanceToOriginWithIndex(int index, double x, double y) {
end_comment

begin_comment
comment|//     return sqrt(x*x + y*y);
end_comment

begin_comment
comment|//   }
end_comment

begin_comment
comment|//   ...
end_comment

begin_comment
comment|//   EXEPCT_CALL(mock, Foo("abc", _, _))
end_comment

begin_comment
comment|//       .WillOnce(Invoke(DistanceToOriginWithLabel));
end_comment

begin_comment
comment|//   EXEPCT_CALL(mock, Bar(5, _, _))
end_comment

begin_comment
comment|//       .WillOnce(Invoke(DistanceToOriginWithIndex));
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// you could write
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   // We can declare any uninteresting argument as Unused.
end_comment

begin_comment
comment|//   double DistanceToOrigin(Unused, double x, double y) {
end_comment

begin_comment
comment|//     return sqrt(x*x + y*y);
end_comment

begin_comment
comment|//   }
end_comment

begin_comment
comment|//   ...
end_comment

begin_comment
comment|//   EXEPCT_CALL(mock, Foo("abc", _, _)).WillOnce(Invoke(DistanceToOrigin));
end_comment

begin_comment
comment|//   EXEPCT_CALL(mock, Bar(5, _, _)).WillOnce(Invoke(DistanceToOrigin));
end_comment

begin_expr_stmt
unit|typedef
name|internal
operator|::
name|IgnoredValue
name|Unused
expr_stmt|;
end_expr_stmt

begin_comment
comment|// This constructor allows us to turn an Action<From> object into an
end_comment

begin_comment
comment|// Action<To>, as long as To's arguments can be implicitly converted
end_comment

begin_comment
comment|// to From's and From's return type cann be implicitly converted to
end_comment

begin_comment
comment|// To's.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|To
operator|>
name|template
operator|<
name|typename
name|From
operator|>
name|Action
operator|<
name|To
operator|>
operator|::
name|Action
argument_list|(
specifier|const
name|Action
operator|<
name|From
operator|>
operator|&
name|from
argument_list|)
operator|:
name|impl_
argument_list|(
argument|new internal::ActionAdaptor<To
argument_list|,
argument|From>(from)
argument_list|)
block|{}
comment|// Creates an action that returns 'value'.  'value' is passed by value
comment|// instead of const reference - otherwise Return("string literal")
comment|// will trigger a compiler error about using array as initializer.
name|template
operator|<
name|typename
name|R
operator|>
name|internal
operator|::
name|ReturnAction
operator|<
name|R
operator|>
name|Return
argument_list|(
argument|R value
argument_list|)
block|{
return|return
name|internal
operator|::
name|ReturnAction
operator|<
name|R
operator|>
operator|(
name|internal
operator|::
name|move
argument_list|(
name|value
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates an action that returns NULL.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicAction
operator|<
name|internal
operator|::
name|ReturnNullAction
operator|>
name|ReturnNull
argument_list|()
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|ReturnNullAction
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates an action that returns from a void function.
end_comment

begin_expr_stmt
specifier|inline
name|PolymorphicAction
operator|<
name|internal
operator|::
name|ReturnVoidAction
operator|>
name|Return
argument_list|()
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|ReturnVoidAction
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates an action that returns the reference to a variable.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|R
operator|>
specifier|inline
name|internal
operator|::
name|ReturnRefAction
operator|<
name|R
operator|>
name|ReturnRef
argument_list|(
argument|R& x
argument_list|)
block|{
comment|// NOLINT
return|return
name|internal
operator|::
name|ReturnRefAction
operator|<
name|R
operator|>
operator|(
name|x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates an action that returns the reference to a copy of the
end_comment

begin_comment
comment|// argument.  The copy is created when the action is constructed and
end_comment

begin_comment
comment|// lives as long as the action.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|R
operator|>
specifier|inline
name|internal
operator|::
name|ReturnRefOfCopyAction
operator|<
name|R
operator|>
name|ReturnRefOfCopy
argument_list|(
argument|const R& x
argument_list|)
block|{
return|return
name|internal
operator|::
name|ReturnRefOfCopyAction
operator|<
name|R
operator|>
operator|(
name|x
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Modifies the parent action (a Return() action) to perform a move of the
end_comment

begin_comment
comment|// argument instead of a copy.
end_comment

begin_comment
comment|// Return(ByMove()) actions can only be executed once and will assert this
end_comment

begin_comment
comment|// invariant.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|R
operator|>
name|internal
operator|::
name|ByMoveWrapper
operator|<
name|R
operator|>
name|ByMove
argument_list|(
argument|R x
argument_list|)
block|{
return|return
name|internal
operator|::
name|ByMoveWrapper
operator|<
name|R
operator|>
operator|(
name|internal
operator|::
name|move
argument_list|(
name|x
argument_list|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates an action that does the default action for the give mock function.
end_comment

begin_expr_stmt
specifier|inline
name|internal
operator|::
name|DoDefaultAction
name|DoDefault
argument_list|()
block|{
return|return
name|internal
operator|::
name|DoDefaultAction
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates an action that sets the variable pointed by the N-th
end_comment

begin_comment
comment|// (0-based) function argument to 'value'.
end_comment

begin_expr_stmt
name|template
operator|<
name|size_t
name|N
operator|,
name|typename
name|T
operator|>
name|PolymorphicAction
operator|<
name|internal
operator|::
name|SetArgumentPointeeAction
operator|<
name|N
operator|,
name|T
operator|,
name|internal
operator|::
name|IsAProtocolMessage
operator|<
name|T
operator|>
operator|::
name|value
operator|>
expr|>
name|SetArgPointee
argument_list|(
argument|const T& x
argument_list|)
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|SetArgumentPointeeAction
operator|<
name|N
argument_list|,
name|T
argument_list|,
name|internal
operator|::
name|IsAProtocolMessage
operator|<
name|T
operator|>
operator|::
name|value
operator|>
operator|(
name|x
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_if
if|#
directive|if
operator|!
operator|(
operator|(
name|GTEST_GCC_VER_
operator|&&
name|GTEST_GCC_VER_
operator|<
literal|40000
operator|)
operator|||
name|GTEST_OS_SYMBIAN
operator|)
end_if

begin_comment
comment|// This overload allows SetArgPointee() to accept a string literal.
end_comment

begin_comment
comment|// GCC prior to the version 4.0 and Symbian C++ compiler cannot distinguish
end_comment

begin_comment
comment|// this overload from the templated version and emit a compile error.
end_comment

begin_expr_stmt
name|template
operator|<
name|size_t
name|N
operator|>
name|PolymorphicAction
operator|<
name|internal
operator|::
name|SetArgumentPointeeAction
operator|<
name|N
operator|,
specifier|const
name|char
operator|*
operator|,
name|false
operator|>
expr|>
name|SetArgPointee
argument_list|(
argument|const char* p
argument_list|)
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|SetArgumentPointeeAction
operator|<
name|N
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|false
operator|>
operator|(
name|p
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|size_t
name|N
operator|>
name|PolymorphicAction
operator|<
name|internal
operator|::
name|SetArgumentPointeeAction
operator|<
name|N
operator|,
specifier|const
name|wchar_t
operator|*
operator|,
name|false
operator|>
expr|>
name|SetArgPointee
argument_list|(
argument|const wchar_t* p
argument_list|)
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|SetArgumentPointeeAction
operator|<
name|N
argument_list|,
specifier|const
name|wchar_t
operator|*
argument_list|,
name|false
operator|>
operator|(
name|p
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// The following version is DEPRECATED.
end_comment

begin_expr_stmt
name|template
operator|<
name|size_t
name|N
operator|,
name|typename
name|T
operator|>
name|PolymorphicAction
operator|<
name|internal
operator|::
name|SetArgumentPointeeAction
operator|<
name|N
operator|,
name|T
operator|,
name|internal
operator|::
name|IsAProtocolMessage
operator|<
name|T
operator|>
operator|::
name|value
operator|>
expr|>
name|SetArgumentPointee
argument_list|(
argument|const T& x
argument_list|)
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|SetArgumentPointeeAction
operator|<
name|N
argument_list|,
name|T
argument_list|,
name|internal
operator|::
name|IsAProtocolMessage
operator|<
name|T
operator|>
operator|::
name|value
operator|>
operator|(
name|x
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates an action that sets a pointer referent to a given value.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T1
operator|,
name|typename
name|T2
operator|>
name|PolymorphicAction
operator|<
name|internal
operator|::
name|AssignAction
operator|<
name|T1
operator|,
name|T2
operator|>
expr|>
name|Assign
argument_list|(
argument|T1* ptr
argument_list|,
argument|T2 val
argument_list|)
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|AssignAction
operator|<
name|T1
argument_list|,
name|T2
operator|>
operator|(
name|ptr
operator|,
name|val
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_if
if|#
directive|if
operator|!
name|GTEST_OS_WINDOWS_MOBILE
end_if

begin_comment
comment|// Creates an action that sets errno and returns the appropriate error.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|PolymorphicAction
operator|<
name|internal
operator|::
name|SetErrnoAndReturnAction
operator|<
name|T
operator|>
expr|>
name|SetErrnoAndReturn
argument_list|(
argument|int errval
argument_list|,
argument|T result
argument_list|)
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|SetErrnoAndReturnAction
operator|<
name|T
operator|>
operator|(
name|errval
operator|,
name|result
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// !GTEST_OS_WINDOWS_MOBILE
end_comment

begin_comment
comment|// Various overloads for InvokeWithoutArgs().
end_comment

begin_comment
comment|// Creates an action that invokes 'function_impl' with no argument.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|FunctionImpl
operator|>
name|PolymorphicAction
operator|<
name|internal
operator|::
name|InvokeWithoutArgsAction
operator|<
name|FunctionImpl
operator|>
expr|>
name|InvokeWithoutArgs
argument_list|(
argument|FunctionImpl function_impl
argument_list|)
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|InvokeWithoutArgsAction
operator|<
name|FunctionImpl
operator|>
operator|(
name|function_impl
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates an action that invokes the given method on the given object
end_comment

begin_comment
comment|// with no argument.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Class
operator|,
name|typename
name|MethodPtr
operator|>
name|PolymorphicAction
operator|<
name|internal
operator|::
name|InvokeMethodWithoutArgsAction
operator|<
name|Class
operator|,
name|MethodPtr
operator|>
expr|>
name|InvokeWithoutArgs
argument_list|(
argument|Class* obj_ptr
argument_list|,
argument|MethodPtr method_ptr
argument_list|)
block|{
return|return
name|MakePolymorphicAction
argument_list|(
name|internal
operator|::
name|InvokeMethodWithoutArgsAction
operator|<
name|Class
argument_list|,
name|MethodPtr
operator|>
operator|(
name|obj_ptr
operator|,
name|method_ptr
operator|)
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates an action that performs an_action and throws away its
end_comment

begin_comment
comment|// result.  In other words, it changes the return type of an_action to
end_comment

begin_comment
comment|// void.  an_action MUST NOT return void, or the code won't compile.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|A
operator|>
specifier|inline
name|internal
operator|::
name|IgnoreResultAction
operator|<
name|A
operator|>
name|IgnoreResult
argument_list|(
argument|const A& an_action
argument_list|)
block|{
return|return
name|internal
operator|::
name|IgnoreResultAction
operator|<
name|A
operator|>
operator|(
name|an_action
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|// Creates a reference wrapper for the given L-value.  If necessary,
end_comment

begin_comment
comment|// you can explicitly specify the type of the reference.  For example,
end_comment

begin_comment
comment|// suppose 'derived' is an object of type Derived, ByRef(derived)
end_comment

begin_comment
comment|// would wrap a Derived&.  If you want to wrap a const Base& instead,
end_comment

begin_comment
comment|// where Base is a base class of Derived, just write:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//   ByRef<const Base>(derived)
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|internal
operator|::
name|ReferenceWrapper
operator|<
name|T
operator|>
name|ByRef
argument_list|(
argument|T& l_value
argument_list|)
block|{
comment|// NOLINT
return|return
name|internal
operator|::
name|ReferenceWrapper
operator|<
name|T
operator|>
operator|(
name|l_value
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// namespace testing
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GMOCK_INCLUDE_GMOCK_GMOCK_ACTIONS_H_
end_comment

end_unit

