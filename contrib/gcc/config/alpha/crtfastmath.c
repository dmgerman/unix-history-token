begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2001 Free Software Foundation, Inc.  * Contributed by Richard Henderson (rth@redhat.com)  *  * This file is free software; you can redistribute it and/or modify it  * under the terms of the GNU General Public License as published by the  * Free Software Foundation; either version 2, or (at your option) any  * later version.  *   * In addition to the permissions in the GNU General Public License, the  * Free Software Foundation gives you unlimited permission to link the  * compiled version of this file with other programs, and to distribute  * those programs without any restriction coming from the use of this  * file.  (The General Public License restrictions do apply in other  * respects; for example, they cover modification of the file, and  * distribution when not linked into another program.)  *   * This file is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; see the file COPYING.  If not, write to  * the Free Software Foundation, 59 Temple Place - Suite 330,  * Boston, MA 02111-1307, USA.  *   *    As a special exception, if you link this library with files  *    compiled with GCC to produce an executable, this does not cause  *    the resulting executable to be covered by the GNU General Public License.  *    This exception does not however invalidate any other reasons why  *    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_comment
comment|/* Assume OSF/1 compatible interfaces.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__ieee_set_fp_control
parameter_list|(
name|unsigned
name|long
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IEEE_MAP_DMZ
value|(1UL<<12)
end_define

begin_comment
comment|/* Map denorm inputs to zero */
end_comment

begin_define
define|#
directive|define
name|IEEE_MAP_UMZ
value|(1UL<<13)
end_define

begin_comment
comment|/* Map underflowed outputs to zero */
end_comment

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|constructor
operator|)
argument_list|)
name|set_fast_math
argument_list|(
name|void
argument_list|)
block|{
name|__ieee_set_fp_control
argument_list|(
name|IEEE_MAP_DMZ
operator||
name|IEEE_MAP_UMZ
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

end_unit

