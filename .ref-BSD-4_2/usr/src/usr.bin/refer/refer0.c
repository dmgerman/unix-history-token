begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)refer0.c	4.1 (Berkeley) 5/6/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
name|int
name|endpush
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sort
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|labels
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|keywant
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|bare
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|biblio
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|science
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|postpunct
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|authrev
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|smallcaps
init|=
literal|""
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|keystr
init|=
literal|"AD"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|convert
init|=
literal|"X.AP"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nmlen
init|=
literal|0
decl_stmt|,
name|dtlen
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|rdata
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
init|=
name|rdata
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|refnum
init|=
literal|0
decl_stmt|;
end_decl_stmt

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
init|=
name|reftext
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|sep
init|=
literal|'\n'
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|tfile
index|[
name|NTFILE
index|]
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

begin_decl_stmt
name|char
modifier|*
name|Ifile
init|=
literal|"standard input"
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Iline
init|=
literal|0
decl_stmt|;
end_decl_stmt

end_unit

