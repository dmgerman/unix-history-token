begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$KAME: des_locl.h,v 1.6 2000/11/06 13:58:09 itojun Exp $	*/
end_comment

begin_comment
comment|/* lib/des/des_locl.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1996 Eric Young (eay@mincom.oz.au)  * All rights reserved.  *  * This file is part of an SSL implementation written  * by Eric Young (eay@mincom.oz.au).  * The implementation was written so as to conform with Netscapes SSL  * specification.  This library and applications are  * FREE FOR COMMERCIAL AND NON-COMMERCIAL USE  * as long as the following conditions are aheared to.  *  * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  If this code is used in a product,  * Eric Young should be given attribution as the author of the parts used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Eric Young (eay@mincom.oz.au)  *  * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_comment
comment|/* WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING  *  * Always modify des_locl.org since des_locl.h is automatically generated from  * it during SSLeay configuration.  *  * WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEADER_DES_LOCL_H
end_ifndef

begin_define
define|#
directive|define
name|HEADER_DES_LOCL_H
end_define

begin_include
include|#
directive|include
file|<crypto/des/des.h>
end_include

begin_undef
undef|#
directive|undef
name|DES_PTR
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_undef
undef|#
directive|undef
name|NOPROTO
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ITERATIONS
value|16
end_define

begin_define
define|#
directive|define
name|HALF_ITERATIONS
value|8
end_define

begin_comment
comment|/* used in des_read and des_write */
end_comment

begin_define
define|#
directive|define
name|MAXWRITE
value|(1024*16)
end_define

begin_define
define|#
directive|define
name|BSIZE
value|(MAXWRITE+4)
end_define

begin_define
define|#
directive|define
name|c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =((DES_LONG)(*((c)++)))    , \ 			 l|=((DES_LONG)(*((c)++)))<< 8L, \ 			 l|=((DES_LONG)(*((c)++)))<<16L, \ 			 l|=((DES_LONG)(*((c)++)))<<24L)
end_define

begin_comment
comment|/* NOTE - c is not incremented as per c2l */
end_comment

begin_define
define|#
directive|define
name|c2ln
parameter_list|(
name|c
parameter_list|,
name|l1
parameter_list|,
name|l2
parameter_list|,
name|n
parameter_list|)
value|{ \ 			c+=n; \ 			l1=l2=0; \ 			switch (n) { \ 			case 8: l2 =((DES_LONG)(*(--(c))))<<24L; \ 			case 7: l2|=((DES_LONG)(*(--(c))))<<16L; \ 			case 6: l2|=((DES_LONG)(*(--(c))))<< 8L; \ 			case 5: l2|=((DES_LONG)(*(--(c))));     \ 			case 4: l1 =((DES_LONG)(*(--(c))))<<24L; \ 			case 3: l1|=((DES_LONG)(*(--(c))))<<16L; \ 			case 2: l1|=((DES_LONG)(*(--(c))))<< 8L; \ 			case 1: l1|=((DES_LONG)(*(--(c))));     \ 				} \ 			}
end_define

begin_define
define|#
directive|define
name|l2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)     )&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>16L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>24L)&0xff))
end_define

begin_comment
comment|/* replacements for htonl and ntohl since I have no idea what to do  * when faced with machines with 8 byte longs. */
end_comment

begin_define
define|#
directive|define
name|HDRSIZE
value|4
end_define

begin_define
define|#
directive|define
name|n2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =((DES_LONG)(*((c)++)))<<24L, \ 			 l|=((DES_LONG)(*((c)++)))<<16L, \ 			 l|=((DES_LONG)(*((c)++)))<< 8L, \ 			 l|=((DES_LONG)(*((c)++))))
end_define

begin_define
define|#
directive|define
name|l2n
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)>>24L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>16L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)     )&0xff))
end_define

begin_comment
comment|/* NOTE - c is not incremented as per l2c */
end_comment

begin_define
define|#
directive|define
name|l2cn
parameter_list|(
name|l1
parameter_list|,
name|l2
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 			c+=n; \ 			switch (n) { \ 			case 8: *(--(c))=(unsigned char)(((l2)>>24L)&0xff); \ 			case 7: *(--(c))=(unsigned char)(((l2)>>16L)&0xff); \ 			case 6: *(--(c))=(unsigned char)(((l2)>> 8L)&0xff); \ 			case 5: *(--(c))=(unsigned char)(((l2)     )&0xff); \ 			case 4: *(--(c))=(unsigned char)(((l1)>>24L)&0xff); \ 			case 3: *(--(c))=(unsigned char)(((l1)>>16L)&0xff); \ 			case 2: *(--(c))=(unsigned char)(((l1)>> 8L)&0xff); \ 			case 1: *(--(c))=(unsigned char)(((l1)     )&0xff); \ 				} \ 			}
end_define

begin_define
define|#
directive|define
name|ROTATE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|(((a)>>(n))+((a)<<(32-(n))))
end_define

begin_comment
comment|/* The changes to this macro may help or hinder, depending on the  * compiler and the achitecture.  gcc2 always seems to do well :-).  * Inspired by Dana How<how@isl.stanford.edu>  * DO NOT use the alternative version on machines with 8 byte longs.  * It does not seem to work on the Alpha, even when DES_LONG is 4  * bytes, probably an issue of accessing non-word aligned objects :-( */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DES_PTR
end_ifdef

begin_define
define|#
directive|define
name|D_ENCRYPT
parameter_list|(
name|L
parameter_list|,
name|R
parameter_list|,
name|S
parameter_list|)
value|{ \ 	u=((R^s[S  ])<<2);	\ 	t= R^s[S+1]; \ 	t=ROTATE(t,2); \ 	L^= (\ 	*(DES_LONG *)((unsigned char *)des_SP+0x100+((t    )&0xfc))+ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x300+((t>> 8)&0xfc))+ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x500+((t>>16)&0xfc))+ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x700+((t>>24)&0xfc))+ \ 	*(DES_LONG *)((unsigned char *)des_SP      +((u    )&0xfc))+ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x200+((u>> 8)&0xfc))+ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x400+((u>>16)&0xfc))+ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x600+((u>>24)&0xfc))); }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* original version */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|undef
end_ifdef

begin_define
define|#
directive|define
name|D_ENCRYPT
parameter_list|(
name|L
parameter_list|,
name|R
parameter_list|,
name|S
parameter_list|)
define|\
value|U.l=R^s[S+1]; \ 	T.s[0]=((U.s[0]>>4)|(U.s[1]<<12))&0x3f3f; \ 	T.s[1]=((U.s[1]>>4)|(U.s[0]<<12))&0x3f3f; \ 	U.l=(R^s[S  ])&0x3f3f3f3fL; \ 	L^=	des_SPtrans[1][(T.c[0])]| \ 		des_SPtrans[3][(T.c[1])]| \ 		des_SPtrans[5][(T.c[2])]| \ 		des_SPtrans[7][(T.c[3])]| \ 		des_SPtrans[0][(U.c[0])]| \ 		des_SPtrans[2][(U.c[1])]| \ 		des_SPtrans[4][(U.c[2])]| \ 		des_SPtrans[6][(U.c[3])];
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|D_ENCRYPT
parameter_list|(
name|Q
parameter_list|,
name|R
parameter_list|,
name|S
parameter_list|)
value|{\ 	u=(R^s[S  ]); \ 	t=R^s[S+1]; \ 	t=ROTATE(t,4); \ 	Q^=	des_SPtrans[1][(t     )&0x3f]| \ 		des_SPtrans[3][(t>> 8L)&0x3f]| \ 		des_SPtrans[5][(t>>16L)&0x3f]| \ 		des_SPtrans[7][(t>>24L)&0x3f]| \ 		des_SPtrans[0][(u     )&0x3f]| \ 		des_SPtrans[2][(u>> 8L)&0x3f]| \ 		des_SPtrans[4][(u>>16L)&0x3f]| \ 		des_SPtrans[6][(u>>24L)&0x3f]; }
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
comment|/* IP and FP 	 * The problem is more of a geometric problem that random bit fiddling. 	 0  1  2  3  4  5  6  7      62 54 46 38 30 22 14  6 	 8  9 10 11 12 13 14 15      60 52 44 36 28 20 12  4 	16 17 18 19 20 21 22 23      58 50 42 34 26 18 10  2 	24 25 26 27 28 29 30 31  to  56 48 40 32 24 16  8  0  	32 33 34 35 36 37 38 39      63 55 47 39 31 23 15  7 	40 41 42 43 44 45 46 47      61 53 45 37 29 21 13  5 	48 49 50 51 52 53 54 55      59 51 43 35 27 19 11  3 	56 57 58 59 60 61 62 63      57 49 41 33 25 17  9  1  	The output has been subject to swaps of the form 	0 1 -> 3 1 but the odd and even bits have been put into 	2 3    2 0 	different words.  The main trick is to remember that 	t=((l>>size)^r)&(mask); 	r^=t; 	l^=(t<<size); 	can be used to swap and move bits between words.  	So l =  0  1  2  3  r = 16 17 18 19 	        4  5  6  7      20 21 22 23 	        8  9 10 11      24 25 26 27 	       12 13 14 15      28 29 30 31 	becomes (for size == 2 and mask == 0x3333) 	   t =   2^16  3^17 -- --   l =  0  1 16 17  r =  2  3 18 19 		 6^20  7^21 -- --        4  5 20 21       6  7 22 23 		10^24 11^25 -- --        8  9 24 25      10 11 24 25 		14^28 15^29 -- --       12 13 28 29      14 15 28 29  	Thanks for hints from Richard Outerbridge - he told me IP&FP 	could be done in 15 xor, 10 shifts and 5 ands. 	When I finally started to think of the problem in 2D 	I first got ~42 operations without xors.  When I remembered 	how to use xors :-) I got it to its final state. 	*/
end_comment

begin_define
define|#
directive|define
name|PERM_OP
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|t
parameter_list|,
name|n
parameter_list|,
name|m
parameter_list|)
value|((t)=((((a)>>(n))^(b))&(m)),\ 	(b)^=(t),\ 	(a)^=((t)<<(n)))
end_define

begin_define
define|#
directive|define
name|IP
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|{ \ 	register DES_LONG tt; \ 	PERM_OP(r,l,tt, 4,0x0f0f0f0fL); \ 	PERM_OP(l,r,tt,16,0x0000ffffL); \ 	PERM_OP(r,l,tt, 2,0x33333333L); \ 	PERM_OP(l,r,tt, 8,0x00ff00ffL); \ 	PERM_OP(r,l,tt, 1,0x55555555L); \ 	}
end_define

begin_define
define|#
directive|define
name|FP
parameter_list|(
name|l
parameter_list|,
name|r
parameter_list|)
define|\
value|{ \ 	register DES_LONG tt; \ 	PERM_OP(l,r,tt, 1,0x55555555L); \ 	PERM_OP(r,l,tt, 8,0x00ff00ffL); \ 	PERM_OP(l,r,tt, 2,0x33333333L); \ 	PERM_OP(r,l,tt,16,0x0000ffffL); \ 	PERM_OP(l,r,tt, 4,0x0f0f0f0fL); \ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

