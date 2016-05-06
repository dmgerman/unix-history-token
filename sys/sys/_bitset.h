begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008, Jeffrey Roberson<jeff@freebsd.org>  * All rights reserved.  *  * Copyright (c) 2008 Nokia Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS__BITSET_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS__BITSET_H_
end_define

begin_comment
comment|/*  * Macros addressing word and bit within it, tuned to make compiler  * optimize cases when SETSIZE fits into single machine word.  */
end_comment

begin_define
define|#
directive|define
name|_BITSET_BITS
value|(sizeof(long) * 8)
end_define

begin_define
define|#
directive|define
name|__howmany
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(((x) + ((y) - 1)) / (y))
end_define

begin_define
define|#
directive|define
name|__bitset_words
parameter_list|(
name|_s
parameter_list|)
value|(__howmany(_s, _BITSET_BITS))
end_define

begin_define
define|#
directive|define
name|BITSET_DEFINE
parameter_list|(
name|t
parameter_list|,
name|_s
parameter_list|)
define|\
value|struct t {								\         long    __bits[__bitset_words((_s))];				\ }
end_define

begin_comment
comment|/*  * Helper to declare a bitset without it's size being a constant.  *  * Sadly we cannot declare a bitset struct with '__bits[]', because it's  * the only member of the struct and the compiler complains.  */
end_comment

begin_define
define|#
directive|define
name|BITSET_DEFINE_VAR
parameter_list|(
name|t
parameter_list|)
value|BITSET_DEFINE(t, 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS__BITSET_H_ */
end_comment

end_unit

