begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 1998-2001, 2003  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: rwlock.h,v 1.18.2.3.2.1 2004/03/06 08:14:47 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_RWLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_RWLOCK_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/condition.h>
end_include

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_macro
name|ISC_LANG_BEGINDECLS
end_macro

begin_typedef
typedef|typedef
enum|enum
block|{
name|isc_rwlocktype_none
init|=
literal|0
block|,
name|isc_rwlocktype_read
block|,
name|isc_rwlocktype_write
block|}
name|isc_rwlocktype_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_USETHREADS
end_ifdef

begin_struct
struct|struct
name|isc_rwlock
block|{
comment|/* Unlocked. */
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_mutex_t
name|lock
decl_stmt|;
comment|/* Locked by lock. */
name|isc_condition_t
name|readable
decl_stmt|;
name|isc_condition_t
name|writeable
decl_stmt|;
name|isc_rwlocktype_t
name|type
decl_stmt|;
comment|/* The number of threads that have the lock. */
name|unsigned
name|int
name|active
decl_stmt|;
comment|/* 	 * The number of lock grants made since the lock was last switched 	 * from reading to writing or vice versa; used in determining 	 * when the quota is reached and it is time to switch. 	 */
name|unsigned
name|int
name|granted
decl_stmt|;
name|unsigned
name|int
name|readers_waiting
decl_stmt|;
name|unsigned
name|int
name|writers_waiting
decl_stmt|;
name|unsigned
name|int
name|read_quota
decl_stmt|;
name|unsigned
name|int
name|write_quota
decl_stmt|;
name|isc_rwlocktype_t
name|original
decl_stmt|;
block|}
struct|;
end_struct

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ISC_PLATFORM_USETHREADS */
end_comment

begin_struct
struct|struct
name|isc_rwlock
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|isc_rwlocktype_t
name|type
decl_stmt|;
name|unsigned
name|int
name|active
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_PLATFORM_USETHREADS */
end_comment

begin_function_decl
name|isc_result_t
name|isc_rwlock_init
parameter_list|(
name|isc_rwlock_t
modifier|*
name|rwl
parameter_list|,
name|unsigned
name|int
name|read_quota
parameter_list|,
name|unsigned
name|int
name|write_quota
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_rwlock_lock
parameter_list|(
name|isc_rwlock_t
modifier|*
name|rwl
parameter_list|,
name|isc_rwlocktype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_rwlock_trylock
parameter_list|(
name|isc_rwlock_t
modifier|*
name|rwl
parameter_list|,
name|isc_rwlocktype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_rwlock_unlock
parameter_list|(
name|isc_rwlock_t
modifier|*
name|rwl
parameter_list|,
name|isc_rwlocktype_t
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|isc_result_t
name|isc_rwlock_tryupgrade
parameter_list|(
name|isc_rwlock_t
modifier|*
name|rwl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_rwlock_downgrade
parameter_list|(
name|isc_rwlock_t
modifier|*
name|rwl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_rwlock_destroy
parameter_list|(
name|isc_rwlock_t
modifier|*
name|rwl
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_RWLOCK_H */
end_comment

end_unit

