begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for targe of a Gould Powernode, for GDB, the GNU debugger.    Copyright (C) 1986, 1987, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|GOULD_PN
end_define

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* This code appears in libraries on Gould machines.  Ignore it. */
end_comment

begin_define
define|#
directive|define
name|IGNORE_SYMBOL
parameter_list|(
name|type
parameter_list|)
value|(type == N_ENTRY)
end_define

begin_comment
comment|/* We don't want the extra gnu symbols on the machine;    they will interfere with the shared segment symbols.  */
end_comment

begin_define
define|#
directive|define
name|NO_GNU_STABS
end_define

begin_comment
comment|/* Macro for text-offset and data info (in PN a.out format).  */
end_comment

begin_define
define|#
directive|define
name|TEXTINFO
define|\
value|text_offset = N_TXTOFF (exec_coffhdr);			\ 	exec_data_offset = N_TXTOFF (exec_coffhdr)		\ 		+ exec_aouthdr.a_text
end_define

begin_comment
comment|/* Macro for number of symbol table entries */
end_comment

begin_define
define|#
directive|define
name|END_OF_TEXT_DEFAULT
define|\
value|(0xffffff)
end_define

begin_comment
comment|/* Macro for number of symbol table entries */
end_comment

begin_define
define|#
directive|define
name|NUMBER_OF_SYMBOLS
define|\
value|(coffhdr.f_nsyms)
end_define

begin_comment
comment|/* Macro for file-offset of symbol table (in usual a.out format).  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_TABLE_OFFSET
define|\
value|N_SYMOFF (coffhdr)
end_define

begin_comment
comment|/* Macro for file-offset of string table (in usual a.out format).  */
end_comment

begin_define
define|#
directive|define
name|STRING_TABLE_OFFSET
define|\
value|(N_STROFF (coffhdr) + sizeof(int))
end_define

begin_comment
comment|/* Macro to store the length of the string table data in INTO.  */
end_comment

begin_define
define|#
directive|define
name|READ_STRING_TABLE_SIZE
parameter_list|(
name|INTO
parameter_list|)
define|\
value|{ INTO = hdr.a_stsize; }
end_define

begin_comment
comment|/* Macro to declare variables to hold the file's header data.  */
end_comment

begin_define
define|#
directive|define
name|DECLARE_FILE_HEADERS
value|struct old_exec hdr;		\ 			      FILHDR coffhdr
end_define

begin_comment
comment|/* Macro to read the header data from descriptor DESC and validate it.    NAME is the file name, for error messages.  */
end_comment

begin_define
define|#
directive|define
name|READ_FILE_HEADERS
parameter_list|(
name|DESC
parameter_list|,
name|NAME
parameter_list|)
define|\
value|{ val = myread (DESC,&coffhdr, sizeof coffhdr);		\   if (val< 0)							\     perror_with_name (NAME);					\   val = myread (DESC,&hdr, sizeof hdr);			\   if (val< 0)							\     perror_with_name (NAME);					\   if (coffhdr.f_magic != GNP1MAGIC)				\     error ("File \"%s\" not in coff executable format.", NAME);	\   if (N_BADMAG (hdr))						\     error ("File \"%s\" not in executable format.", NAME); }
end_define

begin_comment
comment|/* Define COFF and other symbolic names needed on NP1 */
end_comment

begin_define
define|#
directive|define
name|NS32GMAGIC
value|GDPMAGIC
end_define

begin_define
define|#
directive|define
name|NS32SMAGIC
value|PN_MAGIC
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
comment|/* Offset from address of function to start of its code.    Zero on most machines.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_START_OFFSET
value|4
end_define

begin_comment
comment|/* Advance PC across any function entry prologue instructions    to reach some "real" code.  One PN we can have one or two startup    sequences depending on the size of the local stack:     Either:       "suabr b2, #"    of       "lil r4, #", "suabr b2, #(r4)"     "lwbr b6, #", "stw r1, 8(b2)"    Optional "stwbr b3, c(b2)"    Optional "trr r2,r7"      (Gould first argument register passing)      or    Optional "stw r2,8(b3)"   (Gould first argument register passing)  */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|pc
parameter_list|)
value|{ 						\ 	register int op = read_memory_integer ((pc), 4);		\ 	if ((op& 0xffff0000) == 0x580B0000) { 				\ 	    pc += 4;							\ 	    op = read_memory_integer ((pc), 4);				\ 	    if ((op& 0xffff0000) == 0x59400000) {			\ 		pc += 4;						\ 	        op = read_memory_integer ((pc), 4);			\ 		if ((op& 0xffff0000) == 0x5F000000) {			\ 		    pc += 4;						\ 	            op = read_memory_integer ((pc), 4);			\ 		    if (op == 0xD4820008) {				\ 		    	pc += 4;					\ 	            	op = read_memory_integer ((pc), 4);		\ 		    	if (op == 0x5582000C) {				\ 		    	    pc += 4;					\ 	                    op = read_memory_integer ((pc), 2);		\ 		            if (op == 0x2fa0) {				\ 		    	        pc += 2;				\ 		            } else {					\ 	                        op = read_memory_integer ((pc), 4);	\ 		                if (op == 0xd5030008) {			\ 		    	            pc += 4;				\ 		                }					\ 		            }						\ 		        } else {					\ 	                    op = read_memory_integer ((pc), 2);		\ 		            if (op == 0x2fa0) {				\ 		    	        pc += 2;				\ 		            }						\ 		        }						\ 		    }							\ 		}							\ 	    }								\ 	} 								\ 	if ((op& 0xffff0000) == 0x59000000) { 				\ 	    pc += 4;							\ 	    op = read_memory_integer ((pc), 4);				\ 	    if ((op& 0xffff0000) == 0x5F000000) {			\ 		pc += 4;						\ 	        op = read_memory_integer ((pc), 4);			\ 		if (op == 0xD4820008) {					\ 		    pc += 4;						\ 	            op = read_memory_integer ((pc), 4);			\ 		    if (op == 0x5582000C) {				\ 		    	pc += 4;					\ 	                op = read_memory_integer ((pc), 2);		\ 		        if (op == 0x2fa0) {				\ 		    	    pc += 2;					\ 		        } else {					\ 	                    op = read_memory_integer ((pc), 4);		\ 		            if (op == 0xd5030008) {			\ 		    	        pc += 4;				\ 		            }						\ 		        }						\ 		    } else {						\ 	                op = read_memory_integer ((pc), 2);		\ 		        if (op == 0x2fa0) {				\ 		    	    pc += 2;					\ 		        }						\ 		    }							\ 		}							\ 	    }								\ 	} 								\ }
end_define

begin_comment
comment|/* Immediately after a function call, return the saved pc.    Can't go through the frames for this because on some machines    the new frame is not set up until the new function executes    some instructions.  True on PN!  Return address is in R1.    Note: true return location is 4 bytes past R1! */
end_comment

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
define|\
value|(read_register(R1_REGNUM) + 4)
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|0x480000
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
value|{0x28, 0x09}
end_define

begin_comment
comment|/* Amount PC must be decremented by after a breakpoint.    This is often the number of bytes in BREAKPOINT    but not always.  */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|2
end_define

begin_comment
comment|/* Nonzero if instruction at PC is a return instruction. "bu 4(r1)" */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
value|(read_memory_integer (pc, 4) == 0xEC100004)
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
value|((*(short *)p& 0xff80) == 0x8000)
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

begin_define
define|#
directive|define
name|NUM_GEN_REGS
value|16
end_define

begin_define
define|#
directive|define
name|NUM_CPU_REGS
value|3
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{ \   "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", \   "b0", "b1", "b2", "b3", "b4", "b5", "b6", "b7", \   "sp", "ps", "pc", \ }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|R1_REGNUM
value|1
end_define

begin_comment
comment|/* Gr1 => return address of caller */
end_comment

begin_define
define|#
directive|define
name|R4_REGNUM
value|4
end_define

begin_comment
comment|/* Gr4 => register save area */
end_comment

begin_define
define|#
directive|define
name|R5_REGNUM
value|5
end_define

begin_comment
comment|/* Gr5 => register save area */
end_comment

begin_define
define|#
directive|define
name|R6_REGNUM
value|6
end_define

begin_comment
comment|/* Gr6 => register save area */
end_comment

begin_define
define|#
directive|define
name|R7_REGNUM
value|7
end_define

begin_comment
comment|/* Gr7 => register save area */
end_comment

begin_define
define|#
directive|define
name|B1_REGNUM
value|9
end_define

begin_comment
comment|/* Br1 => start of this code routine */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|10
end_define

begin_comment
comment|/* Br2 == (sp) */
end_comment

begin_define
define|#
directive|define
name|AP_REGNUM
value|11
end_define

begin_comment
comment|/* Br3 == (ap) */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|16
end_define

begin_comment
comment|/* A copy of Br2 saved in trap */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|17
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|18
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(NUM_GEN_REGS*4 + NUM_CPU_REGS*4)
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
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On the PN, all normal regs are 4 bytes. */
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
comment|/* Number of bytes of storage in the program's representation    for register N.  On the PN, all regs are 4 bytes. */
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
value|(4)
end_define

begin_comment
comment|/* Largest value REGISTER_VIRTUAL_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|(4)
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
value|bcopy ((FROM), (TO), REGISTER_RAW_SIZE(REGNUM));
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
value|bcopy ((FROM), (TO), REGISTER_VIRTUAL_SIZE(REGNUM));
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
value|(builtin_type_int)
end_define

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function.     On this machine this is a no-op, because gcc isn't used on it    yet.  So this calling convention is not used. */
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
end_define

begin_comment
comment|/* Extract from an arrary REGBUF containing the (raw) register state    a function return value of type TYPE, and copy that, in virtual format,    into VALBUF. */
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

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer.     However, if FRAME_CHAIN_VALID returns zero,    it means the given frame is the outermost one and has no caller.  */
end_comment

begin_comment
comment|/* In the case of the NPL, the frame's norminal address is Br2 and the     previous routines frame is up the stack X bytes, where X is the    value stored in the code function header xA(Br1). */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
value|(findframe(thisframe))
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
value|(chain != 0&& chain != (thisframe)->frame)
end_define

begin_comment
comment|/* Define other aspects of the stack frame on NPL.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|frame
parameter_list|)
define|\
value|(read_memory_integer ((frame)->frame + 8, 4))
end_define

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
define|\
value|((fi)->next_frame ? \ 	 read_memory_integer ((fi)->frame + 12, 4) : \ 	 read_register (AP_REGNUM))
end_define

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|((fi)->frame + 80)
end_define

begin_comment
comment|/* Set VAL to the number of args passed to frame described by FI.    Can set VAL to -1, meaning no way to tell.  */
end_comment

begin_comment
comment|/* We can check the stab info to see how    many arg we have.  No info in stack will tell us */
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
value|(val = findarg(fi))
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
value|{                                                                       \   bzero (&frame_saved_regs, sizeof frame_saved_regs);			\   (frame_saved_regs).regs[PC_REGNUM] = (frame_info)->frame + 8;		\   (frame_saved_regs).regs[R4_REGNUM] = (frame_info)->frame + 0x30;	\   (frame_saved_regs).regs[R5_REGNUM] = (frame_info)->frame + 0x34;	\   (frame_saved_regs).regs[R6_REGNUM] = (frame_info)->frame + 0x38;	\   (frame_saved_regs).regs[R7_REGNUM] = (frame_info)->frame + 0x3C;	\ }
end_define

begin_escape
end_escape

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
value|{ register CORE_ADDR sp = read_register (SP_REGNUM);			\   register int regnum;							\   sp = push_word (sp, read_register (PC_REGNUM));			\   sp = push_word (sp, read_register (FP_REGNUM));			\   write_register (FP_REGNUM, sp);					\   for (regnum = FP_REGNUM - 1; regnum>= 0; regnum--)			\     sp = push_word (sp, read_register (regnum));			\   sp = push_word (sp, read_register (PS_REGNUM));			\   write_register (SP_REGNUM, sp);  }
end_define

begin_comment
comment|/* Discard from the stack the innermost frame,     restoring all saved registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{ register FRAME frame = get_current_frame ();			 \   register CORE_ADDR fp;					 \   register int regnum;						 \   struct frame_saved_regs fsr;					 \   struct frame_info *fi;					 \   fi = get_frame_info (frame);					 \   fp = fi->frame;						 \   get_frame_saved_regs (fi,&fsr);				 \   for (regnum = FP_REGNUM - 1; regnum>= 0; regnum--)		 \     if (fsr.regs[regnum])					 \       write_register (regnum, read_memory_integer (fsr.regs[regnum], 4)); \   if (fsr.regs[PS_REGNUM])					 \     write_register (PS_REGNUM, read_memory_integer (fsr.regs[PS_REGNUM], 4)); \   write_register (FP_REGNUM, read_memory_integer (fp, 4));	 \   write_register (PC_REGNUM, read_memory_integer (fp + 4, 4));   \   write_register (SP_REGNUM, fp + 8);				 \   flush_cached_frames ();					 \   set_current_frame ( create_new_frame (read_register (FP_REGNUM),\ 					read_pc ())); }
end_define

begin_comment
comment|/* This sequence of words is the instructions:      halt      halt      halt      halt      suabr	b2, #<stacksize>      lwbr	b6, #con      stw	r1, 8(b2)	- save caller address, do we care?      lw		r2, 60(b2)	- arg1      labr	b3, 50(b2)      std	r4, 30(b2)	- save r4-r7      std	r6, 38(b2)      lwbr	b1, #<func>	- load function call address      brlnk	r1, 8(b1)	- call function      halt      halt      ld		r4, 30(b2)	- restore r4-r7      ld		r6, 38(b2)     Setup our stack frame, load argumemts, call and then restore registers. */
end_comment

begin_comment
comment|/* FIXME:  The below defines an m68k CALL_DUMMY, which looks nothing like what    is documented above. */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{0xf227e0ff, 0x48e7fffc, 0x426742e7, 0x4eb93232, 0x3232dffc, 0x69696969, 0x4e4f4e71}
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|28
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
value|{ *(int *)((char *) dummyname + 20) = nargs * 4;  \   *(int *)((char *) dummyname + 14) = fun; }
end_define

end_unit

