begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for XScale architectures using ELF    Copyright (C) 1999, 2000, 2001 Free Software Foundation, Inc.    Contributed by Catherine Moore<clm@cygnus.com>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Run-time Target Specification.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VERSION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fputs (" (XScale/ELF non-Linux)", stderr);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SUBTARGET_CPU_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|SUBTARGET_CPU_DEFAULT
value|TARGET_CPU_xscale
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_ASM_SPEC
value|"%{!mcpu=*:-mxscale} %{!mhard-float:-mno-fpu}"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MULTILIB_DEFAULTS
end_ifndef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
define|\
value|{ "mlittle-endian", "mno-thumb-interwork", "marm", "msoft-float" }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

