begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987 by Ed James, UC Berkeley.  All rights reserved.  *  * Copy permission is hereby granted provided that this notice is  * retained on all partial or complete copies.  *  * For more info on this and all of my stuff, mail edjames@berkeley.edu.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|GAMES
index|[]
decl_stmt|,
name|LOG
index|[]
decl_stmt|,
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|clock
decl_stmt|,
name|safe_planes
decl_stmt|,
name|start_time
decl_stmt|,
name|test_mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|filein
decl_stmt|,
modifier|*
name|fileout
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|C_SCREEN
name|screen
decl_stmt|,
modifier|*
name|sp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|LIST
name|air
decl_stmt|,
name|ground
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sgttyb
name|tty_start
decl_stmt|,
name|tty_new
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|DISPLACEMENT
name|displacement
index|[
name|MAXDIR
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PLANE
modifier|*
name|findplane
argument_list|()
decl_stmt|,
modifier|*
name|newplane
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

