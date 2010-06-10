begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Copyright 2003 Google Inc.
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
comment|// Authors: Dan Egnor (egnor@google.com)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A "smart" pointer type with reference tracking.  Every pointer to a
end_comment

begin_comment
comment|// particular object is kept on a circular linked list.  When the last pointer
end_comment

begin_comment
comment|// to an object is destroyed or reassigned, the object is deleted.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Used properly, this deletes the object when the last reference goes away.
end_comment

begin_comment
comment|// There are several caveats:
end_comment

begin_comment
comment|// - Like all reference counting schemes, cycles lead to leaks.
end_comment

begin_comment
comment|// - Each smart pointer is actually two pointers (8 bytes instead of 4).
end_comment

begin_comment
comment|// - Every time a pointer is assigned, the entire list of pointers to that
end_comment

begin_comment
comment|//   object is traversed.  This class is therefore NOT SUITABLE when there
end_comment

begin_comment
comment|//   will often be more than two or three pointers to a particular object.
end_comment

begin_comment
comment|// - References are only tracked as long as linked_ptr<> objects are copied.
end_comment

begin_comment
comment|//   If a linked_ptr<> is converted to a raw pointer and back, BAD THINGS
end_comment

begin_comment
comment|//   will happen (double deletion).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A good use of this class is storing object references in STL containers.
end_comment

begin_comment
comment|// You can safely put linked_ptr<> in a vector<>.
end_comment

begin_comment
comment|// Other uses may not be as good.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Note: If you use an incomplete type with linked_ptr<>, the class
end_comment

begin_comment
comment|// *containing* linked_ptr<> must have a constructor and destructor (even
end_comment

begin_comment
comment|// if they do nothing!).
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Bill Gibbons suggested we use something like this.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Thread Safety:
end_comment

begin_comment
comment|//   Unlike other linked_ptr implementations, in this implementation
end_comment

begin_comment
comment|//   a linked_ptr object is thread-safe in the sense that:
end_comment

begin_comment
comment|//     - it's safe to copy linked_ptr objects concurrently,
end_comment

begin_comment
comment|//     - it's safe to copy *from* a linked_ptr and read its underlying
end_comment

begin_comment
comment|//       raw pointer (e.g. via get()) concurrently, and
end_comment

begin_comment
comment|//     - it's safe to write to two linked_ptrs that point to the same
end_comment

begin_comment
comment|//       shared object concurrently.
end_comment

begin_comment
comment|// TODO(wan@google.com): rename this to safe_linked_ptr to avoid
end_comment

begin_comment
comment|// confusion with normal linked_ptr.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_LINKED_PTR_H_
end_ifndef

begin_define
define|#
directive|define
name|GTEST_INCLUDE_GTEST_INTERNAL_GTEST_LINKED_PTR_H_
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<gtest/internal/gtest-port.h>
end_include

begin_decl_stmt
name|namespace
name|testing
block|{
name|namespace
name|internal
block|{
comment|// Protects copying of all linked_ptr objects.
specifier|extern
name|Mutex
name|g_linked_ptr_mutex
decl_stmt|;
comment|// This is used internally by all instances of linked_ptr<>.  It needs to be
comment|// a non-template class because different types of linked_ptr<> can refer to
comment|// the same object (linked_ptr<Superclass>(obj) vs linked_ptr<Subclass>(obj)).
comment|// So, it needs to be possible for different types of linked_ptr to participate
comment|// in the same circular linked list, so we need a single class type here.
comment|//
comment|// DO NOT USE THIS CLASS DIRECTLY YOURSELF.  Use linked_ptr<T>.
name|class
name|linked_ptr_internal
block|{
name|public
label|:
comment|// Create a new circle that includes only this instance.
name|void
name|join_new
parameter_list|()
block|{
name|next_
operator|=
name|this
expr_stmt|;
block|}
comment|// Many linked_ptr operations may change p.link_ for some linked_ptr
comment|// variable p in the same circle as this object.  Therefore we need
comment|// to prevent two such operations from occurring concurrently.
comment|//
comment|// Note that different types of linked_ptr objects can coexist in a
comment|// circle (e.g. linked_ptr<Base>, linked_ptr<Derived1>, and
comment|// linked_ptr<Derived2>).  Therefore we must use a single mutex to
comment|// protect all linked_ptr objects.  This can create serious
comment|// contention in production code, but is acceptable in a testing
comment|// framework.
comment|// Join an existing circle.
comment|// L< g_linked_ptr_mutex
name|void
name|join
parameter_list|(
name|linked_ptr_internal
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
name|MutexLock
name|lock
argument_list|(
operator|&
name|g_linked_ptr_mutex
argument_list|)
decl_stmt|;
name|linked_ptr_internal
specifier|const
modifier|*
name|p
init|=
name|ptr
decl_stmt|;
while|while
condition|(
name|p
operator|->
name|next_
operator|!=
name|ptr
condition|)
name|p
operator|=
name|p
operator|->
name|next_
expr_stmt|;
name|p
operator|->
name|next_
operator|=
name|this
expr_stmt|;
name|next_
operator|=
name|ptr
expr_stmt|;
block|}
comment|// Leave whatever circle we're part of.  Returns true if we were the
comment|// last member of the circle.  Once this is done, you can join() another.
comment|// L< g_linked_ptr_mutex
name|bool
name|depart
parameter_list|()
block|{
name|MutexLock
name|lock
argument_list|(
operator|&
name|g_linked_ptr_mutex
argument_list|)
decl_stmt|;
if|if
condition|(
name|next_
operator|==
name|this
condition|)
return|return
name|true
return|;
name|linked_ptr_internal
specifier|const
modifier|*
name|p
init|=
name|next_
decl_stmt|;
while|while
condition|(
name|p
operator|->
name|next_
operator|!=
name|this
condition|)
name|p
operator|=
name|p
operator|->
name|next_
expr_stmt|;
name|p
operator|->
name|next_
operator|=
name|next_
expr_stmt|;
return|return
name|false
return|;
block|}
name|private
label|:
name|mutable
name|linked_ptr_internal
specifier|const
modifier|*
name|next_
decl_stmt|;
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|linked_ptr
block|{
name|public
operator|:
typedef|typedef
name|T
name|element_type
typedef|;
comment|// Take over ownership of a raw pointer.  This should happen as soon as
comment|// possible after the object is created.
name|explicit
name|linked_ptr
argument_list|(
argument|T* ptr = NULL
argument_list|)
block|{
name|capture
argument_list|(
name|ptr
argument_list|)
block|; }
operator|~
name|linked_ptr
argument_list|()
block|{
name|depart
argument_list|()
block|; }
comment|// Copy an existing linked_ptr<>, adding ourselves to the list of references.
name|template
operator|<
name|typename
name|U
operator|>
name|linked_ptr
argument_list|(
argument|linked_ptr<U> const& ptr
argument_list|)
block|{
name|copy
argument_list|(
operator|&
name|ptr
argument_list|)
block|; }
name|linked_ptr
argument_list|(
argument|linked_ptr const& ptr
argument_list|)
block|{
comment|// NOLINT
name|assert
argument_list|(
operator|&
name|ptr
operator|!=
name|this
argument_list|)
block|;
name|copy
argument_list|(
operator|&
name|ptr
argument_list|)
block|;   }
comment|// Assignment releases the old value and acquires the new.
name|template
operator|<
name|typename
name|U
operator|>
name|linked_ptr
operator|&
name|operator
operator|=
operator|(
name|linked_ptr
operator|<
name|U
operator|>
specifier|const
operator|&
name|ptr
operator|)
block|{
name|depart
argument_list|()
block|;
name|copy
argument_list|(
operator|&
name|ptr
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|linked_ptr
modifier|&
name|operator
init|=
operator|(
name|linked_ptr
specifier|const
operator|&
name|ptr
operator|)
block|{
if|if
condition|(
operator|&
name|ptr
operator|!=
name|this
condition|)
block|{
name|depart
argument_list|()
expr_stmt|;
name|copy
argument_list|(
operator|&
name|ptr
argument_list|)
expr_stmt|;
block|}
return|return
operator|*
name|this
return|;
block|}
comment|// Smart pointer members.
name|void
name|reset
parameter_list|(
name|T
modifier|*
name|ptr
init|=
name|NULL
parameter_list|)
block|{
name|depart
argument_list|()
expr_stmt|;
name|capture
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
name|T
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|value_
return|;
block|}
name|T
operator|*
name|operator
operator|->
expr|(
block|)
decl|const
block|{
return|return
name|value_
return|;
block|}
name|T
operator|&
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
operator|*
name|value_
return|;
block|}
comment|// Release ownership of the pointed object and returns it.
comment|// Sole ownership by this linked_ptr object is required.
name|T
modifier|*
name|release
parameter_list|()
block|{
name|bool
name|last
init|=
name|link_
operator|.
name|depart
argument_list|()
decl_stmt|;
operator|(
name|void
operator|)
name|last
expr_stmt|;
name|assert
argument_list|(
name|last
argument_list|)
expr_stmt|;
name|T
modifier|*
name|v
init|=
name|value_
decl_stmt|;
name|value_
operator|=
name|NULL
expr_stmt|;
return|return
name|v
return|;
block|}
name|bool
name|operator
operator|==
operator|(
name|T
operator|*
name|p
operator|)
specifier|const
block|{
return|return
name|value_
operator|==
name|p
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
name|T
operator|*
name|p
operator|)
specifier|const
block|{
return|return
name|value_
operator|!=
name|p
return|;
block|}
name|template
operator|<
name|typename
name|U
operator|>
name|bool
name|operator
operator|==
operator|(
name|linked_ptr
operator|<
name|U
operator|>
specifier|const
operator|&
name|ptr
operator|)
specifier|const
block|{
return|return
name|value_
operator|==
name|ptr
operator|.
name|get
argument_list|()
return|;
block|}
name|template
operator|<
name|typename
name|U
operator|>
name|bool
name|operator
operator|!=
operator|(
name|linked_ptr
operator|<
name|U
operator|>
specifier|const
operator|&
name|ptr
operator|)
specifier|const
block|{
return|return
name|value_
operator|!=
name|ptr
operator|.
name|get
argument_list|()
return|;
block|}
name|private
label|:
name|template
operator|<
name|typename
name|U
operator|>
name|friend
name|class
name|linked_ptr
expr_stmt|;
name|T
modifier|*
name|value_
decl_stmt|;
name|linked_ptr_internal
name|link_
decl_stmt|;
name|void
name|depart
parameter_list|()
block|{
if|if
condition|(
name|link_
operator|.
name|depart
argument_list|()
condition|)
name|delete
name|value_
decl_stmt|;
block|}
name|void
name|capture
parameter_list|(
name|T
modifier|*
name|ptr
parameter_list|)
block|{
name|value_
operator|=
name|ptr
expr_stmt|;
name|link_
operator|.
name|join_new
argument_list|()
expr_stmt|;
block|}
name|template
operator|<
name|typename
name|U
operator|>
name|void
name|copy
argument_list|(
argument|linked_ptr<U> const* ptr
argument_list|)
block|{
name|value_
operator|=
name|ptr
operator|->
name|get
argument_list|()
block|;
if|if
condition|(
name|value_
condition|)
name|link_
operator|.
name|join
argument_list|(
operator|&
name|ptr
operator|->
name|link_
argument_list|)
expr_stmt|;
else|else
name|link_
operator|.
name|join_new
argument_list|()
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|==
operator|(
name|T
operator|*
name|ptr
operator|,
specifier|const
name|linked_ptr
operator|<
name|T
operator|>
operator|&
name|x
operator|)
block|{
return|return
name|ptr
operator|==
name|x
operator|.
name|get
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
specifier|inline
name|bool
name|operator
operator|!=
operator|(
name|T
operator|*
name|ptr
operator|,
specifier|const
name|linked_ptr
operator|<
name|T
operator|>
operator|&
name|x
operator|)
block|{
return|return
name|ptr
operator|!=
name|x
operator|.
name|get
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|// A function to convert T* into linked_ptr<T>
end_comment

begin_comment
comment|// Doing e.g. make_linked_ptr(new FooBarBaz<type>(arg)) is a shorter notation
end_comment

begin_comment
comment|// for linked_ptr<FooBarBaz<type>>(new FooBarBaz<type>(arg))
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
name|linked_ptr
operator|<
name|T
operator|>
name|make_linked_ptr
argument_list|(
argument|T* ptr
argument_list|)
block|{
return|return
name|linked_ptr
operator|<
name|T
operator|>
operator|(
name|ptr
operator|)
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// namespace internal
end_comment

begin_comment
unit|}
comment|// namespace testing
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// GTEST_INCLUDE_GTEST_INTERNAL_GTEST_LINKED_PTR_H_
end_comment

end_unit

