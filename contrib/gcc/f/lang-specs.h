begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lang-specs.h file for Fortran    Copyright (C) 1995, 1996, 1997, 1999, 2000 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is the contribution to the `default_compilers' array in gcc.c for    g77.  */
end_comment

begin_block
block|{
literal|".F"
operator|,
literal|"@f77-cpp-input"
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".fpp"
operator|,
literal|"@f77-cpp-input"
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".FPP"
operator|,
literal|"@f77-cpp-input"
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"@f77-cpp-input"
operator|,
literal|"tradcpp0 -lang-fortran %(cpp_options) %{!M:%{!MM:%{!E:%{!pipe:%g.f} |\n\     f771 %{!pipe:%g.f} %(cc1_options) %{I*} %{!fsyntax-only:%(invoke_as)}}}}"
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".r"
operator|,
literal|"@ratfor"
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"@ratfor"
operator|,
literal|"%{C:%{!E:%eGNU C does not support -C without using -E}}\     ratfor %{C} %{v} %i %{E:%W{o*}} %{!E: %{!pipe:-o %g.f} |\n\     f771 %{!pipe:%g.f} %(cc1_options) %{I*} %{!fsyntax-only:%(invoke_as)}}"
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".f"
operator|,
literal|"@f77"
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".for"
operator|,
literal|"@f77"
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".FOR"
operator|,
literal|"@f77"
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"@f77"
operator|,
literal|"%{!M:%{!MM:%{!E:f771 %i %(cc1_options) %{I*}\ 	%{!fsyntax-only:%(invoke_as)}}}}"
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

end_unit

