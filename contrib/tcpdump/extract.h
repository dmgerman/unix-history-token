begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993, 1994, 1995, 1996  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/tcpdump/extract.h,v 1.19 2002/12/11 07:13:51 guy Exp $ (LBL)  */
end_comment

begin_comment
comment|/* Network to host order macros */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|LBL_ALIGN
end_ifdef

begin_comment
comment|/*  * The processor doesn't natively handle unaligned loads.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE___ATTRIBUTE__
end_ifdef

begin_comment
comment|/*  * We have __attribute__; we assume that means we have __attribute__((packed)).  * Declare packed structures containing a u_int16_t and a u_int32_t,  * cast the pointer to point to one of those, and fetch through it;  * the GCC manual doesn't appear to explicitly say that  * __attribute__((packed)) causes the compiler to generate unaligned-safe  * code, but it apppears to do so.  *  * We do this in case the compiler can generate, for this instruction set,  * better code to do an unaligned load and pass stuff to "ntohs()" or  * "ntohl()" than the code to fetch the bytes one at a time and  * assemble them.  (That might not be the case on a little-endian platform,  * where "ntohs()" and "ntohl()" might not be done inline.)  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int16_t
name|val
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|unaligned_u_int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_int32_t
name|val
decl_stmt|;
block|}
name|__attribute__
typedef|((
name|packed
typedef|))
name|unaligned_u_int32_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EXTRACT_16BITS
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int16_t)ntohs(((const unaligned_u_int16_t *)(p))->val))
end_define

begin_define
define|#
directive|define
name|EXTRACT_32BITS
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int32_t)ntohl(((const unaligned_u_int32_t *)(p))->val))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HAVE___ATTRIBUTE__ */
end_comment

begin_comment
comment|/*  * We don't have __attribute__, so do unaligned loads of big-endian  * quantities the hard way - fetch the bytes one at a time and  * assemble them.  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_16BITS
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int16_t)((u_int16_t)*((const u_int8_t *)(p) + 0)<< 8 | \ 		     (u_int16_t)*((const u_int8_t *)(p) + 1)))
end_define

begin_define
define|#
directive|define
name|EXTRACT_32BITS
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int32_t)((u_int32_t)*((const u_int8_t *)(p) + 0)<< 24 | \ 		     (u_int32_t)*((const u_int8_t *)(p) + 1)<< 16 | \ 		     (u_int32_t)*((const u_int8_t *)(p) + 2)<< 8 | \ 		     (u_int32_t)*((const u_int8_t *)(p) + 3)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE___ATTRIBUTE__ */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* LBL_ALIGN */
end_comment

begin_comment
comment|/*  * The processor natively handles unaligned loads, so we can just  * cast the pointer and fetch through it.  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_16BITS
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int16_t)ntohs(*(const u_int16_t *)(p)))
end_define

begin_define
define|#
directive|define
name|EXTRACT_32BITS
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int32_t)ntohl(*(const u_int32_t *)(p)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LBL_ALIGN */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_24BITS
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int32_t)((u_int32_t)*((const u_int8_t *)(p) + 0)<< 16 | \ 		     (u_int32_t)*((const u_int8_t *)(p) + 1)<< 8 | \ 		     (u_int32_t)*((const u_int8_t *)(p) + 2)))
end_define

begin_comment
comment|/* Little endian protocol host order macros */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_LE_8BITS
parameter_list|(
name|p
parameter_list|)
value|(*(p))
end_define

begin_define
define|#
directive|define
name|EXTRACT_LE_16BITS
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int16_t)((u_int16_t)*((const u_int8_t *)(p) + 1)<< 8 | \ 		     (u_int16_t)*((const u_int8_t *)(p) + 0)))
end_define

begin_define
define|#
directive|define
name|EXTRACT_LE_32BITS
parameter_list|(
name|p
parameter_list|)
define|\
value|((u_int32_t)((u_int32_t)*((const u_int8_t *)(p) + 3)<< 24 | \ 		     (u_int32_t)*((const u_int8_t *)(p) + 2)<< 16 | \ 		     (u_int32_t)*((const u_int8_t *)(p) + 1)<< 8 | \ 		     (u_int32_t)*((const u_int8_t *)(p) + 0)))
end_define

end_unit

