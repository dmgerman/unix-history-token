begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/md32_common.h */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1999-2007 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  */
end_comment

begin_comment
comment|/*  * This is a generic 32 bit "collector" for message digest algorithms.  * Whenever needed it collects input character stream into chunks of  * 32 bit values and invokes a block function that performs actual hash  * calculations.  *  * Porting guide.  *  * Obligatory macros:  *  * DATA_ORDER_IS_BIG_ENDIAN or DATA_ORDER_IS_LITTLE_ENDIAN  *	this macro defines byte order of input stream.  * HASH_CBLOCK  *	size of a unit chunk HASH_BLOCK operates on.  * HASH_LONG  *	has to be at lest 32 bit wide, if it's wider, then  *	HASH_LONG_LOG2 *has to* be defined along  * HASH_CTX  *	context structure that at least contains following  *	members:  *		typedef struct {  *			...  *			HASH_LONG	Nl,Nh;  *			either {  *			HASH_LONG	data[HASH_LBLOCK];  *			unsigned char	data[HASH_CBLOCK];  *			};  *			unsigned int	num;  *			...  *			} HASH_CTX;  *	data[] vector is expected to be zeroed upon first call to  *	HASH_UPDATE.  * HASH_UPDATE  *	name of "Update" function, implemented here.  * HASH_TRANSFORM  *	name of "Transform" function, implemented here.  * HASH_FINAL  *	name of "Final" function, implemented here.  * HASH_BLOCK_DATA_ORDER  *	name of "block" function capable of treating *unaligned* input  *	message in original (data) byte order, implemented externally.  * HASH_MAKE_STRING  *	macro convering context variables to an ASCII hash string.  *  * MD5 example:  *  *	#define DATA_ORDER_IS_LITTLE_ENDIAN  *  *	#define HASH_LONG		MD5_LONG  *	#define HASH_LONG_LOG2		MD5_LONG_LOG2  *	#define HASH_CTX		MD5_CTX  *	#define HASH_CBLOCK		MD5_CBLOCK  *	#define HASH_UPDATE		MD5_Update  *	#define HASH_TRANSFORM		MD5_Transform  *	#define HASH_FINAL		MD5_Final  *	#define HASH_BLOCK_DATA_ORDER	md5_block_data_order  *  *<appro@fy.chalmers.se>  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DATA_ORDER_IS_BIG_ENDIAN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DATA_ORDER_IS_LITTLE_ENDIAN
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"DATA_ORDER must be defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_CBLOCK
end_ifndef

begin_error
error|#
directive|error
literal|"HASH_CBLOCK must be defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_LONG
end_ifndef

begin_error
error|#
directive|error
literal|"HASH_LONG must be defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_CTX
end_ifndef

begin_error
error|#
directive|error
literal|"HASH_CTX must be defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_UPDATE
end_ifndef

begin_error
error|#
directive|error
literal|"HASH_UPDATE must be defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_TRANSFORM
end_ifndef

begin_error
error|#
directive|error
literal|"HASH_TRANSFORM must be defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_FINAL
end_ifndef

begin_error
error|#
directive|error
literal|"HASH_FINAL must be defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_BLOCK_DATA_ORDER
end_ifndef

begin_error
error|#
directive|error
literal|"HASH_BLOCK_DATA_ORDER must be defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Engage compiler specific rotate intrinsic function if available.  */
end_comment

begin_undef
undef|#
directive|undef
name|ROTATE
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|PEDANTIC
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|||
name|defined
argument_list|(
name|__ICC
argument_list|)
end_if

begin_define
define|#
directive|define
name|ROTATE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|_lrotl(a,n)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MWERKS__
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__POWERPC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ROTATE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|__rlwinm(a,n,0,31)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__MC68K__
argument_list|)
end_elif

begin_comment
comment|/* Motorola specific tweak.<appro@fy.chalmers.se> */
end_comment

begin_define
define|#
directive|define
name|ROTATE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|( n<24 ? __rol(a,n) : __ror(a,32-n) )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ROTATE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|__rol(a,n)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__GNUC__
operator|>=
literal|2
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_ASM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_INLINE_ASM
argument_list|)
end_elif

begin_comment
comment|/*    * Some GNU C inline assembler templates. Note that these are    * rotates by *constant* number of bits! But that's exactly    * what we need here...    *<appro@fy.chalmers.se>    */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|ROTATE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|({ register unsigned int ret;	\ 				asm (			\ 				"roll %1,%0"		\ 				: "=r"(ret)		\ 				: "I"(n), "0"((unsigned int)(a))	\ 				: "cc");		\ 			   ret;				\ 			})
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_ARCH_PPC
argument_list|)
operator|||
name|defined
argument_list|(
name|_ARCH_PPC64
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|__powerpc
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__powerpc64__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ROTATE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|({ register unsigned int ret;	\ 				asm (			\ 				"rlwinm %0,%1,%2,0,31"	\ 				: "=r"(ret)		\ 				: "r"(a), "I"(n));	\ 			   ret;				\ 			})
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__s390x__
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ROTATE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|({ register unsigned int ret;	\ 				asm ("rll %0,%1,%2"	\ 				: "=r"(ret)		\ 				: "r"(a), "I"(n));	\ 			  ret;				\ 			})
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PEDANTIC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ROTATE
end_ifndef

begin_define
define|#
directive|define
name|ROTATE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|(((a)<<(n))|(((a)&0xffffffff)>>(32-(n))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DATA_ORDER_IS_BIG_ENDIAN
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|PEDANTIC
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__GNUC__
operator|>=
literal|2
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_ASM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_INLINE_ASM
argument_list|)
end_if

begin_if
if|#
directive|if
operator|(
operator|(
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|I386_ONLY
argument_list|)
operator|)
operator|||
expr|\
operator|(
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
operator|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|B_ENDIAN
argument_list|)
end_if

begin_comment
comment|/*      * This gives ~30-40% performance improvement in SHA-256 compiled      * with gcc [on P4]. Well, first macro to be frank. We can pull      * this trick on x86* platforms only, because these CPUs can fetch      * unaligned data without raising an exception.      */
end_comment

begin_define
define|#
directive|define
name|HOST_c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|({ unsigned int r=*((const unsigned int *)(c));	\ 				   asm ("bswapl %0":"=r"(r):"0"(r));	\ 				   (c)+=4; (l)=r;			})
end_define

begin_define
define|#
directive|define
name|HOST_l2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|({ unsigned int r=(l);			\ 				   asm ("bswapl %0":"=r"(r):"0"(r));	\ 				   *((unsigned int *)(c))=r; (c)+=4; r;	})
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__s390__
argument_list|)
operator|||
name|defined
argument_list|(
name|__s390x__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HOST_c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|((l)=*((const unsigned int *)(c)), (c)+=4, (l))
end_define

begin_define
define|#
directive|define
name|HOST_l2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((unsigned int *)(c))=(l), (c)+=4, (l))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_c2l
end_ifndef

begin_define
define|#
directive|define
name|HOST_c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =(((unsigned long)(*((c)++)))<<24),		\ 			 l|=(((unsigned long)(*((c)++)))<<16),		\ 			 l|=(((unsigned long)(*((c)++)))<< 8),		\ 			 l|=(((unsigned long)(*((c)++)))    )		)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_l2c
end_ifndef

begin_define
define|#
directive|define
name|HOST_l2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)>>24)&0xff),	\ 			 *((c)++)=(unsigned char)(((l)>>16)&0xff),	\ 			 *((c)++)=(unsigned char)(((l)>> 8)&0xff),	\ 			 *((c)++)=(unsigned char)(((l)    )&0xff),	\ 			 l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DATA_ORDER_IS_LITTLE_ENDIAN
argument_list|)
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|PEDANTIC
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
name|__GNUC__
operator|>=
literal|2
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_ASM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|OPENSSL_NO_INLINE_ASM
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__s390x__
argument_list|)
end_if

begin_define
define|#
directive|define
name|HOST_c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|({ asm ("lrv	%0,%1"			\ 				   :"=d"(l) :"m"(*(const unsigned int *)(c)));\ 				   (c)+=4; (l);				})
end_define

begin_define
define|#
directive|define
name|HOST_l2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|({ asm ("strv	%1,%0"			\ 				   :"=m"(*(unsigned int *)(c)) :"d"(l));\ 				   (c)+=4; (l);				})
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386
argument_list|)
operator|||
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64
argument_list|)
operator|||
name|defined
argument_list|(
name|__x86_64__
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|B_ENDIAN
end_ifndef

begin_comment
comment|/* See comment in DATA_ORDER_IS_BIG_ENDIAN section. */
end_comment

begin_define
define|#
directive|define
name|HOST_c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|((l)=*((const unsigned int *)(c)), (c)+=4, l)
end_define

begin_define
define|#
directive|define
name|HOST_l2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((unsigned int *)(c))=(l), (c)+=4, l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_c2l
end_ifndef

begin_define
define|#
directive|define
name|HOST_c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =(((unsigned long)(*((c)++)))    ),		\ 			 l|=(((unsigned long)(*((c)++)))<< 8),		\ 			 l|=(((unsigned long)(*((c)++)))<<16),		\ 			 l|=(((unsigned long)(*((c)++)))<<24)		)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_l2c
end_ifndef

begin_define
define|#
directive|define
name|HOST_l2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)    )&0xff),	\ 			 *((c)++)=(unsigned char)(((l)>> 8)&0xff),	\ 			 *((c)++)=(unsigned char)(((l)>>16)&0xff),	\ 			 *((c)++)=(unsigned char)(((l)>>24)&0xff),	\ 			 l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Time for some action:-)  */
end_comment

begin_function
name|int
name|HASH_UPDATE
parameter_list|(
name|HASH_CTX
modifier|*
name|c
parameter_list|,
specifier|const
name|void
modifier|*
name|data_
parameter_list|,
name|size_t
name|len
parameter_list|)
block|{
specifier|const
name|unsigned
name|char
modifier|*
name|data
init|=
name|data_
decl_stmt|;
name|unsigned
name|char
modifier|*
name|p
decl_stmt|;
name|HASH_LONG
name|l
decl_stmt|;
name|size_t
name|n
decl_stmt|;
if|if
condition|(
name|len
operator|==
literal|0
condition|)
return|return
literal|1
return|;
name|l
operator|=
operator|(
name|c
operator|->
name|Nl
operator|+
operator|(
operator|(
operator|(
name|HASH_LONG
operator|)
name|len
operator|)
operator|<<
literal|3
operator|)
operator|)
operator|&
literal|0xffffffffUL
expr_stmt|;
comment|/* 95-05-24 eay Fixed a bug with the overflow handling, thanks to 	 * Wei Dai<weidai@eskimo.com> for pointing it out. */
if|if
condition|(
name|l
operator|<
name|c
operator|->
name|Nl
condition|)
comment|/* overflow */
name|c
operator|->
name|Nh
operator|++
expr_stmt|;
name|c
operator|->
name|Nh
operator|+=
call|(
name|HASH_LONG
call|)
argument_list|(
name|len
operator|>>
literal|29
argument_list|)
expr_stmt|;
comment|/* might cause compiler warning on 16-bit */
name|c
operator|->
name|Nl
operator|=
name|l
expr_stmt|;
name|n
operator|=
name|c
operator|->
name|num
expr_stmt|;
if|if
condition|(
name|n
operator|!=
literal|0
condition|)
block|{
name|p
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|c
operator|->
name|data
expr_stmt|;
if|if
condition|(
name|len
operator|>=
name|HASH_CBLOCK
operator|||
name|len
operator|+
name|n
operator|>=
name|HASH_CBLOCK
condition|)
block|{
name|memcpy
argument_list|(
name|p
operator|+
name|n
argument_list|,
name|data
argument_list|,
name|HASH_CBLOCK
operator|-
name|n
argument_list|)
expr_stmt|;
name|HASH_BLOCK_DATA_ORDER
argument_list|(
name|c
argument_list|,
name|p
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|n
operator|=
name|HASH_CBLOCK
operator|-
name|n
expr_stmt|;
name|data
operator|+=
name|n
expr_stmt|;
name|len
operator|-=
name|n
expr_stmt|;
name|c
operator|->
name|num
operator|=
literal|0
expr_stmt|;
name|memset
argument_list|(
name|p
argument_list|,
literal|0
argument_list|,
name|HASH_CBLOCK
argument_list|)
expr_stmt|;
comment|/* keep it zeroed */
block|}
else|else
block|{
name|memcpy
argument_list|(
name|p
operator|+
name|n
argument_list|,
name|data
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|c
operator|->
name|num
operator|+=
operator|(
name|unsigned
name|int
operator|)
name|len
expr_stmt|;
return|return
literal|1
return|;
block|}
block|}
name|n
operator|=
name|len
operator|/
name|HASH_CBLOCK
expr_stmt|;
if|if
condition|(
name|n
operator|>
literal|0
condition|)
block|{
name|HASH_BLOCK_DATA_ORDER
argument_list|(
name|c
argument_list|,
name|data
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|n
operator|*=
name|HASH_CBLOCK
expr_stmt|;
name|data
operator|+=
name|n
expr_stmt|;
name|len
operator|-=
name|n
expr_stmt|;
block|}
if|if
condition|(
name|len
operator|!=
literal|0
condition|)
block|{
name|p
operator|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|c
operator|->
name|data
expr_stmt|;
name|c
operator|->
name|num
operator|=
operator|(
name|unsigned
name|int
operator|)
name|len
expr_stmt|;
name|memcpy
argument_list|(
name|p
argument_list|,
name|data
argument_list|,
name|len
argument_list|)
expr_stmt|;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_function
name|void
name|HASH_TRANSFORM
parameter_list|(
name|HASH_CTX
modifier|*
name|c
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|data
parameter_list|)
block|{
name|HASH_BLOCK_DATA_ORDER
argument_list|(
name|c
argument_list|,
name|data
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|int
name|HASH_FINAL
parameter_list|(
name|unsigned
name|char
modifier|*
name|md
parameter_list|,
name|HASH_CTX
modifier|*
name|c
parameter_list|)
block|{
name|unsigned
name|char
modifier|*
name|p
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|c
operator|->
name|data
decl_stmt|;
name|size_t
name|n
init|=
name|c
operator|->
name|num
decl_stmt|;
name|p
index|[
name|n
index|]
operator|=
literal|0x80
expr_stmt|;
comment|/* there is always room for one */
name|n
operator|++
expr_stmt|;
if|if
condition|(
name|n
operator|>
operator|(
name|HASH_CBLOCK
operator|-
literal|8
operator|)
condition|)
block|{
name|memset
argument_list|(
name|p
operator|+
name|n
argument_list|,
literal|0
argument_list|,
name|HASH_CBLOCK
operator|-
name|n
argument_list|)
expr_stmt|;
name|n
operator|=
literal|0
expr_stmt|;
name|HASH_BLOCK_DATA_ORDER
argument_list|(
name|c
argument_list|,
name|p
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
name|memset
argument_list|(
name|p
operator|+
name|n
argument_list|,
literal|0
argument_list|,
name|HASH_CBLOCK
operator|-
literal|8
operator|-
name|n
argument_list|)
expr_stmt|;
name|p
operator|+=
name|HASH_CBLOCK
operator|-
literal|8
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|DATA_ORDER_IS_BIG_ENDIAN
argument_list|)
operator|(
name|void
operator|)
name|HOST_l2c
argument_list|(
name|c
operator|->
name|Nh
argument_list|,
name|p
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|HOST_l2c
argument_list|(
name|c
operator|->
name|Nl
argument_list|,
name|p
argument_list|)
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|DATA_ORDER_IS_LITTLE_ENDIAN
argument_list|)
operator|(
name|void
operator|)
name|HOST_l2c
argument_list|(
name|c
operator|->
name|Nl
argument_list|,
name|p
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|HOST_l2c
argument_list|(
name|c
operator|->
name|Nh
argument_list|,
name|p
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|p
operator|-=
name|HASH_CBLOCK
expr_stmt|;
name|HASH_BLOCK_DATA_ORDER
argument_list|(
name|c
argument_list|,
name|p
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|c
operator|->
name|num
operator|=
literal|0
expr_stmt|;
name|memset
argument_list|(
name|p
argument_list|,
literal|0
argument_list|,
name|HASH_CBLOCK
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|HASH_MAKE_STRING
error|#
directive|error
literal|"HASH_MAKE_STRING must be defined!"
else|#
directive|else
name|HASH_MAKE_STRING
argument_list|(
name|c
argument_list|,
name|md
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
literal|1
return|;
block|}
end_function

begin_ifndef
ifndef|#
directive|ifndef
name|MD32_REG_T
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__alpha
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparcv9
argument_list|)
operator|||
name|defined
argument_list|(
name|__mips
argument_list|)
end_if

begin_define
define|#
directive|define
name|MD32_REG_T
value|long
end_define

begin_comment
comment|/*  * This comment was originaly written for MD5, which is why it  * discusses A-D. But it basically applies to all 32-bit digests,  * which is why it was moved to common header file.  *  * In case you wonder why A-D are declared as long and not  * as MD5_LONG. Doing so results in slight performance  * boost on LP64 architectures. The catch is we don't  * really care if 32 MSBs of a 64-bit register get polluted  * with eventual overflows as we *save* only 32 LSBs in  * *either* case. Now declaring 'em long excuses the compiler  * from keeping 32 MSBs zeroed resulting in 13% performance  * improvement under SPARC Solaris7/64 and 5% under AlphaLinux.  * Well, to be honest it should say that this *prevents*   * performance degradation.  *<appro@fy.chalmers.se>  */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Above is not absolute and there are LP64 compilers that  * generate better code if MD32_REG_T is defined int. The above  * pre-processor condition reflects the circumstances under which  * the conclusion was made and is subject to further extension.  *<appro@fy.chalmers.se>  */
end_comment

begin_define
define|#
directive|define
name|MD32_REG_T
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

