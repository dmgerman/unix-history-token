begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Like the compiler, the static analyzer treats some functions differently if
end_comment

begin_comment
comment|// they come from a system header -- for example, it is assumed that system
end_comment

begin_comment
comment|// functions do not arbitrarily free() their parameters, and that some bugs
end_comment

begin_comment
comment|// found in system headers cannot be fixed by the user and should be
end_comment

begin_comment
comment|// suppressed.
end_comment

begin_pragma
pragma|#
directive|pragma
name|clang
name|system_header
end_pragma

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|restrict
end_define

begin_comment
comment|/*restrict*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|struct
name|_FILE
name|FILE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|stdin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|stdout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|stderr
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Include a variant of standard streams that occur in the pre-processed file.
end_comment

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|__stdinp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|__stdoutp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|__stderrp
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|scanf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fscanf
parameter_list|(
name|FILE
modifier|*
specifier|restrict
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|printf
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
name|format
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fprintf
parameter_list|(
name|FILE
modifier|*
specifier|restrict
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|getchar
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Note, on some platforms errno macro gets replaced with a function call.
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|__typeof
argument_list|(
argument|sizeof(int)
argument_list|)
name|size_t
expr_stmt|;
end_typedef

begin_function_decl
name|size_t
name|strlen
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|strcpy
parameter_list|(
name|char
modifier|*
specifier|restrict
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memcpy
parameter_list|(
name|void
modifier|*
name|dst
parameter_list|,
specifier|const
name|void
modifier|*
name|src
parameter_list|,
name|size_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|unsigned
name|long
name|__darwin_pthread_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__darwin_pthread_key_t
name|pthread_key_t
typedef|;
end_typedef

begin_function_decl
name|int
name|pthread_setspecific
parameter_list|(
name|pthread_key_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|long
name|long
name|__int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64_t
name|__darwin_off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__darwin_off_t
name|fpos_t
typedef|;
end_typedef

begin_function_decl
name|void
name|setbuf
parameter_list|(
name|FILE
modifier|*
specifier|restrict
parameter_list|,
name|char
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setvbuf
parameter_list|(
name|FILE
modifier|*
specifier|restrict
parameter_list|,
name|char
modifier|*
specifier|restrict
parameter_list|,
name|int
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|fopen
parameter_list|(
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|,
specifier|const
name|char
modifier|*
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fclose
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|FILE
modifier|*
name|funopen
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|fpos_t
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|fpos_t
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|int
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sqlite3_bind_text_my
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
name|n
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|freeCallback
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|i
decl_stmt|;
name|freeCallback
name|fc
decl_stmt|;
block|}
name|StWithCallback
typedef|;
end_typedef

begin_function_decl
name|int
name|dealocateMemWhenDoneByVal
parameter_list|(
name|void
modifier|*
parameter_list|,
name|StWithCallback
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dealocateMemWhenDoneByRef
parameter_list|(
name|StWithCallback
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|struct
name|CGContext
modifier|*
name|CGContextRef
typedef|;
end_typedef

begin_function_decl
name|CGContextRef
name|CGBitmapContextCreate
parameter_list|(
name|void
modifier|*
name|data
comment|/*, size_t width, size_t height,                                    size_t bitsPerComponent, size_t bytesPerRow,                                    CGColorSpaceRef space,                                    CGBitmapInfo bitmapInfo*/
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|CGBitmapContextGetData
parameter_list|(
name|CGContextRef
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Include xpc.
end_comment

begin_typedef
typedef|typedef
name|struct
name|_xpc_connection_s
modifier|*
name|xpc_connection_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|xpc_finalizer_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|value
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|xpc_connection_set_context
parameter_list|(
name|xpc_connection_t
name|connection
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpc_connection_set_finalizer_f
parameter_list|(
name|xpc_connection_t
name|connection
parameter_list|,
name|xpc_finalizer_t
name|finalizer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xpc_connection_resume
parameter_list|(
name|xpc_connection_t
name|connection
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|//The following are fake system header functions for generic testing.
end_comment

begin_function_decl
name|void
name|fakeSystemHeaderCallInt
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fakeSystemHeaderCallIntPtr
parameter_list|(
name|int
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
struct|struct
name|__SomeStruct
block|{
name|char
modifier|*
name|p
decl_stmt|;
block|}
name|SomeStruct
typedef|;
end_typedef

begin_function_decl
name|void
name|fakeSystemHeaderCall
parameter_list|(
name|SomeStruct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

