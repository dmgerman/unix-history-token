begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Author: Mark Moraes<moraes@csri.toronto.edu> */
end_comment

begin_comment
comment|/* $Id: defs.h,v 1.24 1993/05/23 05:10:52 moraes Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DEFS_H__
end_ifndef

begin_define
define|#
directive|define
name|__DEFS_H__
end_define

begin_comment
comment|/*   *  This file includes all relevant include files, and defines various  *  types and constants. It also defines lots of macros which operate on  *  the malloc blocks and pointers, to try and keep the ugliness  *  abstracted away from the source code.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Some errno.h don't declare this */
end_comment

begin_comment
comment|/*   *  ANSI defines malloc to return void *, and take size_t as an  *  argument, while present Unix convention is char * and unsigned int  *  respectively. This is not ifdef'ed with STDC because you may want to  *  compile a Unix malloc with an ANSI C compiler or vice versa. Note  *  that sys/types.h on BSD Unix systems defines size_t to be int or  *  long. memsize_t is for routines that expect int in Unix and size_t  *  in ANSI.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|STDHEADERS
end_ifdef

begin_define
define|#
directive|define
name|univptr_t
value|void *
end_define

begin_define
define|#
directive|define
name|memsize_t
value|size_t
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! STDHEADERS */
end_comment

begin_define
define|#
directive|define
name|univptr_t
value|char *
end_define

begin_define
define|#
directive|define
name|size_t
value|unsigned int
end_define

begin_define
define|#
directive|define
name|memsize_t
value|int
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* STDHEADERS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGISTER
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_comment
comment|/* gcc probably does better register allocation than I do */
end_comment

begin_define
define|#
directive|define
name|REGISTER
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REGISTER
value|register
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
comment|/*  *  Just in case you want an ANSI malloc without an ANSI compiler, or  *  ANSI includes  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STDHEADERS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|offsetof
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
end_if

begin_define
define|#
directive|define
name|size_t
value|unsigned long
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
name|__STDC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|proto
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|proto
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"externs.h"
end_include

begin_include
include|#
directive|include
file|"assert.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_FAILURE
end_ifndef

begin_define
define|#
directive|define
name|EXIT_FAILURE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|BITSPERBYTE
end_ifndef

begin_define
define|#
directive|define
name|BITSPERBYTE
value|CHAR_BIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<values.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"align.h"
end_include

begin_comment
comment|/* Needs BITSPERBYTE */
end_comment

begin_comment
comment|/*   *  We assume that FREE is a 0 bit, and the for a free block,  *  SIZE(p) == SIZEMASK(p) as an optimization to avoid an unnecessary  *  masking operation with SIZEMASK. See FREESIZE below. Or'ing with  *  ALLOCED should turn on the high bit, And'ing with SIZEMASK should  *  turn it off.  */
end_comment

begin_define
define|#
directive|define
name|FREE
value|((size_t) 0)
end_define

begin_define
define|#
directive|define
name|ALLOCED
value|(HIBITSZ)
end_define

begin_define
define|#
directive|define
name|SIZEMASK
value|(~HIBITSZ)
end_define

begin_union
union|union
name|word
block|{
comment|/* basic unit of storage */
name|size_t
name|size
decl_stmt|;
comment|/* size of this block + 1 bit status */
name|union
name|word
modifier|*
name|next
decl_stmt|;
comment|/* next free block */
name|union
name|word
modifier|*
name|prev
decl_stmt|;
comment|/* prev free block */
name|univptr_t
name|ptr
decl_stmt|;
comment|/* stops lint complaining, keeps alignment */
name|char
name|c
decl_stmt|;
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
name|char
modifier|*
modifier|*
name|cpp
decl_stmt|;
name|int
modifier|*
name|ip
decl_stmt|;
name|int
modifier|*
modifier|*
name|ipp
decl_stmt|;
name|ALIGN
expr_stmt|;
comment|/* alignment stuff - wild fun */
block|}
union|;
end_union

begin_typedef
typedef|typedef
name|union
name|word
name|Word
typedef|;
end_typedef

begin_comment
comment|/*  *  WARNING - Many of these macros are UNSAFE because they have multiple  *  evaluations of the arguments. Use with care, avoid side-effects.  */
end_comment

begin_comment
comment|/*  * These macros define operations on a pointer to a block. The zero'th  * word of a block is the size field, where the top bit is 1 if the  * block is allocated. This word is also referred to as the starting tag.  * The last word of the block is identical to the zero'th word of the  * block and is the end tag.  IF the block is free, the second last word  * is a pointer to the next block in the free list (a doubly linked list  * of all free blocks in the heap), and the third from last word is a  * pointer to the previous block in the free list.  HEADERWORDS is the  * number of words before the pointer in the block that malloc returns,  * TRAILERWORDS is the number of words after the returned block. Note  * that the zero'th and the last word MUST be the boundary tags - this  * is hard-wired into the algorithm. Increasing HEADERWORDS or  * TRAILERWORDS suitably should be accompanied by additional macros to  * operate on those words. The routines most likely to be affected are  * malloc/realloc/free/memalign/mal_verify/mal_heapdump.  */
end_comment

begin_comment
comment|/*  * There are two ways we can refer to a block -- by pointing at the  * start tag, or by pointing at the end tag. For reasons of efficiency  * and performance, free blocks are always referred to by the end tag,  * while allocated blocks are usually referred to by the start tag.  * Accordingly, the following macros indicate the type of their argument  * by using either 'p', 'sp', or 'ep' to indicate a pointer. 'p' means  * the pointer could point at either the start or end tag. 'sp' means it  * must point at a start tag for that macro to work correctly, 'ep'  * means it must point at the end tag. Usually, macros operating on free  * blocks (NEXT, PREV, VALID_PREV_PTR, VALID_NEXT_PTR) take 'ep', while  * macros operating on allocated blocks (REALSIZE, MAGIC_PTR,  * SET_REALSIZE) take 'sp'. The size field may be validated using either  * VALID_START_SIZE_FIELD for an 'sp' or VALID_END_SIZE_FIELD for an  * 'ep'.  */
end_comment

begin_comment
comment|/*  *  SIZE, SIZEFIELD and TAG are valid for allocated and free blocks,  *  REALSIZE is valid for allocated blocks when debugging, and NEXT and  *  PREV are valid for free blocks. We could speed things up by making  *  the free list singly linked when not debugging - the double link are  *  just so we can check for pointer validity. (PREV(NEXT(ep)) == ep and  *  NEXT(PREV(ep)) == ep). FREESIZE is used only to get the size field  *  from FREE blocks - in this implementation, free blocks have a tag  *  bit of 0 so no masking is necessary to operate on the SIZEFIELD when  *  a block is free. We take advantage of that as a minor optimization.  */
end_comment

begin_define
define|#
directive|define
name|SIZEFIELD
parameter_list|(
name|p
parameter_list|)
value|((p)->size)
end_define

begin_define
define|#
directive|define
name|SIZE
parameter_list|(
name|p
parameter_list|)
value|((size_t) (SIZEFIELD(p)& SIZEMASK))
end_define

begin_define
define|#
directive|define
name|ALLOCMASK
parameter_list|(
name|n
parameter_list|)
value|((n) | ALLOCED)
end_define

begin_define
define|#
directive|define
name|FREESIZE
parameter_list|(
name|p
parameter_list|)
value|SIZEFIELD(p)
end_define

begin_comment
comment|/*  *  FREEMASK should be (n)& SIZEMASK, but since (n) will always have  *  the hi bit off after the conversion from bytes requested by the user  *  to words.  */
end_comment

begin_define
define|#
directive|define
name|FREEMASK
parameter_list|(
name|n
parameter_list|)
value|(n)
end_define

begin_define
define|#
directive|define
name|TAG
parameter_list|(
name|p
parameter_list|)
value|(SIZEFIELD(p)& ~SIZEMASK)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|REALSIZE
parameter_list|(
name|sp
parameter_list|)
value|(((sp)+1)->size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_define
define|#
directive|define
name|NEXT
parameter_list|(
name|ep
parameter_list|)
value|(((ep)-1)->next)
end_define

begin_define
define|#
directive|define
name|PREV
parameter_list|(
name|ep
parameter_list|)
value|(((ep)-2)->prev)
end_define

begin_comment
comment|/*  *  HEADERWORDS is the real block header in an allocated block - the  *  free block header uses extra words in the block itself  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|HEADERWORDS
value|2
end_define

begin_comment
comment|/* Start boundary tag + real size in bytes */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! DEBUG */
end_comment

begin_define
define|#
directive|define
name|HEADERWORDS
value|1
end_define

begin_comment
comment|/* Start boundary tag */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_define
define|#
directive|define
name|TRAILERWORDS
value|1
end_define

begin_define
define|#
directive|define
name|FREEHEADERWORDS
value|1
end_define

begin_comment
comment|/* Start boundary tag */
end_comment

begin_define
define|#
directive|define
name|FREETRAILERWORDS
value|3
end_define

begin_comment
comment|/* next and prev, end boundary tag */
end_comment

begin_define
define|#
directive|define
name|ALLOC_OVERHEAD
value|(HEADERWORDS + TRAILERWORDS)
end_define

begin_define
define|#
directive|define
name|FREE_OVERHEAD
value|(FREEHEADERWORDS + FREETRAILERWORDS)
end_define

begin_comment
comment|/*  *  The allocator views memory as a list of non-contiguous arenas. (If  *  successive sbrks() return contiguous blocks, they are colaesced into  *  one arena - if a program never calls sbrk() other than malloc(),  *  then there should only be one arena. This malloc will however  *  happily coexist with other allocators calling sbrk() and uses only  *  the blocks given to it by sbrk. It expects the same courtesy from  *  other allocators. The arenas are chained into a linked list using  *  the first word of each block as a pointer to the next arena. The  *  second word of the arena, and the last word, contain fake boundary  *  tags that are permanantly marked allocated, so that no attempt is  *  made to coalesce past them. See the code in dumpheap for more info.  */
end_comment

begin_define
define|#
directive|define
name|ARENASTART
value|2
end_define

begin_comment
comment|/* next ptr + fake start tag */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/*     * 1 for prev link in free block - next link is absorbed by header    * REALSIZE word    */
end_comment

begin_define
define|#
directive|define
name|FIXEDOVERHEAD
value|(1 + ALLOC_OVERHEAD)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! DEBUG */
end_comment

begin_comment
comment|/* 1 for prev link, 1 for next link, + header and trailer */
end_comment

begin_define
define|#
directive|define
name|FIXEDOVERHEAD
value|(2 + ALLOC_OVERHEAD)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_comment
comment|/*   * Check that pointer is safe to dereference i.e. actually points  * somewhere within the heap and is properly aligned.  */
end_comment

begin_define
define|#
directive|define
name|PTR_IN_HEAP
parameter_list|(
name|p
parameter_list|)
define|\
value|((p)> _malloc_loword&& (p)< _malloc_hiword&& \ 	 ALIGNPTR(p) == ((univptr_t) (p)))
end_define

begin_comment
comment|/* Check that the size field is valid */
end_comment

begin_define
define|#
directive|define
name|VALID_START_SIZE_FIELD
parameter_list|(
name|sp
parameter_list|)
define|\
value|(PTR_IN_HEAP((sp) + SIZE(sp) - 1)&& \ 	 SIZEFIELD(sp) == SIZEFIELD((sp) + SIZE(sp) - 1))
end_define

begin_define
define|#
directive|define
name|VALID_END_SIZE_FIELD
parameter_list|(
name|ep
parameter_list|)
define|\
value|(PTR_IN_HEAP((ep) - SIZE(ep) + 1)&& \ 	 SIZEFIELD(ep) == SIZEFIELD((ep) - SIZE(ep) + 1))
end_define

begin_define
define|#
directive|define
name|ulong
value|unsigned long
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_comment
comment|/*     * Byte that is stored at the end of each block if the requested size    * of the block is not a multiple of sizeof(Word). (If it is a multiple    * of sizeof(Word), then we don't need to put the magic because the    * endboundary tag will be corrupted and the tests that check the    * validity of the boundary tag should detect it    */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|u_char
end_ifndef

begin_define
define|#
directive|define
name|u_char
value|unsigned char
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* u_char */
end_comment

begin_define
define|#
directive|define
name|MAGIC_BYTE
value|((u_char) '\252')
end_define

begin_comment
comment|/*     * Check if size of the block is identical to requested size. Typical    * tests will be of the form DONT_NEED_MAGIC(p) || something for    * short-circuited protection, because blocks where DONT_NEED_MAGIC is    * true will be tested for boundary tag detection so we don't need the    * magic byte at the end.    */
end_comment

begin_define
define|#
directive|define
name|DONT_NEED_MAGIC
parameter_list|(
name|sp
parameter_list|)
define|\
value|(REALSIZE(sp) == ((SIZE(sp) - ALLOC_OVERHEAD) * sizeof(Word)))
end_define

begin_comment
comment|/* Note that VALID_REALSIZE must not be used if DONT_NEED_MAGIC is true */
end_comment

begin_define
define|#
directive|define
name|VALID_REALSIZE
parameter_list|(
name|sp
parameter_list|)
define|\
value|(REALSIZE(sp)< ((SIZE(sp) - ALLOC_OVERHEAD)*sizeof(Word)))
end_define

begin_comment
comment|/* Location of the magic byte */
end_comment

begin_define
define|#
directive|define
name|MAGIC_PTR
parameter_list|(
name|sp
parameter_list|)
value|((u_char *)((sp) + HEADERWORDS) + REALSIZE(sp))
end_define

begin_comment
comment|/*    * malloc code should only use the next two macros SET_REALSIZE and    * VALID_MAGIC, since they are the only ones which have non-DEBUG    * (null) alternatives    */
end_comment

begin_comment
comment|/* Macro sets the realsize of a block if necessary */
end_comment

begin_define
define|#
directive|define
name|SET_REALSIZE
parameter_list|(
name|sp
parameter_list|,
name|n
parameter_list|)
define|\
value|(REALSIZE(sp) = (n), \ 	 DONT_NEED_MAGIC(sp) || (*MAGIC_PTR(sp) = MAGIC_BYTE))
end_define

begin_comment
comment|/* Macro tests that the magic byte is valid if it exists */
end_comment

begin_define
define|#
directive|define
name|VALID_MAGIC
parameter_list|(
name|sp
parameter_list|)
define|\
value|(DONT_NEED_MAGIC(sp) || \ 	 (VALID_REALSIZE(sp)&& (*MAGIC_PTR(sp) == MAGIC_BYTE)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! DEBUG */
end_comment

begin_define
define|#
directive|define
name|SET_REALSIZE
parameter_list|(
name|sp
parameter_list|,
name|n
parameter_list|)
end_define

begin_define
define|#
directive|define
name|VALID_MAGIC
parameter_list|(
name|sp
parameter_list|)
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEBUG */
end_comment

begin_comment
comment|/*   *  Check that a free list ptr points to a block with something pointing  *  back. This is the only reason we use a doubly linked free list.  */
end_comment

begin_define
define|#
directive|define
name|VALID_NEXT_PTR
parameter_list|(
name|ep
parameter_list|)
value|(PTR_IN_HEAP(NEXT(ep))&& PREV(NEXT(ep)) == (ep))
end_define

begin_define
define|#
directive|define
name|VALID_PREV_PTR
parameter_list|(
name|ep
parameter_list|)
value|(PTR_IN_HEAP(PREV(ep))&& NEXT(PREV(ep)) == (ep))
end_define

begin_comment
comment|/*  *  quick bit-arithmetic to check a number (including 1) is a power of two.  */
end_comment

begin_define
define|#
directive|define
name|is_power_of_2
parameter_list|(
name|x
parameter_list|)
value|((((x) - 1)& (x)) == 0)
end_define

begin_comment
comment|/*  *  An array to try and keep track of the distribution of sizes of  *  malloc'ed blocks  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROFILESIZES
end_ifdef

begin_define
define|#
directive|define
name|MAXPROFILESIZE
value|2*1024
end_define

begin_define
define|#
directive|define
name|COUNTSIZE
parameter_list|(
name|nw
parameter_list|)
value|(_malloc_scount[((nw)< MAXPROFILESIZE) ? (nw) : 0]++)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|COUNTSIZE
parameter_list|(
name|nw
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DEF_SBRKUNITS
value|1024
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|USESTDIO
end_ifndef

begin_comment
comment|/*     * Much better not to use stdio - stdio calls malloc() and can    * therefore cause problems when debugging heap corruption. However,    * there's no guaranteed way to turn off buffering on a FILE pointer in    * ANSI.  This is a vile kludge!    */
end_comment

begin_define
define|#
directive|define
name|fputs
parameter_list|(
name|s
parameter_list|,
name|f
parameter_list|)
value|write(fileno(f), (s), strlen(s))
end_define

begin_define
define|#
directive|define
name|setvbuf
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|,
name|n
parameter_list|,
name|l
parameter_list|)
value|__nothing()
end_define

begin_define
define|#
directive|define
name|fflush
parameter_list|(
name|f
parameter_list|)
value|__nothing()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* USESTDIO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRACE
end_ifdef

begin_comment
comment|/*     * Prints a trace string. For convenience, x is an    * sprintf(_malloc_statsbuf, ...) or strcpy(_malloc_statsbuf, ...);    * something which puts the appropriate text to be printed in    * _malloc_statsbuf - ugly, but more convenient than making x a string.    */
end_comment

begin_define
define|#
directive|define
name|PRTRACE
parameter_list|(
name|x
parameter_list|)
define|\
value|if (_malloc_tracing) { \ 	(void) x; \ 	(void) fputs(_malloc_statsbuf, _malloc_statsfile); \   } else \ 	_malloc_tracing += 0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PRTRACE
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|CHECKHEAP
parameter_list|()
define|\
value|if (_malloc_debugging>= 2) \ 	(void) mal_verify(_malloc_debugging>= 3); \   else \ 	_malloc_debugging += 0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CHECKHEAP
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FREEMAGIC
value|'\125'
end_define

begin_comment
comment|/*  *  Memory functions but in words. We just call memset/memcpy, and hope  *  that someone has optimized them. If you are on pure 4.2BSD, either  *  redefine these in terms of bcopy/your own memcpy, or  *  get the functions from one of 4.3src/Henry Spencer's strings  *  package/C News src  */
end_comment

begin_define
define|#
directive|define
name|MEMSET
parameter_list|(
name|p
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
define|\
value|(void) memset((univptr_t) (p), (c), (memsize_t) ((n) * sizeof(Word)))
end_define

begin_define
define|#
directive|define
name|MEMCPY
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|,
name|n
parameter_list|)
define|\
value|(void) memcpy((univptr_t) (p1), (univptr_t) (p2), \ 				  (memsize_t) ((n) * sizeof(Word)))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEBUG
end_ifdef

begin_define
define|#
directive|define
name|DMEMSET
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
value|MEMSET((p), FREEMAGIC, (n))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DMEMSET
parameter_list|(
name|p
parameter_list|,
name|n
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*   *  Thanks to Hugh Redelmeier for pointing out that an rcsid is "a  *  variable accessed in a way not obvious to the compiler", so should  *  be called volatile. Amazing - a use for const volatile...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|RCSID
end_ifndef

begin_comment
comment|/* define RCSID(x) to nothing if don't want the rcs headers */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|x
parameter_list|)
value|static const volatile char *rcsid = x ;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RCSID
parameter_list|(
name|x
parameter_list|)
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
comment|/* __DEFS_H__ */
end_comment

begin_comment
comment|/* Do not add anything after this line */
end_comment

end_unit

