begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sccsid = "@(#)player.h	1.1 3/17/83";  */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_include
include|#
directive|include
file|"externs.h"
end_include

begin_define
define|#
directive|define
name|ROWSINVIEW
value|15
end_define

begin_define
define|#
directive|define
name|COLSINVIEW
value|75
end_define

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|view
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WINDOW
modifier|*
name|slot
decl_stmt|;
end_decl_stmt

end_unit

