begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/Xlib.h>
end_include

begin_define
define|#
directive|define
name|XREPBUFSIZE
value|64
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|rindex
decl_stmt|;
name|int
name|windex
decl_stmt|;
name|int
name|mindex
decl_stmt|;
name|XEvent
name|xrep
index|[
name|XREPBUFSIZE
index|]
decl_stmt|;
block|}
name|XREPBUFFER
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|x_edges_specified
decl_stmt|;
end_decl_stmt

end_unit

