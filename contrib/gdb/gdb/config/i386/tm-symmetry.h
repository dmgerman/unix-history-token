begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine definitions for GDB on a Sequent Symmetry under dynix 3.0,    with Weitek 1167 and i387 support.    Copyright 1986, 1987, 1989, 1991, 1992, 1993, 1994    Free Software Foundation, Inc.    Symmetry version by Jay Vosburgh (fubar@sequent.com).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_SYMMETRY_H
end_ifndef

begin_define
define|#
directive|define
name|TM_SYMMETRY_H
value|1
end_define

begin_comment
comment|/* I don't know if this will work for cross-debugging, even if you do get    a copy of the right include file.  */
end_comment

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_include
include|#
directive|include
file|"i386/tm-i386v.h"
end_include

begin_undef
undef|#
directive|undef
name|START_INFERIOR_TRAPS_EXPECTED
end_undef

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|2
end_define

begin_comment
comment|/* Amount PC must be decremented by after a breakpoint.  This is often the    number of bytes in BREAKPOINT but not always (such as now). */
end_comment

begin_undef
undef|#
directive|undef
name|DECR_PC_AFTER_BREAK
end_undef

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* --- this code can't be used unless we know we are running native,        since it uses host specific ptrace calls. */
end_comment

begin_comment
comment|/* code for 80387 fpu.  Functions are from i386-dep.c, copied into  * symm-dep.c.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_INFO
value|{ i386_float_info(); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of machine registers */
end_comment

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_define
define|#
directive|define
name|NUM_REGS
value|49
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_comment
comment|/* Initializer for an array of names of registers.  There should be at least    NUM_REGS strings in this initializer.  Any excess ones are simply ignored.    Symmetry registers are in this weird order to match the register numbers    in the symbol table entries.  If you change the order, things will probably    break mysteriously for no apparent reason.  Also note that the st(0)...    st(7) 387 registers are represented as st0...st7.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{     "eax",  "edx",  "ecx",   "st0",  "st1", \ 			     "ebx",  "esi",  "edi",   "st2",  "st3", \ 			     "st4",  "st5",  "st6",   "st7",  "esp", \ 			     "ebp",  "eip",  "eflags","fp1",  "fp2", \ 			     "fp3",  "fp4",  "fp5",   "fp6",  "fp7", \ 			     "fp8",  "fp9",  "fp10",  "fp11", "fp12", \ 			     "fp13", "fp14", "fp15",  "fp16", "fp17", \ 			     "fp18", "fp19", "fp20",  "fp21", "fp22", \ 			     "fp23", "fp24", "fp25",  "fp26", "fp27", \ 			     "fp28", "fp29", "fp30",  "fp31" }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|EAX_REGNUM
value|0
end_define

begin_define
define|#
directive|define
name|EDX_REGNUM
value|1
end_define

begin_define
define|#
directive|define
name|ECX_REGNUM
value|2
end_define

begin_define
define|#
directive|define
name|ST0_REGNUM
value|3
end_define

begin_define
define|#
directive|define
name|ST1_REGNUM
value|4
end_define

begin_define
define|#
directive|define
name|EBX_REGNUM
value|5
end_define

begin_define
define|#
directive|define
name|ESI_REGNUM
value|6
end_define

begin_define
define|#
directive|define
name|EDI_REGNUM
value|7
end_define

begin_define
define|#
directive|define
name|ST2_REGNUM
value|8
end_define

begin_define
define|#
directive|define
name|ST3_REGNUM
value|9
end_define

begin_define
define|#
directive|define
name|ST4_REGNUM
value|10
end_define

begin_define
define|#
directive|define
name|ST5_REGNUM
value|11
end_define

begin_define
define|#
directive|define
name|ST6_REGNUM
value|12
end_define

begin_define
define|#
directive|define
name|ST7_REGNUM
value|13
end_define

begin_define
define|#
directive|define
name|FP1_REGNUM
value|18
end_define

begin_comment
comment|/* first 1167 register */
end_comment

begin_comment
comment|/* Get %fp2 - %fp31 by addition, since they are contiguous */
end_comment

begin_undef
undef|#
directive|undef
name|SP_REGNUM
end_undef

begin_define
define|#
directive|define
name|SP_REGNUM
value|14
end_define

begin_comment
comment|/* (usp) Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|ESP_REGNUM
value|14
end_define

begin_undef
undef|#
directive|undef
name|FP_REGNUM
end_undef

begin_define
define|#
directive|define
name|FP_REGNUM
value|15
end_define

begin_comment
comment|/* (ebp) Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|EBP_REGNUM
value|15
end_define

begin_undef
undef|#
directive|undef
name|PC_REGNUM
end_undef

begin_define
define|#
directive|define
name|PC_REGNUM
value|16
end_define

begin_comment
comment|/* (eip) Contains program counter */
end_comment

begin_define
define|#
directive|define
name|EIP_REGNUM
value|16
end_define

begin_undef
undef|#
directive|undef
name|PS_REGNUM
end_undef

begin_define
define|#
directive|define
name|PS_REGNUM
value|17
end_define

begin_comment
comment|/* (ps)  Contains processor status */
end_comment

begin_define
define|#
directive|define
name|EFLAGS_REGNUM
value|17
end_define

begin_comment
comment|/*  * Following macro translates i386 opcode register numbers to Symmetry  * register numbers.  This is used by i386_frame_find_saved_regs.  *  *           %eax  %ecx  %edx  %ebx  %esp  %ebp  %esi  %edi  * i386        0     1     2     3     4     5     6     7  * Symmetry    0     2     1     5    14    15     6     7  *  */
end_comment

begin_define
define|#
directive|define
name|I386_REGNO_TO_SYMMETRY
parameter_list|(
name|n
parameter_list|)
define|\
value|((n)==0?0 :(n)==1?2 :(n)==2?1 :(n)==3?5 :(n)==4?14 :(n)==5?15 :(n))
end_define

begin_comment
comment|/* The magic numbers below are offsets into u_ar0 in the user struct.  * They live in<machine/reg.h>.  Gdb calls this macro with blockend  * holding u.u_ar0 - KERNEL_U_ADDR.  Only the registers listed are  * saved in the u area (along with a few others that aren't useful  * here.  See<machine/reg.h>).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|addr
parameter_list|,
name|blockend
parameter_list|,
name|regno
parameter_list|)
define|\
value|{ struct user foo;
comment|/* needed for finding fpu regs */
value|\ switch (regno) { \     case 0: \       addr = blockend + EAX * sizeof(int); break; \   case 1: \       addr = blockend + EDX * sizeof(int); break; \   case 2: \       addr = blockend + ECX * sizeof(int); break; \   case 3:
comment|/* st(0) */
value|\       addr = ((int)&foo.u_fpusave.fpu_stack[0][0] - (int)&foo); \       break; \   case 4:
comment|/* st(1) */
value|\       addr = ((int)&foo.u_fpusave.fpu_stack[1][0] - (int)&foo); \       break; \   case 5: \       addr = blockend + EBX * sizeof(int); break; \   case 6: \       addr = blockend + ESI * sizeof(int); break; \   case 7: \       addr = blockend + EDI * sizeof(int); break; \   case 8:
comment|/* st(2) */
value|\       addr = ((int)&foo.u_fpusave.fpu_stack[2][0] - (int)&foo); \       break; \   case 9:
comment|/* st(3) */
value|\       addr = ((int)&foo.u_fpusave.fpu_stack[3][0] - (int)&foo); \       break; \   case 10:
comment|/* st(4) */
value|\       addr = ((int)&foo.u_fpusave.fpu_stack[4][0] - (int)&foo); \       break; \   case 11:
comment|/* st(5) */
value|\       addr = ((int)&foo.u_fpusave.fpu_stack[5][0] - (int)&foo); \       break; \   case 12:
comment|/* st(6) */
value|\       addr = ((int)&foo.u_fpusave.fpu_stack[6][0] - (int)&foo); \       break; \   case 13:
comment|/* st(7) */
value|\       addr = ((int)&foo.u_fpusave.fpu_stack[7][0] - (int)&foo); \       break; \   case 14: \       addr = blockend + ESP * sizeof(int); break; \   case 15: \       addr = blockend + EBP * sizeof(int); break; \   case 16: \       addr = blockend + EIP * sizeof(int); break; \   case 17: \       addr = blockend + FLAGS * sizeof(int); break; \   case 18:
comment|/* fp1 */
value|\   case 19:
comment|/* fp2 */
value|\   case 20:
comment|/* fp3 */
value|\   case 21:
comment|/* fp4 */
value|\   case 22:
comment|/* fp5 */
value|\   case 23:
comment|/* fp6 */
value|\   case 24:
comment|/* fp7 */
value|\   case 25:
comment|/* fp8 */
value|\   case 26:
comment|/* fp9 */
value|\   case 27:
comment|/* fp10 */
value|\   case 28:
comment|/* fp11 */
value|\   case 29:
comment|/* fp12 */
value|\   case 30:
comment|/* fp13 */
value|\   case 31:
comment|/* fp14 */
value|\   case 32:
comment|/* fp15 */
value|\   case 33:
comment|/* fp16 */
value|\   case 34:
comment|/* fp17 */
value|\   case 35:
comment|/* fp18 */
value|\   case 36:
comment|/* fp19 */
value|\   case 37:
comment|/* fp20 */
value|\   case 38:
comment|/* fp21 */
value|\   case 39:
comment|/* fp22 */
value|\   case 40:
comment|/* fp23 */
value|\   case 41:
comment|/* fp24 */
value|\   case 42:
comment|/* fp25 */
value|\   case 43:
comment|/* fp26 */
value|\   case 44:
comment|/* fp27 */
value|\   case 45:
comment|/* fp28 */
value|\   case 46:
comment|/* fp29 */
value|\   case 47:
comment|/* fp30 */
value|\   case 48:
comment|/* fp31 */
value|\      addr = ((int)&foo.u_fpasave.fpa_regs[(regno)-18] - (int)&foo); \   } \ }
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  10 i*86 registers, 8 i387    registers, and 31 Weitek 1167 registers */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_BYTES
end_undef

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|((10 * 4) + (8 * 10) + (31 * 4))
end_define

begin_comment
comment|/* Index within `registers' of the first byte of the space for    register N.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_BYTE
end_undef

begin_define
define|#
directive|define
name|REGISTER_BYTE
parameter_list|(
name|N
parameter_list|)
define|\
value|(((N)< 3) ? ((N) * 4) :		\ ((N)< 5) ? ((((N) - 2) * 10) + 2) :	\ ((N)< 8) ? ((((N) - 5) * 4) + 32) :	\ ((N)< 14) ? ((((N) - 8) * 10) + 44) :	\     ((((N) - 14) * 4) + 104))
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation  * for register N.  All registers are 4 bytes, except 387 st(0) - st(7),  * which are 80 bits each.   */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_RAW_SIZE
end_undef

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
define|\
value|(((N)< 3) ? 4 :	\ ((N)< 5) ? 10 :	\ ((N)< 8) ? 4 :		\ ((N)< 14) ? 10 :	\     4)
end_define

begin_comment
comment|/* Nonzero if register N requires conversion    from raw format to virtual format.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERTIBLE
end_undef

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|N
parameter_list|)
define|\
value|(((N)< 3) ? 0 : \ ((N)< 5) ? 1  : \ ((N)< 8) ? 0  : \ ((N)< 14) ? 1 : \     0)
end_define

begin_include
include|#
directive|include
file|"floatformat.h"
end_include

begin_comment
comment|/* Convert data from raw format for register REGNUM in buffer FROM    to virtual format with type TYPE in buffer TO.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERT_TO_VIRTUAL
end_undef

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
value|{ \   double val; \   floatformat_to_double (&floatformat_i387_ext, (FROM),&val); \   store_floating ((TO), TYPE_LENGTH (TYPE), val); \ }
end_define

begin_comment
comment|/* Convert data from virtual format with type TYPE in buffer FROM    to raw format for register REGNUM in buffer TO.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERT_TO_RAW
end_undef

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
value|{ \   double val = extract_floating ((FROM), TYPE_LENGTH (TYPE)); \   floatformat_from_double (&floatformat_i387_ext,&val, (TO)); \ }
end_define

begin_comment
comment|/* Return the GDB type object for the "standard" data type    of data in register N.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_VIRTUAL_TYPE
end_undef

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_TYPE
parameter_list|(
name|N
parameter_list|)
define|\
value|((N< 3) ? builtin_type_int : \ (N< 5) ? builtin_type_double : \ (N< 8) ? builtin_type_int : \ (N< 14) ? builtin_type_double : \     builtin_type_int)
end_define

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function.    Native cc passes the address in eax, gcc (up to version 2.5.8)    passes it on the stack.  gcc should be fixed in future versions to    adopt native cc conventions.  */
end_comment

begin_undef
undef|#
directive|undef
name|STORE_STRUCT_RETURN
end_undef

begin_define
define|#
directive|define
name|STORE_STRUCT_RETURN
parameter_list|(
name|ADDR
parameter_list|,
name|SP
parameter_list|)
value|write_register(0, (ADDR))
end_define

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    a function return value of type TYPE, and copy that, in virtual format,    into VALBUF.  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRACT_RETURN_VALUE
end_undef

begin_define
define|#
directive|define
name|EXTRACT_RETURN_VALUE
parameter_list|(
name|TYPE
parameter_list|,
name|REGBUF
parameter_list|,
name|VALBUF
parameter_list|)
define|\
value|symmetry_extract_return_value(TYPE, REGBUF, VALBUF)
end_define

begin_comment
comment|/* The following redefines make backtracing through sigtramp work.    They manufacture a fake sigtramp frame and obtain the saved pc in sigtramp    from the sigcontext structure which is pushed by the kernel on the    user stack, along with a pointer to it.  */
end_comment

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|((name)&& STREQ ("_sigcode", name))
end_define

begin_comment
comment|/* Offset to saved PC in sigcontext, from<signal.h>.  */
end_comment

begin_define
define|#
directive|define
name|SIGCONTEXT_PC_OFFSET
value|16
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef TM_SYMMETRY_H */
end_comment

end_unit

