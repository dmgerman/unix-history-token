begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a mips box under 4.3bsd.    Copyright (C) 1986, 1987, 1989, 1991, 1992 Free Software Foundation, Inc.    Contributed by Per Bothner (bothner@cs.wisc.edu) at U.Wisconsin    and by Alessandro Forin (af@cs.cmu.edu) at CMU.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"coff/sym.h"
end_include

begin_comment
comment|/* Needed for PDR below.  */
end_comment

begin_include
include|#
directive|include
file|"coff/symconst.h"
end_include

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
value|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FIXME, this triggers host-and-target (``native'') dependent code    which currently sits in mips-xdep.c.  Needs to be moved out to    mips-nat.c or some such.  */
end_comment

begin_define
define|#
directive|define
name|GDB_TARGET_IS_MIPS
end_define

begin_comment
comment|/* Floating point is IEEE compliant */
end_comment

begin_define
define|#
directive|define
name|IEEE_FLOAT
end_define

begin_comment
comment|/* Define this if the C compiler puts an underscore at the front    of external names before giving them to the linker.  */
end_comment

begin_comment
comment|/*#define NAMES_HAVE_UNDERSCORE*/
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

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|pc
parameter_list|)
value|pc = mips_skip_prologue(pc)
end_define

begin_comment
comment|/* Immediately after a function call, return the saved pc.    Can't always go through the frames for this because on some machines    the new frame is not set up until the new function executes    some instructions.  */
end_comment

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
value|read_register(RA_REGNUM)
end_define

begin_comment
comment|/* Are we currently handling a signal */
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
value|in_sigtramp(pc, name)
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0x7ffff000)
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

begin_define
define|#
directive|define
name|BIG_ENDIAN
value|4321
end_define

begin_if
if|#
directive|if
name|TARGET_BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0, 0x5, 0, 0xd}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0xd, 0, 0x5, 0}
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Nonzero if instruction at PC is a return instruction. "j ra" on mips. */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
value|(read_memory_integer (pc, 4) == 0x3e00008)
end_define

begin_comment
comment|/* Return 1 if P points to an invalid floating point value. */
end_comment

begin_define
define|#
directive|define
name|INVALID_FLOAT
parameter_list|(
name|p
parameter_list|,
name|l
parameter_list|)
value|isa_NAN(p,l)
end_define

begin_comment
comment|/* Say how long (all) registers are.  */
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
value|80
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{	"zero",	"at",	"v0",	"v1",	"a0",	"a1",	"a2",	"a3", \ 	"t0",	"t1",	"t2",	"t3",	"t4",	"t5",	"t6",	"t7", \ 	"s0",	"s1",	"s2",	"s3",	"s4",	"s5",	"s6",	"s7", \ 	"t8",	"t9",	"k0",	"k1",	"gp",	"sp",	"s8",	"ra", \ 	"sr",	"lo",	"hi",	"bad",	"cause","pc",    \ 	"f0",   "f1",   "f2",   "f3",   "f4",   "f5",   "f6",   "f7", \ 	"f8",   "f9",   "f10",  "f11",  "f12",  "f13",  "f14",  "f15", \ 	"f16",  "f17",  "f18",  "f19",  "f20",  "f21",  "f22",  "f23",\ 	"f24",  "f25",  "f26",  "f27",  "f28",  "f29",  "f30",  "f31",\ 	"fsr",  "fir",  "fp",   "inx",  "rand", "tlblo","ctxt", "tlbhi",\ 	"epc",  "prid"\     }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|ZERO_REGNUM
value|0
end_define

begin_comment
comment|/* read-only register, always 0 */
end_comment

begin_define
define|#
directive|define
name|A0_REGNUM
value|4
end_define

begin_comment
comment|/* Loc of first arg during a subr call */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|29
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|RA_REGNUM
value|31
end_define

begin_comment
comment|/* Contains return address value */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|32
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|HI_REGNUM
value|34
end_define

begin_comment
comment|/* Multiple/divide temp */
end_comment

begin_define
define|#
directive|define
name|LO_REGNUM
value|33
end_define

begin_comment
comment|/* ... */
end_comment

begin_define
define|#
directive|define
name|BADVADDR_REGNUM
value|35
end_define

begin_comment
comment|/* bad vaddr for addressing exception */
end_comment

begin_define
define|#
directive|define
name|CAUSE_REGNUM
value|36
end_define

begin_comment
comment|/* describes last exception */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|37
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|38
end_define

begin_comment
comment|/* Floating point register 0 (single float) */
end_comment

begin_define
define|#
directive|define
name|FCRCS_REGNUM
value|70
end_define

begin_comment
comment|/* FP control/status */
end_comment

begin_define
define|#
directive|define
name|FCRIR_REGNUM
value|71
end_define

begin_comment
comment|/* FP implementation/revision */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|72
end_define

begin_comment
comment|/* Pseudo register that contains true address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|FIRST_EMBED_REGNUM
value|73
end_define

begin_comment
comment|/* First supervisor register for embedded use */
end_comment

begin_define
define|#
directive|define
name|LAST_EMBED_REGNUM
value|79
end_define

begin_comment
comment|/* Last one */
end_comment

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
value|mips_do_registers_info(_regnum, fp)
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(NUM_REGS*4)
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
value|((N) * 4)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On mips, all regs are 4 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|4
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N.  On mips, all regs are 4 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|4
end_define

begin_comment
comment|/* Largest value REGISTER_RAW_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|4
end_define

begin_comment
comment|/* Largest value REGISTER_VIRTUAL_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|4
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
value|bcopy ((FROM), (TO), 4);
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
value|bcopy ((FROM), (TO), 4);
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
value|(((N)>= FP0_REGNUM&& (N)< FP0_REGNUM+32)  \ 	 ? builtin_type_float : builtin_type_int)
end_define

begin_comment
unit|\
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function. */
end_comment

begin_define
define|#
directive|define
name|STORE_STRUCT_RETURN
parameter_list|(
name|addr
parameter_list|,
name|sp
parameter_list|)
define|\
value|{ sp = push_word(sp, addr);}
end_define

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    a function return value of type TYPE, and copy that, in virtual format,    into VALBUF.  XXX floats */
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
value|bcopy (REGBUF+REGISTER_BYTE (TYPE_CODE (TYPE) == TYPE_CODE_FLT ? FP0_REGNUM : 2), VALBUF, TYPE_LENGTH (TYPE))
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
value|write_register_bytes (REGISTER_BYTE (TYPE_CODE (TYPE) == TYPE_CODE_FLT ? FP0_REGNUM : 2), VALBUF, TYPE_LENGTH (TYPE))
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
value|(*(int *)(REGBUF+16))
end_define

begin_comment
comment|/* Structures are returned by ref in extra arg0 */
end_comment

begin_define
define|#
directive|define
name|USE_STRUCT_CONVENTION
parameter_list|(
name|gcc_p
parameter_list|,
name|type
parameter_list|)
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer. */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
value|(FRAME_ADDR)mips_frame_chain(thisframe)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNELDEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|kernel_debugging
decl_stmt|;
end_decl_stmt

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
value|((chain) != 0					\&& (kernel_debugging ? inside_kernstack(thisframe->frame) : \        !inside_entry_file (FRAME_SAVED_PC (thisframe))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define other aspects of the stack frame.  */
end_comment

begin_comment
comment|/* A macro that tells us whether the function invocation represented    by FI does not have a frame on the stack associated with it.  If it    does not, FRAMELESS is set to 1, else 0.  */
end_comment

begin_comment
comment|/* We handle this differently for mips, and maybe we should not */
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
value|{(FRAMELESS) = 0;}
end_define

begin_comment
comment|/* Saved Pc.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
value|(mips_frame_saved_pc(FRAME))
end_define

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|(fi)->frame
end_define

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|(fi)->frame
end_define

begin_comment
comment|/* Return number of args passed to a frame.    Can return -1, meaning no way to tell.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS
parameter_list|(
name|num
parameter_list|,
name|fi
parameter_list|)
value|(num = mips_frame_num_args(fi))
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

begin_define
define|#
directive|define
name|FRAME_FIND_SAVED_REGS
parameter_list|(
name|frame_info
parameter_list|,
name|frame_saved_regs
parameter_list|)
value|( \   (frame_saved_regs) = *(frame_info)->saved_regs, \   (frame_saved_regs).regs[SP_REGNUM] = (frame_info)->frame)
end_define

begin_escape
end_escape

begin_comment
comment|/* Things needed for making the inferior call functions.  */
end_comment

begin_comment
comment|/* Stack has strict alignment. However, use PUSH_ARGUMENTS    to take care of it. */
end_comment

begin_comment
comment|/*#define STACK_ALIGN(addr)	(((addr)+3)&~3)*/
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
value|sp = mips_push_arguments(nargs, args, sp, struct_return, struct_addr)
end_define

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
value|mips_push_dummy_frame()
end_define

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
value|mips_pop_frame()
end_define

begin_comment
comment|/*  * MIPS has no single step -- the OS might have support to emulate it,  * but that doesn't help for kernel debugging.  */
end_comment

begin_define
define|#
directive|define
name|NO_SINGLE_STEP
value|1
end_define

begin_function_decl
specifier|extern
name|void
name|single_step
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MK_OP
parameter_list|(
name|op
parameter_list|,
name|rs
parameter_list|,
name|rt
parameter_list|,
name|offset
parameter_list|)
value|(((op)<<26)|((rs)<<21)|((rt)<<16)|(offset))
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_SIZE
value|(16*4)
end_define

begin_define
define|#
directive|define
name|Dest_Reg
value|2
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{\  MK_OP(0,RA_REGNUM,0,8),
comment|/* jr $ra # Fake ABOUT_TO_RETURN ...*/
value|\  0,
comment|/* nop 	  #  ... to stop raw backtrace*/
value|\  0x27bd0000,
comment|/* addu	sp,?0 # Pseudo prologue */
value|\
comment|/* Start here: */
value|\  MK_OP(061,SP_REGNUM,12,0),
comment|/* lwc1 $f12,0(sp) # Reload first 4 args*/
value|\  MK_OP(061,SP_REGNUM,13,4),
comment|/* lwc1 $f13,4(sp) */
value|\  MK_OP(061,SP_REGNUM,14,8),
comment|/* lwc1 $f14,8(sp) */
value|\  MK_OP(061,SP_REGNUM,15,12),
comment|/* lwc1 $f15,12(sp) */
value|\  MK_OP(043,SP_REGNUM,4,0),
comment|/* lw $r4,0(sp) # Re-load FP regs*/
value|\  MK_OP(043,SP_REGNUM,5,4),
comment|/* lw $r5,4(sp) */
value|\  MK_OP(043,SP_REGNUM,6,8),
comment|/* lw $r6,8(sp) */
value|\  MK_OP(043,SP_REGNUM,7,12),
comment|/* lw $r7,12(sp) */
value|\  (017<<26)| (Dest_Reg<< 16),
comment|/* lui $r31,<target upper 16 bits>*/
value|\  MK_OP(13,Dest_Reg,Dest_Reg,0),
comment|/* ori $r31,$r31,<lower 16 bits>*/
value|\  (Dest_Reg<<21) | (31<<11) | 9,
comment|/* jalr $r31 */
value|\  MK_OP(043,SP_REGNUM,7,12),
comment|/* lw $r7,12(sp) */
value|\  0x5000d,
comment|/* bpt */
value|\ }
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|12
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
name|start_sp
parameter_list|,
name|fun
parameter_list|,
name|nargs
parameter_list|,
name|args
parameter_list|,
name|rettype
parameter_list|,
name|gcc_p
parameter_list|)
define|\
value|(((int*)dummyname)[11] |= (((unsigned long)(fun))>> 16), \    ((int*)dummyname)[12] |= (unsigned short)(fun))
end_define

begin_comment
comment|/* There's a mess in stack frame creation.  See comments in blockframe.c    near reference to INIT_FRAME_PC_FIRST.  */
end_comment

begin_define
define|#
directive|define
name|INIT_FRAME_PC
parameter_list|(
name|fromleaf
parameter_list|,
name|prev
parameter_list|)
end_define

begin_comment
comment|/* nada */
end_comment

begin_define
define|#
directive|define
name|INIT_FRAME_PC_FIRST
parameter_list|(
name|fromleaf
parameter_list|,
name|prev
parameter_list|)
define|\
value|(prev)->pc = ((fromleaf) ? SAVED_PC_AFTER_CALL ((prev)->next) : \ 	      (prev)->next ? FRAME_SAVED_PC ((prev)->next) : read_pc ());
end_define

begin_comment
comment|/* Special symbol found in blocks associated with routines.  We can hang    mips_extra_func_info_t's off of this.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_EFI_SYMBOL_NAME
value|"__GDB_EFI_INFO__"
end_define

begin_comment
comment|/* Specific information about a procedure.    This overlays the MIPS's PDR records,     mipsread.c (ab)uses this to save memory */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|mips_extra_func_info
block|{
name|long
name|numargs
decl_stmt|;
comment|/* number of args to procedure (was iopt) */
name|PDR
name|pdr
decl_stmt|;
comment|/* Procedure descriptor record */
block|}
typedef|*
name|mips_extra_func_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EXTRA_FRAME_INFO
define|\
value|mips_extra_func_info_t proc_desc; \   int num_args;\   struct frame_saved_regs *saved_regs;
end_define

begin_define
define|#
directive|define
name|INIT_EXTRA_FRAME_INFO
parameter_list|(
name|fromleaf
parameter_list|,
name|fci
parameter_list|)
value|init_extra_frame_info(fci)
end_define

begin_define
define|#
directive|define
name|PRINT_EXTRA_FRAME_INFO
parameter_list|(
name|fi
parameter_list|)
define|\
value|{ \     if (fi&& fi->proc_desc&& fi->proc_desc->pdr.framereg< NUM_REGS) \       printf_filtered (" frame pointer is at %s+%d\n", \                        reg_names[fi->proc_desc->pdr.framereg], \                                  fi->proc_desc->pdr.frameoffset); \   }
end_define

begin_comment
comment|/* It takes two values to specify a frame (at least!) on the MIPS.  Sigh.     In fact, at the moment, the *PC* is the primary value that sets up    a frame.  The PC is looked up to see what function it's in; symbol    information from that function tells us which register is the frame    pointer base, and what offset from there is the "virtual frame pointer".    (This is usually an offset from SP.)  FIXME -- this should be cleaned    up so that the primary value is the SP, and the PC is used to disambiguate    multiple functions with the same SP that are at different stack levels. */
end_comment

begin_define
define|#
directive|define
name|FRAME_SPECIFICATION_DYADIC
end_define

begin_define
define|#
directive|define
name|STAB_REG_TO_REGNUM
parameter_list|(
name|num
parameter_list|)
value|((num)< 32 ? (num) : (num)+FP0_REGNUM-32)
end_define

end_unit

