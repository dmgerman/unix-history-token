begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386 running under the win32 API Unix.    Copyright 1995, 1996 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/tm-i386v.h"
end_include

begin_undef
undef|#
directive|undef
name|MAX_REGISTER_RAW_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|MAX_REGISTER_VIRTUAL_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_undef
undef|#
directive|undef
name|REGISTER_BYTE
end_undef

begin_undef
undef|#
directive|undef
name|REGISTER_BYTES
end_undef

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERTIBLE
end_undef

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERT_TO_RAW
end_undef

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERT_TO_VIRTUAL
end_undef

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_undef
undef|#
directive|undef
name|REGISTER_RAW_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|REGISTER_VIRTUAL_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|REGISTER_VIRTUAL_TYPE
end_undef

begin_comment
comment|/* Number of machine registers */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|24
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_comment
comment|/* the order of the first 8 registers must match the compiler's   * numbering scheme (which is the same as the 386 scheme)  * also, this table must match regmap in i386-pinsn.c.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{ "eax",  "ecx",  "edx",  "ebx",  \ 			 "esp",  "ebp",  "esi",  "edi",  \ 			 "eip",  "ps",   "cs",   "ss",   \ 			 "ds",   "es",   "fs",   "gs",   \ 			 "st",   "st(1)","st(2)","st(3)",\                          "st(4)","st(5)","st(6)","st(7)",}
end_define

begin_define
define|#
directive|define
name|FP0_REGNUM
value|16
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(16 * 4 + 8 * 10)
end_define

begin_comment
comment|/* Index within `registers' of the first byte of the space for    register N.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTE
parameter_list|(
name|N
parameter_list|)
value|(((N)< 16) ? (N) * 4 : (((N) - 16) * 10) + (16 * 4))
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|(((N)< 16) ? 4 : 10)
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|(((N)< 16) ? 4 : 10)
end_define

begin_comment
comment|/* Largest value REGISTER_RAW_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|10
end_define

begin_comment
comment|/* Largest value REGISTER_VIRTUAL_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|10
end_define

begin_comment
comment|/* Nonzero if register N requires conversion    from raw format to virtual format.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|N
parameter_list|)
define|\
value|((N< FP0_REGNUM) ? 0 : 1)
end_define

begin_comment
comment|/* Convert data from raw format for register REGNUM in buffer FROM    to virtual format with type TYPE in buffer TO.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|i387_to_double
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_VIRTUAL
parameter_list|(
name|REGNUM
parameter_list|,
name|TYPE
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|{ \   double val; \   i387_to_double ((FROM), (char *)&val); \   store_floating ((TO), TYPE_LENGTH (TYPE), val); \ }
end_define

begin_decl_stmt
specifier|extern
name|void
name|double_to_i387
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_RAW
parameter_list|(
name|TYPE
parameter_list|,
name|REGNUM
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|{ \   double val = extract_floating ((FROM), TYPE_LENGTH (TYPE)); \   double_to_i387((char *)&val, (TO)); \ }
end_define

begin_comment
comment|/* Return the GDB type object for the "standard" data type    of data in register N.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_TYPE
parameter_list|(
name|N
parameter_list|)
define|\
value|((N< FP0_REGNUM) ? builtin_type_int : \    builtin_type_double)
end_define

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORE
end_define

begin_define
define|#
directive|define
name|IN_SOLIB_CALL_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|skip_trampoline_code (pc, name)
end_define

begin_define
define|#
directive|define
name|SKIP_TRAMPOLINE_CODE
parameter_list|(
name|pc
parameter_list|)
value|skip_trampoline_code (pc, 0)
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|skip_trampoline_code
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|pc
operator|,
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cygwin_pid_to_str
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|target_pid_to_str
parameter_list|(
name|PID
parameter_list|)
value|cygwin_pid_to_str (PID)
end_define

end_unit

