begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	fatal.h	1.2	88/12/22	*/
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
specifier|extern
name|int
name|Fflags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Ffile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Fvalue
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
function_decl|(
modifier|*
name|Ffunc
function_decl|)
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|jmp_buf
name|Fjmp
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FTLMSG
value|0100000
end_define

begin_define
define|#
directive|define
name|FTLCLN
value|0040000
end_define

begin_define
define|#
directive|define
name|FTLFUNC
value|020000
end_define

begin_define
define|#
directive|define
name|FTLACT
value|077
end_define

begin_define
define|#
directive|define
name|FTLJMP
value|02
end_define

begin_define
define|#
directive|define
name|FTLEXIT
value|1
end_define

begin_define
define|#
directive|define
name|FTLRET
value|0
end_define

end_unit

