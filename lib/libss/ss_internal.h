begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 1987, 1988 by MIT Student Information Processing Board  *  * For copyright information, see copyright.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ss_ss_internal_h
end_ifndef

begin_define
define|#
directive|define
name|_ss_ss_internal_h
value|__FILE__
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|PROTOTYPE
parameter_list|(
name|p
parameter_list|)
value|p
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|pointer
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|const
end_define

begin_define
define|#
directive|define
name|volatile
end_define

begin_define
define|#
directive|define
name|PROTOTYPE
parameter_list|(
name|p
parameter_list|)
value|()
end_define

begin_typedef
typedef|typedef
name|char
modifier|*
name|pointer
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not __STDC__ */
end_comment

begin_include
include|#
directive|include
file|"ss.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|LOCAL_ALLOC
parameter_list|(
name|x
parameter_list|)
value|__builtin_alloca(x)
end_define

begin_define
define|#
directive|define
name|LOCAL_FREE
parameter_list|(
name|x
parameter_list|)
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|vax
argument_list|)
end_if

begin_define
define|#
directive|define
name|LOCAL_ALLOC
parameter_list|(
name|x
parameter_list|)
value|alloca(x)
end_define

begin_define
define|#
directive|define
name|LOCAL_FREE
parameter_list|(
name|x
parameter_list|)
end_define

begin_decl_stmt
specifier|extern
name|pointer
name|alloca
name|PROTOTYPE
argument_list|(
operator|(
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__HIGHC__
argument_list|)
end_if

begin_comment
comment|/* Barf! */
end_comment

begin_function_decl
name|pragma
name|on
parameter_list|(
name|alloca
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|LOCAL_ALLOC
parameter_list|(
name|x
parameter_list|)
value|alloca(x)
end_define

begin_define
define|#
directive|define
name|LOCAL_FREE
parameter_list|(
name|x
parameter_list|)
end_define

begin_decl_stmt
specifier|extern
name|pointer
name|alloca
name|PROTOTYPE
argument_list|(
operator|(
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no alloca? */
end_comment

begin_define
define|#
directive|define
name|LOCAL_ALLOC
parameter_list|(
name|x
parameter_list|)
value|malloc(x)
end_define

begin_define
define|#
directive|define
name|LOCAL_FREE
parameter_list|(
name|x
parameter_list|)
value|free(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LOCAL_ALLOC stuff */
end_comment

begin_typedef
typedef|typedef
name|char
name|BOOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ss_abbrev_entry
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* abbrev name */
name|char
modifier|*
modifier|*
name|abbrev
decl_stmt|;
comment|/* new tokens to insert */
name|char
name|beginning_of_line
range|:
literal|1
decl_stmt|;
block|}
name|ss_abbrev_entry
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ss_abbrev_list
block|{
name|int
name|n_abbrevs
decl_stmt|;
name|ss_abbrev_entry
modifier|*
name|first_abbrev
decl_stmt|;
block|}
name|ss_abbrev_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/*    char *path; */
name|ss_abbrev_list
name|abbrevs
index|[
literal|127
index|]
decl_stmt|;
block|}
name|ss_abbrev_info
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_ss_data
block|{
comment|/* init values */
comment|/* this subsystem */
name|char
modifier|*
name|subsystem_name
decl_stmt|;
name|char
modifier|*
name|subsystem_version
decl_stmt|;
comment|/* current request info */
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
comment|/* arg list */
name|char
specifier|const
modifier|*
name|current_request
decl_stmt|;
comment|/* primary name */
comment|/* info directory for 'help' */
name|char
modifier|*
modifier|*
name|info_dirs
decl_stmt|;
comment|/* to be extracted by subroutines */
name|pointer
name|info_ptr
decl_stmt|;
comment|/* (void *) NULL */
comment|/* for ss_listen processing */
name|char
modifier|*
name|prompt
decl_stmt|;
name|ss_request_table
modifier|*
modifier|*
name|rqt_tables
decl_stmt|;
name|ss_abbrev_info
modifier|*
name|abbrev_info
decl_stmt|;
struct|struct
block|{
name|unsigned
name|char
name|escape_disabled
range|:
literal|1
decl_stmt|,
name|abbrevs_disabled
range|:
literal|1
decl_stmt|;
block|}
name|flags
struct|;
comment|/* to get out */
name|int
name|abort
decl_stmt|;
comment|/* exit subsystem */
name|int
name|exit_status
decl_stmt|;
block|}
name|ss_data
typedef|;
end_typedef

begin_define
define|#
directive|define
name|CURRENT_SS_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|ss_info
parameter_list|(
name|sci_idx
parameter_list|)
value|(_ss_table[sci_idx])
end_define

begin_define
define|#
directive|define
name|ss_current_request
parameter_list|(
name|sci_idx
parameter_list|,
name|code_ptr
parameter_list|)
define|\
value|(*code_ptr=0,ss_info(sci_idx)->current_request)
end_define

begin_function_decl
name|void
name|ss_unknown_function
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ss_delete_info_dir
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ss_execute_line
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|ss_parse
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|ss_abbrev_info
modifier|*
name|ss_abbrev_initialize
name|PROTOTYPE
argument_list|(
operator|(
name|char
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|ss_page_stdin
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|ss_data
modifier|*
modifier|*
name|_ss_table
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ss_et_msgs
index|[]
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|pointer
name|malloc
name|PROTOTYPE
argument_list|(
operator|(
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pointer
name|realloc
name|PROTOTYPE
argument_list|(
operator|(
name|pointer
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|pointer
name|calloc
name|PROTOTYPE
argument_list|(
operator|(
name|unsigned
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|exit
name|PROTOTYPE
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ss_internal_h */
end_comment

end_unit

