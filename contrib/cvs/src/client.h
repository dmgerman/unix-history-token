begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Interface between the client and the rest of CVS.  */
end_comment

begin_comment
comment|/* Stuff shared with the server.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|mode_to_string
name|PROTO
argument_list|(
operator|(
name|mode_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|change_mode
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
name|int
name|gzip_level
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|filter_through_gzip
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|pid_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|filter_through_gunzip
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|pid_t
operator|*
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
comment|/*  * Functions to perform CVS commands via the protocol.  argc and argv  * are the arguments and the return value is the exit status (zero success  * nonzero failure).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|client_commit
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
name|client_update
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
name|client_checkout
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
name|client_diff
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
name|client_log
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
name|client_add
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
name|client_remove
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
name|client_status
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
name|client_rdiff
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
name|client_tag
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
name|client_rtag
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
name|client_import
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
name|client_admin
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
name|client_export
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
name|client_history
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
name|client_release
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
name|client_watch
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
name|client_watchers
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
name|client_editors
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
name|client_edit
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
name|client_unedit
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
name|client_init
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
name|client_annotate
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
comment|/*  * Flag variable for seeing whether common code is running as a client  * or to do a local operation.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|client_active
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Flag variable for seeing whether the server has been started yet.  * As of this writing, only edit.c:notify_check() uses it.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|server_started
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Is the -P option to checkout or update specified?  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|client_prune_dirs
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|AUTH_CLIENT_SUPPORT
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|use_authenticating_server
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|connect_to_pserver
name|PROTO
argument_list|(
operator|(
name|int
operator|*
name|tofdp
operator|,
name|int
operator|*
name|fromfdp
operator|,
name|int
name|verify_only
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|CVS_AUTH_PORT
end_ifndef

begin_define
define|#
directive|define
name|CVS_AUTH_PORT
value|2401
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CVS_AUTH_PORT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUTH_CLIENT_SUPPORT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUTH_SERVER_SUPPORT
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|authenticate_connection
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
comment|/* Talking to the server. */
end_comment

begin_decl_stmt
name|void
name|send_to_server
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|str
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|read_from_server
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|buf
operator|,
name|size_t
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Internal functions that handle client communication to server, etc.  */
end_comment

begin_decl_stmt
name|int
name|supported_request
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
name|option_with_arg
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|option
operator|,
name|char
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the responses and then close the connection.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|get_responses_and_close
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|get_server_responses
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start up the connection to the server on the other end.  */
end_comment

begin_decl_stmt
name|void
name|start_server
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send the names of all the argument files to the server.  */
end_comment

begin_decl_stmt
name|void
name|send_file_names
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
operator|,
name|unsigned
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flags for send_file_names.  */
end_comment

begin_comment
comment|/* Expand wild cards?  */
end_comment

begin_define
define|#
directive|define
name|SEND_EXPAND_WILD
value|1
end_define

begin_comment
comment|/*  * Send Repository, Modified and Entry.  argc and argv contain only  * the files to operate on (or empty for everything), not options.  * local is nonzero if we should not recurse (-l option).  */
end_comment

begin_decl_stmt
name|void
name|send_files
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
operator|,
name|int
name|local
operator|,
name|int
name|aflag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Like send_files but never send "Unchanged"--just send the contents of the  * file in that case.  This is used to fix it if you import a directory which  * happens to have CVS directories (yes it is obscure but the testsuite tests  * it).  */
end_comment

begin_decl_stmt
name|void
name|send_files_contents
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
operator|,
name|int
name|local
operator|,
name|int
name|aflag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send an argument to the remote server.  */
end_comment

begin_decl_stmt
name|void
name|send_arg
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|string
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Send a string of single-char options to the remote server, one by one.  */
end_comment

begin_decl_stmt
name|void
name|send_option_string
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|string
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

begin_escape
end_escape

begin_comment
comment|/*  * This structure is used to catalog the responses the client is  * prepared to see from the server.  */
end_comment

begin_struct
struct|struct
name|response
block|{
comment|/* Name of the response.  */
name|char
modifier|*
name|name
decl_stmt|;
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
comment|/*      * Function to carry out the response.  ARGS is the text of the      * command after name and, if present, a single space, have been      * stripped off.  The function can scribble into ARGS if it wants.      */
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
operator|,
name|int
name|len
operator|)
argument_list|)
expr_stmt|;
comment|/*      * ok and error are special; they indicate we are at the end of the      * responses, and error indicates we should exit with nonzero      * exitstatus.      */
enum|enum
block|{
name|response_type_normal
block|,
name|response_type_ok
block|,
name|response_type_error
block|}
name|type
enum|;
endif|#
directive|endif
comment|/* Used by the server to indicate whether response is supported by        the client, as set by the Valid-responses request.  */
enum|enum
block|{
comment|/*        * Failure to implement this response can imply a fatal        * error.  This should be set only for responses which were in the        * original version of the protocol; it should not be set for new        * responses.        */
name|rs_essential
block|,
comment|/* Some clients might not understand this response.  */
name|rs_optional
block|,
comment|/*        * Set by the server to one of the following based on what this        * client actually supports.        */
name|rs_supported
block|,
name|rs_not_supported
block|}
name|status
enum|;
block|}
struct|;
end_struct

begin_comment
comment|/* Table of responses ending in an entry with a NULL name.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|response
name|responses
index|[]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|client_senddate
name|PROTO
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|date
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|client_expand_modules
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
operator|,
name|int
name|local
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|client_send_expansions
name|PROTO
argument_list|(
operator|(
name|int
name|local
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|client_nonexpanded_setup
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|send_init_command
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|failed_patches
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|failed_patches_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|toplevel_wd
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|client_import_setup
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|repository
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|client_process_import_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|message
operator|,
name|char
operator|*
name|vfile
operator|,
name|char
operator|*
name|vtag
operator|,
name|int
name|targc
operator|,
name|char
operator|*
name|targv
index|[]
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
name|client_import_done
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|client_notify
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|,
name|char
operator|*
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

end_unit

