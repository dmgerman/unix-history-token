begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: align.h,v 1.10 1991/04/12 01:03:41 moraes Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ALIGN_H__
end_ifndef

begin_define
define|#
directive|define
name|__ALIGN_H__
end_define

begin_comment
comment|/*   * 'union word' must be aligned to the most pessimistic alignment needed  * on the architecture (See align.h) since all pointers returned by  * malloc and friends are really pointers to a Word. This is the job of  * the 'foo' field in the union, which actually decides the size. (On  * Sun3s, 1 int/long (4 bytes) is good enough, on Sun4s, 8 bytes are  * necessary, i.e. 2 ints/longs)  */
end_comment

begin_comment
comment|/*  * 'union word' should also be the size necessary to ensure that an  * sbrk() immediately following an sbrk(sizeof(union word) * n) returns  * an address one higher than the first sbrk. i.e. contiguous space from  * successive sbrks. (Most sbrks will do this regardless of the size -  * Sun's doesnt) This is not vital - the malloc will work, but will not  * be able to coalesce between sbrk'ed segments.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
operator|||
name|defined
argument_list|(
name|__sparc__
argument_list|)
operator|||
name|defined
argument_list|(
name|__sgi
argument_list|)
end_if

begin_comment
comment|/*  * Sparcs require doubles to be aligned on double word, SGI R4000 based  * machines are 64 bit, this is the conservative way out  */
end_comment

begin_comment
comment|/* this will waste space on R4000s or the 64bit UltraSparc */
end_comment

begin_define
define|#
directive|define
name|ALIGN
value|long foo[2]
end_define

begin_define
define|#
directive|define
name|NALIGN
value|8
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
name|__alpha
argument_list|)
end_if

begin_comment
comment|/* 64 bit */
end_comment

begin_define
define|#
directive|define
name|ALIGN
value|long foo
end_define

begin_define
define|#
directive|define
name|NALIGN
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This default seems to work on most 32bit machines */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ALIGN
end_ifndef

begin_define
define|#
directive|define
name|ALIGN
value|long foo
end_define

begin_define
define|#
directive|define
name|NALIGN
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Align with power of 2 */
end_comment

begin_define
define|#
directive|define
name|SIMPLEALIGN
parameter_list|(
name|X
parameter_list|,
name|N
parameter_list|)
value|(univptr_t)(((size_t)((char *)(X) + (N-1)))& ~(N-1))
end_define

begin_if
if|#
directive|if
name|NALIGN
operator|==
literal|2
operator|||
name|NALIGN
operator|==
literal|4
operator|||
name|NALIGN
operator|==
literal|8
operator|||
name|NALIGN
operator|==
literal|16
end_if

begin_comment
comment|/* if NALIGN is a power of 2, the next line will do ok */
end_comment

begin_define
define|#
directive|define
name|ALIGNPTR
parameter_list|(
name|X
parameter_list|)
value|SIMPLEALIGN(X, NALIGN)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* otherwise we need the generic version; hope the compiler isn't too smart */
end_comment

begin_decl_stmt
specifier|static
name|size_t
name|_N
init|=
name|NALIGN
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ALIGNPTR
parameter_list|(
name|X
parameter_list|)
value|(univptr_t)((((size_t)((univptr_t)(X)+(NALIGN-1)))/_N)*_N)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If your sbrk does not return blocks that are aligned to the  * requirements of malloc(), as specified by ALIGN above, then you need  * to define SBRKEXTRA so that it gets the extra memory needed to find  * an alignment point. Not needed on Suns on which sbrk does return  * properly aligned blocks. But on U*x Vaxen, A/UX and UMIPS at least,  * you need to do this. It is safer to take the non Sun route (!! since  * the non-sun part also works on Suns, maybe we should just remove the  * Sun ifdef)  */
end_comment

begin_if
if|#
directive|if
operator|!
operator|(
name|defined
argument_list|(
name|sun
argument_list|)
operator|||
name|defined
argument_list|(
name|__sun__
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|SBRKEXTRA
value|(sizeof(Word) - 1)
end_define

begin_define
define|#
directive|define
name|SBRKALIGN
parameter_list|(
name|x
parameter_list|)
value|ALIGNPTR(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SBRKEXTRA
value|0
end_define

begin_define
define|#
directive|define
name|SBRKALIGN
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BITSPERBYTE
end_ifndef

begin_comment
comment|/*    * These values should work with any binary representation of integers    * where the high-order bit contains the sign. Should be in values.h,    * but just in case...    */
end_comment

begin_comment
comment|/* a number used normally for size of a shift */
end_comment

begin_if
if|#
directive|if
name|gcos
end_if

begin_define
define|#
directive|define
name|BITSPERBYTE
value|9
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! gcos */
end_comment

begin_define
define|#
directive|define
name|BITSPERBYTE
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* gcos */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BITSPERBYTE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BITS
end_ifndef

begin_define
define|#
directive|define
name|BITS
parameter_list|(
name|type
parameter_list|)
value|(BITSPERBYTE * (int) sizeof(type))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BITS */
end_comment

begin_comment
comment|/* size_t with only the high-order bit turned on */
end_comment

begin_define
define|#
directive|define
name|HIBITSZ
value|(((size_t) 1)<< (BITS(size_t) - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ALIGN_H__ */
end_comment

begin_comment
comment|/* Do not add anything after this line */
end_comment

end_unit

