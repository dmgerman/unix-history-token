begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for target execution on an RS6000, for GDB, the GNU debugger.    Copyright (C) 1986, 1987, 1989, 1991 Free Software Foundation, Inc.    Contributed by IBM Corporation.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|symtab_relocated
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Minimum possible text address in AIX */
end_comment

begin_define
define|#
directive|define
name|TEXT_SEGMENT_BASE
value|0x10000000
end_define

begin_comment
comment|/* text addresses in a core file does not necessarily match to symbol table,    if symbol table relocation wasn't done yet. */
end_comment

begin_define
define|#
directive|define
name|CORE_NEEDS_RELOCATION
parameter_list|(
name|PC
parameter_list|)
define|\
value|if (!symtab_relocated&& !inferior_pid&& (PC)>  TEXT_SEGMENT_BASE)	\     (PC) -= ( TEXT_SEGMENT_BASE + text_adjustment (exec_bfd));
end_define

begin_comment
comment|/* Load segment of a given pc value. */
end_comment

begin_define
define|#
directive|define
name|PC_LOAD_SEGMENT
parameter_list|(
name|PC
parameter_list|)
value|pc_load_segment_name(PC)
end_define

begin_comment
comment|/* Conversion between a register number in stab string to actual register num. */
end_comment

begin_define
define|#
directive|define
name|STAB_REG_TO_REGNUM
parameter_list|(
name|value
parameter_list|)
value|(value)
end_define

begin_comment
comment|/* return true if a given `pc' value is in `call dummy' function. */
end_comment

begin_define
define|#
directive|define
name|PC_IN_CALL_DUMMY
parameter_list|(
name|STOP_PC
parameter_list|,
name|STOP_SP
parameter_list|,
name|STOP_FRAME_ADDR
parameter_list|)
define|\
value|(STOP_SP< STOP_PC&& STOP_PC< STACK_END_ADDR)
end_define

begin_comment
comment|/* For each symtab, we keep track of which BFD it came from.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SYMTAB_INFO
define|\
value|unsigned    nonreloc:1;
end_define

begin_comment
comment|/* TRUE if non relocatable */
end_comment

begin_define
define|#
directive|define
name|INIT_EXTRA_SYMTAB_INFO
parameter_list|(
name|symtab
parameter_list|)
define|\
value|symtab->nonreloc = 0;		\  extern unsigned int text_start, data_start;
end_define

begin_decl_stmt
specifier|extern
name|int
name|inferior_pid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|corefile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* setpgrp() messes up controling terminal. The other version of it    requires libbsd.a. */
end_comment

begin_define
define|#
directive|define
name|setpgrp
parameter_list|(
name|XX
parameter_list|,
name|YY
parameter_list|)
value|setpgid (XX, YY)
end_define

begin_comment
comment|/* We are missing register descriptions in the system header files. Sigh! */
end_comment

begin_struct
struct|struct
name|regs
block|{
name|int
name|gregs
index|[
literal|32
index|]
decl_stmt|;
comment|/* general purpose registers */
name|int
name|pc
decl_stmt|;
comment|/* program conter	*/
name|int
name|ps
decl_stmt|;
comment|/* processor status, or machine state */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fp_status
block|{
name|double
name|fpregs
index|[
literal|32
index|]
decl_stmt|;
comment|/* floating GP registers */
block|}
struct|;
end_struct

begin_comment
comment|/* To be used by function_frame_info. */
end_comment

begin_struct
struct|struct
name|aix_framedata
block|{
name|int
name|offset
decl_stmt|;
comment|/* # of bytes in gpr's and fpr's are saved */
name|int
name|saved_gpr
decl_stmt|;
comment|/* smallest # of saved gpr */
name|int
name|saved_fpr
decl_stmt|;
comment|/* smallest # of saved fpr */
name|int
name|alloca_reg
decl_stmt|;
comment|/* alloca register number (frame ptr) */
name|char
name|frameless
decl_stmt|;
comment|/* true if frameless functions. */
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|function_frame_info
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|,
expr|struct
name|aix_framedata
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the byte order of the machine.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* Define this if the C compiler puts an underscore at the front    of external names before giving them to the linker.  */
end_comment

begin_undef
undef|#
directive|undef
name|NAMES_HAVE_UNDERSCORE
end_undef

begin_comment
comment|/* AIX's assembler doesn't grok dollar signs in identifiers.    So we use dots instead.  This item must be coordinated with G++. */
end_comment

begin_undef
undef|#
directive|undef
name|CPLUS_MARKER
end_undef

begin_define
define|#
directive|define
name|CPLUS_MARKER
value|'.'
end_define

begin_comment
comment|/* Offset from address of function to start of its code.    Zero on most machines.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_START_OFFSET
value|0
end_define

begin_comment
comment|/* Advance PC across any function entry prologue instructions    to reach some "real" code.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|pc
parameter_list|)
value|pc = skip_prologue (pc)
end_define

begin_comment
comment|/* If PC is in some function-call trampoline code, return the PC    where the function itself actually starts.  If not, return NULL.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_TRAMPOLINE_CODE
parameter_list|(
name|pc
parameter_list|)
value|skip_trampoline_code (pc)
end_define

begin_comment
comment|/* When a child process is just starting, we sneak in and relocate    the symbol table (and other stuff) after the dynamic linker has    figured out where they go. But we want to do this relocation just    once. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|loadinfotextindex
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SOLIB_CREATE_INFERIOR_HOOK
parameter_list|(
name|PID
parameter_list|)
define|\
value|do {					\     if (loadinfotextindex == 0)	\ 	xcoff_relocate_symtab (PID);	\   } while (0)
end_define

begin_comment
comment|/* Number of trap signals we need to skip over, once the inferior process    starts running. */
end_comment

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|2
end_define

begin_comment
comment|/* AIX might return a sigtrap, with a "stop after load" status. It should    be ignored by gdb, shouldn't be mixed up with breakpoint traps. */
end_comment

begin_comment
comment|/* Another little glitch  in AIX is signal 0. I have no idea why wait(2)    returns with this status word. It looks harmless. */
end_comment

begin_define
define|#
directive|define
name|SIGTRAP_STOP_AFTER_LOAD
parameter_list|(
name|W
parameter_list|)
define|\
value|if ( (W) == 0x57c || (W) == 0x7f) {	\    if ((W)==0x57c&& breakpoints_inserted) {	\      mark_breakpoints_out ();		\      insert_breakpoints ();		\      insert_step_breakpoint ();		\    }					\    resume (0, 0);			\    continue;				\  }
end_define

begin_comment
comment|/* In xcoff, we cannot process line numbers when we see them. This is    mainly because we don't know the boundaries of the include files. So,    we postpone that, and then enter and sort(?) the whole line table at    once, when we are closing the current symbol table in end_symtab(). */
end_comment

begin_define
define|#
directive|define
name|PROCESS_LINENUMBER_HOOK
parameter_list|()
value|aix_process_linenos ()
end_define

begin_comment
comment|/* When a target process or core-file has been attached, we sneak in    and figure out where the shared libraries have got to. In case there    is no inferior_process exists (e.g. bringing up a core file), we can't    attemtp to relocate symbol table, since we don't have information about    load segments. */
end_comment

begin_define
define|#
directive|define
name|SOLIB_ADD
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
define|\
value|if (inferior_pid)	xcoff_relocate_symtab (inferior_pid)
end_define

begin_comment
comment|/* Immediately after a function call, return the saved pc.    Can't go through the frames for this because on some machines    the new frame is not set up until the new function executes    some instructions.  */
end_comment

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
define|\
value|(register_valid [LR_REGNUM] ? 	\ 	  (*(int*)&registers[REGISTER_BYTE (LR_REGNUM)]) :	\ 	  read_register (LR_REGNUM))
end_define

begin_comment
comment|/*#define SAVED_PC_AFTER_CALL(frame)	saved_pc_after_call(frame) */
end_comment

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|0x2ff80000
end_define

begin_comment
comment|/* Stack grows downward.  */
end_comment

begin_define
define|#
directive|define
name|INNER_THAN
value|<
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* No, we shouldn't use this. push_arguments() should leave stack in a    proper alignment! */
end_comment

begin_comment
comment|/* Stack has strict alignment. */
end_comment

begin_define
define|#
directive|define
name|STACK_ALIGN
parameter_list|(
name|ADDR
parameter_list|)
value|(((ADDR)+7)&-8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how argumets pushed onto stack or passed in registers. */
end_comment

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
define|\
value|sp = push_arguments(nargs, args, sp, struct_return, struct_addr)
end_define

begin_comment
comment|/* Sequence of bytes for breakpoint instruction.  */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x7d, 0x82, 0x10, 0x08}
end_define

begin_comment
comment|/* Amount PC must be decremented by after a breakpoint.    This is often the number of bytes in BREAKPOINT    but not always.  */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

begin_comment
comment|/* Nonzero if instruction at PC is a return instruction.  */
end_comment

begin_comment
comment|/* Allow any of the return instructions, including a trapv and a return    from interrupt.  */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
define|\
value|((read_memory_integer (pc, 4)& 0xfe8007ff) == 0x4e800020)
end_define

begin_comment
comment|/* Return 1 if P points to an invalid floating point value.  */
end_comment

begin_define
define|#
directive|define
name|INVALID_FLOAT
parameter_list|(
name|p
parameter_list|,
name|len
parameter_list|)
value|0
end_define

begin_comment
comment|/* Just a first guess; not checked */
end_comment

begin_comment
comment|/* Largest integer type */
end_comment

begin_define
define|#
directive|define
name|LONGEST
value|long
end_define

begin_comment
comment|/* Name of the builtin type for the LONGEST type above. */
end_comment

begin_define
define|#
directive|define
name|BUILTIN_TYPE_LONGEST
value|builtin_type_long
end_define

begin_comment
comment|/* Say how long (ordinary) registers are.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_TYPE
value|long
end_define

begin_comment
comment|/* Number of machine registers */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|71
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",  \   "r8", "r9", "r10","r11","r12","r13","r14","r15", \   "r16","r17","r18","r19","r20","r21","r22","r23", \   "r24","r25","r26","r27","r28","r29","r30","r31", \   "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",  \   "f8", "f9", "f10","f11","f12","f13","f14","f15", \   "f16","f17","f18","f19","f20","f21","f22","f23", \   "f24","f25","f26","f27","f28","f29","f30","f31", \   "pc", "ps", "cnd", "lr", "cnt", "xer", "mq" }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|1
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|1
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|TOC_REGNUM
value|2
end_define

begin_comment
comment|/* TOC register */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|32
end_define

begin_comment
comment|/* Floating point register 0 */
end_comment

begin_define
define|#
directive|define
name|GP0_REGNUM
value|0
end_define

begin_comment
comment|/* GPR register 0 */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|32
end_define

begin_comment
comment|/* FPR (Floating point) register 0 */
end_comment

begin_define
define|#
directive|define
name|FPLAST_REGNUM
value|63
end_define

begin_comment
comment|/* Last floating point register */
end_comment

begin_comment
comment|/* Special purpose registers... */
end_comment

begin_comment
comment|/* P.S. keep these in the same order as in /usr/mstsave.h `mstsave' structure, for    easier processing */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|64
end_define

begin_comment
comment|/* Program counter (instruction address %iar) */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|65
end_define

begin_comment
comment|/* Processor (or machine) status (%msr) */
end_comment

begin_define
define|#
directive|define
name|CR_REGNUM
value|66
end_define

begin_comment
comment|/* Condition register */
end_comment

begin_define
define|#
directive|define
name|LR_REGNUM
value|67
end_define

begin_comment
comment|/* Link register */
end_comment

begin_define
define|#
directive|define
name|CTR_REGNUM
value|68
end_define

begin_comment
comment|/* Count register */
end_comment

begin_define
define|#
directive|define
name|XER_REGNUM
value|69
end_define

begin_comment
comment|/* Fixed point exception registers */
end_comment

begin_define
define|#
directive|define
name|MQ_REGNUM
value|70
end_define

begin_comment
comment|/* Multiply/quotient register */
end_comment

begin_define
define|#
directive|define
name|FIRST_SP_REGNUM
value|64
end_define

begin_comment
comment|/* first special register number */
end_comment

begin_define
define|#
directive|define
name|LAST_SP_REGNUM
value|70
end_define

begin_comment
comment|/* last special register number */
end_comment

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  	32 4-byte gpr's 	32 8-byte fpr's 	7  4-byte special purpose registers,      total 416 bytes. Keep some extra space for now, in case to add more. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|420
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
define|\
value|(								\   ((N)> FPLAST_REGNUM) ? ((((N) - FPLAST_REGNUM -1) * 4) + 384)\   :((N)>= FP0_REGNUM) ? ((((N) - FP0_REGNUM) * 8) + 128)	\   :((N) * 4) )
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N. */
end_comment

begin_comment
comment|/* Note that the unsigned cast here forces the result of the    subtractiion to very high positive values if N< FP0_REGNUM */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|(((unsigned)(N) - FP0_REGNUM)< 32 ? 8 : 4)
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N.  On the RS6000, all regs are 4 bytes    except the floating point regs which are 8-byte doubles.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|(((unsigned)(N) - FP0_REGNUM)< 32 ? 8 : 4)
end_define

begin_comment
comment|/* Largest value REGISTER_RAW_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|8
end_define

begin_comment
comment|/* Largest value REGISTER_VIRTUAL_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|8
end_define

begin_comment
comment|/* convert a dbx stab register number (from `r' declaration) to a gdb REGNUM */
end_comment

begin_define
define|#
directive|define
name|STAB_REG_TO_REGNUM
parameter_list|(
name|value
parameter_list|)
value|(value)
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
value|((N)>= FP0_REGNUM&& (N)<= FPLAST_REGNUM)
end_define

begin_comment
comment|/* Convert data from raw format for register REGNUM    to virtual format for register REGNUM.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_VIRTUAL
parameter_list|(
name|REGNUM
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|bcopy ((FROM), (TO), REGISTER_RAW_SIZE (REGNUM))
end_define

begin_comment
comment|/* Convert data from virtual format for register REGNUM    to raw format for register REGNUM.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_RAW
parameter_list|(
name|REGNUM
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|bcopy ((FROM), (TO), REGISTER_RAW_SIZE (REGNUM))
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
value|(((unsigned)(N) - FP0_REGNUM)< 32 ? builtin_type_double : builtin_type_int)
end_define

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function. */
end_comment

begin_comment
comment|/* in RS6000, struct return addresses are passed as an extra parameter in r3.    In function return, callee is not responsible of returning this address back.    Since gdb needs to find it, we will store in a designated variable    `rs6000_struct_return_address'. */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|rs6000_struct_return_address
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|STORE_STRUCT_RETURN
parameter_list|(
name|ADDR
parameter_list|,
name|SP
parameter_list|)
define|\
value|{ write_register (3, (ADDR));		\     rs6000_struct_return_address = (unsigned int)(ADDR); }
end_define

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    a function return value of type TYPE, and copy that, in virtual format,    into VALBUF.  */
end_comment

begin_comment
comment|/* #define EXTRACT_RETURN_VALUE(TYPE,REGBUF,VALBUF) \   bcopy (REGBUF, VALBUF, TYPE_LENGTH (TYPE)) */
end_comment

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
value|extract_return_value(TYPE,REGBUF,VALBUF)
end_define

begin_comment
comment|/* Write into appropriate registers a function return value    of type TYPE, given in virtual format.  */
end_comment

begin_define
define|#
directive|define
name|STORE_RETURN_VALUE
parameter_list|(
name|TYPE
parameter_list|,
name|VALBUF
parameter_list|)
define|\
value|{									\     if (TYPE_CODE (TYPE) == TYPE_CODE_FLT)				\ 									\
comment|/* Floating point values are returned starting from FPR1 and up.	\ 	Say a double_double_double type could be returned in		\ 	FPR1/FPR2/FPR3 triple. */
value|\ 									\       write_register_bytes (REGISTER_BYTE (FP0_REGNUM+1), (VALBUF),	\ 						TYPE_LENGTH (TYPE));	\     else								\
comment|/* Everything else is returned in GPR3 and up. */
value|\       write_register_bytes (REGISTER_BYTE (GP0_REGNUM+3), (VALBUF),	\ 						TYPE_LENGTH (TYPE));	\   }
end_define

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    the address in which a function should return its structure value,    as a CORE_ADDR (or an expression that can be used as one).  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_STRUCT_VALUE_ADDRESS
parameter_list|(
name|REGBUF
parameter_list|)
value|rs6000_struct_return_address
end_define

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer. */
end_comment

begin_comment
comment|/* In the case of the RS6000, the frame's nominal address    is the address of a 4-byte word containing the calling frame's address.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(!inside_entry_file ((thisframe)->pc) ?	\    read_memory_integer ((thisframe)->frame, 4) :\    0)
end_define

begin_comment
comment|/* Define other aspects of the stack frame.  */
end_comment

begin_comment
comment|/* A macro that tells us whether the function invocation represented    by FI does not have a frame on the stack associated with it.  If it    does not, FRAMELESS is set to 1, else 0.  */
end_comment

begin_define
define|#
directive|define
name|FRAMELESS_FUNCTION_INVOCATION
parameter_list|(
name|FI
parameter_list|,
name|FRAMELESS
parameter_list|)
define|\
value|FRAMELESS = frameless_function_invocation (FI)
end_define

begin_comment
comment|/* Functions calling alloca() change the value of the stack pointer. We    need to use initial stack pointer (which is saved in r31 by gcc) in     such cases. If a compiler emits traceback table, then we should use the    alloca register specified in traceback table. FIXME. */
end_comment

begin_comment
comment|/* Also, it is a good idea to cache information about frame's saved registers    in the frame structure to speed things up. See tm-m88k.h. FIXME. */
end_comment

begin_define
define|#
directive|define
name|EXTRA_FRAME_INFO
define|\
value|CORE_ADDR initial_sp;
comment|/* initial stack pointer. */
value|\ 	struct frame_saved_regs *cache_fsr;
end_define

begin_comment
comment|/* saved registers	  */
end_comment

begin_comment
comment|/* Frameless function invocation in IBM RS/6000 is half-done. It perfectly    sets up a new frame, e.g. a new frame (in fact stack) pointer, etc, but it     doesn't save the %pc. In the following, even though it is considered a     frameless invocation, we still need to walk one frame up. */
end_comment

begin_define
define|#
directive|define
name|INIT_EXTRA_FRAME_INFO
parameter_list|(
name|fromleaf
parameter_list|,
name|fi
parameter_list|)
define|\
value|fi->initial_sp = 0;		\ 	fi->cache_fsr = 0;
end_define

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
define|\
value|read_memory_integer (read_memory_integer ((FRAME)->frame, 4)+8, 4)
end_define

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|FI
parameter_list|)
define|\
value|(((struct frame_info*)(FI))->initial_sp ?		\ 	((struct frame_info*)(FI))->initial_sp :	\ 	frame_initial_stack_address (FI))
end_define

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|FI
parameter_list|)
value|FRAME_ARGS_ADDRESS(FI)
end_define

begin_comment
comment|/* Set VAL to the number of args passed to frame described by FI.    Can set VAL to -1, meaning no way to tell.  */
end_comment

begin_comment
comment|/* We can't tell how many args there are    now that the C compiler delays popping them.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS
parameter_list|(
name|val
parameter_list|,
name|fi
parameter_list|)
value|(val = -1)
end_define

begin_comment
comment|/* Return number of bytes at start of arglist that are not really args.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_SKIP
value|8
end_define

begin_comment
comment|/* Not sure on this. FIXMEmgo */
end_comment

begin_comment
comment|/* Put here the code to store, into a struct frame_saved_regs,    the addresses of the saved registers of frame described by FRAME_INFO.    This includes special registers such as pc and fp saved in special    ways in the stack frame.  sp is even more special:    the address we return for it IS the sp for the next frame.  */
end_comment

begin_comment
comment|/* In the following implementation for RS6000, we did *not* save sp. I am    not sure if it will be needed. The following macro takes care of gpr's    and fpr's only. */
end_comment

begin_define
define|#
directive|define
name|FRAME_FIND_SAVED_REGS
parameter_list|(
name|FRAME_INFO
parameter_list|,
name|FRAME_SAVED_REGS
parameter_list|)
define|\
value|{									\   int ii;								\   CORE_ADDR frame_addr, func_start;					\   struct aix_framedata fdata;						\ 									\
comment|/* find the start of the function and collect info about its frame. */
value|\ 									\   func_start = get_pc_function_start ((FRAME_INFO)->pc) + FUNCTION_START_OFFSET; \   function_frame_info (func_start,&fdata);				\   bzero (&(FRAME_SAVED_REGS), sizeof (FRAME_SAVED_REGS));		\ 									\
comment|/* if there were any saved registers, figure out parent's stack pointer. */
value|\   frame_addr = 0;							\
comment|/* the following is true only if the frame doesn't have a call to alloca(), \       FIXME. */
value|\   if (fdata.saved_fpr>= 0 || fdata.saved_gpr>= 0) {			\     if ((FRAME_INFO)->prev&& (FRAME_INFO)->prev->frame)		\       frame_addr = (FRAME_INFO)->prev->frame;				\     else								\       frame_addr = read_memory_integer ((FRAME_INFO)->frame, 4);	\   }									\ 									\
comment|/* if != -1, fdata.saved_fpr is the smallest number of saved_fpr. All fpr's \      from saved_fpr to fp31 are saved right underneath caller stack pointer, \      starting from fp31 first. */
value|\ 									\   if (fdata.saved_fpr>= 0) {						\     for (ii=31; ii>= fdata.saved_fpr; --ii) 				\       (FRAME_SAVED_REGS).regs [FP0_REGNUM + ii] = frame_addr - ((32 - ii) * 8); \     frame_addr -= (32 - fdata.saved_fpr) * 8;				\   }									\ 									\
comment|/* if != -1, fdata.saved_gpr is the smallest number of saved_gpr. All gpr's \      from saved_gpr to gpr31 are saved right under saved fprs, starting	\      from r31 first. */
value|\ 									\   if (fdata.saved_gpr>= 0)						\     for (ii=31; ii>= fdata.saved_gpr; --ii)				\       (FRAME_SAVED_REGS).regs [ii] = frame_addr - ((32 - ii) * 4);	\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Things needed for making the inferior call functions.  */
end_comment

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc.  */
end_comment

begin_comment
comment|/* Change these names into rs6k_{push, pop}_frame(). FIXMEmgo. */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
value|push_dummy_frame ()
end_define

begin_comment
comment|/* Discard from the stack the innermost frame,     restoring all saved registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
value|pop_frame ()
end_define

begin_comment
comment|/* This sequence of words is the instructions:  	mflr	r0		// 0x7c0802a6 				// save fpr's 	stfd	r?, num(r1)	// 0xd8010000 there should be 32 of this?? 				// save gpr's 	stm	r0, num(r1)	// 0xbc010000 	stu	r1, num(r1)	// 0x94210000  	// the function we want to branch might be in a different load  	// segment. reset the toc register. Note that the actual toc address 	// will be fix by fix_call_dummy () along with function address.  	st	r2, 0x14(r1)	// 0x90410014 save toc register 	liu	r2, 0x1234	// 0x3c401234 reset a new toc value 0x12345678 	oril	r2, r2,0x5678   // 0x60425678	  				// load absolute address 0x12345678 to r0 	liu	r0, 0x1234	// 0x3c001234 	oril	r0, r0,0x5678	// 0x60005678 	mtctr	r0		// 0x7c0903a6 ctr<- r0 	bctrl			// 0x4e800421 jump subroutine 0x12345678 (%ctr) 	cror	0xf, 0xf, 0xf	// 0x4def7b82 	brpt			// 0x7d821008, breakpoint 	cror	0xf, 0xf, 0xf	// 0x4def7b82 (for 8 byte alignment)     We actually start executing by saving the toc register first, since the pushing    of the registers is done by PUSH_DUMMY_FRAME.  If this were real code,   the arguments for the function called by the `bctrl' would be pushed   between the `stu' and the `bctrl', and we could allow it to execute through.   But the arguments have to be pushed by GDB after the PUSH_DUMMY_FRAME is done,   and we cannot allow to push the registers again. */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{0x7c0802a6, 0xd8010000, 0xbc010000, 0x94210000, \ 		    0x90410014, 0x3c401234, 0x60425678,		    \ 		    0x3c001234, 0x60005678, 0x7c0903a6, 0x4e800421, \ 		    0x4def7b82, 0x7d821008, 0x4def7b82 }
end_define

begin_comment
comment|/* keep this as multiple of 8 (%sp requires 8 byte alignment) */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|56
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|16
end_define

begin_comment
comment|/* Insert the specified number of args and function address    into a call sequence of the above form stored at DUMMYNAME.  */
end_comment

begin_define
define|#
directive|define
name|FIX_CALL_DUMMY
parameter_list|(
name|dummyname
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
name|using_gcc
parameter_list|)
define|\
value|fix_call_dummy(dummyname, pc, fun, nargs, type)
end_define

begin_comment
comment|/* Signal handler for SIGWINCH `window size changed'. */
end_comment

begin_define
define|#
directive|define
name|SIGWINCH_HANDLER
value|aix_resizewindow
end_define

begin_function_decl
specifier|extern
name|void
name|aix_resizewindow
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* `lines_per_page' and `chars_per_line' are local to utils.c. Rectify this. */
end_comment

begin_define
define|#
directive|define
name|SIGWINCH_HANDLER_BODY
define|\ 									\
comment|/* Respond to SIGWINCH `window size changed' signal, and reset GDB's	\    window settings approproatelt. */
define|\ 									\
value|void 						\ aix_resizewindow ()				\ {						\   int fd = fileno (stdout);			\   if (isatty (fd)) {				\     int val;					\ 						\     val = atoi (termdef (fd, 'l'));		\     if (val> 0)				\       lines_per_page = val;			\     val = atoi (termdef (fd, 'c'));		\     if (val> 0)				\       chars_per_line = val;			\   }						\ }
end_define

begin_comment
comment|/* Flag for machine-specific stuff in shared files.  FIXME */
end_comment

begin_define
define|#
directive|define
name|IBM6000_TARGET
end_define

begin_comment
comment|/* RS6000/AIX does not support PT_STEP.  Has to be simulated.  */
end_comment

begin_define
define|#
directive|define
name|NO_SINGLE_STEP
end_define

end_unit

