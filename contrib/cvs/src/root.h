begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 1986-2005 The Free Software Foundation, Inc.  *  * Portions Copyright (C) 1998-2005 Derek Price, Ximbiot<http://ximbiot.com>,  *                                  and others.  *  * Portions Copyright (C) 1992, Brian Berliner and Jeff Polk  * Portions Copyright (C) 1989-1992, Brian Berliner  *  * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with the CVS kit.  */
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
name|extssh_method
block|,
name|fork_method
block|}
name|CVSmethod
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|method_names
index|[]
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* change this in root.c if you change 					   the enum above */
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
comment|/* The complete source CVSroot string. */
name|CVSmethod
name|method
decl_stmt|;
comment|/* One of the enum values above. */
name|char
modifier|*
name|directory
decl_stmt|;
comment|/* The directory name. */
name|unsigned
name|char
name|isremote
decl_stmt|;
comment|/* Nonzero if we are doing remote access. */
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
name|char
modifier|*
name|username
decl_stmt|;
comment|/* The username or NULL if method == local. */
name|char
modifier|*
name|password
decl_stmt|;
comment|/* The password or NULL if method == local. */
name|char
modifier|*
name|hostname
decl_stmt|;
comment|/* The hostname or NULL if method == local. */
name|int
name|port
decl_stmt|;
comment|/* The port or zero if method == local. */
name|char
modifier|*
name|proxy_hostname
decl_stmt|;
comment|/* The hostname of the proxy server, or NULL 				 * when method == local or no proxy will be 				 * used. 				 */
name|int
name|proxy_port
decl_stmt|;
comment|/* The port of the proxy or zero, as above. */
endif|#
directive|endif
comment|/* CLIENT_SUPPORT */
block|}
name|cvsroot_t
typedef|;
end_typedef

begin_decl_stmt
name|cvsroot_t
modifier|*
name|Name_Root
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|dir
operator|,
specifier|const
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_cvsroot_t
name|PROTO
argument_list|(
operator|(
name|cvsroot_t
operator|*
name|root_in
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|cvsroot_t
modifier|*
name|parse_cvsroot
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|root
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|cvsroot_t
modifier|*
name|local_cvsroot
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|Create_Root
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|dir
operator|,
specifier|const
name|char
operator|*
name|rootdir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|root_allow_add
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|root_allow_free
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|root_allow_ok
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|root_allow_used
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

