begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* infokey.h -- Custom keystroke definition support.    $Id: $     Copyright (C) 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Andrew Bettison<andrewb@zip.com.au>.     This design was derived from the "lesskey" system in less 3.4.0. by    Mark Nudelman.     The following terminology is confusing: 	source file = $HOME/.infokey 	infokey file = $HOME/.info    Oh, well.  */
end_comment

begin_comment
comment|/* Default source file, where user writes text definitions to be    compiled to the infokey file.  MS-DOS doesn't allow leading    dots in file names.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MSDOS__
end_ifdef

begin_define
define|#
directive|define
name|INFOKEY_SRCFILE
value|"_infokey"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INFOKEY_SRCFILE
value|".infokey"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default "infokey file", where compiled user defs are kept and    read by Info.  MS-DOS doesn't allow leading dots in file names.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__MSDOS__
end_ifdef

begin_define
define|#
directive|define
name|INFOKEY_FILE
value|"_info"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INFOKEY_FILE
value|".info"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Format of entire infokey file:  	4 bytes		magic number S 	X bytes		version string 	1 byte '\0'	terminator  	any number of sections: 		1 byte		section id 		2 bytes		section length (N) 		N bytes		section definitions: format depends on section  	4 bytes		magic number E  Format of INFO and EA sections: 	 	1 byte		flag: 1 == suppress default key bindings 	Repeat: 		X bytes		key sequence 		1 byte '\0'	terminator 		1 byte		action code (A_xxx)  Format of VAR section: 	 	Repeat: 		X bytes		variable name 		1 byte '\0'	terminator 		Y bytes		value 		1 byte '\0'	terminator  */
end_comment

begin_define
define|#
directive|define
name|INFOKEY_NMAGIC
value|8
end_define

begin_define
define|#
directive|define
name|INFOKEY_MAGIC_S0
value|'\001'
end_define

begin_define
define|#
directive|define
name|INFOKEY_MAGIC_S1
value|'I'
end_define

begin_define
define|#
directive|define
name|INFOKEY_MAGIC_S2
value|'n'
end_define

begin_define
define|#
directive|define
name|INFOKEY_MAGIC_S3
value|'f'
end_define

begin_define
define|#
directive|define
name|INFOKEY_SECTION_INFO
value|'i'
end_define

begin_define
define|#
directive|define
name|INFOKEY_SECTION_EA
value|'e'
end_define

begin_define
define|#
directive|define
name|INFOKEY_SECTION_VAR
value|'v'
end_define

begin_define
define|#
directive|define
name|INFOKEY_MAGIC_E0
value|'A'
end_define

begin_define
define|#
directive|define
name|INFOKEY_MAGIC_E1
value|'l'
end_define

begin_define
define|#
directive|define
name|INFOKEY_MAGIC_E2
value|'f'
end_define

begin_define
define|#
directive|define
name|INFOKEY_MAGIC_E3
value|'n'
end_define

begin_define
define|#
directive|define
name|INFOKEY_RADIX
value|64
end_define

begin_define
define|#
directive|define
name|INFOKEY_MAX_SECTIONLEN
value|500
end_define

begin_define
define|#
directive|define
name|INFOKEY_MAX_DEFLEN
value|16
end_define

begin_define
define|#
directive|define
name|A_MAX_COMMAND
value|120
end_define

begin_define
define|#
directive|define
name|A_INVALID
value|121
end_define

begin_comment
comment|/* Character transformations (independent of info's own) */
end_comment

begin_define
define|#
directive|define
name|CONTROL
parameter_list|(
name|c
parameter_list|)
value|((c)& 0x1f)
end_define

begin_define
define|#
directive|define
name|ISCONTROL
parameter_list|(
name|c
parameter_list|)
value|(((c)& ~0x1f) == 0)
end_define

begin_define
define|#
directive|define
name|META
parameter_list|(
name|c
parameter_list|)
value|((c) | 0x80)
end_define

begin_define
define|#
directive|define
name|UNMETA
parameter_list|(
name|c
parameter_list|)
value|((c)& ~0x80)
end_define

begin_define
define|#
directive|define
name|ISMETA
parameter_list|(
name|c
parameter_list|)
value|(((c)& 0x80) != 0)
end_define

begin_comment
comment|/* Special keys (keys which output different strings on different terminals) */
end_comment

begin_define
define|#
directive|define
name|SK_ESCAPE
value|CONTROL('k')
end_define

begin_define
define|#
directive|define
name|SK_RIGHT_ARROW
value|1
end_define

begin_define
define|#
directive|define
name|SK_LEFT_ARROW
value|2
end_define

begin_define
define|#
directive|define
name|SK_UP_ARROW
value|3
end_define

begin_define
define|#
directive|define
name|SK_DOWN_ARROW
value|4
end_define

begin_define
define|#
directive|define
name|SK_PAGE_UP
value|5
end_define

begin_define
define|#
directive|define
name|SK_PAGE_DOWN
value|6
end_define

begin_define
define|#
directive|define
name|SK_HOME
value|7
end_define

begin_define
define|#
directive|define
name|SK_END
value|8
end_define

begin_define
define|#
directive|define
name|SK_DELETE
value|9
end_define

begin_define
define|#
directive|define
name|SK_INSERT
value|10
end_define

begin_define
define|#
directive|define
name|SK_CTL_LEFT_ARROW
value|11
end_define

begin_define
define|#
directive|define
name|SK_CTL_RIGHT_ARROW
value|12
end_define

begin_define
define|#
directive|define
name|SK_CTL_DELETE
value|13
end_define

begin_define
define|#
directive|define
name|SK_LITERAL
value|40
end_define

end_unit

