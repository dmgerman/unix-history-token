begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for NYU Ultracomputer 29000 target, for GDB, the GNU debugger.    Copyright 1990, 1991 Free Software Foundation, Inc.    Contributed by David Wood @ New York University (wood@nyu.edu).      This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This file includes tm-29k.h, but predefines REGISTER_NAMES and    related macros.  The file supports a 29k running our flavor of    Unix on our Ultra3 PE Boards.  */
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
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|(EXO_REGNUM + 1)
end_define

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{ 						 \  "gr1",									 \  "gr64", "gr65", "gr66", "gr67", "gr68", "gr69", "gr70", "gr71", "gr72", \  "gr73", "gr74", "gr75", "gr76", "gr77", "gr78", "gr79", "gr80", "gr81", \  "gr82", "gr83", "gr84", "gr85", "gr86", "gr87", "gr88", "gr89", "gr90", \  "gr91", "gr92", "gr93", "gr94", "gr95",				 \  "gr96", "gr97", "gr98", "gr99", "gr100", "gr101", "gr102", "gr103", "gr104", \  "gr105", "gr106", "gr107", "gr108", "gr109", "gr110", "gr111", "gr112", \  "gr113", "gr114", "gr115", "gr116", "gr117", "gr118", "gr119", "gr120", \  "gr121", "gr122", "gr123", "gr124", "gr125", "gr126", "gr127",		 \  "lr0", "lr1", "lr2", "lr3", "lr4", "lr5", "lr6", "lr7", "lr8", "lr9",   \  "lr10", "lr11", "lr12", "lr13", "lr14", "lr15", "lr16", "lr17", "lr18", \  "lr19", "lr20", "lr21", "lr22", "lr23", "lr24", "lr25", "lr26", "lr27", \  "lr28", "lr29", "lr30", "lr31", "lr32", "lr33", "lr34", "lr35", "lr36", \  "lr37", "lr38", "lr39", "lr40", "lr41", "lr42", "lr43", "lr44", "lr45", \  "lr46", "lr47", "lr48", "lr49", "lr50", "lr51", "lr52", "lr53", "lr54", \  "lr55", "lr56", "lr57", "lr58", "lr59", "lr60", "lr61", "lr62", "lr63", \  "lr64", "lr65", "lr66", "lr67", "lr68", "lr69", "lr70", "lr71", "lr72", \  "lr73", "lr74", "lr75", "lr76", "lr77", "lr78", "lr79", "lr80", "lr81", \  "lr82", "lr83", "lr84", "lr85", "lr86", "lr87", "lr88", "lr89", "lr90", \  "lr91", "lr92", "lr93", "lr94", "lr95", "lr96", "lr97", "lr98", "lr99", \  "lr100", "lr101", "lr102", "lr103", "lr104", "lr105", "lr106", "lr107", \  "lr108", "lr109", "lr110", "lr111", "lr112", "lr113", "lr114", "lr115", \  "lr116", "lr117", "lr118", "lr119", "lr120", "lr121", "lr122", "lr123", \  "lr124", "lr125", "lr126", "lr127",					 \  "vab", "ops", "cps", "cfg", "cha", "chd", "chc", "rbp", "tmc", "tmr",	 \  "pc0", "pc1", "pc2", "mmu", "lru",					 \  "ipc", "ipa", "ipb", "q", "alu", "bp", "fc", "cr",			 \  "fpe", "int", "fps", "exo" }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_DEBUGGING
end_ifdef

begin_define
define|#
directive|define
name|PADDR_U_REGNUM
value|22
end_define

begin_comment
comment|/* gr86 */
end_comment

begin_define
define|#
directive|define
name|RETURN_REGNUM
value|GR64_REGNUM
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|RETURN_REGNUM
value|GR96_REGNUM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_DEBUGGING */
end_comment

begin_comment
comment|/* Should rename all GR96_REGNUM to RETURN_REGNUM */
end_comment

begin_define
define|#
directive|define
name|GR1_REGNUM
value|(0)
end_define

begin_define
define|#
directive|define
name|GR64_REGNUM
value|1
end_define

begin_define
define|#
directive|define
name|GR96_REGNUM
value|(GR64_REGNUM + 32)
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
value|(LR0_REGNUM + 1)
end_define

begin_comment
comment|/* lr1 */
end_comment

begin_comment
comment|/* Large Return Pointer  */
end_comment

begin_define
define|#
directive|define
name|LRP_REGNUM
value|(123 - 96 + RETURN_REGNUM)
end_define

begin_comment
comment|/* Static link pointer   */
end_comment

begin_define
define|#
directive|define
name|SLP_REGNUM
value|(124 - 96 + RETURN_REGNUM)
end_define

begin_comment
comment|/* Memory Stack Pointer.  */
end_comment

begin_define
define|#
directive|define
name|MSP_REGNUM
value|(125 - 96 + RETURN_REGNUM)
end_define

begin_comment
comment|/* Register allocate bound.  */
end_comment

begin_define
define|#
directive|define
name|RAB_REGNUM
value|(126 - 96 + RETURN_REGNUM)
end_define

begin_comment
comment|/* Register Free Bound.  */
end_comment

begin_define
define|#
directive|define
name|RFB_REGNUM
value|(127 - 96 + RETURN_REGNUM)
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
value|( 32 +  GR96_REGNUM)
end_define

begin_comment
comment|/* Protected Special registers */
end_comment

begin_define
define|#
directive|define
name|VAB_REGNUM
value|(LR0_REGNUM +  128)
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

begin_comment
comment|/* pc2 */
end_comment

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

begin_comment
comment|/* Register sequence gap */
end_comment

begin_comment
comment|/* Unprotected Special registers */
end_comment

begin_define
define|#
directive|define
name|IPC_REGNUM
value|(LRU_REGNUM + 1)
end_define

begin_define
define|#
directive|define
name|IPA_REGNUM
value|(IPC_REGNUM + 1)
end_define

begin_define
define|#
directive|define
name|IPB_REGNUM
value|(IPC_REGNUM + 2)
end_define

begin_define
define|#
directive|define
name|Q_REGNUM
value|(IPC_REGNUM + 3)
end_define

begin_define
define|#
directive|define
name|ALU_REGNUM
value|(IPC_REGNUM + 4)
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
name|BP_REGNUM
value|(IPC_REGNUM + 5)
end_define

begin_define
define|#
directive|define
name|FC_REGNUM
value|(IPC_REGNUM + 6)
end_define

begin_define
define|#
directive|define
name|CR_REGNUM
value|(IPC_REGNUM + 7)
end_define

begin_comment
comment|/* Register sequence gap */
end_comment

begin_define
define|#
directive|define
name|FPE_REGNUM
value|(CR_REGNUM  + 1)
end_define

begin_define
define|#
directive|define
name|INT_REGNUM
value|(FPE_REGNUM + 1)
end_define

begin_define
define|#
directive|define
name|FPS_REGNUM
value|(FPE_REGNUM + 2)
end_define

begin_comment
comment|/* Register sequence gap */
end_comment

begin_define
define|#
directive|define
name|EXO_REGNUM
value|(FPS_REGNUM + 1)
end_define

begin_comment
comment|/* Special register #x.  */
end_comment

begin_define
define|#
directive|define
name|SR_REGNUM
parameter_list|(
name|x
parameter_list|)
define|\
value|((x)< 15  ? VAB_REGNUM + (x)					 \    : (x)>= 128&& (x)< 136 ? IPC_REGNUM + (x-128)		 \    : (x)>= 160&& (x)< 163 ? FPE_REGNUM + (x-160)		 \    : (x) == 164 ? EXO_REGNUM                                     \    : (error ("Internal error in SR_REGNUM"), 0))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|KERNEL_DEBUGGING
end_ifndef

begin_comment
comment|/*  * This macro defines the register numbers (from REGISTER_NAMES) that  * are effectively unavailable to the user through ptrace().  It allows   * us to include the whole register set in REGISTER_NAMES (inorder to   * better support remote debugging).  If it is used in   * fetch/store_inferior_registers() gdb will not complain about I/O errors   * on fetching these registers.  If all registers in REGISTER_NAMES  * are available, then return false (0).  */
end_comment

begin_define
define|#
directive|define
name|CANNOT_STORE_REGISTER
parameter_list|(
name|regno
parameter_list|)
define|\
value|(((regno)>=GR64_REGNUM&& (regno)<GR64_REGNUM+32) ||	\                    ((regno)==VAB_REGNUM) ||	\ 		   ((regno)==OPS_REGNUM) ||	\                    ((regno)>=CFG_REGNUM&& (regno)<=TMR_REGNUM)     ||	\                    ((regno)==MMU_REGNUM) ||	\ 		   ((regno)==LRU_REGNUM) ||	\                    ((regno)>=ALU_REGNUM) ||	\                    ((regno)==CR_REGNUM)  ||	\ 		   ((regno)==EXO_REGNUM))
end_define

begin_define
define|#
directive|define
name|CANNOT_FETCH_REGISTER
parameter_list|(
name|regno
parameter_list|)
value|CANNOT_STORE_REGISTER(regno)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL_DEBUGGING */
end_comment

begin_comment
comment|/*  * Converts an sdb register number to an internal gdb register number.  * Currently under gcc, gr96->0...gr128->31...lr0->32...lr127->159, or...  * 		  	gr64->0...gr95->31, lr0->32...lr127->159.  */
end_comment

begin_define
define|#
directive|define
name|SDB_REG_TO_REGNUM
parameter_list|(
name|value
parameter_list|)
value|(((value)<32) ? ((value)+RETURN_REGNUM) : \ 		 		                 ((value)-32+LR0_REGNUM))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL_DEBUGGING
end_ifdef

begin_comment
comment|/* ublock virtual address as defined in our sys/param.h */
end_comment

begin_comment
comment|/* FIXME: Should get this from sys/param.h */
end_comment

begin_define
define|#
directive|define
name|UVADDR
value|((32*0x100000)-8192)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Are we in sigtramp(), needed in infrun.c.  Specific to ultra3, because  * we take off the leading '_'.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KERNEL_DEBUGGING
argument_list|)
end_if

begin_ifdef
ifdef|#
directive|ifdef
name|SYM1
end_ifdef

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|(name&& !strcmp ("sigtramp", name))
end_define

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|Need
name|to
name|define
name|IN_SIGTRAMP
argument_list|()
end_expr_stmt

begin_for
for|for sym2.
endif|#
directive|endif
endif|#
directive|endif
comment|/* !KERNEL_DEBUGGING */
include|#
directive|include
file|"tm-29k.h"
comment|/**** The following are definitions that override those in tm-29k.h ****/
comment|/* This sequence of words is the instructions    mtsrim cr, 15    loadm 0, 0, lr2, msp     ; load first 16 words of arguments into registers    add msp, msp, 16 * 4     ; point to the remaining arguments   CONST_INSN:    const gr96,inf    consth gr96,inf    calli lr0, gr96    aseq 0x40,gr1,gr1   ; nop    asneq 0x50,gr1,gr1  ; breakpoint    When KERNEL_DEBUGGIN is defined, msp -> gr93, gr96 -> gr64,                                     7d  -> 5d,    60  -> 40    */
comment|/* Position of the "const" instruction within CALL_DUMMY in bytes.  */
undef|#
directive|undef
name|CALL_DUMMY
if|#
directive|if
name|TARGET_BYTE_ORDER
operator|==
name|HOST_BYTE_ORDER
ifdef|#
directive|ifdef
name|KERNEL_DEBUGGING
comment|/* gr96 -> gr64 */
define|#
directive|define
name|CALL_DUMMY
value|{0x0400870f, 0x3600825d, 0x155d5d40, 0x03ff40ff,    \                     0x02ff40ff, 0xc8008040, 0x70400101, 0x72500101}
else|#
directive|else
define|#
directive|define
name|CALL_DUMMY
value|{0x0400870f, 0x3600827d, 0x157d7d40, 0x03ff60ff,    \                     0x02ff60ff, 0xc8008060, 0x70400101, 0x72500101}
endif|#
directive|endif
comment|/* KERNEL_DEBUGGING */
else|#
directive|else
comment|/* Byte order differs.  */
for|you lose
endif|#
directive|endif
comment|/* Byte order differs.  */
if|#
directive|if
operator|!
name|defined
argument_list|(
name|KERNEL_DEBUGGING
argument_list|)
ifdef|#
directive|ifdef
name|SYM1
undef|#
directive|undef
name|DECR_PC_AFTER_BREAK
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
comment|/* Sym1 kernel does the decrement */
else|#
directive|else
for|->"ULTRA3 running other than sym1 OS"!
empty_stmt|;
end_for

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL_DEBUGGING */
end_comment

end_unit

