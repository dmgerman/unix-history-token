begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)lrnref.h	4.1	(Berkeley)	83/02/24	*/
end_comment

begin_define
define|#
directive|define
name|READY
value|0
end_define

begin_define
define|#
directive|define
name|PRINT
value|1
end_define

begin_define
define|#
directive|define
name|COPYIN
value|2
end_define

begin_define
define|#
directive|define
name|COPYOUT
value|3
end_define

begin_define
define|#
directive|define
name|UNCOPIN
value|4
end_define

begin_define
define|#
directive|define
name|UNCOPOUT
value|5
end_define

begin_define
define|#
directive|define
name|PIPE
value|6
end_define

begin_define
define|#
directive|define
name|UNPIPE
value|7
end_define

begin_define
define|#
directive|define
name|YES
value|8
end_define

begin_define
define|#
directive|define
name|NO
value|9
end_define

begin_define
define|#
directive|define
name|SUCCEED
value|10
end_define

begin_define
define|#
directive|define
name|FAIL
value|11
end_define

begin_define
define|#
directive|define
name|BYE
value|12
end_define

begin_define
define|#
directive|define
name|LOG
value|13
end_define

begin_define
define|#
directive|define
name|CHDIR
value|14
end_define

begin_define
define|#
directive|define
name|LEARN
value|15
end_define

begin_define
define|#
directive|define
name|MV
value|16
end_define

begin_define
define|#
directive|define
name|USER
value|17
end_define

begin_define
define|#
directive|define
name|NEXT
value|18
end_define

begin_define
define|#
directive|define
name|SKIP
value|19
end_define

begin_define
define|#
directive|define
name|WHERE
value|20
end_define

begin_define
define|#
directive|define
name|MATCH
value|21
end_define

begin_define
define|#
directive|define
name|NOP
value|22
end_define

begin_define
define|#
directive|define
name|BAD
value|23
end_define

begin_define
define|#
directive|define
name|CREATE
value|24
end_define

begin_define
define|#
directive|define
name|CMP
value|25
end_define

begin_define
define|#
directive|define
name|GOTO
value|26
end_define

begin_define
define|#
directive|define
name|ONCE
value|27
end_define

begin_decl_stmt
specifier|extern
name|int
name|more
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|speed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|sname
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|direct
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|todo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|didok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sequence
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|comfile
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|status
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|wrong
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pwline
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|incopy
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|scrin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|logging
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ask
decl_stmt|;
end_decl_stmt

end_unit

