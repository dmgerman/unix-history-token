begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer_libignore.h -----------------------------------*- C++ -*-===//
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
comment|// LibIgnore allows to ignore all interceptors called from a particular set
end_comment

begin_comment
comment|// of dynamic libraries. LibIgnore can be initialized with several templates
end_comment

begin_comment
comment|// of names of libraries to be ignored. It finds code ranges for the libraries;
end_comment

begin_comment
comment|// and checks whether the provided PC value belongs to the code ranges.
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
name|SANITIZER_LIBIGNORE_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_LIBIGNORE_H
end_define

begin_include
include|#
directive|include
file|"sanitizer_internal_defs.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_common.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_atomic.h"
end_include

begin_include
include|#
directive|include
file|"sanitizer_mutex.h"
end_include

begin_decl_stmt
name|namespace
name|__sanitizer
block|{
name|class
name|LibIgnore
block|{
name|public
label|:
name|explicit
name|LibIgnore
parameter_list|(
name|LinkerInitialized
parameter_list|)
function_decl|;
comment|// Must be called during initialization.
name|void
name|AddIgnoredLibrary
parameter_list|(
specifier|const
name|char
modifier|*
name|name_templ
parameter_list|)
function_decl|;
comment|// Must be called after a new dynamic library is loaded.
name|void
name|OnLibraryLoaded
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
comment|// Must be called after a dynamic library is unloaded.
name|void
name|OnLibraryUnloaded
parameter_list|()
function_decl|;
comment|// Checks whether the provided PC belongs to one of the ignored libraries.
name|bool
name|IsIgnored
argument_list|(
name|uptr
name|pc
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
struct|struct
name|Lib
block|{
name|char
modifier|*
name|templ
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|real_name
decl_stmt|;
comment|// target of symlink
name|bool
name|loaded
decl_stmt|;
block|}
struct|;
struct|struct
name|LibCodeRange
block|{
name|uptr
name|begin
decl_stmt|;
name|uptr
name|end
decl_stmt|;
block|}
struct|;
specifier|static
specifier|const
name|uptr
name|kMaxLibs
init|=
literal|128
decl_stmt|;
comment|// Hot part:
name|atomic_uintptr_t
name|loaded_count_
decl_stmt|;
name|LibCodeRange
name|code_ranges_
index|[
name|kMaxLibs
index|]
decl_stmt|;
comment|// Cold part:
name|BlockingMutex
name|mutex_
decl_stmt|;
name|uptr
name|count_
decl_stmt|;
name|Lib
name|libs_
index|[
name|kMaxLibs
index|]
decl_stmt|;
comment|// Disallow copying of LibIgnore objects.
name|LibIgnore
argument_list|(
specifier|const
name|LibIgnore
operator|&
argument_list|)
expr_stmt|;
comment|// not implemented
name|void
name|operator
init|=
operator|(
specifier|const
name|LibIgnore
operator|&
operator|)
decl_stmt|;
comment|// not implemented
block|}
empty_stmt|;
specifier|inline
name|bool
name|LibIgnore
operator|::
name|IsIgnored
argument_list|(
argument|uptr pc
argument_list|)
specifier|const
block|{
specifier|const
name|uptr
name|n
operator|=
name|atomic_load
argument_list|(
operator|&
name|loaded_count_
argument_list|,
name|memory_order_acquire
argument_list|)
block|;
for|for
control|(
name|uptr
name|i
init|=
literal|0
init|;
name|i
operator|<
name|n
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|pc
operator|>=
name|code_ranges_
index|[
name|i
index|]
operator|.
name|begin
operator|&&
name|pc
operator|<
name|code_ranges_
index|[
name|i
index|]
operator|.
name|end
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// namespace __sanitizer
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_LIBIGNORE_H
end_comment

end_unit

