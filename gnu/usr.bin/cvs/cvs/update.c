begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, Brian Berliner and Jeff Polk  * Copyright (c) 1989-1992, Brian Berliner  *   * You may distribute under the terms of the GNU General Public License as  * specified in the README file that comes with the CVS 1.4 kit.  *   * "update" updates the version in the present directory with respect to the RCS  * repository.  The present version must have been created by "checkout". The  * user can keep up-to-date by calling "update" whenever he feels like it.  *   * The present version can be committed by "commit", but this keeps the version  * in tact.  *   * Arguments following the options are taken to be file names to be updated,  * rather than updating the entire directory.  *   * Modified or non-existent RCS files are checked out and reported as U  *<user_file>  *   * Modified user files are reported as M<user_file>.  If both the RCS file and  * the user file have been modified, the user file is replaced by the result  * of rcsmerge, and a backup file is written for the user in .#file.version.  * If this throws up irreconcilable differences, the file is reported as C  *<user_file>, and as M<user_file> otherwise.  *   * Files added but not yet committed are reported as A<user_file>. Files  * removed but not yet committed are reported as R<user_file>.  *   * If the current directory contains subdirectories that hold concurrent  * versions, these are updated too.  If the -d option was specified, new  * directories added to the repository are automatically created and updated  * as well.  */
end_comment

begin_include
include|#
directive|include
file|"cvs.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
end_ifdef

begin_include
include|#
directive|include
file|"update.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
end_ifdef

begin_include
include|#
directive|include
file|"md5.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
specifier|const
name|char
name|rcsid
index|[]
init|=
literal|"$CVSid: @(#)update.c 1.95 94/10/22 $"
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|USE
argument_list|(
name|rcsid
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|checkout_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|char
operator|*
name|repository
operator|,
name|List
operator|*
name|entries
operator|,
name|List
operator|*
name|srcfiles
operator|,
name|Vers_TS
operator|*
name|vers_ts
operator|,
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|patch_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|char
operator|*
name|repository
operator|,
name|List
operator|*
name|entries
operator|,
name|List
operator|*
name|srcfiles
operator|,
name|Vers_TS
operator|*
name|vers_ts
operator|,
name|char
operator|*
name|update_dir
operator|,
name|int
operator|*
name|docheckout
operator|,
expr|struct
name|stat
operator|*
name|file_info
operator|,
name|unsigned
name|char
operator|*
name|checksum
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int
name|isemptydir
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|merge_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|char
operator|*
name|repository
operator|,
name|List
operator|*
name|entries
operator|,
name|Vers_TS
operator|*
name|vers
operator|,
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|scratch_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|char
operator|*
name|repository
operator|,
name|List
operator|*
name|entries
operator|,
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|Dtype
name|update_dirent_proc
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|dir
operator|,
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

begin_decl_stmt
specifier|static
name|int
name|update_dirleave_proc
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|dir
operator|,
name|int
name|err
operator|,
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|update_file_proc
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
name|List
operator|*
name|entries
operator|,
name|List
operator|*
name|srcfiles
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|CLIENT_SUPPORT
end_ifndef

begin_decl_stmt
specifier|static
name|int
name|update_filesdone_proc
name|PROTO
argument_list|(
operator|(
name|int
name|err
operator|,
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

begin_decl_stmt
specifier|static
name|int
name|write_letter
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|int
name|letter
operator|,
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|ignore_files
name|PROTO
argument_list|(
operator|(
name|List
operator|*
name|ilist
operator|,
name|char
operator|*
name|update_dir
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
end_ifdef

begin_decl_stmt
specifier|static
name|void
name|join_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|List
operator|*
name|srcfiles
operator|,
name|Vers_TS
operator|*
name|vers_ts
operator|,
name|char
operator|*
name|update_dir
operator|,
name|List
operator|*
name|entries
operator|,
name|char
operator|*
name|repository
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|void
name|join_file
name|PROTO
argument_list|(
operator|(
name|char
operator|*
name|file
operator|,
name|List
operator|*
name|srcfiles
operator|,
name|Vers_TS
operator|*
name|vers_ts
operator|,
name|char
operator|*
name|update_dir
operator|,
name|List
operator|*
name|entries
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|char
modifier|*
name|options
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|tag
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|date
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|join_rev1
decl_stmt|,
modifier|*
name|date_rev1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|join_rev2
decl_stmt|,
modifier|*
name|date_rev2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|aflag
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|force_tag_match
init|=
literal|1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|update_build_dirs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|update_prune_dirs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|pipeout
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
end_ifdef

begin_decl_stmt
specifier|static
name|int
name|patches
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
end_ifdef

begin_decl_stmt
name|List
modifier|*
name|ignlist
init|=
operator|(
name|List
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|List
modifier|*
name|ignlist
init|=
operator|(
name|List
operator|*
operator|)
name|NULL
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|time_t
name|last_register_time
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
specifier|const
name|update_usage
index|[]
init|=
block|{
literal|"Usage: %s %s [-APdflRp] [-k kopt] [-r rev|-D date] [-j rev]\n"
block|,
literal|"    [-I ign] [-W spec] [files...]\n"
block|,
literal|"\t-A\tReset any sticky tags/date/kopts.\n"
block|,
literal|"\t-P\tPrune empty directories.\n"
block|,
literal|"\t-d\tBuild directories, like checkout does.\n"
block|,
literal|"\t-f\tForce a head revision match if tag/date not found.\n"
block|,
literal|"\t-l\tLocal directory only, no recursion.\n"
block|,
literal|"\t-R\tProcess directories recursively.\n"
block|,
literal|"\t-p\tSend updates to standard output.\n"
block|,
literal|"\t-k kopt\tUse RCS kopt -k option on checkout.\n"
block|,
literal|"\t-r rev\tUpdate using specified revision/tag.\n"
block|,
literal|"\t-D date\tSet date to update from.\n"
block|,
literal|"\t-j rev\tMerge in changes made between current revision and rev.\n"
block|,
literal|"\t-I ign\tMore files to ignore (! to reset).\n"
block|,
literal|"\t-W spec\tWrappers specification line.\n"
block|,
name|NULL
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * update is the argv,argc based front end for arg parsing  */
end_comment

begin_function
name|int
name|update
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|int
name|c
decl_stmt|,
name|err
decl_stmt|;
name|int
name|local
init|=
literal|0
decl_stmt|;
comment|/* recursive by default */
name|int
name|which
decl_stmt|;
comment|/* where to look for files and dirs */
if|if
condition|(
name|argc
operator|==
operator|-
literal|1
condition|)
name|usage
argument_list|(
name|update_usage
argument_list|)
expr_stmt|;
name|ign_setup
argument_list|()
expr_stmt|;
name|wrap_setup
argument_list|()
expr_stmt|;
comment|/* parse the args */
name|optind
operator|=
literal|1
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getopt
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
literal|"ApPflRQqduk:r:D:j:I:W:"
argument_list|)
operator|)
operator|!=
operator|-
literal|1
condition|)
block|{
switch|switch
condition|(
name|c
condition|)
block|{
case|case
literal|'A'
case|:
name|aflag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'I'
case|:
name|ign_add
argument_list|(
name|optarg
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'W'
case|:
name|wrap_add
argument_list|(
name|optarg
argument_list|,
literal|0
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'k'
case|:
if|if
condition|(
name|options
condition|)
name|free
argument_list|(
name|options
argument_list|)
expr_stmt|;
name|options
operator|=
name|RCS_check_kflag
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'l'
case|:
name|local
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'R'
case|:
name|local
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'Q'
case|:
case|case
literal|'q'
case|:
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
comment|/* The CVS 1.5 client sends these options (in addition to 		   Global_option requests), so we must ignore them.  */
if|if
condition|(
operator|!
name|server_active
condition|)
endif|#
directive|endif
name|error
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|"-q or -Q must be specified before \"%s\""
argument_list|,
name|command_name
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
name|update_build_dirs
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'f'
case|:
name|force_tag_match
operator|=
literal|0
expr_stmt|;
break|break;
case|case
literal|'r'
case|:
name|tag
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'D'
case|:
name|date
operator|=
name|Make_Date
argument_list|(
name|optarg
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'P'
case|:
name|update_prune_dirs
operator|=
literal|1
expr_stmt|;
break|break;
case|case
literal|'p'
case|:
name|pipeout
operator|=
literal|1
expr_stmt|;
name|noexec
operator|=
literal|1
expr_stmt|;
comment|/* so no locks will be created */
break|break;
case|case
literal|'j'
case|:
if|if
condition|(
name|join_rev2
condition|)
name|error
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|,
literal|"only two -j options can be specified"
argument_list|)
expr_stmt|;
if|if
condition|(
name|join_rev1
condition|)
name|join_rev2
operator|=
name|optarg
expr_stmt|;
else|else
name|join_rev1
operator|=
name|optarg
expr_stmt|;
break|break;
case|case
literal|'u'
case|:
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
if|if
condition|(
name|server_active
condition|)
name|patches
operator|=
literal|1
expr_stmt|;
else|else
endif|#
directive|endif
name|usage
argument_list|(
name|update_usage
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'?'
case|:
default|default:
name|usage
argument_list|(
name|update_usage
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|argc
operator|-=
name|optind
expr_stmt|;
name|argv
operator|+=
name|optind
expr_stmt|;
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
if|if
condition|(
name|client_active
condition|)
block|{
comment|/* The first pass does the regular update.  If we receive at least 	   one patch which failed, we do a second pass and just fetch 	   those files whose patches failed.  */
do|do
block|{
name|int
name|status
decl_stmt|;
name|start_server
argument_list|()
expr_stmt|;
name|ign_setup
argument_list|()
expr_stmt|;
if|if
condition|(
name|local
condition|)
name|send_arg
argument_list|(
literal|"-l"
argument_list|)
expr_stmt|;
if|if
condition|(
name|update_build_dirs
condition|)
name|send_arg
argument_list|(
literal|"-d"
argument_list|)
expr_stmt|;
if|if
condition|(
name|pipeout
condition|)
name|send_arg
argument_list|(
literal|"-p"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|force_tag_match
condition|)
name|send_arg
argument_list|(
literal|"-f"
argument_list|)
expr_stmt|;
if|if
condition|(
name|aflag
condition|)
name|send_arg
argument_list|(
literal|"-A"
argument_list|)
expr_stmt|;
if|if
condition|(
name|update_prune_dirs
condition|)
name|send_arg
argument_list|(
literal|"-P"
argument_list|)
expr_stmt|;
name|client_prune_dirs
operator|=
name|update_prune_dirs
expr_stmt|;
name|option_with_arg
argument_list|(
literal|"-r"
argument_list|,
name|tag
argument_list|)
expr_stmt|;
if|if
condition|(
name|date
condition|)
name|client_senddate
argument_list|(
name|date
argument_list|)
expr_stmt|;
if|if
condition|(
name|join_rev1
condition|)
name|option_with_arg
argument_list|(
literal|"-j"
argument_list|,
name|join_rev1
argument_list|)
expr_stmt|;
if|if
condition|(
name|join_rev2
condition|)
name|option_with_arg
argument_list|(
literal|"-j"
argument_list|,
name|join_rev2
argument_list|)
expr_stmt|;
comment|/* If the server supports the command "update-patches", that means 	       that it knows how to handle the -u argument to update, which 	       means to send patches instead of complete files.  */
if|if
condition|(
name|failed_patches
operator|==
name|NULL
condition|)
block|{
name|struct
name|request
modifier|*
name|rq
decl_stmt|;
for|for
control|(
name|rq
operator|=
name|requests
init|;
name|rq
operator|->
name|name
operator|!=
name|NULL
condition|;
name|rq
operator|++
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|rq
operator|->
name|name
argument_list|,
literal|"update-patches"
argument_list|)
operator|==
literal|0
condition|)
block|{
if|if
condition|(
name|rq
operator|->
name|status
operator|==
name|rq_supported
condition|)
block|{
name|send_arg
argument_list|(
literal|"-u"
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
block|}
if|if
condition|(
name|failed_patches
operator|==
name|NULL
condition|)
name|send_files
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|local
argument_list|,
name|aflag
argument_list|)
expr_stmt|;
else|else
block|{
name|int
name|i
decl_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s client: refetching unpatchable files\n"
argument_list|,
name|program_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|toplevel_wd
index|[
literal|0
index|]
operator|!=
literal|'\0'
operator|&&
name|chdir
argument_list|(
name|toplevel_wd
argument_list|)
operator|<
literal|0
condition|)
block|{
name|error
argument_list|(
literal|1
argument_list|,
name|errno
argument_list|,
literal|"could not chdir to %s"
argument_list|,
name|toplevel_wd
argument_list|)
expr_stmt|;
block|}
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|failed_patches_count
condition|;
name|i
operator|++
control|)
operator|(
name|void
operator|)
name|unlink_file
argument_list|(
name|failed_patches
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|send_files
argument_list|(
name|failed_patches_count
argument_list|,
name|failed_patches
argument_list|,
name|local
argument_list|,
name|aflag
argument_list|)
expr_stmt|;
block|}
name|failed_patches
operator|=
name|NULL
expr_stmt|;
name|failed_patches_count
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|fprintf
argument_list|(
name|to_server
argument_list|,
literal|"update\n"
argument_list|)
operator|<
literal|0
condition|)
name|error
argument_list|(
literal|1
argument_list|,
name|errno
argument_list|,
literal|"writing to server"
argument_list|)
expr_stmt|;
name|status
operator|=
name|get_responses_and_close
argument_list|()
expr_stmt|;
if|if
condition|(
name|status
operator|!=
literal|0
condition|)
return|return
name|status
return|;
block|}
do|while
condition|(
name|failed_patches
operator|!=
name|NULL
condition|)
do|;
return|return
literal|0
return|;
block|}
endif|#
directive|endif
comment|/*      * If we are updating the entire directory (for real) and building dirs      * as we go, we make sure there is no static entries file and write the      * tag file as appropriate      */
if|if
condition|(
name|argc
operator|<=
literal|0
operator|&&
operator|!
name|pipeout
condition|)
block|{
if|if
condition|(
name|update_build_dirs
condition|)
block|{
if|if
condition|(
name|unlink_file
argument_list|(
name|CVSADM_ENTSTAT
argument_list|)
operator|<
literal|0
operator|&&
operator|!
name|existence_error
argument_list|(
name|errno
argument_list|)
condition|)
name|error
argument_list|(
literal|1
argument_list|,
name|errno
argument_list|,
literal|"cannot remove file %s"
argument_list|,
name|CVSADM_ENTSTAT
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
if|if
condition|(
name|server_active
condition|)
name|server_clear_entstat
argument_list|(
literal|"."
argument_list|,
name|Name_Repository
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/* keep the CVS/Tag file current with the specified arguments */
if|if
condition|(
name|aflag
operator|||
name|tag
operator|||
name|date
condition|)
block|{
name|WriteTag
argument_list|(
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
name|tag
argument_list|,
name|date
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
if|if
condition|(
name|server_active
condition|)
name|server_set_sticky
argument_list|(
literal|"."
argument_list|,
name|Name_Repository
argument_list|(
name|NULL
argument_list|,
name|NULL
argument_list|)
argument_list|,
name|tag
argument_list|,
name|date
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
block|}
comment|/* look for files/dirs locally and in the repository */
name|which
operator|=
name|W_LOCAL
operator||
name|W_REPOS
expr_stmt|;
comment|/* look in the attic too if a tag or date is specified */
if|if
condition|(
name|tag
operator|!=
name|NULL
operator|||
name|date
operator|!=
name|NULL
operator|||
name|joining
argument_list|()
condition|)
name|which
operator||=
name|W_ATTIC
expr_stmt|;
comment|/* call the command line interface */
name|err
operator|=
name|do_update
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|,
name|options
argument_list|,
name|tag
argument_list|,
name|date
argument_list|,
name|force_tag_match
argument_list|,
name|local
argument_list|,
name|update_build_dirs
argument_list|,
name|aflag
argument_list|,
name|update_prune_dirs
argument_list|,
name|pipeout
argument_list|,
name|which
argument_list|,
name|join_rev1
argument_list|,
name|join_rev2
argument_list|,
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
comment|/* free the space Make_Date allocated if necessary */
if|if
condition|(
name|date
operator|!=
name|NULL
condition|)
name|free
argument_list|(
name|date
argument_list|)
expr_stmt|;
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Command line interface to update (used by checkout)  */
end_comment

begin_function
name|int
name|do_update
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|,
name|xoptions
parameter_list|,
name|xtag
parameter_list|,
name|xdate
parameter_list|,
name|xforce
parameter_list|,
name|local
parameter_list|,
name|xbuild
parameter_list|,
name|xaflag
parameter_list|,
name|xprune
parameter_list|,
name|xpipeout
parameter_list|,
name|which
parameter_list|,
name|xjoin_rev1
parameter_list|,
name|xjoin_rev2
parameter_list|,
name|preload_update_dir
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
name|char
modifier|*
name|xoptions
decl_stmt|;
name|char
modifier|*
name|xtag
decl_stmt|;
name|char
modifier|*
name|xdate
decl_stmt|;
name|int
name|xforce
decl_stmt|;
name|int
name|local
decl_stmt|;
name|int
name|xbuild
decl_stmt|;
name|int
name|xaflag
decl_stmt|;
name|int
name|xprune
decl_stmt|;
name|int
name|xpipeout
decl_stmt|;
name|int
name|which
decl_stmt|;
name|char
modifier|*
name|xjoin_rev1
decl_stmt|;
name|char
modifier|*
name|xjoin_rev2
decl_stmt|;
name|char
modifier|*
name|preload_update_dir
decl_stmt|;
block|{
name|int
name|err
init|=
literal|0
decl_stmt|;
name|char
modifier|*
name|cp
decl_stmt|;
comment|/* fill in the statics */
name|options
operator|=
name|xoptions
expr_stmt|;
name|tag
operator|=
name|xtag
expr_stmt|;
name|date
operator|=
name|xdate
expr_stmt|;
name|force_tag_match
operator|=
name|xforce
expr_stmt|;
name|update_build_dirs
operator|=
name|xbuild
expr_stmt|;
name|aflag
operator|=
name|xaflag
expr_stmt|;
name|update_prune_dirs
operator|=
name|xprune
expr_stmt|;
name|pipeout
operator|=
name|xpipeout
expr_stmt|;
comment|/* setup the join support */
name|join_rev1
operator|=
name|xjoin_rev1
expr_stmt|;
name|join_rev2
operator|=
name|xjoin_rev2
expr_stmt|;
if|if
condition|(
name|join_rev1
operator|&&
operator|(
name|cp
operator|=
name|strchr
argument_list|(
name|join_rev1
argument_list|,
literal|':'
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
operator|*
name|cp
operator|++
operator|=
literal|'\0'
expr_stmt|;
name|date_rev1
operator|=
name|Make_Date
argument_list|(
name|cp
argument_list|)
expr_stmt|;
block|}
else|else
name|date_rev1
operator|=
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
if|if
condition|(
name|join_rev2
operator|&&
operator|(
name|cp
operator|=
name|strchr
argument_list|(
name|join_rev2
argument_list|,
literal|':'
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
operator|*
name|cp
operator|++
operator|=
literal|'\0'
expr_stmt|;
name|date_rev2
operator|=
name|Make_Date
argument_list|(
name|cp
argument_list|)
expr_stmt|;
block|}
else|else
name|date_rev2
operator|=
operator|(
name|char
operator|*
operator|)
name|NULL
expr_stmt|;
comment|/* call the recursion processor */
name|err
operator|=
name|start_recursion
argument_list|(
name|update_file_proc
argument_list|,
name|update_filesdone_proc
argument_list|,
name|update_dirent_proc
argument_list|,
name|update_dirleave_proc
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|,
name|local
argument_list|,
name|which
argument_list|,
name|aflag
argument_list|,
literal|1
argument_list|,
name|preload_update_dir
argument_list|,
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* see if we need to sleep before returning */
if|if
condition|(
name|last_register_time
condition|)
block|{
name|time_t
name|now
decl_stmt|;
operator|(
name|void
operator|)
name|time
argument_list|(
operator|&
name|now
argument_list|)
expr_stmt|;
if|if
condition|(
name|now
operator|==
name|last_register_time
condition|)
name|sleep
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|/* to avoid time-stamp races */
block|}
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * This is the callback proc for update.  It is called for each file in each  * directory by the recursion code.  The current directory is the local  * instantiation.  file is the file name we are to operate on. update_dir is  * set to the path relative to where we started (for pretty printing).  * repository is the repository. entries and srcfiles are the pre-parsed  * entries and source control files.  *   * This routine decides what needs to be done for each file and does the  * appropriate magic for checkout  */
end_comment

begin_function
specifier|static
name|int
name|update_file_proc
parameter_list|(
name|file
parameter_list|,
name|update_dir
parameter_list|,
name|repository
parameter_list|,
name|entries
parameter_list|,
name|srcfiles
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|;
name|char
modifier|*
name|update_dir
decl_stmt|;
name|char
modifier|*
name|repository
decl_stmt|;
name|List
modifier|*
name|entries
decl_stmt|;
name|List
modifier|*
name|srcfiles
decl_stmt|;
block|{
name|int
name|retval
decl_stmt|;
name|Ctype
name|status
decl_stmt|;
name|Vers_TS
modifier|*
name|vers
decl_stmt|;
name|status
operator|=
name|Classify_File
argument_list|(
name|file
argument_list|,
name|tag
argument_list|,
name|date
argument_list|,
name|options
argument_list|,
name|force_tag_match
argument_list|,
name|aflag
argument_list|,
name|repository
argument_list|,
name|entries
argument_list|,
name|srcfiles
argument_list|,
operator|&
name|vers
argument_list|,
name|update_dir
argument_list|,
name|pipeout
argument_list|)
expr_stmt|;
if|if
condition|(
name|pipeout
condition|)
block|{
comment|/* 	 * We just return success without doing anything if any of the really 	 * funky cases occur 	 *  	 * If there is still a valid RCS file, do a regular checkout type 	 * operation 	 */
switch|switch
condition|(
name|status
condition|)
block|{
case|case
name|T_UNKNOWN
case|:
comment|/* unknown file was explicitly asked 					 * about */
case|case
name|T_REMOVE_ENTRY
case|:
comment|/* needs to be un-registered */
case|case
name|T_ADDED
case|:
comment|/* added but not committed */
name|retval
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|T_CONFLICT
case|:
comment|/* old punt-type errors */
name|retval
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|T_UPTODATE
case|:
comment|/* file was already up-to-date */
case|case
name|T_NEEDS_MERGE
case|:
comment|/* needs merging */
case|case
name|T_MODIFIED
case|:
comment|/* locally modified */
case|case
name|T_REMOVED
case|:
comment|/* removed but not committed */
case|case
name|T_CHECKOUT
case|:
comment|/* needs checkout */
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
case|case
name|T_PATCH
case|:
comment|/* needs patch */
endif|#
directive|endif
name|retval
operator|=
name|checkout_file
argument_list|(
name|file
argument_list|,
name|repository
argument_list|,
name|entries
argument_list|,
name|srcfiles
argument_list|,
name|vers
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
break|break;
default|default:
comment|/* can't ever happen :-) */
name|error
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|"unknown file status %d for file %s"
argument_list|,
name|status
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
else|else
block|{
switch|switch
condition|(
name|status
condition|)
block|{
case|case
name|T_UNKNOWN
case|:
comment|/* unknown file was explicitly asked 					 * about */
case|case
name|T_UPTODATE
case|:
comment|/* file was already up-to-date */
name|retval
operator|=
literal|0
expr_stmt|;
break|break;
case|case
name|T_CONFLICT
case|:
comment|/* old punt-type errors */
name|retval
operator|=
literal|1
expr_stmt|;
operator|(
name|void
operator|)
name|write_letter
argument_list|(
name|file
argument_list|,
literal|'C'
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
break|break;
case|case
name|T_NEEDS_MERGE
case|:
comment|/* needs merging */
if|if
condition|(
name|noexec
condition|)
block|{
name|retval
operator|=
literal|1
expr_stmt|;
operator|(
name|void
operator|)
name|write_letter
argument_list|(
name|file
argument_list|,
literal|'C'
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|wrap_merge_is_copy
argument_list|(
name|file
argument_list|)
condition|)
comment|/* Should we be warning the user that we are 			 * overwriting the user's copy of the file?  */
name|retval
operator|=
name|checkout_file
argument_list|(
name|file
argument_list|,
name|repository
argument_list|,
name|entries
argument_list|,
name|srcfiles
argument_list|,
name|vers
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
else|else
name|retval
operator|=
name|merge_file
argument_list|(
name|file
argument_list|,
name|repository
argument_list|,
name|entries
argument_list|,
name|vers
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|T_MODIFIED
case|:
comment|/* locally modified */
name|retval
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|vers
operator|->
name|ts_conflict
condition|)
block|{
name|char
modifier|*
name|filestamp
decl_stmt|;
name|int
name|retcode
decl_stmt|;
comment|/* 		     * If the timestamp has changed and no conflict indicators 		     * are found, it isn't a 'C' any more. 		     */
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
if|if
condition|(
name|server_active
condition|)
name|retcode
operator|=
name|vers
operator|->
name|ts_conflict
index|[
literal|0
index|]
operator|!=
literal|'='
expr_stmt|;
else|else
block|{
name|filestamp
operator|=
name|time_stamp
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|retcode
operator|=
name|strcmp
argument_list|(
name|vers
operator|->
name|ts_conflict
argument_list|,
name|filestamp
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|filestamp
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
name|filestamp
operator|=
name|time_stamp
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|retcode
operator|=
name|strcmp
argument_list|(
name|vers
operator|->
name|ts_conflict
argument_list|,
name|filestamp
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|filestamp
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|retcode
condition|)
block|{
comment|/* 			 * If the timestamps differ, look for Conflict 			 * indicators to see if 'C' anyway. 			 */
name|run_setup
argument_list|(
literal|"%s"
argument_list|,
name|GREP
argument_list|)
expr_stmt|;
name|run_arg
argument_list|(
name|RCS_MERGE_PAT
argument_list|)
expr_stmt|;
name|run_arg
argument_list|(
name|file
argument_list|)
expr_stmt|;
name|retcode
operator|=
name|run_exec
argument_list|(
name|RUN_TTY
argument_list|,
name|DEVNULL
argument_list|,
name|RUN_TTY
argument_list|,
name|RUN_NORMAL
argument_list|)
expr_stmt|;
if|if
condition|(
name|retcode
operator|==
operator|-
literal|1
condition|)
block|{
if|if
condition|(
name|update_dir
index|[
literal|0
index|]
operator|==
literal|'\0'
condition|)
name|error
argument_list|(
literal|1
argument_list|,
name|errno
argument_list|,
literal|"fork failed while examining conflict in `%s'"
argument_list|,
name|file
argument_list|)
expr_stmt|;
else|else
name|error
argument_list|(
literal|1
argument_list|,
name|errno
argument_list|,
literal|"fork failed while examining conflict in `%s/%s'"
argument_list|,
name|update_dir
argument_list|,
name|file
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|retcode
condition|)
block|{
operator|(
name|void
operator|)
name|write_letter
argument_list|(
name|file
argument_list|,
literal|'C'
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|1
expr_stmt|;
block|}
else|else
block|{
comment|/* Reregister to clear conflict flag. */
name|Register
argument_list|(
name|entries
argument_list|,
name|file
argument_list|,
name|vers
operator|->
name|vn_rcs
argument_list|,
name|vers
operator|->
name|ts_rcs
argument_list|,
name|vers
operator|->
name|options
argument_list|,
name|vers
operator|->
name|tag
argument_list|,
name|vers
operator|->
name|date
argument_list|,
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|retval
condition|)
name|retval
operator|=
name|write_letter
argument_list|(
name|file
argument_list|,
literal|'M'
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
break|break;
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
case|case
name|T_PATCH
case|:
comment|/* needs patch */
if|if
condition|(
name|patches
condition|)
block|{
name|int
name|docheckout
decl_stmt|;
name|struct
name|stat
name|file_info
decl_stmt|;
name|unsigned
name|char
name|checksum
index|[
literal|16
index|]
decl_stmt|;
name|retval
operator|=
name|patch_file
argument_list|(
name|file
argument_list|,
name|repository
argument_list|,
name|entries
argument_list|,
name|srcfiles
argument_list|,
name|vers
argument_list|,
name|update_dir
argument_list|,
operator|&
name|docheckout
argument_list|,
operator|&
name|file_info
argument_list|,
name|checksum
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|docheckout
condition|)
block|{
if|if
condition|(
name|server_active
operator|&&
name|retval
operator|==
literal|0
condition|)
name|server_updated
argument_list|(
name|file
argument_list|,
name|update_dir
argument_list|,
name|repository
argument_list|,
name|SERVER_PATCHED
argument_list|,
operator|&
name|file_info
argument_list|,
name|checksum
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
comment|/* Fall through.  */
comment|/* If we're not running as a server, just check the 		   file out.  It's simpler and faster than starting up 		   two new processes (diff and patch).  */
comment|/* Fall through.  */
endif|#
directive|endif
case|case
name|T_CHECKOUT
case|:
comment|/* needs checkout */
name|retval
operator|=
name|checkout_file
argument_list|(
name|file
argument_list|,
name|repository
argument_list|,
name|entries
argument_list|,
name|srcfiles
argument_list|,
name|vers
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
if|if
condition|(
name|server_active
operator|&&
name|retval
operator|==
literal|0
condition|)
name|server_updated
argument_list|(
name|file
argument_list|,
name|update_dir
argument_list|,
name|repository
argument_list|,
name|SERVER_UPDATED
argument_list|,
operator|(
expr|struct
name|stat
operator|*
operator|)
name|NULL
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
case|case
name|T_ADDED
case|:
comment|/* added but not committed */
name|retval
operator|=
name|write_letter
argument_list|(
name|file
argument_list|,
literal|'A'
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
break|break;
case|case
name|T_REMOVED
case|:
comment|/* removed but not committed */
name|retval
operator|=
name|write_letter
argument_list|(
name|file
argument_list|,
literal|'R'
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
break|break;
case|case
name|T_REMOVE_ENTRY
case|:
comment|/* needs to be un-registered */
name|retval
operator|=
name|scratch_file
argument_list|(
name|file
argument_list|,
name|repository
argument_list|,
name|entries
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
if|if
condition|(
name|server_active
operator|&&
name|retval
operator|==
literal|0
condition|)
name|server_updated
argument_list|(
name|file
argument_list|,
name|update_dir
argument_list|,
name|repository
argument_list|,
name|SERVER_UPDATED
argument_list|,
operator|(
expr|struct
name|stat
operator|*
operator|)
name|NULL
argument_list|,
operator|(
name|unsigned
name|char
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
endif|#
directive|endif
break|break;
default|default:
comment|/* can't ever happen :-) */
name|error
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|"unknown file status %d for file %s"
argument_list|,
name|status
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|retval
operator|=
literal|0
expr_stmt|;
break|break;
block|}
block|}
comment|/* only try to join if things have gone well thus far */
if|if
condition|(
name|retval
operator|==
literal|0
operator|&&
name|join_rev1
condition|)
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
name|join_file
argument_list|(
name|file
argument_list|,
name|srcfiles
argument_list|,
name|vers
argument_list|,
name|update_dir
argument_list|,
name|entries
argument_list|,
name|repository
argument_list|)
expr_stmt|;
else|#
directive|else
name|join_file
argument_list|(
name|file
argument_list|,
name|srcfiles
argument_list|,
name|vers
argument_list|,
name|update_dir
argument_list|,
name|entries
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* if this directory has an ignore list, add this file to it */
if|if
condition|(
name|ignlist
condition|)
block|{
name|Node
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|getnode
argument_list|()
expr_stmt|;
name|p
operator|->
name|type
operator|=
name|FILES
expr_stmt|;
name|p
operator|->
name|key
operator|=
name|xstrdup
argument_list|(
name|file
argument_list|)
expr_stmt|;
if|if
condition|(
name|addnode
argument_list|(
name|ignlist
argument_list|,
name|p
argument_list|)
operator|!=
literal|0
condition|)
name|freenode
argument_list|(
name|p
argument_list|)
expr_stmt|;
block|}
name|freevers_ts
argument_list|(
operator|&
name|vers
argument_list|)
expr_stmt|;
return|return
operator|(
name|retval
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * update_filesdone_proc () is used  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
end_ifdef

begin_comment
comment|/* Also used by client.c  */
end_comment

begin_function
name|int
else|#
directive|else
specifier|static
name|int
endif|#
directive|endif
name|update_filesdone_proc
parameter_list|(
name|err
parameter_list|,
name|repository
parameter_list|,
name|update_dir
parameter_list|)
name|int
name|err
decl_stmt|;
name|char
modifier|*
name|repository
decl_stmt|;
name|char
modifier|*
name|update_dir
decl_stmt|;
block|{
comment|/* if this directory has an ignore list, process it then free it */
if|if
condition|(
name|ignlist
condition|)
block|{
name|ignore_files
argument_list|(
name|ignlist
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
name|dellist
argument_list|(
operator|&
name|ignlist
argument_list|)
expr_stmt|;
block|}
comment|/* Clean up CVS admin dirs if we are export */
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
comment|/* In the client, we need to clean these up after we create them.  Doing        it here might would clean up the user's previous contents even on        SIGINT which probably is bad.  */
if|if
condition|(
operator|!
name|client_active
operator|&&
name|strcmp
argument_list|(
name|command_name
argument_list|,
literal|"export"
argument_list|)
operator|==
literal|0
condition|)
else|#
directive|else
if|if
condition|(
name|strcmp
argument_list|(
name|command_name
argument_list|,
literal|"export"
argument_list|)
operator|==
literal|0
condition|)
endif|#
directive|endif
block|{
name|run_setup
argument_list|(
literal|"%s -fr"
argument_list|,
name|RM
argument_list|)
expr_stmt|;
name|run_arg
argument_list|(
name|CVSADM
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|run_exec
argument_list|(
name|RUN_TTY
argument_list|,
name|RUN_TTY
argument_list|,
name|RUN_TTY
argument_list|,
name|RUN_NORMAL
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|CVSADM_ROOT
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
elseif|else
if|if
condition|(
operator|!
name|server_active
operator|&&
operator|!
name|pipeout
condition|)
else|#
directive|else
elseif|else
if|if
condition|(
operator|!
name|pipeout
condition|)
endif|#
directive|endif
comment|/* SERVER_SUPPORT */
block|{
comment|/* If there is no CVS/Root file, add one */
ifdef|#
directive|ifdef
name|CLIENT_SUPPORT
if|if
condition|(
operator|!
name|isfile
argument_list|(
name|CVSADM_ROOT
argument_list|)
comment|/* but only if we want it */
operator|&&
operator|!
operator|(
name|getenv
argument_list|(
literal|"CVS_IGNORE_REMOTE_ROOT"
argument_list|)
operator|&&
name|strchr
argument_list|(
name|CVSroot
argument_list|,
literal|':'
argument_list|)
operator|)
condition|)
else|#
directive|else
comment|/* No CLIENT_SUPPORT */
if|if
condition|(
operator|!
name|isfile
argument_list|(
name|CVSADM_ROOT
argument_list|)
condition|)
endif|#
directive|endif
comment|/* No CLIENT_SUPPORT */
name|Create_Root
argument_list|(
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
name|CVSroot
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* CVSADM_ROOT */
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * update_dirent_proc () is called back by the recursion processor before a  * sub-directory is processed for update.  In this case, update_dirent proc  * will probably create the directory unless -d isn't specified and this is a  * new directory.  A return code of 0 indicates the directory should be  * processed by the recursion code.  A return of non-zero indicates the  * recursion code should skip this directory.  */
end_comment

begin_function
specifier|static
name|Dtype
name|update_dirent_proc
parameter_list|(
name|dir
parameter_list|,
name|repository
parameter_list|,
name|update_dir
parameter_list|)
name|char
modifier|*
name|dir
decl_stmt|;
name|char
modifier|*
name|repository
decl_stmt|;
name|char
modifier|*
name|update_dir
decl_stmt|;
block|{
if|if
condition|(
name|ignore_directory
argument_list|(
name|update_dir
argument_list|)
condition|)
block|{
comment|/* print the warm fuzzy message */
if|if
condition|(
operator|!
name|quiet
condition|)
name|error
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|"Ignoring %s"
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
return|return
name|R_SKIP_ALL
return|;
block|}
if|if
condition|(
operator|!
name|isdir
argument_list|(
name|dir
argument_list|)
condition|)
block|{
comment|/* if we aren't building dirs, blow it off */
if|if
condition|(
operator|!
name|update_build_dirs
condition|)
return|return
operator|(
name|R_SKIP_ALL
operator|)
return|;
if|if
condition|(
name|noexec
condition|)
block|{
comment|/* ignore the missing dir if -n is specified */
name|error
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|"New directory `%s' -- ignored"
argument_list|,
name|dir
argument_list|)
expr_stmt|;
return|return
operator|(
name|R_SKIP_ALL
operator|)
return|;
block|}
else|else
block|{
comment|/* otherwise, create the dir and appropriate adm files */
name|make_directory
argument_list|(
name|dir
argument_list|)
expr_stmt|;
name|Create_Admin
argument_list|(
name|dir
argument_list|,
name|update_dir
argument_list|,
name|repository
argument_list|,
name|tag
argument_list|,
name|date
argument_list|)
expr_stmt|;
block|}
block|}
comment|/*      * If we are building dirs and not going to stdout, we make sure there is      * no static entries file and write the tag file as appropriate      */
if|if
condition|(
operator|!
name|pipeout
condition|)
block|{
if|if
condition|(
name|update_build_dirs
condition|)
block|{
name|char
name|tmp
index|[
name|PATH_MAX
index|]
decl_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|tmp
argument_list|,
literal|"%s/%s"
argument_list|,
name|dir
argument_list|,
name|CVSADM_ENTSTAT
argument_list|)
expr_stmt|;
if|if
condition|(
name|unlink_file
argument_list|(
name|tmp
argument_list|)
operator|<
literal|0
operator|&&
operator|!
name|existence_error
argument_list|(
name|errno
argument_list|)
condition|)
name|error
argument_list|(
literal|1
argument_list|,
name|errno
argument_list|,
literal|"cannot remove file %s"
argument_list|,
name|tmp
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
if|if
condition|(
name|server_active
condition|)
name|server_clear_entstat
argument_list|(
name|update_dir
argument_list|,
name|repository
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/* keep the CVS/Tag file current with the specified arguments */
if|if
condition|(
name|aflag
operator|||
name|tag
operator|||
name|date
condition|)
block|{
name|WriteTag
argument_list|(
name|dir
argument_list|,
name|tag
argument_list|,
name|date
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
if|if
condition|(
name|server_active
condition|)
name|server_set_sticky
argument_list|(
name|update_dir
argument_list|,
name|repository
argument_list|,
name|tag
argument_list|,
name|date
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
comment|/* initialize the ignore list for this directory */
name|ignlist
operator|=
name|getlist
argument_list|()
expr_stmt|;
block|}
comment|/* print the warm fuzzy message */
if|if
condition|(
operator|!
name|quiet
condition|)
name|error
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|"Updating %s"
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
return|return
operator|(
name|R_PROCESS
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * update_dirleave_proc () is called back by the recursion code upon leaving  * a directory.  It will prune empty directories if needed and will execute  * any appropriate update programs.  */
end_comment

begin_comment
comment|/* ARGSUSED */
end_comment

begin_function
specifier|static
name|int
name|update_dirleave_proc
parameter_list|(
name|dir
parameter_list|,
name|err
parameter_list|,
name|update_dir
parameter_list|)
name|char
modifier|*
name|dir
decl_stmt|;
name|int
name|err
decl_stmt|;
name|char
modifier|*
name|update_dir
decl_stmt|;
block|{
name|FILE
modifier|*
name|fp
decl_stmt|;
comment|/* run the update_prog if there is one */
if|if
condition|(
name|err
operator|==
literal|0
operator|&&
operator|!
name|pipeout
operator|&&
operator|!
name|noexec
operator|&&
operator|(
name|fp
operator|=
name|fopen
argument_list|(
name|CVSADM_UPROG
argument_list|,
literal|"r"
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
name|char
modifier|*
name|cp
decl_stmt|;
name|char
modifier|*
name|repository
decl_stmt|;
name|char
name|line
index|[
name|MAXLINELEN
index|]
decl_stmt|;
name|repository
operator|=
name|Name_Repository
argument_list|(
operator|(
name|char
operator|*
operator|)
name|NULL
argument_list|,
name|update_dir
argument_list|)
expr_stmt|;
if|if
condition|(
name|fgets
argument_list|(
name|line
argument_list|,
sizeof|sizeof
argument_list|(
name|line
argument_list|)
argument_list|,
name|fp
argument_list|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
operator|(
name|cp
operator|=
name|strrchr
argument_list|(
name|line
argument_list|,
literal|'\n'
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
operator|*
name|cp
operator|=
literal|'\0'
expr_stmt|;
name|run_setup
argument_list|(
literal|"%s %s"
argument_list|,
name|line
argument_list|,
name|repository
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"%s %s: Executing '"
argument_list|,
name|program_name
argument_list|,
name|command_name
argument_list|)
expr_stmt|;
name|run_print
argument_list|(
name|stdout
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|printf
argument_list|(
literal|"'\n"
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|run_exec
argument_list|(
name|RUN_TTY
argument_list|,
name|RUN_TTY
argument_list|,
name|RUN_TTY
argument_list|,
name|RUN_NORMAL
argument_list|)
expr_stmt|;
block|}
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|fp
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|repository
argument_list|)
expr_stmt|;
block|}
comment|/* FIXME: chdir ("..") loses with symlinks.  */
comment|/* Prune empty dirs on the way out - if necessary */
operator|(
name|void
operator|)
name|chdir
argument_list|(
literal|".."
argument_list|)
expr_stmt|;
if|if
condition|(
name|update_prune_dirs
operator|&&
name|isemptydir
argument_list|(
name|dir
argument_list|)
condition|)
block|{
name|run_setup
argument_list|(
literal|"%s -fr"
argument_list|,
name|RM
argument_list|)
expr_stmt|;
name|run_arg
argument_list|(
name|dir
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|run_exec
argument_list|(
name|RUN_TTY
argument_list|,
name|RUN_TTY
argument_list|,
name|RUN_TTY
argument_list|,
name|RUN_NORMAL
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|err
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Returns 1 if the argument directory is completely empty, other than the  * existence of the CVS directory entry.  Zero otherwise.  */
end_comment

begin_function
specifier|static
name|int
name|isemptydir
parameter_list|(
name|dir
parameter_list|)
name|char
modifier|*
name|dir
decl_stmt|;
block|{
name|DIR
modifier|*
name|dirp
decl_stmt|;
name|struct
name|dirent
modifier|*
name|dp
decl_stmt|;
if|if
condition|(
operator|(
name|dirp
operator|=
name|opendir
argument_list|(
name|dir
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
name|error
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
literal|"cannot open directory %s for empty check"
argument_list|,
name|dir
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
while|while
condition|(
operator|(
name|dp
operator|=
name|readdir
argument_list|(
name|dirp
argument_list|)
operator|)
operator|!=
name|NULL
condition|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|dp
operator|->
name|d_name
argument_list|,
literal|"."
argument_list|)
operator|!=
literal|0
operator|&&
name|strcmp
argument_list|(
name|dp
operator|->
name|d_name
argument_list|,
literal|".."
argument_list|)
operator|!=
literal|0
operator|&&
name|strcmp
argument_list|(
name|dp
operator|->
name|d_name
argument_list|,
name|CVSADM
argument_list|)
operator|!=
literal|0
condition|)
block|{
operator|(
name|void
operator|)
name|closedir
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
block|}
operator|(
name|void
operator|)
name|closedir
argument_list|(
name|dirp
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * scratch the Entries file entry associated with a file  */
end_comment

begin_function
specifier|static
name|int
name|scratch_file
parameter_list|(
name|file
parameter_list|,
name|repository
parameter_list|,
name|entries
parameter_list|,
name|update_dir
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|;
name|char
modifier|*
name|repository
decl_stmt|;
name|List
modifier|*
name|entries
decl_stmt|;
name|char
modifier|*
name|update_dir
decl_stmt|;
block|{
name|history_write
argument_list|(
literal|'W'
argument_list|,
name|update_dir
argument_list|,
literal|""
argument_list|,
name|file
argument_list|,
name|repository
argument_list|)
expr_stmt|;
name|Scratch_Entry
argument_list|(
name|entries
argument_list|,
name|file
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|unlink_file
argument_list|(
name|file
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * check out a file - essentially returns the result of the fork on "co".  */
end_comment

begin_function
specifier|static
name|int
name|checkout_file
parameter_list|(
name|file
parameter_list|,
name|repository
parameter_list|,
name|entries
parameter_list|,
name|srcfiles
parameter_list|,
name|vers_ts
parameter_list|,
name|update_dir
parameter_list|)
name|char
modifier|*
name|file
decl_stmt|;
name|char
modifier|*
name|repository
decl_stmt|;
name|List
modifier|*
name|entries
decl_stmt|;
name|List
modifier|*
name|srcfiles
decl_stmt|;
name|Vers_TS
modifier|*
name|vers_ts
decl_stmt|;
name|char
modifier|*
name|update_dir
decl_stmt|;
block|{
name|char
name|backup
index|[
name|PATH_MAX
index|]
decl_stmt|;
name|int
name|set_time
decl_stmt|,
name|retval
init|=
literal|0
decl_stmt|;
name|int
name|retcode
init|=
literal|0
decl_stmt|;
ifdef|#
directive|ifdef
name|DEATH_SUPPORT
name|int
name|file_is_dead
decl_stmt|;
endif|#
directive|endif
comment|/* don't screw with backup files if we're going to stdout */
if|if
condition|(
operator|!
name|pipeout
condition|)
block|{
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|backup
argument_list|,
literal|"%s/%s%s"
argument_list|,
name|CVSADM
argument_list|,
name|CVSPREFIX
argument_list|,
name|file
argument_list|)
expr_stmt|;
if|if
condition|(
name|isfile
argument_list|(
name|file
argument_list|)
condition|)
name|rename_file
argument_list|(
name|file
argument_list|,
name|backup
argument_list|)
expr_stmt|;
else|else
operator|(
name|void
operator|)
name|unlink_file
argument_list|(
name|backup
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DEATH_SUPPORT
name|file_is_dead
operator|=
name|RCS_isdead
argument_list|(
name|vers_ts
operator|->
name|srcfile
argument_list|,
name|vers_ts
operator|->
name|vn_rcs
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|file_is_dead
condition|)
block|{
endif|#
directive|endif
name|run_setup
argument_list|(
literal|"%s%s -q -r%s %s"
argument_list|,
name|Rcsbin
argument_list|,
name|RCS_CO
argument_list|,
name|vers_ts
operator|->
name|vn_tag
argument_list|,
name|vers_ts
operator|->
name|options
argument_list|)
expr_stmt|;
comment|/*      * if we are checking out to stdout, print a nice message to stderr, and      * add the -p flag to the command      */
if|if
condition|(
name|pipeout
condition|)
block|{
name|run_arg
argument_list|(
literal|"-p"
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|quiet
condition|)
block|{
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"===================================================================\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|update_dir
index|[
literal|0
index|]
condition|)
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Checking out %s/%s\n"
argument_list|,
name|update_dir
argument_list|,
name|file
argument_list|)
expr_stmt|;
else|else
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Checking out %s\n"
argument_list|,
name|file
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"RCS:  %s\n"
argument_list|,
name|vers_ts
operator|->
name|srcfile
operator|->
name|path
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"VERS: %s\n"
argument_list|,
name|vers_ts
operator|->
name|vn_rcs
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"***************\n"
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* tack on the rcs and maybe the user file */
name|run_arg
argument_list|(
name|vers_ts
operator|->
name|srcfile
operator|->
name|path
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|pipeout
condition|)
name|run_arg
argument_list|(
name|file
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEATH_SUPPORT
block|}
if|if
condition|(
name|file_is_dead
operator|||
operator|(
name|retcode
operator|=
name|run_exec
argument_list|(
argument|RUN_TTY
argument_list|,
argument|RUN_TTY
argument_list|,
argument|RUN_TTY
argument_list|,
else|#
directive|else
argument|if ((retcode = run_exec (RUN_TTY, RUN_TTY, RUN_TTY,
endif|#
directive|endif
argument|(pipeout ? (RUN_NORMAL|RUN_REALLY) : RUN_NORMAL))) ==
literal|0
argument|)     { 	if (!pipeout) 	{ 	    Vers_TS *xvers_ts;
ifdef|#
directive|ifdef
name|DEATH_SUPPORT
argument|int resurrecting;  	    resurrecting =
literal|0
argument|;  	    if (file_is_dead&& joining()) 	    {
comment|/* when joining, we need to get dead files checked 		   out.  Try harder.  */
argument|run_setup (
literal|"%s%s -q -r%s %s"
argument|, Rcsbin, RCS_CO, vers_ts->vn_rcs, 			   vers_ts->options); 		 		run_arg (
literal|"-f"
argument|); 		run_arg (vers_ts->srcfile->path); 		run_arg (file); 		if ((retcode = run_exec (RUN_TTY, RUN_TTY, RUN_TTY, RUN_NORMAL)) !=
literal|0
argument|) 		{ 		    error (retcode == -
literal|1
argument|?
literal|1
argument|:
literal|0
argument|, retcode == -
literal|1
argument|? errno :
literal|0
argument|,
literal|"could not check out %s"
argument|, file); 		    (void) unlink_file (backup); 		    return (retcode); 		} 		file_is_dead =
literal|0
argument|; 		resurrecting =
literal|1
argument|; 	    }  	    if (cvswrite == TRUE&& !file_is_dead) 		xchmod (file,
literal|1
argument|);
else|#
directive|else
comment|/* No DEATH_SUPPORT */
argument|if (cvswrite == TRUE) 		xchmod (file,
literal|1
argument|);
endif|#
directive|endif
comment|/* No DEATH_SUPPORT */
comment|/* set the time from the RCS file iff it was unknown before */
argument|if (vers_ts->vn_user == NULL || 		strncmp (vers_ts->ts_rcs,
literal|"Initial"
argument|,
literal|7
argument|) ==
literal|0
argument|) 	    { 		set_time =
literal|1
argument|; 	    } 	    else 		set_time =
literal|0
argument|;  	    wrap_fromcvs_process_file (file);  	    xvers_ts = Version_TS (repository, options, tag, date, file, 			      force_tag_match, set_time, entries, srcfiles); 	    if (strcmp (xvers_ts->options,
literal|"-V4"
argument|) ==
literal|0
argument|) 		xvers_ts->options[
literal|0
argument|] =
literal|'\0'
argument|;
comment|/* If no keyword expansion was specified on command line, 	       use whatever was in the file.  This is how we tell the client 	       whether a file is binary.  */
argument|if (xvers_ts->options[
literal|0
argument|] ==
literal|'\0'
argument|) 	    { 		if (vers_ts->srcfile->expand != NULL) 		{ 		    free (xvers_ts->options); 		    xvers_ts->options = 			xmalloc (strlen (vers_ts->srcfile->expand) +
literal|3
argument|); 		    strcpy (xvers_ts->options,
literal|"-k"
argument|); 		    strcat (xvers_ts->options, vers_ts->srcfile->expand); 		} 	    }  	    (void) time (&last_register_time);
ifdef|#
directive|ifdef
name|DEATH_SUPPORT
argument|if (file_is_dead) 	    { 		if (xvers_ts->vn_user != NULL) 		{ 		    if (update_dir[
literal|0
argument|] ==
literal|'\0'
argument|) 			error (
literal|0
argument|,
literal|0
argument|,
literal|"warning: %s is not (any longer) pertinent"
argument|, 			       file); 		    else 			error (
literal|0
argument|,
literal|0
argument|,
literal|"warning: %s/%s is not (any longer) pertinent"
argument|, 			       update_dir, file); 		} 		Scratch_Entry (entries, file); 		if (unlink_file (file)<
literal|0
argument|&& ! existence_error (errno)) 		{ 		    if (update_dir[
literal|0
argument|] ==
literal|'\0'
argument|) 			error (
literal|0
argument|, errno,
literal|"cannot remove %s"
argument|, file); 		    else 			error (
literal|0
argument|, errno,
literal|"cannot remove %s/%s"
argument|, update_dir, 			       file); 		} 	    } 	    else 	      Register (entries, file, 			resurrecting ?
literal|"0"
argument|: xvers_ts->vn_rcs, 			xvers_ts->ts_user, xvers_ts->options, 			xvers_ts->tag, xvers_ts->date, 			(char *)
literal|0
argument|);
comment|/* Clear conflict flag on fresh checkout */
else|#
directive|else
comment|/* No DEATH_SUPPORT */
argument|Register (entries, file, xvers_ts->vn_rcs, xvers_ts->ts_user, 		      xvers_ts->options, xvers_ts->tag, xvers_ts->date, 		      (char *)
literal|0
argument|);
comment|/* Clear conflict flag on fresh checkout */
endif|#
directive|endif
comment|/* No DEATH_SUPPORT */
comment|/* fix up the vers structure, in case it is used by join */
argument|if (join_rev1) 	    { 		if (vers_ts->vn_user != NULL) 		    free (vers_ts->vn_user); 		if (vers_ts->vn_rcs != NULL) 		    free (vers_ts->vn_rcs); 		vers_ts->vn_user = xstrdup (xvers_ts->vn_rcs); 		vers_ts->vn_rcs = xstrdup (xvers_ts->vn_rcs); 	    }
comment|/* If this is really Update and not Checkout, recode history */
argument|if (strcmp (command_name,
literal|"update"
argument|) ==
literal|0
argument|) 		history_write (
literal|'U'
argument|, update_dir, xvers_ts->vn_rcs, file, 			       repository);  	    freevers_ts (&xvers_ts);
ifdef|#
directive|ifdef
name|DEATH_SUPPORT
argument|if (!really_quiet&& !file_is_dead)
else|#
directive|else
argument|if (!really_quiet)
endif|#
directive|endif
argument|{ 		if (update_dir[
literal|0
argument|]) 		    (void) printf (
literal|"U %s/%s\n"
argument|, update_dir, file); 		else 		    (void) printf (
literal|"U %s\n"
argument|, file); 	    } 	}     }     else     { 	int old_errno = errno;
comment|/* save errno value over the rename */
argument|if (!pipeout&& isfile (backup)) 	    rename_file (backup, file);  	error (retcode == -
literal|1
argument|?
literal|1
argument|:
literal|0
argument|, retcode == -
literal|1
argument|? old_errno :
literal|0
argument|,
literal|"could not check out %s"
argument|, file);  	retval = retcode;     }      if (!pipeout) 	(void) unlink_file (backup);      return (retval); }
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
comment|/* Patch a file.  Runs rcsdiff.  This is only done when running as the  * server.  The hope is that the diff will be smaller than the file  * itself.  */
argument|static int patch_file (file, repository, entries, srcfiles, vers_ts, update_dir, 	    docheckout, file_info, checksum)     char *file;     char *repository;     List *entries;     List *srcfiles;     Vers_TS *vers_ts;     char *update_dir;     int *docheckout;     struct stat *file_info;     unsigned char *checksum; {     char backup[PATH_MAX];     char file1[PATH_MAX];     char file2[PATH_MAX];     int retval =
literal|0
argument|;     int retcode =
literal|0
argument|;     int fail;     FILE *e;      *docheckout =
literal|0
argument|;      if (pipeout || joining ())     { 	*docheckout =
literal|1
argument|; 	return
literal|0
argument|;     }      (void) sprintf (backup,
literal|"%s/%s%s"
argument|, CVSADM, CVSPREFIX, file);     if (isfile (file))         rename_file (file, backup);     else         (void) unlink_file (backup);          (void) sprintf (file1,
literal|"%s/%s%s-1"
argument|, CVSADM, CVSPREFIX, file);     (void) sprintf (file2,
literal|"%s/%s%s-2"
argument|, CVSADM, CVSPREFIX, file);      fail =
literal|0
argument|;
comment|/* We need to check out both revisions first, to see if either one        has a trailing newline.  Because of this, we don't use rcsdiff,        but just use diff.  */
argument|run_setup (
literal|"%s%s -q -p -r%s %s %s"
argument|, Rcsbin, RCS_CO, vers_ts->vn_user, 	       vers_ts->options, vers_ts->srcfile->path);     if (run_exec (RUN_TTY, file1, RUN_TTY, RUN_NORMAL) !=
literal|0
argument|)         fail =
literal|1
argument|;     else     {         e = fopen (file1,
literal|"r"
argument|); 	if (e == NULL) 	    fail =
literal|1
argument|; 	else 	{ 	    if (fseek (e, (long) -
literal|1
argument|, SEEK_END) ==
literal|0
argument|&& getc (e) !=
literal|'\n'
argument|) 	    { 	        fail =
literal|1
argument|; 	    } 	    fclose (e); 	}     }      if (! fail)     {
comment|/* Check it out into file, and then move to file2, so that we            can get the right modes into *FILE_INFO.  We can't check it            out directly into file2 because co doesn't understand how            to do that.  */
argument|run_setup (
literal|"%s%s -q -r%s %s %s %s"
argument|, Rcsbin, RCS_CO, vers_ts->vn_rcs, 		   vers_ts->options, vers_ts->srcfile->path, file); 	if (run_exec (RUN_TTY, RUN_TTY, RUN_TTY, RUN_NORMAL) !=
literal|0
argument|) 	    fail =
literal|1
argument|; 	else 	{ 	    if (!isreadable (file)) 	    {
comment|/* File is dead.  */
argument|fail =
literal|1
argument|; 	    } 	    else 	    { 	        rename_file (file, file2); 		if (cvswrite == TRUE) 		    xchmod (file2,
literal|1
argument|); 		e = fopen (file2,
literal|"r"
argument|); 		if (e == NULL) 		    fail =
literal|1
argument|; 		else 		{ 		    struct MD5Context context; 		    int nl; 		    unsigned char buf[
literal|8192
argument|]; 		    unsigned len;  		    nl =
literal|0
argument|;
comment|/* Compute the MD5 checksum and make sure there is                        a trailing newline.  */
argument|MD5Init (&context); 		    while ((len = fread (buf,
literal|1
argument|, sizeof buf, e)) !=
literal|0
argument|) 		    { 			nl = buf[len -
literal|1
argument|] ==
literal|'\n'
argument|; 		        MD5Update (&context, buf, len); 		    } 		    MD5Final (checksum,&context);  		    if (ferror (e) || ! nl) 		    { 		        fail =
literal|1
argument|; 		    }  		    fclose (e); 		} 	    } 	}     }	        if (! fail)     {
comment|/* FIXME: This whole thing with diff/patch is rather more 	   convoluted than necessary (lots of forks and execs, need to 	   worry about versions of diff and patch, etc.).  Also, we 	   send context lines which aren't needed (in the rare case in 	   which the diff doesn't apply, the checksum would catches it). 	   Solution perhaps is to librarify the RCS routines which apply 	   deltas or something equivalent.  */
comment|/* This is -c, not -u, because we have no way of knowing which 	   DIFF is in use.  */
argument|run_setup (
literal|"%s -c %s %s"
argument|, DIFF, file1, file2);
comment|/* A retcode of 0 means no differences.  1 means some differences.  */
argument|if ((retcode = run_exec (RUN_TTY, file, RUN_TTY, RUN_NORMAL)) !=
literal|0
argument|&& retcode !=
literal|1
argument|) 	{ 	    fail =
literal|1
argument|; 	} 	else 	{
define|#
directive|define
name|BINARY
value|"Binary"
argument|char buf[sizeof BINARY]; 	    unsigned int c;
comment|/* Check the diff output to make sure patch will be handle it.  */
argument|e = fopen (file,
literal|"r"
argument|); 	    if (e == NULL) 		error (
literal|1
argument|, errno,
literal|"could not open diff output file %s"
argument|, file); 	    c = fread (buf,
literal|1
argument|, sizeof BINARY -
literal|1
argument|, e); 	    buf[c] =
literal|'\0'
argument|; 	    if (strcmp (buf, BINARY) ==
literal|0
argument|) 	    {
comment|/* These are binary files.  We could use diff -a, but 		   patch can't handle that.  */
argument|fail =
literal|1
argument|; 	    } 	    fclose (e); 	}     }      if (! fail)     {         Vers_TS *xvers_ts;
comment|/* This stuff is just copied blindly from checkout_file.  I 	   don't really know what it does.  */
argument|xvers_ts = Version_TS (repository, options, tag, date, file, 			       force_tag_match,
literal|0
argument|, entries, srcfiles); 	if (strcmp (xvers_ts->options,
literal|"-V4"
argument|) ==
literal|0
argument|) 	    xvers_ts->options[
literal|0
argument|] =
literal|'\0'
argument|;  	Register (entries, file, xvers_ts->vn_rcs, 		  xvers_ts->ts_user, xvers_ts->options, 		  xvers_ts->tag, xvers_ts->date, NULL);  	if (stat (file2, file_info)<
literal|0
argument|) 	    error (
literal|1
argument|, errno,
literal|"could not stat %s"
argument|, file2);
comment|/* If this is really Update and not Checkout, recode history */
argument|if (strcmp (command_name,
literal|"update"
argument|) ==
literal|0
argument|) 	    history_write (
literal|'P'
argument|, update_dir, xvers_ts->vn_rcs, file, 			   repository);  	freevers_ts (&xvers_ts);  	if (!really_quiet) 	{ 	    if (update_dir[
literal|0
argument|]) 	      (void) printf (
literal|"P %s/%s\n"
argument|, update_dir, file); 	    else 	      (void) printf (
literal|"P %s\n"
argument|, file); 	}     }     else     { 	int old_errno = errno;
comment|/* save errno value over the rename */
argument|if (isfile (backup)) 	    rename_file (backup, file);  	if (retcode !=
literal|0
argument|&& retcode !=
literal|1
argument|) 	    error (retcode == -
literal|1
argument|?
literal|1
argument|:
literal|0
argument|, retcode == -
literal|1
argument|? old_errno :
literal|0
argument|,
literal|"could not diff %s"
argument|, file);  	*docheckout =
literal|1
argument|; 	retval = retcode;     }      (void) unlink_file (backup);     (void) unlink_file (file1);     (void) unlink_file (file2);      return (retval); }
endif|#
directive|endif
comment|/*  * Several of the types we process only print a bit of information consisting  * of a single letter and the name.  */
argument|static int write_letter (file, letter, update_dir)     char *file;     int letter;     char *update_dir; {     if (!really_quiet)     { 	if (update_dir[
literal|0
argument|]) 	    (void) printf (
literal|"%c %s/%s\n"
argument|, letter, update_dir, file); 	else 	    (void) printf (
literal|"%c %s\n"
argument|, letter, file);     }     return (
literal|0
argument|); }
comment|/*  * Do all the magic associated with a file which needs to be merged  */
argument|static int merge_file (file, repository, entries, vers, update_dir)     char *file;     char *repository;     List *entries;     Vers_TS *vers;     char *update_dir; {     char user[PATH_MAX];     char backup[PATH_MAX];     int status;     int retcode =
literal|0
argument|;
comment|/*      * The users currently modified file is moved to a backup file name      * ".#filename.version", so that it will stay around for a few days      * before being automatically removed by some cron daemon.  The "version"      * is the version of the file that the user was most up-to-date with      * before the merge.      */
argument|(void) sprintf (backup,
literal|"%s%s.%s"
argument|, BAKPREFIX, file, vers->vn_user);     if (update_dir[
literal|0
argument|]) 	(void) sprintf (user,
literal|"%s/%s"
argument|, update_dir, file);     else 	(void) strcpy (user, file);      (void) unlink_file (backup);     copy_file (file, backup);     xchmod (file,
literal|1
argument|);      status = RCS_merge(vers->srcfile->path,  		       vers->options, vers->vn_user, vers->vn_rcs);     if (status !=
literal|0
argument|&& status !=
literal|1
argument|)     { 	error (
literal|0
argument|, status == -
literal|1
argument|? errno :
literal|0
argument|,
literal|"could not merge revision %s of %s"
argument|, vers->vn_user, user); 	error (status == -
literal|1
argument|?
literal|1
argument|:
literal|0
argument|,
literal|0
argument|,
literal|"restoring %s from backup file %s"
argument|, 	       user, backup); 	rename_file (backup, file); 	return (
literal|1
argument|);     }      if (strcmp (vers->options,
literal|"-V4"
argument|) ==
literal|0
argument|) 	vers->options[
literal|0
argument|] =
literal|'\0'
argument|;     (void) time (&last_register_time);     { 	char *cp =
literal|0
argument|;  	if (status) 	    cp = time_stamp (file); 	Register (entries, file, vers->vn_rcs, vers->ts_rcs, vers->options, 		  vers->tag, vers->date, cp); 	if (cp) 	    free (cp);     }
comment|/* fix up the vers structure, in case it is used by join */
argument|if (join_rev1)     { 	if (vers->vn_user != NULL) 	    free (vers->vn_user); 	vers->vn_user = xstrdup (vers->vn_rcs);     }
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
comment|/* Send the new contents of the file before the message.  If we        wanted to be totally correct, we would have the client write        the message only after the file has safely been written.  */
argument|if (server_active)     {         server_copy_file (file, update_dir, repository, backup); 	server_updated (file, update_dir, repository, SERVER_MERGED, 			(struct stat *) NULL, (unsigned char *) NULL);     }
endif|#
directive|endif
argument|if (!noexec&& !xcmp (backup, file))     { 	printf (
literal|"%s already contains the differences between %s and %s\n"
argument|, 		user, vers->vn_user, vers->vn_rcs); 	history_write (
literal|'G'
argument|, update_dir, vers->vn_rcs, file, repository); 	return (
literal|0
argument|);     }      if (status ==
literal|1
argument|)     { 	if (!noexec) 	    error (
literal|0
argument|,
literal|0
argument|,
literal|"conflicts found in %s"
argument|, user);  	if (!really_quiet) 	    (void) printf (
literal|"C %s\n"
argument|, user);  	history_write (
literal|'C'
argument|, update_dir, vers->vn_rcs, file, repository);      }     else if (retcode == -
literal|1
argument|)     { 	error (
literal|1
argument|, errno,
literal|"fork failed while examining update of %s"
argument|, user);     }     else     { 	if (!really_quiet) 	    (void) printf (
literal|"M %s\n"
argument|, user); 	history_write (
literal|'G'
argument|, update_dir, vers->vn_rcs, file, repository);     }     return (
literal|0
argument|); }
comment|/*  * Do all the magic associated with a file which needs to be joined  * (-j option)  */
argument|static void
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
argument|join_file (file, srcfiles, vers, update_dir, entries, repository)     char *repository;
else|#
directive|else
argument|join_file (file, srcfiles, vers, update_dir, entries)
endif|#
directive|endif
argument|char *file;     List *srcfiles;     Vers_TS *vers;     char *update_dir;     List *entries; {     char user[PATH_MAX];     char backup[PATH_MAX];     char *options;     int status;      char *rev1;     char *rev2;     char *jrev1;     char *jrev2;     char *jdate1;     char *jdate2;      jrev1 = join_rev1;     jrev2 = join_rev2;     jdate1 = date_rev1;     jdate2 = date_rev2;      if (wrap_merge_is_copy (file))     {
comment|/* FIXME: Should be including update_dir in message.  */
argument|error (
literal|0
argument|,
literal|0
argument|,
literal|"Cannot merge %s because it is a merge-by-copy file."
argument|, file); 	return;     }
comment|/* determine if we need to do anything at all */
argument|if (vers->srcfile == NULL || 	vers->srcfile->path == NULL)     { 	return;     }
comment|/* in all cases, use two revs. */
comment|/* if only one rev is specified, it becomes the second rev */
argument|if (jrev2 == NULL)     { 	jrev2 = jrev1; 	jrev1 = NULL; 	jdate2 = jdate1; 	jdate1 = NULL;     }
comment|/* The file in the working directory doesn't exist in CVS/Entries.        FIXME: Shouldn't this case result in additional processing (if        the file was added going from rev1 to rev2, then do the equivalent        of a "cvs add")?  (yes; easier said than done.. :-) */
argument|if (vers->vn_user == NULL)     {
comment|/* No merge possible YET. */
argument|if (jdate2 != NULL) 	    error (
literal|0
argument|,
literal|0
argument|,
literal|"file %s is present in revision %s as of %s"
argument|, 		   file, jrev2, jdate2); 	else 	    error (
literal|0
argument|,
literal|0
argument|,
literal|"file %s is present in revision %s"
argument|, 		   file, jrev2); 	return;     }
comment|/* Fix for bug CVS/193:      * Used to dump core if the file had been removed on the current branch.      */
argument|if (strcmp(vers->vn_user,
literal|"0"
argument|) ==
literal|0
argument|)     {         error(
literal|0
argument|,
literal|0
argument|,
literal|"file %s has been deleted"
argument|,               file);         return;     }
comment|/* convert the second rev spec, walking branches and dates. */
argument|rev2 = RCS_getversion (vers->srcfile, jrev2, jdate2,
literal|1
argument|,
literal|0
argument|);     if (rev2 == NULL)     { 	if (!quiet) 	{ 	    if (jdate2 != NULL) 		error (
literal|0
argument|,
literal|0
argument|,
literal|"cannot find revision %s as of %s in file %s"
argument|, 		       jrev2, jdate2, file); 	    else 		error (
literal|0
argument|,
literal|0
argument|,
literal|"cannot find revision %s in file %s"
argument|, 		       jrev2, file); 	} 	return;     }
comment|/* skip joining identical revs */
argument|if (strcmp (rev2, vers->vn_user) ==
literal|0
argument|)     {
comment|/* No merge necessary.  */
argument|free (rev2); 	return;     }      if (jrev1 == NULL)     { 	char *tst;
comment|/* if the first rev is missing, then it is implied to be the 	   greatest common ancestor of both the join rev, and the 	   checked out rev. */
comment|/* FIXME: What is this check for '!' about?  If it is legal to 	   have '!' in the first character of vn_user, it isn't 	   documented at struct vers_ts in cvs.h.  */
argument|tst = vers->vn_user; 	if (*tst ==
literal|'!'
argument|) 	{
comment|/* file was dead.  merge anyway and pretend it's been 	       added. */
argument|++tst; 	    Register (entries, file,
literal|"0"
argument|, vers->ts_user, vers->options, 		      vers->tag, (char *)
literal|0
argument|, (char *)
literal|0
argument|); 	} 	rev1 = gca (tst, rev2); 	if (rev1 == NULL) 	{
comment|/* this should not be possible */
argument|error (
literal|0
argument|,
literal|0
argument|,
literal|"bad gca"
argument|); 	    abort(); 	}  	tst = RCS_gettag (vers->srcfile, rev2,
literal|1
argument|,
literal|0
argument|); 	if (tst == NULL) 	{
comment|/* this should not be possible. */
argument|error (
literal|0
argument|,
literal|0
argument|,
literal|"cannot find gca"
argument|); 	    abort(); 	}  	free (tst);
comment|/* these two cases are noops */
argument|if (strcmp (rev1, rev2) ==
literal|0
argument|) 	{ 	    free (rev1); 	    free (rev2); 	    return; 	}     }     else     {
comment|/* otherwise, convert the first rev spec, walking branches and 	   dates.  */
argument|rev1 = RCS_getversion (vers->srcfile, jrev1, jdate1,
literal|1
argument|,
literal|0
argument|); 	if (rev1 == NULL) 	{ 	  if (!quiet) { 	    if (jdate1 != NULL) 		error (
literal|0
argument|,
literal|0
argument|,
literal|"cannot find revision %s as of %s in file %s"
argument|, 		       jrev1, jdate1, file); 	    else 		error (
literal|0
argument|,
literal|0
argument|,
literal|"cannot find revision %s in file %s"
argument|, 		       jrev1, file); 	  } 	  return; 	}     }
comment|/* do the join */
if|#
directive|if
literal|0
argument|dome {
comment|/* special handling when two revisions are specified */
argument|if (join_rev1&& join_rev2) 	{ 	    rev = RCS_getversion (vers->srcfile, join_rev2, date_rev2, 1, 0); 	    if (rev == NULL) 	    { 		if (!quiet&& date_rev2 == NULL) 		    error (0, 0, 			   "cannot find revision %s in file %s", join_rev2, file); 		return; 	    } 	     	    baserev = RCS_getversion (vers->srcfile, join_rev1, date_rev1, 1, 0); 	    if (baserev == NULL) 	    { 		if (!quiet&& date_rev1 == NULL) 		    error (0, 0, 			   "cannot find revision %s in file %s", join_rev1, file); 		free (rev); 		return; 	    }
comment|/* 	     * nothing to do if: 	     *	second revision matches our BASE revision (vn_user)&& 	     *	both revisions are on the same branch 	     */
argument|if (strcmp (vers->vn_user, rev) == 0&& 		numdots (baserev) == numdots (rev)) 	    {
comment|/* might be the same branch.  take a real look */
argument|char *dot = strrchr (baserev, '.'); 		int len = (dot - baserev) + 1; 		 		if (strncmp (baserev, rev, len) == 0) 		    return; 	    } 	} 	else 	{ 	    rev = RCS_getversion (vers->srcfile, join_rev1, date_rev1, 1, 0); 	    if (rev == NULL) 		return; 	    if (strcmp (rev, vers->vn_user) == 0)
comment|/* no merge necessary */
argument|{ 		free (rev); 		return; 	    } 	     	    baserev = RCS_whatbranch (file, join_rev1, srcfiles); 	    if (baserev) 	    { 		char *cp;
comment|/* we get a branch -- turn it into a revision, or NULL if trunk */
argument|if ((cp = strrchr (baserev, '.')) == NULL) 		{ 		    free (baserev); 		    baserev = (char *) NULL; 		} 		else 		    *cp = '\0'; 	    } 	} 	if (baserev&& strcmp (baserev, rev) == 0) 	{
comment|/* they match -> nothing to do */
argument|free (rev); 	    free (baserev); 	    return; 	}     }
endif|#
directive|endif
comment|/* OK, so we have two revisions; continue on */
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
argument|if (server_active&& !isreadable (file))     { 	int retcode;
comment|/* The file is up to date.  Need to check out the current contents.  */
argument|run_setup (
literal|"%s%s -q -r%s"
argument|, Rcsbin, RCS_CO, vers->vn_user); 	run_arg (vers->srcfile->path); 	retcode = run_exec (RUN_TTY, RUN_TTY, RUN_TTY, RUN_NORMAL); 	if (retcode !=
literal|0
argument|) 	    error (
literal|1
argument|, retcode == -
literal|1
argument|? errno :
literal|0
argument|,
literal|"failed to check out %s file"
argument|, file);     }
endif|#
directive|endif
comment|/*      * The users currently modified file is moved to a backup file name      * ".#filename.version", so that it will stay around for a few days      * before being automatically removed by some cron daemon.  The "version"      * is the version of the file that the user was most up-to-date with      * before the merge.      */
argument|(void) sprintf (backup,
literal|"%s%s.%s"
argument|, BAKPREFIX, file, vers->vn_user);     if (update_dir[
literal|0
argument|]) 	(void) sprintf (user,
literal|"%s/%s"
argument|, update_dir, file);     else 	(void) strcpy (user, file);      (void) unlink_file (backup);     copy_file (file, backup);     xchmod (file,
literal|1
argument|);      options = vers->options;
ifdef|#
directive|ifdef
name|HAVE_RCS5
if|#
directive|if
literal|0
argument|if (*options == '\0') 	options = "-kk";
comment|/* to ignore keyword expansions */
endif|#
directive|endif
endif|#
directive|endif
argument|status = RCS_merge (vers->srcfile->path, options, rev1, rev2);     if (status !=
literal|0
argument|&& status !=
literal|1
argument|)     { 	error (
literal|0
argument|, status == -
literal|1
argument|? errno :
literal|0
argument|,
literal|"could not merge revision %s of %s"
argument|, rev2, user); 	error (status == -
literal|1
argument|?
literal|1
argument|:
literal|0
argument|,
literal|0
argument|,
literal|"restoring %s from backup file %s"
argument|, 	       user, backup); 	rename_file (backup, file);     }     free (rev1);     free (rev2);
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
comment|/*      * If we're in server mode, then we need to re-register the file      * even if there were no conflicts (status == 0).      * This tells server_updated() to send the modified file back to      * the client.      */
argument|if (status ==
literal|1
argument||| (status ==
literal|0
argument|&& server_active))
else|#
directive|else
argument|if (status ==
literal|1
argument|)
endif|#
directive|endif
argument|{ 	char *cp =
literal|0
argument|;  	if (status) 	    cp = time_stamp (file); 	Register (entries, file, vers->vn_rcs, vers->ts_rcs, vers->options, 		  vers->tag, vers->date, cp); 	if (cp) 	    free(cp);     }
ifdef|#
directive|ifdef
name|SERVER_SUPPORT
argument|if (server_active)     { 	server_copy_file (file, update_dir, repository, backup); 	server_updated (file, update_dir, repository, SERVER_MERGED, 			(struct stat *) NULL, (unsigned char *) NULL);     }
endif|#
directive|endif
argument|}
comment|/*  * Process the current directory, looking for files not in ILIST and not on  * the global ignore list for this directory.  */
argument|static void ignore_files (ilist, update_dir)     List *ilist;     char *update_dir; {     DIR *dirp;     struct dirent *dp;     struct stat sb;     char *file;     char *xdir;
comment|/* we get called with update_dir set to "." sometimes... strip it */
argument|if (strcmp (update_dir,
literal|"."
argument|) ==
literal|0
argument|) 	xdir =
literal|""
argument|;     else 	xdir = update_dir;      dirp = opendir (
literal|"."
argument|);     if (dirp == NULL) 	return;      ign_add_file (CVSDOTIGNORE,
literal|1
argument|);     wrap_add_file (CVSDOTWRAPPER,
literal|1
argument|);      while ((dp = readdir (dirp)) != NULL)     { 	file = dp->d_name; 	if (strcmp (file,
literal|"."
argument|) ==
literal|0
argument||| strcmp (file,
literal|".."
argument|) ==
literal|0
argument|) 	    continue; 	if (findnode (ilist, file) != NULL) 	    continue;  	if (
ifdef|#
directive|ifdef
name|DT_DIR
argument|dp->d_type != DT_UNKNOWN ||
endif|#
directive|endif
argument|lstat(file,&sb) != -
literal|1
argument|)  	{  	    if (
ifdef|#
directive|ifdef
name|DT_DIR
argument|dp->d_type == DT_DIR || dp->d_type == DT_UNKNOWN&&
endif|#
directive|endif
argument|S_ISDIR(sb.st_mode)) 	    { 		char temp[PATH_MAX];  		(void) sprintf (temp,
literal|"%s/%s"
argument|, file, CVSADM); 		if (isdir (temp)) 		    continue; 	    }
ifdef|#
directive|ifdef
name|S_ISLNK
argument|else if (
ifdef|#
directive|ifdef
name|DT_DIR
argument|dp->d_type == DT_LNK || dp->d_type == DT_UNKNOWN&&
endif|#
directive|endif
argument|S_ISLNK(sb.st_mode)) 	    { 		continue; 	    }
endif|#
directive|endif
argument|} 	 	if (ign_name (file)) 	    continue; 	(void) write_letter (file,
literal|'?'
argument|, xdir);     }     (void) closedir (dirp); }  int joining () {     return (join_rev1 != NULL); }
end_function

end_unit

