begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|LIBC_SCCS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|lint
argument_list|)
end_if

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)heapsort.c	5.1 (Berkeley) 6/4/91"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LIBC_SCCS and not lint */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/*  * Swap two areas of size number of bytes.  Although qsort(3) permits random  * blocks of memory to be sorted, sorting pointers is almost certainly the  * common case (and, were it not, could easily be made so).  Regardless, it  * isn't worth optimizing; the SWAP's get sped up by the cache, and pointer  * arithmetic gets lost in the time required for comparison function calls.  */
end_comment

begin_define
define|#
directive|define
name|SWAP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{ \ 	cnt = size; \ 	do { \ 		ch = *a; \ 		*a++ = *b; \ 		*b++ = ch; \ 	} while (--cnt); \ }
end_define

begin_comment
comment|/*  * Build the list into a heap, where a heap is defined such that for  * the records K1 ... KN, Kj/2>= Kj for 1<= j/2<= j<= N.  *  * There two cases.  If j == nmemb, select largest of Ki and Kj.  If  * j< nmemb, select largest of Ki, Kj and Kj+1.  *  * The initial value depends on if we're building the initial heap or  * reconstructing it after saving a value.  */
end_comment

begin_define
define|#
directive|define
name|HEAP
parameter_list|(
name|initval
parameter_list|)
value|{ \ 	for (i = initval; (j = i * 2)<= nmemb; i = j) { \ 		p = (char *)bot + j * size; \ 		if (j< nmemb&& compar(p, p + size)< 0) { \ 			p += size; \ 			++j; \ 		} \ 		t = (char *)bot + i * size; \ 		if (compar(p, t)<= 0) \ 			break; \ 		SWAP(t, p); \ 	} \ }
end_define

begin_comment
comment|/*  * Heapsort -- Knuth, Vol. 3, page 145.  Runs in O (N lg N), both average  * and worst.  While heapsort is faster than the worst case of quicksort,  * the BSD quicksort does median selection so that the chance of finding  * a data set that will trigger the worst case is nonexistent.  Heapsort's  * only advantage over quicksort is that it requires no additional memory.  */
end_comment

begin_expr_stmt
name|heapsort
argument_list|(
name|bot
argument_list|,
name|nmemb
argument_list|,
name|size
argument_list|,
name|compar
argument_list|)
specifier|register
name|void
operator|*
name|bot
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|size_t
name|nmemb
decl_stmt|,
name|size
decl_stmt|;
end_decl_stmt

begin_macro
name|int
argument_list|(
argument|*compar
argument_list|)
end_macro

begin_expr_stmt
name|__P
argument_list|(
operator|(
specifier|const
name|void
operator|*
operator|,
specifier|const
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|p
decl_stmt|,
modifier|*
name|t
decl_stmt|,
name|ch
decl_stmt|;
specifier|register
name|int
name|cnt
decl_stmt|,
name|i
decl_stmt|,
name|j
decl_stmt|,
name|l
decl_stmt|;
if|if
condition|(
name|nmemb
operator|<=
literal|1
condition|)
return|return
operator|(
literal|0
operator|)
return|;
if|if
condition|(
operator|!
name|size
condition|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* 	 * Items are numbered from 1 to nmemb, so offset from size bytes 	 * below the starting address. 	 */
name|bot
operator|-=
name|size
expr_stmt|;
for|for
control|(
name|l
operator|=
name|nmemb
operator|/
literal|2
operator|+
literal|1
init|;
operator|--
name|l
condition|;
control|)
name|HEAP
argument_list|(
name|l
argument_list|)
expr_stmt|;
comment|/* 	 * For each element of the heap, save the largest element into its 	 * final slot, then recreate the heap. 	 */
while|while
condition|(
name|nmemb
operator|>
literal|1
condition|)
block|{
name|p
operator|=
operator|(
name|char
operator|*
operator|)
name|bot
operator|+
name|size
expr_stmt|;
name|t
operator|=
operator|(
name|char
operator|*
operator|)
name|bot
operator|+
name|nmemb
operator|*
name|size
expr_stmt|;
name|SWAP
argument_list|(
name|p
argument_list|,
name|t
argument_list|)
expr_stmt|;
operator|--
name|nmemb
expr_stmt|;
name|HEAP
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

end_unit

