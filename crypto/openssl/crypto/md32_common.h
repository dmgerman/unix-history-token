begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/md32_common.h */
end_comment

begin_comment
comment|/* ====================================================================  * Copyright (c) 1999 The OpenSSL Project.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.   *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *  * 3. All advertising materials mentioning features or use of this  *    software must display the following acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit. (http://www.OpenSSL.org/)"  *  * 4. The names "OpenSSL Toolkit" and "OpenSSL Project" must not be used to  *    endorse or promote products derived from this software without  *    prior written permission. For written permission, please contact  *    licensing@OpenSSL.org.  *  * 5. Products derived from this software may not be called "OpenSSL"  *    nor may "OpenSSL" appear in their names without prior written  *    permission of the OpenSSL Project.  *  * 6. Redistributions of any form whatsoever must retain the following  *    acknowledgment:  *    "This product includes software developed by the OpenSSL Project  *    for use in the OpenSSL Toolkit (http://www.OpenSSL.org/)"  *  * THIS SOFTWARE IS PROVIDED BY THE OpenSSL PROJECT ``AS IS'' AND ANY  * EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE OpenSSL PROJECT OR  * ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED  * OF THE POSSIBILITY OF SUCH DAMAGE.  * ====================================================================  *  * This product includes cryptographic software written by Eric Young  * (eay@cryptsoft.com).  This product includes software written by Tim  * Hudson (tjh@cryptsoft.com).  *  */
end_comment

begin_comment
comment|/*  * This is a generic 32 bit "collector" for message digest algorithms.  * Whenever needed it collects input character stream into chunks of  * 32 bit values and invokes a block function that performs actual hash  * calculations.  *  * Porting guide.  *  * Obligatory macros:  *  * DATA_ORDER_IS_BIG_ENDIAN or DATA_ORDER_IS_LITTLE_ENDIAN  *	this macro defines byte order of input stream.  * HASH_CBLOCK  *	size of a unit chunk HASH_BLOCK operates on.  * HASH_LONG  *	has to be at lest 32 bit wide, if it's wider, then  *	HASH_LONG_LOG2 *has to* be defined along  * HASH_CTX  *	context structure that at least contains following  *	members:  *		typedef struct {  *			...  *			HASH_LONG	Nl,Nh;  *			HASH_LONG	data[HASH_LBLOCK];  *			int		num;  *			...  *			} HASH_CTX;  * HASH_UPDATE  *	name of "Update" function, implemented here.  * HASH_TRANSFORM  *	name of "Transform" function, implemented here.  * HASH_FINAL  *	name of "Final" function, implemented here.  * HASH_BLOCK_HOST_ORDER  *	name of "block" function treating *aligned* input message  *	in host byte order, implemented externally.  * HASH_BLOCK_DATA_ORDER  *	name of "block" function treating *unaligned* input message  *	in original (data) byte order, implemented externally (it  *	actually is optional if data and host are of the same  *	"endianess").  * HASH_MAKE_STRING  *	macro convering context variables to an ASCII hash string.  *  * Optional macros:  *  * B_ENDIAN or L_ENDIAN  *	defines host byte-order.  * HASH_LONG_LOG2  *	defaults to 2 if not states otherwise.  * HASH_LBLOCK  *	assumed to be HASH_CBLOCK/4 if not stated otherwise.  * HASH_BLOCK_DATA_ORDER_ALIGNED  *	alternative "block" function capable of treating  *	aligned input message in original (data) order,  *	implemented externally.  *  * MD5 example:  *  *	#define DATA_ORDER_IS_LITTLE_ENDIAN  *  *	#define HASH_LONG		MD5_LONG  *	#define HASH_LONG_LOG2		MD5_LONG_LOG2  *	#define HASH_CTX		MD5_CTX  *	#define HASH_CBLOCK		MD5_CBLOCK  *	#define HASH_LBLOCK		MD5_LBLOCK  *	#define HASH_UPDATE		MD5_Update  *	#define HASH_TRANSFORM		MD5_Transform  *	#define HASH_FINAL		MD5_Final  *	#define HASH_BLOCK_HOST_ORDER	md5_block_host_order  *	#define HASH_BLOCK_DATA_ORDER	md5_block_data_order  *  *<appro@fy.chalmers.se>  */
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
name|HASH_BLOCK_HOST_ORDER
end_ifndef

begin_error
error|#
directive|error
literal|"HASH_BLOCK_HOST_ORDER must be defined!"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * Moved below as it's required only if HASH_BLOCK_DATA_ORDER_ALIGNED  * isn't defined.  */
end_comment

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

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_LBLOCK
end_ifndef

begin_define
define|#
directive|define
name|HASH_LBLOCK
value|(HASH_CBLOCK/4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HASH_LONG_LOG2
end_ifndef

begin_define
define|#
directive|define
name|HASH_LONG_LOG2
value|2
end_define

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
name|NO_ASM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_INLINE_ASM
argument_list|)
end_elif

begin_comment
comment|/*    * Some GNU C inline assembler templates. Note that these are    * rotates by *constant* number of bits! But that's exactly    * what we need here...    *    *<appro@fy.chalmers.se>    */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386
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
value|({ register unsigned int ret;	\ 				asm (			\ 				"roll %1,%0"		\ 				: "=r"(ret)		\ 				: "I"(n), "0"(a)	\ 				: "cc");		\ 			   ret;				\ 			})
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc
argument_list|)
operator|||
name|defined
argument_list|(
name|__ppc
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

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Engage compiler specific "fetch in reverse byte order"  * intrinsic function if available.  */
end_comment

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
name|NO_ASM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_INLINE_ASM
argument_list|)
end_if

begin_comment
comment|/* some GNU C inline assembler templates by<appro@fy.chalmers.se> */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|I386_ONLY
argument_list|)
end_if

begin_define
define|#
directive|define
name|BE_FETCH32
parameter_list|(
name|a
parameter_list|)
value|({ register unsigned int l=(a);\ 				asm (			\ 				"bswapl %0"		\ 				: "=r"(l) : "0"(l));	\ 			  l;				\ 			})
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__powerpc
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LE_FETCH32
parameter_list|(
name|a
parameter_list|)
value|({ register unsigned int l;	\ 				asm (			\ 				"lwbrx %0,0,%1"		\ 				: "=r"(l)		\ 				: "r"(a));		\ 			   l;				\ 			})
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__sparc
argument_list|)
operator|&&
name|defined
argument_list|(
name|ULTRASPARC
argument_list|)
end_elif

begin_define
define|#
directive|define
name|LE_FETCH32
parameter_list|(
name|a
parameter_list|)
value|({ register unsigned int l;		\ 				asm (				\ 				"lda [%1]#ASI_PRIMARY_LITTLE,%0"\ 				: "=r"(l)			\ 				: "r"(a));			\ 			   l;					\ 			})
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

begin_if
if|#
directive|if
name|HASH_LONG_LOG2
operator|==
literal|2
end_if

begin_comment
comment|/* Engage only if sizeof(HASH_LONG)== 4 */
end_comment

begin_comment
comment|/* A nice byte order reversal from Wei Dai<weidai@eskimo.com> */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ROTATE
end_ifdef

begin_comment
comment|/* 5 instructions with rotate instruction, else 9 */
end_comment

begin_define
define|#
directive|define
name|REVERSE_FETCH32
parameter_list|(
name|a
parameter_list|,
name|l
parameter_list|)
value|(					\ 		l=*(const HASH_LONG *)(a),				\ 		((ROTATE(l,8)&0x00FF00FF)|(ROTATE((l&0x00FF00FF),24)))	\ 				)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* 6 instructions with rotate instruction, else 8 */
end_comment

begin_define
define|#
directive|define
name|REVERSE_FETCH32
parameter_list|(
name|a
parameter_list|,
name|l
parameter_list|)
value|(				\ 		l=*(const HASH_LONG *)(a),			\ 		l=(((l>>8)&0x00FF00FF)|((l&0x00FF00FF)<<8)),	\ 		ROTATE(l,16)					\ 				)
end_define

begin_comment
comment|/*  * Originally the middle line started with l=(((l&0xFF00FF00)>>8)|...  * It's rewritten as above for two reasons:  *	- RISCs aren't good at long constants and have to explicitely  *	  compose 'em with several (well, usually 2) instructions in a  *	  register before performing the actual operation and (as you  *	  already realized:-) having same constant should inspire the  *	  compiler to permanently allocate the only register for it;  *	- most modern CPUs have two ALUs, but usually only one has  *	  circuitry for shifts:-( this minor tweak inspires compiler  *	  to schedule shift instructions in a better way...  *  *<appro@fy.chalmers.se>  */
end_comment

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

begin_comment
comment|/*  * Make some obvious choices. E.g., HASH_BLOCK_DATA_ORDER_ALIGNED  * and HASH_BLOCK_HOST_ORDER ought to be the same if input data  * and host are of the same "endianess". It's possible to mask  * this with blank #define HASH_BLOCK_DATA_ORDER though...  *  *<appro@fy.chalmers.se>  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|B_ENDIAN
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DATA_ORDER_IS_BIG_ENDIAN
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HASH_BLOCK_DATA_ORDER_ALIGNED
argument_list|)
operator|&&
name|HASH_LONG_LOG2
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|HASH_BLOCK_DATA_ORDER_ALIGNED
value|HASH_BLOCK_HOST_ORDER
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
name|HOST_FETCH32
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|LE_FETCH32
end_ifdef

begin_define
define|#
directive|define
name|HOST_FETCH32
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|LE_FETCH32(p)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|REVERSE_FETCH32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HOST_FETCH32
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|REVERSE_FETCH32(p,l)
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

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|L_ENDIAN
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DATA_ORDER_IS_LITTLE_ENDIAN
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HASH_BLOCK_DATA_ORDER_ALIGNED
argument_list|)
operator|&&
name|HASH_LONG_LOG2
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|HASH_BLOCK_DATA_ORDER_ALIGNED
value|HASH_BLOCK_HOST_ORDER
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
name|DATA_ORDER_IS_BIG_ENDIAN
argument_list|)
end_elif

begin_ifndef
ifndef|#
directive|ifndef
name|HOST_FETCH32
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|BE_FETCH32
end_ifdef

begin_define
define|#
directive|define
name|HOST_FETCH32
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|BE_FETCH32(p)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|REVERSE_FETCH32
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HOST_FETCH32
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|REVERSE_FETCH32(p,l)
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
operator|!
name|defined
argument_list|(
name|HASH_BLOCK_DATA_ORDER_ALIGNED
argument_list|)
end_if

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

begin_define
define|#
directive|define
name|HOST_c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =(((unsigned long)(*((c)++)))<<24),		\ 			 l|=(((unsigned long)(*((c)++)))<<16),		\ 			 l|=(((unsigned long)(*((c)++)))<< 8),		\ 			 l|=(((unsigned long)(*((c)++)))    ),		\ 			 l)
end_define

begin_define
define|#
directive|define
name|HOST_p_c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|)
value|{					\ 			switch (n) {					\ 			case 0: l =((unsigned long)(*((c)++)))<<24;	\ 			case 1: l|=((unsigned long)(*((c)++)))<<16;	\ 			case 2: l|=((unsigned long)(*((c)++)))<< 8;	\ 			case 3: l|=((unsigned long)(*((c)++)));		\ 				} }
end_define

begin_define
define|#
directive|define
name|HOST_p_c2l_p
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|sc
parameter_list|,
name|len
parameter_list|)
value|{					\ 			switch (sc) {					\ 			case 0: l =((unsigned long)(*((c)++)))<<24;	\ 				if (--len == 0) break;			\ 			case 1: l|=((unsigned long)(*((c)++)))<<16;	\ 				if (--len == 0) break;			\ 			case 2: l|=((unsigned long)(*((c)++)))<< 8;	\ 				} }
end_define

begin_comment
comment|/* NOTE the pointer is not incremented at the end of this */
end_comment

begin_define
define|#
directive|define
name|HOST_c2l_p
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|)
value|{					\ 			l=0; (c)+=n;					\ 			switch (n) {					\ 			case 3: l =((unsigned long)(*(--(c))))<< 8;	\ 			case 2: l|=((unsigned long)(*(--(c))))<<16;	\ 			case 1: l|=((unsigned long)(*(--(c))))<<24;	\ 				} }
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
value|(*((c)++)=(unsigned char)(((l)>>24)&0xff),	\ 			 *((c)++)=(unsigned char)(((l)>>16)&0xff),	\ 			 *((c)++)=(unsigned char)(((l)>> 8)&0xff),	\ 			 *((c)++)=(unsigned char)(((l)    )&0xff),	\ 			 l)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|DATA_ORDER_IS_LITTLE_ENDIAN
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HOST_c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =(((unsigned long)(*((c)++)))    ),		\ 			 l|=(((unsigned long)(*((c)++)))<< 8),		\ 			 l|=(((unsigned long)(*((c)++)))<<16),		\ 			 l|=(((unsigned long)(*((c)++)))<<24),		\ 			 l)
end_define

begin_define
define|#
directive|define
name|HOST_p_c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|)
value|{					\ 			switch (n) {					\ 			case 0: l =((unsigned long)(*((c)++)));		\ 			case 1: l|=((unsigned long)(*((c)++)))<< 8;	\ 			case 2: l|=((unsigned long)(*((c)++)))<<16;	\ 			case 3: l|=((unsigned long)(*((c)++)))<<24;	\ 				} }
end_define

begin_define
define|#
directive|define
name|HOST_p_c2l_p
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|sc
parameter_list|,
name|len
parameter_list|)
value|{					\ 			switch (sc) {					\ 			case 0: l =((unsigned long)(*((c)++)));		\ 				if (--len == 0) break;			\ 			case 1: l|=((unsigned long)(*((c)++)))<< 8;	\ 				if (--len == 0) break;			\ 			case 2: l|=((unsigned long)(*((c)++)))<<16;	\ 				} }
end_define

begin_comment
comment|/* NOTE the pointer is not incremented at the end of this */
end_comment

begin_define
define|#
directive|define
name|HOST_c2l_p
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|)
value|{					\ 			l=0; (c)+=n;					\ 			switch (n) {					\ 			case 3: l =((unsigned long)(*(--(c))))<<16;	\ 			case 2: l|=((unsigned long)(*(--(c))))<< 8;	\ 			case 1: l|=((unsigned long)(*(--(c))));		\ 				} }
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
value|(*((c)++)=(unsigned char)(((l)    )&0xff),	\ 			 *((c)++)=(unsigned char)(((l)>> 8)&0xff),	\ 			 *((c)++)=(unsigned char)(((l)>>16)&0xff),	\ 			 *((c)++)=(unsigned char)(((l)>>24)&0xff),	\ 			 l)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Time for some action:-)  */
end_comment

begin_function
name|void
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
name|unsigned
name|long
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
specifier|register
name|HASH_LONG
modifier|*
name|p
decl_stmt|;
specifier|register
name|unsigned
name|long
name|l
decl_stmt|;
name|int
name|sw
decl_stmt|,
name|sc
decl_stmt|,
name|ew
decl_stmt|,
name|ec
decl_stmt|;
if|if
condition|(
name|len
operator|==
literal|0
condition|)
return|return;
name|l
operator|=
operator|(
name|c
operator|->
name|Nl
operator|+
operator|(
name|len
operator|<<
literal|3
operator|)
operator|)
operator|&
literal|0xffffffffL
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
operator|(
name|len
operator|>>
literal|29
operator|)
expr_stmt|;
name|c
operator|->
name|Nl
operator|=
name|l
expr_stmt|;
if|if
condition|(
name|c
operator|->
name|num
operator|!=
literal|0
condition|)
block|{
name|p
operator|=
name|c
operator|->
name|data
expr_stmt|;
name|sw
operator|=
name|c
operator|->
name|num
operator|>>
literal|2
expr_stmt|;
name|sc
operator|=
name|c
operator|->
name|num
operator|&
literal|0x03
expr_stmt|;
if|if
condition|(
operator|(
name|c
operator|->
name|num
operator|+
name|len
operator|)
operator|>=
name|HASH_CBLOCK
condition|)
block|{
name|l
operator|=
name|p
index|[
name|sw
index|]
expr_stmt|;
name|HOST_p_c2l
argument_list|(
name|data
argument_list|,
name|l
argument_list|,
name|sc
argument_list|)
expr_stmt|;
name|p
index|[
name|sw
operator|++
index|]
operator|=
name|l
expr_stmt|;
for|for
control|(
init|;
name|sw
operator|<
name|HASH_LBLOCK
condition|;
name|sw
operator|++
control|)
block|{
name|HOST_c2l
argument_list|(
name|data
argument_list|,
name|l
argument_list|)
expr_stmt|;
name|p
index|[
name|sw
index|]
operator|=
name|l
expr_stmt|;
block|}
name|HASH_BLOCK_HOST_ORDER
argument_list|(
name|c
argument_list|,
name|p
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|len
operator|-=
operator|(
name|HASH_CBLOCK
operator|-
name|c
operator|->
name|num
operator|)
expr_stmt|;
name|c
operator|->
name|num
operator|=
literal|0
expr_stmt|;
comment|/* drop through and do the rest */
block|}
else|else
block|{
name|c
operator|->
name|num
operator|+=
name|len
expr_stmt|;
if|if
condition|(
operator|(
name|sc
operator|+
name|len
operator|)
operator|<
literal|4
condition|)
comment|/* ugly, add char's to a word */
block|{
name|l
operator|=
name|p
index|[
name|sw
index|]
expr_stmt|;
name|HOST_p_c2l_p
argument_list|(
name|data
argument_list|,
name|l
argument_list|,
name|sc
argument_list|,
name|len
argument_list|)
expr_stmt|;
name|p
index|[
name|sw
index|]
operator|=
name|l
expr_stmt|;
block|}
else|else
block|{
name|ew
operator|=
operator|(
name|c
operator|->
name|num
operator|>>
literal|2
operator|)
expr_stmt|;
name|ec
operator|=
operator|(
name|c
operator|->
name|num
operator|&
literal|0x03
operator|)
expr_stmt|;
name|l
operator|=
name|p
index|[
name|sw
index|]
expr_stmt|;
name|HOST_p_c2l
argument_list|(
name|data
argument_list|,
name|l
argument_list|,
name|sc
argument_list|)
expr_stmt|;
name|p
index|[
name|sw
operator|++
index|]
operator|=
name|l
expr_stmt|;
for|for
control|(
init|;
name|sw
operator|<
name|ew
condition|;
name|sw
operator|++
control|)
block|{
name|HOST_c2l
argument_list|(
name|data
argument_list|,
name|l
argument_list|)
expr_stmt|;
name|p
index|[
name|sw
index|]
operator|=
name|l
expr_stmt|;
block|}
if|if
condition|(
name|ec
condition|)
block|{
name|HOST_c2l_p
argument_list|(
name|data
argument_list|,
name|l
argument_list|,
name|ec
argument_list|)
expr_stmt|;
name|p
index|[
name|sw
index|]
operator|=
name|l
expr_stmt|;
block|}
block|}
return|return;
block|}
block|}
name|sw
operator|=
name|len
operator|/
name|HASH_CBLOCK
expr_stmt|;
if|if
condition|(
name|sw
operator|>
literal|0
condition|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|HASH_BLOCK_DATA_ORDER_ALIGNED
argument_list|)
comment|/* 		 * Note that HASH_BLOCK_DATA_ORDER_ALIGNED gets defined 		 * only if sizeof(HASH_LONG)==4. 		 */
if|if
condition|(
operator|(
operator|(
operator|(
name|unsigned
name|long
operator|)
name|data
operator|)
operator|%
literal|4
operator|)
operator|==
literal|0
condition|)
block|{
comment|/* data is properly aligned so that we can cast it: */
name|HASH_BLOCK_DATA_ORDER_ALIGNED
argument_list|(
name|c
argument_list|,
operator|(
name|HASH_LONG
operator|*
operator|)
name|data
argument_list|,
name|sw
argument_list|)
expr_stmt|;
name|sw
operator|*=
name|HASH_CBLOCK
expr_stmt|;
name|data
operator|+=
name|sw
expr_stmt|;
name|len
operator|-=
name|sw
expr_stmt|;
block|}
else|else
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HASH_BLOCK_DATA_ORDER
argument_list|)
while|while
condition|(
name|sw
operator|--
condition|)
block|{
name|memcpy
argument_list|(
name|p
operator|=
name|c
operator|->
name|data
argument_list|,
name|data
argument_list|,
name|HASH_CBLOCK
argument_list|)
expr_stmt|;
name|HASH_BLOCK_DATA_ORDER_ALIGNED
argument_list|(
name|c
argument_list|,
name|p
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|data
operator|+=
name|HASH_CBLOCK
expr_stmt|;
name|len
operator|-=
name|HASH_CBLOCK
expr_stmt|;
block|}
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|HASH_BLOCK_DATA_ORDER
argument_list|)
block|{
name|HASH_BLOCK_DATA_ORDER
argument_list|(
name|c
argument_list|,
name|data
argument_list|,
name|sw
argument_list|)
expr_stmt|;
name|sw
operator|*=
name|HASH_CBLOCK
expr_stmt|;
name|data
operator|+=
name|sw
expr_stmt|;
name|len
operator|-=
name|sw
expr_stmt|;
block|}
endif|#
directive|endif
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
name|c
operator|->
name|data
expr_stmt|;
name|c
operator|->
name|num
operator|=
name|len
expr_stmt|;
name|ew
operator|=
name|len
operator|>>
literal|2
expr_stmt|;
comment|/* words to copy */
name|ec
operator|=
name|len
operator|&
literal|0x03
expr_stmt|;
for|for
control|(
init|;
name|ew
condition|;
name|ew
operator|--
operator|,
name|p
operator|++
control|)
block|{
name|HOST_c2l
argument_list|(
name|data
argument_list|,
name|l
argument_list|)
expr_stmt|;
operator|*
name|p
operator|=
name|l
expr_stmt|;
block|}
name|HOST_c2l_p
argument_list|(
name|data
argument_list|,
name|l
argument_list|,
name|ec
argument_list|)
expr_stmt|;
operator|*
name|p
operator|=
name|l
expr_stmt|;
block|}
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
if|#
directive|if
name|defined
argument_list|(
name|HASH_BLOCK_DATA_ORDER_ALIGNED
argument_list|)
if|if
condition|(
operator|(
operator|(
operator|(
name|unsigned
name|long
operator|)
name|data
operator|)
operator|%
literal|4
operator|)
operator|==
literal|0
condition|)
comment|/* data is properly aligned so that we can cast it: */
name|HASH_BLOCK_DATA_ORDER_ALIGNED
argument_list|(
name|c
argument_list|,
operator|(
name|HASH_LONG
operator|*
operator|)
name|data
argument_list|,
literal|1
argument_list|)
expr_stmt|;
else|else
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HASH_BLOCK_DATA_ORDER
argument_list|)
block|{
name|memcpy
argument_list|(
name|c
operator|->
name|data
argument_list|,
name|data
argument_list|,
name|HASH_CBLOCK
argument_list|)
expr_stmt|;
name|HASH_BLOCK_DATA_ORDER_ALIGNED
argument_list|(
name|c
argument_list|,
name|c
operator|->
name|data
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|HASH_BLOCK_DATA_ORDER
argument_list|)
name|HASH_BLOCK_DATA_ORDER
argument_list|(
name|c
argument_list|,
name|data
argument_list|,
literal|1
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|void
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
specifier|register
name|HASH_LONG
modifier|*
name|p
decl_stmt|;
specifier|register
name|unsigned
name|long
name|l
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
specifier|static
specifier|const
name|unsigned
name|char
name|end
index|[
literal|4
index|]
init|=
block|{
literal|0x80
block|,
literal|0x00
block|,
literal|0x00
block|,
literal|0x00
block|}
decl_stmt|;
specifier|const
name|unsigned
name|char
modifier|*
name|cp
init|=
name|end
decl_stmt|;
comment|/* c->num should definitly have room for at least one more byte. */
name|p
operator|=
name|c
operator|->
name|data
expr_stmt|;
name|i
operator|=
name|c
operator|->
name|num
operator|>>
literal|2
expr_stmt|;
name|j
operator|=
name|c
operator|->
name|num
operator|&
literal|0x03
expr_stmt|;
if|#
directive|if
literal|0
comment|/* purify often complains about the following line as an 	 * Uninitialized Memory Read.  While this can be true, the 	 * following p_c2l macro will reset l when that case is true. 	 * This is because j&0x03 contains the number of 'valid' bytes 	 * already in p[i].  If and only if j&0x03 == 0, the UMR will 	 * occur but this is also the only time p_c2l will do 	 * l= *(cp++) instead of l|= *(cp++) 	 * Many thanks to Alex Tang<altitude@cic.net> for pickup this 	 * 'potential bug' */
ifdef|#
directive|ifdef
name|PURIFY
block|if (j==0) p[i]=0;
comment|/* Yeah, but that's not the way to fix it:-) */
endif|#
directive|endif
block|l=p[i];
else|#
directive|else
name|l
operator|=
operator|(
name|j
operator|==
literal|0
operator|)
condition|?
literal|0
else|:
name|p
index|[
name|i
index|]
expr_stmt|;
endif|#
directive|endif
name|HOST_p_c2l
argument_list|(
name|cp
argument_list|,
name|l
argument_list|,
name|j
argument_list|)
expr_stmt|;
name|p
index|[
name|i
operator|++
index|]
operator|=
name|l
expr_stmt|;
comment|/* i is the next 'undefined word' */
if|if
condition|(
name|i
operator|>
operator|(
name|HASH_LBLOCK
operator|-
literal|2
operator|)
condition|)
comment|/* save room for Nl and Nh */
block|{
if|if
condition|(
name|i
operator|<
name|HASH_LBLOCK
condition|)
name|p
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
name|HASH_BLOCK_HOST_ORDER
argument_list|(
name|c
argument_list|,
name|p
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
block|}
for|for
control|(
init|;
name|i
operator|<
operator|(
name|HASH_LBLOCK
operator|-
literal|2
operator|)
condition|;
name|i
operator|++
control|)
name|p
index|[
name|i
index|]
operator|=
literal|0
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|DATA_ORDER_IS_BIG_ENDIAN
argument_list|)
name|p
index|[
name|HASH_LBLOCK
operator|-
literal|2
index|]
operator|=
name|c
operator|->
name|Nh
expr_stmt|;
name|p
index|[
name|HASH_LBLOCK
operator|-
literal|1
index|]
operator|=
name|c
operator|->
name|Nl
expr_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|DATA_ORDER_IS_LITTLE_ENDIAN
argument_list|)
name|p
index|[
name|HASH_LBLOCK
operator|-
literal|2
index|]
operator|=
name|c
operator|->
name|Nl
expr_stmt|;
name|p
index|[
name|HASH_LBLOCK
operator|-
literal|1
index|]
operator|=
name|c
operator|->
name|Nh
expr_stmt|;
endif|#
directive|endif
name|HASH_BLOCK_HOST_ORDER
argument_list|(
name|c
argument_list|,
name|p
argument_list|,
literal|1
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
name|c
operator|->
name|num
operator|=
literal|0
expr_stmt|;
comment|/* clear stuff, HASH_BLOCK may be leaving some stuff on the stack 	 * but I'm not worried :-) 	memset((void *)c,0,sizeof(HASH_CTX)); 	 */
block|}
end_function

end_unit

