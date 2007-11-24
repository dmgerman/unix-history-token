begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generic remote debugging interface for simulators.     Copyright 2002 Free Software Foundation, Inc.     Contributed by Red Hat, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIM_REGNO_H
end_ifndef

begin_define
define|#
directive|define
name|SIM_REGNO_H
end_define

begin_comment
comment|/* The REGISTER_SIM_REGNO(REGNUM) method, when there is a    corresponding simulator register, returns that register number as a    cardinal.  When there is no corresponding register, it returns a    negative value.  */
end_comment

begin_enum
enum|enum
name|sim_regno
block|{
comment|/* Normal sane architecture.  The simulator is known to not model      this register.  */
name|SIM_REGNO_DOES_NOT_EXIST
init|=
operator|-
literal|1
block|,
comment|/* For possible backward compatibility.  The register cache doesn't      have a corresponding name.  Skip the register entirely.  */
name|LEGACY_SIM_REGNO_IGNORE
init|=
operator|-
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/* Treat all raw registers as valid.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|one2one_register_sim_regno
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

