begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000, 2001 Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_MCHAIN_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_MCHAIN_H_
end_define

begin_include
include|#
directive|include
file|<machine/endian.h>
end_include

begin_comment
comment|/*  * This macros probably belongs to the endian.h  */
end_comment

begin_if
if|#
directive|if
operator|(
name|BYTE_ORDER
operator|==
name|LITTLE_ENDIAN
operator|)
end_if

begin_define
define|#
directive|define
name|htoles
parameter_list|(
name|x
parameter_list|)
value|((u_int16_t)(x))
end_define

begin_define
define|#
directive|define
name|letohs
parameter_list|(
name|x
parameter_list|)
value|((u_int16_t)(x))
end_define

begin_define
define|#
directive|define
name|htolel
parameter_list|(
name|x
parameter_list|)
value|((u_int32_t)(x))
end_define

begin_define
define|#
directive|define
name|letohl
parameter_list|(
name|x
parameter_list|)
value|((u_int32_t)(x))
end_define

begin_define
define|#
directive|define
name|htoleq
parameter_list|(
name|x
parameter_list|)
value|((int64_t)(x))
end_define

begin_define
define|#
directive|define
name|letohq
parameter_list|(
name|x
parameter_list|)
value|((int64_t)(x))
end_define

begin_define
define|#
directive|define
name|htobes
parameter_list|(
name|x
parameter_list|)
value|(htons(x))
end_define

begin_define
define|#
directive|define
name|betohs
parameter_list|(
name|x
parameter_list|)
value|(ntohs(x))
end_define

begin_define
define|#
directive|define
name|htobel
parameter_list|(
name|x
parameter_list|)
value|(htonl(x))
end_define

begin_define
define|#
directive|define
name|betohl
parameter_list|(
name|x
parameter_list|)
value|(ntohl(x))
end_define

begin_function
specifier|static
name|__inline
name|int64_t
name|htobeq
parameter_list|(
name|int64_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|int64_t
operator|)
name|htonl
argument_list|(
call|(
name|u_int32_t
call|)
argument_list|(
name|x
operator|>>
literal|32
argument_list|)
argument_list|)
operator||
operator|(
name|int64_t
operator|)
name|htonl
argument_list|(
call|(
name|u_int32_t
call|)
argument_list|(
name|x
operator|&
literal|0xffffffff
argument_list|)
argument_list|)
operator|<<
literal|32
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int64_t
name|betohq
parameter_list|(
name|int64_t
name|x
parameter_list|)
block|{
return|return
operator|(
name|int64_t
operator|)
name|ntohl
argument_list|(
call|(
name|u_int32_t
call|)
argument_list|(
name|x
operator|>>
literal|32
argument_list|)
argument_list|)
operator||
operator|(
name|int64_t
operator|)
name|ntohl
argument_list|(
call|(
name|u_int32_t
call|)
argument_list|(
name|x
operator|&
literal|0xffffffff
argument_list|)
argument_list|)
operator|<<
literal|32
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* (BYTE_ORDER == LITTLE_ENDIAN) */
end_comment

begin_error
error|#
directive|error
literal|"Macros for Big-Endians are incomplete"
end_error

begin_comment
comment|/* #define htoles(x)	((u_int16_t)(x)) #define letohs(x)	((u_int16_t)(x)) #define	htolel(x)	((u_int32_t)(x)) #define	letohl(x)	((u_int32_t)(x)) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* (BYTE_ORDER == LITTLE_ENDIAN) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Type of copy for mb_{put|get}_mem()  */
end_comment

begin_define
define|#
directive|define
name|MB_MSYSTEM
value|0
end_define

begin_comment
comment|/* use bcopy() */
end_comment

begin_define
define|#
directive|define
name|MB_MUSER
value|1
end_define

begin_comment
comment|/* use copyin()/copyout() */
end_comment

begin_define
define|#
directive|define
name|MB_MINLINE
value|2
end_define

begin_comment
comment|/* use an inline copy loop */
end_comment

begin_define
define|#
directive|define
name|MB_MZERO
value|3
end_define

begin_comment
comment|/* bzero(), mb_put_mem only */
end_comment

begin_define
define|#
directive|define
name|MB_MCUSTOM
value|4
end_define

begin_comment
comment|/* use an user defined function */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbchain
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
name|mb_copy_t
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|c_caddr_t
name|src
parameter_list|,
name|caddr_t
name|dst
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|mbchain
block|{
name|struct
name|mbuf
modifier|*
name|mb_top
decl_stmt|;
comment|/* head of mbufs chain */
name|struct
name|mbuf
modifier|*
name|mb_cur
decl_stmt|;
comment|/* current mbuf */
name|int
name|mb_mleft
decl_stmt|;
comment|/* free space in the current mbuf */
name|int
name|mb_count
decl_stmt|;
comment|/* total number of bytes */
name|mb_copy_t
modifier|*
name|mb_copy
decl_stmt|;
comment|/* user defined copy function */
name|void
modifier|*
name|mb_udata
decl_stmt|;
comment|/* user data */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|mdchain
block|{
name|struct
name|mbuf
modifier|*
name|md_top
decl_stmt|;
comment|/* head of mbufs chain */
name|struct
name|mbuf
modifier|*
name|md_cur
decl_stmt|;
comment|/* current mbuf */
name|u_char
modifier|*
name|md_pos
decl_stmt|;
comment|/* offset in the current mbuf */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|m_fixhdr
parameter_list|(
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_init
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mb_initm
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mb_done
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|mbuf
modifier|*
name|mb_detach
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_fixhdr
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|caddr_t
name|mb_reserve
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_put_uint8
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|u_int8_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_put_uint16be
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|u_int16_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_put_uint16le
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|u_int16_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_put_uint32be
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|u_int32_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_put_uint32le
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|u_int32_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_put_int64be
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|int64_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_put_int64le
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|int64_t
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_put_mem
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|c_caddr_t
name|source
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_put_mbuf
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|mb_put_uio
parameter_list|(
name|struct
name|mbchain
modifier|*
name|mbp
parameter_list|,
name|struct
name|uio
modifier|*
name|uiop
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_init
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_initm
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mbp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_done
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_append_record
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|struct
name|mbuf
modifier|*
name|top
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_next_record
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_uint8
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|u_int8_t
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_uint16
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|u_int16_t
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_uint16le
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|u_int16_t
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_uint16be
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|u_int16_t
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_uint32
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|u_int32_t
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_uint32be
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|u_int32_t
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_uint32le
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|u_int32_t
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_int64
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|int64_t
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_int64be
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|int64_t
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_int64le
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|int64_t
modifier|*
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_mem
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|caddr_t
name|target
parameter_list|,
name|int
name|size
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_mbuf
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|int
name|size
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_get_uio
parameter_list|(
name|struct
name|mdchain
modifier|*
name|mdp
parameter_list|,
name|struct
name|uio
modifier|*
name|uiop
parameter_list|,
name|int
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifdef _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_MCHAIN_H_ */
end_comment

end_unit

