begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991 Aladdin Enterprises.  All rights reserved.    Distributed by Free Software Foundation, Inc.  This file is part of Ghostscript.  Ghostscript is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY.  No author or distributor accepts responsibility to anyone for the consequences of using it or for whether it serves any particular purpose or works at all, unless he says so in writing.  Refer to the Ghostscript General Public License for full details.  Everyone is granted permission to copy, modify and redistribute Ghostscript, but only under the conditions described in the Ghostscript General Public License.  A copy of this license is supposed to have been given to you along with Ghostscript so you can know your rights and responsibilities.  It should be in a file named COPYING.  Among other things, the copyright notice and this notice must be preserved on all copies.  */
end_comment

begin_comment
comment|/* zfilter2.c */
end_comment

begin_comment
comment|/* Additional filter creation for Ghostscript */
end_comment

begin_include
include|#
directive|include
file|"ghost.h"
end_include

begin_include
include|#
directive|include
file|"errors.h"
end_include

begin_include
include|#
directive|include
file|"oper.h"
end_include

begin_include
include|#
directive|include
file|"alloc.h"
end_include

begin_include
include|#
directive|include
file|"stream.h"
end_include

begin_comment
comment|/* Imported from zfilter.c */
end_comment

begin_decl_stmt
name|int
name|filter_read
argument_list|(
name|P3
argument_list|(
argument|os_ptr
argument_list|,
argument|stream_procs _ds *
argument_list|,
argument|stream **
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|filter_write
argument_list|(
name|P3
argument_list|(
argument|os_ptr
argument_list|,
argument|stream_procs _ds *
argument_list|,
argument|stream **
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* .filterASCII85Encode */
end_comment

begin_decl_stmt
specifier|extern
name|stream_procs
name|s_A85E_procs
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|zA85E
parameter_list|(
name|os_ptr
name|op
parameter_list|)
block|{
return|return
name|filter_write
argument_list|(
name|op
argument_list|,
operator|&
name|s_A85E_procs
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* .filterASCII85Decode */
end_comment

begin_decl_stmt
specifier|extern
name|stream_procs
name|s_A85D_procs
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|zA85D
parameter_list|(
name|os_ptr
name|op
parameter_list|)
block|{
return|return
name|filter_read
argument_list|(
name|op
argument_list|,
operator|&
name|s_A85D_procs
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* .filterNullEncode */
end_comment

begin_decl_stmt
specifier|extern
name|stream_procs
name|s_NullE_procs
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|zNullE
parameter_list|(
name|os_ptr
name|op
parameter_list|)
block|{
return|return
name|filter_write
argument_list|(
name|op
argument_list|,
operator|&
name|s_NullE_procs
argument_list|,
name|NULL
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* .filterRunLengthEncode */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* ****** */
end_comment

begin_endif
unit|extern stream_procs s_RLE_procs; extern void s_RLE_init(P2(stream *, uint)); int zRLE(register os_ptr op) {	stream *s; 	int code; 	check_type(*op, t_integer); 	if ( (ulong)(op->value.intval)> max_uint ) 		return e_rangecheck; 	code = filter_write(op - 1,&s_RLE_procs,&s); 	if ( code< 0 ) return code; 	s_RLE_init(s, (uint)(op->value.intval)); 	pop(1); 	return 0; }
endif|#
directive|endif
end_endif

begin_comment
comment|/* ****** */
end_comment

begin_comment
comment|/* .filterRunLengthDecode */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* ****** */
end_comment

begin_endif
unit|extern stream_procs s_RLD_procs; extern void s_RLD_init(P1(stream *)); int zRLD(os_ptr op) {	stream *s; 	int code = filter_write(op,&s_RLD_procs,&s); 	if ( code< 0 ) return code; 	s_RLD_init(s); 	return 0; }
endif|#
directive|endif
end_endif

begin_comment
comment|/* ****** */
end_comment

begin_comment
comment|/* .filterSubFileDecode */
end_comment

begin_comment
comment|/****** Only implemented for null case (count=0, null string) ******/
end_comment

begin_decl_stmt
specifier|extern
name|stream_procs
name|s_SFD_procs
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|zSFD
parameter_list|(
name|os_ptr
name|op
parameter_list|)
block|{
name|int
name|code
decl_stmt|;
name|check_type
argument_list|(
name|op
index|[
operator|-
literal|1
index|]
argument_list|,
name|t_integer
argument_list|)
expr_stmt|;
name|check_type
argument_list|(
operator|*
name|op
argument_list|,
name|t_string
argument_list|)
expr_stmt|;
if|if
condition|(
name|op
index|[
operator|-
literal|1
index|]
operator|.
name|value
operator|.
name|intval
operator|<
literal|0
condition|)
return|return
name|e_rangecheck
return|;
if|if
condition|(
name|op
index|[
operator|-
literal|1
index|]
operator|.
name|value
operator|.
name|intval
operator|!=
literal|0
operator|||
name|r_size
argument_list|(
name|op
argument_list|)
operator|!=
literal|0
condition|)
return|return
name|e_undefined
return|;
comment|/* NYI */
name|code
operator|=
name|filter_read
argument_list|(
name|op
operator|-
literal|2
argument_list|,
operator|&
name|s_SFD_procs
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|code
operator|<
literal|0
condition|)
return|return
name|code
return|;
name|pop
argument_list|(
literal|2
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/* ------ Initialization procedure ------ */
end_comment

begin_decl_stmt
name|op_def
name|zfilter2_op_defs
index|[]
init|=
block|{
block|{
literal|"1.filterASCII85Encode"
block|,
name|zA85E
block|}
block|,
block|{
literal|"1.filterASCII85Decode"
block|,
name|zA85D
block|}
block|,
block|{
literal|"1.filterNullEncode"
block|,
name|zNullE
block|}
block|,
if|#
directive|if
literal|0
comment|/* ****** */
block|{"2.filterRunLengthEncode", zRLE}, 	{"1.filterRunLengthDecode", zRLD},
endif|#
directive|endif
comment|/* ****** */
block|{
literal|"1.filterSubFileDecode"
block|,
name|zSFD
block|}
block|,
name|op_def_end
argument_list|(
literal|0
argument_list|)
block|}
decl_stmt|;
end_decl_stmt

end_unit

