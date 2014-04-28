begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-types.h --------------------------------------------*- C++ -*-===//
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
name|LLDB_lldb_types_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_lldb_types_h_
end_define

begin_include
include|#
directive|include
file|"lldb/lldb-enumerations.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// All host systems must define:
end_comment

begin_comment
comment|//  lldb::condition_t       The native condition type (or a substitute class) for conditions on the host system.
end_comment

begin_comment
comment|//  lldb::mutex_t           The native mutex type for mutex objects on the host system.
end_comment

begin_comment
comment|//  lldb::thread_t          The native thread type for spawned threads on the system
end_comment

begin_comment
comment|//  lldb::thread_arg_t      The type of the one any only thread creation argument for the host system
end_comment

begin_comment
comment|//  lldb::thread_result_t   The return type that gets returned when a thread finishes.
end_comment

begin_comment
comment|//  lldb::thread_func_t     The function prototype used to spawn a thread on the host system.
end_comment

begin_comment
comment|//  #define LLDB_INVALID_PROCESS_ID ...
end_comment

begin_comment
comment|//  #define LLDB_INVALID_THREAD_ID ...
end_comment

begin_comment
comment|//  #define LLDB_INVALID_HOST_THREAD ...
end_comment

begin_comment
comment|//  #define IS_VALID_LLDB_HOST_THREAD ...
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|// TODO: Add a bunch of ifdefs to determine the host system and what
end_comment

begin_comment
comment|// things should be defined. Currently MacOSX is being assumed by default
end_comment

begin_comment
comment|// since that is what lldb was first developed for.
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MSC_VER
end_ifndef

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_WIN32
end_ifdef

begin_include
include|#
directive|include
file|<process.h>
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
typedef|typedef
name|void
modifier|*
name|mutex_t
typedef|;
typedef|typedef
name|void
modifier|*
name|condition_t
typedef|;
typedef|typedef
name|void
modifier|*
name|rwlock_t
typedef|;
typedef|typedef
name|uintptr_t
name|thread_t
typedef|;
comment|// Host thread type
typedef|typedef
name|uint32_t
name|thread_key_t
typedef|;
typedef|typedef
name|void
modifier|*
name|thread_arg_t
typedef|;
comment|// Host thread argument type
typedef|typedef
name|unsigned
name|thread_result_t
typedef|;
comment|// Host thread result type
typedef|typedef
name|thread_result_t
function_decl|(
modifier|*
name|thread_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|// Host thread function type
typedef|typedef
name|void
function_decl|(
modifier|*
name|LogOutputCallback
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|CommandOverrideCallback
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<pthread.h>
end_include

begin_decl_stmt
name|namespace
name|lldb
block|{
comment|//----------------------------------------------------------------------
comment|// MacOSX Types
comment|//----------------------------------------------------------------------
typedef|typedef
operator|::
name|pthread_mutex_t
name|mutex_t
expr_stmt|;
typedef|typedef
name|pthread_cond_t
name|condition_t
typedef|;
typedef|typedef
name|pthread_rwlock_t
name|rwlock_t
typedef|;
typedef|typedef
name|pthread_t
name|thread_t
typedef|;
comment|// Host thread type
typedef|typedef
name|pthread_key_t
name|thread_key_t
typedef|;
typedef|typedef
name|void
modifier|*
name|thread_arg_t
typedef|;
comment|// Host thread argument type
typedef|typedef
name|void
modifier|*
name|thread_result_t
typedef|;
comment|// Host thread result type
typedef|typedef
name|void
modifier|*
function_decl|(
modifier|*
name|thread_func_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
comment|// Host thread function type
typedef|typedef
name|void
function_decl|(
modifier|*
name|LogOutputCallback
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|void
modifier|*
name|baton
parameter_list|)
function_decl|;
typedef|typedef
name|bool
function_decl|(
modifier|*
name|CommandOverrideCallback
function_decl|)
parameter_list|(
name|void
modifier|*
name|baton
parameter_list|,
specifier|const
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LLDB_INVALID_HOST_THREAD
value|((lldb::thread_t)NULL)
end_define

begin_define
define|#
directive|define
name|IS_VALID_LLDB_HOST_THREAD
parameter_list|(
name|t
parameter_list|)
value|((t) != LLDB_INVALID_HOST_THREAD)
end_define

begin_define
define|#
directive|define
name|LLDB_INVALID_HOST_TIME
value|{ 0, 0 }
end_define

begin_decl_stmt
name|namespace
name|lldb
block|{
typedef|typedef
name|uint64_t
name|addr_t
typedef|;
typedef|typedef
name|uint64_t
name|user_id_t
typedef|;
typedef|typedef
name|uint64_t
name|pid_t
typedef|;
typedef|typedef
name|uint64_t
name|tid_t
typedef|;
typedef|typedef
name|uint64_t
name|offset_t
typedef|;
typedef|typedef
name|int32_t
name|break_id_t
typedef|;
typedef|typedef
name|int32_t
name|watch_id_t
typedef|;
typedef|typedef
name|void
modifier|*
name|clang_type_t
typedef|;
typedef|typedef
name|uint64_t
name|queue_id_t
typedef|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_lldb_types_h_
end_comment

end_unit

