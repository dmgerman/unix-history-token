begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent code for the i387.    Copyright 2000, 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I387_NAT_H
end_ifndef

begin_define
define|#
directive|define
name|I387_NAT_H
end_define

begin_comment
comment|/* Fill register REGNUM in GDB's register array with the appropriate    value from *FSAVE.  This function masks off any of the reserved    bits in *FSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_supply_register
parameter_list|(
name|int
name|regnum
parameter_list|,
name|char
modifier|*
name|fsave
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fill GDB's register array with the floating-point register values    in *FSAVE.  This function masks off any of the reserved    bits in *FSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_supply_fsave
parameter_list|(
name|char
modifier|*
name|fsave
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fill register REGNUM (if it is a floating-point register) in *FSAVE    with the value in GDB's register array.  If REGNUM is -1, do this    for all registers.  This function doesn't touch any of the reserved    bits in *FSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_fill_fsave
parameter_list|(
name|char
modifier|*
name|fsave
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fill GDB's register array with the floating-point and SSE register    values in *FXSAVE.  This function masks off any of the reserved    bits in *FXSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_supply_fxsave
parameter_list|(
name|char
modifier|*
name|fxsave
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Fill register REGNUM (if it is a floating-point or SSE register) in    *FXSAVE with the value in GDB's register array.  If REGNUM is -1, do    this for all registers.  This function doesn't touch any of the    reserved bits in *FXSAVE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|i387_fill_fxsave
parameter_list|(
name|char
modifier|*
name|fxsave
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i387-nat.h */
end_comment

end_unit

