begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	ranlib.h	4.2	87/04/06	*/
end_comment

begin_define
define|#
directive|define
name|RANLIBMAG
value|"__.SYMDEF"
end_define

begin_comment
comment|/*  * Structure of the __.SYMDEF table of contents for an archive.  * __.SYMDEF begins with a word giving the number of ranlib structures  * which immediately follow, and then continues with a string  * table consisting of a word giving the number of bytes of strings  * which follow and then the strings themselves.  * The ran_strx fields index the string table whose first byte is numbered 0.  */
end_comment

begin_struct
struct|struct
name|ranlib
block|{
union|union
block|{
name|off_t
name|ran_strx
decl_stmt|;
comment|/* string table index of */
name|char
modifier|*
name|ran_name
decl_stmt|;
comment|/* symbol defined by */
block|}
name|ran_un
union|;
name|off_t
name|ran_off
decl_stmt|;
comment|/* library member at this offset */
block|}
struct|;
end_struct

end_unit

