begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for DEC Alpha    running Windows/NT.    Copyright (C) 1995, 1996, 1998, 1999 Free Software Foundation, Inc.     Derived from code       Contributed by Richard Kenner (kenner@vlsi1.ultra.nyu.edu)     Donn Terry, Softway Systems, Inc.     This file contains the code-generation stuff common to the 32-bit    versions of the DEC/Compaq Alpha architecture.  It is shared by    Interix and NT/Win32 ports.   It should not contain compile-time    or run-time dependent environment values (such as compiler options    or anything containing a file or pathname.)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ABI_WINDOWS_NT
end_undef

begin_define
define|#
directive|define
name|TARGET_ABI_WINDOWS_NT
value|1
end_define

begin_comment
comment|/* WinNT (and thus Interix) use unsigned int */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_comment
comment|/* Pointer is 32 bits but the hardware has 64-bit addresses, sign extended.  */
end_comment

begin_undef
undef|#
directive|undef
name|POINTER_SIZE
end_undef

begin_define
define|#
directive|define
name|POINTER_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|POINTERS_EXTEND_UNSIGNED
value|0
end_define

begin_comment
comment|/* We don't change Pmode to the "obvious" SI mode... the above appears    to affect the in-memory size; we want the registers to stay DImode    to match the md file */
end_comment

begin_comment
comment|/* "long" is 32 bits.  */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.     The trampoline should set the static chain pointer to value placed    into the trampoline and should branch to the specified routine.  */
end_comment

begin_undef
undef|#
directive|undef
name|TRAMPOLINE_TEMPLATE
end_undef

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{							\   fprintf (FILE, "\tbr $27,$LTRAMPP\n");		\   fprintf (FILE, "$LTRAMPP:\n\tldl $1,12($27)\n");	\   fprintf (FILE, "\tldl $27,16($27)\n");		\   fprintf (FILE, "\tjmp $31,($27),0\n");		\   fprintf (FILE, "\t.long 0,0\n");			\ }
end_define

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_undef
undef|#
directive|undef
name|TRAMPOLINE_SIZE
end_undef

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|24
end_define

begin_comment
comment|/* The alignment of a trampoline, in bits.  */
end_comment

begin_undef
undef|#
directive|undef
name|TRAMPOLINE_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|TRAMPOLINE_ALIGNMENT
value|32
end_define

begin_comment
comment|/* Emit RTL insns to initialize the variable parts of a trampoline.    FNADDR is an RTX for the address of the function's pure code.    CXT is an RTX for the static chain value for the function.  */
end_comment

begin_undef
undef|#
directive|undef
name|INITIALIZE_TRAMPOLINE
end_undef

begin_define
define|#
directive|define
name|INITIALIZE_TRAMPOLINE
parameter_list|(
name|TRAMP
parameter_list|,
name|FNADDR
parameter_list|,
name|CXT
parameter_list|)
define|\
value|alpha_initialize_trampoline (TRAMP, FNADDR, CXT, 20, 16, 12)
end_define

end_unit

