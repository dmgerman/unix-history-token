begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* for dbm and dbz */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|dptr
decl_stmt|;
name|int
name|dsize
decl_stmt|;
block|}
name|datum
typedef|;
end_typedef

begin_comment
comment|/* standard dbm functions */
end_comment

begin_function_decl
specifier|extern
name|int
name|dbminit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|datum
name|fetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|store
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|delete
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* not in dbz */
end_comment

begin_function_decl
specifier|extern
name|datum
name|firstkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* not in dbz */
end_comment

begin_function_decl
specifier|extern
name|datum
name|nextkey
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* not in dbz */
end_comment

begin_function_decl
specifier|extern
name|int
name|dbmclose
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in dbz, but not in old dbm */
end_comment

begin_comment
comment|/* new stuff for dbz */
end_comment

begin_function_decl
specifier|extern
name|int
name|dbzfresh
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dbzagain
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|datum
name|dbzfetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dbzstore
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dbzsync
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|long
name|dbzsize
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dbzincore
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dbzcancel
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dbzdebug
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * In principle we could handle unlimited-length keys by operating a chunk  * at a time, but it's not worth it in practice.  Setting a nice large  * bound on them simplifies the code and doesn't hurt anything.  */
end_comment

begin_define
define|#
directive|define
name|DBZMAXKEY
value|255
end_define

end_unit

