begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * FreeBSD install - a package for the installation and maintainance  * of non-core utilities.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * Jordan K. Hubbard  * 18 July 1993  *  * Include and define various things wanted by the create command.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_INST_CREATE_H_INCLUDE
end_ifndef

begin_define
define|#
directive|define
name|_INST_CREATE_H_INCLUDE
end_define

begin_decl_stmt
specifier|extern
name|match_t
name|MatchType
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Prefix
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Comment
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Desc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Display
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Install
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PostInstall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|DeInstall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|PostDeInstall
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Contents
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Require
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|SrcDir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|BaseDir
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|ExcludeFrom
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Mtree
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Pkgdeps
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Conflicts
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|Origin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|InstalledPkg
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
name|int
name|Dereference
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|PlistOnly
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|Recursive
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|zipper
block|{
name|NONE
block|,
name|GZIP
block|,
name|BZIP
block|,
name|BZIP2
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|zipper
name|Zipper
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|add_cksum
parameter_list|(
name|Package
modifier|*
parameter_list|,
name|PackingList
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|check_list
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
name|void
name|copy_plist
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
comment|/* _INST_CREATE_H_INCLUDE */
end_comment

end_unit

