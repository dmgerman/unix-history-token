begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * bit.h --  *  *	Definition of macros for setting and clearing bits in an array  *	of integers.  *  *	It is assumed that "int" is 32 bits wide.  *  * Copyright 1987 Regents of the University of California  * All rights reserved.  *  *  * $Id: bit.h,v 2.1 89/07/03 15:49:11 adam Exp $ SPRITE (Berkeley)  */
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
endif|_BIT
end_endif

end_unit

