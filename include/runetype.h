begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Paul Borman at Krystal Technologies.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)runetype.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RUNETYPE_H_
end_ifndef

begin_define
define|#
directive|define
name|_RUNETYPE_H_
end_define

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<machine/ansi.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_RUNE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_RUNE_T_
name|rune_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_RUNE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_SIZE_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_SIZE_T_
name|size_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_SIZE_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_BSD_WCHAR_T_
end_ifdef

begin_typedef
typedef|typedef
name|_BSD_WCHAR_T_
name|wchar_t
typedef|;
end_typedef

begin_undef
undef|#
directive|undef
name|_BSD_WCHAR_T_
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|_CACHED_RUNES
value|(1<<8 )
end_define

begin_comment
comment|/* Must be a power of 2 */
end_comment

begin_define
define|#
directive|define
name|_CRMASK
value|(~(_CACHED_RUNES - 1))
end_define

begin_comment
comment|/*  * The lower 8 bits of runetype[] contain the digit value of the rune.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|rune_t
name|min
decl_stmt|;
comment|/* First rune of the range */
name|rune_t
name|max
decl_stmt|;
comment|/* Last rune (inclusive) of the range */
name|rune_t
name|map
decl_stmt|;
comment|/* What first maps to in maps */
name|unsigned
name|long
modifier|*
name|types
decl_stmt|;
comment|/* Array of types in range */
block|}
name|_RuneEntry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|nranges
decl_stmt|;
comment|/* Number of ranges stored */
name|_RuneEntry
modifier|*
name|ranges
decl_stmt|;
comment|/* Pointer to the ranges */
block|}
name|_RuneRange
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|magic
index|[
literal|8
index|]
decl_stmt|;
comment|/* Magic saying what version we are */
name|char
name|encoding
index|[
literal|32
index|]
decl_stmt|;
comment|/* ASCII name of this encoding */
name|rune_t
function_decl|(
modifier|*
name|sgetrune
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
specifier|const
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sputrune
function_decl|)
parameter_list|(
name|rune_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
name|rune_t
name|invalid_rune
decl_stmt|;
name|unsigned
name|long
name|runetype
index|[
name|_CACHED_RUNES
index|]
decl_stmt|;
name|rune_t
name|maplower
index|[
name|_CACHED_RUNES
index|]
decl_stmt|;
name|rune_t
name|mapupper
index|[
name|_CACHED_RUNES
index|]
decl_stmt|;
comment|/* 	 * The following are to deal with Runes larger than _CACHED_RUNES - 1. 	 * Their data is actually contiguous with this structure so as to make 	 * it easier to read/write from/to disk. 	 */
name|_RuneRange
name|runetype_ext
decl_stmt|;
name|_RuneRange
name|maplower_ext
decl_stmt|;
name|_RuneRange
name|mapupper_ext
decl_stmt|;
name|void
modifier|*
name|variable
decl_stmt|;
comment|/* Data which depends on the encoding */
name|int
name|variable_len
decl_stmt|;
comment|/* how long that data is */
block|}
name|_RuneLocale
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_RUNE_MAGIC_1
value|"RuneMagi"
end_define

begin_comment
comment|/* Indicates version 0 of RuneLocale */
end_comment

begin_decl_stmt
specifier|extern
name|_RuneLocale
name|_DefaultRuneLocale
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|_RuneLocale
modifier|*
name|_CurrentRuneLocale
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RUNETYPE_H_ */
end_comment

end_unit

