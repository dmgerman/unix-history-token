begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright 1984, 1985 by the Regents of the University of  *	California and by Gregory Glenn Minshall.  *  *	Permission to use, copy, modify, and distribute these  *	programs and their documentation for any purpose and  *	without fee is hereby granted, provided that this  *	copyright and permission appear on all copies and  *	supporting documentation, the name of the Regents of  *	the University of California not be used in advertising  *	or publicity pertaining to distribution of the programs  *	without specific prior permission, and notice be given in  *	supporting documentation that copying and distribution is  *	by permission of the Regents of the University of California  *	and by Gregory Glenn Minshall.  Neither the Regents of the  *	University of California nor Gregory Glenn Minshall make  *	representations about the suitability of this software  *	for any purpose.  It is provided "as is" without  *	express or implied warranty.  */
end_comment

begin_comment
comment|/* the various options that run our life.  Very few of these are implemented 	as yet.  */
end_comment

begin_decl_stmt
name|int
name|OptHome
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where home should send us */
end_comment

begin_decl_stmt
name|int
name|OptLeftMargin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where new line should send us */
end_comment

begin_decl_stmt
name|char
name|OptColTabs
index|[
literal|80
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local tab stops */
end_comment

begin_decl_stmt
name|int
name|OptAPLmode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|OptNullProcessing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* improved null processing */
end_comment

begin_decl_stmt
name|int
name|OptZonesMode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* zones mode off */
end_comment

begin_decl_stmt
name|int
name|OptEnterNL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regular enter/new line keys */
end_comment

begin_decl_stmt
name|int
name|OptColFieldTab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* regular column/field tab keys */
end_comment

begin_decl_stmt
name|int
name|OptPacing
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* do pacing */
end_comment

begin_decl_stmt
name|int
name|OptAlphaInNumeric
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allow alpha in numeric fields */
end_comment

begin_decl_stmt
name|int
name|OptHome
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|OptLeftMargin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|OptWordWrap
decl_stmt|;
end_decl_stmt

end_unit

