begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tc-ns32k.h -- Opcode table for National Semi 32k processor    Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_NS32K
end_ifndef

begin_define
define|#
directive|define
name|TC_NS32K
value|1
end_define

begin_include
include|#
directive|include
file|"bit_fix.h"
end_include

begin_define
define|#
directive|define
name|LOCAL_LABELS_FB
end_define

begin_define
define|#
directive|define
name|AOUT_MACHTYPE
value|137
end_define

begin_define
define|#
directive|define
name|tc_aout_pre_write_hook
parameter_list|(
name|x
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_crawl_symbol_chain
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_define
define|#
directive|define
name|tc_headers_hook
parameter_list|(
name|a
parameter_list|)
value|{;}
end_define

begin_comment
comment|/* not used */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEF_MODEC
end_ifndef

begin_define
define|#
directive|define
name|DEF_MODEC
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEF_MODEL
end_ifndef

begin_define
define|#
directive|define
name|DEF_MODEL
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_ARGS
value|4
end_define

begin_define
define|#
directive|define
name|ARG_LEN
value|50
end_define

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

begin_function_decl
name|void
name|fix_new_ns32k
parameter_list|(
name|fragS
modifier|*
name|frag
parameter_list|,
name|int
name|where
parameter_list|,
name|int
name|size
parameter_list|,
name|struct
name|symbol
modifier|*
name|add_symbol
parameter_list|,
name|struct
name|symbol
modifier|*
name|sub_symbol
parameter_list|,
name|long
name|offset
parameter_list|,
name|int
name|pcrel
parameter_list|,
name|int
name|pcrel_adjust
parameter_list|,
name|int
name|im_disp
parameter_list|,
name|bit_fixS
modifier|*
name|bit_fixP
parameter_list|,
comment|/* really bit_fixS */
name|int
name|bsr
parameter_list|,
name|int
name|r_type
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|void
name|fix_new_ns32k
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_NS32K */
end_comment

begin_comment
comment|/* end of tc-ns32k.h */
end_comment

end_unit

