begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2000-2001 Sendmail, Inc. and its suppliers.  *	All rights reserved.  *  * By using this file, you agree to the terms and conditions set  * forth in the LICENSE file which can be found at the top level of  * the sendmail distribution.  *  *	$Id: debug.h,v 1.15 2001/03/08 03:23:07 ca Exp $  */
end_comment

begin_comment
comment|/* **  libsm debugging and tracing **  See libsm/debug.html for documentation. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SM_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|SM_DEBUG_H
end_define

begin_include
include|#
directive|include
file|<sm/gen.h>
end_include

begin_include
include|#
directive|include
file|<sm/io.h>
end_include

begin_comment
comment|/* **  abstractions for printing trace messages */
end_comment

begin_decl_stmt
specifier|extern
name|SM_FILE_T
modifier|*
name|sm_debug_file
name|__P
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
name|sm_debug_setfile
name|__P
argument_list|(
operator|(
name|SM_FILE_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|PRINTFLIKE
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|)
name|sm_dprintf
name|__P
argument_list|(
operator|(
name|char
operator|*
name|_fmt
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_dflush
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* **  abstractions for setting and testing debug activation levels */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|sm_debug_addsettings_x
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sm_debug_addsetting_x
name|__P
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SM_DEBUG_UNKNOWN
value|((SM_ATOMIC_UINT_T)(-1))
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|char
name|SmDebugMagic
index|[]
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|sm_debug
name|SM_DEBUG_T
typedef|;
end_typedef

begin_struct
struct|struct
name|sm_debug
block|{
specifier|const
name|char
modifier|*
name|sm_magic
decl_stmt|;
comment|/* points to SmDebugMagic */
comment|/* 	**  debug_level is the activation level of this debug 	**  object.  Level 0 means no debug activity. 	**  It is initialized to SM_DEBUG_UNKNOWN, which indicates 	**  that the true value is unknown.  If debug_level == 	**  SM_DEBUG_UNKNOWN, then the access functions will look up 	**  its true value in the internal table of debug settings. 	*/
name|SM_ATOMIC_UINT_T
name|debug_level
decl_stmt|;
comment|/* 	**  debug_name is the name used to reference this SM_DEBUG 	**  structure via the sendmail -d option. 	*/
name|char
modifier|*
name|debug_name
decl_stmt|;
comment|/* 	**  debug_desc is a literal character string of the form 	**  "@(#)$Debug:<name> -<short description> $" 	*/
name|char
modifier|*
name|debug_desc
decl_stmt|;
comment|/* 	**  We keep a linked list of initialized SM_DEBUG structures 	**  so that when sm_debug_addsetting is called, we can reset 	**  them all back to the uninitialized state. 	*/
name|SM_DEBUG_T
modifier|*
name|debug_next
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|SM_DEBUG_CHECK
end_ifndef

begin_define
define|#
directive|define
name|SM_DEBUG_CHECK
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_DEBUG_CHECK */
end_comment

begin_if
if|#
directive|if
name|SM_DEBUG_CHECK
end_if

begin_comment
comment|/* **  This macro is cleverly designed so that if the debug object is below **  the specified level, then the only overhead is a single comparison **  (except for the first time this macro is invoked). */
end_comment

begin_define
define|#
directive|define
name|sm_debug_active
parameter_list|(
name|debug
parameter_list|,
name|level
parameter_list|)
define|\
value|((debug)->debug_level>= (level)&& \ 	     ((debug)->debug_level != SM_DEBUG_UNKNOWN || \ 	      sm_debug_loadactive(debug, level)))
end_define

begin_define
define|#
directive|define
name|sm_debug_level
parameter_list|(
name|debug
parameter_list|)
define|\
value|((debug)->debug_level == SM_DEBUG_UNKNOWN \ 	     ? sm_debug_loadlevel(debug) : (debug)->debug_level)
end_define

begin_define
define|#
directive|define
name|sm_debug_unknown
parameter_list|(
name|debug
parameter_list|)
value|((debug)->debug_level == SM_DEBUG_UNKNOWN)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SM_DEBUG_CHECK */
end_comment

begin_define
define|#
directive|define
name|sm_debug_active
parameter_list|(
name|debug
parameter_list|,
name|level
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|sm_debug_level
parameter_list|(
name|debug
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|sm_debug_unknown
parameter_list|(
name|debug
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SM_DEBUG_CHECK */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|sm_debug_loadactive
name|__P
argument_list|(
operator|(
name|SM_DEBUG_T
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
name|sm_debug_loadlevel
name|__P
argument_list|(
operator|(
name|SM_DEBUG_T
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|SM_DEBUG_INITIALIZER
parameter_list|(
name|name
parameter_list|,
name|desc
parameter_list|)
value|{ \ 		SmDebugMagic, \ 		SM_DEBUG_UNKNOWN, \ 		name, \ 		desc, \ 		NULL}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! SM_DEBUG_H */
end_comment

end_unit

