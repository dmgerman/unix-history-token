begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  $Revision: 1.14 $ ** **  Here be declarations of functions in the InterNetNews library. */
end_comment

begin_comment
comment|/* Memory allocation. */
end_comment

begin_comment
comment|/* Worst-case alignment, in order to shut lint up. */
end_comment

begin_comment
comment|/* =()<typedef @<ALIGNPTR>@	*ALIGNPTR;>()= */
end_comment

begin_typedef
typedef|typedef
name|int
modifier|*
name|ALIGNPTR
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|ALIGNPTR
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|ALIGNPTR
name|xrealloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Headers. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|GenerateMessageID
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|HeaderFind
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|HeaderCleanFrom
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|_DDHANDLE
modifier|*
name|DDstart
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|DDcheck
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|DDend
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* NNTP functions. */
end_comment

begin_function_decl
specifier|extern
name|int
name|NNTPlocalopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|NNTPremoteopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|NNTPconnect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|NNTPsendarticle
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|NNTPsendpassword
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Opening the active file on a client. */
end_comment

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|CAopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|CAlistopen
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CAclose
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Parameter retrieval. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|GetFQDN
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|GetConfigValue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|GetFileConfigValue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|GetModeratorAddress
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Time functions. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TIMEINFO
block|{
name|time_t
name|time
decl_stmt|;
name|long
name|usec
decl_stmt|;
name|long
name|tzone
decl_stmt|;
block|}
name|TIMEINFO
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|time_t
name|parsedate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|GetTimeInfo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Miscellaneous. */
end_comment

begin_function_decl
specifier|extern
name|int
name|getfdcount
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|wildmat
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|waitnb
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xread
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xwrite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xwritev
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|LockFile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|GetResourceUsage
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|SetNonBlocking
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|CloseOnExec
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|Radix32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|INNVersion
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ReadInDescriptor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|ReadInFile
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|FILE
modifier|*
name|xfopena
parameter_list|()
function_decl|;
end_function_decl

end_unit

