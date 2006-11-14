begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Portions Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Portions Copyright (C) 2001  Internet Software Consortium.  * Portions Copyright (C) 2001  Nominum, Inc.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC AND NOMINUM DISCLAIMS ALL  * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: util.h,v 1.3.206.1 2004/03/06 08:15:23 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISCCC_UTIL_H
end_ifndef

begin_define
define|#
directive|define
name|ISCCC_UTIL_H
value|1
end_define

begin_include
include|#
directive|include
file|<isc/util.h>
end_include

begin_comment
comment|/*  * Macros for dealing with unaligned numbers.  *  * Note: no side effects are allowed when invoking these macros!  */
end_comment

begin_define
define|#
directive|define
name|GET8
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		v = *w; \ 		w++; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|GET16
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		v = (unsigned int)w[0]<< 8; \  		v |= (unsigned int)w[1]; \ 		w += 2; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|GET24
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \  		v = (unsigned int)w[0]<< 16; \  		v |= (unsigned int)w[1]<< 8; \  		v |= (unsigned int)w[2]; \ 		w += 3; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|GET32
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		v = (unsigned int)w[0]<< 24; \  		v |= (unsigned int)w[1]<< 16; \  		v |= (unsigned int)w[2]<< 8; \  		v |= (unsigned int)w[3]; \ 		w += 4; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|GET64
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		v = (isc_uint64_t)w[0]<< 56; \  		v |= (isc_uint64_t)w[1]<< 48; \  		v |= (isc_uint64_t)w[2]<< 40; \  		v |= (isc_uint64_t)w[3]<< 32; \  		v |= (isc_uint64_t)w[4]<< 24; \  		v |= (isc_uint64_t)w[5]<< 16; \  		v |= (isc_uint64_t)w[6]<< 8; \  		v |= (isc_uint64_t)w[7]; \ 		w += 8; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|GETC16
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|,
name|d
parameter_list|)
define|\
value|do { \ 		GET8(v, w); \ 		if (v == 0) \ 			d = ISCCC_TRUE; \  		else { \ 			d = ISCCC_FALSE; \ 			if (v == 255) \ 				GET16(v, w); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|GETC32
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		GET24(v, w); \  		if (v == 0xffffffu) \ 			GET32(v, w); \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|GET_OFFSET
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
value|GET32(v, w)
end_define

begin_define
define|#
directive|define
name|GET_MEM
parameter_list|(
name|v
parameter_list|,
name|c
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		memcpy(v, w, c); \ 		w += c; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|GET_TYPE
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		GET8(v, w); \ 		if (v> 127) { \ 			if (v< 255) \ 				v = ((v& 0x7f)<< 16) | ISCCC_RDATATYPE_SIG; \ 			else \ 				GET32(v, w); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PUT8
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		*w = (v& 0x000000ffU); \ 		w++; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PUT16
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		w[0] = (v& 0x0000ff00U)>> 8; \ 		w[1] = (v& 0x000000ffU); \ 		w += 2; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PUT24
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		w[0] = (v& 0x00ff0000U)>> 16; \ 		w[1] = (v& 0x0000ff00U)>> 8; \ 		w[2] = (v& 0x000000ffU); \ 		w += 3; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PUT32
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		w[0] = (v& 0xff000000U)>> 24; \ 		w[1] = (v& 0x00ff0000U)>> 16; \ 		w[2] = (v& 0x0000ff00U)>> 8; \ 		w[3] = (v& 0x000000ffU); \ 		w += 4; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PUT64
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		w[0] = (v& 0xff00000000000000ULL)>> 56; \ 		w[1] = (v& 0x00ff000000000000ULL)>> 48; \ 		w[2] = (v& 0x0000ff0000000000ULL)>> 40; \ 		w[3] = (v& 0x000000ff00000000ULL)>> 32; \ 		w[4] = (v& 0x00000000ff000000ULL)>> 24; \ 		w[5] = (v& 0x0000000000ff0000ULL)>> 16; \ 		w[6] = (v& 0x000000000000ff00ULL)>> 8; \ 		w[7] = (v& 0x00000000000000ffULL); \ 		w += 8; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PUTC16
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		if (v> 0&& v< 255) \ 			PUT8(v, w); \ 		else { \ 			PUT8(255, w); \ 			PUT16(v, w); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PUTC32
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		if (v< 0xffffffU) \ 			PUT24(v, w); \ 		else { \ 			PUT24(0xffffffU, w); \ 			PUT32(v, w); \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PUT_OFFSET
parameter_list|(
name|v
parameter_list|,
name|w
parameter_list|)
value|PUT32(v, w)
end_define

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_define
define|#
directive|define
name|PUT_MEM
parameter_list|(
name|s
parameter_list|,
name|c
parameter_list|,
name|w
parameter_list|)
define|\
value|do { \ 		memcpy(w, s, c); \ 		w += c; \ 	} while (0)
end_define

begin_comment
comment|/*  * Regions.  */
end_comment

begin_define
define|#
directive|define
name|REGION_SIZE
parameter_list|(
name|r
parameter_list|)
value|((unsigned int)((r).rend - (r).rstart))
end_define

begin_define
define|#
directive|define
name|REGION_EMPTY
parameter_list|(
name|r
parameter_list|)
value|((r).rstart == (r).rend)
end_define

begin_define
define|#
directive|define
name|REGION_FROMSTRING
parameter_list|(
name|r
parameter_list|,
name|s
parameter_list|)
value|do { \ 	(r).rstart = (unsigned char *)s; \ 	(r).rend = (r).rstart + strlen(s); \ } while (0)
end_define

begin_comment
comment|/*  * Use this to remove the const qualifier of a variable to assign it to  * a non-const variable or pass it as a non-const function argument ...  * but only when you are sure it won't then be changed!  * This is necessary to sometimes shut up some compilers  * (as with gcc -Wcast-qual) when there is just no other good way to avoid the  * situation.  */
end_comment

begin_define
define|#
directive|define
name|DE_CONST
parameter_list|(
name|konst
parameter_list|,
name|var
parameter_list|)
define|\
value|do { \ 		union { const void *k; void *v; } _u; \ 		_u.k = konst; \ 		var = _u.v; \ 	} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISCCC_UTIL_H */
end_comment

end_unit

