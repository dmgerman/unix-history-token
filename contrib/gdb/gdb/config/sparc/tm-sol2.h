begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target-dependent definitions for Solaris SPARC.     Copyright 2003 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_SOL2_H
end_ifndef

begin_define
define|#
directive|define
name|TM_SOL2_H
end_define

begin_define
define|#
directive|define
name|GDB_MULTI_ARCH
value|GDB_MULTI_ARCH_TM
end_define

begin_comment
comment|/* The Sun compilers (Sun ONE Studio, Forte Developer, Sun WorkShop,    SunPRO) compiler puts out 0 instead of the address in N_SO stabs.    Starting with SunPRO 3.0, the compiler does this for N_FUN stabs    too.  */
end_comment

begin_define
define|#
directive|define
name|SOFUN_ADDRESS_MAYBE_MISSING
end_define

begin_comment
comment|/* The Sun compilers also do "globalization"; see the comment in    sparc-tdep.c for more information.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|sparc_stabs_unglobalize_name
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|STATIC_TRANSFORM_NAME
parameter_list|(
name|name
parameter_list|)
define|\
value|sparc_stabs_unglobalize_name (name)
end_define

begin_define
define|#
directive|define
name|IS_STATIC_TRANSFORM_NAME
parameter_list|(
name|name
parameter_list|)
define|\
value|((name) != sparc_stabs_unglobalize_name (name))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tm-sol2.h */
end_comment

end_unit

