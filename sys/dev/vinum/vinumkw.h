begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997, 1998  *	Nan Yang Computer Services Limited.  All rights reserved.  *  *  This software is distributed under the so-called ``Berkeley  *  License'':  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Nan Yang Computer  *      Services Limited.  * 4. Neither the name of the Company nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * This software is provided ``as is'', and any express or implied  * warranties, including, but not limited to, the implied warranties of  * merchantability and fitness for a particular purpose are disclaimed.  * In no event shall the company or contributors be liable for any  * direct, indirect, incidental, special, exemplary, or consequential  * damages (including, but not limited to, procurement of substitute  * goods or services; loss of use, data, or profits; or business  * interruption) however caused and on any theory of liability, whether  * in contract, strict liability, or tort (including negligence or  * otherwise) arising in any way out of the use of this software, even if  * advised of the possibility of such damage.  *  * $Id: vinumkw.h,v 1.16 2000/02/19 06:52:46 grog Exp grog $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * Command keywords that vinum knows.  These include both user-level  * and kernel-level stuff  */
end_comment

begin_comment
comment|/*  * Our complete vocabulary.  The names of the commands are  * the same as the identifier without the kw_ at the beginning  * (i.e. kw_create defines the "create" keyword).  Preprocessor  * magic in parser.c does the rest.  *  * To add a new word: put it in the table below and one of the  * lists in vinumparser.c (probably keywords).  */
end_comment

begin_enum
enum|enum
name|keyword
block|{
name|kw_create
block|,
name|kw_modify
block|,
name|kw_list
block|,
name|kw_l
init|=
name|kw_list
block|,
name|kw_ld
block|,
comment|/* list drive */
name|kw_ls
block|,
comment|/* list subdisk */
name|kw_lp
block|,
comment|/* list plex */
name|kw_lv
block|,
comment|/* list volume */
name|kw_set
block|,
name|kw_rm
block|,
name|kw_mv
block|,
comment|/* move object */
name|kw_move
block|,
comment|/* synonym for mv */
name|kw_start
block|,
name|kw_stop
block|,
name|kw_makedev
block|,
comment|/* make /dev/vinum devices */
name|kw_setdaemon
block|,
comment|/* set daemon flags */
name|kw_getdaemon
block|,
comment|/* set daemon flags */
name|kw_help
block|,
name|kw_drive
block|,
name|kw_partition
block|,
name|kw_sd
block|,
name|kw_subdisk
init|=
name|kw_sd
block|,
name|kw_plex
block|,
name|kw_volume
block|,
name|kw_vol
init|=
name|kw_volume
block|,
name|kw_read
block|,
name|kw_readpol
block|,
name|kw_org
block|,
name|kw_name
block|,
name|kw_concat
block|,
name|kw_striped
block|,
name|kw_raid4
block|,
name|kw_raid5
block|,
name|kw_driveoffset
block|,
name|kw_plexoffset
block|,
name|kw_len
block|,
name|kw_length
init|=
name|kw_len
block|,
name|kw_size
init|=
name|kw_len
block|,
name|kw_state
block|,
name|kw_setupstate
block|,
name|kw_d
block|,
comment|/* flag names */
name|kw_f
block|,
name|kw_r
block|,
name|kw_s
block|,
name|kw_v
block|,
name|kw_w
block|,
name|kw_round
block|,
comment|/* round robin */
name|kw_prefer
block|,
comment|/* prefer plex */
name|kw_device
block|,
name|kw_init
block|,
name|kw_label
block|,
name|kw_resetconfig
block|,
name|kw_writethrough
block|,
name|kw_writeback
block|,
name|kw_raw
block|,
name|kw_replace
block|,
name|kw_resetstats
block|,
name|kw_attach
block|,
name|kw_detach
block|,
name|kw_rename
block|,
name|kw_printconfig
block|,
name|kw_saveconfig
block|,
name|kw_hotspare
block|,
name|kw_detached
block|,
ifdef|#
directive|ifdef
name|VINUMDEBUG
name|kw_debug
block|,
comment|/* go into debugger */
endif|#
directive|endif
name|kw_stripe
block|,
name|kw_mirror
block|,
name|kw_info
block|,
name|kw_quit
block|,
name|kw_max
block|,
name|kw_setstate
block|,
name|kw_checkparity
block|,
name|kw_rebuildparity
block|,
name|kw_dumpconfig
block|,
name|kw_retryerrors
block|,
name|kw_invalid_keyword
init|=
operator|-
literal|1
block|}
enum|;
end_enum

begin_struct
struct|struct
name|_keywords
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|enum
name|keyword
name|keyword
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|keywordset
block|{
name|int
name|size
decl_stmt|;
name|struct
name|_keywords
modifier|*
name|k
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|_keywords
name|keywords
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|_keywords
name|flag_keywords
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|keywordset
name|keyword_set
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|keywordset
name|flag_set
decl_stmt|;
end_decl_stmt

end_unit

