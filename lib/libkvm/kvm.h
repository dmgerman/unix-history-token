begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)kvm.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KVM_H_
end_ifndef

begin_define
define|#
directive|define
name|_KVM_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/_types.h>
end_include

begin_include
include|#
directive|include
file|<nlist.h>
end_include

begin_comment
comment|/* Default version symbol. */
end_comment

begin_define
define|#
directive|define
name|VRS_SYM
value|"_version"
end_define

begin_define
define|#
directive|define
name|VRS_KEY
value|"VERSION"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_SIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__size_t
name|size_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|_SSIZE_T_DECLARED
end_ifndef

begin_typedef
typedef|typedef
name|__ssize_t
name|ssize_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_SSIZE_T_DECLARED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|__kvm
name|kvm_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|kinfo_proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|kvm_swap
block|{
name|char
name|ksw_devname
index|[
literal|32
index|]
decl_stmt|;
name|int
name|ksw_used
decl_stmt|;
name|int
name|ksw_total
decl_stmt|;
name|int
name|ksw_flags
decl_stmt|;
name|int
name|ksw_reserved1
decl_stmt|;
name|int
name|ksw_reserved2
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|SWIF_DEV_PREFIX
value|0x0002
end_define

begin_function_decl
name|__BEGIN_DECLS
name|int
name|kvm_close
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|kvm_getargv
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|kinfo_proc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|kvm_getenvv
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
specifier|const
name|struct
name|kinfo_proc
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|kvm_geterr
parameter_list|(
name|kvm_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|kvm_getfiles
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kvm_getloadavg
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|double
index|[]
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|kinfo_proc
modifier|*
name|kvm_getprocs
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kvm_getswapinfo
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|struct
name|kvm_swap
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|kvm_nlist
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|struct
name|nlist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kvm_t
modifier|*
name|kvm_open
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|kvm_t
modifier|*
name|kvm_openfiles
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|kvm_read
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|kvm_uread
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|struct
name|kinfo_proc
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|ssize_t
name|kvm_write
parameter_list|(
name|kvm_t
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
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
comment|/* !_KVM_H_ */
end_comment

end_unit

