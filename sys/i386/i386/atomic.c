begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 Peter Jeremy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* This file creates publically callable functions to perform various  * simple arithmetic on memory which is atomic in the presence of  * interrupts and multiple processors.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_comment
comment|/* Firstly make atomic.h generate prototypes as it will for kernel modules */
end_comment

begin_define
define|#
directive|define
name|KLD_MODULE
end_define

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_undef
undef|#
directive|undef
name|_MACHINE_ATOMIC_H_
end_undef

begin_comment
comment|/* forget we included it */
end_comment

begin_undef
undef|#
directive|undef
name|KLD_MODULE
end_undef

begin_undef
undef|#
directive|undef
name|ATOMIC_ASM
end_undef

begin_comment
comment|/* Make atomic.h generate public functions */
end_comment

begin_define
define|#
directive|define
name|static
end_define

begin_undef
undef|#
directive|undef
name|__inline
end_undef

begin_define
define|#
directive|define
name|__inline
end_define

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

end_unit

