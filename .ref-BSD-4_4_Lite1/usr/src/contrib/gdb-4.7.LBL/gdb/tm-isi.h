begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to target GDB on an ISI Optimum V (3.05) under 4.3bsd.    Copyright (C) 1987, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This has not been tested on ISI's running BSD 4.2, but it will probably    work.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_68881
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
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|0xfffe000
end_define

begin_comment
comment|/* Data segment starts at etext rounded up to DATAROUND in {N,Z}MAGIC files */
end_comment

begin_define
define|#
directive|define
name|DATAROUND
value|0x20000
end_define

begin_define
define|#
directive|define
name|N_DATADDR
parameter_list|(
name|hdr
parameter_list|)
value|(hdr.a_magic != OMAGIC ? \ 	(hdr.a_text + DATAROUND)& ~(DATAROUND-1) : hdr.a_text)
end_define

begin_comment
comment|/* Text segment starts at sizeof (struct exec) in {N,Z}MAGIC files */
end_comment

begin_define
define|#
directive|define
name|N_TXTADDR
parameter_list|(
name|hdr
parameter_list|)
value|(hdr.a_magic != OMAGIC ? sizeof (struct exec) : 0)
end_define

begin_comment
comment|/* Amount PC must be decremented by after a breakpoint.    This is often the number of bytes in BREAKPOINT    but not always.    On the ISI, the kernel resets the pc to the trap instr */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

begin_escape
end_escape

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
define|\
value|{ register CORE_ADDR pc = FRAME_SAVED_PC (fi);			\   register int insn = 0177777& read_memory_integer (pc, 2);	\   val = 0;							\   if (insn == 0047757 || insn == 0157374)
comment|/* lea W(sp),sp or addaw #W,sp */
value|\     val = read_memory_integer (pc + 2, 2);			\   else if ((insn& 0170777) == 0050217
comment|/* addql #N, sp */
value|\ 	   || (insn& 0170777) == 0050117)
comment|/* addqw */
value|\     { val = (insn>> 9)& 7; if (val == 0) val = 8; }		\   else if (insn == 0157774)
comment|/* addal #WW, sp */
value|\     val = read_memory_integer (pc + 2, 4);			\   val>>= 2; }
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
value|{ register int regnum;							\   register int regmask;							\   register CORE_ADDR next_addr;						\   register CORE_ADDR pc;						\   register int insn;							\   register int offset;							\   bzero (&frame_saved_regs, sizeof frame_saved_regs);			\   if ((frame_info)->pc>= (frame_info)->frame - CALL_DUMMY_LENGTH - FP_REGNUM*4 - 8*12 - 4 \&& (frame_info)->pc<= (frame_info)->frame)				\     { next_addr = (frame_info)->frame;					\       pc = (frame_info)->frame - CALL_DUMMY_LENGTH - FP_REGNUM * 4 - 8*12 - 4; }\   else   								\     { pc = get_pc_function_start ((frame_info)->pc); 			\
comment|/* Verify we have a link a6 instruction next,			\ 	 or a branch followed by a link a6 instruction;			\ 	 if not we lose.  If we win, find the address above the saved   \ 	 regs using the amount of storage from the link instruction.  */
value|\ retry:									\       insn = read_memory_integer (pc, 2);				\       if (insn == 044016)						\ 	next_addr = (frame_info)->frame - read_memory_integer (pc += 2, 4), pc+=4; \       else if (insn == 047126)						\ 	next_addr = (frame_info)->frame - read_memory_integer (pc += 2, 2), pc+=2; \       else if ((insn& 0177400) == 060000)
comment|/* bra insn */
value|\ 	{ offset = insn& 0377;						\           pc += 2;
comment|/* advance past bra */
value|\ 	  if (offset == 0)
comment|/* bra #word */
value|\ 	    offset = read_memory_integer (pc, 2), pc += 2;		\ 	  else if (offset == 0377)
comment|/* bra #long */
value|\ 	    offset = read_memory_integer (pc, 4), pc += 4;		\ 	  pc += offset;							\ 	  goto retry;							\       } else goto lose;							\
comment|/* If have an addal #-n, sp next, adjust next_addr.  */
value|\       if ((0177777& read_memory_integer (pc, 2)) == 0157774)		\ 	next_addr += read_memory_integer (pc += 2, 4), pc += 4;		\     }									\
comment|/* next should be a moveml to (sp) or -(sp) or a movl r,-(sp) */
value|\   insn = read_memory_integer (pc, 2), pc += 2;				\   regmask = read_memory_integer (pc, 2);				\   if ((insn& 0177760) == 022700)
comment|/* movl rn, (sp) */
value|\     (frame_saved_regs).regs[(insn&7) + ((insn&010)?8:0)] = next_addr;	\   else if ((insn& 0177760) == 024700)
comment|/* movl rn, -(sp) */
value|\     (frame_saved_regs).regs[(insn&7) + ((insn&010)?8:0)] = next_addr-=4; \   else if (insn == 0044327)
comment|/* moveml mask, (sp) */
value|\     { pc += 2;								\
comment|/* Regmask's low bit is for register 0, the first written */
value|\       next_addr -= 4;							\       for (regnum = 0; regnum< 16; regnum++, regmask>>= 1)		\ 	if (regmask& 1)						\           (frame_saved_regs).regs[regnum] = (next_addr += 4);		\   } else if (insn == 0044347)
comment|/* moveml mask, -(sp) */
value|\     { pc += 2;								\
comment|/* Regmask's low bit is for register 15, the first pushed */
value|\       for (regnum = 15; regnum>= 0; regnum--, regmask>>= 1)		\ 	if (regmask& 1)						\           (frame_saved_regs).regs[regnum] = (next_addr -= 4); }		\
comment|/* clrw -(sp); movw ccr,-(sp) may follow.  */
value|\   if (read_memory_integer (pc, 2) == 041147 				\&& read_memory_integer (pc+2, 2) == 042347)			\     (frame_saved_regs).regs[PS_REGNUM] = (next_addr -= 4);		\   lose: ;								\   (frame_saved_regs).regs[SP_REGNUM] = (frame_info)->frame + 8;		\   (frame_saved_regs).regs[FP_REGNUM] = (frame_info)->frame;		\   (frame_saved_regs).regs[PC_REGNUM] = (frame_info)->frame + 4;		\ }
end_define

begin_comment
comment|/* The only reason this is here is the tm-isi.h reference below.  It    was moved back here from tm-68k.h.  FIXME? */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|pc
parameter_list|)
define|\
value|{ register int op = read_memory_integer (pc, 2);	\   if (op == 0047126)					\     pc += 4;
comment|/* Skip link #word */
value|\   else if (op == 0044016)				\     pc += 6;
comment|/* Skip link #long */
value|\
comment|/* Not sure why branches are here.  */
value|\
comment|/* From tm-isi.h, tm-altos.h */
value|\   else if (op == 0060000)				\     pc += 4;
comment|/* Skip bra #word */
value|\   else if (op == 00600377)				\     pc += 6;
comment|/* skip bra #long */
value|\   else if ((op& 0177400) == 0060000)			\     pc += 2;
comment|/* skip bra #char */
value|\ }
end_define

begin_include
include|#
directive|include
file|"tm-68k.h"
end_include

end_unit

