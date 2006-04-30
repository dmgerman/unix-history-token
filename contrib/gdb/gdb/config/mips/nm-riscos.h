begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// OBSOLETE /* This program is free software; you can redistribute it and/or modify
end_comment

begin_comment
comment|// OBSOLETE    it under the terms of the GNU General Public License as published by
end_comment

begin_comment
comment|// OBSOLETE    the Free Software Foundation; either version 2 of the License, or
end_comment

begin_comment
comment|// OBSOLETE    (at your option) any later version.
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE    This program is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// OBSOLETE    but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// OBSOLETE    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// OBSOLETE    GNU General Public License for more details.
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE    You should have received a copy of the GNU General Public License
end_comment

begin_comment
comment|// OBSOLETE    along with this program; if not, write to the Free Software
end_comment

begin_comment
comment|// OBSOLETE    Foundation, Inc., 59 Temple Place - Suite 330,
end_comment

begin_comment
comment|// OBSOLETE    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* MIPS running RISC/os 4.52C.  */
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE #define PCB_OFFSET(FIELD) ((int)&((struct user*)0)->u_pcb.FIELD)
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* RISC/os 5.0 defines this in machparam.h.  */
end_comment

begin_comment
comment|// OBSOLETE #include<bsd43/machine/machparam.h>
end_comment

begin_comment
comment|// OBSOLETE #define NBPG BSD43_NBPG
end_comment

begin_comment
comment|// OBSOLETE #define UPAGES BSD43_UPAGES
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* Where is this used?  I don't see any uses in mips-nat.c, and I don't think
end_comment

begin_comment
comment|// OBSOLETE    the uses in infptrace.c are used if FETCH_INFERIOR_REGISTERS is defined.
end_comment

begin_comment
comment|// OBSOLETE    Does the compiler react badly to "extern CORE_ADDR kernel_u_addr" (even
end_comment

begin_comment
comment|// OBSOLETE    if never referenced)?  */
end_comment

begin_comment
comment|// OBSOLETE #define KERNEL_U_ADDR BSD43_UADDR
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE #define REGISTER_U_ADDR(addr, blockend, regno) 		\
end_comment

begin_comment
comment|// OBSOLETE 	      if (regno< FP0_REGNUM) \
end_comment

begin_comment
comment|// OBSOLETE 		  addr =  UPAGES*NBPG-EF_SIZE+4*((regno)+EF_AT-1); \
end_comment

begin_comment
comment|// OBSOLETE 	      else if (regno< PC_REGNUM) \
end_comment

begin_comment
comment|// OBSOLETE 		  addr = PCB_OFFSET(pcb_fpregs[0]) + 4*(regno-FP0_REGNUM); \
end_comment

begin_comment
comment|// OBSOLETE               else if (regno == PS_REGNUM) \
end_comment

begin_comment
comment|// OBSOLETE                   addr = UPAGES*NBPG-EF_SIZE+4*EF_SR; \
end_comment

begin_comment
comment|// OBSOLETE               else if (regno == mips_regnum (current_gdbarch)->badvaddr) \
end_comment

begin_comment
comment|// OBSOLETE   		  addr = UPAGES*NBPG-EF_SIZE+4*EF_BADVADDR; \
end_comment

begin_comment
comment|// OBSOLETE 	      else if (regno == mips_regnum (current_gdbarch)->lo) \
end_comment

begin_comment
comment|// OBSOLETE 		  addr = UPAGES*NBPG-EF_SIZE+4*EF_MDLO; \
end_comment

begin_comment
comment|// OBSOLETE 	      else if (regno == mips_regnum (current_gdbarch)->hi) \
end_comment

begin_comment
comment|// OBSOLETE 		  addr = UPAGES*NBPG-EF_SIZE+4*EF_MDHI; \
end_comment

begin_comment
comment|// OBSOLETE 	      else if (regno == mips_regnum (current_gdbarch)->cause) \
end_comment

begin_comment
comment|// OBSOLETE 		  addr = UPAGES*NBPG-EF_SIZE+4*EF_CAUSE; \
end_comment

begin_comment
comment|// OBSOLETE 	      else if (regno == mips_regnum (current_gdbarch)->pc) \
end_comment

begin_comment
comment|// OBSOLETE 		  addr = UPAGES*NBPG-EF_SIZE+4*EF_EPC; \
end_comment

begin_comment
comment|// OBSOLETE               else if (regno< mips_regnum (current_gdbarch)->fp_control_status) \
end_comment

begin_comment
comment|// OBSOLETE 		  addr = PCB_OFFSET(pcb_fpregs[0]) + 4*(regno-FP0_REGNUM); \
end_comment

begin_comment
comment|// OBSOLETE 	      else if (regno == mips_regnum (current_gdbarch)->fp_control_status) \
end_comment

begin_comment
comment|// OBSOLETE 		  addr = PCB_OFFSET(pcb_fpc_csr); \
end_comment

begin_comment
comment|// OBSOLETE 	      else if (regno == mips_regnum (current_gdbarch)->fp_implementation_revision) \
end_comment

begin_comment
comment|// OBSOLETE 		  addr = PCB_OFFSET(pcb_fpc_eir); \
end_comment

begin_comment
comment|// OBSOLETE               else \
end_comment

begin_comment
comment|// OBSOLETE                   addr = 0;
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE #include "mips/nm-mips.h"
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* Override copies of {fetch,store}_inferior_registers in infptrace.c.  */
end_comment

begin_comment
comment|// OBSOLETE #define FETCH_INFERIOR_REGISTERS
end_comment

end_unit

