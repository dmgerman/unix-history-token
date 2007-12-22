begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/sha/sha_locl.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|undef
end_ifdef

begin_comment
comment|/* one or the other needs to be defined */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SHA_1
end_ifndef

begin_comment
comment|/* FIPE 180-1 */
end_comment

begin_define
define|#
directive|define
name|SHA_0
end_define

begin_comment
comment|/* FIPS 180   */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ULONG
value|unsigned long
end_define

begin_define
define|#
directive|define
name|UCHAR
value|unsigned char
end_define

begin_define
define|#
directive|define
name|UINT
value|unsigned int
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NOCONST
end_ifdef

begin_define
define|#
directive|define
name|const
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|c2nl
end_undef

begin_define
define|#
directive|define
name|c2nl
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =(((unsigned long)(*((c)++)))<<24), \ 			 l|=(((unsigned long)(*((c)++)))<<16), \ 			 l|=(((unsigned long)(*((c)++)))<< 8), \ 			 l|=(((unsigned long)(*((c)++)))    ))
end_define

begin_undef
undef|#
directive|undef
name|p_c2nl
end_undef

begin_define
define|#
directive|define
name|p_c2nl
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|)
value|{ \ 			switch (n) { \ 			case 0: l =((unsigned long)(*((c)++)))<<24; \ 			case 1: l|=((unsigned long)(*((c)++)))<<16; \ 			case 2: l|=((unsigned long)(*((c)++)))<< 8; \ 			case 3: l|=((unsigned long)(*((c)++))); \ 				} \ 			}
end_define

begin_undef
undef|#
directive|undef
name|c2nl_p
end_undef

begin_comment
comment|/* NOTE the pointer is not incremented at the end of this */
end_comment

begin_define
define|#
directive|define
name|c2nl_p
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|)
value|{ \ 			l=0; \ 			(c)+=n; \ 			switch (n) { \ 			case 3: l =((unsigned long)(*(--(c))))<< 8; \ 			case 2: l|=((unsigned long)(*(--(c))))<<16; \ 			case 1: l|=((unsigned long)(*(--(c))))<<24; \ 				} \ 			}
end_define

begin_undef
undef|#
directive|undef
name|p_c2nl_p
end_undef

begin_define
define|#
directive|define
name|p_c2nl_p
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|sc
parameter_list|,
name|len
parameter_list|)
value|{ \ 			switch (sc) \ 				{ \ 			case 0: l =((unsigned long)(*((c)++)))<<24; \ 				if (--len == 0) break; \ 			case 1: l|=((unsigned long)(*((c)++)))<<16; \ 				if (--len == 0) break; \ 			case 2: l|=((unsigned long)(*((c)++)))<< 8; \ 				} \ 			}
end_define

begin_undef
undef|#
directive|undef
name|nl2c
end_undef

begin_define
define|#
directive|define
name|nl2c
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)>>24)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>16)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8)&0xff), \ 			 *((c)++)=(unsigned char)(((l)    )&0xff))
end_define

begin_undef
undef|#
directive|undef
name|c2l
end_undef

begin_define
define|#
directive|define
name|c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =(((unsigned long)(*((c)++)))    ), \ 			 l|=(((unsigned long)(*((c)++)))<< 8), \ 			 l|=(((unsigned long)(*((c)++)))<<16), \ 			 l|=(((unsigned long)(*((c)++)))<<24))
end_define

begin_undef
undef|#
directive|undef
name|p_c2l
end_undef

begin_define
define|#
directive|define
name|p_c2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|)
value|{ \ 			switch (n) { \ 			case 0: l =((unsigned long)(*((c)++))); \ 			case 1: l|=((unsigned long)(*((c)++)))<< 8; \ 			case 2: l|=((unsigned long)(*((c)++)))<<16; \ 			case 3: l|=((unsigned long)(*((c)++)))<<24; \ 				} \ 			}
end_define

begin_undef
undef|#
directive|undef
name|c2l_p
end_undef

begin_comment
comment|/* NOTE the pointer is not incremented at the end of this */
end_comment

begin_define
define|#
directive|define
name|c2l_p
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|n
parameter_list|)
value|{ \ 			l=0; \ 			(c)+=n; \ 			switch (n) { \ 			case 3: l =((unsigned long)(*(--(c))))<<16; \ 			case 2: l|=((unsigned long)(*(--(c))))<< 8; \ 			case 1: l|=((unsigned long)(*(--(c)))); \ 				} \ 			}
end_define

begin_undef
undef|#
directive|undef
name|p_c2l_p
end_undef

begin_define
define|#
directive|define
name|p_c2l_p
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|,
name|sc
parameter_list|,
name|len
parameter_list|)
value|{ \ 			switch (sc) \ 				{ \ 			case 0: l =((unsigned long)(*((c)++))); \ 				if (--len == 0) break; \ 			case 1: l|=((unsigned long)(*((c)++)))<< 8; \ 				if (--len == 0) break; \ 			case 2: l|=((unsigned long)(*((c)++)))<<16; \ 				} \ 			}
end_define

begin_undef
undef|#
directive|undef
name|l2c
end_undef

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

begin_undef
undef|#
directive|undef
name|ROTATE
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
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
value|(((a)<<(n))|(((a)&0xffffffff)>>(32-(n))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A nice byte order reversal from Wei Dai<weidai@eskimo.com> */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WIN32
argument_list|)
end_if

begin_comment
comment|/* 5 instructions with rotate instruction, else 9 */
end_comment

begin_define
define|#
directive|define
name|Endian_Reverse32
parameter_list|(
name|a
parameter_list|)
define|\
value|{ \ 	unsigned long l=(a); \ 	(a)=((ROTATE(l,8)&0x00FF00FF)|(ROTATE(l,24)&0xFF00FF00)); \ 	}
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
name|Endian_Reverse32
parameter_list|(
name|a
parameter_list|)
define|\
value|{ \ 	unsigned long l=(a); \ 	l=(((l&0xFF00FF00)>>8L)|((l&0x00FF00FF)<<8L)); \ 	(a)=ROTATE(l,16L); \ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* As  pointed out by Wei Dai<weidai@eskimo.com>, F() below can be  * simplified to the code in F_00_19.  Wei attributes these optimisations  * to Peter Gutmann's SHS code, and he attributes it to Rich Schroeppel.  * #define F(x,y,z) (((x)& (y))  |  ((~(x))& (z)))  * I've just become aware of another tweak to be made, again from Wei Dai,  * in F_40_59, (x&a)|(y&a) -> (x|y)&a  */
end_comment

begin_define
define|#
directive|define
name|F_00_19
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((((c) ^ (d))& (b)) ^ (d))
end_define

begin_define
define|#
directive|define
name|F_20_39
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|((b) ^ (c) ^ (d))
end_define

begin_define
define|#
directive|define
name|F_40_59
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|(((b)& (c)) | (((b)|(c))& (d)))
end_define

begin_define
define|#
directive|define
name|F_60_79
parameter_list|(
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|F_20_39(b,c,d)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|SHA_0
end_ifdef

begin_undef
undef|#
directive|undef
name|Xupdate
end_undef

begin_define
define|#
directive|define
name|Xupdate
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|,
name|ia
parameter_list|,
name|ib
parameter_list|,
name|ic
parameter_list|,
name|id
parameter_list|)
value|X[(i)&0x0f]=(a)=\ 	(ia[(i)&0x0f]^ib[((i)+2)&0x0f]^ic[((i)+8)&0x0f]^id[((i)+13)&0x0f]);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SHA_1
end_ifdef

begin_undef
undef|#
directive|undef
name|Xupdate
end_undef

begin_define
define|#
directive|define
name|Xupdate
parameter_list|(
name|a
parameter_list|,
name|i
parameter_list|,
name|ia
parameter_list|,
name|ib
parameter_list|,
name|ic
parameter_list|,
name|id
parameter_list|)
value|(a)=\ 	(ia[(i)&0x0f]^ib[((i)+2)&0x0f]^ic[((i)+8)&0x0f]^id[((i)+13)&0x0f]);\ 	X[(i)&0x0f]=(a)=ROTATE((a),1);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BODY_00_15
parameter_list|(
name|i
parameter_list|,
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
parameter_list|,
name|xa
parameter_list|)
define|\
value|(f)=xa[i]+(e)+K_00_19+ROTATE((a),5)+F_00_19((b),(c),(d)); \ 	(b)=ROTATE((b),30);
end_define

begin_define
define|#
directive|define
name|BODY_16_19
parameter_list|(
name|i
parameter_list|,
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
parameter_list|,
name|xa
parameter_list|,
name|xb
parameter_list|,
name|xc
parameter_list|,
name|xd
parameter_list|)
define|\
value|Xupdate(f,i,xa,xb,xc,xd); \ 	(f)+=(e)+K_00_19+ROTATE((a),5)+F_00_19((b),(c),(d)); \ 	(b)=ROTATE((b),30);
end_define

begin_define
define|#
directive|define
name|BODY_20_31
parameter_list|(
name|i
parameter_list|,
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
parameter_list|,
name|xa
parameter_list|,
name|xb
parameter_list|,
name|xc
parameter_list|,
name|xd
parameter_list|)
define|\
value|Xupdate(f,i,xa,xb,xc,xd); \ 	(f)+=(e)+K_20_39+ROTATE((a),5)+F_20_39((b),(c),(d)); \ 	(b)=ROTATE((b),30);
end_define

begin_define
define|#
directive|define
name|BODY_32_39
parameter_list|(
name|i
parameter_list|,
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
parameter_list|,
name|xa
parameter_list|)
define|\
value|Xupdate(f,i,xa,xa,xa,xa); \ 	(f)+=(e)+K_20_39+ROTATE((a),5)+F_20_39((b),(c),(d)); \ 	(b)=ROTATE((b),30);
end_define

begin_define
define|#
directive|define
name|BODY_40_59
parameter_list|(
name|i
parameter_list|,
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
parameter_list|,
name|xa
parameter_list|)
define|\
value|Xupdate(f,i,xa,xa,xa,xa); \ 	(f)+=(e)+K_40_59+ROTATE((a),5)+F_40_59((b),(c),(d)); \ 	(b)=ROTATE((b),30);
end_define

begin_define
define|#
directive|define
name|BODY_60_79
parameter_list|(
name|i
parameter_list|,
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
parameter_list|,
name|xa
parameter_list|)
define|\
value|Xupdate(f,i,xa,xa,xa,xa); \ 	(f)=X[(i)&0x0f]+(e)+K_60_79+ROTATE((a),5)+F_60_79((b),(c),(d)); \ 	(b)=ROTATE((b),30);
end_define

end_unit

