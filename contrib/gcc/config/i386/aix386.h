begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for IBM PS2 running AIX/386 with gas.    From: Minh Tran-Le<TRANLE@intellicorp.com>    Copyright (C) 1988, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*   * This configuration file is for gcc with gas-2.x and gnu ld 2.x  * with aix ps/2 1.3.x.  */
end_comment

begin_comment
comment|/* Define USE_GAS if you have the new version of gas that can handle  * multiple segments and .section pseudo op.  This will allow gcc to  * use the .init section for g++ ctor/dtor.  *  * If you don't have gas then undefined USE_GAS.  You will also have  * to use collect if you want to use g++  */
end_comment

begin_define
define|#
directive|define
name|USE_GAS
end_define

begin_include
include|#
directive|include
file|"i386/aix386ng.h"
end_include

begin_comment
comment|/* Use crt1.o as a startup file and crtn.o as a closing file.    And add crtbegin.o and crtend.o for ctors and dtors */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}} crtbegin.o%s"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
define|\
value|"crtend.o%s crtn.o%s"
end_define

begin_comment
comment|/* Removed the -K flags because the gnu ld does not handle it */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{T*} %{z:-lm}"
end_define

begin_comment
comment|/* Define a few machine-specific details of the implementation of    constructors.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|"\t.section .init,\"x\""
end_define

begin_define
define|#
directive|define
name|CTOR_LIST_BEGIN
define|\
value|asm (INIT_SECTION_ASM_OP);			\   asm ("pushl $0")
end_define

begin_define
define|#
directive|define
name|CTOR_LIST_END
value|CTOR_LIST_BEGIN
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_CONSTRUCTOR
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_CONSTRUCTOR
value|ix86_svr3_asm_out_constructor
end_define

end_unit

