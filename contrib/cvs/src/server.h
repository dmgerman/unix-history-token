begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface between the server and the rest of CVS.  */
end_comment

begin_comment
comment|/* Miscellaneous stuff which isn't actually particularly server-specific.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STDIN_FILENO
end_ifndef

begin_define
define|#
directive|define
name|STDIN_FILENO
value|0
end_define

begin_define
define|#
directive|define
name|STDOUT_FILENO
value|1
end_define

begin_define
define|#
directive|define
name|STDERR_FILENO
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
end_ifdef

begin_comment
comment|/*  * Nonzero if we are using the server.  Used by various places to call  * server-specific functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|server_active
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|server_expanding
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Server functions exported to the rest of CVS.  */
end_comment

begin_comment
comment|/* Run the server.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|server
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

begin_comment
comment|/* See server.c for description.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|server_pathname_check
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* We have a new Entries line for a file.  TAG or DATE can be NULL.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|server_register
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|,
name|char
operator|*
name|version
operator|,
name|char
operator|*
name|timestamp
operator|,
name|char
operator|*
name|options
operator|,
name|char
operator|*
name|tag
operator|,
name|char
operator|*
name|date
operator|,
name|char
operator|*
name|conflict
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the modification time of the next file sent.  This must be    followed by a call to server_updated on the same file.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|server_modtime
name|PROTO
argument_list|(
operator|(
expr|struct
name|file_info
operator|*
name|finfo
operator|,
name|Vers_TS
operator|*
name|vers_ts
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * We want to nuke the Entries line for a file, and (unless  * server_scratch_entry_only is subsequently called) the file itself.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|server_scratch
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|name
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The file which just had server_scratch called on it needs to have only  * the Entries line removed, not the file itself.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|server_scratch_entry_only
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * We just successfully checked in FILE (which is just the bare  * filename, with no directory).  REPOSITORY is the directory for the  * repository.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|server_checked_in
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|char
operator|*
name|update_dir
operator|,
name|char
operator|*
name|repository
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|server_copy_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|char
operator|*
name|update_dir
operator|,
name|char
operator|*
name|repository
operator|,
name|char
operator|*
name|newfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send the appropriate responses for a file described by FINFO and    VERS.  This is called after server_register or server_scratch.  In    the latter case the file is to be removed (and VERS can be NULL).    In the former case, VERS must be non-NULL, and UPDATED indicates    whether the file is now up to date (SERVER_UPDATED, yes,    SERVER_MERGED, no, SERVER_PATCHED, yes, but file is a diff from    user version to repository version, SERVER_RCS_DIFF, yes, like    SERVER_PATCHED but with an RCS style diff).  MODE is the mode the    file should get, or (mode_t) -1 if this should be obtained from the    file itself.  CHECKSUM is the MD5 checksum of the file, or NULL if    this need not be sent.  If FILEBUF is not NULL, it holds the    contents of the file, in which case the file itself may not exist.    If FILEBUF is not NULL, server_updated will free it.  */
end_comment

begin_enum
enum|enum
name|server_updated_arg4
block|{
name|SERVER_UPDATED
block|,
name|SERVER_MERGED
block|,
name|SERVER_PATCHED
block|,
name|SERVER_RCS_DIFF
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|buffer
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|void
name|server_updated
name|PROTO
argument_list|(
operator|(
expr|struct
name|file_info
operator|*
name|finfo
operator|,
name|Vers_TS
operator|*
name|vers
operator|,
expr|enum
name|server_updated_arg4
name|updated
operator|,
name|mode_t
name|mode
operator|,
name|unsigned
name|char
operator|*
name|checksum
operator|,
expr|struct
name|buffer
operator|*
name|filebuf
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether we should send RCS format patches.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|server_use_rcs_diff
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set the Entries.Static flag.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|server_set_entstat
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|update_dir
operator|,
name|char
operator|*
name|repository
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clear it.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|server_clear_entstat
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|update_dir
operator|,
name|char
operator|*
name|repository
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set or clear a per-directory sticky tag or date.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|server_set_sticky
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|update_dir
operator|,
name|char
operator|*
name|repository
operator|,
name|char
operator|*
name|tag
operator|,
name|char
operator|*
name|date
operator|,
name|int
name|nonbranch
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send Template response.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|server_template
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|server_update_entries
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|char
operator|*
name|update_dir
operator|,
name|char
operator|*
name|repository
operator|,
expr|enum
name|server_updated_arg4
name|updated
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pointer to a malloc'd string which is the directory which    the server should prepend to the pathnames which it sends    to the client.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|server_dir
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|progs
block|{
name|PROG_CHECKIN
block|,
name|PROG_UPDATE
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|void
name|server_prog
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
expr|enum
name|progs
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|server_cleanup
name|PROTO
argument_list|(
operator|(
name|int
name|sig
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_FLOWCONTROL
end_ifdef

begin_comment
comment|/* Pause if it's convenient to avoid memory blowout */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|server_pause_check
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVER_FLOWCONTROL */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUTH_SERVER_SUPPORT
end_ifdef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CVS_Username
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|system_auth
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTH_SERVER_SUPPORT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVER_SUPPORT */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Stuff shared with the client.  */
end_comment

begin_struct
struct|struct
name|request
block|{
comment|/* Name of the request.  */
name|char
modifier|*
name|name
decl_stmt|;
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
comment|/*    * Function to carry out the request.  ARGS is the text of the command    * after name and, if present, a single space, have been stripped off.    */
name|void
argument_list|(
argument|*func
argument_list|)
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|args
operator|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* Stuff for use by the client.  */
enum|enum
block|{
comment|/*        * Failure to implement this request can imply a fatal        * error.  This should be set only for commands which were in the        * original version of the protocol; it should not be set for new        * commands.        */
name|rq_essential
block|,
comment|/* Some servers might lack this request.  */
name|rq_optional
block|,
comment|/*        * Set by the client to one of the following based on what this        * server actually supports.        */
name|rq_supported
block|,
name|rq_not_supported
block|,
comment|/*        * If the server supports this request, and we do too, tell the        * server by making the request.        */
name|rq_enableme
block|}
name|status
enum|;
block|}
struct|;
end_struct

begin_comment
comment|/* Table of requests ending with an entry with a NULL name.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|request
name|requests
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Gzip library, see zlib.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|gunzip_and_write
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|read_and_gzip
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
name|unsigned
name|char
operator|*
operator|*
operator|,
name|size_t
operator|*
operator|,
name|size_t
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

