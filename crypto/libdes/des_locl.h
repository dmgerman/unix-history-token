begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_comment
comment|/*   if (we have termios.h)     define TERMIOS   else if (we have termio.h)     define TERMIO */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIOS_H
end_ifdef

begin_define
define|#
directive|define
name|TERMIOS
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_TERMIOS_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIO_H
end_ifdef

begin_define
define|#
directive|define
name|TERMIO
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
comment|/* !HAVE_TERMIOS_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_CONFIG_H */
end_comment

begin_comment
comment|/* crypto/des/des_locl.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1997 Eric Young (eay@mincom.oz.au)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@mincom.oz.au).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@mincom.oz.au).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@mincom.oz.au)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@mincom.oz.au)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_IO_H
end_ifdef

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"des.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|DES_DEFAULT_OPTIONS
end_ifndef

begin_comment
comment|/* the following is tweaked from a config script, that is why it is a  * protected undef/define */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DES_PTR
end_ifndef

begin_undef
undef|#
directive|undef
name|DES_PTR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This helps C compiler generate the correct code for multiple functional  * units.  It reduces register dependancies at the expense of 2 more  * registers */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DES_RISC1
end_ifndef

begin_undef
undef|#
directive|undef
name|DES_RISC1
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DES_RISC2
end_ifndef

begin_undef
undef|#
directive|undef
name|DES_RISC2
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DES_RISC1
argument_list|)
operator|&&
name|defined
argument_list|(
name|DES_RISC2
argument_list|)
end_if

begin_expr_stmt
name|YOU
name|SHOULD
name|NOT
name|HAVE
name|BOTH
name|DES_RISC1
name|AND
name|DES_RISC2
name|DEFINED
operator|!
operator|!
operator|!
operator|!
operator|!
endif|#
directive|endif
comment|/* Unroll the inner loop, this sometimes helps, sometimes hinders.  * Very mucy CPU dependant */
ifndef|#
directive|ifndef
name|DES_UNROLL
undef|#
directive|undef
name|DES_UNROLL
endif|#
directive|endif
comment|/* These default values were supplied by  * Peter Gutman<pgut001@cs.auckland.ac.nz>  * They are only used if nothing else has been defined */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DES_PTR
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DES_RISC1
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DES_RISC2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|DES_UNROLL
argument_list|)
comment|/* Special defines which change the way the code is built depending on the    CPU and OS.  For SGI machines you can use _MIPS_SZLONG (32 or 64) to find    even newer MIPS CPU's, but at the moment one size fits all for    optimization options.  Older Sparc's work better with only UNROLL, but    there's no way to tell at compile time what it is you're running on */
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
comment|/* Newer Sparc's */
define|#
directive|define
name|DES_PTR
define|#
directive|define
name|DES_RISC1
define|#
directive|define
name|DES_UNROLL
elif|#
directive|elif
name|defined
argument_list|(
name|__ultrix
argument_list|)
comment|/* Older MIPS */
define|#
directive|define
name|DES_PTR
define|#
directive|define
name|DES_RISC2
define|#
directive|define
name|DES_UNROLL
elif|#
directive|elif
name|defined
argument_list|(
name|__osf1__
argument_list|)
comment|/* Alpha */
define|#
directive|define
name|DES_PTR
define|#
directive|define
name|DES_RISC2
elif|#
directive|elif
name|defined
argument_list|(
name|_AIX
argument_list|)
comment|/* RS6000 */
comment|/* Unknown */
elif|#
directive|elif
name|defined
argument_list|(
name|__hpux
argument_list|)
comment|/* HP-PA */
define|#
directive|define
name|DES_UNROLL
elif|#
directive|elif
name|defined
argument_list|(
name|__aux
argument_list|)
comment|/* 68K */
comment|/* Unknown */
elif|#
directive|elif
name|defined
argument_list|(
name|__dgux
argument_list|)
comment|/* 88K (but P6 in latest boxes) */
define|#
directive|define
name|DES_UNROLL
elif|#
directive|elif
name|defined
argument_list|(
name|__sgi
argument_list|)
comment|/* Newer MIPS */
define|#
directive|define
name|DES_PTR
define|#
directive|define
name|DES_RISC2
define|#
directive|define
name|DES_UNROLL
elif|#
directive|elif
name|defined
argument_list|(
name|i386
argument_list|)
comment|/* x86 boxes, should be gcc */
define|#
directive|define
name|DES_PTR
define|#
directive|define
name|DES_RISC1
define|#
directive|define
name|DES_UNROLL
endif|#
directive|endif
comment|/* Systems-specific speed defines */
endif|#
directive|endif
endif|#
directive|endif
comment|/* DES_DEFAULT_OPTIONS */
ifdef|#
directive|ifdef
name|MSDOS
comment|/* Visual C++ 2.1 (Windows NT/95) */
include|#
directive|include
file|<stdlib.h>
include|#
directive|include
file|<errno.h>
include|#
directive|include
file|<time.h>
include|#
directive|include
file|<io.h>
ifndef|#
directive|ifndef
name|RAND
define|#
directive|define
name|RAND
endif|#
directive|endif
undef|#
directive|undef
name|NOPROTO
endif|#
directive|endif
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
operator|||
name|defined
argument_list|(
name|WIN32
argument_list|)
include|#
directive|include
file|<string.h>
endif|#
directive|endif
ifndef|#
directive|ifndef
name|RAND
define|#
directive|define
name|RAND
endif|#
directive|endif
ifdef|#
directive|ifdef
name|linux
undef|#
directive|undef
name|RAND
endif|#
directive|endif
ifdef|#
directive|ifdef
name|MSDOS
define|#
directive|define
name|getpid
parameter_list|()
value|2
define|#
directive|define
name|RAND
undef|#
directive|undef
name|NOPROTO
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|NOCONST
argument_list|)
define|#
directive|define
name|const
endif|#
directive|endif
ifdef|#
directive|ifdef
name|__STDC__
undef|#
directive|undef
name|NOPROTO
endif|#
directive|endif
ifdef|#
directive|ifdef
name|RAND
define|#
directive|define
name|srandom
parameter_list|(
name|s
parameter_list|)
value|srand(s)
define|#
directive|define
name|random
value|rand
endif|#
directive|endif
define|#
directive|define
name|ITERATIONS
value|16
define|#
directive|define
name|HALF_ITERATIONS
value|8
comment|/* used in des_read and des_write */
define|#
directive|define
name|MAXWRITE
value|(1024*16)
define|#
directive|define
name|BSIZE
value|(MAXWRITE+4)
define|#
directive|define
name|c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =((DES_LONG)(*((c)++)))    , \ 			 l|=((DES_LONG)(*((c)++)))<< 8L, \ 			 l|=((DES_LONG)(*((c)++)))<<16L, \ 			 l|=((DES_LONG)(*((c)++)))<<24L)
comment|/* NOTE - c is not incremented as per c2l */
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
define|#
directive|define
name|l2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)     )&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>16L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>24L)&0xff))
comment|/* replacements for htonl and ntohl since I have no idea what to do  * when faced with machines with 8 byte longs. */
define|#
directive|define
name|HDRSIZE
value|4
define|#
directive|define
name|n2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =((DES_LONG)(*((c)++)))<<24L, \ 			 l|=((DES_LONG)(*((c)++)))<<16L, \ 			 l|=((DES_LONG)(*((c)++)))<< 8L, \ 			 l|=((DES_LONG)(*((c)++))))
define|#
directive|define
name|l2n
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)>>24L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>16L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)     )&0xff))
comment|/* NOTE - c is not incremented as per l2c */
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
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
define|#
directive|define
name|ROTATE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|(_lrotr(a,n))
else|#
directive|else
define|#
directive|define
name|ROTATE
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|(((a)>>(n))+((a)<<(32-(n))))
endif|#
directive|endif
comment|/* Don't worry about the LOAD_DATA() stuff, that is used by  * fcrypt() to add it's little bit to the front */
ifdef|#
directive|ifdef
name|DES_FCRYPT
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
else|#
directive|else
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
endif|#
directive|endif
comment|/* The changes to this macro may help or hinder, depending on the  * compiler and the achitecture.  gcc2 always seems to do well :-).  * Inspired by Dana How<how@isl.stanford.edu>  * DO NOT use the alternative version on machines with 8 byte longs.  * It does not seem to work on the Alpha, even when DES_LONG is 4  * bytes, probably an issue of accessing non-word aligned objects :-( */
ifdef|#
directive|ifdef
name|DES_PTR
comment|/* It recently occured to me that 0^0^0^0^0^0^0 == 0, so there  * is no reason to not xor all the sub items together.  This potentially  * saves a register since things can be xored directly into L */
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
ifdef|#
directive|ifdef
name|DES_RISC1
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
value|{ \ 	unsigned int u1,u2,u3; \ 	LOAD_DATA(R,S,u,t,E0,E1,u1); \ 	u2=(int)u>>8L; \ 	u1=(int)u&0xfc; \ 	u2&=0xfc; \ 	t=ROTATE(t,4); \ 	u>>=16L; \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP      +u1); \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x200+u2); \ 	u3=(int)(u>>8L); \ 	u1=(int)u&0xfc; \ 	u3&=0xfc; \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x400+u1); \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x600+u3); \ 	u2=(int)t>>8L; \ 	u1=(int)t&0xfc; \ 	u2&=0xfc; \ 	t>>=16L; \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x100+u1); \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x300+u2); \ 	u3=(int)t>>8L; \ 	u1=(int)t&0xfc; \ 	u3&=0xfc; \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x500+u1); \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x700+u3); }
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DES_RISC2
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
value|{ \ 	unsigned int u1,u2,s1,s2; \ 	LOAD_DATA(R,S,u,t,E0,E1,u1); \ 	u2=(int)u>>8L; \ 	u1=(int)u&0xfc; \ 	u2&=0xfc; \ 	t=ROTATE(t,4); \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP      +u1); \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x200+u2); \ 	s1=(int)(u>>16L); \ 	s2=(int)(u>>24L); \ 	s1&=0xfc; \ 	s2&=0xfc; \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x400+s1); \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x600+s2); \ 	u2=(int)t>>8L; \ 	u1=(int)t&0xfc; \ 	u2&=0xfc; \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x100+u1); \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x300+u2); \ 	s1=(int)(t>>16L); \ 	s2=(int)(t>>24L); \ 	s1&=0xfc; \ 	s2&=0xfc; \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x500+s1); \ 	LL^= *(DES_LONG *)((unsigned char *)des_SP+0x700+s2); }
endif|#
directive|endif
else|#
directive|else
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
value|{ \ 	LOAD_DATA_tmp(R,S,u,t,E0,E1); \ 	t=ROTATE(t,4); \ 	LL^= \ 	*(DES_LONG *)((unsigned char *)des_SP      +((u     )&0xfc))^ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x200+((u>> 8L)&0xfc))^ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x400+((u>>16L)&0xfc))^ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x600+((u>>24L)&0xfc))^ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x100+((t     )&0xfc))^ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x300+((t>> 8L)&0xfc))^ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x500+((t>>16L)&0xfc))^ \ 	*(DES_LONG *)((unsigned char *)des_SP+0x700+((t>>24L)&0xfc)); }
endif|#
directive|endif
else|#
directive|else
comment|/* original version */
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
ifdef|#
directive|ifdef
name|DES_RISC1
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
endif|#
directive|endif
ifdef|#
directive|ifdef
name|DES_RISC2
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
endif|#
directive|endif
else|#
directive|else
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
endif|#
directive|endif
endif|#
directive|endif
comment|/* IP and FP 	 * The problem is more of a geometric problem that random bit fiddling. 	 0  1  2  3  4  5  6  7      62 54 46 38 30 22 14  6 	 8  9 10 11 12 13 14 15      60 52 44 36 28 20 12  4 	16 17 18 19 20 21 22 23      58 50 42 34 26 18 10  2 	24 25 26 27 28 29 30 31  to  56 48 40 32 24 16  8  0  	32 33 34 35 36 37 38 39      63 55 47 39 31 23 15  7 	40 41 42 43 44 45 46 47      61 53 45 37 29 21 13  5 	48 49 50 51 52 53 54 55      59 51 43 35 27 19 11  3 	56 57 58 59 60 61 62 63      57 49 41 33 25 17  9  1  	The output has been subject to swaps of the form 	0 1 -> 3 1 but the odd and even bits have been put into 	2 3    2 0 	different words.  The main trick is to remember that 	t=((l>>size)^r)&(mask); 	r^=t; 	l^=(t<<size); 	can be used to swap and move bits between words.  	So l =  0  1  2  3  r = 16 17 18 19 	        4  5  6  7      20 21 22 23 	        8  9 10 11      24 25 26 27 	       12 13 14 15      28 29 30 31 	becomes (for size == 2 and mask == 0x3333) 	   t =   2^16  3^17 -- --   l =  0  1 16 17  r =  2  3 18 19 		 6^20  7^21 -- --        4  5 20 21       6  7 22 23 		10^24 11^25 -- --        8  9 24 25      10 11 24 25 		14^28 15^29 -- --       12 13 28 29      14 15 28 29  	Thanks for hints from Richard Outerbridge - he told me IP&FP 	could be done in 15 xor, 10 shifts and 5 ands. 	When I finally started to think of the problem in 2D 	I first got ~42 operations without xors.  When I remembered 	how to use xors :-) I got it to its final state. 	*/
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
specifier|extern
specifier|const
name|DES_LONG
name|des_SPtrans
index|[
literal|8
index|]
index|[
literal|64
index|]
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

