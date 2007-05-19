begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2001, 2005 Free Software Foundation, Inc.    Contributed by David Mosberger<davidm@hpl.hp.com>.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GCC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, if you link this library with other files,    some of which are compiled with GCC, to produce an executable,    this library does not by itself cause the resulting executable    to be covered by the GNU General Public License.    This exception does not however invalidate any other reasons why    the executable file might be covered by the GNU General Public License.  */
end_comment

begin_comment
comment|/* We could call fesetenv() here but that would create a confusing    dependency on libm (since that is where fesetenv() gets defined.    To avoid this, just do everything locally.  */
end_comment

begin_define
define|#
directive|define
name|FE_NONIEEE_ENV
value|0x0009a04d0270037f
end_define

begin_decl_stmt
specifier|static
name|void
name|__attribute__
argument_list|(
operator|(
name|constructor
operator|)
argument_list|)
name|__ia64_set_fast_math
argument_list|(
name|void
argument_list|)
block|{
asm|__asm__
specifier|__volatile__
asm|("mov.m ar.fpsr=%0" : : "r"(FE_NONIEEE_ENV));
block|}
end_decl_stmt

end_unit

