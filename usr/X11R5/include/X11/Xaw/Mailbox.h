begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $XConsortium: Mailbox.h,v 1.20 91/05/04 18:58:42 rws Exp $  *  * Copyright 1988 Massachusetts Institute of Technology  *  * Permission to use, copy, modify, and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies and that both that  * copyright notice and this permission notice appear in supporting  * documentation, and that the name of M.I.T. not be used in advertising or  * publicity pertaining to distribution of the software without specific,  * written prior permission.  M.I.T. makes no representations about the  * suitability of this software for any purpose.  It is provided "as is"  * without express or implied warranty.  *  * Author:  Jim Fulton, MIT X Consortium  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XawMailbox_h
end_ifndef

begin_define
define|#
directive|define
name|_XawMailbox_h
end_define

begin_comment
comment|/*  * Mailbox widget; looks a lot like the clock widget, don't it...  */
end_comment

begin_comment
comment|/* resource names used by mailbox widget that aren't defined in StringDefs.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_XtStringDefs_h_
end_ifndef

begin_define
define|#
directive|define
name|XtNupdate
value|"update"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* command to exec */
end_comment

begin_define
define|#
directive|define
name|XtNcheckCommand
value|"checkCommand"
end_define

begin_define
define|#
directive|define
name|XtNonceOnly
value|"onceOnly"
end_define

begin_comment
comment|/* Int: volume for bell */
end_comment

begin_define
define|#
directive|define
name|XtNvolume
value|"volume"
end_define

begin_define
define|#
directive|define
name|XtNfullPixmap
value|"fullPixmap"
end_define

begin_define
define|#
directive|define
name|XtNfullPixmapMask
value|"fullPixmapMask"
end_define

begin_define
define|#
directive|define
name|XtNemptyPixmap
value|"emptyPixmap"
end_define

begin_define
define|#
directive|define
name|XtNemptyPixmapMask
value|"emptyPixmapMask"
end_define

begin_define
define|#
directive|define
name|XtNflip
value|"flip"
end_define

begin_define
define|#
directive|define
name|XtNshapeWindow
value|"shapeWindow"
end_define

begin_define
define|#
directive|define
name|XtCCheckCommand
value|"CheckCommand"
end_define

begin_define
define|#
directive|define
name|XtCVolume
value|"Volume"
end_define

begin_define
define|#
directive|define
name|XtCPixmapMask
value|"PixmapMask"
end_define

begin_define
define|#
directive|define
name|XtCFlip
value|"Flip"
end_define

begin_define
define|#
directive|define
name|XtCShapeWindow
value|"ShapeWindow"
end_define

begin_comment
comment|/* structures */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_MailboxRec
modifier|*
name|MailboxWidget
typedef|;
end_typedef

begin_comment
comment|/* see MailboxP.h */
end_comment

begin_typedef
typedef|typedef
name|struct
name|_MailboxClassRec
modifier|*
name|MailboxWidgetClass
typedef|;
end_typedef

begin_comment
comment|/* see MailboxP.h */
end_comment

begin_decl_stmt
specifier|extern
name|WidgetClass
name|mailboxWidgetClass
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _XawMailbox_h */
end_comment

begin_comment
comment|/* DON'T ADD STUFF AFTER THIS #endif */
end_comment

end_unit

