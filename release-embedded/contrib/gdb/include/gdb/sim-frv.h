begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file defines the interface between the FR-V simulator and GDB.     Copyright 2003 Free Software Foundation, Inc.     Contributed by Red Hat.     This file is part of GDB.     This program is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     This program is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA    02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIM_FRV_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIM_FRV_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
comment|// }
endif|#
directive|endif
enum|enum
name|sim_frv_regs
block|{
name|SIM_FRV_GR0_REGNUM
init|=
literal|0
block|,
name|SIM_FRV_GR63_REGNUM
init|=
literal|63
block|,
name|SIM_FRV_FR0_REGNUM
init|=
literal|64
block|,
name|SIM_FRV_FR63_REGNUM
init|=
literal|127
block|,
name|SIM_FRV_PC_REGNUM
init|=
literal|128
block|,
comment|/* An FR-V architecture may have up to 4096 special purpose registers      (SPRs).  In order to determine a specific constant used to access      a particular SPR, one of the H_SPR_ prefixed offsets defined in      opcodes/frv-desc.h should be added to SIM_FRV_SPR0_REGNUM.  So,      for example, the number that GDB uses to fetch the link register      from the simulator is (SIM_FRV_SPR0_REGNUM + H_SPR_LR).  */
name|SIM_FRV_SPR0_REGNUM
init|=
literal|129
block|,
name|SIM_FRV_SPR4095_REGNUM
init|=
name|SIM_FRV_SPR0_REGNUM
operator|+
literal|4095
block|}
enum|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

