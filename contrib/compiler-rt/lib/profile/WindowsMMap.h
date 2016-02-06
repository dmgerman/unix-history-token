begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*===- WindowsMMap.h - Support library for PGO instrumentation ------------===*\ |* |*                     The LLVM Compiler Infrastructure |* |* This file is distributed under the University of Illinois Open Source |* License. See LICENSE.TXT for details. |* \*===----------------------------------------------------------------------===*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROFILE_INSTRPROFILING_WINDOWS_MMAP_H
end_ifndef

begin_define
define|#
directive|define
name|PROFILE_INSTRPROFILING_WINDOWS_MMAP_H
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|<BaseTsd.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/*  * mmap() flags  */
end_comment

begin_define
define|#
directive|define
name|PROT_READ
value|0x1
end_define

begin_define
define|#
directive|define
name|PROT_WRITE
value|0x2
end_define

begin_comment
comment|/* This flag is only available in WinXP+ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FILE_MAP_EXECUTE
end_ifdef

begin_define
define|#
directive|define
name|PROT_EXEC
value|0x4
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PROT_EXEC
value|0x0
end_define

begin_define
define|#
directive|define
name|FILE_MAP_EXECUTE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAP_FILE
value|0x00
end_define

begin_define
define|#
directive|define
name|MAP_SHARED
value|0x01
end_define

begin_define
define|#
directive|define
name|MAP_PRIVATE
value|0x02
end_define

begin_define
define|#
directive|define
name|MAP_ANONYMOUS
value|0x20
end_define

begin_define
define|#
directive|define
name|MAP_ANON
value|MAP_ANONYMOUS
end_define

begin_define
define|#
directive|define
name|MAP_FAILED
value|((void *) -1)
end_define

begin_comment
comment|/*  * msync() flags  */
end_comment

begin_define
define|#
directive|define
name|MS_ASYNC
value|0x0001
end_define

begin_comment
comment|/* return immediately */
end_comment

begin_define
define|#
directive|define
name|MS_INVALIDATE
value|0x0002
end_define

begin_comment
comment|/* invalidate all cached data */
end_comment

begin_define
define|#
directive|define
name|MS_SYNC
value|0x0010
end_define

begin_comment
comment|/* msync synchronously */
end_comment

begin_comment
comment|/*  * flock() operations  */
end_comment

begin_define
define|#
directive|define
name|LOCK_SH
value|1
end_define

begin_comment
comment|/* shared lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_EX
value|2
end_define

begin_comment
comment|/* exclusive lock */
end_comment

begin_define
define|#
directive|define
name|LOCK_NB
value|4
end_define

begin_comment
comment|/* don't block when locking */
end_comment

begin_define
define|#
directive|define
name|LOCK_UN
value|8
end_define

begin_comment
comment|/* unlock */
end_comment

begin_function_decl
name|void
modifier|*
name|mmap
parameter_list|(
name|void
modifier|*
name|start
parameter_list|,
name|size_t
name|length
parameter_list|,
name|int
name|prot
parameter_list|,
name|int
name|flags
parameter_list|,
name|int
name|fd
parameter_list|,
name|off_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|munmap
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msync
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|,
name|size_t
name|length
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|flock
parameter_list|(
name|int
name|fd
parameter_list|,
name|int
name|operation
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _WIN32 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROFILE_INSTRPROFILING_WINDOWS_MMAP_H */
end_comment

end_unit

