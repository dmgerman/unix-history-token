begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface to "cvs edit", "cvs watch on", and related features     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|watch_on
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
name|watch_off
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

begin_ifdef
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
end_ifdef

begin_comment
comment|/* Check to see if any notifications are sitting around in need of being    sent.  These are the notifications stored in CVSADM_NOTIFY (edit,unedit);    commit calls notify_do directly.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|notify_check
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|repository
operator|,
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CLIENT_SUPPORT */
end_comment

begin_comment
comment|/* Issue a notification for file FILENAME.  TYPE is 'E' for edit, 'U'    for unedit, and 'C' for commit.  WHO is the user currently running.    For TYPE 'E', VAL is the time+host+directory data which goes in    _editors, and WATCHES is zero or more of E,U,C, in that order, to specify    what kinds of temporary watches to set.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|notify_do
name|PROTO
argument_list|(
operator|(
name|int
name|type
operator|,
name|char
operator|*
name|filename
operator|,
name|char
operator|*
name|who
operator|,
name|char
operator|*
name|val
operator|,
name|char
operator|*
name|watches
operator|,
name|char
operator|*
name|repository
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set attributes to reflect the fact that EDITOR is editing FILENAME.    VAL is time+host+directory, or NULL if we are to say that EDITOR is    *not* editing FILENAME.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|editor_set
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|filename
operator|,
name|char
operator|*
name|editor
operator|,
name|char
operator|*
name|val
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Take note of the fact that FILE is up to date (this munges CVS/Base;    processing of CVS/Entries is done separately).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mark_up_to_date
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

