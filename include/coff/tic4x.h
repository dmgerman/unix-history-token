begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* TI COFF information for Texas Instruments TMS320C4X/C3X.    This file customizes the settings in coff/ti.h.         Copyright 2002, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.        This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.        You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COFF_TIC4X_H
end_ifndef

begin_define
define|#
directive|define
name|COFF_TIC4X_H
end_define

begin_define
define|#
directive|define
name|TIC4X_TARGET_ID
value|0x0093
end_define

begin_comment
comment|/* Octets per byte, as a power of two.  */
end_comment

begin_define
define|#
directive|define
name|TI_TARGET_ID
value|TIC4X_TARGET_ID
end_define

begin_define
define|#
directive|define
name|OCTETS_PER_BYTE_POWER
value|2
end_define

begin_comment
comment|/* Add to howto to get absolute/sect-relative version.  */
end_comment

begin_define
define|#
directive|define
name|HOWTO_BANK
value|6
end_define

begin_define
define|#
directive|define
name|TICOFF_TARGET_ARCH
value|bfd_arch_tic4x
end_define

begin_comment
comment|/* We use COFF2.  */
end_comment

begin_define
define|#
directive|define
name|TICOFF_DEFAULT_MAGIC
value|TICOFF2MAGIC
end_define

begin_define
define|#
directive|define
name|TICOFF_TARGET_MACHINE_GET
parameter_list|(
name|FLAGS
parameter_list|)
define|\
value|(((FLAGS)& F_VERS) ? bfd_mach_tic4x : bfd_mach_tic3x)
end_define

begin_define
define|#
directive|define
name|TICOFF_TARGET_MACHINE_SET
parameter_list|(
name|FLAGSP
parameter_list|,
name|MACHINE
parameter_list|)
define|\
value|do							\     {							\       if ((MACHINE) == bfd_mach_tic4x)			\         *(FLAGSP) |= F_VERS;				\     }							\   while (0)
end_define

begin_include
include|#
directive|include
file|"coff/ti.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COFF_TIC4X_H */
end_comment

end_unit

