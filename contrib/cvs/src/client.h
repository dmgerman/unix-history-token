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
operator|,
name|int
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
name|file_gzip_level
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CLIENT_SUPPORT
argument_list|)
operator|||
name|defined
argument_list|(
name|SERVER_SUPPORT
argument_list|)
end_if

begin_comment
comment|/* Whether the connection should be encrypted.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cvsencrypt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Whether the connection should use per-packet authentication.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cvsauthenticate
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|ENCRYPTION
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_KERBEROS
end_ifdef

begin_comment
comment|/* We can't declare the arguments without including krb.h, and I don't    want to do that in every file.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|buffer
modifier|*
name|krb_encrypt_buffer_initialize
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_KERBEROS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GSSAPI
end_ifdef

begin_comment
comment|/* Set this to turn on GSSAPI encryption.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|cvs_gssapi_encrypt
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GSSAPI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENCRYPTION */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GSSAPI
end_ifdef

begin_comment
comment|/* We can't declare the arguments without including gssapi.h, and I    don't want to do that in every file.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|buffer
modifier|*
name|cvs_gssapi_wrap_buffer_initialize
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_GSSAPI */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined (CLIENT_SUPPORT) || defined (SERVER_SUPPORT) */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
end_ifdef

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
name|void
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
operator|,
name|int
name|do_gssapi
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AUTH_SERVER_SUPPORT
argument_list|)
operator|||
operator|(
name|defined
argument_list|(
name|SERVER_SUPPORT
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_GSSAPI
argument_list|)
operator|)
end_if

begin_decl_stmt
specifier|extern
name|void
name|pserver_authenticate_connection
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SERVER_SUPPORT
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_KERBEROS
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|void
name|kserver_authenticate_connection
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
operator|,
name|unsigned
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Flags for send_files.  */
end_comment

begin_define
define|#
directive|define
name|SEND_BUILD_DIRS
value|1
end_define

begin_define
define|#
directive|define
name|SEND_FORCE
value|2
end_define

begin_define
define|#
directive|define
name|SEND_NO_CONTENTS
value|4
end_define

begin_define
define|#
directive|define
name|BACKUP_MODIFIED_FILES
value|8
end_define

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

begin_decl_stmt
specifier|extern
name|void
name|send_a_repository
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
comment|/*      * Function to carry out the response.  ARGS is the text of the      * command after name and, if present, a single space, have been      * stripped off.  The function can scribble into ARGS if it wants.      * Note that although LEN is given, ARGS is also guaranteed to be      * '\0' terminated.      */
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
operator|,
name|char
operator|*
name|where
operator|,
name|int
name|build_dirs
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
modifier|*
name|toplevel_wd
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
operator|,
name|int
name|all_files_binary
operator|,
name|int
name|modtime
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

