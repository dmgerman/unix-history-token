begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lang.h -- declarations for language codes etc.    $Id: lang.h,v 1.7 2001/09/11 18:04:29 karl Exp $     Copyright (C) 1999, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Originally written by Karl Heinz Marbaise<kama@hippo.fido.de>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_H
end_ifndef

begin_define
define|#
directive|define
name|LANG_H
end_define

begin_comment
comment|/* The language code which can be changed through @documentlanguage  * Actually we don't currently support this (may be in the future) ;-)  * These code are the ISO-639 two letter codes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|aa
block|,
name|ab
block|,
name|af
block|,
name|am
block|,
name|ar
block|,
name|as
block|,
name|ay
block|,
name|az
block|,
name|ba
block|,
name|be
block|,
name|bg
block|,
name|bh
block|,
name|bi
block|,
name|bn
block|,
name|bo
block|,
name|br
block|,
name|ca
block|,
name|co
block|,
name|cs
block|,
name|cy
block|,
name|da
block|,
name|de
block|,
name|dz
block|,
name|el
block|,
name|en
block|,
name|eo
block|,
name|es
block|,
name|et
block|,
name|eu
block|,
name|fa
block|,
name|fi
block|,
name|fj
block|,
name|fo
block|,
name|fr
block|,
name|fy
block|,
name|ga
block|,
name|gd
block|,
name|gl
block|,
name|gn
block|,
name|gu
block|,
name|ha
block|,
name|he
block|,
name|hi
block|,
name|hr
block|,
name|hu
block|,
name|hy
block|,
name|ia
block|,
name|id
block|,
name|ie
block|,
name|ik
block|,
name|is
block|,
name|it
block|,
name|iu
block|,
name|ja
block|,
name|jw
block|,
name|ka
block|,
name|kk
block|,
name|kl
block|,
name|km
block|,
name|kn
block|,
name|ko
block|,
name|ks
block|,
name|ku
block|,
name|ky
block|,
name|la
block|,
name|ln
block|,
name|lo
block|,
name|lt
block|,
name|lv
block|,
name|mg
block|,
name|mi
block|,
name|mk
block|,
name|ml
block|,
name|mn
block|,
name|mo
block|,
name|mr
block|,
name|ms
block|,
name|mt
block|,
name|my
block|,
name|na
block|,
name|ne
block|,
name|nl
block|,
name|no
block|,
name|oc
block|,
name|om
block|,
name|or
block|,
name|pa
block|,
name|pl
block|,
name|ps
block|,
name|pt
block|,
name|qu
block|,
name|rm
block|,
name|rn
block|,
name|ro
block|,
name|ru
block|,
name|rw
block|,
name|sa
block|,
name|sd
block|,
name|sg
block|,
name|sh
block|,
name|si
block|,
name|sk
block|,
name|sl
block|,
name|sm
block|,
name|sn
block|,
name|so
block|,
name|sq
block|,
name|sr
block|,
name|ss
block|,
name|st
block|,
name|su
block|,
name|sv
block|,
name|sw
block|,
name|ta
block|,
name|te
block|,
name|tg
block|,
name|th
block|,
name|ti
block|,
name|tk
block|,
name|tl
block|,
name|tn
block|,
name|to
block|,
name|tr
block|,
name|ts
block|,
name|tt
block|,
name|tw
block|,
name|ug
block|,
name|uk
block|,
name|ur
block|,
name|uz
block|,
name|vi
block|,
name|vo
block|,
name|wo
block|,
name|xh
block|,
name|yi
block|,
name|yo
block|,
name|za
block|,
name|zh
block|,
name|zu
block|,
name|last_language_code
block|}
name|language_code_type
typedef|;
end_typedef

begin_comment
comment|/* The current language code.  */
end_comment

begin_decl_stmt
specifier|extern
name|language_code_type
name|language_code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Information for each language.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|language_code_type
name|lc
decl_stmt|;
comment|/* language code as enum type */
name|char
modifier|*
name|abbrev
decl_stmt|;
comment|/* two letter language code */
name|char
modifier|*
name|desc
decl_stmt|;
comment|/* full name for language code */
block|}
name|language_type
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|language_type
name|language_table
index|[]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* The document encoding. This is usefull if we working e.g.  * with german Texinfo so we can produce correct german umlaut  * while creating output (--no-headers ASCII like).  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|no_encoding
block|,
name|ISO_8859_1
block|,
comment|/* default for en, de, */
name|ISO_8859_2
block|,
comment|/* actualy not supported like the rest below */
name|ISO_8859_3
block|,
name|ISO_8859_4
block|,
name|ISO_8859_5
block|,
name|ISO_8859_6
block|,
name|ISO_8859_7
block|,
name|ISO_8859_8
block|,
name|ISO_8859_9
block|,
name|ISO_8859_10
block|,
name|ISO_8859_11
block|,
name|ISO_8859_12
block|,
name|ISO_8859_13
block|,
name|ISO_8859_14
block|,
name|ISO_8859_15
block|,
name|last_encoding_code
block|}
name|encoding_code_type
typedef|;
end_typedef

begin_comment
comment|/* The current document encoding, or null if not set.  */
end_comment

begin_decl_stmt
specifier|extern
name|encoding_code_type
name|document_encoding_code
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maps an HTML abbreviation to ISO and Unicode codes for a given code.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|short
name|int
name|unicode_t
typedef|;
end_typedef

begin_comment
comment|/* should be 16 bits */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|byte_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|html
decl_stmt|;
comment|/* HTML equivalent like umlaut auml =>&auml; */
name|byte_t
name|bytecode
decl_stmt|;
comment|/* 8-Bit Code (ISO 8859-1,...) */
name|unicode_t
name|unicode
decl_stmt|;
comment|/* Unicode in U+ convention */
block|}
name|iso_map_type
typedef|;
end_typedef

begin_comment
comment|/* Information about the document encoding. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|encoding_code_type
name|ec
decl_stmt|;
comment|/* document encoding type (see above enum) */
name|char
modifier|*
name|ecname
decl_stmt|;
comment|/* encoding name like ISO-8859-1 */
name|iso_map_type
modifier|*
name|isotab
decl_stmt|;
comment|/* address of ISO translation table */
block|}
name|encoding_type
typedef|;
end_typedef

begin_comment
comment|/* Table with all the encoding codes that we recognize.  */
end_comment

begin_decl_stmt
specifier|extern
name|encoding_type
name|encoding_table
index|[]
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* The commands.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cm_documentlanguage
argument_list|()
decl_stmt|,
name|cm_documentencoding
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Accents, other non-English characters.  */
end_comment

begin_decl_stmt
name|void
name|cm_accent
argument_list|()
decl_stmt|,
name|cm_special_char
argument_list|()
decl_stmt|,
name|cm_dotless
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|cm_accent_umlaut
argument_list|()
decl_stmt|,
name|cm_accent_acute
argument_list|()
decl_stmt|,
name|cm_accent_cedilla
argument_list|()
decl_stmt|,
name|cm_accent_hat
argument_list|()
decl_stmt|,
name|cm_accent_grave
argument_list|()
decl_stmt|,
name|cm_accent_tilde
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not LANG_H */
end_comment

end_unit

