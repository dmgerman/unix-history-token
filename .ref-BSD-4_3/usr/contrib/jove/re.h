begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************  * This program is copyright (C) 1985, 1986 by Jonathan Payne.  It is    *  * provided to you without charge for use only on a licensed Unix        *  * system.  You may copy JOVE provided that this notice is included with *  * the copy.  You may not sell copies of this program or versions        *  * modified for use on microcomputer systems, unless the copies are      *  * included with a Unix system distribution and the source is provided.  *  *************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NALTS
value|10
end_define

begin_comment
comment|/* number of alternate search strings */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|searchstr
index|[
literal|128
index|]
decl_stmt|,
name|compbuf
index|[
literal|128
index|]
decl_stmt|,
comment|/* global default compbuf */
name|rep_search
index|[
literal|128
index|]
decl_stmt|,
comment|/* replace search string */
name|rep_str
index|[
literal|128
index|]
decl_stmt|,
comment|/* contains replacement string */
modifier|*
name|cur_compb
decl_stmt|,
comment|/* usually points at compbuf */
name|REbuf
index|[
name|LBSIZE
index|]
decl_stmt|,
comment|/* points at line we're scanning */
modifier|*
name|alternates
index|[
name|NALTS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|REdirection
decl_stmt|,
name|REeom
decl_stmt|,
name|REbom
decl_stmt|,
name|REalt_num
decl_stmt|;
end_decl_stmt

end_unit

