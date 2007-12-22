begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 Marcel Moolenaar  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<machine/float.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_comment
comment|/* Memory accesses. */
end_comment

begin_define
define|#
directive|define
name|Load
value|0x01
end_define

begin_define
define|#
directive|define
name|Store
value|0x02
end_define

begin_comment
comment|/* Data type. */
end_comment

begin_define
define|#
directive|define
name|Integer
value|0x11
end_define

begin_define
define|#
directive|define
name|FloatingPoint
value|0x12
end_define

begin_comment
comment|/* Data size. */
end_comment

begin_define
define|#
directive|define
name|Small
value|0x21
end_define

begin_define
define|#
directive|define
name|Medium
value|0x22
end_define

begin_define
define|#
directive|define
name|Large
value|0x23
end_define

begin_comment
comment|/* Post increment. */
end_comment

begin_define
define|#
directive|define
name|NoPostInc
value|0x31
end_define

begin_define
define|#
directive|define
name|MinConstPostInc
value|0x32
end_define

begin_define
define|#
directive|define
name|PlusConstPostInc
value|0x33
end_define

begin_define
define|#
directive|define
name|ScratchRegPostInc
value|0x34
end_define

begin_define
define|#
directive|define
name|PreservedRegPostInc
value|0x35
end_define

begin_if
if|#
directive|if
name|ACCESS
operator|==
literal|0
operator|||
name|TYPE
operator|==
literal|0
operator|||
name|SIZE
operator|==
literal|0
operator|||
name|POSTINC
operator|==
literal|0
end_if

begin_error
error|#
directive|error
error|define ACCESS, TYPE, SIZE and/or POSTINC
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|TYPE
operator|==
name|Integer
end_if

begin_define
define|#
directive|define
name|REG
value|"r8"
end_define

begin_if
if|#
directive|if
name|SIZE
operator|==
name|Small
end_if

begin_define
define|#
directive|define
name|DATA_TYPE
value|short
end_define

begin_define
define|#
directive|define
name|DATA_VALUE
value|0x1234
end_define

begin_define
define|#
directive|define
name|LD
value|"ld2"
end_define

begin_define
define|#
directive|define
name|ST
value|"st2"
end_define

begin_elif
elif|#
directive|elif
name|SIZE
operator|==
name|Medium
end_elif

begin_define
define|#
directive|define
name|DATA_TYPE
value|int
end_define

begin_define
define|#
directive|define
name|DATA_VALUE
value|0x12345678
end_define

begin_define
define|#
directive|define
name|LD
value|"ld4"
end_define

begin_define
define|#
directive|define
name|ST
value|"st4"
end_define

begin_elif
elif|#
directive|elif
name|SIZE
operator|==
name|Large
end_elif

begin_define
define|#
directive|define
name|DATA_TYPE
value|long
end_define

begin_define
define|#
directive|define
name|DATA_VALUE
value|0x1234567890ABCDEF
end_define

begin_define
define|#
directive|define
name|LD
value|"ld8"
end_define

begin_define
define|#
directive|define
name|ST
value|"st8"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|TYPE
operator|==
name|FloatingPoint
end_elif

begin_define
define|#
directive|define
name|REG
value|"f6"
end_define

begin_if
if|#
directive|if
name|SIZE
operator|==
name|Small
end_if

begin_define
define|#
directive|define
name|DATA_TYPE
value|float
end_define

begin_define
define|#
directive|define
name|DATA_VALUE
value|FLT_MIN
end_define

begin_define
define|#
directive|define
name|LD
value|"ldfs"
end_define

begin_define
define|#
directive|define
name|ST
value|"stfs"
end_define

begin_elif
elif|#
directive|elif
name|SIZE
operator|==
name|Medium
end_elif

begin_define
define|#
directive|define
name|DATA_TYPE
value|double
end_define

begin_define
define|#
directive|define
name|DATA_VALUE
value|DBL_MIN
end_define

begin_define
define|#
directive|define
name|LD
value|"ldfd"
end_define

begin_define
define|#
directive|define
name|ST
value|"stfd"
end_define

begin_elif
elif|#
directive|elif
name|SIZE
operator|==
name|Large
end_elif

begin_define
define|#
directive|define
name|DATA_TYPE
value|long double
end_define

begin_define
define|#
directive|define
name|DATA_VALUE
value|LDBL_MIN
end_define

begin_define
define|#
directive|define
name|LD
value|"ldfe"
end_define

begin_define
define|#
directive|define
name|ST
value|"stfe"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
block|{
name|DATA_TYPE
name|aligned
decl_stmt|;
name|char
name|_
decl_stmt|;
name|char
name|misaligned
index|[
sizeof|sizeof
argument_list|(
name|DATA_TYPE
argument_list|)
index|]
decl_stmt|;
block|}
name|data
struct|;
end_struct

begin_decl_stmt
name|DATA_TYPE
modifier|*
name|aligned
init|=
operator|&
name|data
operator|.
name|aligned
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DATA_TYPE
modifier|*
name|misaligned
init|=
operator|(
name|DATA_TYPE
operator|*
operator|)
name|data
operator|.
name|misaligned
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DATA_TYPE
name|value
init|=
name|DATA_VALUE
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|block_copy
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|sz
parameter_list|)
block|{
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|sz
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|()
block|{
comment|/* Set PSR.ac. */
asm|asm
specifier|volatile
asm|("sum 8");
if|#
directive|if
name|ACCESS
operator|==
name|Load
comment|/* 	 * LOAD 	 */
name|block_copy
argument_list|(
name|misaligned
argument_list|,
operator|&
name|value
argument_list|,
sizeof|sizeof
argument_list|(
name|DATA_TYPE
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|POSTINC
operator|==
name|NoPostInc
comment|/* Misaligned load. */
operator|*
name|aligned
operator|=
operator|*
name|misaligned
expr_stmt|;
elif|#
directive|elif
name|POSTINC
operator|==
name|MinConstPostInc
asm|asm
specifier|volatile
asm|( 		"ld8 r2=%0;;" 		LD " " REG "=[r2],%2;;" 		"st8 %0=r2;" ST " %1=" REG ";;" 	    : "=m"(misaligned), "=m"(*aligned) 	    : "i"(-sizeof(DATA_TYPE)) 	    : REG, "r2", "memory");
elif|#
directive|elif
name|POSTINC
operator|==
name|PlusConstPostInc
asm|asm
specifier|volatile
asm|( 		"ld8 r2=%0;;" 		LD " " REG "=[r2],%2;;" 		"st8 %0=r2;" ST " %1=" REG ";;" 	    : "=m"(misaligned), "=m"(*aligned) 	    : "i"(sizeof(DATA_TYPE)) 	    : REG, "r2", "memory");
elif|#
directive|elif
name|POSTINC
operator|==
name|ScratchRegPostInc
asm|asm
specifier|volatile
asm|( 		"ld8 r2=%0; mov r3=%2;;" 		LD " " REG "=[r2],r3;;" 		"st8 %0=r2;" ST " %1=" REG ";;" 	    : "=m"(misaligned), "=m"(*aligned) 	    : "i"(sizeof(DATA_TYPE)) 	    : REG, "r2", "r3", "memory");
elif|#
directive|elif
name|POSTINC
operator|==
name|PreservedRegPostInc
asm|asm
specifier|volatile
asm|( 		"ld8 r2=%0; mov r4=%2;;" 		LD " " REG "=[r2],r4;;" 		"st8 %0=r2;" ST " %1=" REG ";;" 	    : "=m"(misaligned), "=m"(*aligned) 	    : "i"(sizeof(DATA_TYPE)) 	    : REG, "r2", "r4", "memory");
endif|#
directive|endif
elif|#
directive|elif
name|ACCESS
operator|==
name|Store
comment|/* 	 * STORE 	 */
if|#
directive|if
name|POSTINC
operator|==
name|NoPostInc
comment|/* Misaligned store. */
operator|*
name|misaligned
operator|=
name|value
expr_stmt|;
elif|#
directive|elif
name|POSTINC
operator|==
name|MinConstPostInc
asm|asm
specifier|volatile
asm|( 		"ld8 r2=%0;" LD " " REG "=%1;;" 		ST " [r2]=" REG ",%2;;" 		"st8 %0=r2;;" 	    : "=m"(misaligned) 	    : "m"(value), "i"(-sizeof(DATA_TYPE)) 	    : REG, "r2", "memory");
elif|#
directive|elif
name|POSTINC
operator|==
name|PlusConstPostInc
asm|asm
specifier|volatile
asm|( 		"ld8 r2=%0;" LD " " REG "=%1;;" 		ST " [r2]=" REG ",%2;;" 		"st8 %0=r2;;" 	    : "=m"(misaligned) 	    : "m"(value), "i"(sizeof(DATA_TYPE)) 	    : REG, "r2", "memory");
elif|#
directive|elif
name|POSTINC
operator|==
name|ScratchRegPostInc
operator|||
name|POSTINC
operator|==
name|PreservedRegPostInc
return|return
operator|(
literal|1
operator|)
return|;
endif|#
directive|endif
name|block_copy
argument_list|(
name|aligned
argument_list|,
name|data
operator|.
name|misaligned
argument_list|,
sizeof|sizeof
argument_list|(
name|DATA_TYPE
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|*
name|aligned
operator|!=
name|value
condition|)
return|return
operator|(
literal|2
operator|)
return|;
if|#
directive|if
name|POSTINC
operator|==
name|NoPostInc
return|return
operator|(
literal|0
operator|)
return|;
elif|#
directive|elif
name|POSTINC
operator|==
name|MinConstPostInc
return|return
operator|(
operator|(
operator|(
name|char
operator|*
operator|)
name|misaligned
operator|==
name|data
operator|.
name|misaligned
operator|-
sizeof|sizeof
argument_list|(
name|DATA_TYPE
argument_list|)
operator|)
condition|?
literal|0
else|:
literal|4
operator|)
return|;
else|#
directive|else
return|return
operator|(
operator|(
operator|(
name|char
operator|*
operator|)
name|misaligned
operator|==
name|data
operator|.
name|misaligned
operator|+
sizeof|sizeof
argument_list|(
name|DATA_TYPE
argument_list|)
operator|)
condition|?
literal|0
else|:
literal|4
operator|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

