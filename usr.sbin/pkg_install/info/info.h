begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * FreeBSD install - a package for the installation and maintainance  * of non-core utilities.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * Jordan K. Hubbard  * 23 August 1993  *  * Include and define various things wanted by the info command.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INST_INFO_H_INCLUDE
end_ifndef

begin_define
define|#
directive|define
name|_INST_INFO_H_INCLUDE
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MAXINDEXSIZE
end_ifndef

begin_define
define|#
directive|define
name|MAXINDEXSIZE
value|59
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MAXNAMESIZE
end_ifndef

begin_define
define|#
directive|define
name|MAXNAMESIZE
value|20
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|SHOW_COMMENT
value|0x00001
end_define

begin_define
define|#
directive|define
name|SHOW_DESC
value|0x00002
end_define

begin_define
define|#
directive|define
name|SHOW_PLIST
value|0x00004
end_define

begin_define
define|#
directive|define
name|SHOW_INSTALL
value|0x00008
end_define

begin_define
define|#
directive|define
name|SHOW_DEINSTALL
value|0x00010
end_define

begin_define
define|#
directive|define
name|SHOW_REQUIRE
value|0x00020
end_define

begin_define
define|#
directive|define
name|SHOW_PREFIX
value|0x00040
end_define

begin_define
define|#
directive|define
name|SHOW_INDEX
value|0x00080
end_define

begin_define
define|#
directive|define
name|SHOW_FILES
value|0x00100
end_define

begin_define
define|#
directive|define
name|SHOW_DISPLAY
value|0x00200
end_define

begin_define
define|#
directive|define
name|SHOW_REQBY
value|0x00400
end_define

begin_define
define|#
directive|define
name|SHOW_MTREE
value|0x00800
end_define

begin_define
define|#
directive|define
name|SHOW_SIZE
value|0x01000
end_define

begin_define
define|#
directive|define
name|SHOW_ORIGIN
value|0x02000
end_define

begin_define
define|#
directive|define
name|SHOW_CKSUM
value|0x04000
end_define

begin_define
define|#
directive|define
name|SHOW_FMTREV
value|0x08000
end_define

begin_define
define|#
directive|define
name|SHOW_PTREV
value|0x10000
end_define

begin_define
define|#
directive|define
name|SHOW_DEPEND
value|0x20000
end_define

begin_define
define|#
directive|define
name|SHOW_PKGNAME
value|0x40000
end_define

begin_struct
struct|struct
name|which_entry
block|{
name|TAILQ_ENTRY
argument_list|(
argument|which_entry
argument_list|)
name|next
expr_stmt|;
name|char
name|file
index|[
name|PATH_MAX
index|]
decl_stmt|;
name|char
name|package
index|[
name|PATH_MAX
index|]
decl_stmt|;
name|Boolean
name|skip
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|which_head
argument_list|,
name|which_entry
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|int
name|Flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Boolean
name|QUIET
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Boolean
name|UseBlkSz
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Boolean
name|KeepPackage
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|InfoPrefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|PlayPen
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|CheckPkg
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
name|match_t
name|MatchType
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|which_head
modifier|*
name|whead
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|show_file
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_plist
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Package
modifier|*
parameter_list|,
name|plist_t
parameter_list|,
name|Boolean
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_files
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Package
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_index
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_size
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Package
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_cksum
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Package
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_origin
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Package
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|show_fmtrev
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|Package
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _INST_INFO_H_INCLUDE */
end_comment

end_unit

