begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)bit.h	8.2 (Berkeley) 4/28/95  */
end_comment

begin_comment
comment|/*  * bit.h --  *  *	Definition of macros for setting and clearing bits in an array  *	of integers.  *  *	It is assumed that "int" is 32 bits wide.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BIT
end_ifndef

begin_define
define|#
directive|define
name|_BIT
end_define

begin_include
include|#
directive|include
file|"sprite.h"
end_include

begin_define
define|#
directive|define
name|BIT_NUM_BITS_PER_INT
value|32
end_define

begin_define
define|#
directive|define
name|BIT_NUM_BITS_PER_BYTE
value|8
end_define

begin_define
define|#
directive|define
name|Bit_NumInts
parameter_list|(
name|numBits
parameter_list|)
define|\
value|(((numBits)+BIT_NUM_BITS_PER_INT -1)/BIT_NUM_BITS_PER_INT)
end_define

begin_define
define|#
directive|define
name|Bit_NumBytes
parameter_list|(
name|numBits
parameter_list|)
define|\
value|(Bit_NumInts(numBits) * sizeof(int))
end_define

begin_define
define|#
directive|define
name|Bit_Alloc
parameter_list|(
name|numBits
parameter_list|,
name|bitArrayPtr
parameter_list|)
define|\
value|bitArrayPtr = (int *)malloc((unsigned)Bit_NumBytes(numBits)); \         Bit_Zero((numBits), (bitArrayPtr))
end_define

begin_define
define|#
directive|define
name|Bit_Free
parameter_list|(
name|bitArrayPtr
parameter_list|)
define|\
value|free((char *)bitArrayPtr)
end_define

begin_define
define|#
directive|define
name|Bit_Set
parameter_list|(
name|numBits
parameter_list|,
name|bitArrayPtr
parameter_list|)
define|\
value|((bitArrayPtr)[(numBits)/BIT_NUM_BITS_PER_INT] |= \ 				(1<< ((numBits) % BIT_NUM_BITS_PER_INT)))
end_define

begin_define
define|#
directive|define
name|Bit_IsSet
parameter_list|(
name|numBits
parameter_list|,
name|bitArrayPtr
parameter_list|)
define|\
value|((bitArrayPtr)[(numBits)/BIT_NUM_BITS_PER_INT]& \ 				(1<< ((numBits) % BIT_NUM_BITS_PER_INT)))
end_define

begin_define
define|#
directive|define
name|Bit_Clear
parameter_list|(
name|numBits
parameter_list|,
name|bitArrayPtr
parameter_list|)
define|\
value|((bitArrayPtr)[(numBits)/BIT_NUM_BITS_PER_INT]&= \ 				~(1<< ((numBits) % BIT_NUM_BITS_PER_INT)))
end_define

begin_define
define|#
directive|define
name|Bit_IsClear
parameter_list|(
name|numBits
parameter_list|,
name|bitArrayPtr
parameter_list|)
define|\
value|(!(Bit_IsSet((numBits), (bitArrayPtr))))
end_define

begin_define
define|#
directive|define
name|Bit_Copy
parameter_list|(
name|numBits
parameter_list|,
name|srcArrayPtr
parameter_list|,
name|destArrayPtr
parameter_list|)
define|\
value|bcopy((char *)(srcArrayPtr), (char *)(destArrayPtr), \ 		Bit_NumBytes(numBits))
end_define

begin_define
define|#
directive|define
name|Bit_Zero
parameter_list|(
name|numBits
parameter_list|,
name|bitArrayPtr
parameter_list|)
define|\
value|bzero((char *)(bitArrayPtr), Bit_NumBytes(numBits))
end_define

begin_function_decl
specifier|extern
name|int
name|Bit_FindFirstSet
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|Bit_FindFirstClear
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|Bit_Intersect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|Bit_Union
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|Boolean
name|Bit_AnySet
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
modifier|*
name|Bit_Expand
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BIT */
end_comment

end_unit

