begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Doug Rabson  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_ATOMIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_ATOMIC_H_
end_define

begin_comment
comment|/*  * Various simple arithmetic on memory which is atomic in the presence  * of interrupts.  *  * Note: these versions are not SMP safe.  */
end_comment

begin_define
define|#
directive|define
name|atomic_set_char
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_char*)(P) |= (V))
end_define

begin_define
define|#
directive|define
name|atomic_clear_char
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_char*)(P)&= ~(V))
end_define

begin_define
define|#
directive|define
name|atomic_add_char
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_char*)(P) += (V))
end_define

begin_define
define|#
directive|define
name|atomic_subtract_char
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_char*)(P) -= (V))
end_define

begin_define
define|#
directive|define
name|atomic_set_short
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_short*)(P) |= (V))
end_define

begin_define
define|#
directive|define
name|atomic_clear_short
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_short*)(P)&= ~(V))
end_define

begin_define
define|#
directive|define
name|atomic_add_short
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_short*)(P) += (V))
end_define

begin_define
define|#
directive|define
name|atomic_subtract_short
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_short*)(P) -= (V))
end_define

begin_define
define|#
directive|define
name|atomic_set_int
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_int*)(P) |= (V))
end_define

begin_define
define|#
directive|define
name|atomic_clear_int
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_int*)(P)&= ~(V))
end_define

begin_define
define|#
directive|define
name|atomic_add_int
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_int*)(P) += (V))
end_define

begin_define
define|#
directive|define
name|atomic_subtract_int
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_int*)(P) -= (V))
end_define

begin_define
define|#
directive|define
name|atomic_set_long
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_long*)(P) |= (V))
end_define

begin_define
define|#
directive|define
name|atomic_clear_long
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_long*)(P)&= ~(V))
end_define

begin_define
define|#
directive|define
name|atomic_add_long
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_long*)(P) += (V))
end_define

begin_define
define|#
directive|define
name|atomic_subtract_long
parameter_list|(
name|P
parameter_list|,
name|V
parameter_list|)
value|(*(u_long*)(P) -= (V))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _MACHINE_ATOMIC_H_ */
end_comment

end_unit

