begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* write.h     Copyright (C) 1987, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * write.h,v 1.3 1993/10/02 20:58:02 pk Exp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TC_I960
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|hpux
end_ifdef

begin_define
define|#
directive|define
name|EXEC_MACHINE_TYPE
value|HP9000S200_ID
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TC_I960 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LOCAL_LABEL
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|DOT_LABEL_PREFIX
end_ifdef

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
value|(name[0] == '.' \&& (name[1] == 'L' || name[1] == '.'))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not defined DOT_LABEL_PREFIX */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABEL
parameter_list|(
name|name
parameter_list|)
value|(name[0] == 'L')
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not defined DOT_LABEL_PREFIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCAL_LABEL */
end_comment

begin_define
define|#
directive|define
name|S_LOCAL_NAME
parameter_list|(
name|s
parameter_list|)
value|(LOCAL_LABEL(S_GET_NAME(s)))
end_define

begin_include
include|#
directive|include
file|"bit_fix.h"
end_include

begin_comment
comment|/*  * FixSs may be built up in any order.  */
end_comment

begin_struct
struct|struct
name|fix
block|{
name|fragS
modifier|*
name|fx_frag
decl_stmt|;
comment|/* Which frag? */
name|long
name|fx_where
decl_stmt|;
comment|/* Where is the 1st byte to fix up? */
name|symbolS
modifier|*
name|fx_addsy
decl_stmt|;
comment|/* NULL or Symbol whose value we add in. */
name|symbolS
modifier|*
name|fx_subsy
decl_stmt|;
comment|/* NULL or Symbol whose value we subtract. */
ifdef|#
directive|ifdef
name|PIC
name|symbolS
modifier|*
name|fx_gotsy
decl_stmt|;
comment|/* NULL or __GLOBAL_OFFSET_TABLE_ . */
endif|#
directive|endif
name|long
name|fx_offset
decl_stmt|;
comment|/* Absolute number we add in. */
name|struct
name|fix
modifier|*
name|fx_next
decl_stmt|;
comment|/* NULL or -> next fixS. */
name|short
name|int
name|fx_size
decl_stmt|;
comment|/* How many bytes are involved? */
name|char
name|fx_pcrel
decl_stmt|;
comment|/* TRUE: pc-relative. */
name|char
name|fx_pcrel_adjust
decl_stmt|;
comment|/* pc-relative offset adjust */
name|char
name|fx_im_disp
decl_stmt|;
comment|/* TRUE: value is a displacement */
name|bit_fixS
modifier|*
name|fx_bit_fixP
decl_stmt|;
comment|/* IF NULL no bitfix's to do */
name|char
name|fx_bsr
decl_stmt|;
comment|/* sequent-hack */
name|enum
name|reloc_type
name|fx_r_type
decl_stmt|;
comment|/* Sparc hacks */
name|char
name|fx_callj
decl_stmt|;
comment|/* TRUE if target is a 'callj' (used by i960) */
name|long
name|fx_addnumber
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fix
name|fixS
typedef|;
end_typedef

begin_decl_stmt
name|COMMON
name|char
modifier|*
name|next_object_file_charP
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|MANY_SEGMENTS
end_ifndef

begin_decl_stmt
name|COMMON
name|fixS
modifier|*
name|text_fix_root
decl_stmt|,
modifier|*
name|text_fix_tail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chains fixSs. */
end_comment

begin_decl_stmt
name|COMMON
name|fixS
modifier|*
name|data_fix_root
decl_stmt|,
modifier|*
name|data_fix_tail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chains fixSs. */
end_comment

begin_decl_stmt
name|COMMON
name|fixS
modifier|*
name|bss_fix_root
decl_stmt|,
modifier|*
name|bss_fix_tail
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Chains fixSs. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|COMMON
name|fixS
modifier|*
modifier|*
name|seg_fix_rootP
decl_stmt|,
modifier|*
modifier|*
name|seg_fix_tailP
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* -> one of above. */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|string_byte_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|section_alignment
index|[]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|__STDC__
operator|==
literal|1
end_if

begin_function_decl
name|bit_fixS
modifier|*
name|bit_fix_new
parameter_list|(
name|int
name|size
parameter_list|,
name|int
name|offset
parameter_list|,
name|long
name|base_type
parameter_list|,
name|long
name|base_adj
parameter_list|,
name|long
name|min
parameter_list|,
name|long
name|max
parameter_list|,
name|long
name|add
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|append
parameter_list|(
name|char
modifier|*
modifier|*
name|charPP
parameter_list|,
name|char
modifier|*
name|fromP
parameter_list|,
name|unsigned
name|long
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|record_alignment
parameter_list|(
name|segT
name|seg
parameter_list|,
name|int
name|align
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_object_file
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|fixS
modifier|*
name|fix_new
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
name|symbolS
modifier|*
name|add_symbol
parameter_list|,
name|symbolS
modifier|*
name|sub_symbol
parameter_list|,
name|long
name|offset
parameter_list|,
name|int
name|pcrel
parameter_list|,
name|enum
name|reloc_type
name|r_type
ifdef|#
directive|ifdef
name|PIC
parameter_list|,
name|symbolS
modifier|*
name|got_symbol
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* not __STDC__ */
end_comment

begin_function_decl
name|bit_fixS
modifier|*
name|bit_fix_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|fixS
modifier|*
name|fix_new
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|append
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|record_alignment
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|write_object_file
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

begin_comment
comment|/*  * Local Variables:  * comment-column: 0  * fill-column: 131  * End:  */
end_comment

begin_comment
comment|/* end of write.h */
end_comment

end_unit

