begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* memcopy.h -- definitions for memory copy functions.  Generic C version.    Copyright (C) 1991, 1992, 1993, 1997, 2004 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Torbjorn Granlund (tege@sics.se).     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_comment
comment|/* The strategy of the memory functions is:       1. Copy bytes until the destination pointer is aligned.       2. Copy words in unrolled loops.  If the source and destination      are not aligned in the same way, use word memory operations,      but shift and merge two read words before writing.       3. Copy the few remaining bytes.     This is fast on processors that have at least 10 registers for    allocation by GCC, and that can access memory at reg+const in one    instruction.     I made an "exhaustive" test of this memmove when I wrote it,    exhaustive in the sense that I tried all alignment and length    combinations, with and without overlap.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<endian.h>
end_include

begin_comment
comment|/* The macros defined in this file are:     BYTE_COPY_FWD(dst_beg_ptr, src_beg_ptr, nbytes_to_copy)     BYTE_COPY_BWD(dst_end_ptr, src_end_ptr, nbytes_to_copy)     WORD_COPY_FWD(dst_beg_ptr, src_beg_ptr, nbytes_remaining, nbytes_to_copy)     WORD_COPY_BWD(dst_end_ptr, src_end_ptr, nbytes_remaining, nbytes_to_copy)     MERGE(old_word, sh_1, new_word, sh_2)      [I fail to understand.  I feel stupid.  --roland] */
end_comment

begin_comment
comment|/* Type to use for aligned memory operations.    This should normally be the biggest type supported by a single load    and store.  */
end_comment

begin_define
define|#
directive|define
name|op_t
value|unsigned long int
end_define

begin_define
define|#
directive|define
name|OPSIZ
value|(sizeof(op_t))
end_define

begin_comment
comment|/* Type to use for unaligned operations.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|byte
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__LITTLE_ENDIAN
end_if

begin_define
define|#
directive|define
name|MERGE
parameter_list|(
name|w0
parameter_list|,
name|sh_1
parameter_list|,
name|w1
parameter_list|,
name|sh_2
parameter_list|)
value|(((w0)>> (sh_1)) | ((w1)<< (sh_2)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__BYTE_ORDER
operator|==
name|__BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|MERGE
parameter_list|(
name|w0
parameter_list|,
name|sh_1
parameter_list|,
name|w1
parameter_list|,
name|sh_2
parameter_list|)
value|(((w0)<< (sh_1)) | ((w1)>> (sh_2)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Copy exactly NBYTES bytes from SRC_BP to DST_BP,    without any assumptions about alignment of the pointers.  */
end_comment

begin_define
define|#
directive|define
name|BYTE_COPY_FWD
parameter_list|(
name|dst_bp
parameter_list|,
name|src_bp
parameter_list|,
name|nbytes
parameter_list|)
define|\
value|do									      \     {									      \       size_t __nbytes = (nbytes);					      \       while (__nbytes> 0)						      \ 	{								      \ 	  byte __x = ((byte *) src_bp)[0];				      \ 	  src_bp += 1;							      \ 	  __nbytes -= 1;						      \ 	  ((byte *) dst_bp)[0] = __x;					      \ 	  dst_bp += 1;							      \ 	}								      \     } while (0)
end_define

begin_comment
comment|/* Copy exactly NBYTES_TO_COPY bytes from SRC_END_PTR to DST_END_PTR,    beginning at the bytes right before the pointers and continuing towards    smaller addresses.  Don't assume anything about alignment of the    pointers.  */
end_comment

begin_define
define|#
directive|define
name|BYTE_COPY_BWD
parameter_list|(
name|dst_ep
parameter_list|,
name|src_ep
parameter_list|,
name|nbytes
parameter_list|)
define|\
value|do									      \     {									      \       size_t __nbytes = (nbytes);					      \       while (__nbytes> 0)						      \ 	{								      \ 	  byte __x;							      \ 	  src_ep -= 1;							      \ 	  __x = ((byte *) src_ep)[0];					      \ 	  dst_ep -= 1;							      \ 	  __nbytes -= 1;						      \ 	  ((byte *) dst_ep)[0] = __x;					      \ 	}								      \     } while (0)
end_define

begin_comment
comment|/* Copy *up to* NBYTES bytes from SRC_BP to DST_BP, with    the assumption that DST_BP is aligned on an OPSIZ multiple.  If    not all bytes could be easily copied, store remaining number of bytes    in NBYTES_LEFT, otherwise store 0.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_wordcopy_fwd_aligned
argument_list|(
name|long
name|int
argument_list|,
name|long
name|int
argument_list|,
name|size_t
argument_list|)
name|__THROW
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_wordcopy_fwd_dest_aligned
argument_list|(
name|long
name|int
argument_list|,
name|long
name|int
argument_list|,
name|size_t
argument_list|)
name|__THROW
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|WORD_COPY_FWD
parameter_list|(
name|dst_bp
parameter_list|,
name|src_bp
parameter_list|,
name|nbytes_left
parameter_list|,
name|nbytes
parameter_list|)
define|\
value|do									      \     {									      \       if (src_bp % OPSIZ == 0)						      \ 	_wordcopy_fwd_aligned (dst_bp, src_bp, (nbytes) / OPSIZ);	      \       else								      \ 	_wordcopy_fwd_dest_aligned (dst_bp, src_bp, (nbytes) / OPSIZ);	      \       src_bp += (nbytes)& -OPSIZ;					      \       dst_bp += (nbytes)& -OPSIZ;					      \       (nbytes_left) = (nbytes) % OPSIZ;					      \     } while (0)
end_define

begin_comment
comment|/* Copy *up to* NBYTES_TO_COPY bytes from SRC_END_PTR to DST_END_PTR,    beginning at the words (of type op_t) right before the pointers and    continuing towards smaller addresses.  May take advantage of that    DST_END_PTR is aligned on an OPSIZ multiple.  If not all bytes could be    easily copied, store remaining number of bytes in NBYTES_REMAINING,    otherwise store 0.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|_wordcopy_bwd_aligned
argument_list|(
name|long
name|int
argument_list|,
name|long
name|int
argument_list|,
name|size_t
argument_list|)
name|__THROW
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|_wordcopy_bwd_dest_aligned
argument_list|(
name|long
name|int
argument_list|,
name|long
name|int
argument_list|,
name|size_t
argument_list|)
name|__THROW
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|WORD_COPY_BWD
parameter_list|(
name|dst_ep
parameter_list|,
name|src_ep
parameter_list|,
name|nbytes_left
parameter_list|,
name|nbytes
parameter_list|)
define|\
value|do									      \     {									      \       if (src_ep % OPSIZ == 0)						      \ 	_wordcopy_bwd_aligned (dst_ep, src_ep, (nbytes) / OPSIZ);	      \       else								      \ 	_wordcopy_bwd_dest_aligned (dst_ep, src_ep, (nbytes) / OPSIZ);	      \       src_ep -= (nbytes)& -OPSIZ;					      \       dst_ep -= (nbytes)& -OPSIZ;					      \       (nbytes_left) = (nbytes) % OPSIZ;					      \     } while (0)
end_define

begin_comment
comment|/* Threshold value for when to enter the unrolled loops.  */
end_comment

begin_define
define|#
directive|define
name|OP_T_THRES
value|16
end_define

end_unit

