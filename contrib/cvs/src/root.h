begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001, Derek Price and others  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *  * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with the CVS kit.  */
end_comment

begin_comment
comment|/* CVSroot data structures */
end_comment

begin_comment
comment|/* Access method specified in CVSroot. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|null_method
block|,
name|local_method
block|,
name|server_method
block|,
name|pserver_method
block|,
name|kserver_method
block|,
name|gserver_method
block|,
name|ext_method
block|,
name|fork_method
block|}
name|CVSmethod
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|method_names
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* change this in root.c if you change 				   the enum above */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cvsroot_s
block|{
name|char
modifier|*
name|original
decl_stmt|;
comment|/* the complete source CVSroot string */
name|CVSmethod
name|method
decl_stmt|;
comment|/* one of the enum values above */
name|char
modifier|*
name|username
decl_stmt|;
comment|/* the username or NULL if method == local */
name|char
modifier|*
name|password
decl_stmt|;
comment|/* the username or NULL if method == local */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* the hostname or NULL if method == local */
name|int
name|port
decl_stmt|;
comment|/* the port or zero if method == local */
name|char
modifier|*
name|directory
decl_stmt|;
comment|/* the directory name */
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
name|unsigned
name|char
name|isremote
decl_stmt|;
comment|/* nonzero if we are doing remote access */
endif|#
directive|endif
comment|/* CLIENT_SUPPORT */
block|}
name|cvsroot_t
typedef|;
end_typedef

end_unit

