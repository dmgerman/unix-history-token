begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine sub-parameters for SPARC, for GDB, the GNU debugger.    This is included by other tm-*.h files to define SPARC cpu-related info.    Copyright 1986, 1987, 1989, 1991, 1992 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@mcc.com)  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* Floating point is IEEE compatible.  */
end_comment

begin_define
define|#
directive|define
name|IEEE_FLOAT
end_define

begin_comment
comment|/* When passing a structure to a function, Sun cc passes the address    in a register, not the structure itself.  It (under SunOS4) creates    two symbols, so we get a LOC_ARG saying the address is on the stack    (a lie, and a serious one since we don't know which register to    use), and a LOC_REGISTER saying that the struct is in a register    (sort of a lie, but fixable with REG_STRUCT_HAS_ADDR).  Gcc version    two (as of 1.92) behaves like sun cc.  REG_STRUCT_HAS_ADDR is smart    enough to distinguish between Sun cc, gcc version 1 and gcc version 2.     This still doesn't work if the argument is not one passed in a    register (i.e. it's the 7th or later argument).  */
end_comment

begin_define
define|#
directive|define
name|REG_STRUCT_HAS_ADDR
parameter_list|(
name|gcc_p
parameter_list|)
value|(gcc_p != 1)
end_define

begin_define
define|#
directive|define
name|STRUCT_ARG_SYM_GARBAGE
parameter_list|(
name|gcc_p
parameter_list|)
value|(gcc_p != 1)
end_define

begin_comment
comment|/* If Pcc says that a parameter is a short, it's a short.  This is    because the parameter does get passed in in a register as an int,    but pcc puts it onto the stack frame as a short (not nailing    whatever else might be there.  I'm not sure that I consider this    swift.  Sigh.)     No, don't do this.  The problem here is that pcc says that the    argument is in the upper half of the word reserved on the stack,    but puts it in the lower half.  */
end_comment

begin_comment
comment|/* #define BELIEVE_PCC_PROMOTION 1 */
end_comment

begin_comment
comment|/* OK, I've added code to dbxread.c to deal with this case.  */
end_comment

begin_define
define|#
directive|define
name|BELIEVE_PCC_PROMOTION_TYPE
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
comment|/* Advance PC across any function entry prologue instructions    to reach some "real" code.  SKIP_PROLOGUE_FRAMELESS_P advances    the PC past some of the prologue, but stops as soon as it    knows that the function has a frame.  Its result is equal    to its input PC if the function is frameless, unequal otherwise.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|pc
parameter_list|)
define|\
value|{ pc = skip_prologue (pc, 0); }
end_define

begin_define
define|#
directive|define
name|SKIP_PROLOGUE_FRAMELESS_P
parameter_list|(
name|pc
parameter_list|)
define|\
value|{ pc = skip_prologue (pc, 1); }
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|skip_prologue
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Immediately after a function call, return the saved pc.    Can't go through the frames for this because on some machines    the new frame is not set up until the new function executes    some instructions.  */
end_comment

begin_comment
comment|/* On the Sun 4 under SunOS, the compile will leave a fake insn which    encodes the structure size being returned.  If we detect such    a fake insn, step past it.  */
end_comment

begin_define
define|#
directive|define
name|PC_ADJUST
parameter_list|(
name|pc
parameter_list|)
value|sparc_pc_adjust(pc)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc_pc_adjust
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
value|PC_ADJUST (read_register (RP_REGNUM))
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

begin_comment
comment|/* Stack has strict alignment.  */
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

begin_comment
comment|/* Sequence of bytes for breakpoint instruction.  */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x91, 0xd0, 0x20, 0x01}
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
comment|/* For SPARC, this is either a "jmpl %o7+8,%g0" or "jmpl %i7+8,%g0".     Note: this does not work for functions returning structures under SunOS.  */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
define|\
value|((read_memory_integer (pc, 4)|0x00040000) == 0x81c7e008)
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
value|72
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{ "g0", "g1", "g2", "g3", "g4", "g5", "g6", "g7",	\   "o0", "o1", "o2", "o3", "o4", "o5", "sp", "o7",	\   "l0", "l1", "l2", "l3", "l4", "l5", "l6", "l7",	\   "i0", "i1", "i2", "i3", "i4", "i5", "fp", "i7",	\ 								\   "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",	\   "f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15",	\   "f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23",	\   "f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31",	\                                                                 \   "y", "psr", "wim", "tbr", "pc", "npc", "fpsr", "cpsr" }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|G0_REGNUM
value|0
end_define

begin_comment
comment|/* %g0 */
end_comment

begin_define
define|#
directive|define
name|G1_REGNUM
value|1
end_define

begin_comment
comment|/* %g1 */
end_comment

begin_define
define|#
directive|define
name|O0_REGNUM
value|8
end_define

begin_comment
comment|/* %o0 */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|14
end_define

begin_comment
comment|/* Contains address of top of stack, \ 				   which is also the bottom of the frame.  */
end_comment

begin_define
define|#
directive|define
name|RP_REGNUM
value|15
end_define

begin_comment
comment|/* Contains return address value, *before* \ 				   any windows get switched.  */
end_comment

begin_define
define|#
directive|define
name|O7_REGNUM
value|15
end_define

begin_comment
comment|/* Last local reg not saved on stack frame */
end_comment

begin_define
define|#
directive|define
name|L0_REGNUM
value|16
end_define

begin_comment
comment|/* First local reg that's saved on stack frame 				   rather than in machine registers */
end_comment

begin_define
define|#
directive|define
name|I0_REGNUM
value|24
end_define

begin_comment
comment|/* %i0 */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|30
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|I7_REGNUM
value|31
end_define

begin_comment
comment|/* Last local reg saved on stack frame */
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
name|Y_REGNUM
value|64
end_define

begin_comment
comment|/* Temp register for multiplication, etc.  */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|65
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|WIM_REGNUM
value|66
end_define

begin_comment
comment|/* Window Invalid Mask (not really supported) */
end_comment

begin_define
define|#
directive|define
name|TBR_REGNUM
value|67
end_define

begin_comment
comment|/* Trap Base Register (not really supported) */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|68
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|NPC_REGNUM
value|69
end_define

begin_comment
comment|/* Contains next PC */
end_comment

begin_define
define|#
directive|define
name|FPS_REGNUM
value|70
end_define

begin_comment
comment|/* Floating point status register */
end_comment

begin_define
define|#
directive|define
name|CPS_REGNUM
value|71
end_define

begin_comment
comment|/* Coprocessor status register */
end_comment

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(32*4+32*4+8*4)
end_define

begin_comment
comment|/* Index within `registers' of the first byte of the space for    register N.  */
end_comment

begin_comment
comment|/* ?? */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTE
parameter_list|(
name|N
parameter_list|)
value|((N)*4)
end_define

begin_comment
comment|/* The SPARC processor has register windows.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_REGISTER_WINDOWS
end_define

begin_comment
comment|/* Is this register part of the register window system?  A yes answer    implies that 1) The name of this register will not be the same in    other frames, and 2) This register is automatically "saved" (out    registers shifting into ins counts) upon subroutine calls and thus    there is no need to search more than one stack frame for it. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_IN_WINDOW_P
parameter_list|(
name|regnum
parameter_list|)
define|\
value|((regnum)>= 8&& (regnum)< 32)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  */
end_comment

begin_comment
comment|/* On the SPARC, all regs are 4 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|(4)
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N.  */
end_comment

begin_comment
comment|/* On the SPARC, all regs are 4 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|(4)
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
value|(0)
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
value|{ memcpy ((TO), (FROM), 4); }
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
value|{ memcpy ((TO), (FROM), 4); }
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
value|((N)< 32 ? builtin_type_int : (N)< 64 ? builtin_type_float : \   builtin_type_int)
end_define

begin_comment
comment|/* Writing to %g0 is a noop (not an error or exception or anything like    that, however).  */
end_comment

begin_define
define|#
directive|define
name|CANNOT_STORE_REGISTER
parameter_list|(
name|regno
parameter_list|)
value|((regno) == G0_REGNUM)
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
define|\
value|{ target_write_memory ((SP)+(16*4), (char *)&(ADDR), 4); }
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
value|{      	       	       	       	       	       	       	           \     if (TYPE_CODE (TYPE) == TYPE_CODE_FLT)		       		   \       {							       		   \ 	memcpy ((VALBUF), ((int *)(REGBUF))+FP0_REGNUM, TYPE_LENGTH(TYPE));\       }							       		   \     else						       		   \       memcpy ((VALBUF),						   	   \ 	      (char *)(REGBUF) + 4 * 8 +				   \ 	      (TYPE_LENGTH(TYPE)>= 4 ? 0 : 4 - TYPE_LENGTH(TYPE)),	   \ 	      TYPE_LENGTH(TYPE));					   \   }
end_define

begin_comment
comment|/* Write into appropriate registers a function return value    of type TYPE, given in virtual format.  */
end_comment

begin_comment
comment|/* On sparc, values are returned in register %o0.  */
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
value|{    	       	       	       	       	       	       	       	       	     \     if (TYPE_CODE (TYPE) == TYPE_CODE_FLT)				     \
comment|/* Floating-point values are returned in the register pair */
value|\
comment|/* formed by %f0 and %f1 (doubles are, anyway).  */
value|\       write_register_bytes (REGISTER_BYTE (FP0_REGNUM), (VALBUF),	     \ 			    TYPE_LENGTH (TYPE));			     \     else								     \
comment|/* Other values are returned in register %o0.  */
value|\       write_register_bytes (REGISTER_BYTE (O0_REGNUM), (VALBUF),	     \ 			    TYPE_LENGTH (TYPE));  \   }
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
define|\
value|(sparc_extract_struct_value_address (REGBUF))
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|sparc_extract_struct_value_address
name|PARAMS
argument_list|(
operator|(
name|char
index|[
name|REGISTER_BYTES
index|]
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer. */
end_comment

begin_comment
comment|/* In the case of the Sun 4, the frame-chain's nominal address    is held in the frame pointer register.     On the Sun4, the frame (in %fp) is %sp for the previous frame.    From the previous frame's %sp, we can find the previous frame's    %fp: it is in the save area just above the previous frame's %sp.     If we are setting up an arbitrary frame, we'll need to know where    it ends.  Hence the following.  This part of the frame cache    structure should be checked before it is assumed that this frame's    bottom is in the stack pointer.     If there isn't a frame below this one, the bottom of this frame is    in the stack pointer.     If there is a frame below this one, and the frame pointers are    identical, it's a leaf frame and the bottoms are the same also.     Otherwise the bottom of this frame is the top of the next frame.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_FRAME_INFO
value|FRAME_ADDR bottom;
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
define|\
value|(fci)->bottom =					\    ((fci)->next ?					\     ((fci)->frame == (fci)->next_frame ?		\      (fci)->next->bottom : (fci)->next->frame) :	\     read_register (SP_REGNUM));
end_define

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
value|(sparc_frame_chain (thisframe))
end_define

begin_function_decl
name|CORE_ADDR
name|sparc_frame_chain
parameter_list|()
function_decl|;
end_function_decl

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

begin_comment
comment|/* Where is the PC for a specific frame */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
value|frame_saved_pc (FRAME)
end_define

begin_function_decl
name|CORE_ADDR
name|frame_saved_pc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* If the argument is on the stack, it will be here.  */
end_comment

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
name|FRAME_STRUCT_ARGS_ADDRESS
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
value|68
end_define

begin_comment
comment|/*  * The LBL version of gdb uses a modified approach for calling functions  * in the inferior.  Vanilla gdb saves the inferior's cpu on the inferior's  * stack.  This is silly since it easier to save it in the debugger.  */
end_comment

begin_define
define|#
directive|define
name|NEW_CALL_FUNCTION
end_define

begin_define
define|#
directive|define
name|FRAME_FIND_SAVED_REGS
parameter_list|(
name|fi
parameter_list|,
name|sr
parameter_list|)
define|\
value|frame_find_saved_regs(fi,&(sr))
end_define

begin_define
define|#
directive|define
name|POP_FRAME
value|sparc_pop_frame()
end_define

begin_comment
comment|/* Sparc has no reliable single step ptrace call */
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

begin_comment
comment|/* We need two arguments (in general) to the "info frame" command.    Note that the definition of this macro implies that there exists a    function "setup_arbitrary_frame" in sparc-tdep.c */
end_comment

begin_define
define|#
directive|define
name|FRAME_SPECIFICATION_DYADIC
end_define

begin_comment
comment|/* To print every pair of float registers as a double, we use this hook.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_REGISTER_HOOK
parameter_list|(
name|regno
parameter_list|)
define|\
value|if (((regno)>= FP0_REGNUM)		\&& ((regno)<  FP0_REGNUM + 32)	\&& (0 == (regno& 1))) {		\     char doublereg[8];
comment|/* two float regs */
value|\     if (!read_relative_register_raw_bytes (i  , doublereg  )	\&& !read_relative_register_raw_bytes (i+1, doublereg+4)) {	\       printf("\t");			\       print_floating (doublereg, builtin_type_double, stdout);	\     }					\   }
end_define

begin_comment
comment|/* Optimization for storing registers to the inferior.  The hook    DO_DEFERRED_STORES    actually executes any deferred stores.  It is called any time    we are going to proceed the child, or read its registers.    The hook CLEAR_DEFERRED_STORES is called when we want to throw    away the inferior process, e.g. when it dies or we kill it.    FIXME, this does not handle remote debugging cleanly.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|deferred_stores
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DO_DEFERRED_STORES
define|\
value|if (deferred_stores)		\     target_store_registers (-2);
end_define

begin_define
define|#
directive|define
name|CLEAR_DEFERRED_STORES
define|\
value|deferred_stores = 0;
end_define

begin_comment
comment|/*  * Where to find function arguments that don't have dbx symbols.  * (i.e., this allows us to see function args in a backtrace when  * no debugging symbols are present)  */
end_comment

begin_define
define|#
directive|define
name|NAMELESS_ARG
parameter_list|(
name|fi
parameter_list|,
name|n
parameter_list|,
name|v
parameter_list|)
define|\
value|target_read_memory(32 + (fi)->bottom + 4 * n, (char *)&v, 4)
end_define

end_unit

