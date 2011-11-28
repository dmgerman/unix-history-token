begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifdef
ifdef|#
directive|ifdef
name|FLEX_SCANNER
end_ifdef

begin_comment
comment|/* dnl  tables_shared.h - tables serialization header dnl dnl  Copyright (c) 1990 The Regents of the University of California. dnl  All rights reserved. dnl dnl  This code is derived from software contributed to Berkeley by dnl  Vern Paxson. dnl dnl  The United States Government has rights in this work pursuant dnl  to contract no. DE-AC03-76SF00098 between the United States dnl  Department of Energy and the University of California. dnl dnl  This file is part of flex. dnl dnl  Redistribution and use in source and binary forms, with or without dnl  modification, are permitted provided that the following conditions dnl  are met: dnl dnl  1. Redistributions of source code must retain the above copyright dnl     notice, this list of conditions and the following disclaimer. dnl  2. Redistributions in binary form must reproduce the above copyright dnl     notice, this list of conditions and the following disclaimer in the dnl     documentation and/or other materials provided with the distribution. dnl dnl  Neither the name of the University nor the names of its contributors dnl  may be used to endorse or promote products derived from this software dnl  without specific prior written permission. dnl dnl  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR dnl  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED dnl  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR dnl  PURPOSE.
comment|dnl dnl  This file is meant to be included in both the skeleton and the actual dnl  flex code (hence the name "_shared"). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|yyskel_static
end_ifndef

begin_define
define|#
directive|define
name|yyskel_static
value|static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|yyskel_static
end_ifndef

begin_define
define|#
directive|define
name|yyskel_static
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Structures and prototypes for serializing flex tables.  The  * binary format is documented in the manual.  *  * Design considerations:  *  *  -  The format allows many tables per file.  *  -  The tables can be streamed.  *  -  All data is stored in network byte order.  *  -  We do not hinder future unicode support.  *  -  We can lookup tables by name.  */
end_comment

begin_comment
comment|/** Magic number for serialized format. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYTBL_MAGIC
end_ifndef

begin_define
define|#
directive|define
name|YYTBL_MAGIC
value|0xF13C57B1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** Calculate (0-7) = number bytes needed to pad n to next 64-bit boundary. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|yypad64
end_ifndef

begin_define
define|#
directive|define
name|yypad64
parameter_list|(
name|n
parameter_list|)
value|((8-((n)%8))%8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|YYTABLES_TYPES
end_ifndef

begin_define
define|#
directive|define
name|YYTABLES_TYPES
end_define

begin_comment
comment|/** Possible values for td_id field. Each one corresponds to a  *  scanner table of the same name.  */
end_comment

begin_enum
enum|enum
name|yytbl_id
block|{
name|YYTD_ID_ACCEPT
init|=
literal|0x01
block|,
comment|/**< 1-dim ints */
name|YYTD_ID_BASE
init|=
literal|0x02
block|,
comment|/**< 1-dim ints */
name|YYTD_ID_CHK
init|=
literal|0x03
block|,
comment|/**< 1-dim ints */
name|YYTD_ID_DEF
init|=
literal|0x04
block|,
comment|/**< 1-dim ints */
name|YYTD_ID_EC
init|=
literal|0x05
block|,
comment|/**< 1-dim ints */
name|YYTD_ID_META
init|=
literal|0x06
block|,
comment|/**< 1-dim ints */
name|YYTD_ID_NUL_TRANS
init|=
literal|0x07
block|,
comment|/**< 1-dim ints, maybe indices */
name|YYTD_ID_NXT
init|=
literal|0x08
block|,
comment|/**< may be 2 dimensional ints */
name|YYTD_ID_RULE_CAN_MATCH_EOL
init|=
literal|0x09
block|,
comment|/**< 1-dim ints */
name|YYTD_ID_START_STATE_LIST
init|=
literal|0x0A
block|,
comment|/**< 1-dim indices into trans tbl  */
name|YYTD_ID_TRANSITION
init|=
literal|0x0B
block|,
comment|/**< structs */
name|YYTD_ID_ACCLIST
init|=
literal|0x0C
comment|/**< 1-dim ints */
block|}
enum|;
end_enum

begin_comment
comment|/** bit flags for t_flags field of struct yytbl_data */
end_comment

begin_enum
enum|enum
name|yytbl_flags
block|{
comment|/* These first three are mutually exclusive */
name|YYTD_DATA8
init|=
literal|0x01
block|,
comment|/**< data is an array of type flex_int8_t */
name|YYTD_DATA16
init|=
literal|0x02
block|,
comment|/**< data is an array of type flex_int16_t */
name|YYTD_DATA32
init|=
literal|0x04
block|,
comment|/**< data is an array of type flex_int32_t */
comment|/* These two are mutually exclusive. */
name|YYTD_PTRANS
init|=
literal|0x08
block|,
comment|/**< data is a list of indexes of entries                                  into the expanded `yy_transition'                                  array. See notes in manual. */
name|YYTD_STRUCT
init|=
literal|0x10
comment|/**< data consists of yy_trans_info structs */
block|}
enum|;
end_enum

begin_comment
comment|/* The serialized tables header. */
end_comment

begin_struct
struct|struct
name|yytbl_hdr
block|{
name|flex_uint32_t
name|th_magic
decl_stmt|;
comment|/**< Must be 0xF13C57B1 (comes from "Flex Table") */
name|flex_uint32_t
name|th_hsize
decl_stmt|;
comment|/**< Size of this header in bytes. */
name|flex_uint32_t
name|th_ssize
decl_stmt|;
comment|/**< Size of this dataset, in bytes, including header. */
name|flex_uint16_t
name|th_flags
decl_stmt|;
comment|/**< Currently unused, must be 0 */
name|char
modifier|*
name|th_version
decl_stmt|;
comment|/**< Flex version string. NUL terminated. */
name|char
modifier|*
name|th_name
decl_stmt|;
comment|/**< The name of this table set. NUL terminated. */
block|}
struct|;
end_struct

begin_comment
comment|/** A single serialized table */
end_comment

begin_struct
struct|struct
name|yytbl_data
block|{
name|flex_uint16_t
name|td_id
decl_stmt|;
comment|/**< enum yytbl_id table identifier */
name|flex_uint16_t
name|td_flags
decl_stmt|;
comment|/**< how to interpret this data */
name|flex_uint32_t
name|td_hilen
decl_stmt|;
comment|/**< num elements in highest dimension array */
name|flex_uint32_t
name|td_lolen
decl_stmt|;
comment|/**< num elements in lowest dimension array */
name|void
modifier|*
name|td_data
decl_stmt|;
comment|/**< table data */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/** Extract corresponding data size_t from td_flags */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYTDFLAGS2BYTES
end_ifndef

begin_define
define|#
directive|define
name|YYTDFLAGS2BYTES
parameter_list|(
name|td_flags
parameter_list|)
define|\
value|(((td_flags)& YYTD_DATA8)\             ? sizeof(flex_int8_t)\             :(((td_flags)& YYTD_DATA16)\                 ? sizeof(flex_int16_t)\                 :sizeof(flex_int32_t)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FLEX_SCANNER
end_ifdef

begin_expr_stmt
operator|%
name|not
operator|-
end_expr_stmt

begin_for
for|for-header
endif|#
directive|endif
for|yyskel_static flex_int32_t yytbl_calc_total_len
control|(
specifier|const
expr|struct
name|yytbl_data
operator|*
name|tbl
control|)
empty_stmt|;
end_for

begin_ifdef
ifdef|#
directive|ifdef
name|FLEX_SCANNER
end_ifdef

begin_expr_stmt
operator|%
name|ok
operator|-
end_expr_stmt

begin_for
for|for-header
end_for

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vim:set noexpandtab cindent tabstop=8 softtabstop=0 shiftwidth=8 textwidth=0: */
end_comment

end_unit

