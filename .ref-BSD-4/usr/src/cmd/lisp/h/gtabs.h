begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* sccs id  @(#)gtabs.h	34.1  10/3/80  */
end_comment

begin_comment
comment|/*  these are the tables of global lispvals known to the interpreter	*/
end_comment

begin_comment
comment|/*  and compiler.  They are not used by the garbage collector.		*/
end_comment

begin_define
define|#
directive|define
name|GFTABLEN
value|200
end_define

begin_define
define|#
directive|define
name|GCTABLEN
value|8
end_define

begin_decl_stmt
specifier|extern
name|lispval
name|gftab
index|[
name|GFTABLEN
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|lispval
name|gctab
index|[
name|GCTABLEN
index|]
decl_stmt|;
end_decl_stmt

end_unit

