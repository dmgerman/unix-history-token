begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/des/des_locl.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1997 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|||
name|defined
argument_list|(
name|WIN16
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_define
define|#
directive|define
name|MSDOS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<openssl/opensslconf.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MSDOS
end_ifndef

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|__DECC
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_UNISTD
end_ifdef

begin_include
include|#
directive|include
include|OPENSSL_UNISTD
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<openssl/des.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_comment
comment|/* Visual C++ 2.1 (Windows NT/95) */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

begin_include
include|#
directive|include
file|<io.h>
end_include

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
operator|||
name|defined
argument_list|(
name|VMS
argument_list|)
operator|||
name|defined
argument_list|(
name|M_XENIX
argument_list|)
operator|||
name|defined
argument_list|(
name|MSDOS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
operator|&&
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
value|(_lrotr(a,n))
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
value|(((a)>>(n))+((a)<<(32-(n))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't worry about the LOAD_DATA() stuff, that is used by  * fcrypt() to add it's little bit to the front */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DES_FCRYPT
end_ifdef

begin_define
define|#
directive|define
name|LOAD_DATA_tmp
parameter_list|(
name|R
parameter_list|,
name|S
parameter_list|,
name|u
parameter_list|,
name|t
parameter_list|,
name|E0
parameter_list|,
name|E1
parameter_list|)
define|\
value|{ DES_LONG tmp; LOAD_DATA(R,S,u,t,E0,E1,tmp); }
end_define

begin_define
define|#
directive|define
name|LOAD_DATA
parameter_list|(
name|R
parameter_list|,
name|S
parameter_list|,
name|u
parameter_list|,
name|t
parameter_list|,
name|E0
parameter_list|,
name|E1
parameter_list|,
name|tmp
parameter_list|)
define|\
value|t=R^(R>>16L); \ 	u=t&E0; t&=E1; \ 	tmp=(u<<16); u^=R^s[S  ]; u^=tmp; \ 	tmp=(t<<16); t^=R^s[S+1]; t^=tmp
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOAD_DATA_tmp
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|LOAD_DATA(a,b,c,d,e,f,g)
end_define

begin_define
define|#
directive|define
name|LOAD_DATA
parameter_list|(
name|R
parameter_list|,
name|S
parameter_list|,
name|u
parameter_list|,
name|t
parameter_list|,
name|E0
parameter_list|,
name|E1
parameter_list|,
name|tmp
parameter_list|)
define|\
value|u=R^s[S  ]; \ 	t=R^s[S+1]
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The changes to this macro may help or hinder, depending on the  * compiler and the architecture.  gcc2 always seems to do well :-).  * Inspired by Dana How<how@isl.stanford.edu>  * DO NOT use the alternative version on machines with 8 byte longs.  * It does not seem to work on the Alpha, even when DES_LONG is 4  * bytes, probably an issue of accessing non-word aligned objects :-( */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DES_PTR
end_ifdef

begin_comment
comment|/* It recently occurred to me that 0^0^0^0^0^0^0 == 0, so there  * is no reason to not xor all the sub items together.  This potentially  * saves a register since things can be xored directly into L */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DES_RISC1
argument_list|)
operator|||
name|defined
argument_list|(
name|DES_RISC2
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DES_RISC1
end_ifdef

begin_define
define|#
directive|define
name|D_ENCRYPT
parameter_list|(
name|LL
parameter_list|,
name|R
parameter_list|,
name|S
parameter_list|)
value|{ \ 	unsigned int u1,u2,u3; \ 	LOAD_DATA(R,S,u,t,E0,E1,u1); \ 	u2=(int)u>>8L; \ 	u1=(int)u&0xfc; \ 	u2&=0xfc; \ 	t=ROTATE(t,4); \ 	u>>=16L; \ 	LL^= *(const DES_LONG *)(des_SP      +u1); \ 	LL^= *(const DES_LONG *)(des_SP+0x200+u2); \ 	u3=(int)(u>>8L); \ 	u1=(int)u&0xfc; \ 	u3&=0xfc; \ 	LL^= *(const DES_LONG *)(des_SP+0x400+u1); \ 	LL^= *(const DES_LONG *)(des_SP+0x600+u3); \ 	u2=(int)t>>8L; \ 	u1=(int)t&0xfc; \ 	u2&=0xfc; \ 	t>>=16L; \ 	LL^= *(const DES_LONG *)(des_SP+0x100+u1); \ 	LL^= *(const DES_LONG *)(des_SP+0x300+u2); \ 	u3=(int)t>>8L; \ 	u1=(int)t&0xfc; \ 	u3&=0xfc; \ 	LL^= *(const DES_LONG *)(des_SP+0x500+u1); \ 	LL^= *(const DES_LONG *)(des_SP+0x700+u3); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DES_RISC2
end_ifdef

begin_define
define|#
directive|define
name|D_ENCRYPT
parameter_list|(
name|LL
parameter_list|,
name|R
parameter_list|,
name|S
parameter_list|)
value|{ \ 	unsigned int u1,u2,s1,s2; \ 	LOAD_DATA(R,S,u,t,E0,E1,u1); \ 	u2=(int)u>>8L; \ 	u1=(int)u&0xfc; \ 	u2&=0xfc; \ 	t=ROTATE(t,4); \ 	LL^= *(const DES_LONG *)(des_SP      +u1); \ 	LL^= *(const DES_LONG *)(des_SP+0x200+u2); \ 	s1=(int)(u>>16L); \ 	s2=(int)(u>>24L); \ 	s1&=0xfc; \ 	s2&=0xfc; \ 	LL^= *(const DES_LONG *)(des_SP+0x400+s1); \ 	LL^= *(const DES_LONG *)(des_SP+0x600+s2); \ 	u2=(int)t>>8L; \ 	u1=(int)t&0xfc; \ 	u2&=0xfc; \ 	LL^= *(const DES_LONG *)(des_SP+0x100+u1); \ 	LL^= *(const DES_LONG *)(des_SP+0x300+u2); \ 	s1=(int)(t>>16L); \ 	s2=(int)(t>>24L); \ 	s1&=0xfc; \ 	s2&=0xfc; \ 	LL^= *(const DES_LONG *)(des_SP+0x500+s1); \ 	LL^= *(const DES_LONG *)(des_SP+0x700+s2); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|D_ENCRYPT
parameter_list|(
name|LL
parameter_list|,
name|R
parameter_list|,
name|S
parameter_list|)
value|{ \ 	LOAD_DATA_tmp(R,S,u,t,E0,E1); \ 	t=ROTATE(t,4); \ 	LL^= \ 	*(const DES_LONG *)(des_SP      +((u     )&0xfc))^ \ 	*(const DES_LONG *)(des_SP+0x200+((u>> 8L)&0xfc))^ \ 	*(const DES_LONG *)(des_SP+0x400+((u>>16L)&0xfc))^ \ 	*(const DES_LONG *)(des_SP+0x600+((u>>24L)&0xfc))^ \ 	*(const DES_LONG *)(des_SP+0x100+((t     )&0xfc))^ \ 	*(const DES_LONG *)(des_SP+0x300+((t>> 8L)&0xfc))^ \ 	*(const DES_LONG *)(des_SP+0x500+((t>>16L)&0xfc))^ \ 	*(const DES_LONG *)(des_SP+0x700+((t>>24L)&0xfc)); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* original version */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DES_RISC1
argument_list|)
operator|||
name|defined
argument_list|(
name|DES_RISC2
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|DES_RISC1
end_ifdef

begin_define
define|#
directive|define
name|D_ENCRYPT
parameter_list|(
name|LL
parameter_list|,
name|R
parameter_list|,
name|S
parameter_list|)
value|{\ 	unsigned int u1,u2,u3; \ 	LOAD_DATA(R,S,u,t,E0,E1,u1); \ 	u>>=2L; \ 	t=ROTATE(t,6); \ 	u2=(int)u>>8L; \ 	u1=(int)u&0x3f; \ 	u2&=0x3f; \ 	u>>=16L; \ 	LL^=des_SPtrans[0][u1]; \ 	LL^=des_SPtrans[2][u2]; \ 	u3=(int)u>>8L; \ 	u1=(int)u&0x3f; \ 	u3&=0x3f; \ 	LL^=des_SPtrans[4][u1]; \ 	LL^=des_SPtrans[6][u3]; \ 	u2=(int)t>>8L; \ 	u1=(int)t&0x3f; \ 	u2&=0x3f; \ 	t>>=16L; \ 	LL^=des_SPtrans[1][u1]; \ 	LL^=des_SPtrans[3][u2]; \ 	u3=(int)t>>8L; \ 	u1=(int)t&0x3f; \ 	u3&=0x3f; \ 	LL^=des_SPtrans[5][u1]; \ 	LL^=des_SPtrans[7][u3]; }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DES_RISC2
end_ifdef

begin_define
define|#
directive|define
name|D_ENCRYPT
parameter_list|(
name|LL
parameter_list|,
name|R
parameter_list|,
name|S
parameter_list|)
value|{\ 	unsigned int u1,u2,s1,s2; \ 	LOAD_DATA(R,S,u,t,E0,E1,u1); \ 	u>>=2L; \ 	t=ROTATE(t,6); \ 	u2=(int)u>>8L; \ 	u1=(int)u&0x3f; \ 	u2&=0x3f; \ 	LL^=des_SPtrans[0][u1]; \ 	LL^=des_SPtrans[2][u2]; \ 	s1=(int)u>>16L; \ 	s2=(int)u>>24L; \ 	s1&=0x3f; \ 	s2&=0x3f; \ 	LL^=des_SPtrans[4][s1]; \ 	LL^=des_SPtrans[6][s2]; \ 	u2=(int)t>>8L; \ 	u1=(int)t&0x3f; \ 	u2&=0x3f; \ 	LL^=des_SPtrans[1][u1]; \ 	LL^=des_SPtrans[3][u2]; \ 	s1=(int)t>>16; \ 	s2=(int)t>>24L; \ 	s1&=0x3f; \ 	s2&=0x3f; \ 	LL^=des_SPtrans[5][s1]; \ 	LL^=des_SPtrans[7][s2]; }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|D_ENCRYPT
parameter_list|(
name|LL
parameter_list|,
name|R
parameter_list|,
name|S
parameter_list|)
value|{\ 	LOAD_DATA_tmp(R,S,u,t,E0,E1); \ 	t=ROTATE(t,4); \ 	LL^=\ 		des_SPtrans[0][(u>> 2L)&0x3f]^ \ 		des_SPtrans[2][(u>>10L)&0x3f]^ \ 		des_SPtrans[4][(u>>18L)&0x3f]^ \ 		des_SPtrans[6][(u>>26L)&0x3f]^ \ 		des_SPtrans[1][(t>> 2L)&0x3f]^ \ 		des_SPtrans[3][(t>>10L)&0x3f]^ \ 		des_SPtrans[5][(t>>18L)&0x3f]^ \ 		des_SPtrans[7][(t>>26L)&0x3f]; }
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

begin_decl_stmt
name|OPENSSL_EXTERN
specifier|const
name|DES_LONG
name|des_SPtrans
index|[
literal|8
index|]
index|[
literal|64
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|fcrypt_body
parameter_list|(
name|DES_LONG
modifier|*
name|out
parameter_list|,
name|des_key_schedule
name|ks
parameter_list|,
name|DES_LONG
name|Eswap0
parameter_list|,
name|DES_LONG
name|Eswap1
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

