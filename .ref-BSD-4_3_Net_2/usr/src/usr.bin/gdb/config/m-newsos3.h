begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for execution on a Sony/NEWS with News-OS version 3,    for GDB, the GNU debugger.    Copyright (C) 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|NEWSOS3
end_define

begin_include
include|#
directive|include
file|"m-news.h"
end_include

begin_undef
undef|#
directive|undef
name|STACK_END_ADDR
end_undef

begin_comment
comment|/*<machine/vmparam.h> USRSTACK */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0x80000000 - UPAGES*NBPG)
end_define

begin_comment
comment|/* Have siginterupt on NEWS OS 3.x.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_SIGINTERRUPT
end_undef

begin_undef
undef|#
directive|undef
name|USE_PCB
end_undef

begin_comment
comment|/* now old ptrace bug has fixed almost.  Remain constrain is;      When some process do not touch the floating register,      ptrace cannot change the floating register containts. */
end_comment

begin_undef
undef|#
directive|undef
name|PTRACE_BUG
end_undef

begin_undef
undef|#
directive|undef
name|PUSH_DUMMY_FRAME
end_undef

begin_undef
undef|#
directive|undef
name|POP_FRAME
end_undef

begin_comment
comment|/* now ptrace has a bug to write floating register in NEWS OS version 2.x */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
define|\
value|{ register CORE_ADDR sp = read_register (SP_REGNUM);			\   register int regnum;							\   char raw_buffer[12];							\   sp = push_word (sp, read_register (PC_REGNUM));			\   sp = push_word (sp, read_register (FP_REGNUM));			\   write_register (FP_REGNUM, sp);					\   for (regnum = FP0_REGNUM + 7; regnum>= FP0_REGNUM; regnum--)		\     { read_register_bytes (REGISTER_BYTE (regnum), raw_buffer, 12);	\       sp = push_bytes (sp, raw_buffer, 12); }				\   for (regnum = FP_REGNUM - 1; regnum>= 0; regnum--)			\     sp = push_word (sp, read_register (regnum));			\   sp = push_word (sp, read_register (PS_REGNUM));			\   write_register (SP_REGNUM, sp);  }
end_define

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{ register FRAME frame = get_current_frame ();			 	\   register CORE_ADDR fp;					 	\   register int regnum;							\   struct frame_saved_regs fsr;						\   struct frame_info *fi;						\   char raw_buffer[12];							\   fi = get_frame_info (frame);					 	\   fp = fi->frame;						 	\   get_frame_saved_regs (fi,&fsr);					\   for (regnum = FP0_REGNUM + 7; regnum>= FP0_REGNUM; regnum--)		\     if (fsr.regs[regnum])						\       { read_memory (fsr.regs[regnum], raw_buffer, 12);			\         write_register_bytes (REGISTER_BYTE (regnum), raw_buffer, 12); }\   for (regnum = FP_REGNUM - 1; regnum>= 0; regnum--)			\     if (fsr.regs[regnum])						\       write_register (regnum, read_memory_integer (fsr.regs[regnum], 4)); \   if (fsr.regs[PS_REGNUM])						\     write_register (PS_REGNUM, read_memory_integer (fsr.regs[PS_REGNUM], 4)); \   write_register (FP_REGNUM, read_memory_integer (fp, 4));		\   write_register (PC_REGNUM, read_memory_integer (fp + 4, 4));  	\   write_register (SP_REGNUM, fp + 8);					\   flush_cached_frames ();					 	\   set_current_frame (create_new_frame (read_register (FP_REGNUM),	\ 				       read_pc ())); }
end_define

begin_comment
comment|/* NewsOS 3 apparently dies on large alloca's -- roland@ai.mit.edu.  */
end_comment

begin_define
define|#
directive|define
name|BROKEN_LARGE_ALLOCA
end_define

begin_comment
comment|/* Make this macro from peep of core file.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_U_ADDR
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_PCB
end_ifdef

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
value|{	blockend += 4;
comment|/* why? */
value|\         if (regno<= FP_REGNUM) \ 	  addr = blockend + regno * 4; \ 	else if (regno == SP_REGNUM) \ 	  addr = blockend - 4 - 4 * 4; \ 	else if (regno<= PS_REGNUM) \ 	  addr = blockend - 4 + (regno - PS_REGNUM) * 4; \ 	else if (regno< FPC_REGNUM) \ 	  addr = blockend + (14 + 1 + 3) * 4 + (regno - FP0_REGNUM) * 12; \ 	else \ 	  addr = blockend + 15 * 4 + (regno - FPC_REGNUM) * 4; \ }
end_define

begin_else
else|#
directive|else
end_else

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
value|{	blockend += 4;
comment|/* why? */
value|\ 	if (regno<= FP_REGNUM) \ 	  addr = blockend + regno * 4; \ 	else if (regno == SP_REGNUM) \ 	  addr = blockend -4 - 4 * 4; \ 	else if (regno<= PS_REGNUM) \ 	  addr = blockend - 4 + (regno - PS_REGNUM) * 4; \ 	else if (regno< FPC_REGNUM) \ 	  addr = blockend + (14 + 1 + 3) * 4 + (regno - FP0_REGNUM) * 12; \ 	else \ 	  addr = blockend + 15 * 4 + (regno - FPC_REGNUM) * 4; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

