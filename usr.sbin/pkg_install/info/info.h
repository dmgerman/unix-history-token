begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: info.h,v 1.4 1993/09/04 05:06:40 jkh Exp $ */
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

begin_define
define|#
directive|define
name|SHOW_COMMENT
value|0x1
end_define

begin_define
define|#
directive|define
name|SHOW_DESC
value|0x2
end_define

begin_define
define|#
directive|define
name|SHOW_PLIST
value|0x4
end_define

begin_define
define|#
directive|define
name|SHOW_INSTALL
value|0x8
end_define

begin_define
define|#
directive|define
name|SHOW_DEINSTALL
value|0x10
end_define

begin_define
define|#
directive|define
name|SHOW_REQUIRE
value|0x20
end_define

begin_define
define|#
directive|define
name|SHOW_PREFIX
value|0x40
end_define

begin_define
define|#
directive|define
name|SHOW_INDEX
value|0x80
end_define

begin_decl_stmt
specifier|extern
name|int
name|Flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|Boolean
name|AllInstalled
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
modifier|*
name|PlayPen
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|show_file
parameter_list|(
name|char
modifier|*
parameter_list|,
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
name|char
modifier|*
parameter_list|,
name|Package
modifier|*
parameter_list|,
name|plist_t
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

