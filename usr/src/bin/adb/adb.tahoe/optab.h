begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	@(#)optab.h	1.2 (Berkeley) 1/16/89	*/
end_comment

begin_comment
comment|/*  * Argument access types  */
end_comment

begin_define
define|#
directive|define
name|ACCA
value|(8<<3)
end_define

begin_comment
comment|/* address only */
end_comment

begin_define
define|#
directive|define
name|ACCR
value|(1<<3)
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|ACCW
value|(2<<3)
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|ACCM
value|(3<<3)
end_define

begin_comment
comment|/* modify */
end_comment

begin_define
define|#
directive|define
name|ACCB
value|(4<<3)
end_define

begin_comment
comment|/* branch displacement */
end_comment

begin_define
define|#
directive|define
name|ACCI
value|(5<<3)
end_define

begin_comment
comment|/* XFC code */
end_comment

begin_comment
comment|/*  * Argument data types  */
end_comment

begin_define
define|#
directive|define
name|TYPB
value|0
end_define

begin_comment
comment|/* byte */
end_comment

begin_define
define|#
directive|define
name|TYPW
value|1
end_define

begin_comment
comment|/* word */
end_comment

begin_define
define|#
directive|define
name|TYPL
value|2
end_define

begin_comment
comment|/* long */
end_comment

begin_define
define|#
directive|define
name|TYPQ
value|3
end_define

begin_comment
comment|/* quad */
end_comment

begin_define
define|#
directive|define
name|TYPF
value|4
end_define

begin_comment
comment|/* float */
end_comment

begin_define
define|#
directive|define
name|TYPD
value|5
end_define

begin_comment
comment|/* double */
end_comment

begin_comment
comment|/*  * Special instructions  */
end_comment

begin_define
define|#
directive|define
name|KCALL
value|0xcf
end_define

begin_define
define|#
directive|define
name|CASEL
value|0xfc
end_define

begin_struct
specifier|extern
struct|struct
name|optab
block|{
name|char
modifier|*
name|iname
decl_stmt|;
name|u_char
name|val
decl_stmt|;
name|u_char
name|nargs
decl_stmt|;
name|u_char
name|argtype
index|[
literal|6
index|]
decl_stmt|;
block|}
name|optab
index|[]
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|regname
index|[]
decl_stmt|;
end_decl_stmt

end_unit

