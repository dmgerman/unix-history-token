begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   File CKUXLA.H   Language and Character Set Support for UNIX and VAX/VMS.    This file should be used as a template for the language support files   for other C-Kermit implementations -- Macintosh, OS/2, Amiga, etc. */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKUXLA_H
end_ifndef

begin_define
define|#
directive|define
name|CKUXLA_H
end_define

begin_comment
comment|/* Codes for local file character sets */
end_comment

begin_comment
comment|/* ISO 646 and other ISO-646-like 7-bit sets */
end_comment

begin_define
define|#
directive|define
name|FC_USASCII
value|0
end_define

begin_comment
comment|/* US ASCII */
end_comment

begin_define
define|#
directive|define
name|FC_UKASCII
value|1
end_define

begin_comment
comment|/* United Kingdom ASCII */
end_comment

begin_define
define|#
directive|define
name|FC_DUASCII
value|2
end_define

begin_comment
comment|/* Dutch ISO 646 NRC */
end_comment

begin_define
define|#
directive|define
name|FC_FIASCII
value|3
end_define

begin_comment
comment|/* Finnish ISO 646 NRC */
end_comment

begin_define
define|#
directive|define
name|FC_FRASCII
value|4
end_define

begin_comment
comment|/* French ISO 646 NRC */
end_comment

begin_define
define|#
directive|define
name|FC_FCASCII
value|5
end_define

begin_comment
comment|/* French Canadian ISO 646 NRC */
end_comment

begin_define
define|#
directive|define
name|FC_GEASCII
value|6
end_define

begin_comment
comment|/* German ISO 646 NRC */
end_comment

begin_define
define|#
directive|define
name|FC_HUASCII
value|7
end_define

begin_comment
comment|/* Hungarian ISO 646 NRC */
end_comment

begin_define
define|#
directive|define
name|FC_ITASCII
value|8
end_define

begin_comment
comment|/* Italian *ISO 646 NRC */
end_comment

begin_define
define|#
directive|define
name|FC_NOASCII
value|9
end_define

begin_comment
comment|/* Norwegian and Danish ISO 646 NRC */
end_comment

begin_define
define|#
directive|define
name|FC_POASCII
value|10
end_define

begin_comment
comment|/* Portuguese ISO 646 NRC */
end_comment

begin_define
define|#
directive|define
name|FC_SPASCII
value|11
end_define

begin_comment
comment|/* Spanish ISO 646 NRC */
end_comment

begin_define
define|#
directive|define
name|FC_SWASCII
value|12
end_define

begin_comment
comment|/* Swedish ISO 646 NRC */
end_comment

begin_define
define|#
directive|define
name|FC_CHASCII
value|13
end_define

begin_comment
comment|/* Swiss ISO 646 NRC */
end_comment

begin_comment
comment|/* 8-bit Roman character sets */
end_comment

begin_define
define|#
directive|define
name|FC_1LATIN
value|14
end_define

begin_comment
comment|/* ISO 8859-1 Latin Alphabet 1 */
end_comment

begin_define
define|#
directive|define
name|FC_2LATIN
value|15
end_define

begin_comment
comment|/* ISO 8859-2 Latin Alphabet 2 */
end_comment

begin_define
define|#
directive|define
name|FC_DECMCS
value|16
end_define

begin_comment
comment|/* DEC Multinational Character Set */
end_comment

begin_define
define|#
directive|define
name|FC_NEXT
value|17
end_define

begin_comment
comment|/* NeXT workstation character set */
end_comment

begin_define
define|#
directive|define
name|FC_CP437
value|18
end_define

begin_comment
comment|/* IBM PC Code Page 437 */
end_comment

begin_define
define|#
directive|define
name|FC_CP850
value|19
end_define

begin_comment
comment|/* IBM PC Code Page 850 */
end_comment

begin_define
define|#
directive|define
name|FC_CP852
value|20
end_define

begin_comment
comment|/* IBM PC Code Page 852 */
end_comment

begin_define
define|#
directive|define
name|FC_APPQD
value|22
end_define

begin_comment
comment|/* Apple Quickdraw */
end_comment

begin_define
define|#
directive|define
name|FC_DGMCS
value|22
end_define

begin_comment
comment|/* Data General International Character Set */
end_comment

begin_comment
comment|/* Cyrillic sets */
end_comment

begin_define
define|#
directive|define
name|FC_CYRILL
value|23
end_define

begin_comment
comment|/* ISO 8859-5 Latin/Cyrillic */
end_comment

begin_define
define|#
directive|define
name|FC_CP866
value|24
end_define

begin_comment
comment|/* Microsoft CP866 Cyrillic */
end_comment

begin_define
define|#
directive|define
name|FC_KOI7
value|25
end_define

begin_comment
comment|/* KOI-7 = Short KOI */
end_comment

begin_define
define|#
directive|define
name|FC_KOI8
value|26
end_define

begin_comment
comment|/* KOI-8 */
end_comment

begin_comment
comment|/* Japanese sets */
end_comment

begin_define
define|#
directive|define
name|FC_JIS7
value|27
end_define

begin_comment
comment|/* JIS-7 */
end_comment

begin_define
define|#
directive|define
name|FC_SHJIS
value|28
end_define

begin_comment
comment|/* Shifted JIS = CP932 */
end_comment

begin_define
define|#
directive|define
name|FC_JEUC
value|29
end_define

begin_comment
comment|/* Japanese EUC (JAE) */
end_comment

begin_define
define|#
directive|define
name|FC_JDEC
value|30
end_define

begin_comment
comment|/* Japanese DEC Kanji */
end_comment

begin_define
define|#
directive|define
name|MAXFCSETS
value|30
end_define

begin_comment
comment|/* Highest file character set number */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKUXLA_H */
end_comment

end_unit

