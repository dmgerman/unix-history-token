begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for execution on a Hewlett-Packard PA-RISC machine.    Copyright 1986, 1987, 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Contributed by the Center for Software Science at the    University of Utah (pa-gdb-bugs@cs.utah.edu).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Target system byte order. */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* Get at various relevent fields of an instruction word. */
end_comment

begin_define
define|#
directive|define
name|MASK_5
value|0x1f
end_define

begin_define
define|#
directive|define
name|MASK_11
value|0x7ff
end_define

begin_define
define|#
directive|define
name|MASK_14
value|0x3fff
end_define

begin_define
define|#
directive|define
name|MASK_21
value|0x1fffff
end_define

begin_comment
comment|/* This macro gets bit fields using HP's numbering (MSB = 0) */
end_comment

begin_define
define|#
directive|define
name|GET_FIELD
parameter_list|(
name|X
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|((X)>> 31 - (TO)& (1<< ((TO) - (FROM) + 1)) - 1)
end_define

begin_comment
comment|/* Watch out for NaNs */
end_comment

begin_define
define|#
directive|define
name|IEEE_FLOAT
end_define

begin_comment
comment|/* Groan */
end_comment

begin_define
define|#
directive|define
name|ARGS_GROW_DOWN
end_define

begin_comment
comment|/* Define this if the C compiler puts an underscore at the front    of external names before giving them to the linker.  */
end_comment

begin_comment
comment|/* #define NAMES_HAVE_UNDERSCORE */
end_comment

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

begin_comment
comment|/* skip (stw rp, -20(0,sp)); copy 4,1; copy sp, 4; stwm 1,framesize(sp)     for gcc, or (stw rp, -20(0,sp); stwm 1, framesize(sp) for hcc */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|pc
parameter_list|)
define|\
value|{ if (read_memory_integer ((pc), 4) == 0x6BC23FD9)			\     { if (read_memory_integer ((pc) + 4, 4) == 0x8040241)		\ 	(pc) += 16;							\       else if ((read_memory_integer (pc + 4, 4)& ~MASK_14) == 0x68810000) \ 	(pc) += 8;}							\   else if (read_memory_integer ((pc), 4) == 0x8040241)			\     (pc) += 12;								\   else if ((read_memory_integer (pc, 4)& ~MASK_14) == 0x68810000)	\     (pc) += 4;}
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
value|(read_register (RP_REGNUM)& ~3)
end_define

begin_comment
comment|/* Address of end of stack space. Who knows.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|0x80000000
end_define

begin_comment
comment|/* Stack grows upward */
end_comment

begin_define
define|#
directive|define
name|INNER_THAN
value|>
end_define

begin_comment
comment|/* Sequence of bytes for breakpoint instruction.  */
end_comment

begin_comment
comment|/*#define BREAKPOINT {0x00, 0x00, 0x00, 0x00}*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNELDEBUG
end_ifdef

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x00, 0x00, 0xa0, 0x00}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x00, 0x01, 0x00, 0x04}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Amount PC must be decremented by after a breakpoint.    This is often the number of bytes in BREAKPOINT    but not always.     Not on the PA-RISC */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

begin_comment
comment|/* return instruction is bv r0(rp) */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
value|(read_memory_integer (pc, 4) == 0xE840C000)
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
value|100
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"flags", "r1", "rp", "r3", "r4", "r5", "r6", "r7", "r8", "r9",	\   "r10", "r11", "r12", "r13", "r14", "r15", "r16", "r17", "r18", "r19",	\   "r20", "r21", "r22", "arg3", "arg2", "arg1", "arg0", "dp", "ret0", "ret1", \   "sp", "r31", "sar", "pcoqh", "pcsqh", "pcoqt", "pcsqt", \   "eiem", "iir", "isr", "ior", "ipsw", "goto", "sr4", "sr0", "sr1", "sr2", \   "sr3", "sr5", "sr6", "sr7", "cr0", "cr8", "cr9", "ccr", "cr12", "cr13", \   "cr24", "cr25", "cr26", "mpsfu_high", "mpsfu_low", "mpsfu_ovflo", "pad", \   "fpsr", "fpe1", "fpe2", "fpe3", "fpe4", "fpe5", "fpe6", "fpe7", \   "fp4", "fp5", "fp6", "fp7", "fp8", \   "fp9", "fp10", "fp11", "fp12", "fp13", "fp14", "fp15", \   "fp16", "fp17", "fp18", "fp19", "fp20", "fp21", "fp22", "fp23", \   "fp24", "fp25", "fp26", "fp27", "fp28", "fp29", "fp30", "fp31"}
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|RP_REGNUM
value|2
end_define

begin_comment
comment|/* return pointer */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|4
end_define

begin_comment
comment|/* Contains address of executing stack */
end_comment

begin_comment
comment|/* frame */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|30
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|SAR_REGNUM
value|32
end_define

begin_comment
comment|/* shift amount register */
end_comment

begin_define
define|#
directive|define
name|IPSW_REGNUM
value|41
end_define

begin_comment
comment|/* processor status word. ? */
end_comment

begin_define
define|#
directive|define
name|PCOQ_HEAD_REGNUM
value|33
end_define

begin_comment
comment|/* instruction offset queue head */
end_comment

begin_define
define|#
directive|define
name|PCSQ_HEAD_REGNUM
value|34
end_define

begin_comment
comment|/* instruction space queue head */
end_comment

begin_define
define|#
directive|define
name|PCOQ_TAIL_REGNUM
value|35
end_define

begin_comment
comment|/* instruction offset queue tail */
end_comment

begin_define
define|#
directive|define
name|PCSQ_TAIL_REGNUM
value|36
end_define

begin_comment
comment|/* instruction space queue tail */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|64
end_define

begin_comment
comment|/* floating point reg. 0 */
end_comment

begin_define
define|#
directive|define
name|FP4_REGNUM
value|72
end_define

begin_comment
comment|/* compatibility with the rest of gdb. */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|PCOQ_HEAD_REGNUM
end_define

begin_define
define|#
directive|define
name|NPC_REGNUM
value|PCOQ_TAIL_REGNUM
end_define

begin_comment
comment|/* When fetching register values from an inferior or a core file,    clean them up using this macro.  BUF is a char pointer to    the raw value of the register in the registers[] array.  */
end_comment

begin_define
define|#
directive|define
name|CLEAN_UP_REGISTER_VALUE
parameter_list|(
name|regno
parameter_list|,
name|buf
parameter_list|)
define|\
value|do {	\     if ((regno) == PCOQ_HEAD_REGNUM || (regno) == PCOQ_TAIL_REGNUM) \       (buf)[3]&= ~0x3;	\   } while (0)
end_define

begin_comment
comment|/* Define DO_REGISTERS_INFO() to do machine-specific formatting    of register dumps. */
end_comment

begin_define
define|#
directive|define
name|DO_REGISTERS_INFO
parameter_list|(
name|_regnum
parameter_list|,
name|fp
parameter_list|)
value|pa_do_registers_info (_regnum, fp)
end_define

begin_comment
comment|/* PA specific macro to see if the current instruction is nullified. */
end_comment

begin_define
define|#
directive|define
name|INSTRUCTION_NULLIFIED
value|((int)read_register (IPSW_REGNUM)& 0x00200000)
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(32 * 4 + 11 * 4 + 8 * 4 + 12 * 4 + 4 + 32 * 8)
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
value|((N)>= FP4_REGNUM ? ((N) - FP4_REGNUM) * 8 + 288 : (N) * 4)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On the PA-RISC, all regs are 4 bytes    except the floating point regs which are 8 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|((N)< FP4_REGNUM ? 4 : 8)
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
value|REGISTER_RAW_SIZE(N)
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
comment|/* Nonzero if register N requires conversion    from raw format to virtual format.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|N
parameter_list|)
value|0
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
value|{ bcopy ((FROM), (TO), (REGNUM)< FP4_REGNUM ? 4 : 8); }
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
value|{ bcopy ((FROM), (TO), (REGNUM)< FP4_REGNUM ? 4 : 8); }
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
value|((N)< FP4_REGNUM ? builtin_type_int : builtin_type_double)
end_define

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function. */
end_comment

begin_define
define|#
directive|define
name|STORE_STRUCT_RETURN
parameter_list|(
name|ADDR
parameter_list|,
name|SP
parameter_list|)
value|{write_register (28, (ADDR)); }
end_define

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    a function return value of type TYPE, and copy that, in virtual format,    into VALBUF.  */
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
value|bcopy ((REGBUF) + REGISTER_BYTE(TYPE_LENGTH(TYPE)> 4 ? \         FP4_REGNUM :28), VALBUF, TYPE_LENGTH (TYPE))
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
value|write_register_bytes (TYPE_LENGTH(TYPE)> 4 ? FP4_REGNUM :28,		\ 			VALBUF, TYPE_LENGTH (TYPE))
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
value|(*(int *)((REGBUF) + 28))
end_define

begin_comment
comment|/* This is a piece of magic that is given a register number REGNO    and as BLOCKEND the address in the system of the end of the user structure    and stores in ADDR the address in the kernel or core dump    of that register.  */
end_comment

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer.     FRAME_CHAIN_COMBINE takes the chain pointer and the frame's nominal address    and produces the nominal address of the caller frame.     However, if FRAME_CHAIN_VALID returns zero,    it means the given frame is the outermost one and has no caller.    In that case, FRAME_CHAIN_COMBINE is not used.  */
end_comment

begin_comment
comment|/* In the case of the PA-RISC, the frame's nominal address    is the address of a 4-byte word containing the calling frame's    address (previous FP).  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(inside_entry_file ((thisframe)->pc) ? \    read_memory_integer ((thisframe)->frame, 4) :\    0)
end_define

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
define|\
value|frame_chain_valid (chain, thisframe)
end_define

begin_define
define|#
directive|define
name|FRAME_CHAIN_COMBINE
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
value|(chain)
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
value|(FRAMELESS) = frameless_look_for_prologue(FI)
end_define

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
value|frame_saved_pc (FRAME)
end_define

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|((fi)->frame)
end_define

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|((fi)->frame)
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
value|0
end_define

begin_comment
comment|/* Put here the code to store, into a struct frame_saved_regs,    the addresses of the saved registers of frame described by FRAME_INFO.    This includes special registers such as pc and fp saved in special    ways in the stack frame.  sp is even more special:    the address we return for it IS the sp for the next frame.  */
end_comment

begin_comment
comment|/* Deal with dummy functions later. */
end_comment

begin_define
define|#
directive|define
name|STW_P
parameter_list|(
name|INSN
parameter_list|)
value|(((INSN)& 0xfc000000) == 0x68000000)
end_define

begin_define
define|#
directive|define
name|ADDIL_P
parameter_list|(
name|INSN
parameter_list|)
value|(((INSN)& 0xfc000000) == 0x28000000)
end_define

begin_define
define|#
directive|define
name|LDO_P
parameter_list|(
name|INSN
parameter_list|)
value|(((INSN)& 0xfc00c000) == 0x34000000)
end_define

begin_define
define|#
directive|define
name|FRAME_FIND_SAVED_REGS
parameter_list|(
name|frame_info
parameter_list|,
name|frame_saved_regs
parameter_list|)
define|\
value|{ register int regnum;							\   register CORE_ADDR next_addr;						\   register CORE_ADDR pc;						\   unsigned this_insn;							\   unsigned address;							\ 									\   bzero (&frame_saved_regs, sizeof frame_saved_regs);			\   if ((frame_info)->pc<= ((frame_info)->frame - CALL_DUMMY_LENGTH -	\ 			   FP_REGNUM * 4 - 16 * 8)			\&& (frame_info)->pc> (frame_info)->frame)			\     find_dummy_frame_regs ((frame_info),&(frame_saved_regs));		\   else									\     { pc = get_pc_function_start ((frame_info)->pc);			\       if (read_memory_integer (pc, 4) == 0x6BC23FD9)			\ 	{ (frame_saved_regs).regs[RP_REGNUM] = (frame_info)->frame - 20;\ 	  pc = pc + 4;							\ 	}								\       if (read_memory_integer (pc, 4) != 0x8040241) goto lose;		\       pc += 8;
comment|/* skip "copy 4,1; copy 30, 4" */
value|\
comment|/* skip either "stw 1,0(4);addil L'fsize,30;ldo R'fsize(1),30"	\ 	 or "stwm 1,fsize(30)" */
value|\       if ((read_memory_integer (pc, 4)& ~MASK_14) == 0x68810000)	\ 	pc += 12;							\       else								\ 	pc += 4;							\       while (1)								\ 	{ this_insn = read_memory_integer(pc, 4);			\ 	  if (STW_P (this_insn))
comment|/* stw */
value|\ 	    { regnum = GET_FIELD (this_insn, 11, 15);			\ 	      if (!regnum) goto lose;					\ 	      (frame_saved_regs).regs[regnum] = (frame_info)->frame +	\ 		extract_14 (this_insn);					\ 	      pc += 4;							\ 	    }								\ 	  else if (ADDIL_P (this_insn))
comment|/* addil */
value|\ 	    { int next_insn;						\ 	      next_insn = read_memory_integer(pc + 4, 4);		\ 	      if (STW_P (next_insn))
comment|/* stw */
value|\ 		{ regnum = GET_FIELD (this_insn, 6, 10);		\ 		  if (!regnum) goto lose;				\ 		  (frame_saved_regs).regs[regnum] = (frame_info)->frame +\ 		    (extract_21 (this_insn)<< 11) + extract_14 (next_insn);\ 		  pc += 8;						\ 		}							\ 	      else							\ 		break;							\ 	    }								\ 	  else								\ 	    { pc += 4;							\ 	      break;							\ 	    }								\ 	}								\       this_insn = read_memory_integer (pc, 4);				\       if (LDO_P (this_insn))						\ 	{ next_addr = (frame_info)->frame + extract_14 (this_insn);	\ 	  pc += 4;							\ 	}								\       else if (ADDIL_P (this_insn))					\ 	{ next_addr = (frame_info)->frame + (extract_21 (this_insn)<< 11)\ 	    + extract_14 (read_memory_integer (pc + 4, 4));		\ 	    pc += 8;							\ 	  }								\       while (1)								\ 	{ this_insn = read_memory_integer (pc, 4);			\ 	  if ((this_insn& 0xfc001fe0) == 0x2c001220)
comment|/* fstds,ma */
value|\ 	    { regnum = GET_FIELD (this_insn, 27, 31);			\ 	      (frame_saved_regs).regs[regnum + FP0_REGNUM] = next_addr;	\ 	      next_addr += 8;						\ 	    }								\ 	  else								\ 	    break;							\ 	}								\     lose:								\       (frame_saved_regs).regs[FP_REGNUM] = (frame_info)->frame;		\       (frame_saved_regs).regs[SP_REGNUM] = (frame_info)->frame -4;	\     }}
end_define

begin_escape
end_escape

begin_comment
comment|/* Things needed for making the inferior call functions.  */
end_comment

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc. */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
define|\
value|{ register CORE_ADDR sp = read_register (SP_REGNUM);			\   register int regnum;							\   int int_buffer;							\   double freg_buffer;							\
comment|/* Space for "arguments"; the RP goes in here. */
value|\   sp += 48;								\   int_buffer = read_register (RP_REGNUM) | 0x3;				\   write_memory (sp - 20,&int_buffer, 4);				\   int_buffer = read_register (FP_REGNUM);				\   write_memory (sp,&int_buffer, 4);					\   write_register (FP_REGNUM, sp);					\   sp += 4;								\   for (regnum = 1; regnum< 31; regnum++)				\     if (regnum != RP_REGNUM&& regnum != FP_REGNUM)			\       sp = push_word (sp, read_register (regnum));			\   for (regnum = FP0_REGNUM; regnum< NUM_REGS; regnum++)		\     { read_register_bytes (REGISTER_BYTE (regnum),&freg_buffer, 8);	\       sp = push_bytes (sp,&freg_buffer, 8);}				\   sp = push_word (sp, read_register (IPSW_REGNUM));			\   sp = push_word (sp, read_register (SAR_REGNUM));			\   sp = push_word (sp, read_register (PCOQ_TAIL_REGNUM));		\   sp = push_word (sp, read_register (PCSQ_TAIL_REGNUM));		\   write_register (SP_REGNUM, sp);}
end_define

begin_comment
comment|/* Discard from the stack the innermost frame,     restoring all saved registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{ register FRAME frame = get_current_frame ();				\   register CORE_ADDR fp;						\   register int regnum;						 	\   struct frame_saved_regs fsr;					 	\   struct frame_info *fi;					 	\   double freg_buffer;						 	\   fi = get_frame_info (frame);					 	\   fp = fi->frame;						 	\   get_frame_saved_regs (fi,&fsr);				 	\   for (regnum = 31; regnum> 0; regnum--)			 	\     if (fsr.regs[regnum])					 	\       write_register (regnum, read_memory_integer (fsr.regs[regnum], 4)); \   for (regnum = NUM_REGS - 1; regnum>= FP0_REGNUM ; regnum--) 	 	\     if (fsr.regs[regnum])					 	\       { read_memory (fsr.regs[regnum],&freg_buffer, 8);	 	\         write_register_bytes (REGISTER_BYTE (regnum),&freg_buffer, 8); }\   if (fsr.regs[IPSW_REGNUM])					 	\     write_register (IPSW_REGNUM,				 	\ 		    read_memory_integer (fsr.regs[IPSW_REGNUM], 4)); 	\   if (fsr.regs[SAR_REGNUM])					 	\     write_register (SAR_REGNUM,						\ 		    read_memory_integer (fsr.regs[SAR_REGNUM], 4));	\   if (fsr.regs[PCOQ_TAIL_REGNUM])					\     write_register (PCOQ_TAIL_REGNUM,					\ 		    read_memory_integer (fsr.regs[PCOQ_TAIL_REGNUM], 4));\   if (fsr.regs[PCSQ_TAIL_REGNUM])					\     write_register (PCSQ_TAIL_REGNUM,					\ 		    read_memory_integer (fsr.regs[PCSQ_TAIL_REGNUM], 4));\   write_register (FP_REGNUM, read_memory_integer (fp, 4));	 \   write_register (SP_REGNUM, fp + 8);				 \   flush_cached_frames ();					 \   set_current_frame (create_new_frame (read_register (FP_REGNUM),\ 					read_pc ())); }
end_define

begin_comment
comment|/* This sequence of words is the instructions  ; Call stack frame has already been built by gdb. Since we could be calling  ; a varargs function, and we do not have the benefit of a stub to put things in ; the right place, we load the first 4 word of arguments into both the general ; and fp registers. call_dummy 	ldw -36(sp), arg0 	ldw -40(sp), arg1 	ldw -44(sp), arg2 	ldw -48(sp), arg3 	ldo -36(sp), r1 	fldws 0(0, r1), fr4 	fldds -4(0, r1), fr5 	fldws -8(0, r1), fr6 	fldds -12(0, r1), fr7 	ldil 0, r22			; target will be placed here. 	ldo 0(r22), r22 	ldsid (0,r22), r3 	ldil 0, r1			; _sr4export will be placed here. 	ldo 0(r1), r1 	ldsid (0,r1), r4 	combt,=,n r3, r4, text_space	; If target is in data space, do a 	ble 0(sr5, r22)			; "normal" procedure call 	copy r31, r2 	break 4, 8  text_space				; Otherwise, go through _sr4export, 	ble (sr4, r1)			; which will return back here. 	stw 31,-24(r30) 	break 4, 8     The dummy decides if the target is in text space or data space. If    it's in data space, there's no problem because the target can    return back to the dummy. However, if the target is in text space,    the dummy calls the secret, undocumented routine _sr4export, which    calls a function in text space and can return to any space. Instead    of including fake instructions to represent saved registers, we    know that the frame is associated with the call dummy and treat it    specially. */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{ 0x4bda3fb9, 0x4bd93fb1, 0x4bd83fa9, 0x4bd73fa1,	\ 		     0x37c13fb9, 0x24201004, 0x2c391005, 0x24311006,	\ 		     0x2c291007, 0x22c00000, 0x36d60000, 0x02c010a3,	\ 		     0x20200000, 0x34210000, 0x002010a4, 0x80832012,	\ 		     0xe6c06000, 0x081f0242, 0x00010004, 0xe4202000,	\ 		     0x6bdf3fd1, 0x00010004}
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|88
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|0
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
name|gcc_p
parameter_list|)
define|\
value|{ static CORE_ADDR sr4export_address = 0;				\   									\   if (!sr4export_address)						\     {									\       struct minimal_symbol *msymbol;                                   \       msymbol = lookup_minimal_symbol ("_sr4export", (struct objfile *) NULL);\       if (msymbol = NULL)                                               \ 	error ("Can't find an address for _sr4export trampoline");	\       else								\ 	sr4export_address = msymbol -> address;                 	\     }									\   dummyname[9] = deposit_21 (fun>> 11, dummyname[9]);			\   dummyname[10] = deposit_14 (fun& MASK_11, dummyname[10]);		\   dummyname[12] = deposit_21 (sr4export_address>> 11, dummyname[12]);	\   dummyname[13] = deposit_14 (sr4export_address& MASK_11, dummyname[13]);\ }
end_define

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
value|sp = hp_push_arguments(nargs, args, sp, struct_return, struct_addr)
end_define

begin_comment
comment|/* Write the PC to a random value.    On PA-RISC, we need to be sure that the PC space queue is correct. */
end_comment

begin_define
define|#
directive|define
name|WRITE_PC
parameter_list|(
name|addr
parameter_list|)
define|\
value|{ int space_reg, space = ((addr)>> 30);		\   int space_val;					\   if (space == 0)					\     space_reg = 43;
comment|/* Space reg sr4 */
value|\   else if (space == 1)					\     space_reg = 48;
comment|/* Space reg sr5*/
value|\   else							\     error ("pc = %x is in illegal space.", addr);	\   space_val = read_register (space_reg);		\   write_register (PCOQ_HEAD_REGNUM, addr);		\   write_register (PCSQ_HEAD_REGNUM, space_val);		\   write_register (PCOQ_TAIL_REGNUM, addr);		\   write_register (PCSQ_TAIL_REGNUM, space_val);}
end_define

begin_comment
comment|/* Symbol files have two symbol tables.  Rather than do this right,    like the ELF symbol reading code, massive hackery was added    to dbxread.c and partial-stab.h.  This flag turns on that    hackery, which should all go away FIXME FIXME FIXME FIXME now.  */
end_comment

begin_define
define|#
directive|define
name|GDB_TARGET_IS_HPPA
end_define

end_unit

