begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Determine the current selected locale.    Copyright (C) 1995-1999, 2000-2002 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify it    under the terms of the GNU Library General Public License as published    by the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301,    USA.  */
end_comment

begin_comment
comment|/* Written by Ulrich Drepper<drepper@gnu.org>, 1995.  */
end_comment

begin_comment
comment|/* Win32 code written by Tor Lillqvist<tml@iki.fi>.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<locale.h>
end_include

begin_if
if|#
directive|if
name|defined
name|_WIN32
operator|||
name|defined
name|__WIN32__
end_if

begin_undef
undef|#
directive|undef
name|WIN32
end_undef

begin_comment
comment|/* avoid warning on mingw32 */
end_comment

begin_define
define|#
directive|define
name|WIN32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|WIN32
end_ifdef

begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|/* Mingw headers don't have latest language and sublanguage codes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_AFRIKAANS
end_ifndef

begin_define
define|#
directive|define
name|LANG_AFRIKAANS
value|0x36
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_ALBANIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_ALBANIAN
value|0x1c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_ARABIC
end_ifndef

begin_define
define|#
directive|define
name|LANG_ARABIC
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_ARMENIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_ARMENIAN
value|0x2b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_ASSAMESE
end_ifndef

begin_define
define|#
directive|define
name|LANG_ASSAMESE
value|0x4d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_AZERI
end_ifndef

begin_define
define|#
directive|define
name|LANG_AZERI
value|0x2c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_BASQUE
end_ifndef

begin_define
define|#
directive|define
name|LANG_BASQUE
value|0x2d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_BELARUSIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_BELARUSIAN
value|0x23
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_BENGALI
end_ifndef

begin_define
define|#
directive|define
name|LANG_BENGALI
value|0x45
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_CATALAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_CATALAN
value|0x03
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_DIVEHI
end_ifndef

begin_define
define|#
directive|define
name|LANG_DIVEHI
value|0x65
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_ESTONIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_ESTONIAN
value|0x25
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_FAEROESE
end_ifndef

begin_define
define|#
directive|define
name|LANG_FAEROESE
value|0x38
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_FARSI
end_ifndef

begin_define
define|#
directive|define
name|LANG_FARSI
value|0x29
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_GALICIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_GALICIAN
value|0x56
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_GEORGIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_GEORGIAN
value|0x37
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_GUJARATI
end_ifndef

begin_define
define|#
directive|define
name|LANG_GUJARATI
value|0x47
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_HEBREW
end_ifndef

begin_define
define|#
directive|define
name|LANG_HEBREW
value|0x0d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_HINDI
end_ifndef

begin_define
define|#
directive|define
name|LANG_HINDI
value|0x39
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_INDONESIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_INDONESIAN
value|0x21
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_KANNADA
end_ifndef

begin_define
define|#
directive|define
name|LANG_KANNADA
value|0x4b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_KASHMIRI
end_ifndef

begin_define
define|#
directive|define
name|LANG_KASHMIRI
value|0x60
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_KAZAK
end_ifndef

begin_define
define|#
directive|define
name|LANG_KAZAK
value|0x3f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_KONKANI
end_ifndef

begin_define
define|#
directive|define
name|LANG_KONKANI
value|0x57
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_KYRGYZ
end_ifndef

begin_define
define|#
directive|define
name|LANG_KYRGYZ
value|0x40
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_LATVIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_LATVIAN
value|0x26
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_LITHUANIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_LITHUANIAN
value|0x27
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_MACEDONIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_MACEDONIAN
value|0x2f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_MALAY
end_ifndef

begin_define
define|#
directive|define
name|LANG_MALAY
value|0x3e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_MALAYALAM
end_ifndef

begin_define
define|#
directive|define
name|LANG_MALAYALAM
value|0x4c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_MANIPURI
end_ifndef

begin_define
define|#
directive|define
name|LANG_MANIPURI
value|0x58
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_MARATHI
end_ifndef

begin_define
define|#
directive|define
name|LANG_MARATHI
value|0x4e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_MONGOLIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_MONGOLIAN
value|0x50
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_NEPALI
end_ifndef

begin_define
define|#
directive|define
name|LANG_NEPALI
value|0x61
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_ORIYA
end_ifndef

begin_define
define|#
directive|define
name|LANG_ORIYA
value|0x48
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_PUNJABI
end_ifndef

begin_define
define|#
directive|define
name|LANG_PUNJABI
value|0x46
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_SANSKRIT
end_ifndef

begin_define
define|#
directive|define
name|LANG_SANSKRIT
value|0x4f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_SERBIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_SERBIAN
value|0x1a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_SINDHI
end_ifndef

begin_define
define|#
directive|define
name|LANG_SINDHI
value|0x59
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_SLOVAK
end_ifndef

begin_define
define|#
directive|define
name|LANG_SLOVAK
value|0x1b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_SORBIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_SORBIAN
value|0x2e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_SWAHILI
end_ifndef

begin_define
define|#
directive|define
name|LANG_SWAHILI
value|0x41
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_SYRIAC
end_ifndef

begin_define
define|#
directive|define
name|LANG_SYRIAC
value|0x5a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_TAMIL
end_ifndef

begin_define
define|#
directive|define
name|LANG_TAMIL
value|0x49
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_TATAR
end_ifndef

begin_define
define|#
directive|define
name|LANG_TATAR
value|0x44
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_TELUGU
end_ifndef

begin_define
define|#
directive|define
name|LANG_TELUGU
value|0x4a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_THAI
end_ifndef

begin_define
define|#
directive|define
name|LANG_THAI
value|0x1e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_UKRAINIAN
end_ifndef

begin_define
define|#
directive|define
name|LANG_UKRAINIAN
value|0x22
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_URDU
end_ifndef

begin_define
define|#
directive|define
name|LANG_URDU
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_UZBEK
end_ifndef

begin_define
define|#
directive|define
name|LANG_UZBEK
value|0x43
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LANG_VIETNAMESE
end_ifndef

begin_define
define|#
directive|define
name|LANG_VIETNAMESE
value|0x2a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_SAUDI_ARABIA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_SAUDI_ARABIA
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_IRAQ
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_IRAQ
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_EGYPT
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_EGYPT
value|0x03
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_LIBYA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_LIBYA
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_ALGERIA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_ALGERIA
value|0x05
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_MOROCCO
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_MOROCCO
value|0x06
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_TUNISIA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_TUNISIA
value|0x07
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_OMAN
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_OMAN
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_YEMEN
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_YEMEN
value|0x09
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_SYRIA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_SYRIA
value|0x0a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_JORDAN
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_JORDAN
value|0x0b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_LEBANON
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_LEBANON
value|0x0c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_KUWAIT
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_KUWAIT
value|0x0d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_UAE
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_UAE
value|0x0e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_BAHRAIN
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_BAHRAIN
value|0x0f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ARABIC_QATAR
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ARABIC_QATAR
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_AZERI_LATIN
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_AZERI_LATIN
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_AZERI_CYRILLIC
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_AZERI_CYRILLIC
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_CHINESE_MACAU
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_CHINESE_MACAU
value|0x05
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ENGLISH_SOUTH_AFRICA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ENGLISH_SOUTH_AFRICA
value|0x07
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ENGLISH_JAMAICA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ENGLISH_JAMAICA
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ENGLISH_CARIBBEAN
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ENGLISH_CARIBBEAN
value|0x09
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ENGLISH_BELIZE
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ENGLISH_BELIZE
value|0x0a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ENGLISH_TRINIDAD
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ENGLISH_TRINIDAD
value|0x0b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ENGLISH_ZIMBABWE
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ENGLISH_ZIMBABWE
value|0x0c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_ENGLISH_PHILIPPINES
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_ENGLISH_PHILIPPINES
value|0x0d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_FRENCH_LUXEMBOURG
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_FRENCH_LUXEMBOURG
value|0x05
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_FRENCH_MONACO
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_FRENCH_MONACO
value|0x06
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_GERMAN_LUXEMBOURG
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_GERMAN_LUXEMBOURG
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_GERMAN_LIECHTENSTEIN
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_GERMAN_LIECHTENSTEIN
value|0x05
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_KASHMIRI_INDIA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_KASHMIRI_INDIA
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_MALAY_MALAYSIA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_MALAY_MALAYSIA
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_MALAY_BRUNEI_DARUSSALAM
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_MALAY_BRUNEI_DARUSSALAM
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_NEPALI_INDIA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_NEPALI_INDIA
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SERBIAN_LATIN
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SERBIAN_LATIN
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SERBIAN_CYRILLIC
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SERBIAN_CYRILLIC
value|0x03
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_GUATEMALA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_GUATEMALA
value|0x04
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_COSTA_RICA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_COSTA_RICA
value|0x05
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_PANAMA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_PANAMA
value|0x06
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_DOMINICAN_REPUBLIC
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_DOMINICAN_REPUBLIC
value|0x07
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_VENEZUELA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_VENEZUELA
value|0x08
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_COLOMBIA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_COLOMBIA
value|0x09
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_PERU
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_PERU
value|0x0a
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_ARGENTINA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_ARGENTINA
value|0x0b
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_ECUADOR
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_ECUADOR
value|0x0c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_CHILE
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_CHILE
value|0x0d
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_URUGUAY
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_URUGUAY
value|0x0e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_PARAGUAY
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_PARAGUAY
value|0x0f
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_BOLIVIA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_BOLIVIA
value|0x10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_EL_SALVADOR
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_EL_SALVADOR
value|0x11
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_HONDURAS
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_HONDURAS
value|0x12
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_NICARAGUA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_NICARAGUA
value|0x13
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SPANISH_PUERTO_RICO
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SPANISH_PUERTO_RICO
value|0x14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_SWEDISH_FINLAND
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_SWEDISH_FINLAND
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_URDU_PAKISTAN
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_URDU_PAKISTAN
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_URDU_INDIA
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_URDU_INDIA
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_UZBEK_LATIN
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_UZBEK_LATIN
value|0x01
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBLANG_UZBEK_CYRILLIC
end_ifndef

begin_define
define|#
directive|define
name|SUBLANG_UZBEK_CYRILLIC
value|0x02
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XPG3 defines the result of 'setlocale (category, NULL)' as:    "Directs 'setlocale()' to query 'category' and return the current     setting of 'local'."    However it does not specify the exact format.  Neither do SUSV2 and    ISO C 99.  So we can use this feature only on selected systems (e.g.    those using GNU C Library).  */
end_comment

begin_if
if|#
directive|if
name|defined
name|_LIBC
operator|||
operator|(
name|defined
name|__GNU_LIBRARY__
operator|&&
name|__GNU_LIBRARY__
operator|>=
literal|2
operator|)
end_if

begin_define
define|#
directive|define
name|HAVE_LOCALE_NULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Determine the current locale's name, and canonicalize it into XPG syntax      language[_territory[.codeset]][@modifier]    The codeset part in the result is not reliable; the locale_charset()    should be used for codeset information instead.    The result must not be freed; it is statically allocated.  */
end_comment

begin_function
specifier|const
name|char
modifier|*
name|_nl_locale_name
parameter_list|(
name|category
parameter_list|,
name|categoryname
parameter_list|)
name|int
name|category
decl_stmt|;
specifier|const
name|char
modifier|*
name|categoryname
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
name|retval
decl_stmt|;
ifndef|#
directive|ifndef
name|WIN32
comment|/* Use the POSIX methods of looking to 'LC_ALL', 'LC_xxx', and 'LANG'.      On some systems this can be done by the 'setlocale' function itself.  */
if|#
directive|if
name|defined
name|HAVE_SETLOCALE
operator|&&
name|defined
name|HAVE_LC_MESSAGES
operator|&&
name|defined
name|HAVE_LOCALE_NULL
name|retval
operator|=
name|setlocale
argument_list|(
name|category
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Setting of LC_ALL overwrites all other.  */
name|retval
operator|=
name|getenv
argument_list|(
literal|"LC_ALL"
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
operator|==
name|NULL
operator|||
name|retval
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
comment|/* Next comes the name of the desired category.  */
name|retval
operator|=
name|getenv
argument_list|(
name|categoryname
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
operator|==
name|NULL
operator|||
name|retval
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
block|{
comment|/* Last possibility is the LANG environment variable.  */
name|retval
operator|=
name|getenv
argument_list|(
literal|"LANG"
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
operator|==
name|NULL
operator|||
name|retval
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
comment|/* We use C as the default domain.  POSIX says this is 	       implementation defined.  */
name|retval
operator|=
literal|"C"
expr_stmt|;
block|}
block|}
endif|#
directive|endif
return|return
name|retval
return|;
else|#
directive|else
comment|/* WIN32 */
comment|/* Return an XPG style locale name language[_territory][@modifier].      Don't even bother determining the codeset; it's not useful in this      context, because message catalogs are not specific to a single      codeset.  */
name|LCID
name|lcid
decl_stmt|;
name|LANGID
name|langid
decl_stmt|;
name|int
name|primary
decl_stmt|,
name|sub
decl_stmt|;
comment|/* Let the user override the system settings through environment      variables, as on POSIX systems.  */
name|retval
operator|=
name|getenv
argument_list|(
literal|"LC_ALL"
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
operator|!=
name|NULL
operator|&&
name|retval
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
return|return
name|retval
return|;
name|retval
operator|=
name|getenv
argument_list|(
name|categoryname
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
operator|!=
name|NULL
operator|&&
name|retval
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
return|return
name|retval
return|;
name|retval
operator|=
name|getenv
argument_list|(
literal|"LANG"
argument_list|)
expr_stmt|;
if|if
condition|(
name|retval
operator|!=
name|NULL
operator|&&
name|retval
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
return|return
name|retval
return|;
comment|/* Use native Win32 API locale ID.  */
name|lcid
operator|=
name|GetThreadLocale
argument_list|()
expr_stmt|;
comment|/* Strip off the sorting rules, keep only the language part.  */
name|langid
operator|=
name|LANGIDFROMLCID
argument_list|(
name|lcid
argument_list|)
expr_stmt|;
comment|/* Split into language and territory part.  */
name|primary
operator|=
name|PRIMARYLANGID
argument_list|(
name|langid
argument_list|)
expr_stmt|;
name|sub
operator|=
name|SUBLANGID
argument_list|(
name|langid
argument_list|)
expr_stmt|;
comment|/* Dispatch on language.      See also http://www.unicode.org/unicode/onlinedat/languages.html .      For details about languages, see http://www.ethnologue.com/ .  */
switch|switch
condition|(
name|primary
condition|)
block|{
case|case
name|LANG_AFRIKAANS
case|:
return|return
literal|"af_ZA"
return|;
case|case
name|LANG_ALBANIAN
case|:
return|return
literal|"sq_AL"
return|;
case|case
literal|0x5e
case|:
comment|/* AMHARIC */
return|return
literal|"am_ET"
return|;
case|case
name|LANG_ARABIC
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_ARABIC_SAUDI_ARABIA
case|:
return|return
literal|"ar_SA"
return|;
case|case
name|SUBLANG_ARABIC_IRAQ
case|:
return|return
literal|"ar_IQ"
return|;
case|case
name|SUBLANG_ARABIC_EGYPT
case|:
return|return
literal|"ar_EG"
return|;
case|case
name|SUBLANG_ARABIC_LIBYA
case|:
return|return
literal|"ar_LY"
return|;
case|case
name|SUBLANG_ARABIC_ALGERIA
case|:
return|return
literal|"ar_DZ"
return|;
case|case
name|SUBLANG_ARABIC_MOROCCO
case|:
return|return
literal|"ar_MA"
return|;
case|case
name|SUBLANG_ARABIC_TUNISIA
case|:
return|return
literal|"ar_TN"
return|;
case|case
name|SUBLANG_ARABIC_OMAN
case|:
return|return
literal|"ar_OM"
return|;
case|case
name|SUBLANG_ARABIC_YEMEN
case|:
return|return
literal|"ar_YE"
return|;
case|case
name|SUBLANG_ARABIC_SYRIA
case|:
return|return
literal|"ar_SY"
return|;
case|case
name|SUBLANG_ARABIC_JORDAN
case|:
return|return
literal|"ar_JO"
return|;
case|case
name|SUBLANG_ARABIC_LEBANON
case|:
return|return
literal|"ar_LB"
return|;
case|case
name|SUBLANG_ARABIC_KUWAIT
case|:
return|return
literal|"ar_KW"
return|;
case|case
name|SUBLANG_ARABIC_UAE
case|:
return|return
literal|"ar_AE"
return|;
case|case
name|SUBLANG_ARABIC_BAHRAIN
case|:
return|return
literal|"ar_BH"
return|;
case|case
name|SUBLANG_ARABIC_QATAR
case|:
return|return
literal|"ar_QA"
return|;
block|}
return|return
literal|"ar"
return|;
case|case
name|LANG_ARMENIAN
case|:
return|return
literal|"hy_AM"
return|;
case|case
name|LANG_ASSAMESE
case|:
return|return
literal|"as_IN"
return|;
case|case
name|LANG_AZERI
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
comment|/* FIXME: Adjust this when Azerbaijani locales appear on Unix.  */
case|case
name|SUBLANG_AZERI_LATIN
case|:
return|return
literal|"az_AZ@latin"
return|;
case|case
name|SUBLANG_AZERI_CYRILLIC
case|:
return|return
literal|"az_AZ@cyrillic"
return|;
block|}
return|return
literal|"az"
return|;
case|case
name|LANG_BASQUE
case|:
return|return
literal|"eu"
return|;
comment|/* Ambiguous: could be "eu_ES" or "eu_FR".  */
case|case
name|LANG_BELARUSIAN
case|:
return|return
literal|"be_BY"
return|;
case|case
name|LANG_BENGALI
case|:
return|return
literal|"bn_IN"
return|;
case|case
name|LANG_BULGARIAN
case|:
return|return
literal|"bg_BG"
return|;
case|case
literal|0x55
case|:
comment|/* BURMESE */
return|return
literal|"my_MM"
return|;
case|case
literal|0x53
case|:
comment|/* CAMBODIAN */
return|return
literal|"km_KH"
return|;
case|case
name|LANG_CATALAN
case|:
return|return
literal|"ca_ES"
return|;
case|case
literal|0x5c
case|:
comment|/* CHEROKEE */
return|return
literal|"chr_US"
return|;
case|case
name|LANG_CHINESE
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_CHINESE_TRADITIONAL
case|:
return|return
literal|"zh_TW"
return|;
case|case
name|SUBLANG_CHINESE_SIMPLIFIED
case|:
return|return
literal|"zh_CN"
return|;
case|case
name|SUBLANG_CHINESE_HONGKONG
case|:
return|return
literal|"zh_HK"
return|;
case|case
name|SUBLANG_CHINESE_SINGAPORE
case|:
return|return
literal|"zh_SG"
return|;
case|case
name|SUBLANG_CHINESE_MACAU
case|:
return|return
literal|"zh_MO"
return|;
block|}
return|return
literal|"zh"
return|;
case|case
name|LANG_CROATIAN
case|:
comment|/* LANG_CROATIAN == LANG_SERBIAN 				 * What used to be called Serbo-Croatian 				 * should really now be two separate 				 * languages because of political reasons. 				 * (Says tml, who knows nothing about Serbian 				 * or Croatian.) 				 * (I can feel those flames coming already.) 				 */
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_DEFAULT
case|:
return|return
literal|"hr_HR"
return|;
case|case
name|SUBLANG_SERBIAN_LATIN
case|:
return|return
literal|"sr_YU"
return|;
case|case
name|SUBLANG_SERBIAN_CYRILLIC
case|:
return|return
literal|"sr_YU@cyrillic"
return|;
block|}
return|return
literal|"hr"
return|;
case|case
name|LANG_CZECH
case|:
return|return
literal|"cs_CZ"
return|;
case|case
name|LANG_DANISH
case|:
return|return
literal|"da_DK"
return|;
case|case
name|LANG_DIVEHI
case|:
return|return
literal|"div_MV"
return|;
case|case
name|LANG_DUTCH
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_DUTCH
case|:
return|return
literal|"nl_NL"
return|;
case|case
name|SUBLANG_DUTCH_BELGIAN
case|:
comment|/* FLEMISH, VLAAMS */
return|return
literal|"nl_BE"
return|;
block|}
return|return
literal|"nl"
return|;
case|case
literal|0x66
case|:
comment|/* EDO */
return|return
literal|"bin_NG"
return|;
case|case
name|LANG_ENGLISH
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
comment|/* SUBLANG_ENGLISH_US == SUBLANG_DEFAULT. Heh. I thought 	 * English was the language spoken in England. 	 * Oh well. 	 */
case|case
name|SUBLANG_ENGLISH_US
case|:
return|return
literal|"en_US"
return|;
case|case
name|SUBLANG_ENGLISH_UK
case|:
return|return
literal|"en_GB"
return|;
case|case
name|SUBLANG_ENGLISH_AUS
case|:
return|return
literal|"en_AU"
return|;
case|case
name|SUBLANG_ENGLISH_CAN
case|:
return|return
literal|"en_CA"
return|;
case|case
name|SUBLANG_ENGLISH_NZ
case|:
return|return
literal|"en_NZ"
return|;
case|case
name|SUBLANG_ENGLISH_EIRE
case|:
return|return
literal|"en_IE"
return|;
case|case
name|SUBLANG_ENGLISH_SOUTH_AFRICA
case|:
return|return
literal|"en_ZA"
return|;
case|case
name|SUBLANG_ENGLISH_JAMAICA
case|:
return|return
literal|"en_JM"
return|;
case|case
name|SUBLANG_ENGLISH_CARIBBEAN
case|:
return|return
literal|"en_GD"
return|;
comment|/* Grenada? */
case|case
name|SUBLANG_ENGLISH_BELIZE
case|:
return|return
literal|"en_BZ"
return|;
case|case
name|SUBLANG_ENGLISH_TRINIDAD
case|:
return|return
literal|"en_TT"
return|;
case|case
name|SUBLANG_ENGLISH_ZIMBABWE
case|:
return|return
literal|"en_ZW"
return|;
case|case
name|SUBLANG_ENGLISH_PHILIPPINES
case|:
return|return
literal|"en_PH"
return|;
block|}
return|return
literal|"en"
return|;
case|case
name|LANG_ESTONIAN
case|:
return|return
literal|"et_EE"
return|;
case|case
name|LANG_FAEROESE
case|:
return|return
literal|"fo_FO"
return|;
case|case
name|LANG_FARSI
case|:
return|return
literal|"fa_IR"
return|;
case|case
name|LANG_FINNISH
case|:
return|return
literal|"fi_FI"
return|;
case|case
name|LANG_FRENCH
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_FRENCH
case|:
return|return
literal|"fr_FR"
return|;
case|case
name|SUBLANG_FRENCH_BELGIAN
case|:
comment|/* WALLOON */
return|return
literal|"fr_BE"
return|;
case|case
name|SUBLANG_FRENCH_CANADIAN
case|:
return|return
literal|"fr_CA"
return|;
case|case
name|SUBLANG_FRENCH_SWISS
case|:
return|return
literal|"fr_CH"
return|;
case|case
name|SUBLANG_FRENCH_LUXEMBOURG
case|:
return|return
literal|"fr_LU"
return|;
case|case
name|SUBLANG_FRENCH_MONACO
case|:
return|return
literal|"fr_MC"
return|;
block|}
return|return
literal|"fr"
return|;
case|case
literal|0x62
case|:
comment|/* FRISIAN */
return|return
literal|"fy_NL"
return|;
case|case
literal|0x67
case|:
comment|/* FULFULDE */
return|return
literal|"ful_NG"
return|;
case|case
literal|0x3c
case|:
comment|/* GAELIC */
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
literal|0x01
case|:
comment|/* SCOTTISH */
return|return
literal|"gd_GB"
return|;
case|case
literal|0x02
case|:
comment|/* IRISH */
return|return
literal|"ga_IE"
return|;
block|}
return|return
literal|"C"
return|;
case|case
name|LANG_GALICIAN
case|:
return|return
literal|"gl_ES"
return|;
case|case
name|LANG_GEORGIAN
case|:
return|return
literal|"ka_GE"
return|;
case|case
name|LANG_GERMAN
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_GERMAN
case|:
return|return
literal|"de_DE"
return|;
case|case
name|SUBLANG_GERMAN_SWISS
case|:
return|return
literal|"de_CH"
return|;
case|case
name|SUBLANG_GERMAN_AUSTRIAN
case|:
return|return
literal|"de_AT"
return|;
case|case
name|SUBLANG_GERMAN_LUXEMBOURG
case|:
return|return
literal|"de_LU"
return|;
case|case
name|SUBLANG_GERMAN_LIECHTENSTEIN
case|:
return|return
literal|"de_LI"
return|;
block|}
return|return
literal|"de"
return|;
case|case
name|LANG_GREEK
case|:
return|return
literal|"el_GR"
return|;
case|case
literal|0x74
case|:
comment|/* GUARANI */
return|return
literal|"gn_PY"
return|;
case|case
name|LANG_GUJARATI
case|:
return|return
literal|"gu_IN"
return|;
case|case
literal|0x68
case|:
comment|/* HAUSA */
return|return
literal|"ha_NG"
return|;
case|case
literal|0x75
case|:
comment|/* HAWAIIAN */
comment|/* FIXME: Do they mean Hawaiian ("haw_US", 1000 speakers) 	 or Hawaii Creole English ("cpe_US", 600000 speakers)?  */
return|return
literal|"cpe_US"
return|;
case|case
name|LANG_HEBREW
case|:
return|return
literal|"he_IL"
return|;
case|case
name|LANG_HINDI
case|:
return|return
literal|"hi_IN"
return|;
case|case
name|LANG_HUNGARIAN
case|:
return|return
literal|"hu_HU"
return|;
case|case
literal|0x69
case|:
comment|/* IBIBIO */
return|return
literal|"nic_NG"
return|;
case|case
name|LANG_ICELANDIC
case|:
return|return
literal|"is_IS"
return|;
case|case
literal|0x70
case|:
comment|/* IGBO */
return|return
literal|"ibo_NG"
return|;
case|case
name|LANG_INDONESIAN
case|:
return|return
literal|"id_ID"
return|;
case|case
literal|0x5d
case|:
comment|/* INUKTITUT */
return|return
literal|"iu_CA"
return|;
case|case
name|LANG_ITALIAN
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_ITALIAN
case|:
return|return
literal|"it_IT"
return|;
case|case
name|SUBLANG_ITALIAN_SWISS
case|:
return|return
literal|"it_CH"
return|;
block|}
return|return
literal|"it"
return|;
case|case
name|LANG_JAPANESE
case|:
return|return
literal|"ja_JP"
return|;
case|case
name|LANG_KANNADA
case|:
return|return
literal|"kn_IN"
return|;
case|case
literal|0x71
case|:
comment|/* KANURI */
return|return
literal|"kau_NG"
return|;
case|case
name|LANG_KASHMIRI
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_DEFAULT
case|:
return|return
literal|"ks_PK"
return|;
case|case
name|SUBLANG_KASHMIRI_INDIA
case|:
return|return
literal|"ks_IN"
return|;
block|}
return|return
literal|"ks"
return|;
case|case
name|LANG_KAZAK
case|:
return|return
literal|"kk_KZ"
return|;
case|case
name|LANG_KONKANI
case|:
comment|/* FIXME: Adjust this when such locales appear on Unix.  */
return|return
literal|"kok_IN"
return|;
case|case
name|LANG_KOREAN
case|:
return|return
literal|"ko_KR"
return|;
case|case
name|LANG_KYRGYZ
case|:
return|return
literal|"ky_KG"
return|;
case|case
literal|0x54
case|:
comment|/* LAO */
return|return
literal|"lo_LA"
return|;
case|case
literal|0x76
case|:
comment|/* LATIN */
return|return
literal|"la_VA"
return|;
case|case
name|LANG_LATVIAN
case|:
return|return
literal|"lv_LV"
return|;
case|case
name|LANG_LITHUANIAN
case|:
return|return
literal|"lt_LT"
return|;
case|case
name|LANG_MACEDONIAN
case|:
return|return
literal|"mk_MK"
return|;
case|case
name|LANG_MALAY
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_MALAY_MALAYSIA
case|:
return|return
literal|"ms_MY"
return|;
case|case
name|SUBLANG_MALAY_BRUNEI_DARUSSALAM
case|:
return|return
literal|"ms_BN"
return|;
block|}
return|return
literal|"ms"
return|;
case|case
name|LANG_MALAYALAM
case|:
return|return
literal|"ml_IN"
return|;
case|case
literal|0x3a
case|:
comment|/* MALTESE */
return|return
literal|"mt_MT"
return|;
case|case
name|LANG_MANIPURI
case|:
comment|/* FIXME: Adjust this when such locales appear on Unix.  */
return|return
literal|"mni_IN"
return|;
case|case
name|LANG_MARATHI
case|:
return|return
literal|"mr_IN"
return|;
case|case
name|LANG_MONGOLIAN
case|:
return|return
literal|"mn"
return|;
comment|/* Ambiguous: could be "mn_CN" or "mn_MN".  */
case|case
name|LANG_NEPALI
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_DEFAULT
case|:
return|return
literal|"ne_NP"
return|;
case|case
name|SUBLANG_NEPALI_INDIA
case|:
return|return
literal|"ne_IN"
return|;
block|}
return|return
literal|"ne"
return|;
case|case
name|LANG_NORWEGIAN
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_NORWEGIAN_BOKMAL
case|:
return|return
literal|"no_NO"
return|;
case|case
name|SUBLANG_NORWEGIAN_NYNORSK
case|:
return|return
literal|"nn_NO"
return|;
block|}
return|return
literal|"no"
return|;
case|case
name|LANG_ORIYA
case|:
return|return
literal|"or_IN"
return|;
case|case
literal|0x72
case|:
comment|/* OROMO */
return|return
literal|"om_ET"
return|;
case|case
literal|0x79
case|:
comment|/* PAPIAMENTU */
return|return
literal|"pap_AN"
return|;
case|case
literal|0x63
case|:
comment|/* PASHTO */
return|return
literal|"ps"
return|;
comment|/* Ambiguous: could be "ps_PK" or "ps_AF".  */
case|case
name|LANG_POLISH
case|:
return|return
literal|"pl_PL"
return|;
case|case
name|LANG_PORTUGUESE
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_PORTUGUESE
case|:
return|return
literal|"pt_PT"
return|;
comment|/* Hmm. SUBLANG_PORTUGUESE_BRAZILIAN == SUBLANG_DEFAULT. 	   Same phenomenon as SUBLANG_ENGLISH_US == SUBLANG_DEFAULT. */
case|case
name|SUBLANG_PORTUGUESE_BRAZILIAN
case|:
return|return
literal|"pt_BR"
return|;
block|}
return|return
literal|"pt"
return|;
case|case
name|LANG_PUNJABI
case|:
return|return
literal|"pa_IN"
return|;
case|case
literal|0x17
case|:
comment|/* RHAETO-ROMANCE */
return|return
literal|"rm_CH"
return|;
case|case
name|LANG_ROMANIAN
case|:
return|return
literal|"ro_RO"
return|;
case|case
name|LANG_RUSSIAN
case|:
return|return
literal|"ru"
return|;
comment|/* Ambiguous: could be "ru_RU" or "ru_UA".  */
case|case
literal|0x3b
case|:
comment|/* SAMI */
return|return
literal|"se_NO"
return|;
case|case
name|LANG_SANSKRIT
case|:
return|return
literal|"sa_IN"
return|;
case|case
name|LANG_SINDHI
case|:
return|return
literal|"sd"
return|;
case|case
literal|0x5b
case|:
comment|/* SINHALESE */
return|return
literal|"si_LK"
return|;
case|case
name|LANG_SLOVAK
case|:
return|return
literal|"sk_SK"
return|;
case|case
name|LANG_SLOVENIAN
case|:
return|return
literal|"sl_SI"
return|;
case|case
literal|0x77
case|:
comment|/* SOMALI */
return|return
literal|"so_SO"
return|;
case|case
name|LANG_SORBIAN
case|:
comment|/* FIXME: Adjust this when such locales appear on Unix.  */
return|return
literal|"wen_DE"
return|;
case|case
name|LANG_SPANISH
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_SPANISH
case|:
return|return
literal|"es_ES"
return|;
case|case
name|SUBLANG_SPANISH_MEXICAN
case|:
return|return
literal|"es_MX"
return|;
case|case
name|SUBLANG_SPANISH_MODERN
case|:
return|return
literal|"es_ES@modern"
return|;
comment|/* not seen on Unix */
case|case
name|SUBLANG_SPANISH_GUATEMALA
case|:
return|return
literal|"es_GT"
return|;
case|case
name|SUBLANG_SPANISH_COSTA_RICA
case|:
return|return
literal|"es_CR"
return|;
case|case
name|SUBLANG_SPANISH_PANAMA
case|:
return|return
literal|"es_PA"
return|;
case|case
name|SUBLANG_SPANISH_DOMINICAN_REPUBLIC
case|:
return|return
literal|"es_DO"
return|;
case|case
name|SUBLANG_SPANISH_VENEZUELA
case|:
return|return
literal|"es_VE"
return|;
case|case
name|SUBLANG_SPANISH_COLOMBIA
case|:
return|return
literal|"es_CO"
return|;
case|case
name|SUBLANG_SPANISH_PERU
case|:
return|return
literal|"es_PE"
return|;
case|case
name|SUBLANG_SPANISH_ARGENTINA
case|:
return|return
literal|"es_AR"
return|;
case|case
name|SUBLANG_SPANISH_ECUADOR
case|:
return|return
literal|"es_EC"
return|;
case|case
name|SUBLANG_SPANISH_CHILE
case|:
return|return
literal|"es_CL"
return|;
case|case
name|SUBLANG_SPANISH_URUGUAY
case|:
return|return
literal|"es_UY"
return|;
case|case
name|SUBLANG_SPANISH_PARAGUAY
case|:
return|return
literal|"es_PY"
return|;
case|case
name|SUBLANG_SPANISH_BOLIVIA
case|:
return|return
literal|"es_BO"
return|;
case|case
name|SUBLANG_SPANISH_EL_SALVADOR
case|:
return|return
literal|"es_SV"
return|;
case|case
name|SUBLANG_SPANISH_HONDURAS
case|:
return|return
literal|"es_HN"
return|;
case|case
name|SUBLANG_SPANISH_NICARAGUA
case|:
return|return
literal|"es_NI"
return|;
case|case
name|SUBLANG_SPANISH_PUERTO_RICO
case|:
return|return
literal|"es_PR"
return|;
block|}
return|return
literal|"es"
return|;
case|case
literal|0x30
case|:
comment|/* SUTU */
return|return
literal|"bnt_TZ"
return|;
case|case
name|LANG_SWAHILI
case|:
return|return
literal|"sw_KE"
return|;
case|case
name|LANG_SWEDISH
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_DEFAULT
case|:
return|return
literal|"sv_SE"
return|;
case|case
name|SUBLANG_SWEDISH_FINLAND
case|:
return|return
literal|"sv_FI"
return|;
block|}
return|return
literal|"sv"
return|;
case|case
name|LANG_SYRIAC
case|:
return|return
literal|"syr_TR"
return|;
comment|/* An extinct language.  */
case|case
literal|0x64
case|:
comment|/* TAGALOG */
return|return
literal|"tl_PH"
return|;
case|case
literal|0x28
case|:
comment|/* TAJIK */
return|return
literal|"tg_TJ"
return|;
case|case
literal|0x5f
case|:
comment|/* TAMAZIGHT */
return|return
literal|"ber_MA"
return|;
case|case
name|LANG_TAMIL
case|:
return|return
literal|"ta"
return|;
comment|/* Ambiguous: could be "ta_IN" or "ta_LK" or "ta_SG".  */
case|case
name|LANG_TATAR
case|:
return|return
literal|"tt_RU"
return|;
case|case
name|LANG_TELUGU
case|:
return|return
literal|"te_IN"
return|;
case|case
name|LANG_THAI
case|:
return|return
literal|"th_TH"
return|;
case|case
literal|0x51
case|:
comment|/* TIBETAN */
return|return
literal|"bo_CN"
return|;
case|case
literal|0x73
case|:
comment|/* TIGRINYA */
return|return
literal|"ti_ET"
return|;
case|case
literal|0x31
case|:
comment|/* TSONGA */
return|return
literal|"ts_ZA"
return|;
case|case
name|LANG_TURKISH
case|:
return|return
literal|"tr_TR"
return|;
case|case
literal|0x42
case|:
comment|/* TURKMEN */
return|return
literal|"tk_TM"
return|;
case|case
name|LANG_UKRAINIAN
case|:
return|return
literal|"uk_UA"
return|;
case|case
name|LANG_URDU
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
case|case
name|SUBLANG_URDU_PAKISTAN
case|:
return|return
literal|"ur_PK"
return|;
case|case
name|SUBLANG_URDU_INDIA
case|:
return|return
literal|"ur_IN"
return|;
block|}
return|return
literal|"ur"
return|;
case|case
name|LANG_UZBEK
case|:
switch|switch
condition|(
name|sub
condition|)
block|{
comment|/* FIXME: Adjust this when Uzbek locales appear on Unix.  */
case|case
name|SUBLANG_UZBEK_LATIN
case|:
return|return
literal|"uz_UZ@latin"
return|;
case|case
name|SUBLANG_UZBEK_CYRILLIC
case|:
return|return
literal|"uz_UZ@cyrillic"
return|;
block|}
return|return
literal|"uz"
return|;
case|case
literal|0x33
case|:
comment|/* VENDA */
return|return
literal|"ven_ZA"
return|;
case|case
name|LANG_VIETNAMESE
case|:
return|return
literal|"vi_VN"
return|;
case|case
literal|0x52
case|:
comment|/* WELSH */
return|return
literal|"cy_GB"
return|;
case|case
literal|0x34
case|:
comment|/* XHOSA */
return|return
literal|"xh_ZA"
return|;
case|case
literal|0x78
case|:
comment|/* YI */
return|return
literal|"sit_CN"
return|;
case|case
literal|0x3d
case|:
comment|/* YIDDISH */
return|return
literal|"yi_IL"
return|;
case|case
literal|0x6a
case|:
comment|/* YORUBA */
return|return
literal|"yo_NG"
return|;
case|case
literal|0x35
case|:
comment|/* ZULU */
return|return
literal|"zu_ZA"
return|;
default|default:
return|return
literal|"C"
return|;
block|}
endif|#
directive|endif
block|}
end_function

end_unit

