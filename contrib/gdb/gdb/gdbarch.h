begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_comment
comment|/* THIS FILE IS GENERATED */
end_comment

begin_comment
comment|/* Dynamic architecture support for GDB, the GNU debugger.    Copyright 1998, 1999, 2000, 2001, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This file was created with the aid of ``gdbarch.sh''.     The Bourne shell script ``gdbarch.sh'' creates the files    ``new-gdbarch.c'' and ``new-gdbarch.h and then compares them    against the existing ``gdbarch.[hc]''.  Any differences found    being reported.     If editing this file, please also run gdbarch.sh and merge any    changes into that script. Conversely, when making sweeping changes    to this file, modifying gdbarch.sh and using its output may prove    easier. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDBARCH_H
end_ifndef

begin_define
define|#
directive|define
name|GDBARCH_H
end_define

begin_include
include|#
directive|include
file|"dis-asm.h"
end_include

begin_comment
comment|/* Get defs for disassemble_info, which unfortunately is a typedef. */
end_comment

begin_if
if|#
directive|if
operator|!
name|GDB_MULTI_ARCH
end_if

begin_include
include|#
directive|include
file|"value.h"
end_include

begin_comment
comment|/* For default_coerce_float_to_double which is referenced by a macro.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|value
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|minimal_symbol
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|gdbarch
modifier|*
name|current_gdbarch
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If any of the following are defined, the target wasn't correctly    converted. */
end_comment

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EXTRA_FRAME_INFO
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"EXTRA_FRAME_INFO: replaced by struct frame_extra_info"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FRAME_FIND_SAVED_REGS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"FRAME_FIND_SAVED_REGS: replaced by FRAME_INIT_SAVED_REGS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PURE
operator|)
operator|&&
name|defined
argument_list|(
name|GDB_TM_FILE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"GDB_TM_FILE: Pure multi-arch targets do not have a tm.h file."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following are pre-initialized by GDBARCH. */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|struct
name|bfd_arch_info
modifier|*
name|gdbarch_bfd_arch_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set_gdbarch_bfd_arch_info() - not applicable - pre-initialized. */
end_comment

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_ARCHITECTURE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_ARCHITECTURE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_ARCHITECTURE
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_ARCHITECTURE
value|(gdbarch_bfd_arch_info (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_byte_order
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set_gdbarch_byte_order() - not applicable - pre-initialized. */
end_comment

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_BYTE_ORDER
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_BYTE_ORDER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_BYTE_ORDER
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|(gdbarch_byte_order (current_gdbarch))
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
comment|/* The following are initialized by the target dependent code. */
end_comment

begin_comment
comment|/* Number of bits in a char or unsigned char for the target machine.    Just like CHAR_BIT in<limits.h> but describes the target machine.    v::TARGET_CHAR_BIT:int:char_bit::::8 * sizeof (char):8::0:       Number of bits in a short or unsigned short for the target machine. */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_SHORT_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_SHORT_BIT
value|(2*TARGET_CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_short_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_short_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|short_bit
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_SHORT_BIT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_SHORT_BIT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_SHORT_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_SHORT_BIT
value|(gdbarch_short_bit (current_gdbarch))
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
comment|/* Number of bits in an int or unsigned int for the target machine. */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_INT_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_INT_BIT
value|(4*TARGET_CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_int_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_int_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|int_bit
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_INT_BIT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_INT_BIT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_INT_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_INT_BIT
value|(gdbarch_int_bit (current_gdbarch))
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
comment|/* Number of bits in a long or unsigned long for the target machine. */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_LONG_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_LONG_BIT
value|(4*TARGET_CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_long_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_long_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|long_bit
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_LONG_BIT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_LONG_BIT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_LONG_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_LONG_BIT
value|(gdbarch_long_bit (current_gdbarch))
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
comment|/* Number of bits in a long long or unsigned long long for the target    machine. */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_LONG_LONG_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_LONG_LONG_BIT
value|(2*TARGET_LONG_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_long_long_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_long_long_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|long_long_bit
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_LONG_LONG_BIT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_LONG_LONG_BIT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_LONG_LONG_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_LONG_LONG_BIT
value|(gdbarch_long_long_bit (current_gdbarch))
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
comment|/* Number of bits in a float for the target machine. */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_FLOAT_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_FLOAT_BIT
value|(4*TARGET_CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_float_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_float_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|float_bit
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_FLOAT_BIT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_FLOAT_BIT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_FLOAT_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_FLOAT_BIT
value|(gdbarch_float_bit (current_gdbarch))
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
comment|/* Number of bits in a double for the target machine. */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_DOUBLE_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_DOUBLE_BIT
value|(8*TARGET_CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_double_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_double_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|double_bit
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_DOUBLE_BIT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_DOUBLE_BIT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_DOUBLE_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_DOUBLE_BIT
value|(gdbarch_double_bit (current_gdbarch))
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
comment|/* Number of bits in a long double for the target machine. */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_LONG_DOUBLE_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_LONG_DOUBLE_BIT
value|(8*TARGET_CHAR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_long_double_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_long_double_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|long_double_bit
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_LONG_DOUBLE_BIT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_LONG_DOUBLE_BIT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_LONG_DOUBLE_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_LONG_DOUBLE_BIT
value|(gdbarch_long_double_bit (current_gdbarch))
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
comment|/* For most targets, a pointer on the target and its representation as an    address in GDB have the same size and "look the same".  For such a    target, you need only set TARGET_PTR_BIT / ptr_bit and TARGET_ADDR_BIT    / addr_bit will be set from it.       If TARGET_PTR_BIT and TARGET_ADDR_BIT are different, you'll probably    also need to set POINTER_TO_ADDRESS and ADDRESS_TO_POINTER as well.       ptr_bit is the size of a pointer on the target */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_PTR_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_PTR_BIT
value|(TARGET_INT_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_ptr_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_ptr_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|ptr_bit
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_PTR_BIT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_PTR_BIT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_PTR_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_PTR_BIT
value|(gdbarch_ptr_bit (current_gdbarch))
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
comment|/* addr_bit is the size of a target address as represented in gdb */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_ADDR_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_ADDR_BIT
value|(TARGET_PTR_BIT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_addr_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_addr_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|addr_bit
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_ADDR_BIT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_ADDR_BIT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_ADDR_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_ADDR_BIT
value|(gdbarch_addr_bit (current_gdbarch))
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
comment|/* Number of bits in a BFD_VMA for the target object file format. */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_BFD_VMA_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_BFD_VMA_BIT
value|(TARGET_ARCHITECTURE->bits_per_address)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_bfd_vma_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_bfd_vma_bit
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|bfd_vma_bit
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_BFD_VMA_BIT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_BFD_VMA_BIT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_BFD_VMA_BIT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_BFD_VMA_BIT
value|(gdbarch_bfd_vma_bit (current_gdbarch))
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
comment|/* One if `char' acts like `signed char', zero if `unsigned char'. */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_CHAR_SIGNED
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_CHAR_SIGNED
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_char_signed
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_char_signed
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|char_signed
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_CHAR_SIGNED
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_CHAR_SIGNED"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_CHAR_SIGNED
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_CHAR_SIGNED
value|(gdbarch_char_signed (current_gdbarch))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_READ_PC
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_READ_PC
parameter_list|(
name|ptid
parameter_list|)
value|(generic_target_read_pc (ptid))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_read_pc_ftype
function_decl|)
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_read_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_read_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_read_pc_ftype
modifier|*
name|read_pc
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_READ_PC
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_READ_PC"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_READ_PC
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_READ_PC
parameter_list|(
name|ptid
parameter_list|)
value|(gdbarch_read_pc (current_gdbarch, ptid))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_WRITE_PC
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_WRITE_PC
parameter_list|(
name|val
parameter_list|,
name|ptid
parameter_list|)
value|(generic_target_write_pc (val, ptid))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_write_pc_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|val
parameter_list|,
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_write_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|val
parameter_list|,
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_write_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_write_pc_ftype
modifier|*
name|write_pc
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_WRITE_PC
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_WRITE_PC"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_WRITE_PC
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_WRITE_PC
parameter_list|(
name|val
parameter_list|,
name|ptid
parameter_list|)
value|(gdbarch_write_pc (current_gdbarch, val, ptid))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_READ_FP
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_READ_FP
parameter_list|()
value|(generic_target_read_fp ())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_read_fp_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_read_fp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_read_fp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_read_fp_ftype
modifier|*
name|read_fp
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_READ_FP
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_READ_FP"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_READ_FP
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_READ_FP
parameter_list|()
value|(gdbarch_read_fp (current_gdbarch))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_WRITE_FP
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_WRITE_FP
parameter_list|(
name|val
parameter_list|)
value|(generic_target_write_fp (val))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_write_fp_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|val
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_write_fp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_write_fp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_write_fp_ftype
modifier|*
name|write_fp
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_WRITE_FP
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_WRITE_FP"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_WRITE_FP
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_WRITE_FP
parameter_list|(
name|val
parameter_list|)
value|(gdbarch_write_fp (current_gdbarch, val))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_READ_SP
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_READ_SP
parameter_list|()
value|(generic_target_read_sp ())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_read_sp_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_read_sp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_read_sp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_read_sp_ftype
modifier|*
name|read_sp
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_READ_SP
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_READ_SP"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_READ_SP
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_READ_SP
parameter_list|()
value|(gdbarch_read_sp (current_gdbarch))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_WRITE_SP
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_WRITE_SP
parameter_list|(
name|val
parameter_list|)
value|(generic_target_write_sp (val))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_write_sp_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|val
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_write_sp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_write_sp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_write_sp_ftype
modifier|*
name|write_sp
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_WRITE_SP
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_WRITE_SP"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_WRITE_SP
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_WRITE_SP
parameter_list|(
name|val
parameter_list|)
value|(gdbarch_write_sp (current_gdbarch, val))
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
comment|/* Function for getting target's idea of a frame pointer.  FIXME: GDB's    whole scheme for dealing with "frames" and "frame pointers" needs a    serious shakedown. */
end_comment

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_VIRTUAL_FRAME_POINTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_VIRTUAL_FRAME_POINTER
parameter_list|(
name|pc
parameter_list|,
name|frame_regnum
parameter_list|,
name|frame_offset
parameter_list|)
value|(legacy_virtual_frame_pointer (pc, frame_regnum, frame_offset))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_virtual_frame_pointer_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|int
modifier|*
name|frame_regnum
parameter_list|,
name|LONGEST
modifier|*
name|frame_offset
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_virtual_frame_pointer
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|,
name|int
modifier|*
name|frame_regnum
parameter_list|,
name|LONGEST
modifier|*
name|frame_offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_virtual_frame_pointer
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_virtual_frame_pointer_ftype
modifier|*
name|virtual_frame_pointer
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_VIRTUAL_FRAME_POINTER
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_VIRTUAL_FRAME_POINTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_VIRTUAL_FRAME_POINTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_VIRTUAL_FRAME_POINTER
parameter_list|(
name|pc
parameter_list|,
name|frame_regnum
parameter_list|,
name|frame_offset
parameter_list|)
value|(gdbarch_virtual_frame_pointer (current_gdbarch, pc, frame_regnum, frame_offset))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_read_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_register_read_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_register_read
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_read
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_read_ftype
modifier|*
name|register_read
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_write_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_register_write_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_register_write
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_write
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_write_ftype
modifier|*
name|register_write
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdbarch_num_regs
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_num_regs
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|num_regs
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|NUM_REGS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of NUM_REGS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|NUM_REGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NUM_REGS
value|(gdbarch_num_regs (current_gdbarch))
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
comment|/* This macro gives the number of pseudo-registers that live in the    register namespace but do not get fetched or stored on the target.    These pseudo-registers may be aliases for other registers,    combinations of other registers, or they may be computed by GDB. */
end_comment

begin_comment
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|NUM_PSEUDO_REGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NUM_PSEUDO_REGS
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_num_pseudo_regs
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_num_pseudo_regs
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|num_pseudo_regs
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|NUM_PSEUDO_REGS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of NUM_PSEUDO_REGS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|NUM_PSEUDO_REGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|NUM_PSEUDO_REGS
value|(gdbarch_num_pseudo_regs (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_sp_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_sp_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|sp_regnum
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|SP_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SP_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|SP_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|SP_REGNUM
value|(gdbarch_sp_regnum (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_fp_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_fp_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|fp_regnum
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FP_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FP_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FP_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|FP_REGNUM
value|(gdbarch_fp_regnum (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_pc_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_pc_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|pc_regnum
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|PC_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PC_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PC_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|PC_REGNUM
value|(gdbarch_pc_regnum (current_gdbarch))
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
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|FP0_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|FP0_REGNUM
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_fp0_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_fp0_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|fp0_regnum
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FP0_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FP0_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FP0_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|FP0_REGNUM
value|(gdbarch_fp0_regnum (current_gdbarch))
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
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|NPC_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|NPC_REGNUM
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_npc_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_npc_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|npc_regnum
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|NPC_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of NPC_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|NPC_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|NPC_REGNUM
value|(gdbarch_npc_regnum (current_gdbarch))
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
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|NNPC_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|NNPC_REGNUM
value|(-1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_nnpc_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_nnpc_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|nnpc_regnum
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|NNPC_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of NNPC_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|NNPC_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|NNPC_REGNUM
value|(gdbarch_nnpc_regnum (current_gdbarch))
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
comment|/* Convert stab register number (from `r' declaration) to a gdb REGNUM. */
end_comment

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|STAB_REG_TO_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|STAB_REG_TO_REGNUM
parameter_list|(
name|stab_regnr
parameter_list|)
value|(no_op_reg_to_regnum (stab_regnr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_stab_reg_to_regnum_ftype
function_decl|)
parameter_list|(
name|int
name|stab_regnr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_stab_reg_to_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|stab_regnr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_stab_reg_to_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_stab_reg_to_regnum_ftype
modifier|*
name|stab_reg_to_regnum
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|STAB_REG_TO_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of STAB_REG_TO_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|STAB_REG_TO_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|STAB_REG_TO_REGNUM
parameter_list|(
name|stab_regnr
parameter_list|)
value|(gdbarch_stab_reg_to_regnum (current_gdbarch, stab_regnr))
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
comment|/* Provide a default mapping from a ecoff register number to a gdb REGNUM. */
end_comment

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|ECOFF_REG_TO_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|ECOFF_REG_TO_REGNUM
parameter_list|(
name|ecoff_regnr
parameter_list|)
value|(no_op_reg_to_regnum (ecoff_regnr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_ecoff_reg_to_regnum_ftype
function_decl|)
parameter_list|(
name|int
name|ecoff_regnr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_ecoff_reg_to_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|ecoff_regnr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_ecoff_reg_to_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_ecoff_reg_to_regnum_ftype
modifier|*
name|ecoff_reg_to_regnum
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|ECOFF_REG_TO_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of ECOFF_REG_TO_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|ECOFF_REG_TO_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|ECOFF_REG_TO_REGNUM
parameter_list|(
name|ecoff_regnr
parameter_list|)
value|(gdbarch_ecoff_reg_to_regnum (current_gdbarch, ecoff_regnr))
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
comment|/* Provide a default mapping from a DWARF register number to a gdb REGNUM. */
end_comment

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|DWARF_REG_TO_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF_REG_TO_REGNUM
parameter_list|(
name|dwarf_regnr
parameter_list|)
value|(no_op_reg_to_regnum (dwarf_regnr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_dwarf_reg_to_regnum_ftype
function_decl|)
parameter_list|(
name|int
name|dwarf_regnr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_dwarf_reg_to_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|dwarf_regnr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_dwarf_reg_to_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_dwarf_reg_to_regnum_ftype
modifier|*
name|dwarf_reg_to_regnum
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|DWARF_REG_TO_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DWARF_REG_TO_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|DWARF_REG_TO_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF_REG_TO_REGNUM
parameter_list|(
name|dwarf_regnr
parameter_list|)
value|(gdbarch_dwarf_reg_to_regnum (current_gdbarch, dwarf_regnr))
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
comment|/* Convert from an sdb register number to an internal gdb register number.    This should be defined in tm.h, if REGISTER_NAMES is not set up    to map one to one onto the sdb register numbers. */
end_comment

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|SDB_REG_TO_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|SDB_REG_TO_REGNUM
parameter_list|(
name|sdb_regnr
parameter_list|)
value|(no_op_reg_to_regnum (sdb_regnr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_sdb_reg_to_regnum_ftype
function_decl|)
parameter_list|(
name|int
name|sdb_regnr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_sdb_reg_to_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|sdb_regnr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_sdb_reg_to_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_sdb_reg_to_regnum_ftype
modifier|*
name|sdb_reg_to_regnum
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|SDB_REG_TO_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SDB_REG_TO_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|SDB_REG_TO_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|SDB_REG_TO_REGNUM
parameter_list|(
name|sdb_regnr
parameter_list|)
value|(gdbarch_sdb_reg_to_regnum (current_gdbarch, sdb_regnr))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|DWARF2_REG_TO_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF2_REG_TO_REGNUM
parameter_list|(
name|dwarf2_regnr
parameter_list|)
value|(no_op_reg_to_regnum (dwarf2_regnr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_dwarf2_reg_to_regnum_ftype
function_decl|)
parameter_list|(
name|int
name|dwarf2_regnr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_dwarf2_reg_to_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|dwarf2_regnr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_dwarf2_reg_to_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_dwarf2_reg_to_regnum_ftype
modifier|*
name|dwarf2_reg_to_regnum
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|DWARF2_REG_TO_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DWARF2_REG_TO_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|DWARF2_REG_TO_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF2_REG_TO_REGNUM
parameter_list|(
name|dwarf2_regnr
parameter_list|)
value|(gdbarch_dwarf2_reg_to_regnum (current_gdbarch, dwarf2_regnr))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|REGISTER_NAME
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_NAME
parameter_list|(
name|regnr
parameter_list|)
value|(legacy_register_name (regnr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
name|gdbarch_register_name_ftype
function_decl|)
parameter_list|(
name|int
name|regnr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|char
modifier|*
name|gdbarch_register_name
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_name
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_name_ftype
modifier|*
name|register_name
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_NAME
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_NAME"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_NAME
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_NAME
parameter_list|(
name|regnr
parameter_list|)
value|(gdbarch_register_name (current_gdbarch, regnr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|register_size
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_SIZE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_SIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_SIZE
value|(gdbarch_register_size (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_bytes
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_bytes
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|register_bytes
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_BYTES
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_BYTES"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_BYTES
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(gdbarch_register_bytes (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_register_byte_ftype
function_decl|)
parameter_list|(
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_byte
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_byte
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_byte_ftype
modifier|*
name|register_byte
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_BYTE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_BYTE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_BYTE
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_BYTE
parameter_list|(
name|reg_nr
parameter_list|)
value|(gdbarch_register_byte (current_gdbarch, reg_nr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_register_raw_size_ftype
function_decl|)
parameter_list|(
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_raw_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_raw_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_raw_size_ftype
modifier|*
name|register_raw_size
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_RAW_SIZE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_RAW_SIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_RAW_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|reg_nr
parameter_list|)
value|(gdbarch_register_raw_size (current_gdbarch, reg_nr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_max_register_raw_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_max_register_raw_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|max_register_raw_size
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|MAX_REGISTER_RAW_SIZE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of MAX_REGISTER_RAW_SIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|MAX_REGISTER_RAW_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|(gdbarch_max_register_raw_size (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_register_virtual_size_ftype
function_decl|)
parameter_list|(
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_virtual_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_virtual_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_virtual_size_ftype
modifier|*
name|register_virtual_size
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_VIRTUAL_SIZE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_VIRTUAL_SIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_VIRTUAL_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|reg_nr
parameter_list|)
value|(gdbarch_register_virtual_size (current_gdbarch, reg_nr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_max_register_virtual_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_max_register_virtual_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|max_register_virtual_size
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|MAX_REGISTER_VIRTUAL_SIZE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of MAX_REGISTER_VIRTUAL_SIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|MAX_REGISTER_VIRTUAL_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|(gdbarch_max_register_virtual_size (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|type
modifier|*
function_decl|(
name|gdbarch_register_virtual_type_ftype
function_decl|)
parameter_list|(
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|gdbarch_register_virtual_type
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_virtual_type
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_virtual_type_ftype
modifier|*
name|register_virtual_type
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_VIRTUAL_TYPE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_VIRTUAL_TYPE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_VIRTUAL_TYPE
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_TYPE
parameter_list|(
name|reg_nr
parameter_list|)
value|(gdbarch_register_virtual_type (current_gdbarch, reg_nr))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|DO_REGISTERS_INFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|DO_REGISTERS_INFO
parameter_list|(
name|reg_nr
parameter_list|,
name|fpregs
parameter_list|)
value|(do_registers_info (reg_nr, fpregs))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_do_registers_info_ftype
function_decl|)
parameter_list|(
name|int
name|reg_nr
parameter_list|,
name|int
name|fpregs
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_do_registers_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|reg_nr
parameter_list|,
name|int
name|fpregs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_do_registers_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_do_registers_info_ftype
modifier|*
name|do_registers_info
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|DO_REGISTERS_INFO
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DO_REGISTERS_INFO"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|DO_REGISTERS_INFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|DO_REGISTERS_INFO
parameter_list|(
name|reg_nr
parameter_list|,
name|fpregs
parameter_list|)
value|(gdbarch_do_registers_info (current_gdbarch, reg_nr, fpregs))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|PRINT_FLOAT_INFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|PRINT_FLOAT_INFO
parameter_list|()
value|(default_print_float_info ())
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_print_float_info_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_print_float_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_print_float_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_print_float_info_ftype
modifier|*
name|print_float_info
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|PRINT_FLOAT_INFO
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PRINT_FLOAT_INFO"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PRINT_FLOAT_INFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|PRINT_FLOAT_INFO
parameter_list|()
value|(gdbarch_print_float_info (current_gdbarch))
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
comment|/* MAP a GDB RAW register number onto a simulator register number.  See    also include/...-sim.h. */
end_comment

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|REGISTER_SIM_REGNO
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_SIM_REGNO
parameter_list|(
name|reg_nr
parameter_list|)
value|(default_register_sim_regno (reg_nr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_register_sim_regno_ftype
function_decl|)
parameter_list|(
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_sim_regno
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|reg_nr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_sim_regno
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_sim_regno_ftype
modifier|*
name|register_sim_regno
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_SIM_REGNO
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_SIM_REGNO"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_SIM_REGNO
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_SIM_REGNO
parameter_list|(
name|reg_nr
parameter_list|)
value|(gdbarch_register_sim_regno (current_gdbarch, reg_nr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REGISTER_BYTES_OK
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch REGISTER_BYTES_OK */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|REGISTER_BYTES_OK_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_BYTES_OK_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|REGISTER_BYTES_OK_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_BYTES_OK_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_bytes_ok_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_BYTES_OK_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_BYTES_OK"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_BYTES_OK_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_BYTES_OK_P
parameter_list|()
value|(gdbarch_register_bytes_ok_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|REGISTER_BYTES_OK
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_BYTES_OK
parameter_list|(
name|nr_bytes
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "REGISTER_BYTES_OK"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_register_bytes_ok_ftype
function_decl|)
parameter_list|(
name|long
name|nr_bytes
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_bytes_ok
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|long
name|nr_bytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_bytes_ok
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_bytes_ok_ftype
modifier|*
name|register_bytes_ok
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_BYTES_OK
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_BYTES_OK"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_BYTES_OK
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_BYTES_OK
parameter_list|(
name|nr_bytes
parameter_list|)
value|(gdbarch_register_bytes_ok (current_gdbarch, nr_bytes))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|CANNOT_FETCH_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|CANNOT_FETCH_REGISTER
parameter_list|(
name|regnum
parameter_list|)
value|(cannot_register_not (regnum))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_cannot_fetch_register_ftype
function_decl|)
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_cannot_fetch_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_cannot_fetch_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_cannot_fetch_register_ftype
modifier|*
name|cannot_fetch_register
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CANNOT_FETCH_REGISTER
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CANNOT_FETCH_REGISTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CANNOT_FETCH_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|CANNOT_FETCH_REGISTER
parameter_list|(
name|regnum
parameter_list|)
value|(gdbarch_cannot_fetch_register (current_gdbarch, regnum))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|CANNOT_STORE_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|CANNOT_STORE_REGISTER
parameter_list|(
name|regnum
parameter_list|)
value|(cannot_register_not (regnum))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_cannot_store_register_ftype
function_decl|)
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_cannot_store_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_cannot_store_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_cannot_store_register_ftype
modifier|*
name|cannot_store_register
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CANNOT_STORE_REGISTER
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CANNOT_STORE_REGISTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CANNOT_STORE_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|CANNOT_STORE_REGISTER
parameter_list|(
name|regnum
parameter_list|)
value|(gdbarch_cannot_store_register (current_gdbarch, regnum))
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
comment|/* setjmp/longjmp support. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GET_LONGJMP_TARGET
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch GET_LONGJMP_TARGET */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GET_LONGJMP_TARGET_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|GET_LONGJMP_TARGET_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_get_longjmp_target_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|GET_LONGJMP_TARGET_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of GET_LONGJMP_TARGET"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|GET_LONGJMP_TARGET_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET_P
parameter_list|()
value|(gdbarch_get_longjmp_target_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|GET_LONGJMP_TARGET
argument_list|)
end_if

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET
parameter_list|(
name|pc
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "GET_LONGJMP_TARGET"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_get_longjmp_target_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
modifier|*
name|pc
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_get_longjmp_target
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
modifier|*
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_get_longjmp_target
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_get_longjmp_target_ftype
modifier|*
name|get_longjmp_target
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|GET_LONGJMP_TARGET
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of GET_LONGJMP_TARGET"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|GET_LONGJMP_TARGET
argument_list|)
end_if

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET
parameter_list|(
name|pc
parameter_list|)
value|(gdbarch_get_longjmp_target (current_gdbarch, pc))
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
comment|/* Non multi-arch DUMMY_FRAMES are a mess (multi-arch ones are not that    much better but at least they are vaguely consistent).  The headers    and body contain convoluted #if/#else sequences for determine how    things should be compiled.  Instead of trying to mimic that    behaviour here (and hence entrench it further) gdbarch simply    reqires that these methods be set up from the word go.  This also    avoids any potential problems with moving beyond multi-arch partial. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_use_generic_dummy_frames
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_use_generic_dummy_frames
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|use_generic_dummy_frames
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|USE_GENERIC_DUMMY_FRAMES
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of USE_GENERIC_DUMMY_FRAMES"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|USE_GENERIC_DUMMY_FRAMES
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_GENERIC_DUMMY_FRAMES
value|(gdbarch_use_generic_dummy_frames (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_call_dummy_location
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_call_dummy_location
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|call_dummy_location
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CALL_DUMMY_LOCATION
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CALL_DUMMY_LOCATION"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_LOCATION
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_LOCATION
value|(gdbarch_call_dummy_location (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_call_dummy_address_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_call_dummy_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_call_dummy_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_call_dummy_address_ftype
modifier|*
name|call_dummy_address
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CALL_DUMMY_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CALL_DUMMY_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_ADDRESS
parameter_list|()
value|(gdbarch_call_dummy_address (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_call_dummy_start_offset
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_call_dummy_start_offset
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|call_dummy_start_offset
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CALL_DUMMY_START_OFFSET
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CALL_DUMMY_START_OFFSET"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_START_OFFSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|(gdbarch_call_dummy_start_offset (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_call_dummy_breakpoint_offset
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_call_dummy_breakpoint_offset
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|call_dummy_breakpoint_offset
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CALL_DUMMY_BREAKPOINT_OFFSET
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CALL_DUMMY_BREAKPOINT_OFFSET"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_BREAKPOINT_OFFSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET
value|(gdbarch_call_dummy_breakpoint_offset (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_call_dummy_breakpoint_offset_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_call_dummy_breakpoint_offset_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|call_dummy_breakpoint_offset_p
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CALL_DUMMY_BREAKPOINT_OFFSET_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CALL_DUMMY_BREAKPOINT_OFFSET_P"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_BREAKPOINT_OFFSET_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET_P
value|(gdbarch_call_dummy_breakpoint_offset_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_call_dummy_length
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_call_dummy_length
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|call_dummy_length
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CALL_DUMMY_LENGTH
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CALL_DUMMY_LENGTH"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_LENGTH
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|(gdbarch_call_dummy_length (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_pc_in_call_dummy_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|CORE_ADDR
name|frame_address
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_pc_in_call_dummy
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|CORE_ADDR
name|frame_address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_pc_in_call_dummy
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_pc_in_call_dummy_ftype
modifier|*
name|pc_in_call_dummy
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|PC_IN_CALL_DUMMY
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PC_IN_CALL_DUMMY"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PC_IN_CALL_DUMMY
argument_list|)
end_if

begin_define
define|#
directive|define
name|PC_IN_CALL_DUMMY
parameter_list|(
name|pc
parameter_list|,
name|sp
parameter_list|,
name|frame_address
parameter_list|)
value|(gdbarch_pc_in_call_dummy (current_gdbarch, pc, sp, frame_address))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_call_dummy_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_call_dummy_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|call_dummy_p
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CALL_DUMMY_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CALL_DUMMY_P"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_P
value|(gdbarch_call_dummy_p (current_gdbarch))
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
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_WORDS
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_WORDS
value|(legacy_call_dummy_words)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|LONGEST
modifier|*
name|gdbarch_call_dummy_words
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_call_dummy_words
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|LONGEST
modifier|*
name|call_dummy_words
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CALL_DUMMY_WORDS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CALL_DUMMY_WORDS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_WORDS
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_WORDS
value|(gdbarch_call_dummy_words (current_gdbarch))
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
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|SIZEOF_CALL_DUMMY_WORDS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIZEOF_CALL_DUMMY_WORDS
value|(legacy_sizeof_call_dummy_words)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_sizeof_call_dummy_words
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_sizeof_call_dummy_words
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|sizeof_call_dummy_words
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|SIZEOF_CALL_DUMMY_WORDS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SIZEOF_CALL_DUMMY_WORDS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|SIZEOF_CALL_DUMMY_WORDS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIZEOF_CALL_DUMMY_WORDS
value|(gdbarch_sizeof_call_dummy_words (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_call_dummy_stack_adjust_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_call_dummy_stack_adjust_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|call_dummy_stack_adjust_p
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CALL_DUMMY_STACK_ADJUST_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CALL_DUMMY_STACK_ADJUST_P"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_STACK_ADJUST_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_STACK_ADJUST_P
value|(gdbarch_call_dummy_stack_adjust_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_call_dummy_stack_adjust
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_call_dummy_stack_adjust
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|call_dummy_stack_adjust
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CALL_DUMMY_STACK_ADJUST
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CALL_DUMMY_STACK_ADJUST"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CALL_DUMMY_STACK_ADJUST
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY_STACK_ADJUST
value|(gdbarch_call_dummy_stack_adjust (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_fix_call_dummy_ftype
function_decl|)
parameter_list|(
name|char
modifier|*
name|dummy
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|fun
parameter_list|,
name|int
name|nargs
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|int
name|gcc_p
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_fix_call_dummy
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|char
modifier|*
name|dummy
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|fun
parameter_list|,
name|int
name|nargs
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|int
name|gcc_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_fix_call_dummy
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_fix_call_dummy_ftype
modifier|*
name|fix_call_dummy
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FIX_CALL_DUMMY
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FIX_CALL_DUMMY"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FIX_CALL_DUMMY
argument_list|)
end_if

begin_define
define|#
directive|define
name|FIX_CALL_DUMMY
parameter_list|(
name|dummy
parameter_list|,
name|pc
parameter_list|,
name|fun
parameter_list|,
name|nargs
parameter_list|,
name|args
parameter_list|,
name|type
parameter_list|,
name|gcc_p
parameter_list|)
value|(gdbarch_fix_call_dummy (current_gdbarch, dummy, pc, fun, nargs, args, type, gcc_p))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|INIT_FRAME_PC_FIRST
argument_list|)
end_if

begin_define
define|#
directive|define
name|INIT_FRAME_PC_FIRST
parameter_list|(
name|fromleaf
parameter_list|,
name|prev
parameter_list|)
value|(init_frame_pc_noop (fromleaf, prev))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_init_frame_pc_first_ftype
function_decl|)
parameter_list|(
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
name|prev
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_init_frame_pc_first
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
name|prev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_init_frame_pc_first
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_init_frame_pc_first_ftype
modifier|*
name|init_frame_pc_first
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|INIT_FRAME_PC_FIRST
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of INIT_FRAME_PC_FIRST"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|INIT_FRAME_PC_FIRST
argument_list|)
end_if

begin_define
define|#
directive|define
name|INIT_FRAME_PC_FIRST
parameter_list|(
name|fromleaf
parameter_list|,
name|prev
parameter_list|)
value|(gdbarch_init_frame_pc_first (current_gdbarch, fromleaf, prev))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|INIT_FRAME_PC
argument_list|)
end_if

begin_define
define|#
directive|define
name|INIT_FRAME_PC
parameter_list|(
name|fromleaf
parameter_list|,
name|prev
parameter_list|)
value|(init_frame_pc_default (fromleaf, prev))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_init_frame_pc_ftype
function_decl|)
parameter_list|(
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
name|prev
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_init_frame_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
name|prev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_init_frame_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_init_frame_pc_ftype
modifier|*
name|init_frame_pc
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|INIT_FRAME_PC
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of INIT_FRAME_PC"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|INIT_FRAME_PC
argument_list|)
end_if

begin_define
define|#
directive|define
name|INIT_FRAME_PC
parameter_list|(
name|fromleaf
parameter_list|,
name|prev
parameter_list|)
value|(gdbarch_init_frame_pc (current_gdbarch, fromleaf, prev))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_believe_pcc_promotion
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_believe_pcc_promotion
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|believe_pcc_promotion
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|BELIEVE_PCC_PROMOTION
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of BELIEVE_PCC_PROMOTION"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|BELIEVE_PCC_PROMOTION
argument_list|)
end_if

begin_define
define|#
directive|define
name|BELIEVE_PCC_PROMOTION
value|(gdbarch_believe_pcc_promotion (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_believe_pcc_promotion_type
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_believe_pcc_promotion_type
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|believe_pcc_promotion_type
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|BELIEVE_PCC_PROMOTION_TYPE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of BELIEVE_PCC_PROMOTION_TYPE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|BELIEVE_PCC_PROMOTION_TYPE
argument_list|)
end_if

begin_define
define|#
directive|define
name|BELIEVE_PCC_PROMOTION_TYPE
value|(gdbarch_believe_pcc_promotion_type (current_gdbarch))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|COERCE_FLOAT_TO_DOUBLE
argument_list|)
end_if

begin_define
define|#
directive|define
name|COERCE_FLOAT_TO_DOUBLE
parameter_list|(
name|formal
parameter_list|,
name|actual
parameter_list|)
value|(default_coerce_float_to_double (formal, actual))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_coerce_float_to_double_ftype
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
name|formal
parameter_list|,
name|struct
name|type
modifier|*
name|actual
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_coerce_float_to_double
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|formal
parameter_list|,
name|struct
name|type
modifier|*
name|actual
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_coerce_float_to_double
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_coerce_float_to_double_ftype
modifier|*
name|coerce_float_to_double
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|COERCE_FLOAT_TO_DOUBLE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of COERCE_FLOAT_TO_DOUBLE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|COERCE_FLOAT_TO_DOUBLE
argument_list|)
end_if

begin_define
define|#
directive|define
name|COERCE_FLOAT_TO_DOUBLE
parameter_list|(
name|formal
parameter_list|,
name|actual
parameter_list|)
value|(gdbarch_coerce_float_to_double (current_gdbarch, formal, actual))
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
comment|/* GET_SAVED_REGISTER is like DUMMY_FRAMES.  It is at level one as the    old code has strange #ifdef interaction.  So far no one has found    that default_get_saved_register() is the default they are after. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_get_saved_register_ftype
function_decl|)
parameter_list|(
name|char
modifier|*
name|raw_buffer
parameter_list|,
name|int
modifier|*
name|optimized
parameter_list|,
name|CORE_ADDR
modifier|*
name|addrp
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|enum
name|lval_type
modifier|*
name|lval
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_get_saved_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|char
modifier|*
name|raw_buffer
parameter_list|,
name|int
modifier|*
name|optimized
parameter_list|,
name|CORE_ADDR
modifier|*
name|addrp
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|enum
name|lval_type
modifier|*
name|lval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_get_saved_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_get_saved_register_ftype
modifier|*
name|get_saved_register
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|GET_SAVED_REGISTER
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of GET_SAVED_REGISTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>=
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|GET_SAVED_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|GET_SAVED_REGISTER
parameter_list|(
name|raw_buffer
parameter_list|,
name|optimized
parameter_list|,
name|addrp
parameter_list|,
name|frame
parameter_list|,
name|regnum
parameter_list|,
name|lval
parameter_list|)
value|(gdbarch_get_saved_register (current_gdbarch, raw_buffer, optimized, addrp, frame, regnum, lval))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|REGISTER_CONVERTIBLE
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|nr
parameter_list|)
value|(generic_register_convertible_not (nr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_register_convertible_ftype
function_decl|)
parameter_list|(
name|int
name|nr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_convertible
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|nr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_convertible
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_convertible_ftype
modifier|*
name|register_convertible
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_CONVERTIBLE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_CONVERTIBLE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_CONVERTIBLE
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|nr
parameter_list|)
value|(gdbarch_register_convertible (current_gdbarch, nr))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|REGISTER_CONVERT_TO_VIRTUAL
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_VIRTUAL
parameter_list|(
name|regnum
parameter_list|,
name|type
parameter_list|,
name|from
parameter_list|,
name|to
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "REGISTER_CONVERT_TO_VIRTUAL"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_register_convert_to_virtual_ftype
function_decl|)
parameter_list|(
name|int
name|regnum
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_register_convert_to_virtual
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_convert_to_virtual
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_convert_to_virtual_ftype
modifier|*
name|register_convert_to_virtual
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_CONVERT_TO_VIRTUAL
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_CONVERT_TO_VIRTUAL"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_CONVERT_TO_VIRTUAL
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_VIRTUAL
parameter_list|(
name|regnum
parameter_list|,
name|type
parameter_list|,
name|from
parameter_list|,
name|to
parameter_list|)
value|(gdbarch_register_convert_to_virtual (current_gdbarch, regnum, type, from, to))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|REGISTER_CONVERT_TO_RAW
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_RAW
parameter_list|(
name|type
parameter_list|,
name|regnum
parameter_list|,
name|from
parameter_list|,
name|to
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "REGISTER_CONVERT_TO_RAW"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_register_convert_to_raw_ftype
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|int
name|regnum
parameter_list|,
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_register_convert_to_raw
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|int
name|regnum
parameter_list|,
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_convert_to_raw
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_convert_to_raw_ftype
modifier|*
name|register_convert_to_raw
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REGISTER_CONVERT_TO_RAW
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_CONVERT_TO_RAW"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REGISTER_CONVERT_TO_RAW
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_RAW
parameter_list|(
name|type
parameter_list|,
name|regnum
parameter_list|,
name|from
parameter_list|,
name|to
parameter_list|)
value|(gdbarch_register_convert_to_raw (current_gdbarch, type, regnum, from, to))
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
comment|/* This function is called when the value of a pseudo-register needs to    be updated.  Typically it will be defined on a per-architecture    basis. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FETCH_PSEUDO_REGISTER
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch FETCH_PSEUDO_REGISTER */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FETCH_PSEUDO_REGISTER_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|FETCH_PSEUDO_REGISTER_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|FETCH_PSEUDO_REGISTER_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|FETCH_PSEUDO_REGISTER_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_fetch_pseudo_register_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FETCH_PSEUDO_REGISTER_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FETCH_PSEUDO_REGISTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FETCH_PSEUDO_REGISTER_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|FETCH_PSEUDO_REGISTER_P
parameter_list|()
value|(gdbarch_fetch_pseudo_register_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|FETCH_PSEUDO_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|FETCH_PSEUDO_REGISTER
parameter_list|(
name|regnum
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "FETCH_PSEUDO_REGISTER"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_fetch_pseudo_register_ftype
function_decl|)
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_fetch_pseudo_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_fetch_pseudo_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_fetch_pseudo_register_ftype
modifier|*
name|fetch_pseudo_register
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FETCH_PSEUDO_REGISTER
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FETCH_PSEUDO_REGISTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FETCH_PSEUDO_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|FETCH_PSEUDO_REGISTER
parameter_list|(
name|regnum
parameter_list|)
value|(gdbarch_fetch_pseudo_register (current_gdbarch, regnum))
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
comment|/* This function is called when the value of a pseudo-register needs to    be set or stored.  Typically it will be defined on a    per-architecture basis. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STORE_PSEUDO_REGISTER
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch STORE_PSEUDO_REGISTER */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STORE_PSEUDO_REGISTER_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|STORE_PSEUDO_REGISTER_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|STORE_PSEUDO_REGISTER_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|STORE_PSEUDO_REGISTER_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_store_pseudo_register_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|STORE_PSEUDO_REGISTER_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of STORE_PSEUDO_REGISTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|STORE_PSEUDO_REGISTER_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|STORE_PSEUDO_REGISTER_P
parameter_list|()
value|(gdbarch_store_pseudo_register_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|STORE_PSEUDO_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|STORE_PSEUDO_REGISTER
parameter_list|(
name|regnum
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "STORE_PSEUDO_REGISTER"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_store_pseudo_register_ftype
function_decl|)
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_store_pseudo_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_store_pseudo_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_store_pseudo_register_ftype
modifier|*
name|store_pseudo_register
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|STORE_PSEUDO_REGISTER
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of STORE_PSEUDO_REGISTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|STORE_PSEUDO_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|STORE_PSEUDO_REGISTER
parameter_list|(
name|regnum
parameter_list|)
value|(gdbarch_store_pseudo_register (current_gdbarch, regnum))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|POINTER_TO_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|POINTER_TO_ADDRESS
parameter_list|(
name|type
parameter_list|,
name|buf
parameter_list|)
value|(unsigned_pointer_to_address (type, buf))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_pointer_to_address_ftype
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_pointer_to_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_pointer_to_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_pointer_to_address_ftype
modifier|*
name|pointer_to_address
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|POINTER_TO_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of POINTER_TO_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|POINTER_TO_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|POINTER_TO_ADDRESS
parameter_list|(
name|type
parameter_list|,
name|buf
parameter_list|)
value|(gdbarch_pointer_to_address (current_gdbarch, type, buf))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|ADDRESS_TO_POINTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|ADDRESS_TO_POINTER
parameter_list|(
name|type
parameter_list|,
name|buf
parameter_list|,
name|addr
parameter_list|)
value|(unsigned_address_to_pointer (type, buf, addr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_address_to_pointer_ftype
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_address_to_pointer
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_address_to_pointer
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_address_to_pointer_ftype
modifier|*
name|address_to_pointer
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|ADDRESS_TO_POINTER
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of ADDRESS_TO_POINTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|ADDRESS_TO_POINTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|ADDRESS_TO_POINTER
parameter_list|(
name|type
parameter_list|,
name|buf
parameter_list|,
name|addr
parameter_list|)
value|(gdbarch_address_to_pointer (current_gdbarch, type, buf, addr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INTEGER_TO_ADDRESS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch INTEGER_TO_ADDRESS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INTEGER_TO_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|INTEGER_TO_ADDRESS_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|INTEGER_TO_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|INTEGER_TO_ADDRESS_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_integer_to_address_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|INTEGER_TO_ADDRESS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of INTEGER_TO_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|INTEGER_TO_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|INTEGER_TO_ADDRESS_P
parameter_list|()
value|(gdbarch_integer_to_address_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|INTEGER_TO_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|INTEGER_TO_ADDRESS
parameter_list|(
name|type
parameter_list|,
name|buf
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "INTEGER_TO_ADDRESS"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_integer_to_address_ftype
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_integer_to_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_integer_to_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_integer_to_address_ftype
modifier|*
name|integer_to_address
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|INTEGER_TO_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of INTEGER_TO_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|INTEGER_TO_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|INTEGER_TO_ADDRESS
parameter_list|(
name|type
parameter_list|,
name|buf
parameter_list|)
value|(gdbarch_integer_to_address (current_gdbarch, type, buf))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|RETURN_VALUE_ON_STACK
argument_list|)
end_if

begin_define
define|#
directive|define
name|RETURN_VALUE_ON_STACK
parameter_list|(
name|type
parameter_list|)
value|(generic_return_value_on_stack_not (type))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_return_value_on_stack_ftype
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_return_value_on_stack
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_return_value_on_stack
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_return_value_on_stack_ftype
modifier|*
name|return_value_on_stack
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|RETURN_VALUE_ON_STACK
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of RETURN_VALUE_ON_STACK"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|RETURN_VALUE_ON_STACK
argument_list|)
end_if

begin_define
define|#
directive|define
name|RETURN_VALUE_ON_STACK
parameter_list|(
name|type
parameter_list|)
value|(gdbarch_return_value_on_stack (current_gdbarch, type))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_extract_return_value_ftype
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|regbuf
parameter_list|,
name|char
modifier|*
name|valbuf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_extract_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|regbuf
parameter_list|,
name|char
modifier|*
name|valbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_extract_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_extract_return_value_ftype
modifier|*
name|extract_return_value
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|EXTRACT_RETURN_VALUE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of EXTRACT_RETURN_VALUE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|EXTRACT_RETURN_VALUE
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRACT_RETURN_VALUE
parameter_list|(
name|type
parameter_list|,
name|regbuf
parameter_list|,
name|valbuf
parameter_list|)
value|(gdbarch_extract_return_value (current_gdbarch, type, regbuf, valbuf))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|PUSH_ARGUMENTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|PUSH_ARGUMENTS
parameter_list|(
name|nargs
parameter_list|,
name|args
parameter_list|,
name|sp
parameter_list|,
name|struct_return
parameter_list|,
name|struct_addr
parameter_list|)
value|(default_push_arguments (nargs, args, sp, struct_return, struct_addr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_push_arguments_ftype
function_decl|)
parameter_list|(
name|int
name|nargs
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|int
name|struct_return
parameter_list|,
name|CORE_ADDR
name|struct_addr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_push_arguments
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|nargs
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|int
name|struct_return
parameter_list|,
name|CORE_ADDR
name|struct_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_push_arguments
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_push_arguments_ftype
modifier|*
name|push_arguments
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|PUSH_ARGUMENTS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PUSH_ARGUMENTS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PUSH_ARGUMENTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|PUSH_ARGUMENTS
parameter_list|(
name|nargs
parameter_list|,
name|args
parameter_list|,
name|sp
parameter_list|,
name|struct_return
parameter_list|,
name|struct_addr
parameter_list|)
value|(gdbarch_push_arguments (current_gdbarch, nargs, args, sp, struct_return, struct_addr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_push_dummy_frame_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_push_dummy_frame
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_push_dummy_frame
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_push_dummy_frame_ftype
modifier|*
name|push_dummy_frame
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|PUSH_DUMMY_FRAME
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PUSH_DUMMY_FRAME"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PUSH_DUMMY_FRAME
argument_list|)
end_if

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
value|(gdbarch_push_dummy_frame (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PUSH_RETURN_ADDRESS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch PUSH_RETURN_ADDRESS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PUSH_RETURN_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|PUSH_RETURN_ADDRESS_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|PUSH_RETURN_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|PUSH_RETURN_ADDRESS_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_push_return_address_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|PUSH_RETURN_ADDRESS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PUSH_RETURN_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PUSH_RETURN_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|PUSH_RETURN_ADDRESS_P
parameter_list|()
value|(gdbarch_push_return_address_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|PUSH_RETURN_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|PUSH_RETURN_ADDRESS
parameter_list|(
name|pc
parameter_list|,
name|sp
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "PUSH_RETURN_ADDRESS"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_push_return_address_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_push_return_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_push_return_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_push_return_address_ftype
modifier|*
name|push_return_address
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|PUSH_RETURN_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PUSH_RETURN_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PUSH_RETURN_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|PUSH_RETURN_ADDRESS
parameter_list|(
name|pc
parameter_list|,
name|sp
parameter_list|)
value|(gdbarch_push_return_address (current_gdbarch, pc, sp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_pop_frame_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_pop_frame
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_pop_frame
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_pop_frame_ftype
modifier|*
name|pop_frame
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|POP_FRAME
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of POP_FRAME"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|POP_FRAME
argument_list|)
end_if

begin_define
define|#
directive|define
name|POP_FRAME
value|(gdbarch_pop_frame (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_store_struct_return_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_store_struct_return
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_store_struct_return
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_store_struct_return_ftype
modifier|*
name|store_struct_return
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|STORE_STRUCT_RETURN
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of STORE_STRUCT_RETURN"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|STORE_STRUCT_RETURN
argument_list|)
end_if

begin_define
define|#
directive|define
name|STORE_STRUCT_RETURN
parameter_list|(
name|addr
parameter_list|,
name|sp
parameter_list|)
value|(gdbarch_store_struct_return (current_gdbarch, addr, sp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_store_return_value_ftype
function_decl|)
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|valbuf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_store_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|valbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_store_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_store_return_value_ftype
modifier|*
name|store_return_value
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|STORE_RETURN_VALUE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of STORE_RETURN_VALUE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|STORE_RETURN_VALUE
argument_list|)
end_if

begin_define
define|#
directive|define
name|STORE_RETURN_VALUE
parameter_list|(
name|type
parameter_list|,
name|valbuf
parameter_list|)
value|(gdbarch_store_return_value (current_gdbarch, type, valbuf))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EXTRACT_STRUCT_VALUE_ADDRESS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch EXTRACT_STRUCT_VALUE_ADDRESS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EXTRACT_STRUCT_VALUE_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRACT_STRUCT_VALUE_ADDRESS_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|EXTRACT_STRUCT_VALUE_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRACT_STRUCT_VALUE_ADDRESS_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_extract_struct_value_address_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|EXTRACT_STRUCT_VALUE_ADDRESS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of EXTRACT_STRUCT_VALUE_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|EXTRACT_STRUCT_VALUE_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRACT_STRUCT_VALUE_ADDRESS_P
parameter_list|()
value|(gdbarch_extract_struct_value_address_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|EXTRACT_STRUCT_VALUE_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRACT_STRUCT_VALUE_ADDRESS
parameter_list|(
name|regbuf
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "EXTRACT_STRUCT_VALUE_ADDRESS"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_extract_struct_value_address_ftype
function_decl|)
parameter_list|(
name|char
modifier|*
name|regbuf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_extract_struct_value_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|char
modifier|*
name|regbuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_extract_struct_value_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_extract_struct_value_address_ftype
modifier|*
name|extract_struct_value_address
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|EXTRACT_STRUCT_VALUE_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of EXTRACT_STRUCT_VALUE_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|EXTRACT_STRUCT_VALUE_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRACT_STRUCT_VALUE_ADDRESS
parameter_list|(
name|regbuf
parameter_list|)
value|(gdbarch_extract_struct_value_address (current_gdbarch, regbuf))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|USE_STRUCT_CONVENTION
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_STRUCT_CONVENTION
parameter_list|(
name|gcc_p
parameter_list|,
name|value_type
parameter_list|)
value|(generic_use_struct_convention (gcc_p, value_type))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_use_struct_convention_ftype
function_decl|)
parameter_list|(
name|int
name|gcc_p
parameter_list|,
name|struct
name|type
modifier|*
name|value_type
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_use_struct_convention
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|gcc_p
parameter_list|,
name|struct
name|type
modifier|*
name|value_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_use_struct_convention
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_use_struct_convention_ftype
modifier|*
name|use_struct_convention
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|USE_STRUCT_CONVENTION
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of USE_STRUCT_CONVENTION"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|USE_STRUCT_CONVENTION
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_STRUCT_CONVENTION
parameter_list|(
name|gcc_p
parameter_list|,
name|value_type
parameter_list|)
value|(gdbarch_use_struct_convention (current_gdbarch, gcc_p, value_type))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_frame_init_saved_regs_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_frame_init_saved_regs
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_frame_init_saved_regs
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_frame_init_saved_regs_ftype
modifier|*
name|frame_init_saved_regs
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FRAME_INIT_SAVED_REGS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FRAME_INIT_SAVED_REGS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FRAME_INIT_SAVED_REGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_INIT_SAVED_REGS
parameter_list|(
name|frame
parameter_list|)
value|(gdbarch_frame_init_saved_regs (current_gdbarch, frame))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INIT_EXTRA_FRAME_INFO
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch INIT_EXTRA_FRAME_INFO */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|INIT_EXTRA_FRAME_INFO_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|INIT_EXTRA_FRAME_INFO_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|INIT_EXTRA_FRAME_INFO_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|INIT_EXTRA_FRAME_INFO_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_init_extra_frame_info_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|INIT_EXTRA_FRAME_INFO_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of INIT_EXTRA_FRAME_INFO"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|INIT_EXTRA_FRAME_INFO_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|INIT_EXTRA_FRAME_INFO_P
parameter_list|()
value|(gdbarch_init_extra_frame_info_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|INIT_EXTRA_FRAME_INFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|INIT_EXTRA_FRAME_INFO
parameter_list|(
name|fromleaf
parameter_list|,
name|frame
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "INIT_EXTRA_FRAME_INFO"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_init_extra_frame_info_ftype
function_decl|)
parameter_list|(
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_init_extra_frame_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|fromleaf
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_init_extra_frame_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_init_extra_frame_info_ftype
modifier|*
name|init_extra_frame_info
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|INIT_EXTRA_FRAME_INFO
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of INIT_EXTRA_FRAME_INFO"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|INIT_EXTRA_FRAME_INFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|INIT_EXTRA_FRAME_INFO
parameter_list|(
name|fromleaf
parameter_list|,
name|frame
parameter_list|)
value|(gdbarch_init_extra_frame_info (current_gdbarch, fromleaf, frame))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_skip_prologue_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|ip
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_skip_prologue
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_skip_prologue
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_skip_prologue_ftype
modifier|*
name|skip_prologue
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|SKIP_PROLOGUE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SKIP_PROLOGUE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|SKIP_PROLOGUE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|ip
parameter_list|)
value|(gdbarch_skip_prologue (current_gdbarch, ip))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|PROLOGUE_FRAMELESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|PROLOGUE_FRAMELESS_P
parameter_list|(
name|ip
parameter_list|)
value|(generic_prologue_frameless_p (ip))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_prologue_frameless_p_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|ip
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_prologue_frameless_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|ip
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_prologue_frameless_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_prologue_frameless_p_ftype
modifier|*
name|prologue_frameless_p
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|PROLOGUE_FRAMELESS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PROLOGUE_FRAMELESS_P"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PROLOGUE_FRAMELESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|PROLOGUE_FRAMELESS_P
parameter_list|(
name|ip
parameter_list|)
value|(gdbarch_prologue_frameless_p (current_gdbarch, ip))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_inner_than_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|lhs
parameter_list|,
name|CORE_ADDR
name|rhs
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_inner_than
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|lhs
parameter_list|,
name|CORE_ADDR
name|rhs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_inner_than
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_inner_than_ftype
modifier|*
name|inner_than
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|INNER_THAN
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of INNER_THAN"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|INNER_THAN
argument_list|)
end_if

begin_define
define|#
directive|define
name|INNER_THAN
parameter_list|(
name|lhs
parameter_list|,
name|rhs
parameter_list|)
value|(gdbarch_inner_than (current_gdbarch, lhs, rhs))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|BREAKPOINT_FROM_PC
argument_list|)
end_if

begin_define
define|#
directive|define
name|BREAKPOINT_FROM_PC
parameter_list|(
name|pcptr
parameter_list|,
name|lenptr
parameter_list|)
value|(legacy_breakpoint_from_pc (pcptr, lenptr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
function_decl|(
name|gdbarch_breakpoint_from_pc_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
modifier|*
name|pcptr
parameter_list|,
name|int
modifier|*
name|lenptr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|unsigned
name|char
modifier|*
name|gdbarch_breakpoint_from_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
modifier|*
name|pcptr
parameter_list|,
name|int
modifier|*
name|lenptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_breakpoint_from_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_breakpoint_from_pc_ftype
modifier|*
name|breakpoint_from_pc
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|BREAKPOINT_FROM_PC
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of BREAKPOINT_FROM_PC"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|BREAKPOINT_FROM_PC
argument_list|)
end_if

begin_define
define|#
directive|define
name|BREAKPOINT_FROM_PC
parameter_list|(
name|pcptr
parameter_list|,
name|lenptr
parameter_list|)
value|(gdbarch_breakpoint_from_pc (current_gdbarch, pcptr, lenptr))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|MEMORY_INSERT_BREAKPOINT
argument_list|)
end_if

begin_define
define|#
directive|define
name|MEMORY_INSERT_BREAKPOINT
parameter_list|(
name|addr
parameter_list|,
name|contents_cache
parameter_list|)
value|(default_memory_insert_breakpoint (addr, contents_cache))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_memory_insert_breakpoint_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|char
modifier|*
name|contents_cache
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_memory_insert_breakpoint
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|char
modifier|*
name|contents_cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_memory_insert_breakpoint
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_memory_insert_breakpoint_ftype
modifier|*
name|memory_insert_breakpoint
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|MEMORY_INSERT_BREAKPOINT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of MEMORY_INSERT_BREAKPOINT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|MEMORY_INSERT_BREAKPOINT
argument_list|)
end_if

begin_define
define|#
directive|define
name|MEMORY_INSERT_BREAKPOINT
parameter_list|(
name|addr
parameter_list|,
name|contents_cache
parameter_list|)
value|(gdbarch_memory_insert_breakpoint (current_gdbarch, addr, contents_cache))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|MEMORY_REMOVE_BREAKPOINT
argument_list|)
end_if

begin_define
define|#
directive|define
name|MEMORY_REMOVE_BREAKPOINT
parameter_list|(
name|addr
parameter_list|,
name|contents_cache
parameter_list|)
value|(default_memory_remove_breakpoint (addr, contents_cache))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_memory_remove_breakpoint_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|char
modifier|*
name|contents_cache
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_memory_remove_breakpoint
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|char
modifier|*
name|contents_cache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_memory_remove_breakpoint
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_memory_remove_breakpoint_ftype
modifier|*
name|memory_remove_breakpoint
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|MEMORY_REMOVE_BREAKPOINT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of MEMORY_REMOVE_BREAKPOINT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|MEMORY_REMOVE_BREAKPOINT
argument_list|)
end_if

begin_define
define|#
directive|define
name|MEMORY_REMOVE_BREAKPOINT
parameter_list|(
name|addr
parameter_list|,
name|contents_cache
parameter_list|)
value|(gdbarch_memory_remove_breakpoint (current_gdbarch, addr, contents_cache))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_decr_pc_after_break
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_decr_pc_after_break
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|decr_pc_after_break
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|DECR_PC_AFTER_BREAK
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DECR_PC_AFTER_BREAK"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|DECR_PC_AFTER_BREAK
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|(gdbarch_decr_pc_after_break (current_gdbarch))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|PREPARE_TO_PROCEED
argument_list|)
end_if

begin_define
define|#
directive|define
name|PREPARE_TO_PROCEED
parameter_list|(
name|select_it
parameter_list|)
value|(default_prepare_to_proceed (select_it))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_prepare_to_proceed_ftype
function_decl|)
parameter_list|(
name|int
name|select_it
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_prepare_to_proceed
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|select_it
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_prepare_to_proceed
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_prepare_to_proceed_ftype
modifier|*
name|prepare_to_proceed
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|PREPARE_TO_PROCEED
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PREPARE_TO_PROCEED"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PREPARE_TO_PROCEED
argument_list|)
end_if

begin_define
define|#
directive|define
name|PREPARE_TO_PROCEED
parameter_list|(
name|select_it
parameter_list|)
value|(gdbarch_prepare_to_proceed (current_gdbarch, select_it))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_function_start_offset
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_function_start_offset
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|function_start_offset
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FUNCTION_START_OFFSET
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FUNCTION_START_OFFSET"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FUNCTION_START_OFFSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|FUNCTION_START_OFFSET
value|(gdbarch_function_start_offset (current_gdbarch))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|REMOTE_TRANSLATE_XFER_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|REMOTE_TRANSLATE_XFER_ADDRESS
parameter_list|(
name|gdb_addr
parameter_list|,
name|gdb_len
parameter_list|,
name|rem_addr
parameter_list|,
name|rem_len
parameter_list|)
value|(generic_remote_translate_xfer_address (gdb_addr, gdb_len, rem_addr, rem_len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_remote_translate_xfer_address_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|gdb_addr
parameter_list|,
name|int
name|gdb_len
parameter_list|,
name|CORE_ADDR
modifier|*
name|rem_addr
parameter_list|,
name|int
modifier|*
name|rem_len
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_remote_translate_xfer_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|gdb_addr
parameter_list|,
name|int
name|gdb_len
parameter_list|,
name|CORE_ADDR
modifier|*
name|rem_addr
parameter_list|,
name|int
modifier|*
name|rem_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_remote_translate_xfer_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_remote_translate_xfer_address_ftype
modifier|*
name|remote_translate_xfer_address
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REMOTE_TRANSLATE_XFER_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REMOTE_TRANSLATE_XFER_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REMOTE_TRANSLATE_XFER_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|REMOTE_TRANSLATE_XFER_ADDRESS
parameter_list|(
name|gdb_addr
parameter_list|,
name|gdb_len
parameter_list|,
name|rem_addr
parameter_list|,
name|rem_len
parameter_list|)
value|(gdbarch_remote_translate_xfer_address (current_gdbarch, gdb_addr, gdb_len, rem_addr, rem_len))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_frame_args_skip
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_frame_args_skip
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|frame_args_skip
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FRAME_ARGS_SKIP
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FRAME_ARGS_SKIP"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FRAME_ARGS_SKIP
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_ARGS_SKIP
value|(gdbarch_frame_args_skip (current_gdbarch))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|FRAMELESS_FUNCTION_INVOCATION
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAMELESS_FUNCTION_INVOCATION
parameter_list|(
name|fi
parameter_list|)
value|(generic_frameless_function_invocation_not (fi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_frameless_function_invocation_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_frameless_function_invocation
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_frameless_function_invocation
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_frameless_function_invocation_ftype
modifier|*
name|frameless_function_invocation
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FRAMELESS_FUNCTION_INVOCATION
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FRAMELESS_FUNCTION_INVOCATION"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FRAMELESS_FUNCTION_INVOCATION
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAMELESS_FUNCTION_INVOCATION
parameter_list|(
name|fi
parameter_list|)
value|(gdbarch_frameless_function_invocation (current_gdbarch, fi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_frame_chain_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_frame_chain
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_frame_chain
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_frame_chain_ftype
modifier|*
name|frame_chain
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FRAME_CHAIN
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FRAME_CHAIN"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FRAME_CHAIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|frame
parameter_list|)
value|(gdbarch_frame_chain (current_gdbarch, frame))
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
comment|/* Define a default FRAME_CHAIN_VALID, in the form that is suitable for    most targets.  If FRAME_CHAIN_VALID returns zero it means that the    given frame is the outermost one and has no caller.       XXXX - both default and alternate frame_chain_valid functions are    deprecated.  New code should use dummy frames and one of the generic    functions. */
end_comment

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|FRAME_CHAIN_VALID
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
value|(func_frame_chain_valid (chain, thisframe))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_frame_chain_valid_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|chain
parameter_list|,
name|struct
name|frame_info
modifier|*
name|thisframe
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_frame_chain_valid
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|chain
parameter_list|,
name|struct
name|frame_info
modifier|*
name|thisframe
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_frame_chain_valid
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_frame_chain_valid_ftype
modifier|*
name|frame_chain_valid
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FRAME_CHAIN_VALID
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FRAME_CHAIN_VALID"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FRAME_CHAIN_VALID
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
value|(gdbarch_frame_chain_valid (current_gdbarch, chain, thisframe))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_frame_saved_pc_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_frame_saved_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_frame_saved_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_frame_saved_pc_ftype
modifier|*
name|frame_saved_pc
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FRAME_SAVED_PC
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FRAME_SAVED_PC"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FRAME_SAVED_PC
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|fi
parameter_list|)
value|(gdbarch_frame_saved_pc (current_gdbarch, fi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_frame_args_address_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_frame_args_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_frame_args_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_frame_args_address_ftype
modifier|*
name|frame_args_address
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FRAME_ARGS_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FRAME_ARGS_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FRAME_ARGS_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|(gdbarch_frame_args_address (current_gdbarch, fi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_frame_locals_address_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_frame_locals_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|fi
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_frame_locals_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_frame_locals_address_ftype
modifier|*
name|frame_locals_address
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FRAME_LOCALS_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FRAME_LOCALS_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FRAME_LOCALS_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|(gdbarch_frame_locals_address (current_gdbarch, fi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_saved_pc_after_call_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_saved_pc_after_call
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_saved_pc_after_call
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_saved_pc_after_call_ftype
modifier|*
name|saved_pc_after_call
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|SAVED_PC_AFTER_CALL
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SAVED_PC_AFTER_CALL"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|SAVED_PC_AFTER_CALL
argument_list|)
end_if

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
value|(gdbarch_saved_pc_after_call (current_gdbarch, frame))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_frame_num_args_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_frame_num_args
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_frame_num_args
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_frame_num_args_ftype
modifier|*
name|frame_num_args
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|FRAME_NUM_ARGS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FRAME_NUM_ARGS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FRAME_NUM_ARGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS
parameter_list|(
name|frame
parameter_list|)
value|(gdbarch_frame_num_args (current_gdbarch, frame))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STACK_ALIGN
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch STACK_ALIGN */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STACK_ALIGN_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|STACK_ALIGN_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|STACK_ALIGN_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|STACK_ALIGN_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_stack_align_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|STACK_ALIGN_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of STACK_ALIGN"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|STACK_ALIGN_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|STACK_ALIGN_P
parameter_list|()
value|(gdbarch_stack_align_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|STACK_ALIGN
argument_list|)
end_if

begin_define
define|#
directive|define
name|STACK_ALIGN
parameter_list|(
name|sp
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "STACK_ALIGN"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_stack_align_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_stack_align
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_stack_align
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_stack_align_ftype
modifier|*
name|stack_align
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|STACK_ALIGN
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of STACK_ALIGN"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|STACK_ALIGN
argument_list|)
end_if

begin_define
define|#
directive|define
name|STACK_ALIGN
parameter_list|(
name|sp
parameter_list|)
value|(gdbarch_stack_align (current_gdbarch, sp))
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
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|EXTRA_STACK_ALIGNMENT_NEEDED
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRA_STACK_ALIGNMENT_NEEDED
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_extra_stack_alignment_needed
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_extra_stack_alignment_needed
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|extra_stack_alignment_needed
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|EXTRA_STACK_ALIGNMENT_NEEDED
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of EXTRA_STACK_ALIGNMENT_NEEDED"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|EXTRA_STACK_ALIGNMENT_NEEDED
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRA_STACK_ALIGNMENT_NEEDED
value|(gdbarch_extra_stack_alignment_needed (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REG_STRUCT_HAS_ADDR
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch REG_STRUCT_HAS_ADDR */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|REG_STRUCT_HAS_ADDR_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|REG_STRUCT_HAS_ADDR_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|REG_STRUCT_HAS_ADDR_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|REG_STRUCT_HAS_ADDR_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_reg_struct_has_addr_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REG_STRUCT_HAS_ADDR_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REG_STRUCT_HAS_ADDR"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REG_STRUCT_HAS_ADDR_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|REG_STRUCT_HAS_ADDR_P
parameter_list|()
value|(gdbarch_reg_struct_has_addr_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|REG_STRUCT_HAS_ADDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|REG_STRUCT_HAS_ADDR
parameter_list|(
name|gcc_p
parameter_list|,
name|type
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "REG_STRUCT_HAS_ADDR"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_reg_struct_has_addr_ftype
function_decl|)
parameter_list|(
name|int
name|gcc_p
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_reg_struct_has_addr
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|gcc_p
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_reg_struct_has_addr
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_reg_struct_has_addr_ftype
modifier|*
name|reg_struct_has_addr
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|REG_STRUCT_HAS_ADDR
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REG_STRUCT_HAS_ADDR"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|REG_STRUCT_HAS_ADDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|REG_STRUCT_HAS_ADDR
parameter_list|(
name|gcc_p
parameter_list|,
name|type
parameter_list|)
value|(gdbarch_reg_struct_has_addr (current_gdbarch, gcc_p, type))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SAVE_DUMMY_FRAME_TOS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch SAVE_DUMMY_FRAME_TOS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SAVE_DUMMY_FRAME_TOS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|SAVE_DUMMY_FRAME_TOS_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|SAVE_DUMMY_FRAME_TOS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|SAVE_DUMMY_FRAME_TOS_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_save_dummy_frame_tos_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|SAVE_DUMMY_FRAME_TOS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SAVE_DUMMY_FRAME_TOS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|SAVE_DUMMY_FRAME_TOS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|SAVE_DUMMY_FRAME_TOS_P
parameter_list|()
value|(gdbarch_save_dummy_frame_tos_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|SAVE_DUMMY_FRAME_TOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SAVE_DUMMY_FRAME_TOS
parameter_list|(
name|sp
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "SAVE_DUMMY_FRAME_TOS"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_save_dummy_frame_tos_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_save_dummy_frame_tos
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_save_dummy_frame_tos
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_save_dummy_frame_tos_ftype
modifier|*
name|save_dummy_frame_tos
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|SAVE_DUMMY_FRAME_TOS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SAVE_DUMMY_FRAME_TOS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|SAVE_DUMMY_FRAME_TOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SAVE_DUMMY_FRAME_TOS
parameter_list|(
name|sp
parameter_list|)
value|(gdbarch_save_dummy_frame_tos (current_gdbarch, sp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_parm_boundary
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_parm_boundary
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|parm_boundary
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|PARM_BOUNDARY
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PARM_BOUNDARY"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|PARM_BOUNDARY
argument_list|)
end_if

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|(gdbarch_parm_boundary (current_gdbarch))
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
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_FLOAT_FORMAT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_FLOAT_FORMAT
value|(default_float_format (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
specifier|const
name|struct
name|floatformat
modifier|*
name|gdbarch_float_format
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_float_format
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|struct
name|floatformat
modifier|*
name|float_format
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_FLOAT_FORMAT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_FLOAT_FORMAT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_FLOAT_FORMAT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_FLOAT_FORMAT
value|(gdbarch_float_format (current_gdbarch))
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
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_DOUBLE_FORMAT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_DOUBLE_FORMAT
value|(default_double_format (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
specifier|const
name|struct
name|floatformat
modifier|*
name|gdbarch_double_format
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_double_format
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|struct
name|floatformat
modifier|*
name|double_format
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_DOUBLE_FORMAT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_DOUBLE_FORMAT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_DOUBLE_FORMAT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_DOUBLE_FORMAT
value|(gdbarch_double_format (current_gdbarch))
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
comment|/* Default (value) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_LONG_DOUBLE_FORMAT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_LONG_DOUBLE_FORMAT
value|(default_double_format (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
specifier|const
name|struct
name|floatformat
modifier|*
name|gdbarch_long_double_format
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_long_double_format
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|struct
name|floatformat
modifier|*
name|long_double_format
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_LONG_DOUBLE_FORMAT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_LONG_DOUBLE_FORMAT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_LONG_DOUBLE_FORMAT
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_LONG_DOUBLE_FORMAT
value|(gdbarch_long_double_format (current_gdbarch))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|CONVERT_FROM_FUNC_PTR_ADDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONVERT_FROM_FUNC_PTR_ADDR
parameter_list|(
name|addr
parameter_list|)
value|(core_addr_identity (addr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_convert_from_func_ptr_addr_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_convert_from_func_ptr_addr
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_convert_from_func_ptr_addr
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_convert_from_func_ptr_addr_ftype
modifier|*
name|convert_from_func_ptr_addr
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|CONVERT_FROM_FUNC_PTR_ADDR
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CONVERT_FROM_FUNC_PTR_ADDR"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|CONVERT_FROM_FUNC_PTR_ADDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONVERT_FROM_FUNC_PTR_ADDR
parameter_list|(
name|addr
parameter_list|)
value|(gdbarch_convert_from_func_ptr_addr (current_gdbarch, addr))
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
comment|/* On some machines there are bits in addresses which are not really    part of the address, but are used by the kernel, the hardware, etc.    for special purposes.  ADDR_BITS_REMOVE takes out any such bits so    we get a "real" address such as one would find in a symbol table.    This is used only for addresses of instructions, and even then I'm    not sure it's used in all contexts.  It exists to deal with there    being a few stray bits in the PC which would mislead us, not as some    sort of generic thing to handle alignment or segmentation (it's    possible it should be in TARGET_READ_PC instead). */
end_comment

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|ADDR_BITS_REMOVE
argument_list|)
end_if

begin_define
define|#
directive|define
name|ADDR_BITS_REMOVE
parameter_list|(
name|addr
parameter_list|)
value|(core_addr_identity (addr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_addr_bits_remove_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_addr_bits_remove
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_addr_bits_remove
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_addr_bits_remove_ftype
modifier|*
name|addr_bits_remove
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|ADDR_BITS_REMOVE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of ADDR_BITS_REMOVE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|ADDR_BITS_REMOVE
argument_list|)
end_if

begin_define
define|#
directive|define
name|ADDR_BITS_REMOVE
parameter_list|(
name|addr
parameter_list|)
value|(gdbarch_addr_bits_remove (current_gdbarch, addr))
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
comment|/* It is not at all clear why SMASH_TEXT_ADDRESS is not folded into    ADDR_BITS_REMOVE. */
end_comment

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|SMASH_TEXT_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SMASH_TEXT_ADDRESS
parameter_list|(
name|addr
parameter_list|)
value|(core_addr_identity (addr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_smash_text_address_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_smash_text_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_smash_text_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_smash_text_address_ftype
modifier|*
name|smash_text_address
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|SMASH_TEXT_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SMASH_TEXT_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|SMASH_TEXT_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|SMASH_TEXT_ADDRESS
parameter_list|(
name|addr
parameter_list|)
value|(gdbarch_smash_text_address (current_gdbarch, addr))
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
comment|/* FIXME/cagney/2001-01-18: This should be split in two.  A target method that indicates if    the target needs software single step.  An ISA method to implement it.       FIXME/cagney/2001-01-18: This should be replaced with something that inserts breakpoints    using the breakpoint system instead of blatting memory directly (as with rs6000).       FIXME/cagney/2001-01-18: The logic is backwards.  It should be asking if the target can    single step.  If not, then implement single step using breakpoints. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SOFTWARE_SINGLE_STEP
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch SOFTWARE_SINGLE_STEP */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SOFTWARE_SINGLE_STEP_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|SOFTWARE_SINGLE_STEP_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|SOFTWARE_SINGLE_STEP_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|SOFTWARE_SINGLE_STEP_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_software_single_step_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|SOFTWARE_SINGLE_STEP_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SOFTWARE_SINGLE_STEP"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|SOFTWARE_SINGLE_STEP_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|SOFTWARE_SINGLE_STEP_P
parameter_list|()
value|(gdbarch_software_single_step_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|SOFTWARE_SINGLE_STEP
argument_list|)
end_if

begin_define
define|#
directive|define
name|SOFTWARE_SINGLE_STEP
parameter_list|(
name|sig
parameter_list|,
name|insert_breakpoints_p
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "SOFTWARE_SINGLE_STEP"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_software_single_step_ftype
function_decl|)
parameter_list|(
name|enum
name|target_signal
name|sig
parameter_list|,
name|int
name|insert_breakpoints_p
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_software_single_step
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|enum
name|target_signal
name|sig
parameter_list|,
name|int
name|insert_breakpoints_p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_software_single_step
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_software_single_step_ftype
modifier|*
name|software_single_step
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|SOFTWARE_SINGLE_STEP
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SOFTWARE_SINGLE_STEP"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|SOFTWARE_SINGLE_STEP
argument_list|)
end_if

begin_define
define|#
directive|define
name|SOFTWARE_SINGLE_STEP
parameter_list|(
name|sig
parameter_list|,
name|insert_breakpoints_p
parameter_list|)
value|(gdbarch_software_single_step (current_gdbarch, sig, insert_breakpoints_p))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|TARGET_PRINT_INSN
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_PRINT_INSN
parameter_list|(
name|vma
parameter_list|,
name|info
parameter_list|)
value|(legacy_print_insn (vma, info))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_print_insn_ftype
function_decl|)
parameter_list|(
name|bfd_vma
name|vma
parameter_list|,
name|disassemble_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_print_insn
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|bfd_vma
name|vma
parameter_list|,
name|disassemble_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_print_insn
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_print_insn_ftype
modifier|*
name|print_insn
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|TARGET_PRINT_INSN
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_PRINT_INSN"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_PRINT_INSN
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_PRINT_INSN
parameter_list|(
name|vma
parameter_list|,
name|info
parameter_list|)
value|(gdbarch_print_insn (current_gdbarch, vma, info))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|SKIP_TRAMPOLINE_CODE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SKIP_TRAMPOLINE_CODE
parameter_list|(
name|pc
parameter_list|)
value|(generic_skip_trampoline_code (pc))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_skip_trampoline_code_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_skip_trampoline_code
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_skip_trampoline_code
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_skip_trampoline_code_ftype
modifier|*
name|skip_trampoline_code
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|SKIP_TRAMPOLINE_CODE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SKIP_TRAMPOLINE_CODE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|SKIP_TRAMPOLINE_CODE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SKIP_TRAMPOLINE_CODE
parameter_list|(
name|pc
parameter_list|)
value|(gdbarch_skip_trampoline_code (current_gdbarch, pc))
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
comment|/* For SVR4 shared libraries, each call goes through a small piece of    trampoline code in the ".plt" section.  IN_SOLIB_CALL_TRAMPOLINE evaluates    to nonzero if we are current stopped in one of these. */
end_comment

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|IN_SOLIB_CALL_TRAMPOLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|IN_SOLIB_CALL_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|(generic_in_solib_call_trampoline (pc, name))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_in_solib_call_trampoline_ftype
function_decl|)
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_in_solib_call_trampoline
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|,
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_in_solib_call_trampoline
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_in_solib_call_trampoline_ftype
modifier|*
name|in_solib_call_trampoline
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|IN_SOLIB_CALL_TRAMPOLINE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of IN_SOLIB_CALL_TRAMPOLINE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|IN_SOLIB_CALL_TRAMPOLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|IN_SOLIB_CALL_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|(gdbarch_in_solib_call_trampoline (current_gdbarch, pc, name))
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
comment|/* A target might have problems with watchpoints as soon as the stack    frame of the current function has been destroyed.  This mostly happens    as the first action in a funtion's epilogue.  in_function_epilogue_p()    is defined to return a non-zero value if either the given addr is one    instruction after the stack destroying instruction up to the trailing    return instruction or if we can figure out that the stack frame has    already been invalidated regardless of the value of addr.  Targets    which don't suffer from that problem could just let this functionality    untouched. */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_in_function_epilogue_p_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_in_function_epilogue_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_in_function_epilogue_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_in_function_epilogue_p_ftype
modifier|*
name|in_function_epilogue_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Given a vector of command-line arguments, return a newly allocated    string which, when passed to the create_inferior function, will be    parsed (on Unix systems, by the shell) to yield the same vector.    This function should call error() if the argument vector is not    representable for this target or if this target does not support    command-line arguments.    ARGC is the number of elements in the vector.    ARGV is an array of strings, one per argument. */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
function_decl|(
name|gdbarch_construct_inferior_arguments_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|char
modifier|*
name|gdbarch_construct_inferior_arguments
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_construct_inferior_arguments
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_construct_inferior_arguments_ftype
modifier|*
name|construct_inferior_arguments
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DWARF2_BUILD_FRAME_INFO
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DWARF2_BUILD_FRAME_INFO */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DWARF2_BUILD_FRAME_INFO_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF2_BUILD_FRAME_INFO_P
parameter_list|()
value|(1)
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
comment|/* Default predicate for non- multi-arch targets. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|DWARF2_BUILD_FRAME_INFO_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF2_BUILD_FRAME_INFO_P
parameter_list|()
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_dwarf2_build_frame_info_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|DWARF2_BUILD_FRAME_INFO_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DWARF2_BUILD_FRAME_INFO"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|DWARF2_BUILD_FRAME_INFO_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF2_BUILD_FRAME_INFO_P
parameter_list|()
value|(gdbarch_dwarf2_build_frame_info_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|DWARF2_BUILD_FRAME_INFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF2_BUILD_FRAME_INFO
parameter_list|(
name|objfile
parameter_list|)
value|(internal_error (__FILE__, __LINE__, "DWARF2_BUILD_FRAME_INFO"), 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_dwarf2_build_frame_info_ftype
function_decl|)
parameter_list|(
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_dwarf2_build_frame_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|objfile
modifier|*
name|objfile
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_dwarf2_build_frame_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_dwarf2_build_frame_info_ftype
modifier|*
name|dwarf2_build_frame_info
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|DWARF2_BUILD_FRAME_INFO
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DWARF2_BUILD_FRAME_INFO"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|DWARF2_BUILD_FRAME_INFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF2_BUILD_FRAME_INFO
parameter_list|(
name|objfile
parameter_list|)
value|(gdbarch_dwarf2_build_frame_info (current_gdbarch, objfile))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|ELF_MAKE_MSYMBOL_SPECIAL
argument_list|)
end_if

begin_define
define|#
directive|define
name|ELF_MAKE_MSYMBOL_SPECIAL
parameter_list|(
name|sym
parameter_list|,
name|msym
parameter_list|)
value|(default_elf_make_msymbol_special (sym, msym))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_elf_make_msymbol_special_ftype
function_decl|)
parameter_list|(
name|asymbol
modifier|*
name|sym
parameter_list|,
name|struct
name|minimal_symbol
modifier|*
name|msym
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_elf_make_msymbol_special
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|asymbol
modifier|*
name|sym
parameter_list|,
name|struct
name|minimal_symbol
modifier|*
name|msym
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_elf_make_msymbol_special
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_elf_make_msymbol_special_ftype
modifier|*
name|elf_make_msymbol_special
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|ELF_MAKE_MSYMBOL_SPECIAL
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of ELF_MAKE_MSYMBOL_SPECIAL"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|ELF_MAKE_MSYMBOL_SPECIAL
argument_list|)
end_if

begin_define
define|#
directive|define
name|ELF_MAKE_MSYMBOL_SPECIAL
parameter_list|(
name|sym
parameter_list|,
name|msym
parameter_list|)
value|(gdbarch_elf_make_msymbol_special (current_gdbarch, sym, msym))
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
comment|/* Default (function) for non- multi-arch platforms. */
end_comment

begin_if
if|#
directive|if
operator|(
operator|!
name|GDB_MULTI_ARCH
operator|)
operator|&&
operator|!
name|defined
argument_list|(
name|COFF_MAKE_MSYMBOL_SPECIAL
argument_list|)
end_if

begin_define
define|#
directive|define
name|COFF_MAKE_MSYMBOL_SPECIAL
parameter_list|(
name|val
parameter_list|,
name|msym
parameter_list|)
value|(default_coff_make_msymbol_special (val, msym))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_coff_make_msymbol_special_ftype
function_decl|)
parameter_list|(
name|int
name|val
parameter_list|,
name|struct
name|minimal_symbol
modifier|*
name|msym
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_coff_make_msymbol_special
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|val
parameter_list|,
name|struct
name|minimal_symbol
modifier|*
name|msym
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_coff_make_msymbol_special
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_coff_make_msymbol_special_ftype
modifier|*
name|coff_make_msymbol_special
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|&&
name|defined
argument_list|(
name|COFF_MAKE_MSYMBOL_SPECIAL
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of COFF_MAKE_MSYMBOL_SPECIAL"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GDB_MULTI_ARCH
end_if

begin_if
if|#
directive|if
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|COFF_MAKE_MSYMBOL_SPECIAL
argument_list|)
end_if

begin_define
define|#
directive|define
name|COFF_MAKE_MSYMBOL_SPECIAL
parameter_list|(
name|val
parameter_list|,
name|msym
parameter_list|)
value|(gdbarch_coff_make_msymbol_special (current_gdbarch, val, msym))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|struct
name|gdbarch_tdep
modifier|*
name|gdbarch_tdep
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Mechanism for co-ordinating the selection of a specific    architecture.     GDB targets (*-tdep.c) can register an interest in a specific    architecture.  Other GDB components can register a need to maintain    per-architecture data.     The mechanisms below ensures that there is only a loose connection    between the set-architecture command and the various GDB    components.  Each component can independently register their need    to maintain architecture specific data with gdbarch.     Pragmatics:     Previously, a single TARGET_ARCHITECTURE_HOOK was provided.  It    didn't scale.     The more traditional mega-struct containing architecture specific    data for all the various GDB components was also considered.  Since    GDB is built from a variable number of (fairly independent)    components it was determined that the global aproach was not    applicable. */
end_comment

begin_comment
comment|/* Register a new architectural family with GDB.     Register support for the specified ARCHITECTURE with GDB.  When    gdbarch determines that the specified architecture has been    selected, the corresponding INIT function is called.     --     The INIT function takes two parameters: INFO which contains the    information available to gdbarch about the (possibly new)    architecture; ARCHES which is a list of the previously created    ``struct gdbarch'' for this architecture.     The INIT function parameter INFO shall, as far as possible, be    pre-initialized with information obtained from INFO.ABFD or    previously selected architecture (if similar).     The INIT function shall return any of: NULL - indicating that it    doesn't recognize the selected architecture; an existing ``struct    gdbarch'' from the ARCHES list - indicating that the new    architecture is just a synonym for an earlier architecture (see    gdbarch_list_lookup_by_info()); a newly created ``struct gdbarch''    - that describes the selected architecture (see gdbarch_alloc()).     The DUMP_TDEP function shall print out all target specific values.    Care should be taken to ensure that the function works in both the    multi-arch and non- multi-arch cases. */
end_comment

begin_struct
struct|struct
name|gdbarch_list
block|{
name|struct
name|gdbarch
modifier|*
name|gdbarch
decl_stmt|;
name|struct
name|gdbarch_list
modifier|*
name|next
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gdbarch_info
block|{
comment|/* Use default: NULL (ZERO). */
specifier|const
name|struct
name|bfd_arch_info
modifier|*
name|bfd_arch_info
decl_stmt|;
comment|/* Use default: BFD_ENDIAN_UNKNOWN (NB: is not ZERO).  */
name|int
name|byte_order
decl_stmt|;
comment|/* Use default: NULL (ZERO). */
name|bfd
modifier|*
name|abfd
decl_stmt|;
comment|/* Use default: NULL (ZERO). */
name|struct
name|gdbarch_tdep_info
modifier|*
name|tdep_info
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|gdbarch
modifier|*
function_decl|(
name|gdbarch_init_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch_info
name|info
parameter_list|,
name|struct
name|gdbarch_list
modifier|*
name|arches
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_dump_tdep_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|ui_file
modifier|*
name|file
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* DEPRECATED - use gdbarch_register() */
end_comment

begin_function_decl
specifier|extern
name|void
name|register_gdbarch_init
parameter_list|(
name|enum
name|bfd_architecture
name|architecture
parameter_list|,
name|gdbarch_init_ftype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|gdbarch_register
parameter_list|(
name|enum
name|bfd_architecture
name|architecture
parameter_list|,
name|gdbarch_init_ftype
modifier|*
parameter_list|,
name|gdbarch_dump_tdep_ftype
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return a freshly allocated, NULL terminated, array of the valid    architecture names.  Since architectures are registered during the    _initialize phase this function only returns useful information    once initialization has been completed. */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
modifier|*
name|gdbarch_printable_names
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper function.  Search the list of ARCHES for a GDBARCH that    matches the information provided by INFO. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|gdbarch_list
modifier|*
name|gdbarch_list_lookup_by_info
parameter_list|(
name|struct
name|gdbarch_list
modifier|*
name|arches
parameter_list|,
specifier|const
name|struct
name|gdbarch_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper function.  Create a preliminary ``struct gdbarch''.  Perform    basic initialization using values obtained from the INFO andTDEP    parameters.  set_gdbarch_*() functions are called to complete the    initialization of the object. */
end_comment

begin_function_decl
specifier|extern
name|struct
name|gdbarch
modifier|*
name|gdbarch_alloc
parameter_list|(
specifier|const
name|struct
name|gdbarch_info
modifier|*
name|info
parameter_list|,
name|struct
name|gdbarch_tdep
modifier|*
name|tdep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper function.  Free a partially-constructed ``struct gdbarch''.    It is assumed that the caller freeds the ``struct    gdbarch_tdep''. */
end_comment

begin_function_decl
specifier|extern
name|void
name|gdbarch_free
parameter_list|(
name|struct
name|gdbarch
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper function. Force an update of the current architecture.     The actual architecture selected is determined by INFO, ``(gdb) set    architecture'' et.al., the existing architecture and BFD's default    architecture.  INFO should be initialized to zero and then selected    fields should be updated.     Returns non-zero if the update succeeds */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_update_p
parameter_list|(
name|struct
name|gdbarch_info
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register per-architecture data-pointer.     Reserve space for a per-architecture data-pointer.  An identifier    for the reserved data-pointer is returned.  That identifer should    be saved in a local static variable.     The per-architecture data-pointer can be initialized in one of two    ways: The value can be set explicitly using a call to    set_gdbarch_data(); the value can be set implicitly using the value    returned by a non-NULL INIT() callback.  INIT(), when non-NULL is    called after the basic architecture vector has been created.     When a previously created architecture is re-selected, the    per-architecture data-pointer for that previous architecture is    restored.  INIT() is not called.     During initialization, multiple assignments of the data-pointer are    allowed, non-NULL values are deleted by calling FREE().  If the    architecture is deleted using gdbarch_free() all non-NULL data    pointers are also deleted using FREE().     Multiple registrarants for any architecture are allowed (and    strongly encouraged).  */
end_comment

begin_struct_decl
struct_decl|struct
name|gdbarch_data
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
modifier|*
function_decl|(
name|gdbarch_data_init_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_data_free_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|void
modifier|*
name|pointer
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|struct
name|gdbarch_data
modifier|*
name|register_gdbarch_data
parameter_list|(
name|gdbarch_data_init_ftype
modifier|*
name|init
parameter_list|,
name|gdbarch_data_free_ftype
modifier|*
name|free
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_data
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|gdbarch_data
modifier|*
name|data
parameter_list|,
name|void
modifier|*
name|pointer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
modifier|*
name|gdbarch_data
parameter_list|(
name|struct
name|gdbarch_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register per-architecture memory region.     Provide a memory-region swap mechanism.  Per-architecture memory    region are created.  These memory regions are swapped whenever the    architecture is changed.  For a new architecture, the memory region    is initialized with zero (0) and the INIT function is called.     Memory regions are swapped / initialized in the order that they are    registered.  NULL DATA and/or INIT values can be specified.     New code should use register_gdbarch_data(). */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_swap_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|register_gdbarch_swap
parameter_list|(
name|void
modifier|*
name|data
parameter_list|,
name|unsigned
name|long
name|size
parameter_list|,
name|gdbarch_swap_ftype
modifier|*
name|init
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|REGISTER_GDBARCH_SWAP
parameter_list|(
name|VAR
parameter_list|)
value|register_gdbarch_swap (&(VAR), sizeof ((VAR)), NULL)
end_define

begin_comment
comment|/* The target-system-dependent byte order is dynamic */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_byte_order
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BYTE_ORDER
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|(target_byte_order + 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|target_byte_order_auto
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BYTE_ORDER_AUTO
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER_AUTO
value|(target_byte_order_auto + 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The target-system-dependent BFD architecture is dynamic */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_architecture_auto
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ARCHITECTURE_AUTO
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ARCHITECTURE_AUTO
value|(target_architecture_auto + 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|bfd_arch_info
modifier|*
name|target_architecture
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ARCHITECTURE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ARCHITECTURE
value|(target_architecture + 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The target-system-dependent disassembler is semi-dynamic */
end_comment

begin_function_decl
specifier|extern
name|int
name|dis_asm_read_memory
parameter_list|(
name|bfd_vma
name|memaddr
parameter_list|,
name|bfd_byte
modifier|*
name|myaddr
parameter_list|,
name|unsigned
name|int
name|len
parameter_list|,
name|disassemble_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dis_asm_memory_error
parameter_list|(
name|int
name|status
parameter_list|,
name|bfd_vma
name|memaddr
parameter_list|,
name|disassemble_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dis_asm_print_address
parameter_list|(
name|bfd_vma
name|addr
parameter_list|,
name|disassemble_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|tm_print_insn
function_decl|)
parameter_list|(
name|bfd_vma
parameter_list|,
name|disassemble_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|disassemble_info
name|tm_print_insn_info
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_PRINT_INSN_INFO
end_ifndef

begin_define
define|#
directive|define
name|TARGET_PRINT_INSN_INFO
value|(&tm_print_insn_info)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set the dynamic target-system-dependent parameters (architecture,    byte-order, ...) using information found in the BFD */
end_comment

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_from_file
parameter_list|(
name|bfd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Initialize the current architecture to the "first" one we find on    our list.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|initialize_current_architecture
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For non-multiarched targets, do any initialization of the default    gdbarch object necessary after the _initialize_MODULE functions    have run.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|initialize_non_multiarch
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* gdbarch trace variable */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|gdbarch_debug
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|gdbarch_dump
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|ui_file
modifier|*
name|file
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

