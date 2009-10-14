begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Support/LeakDetector.h - Provide leak detection ----*- C++ -*-===//
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
comment|// This file defines a class that can be used to provide very simple memory leak
end_comment

begin_comment
comment|// checks for an API.  Basically LLVM uses this to make sure that Instructions,
end_comment

begin_comment
comment|// for example, are deleted when they are supposed to be, and not leaked away.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// When compiling with NDEBUG (Release build), this class does nothing, thus
end_comment

begin_comment
comment|// adding no checking overhead to release builds.  Note that this class is
end_comment

begin_comment
comment|// implemented in a very simple way, requiring completely manual manipulation
end_comment

begin_comment
comment|// and checking for garbage, but this is intentional: users should not be using
end_comment

begin_comment
comment|// this API, only other APIs should.
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
name|LLVM_SUPPORT_LEAKDETECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_LEAKDETECTOR_H
end_define

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Value
decl_stmt|;
struct|struct
name|LeakDetector
block|{
comment|/// addGarbageObject - Add a pointer to the internal set of "garbage" object
comment|/// pointers.  This should be called when objects are created, or if they are
comment|/// taken out of an owning collection.
comment|///
specifier|static
name|void
name|addGarbageObject
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|addGarbageObjectImpl
argument_list|(
name|Object
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/// removeGarbageObject - Remove a pointer from our internal representation of
comment|/// our "garbage" objects.  This should be called when an object is added to
comment|/// an "owning" collection.
comment|///
specifier|static
name|void
name|removeGarbageObject
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|removeGarbageObjectImpl
argument_list|(
name|Object
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/// checkForGarbage - Traverse the internal representation of garbage
comment|/// pointers.  If there are any pointers that have been add'ed, but not
comment|/// remove'd, big obnoxious warnings about memory leaks are issued.
comment|///
comment|/// The specified message will be printed indicating when the check was
comment|/// performed.
comment|///
specifier|static
name|void
name|checkForGarbage
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Message
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|checkForGarbageImpl
argument_list|(
name|C
argument_list|,
name|Message
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/// Overload the normal methods to work better with Value*'s because they are
comment|/// by far the most common in LLVM.  This does not affect the actual
comment|/// functioning of this class, it just makes the warning messages nicer.
comment|///
specifier|static
name|void
name|addGarbageObject
parameter_list|(
specifier|const
name|Value
modifier|*
name|Object
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|addGarbageObjectImpl
argument_list|(
name|Object
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
specifier|static
name|void
name|removeGarbageObject
parameter_list|(
specifier|const
name|Value
modifier|*
name|Object
parameter_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
name|removeGarbageObjectImpl
argument_list|(
name|Object
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|private
label|:
comment|// If we are debugging, the actual implementations will be called...
specifier|static
name|void
name|addGarbageObjectImpl
parameter_list|(
specifier|const
name|Value
modifier|*
name|Object
parameter_list|)
function_decl|;
specifier|static
name|void
name|removeGarbageObjectImpl
parameter_list|(
specifier|const
name|Value
modifier|*
name|Object
parameter_list|)
function_decl|;
specifier|static
name|void
name|addGarbageObjectImpl
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|)
function_decl|;
specifier|static
name|void
name|removeGarbageObjectImpl
parameter_list|(
name|void
modifier|*
name|Object
parameter_list|)
function_decl|;
specifier|static
name|void
name|checkForGarbageImpl
argument_list|(
name|LLVMContext
operator|&
name|C
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Message
argument_list|)
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

