begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* reloc.h -- Header file for relocation information.    Copyright 1989, 1990, 1991 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Relocation types for a.out files using reloc_info_extended    (SPARC and AMD 29000). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RELOC_H_READ_
end_ifndef

begin_define
define|#
directive|define
name|_RELOC_H_READ_
value|1
end_define

begin_enum
enum|enum
name|reloc_type
block|{
name|RELOC_8
block|,
name|RELOC_16
block|,
name|RELOC_32
block|,
comment|/* simple relocations */
name|RELOC_DISP8
block|,
name|RELOC_DISP16
block|,
name|RELOC_DISP32
block|,
comment|/* pc-rel displacement */
name|RELOC_WDISP30
block|,
name|RELOC_WDISP22
block|,
name|RELOC_HI22
block|,
name|RELOC_22
block|,
name|RELOC_13
block|,
name|RELOC_LO10
block|,
name|RELOC_SFA_BASE
block|,
name|RELOC_SFA_OFF13
block|,
name|RELOC_BASE10
block|,
name|RELOC_BASE13
block|,
name|RELOC_BASE22
block|,
comment|/* P.I.C. (base-relative) */
name|RELOC_PC10
block|,
name|RELOC_PC22
block|,
comment|/* for some sort of pc-rel P.I.C. (?) */
name|RELOC_JMP_TBL
block|,
comment|/* P.I.C. jump table */
name|RELOC_SEGOFF16
block|,
comment|/* reputedly for shared libraries somehow */
name|RELOC_GLOB_DAT
block|,
name|RELOC_JMP_SLOT
block|,
name|RELOC_RELATIVE
block|,
name|RELOC_11
block|,
name|RELOC_WDISP2_14
block|,
name|RELOC_WDISP19
block|,
name|RELOC_HHI22
block|,
name|RELOC_HLO10
block|,
comment|/* 29K relocation types */
name|RELOC_JUMPTARG
block|,
name|RELOC_CONST
block|,
name|RELOC_CONSTH
block|,
name|RELOC_WDISP14
block|,
name|RELOC_WDISP21
block|,
name|NO_RELOC
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|RELOC_TYPE_NAMES
define|\
value|"8",		"16",		"32",		"DISP8",	\ "DISP16",	"DISP32",	"WDISP30",	"WDISP22",	\ "HI22",		"22",		"13",		"LO10",		\ "SFA_BASE",	"SFAOFF13",	"BASE10",	"BASE13",	\ "BASE22",	"PC10",		"PC22",		"JMP_TBL",	\ "SEGOFF16",	"GLOB_DAT",	"JMP_SLOT",	"RELATIVE",	\ "11",		"WDISP2_14",	"WDISP19", 	"HHI22",	\ "HLO10",							\ "JUMPTARG",	"CONST",	"CONSTH",	"WDISP14",	\ "WDISP21",	\ "NO_RELOC"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RELOC_H_READ_ */
end_comment

begin_comment
comment|/* end of reloc.h */
end_comment

end_unit

