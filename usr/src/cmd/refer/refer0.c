begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"stdio.h"
end_include

begin_include
include|#
directive|include
file|"refer..c"
end_include

begin_decl_stmt
name|FILE
modifier|*
name|in
init|=
name|stdin
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|int
name|endpush
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|labels
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|keywant
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|sort
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|bare
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|authrev
literal|0
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
operator|*
name|smallcaps
literal|""
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|char
operator|*
name|keystr
literal|"AD"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|nmlen
literal|0
operator|,
name|dtlen
literal|0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
modifier|*
name|data
index|[
name|NSERCH
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|search
name|data
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|int
name|refnum
literal|0
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
name|reftext
index|[
name|NRFTXT
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|reftable
index|[
name|NRFTBL
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|rtp
name|reftext
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|int
name|sep
literal|'\n'
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|char
name|tfile
index|[
name|NTFILE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|fo
init|=
name|stdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|FILE
modifier|*
name|ftemp
init|=
name|stdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ofile
index|[
name|NTFILE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|gfile
index|[
name|NTFILE
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|hidenam
index|[
name|NTFILE
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|char
operator|*
name|Ifile
literal|"standard input"
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|int
name|Iline
literal|0
expr_stmt|;
end_expr_stmt

end_unit

