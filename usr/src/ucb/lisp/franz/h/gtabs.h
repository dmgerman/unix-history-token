begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*					-[Sat Jan 29 13:57:36 1983 by jkf]-  * 	gtabs.h				$Locker:  $  * global lispval table  *  * $Header: /na/franz/franz/h/gtabs.h,v 1.1 83/01/29 14:06:37 jkf Exp $  *  * (c) copyright 1982, Regents of the University of California  */
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

