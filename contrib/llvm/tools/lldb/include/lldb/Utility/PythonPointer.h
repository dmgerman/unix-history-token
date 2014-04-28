begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---------------------PythonPointer.h ------------------------*- C++ -*-===//
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
name|utility_PythonPointer_h_
end_ifndef

begin_define
define|#
directive|define
name|utility_PythonPointer_h_
end_define

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-python.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|template
operator|<
name|class
name|T
operator|>
name|class
name|PythonPointer
block|{
name|public
operator|:
typedef|typedef
name|PyObject
modifier|*
name|element_type
typedef|;
name|private
operator|:
name|element_type
operator|*
name|ptr_
expr_stmt|;
name|bool
name|my_ref
decl_stmt|;
name|public
label|:
name|PythonPointer
argument_list|(
argument|element_type p
argument_list|,
argument|bool steal_ref = false
argument_list|)
block|:
name|ptr_
argument_list|(
name|p
argument_list|)
operator|,
name|my_ref
argument_list|(
argument|!steal_ref
argument_list|)
block|{
if|if
condition|(
name|my_ref
condition|)
name|Py_INCREF
argument_list|(
name|ptr_
argument_list|)
expr_stmt|;
block|}
name|PythonPointer
argument_list|(
argument|const PythonPointer& r
argument_list|,
argument|bool steal_ref = false
argument_list|)
block|:
name|ptr_
argument_list|(
name|r
operator|.
name|ptr_
argument_list|)
operator|,
name|my_ref
argument_list|(
argument|!steal_ref
argument_list|)
block|{
if|if
condition|(
name|my_ref
condition|)
name|Py_INCREF
argument_list|(
name|ptr_
argument_list|)
expr_stmt|;
block|}
operator|~
name|PythonPointer
argument_list|()
block|{
if|if
condition|(
name|my_ref
condition|)
name|Py_XDECREF
argument_list|(
name|ptr_
argument_list|)
expr_stmt|;
block|}
name|PythonPointer
name|StealReference
parameter_list|()
block|{
return|return
name|PythonPointer
argument_list|(
name|ptr_
argument_list|,
name|true
argument_list|)
return|;
block|}
name|PythonPointer
name|DuplicateReference
parameter_list|()
block|{
return|return
name|PythonPointer
argument_list|(
name|ptr_
argument_list|,
name|false
argument_list|)
return|;
block|}
name|element_type
name|get
argument_list|()
specifier|const
block|{
return|return
name|ptr_
return|;
block|}
name|bool
name|IsNull
parameter_list|()
block|{
return|return
name|ptr_
operator|==
name|NULL
return|;
block|}
name|bool
name|IsNone
parameter_list|()
block|{
return|return
name|ptr_
operator|==
name|Py_None
return|;
block|}
name|operator
name|PyObject
modifier|*
parameter_list|()
block|{
return|return
name|ptr_
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// utility_PythonPointer_h_
end_comment

end_unit

