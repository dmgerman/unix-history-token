begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Header: /f/osi/others/quipu/uips/pod/RCS/pod.h,v 7.1 91/02/22 09:31:50 mrose Interim $  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"sequence.h"
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xatom.h>
end_include

begin_include
include|#
directive|include
file|<X11/Intrinsic.h>
end_include

begin_include
include|#
directive|include
file|<X11/StringDefs.h>
end_include

begin_include
include|#
directive|include
file|<X11/cursorfont.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xutil.h>
end_include

begin_include
include|#
directive|include
file|<X11/Shell.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Cardinals.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Viewport.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Command.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/AsciiText.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Label.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Form.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SimpleMenu.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Sme.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SmeBSB.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/SmeLine.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/MenuButton.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/Dialog.h>
end_include

begin_include
include|#
directive|include
file|<X11/Xaw/List.h>
end_include

begin_define
define|#
directive|define
name|FONTHEIGHT
parameter_list|(
name|f
parameter_list|)
value|((f)->max_bounds.ascent + \ 		       (f)->max_bounds.descent )
end_define

begin_define
define|#
directive|define
name|FONTWIDTH
parameter_list|(
name|f
parameter_list|)
value|((f)->max_bounds.width)
end_define

end_unit

