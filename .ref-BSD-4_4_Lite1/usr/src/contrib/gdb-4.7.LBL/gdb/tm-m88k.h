begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine description for generic Motorola 88000, for GDB.    Copyright 1986, 1987, 1988, 1989, 1990, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* g++ support is not yet included.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* We cache information about saved registers in the frame structure,    to save us from having to re-scan function prologues every time    a register in a non-current frame is accessed.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_FRAME_INFO
define|\
value|struct frame_saved_regs *fsr;	\ 	CORE_ADDR locals_pointer;	\ 	CORE_ADDR args_pointer;
end_define

begin_comment
comment|/* Zero the frame_saved_regs pointer when the frame is initialized,    so that FRAME_FIND_SAVED_REGS () will know to allocate and    initialize a frame_saved_regs struct the first time it is called.    Set the arg_pointer to -1, which is not valid; 0 and other values    indicate real, cached values.  */
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
value|init_extra_frame_info (fromleaf, fi)
end_define

begin_function_decl
specifier|extern
name|void
name|init_extra_frame_info
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IEEE_FLOAT
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
name|frompc
parameter_list|)
define|\
value|skip_prologue (frompc)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|skip_prologue
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The m88k kernel aligns all instructions on 4-byte boundaries.  The    kernel also uses the least significant two bits for its own hocus    pocus.  When gdb receives an address from the kernel, it needs to    preserve those right-most two bits, but gdb also needs to be careful    to realize that those two bits are not really a part of the address    of an instruction.  Shrug.  */
end_comment

begin_define
define|#
directive|define
name|ADDR_BITS_REMOVE
parameter_list|(
name|addr
parameter_list|)
value|((addr)& ~3)
end_define

begin_define
define|#
directive|define
name|ADDR_BITS_SET
parameter_list|(
name|addr
parameter_list|)
value|(((addr) | 0x00000002) - 4)
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
define|\
value|(ADDR_BITS_REMOVE (read_register (SRP_REGNUM)))
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

begin_comment
comment|/* instruction 0xF000D1FF is 'tb0 0,r0,511'    If Bit bit 0 of r0 is clear (always true),    initiate exception processing (trap).  */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0xF0, 0x00, 0xD1, 0xFF}
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
comment|/* 'jmp r1' or 'jmp.n r1' is used to return from a subroutine. */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
value|(read_memory_integer (pc, 2) == 0xF800)
end_define

begin_comment
comment|/* Return 1 if P points to an invalid floating point value.    LEN is the length in bytes.  */
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
value|IEEE_isNAN(p,len)
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
value|38
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{\  	"r0",\ 	"r1",\ 	"r2",\ 	"r3",\ 	"r4",\ 	"r5",\ 	"r6",\ 	"r7",\ 	"r8",\ 	"r9",\ 	"r10",\ 	"r11",\ 	"r12",\ 	"r13",\ 	"r14",\ 	"r15",\ 	"r16",\ 	"r17",\ 	"r18",\ 	"r19",\ 	"r20",\ 	"r21",\ 	"r22",\ 	"r23",\ 	"r24",\ 	"r25",\ 	"r26",\ 	"r27",\ 	"r28",\ 	"r29",\ 	"r30",\ 	"r31",\ 	"psr",\ 	"fpsr",\ 	"fpcr",\ 	"sxip",\ 	"snip",\ 	"sfip",\ 	"vbr",\ 	"dmt0",\ 	"dmd0",\ 	"dma0",\ 	"dmt1",\ 	"dmd1",\ 	"dma1",\ 	"dmt2",\ 	"dmd2",\ 	"dma2",\ 	"sr0",\ 	"sr1",\ 	"sr2",\ 	"sr3",\ 	"fpecr",\ 	"fphs1",\ 	"fpls1",\ 	"fphs2",\ 	"fpls2",\ 	"fppt",\ 	"fprh",\ 	"fprl",\ 	"fpit",\ 	"fpsr",\ 	"fpcr",\ 	}
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|SRP_REGNUM
value|1
end_define

begin_comment
comment|/* Contains subroutine return pointer */
end_comment

begin_define
define|#
directive|define
name|RV_REGNUM
value|2
end_define

begin_comment
comment|/* Contains simple return values */
end_comment

begin_define
define|#
directive|define
name|SRA_REGNUM
value|12
end_define

begin_comment
comment|/* Contains address of struct return values */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|31
end_define

begin_comment
comment|/* Reg fetched to locate frame when pgm stops */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|31
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|SXIP_REGNUM
value|35
end_define

begin_comment
comment|/* Contains Shadow Execute Instruction Pointer */
end_comment

begin_define
define|#
directive|define
name|SNIP_REGNUM
value|36
end_define

begin_comment
comment|/* Contains Shadow Next Instruction Pointer */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|SXIP_REGNUM
end_define

begin_comment
comment|/* Program Counter */
end_comment

begin_define
define|#
directive|define
name|NPC_REGNUM
value|SNIP_REGNUM
end_define

begin_comment
comment|/* Next Program Counter */
end_comment

begin_define
define|#
directive|define
name|PSR_REGNUM
value|32
end_define

begin_comment
comment|/* Processor Status Register */
end_comment

begin_define
define|#
directive|define
name|FPSR_REGNUM
value|33
end_define

begin_comment
comment|/* Floating Point Status Register */
end_comment

begin_define
define|#
directive|define
name|FPCR_REGNUM
value|34
end_define

begin_comment
comment|/* Floating Point Control Register */
end_comment

begin_define
define|#
directive|define
name|SFIP_REGNUM
value|37
end_define

begin_comment
comment|/* Contains Shadow Fetched Intruction pointer */
end_comment

begin_define
define|#
directive|define
name|NNPC_REGNUM
value|SFIP_REGNUM
end_define

begin_comment
comment|/* Next Next Program Counter */
end_comment

begin_comment
comment|/* PSR status bit definitions.  */
end_comment

begin_define
define|#
directive|define
name|PSR_MODE
value|0x80000000
end_define

begin_define
define|#
directive|define
name|PSR_BYTE_ORDER
value|0x40000000
end_define

begin_define
define|#
directive|define
name|PSR_SERIAL_MODE
value|0x20000000
end_define

begin_define
define|#
directive|define
name|PSR_CARRY
value|0x10000000
end_define

begin_define
define|#
directive|define
name|PSR_SFU_DISABLE
value|0x000003f0
end_define

begin_define
define|#
directive|define
name|PSR_SFU1_DISABLE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|PSR_MXM
value|0x00000004
end_define

begin_define
define|#
directive|define
name|PSR_IND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|PSR_SFRZ
value|0x00000001
end_define

begin_comment
comment|/* BCS requires that the SXIP_REGNUM (or PC_REGNUM) contain the address    of the next instr to be executed when a breakpoint occurs.  Because    the kernel gets the next instr (SNIP_REGNUM), the instr in SNIP needs    to be put back into SFIP, and the instr in SXIP should be shifted    to SNIP */
end_comment

begin_comment
comment|/* Are you sitting down?  It turns out that the 88K BCS (binary compatibility   standard) folks originally felt that the debugger should be responsible   for backing up the IPs, not the kernel (as is usually done).  Well, they   have reversed their decision, and in future releases our kernel will be   handling the backing up of the IPs.  So, eventually, we won't need to   do the SHIFT_INST_REGS stuff.  But, for now, since there are 88K systems out   there that do need the debugger to do the IP shifting, and since there   will be systems where the kernel does the shifting, the code is a little   more complex than perhaps it needs to be (we still go inside SHIFT_INST_REGS,   and if the shifting hasn't occurred then gdb goes ahead and shifts).  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_INST_REGS
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  */
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
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(NUM_REGS * REGISTER_RAW_SIZE(0))
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
value|((N)*REGISTER_RAW_SIZE(0))
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
value|(REGISTER_RAW_SIZE(N))
end_define

begin_comment
comment|/* Largest value REGISTER_RAW_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|(REGISTER_RAW_SIZE(0))
end_define

begin_comment
comment|/* Largest value REGISTER_VIRTUAL_SIZE can have. /* Are FPS1, FPS2, FPR "virtual" regisers? */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|(REGISTER_RAW_SIZE(0))
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
value|{bcopy ((FROM), (TO), REGISTER_RAW_SIZE (REGNUM));}
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
end_define

begin_block
block|{
name|bcopy
argument_list|(
operator|(
name|FROM
operator|)
argument_list|,
operator|(
name|TO
operator|)
argument_list|,
name|REGISTER_RAW_SIZE
argument_list|(
name|REGNUM
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_block

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
comment|/* The 88k call/return conventions call for "small" values to be returned    into consecutive registers starting from r2.  */
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
value|bcopy (&(((char *)REGBUF)[REGISTER_BYTE(RV_REGNUM)]), (VALBUF), TYPE_LENGTH (TYPE))
end_define

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
value|write_register_bytes (2*REGISTER_RAW_SIZE(0), (VALBUF), TYPE_LENGTH (TYPE))
end_define

begin_comment
comment|/* In COFF, if PCC says a parameter is a short or a char, do not    change it to int (it seems the convention is to change it). */
end_comment

begin_define
define|#
directive|define
name|BELIEVE_PCC_PROMOTION
value|1
end_define

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer.     However, if FRAME_CHAIN_VALID returns zero,    it means the given frame is the outermost one and has no caller.  */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|frame_chain
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|frame_chain_valid
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|frameless_function_invocation
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|frame_chain (thisframe)
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
name|FRAMELESS_FUNCTION_INVOCATION
parameter_list|(
name|frame
parameter_list|,
name|fromleaf
parameter_list|)
define|\
value|fromleaf = frameless_function_invocation (frame)
end_define

begin_comment
comment|/* Define other aspects of the stack frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
define|\
value|frame_saved_pc (FRAME)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|frame_saved_pc
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
define|\
value|frame_args_address (fi)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|frame_args_address
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
define|\
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
comment|/* On the 88k, parameter registers get stored into the so called "homing"    area.  This *always* happens when you compiled with GCC and use -g.    Also, (with GCC and -g) the saving of the parameter register values    always happens right within the function prologue code, so these register    values can generally be relied upon to be already copied into their    respective homing slots by the time you will normally try to look at    them (we hope).     Note that homing area stack slots are always at *positive* offsets from    the frame pointer.  Thus, the homing area stack slots for the parameter    registers (passed values) for a given function are actually part of the    frame area of the caller.  This is unusual, but it should not present    any special problems for GDB.     Note also that on the 88k, we are only interested in finding the    registers that might have been saved in memory.  This is a subset of    the whole set of registers because the standard calling sequence allows    the called routine to clobber many registers.     We could manage to locate values for all of the so called "preserved"    registers (some of which may get saved within any particular frame) but    that would require decoding all of the tdesc information.  Tht would be    nice information for GDB to have, but it is not strictly manditory if we    can live without the ability to look at values within (or backup to)    previous frames. */
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
value|frame_find_saved_regs (frame_info,&frame_saved_regs)
end_define

begin_escape
end_escape

begin_comment
comment|/* There is not currently a functioning way to call functions in the    inferior.  */
end_comment

begin_comment
comment|/* But if there was this is where we'd put the call dummy.  */
end_comment

begin_comment
comment|/* #define CALL_DUMMY_LOCATION AFTER_TEXT_END */
end_comment

begin_comment
comment|/* When popping a frame on the 88k (say when doing a return command), the    calling function only expects to have the "preserved" registers restored.    Thus, those are the only ones that we even try to restore here.   */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
value|pop_frame ()
end_define

begin_function_decl
specifier|extern
name|void
name|pop_frame
parameter_list|()
function_decl|;
end_function_decl

end_unit

