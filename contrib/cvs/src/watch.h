begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface to "cvs watch add", "cvs watchers", and related features     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|watch_usage
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flags to pass between the various functions making up the    add/remove code.  All in a single structure in case there is some    need to make the code reentrant some day.  */
end_comment

begin_struct
struct|struct
name|addremove_args
block|{
comment|/* A flag for each watcher type.  */
name|int
name|edit
decl_stmt|;
name|int
name|unedit
decl_stmt|;
name|int
name|commit
decl_stmt|;
comment|/* Are we adding or removing (non-temporary) edit,unedit,and/or commit        watches?  */
name|int
name|adding
decl_stmt|;
comment|/* Should we add a temporary edit watch?  */
name|int
name|add_tedit
decl_stmt|;
comment|/* Should we add a temporary unedit watch?  */
name|int
name|add_tunedit
decl_stmt|;
comment|/* Should we add a temporary commit watch?  */
name|int
name|add_tcommit
decl_stmt|;
comment|/* Should we remove all temporary watches?  */
name|int
name|remove_temp
decl_stmt|;
comment|/* Should we set the default?  This is here for passing among various        routines in watch.c (a good place for it if there is ever any reason        to make the stuff reentrant), not for watch_modify_watchers.  */
name|int
name|setting_default
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Modify the watchers for FILE.  *WHAT tells what to do to them.    If FILE is NULL, modify default args (WHAT->SETTING_DEFAULT is    not used).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|watch_modify_watchers
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
expr|struct
name|addremove_args
operator|*
name|what
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|watch_add
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|watch_remove
name|PROTO
argument_list|(
operator|(
name|int
name|argc
operator|,
name|char
operator|*
operator|*
name|argv
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

