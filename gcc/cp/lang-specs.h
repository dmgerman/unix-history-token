begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for specs for C++.    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000,    2001, 2002, 2003, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* This is the contribution to the `default_compilers' array in gcc.c for    g++.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPLUSPLUS_CPP_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CPLUSPLUS_CPP_SPEC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_block
block|{
literal|".cc"
operator|,
literal|"@c++"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".cp"
operator|,
literal|"@c++"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".cxx"
operator|,
literal|"@c++"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".cpp"
operator|,
literal|"@c++"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".c++"
operator|,
literal|"@c++"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".C"
operator|,
literal|"@c++"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".CPP"
operator|,
literal|"@c++"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".H"
operator|,
literal|"@c++-header"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".hh"
operator|,
literal|"@c++-header"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"@c++-header"
operator|,
literal|"%{E|M|MM:cc1plus -E %(cpp_options) %2 %(cpp_debug_options)}\      %{!E:%{!M:%{!MM:\        %{save-temps|no-integrated-cpp:cc1plus -E\ 		%(cpp_options) %2 -o %{save-temps:%b.ii} %{!save-temps:%g.ii} \n}\       cc1plus %{save-temps|no-integrated-cpp:-fpreprocessed %{save-temps:%b.ii} %{!save-temps:%g.ii}}\ 	      %{!save-temps:%{!no-integrated-cpp:%(cpp_unique_options)}}\ 	%(cc1_options) %2 %{+e1*}\ 	%{!fsyntax-only:-o %g.s %{!o*:--output-pch=%i.gch} %W{o*:--output-pch=%*}%V}}}}"
operator|,
name|CPLUSPLUS_CPP_SPEC
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"@c++"
operator|,
literal|"%{E|M|MM:cc1plus -E %(cpp_options) %2 %(cpp_debug_options)}\      %{!E:%{!M:%{!MM:\        %{save-temps|no-integrated-cpp:cc1plus -E\ 		%(cpp_options) %2 -o %{save-temps:%b.ii} %{!save-temps:%g.ii} \n}\       cc1plus %{save-temps|no-integrated-cpp:-fpreprocessed %{save-temps:%b.ii} %{!save-temps:%g.ii}}\ 	      %{!save-temps:%{!no-integrated-cpp:%(cpp_unique_options)}}\ 	%(cc1_options) %2 %{+e1*}\        %{!fsyntax-only:%(invoke_as)}}}}"
operator|,
name|CPLUSPLUS_CPP_SPEC
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".ii"
operator|,
literal|"@c++-cpp-output"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"@c++-cpp-output"
operator|,
literal|"%{!M:%{!MM:%{!E:\     cc1plus -fpreprocessed %i %(cc1_options) %2 %{+e*}\     %{!fsyntax-only:%(invoke_as)}}}}"
operator|,
literal|0
operator|,
literal|0
operator|,
literal|0
block|}
end_block

begin_operator
operator|,
end_operator

end_unit

