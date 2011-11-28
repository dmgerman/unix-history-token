begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  tables.h - tables serialization code  *  *  Copyright (c) 1990 The Regents of the University of California.  *  All rights reserved.  *  *  This code is derived from software contributed to Berkeley by  *  Vern Paxson.  *  *  The United States Government has rights in this work pursuant  *  to contract no. DE-AC03-76SF00098 between the United States  *  Department of Energy and the University of California.  *  *  This file is part of flex.  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in the  *     documentation and/or other materials provided with the distribution.  *  *  Neither the name of the University nor the names of its contributors  *  may be used to endorse or promote products derived from this software  *  without specific prior written permission.  *  *  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  *  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  *  PURPOSE.  */
end_comment

begin_escape
end_escape

begin_ifndef
ifndef|#
directive|ifndef
name|TABLES_H
end_ifndef

begin_define
define|#
directive|define
name|TABLES_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_comment
comment|/* *INDENT-OFF* */
end_comment

begin_extern
extern|extern
literal|"C"
block|{
comment|/* *INDENT-ON* */
endif|#
directive|endif
comment|/* Tables serialization API declarations. */
include|#
directive|include
file|"tables_shared.h"
struct|struct
name|yytbl_writer
block|{
name|FILE
modifier|*
name|out
decl_stmt|;
name|flex_uint32_t
name|total_written
decl_stmt|;
comment|/**< bytes written so far */
name|fpos_t
name|th_ssize_pos
decl_stmt|;
comment|/**< position of th_ssize */
block|}
struct|;
comment|/* These are used by main.c, gen.c, etc.  * tablesext - if true, create external tables  * tablesfilename - filename for external tables  * tablesname - name that goes in serialized data, e.g., "yytables"  * tableswr -  writer for external tables  * tablesverify - true if tables-verify option specified  * gentables - true if we should spit out the normal C tables  */
specifier|extern
name|bool
name|tablesext
decl_stmt|,
name|tablesverify
decl_stmt|,
name|gentables
decl_stmt|;
specifier|extern
name|char
modifier|*
name|tablesfilename
decl_stmt|,
modifier|*
name|tablesname
decl_stmt|;
specifier|extern
name|struct
name|yytbl_writer
name|tableswr
decl_stmt|;
name|int
name|yytbl_writer_init
parameter_list|(
name|struct
name|yytbl_writer
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
name|int
name|yytbl_hdr_init
parameter_list|(
name|struct
name|yytbl_hdr
modifier|*
name|th
parameter_list|,
specifier|const
name|char
modifier|*
name|version_str
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
name|int
name|yytbl_data_init
parameter_list|(
name|struct
name|yytbl_data
modifier|*
name|tbl
parameter_list|,
name|enum
name|yytbl_id
name|id
parameter_list|)
function_decl|;
name|int
name|yytbl_data_destroy
parameter_list|(
name|struct
name|yytbl_data
modifier|*
name|td
parameter_list|)
function_decl|;
name|int
name|yytbl_hdr_fwrite
parameter_list|(
name|struct
name|yytbl_writer
modifier|*
name|wr
parameter_list|,
specifier|const
name|struct
name|yytbl_hdr
modifier|*
name|th
parameter_list|)
function_decl|;
name|int
name|yytbl_data_fwrite
parameter_list|(
name|struct
name|yytbl_writer
modifier|*
name|wr
parameter_list|,
name|struct
name|yytbl_data
modifier|*
name|td
parameter_list|)
function_decl|;
name|void
name|yytbl_data_compress
parameter_list|(
name|struct
name|yytbl_data
modifier|*
name|tbl
parameter_list|)
function_decl|;
name|struct
name|yytbl_data
modifier|*
name|mkftbl
parameter_list|(
name|void
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
comment|/* *INDENT-OFF* */
block|}
end_extern

begin_comment
comment|/* *INDENT-ON* */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vim:set expandtab cindent tabstop=4 softtabstop=4 shiftwidth=4 textwidth=0: */
end_comment

end_unit

