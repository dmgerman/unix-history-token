begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Software floating-point emulation.    Convert a 64bit unsigned integer to IEEE double    Copyright (C) 1997,1999, 2006 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Richard Henderson (rth@cygnus.com) and 		  Jakub Jelinek (jj@ultra.linux.cz).     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     In addition to the permissions in the GNU Lesser General Public    License, the Free Software Foundation gives you unlimited    permission to link the compiled version of this file into    combinations with other programs, and to distribute those    combinations without any restriction coming from the use of this    file.  (The Lesser General Public License restrictions do apply in    other respects; for example, they cover modification of the file,    and distribution when not linked into a combine executable.)     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, write to the Free    Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"soft-fp.h"
end_include

begin_include
include|#
directive|include
file|"double.h"
end_include

begin_function
name|double
name|__floatundidf
parameter_list|(
name|UDItype
name|i
parameter_list|)
block|{
name|FP_DECL_EX
expr_stmt|;
name|FP_DECL_D
argument_list|(
name|A
argument_list|)
expr_stmt|;
name|DFtype
name|a
decl_stmt|;
name|FP_FROM_INT_D
argument_list|(
name|A
argument_list|,
name|i
argument_list|,
name|DI_BITS
argument_list|,
name|UDItype
argument_list|)
expr_stmt|;
name|FP_PACK_RAW_D
argument_list|(
name|a
argument_list|,
name|A
argument_list|)
expr_stmt|;
name|FP_HANDLE_EXCEPTIONS
expr_stmt|;
return|return
name|a
return|;
block|}
end_function

end_unit

