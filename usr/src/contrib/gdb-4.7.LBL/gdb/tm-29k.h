begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for target machine of AMD 29000, for GDB, the GNU debugger.    Copyright 1990, 1991 Free Software Foundation, Inc.    Contributed by Cygnus Support.  Written by Jim Kingdon.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Parameters for an EB29K (a board which plugs into a PC and is    accessed through EBMON software running on the PC, which we    use as we'd use a remote stub (see remote-eb.c).     If gdb is ported to other 29k machines/systems, the    machine/system-specific parts should be removed from this file (a    la tm-68k.h).  */
end_comment

begin_comment
comment|/* Byte order is configurable, but this machine runs big-endian.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* Floating point uses IEEE representations.  */
end_comment

begin_define
define|#
directive|define
name|IEEE_FLOAT
end_define

begin_comment
comment|/* Recognize our magic number.  */
end_comment

begin_define
define|#
directive|define
name|BADMAG
parameter_list|(
name|x
parameter_list|)
value|((x).f_magic != 0572)
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
define|\
value|{ pc = skip_prologue (pc); }
end_define

begin_function_decl
name|CORE_ADDR
name|skip_prologue
parameter_list|()
function_decl|;
end_function_decl

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
value|(read_register (LR0_REGNUM))
end_define

begin_comment
comment|/* I'm not sure about the exact value of this, but based on looking    at the stack pointer when we get to main this seems to be right.     This is the register stack; We call it "CONTROL" in GDB for consistency    with Pyramid.  */
end_comment

begin_define
define|#
directive|define
name|CONTROL_END_ADDR
value|0x80200000
end_define

begin_comment
comment|/* Memory stack.  This is for the default register stack size, which is    only 0x800 bytes.  Perhaps we should let the user specify stack sizes    (and tell EBMON with the "ZS" command).  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|0x801ff800
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
comment|/* Stack must be aligned on 32-bit word boundaries.  */
end_comment

begin_define
define|#
directive|define
name|STACK_ALIGN
parameter_list|(
name|ADDR
parameter_list|)
value|(((ADDR) + 3)& ~3)
end_define

begin_comment
comment|/* Sequence of bytes for breakpoint instruction.  */
end_comment

begin_comment
comment|/* ASNEQ 0x50, gr1, gr1    The trap number 0x50 is chosen arbitrarily.    We let the command line (or previously included files) override this    setting.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BREAKPOINT
end_ifndef

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
value|{0x72, 0x50, 0x01, 0x01}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Target is little-endian.  */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x01, 0x01, 0x50, 0x72}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target is little-endian.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BREAKPOINT */
end_comment

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
comment|/* Nonzero if instruction at PC is a return instruction.    On the 29k, this is a "jmpi l0" instruction.  */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
define|\
value|((read_memory_integer (pc, 4)& 0xff0000ff) == 0xc0000080)
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
comment|/* Allow the register declarations here to be overridden for remote    kernel debugging.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|REGISTER_NAMES
argument_list|)
end_if

begin_comment
comment|/* Number of machine registers */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|205
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.     FIXME, add floating point registers and support here.     Also note that this list does not attempt to deal with kernel    debugging (in which the first 32 registers are gr64-gr95).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"gr96", "gr97", "gr98", "gr99", "gr100", "gr101", "gr102", "gr103", "gr104", \  "gr105", "gr106", "gr107", "gr108", "gr109", "gr110", "gr111", "gr112", \  "gr113", "gr114", "gr115", "gr116", "gr117", "gr118", "gr119", "gr120", \  "gr121", "gr122", "gr123", "gr124", "gr125", "gr126", "gr127",		 \  "lr0", "lr1", "lr2", "lr3", "lr4", "lr5", "lr6", "lr7", "lr8", "lr9",   \  "lr10", "lr11", "lr12", "lr13", "lr14", "lr15", "lr16", "lr17", "lr18", \  "lr19", "lr20", "lr21", "lr22", "lr23", "lr24", "lr25", "lr26", "lr27", \  "lr28", "lr29", "lr30", "lr31", "lr32", "lr33", "lr34", "lr35", "lr36", \  "lr37", "lr38", "lr39", "lr40", "lr41", "lr42", "lr43", "lr44", "lr45", \  "lr46", "lr47", "lr48", "lr49", "lr50", "lr51", "lr52", "lr53", "lr54", \  "lr55", "lr56", "lr57", "lr58", "lr59", "lr60", "lr61", "lr62", "lr63", \  "lr64", "lr65", "lr66", "lr67", "lr68", "lr69", "lr70", "lr71", "lr72", \  "lr73", "lr74", "lr75", "lr76", "lr77", "lr78", "lr79", "lr80", "lr81", \  "lr82", "lr83", "lr84", "lr85", "lr86", "lr87", "lr88", "lr89", "lr90", \  "lr91", "lr92", "lr93", "lr94", "lr95", "lr96", "lr97", "lr98", "lr99", \  "lr100", "lr101", "lr102", "lr103", "lr104", "lr105", "lr106", "lr107", \  "lr108", "lr109", "lr110", "lr111", "lr112", "lr113", "lr114", "lr115", \  "lr116", "lr117", "lr118", "lr119", "lr120", "lr121", "lr122", "lr123", \  "lr124", "lr125", "lr126", "lr127",					 \   "AI0", "AI1", "AI2", "AI3", "AI4", "AI5", "AI6", "AI7", "AI8", "AI9",  \   "AI10", "AI11", "AI12", "AI13", "AI14", "AI15", "FP",			 \   "bp", "fc", "cr", "q",						 \   "vab", "ops", "cps", "cfg", "cha", "chd", "chc", "rbp", "tmc", "tmr",	 \   "pc0", "pc1", "pc2", "mmu", "lru", "fpe", "inte", "fps", "exo", "gr1",  \   "alu", "ipc", "ipa", "ipb" }
end_define

begin_comment
comment|/*  * Converts an sdb register number to an internal gdb register number.  * Currently under epi, gr96->0...gr127->31...lr0->32...lr127->159, or...  * 		  	gr64->0...gr95->31, lr0->32...lr127->159.  */
end_comment

begin_define
define|#
directive|define
name|SDB_REG_TO_REGNUM
parameter_list|(
name|value
parameter_list|)
define|\
value|(((value)>= 96&& (value)<= 127) ? ((value) - 96) : \    ((value)>= 128&& (value)<=  255) ? ((value) - 128 + LR0_REGNUM) : \    (value))
end_define

begin_comment
comment|/*  * Provide the processor register numbers of some registers that are  * expected/written in instructions that might change under different  * register sets.  Namely, gcc can compile (-mkernel-registers) so that  * it uses gr64-gr95 in stead of gr96-gr127.  */
end_comment

begin_define
define|#
directive|define
name|MSP_HW_REGNUM
value|125
end_define

begin_comment
comment|/* gr125 */
end_comment

begin_define
define|#
directive|define
name|RAB_HW_REGNUM
value|126
end_define

begin_comment
comment|/* gr126 */
end_comment

begin_comment
comment|/* Convert Processor Special register #x to REGISTER_NAMES register # */
end_comment

begin_define
define|#
directive|define
name|SR_REGNUM
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)< 15  ? VAB_REGNUM + (x)					 \    : (x)>= 128&& (x)< 131 ? IPC_REGNUM + (x) - 128		 \    : (x) == 131 ? Q_REGNUM					 \    : (x) == 132 ? ALU_REGNUM					 \    : (x)>= 133&& (x)< 136 ? BP_REGNUM + (x) - 133		 \    : (x)>= 160&& (x)< 163 ? FPE_REGNUM + (x) - 160		 \    : (x) == 164 ? EXO_REGNUM                                     \    : (error ("Internal error in SR_REGNUM"), 0))
end_define

begin_define
define|#
directive|define
name|GR96_REGNUM
value|0
end_define

begin_comment
comment|/* Define the return register separately, so it can be overridden for    kernel procedure calling conventions. */
end_comment

begin_define
define|#
directive|define
name|RETURN_REGNUM
value|GR96_REGNUM
end_define

begin_define
define|#
directive|define
name|GR1_REGNUM
value|200
end_define

begin_comment
comment|/* This needs to be the memory stack pointer, not the register stack pointer,    to make call_function work right.  */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|MSP_REGNUM
end_define

begin_define
define|#
directive|define
name|FP_REGNUM
value|33
end_define

begin_comment
comment|/* lr1 */
end_comment

begin_comment
comment|/* Large Return Pointer (gr123).  */
end_comment

begin_define
define|#
directive|define
name|LRP_REGNUM
value|(123 - 96 + GR96_REGNUM)
end_define

begin_comment
comment|/* Static link pointer (gr124).  */
end_comment

begin_define
define|#
directive|define
name|SLP_REGNUM
value|(124 - 96 + GR96_REGNUM)
end_define

begin_comment
comment|/* Memory Stack Pointer (gr125).  */
end_comment

begin_define
define|#
directive|define
name|MSP_REGNUM
value|(125 - 96 + GR96_REGNUM)
end_define

begin_comment
comment|/* Register allocate bound (gr126).  */
end_comment

begin_define
define|#
directive|define
name|RAB_REGNUM
value|(126 - 96 + GR96_REGNUM)
end_define

begin_comment
comment|/* Register Free Bound (gr127).  */
end_comment

begin_define
define|#
directive|define
name|RFB_REGNUM
value|(127 - 96 + GR96_REGNUM)
end_define

begin_comment
comment|/* Register Stack Pointer.  */
end_comment

begin_define
define|#
directive|define
name|RSP_REGNUM
value|GR1_REGNUM
end_define

begin_define
define|#
directive|define
name|LR0_REGNUM
value|32
end_define

begin_define
define|#
directive|define
name|BP_REGNUM
value|177
end_define

begin_define
define|#
directive|define
name|FC_REGNUM
value|178
end_define

begin_define
define|#
directive|define
name|CR_REGNUM
value|179
end_define

begin_define
define|#
directive|define
name|Q_REGNUM
value|180
end_define

begin_define
define|#
directive|define
name|VAB_REGNUM
value|181
end_define

begin_define
define|#
directive|define
name|OPS_REGNUM
value|(VAB_REGNUM + 1)
end_define

begin_define
define|#
directive|define
name|CPS_REGNUM
value|(VAB_REGNUM + 2)
end_define

begin_define
define|#
directive|define
name|CFG_REGNUM
value|(VAB_REGNUM + 3)
end_define

begin_define
define|#
directive|define
name|CHA_REGNUM
value|(VAB_REGNUM + 4)
end_define

begin_define
define|#
directive|define
name|CHD_REGNUM
value|(VAB_REGNUM + 5)
end_define

begin_define
define|#
directive|define
name|CHC_REGNUM
value|(VAB_REGNUM + 6)
end_define

begin_define
define|#
directive|define
name|RBP_REGNUM
value|(VAB_REGNUM + 7)
end_define

begin_define
define|#
directive|define
name|TMC_REGNUM
value|(VAB_REGNUM + 8)
end_define

begin_define
define|#
directive|define
name|TMR_REGNUM
value|(VAB_REGNUM + 9)
end_define

begin_define
define|#
directive|define
name|NPC_REGNUM
value|(VAB_REGNUM + 10)
end_define

begin_comment
comment|/* pc0 */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|(VAB_REGNUM + 11)
end_define

begin_comment
comment|/* pc1 */
end_comment

begin_define
define|#
directive|define
name|PC2_REGNUM
value|(VAB_REGNUM + 12)
end_define

begin_define
define|#
directive|define
name|MMU_REGNUM
value|(VAB_REGNUM + 13)
end_define

begin_define
define|#
directive|define
name|LRU_REGNUM
value|(VAB_REGNUM + 14)
end_define

begin_define
define|#
directive|define
name|FPE_REGNUM
value|(VAB_REGNUM + 15)
end_define

begin_define
define|#
directive|define
name|INTE_REGNUM
value|(VAB_REGNUM + 16)
end_define

begin_define
define|#
directive|define
name|FPS_REGNUM
value|(VAB_REGNUM + 17)
end_define

begin_define
define|#
directive|define
name|EXO_REGNUM
value|(VAB_REGNUM + 18)
end_define

begin_comment
comment|/* gr1 is defined above as 200 = VAB_REGNUM + 19 */
end_comment

begin_define
define|#
directive|define
name|ALU_REGNUM
value|(VAB_REGNUM + 20)
end_define

begin_define
define|#
directive|define
name|PS_REGNUM
value|ALU_REGNUM
end_define

begin_define
define|#
directive|define
name|IPC_REGNUM
value|(VAB_REGNUM + 21)
end_define

begin_define
define|#
directive|define
name|IPA_REGNUM
value|(VAB_REGNUM + 22)
end_define

begin_define
define|#
directive|define
name|IPB_REGNUM
value|(VAB_REGNUM + 23)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(REGISTER_NAMES) */
end_comment

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(NUM_REGS * 4)
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
value|((N)*4)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  */
end_comment

begin_comment
comment|/* All regs are 4 bytes.  */
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
comment|/* All regs are 4 bytes.  */
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
value|{ bcopy ((FROM), (TO), 4); }
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
value|{ bcopy ((FROM), (TO), 4); }
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
value|(((N) == PC_REGNUM || (N) == LRP_REGNUM || (N) == SLP_REGNUM         \     || (N) == MSP_REGNUM || (N) == RAB_REGNUM || (N) == RFB_REGNUM     \     || (N) == GR1_REGNUM || (N) == FP_REGNUM || (N) == LR0_REGNUM       \     || (N) == NPC_REGNUM || (N) == PC2_REGNUM)                           \    ? lookup_pointer_type (builtin_type_void) : builtin_type_int)
end_define

begin_escape
end_escape

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function. */
end_comment

begin_comment
comment|/* On the 29k the LRP points to the part of the structure beyond the first    16 words.  */
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
value|write_register (LRP_REGNUM, (ADDR) + 16 * 4);
end_define

begin_comment
comment|/* Should call_function allocate stack space for a struct return?  */
end_comment

begin_comment
comment|/* On the 29k objects over 16 words require the caller to allocate space.  */
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
value|(TYPE_LENGTH (type)> 16 * 4)
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
value|{    	       	       	       	       	       	       	       	       	   \     int reg_length = TYPE_LENGTH (TYPE);				   \     if (reg_length> 16 * 4)						   \       {									   \ 	reg_length = 16 * 4;						   \ 	read_memory (*((int *)(REGBUF) + LRP_REGNUM), (VALBUF) + 16 * 4,   \ 		     TYPE_LENGTH (TYPE) - 16 * 4);			   \       }									   \     bcopy (((int *)(REGBUF))+RETURN_REGNUM, (VALBUF), reg_length);	   \   }
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
value|{									  \     int reg_length = TYPE_LENGTH (TYPE);				  \     if (reg_length> 16 * 4)						  \       {									  \         reg_length = 16 * 4;						  \         write_memory (read_register (LRP_REGNUM),			  \ 		      (char *)(VALBUF) + 16 * 4,			  \ 		      TYPE_LENGTH (TYPE) - 16 * 4);			  \       }									  \     write_register_bytes (REGISTER_BYTE (RETURN_REGNUM), (char *)(VALBUF),  \ 			  TYPE_LENGTH (TYPE));				  \   }
end_define

begin_escape
end_escape

begin_comment
comment|/* The am29k user's guide documents well what the stacks look like.    But what isn't so clear there is how this interracts with the    symbols, or with GDB.    In the following saved_msp, saved memory stack pointer (which functions    as a memory frame pointer), means either    a register containing the memory frame pointer or, in the case of    functions with fixed size memory frames (i.e. those who don't use    alloca()), the result of the calculation msp + msize.     LOC_ARG, LOC_LOCAL - For GCC, these are relative to saved_msp.      For high C, these are relative to msp (making alloca impossible).    LOC_REGISTER, LOC_REGPARM - The register number is the number at the      time the function is running (after the prologue), or in the case      of LOC_REGPARM, may be a register number in the range 160-175.     The compilers do things like store an argument into memory, and then put out    a LOC_ARG for it, or put it into global registers and put out a    LOC_REGPARM.  Thus is it important to execute the first line of    code (i.e. the line of the open brace, i.e. the prologue) of a function    before trying to print arguments or anything.     The following diagram attempts to depict what is going on in memory    (see also the _am29k user's guide_) and also how that interacts with    GDB frames.  We arbitrarily pick fci->frame to point the same place    as the register stack pointer; since we set it ourself in    INIT_EXTRA_FRAME_INFO, and access it only through the FRAME_*    macros, it doesn't really matter exactly how we    do it.  However, note that FRAME_FP is used in two ways in GDB:    (1) as a "magic cookie" which uniquely identifies frames (even over    calls to the inferior), (2) (in PC_IN_CALL_DUMMY [ON_STACK])    as the value of SP_REGNUM before the dummy frame was pushed.  These    two meanings would be incompatible for the 29k if we defined    CALL_DUMMY_LOCATION == ON_STACK (but we don't, so don't worry about it).    Also note that "lr1" below, while called a frame pointer    in the user's guide, has only one function:  To determine whether    registers need to be filled in the function epilogue.     Consider the code:< call bar>        	loc1: . . .         bar:  sub gr1,gr1,rsize_b 	      . . . 	      add mfp,msp,0 	      sub msp,msp,msize_b 	      . . .< call foo> 	loc2: . . .         foo:  sub gr1,gr1,rsize_f 	      . . . 	      add mfp,msp,0 	      sub msp,msp,msize_f 	      . . .         loc3:< suppose the inferior stops here>                     memory stack      register stack 		   |           |     |____________| 		   |           |     |____loc1____| 	  +------->|___________|     |            |   ^ 	  |        | ^         |     |  locals_b  |   | 	  |        | |         |     |____________|   | 	  |        | |         |     |            |   | rsize_b 	  |        | | msize_b |     | args_to_f  |   | 	  |        | |         |     |____________|   | 	  |        | |         |     |____lr1_____|   V 	  |        | V         |     |____loc2____|<----------------+ 	  |   +--->|___________|<---------mfp     |   ^             | 	  |   |    | ^         |     |  locals_f  |   |             | 	  |   |    | | msize_f |     |____________|   |             | 	  |   |    | |         |     |            |   | rsize_f     | 	  |   |    | V         |     |   args     |   |             | 	  |   |    |___________|<msp |____________|   |             | 	  |   |                      |_____lr1____|   V             | 	  |   |                      |___garbage__|<- gr1<----+   |  	  |   |                 		                |   |           |   |                 		                |   | 	  |   |	       	       	     pc=loc3	                |   | 	  |   |         		      	                |   | 	  |   |         		      	                |   | 	  |   |            frame cache	      	                |   |           |   |       |_________________|     	                |   |           |   |       |rsize=rsize_b    |     	                |   |           |   |       |msize=msize_b    |     	                |   |           +---|--------saved_msp        |     	                |   |               |       |frame------------------------------------|---+               |       |pc=loc2          |                       |               |       |_________________|                       |               |       |rsize=rsize_f    |                       |               |       |msize=msize_f    |                       |               +--------saved_msp        |                       |                       |frame------------------------------------+                       |pc=loc3          |                       |_________________|     So, is that sufficiently confusing?  Welcome to the 29000.    Notes:    * The frame for foo uses a memory frame pointer but the frame for      bar does not.  In the latter case the saved_msp is      computed by adding msize to the saved_msp of the      next frame.    * msize is in the frame cache only for high C's sake.  */
end_comment

begin_function_decl
name|void
name|read_register_stack
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|long
name|read_register_stack_integer
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_define
define|#
directive|define
name|EXTRA_FRAME_INFO
define|\
value|CORE_ADDR saved_msp;    \   unsigned int rsize;     \   unsigned int msize;	  \   unsigned char flags;
end_define

begin_comment
comment|/* Bits for flags in EXTRA_FRAME_INFO */
end_comment

begin_define
define|#
directive|define
name|TRANSPARENT
value|0x1
end_define

begin_comment
comment|/* This is a transparent frame */
end_comment

begin_define
define|#
directive|define
name|MFP_USED
value|0x2
end_define

begin_comment
comment|/* A memory frame pointer is used */
end_comment

begin_comment
comment|/* Because INIT_FRAME_PC gets passed fromleaf, that's where we init    not only ->pc and ->frame, but all the extra stuff, when called from    get_prev_frame_info, that is.  */
end_comment

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

begin_function_decl
name|void
name|init_extra_frame_info
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|INIT_FRAME_PC
parameter_list|(
name|fromleaf
parameter_list|,
name|fci
parameter_list|)
value|init_frame_pc(fromleaf, fci)
end_define

begin_function_decl
name|void
name|init_frame_pc
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* FRAME_CHAIN takes a FRAME    and produces the frame's chain-pointer.     However, if FRAME_CHAIN_VALID returns zero,    it means the given frame is the outermost one and has no caller.  */
end_comment

begin_comment
comment|/* On the 29k, the nominal address of a frame is the address on the    register stack of the return address (the one next to the incoming    arguments, not down at the bottom so nominal address == stack pointer).     GDB expects "nominal address" to equal contents of FP_REGNUM,    at least when it comes time to create the innermost frame.    However, that doesn't work for us, so when creating the innermost    frame we set ->frame ourselves in INIT_EXTRA_FRAME_INFO.  */
end_comment

begin_comment
comment|/* These are mostly dummies for the 29k because INIT_FRAME_PC    sets prev->frame instead.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
value|((thisframe)->frame + (thisframe)->rsize)
end_define

begin_comment
comment|/* Determine if the frame has a 'previous' and back-traceable frame. */
end_comment

begin_define
define|#
directive|define
name|FRAME_IS_UNCHAINED
parameter_list|(
name|frame
parameter_list|)
value|((frame)->flags& TRANSPARENT)
end_define

begin_comment
comment|/* Find the previous frame of a transparent routine.  * For now lets not try and trace through a transparent routine (we might   * have to assume that all transparent routines are traps).  */
end_comment

begin_define
define|#
directive|define
name|FIND_PREV_UNCHAINED_FRAME
parameter_list|(
name|frame
parameter_list|)
value|0
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

begin_comment
comment|/* Saved pc (i.e. return address).  */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|fraim
parameter_list|)
define|\
value|(read_register_stack_integer ((fraim)->frame + (fraim)->rsize, 4))
end_define

begin_comment
comment|/* Local variables (i.e. LOC_LOCAL) are on the memory stack, with their    offsets being relative to the memory stack pointer (high C) or    saved_msp (gcc).  */
end_comment

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|frame_locals_address (fi)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|frame_locals_address
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return number of args passed to a frame.    Can return -1, meaning no way to tell.  */
end_comment

begin_comment
comment|/* While we could go the effort of finding the tags word and getting    the argcount field from it,    (1) It only counts arguments in registers, i.e. the first 16 words        of arguments    (2) It gives the number of arguments the function was declared with        not how many it was called with (or some variation, like all 16        words for varadic functions).  This makes argcount pretty much        redundant with -g info, even for varadic functions.    So don't bother.  */
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
value|((numargs) = -1)
end_define

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|FRAME_LOCALS_ADDRESS (fi)
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
comment|/* Provide our own get_saved_register.  HAVE_REGISTER_WINDOWS is insufficient    because registers get renumbered on the 29k without getting saved.  */
end_comment

begin_define
define|#
directive|define
name|GET_SAVED_REGISTER
end_define

begin_escape
end_escape

begin_comment
comment|/* Call function stuff.  */
end_comment

begin_comment
comment|/* The dummy frame looks like this (see also the general frame picture    above):  					register stack  	                	      |                |  frame for function                	                      |   locals_sproc |  executing at time                                       |________________|  of call_function.                      		      |	               |  We must not disturb                      		      |	args_out_sproc |  it.         memory stack 		      |________________|                      		      |____lr1_sproc___|<-+        |            |		      |__retaddr_sproc_|  |<-- gr1 (at start)        |____________|<-msp 0<-----------mfp_dummy_____|  |        |            |  (at start)     |  save regs     |  |        | arg_slop   |		      |  pc0,pc1       |  |        | (16 words) |		      | gr96-gr124     |  |        |____________|<-msp 1--after   | sr160-sr162    |  |        |            | PUSH_DUMMY_FRAME| sr128-sr135    |  |        | struct ret |                 |________________|  |        | 17+        |                 |                |  |         |____________|<- lrp           | args_out_dummy |  |        | struct ret |		      |  (16 words)    |  |        | 16         |		      |________________|  |        | (16 words) |                 |____lr1_dummy___|--+        |____________|<- msp 2--after  |_retaddr_dummy__|<- gr1 after        |            | struct ret      |                |   PUSH_DUMMY_FRAME        | margs17+   | area allocated  |  locals_inf    |        |            |                 |________________|    called        |____________|<- msp 4--when   |                |    function's        |            |   inf called    | args_out_inf   |    frame (set up        | margs16    |                 |________________|    by called        | (16 words) |                 |_____lr1_inf____|    function).        |____________|<- msp 3--after  |       .        |        |            |   args pushed   |       .        |        |            |	              |       .        |                                       |                |     arg_slop: This area is so that when the call dummy adds 16 words to       the msp, it won't end up larger than mfp_dummy (it is needed in the       case where margs and struct_ret do not add up to at least 16 words).    struct ret:  This area is allocated by GDB if the return value is more       than 16 words.  struct ret_16 is not used on the 29k.    margs:  Pushed by GDB.  The call dummy copies the first 16 words to       args_out_dummy.    retaddr_sproc:  Contains the PC at the time we call the function.       set by PUSH_DUMMY_FRAME and read by POP_FRAME.    retaddr_dummy:  This points to a breakpoint instruction in the dummy.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Rsize for dummy frame, in bytes.  */
end_comment

begin_comment
comment|/* Bytes for outgoing args, lr1, and retaddr.  */
end_comment

begin_define
define|#
directive|define
name|DUMMY_ARG
value|(2 * 4 + 16 * 4)
end_define

begin_comment
comment|/* Number of special registers (sr128-) to save.  */
end_comment

begin_define
define|#
directive|define
name|DUMMY_SAVE_SR128
value|8
end_define

begin_comment
comment|/* Number of special registers (sr160-) to save.  */
end_comment

begin_define
define|#
directive|define
name|DUMMY_SAVE_SR160
value|3
end_define

begin_comment
comment|/* Number of general (gr96- or gr64-) registers to save.  */
end_comment

begin_define
define|#
directive|define
name|DUMMY_SAVE_GREGS
value|29
end_define

begin_define
define|#
directive|define
name|DUMMY_FRAME_RSIZE
define|\
value|(4
comment|/* mfp_dummy */
value|\  + 2 * 4
comment|/* pc0, pc1 */
value|\  + DUMMY_SAVE_GREGS * 4   \  + DUMMY_SAVE_SR160 * 4	  \  + DUMMY_SAVE_SR128 * 4	  \  + DUMMY_ARG		  \  + 4
comment|/* pad to doubleword */
value|)
end_define

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
value|push_dummy_frame()
end_define

begin_function_decl
specifier|extern
name|void
name|push_dummy_frame
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Discard from the stack the innermost frame,    restoring all saved registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
value|pop_frame()
end_define

begin_function_decl
specifier|extern
name|void
name|pop_frame
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* This sequence of words is the instructions    mtsrim cr, 15    loadm 0, 0, lr2, msp     ; load first 16 words of arguments into registers    add msp, msp, 16 * 4     ; point to the remaining arguments  CONST_INSN:    const lr0,inf		; (replaced by       half of target addr)    consth lr0,inf		; (replaced by other half of target addr)    calli lr0, lr0     aseq 0x40,gr1,gr1   ; nop  BREAKPT_INSN:    asneq 0x50,gr1,gr1  ; breakpoint	(replaced by local breakpoint insn)    */
end_comment

begin_if
if|#
directive|if
name|TARGET_BYTE_ORDER
operator|==
name|HOST_BYTE_ORDER
end_if

begin_define
define|#
directive|define
name|BS
parameter_list|(
specifier|const
parameter_list|)
value|const
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BS
parameter_list|(
specifier|const
parameter_list|)
value|(((const)& 0xff)<< 24) |	\ 			(((const)& 0xff00)<< 8) |	\ 			(((const)& 0xff0000)>> 8) |	\ 			(((const)& 0xff000000)>> 24)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Position of the "const" and blkt instructions within CALL_DUMMY in bytes. */
end_comment

begin_define
define|#
directive|define
name|CONST_INSN
value|(3 * 4)
end_define

begin_define
define|#
directive|define
name|BREAKPT_INSN
value|(7 * 4)
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{	\ 		BS(0x0400870f),\ 		BS(0x36008200|(MSP_HW_REGNUM)), \ 		BS(0x15000040|(MSP_HW_REGNUM<<8)|(MSP_HW_REGNUM<<16)), \ 		BS(0x03ff80ff),	\ 		BS(0x02ff80ff),	\ 		BS(0xc8008080),	\ 		BS(0x70400101),	\ 		BS(0x72500101)}
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|(8 * 4)
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
comment|/* Helper macro for FIX_CALL_DUMMY.  WORDP is a long * which points to a    word in target byte order; bits 0-7 and 16-23 of *WORDP are replaced with    bits 0-7 and 8-15 of DATA (which is in host byte order).  */
end_comment

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
name|STUFF_I16
parameter_list|(
name|WORDP
parameter_list|,
name|DATA
parameter_list|)
define|\
value|{ \     *((char *)(WORDP) + 3) = ((DATA)& 0xff);\     *((char *)(WORDP) + 1) = (((DATA)>> 8)& 0xff);\   }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Target is little endian.  */
end_comment

begin_define
define|#
directive|define
name|STUFF_I16
parameter_list|(
name|WORDP
parameter_list|,
name|DATA
parameter_list|)
define|\
value|{
end_define

begin_expr_stmt
operator|*
operator|(
name|char
operator|*
operator|)
operator|(
name|WORDP
operator|)
operator|=
operator|(
operator|(
name|DATA
operator|)
operator|&
literal|0xff
operator|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
operator|*
operator|(
operator|(
name|char
operator|*
operator|)
operator|(
name|WORDP
operator|)
operator|+
literal|2
operator|)
operator|=
operator|(
operator|(
operator|(
name|DATA
operator|)
operator|>>
literal|8
operator|)
operator|&
literal|0xff
operator|)
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target is little endian.  */
end_comment

begin_comment
comment|/* Insert the specified number of args and function address    into a call sequence of the above form stored at DUMMYNAME.  */
end_comment

begin_comment
comment|/* Currently this stuffs in the address of the function that we are calling.    Since different 29k systems use different breakpoint instructions, it    also stuffs BREAKPOINT in the right place (to avoid having to    duplicate CALL_DUMMY in each tm-*.h file).  */
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
value|{\     STUFF_I16((char *)dummyname + CONST_INSN, fun);		\     STUFF_I16((char *)dummyname + CONST_INSN + 4, fun>> 16);	\
comment|/* FIXME  memcpy ((char *)(dummyname) + BREAKPT_INSN, break_insn, 4); */
value|\   }
end_define

begin_comment
comment|/* 29k architecture has separate data& instruction memories -- wired to    different pins on the chip -- and can't execute the data memory.    Also, there should be space after text_end;    we won't get a SIGSEGV or scribble on data space.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_LOCATION
value|AFTER_TEXT_END
end_define

begin_comment
comment|/* Because of this, we need (as a kludge) to know the addresses of the    text section.  */
end_comment

begin_define
define|#
directive|define
name|NEED_TEXT_START_END
end_define

begin_comment
comment|/* How to translate register numbers in the .stab's into gdb's internal register    numbers.  We don't translate them, but we warn if an invalid register    number is seen.  Note that FIXME, we use the value "sym" as an implicit    argument in printing the error message.  It happens to be available where    this macro is used.  (This macro definition appeared in a late revision    of gdb-3.91.6 and is not well tested.  Also, it should be a "complaint".) */
end_comment

begin_define
define|#
directive|define
name|STAB_REG_TO_REGNUM
parameter_list|(
name|num
parameter_list|)
define|\
value|(((num)> LR0_REGNUM + 127) \ 	   ? fprintf(stderr, 	\ 		"Invalid register number %d in symbol table entry for %s\n", \ 	         (num), SYMBOL_NAME (sym)), (num)	\ 	   : (num))
end_define

end_unit

