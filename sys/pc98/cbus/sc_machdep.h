begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999 FreeBSD(98) Porting Team.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PC98_PC98_SC_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_PC98_PC98_SC_MACHDEP_H_
end_define

begin_undef
undef|#
directive|undef
name|SC_ALT_MOUSE_IMAGE
end_undef

begin_undef
undef|#
directive|undef
name|SC_DFLT_FONT
end_undef

begin_undef
undef|#
directive|undef
name|SC_MOUSE_CHAR
end_undef

begin_undef
undef|#
directive|undef
name|SC_PIXEL_MODE
end_undef

begin_undef
undef|#
directive|undef
name|SC_NO_FONT_LOADING
end_undef

begin_define
define|#
directive|define
name|SC_NO_FONT_LOADING
value|1
end_define

begin_undef
undef|#
directive|undef
name|SC_NO_PALETTE_LOADING
end_undef

begin_define
define|#
directive|define
name|SC_NO_PALETTE_LOADING
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SC_KERNEL_CONS_ATTR
end_ifndef

begin_define
define|#
directive|define
name|SC_KERNEL_CONS_ATTR
value|(FG_LIGHTGREY | BG_BLACK)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KANJI
value|1
end_define

begin_define
define|#
directive|define
name|BELL_DURATION
value|5
end_define

begin_define
define|#
directive|define
name|BELL_PITCH_8M
value|1339
end_define

begin_define
define|#
directive|define
name|BELL_PITCH_5M
value|1678
end_define

begin_define
define|#
directive|define
name|UJIS
value|0
end_define

begin_define
define|#
directive|define
name|SJIS
value|1
end_define

begin_define
define|#
directive|define
name|PRINTABLE
parameter_list|(
name|c
parameter_list|)
value|((c)> 0x1b || ((c)> 0x0f&& (c)< 0x1b) \ 				 || (c)< 0x07)
end_define

begin_define
define|#
directive|define
name|ISMOUSEAVAIL
parameter_list|(
name|af
parameter_list|)
value|(1)
end_define

begin_define
define|#
directive|define
name|ISFONTAVAIL
parameter_list|(
name|af
parameter_list|)
value|((af)& V_ADP_FONT)
end_define

begin_define
define|#
directive|define
name|ISPALAVAIL
parameter_list|(
name|af
parameter_list|)
value|((af)& V_ADP_PALETTE)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KANJI
end_ifdef

begin_define
define|#
directive|define
name|IS_KTYPE_ASCII_or_HANKAKU
parameter_list|(
name|A
parameter_list|)
value|(!((A)& 0xee))
end_define

begin_define
define|#
directive|define
name|IS_KTYPE_KANA
parameter_list|(
name|A
parameter_list|)
value|((A)& 0x11)
end_define

begin_define
define|#
directive|define
name|KTYPE_MASK_CTRL
parameter_list|(
name|A
parameter_list|)
value|((A)&= 0xF0)
end_define

begin_define
define|#
directive|define
name|_SCR_MD_STAT_DECLARED_
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_char
name|kanji_1st_char
decl_stmt|;
name|u_char
name|kanji_type
decl_stmt|;
define|#
directive|define
name|KTYPE_ASCII
value|0
comment|/* ASCII */
define|#
directive|define
name|KTYPE_KANA
value|1
comment|/* HANKAKU */
define|#
directive|define
name|KTYPE_JKANA
value|0x10
comment|/* JIS HANKAKU */
define|#
directive|define
name|KTYPE_7JIS
value|0x20
comment|/* JIS */
define|#
directive|define
name|KTYPE_SJIS
value|2
comment|/* Shift JIS */
define|#
directive|define
name|KTYPE_UJIS
value|4
comment|/* UJIS */
define|#
directive|define
name|KTYPE_SUKANA
value|3
comment|/* Shift JIS or UJIS HANKAKU */
define|#
directive|define
name|KTYPE_SUJIS
value|6
comment|/* SHift JIS or UJIS */
define|#
directive|define
name|KTYPE_KANIN
value|0x80
comment|/* Kanji Invoke sequence */
define|#
directive|define
name|KTYPE_ASCIN
value|0x40
comment|/* ASCII Invoke sequence */
block|}
name|scr_md_stat_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KANJI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_PC98_PC98_SC_MACHDEP_H_ */
end_comment

end_unit

