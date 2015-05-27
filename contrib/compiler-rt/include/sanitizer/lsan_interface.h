begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- sanitizer/lsan_interface.h ------------------------------*- C++ -*-===//
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
comment|// This file is a part of LeakSanitizer.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Public interface header.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SANITIZER_LSAN_INTERFACE_H
end_ifndef

begin_define
define|#
directive|define
name|SANITIZER_LSAN_INTERFACE_H
end_define

begin_include
include|#
directive|include
file|<sanitizer/common_interface_defs.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|// Allocations made between calls to __lsan_disable() and __lsan_enable() will
comment|// be treated as non-leaks. Disable/enable pairs may be nested.
name|void
name|__lsan_disable
parameter_list|()
function_decl|;
name|void
name|__lsan_enable
parameter_list|()
function_decl|;
comment|// The heap object into which p points will be treated as a non-leak.
name|void
name|__lsan_ignore_object
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|)
function_decl|;
comment|// Memory regions registered through this interface will be treated as sources
comment|// of live pointers during leak checking. Useful if you store pointers in
comment|// mapped memory.
comment|// Points of note:
comment|// - __lsan_unregister_root_region() must be called with the same pointer and
comment|// size that have earlier been passed to __lsan_register_root_region()
comment|// - LSan will skip any inaccessible memory when scanning a root region. E.g.,
comment|// if you map memory within a larger region that you have mprotect'ed, you can
comment|// register the entire large region.
comment|// - the implementation is not optimized for performance. This interface is
comment|// intended to be used for a small number of relatively static regions.
name|void
name|__lsan_register_root_region
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
name|void
name|__lsan_unregister_root_region
parameter_list|(
specifier|const
name|void
modifier|*
name|p
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
comment|// Calling this function makes LSan enter the leak checking phase immediately.
comment|// Use this if normal end-of-process leak checking happens too late (e.g. if
comment|// you have intentional memory leaks in your shutdown code). Calling this
comment|// function overrides end-of-process leak checking; it must be called at
comment|// most once per process. This function will terminate the process if there
comment|// are memory leaks and the exit_code flag is non-zero.
name|void
name|__lsan_do_leak_check
parameter_list|()
function_decl|;
comment|// The user may optionally provide this function to disallow leak checking
comment|// for the program it is linked into (if the return value is non-zero). This
comment|// function must be defined as returning a constant value; any behavior beyond
comment|// that is unsupported.
name|int
name|__lsan_is_turned_off
parameter_list|()
function_decl|;
comment|// This function may be optionally provided by the user and should return
comment|// a string containing LSan suppressions.
specifier|const
name|char
modifier|*
name|__lsan_default_suppressions
parameter_list|()
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_comment
comment|// extern "C"
end_comment

begin_decl_stmt
name|namespace
name|__lsan
block|{
name|class
name|ScopedDisabler
block|{
name|public
label|:
name|ScopedDisabler
argument_list|()
block|{
name|__lsan_disable
argument_list|()
expr_stmt|;
block|}
operator|~
name|ScopedDisabler
argument_list|()
block|{
name|__lsan_enable
argument_list|()
block|; }
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace __lsan
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// SANITIZER_LSAN_INTERFACE_H
end_comment

end_unit

