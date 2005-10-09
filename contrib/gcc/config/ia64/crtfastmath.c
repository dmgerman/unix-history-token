begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 2001 Free Software Foundation, Inc.    Contributed by David Mosberger<davidm@hpl.hp.com>.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with the GNU C Library; see the file COPYING.LIB.  If not,    write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* In addition to the permissions in the GNU General Public License, the    Free Software Foundation gives you unlimited permission to link the    compiled version of this file into combinations with other programs,    and to distribute those combinations without any restriction coming    from the use of this file.  (The General Public License restrictions    do apply in other respects; for example, they cover modification of    the file, and distribution when not linked into a combine    executable.)  */
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

