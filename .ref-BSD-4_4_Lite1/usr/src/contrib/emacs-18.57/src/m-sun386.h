begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* m- file for Sun's 386-based RoadRunner.  This file borrows heavily from   "m-sun2.h", but since that file is heavily cpu-specific, it was easier   not to include it.  This file is part of GNU Emacs.  GNU Emacs is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU Emacs is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Emacs; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Say this machine is a bird */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|roadrunner
end_ifndef

begin_define
define|#
directive|define
name|roadrunner
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Actual cpu-specific defs */
end_comment

begin_include
include|#
directive|include
file|"m-intel386.h"
end_include

begin_comment
comment|/* Data type of load average, as read out of kmem.  */
end_comment

begin_define
define|#
directive|define
name|LOAD_AVE_TYPE
value|long
end_define

begin_comment
comment|/* Convert that into an integer that is 100 for a load average of 1.0  */
end_comment

begin_define
define|#
directive|define
name|LOAD_AVE_CVT
parameter_list|(
name|x
parameter_list|)
value|(int) (((double) (x)) * 100.0 / FSCALE)
end_define

begin_comment
comment|/* Underscores are not prepended to C symbols on this machine.  */
end_comment

begin_undef
undef|#
directive|undef
name|LDAV_SYMBOL
end_undef

begin_define
define|#
directive|define
name|LDAV_SYMBOL
value|"avenrun"
end_define

begin_comment
comment|/* Must use the system's termcap.  It does special things.  */
end_comment

begin_define
define|#
directive|define
name|LIBS_TERMCAP
value|-ltermcap
end_define

begin_comment
comment|/* Arrange to link with sun windows, if requested.  */
end_comment

begin_comment
comment|/* For details on emacstool and sunfns, see etc/SUN-SUPPORT */
end_comment

begin_comment
comment|/* These programs require Sun UNIX 4.2 Release 3.2 or greater */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SUN_WINDOWS
end_ifdef

begin_define
define|#
directive|define
name|OTHER_FILES
value|${etcdir}emacstool
end_define

begin_define
define|#
directive|define
name|LIBS_MACHINE
value|-lsuntool -lsunwindow -lpixrect
end_define

begin_define
define|#
directive|define
name|OBJECTS_MACHINE
value|sunfns.o
end_define

begin_define
define|#
directive|define
name|SYMS_MACHINE
value|syms_of_sunfns ()
end_define

begin_define
define|#
directive|define
name|PURESIZE
value|132000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Roadrunner uses 'COFF' format */
end_comment

begin_define
define|#
directive|define
name|COFF
end_define

begin_define
define|#
directive|define
name|C_SWITCH_MACHINE
value|-Bstatic
end_define

begin_comment
comment|/* avoid dynamic linking */
end_comment

begin_define
define|#
directive|define
name|LD_SWITCH_MACHINE
value|-n -Bstatic
end_define

begin_comment
comment|/* Get rid of the -e __start that s-sunos4.h does.  */
end_comment

begin_undef
undef|#
directive|undef
name|LD_SWITCH_SYSTEM
end_undef

end_unit

