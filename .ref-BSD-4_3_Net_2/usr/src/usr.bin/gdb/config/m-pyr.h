begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a Pyramidax under OSx 4.0 (4.2bsd).    Copyright (C) 1988, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* The FSF prefers to define "pyramid on Pyramid 90x machines; the    manufacturer insists on "pyr".  Define both. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|pyr
end_ifndef

begin_define
define|#
directive|define
name|pyr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|pyramid
end_ifndef

begin_define
define|#
directive|define
name|pyramid
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define PYRAMID_CONTROL_FRAME_DEBUGGING to get copious messages    about reading the control stack on standard output. This    makes gdb unusable as a debugger. */
end_comment

begin_comment
comment|/* #define PYRAMID_CONTROL_FRAME_DEBUGGING */
end_comment

begin_comment
comment|/* Define PYRAMID_FRAME_DEBUGGING /* use Pyramid's slightly strange ptrace */
end_comment

begin_define
define|#
directive|define
name|PYRAMID_PTRACE
end_define

begin_comment
comment|/* Traditional Unix virtual address spaces have thre regions: text,    data and stack.  The text, initialised data, and uninitialised data    are represented in separate segments of the a.out file.    When a process dumps core, the data and stack regions are written    to a core file.  This gives a debugger enough information to    reconstruct (and debug) the virtual address space at the time of    the coredump.    Pyramids have an distinct fourth region of the virtual address    space, in which the contents of the windowed registers are stacked    in fixed-size frames.  Pyramid refer to this region as the control    stack.  Each call (or trap) automatically allocates a new register    frame; each return deallocates the current frame and restores the    windowed registers to their values before the call.     When dumping core, the control stack is written to a core files as    a third segment. The core-handling functions need to know to deal    with it. */
end_comment

begin_comment
comment|/* Tell core.c there is an extra segment.  */
end_comment

begin_define
define|#
directive|define
name|REG_STACK_SEGMENT
end_define

begin_comment
comment|/* Tell dep.c what the extra segment is.  */
end_comment

begin_define
define|#
directive|define
name|PYRAMID_CORE
end_define

begin_comment
comment|/* Define the bit, byte, and word ordering of the machine.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
end_define

begin_comment
comment|/* Floating point is IEEE compatible on most Pyramid hardware    (Older processors do not have IEEE NaNs).  */
end_comment

begin_define
define|#
directive|define
name|IEEE_FLOAT
end_define

begin_define
define|#
directive|define
name|NO_SIGINTERRUPT
end_define

begin_define
define|#
directive|define
name|HAVE_WAIT_STRUCT
end_define

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible.  */
end_comment

begin_define
define|#
directive|define
name|SET_STACK_LIMIT_HUGE
end_define

begin_comment
comment|/* Define this if the C compiler puts an underscore at the front    of external names before giving them to the linker.  */
end_comment

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORE
end_define

begin_comment
comment|/* Debugger information will be in DBX format.  */
end_comment

begin_define
define|#
directive|define
name|READ_DBX_FORMAT
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

begin_comment
comment|/* FIXME -- do we want to skip insns to allocate the local frame?    If so, what do they look like?    This is becoming harder, since tege@sics.SE wants to change    gcc to not output a prologue when no frame is needed.   */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|pc
parameter_list|)
value|do {} while (0)
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
value|FRAME_SAVED_PC(frame)
end_define

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|(0x80000000 - (UPAGES * NBPG))
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_comment
comment|/* This seems to be right for the 90x comp.vuw.ac.nz.    The correct value at any site may be a function of the configured    maximum control stack depth.  If so, I don't know where the    control-stack depth is configured, so I can't #include it here. */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0xc00cc000)
end_define

begin_comment
comment|/* Register window stack (Control stack) stack definitions     - Address of beginning of control stack.     - size of control stack frame    (Note that since crts0 is usually the first function called,     main()'s control stack is one frame (0x80 bytes) beyond this value.  */
end_comment

begin_define
define|#
directive|define
name|CONTROL_STACK_ADDR
value|(0xc00cd000)
end_define

begin_comment
comment|/* Bytes in a register window -- 16 parameter regs, 16 local regs    for each call, is 32 regs * 4 bytes */
end_comment

begin_define
define|#
directive|define
name|CONTROL_STACK_FRAME_SIZE
value|(32*4)
end_define

begin_comment
comment|/* FIXME.  On a pyr, Data Stack grows downward; control stack goes upwards.     Which direction should we use for INNER_THAN, PC_INNER_THAN ?? */
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
name|PC_INNER_THAN
value|>
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
value|(((ADDR)+3)&-4)
end_define

begin_comment
comment|/* Sequence of bytes for breakpoint instruction.  */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0xf0, 00, 00, 00}
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
comment|/* Nonzero if instruction at PC is a return instruction.     On a pyr, this is either "ret" or "retd".    It would be friendly to check that any "retd" always had an    argument of 0, since anything else is invalid. */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
define|\
value|(((read_memory_integer (pc, 2)& 0x3ff0) == 0x3090) || \  ((read_memory_integer (pc, 2)& 0x0ff0) == 0x00a0))
end_define

begin_comment
comment|/* Return 1 if P points to an invalid floating point value.    LEN is the length in bytes -- not relevant on the Vax.  */
end_comment

begin_comment
comment|/* FIXME -- this is ok for a vax, bad for big-endian ieee format.    I would use the definition for a Sun; but it is no better! */
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
value|((*(short *) p& 0xff80) == 0x8000)
end_define

begin_comment
comment|/* Larges integer type */
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

begin_comment
comment|/* pyramids have 64, plus one for the PSW; plus perhaps one more for the    kernel stack pointer (ksp) and control-stack pointer (CSP) */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|67
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"gr0", "gr1", "gr2", "gr3", "gr4", "gr5", "gr6", "gr7", \  "gr8", "gr9", "gr10", "gr11", "logpsw", "cfp", "sp", "pc", \  "pr0", "pr1", "pr2", "pr3", "pr4", "pr5", "pr6", "pr7", \  "pr8", "pr9", "pr10", "pr11", "pr12", "pr13", "pr14", "pr15", \  "lr0", "lr1", "lr2", "lr3", "lr4", "lr5", "lr6", "lr7", \  "lr8", "lr9", "lr10", "lr11", "lr12", "lr13", "lr14", "lr15", \  "tr0", "tr1", "tr2", "tr3", "tr4", "tr5", "tr6", "tr7", \  "tr8", "tr9", "tr10", "tr11", "tr12", "tr13", "tr14", "tr15", \   "psw", "ksp", "csp"}
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_comment
comment|/* pseudo-registers: */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|64
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|PSW_REGNUM
value|64
end_define

begin_comment
comment|/* Contains current psw, whatever it is.*/
end_comment

begin_define
define|#
directive|define
name|CSP_REGNUM
value|65
end_define

begin_comment
comment|/* address of this control stack frame*/
end_comment

begin_define
define|#
directive|define
name|KSP_REGNUM
value|66
end_define

begin_comment
comment|/* Contains process's Kernel Stack Pointer */
end_comment

begin_define
define|#
directive|define
name|CFP_REGNUM
value|13
end_define

begin_comment
comment|/* Current data-stack frame ptr */
end_comment

begin_define
define|#
directive|define
name|TR0_REGNUM
value|48
end_define

begin_comment
comment|/* After function call, contains 				   function result */
end_comment

begin_comment
comment|/* Registers interesting to the machine-independent part of gdb*/
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|CSP_REGNUM
end_define

begin_comment
comment|/* Contains address of executing (control) 				   stack frame */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|14
end_define

begin_comment
comment|/* Contains address of top of stack -??*/
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|15
end_define

begin_comment
comment|/* Contains program counter */
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
parameter_list|)
value|pyr_do_registers_info(_regnum)
end_define

begin_comment
comment|/* need this so we can find the global registers: they never get saved. */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|global_reg_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|last_frame_offset
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|reg_stack_start
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|reg_stack_end
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|reg_stack_offset
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define offsets of registers in the core file (or maybe u area) */
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
value|{ struct user __u;					\   addr = blockend  + (regno - 16 ) * 4;			\   if (regno == 67) {   					\       printf("\\geting reg 67\\");			\       addr = (int)(&__u.u_pcb.pcb_csp) - (int)&__u;	\   } else if (regno == KSP_REGNUM) {			\       printf("\\geting KSP (reg %d)\\", KSP_REGNUM);	\       addr = (int)(&__u.u_pcb.pcb_ksp) - (int)&__u;	\   } else if (regno == CSP_REGNUM) {			\       printf("\\geting CSP (reg %d\\",CSP_REGNUM);	\       addr = (int)(&__u.u_pcb.pcb_csp) - (int)&__u;	\   } else if (regno == 64) {				\       printf("\\geting reg 64\\");			\       addr = (int)(&__u.u_pcb.pcb_csp) - (int)&__u;	\    } else if (regno == PS_REGNUM)			\       addr = blockend - 4;				\   else if (1&& ((16> regno)&& (regno> 11)))		\       addr = last_frame_offset + (4 *(regno+32));	\   else if (0&& (12> regno)) 				\       addr = global_reg_offset + (4 *regno);		\   else if (16> regno)	 				\       addr = global_reg_offset + (4 *regno);		\  else							\       addr = blockend  + (regno - 16 ) * 4;		\ }
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
comment|/* the Pyramid has register windows.  */
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
value|((regnum)>= 16&& (regnum)< 64)
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
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On the Pyramid, all regs are 4 bytes.  */
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
comment|/* Number of bytes of storage in the program's representation    for register N.  On the Pyramid, all regs are 4 bytes.  */
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
value|builtin_type_int
end_define

begin_comment
comment|/* FIXME: It seems impossible for both EXTRACT_RETURN_VALUE and    STORE_RETURN_VALUE to be correct. */
end_comment

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function. */
end_comment

begin_comment
comment|/****FIXME****/
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
value|{ write_register (TR0_REGNUM, (ADDR)); }
end_define

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    a function return value of type TYPE, and copy that, in virtual format,    into VALBUF.  */
end_comment

begin_comment
comment|/* Note that on a register-windowing machine (eg, Pyr, SPARC), this is    where the value is found after the function call -- ie, it should    correspond to GNU CC's FUNCTION_VALUE rather than FUNCTION_OUTGOING_VALUE.*/
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
value|bcopy (((int *)(REGBUF))+TR0_REGNUM, VALBUF, TYPE_LENGTH (TYPE))
end_define

begin_comment
comment|/* Write into appropriate registers a function return value    of type TYPE, given in virtual format.  */
end_comment

begin_comment
comment|/* on pyrs, values are returned in */
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
value|write_register_bytes (REGISTER_BYTE(TR0_REGNUM), VALBUF, TYPE_LENGTH (TYPE))
end_define

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    the address in which a function should return its structure value,    as a CORE_ADDR (or an expression that can be used as one).  */
end_comment

begin_comment
comment|/* FIXME */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_STRUCT_VALUE_ADDRESS
parameter_list|(
name|REGBUF
parameter_list|)
define|\
value|( ((int *)(REGBUF)) [TR0_REGNUM])
end_define

begin_comment
comment|/* Compensate for lack of `vprintf' function.  */
end_comment

begin_define
define|#
directive|define
name|vprintf
parameter_list|(
name|format
parameter_list|,
name|ap
parameter_list|)
value|_doprnt (format, ap, stdout)
end_define

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_FRAME_INFO
define|\
value|FRAME_ADDR bottom;	\ 	CORE_ADDR frame_cfp;	\ 	CORE_ADDR frame_window_addr;
end_define

begin_define
define|#
directive|define
name|INIT_EXTRA_FRAME_INFO
parameter_list|(
name|fci
parameter_list|)
define|\
value|do {								\   (fci)->frame_window_addr = (fci)->frame;			\   (fci)->bottom =						\ 	  ((fci)->next ?					\ 	   ((fci)->frame == (fci)->next_frame ?			\ 	    (fci)->next->bottom : (fci)->next->frame) :		\ 	   read_register (SP_REGNUM));				\   (fci)->frame_cfp =						\ 	  read_register (CFP_REGNUM);				\
comment|/***fprintf (stderr,						\ 	   "[[creating new frame for %0x,pc=%0x,csp=%0x]]\n",	\ 	   (fci)->frame, (fci)->pc,(fci)->frame_cfp);*/
value|\ } while (0);
end_define

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer.     FRAME_CHAIN_COMBINE takes the chain pointer and the frame's nominal address    and produces the nominal address of the caller frame.     However, if FRAME_CHAIN_VALID returns zero,    it means the given frame is the outermost one and has no caller.    In that case, FRAME_CHAIN_COMBINE is not used.  */
end_comment

begin_comment
comment|/* In the case of the pyr, the frame's nominal address is the address    of parameter register 0.  The previous frame is found 32 words up.   */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|( (thisframe) -> frame - CONTROL_STACK_FRAME_SIZE)
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
value|(chain != 0&& (outside_startup_file (FRAME_SAVED_PC (thisframe))))
end_define

begin_comment
comment|/*((thisframe)>= CONTROL_STACK_ADDR))*/
end_comment

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
comment|/* A macro that tells us whether the function invocation represented    by FI does not have a frame on the stack associated with it.  If it    does not, FRAMELESS is set to 1, else 0.     I do not understand what this means on a Pyramid, where functions    *always* have a control-stack frame, but may or may not have a    frame on the data stack.  Since GBD uses the value of the    control stack pointer as its "address" of a frame, FRAMELESS    is always 1, so does not need to be defined.  */
end_comment

begin_comment
comment|/* Where is the PC for a specific frame */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|fi
parameter_list|)
define|\
value|((CORE_ADDR) (read_memory_integer ( (fi) -> frame + 60, 4)))
end_define

begin_comment
comment|/* There may be bugs in FRAME_ARGS_ADDRESS and FRAME_LOCALS_ADDRESS;    or there may be bugs in accessing the registers that break    their definitions.    Having the macros expand into functions makes them easier to debug.    When the bug is finally located, the inline macro defintions can    be un-#if 0ed, and frame_args_addr and frame_locals_address can    be deleted from pyr-dep.c */
end_comment

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
define|\
value|frame_args_addr(fi)
end_define

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
define|\
value|frame_locals_address(fi)
end_define

begin_comment
comment|/* The following definitions doesn't seem to work.    I don't understand why. */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
define|\
comment|/*(FRAME_FP(fi) + (13*4))*/
value|(read_register (CFP_REGNUM))
end_define

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
define|\
value|((fi)->frame +(16*4))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* Return number of args passed to a frame.    Can return -1, meaning no way to tell.  */
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
comment|/* Put here the code to store, into a struct frame_saved_regs,    the addresses of the saved registers of frame described by FRAME_INFO.    This includes special registers such as pc and fp saved in special    ways in the stack frame.  sp is even more special:    the address we return for it IS the sp for the next frame.     Note that on register window machines, we are currently making the    assumption that window registers are being saved somewhere in the    frame in which they are being used.  If they are stored in an    inferior frame, find_saved_register will break.     On pyrs, frames of window registers are stored contiguously on a    separate stack.  All window registers are always stored.    The pc and psw (gr15 and gr14)  are also always saved: the call    insn saves them in pr15 and pr14 of the new frame (tr15,tr14 of the    old frame).      The data-stack frame pointer (CFP) is only saved in functions which    allocate a (data)stack frame (with "adsf").  We detect them by    looking at the first insn of the procedure.      Other non-window registers (gr0-gr11) are never saved.  Pyramid's C    compiler and gcc currently ignore them, so it's not an issue.   */
end_comment

begin_define
define|#
directive|define
name|FRAME_FIND_SAVED_REGS
parameter_list|(
name|fi_p
parameter_list|,
name|frame_saved_regs
parameter_list|)
define|\
value|{  register int regnum;							\   register CORE_ADDR pc;						\   register CORE_ADDR fn_start_pc;					\   register int first_insn;						\   register CORE_ADDR prev_cf_addr;					\   register int window_ptr;						\   FRAME fid = FRAME_INFO_ID (fi_p);					\   if (!fid) fatal ("Bad frame info struct in FRAME_FIND_SAVED_REGS");	\   bzero (&(frame_saved_regs), sizeof (frame_saved_regs));		\ 									\   window_ptr = prev_cf_addr = FRAME_FP(fi_p);				\ 									\   for (regnum = 16 ; regnum< 64; regnum++,window_ptr+=4)		\   {									\     (frame_saved_regs).regs[regnum] = window_ptr;			\   }									\ 									\
comment|/* In each window, psw, and pc are "saved" in tr14,tr15. */
value|\
comment|/*** psw is sometimes saved in gr12 (so sez<sys/pcb.h>) */
value|\   (frame_saved_regs).regs[PS_REGNUM] = FRAME_FP(fi_p) + (14*4);  	\ 									\
comment|/*(frame_saved_regs).regs[PC_REGNUM] = (frame_saved_regs).regs[31];*/
value|\   (frame_saved_regs).regs[PC_REGNUM] = FRAME_FP(fi_p) + ((15+32)*4);	\ 									\
comment|/* Functions that allocate a frame save sp *where*? */
value|\
comment|/*first_insn = read_memory_integer (get_pc_function_start ((fi_p)->pc),4); */
value|\ 									\   fn_start_pc = (get_pc_function_start ((fi_p)->pc));			\   first_insn = read_memory_integer(fn_start_pc, 4);			\ 									\   if (0x08 == ((first_insn>> 20)&0x0ff)) {				\
comment|/* NB: because WINDOW_REGISTER_P(cfp) is false, a saved cfp		\        in this frame is only visible in this frame's callers.		\        That means the cfp we mark saved is my caller's cfp, ie pr13.	\        I don't understand why we don't have to do that for pc, too.  */
value|\ 									\     (frame_saved_regs).regs[CFP_REGNUM] = FRAME_FP(fi_p)+(13*4);	\ 									\     (frame_saved_regs).regs[SP_REGNUM] =				\ 	  read_memory_integer (FRAME_FP(fi_p)+((13+32)*4),4);		\   }									\ 									\
comment|/*									\  *(frame_saved_regs).regs[CFP_REGNUM] = (frame_saved_regs).regs[61];	\  * (frame_saved_regs).regs[SP_REGNUM] =					\  *	  read_memory_integer (FRAME_FP(fi_p)+((13+32)*4),4);		\  */
value|\ 									\   (frame_saved_regs).regs[CSP_REGNUM] = prev_cf_addr;			\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Things needed for making the inferior call functions.  */
end_comment

begin_comment
comment|/* These are all lies.  These macro definitions are appropriate for a     SPARC. On a pyramid, pushing a dummy frame will    surely involve writing the control stack pointer,    then saving the pc.  This requires a privileged instruction.    Maybe one day Pyramid can be persuaded to add a syscall to do this.    Until then, we are out of luck. */
end_comment

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
define|\
value|{ register CORE_ADDR sp = read_register (SP_REGNUM);\   register int regnum;				    \   sp = push_word (sp, 0);
comment|/* arglist */
value|\   for (regnum = 11; regnum>= 0; regnum--)	    \     sp = push_word (sp, read_register (regnum));    \   sp = push_word (sp, read_register (PC_REGNUM));   \   sp = push_word (sp, read_register (FP_REGNUM));   \
comment|/*  sp = push_word (sp, read_register (AP_REGNUM));*/
value|\   sp = push_word (sp, (read_register (PS_REGNUM)& 0xffef)   \ 		      + 0x2fff0000);		    \   sp = push_word (sp, 0); 			    \   write_register (SP_REGNUM, sp);		    \   write_register (FP_REGNUM, sp);		    \
comment|/*  write_register (AP_REGNUM, sp + 17 * sizeof (int));*/
value|}
end_define

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{ register CORE_ADDR fp = read_register (FP_REGNUM);		 \   register int regnum;						 \   register int regmask = read_memory_integer (fp + 4, 4);	 \   write_register (PS_REGNUM, 					 \ 		  (regmask& 0xffff)				 \ 		  | (read_register (PS_REGNUM)& 0xffff0000));	 \   write_register (PC_REGNUM, read_memory_integer (fp + 16, 4));  \   write_register (FP_REGNUM, read_memory_integer (fp + 12, 4));  \
comment|/*  write_register (AP_REGNUM, read_memory_integer (fp + 8, 4));*/
value|\   fp += 16;							 \   for (regnum = 0; regnum< 12; regnum++)			 \     if (regmask& (0x10000<< regnum))				 \       write_register (regnum, read_memory_integer (fp += 4, 4)); \   fp = fp + 4 + ((regmask>> 30)& 3);				 \   if (regmask& 0x20000000)					 \     { regnum = read_memory_integer (fp, 4);			 \       fp += (regnum + 1) * 4; }					 \   write_register (SP_REGNUM, fp);				 \   set_current_frame (read_register (FP_REGNUM)); }
end_define

begin_comment
comment|/* This sequence of words is the instructions      calls #69, @#32323232      bpt    Note this is 8 bytes.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{0x329f69fb, 0x03323232}
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|0
end_define

begin_comment
comment|/* Start execution at beginning of dummy */
end_comment

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
name|type
parameter_list|)
define|\
value|{ *((char *) dummyname + 1) = nargs;		\   *(int *)((char *) dummyname + 3) = fun; }
end_define

begin_escape
end_escape

begin_comment
comment|/* Interface definitions for kernel debugger KDB.  */
end_comment

begin_comment
comment|/* I have *no idea* how to debug OSx kernels, so this    is flushed, possible forever. */
end_comment

end_unit

