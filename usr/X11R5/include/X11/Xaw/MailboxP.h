begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: MailboxP.h,v 1.20 91/07/19 21:52:57 rws Exp $  *  * Copyright 1988 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * Author:  Jim Fulton, MIT X Consortium  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawMailboxP_h
end_ifndef

begin_define
define|#
directive|define
name|_XawMailboxP_h
end_define

begin_include
include|#
directive|include
file|<X11/Xaw/Mailbox.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleP.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV
end_ifdef

begin_define
define|#
directive|define
name|MAILBOX_DIRECTORY
value|"/usr/mail"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_define
define|#
directive|define
name|MAILBOX_DIRECTORY
value|"/var/mail"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MAILBOX_DIRECTORY
value|"/usr/spool/mail"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* new fields for mailbox widget */
comment|/* resources */
name|int
name|update
decl_stmt|;
comment|/* seconds between updates */
name|Pixel
name|foreground_pixel
decl_stmt|;
comment|/* color index of normal state fg */
name|String
name|filename
decl_stmt|;
comment|/* filename to watch */
name|String
name|check_command
decl_stmt|;
comment|/* command to exec for mail check */
name|Boolean
name|flipit
decl_stmt|;
comment|/* do flip of full pixmap */
name|int
name|volume
decl_stmt|;
comment|/* bell volume */
name|Boolean
name|once_only
decl_stmt|;
comment|/* ring bell only once on new mail */
comment|/* local state */
name|GC
name|gc
decl_stmt|;
comment|/* normal GC to use */
name|long
name|last_size
decl_stmt|;
comment|/* size in bytes of mailboxname */
name|XtIntervalId
name|interval_id
decl_stmt|;
comment|/* time between checks */
name|Boolean
name|flag_up
decl_stmt|;
comment|/* is the flag up? */
struct|struct
name|_mbimage
block|{
name|Pixmap
name|bitmap
decl_stmt|,
name|mask
decl_stmt|;
comment|/* depth 1, describing shape */
name|Pixmap
name|pixmap
decl_stmt|;
comment|/* full depth pixmap */
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* geometry of pixmaps */
block|}
name|full
struct|,
name|empty
struct|;
name|Boolean
name|shapeit
decl_stmt|;
comment|/* do shape extension */
struct|struct
block|{
name|Pixmap
name|mask
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|shape_cache
struct|;
comment|/* last set of info */
block|}
name|MailboxPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MailboxRec
block|{
comment|/* full instance record */
name|CorePart
name|core
decl_stmt|;
name|SimplePart
name|simple
decl_stmt|;
name|MailboxPart
name|mailbox
decl_stmt|;
block|}
name|MailboxRec
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|/* new fields for mailbox class */
name|int
name|dummy
decl_stmt|;
comment|/* stupid C compiler */
block|}
name|MailboxClassPart
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_MailboxClassRec
block|{
comment|/* full class record declaration */
name|CoreClassPart
name|core_class
decl_stmt|;
name|SimpleClassPart
name|simple_class
decl_stmt|;
name|MailboxClassPart
name|mailbox_class
decl_stmt|;
block|}
name|MailboxClassRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|MailboxClassRec
name|mailboxClassRec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* class pointer */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawMailboxP_h */
end_comment

end_unit

