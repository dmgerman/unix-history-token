begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This code is derived from software copyrighted by the Free Software  * Foundation.  *  * Modified 1991 by Donn Seeley at UUNET Technologies, Inc.  *  *	@(#)m-tahoe.h	6.4 (Berkeley) 5/8/91  */
end_comment

begin_comment
comment|/*  * Ported by the State University of New York at Buffalo by the Distributed  * Computer Systems Lab, Department of Computer Science, 1991.  */
end_comment

begin_comment
comment|/*  * These first two are kludges to get this thing to compile under Reno (or  * at least the Reno running on okeeffe). It seems there are a few problems  * with the include files.  */
end_comment

begin_comment
comment|/*  * Until gdb becomes POSIX-compatible...  */
end_comment

begin_define
define|#
directive|define
name|USE_OLD_TTY
value|1
end_define

begin_comment
comment|/*  * That's all for the kludges. Now on to the port...  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tahoe
end_ifndef

begin_define
define|#
directive|define
name|tahoe
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the bit, byte, and word ordering of the machine.  */
end_comment

begin_comment
comment|/* #define BITS_BIG_ENDIAN */
end_comment

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
comment|/* Library stuff: POSIX tty (not supported yet), V7 tty (sigh), vprintf.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS
value|1
end_define

begin_define
define|#
directive|define
name|USE_OLD_TTY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
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
value|2
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
define|\
value|{ register int op = (unsigned char) read_memory_integer (pc, 1);  \   if (op == 0x11) pc += 2;
comment|/* skip brb */
value|\   if (op == 0x13) pc += 3;
comment|/* skip brw */
value|\   if (op == 0x2c&&						  \       ((unsigned char) read_memory_integer (pc+2, 1)) == 0x5e)	  \     pc += 3;
comment|/* skip subl2 */
value|\   if (op == 0xe9&&						  \       ((unsigned char) read_memory_integer (pc+1, 1)) == 0xae&&  \       ((unsigned char) read_memory_integer(pc+3, 1)) == 0x5e)	  \      pc += 4;
comment|/* skip movab */
value|\   if (op == 0xe9&&						  \       ((unsigned char) read_memory_integer (pc+1, 1)) == 0xce&&  \       ((unsigned char) read_memory_integer(pc+4, 1)) == 0x5e)	  \     pc += 5;
comment|/* skip movab */
value|\   if (op == 0xe9&&						  \       ((unsigned char) read_memory_integer (pc+1, 1)) == 0xee&&  \       ((unsigned char) read_memory_integer(pc+6, 1)) == 0x5e)	  \     pc += 7;
comment|/* skip movab */
value|\ }
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
value|(0xc0000000 - (UPAGES * NBPG))
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0xc0000000 - (UPAGES * NBPG))
end_define

begin_comment
comment|/* Same as offsetof macro from stddef.h (which 4.3BSD doesn't have).  */
end_comment

begin_define
define|#
directive|define
name|my_offsetof
parameter_list|(
name|TYPE
parameter_list|,
name|MEMBER
parameter_list|)
value|((unsigned long)&((TYPE *)0)->MEMBER)
end_define

begin_comment
comment|/* Under BSD, sigtramp is in the u area.  Note that this definition    includes both the subroutine at u_pcb.pcb_sigc[3], and the    routine at u_pcb.pcb_sigc[0] (which does a calls to u_pcb.pcb_sigc[3]).    I think this is what we want.  */
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
define|\
value|((pc)>= KERNEL_U_ADDR + my_offsetof (struct user, u_pcb.pcb_sigc[0])   \&& (pc)< KERNEL_U_ADDR + my_offsetof (struct user, u_pcb.pcb_sigc[5]) \    )
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
comment|/* Sequence of bytes for breakpoint instruction.  */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x30}
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

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
value|(read_memory_integer (pc, 1) == 0x40)
end_define

begin_comment
comment|/* Return 1 if P points to an invalid floating point value.    LEN is the length in bytes -- not relevant on the Tahoe. */
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
value|19
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "r12", "fp", "sp", "pc", "ps", "al", "ah"}
end_define

begin_define
define|#
directive|define
name|FP_REGNUM
value|13
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|14
end_define

begin_comment
comment|/* Contains address of top of stack */
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

begin_define
define|#
directive|define
name|PS_REGNUM
value|16
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|AL_REGNUM
value|17
end_define

begin_comment
comment|/* Contains accumulator */
end_comment

begin_define
define|#
directive|define
name|AH_REGNUM
value|18
end_define

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
value|{ addr = blockend - 100 + regno * 4;			\   if (regno == PC_REGNUM) addr = blockend - 8;		\   if (regno == PS_REGNUM) addr = blockend - 4;		\   if (regno == FP_REGNUM) addr = blockend - 40;	        \   if (regno == SP_REGNUM) addr = blockend - 36;         \   if (regno == AL_REGNUM) addr = blockend - 20;       \   if (regno == AH_REGNUM) addr = blockend - 24;}
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(19*4)
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
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On the tahoe, all regs are 4 bytes.  */
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
comment|/* Number of bytes of storage in the program's representation    for register N.  On the tahoe, all regs are 4 bytes.  */
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
value|{ write_register (1, (ADDR)); }
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
value|bcopy (REGBUF, VALBUF, TYPE_LENGTH (TYPE))
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
value|write_register_bytes (0, VALBUF, TYPE_LENGTH (TYPE))
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
value|(*(int *)(REGBUF))
end_define

begin_comment
comment|/* Compensate for lack of `vprintf' function.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VPRINTF
end_ifndef

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_VPRINTF */
end_comment

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).     FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer.     FRAME_CHAIN_COMBINE takes the chain pointer and the frame's nominal address    and produces the nominal address of the caller frame.     However, if FRAME_CHAIN_VALID returns zero,    it means the given frame is the outermost one and has no caller.    In that case, FRAME_CHAIN_COMBINE is not used.  */
end_comment

begin_comment
comment|/* In the case of the Tahoe, the frame's nominal address is the FP value,    and it points to the old FP */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(outside_startup_file ((thisframe)->pc) ? \    read_memory_integer ((thisframe)->frame, 4) :\    0)
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
comment|/* Saved PC */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
value|(read_memory_integer ((FRAME)->frame - 8, 4))
end_define

begin_comment
comment|/* In most of GDB, getting the args address is too important to    just say "I don't know". */
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

begin_comment
comment|/* Address to use as an anchor for finding local variables */
end_comment

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
comment|/* Return number of args passed to a frame.    Can return -1, meaning no way to tell.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS
parameter_list|(
name|numargs
parameter_list|,
name|fi
parameter_list|)
define|\
value|{ numargs = ((0xffff& read_memory_integer(((fi)->frame-4),4)) - 4)>> 2; }
end_define

begin_comment
comment|/* Return number of bytes at start of arglist that are not really args.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_SKIP
value|4
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
define|\
value|{ register int regnum;     \   register int rmask = read_memory_integer ((frame_info)->frame-4, 4)>> 16;\   register CORE_ADDR next_addr;     \   bzero (&frame_saved_regs, sizeof frame_saved_regs);     \   next_addr = (frame_info)->frame - 8;     \   for (regnum = 12; regnum>= 0; regnum--, rmask<<= 1)  \     (frame_saved_regs).regs[regnum] = (rmask& 0x1000) ? (next_addr -= 4) : 0;\   (frame_saved_regs).regs[SP_REGNUM] = (frame_info)->frame + 4;  \   (frame_saved_regs).regs[PC_REGNUM] = (frame_info)->frame - 8;  \   (frame_saved_regs).regs[FP_REGNUM] = (frame_info)->frame;      \ }
end_define

begin_comment
comment|/* Things needed for making the inferior call functions.  */
end_comment

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
define|\
value|{ register CORE_ADDR sp = read_register (SP_REGNUM);	\   register int regnum;					\ printf("PUSH_DUMMY_FRAME\n");				\   sp = push_word (sp, read_register (FP_REGNUM));	\   write_register (FP_REGNUM, sp);			\   sp = push_word (sp, 0x1fff0004);
comment|/*SAVE MASK*/
value|\   sp = push_word (sp, read_register (PC_REGNUM));	\   for (regnum = 12; regnum>= 0; regnum--)		\     sp = push_word (sp, read_register (regnum));	\   write_register (SP_REGNUM, sp);			\ }
end_define

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{ register CORE_ADDR fp = read_register (FP_REGNUM);			\   register int regnum;							\   register int regmask = read_memory_integer (fp-4, 4);			\ printf("POP_FRAME\n");							\   regmask>>= 16;                                               	\   write_register (SP_REGNUM, fp+4);	                           	\   write_register (PC_REGNUM, read_memory_integer(fp-8, 4));	  	\   write_register (FP_REGNUM, read_memory_integer(fp, 4));  		\   fp -= 8;								\   for (regnum = 12; regnum>= 0; regnum--, regmask<<= 1)		\     if (regmask& 0x1000)                                            	\       write_register (regnum, read_memory_integer (fp-=4, 4));		\   flush_cached_frames ();						\   set_current_frame (create_new_frame (read_register (FP_REGNUM),	\ 					read_pc ())); }
end_define

begin_comment
comment|/* This sequence of words is the instructions      calls #69, @#32323232      bpt    Note this is 8 bytes.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{0xbf699f32, 0x32323230}
end_define

begin_comment
comment|/* Start execution at beginning of dummy */
end_comment

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
name|type
parameter_list|)
define|\
value|{ int temp = (int) fun;				\   *((char *) dummyname + 1) = nargs;		\   bcopy(&temp,(char *)dummyname+3,4); }
end_define

begin_comment
comment|/* Interface definitions for kernel debugger KDB.  */
end_comment

begin_comment
comment|/* Map machine fault codes into signal numbers.    First subtract 0, divide by 4, then index in a table.    Faults for which the entry in this table is 0    are not handled by KDB; the program's own trap handler    gets to handle then.  */
end_comment

begin_define
define|#
directive|define
name|FAULT_CODE_ORIGIN
value|0
end_define

begin_define
define|#
directive|define
name|FAULT_CODE_UNITS
value|4
end_define

begin_define
define|#
directive|define
name|FAULT_TABLE
define|\
value|{ 0, SIGKILL, SIGSEGV, 0, 0, 0, 0, 0, \   0, 0, SIGTRAP, SIGTRAP, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0}
end_define

begin_comment
comment|/* Start running with a stack stretching from BEG to END.    BEG and END should be symbols meaningful to the assembler.    This is used only for kdb.  */
end_comment

begin_define
define|#
directive|define
name|INIT_STACK
parameter_list|(
name|beg
parameter_list|,
name|end
parameter_list|)
define|\
value|{ asm (".globl end");         \   asm ("movl $ end, sp");      \   asm ("clrl fp"); }
end_define

begin_comment
comment|/* Push the frame pointer register on the stack.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("pushl fp");
end_define

begin_comment
comment|/* Copy the top-of-stack to the frame pointer register.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME_PTR
define|\
value|asm ("movl (sp), fp");
end_define

begin_comment
comment|/* After KDB is entered by a fault, push all registers    that GDB thinks about (all NUM_REGS of them),    so that they appear in order of ascending GDB register number.    The fault code will be on the stack beyond the last register.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_REGISTERS
define|\
value|{ asm ("pushl 8(sp)");        \   asm ("pushl 8(sp)");        \   asm ("pushal 0x41(sp)");    \   asm ("pushl r0" );       \   asm ("pushl r1" );       \   asm ("pushl r2" );       \   asm ("pushl r3" );       \   asm ("pushl r4" );       \   asm ("pushl r5" );       \   asm ("pushl r6" );       \   asm ("pushl r7" );       \   asm ("pushl r8" );       \   asm ("pushl r9" );       \   asm ("pushl r10" );       \   asm ("pushl r11" );       \   asm ("pushl r12" );       \   asm ("pushl fp" );       \   asm ("pushl sp" );       \   asm ("pushl pc" );       \   asm ("pushl ps" );       \   asm ("pushl aclo" );       \   asm ("pushl achi" );       \ }
end_define

begin_comment
comment|/* Assuming the registers (including processor status) have been    pushed on the stack in order of ascending GDB register number,    restore them and return to the address in the saved PC register.  */
end_comment

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{                          \   asm ("movl (sp)+, achi");   \   asm ("movl (sp)+, aclo");   \   asm ("movl (sp)+, ps");   \   asm ("movl (sp)+, pc");   \   asm ("movl (sp)+, sp");   \   asm ("movl (sp)+, fp");   \   asm ("movl (sp)+, r12");   \   asm ("movl (sp)+, r11");   \   asm ("movl (sp)+, r10");   \   asm ("movl (sp)+, r9");   \   asm ("movl (sp)+, r8");   \   asm ("movl (sp)+, r7");   \   asm ("movl (sp)+, r6");   \   asm ("movl (sp)+, r5");   \   asm ("movl (sp)+, r4");   \   asm ("movl (sp)+, r3");   \   asm ("movl (sp)+, r2");   \   asm ("movl (sp)+, r1");   \   asm ("movl (sp)+, r0");   \   asm ("subl2 $8,(sp)");   \   asm ("movl (sp),sp");    \   asm ("rei"); }
end_define

end_unit

