begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for sparclite 86x w/o FPU.    Copyright (C) 1998, 1999, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__sparc__ -D__sparclite86x__ -Acpu=sparc -Amachine=sparc"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (sparclite 86x)");
end_define

begin_comment
comment|/* Enable app-regs and epilogue options.  Do not enable the fpu.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_APP_REGS + MASK_EPILOGUE)
end_define

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{v:-v} %{mlittle-endian-data:--little-endian-data} %(asm_cpu)"
end_define

begin_comment
comment|/* US Software GOFAST library support.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SUBTARGET_OPTABS
end_undef

begin_define
define|#
directive|define
name|INIT_SUBTARGET_OPTABS
value|INIT_GOFAST_OPTABS
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{v:-V}"
end_define

begin_undef
undef|#
directive|undef
name|BYTES_BIG_ENDIAN
end_undef

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|(! TARGET_LITTLE_ENDIAN_DATA)
end_define

begin_undef
undef|#
directive|undef
name|WORDS_BIG_ENDIAN
end_undef

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|(! TARGET_LITTLE_ENDIAN_DATA)
end_define

begin_define
define|#
directive|define
name|TARGET_LITTLE_ENDIAN_DATA
value|(target_flags& MASK_LITTLE_ENDIAN)
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
define|\
value|{ "little-endian-data",              MASK_LITTLE_ENDIAN,	N_("Use little-endian byte order for data")},
end_define

end_unit

