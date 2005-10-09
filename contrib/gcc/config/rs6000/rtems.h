begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for rtems targeting a PowerPC using elf.    Copyright (C) 1996, 1997, 2000, 2001, 2002, 2003, 2005    Free Software Foundation, Inc.    Contributed by Joel Sherrill (joel@OARcorp.com).     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 59 Temple Place - Suite 330, Boston,    MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Specify predefined symbols in preprocessor.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_OS_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do                                      \     {                                     \       builtin_define_std ("PPC");         \       builtin_define ("__rtems__");       \       builtin_define ("__USE_INIT_FINI__"); \       builtin_assert ("system=rtems");    \       builtin_assert ("cpu=powerpc");     \       builtin_assert ("machine=powerpc"); \       TARGET_OS_SYSV_CPP_BUILTINS ();     \     }                                     \   while (0)
end_define

begin_undef
undef|#
directive|undef
name|CPP_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_OS_DEFAULT_SPEC
value|"%(cpp_os_rtems)"
end_define

begin_define
define|#
directive|define
name|CPP_OS_RTEMS_SPEC
value|"\ %{!mcpu*:  %{!Dppc*: %{!Dmpc*: -Dmpc750} } }\ %{mcpu=403:  %{!Dppc*: %{!Dmpc*: -Dppc403}  } } \ %{mcpu=505:  %{!Dppc*: %{!Dmpc*: -Dmpc505}  } } \ %{mcpu=601:  %{!Dppc*: %{!Dmpc*: -Dppc601}  } } \ %{mcpu=602:  %{!Dppc*: %{!Dmpc*: -Dppc602}  } } \ %{mcpu=603:  %{!Dppc*: %{!Dmpc*: -Dppc603}  } } \ %{mcpu=603e: %{!Dppc*: %{!Dmpc*: -Dppc603e} } } \ %{mcpu=604:  %{!Dppc*: %{!Dmpc*: -Dmpc604}  } } \ %{mcpu=750:  %{!Dppc*: %{!Dmpc*: -Dmpc750}  } } \ %{mcpu=821:  %{!Dppc*: %{!Dmpc*: -Dmpc821}  } } \ %{mcpu=860:  %{!Dppc*: %{!Dmpc*: -Dmpc860}  } }"
end_define

begin_undef
undef|#
directive|undef
name|SUBSUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBSUBTARGET_EXTRA_SPECS
define|\
value|{ "cpp_os_rtems",		CPP_OS_RTEMS_SPEC }
end_define

end_unit

