begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Ed Schouten<ed@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_THREADS_H_
end_ifndef

begin_define
define|#
directive|define
name|_THREADS_H_
end_define

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_comment
comment|/*  * The C11 threads interface.  *  * This interface is implemented as a light-weight wrapper around  *<pthread.h>.  To prevent namespace pollution, the once_flag object,  * its corresponding ONCE_FLAG_INIT and TSS_DTOR_ITERATIONS have been  * copied from this header file.  They must be kept in sync.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|pthread_cond
modifier|*
name|cnd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread_mutex
modifier|*
name|mtx_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|pthread
modifier|*
name|thrd_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|tss_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|__state
decl_stmt|;
name|mtx_t
name|__mutex
decl_stmt|;
block|}
name|once_flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|tss_dtor_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|thrd_start_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_enum
enum|enum
block|{
name|mtx_plain
init|=
literal|0x1
block|,
name|mtx_recursive
init|=
literal|0x2
block|,
name|mtx_timed
init|=
literal|0x4
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
name|thrd_busy
init|=
literal|1
block|,
name|thrd_error
init|=
literal|2
block|,
name|thrd_nomem
init|=
literal|3
block|,
name|thrd_success
init|=
literal|4
block|,
name|thrd_timedout
init|=
literal|5
block|}
enum|;
end_enum

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__cplusplus
argument_list|)
operator|||
name|__cplusplus
operator|<
literal|201103L
end_if

begin_define
define|#
directive|define
name|thread_local
value|_Thread_local
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ONCE_FLAG_INIT
value|{ 0, NULL }
end_define

begin_define
define|#
directive|define
name|TSS_DTOR_ITERATIONS
value|4
end_define

begin_function_decl
name|__BEGIN_DECLS
name|void
name|call_once
parameter_list|(
name|once_flag
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cnd_broadcast
parameter_list|(
name|cnd_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cnd_destroy
parameter_list|(
name|cnd_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cnd_init
parameter_list|(
name|cnd_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cnd_signal
parameter_list|(
name|cnd_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cnd_timedwait
parameter_list|(
name|cnd_t
modifier|*
name|__restrict
parameter_list|,
name|mtx_t
modifier|*
name|__restrict
name|__mtx
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|__restrict
parameter_list|)
function_decl|__requires_exclusive
parameter_list|(
function_decl|*__mtx
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|cnd_wait
parameter_list|(
name|cnd_t
modifier|*
parameter_list|,
name|mtx_t
modifier|*
name|__mtx
parameter_list|)
function_decl|__requires_exclusive
parameter_list|(
function_decl|*__mtx
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|mtx_destroy
parameter_list|(
name|mtx_t
modifier|*
name|__mtx
parameter_list|)
function_decl|__requires_unlocked
parameter_list|(
function_decl|*__mtx
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|mtx_init
parameter_list|(
name|mtx_t
modifier|*
name|__mtx
parameter_list|,
name|int
parameter_list|)
function_decl|__requires_unlocked
parameter_list|(
function_decl|*__mtx
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|mtx_lock
parameter_list|(
name|mtx_t
modifier|*
name|__mtx
parameter_list|)
function_decl|__locks_exclusive
parameter_list|(
function_decl|*__mtx
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|mtx_timedlock
parameter_list|(
name|mtx_t
modifier|*
name|__restrict
name|__mtx
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|__restrict
parameter_list|)
function_decl|__trylocks_exclusive
parameter_list|(
name|thrd_success
parameter_list|,
function_decl|*__mtx
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|mtx_trylock
parameter_list|(
name|mtx_t
modifier|*
name|__mtx
parameter_list|)
function_decl|__trylocks_exclusive
parameter_list|(
name|thrd_success
parameter_list|,
function_decl|*__mtx
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|mtx_unlock
parameter_list|(
name|mtx_t
modifier|*
name|__mtx
parameter_list|)
function_decl|__unlocks
parameter_list|(
function_decl|*__mtx
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|int
name|thrd_create
parameter_list|(
name|thrd_t
modifier|*
parameter_list|,
name|thrd_start_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|thrd_t
name|thrd_current
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thrd_detach
parameter_list|(
name|thrd_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thrd_equal
parameter_list|(
name|thrd_t
parameter_list|,
name|thrd_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|_Noreturn
name|void
name|thrd_exit
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thrd_join
parameter_list|(
name|thrd_t
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|thrd_sleep
parameter_list|(
specifier|const
name|struct
name|timespec
modifier|*
parameter_list|,
name|struct
name|timespec
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|thrd_yield
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tss_create
parameter_list|(
name|tss_t
modifier|*
parameter_list|,
name|tss_dtor_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tss_delete
parameter_list|(
name|tss_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|tss_get
parameter_list|(
name|tss_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|tss_set
parameter_list|(
name|tss_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_THREADS_H_ */
end_comment

end_unit

