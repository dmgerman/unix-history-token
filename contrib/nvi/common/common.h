begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1991, 1993, 1994, 1995, 1996  *	Keith Bostic.  All rights reserved.  *  * See the LICENSE file for redistribution information.  *  *	@(#)common.h	10.13 (Berkeley) 9/25/96  */
end_comment

begin_comment
comment|/*  * Porting information built at configuration time.  Included before  * any of nvi's include files.  */
end_comment

begin_include
include|#
directive|include
file|"port.h"
end_include

begin_comment
comment|/*  * Pseudo-local includes.  These are files that are unlikely to exist  * on most machines to which we're porting vi, and we want to include  * them in a very specific order, regardless.  */
end_comment

begin_include
include|#
directive|include
file|<db.h>
end_include

begin_include
include|#
directive|include
file|<regex.h>
end_include

begin_comment
comment|/*  * Forward structure declarations.  Not pretty, but the include files  * are far too interrelated for a clean solution.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_cb
name|CB
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_csc
name|CSC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_event
name|EVENT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_excmd
name|EXCMD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_exf
name|EXF
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_fref
name|FREF
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_gs
name|GS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_lmark
name|LMARK
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_mark
name|MARK
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_msg
name|MSGS
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_option
name|OPTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_optlist
name|OPTLIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_scr
name|SCR
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_script
name|SCRIPT
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_seq
name|SEQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_tag
name|TAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_tagf
name|TAGF
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_tagq
name|TAGQ
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_text
name|TEXT
typedef|;
end_typedef

begin_comment
comment|/* Autoindent state. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|C_NOTSET
block|,
name|C_CARATSET
block|,
name|C_NOCHANGE
block|,
name|C_ZEROSET
block|}
name|carat_t
typedef|;
end_typedef

begin_comment
comment|/* Busy message types. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|BUSY_ON
init|=
literal|1
block|,
name|BUSY_OFF
block|,
name|BUSY_UPDATE
block|}
name|busy_t
typedef|;
end_typedef

begin_comment
comment|/*  * Routines that return a confirmation return:  *  *	CONF_NO		User answered no.  *	CONF_QUIT	User answered quit, eof or an error.  *	CONF_YES	User answered yes.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CONF_NO
block|,
name|CONF_QUIT
block|,
name|CONF_YES
block|}
name|conf_t
typedef|;
end_typedef

begin_comment
comment|/* Directions. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|NOTSET
block|,
name|FORWARD
block|,
name|BACKWARD
block|}
name|dir_t
typedef|;
end_typedef

begin_comment
comment|/* Line operations. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LINE_APPEND
block|,
name|LINE_DELETE
block|,
name|LINE_INSERT
block|,
name|LINE_RESET
block|}
name|lnop_t
typedef|;
end_typedef

begin_comment
comment|/* Lock return values. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|LOCK_FAILED
block|,
name|LOCK_SUCCESS
block|,
name|LOCK_UNAVAIL
block|}
name|lockr_t
typedef|;
end_typedef

begin_comment
comment|/* Sequence types. */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|SEQ_ABBREV
block|,
name|SEQ_COMMAND
block|,
name|SEQ_INPUT
block|}
name|seq_t
typedef|;
end_typedef

begin_comment
comment|/*  * Local includes.  */
end_comment

begin_include
include|#
directive|include
file|"key.h"
end_include

begin_comment
comment|/* Required by args.h. */
end_comment

begin_include
include|#
directive|include
file|"args.h"
end_include

begin_comment
comment|/* Required by options.h. */
end_comment

begin_include
include|#
directive|include
file|"options.h"
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|"msg.h"
end_include

begin_comment
comment|/* Required by gs.h. */
end_comment

begin_include
include|#
directive|include
file|"cut.h"
end_include

begin_comment
comment|/* Required by gs.h. */
end_comment

begin_include
include|#
directive|include
file|"seq.h"
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_comment
comment|/* Required by ex.h. */
end_comment

begin_include
include|#
directive|include
file|"mark.h"
end_include

begin_comment
comment|/* Required by gs.h. */
end_comment

begin_include
include|#
directive|include
file|"../ex/ex.h"
end_include

begin_comment
comment|/* Required by gs.h. */
end_comment

begin_include
include|#
directive|include
file|"gs.h"
end_include

begin_comment
comment|/* Required by screen.h. */
end_comment

begin_include
include|#
directive|include
file|"screen.h"
end_include

begin_comment
comment|/* Required by exf.h. */
end_comment

begin_include
include|#
directive|include
file|"exf.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"mem.h"
end_include

begin_include
include|#
directive|include
file|"com_extern.h"
end_include

end_unit

