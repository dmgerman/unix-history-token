begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for specs for C++.    Copyright (C) 1995, 1996, 1997, 1998, 1999, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is the contribution to the `default_compilers' array in gcc.c for    g++.  */
end_comment

begin_block
block|{
literal|".cc"
operator|,
block|{
literal|"@c++"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".cp"
operator|,
block|{
literal|"@c++"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".cxx"
operator|,
block|{
literal|"@c++"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".cpp"
operator|,
block|{
literal|"@c++"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".c++"
operator|,
block|{
literal|"@c++"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".C"
operator|,
block|{
literal|"@c++"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"@c++"
operator|,
if|#
directive|if
name|USE_CPPLIB
block|{
literal|"%{E|M|MM:cpp0 -lang-c++ %{nostdinc*} %{C} %{v} %{A*} %{I*} %{P} %{$} %I\ 	%{C:%{!E:%eGNU C++ does not support -C without using -E}}\ 	%{M} %{MM} %{MD:-MD %b.d} %{MMD:-MMD %b.d} %{MG}\ 	%{!no-gcc:-D__GNUC__=%v1 -D__GNUG__=%v1 -D__GNUC_MINOR__=%v2}\ 	-D__cplusplus\ 	%{ansi:-trigraphs -D__STRICT_ANSI__} %{!undef:%{!ansi:%p} %P}\ 	%{!fno-exceptions:-D__EXCEPTIONS}\         %c %{Os:-D__OPTIMIZE_SIZE__} %{O*:%{!O0:-D__OPTIMIZE__}} %{trigraphs}\ 	%{ffast-math:-D__FAST_MATH__}\ 	%{g*} %{W*} %{w} %{pedantic*} %{H} %{d*} %C %{D*} %{U*} %{i*} %Z\         %i %{E:%W{o*}}%{M:%W{o*}}%{MM:%W{o*}}\n}\       %{!E:%{!M:%{!MM:cc1plus %i %1 %2\                             -lang-c++ %{nostdinc*} %{C} %{A*} %{I*} %{P} %{$} %I\                             %{MD:-MD %b.d} %{MMD:-MMD %b.d} %{MG}\                             %{!no-gcc:-D__GNUC__=%v1 -D__GNUG__=%v1\                             -D__GNUC_MINOR__=%v2} -D__cplusplus\                             %{ansi:-trigraphs -D__STRICT_ANSI__} %{!undef:%{!ansi:%p} %P}\                             %{!fno-exceptions:-D__EXCEPTIONS}\                             %c %{Os:-D__OPTIMIZE_SIZE__} %{O*:%{!O0:-D__OPTIMIZE__}}\ 			    %{ffast-math:-D__FAST_MATH__}\                             %{trigraphs}\ 			    %{!Q:-quiet} -dumpbase %b.cc %{d*} %{m*} %{a}\ 			    %{g*} %{O*} %{W*} %{w} %{pedantic*} %{ansi}\                             %{H} %{d*} %C %{D*} %{U*} %{i*} %Z\ 			    %{v:-version} %{pg:-p} %{p}\ 			    %{f*} %{+e*} %{aux-info*} %{Qn:-fno-ident}\ 			    %{pg:%{fomit-frame-pointer:%e-pg and -fomit-frame-pointer are incompatible}}\ 			    %{S:%W{o*}%{!o*:-o %b.s}}%{!S:-o %{|!pipe:%g.s}}|\n\               %{!S:as %a %Y\ 		      %{c:%W{o*}%{!o*:-o %w%b%O}}%{!c:-o %d%w%u%O}\                       %{!pipe:%g.s} %A\n }}}}"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* ! USE_CPPLIB */
end_comment

begin_block
block|{
literal|"cpp0 -lang-c++ %{nostdinc*} %{C} %{v} %{A*} %{I*} %{P} %{$} %I\ 	%{C:%{!E:%eGNU C++ does not support -C without using -E}}\ 	%{M} %{MM} %{MD:-MD %b.d} %{MMD:-MMD %b.d} %{MG}\ 	%{!no-gcc:-D__GNUC__=%v1 -D__GNUG__=%v1 -D__GNUC_MINOR__=%v2}\ 	-D__cplusplus\ 	%{ansi:-trigraphs -D__STRICT_ANSI__} %{!undef:%{!ansi:%p} %P}\ 	%{!fno-exceptions:-D__EXCEPTIONS}\         %c %{Os:-D__OPTIMIZE_SIZE__} %{O*:%{!O0:-D__OPTIMIZE__}} %{trigraphs}\ 	%{ffast-math:-D__FAST_MATH__}\ 	%{g*} %{W*} %{w} %{pedantic*} %{H} %{d*} %C %{D*} %{U*} %{i*} %Z\         %i %{!M:%{!MM:%{!E:%{!pipe:%g.ii}}}}%{E:%W{o*}}%{M:%W{o*}}%{MM:%W{o*}} |\n"
operator|,
literal|"%{!M:%{!MM:%{!E:cc1plus %{!pipe:%g.ii} %1 %2\ 			    %{!Q:-quiet} -dumpbase %b.cc %{d*} %{m*} %{a}\ 			    %{g*} %{O*} %{W*} %{w} %{pedantic*} %{ansi}\ 			    %{v:-version} %{pg:-p} %{p}\ 			    %{f*} %{+e*} %{aux-info*} %{Qn:-fno-ident}\ 			    %{pg:%{fomit-frame-pointer:%e-pg and -fomit-frame-pointer are incompatible}}\ 			    %{S:%W{o*}%{!o*:-o %b.s}}%{!S:-o %{|!pipe:%g.s}}|\n\               %{!S:as %a %Y\ 		      %{c:%W{o*}%{!o*:-o %w%b%O}}%{!c:-o %d%w%u%O}\                       %{!pipe:%g.s} %A\n }}}}"
block|}
end_block

begin_endif
unit|},
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! USE_CPPLIB */
end_comment

begin_block
block|{
literal|".ii"
operator|,
block|{
literal|"@c++-cpp-output"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"@c++-cpp-output"
operator|,
block|{
literal|"%{!M:%{!MM:%{!E:cc1plus %i %1 %2 %{!Q:-quiet} %{d*} %{m*} %{a}\ 			    %{g*} %{O*} %{W*} %{w} %{pedantic*} %{ansi}\ 			    %{v:-version} %{pg:-p} %{p}\ 			    %{f*} %{+e*} %{aux-info*} %{Qn:-fno-ident}\ 			    %{pg:%{fomit-frame-pointer:%e-pg and -fomit-frame-pointer are incompatible}}\ 			    %{S:%W{o*}%{!o*:-o %b.s}}%{!S:-o %{|!pipe:%g.s}} |\n\ 	            %{!S:as %a %Y\ 			    %{c:%W{o*}%{!o*:-o %w%b%O}}%{!c:-o %d%w%u%O}\ 			    %{!pipe:%g.s} %A\n }}}}"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

end_unit

