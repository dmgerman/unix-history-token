begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* crypto/cast/cast_lcl.h */
end_comment

begin_comment
comment|/* Copyright (C) 1995-1998 Eric Young (eay@cryptsoft.com)  * All rights reserved.  *  * This package is an SSL implementation written  * by Eric Young (eay@cryptsoft.com).  * The implementation was written so as to conform with Netscapes SSL.  *   * This library is free for commercial and non-commercial use as long as  * the following conditions are aheared to.  The following conditions  * apply to all code found in this distribution, be it the RC4, RSA,  * lhash, DES, etc., code; not just the SSL code.  The SSL documentation  * included with this distribution is covered by the same copyright terms  * except that the holder is Tim Hudson (tjh@cryptsoft.com).  *   * Copyright remains Eric Young's, and as such any Copyright notices in  * the code are not to be removed.  * If this package is used in a product, Eric Young should be given attribution  * as the author of the parts of the library used.  * This can be in the form of a textual message at program startup or  * in documentation (online or textual) provided with the package.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    "This product includes cryptographic software written by  *     Eric Young (eay@cryptsoft.com)"  *    The word 'cryptographic' can be left out if the rouines from the library  *    being used are not cryptographic related :-).  * 4. If you include any Windows specific code (or a derivative thereof) from   *    the apps directory (application code) you must include an acknowledgement:  *    "This product includes software written by Tim Hudson (tjh@cryptsoft.com)"  *   * THIS SOFTWARE IS PROVIDED BY ERIC YOUNG ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * The licence and distribution terms for any publically available version or  * derivative of this code cannot be changed.  i.e. this code cannot simply be  * copied and put under another distribution licence  * [including the GNU Public Licence.]  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"openssl/e_os.h"
end_include

begin_comment
comment|/* OPENSSL_EXTERN */
end_comment

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
value|(l =((unsigned long)(*((c)++)))    , \ 			 l|=((unsigned long)(*((c)++)))<< 8L, \ 			 l|=((unsigned long)(*((c)++)))<<16L, \ 			 l|=((unsigned long)(*((c)++)))<<24L)
end_define

begin_comment
comment|/* NOTE - c is not incremented as per c2l */
end_comment

begin_undef
undef|#
directive|undef
name|c2ln
end_undef

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
value|{ \ 			c+=n; \ 			l1=l2=0; \ 			switch (n) { \ 			case 8: l2 =((unsigned long)(*(--(c))))<<24L; \ 			case 7: l2|=((unsigned long)(*(--(c))))<<16L; \ 			case 6: l2|=((unsigned long)(*(--(c))))<< 8L; \ 			case 5: l2|=((unsigned long)(*(--(c))));     \ 			case 4: l1 =((unsigned long)(*(--(c))))<<24L; \ 			case 3: l1|=((unsigned long)(*(--(c))))<<16L; \ 			case 2: l1|=((unsigned long)(*(--(c))))<< 8L; \ 			case 1: l1|=((unsigned long)(*(--(c))));     \ 				} \ 			}
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
value|(*((c)++)=(unsigned char)(((l)     )&0xff), \ 			 *((c)++)=(unsigned char)(((l)>> 8L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>16L)&0xff), \ 			 *((c)++)=(unsigned char)(((l)>>24L)&0xff))
end_define

begin_comment
comment|/* NOTE - c is not incremented as per l2c */
end_comment

begin_undef
undef|#
directive|undef
name|l2cn
end_undef

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

begin_comment
comment|/* NOTE - c is not incremented as per n2l */
end_comment

begin_define
define|#
directive|define
name|n2ln
parameter_list|(
name|c
parameter_list|,
name|l1
parameter_list|,
name|l2
parameter_list|,
name|n
parameter_list|)
value|{ \ 			c+=n; \ 			l1=l2=0; \ 			switch (n) { \ 			case 8: l2 =((unsigned long)(*(--(c))))    ; \ 			case 7: l2|=((unsigned long)(*(--(c))))<< 8; \ 			case 6: l2|=((unsigned long)(*(--(c))))<<16; \ 			case 5: l2|=((unsigned long)(*(--(c))))<<24; \ 			case 4: l1 =((unsigned long)(*(--(c))))    ; \ 			case 3: l1|=((unsigned long)(*(--(c))))<< 8; \ 			case 2: l1|=((unsigned long)(*(--(c))))<<16; \ 			case 1: l1|=((unsigned long)(*(--(c))))<<24; \ 				} \ 			}
end_define

begin_comment
comment|/* NOTE - c is not incremented as per l2n */
end_comment

begin_define
define|#
directive|define
name|l2nn
parameter_list|(
name|l1
parameter_list|,
name|l2
parameter_list|,
name|c
parameter_list|,
name|n
parameter_list|)
value|{ \ 			c+=n; \ 			switch (n) { \ 			case 8: *(--(c))=(unsigned char)(((l2)    )&0xff); \ 			case 7: *(--(c))=(unsigned char)(((l2)>> 8)&0xff); \ 			case 6: *(--(c))=(unsigned char)(((l2)>>16)&0xff); \ 			case 5: *(--(c))=(unsigned char)(((l2)>>24)&0xff); \ 			case 4: *(--(c))=(unsigned char)(((l1)    )&0xff); \ 			case 3: *(--(c))=(unsigned char)(((l1)>> 8)&0xff); \ 			case 2: *(--(c))=(unsigned char)(((l1)>>16)&0xff); \ 			case 1: *(--(c))=(unsigned char)(((l1)>>24)&0xff); \ 				} \ 			}
end_define

begin_undef
undef|#
directive|undef
name|n2l
end_undef

begin_define
define|#
directive|define
name|n2l
parameter_list|(
name|c
parameter_list|,
name|l
parameter_list|)
value|(l =((unsigned long)(*((c)++)))<<24L, \                          l|=((unsigned long)(*((c)++)))<<16L, \                          l|=((unsigned long)(*((c)++)))<< 8L, \                          l|=((unsigned long)(*((c)++))))
end_define

begin_undef
undef|#
directive|undef
name|l2n
end_undef

begin_define
define|#
directive|define
name|l2n
parameter_list|(
name|l
parameter_list|,
name|c
parameter_list|)
value|(*((c)++)=(unsigned char)(((l)>>24L)&0xff), \                          *((c)++)=(unsigned char)(((l)>>16L)&0xff), \                          *((c)++)=(unsigned char)(((l)>> 8L)&0xff), \                          *((c)++)=(unsigned char)(((l)     )&0xff))
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
name|ROTL
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|(_lrotl(a,n))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ROTL
parameter_list|(
name|a
parameter_list|,
name|n
parameter_list|)
value|((((a)<<(n))&0xffffffffL)|((a)>>(32-(n))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|C_M
value|0x3fc
end_define

begin_define
define|#
directive|define
name|C_0
value|22L
end_define

begin_define
define|#
directive|define
name|C_1
value|14L
end_define

begin_define
define|#
directive|define
name|C_2
value|6L
end_define

begin_define
define|#
directive|define
name|C_3
value|2L
end_define

begin_comment
comment|/* left shift */
end_comment

begin_comment
comment|/* The rotate has an extra 16 added to it to help the x86 asm */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CAST_PTR
argument_list|)
end_if

begin_define
define|#
directive|define
name|E_CAST
parameter_list|(
name|n
parameter_list|,
name|key
parameter_list|,
name|L
parameter_list|,
name|R
parameter_list|,
name|OP1
parameter_list|,
name|OP2
parameter_list|,
name|OP3
parameter_list|)
define|\
value|{ \ 	int i; \ 	t=(key[n*2] OP1 R)&0xffffffffL; \ 	i=key[n*2+1]; \ 	t=ROTL(t,i); \ 	L^= (((((*(CAST_LONG *)((unsigned char *) \ 			CAST_S_table0+((t>>C_2)&C_M)) OP2 \ 		*(CAST_LONG *)((unsigned char *) \ 			CAST_S_table1+((t<<C_3)&C_M)))&0xffffffffL) OP3 \ 		*(CAST_LONG *)((unsigned char *) \ 			CAST_S_table2+((t>>C_0)&C_M)))&0xffffffffL) OP1 \ 		*(CAST_LONG *)((unsigned char *) \ 			CAST_S_table3+((t>>C_1)&C_M)))&0xffffffffL; \ 	}
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|CAST_PTR2
argument_list|)
end_elif

begin_define
define|#
directive|define
name|E_CAST
parameter_list|(
name|n
parameter_list|,
name|key
parameter_list|,
name|L
parameter_list|,
name|R
parameter_list|,
name|OP1
parameter_list|,
name|OP2
parameter_list|,
name|OP3
parameter_list|)
define|\
value|{ \ 	int i; \ 	CAST_LONG u,v,w; \ 	w=(key[n*2] OP1 R)&0xffffffffL; \ 	i=key[n*2+1]; \ 	w=ROTL(w,i); \ 	u=w>>C_2; \ 	v=w<<C_3; \ 	u&=C_M; \ 	v&=C_M; \ 	t= *(CAST_LONG *)((unsigned char *)CAST_S_table0+u); \ 	u=w>>C_0; \ 	t=(t OP2 *(CAST_LONG *)((unsigned char *)CAST_S_table1+v))&0xffffffffL;\ 	v=w>>C_1; \ 	u&=C_M; \ 	v&=C_M; \ 	t=(t OP3 *(CAST_LONG *)((unsigned char *)CAST_S_table2+u)&0xffffffffL);\ 	t=(t OP1 *(CAST_LONG *)((unsigned char *)CAST_S_table3+v)&0xffffffffL);\ 	L^=(t&0xffffffff); \ 	}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|E_CAST
parameter_list|(
name|n
parameter_list|,
name|key
parameter_list|,
name|L
parameter_list|,
name|R
parameter_list|,
name|OP1
parameter_list|,
name|OP2
parameter_list|,
name|OP3
parameter_list|)
define|\
value|{ \ 	CAST_LONG a,b,c,d; \ 	t=(key[n*2] OP1 R)&0xffffffff; \ 	t=ROTL(t,(key[n*2+1])); \ 	a=CAST_S_table0[(t>> 8)&0xff]; \ 	b=CAST_S_table1[(t    )&0xff]; \ 	c=CAST_S_table2[(t>>24)&0xff]; \ 	d=CAST_S_table3[(t>>16)&0xff]; \ 	L^=(((((a OP2 b)&0xffffffffL) OP3 c)&0xffffffffL) OP1 d)&0xffffffffL; \ 	}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|OPENSSL_EXTERN
specifier|const
name|CAST_LONG
name|CAST_S_table0
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OPENSSL_EXTERN
specifier|const
name|CAST_LONG
name|CAST_S_table1
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OPENSSL_EXTERN
specifier|const
name|CAST_LONG
name|CAST_S_table2
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OPENSSL_EXTERN
specifier|const
name|CAST_LONG
name|CAST_S_table3
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OPENSSL_EXTERN
specifier|const
name|CAST_LONG
name|CAST_S_table4
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OPENSSL_EXTERN
specifier|const
name|CAST_LONG
name|CAST_S_table5
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OPENSSL_EXTERN
specifier|const
name|CAST_LONG
name|CAST_S_table6
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|OPENSSL_EXTERN
specifier|const
name|CAST_LONG
name|CAST_S_table7
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

end_unit

