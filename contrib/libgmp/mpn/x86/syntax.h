begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* asm.h -- Definitions for x86 syntax variations.  Copyright (C) 1992, 1994, 1995 Free Software Foundation, Inc.  This file is part of the GNU MP Library.  The GNU MP Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU MP Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU MP Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|ALIGN
end_undef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD_SYNTAX
argument_list|)
operator|||
name|defined
argument_list|(
name|ELF_SYNTAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|R
parameter_list|(
name|r
parameter_list|)
value|%r
end_define

begin_define
define|#
directive|define
name|MEM
parameter_list|(
name|base
parameter_list|)
value|(base)
end_define

begin_define
define|#
directive|define
name|MEM_DISP
parameter_list|(
name|base
parameter_list|,
name|displacement
parameter_list|)
value|displacement(R(base))
end_define

begin_define
define|#
directive|define
name|MEM_INDEX
parameter_list|(
name|base
parameter_list|,
name|index
parameter_list|,
name|size
parameter_list|)
value|(R(base),R(index),size)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|INSN1
parameter_list|(
name|mnemonic
parameter_list|,
name|size_suffix
parameter_list|,
name|dst
parameter_list|)
value|mnemonic##size_suffix dst
end_define

begin_define
define|#
directive|define
name|INSN2
parameter_list|(
name|mnemonic
parameter_list|,
name|size_suffix
parameter_list|,
name|dst
parameter_list|,
name|src
parameter_list|)
value|mnemonic##size_suffix src,dst
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|INSN1
parameter_list|(
name|mnemonic
parameter_list|,
name|size_suffix
parameter_list|,
name|dst
parameter_list|)
value|mnemonic
comment|/**/
value|size_suffix dst
end_define

begin_define
define|#
directive|define
name|INSN2
parameter_list|(
name|mnemonic
parameter_list|,
name|size_suffix
parameter_list|,
name|dst
parameter_list|,
name|src
parameter_list|)
value|mnemonic
comment|/**/
value|size_suffix src,dst
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TEXT
value|.text
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|BSD_SYNTAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|log
parameter_list|)
value|.align log
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ELF_SYNTAX
argument_list|)
end_if

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|log
parameter_list|)
value|.align 1<<(log)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GLOBL
value|.globl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INTEL_SYNTAX
end_ifdef

begin_define
define|#
directive|define
name|R
parameter_list|(
name|r
parameter_list|)
value|r
end_define

begin_define
define|#
directive|define
name|MEM
parameter_list|(
name|base
parameter_list|)
value|[base]
end_define

begin_define
define|#
directive|define
name|MEM_DISP
parameter_list|(
name|base
parameter_list|,
name|displacement
parameter_list|)
value|[base+(displacement)]
end_define

begin_define
define|#
directive|define
name|MEM_INDEX
parameter_list|(
name|base
parameter_list|,
name|index
parameter_list|,
name|size
parameter_list|)
value|[base+index*size]
end_define

begin_define
define|#
directive|define
name|INSN1
parameter_list|(
name|mnemonic
parameter_list|,
name|size_suffix
parameter_list|,
name|dst
parameter_list|)
value|mnemonic dst
end_define

begin_define
define|#
directive|define
name|INSN2
parameter_list|(
name|mnemonic
parameter_list|,
name|size_suffix
parameter_list|,
name|dst
parameter_list|,
name|src
parameter_list|)
value|mnemonic dst,src
end_define

begin_define
define|#
directive|define
name|TEXT
value|.text
end_define

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|log
parameter_list|)
value|.align log
end_define

begin_define
define|#
directive|define
name|GLOBL
value|.globl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BROKEN_ALIGN
end_ifdef

begin_undef
undef|#
directive|undef
name|ALIGN
end_undef

begin_define
define|#
directive|define
name|ALIGN
parameter_list|(
name|log
parameter_list|)
value|.align log,0x90
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

