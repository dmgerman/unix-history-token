begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: Xtty.h,v 10.3 86/02/01 15:42:44 tony Rel $ */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_TTYWindow
block|{
name|Window
name|w
decl_stmt|;
comment|/* The window id */
name|int
name|pid
decl_stmt|;
comment|/* The pid of the subprocess xterm */
name|short
name|file
decl_stmt|;
comment|/* The file id of the tty to read and write  	    	    	    	   characters to/from */
block|}
name|TTYWindow
typedef|;
end_typedef

begin_function_decl
name|TTYWindow
modifier|*
name|CreateTTYWindow
parameter_list|()
function_decl|;
end_function_decl

end_unit

