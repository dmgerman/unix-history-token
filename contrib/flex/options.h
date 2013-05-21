begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* flex - tool to generate fast lexical analyzers */
end_comment

begin_comment
comment|/*  Copyright (c) 1990 The Regents of the University of California. */
end_comment

begin_comment
comment|/*  All rights reserved. */
end_comment

begin_comment
comment|/*  This code is derived from software contributed to Berkeley by */
end_comment

begin_comment
comment|/*  Vern Paxson. */
end_comment

begin_comment
comment|/*  The United States Government has rights in this work pursuant */
end_comment

begin_comment
comment|/*  to contract no. DE-AC03-76SF00098 between the United States */
end_comment

begin_comment
comment|/*  Department of Energy and the University of California. */
end_comment

begin_comment
comment|/*  This file is part of flex. */
end_comment

begin_comment
comment|/*  Redistribution and use in source and binary forms, with or without */
end_comment

begin_comment
comment|/*  modification, are permitted provided that the following conditions */
end_comment

begin_comment
comment|/*  are met: */
end_comment

begin_comment
comment|/*  1. Redistributions of source code must retain the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer. */
end_comment

begin_comment
comment|/*  2. Redistributions in binary form must reproduce the above copyright */
end_comment

begin_comment
comment|/*     notice, this list of conditions and the following disclaimer in the */
end_comment

begin_comment
comment|/*     documentation and/or other materials provided with the distribution. */
end_comment

begin_comment
comment|/*  Neither the name of the University nor the names of its contributors */
end_comment

begin_comment
comment|/*  may be used to endorse or promote products derived from this software */
end_comment

begin_comment
comment|/*  without specific prior written permission. */
end_comment

begin_comment
comment|/*  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR */
end_comment

begin_comment
comment|/*  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED */
end_comment

begin_comment
comment|/*  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR */
end_comment

begin_comment
comment|/*  PURPOSE. */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|OPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|OPTIONS_H
end_define

begin_include
include|#
directive|include
file|"scanopt.h"
end_include

begin_decl_stmt
specifier|extern
name|optspec_t
name|flexopts
index|[]
decl_stmt|;
end_decl_stmt

begin_enum
enum|enum
name|flexopt_flag_t
block|{
comment|/* Use positive integers only, since they are return codes for scanopt. 	 * Order is not important. */
name|OPT_7BIT
init|=
literal|1
block|,
name|OPT_8BIT
block|,
name|OPT_ALIGN
block|,
name|OPT_ALWAYS_INTERACTIVE
block|,
name|OPT_ARRAY
block|,
name|OPT_BACKUP
block|,
name|OPT_BATCH
block|,
name|OPT_BISON_BRIDGE
block|,
name|OPT_BISON_BRIDGE_LOCATIONS
block|,
name|OPT_CASE_INSENSITIVE
block|,
name|OPT_COMPRESSION
block|,
name|OPT_CPLUSPLUS
block|,
name|OPT_DEBUG
block|,
name|OPT_DEFAULT
block|,
name|OPT_DONOTHING
block|,
name|OPT_ECS
block|,
name|OPT_FAST
block|,
name|OPT_FULL
block|,
name|OPT_HEADER_FILE
block|,
name|OPT_HELP
block|,
name|OPT_INTERACTIVE
block|,
name|OPT_LEX_COMPAT
block|,
name|OPT_POSIX_COMPAT
block|,
name|OPT_MAIN
block|,
name|OPT_META_ECS
block|,
name|OPT_NEVER_INTERACTIVE
block|,
name|OPT_NO_ALIGN
block|,
name|OPT_NO_ANSI_FUNC_DEFS
block|,
name|OPT_NO_ANSI_FUNC_PROTOS
block|,
name|OPT_NO_DEBUG
block|,
name|OPT_NO_DEFAULT
block|,
name|OPT_NO_ECS
block|,
name|OPT_NO_LINE
block|,
name|OPT_NO_MAIN
block|,
name|OPT_NO_META_ECS
block|,
name|OPT_NO_REENTRANT
block|,
name|OPT_NO_REJECT
block|,
name|OPT_NO_STDINIT
block|,
name|OPT_NO_UNPUT
block|,
name|OPT_NO_WARN
block|,
name|OPT_NO_YYGET_EXTRA
block|,
name|OPT_NO_YYGET_IN
block|,
name|OPT_NO_YYGET_LENG
block|,
name|OPT_NO_YYGET_LINENO
block|,
name|OPT_NO_YYGET_LLOC
block|,
name|OPT_NO_YYGET_LVAL
block|,
name|OPT_NO_YYGET_OUT
block|,
name|OPT_NO_YYGET_TEXT
block|,
name|OPT_NO_YYLINENO
block|,
name|OPT_NO_YYMORE
block|,
name|OPT_NO_YYSET_EXTRA
block|,
name|OPT_NO_YYSET_IN
block|,
name|OPT_NO_YYSET_LINENO
block|,
name|OPT_NO_YYSET_LLOC
block|,
name|OPT_NO_YYSET_LVAL
block|,
name|OPT_NO_YYSET_OUT
block|,
name|OPT_NO_YYWRAP
block|,
name|OPT_NO_YY_POP_STATE
block|,
name|OPT_NO_YY_PUSH_STATE
block|,
name|OPT_NO_YY_SCAN_BUFFER
block|,
name|OPT_NO_YY_SCAN_BYTES
block|,
name|OPT_NO_YY_SCAN_STRING
block|,
name|OPT_NO_YY_TOP_STATE
block|,
name|OPT_OUTFILE
block|,
name|OPT_PERF_REPORT
block|,
name|OPT_POINTER
block|,
name|OPT_PREFIX
block|,
name|OPT_PREPROCDEFINE
block|,
name|OPT_PREPROC_LEVEL
block|,
name|OPT_READ
block|,
name|OPT_REENTRANT
block|,
name|OPT_REJECT
block|,
name|OPT_SKEL
block|,
name|OPT_STACK
block|,
name|OPT_STDINIT
block|,
name|OPT_STDOUT
block|,
name|OPT_TABLES_FILE
block|,
name|OPT_TABLES_VERIFY
block|,
name|OPT_TRACE
block|,
name|OPT_NO_UNISTD_H
block|,
name|OPT_VERBOSE
block|,
name|OPT_VERSION
block|,
name|OPT_WARN
block|,
name|OPT_YYCLASS
block|,
name|OPT_YYLINENO
block|,
name|OPT_YYMORE
block|,
name|OPT_YYWRAP
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vim:set tabstop=8 softtabstop=4 shiftwidth=4 textwidth=0: */
end_comment

end_unit

