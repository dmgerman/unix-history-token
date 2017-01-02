begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- CFUtils.h -----------------------------------------------*- C++ -*-===//
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
comment|//  Created by Greg Clayton on 3/5/07.
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
name|__CFUtils_h__
end_ifndef

begin_define
define|#
directive|define
name|__CFUtils_h__
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
comment|// explicitly released using the release() member function.
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
name|CFReleaser
block|{
name|public
operator|:
comment|// Type names for the avlue
typedef|typedef
name|T
name|element_type
typedef|;
comment|// Constructors and destructors
name|CFReleaser
argument_list|(
argument|T ptr = NULL
argument_list|)
operator|:
name|_ptr
argument_list|(
argument|ptr
argument_list|)
block|{}
name|CFReleaser
argument_list|(
specifier|const
name|CFReleaser
operator|&
name|copy
argument_list|)
operator|:
name|_ptr
argument_list|(
argument|copy.get()
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
end_expr_stmt

begin_expr_stmt
name|virtual
operator|~
name|CFReleaser
argument_list|()
block|{
name|reset
argument_list|()
block|; }
comment|// Assignments
name|CFReleaser
operator|&
name|operator
operator|=
operator|(
specifier|const
name|CFReleaser
operator|<
name|T
operator|>
operator|&
name|copy
operator|)
block|{
if|if
condition|(
name|copy
operator|!=
operator|*
name|this
condition|)
block|{
comment|// Replace our owned pointer with the new one
name|reset
argument_list|(
name|copy
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

begin_comment
unit|}
comment|// Get the address of the contained type
end_comment

begin_expr_stmt
unit|T
operator|*
name|ptr_address
argument_list|()
block|{
return|return
operator|&
name|_ptr
return|;
block|}
end_expr_stmt

begin_comment
comment|// Access the pointer itself
end_comment

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

begin_function
name|T
name|get
parameter_list|()
block|{
return|return
name|_ptr
return|;
block|}
end_function

begin_comment
comment|// Set a new value for the pointer and CFRelease our old
end_comment

begin_comment
comment|// value if we had a valid one.
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
name|ptr
operator|!=
name|_ptr
condition|)
block|{
if|if
condition|(
name|_ptr
operator|!=
name|NULL
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
block|}
end_function

begin_comment
comment|// Release ownership without calling CFRelease
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
name|element_type
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
comment|// #ifndef __CFUtils_h__
end_comment

end_unit

