begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Project database buffer definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Field Definitions  */
end_comment

begin_define
define|#
directive|define
name|_PBKS
value|'|'
end_define

begin_comment
comment|/* key field separator character */
end_comment

begin_define
define|#
directive|define
name|_PBFS
value|':'
end_define

begin_comment
comment|/* non-key field separator character */
end_comment

begin_comment
comment|/*  * Functions defined for project database buffers  */
end_comment

begin_function_decl
specifier|extern
name|void
name|pbclear
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* clear buffer */
end_comment

begin_function_decl
specifier|extern
name|void
name|pbshrink
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* shrink buffer */
end_comment

begin_function_decl
specifier|extern
name|int
name|pbstretch
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* stretch buffer */
end_comment

begin_function_decl
specifier|extern
name|int
name|pbaddkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add key */
end_comment

begin_function_decl
specifier|extern
name|int
name|pbchgkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* change existing key */
end_comment

begin_function_decl
specifier|extern
name|int
name|pbcmpkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* compare keys */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|pbcpykey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* copy key */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|pbfndkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find key */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|pbgetkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get next key */
end_comment

begin_function_decl
specifier|extern
name|int
name|pblenkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* length of key */
end_comment

begin_function_decl
specifier|extern
name|void
name|pbrmkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove key */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|pbskipkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* skip to next key */
end_comment

begin_function_decl
specifier|extern
name|int
name|pbaddfield
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add non-key field */
end_comment

begin_function_decl
specifier|extern
name|int
name|pbchgfield
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* change existing non-key field */
end_comment

begin_function_decl
specifier|extern
name|int
name|pbcmpfield
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* compare non-key fields */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|pbcpyfield
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* copy non-key field */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|pbfndfield
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find non-key field */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|pbgetfield
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get next non-key field */
end_comment

begin_function_decl
specifier|extern
name|int
name|pblenfield
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* length of non-key field */
end_comment

begin_function_decl
specifier|extern
name|void
name|pbrmfield
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove non-key field */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|pbskipfield
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* skip to next non-key field */
end_comment

begin_function_decl
specifier|extern
name|int
name|pbaddflag
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add flag field */
end_comment

begin_function_decl
specifier|extern
name|void
name|pbchgflag
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* change existing flag field */
end_comment

begin_function_decl
specifier|extern
name|int
name|pbfndflag
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find flag field */
end_comment

begin_function_decl
specifier|extern
name|void
name|pbrmflag
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove flag field */
end_comment

begin_function_decl
specifier|extern
name|int
name|pbaddstring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add string field */
end_comment

begin_function_decl
specifier|extern
name|int
name|pbchgstring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* change existing string field */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|pbfndstring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* find string field */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|pbgetstring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* get specified string field */
end_comment

begin_function_decl
specifier|extern
name|void
name|pbrmstring
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* remove string field */
end_comment

end_unit

