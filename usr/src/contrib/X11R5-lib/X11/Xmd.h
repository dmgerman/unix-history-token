begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************** Copyright 1987 by Digital Equipment Corporation, Maynard, Massachusetts, and the Massachusetts Institute of Technology, Cambridge, Massachusetts.                          All Rights Reserved  Permission to use, copy, modify, and distribute this software and its  documentation for any purpose and without fee is hereby granted,  provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in  supporting documentation, and that the names of Digital or MIT not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.    DIGITAL DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL DIGITAL BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  ******************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XMD_H
end_ifndef

begin_define
define|#
directive|define
name|XMD_H
value|1
end_define

begin_comment
comment|/* $XConsortium: Xmd.h,v 1.41 91/05/10 10:00:03 jap Exp $ */
end_comment

begin_comment
comment|/*  *  Xmd.h: MACHINE DEPENDENT DECLARATIONS.  */
end_comment

begin_comment
comment|/*  * Special per-machine configuration flags.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CRAY
end_ifdef

begin_define
define|#
directive|define
name|WORD64
end_define

begin_comment
comment|/* 64-bit architecture */
end_comment

begin_define
define|#
directive|define
name|UNSIGNEDBITFIELDS
end_define

begin_comment
comment|/* bit fields do not honor sign */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Stuff to handle large architecture machines; the constants were generated  * on a 32-bit machine and must coorespond to the protocol.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORD64
end_ifdef

begin_define
define|#
directive|define
name|MUSTCOPY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WORD64 */
end_comment

begin_comment
comment|/*  * Definition of macro used to set constants for size of network structures;  * machines with preprocessors that can't handle all of the sz_ symbols  * can define this macro to be sizeof(x) if and only if their compiler doesn't  * pad out structures (esp. the xTextElt structure which contains only two   * one-byte fields).  Network structures should always define sz_symbols.  *  * The sz_ prefix is used instead of something more descriptive so that the  * symbols are no more than 32 characters long (which causes problems for some  * compilers and preprocessors).  *  * The extra indirection in the __STDC__ case is to get macro arguments to  * expand correctly before the concatenation, rather than afterward.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
operator|&&
operator|!
name|defined
argument_list|(
name|UNIXCPP
argument_list|)
end_if

begin_define
define|#
directive|define
name|_SIZEOF
parameter_list|(
name|x
parameter_list|)
value|sz_##x
end_define

begin_define
define|#
directive|define
name|SIZEOF
parameter_list|(
name|x
parameter_list|)
value|_SIZEOF(x)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SIZEOF
parameter_list|(
name|x
parameter_list|)
value|sz_
comment|/**/
value|x
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* if ANSI C compiler else not */
end_comment

begin_comment
comment|/*  * Bitfield suffixes for the protocol structure elements, if you  * need them.  Note that bitfields are not guarranteed to be signed  * (or even unsigned) according to ANSI C.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WORD64
end_ifdef

begin_define
define|#
directive|define
name|B32
value|:32
end_define

begin_define
define|#
directive|define
name|B16
value|:16
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|B32
end_define

begin_define
define|#
directive|define
name|B16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|long
name|INT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|INT16
typedef|;
end_typedef

begin_if
if|#
directive|if
name|__STDC__
operator|||
name|defined
argument_list|(
name|sgi
argument_list|)
operator|||
name|defined
argument_list|(
name|AIXV3
argument_list|)
end_if

begin_typedef
typedef|typedef
name|signed
name|char
name|INT8
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|char
name|INT8
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|long
name|CARD32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|CARD16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|CARD8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|BITS32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|BITS16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BYTE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|BOOL
typedef|;
end_typedef

begin_comment
comment|/*  * definitions for sign-extending bitfields on 64-bit architectures  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|WORD64
argument_list|)
operator|&&
name|defined
argument_list|(
name|UNSIGNEDBITFIELDS
argument_list|)
end_if

begin_define
define|#
directive|define
name|cvtINT8toInt
parameter_list|(
name|val
parameter_list|)
value|(((val)& 0x00000080) ? ((val) | 0xffffffffffffff00) : (val))
end_define

begin_define
define|#
directive|define
name|cvtINT16toInt
parameter_list|(
name|val
parameter_list|)
value|(((val)& 0x00008000) ? ((val) | 0xffffffffffff0000) : (val))
end_define

begin_define
define|#
directive|define
name|cvtINT32toInt
parameter_list|(
name|val
parameter_list|)
value|(((val)& 0x80000000) ? ((val) | 0xffffffff00000000) : (val))
end_define

begin_define
define|#
directive|define
name|cvtINT8toShort
parameter_list|(
name|val
parameter_list|)
value|cvtINT8toInt(val)
end_define

begin_define
define|#
directive|define
name|cvtINT16toShort
parameter_list|(
name|val
parameter_list|)
value|cvtINT16toInt(val)
end_define

begin_define
define|#
directive|define
name|cvtINT32toShort
parameter_list|(
name|val
parameter_list|)
value|cvtINT32toInt(val)
end_define

begin_define
define|#
directive|define
name|cvtINT8toLong
parameter_list|(
name|val
parameter_list|)
value|cvtINT8toInt(val)
end_define

begin_define
define|#
directive|define
name|cvtINT16toLong
parameter_list|(
name|val
parameter_list|)
value|cvtINT16toInt(val)
end_define

begin_define
define|#
directive|define
name|cvtINT32toLong
parameter_list|(
name|val
parameter_list|)
value|cvtINT32toInt(val)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|cvtINT8toInt
parameter_list|(
name|val
parameter_list|)
value|(val)
end_define

begin_define
define|#
directive|define
name|cvtINT16toInt
parameter_list|(
name|val
parameter_list|)
value|(val)
end_define

begin_define
define|#
directive|define
name|cvtINT32toInt
parameter_list|(
name|val
parameter_list|)
value|(val)
end_define

begin_define
define|#
directive|define
name|cvtINT8toShort
parameter_list|(
name|val
parameter_list|)
value|(val)
end_define

begin_define
define|#
directive|define
name|cvtINT16toShort
parameter_list|(
name|val
parameter_list|)
value|(val)
end_define

begin_define
define|#
directive|define
name|cvtINT32toShort
parameter_list|(
name|val
parameter_list|)
value|(val)
end_define

begin_define
define|#
directive|define
name|cvtINT8toLong
parameter_list|(
name|val
parameter_list|)
value|(val)
end_define

begin_define
define|#
directive|define
name|cvtINT16toLong
parameter_list|(
name|val
parameter_list|)
value|(val)
end_define

begin_define
define|#
directive|define
name|cvtINT32toLong
parameter_list|(
name|val
parameter_list|)
value|(val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WORD64 and UNSIGNEDBITFIELDS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MUSTCOPY
end_ifdef

begin_comment
comment|/*  * This macro must not cast or else pointers will get aligned and be wrong  */
end_comment

begin_define
define|#
directive|define
name|NEXTPTR
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|(((char *) p) + SIZEOF(t))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* else not MUSTCOPY, this is used for 32-bit machines */
end_comment

begin_comment
comment|/*  * this version should leave result of type (t *), but that should only be   * used when not in MUSTCOPY  */
end_comment

begin_define
define|#
directive|define
name|NEXTPTR
parameter_list|(
name|p
parameter_list|,
name|t
parameter_list|)
value|(((t *)(p)) + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MUSTCOPY - used machines whose C structs don't line up with proto */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XMD_H */
end_comment

end_unit

