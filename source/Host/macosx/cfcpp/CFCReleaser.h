begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CFCReleaser.h -------------------------------------------*- C++ -*-===//
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
name|CoreFoundationCPP_CFReleaser_h_
end_ifndef

begin_define
define|#
directive|define
name|CoreFoundationCPP_CFReleaser_h_
end_define

begin_include
include|#
directive|include
file|<CoreFoundation/CoreFoundation.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// Templatized CF helper class that can own any CF pointer and will
end_comment

begin_comment
comment|// call CFRelease() on any valid pointer it owns unless that pointer is
end_comment

begin_comment
comment|// explicitly released using the release() member function. This class
end_comment

begin_comment
comment|// is designed to mimic the std::auto_ptr<T> class and has all of the
end_comment

begin_comment
comment|// same functions. The one thing to watch out for is the
end_comment

begin_comment
comment|// CFCReleaser<T>::release() function won't actually CFRelease any owned
end_comment

begin_comment
comment|// pointer, it is designed to relinquish ownership of the pointer just
end_comment

begin_comment
comment|// like std:auto_ptr<T>::release() does.
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
name|class
name|CFCReleaser
block|{
name|public
operator|:
comment|//----------------------------------------------------------
comment|// Constructor that takes a pointer to a CF object that is
comment|// to be released when this object goes out of scope
comment|//----------------------------------------------------------
name|CFCReleaser
argument_list|(
argument|T ptr = NULL
argument_list|)
operator|:
name|_ptr
argument_list|(
argument|ptr
argument_list|)
block|{}
comment|//----------------------------------------------------------
comment|// Copy constructor
comment|//
comment|// Note that copying a CFCReleaser will not transfer
comment|// ownership of the contained pointer, but it will bump its
comment|// reference count. This is where this class differs from
comment|// std::auto_ptr.
comment|//----------------------------------------------------------
name|CFCReleaser
argument_list|(
specifier|const
name|CFCReleaser
operator|&
name|rhs
argument_list|)
operator|:
name|_ptr
argument_list|(
argument|rhs.get()
argument_list|)
block|{
if|if
condition|(
name|get
argument_list|()
condition|)
operator|::
name|CFRetain
argument_list|(
name|get
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|//----------------------------------------------------------
comment|// The destructor will release the pointer that it contains
comment|// if it has a valid pointer.
comment|//----------------------------------------------------------
name|virtual
operator|~
name|CFCReleaser
argument_list|()
block|{
name|reset
argument_list|()
block|; }
comment|//----------------------------------------------------------
comment|// Assignment operator.
comment|//
comment|// Note that assigning one CFCReleaser to another will
comment|// not transfer ownership of the contained pointer, but it
comment|// will bump its reference count. This is where this class
comment|// differs from std::auto_ptr.
comment|//----------------------------------------------------------
name|CFCReleaser
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CFCReleaser
operator|<
name|T
operator|>
operator|&
name|rhs
operator|)
block|{
if|if
condition|(
name|this
operator|!=
operator|&
name|rhs
condition|)
block|{
comment|// Replace our owned pointer with the new one
name|reset
argument_list|(
name|rhs
operator|.
name|get
argument_list|()
argument_list|)
expr_stmt|;
comment|// Retain the current pointer that we own
if|if
condition|(
name|get
argument_list|()
condition|)
operator|::
name|CFRetain
argument_list|(
name|get
argument_list|()
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|//----------------------------------------------------------
end_comment

begin_comment
comment|// Get the address of the contained type in case it needs
end_comment

begin_comment
comment|// to be passed to a function that will fill in a pointer
end_comment

begin_comment
comment|// value. The function currently will assert if _ptr is not
end_comment

begin_comment
comment|// NULL because the only time this method should be used is
end_comment

begin_comment
comment|// if another function will modify the contents, and we
end_comment

begin_comment
comment|// could leak a pointer if this is not NULL. If the
end_comment

begin_comment
comment|// assertion fires, check the offending code, or call
end_comment

begin_comment
comment|// reset() prior to using the "ptr_address()" member to make
end_comment

begin_comment
comment|// sure any owned objects has CFRelease called on it.
end_comment

begin_comment
comment|// I had to add the "enforce_null" bool here because some
end_comment

begin_comment
comment|// API's require the pointer address even though they don't change it.
end_comment

begin_comment
comment|//----------------------------------------------------------
end_comment

begin_expr_stmt
unit|T
operator|*
name|ptr_address
argument_list|(
argument|bool enforce_null = true
argument_list|)
block|{
if|if
condition|(
name|enforce_null
condition|)
name|assert
argument_list|(
name|_ptr
operator|==
name|NULL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
operator|&
name|_ptr
return|;
end_return

begin_comment
unit|}
comment|//----------------------------------------------------------
end_comment

begin_comment
comment|// Access the pointer itself
end_comment

begin_comment
comment|//----------------------------------------------------------
end_comment

begin_macro
unit|T
name|get
argument_list|()
end_macro

begin_block
block|{
return|return
name|_ptr
return|;
block|}
end_block

begin_expr_stmt
specifier|const
name|T
name|get
argument_list|()
specifier|const
block|{
return|return
name|_ptr
return|;
block|}
end_expr_stmt

begin_comment
comment|//----------------------------------------------------------
end_comment

begin_comment
comment|// Set a new value for the pointer and CFRelease our old
end_comment

begin_comment
comment|// value if we had a valid one.
end_comment

begin_comment
comment|//----------------------------------------------------------
end_comment

begin_function
name|void
name|reset
parameter_list|(
name|T
name|ptr
init|=
name|NULL
parameter_list|)
block|{
if|if
condition|(
operator|(
name|_ptr
operator|!=
name|NULL
operator|)
operator|&&
operator|(
name|ptr
operator|!=
name|_ptr
operator|)
condition|)
operator|::
name|CFRelease
argument_list|(
name|_ptr
argument_list|)
expr_stmt|;
name|_ptr
operator|=
name|ptr
expr_stmt|;
block|}
end_function

begin_comment
comment|//----------------------------------------------------------
end_comment

begin_comment
comment|// Release ownership without calling CFRelease. This class
end_comment

begin_comment
comment|// is designed to mimic std::auto_ptr<T>, so the release
end_comment

begin_comment
comment|// method releases ownership of the contained pointer
end_comment

begin_comment
comment|// and does NOT call CFRelease.
end_comment

begin_comment
comment|//----------------------------------------------------------
end_comment

begin_function
name|T
name|release
parameter_list|()
block|{
name|T
name|tmp
init|=
name|_ptr
decl_stmt|;
name|_ptr
operator|=
name|NULL
expr_stmt|;
return|return
name|tmp
return|;
block|}
end_function

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|T
name|_ptr
decl_stmt|;
end_decl_stmt

begin_endif
unit|};
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifdef __cplusplus
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef CoreFoundationCPP_CFReleaser_h_
end_comment

end_unit

