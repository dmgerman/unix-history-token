begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for specs for Objective-C.    Copyright (C) 1998, 1999, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is the contribution to the `default_compilers' array in gcc.c for    objc.  */
end_comment

begin_block
block|{
literal|".m"
operator|,
block|{
literal|"@objective-c"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"@objective-c"
operator|,
if|#
directive|if
name|USE_CPPLIB
block|{
literal|"%{E|M|MM:cpp0 -lang-objc %{nostdinc*} %{C} %{v} %{A*} %{I*} %{P} %{$} %I\ 	%{C:%{!E:%eGNU C does not support -C without using -E}}\ 	%{M} %{MM} %{MD:-MD %b.d} %{MMD:-MMD %b.d} %{MG}\         -D__OBJC__ %{!no-gcc:-D__GNUC__=%v1 -D__GNUC_MINOR__=%v2}\ 	%{ansi:-trigraphs -D__STRICT_ANSI__}\ 	%{!undef:%{!ansi:%p} %P} %{trigraphs}\         %c %{Os:-D__OPTIMIZE_SIZE__} %{O*:%{!O0:-D__OPTIMIZE__}}\ 	%{ffast-math:-D__FAST_MATH__}\         %{traditional} %{ftraditional:-traditional}\         %{traditional-cpp:-traditional}\ 	%{fleading-underscore} %{fno-leading-underscore}\ 	%{g*} %{W*} %{w} %{pedantic*} %{H} %{d*} %C %{D*} %{U*} %{i*} %Z\         %i %{E:%W{o*}}%{M:%W{o*}}%{MM:%W{o*}}\n}"
block|,
literal|"%{!M:%{!MM:%{!E:cc1obj %i %1 \ 		   %{nostdinc*} %{A*} %{I*} %{P} %I\                    %{MD:-MD %b.d} %{MMD:-MMD %b.d} %{MG}\ 		   -D__OBJC__ %{!no-gcc:-D__GNUC__=%v1 -D__GNUC_MINOR__=%v2}\ 		   %{!undef:%{!ansi:%p} %P} %{trigraphs}\ 		   %c %{Os:-D__OPTIMIZE_SIZE__} %{O*:%{!O0:-D__OPTIMIZE__}}\ 		   %{ffast-math:-D__FAST_MATH__}\ 		   %{!Q:-quiet} -dumpbase %b.m %{d*} %{m*} %{a*}\ 		   %{g*} %{O*} %{W*} %{w} %{pedantic*} %{ansi} \ 		   %{traditional} %{v:-version} %{pg:-p} %{p} %{f*} \     		   -lang-objc %{gen-decls} \ 		   %{aux-info*} %{Qn:-fno-ident}\ 		   %{pg:%{fomit-frame-pointer:%e-pg and -fomit-frame-pointer are incompatible}}\ 		   %{S:%W{o*}%{!o*:-o %b.s}}%{!S:-o %{|!pipe:%g.s}} |\n\      %{!S:as %a %Y\ 	%{c:%W{o*}%{!o*:-o %w%b%O}}%{!c:-o %d%w%u%O}\         %{!pipe:%g.s} %A\n }}}}"
block|}
else|#
directive|else
comment|/* ! USE_CPPLIB */
block|{
literal|"cpp0 -lang-objc %{nostdinc*} %{C} %{v} %{A*} %{I*} %{P} %{$} %I\ 	%{C:%{!E:%eGNU C does not support -C without using -E}}\ 	%{M} %{MM} %{MD:-MD %b.d} %{MMD:-MMD %b.d} %{MG}\         -D__OBJC__ %{!no-gcc:-D__GNUC__=%v1 -D__GNUC_MINOR__=%v2}\ 	 %{ansi:-trigraphs -D__STRICT_ANSI__}\ 	%{!undef:%{!ansi:%p} %P} %{trigraphs}\         %c %{Os:-D__OPTIMIZE_SIZE__} %{O*:%{!O0:-D__OPTIMIZE__}}\ 	%{ffast-math:-D__FAST_MATH__}\         %{traditional} %{ftraditional:-traditional}\         %{traditional-cpp:-traditional}\ 	%{fleading-underscore} %{fno-leading-underscore}\ 	%{g*} %{W*} %{w} %{pedantic*} %{H} %{d*} %C %{D*} %{U*} %{i*} %Z\         %i %{!M:%{!MM:%{!E:%{!pipe:%g.mi}}}}%{E:%W{o*}}%{M:%W{o*}}%{MM:%W{o*}} |\n"
block|,
literal|"%{!M:%{!MM:%{!E:cc1obj %{!pipe:%g.mi} %1 \ 		   %{!Q:-quiet} -dumpbase %b.m %{d*} %{m*} %{a*}\ 		   %{g*} %{O*} %{W*} %{w} %{pedantic*} %{ansi} \ 		   %{traditional} %{v:-version} %{pg:-p} %{p} %{f*} \     		   -lang-objc %{gen-decls} \ 		   %{aux-info*} %{Qn:-fno-ident}\ 		   %{pg:%{fomit-frame-pointer:%e-pg and -fomit-frame-pointer are incompatible}}\ 		   %{S:%W{o*}%{!o*:-o %b.s}}%{!S:-o %{|!pipe:%g.s}} |\n\               %{!S:as %a %Y\ 		      %{c:%W{o*}%{!o*:-o %w%b%O}}%{!c:-o %d%w%u%O}\                       %{!pipe:%g.s} %A\n }}}}"
block|}
endif|#
directive|endif
comment|/* ! USE_CPPLIB */
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|".mi"
operator|,
block|{
literal|"@objc-cpp-output"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
block|{
literal|"@objc-cpp-output"
operator|,
block|{
literal|"%{!M:%{!MM:%{!E:cc1obj %i %1 \ 		   %{!Q:-quiet} -dumpbase %b.m %{d*} %{m*} %{a*}\ 		   %{g*} %{O*} %{W*} %{w} %{pedantic*} %{ansi} \ 		   %{traditional} %{v:-version} %{pg:-p} %{p} %{f*} \     		   -lang-objc %{gen-decls} \ 		   %{aux-info*} %{Qn:-fno-ident}\ 		   %{pg:%{fomit-frame-pointer:%e-pg and -fomit-frame-pointer are incompatible}}\ 		   %{S:%W{o*}%{!o*:-o %b.s}}%{!S:-o %{|!pipe:%g.s}} |\n"
block|,
literal|"%{!S:as %a %Y\ 	%{c:%W{o*}%{!o*:-o %w%b%O}}%{!c:-o %d%w%u%O}\         %{!pipe:%g.s} %A\n }}}}"
block|}
block|}
end_block

begin_operator
operator|,
end_operator

end_unit

