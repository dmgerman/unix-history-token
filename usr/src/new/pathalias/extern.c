begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* pathalias -- by steve bellovin, as told to peter honeyman */
end_comment

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
literal|"@(#)extern.c	8.1 (down!honey) 86/01/19"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|"def.h"
end_include

begin_decl_stmt
name|node
modifier|*
name|Home
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Cfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|Ifiles
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|ProgName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Vflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Cflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Iflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Tflag
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Lineno
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Netchars
init|=
literal|"!:@%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* sparse, but sufficient */
end_comment

begin_decl_stmt
name|int
name|Ncount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Lcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Graphout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|Linkout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|node
modifier|*
modifier|*
name|Table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* hash table + priority queue */
end_comment

begin_decl_stmt
name|long
name|Tabsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of Table */
end_comment

begin_decl_stmt
name|node
modifier|*
name|Private
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of private nodes in this file */
end_comment

begin_decl_stmt
name|long
name|Hashpart
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used while mapping -- above is heap */
end_comment

begin_decl_stmt
name|int
name|Scanstate
init|=
name|NEWLINE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* scanner (yylex) state */
end_comment

end_unit

