begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*     eui64.h - EUI64 routines for IPv6CP.     Copyright (C) 1999  Tommi Komulainen<Tommi.Komulainen@iki.fi>      Redistribution and use in source and binary forms are permitted     provided that the above copyright notice and this paragraph are     duplicated in all such forms and that any documentation,     advertising materials, and other materials related to such     distribution and use acknowledge that the software was developed     by Tommi Komulainen.  The name of the author may not be used     to endorse or promote products derived from this software without     specific prior written permission.     THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR     IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED     WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.           $Id: eui64.h,v 1.3 1999/09/30 19:56:37 masputra Exp $     $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EUI64_H__
end_ifndef

begin_define
define|#
directive|define
name|__EUI64_H__
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INET6
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"this file should only be included when INET6 is defined"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not defined(INET6) */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOL2
argument_list|)
end_if

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_typedef
typedef|typedef
union|union
block|{
name|uint8_t
name|e8
index|[
literal|8
index|]
decl_stmt|;
comment|/* lower 64-bit IPv6 address */
name|uint32_t
name|e32
index|[
literal|2
index|]
decl_stmt|;
comment|/* lower 64-bit IPv6 address */
block|}
name|eui64_t
typedef|;
end_typedef

begin_comment
comment|/*  * Declare the two below, since in.h only defines them when _KERNEL  * is declared - which shouldn't be true when dealing with user-land programs  */
end_comment

begin_define
define|#
directive|define
name|s6_addr8
value|_S6_un._S6_u8
end_define

begin_define
define|#
directive|define
name|s6_addr32
value|_S6_un._S6_u32
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* else if not defined(SOL2) */
end_comment

begin_comment
comment|/*  * TODO:  *  * Maybe this should be done by processing struct in6_addr directly...  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|u_int8_t
name|e8
index|[
literal|8
index|]
decl_stmt|;
name|u_int16_t
name|e16
index|[
literal|4
index|]
decl_stmt|;
name|u_int32_t
name|e32
index|[
literal|2
index|]
decl_stmt|;
block|}
name|eui64_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(SOL2) */
end_comment

begin_define
define|#
directive|define
name|eui64_iszero
parameter_list|(
name|e
parameter_list|)
value|(((e).e32[0] | (e).e32[1]) == 0)
end_define

begin_define
define|#
directive|define
name|eui64_equals
parameter_list|(
name|e
parameter_list|,
name|o
parameter_list|)
value|(((e).e32[0] == (o).e32[0])&& \ 				((e).e32[1] == (o).e32[1]))
end_define

begin_define
define|#
directive|define
name|eui64_zero
parameter_list|(
name|e
parameter_list|)
value|(e).e32[0] = (e).e32[1] = 0;
end_define

begin_define
define|#
directive|define
name|eui64_copy
parameter_list|(
name|s
parameter_list|,
name|d
parameter_list|)
value|memcpy(&(d),&(s), sizeof(eui64_t))
end_define

begin_define
define|#
directive|define
name|eui64_magic
parameter_list|(
name|e
parameter_list|)
value|do {			\ 				(e).e32[0] = magic();	\ 				(e).e32[1] = magic();	\ 				(e).e8[0]&= ~2;	\ 				} while (0)
end_define

begin_define
define|#
directive|define
name|eui64_magic_nz
parameter_list|(
name|x
parameter_list|)
value|do {				\ 				eui64_magic(x);			\ 				} while (eui64_iszero(x))
end_define

begin_define
define|#
directive|define
name|eui64_magic_ne
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|do {				\ 				eui64_magic(x);			\ 				} while (eui64_equals(x, y))
end_define

begin_define
define|#
directive|define
name|eui64_get
parameter_list|(
name|ll
parameter_list|,
name|cp
parameter_list|)
value|do {				\ 				eui64_copy((*cp), (ll));	\ 				(cp) += sizeof(eui64_t);	\ 				} while (0)
end_define

begin_define
define|#
directive|define
name|eui64_put
parameter_list|(
name|ll
parameter_list|,
name|cp
parameter_list|)
value|do {				\ 				eui64_copy((ll), (*cp));	\ 				(cp) += sizeof(eui64_t);	\ 				} while (0)
end_define

begin_define
define|#
directive|define
name|eui64_set32
parameter_list|(
name|e
parameter_list|,
name|l
parameter_list|)
value|do {			\ 				(e).e32[0] = 0;		\ 				(e).e32[1] = htonl(l);	\ 				} while (0)
end_define

begin_define
define|#
directive|define
name|eui64_setlo32
parameter_list|(
name|e
parameter_list|,
name|l
parameter_list|)
value|eui64_set32(e, l)
end_define

begin_decl_stmt
name|char
modifier|*
name|eui64_ntoa
name|__P
argument_list|(
operator|(
name|eui64_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Returns ascii representation of id */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __EUI64_H__ */
end_comment

end_unit

