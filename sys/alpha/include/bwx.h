begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BWX_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BWX_H_
end_define

begin_comment
comment|/*  * Byte/word accesses must be made with particular values for addr<37,38>  */
end_comment

begin_define
define|#
directive|define
name|BWX_EV56_INT8
value|(0L<< 37)
end_define

begin_define
define|#
directive|define
name|BWX_EV56_INT4
value|(1L<< 37)
end_define

begin_define
define|#
directive|define
name|BWX_EV56_INT2
value|(2L<< 37)
end_define

begin_define
define|#
directive|define
name|BWX_EV56_INT1
value|(3L<< 37)
end_define

begin_function
specifier|static
name|__inline
name|u_int8_t
name|ldbu
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
block|{
name|u_int64_t
name|r
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("ldbu %0,%1" : "=r"(r) : "m"(*(u_int8_t*)va));
return|return
name|r
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int16_t
name|ldwu
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
block|{
name|u_int64_t
name|r
decl_stmt|;
asm|__asm__
specifier|__volatile__
asm|("ldwu %0,%1" : "=r"(r) : "m"(*(u_int16_t*)va));
return|return
name|r
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|u_int32_t
name|ldl
parameter_list|(
name|vm_offset_t
name|va
parameter_list|)
block|{
return|return
operator|*
operator|(
name|u_int32_t
operator|*
operator|)
name|va
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|stb
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|u_int64_t
name|r
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("stb %1,%0" : "=m"(*(u_int8_t*)va) : "r"(r));
asm|__asm__
specifier|__volatile__
asm|("mb");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|stw
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|u_int64_t
name|r
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("stw %1,%0" : "=m"(*(u_int16_t*)va) : "r"(r));
asm|__asm__
specifier|__volatile__
asm|("mb");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|stl
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|u_int64_t
name|r
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("stl %1,%0" : "=m"(*(u_int32_t*)va) : "r"(r));
asm|__asm__
specifier|__volatile__
asm|("mb");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|stb_nb
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|u_int64_t
name|r
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("stb %1,%0" : "=m"(*(u_int8_t*)va) : "r"(r));
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|stw_nb
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|u_int64_t
name|r
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("stw %1,%0" : "=m"(*(u_int16_t*)va) : "r"(r));
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|stl_nb
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|u_int64_t
name|r
parameter_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("stl %1,%0" : "=m"(*(u_int32_t*)va) : "r"(r));
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_BWX_H_ */
end_comment

end_unit

