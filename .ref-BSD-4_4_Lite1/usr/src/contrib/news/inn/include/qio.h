begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.2 $ ** **  Quick I/O package -- optimized for reading through a file. */
end_comment

begin_comment
comment|/* **  State for a quick open file. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_QIOSTATE
block|{
name|int
name|fd
decl_stmt|;
name|int
name|Size
decl_stmt|;
name|int
name|flag
decl_stmt|;
name|int
name|Length
decl_stmt|;
name|char
modifier|*
name|Buffer
decl_stmt|;
name|char
modifier|*
name|End
decl_stmt|;
name|char
modifier|*
name|Start
decl_stmt|;
name|long
name|Count
decl_stmt|;
block|}
name|QIOSTATE
typedef|;
end_typedef

begin_comment
comment|/* A reasonable buffersize to use. */
end_comment

begin_define
define|#
directive|define
name|QIO_BUFFER
value|8192
end_define

begin_comment
comment|/* Values for QIOstate.flag */
end_comment

begin_define
define|#
directive|define
name|QIO_ok
value|0
end_define

begin_define
define|#
directive|define
name|QIO_error
value|1
end_define

begin_define
define|#
directive|define
name|QIO_long
value|2
end_define

begin_define
define|#
directive|define
name|QIOerror
parameter_list|(
name|qp
parameter_list|)
value|((qp)->flag> 0)
end_define

begin_define
define|#
directive|define
name|QIOtoolong
parameter_list|(
name|qp
parameter_list|)
value|((qp)->flag == QIO_long)
end_define

begin_define
define|#
directive|define
name|QIOtell
parameter_list|(
name|qp
parameter_list|)
value|((qp)->Count - ((qp)->End - (qp)->Start))
end_define

begin_define
define|#
directive|define
name|QIOlength
parameter_list|(
name|qp
parameter_list|)
value|((qp)->Length)
end_define

begin_define
define|#
directive|define
name|QIOfileno
parameter_list|(
name|qp
parameter_list|)
value|((qp)->fd)
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|QIOread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|QIOSTATE
modifier|*
name|QIOopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|QIOSTATE
modifier|*
name|QIOfdopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|QIOclose
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|QIOrewind
parameter_list|()
function_decl|;
end_function_decl

end_unit

