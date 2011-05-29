begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 by Peter Jeremy<peterjeremy@acm.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE  * USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*---------------------------------------------------------------------------- | One of the macros `BIGENDIAN' or `LITTLEENDIAN' must be defined. *----------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|BIGENDIAN
end_define

begin_comment
comment|/*---------------------------------------------------------------------------- | The macro `BITS64' can be defined to indicate that 64-bit integer types are | supported by the compiler. *----------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|BITS64
end_define

begin_comment
comment|/*---------------------------------------------------------------------------- | Each of the following `typedef's defines the most convenient type that holds | integers of at least as many bits as specified.  For example, `uint8' should | be the most convenient type that can hold unsigned integers of as many as | 8 bits.  The `flag' type must be able to hold either a 0 or 1.  For most | implementations of C, `flag', `uint8', and `int8' should all be `typedef'ed | to the same as `int'. *----------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
name|int
name|flag
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|uint8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|uint16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|int32
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|BITS64
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|uint64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|int
name|int64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------- | Each of the following `typedef's defines a type that holds integers | of _exactly_ the number of bits specified.  For instance, for most | implementation of C, `bits16' and `sbits16' should be `typedef'ed to | `unsigned short int' and `signed short int' (or `short int'), respectively. *----------------------------------------------------------------------------*/
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|bits8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|char
name|sbits8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|bits16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|short
name|int
name|sbits16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|bits32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
name|sbits32
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|BITS64
end_ifdef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|int
name|bits64
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|long
name|int
name|sbits64
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BITS64
end_ifdef

begin_comment
comment|/*---------------------------------------------------------------------------- | The `LIT64' macro takes as its argument a textual integer literal and | if necessary ``marks'' the literal as having a 64-bit integer type. | For example, the GNU C Compiler (`gcc') requires that 64-bit literals be | appended with the letters `LL' standing for `long long', which is `gcc's | name for the 64-bit integer type.  Some compilers may allow `LIT64' to be | defined as the identity macro:  `#define LIT64( a ) a'. *----------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|LIT64
parameter_list|(
name|a
parameter_list|)
value|a##L
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*---------------------------------------------------------------------------- | The macro `INLINE' can be used before functions that should be inlined.  If | a compiler does not support explicit inlining, this macro should be defined | to be `static'. *----------------------------------------------------------------------------*/
end_comment

begin_define
define|#
directive|define
name|INLINE
value|extern inline
end_define

end_unit

