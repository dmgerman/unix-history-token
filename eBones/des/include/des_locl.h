begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* des_locl.h */
end_comment

begin_comment
comment|/* Copyright (C) 1993 Eric Young - see README for more details */
end_comment

begin_comment
comment|/*-  *	$Id: des_locl.h,v 1.2 1994/07/19 19:22:18 g89r4222 Exp $  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"des.h"
end_include

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

begin_define
define|#
directive|define
name|bcopy
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|len
parameter_list|)
value|memcpy(b2, b1, (size_t)(len))
end_define

begin_define
define|#
directive|define
name|bzero
parameter_list|(
name|b
parameter_list|,
name|len
parameter_list|)
value|memset(b, 0, (size_t)(len))
end_define

begin_define
define|#
directive|define
name|bcmp
parameter_list|(
name|b1
parameter_list|,
name|b2
parameter_list|,
name|len
parameter_list|)
value|memcmp(b1, b2, (size_t)(len))
end_define

begin_define
define|#
directive|define
name|index
parameter_list|(
name|s1
parameter_list|,
name|char
parameter_list|)
value|strchr(s1,char)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|MSDOS
end_ifdef

begin_define
define|#
directive|define
name|getpid
parameter_list|()
value|2
end_define

begin_define
define|#
directive|define
name|RAND
end_define

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PROTO
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

begin_define
define|#
directive|define
name|PROTO
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RAND
end_ifdef

begin_define
define|#
directive|define
name|random
parameter_list|()
value|rand()
end_define

begin_define
define|#
directive|define
name|srandom
parameter_list|(
name|s
parameter_list|)
value|srand(s)
end_define

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
value|(l =((unsigned long)(*((c)++)))    , \ 			 l|=((unsigned long)(*((c)++)))<< 8, \ 			 l|=((unsigned long)(*((c)++)))<<16, \ 			 l|=((unsigned long)(*((c)++)))<<24)
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
value|{ \ 			c+=n; \ 			l1=l2=0; \ 			switch (n) { \ 			case 8: l2|=((unsigned long)(*(--(c))))<<24; \ 			case 7: l2|=((unsigned long)(*(--(c))))<<16; \ 			case 6: l2|=((unsigned long)(*(--(c))))<< 8; \ 			case 5: l2|=((unsigned long)(*(--(c))));     \ 			case 4: l1|=((unsigned long)(*(--(c))))<<24; \ 			case 3: l1|=((unsigned long)(*(--(c))))<<16; \ 			case 2: l1|=((unsigned long)(*(--(c))))<< 8; \ 			case 1: l1|=((unsigned long)(*(--(c))));     \ 				} \ 			}
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
value|(*((c)++)=(unsigned char)(((l)    )&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>16)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>24)&0xff))
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
value|(l =((unsigned long)(*((c)++)))<<24, \ 			 l|=((unsigned long)(*((c)++)))<<16, \ 			 l|=((unsigned long)(*((c)++)))<< 8, \ 			 l|=((unsigned long)(*((c)++))))
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
value|(*((c)++)=(unsigned char)(((l)>>24)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>16)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8)&0xff), \ 			 *((c)++)=(unsigned char)(((l)    )&0xff))
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
value|{ \ 			c+=n; \ 			switch (n) { \ 			case 8: *(--(c))=(unsigned char)(((l2)>>24)&0xff); \ 			case 7: *(--(c))=(unsigned char)(((l2)>>16)&0xff); \ 			case 6: *(--(c))=(unsigned char)(((l2)>> 8)&0xff); \ 			case 5: *(--(c))=(unsigned char)(((l2)    )&0xff); \ 			case 4: *(--(c))=(unsigned char)(((l1)>>24)&0xff); \ 			case 3: *(--(c))=(unsigned char)(((l1)>>16)&0xff); \ 			case 2: *(--(c))=(unsigned char)(((l1)>> 8)&0xff); \ 			case 1: *(--(c))=(unsigned char)(((l1)    )&0xff); \ 				} \ 			}
end_define

begin_comment
comment|/* The changes to this macro may help or hinder, depending on the  * compiler and the achitecture.  gcc2 always seems to do well :-).  * Inspired by Dana How<how@isl.stanford.edu>  * DO NOT use the alternative version on machines with 8 byte longs. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ALT_ECB
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
value|u=((R^s[S  ])<<2);	\ 	t= R^s[S+1]; \ 	t=((t>>2)+(t<<30)); \ 	L^= \ 	*(unsigned long *)(des_SP+0x0100+((t    )&0xfc))+ \ 	*(unsigned long *)(des_SP+0x0300+((t>> 8)&0xfc))+ \ 	*(unsigned long *)(des_SP+0x0500+((t>>16)&0xfc))+ \ 	*(unsigned long *)(des_SP+0x0700+((t>>24)&0xfc))+ \ 	*(unsigned long *)(des_SP+       ((u    )&0xfc))+ \   	*(unsigned long *)(des_SP+0x0200+((u>> 8)&0xfc))+ \   	*(unsigned long *)(des_SP+0x0400+((u>>16)&0xfc))+ \  	*(unsigned long *)(des_SP+0x0600+((u>>24)&0xfc));
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
name|MSDOS
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
value|U.l=R^s[S+1]; \ 	T.s[0]=((U.s[0]>>4)|(U.s[1]<<12))&0x3f3f; \ 	T.s[1]=((U.s[1]>>4)|(U.s[0]<<12))&0x3f3f; \ 	U.l=(R^s[S  ])&0x3f3f3f3f; \ 	L^=	des_SPtrans[1][(T.c[0])]| \ 		des_SPtrans[3][(T.c[1])]| \ 		des_SPtrans[5][(T.c[2])]| \ 		des_SPtrans[7][(T.c[3])]| \ 		des_SPtrans[0][(U.c[0])]| \ 		des_SPtrans[2][(U.c[1])]| \ 		des_SPtrans[4][(U.c[2])]| \ 		des_SPtrans[6][(U.c[3])];
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
name|L
parameter_list|,
name|R
parameter_list|,
name|S
parameter_list|)
define|\
value|u=(R^s[S  ]); \ 	t=R^s[S+1]; \ 	t=((t>>4)+(t<<28)); \ 	L^=	des_SPtrans[1][(t    )&0x3f]| \ 		des_SPtrans[3][(t>> 8)&0x3f]| \ 		des_SPtrans[5][(t>>16)&0x3f]| \ 		des_SPtrans[7][(t>>24)&0x3f]| \ 		des_SPtrans[0][(u    )&0x3f]| \ 		des_SPtrans[2][(u>> 8)&0x3f]| \ 		des_SPtrans[4][(u>>16)&0x3f]| \ 		des_SPtrans[6][(u>>24)&0x3f];
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

end_unit

