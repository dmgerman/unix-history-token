begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_COMPAT_FREEBSD32_FREEBSD32_H_
end_ifndef

begin_define
define|#
directive|define
name|_COMPAT_FREEBSD32_FREEBSD32_H_
end_define

begin_define
define|#
directive|define
name|PTRIN
parameter_list|(
name|v
parameter_list|)
value|(void *)(uintptr_t) (v)
end_define

begin_define
define|#
directive|define
name|PTROUT
parameter_list|(
name|v
parameter_list|)
value|(u_int32_t)(uintptr_t) (v)
end_define

begin_define
define|#
directive|define
name|CP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|fld
parameter_list|)
value|do { (dst).fld = (src).fld; } while (0)
end_define

begin_define
define|#
directive|define
name|PTRIN_CP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|fld
parameter_list|)
define|\
value|do { (dst).fld = PTRIN((src).fld); } while (0)
end_define

begin_define
define|#
directive|define
name|PTROUT_CP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|fld
parameter_list|)
define|\
value|do { (dst).fld = PTROUT((src).fld); } while (0)
end_define

begin_struct
struct|struct
name|timeval32
block|{
name|int32_t
name|tv_sec
decl_stmt|;
name|int32_t
name|tv_usec
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TV_CP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|fld
parameter_list|)
value|do {			\ 	CP((src).fld,(dst).fld,tv_sec);		\ 	CP((src).fld,(dst).fld,tv_usec);	\ } while (0);
end_define

begin_struct
struct|struct
name|timespec32
block|{
name|u_int32_t
name|tv_sec
decl_stmt|;
name|u_int32_t
name|tv_nsec
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TS_CP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|fld
parameter_list|)
value|do {			\ 	CP((src).fld,(dst).fld,tv_sec);		\ 	CP((src).fld,(dst).fld,tv_nsec);	\ } while (0);
end_define

begin_struct
struct|struct
name|rusage32
block|{
name|struct
name|timeval32
name|ru_utime
decl_stmt|;
name|struct
name|timeval32
name|ru_stime
decl_stmt|;
name|int32_t
name|ru_maxrss
decl_stmt|;
name|int32_t
name|ru_ixrss
decl_stmt|;
name|int32_t
name|ru_idrss
decl_stmt|;
name|int32_t
name|ru_isrss
decl_stmt|;
name|int32_t
name|ru_minflt
decl_stmt|;
name|int32_t
name|ru_majflt
decl_stmt|;
name|int32_t
name|ru_nswap
decl_stmt|;
name|int32_t
name|ru_inblock
decl_stmt|;
name|int32_t
name|ru_oublock
decl_stmt|;
name|int32_t
name|ru_msgsnd
decl_stmt|;
name|int32_t
name|ru_msgrcv
decl_stmt|;
name|int32_t
name|ru_nsignals
decl_stmt|;
name|int32_t
name|ru_nvcsw
decl_stmt|;
name|int32_t
name|ru_nivcsw
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FREEBSD4_MNAMELEN
value|(88 - 2 * sizeof(int32_t))
end_define

begin_comment
comment|/* size of on/from name bufs */
end_comment

begin_comment
comment|/* 4.x version */
end_comment

begin_struct
struct|struct
name|statfs32
block|{
name|int32_t
name|f_spare2
decl_stmt|;
name|int32_t
name|f_bsize
decl_stmt|;
name|int32_t
name|f_iosize
decl_stmt|;
name|int32_t
name|f_blocks
decl_stmt|;
name|int32_t
name|f_bfree
decl_stmt|;
name|int32_t
name|f_bavail
decl_stmt|;
name|int32_t
name|f_files
decl_stmt|;
name|int32_t
name|f_ffree
decl_stmt|;
name|fsid_t
name|f_fsid
decl_stmt|;
name|uid_t
name|f_owner
decl_stmt|;
name|int32_t
name|f_type
decl_stmt|;
name|int32_t
name|f_flags
decl_stmt|;
name|int32_t
name|f_syncwrites
decl_stmt|;
name|int32_t
name|f_asyncwrites
decl_stmt|;
name|char
name|f_fstypename
index|[
name|MFSNAMELEN
index|]
decl_stmt|;
name|char
name|f_mntonname
index|[
name|FREEBSD4_MNAMELEN
index|]
decl_stmt|;
name|int32_t
name|f_syncreads
decl_stmt|;
name|int32_t
name|f_asyncreads
decl_stmt|;
name|int16_t
name|f_spares1
decl_stmt|;
name|char
name|f_mntfromname
index|[
name|FREEBSD4_MNAMELEN
index|]
decl_stmt|;
name|int16_t
name|f_spares2
name|__packed
decl_stmt|;
name|int32_t
name|f_spare
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_COMPAT_FREEBSD32_FREEBSD32_H_ */
end_comment

end_unit

