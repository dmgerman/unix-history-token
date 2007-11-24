begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * FreeBSD install - a package for the installation and maintainance  * of non-core utilities.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * Jeremy D. Lea.  * 11 May 2002  *  * This is the version module. Based on pkg_version.pl by Bruce A. Mah.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INST_VERSION_H_INCLUDE
end_ifndef

begin_define
define|#
directive|define
name|_INST_VERSION_H_INCLUDE
end_define

begin_comment
comment|/* Where the ports lives by default */
end_comment

begin_define
define|#
directive|define
name|DEF_PORTS_DIR
value|"/usr/ports"
end_define

begin_comment
comment|/* just in case we change the environment variable name */
end_comment

begin_define
define|#
directive|define
name|PORTSDIR
value|"PORTSDIR"
end_define

begin_comment
comment|/* macro to get name of directory where we put logging information */
end_comment

begin_define
define|#
directive|define
name|PORTS_DIR
value|(getenv(PORTSDIR) ? getenv(PORTSDIR) : DEF_PORTS_DIR)
end_define

begin_struct
struct|struct
name|index_entry
block|{
name|SLIST_ENTRY
argument_list|(
argument|index_entry
argument_list|)
name|next
expr_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|origin
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|SLIST_HEAD
argument_list|(
name|index_head
argument_list|,
name|index_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|LimitChars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PreventChars
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|MatchName
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|LookUpOrigin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Boolean
name|RegexExtended
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Boolean
name|UseINDEXOnly
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Boolean
name|ShowOrigin
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|version_match
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INST_VERSION_H_INCLUDE */
end_comment

end_unit

