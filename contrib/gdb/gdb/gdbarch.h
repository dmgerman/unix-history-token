begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_comment
comment|/* THIS FILE IS GENERATED */
end_comment

begin_comment
comment|/* Dynamic architecture support for GDB, the GNU debugger.     Copyright 1998, 1999, 2000, 2001, 2002, 2003, 2004 Free    Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_struct_decl
struct_decl|struct
name|floatformat
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ui_file
struct_decl|;
end_struct_decl

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

begin_struct_decl
struct_decl|struct
name|regcache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reggroup
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regset
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|disassemble_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|target_ops
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

begin_function_decl
specifier|extern
name|enum
name|gdb_osabi
name|gdbarch_osabi
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set_gdbarch_osabi() - not applicable - pre-initialized. */
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
name|TARGET_OSABI
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of TARGET_OSABI"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_OSABI
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_OSABI
value|(gdbarch_osabi (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The following are initialized by the target dependent code. */
end_comment

begin_comment
comment|/* Number of bits in a char or unsigned char for the target machine.    Just like CHAR_BIT in<limits.h> but describes the target machine.    v:2:TARGET_CHAR_BIT:int:char_bit::::8 * sizeof (char):8::0:       Number of bits in a short or unsigned short for the target machine. */
end_comment

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

begin_comment
comment|/* Number of bits in an int or unsigned int for the target machine. */
end_comment

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

begin_comment
comment|/* Number of bits in a long or unsigned long for the target machine. */
end_comment

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

begin_comment
comment|/* Number of bits in a long long or unsigned long long for the target    machine. */
end_comment

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

begin_comment
comment|/* Number of bits in a float for the target machine. */
end_comment

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

begin_comment
comment|/* Number of bits in a double for the target machine. */
end_comment

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

begin_comment
comment|/* Number of bits in a long double for the target machine. */
end_comment

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

begin_comment
comment|/* For most targets, a pointer on the target and its representation as an    address in GDB have the same size and "look the same".  For such a    target, you need only set TARGET_PTR_BIT / ptr_bit and TARGET_ADDR_BIT    / addr_bit will be set from it.       If TARGET_PTR_BIT and TARGET_ADDR_BIT are different, you'll probably    also need to set POINTER_TO_ADDRESS and ADDRESS_TO_POINTER as well.       ptr_bit is the size of a pointer on the target */
end_comment

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

begin_comment
comment|/* addr_bit is the size of a target address as represented in gdb */
end_comment

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

begin_comment
comment|/* Number of bits in a BFD_VMA for the target object file format. */
end_comment

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

begin_comment
comment|/* One if `char' acts like `signed char', zero if `unsigned char'. */
end_comment

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TARGET_READ_PC
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch TARGET_READ_PC */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_READ_PC_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_READ_PC_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_read_pc_p
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
name|TARGET_READ_PC_P
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
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_READ_PC_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_READ_PC_P
parameter_list|()
value|(gdbarch_read_pc_p (current_gdbarch))
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

begin_comment
comment|/* UNWIND_SP is a direct replacement for TARGET_READ_SP. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TARGET_READ_SP
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch TARGET_READ_SP */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TARGET_READ_SP_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_READ_SP_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_read_sp_p
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
name|TARGET_READ_SP_P
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
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|TARGET_READ_SP_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_READ_SP_P
parameter_list|()
value|(gdbarch_read_sp_p (current_gdbarch))
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

begin_comment
comment|/* Function for getting target's idea of a frame pointer.  FIXME: GDB's    whole scheme for dealing with "frames" and "frame pointers" needs a    serious shakedown. */
end_comment

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

begin_function_decl
specifier|extern
name|int
name|gdbarch_pseudo_register_read_p
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
name|gdbarch_pseudo_register_read_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|cookednum
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_pseudo_register_read
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|cookednum
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
name|set_gdbarch_pseudo_register_read
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_pseudo_register_read_ftype
modifier|*
name|pseudo_register_read
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdbarch_pseudo_register_write_p
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
name|gdbarch_pseudo_register_write_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|cookednum
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_pseudo_register_write
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|int
name|cookednum
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_pseudo_register_write
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_pseudo_register_write_ftype
modifier|*
name|pseudo_register_write
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

begin_comment
comment|/* This macro gives the number of pseudo-registers that live in the    register namespace but do not get fetched or stored on the target.    These pseudo-registers may be aliases for other registers,    combinations of other registers, or they may be computed by GDB. */
end_comment

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

begin_comment
comment|/* GDB's standard (or well known) register numbers.  These can map onto    a real register or a pseudo (computed) register or not be defined at    all (-1).    SP_REGNUM will hopefully be replaced by UNWIND_SP. */
end_comment

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

begin_function_decl
specifier|extern
name|int
name|gdbarch_ps_regnum
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
name|set_gdbarch_ps_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|ps_regnum
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
name|PS_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PS_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PS_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|PS_REGNUM
value|(gdbarch_ps_regnum (current_gdbarch))
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

begin_comment
comment|/* Convert stab register number (from `r' declaration) to a gdb REGNUM. */
end_comment

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

begin_comment
comment|/* Provide a default mapping from a ecoff register number to a gdb REGNUM. */
end_comment

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

begin_comment
comment|/* Provide a default mapping from a DWARF register number to a gdb REGNUM. */
end_comment

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

begin_comment
comment|/* Convert from an sdb register number to an internal gdb register number. */
end_comment

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

begin_typedef
typedef|typedef
specifier|const
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
specifier|const
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

begin_comment
comment|/* REGISTER_TYPE is a direct replacement for DEPRECATED_REGISTER_VIRTUAL_TYPE. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_type_p
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
name|struct
name|type
modifier|*
function_decl|(
name|gdbarch_register_type_ftype
function_decl|)
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
end_typedef

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|gdbarch_register_type
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
name|set_gdbarch_register_type
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_type_ftype
modifier|*
name|register_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* REGISTER_TYPE is a direct replacement for DEPRECATED_REGISTER_VIRTUAL_TYPE. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_REGISTER_VIRTUAL_TYPE
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_REGISTER_VIRTUAL_TYPE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_VIRTUAL_TYPE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_VIRTUAL_TYPE_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_register_virtual_type_p
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
name|DEPRECATED_REGISTER_VIRTUAL_TYPE_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_VIRTUAL_TYPE"
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
name|DEPRECATED_REGISTER_VIRTUAL_TYPE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_VIRTUAL_TYPE_P
parameter_list|()
value|(gdbarch_deprecated_register_virtual_type_p (current_gdbarch))
end_define

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
name|gdbarch_deprecated_register_virtual_type_ftype
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
name|gdbarch_deprecated_register_virtual_type
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
name|set_gdbarch_deprecated_register_virtual_type
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_register_virtual_type_ftype
modifier|*
name|deprecated_register_virtual_type
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
name|DEPRECATED_REGISTER_VIRTUAL_TYPE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_VIRTUAL_TYPE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_VIRTUAL_TYPE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_VIRTUAL_TYPE
parameter_list|(
name|reg_nr
parameter_list|)
value|(gdbarch_deprecated_register_virtual_type (current_gdbarch, reg_nr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEPRECATED_REGISTER_BYTES can be deleted.  The value is computed    from REGISTER_TYPE. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_register_bytes
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
name|set_gdbarch_deprecated_register_bytes
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|deprecated_register_bytes
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
name|DEPRECATED_REGISTER_BYTES
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_BYTES"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_BYTES
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_BYTES
value|(gdbarch_deprecated_register_bytes (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If the value returned by DEPRECATED_REGISTER_BYTE agrees with the    register offsets computed using just REGISTER_TYPE, this can be    deleted.  See: maint print registers.  NOTE: cagney/2002-05-02: This    function with predicate has a valid (callable) initial value.  As a    consequence, even when the predicate is false, the corresponding    function works.  This simplifies the migration process - old code,    calling DEPRECATED_REGISTER_BYTE, doesn't need to be modified. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_REGISTER_BYTE
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_REGISTER_BYTE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_BYTE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_BYTE_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_register_byte_p
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
name|DEPRECATED_REGISTER_BYTE_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_BYTE"
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
name|DEPRECATED_REGISTER_BYTE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_BYTE_P
parameter_list|()
value|(gdbarch_deprecated_register_byte_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_deprecated_register_byte_ftype
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
name|gdbarch_deprecated_register_byte
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
name|set_gdbarch_deprecated_register_byte
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_register_byte_ftype
modifier|*
name|deprecated_register_byte
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
name|DEPRECATED_REGISTER_BYTE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_BYTE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_BYTE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_BYTE
parameter_list|(
name|reg_nr
parameter_list|)
value|(gdbarch_deprecated_register_byte (current_gdbarch, reg_nr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If all registers have identical raw and virtual sizes and those    sizes agree with the value computed from REGISTER_TYPE,    DEPRECATED_REGISTER_RAW_SIZE can be deleted.  See: maint print    registers. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_REGISTER_RAW_SIZE
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_REGISTER_RAW_SIZE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_RAW_SIZE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_RAW_SIZE_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_register_raw_size_p
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
name|DEPRECATED_REGISTER_RAW_SIZE_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_RAW_SIZE"
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
name|DEPRECATED_REGISTER_RAW_SIZE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_RAW_SIZE_P
parameter_list|()
value|(gdbarch_deprecated_register_raw_size_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_deprecated_register_raw_size_ftype
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
name|gdbarch_deprecated_register_raw_size
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
name|set_gdbarch_deprecated_register_raw_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_register_raw_size_ftype
modifier|*
name|deprecated_register_raw_size
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
name|DEPRECATED_REGISTER_RAW_SIZE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_RAW_SIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_RAW_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_RAW_SIZE
parameter_list|(
name|reg_nr
parameter_list|)
value|(gdbarch_deprecated_register_raw_size (current_gdbarch, reg_nr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If all registers have identical raw and virtual sizes and those    sizes agree with the value computed from REGISTER_TYPE,    DEPRECATED_REGISTER_VIRTUAL_SIZE can be deleted.  See: maint print    registers. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_REGISTER_VIRTUAL_SIZE
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_REGISTER_VIRTUAL_SIZE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_VIRTUAL_SIZE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_VIRTUAL_SIZE_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_register_virtual_size_p
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
name|DEPRECATED_REGISTER_VIRTUAL_SIZE_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_VIRTUAL_SIZE"
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
name|DEPRECATED_REGISTER_VIRTUAL_SIZE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_VIRTUAL_SIZE_P
parameter_list|()
value|(gdbarch_deprecated_register_virtual_size_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_deprecated_register_virtual_size_ftype
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
name|gdbarch_deprecated_register_virtual_size
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
name|set_gdbarch_deprecated_register_virtual_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_register_virtual_size_ftype
modifier|*
name|deprecated_register_virtual_size
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
name|DEPRECATED_REGISTER_VIRTUAL_SIZE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_VIRTUAL_SIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_VIRTUAL_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_VIRTUAL_SIZE
parameter_list|(
name|reg_nr
parameter_list|)
value|(gdbarch_deprecated_register_virtual_size (current_gdbarch, reg_nr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEPRECATED_MAX_REGISTER_RAW_SIZE can be deleted.  It has been    replaced by the constant MAX_REGISTER_SIZE. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_MAX_REGISTER_RAW_SIZE
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_MAX_REGISTER_RAW_SIZE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_MAX_REGISTER_RAW_SIZE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_MAX_REGISTER_RAW_SIZE_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_max_register_raw_size_p
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
name|DEPRECATED_MAX_REGISTER_RAW_SIZE_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_MAX_REGISTER_RAW_SIZE"
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
name|DEPRECATED_MAX_REGISTER_RAW_SIZE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_MAX_REGISTER_RAW_SIZE_P
parameter_list|()
value|(gdbarch_deprecated_max_register_raw_size_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_max_register_raw_size
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
name|set_gdbarch_deprecated_max_register_raw_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|deprecated_max_register_raw_size
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
name|DEPRECATED_MAX_REGISTER_RAW_SIZE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_MAX_REGISTER_RAW_SIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_MAX_REGISTER_RAW_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_MAX_REGISTER_RAW_SIZE
value|(gdbarch_deprecated_max_register_raw_size (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE can be deleted.  It has been    replaced by the constant MAX_REGISTER_SIZE. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_max_register_virtual_size_p
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
name|DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE"
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
name|DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE_P
parameter_list|()
value|(gdbarch_deprecated_max_register_virtual_size_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_max_register_virtual_size
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
name|set_gdbarch_deprecated_max_register_virtual_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|deprecated_max_register_virtual_size
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
name|DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_MAX_REGISTER_VIRTUAL_SIZE
value|(gdbarch_deprecated_max_register_virtual_size (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* See gdbint.texinfo, and PUSH_DUMMY_CALL. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_unwind_dummy_id_p
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
name|struct
name|frame_id
function_decl|(
name|gdbarch_unwind_dummy_id_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|struct
name|frame_id
name|gdbarch_unwind_dummy_id
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_unwind_dummy_id
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_unwind_dummy_id_ftype
modifier|*
name|unwind_dummy_id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Implement UNWIND_DUMMY_ID and PUSH_DUMMY_CALL, then delete    SAVE_DUMMY_FRAME_TOS. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_SAVE_DUMMY_FRAME_TOS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_SAVE_DUMMY_FRAME_TOS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_SAVE_DUMMY_FRAME_TOS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_SAVE_DUMMY_FRAME_TOS_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_save_dummy_frame_tos_p
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
name|DEPRECATED_SAVE_DUMMY_FRAME_TOS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_SAVE_DUMMY_FRAME_TOS"
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
name|DEPRECATED_SAVE_DUMMY_FRAME_TOS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_SAVE_DUMMY_FRAME_TOS_P
parameter_list|()
value|(gdbarch_deprecated_save_dummy_frame_tos_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_save_dummy_frame_tos_ftype
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
name|gdbarch_deprecated_save_dummy_frame_tos
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
name|set_gdbarch_deprecated_save_dummy_frame_tos
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_save_dummy_frame_tos_ftype
modifier|*
name|deprecated_save_dummy_frame_tos
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
name|DEPRECATED_SAVE_DUMMY_FRAME_TOS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_SAVE_DUMMY_FRAME_TOS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_SAVE_DUMMY_FRAME_TOS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_SAVE_DUMMY_FRAME_TOS
parameter_list|(
name|sp
parameter_list|)
value|(gdbarch_deprecated_save_dummy_frame_tos (current_gdbarch, sp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Implement UNWIND_DUMMY_ID and PUSH_DUMMY_CALL, then delete    DEPRECATED_FP_REGNUM. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_fp_regnum
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
name|set_gdbarch_deprecated_fp_regnum
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|deprecated_fp_regnum
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
name|DEPRECATED_FP_REGNUM
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FP_REGNUM"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FP_REGNUM
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FP_REGNUM
value|(gdbarch_deprecated_fp_regnum (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Implement UNWIND_DUMMY_ID and PUSH_DUMMY_CALL, then delete    DEPRECATED_TARGET_READ_FP. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_TARGET_READ_FP
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_TARGET_READ_FP */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_TARGET_READ_FP_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_TARGET_READ_FP_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_target_read_fp_p
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
name|DEPRECATED_TARGET_READ_FP_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_TARGET_READ_FP"
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
name|DEPRECATED_TARGET_READ_FP_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_TARGET_READ_FP_P
parameter_list|()
value|(gdbarch_deprecated_target_read_fp_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_target_read_fp_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_deprecated_target_read_fp
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
name|set_gdbarch_deprecated_target_read_fp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_target_read_fp_ftype
modifier|*
name|deprecated_target_read_fp
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
name|DEPRECATED_TARGET_READ_FP
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_TARGET_READ_FP"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_TARGET_READ_FP
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_TARGET_READ_FP
parameter_list|()
value|(gdbarch_deprecated_target_read_fp (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* See gdbint.texinfo.  See infcall.c.  New, all singing all dancing,    replacement for DEPRECATED_PUSH_ARGUMENTS. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_push_dummy_call_p
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
name|CORE_ADDR
function_decl|(
name|gdbarch_push_dummy_call_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|func_addr
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|CORE_ADDR
name|bp_addr
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
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_push_dummy_call
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|func_addr
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|CORE_ADDR
name|bp_addr
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
name|set_gdbarch_push_dummy_call
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_push_dummy_call_ftype
modifier|*
name|push_dummy_call
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* PUSH_DUMMY_CALL is a direct replacement for DEPRECATED_PUSH_ARGUMENTS. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_PUSH_ARGUMENTS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_PUSH_ARGUMENTS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_PUSH_ARGUMENTS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PUSH_ARGUMENTS_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_push_arguments_p
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
name|DEPRECATED_PUSH_ARGUMENTS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_PUSH_ARGUMENTS"
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
name|DEPRECATED_PUSH_ARGUMENTS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PUSH_ARGUMENTS_P
parameter_list|()
value|(gdbarch_deprecated_push_arguments_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_push_arguments_ftype
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
name|gdbarch_deprecated_push_arguments
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
name|set_gdbarch_deprecated_push_arguments
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_push_arguments_ftype
modifier|*
name|deprecated_push_arguments
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
name|DEPRECATED_PUSH_ARGUMENTS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_PUSH_ARGUMENTS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_PUSH_ARGUMENTS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PUSH_ARGUMENTS
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
value|(gdbarch_deprecated_push_arguments (current_gdbarch, nargs, args, sp, struct_return, struct_addr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEPRECATED_USE_GENERIC_DUMMY_FRAMES can be deleted.  Always true. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_use_generic_dummy_frames
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
name|set_gdbarch_deprecated_use_generic_dummy_frames
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|deprecated_use_generic_dummy_frames
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
name|DEPRECATED_USE_GENERIC_DUMMY_FRAMES
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_USE_GENERIC_DUMMY_FRAMES"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_USE_GENERIC_DUMMY_FRAMES
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_USE_GENERIC_DUMMY_FRAMES
value|(gdbarch_deprecated_use_generic_dummy_frames (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Implement PUSH_RETURN_ADDRESS, and then merge in    DEPRECATED_PUSH_RETURN_ADDRESS. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_PUSH_RETURN_ADDRESS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_PUSH_RETURN_ADDRESS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_PUSH_RETURN_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PUSH_RETURN_ADDRESS_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_push_return_address_p
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
name|DEPRECATED_PUSH_RETURN_ADDRESS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_PUSH_RETURN_ADDRESS"
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
name|DEPRECATED_PUSH_RETURN_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PUSH_RETURN_ADDRESS_P
parameter_list|()
value|(gdbarch_deprecated_push_return_address_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_push_return_address_ftype
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
name|gdbarch_deprecated_push_return_address
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
name|set_gdbarch_deprecated_push_return_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_push_return_address_ftype
modifier|*
name|deprecated_push_return_address
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
name|DEPRECATED_PUSH_RETURN_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_PUSH_RETURN_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_PUSH_RETURN_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PUSH_RETURN_ADDRESS
parameter_list|(
name|pc
parameter_list|,
name|sp
parameter_list|)
value|(gdbarch_deprecated_push_return_address (current_gdbarch, pc, sp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Implement PUSH_DUMMY_CALL, then merge in DEPRECATED_DUMMY_WRITE_SP. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_DUMMY_WRITE_SP
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_DUMMY_WRITE_SP */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_DUMMY_WRITE_SP_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_DUMMY_WRITE_SP_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_dummy_write_sp_p
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
name|DEPRECATED_DUMMY_WRITE_SP_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_DUMMY_WRITE_SP"
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
name|DEPRECATED_DUMMY_WRITE_SP_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_DUMMY_WRITE_SP_P
parameter_list|()
value|(gdbarch_deprecated_dummy_write_sp_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_dummy_write_sp_ftype
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
name|gdbarch_deprecated_dummy_write_sp
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
name|set_gdbarch_deprecated_dummy_write_sp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_dummy_write_sp_ftype
modifier|*
name|deprecated_dummy_write_sp
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
name|DEPRECATED_DUMMY_WRITE_SP
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_DUMMY_WRITE_SP"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_DUMMY_WRITE_SP
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_DUMMY_WRITE_SP
parameter_list|(
name|val
parameter_list|)
value|(gdbarch_deprecated_dummy_write_sp (current_gdbarch, val))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEPRECATED_REGISTER_SIZE can be deleted. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_register_size
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
name|set_gdbarch_deprecated_register_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|deprecated_register_size
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
name|DEPRECATED_REGISTER_SIZE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_SIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_SIZE
value|(gdbarch_deprecated_register_size (current_gdbarch))
end_define

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
operator|>
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

begin_comment
comment|/* DEPRECATED_CALL_DUMMY_START_OFFSET can be deleted. */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_deprecated_call_dummy_start_offset
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
name|set_gdbarch_deprecated_call_dummy_start_offset
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|deprecated_call_dummy_start_offset
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
name|DEPRECATED_CALL_DUMMY_START_OFFSET
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_CALL_DUMMY_START_OFFSET"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_CALL_DUMMY_START_OFFSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_CALL_DUMMY_START_OFFSET
value|(gdbarch_deprecated_call_dummy_start_offset (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEPRECATED_CALL_DUMMY_BREAKPOINT_OFFSET can be deleted. */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_deprecated_call_dummy_breakpoint_offset
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
name|set_gdbarch_deprecated_call_dummy_breakpoint_offset
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|deprecated_call_dummy_breakpoint_offset
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
name|DEPRECATED_CALL_DUMMY_BREAKPOINT_OFFSET
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_CALL_DUMMY_BREAKPOINT_OFFSET"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_CALL_DUMMY_BREAKPOINT_OFFSET
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_CALL_DUMMY_BREAKPOINT_OFFSET
value|(gdbarch_deprecated_call_dummy_breakpoint_offset (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEPRECATED_CALL_DUMMY_LENGTH can be deleted. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_call_dummy_length
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
name|set_gdbarch_deprecated_call_dummy_length
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|deprecated_call_dummy_length
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
name|DEPRECATED_CALL_DUMMY_LENGTH
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_CALL_DUMMY_LENGTH"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_CALL_DUMMY_LENGTH
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_CALL_DUMMY_LENGTH
value|(gdbarch_deprecated_call_dummy_length (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEPRECATED_CALL_DUMMY_WORDS can be deleted. */
end_comment

begin_function_decl
specifier|extern
name|LONGEST
modifier|*
name|gdbarch_deprecated_call_dummy_words
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
name|set_gdbarch_deprecated_call_dummy_words
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|LONGEST
modifier|*
name|deprecated_call_dummy_words
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
name|DEPRECATED_CALL_DUMMY_WORDS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_CALL_DUMMY_WORDS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_CALL_DUMMY_WORDS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_CALL_DUMMY_WORDS
value|(gdbarch_deprecated_call_dummy_words (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Implement PUSH_DUMMY_CALL, then delete DEPRECATED_SIZEOF_CALL_DUMMY_WORDS. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_sizeof_call_dummy_words
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
name|set_gdbarch_deprecated_sizeof_call_dummy_words
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|deprecated_sizeof_call_dummy_words
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
name|DEPRECATED_SIZEOF_CALL_DUMMY_WORDS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_SIZEOF_CALL_DUMMY_WORDS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_SIZEOF_CALL_DUMMY_WORDS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_SIZEOF_CALL_DUMMY_WORDS
value|(gdbarch_deprecated_sizeof_call_dummy_words (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEPRECATED_FIX_CALL_DUMMY can be deleted.  For the SPARC, implement    PUSH_DUMMY_CODE and set CALL_DUMMY_LOCATION to ON_STACK. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_FIX_CALL_DUMMY
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_FIX_CALL_DUMMY */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FIX_CALL_DUMMY_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FIX_CALL_DUMMY_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_fix_call_dummy_p
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
name|DEPRECATED_FIX_CALL_DUMMY_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FIX_CALL_DUMMY"
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
name|DEPRECATED_FIX_CALL_DUMMY_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FIX_CALL_DUMMY_P
parameter_list|()
value|(gdbarch_deprecated_fix_call_dummy_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_fix_call_dummy_ftype
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
name|gdbarch_deprecated_fix_call_dummy
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
name|set_gdbarch_deprecated_fix_call_dummy
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_fix_call_dummy_ftype
modifier|*
name|deprecated_fix_call_dummy
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
name|DEPRECATED_FIX_CALL_DUMMY
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FIX_CALL_DUMMY"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FIX_CALL_DUMMY
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FIX_CALL_DUMMY
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
value|(gdbarch_deprecated_fix_call_dummy (current_gdbarch, dummy, pc, fun, nargs, args, type, gcc_p))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is a replacement for DEPRECATED_FIX_CALL_DUMMY et.al. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_push_dummy_code_p
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
name|CORE_ADDR
function_decl|(
name|gdbarch_push_dummy_code_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|CORE_ADDR
name|funaddr
parameter_list|,
name|int
name|using_gcc
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|,
name|int
name|nargs
parameter_list|,
name|struct
name|type
modifier|*
name|value_type
parameter_list|,
name|CORE_ADDR
modifier|*
name|real_pc
parameter_list|,
name|CORE_ADDR
modifier|*
name|bp_addr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_push_dummy_code
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|CORE_ADDR
name|funaddr
parameter_list|,
name|int
name|using_gcc
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|,
name|int
name|nargs
parameter_list|,
name|struct
name|type
modifier|*
name|value_type
parameter_list|,
name|CORE_ADDR
modifier|*
name|real_pc
parameter_list|,
name|CORE_ADDR
modifier|*
name|bp_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_push_dummy_code
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_push_dummy_code_ftype
modifier|*
name|push_dummy_code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Implement PUSH_DUMMY_CALL, then delete DEPRECATED_PUSH_DUMMY_FRAME. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_PUSH_DUMMY_FRAME
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_PUSH_DUMMY_FRAME */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_PUSH_DUMMY_FRAME_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PUSH_DUMMY_FRAME_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_push_dummy_frame_p
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
name|DEPRECATED_PUSH_DUMMY_FRAME_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_PUSH_DUMMY_FRAME"
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
name|DEPRECATED_PUSH_DUMMY_FRAME_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PUSH_DUMMY_FRAME_P
parameter_list|()
value|(gdbarch_deprecated_push_dummy_frame_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_push_dummy_frame_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_deprecated_push_dummy_frame
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
name|set_gdbarch_deprecated_push_dummy_frame
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_push_dummy_frame_ftype
modifier|*
name|deprecated_push_dummy_frame
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
name|DEPRECATED_PUSH_DUMMY_FRAME
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_PUSH_DUMMY_FRAME"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_PUSH_DUMMY_FRAME
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PUSH_DUMMY_FRAME
value|(gdbarch_deprecated_push_dummy_frame (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_DO_REGISTERS_INFO
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_DO_REGISTERS_INFO */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_DO_REGISTERS_INFO_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_DO_REGISTERS_INFO_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_do_registers_info_p
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
name|DEPRECATED_DO_REGISTERS_INFO_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_DO_REGISTERS_INFO"
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
name|DEPRECATED_DO_REGISTERS_INFO_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_DO_REGISTERS_INFO_P
parameter_list|()
value|(gdbarch_deprecated_do_registers_info_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_do_registers_info_ftype
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
name|gdbarch_deprecated_do_registers_info
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
name|set_gdbarch_deprecated_do_registers_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_do_registers_info_ftype
modifier|*
name|deprecated_do_registers_info
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
name|DEPRECATED_DO_REGISTERS_INFO
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_DO_REGISTERS_INFO"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_DO_REGISTERS_INFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_DO_REGISTERS_INFO
parameter_list|(
name|reg_nr
parameter_list|,
name|fpregs
parameter_list|)
value|(gdbarch_deprecated_do_registers_info (current_gdbarch, reg_nr, fpregs))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_print_registers_info_ftype
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
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|int
name|all
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_print_registers_info
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
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|int
name|all
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_print_registers_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_print_registers_info_ftype
modifier|*
name|print_registers_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdbarch_print_float_info_p
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
name|gdbarch_print_float_info_ftype
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
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
specifier|const
name|char
modifier|*
name|args
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
parameter_list|,
name|struct
name|ui_file
modifier|*
name|file
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
specifier|const
name|char
modifier|*
name|args
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_print_vector_info_p
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
name|gdbarch_print_vector_info_ftype
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
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
specifier|const
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_print_vector_info
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
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
specifier|const
name|char
modifier|*
name|args
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_print_vector_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_print_vector_info_ftype
modifier|*
name|print_vector_info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* MAP a GDB RAW register number onto a simulator register number.  See    also include/...-sim.h. */
end_comment

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

begin_comment
comment|/* NOTE: cagney/2002-11-24: This function with predicate has a valid    (callable) initial value.  As a consequence, even when the predicate    is false, the corresponding function works.  This simplifies the    migration process - old code, calling DEPRECATED_PC_IN_CALL_DUMMY(),    doesn't need to be modified. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_PC_IN_CALL_DUMMY
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_PC_IN_CALL_DUMMY */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_PC_IN_CALL_DUMMY_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PC_IN_CALL_DUMMY_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_pc_in_call_dummy_p
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
name|DEPRECATED_PC_IN_CALL_DUMMY_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_PC_IN_CALL_DUMMY"
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
name|DEPRECATED_PC_IN_CALL_DUMMY_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PC_IN_CALL_DUMMY_P
parameter_list|()
value|(gdbarch_deprecated_pc_in_call_dummy_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_deprecated_pc_in_call_dummy_ftype
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
name|gdbarch_deprecated_pc_in_call_dummy
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
name|set_gdbarch_deprecated_pc_in_call_dummy
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_pc_in_call_dummy_ftype
modifier|*
name|deprecated_pc_in_call_dummy
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
name|DEPRECATED_PC_IN_CALL_DUMMY
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_PC_IN_CALL_DUMMY"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_PC_IN_CALL_DUMMY
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_PC_IN_CALL_DUMMY
parameter_list|(
name|pc
parameter_list|,
name|sp
parameter_list|,
name|frame_address
parameter_list|)
value|(gdbarch_deprecated_pc_in_call_dummy (current_gdbarch, pc, sp, frame_address))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_INIT_FRAME_PC_FIRST
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_INIT_FRAME_PC_FIRST */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_INIT_FRAME_PC_FIRST_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_INIT_FRAME_PC_FIRST_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_init_frame_pc_first_p
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
name|DEPRECATED_INIT_FRAME_PC_FIRST_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_INIT_FRAME_PC_FIRST"
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
name|DEPRECATED_INIT_FRAME_PC_FIRST_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_INIT_FRAME_PC_FIRST_P
parameter_list|()
value|(gdbarch_deprecated_init_frame_pc_first_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_init_frame_pc_first_ftype
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
name|CORE_ADDR
name|gdbarch_deprecated_init_frame_pc_first
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
name|set_gdbarch_deprecated_init_frame_pc_first
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_init_frame_pc_first_ftype
modifier|*
name|deprecated_init_frame_pc_first
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
name|DEPRECATED_INIT_FRAME_PC_FIRST
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_INIT_FRAME_PC_FIRST"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_INIT_FRAME_PC_FIRST
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_INIT_FRAME_PC_FIRST
parameter_list|(
name|fromleaf
parameter_list|,
name|prev
parameter_list|)
value|(gdbarch_deprecated_init_frame_pc_first (current_gdbarch, fromleaf, prev))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_INIT_FRAME_PC
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_INIT_FRAME_PC */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_INIT_FRAME_PC_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_INIT_FRAME_PC_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_init_frame_pc_p
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
name|DEPRECATED_INIT_FRAME_PC_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_INIT_FRAME_PC"
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
name|DEPRECATED_INIT_FRAME_PC_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_INIT_FRAME_PC_P
parameter_list|()
value|(gdbarch_deprecated_init_frame_pc_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_init_frame_pc_ftype
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
name|CORE_ADDR
name|gdbarch_deprecated_init_frame_pc
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
name|set_gdbarch_deprecated_init_frame_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_init_frame_pc_ftype
modifier|*
name|deprecated_init_frame_pc
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
name|DEPRECATED_INIT_FRAME_PC
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_INIT_FRAME_PC"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_INIT_FRAME_PC
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_INIT_FRAME_PC
parameter_list|(
name|fromleaf
parameter_list|,
name|prev
parameter_list|)
value|(gdbarch_deprecated_init_frame_pc (current_gdbarch, fromleaf, prev))
end_define

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_GET_SAVED_REGISTER
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_GET_SAVED_REGISTER */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_GET_SAVED_REGISTER_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_GET_SAVED_REGISTER_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_get_saved_register_p
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
name|DEPRECATED_GET_SAVED_REGISTER_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_GET_SAVED_REGISTER"
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
name|DEPRECATED_GET_SAVED_REGISTER_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_GET_SAVED_REGISTER_P
parameter_list|()
value|(gdbarch_deprecated_get_saved_register_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_get_saved_register_ftype
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
name|gdbarch_deprecated_get_saved_register
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
name|set_gdbarch_deprecated_get_saved_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_get_saved_register_ftype
modifier|*
name|deprecated_get_saved_register
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
name|DEPRECATED_GET_SAVED_REGISTER
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_GET_SAVED_REGISTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_GET_SAVED_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_GET_SAVED_REGISTER
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
value|(gdbarch_deprecated_get_saved_register (current_gdbarch, raw_buffer, optimized, addrp, frame, regnum, lval))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For register<-> value conversions, replaced by CONVERT_REGISTER_P et.al.    For raw<-> cooked register conversions, replaced by pseudo registers. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_REGISTER_CONVERTIBLE
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_REGISTER_CONVERTIBLE */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_CONVERTIBLE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_CONVERTIBLE_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_register_convertible_p
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
name|DEPRECATED_REGISTER_CONVERTIBLE_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_CONVERTIBLE"
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
name|DEPRECATED_REGISTER_CONVERTIBLE_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_CONVERTIBLE_P
parameter_list|()
value|(gdbarch_deprecated_register_convertible_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_deprecated_register_convertible_ftype
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
name|gdbarch_deprecated_register_convertible
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
name|set_gdbarch_deprecated_register_convertible
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_register_convertible_ftype
modifier|*
name|deprecated_register_convertible
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
name|DEPRECATED_REGISTER_CONVERTIBLE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_CONVERTIBLE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_CONVERTIBLE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_CONVERTIBLE
parameter_list|(
name|nr
parameter_list|)
value|(gdbarch_deprecated_register_convertible (current_gdbarch, nr))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For register<-> value conversions, replaced by CONVERT_REGISTER_P et.al.    For raw<-> cooked register conversions, replaced by pseudo registers. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_register_convert_to_virtual_ftype
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
name|gdbarch_deprecated_register_convert_to_virtual
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
name|set_gdbarch_deprecated_register_convert_to_virtual
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_register_convert_to_virtual_ftype
modifier|*
name|deprecated_register_convert_to_virtual
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
name|DEPRECATED_REGISTER_CONVERT_TO_VIRTUAL
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_CONVERT_TO_VIRTUAL"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_CONVERT_TO_VIRTUAL
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_CONVERT_TO_VIRTUAL
parameter_list|(
name|regnum
parameter_list|,
name|type
parameter_list|,
name|from
parameter_list|,
name|to
parameter_list|)
value|(gdbarch_deprecated_register_convert_to_virtual (current_gdbarch, regnum, type, from, to))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For register<-> value conversions, replaced by CONVERT_REGISTER_P et.al.    For raw<-> cooked register conversions, replaced by pseudo registers. */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_register_convert_to_raw_ftype
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
specifier|const
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
name|gdbarch_deprecated_register_convert_to_raw
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
specifier|const
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
name|set_gdbarch_deprecated_register_convert_to_raw
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_register_convert_to_raw_ftype
modifier|*
name|deprecated_register_convert_to_raw
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
name|DEPRECATED_REGISTER_CONVERT_TO_RAW
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REGISTER_CONVERT_TO_RAW"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REGISTER_CONVERT_TO_RAW
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REGISTER_CONVERT_TO_RAW
parameter_list|(
name|type
parameter_list|,
name|regnum
parameter_list|,
name|from
parameter_list|,
name|to
parameter_list|)
value|(gdbarch_deprecated_register_convert_to_raw (current_gdbarch, type, regnum, from, to))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_convert_register_p_ftype
function_decl|)
parameter_list|(
name|int
name|regnum
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
name|gdbarch_convert_register_p
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_convert_register_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_convert_register_p_ftype
modifier|*
name|convert_register_p
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
name|CONVERT_REGISTER_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CONVERT_REGISTER_P"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CONVERT_REGISTER_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONVERT_REGISTER_P
parameter_list|(
name|regnum
parameter_list|,
name|type
parameter_list|)
value|(gdbarch_convert_register_p (current_gdbarch, regnum, type))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_register_to_value_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
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
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_register_to_value
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
parameter_list|,
name|int
name|regnum
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
name|set_gdbarch_register_to_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_to_value_ftype
modifier|*
name|register_to_value
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
name|REGISTER_TO_VALUE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of REGISTER_TO_VALUE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|REGISTER_TO_VALUE
argument_list|)
end_if

begin_define
define|#
directive|define
name|REGISTER_TO_VALUE
parameter_list|(
name|frame
parameter_list|,
name|regnum
parameter_list|,
name|type
parameter_list|,
name|buf
parameter_list|)
value|(gdbarch_register_to_value (current_gdbarch, frame, regnum, type, buf))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_value_to_register_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_value_to_register
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
parameter_list|,
name|int
name|regnum
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
specifier|const
name|void
modifier|*
name|buf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_value_to_register
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_value_to_register_ftype
modifier|*
name|value_to_register
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
name|VALUE_TO_REGISTER
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of VALUE_TO_REGISTER"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VALUE_TO_REGISTER
argument_list|)
end_if

begin_define
define|#
directive|define
name|VALUE_TO_REGISTER
parameter_list|(
name|frame
parameter_list|,
name|regnum
parameter_list|,
name|type
parameter_list|,
name|buf
parameter_list|)
value|(gdbarch_value_to_register (current_gdbarch, frame, regnum, type, buf))
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
specifier|const
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
specifier|const
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_POP_FRAME
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_POP_FRAME */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_POP_FRAME_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_POP_FRAME_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_pop_frame_p
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
name|DEPRECATED_POP_FRAME_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_POP_FRAME"
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
name|DEPRECATED_POP_FRAME_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_POP_FRAME_P
parameter_list|()
value|(gdbarch_deprecated_pop_frame_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_pop_frame_ftype
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|gdbarch_deprecated_pop_frame
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
name|set_gdbarch_deprecated_pop_frame
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_pop_frame_ftype
modifier|*
name|deprecated_pop_frame
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
name|DEPRECATED_POP_FRAME
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_POP_FRAME"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_POP_FRAME
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_POP_FRAME
value|(gdbarch_deprecated_pop_frame (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOTE: cagney/2003-03-24: Replaced by PUSH_ARGUMENTS. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_STORE_STRUCT_RETURN
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_STORE_STRUCT_RETURN */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_STORE_STRUCT_RETURN_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_STORE_STRUCT_RETURN_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_store_struct_return_p
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
name|DEPRECATED_STORE_STRUCT_RETURN_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_STORE_STRUCT_RETURN"
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
name|DEPRECATED_STORE_STRUCT_RETURN_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_STORE_STRUCT_RETURN_P
parameter_list|()
value|(gdbarch_deprecated_store_struct_return_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_store_struct_return_ftype
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
name|gdbarch_deprecated_store_struct_return
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
name|set_gdbarch_deprecated_store_struct_return
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_store_struct_return_ftype
modifier|*
name|deprecated_store_struct_return
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
name|DEPRECATED_STORE_STRUCT_RETURN
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_STORE_STRUCT_RETURN"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_STORE_STRUCT_RETURN
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_STORE_STRUCT_RETURN
parameter_list|(
name|addr
parameter_list|,
name|sp
parameter_list|)
value|(gdbarch_deprecated_store_struct_return (current_gdbarch, addr, sp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* It has been suggested that this, well actually its predecessor,    should take the type/value of the function to be called and not the    return type.  This is left as an exercise for the reader. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_return_value_p
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
name|enum
name|return_value_convention
function_decl|(
name|gdbarch_return_value_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|valtype
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|void
modifier|*
name|readbuf
parameter_list|,
specifier|const
name|void
modifier|*
name|writebuf
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|enum
name|return_value_convention
name|gdbarch_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|type
modifier|*
name|valtype
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|void
modifier|*
name|readbuf
parameter_list|,
specifier|const
name|void
modifier|*
name|writebuf
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_return_value_ftype
modifier|*
name|return_value
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The deprecated methods RETURN_VALUE_ON_STACK, EXTRACT_RETURN_VALUE,    STORE_RETURN_VALUE and USE_STRUCT_CONVENTION have all been folded    into RETURN_VALUE. */
end_comment

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
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|void
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
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
name|void
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
name|regcache
parameter_list|,
name|valbuf
parameter_list|)
value|(gdbarch_extract_return_value (current_gdbarch, type, regcache, valbuf))
end_define

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
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
specifier|const
name|void
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
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|,
specifier|const
name|void
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
name|regcache
parameter_list|,
name|valbuf
parameter_list|)
value|(gdbarch_store_return_value (current_gdbarch, type, regcache, valbuf))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_extract_return_value_ftype
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
name|gdbarch_deprecated_extract_return_value
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
name|set_gdbarch_deprecated_extract_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_extract_return_value_ftype
modifier|*
name|deprecated_extract_return_value
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
name|DEPRECATED_EXTRACT_RETURN_VALUE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_EXTRACT_RETURN_VALUE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_EXTRACT_RETURN_VALUE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_EXTRACT_RETURN_VALUE
parameter_list|(
name|type
parameter_list|,
name|regbuf
parameter_list|,
name|valbuf
parameter_list|)
value|(gdbarch_deprecated_extract_return_value (current_gdbarch, type, regbuf, valbuf))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_store_return_value_ftype
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
name|gdbarch_deprecated_store_return_value
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
name|set_gdbarch_deprecated_store_return_value
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_store_return_value_ftype
modifier|*
name|deprecated_store_return_value
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
name|DEPRECATED_STORE_RETURN_VALUE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_STORE_RETURN_VALUE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_STORE_RETURN_VALUE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_STORE_RETURN_VALUE
parameter_list|(
name|type
parameter_list|,
name|valbuf
parameter_list|)
value|(gdbarch_deprecated_store_return_value (current_gdbarch, type, valbuf))
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

begin_comment
comment|/* As of 2004-01-17 only the 32-bit SPARC ABI has been identified as an    ABI suitable for the implementation of a robust extract    struct-convention return-value address method (the sparc saves the    address in the callers frame).  All the other cases so far examined,    the DEPRECATED_EXTRACT_STRUCT_VALUE implementation has been    erreneous - the code was incorrectly assuming that the return-value    address, stored in a register, was preserved across the entire    function call.    For the moment retain DEPRECATED_EXTRACT_STRUCT_VALUE as a marker of    the ABIs that are still to be analyzed - perhaps this should simply    be deleted.  The commented out extract_returned_value_address method    is provided as a starting point for the 32-bit SPARC.  It, or    something like it, along with changes to both infcmd.c and stack.c    will be needed for that case to work.  NB: It is passed the callers    frame since it is only after the callee has returned that this    function is used.   M:::CORE_ADDR:extract_returned_value_address:struct frame_info *caller_frame:caller_frame */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_extract_struct_value_address_p
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
name|DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS"
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
name|DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS_P
parameter_list|()
value|(gdbarch_deprecated_extract_struct_value_address_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_extract_struct_value_address_ftype
function_decl|)
parameter_list|(
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_deprecated_extract_struct_value_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_deprecated_extract_struct_value_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_extract_struct_value_address_ftype
modifier|*
name|deprecated_extract_struct_value_address
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
name|DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_EXTRACT_STRUCT_VALUE_ADDRESS
parameter_list|(
name|regcache
parameter_list|)
value|(gdbarch_deprecated_extract_struct_value_address (current_gdbarch, regcache))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_FRAME_INIT_SAVED_REGS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_FRAME_INIT_SAVED_REGS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_INIT_SAVED_REGS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_INIT_SAVED_REGS_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_frame_init_saved_regs_p
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
name|DEPRECATED_FRAME_INIT_SAVED_REGS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_INIT_SAVED_REGS"
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
name|DEPRECATED_FRAME_INIT_SAVED_REGS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_INIT_SAVED_REGS_P
parameter_list|()
value|(gdbarch_deprecated_frame_init_saved_regs_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_frame_init_saved_regs_ftype
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
name|gdbarch_deprecated_frame_init_saved_regs
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
name|set_gdbarch_deprecated_frame_init_saved_regs
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_frame_init_saved_regs_ftype
modifier|*
name|deprecated_frame_init_saved_regs
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
name|DEPRECATED_FRAME_INIT_SAVED_REGS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_INIT_SAVED_REGS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_INIT_SAVED_REGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_INIT_SAVED_REGS
parameter_list|(
name|frame
parameter_list|)
value|(gdbarch_deprecated_frame_init_saved_regs (current_gdbarch, frame))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_INIT_EXTRA_FRAME_INFO
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_INIT_EXTRA_FRAME_INFO */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_INIT_EXTRA_FRAME_INFO_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_INIT_EXTRA_FRAME_INFO_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_init_extra_frame_info_p
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
name|DEPRECATED_INIT_EXTRA_FRAME_INFO_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_INIT_EXTRA_FRAME_INFO"
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
name|DEPRECATED_INIT_EXTRA_FRAME_INFO_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_INIT_EXTRA_FRAME_INFO_P
parameter_list|()
value|(gdbarch_deprecated_init_extra_frame_info_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_deprecated_init_extra_frame_info_ftype
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
name|gdbarch_deprecated_init_extra_frame_info
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
name|set_gdbarch_deprecated_init_extra_frame_info
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_init_extra_frame_info_ftype
modifier|*
name|deprecated_init_extra_frame_info
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
name|DEPRECATED_INIT_EXTRA_FRAME_INFO
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_INIT_EXTRA_FRAME_INFO"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_INIT_EXTRA_FRAME_INFO
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_INIT_EXTRA_FRAME_INFO
parameter_list|(
name|fromleaf
parameter_list|,
name|frame
parameter_list|)
value|(gdbarch_deprecated_init_extra_frame_info (current_gdbarch, fromleaf, frame))
end_define

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

begin_typedef
typedef|typedef
specifier|const
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
specifier|const
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_adjust_breakpoint_address_p
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
name|CORE_ADDR
function_decl|(
name|gdbarch_adjust_breakpoint_address_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|bpaddr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_adjust_breakpoint_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|bpaddr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_adjust_breakpoint_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_adjust_breakpoint_address_ftype
modifier|*
name|adjust_breakpoint_address
parameter_list|)
function_decl|;
end_function_decl

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

begin_typedef
typedef|typedef
name|void
function_decl|(
name|gdbarch_remote_translate_xfer_address_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|regcache
modifier|*
name|regcache
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
name|struct
name|regcache
modifier|*
name|regcache
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

begin_comment
comment|/* DEPRECATED_FRAMELESS_FUNCTION_INVOCATION is not needed.  The new    frame code works regardless of the type of frame - frameless,    stackless, or normal. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_FRAMELESS_FUNCTION_INVOCATION
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_FRAMELESS_FUNCTION_INVOCATION */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAMELESS_FUNCTION_INVOCATION_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAMELESS_FUNCTION_INVOCATION_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_frameless_function_invocation_p
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
name|DEPRECATED_FRAMELESS_FUNCTION_INVOCATION_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAMELESS_FUNCTION_INVOCATION"
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
name|DEPRECATED_FRAMELESS_FUNCTION_INVOCATION_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAMELESS_FUNCTION_INVOCATION_P
parameter_list|()
value|(gdbarch_deprecated_frameless_function_invocation_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_deprecated_frameless_function_invocation_ftype
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
name|gdbarch_deprecated_frameless_function_invocation
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
name|set_gdbarch_deprecated_frameless_function_invocation
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_frameless_function_invocation_ftype
modifier|*
name|deprecated_frameless_function_invocation
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
name|DEPRECATED_FRAMELESS_FUNCTION_INVOCATION
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAMELESS_FUNCTION_INVOCATION"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAMELESS_FUNCTION_INVOCATION
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAMELESS_FUNCTION_INVOCATION
parameter_list|(
name|fi
parameter_list|)
value|(gdbarch_deprecated_frameless_function_invocation (current_gdbarch, fi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_FRAME_CHAIN
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_FRAME_CHAIN */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_CHAIN_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_CHAIN_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_frame_chain_p
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
name|DEPRECATED_FRAME_CHAIN_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_CHAIN"
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
name|DEPRECATED_FRAME_CHAIN_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_CHAIN_P
parameter_list|()
value|(gdbarch_deprecated_frame_chain_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_frame_chain_ftype
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
name|gdbarch_deprecated_frame_chain
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
name|set_gdbarch_deprecated_frame_chain
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_frame_chain_ftype
modifier|*
name|deprecated_frame_chain
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
name|DEPRECATED_FRAME_CHAIN
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_CHAIN"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_CHAIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_CHAIN
parameter_list|(
name|frame
parameter_list|)
value|(gdbarch_deprecated_frame_chain (current_gdbarch, frame))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_FRAME_CHAIN_VALID
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_FRAME_CHAIN_VALID */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_CHAIN_VALID_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_CHAIN_VALID_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_frame_chain_valid_p
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
name|DEPRECATED_FRAME_CHAIN_VALID_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_CHAIN_VALID"
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
name|DEPRECATED_FRAME_CHAIN_VALID_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_CHAIN_VALID_P
parameter_list|()
value|(gdbarch_deprecated_frame_chain_valid_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_deprecated_frame_chain_valid_ftype
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
name|gdbarch_deprecated_frame_chain_valid
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
name|set_gdbarch_deprecated_frame_chain_valid
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_frame_chain_valid_ftype
modifier|*
name|deprecated_frame_chain_valid
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
name|DEPRECATED_FRAME_CHAIN_VALID
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_CHAIN_VALID"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_CHAIN_VALID
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
value|(gdbarch_deprecated_frame_chain_valid (current_gdbarch, chain, thisframe))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEPRECATED_FRAME_SAVED_PC has been replaced by UNWIND_PC.  Please    note, per UNWIND_PC's doco, that while the two have similar    interfaces they have very different underlying implementations. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_FRAME_SAVED_PC
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_FRAME_SAVED_PC */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_SAVED_PC_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_SAVED_PC_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_frame_saved_pc_p
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
name|DEPRECATED_FRAME_SAVED_PC_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_SAVED_PC"
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
name|DEPRECATED_FRAME_SAVED_PC_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_SAVED_PC_P
parameter_list|()
value|(gdbarch_deprecated_frame_saved_pc_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_frame_saved_pc_ftype
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
name|gdbarch_deprecated_frame_saved_pc
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
name|set_gdbarch_deprecated_frame_saved_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_frame_saved_pc_ftype
modifier|*
name|deprecated_frame_saved_pc
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
name|DEPRECATED_FRAME_SAVED_PC
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_SAVED_PC"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_SAVED_PC
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_SAVED_PC
parameter_list|(
name|fi
parameter_list|)
value|(gdbarch_deprecated_frame_saved_pc (current_gdbarch, fi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_unwind_pc_p
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
name|CORE_ADDR
function_decl|(
name|gdbarch_unwind_pc_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_unwind_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_unwind_pc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_unwind_pc_ftype
modifier|*
name|unwind_pc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdbarch_unwind_sp_p
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
name|CORE_ADDR
function_decl|(
name|gdbarch_unwind_sp_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_unwind_sp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|struct
name|frame_info
modifier|*
name|next_frame
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_unwind_sp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_unwind_sp_ftype
modifier|*
name|unwind_sp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DEPRECATED_FRAME_ARGS_ADDRESS as been replaced by the per-frame    frame-base.  Enable frame-base before frame-unwind. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_FRAME_ARGS_ADDRESS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_FRAME_ARGS_ADDRESS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_ARGS_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_ARGS_ADDRESS_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_frame_args_address_p
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
name|DEPRECATED_FRAME_ARGS_ADDRESS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_ARGS_ADDRESS"
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
name|DEPRECATED_FRAME_ARGS_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_ARGS_ADDRESS_P
parameter_list|()
value|(gdbarch_deprecated_frame_args_address_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_frame_args_address_ftype
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
name|gdbarch_deprecated_frame_args_address
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
name|set_gdbarch_deprecated_frame_args_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_frame_args_address_ftype
modifier|*
name|deprecated_frame_args_address
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
name|DEPRECATED_FRAME_ARGS_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_ARGS_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_ARGS_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|(gdbarch_deprecated_frame_args_address (current_gdbarch, fi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEPRECATED_FRAME_LOCALS_ADDRESS as been replaced by the per-frame    frame-base.  Enable frame-base before frame-unwind. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_FRAME_LOCALS_ADDRESS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_FRAME_LOCALS_ADDRESS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_LOCALS_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_LOCALS_ADDRESS_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_frame_locals_address_p
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
name|DEPRECATED_FRAME_LOCALS_ADDRESS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_LOCALS_ADDRESS"
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
name|DEPRECATED_FRAME_LOCALS_ADDRESS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_LOCALS_ADDRESS_P
parameter_list|()
value|(gdbarch_deprecated_frame_locals_address_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_frame_locals_address_ftype
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
name|gdbarch_deprecated_frame_locals_address
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
name|set_gdbarch_deprecated_frame_locals_address
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_frame_locals_address_ftype
modifier|*
name|deprecated_frame_locals_address
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
name|DEPRECATED_FRAME_LOCALS_ADDRESS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_FRAME_LOCALS_ADDRESS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_FRAME_LOCALS_ADDRESS
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|(gdbarch_deprecated_frame_locals_address (current_gdbarch, fi))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_SAVED_PC_AFTER_CALL
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_SAVED_PC_AFTER_CALL */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_SAVED_PC_AFTER_CALL_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_SAVED_PC_AFTER_CALL_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_saved_pc_after_call_p
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
name|DEPRECATED_SAVED_PC_AFTER_CALL_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_SAVED_PC_AFTER_CALL"
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
name|DEPRECATED_SAVED_PC_AFTER_CALL_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_SAVED_PC_AFTER_CALL_P
parameter_list|()
value|(gdbarch_deprecated_saved_pc_after_call_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_saved_pc_after_call_ftype
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
name|gdbarch_deprecated_saved_pc_after_call
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
name|set_gdbarch_deprecated_saved_pc_after_call
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_saved_pc_after_call_ftype
modifier|*
name|deprecated_saved_pc_after_call
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
name|DEPRECATED_SAVED_PC_AFTER_CALL
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_SAVED_PC_AFTER_CALL"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_SAVED_PC_AFTER_CALL
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
value|(gdbarch_deprecated_saved_pc_after_call (current_gdbarch, frame))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FRAME_NUM_ARGS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch FRAME_NUM_ARGS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FRAME_NUM_ARGS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_frame_num_args_p
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
name|FRAME_NUM_ARGS_P
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
operator|(
name|GDB_MULTI_ARCH
operator|>
name|GDB_MULTI_ARCH_PARTIAL
operator|)
operator|||
operator|!
name|defined
argument_list|(
name|FRAME_NUM_ARGS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS_P
parameter_list|()
value|(gdbarch_frame_num_args_p (current_gdbarch))
end_define

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

begin_comment
comment|/* DEPRECATED_STACK_ALIGN has been replaced by an initial aligning call    to frame_align and the requirement that methods such as    push_dummy_call and frame_red_zone_size maintain correct stack/frame    alignment. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_STACK_ALIGN
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_STACK_ALIGN */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_STACK_ALIGN_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_STACK_ALIGN_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_stack_align_p
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
name|DEPRECATED_STACK_ALIGN_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_STACK_ALIGN"
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
name|DEPRECATED_STACK_ALIGN_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_STACK_ALIGN_P
parameter_list|()
value|(gdbarch_deprecated_stack_align_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_deprecated_stack_align_ftype
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
name|gdbarch_deprecated_stack_align
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
name|set_gdbarch_deprecated_stack_align
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_stack_align_ftype
modifier|*
name|deprecated_stack_align
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
name|DEPRECATED_STACK_ALIGN
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_STACK_ALIGN"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_STACK_ALIGN
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_STACK_ALIGN
parameter_list|(
name|sp
parameter_list|)
value|(gdbarch_deprecated_stack_align (current_gdbarch, sp))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_frame_align_p
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
name|CORE_ADDR
function_decl|(
name|gdbarch_frame_align_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|address
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_frame_align
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|address
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_frame_align
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_frame_align_ftype
modifier|*
name|frame_align
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DEPRECATED_REG_STRUCT_HAS_ADDR has been replaced by    stabs_argument_has_addr. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|DEPRECATED_REG_STRUCT_HAS_ADDR
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch DEPRECATED_REG_STRUCT_HAS_ADDR */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REG_STRUCT_HAS_ADDR_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REG_STRUCT_HAS_ADDR_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_deprecated_reg_struct_has_addr_p
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
name|DEPRECATED_REG_STRUCT_HAS_ADDR_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REG_STRUCT_HAS_ADDR"
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
name|DEPRECATED_REG_STRUCT_HAS_ADDR_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REG_STRUCT_HAS_ADDR_P
parameter_list|()
value|(gdbarch_deprecated_reg_struct_has_addr_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_deprecated_reg_struct_has_addr_ftype
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
name|gdbarch_deprecated_reg_struct_has_addr
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
name|set_gdbarch_deprecated_reg_struct_has_addr
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_deprecated_reg_struct_has_addr_ftype
modifier|*
name|deprecated_reg_struct_has_addr
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
name|DEPRECATED_REG_STRUCT_HAS_ADDR
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of DEPRECATED_REG_STRUCT_HAS_ADDR"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DEPRECATED_REG_STRUCT_HAS_ADDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEPRECATED_REG_STRUCT_HAS_ADDR
parameter_list|(
name|gcc_p
parameter_list|,
name|type
parameter_list|)
value|(gdbarch_deprecated_reg_struct_has_addr (current_gdbarch, gcc_p, type))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_stabs_argument_has_addr_ftype
function_decl|)
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
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_stabs_argument_has_addr
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
name|set_gdbarch_stabs_argument_has_addr
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_stabs_argument_has_addr_ftype
modifier|*
name|stabs_argument_has_addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdbarch_frame_red_zone_size
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
name|set_gdbarch_frame_red_zone_size
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|frame_red_zone_size
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
name|FRAME_RED_ZONE_SIZE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FRAME_RED_ZONE_SIZE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FRAME_RED_ZONE_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|FRAME_RED_ZONE_SIZE
value|(gdbarch_frame_red_zone_size (current_gdbarch))
end_define

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

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_convert_from_func_ptr_addr_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|struct
name|target_ops
modifier|*
name|targ
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
parameter_list|,
name|struct
name|target_ops
modifier|*
name|targ
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

begin_comment
comment|/* On some machines there are bits in addresses which are not really    part of the address, but are used by the kernel, the hardware, etc.    for special purposes.  ADDR_BITS_REMOVE takes out any such bits so    we get a "real" address such as one would find in a symbol table.    This is used only for addresses of instructions, and even then I'm    not sure it's used in all contexts.  It exists to deal with there    being a few stray bits in the PC which would mislead us, not as some    sort of generic thing to handle alignment or segmentation (it's    possible it should be in TARGET_READ_PC instead). */
end_comment

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

begin_comment
comment|/* It is not at all clear why SMASH_TEXT_ADDRESS is not folded into    ADDR_BITS_REMOVE. */
end_comment

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

begin_comment
comment|/* FIXME: cagney/2003-08-28: Need to find a better way of selecting the    disassembler.  Perhaphs objdump can handle it? */
end_comment

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
name|struct
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
name|struct
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

begin_comment
comment|/* If IN_SOLIB_DYNSYM_RESOLVE_CODE returns true, and SKIP_SOLIB_RESOLVER    evaluates non-zero, this is the address where the debugger will place    a step-resume breakpoint to get us past the dynamic linker. */
end_comment

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_skip_solib_resolver_ftype
function_decl|)
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
end_typedef

begin_function_decl
specifier|extern
name|CORE_ADDR
name|gdbarch_skip_solib_resolver
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
name|set_gdbarch_skip_solib_resolver
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_skip_solib_resolver_ftype
modifier|*
name|skip_solib_resolver
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* For SVR4 shared libraries, each call goes through a small piece of    trampoline code in the ".plt" section.  IN_SOLIB_CALL_TRAMPOLINE evaluates    to nonzero if we are currently stopped in one of these. */
end_comment

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

begin_comment
comment|/* Some systems also have trampoline code for returning from shared libs. */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_in_solib_return_trampoline_ftype
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
name|gdbarch_in_solib_return_trampoline
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
name|set_gdbarch_in_solib_return_trampoline
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_in_solib_return_trampoline_ftype
modifier|*
name|in_solib_return_trampoline
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
name|IN_SOLIB_RETURN_TRAMPOLINE
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of IN_SOLIB_RETURN_TRAMPOLINE"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|IN_SOLIB_RETURN_TRAMPOLINE
argument_list|)
end_if

begin_define
define|#
directive|define
name|IN_SOLIB_RETURN_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|(gdbarch_in_solib_return_trampoline (current_gdbarch, pc, name))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Sigtramp is a routine that the kernel calls (which then calls the    signal handler).  On most machines it is a library routine that is    linked into the executable.       This macro, given a program counter value and the name of the    function in which that PC resides (which can be null if the name is    not known), returns nonzero if the PC and name show that we are in    sigtramp.       On most machines just see if the name is sigtramp (and if we have    no name, assume we are not in sigtramp).       FIXME: cagney/2002-04-21: The function find_pc_partial_function    calls find_pc_sect_partial_function() which calls PC_IN_SIGTRAMP.    This means PC_IN_SIGTRAMP function can't be implemented by doing its    own local NAME lookup.       FIXME: cagney/2002-04-21: PC_IN_SIGTRAMP is something of a mess.    Some code also depends on SIGTRAMP_START and SIGTRAMP_END but other    does not. */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_pc_in_sigtramp_ftype
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
name|gdbarch_pc_in_sigtramp
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
name|set_gdbarch_pc_in_sigtramp
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_pc_in_sigtramp_ftype
modifier|*
name|pc_in_sigtramp
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
name|PC_IN_SIGTRAMP
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of PC_IN_SIGTRAMP"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|PC_IN_SIGTRAMP
argument_list|)
end_if

begin_define
define|#
directive|define
name|PC_IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|(gdbarch_pc_in_sigtramp (current_gdbarch, pc, name))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIGTRAMP_START
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch SIGTRAMP_START */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIGTRAMP_START_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGTRAMP_START_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_sigtramp_start_p
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
name|SIGTRAMP_START_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SIGTRAMP_START"
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
name|SIGTRAMP_START_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGTRAMP_START_P
parameter_list|()
value|(gdbarch_sigtramp_start_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_sigtramp_start_ftype
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
name|gdbarch_sigtramp_start
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
name|set_gdbarch_sigtramp_start
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_sigtramp_start_ftype
modifier|*
name|sigtramp_start
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
name|SIGTRAMP_START
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SIGTRAMP_START"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIGTRAMP_START
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGTRAMP_START
parameter_list|(
name|pc
parameter_list|)
value|(gdbarch_sigtramp_start (current_gdbarch, pc))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SIGTRAMP_END
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch SIGTRAMP_END */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIGTRAMP_END_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGTRAMP_END_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_sigtramp_end_p
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
name|SIGTRAMP_END_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SIGTRAMP_END"
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
name|SIGTRAMP_END_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGTRAMP_END_P
parameter_list|()
value|(gdbarch_sigtramp_end_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_sigtramp_end_ftype
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
name|gdbarch_sigtramp_end
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
name|set_gdbarch_sigtramp_end
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_sigtramp_end_ftype
modifier|*
name|sigtramp_end
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
name|SIGTRAMP_END
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of SIGTRAMP_END"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIGTRAMP_END
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIGTRAMP_END
parameter_list|(
name|pc
parameter_list|)
value|(gdbarch_sigtramp_end (current_gdbarch, pc))
end_define

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

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|gdbarch_name_of_malloc
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
name|set_gdbarch_name_of_malloc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|char
modifier|*
name|name_of_malloc
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
name|NAME_OF_MALLOC
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of NAME_OF_MALLOC"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NAME_OF_MALLOC
argument_list|)
end_if

begin_define
define|#
directive|define
name|NAME_OF_MALLOC
value|(gdbarch_name_of_malloc (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_cannot_step_breakpoint
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
name|set_gdbarch_cannot_step_breakpoint
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|cannot_step_breakpoint
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
name|CANNOT_STEP_BREAKPOINT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of CANNOT_STEP_BREAKPOINT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CANNOT_STEP_BREAKPOINT
argument_list|)
end_if

begin_define
define|#
directive|define
name|CANNOT_STEP_BREAKPOINT
value|(gdbarch_cannot_step_breakpoint (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_have_nonsteppable_watchpoint
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
name|set_gdbarch_have_nonsteppable_watchpoint
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|have_nonsteppable_watchpoint
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
name|HAVE_NONSTEPPABLE_WATCHPOINT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of HAVE_NONSTEPPABLE_WATCHPOINT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_NONSTEPPABLE_WATCHPOINT
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_NONSTEPPABLE_WATCHPOINT
value|(gdbarch_have_nonsteppable_watchpoint (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ADDRESS_CLASS_TYPE_FLAGS
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch ADDRESS_CLASS_TYPE_FLAGS */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ADDRESS_CLASS_TYPE_FLAGS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|ADDRESS_CLASS_TYPE_FLAGS_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_address_class_type_flags_p
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
name|ADDRESS_CLASS_TYPE_FLAGS_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of ADDRESS_CLASS_TYPE_FLAGS"
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
name|ADDRESS_CLASS_TYPE_FLAGS_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|ADDRESS_CLASS_TYPE_FLAGS_P
parameter_list|()
value|(gdbarch_address_class_type_flags_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_address_class_type_flags_ftype
function_decl|)
parameter_list|(
name|int
name|byte_size
parameter_list|,
name|int
name|dwarf2_addr_class
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_address_class_type_flags
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|byte_size
parameter_list|,
name|int
name|dwarf2_addr_class
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_address_class_type_flags
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_address_class_type_flags_ftype
modifier|*
name|address_class_type_flags
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
name|ADDRESS_CLASS_TYPE_FLAGS
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of ADDRESS_CLASS_TYPE_FLAGS"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|ADDRESS_CLASS_TYPE_FLAGS
argument_list|)
end_if

begin_define
define|#
directive|define
name|ADDRESS_CLASS_TYPE_FLAGS
parameter_list|(
name|byte_size
parameter_list|,
name|dwarf2_addr_class
parameter_list|)
value|(gdbarch_address_class_type_flags (current_gdbarch, byte_size, dwarf2_addr_class))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|int
name|gdbarch_address_class_type_flags_to_name_p
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
specifier|const
name|char
modifier|*
function_decl|(
name|gdbarch_address_class_type_flags_to_name_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|type_flags
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|gdbarch_address_class_type_flags_to_name
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|int
name|type_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_address_class_type_flags_to_name
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_address_class_type_flags_to_name_ftype
modifier|*
name|address_class_type_flags_to_name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|gdbarch_address_class_name_to_type_flags_p
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
name|int
function_decl|(
name|gdbarch_address_class_name_to_type_flags_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|type_flags_ptr
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_address_class_name_to_type_flags
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|int
modifier|*
name|type_flags_ptr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_address_class_name_to_type_flags
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_address_class_name_to_type_flags_ftype
modifier|*
name|address_class_name_to_type_flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Is a register in a group */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
name|gdbarch_register_reggroup_p_ftype
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
name|struct
name|reggroup
modifier|*
name|reggroup
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
name|int
name|gdbarch_register_reggroup_p
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
name|reggroup
modifier|*
name|reggroup
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_register_reggroup_p
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_register_reggroup_p_ftype
modifier|*
name|register_reggroup_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fetch the pointer to the ith function argument. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|FETCH_POINTER_ARGUMENT
argument_list|)
end_if

begin_comment
comment|/* Legacy for systems yet to multi-arch FETCH_POINTER_ARGUMENT */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FETCH_POINTER_ARGUMENT_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|FETCH_POINTER_ARGUMENT_P
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

begin_function_decl
specifier|extern
name|int
name|gdbarch_fetch_pointer_argument_p
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
name|FETCH_POINTER_ARGUMENT_P
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FETCH_POINTER_ARGUMENT"
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
name|FETCH_POINTER_ARGUMENT_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|FETCH_POINTER_ARGUMENT_P
parameter_list|()
value|(gdbarch_fetch_pointer_argument_p (current_gdbarch))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|CORE_ADDR
function_decl|(
name|gdbarch_fetch_pointer_argument_ftype
function_decl|)
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|argi
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
name|CORE_ADDR
name|gdbarch_fetch_pointer_argument
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
parameter_list|,
name|int
name|argi
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
name|set_gdbarch_fetch_pointer_argument
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_fetch_pointer_argument_ftype
modifier|*
name|fetch_pointer_argument
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
name|FETCH_POINTER_ARGUMENT
argument_list|)
end_if

begin_error
error|#
directive|error
literal|"Non multi-arch definition of FETCH_POINTER_ARGUMENT"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FETCH_POINTER_ARGUMENT
argument_list|)
end_if

begin_define
define|#
directive|define
name|FETCH_POINTER_ARGUMENT
parameter_list|(
name|frame
parameter_list|,
name|argi
parameter_list|,
name|type
parameter_list|)
value|(gdbarch_fetch_pointer_argument (current_gdbarch, frame, argi, type))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return the appropriate register set for a core file section with    name SECT_NAME and size SECT_SIZE. */
end_comment

begin_function_decl
specifier|extern
name|int
name|gdbarch_regset_from_core_section_p
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
specifier|const
name|struct
name|regset
modifier|*
function_decl|(
name|gdbarch_regset_from_core_section_ftype
function_decl|)
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|char
modifier|*
name|sect_name
parameter_list|,
name|size_t
name|sect_size
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
specifier|extern
specifier|const
name|struct
name|regset
modifier|*
name|gdbarch_regset_from_core_section
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
specifier|const
name|char
modifier|*
name|sect_name
parameter_list|,
name|size_t
name|sect_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_gdbarch_regset_from_core_section
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|gdbarch_regset_from_core_section_ftype
modifier|*
name|regset_from_core_section
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* Register a new architectural family with GDB.     Register support for the specified ARCHITECTURE with GDB.  When    gdbarch determines that the specified architecture has been    selected, the corresponding INIT function is called.     --     The INIT function takes two parameters: INFO which contains the    information available to gdbarch about the (possibly new)    architecture; ARCHES which is a list of the previously created    ``struct gdbarch'' for this architecture.     The INFO parameter is, as far as possible, be pre-initialized with    information obtained from INFO.ABFD or the previously selected    architecture.     The ARCHES parameter is a linked list (sorted most recently used)    of all the previously created architures for this architecture    family.  The (possibly NULL) ARCHES->gdbarch can used to access    values from the previously selected architecture for this    architecture family.  The global ``current_gdbarch'' shall not be    used.     The INIT function shall return any of: NULL - indicating that it    doesn't recognize the selected architecture; an existing ``struct    gdbarch'' from the ARCHES list - indicating that the new    architecture is just a synonym for an earlier architecture (see    gdbarch_list_lookup_by_info()); a newly created ``struct gdbarch''    - that describes the selected architecture (see gdbarch_alloc()).     The DUMP_TDEP function shall print out all target specific values.    Care should be taken to ensure that the function works in both the    multi-arch and non- multi-arch cases. */
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
comment|/* Use default: GDB_OSABI_UNINITIALIZED (-1).  */
name|enum
name|gdb_osabi
name|osabi
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
comment|/* Helper function.  Allocate memory from the ``struct gdbarch''    obstack.  The memory is freed when the corresponding architecture    is also freed.  */
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|gdbarch_obstack_zalloc
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
name|long
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GDBARCH_OBSTACK_CALLOC
parameter_list|(
name|GDBARCH
parameter_list|,
name|NR
parameter_list|,
name|TYPE
parameter_list|)
value|((TYPE *) gdbarch_obstack_zalloc ((GDBARCH), (NR) * sizeof (TYPE)))
end_define

begin_define
define|#
directive|define
name|GDBARCH_OBSTACK_ZALLOC
parameter_list|(
name|GDBARCH
parameter_list|,
name|TYPE
parameter_list|)
value|((TYPE *) gdbarch_obstack_zalloc ((GDBARCH), sizeof (TYPE)))
end_define

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
comment|/* Helper function.  Find an architecture matching info.     INFO should be initialized using gdbarch_info_init, relevant fields    set, and then finished using gdbarch_info_fill.     Returns the corresponding architecture, or NULL if no matching    architecture was found.  "current_gdbarch" is not updated.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|gdbarch
modifier|*
name|gdbarch_find_by_info
parameter_list|(
name|struct
name|gdbarch_info
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Helper function.  Set the global "current_gdbarch" to "gdbarch".     FIXME: kettenis/20031124: Of the functions that follow, only    gdbarch_from_bfd is supposed to survive.  The others will    dissappear since in the future GDB will (hopefully) be truly    multi-arch.  However, for now we're still stuck with the concept of    a single active architecture.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|deprecated_current_gdbarch_select_hack
parameter_list|(
name|struct
name|gdbarch
modifier|*
name|gdbarch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register per-architecture data-pointer.     Reserve space for a per-architecture data-pointer.  An identifier    for the reserved data-pointer is returned.  That identifer should    be saved in a local static variable.     The per-architecture data-pointer is either initialized explicitly    (set_gdbarch_data()) or implicitly (by INIT() via a call to    gdbarch_data()).     Memory for the per-architecture data shall be allocated using    gdbarch_obstack_zalloc.  That memory will be deleted when the    corresponding architecture object is deleted.     When a previously created architecture is re-selected, the    per-architecture data-pointer for that previous architecture is    restored.  INIT() is not re-called.     Multiple registrarants for any architecture are allowed (and    strongly encouraged).  */
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
name|gdbarch
modifier|*
name|gdbarch
parameter_list|,
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
name|deprecated_register_gdbarch_swap
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
name|DEPRECATED_REGISTER_GDBARCH_SWAP
parameter_list|(
name|VAR
parameter_list|)
value|deprecated_register_gdbarch_swap (&(VAR), sizeof ((VAR)), NULL)
end_define

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

