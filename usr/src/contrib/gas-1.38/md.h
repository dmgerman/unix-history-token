begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* md.h -machine dependent- */
end_comment

begin_comment
comment|/* Copyright (C) 1987 Free Software Foundation, Inc.  This file is part of Gas, the GNU Assembler.  The GNU assembler is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the GNU Assembler General Public License for full details.  Everyone is granted permission to copy, modify and redistribute the GNU Assembler, but only under the conditions described in the GNU Assembler General Public License.  A copy of this license is supposed to have been given to you along with the GNU Assembler so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* In theory (mine, at least!) the machine dependent part of the assembler    should only have to include one file.  This one.  -- JF */
end_comment

begin_comment
comment|/* JF added this here */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|poc_name
decl_stmt|;
comment|/* assembler mnemonic, lower case, no '.' */
name|void
function_decl|(
modifier|*
name|poc_handler
function_decl|)
parameter_list|()
function_decl|;
comment|/* Do the work */
name|int
name|poc_val
decl_stmt|;
comment|/* Value to pass to handler */
block|}
name|pseudo_typeS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|pseudo_typeS
name|md_pseudo_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* JF moved this here from as.h under the theory that nobody except MACHINE.c    and write.c care about it anyway. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|rlx_forward
decl_stmt|;
comment|/* Forward  reach. Signed number.> 0. */
name|long
name|rlx_backward
decl_stmt|;
comment|/* Backward reach. Signed number.< 0. */
name|unsigned
name|char
name|rlx_length
decl_stmt|;
comment|/* Bytes length of this address. */
name|relax_substateT
name|rlx_more
decl_stmt|;
comment|/* Next longer relax-state. */
comment|/* 0 means there is no 'next' relax-state. */
block|}
name|relax_typeS
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|relax_typeS
name|md_relax_table
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define it in MACHINE.c */
end_comment

begin_function_decl
name|char
modifier|*
name|md_atof
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_assemble
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_convert_frag
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_end
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|md_estimate_size_before_relax
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|md_number_to_chars
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* end: md.h */
end_comment

end_unit

