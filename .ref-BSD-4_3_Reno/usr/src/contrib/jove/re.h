begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***************************************************************************  * This program is Copyright (C) 1986, 1987, 1988 by Jonathan Payne.  JOVE *  * is provided to you without charge, and with no warranty.  You may give  *  * away copies of JOVE, including sources, provided that this notice is    *  * included in all the files.                                              *  ***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NALTS
value|16
end_define

begin_comment
comment|/* number of alternate search strings */
end_comment

begin_define
define|#
directive|define
name|COMPSIZE
value|256
end_define

begin_comment
comment|/* kinds of regular expression compiles */
end_comment

begin_define
define|#
directive|define
name|NORM
value|0
end_define

begin_comment
comment|/* nothing special */
end_comment

begin_define
define|#
directive|define
name|OKAY_RE
value|1
end_define

begin_comment
comment|/* allow regular expressions */
end_comment

begin_define
define|#
directive|define
name|IN_CB
value|2
end_define

begin_comment
comment|/* in curly brace; implies OKAY_RE */
end_comment

begin_struct
struct|struct
name|RE_block
block|{
name|char
name|r_compbuf
index|[
name|COMPSIZE
index|]
decl_stmt|,
modifier|*
name|r_alternates
index|[
name|NALTS
index|]
decl_stmt|,
name|r_lbuf
index|[
name|LBSIZE
index|]
decl_stmt|;
name|int
name|r_nparens
decl_stmt|,
name|r_firstc
decl_stmt|,
name|r_anchored
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
name|searchstr
index|[
literal|128
index|]
decl_stmt|,
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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* contains replacement string */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|REdirection
decl_stmt|,
name|REbom
decl_stmt|,
comment|/* beginning and end columns of match */
name|REeom
decl_stmt|,
name|REdelta
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* increase in line length due to last re_dosub */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|okay_wrap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do a wrap search ... not when we're 				   parsing errors ... */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|getsearch
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|LookingAt
name|proto
argument_list|(
operator|(
name|char
operator|*
name|pattern
operator|,
name|char
operator|*
name|buf
operator|,
name|int
name|offset
operator|)
argument_list|)
decl_stmt|,
name|look_at
name|proto
argument_list|(
operator|(
name|char
operator|*
name|expr
operator|)
argument_list|)
decl_stmt|,
name|re_lindex
name|proto
argument_list|(
operator|(
expr|struct
name|line
operator|*
name|line
operator|,
name|int
name|offset
operator|,
expr|struct
name|RE_block
operator|*
name|re_blk
operator|,
name|int
name|lbuf_okay
operator|,
name|int
name|crater
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Bufpos
modifier|*
name|docompiled
name|proto
argument_list|(
operator|(
name|int
name|dir
operator|,
expr|struct
name|RE_block
operator|*
name|re_blk
operator|)
argument_list|)
decl_stmt|,
modifier|*
name|dosearch
name|proto
argument_list|(
operator|(
name|char
operator|*
name|pattern
operator|,
name|int
name|dir
operator|,
name|int
name|re
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|REcompile
name|proto
argument_list|(
operator|(
name|char
operator|*
name|pattern
operator|,
name|int
name|re
operator|,
expr|struct
name|RE_block
operator|*
name|re_blk
operator|)
argument_list|)
decl_stmt|,
name|find_tag
name|proto
argument_list|(
operator|(
name|char
operator|*
name|tag
operator|,
name|int
name|localp
operator|)
argument_list|)
decl_stmt|,
name|putmatch
name|proto
argument_list|(
operator|(
name|int
name|which
operator|,
name|char
operator|*
name|buf
operator|,
name|size_t
name|size
operator|)
argument_list|)
decl_stmt|,
name|re_dosub
name|proto
argument_list|(
operator|(
expr|struct
name|RE_block
operator|*
name|re_blk
operator|,
name|char
operator|*
name|tobuf
operator|,
name|int
name|delp
operator|)
argument_list|)
decl_stmt|,
name|setsearch
name|proto
argument_list|(
operator|(
name|char
operator|*
name|str
operator|)
argument_list|)
decl_stmt|,
name|RErecur
name|proto
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

