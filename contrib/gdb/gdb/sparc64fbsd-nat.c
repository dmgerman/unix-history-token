begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent code for FreeBSD/sparc64.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"sparc64-tdep.h"
end_include

begin_include
include|#
directive|include
file|"sparc-nat.h"
end_include

begin_comment
comment|/* Provide a prototype to silence -Wmissing-prototypes.  */
end_comment

begin_function_decl
name|void
name|_initialize_sparc64fbsd_nat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|_initialize_sparc64fbsd_nat
parameter_list|(
name|void
parameter_list|)
block|{
name|sparc_gregset
operator|=
operator|&
name|sparc64fbsd_gregset
expr_stmt|;
block|}
end_function

end_unit

