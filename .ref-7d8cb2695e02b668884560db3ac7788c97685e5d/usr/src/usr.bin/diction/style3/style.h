begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * %sccs.include.proprietary.c%  *  *	@(#)style.h	4.4 (Berkeley) %G%  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|part
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|style
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|topic
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pastyle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lstyle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rstyle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|estyle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nstyle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Nstyle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rthresh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|lthresh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pstyle
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sleng
index|[
literal|50
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|numsent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|letnonf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|numnonf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|vowel
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|numwds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|twds
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|numlet
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxsent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxindex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|minindex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|qcount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|icount
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|minsent
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|simple
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|compound
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|compdx
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|complex
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nomin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tobe
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|noun
decl_stmt|,
name|infin
decl_stmt|,
name|pron
decl_stmt|,
name|aux
decl_stmt|,
name|adv
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|passive
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|beg
index|[
literal|15
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|prepc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|conjc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|verbc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tverbc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|adj
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|MAXPAR
value|20
end_define

begin_decl_stmt
specifier|extern
name|int
name|leng
index|[]
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern sentno;
end_extern

end_unit

